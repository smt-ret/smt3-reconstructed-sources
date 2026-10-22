#pragma once
#include "types.h"

typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct titleGlobal titleGlobal;

struct titleGlobal {
    sdfMemHandle_t *mh;
    sdfTexHandle_t *LogoSpriteHandle;
    sdfTexHandle_t *TlogoSpriteHandle;
    sdfTexHandle_t *PressSpriteHandle;
    sdfTexHandle_t *Win1SpriteHandle;
    sdfTexHandle_t *Win1BSpriteHandle;
    s32 step;
    s32 pos;
    s32 cnt;
    s32 loopflg;
    s32 bgalp;
    s32 menucnt;
    s32 pressFadeinCnt;
    s32 LogoCnt;
    s32 ModePos;
    s32 MovieId;
};
