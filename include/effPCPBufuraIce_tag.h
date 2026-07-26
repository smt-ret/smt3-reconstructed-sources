#pragma once
#include "types.h"

typedef struct effPCPBufuraIce_tag effPCPBufuraIce_tag;
typedef struct effPartHandle_t effPartHandle_t;

struct effPCPBufuraIce_tag {
    sdfVector4_t pos;
    sdfMatrix4_t matrix;
    s32 frame;
    f32 rot_y;
    f32 scale;
    u32 abgr;
    effPartHandle_t hModel[UNKNOWN_ARRAY_SIZE];
};
