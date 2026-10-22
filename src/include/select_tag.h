#pragma once
#include "types.h"

typedef struct _FRQ _FRQ;
typedef struct defkey_tag defkey_tag;
typedef struct sdfIVector2_t sdfIVector2_t;
typedef struct select_tag select_tag;

struct select_tag {
    sdfIVector2_t *pos;
    _FRQ *pfont;
    u32 mask;
    s16 phase;
    s16 select;
    s16 select_imm;
    s16 lines;
    s16 alpha;
    s16 numdef;
    defkey_tag *defkey[16];
};
