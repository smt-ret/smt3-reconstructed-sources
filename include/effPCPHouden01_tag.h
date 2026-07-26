#pragma once
#include "types.h"

typedef struct effPCPHouden01_tag effPCPHouden01_tag;
typedef struct effPCPThunderSpherePoly_t effPCPThunderSpherePoly_t;

struct effPCPHouden01_tag {
    sdfVector4_t pos;
    f32 scale;
    u32 abgr;
    u32 frame;
    effPCPThunderSpherePoly_t *pThunderPoly;
};
