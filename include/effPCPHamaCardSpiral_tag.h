#pragma once
#include "types.h"

typedef struct dds3ScatterPolyList_tag dds3ScatterPolyList_tag;
typedef struct effPCPHamaCardSpiralParam_t effPCPHamaCardSpiralParam_t;
typedef struct effPCPHamaCardSpiralPart_tag effPCPHamaCardSpiralPart_tag;
typedef struct effPCPHamaCardSpiral_tag effPCPHamaCardSpiral_tag;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPHamaCardSpiral_tag {
    effPCPHamaCardSpiralParam_t *param;
    effPCPHamaCardSpiralPart_tag pPart[UNKNOWN_ARRAY_SIZE];
    f32 scale;
    u32 abgr;
    dds3ScatterPolyList_tag *hPoly;
    sdfMemHandle_t *hMem;
    u32 AttachNum;
    effPartHandle_t pAttach[UNKNOWN_ARRAY_SIZE];
    sdfMemHandle_t *hAttachMem;
};
