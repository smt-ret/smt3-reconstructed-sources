#pragma once
#include "types.h"

typedef enum {
    CMP_DH_MOVETYPE_NONE = 0,
    CMP_DH_MOVETYPE_LOW = 1,
    CMP_DH_MOVETYPE_HIGH = 2,
} CMP_DH_MOVETYPE;

typedef enum {
    CMP_DH_DRAWTYPE_NORMAL = 0,
    CMP_DH_DRAWTYPE_LIGHT = 1,
} CMP_DH_DRAWTYPE;

typedef enum {
    CMP_SEQ_DH_ROOT = 0,
    CMP_SEQ_DH_ATTACH_STATUS = 1,
    CMP_SEQ_DH_ATTACH_CFM = 2,
    CMP_SEQ_DH_REMOVE_CFM = 3,
    CMP_SEQ_DH_ERR = 4,
} CMP_SEQ_DH;

typedef enum {
    CMB_STATSTYLE_HELP = 0,
    CMB_STATSTYLE_NOHELP = 1,
    CMB_STATSTYLE_LEVUP = 2,
    CMB_STATSTYLE_INFO = 3,
    CMB_STATSTYLE_HEARTS = 4,
} CMB_STATSTYLE;

typedef enum {
    CMP_SELSTR_YN = 0,
    CMP_SELSTR_ATTACH = 1,
} CMP_SELSTR;

typedef enum {
    CMP_ETCSTR_CALL = 0,
    CMP_ETCSTR_NO_DH_DEV = 1,
} CMP_ETCSTR;

typedef enum {
    CMP_INFO_COMMAND = 0,
    CMP_INFO_SKILL = 1,
    CMP_INFO_STATUS = 2,
    CMP_INFO_PARTY = 3,
    CMP_INFO_ITEM = 4,
    CMP_INFO_STOCK = 5,
    CMP_INFO_TARGET = 6,
    CMP_INFO_ITEM_USE = 7,
    CMP_INFO_JEW = 8,
    CMP_INFO_VAL = 9,
    CMP_INFO_DH = 10,
    CMP_INFO_DH_REMOVE = 11,
    CMP_INFO_DH_ATTACH = 12,
    CMP_INFO_SYOKAN = 13,
    CMP_INFO_KIKAN = 14,
    CMP_INFO_WAKARE = 15,
    CMP_INFO_SUTE = 16,
} CMP_INFO;

typedef enum {
    CMP_SEQ_RO = 0,
    CMP_SEQ_IT = 1,
    CMP_SEQ_SK = 2,
    CMP_SEQ_PA = 3,
    CMP_SEQ_DE = 4,
    CMP_SEQ_ST = 5,
    CMP_SEQ_SY = 6,
    CMP_SEQ_LO = 7,
    CMP_SEQ_SUSPEND = 8,
    CMP_SEQ_DSL = 9,
    CMP_SEQ_TSL = 10,
    CMP_SEQ_SSL = 11,
    CMP_SEQ_ISL = 12,
    CMP_SEQ_DE_EQ = 13,
    CMP_SEQ_DE_RE = 14,
    CMP_SEQ_SPL_CFM = 15,
    CMP_SEQ_SPL = 16,
    CMP_SEQ_IT_DES_CFM = 17,
    CMP_SEQ_MAX = 18,
} CMP_SEQ;

typedef enum {
    INIT = 0,
    CHECK = 1,
    SAVEINIT = 2,
    SAVEWAIT = 3,
    ENDWAIT = 4,
    GOTITLE = 5,
    ERROR = 6,
    END = 7,
} CMP_SUSPEND;

typedef enum {
    CMP_SEQ_IT_USE = 0,
    CMP_SEQ_IT_DES = 1,
    CMP_SEQ_IT_JEW = 2,
    CMP_SEQ_IT_VAL = 3,
} CMP_SEQ_IT;

typedef enum {
    CMP_SEQ_PA_CALL = 0,
    CMP_SEQ_PA_RET = 1,
    CMP_SEQ_PA_SPL = 2,
} CMP_SEQ_PA;

typedef enum {
    CMP_EXITSTAT_NORMAL = 0,
    CMP_EXITSTAT_LOAD = 1,
} CMP_EXITSTAT;

typedef enum {
    CMP_SEQTYPE_FLAG = -1,
    CMP_SEQTYPE_NONE = 0,
    CMP_SEQTYPE_NEXT = 1,
    CMP_SEQTYPE_PREV = 2,
} CMP_SEQTYPE;

typedef enum {
    CMP_CURSOREFF_NONE = 0,
    CMP_CURSOREFF_COLOR = 1,
    CMP_CURSOREFF_FADEOUT = 2,
    CMP_CURSOREFF_REVIVE = 3,
    CMP_CURSOREFF_REMOVE = 4,
    CMP_CURSOREFF_OFSX = 5,
} CMP_CURSOREFF;

typedef enum {
    CMP_CURSOREFF_TARGET_STR = 0,
    CMP_CURSOREFF_TARGET_PANEL = 1,
    CMP_CURSOREFF_TARGET_MAX = 2,
} CMP_CURSOREFF_TARGET;

typedef enum {
    CMP_STOCKDRAW_NONE = 0,
    CMP_STOCKDRAW_CURSOR_0 = 1,
    CMP_STOCKDRAW_COLOR_0 = 2,
    CMP_STOCKDRAW_SECOND = 3,
    CMP_STOCKDRAW_PARTY = 4,
    CMP_STOCKDRAW_CURSOR_1 = 5,
    CMP_STOCKDRAW_ALL = 6,
} CMP_STOCKDRAW;

typedef enum {
    CMP_PANELEFFTYPE_RECOVER = 0,
    CMP_PANELEFFTYPE_RECOVER_BAD = 1,
    CMP_PANELEFFTYPE_RECOVER_DEAD = 2,
    CMP_PANELEFFTYPE_ITEM_TOKUSYU = 3,
    CMP_PANELEFFTYPE_NOTARGET = 4,
    CMP_PANELEFFTYPE_KUGAT = 5,
    CMP_PANELEFFTYPE_HEARTS = 6,
    CMP_PANELEFFTYPE_EXPERIENCE = 7,
} CMP_PANELEFFTYPE;

typedef enum {
    CMP_YESNO_STYLE_SMALL = 0,
    CMP_YESNO_STYLE_LEARGE = 1,
    CMP_YESNO_STYLE_MESSAGE = 2,
    CMP_YESNO_STYLE_SELECT = 3,
} CMP_YESNO_STYLE;

typedef struct cmpCmdSelInfo_t cmpCmdSelInfo_t;
typedef struct cmpCrossFadeFunc_t cmpCrossFadeFunc_t;
typedef struct cmpCrossInfo_t cmpCrossInfo_t;
typedef struct cmpCrossParam_t cmpCrossParam_t;
typedef struct cmpCursorEffCore_t cmpCursorEffCore_t;
typedef struct cmpCursorEff_t cmpCursorEff_t;
typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpCursorPos_t cmpCursorPos_t;
typedef struct cmpCursorSize_t cmpCursorSize_t;
typedef struct cmpDataDH_t cmpDataDH_t;
typedef struct cmpDataInfo_t cmpDataInfo_t;
typedef struct cmpDataPanelEff_t cmpDataPanelEff_t;
typedef struct cmpDataStatus_t cmpDataStatus_t;
typedef struct cmpDataStock_t cmpDataStock_t;
typedef struct cmpDataYesNo_t cmpDataYesNo_t;
typedef struct cmpGlobalWork_t cmpGlobalWork_t;
typedef struct cmpHeartsIcon_t cmpHeartsIcon_t;
typedef struct cmpHeartsInfo_t cmpHeartsInfo_t;
typedef struct cmpHeartsPosTbl_t cmpHeartsPosTbl_t;
typedef struct cmpLocalSkill_t cmpLocalSkill_t;
typedef struct cmpLocalStock_t cmpLocalStock_t;
typedef struct cmpPanelEffRecoverParamCore_t cmpPanelEffRecoverParamCore_t;
typedef struct cmpPanelEffRecoverParam_t cmpPanelEffRecoverParam_t;
typedef struct cmpPanelEff_s cmpPanelEff_s;
typedef struct cmpSeqInfo_s cmpSeqInfo_s;
typedef struct cmpStatusModel_t cmpStatusModel_t;
typedef struct cmpStockInfo_t cmpStockInfo_t;
typedef struct cmpYesNoInfo_t cmpYesNoInfo_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclPanelPos_t fclPanelPos_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct cmpDataDH_t {
    cmpSeqInfo_t *SeqInfo;
    sdfMemHandle_t *MH;
    s8 Flag;
    s32 Timer;
    s32 ActiveTimer;
    s32 EquipTimer;
    s32 PadActTimer;
    s32 CmdBgRate;
    s8 CurrentSelSetting;
    s8 SelectPos;
    s8 LatestEquipHearts;
    datUnitWork_t *LatestStock;
    cmpStockInfo_t *pStockInfo;
    cmpCursorInfo_t *CursorInfo;
    sdfTexHandle_t *TexHandle[3];
    s32 BlurTimer[64];
    cmpHeartsIcon_t *HeartsIcon[64];
    cmpHeartsInfo_t *HeartsInfo;
};

struct cmpSeqInfo_s {
    u8 Flag;
    s8 Current;
    s8 Next;
    s8 Last;
    s8 Change;
    s8 MesFlag;
    dds3ProcessID_t *MesPID;
    s32 Timer;
    cmpSeqInfo_s *pParent;
};

struct cmpStockInfo_t {
    cmpLocalStock_t *LocalStock[2];
    cmpCursorInfo_t *SelPos[2];
    s8 DrawMode;
};

struct cmpCursorInfo_t {
    s32 StepY;
    s8 StopFlag;
    cmpCursorSize_t *CursorSize;
    cmpCursorPos_t *CursorPos;
};

struct cmpHeartsInfo_t {
    u32 Stat;
    s32 Timer;
    s8 Spd;
    s8 HeartsID;
    s8 PanelStat;
    s32 PanelTimer;
    s32 PanelSpd;
};

struct cmpCursorSize_t {
    s32 X;
    s32 Y;
    s32 W;
    s32 H;
    s32 DefX;
    s32 DefY;
};

struct cmpCursorPos_t {
    u8 ListNums;
    s8 InvisibleListNums;
    s16 Index;
    u8 Shift;
    u8 DrawShift;
    u8 ShiftMax;
    char pStr[UNKNOWN_ARRAY_SIZE];
    u8 pFlag[UNKNOWN_ARRAY_SIZE];
    s32 Timer;
    s32 ActiveTimer;
    s8 EffFlag;
    cmpCursorEff_t *Eff[256];
};

struct cmpHeartsIcon_t {
    s8 Stat;
    s8 IconType;
    u32 IconColor;
    s8 MoveType;
    s8 Axis;
    s32 AxisChg;
    s32 Wait1st;
    s32 Wait;
    f32 Angle;
    f32 DefAng;
    f32 DistAng;
    s32 DefCnt;
    s32 Cnt;
    s32 Timer;
    s32 TimerSpd;
};

struct cmpLocalStock_t {
    u16 Flag;
    s8 PartyCnt;
    s8 StockCnt;
    s8 InvalidCnt;
    s8 StockIdx[16];
    s8 ListIdx[16];
    u16 BadStatus[16];
    u8 BadTimer[16];
};

struct cmpCursorEff_t {
    cmpCursorEffCore_t *Target[2];
};

struct cmpCursorEffCore_t {
    s8 Type;
    u8 Spd;
    s32 Timer;
};

struct cmpDataStock_t {
    cmpSeqInfo_t *SeqInfo;
    sdfMemHandle_t *MH;
    s8 Mode;
    cmpStockInfo_t *pStockInfo;
};

struct cmpDataInfo_t {
    cmpSeqInfo_t *SeqInfo;
    sdfMemHandle_t *MH;
    char *pInfoStr;
};

struct cmpGlobalWork_t {
    cmpSeqInfo_t *SeqInfo;
    sdfMemHandle_t *MH;
    s8 Flag;
    cmpCursorInfo_t *RootCI[4];
    cmpCursorInfo_t *WorkCI[2];
    cmpStockInfo_t *StockInfo;
    cmpLocalStock_t *DrawList;
    u8 ItemCnt;
    s8 ItemListFlag;
    u16 ItemIdx[160];
    s8 ItemType;
    s8 StatusFlag;
    cmpCrossInfo_t *CrossInfo;
    s32 BaseRate;
    dds3ProcessID_t *HeartsPID;
    s32 RootTimer;
    s32 FadeInTimer;
    s32 PanelRate[16];
    s8 PanelSpd[16];
    s32 PanelWait[16];
};

struct cmpCrossInfo_t {
    cmpCrossParam_t *Before;
    cmpCrossParam_t *After;
};

struct cmpCrossParam_t {
    cmpCrossFadeFunc_t *DrawFunc;
    fclPanelPos_t *Pos;
    cmpCursorInfo_t *pCursorInfo;
    void *pData;
    s32 Rate;
    s8 Mode;
    u32 OtNo;
};

struct cmpHeartsPosTbl_t {
    s8 HeartsID;
    s8 IconType;
    u32 Color;
};

struct cmpDataPanelEff_t {
    cmpSeqInfo_t *SeqInfo;
    sdfMemHandle_t *MH;
    cmpPanelEff_s *QueInst[32];
};

struct cmpPanelEff_s {
    u8 Flag;
    u8 Speed;
    u8 StartWait;
    u8 Type;
    u32 StartCol;
    u32 EndCol;
    s32 X;
    s32 Y;
    u32 Z;
    u16 W;
    u16 H;
    s32 Timer;
    s32 Work;
    cmpPanelEffRecoverParam_t *RecovParam;
};

struct cmpPanelEffRecoverParam_t {
    cmpPanelEffRecoverParamCore_t *Core[16];
};

struct cmpPanelEffRecoverParamCore_t {
    s32 X;
    s32 Y;
    s32 StartX;
    s32 StartY;
    s32 EndX;
    s32 EndY;
    s32 Len;
    u8 Dir;
    s32 FrameDef;
    s32 Frame;
    u32 Col;
};

struct cmpDataStatus_t {
    cmpSeqInfo_t *SeqInfo;
    sdfMemHandle_t *MH;
    u16 DevilList[16];
    s8 ListCount;
    s8 SelPos;
};

struct cmpDataYesNo_t {
    cmpSeqInfo_t *SeqInfo;
    sdfMemHandle_t *MH;
    cmpYesNoInfo_t *pYesNoInfo;
};

struct cmpYesNoInfo_t {
    fclPanelPos_t *Pos;
    s32 Col;
    s8 Style;
    s8 MainStrNo;
    dds3ProcessID_t *ScriptPID;
    u8 pMainStrScr[UNKNOWN_ARRAY_SIZE];
    char *pSelStr[2];
    cmpCursorInfo_t *CursorInfo;
};

struct cmpStatusModel_t {
    u8 MotionNo;
    f32 Scl;
    f32 Spd;
    sdfVector4_t Pos;
    sdfVector4_t Rot;
};

struct cmpCmdSelInfo_t {
    s8 pCmdStr[UNKNOWN_ARRAY_SIZE];
    cmpCursorInfo_t *CursorInfo;
};

struct cmpLocalSkill_t {
    s8 SkillCnt;
    s8 SkillIdx[24];
};

typedef struct cmpSeqInfo_s cmpSeqInfo_t;
