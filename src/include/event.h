#pragma once
#include "types.h"

typedef enum {
    BE_DATATYPE_NAME = 0,
    BE_DATATYPE_STAGE = 1,
    BE_DATATYPE_F1 = 2,
    BE_DATATYPE_F2 = 3,
    BE_DATATYPE_FTB = 4,
    BE_DATATYPE_PB = 5,
    BE_DATATYPE_MSE = 6,
    BE_DATATYPE_D3P = 7,
    BE_DATATYPE_BED = 8,
    BE_DATATYPE_TMX = 9,
    BE_DATATYPE_MAX = 10,
} BE_DATATYPE;

typedef enum {
    EVT_PACK_STAT_ERR = -1,
    EVT_PACK_STAT_NON = 0,
    EVT_PACK_STAT_LOAD = 1,
    EVT_PACK_STAT_OK = 2,
    EVT_PACK_STAT_END = 3,
} EVT_PACK_STAT;

typedef enum {
    EVT_VIEWER_MENU_NON = 0,
    EVT_VIEWER_MENU_MAIN = 1,
    EVT_VIEWER_MENU_SELECT = 2,
    EVT_VIEWER_MENU_FILENAME = 3,
    EVT_VIEWER_MENU_OBJLIST = 4,
    EVT_VIEWER_MENU_FRAMELIST = 5,
    EVT_VIEWER_MENU_FRAMECHANGE = 6,
    EVT_VIEWER_MENU_INTCHANGE = 7,
    EVT_VIEWER_MENU_FLOATCHANGE = 8,
    EVT_VIEWER_MENU_FILENAME2 = 9,
    EVT_VIEWER_MENU_BASICLIST = 10,
    EVT_VIEWER_MENU_DATA = 11,
    EVT_VIEWER_MENU_EVENTPOS = 12,
    EVT_VIEWER_MENU_MAX = 13,
} EVT_VIEWER_MENU;

typedef enum {
    MAIN_MENU_SAVEPROJ = 0,
    MAIN_MENU_LOADPROJ = 1,
    MAIN_MENU_LOADNEWPROJ = 2,
    MAIN_MENU_SETSTARTFRAME = 3,
    MAIN_MENU_SETENDFRAME = 4,
    MAIN_MENU_SETTOTALFRAME = 5,
    MAIN_MENU_CAPTURE = 6,
    MAIN_MENU_MAX = 7,
} MAIN_MENU;

typedef enum {
    FRAME_DELETE = -1,
    FRAME_START = 0,
    FRAME_LENGTH = 1,
    FRAME_RANGE = 2,
    FRAME_ALPHA = 3,
    FRAME_SCALE = 4,
    FRAME_HOKAN = 5,
    FRAME_FOVY = 6,
    FRAME_VOLUME = 7,
    FRAME_NO = 8,
    FRAME_END = 9,
    FRAME_LINK = 10,
    FRAME_SW = 11,
    FRAME_MODE = 12,
    FRAME_DATA = 13,
    FRAME_SOFTEN_BIAS = 14,
    FRAME_STOP = 15,
    FRAME_PRESET = 16,
    FRAME_MAX = 17,
} FRAME_NUM;

typedef enum {
    EVT_MOON_STAT_CALC = 1,
    EVT_MOON_STAT_DRAW = 2,
} EVT_MOON_STAT;

typedef enum {
    PMD_DATATYPE_CUTINFO = 0,
    PMD_DATATYPE_NAME = 1,
    PMD_DATATYPE_STAGE = 2,
    PMD_DATATYPE_UNIT = 3,
    PMD_DATATYPE_FRAME = 4,
    PMD_DATATYPE_CAMERA = 5,
    PMD_DATATYPE_MESSAGE = 6,
    PMD_DATATYPE_EFFECT = 7,
    PMD_DATATYPE_EFFECTDATA = 8,
    PMD_DATATYPE_UNITDATA = 9,
    PMD_DATATYPE_F1 = 10,
    PMD_DATATYPE_F2 = 11,
    PMD_DATATYPE_FTB = 12,
    PMD_DATATYPE_SLIGHT = 13,
    PMD_DATATYPE_SFOG = 14,
    PMD_DATATYPE_BLUR2 = 15,
    PMD_DATATYPE_MULTBLUR = 16,
    PMD_DATATYPE_DISTBLUR = 17,
    PMD_DATATYPE_FILTER = 18,
    PMD_DATATYPE_MULTFILTER = 19,
    PMD_DATATYPE_RIPBLUR = 20,
    PMD_DATATYPE_MAX = 21,
} PMD_DATATYPE;

typedef enum {
    PMD_OBJTYPE_STAGE = 0,
    PMD_OBJTYPE_UNIT = 1,
    PMD_OBJTYPE_CAMERA = 2,
    PMD_OBJTYPE_EFFECT = 3,
    PMD_OBJTYPE_MESSAGE = 4,
    PMD_OBJTYPE_SE = 5,
    PMD_OBJTYPE_FADE = 6,
    PMD_OBJTYPE_QUAKE = 7,
    PMD_OBJTYPE_BLUR = 8,
    PMD_OBJTYPE_LIGHT = 9,
    PMD_OBJTYPE_SLIGHT = 10,
    PMD_OBJTYPE_SFOG = 11,
    PMD_OBJTYPE_SKY = 12,
    PMD_OBJTYPE_BLUR2 = 13,
    PMD_OBJTYPE_MBLUR = 14,
    PMD_OBJTYPE_DBLUR = 15,
    PMD_OBJTYPE_FILTER = 16,
    PMD_OBJTYPE_MFILTER = 17,
    PMD_OBJTYPE_BED = 18,
    PMD_OBJTYPE_BGM = 19,
    PMD_OBJTYPE_MG1 = 20,
    PMD_OBJTYPE_MG2 = 21,
    PMD_OBJTYPE_FB = 22,
    PMD_OBJTYPE_RBLUR = 23,
    PMD_OBJTYPE_MAX = 24,
} PMD_OBJTYPE;

typedef enum {
    PMD_EFFTYPE_D3P = 0,
    PMD_EFFTYPE_BED = 1,
    PMD_EFFTYPE_MG1 = 2,
    PMD_EFFTYPE_MG2 = 3,
} PMD_EFFTYPE;

typedef enum {
    PMD_FADE_WHITE_IN = 0,
    PMD_FADE_WHITE_OUT = 1,
    PMD_FADE_BLACK_IN = 2,
    PMD_FADE_BLACK_OUT = 3,
} PMD_FADE;

typedef enum {
    PMD_BGM_TYPE_PLAY = 0,
    PMD_BGM_TYPE_FADEIN = 1,
    PMD_BGM_TYPE_FADEOUT = 2,
    PMD_BGM_TYPE_TRANS = 3,
    PMD_BGM_TYPE_VOLDOWN = 4,
    PMD_BGM_TYPE_VOLUP = 5,
    PMD_BGM_TYPE_ALLSTOP = 6,
} PMD_BGM;

typedef enum {
    PMD_UNIT_DISP_ON = 0,
    PMD_UNIT_DISP_OFF = 1,
    PMD_UNIT_SHADOW_OFF = 2,
    PMD_UNIT_MSHADOW_ON = 3,
    PMD_UNIT_VSHADOW_ON = 4,
} PMD_UNIT;

typedef enum {
    EVT_UNIT_STAT_WAIT = 0,
    EVT_UNIT_STAT_MOVE = 1,
    EVT_UNIT_STAT_MOTION = 2,
    EVT_UNIT_STAT_ROT = 3,
    EVT_UNIT_STAT_ACTION = 4,
} EVT_UNIT_STAT;

typedef enum {
    EVT_UNIT_TARGET_TYPE_POS = 0,
    EVT_UNIT_TARGET_TYPE_POINT = 1,
    EVT_UNIT_TARGET_TYPE_PATH = 2,
} EVT_UNIT_TARGET;

typedef enum {
    EVT_UNIT_MOVE_TYPE_0 = 0,
    EVT_UNIT_MOVE_TYPE_1 = 1,
    EVT_UNIT_MOVE_TYPE_FUNC = 2,
    EVT_UNIT_MOVE_TYPE_PATHTRACE = 3,
    EVT_UNIT_MOVE_TYPE_MAX = 4,
} EVT_UNIT_MOVE;

typedef enum {
    EVT_MOT_WAIT = 0,
    EVT_MOT_LOOP = 1,
    EVT_MOT_STOP = 2,
    EVT_MOT_AUTO = 3,
    EVT_MOT_SP = 4,
    EVT_MOT_MOUTHSET = 5,
    EVT_MOT_F_STOP = 12,
} EVT_MOT;

typedef struct beDataInfo_u beDataInfo_u;
typedef struct beHeader_s beHeader_s;
typedef struct beMotionSeTable_s beMotionSeTable_s;
typedef struct beNameTable_s beNameTable_s;
typedef struct beStageTable_s beStageTable_s;
typedef struct beTypeTable_s beTypeTable_s;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct dds3Effect_DistortionBlurParam_t dds3Effect_DistortionBlurParam_t;
typedef struct dds3Effect_Filter_t dds3Effect_Filter_t;
typedef struct dds3Effect_PartialMultiBlurParam_t dds3Effect_PartialMultiBlurParam_t;
typedef struct dds3Effect_PartialMultiFilterParam_t dds3Effect_PartialMultiFilterParam_t;
typedef struct dds3Effect_RippleBlurParam_t dds3Effect_RippleBlurParam_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3PathBasicControl_t dds3PathBasicControl_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtFrameInfo_t evtFrameInfo_t;
typedef struct evtFrameList_t evtFrameList_t;
typedef struct evtMoonProcessData_t evtMoonProcessData_t;
typedef struct evtMoon_t evtMoon_t;
typedef struct evtMotionSeData_t evtMotionSeData_t;
typedef struct evtPackProcessData_t evtPackProcessData_t;
typedef struct evtPicturePriTbl_t evtPicturePriTbl_t;
typedef struct evtPictureProcessData_t evtPictureProcessData_t;
typedef struct evtTexManager evtTexManager;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct evtUnitHandle_t_ActionDelegate evtUnitHandle_t_ActionDelegate;
typedef struct evtViewerInfo_t evtViewerInfo_t;
typedef struct evtViewerMenu_t evtViewerMenu_t;
typedef struct evtViewerMenu_t_menufuncDelegate evtViewerMenu_t_menufuncDelegate;
typedef struct evtViewerObject_s evtViewerObject_s;
typedef struct fileHandle_t fileHandle_t;
typedef struct menuinfo_t menuinfo_t;
typedef struct pmdCameraTable_t pmdCameraTable_t;
typedef struct pmdCutInfo_t pmdCutInfo_t;
typedef struct pmdDataInfo_t pmdDataInfo_t;
typedef struct pmdEffectTable_t pmdEffectTable_t;
typedef struct pmdFrameTable_t pmdFrameTable_t;
typedef struct pmdHeader_t pmdHeader_t;
typedef struct pmdNameTable_t pmdNameTable_t;
typedef struct pmdProcessWork_t pmdProcessWork_t;
typedef struct pmdSceneFogTable_t pmdSceneFogTable_t;
typedef struct pmdSceneLightTable_t pmdSceneLightTable_t;
typedef struct pmdStageTable_t pmdStageTable_t;
typedef struct pmdTypeTable_t pmdTypeTable_t;
typedef struct pmdUnitTable_t pmdUnitTable_t;
typedef struct sdf3DLightParallelPacket_t sdf3DLightParallelPacket_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct evtUnitHandle_t {
    u32 NowLightRGB;
    u32 BaseLightRGB;
    u32 TargetLightRGB;
    u32 WorkLightRGB;
    sdfVector4_t NowLightDir;
    sdfVector4_t BaseLightDir;
    sdfVector4_t TargetLightDir;
    sdfVector4_t WorkLightDir;
    u32 NowAmbientRGB;
    u32 BaseAmbientRGB;
    u32 TargetAmbientRGB;
    u32 WorkAmbientRGB;
    u32 BaseModelRGBA;
    u32 TargetModelRGBA;
    sdf3DLightParallelPacket_t *PrivateLightPacket;
    sdf3DLightParallelPacket_t *PublicLightPacket;
    sdfVector4_t PosTarget;
    dds3Basic_t *Owner;
    dds3Basic_t *BasicLight;
    dds3Basic_t *BasicLight2;
    dds3ModelHandle_t *Model;
    dds3Basic_t *MoveTarget;
    evtUnitHandle_t_ActionDelegate *Action;
    f32 Sin;
    dds3PathBasicControl_t *Path;
    f32 PathStep;
    u32 Flag;
    s16 Stat;
    s16 TargetType;
    s16 MoveType;
    s16 Frame;
    s16 MovePara1;
    s16 MovePara2;
    f32 WaitSpeed;
    s16 WaitMotion;
    s16 WaitBefore;
    s16 WaitSmooth;
    s16 NowMotion;
    s16 NowBefore;
    s16 NowSmooth;
    s16 MotEndFrame;
    s16 MoveTimer;
    s16 StopTimer;
    s8 KutiGroup;
    s8 KutiMotion;
    u8 ExFlags[12];
    s16 ExWaitMotion[12];
    s16 ExNowMotion[12];
    s16 ExBefore[12];
    s16 ExSmooth[12];
    u16 LightRGBAnimeFrame;
    u16 LightDirAnimeFrame;
    u16 ModelRGBAnimeFrame;
    u16 ModelRGBAnimeMaxFrame;
    u16 ModelAAnimeFrame;
    u16 ModelAAnimeMaxFrame;
    u16 BasicLightAnimeFrame;
    u16 BasicLightAnimeMaxFrame;
    void *modelobj;
    sdfVector3_t modelrot;
    void *modelanm;
    sdfVector3_t modelofs;
    s16 formindex;
    u8 e723sp;
    u8 modeflg;
    s16 modeframe;
    f32 soften;
    f32 bias;
};

struct evtMoon_t {
    s32 Stat;
    s32 Age;
    s32 TakaraCnt;
    s32 pub;
    f32 MoveCnt;
};

struct evtViewerInfo_t {
    sdfMemHandle_t *mem;
    u32 stat;
    pmdProcessWork_t *workdata;
    s32 totalframe;
    s32 firstframe;
    s32 lastframe;
    s32 nowframe;
    s32 oldframe;
    s32 nametablecnt;
    pmdNameTable_t *nametable[256];
    dds3Basic_t *activecamera;
    dds3Basic_t *freecamera;
    dds3Basic_t *gamecamera;
    s32 objcnt;
    evtViewerObject_s *firstobjinfo;
    evtViewerObject_s *lastobjinfo;
    dds3Basic_t *efftable[127];
    s32 framedisp;
    menuinfo_t *menustack[8];
    s32 sp;
    s32 nowmenu;
    s32 menusw;
    s32 fldfilter;
    dds3ProcessID_t *pid;
    s32 drawblur2;
    s32 drawmblur;
    s32 drawdblur;
    s32 drawfilter;
    s32 drawmfilter;
    s32 drawrblur;
    s32 mainmenu_y;
    s32 work_base;
    s32 work_x;
    s32 work_y;
    s32 eventpos_y;
    s32 select_y;
    s32 select_max;
    char *select_header;
    char *select_str;
    s32 filename_x;
    s32 filename_y;
    u16 filename[12];
    char *fileext;
    char *gamedata_filename;
    s32 objlist_y;
    s32 objlist_base;
    s32 framelist_x;
    s32 framelist_y;
    s32 framelist_base;
    evtViewerObject_s *framelist_target;
    s32 framelist_type;
    s32 value;
    s32 min;
    s32 max;
    f32 fvalue;
    f32 fmin;
    f32 fmax;
};

struct pmdDataInfo_t {
    s8 c0;
    s8 c1;
    s8 c2;
    s8 c3;
    s16 s0;
    s16 s1;
    s32 i;
    f32 f;
    intptr_t p;
};

struct evtViewerObject_s {
    s32 type;
    s32 nameindex;
    s32 fileindex;
    dds3Basic_t *basic;
    pmdDataInfo_t data;
    void *p;
    s32 framecnt;
    evtFrameInfo_t *firstframeinfo;
    evtFrameInfo_t *lastframeinfo;
    evtViewerObject_s *next;
    evtViewerObject_s *prev;
};

struct pmdSceneLightTable_t {
    sdfVector4_t Color;
    sdfVector4_t Dir;
    sdfVector4_t Ambient;
};

struct pmdSceneFogTable_t {
    f32 Min;
    f32 Max;
    f32 Near;
    f32 Far;
    u32 Color;
    s32 Reserve1;
    s32 Reserve2;
    s32 Reserve3;
};

struct pmdProcessWork_t {
    u32 flag;
    char *filename1;
    s32 CameraFirst;
    pmdHeader_t *Header1;
    pmdTypeTable_t *TypeTable1;
    pmdNameTable_t *NameTable1;
    s32 NameCount1;
    pmdStageTable_t *StageTable;
    s32 StageCount;
    u8 *StageF1;
    u8 *StageF2;
    u8 *StageTB;
    pmdUnitTable_t *UnitTable;
    s32 UnitCount;
    u8 *UnitData;
    pmdEffectTable_t *EffectTable;
    s32 EffectCount;
    void *EffectData;
    dds3Basic_t *obj_data;
    fileHandle_t *FileHandle2;
    sdfMemHandle_t *MemHandle2;
    u8 *pm2;
    char *fkey;
    pmdHeader_t *Header2;
    pmdTypeTable_t *TypeTable2;
    pmdNameTable_t *NameTable2;
    s32 NameCount2;
    pmdCutInfo_t *CutInfo;
    pmdFrameTable_t *FrameTable;
    s32 FrameCount;
    pmdCameraTable_t *CameraTable;
    s32 CameraCount;
    pmdSceneLightTable_t *SLightTable;
    s32 SLightCount;
    pmdSceneFogTable_t *SFogTable;
    s32 SFogCount;
    dds3Effect_Blur_t *Blur2Table;
    s32 Blur2Count;
    dds3Effect_PartialMultiBlurParam_t *MBlurTable;
    s32 MBlurCount;
    dds3Effect_DistortionBlurParam_t *DBlurTable;
    s32 DBlurCount;
    dds3Effect_Filter_t *FilterTable;
    s32 FilterCount;
    dds3Effect_PartialMultiFilterParam_t *MFilterTable;
    s32 MFilterCount;
    dds3Effect_RippleBlurParam_t *RBlurTable;
    s32 RBlurCount;
    s32 MesHandle;
    dds3ProcessID_t *ProcessID;
    s32 EventNo;
    s32 CutNo;
    s32 NowFrame;
    f32 NowFrameF;
    dds3Basic_t *EffectBasicTable;
    void *hide_ypos;
    evtTexManager *TexMngr;
    void *ChrObj;
    void *ChrList;
    void *AnmList;
    void *FldObj;
    void *FldList;
    void *anim_list;
};

struct evtFrameInfo_t {
    u16 frame;
    u16 length;
    s32 nameindex;
    pmdDataInfo_t *data[2];
    pmdDataInfo_t work;
    void *p;
    evtFrameInfo_t *next;
    evtFrameInfo_t *prev;
};

struct pmdHeader_t {
    s8 FileType;
    s8 FileFormat;
    s16 UserID;
    s32 FileSize;
    u8 MagicCode[4];
    s32 ExpandSize;
    s32 TypeTableCount;
    s32 Version;
    s32 Reserve2;
    s32 Reserve3;
};

struct pmdStageTable_t {
    s32 NameIndex;
    s32 FileIndex;
    s32 MajorNum;
    s32 MinorNum;
};

struct pmdCutInfo_t {
    s32 FirstFrame;
    s32 LastFrame;
    s32 TotalFrame;
    s32 Reserve1;
};

struct pmdNameTable_t {
    char *Name;
};

struct menuinfo_t {
    u16 menu;
    u16 x;
    u16 y;
    u16 reserve1;
};

struct pmdTypeTable_t {
    s32 Type;
    s32 ItemSize;
    s32 ItemCount;
    s32 ItemAddress;
};

struct pmdUnitTable_t {
    s32 NameIndex;
    s32 FileIndex;
    s32 MajorNum;
    s32 MinorNum;
    s32 DataOffset;
    s32 DataSize;
    s32 Reserve1;
    s32 Reserve2;
};

struct pmdEffectTable_t {
    s32 NameIndex;
    s32 DataOffset;
    s32 Type;
    s32 Reserve2;
};

struct pmdFrameTable_t {
    u16 ObjectType;
    u16 Frame;
    u16 Length;
    s16 NameIndex;
    pmdDataInfo_t *Data[2];
};

struct pmdCameraTable_t {
    s32 NameIndex;
    s32 Reserve1;
    s32 Reserve2;
    s32 Reserve3;
};

struct evtFrameList_t {
    s16 cnt;
    s8 list[8];
};

struct evtViewerMenu_t {
    evtViewerMenu_t_menufuncDelegate *menufunc;
};

struct beDataInfo_u {
    s8 c[4];
    s16 s[2];
    s32 i;
    f32 f;
    intptr_t p;
};

struct beHeader_s {
    u8 FileType;
    u8 FileFormat;
    u16 UserID;
    s32 FileSize;
    u16 *MagicCode;
    s32 ExpandSize;
    s32 TypeTableCount;
    s32 Version;
    s32 Reserve2;
    s32 Reserve3;
};

struct beTypeTable_s {
    s32 Type;
    s32 ItemSize;
    s32 ItemCount;
    s32 ItemAddress;
    s32 ID;
    s32 LinkID;
    s32 NameIndex;
    s32 UserData;
};

struct beNameTable_s {
    u16 Name[32];
};

struct beStageTable_s {
    s32 MajorNum;
    s32 MinorNum;
    s32 Reserve1;
    s32 Reserve2;
};

struct beMotionSeTable_s {
    s32 Frame;
    s32 Se;
    s32 Reserve1;
    s32 Reserve2;
};

struct evtMotionSeData_t {
    s32 unitid;
    s32 eventno;
    s32 rid;
    s32 OldFrame;
    u8 **bPlayed;
};

struct evtPackProcessData_t {
    s32 eventno;
    s32 stat;
    bool assetbundle;
    fileHandle_t *be_f;
    u8 *addr;
    beHeader_s header;
    beTypeTable_s *typetable;
    beNameTable_s *nametable;
    s32 f1_size;
    u8 *f1_m;
    void *f1_p;
    s32 f2_size;
    u8 *f2_m;
    void *f2_p;
    void *distblurtex;
    sdfTexHandle_t *multblurtex;
    sdfTexHandle_t *ripblurtex;
    sdfTexHandle_t *multfiltertex;
    evtTexManager *e9xxxTexManager;
};

struct evtMoonProcessData_t {
    sdfTexHandle_t *MoonTmx1;
    sdfTexHandle_t *MoonTmx2;
    sdfTexHandle_t *MoonTmx3;
    sdfTexHandle_t *MoonTmx4;
    sdfTexHandle_t *MoonTmx5;
    sdfTexHandle_t *MoonTmx6;
};

struct evtPictureProcessData_t {
    u32 flag;
    sdfTexHandle_t *tex;
    s32 ot;
    s32 x;
    s32 y;
    s32 alpha;
    f32 zoom;
    s32 size_sw;
    s32 size_sh;
    s32 size_tw;
    s32 size_th;
    s32 pri;
    s32 pos_x0;
    s32 pos_y0;
    s32 pos_x1;
    s32 pos_y1;
    s32 pos_time;
    s32 pos_cnt;
    s32 alp_a0;
    s32 alp_a1;
    s32 alp_time;
    s32 alp_cnt;
    s32 zoom_p0;
    s32 zoom_p1;
    s32 zoom_time;
    s32 zoom_cnt;
    void *pic;
    bool sp;
};

struct evtPicturePriTbl_t {
    sdfTexHandle_t *tex;
    s32 ot;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 zoom;
    s32 u0;
    s32 v0;
    s32 u1;
    s32 v1;
    s32 alpha;
    s32 pri;
    void *obj;
    bool sp;
};
