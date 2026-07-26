# SMT3 IL2CPP Dump -> Clean C Headers

`smt3dump` turns an IDA "local types" dump of the SMT3 HD IL2CPP (C# -> C++) build into
readable C headers and module sources.

## Motivation

The input (`smt3hd_main.elf.h`) is a 627k-line IDA local-types listing of **SMT3 HD**, an
IL2CPP build carrying the original engine and library modules (`libsdf`, `model`, `basic`,
`bilManager`, `field`, ...). The dump encodes the native C structures, buried under IL2CPP
mangling and runtime metadata. Recovering clean C declarations gives a **reference layout**
of those modules.

We reverse the mangling for the game declarations and drop the .NET/Unity runtime noise.
The recovered layout is the Unity-flavored one the port produced, not the PS2 original (the
remaster replaced the game's own types, e.g. its math types, with UnityEngine equivalents).

## Headers vs modules

`_H_` (underscore-H-underscore) marks a type **declared in a shared native header** (`.h`).
Everything else is defined **locally in a module** (`.c`). So shared type layouts and
declarations route to `<header>.h`; module-local structs and data route to `<module>.c`.

`<file>_H_<Type>` splits on the **first** `_H_`: source header `<file>.h`, clean type
`<Type>`. Module globals (`fldGlobal`, `fldMain`, ...) are compilation-unit statics and
carry no `_H_`, so `_H_` alone cannot be the game/runtime filter; a runtime blocklist does
that instead (below).

## What is emitted

The IL2CPP variants of a type (`_o`, `_c`, `_StaticFields`, `_VTable`, `_RGCTXs`, and the
`_array` forward-decls) are not emitted as types; they only inform member resolution.

| Declaration | Kept when | Routed to | Emitted as |
|---|---|---|---|
| `A_H_B_Fields` | has a body | `A.h` | `struct B { ... };` (shared type layout) |
| `M_Fields` (no `_H_`) | has a body, not junk | `<module>.c` | `struct M { ... };` (module-local struct) |
| `M_Fields` where `M` has no functions or data | has a body, not junk | `<M>.h` | `struct M { ... };` (struct-only base, promoted to a header) |
| `A_H_B_StaticFields` | non-empty | `A.h` | `extern` globals (shared, declared in a header) |
| `M_StaticFields` (no `_H_`) | non-empty, not junk | `<module>.c` | `static` symbols (module-local data) |
| `X_Define` holder | always | `<header>.h` | a `#define` macro group |
| enum type | in metadata | its type's `.h` | a C `enum` |
| everything else | | dropped | |

A nested local type folds into its outermost enclosing module's `.c` (`billManager_hG_t`
-> `billManager.c`).

IL2CPP keeps the original C struct tag (`foo_tag`/`foo_t`/`foo_s`) but drops the `_H_`
shared-header marker, so a base that is only a type layout (no functions or data) would
land as a `.c` no other module can include. Such a struct-only base is promoted to its own
`<base>.h` (`effPCPFlashPolyCircle_tag` -> `effPCPFlashPolyCircle_tag.h`). Cross-module
references still forward-declare the tag, as with any other type.

`#define` holders (`pb_H_pb_Define`) carry only their names in the dump; values live in the
static constructor, recovered from `global-metadata.dat` when available, else emitted as the
`UNKNOWN_DEFINE_VALUE` sentinel.

Empty structs (static-class holders like `bilManager_Fields {}`) are dropped.
Compiler/runtime junk is filtered: `_PrivateImplementationDetails`, `*Anonymous*`,
`*_Arrays`, `*_RectangularArrays`, `UnityEngineInternal`, names starting with `_`, and the
runtime namespaces below.

**Runtime blocklist** (top-level namespace tokens treated as .NET/Unity/IL2CPP runtime, not
game code): `System`, `Mono`, `Microsoft`, `UnityEngine`, `UnityEngineInternal`, `Unity`,
`TMPro`, `Il2Cpp`, `I18N`, `Locale`, `SR`, `Newtonsoft`, `nn` (Switch OS SDK).

## Member type-resolution

Each member/field line is `[struct ]<type-tokens> [*...] <name>[...] ;`. Only the type is
rewritten; pointers, the member name, and trailing tokens are preserved verbatim.

| Dump type form | Clean output |
|---|---|
| `A_H_B_o *` / `A_H_B_Fields` | `B *` (reference to the clean imported type) |
| `<X>_array *` (any namespace) | `<elem> *`; `_array_array` -> `**`; element resolved recursively |
| `System_SByte` / `System_Byte` | `s8` / `u8` |
| `System_Int16` / `System_UInt16` | `s16` / `u16` |
| `System_Int32` / `System_UInt32` | `s32` / `u32` |
| `System_Int64` / `System_UInt64` | `s64` / `u64` |
| `System_Single` / `System_Double` | `f32` / `f64` |
| `System_Boolean` | `bool` |
| `System_Char` | `u16` (UTF-16) |
| `System_IntPtr` / `System_UIntPtr` | `intptr_t` / `uintptr_t` |
| `System_String_o` | `char *` |
| `System_Object_o` / `Il2CppObject` | `void *` |
| `UnityEngine_Vector2/3/4_o`, `Matrix4x4_o`, `Quaternion_o`, `Color_o`, `Color32_o` | inferred `sdf*_t` typedef from `il2cpp_common.h` |
| any other unresolved runtime type | `void *` |
| any other unresolved game type | opaque forward-decl, cleaned name kept |

Types are emitted in the as (`s8`/`u8`/.../`s64`/`u64`, `f32`/`f64`),
aliased in `il2cpp_common.h`.

The port replaced the game's math types with UnityEngine ones; they map back to inferred
original `sdf*` names (`UnityEngine_Vector4` -> `sdfVector4_t`, `Matrix4x4` -> `sdfMatrix4_t`,
...), defined as concrete typedefs in `il2cpp_common.h`.

## Recovery from the transpiled `.c`

The optional Hex-Rays `.c` export (`--source`) recovers what the type layout erased:

- **Fixed-array dimensions.** IL2CPP arrays are dimensionless in the type; constructor
  bodies allocate them (`il2cpp::NewSpecific(elem___TypeInfo, N)`, directly or through a
  local variable. For a jagged array only the outer (allocated) dimension is known, so it becomes `elem *name[N]` with
  the inner levels left as pointers. If the size cannot be determined by the script, `UNKNOWN_ARRAY_SIZE` is used.
- **Function prototypes**, cleaned to native C signatures (the IL2CPP `MethodInfo` context
  parameter is dropped, and the owning-class prefix is stripped:
  `dds3KernelCore__dds3StartProcess` -> `dds3StartProcess`).
- **Function bodies** (`--bodies`). A deterministic strip turns a Hex-Rays body into
  readable pseudo-C: IL2CPP generated junk is removed, `->fields.` and `x->static_fields->G`
  collapse to the field / global; Hex-Rays pseudo-types become standard C. A body too
  tangled to strip cleanly (inlined `sub_` helpers, irreducible `goto`/`LABEL_` control
  flow, or metadata woven into real branches) is kept as a stub with a list of callers/callee's.
  Two further passes clean the reconstructed body: never-referenced local declarations (the
  Hex-Rays receiver/temp spills) are dropped, and each call sheds the trailing `MethodInfo`
  context arg the prototype already dropped (a `Method_*` literal, or a `0` when the call is
  one arg past the callee's known arity).
- **Function addresses.** An IDA `.map` (`--map`) is the authoritative source: its `.text`
  "Publics by Value" give each function's address, with the linker `Class$$method` name
  transformed to the Hex-Rays spelling to match. Without a `.map`, the `//----- (address) ----`
  separators in the `.c` are used as a fallback (they cover fewer functions). The address is
  emitted as a `// 0x<addr>` comment above the reconstructed function, and the full set is
  written to `symbols.txt` (every emitted function, ordered by binary address, with its
  source file and linker name) as a linkage reference. Data-symbol addresses are not
  recovered: the game globals live inside IL2CPP `_StaticFields`, not as addressed data
  symbols in either the dump or the `.map`.

## Testing

- Fixtures are small real snippets carved from the dump (`sdfModelNode_t`, `bilInstance_s`,
  `sdfMatrix4_t`, `fldGlobal`, ...), not synthetic.
- Unit tests per pure function: routing, the full type-mapping table, `_array` depth,
  self-reference and cycles, empty-`_StaticFields` skip, array-size recovery, enum emission,
  `#define` values, prototype cleaning, body stripping and stub fallback.
- `ruff` and `pyright` (strict) clean.
