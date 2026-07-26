#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct cmbGlobalWork_t cmbGlobalWork_t;
typedef struct cmpCmdSelInfo_t cmpCmdSelInfo_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclPanelMoverFunc_t fclPanelMoverFunc_t;
typedef struct fclPanelMover_t fclPanelMover_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static char *gFclCombineTexFile[7];
static cmbGlobalWork_t *CMB_GBWK;
static s8 gProcessStat;
static char *gCombineMenuStr[4];
static u8 gCmdMenuFlag[UNKNOWN_ARRAY_SIZE];
static char *gZensyoMenuStr[3];
static char *gTalkMenuStr[8];
static u8 gTalkMenuFlag[UNKNOWN_ARRAY_SIZE];
static void *bgmkeys;
static s32 bgmkeysidx;

void FadeOutWindow(void);
void FilterDelete(void);
void FinalizeGameObject(void);
void FinalizeUI(void);
s32 FindId(s32 type, char *name);
char *GetAppendix(void);
char *GetPlatformStr(void);
void InitializeGameObject(void);
void InitializeModelCameraForUnity(void);
void InitializeUI(s32 eventno);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void LoadLocalizeText(char *key, char *filename);
void Log(char *fmt, void **parray);
void Remove(char *key);
void SetRootMenuText(cmpCmdSelInfo_t **csel, char **menu);
void UnloadAB(AssetBundleCtrl *this, char *key);
void WindowDispOff(bool sw);
dds3Basic_t *dds3GetActiveScene(void);
u32 dds3GetProcessStat(dds3ProcessID_t **id);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void dds3VisibleSceneBasic(dds3Basic_t **basic, s32 visible);
bool evtBitCheck(s32 no);
void evtDisableMoonCalc(void);
void evtDisableMoonDraw(void);
void evtEnableMoonDraw(void);
s32 evtGetAgeOfMoon(void);
void evtStartEvent(s32 no);
s8 fclChkSignal(s8 Idx);
void fclClearSignal(s8 Idx);
void fclCombineBGM(s8 Mode);
void fclCombineEventStart(s8 Signal);
void fclCombineInitPanelMover(cmbGlobalWork_t *pData);
void fclCombineInitialize(void);
s32 fclCombineTokusyuBGM(void);
s32 fclEncycWork(void);
void fclInitPanelMover(fclPanelMover_t *pMover, s32 DefX, s32 DefY, s32 MaxOfsX, s32 MaxOfsY, s32 DefRate, s32 Spd, fclPanelMoverFunc_t *MoverFunc);
void fclScriptForcedEnd(dds3ProcessID_t *PID);
s8 fclSetVal(s8 Idx, s32 Val);
void fclUpdateInit(void);
bool fldProc_CallSisetuReturn(void);
void fldSetCharClr(void);
s32 p2sdFadeIn(s32 a);
s32 p2sdFadeOut(s32 a);
s32 p2sdPlayBGM(s32 a);
void sdfTexFree(sdfTexHandle_t *aHandle);

// 0x146b990
dds3ProcessFunc_t *_fclCombineCalc(dds3ProcessID_t *PID) {
  u32 Current;
  s32 v7;
  s32 v8;
  s32 v10;
  dds3Basic_t_o *basic;
  dds3ProcessID_t_o *id;

  basic = 0;
  if (fclChkSignal(1))
  {
    id = 0;
    id = dds3SearchProcessName(StringLiteral_16163);
    if (dds3GetProcessStat(&id) - 1 <= 2)
    {
      Current = CMB_GBWK->SeqInfo->Current;
      if (Current <= 0x12)
      {
        v7 = 1 << Current;
        if ((v7 & 0x173) != 0)
        if ((v7 & 0x6000C) != 0)
      }
      basic = dds3GetActiveScene();
      if (basic)
      {
        v8 = 0;
        dds3VisibleSceneBasic(&basic, v8);
        {
          v10 = CMB_GBWK->SeqInfo->Current;
          if (!CMB_GBWK->SeqInfo->Current || v10 == 18 || (v10 - 2) <= 2)
          {
            evtEnableMoonDraw();
          }
          else
          {
            evtDisableMoonDraw();
          }
          if (fclEncycWork())
          {
            evtDisableMoonDraw();
          }
          cmbCalcSequence(PID);
          return 0;
        }
      }
    }
    basic = dds3GetActiveScene();
    if (basic)
    {
      v8 = 1;
    }
  }
  return 0;
}

// 0x146bcf0
void *_fclCombineDraw(dds3ProcessID_t *PID) {
  if (fclChkSignal(1))
  {
    cmbDrawSequence(PID);
  }
  return 0;
}

// 0x146bd90
void *_fclCombineUpdate(dds3ProcessID_t *PID) {
    fclChkSignal(0);
    IsLoad(0, 0);
    fclUpdateInit();
    return 0;
}

// 0x146c3c0
s8 fclChkCombineProcess(void) {
  struct fclCombineInit_StaticFields *static_fields;
  s32 gProcessStat;

  static_fields = fclCombineInit->static_fields;
  gProcessStat = static_fields->gProcessStat;
  if (gProcessStat == 1)
    return 1;
  if (gProcessStat != 2)
    return 0;
  static_fields->gProcessStat = 0;
  return 0;
}

// 0x146a630
void fclCombineBGM(s8 Mode) {
    FindId(0, 0);
    p2sdFadeIn(0);
    p2sdFadeOut(0);
    p2sdPlayBGM(0);
}

// 0x1454b10
s8 fclCombineChkEventStat(void) {
  u32 ProcessStat;
  dds3ProcessID_t_o *id;

  id = 0;
  id = dds3SearchProcessName(StringLiteral_16163);
  ProcessStat = dds3GetProcessStat(&id);
  return ProcessStat == 1 || (ProcessStat & 0xFFFFFFFE) == 2;
}

// 0x146b390
void *fclCombineDestroy(dds3ProcessID_t *PID) {
  System_String_o *v4;
  System_Object_array *v6;
  dds3ProcessID_t_o *ScriptPID;
  System_String_o *v12;
  System_Object_array *v14;
  System_String_o *PlatformStr;
  System_String_o *v26;
  s32 v28;
  System_String_o *Item;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v37;
  AssetBundleCtrl_o *v38;
  AssetBundleCtrl_o *v40;
  System_String_o *Appendix;
  System_String_o *v42;

  v4 = Concat(StringLiteral_16178, CMB_GBWK);
  v6 = Empty_string_();
  Log(v4, v6, 0);
  if (!CMB_GBWK)
  gKeisyoListBuf = 0;
  cmpModelFreeResource();
  cmpModelEnd();
  ScriptPID = CMB_GBWK->ScriptPID;
  fclScriptForcedEnd(ScriptPID);
  v12 = Concat(StringLiteral_16179, CMB_GBWK);
  v14 = Empty_string_();
  Log(v12, v14, 0);
  CMB_GBWK->pScriptData = 0;
  CMB_GBWK->pCollectData = 0;
  fclSetVal(1, 100);
  fclCombineBGM(1);
  WindowDispOff(0);
  CMB_GBWK->bReadPhase = 0;
  CMB_GBWK = 0;
  gProcessStat = 2;
  evtDisableMoonDraw();
  FinalizeGameObject();
  FinalizeUI();
  Remove(StringLiteral_16177, 0);
  Remove(StringLiteral_16176, 0);
  Remove(StringLiteral_16175, 0);
  Remove(StringLiteral_12292, 0);
  Remove(StringLiteral_16174, 0);
  PlatformStr = GetPlatformStr();
  v26 = Concat_5224608(StringLiteral_12292, PlatformStr);
  Remove(v26, 0);
  v28 = 0;
  {
  }
  while (v28 < _get_Count(bgmkeys))
  {
    asset_bc = get_asset_bc();
    Item = _get_Item(
             bgmkeys,
             v28);
    UnloadAB(asset_bc, Item);
    ++v28;
  }
  _Clear(bgmkeys);
  bgmkeysidx = 0;
  v37 = get_asset_bc();
  UnloadAB(v37, StringLiteral_16165);
  v38 = get_asset_bc();
  UnloadAB(v38, StringLiteral_4897);
  v40 = get_asset_bc();
  Appendix = GetAppendix();
  v42 = Concat_5224608(StringLiteral_4897, Appendix);
  UnloadAB(v40, v42);
  fldSetCharClr();
  PID->func_ans = -1;
  return 0;
}

// 0x1454d40
void fclCombineDisableCmdZensyo(void) {
  bool v1;
  bool v2;
  fclCombineInit_c *v4;
  struct fclCombineInit_StaticFields *static_fields;
  cmpCursorInfo_t_o *CursorInfo;
  System_Byte_array *gCmdMenuFlag;
  struct System_Byte_array *v9;
  struct System_Byte_array *v12;
  struct cmpCursorPos_t_o *CursorPos;

  v1 = evtBitCheck(40);
  v2 = evtBitCheck(2208);
  if (!v1 && !v2)
  {
    static_fields = v4->static_fields;
    CursorInfo = static_fields->CMB_GBWK->CmdSelInfo->CursorInfo;
    gCmdMenuFlag = static_fields->gCmdMenuFlag;
    cmpSetCursorFlag(CursorInfo, gCmdMenuFlag);
    v9 = gCmdMenuFlag;
    if ((v9->m_Items[1] & 2) == 0)
    {
      v12 = gCmdMenuFlag;
      v12->m_Items[1] |= 2u;
      CursorPos = CMB_GBWK->CmdSelInfo->CursorInfo->CursorPos;
      ++CursorPos->InvisibleListNums;
    }
  }
}

// 0x1458ec0
void fclCombineDisableTalkIkenie(void) {
  fclCombineInit_c *v2;
  struct fclCombineInit_StaticFields *static_fields;
  cmpCursorInfo_t_o *CursorInfo;
  System_Byte_array *gTalkMenuFlag;
  struct System_Byte_array *v7;
  struct System_Byte_array *v10;
  struct cmpCursorPos_t_o *CursorPos;

  if (!evtBitCheck(37))
  {
    static_fields = v2->static_fields;
    CursorInfo = static_fields->CMB_GBWK->TalkSelInfo->CursorInfo;
    gTalkMenuFlag = static_fields->gTalkMenuFlag;
    cmpSetCursorFlag(CursorInfo, gTalkMenuFlag);
    v7 = gTalkMenuFlag;
    if ((v7->m_Items[2] & 2) == 0)
    {
      v10 = gTalkMenuFlag;
      v10->m_Items[2] |= 2u;
      CursorPos = CMB_GBWK->TalkSelInfo->CursorInfo->CursorPos;
      ++CursorPos->InvisibleListNums;
    }
  }
}

// 0x1459020
void fclCombineDisableTalkMagatama(void) {
  fclCombineInit_c *v2;
  struct fclCombineInit_StaticFields *static_fields;
  cmpCursorInfo_t_o *CursorInfo;
  System_Byte_array *gTalkMenuFlag;
  struct System_Byte_array *v7;
  struct System_Byte_array *v10;
  struct cmpCursorPos_t_o *CursorPos;

  if (evtBitCheck(163))
  {
    static_fields = v2->static_fields;
    CursorInfo = static_fields->CMB_GBWK->TalkSelInfo->CursorInfo;
    gTalkMenuFlag = static_fields->gTalkMenuFlag;
    cmpSetCursorFlag(CursorInfo, gTalkMenuFlag);
    v7 = gTalkMenuFlag;
    if ((v7->m_Items[6] & 2) == 0)
    {
      v10 = gTalkMenuFlag;
      v10->m_Items[6] |= 2u;
      CursorPos = CMB_GBWK->TalkSelInfo->CursorInfo->CursorPos;
      ++CursorPos->InvisibleListNums;
    }
  }
}

// 0x1459180
void fclCombineDisableTalkZensyo(void) {
  bool v1;
  bool v2;
  fclCombineInit_c *v4;
  struct fclCombineInit_StaticFields *static_fields;
  cmpCursorInfo_t_o *CursorInfo;
  System_Byte_array *gTalkMenuFlag;
  struct System_Byte_array *v9;
  struct System_Byte_array *v12;
  struct cmpCursorPos_t_o *CursorPos;

  v1 = evtBitCheck(40);
  v2 = evtBitCheck(2208);
  if (!v1 && !v2)
  {
    static_fields = v4->static_fields;
    CursorInfo = static_fields->CMB_GBWK->TalkSelInfo->CursorInfo;
    gTalkMenuFlag = static_fields->gTalkMenuFlag;
    cmpSetCursorFlag(CursorInfo, gTalkMenuFlag);
    v9 = gTalkMenuFlag;
    if ((v9->m_Items[5] & 2) == 0)
    {
      v12 = gTalkMenuFlag;
      v12->m_Items[5] |= 2u;
      CursorPos = CMB_GBWK->TalkSelInfo->CursorInfo->CursorPos;
      ++CursorPos->InvisibleListNums;
    }
  }
}

// 0x146a1f0
void fclCombineEventEnd(void) {
  fclSetVal(1, 100);
}

// 0x1454bb0
void fclCombineEventStart(s8 Signal) {
  fclSetVal(1, Signal);
  fclClearSignal(1);
  evtStartEvent(800);
}

// 0x146a870
void fclCombineInitPanelMover(cmbGlobalWork_t *pData) {
  struct fclPanelMover_t_array *PanelMover;
  il2cpp_array_size_t max_length;
  u64 v5;
  fclPanelMover_t_o *v7;
  u64 *v8;

  PanelMover = pData->PanelMover;
  max_length = PanelMover->max_length;
  if (max_length >= 1)
  {
    v5 = 0;
    do
    {
      v7 = PanelMover->m_Items[v5];
      v8 = Allocate(fclPanelMoverFunc_t);
      fclPanelMoverFunc_t___ctor(v8, 0, Method_fclPanel_fclDefaultMoverFunc__);
      fclInitPanelMover(v7, 0, 0, 50, 0, 512, 48, v8);
      PanelMover = pData->PanelMover;
      LODWORD(max_length) = PanelMover->max_length;
      ++v5;
    }
    while (v5 < max_length);
  }
}

// 0x146a980
void fclCombineInitialize(void) {
  u64 *v1;
  u64 *v2;
  cmpSeqInfo_t_o *SeqInfo;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *Appendix;
  System_String_o *v12;
  System_String_o *v13;
  System_String_o *v14;
  AssetBundleCtrl_o *v15;
  AssetBundleCtrl_o *v16;
  s32 inited;
  fclCombineInit_c *v21;
  struct fclCombineInit_StaticFields *static_fields;
  s64 *v23;
  fclCombineInit_c *v24;
  fclCombineInit_c *v25;
  s32 v27;
  System_String_o *Item;
  System_String_o *v30;
  AssetBundleCtrl_o *v33;

  v1 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v1);
  v2 = Allocate(cmbGlobalWork_t);
  cmbGlobalWork_t___ctor(v2);
  CMB_GBWK = v2;
  FilterDelete();
  Registed = 0;
  RegNum = 0;
  SeqInfo = CMB_GBWK->SeqInfo;
  cmpInitSeqInfo(SeqInfo, 0);
  asset_bc = get_asset_bc();
  Appendix = GetAppendix();
  v12 = Concat_5224608(StringLiteral_4897, Appendix);
  v13 = GetAppendix();
  v14 = Concat_5224608(StringLiteral_4897, v13);
  Load(asset_bc, v12, v14, 0);
  v15 = get_asset_bc();
  Load(v15, StringLiteral_4897, StringLiteral_4897, 0);
  v16 = get_asset_bc();
  Load(v16, StringLiteral_16165, StringLiteral_16165, 0);
  inited = cmbChkGeneralStat();
  _Clear(bgmkeys);
  bgmkeysidx = 0;
  fclCombineTokusyuBGM();
  _Add(bgmkeys, StringLiteral_16166);
  _Add(bgmkeys, StringLiteral_16167);
  _Add(bgmkeys, StringLiteral_16168);
  if (inited)
  {
    if (inited == 1)
    {
      static_fields = v21->static_fields;
      v23 = &StringLiteral_16169;
    }
    else
    {
      static_fields = v25->static_fields;
      v23 = &StringLiteral_16171;
    }
  }
  else
  {
    static_fields = v24->static_fields;
    v23 = &StringLiteral_16170;
  }
  _Add(static_fields->bgmkeys, *v23);
  v27 = 0;
  {
  }
  while (v27 < _get_Count(bgmkeys))
  {
    v33 = get_asset_bc();
    Item = _get_Item(
             bgmkeys,
             v27);
    v30 = _get_Item(
            bgmkeys,
            v27);
    Load(v33, Item, v30, 0);
    ++v27;
  }
  CMB_GBWK->Initialized = 0;
}

// 0x146c2a0
s32 fclCombineProcessEnd(void) {
  if (!fldProc_CallSisetuReturn())
    return 0;
  FadeOutWindow();
  dds3KillProcessName(StringLiteral_16180, 1);
  dds3KillProcessName(StringLiteral_16181, 1);
  dds3KillProcessName(StringLiteral_16182, 1);
  return 1;
}

// 0x146c0c0
void fclCombineProcessStart(void) {
  u64 *v3;
  u64 *v5;
  u64 *v6;
  u64 *v7;

  fclCombineInitialize();
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_fclCombineInit__fclCombineCalc__);
  dds3StartProcess(StringLiteral_16180, 0x400u, 1, 1, v3, 0, 0, 0, 0, 0);
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_fclCombineInit__fclCombineDraw__);
  dds3StartProcess(StringLiteral_16181, 0x2B10u, 1, 1, v5, 0, 0, 0, 0, 0);
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_fclCombineInit__fclCombineUpdate__);
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_fclCombineInit_fclCombineDestroy__);
  dds3StartProcess(StringLiteral_16182, 0x520Cu, 1, 1, v6, 0, v7, 0, 0, 0);
  gProcessStat = 1;
}

// 0x146a270
void fclCombineTexFree(void) {
  char v2;
  fclCombineInit_c *v3;
  struct fclCombineInit_StaticFields *static_fields;
  struct sdfTexHandle_t_array *TexHandle;
  sdfTexHandle_t_o *v7;

  v2 = 0;
  {
  }
  while (1)
  {
    static_fields = v3->static_fields;
    if (v2 >= SLODWORD(static_fields->gFclCombineTexFile->max_length))
      break;
    TexHandle = static_fields->CMB_GBWK->TexHandle;
    v7 = TexHandle->m_Items[v2];
    sdfTexFree(v7);
    ++v2;
  }
  Write(StringLiteral_16164, 0);
}

// 0x146a260
void fclCombineTexLoad(void) {
  ;
}

// 0x146a4f0
s32 fclCombineTokusyuBGM(void) {
  u64 v4;
  s32 v5;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v9;
  s32 id;

  else if (evtGetAgeOfMoon())
  {
    return 0;
  }
  v4 = 0;
  v5 = 0;
  do
  {
    while (1)
    {
      unitwork = DDS3_GBWK->unitwork;
      v9 = unitwork->m_Items[v4];
      if ((v9->flag & 1) == 0)
      id = v9->id;
      if (id == 82)
        break;
      if (id == 81)
        v5 |= 1u;
      if (++v4 == 16)
    }
    v5 |= 2u;
    ++v4;
  }
  while (v4 != 16);
  if (v5 == 3)
    return 0;
  else
    return v5;
}

// 0x146adf0
void fclUpdateInit(void) {
    LoadFileByte(0, 0, 0);
    InitializeUI(0);
    SetRootMenuText(0, 0);
    InitializeGameObject();
    evtDisableMoonCalc();
    fclCombineInitPanelMover(0);
    fclCombineTokusyuBGM();
    fclCombineBGM(0);
    fclSetVal(0, 0);
    evtBitCheck(0);
    fclCombineEventStart(0);
    InitializeModelCameraForUnity();
    LoadLocalizeText(0, 0);
    GetPlatformStr();
}
