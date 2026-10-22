#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct FieldChrHD FieldChrHD;
typedef struct ModelHD ModelHD;
typedef struct NB_FILEHANDLE_T NB_FILEHANDLE_T;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbSound_t nbSound_t;

static s32 ftbl[512];
static s32 mse_nextidx;
static void *nbCache_B_P;
static void *nbCache_Fld_B;
static void *nbCache_Fld_F;
static bool Cache_Field_F_ModeOn;
static char *BootLoad_akey;

s32 ChkUseMarukage(s32 deveilID);
void Dai2keitai(s32 unitid);
void DanteBattleVoiceInit(s32 unitid, void *obj);
u8 Get(s32 id);
char *GetAkey(s32 no);
char *GetFname(s32 no);
nbFormation_t *GetForm(FieldChrHD *this);
s32 IsBattleQueue(FieldChrHD *this);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void LoadKeys(s32 type, char *key, char *path);
s32 LoadKeysMSE(char *key, s32 idx);
void *LoadPrefabAsync(AssetBundleCtrl *this, char *key, char *path, char *name);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void LoadSound(char *key, char *path);
void RetTransparent(void *obj);
void SetAnimator(void *obj, char *animkey, s32 animno);
s32 SetForm(nbEventProcessData_t *ed);
void SetFrameAnime(ModelHD *this, bool act);
void SetLayerAll2(FieldChrHD *this, void *rootobj, s32 setlayer);
void SetModelObject(FieldChrHD *this, void *chr, void *kage);
void SetTransparent(void *obj, u32 rgba, f32 alfrgb);
void UnloadAB(AssetBundleCtrl *this, char *key);
bool evtBitCheck(s32 no);
FieldChrHD *mdlSetHD(void *obj, s32 mode, evtUnitHandle_t *hunit, s32 layer);
char *nbLoadStartUnitPack(s32 unitid);

// 0x1593660
void DecodeMotionSe(nbSound_t *s, void *addr, s32 size, s32 seno, s32 minor) {
  u64 *v8;

  v8 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v8);
  if (s && evtBitCheck(3087))
  {
    Get(minor, 0);
  }
}

// 0x1593710
void DecodeNegoSe(nbSound_t *s, void *addr, s32 size, s32 minor) {
  ;
}

// 0x1593650
void DecodeUnit(void *addr, s32 size, s32 major, s32 minor) {
  ;
}

// 0x1593730
s32 nbCheckLoadUnitPackFile(nbFormation_t **form, s32 major, s32 minor, bool semiflg) {
  _BOOL4 v5;
  AssetBundleCtrl_o *asset_bc;
  s32 read_minor;
  System_String_o *Fname;
  AssetBundleCtrl_o *v12;
  System_String_o *akey;
  AssetBundleCtrl_o *v14;
  System_String_o *v15;
  UnityEngine_Object_o *Prefab_16624656;
  bool v18;
  nbFormation_t_o *v20;
  System_String_o *v21;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v26;
  UnityEngine_Transform_o *v27;
  UnityEngine_Transform_o *Child;
  nbFormation_t_o *v29;
  f32 v30;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *v33;
  Il2CppObject *v34;
  FieldChrHD_o *v36;
  System_String_o *v39;
  AssetBundleCtrl_o *v40;
  Il2CppObject *v41;
  UnityEngine_Component_o *v42;
  UnityEngine_Transform_o *v44;
  Il2CppObject *v45;
  UnityEngine_GameObject_o *v46;
  FieldChrHD_o *v47;
  UnityEngine_GameObject_o *v48;
  s32 v49;
  u64 *v50;
  System_String_o *v52;
  System_String_o *v53;
  System_String_o *v55;
  AssetBundleCtrl_o *v56;
  Il2CppObject *v57;
  UnityEngine_Component_o *v58;
  UnityEngine_Transform_o *v60;
  Il2CppObject *v61;
  UnityEngine_GameObject_o *v62;
  s32 IsBattleQueue;
  UnityEngine_Quaternion_o rotation;
  s32 v65;

  v5 = semiflg;
  *&rotation.x = 0;
  *&rotation.z = 0;
  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, (*form)->akey, 0))
    return 0;
  read_minor = (*form)->read_minor;
  Fname = GetFname(read_minor);
  v12 = get_asset_bc();
  akey = (*form)->akey;
  v14 = v12;
  v15 = Concat_5224608("charactor/b/", Fname);
  Prefab_16624656 = LoadPrefab_16624656(v14, akey, v15, Fname);
  v18 = op_Inequality(Prefab_16624656, 0, 0);
  v20 = *form;
  if (!v18)
  {
    v20->akey = nbLoadStartUnitPack(61);
    (*form)->read_minor = 61;
    v65 = (*form)->read_minor;
    v50 = sub_8D3950(s32, &v65);
    v52 = Format("battle/voice/devil_0x{0:x3}", v50, 0);
    v53 = (*form)->akey;
    LoadSound(v53, v52);
    return 0;
  }
  v21 = v20->akey;
  LoadKeys(4, v21, 0);
  transform = get_transform(kernelObject->btldevil, 0);
  v26 = Instantiate_object__425664(Prefab_16624656, transform, 0);
  (*form)->modelobj = v26;
  v27 = get_transform(v26, 0);
  Child = GetChild(v27, 0);
  rotation = get_rotation(Child);
  sub_1A1CAE0(&rotation.x, 0);
  v29 = *form;
  v29->modelrot.x = v30;
  *&v29->modelrot.y = 0;
  gameObject = get_gameObject(Child);
  Component_object = GetComponent_object_(gameObject);
  (*form)->modelanm = Component_object;
  v33 = get_gameObject(Child);
  v34 = AddComponent_object_(v33);
  SetAnimator(v34, Component_object, 0);
  v36 = mdlSetHD(v26, 1, 0, 15);
  SetForm(v36, *form, 0);
  SetFrameAnime(v36, 1);
  DanteBattleVoiceInit(read_minor, v26);
  switch (ChkUseMarukage(read_minor))
  {
    case -1:
      goto LABEL_40;
    case 0:
      goto LABEL_56;
    case 1:
      v39 = "charactor/b/common/battle_chara_shadow";
      v40 = get_asset_bc();
      v41 = LoadPrefab_16624656(v40, "common", v39, "battle_chara_shadow");
      v42 = get_transform(v26, 0);
      v44 = get_transform(v42, 0);
      v45 = Instantiate_object__425664(v41, v44, 0);
      v46 = get_gameObject(Child);
      SetModelObject(v36, v46, v45);
LABEL_40:
      v47 = v36;
      v48 = v26;
      v49 = 14;
      goto LABEL_58;
    case 2:
      v55 = "charactor/b/common/battle_chara_shadow";
      v56 = get_asset_bc();
      v57 = LoadPrefab_16624656(v56, "common", v55, "battle_chara_shadow");
      v58 = get_transform(v26, 0);
      v60 = get_transform(v58, 0);
      v61 = Instantiate_object__425664(v57, v60, 0);
      v62 = get_gameObject(Child);
      SetModelObject(v36, v62, v61);
LABEL_56:
      if (((*form)->stat & 0x100) != 0)
      {
        v49 = 13;
        v47 = v36;
        v48 = v26;
LABEL_58:
        SetLayerAll2(v47, v48, v49);
      }
      break;
    default:
      break;
  }
  if ((v5 & ~((*form)->anime >> 9) & 1) != 0)
  {
    IsBattleQueue = IsBattleQueue(v36);
    SetTransparent(v36, 0, 0.0, IsBattleQueue, 0);
  }
  return 1;
}

// 0x1593d40
void nbCheckLoadUnitPackFile_Boot(void) {
  u64 *v3;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v5;
  u64 *v6;
  UnityEngine_Transform_o *v7;
  UnityEngine_Transform_o *v8;
  u64 *v9;
  UnityEngine_Transform_o *v10;
  UnityEngine_Transform_o *v11;
  u64 *v14;
  UnityEngine_Transform_o *v15;
  UnityEngine_Transform_o *v16;
  u64 *v17;
  UnityEngine_Transform_o *v18;
  UnityEngine_Transform_o *v19;
  u64 *v20;
  UnityEngine_Transform_o *v21;
  UnityEngine_Transform_o *v22;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *Fname;
  AssetBundleCtrl_o *v29;
  System_String_o *BootLoad_akey;
  System_String_o *v32;
  Il2CppObject *Prefab_16624656;
  UnityEngine_Transform_o *v35;
  Il2CppObject *v36;

  SetActive(kernelObject->btldevil, 1, 0);
  v3 = Allocate(UnityEngine_GameObject);
  _ctor(v3, "Cache", 0);
  transform = get_transform(v3, 0);
  v5 = get_transform(kernelObject->btldevil, 0);
  set_parent(transform, v5);
  v6 = Allocate(UnityEngine_GameObject);
  _ctor(v6, "B", 0);
  v7 = get_transform(v6, 0);
  v8 = get_transform(v3, 0);
  set_parent(v7, v8);
  v9 = Allocate(UnityEngine_GameObject);
  _ctor(v9, "P", 0);
  v10 = get_transform(v9, 0);
  v11 = get_transform(v6, 0);
  set_parent(v10, v11);
  nbCache_B_P = v9;
  v14 = Allocate(UnityEngine_GameObject);
  _ctor(v14, "Cache", 0);
  v15 = get_transform(v14, 0);
  v16 = get_transform(
          kernelObject->ObjectsFolder3D,
          0);
  set_parent(v15, v16);
  v17 = Allocate(UnityEngine_GameObject);
  _ctor(v17, "B", 0);
  v18 = get_transform(v17, 0);
  v19 = get_transform(v14, 0);
  set_parent(v18, v19);
  nbCache_Fld_B = v17;
  v20 = Allocate(UnityEngine_GameObject);
  _ctor(v20, "F", 0);
  v21 = get_transform(v20, 0);
  v22 = get_transform(v14, 0);
  set_parent(v21, v22);
  nbCache_Fld_F = v20;
  BootLoad_akey = nbLoadStartUnitPack(0);
  asset_bc = get_asset_bc();
  if (IsLoad(asset_bc, BootLoad_akey))
  {
    Fname = GetFname(0);
    v29 = get_asset_bc();
    v32 = Concat_5224608("charactor/b/", Fname);
    Prefab_16624656 = LoadPrefab_16624656(v29, BootLoad_akey, v32, Fname);
    v35 = get_transform(v9, 0);
    v36 = Instantiate_object__425664(Prefab_16624656, v35, 0);
    set_name(v36, "boot_0x00");
    SetActive(v36, 0, 0);
  }
}

// 0x1594e40
s32 nbCheckLoadUnitPackFile_MSE(nbFormation_t **form, s32 major, s32 minor, bool semiflg) {
  AssetBundleCtrl_o *asset_bc;
  System_String_o *akey;
  s32 mse_nextidx;
  s32 KeysMSE;

  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, (*form)->akey, 0))
    return 0;
  akey = (*form)->akey;
  KeysMSE = LoadKeysMSE(akey, mse_nextidx);
  mse_nextidx = KeysMSE;
  if (mse_nextidx != -1)
    return 0;
  mse_nextidx = 0;
  return 1;
}

// 0x1594fc0
s32 nbCheckLoadUnitPackFile_Model(nbFormation_t **form, s32 major, s32 minor, bool semiflg) {
  _BOOL4 v5;
  s32 read_minor;
  System_String_o *Fname;
  nbFormation_t_o *v10;
  s32 asyncPhase;
  System_String_o *v12;
  s32 result;
  AssetBundleCtrl_o *v14;
  System_String_o *akey;
  AssetBundleCtrl_o *v16;
  System_String_o *v17;
  UnityEngine_AssetBundleRequest_o *PrefabAsync;
  nbFormation_t_o *v19;
  s32 v20;
  UnityEngine_Transform_o *v22;
  System_String_o *v23;
  UnityEngine_Object_o *v25;
  UnityEngine_Transform_o *v27;
  UnityEngine_GameObject_o *v28;
  Il2CppObject *v29;
  nbFormation_t_o *v30;
  nbFormation_t_o *v31;
  f32 z;
  nbFormation_t_o *v33;
  s32 v34;
  AssetBundleCtrl_o *v35;
  UnityEngine_Object_o *readObject;
  Il2CppObject *v38;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v42;
  UnityEngine_Transform_o *v43;
  UnityEngine_Transform_o *Child;
  nbFormation_t_o *v45;
  f32 v46;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *v49;
  Il2CppObject *v50;
  FieldChrHD_o *v52;
  System_String_o *v55;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_Component_o *v58;
  UnityEngine_Transform_o *v60;
  Il2CppObject *v61;
  UnityEngine_GameObject_o *v62;
  FieldChrHD_o *v63;
  UnityEngine_GameObject_o *v64;
  s32 v65;
  nbFormation_t_o *v66;
  UnityEngine_Object_o *asset;
  UnityEngine_Object_o *v68;
  System_String_o *v69;
  AssetBundleCtrl_o *v70;
  Il2CppObject *v71;
  UnityEngine_Component_o *v72;
  UnityEngine_Transform_o *v74;
  Il2CppObject *v75;
  UnityEngine_GameObject_o *v76;
  s32 IsBattleQueue;
  UnityEngine_Quaternion_o rotation;

  v5 = semiflg;
  *&rotation.x = 0;
  *&rotation.z = 0;
  read_minor = (*form)->read_minor;
  Fname = GetFname(read_minor);
  v10 = *form;
  asyncPhase = (*form)->asyncPhase;
  v12 = Fname;
  if (asyncPhase)
  {
    result = 0;
    if (asyncPhase <= 2)
      goto LABEL_8;
LABEL_34:
    if (asyncPhase == 3)
    {
      if (get_isDone(v10->aReq))
      {
        v66 = *form;
        asset = get_asset((*form)->aReq, 0);
        if (asset)
        {
          if (asset->klass == UnityEngine_GameObject)
            v68 = asset;
          else
            v68 = 0;
        }
        else
        {
          v68 = 0;
        }
        v66->readObject = v68;
        v19 = *form;
        result = 0;
        v20 = 100;
        goto LABEL_69;
      }
      return 0;
    }
    if (asyncPhase != 100)
      return result;
    readObject = v10->readObject;
    if (op_Inequality(readObject, 0, 0))
    {
      v38 = (*form)->readObject;
      transform = get_transform(kernelObject->btldevil, 0);
      v42 = Instantiate_object__425664(v38, transform, 0);
      (*form)->modelobj = v42;
      v43 = get_transform(v42, 0);
      Child = GetChild(v43, 0);
      rotation = get_rotation(Child);
      sub_1A1CAE0(&rotation.x, 0);
      v45 = *form;
      v45->modelrot.x = v46;
      *&v45->modelrot.y = 0;
      gameObject = get_gameObject(Child);
      Component_object = GetComponent_object_(gameObject);
      (*form)->modelanm = Component_object;
      v49 = get_gameObject(Child);
      v50 = AddComponent_object_(v49);
      SetAnimator(v50, Component_object, 0);
      v52 = mdlSetHD(v42, 1, 0, 15);
      SetForm(v52, *form, 0);
      SetFrameAnime(v52, 1);
      DanteBattleVoiceInit(read_minor, v42);
      Dai2keitai(read_minor);
      switch (ChkUseMarukage(read_minor))
      {
        case -1:
          goto LABEL_60;
        case 0:
          goto LABEL_77;
        case 1:
          v55 = "charactor/b/common/battle_chara_shadow";
          asset_bc = get_asset_bc();
          Prefab_16624656 = LoadPrefab_16624656(asset_bc, "common", v55, "battle_chara_shadow");
          v58 = get_transform(v42, 0);
          v60 = get_transform(v58, 0);
          v61 = Instantiate_object__425664(Prefab_16624656, v60, 0);
          v62 = get_gameObject(Child);
          SetModelObject(v52, v62, v61);
LABEL_60:
          v63 = v52;
          v64 = v42;
          v65 = 14;
          goto LABEL_79;
        case 2:
          v69 = "charactor/b/common/battle_chara_shadow";
          v70 = get_asset_bc();
          v71 = LoadPrefab_16624656(v70, "common", v69, "battle_chara_shadow");
          v72 = get_transform(v42, 0);
          v74 = get_transform(v72, 0);
          v75 = Instantiate_object__425664(v71, v74, 0);
          v76 = get_gameObject(Child);
          SetModelObject(v52, v76, v75);
LABEL_77:
          if (((*form)->stat & 0x100) != 0)
          {
            v65 = 13;
            v63 = v52;
            v64 = v42;
LABEL_79:
            SetLayerAll2(v63, v64, v65);
          }
          break;
        default:
          break;
      }
      if ((v5 & ~((*form)->anime >> 9) & 1) != 0)
      {
        IsBattleQueue = IsBattleQueue(v52);
        SetTransparent(v52, 0, 0.0, IsBattleQueue, 0);
      }
    }
    (*form)->readObject = 0;
    (*form)->aReq = 0;
    goto LABEL_83;
  }
  if ((v10->stat & 0x100) == 0)
  {
LABEL_33:
    v10->asyncPhase = 1;
    v10 = *form;
    asyncPhase = (*form)->asyncPhase;
    result = 0;
    if (asyncPhase <= 2)
    {
LABEL_8:
      if (asyncPhase != 1)
      {
        if (asyncPhase != 2)
          return result;
        v14 = get_asset_bc();
        akey = (*form)->akey;
        v16 = v14;
        v17 = Concat_5224608("charactor/b/", v12);
        PrefabAsync = LoadPrefabAsync(v16, akey, v17, v12);
        result = 0;
        v10->aReq = PrefabAsync;
        v19 = *form;
        v20 = 3;
        goto LABEL_69;
      }
      v35 = get_asset_bc();
      if (IsLoad(v35, (*form)->akey, 0))
      {
        v19 = *form;
        result = 0;
        v20 = 2;
LABEL_69:
        v19->asyncPhase = v20;
        return result;
      }
      return 0;
    }
    goto LABEL_34;
  }
  v22 = get_transform(nbCache_B_P, 0);
  v23 = Concat_5224608(v12, "(Clone)", 0);
  v25 = Find(v22, v23, 0);
  if (!op_Inequality(v25, 0, 0))
  {
    v10 = *form;
    goto LABEL_33;
  }
  v27 = get_transform(kernelObject->btldevil, 0);
  set_parent(v25, v27);
  v28 = get_gameObject(v25);
  SetActive(v28, 1, 0);
  (*form)->modelobj = v28;
  v29 = GetComponent_object_(v28);
  v30 = GetForm(v29);
  v31 = *form;
  z = v30->modelrot.z;
  *&v31->modelrot.x = *&v30->modelrot.x;
  v31->modelrot.z = z;
  (*form)->modelanm = v30->modelanm;
  SetForm(v29, *form, 0);
  v33 = *form;
  if ((v5 & ~((*form)->anime >> 9) & 1) == 0)
    goto LABEL_84;
  v34 = IsBattleQueue(v29);
  SetTransparent(v29, 0, 0.0, v34, 0);
LABEL_83:
  v33 = *form;
LABEL_84:
  v33->asyncPhase = 0;
  return 1;
}

// 0x1594fa0
void nbCheckLoadUnitPackFile_ModelInit(nbFormation_t **form) {
  (*form)->asyncPhase = 0;
  (*form)->aReq = 0;
}

// 0x1593720
void nbDecodePackData(void *p, s32 major, s32 minor) {
  ;
}

// 0x1594260
void nbDestroyCache(void) {
  UnityEngine_Transform_o *transform;
  s64 *Enumerator;
  UnityEngine_Component_o *v5;
  UnityEngine_Component_o *v6;
  UnityEngine_Component_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  UnityEngine_Object_o *v14;
  s64 *Interface;
  u64 v16[3];

  transform = get_transform(nbCache_B_P, 0);
  Enumerator = GetEnumerator(transform);
  while ((sub_69BB0(0, System_Collections_IEnumerator, Enumerator) & 1) != 0)
  {
    v5 = sub_69A60(1u, System_Collections_IEnumerator, Enumerator);
    v6 = v5;
    if (v5)
    {
      klass = v5->klass;
      if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Transform)
      {
        sub_8FC2C0(klass->_1.element_class, UnityEngine_Transform, v16);
        if ((v16[0] & 1) != 0)
          v9 = v16[2];
        else
          v9 = v16 + 1;
        v10 = sub_8C4940(v9);
      }
    }
    gameObject = get_gameObject(v5);
    name = get_name(gameObject);
    if (op_Inequality(name, "boot_0x00", 0))
    {
      v14 = get_gameObject(v6);
      Destroy_27360000(v14);
    }
  }
  Interface = QueryInterface(Enumerator, System_IDisposable);
  if (Interface)
    sub_22F10(0, System_IDisposable, Interface);
}

// 0x15945d0
void *nbFldCache_ToField(char *fld_name) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v6;
  Il2CppObject *v9;
  UnityEngine_Transform_o *v12;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v16;
  s64 *Enumerator;
  UnityEngine_Component_o *v18;
  UnityEngine_Component_c *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  UnityEngine_Object_o *v24;
  s64 *Interface;
  u64 v26[3];

  transform = get_transform(nbCache_Fld_B, 0);
  v6 = Find(transform, fld_name, 0);
  if (op_Inequality(v6, 0, 0))
  {
    v9 = Concat_5224608("バトル背景キャッシュ有 ", fld_name);
    Log(v9, 0);
    v12 = get_transform(kernelObject->ObjectsFolder3D, 0);
    set_parent(v6, v12);
    gameObject = get_gameObject(v6);
    SetActive(gameObject, 1, 0);
    return get_gameObject(v6);
  }
  else
  {
    v16 = get_transform(nbCache_Fld_B, 0);
    Enumerator = GetEnumerator(v16);
    while ((sub_69BB0(0, System_Collections_IEnumerator, Enumerator) & 1) != 0)
    {
      v18 = sub_69A60(1u, System_Collections_IEnumerator, Enumerator);
      if (v18)
      {
        klass = v18->klass;
        if (v18->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Transform)
        {
          sub_8FC2C0(klass->_1.element_class, UnityEngine_Transform, v26);
          if ((v26[0] & 1) != 0)
            v21 = v26[2];
          else
            v21 = v26 + 1;
          v22 = sub_8C4940(v21);
        }
      }
      v24 = get_gameObject(v18);
      Destroy_27360000(v24);
    }
    Interface = QueryInterface(Enumerator, System_IDisposable);
    if (Interface)
      sub_22F10(0, System_IDisposable, Interface);
    return 0;
  }
}

// 0x1594ac0
void *nbFldCache_ToField_F(char *fld_name) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v6;
  Il2CppObject *v9;
  UnityEngine_Transform_o *v12;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v16;
  s64 *Enumerator;
  UnityEngine_Component_o *v18;
  UnityEngine_Component_c *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  UnityEngine_Object_o *v24;
  s64 *Interface;
  u64 v26[3];

  transform = get_transform(nbCache_Fld_F, 0);
  v6 = Find(transform, fld_name, 0);
  if (op_Inequality(v6, 0, 0))
  {
    v9 = Concat_5224608("エンカウント前の背景キャッシュ有 ", fld_name);
    Log(v9, 0);
    v12 = get_transform(kernelObject->ObjectsFolder3D, 0);
    set_parent(v6, v12);
    gameObject = get_gameObject(v6);
    SetActive(gameObject, 1, 0);
    return get_gameObject(v6);
  }
  else
  {
    v16 = get_transform(nbCache_Fld_F, 0);
    Enumerator = GetEnumerator(v16);
    while ((sub_69BB0(0, System_Collections_IEnumerator, Enumerator) & 1) != 0)
    {
      v18 = sub_69A60(1u, System_Collections_IEnumerator, Enumerator);
      if (v18)
      {
        klass = v18->klass;
        if (v18->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Transform)
        {
          sub_8FC2C0(klass->_1.element_class, UnityEngine_Transform, v26);
          if ((v26[0] & 1) != 0)
            v21 = v26[2];
          else
            v21 = v26 + 1;
          v22 = sub_8C4940(v21);
        }
      }
      v24 = get_gameObject(v18);
      Destroy_27360000(v24);
    }
    Interface = QueryInterface(Enumerator, System_IDisposable);
    if (Interface)
      sub_22F10(0, System_IDisposable, Interface);
    return 0;
  }
}

// 0x1593500
void nbFreeFlyUnitPack(nbMainProcessData_t **data) {
  AssetBundleCtrl_o *asset_bc;

  if (!IsNullOrEmpty((*data)->flyh_akey, 0))
  {
    asset_bc = get_asset_bc();
    UnloadAB(asset_bc, (*data)->flyh_akey, 0);
    (*data)->flyh_akey = "";
  }
}

// 0x1593460
s32 nbLoadCheckFlyUnitPack(nbMainProcessData_t **data) {
  AssetBundleCtrl_o *asset_bc;

  if ((*data)->encno != 333)
    return 1;
  asset_bc = get_asset_bc();
  return IsLoad(asset_bc, (*data)->flyh_akey, 0);
}

// 0x1593270
void nbLoadFlyUnitPack(nbMainProcessData_t **data) {
  nbMainProcessData_t_o *v4;

  (*data)->flyh_akey = "";
  if ((*data)->encno == 333 && IsNullOrEmpty((*data)->flyh_akey, 0))
  {
    v4 = *data;
    v4->flyh_akey = nbLoadStartUnitPack(255);
  }
}

// 0x1593320
char *nbLoadStartUnitPack(s32 unitid) {
  System_String_o *Akey;
  AssetBundleCtrl_o *asset_bc;
  DlcFileCtr_o *dlc;
  AssetBundleCtrl_o *v8;

  Akey = GetAkey(unitid);
  if (Equals_5234480(Akey, "dvl0xc0d"))
  {
    asset_bc = get_asset_bc();
    dlc = get_dlc(asset_bc);
    Load(dlc, Akey, 2, Akey, 0);
  }
  else
  {
    v8 = get_asset_bc();
    Load(v8, Akey, Akey, 0);
  }
  _Add(unitAB_List, Akey);
  return Akey;
}

// 0x15935c0
void nbLoadUnitPackFile(nbFormation_t **form, s32 major, s32 minor) {
  nbFormation_t_o *v6;

  v6 = *form;
  v6->akey = nbLoadStartUnitPack(minor, *&major);
  (*form)->read_minor = minor;
}

// 0x1594520
void nbNoDestroy_MoveCache_Field_B(void *modelobj) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v6;

  transform = get_transform(modelobj, 0);
  v6 = get_transform(nbCache_Fld_B, 0);
  set_parent(transform, v6);
  SetActive(modelobj, 0, 0);
}

// 0x15949c0
bool nbNoDestroy_MoveCache_Field_F(void *modelobj) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v6;

  if (!Cache_Field_F_ModeOn)
    return 0;
LABEL_6:
  Cache_Field_F_ModeOn = 0;
  transform = get_transform(modelobj, 0);
  v6 = get_transform(nbCache_Fld_F, 0);
  set_parent(transform, v6);
  SetActive(modelobj, 0, 0);
  return 1;
}

// 0x1594950
void nbNoDestroy_MoveCache_Field_F_ModeOn(void) {
  Cache_Field_F_ModeOn = 1;
}

// 0x1594160
void nbNoDestroy_MoveCache_Party(void *modelobj) {
  Il2CppObject *Component_object;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v8;

  Component_object = GetComponent_object_(modelobj);
  if (op_Inequality(Component_object, 0, 0))
    RetTransparent(Component_object, 0);
  transform = get_transform(modelobj, 0);
  v8 = get_transform(nbCache_B_P, 0);
  set_parent(transform, v8);
  SetActive(modelobj, 0, 0);
}

// 0x15935a0
void nbSetUnitPackFileHandle(nbFormation_t **form, NB_FILEHANDLE_T *fh) {
  if (!(*form)->packh)
    (*form)->packh = fh;
}
