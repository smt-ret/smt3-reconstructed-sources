#!/usr/bin/env python3
"""Compare a runtime IL2CPP literal dump against the inferred map, then merge.

The inferred map in inputs/stringliteral_map.json was derived by cross-referencing the HD
build against the PS2 one. A dump read straight out of the running game is authoritative,
so any disagreement is an error in the inference and worth seeing before merging.

    verify_literal_dump.py <il2cpp_strings.json> [--merge]
"""
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
INFERRED = HERE / "inputs" / "stringliteral_map.json"


def main(argv: list[str]) -> int:
    if not argv:
        print(__doc__)
        return 2
    dump = {int(k): v for k, v in json.loads(Path(argv[0]).read_text(encoding="utf-8")).items()}
    inferred = {int(k): v for k, v in json.loads(INFERRED.read_text(encoding="utf-8")).items()}

    both = sorted(set(dump) & set(inferred))
    bad = [n for n in both if dump[n] != inferred[n]]
    print(f"runtime dump   : {len(dump)} literals")
    print(f"inferred map   : {len(inferred)} literals")
    print(f"overlap        : {len(both)}")
    print(f"disagreements  : {len(bad)}")
    for n in bad[:20]:
        print(f"   StringLiteral_{n}: runtime {dump[n]!r} vs inferred {inferred[n]!r}")

    if "--merge" not in argv:
        print("\n(pass --merge to write the union, runtime winning on conflicts)")
        return 1 if bad else 0

    merged = dict(inferred)
    merged.update(dump)  # the runtime is authoritative
    INFERRED.write_text(
        json.dumps({str(k): merged[k] for k in sorted(merged)}, indent=1, ensure_ascii=False),
        encoding="utf-8",
    )
    print(f"\nmerged: {len(merged)} literals written to {INFERRED}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
