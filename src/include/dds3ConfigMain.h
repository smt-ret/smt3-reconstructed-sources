#pragma once
#include "types.h"

typedef enum {
    CFG_PROC_MODE_CAMP = 0,
    CFG_PROC_MODE_TITLE = 1,
} CFG_PROC_MODE;

typedef enum {
    BGM_VOL = 0,
    SE_VOL = 1,
    VOICE_VOL = 2,
    MOVIE_VOL = 3,
    VOICE_TYPE = 4,
    SOUND_TYPE = 5,
    VERTICAL_REVERSE = 6,
    HORIZONTAL_REVERSE = 7,
    BRIGHT = 8,
    GAME_LEVEL = 9,
    VIBRATION = 10,
    CURSOR = 11,
    AUTO = 12,
    RETURN = 13,
    MAX = 14,
} CFG_TYPE;

typedef enum {
    CFG_TYPE_SOUND = 15,
} CFG_TYPE2;

typedef enum {
    CFG_CURSOR_NONE = 0,
    CFG_CURSOR_ACTIVE = 1,
    CFG_CURSOR_MAX = 2,
} CFG_CURSOR;

typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpSeqInfo_s cmpSeqInfo_t;
typedef struct dds3ConfigGBWK_t dds3ConfigGBWK_t;
typedef struct fclPanelMover_t fclPanelMover_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct dds3ConfigGBWK_t {
    cmpSeqInfo_t *SeqInfo;
    sdfMemHandle_t *MH;
    u8 ProcMode;
    u8 BgFlag;
    cmpCursorInfo_t *CursorInfo;
    fclPanelMover_t *PanelMover[2];
    s32 BaseTimer;
    sdfTexHandle_t *BG;
};
