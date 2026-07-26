#pragma once
#include "types.h"

typedef struct fileCb_t fileCb_t;
typedef struct fileEndCallback_t fileEndCallback_t;
typedef struct pacFileCb_t pacFileCb_t;
typedef struct pacFileEndCallback_t pacFileEndCallback_t;
typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfPacDecodeCb_t sdfPacDecodeCb_t;

struct pacFileCb_t {
    fileCb_t *_base;
    sdfPacDecodeCb_t *decodeCb;
    u16 decodeEnd;
    u16 readIndex;
    pacFileCb_t *endCallbackLink;
};

struct fileCb_t {
    u8 type;
    u8 phase;
    u8 allocRetry;
    u8 allocHeadOrTail;
    fileCb_t *next;
    char *filename;
    sdfFileCmdHandle_t *fileHandle;
    s32 loadRemain;
    s32 size;
    fileEndCallback_t *fendCallback;
    pacFileEndCallback_t *pendCallback;
    void *endCallbackParm;
    sdfMemHandle_t *memHandle;
    void *topPtr;
    u8 loadPtr;
    fileCb_t *callbackNext;
};
