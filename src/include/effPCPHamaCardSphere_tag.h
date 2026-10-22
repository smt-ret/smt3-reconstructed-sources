#pragma once
#include "types.h"

typedef struct dds3ScatterPolyList_tag dds3ScatterPolyList_tag;
typedef struct effPCPHamaCardSphereParam_t effPCPHamaCardSphereParam_t;
typedef struct effPCPHamaCardSpherePart_tag effPCPHamaCardSpherePart_tag;
typedef struct effPCPHamaCardSphere_tag effPCPHamaCardSphere_tag;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPHamaCardSphere_tag {
    effPCPHamaCardSphereParam_t *param;
    effPCPHamaCardSpherePart_tag *pPart;
    f32 scale;
    u32 abgr;
    dds3ScatterPolyList_tag *hPoly;
    sdfMemHandle_t *hMem;
    u32 AttachNum;
    effPartHandle_t *pAttach;
    sdfMemHandle_t *hAttachMem;
};
