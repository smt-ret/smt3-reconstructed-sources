#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct cfgCaptionData_t cfgCaptionData_t;
typedef struct configUI configUI;
typedef struct dds3AdminiData_t dds3AdminiData_t;
typedef struct dds3ConfigGBWK_t dds3ConfigGBWK_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclSprTblArry_t fclSprTblArry_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static fclSprTblArry_t *dds3ConfigSprTblArry[2];
static void *configObj;
static configUI *_configUIScr;
static bool _baseFlagConfig;
static s32 firstDifficulty;
static s32 configSelTop;
static s32 configBakTop;
static s32 firstBGM;
static bool init_flag;
static cfgCaptionData_t *ConfigCaptionData[14];
static dds3ConfigGBWK_t *GBWK;
static s8 gProcessStat;
static s32 *gFlagBak[2];
static f32 britbl[19];
static s32 id_Config_Bright;

void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
void CampDispOff(dds3DefaultMain *this, bool titlemode);
void CampDispOn(dds3DefaultMain *this, bool titlemode);
void CursorPosCorrection(s8 Dir);
dds3AdminiData_t *GetAdminiProcessData(void);
f32 GetConfigBright(void);
char *GetPlatformStr(void);
void LoadLocalizeText(char *key, char *filename);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Remove(char *key);
void ScrollTopCorrection(void);
void dds3ConfigScrollPositionSet(s32 index);
dds3ConfigGBWK_t *dds3InitConfig(s32 Mode);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
sdfTexHandle_t *fclLoadTexture(char *pFileName);
void sdfTexFree(sdfTexHandle_t *aHandle);

// 0x1527cb0
void CursorPosCorrection(s8 Dir) {
  cmpCursorInfo_t_o *CursorInfo;
  s32 CursorIndex;
  struct UnityEngine_GameObject_array *ConfigCursor;
  s64 v8;
  UnityEngine_Object_o *v10;
  struct UnityEngine_GameObject_array *v12;

  while (1)
  {
    CursorInfo = GBWK->CursorInfo;
    cmpMoveCursor(CursorInfo, Dir);
    CursorIndex = cmpGetCursorIndex(GBWK->CursorInfo);
    ConfigCursor = _configUIScr->ConfigCursor;
    v8 = CursorIndex;
    v10 = ConfigCursor->m_Items[CursorIndex];
    if (!op_Equality(v10, 0, 0))
    {
      v12 = _configUIScr->ConfigCursor;
      if (get_activeSelf(v12->m_Items[v8]))
        break;
    }
  }
}

// 0x1528e00
f32 GetConfigBright(void) {
  s32 Bit;
  f32 v4;
  s32 v5;
  struct System_Single_array *britbl;
  s32 max_length;

  Bit = cfgGetBit(8u);
  v4 = 1.0;
  if ((Bit & 0x80000000) == 0)
  {
    v5 = Bit;
    max_length = britbl->max_length;
    if (v5 < max_length)
    {
      return britbl->m_Items[v5];
    }
  }
  return v4;
}

// 0x1527e40
void ScrollTopCorrection(void) {
}

// 0x1528ac0
void SetTextMeshBright(void) {
  f32 ConfigBright;
  f32 v6;
  UnityEngine_GameObject_o *BrighTextMesh;
  UnityEngine_Transform_o *transform;
  s32 v9;
  UnityEngine_Transform_o *v10;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Component_o *v13;
  UnityEngine_GUILayer_o *Component_GUILayer;
  s64 v15;
  s64 v16;
  s64 v17;
  u64 v18;
  s64 v19;
  UnityEngine_Material_o *v24;
  UnityEngine_Transform_o *v25;

  ConfigBright = GetConfigBright();
  v6 = ConfigBright;
  BrighTextMesh = kernelObject->BrighTextMesh;
  transform = get_transform(BrighTextMesh, 0);
  if (get_childCount(transform) >= 1)
  {
    v9 = 0;
    do
    {
      v10 = get_transform(BrighTextMesh, 0);
      Child = GetChild(v10, v9);
      gameObject = get_gameObject(Child);
      v13 = get_transform(gameObject, 0);
      Component_GUILayer = GetComponent_GUILayer_(v13);
      v15 = (*&Component_GUILayer->klass[3]._2.thread_static_fields_size)(
              Component_GUILayer,
              *&Component_GUILayer->klass[3]._2.flags);
      v16 = *(v15 + 24);
      if (v16 >= 1)
      {
        v17 = v15;
        v18 = 0;
        v19 = v15 + 32;
        do
        {
          if (HasProperty_27243776(*(v19 + 8 * v18), StringLiteral_5226, 0))
          {
            v24 = *(v19 + 8 * v18);
            SetFloat_27246832(v24, id_Config_Bright, v6);
          }
          LODWORD(v16) = *(v17 + 24);
          ++v18;
        }
        while (v18 < v16);
      }
      ++v9;
      v25 = get_transform(BrighTextMesh, 0);
    }
    while (v9 < get_childCount(v25));
  }
}

// 0x1526360
dds3ProcessFunc_t *dds3CalcConfig(dds3ProcessID_t *PID) {
  u64 v3;
  cmpSeqInfo_t_o *SeqInfo;

  if ((*(*(*(*(v3 + 184) + 56LL) + 16LL) + 16LL) & 0x10) != 0)
  {
    if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
    if (cfgChkBGMChange(v3))
    {
      SeqInfo = GBWK->SeqInfo;
      cmpUpdateTerminate(SeqInfo);
      PID->func_ans = -1;
    }
  }
  return 0;
}

// 0x1528cc0
s32 dds3CheckConfigBit(u32 Type) {
    return 0;
}

// 0x152ded0
s8 dds3ChkConfigProcess(void) {
  struct dds3ConfigMain_StaticFields *static_fields;
  s32 gProcessStat;

  static_fields = dds3ConfigMain->static_fields;
  gProcessStat = static_fields->gProcessStat;
  if (gProcessStat == 1)
    return 1;
  if (gProcessStat != 2)
    return 0;
  static_fields->gProcessStat = 0;
  return 0;
}

// 0x152de30
void dds3ConfigProcessEnd(void) {
  dds3KillProcessName(StringLiteral_14668, 1);
  dds3KillProcessName(StringLiteral_14669, 1);
  dds3KillProcessName(StringLiteral_14670, 1);
}

// 0x152d4f0
void dds3ConfigProcessStart(s32 Mode) {
  struct dds3ConfigGBWK_t_o *inited;
  System_String_o *PlatformStr;
  System_String_o *v8;
  System_String_o *v9;
  System_String_o *v10;
  System_String_o *v11;
  System_String_o *v12;
  System_String_o *v13;
  System_String_o *v14;
  u64 *v17;
  Il2CppObject *data;
  u64 *v20;
  u64 *v21;
  u64 *v22;

  else if (GBWK)
  {
    return;
  }
  inited = dds3InitConfig(Mode);
  GBWK = inited;
  _configUIScr = GetComponent_object_(configObj);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_14666);
  PlatformStr = GetPlatformStr();
  v8 = Concat_5224608(StringLiteral_4611, PlatformStr);
  v9 = GetPlatformStr();
  v10 = Concat_5224608(StringLiteral_14666, v9);
  LoadLocalizeText(v8, v10);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_14667);
  v11 = GetPlatformStr();
  v12 = Concat_5224608(StringLiteral_4611, v11);
  v13 = GetPlatformStr();
  v14 = Concat_5224608(StringLiteral_14667, v13);
  LoadLocalizeText(v12, v14);
  firstDifficulty = cfgGetBit(9u);
  dds3ConfigScrollPositionSet(0);
  v17 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v17,
    0,
    Method_dds3ConfigMain_dds3CalcConfig__);
  data = GBWK;
  dds3StartProcess(StringLiteral_14668, 0x3F2u, 1, 1, v17, 0, 0, 0, data, 0);
  v20 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v20,
    0,
    Method_dds3ConfigMain_dds3DrawConfig__);
  dds3StartProcess(
    StringLiteral_14669,
    0x2B07u,
    1,
    1,
    v20,
    0,
    0,
    0,
    GBWK,
    0);
  v21 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v21,
    0,
    Method_dds3ConfigMain_dds3UpdateConfig__);
  v22 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v22,
    0,
    Method_dds3ConfigMain_dds3DestroyConfig__);
  dds3StartProcess(
    StringLiteral_14670,
    0x520Bu,
    1,
    1,
    v21,
    0,
    v22,
    0,
    GBWK,
    0);
  gProcessStat = 1;
}

// 0x152d860
void dds3ConfigScrollPositionSet(s32 index) {
}

// 0x152cca0
dds3ProcessFunc_t *dds3DestroyConfig(dds3ProcessID_t *PID) {
    ButtonGuideDispOff();
    GetAdminiProcessData();
    CampDispOff(0, 0);
    sdfTexFree(0);
    Remove(0);
    GetPlatformStr();
    return 0;
}

// 0x1526460
dds3ProcessFunc_t *dds3DrawConfig(dds3ProcessID_t *PID) {
    return 0;
}

// 0x152c260
dds3ConfigGBWK_t *dds3InitConfig(s32 Mode) {
  u8 v2;
  u64 *v3;
  dds3ConfigGBWK_t_o *v4;
  cmpSeqInfo_t_o *SeqInfo;
  cmpCursorInfo_t_o *CursorInfo;
  struct dds3DefaultMain_o *kernelObject;
  UnityEngine_Object_o *campObjUI;
  bool v16;
  struct dds3DefaultMain_o *v22;
  UnityEngine_Object_o *v23;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v28;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v32;

  v2 = Mode;
  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  v4 = Allocate(dds3ConfigGBWK_t);
  dds3ConfigGBWK_t___ctor(v4);
  v4->MH = v3;
  SeqInfo = v4->SeqInfo;
  cmpInitSeqInfo(SeqInfo, 0);
  CursorInfo = v4->CursorInfo;
  v4->ProcMode = v2;
  cmpInitCursorSize(CursorInfo, 0, 0, 0, 0, 0);
  cmpInitCursorInfo(v4->CursorInfo, 0xEu, 0xEu, 0);
  configBakTop = 0;
  configSelTop = 0;
  cfgInitPanelMover(v4);
  v4->BaseTimer = 0;
  campObjUI = kernelObject->campObjUI;
  if (op_Equality(campObjUI, 0, 0)
    || !get_activeSelf(kernelObject->campObjUI))
  {
    v16 = 0;
  }
  else
  {
    SetActive(kernelObject->campObjUI, 0, 0);
    v16 = 1;
  }
  _baseFlagConfig = v16;
  if (v4->ProcMode != 1)
  {
    v4->BG = 0;
  }
  v4->BG = fclLoadTexture(StringLiteral_14664);
  CampDispOn(kernelObject, 1);
  v22 = kernelObject;
  v23 = v22->campObjUI;
  if (!op_Equality(v23, 0, 0) && get_activeSelf(v22->campObjUI))
    SetActive(v22->campObjUI, 0, 0);
  ButtonGuideDispSet(StringLiteral_12430, 0, 0, 90);
  {
  }
  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, StringLiteral_4611, StringLiteral_5156, StringLiteral_14665);
  v28 = Find(StringLiteral_4905, 0);
  transform = get_transform(v28, 0);
  v32 = Instantiate_object__425664(Prefab_16624656, transform, 0);
  configObj = v32;
  AddComponent_object_(configObj);
  SetActive(configObj, 0, 0);
  firstBGM = cfgGetBit(5u);
  return v4;
}

// 0x1527490
dds3ProcessFunc_t *dds3UpdateConfig(dds3ProcessID_t *PID) {
  u16 v5;
  s32 CursorIndex;
  struct cmpSeqInfo_t_o *SeqInfo;
  u8 Flag;
  u32 v12;
  s32 v14;
  s32 v18;
  System_Int32_array **p_config_data;
  s32 v21;
  cmpCursorInfo_t_o *v24;
  cmpCursorInfo_t_o *CursorInfo;
  u16 v29;
  s32 Bit;

  v5 = cmpChkCommonInput(CMP_PE_NORMAL | 0xC0);
  CursorIndex = cmpGetCursorIndex(GBWK->CursorInfo);
  SeqInfo = GBWK->SeqInfo;
  Flag = SeqInfo->Flag;
  if ((Flag & 0x40) == 0)
  {
    v12 = v5;
    if (v5 <= 0x10u)
    {
      if (v5 != 1)
      {
        if (v5 != 2)
        {
          if (v5 == 16)
          {
            CursorPosCorrection(255);
            ScrollTopCorrection();
            v14 = 1;
          }
        }
        SeqInfo->Flag = Flag | 0x10;
        v14 = 1;
      }
      if (CursorIndex == 13)
      v14 = 0;
    }
    switch (v5)
    {
      case 0x20u:
        v14 = 1;
        CursorPosCorrection(1);
        ScrollTopCorrection();
      case 0x40u:
        if (CursorIndex == 13)
        Bit = cfgGetBit(CursorIndex);
        p_config_data = &DDS3_GBWK->config_data;
        v21 = Bit - 1;
        break;
      case 0x80u:
        if (CursorIndex == 13)
        v18 = cfgGetBit(CursorIndex);
        p_config_data = &DDS3_GBWK->config_data;
        v21 = v18 + 1;
        break;
      default:
        v14 = 1;
        if (cmpChkPadPressUpDown())
        {
          {
            CursorInfo = GBWK->CursorInfo;
            v28 = cmpDisablePadBitStop(CursorInfo, v12, 0x30u);
            v29 = v28;
            cfgUpdatePanelMover();
            cfgUpdateBaseTimer();
            if (v14)
            {
              cmpPlaySE(v29);
            }
            return 0;
          }
        }
        v24 = GBWK->CursorInfo;
        cmpMoveCursor(v24, 0);
    }
    cfgSetBit(CursorIndex, p_config_data, v21);
    v14 = 1;
  }
  if (cfgChkBGMChange())
    PID->func_ans = -1;
  return 0;
}

// 0x152bba0
void slScrollPositionTop(s32 top) {
}
