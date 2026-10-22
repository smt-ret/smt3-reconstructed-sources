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
  cmpCursorInfo_t_o *CursorInfo;
  s32 CursorIndex;
  dds3ConfigMain_c *v6;
  u64 v8;
  s64 v9;
  struct UnityEngine_GameObject_array *ConfigCursor;
  UnityEngine_Object_o *v12;
  struct UnityEngine_GameObject_array *v14;
  s32 configSelTop;
  s32 v17;
  s32 v19;

  CursorInfo = GBWK->CursorInfo;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  if (CursorIndex >= 1)
  {
    v8 = 0;
    v9 = CursorIndex;
    do
    {
      ConfigCursor = _configUIScr->ConfigCursor;
      v12 = ConfigCursor->m_Items[v8];
      if (op_Equality(v12, 0, 0))
        goto LABEL_26;
      v14 = _configUIScr->ConfigCursor;
      if (!get_activeSelf(v14->m_Items[v8]))
LABEL_26:
        --CursorIndex;
      ++v8;
    }
    while (v9 != v8);
  }
  else
  {
    if (configSelTop > CursorIndex)
      goto LABEL_37;
  }
  if (configSelTop + 3 <= CursorIndex)
  {
LABEL_37:
    v17 = *&v6->_2.bitflags1 & 0x200;
    if (CursorIndex <= 2)
    {
      if (!configSelTop)
        return;
      if ((v6->_2.bitflags2 & 2) != 0)
        goto LABEL_42;
      goto LABEL_49;
    }
    else
    {
      v19 = configSelTop;
      if (v19 > CursorIndex)
        goto LABEL_41;
    }
    if (v19 + 3 < CursorIndex)
    {
      configSelTop = CursorIndex - 3;
    }
  }
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
          if (HasProperty_27243776(*(v19 + 8 * v18), "_Config_Bright", 0))
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
  u32 v3;

  else
  {
    v3 = Type;
  }
  return cfgGetBit(v3);
}

// 0x152ded0
s8 dds3ChkConfigProcess(void) {
  s32 gProcessStat;

  if (gProcessStat == 1)
    return 1;
LABEL_6:
  if (gProcessStat != 2)
    return 0;
  gProcessStat = 0;
  return 0;
}

// 0x152de30
void dds3ConfigProcessEnd(void) {
  dds3KillProcessName("config", 1);
  dds3KillProcessName("config_draw", 1);
  dds3KillProcessName("config_update", 1);
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
  LoadLocalizeText("common", "CONFIG");
  PlatformStr = GetPlatformStr();
  v8 = Concat_5224608("common", PlatformStr);
  v9 = GetPlatformStr();
  v10 = Concat_5224608("CONFIG", v9);
  LoadLocalizeText(v8, v10);
  LoadLocalizeText("common", "DDS3CONFIGHELP");
  v11 = GetPlatformStr();
  v12 = Concat_5224608("common", v11);
  v13 = GetPlatformStr();
  v14 = Concat_5224608("DDS3CONFIGHELP", v13);
  LoadLocalizeText(v12, v14);
  firstDifficulty = cfgGetBit(9u);
  dds3ConfigScrollPositionSet(0);
  v17 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v17,
    0,
    Method_dds3ConfigMain_dds3CalcConfig__);
  data = GBWK;
  dds3StartProcess("config", 0x3F2u, 1, 1, v17, 0, 0, 0, data, 0);
  v20 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v20,
    0,
    Method_dds3ConfigMain_dds3DrawConfig__);
  dds3StartProcess(
    "config_draw",
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
    "config_update",
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
  UnityEngine_Transform_o *transform;
  UnityEngine_RectTransform_o *v5;
  f32 y;
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_RectTransform_o *v8;
  f32 v10;
  UnityEngine_Transform_o *v11;
  f32 v13;
  f32 v14;
  u64 *v15;
  Il2CppObject *v17;
  s32 v19;
  UnityEngine_Transform_o *v21;
  UnityEngine_Transform_o *v24;
  UnityEngine_Transform_o *Child;
  UnityEngine_RectTransform_o *v26;
  System_Object_array *v27;
  s64 *v29;
  s64 *v30;
  s64 *v33;
  s64 *v34;
  Il2CppObject *v38;
  f32 v45;
  f32 v46;
  s32 v47;
  f32 v48;

  transform = get_transform(_configUIScr->_scrollRect, 0);
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
  v8 = get_transform(
         _configUIScr->_scrollcontent,
         0);
  if (v8 && v8->klass != UnityEngine_RectTransform)
    v8 = 0;
  v45 = get_sizeDelta(v8).y;
  if (v45 <= y)
  {
    set_verticalNormalizedPosition(Component_GUILayer, 1.0);
  }
  else
  {
    v10 = v45;
    v11 = get_transform(_configUIScr->_scrollcontent, 0);
    v13 = (((index + 0.5) / get_childCount(v11)) - ((y * 0.5) / v10)) / (1.0 - (y / v10));
    v14 = Clamp(1.0 - v13, 0.0, 1.0);
    set_verticalNormalizedPosition(Component_GUILayer, v14);
    v48 = v10;
    v15 = sub_8D3950(f32, &v48);
    v17 = Concat_5269984("contentHeight[", v15, "]");
    Log(v17, 0);
    v19 = 0;
    {
LABEL_27:
    }
    while (1)
    {
      v21 = get_transform(_configUIScr->_scrollcontent, 0);
      if (v19 >= get_childCount(v21))
        break;
      v24 = get_transform(_configUIScr->_scrollcontent, 0);
      Child = GetChild(v24, v19);
      if (Child)
      {
        if (Child->klass == UnityEngine_RectTransform)
          v26 = Child;
        else
          v26 = 0;
      }
      else
      {
        v26 = 0;
      }
      get_sizeDelta(v26);
      v27 = NewSpecific(object, 5u);
      v27->m_Items[0] = "content[";
      v47 = v19;
      v29 = sub_8D3950(s32, &v47);
      v30 = v29;
      v27->m_Items[1] = v30;
      v27->m_Items[2] = ":";
      v46 = get_sizeDelta(v26).y;
      v33 = sub_8D3950(f32, &v46);
      v34 = v33;
      v27->m_Items[3] = v34;
      v27->m_Items[4] = "]";
      v38 = Concat_5270224(v27);
      Log(v38, 0);
      ++v19;
        goto LABEL_27;
    }
  }
}

// 0x152cca0
dds3ProcessFunc_t *dds3DestroyConfig(dds3ProcessID_t *PID) {
  System_Array_o *config_data;
  struct System_Int32_array_array *gFlagBak;
  u64 *v8;
  dds3AdminiData_t_o *AdminiProcessData;
  u32 Stat;
  Il2CppObject *CallData;
  u32 v14;
  sdfTexHandle_t_o *BG;
  UnityEngine_Object_o *configObj;
  struct dds3DefaultMain_o *kernelObject;
  UnityEngine_Object_o *campObjUI;
  System_String_o *PlatformStr;
  System_String_o *v25;
  System_String_o *v26;
  System_String_o *v27;
  s32 v29;

  if (GBWK)
  {
    config_data = DDS3_GBWK->config_data;
    Copy_3886320(config_data, gFlagBak->m_Items[1], DDS3_GBWK->config_data->max_length);
    if (GBWK->ProcMode == 1)
    {
      ButtonGuideDispOff();
      v29 = 1;
      v8 = sub_8D3950(s32, &v29);
      AdminiProcessData = GetAdminiProcessData(v8);
      Stat = AdminiProcessData->Stat;
      AdminiProcessData->NextSequence = 2;
      AdminiProcessData->CallCount = 2;
      CallData = AdminiProcessData->CallData;
      v14 = Stat & 0xFFFEFFF6 | 1;
      AdminiProcessData->Stat = v14;
      if (CallData)
      {
        AdminiProcessData->CallData = 0;
        AdminiProcessData->CallDataSize = 0;
      }
      AdminiProcessData->CallData = v8;
      AdminiProcessData->CallDataSize = 4 * (v8 != 0);
      AdminiProcessData->Stat = v14 & 0xFFFEFFF3;
      CampDispOff(kernelObject, 1);
    }
    BG = GBWK->BG;
    if (BG)
    {
      sdfTexFree(BG);
    }
    GBWK = 0;
    gProcessStat = 0;
  }
  Destroy_27360000(configObj);
  configObj = 0;
  _configUIScr = 0;
  if (_baseFlagConfig)
  {
    campObjUI = kernelObject->campObjUI;
    if (!op_Equality(campObjUI, 0, 0)
      && !get_activeSelf(kernelObject->campObjUI))
    {
      SetActive(kernelObject->campObjUI, 1, 0);
    }
    cmpMenuInit(8);
  }
  Remove("CONFIG", 0);
  PlatformStr = GetPlatformStr();
  v25 = Concat_5224608("CONFIG", PlatformStr);
  Remove(v25, 0);
  Remove("DDS3CONFIGHELP", 0);
  v26 = GetPlatformStr();
  v27 = Concat_5224608("DDS3CONFIGHELP", v26);
  Remove(v27, 0);
  return 0;
}

// 0x1526460
dds3ProcessFunc_t *dds3DrawConfig(dds3ProcessID_t *PID) {
  bool v6;
  cmpSeqInfo_t_o *SeqInfo;

  cmpConfigObjUI();
  if ((GBWK->SeqInfo->Flag & 0x10) != 0)
  {
    else
    {
      v6 = cfgChkBGMChange(dds3ConfigMain);
      if (v6)
        goto LABEL_10;
    }
  }
  cfgDrawFrame(0x47u);
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
      goto LABEL_47;
    goto LABEL_44;
  }
LABEL_26:
  v4->BG = fclLoadTexture("/title/cfg_bg.tmx");
  CampDispOn(kernelObject, 1);
  v22 = kernelObject;
  v23 = v22->campObjUI;
  if (!op_Equality(v23, 0, 0) && get_activeSelf(v22->campObjUI))
    SetActive(v22->campObjUI, 0, 0);
  ButtonGuideDispSet("CFG01", 0, 0, 90);
  {
LABEL_44:
  }
LABEL_47:
  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, "common", "dds3data/UI", "configUI");
  v28 = Find("Canvas_UI", 0);
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
              goto LABEL_60;
            goto LABEL_36;
          }
          goto LABEL_35;
        }
LABEL_48:
        SeqInfo->Flag = Flag | 0x10;
        v14 = 1;
          goto LABEL_60;
        goto LABEL_36;
      }
      if (CursorIndex == 13)
        goto LABEL_48;
LABEL_59:
      v14 = 0;
        goto LABEL_60;
      goto LABEL_36;
    }
    switch (v5)
    {
      case 0x20u:
        v14 = 1;
        CursorPosCorrection(1);
        ScrollTopCorrection();
          goto LABEL_60;
        goto LABEL_36;
      case 0x40u:
        if (CursorIndex == 13)
          goto LABEL_59;
        Bit = cfgGetBit(CursorIndex);
        p_config_data = &DDS3_GBWK->config_data;
        v21 = Bit - 1;
        break;
      case 0x80u:
        if (CursorIndex == 13)
          goto LABEL_59;
        v18 = cfgGetBit(CursorIndex);
        p_config_data = &DDS3_GBWK->config_data;
        v21 = v18 + 1;
        break;
      default:
LABEL_35:
        v14 = 1;
          goto LABEL_60;
LABEL_36:
LABEL_60:
        if (cmpChkPadPressUpDown())
        {
LABEL_61:
          {
LABEL_62:
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
LABEL_45:
          goto LABEL_62;
        }
LABEL_38:
        v24 = GBWK->CursorInfo;
        cmpMoveCursor(v24, 0);
          goto LABEL_62;
        goto LABEL_45;
    }
    cfgSetBit(CursorIndex, p_config_data, v21);
    v14 = 1;
      goto LABEL_60;
    goto LABEL_36;
  }
  if (cfgChkBGMChange())
    PID->func_ans = -1;
  return 0;
}

// 0x152bba0
void slScrollPositionTop(s32 top) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v5;
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_RectTransform_o *v9;
  f32 v11;
  s64 **v12;
  f32 v13;
  u64 v14;
  s32 v15;
  struct UnityEngine_GameObject_array *ConfigCursor;
  UnityEngine_Object_o *v23;
  struct UnityEngine_GameObject_array *v25;
  UnityEngine_Transform_o *v28;
  UnityEngine_Transform_o *Child;
  UnityEngine_RectTransform_o *v30;
  f32 v31;
  System_Object_array *v32;
  s64 **v33;
  s64 *v34;
  s64 *v36;
  s64 *v37;
  s64 *v41;
  s64 *v42;
  Il2CppObject *v46;
  f32 v47;
  f32 y;
  UnityEngine_UI_ScrollRect_o *v49;
  f32 v50;
  s32 v51;

  transform = get_transform(_configUIScr->_scrollRect, 0);
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
  Component_GUILayer = GetComponent_GUILayer_(v5);
  if (top)
  {
    v49 = Component_GUILayer;
    v9 = get_transform(_configUIScr->_scrollcontent, 0);
    if (v9 && v9->klass != UnityEngine_RectTransform)
      v9 = 0;
    y = get_sizeDelta(v9).y;
    v11 = y - COERCE_FLOAT(LODWORD(get_sizeDelta(v5).y));
    if (top < 1)
    {
      v13 = 0.0;
    }
    else
    {
      v12 = &"content[";
      v13 = 0.0;
      v14 = 0;
      v15 = 0;
      do
      {
        ConfigCursor = _configUIScr->ConfigCursor;
        v23 = ConfigCursor->m_Items[v14];
        if (!op_Equality(v23, 0, 0))
        {
          v25 = _configUIScr->ConfigCursor;
          if (get_activeSelf(v25->m_Items[v14]))
          {
            v28 = get_transform(_configUIScr->_scrollcontent, 0);
            Child = GetChild(v28, v14);
            if (Child)
            {
              if (Child->klass == UnityEngine_RectTransform)
                v30 = Child;
              else
                v30 = 0;
            }
            else
            {
              v30 = 0;
            }
            v31 = get_sizeDelta(v30).y;
            v32 = NewSpecific(object, 5u);
            v33 = v12;
            v34 = *v12;
            v32->m_Items[0] = v34;
            v51 = v15;
            v36 = sub_8D3950(s32, &v51);
            v37 = v36;
            v32->m_Items[1] = v37;
            v32->m_Items[2] = ":";
            v50 = get_sizeDelta(v30).y;
            v41 = sub_8D3950(f32, &v50);
            v42 = v41;
            v12 = v33;
            v32->m_Items[3] = v42;
            v32->m_Items[4] = "]";
            v46 = Concat_5270224(v32);
            v13 = v13 + v31;
            Log(v46, 0);
            ++v15;
          }
        }
        ++v14;
      }
      while (v15 < top);
    }
    v47 = Clamp(1.0 - (v13 / v11), 0.0, 1.0, 0);
    set_verticalNormalizedPosition(v49, v47);
  }
  else
  {
    set_verticalNormalizedPosition(Component_GUILayer, 1.0);
  }
}
