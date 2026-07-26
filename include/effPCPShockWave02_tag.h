#pragma once
#include "types.h"

typedef struct effPCPShockWave02_tag effPCPShockWave02_tag;
typedef struct effPCP_ThunderPoly_t effPCP_ThunderPoly_t;

struct effPCPShockWave02_tag {
    sdfVector4_t pos;
    f32 radius;
    f32 scale;
    u32 abgr;
    effPCP_ThunderPoly_t pThunderPoly[UNKNOWN_ARRAY_SIZE];
};
