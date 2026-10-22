#pragma once
#include "types.h"

typedef struct sdfShapeClass sdfShapeClass;

struct sdfShapeClass {
    u16 numOfPacket;
    u16 priority;
    void *packetStart;
    s32 pad[2];
    u8 packetType;
    u8 mpgType;
    u16 packetPrio;
    u16 packetSize;
    u16 matIndex;
    void *dataBody;
    s32 pad2[1];
};
