#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct FldNameData FldNameData;
typedef struct FsSaveData FsSaveData;
typedef struct GameFileInfo_t GameFileInfo_t;
typedef struct NB_FILEHANDLE_T NB_FILEHANDLE_T;
typedef struct _FRQ _FRQ;
typedef struct dds3AdditionWork_t dds3AdditionWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3GlobalWork_t dds3GlobalWork_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct dds3SystemWork_t dds3SystemWork_t;
typedef struct fileCb_t fileCb_t;
typedef struct fileHandle_t fileHandle_t;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;
typedef struct saveUI saveUI;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct slMain_nextFuncDelegate slMain_nextFuncDelegate;
typedef struct slMain_slExitWaitNextFuncDelegate slMain_slExitWaitNextFuncDelegate;
typedef struct slMain_slHitAnyKeyNextFuncDelegate slMain_slHitAnyKeyNextFuncDelegate;
typedef struct slMain_slQueryNoFuncDelegate slMain_slQueryNoFuncDelegate;
typedef struct slMain_slQueryYesFuncDelegate slMain_slQueryYesFuncDelegate;
typedef struct slMain_slSaveWriteFile_endFuncDelegate slMain_slSaveWriteFile_endFuncDelegate;

static s32 slDDS3To31Flg;
static s32 slProcShutDownFlg;
static sdfTexHandle_t *hSlTex01;
static sdfTexHandle_t *hSlTex02;
static void *slProcPtr;
static s32 selectWait;
static s32 selectNum;
static dds3GlobalWork_t *dds3Work;
static bool _baseFlagSlMain;
static void *dataFileObj;
static saveUI *_saveUI;
static s32 bakSelect;
static bool debugCall;
static s32 saveButtonGuideFlag;
static s32 proc_func_ans;
static s32 loadMode;
static dds3AdditionWork_t *AdditionWork;
static dds3SystemWork_t *SystemWork;
static bool saveDataInit;
static u16 saveVer;
static u8 fileMesData[514];
static u8 loadMesData[361];
static slMain_slExitWaitNextFuncDelegate *slExitWaitNextFunc;
static s32 slExitWaitCnt;
static slMain_slHitAnyKeyNextFuncDelegate *slHitAnyKeyNextFunc;
static char *slSaveData_writeFile_wk_ptr;
static s32 slSaveData_writeFile_wk_size;
static f32 slFileSelDraw_blendcnt;
static f32 slFileSelDraw_blend;
static fileCb_t *baseIconFileHandle;
static sdfMemHandle_t *baseIconMh;
static void *baseIconPtr;
static s32 baseIconSize;
static s32 slFileHandle;
static sdfMemHandle_t *slLoadMh;
static void *slLoadPtr;
static s32 gslCheckCardWait;
static s32 gslDrawFlagFile;
static s32 gslDrawFlagBg;
static s32 gslAnimCnt;
static s32 gSlSelCnt;
static s32 gSlNowCardCheck;
static s32 gSlExitMode;
static s32 gSlFileSelKyeFlg;
static s32 gSlFileErroeFlg;
static s32 gSlSaveMode;
static s32 gSlEndingMode;
static s32 slChooseSaveIndex;
static slMain_slQueryYesFuncDelegate *slQueryYesFunc;
static slMain_slQueryNoFuncDelegate *slQueryNoFunc;
static s32 ContinueProc;
static s32 slQueryYesNoCursor;
static s32 slQueryYesNoMsg;
static s32 slQueryYesNoKeyFlag;
static s32 slInitalizeFlag;
static s32 gslStatFileInfo[21];
static s32 gslDirMode;
static GameFileInfo_t *gslInfo[21];
static s32 gslSelTop;
static s32 gslSelect;
static s32 gslFlushCnt;
static s32 gslMode;
static s32 gslInfoLoadFlg;
static s32 gslExitType;
static s32 gslInfoCode;
static s32 gslErrorCode;
static s32 gslErrorKeyFlag;
static s32 version_convert_ver;
static _FRQ *slKanjiDraw_handle;
static _FRQ *slKanjiDrawH_handle;
static f32 slNextPageDraw_fc;
static s32 gSlMcAccessCnt;
static f32 slMcAccessDraw_fc;
static s32 gSlWindowCnt;
static char *slSaveWriteFile_buff;
static s32 slSaveWriteFile_size;
static slMain_slSaveWriteFile_endFuncDelegate *slSaveWriteFile_endFunc;
static void *slSaveWriteFile_dataWaitPtr;

void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
bool CampBaseOff(dds3DefaultMain *this);
bool CampBaseOn(dds3DefaultMain *this);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void DrwSprite2D_17010048(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, u32 rgba, sdfTexHandle_t *th);
char *GetAreaName(FldNameData *this, s32 fld, s32 area);
char *GetBasyoName(s32 fieldID, s32 nameU, s32 nameD);
char *GetFieldName(FldNameData *this, s32 fld);
char *GetLocalizeText(char *ID);
char *GetPlatformStr(void);
char *GetSaveNmlName(FldNameData *this, s32 TmnlId);
char *GetSaveSmlName(FldNameData *this, s32 TmnlId);
void GetSuspendDispName(FsSaveData *this, s32 *nameU, s32 *nameD);
void GetSuspendFieldArea(FsSaveData *this, s32 *fieldID, s32 *areaID);
sdfColor_t GetToRGBA(u32 val);
void LoadLocalizeText(char *key, char *filename);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
s32 Load_18090368(FsSaveData *this, s32 num, dds3GlobalWork_t **Loadbuff, dds3AdditionWork_t **AdditionBuff);
void Remove(char *key);
char *RepColTag(char *txt, void **LegacyParamArray);
bool Save(FsSaveData *this, s32 num, dds3GlobalWork_t *Savebuff, bool init);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void SetupUI(void);
void aDrawBoxF(s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b, s32 a);
void aDrawBoxG(s32 x, s32 y, s32 w, s32 h, s32 r0, s32 g0, s32 b0, s32 a0, s32 r1, s32 g1, s32 b1, s32 a1, s32 r2, s32 g2, s32 b2, s32 a2, s32 r3, s32 g3, s32 b3, s32 a3);
s32 datGetPlayerLevel(void);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
bool dds3CheckDLC1(void);
bool dds3CheckDLC2(void);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
dds3Basic_t *dds3GetActiveScene(void);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void dds3SoftResetOff(void);
void dds3SoftResetOn(void);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void dds3VisibleSceneBasic(dds3Basic_t **basic, s32 visible);
bool evtBitCheck(s32 no);
void evtBitOn(s32 no);
s8 fclChkMessage(void);
s8 fclChkSelMessage(void);
s8 fclDestroyMessage(void);
s8 fclEndMessage(void);
s8 fclGetSelMessagePos(void);
s8 fclInitMessage(void *pData);
void fclSetMessageInvalid(s8 Mode);
s8 fclStartMessage(s32 MsgNo);
s8 fclStartSelMessage(s32 SelMsgNo);
void fclUpdateMessage(void);
s32 fileCheckEnd(NB_FILEHANDLE_T *fileHandle);
void *fileGetLoadPtr(fileCb_t *fileHandle);
s32 fileGetLoadSize(fileCb_t *fileHandle);
sdfMemHandle_t *fileGetMemHandle(fileHandle_t *fileHandle);
s32 fileHandleFree(fileHandle_t *fileHandle);
void fmShutDown(void);
_FRQ *frDestroyFontRequestAfter(_FRQ *pFRQ);
u8 frDisableMode(s8 Flag);
s32 frDrawFont(_FRQ *pFRQ);
s32 frDrawFontEx(_FRQ *pFRQ, s8 Mode);
s32 frDrawFontEx2(_FRQ *pFRQ, s8 Mode, u32 Ot);
u8 frEnableMode(s8 Flag);
char *frGetCNameString(s8 TargetNo);
void frSetDrawPosition(_FRQ *pFRQ, s32 X, s32 Y);
void frSetFontColor(_FRQ *pFRQ, u32 Color);
void frSetFontDrawOT(u32 OtType);
void frSetFontSpace(_FRQ *pFRQ, s32 Space);
_FRQ *frSetFontString(char *pStr, s8 Style, s8 ColNo, s8 Tp, _FRQ *pFRQ);
_FRQ *frwGetSmallFontFRQ_20602048(s32 X, s32 Y, s32 Pri, u32 Col, char *pStr, _FRQ *pFRQ, s32 ftype);
_FRQ *frwGetSmallNumFontFRQ_20603536(s32 X, s32 Y, s32 Pri, u32 Color, char *pStr, _FRQ *pFRQ);
void getPlayTimeToInt(s32 time, s32 ***getTime);
void loadHeaderGameFileInfo(FsSaveData *this, s32 num, GameFileInfo_t **data);
void mcMakeFileName(char **path, s32 num);
void p2sdPlaySeEx(s32 MidiNo, s32 aVolume, s32 pan);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
f32 sdfSin(f32 aRadius);
void *slBootTop(void);
void *slCancel(void);
s32 slCheckSaveData(s32 select);
void *slChooseData(void);
void *slChooseData_getCardInfoNext(void);
void *slDraw(dds3ProcessID_t *id);
s32 slDrawInfo(void);
void *slEndingExit(void);
void *slEndingTop(void);
void *slExitToTitle2(void);
void *slExitToTitleSub(void);
void *slExitWait(slMain_slExitWaitNextFuncDelegate *nextFunc);
void slFileListDispCheck(void);
void slFileListInit(void);
char *slFileLoadMsg(char *msg, s32 cnt);
void *slFileSel(void);
void *slFileSelDraw(dds3ProcessID_t *id);
void slKanjiDrawH(s32 x, s32 y, u32 rgba, char **moji);
void slLast(void);
s32 slQueryYesNoDraw(void);
void *slSaveData_writeFile(bool init);
void slScrollPositionTop(s32 top);
void slSetInfo(s32 id);
void *slSuspendInit(void);
void slTitleSet(s32 Code);
void *slTop(void);

// 0x15f2500
void EndingEventUnlock(s32 evtno) {
  ;
}

// 0x15f2510
void EndingStaffRollUnlock(void) {
  ;
}

// 0x15ee590
char *GetBasyoName(s32 fieldID, s32 nameU, s32 nameD) {
  System_String_o *result;

  result = StringLiteral_416;
  if (nameD == -1)
  {
    if (nameU >= 1)
    {
      return GetAreaName(fldNameData, fieldID, nameU);
    }
  }
  else if (nameD >= 1)
  {
    return GetBasyoName(fldNameData, fieldID, nameD);
  }
  return result;
}

// 0x15e9250
void SetupUI(void) {
  System_String_o *PlatformStr;
  System_String_o *v4;
  System_String_o *v5;
  System_String_o *v6;
  UnityEngine_Object_o *dataFileObj;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  Il2CppObject *p_obj;
  AssetBundleCtrl_o *v18;
  UnityEngine_GameObject_o *v20;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v24;
  UnityEngine_Object_o *saveUI;
  bool v29;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *saveTop;

  fclDestroyMessage();
  LoadLocalizeText(StringLiteral_4611, StringLiteral_22077);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_14667);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_22078);
  PlatformStr = GetPlatformStr();
  v4 = Concat_5224608(StringLiteral_4611, PlatformStr);
  v5 = GetPlatformStr();
  v6 = Concat_5224608(StringLiteral_22077, v5);
  LoadLocalizeText(v4, v6);
  if (op_Equality(dataFileObj, 0, 0))
  {
    if (gslMode == 5)
    {
      asset_bc = get_asset_bc();
      Prefab_16624656 = LoadPrefab_16624656(asset_bc, StringLiteral_4611, StringLiteral_5156, StringLiteral_22079);
      p_obj = &fileMesData->obj;
    }
    else
    {
      v18 = get_asset_bc();
      Prefab_16624656 = LoadPrefab_16624656(v18, StringLiteral_4611, StringLiteral_5156, StringLiteral_22080);
      p_obj = &loadMesData->obj;
    }
    fclInitMessage(p_obj);
    v20 = Find(StringLiteral_4905, 0);
    transform = get_transform(v20, 0);
    v24 = Instantiate_object__425664(Prefab_16624656, transform, 0);
    dataFileObj = v24;
    AddComponent_object_(dataFileObj);
  }
  saveUI = _saveUI;
  v29 = op_Equality(saveUI, 0, 0);
  if (v29)
  {
    Component_object = GetComponent_object_(dataFileObj);
    _saveUI = Component_object;
  }
  saveTop = _saveUI->_saveTop;
  cmpSetupObject(saveTop, 0);
  slInitalizeFlag = 0;
}

// 0x15f1c50
void fmProcTrigSequence(s32 mode, bool callDebug) {
  u64 *v5;
  slMain_c *v9;
  u64 *v10;
  u64 *v11;
  u64 *v12;
  s32 v13;
  u64 *v14;
  u64 *v15;
  struct GameFileInfo_t_o *GameFileInfo;
  u64 *v19;
  u64 *v20;
  u64 *v21;
  dds3Basic_t_o *basic;

  basic = 0;
  v5 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v5);
  dds3SoftResetOff();
  slDDS3To31Flg = 0;
  debugCall = callDebug;
  gslDrawFlagBg = 1;
  gSlEndingMode = 0;
  switch (mode)
  {
    case 0:
      v10 = Allocate(System_Func_dds3ProcessID_t__object_);
      object____ctor(
        v10,
        0,
        Method_slMain_slSaveProc1st__);
      slProcPtr = v10;
      mode = 0;
      gslDirMode = 0;
    case 1:
      v12 = Allocate(System_Func_dds3ProcessID_t__object_);
      object____ctor(
        v12,
        0,
        Method_slMain_slLoadProc1st__);
      slProcPtr = v12;
      gslDirMode = 0;
      mode = 1;
      if ((v9->_2.bitflags2 & 2) == 0)
    case 2:
      gSlEndingMode = 1;
      if (evtBitCheck(294))
      {
        if (evtBitCheck(3712))
          v13 = 2215;
        else
          v13 = 2214;
      }
      else if (evtBitCheck(149))
      {
        v13 = 2212;
      }
      else if (evtBitCheck(148))
      {
        v13 = 2213;
      }
      else if (evtBitCheck(146))
      {
        v13 = 2209;
      }
      else if (evtBitCheck(145))
      {
        v13 = 2211;
      }
      else
      {
        if (!evtBitCheck(147))
        v13 = 2210;
      }
      evtBitOn(v13);
      evtBitOn(2208);
      GameFileInfo = DDS3_GBWK->GameFileInfo;
      ++GameFileInfo->endcnt;
      DDS3_GBWK->GameFileInfo->newfile = 1;
      v19 = Allocate(System_Func_dds3ProcessID_t__object_);
      object____ctor(
        v19,
        0,
        Method_slMain_slEndingProc1st__);
      slProcPtr = v19;
      mode = 2;
      proc_func_ans = 0;
      v20 = Allocate(System_Func_dds3ProcessID_t__object_);
      object____ctor(
        v20,
        0,
        Method_slMain_slCalc__);
      v21 = Allocate(System_Func_dds3ProcessID_t__object_);
      object____ctor(
        v21,
        0,
        Method_slMain_slShutDownProcess__);
      dds3StartProcess(StringLiteral_22126, 0x2B0Au, 0, 0, v20, 0, v21, 0, 0, 0);
      slProcShutDownFlg = 1;
      dds3FadeIn(0, 0, 0, 8u);
      slSetInfo(0);
      gSlExitMode = 0;
      slExitWaitCnt = 0;
      gslSelTop = 0;
      gslSelect = -1;
      gslFlushCnt = 0;
      gslMode = mode;
      *&gslInfoLoadFlg = 1;
      gslErrorCode = 0;
      gslErrorKeyFlag = 0;
      gslDrawFlagFile = 0;
      gSlSaveMode = 0;
      gslCheckCardWait = 0;
      gslAnimCnt = 0;
      gSlSelCnt = 0;
      gSlNowCardCheck = 0;
      gSlFileSelKyeFlg = 0;
      gSlFileErroeFlg = 0;
      slQueryYesNoCursor = -1;
      slQueryYesNoMsg = 0;
      slQueryYesNoKeyFlag = 0;
      slInitalizeFlag = 0;
      gSlMcAccessCnt = 0;
      gSlWindowCnt = 0;
      basic = dds3GetActiveScene();
      if (basic)
      {
        dds3VisibleSceneBasic(&basic, 0);
      }
      return;
    case 3:
      v14 = Allocate(System_Func_dds3ProcessID_t__object_);
      object____ctor(
        v14,
        0,
        Method_slMain_slBootProc1st__);
      slProcPtr = v14;
      gslDrawFlagBg = 0;
      mode = 3;
      if ((v9->_2.bitflags2 & 2) == 0)
    case 4:
      mode = 1;
      slDDS3To31Flg = 1;
      v11 = Allocate(System_Func_dds3ProcessID_t__object_);
      object____ctor(
        v11,
        0,
        Method_slMain_slLoadProc1st__);
      slProcPtr = v11;
      gslDirMode = 1;
      if ((v9->_2.bitflags2 & 2) == 0)
    case 5:
      v15 = Allocate(System_Func_dds3ProcessID_t__object_);
      object____ctor(
        v15,
        0,
        Method_slMain_slLoadProc1st__);
      slProcPtr = v15;
      mode = 5;
      if ((v9->_2.bitflags2 & 2) == 0)
    default:
      if ((v9->_2.bitflags2 & 2) != 0)
  }
}

// 0x15f2380
s32 fmProcessChk(void) {
  return dds3SearchProcessName(StringLiteral_22126) != 0;
}

// 0x15f0a80
void fmShutDown(void) {
  slMain_c *v2;
  struct slMain_StaticFields *static_fields;
  slMain_c *v4;
  struct slMain_StaticFields *v5;
  struct slMain_StaticFields *v6;
  dds3Basic_t_o *basic;

  basic = 0;
  slHitAnyKeyNextFunc = 0;
  static_fields = v2->static_fields;
  if (static_fields->slProcShutDownFlg)
  {
    static_fields->slProcShutDownFlg = 0;
    v5 = slMain->static_fields;
    if (v5->hSlTex02)
    {
      v5->hSlTex02 = 0;
    }
    v6 = v4->static_fields;
    if (v6->hSlTex01)
    {
      v6->hSlTex01 = 0;
    }
    if (!dds3SearchProcessName(StringLiteral_16586))
    {
      basic = dds3GetActiveScene();
      if (basic)
      {
        dds3VisibleSceneBasic(&basic, 1);
      }
    }
    dds3KillProcessName(StringLiteral_22126, 1);
    dds3SoftResetOn();
  }
}

// 0x15f2370
s8 fmShutDown2(void) {
  return 1;
}

// 0x15f2360
void fmShutDownFade(void) {
  ;
}

// 0x15dfff0
void getPlayTimeToInt(s32 time, s32 ***getTime) {
  s32 v3;
  s32 v7;

  if (time >= 107998200)
    v3 = 107998200;
  else
    v3 = time;
  (*getTime)->m_Items[0] = v3 / 108000;
  (*getTime)->m_Items[1] = v3 % 108000;
  (*getTime)->m_Items[1] /= 1800;
  v7 = v3 % 1800;
  (*getTime)->m_Items[2] = v7;
  (*getTime)->m_Items[2] /= 30;
}

// 0x15e01f0
char *getPlayTimeToSting(s32 time) {
    getPlayTimeToInt(0, 0);
    return 0;
}

// 0x15eba10
void mcMakeFileName(char **path, s32 num) {
}

// 0x15f1910
s32 sl1Ken(void) {
  return 0;
}

// 0x15f13a0
void *slBootError(void) {
  u64 *v3;
  u64 *v4;
  u64 *v7;

  gslDrawFlagBg = 1;
  slSetInfo(0);
  slQueryYesNoMsg = 5;
  v3 = Allocate(slMain_slQueryYesFuncDelegate);
  _ctor(v3, 0, Method_slMain_slExitToTitle__, 0);
  v4 = Allocate(slMain_slQueryNoFuncDelegate);
  _ctor(v4, 0, Method_slMain_slBootRetry__, 0);
  slQueryYesFunc = v3;
  slQueryNoFunc = v4;
  slQueryYesNoCursor = 1;
  slQueryYesNoKeyFlag = 0;
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_slMain_slQueryYesNoProc__);
  return v7;
}

// 0x15f1530
void *slBootError2(void) {
  u64 *v3;
  u64 *v4;
  u64 *v7;

  gslDrawFlagBg = 1;
  slSetInfo(0);
  slQueryYesNoMsg = 6;
  v3 = Allocate(slMain_slQueryYesFuncDelegate);
  _ctor(v3, 0, Method_slMain_slExitToTitle__, 0);
  v4 = Allocate(slMain_slQueryNoFuncDelegate);
  _ctor(v4, 0, Method_slMain_slBootRetry__, 0);
  slQueryYesFunc = v3;
  slQueryNoFunc = v4;
  slQueryYesNoCursor = 1;
  slQueryYesNoKeyFlag = 0;
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_slMain_slQueryYesNoProc__);
  return v7;
}

// 0x15f18a0
void *slBootProc1st(dds3ProcessID_t *procId) {
  return slBootTop();
}

// 0x15ea690
void *slBootProc_CheckCard(dds3ProcessID_t *procId) {
  return 0;
}

// 0x15ea6a0
void *slBootProc_CheckCardR(dds3ProcessID_t *procId) {
  return 0;
}

// 0x15efdd0
void *slBootRetry(void) {
  u64 *v1;

  v1 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v1,
    0,
    Method_slMain_slBootProc_CheckCardR__);
  return v1;
}

// 0x15f12f0
void *slBootTop(void) {
  u64 *v2;

  slSetInfo(0);
  gslDrawFlagFile = 0;
  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_slMain_slBootProc_CheckCard__);
  return v2;
}

// 0x15e2650
void *slCalc(dds3ProcessID_t *id) {
    slDraw(0);
    fileCheckEnd(0);
    fileGetMemHandle(0);
    fileGetLoadPtr(0);
    fileGetLoadSize(0);
    fileHandleFree(0);
    slLast();
    return 0;
}

// 0x15ee420
void *slCancel(void) {
  u64 v2;
  s32 gslMode;
  dds3ProcessID_t_o *v4;
  u64 *v5;

  else
  {
    if (gslMode == 1)
  }
  if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
  {
    if (gslMode != 5)
    {
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      slSetInfo(0);
      v5 = Allocate(slMain_slExitWaitNextFuncDelegate);
      _ctor(v5, 0, Method_slMain_slExit__, 0);
      return slExitWait(v5);
    }
  }
  else  v4 = dds3SearchProcessName(StringLiteral_16586);
  if (v4)
  slExitToTitle2(v2);
  return 0;
}

// 0x15e99c0
void *slCardChk(void) {
  slSetInfo(1);
  gslErrorCode = 0;
  gslDrawFlagFile = 0;
  return slTop();
}

// 0x15e18b0
s32 slCheckSaveData(s32 select) {
    dds3CheckDLC1();
    dds3CheckDLC2();
    GetSuspendFieldArea(0, 0, 0);
    dds3CheckDLC6();
    dds3CheckDLC7();
    return 0;
}

// 0x15efdc0
s32 slChkWindowOpenDone(void) {
  return 1;
}

// 0x15ea5c0
void *slChooseData(void) {
  u64 *v3;

  slChooseSaveIndex = 0;
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_slMain_slChooseData_getCardInfo2__);
  return v3;
}

// 0x15eb250
void *slChooseData_B(void) {
  u64 *v3;

  slChooseSaveIndex = 0;
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_slMain_slChooseData_getCardInfo2_B__);
  return v3;
}

// 0x15eb1d0
void *slChooseData_getCardInfo(void) {
  u64 *v1;

  v1 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v1,
    0,
    Method_slMain_slChooseData_getCardInfo2__);
  return v1;
}

// 0x15ee6a0
void *slChooseData_getCardInfo2(dds3ProcessID_t *procId) {
  u64 *v2;

  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_slMain_slChooseData_getCardInfo3__);
  return v2;
}

// 0x15ee7f0
void *slChooseData_getCardInfo2_B(dds3ProcessID_t *procId) {
  return 0;
}

// 0x15ee720
void *slChooseData_getCardInfo3(dds3ProcessID_t *procId) {
  u64 *v2;

  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_slMain_slHeadLoadProc_openFile__);
  return v2;
}

// 0x15ee800
void *slChooseData_getCardInfo3_B(dds3ProcessID_t *procId) {
  return 0;
}

// 0x15ec570
void *slChooseData_getCardInfoNext(void) {
  u64 v2;
  s64 v3;
  s32 v4;
  s64 v5;
  u64 *v6;

  v3 = *(v2 + 184);
  v4 = *(v3 + 276) + 1;
  *(v3 + 276) = v4;
  v5 = *(v2 + 184);
  if (v4 != *(*(*(v5 + 64) + 56LL) + 24LL))
  {
    if ((*(v2 + 294) & 0x200) != 0 && !*(v2 + 216))
    {
      if ((byte_3F5A100 & 1) != 0)
    }
    else if ((byte_3F5A100 & 1) != 0)
    {
      v6 = Allocate(System_Func_dds3ProcessID_t__object_);
      object____ctor(
        v6,
        0,
        Method_slMain_slChooseData_getCardInfo2__);
      return v6;
    }
  }
  if ((*(v2 + 294) & 0x200) != 0 && !*(v2 + 216))
  {
    slChooseSaveIndex = 0;
  }
  else
  {
    *(v5 + 276) = 0;
  }
  return slFileSel(v2);
}

// 0x15ee810
void *slChooseData_getCardInfoNext_B(void) {
  return 0;
}

// 0x15eb320
void *slChooseData_getCardInfo_B(void) {
  u64 *v1;

  v1 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v1,
    0,
    Method_slMain_slChooseData_getCardInfo2_B__);
  return v1;
}

// 0x15ee340
void *slContinueYesNo(slMain_slQueryYesFuncDelegate *yesFunc, slMain_slQueryNoFuncDelegate *noFunc, s32 yesNoDefault) {
  u64 *v8;

  slQueryYesFunc = yesFunc;
  slQueryNoFunc = noFunc;
  slQueryYesNoCursor = yesNoDefault;
  slQueryYesNoKeyFlag = 0;
  ContinueProc = 1;
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_slMain_slContinueYesNoProc__);
  return v8;
}

// 0x15f06d0
void *slContinueYesNoProc(dds3ProcessID_t *procId) {
  slMain_c *v4;
  struct slMain_StaticFields **p_static_fields;
  struct slMain_StaticFields *static_fields;
  s32 ContinueProc;
  slMain_c *v10;
  struct slMain_StaticFields *v11;
  s32 v12;
  s32 SelMessagePos;
  slMain_c *v20;

  fclUpdateMessage();
  if (fclChkMessage())
    return 0;
  p_static_fields = &v4->static_fields;
  static_fields = v4->static_fields;
  ContinueProc = static_fields->ContinueProc;
  switch (ContinueProc)
  {
    case 3:
      static_fields->slQueryYesNoCursor = -1;
      (*p_static_fields)->slQueryYesNoMsg = 0;
      return Invoke((*p_static_fields)->slQueryYesFunc, 0);
    case 2:
      if (fclChkSelMessage())
        return 0;
      SelMessagePos = fclGetSelMessagePos();
      if (SelMessagePos != 1)
      {
        if (SelMessagePos)
          return 0;
        SelectYesSe = -1;
        fclEndMessage();
        ButtonGuideDispOff();
        dds3FadeOut(0, 0, 0, 0xFu);
        v11 = v20->static_fields;
        v12 = 3;
      }
      SelectYesSe = -1;
      ButtonGuideDispSet(StringLiteral_22081, 0, 0, 90);
      fclEndMessage();
      *&slQueryYesNoCursor = 0xFFFFFFFFLL;
      return Invoke(slQueryNoFunc, 0);
    case 1:
      SelectYesSe = 17;
      fclSetMessageInvalid(0);
      fclStartMessage(4);
      fclStartSelMessage(5);
      v11 = v10->static_fields;
      v12 = 2;
      v11->ContinueProc = v12;
      return 0;
    default:
      return 0;
  }
}

// 0x15e17d0
void slDLCMsgKill(void) {
    fmShutDown();
    ButtonGuideDispOff();
}

// 0x15e1590
void *slDLCMsgProc(void) {
  struct System_String_o *slSaveData_writeFile_wk_ptr;
  u64 *v4;
  struct slMain_StaticFields *static_fields;
  u64 *v8;

  gslSelect = -1;
  v4 = Allocate(slMain_slSaveWriteFile_endFuncDelegate);
  _ctor(v4, 0, Method_slMain_slSaveWriteEnd_baseIcon__, 0);
  static_fields = slMain->static_fields;
  slSaveWriteFile_buff = slSaveData_writeFile_wk_ptr;
  slSaveWriteFile_size = static_fields->slSaveData_writeFile_wk_size;
  slSaveWriteFile_endFunc = v4;
  slSaveWriteFile_dataWaitPtr = 0;
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_slMain_slSaveProc_openFile__);
  return v8;
}

// 0x15e28f0
void *slDraw(dds3ProcessID_t *id) {
  u64 v5;
  UnityEngine_Object_o *saveUI;
  UnityEngine_Object_o *announceObj;
  UnityEngine_GameObject_o *v12;

  rsetOtOfs(70);
  rsetAlpha(0);
  rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
  slFileListDispCheck();
  if (gslDrawFlagFile == 1)
  {
    slFileSelDraw(v5);
  }
  if ((*(v5 + 295) & 2) != 0 && !*(v5 + 216))
  {
    if (gslMode == 5)
  }
  else  if ((*(v5 + 295) & 2) != 0 && !*(v5 + 216))
  v6 = slDrawInfo(v5);
  if (slQueryYesNoDraw() | v6)
  saveUI = _saveUI;
  if (!op_Inequality(saveUI, 0, 0))
  announceObj = _saveUI->_announceObj;
  v12 = _saveUI->_announceObj;
  cmpSetupObject(v12, 0);
  {
  }
  rsetAlpha(0);
  rsetTest(1, 5, 128, 3, 0, 0, 1, 2);
  return 0;
}

// 0x15e90b0
void slDrawError(void) {
  ;
}

// 0x15e77c0
s32 slDrawInfo(void) {
    GetLocalizeText(0);
    RepColTag(0, 0);
    slKanjiDrawH(0, 0, 0, 0);
    return 0;
}

// 0x15efe50
s32 slDrawWindow(void) {
  return 1;
}

// 0x15e9710
void *slEnd(dds3ProcessID_t *id) {
  id->func_ans = -1;
  slLast();
  return 0;
}

// 0x15ea390
void *slEndingExit(void) {
  u64 *v5;
  u64 *v6;
  u64 *v9;

  slSetInfo(0);
  gslErrorCode = 0;
  gslDrawFlagFile = 0;
  slQueryYesNoMsg = 8;
  init_flag = 1;
  v5 = Allocate(slMain_slQueryYesFuncDelegate);
  _ctor(v5, 0, Method_slMain_slExitToTitle__, 0);
  v6 = Allocate(slMain_slQueryNoFuncDelegate);
  _ctor(v6, 0, Method_slMain_slEndingTop__, 0);
  slQueryYesFunc = v5;
  slQueryNoFunc = v6;
  slQueryYesNoCursor = 1;
  slQueryYesNoKeyFlag = 0;
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_slMain_slQueryYesNoProc__);
  return v9;
}

// 0x15f1830
void *slEndingProc1st(dds3ProcessID_t *procId) {
    SetupUI();
    slEndingTop();
    return 0;
}

// 0x15f1160
void *slEndingTop(void) {
  u64 *v4;
  u64 *v5;
  u64 *v8;

  gslMode = 0;
  slSetInfo(0);
  gslErrorCode = 0;
  gslDrawFlagFile = 0;
  slQueryYesNoMsg = 4;
  v4 = Allocate(slMain_slQueryYesFuncDelegate);
  _ctor(v4, 0, Method_slMain_slTop__, 0);
  v5 = Allocate(slMain_slQueryNoFuncDelegate);
  _ctor(v5, 0, Method_slMain_slEndingExit__, 0);
  slQueryYesFunc = v4;
  slQueryNoFunc = v5;
  slQueryYesNoCursor = 0;
  slQueryYesNoKeyFlag = 0;
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_slMain_slQueryYesNoProc__);
  return v8;
}

// 0x15ea140
void *slEndingUpd2(void) {
  u64 *v3;
  u64 *v4;
  u64 *v7;

  slSetInfo(0);
  gslErrorCode = 0;
  slQueryYesNoMsg = 9;
  v3 = Allocate(slMain_slQueryYesFuncDelegate);
  _ctor(v3, 0, Method_slMain_slSaveData__, 0);
  v4 = Allocate(slMain_slQueryNoFuncDelegate);
  _ctor(v4, 0, Method_slMain_slFileSel__, 0);
  slQueryYesFunc = v3;
  slQueryNoFunc = v4;
  slQueryYesNoCursor = 1;
  slQueryYesNoKeyFlag = 0;
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_slMain_slQueryYesNoProc__);
  return v7;
}

// 0x15ea6c0
void *slErrorWait(dds3ProcessID_t *procId) {
  bool v4;
  bool v5;

  v4 = DDS3_PADCHECK_TRIG(1);
  if (v4)
  {
    else  }
  v5 = DDS3_PADCHECK_TRIG(3);
  if (!v5)
    return 0;
  if (slProcShutDownFlg != 1)
    return 0;
  p2sdPlaySeEx(8, 127, 63);
  HIDWORD(v7[2].klass->vtable[4].method) = 0;
  v7[2].klass->_2.instance_size = 0;
  return slTop();
}

// 0x15ea6b0
void *slErrorWaitMc(dds3ProcessID_t *procId) {
  return 0;
}

// 0x15f1930
void *slErrorWaitToFileMc(dds3ProcessID_t *procId) {
  return 0;
}

// 0x15e9780
void *slExit(void) {
  u64 *v3;

  slSetInfo(0);
  gslDrawFlagFile = 0;
  gslDrawFlagBg = 0;
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_slMain_slEnd__);
  return v3;
}

// 0x15e9830
void *slExitToTitle(void) {
  slExitToTitleSub();
  return 0;
}

// 0x15f16c0
void *slExitToTitle2(void) {
    dds3SearchProcessName(0);
    dds3AdminiCallSequence(0, 0, 0, 0);
    return 0;
}

// 0x15e98a0
void *slExitToTitleSub(void) {
    dds3SearchProcessName(0);
    dds3AdminiCallSequence(0, 0, 0, 0);
    return 0;
}

// 0x15eb0e0
void *slExitWait(slMain_slExitWaitNextFuncDelegate *nextFunc) {
  u64 *v5;

  dds3FadeOut(0, 0, 0, 0xFu);
  slExitWaitNextFunc = nextFunc;
  slExitWaitCnt = 20;
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_slMain_slExitWaitProc__);
  return v5;
}

// 0x15e1e30
void *slExitWaitProc(dds3ProcessID_t *procId) {
  u64 v3;
  struct slMain_StaticFields *static_fields;

  --*(*(v3 + 184) + 144LL);
  static_fields = *(v3 + 184);
  if (static_fields->slExitWaitCnt > 0)
    return 0;
  if (procId->func_ans == -1)
  {
    if ((*(v3 + 294) & 0x200) != 0 && !*(v3 + 216))
    slLast(v3);
    return 0;
  }
  else
  {
    if ((*(v3 + 294) & 0x200) != 0 && !*(v3 + 216))
    {
      static_fields = slMain->static_fields;
    }
    return Invoke(static_fields->slExitWaitNextFunc, 0);
  }
}

// 0x15dfcf0
void slFileListDispCheck(void) {
}

// 0x15df9f0
void slFileListInit(void) {
}

// 0x15efff0
char *slFileLoadMsg(char *msg, s32 cnt) {
  u64 *v5;
  System_String_array *v16;
  System_String_array *v18;
  u32 *v19;
  s32 v20;
  u32 v21;
  u32 *v22;
  s32 v23;
  System_String_o *v24;
  s64 v25;
  s64 v27;
  System_String_o *v29;

  v5 = NewSpecific(string, 0xAu);
  v5[4] = StringLiteral_5824;
  v5[5] = StringLiteral_5825;
  v5[6] = StringLiteral_5826;
  v5[7] = StringLiteral_5827;
  v5[8] = StringLiteral_5828;
  v5[9] = StringLiteral_5829;
  v5[10] = StringLiteral_5830;
  v5[11] = StringLiteral_5831;
  v5[12] = StringLiteral_5832;
  v5[13] = StringLiteral_5833;
  v16 = NewSpecific(string, 1u);
  v16->m_Items[0] = StringLiteral_22110;
  v18 = Split_5246672(msg, v16, 0);
  v19 = NewSpecific(s32, 2u);
  v20 = cnt / 10;
  v21 = v19[6];
  v22 = v19;
  v23 = cnt % 10;
  v19[8] = v20;
  v19[9] = v23;
  v24 = v18->m_Items[0];
  if (v19[8])
  {
    v25 = v19[8];
    v24 = Concat_5224608(v18->m_Items[0], v5[v25 + 4]);
  }
  v27 = v22[9];
  v29 = Concat_5224608(v24, v5[v27 + 4]);
  return Concat_5224608(v29, v18->m_Items[1]);
}

// 0x15e9a40
void *slFileSel(void) {
  s32 gslMode;
  s32 v5;
  u64 v6;
  u64 v7;
  s32 v8;
  s64 parent;
  s16 v10;
  s32 i;
  s64 v12;
  struct System_Int32_array *gslStatFileInfo;
  struct GameFileInfo_t_array *gslInfo;
  struct System_Int32_array *v18;
  struct GameFileInfo_t_array *v20;
  struct GameFileInfo_t_array *v23;
  Il2CppClass **v25;
  s16 v26;
  s32 v27;
  struct slMain_StaticFields *static_fields;
  struct slMain_StaticFields **p_static_fields;
  struct slMain_StaticFields *v30;
  s32 gslSelTop;
  s32 gslSelect;
  u64 *v33;

  slSetInfo(0);
  if (!gslMode)
  {
    v5 = 11;
  }
  if (gslMode != 5)
  {
    v5 = 12;
    slTitleSet(v5);
  }
  *(*(v6 + 184) + 236LL) = 0;
  v7 = 0;
  v8 = 0;
  parent = 0;
  *(*(v6 + 184) + 260LL) = 0;
  v10 = *(v6 + 294);
  if ((v10 & 0x200) != 0)
  for (i = 0; ; i = v10 & 0x200)
  {
    v12 = *(v6 + 184);
    if (v7 >= *(*(*(v12 + 64) + 56LL) + 24LL))
      break;

    {
      gslStatFileInfo = *(v12 + 320);
      if (v7 >= LODWORD(gslStatFileInfo->max_length))
    }
    gslStatFileInfo->m_Items[v7] = 0;
    if (gslInfo->m_Items[v7]->PlayTime >= 1)
    {
      v18 = gslStatFileInfo;
      v18->m_Items[v7] = 1;
      v20 = gslInfo;
      if (parent <= v20->m_Items[v7]->saveTime)
      {
        v23 = gslInfo;
        v25 = &v23->obj.klass + v7;
        v8 = v7;
        parent = v25[4]->_1.parent;
      }
    }
    ++v7;
    if ((v10 & 0x200) == 0)
  }
  if (!i || *(v6 + 216))
  {
    if (*(v12 + 312))
    if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
    slFileListInit(v6);
    slInitalizeFlag = 1;
    v26 = *(v6 + 294);
    if ((v26 & 0x200) == 0)
  }
  if (!slInitalizeFlag)
  v26 = *(v6 + 294);
  if ((v26 & 0x200) == 0)
  {
    v27 = 0;
  }
  v27 = v26 & 0x200;
  p_static_fields = (v6 + 184);
  static_fields = *(v6 + 184);
  if (static_fields->gslMode == 5)
  {
    if (v27 && !*(v6 + 216))
    {
      static_fields = slMain->static_fields;
    }
    static_fields->gslSelect = 0;
  }
  if (v27 && !*(v6 + 216))
  {
    p_static_fields = &slMain->static_fields;
    static_fields = slMain->static_fields;
    if ((static_fields->gslSelect & 0x80000000) == 0)
  }
  else  if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
  {
    p_static_fields = &slMain->static_fields;
    static_fields = slMain->static_fields;
  }
  static_fields->gslSelect = v8;
  v30 = *p_static_fields;
  gslSelTop = (*p_static_fields)->gslSelTop;
  gslSelect = (*p_static_fields)->gslSelect;
  if (gslSelTop <= gslSelect)
  {
    if ((*(v6 + 294) & 0x200) != 0 && !*(v6 + 216))
    {
      v30 = slMain->static_fields;
      gslSelTop = v30->gslSelTop;
      gslSelect = v30->gslSelect;
    }
    if (gslSelTop + 3 >= gslSelect)
    if ((*(v6 + 295) & 2) != 0 && !*(v6 + 216))
    {
      v30 = slMain->static_fields;
      gslSelect = v30->gslSelect;
    }
    gslSelect -= 3;
  }
  else if ((*(v6 + 294) & 0x200) != 0 && !*(v6 + 216))
  {
    v30 = slMain->static_fields;
    gslSelect = v30->gslSelect;
  }
  v30->gslSelTop = gslSelect;
  slScrollPositionTop(*(*(v6 + 184) + 344LL));
  v33 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v33,
    0,
    Method_slMain_slFileSelCalc__);
  return v33;
}

// 0x15ecb30
void *slFileSelCalc(dds3ProcessID_t *id) {
    ButtonGuideDispSet(0, 0, 0, 0);
    DDS3_PADCHECK_REP(0);
    p2sdPlaySeEx(0, 0, 0);
    DDS3_PADCHECK_TRIG(0);
    slCheckSaveData(0);
    slTop();
    slSetInfo(0);
    slFileSel();
    ButtonGuideDispOff();
    fclSetMessageInvalid(0);
    fclStartMessage(0);
    fclUpdateMessage();
    fclChkMessage();
    fclEndMessage();
    slEndingExit();
    slCancel();
    return 0;
}

// 0x15e2bc0
void *slFileSelDraw(dds3ProcessID_t *id) {
    sdfSin(0);
    rsetOtOfs(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    rsetAlpha(0);
    aDrawBoxF(0, 0, 0, 0, 0, 0, 0, 0);
    DrwSprite2D_17010048(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    aDrawBoxG(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    slScrollPositionTop(0);
    GetToRGBA(0);
    Set(0, 0);
    GetLocalizeText(0);
    RepColTag(0, 0);
    GetSaveSmlName(0, 0);
    GetSaveNmlName(0, 0);
    GetSuspendFieldArea(0, 0, 0);
    GetSuspendDispName(0, 0, 0);
    GetFieldName(0, 0);
    GetAreaName(0, 0, 0);
    getPlayTimeToInt(0, 0);
    return 0;
}

// 0x15ec030
void *slFormatCancel(void) {
  s32 v3;
  struct slMain_StaticFields *static_fields;
  u64 *v5;
  intptr_t *v6;
  u64 *v7;
  u64 *v8;
  u64 *v11;

  {
    else
    {
      static_fields = slMain->static_fields;
      if (!static_fields->gSlEndingMode)
    }
    static_fields->slQueryYesNoMsg = 7;
    v5 = Allocate(slMain_slQueryYesFuncDelegate);
    v6 = &Method_slMain_slEndingExit__;
  }
  v3 = 0;
  static_fields = slMain->static_fields;
  if (static_fields->gSlEndingMode)
  static_fields->slQueryYesNoMsg = 7;
  v5 = Allocate(slMain_slQueryYesFuncDelegate);
  v6 = &Method_slMain_slExit__;
  v7 = v5;
  _ctor(v5, 0, *v6, 0);
  v8 = Allocate(slMain_slQueryNoFuncDelegate);
  _ctor(v8, 0, Method_slMain_slTop__, 0);
  slQueryYesFunc = v7;
  slQueryNoFunc = v8;
  slQueryYesNoCursor = 1;
  slQueryYesNoKeyFlag = 0;
  v11 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v11,
    0,
    Method_slMain_slQueryYesNoProc__);
  return v11;
}

// 0x15ebfb0
void *slFormatStart(void) {
  u64 *v1;

  v1 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v1,
    0,
    Method_slMain_slProc_Format__);
  return v1;
}

// 0x15e96a0
s32 slGetExitMode(void) {
  return gSlExitMode;
}

// 0x15f2400
s32 slGetExitType(void) {
  return gslExitType;
}

// 0x15f1080
s32 slGetInfo(void) {
  return gslInfoCode;
}

// 0x15ee2b0
s32 slGetPadRep(bool map) {
  if (!map)
    return 0;
  return slProcShutDownFlg == 1;
}

// 0x15ea930
s32 slGetPadTrig(bool map) {
  if (!map)
    return 0;
  return slProcShutDownFlg == 1;
}

// 0x15ec220
void *slHeadLoad(void) {
  u64 *v1;

  v1 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v1,
    0,
    Method_slMain_slHeadLoadProc_openFile__);
  return v1;
}

// 0x15ec3a0
void *slHeadLoadProc_closeFile(dds3ProcessID_t *procId) {
    loadHeaderGameFileInfo(0, 0, 0);
    slChooseData_getCardInfoNext();
    return 0;
}

// 0x15ec2a0
void *slHeadLoadProc_openFile(dds3ProcessID_t *procId) {
  u64 *v2;

  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_slMain_slHeadLoadProc_readFile__);
  return v2;
}

// 0x15ec320
void *slHeadLoadProc_readFile(dds3ProcessID_t *procId) {
  u64 *v2;

  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_slMain_slHeadLoadProc_closeFile__);
  return v2;
}

// 0x15ea9c0
void *slHitAnyKey(slMain_slHitAnyKeyNextFuncDelegate *nextFunc) {
  u64 *v4;

  slHitAnyKeyNextFunc = nextFunc;
  gslErrorKeyFlag = 0;
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_slMain_slHitAnyKeyProc__);
  return v4;
}

// 0x15ead50
void *slHitAnyKeyNoChk(slMain_nextFuncDelegate *nextFunc) {
  u64 *v3;

  gslErrorKeyFlag = 0;
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_slMain_slHitAnyKeyNoChkProc__);
  return v3;
}

// 0x15eadf0
void *slHitAnyKeyNoChkProc(dds3ProcessID_t *procId) {
  bool v4;
  bool v6;
  u64 v8;
  slMain_slHitAnyKeyNextFuncDelegate_o *slHitAnyKeyNextFunc;

  v4 = DDS3_PADCHECK_TRIG(1);
  if (v4)
  {
    else  }
  v6 = DDS3_PADCHECK_TRIG(3);
  if (v6)
  {
    else  }
  else if (gslMode != 5)
  {
    return 0;
  }
  slSetInfo(0);
  gslErrorCode = 0;
  *(*(v8 + 184) + 236LL) = 0;
  if (procId->func_ans != -1)
  {
    if ((*(v8 + 294) & 0x200) != 0 && !*(v8 + 216))
    {
      if (slHitAnyKeyNextFunc)
    }
    else
    {
      slHitAnyKeyNextFunc = *(*(v8 + 184) + 152LL);
      if (slHitAnyKeyNextFunc)
      {
        return Invoke(slHitAnyKeyNextFunc, 0);
      }
    }
    procId->func_ans = -1;
    if ((*(v8 + 295) & 2) != 0 && !*(v8 + 216))
    slLast(v8);
    return 0;
  }
  if ((*(v8 + 294) & 0x200) != 0 && !*(v8 + 216))
  return slExitWait(0);
}

// 0x15eaa70
void *slHitAnyKeyProc(dds3ProcessID_t *procId) {
  bool v6;
  bool v7;
  slMain_c *v12;
  struct slMain_StaticFields *static_fields;

  else if (gslErrorKeyFlag)
  {
    return 0;
  }
  v6 = DDS3_PADCHECK_TRIG(1);
  if (v6)
  {
    else  }
  v7 = DDS3_PADCHECK_TRIG(3);
  if (!v7)
    return 0;
  if (slProcShutDownFlg != 1)
    return 0;
  p2sdPlaySeEx(8, 127, 63);
  gslErrorKeyFlag = 1;
  slSetInfo(0);
  gslErrorCode = 0;
  gslDrawFlagFile = 0;
  static_fields = v12->static_fields;
  if (static_fields->gslSelect == 20)
  {
    procId->func_ans = -1;
    return 0;
  }
  return Invoke(static_fields->slHitAnyKeyNextFunc, 0);
}

// 0x15f0e80
void slKanjiDraw(s32 x, s32 y, u32 rgba, char *moji) {
  _FRQ_o *SmallFontFRQ_20602048;
  _FRQ_o *slKanjiDraw_handle;

  SmallFontFRQ_20602048 = frwGetSmallFontFRQ_20602048(16 * (x * 3.75), 16 * (y * 2.25), 0, rgba, moji, 0, -1, 0);
  slKanjiDraw_handle = SmallFontFRQ_20602048;
  frDrawFont(slKanjiDraw_handle);
  frDestroyFontRequestAfter(slKanjiDraw_handle);
}

// 0x15efe60
void slKanjiDrawH(s32 x, s32 y, u32 rgba, char **moji) {
  s32 v9;
  _FRQ_o *v11;

  v9 = (x * 3.75);
  frEnableMode(1);
  v11 = frSetFontString(*moji, 0, 0, 0, 0);
  slKanjiDrawH_handle = v11;
  frDisableMode(1);
  frSetFontSpace(slKanjiDrawH_handle, 1);
  frSetDrawPosition(slKanjiDrawH_handle, 16 * v9, 16 * (y * 2.25), 0);
  frSetFontColor(slKanjiDrawH_handle, rgba);
  frDrawFontEx2(slKanjiDrawH_handle, 0, 0x4Au);
  frDestroyFontRequestAfter(slKanjiDrawH_handle);
  frSetFontDrawOT(0x48u);
}

// 0x15f0fa0
void slKanjiDrawN(s32 x, s32 y, u32 rgba, char **moji) {
  _FRQ_o *SmallNumFontFRQ_20603536;

  SmallNumFontFRQ_20603536 = frwGetSmallNumFontFRQ_20603536(
                               16 * (x * 3.75),
                               16 * (y * 2.25),
                               0,
                               rgba,
                               *moji,
                               0,
                               0);
  frDrawFontEx(SmallNumFontFRQ_20603536, 1);
  frDestroyFontRequestAfter(SmallNumFontFRQ_20603536);
}

// 0x15e1f20
void slLast(void) {
  UnityEngine_Object_o *dataFileObj;
  System_String_o *PlatformStr;
  System_String_o *v7;

  if (_baseFlagSlMain)
  {
    CampBaseOn(kernelObject);
  }
  _baseFlagSlMain = 0;
  Destroy_27360000(dataFileObj);
  Remove(StringLiteral_22077, 0);
  Remove(StringLiteral_14667, 0);
  Remove(StringLiteral_22078, 0);
  PlatformStr = GetPlatformStr();
  v7 = Concat_5224608(StringLiteral_22077, PlatformStr);
  Remove(v7, 0);
  if (debugCall)
  {
    dds3FadeIn(0x40u, 0x40u, 0x40u, 0x1Eu);
  }
  else
  {
    if (gSlExitMode == 2)
    {
      dds3FadeOut(0, 0, 0, 0);
    }
  }
  else
  {
    fclDestroyMessage();
  }
}

// 0x15ec6b0
void *slLoadData(void) {
  u64 *v1;

  v1 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v1,
    0,
    Method_slMain_slLoadProc_openFile__);
  return v1;
}

// 0x15e21b0
void *slLoadProc1st(dds3ProcessID_t *procId) {
  return slTop();
}

// 0x15ec980
void *slLoadProc_closeFile(dds3ProcessID_t *procId) {
  u64 *v7;

  gfldTitleMiniID = 0;
  cfgCopyFlagGblToBak();
  slSetInfo(13);
  if (gslMode == 5)
  {
    return slSuspendInit();
  }
  gslErrorKeyFlag = 0;
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_slMain_slHitAnyKeyNoChkProc__);
  return v7;
}

// 0x15ec730
void *slLoadProc_openFile(dds3ProcessID_t *procId) {
    Load_18090368(0, 0, 0, 0);
    return 0;
}

// 0x15ec900
void *slLoadProc_readFile(dds3ProcessID_t *procId) {
  u64 *v2;

  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_slMain_slLoadProc_closeFile__);
  return v2;
}

// 0x15f0ca0
void slMcAccessDraw(void) {
  ;
}

// 0x15f0cb0
void slNextPageDraw(void) {
  ;
}

// 0x15e90c0
void *slNoCard(void) {
  u64 *v3;

  slSetInfo(0);
  gslErrorCode = 1;
  gslErrorKeyFlag = 0;
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_slMain_slErrorWaitMc__);
  return v3;
}

// 0x15ebe80
void *slProc_Format(dds3ProcessID_t *procId) {
  u64 *v2;
  u64 *v5;

  v2 = Allocate(slMain_slHitAnyKeyNextFuncDelegate);
  _ctor(v2, 0, Method_slMain_slCardChk__, 0);
  slHitAnyKeyNextFunc = v2;
  gslErrorKeyFlag = 0;
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_slMain_slHitAnyKeyProc__);
  return v5;
}

// 0x15ea2c0
void *slQueryYesNo(slMain_slQueryYesFuncDelegate *yesFunc, slMain_slQueryNoFuncDelegate *noFunc, s32 yesNoDefault) {
  u64 *v8;

  slQueryYesFunc = yesFunc;
  slQueryNoFunc = noFunc;
  slQueryYesNoCursor = yesNoDefault;
  slQueryYesNoKeyFlag = 0;
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_slMain_slQueryYesNoProc__);
  return v8;
}

// 0x15e8270
s32 slQueryYesNoDraw(void) {
    ButtonGuideDispSet(0, 0, 0, 0);
    rsetOtOfs(0);
    rsetAlpha(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    GetLocalizeText(0);
    RepColTag(0, 0);
    slKanjiDrawH(0, 0, 0, 0);
    slFileLoadMsg(0, 0);
    return 0;
}

// 0x15ee820
void *slQueryYesNoProc(dds3ProcessID_t *procId) {
    DDS3_PADCHECK_TRIG(0);
    p2sdPlaySeEx(0, 0, 0);
    return 0;
}

// 0x15eb3a0
void *slSaveData(void) {
  u64 *v1;

  v1 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v1,
    0,
    Method_slMain_slSaveProc_Write_mkdir__);
  return v1;
}

// 0x15eb420
void *slSaveData_chdir(void) {
  u64 *v1;

  v1 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v1,
    0,
    Method_slMain_slSaveProc_Write_chdir__);
  return v1;
}

// 0x15eb630
void *slSaveData_deleteIconSys(void) {
  return slSaveData_writeFile(0);
}

// 0x15e0640
void *slSaveData_writeFile(bool init) {
    mcMakeFileName(0, 0);
    datGetPlayerLevel();
    evtBitCheck(0);
    frGetCNameString(0);
    return 0;
}

// 0x15e25e0
void *slSaveProc1st(dds3ProcessID_t *procId) {
  v2[2].klass->rgctx_data = 0;
  return slTop();
}

// 0x15ea550
void *slSaveProc_CheckCard(dds3ProcessID_t *procId) {
  return slChooseData();
}

// 0x15eb570
void *slSaveProc_Write_chdir(dds3ProcessID_t *procId) {
  return slSaveData_writeFile(0);
}

// 0x15eb6a0
void *slSaveProc_Write_deleteIconSys(dds3ProcessID_t *procId) {
  return 0;
}

// 0x15eb4a0
void *slSaveProc_Write_mkdir(dds3ProcessID_t *procId) {
  u64 *v2;

  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_slMain_slSaveProc_Write_chdir__);
  return v2;
}

// 0x15f1b10
void *slSaveProc_closeFile(dds3ProcessID_t *procId) {
  return Invoke(slSaveWriteFile_endFunc, 0);
}

// 0x15eb6b0
void *slSaveProc_doNothing(dds3ProcessID_t *procId) {
  u64 *v2;
  u64 *v5;

  slSetInfo(4);
  v2 = Allocate(slMain_slHitAnyKeyNextFuncDelegate);
  _ctor(v2, 0, Method_slMain_slFileSel__, 0);
  slHitAnyKeyNextFunc = v2;
  gslErrorKeyFlag = 0;
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_slMain_slHitAnyKeyProc__);
  return v5;
}

// 0x15f1940
void *slSaveProc_openFile(dds3ProcessID_t *procId) {
  u64 *v3;
  intptr_t *v4;
  FsSaveData_o *saveData;
  Il2CppObject *v7;

  else if (slSaveWriteFile_dataWaitPtr)
  {
    v3 = Allocate(System_Func_dds3ProcessID_t__object_);
    v4 = &Method_slMain_slSaveProc_waitDataReady__;
  }
  Save(
    saveData,
    gslSelect,
    dds3Work,
    saveDataInit,
    0);
  gslDrawFlagFile = 1;
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  v4 = &Method_slMain_slSaveProc_writeFile__;
  v7 = v3;
  object____ctor(v3, 0, *v4);
  return v7;
}

// 0x15f1b80
void *slSaveProc_waitDataReady(dds3ProcessID_t *procId) {
  u64 *v3;

  else if (baseIconFileHandle)
  {
    return 0;
  }
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_slMain_slSaveProc_writeFile__);
  return v3;
}

// 0x15f1a90
void *slSaveProc_writeFile(dds3ProcessID_t *procId) {
  u64 *v2;

  v2 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v2,
    0,
    Method_slMain_slSaveProc_closeFile__);
  return v2;
}

// 0x15eb850
void *slSaveWriteEnd_baseIcon(void) {
  u64 *v1;

  v1 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v1,
    0,
    Method_slMain_slSaveProc_doNothing__);
  return v1;
}

// 0x15eb7d0
void *slSaveWriteEnd_iconSys(void) {
  u64 *v1;

  v1 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v1,
    0,
    Method_slMain_slSaveProc_doNothing__);
  return v1;
}

// 0x15eb8d0
void *slSaveWriteEnd_saveData(void) {
  u64 *v4;
  intptr_t *v5;
  Il2CppObject *v6;

  if (gslMode != 5)
  gslErrorKeyFlag = 0;
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  v5 = &Method_slMain_slHitAnyKeyNoChkProc__;
  v6 = v4;
  object____ctor(v4, 0, *v5);
  return v6;
}

// 0x15e16f0
void *slSaveWriteFile(char *filename, char *buff, s32 *size, slMain_slSaveWriteFile_endFuncDelegate *endFunc, void *srcPtr) {
  u64 *v11;

  slSaveWriteFile_buff = buff;
  slSaveWriteFile_size = *size;
  slSaveWriteFile_endFunc = endFunc;
  slSaveWriteFile_dataWaitPtr = srcPtr;
  v11 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v11,
    0,
    Method_slMain_slSaveProc_openFile__);
  return v11;
}

// 0x15df760
void slScrollPositionSet(s32 index) {
  UnityEngine_Transform_o *transform;
  UnityEngine_RectTransform_o *v5;
  f32 y;
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_RectTransform_o *v8;
  f32 v10;
  UnityEngine_Transform_o *v11;
  f32 v13;
  f32 v14;
  f32 v16;

  transform = get_transform(_saveUI->_scrollRect, 0);
  if (transform)
  {
    if (transform->klass == UnityEngine_RectTransform)
      v5 = transform;
    else
      v5 = 0;
  }
  else
  {
    v5 = 0;
  }
  y = get_sizeDelta(v5).y;
  Component_GUILayer = GetComponent_GUILayer_(v5);
  v8 = get_transform(_saveUI->_scrollcontent, 0);
  if (v8 && v8->klass != UnityEngine_RectTransform)
    v8 = 0;
  v16 = get_sizeDelta(v8).y;
  if (v16 <= y)
  {
    v14 = 1.0;
  }
  else
  {
    v10 = v16;
    v11 = get_transform(_saveUI->_scrollcontent, 0);
    v13 = (((index + 0.5) / get_childCount(v11)) - ((y * 0.5) / v10)) / (1.0 - (y / v10));
    v14 = Clamp(1.0 - v13, 0.0, 1.0);
  }
  set_verticalNormalizedPosition(Component_GUILayer, v14);
}

// 0x15df930
void slScrollPositionTop(s32 top) {
  UnityEngine_Component_o *transform;
  UnityEngine_GUILayer_o *Component_GUILayer;

  transform = get_transform(_saveUI->_scrollRect, 0);
  if (transform && transform->klass != UnityEngine_RectTransform)
    transform = 0;
  Component_GUILayer = GetComponent_GUILayer_(transform);
  set_verticalNormalizedPosition(Component_GUILayer, (top * -0.0625) + 1.0, 0);
}

// 0x15e9180
void slSetInfo(s32 id) {
}

// 0x15f10f0
void slSetKayWait(void) {
  slProcShutDownFlg = 1;
}

// 0x15f2470
void slSetTmnlID(s32 type, s32 id) {
  s16 v3;
  s16 v4;

  v3 = id;
  v4 = type;
  DDS3_GBWK->fldSave->tmnltype = v4;
  DDS3_GBWK->fldSave->tmnlid = v3;
}

// 0x15e1400
dds3ProcessID_t *slShutDownProcess(dds3ProcessID_t *id) {
  fmShutDown();
  ButtonGuideDispOff();
  return 0;
}

// 0x15f1920
s32 slSizeChk(void) {
  return 1;
}

// 0x15e0350
bool slSuspendDataCheck(void) {
  struct GameFileInfo_t_array *gslInfo;
  struct GameFileInfo_t_array *v6;
  u64 *v7;
  GlobalData_c *v10;
  struct GlobalData_StaticFields *static_fields;
  FsSaveData_o *saveData;
  struct GameFileInfo_t_array *v14;
  struct GameFileInfo_t_array *v16;

  if (!gslInfo->m_Items[20])
  {
    v6 = gslInfo;
    v7 = Allocate(GameFileInfo_t);
    GameFileInfo_t___ctor(v7);
    v6->m_Items[20] = v7;
  }
  static_fields = v10->static_fields;
  saveData = static_fields->saveData;
  v14 = gslInfo;
  loadHeaderGameFileInfo(saveData, 20, &v14->m_Items[20]);
  v16 = gslInfo;
  return v16->m_Items[20]->PlayTime > 0;
}

// 0x15e1490
void *slSuspendInit(void) {
  slMain_c *v2;
  struct slMain_StaticFields *static_fields;
  struct GameFileInfo_t_array *gslInfo;
  s64 gslSelect;
  u64 *v6;

  gslSelect = 20;
  static_fields = v2->static_fields;
  gslInfo = static_fields->gslInfo;
  gslSelect = static_fields->gslSelect;
  v6 = Allocate(GameFileInfo_t);
  GameFileInfo_t___ctor(v6);
  gslInfo->m_Items[gslSelect] = v6;
  return slSaveData_writeFile(1);
}

// 0x15e1320
void slSuspendKill(void) {
    fmShutDown();
    ButtonGuideDispOff();
}

// 0x15e0530
void *slSuspendProc(void) {
  slMain_c *v2;
  struct slMain_StaticFields *static_fields;
  struct GameFileInfo_t_array *gslInfo;
  s64 gslSelect;
  u64 *v6;

  gslMode = 0;
  gslSelect = 20;
  static_fields = v2->static_fields;
  gslInfo = static_fields->gslInfo;
  gslSelect = static_fields->gslSelect;
  v6 = Allocate(GameFileInfo_t);
  GameFileInfo_t___ctor(v6);
  gslInfo->m_Items[gslSelect] = v6;
  return slSaveData_writeFile(0);
}

// 0x15e9f10
void slTitleSet(s32 Code) {
    GetLocalizeText(0);
    RepColTag(0, 0);
}

// 0x15e2220
void *slTop(void) {
    slSetInfo(0);
    CampBaseOff(0);
    SetupUI();
    ButtonGuideDispSet(0, 0, 0, 0);
    return 0;
}

// 0x15f0cd0
s32 slVersionConvert_GetSize(void) {
  s32 version_convert_ver;
  sdfMemRecord_t_o *DDS3_GBWK;

  else
  {
    if (version_convert_ver == 1)
      return 63888;
  }
  else if (version_convert_ver == 2)
  {
    return 64048;
  }
  if (version_convert_ver == 3)
    return 93632;
  if (version_convert_ver == 4)
    return 93632;
  {
  }
  return SizeOf_sdfMemRecord_t_(DDS3_GBWK);
}

// 0x15f0cc0
void slVersionConvert_Step1(void) {
  ;
}

// 0x15ecb20
void slVersionConvert_Step3(void) {
  ;
}
