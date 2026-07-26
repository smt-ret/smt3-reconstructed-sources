#pragma once
#include "types.h"

typedef struct sdfMotNodeMatBase_t sdfMotNodeMatBase_t;
typedef struct sdfMotNodeMatColor_t sdfMotNodeMatColor_t;

struct sdfMotNodeMatColor_t {
    sdfMotNodeMatBase_t *base;
    u32 blendSrc;
};
