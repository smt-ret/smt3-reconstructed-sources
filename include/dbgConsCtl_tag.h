#pragma once
#include "types.h"

typedef struct dbgConsCtl_tag dbgConsCtl_tag;
typedef struct sdfDrawTag_t sdfDrawTag_t;

struct dbgConsCtl_tag {
    s32 px;
    s32 py;
    s32 sx;
    s32 sy;
    u32 pz;
    u32 panelCol;
    u32 frameCol;
    s32 cx;
    s32 cy;
    s32 cz;
    sdfDrawTag_t *tag;
};
