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
    GlobalData_ResultData *stage_data;
    GlobalData_PadConfig *padconfig;
};

struct GlobalData_ResultData {
    u8 *Mission;
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
    u8 *pad;
};

static dds3DefaultMain *kernelObject;
static FsSaveData *saveData;
static s32 screen_wid;
static s32 screen_hei;
static s32 STAGEMAX;
static s32 SAVEDATA_VER;
static void *world_font;
static s16 CONTROLER_TYPE_KEYBOAD;
static s16 CONTROLER_TYPE_GAMEPAD;
static GlobalData_SaveData system_save;
static bool logoSkip;
static bool absorbSE;
static TextManager *txtMgr;
static GfxManager *gfxMgr;
static void *DebugObject;
static s32 loadmode;
static u8 *dante_pb;
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
  UnityEngine_GameObject_o *v5;
  u32 Bit;
  s32 v10;
  System_String_o *v12;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 fieldOldID;
  struct System_String_array *attempt;
  s32 IndexOf_5262640;
  System_String_o *v25;
  System_String_o *v26;
  System_String_o *v27;
  struct System_String_array *v30;
  System_String_o *v32;
  u16 Chars;

  Chars = 0;
  v5 = Find("Canvas_UI", 0);
  get_transform(v5, 0);
  Bit = cfgGetBit(5u);
  if (Bit <= 4)
  {
    v10 = Bit;
    if (check_owner(0, v10))
    {
      v12 = Concat_5224608(name, "_L_");
      if (_Contains(dlcreplist, name))
      {
        goto LABEL_24;
      }
      if (_Contains(dlcreplist, v12))
      {
LABEL_24:
        fieldID = fldGb->fieldID;
        fieldOldID = fldGb->fieldOldID;
        if (fieldID < 128)
          fieldOldID = fieldID;
        if ((fieldOldID - 11) >= 0x33)
        {
          if (append)
          {
            return Concat_5224608(name, attempt->m_Items[v10]);
          }
          IndexOf_5262640 = LastIndexOf_5262640(name, "_L_");
          v25 = name;
          if (IndexOf_5262640 != -1)
            v25 = Substring_5248048(name, 0, IndexOf_5262640);
          Chars = get_Chars(v25, 0);
          v26 = sub_3C3A80(&Chars, 0);
          v27 = ToUpper(v26, 0);
          if (Equals_5234480(v27, "B")
            || Equals_5234480(v27, "F"))
          {
            v30 = attempt;
            v32 = ToUpper(v30->m_Items[v10], 0);
            return Concat_5221536(v25, v32, "_L_");
          }
        }
      }
    }
  }
  return name;
}

// 0x1144d70
bool CheckDLCKey(char *key) {
  s32 Length;
  System_String_o *v4;
  System_String_o *v5;
  System_String_o *v6;
  System_String_o *v7;
  bool v8;
  u16 Chars;

  Length = get_Length(key);
  Chars = get_Chars(key, Length - 1);
  v4 = sub_3C3A80(&Chars, 0);
  v5 = ToUpper(v4, 0);
  v8 = op_Equality(v5, "M", 0)
    || (v6 = Substring_5248048(key, 0, 4),
        v7 = ToUpper(v6, 0),
        op_Equality(v7, "E815", 0))
    || op_Equality(key, "E060", 0)
    || op_Equality(key, "F060", 0)
    || op_Equality(v7, "E816", 0)
    || op_Equality(key, "E061", 0)
    || op_Equality(key, "F061", 0);
  return v8;
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

LABEL_7:
  else
  {
    v3 = dds3CheckDLC6();
    if (area != 60)
      goto LABEL_15;
  }
  if (v3)
    return 15;
LABEL_15:
LABEL_19:
  if (((area == 61) & dds3CheckDLC7()) != 0)
    return 16;
  else
    return area;
}

// 0x11478f0
s32 DLCGetFieldCheck(s32 no) {
  bool v3;
  bool v6;

LABEL_7:
  else
  {
    v3 = dds3CheckDLC6();
    if (no != 15)
      goto LABEL_15;
  }
  if (v3)
  {
    if (fldGb->fieldID != 15)
      return 60;
  }
LABEL_15:
LABEL_19:
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

LABEL_7:
  else
  {
    v3 = dds3CheckDLC6();
    if (no != 32)
      goto LABEL_15;
  }
  if (v3)
    return 60;
LABEL_15:
LABEL_19:
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
    return "e015";
  if (no == 61)
    return "e016";
  return key;
}

// 0x11473e0
char *DLCGetTerminalName(s32 no) {
  System_String_o *LocalizeText;
  bool v4;
  bool v9;

  LocalizeText = "";
LABEL_7:
  v4 = dds3CheckDLC6();
  if (no == 32 && v4)
  {
    else if ((byte_3F58BA1 & 1) != 0)
    {
      goto LABEL_16;
    }
    goto LABEL_16;
  }
LABEL_20:
LABEL_24:
  v9 = dds3CheckDLC7();
  if (no == 33 && v9)
  {
    else if ((byte_3F58BA1 & 1) != 0)
    {
      goto LABEL_33;
    }
    goto LABEL_33;
  }
  return LocalizeText;
}

// 0x11471e0
void DLCTerminalList(fclDataTerminal_t **term) {
  fclDataTerminal_t_o *v4;
  u32 TerminalCnt;
  struct System_SByte_array *TerminalList;
  fclDataTerminal_t_o *v9;
  u32 v10;
  struct System_SByte_array *v11;

LABEL_7:
  else if (!dds3CheckDLC6())
  {
    goto LABEL_18;
  }
  v4 = *term;
  if ((*term)->TerminalNo != 32)
  {
    TerminalCnt = v4->TerminalCnt;
    TerminalList = v4->TerminalList;
    ++v4->TerminalCnt;
    TerminalList->m_Items[TerminalCnt] = 32;
      goto LABEL_20;
    goto LABEL_19;
  }
LABEL_18:
    goto LABEL_20;
LABEL_19:
LABEL_20:
LABEL_22:
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
  u64 *v5;
  System_String_o *v7;
  bool IsDLCField;
  s64 *v9;
  s32 v11;

  v11 = field;
  v5 = sub_8D3950(s32, &v11);
  v7 = Format(fmt, v5, 0);
  IsDLCField = IsDLCField(field);
  v9 = &"m";
  if (!IsDLCField)
    v9 = &"";
  return Concat_5224608(v7, *v9);
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
  System_Collections_Generic_List_mdlEffectResrcItem_t__o *dlcreplist;
  u64 *v6;
  System_String_o *v7;
  System_Collections_Generic_List_mdlEffectResrcItem_t__o *v10;
  u64 *v11;
  System_String_o *v12;
  System_Collections_Generic_List_mdlEffectResrcItem_t__o *v15;
  u64 *v16;
  System_String_o *v17;
  System_Collections_Generic_List_mdlEffectResrcItem_t__o *v20;
  u64 *v21;
  System_String_o *v22;
  System_Collections_Generic_List_mdlEffectResrcItem_t__o *v25;
  u64 *v26;
  System_String_o *v27;
  System_Collections_Generic_List_mdlEffectResrcItem_t__o *v30;
  u64 *v31;
  System_String_o *v32;
  System_Collections_Generic_List_mdlEffectResrcItem_t__o *v35;
  u64 *v36;
  System_String_o *v37;
  System_Collections_Generic_List_mdlEffectResrcItem_t__o *v40;
  u64 *v41;
  System_String_o *v42;
  s32 v45;

  _Clear(dlcreplist);
  _Add(dlcreplist, "b_bgm01");
  _Add(dlcreplist, "fldbgm");
  v45 = 1;
  v6 = sub_8D3950(s32, &v45);
  v7 = Format("B0500_B050{0}_BGM01_L_", v6, 0);
  _Add(dlcreplist, v7);
  v10 = dlcreplist;
  v45 = 2;
  v11 = sub_8D3950(s32, &v45);
  v12 = Format("B0500_B050{0}_BGM01_L_", v11, 0);
  _Add(v10, v12);
  v15 = dlcreplist;
  v45 = 3;
  v16 = sub_8D3950(s32, &v45);
  v17 = Format("B0500_B050{0}_BGM01_L_", v16, 0);
  _Add(v15, v17);
  v20 = dlcreplist;
  v45 = 4;
  v21 = sub_8D3950(s32, &v45);
  v22 = Format("B0500_B050{0}_BGM01_L_", v21, 0);
  _Add(v20, v22);
  v25 = dlcreplist;
  v45 = 5;
  v26 = sub_8D3950(s32, &v45);
  v27 = Format("B0500_B050{0}_BGM01_L_", v26, 0);
  _Add(v25, v27);
  v30 = dlcreplist;
  v45 = 6;
  v31 = sub_8D3950(s32, &v45);
  v32 = Format("B0500_B050{0}_BGM01_L_", v31, 0);
  _Add(v30, v32);
  v35 = dlcreplist;
  v45 = 7;
  v36 = sub_8D3950(s32, &v45);
  v37 = Format("B0500_B050{0}_BGM01_L_", v36, 0);
  _Add(v35, v37);
  v40 = dlcreplist;
  v45 = 8;
  v41 = sub_8D3950(s32, &v45);
  v42 = Format("B0500_B050{0}_BGM01_L_", v41, 0);
  _Add(v40, v42);
  _Add(dlcreplist, "F002_01_L_");
  _Add(dlcreplist, "F007_01_L_");
}

// 0x1147cd0
bool IsDLCField(s32 area) {
  bool v3;

LABEL_7:
  else
  {
    v3 = dds3CheckDLC6();
    if (area != 60)
      goto LABEL_15;
  }
  if (v3)
    return 1;
LABEL_15:
LABEL_19:
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
  s32 loadmode;
  struct System_String_array *attempt;
  s64 v5;
  u64 *v11;
  Il2CppObject *v13;
  bool v18;
  s32 v20;

  else
  {
    if (!loadmode)
      return 1;
  }
  else
  {
    LODWORD(attempt) = loadmode >> 12;
    v5 = loadmode & 0xFFF;
    if (attempt != 3)
    {
LABEL_9:
      if (attempt != 2)
      {
        if (attempt == 1)
        {
          StopBGMALL_Compulsion(1);
          LOBYTE(attempt) = 2;
            goto LABEL_55;
          goto LABEL_53;
        }
        goto LABEL_52;
      }
      else if (IsBGMStopped())
      {
LABEL_21:
        {
        }
        RemoveKeys(1, "fldbgm");
        Concat_5224608("fldbgm", attempt->m_Items[v5]);
        LOBYTE(attempt) = 3;
          goto LABEL_55;
        goto LABEL_53;
      }
      LOBYTE(attempt) = 2;
LABEL_52:
      {
LABEL_55:
        v18 = 0;
        loadmode = v5 & 0xFFFF0FFF | ((attempt & 0xF) << 12);
        return v18;
      }
LABEL_53:
      goto LABEL_55;
    }
  }
  LOBYTE(attempt) = 3;
  if (!IsFieldBGMLoaded("fldbgm"))
    goto LABEL_52;
  v20 = 3;
  v11 = sub_8D3950(s32, &v20);
  v13 = Concat("Step = ", v11);
  Log(v13, 0);
  LoadKeys(1, "fldbgm", 0);
  fldBgmPlay();
  loadmode = 0;
  return 1;
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
    && op_Inequality(v7, "e815", 0)
    && op_Inequality(v7, "e816", 0)
    && op_Inequality(v7, "e060", 0)
    && op_Inequality(v7, "e061", 0)
    && op_Inequality(v7, "f060", 0)
    && op_Inequality(v7, "f061", 0))
  {
    goto LABEL_25;
  }
  Appendix = GetAppendix();
  v10 = Concat_5224608("e715", Appendix);
  v11 = GetAppendix();
  v12 = Concat_5224608("e714", v11);
  if (op_Equality(key, "e714", 0)
    || op_Equality(key, v12, 0)
    || op_Equality(key, "e715", 0)
    || op_Equality(key, v10, 0)
    || op_Equality(key, "e723", 0)
    || op_Equality(key, "e728", 0)
    || op_Equality(key, "e729", 0)
    || op_Equality(key, "e730", 0)
    || op_Equality(key, "e731", 0))
  {
LABEL_25:
    else if ((byte_3F58BA9 & 1) != 0)
    {
LABEL_28:
      Ctrl = get_Ctrl();
      Load(Ctrl, key, name, 0);
      return;
    }
    goto LABEL_28;
  }
  if (op_Equality(v7, "e815", 0)
    || op_Equality(v7, "e060", 0)
    || op_Equality(v7, "f060", 0))
  {
    v14 = 6;
  }
  else
  {
    v14 = 2;
  }
  if (op_Equality(v7, "e816", 0)
    || op_Equality(v7, "e061", 0)
    || op_Equality(v7, "f061", 0))
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
      v18 = Format_5268784("b_bgm01", v17);
      appended = AppendDLC(v18, 1);
      Ctrl = get_Ctrl();
      if (!IsLoad(Ctrl, appended))
      {
        v24 = get_Ctrl();
        dlc = get_dlc(v24);
        Load(dlc, appended, v8, appended, 0);
      }
      goto LABEL_46;
    case 2:
      v9 = Empty_string_();
      v12 = Format_5268784("b_bgm01", v9);
      v14 = AppendDLC(v12, 1);
      v15 = get_Ctrl();
      if (!IsLoad(v15, v14))
        goto LABEL_27;
      LoadKeys(1, "b_bgm01", 0);
LABEL_46:
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
LABEL_27:
      result = 0;
      break;
  }
  return result;
}

// 0x1144f40
void LoadCollectionBook(void) {
  LoadLocalizeText("e800", "COLLECTIONBOOK");
  LoadLocalizeText("e800", "COLLECTIONBOOK_M");
}

// 0x1146020
void LoadField(s32 fld) {
  u64 *v3;
  System_String_o *v5;
  AssetBundleCtrl_o *Ctrl;
  DlcFileCtr_o *dlc;
  System_String_o *v9;
  System_String_o *v10;
  DlcFileCtr_o *v11;
  System_String_o *v12;
  s32 v13;
  AssetBundleCtrl_o *v14;
  AssetBundleCtrl_o *v15;
  AssetBundleCtrl_o *v16;
  s32 v17;

  v17 = fld;
  v3 = sub_8D3950(s32, &v17);
  v5 = Format("f{0:D3}", v3, 0);
  if (IsDLCField(fld))
  {
    Ctrl = get_Ctrl();
    dlc = get_dlc(Ctrl);
    v9 = Concat_5224608(v5, "m");
    v10 = Concat_5224608(v5, "m");
    v11 = dlc;
    v12 = v9;
    v13 = 2;
    goto LABEL_37;
  }
  if (fld == 61)
  {
    v15 = get_Ctrl();
    v11 = get_dlc(v15);
    v12 = v5;
    v13 = 7;
    goto LABEL_36;
  }
  if (fld == 60)
  {
    v14 = get_Ctrl();
    v11 = get_dlc(v14);
    v12 = v5;
    v13 = 6;
LABEL_36:
    v10 = v5;
LABEL_37:
    Load(v11, v12, v13, v10, 0);
    return;
  }
  v16 = get_Ctrl();
  Load(v16, v5, v5, 0);
}

// 0x1145af0
void LoadFieldBGM(char *key) {
  System_String_o *appended;
  s32 Bit;
  s32 v9;
  AssetBundleCtrl_o *v14;

  appended = AppendDLC(key, 1);
  else
  {
    Bit = cfgGetBit(5u);
    if (!Bit)
      goto LABEL_27;
  }
  v9 = Bit;
  else if (check_owner(0, Bit))
  {
    goto LABEL_12;
  }
LABEL_27:
  v14 = get_Ctrl();
  Load(v14, key, key, 0);
}

// 0x11435d0
s32 LoadManiacsChar(bool mode, s32 phase) {
  System_Object_array *v4;
  s64 *v6;
  s64 *v7;
  s64 *v10;
  s64 *v11;
  System_String_o *v14;
  System_Object_array *v16;
  s64 *v18;
  System_String_o *v19;
  AssetBundleCtrl_o *Ctrl;
  AssetBundleCtrl_o *v21;
  AssetBundleCtrl_o *v23;
  AssetBundleCtrl_o *v25;
  DlcFileCtr_o *dlc;
  System_String_o *v27;
  System_String_o *v28;
  s64 *v29;
  System_String_o *v30;
  AssetBundleCtrl_o *v31;
  s64 *v33;
  System_String_o *v34;
  AssetBundleCtrl_o *v35;
  AssetBundleCtrl_o *v37;
  AssetBundleCtrl_o *v43;
  AssetBundleCtrl_o *v45;
  AssetBundleCtrl_o *v47;
  DlcFileCtr_o *v48;
  AssetBundleCtrl_o *v49;
  AssetBundleCtrl_o *v50;
  System_String_o *v51;
  System_String_o *v52;
  s32 v54;
  bool v55[4];

  v55[0] = mode;
  v4 = NewSpecific(object, 5u);
  v4->m_Items[0] = "@@@@@ LoadManiachsChar : ";
  v6 = sub_3C0020(v55);
  v7 = v6;
  v4->m_Items[1] = v7;
  v4->m_Items[2] = ",";
  v54 = phase;
  v10 = sub_8D3950(s32, &v54);
  v11 = v10;
  v4->m_Items[3] = v11;
  v4->m_Items[4] = " @@@@@";
  v14 = Concat_5270224(v4);
  v16 = Empty_string_();
  Log(v14, v16, 0);
  if (phase)
  {
    if (phase != 1)
    {
      if (phase == 2)
      {
        if (v55[0])
          v18 = &"extram";
        else
          v18 = &"extrar";
        v19 = *v18;
        Ctrl = get_Ctrl();
        if (IsLoad(Ctrl, v19))
          phase = 3;
        else
          phase = 2;
      }
      return phase + 3;
    }
    if (v55[0])
      v29 = &"dvl0xc0d";
    else
      v29 = &"dvl0xc0r";
    v30 = *v29;
    v31 = get_Ctrl();
    if (!IsLoad(v31, v30))
    {
      phase = 1;
      return phase + 3;
    }
    v33 = &"extrar";
    if (v55[0])
      v33 = &"extram";
    v34 = *v33;
    v35 = get_Ctrl();
    if (!IsLoad(v35, v34))
    {
      if (v55[0])
      {
        v37 = get_Ctrl();
        dlc = get_dlc(v37);
        phase = 2;
        v27 = v34;
        v28 = v34;
LABEL_104:
        Load(dlc, v27, 2, v28, 0);
        return phase + 3;
      }
      v50 = get_Ctrl();
      v51 = v34;
      v52 = v34;
LABEL_166:
      Load(v50, v51, v52, 0);
      phase = 2;
      return phase + 3;
    }
    goto LABEL_129;
  }
  if (v55[0])
  {
    v21 = get_Ctrl();
    if (IsLoad(v21, "dvl0xc0d"))
    {
      v23 = get_Ctrl();
      if (!IsLoad(v23, "extram"))
      {
        v25 = get_Ctrl();
        dlc = get_dlc(v25);
        v27 = "extram";
        phase = 2;
        v28 = "extram";
        goto LABEL_104;
      }
      goto LABEL_129;
    }
    v47 = get_Ctrl();
    v48 = get_dlc(v47);
    Load(v48, "dvl0xc0d", 2, "dvl0xc0d", 0);
    phase = 1;
  }
  else
  {
    v43 = get_Ctrl();
    if (IsLoad(v43, "dvl0xc0r"))
    {
      v45 = get_Ctrl();
      if (!IsLoad(v45, "extrar"))
      {
        v50 = get_Ctrl();
        v51 = "extrar";
        v52 = "extrar";
        goto LABEL_166;
      }
LABEL_129:
      phase = 3;
      return phase + 3;
    }
    v49 = get_Ctrl();
    Load(v49, "dvl0xc0r", "dvl0xc0r", 0);
    phase = 1;
  }
  return phase + 3;
}

// 0x1143f20
void *LoadManiacsChar_18104096(s32 *phase) {
  bool IsDLC;
  bool v4;
  u64 *v5;
  System_String_o *v6;
  System_Object_array *v8;
  Il2CppObject *v11;
  AssetBundleCtrl_o *Ctrl;
  s64 *v13;
  AssetBundleCtrl_o *v15;
  s64 *v16;
  System_String_o *v17;
  System_String_o *PBname;
  u64 *v21;
  System_String_o *v22;
  System_Object_array *v24;
  s64 *v25;
  s64 *v26;
  s64 *v27;
  AssetBundleCtrl_o *v28;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v30;
  UnityEngine_Transform_o *transform;
  System_String_o *v33;
  System_Object_array *v35;
  UnityEngine_Component_o *Animator;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *v40;
  System_String_o *name;
  AssetBundleCtrl_o *v44;
  System_String_o *v45;
  evtUnitHandle_t_o *UnitHandleObjectBasic;
  System_Object_array *v51;
  System_String_o **v53;
  s32 v54;
  s32 v55;

  IsDLC = IsDLC();
  v55 = *phase;
  v4 = IsDLC;
  v5 = sub_8D3950(s32, &v55);
  v6 = Concat_5269984("@@@@@ LoadManiachsChar2 ", v5, " @@@@@");
  v8 = Empty_string_();
  Log(v6, v8, 0);
  if (IsfldSetChar("DANTE_UNIT"))
  {
    return fldGetCharObj("DANTE_UNIT");
  }
  else
  {
    if (v4)
    {
      Ctrl = get_Ctrl();
      v13 = &"dvl0xc0d";
    }
    else
    {
      Ctrl = get_Ctrl();
      v13 = &"dvl0xc0r";
    }
    v11 = 0;
    if (IsLoad(Ctrl, *v13))
    {
      v15 = get_Ctrl();
      v16 = &"r";
      if (v4)
        v16 = &"m";
      v53 = v16;
      v17 = Concat_5224608("extra", *v16);
      if (IsLoad(v15, v17))
      {
        GetAkey(192);
        PBname = GetPBname(192);
        Concat_5221536("dds3data/dvl_pb/", PBname, ".bytes");
        if (v4)
        {
          v25 = &"devil_field";
          v26 = &"charactor/f/dante";
          v27 = &"extram";
        }
        else
        {
          v25 = &"raidou_field";
          v26 = &"charactor/f/raidou";
          v27 = &"extrar";
        }
        v28 = get_Ctrl();
        Prefab_16624656 = LoadPrefab_16624656(v28, *v27, *v26, *v25);
        v30 = Find("Character", 0);
        transform = get_transform(v30, 0);
        v11 = Instantiate_object__425664(Prefab_16624656, transform, 0);
        v33 = Concat_5269984("@@@@@ LoadManiachsChar2 : SetObject ", v11, " @@@@@");
        v35 = Empty_string_();
        Log(v33, v35, 0);
        set_name(v11, "DANTE_UNIT");
        Animator = GetAnimator(v11);
        gameObject = get_gameObject(Animator);
        Component_object = GetComponent_object_(gameObject);
        if (op_Equality(Component_object, 0, 0))
        {
          v40 = get_gameObject(Animator);
          AddComponent_object_(v40);
        }
        name = get_name(v11);
        fldSetCharAdd(name, v11);
        v44 = get_Ctrl();
        v45 = Concat_5224608("extra", *v53);
        UnloadAB(v44, v45);
        UnitHandleObjectBasic = dds3GetUnitHandleObjectBasic(&player3);
        mdlSetHD(v11, 2, UnitHandleObjectBasic, 15);
        SetDevilEffect(&player3, 192);
        UnitHandleObjectBasic->Model->modelRoot->modelobj = v11;
        v51 = Empty_string_();
        Log("@@@@@ LoadManiachsChar2 : Finished @@@@@", v51, 0);
        *phase = 0;
      }
      else
      {
        v54 = *phase;
        v21 = sub_8D3950(s32, &v54);
        v22 = Concat_5269984("@@@@@ LoadManiachsChar2 ", v21, " @@@@@");
        v24 = Empty_string_();
        Log(v22, v24, 0);
        return 0;
      }
    }
  }
  return v11;
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
  v4 = &"d";
  if (!IsDLC)
    v4 = &"r";
  v5 = IsDLC;
  v6 = *v4;
LABEL_12:
  Ctrl = get_Ctrl();
  v8 = Concat_5224608("dvl0xc0", v6);
  UnloadAB(Ctrl, v8);
  v10 = get_Ctrl();
  v11 = &"extram";
  if (!v5)
    v11 = &"extrar";
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

  v3 = Find("Canvas_UI", 0);
  get_transform(v3, 0);
  Bit = cfgGetBit(5u);
LABEL_10:
  Ctrl = get_Ctrl();
  UnloadAB(Ctrl, key);
  v11 = 0;
  do
  {
    else
    {
      if (!check_owner(0, Bit))
        goto LABEL_31;
    }
    if ((byte_3F58BA9 & 1) == 0)
      goto LABEL_24;
LABEL_25:
    v14 = get_Ctrl();
    v16 = v14;
    v18 = Concat_5224608("fldbgm", attempt->m_Items[v11]);
    UnloadAB(v16, v18);
LABEL_31:
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

  v5 = Find("Canvas_UI", 0);
  get_transform(v5, 0);
  if (!_Contains(dlcreplist, name))
  {
    v10 = Concat_5224608(name, "_L_");
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
    v11 = "fldbgm";
    v15 = Concat_5224608(v11, attempt->m_Items[old]);
    Ctrl = get_Ctrl();
    if (IsLoad(Ctrl, v15))
    {
      Bit = cfgGetBit(5u);
      loadmode = Bit + 4096;
      v21 = "fldbgm";
      v22 = get_Ctrl();
      UnloadAB(v22, v15);
      v23 = attempt;
      v27 = Concat_5224608(v21, v23->m_Items[Bit]);
      if (!Bit)
        goto LABEL_75;
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
LABEL_75:
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
  Remove("COLLECTIONBOOK", 0);
  Remove("COLLECTIONBOOK_M", 0);
}
