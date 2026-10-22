#pragma once
#include "types.h"

typedef struct dds3RingPolyExpList_tag dds3RingPolyExpList_tag;
typedef struct effPCPRingPolyExpParam_t effPCPRingPolyExpParam_t;
typedef struct effPCPRingPolyExp_tag effPCPRingPolyExp_tag;

struct effPCPRingPolyExp_tag {
    effPCPRingPolyExpParam_t *param;
    s32 frame;
    u32 abgr;
    u32 point_max;
    dds3RingPolyExpList_tag *hPoly;
};
