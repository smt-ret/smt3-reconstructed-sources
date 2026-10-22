import struct
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

import build_literal_map as blm


def make_metadata(pairs: list[tuple[int, int]], literal_count: int = 2) -> bytes:
    header = bytearray(struct.pack("<II", blm.SANITY, blm.SUPPORTED_VERSION))
    header += bytes(8 * 33)
    body_start = len(header)

    literal_size = literal_count * 8
    pairs_offset = body_start + literal_size
    struct.pack_into("<II", header, 8 + blm.STRING_LITERAL_INDEX * 8, body_start, literal_size)
    struct.pack_into("<II", header, 8 + blm.USAGE_PAIRS_INDEX * 8, pairs_offset, len(pairs) * 8)

    body = bytes(literal_size) + b"".join(struct.pack("<II", s, e) for s, e in pairs)
    return bytes(header) + body


def encode(kind: int, index: int) -> int:
    return (kind << 29) | index


def test_decodes_string_literal_usages() -> None:
    data = make_metadata([(100, encode(blm.USAGE_KIND_STRING_LITERAL, 7))])
    assert blm.parse_string_literal_usages(data) == {100: 7}


def test_ignores_other_usage_kinds() -> None:
    data = make_metadata([(100, encode(1, 7)), (101, encode(blm.USAGE_KIND_STRING_LITERAL, 9))])
    assert blm.parse_string_literal_usages(data) == {101: 9}


def test_repeated_slot_with_same_literal_is_accepted() -> None:
    entry = (100, encode(blm.USAGE_KIND_STRING_LITERAL, 7))
    assert blm.parse_string_literal_usages(make_metadata([entry, entry])) == {100: 7}


def test_conflicting_slot_raises() -> None:
    data = make_metadata(
        [
            (100, encode(blm.USAGE_KIND_STRING_LITERAL, 7)),
            (100, encode(blm.USAGE_KIND_STRING_LITERAL, 8)),
        ]
    )
    with pytest.raises(ValueError, match="two literals"):
        blm.parse_string_literal_usages(data)


def test_index_mask_ignores_kind_bits() -> None:
    data = make_metadata([(0, encode(blm.USAGE_KIND_STRING_LITERAL, 0x1FFFFFFF))])
    assert blm.parse_string_literal_usages(data) == {0: 0x1FFFFFFF}


def test_bad_sanity_raises() -> None:
    data = bytearray(make_metadata([]))
    struct.pack_into("<I", data, 0, 0xDEADBEEF)
    with pytest.raises(ValueError, match="sanity"):
        blm.read_header_section(bytes(data), blm.USAGE_PAIRS_INDEX)


def test_unsupported_version_raises() -> None:
    data = bytearray(make_metadata([]))
    struct.pack_into("<I", data, 4, 29)
    with pytest.raises(ValueError, match="version 29"):
        blm.read_header_section(bytes(data), blm.USAGE_PAIRS_INDEX)


def test_section_past_end_raises() -> None:
    data = bytearray(make_metadata([]))
    struct.pack_into("<II", data, 8 + blm.USAGE_PAIRS_INDEX * 8, 16, 1 << 30)
    with pytest.raises(ValueError, match="past end"):
        blm.read_header_section(bytes(data), blm.USAGE_PAIRS_INDEX)


def test_build_map_is_one_based(tmp_path: Path) -> None:
    slots = [(50, encode(blm.USAGE_KIND_STRING_LITERAL, 0)), (51, encode(blm.USAGE_KIND_STRING_LITERAL, 1))]
    path = tmp_path / "global-metadata.dat"
    path.write_bytes(make_metadata(slots))

    class FakeMetadata:
        strings = {0: "zero", 1: "one"}

    original = blm.metadata_mod.Metadata.from_file
    blm.metadata_mod.Metadata.from_file = staticmethod(lambda _: FakeMetadata())
    try:
        assert blm.build_map(path) == {1: "zero", 2: "one"}
    finally:
        blm.metadata_mod.Metadata.from_file = original


def test_build_map_rejects_non_contiguous_slots(tmp_path: Path) -> None:
    slots = [(50, encode(blm.USAGE_KIND_STRING_LITERAL, 0)), (99, encode(blm.USAGE_KIND_STRING_LITERAL, 1))]
    path = tmp_path / "global-metadata.dat"
    path.write_bytes(make_metadata(slots))
    with pytest.raises(ValueError, match="not contiguous"):
        blm.build_map(path)


def test_build_map_rejects_count_mismatch(tmp_path: Path) -> None:
    slots = [(50, encode(blm.USAGE_KIND_STRING_LITERAL, 0))]
    path = tmp_path / "global-metadata.dat"
    path.write_bytes(make_metadata(slots, literal_count=5))
    with pytest.raises(ValueError, match="metadata declares 5"):
        blm.build_map(path)
