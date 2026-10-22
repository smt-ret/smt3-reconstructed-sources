#pragma once
#include "types.h"

typedef struct sdfGrScreenDef_t sdfGrScreenDef_t;

struct sdfGrScreenDef_t {
    s16 w;
    s16 h;
    s16 buffH;
    u16 pixelFormat;
    u16 zbuffFormat;
    u16 fieldFrameMode;
};
