#pragma once
#include "types.h"

typedef enum {
    AM_MK_PLAYER = 0,
    AM_MK_CAMERA = 1,
    AM_MK_EXIT = 2,
    AM_MK_GATTAI = 3,
    AM_MK_KAIFUKU = 4,
    AM_MK_SAVE = 5,
    AM_MK_SHOP = 6,
    AM_MK_RAG = 7,
    AM_MK_L1 = 8,
    AM_MK_R1 = 9,
    AM_MK_EL = 10,
    AM_MK_UP = 11,
    AM_MK_DOWN = 12,
    AM_MK_NPC = 13,
    AM_MK_SPC = 14,
    AM_MK_ANA = 15,
} AM_MK;

typedef enum {
    FLD_RES_PORTAL = 0,
    FLD_RES_BLOCK_RANGE = 1,
    FLD_RES_DRAW_OBJ = 2,
    FLD_RES_COL_OBJ = 3,
    FLD_RES_CAMERA = 4,
    FLD_RES_TEXLIST = 5,
    FLD_RES_EVENT = 6,
    FLD_RES_RENGE = 7,
    FLD_RES_MATERIAL = 8,
    FLD_RES_MOTION = 9,
    FLD_RES_POSITION = 10,
    FLD_RES_EFFECT = 11,
    FLD_RES_LIGHT = 12,
} FLD_RES;

typedef enum {
    FLD_OBJBLOCK_MOVE_D_AND_R_TYPE = 0,
    FLD_OBJBLOCK_NO_MOVE_D_AND_R_OBJ_TYPE = 1,
    FLD_OBJBLOCK_EVENT_TYPE = 2,
    FLD_OBJBLOCK_CAMERA_TYPE = 3,
    FLD_OBJBLOCK_EFFECT_TYPE = 4,
} FLD_OBJBLOCK;

typedef enum {
    FLD_EFFECTTYPE_BILLBOARD = 0,
    FLD_EFFECTTYPE_D3P = 1,
} FLD_EFFECTTYPE;

typedef enum {
    FLD_MOTION_TYPE_TRANS = 0,
    FLD_MOTION_TYPE_ROT = 1,
    FLD_MOTION_TYPE_ROT_QTN = 2,
    FLD_MOTION_TYPE_SCALE = 3,
    FLD_MOTION_TYPE_CAMERA = 4,
    FLD_MOTION_TYPE_EVENT_LIGHT = 5,
    FLD_MOTION_TYPE_NO_USE = -1,
} FLD_MOTION_TYPE;

typedef enum {
    FLD_TEX_TYPE_STRING = 0,
    FLD_TEX_TYPE_MEMORYIMAGE = 1,
} FLD_TEX_TYPE;

typedef enum {
    FLD_HIT_POLYGON_TYPE = 0,
    FLD_HIT_SPHERE_TYPE = 1,
    FLD_HIT_BOX_TYPE = 2,
} FLD_HIT;

typedef enum {
    FLD_HAITI_TYPE_PUB_VERTEX = 0,
    FLD_HAITI_TYPE_EVENTHIT = 1,
    FLD_HAITI_TYPE_NPC = 2,
    FLD_HAITI_TYPE_TAKARABAKO = 3,
    FLD_HAITI_TYPE_SAVE_POINT = 4,
    FLD_HAITI_TYPE_3DCURSOL = 5,
    FLD_HAITI_TYPE_LIGHT = 6,
    FLD_HAITI_TYPE_ENV_SE = 7,
    FLD_HAITI_TYPE_HANYOU = 8,
} FLD_HAITI_TYPE;

typedef enum {
    FLD_HAITI_EVEHIT_SPHERE = 0,
    FLD_HAITI_EVEHIT_POL = 1,
    FLD_HAITI_EVEHIT_BOX = 2,
} FLD_HAITI_EVEHIT;

typedef enum {
    FLD_HAITI_CURSOL3DTYPE_DEGUTI = 0,
    FLD_HAITI_CURSOL3DTYPE_SINNYU_OK = 1,
    FLD_HAITI_CURSOL3DTYPE_UE_IDOU = 2,
    FLD_HAITI_CURSOL3DTYPE_SITA_IDOU = 3,
    FLD_HAITI_CURSOL3DTYPE_TOKUSHU = 4,
    FLD_HAITI_CURSOL3DTYPE_TALK_OK = 5,
    FLD_HAITI_CURSOL3DTYPE_SISETU = 6,
} FLD_HAITI;

typedef enum {
    FLD_PATH_SOUTAI_TYPE = 0,
    FLD_PATH_ZETTAI_TYPE = 1,
} FLD_PATH;

typedef enum {
    FLD_EFFECT_NOT_SHOKI_HYOUZI_BIT = 0,
    FLD_EFFECT_NOT_SHOKI_ANIME_BIT = 1,
    FLD_EFFECT_RESERVE_1_BIT = 2,
    FLD_EFFECT_RESERVE_2_BIT = 3,
} FLD_EFFECT;

typedef enum {
    LINKRES_DRAWRES_FOR_MOVE = 1,
} LINKRES;

typedef enum {
    FLD_FACEATTR_PLAYERONLY_HIT_BIT = 0,
    FLD_FACEATTR_MOVEYUKA_BIT = 6,
    FLD_FACEATTR_MOVEOBJ_BIT = 7,
    FLD_FACEATTR_KEISHA_BIT = 8,
    FLD_FACEATTR_FOOTSE_BIT = 9,
    FLD_FACEATTR_TRANSOBJ_BIT = 10,
    FLD_FACEATTR_AUTOMAP_BIT = 11,
    FLD_FACEATTR_PLACE_BIT = 12,
    FLD_FACEATTR_ENCOUNT_BIT = 13,
    FLD_FACEATTR_TRAP_BIT = 14,
    FLD_FACEATTR_HANYOU_BIT = 15,
} FLD_FACEATTR;

typedef enum {
    FLD_LIGHT_USE_SCENELIGHT = 0,
    FLD_LIGHT_RESERVE1 = 1,
    FLD_LIGHT_RESERVE2 = 2,
} FLD_LIGHT;

typedef enum {
    BOX_TYPE_ITEM = 0,
    BOX_TYPE_GEM = 1,
    BOX_TYPE_DH = 2,
    BOX_TYPE_MAKA = 3,
} BOX_TYPE;

typedef enum {
    BOX_TRAP_NORMAL = 0,
    BOX_TRAP_ENEMY = 1,
    BOX_TRAP_DAMAGE1 = 2,
    BOX_TRAP_DAMAGE2 = 3,
    BOX_TRAP_DAMAGE3 = 4,
    BOX_TRAP_DAMAGE4 = 5,
    BOX_TRAP_DAMAGE5 = 6,
    BOX_TRAP_ETC = 7,
} BOX_TRAP;

typedef enum {
    SL_EXITMODE_CANCEL = 0,
    SL_EXITMODE_SAVE = 1,
    SL_EXITMODE_LOAD = 2,
} SL_EXITMODE;

typedef enum {
    FLD_SEQ_INIT = 0,
    FLD_SEQ_INIT2 = 1,
    FLD_SEQ_BGMLOAD = 2,
    FLD_SEQ_BGMLOAD2 = 3,
    FLD_SEQ_STARTSCR_WAIT = 4,
    FLD_SEQ_PRIVATE_PROCSTART = 5,
    FLD_SEQ_SLEEP = 6,
    FLD_SEQ_PRIVATE_PROCEND = 7,
    FLD_SEQ_FADEOUT = 8,
    FLD_SEQ_END = 9,
    FLD_SEQ_DEBUG_END_INI = 10,
    FLD_SEQ_DEBUG_END_SET = 11,
    FLD_SEQ_MAX = 12,
} FLD_SEQ;

typedef enum {
    FLD_SEQFLAG_BUSY = 1,
    FLD_SEQFLAG_EXIT = 2,
} FLD_SEQFLAG;

typedef enum {
    FLD_PROCFLAG_ENCOUNT = 16,
    FLD_PROCFLAG_CAMP = 32,
    FLD_PROCFLAG_UNITPAD = 64,
    FLD_PROCFLAG_CAMP2 = 128,
} FLD_PROCFLAG;

typedef enum {
    FLD_PROC_MODE_FLD = 0,
    FLD_PROC_MODE_CAMP = 1,
} FLD_PROC_MODE;

typedef enum {
    WAIT = 0,
    INIT = 1,
    CHECK = 2,
    SAVEINIT = 3,
    SAVEWAIT = 4,
    GOTITLE = 5,
    END = 6,
} CONTINUE_PROC;

typedef struct DLCAmIcon_t DLCAmIcon_t;
typedef struct FLDCAM_t FLDCAM_t;
typedef struct GameFileInfoOld_t GameFileInfoOld_t;
typedef struct GameFileInfo_t GameFileInfo_t;
typedef struct Sprite3D_t Sprite3D_t;
typedef struct UV_t UV_t;
typedef struct VIEWTEST_AREA_t VIEWTEST_AREA_t;
typedef struct VTX_t VTX_t;
typedef struct collision_s collision_s;
typedef struct dds3AdditionWork_t dds3AdditionWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3SystemWork_t dds3SystemWork_t;
typedef struct fldAddressProcessData_t fldAddressProcessData_t;
typedef struct fldAmAreaData_t fldAmAreaData_t;
typedef struct fldAmFileHeader2_t fldAmFileHeader2_t;
typedef struct fldAmFileHeader_t fldAmFileHeader_t;
typedef struct fldAmIcon_t fldAmIcon_t;
typedef struct fldAmMdl_t fldAmMdl_t;
typedef struct fldAmSBlock_t fldAmSBlock_t;
typedef struct fldAmXYZ_t fldAmXYZ_t;
typedef struct fldAreaName_t fldAreaName_t;
typedef struct fldAutoMapBuff31_t fldAutoMapBuff31_t;
typedef struct fldAutoMapBuffEX_t fldAutoMapBuffEX_t;
typedef struct fldAutoMapBuff_t fldAutoMapBuff_t;
typedef struct fldBasyoName_t fldBasyoName_t;
typedef struct fldBlockBuff_t fldBlockBuff_t;
typedef struct fldConstruntAreaFL2_t fldConstruntAreaFL2_t;
typedef struct fldConstruntObject_t fldConstruntObject_t;
typedef struct fldDebug_t fldDebug_t;
typedef struct fldEncountContol_t fldEncountContol_t;
typedef struct fldFileAreaDataFL1_t fldFileAreaDataFL1_t;
typedef struct fldFileAreaDataFL2_t fldFileAreaDataFL2_t;
typedef struct fldFileHeader_t fldFileHeader_t;
typedef struct fldFileInfoHeaderFL1_t fldFileInfoHeaderFL1_t;
typedef struct fldFileInfoHeaderFL2_t fldFileInfoHeaderFL2_t;
typedef struct fldFloorName_t fldFloorName_t;
typedef struct fldFollowCameraControl_t fldFollowCameraControl_t;
typedef struct fldGlobalWork_t fldGlobalWork_t;
typedef struct fldInputPanelProcessData_t fldInputPanelProcessData_t;
typedef struct fldNpcTable_t fldNpcTable_t;
typedef struct fldNpcUp_t fldNpcUp_t;
typedef struct fldResCam_t fldResCam_t;
typedef struct fldResCollPolyTomeName_t fldResCollPolyTomeName_t;
typedef struct fldResCollPolyTome_t fldResCollPolyTome_t;
typedef struct fldResCollisionBall_t fldResCollisionBall_t;
typedef struct fldResCollisionBox_t fldResCollisionBox_t;
typedef struct fldResCollisionPolyFace_t fldResCollisionPolyFace_t;
typedef struct fldResCollisionPoly_t fldResCollisionPoly_t;
typedef struct fldResCollision_t fldResCollision_t;
typedef struct fldResEvent_t fldResEvent_t;
typedef struct fldResHeadAreaName_t fldResHeadAreaName_t;
typedef struct fldResHeadLinkData_t fldResHeadLinkData_t;
typedef struct fldResHeadLink_t fldResHeadLink_t;
typedef struct fldResHeadPos_t fldResHeadPos_t;
typedef struct fldResHead_t fldResHead_t;
typedef struct fldResModel_t fldResModel_t;
typedef struct fldResPutEveBall_t fldResPutEveBall_t;
typedef struct fldResPutEveBox_t fldResPutEveBox_t;
typedef struct fldResPutEvePoly_t fldResPutEvePoly_t;
typedef struct fldResPutItemBox_t fldResPutItemBox_t;
typedef struct fldResPutNpc_t fldResPutNpc_t;
typedef struct fldResPutSE_t fldResPutSE_t;
typedef struct fldResPut_t fldResPut_t;
typedef struct fldResourceAreaRangePlane_t fldResourceAreaRangePlane_t;
typedef struct fldResourceAreaRange_t fldResourceAreaRange_t;
typedef struct fldResourceDataTable_t fldResourceDataTable_t;
typedef struct fldResourceEffect_t fldResourceEffect_t;
typedef struct fldResourceLightPath_t fldResourceLightPath_t;
typedef struct fldResourceLight_t fldResourceLight_t;
typedef struct fldResourceModelRange_t fldResourceModelRange_t;
typedef struct fldResourcePathData_t fldResourcePathData_t;
typedef struct fldResourcePathTableInfo_t fldResourcePathTableInfo_t;
typedef struct fldResourcePathTable_t fldResourcePathTable_t;
typedef struct fldResourcePoint_t fldResourcePoint_t;
typedef struct fldResourcePortal_t fldResourcePortal_t;
typedef struct fldResourceRadiusRange_t fldResourceRadiusRange_t;
typedef struct fldResourceTextureList_t fldResourceTextureList_t;
typedef struct fldResourceTypeTable_t fldResourceTypeTable_t;
typedef struct fldSaveNml_t fldSaveNml_t;
typedef struct fldSaveSml_t fldSaveSml_t;
typedef struct fldSave_t fldSave_t;
typedef struct fldSceneParam_t fldSceneParam_t;
typedef struct fldSequenceControl_t fldSequenceControl_t;
typedef struct fldSuspendName_t fldSuspendName_t;
typedef struct fldTakaraTbl_t fldTakaraTbl_t;
typedef struct fldUnitControl_t fldUnitControl_t;
typedef struct sdfIVector3_t sdfIVector3_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelDef_t sdfModelDef_t;

struct fldResourcePathData_t {
    u32 nKey;
    void *pItem;
    u32 *pKey;
};

struct fldResourceLightPath_t {
    f32 InsideR;
    f32 OutsideR;
    f32 Soften;
    f32 Bias;
    f32 DiffuseR;
    f32 DiffuseG;
    f32 DiffuseB;
    f32 AmbientR;
    f32 AmbientG;
    f32 AmbientB;
};

struct GameFileInfo_t {
    u16 verstr[3];
    u16 ver;
    u16 TmnlMode;
    u16 TmnlId;
    u16 Lv;
    u16 mode;
    s32 PlayTime;
    s16 endcnt;
    s16 newfile;
    char *cname_code;
    u16 cname_nums;
    char *pad3;
    u16 dante_mode;
    u16 end_list[7];
    s64 saveTime;
    s8 autoMapOpen[36];
    s8 autoMapOpenEX[2];
};

struct fldSave_t {
    fldBlockBuff_t *PushBlock[40];
    fldAutoMapBuff_t *amap;
    u8 takara[32];
    s16 tmnltype;
    s16 tmnlid;
    s32 AnahoriCnt;
    u8 takara2[12];
    s32 pub[11];
};

struct fldAutoMapBuff31_t {
    u32 *blkOpenFlg[8];
};

struct fldAutoMapBuffEX_t {
    u32 *blkOpenFlg[2];
};

struct fldAutoMapBuff_t {
    u32 *blkOpenFlg[30];
};

struct fldBlockBuff_t {
    u16 MviewOffFlg;
    u16 ManimeOffFlg;
    u16 hitOffFlg;
    u16 EviewOffFlg;
    u16 EanimeOffFlg;
    u8 EanimeCngID[16];
    u16 npcOffFlg;
    u16 gimicLastFlg;
};

struct fldResourceLight_t {
    u32 resv;
    u32 Flag;
    u32 AnimeType;
    f32 InsideR;
    f32 OutsideR;
    f32 Soften;
    f32 Bias;
    f32 DiffuseR;
    f32 DiffuseG;
    f32 DiffuseB;
    f32 AmbientR;
    f32 AmbientG;
    f32 AmbientB;
};

struct fldAmAreaData_t {
    char *pName;
    fldAmSBlock_t *pSB;
    u32 nSB;
    fldAmMdl_t *pMdl;
    fldAmXYZ_t *pPos;
};

struct DLCAmIcon_t {
    s32 fieldID;
    s32 areaID;
    s32 blockID;
    s32 floorID;
    s32 nodeIdx;
    fldAmIcon_t *fldAmIcon[1];
};

struct fldAmMdl_t {
    sdfModelDef_t *pMdl;
    void *pMat;
};

struct fldAmXYZ_t {
    f32 x;
    f32 y;
    f32 z;
};

struct fldAmSBlock_t {
    char *pName;
    u32 nodeIdx;
    fldAmIcon_t *pIcon;
    u32 nIcon;
    s32 floor;
    fldAmXYZ_t *pPos0;
    fldAmXYZ_t *pPos1;
};

struct fldAmIcon_t {
    u32 type;
    fldAmXYZ_t *pPos;
};

struct FLDCAM_t {
    f32 leng;
    f32 tgty;
    f32 camy;
    f32 fovy;
};

struct fldResPutEveBall_t {
    u32 Type;
    f32 r;
};

struct fldResPut_t {
    u32 Type;
    u32 EveIdx;
    u32 Visible;
    u32 _union;
    u8 *pDate;
    fldResPutEveBall_t *pEveBall;
};

struct fldResHeadPos_t {
    sdfVector4_t pos;
    sdfVector4_t rot;
    sdfVector4_t scl;
};

struct fldResHead_t {
    u32 resourceID;
    u32 resourceType;
    char *resourceName;
    u32 flag;
    fldResHeadPos_t *sisei;
    fldResHeadAreaName_t *areaname;
    fldResHeadLink_t *resourceLink;
    char *SBlockName;
    u32 _union;
    u8 *pDate;
    fldResPut_t *pPut;
};

struct fldResHeadAreaName_t {
    u32 num;
    char *name;
};

struct fldResHeadLink_t {
    u32 num;
    fldResHeadLinkData_t *data;
};

struct fldResHeadLinkData_t {
    u32 mode;
    char *name;
    u32 scl;
};

struct fldGlobalWork_t {
    s32 mode;
    s32 fieldID;
    s32 areaID;
    s32 blockID;
    s32 fieldOldID;
    s32 flag;
    s32 cammode;
    s32 cammode2;
    char *cammode5name;
    sdfVector4_t campos;
    s32 FootSE;
    s32 FootSEUp;
    s32 ElvIdx;
    s32 WaterIdx;
    char *startPro;
    dds3Basic_t *fastArea;
    f32 PlayerMoveLen;
    s32 NoEncountCnt;
    s32 AmSBlock;
    s32 AmFloor;
    s32 nameU;
    s32 nameD;
    s32 NoInpAmCnt;
    s32 NoInpPlCnt;
    s32 GunDmgOn;
    s32 areaOldID;
    s32 NoroiDamegeCnt;
    s32 CashStat;
    s32 CashFieldID;
    s32 CashAreaID;
    s32 AllPanelMode;
    s32 AllPanelCnt;
    s32 EL_serialID;
    s32 CamTableIdx;
    s32 BgmId;
    s32 SeId;
    s32 AreaToArea;
    s32 Snow;
    s32 DmgOn;
    f32 DmgLeng;
    s32 LightMa;
    s32 EncPID;
    s32 EncPIDUpper;
    f32 WaterY;
    f32 LastMoveLeng;
    s32 FukiTalk;
    sdfMemHandle_t *ghAmBg1LoadBuff;
    void *gAmBg1LoadBuff;
    sdfMemHandle_t *ghAmBg2LoadBuff;
    void *gAmBg2LoadBuff;
    sdfMemHandle_t *ghAmBg3LoadBuff;
    void *gAmBg3LoadBuff;
    sdfMemHandle_t *ghAmMk1LoadBuff;
    void *gAmMk1LoadBuff;
    sdfMemHandle_t *ghAmMk2LoadBuff;
    void *gAmMk2LoadBuff;
    s32 syukan_cam_reset_flg;
    s32 dmy5;
    f32 playerX;
    f32 playerY;
    f32 playerZ;
    f32 playerOldX;
    f32 playerOldY;
    f32 playerOldZ;
    f32 playerNewX;
    f32 playerNewY;
    f32 playerNewZ;
    f32 PlayerKakudo;
    f32 PlayerKakudoGoal;
    f32 PlayerMotionFrame;
    f32 PlayerSaka;
    s32 HitUpdate;
    s32 dmy6[2];
};

struct fldDebug_t {
    s32 MenuOn;
    s32 MenuCur;
    s32 MenuCur1;
    s32 MenuCur2;
    s32 MenuCur3;
    s32 MenuCur4;
    s32 MenuCur9;
    s32 MenuCur10;
    s32 MenuCur11;
    s32 MenuCur12;
    s32 MenuCur13;
    s32 HitView;
    s32 ViewMode;
    s32 InfoOn;
    s32 BlurOn;
    s32 ExBlurOn;
    s32 SkyTblID;
    s32 SkyTblAnm;
    s32 FilterID;
    s32 FilterAlp;
    s32 FilterMode;
    s32 FilterAnm;
    s32 EncountOn;
    s32 EncountBtnOn;
    s32 NoClip;
    s32 PlayerStatus;
    s32 PlayerAction;
    s32 AutomapRapid;
    s32 SpProcOn;
    s32 PlayerMoveSpeed;
    s32 WarpSkip;
    s32 VibPoworLow;
    s32 VibPoworHigh;
    s32 VibTimeLow;
    s32 VibTimeHigh;
    s32 MemoryDisp;
};

struct fldAreaName_t {
    s16 _fld;
    s16 _area;
    char *_name;
};

struct fldBasyoName_t {
    s16 _fld;
    s16 _basyo;
    char *_name;
};

struct fldFloorName_t {
    s16 _fld;
    s16 _floor;
    char *_name;
};

struct fldSuspendName_t {
    s16 _fld;
    s16 _area;
    char *_name;
};

struct fldNpcTable_t {
    s16 _type;
    s16 _model_id1;
    s16 _model_id2;
    s16 _model_mot;
    s16 _hit_size;
    s16 _camera;
    s16 _flag;
    s16 _flag_switch;
};

struct fldNpcUp_t {
    s8 _field;
    s8 _area;
    char *_name;
    s8 _model_id1;
    u8 _model_id2;
    s8 _model_mot;
    s8 _hit_size;
    s8 _camera;
    s16 _flag;
};

struct fldTakaraTbl_t {
    s32 _Type;
    s16 _ItemID;
    s16 _ItemNum;
    s32 _Trap;
    s32 _Param;
};

struct fldSaveNml_t {
    s16 _fld;
    s16 _flg;
};

struct fldSaveSml_t {
    s16 _fld;
    s16 _jmp;
};

struct fldResCollisionPoly_t {
    u32 nVertex;
    u32 nFace;
    u32 n3;
    sdfVector4_t *pVertex;
    fldResCollisionPolyFace_t *pFace;
    fldResCollPolyTome_t *pTome;
};

struct fldResCollisionPolyFace_t {
    u32 Attr;
    u8 Myuka;
    u8 Se;
    u16 TomeIdx;
    u16 Basyo;
    u8 Amap0;
    u8 Amap1;
    u32 VtxIdx[4];
    s16 EncType;
    s16 EncIdx;
    s16 Spc1;
    s16 Spc2;
};

struct fldResCollPolyTome_t {
    s32 Num;
    fldResCollPolyTomeName_t *TomeName[32];
};

struct fldResCollPolyTomeName_t {
    char *Name;
    s32 res;
};

struct collision_s {
    s16 mode2D;
    s16 numedges;
    sdfVector4_t normal;
    f32 num;
    sdfVector4_t e_normal[4];
    f32 e_num[4];
    f32 min[2];
    f32 max[2];
    sdfVector4_t point[4];
    sdfVector4_t elv;
    s16 blockID;
    s16 hitflag;
    s32 resID;
    dds3Basic_t *matter;
    fldResCollisionPolyFace_t *pFace;
    fldResCollPolyTome_t *pTome;
    s32 hojiID;
    s32 npcID;
};

struct fldResourcePoint_t {
    sdfVector4_t pos;
    sdfVector4_t rot;
    sdfVector4_t scl;
};

struct fldSceneParam_t {
    fldResourcePoint_t safeUnitPoint;
    u32 flag;
    s32 mode;
    u32 pointResrcID;
    s32 noUnit;
    u16 *pointResName;
    s32 loadField;
    s32 loadArea;
    s32 loadScript;
    s32 callmode;
    s16 bgm;
    s16 bgmMode;
    s32 camMode;
    u32 padd1;
    u32 padd2;
    u16 *camName;
    u16 *FoceScript;
    u32 loadMode;
    u32 pad[16];
};

struct fldUnitControl_t {
    dds3Basic_t *handle;
    dds3Basic_t *handle2;
    s8 moveFlag;
    s8 rotFlag;
};

struct fldFollowCameraControl_t {
    sdfVector4_t wideCameraOffset;
    sdfVector4_t wideTargetOffset;
    sdfVector4_t narrowCameraOffset;
    sdfVector4_t narrowTargetOffset;
    sdfVector4_t q0;
    sdfVector4_t q1;
    f32 rotFrame;
    f32 rotFrameMax;
    f32 t0;
    f32 t1;
    f32 lenFrame;
    f32 lenFrameMax;
    dds3Basic_t *handle;
};

struct fldEncountContol_t {
    sdfVector4_t unitPos;
};

struct fldSequenceControl_t {
    u32 flag;
    s32 phase;
};

struct dds3AdditionWork_t {
    s32 fieldID;
    s32 areaID;
    sdfVector4_t playerPos;
    sdfVector4_t playerRot;
    s32 CamTableIdx;
    s32 BgmId;
    s32 SeId;
    u8 WarpIndex;
    s32 nameU;
    s32 nameD;
    u8 CamMode;
    s32 AmFloor;
    u8 gFldNowDZone;
    s8 dummy[5];
};

struct dds3SystemWork_t {
    s8 dlcflg[8];
    s8 dummy[20];
    s16 Transport_Count;
    s16 Combine_Count;
    s16 Purchase_Bit;
    s16 Race_Bit;
    s16 EndingList;
    s16 GiftCount;
    s16 WeakCount;
    s16 TalkJoin;
    u32 Bad_Bit;
    u32 MagaTama_Bit;
};

struct fldAmFileHeader2_t {
    u32 pAmInfo;
    fldAmAreaData_t *pArea;
    u32 nArea;
};

struct fldAmFileHeader_t {
    u32 Version;
    u8 MagCode[4];
};

struct UV_t {
    u16 u;
    u16 v;
};

struct VTX_t {
    f32 x;
    f32 y;
};

struct Sprite3D_t {
    sdfVector4_t pos;
    UV_t *uv0;
    UV_t *uv1;
    UV_t *uv2;
    UV_t *uv3;
    VTX_t *vt0;
    VTX_t *vt1;
    VTX_t *vt2;
    VTX_t *vt3;
    s32 col;
    f32 rot;
};

struct fldResourceEffect_t {
    u32 flag;
    u32 type;
    u32 noEffect;
    f32 size[3];
    u32 offsetZ;
    u32 groupID;
    u32 param0;
    u32 param1;
};

struct fldResCollisionBall_t {
    u32 Attr;
    s32 EveResIdx;
    f32 r;
};

struct fldResCollisionBox_t {
    u32 Attr;
    s32 EveResIdx;
    f32 zw;
    f32 xw;
    f32 yw;
};

struct fldResCollision_t {
    u32 Type;
    u32 Attr;
    u32 _union;
};

struct fldResEvent_t {
    u32 flag;
    char *label;
};

struct fldResPutEvePoly_t {
    u32 Type;
    f32 y;
    f32 z;
};

struct fldResPutEveBox_t {
    u32 Type;
    f32 y;
    f32 x;
    f32 z;
};

struct fldResPutNpc_t {
    u32 id;
};

struct fldResPutItemBox_t {
    u32 id;
};

struct fldResPutSE_t {
    f32 r;
    s32 id;
};

struct fldResModel_t {
    u32 Flag;
    u32 nLod;
    u32 dmy;
    u32 dmy2;
    u32 pMdl;
    u32 pMat;
    u32 dmy3;
    u32 dmy4;
    u32 pMot;
};

struct fldResourceTextureList_t {
    u32 flag;
    u32 nTexture;
    u32 Texture;
};

struct fldResourcePathTable_t {
    u32 type;
    fldResourcePathData_t *pData;
};

struct fldResourcePathTableInfo_t {
    u32 nPathTable;
    fldResourcePathTable_t *pPathTableDat;
};

struct fldResCam_t {
    f32 fovy;
};

struct fldResourceDataTable_t {
    u32 resourceID;
    void *pData;
    u32 dataTop;
};

struct fldResourceTypeTable_t {
    u32 type;
    u32 nResourceDataTable;
    fldResHead_t *pResourceDataTable;
};

struct fldConstruntObject_t {
    u32 type;
    u32 objectID;
    u32 attachAreaID;
    u32 parentObjectID;
    u32 resourceID[2];
    u32 padd[2];
    sdfVector4_t pos;
    sdfVector4_t quat;
    sdfVector4_t scl;
};

struct fldFileAreaDataFL1_t {
    u32 fileID;
    u32 SkyTblIdx;
    char *filename0;
    char *filename1;
    char *filename2;
    char *filename3;
};

struct fldFileAreaDataFL2_t {
    u32 fileID;
    char *label;
    s32 areaFrameno;
};

struct fldConstruntAreaFL2_t {
    u32 flag;
    char *areaName;
    u32 areaID;
};

struct fldFileInfoHeaderFL1_t {
    u32 nResourceTypeTable;
    fldResourceTypeTable_t *pResourceTypeTable;
    fldFileAreaDataFL1_t *pAreaData;
};

struct fldFileInfoHeaderFL2_t {
    u32 nResourceTypeTable;
    fldResourceTypeTable_t *pResourceTypeTable;
    fldFileAreaDataFL2_t *pAreaData;
    u32 nArea;
    fldConstruntAreaFL2_t *pAreaTable;
};

struct fldFileHeader_t {
    u32 Version;
    u8 MagCode[4];
};

struct fldResourceAreaRangePlane_t {
    sdfVector4_t normal;
    sdfVector4_t point;
};

struct fldResourceAreaRange_t {
    u32 nPlane;
    fldResourceAreaRangePlane_t *pPlane;
};

struct fldResourcePortal_t {
    u32 nVertex;
    u32 nFace;
    u32 attachAreaID[2];
    sdfVector4_t *pVertex;
    sdfIVector3_t *pFace;
};

struct fldResourceModelRange_t {
    u32 nVertex;
    u32 nFace;
    sdfVector4_t *pVertex;
    sdfIVector3_t *pFace;
    void *dummy;
};

struct fldResourceRadiusRange_t {
    u32 type;
    f32 r;
    u32 padd[2];
    sdfVector4_t size;
};

struct GameFileInfoOld_t {
    u16 TmnlMode;
    u16 TmnlId;
    u16 Lv;
    u16 pad;
    s32 PlayTime;
    s32 pad2;
    s32 pad3;
};

struct fldInputPanelProcessData_t {
    u16 Count;
    u16 Type;
    u16 Draw;
    u16 Reserve1;
    void *PanelText;
    void *PanelObj;
};

struct fldAddressProcessData_t {
    s32 dmy[4];
};

struct VIEWTEST_AREA_t {
    u32 serialID;
    sdfVector4_t CenterPos;
    f32 r;
    void *workdata;
};
