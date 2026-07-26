#include "types.h"

typedef struct AnimChecker AnimChecker;
typedef struct AnimCheckerPMV AnimCheckerPMV;
typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct EventEMsgData EventEMsgData;
typedef struct FieldChrHD FieldChrHD;
typedef struct btlKutiManager btlKutiManager;
typedef struct datUnitVisual_s datUnitVisual_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelFileTable_t dds3ModelFileTable_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3PathBasicControl_t dds3PathBasicControl_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct evtKutiManager evtKutiManager;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct evtUnitHandle_t_ActionDelegate evtUnitHandle_t_ActionDelegate;
typedef struct fldTitleName fldTitleName;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct sdf3DLightParallelPacket_t sdf3DLightParallelPacket_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

static u32 EVTFLAG;
static sdfVector4_t r_v;
static sdfVector4_t r_v2;
static sdfVector4_t r_cen;
static sdfVector4_t r_w;
static sdfVector4_t r_w2;
static char *_match_name;
static char *_match_key;

void AddLoad(dds3Basic_t *basic, char *key, s32 major, s32 minor, char *name, void *obj, s32 type, char *dvl);
char *AddModel(dds3Basic_t *basic, void *obj, s32 major, s32 minor);
void AttachHD(void *obj, dds3Basic_t *basic, char *name, s32 cb);
bool Contains(btlKutiManager *this);
void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
void FromRotation(f32 aAngle);
u8 Get(s32 id);
void *GetAnimator(void *obj);
void GetBaseAmbientRGB(evtUnitHandle_t **h);
void GetBaseLightDir(evtUnitHandle_t **h);
void GetBaseLightRGB(evtUnitHandle_t **h);
EventEMsgData *GetData(char *key);
void *GetGameObject_PartName(void *rootobj, char *findname);
evtKutiManager *GetKutiManager(void);
f32 GetSplineLength(dds3PathBasicControl_t *path);
s32 GetTableIndex(char *key, char *name);
s32 IsBattleQueue(FieldChrHD *this);
bool IsDLC(void);
bool IsFinished(fldTitleName *this);
bool IsLoad(AssetBundles *this, char *key);
bool IsSpeakStart(void);
bool IsSpeaking(void);
bool IsfldSetChar(char *name);
void Lerp(f32 aRatio);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Mult(void);
void NoFindHelper0(char *Owner_name, char *Light_name, sdfVector4_t *pos, sdfVector4_t *lpos);
char *ReplaceDvlKeyName(char *dvl, s32 *minor);
void RetTransparent(void *obj);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__GET_ROW2(void);
f32 SDF_VU0__INNERPRODUCT(void);
void SDF_VU0__LOADIDENTITYVECTOR(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SCALEVECTOR_B(f32 v);
void SDF_VU0__SETVECTOR_Y(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STORE_ROW2(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
u32 SDF_VU0__dds3ColorFtoI(f32 ratio);
void SDF_VU0__dds3ColorItoF(u32 rgba);
void SetCharacterType(AnimChecker *this, s32 type);
void SetFrame(AnimCheckerPMV *this, s32 frame, bool linkage);
void SetMouthMotion(AnimChecker *this, s32 motion);
void SetTransparent(void *obj, u32 rgba, f32 alfrgb);
void SetUnit(evtKutiManager *this, evtUnitHandle_t *h);
void SetUpDateDI(FieldChrHD *this);
void ToMatrix(void);
void UnitAnime(evtUnitHandle_t **h);
void UnloadModel(char *key, bool ul);
void UpdateDying(void *plyobj);
s32 datCheckDying(datUnitWork_t *work);
void dds3AddPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3AddRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
dds3Basic_t *dds3GetActiveScene(void);
dds3Basic_t *dds3GetControlScene(void);
void *dds3ObjectBaseGetModelHandle(dds3Basic_t **pObjectBasic);
void dds3PathBasicControlAlterMode(dds3PathBasicControl_t **pControl, u32 mode);
void dds3PathBasicControlGetPos(dds3PathBasicControl_t **pControl);
f32 dds3PathBasicControlGetRatio(dds3PathBasicControl_t **pControl);
void dds3PathBasicControlGetRot(dds3PathBasicControl_t **pControl);
u32 dds3PathBasicControlNextStep(dds3PathBasicControl_t **pControl);
void dds3PathBasicControlSetRatio(dds3PathBasicControl_t **pControl, f32 ratio);
void dds3PathBasicFreeControl(dds3PathBasicControl_t **pControl);
dds3PathBasicControl_t *dds3PathBasicMakeControl(dds3Basic_t **pBasic);
void dds3RotationArc(void);
s32 dds3SceneBasicExistBasicFromType(dds3Basic_t **scene, s32 type, dds3Basic_t *target);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
s32 evtCheckMoveEnd(evtUnitHandle_t **h);
void evtGetUnitDirVector(evtUnitHandle_t **h);
void evtSetUnitExMotion(evtUnitHandle_t **h, s32 group, s32 motion, s32 before, s32 smooth, s32 mode);
void evtSetUnitLightAndAmbient(evtUnitHandle_t **h, u32 frame, u32 lrgb, u32 argb);
void evtSetUnitLightDir(evtUnitHandle_t **h, s32 frame);
void evtUnitHandle_t__Clear(evtUnitHandle_t *this);
s32 evtUnitMoveType0(evtUnitHandle_t **h);
s32 evtUnitMoveTypePathTrace(evtUnitHandle_t **h);
s32 evtUnitRotationQuat(evtUnitHandle_t **h, sdfVector4_t rot, f32 radio);
s32 evtUnitRotationTarget(evtUnitHandle_t **h, sdfVector4_t pos, f32 radio);
void evtUpdateEx_UnitLightColorAfter(evtUnitHandle_t **hunit);
s8 fldProcCheckFlag(u32 flag);
void fldSetCharAdd(char *name, void *obj);
void fldSetCharClr(void);
void fldSetCharDel(char *name);
void mdlAnimSetBattle(evtUnitHandle_t **h, s32 motion);
s32 mdlChkMotionEndBattle(evtUnitHandle_t *h, void *chr_trans, void *mAnimator);
s32 mdlChkMotionEndBattleDying(evtUnitHandle_t *h, void *chr_trans, void *mAnimator);
s32 mdlChkMotionEndForUnity(evtUnitHandle_t **h, s32 index);
u32 mdlGetColor(dds3ModelHandle_t **aHandle);
s32 mdlGetMotionFrameForUnity_26969536(evtUnitHandle_t **h, s32 index);
s32 mdlGetMotionMinorNumForUnity(evtUnitHandle_t **h, s32 layer);
void mdlMotionStopKutiForUnity(evtUnitHandle_t **h, s32 index, bool sw);
void mdlSetColor(dds3ModelHandle_t **aHandle, u32 aColor);
FieldChrHD *mdlSetHD(void *obj, s32 mode, evtUnitHandle_t *hunit, s32 layer);
void mdlSetLight(dds3ModelHandle_t **HNDL, sdf3DLightParallelPacket_t *LIGHT);
void mdlSetMotionSpeedAnimator(void *mAnimator, f32 speed);
void mdlSetMotionSpeedForUnity(evtUnitHandle_t **h, s32 layer, f32 speed);
void mdlSmoothLoopMotionForUnity(evtUnitHandle_t **h, s32 layer, s32 motion, s32 before, s32 wait, bool btl);
void mdlSmoothSingleMotionForUnity(evtUnitHandle_t **h, s32 layer, s32 motion, s32 before, s32 wait, bool btl);
nbMainProcessData_t *nbGetMainProcessData(void);
datUnitVisual_t *nbGetUnitVisual(datUnitWork_t *work);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);

// 0x19505e0
void AttachModel(dds3Basic_t *basic, s32 major, s32 minor) {
  s32 v5;
  struct dds3ModelFileKindTable_t_array *modelFileKindTable;
  struct dds3ModelFileIndex_t_array *indexTable;
  struct dds3ModelFileTableDef_t_array *modelFileTable;
  struct dds3ModelFileTable_t_array *fileTable;
  dds3ModelFileTable_t_o *v15;
  il2cpp_array_size_t max_length;
  u64 v18;
  dds3ModelFileIndex_t_o *v20;
  dds3ModelFileTable_t_o **m_Items;
  AssetBundleCtrl_o *asset_bc;
  bool IsLoad;
  struct System_String_o **v30;
  System_String_o *v31;
  dds3ModelFileTable_t_o *v36;
  System_String_o *fname;
  System_String_o *FileName;
  System_String_o *v40;
  System_String_o *akey;

  v5 = major;
  indexTable = modelFileKindTable->m_Items[v5]->indexTable;
  fileTable = modelFileTable->m_Items[v5]->fileTable;
  v15 = Allocate(dds3ModelFileTable_t);
  dds3ModelFileTable_t___ctor(v15);
  max_length = indexTable->max_length;
  if (v5 == 3 && minor == 29)
  {
    if (IsDLC())
      minor = 30;
    else
      minor = 29;
  }
  if (max_length >= 1)
  {
    v18 = 0;
    while (1)
    {
      v20 = indexTable->m_Items[v18];
      if (v20->major == v5)
      {
        if (minor == v20->minor)
        {
          if (!IsNullOrEmpty(fileTable->m_Items[v18]->akey))
            break;
        }
      }
      if (++v18 >= max_length)
        return;
    }
    m_Items = fileTable->m_Items;
    asset_bc = get_asset_bc();
    IsLoad = IsLoad(asset_bc, m_Items[v18]->akey);
    v30 = m_Items[v18];
    if (IsLoad)
    {
      v15->akey = v30[5];
      v31 = v30[6];
      v15->fname = v31;
      v15->modelFile = v30[3];
      v15->motionFile = v30[4];
      v15->texFile = v30[2];
      if (v5 == 6 && minor == 256)
        v15->fname = Concat_5224608(v31, StringLiteral_427);
      AddModel(basic, v15, v5, minor);
    }
    else
    {
      if (!IsNullOrEmpty(v30[2]))
      {
        if (Equals_5234480(m_Items[v18]->texFile, StringLiteral_1557))
          v5 = 6;
        if (Equals_5234480(m_Items[v18]->texFile, StringLiteral_16004))
          v5 = 2;
      }
      v36 = m_Items[v18];
      v15->akey = v36->akey;
      fname = v36->fname;
      v15->fname = fname;
      v15->modelFile = v36->modelFile;
      v15->motionFile = v36->motionFile;
      v15->texFile = v36->texFile;
      FileName = GetFileName(fname);
      v40 = FileName;
      if (minor == 256 && v5 == 6)
      {
        v40 = Concat_5224608(FileName, StringLiteral_427);
        v15->fname = Concat_5224608(v15->fname, StringLiteral_427);
      }
      akey = v15->akey;
      AddLoad(basic, akey, v5, minor, v40, v15, 1, 0);
    }
  }
}

// 0x195adc0
s32 AttachModel_26586560(dds3Basic_t *basic, char *key, char *chkname, char *name) {
    IsDLC();
    GetTableIndex(0, 0);
    Contains(0);
    IsLoad(0, 0);
    GetData(0);
    LoadPrefab_16624656(0, 0, 0, 0);
    IsfldSetChar(0);
    AttachHD(0, 0, 0, 0);
    GetAnimator(0);
    SetCharacterType(0, 0);
    UpdateDying(0);
    fldSetCharAdd(0, 0);
    ReplaceDvlKeyName(0, 0);
    AddModel(0, 0, 0, 0);
    AddLoad(0, 0, 0, 0, 0, 0, 0, 0);
    return 0;
}

// 0x195bcc0
void AttachModel_26590400(dds3Basic_t *basic, char *key, char *name) {
    LoadPrefab_16624656(0, 0, 0, 0);
    dds3ObjectBaseGetModelHandle(0);
    GetAnimator(0);
    SetCharacterType(0, 0);
    mdlSetHD(0, 0, 0, 0);
    SetUpDateDI(0);
    fldSetCharAdd(0, 0);
}

// 0x195c050
void DetachModel(dds3Basic_t *basic, bool ul) {
  UnityEngine_GameObject_o *v5;
  UnityEngine_Transform_o *transform;
  System_String_o *v7;
  s32 v8;
  UnityEngine_Object_o *Child;
  System_String_o *name;
  System_String_o *v12;
  System_String_o *v14;

  if (basic && basic->name)
  {
    v5 = Find(StringLiteral_4879, 0);
    transform = get_transform(v5, 0);
    v7 = ToUpper(basic->name, 0);
    if (get_childCount(transform) < 1)
    {
      v8 = 0;
    }
    else
    {
      v8 = 0;
      do
      {
        Child = GetChild(transform, v8);
        name = get_name(Child);
        if (Equals_5239888(name, v7, 5))
          break;
        ++v8;
      }
      while (v8 < get_childCount(transform));
    }
    if (v8 != get_childCount(transform))
    {
      v12 = basic->name;
      UnloadModel(v12, ul);
      v14 = basic->name;
      fldSetCharDel(v14);
    }
  }
}

// 0x195c1d0
void DetachModelAll(void) {
    fldSetCharClr();
}

// 0x19568b0
void GetBaseAmbientRGB(evtUnitHandle_t **h) {
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
}

// 0x1956a20
void GetBaseLightDir(evtUnitHandle_t **h) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
}

// 0x1956720
void GetBaseLightRGB(evtUnitHandle_t **h) {
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
}

// 0x1954e80
f32 GetSplineLength(dds3PathBasicControl_t *path) {
  f32 Ratio;
  f32 v3;
  dds3PathBasicControl_t_o *pControl;

  pControl = path;
  Ratio = dds3PathBasicControlGetRatio(&pControl);
  dds3PathBasicControlSetRatio(&pControl, 0.0);
  dds3PathBasicControlGetPos(&pControl);
  v3 = 0.05;
  do
  {
    SDF_VU0__COPYVECTOR_A_TO_B();
    dds3PathBasicControlSetRatio(&pControl, v3);
    dds3PathBasicControlGetPos(&pControl);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__COPYVECTOR_C_TO_A();
    v3 = v3 + 0.05;
  }
  while (v3 <= 1.0);
  dds3PathBasicControlSetRatio(&pControl, Ratio);
  return 0.0;
}

// 0x195bb10
s32 GetTableIndex(char *key, char *name) {
  System_String_o *v6;
  u64 *v8;

  v6 = ToUpper(key, 0);
  _match_key = v6;
  _match_name = ToUpper(name, 0);
  v8 = Allocate(System_Predicate_dds3ModelFileTable_t_);
  __ctor(
    v8,
    0,
    Method_evtUnitManager_MatchMFT2__);
  return FindIndex_dds3ModelFileTable_t_(eventModelFileTable2, v8);
}

// 0x1956b90
void MakeLightPacket(evtUnitHandle_t **h) {
  if (((*h)->Flag & 0x20000) == 0)
  {
    (*h)->PublicLightPacket = 0;
    if (((*h)->Flag & 0x40700) != 0)
    {
      SDF_VU0__dds3ColorItoF((*h)->NowLightRGB, 0);
      SDF_VU0__LOADVECTOR((*h)->NowLightDir, 0);
      SDF_VU0__dds3ColorItoF((*h)->NowAmbientRGB, 0);
      (*h)->PublicLightPacket = (*h)->PrivateLightPacket;
    }
  }
}

// 0x195bc20
bool MatchMFT2(dds3ModelFileTable_t *src) {
  if (IsNullOrEmpty(src->akey))
    return 0;
  return op_Equality(_match_name, src->modelFile, 0);
}

// 0x195c240
void PlayerUnitDisp(evtUnitHandle_t **h, bool sw) {
  struct dds3Basic_t_o *Owner;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *Child;
  struct dds3ModelHandle_t_o *Model;
  u32 stat;
  u32 v11;
  UnityEngine_Vector3_o localPosition;
  UnityEngine_Vector3_o v14;

  Owner = (*h)->Owner;
  if (Owner)
  {
    transform = get_transform(Owner->gameObject, 0);
    Child = GetChild(transform, 0);
    localPosition = get_localPosition(Child);
    v14.x = localPosition.x;
    v14.z = localPosition.z;
    v14.y = 1000.0;
    if (sw)
      v14.y = 0.0;
    set_localPosition(Child, v14);
    Model = (*h)->Model;
    if (Model)
    {
      stat = Model->stat;
      if (sw)
        v11 = stat & 0xFFFFFFFE;
      else
        v11 = stat | 1;
      Model->stat = v11;
    }
  }
}

// 0x1954f50
void UnitAnime(evtUnitHandle_t **h) {
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__SCALEVECTOR_B(0);
    SDF_VU0__ADDVECTOR();
    mdlGetColor(0);
    SDF_VU0__dds3ColorFtoI(0);
    mdlSetColor(0, 0);
    SDF_VU0__Retdds3ColorItoF(0, 0);
    IsBattleQueue(0);
    SetTransparent(0, 0, 0);
    RetTransparent(0);
    dds3GetActiveScene();
    dds3SceneBasicExistBasicFromType(0, 0, 0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    NoFindHelper0(0, 0, 0, 0);
    GetGameObject_PartName(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    dds3RotationArc();
    Lerp(0);
    ToMatrix();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__VECTOR_W_SET_ZERO();
    evtUpdateEx_UnitLightColorAfter(0);
    SDF_VU0__VECTOR_W_SET_ONE();
}

// 0x1954c50
s32 evtCheckMoveEnd(evtUnitHandle_t **h) {
  evtUnitHandle_t_o *v3;
  u32 MoveType;
  f32 Ratio;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  f32 *poseset;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  UnityEngine_Vector4_o v16;
  UnityEngine_Vector4_o v17;

  v3 = *h;
  MoveType = (*h)->MoveType;
  if (MoveType < 3)
  {
    x = v3->PosTarget.x;
    y = v3->PosTarget.y;
    z = v3->PosTarget.z;
    w = v3->PosTarget.w;
    poseset = v3->Owner->poseset;
    v11 = poseset[6];
    v12 = poseset[7];
    v14 = poseset[8];
    v13 = poseset[9];
    v16.x = x;
    v16.y = y;
    v16.z = z;
    v16.w = w;
    SDF_VU0__LOADVECTOR(v16);
    v17.x = v11;
    v17.y = v12;
    v17.z = v14;
    v17.w = v13;
    SDF_VU0__LOADVECTOR_B(v17);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__SETVECTOR_Y(0.0);
    if (SDF_VU0__GETLENGTH() <= 20.0)
      return 1;
  }
  else if (MoveType == 3)
  {
    Ratio = dds3PathBasicControlGetRatio(&v3->Path);
    if (((*h)->Flag & 4) != 0)
    {
      if (Ratio == 0.0)
        return 1;
    }
    else if (Ratio == 1.0)
    {
      return 1;
    }
  }
  return 0;
}

// 0x1957a10
s32 evtCheckUnitWait(evtUnitHandle_t **h) {
  evtUnitHandle_t_o *v3;
  s32 Stat;

  v3 = *h;
  Stat = (*h)->Stat;
  if (!(*h)->Stat)
    return 1;
  if (Stat != 2 || v3->Frame < 1)
    return 0;
  return mdlChkMotionEndForUnity(h, 0) != 0;
}

// 0x19577c0
evtUnitHandle_t *evtCreateUnitHandle(dds3Basic_t **owner, dds3ModelHandle_t *model) {
    evtUnitHandle_t__Clear(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    return 0;
}

// 0x1957910
s32 evtDeleteUnitHandle(evtUnitHandle_t **h) {
  dds3ModelHandle_t_o **p_Model;
  evtUnitHandle_t_o *v4;
  dds3PathBasicControl_t_o **p_Path;
  struct dds3PathBasicControl_t_o *Path;

  if (*h)
  {
    p_Model = &(*h)->Model;
    mdlSetLight(p_Model, 0);
    v4 = *h;
    if ((*h)->PrivateLightPacket)
    {
      v4->PrivateLightPacket = 0;
      v4 = *h;
    }
    Path = v4->Path;
    p_Path = &v4->Path;
    if (Path)
    {
      dds3PathBasicFreeControl(p_Path);
      (*h)->Path = 0;
    }
  }
  return 1;
}

// 0x1954d90
s32 evtGetNextMovePos(evtUnitHandle_t **h) {
  evtUnitHandle_t_o *v2;
  f32 Ratio;

  v2 = *h;
  if ((*h)->Stat != 1)
    return 0;
  if (v2->TargetType != 2)
    return 0;
  Ratio = dds3PathBasicControlGetRatio(&v2->Path);
  if (((*h)->Flag & 4) == 0)
  {
    if (Ratio == 1.0)
      return 0;
  }
  if (Ratio != 0.0)
  {
    dds3PathBasicControlSetRatio(
      &(*h)->Path,
      fminf(fmaxf(Ratio + (*h)->PathStep, 0.0), 1.0),
      0);
    dds3PathBasicControlGetPos(&(*h)->Path, 0);
    SDF_VU0__STOREVECTOR(&(*h)->PosTarget, 0);
    return 1;
  }
  return 0;
}

// 0x1954b80
void evtGetUnitDirVector(evtUnitHandle_t **h) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__STORE_ROW2(0);
    SDF_VU0__NORMALIZE();
    SDF_VU0__SCALEVECTOR(0);
}

// 0x1957570
evtUnitHandle_t *evtGetUnitHandle(s32 serial) {
    dds3GetActiveScene();
    dds3SearchSceneBasic(0, 0, 0);
    return 0;
}

// 0x19576c0
evtUnitHandle_t *evtGetUnitHandle2(dds3Basic_t *unit) {
    return 0;
}

// 0x19579c0
s32 evtGetUnitStat(evtUnitHandle_t **h) {
  return (*h)->Stat;
}

// 0x1956d60
void evtLinkExternalLightPacket(evtUnitHandle_t **h, sdf3DLightParallelPacket_t **packet) {
  (*h)->PublicLightPacket = *packet;
  (*h)->Flag |= 0x20000u;
}

// 0x1956c10
void evtLinkLightObjectBasic(evtUnitHandle_t **h, dds3Basic_t **light, s32 frame) {
  evtUnitHandle_t_o *v7;

  (*h)->BasicLight2 = (*h)->BasicLight;
  (*h)->BasicLight = *light;
  (*h)->Flag |= 0x40000u;
  (*h)->BasicLightAnimeFrame = 0;
  v7 = *h;
  if (frame)
  {
    v7->BasicLightAnimeMaxFrame = frame;
    (*h)->Flag |= 0x80000u;
    (*h)->Flag &= ~0x100000u;
  }
  else
  {
    v7->BasicLightAnimeMaxFrame = 0;
    (*h)->Flag &= 0xFFE7FFFF;
    (*h)->BasicLight2 = 0;
  }
}

// 0x1957ef0
void evtRunUnitKutiMotion(evtUnitHandle_t **h) {
  evtUnitHandle_t_o *v4;
  evtKutiManager_o *KutiManager;

  v4 = *h;
  set_animchecker(v4, -1);
  evtSetUnitExMotion(h, (*h)->KutiGroup, (*h)->KutiMotion, 0, 0, 1);
  KutiManager = GetKutiManager();
  if (op_Inequality(KutiManager, 0, 0))
    SetUnit(KutiManager, *h);
}

// 0x19593e0
s32 evtSetUnitAction(evtUnitHandle_t **h, evtUnitHandle_t_ActionDelegate *func, void *data) {
  if (!func)
    return 0;
  (*h)->Stat = 4;
  (*h)->Frame = 0;
  (*h)->Action = func;
  return 1;
}

// 0x1957240
void evtSetUnitColorA(evtUnitHandle_t **h, u32 frame, u32 a) {
  dds3ModelHandle_t_o **p_Model;
  u32 Color;
  struct dds3Basic_t_o *Owner;
  u32 v11;
  UnityEngine_Object_o *gameObject;
  Il2CppObject *Component_object;
  s32 IsBattleQueue;
  u32 v16;

  (*h)->ModelAAnimeMaxFrame = frame;
  (*h)->ModelAAnimeFrame = 0;
  p_Model = &(*h)->Model;
  if (frame)
  {
    Color = mdlGetColor(p_Model);
    HIBYTE((*h)->BaseModelRGBA) = HIBYTE(Color);
    HIBYTE((*h)->TargetModelRGBA) = HIBYTE(a);
    (*h)->Flag |= 0x10000u;
    Owner = (*h)->Model->Owner;
    if (Owner)
    {
      v11 = Color;
      gameObject = Owner->gameObject;
      if (op_Inequality(gameObject, 0, 0))
      {
        Component_object = GetComponent_object_(
                             (*h)->Model->Owner->gameObject);
        if (op_Inequality(Component_object, 0, 0))
        {
          IsBattleQueue = IsBattleQueue(Component_object);
          SetTransparent(Component_object, v11 & 0xFF000000, 0.0, IsBattleQueue, 0);
        }
      }
    }
  }
  else
  {
    v16 = mdlGetColor(p_Model);
    mdlSetColor(p_Model, a & 0xFF000000 | v16 & 0xFFFFFF);
    HIBYTE((*h)->BaseModelRGBA) = HIBYTE(a);
    (*h)->Flag &= ~0x10000u;
  }
}

// 0x1957050
void evtSetUnitColorRGB(evtUnitHandle_t **h, u32 frame, u32 rgb) {
  dds3ModelHandle_t_o **p_Model;
  u32 Color;
  struct dds3Basic_t_o *Owner;
  UnityEngine_Object_o *gameObject;
  Il2CppObject *Component_object;

  (*h)->ModelRGBAnimeMaxFrame = frame;
  (*h)->ModelRGBAnimeFrame = 0;
  p_Model = &(*h)->Model;
  if (frame)
  {
    (*h)->BaseModelRGBA = mdlGetColor(p_Model) & 0xFFFFFF
                               | (HIBYTE((*h)->BaseModelRGBA) << 24);
    (*h)->TargetModelRGBA = rgb & 0xFFFFFF | (HIBYTE((*h)->TargetModelRGBA) << 24);
    (*h)->Flag |= 0x8000u;
  }
  else
  {
    Color = mdlGetColor(p_Model);
    mdlSetColor(p_Model, Color & 0xFF000000 | rgb & 0xFFFFFF);
    (*h)->BaseModelRGBA = rgb & 0xFFFFFF | (HIBYTE((*h)->BaseModelRGBA) << 24);
    (*h)->Flag &= ~0x8000u;
    Owner = (*h)->Model->Owner;
    if (Owner)
    {
      gameObject = Owner->gameObject;
      if (op_Implicit(gameObject, 0))
      {
        Component_object = GetComponent_object_(
                             (*h)->Model->Owner->gameObject);
        if (op_Inequality(Component_object, 0, 0))
        {
          (Component_object->klass->vtable[23].methodPtr)(
            Component_object,
            rgb,
            Component_object->klass->vtable[23].method);
          (Component_object->klass->vtable[24].methodPtr)(
            Component_object,
            Component_object->klass->vtable[24].0.0);
        }
      }
    }
  }
}

// 0x1958000
void evtSetUnitExMotion(evtUnitHandle_t **h, s32 group, s32 motion, s32 before, s32 smooth, s32 mode) {
  s16 v8;
  s16 v9;
  evtUnitHandle_t_o *v13;
  struct System_Byte_array *ExFlags;
  struct System_Int16_array *ExNowMotion;
  struct System_Int16_array *ExBefore;
  struct System_Int16_array *ExSmooth;
  struct System_Byte_array *v23;
  struct System_Byte_array *v25;
  struct System_Byte_array *v27;
  struct System_Byte_array *v29;
  struct dds3Basic_t_o *Owner;
  UnityEngine_Object_o *gameObject;
  UnityEngine_GameObject_o *v34;
  UnityEngine_Component_o *Animator;
  UnityEngine_GUILayer_o *Component_GUILayer;

  v8 = smooth;
  v9 = before;
  v13 = *h;
  set_animchecker(v13, -1, *&motion);
  ExFlags = (*h)->ExFlags;
  ExFlags->m_Items[group] = 3;
  ExNowMotion = (*h)->ExNowMotion;
  ExNowMotion->m_Items[group] = motion;
  ExBefore = (*h)->ExBefore;
  ExBefore->m_Items[group] = v9;
  ExSmooth = (*h)->ExSmooth;
  ExSmooth->m_Items[group] = v8;
  switch (mode)
  {
    case 0:
      v23 = (*h)->ExFlags;
      v23->m_Items[group] |= 4u;
      break;
    case 1:
      v25 = (*h)->ExFlags;
      v25->m_Items[group] |= 8u;
      break;
    case 2:
      v27 = (*h)->ExFlags;
      v27->m_Items[group] |= 0x10u;
      break;
    case 4:
      v29 = (*h)->ExFlags;
      v29->m_Items[group] |= 0x20u;
      break;
    case 5:
      Owner = (*h)->Owner;
      if (Owner)
      {
        gameObject = Owner->gameObject;
        if (op_Inequality(gameObject, 0, 0))
        {
          v34 = (*h)->Owner->gameObject;
          Animator = GetAnimator(v34);
          if (op_Inequality(Animator, 0, 0))
          {
            Component_GUILayer = GetComponent_GUILayer_(Animator);
            if (op_Inequality(Component_GUILayer, 0, 0))
              SetMouthMotion(Component_GUILayer, motion);
          }
        }
      }
      break;
    default:
      return;
  }
}

// 0x1957b00
void evtSetUnitKutiMotion(evtUnitHandle_t **h, s32 group, s32 motion) {
  s8 v4;
  s8 v5;
  evtUnitHandle_t_o *v7;
  evtKutiManager_o *KutiManager;

  v4 = motion;
  v5 = group;
  v7 = *h;
  set_animchecker(v7, -1, *&motion);
  (*h)->KutiGroup = v5;
  (*h)->KutiMotion = v4;
  KutiManager = GetKutiManager();
  if (op_Inequality(KutiManager, 0, 0))
    SetUnit(KutiManager, *h);
}

// 0x1956e70
void evtSetUnitLightAndAmbient(evtUnitHandle_t **h, u32 frame, u32 lrgb, u32 argb) {
  u16 v7;
  evtUnitHandle_t_o *v9;
  evtUnitHandle_t_o *v11;

  v7 = frame;
  (*h)->LightRGBAnimeFrame = v7;
  (*h)->TargetLightRGB = lrgb;
  (*h)->TargetAmbientRGB = argb;
  GetBaseLightRGB(h, *&frame);
  v9 = *h;
  v9->BaseLightRGB = SDF_VU0__dds3ColorFtoI(128.0);
  GetBaseAmbientRGB(h);
  v11 = *h;
  v11->BaseAmbientRGB = SDF_VU0__dds3ColorFtoI(128.0);
  (*h)->Flag |= 0x800u;
  (*h)->Flag &= ~0x1000u;
}

// 0x1956f70
void evtSetUnitLightDir(evtUnitHandle_t **h, s32 frame) {
  u16 v3;

  v3 = frame;
  (*h)->LightDirAnimeFrame = v3;
  SDF_VU0__VECTOR_W_SET_ZERO();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&(*h)->TargetLightDir, 0);
  GetBaseLightDir(h);
  SDF_VU0__STOREVECTOR(&(*h)->BaseLightDir, 0);
  (*h)->Flag |= 0x400u;
  (*h)->Flag |= 0x2000u;
  (*h)->Flag &= ~0x4000u;
}

// 0x1958370
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode) {
  s16 v7;
  s16 v8;
  evtUnitHandle_t_o *v11;

  v7 = smooth;
  v8 = before;
  v11 = *h;
  set_animchecker(v11, motion, *&before);
  (*h)->Frame = 0;
  (*h)->Stat = 2;
  (*h)->NowMotion = motion;
  (*h)->Action = 0;
  (*h)->NowBefore = v8;
  (*h)->NowSmooth = v7;
  (*h)->Flag &= ~1u;
  (*h)->Flag &= ~0x20u;
  (*h)->Flag &= ~0x40u;
  (*h)->Flag &= ~0x400000u;
  (*h)->Flag &= ~0x800000u;
  (*h)->Flag |= 0x80u;
  switch (mode)
  {
    case 0:
      (*h)->Flag |= 0x20u;
      break;
    case 1:
      (*h)->Flag |= 1u;
      break;
    case 3:
      (*h)->Flag |= 0x40u;
      break;
    case 4:
      (*h)->Flag &= ~0x80u;
      break;
    case 12:
      (*h)->e723sp = 1;
      (*h)->modeframe = 0;
      break;
    default:
      return;
  }
}

// 0x1958ed0
void evtSetUnitMove1(evtUnitHandle_t **h, s32 movetype, sdfVector4_t pos, s32 motion, s32 para1, s32 para2, evtUnitHandle_t_ActionDelegate *func, void *data) {
  s16 v11;
  s16 v12;

  (*h)->Stat = 1;
  (*h)->TargetType = 0;
  (*h)->MoveType = movetype;
  (*h)->MoveTarget = 0;
  v11 = para2;
  v12 = para1;
  SDF_VU0__COPYVECTOR(&(*h)->PosTarget, pos, 0);
  (*h)->MovePara1 = v12;
  (*h)->MovePara2 = v11;
  (*h)->Action = func;
  (*h)->Frame = 0;
}

// 0x1958f60
void evtSetUnitMove2(evtUnitHandle_t **h, s32 movetype, s32 posID, s32 motion, s32 para1, s32 para2, evtUnitHandle_t_ActionDelegate *func, void *data) {
  s16 v10;
  s16 v11;
  s16 v13;
  dds3Basic_t_o *v16;
  struct dds3Basic_t_o *v17;
  s64 v18;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o v25;

  v10 = para2;
  v11 = para1;
  v13 = movetype;
  pBasic = 0;
  pBasic = dds3GetControlScene();
  v16 = dds3SearchSceneBasic(&pBasic, posID, 0x11u);
  if (v16)
  {
    v17 = v16;
    v18 = il2cp::SizeOf(v16->workdata, fldResourcePoint_t);
    v20 = *v18;
    v21 = *(v18 + 4);
    v23 = *(v18 + 8);
    v22 = *(v18 + 12);
    (*h)->Stat = 1;
    (*h)->TargetType = 0;
    (*h)->MoveType = v13;
    (*h)->MoveTarget = 0;
    v25.x = v20;
    v25.y = v21;
    v25.z = v23;
    v25.w = v22;
    SDF_VU0__COPYVECTOR(&(*h)->PosTarget, v25, 0);
    (*h)->MovePara1 = v11;
    (*h)->MovePara2 = v10;
    (*h)->Action = func;
    (*h)->Frame = 0;
    (*h)->TargetType = 1;
    (*h)->MoveTarget = v17;
  }
}

// 0x1959100
void evtSetUnitMove3(evtUnitHandle_t **h, s32 pathID, s32 para1, s32 para2, s32 movesys, s32 movedir, s32 rotsys) {
  s16 v11;
  s16 v12;
  dds3PathBasicControl_t_o *Control;
  dds3PathBasicControl_t_o *v18;
  s16 v19;
  evtUnitHandle_t_o *v20;
  u32 v21;
  evtUnitHandle_t_o *v22;
  u32 v23;
  evtUnitHandle_t_o *v24;
  u32 v25;
  dds3Basic_t_o *pBasic;
  dds3PathBasicControl_t_o *pControl;
  dds3Basic_t_o *v28;

  v11 = para2;
  v12 = para1;
  pControl = 0;
  v28 = 0;
  pBasic = 0;
  pBasic = dds3GetControlScene();
  v28 = dds3SearchSceneBasic(&pBasic, pathID, 0x10u);
  if (v28)
  {
    if ((*h)->Path)
      dds3PathBasicFreeControl(&(*h)->Path, 0);
    Control = dds3PathBasicMakeControl(&v28);
    pControl = Control;
    (*h)->Path = Control;
    v18 = Control;
    (*h)->PathStep = 40.0 / GetSplineLength(v18);
    if (movedir)
    {
      dds3PathBasicControlSetRatio(&pControl, 1.0);
      dds3PathBasicControlAlterMode(&pControl, 1u);
      (*h)->PathStep = -(*h)->PathStep;
      if (movesys != 1)
      {
        if (movesys)
        v19 = 0;
        (*h)->Flag &= ~2u;
        (*h)->MoveType = v19;
        if (movedir)
        {
          if (movedir != 1)
          v20 = *h;
          v21 = (*h)->Flag | 4;
        }
        else
        {
          v20 = *h;
          v21 = (*h)->Flag & 0xFFFFFFFB;
        }
        v20->Flag = v21;
        if (rotsys == 2)
        {
          (*h)->Flag &= ~8u;
          v24 = *h;
          v25 = (*h)->Flag | 0x10;
        }
        else
        {
          if (rotsys == 1)
          {
            v22 = *h;
            v23 = (*h)->Flag | 8;
          }
          else
          {
            if (rotsys)
            {
              (*h)->Stat = 1;
              (*h)->TargetType = 2;
              (*h)->MoveTarget = v28;
              dds3PathBasicControlGetPos(&pControl);
              SDF_VU0__STOREVECTOR(&(*h)->PosTarget, 0);
              (*h)->MovePara1 = v12;
              (*h)->MovePara2 = v11;
              (*h)->Action = 0;
              (*h)->Frame = 0;
              return;
            }
            v22 = *h;
            v23 = (*h)->Flag & 0xFFFFFFF7;
          }
          v22->Flag = v23;
          v24 = *h;
          v25 = (*h)->Flag & 0xFFFFFFEF;
        }
        v24->Flag = v25;
      }
    }
    else
    {
      dds3PathBasicControlSetRatio(&pControl, 0.0);
      dds3PathBasicControlAlterMode(&pControl, 0);
      if (movesys != 1)
    }
    (*h)->Flag |= 2u;
    v19 = 3;
  }
}

// 0x1958cc0
void evtSetUnitMovePos(evtUnitHandle_t **h, sdfVector4_t pos) {
  SDF_VU0__COPYVECTOR(&(*h)->PosTarget, pos, 0);
}

// 0x1958cd0
void evtSetUnitRot1(evtUnitHandle_t **h, sdfVector4_t rot, s32 para1) {
  s16 v4;

  if ((para1 - 1) <= 0x63)
  {
    (*h)->Stat = 3;
    (*h)->MoveTarget = 0;
    v4 = para1;
    SDF_VU0__COPYVECTOR(&(*h)->PosTarget, rot, 0);
    (*h)->MovePara1 = v4;
    (*h)->MovePara2 = 0;
    (*h)->Action = 0;
    (*h)->Frame = 0;
  }
}

// 0x1958d40
void evtSetUnitRot2(evtUnitHandle_t **h, s32 posID, s32 para1) {
  dds3Basic_t_o *v8;
  struct dds3Basic_t_o *v9;
  f32 *v10;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o v17;

  pBasic = 0;
  pBasic = dds3GetControlScene();
  v8 = dds3SearchSceneBasic(&pBasic, posID, 0x11u);
  if (v8)
  {
    v9 = v8;
    v10 = il2cp::SizeOf(v8->workdata, fldResourcePoint_t);
    v12 = v10[4];
    v13 = v10[5];
    v15 = v10[6];
    v14 = v10[7];
    else if ((para1 - 1) > 0x63)
    {
      (*h)->MoveTarget = v9;
      return;
    }
    (*h)->Stat = 3;
    (*h)->MoveTarget = 0;
    v17.x = v12;
    v17.y = v13;
    v17.z = v15;
    v17.w = v14;
    SDF_VU0__COPYVECTOR(&(*h)->PosTarget, v17, 0);
    (*h)->MovePara1 = para1;
    (*h)->MovePara2 = 0;
    (*h)->Action = 0;
    (*h)->Frame = 0;
  }
}

// 0x19579f0
void evtSetWaitHokanFrame(evtUnitHandle_t **h, s32 before, s32 smooth) {
  (*h)->WaitBefore = before;
  (*h)->WaitSmooth = smooth;
}

// 0x19579d0
void evtSetWaitMotion(evtUnitHandle_t **h, s32 motion) {
  (*h)->WaitMotion = motion;
}

// 0x19579e0
void evtSetWaitMotionSpeed(evtUnitHandle_t **h, f32 sp) {
  (*h)->WaitSpeed = sp;
}

// 0x1957420
s32 evtUnitLightAnimeStat(evtUnitHandle_t **h) {
  return ((*h)->Flag & 0x7800) != 0;
}

// 0x1957460
void evtUnitLightOff(evtUnitHandle_t **h, s32 frame) {
  evtUnitHandle_t_o *v7;
  u32 v8;

  if (frame)
  {
    evtSetUnitLightAndAmbient(h, frame, 0, 0);
    (*h)->Flag &= ~0x800u;
    (*h)->Flag |= 0x1000u;
    SDF_VU0__LOADIDENTITYVECTOR();
    evtSetUnitLightDir(h, frame);
    (*h)->Flag &= ~0x2000u;
    v7 = *h;
    v8 = (*h)->Flag | 0x4000;
  }
  else
  {
    (*h)->Flag &= 0xFFFFF8FF;
    (*h)->Flag &= 0xFFFFAFFF;
    v7 = *h;
    v8 = (*h)->Flag & 0xFFFFD7FF;
  }
  v7->Flag = v8;
}

// 0x1957440
void evtUnitLightOn(evtUnitHandle_t **h) {
  (*h)->Flag |= 0x300u;
}

// 0x1959410
s32 evtUnitManagerPrimaryFunc(dds3PoseSet_t *pose, dds3Basic_t *basic) {
    fldProcCheckFlag(0);
    UnitAnime(0);
    mdlAnimSetBattle(0, 0);
    mdlSmoothLoopMotionForUnity(0, 0, 0, 0, 0, 0);
    mdlSmoothSingleMotionForUnity(0, 0, 0, 0, 0, 0);
    mdlChkMotionEndBattleDying(0, 0, 0);
    mdlGetMotionMinorNumForUnity(0, 0);
    mdlChkMotionEndBattle(0, 0, 0);
    nbGetUnitWorkFromFormindex(0);
    datCheckDying(0);
    Get(0);
    nbGetUnitVisual(0);
    mdlSetMotionSpeedForUnity(0, 0, 0);
    mdlSetMotionSpeedAnimator(0, 0);
    mdlChkMotionEndForUnity(0, 0);
    evtUnitRotationQuat(0, (sdfVector4_t){0}, 0);
    evtCheckMoveEnd(0);
    dds3PathBasicControlGetRatio(0);
    dds3PathBasicControlSetRatio(0, 0);
    dds3PathBasicControlGetPos(0);
    SDF_VU0__STOREVECTOR(0);
    evtUnitMoveType0(0);
    evtUnitMoveTypePathTrace(0);
    mdlGetMotionFrameForUnity_26969536(0, 0);
    IsSpeakStart();
    GetKutiManager();
    Contains(0);
    IsSpeaking();
    mdlMotionStopKutiForUnity(0, 0, 0);
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    GetAnimator(0);
    SetFrame(0, 0, 0);
    nbGetMainProcessData();
    return 0;
}

// 0x1958960
s32 evtUnitMoveType0(evtUnitHandle_t **h) {
    evtUnitRotationTarget(0, (sdfVector4_t){0}, 0);
    evtGetUnitDirVector(0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__STOREVECTOR(0);
    dds3AddPosPoseSet(0, (sdfVector4_t){0});
    return 0;
}

// 0x1958b30
s32 evtUnitMoveTypePathTrace(evtUnitHandle_t **h) {
    dds3PathBasicControlNextStep(0);
    dds3PathBasicControlGetPos(0);
    SDF_VU0__STOREVECTOR(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    dds3PathBasicControlGetRot(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    FromEuler(0, 0, 0);
    Mult();
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    return 0;
}

// 0x19587f0
s32 evtUnitRotationQuat(evtUnitHandle_t **h, sdfVector4_t rot, f32 radio) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  s64 v11;
  s64 v12;
  UnityEngine_Vector4_o zero;
  UnityEngine_Vector4_o v15;
  UnityEngine_Vector4_o v16;

  w = rot.w;
  z = rot.z;
  y = rot.y;
  x = rot.x;
  *&zero.x = 0;
  *&zero.z = 0;
  zero = get_zero();
  v15.x = x;
  v15.y = y;
  v15.z = z;
  v15.w = w;
  SDF_VU0__LOADVECTOR(v15);
  ToMatrix();
  SDF_VU0__GET_ROW2();
  SDF_VU0__SETVECTOR_Y(0.0);
  SDF_VU0__VECTOR_W_SET_ZERO();
  SDF_VU0__NORMALIZE();
  SDF_VU0__SCALEVECTOR(-1.0);
  SDF_VU0__LOADVECTOR_B((*h)->Owner->poseset->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&zero);
  v11 = *&zero.x;
  v12 = *&zero.z;
  *&v16.x = v11;
  *&v16.z = v12;
  return evtUnitRotationTarget(h, v16, radio);
}

// 0x1958520
s32 evtUnitRotationTarget(evtUnitHandle_t **h, sdfVector4_t pos, f32 radio) {
    evtGetUnitDirVector(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__SETVECTOR_Y(0);
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__INNERPRODUCT();
    FromRotation(0);
    dds3AddRotPoseSet(0, (sdfVector4_t){0});
    return 0;
}

// 0x1956d80
void evtUnlinkExternalLightPacket(evtUnitHandle_t **h) {
  evtUnitHandle_t_o *v3;

  (*h)->Flag &= ~0x20000u;
  else
  {
    v3 = *h;
    if (((*h)->Flag & 0x20000) != 0)
      return;
  }
  v3->PublicLightPacket = 0;
  if (((*h)->Flag & 0x40700) != 0)
  {
    SDF_VU0__dds3ColorItoF((*h)->NowLightRGB, 0);
    SDF_VU0__LOADVECTOR((*h)->NowLightDir, 0);
    SDF_VU0__dds3ColorItoF((*h)->NowAmbientRGB, 0);
    (*h)->PublicLightPacket = (*h)->PrivateLightPacket;
  }
}

// 0x1956cf0
void evtUnlinkLightObjectBasic(evtUnitHandle_t **h, s32 frame) {
  evtUnitHandle_t_o *v3;
  evtUnitHandle_t_o *v4;
  u32 v5;

  v3 = *h;
  if ((*h)->BasicLight)
  {
    if (frame)
    {
      v3->BasicLightAnimeFrame = 0;
      (*h)->BasicLightAnimeMaxFrame = frame;
      (*h)->Flag &= ~0x80000u;
      v4 = *h;
      v5 = (*h)->Flag | 0x100000;
    }
    else
    {
      v3->BasicLight = 0;
      (*h)->Flag &= ~0x40000u;
      v4 = *h;
      v5 = (*h)->Flag & 0xFFE7FFFF;
    }
    v4->Flag = v5;
  }
}

// 0x1954b20
void evtVu0SubVectorXZAxis(sdfVector4_t a, sdfVector4_t b) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  UnityEngine_Vector4_o v7;

  w = b.w;
  z = b.z;
  y = b.y;
  x = b.x;
  SDF_VU0__LOADVECTOR(a);
  v7.x = x;
  v7.y = y;
  v7.z = z;
  v7.w = w;
  SDF_VU0__LOADVECTOR_B(v7);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__SETVECTOR_Y(0.0);
}

// 0x195ac10
s32 mdlChkMotionEndForUnity(evtUnitHandle_t **h, s32 index) {
  struct dds3Basic_t_o *Owner;
  UnityEngine_Object_o *gameObject;
  UnityEngine_Component_o *transform;
  UnityEngine_GameObject_o *v9;
  UnityEngine_Object_o *Animator;
  UnityEngine_Object_o *Component_GUILayer;

  if (!*h)
    return 1;
  Owner = (*h)->Owner;
  gameObject = Owner->gameObject;
  if (op_Equality(gameObject, 0, 0))
    return 1;
  transform = get_transform(Owner->gameObject, 0);
  v9 = get_gameObject(transform);
  Animator = GetAnimator(v9);
  if (op_Equality(Animator, 0, 0))
    return 1;
  Component_GUILayer = GetComponent_GUILayer_(Animator);
  return op_Equality(Component_GUILayer, 0, 0)
      || IsFinished(Component_GUILayer, index, 0);
}
