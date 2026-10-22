#pragma once
#include "types.h"

typedef struct effBTL_t effBTL_t;
typedef struct effPCPHelperBEDParam_t effPCPHelperBEDParam_t;
typedef struct effPCPHelperBEDPart_tag effPCPHelperBEDPart_tag;
typedef struct effPCPHelperBED_tag effPCPHelperBED_tag;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPHelperBED_tag {
    effPCPHelperBEDParam_t *param;
    effPCPHelperBEDPart_tag *pPart;
    sdfMemHandle_t *hPartMem;
    effBTL_t *hBED;
    effPartHandle_t *hHelper;
    f32 scale;
    s32 frame;
    s32 MarkLength;
    u32 MarkCount;
    u32 abgr;
};
