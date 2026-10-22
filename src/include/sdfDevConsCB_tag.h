#pragma once
#include "types.h"

typedef struct sdfDevConsCB_tag sdfDevConsCB_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct sdfDevConsCB_tag {
    sdfDevConsCB_tag *prev;
    sdfDevConsCB_tag *next;
    u16 x;
    u16 y;
    s16 w;
    s16 h;
    s16 locX;
    s16 locY;
    u8 mode;
    u8 pad;
    u8 attr;
    u8 tabwidth;
    sdfMemHandle_t *bufferHandle;
    u8 *bufferPtr;
};
