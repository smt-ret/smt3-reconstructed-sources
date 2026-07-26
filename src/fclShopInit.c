#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct cmpCmdSelInfo_t cmpCmdSelInfo_t;
typedef struct cmpSeqInfo_s cmpSeqInfo_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclDataShop_t fclDataShop_t;
typedef struct fclPanelMoverFunc_t fclPanelMoverFunc_t;
typedef struct fclPanelMover_t fclPanelMover_t;
typedef struct fclPanel_t fclPanel_t;
typedef struct lstListWindow_t lstListWindow_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static char *gFclShopTexFile[2];
static s32 mPlace;
static s32 OwnerID;
static char *VoiceName;
static u8 LISTMAX;
static fclDataShop_t *GBWK;
static s8 gProcessStat;
static char *gShopMenuStr[4];

void ButtonGuideDispOff(void);
s32 CMP_X(s32 a);
s32 CMP_XM(s32 a);
s32 CMP_Y(s32 b);
s32 CMP_YM(s32 b);
void FadeOutWindow(void);
s8 FclDebug(s8 Mode, void *pData);
void FilterDelete(void);
void FinalizeUI(void);
s32 FindId(s32 type, char *name);
char *GetAppendix(void);
void InitializeGameObject(void);
void InitializeModelCameraForUnity(void);
void InitializeUI(s32 eventno);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void LoadKeys(s32 type, char *key, char *path);
void LoadLocalizeText(char *key, char *filename);
void Remove(char *key);
void SetButtonGuide(s32 mode, bool sw);
void SetRootMenuText(cmpCmdSelInfo_t **csel, char **menu);
void UnloadAB(AssetBundleCtrl *this, char *key);
void WindowDispOff(bool sw);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
void evtDisableMoonCalc(void);
void evtDisableMoonDraw(void);
void evtStartEvent(s32 no);
void fclClearSignal(s8 Idx);
void fclFreeStage(void);
void fclInitPanel(fclPanel_t *pPanel, s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Type, s8 Spd);
void fclInitPanelMover(fclPanelMover_t *pMover, s32 DefX, s32 DefY, s32 MaxOfsX, s32 MaxOfsY, s32 DefRate, s32 Spd, fclPanelMoverFunc_t *MoverFunc);
fclDataShop_t *fclInitShop(s8 Place, cmpSeqInfo_t *pParentSeqInfo);
sdfTexHandle_t *fclLoadTexture(char *pFileName);
void fclScriptForcedEnd(dds3ProcessID_t *PID);
void fclSetPanelTex(fclPanel_t *pPanel, u32 UV1, u32 UV2, u32 UV3, u32 UV4, sdfTexHandle_t *TexHandle);
s8 fclSetVal(s8 Idx, s32 Val);
void fclShopEventEnd(void);
void fclShopInitPanelMover(fclDataShop_t *pData);
void fclShopLoadMesScript(fclDataShop_t *pData, s32 Place);
void fclShopTexFree(fclDataShop_t *pData);
void fclShopTexLoad(fclDataShop_t *pData);
bool fldProc_CallSisetuReturn(void);
void lstInitListWindow(s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Style, lstListWindow_t *pListWindow);
s32 p2sdFadeOut(s32 a);
s32 p2sdPlayBGM(s32 a);
void sdfTexFree(sdfTexHandle_t *aHandle);
void shpInitItemWindow(lstListWindow_t *pListWindow);

// 0x19a62a0
s8 fclChkShopProcess(void) {
  struct fclShopInit_StaticFields *static_fields;
  s32 gProcessStat;

  static_fields = fclShopInit->static_fields;
  gProcessStat = static_fields->gProcessStat;
  if (gProcessStat == 1)
    return 1;
  if (gProcessStat != 2)
    return 0;
  static_fields->gProcessStat = 0;
  return 0;
}

// 0x19a5760
void *fclDestroyShop(dds3ProcessID_t *PID) {
    fclShopTexFree(0);
    fclScriptForcedEnd(0);
    fclShopEventEnd();
    evtDisableMoonDraw();
    FindId(0, 0);
    p2sdFadeOut(0);
    FinalizeUI();
    WindowDispOff(0);
    Remove(0);
    IsLoad(0, 0);
    UnloadAB(0, 0);
    GetAppendix();
    return 0;
}

// 0x19a4a10
fclDataShop_t *fclInitShop(s8 Place, cmpSeqInfo_t *pParentSeqInfo) {
  fclDataShop_t_o *v5;
  cmpSeqInfo_t_o *SeqInfo;
  fclPanel_t_o *HelpPanel;
  s32 v13;
  s32 v15;
  fclPanel_t_o *BackPanel;
  s32 v18;
  s32 v19;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *Appendix;
  System_String_o *v28;
  System_String_o *v29;
  System_String_o *v30;
  AssetBundleCtrl_o *v31;
  AssetBundleCtrl_o *v32;
  fclShopInit_c *v34;
  bool v35;
  s32 v36;
  struct fclShopInit_StaticFields *static_fields;
  struct fclShopInit_StaticFields *v38;
  AssetBundleCtrl_o *v39;
  AssetBundleCtrl_o *v42;

  v5 = Allocate(fclDataShop_t);
  fclDataShop_t___ctor(v5);
  FilterDelete();
  SeqInfo = v5->SeqInfo;
  cmpInitSeqInfo(SeqInfo, pParentSeqInfo);
  v5->SeqInfo->Current = 0;
  v5->SeqInfo->Last = 0;
  v5->SeqInfo->Change = 1;
  v5->Place = Place;
  v5->ScriptPID = 0;
  mPlace = Place;
  shpInitItemWindow(v5->ListWindow);
  HelpPanel = v5->HelpPanel;
  v13 = CMP_X(318);
  v15 = CMP_Y(113);
  fclInitPanel(HelpPanel, v13, v15, 0xFFFFFu, 189, 98, FCL_SHOP_WINCOL_HELP, 2, 16);
  BackPanel = v5->BackPanel;
  v18 = CMP_X(0);
  v19 = CMP_Y(83);
  fclInitPanel(BackPanel, v18, v19, 0xFFFFFu, 512, 228, 0, 0, 29);
  evtDisableMoonCalc();
  fclShopTexLoad(v5);
  fclShopInitPanelMover(v5);
  fclSetVal(2, 0);
  fclSetVal(3, Place);
  InitializeModelCameraForUnity();
  asset_bc = get_asset_bc();
  Appendix = GetAppendix();
  v28 = Concat_5224608(StringLiteral_4691, Appendix);
  v29 = GetAppendix();
  v30 = Concat_5224608(StringLiteral_4691, v29);
  Load(asset_bc, v28, v30, 0);
  v31 = get_asset_bc();
  Load(v31, StringLiteral_4691, StringLiteral_4691, 0);
  v32 = get_asset_bc();
  Load(v32, StringLiteral_16430, StringLiteral_16430, 0);
  if (mPlace == 1)
  {
    v35 = !evtBitCheck(2353);
    if (v35)
      v36 = 2;
    else
      v36 = 0;
  }
  else
  {
    v36 = 0;
  }
  OwnerID = v36;
  static_fields = v34->static_fields;
  if (static_fields->mPlace == 5)
  {
    static_fields->OwnerID = 1;
  }
  VoiceName = 0;
  v38 = v34->static_fields;
  if (v38->OwnerID == 2)
  {
    v38->VoiceName = StringLiteral_16431;
    v39 = get_asset_bc();
    if (!IsLoad(v39, VoiceName))
    {
      v42 = get_asset_bc();
      Load(v42, VoiceName, VoiceName, 0);
    }
  }
  v5->Initialized = 0;
  return v5;
}

// 0x19a5d30
void fclShopEventEnd(void) {
    dds3KillProcessName(0, 0);
    fclFreeStage();
}

// 0x19a09d0
void fclShopEventStart(s8 Signal) {
  fclSetVal(1, Signal);
  fclClearSignal(1);
  evtStartEvent(802);
}

// 0x19a5260
void fclShopInitPanelMover(fclDataShop_t *pData) {
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

// 0x19a55a0
void fclShopLoadMesScript(fclDataShop_t *pData, s32 Place) {
  System_String_o *v6;
  s32 v7;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v10;
  s64 *v11;

  evtBitOff(2812);
  if (Place == 5)
  {
    v6 = StringLiteral_16440;
    evtBitOn(2812);
    v7 = 2;
  }
  else if (Place == 1 && !evtBitCheck(2353))
  {
    v6 = StringLiteral_16439;
    v7 = 1;
  }
  else
  {
    v6 = StringLiteral_16438;
    v7 = 0;
  }
  asset_bc = get_asset_bc();
  pData->pScriptData = LoadFileByte(asset_bc, StringLiteral_4691, v6);
  if (v7 == 2)
  {
    v10 = StringLiteral_4691;
    v11 = &StringLiteral_16433;
  }
  else if (v7 == 1)
  {
    v10 = StringLiteral_4691;
    v11 = &StringLiteral_16434;
  }
  else
  {
    v10 = StringLiteral_4691;
    v11 = &StringLiteral_16432;
  }
  LoadLocalizeText(v10, *v11);
}

// 0x19a6180
s32 fclShopProcessEnd(void) {
  if (!fldProc_CallSisetuReturn())
    return 0;
  FadeOutWindow();
  dds3KillProcessName(StringLiteral_16442, 1);
  dds3KillProcessName(StringLiteral_16443, 1);
  dds3KillProcessName(StringLiteral_16444, 1);
  return 1;
}

// 0x19a5e90
void fclShopProcessStart(void *pPlace) {
    fclInitShop(0, 0);
    FclDebug(0, 0);
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
}

// 0x19a5c00
void fclShopTexFree(fclDataShop_t *pData) {
  char v3;
  struct sdfTexHandle_t_array *TexHandle;
  sdfTexHandle_t_o *v7;

  v3 = 0;
  {
  }
  while (v3 < SLODWORD(gFclShopTexFile->max_length))
  {
    TexHandle = pData->TexHandle;
    v7 = TexHandle->m_Items[v3];
    sdfTexFree(v7);
    ++v3;
  }
  Write(StringLiteral_16437, 0);
}

// 0x19a5050
void fclShopTexLoad(fclDataShop_t *pData) {
    fclLoadTexture(0);
    fclSetPanelTex(0, 0, 0, 0, 0, 0);
}

// 0x19a5370
void fclShopUpdateInit(fclDataShop_t *data) {
  s32 Id;

  LoadKeys(1, StringLiteral_4691, 0);
  LoadKeys(3, StringLiteral_4691, 0);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_16174);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5045);
  Id = FindId(0, StringLiteral_11811);
  p2sdPlayBGM(Id);
  InitializeUI(802);
  SetButtonGuide(0, 0);
  ButtonGuideDispOff();
  data->EventEnd = 0;
  SetRootMenuText(&data->CmdSelInfo, gShopMenuStr);
  InitializeGameObject();
  fclShopLoadMesScript(data, mPlace);
}

// 0x19a6370
void fclTerminateShop(void) {
  struct fclDataShop_t_o *GBWK;

  if (GBWK)
  {
    GBWK->SeqInfo->Flag |= 0x10u;
  }
}

// 0x19a5de0
s32 shpGetPay(void) {
  struct fclDataShop_t_o *GBWK;

  if (!GBWK)
    return 0;
  return GBWK->PayMoney;
}

// 0x19a4f10
void shpInitItemWindow(lstListWindow_t *pListWindow) {
  s32 v3;
  s32 v4;
  cmpCursorInfo_t_o *CursorInfo;
  cmpCursorInfo_t_o *v9;

  v3 = CMP_XM(12);
  v4 = CMP_YM(113);
  lstInitListWindow(v3, v4, 0xFFFFFu, 299, 184, 0x19191E59u, 0, pListWindow);
  CursorInfo = pListWindow->CursorInfo;
  cmpInitCursorSize(CursorInfo, 33, 16, 255, 22, 26);
  v9 = pListWindow->CursorInfo;
  cmpInitCursorInfo(v9, LISTMAX, LISTMAX, 0);
}
