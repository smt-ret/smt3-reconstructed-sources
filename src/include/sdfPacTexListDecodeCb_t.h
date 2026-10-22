#pragma once
#include "types.h"

typedef struct sdfPacStdBlockHeader_t sdfPacStdBlockHeader_t;
typedef struct sdfPacTexListDecodeCb_t sdfPacTexListDecodeCb_t;
typedef struct sdfPacTmxDecodeCb_t sdfPacTmxDecodeCb_t;

struct sdfPacTexListDecodeCb_t {
    u32 count;
    u32 currNum;
    s32 pad[2];
    sdfPacStdBlockHeader_t *currHeader;
    sdfPacTmxDecodeCb_t *tmxCb;
};
