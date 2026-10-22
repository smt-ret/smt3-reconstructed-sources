#pragma once
#include "types.h"

typedef struct _FRQ _FRQ;
typedef struct itfMesBinMesHeader_t itfMesBinMesHeader_t;
typedef struct message_tag message_tag;
typedef struct sdfIVector2_t sdfIVector2_t;

struct message_tag {
    sdfIVector2_t *pos;
    itfMesBinMesHeader_t *pbinheader;
    _FRQ *pfont;
    s8 phase;
    u8 wait;
    u8 last_style;
    u8 last_col;
    u8 last_tp;
    u8 last_spd;
    s16 lines;
    s16 page;
    s16 maxpage;
    char *tag_id;
    char *text;
    s32 callmode;
};
