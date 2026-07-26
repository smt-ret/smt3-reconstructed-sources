#pragma once
#include "types.h"

typedef struct effPCPBufuIce_tag effPCPBufuIce_tag;
typedef struct effPartHandle_t effPartHandle_t;

struct effPCPBufuIce_tag {
    sdfVector4_t pos;
    sdfMatrix4_t matrix;
    s32 frame;
    f32 rot_y;
    f32 scale;
    u32 abgr;
    effPartHandle_t *hModel;
};
