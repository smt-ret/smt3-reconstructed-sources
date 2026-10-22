#pragma once
#include "types.h"

typedef struct effPCPMegidora01_tag effPCPMegidora01_tag;
typedef struct effPCPThunderSpherePoly_t effPCPThunderSpherePoly_t;

struct effPCPMegidora01_tag {
    sdfVector4_t pos;
    f32 scale;
    u32 abgr;
    u32 frame;
    effPCPThunderSpherePoly_t *pThunderPoly;
};
