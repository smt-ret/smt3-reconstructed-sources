#pragma once
#include "types.h"

typedef struct GameFileInfo_t GameFileInfo_t;
typedef struct mselGlobal mselGlobal;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct mselGlobal {
    sdfMemHandle_t *mh;
    sdfMemHandle_t *mh_gbwk;
    sdfMemHandle_t *mh_zen;
    GameFileInfo_t *GameFileInfo;
    sdfTexHandle_t *BgSpriteHandle;
    sdfTexHandle_t *AttSpriteHandle;
    sdfTexHandle_t *SelSpriteHandle;
    s32 step;
    s32 cnt;
    s32 ModePos;
    sdfMemHandle_t *MessageMH;
    void *pMessage;
    s32 ZensyoNum;
    s32 ZensyoSelect[5];
    u8 Zalpha_cnt;
    u32 Z_RGBA;
    u32 ZNalpha_cnt;
    u32 ZN_RGBA;
    u8 ZBalpha_cnt;
    u32 ZB_RGBA;
    s32 ZBNum;
    s32 ZBSelect[5];
    s32 mode;
    u32 cur_alpha;
    u32 cur_alphacnt;
};
