#pragma once
#include "types.h"

typedef struct effPCPHwave01_tag effPCPHwave01_tag;
typedef struct effPartHandle_t effPartHandle_t;

struct effPCPHwave01_tag {
    sdfVector4_t pos;
    u32 abgr;
    effPartHandle_t *hPB;
    effPartHandle_t *hD3P;
};
