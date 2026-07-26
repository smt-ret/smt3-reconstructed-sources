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
    IsLoad(0, 0);
    GetFname(0);
    LoadPrefab_16624656(0, 0, 0, 0);
    nbLoadStartUnitPack(0);
    LoadSound(0, 0);
    LoadKeys(0, 0, 0);
    SetAnimator(0, 0, 0);
    mdlSetHD(0, 0, 0, 0);
    SetForm(0);
    SetFrameAnime(0, 0);
    DanteBattleVoiceInit(0, 0);
    ChkUseMarukage(0);
    SetModelObject(0, 0, 0);
    SetLayerAll2(0, 0, 0);
    IsBattleQueue(0);
    SetTransparent(0, 0, 0);
    return 0;
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
  _ctor(v3, StringLiteral_21669, 0);
  transform = get_transform(v3, 0);
  v5 = get_transform(kernelObject->btldevil, 0);
  set_parent(transform, v5);
  v6 = Allocate(UnityEngine_GameObject);
  _ctor(v6, StringLiteral_4907, 0);
  v7 = get_transform(v6, 0);
  v8 = get_transform(v3, 0);
  set_parent(v7, v8);
  v9 = Allocate(UnityEngine_GameObject);
  _ctor(v9, StringLiteral_3237, 0);
  v10 = get_transform(v9, 0);
  v11 = get_transform(v6, 0);
  set_parent(v10, v11);
  nbCache_B_P = v9;
  v14 = Allocate(UnityEngine_GameObject);
  _ctor(v14, StringLiteral_21669, 0);
  v15 = get_transform(v14, 0);
  v16 = get_transform(
          kernelObject->ObjectsFolder3D,
          0);
  set_parent(v15, v16);
  v17 = Allocate(UnityEngine_GameObject);
  _ctor(v17, StringLiteral_4907, 0);
  v18 = get_transform(v17, 0);
  v19 = get_transform(v14, 0);
  set_parent(v18, v19);
  nbCache_Fld_B = v17;
  v20 = Allocate(UnityEngine_GameObject);
  _ctor(v20, StringLiteral_703, 0);
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
    v32 = Concat_5224608(StringLiteral_5253, Fname);
    Prefab_16624656 = LoadPrefab_16624656(v29, BootLoad_akey, v32, Fname);
    v35 = get_transform(v9, 0);
    v36 = Instantiate_object__425664(Prefab_16624656, v35, 0);
    set_name(v36, StringLiteral_12341);
    SetActive(v36, 0, 0);
  }
}

// 0x1594e40
s32 nbCheckLoadUnitPackFile_MSE(nbFormation_t **form, s32 major, s32 minor, bool semiflg) {
  AssetBundleCtrl_o *asset_bc;
  System_String_o *akey;
  s32 mse_nextidx;
  s32 KeysMSE;
  nbUnitPack_c *v13;
  struct nbUnitPack_StaticFields *static_fields;

  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, (*form)->akey, 0))
    return 0;
  akey = (*form)->akey;
  KeysMSE = LoadKeysMSE(akey, mse_nextidx);
  mse_nextidx = KeysMSE;
  static_fields = v13->static_fields;
  if (static_fields->mse_nextidx != -1)
    return 0;
  static_fields->mse_nextidx = 0;
  return 1;
}

// 0x1594fc0
s32 nbCheckLoadUnitPackFile_Model(nbFormation_t **form, s32 major, s32 minor, bool semiflg) {
    GetFname(0);
    SetAnimator(0, 0, 0);
    mdlSetHD(0, 0, 0, 0);
    SetForm(0);
    SetFrameAnime(0, 0);
    DanteBattleVoiceInit(0, 0);
    Dai2keitai(0);
    ChkUseMarukage(0);
    LoadPrefab_16624656(0, 0, 0, 0);
    SetModelObject(0, 0, 0);
    SetLayerAll2(0, 0, 0);
    IsBattleQueue(0);
    SetTransparent(0, 0, 0);
    LoadPrefabAsync(0, 0, 0, 0);
    IsLoad(0, 0);
    GetForm(0);
    return 0;
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
}

// 0x15945d0
void *nbFldCache_ToField(char *fld_name) {
    return 0;
}

// 0x1594ac0
void *nbFldCache_ToField_F(char *fld_name) {
    return 0;
}

// 0x1593500
void nbFreeFlyUnitPack(nbMainProcessData_t **data) {
  AssetBundleCtrl_o *asset_bc;

  if (!IsNullOrEmpty((*data)->flyh_akey, 0))
  {
    asset_bc = get_asset_bc();
    UnloadAB(asset_bc, (*data)->flyh_akey, 0);
    (*data)->flyh_akey = StringLiteral_416;
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

  (*data)->flyh_akey = StringLiteral_416;
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
  if (Equals_5234480(Akey, StringLiteral_4869))
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
  struct nbUnitPack_StaticFields *static_fields;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v6;

  static_fields = nbUnitPack->static_fields;
  if (!static_fields->Cache_Field_F_ModeOn)
    return 0;
  static_fields->Cache_Field_F_ModeOn = 0;
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
