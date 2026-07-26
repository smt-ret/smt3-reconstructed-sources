#pragma once
#include "types.h"

typedef struct sdfMcCb_tag sdfMcCb_tag;
typedef struct sdfMcCb_tag_funcDelegate sdfMcCb_tag_funcDelegate;

struct sdfMcCb_tag {
    sdfMcCb_tag *next;
    sdfMcCb_tag_funcDelegate *func;
    u8 mediaType;
    u8 port;
    u8 slot;
    u8 timer;
    s32 type;
    s32 free;
    s32 format;
    u8 fileInfoCount;
    u8 fileInfoReady;
    u8 cardStat;
    u8 unformatRetry;
    u8 cmdDoing;
    u8 req;
    u8 reqResult;
    u8 reqCmd;
    s32 cmdFd;
    void *cmdBuff;
    s32 cmdSize;
    char *filename;
};
