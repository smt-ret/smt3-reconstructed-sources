#pragma once
#include "types.h"

typedef struct sdfDevConsDrawCB_t sdfDevConsDrawCB_t;

struct sdfDevConsDrawCB_t {
    s32 buffSize;
    u16 dblBuffId;
    u16 stepY;
};
