#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct cmpCmdSelInfo_t cmpCmdSelInfo_t;
typedef struct cmpSeqInfo_s cmpSeqInfo_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclDataRag_t fclDataRag_t;
typedef struct lstListWindow_t lstListWindow_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static char *gFclRagTexFile[2];
static u8 LISTMAX;
static fclDataRag_t *GBWK;
static s8 gProcessStat;
static char *gRagMenuStr[5];
static u8 gCommandFlag[UNKNOWN_ARRAY_SIZE];

void ButtonGuideDispOff(void);
s32 CMP_XM(s32 a);
s32 CMP_YM(s32 b);
void FadeOutWindow(void);
s8 FclDebug(s8 Mode, void *pData);
void FilterDelete(void);
void FinalizeGameObject(void);
void FinalizeUI(void);
s32 FindId(s32 type, char *name);
char *GetAppendix(void);
void *GetCampCameraObj(dds3DefaultMain *this);
char *GetPlatformStr(void);
void InitializeGameObject(void);
void InitializeUI(s32 eventno);
void Load(char *key, char *filePath);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void LoadKeys(s32 type, char *key, char *path);
void LoadLocalizeText(char *key, char *filename);
s32 PlaySE(char *name);
void Remove(char *key);
void SetButtonGuide(s32 mode, bool sw);
void SetRootMenuText(cmpCmdSelInfo_t **csel, char **menu);
void UnloadAB(AssetBundleCtrl *this, char *key);
void WindowDispOff(bool sw);
u32 dds3GetRandA(char *name);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
void evtDisableMoonCalc(void);
void evtDisableMoonDraw(void);
void evtFreeStage(void);
void evtStartEvent(s32 no);
void fclFilterOFF(void);
fclDataRag_t *fclInitRag(s8 Place, cmpSeqInfo_t *pParentSeqInfo);
void fclInitRagCore(s8 Place, fclDataRag_t *pData, bool flg);
void fclRagEventEnd(void);
void fclRagInitPanelMover(fclDataRag_t *pData);
void fclRagTexFree(fclDataRag_t *pData);
void fclScriptForcedEnd(dds3ProcessID_t *PID);
void fclShuffleBuf8u(u8 **pBuf, s32 BufSize, s32 ShuffleCount);
bool fldProc_CallSisetuReturn(void);
void lstInitListWindow(s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Style, lstListWindow_t *pListWindow);
s32 p2sdFadeOut(s32 a);
s32 p2sdPlayBGM(s32 a);
void ragCreateAllList(s32 Mode, s32 Place, fclDataRag_t *pData);
s8 ragCreateItemList(u8 PackID, fclDataRag_t *pData);
s8 ragCreateMitamaList(u8 PackID, fclDataRag_t *pData);
s8 ragCreateSeireiList(u8 PackID, fclDataRag_t *pData);
void ragInitItemWindow(s32 ListNums, lstListWindow_t *pListWindow);
void ragInitMitamaWindow(s32 ListNums, lstListWindow_t *pListWindow);
void ragInitSeireiWindow(s32 ListNums, lstListWindow_t *pListWindow);
s32 ragRandGetMitama(u8 PackID, s8 MitamaIndex);
s32 ragRandGetSeirei(u8 PackID, s8 SeireiIndex);
void sdfTexFree(sdfTexHandle_t *aHandle);

// 0x13d6cf0
s8 fclChkRagProcess(void) {
  struct fclRagInit_StaticFields *static_fields;
  s32 gProcessStat;

  static_fields = fclRagInit->static_fields;
  gProcessStat = static_fields->gProcessStat;
  if (gProcessStat == 1)
    return 1;
  if (gProcessStat != 2)
    return 0;
  static_fields->gProcessStat = 0;
  return 0;
}

// 0x13d4150
void *fclDestroyRag(dds3ProcessID_t *PID) {
  u64 v3;
  dds3ProcessID_t_o *ScriptPID;
  s32 Id;
  System_String_o *PlatformStr;
  System_String_o *v18;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v21;
  AssetBundleCtrl_o *v22;
  System_String_o *Appendix;
  System_String_o *v24;

  if (*(*(v3 + 184) + 16LL))
  {
    if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
    fclRagTexFree(v3);
    ScriptPID = GBWK->ScriptPID;
    fclScriptForcedEnd(ScriptPID);
    GBWK->pScriptData = 0;
    fclRagEventEnd();
    GBWK = 0;
    gProcessStat = 2;
    evtDisableMoonDraw();
    Id = FindId(0, StringLiteral_11819);
    p2sdFadeOut(Id);
    FinalizeGameObject();
    WindowDispOff(0);
    FinalizeUI();
    Remove(StringLiteral_16174, 0);
    Remove(StringLiteral_12292, 0);
    Remove(StringLiteral_16308, 0);
    Remove(StringLiteral_5045, 0);
    PlatformStr = GetPlatformStr();
    v18 = Concat_5224608(StringLiteral_12292, PlatformStr);
    Remove(v18, 0);
    asset_bc = get_asset_bc();
    UnloadAB(asset_bc, StringLiteral_16306);
    v21 = get_asset_bc();
    UnloadAB(v21, StringLiteral_16305);
    v22 = get_asset_bc();
    Appendix = GetAppendix();
    v24 = Concat_5224608(StringLiteral_16305, Appendix);
    UnloadAB(v22, v24);
  }
  PID->func_ans = -1;
  return 0;
}

// 0x13d3340
fclDataRag_t *fclInitRag(s8 Place, cmpSeqInfo_t *pParentSeqInfo) {
  fclDataRag_t_o *v5;
  cmpSeqInfo_t_o *SeqInfo;
  struct fclPanel_t_o *HelpPanel;
  s32 v11;
  s32 v13;
  u32 FCL_RAG_WINCOL_HELP;
  u64 *v16;
  u64 *v17;
  struct fclPanel_t_o *SyojiPanel;
  s32 v19;
  s32 v20;
  u32 FCL_RAG_WINCOL_SYOJI;
  s32 v22;
  u64 *v23;
  u64 *v24;
  struct fclPanel_t_o *BackPanel;
  s32 v26;
  s32 v27;
  u64 *v28;
  u64 *v29;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *Appendix;
  System_String_o *v35;
  System_String_o *v36;
  System_String_o *v37;
  AssetBundleCtrl_o *v38;
  AssetBundleCtrl_o *v39;
  UnityEngine_GameObject_o *CampCameraObj;

  v5 = Allocate(fclDataRag_t);
  fclDataRag_t___ctor(v5);
  FilterDelete();
  SeqInfo = v5->SeqInfo;
  cmpInitSeqInfo(SeqInfo, pParentSeqInfo);
  v5->SeqInfo->Current = 0;
  v5->SeqInfo->Last = 0;
  v5->SeqInfo->Change = 1;
  v5->Place = Place;
  v5->ScriptPID = 0;
  HelpPanel = v5->HelpPanel;
  v11 = CMP_XM(246);
  v13 = CMP_YM(80);
  HelpPanel->X = v11;
  HelpPanel->Y = v13;
  HelpPanel->Col = FCL_RAG_WINCOL_HELP;
  *&HelpPanel->Z = 0x6B00E5000FFFFFLL;
  HelpPanel->Spd = 16;
  *&HelpPanel->Timer = 0;
  HelpPanel->TexHandle = 0;
  v16 = Allocate(fclDrawPanelFunc_t);
  fclDrawPanelFunc_t___ctor(v16, 0, Method_fclPanel_fclDrawPanelType2__);
  HelpPanel->DrawFunc = v16;
  v17 = Allocate(fclUpdatePanelFunc_t);
  fclUpdatePanelFunc_t___ctor(v17, 0, Method_fclPanel_fclUpdatePanelType2__);
  HelpPanel->UpdateFunc = v17;
  SyojiPanel = v5->SyojiPanel;
  v19 = CMP_XM(234);
  v20 = CMP_YM(220);
  v22 = v20;
  SyojiPanel->X = v19;
  SyojiPanel->Y = v22;
  SyojiPanel->Col = FCL_RAG_WINCOL_SYOJI;
  SyojiPanel->Spd = 16;
  *&SyojiPanel->Z = 0x5100F1000FFFFFLL;
  *&SyojiPanel->Timer = 0;
  SyojiPanel->TexHandle = 0;
  v23 = Allocate(fclDrawPanelFunc_t);
  fclDrawPanelFunc_t___ctor(v23, 0, Method_fclPanel_fclDrawPanelTypeDef__);
  SyojiPanel->DrawFunc = v23;
  v24 = Allocate(fclUpdatePanelFunc_t);
  fclUpdatePanelFunc_t___ctor(v24, 0, Method_fclPanel_fclUpdatePanelTypeDef__);
  SyojiPanel->UpdateFunc = v24;
  BackPanel = v5->BackPanel;
  v26 = CMP_XM(0);
  v27 = CMP_YM(50);
  *&BackPanel->Z = 0x1090200000FFFFFLL;
  BackPanel->X = v26;
  BackPanel->Y = v27;
  BackPanel->Col = 0;
  *&BackPanel->Timer = 0;
  BackPanel->TexHandle = 0;
  BackPanel->Spd = 29;
  v28 = Allocate(fclDrawPanelFunc_t);
  fclDrawPanelFunc_t___ctor(v28, 0, Method_fclPanel_fclDrawPanelType0__);
  BackPanel->DrawFunc = v28;
  v29 = Allocate(fclUpdatePanelFunc_t);
  fclUpdatePanelFunc_t___ctor(v29, 0, Method_fclPanel_fclUpdatePanelType0__);
  BackPanel->UpdateFunc = v29;
  evtDisableMoonCalc();
  asset_bc = get_asset_bc();
  Appendix = GetAppendix();
  v35 = Concat_5224608(StringLiteral_16305, Appendix);
  v36 = GetAppendix();
  v37 = Concat_5224608(StringLiteral_16305, v36);
  Load(asset_bc, v35, v37, 0);
  v38 = get_asset_bc();
  Load(v38, StringLiteral_16305, StringLiteral_16305, 0);
  v39 = get_asset_bc();
  Load(v39, StringLiteral_16306, StringLiteral_16306, 0);
  v5->Initialized = 0;
  CampCameraObj = GetCampCameraObj(kernelObject);
  campCameraObj = CampCameraObj;
  return v5;
}

// 0x13d3d40
void fclInitRagCore(s8 Place, fclDataRag_t *pData, bool flg) {
    ragCreateAllList(0, 0, 0);
    SetRootMenuText(0, 0);
}

// 0x13d4580
void fclRagEventEnd(void) {
  dds3KillProcessName(StringLiteral_16309, 1);
  evtFreeStage();
  fclFilterOFF();
}

// 0x13ce950
void fclRagEventStart(s8 Signal) {
  struct System_Int32_array *gFclVal;
  struct System_SByte_array *gFclSignal;

  gFclVal->m_Items[1] = Signal;

  {
  }
  gFclSignal->m_Items[1] = 0;
  evtStartEvent(803);
  PlaySE(StringLiteral_9025);
}

// 0x13d3c40
void fclRagInitPanelMover(fclDataRag_t *pData) {
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
      v7->Mode = 0;
      *&v7->OfsX = 0;
      *&v7->MaxOfsX = 50;
      *&v7->Rate = 0x2000000200LL;
      v7->MoverFunc = v8;
      fclPanelMoverFunc_t__Invoke(v8, v7);
      PanelMover = pData->PanelMover;
      LODWORD(max_length) = PanelMover->max_length;
      ++v5;
    }
    while (v5 < max_length);
  }
}

// 0x13d6bd0
s32 fclRagProcessEnd(void) {
  if (!fldProc_CallSisetuReturn())
    return 0;
  FadeOutWindow();
  dds3KillProcessName(StringLiteral_16315, 1);
  dds3KillProcessName(StringLiteral_16316, 1);
  dds3KillProcessName(StringLiteral_16317, 1);
  return 1;
}

// 0x13d6950
void fclRagProcessStart(s8 Place) {
  struct fclDataRag_t_o *inited;
  Il2CppObject *GBWK;
  u64 *v9;
  Il2CppObject *data;
  u64 *v12;
  u64 *v13;
  u64 *v14;

  else if (GBWK)
  {
    return;
  }
  inited = fclInitRag(Place, 0);
  GBWK = inited;
  FclDebug(2, GBWK);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_fclRagCalc_ragCalc__);
  data = GBWK;
  dds3StartProcess(StringLiteral_16315, 0x403u, 1, 1, v9, 0, 0, 0, data, 0);
  v12 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v12,
    0,
    Method_fclRagDraw_ragDraw__);
  dds3StartProcess(
    StringLiteral_16316,
    0x2B13u,
    1,
    1,
    v12,
    0,
    0,
    0,
    GBWK,
    0);
  v13 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v13,
    0,
    Method_fclRagUpdate_ragUpdate__);
  v14 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v14,
    0,
    Method_fclRagInit_fclDestroyRag__);
  dds3StartProcess(
    StringLiteral_16317,
    0x520Fu,
    1,
    1,
    v13,
    0,
    v14,
    0,
    GBWK,
    0);
  gProcessStat = 1;
}

// 0x13d4480
void fclRagTexFree(fclDataRag_t *pData) {
  fclRagInit_c *v2;
  char v3;
  struct fclRagInit_StaticFields *static_fields;
  s32 v5;
  sdfTexHandle_t_o *TexHandleBG;

  v3 = 0;
  do
  {
    static_fields = v2->static_fields;
    v5 = v3++;
  }
  while (v5 < SLODWORD(static_fields->gFclRagTexFile->max_length));
  TexHandleBG = static_fields->GBWK->TexHandleBG;
  sdfTexFree(TexHandleBG);
  Write(StringLiteral_16310, 0);
}

// 0x13d3c30
void fclRagTexLoad(fclDataRag_t *pData) {
  ;
}

// 0x13d3890
void fclRagUpdateInit(fclDataRag_t *data) {
  AssetBundleCtrl_o *asset_bc;
  s32 Id;
  struct System_Int32_array *gFclVal;
  System_String_o *PlatformStr;
  System_String_o *v15;
  System_String_o *v16;
  System_String_o *v17;

  LoadKeys(1, StringLiteral_16305, 0);
  LoadKeys(3, StringLiteral_16305, 0);
  cmpModelInit();
  cmpModelEnd();
  fclRagInitPanelMover(data);
  asset_bc = get_asset_bc();
  data->pScriptData = LoadFileByte(asset_bc, StringLiteral_16305, StringLiteral_16307);
  Id = FindId(0, StringLiteral_11819);
  p2sdPlayBGM(Id);
  gFclVal->m_Items[2] = 0;
  LoadLocalizeText(StringLiteral_16305, StringLiteral_16308);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_16174);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_12292);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5045);
  PlatformStr = GetPlatformStr();
  v15 = Concat_5224608(StringLiteral_4611, PlatformStr);
  v16 = GetPlatformStr();
  v17 = Concat_5224608(StringLiteral_12292, v16);
  LoadLocalizeText(v15, v17);
  InitializeUI(803);
  SetButtonGuide(0, 0);
  ButtonGuideDispOff();
  data->EventEnd = 0;
  InitializeGameObject();
  fclInitRagCore(data->Place, data, 1);
}

// 0x13d6dc0
void fclTerminateRag(void) {
  struct fclDataRag_t_o *GBWK;

  if (GBWK)
  {
    GBWK->SeqInfo->Flag |= 0x10u;
  }
}

// 0x13d6360
void ragCreateAllList(s32 Mode, s32 Place, fclDataRag_t *pData) {
  struct fclRag_t_array *fclRagTbl;
  struct System_Int16_array *EventBitPos;
  s32 v11;
  _BOOL8 v12;
  struct fclRag_t_array *v15;
  struct System_Byte_array *ItemPackID;
  u8 v19;
  struct fclRag_t_array *v22;
  struct System_Byte_array *v24;
  struct System_Byte_array *gCommandFlag;
  struct cmpCursorPos_t_o *CursorPos;
  s32 ItemListCnt;
  lstListWindow_t_o *ItemWindow;
  struct fclRag_t_array *v36;
  struct System_Byte_array *SeireiPackID;
  u8 v40;
  struct fclRag_t_array *v43;
  struct System_Byte_array *v45;
  struct System_Byte_array *v48;
  struct cmpCursorPos_t_o *v50;
  s32 SeireiListCnt;
  lstListWindow_t_o *SeireiWindow;
  struct fclRag_t_array *v56;
  struct System_Byte_array *MitamaPackID;
  struct fclRag_t_array *v61;
  struct System_Byte_array *v63;
  struct System_Byte_array *v66;
  struct cmpCursorPos_t_o *v68;
  cmpCursorInfo_t_o *CursorInfo;
  System_Byte_array *v71;

  EventBitPos = fclRagTbl->m_Items[Place]->EventBitPos;
  v11 = EventBitPos->m_Items[0];
  if (v11 < 0)
  {
    v12 = 0;
  }
  else
  {
    v12 = evtBitCheck(v11);
  }
  v15 = fclRagTbl;
  ItemPackID = v15->m_Items[Place]->ItemPackID;
  v19 = ItemPackID->m_Items[v12];
  pData->ItemListCnt = ragCreateItemList(v19, pData, pData);
  v22 = fclRagTbl;
  v24 = v22->m_Items[Place]->ItemPackID;
  if (!v24->m_Items[v12])
  {
    gCommandFlag->m_Items[0] |= 2u;
    CursorPos = pData->CmdSelInfo->CursorInfo->CursorPos;
    ++CursorPos->InvisibleListNums;
  }
  ItemListCnt = pData->ItemListCnt;
  ItemWindow = pData->ItemWindow;
  else
  {
    ragInitItemWindow(ItemListCnt, pData->ItemWindow);
    if (Mode)
      return;
  }
  v36 = fclRagTbl;
  SeireiPackID = v36->m_Items[Place]->SeireiPackID;
  v40 = SeireiPackID->m_Items[v12];
  pData->SeireiListCnt = ragCreateSeireiList(v40, pData);
  v43 = fclRagTbl;
  v45 = v43->m_Items[Place]->SeireiPackID;
  if (!v45->m_Items[v12])
  {
    v48 = gCommandFlag;
    v48->m_Items[1] |= 2u;
    v50 = pData->CmdSelInfo->CursorInfo->CursorPos;
    ++v50->InvisibleListNums;
  }
  SeireiListCnt = pData->SeireiListCnt;
  SeireiWindow = pData->SeireiWindow;
  ragInitSeireiWindow(SeireiListCnt, SeireiWindow);
  v56 = fclRagTbl;
  MitamaPackID = v56->m_Items[Place]->MitamaPackID;
  pData->MitamaListCnt = ragCreateMitamaList(MitamaPackID->m_Items[v12], pData);
  v61 = fclRagTbl;
  v63 = v61->m_Items[Place]->MitamaPackID;
  if (!v63->m_Items[v12])
  {
    v66 = gCommandFlag;
    v66->m_Items[2] |= 2u;
    v68 = pData->CmdSelInfo->CursorInfo->CursorPos;
    ++v68->InvisibleListNums;
  }
  CursorInfo = pData->CmdSelInfo->CursorInfo;
  v71 = gCommandFlag;
  cmpSetCursorFlag(CursorInfo, v71);
  ragInitMitamaWindow(pData->MitamaListCnt, pData->MitamaWindow);
}

// 0x13d5920
s8 ragCreateItemList(u8 PackID, fclDataRag_t *pData) {
  struct System_SByte_array *ItemList;
  u64 v5;
  s8 v6;
  s64 v7;
  u32 v8;
  struct System_Byte_array_array *fclRagItemPackTbl;
  System_Byte_array *v12;
  s64 v14;
  struct fclRagItem_t_array *fclRagItemTbl;
  s64 ItemID;
  System_Array_o *v18;
  s64 v19;
  s32 v21;
  s64 v22;
  u64 *v24;
  s32 HeartsFlag;
  struct System_Int32_array *gFclVal;

  ItemList = pData->ItemList;
  pData->HeartsFlag = 0;
  v5 = 0;
  v6 = 0;
  v7 = PackID;
  v8 = PackID;
  do
  {
    v12 = fclRagItemPackTbl->m_Items[v7];
    v14 = v12->m_Items[v5];
    ItemID = fclRagItemTbl->m_Items[v14]->ItemID;
    if ((byte_3F59715 & 1) == 0)
    v18 = NewSpecific(sbyte, 0x19u);
    InitializeArray_1543888(v18, Field__PrivateImplementationDetails__1611B884F9514B730E1DFD40ABEFFAC12FD56E0F);
    if ((ItemID - 64) > 0x18)
    {
      if (!ItemID)
    }
    v19 = ItemID - 64;
    v21 = *(&v18[2].klass + v19);
    if (!v21)
    if (!cmbChkGetHearts(v21))
    {
      pData->HeartsFlag = 1;
      v22 = v6;
      ++v6;
      ItemList->m_Items[v22] = v14;
    }
    ++v5;
  }
  while (v5 != 32);
  v24 = Allocate(fclMisc_fclSort8uNonZero);
  _ctor(v24, 0);
  Sort_3899472(ItemList, v24);
  HeartsFlag = pData->HeartsFlag;
  else  gFclVal->m_Items[4] = HeartsFlag;
  return v6;
}

// 0x13d5ff0
s8 ragCreateMitamaList(u8 PackID, fclDataRag_t *pData) {
  il2cpp_array_size_t max_length;
  s32 v6;
  s64 RandA;
  s32 v8;
  s32 v9;
  s32 v10;
  System_Byte_array *v11;
  struct System_SByte_array *MitamaList;
  System_Byte_array *v15;
  u64 v16;
  s32 v18;
  u64 v21;
  struct System_UInt16_array *fclRagDefaultMitamaTbl;
  u16 v25;
  signed s64 v26;
  u64 v28;
  s8 v30;
  s8 Mitama;
  s64 v32;
  u64 *v34;
  s64 v36;
  char v37;
  s32 v38;

  max_length = fclRagDefaultMitamaTbl->max_length;
  v6 = 8 - max_length;
  v38 = max_length;
  RandA = dds3GetRandA(StringLiteral_416);
  v8 = v6;
  v9 = v6;
  v10 = v6 << 24;
  v36 = RandA / v6;
  v11 = NewSpecific(byte, v6);
  MitamaList = pData->MitamaList;
  v15 = v11;
  if (v10 >= 1)
  {
    v16 = 0;
    do
    {
      v11->m_Items[v16] = v16;
      ++v16;
    }
    while (v16 < v9);
  }
  v18 = RandA - v36 * v8;
  fclShuffleBuf8u(v15, v9, 16);
  if (v38 << 24 < 1)
  {
    LOBYTE(v26) = 0;
    v37 = RandA - v36 * v8;
    if (v18 << 24 < 1)
  }
  v21 = 0;
  do
  {
    v25 = fclRagDefaultMitamaTbl->m_Items[v21];
    v26 = v21 + 1;
    MitamaList->m_Items[v21++] = v25;
  }
  while (v26 < v38);
  v37 = v18;
  if (v18 << 24 >= 1)
  {
    v28 = 0;
    do
    {
      v30 = v15->m_Items[v28];
      Mitama = ragRandGetMitama(PackID, v30);
      v32 = v26;
      ++v28;
      LOBYTE(v26) = v26 + 1;
      MitamaList->m_Items[v32] = Mitama;
    }
    while (v28 < v37);
  }
  v34 = Allocate(fclMisc_fclSort8uNonZero);
  _ctor(v34, 0);
  Sort_3899472(MitamaList, v34);
  return v37 + v38;
}

// 0x13d5c80
s8 ragCreateSeireiList(u8 PackID, fclDataRag_t *pData) {
  il2cpp_array_size_t max_length;
  s32 v6;
  s64 RandA;
  s32 v8;
  s32 v9;
  s32 v10;
  System_Byte_array *v11;
  struct System_SByte_array *SeireiList;
  System_Byte_array *v15;
  u64 v16;
  s32 v18;
  u64 v21;
  struct System_UInt16_array *fclRagDefaultSeireiTbl;
  u16 v25;
  signed s64 v26;
  u64 v28;
  s8 v30;
  s8 Seirei;
  s64 v32;
  u64 *v34;
  s64 v36;
  char v37;
  s32 v38;

  max_length = fclRagDefaultSeireiTbl->max_length;
  v6 = 8 - max_length;
  v38 = max_length;
  RandA = dds3GetRandA(StringLiteral_416);
  v8 = v6;
  v9 = v6;
  v10 = v6 << 24;
  v36 = RandA / v6;
  v11 = NewSpecific(byte, v6);
  SeireiList = pData->SeireiList;
  v15 = v11;
  if (v10 >= 1)
  {
    v16 = 0;
    do
    {
      v11->m_Items[v16] = v16;
      ++v16;
    }
    while (v16 < v9);
  }
  v18 = RandA - v36 * v8;
  fclShuffleBuf8u(v15, v9, 16);
  if (v38 << 24 < 1)
  {
    LOBYTE(v26) = 0;
    v37 = RandA - v36 * v8;
    if (v18 << 24 < 1)
  }
  v21 = 0;
  do
  {
    v25 = fclRagDefaultSeireiTbl->m_Items[v21];
    v26 = v21 + 1;
    SeireiList->m_Items[v21++] = v25;
  }
  while (v26 < v38);
  v37 = v18;
  if (v18 << 24 >= 1)
  {
    v28 = 0;
    do
    {
      v30 = v15->m_Items[v28];
      Seirei = ragRandGetSeirei(PackID, v30);
      v32 = v26;
      ++v28;
      LOBYTE(v26) = v26 + 1;
      SeireiList->m_Items[v32] = Seirei;
    }
    while (v28 < v37);
  }
  v34 = Allocate(fclMisc_fclSort8uNonZero);
  _ctor(v34, 0);
  Sort_3899472(SeireiList, v34);
  return v37 + v38;
}

// 0x13d48a0
u8 ragGetItemTblIndex(u16 ItemID) {
    return 0;
}

// 0x13d47a0
u8 ragGetMitamaTblIndex(u16 MitamaID) {
    return 0;
}

// 0x13d46a0
u8 ragGetSeireiTblIndex(u16 SeireiID) {
    return 0;
}

// 0x13d5560
void ragInitItemWindow(s32 ListNums, lstListWindow_t *pListWindow) {
  u8 v4;
  s32 v5;
  s32 v6;
  cmpCursorInfo_t_o *CursorInfo;
  cmpCursorInfo_t_o *v11;

  v4 = ListNums;
  v5 = CMP_XM(37);
  v6 = CMP_YM(80);
  lstInitListWindow(v5, v6, 0xFFFFFu, 191, 221, 0x19191E59u, 0, pListWindow);
  CursorInfo = pListWindow->CursorInfo;
  cmpInitCursorSize(CursorInfo, 35, 22, 143, 22, 26);
  v11 = pListWindow->CursorInfo;
  cmpInitCursorInfo(v11, v4, LISTMAX, 0);
}

// 0x13d57e0
void ragInitMitamaWindow(s32 ListNums, lstListWindow_t *pListWindow) {
  u8 v4;
  s32 v5;
  s32 v6;
  cmpCursorInfo_t_o *CursorInfo;
  cmpCursorInfo_t_o *v11;

  v4 = ListNums;
  v5 = CMP_XM(37);
  v6 = CMP_YM(80);
  lstInitListWindow(v5, v6, 0xFFFFFu, 191, 221, 0x19191E59u, 0, pListWindow);
  CursorInfo = pListWindow->CursorInfo;
  cmpInitCursorSize(CursorInfo, 35, 22, 143, 22, 26);
  v11 = pListWindow->CursorInfo;
  cmpInitCursorInfo(v11, v4, LISTMAX, 0);
}

// 0x13d56a0
void ragInitSeireiWindow(s32 ListNums, lstListWindow_t *pListWindow) {
  u8 v4;
  s32 v5;
  s32 v6;
  cmpCursorInfo_t_o *CursorInfo;
  cmpCursorInfo_t_o *v11;

  v4 = ListNums;
  v5 = CMP_XM(37);
  v6 = CMP_YM(80);
  lstInitListWindow(v5, v6, 0xFFFFFu, 191, 221, 0x19191E59u, 0, pListWindow);
  CursorInfo = pListWindow->CursorInfo;
  cmpInitCursorSize(CursorInfo, 35, 22, 143, 22, 26);
  v11 = pListWindow->CursorInfo;
  cmpInitCursorInfo(v11, v4, LISTMAX, 0);
}

// 0x13d4f80
s32 ragRandGetMitama(u8 PackID, s8 MitamaIndex) {
  struct fclRagMitamaPack_t_array *fclRagMitamaPackTbl;
  u32 v7;
  s64 v8;
  struct System_Byte_array *Per;
  s32 v12;
  u32 v13;
  u32 RandA;
  struct fclRagMitamaPack_t_array *v17;
  u32 v19;
  struct System_Byte_array *v20;
  struct fclRagMitamaPack_t_array *v22;
  struct System_Byte_array *v24;
  struct fclRagMitamaPack_t_array *v26;
  struct System_Byte_array *v28;
  struct fclRagMitamaPack_t_array *v31;
  struct System_Byte_array *v33;
  struct fclRagMitamaPack_t_array *v35;
  struct System_Byte_array *v37;
  struct fclRagMitamaPack_t_array *v40;
  struct System_Byte_array *v42;
  struct fclRagMitamaPack_t_array *v45;
  struct System_Byte_array *v47;
  s64 v51;
  struct fclRagMitamaPack_t_array *v55;
  struct System_Byte_array_array *Index;
  System_Byte_array *v59;

  v7 = PackID;
  v8 = PackID;
  Per = fclRagMitamaPackTbl->m_Items[PackID]->Per;
  v12 = Per->m_Items[6];
  v13 = v12 + 1;
  RandA = dds3GetRandA(StringLiteral_416);
  v17 = fclRagMitamaPackTbl;
  v19 = RandA % v13;
  v20 = v17->m_Items[v8]->Per;
  if (v19 <= v20->m_Items[0])
  {
    v51 = 0;
  }
  v22 = fclRagMitamaPackTbl;
  v24 = v22->m_Items[v8]->Per;
  if (v19 <= v24->m_Items[1])
  {
    v51 = 1;
  }
  v26 = fclRagMitamaPackTbl;
  v28 = v26->m_Items[v8]->Per;
  if (v19 <= v28->m_Items[2])
  {
    v51 = 2;
  }
  v31 = fclRagMitamaPackTbl;
  v33 = v31->m_Items[v8]->Per;
  if (v19 <= v33->m_Items[3])
  {
    v51 = 3;
  }
  v35 = fclRagMitamaPackTbl;
  v37 = v35->m_Items[v8]->Per;
  if (v19 <= v37->m_Items[4])
  {
    v51 = 4;
  }
  v40 = fclRagMitamaPackTbl;
  v42 = v40->m_Items[v8]->Per;
  if (v19 <= v42->m_Items[5])
  {
    v51 = 5;
  }
  v45 = fclRagMitamaPackTbl;
  v47 = v45->m_Items[v8]->Per;
  if (v19 > v47->m_Items[6])
    return 0;
  v51 = 6;
  v55 = fclRagMitamaPackTbl;
  Index = v55->m_Items[v8]->Index;
  v59 = Index->m_Items[MitamaIndex];
  return v59->m_Items[v51];
}

// 0x13d49a0
s32 ragRandGetSeirei(u8 PackID, s8 SeireiIndex) {
  struct fclRagSeireiPack_t_array *fclRagSeireiPackTbl;
  u32 v7;
  s64 v8;
  struct System_Byte_array *Per;
  s32 v12;
  u32 v13;
  u32 RandA;
  struct fclRagSeireiPack_t_array *v17;
  u32 v19;
  struct System_Byte_array *v20;
  struct fclRagSeireiPack_t_array *v22;
  struct System_Byte_array *v24;
  struct fclRagSeireiPack_t_array *v26;
  struct System_Byte_array *v28;
  struct fclRagSeireiPack_t_array *v31;
  struct System_Byte_array *v33;
  struct fclRagSeireiPack_t_array *v35;
  struct System_Byte_array *v37;
  struct fclRagSeireiPack_t_array *v40;
  struct System_Byte_array *v42;
  struct fclRagSeireiPack_t_array *v45;
  struct System_Byte_array *v47;
  s64 v51;
  struct fclRagSeireiPack_t_array *v55;
  struct System_Byte_array_array *Index;
  System_Byte_array *v59;

  v7 = PackID;
  v8 = PackID;
  Per = fclRagSeireiPackTbl->m_Items[PackID]->Per;
  v12 = Per->m_Items[6];
  v13 = v12 + 1;
  RandA = dds3GetRandA(StringLiteral_416);
  v17 = fclRagSeireiPackTbl;
  v19 = RandA % v13;
  v20 = v17->m_Items[v8]->Per;
  if (v19 <= v20->m_Items[0])
  {
    v51 = 0;
  }
  v22 = fclRagSeireiPackTbl;
  v24 = v22->m_Items[v8]->Per;
  if (v19 <= v24->m_Items[1])
  {
    v51 = 1;
  }
  v26 = fclRagSeireiPackTbl;
  v28 = v26->m_Items[v8]->Per;
  if (v19 <= v28->m_Items[2])
  {
    v51 = 2;
  }
  v31 = fclRagSeireiPackTbl;
  v33 = v31->m_Items[v8]->Per;
  if (v19 <= v33->m_Items[3])
  {
    v51 = 3;
  }
  v35 = fclRagSeireiPackTbl;
  v37 = v35->m_Items[v8]->Per;
  if (v19 <= v37->m_Items[4])
  {
    v51 = 4;
  }
  v40 = fclRagSeireiPackTbl;
  v42 = v40->m_Items[v8]->Per;
  if (v19 <= v42->m_Items[5])
  {
    v51 = 5;
  }
  v45 = fclRagSeireiPackTbl;
  v47 = v45->m_Items[v8]->Per;
  if (v19 > v47->m_Items[6])
    return 0;
  v51 = 6;
  v55 = fclRagSeireiPackTbl;
  Index = v55->m_Items[v8]->Index;
  v59 = Index->m_Items[SeireiIndex];
  return v59->m_Items[v51];
}
