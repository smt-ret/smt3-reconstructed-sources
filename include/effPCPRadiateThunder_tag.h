#pragma once
#include "types.h"

typedef struct effPCPRadiateThunderParam_t effPCPRadiateThunderParam_t;
typedef struct effPCPRadiateThunderPart_tag effPCPRadiateThunderPart_tag;
typedef struct effPCPRadiateThunder_tag effPCPRadiateThunder_tag;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPRadiateThunder_tag {
    effPCPRadiateThunderParam_t *param;
    effPCPRadiateThunderPart_tag *pPart;
    f32 scale;
    f32 height;
    u32 abgr;
    effPartHandle_t **phAttach;
    sdfMemHandle_t *hAttachMem;
    sdfMemHandle_t *hMem;
};
