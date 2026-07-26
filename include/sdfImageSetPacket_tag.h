#pragma once
#include "types.h"

typedef struct sdfImageSetDataPacket_t sdfImageSetDataPacket_t;
typedef struct sdfImageSetPacket_tag sdfImageSetPacket_tag;
typedef struct sdfImageSetRegsPacket_t sdfImageSetRegsPacket_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct sdfImageSetPacket_tag {
    sdfImageSetPacket_tag *next;
    void *data;
    sdfMemHandle_t *dataMemHandle;
    u8 dataMemMode;
    u8 pad[3];
    sdfImageSetRegsPacket_t *regsPacket;
    sdfImageSetDataPacket_t *dataPacket[1];
};
