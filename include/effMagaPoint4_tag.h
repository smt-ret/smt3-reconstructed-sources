#pragma once
#include "types.h"

typedef struct effBezier4P_t effBezier4P_t;
typedef struct effMagaPoint4Param_t effMagaPoint4Param_t;
typedef struct effMagaPoint4Part_tag effMagaPoint4Part_tag;
typedef struct effMagaPoint4_tag effMagaPoint4_tag;
typedef struct effMagatuhi_tag effMagatuhi_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effMagaPoint4_tag {
    effMagaPoint4Param_t *param;
    effMagaPoint4Part_tag pPart[UNKNOWN_ARRAY_SIZE];
    effBezier4P_t *pBezier4P;
    effMagatuhi_tag *pMagatuhi;
    sdfMemHandle_t *hMem;
};
