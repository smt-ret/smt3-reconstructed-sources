#pragma once
#include "types.h"

typedef struct dds3ScatterPolyList_tag dds3ScatterPolyList_tag;
typedef struct effPCPHamaCardScatterParam_t effPCPHamaCardScatterParam_t;
typedef struct effPCPHamaCardScatterPart_tag effPCPHamaCardScatterPart_tag;
typedef struct effPCPHamaCardScatter_tag effPCPHamaCardScatter_tag;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPHamaCardScatter_tag {
    effPCPHamaCardScatterParam_t *param;
    effPCPHamaCardScatterPart_tag *pPart;
    f32 scale;
    u32 abgr;
    dds3ScatterPolyList_tag *hPoly;
    sdfMemHandle_t *hMem;
    u32 AttachNum;
    effPartHandle_t *pAttach;
    sdfMemHandle_t *hAttachMem;
};
