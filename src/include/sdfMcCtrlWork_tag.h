#pragma once
#include "types.h"

typedef struct sdfMcCb_tag sdfMcCb_tag;
typedef struct sdfMcCtrlWork_tag sdfMcCtrlWork_tag;

struct sdfMcCtrlWork_tag {
    s8 cmdDoing;
    sdfMcCb_tag *cmdDoingCb;
    sdfMcCb_tag *cbLink;
    s16 getDirFileNum;
    s16 getDirBaseLeng;
    s32 getDirFd;
};
