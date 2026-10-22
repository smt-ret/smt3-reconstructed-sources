#pragma once
#include "types.h"

typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfShapeFacePacketIF_t sdfShapeFacePacketIF_t;

struct sdfShapeFacePacketIF_t {
    s32 index[48];
    s32 indexCount;
    s32 localFaceCount;
    s32 packetPtr;
    s32 packetSize;
    s32 faceNum;
    sdfMemHandle_t *packetHandle;
    void *packetTop;
    s32 vpuMemOffset;
    u16 attrBits;
    u16 packetBits;
};
