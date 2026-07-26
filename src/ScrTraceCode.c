#include "types.h"

typedef struct AnimChecker AnimChecker;
typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct FieldBgHD FieldBgHD;
typedef struct FieldChrHD FieldChrHD;
typedef struct GunHD GunHD;
typedef struct ScrTraceCode_LOADTYPE ScrTraceCode_LOADTYPE;
typedef struct ScrTraceCode_LoadTypeList ScrTraceCode_LoadTypeList;
typedef struct Scr_AnonymousClass Scr_AnonymousClass;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelFileTable_t dds3ModelFileTable_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct mdlEffectResrcList_t mdlEffectResrcList_t;
typedef struct scrProcessWork_s scrProcessWork_s;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;

struct ScrTraceCode_LoadTypeList {
    s32 type;
    dds3Basic_t *basic;
    char *key;
    char *dvlkey;
    s32 major;
    s32 minor;
    char *name;
    void *obj;
};

struct ScrTraceCode_LOADTYPE {
    s32 value__;
};

static scrProcessWork_s *nowpwork;
static scrProcessWork_s *scrHandle_t;
static s32 LoadCount;
static s32 CodeFunc_2Operation_i1;
static s32 CodeFunc_2Operation_i2;
static s32 CodeFunc_2Operation_ri;
static f32 CodeFunc_2Operation_f1;
static f32 CodeFunc_2Operation_f2;
static f32 CodeFunc_2Operation_rf;
static s32 CodeFunc_2Operation_t1;
static s32 CodeFunc_2Operation_t2;
static Scr_AnonymousClass *codefunc[35];
static s32 eventcnt;
static void *LoadPacket;
static ScrTraceCode_LoadTypeList *UnloadPacket[50];
static s32 LoadFlag;
static void HoleEff[UNKNOWN_ARRAY_SIZE];

void AttachHD(void *obj, dds3Basic_t *basic, char *name, s32 cb);
void CodeFunc_2Operation(scrProcessWork_s *pwork, s32 type);
char *GetAkey(s32 no);
void *GetAnimator(void *obj);
char *GetPBname(s32 no);
bool IsPaused(void);
void Load(char *key, char *filePath);
void *LoadFile(AssetBundleCtrl *this, char *key, char *path, char *name, char *extension);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void LoadKeys(s32 type, char *key, char *path);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Log(char *fmt, void **parray);
f32 PopFloat(scrProcessWork_s *pwork);
s32 PopInt(scrProcessWork_s *pwork);
FieldChrHD *PriChrHDGet(void *obj);
void RemoveKeys(s32 type, char *key);
char *ReplaceDvlKeyName(char *dvl, s32 *minor);
void SetCharacterType(AnimChecker *this, s32 type);
void SetDevilEffect(dds3Basic_t **bas, s32 id);
void SetEveUnit(GunHD *this, evtUnitHandle_t *hunit_tmp);
void SetMajinHoleEffect(dds3Basic_t **bas);
void SetShinenEffect(dds3Basic_t **bas, s32 id);
void UnloadAB(AssetBundleCtrl *this, char *key);
void UpdateDying(void *plyobj);
void billSetTexture(void **pTexture);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
dds3Basic_t *dds3GetControlScene(void);
dds3Basic_t *dds3SceneBasicSearchNameAndType(dds3Basic_t *scene, u32 type, char *name);
void evtUpdateEx_CharLoadAfter(FieldChrHD *fHD, void *rootobj, dds3Basic_t *unit, char *mname);
void evtUpdateEx_FieldLoadAfter(FieldBgHD *fobj, void *rootobj, char *mname);
void fldSetCharAdd(char *name, void *obj);
void mdlCreateEffectResrc_D3P(mdlEffectResrcList_t **listPtr, void *data, void **pTexture);
void mdlEffectCreateUnity(s32 aMajor, s32 aMinor, mdlEffectResrcList_t **efc_res_list, bool loadf);
bool mdlGenEffect(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aPlayGroup);
FieldChrHD *mdlSetHD(void *obj, s32 mode, evtUnitHandle_t *hunit, s32 layer);
void mdlSmoothLoopMotionForUnity(evtUnitHandle_t **h, s32 layer, s32 motion, s32 before, s32 wait, bool btl);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);
sdfModelRootNode_t *sdfModelMakeUnity(sdfModelTexList_t *aTexList, u8 **bData, s32 bPos);

// 0x1d0070
void AddLoad(dds3Basic_t *basic, char *key, s32 major, s32 minor, char *name, void *obj, s32 type, char *dvl) {
  System_Object_array *v18;
  u64 *v19;
  System_String_o *v24;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v28;
  DlcFileCtr_o *dlc;
  AssetBundleCtrl_o *v30;

  v18 = Empty_string_();
  Log(StringLiteral_8892, v18, 0);
  v19 = Allocate(ScrTraceCode_LoadTypeList);
  _ctor(v19, 0);
  *(v19 + 4) = type;
  *(v19 + 12) = major;
  v19[3] = basic;
  v19[4] = key;
  *(v19 + 13) = minor;
  v19[7] = name;
  v19[8] = obj;
  _Add(LoadPacket, v19);
  ++LoadFlag;
  if (IsNullOrEmpty(dvl))
  {
    v19[5] = 0;
  }
  else
  {
    v24 = ReplaceDvlKeyName(dvl, v19 + 13);
    v19[5] = v24;
    if (!IsNullOrEmpty(v24))
    {
      asset_bc = get_asset_bc();
      Load(asset_bc, v19[5], v19[5], 0);
    }
  }
  if (Equals_5234480(v19[4], StringLiteral_4870))
  {
    v28 = get_asset_bc();
    dlc = get_dlc(v28);
    Load(dlc, key, 2, key, 0);
  }
  else
  {
    v30 = get_asset_bc();
    Load(v30, key, key, 0);
  }
}

// 0x1cd7f0
char *AddModel(dds3Basic_t *basic, void *obj, s32 major, s32 minor) {
    Log(0, 0);
    LoadPrefab_16624656(0, 0, 0, 0);
    AttachHD(0, 0, 0, 0);
    LoadKeys(0, 0, 0);
    SetDevilEffect(0, 0);
    SetMajinHoleEffect(0);
    SetShinenEffect(0, 0);
    dds3GetBaseControlWorkData(0);
    GetAnimator(0);
    SetCharacterType(0, 0);
    UpdateDying(0);
    mdlSmoothLoopMotionForUnity(0, 0, 0, 0, 0, 0);
    fldSetCharAdd(0, 0);
    return 0;
}

// 0x1ce380
void AttachHD(void *obj, dds3Basic_t *basic, char *name, s32 cb) {
    evtUpdateEx_FieldLoadAfter(0, 0, 0);
    PriChrHDGet(0);
    SetEveUnit(0, 0);
    mdlSetHD(0, 0, 0, 0);
    evtUpdateEx_CharLoadAfter(0, 0, 0, 0);
}

// 0x1ca920
void CodeFunc_2Operation(scrProcessWork_s *pwork, s32 type) {
    PopInt(0);
    PopFloat(0);
}

// 0x1cb2e0
s32 CodeFunc_Add(scrProcessWork_s *pwork) {
  CodeFunc_2Operation(pwork, 0);
  ++pwork->CP;
  return 1;
}

// 0x1cbc40
s32 CodeFunc_And(scrProcessWork_s *pwork) {
  CodeFunc_2Operation(pwork, 5);
  ++pwork->CP;
  return 1;
}

// 0x1ca670
s32 CodeFunc_Call(scrProcessWork_s *pwork) {
  s32 CP;
  struct System_Byte_array *StackType;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v8;
  struct scrCode_t_array *Code;
  s32 v11;
  struct scrProcTable_t_array *ProcTable;
  s64 v14;

  CP = pwork->CP;
  StackType = pwork->StackType;
  SP = pwork->SP;
  StackType->m_Items[SP] = 4;
  StackData = pwork->StackData;
  v8 = pwork->SP;
  *(&StackData->m_Items[0].i + v8) = CP;
  Code = pwork->Code;
  v11 = pwork->CP;
  ++pwork->SP;
  ProcTable = pwork->ProcTable;
  v14 = *(&Code->m_Items[0].i + 2 * v11 + 1);
  pwork->CP = ProcTable->m_Items[v14].CodeAddress;
  return 1;
}

// 0x1ca3d0
s32 CodeFunc_Comm(scrProcessWork_s *pwork) {
  struct scrCode_t_array *Code;
  s32 CP;
  s64 v6;
  struct scrCommandTable_t_array *scrCommandTable;
  s32 SP;
  struct scrCommandTable_t_array *v14;

  Code = pwork->Code;
  CP = pwork->CP;
  v6 = *(&Code->m_Items[0].i + 2 * CP + 1);
  nowpwork = pwork;
  if (!scrCommandTable_t_funcDelegate__Invoke(scrCommandTable->m_Items[v6].comm))
    return 2;
  SP = pwork->SP;
  v14 = scrCommandTable;
  pwork->SP = SP - v14->m_Items[v6].paranum;
  if (CP == pwork->CP)
    pwork->CP = CP + 1;
  return 1;
}

// 0x1cb460
s32 CodeFunc_Div(scrProcessWork_s *pwork) {
  CodeFunc_2Operation(pwork, 3);
  ++pwork->CP;
  return 1;
}

// 0x1cbcc0
s32 CodeFunc_EQ(scrProcessWork_s *pwork) {
  CodeFunc_2Operation(pwork, 6);
  ++pwork->CP;
  return 1;
}

// 0x1ca550
s32 CodeFunc_End(scrProcessWork_s *pwork) {
  if (!pwork->SP)
    return 0;
  pwork->CP = PopInt(pwork) + 1;
  return 1;
}

// 0x1ca8a0
s32 CodeFunc_Goto(scrProcessWork_s *pwork) {
  struct scrLabelTable_t_array *LabelTable;
  struct scrCode_t_array *Code;
  s64 CP;
  s64 v6;

  LabelTable = pwork->LabelTable;
  Code = pwork->Code;
  CP = pwork->CP;
  v6 = *(&Code->m_Items[0].i + 2 * CP + 1);
  pwork->CP = LabelTable->m_Items[v6].CodeAddress;
  return 1;
}

// 0x1cbfc0
s32 CodeFunc_IF(scrProcessWork_s *pwork) {
  struct System_Byte_array *StackType;
  s64 v4;
  s64 v6;
  System_String_o *v7;
  System_Object_array *v9;
  struct scrLabelTable_t_array *LabelTable;
  struct scrCode_t_array *Code;
  s64 CP;
  s64 v14;

  StackType = pwork->StackType;
  v4 = pwork->SP - 1LL;
  v6 = StackType->m_Items[v4];
  if (v6 <= 4)
    __asm { BR              X10 }
  v7 = StringLiteral_8879;
  v9 = Empty_string_();
  Log(v7, v9, 0);
  LabelTable = pwork->LabelTable;
  Code = pwork->Code;
  CP = pwork->CP;
  v14 = *(&Code->m_Items[0].i + 2 * CP + 1);
  pwork->CP = LabelTable->m_Items[v14].CodeAddress;
  return 1;
}

// 0x1ca5e0
s32 CodeFunc_Jump(scrProcessWork_s *pwork) {
  struct scrCode_t_array *Code;
  s64 CP;
  struct scrProcTable_t_array *ProcTable;
  s64 v6;

  Code = pwork->Code;
  CP = pwork->CP;
  ProcTable = pwork->ProcTable;
  v6 = *(&Code->m_Items[0].i + 2 * CP + 1);
  pwork->CP = ProcTable->m_Items[v6].CodeAddress;
  return 1;
}

// 0x1cbe40
s32 CodeFunc_L(scrProcessWork_s *pwork) {
  CodeFunc_2Operation(pwork, 9);
  ++pwork->CP;
  return 1;
}

// 0x1cbf40
s32 CodeFunc_LE(scrProcessWork_s *pwork) {
  CodeFunc_2Operation(pwork, 11);
  ++pwork->CP;
  return 1;
}

// 0x1cb4e0
s32 CodeFunc_Minus(scrProcessWork_s *pwork) {
  struct System_Byte_array *StackType;
  s64 v4;
  s64 v6;
  System_String_o *v7;
  System_Object_array *v9;

  StackType = pwork->StackType;
  v4 = pwork->SP - 1LL;
  v6 = StackType->m_Items[v4];
  if (v6 <= 4)
    __asm { BR              X10 }
  v7 = StringLiteral_8875;
  v9 = Empty_string_();
  Log(v7, v9, 0);
  ++pwork->CP;
  return 1;
}

// 0x1cb3e0
s32 CodeFunc_Mul(scrProcessWork_s *pwork) {
  CodeFunc_2Operation(pwork, 2);
  ++pwork->CP;
  return 1;
}

// 0x1cbd40
s32 CodeFunc_NEQ(scrProcessWork_s *pwork) {
  CodeFunc_2Operation(pwork, 7);
  ++pwork->CP;
  return 1;
}

// 0x1cb950
s32 CodeFunc_Not(scrProcessWork_s *pwork) {
  struct System_Byte_array *StackType;
  s64 v4;
  s64 v6;
  System_String_o *v7;
  System_Object_array *v9;

  StackType = pwork->StackType;
  v4 = pwork->SP - 1LL;
  v6 = StackType->m_Items[v4];
  if (v6 <= 4)
    __asm { BR              X10 }
  v7 = StringLiteral_8877;
  v9 = Empty_string_();
  Log(v7, v9, 0);
  ++pwork->CP;
  return 1;
}

// 0x1cbbc0
s32 CodeFunc_Or(scrProcessWork_s *pwork) {
  CodeFunc_2Operation(pwork, 4);
  ++pwork->CP;
  return 1;
}

// 0x1ca0c0
s32 CodeFunc_PopFX(scrProcessWork_s *pwork) {
  struct scrCode_t_array *Code;
  struct System_Single_array *FloatVariable;
  s64 CP;
  s64 v8;
  f32 v9;

  Code = pwork->Code;
  FloatVariable = DDS3_GBWK->FloatVariable;
  CP = pwork->CP;
  v8 = *(&Code->m_Items[0].i + 2 * CP + 1);
  v9 = PopFloat(pwork);
  FloatVariable->m_Items[v8] = v9;
  ++pwork->CP;
  return 1;
}

// 0x1c9fb0
s32 CodeFunc_PopIX(scrProcessWork_s *pwork) {
  struct scrCode_t_array *Code;
  struct System_Int32_array *IntVariable;
  s64 CP;
  s64 v8;
  s32 v9;

  Code = pwork->Code;
  IntVariable = DDS3_GBWK->IntVariable;
  CP = pwork->CP;
  v8 = *(&Code->m_Items[0].i + 2 * CP + 1);
  v9 = PopInt(pwork);
  IntVariable->m_Items[v8] = v9;
  ++pwork->CP;
  return 1;
}

// 0x1ca2c0
s32 CodeFunc_PopLFX(scrProcessWork_s *pwork) {
  struct System_Single_array *LocalFloat;
  struct scrCode_t_array *Code;
  s64 CP;
  s64 v7;
  f32 v8;

  LocalFloat = pwork->LocalFloat;
  if (!LocalFloat)
    return 0;
  Code = pwork->Code;
  CP = pwork->CP;
  v7 = *(&Code->m_Items[0].i + 2 * CP + 1);
  v8 = PopFloat(pwork);
  LocalFloat->m_Items[v7] = v8;
  ++pwork->CP;
  return 1;
}

// 0x1ca1d0
s32 CodeFunc_PopLIX(scrProcessWork_s *pwork) {
  struct System_UInt32_array *LocalInt;
  struct scrCode_t_array *Code;
  s64 CP;
  s64 v7;
  s32 v8;

  LocalInt = pwork->LocalInt;
  if (!LocalInt)
    return 0;
  Code = pwork->Code;
  CP = pwork->CP;
  v7 = *(&Code->m_Items[0].i + 2 * CP + 1);
  v8 = PopInt(pwork);
  LocalInt->m_Items[v7] = v8;
  ++pwork->CP;
  return 1;
}

// 0x1ca3b0
s32 CodeFunc_Proc(scrProcessWork_s *pwork) {
  ++pwork->CP;
  return 1;
}

// 0x1c97a0
s32 CodeFunc_PushF(scrProcessWork_s *pwork) {
  struct scrCode_t_array *Code;
  s64 v4;
  s32 v6;
  struct System_Byte_array *StackType;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v11;
  s32 v14;

  Code = pwork->Code;
  v4 = pwork->CP + 1LL;
  pwork->CP = v4;
  v6 = *(&Code->m_Items[0].i + v4);
  StackType = pwork->StackType;
  SP = pwork->SP;
  StackType->m_Items[SP] = 1;
  StackData = pwork->StackData;
  v11 = pwork->SP;
  *(&StackData->m_Items[0].i + v11) = v6;
  v14 = pwork->SP + 1;
  ++pwork->CP;
  pwork->SP = v14;
  return 1;
}

// 0x1c9a10
s32 CodeFunc_PushFX(scrProcessWork_s *pwork) {
  struct scrCode_t_array *Code;
  struct System_Single_array *FloatVariable;
  s64 CP;
  s64 v8;
  s32 v10;
  struct System_Byte_array *StackType;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v15;
  s32 v18;

  Code = pwork->Code;
  FloatVariable = DDS3_GBWK->FloatVariable;
  CP = pwork->CP;
  v8 = *(&Code->m_Items[0].i + 2 * CP + 1);
  v10 = LODWORD(FloatVariable->m_Items[v8]);
  StackType = pwork->StackType;
  SP = pwork->SP;
  StackType->m_Items[SP] = 1;
  StackData = pwork->StackData;
  v15 = pwork->SP;
  *(&StackData->m_Items[0].i + v15) = v10;
  v18 = pwork->SP + 1;
  ++pwork->CP;
  pwork->SP = v18;
  return 1;
}

// 0x1c9590
s32 CodeFunc_PushI(scrProcessWork_s *pwork) {
  struct scrCode_t_array *Code;
  s64 v4;
  s32 v6;
  struct System_Byte_array *StackType;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v11;
  s32 v14;

  Code = pwork->Code;
  v4 = pwork->CP + 1LL;
  pwork->CP = v4;
  v6 = *(&Code->m_Items[0].i + v4);
  StackType = pwork->StackType;
  SP = pwork->SP;
  StackType->m_Items[SP] = 0;
  StackData = pwork->StackData;
  v11 = pwork->SP;
  *(&StackData->m_Items[0].i + v11) = v6;
  v14 = pwork->SP + 1;
  ++pwork->CP;
  pwork->SP = v14;
  return 1;
}

// 0x1c96a0
s32 CodeFunc_PushIS(scrProcessWork_s *pwork) {
  struct scrCode_t_array *Code;
  s64 CP;
  s32 v6;
  struct System_Byte_array *StackType;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v11;
  s32 v14;

  Code = pwork->Code;
  CP = pwork->CP;
  v6 = *(&Code->m_Items[0].i + 2 * CP + 1);
  StackType = pwork->StackType;
  SP = pwork->SP;
  StackType->m_Items[SP] = 0;
  StackData = pwork->StackData;
  v11 = pwork->SP;
  *(&StackData->m_Items[0].i + v11) = v6;
  v14 = pwork->SP + 1;
  ++pwork->CP;
  pwork->SP = v14;
  return 1;
}

// 0x1c98b0
s32 CodeFunc_PushIX(scrProcessWork_s *pwork) {
  struct scrCode_t_array *Code;
  struct System_Int32_array *IntVariable;
  s64 CP;
  s64 v8;
  s32 v10;
  struct System_Byte_array *StackType;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v15;
  s32 v18;

  Code = pwork->Code;
  IntVariable = DDS3_GBWK->IntVariable;
  CP = pwork->CP;
  v8 = *(&Code->m_Items[0].i + 2 * CP + 1);
  v10 = IntVariable->m_Items[v8];
  StackType = pwork->StackType;
  SP = pwork->SP;
  StackType->m_Items[SP] = 0;
  StackData = pwork->StackData;
  v15 = pwork->SP;
  *(&StackData->m_Items[0].i + v15) = v10;
  v18 = pwork->SP + 1;
  ++pwork->CP;
  pwork->SP = v18;
  return 1;
}

// 0x1c9ca0
s32 CodeFunc_PushLFX(scrProcessWork_s *pwork) {
  struct scrCode_t_array *Code;
  s64 CP;
  struct System_Single_array *LocalFloat;
  s64 v7;
  s32 v9;
  struct System_Byte_array *StackType;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v14;
  s32 v17;

  Code = pwork->Code;
  CP = pwork->CP;
  LocalFloat = pwork->LocalFloat;
  v7 = *(&Code->m_Items[0].i + 2 * CP + 1);
  v9 = LODWORD(LocalFloat->m_Items[v7]);
  StackType = pwork->StackType;
  SP = pwork->SP;
  StackType->m_Items[SP] = 1;
  StackData = pwork->StackData;
  v14 = pwork->SP;
  *(&StackData->m_Items[0].i + v14) = v9;
  v17 = pwork->SP + 1;
  ++pwork->CP;
  pwork->SP = v17;
  return 1;
}

// 0x1c9b70
s32 CodeFunc_PushLIX(scrProcessWork_s *pwork) {
  struct scrCode_t_array *Code;
  s64 CP;
  struct System_UInt32_array *LocalInt;
  s64 v7;
  s32 v9;
  struct System_Byte_array *StackType;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v14;
  s32 v17;

  Code = pwork->Code;
  CP = pwork->CP;
  LocalInt = pwork->LocalInt;
  v7 = *(&Code->m_Items[0].i + 2 * CP + 1);
  v9 = LocalInt->m_Items[v7];
  StackType = pwork->StackType;
  SP = pwork->SP;
  StackType->m_Items[SP] = 0;
  StackData = pwork->StackData;
  v14 = pwork->SP;
  *(&StackData->m_Items[0].i + v14) = v9;
  v17 = pwork->SP + 1;
  ++pwork->CP;
  pwork->SP = v17;
  return 1;
}

// 0x1c9ee0
s32 CodeFunc_PushReg(scrProcessWork_s *pwork) {
  struct System_Byte_array *StackType;
  u32 max_length;
  s64 SP;
  struct scrStackData_u_array *StackData;
  u32 v8;
  s64 v9;
  s32 v13;

  StackType = pwork->StackType;
  max_length = StackType->max_length;
  SP = pwork->SP;
  StackType->m_Items[SP] = StackType->m_Items[27];
  StackData = pwork->StackData;
  v8 = StackData->max_length;
  v9 = pwork->SP;
  *(&StackData->m_Items[0].i + v9) = *&StackData->m_Items[6].c0;
  v13 = pwork->SP + 1;
  ++pwork->CP;
  pwork->SP = v13;
  return 1;
}

// 0x1c9dd0
s32 CodeFunc_PushSTR(scrProcessWork_s *pwork) {
  struct scrCode_t_array *Code;
  s64 CP;
  s32 v6;
  struct System_Byte_array *StackType;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v11;
  s32 v14;

  Code = pwork->Code;
  CP = pwork->CP;
  v6 = *(&Code->m_Items[0].i + 2 * CP + 1);
  StackType = pwork->StackType;
  SP = pwork->SP;
  StackType->m_Items[SP] = 5;
  StackData = pwork->StackData;
  v11 = pwork->SP;
  *(&StackData->m_Items[0].i + v11) = v6;
  v14 = pwork->SP + 1;
  ++pwork->CP;
  pwork->SP = v14;
  return 1;
}

// 0x1ca7b0
s32 CodeFunc_Run(scrProcessWork_s *pwork) {
  System_String_o *v3;
  System_Object_array *v5;

  v3 = StringLiteral_8873;
  v5 = Empty_string_();
  Log(v3, v5, 0);
  ++pwork->CP;
  return 1;
}

// 0x1cbdc0
s32 CodeFunc_S(scrProcessWork_s *pwork) {
  CodeFunc_2Operation(pwork, 8);
  ++pwork->CP;
  return 1;
}

// 0x1cbec0
s32 CodeFunc_SE(scrProcessWork_s *pwork) {
  CodeFunc_2Operation(pwork, 10);
  ++pwork->CP;
  return 1;
}

// 0x1cb360
s32 CodeFunc_Sub(scrProcessWork_s *pwork) {
  CodeFunc_2Operation(pwork, 1);
  ++pwork->CP;
  return 1;
}

// 0x1d0a80
void FindHojiObj(void) {
  UnityEngine_GameObject_o *FildMapObj;
  UnityEngine_Object_o *Component_object;
  dds3Basic_t_o *ControlScene;
  UnityEngine_Object_c *klass;
  const char *namespaze;
  dds3Basic_t_o *v10;
  s64 v11;
  System_String_o *name;
  dds3Basic_t_o *v15;
  UnityEngine_Object_c *v16;
  s64 v18;

  if (!op_Equality(FildMapObj, 0, 0))
  {
    Component_object = GetComponent_object_(FildMapObj);
    if (!op_Equality(Component_object, 0, 0))
    {
      ControlScene = dds3GetControlScene();
      if (ControlScene)
      {
        klass = Component_object[1].klass;
        namespaze = klass->_1.namespaze;
        if (namespaze >= 1)
        {
          v10 = ControlScene;
          v11 = 4;
          do
          {
            name = get_name(*(&klass->_1.image + v11), 0);
            v15 = dds3SceneBasicSearchNameAndType(v10, 6u, name);
            if (v15)
            {
              v16 = Component_object[1].klass;
              v15->gameObject = *(&v16->_1.image + v11);
            }
            klass = Component_object[1].klass;
            LODWORD(namespaze) = klass->_1.namespaze;
            v18 = v11 - 3;
            ++v11;
          }
          while (v18 < namespaze);
        }
      }
    }
  }
}

// 0x1c71e0
void InitLoadPacket(void) {
  struct ScrTraceCode_LoadTypeList_array *v4;
  u64 v6;
  struct ScrTraceCode_LoadTypeList_array *UnloadPacket;

  LoadCount = 0;
  LoadFlag = 0;
  _Clear(LoadPacket);
  v4 = NewSpecific(ScrTraceCode_LoadTypeList, 0x32u);
  v6 = 0;
  UnloadPacket = v4;
  while (1)
  {
    UnloadPacket->m_Items[v6] = 0;
    if (v6 == 49)
      break;
    ++v6;
  }
}

// 0x1d0a10
bool IsStartModelLoaded(void) {
  return check_loading();
}

// 0x1d09a0
void LoadEventModel(void) {
  check_loading();
}

// 0x1c92c0
f32 PopFloat(scrProcessWork_s *pwork) {
  struct System_Byte_array *StackType;
  s64 v4;
  s64 v6;
  System_String_o *v7;
  System_Object_array *v9;

  StackType = pwork->StackType;
  v4 = pwork->SP - 1LL;
  pwork->SP = v4;
  v6 = StackType->m_Items[v4];
  if (v6 <= 4)
    __asm { BR              X10 }
  v7 = StringLiteral_8872;
  v9 = Empty_string_();
  Log(v7, v9, 0);
  return 0.0;
}

// 0x1c9030
s32 PopInt(scrProcessWork_s *pwork) {
  struct System_Byte_array *StackType;
  s64 v4;
  s64 v6;
  System_String_o *v7;
  System_Object_array *v9;

  StackType = pwork->StackType;
  v4 = pwork->SP - 1LL;
  pwork->SP = v4;
  v6 = StackType->m_Items[v4];
  if (v6 <= 4)
    __asm { BR              X10 }
  v7 = StringLiteral_8870;
  v9 = Empty_string_();
  Log(v7, v9, 0);
  return 0;
}

// 0x1c8e70
void PushFloat(scrProcessWork_s *pwork, f32 data) {
  struct System_Byte_array *StackType;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v7;

  StackType = pwork->StackType;
  SP = pwork->SP;
  StackType->m_Items[SP] = 1;
  StackData = pwork->StackData;
  v7 = pwork->SP;
  *(&StackData->m_Items[0].i + v7) = data;
  ++pwork->SP;
}

// 0x1c8de0
void PushInt(scrProcessWork_s *pwork, s32 data) {
  struct System_Byte_array *StackType;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v7;

  StackType = pwork->StackType;
  SP = pwork->SP;
  StackType->m_Items[SP] = 0;
  StackData = pwork->StackData;
  v7 = pwork->SP;
  *(&StackData->m_Items[0].i + v7) = data;
  ++pwork->SP;
}

// 0x1c8fa0
void PushRet(scrProcessWork_s *pwork, s32 cp) {
  struct System_Byte_array *StackType;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v7;

  StackType = pwork->StackType;
  SP = pwork->SP;
  StackType->m_Items[SP] = 4;
  StackData = pwork->StackData;
  v7 = pwork->SP;
  *(&StackData->m_Items[0].i + v7) = cp;
  ++pwork->SP;
}

// 0x1c8f10
void PushStr(scrProcessWork_s *pwork, s32 data) {
  struct System_Byte_array *StackType;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v7;

  StackType = pwork->StackType;
  SP = pwork->SP;
  StackType->m_Items[SP] = 5;
  StackData = pwork->StackData;
  v7 = pwork->SP;
  *(&StackData->m_Items[0].i + v7) = data;
  ++pwork->SP;
}

// 0x1d0300
char *ReplaceDvlKeyName(char *dvl, s32 *minor) {
  System_String_o *v5;
  s32 CurrentEvent;
  s64 *v9;
  s32 v10;

  v5 = ToUpper(dvl, 0);
  if (Equals_5234480(v5, StringLiteral_8893))
  {
    else
    {
      if (CurrentEvent == 644)
      {
        v9 = &StringLiteral_8894;
        v10 = 299;
        *minor = v10;
        return *v9;
      }
    }
    else if (CurrentEvent == 658)
    {
      v9 = &StringLiteral_8895;
      v10 = 205;
    }
  }
  if (Equals_5234480(v5, StringLiteral_8896))
  {
    v9 = &StringLiteral_8897;
    v10 = 204;
  }
  if (Equals_5234480(v5, StringLiteral_8898))
  {
    v9 = &StringLiteral_8899;
    v10 = 258;
  }
  if (Equals_5234480(v5, StringLiteral_8900))
  {
    v9 = &StringLiteral_8901;
    v10 = 259;
  }
  if (Equals_5234480(v5, StringLiteral_8902))
  {
    v9 = &StringLiteral_8903;
    v10 = 203;
  }
  return dvl;
}

// 0x1c8d50
s32 SDF_ABORT1(char *a) {
  System_Object_array *v4;

  v4 = Empty_string_();
  Log(a, v4, 0);
  return 0;
}

// 0x1ce640
void SetDevilEffect(dds3Basic_t **bas, s32 id) {
    dds3GetBaseControlWorkData(0);
    GetAkey(0);
    GetPBname(0);
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    sdfModelMakeUnity(0, 0, 0);
    mdlEffectCreateUnity(0, 0, 0, 0);
    mdlGenEffect(0, 0, 0);
}

// 0x1ce950
void SetMajinHoleEffect(dds3Basic_t **bas) {
    dds3GetBaseControlWorkData(0);
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    LoadFile(0, 0, 0, 0, 0);
    billSetTexture(0);
    sdfModelMakeUnity(0, 0, 0);
    LoadFileByte(0, 0, 0);
    mdlCreateEffectResrc_D3P(0, 0, 0);
    mdlGenEffect(0, 0, 0);
}

// 0x1cef30
void SetShinenEffect(dds3Basic_t **bas, s32 id) {
    dds3GetBaseControlWorkData(0);
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    sdfModelMakeUnity(0, 0, 0);
    LoadFileByte(0, 0, 0);
    mdlCreateEffectResrc_D3P(0, 0, 0);
    mdlGenEffect(0, 0, 0);
}

// 0x1cf4a0
void Unload(char *key) {
  u64 v3;
  struct ScrTraceCode_LoadTypeList_array *UnloadPacket;
  struct ScrTraceCode_LoadTypeList_array *v8;
  struct ScrTraceCode_LoadTypeList_array *v12;
  AssetBundleCtrl_o *asset_bc;
  struct ScrTraceCode_LoadTypeList_array *v18;
  struct ScrTraceCode_LoadTypeList_array *v21;
  System_String_o *v23;
  AssetBundleCtrl_o *v25;
  struct ScrTraceCode_LoadTypeList_array *v26;
  struct ScrTraceCode_LoadTypeList_array *v28;

  v3 = 0;
  while (1)
  {
    if (UnloadPacket->m_Items[v3])
    {
      v8 = UnloadPacket;
      if (op_Equality(key, v8->m_Items[v3]->name, 0))
        break;
    }
    if (v3++ >= 0x31)
      return;
  }
  v12 = UnloadPacket;
  if (!IsNullOrEmpty(v12->m_Items[v3]->dvlkey))
  {
    asset_bc = get_asset_bc();
    v18 = UnloadPacket;
    UnloadAB(asset_bc, v18->m_Items[v3]->dvlkey);
  }
  v21 = UnloadPacket;
  v23 = v21->m_Items[v3]->key;
  RemoveKeys(4, v23);
  v25 = get_asset_bc();
  v26 = UnloadPacket;
  UnloadAB(v25, v26->m_Items[v3]->key);
  v28 = UnloadPacket;
  v28->m_Items[v3] = 0;
  UnloadUnusedAssets();
}

// 0x1cfd30
void UnloadALL(void) {
  u64 i;
  struct ScrTraceCode_LoadTypeList_array *UnloadPacket;
  struct ScrTraceCode_LoadTypeList_array *v7;
  struct ScrTraceCode_LoadTypeList_array *v10;
  System_String_o *key;
  struct ScrTraceCode_LoadTypeList_array *v14;
  AssetBundleCtrl_o *asset_bc;
  struct ScrTraceCode_LoadTypeList_array *v20;
  AssetBundleCtrl_o *v23;
  struct ScrTraceCode_LoadTypeList_array *v25;
  struct ScrTraceCode_LoadTypeList_array *v27;

  for (i = 0; i != 50; ++i)
  {
    if (UnloadPacket->m_Items[i])
    {
      v7 = UnloadPacket;
      if (v7->m_Items[i]->type == 1)
      {
        v10 = UnloadPacket;
        key = v10->m_Items[i]->key;
        {
        }
        RemoveKeys(4, key);
      }
      v14 = UnloadPacket;
      if (!IsNullOrEmpty(v14->m_Items[i]->dvlkey))
      {
        asset_bc = get_asset_bc();
        v20 = UnloadPacket;
        UnloadAB(asset_bc, v20->m_Items[i]->dvlkey);
      }
      v23 = get_asset_bc();
      v25 = UnloadPacket;
      UnloadAB(v23, v25->m_Items[i]->key);
      v27 = UnloadPacket;
      v27->m_Items[i] = 0;
    }
  }
  UnloadUnusedAssets();
  LoadCount = 0;
}

// 0x1cf7b0
void UnloadModel(char *key, bool ul) {
  u64 v5;
  struct ScrTraceCode_LoadTypeList_array *UnloadPacket;
  struct ScrTraceCode_LoadTypeList_array *v10;
  struct ScrTraceCode_LoadTypeList_array *v14;
  AssetBundleCtrl_o *asset_bc;
  struct ScrTraceCode_LoadTypeList_array *v20;
  AssetBundleCtrl_o *v23;
  struct ScrTraceCode_LoadTypeList_array *v25;
  struct ScrTraceCode_LoadTypeList_array *v27;

  v5 = 0;
  while (1)
  {
    if (UnloadPacket->m_Items[v5])
    {
      v10 = UnloadPacket;
      if (op_Equality(key, v10->m_Items[v5]->name, 0))
        break;
    }
    if (v5++ >= 0x31)
      return;
  }
  v14 = UnloadPacket;
  if (!IsNullOrEmpty(v14->m_Items[v5]->dvlkey))
  {
    asset_bc = get_asset_bc();
    v20 = UnloadPacket;
    UnloadAB(asset_bc, v20->m_Items[v5]->dvlkey);
  }
  v23 = get_asset_bc();
  v25 = UnloadPacket;
  UnloadAB(v23, v25->m_Items[v5]->key);
  v27 = UnloadPacket;
  v27->m_Items[v5] = 0;
  if (ul)
    UnloadUnusedAssets();
}

// 0x1cfa80
void UnloadModel_1899136(char *key) {
  u64 v3;
  struct ScrTraceCode_LoadTypeList_array *UnloadPacket;
  struct ScrTraceCode_LoadTypeList_array *v8;
  struct ScrTraceCode_LoadTypeList_array *v12;
  AssetBundleCtrl_o *asset_bc;
  struct ScrTraceCode_LoadTypeList_array *v18;
  AssetBundleCtrl_o *v21;
  struct ScrTraceCode_LoadTypeList_array *v23;
  struct ScrTraceCode_LoadTypeList_array *v25;

  v3 = 0;
  while (1)
  {
    if (UnloadPacket->m_Items[v3])
    {
      v8 = UnloadPacket;
      if (op_Equality(key, v8->m_Items[v3]->name, 0))
        break;
    }
    if (v3++ >= 0x31)
      return;
  }
  v12 = UnloadPacket;
  if (!IsNullOrEmpty(v12->m_Items[v3]->dvlkey))
  {
    asset_bc = get_asset_bc();
    v18 = UnloadPacket;
    UnloadAB(asset_bc, v18->m_Items[v3]->dvlkey);
  }
  v21 = get_asset_bc();
  v23 = UnloadPacket;
  UnloadAB(v21, v23->m_Items[v3]->key);
  v25 = UnloadPacket;
  v25->m_Items[v3] = 0;
}

// 0x1cf320
void UpdateDying(void *plyobj) {
  System_String_o *name;
  System_String_o *v4;
  System_String_o *v5;
  UnityEngine_Animator_o *Animator;

  name = get_name(plyobj);
  if (!IsNullOrEmpty(name) && get_Length(name) >= 12)
  {
    v4 = Substring_5248048(name, 0, 12);
    v5 = ToUpper(v4, 0);
    if (Equals_5234480(v5, StringLiteral_8891))
    {
      Animator = GetAnimator(plyobj);
      if (!op_Equality(Animator, 0, 0) && get_layerCount(Animator) != 1)
      {
        SetInteger(
          Animator,
          StringLiteral_4572,
          (fldDbg->PlayerStatus >> 1) & 1,
          0);
      }
    }
  }
}

// 0x1cf490
bool is_event_devil(dds3ModelFileTable_t *ft, s32 *major, s32 *minor) {
  return 0;
}

// 0x1cd400
s32 scrGetCodePointer(void) {
  return nowpwork->CP;
}

// 0x1cd5c0
s32 scrGetCommandTimer(void) {
  return nowpwork->CommandTimer;
}

// 0x1cd630
f32 scrGetCommandTimerF(void) {
  return nowpwork->CommandTimerF;
}

// 0x1cd780
void *scrGetData(void) {
  return nowpwork->data;
}

// 0x1ccb10
f32 scrGetFloatPara(s32 n) {
  struct scrProcessWork_s_o *nowpwork;
  struct System_Byte_array *StackType;
  s32 v6;
  s64 v8;
  System_String_o *v9;
  System_Object_array *v11;

  StackType = nowpwork->StackType;
  v6 = nowpwork->SP + ~n;
  v8 = StackType->m_Items[v6];
  if (v8 <= 4)
    __asm { BR              X10 }
  v9 = StringLiteral_8881;
  v11 = Empty_string_();
  Log(v9, v11, 0);
  return 0.0;
}

// 0x1cc7a0
s32 scrGetIntPara(s32 n) {
  struct scrProcessWork_s_o *nowpwork;
  struct System_Byte_array *StackType;
  s32 v6;
  s64 v8;
  System_String_o *v9;
  System_Object_array *v11;

  StackType = nowpwork->StackType;
  v6 = nowpwork->SP + ~n;
  v8 = StackType->m_Items[v6];
  if (v8 <= 4)
    __asm { BR              X10 }
  v9 = StringLiteral_8880;
  v11 = Empty_string_();
  Log(v9, v11, 0);
  return 0;
}

// 0x1cd360
s32 scrGetLabelCodeAddress(s32 labelindex) {
  struct scrLabelTable_t_array *LabelTable;

  LabelTable = nowpwork->LabelTable;
  return LabelTable->m_Items[labelindex].CodeAddress;
}

// 0x1cd6a0
s32 scrGetMessageHandle(void) {
  return nowpwork->MesHandle;
}

// 0x1cd2c0
s32 scrGetProcedureCodeAddress(s32 procindex) {
  struct scrProcTable_t_array *ProcTable;

  ProcTable = nowpwork->ProcTable;
  return ProcTable->m_Items[procindex].CodeAddress;
}

// 0x1cd710
scrProcessWork_s *scrGetScriptHandle(void) {
  return nowpwork;
}

// 0x1cd4e0
s32 scrGetScriptTimer(void) {
  return nowpwork->ScriptTimer;
}

// 0x1cd550
f32 scrGetScriptTimerF(void) {
  return nowpwork->ScriptTimerF;
}

// 0x1cce80
char *scrGetStrPara(s32 n) {
  struct scrProcessWork_s_o *nowpwork;
  s32 v5;
  struct System_Byte_array *StackType;
  s32 v7;
  s64 v8;
  struct scrProcessWork_s_o *v10;
  struct scrStackData_u_array *StackData;
  u32 max_length;
  System_String_o *v13;
  System_Object_array *v15;
  s32 v17;
  s32 v19;
  s32 v20;
  System_Array_o *v22;
  System_Text_Encoding_o *ASCII;
  System_String_o *v25;

  v5 = ~n;
  StackType = nowpwork->StackType;
  v7 = nowpwork->SP + v5;
  v8 = v7;
  if (StackType->m_Items[v7] != 5)
  {
    v13 = StringLiteral_8882;
    v15 = Empty_string_();
    Log(v13, v15, 0);
    return 0;
  }
  v10 = nowpwork;
  StackData = v10->StackData;
  max_length = StackData->max_length;
  v17 = *(&StackData->m_Items[0].i + v8);
  v19 = IndexOf_byte_(
          v10->StringData,
          0,
          *(&v10->StackData->m_Items[0].i + v8));
  if (v19 == -1)
    return 0;
  v20 = v19 - v17;
  v22 = NewSpecific(byte, (v19 - v17 + 1));
  BlockCopy(nowpwork->StringData, v17, v22, 0, v20);
  ASCII = get_ASCII();
  v25 = (ASCII->klass[1]._1.byval_arg.data)(ASCII, v22, *&ASCII->klass[1]._1.byval_arg.bits);
  return Replace_5267216(v25, StringLiteral_859, StringLiteral_416);
}

// 0x1cd470
void scrSetCodePointer(s32 cp) {
  nowpwork->CP = cp;
}

// 0x1cd1f0
void scrSetFloatReturnValue(f32 f) {
  struct System_Byte_array *StackType;
  struct scrStackData_u_array *StackData;

  StackType = nowpwork->StackType;
  StackType->m_Items[27] = 1;
  StackData = nowpwork->StackData;
  *&StackData->m_Items[6].c0 = f;
}

// 0x1cd120
void scrSetIntReturnValue(s32 i) {
  struct System_Byte_array *StackType;
  struct scrStackData_u_array *StackData;

  StackType = nowpwork->StackType;
  StackType->m_Items[27] = 0;
  StackData = nowpwork->StackData;
  *&StackData->m_Items[6].c0 = i;
}

// 0x1c87e0
s32 scrTraceCode(scrProcessWork_s *pwork) {
  struct scrCode_t_array *Code;
  s64 CP;
  s64 v6;
  struct Scr_AnonymousClass_array *codefunc;
  s32 v11;
  f32 CommandTimerF;
  f32 v15;
  f32 ScriptTimerF;
  s32 v17;
  f32 deltaTime;
  s32 v19;

  while (1)
  {
    Code = pwork->Code;
    CP = pwork->CP;
    v6 = *(&Code->m_Items[0].i + 2 * CP);
    if (IsPaused())
      break;
    v11 = Invoke(codefunc->m_Items[v6]->func, pwork);
    switch (v11)
    {
      case 1:
        pwork->CommandTimer = 0;
        pwork->CommandTimerF = 0.0;
        break;
      case 2:
      case 0:
        pwork->CommandTimer = 0;
        pwork->CommandTimerF = 0.0;
        return 2;
    }
  }
  ++eventcnt;
  CommandTimerF = pwork->CommandTimerF;
  v15 = CommandTimerF + get_deltaTime();
  ScriptTimerF = pwork->ScriptTimerF;
  v17 = pwork->CommandTimer + 1;
  pwork->CommandTimerF = v15;
  pwork->CommandTimer = v17;
  deltaTime = get_deltaTime();
  v19 = pwork->ScriptTimer + 1;
  pwork->ScriptTimerF = ScriptTimerF + deltaTime;
  pwork->ScriptTimer = v19;
  return 1;
}
