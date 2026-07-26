#pragma once
#include "types.h"

typedef struct sdfImageSetCb_t sdfImageSetCb_t;
typedef struct sdfImageSetPacket_tag sdfImageSetPacket_tag;

struct sdfImageSetCb_t {
    s32 semaId;
    sdfImageSetPacket_tag *packetHead;
    sdfImageSetPacket_tag *packetTail;
    void *tagHead;
    void *tagTail;
};
