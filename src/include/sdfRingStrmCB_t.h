#pragma once
#include "types.h"

typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfRingStrmCB_t sdfRingStrmCB_t;
typedef struct sdfRingStrmCB_t_callbackDelegate sdfRingStrmCB_t_callbackDelegate;

struct sdfRingStrmCB_t {
    u8 stat;
    u8 readStat;
    u16 numOfBlock;
    u16 blockHead;
    u16 blockTail;
    u16 blockActive;
    u16 blockLock;
    u32 blockSize;
    u32 lockLeng;
    sdfMemHandle_t *buffMemHandle;
    u8 buffTop;
    s32 activeLeng;
    sdfFileCmdHandle_t *fileHandle;
    s32 readSize;
    s32 readProgress;
    s32 dataPos;
    sdfRingStrmCB_t_callbackDelegate *callback;
    void *callbackParam;
};
