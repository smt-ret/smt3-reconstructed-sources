#!/usr/bin/env python3
"""Compute the byte offset of every member in the transpiled IL2CPP struct definitions."""

from __future__ import annotations

import re
from dataclasses import dataclass, field
from pathlib import Path

_START = re.compile(r"^struct (?:__cppobj )?(?:__declspec\([^)]*\) )?([A-Za-z_]\w*)"
                    r"(?:\s*:\s*([A-Za-z_]\w*))?$")
_MEMBER = re.compile(r"^(?:const |struct |volatile )*([A-Za-z_]\w*)\s*((?:\*\s*)*)"
                     r"([A-Za-z_]\w*)\s*(\[(\d+)\])?;$")

PRIMITIVES = {
    "bool": 1, "char": 1, "int8_t": 1, "uint8_t": 1, "__int8": 1,
    "int16_t": 2, "uint16_t": 2, "__int16": 2, "wchar_t": 2, "char16_t": 2,
    "int32_t": 4, "uint32_t": 4, "__int32": 4, "int": 4, "float": 4,
    "int64_t": 8, "uint64_t": 8, "__int64": 8, "double": 8,
    "il2cpp_array_size_t": 8, "intptr_t": 8, "uintptr_t": 8, "size_t": 8,
    "Il2CppMethodPointer": 8, "VirtualInvokeData": 16,
}
POINTER_SIZE = 8


@dataclass
class Struct:
    name: str
    base: str | None
    members: list[tuple[str, str, int]] = field(default_factory=list)  # (type, name, array count)


def parse(text: str) -> dict[str, Struct]:
    lines = text.split("\n")
    structs: dict[str, Struct] = {}
    i, n = 0, len(lines)
    while i < n:
        m = _START.match(lines[i])
        if m and i + 1 < n and lines[i + 1].strip() == "{":
            s = Struct(m.group(1), m.group(2))
            j = i + 2
            while j < n and not lines[j].startswith("};"):
                line = lines[j].strip()
                if (mm := _MEMBER.match(line)) is not None:
                    count = int(mm.group(5)) if mm.group(5) else 1
                    kind = "*" if mm.group(2).strip() else mm.group(1)
                    s.members.append((kind, mm.group(3), count))
                j += 1
            structs[s.name] = s
            i = j
        i += 1
    return structs


class Layout:
    """Member offsets, resolving base classes and nested structs on demand."""

    def __init__(self, structs: dict[str, Struct]) -> None:
        self._structs = structs
        self._sizes: dict[str, tuple[int, int]] = {}  # name -> (size, alignment)
        self._resolving: set[str] = set()

    def size_align(self, type_name: str) -> tuple[int, int]:
        if type_name == "*":
            return (POINTER_SIZE, POINTER_SIZE)
        if (prim := PRIMITIVES.get(type_name)) is not None:
            return (prim, min(prim, 8))
        if type_name in self._sizes:
            return self._sizes[type_name]
        s = self._structs.get(type_name)
        if s is None or type_name in self._resolving:
            # An opaque or self-referencing type only ever appears behind a pointer.
            return (POINTER_SIZE, POINTER_SIZE)
        self._resolving.add(type_name)
        offsets, size, align = self._walk(s)
        self._resolving.discard(type_name)
        self._sizes[type_name] = (size, align)
        return (size, align)

    def offsets(self, name: str) -> dict[str, int]:
        return {m: off for m, (off, _) in self.members(name).items()}

    def members(self, name: str) -> dict[str, tuple[int, str]]:
        """member -> (offset, declaring struct), which may be a base class."""
        s = self._structs.get(name)
        if s is None:
            return {}
        return self._walk(s)[0]

    def _walk(self, s: Struct) -> tuple[dict[str, tuple[int, str]], int, int]:
        offsets: dict[str, tuple[int, str]] = {}
        pos = 0
        align = 1
        if s.base and s.base in self._structs:
            offsets, pos, align = self._walk(self._structs[s.base])
        for type_name, member, count in s.members:
            size, member_align = self.size_align(type_name)
            pos = (pos + member_align - 1) // member_align * member_align
            offsets[member] = (pos, s.name)
            # A sub-struct puts its members at this offset, but they belong to it, not here.
            nested = self._structs.get(type_name)
            if nested is not None and type_name not in self._resolving:
                self._resolving.add(type_name)
                inner, _, _ = self._walk(nested)
                self._resolving.discard(type_name)
                for inner_member, (inner_off, declaring) in inner.items():
                    offsets.setdefault(f"{member}.{inner_member}", (pos + inner_off, declaring))
            pos += size * count
            align = max(align, member_align)
        return (offsets, (pos + align - 1) // align * align, align)


def load(header: Path) -> Layout:
    return Layout(parse(header.read_text(encoding="utf-8", errors="replace")))


if __name__ == "__main__":
    import sys

    layout = load(Path(sys.argv[1] if len(sys.argv) > 1
                       else Path(__file__).parent / "inputs/smt3hd_main.elf.h"))
    target = sys.argv[2] if len(sys.argv) > 2 else "newdata_H_datEncount_s_Fields"
    for member, (off, owner) in layout.members(target).items():
        print(f"  +{off:<5} {member:<24} declared by {owner}")
