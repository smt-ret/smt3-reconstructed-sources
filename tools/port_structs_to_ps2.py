#!/usr/bin/env python3
"""Emit PS2 C declarations for the HD structs of a subsystem, for import into the PS2 IDB."""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

_START = re.compile(r"^struct (?:__cppobj )?([A-Za-z_]\w*)(?:\s*:\s*([A-Za-z_]\w*))?$")
_MEMBER = re.compile(r"^(?:const |struct |volatile )*([A-Za-z_]\w*)\s*((?:\*\s*)*)"
                     r"([A-Za-z_]\w*)\s*(\[(\d+)\])?;$")

PRIMITIVES = {
    "uint8_t": "u8", "uint16_t": "u16", "uint32_t": "u32", "uint64_t": "u64",
    "int8_t": "s8", "int16_t": "s16", "int32_t": "s32", "int64_t": "s64",
    "float": "f32", "double": "f64", "bool": "bool", "char": "char",
    "Il2CppObject": "void", "System_Object": "void", "System_String": "char",
    "System_IntPtr": "void", "System_UIntPtr": "void",
}
ARRAY_ELEMENTS = {
    "System_Byte_array": "u8", "System_SByte_array": "s8",
    "System_UInt16_array": "u16", "System_Int16_array": "s16",
    "System_UInt32_array": "u32", "System_Int32_array": "s32",
    "System_UInt64_array": "u64", "System_Int64_array": "s64",
    "System_Single_array": "f32", "System_Double_array": "f64",
    "System_Object_array": "void", "System_String_array": "char",
    "System_Boolean_array": "bool",
}
# The remaster swapped the game's own math types for UnityEngine ones.
UNITY_TYPES = {
    "UnityEngine_Vector2": "sdfVector2_t", "UnityEngine_Vector3": "sdfVector3_t",
    "UnityEngine_Vector4": "sdfVector4_t", "UnityEngine_Quaternion": "sdfQuaternion_t",
    "UnityEngine_Matrix4x4": "sdfMatrix4_t", "UnityEngine_Color": "sdfColor_t",
    "UnityEngine_Color32": "sdfColor32_t",
}


def parse_header(path: Path) -> dict[str, dict]:
    raw: dict[str, dict] = {}
    lines = path.read_text(encoding="utf-8", errors="replace").split("\n")
    i, n = 0, len(lines)
    while i < n:
        m = _START.match(lines[i])
        if m and i + 1 < n and lines[i + 1].strip() == "{":
            members = []
            j = i + 2
            while j < n and not lines[j].startswith("};"):
                mm = _MEMBER.match(lines[j].strip())
                if mm:
                    members.append((mm.group(1), mm.group(2).count("*"), mm.group(3),
                                    int(mm.group(5)) if mm.group(5) else 1))
                j += 1
            raw[m.group(1)] = {"base": m.group(2), "members": members}
            i = j
        i += 1
    return raw


def flatten(raw: dict[str, dict], name: str, seen: set[str] | None = None) -> list[tuple]:
    seen = seen if seen is not None else set()
    if name in seen or name not in raw:
        return []
    seen.add(name)
    out = list(flatten(raw, raw[name]["base"], seen)) if raw[name]["base"] else []
    return out + raw[name]["members"]


def instance_fields(raw: dict[str, dict]) -> dict[str, list[tuple]]:
    return {n[: -len("_Fields")]: flatten(raw, n) for n in raw if n.endswith("_Fields")}


def short(name: str) -> str:
    return name.split("_H_", 1)[1] if "_H_" in name else name


# Names the C# compiler generates: lambda closures and iterator state machines.
_COMPILER_GENERATED = re.compile(r"_c__DisplayClass|_d__\d|<.*>")


def classify(name: str, members: list[tuple]) -> str:
    names = {m[2] for m in members}
    if not members:
        return "empty"
    if "invoke_impl" in names or "m_target" in names:
        return "delegate"
    if len(members) == 1 and members[0][2] == "value__":
        return "enum"
    if _COMPILER_GENERATED.search(name):
        return "compiler"
    if "m_CachedPtr" in names:
        return "unity"  # UnityEngine.Object's native handle: no PS2 counterpart
    if "UnityEx" in name or name.endswith(("Attribute", "Job", "DrawJob")):
        return "unity"  # remaster-only: post-processing, C# attributes, Unity job structs
    return "struct"


class TypeMapper:
    def __init__(self, delegates: set[str]) -> None:
        self._delegates = delegates

    def native(self, token: str, pointers: int) -> tuple[str, int]:
        if token in PRIMITIVES:
            return PRIMITIVES[token], pointers
        base = short(token)
        if base in ARRAY_ELEMENTS:
            return ARRAY_ELEMENTS[base], max(pointers, 1)
        if base.endswith("_array"):
            inner = short(base[: -len("_array")].removesuffix("_o"))
            if inner.endswith("_array") or inner.startswith(("System_", "Mono_")):
                return "void", max(pointers, 1)  # jagged: no single PS2 element type
            if inner.startswith("UnityEngine_") and inner not in UNITY_TYPES:
                return "void", max(pointers, 1)
            return UNITY_TYPES.get(inner, ARRAY_ELEMENTS.get(inner, inner)), max(pointers, 1)
        base = base.removesuffix("_o")
        if base in UNITY_TYPES:
            return UNITY_TYPES[base], pointers
        if base in PRIMITIVES:
            return PRIMITIVES[base], pointers
        if base in self._delegates or base.startswith("UnityEngine_"):
            return "void", max(pointers, 1)  # a callback is a plain function pointer here
        if base.endswith("_array") or base.startswith(("System_", "Mono_", "Il2Cpp")):
            # a jagged array or a framework generic: one pointer wide, with no PS2 shape
            return "void", max(pointers, 1)
        return base, pointers


def declaration(name: str, members: list[tuple], mapper: TypeMapper) -> str:
    present = {m[2] for m in members}
    lines = [f"struct {name} {{"]
    for token, pointers, member, count in members:
        # `<field>_p` beside a `<field>` array is the transpiler's index, not a member.
        if member.endswith("_p") and member[:-2] in present:
            continue
        kind, stars = mapper.native(token, pointers)
        spacing = " " + "*" * stars if stars else " "
        lines.append(f"    {kind}{spacing}{member}{f'[{count}]' if count > 1 else ''};")
    lines.append("};")
    return "\n".join(lines)


def main() -> None:
    here = Path(__file__).parent
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("prefix", help="struct-name prefix, e.g. dds3")
    parser.add_argument("--header", type=Path, default=here / "inputs/smt3hd_main.elf.h")
    parser.add_argument("-o", "--output", type=Path, required=True)
    args = parser.parse_args()

    raw = parse_header(args.header)
    fields = instance_fields(raw)
    delegates = {short(n) for n, m in fields.items() if classify(n, m) == "delegate"}
    mapper = TypeMapper(delegates)

    counts: dict[str, int] = {}
    decls = []
    for name, members in sorted(fields.items()):
        if not short(name).lower().startswith(args.prefix.lower()):
            continue
        kind = classify(name, members)
        counts[kind] = counts.get(kind, 0) + 1
        if kind == "struct":
            decls.append(declaration(short(name), members, mapper))

    args.output.write_text("\n\n".join(decls) + "\n", encoding="utf-8")
    for kind in sorted(counts):
        print(f"  {kind:<10} {counts[kind]}")
    print(f"wrote {len(decls)} declarations to {args.output}")


if __name__ == "__main__":
    main()
