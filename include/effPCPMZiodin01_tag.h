#pragma once
#include "types.h"

typedef struct effPCPMZiodin01_tag effPCPMZiodin01_tag;
typedef struct effPCP_ThunderPoly_t effPCP_ThunderPoly_t;

struct effPCPMZiodin01_tag {
    sdfVector4_t pos;
    f32 radius;
    f32 scale;
    u32 abgr;
    effPCP_ThunderPoly_t *pThunderPoly;
};
