#pragma once
#include "types.h"

typedef struct sdfDevConsClass sdfDevConsClass;
typedef struct sdfDmaTag_t sdfDmaTag_t;
typedef struct sdfGifTag_t sdfGifTag_t;

struct sdfDevConsClass {
    sdfDmaTag_t *dmaTag;
    sdfGifTag_t *texGifTag;
    u64 clampData;
    u64 clampReg;
    u64 tex1Data;
    u64 tex1Reg;
    u64 tex0Data;
    u64 tex0Reg;
    sdfGifTag_t *primGifTag;
};
