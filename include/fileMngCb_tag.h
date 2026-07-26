#pragma once
#include "types.h"

typedef struct fileCb_t fileCb_t;
typedef struct fileMngCb_tag fileMngCb_tag;
typedef struct pacBlockData_t pacBlockData_t;
typedef struct pacFileCb_t pacFileCb_t;

struct fileMngCb_tag {
    s32 semaId;
    u8 index;
    u8 readIndex;
    u8 activeCount;
    u8 freeCount;
    fileCb_t *queue;
    fileCb_t *queueTail;
    fileCb_t *endCallbackLink;
    pacFileCb_t *pacEndCallbackLink;
    fileCb_t *closeLink;
    u8 buffer;
    pacBlockData_t *data[4];
};
