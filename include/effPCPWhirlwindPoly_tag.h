#pragma once
#include "types.h"

typedef struct dds3WhirlwindPolyList_tag dds3WhirlwindPolyList_tag;
typedef struct effPCPWhirlwindPolyParam_t effPCPWhirlwindPolyParam_t;
typedef struct effPCPWhirlwindPolyPart_tag effPCPWhirlwindPolyPart_tag;
typedef struct effPCPWhirlwindPoly_tag effPCPWhirlwindPoly_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPWhirlwindPoly_tag {
    sdfMatrix4_t matrix;
    effPCPWhirlwindPolyParam_t *param;
    effPCPWhirlwindPolyPart_tag pPart[UNKNOWN_ARRAY_SIZE];
    f32 scale;
    u32 abgr;
    dds3WhirlwindPolyList_tag *hPoly;
    sdfMemHandle_t *hMem;
};
