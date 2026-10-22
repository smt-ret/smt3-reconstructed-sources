import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

import build_array_lengths as bal
import field_offsets
from smt3 import smt3dump

HEADER = """struct Thing_Fields
{
  int8_t a;
  uint8_t b;
  struct System_UInt16_array *items;
  uint32_t tail;
};

struct __cppobj Derived_Fields : Thing_Fields
{
  struct System_Byte_array *extra;
};
"""


def layout() -> field_offsets.Layout:
    return field_offsets.Layout(field_offsets.parse(HEADER))


def test_offsets_follow_c_alignment() -> None:
    assert layout().offsets("Thing_Fields") == {"a": 0, "b": 1, "items": 8, "tail": 16}


def test_inherited_members_keep_their_declaring_struct() -> None:
    members = layout().members("Derived_Fields")
    assert members["items"] == (8, "Thing_Fields")
    assert members["extra"] == (24, "Derived_Fields")


def test_build_maps_object_offset_to_member() -> None:
    arrays = {"Thing+24": {"UInt16[]": {"11": 5}}}  # object offset 24 -> member offset 8
    classes = {"1": {"strings": {"16": "Thing", "24": ""}}}
    lengths, stats = bal.build(arrays, classes, layout())
    assert lengths == {"Thing": {"items": [11, True]}}
    assert stats["resolved"] == 1


def test_varying_lengths_are_not_fixed_size() -> None:
    arrays = {"Thing+24": {"UInt16[]": {"11": 5, "12": 2}}}
    classes = {"1": {"strings": {"16": "Thing", "24": ""}}}
    lengths, stats = bal.build(arrays, classes, layout())
    assert lengths == {}
    assert stats["ambiguous"] == 1


def test_offset_matching_no_member_is_dropped() -> None:
    arrays = {"Thing+88": {"UInt16[]": {"11": 5}}}  # past the object, an over-read
    classes = {"1": {"strings": {"16": "Thing", "24": ""}}}
    lengths, stats = bal.build(arrays, classes, layout())
    assert lengths == {}
    assert stats["no_member"] == 1


def test_reference_elements_are_not_value_types() -> None:
    arrays = {"Thing+24": {"String[]": {"4": 3}}}
    classes = {"1": {"strings": {"16": "Thing", "24": ""}}}
    lengths, _ = bal.build(arrays, classes, layout())
    assert lengths == {"Thing": {"items": [4, False]}}


def test_namespaced_class_resolves_to_prefixed_struct() -> None:
    header = HEADER.replace("Thing_Fields", "ns_H_Thing_Fields")
    lay = field_offsets.Layout(field_offsets.parse(header))
    arrays = {"Thing+24": {"UInt16[]": {"7": 1}}}
    classes = {"1": {"strings": {"16": "Thing", "24": "ns_H"}}}
    lengths, _ = bal.build(arrays, classes, lay)
    assert lengths == {"ns_H_Thing": {"items": [7, True]}}


def test_loader_flattens_to_size_map(tmp_path: Path) -> None:
    (tmp_path / "array_lengths.json").write_text(json.dumps({"S": {"f": [3, True]}}))
    assert smt3dump._load_array_lengths(tmp_path / "any.h") == {("S", "f"): (3, True)}


def test_loader_is_absent_without_the_file(tmp_path: Path) -> None:
    assert smt3dump._load_array_lengths(tmp_path / "any.h") == {}


NESTED_HEADER = """struct Inner_Fields
{
  uint32_t pad;
  struct System_Int32_array *values;
};

struct Outer_Fields
{
  uint64_t head;
  struct Inner_Fields inner;
};
"""


def test_inline_substruct_members_belong_to_the_substruct() -> None:
    lay = field_offsets.Layout(field_offsets.parse(NESTED_HEADER))
    members = lay.members("Outer_Fields")
    assert members["inner.values"] == (16, "Inner_Fields")


def test_build_attributes_nested_array_to_its_own_struct() -> None:
    lay = field_offsets.Layout(field_offsets.parse(NESTED_HEADER))
    arrays = {"Outer+32": {"Int32[]": {"6": 4}}}  # object offset 32 -> member offset 16
    classes = {"1": {"strings": {"16": "Outer", "24": ""}}}
    lengths, stats = bal.build(arrays, classes, lay)
    assert lengths == {"Inner": {"values": [6, True]}}
    assert stats["resolved"] == 1
