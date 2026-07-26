#pragma once
#include "types.h"

typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct stfGlobal stfGlobal;

struct stfGlobal {
    sdfMemHandle_t *mh;
    sdfTexHandle_t *LineSpriteHandle;
    sdfTexHandle_t *MaskSpriteHandle;
    sdfTexHandle_t *PicSpriteHandle;
    sdfTexHandle_t *CapcomSpriteHandle;
    sdfMemHandle_t hFileLine[UNKNOWN_ARRAY_SIZE];
    void pFileLine[UNKNOWN_ARRAY_SIZE];
    sdfMemHandle_t hFileMask[UNKNOWN_ARRAY_SIZE];
    void pFileMask[UNKNOWN_ARRAY_SIZE];
    sdfMemHandle_t hFilePic[UNKNOWN_ARRAY_SIZE];
    void pFilePic[UNKNOWN_ARRAY_SIZE];
    sdfMemHandle_t *hFileFont1;
    void *pFileFont1;
    sdfMemHandle_t *hFileFont2;
    void *pFileFont2;
    sdfMemHandle_t *hFileCapcom;
    void *pFileCapcom;
    s32 step;
    s32 pos;
    s32 cnt;
    s32 max;
    f32 roll;
    f32 speed;
    s32 ImgNo;
    s32 ImgCnt;
    s32 ImgAlpCnt;
    s32 ImgLife;
    s32 ImgDir;
    s32 ImgDrawCount;
    s32 FadeOutImgAlphaCnt;
    s32 ImageDrawing;
};
