#pragma once
#include "types.h"

typedef struct sdfCorePacketHeader_t sdfCorePacketHeader_t;
typedef struct sdfCorePrimHeader_t sdfCorePrimHeader_t;

struct sdfCorePacketHeader_t {
    u8 packetType;
    u8 mpgType;
    s16 priority;
    u16 size;
    u16 matIndex;
    u32 extData[2];
    sdfCorePrimHeader_t *primHeader;
};
