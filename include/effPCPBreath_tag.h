#pragma once
#include "types.h"

typedef struct effPCPBreathParam_t effPCPBreathParam_t;
typedef struct effPCPBreath_tag effPCPBreath_tag;

struct effPCPBreath_tag {
    sdfMatrix4_t matrix;
    effPCPBreathParam_t *param;
    u32 abgr;
    u32 frame;
    f32 rotate;
    f32 speed;
    void *hD3P;
};
