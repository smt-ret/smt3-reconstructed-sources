#pragma once
#include "types.h"

typedef struct effPCPRadiateThunderPart_tag effPCPRadiateThunderPart_tag;
typedef struct effPCP_ThunderPoly_t effPCP_ThunderPoly_t;

struct effPCPRadiateThunderPart_tag {
    effPCP_ThunderPoly_t *pThunderPoly;
    s32 frame;
    f32 radius;
    f32 radius_s;
    f32 radian;
    f32 radian_s;
};
