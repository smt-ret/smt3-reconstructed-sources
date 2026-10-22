"""Annotate the SMT3 HD IDB with recovered string literals and observed array lengths.

Run inside IDA. Reads the two JSON inputs from $SMT3_FINDINGS, else this script's directory.
"""

import json
import os

import ida_bytes
import ida_kernwin
import ida_name
import idc

# Hex-Rays prints a global's name but not its comment, so the text goes in the name to reach
# the pseudocode; the comment keeps the exact text.
RENAME_LITERALS = True
MAX_COMMENT = 400
MAX_NAME = 48


def findings_dir():
    override = os.environ.get("SMT3_FINDINGS")
    if override:
        return override
    return os.path.dirname(os.path.abspath(__file__))


def load(name):
    path = os.path.join(findings_dir(), name)
    if not os.path.isfile(path):
        raise RuntimeError(
            "%s not found. Copy it next to this script, or set SMT3_FINDINGS to its "
            "directory." % path
        )
    with open(path, "rb") as fh:
        return json.loads(fh.read().decode("utf-8"))


def identifier(text):
    """The ASCII identifier part of `text`, or None when nothing usable survives."""
    kept = "".join(c if (c.isalnum() and c.isascii()) or c == "_" else "_" for c in text)
    while "__" in kept:
        kept = kept.replace("__", "_")
    kept = kept.strip("_")
    return kept[:MAX_NAME] or None


def apply_literals(literals):
    applied = missing = renamed = 0
    for ordinal, text in literals.items():
        ea = ida_name.get_name_ea(idc.BADADDR, "StringLiteral_%s" % ordinal)
        if ea == idc.BADADDR:
            missing += 1
            continue
        comment = text if len(text) <= MAX_COMMENT else text[:MAX_COMMENT] + "..."
        ida_bytes.set_cmt(ea, comment, True)
        applied += 1
        if not RENAME_LITERALS:
            continue
        # The ordinal keeps it unique: texts repeat, and non-ASCII ones leave no stem at all.
        stem = identifier(text)
        name = "sl_%s_%s" % (stem, ordinal) if stem else "sl_%s" % ordinal
        if ida_name.set_name(ea, name, ida_name.SN_NOWARN | ida_name.SN_FORCE):
            renamed += 1
    return applied, missing, renamed


def struct_id(name):
    tid = idc.get_struc_id(name)
    return None if tid == idc.BADADDR else tid


def apply_array_lengths(lengths):
    applied = missing = 0
    for struct, members in lengths.items():
        # The reconstruction strips the IL2CPP variant suffix; the IDB keeps it.
        candidates = [struct + "_Fields", struct + "_StaticFields", struct]
        tid = next((t for t in map(struct_id, candidates) if t is not None), None)
        if tid is None:
            missing += len(members)
            continue
        for member, value in members.items():
            count = value[0] if isinstance(value, list) else value
            offset = idc.get_member_offset(tid, member)
            if offset == -1:
                missing += 1
                continue
            idc.set_member_cmt(tid, offset, "runtime length %d" % count, True)
            applied += 1
    return applied, missing


def main():
    literals = load("stringliteral_map.json")
    lengths = load("array_lengths.json")

    applied, missing, renamed = apply_literals(literals)
    print("string literals: %d commented, %d not in this database, %d renamed"
          % (applied, missing, renamed))

    applied_arrays, missing_arrays = apply_array_lengths(lengths)
    print("array lengths: %d commented, %d members not found" % (applied_arrays, missing_arrays))

    ida_kernwin.msg("SMT3 findings applied.\n")


if __name__ == "__main__":
    main()
