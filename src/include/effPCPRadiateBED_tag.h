#pragma once
#include "types.h"

typedef struct effBTL_t effBTL_t;
typedef struct effPCPRadiateBEDParam_t effPCPRadiateBEDParam_t;
typedef struct effPCPRadiateBEDPart_tag effPCPRadiateBEDPart_tag;
typedef struct effPCPRadiateBED_tag effPCPRadiateBED_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPRadiateBED_tag {
    effPCPRadiateBEDParam_t *param;
    effPCPRadiateBEDPart_tag *pPart;
    effBTL_t *hBED;
    u8 original;
    f32 scale;
    u32 abgr;
    sdfMemHandle_t *hMem;
};
