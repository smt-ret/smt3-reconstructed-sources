#pragma once
#include "types.h"

typedef struct effPCPEyeThunder_tag effPCPEyeThunder_tag;
typedef struct effPCP_ThunderPoly_t effPCP_ThunderPoly_t;

struct effPCPEyeThunder_tag {
    sdfVector4_t pos;
    u32 abgr;
    u32 frame;
    f32 start;
    f32 length;
    effPCP_ThunderPoly_t *pThunderPoly;
};
