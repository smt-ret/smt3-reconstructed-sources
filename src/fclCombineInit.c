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
static u8 *gCmdMenuFlag;
static char *gZensyoMenuStr[3];
static char *gTalkMenuStr[8];
static u8 *gTalkMenuFlag;
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
    id = dds3SearchProcessName("e800_main");
    if (dds3GetProcessStat(&id) - 1 <= 2)
    {
      Current = CMB_GBWK->SeqInfo->Current;
      if (Current <= 0x12)
      {
        v7 = 1 << Current;
        if ((v7 & 0x173) != 0)
          goto LABEL_21;
        if ((v7 & 0x6000C) != 0)
          goto LABEL_32;
      }
      basic = dds3GetActiveScene();
      if (basic)
      {
        v8 = 0;
LABEL_29:
        dds3VisibleSceneBasic(&basic, v8);
        {
LABEL_35:
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
LABEL_33:
        goto LABEL_35;
      }
LABEL_32:
        goto LABEL_35;
      goto LABEL_33;
    }
LABEL_21:
    basic = dds3GetActiveScene();
    if (basic)
    {
      v8 = 1;
      goto LABEL_29;
    }
    goto LABEL_32;
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
  fclCombineInit_c *v3;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v12;
  AssetBundleCtrl_o *v16;
  System_String_o *Item;

  else
  {
    if (CMB_GBWK->Initialized)
      goto LABEL_6;
  }
  if (_get_Count(bgmkeys) == bgmkeysidx)
  {
    asset_bc = get_asset_bc();
    if (IsLoad(asset_bc, "e800"))
    {
      v12 = get_asset_bc();
      if (IsLoad(v12, "f800"))
      {
        fclUpdateInit();
        CMB_GBWK->Initialized = 1;
        if ((v3->_2.bitflags2 & 2) == 0)
          goto LABEL_9;
        goto LABEL_7;
      }
    }
  }
  else
  {
    v16 = get_asset_bc();
    Item = _get_Item(
             bgmkeys,
             bgmkeysidx);
    if (IsLoad(v16, Item))
    {
      ++bgmkeysidx;
    }
  }
  return 0;
}

// 0x146c3c0
s8 fclChkCombineProcess(void) {
  s32 gProcessStat;

  if (gProcessStat == 1)
    return 1;
LABEL_6:
  if (gProcessStat != 2)
    return 0;
  gProcessStat = 0;
  return 0;
}

// 0x146a630
void fclCombineBGM(s8 Mode) {
  s32 inited;
  s32 TokusyuBGM;
  s64 *v7;
  s32 Id;

  inited = cmbChkGeneralStat();
  TokusyuBGM = CMB_GBWK->TokusyuBGM;
  if (TokusyuBGM == 2)
  {
    else
    {
      v7 = &"JYAKYO05_BGM00";
    }
  }
  else if (TokusyuBGM == 1)
  {
    else
    {
      v7 = &"JYAKYO04_BGM00";
    }
  }
  else if (inited)
  {
    if (inited == 1)
    {
      v7 = &"JYAKYO01_BGM00";
    }
    else
    {
      v7 = &"JYAKYO00_BGM00";
    }
  }
  else
  {
    v7 = &"JYAKYO03_BGM00";
  }
  Id = FindId(0, *v7);
  switch (Mode)
  {
    case 2:
      p2sdFadeIn(Id);
      break;
    case 1:
      p2sdFadeOut(Id);
      break;
    case 0:
      p2sdPlayBGM(Id);
      break;
  }
}

// 0x1454b10
s8 fclCombineChkEventStat(void) {
  u32 ProcessStat;
  dds3ProcessID_t_o *id;

  id = 0;
  id = dds3SearchProcessName("e800_main");
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

  v4 = Concat("!!!!!! Unload Combine !!!!! : ", CMB_GBWK);
  v6 = Empty_string_();
  Log(v4, v6, 0);
  if (!CMB_GBWK)
    goto LABEL_74;
LABEL_14:
  gKeisyoListBuf = 0;
  cmpModelFreeResource();
  cmpModelEnd();
  ScriptPID = CMB_GBWK->ScriptPID;
  fclScriptForcedEnd(ScriptPID);
  v12 = Concat("!!!!!! Unload Combine2 !!!!! : ", CMB_GBWK);
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
  Remove("BIRTH", 0);
  Remove("TALK", 0);
  Remove("MES_DATA", 0);
  Remove("CAMP", 0);
  Remove("FACILITY", 0);
  PlatformStr = GetPlatformStr();
  v26 = Concat_5224608("CAMP", PlatformStr);
  Remove(v26, 0);
  v28 = 0;
  {
LABEL_52:
  }
  while (v28 < _get_Count(bgmkeys))
  {
    asset_bc = get_asset_bc();
    Item = _get_Item(
             bgmkeys,
             v28);
    UnloadAB(asset_bc, Item);
    ++v28;
      goto LABEL_52;
  }
  _Clear(bgmkeys);
  bgmkeysidx = 0;
  v37 = get_asset_bc();
  UnloadAB(v37, "f800");
  v38 = get_asset_bc();
  UnloadAB(v38, "e800");
  v40 = get_asset_bc();
  Appendix = GetAppendix();
  v42 = Concat_5224608("e800", Appendix);
  UnloadAB(v40, v42);
  fldSetCharClr();
LABEL_74:
  PID->func_ans = -1;
  return 0;
}

// 0x1454d40
void fclCombineDisableCmdZensyo(void) {
  bool v1;
  bool v2;
  cmpCursorInfo_t_o *CursorInfo;
  System_Byte_array *gCmdMenuFlag;
  struct System_Byte_array *v9;
  struct System_Byte_array *v12;
  struct cmpCursorPos_t_o *CursorPos;

  v1 = evtBitCheck(40);
  v2 = evtBitCheck(2208);
  if (!v1 && !v2)
  {
    CursorInfo = CMB_GBWK->CmdSelInfo->CursorInfo;
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
  cmpCursorInfo_t_o *CursorInfo;
  System_Byte_array *gTalkMenuFlag;
  struct System_Byte_array *v7;
  struct System_Byte_array *v10;
  struct cmpCursorPos_t_o *CursorPos;

  if (!evtBitCheck(37))
  {
    CursorInfo = CMB_GBWK->TalkSelInfo->CursorInfo;
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
  cmpCursorInfo_t_o *CursorInfo;
  System_Byte_array *gTalkMenuFlag;
  struct System_Byte_array *v7;
  struct System_Byte_array *v10;
  struct cmpCursorPos_t_o *CursorPos;

  if (evtBitCheck(163))
  {
    CursorInfo = CMB_GBWK->TalkSelInfo->CursorInfo;
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
  cmpCursorInfo_t_o *CursorInfo;
  System_Byte_array *gTalkMenuFlag;
  struct System_Byte_array *v9;
  struct System_Byte_array *v12;
  struct cmpCursorPos_t_o *CursorPos;

  v1 = evtBitCheck(40);
  v2 = evtBitCheck(2208);
  if (!v1 && !v2)
  {
    CursorInfo = CMB_GBWK->TalkSelInfo->CursorInfo;
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
  s64 *v23;
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
  v12 = Concat_5224608("e800", Appendix);
  v13 = GetAppendix();
  v14 = Concat_5224608("e800", v13);
  Load(asset_bc, v12, v14, 0);
  v15 = get_asset_bc();
  Load(v15, "e800", "e800", 0);
  v16 = get_asset_bc();
  Load(v16, "f800", "f800", 0);
  inited = cmbChkGeneralStat();
  _Clear(bgmkeys);
  bgmkeysidx = 0;
  fclCombineTokusyuBGM();
  _Add(bgmkeys, "e800bgm4");
  _Add(bgmkeys, "e800bgm5");
  _Add(bgmkeys, "e800bgm6");
  if (inited)
  {
    if (inited == 1)
    {
      v23 = &"e800bgm1";
    }
    else
    {
      v23 = &"e800bgm0";
    }
  }
  else
  {
    v23 = &"e800bgm3";
  }
  _Add(bgmkeys, *v23);
  v27 = 0;
  {
LABEL_38:
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
      goto LABEL_38;
  }
  CMB_GBWK->Initialized = 0;
}

// 0x146c2a0
s32 fclCombineProcessEnd(void) {
  if (!fldProc_CallSisetuReturn())
    return 0;
LABEL_6:
  FadeOutWindow();
  dds3KillProcessName("combine", 1);
  dds3KillProcessName("combine_draw", 1);
  dds3KillProcessName("combine_update", 1);
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
  dds3StartProcess("combine", 0x400u, 1, 1, v3, 0, 0, 0, 0, 0);
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_fclCombineInit__fclCombineDraw__);
  dds3StartProcess("combine_draw", 0x2B10u, 1, 1, v5, 0, 0, 0, 0, 0);
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
  dds3StartProcess("combine_update", 0x520Cu, 1, 1, v6, 0, v7, 0, 0, 0);
  gProcessStat = 1;
}

// 0x146a270
void fclCombineTexFree(void) {
  char v2;
  struct sdfTexHandle_t_array *TexHandle;
  sdfTexHandle_t_o *v7;

  v2 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    if (v2 >= SLODWORD(gFclCombineTexFile->max_length))
      break;
    TexHandle = CMB_GBWK->TexHandle;
    v7 = TexHandle->m_Items[v2];
    sdfTexFree(v7);
    ++v2;
      goto LABEL_6;
  }
  Write("COMBINE : Tex free.\n", 0);
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
        goto LABEL_18;
      id = v9->id;
      if (id == 82)
        break;
      if (id == 81)
        v5 |= 1u;
LABEL_18:
      if (++v4 == 16)
        goto LABEL_21;
    }
    v5 |= 2u;
    ++v4;
  }
  while (v4 != 16);
LABEL_21:
  if (v5 == 3)
    return 0;
  else
    return v5;
}

// 0x146adf0
void fclUpdateInit(void) {
  struct cmbGlobalWork_t_o *CMB_GBWK;
  AssetBundleCtrl_o *asset_bc;
  struct cmbGlobalWork_t_o *v5;
  AssetBundleCtrl_o *v6;
  s64 v11;
  fclCombineInit_c *v12;
  u64 v13;
  struct System_Byte_array *gCmdMenuFlag;
  u64 max_length_low;
  s64 v17;
  u64 v18;
  struct System_Byte_array *gTalkMenuFlag;
  u64 v20;
  struct cmbGlobalWork_t_o *v28;
  bool v33;
  System_String_o *PlatformStr;
  System_String_o *v38;
  System_String_o *v39;
  System_String_o *v40;

  asset_bc = get_asset_bc();
  CMB_GBWK->pScriptData = LoadFileByte(asset_bc, "e800", "dds3data/facility/scr/combine/message.bf.bytes");
  v5 = CMB_GBWK;
  v6 = get_asset_bc();
  v5->pCollectData = LoadFileByte(v6, "e800", "dds3data/facility/msg/combine/collect.bmd.bytes");
  CMB_GBWK->SeqInfo->Current = 0;
  CMB_GBWK->SeqInfo->Last = 0;
  CMB_GBWK->SeqInfo->Change = 1;
  InitializeUI(800);
  CMB_GBWK->EventEnd = 0;
  CMB_GBWK->bDrawDisabled = 0;
  SetRootMenuText(&CMB_GBWK->CmdSelInfo, gCombineMenuStr);
  SetRootMenuText(&CMB_GBWK->ZensyoSelInfo, gZensyoMenuStr);
  SetRootMenuText(&CMB_GBWK->TalkSelInfo, gTalkMenuStr);
  v11 = 32;
  v13 = 0;
  {
LABEL_15:
  }
  while (1)
  {
    max_length_low = LODWORD(gCmdMenuFlag->max_length);
    if (v13 >= max_length_low)
      break;
    else if (v13 >= max_length_low)
    {
      goto LABEL_21;
    }
    *(&gCmdMenuFlag->obj.klass + v11++) = 0;
    v13 = v11 - 32;
      goto LABEL_15;
  }
  v17 = 32;
  v18 = 0;
  if ((v12->_2.bitflags2 & 2) == 0)
    goto LABEL_29;
LABEL_27:
LABEL_29:
  while (1)
  {
    v20 = LODWORD(gTalkMenuFlag->max_length);
    if (v18 >= v20)
      break;
    else if (v18 >= v20)
    {
      goto LABEL_33;
    }
    *(&gTalkMenuFlag->obj.klass + v17) = 0;
    v18 = ++v17 - 32;
      goto LABEL_27;
  }
  else
  {
    InitializeGameObject(fclCombineDraw);
      goto LABEL_42;
  }
LABEL_42:
  CMB_GBWK->HelpFlag = 0;
  CMB_GBWK->StatFlag = 0;
  CMB_GBWK->ErrorFlag = 0;
  evtDisableMoonCalc();
  cmpModelInit();
  cmpModelEnd();
  cmbInitEffParam();
  fclCombineInitPanelMover(CMB_GBWK);
  v28 = CMB_GBWK;
  v28->TokusyuBGM = fclCombineTokusyuBGM();
  fclCombineBGM(0);
  fclSetVal(2, 0);
  v33 = evtBitCheck(2325);
  if (!v33)
  {
    CMB_GBWK->Jyakyo1st = 1;
  }
  fclCombineEventStart(1);
  InitializeModelCameraForUnity();
  LoadLocalizeText("common", "FACILITY");
  LoadLocalizeText("common", "CAMP");
  LoadLocalizeText("e800", "MES_DATA");
  LoadLocalizeText("e800", "TALK");
  LoadLocalizeText("common", "BIRTH");
  PlatformStr = GetPlatformStr();
  v38 = Concat_5224608("common", PlatformStr);
  v39 = GetPlatformStr();
  v40 = Concat_5224608("CAMP", v39);
  LoadLocalizeText(v38, v40);
  CMB_GBWK->bReadPhase = 0;
}
