#pragma once
#include "types.h"

typedef struct dds3WhirlwindPolyList_tag dds3WhirlwindPolyList_tag;
typedef struct effPCPWhirlwind3PolyParam_t effPCPWhirlwind3PolyParam_t;
typedef struct effPCPWhirlwind3PolyPart_tag effPCPWhirlwind3PolyPart_tag;
typedef struct effPCPWhirlwind3Poly_tag effPCPWhirlwind3Poly_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPWhirlwind3Poly_tag {
    sdfMatrix4_t matrix;
    effPCPWhirlwind3PolyParam_t *param;
    effPCPWhirlwind3PolyPart_tag *pPart;
    f32 scale;
    u32 abgr;
    s32 frame_all;
    dds3WhirlwindPolyList_tag *hPoly;
    sdfMemHandle_t *hMem;
};
