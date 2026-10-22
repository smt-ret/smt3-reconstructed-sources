#pragma once
#include "types.h"

typedef struct dds3RingPolyExpList_tag dds3RingPolyExpList_tag;
typedef struct effPCPRingPolyExp2Param_t effPCPRingPolyExp2Param_t;
typedef struct effPCPRingPolyExp2_tag effPCPRingPolyExp2_tag;

struct effPCPRingPolyExp2_tag {
    effPCPRingPolyExp2Param_t *param;
    s32 frame;
    u32 abgr;
    f32 rotate_z;
    f32 rotate_y;
    f32 rotate_s;
    f32 rotate_a;
    f32 radius;
    f32 radius_s;
    dds3RingPolyExpList_tag *hPoly;
};
