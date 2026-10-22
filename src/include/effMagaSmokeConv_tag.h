#pragma once
#include "types.h"

typedef struct effBezier4P_t effBezier4P_t;
typedef struct effMagaSmokeConvParam_t effMagaSmokeConvParam_t;
typedef struct effMagaSmokeConvPart_tag effMagaSmokeConvPart_tag;
typedef struct effMagaSmokeConv_tag effMagaSmokeConv_tag;
typedef struct effMagatuhi_tag effMagatuhi_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effMagaSmokeConv_tag {
    effMagaSmokeConvParam_t *param;
    effMagaSmokeConvPart_tag *pPart;
    effBezier4P_t *pBezier4P;
    f32 scale;
    u32 abgr;
    effMagatuhi_tag *pMagatuhi;
    sdfMemHandle_t *hMem;
};
