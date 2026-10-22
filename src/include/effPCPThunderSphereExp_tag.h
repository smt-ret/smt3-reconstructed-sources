#pragma once
#include "types.h"

typedef struct effPCPThunderSphereExp_tag effPCPThunderSphereExp_tag;
typedef struct effPCPThunderSpherePoly_t effPCPThunderSpherePoly_t;

struct effPCPThunderSphereExp_tag {
    sdfVector4_t pos;
    s32 life;
    s32 fade_in;
    s32 fade_out;
    s32 radius_s;
    s32 radius_e;
    u32 abgr;
    s32 frame;
    f32 scale;
    effPCPThunderSpherePoly_t *pThunderSpherePoly;
};
