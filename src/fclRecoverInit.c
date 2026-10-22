#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct cmpCmdSelInfo_t cmpCmdSelInfo_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclDataRecover_t fclDataRecover_t;
typedef struct fclPanelMoverFunc_t fclPanelMoverFunc_t;
typedef struct fclPanelMover_t fclPanelMover_t;
typedef struct fclPanel_t fclPanel_t;
typedef struct lstListWindow_t lstListWindow_t;
typedef struct mdlEffectResrcList_t mdlEffectResrcList_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;

static char *gFclRecoverTexFile[3];
static char *gRecoverMenuStr[7];
static u8 LISTMAX;
static u8 *gCommandFlag;
static fclDataRecover_t *GBWK;
static s32 gProcessStat;
static fclDataRecover_t *rcv_data;

void ButtonGuideDispOff(void);
s32 CMP_X(s32 a);
s32 CMP_XM(s32 a);
s32 CMP_Y(s32 b);
s32 CMP_YM(s32 b);
void FadeOutWindow(void);
void FilterDelete(void);
void FinalizeGameObject(void);
void FinalizeUI(void);
s32 FindId(s32 type, char *name);
char *GetAppendix(void);
void InitializeGameObject(void);
void InitializeModelCameraForUnity(void);
void InitializeUI(s32 eventno);
void Load(char *key, char *filePath);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void LoadKeys(s32 type, char *key, char *path);
void LoadLocalizeText(char *key, char *filename);
void Remove(char *key);
void SetButtonGuide(s32 mode, bool sw);
void SetRootMenuText(cmpCmdSelInfo_t **csel, char **menu);
void UnloadAB(AssetBundleCtrl *this, char *key);
void WindowDispOff(bool sw);
void dds3EffectDelete(void **pData);
s32 dds3EffectObjectBasicDestructor(dds3Basic_t *aPtr);
dds3Basic_t *dds3GetActiveScene(void);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
dds3Basic_t *dds3SceneBasicSearchNameAndType(dds3Basic_t *scene, u32 type, char *name);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void evtDisableMoonCalc(void);
void evtDisableMoonDraw(void);
void evtStartEvent(s32 no);
void fclClearSignal(s8 Idx);
void fclFreeStage(void);
void fclInitPanel(fclPanel_t *pPanel, s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Type, s8 Spd);
void fclInitPanelMover(fclPanelMover_t *pMover, s32 DefX, s32 DefY, s32 MaxOfsX, s32 MaxOfsY, s32 DefRate, s32 Spd, fclPanelMoverFunc_t *MoverFunc);
fclDataRecover_t *fclInitRecover(s8 Place);
void fclLoadPB(void);
void fclRecoverEventEnd(void);
void fclRecoverEventStart(s8 Signal);
void fclScriptForcedEnd(dds3ProcessID_t *PID);
s8 fclSetVal(s8 Idx, s32 Val);
bool fldProc_CallSisetuReturn(void);
void lstInitListWindow(s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Style, lstListWindow_t *pListWindow);
void mdlCreateEffectResrc_D3P(mdlEffectResrcList_t **listPtr, void *data, void **pTexture);
bool mdlGenEffect(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aPlayGroup);
s32 p2sdFadeOut(s32 a);
void p2sdPlayBGM_20175904(char *define_name);
void rcvInitSkillWindow(lstListWindow_t *pListWindow);
void rcvInitStockWindow(lstListWindow_t *pListWindow);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);
sdfModelRootNode_t *sdfModelMakeUnity(sdfModelTexList_t *aTexList, u8 **bData, s32 bPos);

// 0x1995160
s32 fclChkRecoverProcess(void) {
  s32 gProcessStat;

  if (gProcessStat == 1)
    return gProcessStat;
  if (gProcessStat == 2)
  {
    gProcessStat = 0;
    gProcessStat = 0;
    return gProcessStat;
  }
  return 0;
}

// 0x1994a20
void *fclDestroyRecover(dds3ProcessID_t *PID) {
  struct fclDataRecover_t_o *GBWK;

  if (GBWK)
  {
    else if ((byte_3F5ABE8 & 1) != 0)
    {
      goto LABEL_11;
    }
    goto LABEL_11;
  }
LABEL_42:
  FinalizeUI();
  PID->func_ans = -1;
  return 0;
}

// 0x1994440
fclDataRecover_t *fclInitRecover(s8 Place) {
  fclDataRecover_t_o *v3;
  cmpSeqInfo_t_o *SeqInfo;
  lstListWindow_t_o *StockWindow;
  fclPanel_t_o *BackPanel;
  s32 v12;
  s32 v13;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *Appendix;
  System_String_o *v19;
  System_String_o *v20;
  System_String_o *v21;
  AssetBundleCtrl_o *v22;
  AssetBundleCtrl_o *v23;

  v3 = Allocate(fclDataRecover_t);
  fclDataRecover_t___ctor(v3);
  FilterDelete();
  SeqInfo = v3->SeqInfo;
  cmpInitSeqInfo(SeqInfo, 0);
  v3->SeqInfo->Current = 0;
  v3->SeqInfo->Last = 0;
  v3->SeqInfo->Change = 1;
  v3->Place = Place;
  v3->ScriptPID = 0;
  StockWindow = v3->StockWindow;
  rcvInitStockWindow(StockWindow);
  rcvInitSkillWindow(v3->SkillWindow);
  BackPanel = v3->BackPanel;
  v12 = CMP_X(0);
  v13 = CMP_Y(83);
  fclInitPanel(BackPanel, v12, v13, 0xFFFFFu, 512, 228, 0, 0, 29);
  fclRecoverEventStart(1);
  asset_bc = get_asset_bc();
  Appendix = GetAppendix();
  v19 = Concat_5224608("e801", Appendix);
  v20 = GetAppendix();
  v21 = Concat_5224608("e801", v20);
  Load(asset_bc, v19, v21, 0);
  v22 = get_asset_bc();
  Load(v22, "e801", "e801", 0);
  v23 = get_asset_bc();
  Load(v23, "f801", "f801", 0);
  v3->Initialized = 0;
  evtDisableMoonCalc();
  return v3;
}

// 0x1993c80
void fclLoadPB(void) {
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *v4;
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  Il2CppObject *pModel;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  dds3ModelResrc_t_o *v11;
  u64 *monitor;
  u64 *v13;
  u64 *v14;
  System_Byte_array *v16;
  dds3ModelHandle_t_o *v17;
  AssetBundleCtrl_o *asset_bc;
  System_Byte_array *FileByte;
  AssetBundleCtrl_o *v22;
  System_Byte_array *v23;
  mdlEffectResrcList_t_o *listPtr;
  System_Byte_array *aTopPtr;
  dds3ModelHandle_t_o *aHandle;
  dds3Basic_t_o *pObjectBasic;
  u64 v30[3];

  aTopPtr = 0;
  aHandle = 0;
  listPtr = 0;
  pObjectBasic = 0;
  else
  {
    ActiveScene = dds3GetActiveScene();
    if (!ActiveScene)
      return;
  }
  v4 = ActiveScene;
  pObjectBasic = dds3SceneBasicSearchNameAndType(v4, 5u, "npc_kaihuku_e801");
  if (pObjectBasic)
  {
    BaseControlWorkData = dds3GetBaseControlWorkData(&pObjectBasic);
    pModel = BaseControlWorkData->pModel;
    if (pModel)
    {
      klass = pModel->klass;
      if (pModel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v30);
        if ((v30[0] & 1) != 0)
          v9 = v30[2];
        else
          v9 = v30 + 1;
        v10 = sub_8C4940(v9);
      }
    }
    aHandle = BaseControlWorkData->pModel;
    v11 = Allocate(dds3ModelResrc_t);
    dds3ModelResrc_t___ctor(v11);
    pModel[2].monitor = v11;
    v11->major = 1;
    *(pModel[2].monitor + 17) = 1;
    monitor = pModel[2].monitor;
    pModel[3].monitor = 0;
    monitor[12] = 0;
    v13 = pModel[2].monitor;
    v14 = Allocate(mdlEffectResrcList_t);
    mdlEffectResrcList_t___ctor(v14);
    v13[13] = v14;
    aTopPtr = 0;
    sdfDevLoadFileUnity_25061072("dds3data/event/e801/kaifuk.PB.bytes", &aTopPtr, 0, "e801");
    v16 = aTopPtr;
    v17 = pModel;
    {
      v17 = pModel;
    }
    pModel[4].klass = sdfModelMakeUnity(0, v16, 0);
    v17->modelRoot->modelobj = pObjectBasic->gameObject;
    v17->resrc->effectData = &aTopPtr->obj;
    listPtr = v17->resrc->effectResrcList;
    asset_bc = get_asset_bc();
    FileByte = LoadFileByte(asset_bc, "e801", "dds3data/event/e801/KAI.D3P.bytes");
    mdlCreateEffectResrc_D3P(&listPtr, &FileByte->obj, 0);
    v22 = get_asset_bc();
    v23 = LoadFileByte(v22, "e801", "dds3data/event/e801/KAI2.D3P.bytes");
    mdlCreateEffectResrc_D3P(&listPtr, &v23->obj, 0);
    aHandle->resrc->effectResrcList = listPtr;
    if (!mdlGenEffect(&aHandle, -1, -1))
    {
      mdlGenEffect(&aHandle, 0, 0);
    }
    rcv_data->EffFlag = 1;
  }
}

// 0x1993bd0
void fclRecoverEventEnd(void) {
  dds3KillProcessName("e801_main", 1);
  else
  {
    fclFreeStage();
  }
}

// 0x1993b20
void fclRecoverEventStart(s8 Signal) {
  fclSetVal(1, Signal);
  fclClearSignal(1);
  evtStartEvent(801);
}

// 0x1994330
void fclRecoverInitPanelMover(fclDataRecover_t *pData) {
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
      fclInitPanelMover(v7, 0, 0, 50, 0, 512, 32, v8);
      PanelMover = pData->PanelMover;
      LODWORD(max_length) = PanelMover->max_length;
      ++v5;
    }
    while (v5 < max_length);
  }
}

// 0x1995040
s32 fclRecoverProcessEnd(void) {
  if (!fldProc_CallSisetuReturn())
    return 0;
LABEL_6:
  FadeOutWindow();
  dds3KillProcessName("recover", 1);
  dds3KillProcessName("recover_draw", 1);
  dds3KillProcessName("recover_update", 1);
  return 1;
}

// 0x1994dc0
void fclRecoverProcessStart(s8 Place) {
  u64 *v5;
  Il2CppObject *data;
  u64 *v8;
  u64 *v9;
  u64 *v10;

  if (DDS3_GBWK->stockcnt)
  {
    else if (GBWK)
    {
      return;
    }
    GBWK = fclInitRecover(Place);
    v5 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v5,
      0,
      Method_fclRecoverCalc_rcvCalc__);
    data = GBWK;
    dds3StartProcess("recover", 0x401u, 1, 1, v5, 0, 0, 0, data, 0);
    v8 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v8,
      0,
      Method_fclRecoverDraw_rcvDraw__);
    dds3StartProcess(
      "recover_draw",
      0x2B11u,
      1,
      1,
      v8,
      0,
      0,
      0,
      GBWK,
      0);
    v9 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v9,
      0,
      Method_fclRecoverUpdate_rcvUpdate__);
    v10 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v10,
      0,
      Method_fclRecoverInit_fclDestroyRecover__);
    dds3StartProcess(
      "recover_update",
      0x520Du,
      1,
      1,
      v9,
      0,
      v10,
      0,
      GBWK,
      0);
    gProcessStat = 1;
  }
}

// 0x19940b0
void fclRecoverTexFree(fclDataRecover_t *pData) {
  Il2CppObject *pDataa;

  pData->EffD3P = 0;
  dds3EffectObjectBasicDestructor(pData->bas);
  pDataa = &pData->EffD3P->obj;
  dds3EffectDelete(&pDataa);
  pData->EffFlag = 0;
  pData->EffD3P = 0;
  pData->bas = 0;
}

// 0x1994040
void fclRecoverTexLoad(void) {
  fclLoadPB();
}

// 0x19946e0
void fclRecoverUpdateInit(fclDataRecover_t *data) {
  AssetBundleCtrl_o *asset_bc;
  struct System_Byte_array *gCommandFlag;
  struct System_Byte_array *v13;
  cmpCursorInfo_t_o *CursorInfo;
  System_Byte_array *v16;

  LoadKeys(1, "e801", 0);
  LoadKeys(3, "e801", 0);
  rcv_data = data;
  asset_bc = get_asset_bc();
  data->pScriptData = LoadFileByte(asset_bc, "e801", "dds3data/facility/scr/recover/message.bf.bytes");
  LoadLocalizeText("common", "FACILITY");
  LoadLocalizeText("e801", "RECOVER_MES_DATA");
  InitializeUI(801);
  SetRootMenuText(&GBWK->CmdSelInfo, gRecoverMenuStr);
  SetButtonGuide(0, 0);
  ButtonGuideDispOff();
  data->EventEnd = 0;
  gCommandFlag->m_Items[1] |= 2u;
  v13 = gCommandFlag;
  v13->m_Items[2] |= 2u;
  data->CmdSelInfo->CursorInfo->CursorPos->InvisibleListNums = 2;
  CursorInfo = data->CmdSelInfo->CursorInfo;
  v16 = gCommandFlag;
  cmpSetCursorFlag(CursorInfo, v16);
  InitializeGameObject();
  GBWK->EffFlag = 0;
  p2sdPlayBGM_20175904("SHOPSND2_BGM00");
  fclSetVal(2, 0);
  InitializeModelCameraForUnity();
}

// 0x1994240
void rcvInitSkillWindow(lstListWindow_t *pListWindow) {
  s32 v3;
  s32 v4;
  cmpCursorInfo_t_o *CursorInfo;

  v3 = CMP_XM(39);
  v4 = CMP_YM(130);
  lstInitListWindow(v3, v4, 0xFFFFFu, 236, 168, 0x19191E59u, 0, pListWindow);
  CursorInfo = pListWindow->CursorInfo;
  cmpInitCursorSize(CursorInfo, 30, 12, 196, 26, 26);
}

// 0x1994150
void rcvInitStockWindow(lstListWindow_t *pListWindow) {
  s32 v3;
  s32 v4;
  cmpCursorInfo_t_o *CursorInfo;

  v3 = CMP_XM(30);
  v4 = CMP_YM(113);
  lstInitListWindow(v3, v4, 0xFFFFFu, 452, 184, 0x19191E59u, 0, pListWindow);
  CursorInfo = pListWindow->CursorInfo;
  cmpInitCursorSize(CursorInfo, 33, 8, 403, 26, 35);
}
