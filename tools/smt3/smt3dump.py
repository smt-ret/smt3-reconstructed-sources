from __future__ import annotations

import argparse
import json
import re
from collections import Counter
from collections.abc import Iterable, Iterator
from dataclasses import dataclass
from pathlib import Path

from smt3.metadata import Metadata

# Top-level namespace tokens that are .NET/Unity/IL2CPP runtime, not game code. Applied to
# `_H_`-less declarations (module globals) and to unresolved external member types.
RUNTIME: frozenset[str] = frozenset(
    {
        "System",
        "Mono",
        "Microsoft",
        "UnityEngine",
        "UnityEngineInternal",
        "Unity",
        "TMPro",
        "Il2Cpp",
        "I18N",
        "Locale",
        "SR",
        "Newtonsoft",
        "nn",  # Nintendo Switch OS SDK (nn::ec, nn::account, ...)
    }
)

# IL2CPP per-type wrapper suffixes; the payload type name is what precedes them.
_WRAPPERS = ("_o", "_Fields", "_StaticFields", "_VTable", "_RGCTXs", "_c")

# C primitives already present verbatim in the dump.
_PRIMITIVE = re.compile(
    r"^(?:u?int(?:8|16|32|64)_t|u?intptr_t|size_t|float|double|bool|char|void)$"
)

# System.* value types -> decomp-friendly C (s8/u32/f32/..., see types.h).
# System_String/_Object resolve through their pointer.
_IL2CPP_TYPE_TO_DECOMP_TYPE: dict[str, str] = {
    "System_SByte": "s8",
    "System_Byte": "u8",
    "System_Int16": "s16",
    "System_UInt16": "u16",
    "System_Int32": "s32",
    "System_UInt32": "u32",
    "System_Int64": "s64",
    "System_UInt64": "u64",
    "System_Single": "f32",
    "System_Double": "f64",
    "System_Boolean": "bool",
    "System_Char": "u16",
    "System_IntPtr": "intptr_t",
    "System_UIntPtr": "uintptr_t",
    "System_String": "char",  # a string reference is char*; the member's own * remains
    "System_Object": "void",
    "Il2CppObject": "void",
}

# Fixed-width C primitives already in the dump -> the same decomp aliases.
_STDINT_TYPE_TO_DECOMP_TYPE: dict[str, str] = {
    "int8_t": "s8", "uint8_t": "u8",
    "int16_t": "s16", "uint16_t": "u16",
    "int32_t": "s32", "uint32_t": "u32",
    "int64_t": "s64", "uint64_t": "u64",
    "float": "f32", "double": "f64",
}

# The port replaced the game's math types with UnityEngine ones; map them back to inferred
# original sdf names (concrete typedefs in types.h). Best-guess reconstructions.
_UNITY_TO_SDF_TYPE: dict[str, str] = {
    "UnityEngine_Vector2": "sdfVector2_t",
    "UnityEngine_Vector3": "sdfVector3_t",
    "UnityEngine_Vector4": "sdfVector4_t",
    "UnityEngine_Quaternion": "sdfQuaternion_t",
    "UnityEngine_Matrix4x4": "sdfMatrix4_t",
    "UnityEngine_Color": "sdfColor_t",
    "UnityEngine_Color32": "sdfColor32_t",
}

# IL2CPP array element TypeInfo names that are value types (stored inline); the rest are
# reference types (arrays of pointers). Distinguishes `elem name[N]` from `elem *name[N]`.
VALUE_TYPES: frozenset[str] = frozenset(
    {
        "byte", "sbyte", "short", "ushort", "int", "uint", "long", "ulong",
        "char", "float", "double", "bool", "intptr", "uintptr",
        "UnityEngine_Vector2", "UnityEngine_Vector3", "UnityEngine_Vector4",
        "UnityEngine_Quaternion", "UnityEngine_Matrix4x4",
        "UnityEngine_Color", "UnityEngine_Color32",
    }
)

# Names types.h defines concretely. A real `_H_` type with one of these names (e.g.
# libsdf's sdfMatrix4_t, which wraps the Unity matrix) is skipped to avoid a duplicate
# definition, and such names are never forward-declared.
MATH_PROVIDED: frozenset[str] = frozenset(_UNITY_TO_SDF_TYPE.values())

COMMON_HEADER = "types.h"

_COMMON_BODY = """\
#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef int8_t s8;
typedef uint8_t u8;
typedef int16_t s16;
typedef uint16_t u16;
typedef int32_t s32;
typedef uint32_t u32;
typedef int64_t s64;
typedef uint64_t u64;
typedef float f32;
typedef double f64;

#define UNKNOWN_ARRAY_SIZE 1
#define UNKNOWN_DEFINE_VALUE 0

typedef struct { f32 x, y; } sdfVector2_t;
typedef struct { f32 x, y, z; } sdfVector3_t;
typedef struct { f32 x, y, z, w; } sdfVector4_t;
typedef struct { f32 x, y, z, w; } sdfQuaternion_t;
typedef struct { f32 m[16]; } sdfMatrix4_t;
typedef struct { f32 r, g, b, a; } sdfColor_t;
typedef struct { u8 r, g, b, a; } sdfColor32_t;
"""


@dataclass(frozen=True)
class Block:
    name: str
    members: list[str]


@dataclass(frozen=True)
class Resolved:
    text: str  # clean C type token
    ref: str | None  # struct tag needing a per-file forward declaration, else None


_START = re.compile(r"^struct ([A-Za-z_][A-Za-z0-9_]*)$")
# `[struct] TYPE [*...] name;`
_MEMBER = re.compile(
    r"^(?:struct\s+)?([A-Za-z_][A-Za-z0-9_]*)\s*([*\s]*)\s*([A-Za-z_][A-Za-z0-9_]*)\s*;$"
)


# Array-size recovery from the transpiled .c constructors:
#   this->fields.<f>            = il2cpp::NewSpecific(<elem>___TypeInfo, <N>u);   (instance)
#   <Class>_TypeInfo->static_fields->.<f> = <v>;  <v> = NewSpecific(...);         (static)
_THIS_PARAM = re.compile(r"(\w+)_o \*this\b")  # the receiver param (own line or inline)
# Whitespace-tolerant so it still matches after multi-line calls are joined with spaces.
_NEWSPEC = re.compile(r"il2cpp::NewSpecific\(\s*(\w+)___TypeInfo,\s*(0x[0-9A-Fa-f]+|\d+)u?\s*\)")
_VAR_ALLOC = re.compile(r"^(\w+) = il2cpp::NewSpecific\(")
_THIS_FIELD = re.compile(r"^this->fields\.(\w+) = (.+);$")
_STATIC_FIELD = re.compile(r"^(\w+)_TypeInfo->static_fields->(\w+) = (.+);$")

# (struct-or-class base, field) -> (element count, element-is-value-type)
ArraySizes = dict[tuple[str, str], tuple[int, bool]]

def _rhs_alloc(rhs: str, var_alloc: dict[str, tuple[str, int]]) -> tuple[str, int] | None:
    m = _NEWSPEC.search(rhs)
    if m:
        return (m.group(1), int(m.group(2), 0))
    return var_alloc.get(rhs.strip())

def _logical_lines(lines: Iterable[str]) -> Iterator[str]:
    it = iter(lines)
    for raw in it:
        s = raw.strip()
        if not s.endswith("il2cpp::NewSpecific("):
            yield s
            continue
        parts = [s]
        depth = s.count("(") - s.count(")")
        while depth > 0 and len(parts) <= 4:
            try:
                nxt = next(it).strip()
            except StopIteration:
                break
            parts.append(nxt)
            depth += nxt.count("(") - nxt.count(")")
        yield " ".join(parts)


def array_sizes(lines: Iterable[str]) -> ArraySizes:
    """Recover fixed array element counts from constructor ``NewSpecific()`` allocations."""
    sizes: ArraySizes = {}
    cur_struct: str | None = None
    var_alloc: dict[str, tuple[str, int]] = {}
    for line in _logical_lines(lines):
        if "__fastcall" in line:  # function boundary: reset local state
            var_alloc = {}
            cur_struct = None
        if tp := _THIS_PARAM.search(line):
            cur_struct = tp.group(1)
            continue
        if line.startswith("this->fields."):
            fm = _THIS_FIELD.match(line)
            if cur_struct and fm and (alloc := _rhs_alloc(fm.group(2), var_alloc)):
                elem, n = alloc
                if n:
                    sizes[cur_struct, fm.group(1)] = (n, elem in VALUE_TYPES)
        elif "_TypeInfo->static_fields->" in line:
            sm = _STATIC_FIELD.match(line)
            if sm and (alloc := _rhs_alloc(sm.group(3), var_alloc)):
                elem, n = alloc
                if n:
                    sizes[sm.group(1), sm.group(2)] = (n, elem in VALUE_TYPES)
        elif (am := _VAR_ALLOC.match(line)) and (nm := _NEWSPEC.search(line)):
            var_alloc[am.group(1)] = (nm.group(1), int(nm.group(2), 0))
    return sizes

# Function declarations in the transpiled .c: `<ret> __fastcall <name>(<params>);`
_PROTO = re.compile(r"^([A-Za-z_][\w *]*?[ *])__fastcall (\w+)\((.*)\);")
_PARAM_NAME = re.compile(r"^(.*[ *])(\w+)$")

def _clean_ctype(expr: str) -> tuple[str, int, str | None]:
    """Clean a C type expression to (base type, pointer depth, referenced tag)."""
    expr = expr.replace("const ", "").replace("struct ", "").replace("__struct_ptr", "")
    stars = expr.count("*")
    tok = expr.replace("*", "").strip()
    depth = 0
    while tok.endswith("_array"):  # a managed array passed/returned is a pointer
        tok = tok[: -len("_array")]
        depth += 1
    r = resolve_base(tok)
    return r.text, stars + depth, r.ref

def _clean_prototype(ret: str, args: str) -> tuple[str, str, set[str]]:
    """Clean a declaration to (return type, param signature, referenced tags)."""
    refs: set[str] = set()

    def ptr(text: str, n: int) -> str:
        return f"{text} {'*' * n}" if n else text

    rtext, rstars, rref = _clean_ctype(ret)
    if rref:
        refs.add(rref)
    params: list[str] = []
    for raw in args.split(","):
        p = raw.replace("__struct_ptr", "").strip()
        if not p or p == "void" or "MethodInfo" in p:  # drop the il2cpp method context
            continue
        pm = _PARAM_NAME.match(p)
        if not pm:
            text, n, ref = _clean_ctype(p)
            params.append(ptr(text, n))
        else:
            text, n, ref = _clean_ctype(pm.group(1))
            params.append(f"{ptr(text, n)}{'' if n else ' '}{pm.group(2)}")
        if ref:
            refs.add(ref)
    return ptr(rtext, rstars), ", ".join(params) if params else "void", refs


def proto_name(name: str) -> str:
    """Strip the owning class/namespace prefix from a mangled function name."""
    if "_H_" in name:
        return name.split("_H_", 1)[1]
    return name.split("__", 1)[1] if "__" in name else name


def function_prototypes(lines: Iterable[str]) -> dict[str, tuple[str, str, set[str]]]:
    """Parse function declarations to ``{name: (return, params, refs)}``."""
    protos: dict[str, tuple[str, str, set[str]]] = {}
    for raw in lines:
        line = raw.strip()
        if "__fastcall" not in line or ");" not in line:
            continue
        m = _PROTO.match(line)
        if m:
            protos[m.group(2)] = _clean_prototype(m.group(1), m.group(3))
    return protos

_DEF_HEADER = re.compile(r"__fastcall (\w+)\(")
_CALL = re.compile(r"\b([A-Za-z_]\w*)\s*\(")
_ADDR_SEP = re.compile(r"^//----- \(0*([0-9A-Fa-f]+)\)")

def function_addresses(lines: Iterable[str]) -> dict[str, int]:
    """Parse Hex-Rays ``//----- (ADDR) ----`` separators to ``{function name: address}``."""
    out: dict[str, int] = {}
    pending: int | None = None
    for raw in lines:
        if pending is not None:
            if raw.strip():
                if (d := _DEF_HEADER.search(raw)) and not raw.strip().endswith(";"):
                    out.setdefault(d.group(1), pending)
                pending = None
            continue
        if m := _ADDR_SEP.match(raw):
            pending = int(m.group(1), 16)
    return out

# IDA .map "Publics by Value": ``SEGMENT:OFFSET       name``. Code lives in .text (0004).
_MAP_SYM = re.compile(r"^ ([0-9A-Fa-f]{8}):([0-9A-Fa-f]{16})\s+(\S+)$")

def map_symbols(lines: Iterable[str]) -> dict[str, tuple[int, str]]:
    """Parse an IDA ``.map`` to ``{mangled name: (address, linker symbol)}`` for code symbols.

    The linker ``Class$$method`` / ``Namespace.Type`` spelling is converted to the Hex-Rays
    ``__`` / ``_`` form the rest of the tool keys on.
    """
    out: dict[str, tuple[int, str]] = {}
    for raw in lines:
        m = _MAP_SYM.match(raw)
        if m is None or m.group(1) != "00000004" or "$$" not in m.group(3):
            continue
        linker = m.group(3)
        mangled = linker.replace("$$", "__").replace(".", "_")
        out.setdefault(mangled, (int(m.group(2), 16), linker))
    return out

def call_graph(lines: Iterable[str], valid: frozenset[str]) -> dict[str, list[str]]:
    """Map each function to the ``valid`` game functions it calls, in first-seen order."""
    graph: dict[str, list[str]] = {}
    cur: str | None = None
    seen: set[str] = set()
    state = "top"  # top -> sig -> body
    for raw in lines:
        line = raw.strip()
        if state == "top":
            if "__fastcall" in line and not line.endswith(";"):
                m = _DEF_HEADER.search(line)
                if m:
                    cur, seen, state = m.group(1), set[str](), "sig"
        elif state == "sig":  # skip the (possibly multi-line) signature
            if line.endswith(";"):  # was a declaration, not a definition
                state = "top"
            elif line.endswith("{") or line == "{":
                graph.setdefault(cur, [])  # type: ignore[arg-type]
                state = "body"
        else:  # body
            if raw.startswith("}"):  # column-0 brace ends the function (nested ones indent)
                state = "top"
                continue
            for c in _CALL.finditer(line):
                name = c.group(1)
                if name != cur and name in valid and name not in seen:
                    seen.add(name)
                    graph[cur].append(name)  # type: ignore[index]
    return graph

# Deterministic IL2CPP-boilerplate strip, turning a Hex-Rays body into readable pseudo-C.
_META_GUARD = re.compile(
    r"\n[ \t]*if \( \(byte_[0-9A-F]+ & 1\) == 0 \)\n[ \t]*\{"
    r"\n(?:[^\n]*\n)*?[ \t]*byte_[0-9A-F]+ = 1;\n[ \t]*\}"
)
# The braceless forms. `_strip_typeinit_blocks` cuts the braced one by counting braces: a
# non-greedy regex stops at a nested `}` and leaves the body unbalanced.
_TYPEINIT = re.compile(
    r"\n[ \t]*if \([^\n]*cctor_finished \)\n[ \t]*il2cpp::TypeInitializer\([^\n]*\);"
    r"|\n[ \t]*il2cpp::TypeInitializer\([^\n]*\);"
)
_TYPEINIT_GUARD = re.compile(r"\n([ \t]*)if \([^\n]*cctor_finished \)\n[ \t]*\{")


def _strip_typeinit_blocks(b: str) -> str:
    """Remove `if (... cctor_finished) { ... }` blocks, matching braces properly."""
    while (m := _TYPEINIT_GUARD.search(b)) is not None:
        i = b.index("{", m.start())
        depth = 0
        for j in range(i, len(b)):
            if b[j] == "{":
                depth += 1
            elif b[j] == "}":
                depth -= 1
                if depth == 0:
                    b = b[: m.start()] + b[j + 1 :]
                    break
        else:
            return b  # unterminated: leave it alone rather than cut something wrong
    return b
# A body too tangled for a naive strip: an inlined unnamed helper, or irreducible control
# flow the cleaner could not remove. Reported by `clean_bodies`, but still emitted.
_COMPLEX = re.compile(r"\bsub_[0-9A-Fa-f]+|\bgoto\b|\bLABEL_")

# Whole-line IL2CPP scaffolding to delete (metadata init, cctor/type-info, exception throws).
# The class-TypeInfo pointer is dead once `x->static_fields->G` collapses to `G`, so its
# decl/assignments go; the element TypeInfo inside NewSpecific/Allocate is kept but cleaned.
_JUNK_LINE = re.compile(
    r"InitializeMethodMetadata|TypeInitializer|cctor_finished|_TypeInfo->_"
    r"|\*\w+_TypeInfo;|\w+_TypeInfo = |= :*\w+_TypeInfo;"
    r"|Il2CppExceptionWrapper|\w*Exception\w*\(|::Throw|Codegen"
    r"|const MethodInfo \*\w+;|byte_[0-9A-F]+ = 1;"
)
# `goto LABEL_n;` / `LABEL_n:` are control flow, not scaffolding: deleting them takes whole
# branches with them (a braceless `if (!dlc) goto LABEL_14;` loses its condition).

# A control statement with no `{`: its body is the single next statement, so deleting that
# statement as scaffolding leaves the guard standing over unrelated code.
_BRACELESS_CTRL = re.compile(r"^[ \t]*(?:\}[ \t]*)?(?:else[ \t]+)?(?:if|for|while)[ \t]*\(.*\)[ \t]*$")

_HEXRAYS_TYPE_TO_DECOMP_TYPE = [
    ("unsigned __int64", "u64"), ("unsigned __int32", "u32"),
    ("unsigned __int16", "u16"), ("unsigned __int8", "u8"),
    ("__int64", "s64"), ("__int32", "s32"), ("__int16", "s16"),
    ("__int8", "s8"), ("_QWORD", "u64"), ("_DWORD", "u32"),
    ("_WORD", "u16"), ("_BYTE", "u8"), ("_BOOL", "bool"),
]

_BASIC_C_TYPE_TO_DECOMP_TYPE = [
    ("unsigned int", "u32"), ("unsigned short", "u16"), ("unsigned char", "u8"),
    ("signed char", "s8"), ("int", "s32"), ("short", "s16"),
]

# Hex-Rays often lifts the class pointer into a local (`v = X->static_fields;`) instead of
# writing `X->static_fields->G` inline, which the inline collapse below cannot see.
_STATIC_BASE_LOCAL = re.compile(r"(?m)^[ \t]*(\w+) = &?[\w>.\-]+->static_fields;[ \t]*$\n?")

_STRING_LITERAL_REF = re.compile(r"\bStringLiteral_(\d+)\b")


def _c_string(text: str) -> str:
    """Render metadata text as a C string literal."""
    out = text.replace("\\", "\\\\").replace('"', '\\"')
    out = out.replace("\n", "\\n").replace("\r", "\\r").replace("\t", "\\t")
    return f'"{out}"'


def _resolve_string_literals(b: str, strings: dict[int, str] | None) -> str:
    """`StringLiteral_4529` -> the text it names, or the placeholder if it is unmapped."""
    if not strings:
        return b
    def sub(m: re.Match[str]) -> str:
        text = strings.get(int(m.group(1)))
        return _c_string(text) if text is not None else m.group(0)
    return _STRING_LITERAL_REF.sub(sub, b)


def _collapse_static_field_locals(b: str) -> str:
    """`v = X->static_fields; ... v->G` -> `G`. Runs after the inline collapse; the `->`
    lookbehind stops it eating `X->static_fields->G` when the local is named `static_fields`.
    """
    while (m := _STATIC_BASE_LOCAL.search(b)) is not None:
        local = m.group(1)
        b = b[: m.start()] + b[m.end() :]
        b = re.sub(rf"(?<![>\w]){re.escape(local)}->", "", b)
    return b


def _strip_empty_ifs(b: str) -> str:
    """Remove `if (cond) {}` guards left after their metadata/throw body was deleted."""
    for _ in range(6):
        # if (...) {} else  ->  keep the else body, drop the guard + else keyword
        new = re.sub(r"[ \t]*if \([^\n]*\)[ \t\n]*\{[ \t\n]*\}[ \t\n]*else\b", "", b)
        # if (...) {}  ->  gone
        new = re.sub(r"[ \t]*if \([^\n]*\)[ \t\n]*\{[ \t\n]*\}[ \t]*\n?", "", new)
        if new == b:
            return b
        b = new
    return b


_LOCAL_DECL = re.compile(
    r"^[ \t]+(?:struct[ \t]+)?[A-Za-z_]\w*(?:[ \t]+\**|\**[ \t]+)"
    r"([A-Za-z_]\w*)(?:\[[^\]]*\])?;[ \t]*$"
)
_DECL_KEYWORDS = frozenset(
    {"return", "break", "continue", "goto", "case", "else", "do", "while", "for",
     "if", "switch", "typedef"}
)

def _drop_unused_locals(b: str) -> str:
    """Remove local declarations (`TYPE name;`, no initializer) never referenced again."""
    uses: Counter[str] = Counter(re.findall(r"[A-Za-z_]\w*", b))
    kept: list[str] = []
    for ln in b.split("\n"):
        m = _LOCAL_DECL.match(ln)
        if m and ln.split()[0] not in _DECL_KEYWORDS and uses[m.group(1)] <= 1:
            continue  # declared once, never used
        kept.append(ln)
    return "\n".join(kept)


def _fix_call_arity(b: str, arity: dict[str, int]) -> str:
    """Drop the trailing IL2CPP context arg the cleaned prototypes already shed.

    The call keeps the ``MethodInfo`` the prototype dropped, so its arity is one too high;
    the tail goes only when it is that context (``0`` or ``Method_*``) and the arg list is
    flat.
    """
    method = re.compile(r"Method_\w+$")

    def repl(m: re.Match[str]) -> str:
        name, inner = m.group(1), m.group(2)
        n = arity.get(name)
        if n is None:
            return m.group(0)
        args = [a.strip() for a in inner.split(",")] if inner.strip() else []
        if len(args) == n + 1 and args and (args[-1] == "0" or method.match(args[-1])):
            args = args[:-1]
        return f"{name}({', '.join(args)})"

    return re.sub(r"\b([A-Za-z_]\w*)\(([^()]*)\)", repl, b)


def _clean_body(
    body: str,
    names: dict[str, str] | None = None,
    arity: dict[str, int] | None = None,
    strings: dict[int, str] | None = None,
) -> str:
    b = _META_GUARD.sub("", body) 
    b = _strip_typeinit_blocks(b)
    b = _TYPEINIT.sub("", b)
    temps = set(re.findall(r"const MethodInfo \*(\w+);", b)) | {"method"}
    kept: list[str] = []
    for raw in b.split("\n"):
        ln = re.sub(r"[ \t]*//.*$", "", raw)
        if not _JUNK_LINE.search(ln):
            kept.append(ln)
            continue
        # The deleted line was the single statement under a braceless guard, so the guard
        # now covers whatever follows. Drop it too, and repeat for a nested chain.
        while kept and _BRACELESS_CTRL.match(kept[-1]):
            kept.pop()
    b = "\n".join(kept)
    for t in temps:
        b = re.sub(rf",\s*{re.escape(t)}\b", "", b)
        b = re.sub(rf"\b{re.escape(t)}\s*,\s*", "", b)
        b = re.sub(rf"\(\s*{re.escape(t)}\s*\)", "()", b)
    b = re.sub(r"\bj_(?=[A-Za-z_])", "", b)  # Hex-Rays jump-thunk prefix (j_Allocate -> Allocate)
    b = b.replace("il2cpp::", "").replace("->fields.", "->").replace(".fields.", ".")
    b = _resolve_string_literals(b, strings)
    b = re.sub(r"\b\w+->static_fields->", "", b)  # `x->static_fields->G` is a global `G`
    b = _collapse_static_field_locals(b)

    def _call(m: re.Match[str]) -> str:
        full = m.group(1)
        return (names.get(full, proto_name(full)) if names else proto_name(full)) + "("

    b = re.sub(r"\b([A-Za-z_]\w*(?:_H_|__)\w+)\(", _call, b)
    b = b.replace("___TypeInfo", "").replace("_TypeInfo", "")  # NewSpecific(int, 6u) etc.
    b = re.sub(r"\b\w+_H_(\w+)", r"\1", b)  # drop file/namespace prefix on body type names
    for type, c in _HEXRAYS_TYPE_TO_DECOMP_TYPE:
        b = re.sub(rf"\b{re.escape(type)}\b", c, b)
    for type, d in _STDINT_TYPE_TO_DECOMP_TYPE.items():
        b = re.sub(rf"\b{type}\b", d, b)
    for type, d in _BASIC_C_TYPE_TO_DECOMP_TYPE:
        b = re.sub(rf"\b{type}\b", d, b)
    b = re.sub(r"\( +", "(", b)  # remove extra parenthesis padding
    b = re.sub(r" +\)", ")", b)
    b = re.sub(r"(?m)^[ \t]*(\w+) = \1;[ \t]*$\n?", "", b)  # dead self-assignments
    b = re.sub(r",\s*Method_\w+\s*\)", ")", b)  # trailing MethodInfo literal the proto drops
    b = re.sub(r"\(\s*Method_\w+\s*\)", "()", b)
    if arity:
        b = _fix_call_arity(b, arity)
    b = _strip_empty_ifs(b)
    b = _drop_unused_locals(b)
    b = re.sub(r"\n[ \t]*\n(?:[ \t]*\n)+", "\n\n", b)
    return b.strip("\n")


def _complexity(cleaned: str) -> str:
    """Why a body is too tangled to reconstruct; empty string means reconstruct it."""
    if m := _COMPLEX.search(cleaned):
        return "inlined sub_ helper(s)" if m.group(0).startswith("sub_") else "goto control flow"
    if cleaned.count("{") != cleaned.count("}"):
        return "unbalanced control flow"
    if len(re.findall(r"\belse\b", cleaned)) > len(re.findall(r"\bif\b", cleaned)):
        return "metadata woven into control flow"
    return "too many statements" if cleaned.count("\n") > 200 else ""


def clean_bodies(
    lines: Iterable[str],
    names: dict[str, str] | None = None,
    arity: dict[str, int] | None = None,
    strings: dict[int, str] | None = None,
) -> tuple[dict[str, str], dict[str, str]]:
    """Reconstruct bodies from the .c; return (bodies, reason-the-body-is-approximate)."""
    bodies: dict[str, str] = {}
    reasons: dict[str, str] = {}
    cur: str | None = None
    buf: list[str] = []
    state = "top"
    for raw in lines:
        line = raw.rstrip("\n")
        s = line.strip()
        if state == "top":
            if "__fastcall" in line and not s.endswith(";") and (m := _DEF_HEADER.search(line)):
                cur, state = m.group(1), "sig"
        elif state == "sig":
            if s.endswith(";"):
                state = "top"
            elif s == "{" or s.endswith("{"):
                buf, state = [], "body"
        elif raw.startswith("}"):
            if cur:
                cleaned = _clean_body("\n".join(buf), names, arity, strings)
                # Even a tangled body carries arithmetic, constants and field offsets a
                # stub throws away. Only a brace-unbalanced one is dropped: it would not
                # parse and would swallow the rest of the file.
                if reason := _complexity(cleaned):
                    reasons[cur] = reason
                if cleaned.count("{") == cleaned.count("}"):
                    bodies[cur] = cleaned
            state, cur = "top", None
        else:
            buf.append(line)
    return bodies, reasons


def parse_blocks(text: str) -> Iterator[Block]:
    """Yield every ``struct NAME { ... };`` definition (forward decls are skipped)."""
    lines = text.split("\n")
    i, n = 0, len(lines)
    while i < n:
        m = _START.match(lines[i])
        if m and i + 1 < n and lines[i + 1].strip() == "{":
            members: list[str] = []
            j = i + 2
            while j < n and not lines[j].startswith("};"):
                s = lines[j].strip()
                if s and not s.startswith("/"):
                    members.append(s)
                j += 1
            yield Block(m.group(1), members)
            i = j + 1
        else:
            i += 1


def _is_junk(base: str) -> bool:
    """Compiler/runtime-generated types that are not original game code."""
    if base.startswith("_"):  # _Module_, _PrivateImplementationDetails, __f__Anonymous...
        return True
    if "Anonymous" in base or "PrivateImplementationDetails" in base or "__c" in base:
        return True
    if base.endswith("_Arrays") or base.endswith("_RectangularArrays"):
        return True
    return base.split("_", 1)[0] in RUNTIME


def _module_of(base: str, modules: frozenset[str] | None) -> str:
    """The .c a local type belongs to: its outermost enclosing known module, else itself."""
    if modules:
        parts = base.split("_")
        for k in range(1, len(parts)):
            prefix = "_".join(parts[:k])
            if prefix in modules:
                return prefix
    return base


def route(
    name: str, *, nonempty: bool, modules: frozenset[str] | None = None
) -> tuple[str, str, str] | None:
    """Map a struct name to ``(file, kind, cleanname)``, or ``None`` if not emitted.

    ``_H_`` marks a shared header (``<hdr>.h``); anything else is module-local. ``kind`` is
    "struct", "extern", "static", or "define".
    """
    if name.endswith("_StaticFields"):
        if not nonempty:
            return None
        base = name[: -len("_StaticFields")]
        if "_H_" in base:
            hdr, clean = base.split("_H_", 1)
            hdr = f"{hdr}.h"
        else:
            if _is_junk(base):
                return None
            hdr, clean = f"{_module_of(base, modules)}.h", base
        if clean.split("_")[-1] == "Define":  # a group of C `#define` constants
            return (hdr, "define", clean)
        if "_H_" in base:  # a shared global declared in a header
            return (hdr, "extern", clean)
        return (f"{_module_of(base, modules)}.c", "static", base)  # module-local
    if name.endswith("_Fields"):
        if not nonempty:  # empty struct (e.g. a static-class holder): nothing to emit
            return None
        base = name[: -len("_Fields")]
        if "_H_" in base:
            file, clean = base.split("_H_", 1)
            if clean in MATH_PROVIDED:  # redundant wrapper of a common-provided math type
                return None
            return (f"{file}.h", "struct", clean)
        if _is_junk(base) or base in MATH_PROVIDED:
            return None
        return (f"{_module_of(base, modules)}.c", "struct", base)  # locally-defined struct
    return None


def _strip_wrapper(token: str) -> str:
    for suf in _WRAPPERS:
        if token.endswith(suf) and len(token) > len(suf):
            return token[: -len(suf)]
    return token


def resolve_base(token: str) -> Resolved:
    """Resolve a bare type token (no ``struct``/pointer/``_array``) to a clean C type.

    Enums and structs both come back with their name in ``ref``; the caller separates them
    by the known enum set.
    """
    token = _strip_wrapper(token)
    if _PRIMITIVE.match(token):
        return Resolved(_STDINT_TYPE_TO_DECOMP_TYPE.get(token, token), None)
    if "_H_" in token:  # imported game type
        clean = token.split("_H_", 1)[1]
        if clean in MATH_PROVIDED:  # provided by common, no forward decl
            return Resolved(clean, None)
        return Resolved(clean, clean)  # enum or struct; the caller classifies by `enums`
    if token in _IL2CPP_TYPE_TO_DECOMP_TYPE:
        return Resolved(_IL2CPP_TYPE_TO_DECOMP_TYPE[token], None)
    if token in _UNITY_TO_SDF_TYPE:
        return Resolved(_UNITY_TO_SDF_TYPE[token], None)  # defined in common, no forward decl
    if token.split("_", 1)[0] in RUNTIME:  # unresolved runtime type -> opaque pointer
        return Resolved("void", None)
    return Resolved(token, token)  # game external (or enum): keep the name


def rewrite_member(
    line: str, *, struct: str | None = None, sizes: ArraySizes | None = None
) -> tuple[str, set[str]]:
    """Rewrite one member/field line to clean C. Returns ``(line, referenced tags)``."""
    m = _MEMBER.match(line)
    if not m:
        return (line, set())
    type_tok, stars_raw, name = m.group(1), m.group(2), m.group(3)
    stars = stars_raw.count("*")

    depth = 0
    while type_tok.endswith("_array"):
        type_tok = type_tok[: -len("_array")]
        depth += 1

    resolved = resolve_base(type_tok)
    refs: set[str] = {resolved.ref} if resolved.ref else set()

    # Only the outer (allocated) dimension is known, so a jagged array materializes that and
    # keeps its inner levels as pointers.
    recovered = sizes.get((struct, name)) if sizes and struct else None
    if depth == 1 and recovered is not None:
        count, is_value = recovered
        ptr = " " if is_value else " *"
        return (f"{resolved.text}{ptr}{name}[{count}];", refs)
    if depth >= 2 and recovered is not None:
        count = recovered[0]
        inner = "*" * (depth - 1)
        return (f"{resolved.text} {inner}{name}[{count}];", refs)

    if depth:
        # No recoverable count: emit a pointer so the field stays one word wide and the
        # offsets after it hold.
        inner = "*" * (depth - 1)
        return (f"{resolved.text} {inner}*{name};", refs)
    ptr = " " + "*" * stars if stars else " "
    return (f"{resolved.text}{ptr}{name};", refs)


_Macro = tuple[str, "int | str | None"]  # (name, value)


@dataclass
class _FileModel:
    structs: list[tuple[str, list[str]]]  # (cleanname, rendered members)
    enums: list[tuple[str, list[tuple[str, int]]]]  # (name, [(member, value)])
    externs: list[tuple[str, list[str]]]  # (owner, rendered) shared globals in a header
    statics: list[tuple[str, list[str]]]  # (owner, rendered) module-local symbols in a .c
    defines: list[tuple[str, list[_Macro]]]  # (owner, macros) `#define` constant groups
    stubs: list[tuple[str, str]]  # (name, call-graph stub body)
    callees: set[str]  # display names called here, need a local prototype
    refs: set[str]  # struct types referenced, forward-declared
    enum_refs: set[str]  # enum types referenced, pulled in by #include
    defined: set[str]


def _blank_model() -> _FileModel:
    return _FileModel(
        structs=[], enums=[], externs=[], statics=[], defines=[], stubs=[], callees=set(),
        refs=set(), enum_refs=set(), defined=set(),
    )

def _module_bases(blocks: list[Block]) -> frozenset[str]:
    """Every non-`_H_` local class base (the set nested types fold their .c into)."""
    bases: set[str] = set()
    for b in blocks:
        for suf in ("_Fields", "_StaticFields"):
            if b.name.endswith(suf):
                base = b.name[: -len(suf)]
                if "_H_" not in base and not _is_junk(base):
                    bases.add(base)
    return frozenset(bases)

def _struct_base(name: str) -> str:
    """The size-map key for a block: its name minus the IL2CPP variant suffix."""
    for suf in ("_StaticFields", "_Fields"):
        if name.endswith(suf):
            return name[: -len(suf)]
    return name

def _header_of(file: str) -> str:
    """The header a declaration belongs in (a module's enums live in its .h, not its .c)."""
    return file.rsplit(".", 1)[0] + ".h"

# C#/IL2CPP-only methods with no place in a native-C game: constructors, property/event
# accessors, operators, Object/interface/iterator/delegate methods, and the array helpers.
_IL2CPP_METHOD = re.compile(
    r"___c?ctor"
    r"|__get_|__set_|__add_|__remove_|__op_|__System_"
    r"|_Arrays__|_RectangularArrays|InitializeWithDefaultInstances|DeleteArray"
    r"|__(?:Equals|GetHashCode|ToString|Finalize|Dispose|MemberwiseClone|GetType|Clone"
    r"|MoveNext|GetEnumerator|Reset|Invoke|BeginInvoke|EndInvoke|DynamicInvoke)(?![A-Za-z])"
)

def _route_function(name: str, modules: frozenset[str]) -> str | None:
    """The .c a function's stub belongs in, or None for runtime/compiler functions."""
    if name.startswith("sub_") or _is_junk(name) or _IL2CPP_METHOD.search(name):
        return None  # unnamed helper, compiler-gen type, or a C#-only class method
    if "_H_" in name:
        return name.split("_H_", 1)[0] + ".c"  # method of a header-declared type
    module = _module_of(name, modules)
    # Only real game modules (that also have struct/static declarations) get function stubs;
    # a name that resolves to no known module is a C# class, not code.
    return f"{module}.c" if module in modules else None

def display_map(protos: Iterable[str], modules: frozenset[str]) -> dict[str, str]:
    """Map each kept function's mangled name to its display name.

    The owning-class prefix is stripped, except where that would collide inside one file.
    """
    kept: list[tuple[str, str]] = []
    for n in protos:
        file = _route_function(n, modules)
        if file is not None:
            kept.append((file, n))
    by_file: dict[tuple[str, str], set[str]] = {}
    for file, n in kept:
        by_file.setdefault((file, proto_name(n)), set()).add(n)
    collided = {n for names in by_file.values() if len(names) > 1 for n in names}
    return {n: (n if n in collided else proto_name(n)) for _, n in kept}


def _sig_arity(sig: str) -> int:
    """Parameter count of a cleaned prototype signature (`void` -> 0)."""
    if sig.strip() in ("", "void"):
        return 0
    depth, commas = 0, 0
    for ch in sig:
        if ch in "([":
            depth += 1
        elif ch in ")]":
            depth -= 1
        elif ch == "," and depth == 0:
            commas += 1
    return commas + 1


def arity_map(
    protos: dict[str, tuple[str, str, set[str]]], display: dict[str, str]
) -> dict[str, int]:
    """Display name -> parameter count, dropping names that map to conflicting arities."""
    out: dict[str, int] = {}
    conflict: set[str] = set()
    for name, (_ret, sig, _refs) in protos.items():
        d = display.get(name, proto_name(name))
        n = _sig_arity(sig)
        if d in out and out[d] != n:
            conflict.add(d)
        out[d] = n
    for d in conflict:
        del out[d]
    return out


def symbol_map(
    protos: dict[str, tuple[str, str, set[str]]],
    addresses: dict[str, int],
    modules: frozenset[str],
    linker: dict[str, str] | None = None,
) -> str:
    """Every emitted function by binary address, as
    ``<address>  <symbol>  <source>  [<linker symbol>]``.
    """
    display = display_map(protos, modules)
    linker = linker or {}
    rows: list[tuple[int, str, str, str]] = []
    for name in protos:
        file = _route_function(name, modules)
        addr = addresses.get(name)
        if file is not None and addr is not None:
            rows.append((addr, display.get(name, proto_name(name)), file, linker.get(name, "")))
    rows.sort()
    out = [
        "# SMT3 reconstructed sources: function address map",
        f"# {len(rows)} functions, ordered by binary address",
        "# address     symbol  source  linker-name",
    ]
    out += [f"{addr:#010x}  {name}  {file}  {ln}".rstrip() for addr, name, file, ln in rows]
    return "\n".join(out) + "\n"


_SCALAR_RET = frozenset(
    {
        "void", "bool", "char", "s8", "u8", "s16", "u16", "s32", "u32",
        "s64", "u64", "f32", "f64", "intptr_t", "uintptr_t", "size_t",
    }
)

def _fake_value(t: str, enums: frozenset[str]) -> str:
    """A zero value of type ``t``: 0 for scalars/pointers/enums, else a compound literal."""
    t = t.strip()
    if t.endswith("*") or t in _SCALAR_RET or _PRIMITIVE.match(t) or t in enums:
        return "0"
    return f"({t}){{0}}"  # struct by value

def _fake_args(sig: str, enums: frozenset[str]) -> str:
    if sig == "void":
        return ""
    args: list[str] = []
    for p in sig.split(","):
        m = _PARAM_NAME.match(p.strip())
        args.append(_fake_value(m.group(1) if m else p, enums))
    return ", ".join(args)

def _assemble_stub(
    ret: str, name: str, sig: str, callees: list[tuple[str, str]], enums: frozenset[str]
) -> str:
    """A stub whose body is the call graph: one ``callee(fakes);`` per edge, then a return."""
    sep = "" if ret.endswith("*") else " "
    body = "".join(f"    {c}({_fake_args(csig, enums)});\n" for c, csig in callees)
    tail = "" if ret == "void" else f"    return {_fake_value(ret, enums)};\n"
    return f"{ret}{sep}{name}({sig}) {{\n{body}{tail}}}"

def build(
    text: str,
    sizes: ArraySizes | None = None,
    meta: Metadata | None = None,
    protos: dict[str, tuple[str, str, set[str]]] | None = None,
    graph: dict[str, list[str]] | None = None,
    bodies: dict[str, str] | None = None,
    addresses: dict[str, int] | None = None,
) -> tuple[
    dict[str, _FileModel], Counter[str], dict[str, str],
    dict[str, tuple[str, str, set[str]]], dict[str, str],
]:
    """Group parsed blocks and functions into per-file models.

    Returns ``(files, drops, enum->header, display->(return,params,refs), foo_t->foo_s)``.
    """
    files: dict[str, _FileModel] = {}
    dropped: Counter[str] = Counter()
    enum_header: dict[str, str] = {}
    enums: frozenset[str] = frozenset(meta.enums) if meta else frozenset()
    consts = meta.constants if meta else {}
    blocks = list(parse_blocks(text))
    modules = _module_bases(blocks)
    for block in blocks:
        routed = route(block.name, nonempty=bool(block.members), modules=modules)
        if routed is None:
            dropped[_drop_reason(block.name)] += 1
            continue
        file, kind, clean = routed
        if kind == "struct" and clean in enums:  # emit as a C enum in this type's header
            header = _header_of(file)
            files.setdefault(header, _blank_model()).enums.append((clean, meta.enums[clean]))  # type: ignore[union-attr]
            enum_header[clean] = header
            continue
        model = files.setdefault(file, _blank_model())
        if kind == "define":
            # Metadata is authoritative for a constant group (the dump only lists the runtime
            # statics it happened to see); fall back to dump names.
            macros: list[_Macro] = list(consts.get(clean, []))
            if not macros:
                macros = [
                    (m.group(3), None) for mem in block.members if (m := _MEMBER.match(mem))
                ]
            model.defines.append((clean, macros))
            continue
        base = _struct_base(block.name)
        rendered: list[str] = []
        for member in block.members:
            line, refs = rewrite_member(member, struct=base, sizes=sizes)
            rendered.append(line)
            model.enum_refs |= refs & enums
            model.refs |= refs - enums
        if kind == "struct":
            model.structs.append((clean, rendered))
            model.defined.add(clean)
        elif kind == "extern":
            model.externs.append((clean, rendered))
        else:
            model.statics.append((clean, rendered))
    dmap = display_map(protos or {}, modules)
    kept_names = list(dmap)

    def disp(fname: str) -> str:
        return dmap.get(fname, proto_name(fname))

    func_sig: dict[str, tuple[str, str, set[str]]] = {}
    for fname in kept_names:
        ret, sig, refs = protos[fname]  # type: ignore[index]
        func_sig[disp(fname)] = (ret, sig, refs)
    for fname, (ret, sig, prefs) in (protos or {}).items():
        pfile = _route_function(fname, modules)
        if pfile is None:
            continue
        model = files.setdefault(pfile, _blank_model())
        display = disp(fname)
        callees: list[tuple[str, str]] = []
        for c in (graph or {}).get(fname, []):
            cd = disp(c)
            _cret, csig, crefs = func_sig.get(cd, ("", "void", set[str]()))
            callees.append((cd, csig))
            model.callees.add(cd)
            model.enum_refs |= crefs & enums  # forward-decl the callee's param/return types
            model.refs |= crefs - enums
        banner = f"// {addr:#x}\n" if (addr := (addresses or {}).get(fname)) else ""
        if bodies and fname in bodies:  # cleaned real body
            sep = "" if ret.endswith("*") else " "
            model.stubs.append(
                (display, f"{banner}{ret}{sep}{display}({sig}) {{\n{bodies[fname]}\n}}")
            )
        else:  # no body in the .c at all -> call-graph stub
            model.stubs.append(
                (display, banner + _assemble_stub(ret, display, sig, callees, enums))
            )
        model.enum_refs |= prefs & enums
        model.refs |= prefs - enums
    alias = _struct_aliases(files)
    files = _promote_struct_headers(files)
    return files, dropped, enum_header, func_sig, alias


def _promote_struct_headers(files: dict[str, _FileModel]) -> dict[str, _FileModel]:
    """Route a .c that only declares struct layouts to ``<base>.h``.

    IL2CPP keeps the struct tag without the ``_H_`` marker, so a pure type-definition base
    would otherwise land as a ``.c`` no other module can include.
    """
    promoted: dict[str, _FileModel] = {}
    for file, model in files.items():
        if file.endswith(".c") and model.structs and not (
            model.enums or model.externs or model.statics
            or model.defines or model.stubs or model.callees
        ):
            file = file[: -len(".c")] + ".h"
        existing = promoted.get(file)
        if existing is None:
            promoted[file] = model
        else:  # a header of this base already exists (e.g. an enum-only .h): fold in
            existing.structs += model.structs
            existing.enums += model.enums
            existing.refs |= model.refs
            existing.enum_refs |= model.enum_refs
            existing.defined |= model.defined
    return promoted


def _struct_aliases(files: dict[str, _FileModel]) -> dict[str, str]:
    """Map a referenced-but-undefined ``X_t`` to the struct tag it typedefs (``X_s``).

    IL2CPP keeps only the tag as a real struct while code uses the typedef name, so pairing
    them is what makes the typedef resolve to a complete type.
    """
    defined: set[str] = set[str]().union(*(m.defined for m in files.values())) if files else set()
    base_of = re.compile(r"_(?:s|t|tag)$")
    canonical: dict[str, str] = {}
    for d in sorted(defined):
        canonical.setdefault(base_of.sub("", d), d)
    refs: set[str] = set[str]().union(*(m.refs for m in files.values())) if files else set()
    alias: dict[str, str] = {}
    for r in refs - defined:
        target = canonical.get(base_of.sub("", r))
        if target and target != r:
            alias[r] = target
    return alias


def _drop_reason(name: str) -> str:
    if name.endswith("_StaticFields"):
        return "runtime/empty statics"
    if name.endswith("_Fields"):
        return "runtime/compiler-gen types"
    return "other"


def _macro_line(name: str, value: int | str | None) -> str:
    if value is None:
        return f"#define {name} UNKNOWN_DEFINE_VALUE"
    if isinstance(value, str):
        return f'#define {name} "{value}"'
    return f"#define {name} {value}"


def _render_file(
    file: str,
    model: _FileModel,
    enum_header: dict[str, str],
    func_sig: dict[str, tuple[str, str, set[str]]],
    alias: dict[str, str],
) -> str:
    is_header = file.endswith(".h")
    # A `foo_t` that typedefs a struct we define here (`foo_s`) is emitted after the struct so
    # it resolves to a complete type; the rest are forward-declared (aliased ones through
    # their real tag, so `foo_t` is the same type everywhere).
    local_alias = sorted(a for a, tgt in alias.items() if tgt in model.defined)
    tags = sorted((model.refs | model.defined) - set(local_alias))
    # Enums are real types (not forward-declarable), so pull in the header defining each
    # referenced enum we don't define ourselves. Structs stay forward-declared: including
    # their headers cascades enum-collision/incomplete-array errors, and the datUnitWork_s/_t
    # alias split leaves the type incomplete anyway.
    includes = sorted(
        {enum_header[e] for e in model.enum_refs if enum_header.get(e, file) != file}
    )
    out: list[str] = []
    if is_header:
        out.append("#pragma once")
    out += [f'#include "{COMMON_HEADER}"']
    out += [f'#include "{inc}"' for inc in includes]
    out.append("")
    for _owner, macros in model.defines:
        out += [_macro_line(n, v) for n, v in macros]
        out.append("")
    for enum_name, members in model.enums:
        out.append("typedef enum {")
        out += [f"    {member} = {value}," for member, value in members]
        out += [f"}} {enum_name};", ""]
    if tags:
        out += [f"typedef struct {alias.get(t, t)} {t};" for t in tags]
        out.append("")
    for clean, members in model.structs:
        out.append(f"struct {clean} {{")
        out += [f"    {m}" for m in members]
        out += ["};", ""]
    for a in local_alias:  # typedef of a struct defined just above -> a complete type
        out.append(f"typedef struct {alias[a]} {a};")
    if local_alias:
        out.append("")
    for _owner, members in model.externs:
        out += [f"extern {m}" for m in members]
        out.append("")
    for _owner, members in model.statics:
        out += [f"static {m}" for m in members]
        out.append("")
    if model.callees:
        for c in sorted(model.callees):
            ret, sig, _ = func_sig.get(c, ("int", "void", set()))
            out.append(f"{ret}{'' if ret.endswith('*') else ' '}{c}({sig});")
        out.append("")
    if model.stubs:
        for _, stub in sorted(model.stubs):
            out += [stub, ""]
    return "\n".join(out).rstrip() + "\n"


def generate(
    text: str,
    sizes: ArraySizes | None = None,
    meta: Metadata | None = None,
    protos: dict[str, tuple[str, str, set[str]]] | None = None,
    graph: dict[str, list[str]] | None = None,
    bodies: dict[str, str] | None = None,
    addresses: dict[str, int] | None = None,
) -> dict[str, str]:
    """Full transformation: dump text -> ``{filename: contents}`` (incl. common header)."""
    files, _, enum_header, func_sig, alias = build(
        text, sizes, meta, protos, graph, bodies, addresses
    )
    out: dict[str, str] = {COMMON_HEADER: _COMMON_BODY}
    for file, model in files.items():
        out[file] = _render_file(file, model, enum_header, func_sig, alias)
    return out

def _load_array_lengths(input_path: Path) -> ArraySizes:
    """Array counts observed at runtime, for fields whose allocation had no constant count."""
    p = input_path.parent / "array_lengths.json"
    if not p.is_file():
        return {}
    raw = json.loads(p.read_text(encoding="utf-8"))
    return {
        (struct, member): (count, is_value)
        for struct, members in raw.items()
        for member, (count, is_value) in members.items()
    }


def _load_literal_map(input_path: Path) -> dict[int, str] | None:
    """The recovered `StringLiteral_<n>` -> text map, if it sits beside the dump."""
    p = input_path.parent / "stringliteral_map.json"
    if not p.is_file():
        return None
    return {int(k): v for k, v in json.loads(p.read_text(encoding="utf-8")).items()}


def run(
    input_path: Path,
    outdir: Path,
    only: set[str] | None = None,
    source_c: Path | None = None,
    metadata: Path | None = None,
    clean_body: bool = False,
    symbol_map_path: Path | None = None,
) -> Counter[str]:
    """Generate files into ``outdir`` (.h in include/, .c at top). Returns drop counts.

    ``source_c`` is the transpiled .c (recovers array dimensions, prototypes, bodies);
    ``metadata`` is global-metadata.dat (recovers enum and ``#define`` values);
    ``symbol_map_path`` is an IDA ``.map`` (authoritative function addresses).
    """
    text = input_path.read_text(encoding="utf-8", errors="replace")
    meta = Metadata.from_file(metadata) if metadata is not None else None
    literals = _load_literal_map(input_path)
    sizes: ArraySizes | None = None
    protos: dict[str, tuple[str, str, set[str]]] | None = None
    graph: dict[str, list[str]] | None = None
    bodies: dict[str, str] | None = None

    addresses: dict[str, int] = {}
    linker: dict[str, str] = {}
    modules = _module_bases(list(parse_blocks(text)))
    if symbol_map_path is not None:
        with symbol_map_path.open("r", encoding="utf-8", errors="replace") as fh:
            syms = map_symbols(fh)
        addresses = {n: a for n, (a, _) in syms.items()}
        linker = {n: ln for n, (_, ln) in syms.items()}
    if source_c is not None:
        with source_c.open("r", encoding="utf-8", errors="replace") as fh:
            sizes = array_sizes(fh)
        # Constructor counts win; runtime observations only fill in what they did not resolve.
        sizes = _load_array_lengths(input_path) | sizes
        with source_c.open("r", encoding="utf-8", errors="replace") as fh:
            protos = function_prototypes(fh)
        if not addresses:  # fall back to the Hex-Rays separators when no .map is given
            with source_c.open("r", encoding="utf-8", errors="replace") as fh:
                addresses = function_addresses(fh)
        kept = frozenset(n for n in protos if _route_function(n, modules) is not None)
        with source_c.open("r", encoding="utf-8", errors="replace") as fh:
            graph = call_graph(fh, kept)
        if clean_body:
            dmap = display_map(protos, modules)
            aritymap = arity_map(protos, dmap)
            with source_c.open("r", encoding="utf-8", errors="replace") as fh:
                bodies, reasons = clean_bodies(fh, dmap, aritymap, literals)

    files, dropped, enum_header, func_sig, alias = build(
        text, sizes, meta, protos, graph, bodies, addresses
    )
    include_dir = outdir / "include"
    include_dir.mkdir(parents=True, exist_ok=True)

    def dest(name: str) -> Path:
        return (include_dir if name.endswith(".h") else outdir) / name

    dest(COMMON_HEADER).write_text(_COMMON_BODY, encoding="utf-8")
    for file, model in files.items():
        if only is not None and file.rsplit(".", 1)[0] not in only:
            continue
        content = _render_file(file, model, enum_header, func_sig, alias)
        dest(file).write_text(content, encoding="utf-8")
    if addresses and only is None:
        (outdir / "symbols.txt").write_text(
            symbol_map(protos or {}, addresses, modules, linker), encoding="utf-8"
        )
    return dropped

def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter
    )
    ap.add_argument("input", type=Path, help="IDA IL2CPP local-types dump (.h)")
    ap.add_argument("-o", "--outdir", type=Path, required=True, help="output directory")
    ap.add_argument("--only", help="comma-separated header basenames to emit (e.g. libsdf,model)")
    ap.add_argument("--stats", action="store_true", help="print dropped-declaration counts")
    ap.add_argument(
        "--source", type=Path, help="transpiled IL2CPP .c to recover fixed-array sizes from"
    )
    ap.add_argument(
        "--metadata", type=Path, help="global-metadata.dat to recover enum/#define values from"
    )
    ap.add_argument(
        "--bodies", action="store_true",
        help="emit cleaned real bodies for simple functions (else call-graph stubs)",
    )
    ap.add_argument(
        "--map", type=Path, help="IDA .map for authoritative function addresses"
    )
    args = ap.parse_args(argv)
    only = set(args.only.split(",")) if args.only else None
    dropped = run(
        args.input, args.outdir, only=only, source_c=args.source, metadata=args.metadata,
        clean_body=args.bodies, symbol_map_path=args.map,
    )
    if args.stats:
        for reason, count in dropped.most_common():
            print(f"  dropped {count:6} : {reason}")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
