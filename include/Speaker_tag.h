#pragma once
#include "types.h"

typedef struct Speaker_tag Speaker_tag;
typedef struct _FRQ _FRQ;
typedef struct sdfIVector2_t sdfIVector2_t;

struct Speaker_tag {
    sdfIVector2_t *pos;
    _FRQ *pfont;
    u16 num;
    s16 reserved;
};
