#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct FieldChrHD FieldChrHD;
typedef struct FsSaveData FsSaveData;
typedef struct GfxManager GfxManager;
typedef struct GlobalData_PadConfig GlobalData_PadConfig;
typedef struct GlobalData_ResultData GlobalData_ResultData;
typedef struct GlobalData_SaveData GlobalData_SaveData;
typedef struct GlobalData_SystemOption GlobalData_SystemOption;
typedef struct TextManager TextManager;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fclDataTerminal_t fclDataTerminal_t;

struct GlobalData_SystemOption {
    f32 sys_bgm_vol;
    f32 sys_se_vol;
};

struct GlobalData_SaveData {
    GlobalData_SystemOption gameoption;
    s16 pad2;
    GlobalData_ResultData stage_data[UNKNOWN_ARRAY_SIZE];
    GlobalData_PadConfig padconfig[UNKNOWN_ARRAY_SIZE];
};

struct GlobalData_ResultData {
    u8 Mission[UNKNOWN_ARRAY_SIZE];
    s16 State;
    s16 Star;
    u32 Score;
    u32 Count;
};

struct GlobalData_PadConfig {
    s16 btn_a;
    s16 btn_b;
    s16 btn_x;
    s16 btn_y;
    s16 btn_r1;
    s16 btn_l1;
    s16 btn_st;
    s16 key_u;
    s16 key_d;
    s16 key_l;
    s16 key_r;
    s16 key_lu;
    s16 key_ld;
    s16 key_rd;
    s16 key_ru;
    s16 type;
    u8 pad[UNKNOWN_ARRAY_SIZE];
};

static dds3DefaultMain *kernelObject;
static FsSaveData *saveData;
static s32 screen_wid;
static s32 screen_hei;
static s32 STAGEMAX;
static s32 SAVEDATA_VER;
static void world_font[UNKNOWN_ARRAY_SIZE];
static s16 CONTROLER_TYPE_KEYBOAD;
static s16 CONTROLER_TYPE_GAMEPAD;
static GlobalData_SaveData system_save;
static bool logoSkip;
static bool absorbSE;
static TextManager *txtMgr;
static GfxManager *gfxMgr;
static void *DebugObject;
static s32 loadmode;
static u8 dante_pb[UNKNOWN_ARRAY_SIZE];
static void *dlcreplist;
static char *attempt[5];

char *AppendDLC(char *name, bool append);
char *GetAkey(s32 no);
void *GetAnimator(void *obj);
char *GetAppendix(void);
char *GetLocalizeText(char *ID);
char *GetPBname(s32 no);
bool IsBGMStopped(void);
bool IsDLC(void);
bool IsDLCField(s32 area);
bool IsFieldBGMLoaded(char *key);
bool IsLoad(AssetBundles *this, char *key);
bool IsfldSetChar(char *name);
void Load(char *key, char *filePath);
void LoadKeys(s32 type, char *key, char *path);
void LoadLocalizeText(char *key, char *filename);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Log(char *fmt, void **parray);
void Remove(char *key);
void RemoveKeys(s32 type, char *key);
void SetDevilEffect(dds3Basic_t **bas, s32 id);
void StopBGMALL_Compulsion(bool flg);
void UnloadAB(AssetBundleCtrl *this, char *key);
bool dds3CheckDLC1(void);
bool dds3CheckDLC2(void);
bool dds3CheckDLC3(void);
bool dds3CheckDLC4(void);
bool dds3CheckDLC5(void);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);
bool dds3CheckDLC8(void);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
void fldBgmPlay(void);
void *fldGetCharObj(char *name);
void fldSetCharAdd(char *name, void *obj);
FieldChrHD *mdlSetHD(void *obj, s32 mode, evtUnitHandle_t *hunit, s32 layer);

// 0x1145d00
char *AppendDLC(char *name, bool append) {
    return 0;
}

// 0x1144d70
bool CheckDLCKey(char *key) {
    return 0;
}

// 0x1144ed0
u16 CheckRegistID(void) {
  if (IsDLC())
    return 193;
  else
    return 192;
}

// 0x1143350
s32 CurLoop(s32 idx, s32 idxmin, s32 idxmax) {
  s32 v4;

  v4 = idxmax - 1;
  if (idx >= idxmin)
    v4 = idx;
  if (v4 >= idxmax)
    return idxmin;
  else
    return v4;
}

// 0x1147b60
s32 DLCGetArea(s32 area) {
  bool v3;

  else
  {
    v3 = dds3CheckDLC6();
    if (area != 60)
  }
  if (v3)
    return 15;
  if (((area == 61) & dds3CheckDLC7()) != 0)
    return 16;
  else
    return area;
}

// 0x11478f0
s32 DLCGetFieldCheck(s32 no) {
  bool v3;
  bool v6;

  else
  {
    v3 = dds3CheckDLC6();
    if (no != 15)
  }
  if (v3)
  {
    if (fldGb->fieldID != 15)
      return 60;
  }
  v6 = dds3CheckDLC7();
  if (no == 16 && v6)
  {
    if (fldGb->fieldID != 16)
      return 61;
  }
  return no;
}

// 0x11476b0
s32 DLCGetFieldNo(s32 no) {
  bool v3;
  s32 v5;
  bool v6;
  bool v9;

  else
  {
    v3 = dds3CheckDLC6();
    if (no != 32)
  }
  if (v3)
    return 60;
  v6 = dds3CheckDLC7();
  v5 = 61;
  if (no == 33 && v6)
    return v5;
  v9 = dds3CheckDLC6();
  if (no == 62 && v9)
    return 60;
  if (((no == 63) & dds3CheckDLC7()) != 0)
    return 61;
  else
    return 0;
}

// 0x1147ad0
char *DLCGetFieldSeKey(char *key, s32 no) {
  if (no == 60)
    return StringLiteral_4909;
  if (no == 61)
    return StringLiteral_4910;
  return key;
}

// 0x11473e0
char *DLCGetTerminalName(s32 no) {
    dds3CheckDLC6();
    GetLocalizeText(0);
    dds3CheckDLC7();
    return 0;
}

// 0x11471e0
void DLCTerminalList(fclDataTerminal_t **term) {
  fclDataTerminal_t_o *v4;
  u32 TerminalCnt;
  struct System_SByte_array *TerminalList;
  fclDataTerminal_t_o *v9;
  u32 v10;
  struct System_SByte_array *v11;

  else  v4 = *term;
  if ((*term)->TerminalNo != 32)
  {
    TerminalCnt = v4->TerminalCnt;
    TerminalList = v4->TerminalList;
    ++v4->TerminalCnt;
    TerminalList->m_Items[TerminalCnt] = 32;
  }
  else if (!dds3CheckDLC7())
  {
    return;
  }
  v9 = *term;
  if ((*term)->TerminalNo != 33)
  {
    v10 = v9->TerminalCnt;
    v11 = v9->TerminalList;
    ++v9->TerminalCnt;
    v11->m_Items[v10] = 33;
  }
}

// 0x1143380
f32 GetAnimationClipTime(void *obj, char *clipname) {
  Il2CppObject *v5;
  Il2CppObject *Component_object;
  UnityEngine_RuntimeAnimatorController_o *runtimeAnimatorController;
  System_Object_array *animationClips;
  u64 *v10;
  Il2CppObject *object;

  v5 = Allocate(GlobalData___c__DisplayClass27_0);
  _ctor(v5, 0);
  v5[1].klass = clipname;
  Component_object = GetComponent_object_(obj);
  if (!op_Inequality(Component_object, 0, 0))
    return 0.0;
  runtimeAnimatorController = get_runtimeAnimatorController(Component_object);
  animationClips = get_animationClips(runtimeAnimatorController);
  v10 = Allocate(System_Predicate_AnimationClip_);
  __ctor(
    v10,
    v5,
    Method_GlobalData___c__DisplayClass27_0__GetAnimationClipTime_b__0__);
  object = Find_object_(animationClips, v10);
  if (op_Inequality(object, 0, 0))
    return get_length(object);
  else
    return 0.0;
}

// 0x1143500
char *GetFieldAssetName(char *fmt, s32 field) {
    IsDLCField(0);
    return 0;
}

// 0x1143370
s32 GetMachine(void) {
  return 1;
}

// 0x1145450
bool GetOrUsed(s32 idx) {
  bool result;

  switch (idx)
  {
    case 1:
      result = dds3CheckDLC1();
      break;
    case 2:
      result = dds3CheckDLC2();
      break;
    case 3:
      result = dds3CheckDLC3();
      break;
    case 4:
      result = dds3CheckDLC4();
      break;
    case 5:
      result = dds3CheckDLC5();
      break;
    case 6:
      result = dds3CheckDLC6();
      break;
    case 7:
      result = dds3CheckDLC7();
      break;
    case 8:
      result = dds3CheckDLC8();
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// 0x11458a0
s32 GetOwnerNo(s32 mode, s32 no) {
  if (mode || (no - 1) > 3)
    return -1;
  else
    return dword_32C3BA0[no - 1];
}

// 0x1145050
void InitializeDLCReplaceTable(void) {
}

// 0x1147cd0
bool IsDLCField(s32 area) {
  bool v3;

  else
  {
    v3 = dds3CheckDLC6();
    if (area != 60)
  }
  if (v3)
    return 1;
  return (area == 61) & dds3CheckDLC7();
}

// 0x1146310
bool IsFieldBGMLoaded(char *key) {
  System_String_o *appended;
  AssetBundleCtrl_o *Ctrl;

  appended = AppendDLC(key, 1);
  Ctrl = get_Ctrl();
  return IsLoad(Ctrl, appended);
}

// 0x1146ea0
bool IsReloaded(s32 oldbgm) {
    StopBGMALL_Compulsion(0);
    IsBGMStopped();
    RemoveKeys(0, 0);
    IsFieldBGMLoaded(0);
    LoadKeys(0, 0, 0);
    fldBgmPlay();
    return 0;
}

// 0x1144900
void LoadAssetExt(char *key, char *name, char *dlc) {
  System_String_o *v7;
  System_String_o *Appendix;
  System_String_o *v10;
  System_String_o *v11;
  System_String_o *v12;
  AssetBundleCtrl_o *Ctrl;
  s32 v14;
  AssetBundleCtrl_o *v16;
  DlcFileCtr_o *v17;

  v7 = key;
  if (get_Length(key) == 7)
    v7 = Substring_5248048(key, 0, 4);
  if (IsNullOrEmpty(dlc)
    && op_Inequality(v7, StringLiteral_4883, 0)
    && op_Inequality(v7, StringLiteral_4884, 0)
    && op_Inequality(v7, StringLiteral_4885, 0)
    && op_Inequality(v7, StringLiteral_4886, 0)
    && op_Inequality(v7, StringLiteral_4887, 0)
    && op_Inequality(v7, StringLiteral_4888, 0))
  {
  }
  Appendix = GetAppendix();
  v10 = Concat_5224608(StringLiteral_4690, Appendix);
  v11 = GetAppendix();
  v12 = Concat_5224608(StringLiteral_4689, v11);
  if (op_Equality(key, StringLiteral_4689, 0)
    || op_Equality(key, v12, 0)
    || op_Equality(key, StringLiteral_4690, 0)
    || op_Equality(key, v10, 0)
    || op_Equality(key, StringLiteral_4730, 0)
    || op_Equality(key, StringLiteral_4731, 0)
    || op_Equality(key, StringLiteral_4889, 0)
    || op_Equality(key, StringLiteral_4890, 0)
    || op_Equality(key, StringLiteral_4721, 0))
  {
    else if ((byte_3F58BA9 & 1) != 0)
    {
      Ctrl = get_Ctrl();
      Load(Ctrl, key, name, 0);
      return;
    }
  }
  if (op_Equality(v7, StringLiteral_4883, 0)
    || op_Equality(v7, StringLiteral_4885, 0)
    || op_Equality(v7, StringLiteral_4887, 0))
  {
    v14 = 6;
  }
  else
  {
    v14 = 2;
  }
  if (op_Equality(v7, StringLiteral_4884, 0)
    || op_Equality(v7, StringLiteral_4886, 0)
    || op_Equality(v7, StringLiteral_4888, 0))
  {
    v14 = 7;
  }
  v16 = get_Ctrl();
  v17 = get_dlc(v16);
  Load(v17, key, v14, name, 0);
}

// 0x11463e0
s32 LoadBattleBGM(s32 *bgmdone, s32 *bgmloadphase) {
  s32 result;
  s32 Bit;
  s32 v8;
  System_Object_array *v9;
  System_String_o *v12;
  System_String_o *v14;
  AssetBundleCtrl_o *v15;
  System_Object_array *v17;
  System_String_o *v18;
  System_String_o *appended;
  AssetBundleCtrl_o *Ctrl;
  AssetBundleCtrl_o *v24;
  DlcFileCtr_o *dlc;

  if (*bgmdone == 1)
    return 1;
  switch (*bgmloadphase)
  {
    case 1:
      Bit = cfgGetBit(5u);
      if ((Bit - 1) > 3)
        v8 = -1;
      else
        v8 = dword_32C3BA0[Bit - 1];
      v17 = Empty_string_();
      v18 = Format_5268784(StringLiteral_4900, v17);
      appended = AppendDLC(v18, 1);
      Ctrl = get_Ctrl();
      if (!IsLoad(Ctrl, appended))
      {
        v24 = get_Ctrl();
        dlc = get_dlc(v24);
        Load(dlc, appended, v8, appended, 0);
      }
    case 2:
      v9 = Empty_string_();
      v12 = Format_5268784(StringLiteral_4900, v9);
      v14 = AppendDLC(v12, 1);
      v15 = get_Ctrl();
      if (!IsLoad(v15, v14))
      LoadKeys(1, StringLiteral_4900, 0);
      ++*bgmloadphase;
      result = 0;
      break;
    case 3:
      *bgmloadphase = 4;
      return 0;
    case 4:
      *bgmloadphase = 0;
      *bgmdone = 1;
      return 1;
    default:
      result = 0;
      break;
  }
  return result;
}

// 0x1144f40
void LoadCollectionBook(void) {
  LoadLocalizeText(StringLiteral_4897, StringLiteral_4898);
  LoadLocalizeText(StringLiteral_4897, StringLiteral_4899);
}

// 0x1146020
void LoadField(s32 fld) {
    IsDLCField(0);
    Load(0, 0);
    Load(0, 0);
}

// 0x1145af0
void LoadFieldBGM(char *key) {
    AppendDLC(0, 0);
    Load(0, 0);
    Load(0, 0);
}

// 0x11435d0
s32 LoadManiacsChar(bool mode, s32 phase) {
    Log(0, 0);
    IsLoad(0, 0);
    Load(0, 0);
    Load(0, 0);
    return 0;
}

// 0x1143f20
void *LoadManiacsChar_18104096(s32 *phase) {
    IsDLC();
    Log(0, 0);
    IsfldSetChar(0);
    fldGetCharObj(0);
    IsLoad(0, 0);
    GetAkey(0);
    GetPBname(0);
    LoadPrefab_16624656(0, 0, 0, 0);
    GetAnimator(0);
    fldSetCharAdd(0, 0);
    UnloadAB(0, 0);
    dds3GetUnitHandleObjectBasic(0);
    mdlSetHD(0, 0, 0, 0);
    SetDevilEffect(0, 0);
    return 0;
}

// 0x1144760
void ReleaseManiacsChar(void) {
  bool IsDLC;
  s64 *v4;
  bool v5;
  System_String_o *v6;
  AssetBundleCtrl_o *Ctrl;
  System_String_o *v8;
  AssetBundleCtrl_o *v10;
  s64 *v11;

  IsDLC = IsDLC();
  v4 = &StringLiteral_2990;
  if (!IsDLC)
    v4 = &StringLiteral_4653;
  v5 = IsDLC;
  v6 = *v4;
  Ctrl = get_Ctrl();
  v8 = Concat_5224608(StringLiteral_4882, v6);
  UnloadAB(Ctrl, v8);
  v10 = get_Ctrl();
  v11 = &StringLiteral_4870;
  if (!v5)
    v11 = &StringLiteral_4868;
  UnloadAB(v10, *v11);
}

// 0x1146710
void RemoveDLC(char *key) {
  UnityEngine_GameObject_o *v3;
  s32 Bit;
  AssetBundleCtrl_o *Ctrl;
  u64 v11;
  AssetBundleCtrl_o *v14;
  struct System_String_array *attempt;
  AssetBundleCtrl_o *v16;
  System_String_o *v18;
  System_String_o *v19;
  struct System_String_array *v20;
  System_String_o *v23;
  AssetBundleCtrl_o *v24;

  v3 = Find(StringLiteral_4905, 0);
  get_transform(v3, 0);
  Bit = cfgGetBit(5u);
  Ctrl = get_Ctrl();
  UnloadAB(Ctrl, key);
  v11 = 0;
  do
  {
    else
    {
      if (!check_owner(0, Bit))
    }
    if ((byte_3F58BA9 & 1) == 0)
    v14 = get_Ctrl();
    v16 = v14;
    v18 = Concat_5224608(StringLiteral_4901, attempt->m_Items[v11]);
    UnloadAB(v16, v18);
    ++v11;
  }
  while (v11 != 5);
  {
    v19 = key;
  }
  else
  {
    v19 = key;
  }
  v20 = attempt;
  v23 = Concat_5224608(v19, v20->m_Items[Bit]);
  v24 = get_Ctrl();
  UnloadAB(v24, v23);
  RemoveKeys(1, v19);
}

// 0x11458d0
bool ReplaceDLCName(char **key, char *name) {
  UnityEngine_GameObject_o *v5;
  System_String_o *v10;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 fieldOldID;
  u32 Bit;
  s32 v19;
  System_String_o *v22;
  struct System_String_array *attempt;

  v5 = Find(StringLiteral_4905, 0);
  get_transform(v5, 0);
  if (!_Contains(dlcreplist, name))
  {
    v10 = Concat_5224608(name, StringLiteral_4906);
    if (!_Contains(dlcreplist, v10))
      return 0;
  }
  fieldID = fldGb->fieldID;
  fieldOldID = fldGb->fieldOldID;
  if (fieldID < 128)
    fieldOldID = fieldID;
  if ((fieldOldID - 10) >= 0x34)
  {
    Bit = cfgGetBit(5u);
    if (Bit <= 4)
    {
      v19 = Bit;
      if (check_owner(0, v19))
      {
        v22 = *key;
        *key = Concat_5224608(v22, attempt->m_Items[v19]);
      }
    }
  }
  return 1;
}

// 0x1146a50
void RequestReload(s32 old) {
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 fieldOldID;
  System_String_o *v11;
  struct System_String_array *attempt;
  System_String_o *v15;
  AssetBundleCtrl_o *Ctrl;
  s32 Bit;
  System_String_o *v21;
  AssetBundleCtrl_o *v22;
  struct System_String_array *v23;
  System_String_o *v27;
  AssetBundleCtrl_o *v28;
  DlcFileCtr_o *dlc;
  s32 v30;
  AssetBundleCtrl_o *v32;

  else if (loadmode)
  {
    return;
  }
  else if (!check_owner(0, old))
  {
    return;
  }
  fieldID = fldGb->fieldID;
  fieldOldID = fldGb->fieldOldID;
  if (fieldID < 128)
    fieldOldID = fieldID;
  if ((fieldOldID - 11) >= 0x33)
  {
    v11 = StringLiteral_4901;
    v15 = Concat_5224608(v11, attempt->m_Items[old]);
    Ctrl = get_Ctrl();
    if (IsLoad(Ctrl, v15))
    {
      Bit = cfgGetBit(5u);
      loadmode = Bit + 4096;
      v21 = StringLiteral_4901;
      v22 = get_Ctrl();
      UnloadAB(v22, v15);
      v23 = attempt;
      v27 = Concat_5224608(v21, v23->m_Items[Bit]);
      if (!Bit)
      if (check_owner(0, Bit))
      {
        v28 = get_Ctrl();
        dlc = get_dlc(v28);
        if ((Bit - 1) > 3)
          v30 = -1;
        else
          v30 = dword_32C3BA0[Bit - 1];
        Load(dlc, v27, v30, v27, 0);
      }
      else
      {
        v32 = get_Ctrl();
        Load(v32, v27, v27, 0);
      }
    }
    else
    {
      IsBGMStopped();
    }
  }
}

// 0x1144fd0
void UnloadCollectionBook(void) {
  Remove(StringLiteral_4898, 0);
  Remove(StringLiteral_4899, 0);
}
