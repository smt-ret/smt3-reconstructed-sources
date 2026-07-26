from pathlib import Path

from smt3 import smt3dump
from smt3.metadata import Metadata

FIXTURE = Path(__file__).parent / "fixtures" / "smt3_snippet.h"


# --- parsing -------------------------------------------------------------


def test_parse_blocks_finds_definitions_not_forward_decls() -> None:
    text = "struct Foo_Fields;\nstruct Foo_Fields\n{\n  int32_t a;\n};\n"
    blocks = list(smt3dump.parse_blocks(text))
    assert len(blocks) == 1
    assert blocks[0].name == "Foo_Fields"
    assert blocks[0].members == ["int32_t a;"]


def test_parse_blocks_skips_comment_lines() -> None:
    text = "struct X_Fields\n{\n  /* 1561 */\n  float a;\n};\n"
    (block,) = smt3dump.parse_blocks(text)
    assert block.members == ["float a;"]


# --- routing -------------------------------------------------------------


def test_route_h_marked_fields() -> None:
    assert smt3dump.route("newdata_H_datUnitWork_s_Fields", nonempty=True) == (
        "newdata.h",
        "struct",
        "datUnitWork_s",
    )


def test_route_splits_on_first_h_marker() -> None:
    assert smt3dump.route("libsdf_H_sdfModelNode_t_Fields", nonempty=True) == (
        "libsdf.h",
        "struct",
        "sdfModelNode_t",
    )


def test_route_non_h_fields_to_module_c() -> None:
    # locally-defined struct (no _H_) is emitted into a module .c, not dropped
    assert smt3dump.route("FLD_INF_PACK_t_Fields", nonempty=True) == (
        "FLD_INF_PACK_t.c",
        "struct",
        "FLD_INF_PACK_t",
    )


def test_struct_only_base_promoted_to_header() -> None:
    # a base with only a struct layout (no functions or data) is a header, not a .c
    src = (
        "struct effPCPFlashPolyCirclePart_tag_Fields\n"
        "{\n"
        "  uint32_t abgr;\n"
        "  int32_t frame;\n"
        "};\n"
    )
    out = smt3dump.generate(src)
    assert "effPCPFlashPolyCirclePart_tag.h" in out
    assert "effPCPFlashPolyCirclePart_tag.c" not in out
    header = out["effPCPFlashPolyCirclePart_tag.h"]
    assert header.startswith("#pragma once")
    assert "struct effPCPFlashPolyCirclePart_tag {" in header


def test_module_with_functions_stays_c() -> None:
    # a base that also owns data/functions keeps its struct in the module .c
    out = smt3dump.generate(FIXTURE.read_text())
    assert "billManager.c" in out  # has StaticFields data alongside its nested struct
    assert "billManager.h" not in out


def test_route_module_statics_to_c() -> None:
    assert smt3dump.route("fldGlobal_StaticFields", nonempty=True) == (
        "fldGlobal.c",
        "static",
        "fldGlobal",
    )


def test_route_h_marked_globals_are_extern() -> None:
    assert smt3dump.route("field_H_fldSceneParam_t_StaticFields", nonempty=True) == (
        "field.h",
        "extern",
        "fldSceneParam_t",
    )


def test_route_empty_statics_dropped() -> None:
    assert smt3dump.route("fldSky_typeSKYTBL_StaticFields", nonempty=False) is None


def test_route_runtime_and_junk_dropped() -> None:
    assert smt3dump.route("System_Type_StaticFields", nonempty=True) is None
    assert smt3dump.route("Mono_Security_Uri_StaticFields", nonempty=True) is None
    assert smt3dump.route("_PrivateImplementationDetails___Size_Fields", nonempty=True) is None
    assert smt3dump.route("bilManager_Arrays_Fields", nonempty=True) is None
    assert smt3dump.route("UnityEngineInternal_Mathf_Fields", nonempty=True) is None
    assert smt3dump.route("nn_ec_ConsumableServiceItemId_Fields", nonempty=True) is None


# --- member rewriting ----------------------------------------------------


def _rw(line: str) -> str:
    return smt3dump.rewrite_member(line)[0]


def test_rewrite_primitive_to_decomp_alias() -> None:
    assert _rw("uint16_t flags;") == "u16 flags;"
    assert _rw("float bounds;") == "f32 bounds;"


def test_rewrite_imported_object_pointer() -> None:
    line, refs = smt3dump.rewrite_member("struct libsdf_H_sdfModelNode_t_o *prev;")
    assert line == "sdfModelNode_t *prev;"
    assert refs == {"sdfModelNode_t"}


def test_rewrite_array_unknown_size_uses_sentinel() -> None:
    # System_SByte_array with no recovered size -> a grep-able sentinel dimension
    assert _rw("struct System_SByte_array *s;") == "s8 s[UNKNOWN_ARRAY_SIZE];"
    assert _rw("struct System_UInt32_array *pad1;") == "u32 pad1[UNKNOWN_ARRAY_SIZE];"


def test_rewrite_array_of_array_keeps_inner_pointer() -> None:
    assert (
        _rw("struct System_Byte_array_array *field_name;")
        == "u8 *field_name[UNKNOWN_ARRAY_SIZE];"
    )


def test_rewrite_imported_array() -> None:
    line, refs = smt3dump.rewrite_member("struct libsdf_H_sdfMemHandle_t_array *h;")
    assert line == "sdfMemHandle_t h[UNKNOWN_ARRAY_SIZE];"
    assert refs == {"sdfMemHandle_t"}


def test_rewrite_unity_math_value() -> None:
    line, refs = smt3dump.rewrite_member("struct UnityEngine_Vector4_o pos;")
    assert line == "sdfVector4_t pos;"  # inferred original name
    assert refs == set()  # provided by il2cpp_common.h


def test_rewrite_il2cpp_object_to_void() -> None:
    assert _rw("Il2CppObject *userData;") == "void *userData;"


def test_rewrite_system_string_pointer() -> None:
    assert _rw("struct System_String_o *name;") == "char *name;"


def test_rewrite_game_external_kept_opaque() -> None:
    line, refs = smt3dump.rewrite_member("struct FldNameData_o *fldNameData;")
    assert line == "FldNameData *fldNameData;"
    assert refs == {"FldNameData"}


def test_rewrite_runtime_external_to_void() -> None:
    assert _rw("struct System_Func_dds3Basic_t__int__o *cb;") == "void *cb;"


# --- end to end ----------------------------------------------------------


def test_generate_produces_headers_and_modules() -> None:
    out = smt3dump.generate(FIXTURE.read_text())
    assert "il2cpp_common.h" in out
    assert "libsdf.h" in out  # _H_ types -> header
    assert "fldGlobal.c" in out  # module globals -> .c
    assert "fldGlobal.h" not in out
    # empty StaticFields must not create files
    assert "field.h" not in out


def test_generated_struct_body_and_forward_decls() -> None:
    out = smt3dump.generate(FIXTURE.read_text())
    libsdf = out["libsdf.h"]
    assert '#include "il2cpp_common.h"' in libsdf
    assert "typedef struct sdfModelNode_t sdfModelNode_t;" in libsdf
    assert "struct sdfModelNode_t {" in libsdf
    assert "sdfModelNode_t *next;" in libsdf
    assert "sdfVector4_t pos;" in libsdf
    assert "void *userData;" in libsdf


def test_generated_module_symbols_are_static() -> None:
    out = smt3dump.generate(FIXTURE.read_text())
    g = out["fldGlobal.c"]
    assert g.startswith('#include "il2cpp_common.h"')  # no banner, include leads
    assert "#pragma once" not in g  # a .c is not include-guarded
    assert "static s32 fldAllCnt;" in g
    assert "static FldNameData *fldNameData;" in g
    assert "static char fldsave_nml_name[UNKNOWN_ARRAY_SIZE];" in g
    assert "typedef struct FldNameData FldNameData;" in g


def test_locally_defined_struct_is_emitted_not_opaque() -> None:
    # Regression: a non-_H_ struct with a real body must be emitted (not left as a dangling
    # opaque forward-decl), folded into its parent module's .c (billManager, not its own).
    out = smt3dump.generate(FIXTURE.read_text())
    assert "billManager_hG_t.c" not in out  # folded into the parent module
    c = out["billManager.c"]
    assert "struct billManager_hG_t {" in c
    assert "u16 type;" in c
    assert "billHandle_t *handle;" in c  # _H_ member resolves to clean imported name


def test_module_static_table() -> None:
    out = smt3dump.generate(FIXTURE.read_text())
    c = out["billManager.c"]
    assert "static f32 bill_alf_raito;" in c
    assert "static BillTable_t BillboardTable[UNKNOWN_ARRAY_SIZE];" in c


def test_empty_struct_holder_is_dropped() -> None:
    # A static-class holder with no instance fields must not emit `struct X {};`.
    assert smt3dump.route("bilManager_Fields", nonempty=False) is None
    out = smt3dump.generate(FIXTURE.read_text())
    assert "struct billManager {" not in out.get("billManager.c", "")


def test_define_holder_becomes_macros() -> None:
    assert smt3dump.route("pb_H_pb_Define_StaticFields", nonempty=True) == (
        "pb.h",
        "define",
        "pb_Define",
    )
    out = smt3dump.generate(FIXTURE.read_text())
    pb = out["pb.h"]
    assert "#define PB_MCRD_TYPE_NOCRD" in pb
    assert "#define PB_MCRD_STAT_SUCCEED" in pb
    # no bogus value invented, and not emitted as a struct/extern
    assert "PB_MCRD_TYPE_NOCRD;" not in pb
    assert "struct pb_Define" not in pb


# --- array-size recovery from transpiled .c ------------------------------

_CTOR_C = """\
void __fastcall basic_H_dds3UnitStatus_t___ctor(basic_H_dds3UnitStatus_t_o *this, int *m)
{
  this->fields.rpoints = il2cpp::NewSpecific(byte___TypeInfo, 4u);
  this->fields.regists = il2cpp::NewSpecific(sbyte___TypeInfo, 8u);
  this->fields.actors = il2cpp::NewSpecific(basic_H_dds3Basic_t___TypeInfo, 3u);
  this->fields.dynamic = il2cpp::NewSpecific(byte___TypeInfo, 0);
}
void __fastcall beast_aisyo___cctor(const MethodInfo *m)
{
  v1 = il2cpp::NewSpecific(byte___TypeInfo, 0xDD1u);
  beast_aisyo_TypeInfo->static_fields->tbl = v1;
}
void __fastcall scr_H_scrHeader_t___ctor(
        scr_H_scrHeader_t_o *this,
        System_Byte_array *dat,
        const MethodInfo *method)
{
  this->fields.names = il2cpp::NewSpecific(sbyte___TypeInfo, 16u);
}
"""


def test_array_sizes_multiline_signature() -> None:
    # Regression: the receiver `_o *this` param sits on its own line, so the struct context
    # must be picked up there, not only when it shares the __fastcall line.
    s = smt3dump.array_sizes(_CTOR_C.splitlines())
    assert s[("scr_H_scrHeader_t", "names")] == (16, True)


def test_array_sizes_instance_and_static() -> None:
    s = smt3dump.array_sizes(_CTOR_C.splitlines())
    assert s[("basic_H_dds3UnitStatus_t", "rpoints")] == (4, True)  # byte -> value
    assert s[("basic_H_dds3UnitStatus_t", "regists")] == (8, True)  # sbyte -> value
    assert s[("basic_H_dds3UnitStatus_t", "actors")] == (3, False)  # class -> reference
    assert s[("beast_aisyo", "tbl")] == (0xDD1, True)  # static, hex, via local var
    assert ("basic_H_dds3UnitStatus_t", "dynamic") not in s  # size 0 -> skipped


def test_recovered_size_materializes_array() -> None:
    sizes = smt3dump.array_sizes(_CTOR_C.splitlines())
    # value element -> fixed array, no pointer, no /* [] */ marker
    line, _ = smt3dump.rewrite_member(
        "struct System_Byte_array *rpoints;",
        struct="basic_H_dds3UnitStatus_t",
        sizes=sizes,
    )
    assert line == "u8 rpoints[4];"
    # reference element -> array of pointers
    line, refs = smt3dump.rewrite_member(
        "struct basic_H_dds3Basic_t_array *actors;",
        struct="basic_H_dds3UnitStatus_t",
        sizes=sizes,
    )
    assert line == "dds3Basic_t *actors[3];"
    assert refs == {"dds3Basic_t"}


def test_unrecovered_array_uses_sentinel() -> None:
    sizes = smt3dump.array_sizes(_CTOR_C.splitlines())
    line, _ = smt3dump.rewrite_member(
        "struct System_Byte_array *unknown;", struct="whatever", sizes=sizes
    )
    assert line == "u8 unknown[UNKNOWN_ARRAY_SIZE];"


_MULTILINE_C = """\
void __fastcall wide_H_w_t___ctor(wide_H_w_t_o *this, const MethodInfo *m)
{
  this->fields.wide = il2cpp::NewSpecific(
                        byte___TypeInfo,
                        7u);
}
void __fastcall wide_cc___cctor(const MethodInfo *m)
{
  v9 = il2cpp::NewSpecific(
         int___TypeInfo,
         5u);
  wide_cc_TypeInfo->static_fields->widetbl = v9;
}
"""


def test_array_sizes_multiline_newspecific() -> None:
    # Hex-Rays wraps long allocations across physical lines; the scanner joins them.
    s = smt3dump.array_sizes(_MULTILINE_C.splitlines())
    assert s[("wide_H_w_t", "wide")] == (7, True)  # multi-line instance alloc
    assert s[("wide_cc", "widetbl")] == (5, True)  # multi-line static via local var


def test_jagged_array_outer_dimension_materialized() -> None:
    # byte[][] : only the outer (allocated) dimension is known; the inner stays a pointer.
    jag = (
        "void __fastcall jag_H_j_t___ctor(jag_H_j_t_o *this, const MethodInfo *m)\n{\n"
        "  this->fields.rows = il2cpp::NewSpecific(int_array___TypeInfo, 3u);\n}\n"
    )
    sizes = smt3dump.array_sizes(jag.splitlines())
    line, _ = smt3dump.rewrite_member(
        "struct System_Int32_array_array *rows;", struct="jag_H_j_t", sizes=sizes
    )
    assert line == "s32 *rows[3];"


# --- metadata: enums and #define values ----------------------------------

_META = Metadata(
    enums={"ATTR_ATK": [("ATTR_NON", -1), ("ATTR_BUTURI", 0), ("ATTR_KAEN", 1)]},
    constants={"pb_Define": [("PB_MAP_X", 20), ("PB_PATH", "data/x"), ("PB_MCRD_NOCRD", None)]},
)

_ENUM_C = """\
struct newdata_H_ATTR_ATK_Fields
{
  int32_t value__;
};

struct newdata_H_holder_s_Fields
{
  struct newdata_H_ATTR_ATK_o attr;
};

struct pb_H_pb_Define_StaticFields
{
  int32_t PB_MAP_X;
  int32_t PB_PATH;
  int32_t PB_MCRD_NOCRD;
};
"""


def test_enum_emitted_in_its_own_header_not_as_struct() -> None:
    out = smt3dump.generate(_ENUM_C, meta=_META)
    assert "il2cpp_enums.h" not in out  # no shared enums header, per-file now
    nd = out["newdata.h"]
    assert "typedef enum {" in nd
    assert "ATTR_NON = -1," in nd
    assert "} ATTR_ATK;" in nd
    # the enum's value__ struct is NOT emitted, and a same-file field uses the enum name
    assert "struct ATTR_ATK {" not in nd
    assert "ATTR_ATK attr;" in nd


def test_enum_referenced_cross_file_is_included() -> None:
    src = _ENUM_C + (
        "\nstruct model_H_user_t_Fields\n{\n  struct newdata_H_ATTR_ATK_o kind;\n};\n"
    )
    out = smt3dump.generate(src, meta=_META)
    model = out["model.h"]
    assert '#include "newdata.h"' in model  # enum lives in newdata.h -> pull it in
    assert "ATTR_ATK kind;" in model


def test_define_values_from_metadata() -> None:
    out = smt3dump.generate(_ENUM_C, meta=_META)
    pb = out["pb.h"]
    assert "#define PB_MAP_X 20" in pb
    assert '#define PB_PATH "data/x"' in pb
    assert "#define PB_MCRD_NOCRD UNKNOWN_DEFINE_VALUE" in pb  # no value in metadata


def test_decode_value() -> None:
    from smt3.metadata import decode_value

    assert decode_value(b"") is None
    assert decode_value(b"\x14\x00\x00\x00") == 20  # int32
    assert decode_value(b"\x00\x00\x00\x00") == 0  # 4-byte zero must not read as ""
    assert decode_value(b"\xff") == -1  # signed byte
    assert decode_value(b"\x03\x00\x00\x00abc") == "abc"  # length-prefixed string
    assert decode_value(bytes(range(16))) == bytes(range(16)).hex()  # opaque blob


def test_no_metadata_still_works() -> None:
    out = smt3dump.generate(_ENUM_C)  # meta=None
    assert "il2cpp_enums.h" not in out
    assert "struct ATTR_ATK {" in out["newdata.h"]  # falls back to the value__ struct


# --- function prototypes from the .c ------------------------------------

_DECLS = """\
void __fastcall libsdf_H_sdfModelNode_t___ctor(libsdf_H_sdfModelNode_t_o *this, const MethodInfo *method);
float __fastcall libsdf_H_SDF_VU0__GetLen(sdfVector4_t v, const MethodInfo *method);
basic_H_dds3Basic_t_o *__fastcall fldMain__fldGetUnit(field_H_fldResourcePoint_t_o *__struct_ptr p, const MethodInfo *m);
bool __fastcall fldMain__fldChk(const MethodInfo *method);
void __fastcall System_String___ctor(System_String_o *this, const MethodInfo *method);
__int64 __fastcall sub_17C8640(__int64 a1, __int64 a2, int32_t *a3);
"""


def test_function_prototypes_parsed_and_cleaned() -> None:
    p = smt3dump.function_prototypes(_DECLS.splitlines())
    # cleaned components: __fastcall + MethodInfo dropped, _o types resolved
    ret, sig, refs = p["libsdf_H_sdfModelNode_t___ctor"]
    assert (ret, sig) == ("void", "sdfModelNode_t *this")
    assert "sdfModelNode_t" in refs
    ret2, sig2, _ = p["fldMain__fldGetUnit"]
    assert (ret2, sig2) == ("dds3Basic_t *", "fldResourcePoint_t *p")
    assert p["fldMain__fldChk"][:2] == ("bool", "void")


def test_il2cpp_methods_are_filtered() -> None:
    decls = "\n".join(
        f"void __fastcall {n}(int32_t *this, const MethodInfo *m);"
        for n in (
            "fldMain___ctor",  # constructor
            "cmp_H_Foo__get_Hp",  # property getter
            "cmp_H_Foo__set_Hp",  # property setter
            "cmp_H_Foo__op_Addition",  # operator
            "Foo__ToString",  # Object method
            "Bar__System_IDisposable_Dispose",  # interface impl
            "Baz__Invoke",  # delegate invoke
            "CmpDraw_Arrays__DeleteArray_object_",  # il2cpp array helper
            "Qux__InitializeWithDefaultInstances_object_",
        )
    )
    # plus two real game functions that must survive
    decls += "\nbool __fastcall fldMain__fldSetUnit(const MethodInfo *m);"
    decls += "\nint32_t __fastcall cmp_H_Foo__GetHp(int32_t *this, const MethodInfo *m);"
    out = smt3dump.generate("struct fldMain_StaticFields\n{\n  int32_t x;\n};\n",
                            protos=smt3dump.function_prototypes(decls.splitlines()))
    blob = "".join(out.values())
    for gone in ("___ctor", "get_Hp", "set_Hp", "op_Addition", "ToString", "Dispose",
                 "Invoke", "DeleteArray", "InitializeWithDefaultInstances"):
        assert gone not in blob, gone
    assert "bool fldSetUnit(void) {" in out["fldMain.c"]  # real function kept (as a stub)
    assert "GetHp" in blob  # real Get* (capital) kept, not confused with get_


_BODIES = """\
void __fastcall fldMain__fldSetUnit(const MethodInfo *method)
{
  if ( x )
    ScrTraceCode__CodeFunc_Add(a, b);
  v3 = il2cpp::NewSpecific(byte___TypeInfo, 4u);
  fldMain__fldChk();
  ScrTraceCode__CodeFunc_Add(c, d);
}
void __fastcall System_String___ctor(System_String_o *this, const MethodInfo *method)
{
  fldMain__fldChk();
}
"""


def test_call_graph_extraction() -> None:
    valid = frozenset({"ScrTraceCode__CodeFunc_Add", "fldMain__fldChk"})
    g = smt3dump.call_graph(_BODIES.splitlines(), valid)
    # only valid callees, deduped, in first-seen order; il2cpp:: and keywords ignored
    assert g["fldMain__fldSetUnit"] == ["ScrTraceCode__CodeFunc_Add", "fldMain__fldChk"]


def test_call_graph_renders_in_stub_body() -> None:
    protos = smt3dump.function_prototypes(
        ["void __fastcall fldMain__fldSetUnit(const MethodInfo *m);"]
    )
    graph = {"fldMain__fldSetUnit": ["ScrTraceCode__CodeFunc_Add", "fldMain__fldChk"]}
    text = "struct fldMain_StaticFields\n{\n  int32_t x;\n};\n"
    out = smt3dump.generate(text, protos=protos, graph=graph)
    stub = out["fldMain.c"]
    assert "void fldSetUnit(void) {" in stub
    assert "    CodeFunc_Add();" in stub  # callee names stripped like function names
    assert "    fldChk();" in stub


_SIMPLE_FN = """\
int32_t __fastcall datCalc__datGetParam(newdata_H_datUnitWork_t_o *work, const MethodInfo *method)
{
  int32_t BaseParam; // w0
  if ( (byte_3F5A210 & 1) == 0 )
  {
    il2cpp::InitializeMethodMetadata(0x40DDu);
    byte_3F5A210 = 1;
  }
  BaseParam = datCalc__datGetBaseParam(work, 3, method);
  return work->fields.level + BaseParam;
}
"""


def test_clean_bodies_strips_boilerplate() -> None:
    bodies, reasons = smt3dump.clean_bodies(_SIMPLE_FN.splitlines())
    body = bodies["datCalc__datGetParam"]
    assert "InitializeMethodMetadata" not in body  # metadata guard gone
    assert "MethodInfo" not in body and "byte_3F5A210" not in body
    assert "datGetBaseParam(work, 3)" in body  # method-context arg + name mangling stripped
    assert "work->level" in body  # ->fields. collapsed
    assert not reasons  # this one is simple


def test_clean_bodies_static_fields_and_reason() -> None:
    fn = (
        "void __fastcall dds3__Init(const MethodInfo *method)\n{\n"
        "  v3->static_fields->DDS3_GBWK = 0;\n"
        "  sub_8FC2C0(v3);\n}\n"  # sub_ helper -> complex
    )
    bodies, reasons = smt3dump.clean_bodies(fn.splitlines())
    assert "dds3__Init" not in bodies  # complex -> not reconstructed
    assert reasons["dds3__Init"] == "inlined sub_ helper(s)"


def test_clean_body_strips_typeinfo_and_metadata_variants() -> None:
    # the `if (byte & 1) == 0 { InitMeta(); }` variant (no `byte = 1`) + dead TypeInfo lines
    fn = (
        "int __fastcall m__f(const MethodInfo *x)\n{\n"
        "  dds3GlobalWork_c *dds3GlobalWork_TypeInfo;\n"
        "  if ( (byte_3F5A20B & 1) == 0 )\n  {\n"
        "    il2cpp::InitializeMethodMetadata(0x40ABu);\n  }\n"
        "  dds3GlobalWork_TypeInfo = ::dds3GlobalWork_TypeInfo;\n"
        "  return dds3GlobalWork_TypeInfo->static_fields->GBWK->fields.hp;\n}\n"
    )
    bodies, _ = smt3dump.clean_bodies(fn.splitlines())
    body = bodies["m__f"]
    assert "InitializeMethodMetadata" not in body
    assert "_TypeInfo" not in body
    assert "return GBWK->hp;" in body  # static_fields + ->fields. collapsed


def test_entangled_metadata_is_stubbed_not_mangled() -> None:
    # a cctor guard wrapping real code -> stripping breaks control flow -> keep as a stub
    fn = (
        "void __fastcall m__g(const MethodInfo *x)\n{\n"
        "  if ( v5 && !v3->_2.cctor_finished )\n  {\n"
        "    il2cpp::TypeInitializer(v3, x);\n"
        "    GBWK->static_fields->hp = v7;\n  }\n"
        "  else\n  {\n    GBWK->hp = v7;\n  }\n}\n"
    )
    bodies, reasons = smt3dump.clean_bodies(fn.splitlines())
    assert "m__g" not in bodies  # not reconstructed
    assert "woven" in reasons["m__g"] or "unbalanced" in reasons["m__g"]


def test_static_fields_global_collapses() -> None:
    fn = "int __fastcall m__f(const MethodInfo *x)\n{\n  return v3->static_fields->DDS3_GBWK;\n}\n"
    bodies, _ = smt3dump.clean_bodies(fn.splitlines())
    assert bodies["m__f"] == "  return DDS3_GBWK;"


def test_bodies_mode_emits_real_body_and_complex_note() -> None:
    protos = smt3dump.function_prototypes(
        ["int32_t __fastcall datCalc__datGetParam(newdata_H_datUnitWork_t_o *work, "
         "const MethodInfo *m);"]
    )
    bodies, reasons = smt3dump.clean_bodies(_SIMPLE_FN.splitlines())
    out = smt3dump.generate(
        "struct datCalc_StaticFields\n{\n  int32_t x;\n};\n",
        protos=protos, bodies=bodies, reasons=reasons,
    )
    c = out["datCalc.c"]
    assert "s32 datGetParam(datUnitWork_t *work) {" in c
    assert "work->level" in c  # real logic, not a call-graph stub


def test_struct_s_t_typedef_alias() -> None:
    # foo_s is defined; foo_t is only used (as _o) -> emit `typedef struct foo_s foo_t;`
    text = (
        "struct newdata_H_datUnitWork_s_Fields\n{\n  int32_t level;\n};\n\n"
        "struct newdata_H_holder_s_Fields\n{\n  struct newdata_H_datUnitWork_t_o *w;\n};\n"
    )
    nd = smt3dump.generate(text)["newdata.h"]
    assert "struct datUnitWork_s {" in nd
    assert "typedef struct datUnitWork_s datUnitWork_t;" in nd  # the alias
    assert "typedef struct datUnitWork_t datUnitWork_t;" not in nd  # not a bogus self-typedef
    assert "datUnitWork_t *w;" in nd  # the field uses the typedef, now a complete type


def test_proto_name_strips_owner() -> None:
    assert smt3dump.proto_name("ScrTraceCode__CodeFunc_Add") == "CodeFunc_Add"
    assert smt3dump.proto_name("fldMain__fldChk") == "fldChk"
    # a header type keeps its type qualifier (unique within the shared header)
    assert smt3dump.proto_name("libsdf_H_SDF_VU0__GetLen") == "SDF_VU0__GetLen"


def test_prototypes_routed_and_name_stripped() -> None:
    protos = smt3dump.function_prototypes(_DECLS.splitlines())
    # a minimal dump so fldMain is a known module (functions fold into fldMain.c)
    text = "struct fldMain_StaticFields\n{\n  int32_t x;\n};\n"
    out = smt3dump.generate(text, protos=protos)
    # functions become stubs in a .c (definitions live in .c, headers stay types-only)
    assert "f32 SDF_VU0__GetLen(sdfVector4_t v) {" in out["libsdf.c"]
    # module function -> the module .c, module prefix stripped
    assert "bool fldChk(void) {" in out["fldMain.c"]
    assert "sdfModelNode_t___ctor" not in "".join(out.values())  # ctor filtered out
    assert "String" not in "".join(out.values())  # System_String dropped
    assert "sub_17C8640" not in "".join(out.values())  # unnamed helper dropped


def test_common_has_unity_math() -> None:
    out = smt3dump.generate(FIXTURE.read_text())
    common = out["il2cpp_common.h"]
    assert "sdfVector4_t" in common
    assert "sdfMatrix4_t" in common
    assert "#include <stdint.h>" in common


def test_math_wrapper_type_skipped_no_recursion() -> None:
    # The real libsdf sdfMatrix4_t wraps the Unity matrix; common provides sdfMatrix4_t,
    # so the wrapper must be skipped (no `struct sdfMatrix4_t { sdfMatrix4_t pm; }`).
    assert smt3dump.route("libsdf_H_sdfMatrix4_t_Fields", nonempty=True) is None
    out = smt3dump.generate(FIXTURE.read_text())
    assert "struct sdfMatrix4_t {" not in out.get("libsdf.h", "")


def test_common_has_decomp_typedefs() -> None:
    common = smt3dump.generate(FIXTURE.read_text())["il2cpp_common.h"]
    assert "typedef int32_t s32;" in common
    assert "typedef uint32_t u32;" in common
    assert "typedef float f32;" in common
    assert "typedef struct { f32 x, y, z, w; } sdfVector4_t;" in common


# --- function display names (module-prefix stripping) --------------------


def test_display_map_strips_cross_file_ambiguity_but_keeps_same_file() -> None:
    protos = {
        n: ("void", "void", set[str]())
        for n in (
            "dds3KernelCore__dds3StartProcess",  # -> dds3KernelCore.c
            "fclShare__dds3StartProcess",  # -> fclShare.c (different file)
            "fldSky_FIL_t__Copy",  # both fold into fldSky.c (same file)
            "fldSky_typeSKYTBL__Copy",
        )
    }
    modules = frozenset({"dds3KernelCore", "fclShare", "fldSky"})
    dmap = smt3dump.display_map(protos, modules)
    # same stripped name but different files -> stripped for readability
    assert dmap["dds3KernelCore__dds3StartProcess"] == "dds3StartProcess"
    assert dmap["fclShare__dds3StartProcess"] == "dds3StartProcess"
    # same stripped name colliding in one file -> full names kept (no redefinition)
    assert dmap["fldSky_FIL_t__Copy"] == "fldSky_FIL_t__Copy"
    assert dmap["fldSky_typeSKYTBL__Copy"] == "fldSky_typeSKYTBL__Copy"


def test_clean_body_maps_plain_c_spellings() -> None:
    fn = "void __fastcall m__f(const MethodInfo *x)\n{\n  unsigned int a;\n  int b;\n  a = b;\n}\n"
    body = smt3dump.clean_bodies(fn.splitlines())[0]["m__f"]
    assert "u32 a;" in body  # plain `unsigned int` -> u32 (not `unsigned s32`)
    assert "s32 b;" in body


def test_clean_body_calls_follow_display_map() -> None:
    fn = "void __fastcall A__f(const MethodInfo *m)\n{\n  A_x_t__Set();\n  B__g();\n}\n"
    names = {"A_x_t__Set": "A_x_t__Set", "B__g": "g"}  # first kept full, second stripped
    bodies, _ = smt3dump.clean_bodies(fn.splitlines(), names)
    body = bodies["A__f"]
    assert "A_x_t__Set();" in body  # same-file collision -> full name preserved
    assert "  g();" in body  # unambiguous -> stripped


def test_clean_body_drops_unused_local_declarations() -> None:
    fn = (
        "void __fastcall m__f(const MethodInfo *x)\n{\n"
        "  s64 v1;\n"
        "  dds3TitleMain_c *v2;\n"
        "  s32 keep;\n"
        "  keep = 5;\n"
        "  GBWK = keep;\n}\n"
    )
    body = smt3dump.clean_bodies(fn.splitlines())[0]["m__f"]
    assert "v1" not in body  # declared once, never used
    assert "v2" not in body
    assert "s32 keep;" in body  # used -> kept


def test_clean_body_reconciles_call_arity() -> None:
    fn = (
        "void __fastcall m__f(const MethodInfo *x)\n{\n"
        "  sdfTexFree(handle, 0);\n"     # proto arity 1, trailing 0 = MethodInfo
        "  p2sdPlaySE(0, 0);\n"          # first 0 real, second is context
        "  p2sdPlaySE(0);\n"             # already correct, untouched
        "  AddComponent(obj, Method_Foo);\n}\n"  # Method_ literal dropped regardless of arity
    )
    arity = {"sdfTexFree": 1, "p2sdPlaySE": 1}
    body = smt3dump.clean_bodies(fn.splitlines(), None, arity)[0]["m__f"]
    assert "sdfTexFree(handle);" in body
    assert "p2sdPlaySE(0);" in body
    assert "p2sdPlaySE(0, 0)" not in body
    assert "AddComponent(obj);" in body


def test_function_addresses_from_separators() -> None:
    src = [
        "//----- (0000000000FFB9B0) ----------------------------------------------------",
        "void __fastcall dds3TitleMain__dds3TitleInit(dds3TitleMain_o *this, int32_t mode)",
        "{",
        "  return;",
        "}",
        "//----- (00000000000002D0) ----------------------------------------------------",
        "int64_t __fastcall B__bar(const MethodInfo *m)",
        "{",
        "  return 0;",
        "}",
    ]
    assert smt3dump.function_addresses(src) == {
        "dds3TitleMain__dds3TitleInit": 0xFFB9B0,
        "B__bar": 0x2D0,
    }


_MODULE_TEXT = "struct fldMain_StaticFields\n{\n  int32_t g;\n};\n"


def test_generate_annotates_function_address() -> None:
    protos = smt3dump.function_prototypes(
        ["void __fastcall fldMain__fldFoo(int32_t x, const MethodInfo *m);"]
    )
    out = smt3dump.generate(
        _MODULE_TEXT, protos=protos, addresses={"fldMain__fldFoo": 0x1234560}
    )
    assert "// 0x1234560" in out["fldMain.c"]


def test_symbol_map_orders_by_address() -> None:
    protos = smt3dump.function_prototypes(
        [
            "void __fastcall fldMain__b(const MethodInfo *m);",
            "void __fastcall fldMain__a(const MethodInfo *m);",
        ]
    )
    modules = smt3dump._module_bases(list(smt3dump.parse_blocks(_MODULE_TEXT)))
    text = smt3dump.symbol_map(
        protos, {"fldMain__b": 0x200, "fldMain__a": 0x100}, modules
    )
    rows = [ln for ln in text.splitlines() if not ln.startswith("#")]
    assert rows[0].split() == ["0x00000100", "a", "fldMain.c"]
    assert rows[1].split() == ["0x00000200", "b", "fldMain.c"]


def test_map_symbols_parses_text_publics() -> None:
    lines = [
        " 00000004:00000000017B52C0       dds3KernelCore$$dds3StartProcess",
        " 00000004:0000000000000220       TMPro.CaretInfo$$.ctor",
        " 0000000B:0000000000000010       xmmword_10",   # data segment, ignored
        " 00000004:0000000000000030       .init_proc",   # no $$, ignored
    ]
    syms = smt3dump.map_symbols(lines)
    assert syms["dds3KernelCore__dds3StartProcess"] == (
        0x17B52C0, "dds3KernelCore$$dds3StartProcess"
    )
    assert syms["TMPro_CaretInfo___ctor"] == (0x220, "TMPro.CaretInfo$$.ctor")
    assert all("xmmword" not in n for n in syms)  # data + unnamed skipped
    assert ".init_proc" not in syms


def test_symbol_map_includes_linker_name() -> None:
    protos = smt3dump.function_prototypes(
        ["void __fastcall fldMain__a(const MethodInfo *m);"]
    )
    modules = smt3dump._module_bases(list(smt3dump.parse_blocks(_MODULE_TEXT)))
    text = smt3dump.symbol_map(
        protos, {"fldMain__a": 0x100}, modules, {"fldMain__a": "fldMain$$a"}
    )
    row = [ln for ln in text.splitlines() if not ln.startswith("#")][0]
    assert row.split() == ["0x00000100", "a", "fldMain.c", "fldMain$$a"]
