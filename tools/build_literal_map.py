#!/usr/bin/env python3
"""Derive the `StringLiteral_<n>` -> text map from global-metadata.dat."""

from __future__ import annotations

import argparse
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent / "smt3"))

import metadata as metadata_mod

SANITY = 0xFAB11BAF
SUPPORTED_VERSION = 24
USAGE_PAIRS_INDEX = 24
STRING_LITERAL_INDEX = 0
USAGE_KIND_STRING_LITERAL = 5


def read_header_section(data: bytes, index: int) -> tuple[int, int]:
    sanity, version = struct.unpack_from("<II", data, 0)
    if sanity != SANITY:
        raise ValueError(f"not a global-metadata.dat: sanity {sanity:#x}, expected {SANITY:#x}")
    if version != SUPPORTED_VERSION:
        raise ValueError(
            f"metadata version {version} unsupported; the usage tables this reads exist "
            f"only in version {SUPPORTED_VERSION}"
        )
    offset, size = struct.unpack_from("<II", data, 8 + index * 8)
    if offset + size > len(data):
        raise ValueError(f"section {index} runs past end of file: {offset}+{size} > {len(data)}")
    return offset, size


def parse_string_literal_usages(data: bytes) -> dict[int, int]:
    offset, size = read_header_section(data, USAGE_PAIRS_INDEX)
    usages: dict[int, int] = {}
    for i in range(size // 8):
        slot, encoded = struct.unpack_from("<II", data, offset + i * 8)
        if encoded >> 29 != USAGE_KIND_STRING_LITERAL:
            continue
        literal = encoded & 0x1FFFFFFF
        if usages.setdefault(slot, literal) != literal:
            raise ValueError(f"usage slot {slot} maps to two literals")
    return usages


def build_map(metadata_path: Path) -> dict[int, str]:
    data = metadata_path.read_bytes()
    _, literal_table_size = read_header_section(data, STRING_LITERAL_INDEX)
    expected = literal_table_size // 8

    usages = parse_string_literal_usages(data)
    if len(usages) != expected:
        raise ValueError(f"found {len(usages)} literal slots, metadata declares {expected}")

    base = min(usages)
    if max(usages) - base + 1 != expected:
        raise ValueError("string-literal usage slots are not contiguous")

    strings = metadata_mod.Metadata.from_file(metadata_path).strings
    # IDA numbers the cache slots from 1, so slot `base` is StringLiteral_1.
    return {slot - base + 1: strings[literal] for slot, literal in usages.items()}


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("metadata", type=Path, nargs="?", default=Path(__file__).parent / "inputs/global-metadata.dat")
    parser.add_argument("-o", "--output", type=Path, default=Path(__file__).parent / "inputs/stringliteral_map.json")
    parser.add_argument("--compare", type=Path, help="report disagreements against an existing map")
    args = parser.parse_args()

    literals = build_map(args.metadata)

    if args.compare:
        old = {int(k): v for k, v in json.loads(args.compare.read_text(encoding="utf-8")).items()}
        agree = sum(1 for n, text in old.items() if literals.get(n) == text)
        print(f"compare: {agree}/{len(old)} agree")

    args.output.write_text(
        json.dumps({str(n): literals[n] for n in sorted(literals)}, ensure_ascii=False, indent=0),
        encoding="utf-8",
    )
    print(f"wrote {len(literals)} literals to {args.output}")


if __name__ == "__main__":
    main()
