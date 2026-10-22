#!/usr/bin/env python3
"""Turn a runtime heap scan of Il2CppArray lengths into fixed array counts for the generator."""

from __future__ import annotations

import argparse
import json
from pathlib import Path

import field_offsets

OBJECT_HEADER_SIZE = 16  # Il2CppObject: klass, monitor

# Element types stored inline rather than as pointers.
VALUE_ELEMENTS = frozenset({
    "Byte", "SByte", "Int16", "UInt16", "Int32", "UInt32", "Int64", "UInt64",
    "Char", "Single", "Double", "Boolean", "IntPtr", "UIntPtr", "Decimal",
    "Vector2", "Vector3", "Vector4", "Quaternion", "Matrix4x4", "Color", "Color32",
})


def is_value_element(element: str) -> bool:
    return element.removesuffix("[]") in VALUE_ELEMENTS


def struct_suffixes(name: str) -> tuple[str, ...]:
    return (f"{name}_Fields", f"{name}_StaticFields")


def class_namespaces(classes: dict) -> dict[str, set[str]]:
    """Class name -> the namespaces it was seen in."""
    namespaces: dict[str, set[str]] = {}
    for record in classes.values():
        strings = record["strings"]
        name = strings.get("16")
        if name:
            namespaces.setdefault(name, set()).add(strings.get("24", ""))
    return namespaces


def base_of(struct: str) -> str:
    for suffix in ("_StaticFields", "_Fields"):
        if struct.endswith(suffix):
            return struct[: -len(suffix)]
    return struct


def build(arrays: dict, classes: dict, layout: field_offsets.Layout) -> tuple[dict, dict]:
    namespaces = class_namespaces(classes)
    lengths: dict[str, dict[str, int]] = {}
    stats = {"observations": 0, "no_class": 0, "no_struct": 0, "no_member": 0,
             "ambiguous": 0, "resolved": 0, "conflict": 0}

    for key, elements in arrays.items():
        owner, _, offset_text = key.rpartition("+")
        stats["observations"] += 1
        seen = {int(n) for counts in elements.values() for n in counts}
        if len(seen) != 1:
            stats["ambiguous"] += 1
            continue
        count = seen.pop()
        is_value = all(is_value_element(e) for e in elements)

        candidates = namespaces.get(owner)
        if not candidates:
            stats["no_class"] += 1
            continue

        member_offset = int(offset_text) - OBJECT_HEADER_SIZE
        matched = None
        for namespace in candidates:
            prefix = f"{namespace}_{owner}" if namespace else owner
            for struct in struct_suffixes(prefix):
                members = layout.members(struct)
                if not members:
                    continue
                for member, (off, declaring) in members.items():
                    if off == member_offset:
                        # "outer.inner" belongs to the sub-struct: key it by the inner name.
                        matched = (base_of(declaring), member.rpartition(".")[2])
                        break
                if matched:
                    break
            if matched:
                break

        if matched is None:
            stats["no_member"] += 1
            continue
        struct_base, member = matched
        previous = lengths.setdefault(struct_base, {}).get(member)
        if previous is not None and previous[0] != count:
            stats["conflict"] += 1
            continue
        lengths[struct_base][member] = [count, is_value]
        stats["resolved"] += 1
    return lengths, stats


def main() -> None:
    here = Path(__file__).parent
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--arrays", type=Path, default=here / "inputs/il2cpp_arrays.json")
    parser.add_argument("--classes", type=Path, default=here / "inputs/il2cpp_classes.json")
    parser.add_argument("--header", type=Path, default=here / "inputs/smt3hd_main.elf.h")
    parser.add_argument("-o", "--output", type=Path, default=here / "inputs/array_lengths.json")
    args = parser.parse_args()

    layout = field_offsets.load(args.header)
    lengths, stats = build(json.loads(args.arrays.read_text()),
                           json.loads(args.classes.read_text()), layout)
    for name, value in stats.items():
        print(f"  {name:<14} {value}")
    fields = sum(len(v) for v in lengths.values())
    args.output.write_text(json.dumps(lengths, indent=0, sort_keys=True), encoding="utf-8")
    print(f"wrote {fields} array lengths across {len(lengths)} structs to {args.output}")


if __name__ == "__main__":
    main()
