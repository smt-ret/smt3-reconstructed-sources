#pragma once
#include "types.h"

typedef struct _FRQ _FRQ;
typedef struct frMsgInfo_t frMsgInfo_t;

struct frMsgInfo_t {
    s32 X;
    s32 Y;
    u32 Z;
    u8 Style;
    u8 ColNo;
    u8 Tp;
    u8 Spd;
    u8 *pMsg;
    _FRQ *pFRQ;
    s32 Ofs;
    s8 FrqFlag;
    s8 RetFlag;
    char *talk_tag;
};
