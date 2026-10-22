#pragma once
#include "types.h"

#define PB_BLOCK_GRP_MAX 64
#define PB_KEYACT_MAX 5
#define PB_PANEL_COLR 32
#define PB_PANEL_COLG 32
#define PB_PANEL_COLB 32
#define PB_PANEL_COLA 80
#define PB_FNT_DEFZ 16711682
#define PB_CSR_DEFZ 16711681
#define PB_SPR_DEFZ 16711680
#define COL_WHITE 0
#define COL_BLUE 1
#define COL_RED 2
#define COL_GREEN 4
#define COL_YELLOW 6
#define COL_GRAY 8
#define PB_BGM_EDIT 4
#define PB_BGM_GAME 3407872
#define PB_MODEL_SCALE 1053609165
#define PB_PCHAR_MAX 4
#define PB_BLOCK_LENGTH 40
#define PB_BLOCK_LENGTH_H 20
#define PB_MAPBLK_OFS_X -380
#define PB_MAPBLK_OFS_Y -380
#define PB_BLK_FLOR_COL -2141167520
#define PB_BLK_WALL_COL -2141167520
#define PB_BLK_MCORE_COL -2144325584
#define PB_BLK_MOVE_COL -2144325584
#define PB_BLK_RCORE_COL -2141167520
#define PB_BLK_CORE_COL -2141167520
#define PB_BLK_EXIT_COL -2139062272
#define PB_OL_MOVE_COL -2133798704
#define PB_OL_RND_COL -2133798704
#define PB_MAP_X 20
#define PB_MAP_Y 20
#define PB_SYSTEM_DATAFILE_PATH1 "/pb/mapdata/data/pb1/"
#define PB_SYSTEM_DATAFILE_PATH2 "/pb/mapdata/data/pb2/"
#define PB_MAP_GRPID_MASK 8191
#define PB_MAP_HALL 2048
#define PB_MAP_GOAL 4096
#define PB_MAP_BLK_MASK 7
#define UseMultTap 0
#define PB_MCRD_TITLE "BISLPS-12345"
#define PB_MCRD_FILE "map_"
#define PB_MCRD_FORMAT 0
#define PB_MCRD_UNFORMAT 0
#define PB_MCRD_STAT_NOCARD -10
#define PB_MCRD_ENTMAX 18
#define PB_GET_DIRECTORY_CLUSTER 2

typedef enum {
    PB_BLKTYP_FLOR = 0,
    PB_BLKTYP_WALL = 1,
    PB_BLKTYP_MCORE = 2,
    PB_BLKTYP_NRML = 3,
    PB_BLKTYP_RCODE = 4,
    PB_BLKTYP_RND = 5,
    PB_BLKTYP_EXIT = 6,
} PB_BLKTYP;

typedef enum {
    PB_ERR_ = 0,
    PB_ERR_NOPS2_MC = 1,
    PB_ERR_NOAREA_MC = 2,
    PB_ERR_UNFORM_MC = 3,
    PB_ERR_CLEAR = 4,
    PB_ERR_LOAD = 5,
    PB_ERR_SAVE = 6,
    PB_ERR_NOTPBDIR_MC = 7,
    PB_ERR_NOFIND_MC = 8,
    PB_ERR_UNDO = 9,
} PB_ERR;

typedef enum {
    PB_U = 0,
    PB_R = 1,
    PB_D = 2,
    PB_L = 3,
    PB_DROP = 4,
} PB;

typedef enum {
    PB_RND_L = -1,
    PB_RND_R = 1,
} PB_RND;

typedef enum {
    PB_MAP_FLOR = 0,
    PB_MAP_WALL = 1,
    PB_MAP_MCORE = 2,
    PB_MAP_MOVE = 3,
    PB_MAP_RCORE = 4,
    PB_MAP_RND = 5,
} PB_MAP;

typedef enum {
    PB_MESS_RUN = 0,
    PB_MESS_REDRAW = 1,
    PB_MESS_NEXT = 2,
    PB_MESS_PREV = 3,
    PB_MESS_GOTO_ID = 4,
    PB_MESS_EXIT = 5,
    PB_MESS_EXIT_MAIN = 6,
} PB_MESS;

typedef enum {
    PB_PROC_EDIT = 0,
    PB_PROC_GAME = 1,
    PB_PROC_HELP = 2,
} PB_PRCC;

typedef enum {
    PB_MODE_EDIT = 0,
    PB_MODE_GAME = 1,
} PB_MODE;

typedef enum {
    PB_MENU_ROOT = 0,
    PB_MENU_FILE = 1,
    PB_MENU_CAMERA = 2,
    PB_MENU_DATA = 3,
    PB_MENU_MC_SLOT = 4,
    PB_MENU_MC_FILE = 5,
} pbMenu_AnonymousEnum;

typedef enum {
    PB_MOTION_STAY = 0,
    PB_MOTION_READY = 0,
    PB_MOTION_WALK = 1,
    PB_MOTION_PUSH = 2,
} PB_MOTION;

typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbBackup_t pbBackup_t;
typedef struct pbBlockDataBase_t pbBlockDataBase_t;
typedef struct pbBlockData_t pbBlockData_t;
typedef struct pbGroupData_t pbGroupData_t;
typedef struct pbLevelTable_t pbLevelTable_t;
typedef struct pbMCardStat_t pbMCardStat_t;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct pbWork_t pbWork_t;
typedef struct pb_Define pb_Define;
typedef struct pb_MCARD_sceMcTblGetDir pb_MCARD_sceMcTblGetDir;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfMemHandle_t sdfMemHandle_tag;

struct pbProcHandle_t {
    dds3ProcessID_t *id;
    s32 mes;
    u16 x;
    u16 y;
    void *data;
};

struct pbGroupData_t {
    s32 flag;
    s16 grpID;
    s16 num;
    pbBlockData_t *core;
    sdfMemHandle_tag *hblk;
    pbBlockData_t *blk;
    sdfVector4_t angle;
    sdfVector4_t trans;
    u32 outline_c[8];
};

struct pbBlockData_t {
    s16 type;
    s16 x;
    s16 y;
    s16 outline_num;
    sdfVector4_t outline_v[8];
};

struct pbLevelTable_t {
    s16 stage;
    s16 label;
};

struct pb_Define {
    s32 pbGeneral_h_;
};

struct pbBlockDataBase_t {
    s32 grp_num;
    pbGroupData_t *grp[64];
    sdfMat_t *mat;
};

struct pbWork_t {
    pbBackup_t *bup;
    u32 camera_mode;
    void *blockTex;
    void *bgTex;
    void *etcTex;
    void *helpTex;
    sdfMemHandle_t *mhscript;
    u16 level;
    u16 stage;
    u8 debug_flag;
    u8 reserved0;
    u16 reserved1;
    u32 debug;
    pbProcHandle_t *menu_proc;
    pbProcHandle_t *help_proc;
    u8 *pscript;
};

struct pbBackup_t {
    u32 pchar_num;
    u8 pchar_reg[4];
    u16 *pchar_pos;
    u16 exit_pos[2];
    u16 *mapdata;
};

struct pbMCardStat_t {
    s32 format;
    s32 type;
    s32 free;
    s32 stat;
};

struct pb_MCARD_sceMcTblGetDir {
    pb_MCARD_sceMcTblGetDir *mcDirEnt_t;
};

extern pbWork_t *pbWk;
