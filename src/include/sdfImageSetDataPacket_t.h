#pragma once
#include "types.h"

typedef struct sdfImageSetDataPacket_t sdfImageSetDataPacket_t;

struct sdfImageSetDataPacket_t {
    u64 dmaTag;
    u64 dmaOpt;
    u64 gifTag;
    u64 gifReg;
    u64 dataDmaTag;
    u64 dataDmaOpt;
};
