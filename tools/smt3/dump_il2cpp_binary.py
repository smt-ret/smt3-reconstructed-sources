"""Dump the loaded IL2CPP binary from IDA to a flat memory image.

Run inside IDA Pro (File > Script file..., or the console) on the database that holds the
Switch il2cpp `main` binary. It writes every loaded segment into one file at
``file_offset = ea - image_base``, so the file mirrors the in-memory image. Feed that file
plus ``global-metadata.dat`` to Il2CppDumper (choose the "dumped" option and enter the image
base printed below) to recover field offsets and the Il2CppType table (authoritative
field/const types) that metadata alone lacks.

Output: ``<idb dir>/il2cpp_dump.bin`` and the image base on the console.
"""

from __future__ import annotations

import os

import ida_bytes
import ida_nalt
import ida_segment
import idaapi

_CHUNK = 1 << 20  # read in 1 MiB chunks; get_bytes on a whole segment can be huge/slow


def _segments() -> list[tuple[int, int]]:
    segs: list[tuple[int, int]] = []
    for i in range(ida_segment.get_segm_qty()):
        s = ida_segment.getnseg(i)
        if s and s.end_ea > s.start_ea:
            segs.append((s.start_ea, s.end_ea))
    return sorted(segs)


def dump(out_path: str | None = None) -> None:
    segs = _segments()
    if not segs:
        print("[dump] no segments found")
        return
    base = segs[0][0]
    end = segs[-1][1]
    size = end - base
    out_path = out_path or os.path.join(
        os.path.dirname(ida_nalt.get_input_file_path()) or ".", "il2cpp_dump.bin"
    )

    print(f"[dump] image base = 0x{base:X}")
    print(f"[dump] span       = 0x{base:X} .. 0x{end:X}  ({size / 1024 / 1024:.1f} MiB)")
    print(f"[dump] segments   = {len(segs)}")

    with open(out_path, "wb") as fh:
        fh.truncate(size)  # zero-fill gaps between segments
        for start, stop in segs:
            fh.seek(start - base)
            ea = start
            while ea < stop:
                n = min(_CHUNK, stop - ea)
                data = ida_bytes.get_bytes(ea, n)
                if data is None:  # unmapped page inside the segment, leave it zero
                    ea += n
                    continue
                fh.write(data)
                ea += len(data)
    print(f"[dump] wrote {out_path}")
    print(f"[dump] -> Il2CppDumper: pick this file + global-metadata.dat; base 0x{base:X}")


if __name__ == "__main__":
    idaapi.auto_wait()  # make sure auto-analysis is done before dumping
    dump()
