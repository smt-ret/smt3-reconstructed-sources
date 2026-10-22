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
    sdfMemHandle_t *hFileLine;
    void *pFileLine;
    sdfMemHandle_t *hFileMask;
    void *pFileMask;
    sdfMemHandle_t *hFilePic;
    void *pFilePic;
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
