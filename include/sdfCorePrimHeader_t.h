#pragma once
#include "types.h"

typedef struct sdfCorePrimHeader_t sdfCorePrimHeader_t;

struct sdfCorePrimHeader_t {
    u16 faceCount;
    u16 pointCount;
    u16 attrBits;
    u16 packetBits;
};
