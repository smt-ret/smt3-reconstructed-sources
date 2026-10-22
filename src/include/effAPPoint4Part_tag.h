#pragma once
#include "types.h"

typedef struct effAPPoint4Part_tag effAPPoint4Part_tag;
typedef struct effPartHandle_t effPartHandle_t;

struct effAPPoint4Part_tag {
    s32 frame;
    effPartHandle_t *hPart;
};
