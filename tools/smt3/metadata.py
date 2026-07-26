"""
IL2CPP global-metadata.dat parser based off of il2cppdumper.
"""

from __future__ import annotations

import bisect
import struct
from dataclasses import dataclass, field
from pathlib import Path

_MAGIC = 0xFAB11BAF
_VERSION = 24

# Ordinal positions of the (offset,size) pairs in the v24 header, after magic+version.
_SECTIONS = (
    "stringLiteral", "stringLiteralData", "string", "events", "properties", "methods",
    "parameterDefaultValues", "fieldDefaultValues", "fieldAndParamData",
    "fieldMarshaledSizes", "parameters", "fields",
)

_TYPEDEF_SIZE = 100  # Il2CppTypeDefinition (this v24 variant)
_TD_NAME = 0         # nameIndex (int32)
_TD_FIELD_START = 44  # fieldStart (int32)
_TD_FIELD_COUNT = 80  # field_count (uint16)
_FIELD_SIZE = 12     # Il2CppFieldDefinition: nameIndex, typeIndex, token
_FDV_SIZE = 12       # Il2CppFieldDefaultValue: fieldIndex, typeIndex, dataIndex
_TYPEDEFS_INDEX = 19  # ordinal of typeDefinitions in the header


def decode_value(raw: bytes) -> int | str | None:
    """Decode a default-value blob slice: length-prefixed UTF-8 string, or a little-endian
    integer. A 4/8-byte float/double returns as its integer bit pattern (type not stored).
    """
    if not raw:
        return None
    if len(raw) >= 5:  # possible length-prefixed string
        n = int.from_bytes(raw[:4], "little", signed=True)
        if n == len(raw) - 4 > 0:
            try:
                text = raw[4:].decode("utf-8")
                if text.isprintable():
                    return text
            except UnicodeDecodeError:
                pass
    if len(raw) > 8:
        return raw.hex()  # opaque blob (byte array, GUID, ...)
    return int.from_bytes(raw, "little", signed=True)


def _empty_enums() -> dict[str, list[tuple[str, int]]]:
    return {}


def _empty_constants() -> dict[str, list[tuple[str, int | str | None]]]:
    return {}


@dataclass
class Metadata:
    """Enum and constant values keyed by IL2CPP short type name."""

    enums: dict[str, list[tuple[str, int]]] = field(default_factory=_empty_enums)
    constants: dict[str, list[tuple[str, int | str | None]]] = field(
        default_factory=_empty_constants
    )

    @classmethod
    def from_file(cls, path: Path) -> Metadata:
        return cls.from_bytes(path.read_bytes())

    @classmethod
    def from_bytes(cls, d: bytes) -> Metadata:  # noqa: C901 - a flat binary walk
        magic, version = struct.unpack_from("<Ii", d, 0)
        if magic != _MAGIC or version != _VERSION:
            raise ValueError(f"not a v{_VERSION} metadata (magic=0x{magic:08X} version={version})")

        def i32(o: int) -> int:
            return struct.unpack_from("<i", d, o)[0]

        def u16(o: int) -> int:
            return struct.unpack_from("<H", d, o)[0]

        def pair(n: int) -> tuple[int, int]:
            return i32(8 + 8 * n), i32(8 + 8 * n + 4)

        sec = {name: pair(n) for n, name in enumerate(_SECTIONS)}
        str_off = sec["string"][0]

        def name(idx: int) -> str:
            end = d.index(b"\x00", str_off + idx)
            return d[str_off + idx : end].decode("ascii", "replace")

        data_off, data_size = sec["fieldAndParamData"]
        fdv_off, fdv_size = sec["fieldDefaultValues"]
        field_value: dict[int, int] = {}
        boundaries: set[int] = set()
        for k in range(fdv_size // _FDV_SIZE):
            b = fdv_off + k * _FDV_SIZE
            field_value[i32(b)] = i32(b + 8)  # fieldIndex -> dataIndex
            boundaries.add(i32(b + 8))
        p_off, p_size = sec["parameterDefaultValues"]
        for k in range(p_size // 12):
            boundaries.add(i32(p_off + k * 12 + 8))
        bounds = sorted(x for x in boundaries if x >= 0) + [data_size]

        def value_at(data_index: int) -> int | str | None:
            j = bisect.bisect_right(bounds, data_index)
            raw = d[data_off + data_index : data_off + bounds[j]]
            return decode_value(raw)

        fields_off = sec["fields"][0]

        def field_name(fi: int) -> str:
            return name(i32(fields_off + fi * _FIELD_SIZE))

        td_off, td_size = pair(_TYPEDEFS_INDEX)
        meta = cls()
        for t in range(td_size // _TYPEDEF_SIZE):
            b = td_off + t * _TYPEDEF_SIZE
            start = i32(b + _TD_FIELD_START)
            count = u16(b + _TD_FIELD_COUNT)
            if count == 0:
                continue
            valued = [
                (field_name(fi), field_value[fi]) for fi in range(start, start + count)
                if fi in field_value
            ]
            if not valued:
                continue
            tname = name(i32(b + _TD_NAME))
            if field_name(start) == "value__":  # enum: integral members
                members = [(n, v) for n, di in valued if isinstance(v := value_at(di), int)]
                if members:
                    meta.enums[tname] = members
            else:
                meta.constants[tname] = [(n, value_at(di)) for n, di in valued]
        _validate(meta)
        return meta


def _validate(meta: Metadata) -> None:
    if not meta.enums and not meta.constants:
        raise ValueError("metadata parse produced no enums or constants (layout mismatch?)")
