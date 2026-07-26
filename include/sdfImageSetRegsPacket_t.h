#pragma once
#include "types.h"

typedef struct sdfImageSetRegsPacket_t sdfImageSetRegsPacket_t;

struct sdfImageSetRegsPacket_t {
    u64 dmaTag;
    u64 dmaOpt;
    u64 gifTag;
    u64 gifReg;
    u64 bitbltbufDat;
    u64 bitbltbufReg;
    u64 trxposDat;
    u64 trxposReg;
    u64 trxregDat;
    u64 trxregReg;
    u64 trxdirDat;
    u64 trxdirReg;
};
