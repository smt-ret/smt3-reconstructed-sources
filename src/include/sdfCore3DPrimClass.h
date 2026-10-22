#pragma once
#include "types.h"

typedef struct sdfCore3DPrimClass sdfCore3DPrimClass;
typedef struct sdfDmaTag_t sdfDmaTag_t;
typedef struct sdfGifTag_t sdfGifTag_t;

struct sdfCore3DPrimClass {
    sdfDmaTag_t *dmatag;
    sdfGifTag_t *giftag;
};
