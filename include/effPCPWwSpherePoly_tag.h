#pragma once
#include "types.h"

typedef struct dds3WhirlwindPolyList_tag dds3WhirlwindPolyList_tag;
typedef struct effPCPWwSpherePolyParam_t effPCPWwSpherePolyParam_t;
typedef struct effPCPWwSpherePolyPart_tag effPCPWwSpherePolyPart_tag;
typedef struct effPCPWwSpherePoly_tag effPCPWwSpherePoly_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPWwSpherePoly_tag {
    sdfMatrix4_t matrix;
    effPCPWwSpherePolyParam_t *param;
    effPCPWwSpherePolyPart_tag pPart[UNKNOWN_ARRAY_SIZE];
    f32 scale;
    u32 abgr;
    dds3WhirlwindPolyList_tag *hPoly;
    sdfMemHandle_t *hMem;
};
