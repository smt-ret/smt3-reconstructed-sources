#pragma once
#include "types.h"

typedef struct pb_debug_tag pb_debug_tag;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct pb_debug_tag {
    sdfMemHandle_t *memhandle;
    s16 phase;
    s16 menu_cursor;
    s16 systemfileNum;
    s16 d_level;
    s16 d_stage;
    u16 reserved;
    s32 top;
    s32 offset;
};
