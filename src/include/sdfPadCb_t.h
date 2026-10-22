#pragma once
#include "types.h"

typedef struct sdfPadCb_t sdfPadCb_t;

struct sdfPadCb_t {
    u8 port;
    u8 slot;
    u8 stat;
    u8 padding;
    u8 mode;
    u8 reqMode;
    u16 padData;
    u16 lastPadData;
    u32 repeatLapse;
    u8 *analog[2];
    u8 press[12];
    s16 actData[2];
    s16 actDataBack[2];
};
