# inputs/

| File | Required | Produced by | Used for |
|---|---|---|---|
| `smt3hd_main.elf.h` | yes | IDA "Local Types" export of the IL2CPP `main` binary | struct/global/enum layouts (the core input) |
| `smt3hd_main.elf.c` | no | Hex-Rays "Export to C" of the same database | recovering fixed-array sizes, function prototypes and bodies (`--source`, `--bodies`) |
| `global-metadata.dat` | no | the game's IL2CPP `global-metadata.dat` | recovering enum member values and `#define` constants (`--metadata`) |
| `smt3hd_main.elf.map` | no | IDA "Produce MAP file" of the same database | authoritative function addresses for annotations and `symbols.txt` (`--map`) |

Usage:

```sh
smt3dump tools/inputs/smt3hd_main.elf.h -o src \
    --source tools/inputs/smt3hd_main.elf.c --metadata tools/inputs/global-metadata.dat \
    --map tools/inputs/smt3hd_main.elf.map --bodies --stats
```
