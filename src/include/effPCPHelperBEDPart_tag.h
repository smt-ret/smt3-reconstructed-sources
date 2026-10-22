#pragma once
#include "types.h"

typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct effPCPHelperBEDPart_tag effPCPHelperBEDPart_tag;

struct effPCPHelperBEDPart_tag {
    sdfVector4_t pos;
    u8 move;
    s32 frame;
    s32 life;
    effEveBEDCutHandle_t *hBEDCut;
};
