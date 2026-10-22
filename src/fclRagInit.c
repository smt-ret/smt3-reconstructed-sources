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
static u8 *gCommandFlag;

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
  s32 gProcessStat;

  if (gProcessStat == 1)
    return 1;
LABEL_6:
  if (gProcessStat != 2)
    return 0;
  gProcessStat = 0;
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
    fclRagTexFree(v3);
    ScriptPID = GBWK->ScriptPID;
    fclScriptForcedEnd(ScriptPID);
    GBWK->pScriptData = 0;
    fclRagEventEnd();
    GBWK = 0;
    gProcessStat = 2;
    evtDisableMoonDraw();
    Id = FindId(0, "SHOPSN10_BGM00");
    p2sdFadeOut(Id);
    FinalizeGameObject();
    WindowDispOff(0);
    FinalizeUI();
    Remove("FACILITY", 0);
    Remove("CAMP", 0);
    Remove("RAG_MES_DATA", 0);
    Remove("DATITEMHELP", 0);
    PlatformStr = GetPlatformStr();
    v18 = Concat_5224608("CAMP", PlatformStr);
    Remove(v18, 0);
    asset_bc = get_asset_bc();
    UnloadAB(asset_bc, "f803");
    v21 = get_asset_bc();
    UnloadAB(v21, "e803");
    v22 = get_asset_bc();
    Appendix = GetAppendix();
    v24 = Concat_5224608("e803", Appendix);
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
  v35 = Concat_5224608("e803", Appendix);
  v36 = GetAppendix();
  v37 = Concat_5224608("e803", v36);
  Load(asset_bc, v35, v37, 0);
  v38 = get_asset_bc();
  Load(v38, "e803", "e803", 0);
  v39 = get_asset_bc();
  Load(v39, "f803", "f803", 0);
  v5->Initialized = 0;
LABEL_34:
  CampCameraObj = GetCampCameraObj(kernelObject);
  campCameraObj = CampCameraObj;
  return v5;
}

// 0x13d3d40
void fclInitRagCore(s8 Place, fclDataRag_t *pData, bool flg) {
  System_String_array *gRagMenuStr;
  s64 v10;
  u64 v12;
  struct System_Byte_array *gCommandFlag;
  u64 max_length_low;
  u64 i;
  struct System_SByte_array *ItemList;
  u64 *v20;
  u64 v23;
  struct System_SByte_array *SeireiList;
  u64 *v27;
  u64 v29;
  struct System_SByte_array *MitamaList;
  u64 *v33;
  s8 v34[4];
  s8 v35[4];
  s8 v36[4];

  ragCreateAllList(0, Place, pData);
  if (flg)
  {
    SetRootMenuText(&pData->CmdSelInfo, gRagMenuStr);
  }
  v10 = 32;
  v12 = 0;
  {
LABEL_17:
  }
  while (1)
  {
    max_length_low = LODWORD(gCommandFlag->max_length);
    if (v12 >= max_length_low)
      break;
    else if (v12 >= max_length_low)
    {
      goto LABEL_23;
    }
    *(&gCommandFlag->obj.klass + v10++) = 0;
    v12 = v10 - 32;
      goto LABEL_17;
  }
  Write("\n", 0);
  Write("ITEM   : ", 0);
  for (i = 0; i != 32; ++i)
  {
    ItemList = pData->ItemList;
    v36[0] = ItemList->m_Items[i];
    v20 = sub_8D3950(sbyte, v36);
    Write_2930400("{0:x2} ", v20);
  }
  Write("\n", 0);
  Write("SEIREI : ", 0);
  if (pData->SeireiListCnt >= 1)
  {
    v23 = 0;
    do
    {
      SeireiList = pData->SeireiList;
      v35[0] = SeireiList->m_Items[v23];
      v27 = sub_8D3950(sbyte, v35);
      Write_2930400("{0:x2} ", v27);
      ++v23;
    }
    while (v23 < pData->SeireiListCnt);
  }
  Write("\n", 0);
  Write("MITAMA : ", 0);
  if (pData->MitamaListCnt >= 1)
  {
    v29 = 0;
    do
    {
      MitamaList = pData->MitamaList;
      v34[0] = MitamaList->m_Items[v29];
      v33 = sub_8D3950(sbyte, v34);
      Write_2930400("{0:x2} ", v33);
      ++v29;
    }
    while (v29 < pData->MitamaListCnt);
  }
  Write("\n", 0);
  Write("\n", 0);
}

// 0x13d4580
void fclRagEventEnd(void) {
  dds3KillProcessName("e803_main", 1);
LABEL_10:
  evtFreeStage();
  fclFilterOFF();
}

// 0x13ce950
void fclRagEventStart(s8 Signal) {
  struct System_Int32_array *gFclVal;
  struct System_SByte_array *gFclSignal;

LABEL_7:
  gFclVal->m_Items[1] = Signal;
  if ((byte_3F59719 & 1) != 0)
  {
      goto LABEL_17;
  }
  else
  {
      goto LABEL_17;
  }
LABEL_17:
  gFclSignal->m_Items[1] = 0;
  evtStartEvent(803);
  PlaySE("SHOPSN10_SE00");
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
LABEL_6:
  FadeOutWindow();
  dds3KillProcessName("rag", 1);
  dds3KillProcessName("rag_draw", 1);
  dds3KillProcessName("rag_update", 1);
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
  dds3StartProcess("rag", 0x403u, 1, 1, v9, 0, 0, 0, data, 0);
  v12 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v12,
    0,
    Method_fclRagDraw_ragDraw__);
  dds3StartProcess(
    "rag_draw",
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
    "rag_update",
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
  char v3;
  s32 v5;
  sdfTexHandle_t_o *TexHandleBG;

  v3 = 0;
  do
  {
    v5 = v3++;
  }
  while (v5 < SLODWORD(gFclRagTexFile->max_length));
  TexHandleBG = GBWK->TexHandleBG;
  sdfTexFree(TexHandleBG);
  Write("RAG : Tex free.\n", 0);
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

  LoadKeys(1, "e803", 0);
  LoadKeys(3, "e803", 0);
  cmpModelInit();
  cmpModelEnd();
  fclRagInitPanelMover(data);
  asset_bc = get_asset_bc();
  data->pScriptData = LoadFileByte(asset_bc, "e803", "dds3data/facility/scr/rag/message.bf.bytes");
  Id = FindId(0, "SHOPSN10_BGM00");
  p2sdPlayBGM(Id);
LABEL_25:
  gFclVal->m_Items[2] = 0;
  LoadLocalizeText("e803", "RAG_MES_DATA");
  LoadLocalizeText("common", "FACILITY");
  LoadLocalizeText("common", "CAMP");
  LoadLocalizeText("common", "DATITEMHELP");
  PlatformStr = GetPlatformStr();
  v15 = Concat_5224608("common", PlatformStr);
  v16 = GetPlatformStr();
  v17 = Concat_5224608("CAMP", v16);
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
      goto LABEL_15;
  }
  else
  {
    v12 = evtBitCheck(v11);
      goto LABEL_15;
  }
LABEL_15:
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
      goto LABEL_18;
LABEL_19:
    v18 = NewSpecific(sbyte, 0x19u);
    InitializeArray_1543888(v18, Field__PrivateImplementationDetails__1611B884F9514B730E1DFD40ABEFFAC12FD56E0F);
    if ((ItemID - 64) > 0x18)
    {
      if (!ItemID)
        goto LABEL_32;
      goto LABEL_29;
    }
    v19 = ItemID - 64;
    v21 = *(&v18[2].klass + v19);
    if (!v21)
      goto LABEL_29;
    if (!cmbChkGetHearts(v21))
    {
      pData->HeartsFlag = 1;
LABEL_29:
      v22 = v6;
      ++v6;
      ItemList->m_Items[v22] = v14;
    }
LABEL_32:
    ++v5;
  }
  while (v5 != 32);
  v24 = Allocate(fclMisc_fclSort8uNonZero);
  _ctor(v24, 0);
  Sort_3899472(ItemList, v24);
  HeartsFlag = pData->HeartsFlag;
  else if ((byte_3F5971B & 1) == 0)
  {
    goto LABEL_36;
  }
  gFclVal->m_Items[4] = HeartsFlag;
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
LABEL_10:
  v38 = max_length;
  RandA = dds3GetRandA("");
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
      goto LABEL_43;
    goto LABEL_34;
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
LABEL_34:
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
LABEL_43:
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
LABEL_10:
  v38 = max_length;
  RandA = dds3GetRandA("");
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
      goto LABEL_43;
    goto LABEL_34;
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
LABEL_34:
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
LABEL_43:
  v34 = Allocate(fclMisc_fclSort8uNonZero);
  _ctor(v34, 0);
  Sort_3899472(SeireiList, v34);
  return v37 + v38;
}

// 0x13d48a0
u8 ragGetItemTblIndex(u16 ItemID) {
  u64 v3;
  struct fclRagItem_t_array *fclRagItemTbl;
  u64 max_length_low;

  v3 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(fclRagItemTbl->max_length);
    if (v3 >= max_length_low)
      break;
    else if (v3 >= max_length_low)
    {
      goto LABEL_12;
    }
    if (fclRagItemTbl->m_Items[v3]->ItemID == ItemID)
      return v3;
    ++v3;
      goto LABEL_6;
  }
  LOBYTE(v3) = 0;
  return v3;
}

// 0x13d47a0
u8 ragGetMitamaTblIndex(u16 MitamaID) {
  u64 v3;
  struct fclRagDevil_t_array *fclRagMitamaTbl;
  u64 max_length_low;

  v3 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(fclRagMitamaTbl->max_length);
    if (v3 >= max_length_low)
      break;
    else if (v3 >= max_length_low)
    {
      goto LABEL_12;
    }
    if (fclRagMitamaTbl->m_Items[v3]->DevilID == MitamaID)
      return v3;
    ++v3;
      goto LABEL_6;
  }
  LOBYTE(v3) = 0;
  return v3;
}

// 0x13d46a0
u8 ragGetSeireiTblIndex(u16 SeireiID) {
  u64 v3;
  struct fclRagDevil_t_array *fclRagSeireiTbl;
  u64 max_length_low;

  v3 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(fclRagSeireiTbl->max_length);
    if (v3 >= max_length_low)
      break;
    else if (v3 >= max_length_low)
    {
      goto LABEL_12;
    }
    if (fclRagSeireiTbl->m_Items[v3]->DevilID == SeireiID)
      return v3;
    ++v3;
      goto LABEL_6;
  }
  LOBYTE(v3) = 0;
  return v3;
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
LABEL_14:
  v13 = v12 + 1;
  RandA = dds3GetRandA("");
  v17 = fclRagMitamaPackTbl;
  v19 = RandA % v13;
  v20 = v17->m_Items[v8]->Per;
  if (v19 <= v20->m_Items[0])
  {
    v51 = 0;
      goto LABEL_90;
LABEL_73:
    goto LABEL_90;
  }
  v22 = fclRagMitamaPackTbl;
  v24 = v22->m_Items[v8]->Per;
  if (v19 <= v24->m_Items[1])
  {
    v51 = 1;
      goto LABEL_90;
    goto LABEL_73;
  }
  v26 = fclRagMitamaPackTbl;
  v28 = v26->m_Items[v8]->Per;
  if (v19 <= v28->m_Items[2])
  {
    v51 = 2;
      goto LABEL_90;
    goto LABEL_73;
  }
  v31 = fclRagMitamaPackTbl;
  v33 = v31->m_Items[v8]->Per;
  if (v19 <= v33->m_Items[3])
  {
    v51 = 3;
      goto LABEL_90;
    goto LABEL_73;
  }
  v35 = fclRagMitamaPackTbl;
  v37 = v35->m_Items[v8]->Per;
  if (v19 <= v37->m_Items[4])
  {
    v51 = 4;
      goto LABEL_90;
    goto LABEL_73;
  }
  v40 = fclRagMitamaPackTbl;
  v42 = v40->m_Items[v8]->Per;
  if (v19 <= v42->m_Items[5])
  {
    v51 = 5;
      goto LABEL_90;
    goto LABEL_73;
  }
  v45 = fclRagMitamaPackTbl;
  v47 = v45->m_Items[v8]->Per;
  if (v19 > v47->m_Items[6])
    return 0;
  v51 = 6;
    goto LABEL_73;
LABEL_90:
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
LABEL_14:
  v13 = v12 + 1;
  RandA = dds3GetRandA("");
  v17 = fclRagSeireiPackTbl;
  v19 = RandA % v13;
  v20 = v17->m_Items[v8]->Per;
  if (v19 <= v20->m_Items[0])
  {
    v51 = 0;
      goto LABEL_90;
LABEL_73:
    goto LABEL_90;
  }
  v22 = fclRagSeireiPackTbl;
  v24 = v22->m_Items[v8]->Per;
  if (v19 <= v24->m_Items[1])
  {
    v51 = 1;
      goto LABEL_90;
    goto LABEL_73;
  }
  v26 = fclRagSeireiPackTbl;
  v28 = v26->m_Items[v8]->Per;
  if (v19 <= v28->m_Items[2])
  {
    v51 = 2;
      goto LABEL_90;
    goto LABEL_73;
  }
  v31 = fclRagSeireiPackTbl;
  v33 = v31->m_Items[v8]->Per;
  if (v19 <= v33->m_Items[3])
  {
    v51 = 3;
      goto LABEL_90;
    goto LABEL_73;
  }
  v35 = fclRagSeireiPackTbl;
  v37 = v35->m_Items[v8]->Per;
  if (v19 <= v37->m_Items[4])
  {
    v51 = 4;
      goto LABEL_90;
    goto LABEL_73;
  }
  v40 = fclRagSeireiPackTbl;
  v42 = v40->m_Items[v8]->Per;
  if (v19 <= v42->m_Items[5])
  {
    v51 = 5;
      goto LABEL_90;
    goto LABEL_73;
  }
  v45 = fclRagSeireiPackTbl;
  v47 = v45->m_Items[v8]->Per;
  if (v19 > v47->m_Items[6])
    return 0;
  v51 = 6;
    goto LABEL_73;
LABEL_90:
  v55 = fclRagSeireiPackTbl;
  Index = v55->m_Items[v8]->Index;
  v59 = Index->m_Items[SeireiIndex];
  return v59->m_Items[v51];
}
