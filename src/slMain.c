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

  result = "";
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
  LoadLocalizeText("common", "SAVE");
  LoadLocalizeText("common", "DDS3CONFIGHELP");
  LoadLocalizeText("common", "SUSPENDNAME");
  PlatformStr = GetPlatformStr();
  v4 = Concat_5224608("common", PlatformStr);
  v5 = GetPlatformStr();
  v6 = Concat_5224608("SAVE", v5);
  LoadLocalizeText(v4, v6);
  if (op_Equality(dataFileObj, 0, 0))
  {
    if (gslMode == 5)
    {
      asset_bc = get_asset_bc();
      Prefab_16624656 = LoadPrefab_16624656(asset_bc, "common", "dds3data/UI", "continueUI");
      p_obj = &fileMesData->obj;
        goto LABEL_36;
    }
    else
    {
      v18 = get_asset_bc();
      Prefab_16624656 = LoadPrefab_16624656(v18, "common", "dds3data/UI", "saveUI");
      p_obj = &loadMesData->obj;
        goto LABEL_36;
    }
LABEL_36:
    fclInitMessage(p_obj);
    v20 = Find("Canvas_UI", 0);
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
      goto LABEL_14;
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
        goto LABEL_62;
      goto LABEL_15;
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
          goto LABEL_55;
        v13 = 2210;
      }
      evtBitOn(v13);
LABEL_55:
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
      if ((v9->_2.bitflags2 & 2) != 0)
      {
LABEL_15:
      }
LABEL_62:
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
      dds3StartProcess("FileMentCalc", 0x2B0Au, 0, 0, v20, 0, v21, 0, 0, 0);
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
        goto LABEL_62;
      goto LABEL_15;
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
        goto LABEL_62;
      goto LABEL_15;
    case 5:
      v15 = Allocate(System_Func_dds3ProcessID_t__object_);
      object____ctor(
        v15,
        0,
        Method_slMain_slLoadProc1st__);
      slProcPtr = v15;
      mode = 5;
      if ((v9->_2.bitflags2 & 2) == 0)
        goto LABEL_62;
      goto LABEL_15;
    default:
LABEL_14:
      if ((v9->_2.bitflags2 & 2) != 0)
        goto LABEL_15;
      goto LABEL_62;
  }
}

// 0x15f2380
s32 fmProcessChk(void) {
  return dds3SearchProcessName("FileMentCalc") != 0;
}

// 0x15f0a80
void fmShutDown(void) {
  dds3Basic_t_o *basic;

  basic = 0;
  slHitAnyKeyNextFunc = 0;
  if (slProcShutDownFlg)
  {
    slProcShutDownFlg = 0;
    if (hSlTex02)
    {
      hSlTex02 = 0;
    }
    if (hSlTex01)
    {
      hSlTex01 = 0;
    }
    if (!dds3SearchProcessName("fldProcSequence"))
    {
      basic = dds3GetActiveScene();
      if (basic)
      {
        dds3VisibleSceneBasic(&basic, 1);
      }
    }
    dds3KillProcessName("FileMentCalc", 1);
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
  System_Int32_array *v5;
  u64 *v7;
  u64 *v9;
  u64 *v11;
  s32 v13;
  s32 v14;
  s32 v15;
  System_Int32_array *getTime;

  v5 = NewSpecific(s32, 3u);
  getTime = v5;
  getPlayTimeToInt(time, &getTime);
  v15 = v5->m_Items[0];
  v7 = sub_8D3950(s32, &v15);
  v14 = v5->m_Items[1];
  v9 = sub_8D3950(s32, &v14);
  v13 = v5->m_Items[2];
  v11 = sub_8D3950(s32, &v13);
  return Format_5268688("{0:D3}:{1:D2}:{2:D2}", v7, v9, v11);
}

// 0x15eba10
void mcMakeFileName(char **path, s32 num) {
  s32 gslDirMode;
  System_Object_array *v8;
  s32 v11;
  s64 *v12;
  s64 *v13;
  s64 *v16;
  s64 *v17;
  s64 *v20;
  s64 *v24;
  s64 *v25;
  s64 *v27;
  s64 *v28;
  s32 v35;
  s32 v36;

  if (!gslDirMode)
    goto LABEL_34;
LABEL_6:
  v8 = NewSpecific(object, 4u);
  v8->m_Items[0] = "-dds3";
  v8->m_Items[1] = "-{1:D}";
  if (gslDirMode == 1)
  {
    v11 = 65242;
LABEL_44:
    v36 = v11;
    v24 = sub_8D3950(s32, &v36);
    v25 = v24;
    v8->m_Items[2] = v25;
    v35 = num;
    v27 = sub_8D3950(s32, &v35);
    v28 = v27;
    v8->m_Items[3] = v28;
    v20 = &"BISLPM-{0:D5}";
    goto LABEL_53;
  }
  LOWORD(v35) = ToChar_2954880(99999);
  v12 = sub_8D3950(char, &v35);
  v13 = v12;
  v8->m_Items[2] = v13;
  v36 = num;
  v16 = sub_8D3950(s32, &v36);
  v17 = v16;
  v8->m_Items[3] = v17;
  v20 = &"BISLPS-{0:D5}";
LABEL_53:
  *path = Format_5268784(*v20, v8);
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
  u64 *v3;
  System_Reflection_Assembly_o *v7;
  u64 v8;
  char *v9;
  s64 *v10;
  fileCb_t_o *v11;
  u64 v15[3];

  v3 = Allocate(fileCb_t);
  fileCb_t___ctor(v3);
  ++gslAnimCnt;
  slDraw(id);
  v7 = Assembly___Invoke(slProcPtr, id);
  if (proc_func_ans == -1)
  {
    id->func_ans = -1;
  }
  else if (id->func_ans != -1)
  {
    if (v7)
    {
      if (v7->klass != System_Func_dds3ProcessID_t__object_)
      {
        sub_8FC2C0(v7->klass->_1.element_class, System_Func_dds3ProcessID_t__object_, v15);
        if ((v15[0] & 1) != 0)
          v9 = v15[2];
        else
          v9 = v15 + 1;
        v10 = sub_8C4940(v9);
      }
      *(*(v8 + 184) + 24LL) = v7;
    }
    v11 = *(*(v8 + 184) + 184LL);
    if (v11)
    {
      if (fileCheckEnd(v11))
      {
        baseIconFileHandle = 0;
        baseIconMh = fileGetMemHandle(v11);
        baseIconPtr = fileGetLoadPtr(v11);
        baseIconSize = fileGetLoadSize(v11);
        fileHandleFree(v11);
      }
    }
    return 0;
  }
  slLast(v8);
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
      goto LABEL_13;
  }
  if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
  {
    if (gslMode != 5)
    {
LABEL_17:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      slSetInfo(0);
      v5 = Allocate(slMain_slExitWaitNextFuncDelegate);
      _ctor(v5, 0, Method_slMain_slExit__, 0);
      return slExitWait(v5);
    }
  }
  else if (gslMode != 5)
  {
    goto LABEL_17;
  }
LABEL_13:
  v4 = dds3SearchProcessName("fldProcSequence");
  if (v4)
    goto LABEL_17;
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
  s32 gslMode;
  s32 areaID[2];

  areaID[1] = 0;
  areaID[0] = 0;
  else
  {
    if (gslMode == 1)
      goto LABEL_13;
  }
  if (gslMode == 5)
    goto LABEL_13;
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

LABEL_7:
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
        goto LABEL_15;
    }
    else if ((byte_3F5A100 & 1) != 0)
    {
LABEL_15:
      v6 = Allocate(System_Func_dds3ProcessID_t__object_);
      object____ctor(
        v6,
        0,
        Method_slMain_slChooseData_getCardInfo2__);
      return v6;
    }
    goto LABEL_15;
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
  struct slMain_StaticFields **p_static_fields;
  s32 ContinueProc;
  s32 v12;
  s32 SelMessagePos;

  fclUpdateMessage();
  if (fclChkMessage())
    return 0;
  switch (ContinueProc)
  {
    case 3:
      slQueryYesNoCursor = -1;
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
        v12 = 3;
        goto LABEL_24;
      }
      SelectYesSe = -1;
      ButtonGuideDispSet("CNT01", 0, 0, 90);
      fclEndMessage();
      *&slQueryYesNoCursor = 0xFFFFFFFFLL;
      return Invoke(slQueryNoFunc, 0);
    case 1:
      SelectYesSe = 17;
      fclSetMessageInvalid(0);
      fclStartMessage(4);
      fclStartSelMessage(5);
      v12 = 2;
LABEL_24:
      ContinueProc = v12;
      return 0;
    default:
      return 0;
  }
}

// 0x15e17d0
void slDLCMsgKill(void) {
LABEL_7:
  fmShutDown();
  else
  {
    ButtonGuideDispOff();
  }
}

// 0x15e1590
void *slDLCMsgProc(void) {
  struct System_String_o *slSaveData_writeFile_wk_ptr;
  u64 *v4;
  u64 *v8;

  gslSelect = -1;
  v4 = Allocate(slMain_slSaveWriteFile_endFuncDelegate);
  _ctor(v4, 0, Method_slMain_slSaveWriteEnd_baseIcon__, 0);
  slSaveWriteFile_buff = slSaveData_writeFile_wk_ptr;
  slSaveWriteFile_size = slSaveData_writeFile_wk_size;
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
      goto LABEL_44;
  }
  else if (*(*(v5 + 184) + 356LL) == 5)
  {
    goto LABEL_44;
  }
  v6 = slDrawInfo(v5);
  if (slQueryYesNoDraw() | v6)
    goto LABEL_44;
  saveUI = _saveUI;
  if (!op_Inequality(saveUI, 0, 0))
    goto LABEL_44;
  announceObj = _saveUI->_announceObj;
  if (!op_Inequality(announceObj, 0, 0))
  {
LABEL_44:
      goto LABEL_47;
    goto LABEL_45;
  }
  v12 = _saveUI->_announceObj;
  cmpSetupObject(v12, 0);
  {
LABEL_45:
  }
LABEL_47:
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
  UnityEngine_Object_o *saveUI;
  slMain_c *v6;
  s32 gslInfoCode;
  u64 v8;
  struct TMPro_TextMeshProUGUI_array *announceList;
  u64 max_length_low;
  struct TMPro_TextMeshProUGUI_array *v13;
  TMPro_TMP_Text_o *v15;
  System_String_o *LocalizeText;
  System_Object_array *v17;
  s64 *v18;
  s64 *v20;
  System_String_o *v23;
  struct TMPro_TextMeshProUGUI_array *v25;
  TMPro_TMP_Text_o *v27;
  System_String_o *v28;
  System_Object_array *v29;
  System_Object_array *v30;
  s64 *v31;
  s64 *v33;
  System_String_o *v36;
  struct TMPro_TextMeshProUGUI_array *v38;
  TMPro_TMP_Text_o *v40;
  System_String_o *v41;
  System_Object_array *v42;
  System_Object_array *v43;
  s64 *v44;
  s64 *v46;
  System_String_o *v49;
  struct slMain_StaticFields **p_static_fields;
  struct TMPro_TextMeshProUGUI_array *v52;
  TMPro_TMP_Text_o *v54;
  System_String_o *v55;
  System_Object_array *v56;
  System_Object_array *v57;
  s64 *v58;
  s64 *v60;
  System_String_o *v63;
  struct slMain_StaticFields **v66;
  struct TMPro_TextMeshProUGUI_array *v68;
  TMPro_TMP_Text_o *v70;
  System_String_o *v71;
  System_Object_array *v72;
  System_Object_array *v73;
  s64 *v74;
  s64 *v76;
  System_String_o *v79;
  UnityEngine_GameObject_o *announceObj;
  s32 v81;
  s32 v83;
  System_String_o *v84;
  System_String_o *moji;
  System_String_o *v86;
  System_String_o *v87;

  v87 = 0;
  moji = 0;
  v86 = 0;
  v84 = 0;
  saveUI = _saveUI;
  if (op_Equality(saveUI, 0, 0))
    return 0;
  else
  {
    if (!gslInfoCode)
      return 0;
  }
  else if (gslInfoCode == 11)
  {
    return 0;
  }
  if (gslInfoCode == 12)
    return 0;
LABEL_19:
  v8 = 0;
  if ((v6->_2.bitflags2 & 2) == 0)
    goto LABEL_24;
LABEL_20:
LABEL_24:
  while (1)
  {
    announceList = _saveUI->_announceList;
    max_length_low = LODWORD(announceList->max_length);
    if (v8 >= max_length_low)
      break;
    else if (v8 >= max_length_low)
    {
LABEL_28:
    }
    set_text(announceList->m_Items[v8], "");
    ++v8;
      goto LABEL_20;
  }
  v87 = "メモリーカード（ＰＳ２）を";
  v86 = "抜かないでください";
  if (gslInfoCode == 1)
  {
    v13 = _saveUI->_announceList;
    v15 = v13->m_Items[0];
    LocalizeText = GetLocalizeText("MC_MSGNOWCHECKING");
    v83 = 0;
    v17 = NewSpecific(object, 1u);
    v18 = sub_8D3950(s32, &v83);
    v20 = v18;
    v17->m_Items[0] = v20;
    v23 = RepColTag(LocalizeText, v17);
    set_text(v15, v23);
  }
  if (gslInfoCode == 2)
  {
    v25 = _saveUI->_announceList;
    v27 = v25->m_Items[0];
    v28 = GetLocalizeText("MC_MSGWRITING");
    v29 = NewSpecific(object, 1u);
    v83 = 0;
    v30 = v29;
    v31 = sub_8D3950(s32, &v83);
    v33 = v31;
    v30->m_Items[0] = v33;
    v36 = RepColTag(v28, v30);
    set_text(v27, v36);
  }
  if (gslInfoCode == 3)
  {
    v38 = _saveUI->_announceList;
    v40 = v38->m_Items[0];
    v41 = GetLocalizeText("MC_MSGREADING");
    v42 = NewSpecific(object, 1u);
    v83 = 0;
    v43 = v42;
    v44 = sub_8D3950(s32, &v83);
    v46 = v44;
    v43->m_Items[0] = v46;
    v49 = RepColTag(v41, v43);
    set_text(v40, v49);
  }
  if (gslInfoCode == 4)
  {
    gSlExitMode = 1;
    v52 = (*p_static_fields)->_saveUI->_announceList;
    v54 = v52->m_Items[0];
    v55 = GetLocalizeText("MC_MSGSAVEDONE");
    v56 = NewSpecific(object, 1u);
    v83 = 0;
    v57 = v56;
    v58 = sub_8D3950(s32, &v83);
    v60 = v58;
    v57->m_Items[0] = v60;
    v63 = RepColTag(v55, v57);
    set_text(v54, v63);
  }
  if (gslInfoCode == 5)
  {
    moji = "フォーマット中です";
    if ((v6->_2.bitflags2 & 2) != 0)
    {
      {
      }
    }
    slKanjiDrawH(85, 76, 0x64618780u, &moji);
    slKanjiDrawH(85, 88, 0x64618780u, &v87);
    slKanjiDrawH(85, 100, 0x64618780u, &v86);
  }
  if (gslInfoCode == 6)
  {
    v84 = "フォーマットが終了しました";
    if ((v6->_2.bitflags2 & 2) != 0)
    {
      {
      }
    }
    slKanjiDrawH(85, 76, 0x64618780u, &v84);
  }
  if (gslInfoCode == 13)
  {
    gSlExitMode = 2;
    v68 = (*v66)->_saveUI->_announceList;
    v70 = v68->m_Items[0];
    v71 = GetLocalizeText("MC_MSGLOADDONE");
    v72 = NewSpecific(object, 1u);
    v83 = 0;
    v73 = v72;
    v74 = sub_8D3950(s32, &v83);
    v76 = v74;
    v73->m_Items[0] = v76;
    v79 = RepColTag(v71, v73);
    set_text(v70, v79);
  }
  announceObj = _saveUI->_announceObj;
  v81 = 1;
  cmpSetupObject(announceObj, 1);
  return v81;
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
  else
  {
    SetupUI(slMain);
  }
  return slEndingTop();
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
LABEL_10:
  if (v4)
  {
    else if (slProcShutDownFlg == 1)
    {
      goto LABEL_25;
    }
  }
  v5 = DDS3_PADCHECK_TRIG(3);
LABEL_21:
  if (!v5)
    return 0;
  if (slProcShutDownFlg != 1)
    return 0;
LABEL_25:
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
  dds3ProcessID_t_o *v4;

  gslExitType = 1;
  v4 = dds3SearchProcessName("fldProcSequence");
  if (v4)
  {
      goto LABEL_11;
    goto LABEL_21;
  }
  if (!slDDS3To31Flg)
    goto LABEL_20;
LABEL_16:
LABEL_22:
  proc_func_ans = -1;
  return 0;
}

// 0x15e98a0
void *slExitToTitleSub(void) {
  u64 *v5;
  s32 v6;

  proc_func_ans = -1;
  if (dds3SearchProcessName("fldProcSequence"))
    return 0;
  else if (slDDS3To31Flg)
  {
    return 0;
  }
  v6 = 0;
  v5 = sub_8D3950(s32, &v6);
  dds3AdminiCallSequence(2, v5, 4, 0);
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
  if (slExitWaitCnt > 0)
    return 0;
  if (procId->func_ans == -1)
  {
    slLast(v3);
    return 0;
  }
  else
  {
    return Invoke(slExitWaitNextFunc, 0);
  }
}

// 0x15dfcf0
void slFileListDispCheck(void) {
  UnityEngine_Object_o *saveUI;
  u64 v7;
  struct UnityEngine_Animator_array *animeList;
  u64 max_length_low;
  struct UnityEngine_GameObject_array *cursorList;
  s64 gslSelect;
  UnityEngine_GameObject_o *v15;
  UnityEngine_AnimatorStateInfo_o v16;
  UnityEngine_AnimatorStateInfo_o v17;

  memset(&v17, 0, sizeof(v17));
  else
  {
    if (gslDrawFlagFile)
      return;
  }
  saveUI = _saveUI;
  if (!op_Equality(saveUI, 0, 0))
  {
    v7 = 0;
    while (1)
    {
      animeList = _saveUI->_animeList;
      max_length_low = LODWORD(animeList->max_length);
      if (v7 >= max_length_low)
        return;
      else if (v7 >= max_length_low)
      {
        goto LABEL_21;
      }
      GetCurrentAnimatorStateInfo(&v16, animeList->m_Items[v7], 0);
      v17 = v16;
      if (sub_85FB40(&v17) >= 1.0)
        break;
      else if (v7 == gslSelect)
      {
        break;
      }
LABEL_40:
      if (++v7 > 3)
        return;
    }
    if (v7 == 3)
      goto LABEL_49;
    if (v7 == LODWORD(_saveUI->_animeList->max_length) - 1)
    {
LABEL_49:
      gslDrawFlagFile = 1;
      cursorList = _saveUI->_cursorList;
      v15 = cursorList->m_Items[gslSelect];
      cmpSetupObject(v15, 1);
      gSlSelCnt = 30;
    }
    goto LABEL_40;
  }
}

// 0x15df9f0
void slFileListInit(void) {
  UnityEngine_GameObject_o *saveTop;
  u64 v5;
  struct UnityEngine_GameObject_array *cursorList;
  u64 max_length_low;
  UnityEngine_GameObject_o *v10;
  struct System_Int32_array *gslStatFileInfo;
  struct System_Int32_array *v15;
  struct UnityEngine_Animator_array *animeList;
  UnityEngine_Animator_o *v19;
  System_String_o *v20;
  s32 v21;
  struct UnityEngine_Animator_array *v22;
  struct UnityEngine_Animator_array *v24;

  saveTop = _saveUI->_saveTop;
  cmpSetupObject(saveTop, 1);
  v5 = 0;
  {
LABEL_12:
  }
  while (1)
  {
    cursorList = _saveUI->_cursorList;
    max_length_low = LODWORD(cursorList->max_length);
    if (v5 >= max_length_low)
      break;
    else if (v5 >= max_length_low)
    {
      goto LABEL_18;
    }
    v10 = cursorList->m_Items[v5];
    cmpSetupObject(v10, 0);
    if (gslStatFileInfo->m_Items[v5])
    {
      v15 = gslStatFileInfo;
      if (v15->m_Items[v5] == 1)
      {
        animeList = _saveUI->_animeList;
        v19 = animeList->m_Items[v5];
        v20 = "savefile";
        v21 = v5 & 3;
      }
      else
      {
        v24 = _saveUI->_animeList;
        v19 = v24->m_Items[v5];
        v20 = "savefile";
        v21 = 7;
      }
    }
    else
    {
      v22 = _saveUI->_animeList;
      v19 = v22->m_Items[v5];
      v20 = "savefile";
      v21 = 6;
    }
    SetInteger(v19, v20, v21);
    ++v5;
      goto LABEL_12;
  }
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
  v5[4] = "０";
  v5[5] = "１";
  v5[6] = "２";
  v5[7] = "３";
  v5[8] = "４";
  v5[9] = "５";
  v5[10] = "６";
  v5[11] = "７";
  v5[12] = "８";
  v5[13] = "９";
  v16 = NewSpecific(string, 1u);
  v16->m_Items[0] = "<V 0>";
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
    goto LABEL_19;
  }
  if (gslMode != 5)
  {
    v5 = 12;
LABEL_19:
    slTitleSet(v5);
  }
  *(*(v6 + 184) + 236LL) = 0;
  v7 = 0;
  v8 = 0;
  parent = 0;
  *(*(v6 + 184) + 260LL) = 0;
  v10 = *(v6 + 294);
  if ((v10 & 0x200) != 0)
    goto LABEL_27;
LABEL_26:
  for (i = 0; ; i = v10 & 0x200)
  {
    v12 = *(v6 + 184);
    if (v7 >= *(*(*(v12 + 64) + 56LL) + 24LL))
      break;
    if (i && !*(v6 + 216))
    {
      if (v7 >= LODWORD(gslStatFileInfo->max_length))
      {
LABEL_34:
      }
    }
    else
    {
      gslStatFileInfo = *(v12 + 320);
      if (v7 >= LODWORD(gslStatFileInfo->max_length))
        goto LABEL_34;
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
      goto LABEL_26;
LABEL_27:
  }
  if (!i || *(v6 + 216))
  {
    if (*(v12 + 312))
      goto LABEL_57;
LABEL_60:
    slFileListInit(v6);
    slInitalizeFlag = 1;
    v26 = *(v6 + 294);
    if ((v26 & 0x200) == 0)
      goto LABEL_58;
    goto LABEL_64;
  }
  if (!slInitalizeFlag)
    goto LABEL_60;
LABEL_57:
  v26 = *(v6 + 294);
  if ((v26 & 0x200) == 0)
  {
LABEL_58:
    v27 = 0;
    goto LABEL_67;
  }
LABEL_64:
  v27 = v26 & 0x200;
LABEL_67:
  p_static_fields = (v6 + 184);
  static_fields = *(v6 + 184);
  if (gslMode == 5)
  {
    gslSelect = 0;
    goto LABEL_97;
  }
  if (v27 && !*(v6 + 216))
  {
    if ((gslSelect & 0x80000000) == 0)
      goto LABEL_97;
  }
  else if ((gslSelect & 0x80000000) == 0)
  {
    goto LABEL_97;
  }
  gslSelect = v8;
  v30 = *p_static_fields;
  gslSelTop = (*p_static_fields)->gslSelTop;
  gslSelect = (*p_static_fields)->gslSelect;
  if (gslSelTop <= gslSelect)
  {
    if (gslSelTop + 3 >= gslSelect)
      goto LABEL_93;
    gslSelect -= 3;
  }
  else  gslSelTop = gslSelect;
LABEL_93:
  slScrollPositionTop(*(*(v6 + 184) + 344LL));
LABEL_97:
  v33 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v33,
    0,
    Method_slMain_slFileSelCalc__);
  return v33;
}

// 0x15ecb30
void *slFileSelCalc(dds3ProcessID_t *id) {
  u64 v3;
  struct slMain_StaticFields *static_fields;
  s32 selectWait;
  struct slMain_StaticFields *v6;
  s64 *v7;
  struct slMain_StaticFields *v8;
  bool v11;
  bool v14;
  bool v15;
  s16 v16;
  s32 v17;
  struct slMain_StaticFields *v18;
  struct slMain_StaticFields **p_static_fields;
  s32 gslSelTop;
  struct slMain_StaticFields *v21;
  struct slMain_StaticFields *v22;
  struct slMain_StaticFields *v23;
  s64 v24;
  bool v25;
  s16 v26;
  s32 v27;
  struct slMain_StaticFields *v28;
  struct slMain_StaticFields **v29;
  s32 v30;
  struct slMain_StaticFields *v31;
  struct slMain_StaticFields *v32;
  struct slMain_StaticFields *v33;
  s64 v34;
  struct slMain_StaticFields *v35;
  s32 v36;
  s32 gslSelect;
  bool v39;
  s32 v42;
  s32 v45;
  bool v46;
  struct slMain_StaticFields *v47;
  s16 v48;
  s32 v49;
  s32 gSlFileSelKyeFlg;
  s16 v51;
  s32 v52;
  u64 v54;
  s16 v55;
  s32 v56;
  s32 gslMode;
  u64 *v63;
  u64 *v64;
  u64 *v67;
  intptr_t *v68;
  s16 v74;
  s32 v75;
  struct slMain_StaticFields **v76;
  u64 *v78;
  intptr_t *v79;
  struct System_Int32_array *gslStatFileInfo;
  s64 v81;
  u64 *v85;
  u64 *v86;
  Il2CppObject *v93;

  static_fields = *(v3 + 184);
  if (selectWait >= 1)
  {
    selectWait = selectWait - 1;
  }
  if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
  {
    if (gSlFileSelKyeFlg)
      goto LABEL_297;
  }
  else
  {
    v6 = *(v3 + 184);
    if (gSlFileSelKyeFlg)
      goto LABEL_297;
  }
  if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
  {
    if (selectWait)
      goto LABEL_297;
  }
  else if (selectWait)
  {
    goto LABEL_297;
  }
  if (gslMode == 5)
  {
    v7 = &"CNT01";
  }
  else
  {
    v7 = &"SAV01";
  }
  ButtonGuideDispSet(*v7, 0, 0, 90);
  v8 = *(v3 + 184);
  if (gSlSelCnt < 21)
    goto LABEL_234;
  if (gslMode == 5)
    goto LABEL_234;
  v11 = DDS3_PADCHECK_REP(6);
  if (v11)
  {
    if (slProcShutDownFlg == 1)
    {
      p2sdPlaySeEx(0, 127, 63);
      --gslSelect;
    }
  }
  v14 = DDS3_PADCHECK_REP(7);
  if (v14)
  {
    if (*(*(v3 + 184) + 4LL) == 1)
    {
      p2sdPlaySeEx(0, 127, 63);
      ++*(*(v3 + 184) + 348LL);
    }
  }
  if (!*(*(v3 + 184) + 348LL))
    goto LABEL_162;
  v15 = DDS3_PADCHECK_REP(4);
  if (!v15)
    goto LABEL_162;
  if (*(*(v3 + 184) + 4LL) != 1)
    goto LABEL_162;
  p2sdPlaySeEx(0, 127, 63);
  if ((v16 & 0x200) == 0)
  {
    v17 = 0;
    if (!gslSelTop)
      goto LABEL_118;
    goto LABEL_130;
  }
  v17 = v16 & 0x200;
  p_static_fields = (v3 + 184);
  v18 = *(v3 + 184);
  if (gslSelTop)
  {
LABEL_130:
    if (gslSelTop <= 3)
    {
      gslSelect -= gslSelTop;
      v22 = *p_static_fields;
      if ((*p_static_fields)->gslSelect < 0)
      {
        gslSelect = 0;
      }
      if ((*(v3 + 295) & 2) == 0 || *(v3 + 216))
        goto LABEL_160;
      goto LABEL_159;
    }
    gslSelect -= 4;
    v23 = *p_static_fields;
    if ((*p_static_fields)->gslSelect < 0)
    {
      gslSelect = 0;
    }
    *(*(v3 + 184) + 344LL) -= 4;
    v24 = *(v3 + 184);
    if ((*(v24 + 344) & 0x80000000) != 0)
    {
      if ((*(v3 + 295) & 2) == 0 || *(v3 + 216))
        goto LABEL_161;
LABEL_159:
LABEL_160:
      v24 = *(v3 + 184);
LABEL_161:
      *(v24 + 344) = 0;
    }
LABEL_162:
    if ((*(v3 + 295) & 2) == 0)
      goto LABEL_165;
    goto LABEL_163;
  }
LABEL_118:
  gslSelect -= 4;
  v21 = *(v3 + 184);
  if ((gslSelect & 0x80000000) == 0)
    goto LABEL_162;
  gslSelect = 0;
  if ((*(v3 + 295) & 2) != 0)
  {
LABEL_163:
  }
LABEL_165:
  if (*(*(v3 + 184) + 348LL) == 19)
    goto LABEL_234;
  v25 = DDS3_PADCHECK_REP(5);
  if (!v25)
    goto LABEL_234;
  if (*(*(v3 + 184) + 4LL) != 1)
    goto LABEL_234;
  p2sdPlaySeEx(0, 127, 63);
  if ((v26 & 0x200) != 0)
  {
    v27 = v26 & 0x200;
  }
  else
  {
    v27 = 0;
  }
  v29 = (v3 + 184);
  v28 = *(v3 + 184);
  v30 = gslSelTop;
  if (v30 != 16)
  {
    if (v27 && !*(v3 + 216))
    {
      v30 = gslSelTop;
    }
    if (v30 >= 13)
    {
      if (v27 && !*(v3 + 216))
      {
        v30 = gslSelTop;
      }
      gslSelect = gslSelect + 16 - v30;
      v32 = *v29;
      if ((*v29)->gslSelect >= 20)
      {
        gslSelect = 19;
      }
      if ((*(v3 + 295) & 2) == 0 || *(v3 + 216))
        goto LABEL_232;
      goto LABEL_231;
    }
    gslSelect += 4;
    v33 = *v29;
    if ((*v29)->gslSelect >= 20)
    {
      gslSelect = 19;
    }
    *(*(v3 + 184) + 344LL) += 4;
    v34 = *(v3 + 184);
    if (*(v34 + 344) >= 17)
    {
      if ((*(v3 + 295) & 2) == 0 || *(v3 + 216))
        goto LABEL_233;
LABEL_231:
LABEL_232:
      v34 = *(v3 + 184);
LABEL_233:
      *(v34 + 344) = 16;
    }
LABEL_234:
    if ((*(v3 + 295) & 2) == 0)
      goto LABEL_237;
    goto LABEL_235;
  }
  gslSelect += 4;
  v31 = *(v3 + 184);
  if (gslSelect < 20)
    goto LABEL_234;
  gslSelect = 19;
  if ((*(v3 + 295) & 2) != 0)
  {
LABEL_235:
  }
LABEL_237:
  *(*(v3 + 184) + 348LL) += 10 * *(*(*(*(v3 + 184) + 64LL) + 56LL) + 24LL);
  *(*(v3 + 184) + 348LL) %= *(*(*(*(v3 + 184) + 64LL) + 56LL) + 24LL);
  v35 = *(v3 + 184);
  v36 = gslSelTop;
  if (v36 <= gslSelect)
  {
    if ((*(v3 + 294) & 0x200) != 0 && !*(v3 + 216))
    {
      v36 = gslSelTop;
    }
    if (v36 + 3 >= gslSelect)
      goto LABEL_250;
    gslSelect -= 3;
  }
  else  gslSelTop = gslSelect;
LABEL_250:
  if (*(*(v3 + 184) + 248LL) >= 21)
  {
    v39 = DDS3_PADCHECK_TRIG(1);
    if (v39)
    {
      if (slProcShutDownFlg == 1)
      {
        v42 = slCheckSaveData(gslSelect);
        gSlFileErroeFlg = v42;
        if (gSlFileErroeFlg)
        {
          v45 = 4;
        }
        else
        {
          v45 = 1;
        }
        gSlFileSelKyeFlg = v45;
      }
    }
    v46 = DDS3_PADCHECK_TRIG(3);
    if (v46)
    {
      v47 = *(v3 + 184);
      if (slProcShutDownFlg == 1)
      {
        gSlFileSelKyeFlg = 2;
      }
    }
  }
LABEL_297:
  v48 = *(v3 + 294);
  if ((v48 & 0x200) == 0)
  {
    v49 = 0;
    gSlFileSelKyeFlg = *(*(v3 + 184) + 260LL);
    if (gSlFileSelKyeFlg != 3)
      goto LABEL_299;
LABEL_324:
    return slTop(v3);
  }
  v49 = v48 & 0x200;
  gSlFileSelKyeFlg = *(*(v3 + 184) + 260LL);
  if (gSlFileSelKyeFlg == 3)
    goto LABEL_324;
LABEL_299:
  if (!v49 || *(v3 + 216))
  {
    if (gSlFileSelKyeFlg)
      goto LABEL_302;
    return 0;
  }
  if (!gSlFileSelKyeFlg)
    return 0;
LABEL_302:
  v51 = *(v3 + 294);
  if ((v51 & 0x200) == 0)
  {
    v52 = 0;
    if (gSlFileSelKyeFlg != 1)
      goto LABEL_304;
LABEL_331:
    if (v52 && !*(v3 + 216))
    slSetInfo(0);
    if (gslMode)
    {
      if (gslMode == 5)
      {
        p2sdPlaySeEx(8, 127, 63);
        v63 = Allocate(slMain_slQueryYesFuncDelegate);
        _ctor(v63, 0, Method_slMain_slLoadData__, 0);
        v64 = Allocate(slMain_slQueryNoFuncDelegate);
        _ctor(v64, 0, Method_slMain_slFileSel__, 0);
        slQueryYesFunc = v63;
        slQueryNoFunc = v64;
        slQueryYesNoCursor = 1;
        slQueryYesNoKeyFlag = 0;
        ContinueProc = 1;
        v67 = Allocate(System_Func_dds3ProcessID_t__object_);
        v68 = &Method_slMain_slContinueYesNoProc__;
        goto LABEL_475;
      }
      v81 = gslSelect;
      if (gslStatFileInfo->m_Items[v81] != 1)
      {
        p2sdPlaySeEx(13, 127, 63);
        return slFileSel();
      }
      p2sdPlaySeEx(8, 127, 63);
      slQueryYesNoMsg = 3;
      v85 = Allocate(slMain_slQueryYesFuncDelegate);
      _ctor(v85, 0, Method_slMain_slLoadData__, 0);
      v86 = Allocate(slMain_slQueryNoFuncDelegate);
      _ctor(v86, 0, Method_slMain_slFileSel__, 0);
      p2sdPlaySeEx(8, 127, 63);
      gSlSaveMode = 2;
      v67 = Allocate(System_Func_dds3ProcessID_t__object_);
      v68 = &Method_slMain_slSaveProc_Write_mkdir__;
      goto LABEL_475;
    }
    p2sdPlaySeEx(8, 127, 63);
    if ((v74 & 0x200) != 0)
    {
      v75 = v74 & 0x200;
      if (!gSlEndingMode)
        goto LABEL_374;
    }
    else
    {
      v75 = 0;
      if (!gSlEndingMode)
      {
LABEL_374:
        gSlSaveMode = 1;
        (*v76)->slQueryYesNoMsg = 1;
        v78 = Allocate(slMain_slQueryYesFuncDelegate);
        v79 = &Method_slMain_slSaveData__;
LABEL_469:
        v85 = v78;
        _ctor(v78, 0, *v79, 0);
        v86 = Allocate(slMain_slQueryNoFuncDelegate);
        _ctor(v86, 0, Method_slMain_slFileSel__, 0);
        goto LABEL_471;
      }
    }
    gSlSaveMode = 1;
    (*v76)->slQueryYesNoMsg = 1;
    v78 = Allocate(slMain_slQueryYesFuncDelegate);
    v79 = &Method_slMain_slEndingUpd2__;
    goto LABEL_469;
  }
  v52 = v51 & 0x200;
  if (gSlFileSelKyeFlg == 1)
    goto LABEL_331;
LABEL_304:
  if (!v52 || *(v3 + 216))
  {
    if (gSlFileSelKyeFlg == 2)
      goto LABEL_307;
LABEL_406:
    if (gSlFileSelKyeFlg == 4)
    {
      ButtonGuideDispOff();
      fclSetMessageInvalid(1);
      fclStartMessage(gSlFileErroeFlg - 1);
      gSlFileSelKyeFlg = 5;
    }
    if (*(*(v3 + 184) + 260LL) == 5)
    {
      fclUpdateMessage();
      v93 = 0;
      if (!fclChkMessage())
      {
        fclEndMessage();
        v93 = 0;
        gSlFileSelKyeFlg = 0;
      }
      return v93;
    }
    return 0;
  }
  if (gSlFileSelKyeFlg != 2)
    goto LABEL_406;
LABEL_307:
  p2sdPlaySeEx(10, 127, 63);
  if ((v55 & 0x200) != 0)
  {
    v56 = v55 & 0x200;
    if (*(*(v54 + 184) + 272LL))
      goto LABEL_317;
  }
  else
  {
    v56 = 0;
    if (gSlEndingMode)
    {
LABEL_317:
      return slEndingExit(v54);
    }
  }
  return slCancel(v54);
}

// 0x15e2bc0
void *slFileSelDraw(dds3ProcessID_t *id) {
  System_Char_array *v2;
  System_Char_array *v3;
  u64 *v4;
  s64 *v5;
  s64 *v6;
  u32 *v7;
  s64 *v9;
  s64 *v10;
  s64 *v12;
  s64 *v14;
  f32 slFileSelDraw_blendcnt;
  f32 v19;
  slMain_c *v24;
  s32 gSlSelCnt;
  s32 v26;
  s32 v27;
  s32 v31;
  s32 v32;
  s32 v33;
  s32 i;
  sdfTexHandle_t_o *th;
  s32 v36;
  s32 v37;
  s32 v38;
  sdfTexHandle_t_o *hSlTex01;
  s64 v40;
  s16 v41;
  u64 v42;
  s32 j;
  struct slMain_StaticFields **p_static_fields;
  UnityEngine_GameObject_o *v49;
  bool v50;
  struct UnityEngine_GameObject_array *v51;
  UnityEngine_GameObject_o *v53;
  u64 k;
  struct saveUI_o *saveUI;
  struct UnityEngine_Animator_array *animeList;
  struct System_Int32_array *gslStatFileInfo;
  UnityEngine_Animator_o *v65;
  System_String_o *v66;
  s32 v67;
  struct System_Int32_array *v68;
  struct UnityEngine_Animator_array *v71;
  struct UnityEngine_Animator_array *v74;
  slMain_c *v76;
  signed s64 gslSelTop;
  s16 v79;
  s32 v80;
  s32 v81;
  s32 v82;
  sdfTexHandle_t_o *v83;
  s32 v84;
  struct System_Int32_array *v85;
  sdfTexHandle_t_o *v88;
  u64 *v89;
  struct saveFileUI_array *fileList;
  s32 v98;
  struct System_Int32_array *v101;
  struct System_Int32_array *v103;
  struct saveFileUI_array *v105;
  TMPro_TMP_Text_o *v107;
  System_String_o *v108;
  System_Object_array *v109;
  System_Object_array *v110;
  s64 *v111;
  s64 *v113;
  System_String_o *v115;
  struct saveFileUI_array *v116;
  struct saveFileUI_array *v118;
  struct saveFileUI_array *v122;
  TMPro_TMP_Text_o *noDataText;
  System_String_o *LocalizeText;
  u64 *v126;
  s32 v127;
  u64 *v128;
  struct GameFileInfo_t_array *gslInfo;
  struct saveFileUI_array *v132;
  u64 *v134;
  s64 *v135;
  s64 *v137;
  struct saveFileUI_array *v139;
  s64 *v141;
  s64 *v143;
  System_String_o *v145;
  slMain_c *v146;
  u32 *v148;
  f32 slFileSelDraw_blend;
  f32 v150;
  s64 v152;
  s64 v153;
  s64 v156;
  s64 v159;
  s64 v161;
  s64 v164;
  s64 v167;
  s64 v169;
  s64 v172;
  s64 v173;
  s32 v174;
  s64 v175;
  s64 v176;
  s64 v179;
  s64 v182;
  s64 v185;
  s64 v187;
  s32 r2;
  s64 v189;
  s32 g2;
  s64 v191;
  s32 b2;
  s64 v193;
  s32 r3;
  s64 v195;
  s32 g3;
  s64 v197;
  u32 v199;
  s32 b3;
  s32 v201;
  s64 v202;
  s32 v203;
  s64 v204;
  s64 v207;
  s64 v210;
  s64 v213;
  s64 v216;
  s32 v218;
  s64 v220;
  s32 v222;
  s64 v224;
  s32 v226;
  s64 v228;
  s32 v230;
  s64 v232;
  s32 v234;
  s64 v236;
  s32 v238;
  s64 v240;
  s32 v242;
  s32 v243;
  s16 v244;
  s32 v245;
  s32 v247;
  sdfTexHandle_t_o *v249;
  struct System_Int32_array *v271;
  struct GameFileInfo_t_array *v274;
  struct saveFileUI_array *v276;
  struct saveFileUI_array *v280;
  UnityEngine_GameObject_o *lvObj;
  System_String_o *FieldName;
  s32 v293;
  s32 v294;
  Il2CppObject *v295;
  Il2CppObject *AreaName;
  FldNameData_o *fldNameData;
  System_String_o *SaveSmlName;
  Il2CppObject *v310;
  struct saveFileUI_array *v316;
  TMPro_TMP_Text_o *terminalName;
  System_Object_array *v319;
  System_Object_array *v320;
  s64 *v321;
  s64 *v323;
  System_String_o *v325;
  struct GameFileInfo_t_array *v328;
  s32 Lv_low;
  struct saveFileUI_array *v331;
  UnityEngine_GameObject_o *v333;
  struct saveFileUI_array *v335;
  System_Int32_array *v339;
  struct GameFileInfo_t_array *v341;
  struct saveFileUI_array *v344;
  struct CounterCtr_array *playTime;
  struct saveFileUI_array *v347;
  struct CounterCtr_array *v349;
  struct GameFileInfo_t_array *v354;
  struct saveFileUI_array *v357;
  TMPro_TMP_Text_o *difficulty;
  System_String_o *v360;
  System_String_o *v363;
  struct GameFileInfo_t_array *v365;
  struct GameFileInfo_t_array *v368;
  s64 *v370;
  struct GameFileInfo_t_array *v373;
  struct GameFileInfo_t_array *v376;
  struct saveFileUI_array *v379;
  TMPro_TMP_Text_o *v381;
  System_Object_array *v382;
  System_Object_array *v383;
  s64 *v384;
  s64 *v386;
  struct saveFileUI_array *v392;
  s64 v394;
  struct GameFileInfo_t_array *v395;
  System_Array_o *v397;
  System_Array_o *v398;
  struct GameFileInfo_t_array *v400;
  struct System_Char_array *end_list;
  struct saveFileUI_array *v405;
  struct UnityEngine_GameObject_array *endingOption;
  UnityEngine_GameObject_o *v409;
  struct saveFileUI_array *v410;
  struct UnityEngine_GameObject_array *v412;
  struct saveFileUI_array *v414;
  UnityEngine_Animator_o *endingBase;
  System_String_o *v417;
  s32 v418;
  struct saveFileUI_array *v419;
  struct UnityEngine_GameObject_array *v421;
  UnityEngine_GameObject_o *v423;
  struct saveFileUI_array *v424;
  struct UnityEngine_GameObject_array *v426;
  struct saveFileUI_array *v428;
  struct saveFileUI_array *v430;
  struct UnityEngine_Animator_array *endingList;
  u64 v436;
  System_Array_o *v437;
  System_Array_o *v438;
  struct GameFileInfo_t_array *v439;
  struct System_Char_array *v441;
  s64 v443;
  struct saveFileUI_array *v446;
  struct UnityEngine_Animator_array *v448;
  s64 v450;
  UnityEngine_Animator_o *v452;
  s32 v454;
  System_String_o *v455;
  UnityEngine_Animator_o *v456;
  struct saveFileUI_array *v457;
  struct UnityEngine_Animator_array *v459;
  s64 v461;
  struct GameFileInfo_t_array *v463;
  s32 endcnt;
  s32 v466;
  s32 v467;
  u64 n;
  struct saveFileUI_array *v470;
  struct saveFileUI_array *v473;
  struct UnityEngine_GameObject_array *v475;
  UnityEngine_GameObject_o *v477;
  u64 m;
  struct saveFileUI_array *v480;
  struct saveFileUI_array *v482;
  struct UnityEngine_GameObject_array *lapObj;
  UnityEngine_GameObject_o *v486;
  struct saveFileUI_array *v487;
  struct GameFileInfo_t_array *v490;
  struct saveFileUI_array *v492;
  TMPro_TMP_Text_o *playerName;
  System_String_o *v495;
  System_Object_array *v496;
  System_Object_array *v497;
  s64 *v498;
  s64 *v500;
  System_String_o *v502;
  u64 ii;
  struct saveFileUI_array *v505;
  struct saveFileUI_array *v508;
  struct UnityEngine_GameObject_array *loopStartNon;
  UnityEngine_GameObject_o *v512;
  struct GameFileInfo_t_array *v513;
  struct GameFileInfo_t_array *v517;
  GameFileInfo_t_o *v519;
  struct saveFileUI_array *v520;
  System_String_o *cname_code;
  TMPro_TMP_Text_o *v523;
  System_Object_array *v524;
  System_Object_array *v525;
  s64 *v526;
  s64 *v528;
  System_String_o *v531;
  u64 jj;
  struct saveFileUI_array *v534;
  struct saveFileUI_array *v537;
  struct UnityEngine_GameObject_array *v539;
  UnityEngine_GameObject_o *v541;
  struct GameFileInfo_t_array *v543;
  sdfTexHandle_t_o *v546;
  sdfTexHandle_t_o *v548;
  s32 b1;
  s32 g1;
  s32 g1a;
  s32 v554;
  s32 v555;
  s32 v556;
  s32 v557;
  s32 x;
  s32 xa;
  u32 y;
  u64 *v561;
  _BOOL4 colidx;
  s32 v563;
  u32 *v564;
  s32 v565;
  UnityEngine_AnimatorStateInfo_o v566;
  s32 nameD[2];
  s32 areaID[2];
  System_Int32_array *getTime;
  UnityEngine_AnimatorStateInfo_o v570;
  UnityEngine_Color_o v571;
  UnityEngine_Color_o v572;
  UnityEngine_Color_o v573;
  UnityEngine_Color_o v574;

  memset(&v570, 0, sizeof(v570));
  *areaID = 0;
  getTime = 0;
  *nameD = 0;
  v2 = NewSpecific(char, 0x10u);
  CreateString_5280336(0, v2);
  v3 = NewSpecific(char, 0x12u);
  CreateString_5280336(0, v3);
  v4 = NewSpecific(int__, 3u);
  v5 = NewSpecific(s32, 3u);
  v6 = v5;
  v7 = v4 + 3;
  v4[4] = v6;
  v9 = NewSpecific(s32, 3u);
  v10 = v9;
  v4[5] = v10;
  v12 = NewSpecific(s32, 3u);
  v14 = v12;
  v4[6] = v14;
  slFileSelDraw_blendcnt = slFileSelDraw_blendcnt + 0.1;
  v19 = sdfSin(slFileSelDraw_blendcnt);
  slFileSelDraw_blend = (v19 * 0.5) + 0.5;
  if (slFileSelDraw_blend < 0.0)
  {
    slFileSelDraw_blend = 0.0;
  }
  if (slFileSelDraw_blend > 1.0)
  {
    slFileSelDraw_blend = 1.0;
  }
  v564 = v4 + 3;
  rsetOtOfs(73);
  rsetTest(1, 0, 128, 2, 0, 0, 1, 1);
  rsetAlpha(0);
  aDrawBoxF(0, 0, 512, 448, 0, 0, 0, 0);
  rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
  rsetOtOfs(71);
  rsetAlpha(0);
  rsetTest(1, 0, 128, 3, 0, 0, 1, 1);
  else
  {
    if (gSlSelCnt < 8)
      goto LABEL_40;
  }
  else if (gSlSelCnt > 14)
  {
    goto LABEL_54;
  }
  v36 = gSlSelCnt << 9;
  v37 = v36 - 3584;
  v38 = v36 - 3577;
  if (v37 >= 0)
    v38 = v37;
  v26 = 512 - (v38 >> 3);
  if ((v24->_2.bitflags2 & 2) != 0)
  {
LABEL_55:
  }
LABEL_80:
  DrwSprite2D_17010048(v26 + 382, 52, 130, 29, 4, 13, 130, 29, 0x80808080, hSlTex01);
  DrwSprite2D_17010048(v26, 52, 382, 29, 133, 13, 1, 29, 0x80808080, hSlTex01);
  aDrawBoxG(v26, 22, 512, 4, 0, 0, 0, 89, 0, 0, 0, 89, 0, 0, 0, 89, 0, 0, 0, 89);
  aDrawBoxG(v26, 40, 512, 4, 0, 0, 0, 89, 0, 0, 0, 89, 0, 0, 0, 89, 0, 0, 0, 89);
  aDrawBoxG(v26, 207, 512, 2, 0, 0, 0, 89, 0, 0, 0, 89, 0, 0, 0, 89, 0, 0, 0, 89);
  {
LABEL_84:
    v27 = gSlSelCnt;
    if (v27 >= 8)
      goto LABEL_43;
    goto LABEL_85;
  }
LABEL_41:
    goto LABEL_84;
  v27 = gSlSelCnt;
  if (v27 >= 8)
  {
LABEL_43:
    else if (v27 > 14)
    {
LABEL_46:
      v26 = 0;
LABEL_64:
      for (i = 88; i != 472; i += 64)
      {
        th = hSlTex01;
        DrwSprite2D_17010048(v26 + 392, i, 120, 6, 3, 2, 120, 6, 0x80808080, th);
        DrwSprite2D_17010048(v26, i, 392, 6, 3, 2, 1, 6, 0x80808080, hSlTex01);
      }
      goto LABEL_85;
    }
    v31 = v27 << 9;
    v32 = v31 - 3584;
    v33 = v31 - 3577;
    if (v32 >= 0)
      v33 = v32;
    v26 = (v33 >> 3) - 512;
    goto LABEL_64;
  }
LABEL_85:
  v563 = v26;
  if (bakSelect != gslSelect)
  {
    v40 = 4;
    v41 = *&v24->_2.bitflags1;
    v42 = 0;
    if ((v41 & 0x200) == 0)
      goto LABEL_94;
LABEL_90:
    for (j = v41 & 0x200; ; j = 0)
    {
      if (v42 >= SLODWORD(_saveUI->_cursorList->max_length))
      {
        bakSelect = gslSelect;
        slScrollPositionTop((*p_static_fields)->gslSelTop);
        break;
      }
      else if (v42 == gslSelect)
      {
        goto LABEL_99;
      }
      v51 = _saveUI->_cursorList;
      v53 = *(&v51->obj.klass + v40);
      v49 = v53;
      v50 = 0;
LABEL_93:
      cmpSetupObject(v49, v50);
      ++v40;
      v42 = v40 - 4;
      if ((v41 & 0x200) != 0)
        goto LABEL_90;
LABEL_94:
      ;
    }
  }
  v561 = v4;
  for (k = 0; ; ++k)
  {
    saveUI = _saveUI;
    if (k >= SLODWORD(saveUI->_fileList->max_length))
      break;
    else
    {
      animeList = saveUI->_animeList;
      if (k >= LODWORD(animeList->max_length))
        goto LABEL_131;
    }
    GetCurrentAnimatorStateInfo(&v566, animeList->m_Items[k], 0);
    v570 = v566;
    if (gslStatFileInfo->m_Items[k] != 1)
    {
      v68 = gslStatFileInfo;
      if (v68->m_Items[k] == 2)
      {
        v71 = _saveUI->_animeList;
        v65 = v71->m_Items[k];
        v66 = "savefile";
        v67 = 7;
        goto LABEL_167;
      }
      goto LABEL_168;
    }
    else if (k == gslSelect)
    {
      goto LABEL_138;
    }
    if (!sub_85F980(&v570, "savefile_offstay"))
    {
      v74 = _saveUI->_animeList;
      v65 = v74->m_Items[k];
      v66 = "savefile";
      v67 = 4;
      goto LABEL_167;
    }
LABEL_168:
    else
    {
      if (k < gslSelTop)
        continue;
    }
    else if (k > gslSelTop + 3)
    {
      continue;
    }
    v79 = *&v76->_2.bitflags1;
    if ((v79 & 0x200) != 0)
    {
      v80 = v79 & 0x200;
    }
    else
    {
      v80 = 0;
    }
    colidx = k == gslSelect;
    else
    {
      v81 = gSlSelCnt;
      if (v81 > 9)
        goto LABEL_184;
    }
    if (k <= 4)
    {
      if (((1 << k) & 0x15) != 0)
      {
        v82 = (v81 << 9) / 10 - 512;
      }
      else
      {
        v82 = 512 - (v81 << 9) / 10;
      }
      v563 = v82;
    }
    if ((v76->_2.bitflags2 & 2) != 0)
      goto LABEL_185;
LABEL_202:
    v565 = k << 6;
    v83 = hSlTex01;
    v84 = v565 + 94;
    DrwSprite2D_17010048(v563 + 382, v565 + 94, 130, 29, 132, 38, -130, 29, 0x80808080, v83);
    DrwSprite2D_17010048(v563, v565 + 94, 382, 29, 132, 38, 1, 29, 0x80808080, hSlTex01);
    DrwSprite2D_17010048(v563, v565 + 123, 130, 29, 3, 38, 130, 29, 0x80808080, hSlTex01);
    y = v565 + 123;
    DrwSprite2D_17010048(v563 + 130, v565 + 123, 382, 29, 132, 38, 1, 29, 0x80808080, hSlTex01);
    v85 = gslStatFileInfo;
    if (v85->m_Items[k] != 1)
    {
      v88 = hSlTex01;
      DrwSprite2D_17010048(v563 + 382, v84, 130, 29, 133, 77, -130, 29, 0x80808080, v88);
      DrwSprite2D_17010048(v563, v84, 382, 29, 133, 77, 1, 29, 0x80808080, hSlTex01);
      DrwSprite2D_17010048(v563, y, 130, 29, 4, 77, 130, 29, 0x80808080, hSlTex01);
      DrwSprite2D_17010048(v563 + 130, y, 382, 29, 133, 77, 1, 29, 0x80808080, hSlTex01);
    }
    v89 = v561;
    switch (k)
    {
      case 0:
        if (gSlSelCnt >= 15)
          goto LABEL_239;
        continue;
      case 1:
        if (gSlSelCnt >= 17)
          goto LABEL_239;
        continue;
      case 2:
        if (gSlSelCnt >= 19)
          goto LABEL_239;
        continue;
      case 3:
        if (gSlSelCnt >= 23)
          goto LABEL_239;
        continue;
      case 4:
        else if (gSlSelCnt < 25)
        {
          continue;
        }
LABEL_239:
        v571 = GetToRGBA(0xFFFFFFFF);
        fileList = _saveUI->_fileList;
        v98 = k + 1;
        Set(fileList->m_Items[k]->_fileNum, k + 1, v571, colidx, 0);
        v101 = gslStatFileInfo;
        if (!v101->m_Items[k])
        {
          v118 = _saveUI->_fileList;
          Set(v118->m_Items[k]->_noDataNum, v98, v571, 0, 0);
          if (gslMode == 1)
          {
            v122 = _saveUI->_fileList;
            noDataText = v122->m_Items[k]->_noDataText;
            LocalizeText = GetLocalizeText("MC_NDFILE");
            v126 = NewSpecific(object, 1u);
            v127 = colidx;
            v128 = v126;
          }
          else
          {
            v139 = _saveUI->_fileList;
            noDataText = v139->m_Items[k]->_noDataText;
            LocalizeText = GetLocalizeText("MC_NEWFILE");
            v128 = NewSpecific(object, 1u);
            v127 = 20;
          }
          v566.m_Name = v127;
          v141 = sub_8D3950(s32, &v566);
          v143 = v141;
          v128[4] = v143;
LABEL_327:
          v145 = RepColTag(LocalizeText, v128);
          set_text(noDataText, v145);
LABEL_328:
          v89 = v561;
          goto LABEL_329;
        }
        v103 = gslStatFileInfo;
        if (v103->m_Items[k] == 2)
        {
          v105 = _saveUI->_fileList;
          v107 = v105->m_Items[k]->_noDataText;
          v108 = GetLocalizeText("MC_CRFILE");
          v109 = NewSpecific(object, 1u);
          v566.m_Name = 7;
          v110 = v109;
          v111 = sub_8D3950(s32, &v566);
          v113 = v111;
          v110->m_Items[0] = v113;
          v115 = RepColTag(v108, v110);
          set_text(v107, v115);
          v116 = _saveUI->_fileList;
          Set(v116->m_Items[k]->_brokenNum, v98, v571, 0, 0);
          goto LABEL_328;
        }
        if (gslInfo->m_Items[k]->newfile)
        {
          v132 = _saveUI->_fileList;
          noDataText = v132->m_Items[k]->_noDataText;
          LocalizeText = GetLocalizeText("MC_NEWGAME");
          v134 = NewSpecific(object, 1u);
          v566.m_Name = colidx;
          v128 = v134;
          v135 = sub_8D3950(s32, &v566);
          v137 = v135;
          v128[4] = v137;
          goto LABEL_327;
        }
LABEL_329:
        else
        {
          if (k != gslSelect)
            goto LABEL_448;
        }
        if ((v146->_2.bitflags2 & 2) != 0)
        {
          v148 = v564;
        }
        else
        {
          v148 = v564;
        }
        v150 = 1.0 - slFileSelDraw_blend;
        v152 = v89[4];
        *(v152 + 32) = ((slFileSelDraw_blend * 56.0) + (v150 * 30.0));
        v153 = v89[4];
        *(v153 + 36) = ((slFileSelDraw_blend * 83.0) + (v150 * 19.0));
        v156 = v89[4];
        *(v156 + 40) = ((slFileSelDraw_blend * 100.0) + (v150 * 54.0));
        v159 = v89[5];
        *(v159 + 32) = ((slFileSelDraw_blend * 32.0) + (v150 * 32.0));
        v161 = v89[5];
        *(v161 + 36) = ((slFileSelDraw_blend * 23.0) + (v150 * 23.0));
        v164 = v89[5];
        *(v164 + 40) = ((slFileSelDraw_blend * 66.0) + (v150 * 66.0));
        v167 = v89[6];
        *(v167 + 32) = ((slFileSelDraw_blend * 30.0) + (v150 * 56.0));
        v169 = v89[6];
        *(v169 + 36) = ((slFileSelDraw_blend * 19.0) + (v150 * 83.0));
        v172 = v89[6];
        *(v172 + 40) = ((slFileSelDraw_blend * 54.0) + (v150 * 100.0));
        v173 = v89[4];
        v174 = *(v173 + 32);
        v175 = v89[4];
        x = *(v175 + 36);
        v176 = v89[4];
        v556 = *(v176 + 40);
        v179 = v89[5];
        v554 = *(v179 + 32);
        v182 = v89[5];
        g1 = *(v182 + 36);
        v185 = v89[5];
        b1 = *(v185 + 40);
        v187 = v89[5];
        r2 = *(v187 + 32);
        v189 = v89[5];
        g2 = *(v189 + 36);
        v191 = v89[5];
        b2 = *(v191 + 40);
        v193 = v89[4];
        r3 = *(v193 + 32);
        v195 = v89[4];
        g3 = *(v195 + 36);
        v197 = v89[4];
        v199 = v565 + 97;
        b3 = *(v197 + 40);
        v201 = v199 >> 1;
        aDrawBoxG(0, v199 >> 1, 203, 26, v174, x, v556, 32, v554, g1, b1, 32, r2, g2, b2, 32, r3, g3, b3, 32);
        v202 = v561[5];
        v203 = *(v202 + 32);
        v204 = v561[5];
        xa = *(v204 + 36);
        v207 = v561[5];
        v557 = *(v207 + 40);
        v210 = v561[6];
        v555 = *(v210 + 32);
        v213 = v561[6];
        g1a = *(v213 + 36);
        v216 = v561[6];
        v218 = *(v216 + 40);
        v220 = v561[6];
        v222 = *(v220 + 32);
        v224 = v561[6];
        v226 = *(v224 + 36);
        v228 = v561[6];
        v230 = *(v228 + 40);
        v232 = v561[5];
        v234 = *(v232 + 32);
        v236 = v561[5];
        v238 = *(v236 + 36);
        v240 = v561[5];
        aDrawBoxG(
          203,
          v201,
          309,
          26,
          v203,
          xa,
          v557,
          32,
          v555,
          g1a,
          v218,
          32,
          v222,
          v226,
          v230,
          32,
          v234,
          v238,
          *(v240 + 40),
          32,
          0);
        v242 = ((slFileSelDraw_blend * 256.0) + (v150 * 0.0));
        aDrawBoxG(
          0,
          (v565 + 99) >> 1,
          v242 + 203,
          12,
          105,
          150,
          177,
          38,
          63,
          55,
          140,
          38,
          63,
          55,
          140,
          38,
          105,
          150,
          177,
          38,
          0);
        aDrawBoxG(
          v242 + 203,
          (v565 + 99) >> 1,
          v242 + 232,
          12,
          63,
          55,
          140,
          38,
          54,
          38,
          94,
          0,
          54,
          38,
          94,
          0,
          63,
          55,
          140,
          38,
          0);
        v243 = ((slFileSelDraw_blend * 0.0) + (v150 * 256.0));
        aDrawBoxG(77 - 2 * v243, y >> 1, v243 + 233, 12, 54, 38, 94, 0, 63, 55, 140, 38, 63, 55, 140, 38, 54, 38, 94, 0);
        aDrawBoxG(310 - v243, y >> 1, v243 + 202, 12, 63, 55, 140, 38, 54, 38, 94, 38, 54, 38, 94, 38, 63, 55, 140, 38);
LABEL_448:
        v244 = *&v146->_2.bitflags1;
        if ((v244 & 0x200) != 0)
        {
          v245 = v244 & 0x200;
        }
        else
        {
          v245 = 0;
        }
        if (k == gslSelect)
          v247 = 22;
        else
          v247 = 0;
        else
        {
          v249 = hSlTex01;
            goto LABEL_482;
        }
LABEL_482:
        DrwSprite2D_17010048(34, v565 + 100, 18, 21, 19 * k + 137, v247 | 1, 18, 21, 0x80808080, v249);
        if (k == LODWORD(_saveUI->_fileList->max_length))
          continue;
        else
        {
          v271 = gslStatFileInfo;
          if (k >= LODWORD(v271->max_length))
            goto LABEL_486;
        }
        if (v271->m_Items[k] != 1)
          continue;
        v274 = gslInfo;
        if (v274->m_Items[k]->newfile)
        {
          v276 = _saveUI->_fileList;
          set_text(v276->m_Items[k]->_terminalName, "");
          GetToRGBA(0xFFFFFFFF);
          v280 = _saveUI->_fileList;
          lvObj = v280->m_Items[k]->_lvObj;
          cmpSetupObject(lvObj, 0);
          goto LABEL_607;
        }
        else
        {
          if (gslMode != 5)
            goto LABEL_541;
        }
        *nameD = 0;
        *areaID = 0;
        GetSuspendFieldArea(saveData, &areaID[1], areaID);
        GetSuspendDispName(saveData, &nameD[1], nameD);
        FieldName = GetFieldName(fldNameData, areaID[1]);
        v293 = areaID[1];
        v294 = nameD[1];
        v295 = FieldName;
        if (v294 < 1)
        {
          AreaName = "";
        }
        else
        {
          AreaName = GetAreaName(fldNameData, v293, v294);
        }
        v310 = GetLocalizeText("SAVE_MIDDLEMARK");
        if (areaID[1] != 45 || nameD[1] != 11)
        {
          if (!Equals_5234480(v295, AreaName)
            && op_Inequality(AreaName, "", 0))
          {
            SaveSmlName = Format_5268688("{0}{1}{2}", v295, v310, AreaName);
LABEL_574:
            AreaName = SaveSmlName;
            goto LABEL_576;
          }
          AreaName = v295;
        }
LABEL_576:
        v316 = _saveUI->_fileList;
        terminalName = v316->m_Items[k]->_terminalName;
        v319 = NewSpecific(object, 1u);
        v566.m_Name = colidx;
        v320 = v319;
        v321 = sub_8D3950(s32, &v566);
        v323 = v321;
        v320->m_Items[0] = v323;
        v325 = RepColTag(AreaName, v320);
        set_text(terminalName, v325);
        v328 = gslInfo;
        if (LOBYTE(v328->m_Items[k]->Lv) >= 0x63u)
          Lv_low = 99;
        else
          Lv_low = LOBYTE(v328->m_Items[k]->Lv);
        v331 = _saveUI->_fileList;
        v333 = v331->m_Items[k]->_lvObj;
        cmpSetupObject(v333, 1);
        v573 = GetToRGBA(0xFFFFFFFF);
        v335 = _saveUI->_fileList;
        Set(v335->m_Items[k]->_playerLV, Lv_low, v573, colidx, 0);
LABEL_607:
        getTime = NewSpecific(s32, 3u);
        v339 = getTime;
        v341 = gslInfo;
        getPlayTimeToInt(v341->m_Items[k]->PlayTime, &getTime);
        v574 = GetToRGBA(0xFFFFFFFF);
        v344 = _saveUI->_fileList;
        playTime = v344->m_Items[k]->_playTime;
        Set(playTime->m_Items[0], v339->m_Items[0], v574, colidx, 0);
        v572 = GetToRGBA(0xFFFFFFFF);
        v347 = _saveUI->_fileList;
        v349 = v347->m_Items[k]->_playTime;
        Set(v349->m_Items[1], v339->m_Items[1], v572, colidx, 0);
        if (slDDS3To31Flg)
          goto LABEL_831;
        v354 = gslInfo;
        if (v354->m_Items[k]->newfile)
        {
          v357 = _saveUI->_fileList;
          difficulty = v357->m_Items[k]->_difficulty;
          v360 = "";
          goto LABEL_692;
        }
        v363 = "";
        v365 = gslInfo;
        if (!v365->m_Items[k]->mode)
        {
          v370 = &"DDS3CONFIGHELP_L0016";
          {
            v370 = &"DDS3CONFIGHELP_L0016";
          }
          goto LABEL_677;
        }
        v368 = gslInfo;
        if (v368->m_Items[k]->mode == 1)
        {
          v370 = &"DDS3CONFIGHELP_L0017";
          {
            v370 = &"DDS3CONFIGHELP_L0017";
          }
LABEL_677:
          v363 = GetLocalizeText(*v370);
          goto LABEL_678;
        }
        v373 = gslInfo;
        if (v373->m_Items[k]->mode == 2)
        {
          v370 = &"DDS3CONFIGHELP_L0018";
          {
            v370 = &"DDS3CONFIGHELP_L0018";
          }
          goto LABEL_677;
        }
        v376 = gslInfo;
        if (v376->m_Items[k]->mode == 3)
        {
          v370 = &"DDS3CONFIGHELP_L0019";
          {
            v370 = &"DDS3CONFIGHELP_L0019";
          }
          goto LABEL_677;
        }
LABEL_678:
        v379 = _saveUI->_fileList;
        v381 = v379->m_Items[k]->_difficulty;
        v382 = NewSpecific(object, 1u);
        v566.m_Name = colidx;
        v383 = v382;
        v384 = sub_8D3950(s32, &v566);
        v386 = v384;
        v383->m_Items[0] = v386;
        v360 = RepColTag(v363, v383);
        difficulty = v381;
LABEL_692:
        set_text(difficulty, v360);
        v392 = _saveUI->_fileList;
        v394 = v392 + 8 * k;
        v395 = gslInfo;
        SetInteger(
          *(*(v394 + 32) + 104LL),
          "savemode",
          v395->m_Items[k]->dante_mode + 1,
          0);
        v397 = NewSpecific(s32, 7u);
        InitializeArray_1543888(v397, Field__PrivateImplementationDetails__50567A6578C37E24118E2B7EE8F5C7930666F62F);
        v398 = NewSpecific(s32, 7u);
        InitializeArray_1543888(v398, Field__PrivateImplementationDetails__50567A6578C37E24118E2B7EE8F5C7930666F62F);
        v400 = gslInfo;
        end_list = v400->m_Items[k]->end_list;
        if (end_list->m_Items[6] == 1)
        {
          v405 = _saveUI->_fileList;
          endingOption = v405->m_Items[k]->_endingOption;
          v409 = endingOption->m_Items[0];
          cmpSetupObject(v409, 1);
          v410 = _saveUI->_fileList;
          v412 = v410->m_Items[k]->_endingOption;
          cmpSetupObject(v412->m_Items[1], 0);
          v414 = _saveUI->_fileList;
          endingBase = v414->m_Items[k]->_endingBase;
          v417 = "saveed_base_r";
          v418 = 1;
        }
        else
        {
          v419 = _saveUI->_fileList;
          v421 = v419->m_Items[k]->_endingOption;
          v423 = v421->m_Items[0];
          cmpSetupObject(v423, 0);
          v424 = _saveUI->_fileList;
          v426 = v424->m_Items[k]->_endingOption;
          cmpSetupObject(v426->m_Items[1], 1);
          v428 = _saveUI->_fileList;
          SetInteger(v428->m_Items[k]->_endingBase, "saveed_base_r", 0);
          v430 = _saveUI->_fileList;
          endingList = v430->m_Items[k]->_endingList;
          endingBase = endingList->m_Items[0];
          v417 = "saveed_icon";
          v418 = 0;
        }
        SetInteger(endingBase, v417, v418);
        if (SLODWORD(v397[1].monitor) >= 1)
        {
          v436 = 0;
          v437 = v397 + 2;
          v438 = v398 + 2;
          do
          {
            v439 = gslInfo;
            v441 = v439->m_Items[k]->end_list;
            v443 = *(&v437->klass + v436);
            if (v441->m_Items[v443] == 1)
            {
              v446 = _saveUI->_fileList;
              v448 = v446->m_Items[k]->_endingList;
              v450 = *(&v438->klass + v436);
              v452 = v448->m_Items[v450];
              v454 = *(&v437->klass + v436) + 1;
              v455 = "saveed_icon";
              v456 = v452;
            }
            else
            {
              v457 = _saveUI->_fileList;
              v459 = v457->m_Items[k]->_endingList;
              v461 = *(&v438->klass + v436);
              v456 = v459->m_Items[v461];
              v455 = "saveed_icon";
              v454 = 0;
            }
            SetInteger(v456, v455, v454);
            ++v436;
          }
          while (v436 < SLODWORD(v397[1].monitor));
        }
        v463 = gslInfo;
        endcnt = v463->m_Items[k]->endcnt;
        if (endcnt >= 0)
          v466 = endcnt + 1;
        else
          v466 = 1;
        if (v466 >= 99)
          v467 = 99;
        else
          v467 = v466;
        if (v467 >= 2)
        {
          for (m = 0; ; ++m)
          {
            v480 = _saveUI->_fileList;
            if (m >= SLODWORD(v480->m_Items[k]->_lapObj->max_length))
              break;
            v482 = _saveUI->_fileList;
            lapObj = v482->m_Items[k]->_lapObj;
            v486 = lapObj->m_Items[m];
            cmpSetupObject(v486, 1);
          }
          v487 = _saveUI->_fileList;
          Set(v487->m_Items[k]->_lapNum, v467, v572, colidx, 0);
        }
        else
        {
          for (n = 0; ; ++n)
          {
            v470 = _saveUI->_fileList;
            if (n >= SLODWORD(v470->m_Items[k]->_lapObj->max_length))
              break;
            v473 = _saveUI->_fileList;
            v475 = v473->m_Items[k]->_lapObj;
            v477 = v475->m_Items[n];
            cmpSetupObject(v477, 0);
          }
        }
LABEL_831:
        v490 = gslInfo;
        if (v490->m_Items[k]->newfile)
        {
          v492 = _saveUI->_fileList;
          playerName = v492->m_Items[k]->_playerName;
          v495 = GetLocalizeText("MC_NEWGAME");
          v496 = NewSpecific(object, 1u);
          v566.m_Name = colidx;
          v497 = v496;
          v498 = sub_8D3950(s32, &v566);
          v500 = v498;
          v497->m_Items[0] = v500;
          v502 = RepColTag(v495, v497);
          set_text(playerName, v502);
          for (ii = 0; ; ++ii)
          {
            v505 = _saveUI->_fileList;
            if (ii >= SLODWORD(v505->m_Items[k]->_loopStartNon->max_length))
              break;
            v508 = _saveUI->_fileList;
            loopStartNon = v508->m_Items[k]->_loopStartNon;
            v512 = loopStartNon->m_Items[ii];
            cmpSetupObject(v512, 0);
          }
        }
        else
        {
          v513 = gslInfo;
          if (v513->m_Items[k]->cname_nums)
          {
            v517 = gslInfo;
            v519 = v517->m_Items[k];
            v520 = _saveUI->_fileList;
            cname_code = v519->cname_code;
            v523 = v520->m_Items[k]->_playerName;
            v524 = NewSpecific(object, 1u);
            v566.m_Name = colidx;
            v525 = v524;
            v526 = sub_8D3950(s32, &v566);
            v528 = v526;
            v525->m_Items[0] = v528;
            v531 = RepColTag(cname_code, v525);
            set_text(v523, v531);
            for (jj = 0; ; ++jj)
            {
              v534 = _saveUI->_fileList;
              if (jj >= SLODWORD(v534->m_Items[k]->_loopStartNon->max_length))
                break;
              v537 = _saveUI->_fileList;
              v539 = v537->m_Items[k]->_loopStartNon;
              v541 = v539->m_Items[jj];
              cmpSetupObject(v541, 1);
            }
          }
        }
        v543 = gslInfo;
        if (!v543->m_Items[k]->newfile)
        {
          v546 = hSlTex01;
          DrwSprite2D_17010048(82, v565 + 106, 25, 13, 137, v247 + 45, 25, 13, 0x80808080, v546);
        }
        v548 = hSlTex01;
        DrwSprite2D_17010048(333, v565 + 106, 46, 13, 163, v247 + 45, 46, 13, 0x80808080, v548);
        DrwSprite2D_17010048(412, v565 + 106, 6, 13, 210, 45, 6, 13, 0x80808080, hSlTex01);
        break;
      default:
        goto LABEL_239;
    }
  }
  rsetAlpha(0);
  rsetTest(1, 5, 128, 3, 0, 0, 1, 2);
  rsetOtOfs(71);
  rsetAlpha(0);
  rsetTest(1, 5, 128, 3, 0, 0, 1, 2);
  return 0;
}

// 0x15ec030
void *slFormatCancel(void) {
  s32 v3;
  u64 *v5;
  intptr_t *v6;
  u64 *v7;
  u64 *v8;
  u64 *v11;

  {
    else
    {
      if (!gSlEndingMode)
        goto LABEL_11;
    }
LABEL_5:
    slQueryYesNoMsg = 7;
    v5 = Allocate(slMain_slQueryYesFuncDelegate);
    v6 = &Method_slMain_slEndingExit__;
    goto LABEL_15;
  }
  v3 = 0;
  if (gSlEndingMode)
    goto LABEL_5;
LABEL_11:
  slQueryYesNoMsg = 7;
  v5 = Allocate(slMain_slQueryYesFuncDelegate);
  v6 = &Method_slMain_slExit__;
LABEL_15:
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
  slMain_c *v2;
  struct FsSaveData_o *saveData;
  struct FsSaveData_o *v4;
  struct GameFileInfo_t_array *gslInfo;
  s64 slChooseSaveIndex;
  GameFileInfo_t_o **v9;
  s32 v10;
  FsSaveData_o *v11;
  struct GameFileInfo_t_array *v13;
  s64 v14;

  if (gslMode == 5)
  {
    else
    {
      if ((v2->_2.bitflags2 & 2) != 0)
        goto LABEL_10;
    }
    v9 = &gslInfo->m_Items[slChooseSaveIndex];
    v10 = 20;
    v11 = saveData;
    goto LABEL_25;
  }
  else
  {
    v4 = saveData;
    if ((v2->_2.bitflags2 & 2) != 0)
      goto LABEL_15;
  }
  v13 = gslInfo;
  v14 = slChooseSaveIndex;
  v9 = &v13->m_Items[v14];
  v11 = v4;
  v10 = slChooseSaveIndex;
LABEL_25:
  loadHeaderGameFileInfo(v11, v10, v9);
  return slChooseData_getCardInfoNext();
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
LABEL_10:
  if (v4)
  {
    else if (slProcShutDownFlg == 1)
    {
      goto LABEL_29;
    }
  }
  v6 = DDS3_PADCHECK_TRIG(3);
  if (v6)
  {
    else if (slProcShutDownFlg == 1)
    {
      goto LABEL_29;
    }
  }
  else if (gslMode != 5)
  {
    return 0;
  }
LABEL_29:
  slSetInfo(0);
  gslErrorCode = 0;
  *(*(v8 + 184) + 236LL) = 0;
  if (procId->func_ans != -1)
  {
    if ((*(v8 + 294) & 0x200) != 0 && !*(v8 + 216))
    {
      if (slHitAnyKeyNextFunc)
        goto LABEL_36;
    }
    else
    {
      slHitAnyKeyNextFunc = *(*(v8 + 184) + 152LL);
      if (slHitAnyKeyNextFunc)
      {
LABEL_36:
        return Invoke(slHitAnyKeyNextFunc, 0);
      }
    }
    procId->func_ans = -1;
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

  else if (gslErrorKeyFlag)
  {
    return 0;
  }
  v6 = DDS3_PADCHECK_TRIG(1);
  if (v6)
  {
    else if (slProcShutDownFlg == 1)
    {
      goto LABEL_35;
    }
  }
  v7 = DDS3_PADCHECK_TRIG(3);
  if (!v7)
    return 0;
  if (slProcShutDownFlg != 1)
    return 0;
LABEL_35:
  p2sdPlaySeEx(8, 127, 63);
  gslErrorKeyFlag = 1;
  slSetInfo(0);
  gslErrorCode = 0;
  gslDrawFlagFile = 0;
  if (gslSelect == 20)
  {
    procId->func_ans = -1;
    return 0;
  }
  return Invoke(slHitAnyKeyNextFunc, 0);
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
  Remove("SAVE", 0);
  Remove("DDS3CONFIGHELP", 0);
  Remove("SUSPENDNAME", 0);
  PlatformStr = GetPlatformStr();
  v7 = Concat_5224608("SAVE", PlatformStr);
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
LABEL_21:
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
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  slMain_c *v4;
  FsSaveData_o *saveData;
  dds3GlobalWork_t_o **p_dds3Work;
  dds3AdditionWork_t_o **p_AdditionWork;
  s32 gslSelect;
  u64 *v11;

  dds3Work = DDS3_GBWK;
  if (gslMode != 5)
  {
    else
    {
      if ((v4->_2.bitflags2 & 2) != 0)
        goto LABEL_18;
    }
    p_dds3Work = &dds3Work;
    p_AdditionWork = &AdditionWork;
    goto LABEL_24;
  }
  else
  {
    if ((v4->_2.bitflags2 & 2) != 0)
      goto LABEL_13;
  }
  p_dds3Work = &dds3Work;
  p_AdditionWork = &AdditionWork;
  gslSelect = 20;
LABEL_24:
  loadMode = Load_18090368(saveData, gslSelect, p_dds3Work, p_AdditionWork);
  v11 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v11,
    0,
    Method_slMain_slLoadProc_readFile__);
  return v11;
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
LABEL_7:
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
  UnityEngine_Object_o *saveUI;
  s32 v5;
  s16 v7;
  s32 v8;
  s32 slQueryYesNoCursor;
  UnityEngine_GameObject_o *choiceBaseObj;
  System_String_o *v121;
  System_String_o *v122;
  System_String_o *moji;

  v122 = 0;
  moji = 0;
  v121 = 0;
  NewSpecific(uint, 2u);
  saveUI = _saveUI;
  if (op_Equality(saveUI, 0, 0))
    return 0;
  if ((v7 & 0x200) == 0)
  {
    v8 = 0;
    if (slQueryYesNoCursor != -1)
      goto LABEL_13;
LABEL_194:
    if (!v8)
      goto LABEL_199;
LABEL_195:
    goto LABEL_199;
  }
  v8 = v7 & 0x200;
  if (slQueryYesNoCursor == -1)
    goto LABEL_194;
LABEL_13:
  else if (slQueryYesNoMsg)
  {
    goto LABEL_16;
  }
  if (v8)
    goto LABEL_195;
LABEL_199:
  choiceBaseObj = _saveUI->_choiceBaseObj;
  cmpSetupObject(choiceBaseObj, 0);
  v5 = 0;
  if (saveButtonGuideFlag == 1)
  {
    ButtonGuideDispSet("SAV01", 0, 0, 90);
    v5 = 0;
    saveButtonGuideFlag = 0;
  }
  return v5;
}

// 0x15ee820
void *slQueryYesNoProc(dds3ProcessID_t *procId) {
  slMain_c *v2;
  s32 slQueryYesNoMsg;
  struct slMain_StaticFields **p_static_fields;
  s32 slQueryYesNoKeyFlag;
  bool v9;
  bool v12;
  bool v16;
  s32 v20;
  bool v22;
  u64 *v26;
  s32 v36;
  s16 v37;
  s32 v38;
  bool v41;
  struct slMain_StaticFields *v47;
  s32 v48;
  bool v51;
  bool v55;
  s32 v59;
  s16 v60;
  s32 v61;
  bool v63;
  s16 v65;
  s32 v66;

  else
  {
    if (slQueryYesNoMsg == 5)
      goto LABEL_29;
  }
  else if (slQueryYesNoMsg != 6)
  {
LABEL_9:
    else if (slQueryYesNoMsg == 4)
    {
      goto LABEL_164;
    }
    if (slQueryYesNoMsg != 8)
    {
      if (slQueryYesNoKeyFlag)
      {
LABEL_20:
        if ((v2->_2.bitflags2 & 2) != 0)
          goto LABEL_21;
        goto LABEL_23;
      }
      v41 = DDS3_PADCHECK_TRIG(7);
      if (v41)
      {
        if (slProcShutDownFlg == 1)
        {
          if (slQueryYesNoCursor != 1)
          {
            p2sdPlaySeEx(0, 127, 63);
          }
          slQueryYesNoCursor = 1;
          if ((v2->_2.bitflags2 & 2) == 0)
            goto LABEL_23;
          goto LABEL_21;
        }
      }
      v51 = DDS3_PADCHECK_TRIG(6);
      if (v51)
      {
        if (slProcShutDownFlg == 1)
        {
          if (slQueryYesNoCursor)
          {
            p2sdPlaySeEx(0, 127, 63);
          }
          slQueryYesNoCursor = 0;
          if ((v2->_2.bitflags2 & 2) == 0)
            goto LABEL_23;
          goto LABEL_21;
        }
      }
      v55 = DDS3_PADCHECK_TRIG(1);
      if (!v55)
        goto LABEL_495;
      if (slProcShutDownFlg == 1)
      {
        if (!slQueryYesNoCursor)
        {
          if (slQueryYesNoMsg == 1)
          {
            if (!gSlEndingMode)
              goto LABEL_496;
          }
          if (slQueryYesNoMsg == 9)
          {
            if (gSlEndingMode)
              goto LABEL_496;
          }
        }
        if (slQueryYesNoCursor)
          goto LABEL_497;
        if (slQueryYesNoMsg == 3)
        {
LABEL_496:
          v59 = 17;
        }
        else
        {
LABEL_497:
          v59 = 8;
        }
        p2sdPlaySeEx(v59, 127, 63);
        if ((v65 & 0x200) != 0)
        {
          v66 = v65 & 0x200;
          if (!slQueryYesNoCursor)
          {
LABEL_479:
            slQueryYesNoKeyFlag = 1;
            if ((v2->_2.bitflags2 & 2) == 0)
              goto LABEL_23;
            goto LABEL_21;
          }
        }
        else
        {
          v66 = 0;
          if (!slQueryYesNoCursor)
            goto LABEL_479;
        }
      }
      else
      {
LABEL_495:
        v63 = DDS3_PADCHECK_TRIG(3);
        if (!v63)
          goto LABEL_20;
        if (slProcShutDownFlg != 1)
          goto LABEL_20;
        p2sdPlaySeEx(10, 127, 63);
          goto LABEL_490;
      }
LABEL_490:
      goto LABEL_491;
    }
LABEL_164:
    else if (DDS3_PADCHECK_TRIG(7))
    {
      goto LABEL_167;
    }
    if (DDS3_PADCHECK_TRIG(6))
    {
      if (slQueryYesNoCursor)
      {
        p2sdPlaySeEx(0, 127, 63);
      }
      v26 = 0;
      slQueryYesNoCursor = 0;
      return v26;
    }
    if (!DDS3_PADCHECK_TRIG(1))
    {
      v26 = 0;
      if (!DDS3_PADCHECK_TRIG(3))
        return v26;
      p2sdPlaySeEx(10, 127, 63);
      slQueryYesNoCursor = -1;
      slQueryYesNoMsg = 0;
      return Invoke(slQueryNoFunc, 0);
    }
    if (!slQueryYesNoCursor)
    {
      if (slQueryYesNoMsg == 1)
        goto LABEL_498;
    }
    if (!slQueryYesNoCursor)
    {
      if (slQueryYesNoMsg == 3)
        goto LABEL_498;
    }
    if (slQueryYesNoCursor)
      goto LABEL_499;
    if (slQueryYesNoMsg != 9)
    {
LABEL_499:
      v36 = 8;
    }
    else
    {
LABEL_498:
      v36 = 17;
    }
    p2sdPlaySeEx(v36, 127, 63);
    if ((v60 & 0x200) != 0)
    {
      v61 = v60 & 0x200;
      if (!slQueryYesNoCursor)
      {
LABEL_421:
        if (v61)
        {
LABEL_334:
        }
LABEL_336:
        slQueryYesNoCursor = -1;
        (*p_static_fields)->slQueryYesNoMsg = 0;
        return Invoke((*p_static_fields)->slQueryYesFunc, 0);
      }
    }
    else
    {
      v61 = 0;
      if (!slQueryYesNoCursor)
        goto LABEL_421;
    }
    if (!v61)
    {
LABEL_340:
      slQueryYesNoCursor = -1;
      (*p_static_fields)->slQueryYesNoMsg = 0;
      v47 = *p_static_fields;
      return Invoke(slQueryNoFunc, 0);
    }
LABEL_338:
    goto LABEL_340;
  }
LABEL_29:
  else if (slQueryYesNoKeyFlag)
  {
    goto LABEL_32;
  }
  v9 = DDS3_PADCHECK_TRIG(7);
  if (v9)
  {
    if (slProcShutDownFlg == 1)
    {
      if (slQueryYesNoCursor != 1)
      {
        p2sdPlaySeEx(0, 127, 63);
      }
      slQueryYesNoCursor = 1;
      if ((v2->_2.bitflags2 & 2) == 0)
        goto LABEL_321;
LABEL_33:
      goto LABEL_321;
    }
  }
  v12 = DDS3_PADCHECK_TRIG(6);
  if (!v12)
    goto LABEL_500;
  if (slProcShutDownFlg != 1)
  {
LABEL_500:
    v16 = DDS3_PADCHECK_TRIG(1);
    if (v16)
    {
      if (slProcShutDownFlg == 1)
      {
        if (!slQueryYesNoCursor)
        {
          if (slQueryYesNoMsg == 1)
            goto LABEL_501;
        }
        if (slQueryYesNoCursor)
          goto LABEL_502;
        if (slQueryYesNoMsg != 3)
        {
LABEL_502:
          v20 = 8;
        }
        else
        {
LABEL_501:
          v20 = 17;
        }
        p2sdPlaySeEx(v20, 127, 63);
        if ((v37 & 0x200) != 0)
        {
          v38 = v37 & 0x200;
          if (!slQueryYesNoCursor)
          {
LABEL_254:
            slQueryYesNoKeyFlag = 1;
            if ((v2->_2.bitflags2 & 2) != 0)
              goto LABEL_33;
            goto LABEL_321;
          }
        }
        else
        {
          v38 = 0;
          if (!slQueryYesNoCursor)
            goto LABEL_254;
        }
LABEL_318:
LABEL_319:
        goto LABEL_320;
      }
    }
    v22 = DDS3_PADCHECK_TRIG(3);
    if (v22)
    {
      if (slProcShutDownFlg == 1)
      {
        p2sdPlaySeEx(10, 127, 63);
          goto LABEL_319;
        goto LABEL_318;
      }
    }
LABEL_32:
    if ((v2->_2.bitflags2 & 2) == 0)
      goto LABEL_321;
    goto LABEL_33;
  }
  if (slQueryYesNoCursor)
  {
    p2sdPlaySeEx(0, 127, 63);
  }
  slQueryYesNoCursor = 0;
  if ((v2->_2.bitflags2 & 2) != 0)
    goto LABEL_33;
LABEL_321:
  v48 = slQueryYesNoKeyFlag;
  switch (v48)
  {
    case 2:
      if ((v2->_2.bitflags2 & 2) == 0)
        goto LABEL_340;
      goto LABEL_338;
    case 1:
      goto LABEL_333;
    case 0:
      else if (slQueryYesNoMsg == 5)
      {
        goto LABEL_327;
      }
      break;
  }
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
  s32 gslSelect;
  struct System_Char_array *verstr;
  struct System_Char_array *v10;
  struct System_Char_array *v12;
  struct GameFileInfo_t_o *GameFileInfo;
  struct GameFileInfo_t_o *v17;
  bool v19;
  s16 v21;
  u64 v22;
  s16 v25;
  char *v26;
  struct GameFileInfo_t_array *gslInfo;
  bool v29;
  struct System_Char_array *end_list;
  struct GameFileInfo_t_o *v34;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct System_Byte_array *cname_nums;
  dds3GlobalWork_c *v38;
  struct GameFileInfo_t_array *v41;
  struct System_Char_array *v44;
  struct System_Char_array *v45;
  u16 v46;
  struct GameFileInfo_t_array *v47;
  struct System_Char_array *v49;
  struct System_Char_array *v50;
  u16 v52;
  struct GameFileInfo_t_array *v54;
  struct System_Char_array *v56;
  struct System_Char_array *v57;
  u16 v59;
  struct GameFileInfo_t_array *v62;
  struct GameFileInfo_t_array *v65;
  struct GameFileInfo_t_array *v67;
  struct GameFileInfo_t_array *v69;
  struct GameFileInfo_t_array *v71;
  struct GameFileInfo_t_array *v73;
  struct GameFileInfo_t_array *v75;
  struct GameFileInfo_t_array *v77;
  struct GameFileInfo_t_array *v79;
  GameFileInfo_t_o *v81;
  s64 v82;
  struct GameFileInfo_t_array *v84;
  u64 v85;
  struct GameFileInfo_t_array *v88;
  struct System_Char_array *v91;
  struct System_Char_array *v92;
  s16 v94;
  struct GameFileInfo_t_o *v98;
  struct GameFileInfo_t_array *v100;
  struct GameFileInfo_t_array *v102;
  struct dds3GlobalWork_t_o *v106;
  s32 gSlSaveMode;
  struct System_String_o *slSaveData_writeFile_wk_ptr;
  u64 *v110;
  intptr_t *v111;
  u64 *v114;
  u64 *v118;
  u64 dateData;
  System_String_o *path;

  path = 0;
  dateData = 0;
  saveDataInit = init;
  gslDrawFlagFile = 2;
  path = "";
  mcMakeFileName(&path, gslSelect);
  verstr = DDS3_GBWK->GameFileInfo->verstr;
  verstr->m_Items[0] = 86;
  v10 = DDS3_GBWK->GameFileInfo->verstr;
  v10->m_Items[1] = 69;
  v12 = DDS3_GBWK->GameFileInfo->verstr;
  v12->m_Items[2] = 82;
  DDS3_GBWK->GameFileInfo->ver = saveVer;
  DDS3_GBWK->GameFileInfo->TmnlMode = DDS3_GBWK->fldSave->tmnltype;
  DDS3_GBWK->GameFileInfo->TmnlId = DDS3_GBWK->fldSave->tmnlid;
  GameFileInfo = DDS3_GBWK->GameFileInfo;
  GameFileInfo->Lv = datGetPlayerLevel();
  DDS3_GBWK->GameFileInfo->PlayTime = DDS3_GBWK->playtime;
  v17 = DDS3_GBWK->GameFileInfo;
  v17->mode = cfgGetBit(9u);
  v19 = evtBitCheck(3712);
  if (v19)
  {
    v21 = 1;
  }
  else
  {
    v21 = 0;
  }
  v22 = 0;
  DDS3_GBWK->GameFileInfo->dante_mode = v21;
  {
LABEL_31:
    goto LABEL_35;
  }
  while (1)
  {
LABEL_35:
    if (v22 >= SLODWORD(gslInfo->m_Items[gslSelect]->end_list->max_length))
      break;
    v29 = evtBitCheck(v22 + 2209);
    if (v29)
    {
      end_list = DDS3_GBWK->GameFileInfo->end_list;
      v25 = 1;
    }
    else
    {
      end_list = DDS3_GBWK->GameFileInfo->end_list;
      v25 = 0;
    }
    v26 = end_list + 2 * v22++;
    *(v26 + 16) = v25;
      goto LABEL_31;
  }
  v34 = DDS3_GBWK->GameFileInfo;
  v34->cname_code = frGetCNameString(0);
  cname_nums = DDS3_GBWK->cname_nums;
  DDS3_GBWK->GameFileInfo->cname_nums = cname_nums->m_Items[0];
  if (init)
  {
      goto LABEL_135;
    goto LABEL_59;
  }
  v41 = gslInfo;
  v44 = v41->m_Items[gslSelect]->verstr;
  v45 = DDS3_GBWK->GameFileInfo->verstr;
  v46 = v45->m_Items[0];
  v44->m_Items[0] = v46;
  v47 = gslInfo;
  v49 = v47->m_Items[gslSelect]->verstr;
  v50 = DDS3_GBWK->GameFileInfo->verstr;
  v52 = v50->m_Items[1];
  v49->m_Items[1] = v52;
  v54 = gslInfo;
  v56 = v54->m_Items[gslSelect]->verstr;
  v57 = DDS3_GBWK->GameFileInfo->verstr;
  v59 = v57->m_Items[2];
  v56->m_Items[2] = v59;
  v62 = gslInfo;
  v62->m_Items[gslSelect]->ver = DDS3_GBWK->GameFileInfo->ver;
  v65 = gslInfo;
  v65->m_Items[gslSelect]->TmnlMode = DDS3_GBWK->GameFileInfo->TmnlMode;
  v67 = gslInfo;
  v67->m_Items[gslSelect]->TmnlId = DDS3_GBWK->GameFileInfo->TmnlId;
  v69 = gslInfo;
  v69->m_Items[gslSelect]->Lv = DDS3_GBWK->GameFileInfo->Lv;
  v71 = gslInfo;
  v71->m_Items[gslSelect]->PlayTime = DDS3_GBWK->GameFileInfo->PlayTime;
  v73 = gslInfo;
  v73->m_Items[gslSelect]->endcnt = DDS3_GBWK->GameFileInfo->endcnt;
  v75 = gslInfo;
  v75->m_Items[gslSelect]->newfile = DDS3_GBWK->GameFileInfo->newfile;
  v77 = gslInfo;
  v77->m_Items[gslSelect]->mode = DDS3_GBWK->GameFileInfo->mode;
  v79 = gslInfo;
  v81 = v79->m_Items[gslSelect];
  v82 = 16;
  v81->dante_mode = DDS3_GBWK->GameFileInfo->dante_mode;
  {
LABEL_103:
    goto LABEL_106;
  }
  while (1)
  {
LABEL_106:
    v84 = gslInfo;
    v85 = v82 - 16;
    if (v85 >= SLODWORD(v84->m_Items[gslSelect]->end_list->max_length))
      break;
    v88 = gslInfo;
    v91 = v88->m_Items[gslSelect]->end_list;
    v92 = DDS3_GBWK->GameFileInfo->end_list;
    v94 = *(&v92->obj.klass + v82);
    *(&v91->obj.klass + v82++) = v94;
      goto LABEL_103;
  }
  dateData = get_Now().dateData;
  v98 = DDS3_GBWK->GameFileInfo;
  v98->saveTime = sub_2DCC50(&dateData);
  v100 = gslInfo;
  v100->m_Items[gslSelect]->cname_code = DDS3_GBWK->GameFileInfo->cname_code;
  v102 = gslInfo;
  v102->m_Items[gslSelect]->cname_nums = DDS3_GBWK->GameFileInfo->cname_nums;
  if ((v38->_2.bitflags2 & 2) != 0)
  {
LABEL_59:
  }
LABEL_135:
  v106 = DDS3_GBWK;
  dds3Work = v106;
  if (!gSlSaveMode)
    goto LABEL_142;
  else if (gSlSaveMode == 2)
  {
    goto LABEL_142;
  }
  v110 = Allocate(slMain_slSaveWriteFile_endFuncDelegate);
  v111 = &Method_slMain_slSaveWriteEnd_baseIcon__;
LABEL_153:
  v114 = v110;
  _ctor(v110, 0, *v111, 0);
  slSaveWriteFile_buff = slSaveData_writeFile_wk_ptr;
  slSaveWriteFile_size = slSaveData_writeFile_wk_size;
  slSaveWriteFile_endFunc = v114;
  slSaveWriteFile_dataWaitPtr = 0;
  v118 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v118,
    0,
    Method_slMain_slSaveProc_openFile__);
  return v118;
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
LABEL_7:
  return slSaveData_writeFile(0);
}

// 0x15eb6a0
void *slSaveProc_Write_deleteIconSys(dds3ProcessID_t *procId) {
  return 0;
}

// 0x15eb4a0
void *slSaveProc_Write_mkdir(dds3ProcessID_t *procId) {
  u64 *v2;

LABEL_7:
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
LABEL_6:
    v3 = Allocate(System_Func_dds3ProcessID_t__object_);
    v4 = &Method_slMain_slSaveProc_waitDataReady__;
    goto LABEL_15;
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
LABEL_15:
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
    goto LABEL_15;
LABEL_6:
LABEL_10:
  gslErrorKeyFlag = 0;
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  v5 = &Method_slMain_slHitAnyKeyNoChkProc__;
LABEL_16:
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
  slMain_c *v3;

  else
  {
    if (gslInfoCode)
      goto LABEL_6;
  }
  gSlWindowCnt = 0;
  if ((v3->_2.bitflags2 & 2) != 0)
  {
LABEL_7:
  }
LABEL_14:
  gslInfoCode = id;
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
  v14 = gslInfo;
  loadHeaderGameFileInfo(saveData, 20, &v14->m_Items[20]);
  v16 = gslInfo;
  return v16->m_Items[20]->PlayTime > 0;
}

// 0x15e1490
void *slSuspendInit(void) {
  struct GameFileInfo_t_array *gslInfo;
  s64 gslSelect;
  u64 *v6;

  gslSelect = 20;
  v6 = Allocate(GameFileInfo_t);
  GameFileInfo_t___ctor(v6);
  gslInfo->m_Items[gslSelect] = v6;
  return slSaveData_writeFile(1);
}

// 0x15e1320
void slSuspendKill(void) {
LABEL_7:
  fmShutDown();
  else
  {
    ButtonGuideDispOff();
  }
}

// 0x15e0530
void *slSuspendProc(void) {
  struct GameFileInfo_t_array *gslInfo;
  s64 gslSelect;
  u64 *v6;

  gslMode = 0;
  gslSelect = 20;
  v6 = Allocate(GameFileInfo_t);
  GameFileInfo_t___ctor(v6);
  gslInfo->m_Items[gslSelect] = v6;
  return slSaveData_writeFile(0);
}

// 0x15e9f10
void slTitleSet(s32 Code) {
  TMPro_TMP_Text_o *titleMsg;
  System_String_o *LocalizeText;
  System_Object_array *v6;
  s64 *v8;
  System_String_o *v11;
  s32 v13;
  s32 v14;

  if (Code == 12)
  {
    titleMsg = _saveUI->_titleMsg;
    LocalizeText = GetLocalizeText("MC_MSGSELECTLOADFILE");
    v13 = 0;
    v6 = NewSpecific(object, 1u);
    v8 = sub_8D3950(s32, &v13);
    if (!v8)
      goto LABEL_21;
    goto LABEL_20;
  }
  if (Code != 11)
    return;
  titleMsg = _saveUI->_titleMsg;
  LocalizeText = GetLocalizeText("MC_MSGSELECTSAVEFILE");
  v14 = 0;
  v6 = NewSpecific(object, 1u);
  v8 = sub_8D3950(s32, &v14);
  if (v8)
  {
LABEL_20:
  }
LABEL_21:
  v6->m_Items[0] = v8;
  v11 = RepColTag(LocalizeText, v6);
  set_text(titleMsg, v11);
}

// 0x15e2220
void *slTop(void) {
  slMain_c *v2;
  u64 v3;
  s16 v4;
  char *v5;
  s32 i;
  struct slMain_StaticFields **p_static_fields;
  struct System_Int32_array *gslStatFileInfo;
  u64 max_length_low;
  slMain_c *v13;
  s64 v14;
  u64 v15;
  struct GameFileInfo_t_array *gslInfo;
  u32 *v19;
  u64 *v20;
  bool v25;
  s64 *v28;
  u64 *v31;

  gSlSelCnt = 0;
  gslSelTop = 0;
  v3 = 0;
  gslSelect = -1;
  v4 = *&v2->_2.bitflags1;
  if ((v4 & 0x200) != 0)
    goto LABEL_10;
LABEL_9:
  for (i = 0; ; i = v4 & 0x200)
  {
    max_length_low = LODWORD(gslStatFileInfo->max_length);
    if (v3 >= max_length_low)
      break;
    else if (v3 >= max_length_low)
    {
      goto LABEL_17;
    }
    v5 = gslStatFileInfo + 4 * v3++;
    *(v5 + 8) = 0;
    if ((v4 & 0x200) == 0)
      goto LABEL_9;
LABEL_10:
  }
  gslCheckCardWait = 15;
  (*p_static_fields)->gSlNowCardCheck = 1;
  slSetInfo(1);
  gslDrawFlagFile = 0;
  v14 = 4;
  v15 = 0;
  if ((v13->_2.bitflags2 & 2) != 0)
  {
LABEL_26:
    goto LABEL_28;
  }
  while (1)
  {
LABEL_28:
    if (!*(&gslInfo->obj.klass + v14))
      break;
    if (v14 == 24)
      goto LABEL_43;
LABEL_25:
    v15 = ++v14 - 4;
      goto LABEL_26;
  }
  v19 = gslInfo;
  v20 = Allocate(GameFileInfo_t);
  GameFileInfo_t___ctor(v20);
  *&v19[2 * v14] = v20;
  if (v14 != 24)
    goto LABEL_25;
LABEL_43:
  v25 = CampBaseOff(kernelObject);
  LOBYTE(v26[2].klass->_1.this_arg.data) = v25;
  SetupUI();
  if (gslMode == 5)
  {
    v28 = &"CNT01";
  }
  else
  {
    v28 = &"SAV01";
  }
  ButtonGuideDispSet(*v28, 0, 0, 90);
  saveButtonGuideFlag = 0;
  v31 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v31,
    0,
    Method_slMain_slSaveProc_CheckCard__);
  return v31;
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
LABEL_16:
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
