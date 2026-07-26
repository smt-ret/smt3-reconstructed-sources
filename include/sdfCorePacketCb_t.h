#pragma once
#include "types.h"

typedef struct sdfCorePacketCb_t sdfCorePacketCb_t;
typedef struct sdfCorePacketPointBuff_tag sdfCorePacketPointBuff_tag;
typedef struct sdfMatPacket_t sdfMatPacket_t;

struct sdfCorePacketCb_t {
    sdfMatrix4_t *tmSave;
    s16 faceCount;
    s16 pointCount;
    s32 attrBits;
    s32 packetBits;
    s32 orgAttrBits;
    s16 drawFaceCount;
    s16 backfaceCount;
    sdfMatPacket_t *matPacketPtr;
    u32 color;
    f32 fdSoften;
    f32 fdBias;
    sdfCorePacketPointBuff_tag *pointBuff;
    sdfCorePacketPointBuff_tag *freePointBuff;
    sdfCorePacketPointBuff_tag *extPointBuff;
    s32 freePointCount;
    s32 extPointCount;
    sdfCorePacketPointBuff_tag *extPointTop;
    sdfCorePacketPointBuff_tag extPointLink[UNKNOWN_ARRAY_SIZE];
    void *packetOpenPtr;
    void *packetTopPtr;
    void *packetStartPtr;
    void *packetPtr;
    void *dataPtr;
    u16 facePtr;
    f32 vertexPtr;
    f32 normalPtr;
    f32 uvPtr;
    f32 uv2Ptr;
    u32 vertColPtr;
    f32 backfaceSign;
};
