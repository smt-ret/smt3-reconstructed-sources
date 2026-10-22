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
static void *HoleEff;

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
  Log("AddLoad!!!!!!!!!!!!!!!!", v18, 0);
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
  if (Equals_5234480(v19[4], "extram"))
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
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  System_String_o *v12;
  s32 v13;
  bool IsNullOrEmpty;
  System_String_o *v15;
  System_String_o *v16;
  Il2CppClass *v17;
  System_String_o *v18;
  System_String_o *v19;
  System_String_array *v20;
  System_String_o *monitor;
  Il2CppClass *v27;
  System_String_o *v29;
  System_Object_array *v31;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  System_String_o *v36;
  s32 v37;
  bool v38;
  s32 v39;
  s64 *v40;
  UnityEngine_GameObject_o *v41;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v44;
  System_String_o *name;
  Il2CppObject *v47;
  u64 *v49;
  dds3Basic_t_o *v51;
  Il2CppObject *workdata;
  Il2CppClass *v54;
  s64 v55;
  evtUnitHandle_t_o *v56;
  evtUnitHandle_t_o **v57;
  Il2CppClass *v58;
  u64 *interfaceOffsets;
  UnityEngine_Transform_o *v60;
  UnityEngine_Transform_o *Child;
  Il2CppClass *v63;
  dds3Basic_t_o *v66;
  _BOOL4 v67;
  System_String_o *v68;
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  Il2CppObject *pModel;
  Il2CppClass *v74;
  s64 v75;
  UnityEngine_Component_o *Animator;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *v83;
  Il2CppObject *v84;
  s32 v85;
  evtUnitHandle_t_o *v86;
  s32 NowMotion;
  s32 NowBefore;
  s32 NowSmooth;
  s32 v93;
  char *v101;
  s64 *v102;
  char *v103;
  s64 *v104;
  s32 LoadCount;
  dds3Basic_t_o *basica;
  u64 v107[2];
  char *v108;
  UnityEngine_Vector3_o zero;

  basica = basic;
  if (obj)
  {
    klass = obj->klass;
    if (obj->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelFileTable_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelFileTable_t, v107);
      if ((v107[0] & 1) != 0)
        v10 = v108;
      else
        v10 = v107 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  v12 = "charactor";
  v13 = 0;
  if (major <= 7)
  {
    if (((1 << major) & 5) != 0)
    {
      v19 = Concat_5224608("charactor", "/f");
LABEL_23:
      v12 = v19;
      v13 = 0;
      goto LABEL_24;
    }
    if (((1 << major) & 0x42) != 0)
    {
      v17 = obj[3].klass;
      if (Equals_5234480(v17, "devil_0x100e"))
        v18 = "devil_0x100";
      else
        v18 = v17;
      v12 = Concat_5221536(v12, "/b/", v18);
      v13 = 1;
    }
    else if (((1 << major) & 0x88) != 0)
    {
      IsNullOrEmpty = IsNullOrEmpty(obj[1].klass);
      v15 = "/";
      if (IsNullOrEmpty)
        v16 = "e";
      else
        v16 = ToLower(obj[1].klass, 0);
      v19 = Concat_5221536(v12, v15, v16);
      goto LABEL_23;
    }
  }
LABEL_24:
  v20 = NewSpecific(string, 6u);
  v20->m_Items[0] = "AddModel : ";
  monitor = obj[2].monitor;
  v20->m_Items[1] = monitor;
  v20->m_Items[2] = ",";
  v20->m_Items[3] = v12;
  v20->m_Items[4] = "/";
  v27 = obj[3].klass;
  v20->m_Items[5] = v27;
  v29 = Concat_5271600(v20);
  v31 = Empty_string_();
  Log(v29, v31, 0);
  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, obj[2].monitor, v12, obj[3].klass);
  v36 = 0;
  if (op_Inequality(Prefab_16624656, 0, 0))
  {
    if (IsNullOrEmpty(obj[1].klass))
    {
      v37 = 0;
    }
    else
    {
      v38 = Equals_5234480(obj[1].klass, "I");
      if (Equals_5234480(obj[1].klass, "J"))
        v39 = 2;
      else
        v39 = 0;
      v37 = v39 & 0xFFFFFFFE | v38;
    }
    v40 = &"Character";
    if ((v37 & 1) != 0)
      v40 = &"Field";
    v41 = Find(*v40, 0);
    transform = get_transform(v41, 0);
    v44 = Instantiate_object__425664(Prefab_16624656, transform, 0);
    name = get_name(v44);
    v47 = Replace_5267216(name, "(Clone)", "", 0);
    v49 = sub_8D3950(s32, &LoadCount);
    v36 = Format_5268592("{0}_{1}", v47, v49);
    set_name(v44, v36);
    v51 = basica;
    workdata = basica->workdata;
    v54 = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < v55
      || v54->_2.typeHierarchy[v55 - 1] != dds3UnitObjectBasicWorkData_t)
    {
      sub_8FC2C0(v54->_1.element_class, dds3UnitObjectBasicWorkData_t, v107);
      if ((v107[0] & 1) != 0)
        v101 = v108;
      else
        v101 = v107 + 1;
      v102 = sub_8C4940(v101);
    }
    v58 = workdata[2].klass;
    v57 = &workdata[2];
    v56 = v58;
    interfaceOffsets = v58->_1.interfaceOffsets;
    if (interfaceOffsets)
    {
      interfaceOffsets[12] = basica;
      v56 = *v57;
    }
    v56->modelobj = v44;
    if (v13)
    {
      v60 = get_transform(v44, 0);
      Child = GetChild(v60, 0);
      zero = get_zero();
      set_localPosition(Child, zero);
      v51 = basica;
    }
    v63 = obj[3].klass;
    AttachHD(v44, v51, v63, v37);
    v66 = basica;
    if (basica)
    {
      basica->gameObject = v44;
      v66->name = v36;
    }
    v67 = major == 1 || (major | 1) == 7;
    if (minor >= 1 && v67)
    {
      v68 = obj[2].monitor;
      LoadKeys(4, v68, 0);
      SetDevilEffect(&basica, minor);
    }
    if (major == 2 && minor == 20)
    {
      SetMajinHoleEffect(&basica);
    }
    else if (major == 3 && (minor & 0xFFFFFFFC) == 0x18)
    {
      SetShinenEffect(&basica, minor);
    }
    BaseControlWorkData = dds3GetBaseControlWorkData(&(*v57)->Owner, 0);
    SetActive(v44, (BaseControlWorkData->flag & 1) == 0, 0);
    pModel = BaseControlWorkData->pModel;
    v74 = pModel->klass;
    if (pModel->klass->_2.typeHierarchyDepth < v75
      || v74->_2.typeHierarchy[v75 - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(v74->_1.element_class, dds3ModelHandle_t, v107);
      if ((v107[0] & 1) != 0)
        v103 = v108;
      else
        v103 = v107 + 1;
      v104 = sub_8C4940(v103);
    }
    if ((pModel[1].klass & 1) != 0)
      SetActive(v44, 0, 0);
    Animator = GetAnimator(v44);
    if (op_Inequality(Animator, 0, 0))
    {
      gameObject = get_gameObject(Animator);
      Component_object = GetComponent_object_(gameObject);
      if (op_Equality(Component_object, 0, 0))
      {
        v83 = get_gameObject(Animator);
        v84 = AddComponent_object_(v83);
        if (v67)
          v85 = 2;
        else
          v85 = 0;
        SetCharacterType(v84, v85);
      }
      UpdateDying(v44);
      v86 = *v57;
      NowMotion = (*v57)->NowMotion;
      if ((*v57)->NowMotion)
      {
        NowBefore = v86->NowBefore;
        NowSmooth = v86->NowSmooth;
        mdlSmoothLoopMotionForUnity(v57, 0, NowMotion, NowBefore, NowSmooth, 0, 0);
      }
    }
    fldSetCharAdd(v36, v44);
    v93 = LoadCount;
    LoadCount = v93 + 1;
    if (v93 >= 0xFFFF)
    {
      LoadCount = 0;
    }
  }
  return v36;
}

// 0x1ce380
void AttachHD(void *obj, dds3Basic_t *basic, char *name, s32 cb) {
  dds3Basic_t_o *v7;
  FieldBgHD_o *v9;
  UnityEngine_Transform_o *transform;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v16;
  s64 *v17;
  UnityEngine_Object_o *Manager__PriChrHDGet;
  bool v20;
  evtUnitHandle_t_o *v22;
  u64 v24[3];

  v7 = basic;
  if (cb == 2)
  {
    v9 = AddComponent_object_(obj);
    v9->filedname = name;
    {
LABEL_6:
    }
LABEL_9:
    evtUpdateEx_FieldLoadAfter(v9, obj, name);
    return;
  }
  if (cb == 1)
  {
    v9 = AddComponent_object_(obj);
    transform = get_transform(obj, 0);
    Rotate_27486992(transform, 0.0, 180.0, 0.0);
    v9->filedname = name;
      goto LABEL_6;
    goto LABEL_9;
  }
  workdata = v7->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v24);
      if ((v24[0] & 1) != 0)
        v16 = v24[2];
      else
        v16 = v24 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  Manager__PriChrHDGet = PriChrHDGet(obj);
  v20 = op_Inequality(Manager__PriChrHDGet, 0, 0);
  v22 = workdata[2].klass;
  if (v20)
  {
    SetEveUnit(Manager__PriChrHDGet, v22);
  }
  else
  {
    Manager__PriChrHDGet = mdlSetHD(obj, 2, v22, 15);
  }
  evtUpdateEx_CharLoadAfter(Manager__PriChrHDGet, obj, v7, name);
}

// 0x1ca920
void CodeFunc_2Operation(scrProcessWork_s *pwork, s32 type) {
  struct System_Byte_array *StackType;
  s64 v6;
  s32 v9;
  struct System_Byte_array *v10;
  s64 v11;
  s32 CodeFunc_2Operation_t1;
  s32 CodeFunc_2Operation_t2;
  f32 v21;
  struct System_Byte_array *v23;
  f32 CodeFunc_2Operation_rf;
  s64 v25;
  s64 SP;
  struct scrStackData_u_array *StackData;
  s64 v31;

  StackType = pwork->StackType;
  v6 = pwork->SP - 1LL;
  v9 = StackType->m_Items[v6];
  CodeFunc_2Operation_t1 = v9;
  v10 = pwork->StackType;
  v11 = pwork->SP - 2LL;
  CodeFunc_2Operation_t2 = v10->m_Items[v11];
  if (CodeFunc_2Operation_t1)
  {
    else if (CodeFunc_2Operation_t1 != 2)
    {
      goto LABEL_30;
    }
  }
  else
  {
    if (!CodeFunc_2Operation_t2)
      goto LABEL_20;
  }
  if (CodeFunc_2Operation_t2 == 2)
    goto LABEL_20;
LABEL_30:
  CodeFunc_2Operation_f1 = PopFloat(pwork, *&type);
  v21 = PopFloat(pwork);
  CodeFunc_2Operation_f2 = v21;
  if (type <= 0xB)
    __asm { BR              X10 }
  v23 = pwork->StackType;
  v25 = pwork->SP;
  v23->m_Items[v25] = 1;
LABEL_47:
  StackData = pwork->StackData;
  v31 = pwork->SP;
  *(&StackData->m_Items[0].i + v31) = CodeFunc_2Operation_rf;
  ++pwork->SP;
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
  v7 = "CodeFunc_IF(..) invalid stack type(?)!!\n";
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
  v7 = "CodeFunc_Minus(..) invalid stack type(?)!!\n";
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
  v7 = "CodeFunc_Not(..) invalid stack type(?)!!\n";
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

  v3 = "CodeFunc_Run(..) Can't running command!!\n";
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
  ScrTraceCode_c *v5;
  u64 v6;
  struct ScrTraceCode_LoadTypeList_array *UnloadPacket;

  LoadCount = 0;
  LoadFlag = 0;
  _Clear(LoadPacket);
  v4 = NewSpecific(ScrTraceCode_LoadTypeList, 0x32u);
  v6 = 0;
  UnloadPacket = v4;
  if ((v5->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
    goto LABEL_11;
  }
  while (1)
  {
LABEL_11:
    UnloadPacket->m_Items[v6] = 0;
    if (v6 == 49)
      break;
    ++v6;
      goto LABEL_9;
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
  v7 = "PopFloat(..) invalid stack type(?)!!\n";
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
  v7 = "PopInt(..) invalid stack type!!\n";
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
  if (Equals_5234480(v5, "DVL0X113"))
  {
    else
    {
      if (CurrentEvent == 644)
      {
LABEL_7:
        v9 = &"dvl0x12b";
        v10 = 299;
LABEL_22:
        *minor = v10;
        return *v9;
      }
    }
    else if (CurrentEvent == 658)
    {
LABEL_12:
      v9 = &"dvl0xcd";
      v10 = 205;
      goto LABEL_22;
    }
  }
  if (Equals_5234480(v5, "DVL0X11B"))
  {
    v9 = &"dvl0xcc";
    v10 = 204;
    goto LABEL_22;
  }
  if (Equals_5234480(v5, "DVL0X123"))
  {
    v9 = &"dvl0x102";
    v10 = 258;
    goto LABEL_22;
  }
  if (Equals_5234480(v5, "DVL0X124"))
  {
    v9 = &"dvl0x103";
    v10 = 259;
    goto LABEL_22;
  }
  if (Equals_5234480(v5, "DVL0X161"))
  {
    v9 = &"dvl0xcb";
    v10 = 203;
    goto LABEL_22;
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
  dds3ModelHandle_t_o *pModel;
  dds3ModelHandle_t_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  dds3ModelResrc_t_o *v10;
  struct dds3ModelResrc_t_o *resrc;
  struct dds3ModelResrc_t_o *v12;
  u64 *v13;
  System_String_o *Akey;
  System_String_o *PBname;
  System_String_o *v17;
  System_Byte_array *v19;
  dds3ModelHandle_t_o *v20;
  mdlEffectResrcList_t_o *efc_res_list;
  System_Byte_array *aTopPtr;
  dds3ModelHandle_t_o *v26[3];
  dds3ModelHandle_t_o *aHandle;

  aHandle = 0;
  efc_res_list = 0;
  aTopPtr = 0;
  pModel = dds3GetBaseControlWorkData(bas)->pModel;
  if (pModel)
  {
    klass = pModel->klass;
    if (pModel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v26);
      if ((v26[0] & 1) != 0)
        v8 = v26[2];
      else
        v8 = v26 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  aHandle = pModel;
  v10 = Allocate(dds3ModelResrc_t);
  dds3ModelResrc_t___ctor(v10);
  pModel->resrc = v10;
  v10->major = 1;
  pModel->resrc->minor = id;
  resrc = pModel->resrc;
  pModel->effects = 0;
  resrc->effectData = 0;
  v12 = pModel->resrc;
  v13 = Allocate(mdlEffectResrcList_t);
  mdlEffectResrcList_t___ctor(v13);
  v12->effectResrcList = v13;
  Akey = GetAkey(id);
  PBname = GetPBname(id);
  v17 = Concat_5221536("dds3data/dvl_pb/", PBname, ".bytes");
  aTopPtr = 0;
  sdfDevLoadFileUnity_25061072(v17, &aTopPtr, 0, Akey);
  v19 = aTopPtr;
  v20 = pModel;
  {
    v20 = pModel;
  }
  pModel->modelRoot = sdfModelMakeUnity(0, v19, 0);
  v20->modelRoot->modelobj = (*bas)->gameObject;
  v20->resrc->effectData = &aTopPtr->obj;
  efc_res_list = v20->resrc->effectResrcList;
  mdlEffectCreateUnity(6, id, &efc_res_list, 1);
  v20->resrc->effectResrcList = efc_res_list;
  if (!mdlGenEffect(&aHandle, -1, -1))
  {
    mdlGenEffect(&aHandle, 0, 0);
  }
}

// 0x1ce950
void SetMajinHoleEffect(dds3Basic_t **bas) {
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  Il2CppObject *pModel;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  dds3ModelResrc_t_o *v9;
  u64 *monitor;
  u64 *v11;
  u64 *v12;
  System_String_o *v13;
  struct UnityEngine_Texture_array *HoleEff;
  struct UnityEngine_Texture_array *v19;
  struct UnityEngine_Texture_array *v21;
  AssetBundleCtrl_o *asset_bc;
  s64 *File;
  s64 *v25;
  s64 v26;
  s64 v27;
  char *v28;
  s64 *v29;
  s64 v31;
  s64 v32;
  char *v33;
  s64 *v34;
  UnityEngine_Texture_array *v36;
  dds3ModelHandle_t_o *v38;
  System_Byte_array *v39;
  dds3ModelHandle_t_o *v40;
  AssetBundleCtrl_o *v41;
  System_Byte_array *FileByte;
  struct UnityEngine_Texture_array *v45;
  mdlEffectResrcList_t_o *listPtr;
  System_Byte_array *aTopPtr;
  u64 v49[2];
  char *v50;
  dds3ModelHandle_t_o *aHandle;

  aHandle = 0;
  listPtr = 0;
  aTopPtr = 0;
  BaseControlWorkData = dds3GetBaseControlWorkData(bas);
  pModel = BaseControlWorkData->pModel;
  if (pModel)
  {
    klass = pModel->klass;
    if (pModel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v49);
      if ((v49[0] & 1) != 0)
        v7 = v50;
      else
        v7 = v49 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  aHandle = BaseControlWorkData->pModel;
  v9 = Allocate(dds3ModelResrc_t);
  dds3ModelResrc_t___ctor(v9);
  pModel[2].monitor = v9;
  v9->major = 2;
  *(pModel[2].monitor + 17) = 20;
  monitor = pModel[2].monitor;
  pModel[3].monitor = 0;
  monitor[12] = 0;
  v11 = pModel[2].monitor;
  v12 = Allocate(mdlEffectResrcList_t);
  mdlEffectResrcList_t___ctor(v12);
  v11[13] = v12;
  aTopPtr = 0;
  v13 = "fldplayer";
  sdfDevLoadFileUnity_25061072("charactor/f/hole/majin_hole.PB.bytes", &aTopPtr, 0, "fldplayer");
  if (HoleEff)
  {
    else if (!LODWORD(HoleEff->max_length))
    {
      goto LABEL_17;
    }
    HoleEff->m_Items[0] = 0;
    UnloadUnusedAssets();
  }
  v19 = NewSpecific(UnityEngine_Texture, 1u);
  HoleEff = v19;
  v21 = HoleEff;
  asset_bc = get_asset_bc();
  File = LoadFile(asset_bc, "fldplayer", "charactor/f/hole", "majin_hole_0", ".png");
  v25 = File;
  if (File)
  {
    v26 = *File;
    if (*(*File + 288) < v27 || *(*(v26 + 200) + 8 * v27 - 8) != UnityEngine_Texture)
    {
      sub_8FC2C0(*(v26 + 64), UnityEngine_Texture, v49);
      if ((v49[0] & 1) != 0)
        v28 = v50;
      else
        v28 = v49 + 1;
      v29 = sub_8C4940(v28);
    }
    v31 = *v25;
    if (*(*v25 + 288) < v32 || *(*(v31 + 200) + 8 * v32 - 8) != UnityEngine_Texture)
    {
      sub_8FC2C0(*(v31 + 64), UnityEngine_Texture, v49);
      if ((v49[0] & 1) != 0)
        v33 = v50;
      else
        v33 = v49 + 1;
      v34 = sub_8C4940(v33);
    }
  }
  v21->m_Items[0] = v25;
  v36 = HoleEff;
  billSetTexture(v36);
  v38 = aHandle;
  v39 = aTopPtr;
  v40 = aHandle;
  {
    v40 = aHandle;
  }
  v38->modelRoot = sdfModelMakeUnity(0, v39, 0);
  v40->modelRoot->modelobj = (*bas)->gameObject;
  v40->resrc->effectData = &aTopPtr->obj;
  listPtr = v40->resrc->effectResrcList;
  v41 = get_asset_bc();
  FileByte = LoadFileByte(v41, v13, "charactor/f/hole/majin_hole.D3P.bytes");
  mdlCreateEffectResrc_D3P(&listPtr, &FileByte->obj, 0);
  v40->resrc->effectResrcList = listPtr;
  if (!mdlGenEffect(&aHandle, -1, -1))
  {
    mdlGenEffect(&aHandle, 0, 0);
  }
  else
  {
    v45 = HoleEff;
    if (!LODWORD(v45->max_length))
      goto LABEL_61;
  }
  v45->m_Items[0] = 0;
  UnloadUnusedAssets();
}

// 0x1cef30
void SetShinenEffect(dds3Basic_t **bas, s32 id) {
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
  s32 v15;
  u64 *v16;
  System_String_o *v17;
  System_String_o *v18;
  System_Byte_array *v20;
  dds3ModelHandle_t_o *v21;
  u64 *v22;
  System_String_o *v23;
  System_String_o *v25;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v27;
  System_Byte_array *FileByte;
  AssetBundleCtrl_o *v30;
  System_String_o *v31;
  System_Byte_array *v32;
  s32 v34;
  mdlEffectResrcList_t_o *listPtr;
  System_Byte_array *aTopPtr;
  dds3ModelHandle_t_o *aHandle;
  u64 v38[3];

  listPtr = 0;
  aTopPtr = 0;
  aHandle = 0;
  BaseControlWorkData = dds3GetBaseControlWorkData(bas);
  pModel = BaseControlWorkData->pModel;
  if (pModel)
  {
    klass = pModel->klass;
    if (pModel->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v38);
      if ((v38[0] & 1) != 0)
        v9 = v38[2];
      else
        v9 = v38 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  aHandle = BaseControlWorkData->pModel;
  v11 = Allocate(dds3ModelResrc_t);
  dds3ModelResrc_t___ctor(v11);
  pModel[2].monitor = v11;
  v11->major = 1;
  *(pModel[2].monitor + 17) = id;
  monitor = pModel[2].monitor;
  pModel[3].monitor = 0;
  monitor[12] = 0;
  v13 = pModel[2].monitor;
  v14 = Allocate(mdlEffectResrcList_t);
  mdlEffectResrcList_t___ctor(v14);
  v13[13] = v14;
  if ((id - 25) > 2)
    v15 = 51;
  else
    v15 = dword_32C3078[id - 25];
  LODWORD(v38[0]) = v15;
  v16 = sub_8D3950(s32, v38);
  v17 = Format("npc{0:D2}", v16, 0);
  v18 = Concat_5221536("dds3data/fld/f/bin/", v17, ".PB.bytes");
  aTopPtr = 0;
  sdfDevLoadFileUnity_25061072(v18, &aTopPtr, 0, "f_bin");
  v20 = aTopPtr;
  v21 = pModel;
  {
    v21 = pModel;
  }
  pModel[4].klass = sdfModelMakeUnity(0, v20, 0);
  v21->modelRoot->modelobj = (*bas)->gameObject;
  v21->resrc->effectData = &aTopPtr->obj;
  listPtr = v21->resrc->effectResrcList;
  v34 = v15;
  v22 = sub_8D3950(s32, &v34);
  v23 = Format("npc_eff{0:D2}", v22, 0);
  v25 = Concat_5224608("dds3data/fld/f/bin/", v23);
  asset_bc = get_asset_bc();
  v27 = Concat_5224608(v25, "_0.D3P.bytes");
  FileByte = LoadFileByte(asset_bc, "f_bin", v27);
  mdlCreateEffectResrc_D3P(&listPtr, &FileByte->obj, 0);
  v30 = get_asset_bc();
  v31 = Concat_5224608(v25, "_1.D3P.bytes");
  v32 = LoadFileByte(v30, "f_bin", v31);
  mdlCreateEffectResrc_D3P(&listPtr, &v32->obj, 0);
  aHandle->resrc->effectResrcList = listPtr;
  if (!mdlGenEffect(&aHandle, -1, -1))
  {
    mdlGenEffect(&aHandle, 0, 0);
  }
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
    if (Equals_5234480(v5, "PLAYER_TATOO"))
    {
      Animator = GetAnimator(plyobj);
      if (!op_Equality(Animator, 0, 0) && get_layerCount(Animator) != 1)
      {
        SetInteger(
          Animator,
          "anim",
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
  v9 = "scrGetFloatPara(..) invalid stack type!!\n";
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
  v9 = "scrGetIntPara(..) invalid stack type!!\n";
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
    v13 = "scrGetStrPara(..) invalid stack type!!\n";
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
  return Replace_5267216(v25, " ", "");
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
        goto LABEL_20;
      case 0:
        pwork->CommandTimer = 0;
        pwork->CommandTimerF = 0.0;
        return 2;
    }
  }
LABEL_20:
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
