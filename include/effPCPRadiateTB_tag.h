#pragma once
#include "types.h"

typedef struct effBTL_t effBTL_t;
typedef struct effPCPRadiateTBParam_t effPCPRadiateTBParam_t;
typedef struct effPCPRadiateTBPart_tag effPCPRadiateTBPart_tag;
typedef struct effPCPRadiateTB_tag effPCPRadiateTB_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effPCPRadiateTB_tag {
    effPCPRadiateTBParam_t *param;
    effPCPRadiateTBPart_tag pPart[UNKNOWN_ARRAY_SIZE];
    effBTL_t hBED[UNKNOWN_ARRAY_SIZE];
    u8 original;
    u32 abgr;
    sdfMemHandle_t *hMem;
};
