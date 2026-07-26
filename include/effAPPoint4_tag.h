#pragma once
#include "types.h"

typedef struct effAPPoint4Param_t effAPPoint4Param_t;
typedef struct effAPPoint4Part_tag effAPPoint4Part_tag;
typedef struct effAPPoint4_tag effAPPoint4_tag;
typedef struct effBezier4P_t effBezier4P_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct effAPPoint4_tag {
    effAPPoint4Param_t *param;
    effAPPoint4Part_tag pPart[UNKNOWN_ARRAY_SIZE];
    effBezier4P_t *pBezier4P;
    sdfMemHandle_t *hMem;
};
