#pragma once
#include "types.h"

typedef struct dds3WhirlwindPolyList_tag dds3WhirlwindPolyList_tag;
typedef struct effPCPWhirlwind2PolyParam_t effPCPWhirlwind2PolyParam_t;
typedef struct effPCPWhirlwind2PolyPart_tag effPCPWhirlwind2PolyPart_tag;
typedef struct effPCPWhirlwind2Poly_tag effPCPWhirlwind2Poly_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPWhirlwind2Poly_tag {
    sdfMatrix4_t matrix;
    effPCPWhirlwind2PolyParam_t *param;
    effPCPWhirlwind2PolyPart_tag *pPart;
    f32 scale;
    u32 abgr;
    s32 frame_all;
    dds3WhirlwindPolyList_tag *hPoly;
    sdfMemHandle_t *hMem;
};
