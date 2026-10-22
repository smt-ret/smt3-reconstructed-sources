#pragma once
#include "types.h"

typedef enum {
    NME_TEX_MAX = 4,
    NME_FONT_STYLE = 4,
    NME_FONT_STYLE_CAP = 1,
    NME_FONT_STYLE_CNAME = 1,
    NME_SEI_NUMS = 4,
    NME_MEI_NUMS = 4,
    NME_CNAME_NUMS = 8,
    NME_NAME_NUMS = 8,
} NME;

typedef enum {
    NME_SEQ_NONE = 0,
    NME_SEQ_EXIT = 1,
} NME_SEQ;

typedef enum {
    NME_ENTMODE_NAME_AND_CNAME = 0,
    NME_ENTMODE_NAME_ONLY = 1,
    NME_ENTMODE_MAX = 2,
} NME_ENTMODE;

typedef enum {
    NME_TARGET_PLAYER = 0,
    NME_TARGET_TEACHER = 1,
    NME_TARGET_ISAM = 2,
    NME_TARGET_CHIAKI = 3,
    NME_TARGET_MAX = 4,
} NME_TARGET;

typedef enum {
    NME_ENTTYPE_SEI = 0,
    NME_ENTTYPE_MEI = 1,
    NME_ENTTYPE_CNAME = 2,
    NME_ENTTYPE_MAX = 3,
} NME_ENTTYPE;

typedef enum {
    NME_MODE_HIRA = 0,
    NME_MODE_KATA = 1,
    NME_MODE_EISU = 2,
    NME_MODE_KAN = 3,
    NME_MODE_MAX = 4,
} NME_MODE;

typedef enum {
    NME_SPR_CAPBASE_HIRA = 0,
    NME_SPR_CAPBASE_KATA = 1,
    NME_SPR_CAPBASE_EISU = 2,
    NME_SPR_CAPBASE_KAN = 3,
    NME_SPR_LLine = 4,
    NME_SPR_RLine = 5,
    NME_SPR_06 = 6,
    NME_SPR_07 = 7,
    NME_SPR_NML_UBAR = 8,
    NME_SPR_SEL_UBAR = 9,
    NME_SPR_INFO_NAME = 10,
    NME_SPR_L = 11,
    NME_SPR_NML_HIRA = 12,
    NME_SPR_NML_KATA = 13,
    NME_SPR_NML_EISU = 14,
    NME_SPR_NML_KAN = 15,
    NME_SPR_R = 16,
    NME_SPR_SEI = 17,
    NME_SPR_MEI = 18,
    NME_SPR_SEL_HIRA = 19,
    NME_SPR_SEL_KATA = 20,
    NME_SPR_SEL_EISU = 21,
    NME_SPR_SEL_KAN = 22,
    NME_SPR_BAR = 23,
    NME_SPR_24 = 24,
    NME_SPR_UL_LINE = 25,
    NME_SPR_BL_LINE = 26,
    NME_SPR_UR_LINE = 27,
    NME_SPR_BR_LINE = 28,
    NME_SPR_29 = 29,
    NME_SPR_30 = 30,
    NME_SPR_31 = 31,
    NME_SPR_32 = 32,
    NME_SPR_33 = 33,
    NME_SPR_34 = 34,
    NME_SPR_35 = 35,
    NME_SPR_36 = 36,
    NME_SPR_37 = 37,
    NME_SPR_38 = 38,
    NME_SPR_39 = 39,
    NME_SPR_40 = 40,
    NME_SPR_41 = 41,
    NME_SPR_42 = 42,
    NME_SPR_43 = 43,
    NME_SPR_44 = 44,
    NME_SPR_45 = 45,
    NME_SPR_46 = 46,
    NME_SPR_47 = 47,
    NME_SPR_48 = 48,
    NME_SPR_49 = 49,
    NME_SPR_50 = 50,
    NME_SPR_51 = 51,
    NME_SPR_52 = 52,
    NME_SPR_53 = 53,
    NME_SPR_54 = 54,
    NME_SPR_55 = 55,
    NME_SPR_56 = 56,
    NME_SPR_57 = 57,
    NME_SPR_58 = 58,
    NME_SPR_59 = 59,
    NME_SPR_60 = 60,
    NME_SPR_61 = 61,
    NME_SPR_INFO_CODENAME = 62,
    NME_SPR_63 = 63,
    NME_SPR_64 = 64,
    NME_SPR_65 = 65,
    NME_SPR_66 = 66,
    NME_SPR_67 = 67,
    NME_SPR_68 = 68,
    NME_SPR_69 = 69,
    NME_SPR_70 = 70,
    NME_SPR_71 = 71,
    NME_SPR_72 = 72,
    NME_SPR_BG = 73,
    NME_SPR_MAX = 74,
} NME_SPR;

typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpSeqInfo_s cmpSeqInfo_t;
typedef struct fclDrawSprTbl_t fclDrawSprTbl_t;
typedef struct fclSprTblArry_t fclSprTblArry_t;
typedef struct fclSprTbl_t fclSprTbl_t;
typedef struct nmeData_t nmeData_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct nmeData_t {
    cmpSeqInfo_t *SeqInfo;
    sdfMemHandle_t *MH;
    s8 TargetNo;
    s8 EntryMode;
    s8 EntryType;
    s8 CfmFlag;
    cmpCursorInfo_t *ModeCursor;
    cmpCursorInfo_t *CharCursor[2];
    s8 FuncFlag;
    cmpCursorInfo_t *FuncCursor;
    cmpCursorInfo_t *YesNoCursor;
    s8 ListCapFlag;
    s8 InputNums[3];
    s8 InputPos;
    u8 *InputCode;
    sdfTexHandle_t *Tex[4];
    s32 BaseRate;
};

extern fclSprTbl_t *nmeSprTbl00[45];
extern fclDrawSprTbl_t *nmeDrawSprTbl00[74];
extern fclSprTbl_t *nmeSprTbl01[17];
extern fclDrawSprTbl_t *nmeDrawSprTbl01[27];
extern fclSprTbl_t *nmeSprTbl02[2];
extern fclDrawSprTbl_t *nmeDrawSprTbl02[2];
extern fclSprTbl_t *nmeSprTbl03[20];
extern fclDrawSprTbl_t *nmeDrawSprTbl03[27];
extern fclSprTblArry_t *nmeSprTblArry[4];
