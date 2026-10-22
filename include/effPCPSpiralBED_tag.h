#pragma once
#include "types.h"

typedef struct effBTL_t effBTL_t;
typedef struct effPCPSpiralBEDParam_t effPCPSpiralBEDParam_t;
typedef struct effPCPSpiralBEDPart_tag effPCPSpiralBEDPart_tag;
typedef struct effPCPSpiralBED_tag effPCPSpiralBED_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPSpiralBED_tag {
    effPCPSpiralBEDParam_t *param;
    effPCPSpiralBEDPart_tag *pPart;
    effBTL_t *hBED;
    u8 original;
    f32 scale;
    u32 abgr;
    sdfMemHandle_t *hMem;
};
