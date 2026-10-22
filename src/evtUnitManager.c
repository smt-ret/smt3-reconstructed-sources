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
        v15->fname = Concat_5224608(v31, "e");
      AddModel(basic, v15, v5, minor);
    }
    else
    {
      if (!IsNullOrEmpty(v30[2]))
      {
        if (Equals_5234480(m_Items[v18]->texFile, "b"))
          v5 = 6;
        if (Equals_5234480(m_Items[v18]->texFile, "f"))
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
        v40 = Concat_5224608(FileName, "e");
        v15->fname = Concat_5224608(v15->fname, "e");
      }
      akey = v15->akey;
      AddLoad(basic, akey, v5, minor, v40, v15, 1, 0);
    }
  }
}

// 0x195adc0
s32 AttachModel_26586560(dds3Basic_t *basic, char *key, char *chkname, char *name) {
  struct dds3ModelFileTable_t_array *eventModelFileTable2;
  bool IsDLC;
  s32 TableIndex;
  u32 v14;
  Il2CppClass **v16;
  Il2CppObject **v17;
  Il2CppClass *v18;
  bool IsNullOrEmpty;
  s32 v20;
  u32 max_length;
  s32 v23;
  _BOOL4 v27;
  s32 v29;
  _BOOL4 v31;
  s32 v33;
  Il2CppObject *v35;
  System_String_o *klass;
  System_String_o *monitor;
  System_String_o *v39;
  System_String_o **v40;
  System_String_o *v42;
  System_String_o *v45;
  System_String_o *FileNameWithoutExtension;
  s32 Length;
  s32 IndexOf;
  System_String_o *v51;
  _BOOL4 Manager__Contains;
  _BOOL4 v54;
  AssetBundleCtrl_o *asset_bc;
  s64 *v57;
  UnityEngine_GameObject_o *v58;
  dds3Basic_t_o *v60;
  Il2CppObject *Data;
  Il2CppObject *Prefab_16624656;
  char *v64;
  s64 *v65;
  s32 v68;
  s32 v69;
  s32 v70;
  System_String_o *v71;
  s32 v73;
  s32 v74;
  System_String_o *v75;
  s32 IndexOf_5262640;
  s32 v77;
  s32 v78;
  System_String_o *v79;
  System_String_o *v80;
  Il2CppObject *v82;
  System_String_o *v83;
  s32 v84;
  AssetBundleCtrl_o *v85;
  Il2CppObject *v87;
  System_String_o *v88;
  Il2CppObject *workdata;
  Il2CppClass *v93;
  s64 typeHierarchyDepth;
  Il2CppClass *v95;
  u64 *interfaceOffsets;
  UnityEngine_Component_o *Animator;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *v104;
  Il2CppObject *v105;
  System_String_o *v107;
  char *v109;
  s64 *v110;
  UnityEngine_Transform_o *parent;
  System_String_o *path;
  s32 v113;
  s32 v114;
  s32 v115;
  dds3Basic_t_o *basica;
  s32 cb;
  s32 v118;
  s32 minor;
  u64 v120[2];
  char *v121;

  minor = 0;
  v118 = 0;
  IsDLC = IsDLC();
  TableIndex = GetTableIndex(key, chkname);
  if (TableIndex == -1)
    return 0;
  v14 = TableIndex;
  basica = basic;
  v16 = &eventModelFileTable2->obj.klass + TableIndex;
  v18 = v16[4];
  v17 = (v16 + 4);
  IsNullOrEmpty = IsNullOrEmpty(v18->_1.name);
  if (!IsNullOrEmpty)
  {
    v23 = Equals_5234480((*v17)[1].klass, "D", 0);
    if (Equals_5234480((*v17)[1].klass, "P", 0))
      v23 = 2;
    if (Equals_5234480((*v17)[1].klass, "E", 0))
      v20 = 3;
    else
      v20 = v23;
    v27 = Equals_5234480((*v17)[1].klass, "b", 0);
    if (Equals_5234480((*v17)[1].klass, "f", 0))
      v29 = 2;
    else
      v29 = v27;
    v113 = v29;
    v31 = Equals_5234480((*v17)[1].klass, "I", 0);
    if (Equals_5234480((*v17)[1].klass, "J", 0))
      v33 = 2;
    else
      v33 = v31;
    cb = v33;
    max_length = eventModelFileTable2->max_length;
    if (v14 < max_length)
      goto LABEL_45;
LABEL_44:
  }
  cb = 0;
  v113 = 0;
  v20 = 0;
  max_length = eventModelFileTable2->max_length;
  if (v14 >= max_length)
    goto LABEL_44;
LABEL_45:
  v35 = *v17;
  klass = (*v17)[3].klass;
  monitor = v35[2].monitor;
  if (v20 == 1)
  {
    if (IsDLC)
    {
      klass = Concat_5224608("dante/dante_", monitor);
      monitor = Concat_5224608(monitor, "m");
    }
    else
    {
      klass = Concat_5224608("raidou/raidou_", monitor);
    }
    v39 = "charactor/";
    v115 = IsNullOrEmpty;
    v40 = &"e";
  }
  else
  {
    v39 = "charactor/";
    v115 = IsNullOrEmpty;
    if ((cb == 1) | v115)
    {
      v40 = &"e";
    }
    else
    {
      v40 = &v35[1];
    }
  }
  v42 = Concat_5224608(v39, *v40);
  if (v20 == 2)
  {
    v45 = Concat_5224608("player_tatoo/player_tatoo_", (*v17)[2].monitor, 0);
    klass = v45;
    monitor = (*v17)[2].monitor;
    if (IsDLC)
      monitor = Concat_5224608((*v17)[2].monitor, "m", 0);
    else
      klass = Concat_5224608(v45, "_raidou");
    path = "charactor/e";
  }
  else
  {
    path = v42;
  }
  FileNameWithoutExtension = GetFileNameWithoutExtension(klass);
  Length = get_Length(klass);
  IndexOf = LastIndexOf(klass, 0x2Fu, 0);
  v51 = klass;
  if (IndexOf != -1)
    v51 = Substring_5248048(klass, IndexOf + 1, Length + ~IndexOf);
  v114 = v20;
  Manager__Contains = Contains(v51, 0);
  v54 = v20 == 3;
  asset_bc = get_asset_bc();
  if (((Manager__Contains | IsLoad(asset_bc, monitor)) & 1) != 0)
  {
    v57 = &"Character";
    if ((cb & 1) != 0)
      v57 = &"Field";
    v58 = Find(*v57, 0);
    parent = get_transform(v58, 0);
    if (IsNullOrEmpty)
    {
      if (v115)
      {
LABEL_83:
        if (Manager__Contains)
        {
          v60 = basica;
          Data = GetData(v51, 0);
          Prefab_16624656 = Data;
          if (Data)
          {
            if (Data->klass != UnityEngine_GameObject)
            {
              sub_8FC2C0(Data->klass->_1.element_class, UnityEngine_GameObject, v120);
              if ((v120[0] & 1) != 0)
                v64 = v121;
              else
                v64 = v120 + 1;
              v65 = sub_8C4940(v64);
            }
          }
        }
        else
        {
          v60 = basica;
          v85 = get_asset_bc();
          Prefab_16624656 = LoadPrefab_16624656(v85, monitor, path, klass);
        }
        v87 = Instantiate_object__425664(Prefab_16624656, parent, 0);
        v88 = FileNameWithoutExtension;
        v118 = 0;
          goto LABEL_136;
LABEL_133:
        else
        {
          if (IsfldSetChar(v88))
            goto LABEL_135;
        }
        set_name(v87, v88);
        v60->gameObject = v87;
        v60->name = v88;
        workdata = v60->workdata;
        v93 = workdata->klass;
        if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || v93->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
        {
          sub_8FC2C0(v93->_1.element_class, dds3UnitObjectBasicWorkData_t, v120);
          if ((v120[0] & 1) != 0)
            v109 = v121;
          else
            v109 = v120 + 1;
          v110 = sub_8C4940(v109);
        }
        v95 = workdata[2].klass;
        interfaceOffsets = v95->_1.interfaceOffsets;
        if (interfaceOffsets)
        {
          interfaceOffsets[12] = v60;
          v95 = workdata[2].klass;
        }
        v95->vtable[1].method = v87;
        AttachHD(v87, v60, FileNameWithoutExtension, cb);
        SetActive(v87, 1, 0);
        Animator = GetAnimator(v87);
        if (op_Inequality(Animator, 0, 0))
        {
          gameObject = get_gameObject(Animator);
          Component_object = GetComponent_object_(gameObject);
          if (op_Equality(Component_object, 0, 0))
          {
            v104 = get_gameObject(Animator);
            v105 = AddComponent_object_(v104);
            SetCharacterType(v105, 0);
          }
          UpdateDying(v87);
        }
        v107 = get_name(v87);
        fldSetCharAdd(v107, v87);
        return 0;
      }
    }
    else
    {
      if (op_Inequality((*v17)[1].klass, "E", 0) | v115)
        goto LABEL_83;
    }
    if (IsNullOrEmpty((*v17)[1].klass, 0))
      return 0;
  }
  v68 = v54 && Manager__Contains;
  v69 = -1;
  v70 = 3;
  minor = -1;
  if (IsNullOrEmpty)
  {
    v71 = 0;
    if (v68)
      goto LABEL_101;
    goto LABEL_119;
  }
  if (v113 == 1)
    v73 = 6;
  else
    v73 = 3;
  if (v113 == 2)
    v70 = 2;
  else
    v70 = v73;
  if (v114 != 3)
  {
    v71 = 0;
    if (IsNullOrEmpty(0))
      goto LABEL_167;
    goto LABEL_116;
  }
  v74 = IndexOf_5260384(klass, "/");
  v75 = Substring_5248048(klass, 0, v74);
  IndexOf_5262640 = LastIndexOf_5262640(v75, "0x");
  if (IndexOf_5262640 == -1)
  {
    if (Equals_5234480(v75, "moter"))
      v71 = "dvl0xca";
    else
      v71 = 0;
    if (IsNullOrEmpty(v71))
      goto LABEL_167;
LABEL_116:
    v80 = Substring(v71, 5);
    TryParse_2306272(v80, 515, 0, &minor);
    v69 = minor;
    if (minor != -1)
      v70 = 7;
    if (v68)
      goto LABEL_101;
    goto LABEL_119;
  }
  v77 = IndexOf_5262640;
  v78 = get_Length(v75);
  v79 = Substring_5248048(v75, v77, v78 - v77);
  v71 = Concat_5224608("dvl", v79);
  if (!IsNullOrEmpty(v71))
    goto LABEL_116;
LABEL_167:
  v69 = -1;
  if (v68)
  {
LABEL_101:
    ReplaceDvlKeyName(v71, &minor);
    AddModel(basica, *v17, v70, minor);
    return 0;
  }
LABEL_119:
  v82 = *v17;
  v83 = (*v17)[2].monitor;
  v84 = 1;
  AddLoad(basica, v83, v70, v69, FileNameWithoutExtension, v82, 1, v71);
  return v84;
}

// 0x195bcc0
void AttachModel_26590400(dds3Basic_t *basic, char *key, char *name) {
  UnityEngine_GameObject_o *v7;
  UnityEngine_Transform_o *transform;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  Il2CppObject *v14;
  Il2CppObject *ModelHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v18;
  s64 *v19;
  UnityEngine_Component_o *Animator;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *v27;
  Il2CppObject *v28;
  FieldChrHD_o *v30;
  System_String_o *v32;
  dds3Basic_t_o *v33[3];
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = basic;
  v7 = Find("Character", 0);
  transform = get_transform(v7, 0);
  asset_bc = get_asset_bc();
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, key, "charactor/e", name);
  if (op_Inequality(Prefab_16624656, 0, 0))
  {
    v14 = Instantiate_object__425664(Prefab_16624656, transform, 0);
    set_name(v14, name);
    basic->gameObject = v14;
    basic->name = name;
    ModelHandle = dds3ObjectBaseGetModelHandle(&pObjectBasic);
    if (ModelHandle)
    {
      klass = ModelHandle->klass;
      if (ModelHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v33);
        if ((v33[0] & 1) != 0)
          v18 = v33[2];
        else
          v18 = v33 + 1;
        v19 = sub_8C4940(v18);
      }
      ModelHandle[6].klass = pObjectBasic;
    }
    SetActive(v14, 1, 0);
    Animator = GetAnimator(v14);
    if (op_Inequality(Animator, 0, 0))
    {
      gameObject = get_gameObject(Animator);
      Component_object = GetComponent_object_(gameObject);
      if (op_Equality(Component_object, 0, 0))
      {
        v27 = get_gameObject(Animator);
        v28 = AddComponent_object_(v27);
        SetCharacterType(v28, 0);
      }
    }
    v30 = mdlSetHD(v14, 2, 0, 15);
    if (op_Inequality(v30, 0, 0))
      SetUpDateDI(v30);
    v32 = get_name(v14);
    fldSetCharAdd(v32, v14);
  }
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
    v5 = Find("Character", 0);
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
  else
  {
    fldSetCharClr();
  }
}

// 0x19568b0
void GetBaseAmbientRGB(evtUnitHandle_t **h) {
  struct dds3Basic_t_o *BasicLight;
  u32 Flag;
  bool v5;
  s32 v6;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  u64 v13[3];
  UnityEngine_Vector4_o dds3Ambient;

  BasicLight = (*h)->BasicLight;
  Flag = (*h)->Flag;
  if (BasicLight)
    v5 = (Flag & 0x40000) == 0;
  else
    v5 = 1;
  if (v5)
  {
    v6 = 0;
    workdata = 0;
    if ((Flag & 0x200) != 0)
    {
LABEL_14:
      SDF_VU0__dds3ColorItoF((*h)->NowAmbientRGB, 0);
      return;
    }
  }
  else
  {
    workdata = BasicLight->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3LightObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3LightObjectBasicWorkData_t, v13);
      if ((v13[0] & 1) != 0)
        v11 = v13[2];
      else
        v11 = v13 + 1;
      v12 = sub_8C4940(v11);
    }
    v6 = (HIDWORD(workdata[3].monitor) >> 3) & 1;
    if ((Flag & 0x200) != 0)
      goto LABEL_14;
  }
  if (v6)
  {
    dds3Ambient = *(workdata + 24);
  }
  else
  {
  }
  SDF_VU0__LOADVECTOR(dds3Ambient);
}

// 0x1956a20
void GetBaseLightDir(evtUnitHandle_t **h) {
  evtUnitHandle_t_o *v3;
  struct dds3Basic_t_o *BasicLight;
  u32 Flag;
  bool v6;
  s32 v7;
  struct sdf3DLight_t_array *dds3DirLights;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  u64 v16[3];

  v3 = *h;
  BasicLight = (*h)->BasicLight;
  Flag = (*h)->Flag;
  if (BasicLight)
    v6 = (Flag & 0x40000) == 0;
  else
    v6 = 1;
  if (v6)
  {
    v7 = 0;
    if ((Flag & 0x400) != 0)
      goto LABEL_19;
    goto LABEL_9;
  }
  workdata = BasicLight->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3LightObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3LightObjectBasicWorkData_t, v16);
    if ((v16[0] & 1) != 0)
      v14 = v16[2];
    else
      v14 = v16 + 1;
    v15 = sub_8C4940(v14);
  }
  v7 = (HIDWORD(workdata[3].monitor) >> 3) & 1;
  if ((Flag & 0x400) == 0)
  {
LABEL_9:
    if (!v7)
    {
      v3 = dds3DirLights->m_Items[0];
    }
  }
LABEL_19:
  SDF_VU0__LOADVECTOR(v3->NowLightDir);
}

// 0x1956720
void GetBaseLightRGB(evtUnitHandle_t **h) {
  struct dds3Basic_t_o *BasicLight;
  u32 Flag;
  bool v5;
  s32 v6;
  Il2CppObject *workdata;
  UnityEngine_Vector4_o *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  struct sdf3DLight_t_array *dds3DirLights;
  char *v14;
  s64 *v15;
  u64 v16[3];

  BasicLight = (*h)->BasicLight;
  Flag = (*h)->Flag;
  if (BasicLight)
    v5 = (Flag & 0x40000) == 0;
  else
    v5 = 1;
  if (v5)
  {
    v6 = 0;
    workdata = 0;
    if ((Flag & 0x100) != 0)
    {
LABEL_14:
      SDF_VU0__dds3ColorItoF((*h)->NowLightRGB, 0);
      return;
    }
  }
  else
  {
    workdata = BasicLight->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3LightObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3LightObjectBasicWorkData_t, v16);
      if ((v16[0] & 1) != 0)
        v14 = v16[2];
      else
        v14 = v16 + 1;
      v15 = sub_8C4940(v14);
    }
    v6 = (HIDWORD(workdata[3].monitor) >> 3) & 1;
    if ((Flag & 0x100) != 0)
      goto LABEL_14;
  }
  if (v6)
  {
    v8 = workdata[1].klass;
  }
  else
  {
    v8 = dds3DirLights->m_Items[0];
  }
  SDF_VU0__LOADVECTOR(v8[1]);
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
  f32 v3;
  u32 v5;
  evtUnitHandle_t_o *v6;
  evtUnitHandle_t_o *v7;
  f32 v8;
  dds3ModelHandle_t_o **v10;
  u32 v11;
  u32 v12;
  struct dds3Basic_t_o *v14;
  UnityEngine_Object_o *v15;
  bool v16;
  Il2CppObject *v17;
  f32 v18;
  dds3ModelHandle_t_o **p_Model;
  u32 Color;
  u32 v22;
  struct dds3Basic_t_o *Owner;
  UnityEngine_Object_o *gameObject;
  Il2CppObject *Component_object;
  evtUnitHandle_t_o *v27;
  u32 ModelRGBAnimeFrame;
  evtUnitHandle_t_o *v29;
  u32 ModelAAnimeFrame;
  s32 IsBattleQueue;
  evtUnitHandle_t_o *v33;
  dds3Basic_t_o *BasicLight;
  dds3Basic_t_o *BasicLight2;
  evtUnitHandle_t_o *v37;
  struct dds3Basic_t_o *v38;
  s32 v39;
  Il2CppObject *v40;
  Il2CppObject *workdata;
  f32 v42;
  f32 v43;
  evtUnitHandle_t_o *v44;
  u32 Flag;
  f32 v46;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v49;
  s64 *v50;
  struct dds3Basic_t_o *v51;
  Il2CppClass *v52;
  s64 v53;
  char *v54;
  s64 *v55;
  sdfModelRootNode_t_o *modelRoot;
  struct dds3Basic_t_o *v59;
  System_String_o *name;
  System_String_o *v61;
  UnityEngine_Vector4_o *p_pos;
  Il2CppClass *v64;
  struct sdf3DLight_t_array *dds3DirLights;
  evtUnitHandle_t_o *v69;
  u32 v70;
  UnityEngine_Object_o *modelobj;
  UnityEngine_GameObject_o *v73;
  UnityEngine_GameObject_o *GameObject_PartName;
  UnityEngine_Transform_o *transform;
  struct dds3Basic_t_o *v78;
  System_String_o *v79;
  System_String_o *v80;
  UnityEngine_Vector4_o *v81;
  UnityEngine_Transform_o *v82;
  struct dds3Basic_t_o *v84;
  System_String_o *v85;
  System_String_o *v86;
  UnityEngine_Vector4_o *v87;
  f32 v91;
  f32 v92;
  f32 v94;
  f32 v95;
  evtUnitHandle_t_o *v97;
  u32 v98;
  u32 BasicLightAnimeMaxFrame;
  u32 BasicLightAnimeFrame;
  evtUnitHandle_t_o *v101;
  UnityEngine_Vector4_o *v102;
  struct sdf3DLight_t_array *v104;
  _BOOL4 v106;
  evtUnitHandle_t_o *v107;
  evtUnitHandle_t_o *v115;
  u32 v116;
  f32 v117;
  UnityEngine_Vector4_o *v119;
  UnityEngine_Vector4_o *v120;
  struct sdf3DLight_t_array *v122;
  evtUnitHandle_t_o *v124;
  u32 v125;
  evtUnitHandle_t_o *v128;
  u32 v129;
  evtUnitHandle_t_o *v130;
  evtUnitHandle_t_o *v131;
  f32 v132;
  f32 v133;
  u32 v134;
  struct sdf3DLight_t_array *v136;
  evtUnitHandle_t_o *v138;
  f32 v139;
  f32 v140;
  evtUnitHandle_t_o *v145;
  evtUnitHandle_t_o *v150;
  f32 v155;
  f32 v157;
  evtUnitHandle_t_o *v160;
  u32 v161;
  f32 w;
  UnityEngine_Vector4_o v163;
  UnityEngine_Vector4_o v164;
  UnityEngine_Vector4_o pos;
  dds3Basic_t_o *ActiveScene;
  UnityEngine_Vector4_o v167;
  u64 v168[2];
  char *v169;
  dds3Basic_t_o *scene;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v172;
  UnityEngine_Vector4_o v173;
  UnityEngine_Vector4_o TargetLightDir;
  UnityEngine_Vector4_o dds3Ambient;
  UnityEngine_Vector4_o v176;

  v3 = 0.0;
  *&v167.x = 0;
  *&v167.z = 0;
  *&pos.z = 0;
  ActiveScene = 0;
  scene = 0;
  *&v164.z = 0;
  *&pos.x = 0;
  *&v163.x = 0;
  *&v163.z = 0;
  *&v164.x = 0;
  sub_854690(&v167.x, 0.0, 0.0, 0.0, 1.0);
  else
  {
    v6 = *h;
    if (((*h)->Flag & 0x8000) == 0)
      goto LABEL_6;
  }
  v18 = 1.0;
  if (v6->ModelRGBAnimeMaxFrame)
  {
    LOWORD(v5) = v6->ModelRGBAnimeFrame;
    v18 = v5 / v6->ModelRGBAnimeMaxFrame;
  }
  SDF_VU0__dds3ColorItoF(v6->TargetModelRGBA);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__dds3ColorItoF((*h)->BaseModelRGBA, 0);
  SDF_VU0__SCALEVECTOR(1.0 - v18);
  SDF_VU0__SCALEVECTOR_B(v18);
  SDF_VU0__ADDVECTOR();
  p_Model = &(*h)->Model;
  Color = mdlGetColor(p_Model);
  v22 = Color & 0xFF000000 | SDF_VU0__dds3ColorFtoI(128.0) & 0xFFFFFF;
  mdlSetColor(&(*h)->Model, v22, 0);
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
          v22,
          Component_object->klass->vtable[23].method);
        (Component_object->klass->vtable[24].methodPtr)(
          Component_object,
          Component_object->klass->vtable[24].0.0);
      }
    }
  }
  v27 = *h;
  ModelRGBAnimeFrame = (*h)->ModelRGBAnimeFrame;
  if (ModelRGBAnimeFrame >= (*h)->ModelRGBAnimeMaxFrame)
  {
    v27->Flag &= ~0x8000u;
    v7 = *h;
    if (((*h)->Flag & 0x10000) == 0)
      goto LABEL_48;
  }
  else
  {
    v27->ModelRGBAnimeFrame = ModelRGBAnimeFrame + 1;
    v7 = *h;
    if (((*h)->Flag & 0x10000) == 0)
      goto LABEL_48;
  }
LABEL_7:
  v8 = 1.0;
  if (v7->ModelAAnimeMaxFrame)
  {
    LOWORD(v5) = v7->ModelAAnimeFrame;
    v8 = v5 / v7->ModelAAnimeMaxFrame;
  }
  SDF_VU0__dds3ColorItoF(v7->TargetModelRGBA);
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__dds3ColorItoF((*h)->BaseModelRGBA, 0);
  SDF_VU0__SCALEVECTOR(1.0 - v8);
  SDF_VU0__SCALEVECTOR_B(v8);
  SDF_VU0__ADDVECTOR();
  v10 = &(*h)->Model;
  v11 = mdlGetColor(v10);
  v12 = SDF_VU0__dds3ColorFtoI(128.0) & 0xFF000000 | v11 & 0xFFFFFF;
  mdlSetColor(&(*h)->Model, v12, 0);
  v14 = (*h)->Model->Owner;
  if (v14)
  {
    v15 = v14->gameObject;
    v16 = op_Implicit(v15, 0);
    v17 = 0;
    if (v16)
      v17 = GetComponent_object_(
              (*h)->Model->Owner->gameObject);
  }
  else
  {
    v17 = 0;
  }
  v29 = *h;
  ModelAAnimeFrame = (*h)->ModelAAnimeFrame;
  if (ModelAAnimeFrame < (*h)->ModelAAnimeMaxFrame)
  {
    v29->ModelAAnimeFrame = ModelAAnimeFrame + 1;
      goto LABEL_42;
    goto LABEL_46;
  }
  v29->Flag &= ~0x10000u;
  w = SDF_VU0__Retdds3ColorItoF(v12, 128.0).w;
  if (w == 0.0)
  {
    {
LABEL_42:
    }
LABEL_46:
    if (op_Inequality(v17, 0, 0))
    {
      IsBattleQueue = IsBattleQueue(v17);
      SetTransparent(v17, v12, 0.0, IsBattleQueue, 0);
    }
    goto LABEL_48;
  }
  if (op_Inequality(v17, 0, 0))
  {
    RetTransparent(v17, 0);
    if (((*h)->Flag & 0x40000) == 0)
      goto LABEL_59;
    goto LABEL_49;
  }
LABEL_48:
  if (((*h)->Flag & 0x40000) == 0)
    goto LABEL_59;
LABEL_49:
  scene = dds3GetActiveScene();
  v33 = *h;
  BasicLight = (*h)->BasicLight;
  if (!BasicLight)
    goto LABEL_58;
  if (!dds3SceneBasicExistBasicFromType(&scene, 9, BasicLight))
  {
    (*h)->BasicLight = 0;
    (*h)->BasicLight2 = 0;
    v33 = *h;
LABEL_58:
    v33->Flag &= ~0x40000u;
  }
LABEL_59:
  if ((*h)->BasicLight2)
  {
    ActiveScene = dds3GetActiveScene();
    BasicLight2 = (*h)->BasicLight2;
    if (dds3SceneBasicExistBasicFromType(&ActiveScene, 9, BasicLight2))
      (*h)->BasicLight2 = 0;
  }
  v37 = *h;
  v38 = (*h)->BasicLight;
  if (v38 && (v37->Flag & 0x40000) != 0)
  {
    workdata = v38->workdata;
    if (workdata)
    {
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3LightObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3LightObjectBasicWorkData_t, v168);
        if ((v168[0] & 1) != 0)
          v49 = v169;
        else
          v49 = v168 + 1;
        v50 = sub_8C4940(v49);
      }
    }
    v51 = v37->BasicLight2;
    if (v51)
    {
      v40 = v51->workdata;
      if (v40)
      {
        v52 = v40->klass;
        if (v40->klass->_2.typeHierarchyDepth < v53
          || v52->_2.typeHierarchy[v53 - 1] != dds3LightObjectBasicWorkData_t)
        {
          sub_8FC2C0(v52->_1.element_class, dds3LightObjectBasicWorkData_t, v168);
          if ((v168[0] & 1) != 0)
            v54 = v169;
          else
            v54 = v168 + 1;
          v55 = sub_8C4940(v54);
        }
      }
    }
    else
    {
      v40 = 0;
    }
    modelRoot = v37->Model->modelRoot;
    if (sdfModelGetMarkPosUnity(modelRoot, 0))
    {
      *&v163.x = 0;
      *&v163.z = 0;
      SDF_VU0__STOREVECTOR(&v163);
      v59 = (*h)->BasicLight;
      name = (*h)->Owner->name;
      v61 = v59->name;
      p_pos = &v59->poseset->pos;
      NoFindHelper0(name, v61, &v163, p_pos);
      v173 = v163;
    }
    else
    {
      modelobj = (*h)->modelobj;
      if (op_Inequality(modelobj, 0, 0))
      {
        v73 = (*h)->modelobj;
        GameObject_PartName = GetGameObject_PartName(v73, "_skin");
        if (op_Inequality(GameObject_PartName, 0, 0))
        {
          transform = get_transform(GameObject_PartName, 0);
          position = get_position(transform);
          pos.x = position.x * 100.0;
          pos.w = 0.0;
          pos.y = position.y * -100.0;
          pos.z = position.z * 100.0;
          v78 = (*h)->BasicLight;
          v79 = (*h)->Owner->name;
          v80 = v78->name;
          v81 = &v78->poseset->pos;
          NoFindHelper0(v79, v80, &pos, v81);
          v173 = pos;
        }
        else
        {
          v82 = get_transform((*h)->modelobj, 0);
          v172 = get_position(v82);
          v164.x = v172.x * 100.0;
          v164.w = 0.0;
          v164.y = v172.y * -100.0;
          v164.z = v172.z * 100.0;
          v84 = (*h)->BasicLight;
          v85 = (*h)->Owner->name;
          v86 = v84->name;
          v87 = &v84->poseset->pos;
          NoFindHelper0(v85, v86, &v164, v87);
          v173 = v164;
        }
      }
      else
      {
        v173.x = 0.0;
        v173.y = 0.0;
        v173.z = 0.0;
        v173.w = 0.0;
      }
    }
    SDF_VU0__LOADVECTOR(v173);
    SDF_VU0__STOREVECTOR(&r_cen);
    SDF_VU0__LOADVECTOR_B((*h)->BasicLight->poseset->pos, 0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(&r_v);
    SDF_VU0__GETLENGTH();
    v91 = *&workdata[2].monitor;
    if (v91 >= 0.0)
    {
      v42 = 1.0;
      v3 = 0.0;
      if (!v40)
        goto LABEL_162;
    }
    else
    {
      v92 = *(&workdata[2].monitor + 1);
      if (v92 <= 0.0)
      {
        v42 = 0.0;
        v3 = 0.0;
        if (!v40)
          goto LABEL_162;
      }
      else
      {
        v42 = 1.0 - ((0.0 - v91) / (v92 - v91));
        v3 = 0.0;
        if (!v40)
          goto LABEL_162;
      }
    }
    SDF_VU0__LOADVECTOR(r_cen);
    SDF_VU0__LOADVECTOR_B((*h)->BasicLight2->poseset->pos, 0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(&r_v2);
    SDF_VU0__GETLENGTH();
    v94 = *&v40[2].monitor;
    if (v94 >= 0.0)
    {
      v3 = 1.0;
        goto LABEL_163;
      goto LABEL_157;
    }
    v95 = *(&v40[2].monitor + 1);
    if (v95 > 0.0)
    {
      v3 = 1.0 - ((0.0 - v94) / (v95 - v94));
        goto LABEL_163;
LABEL_157:
LABEL_163:
      SDF_VU0__LOADVECTOR(r_v);
      if ((BYTE4(workdata[3].monitor) & 8) != 0)
      {
        SDF_VU0__STOREVECTOR(&workdata[1].klass->_1.byval_arg);
        v43 = 0.0;
        v39 = 1;
        v44 = *h;
        Flag = (*h)->Flag;
        if ((Flag & 0x6000) != 0)
          goto LABEL_71;
      }
      else
      {
        v97 = *h;
        v98 = (*h)->Flag;
        if ((v98 & 0x180000) != 0)
        {
          if (v97->BasicLightAnimeMaxFrame)
          {
            BasicLightAnimeFrame = v97->BasicLightAnimeFrame;
            BasicLightAnimeMaxFrame = v97->BasicLightAnimeMaxFrame;
            v97->BasicLightAnimeFrame = BasicLightAnimeFrame + 1;
            v101 = *h;
            if ((v98 & 0x100000) != 0)
              v43 = 1.0 - (BasicLightAnimeFrame / BasicLightAnimeMaxFrame);
            else
              v43 = BasicLightAnimeFrame / BasicLightAnimeMaxFrame;
            if ((*h)->BasicLightAnimeFrame >= (*h)->BasicLightAnimeMaxFrame)
            {
              v161 = v101->Flag;
              if ((v161 & 0x100000) != 0)
              {
                v101->Flag = v161 & 0xFFFBFFFF;
                (*h)->BasicLight = 0;
                v101 = *h;
                v161 = (*h)->Flag;
              }
              v101->Flag = v161 & 0xFFE7FFFF;
              v39 = 0;
              (*h)->BasicLight2 = 0;
              v44 = *h;
              Flag = (*h)->Flag;
              if ((Flag & 0x6000) != 0)
                goto LABEL_71;
            }
            else
            {
              v39 = 0;
              v44 = *h;
              Flag = (*h)->Flag;
              if ((Flag & 0x6000) != 0)
                goto LABEL_71;
            }
          }
          else
          {
            v39 = 0;
            if ((v98 & 0x100000) != 0)
              v43 = 0.0;
            else
              v43 = 1.0;
            v44 = *h;
            Flag = (*h)->Flag;
            if ((Flag & 0x6000) != 0)
              goto LABEL_71;
          }
        }
        else
        {
          v39 = 0;
          v43 = 1.0;
          v44 = *h;
          Flag = (*h)->Flag;
          if ((Flag & 0x6000) != 0)
            goto LABEL_71;
        }
      }
      goto LABEL_173;
    }
LABEL_162:
      goto LABEL_163;
    goto LABEL_157;
  }
  v39 = 0;
  v40 = 0;
  workdata = 0;
  v42 = 0.0;
  v43 = 0.0;
  v44 = *h;
  Flag = (*h)->Flag;
  if ((Flag & 0x6000) != 0)
  {
LABEL_71:
    if (v44->LightDirAnimeFrame)
      v46 = 1.0 / v44->LightDirAnimeFrame;
    else
      v46 = 1.0;
    SDF_VU0__LOADVECTOR(v44->BaseLightDir);
    if (((*h)->Flag & 0x2000) != 0)
    {
      TargetLightDir = (*h)->TargetLightDir;
    }
    else
    {
      if (v39)
      {
        v64 = workdata[1].klass;
      }
      else
      {
        v64 = dds3DirLights->m_Items[0];
      }
      TargetLightDir = v64->_1.byval_arg;
    }
    SDF_VU0__LOADVECTOR_B(TargetLightDir);
    dds3RotationArc();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR(v167);
    Lerp(v46, 0);
    ToMatrix();
    SDF_VU0__LOADVECTOR((*h)->BaseLightDir, 0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(&(*h)->WorkLightDir, 0);
    SDF_VU0__STOREVECTOR(&(*h)->BaseLightDir, 0);
    v69 = *h;
    if ((*h)->LightDirAnimeFrame)
    {
      v69->LightDirAnimeFrame = (*h)->LightDirAnimeFrame - 1;
    }
    else
    {
      v70 = v69->Flag;
      if ((v70 & 0x4000) != 0)
      {
        v69->Flag = v70 & 0xFFFFFBFF;
        v69 = *h;
        v70 = (*h)->Flag;
      }
      v69->Flag = v70 & 0xFFFF9FFF;
    }
    goto LABEL_183;
  }
LABEL_173:
  if ((Flag & 0x400) == 0)
  {
    if (v39)
    {
      v102 = workdata[1].klass;
    }
    else
    {
      v104 = dds3DirLights;
      v102 = v104->m_Items[0];
    }
    SDF_VU0__LOADVECTOR(v102[2]);
    SDF_VU0__STOREVECTOR(&(*h)->WorkLightDir, 0);
  }
LABEL_183:
  v106 = v39 == 0 && workdata != 0;
  v107 = *h;
  if (!v106)
  {
    SDF_VU0__COPYVECTOR(&v107->NowLightDir, v107->WorkLightDir);
    v115 = *h;
    v116 = (*h)->Flag;
    if ((v116 & 0x1800) != 0)
      goto LABEL_199;
LABEL_205:
    if ((v116 & 0x100) != 0)
    {
      if ((v116 & 0x200) != 0)
        goto LABEL_243;
    }
    else
    {
      if (v39)
      {
        v120 = workdata[1].klass;
      }
      else
      {
        v136 = dds3DirLights;
        v120 = v136->m_Items[0];
      }
      SDF_VU0__LOADVECTOR(v120[1]);
      v138 = *h;
      v138->WorkLightRGB = SDF_VU0__dds3ColorFtoI(128.0);
      if (((*h)->Flag & 0x200) != 0)
      {
LABEL_243:
        if (v39 != 0 || workdata == 0)
          goto LABEL_230;
LABEL_244:
        v139 = v42 * v43;
        SDF_VU0__dds3ColorItoF((*h)->WorkLightRGB, 0);
        v140 = 1.0 - (v42 * v43);
        SDF_VU0__SCALEVECTOR(v140);
        SDF_VU0__LOADVECTOR_B(*&workdata[1].klass->_1.name);
        SDF_VU0__SCALEVECTOR_B(v42 * v43);
        SDF_VU0__ADDVECTOR();
        SDF_VU0__STOREVECTOR(&r_w);
        if (v40)
        {
          SDF_VU0__dds3ColorItoF((*h)->WorkLightRGB, 0);
          SDF_VU0__SCALEVECTOR(1.0 - v3);
          SDF_VU0__LOADVECTOR_B(*&v40[1].klass->_1.name);
          SDF_VU0__SCALEVECTOR_B(v3);
          SDF_VU0__ADDVECTOR();
          SDF_VU0__SCALEVECTOR(1.0 - v43);
          SDF_VU0__LOADVECTOR_B(r_w);
          SDF_VU0__SCALEVECTOR_B(v43);
          SDF_VU0__ADDVECTOR();
        }
        SDF_VU0__VECTOR_W_SET_ZERO();
        v145 = *h;
        v145->NowLightRGB = SDF_VU0__dds3ColorFtoI(128.0);
        SDF_VU0__dds3ColorItoF((*h)->WorkAmbientRGB, 0);
        SDF_VU0__SCALEVECTOR(v140);
        SDF_VU0__LOADVECTOR_B(*(workdata + 24), 0);
        SDF_VU0__SCALEVECTOR_B(v139);
        SDF_VU0__ADDVECTOR();
        SDF_VU0__STOREVECTOR(&r_w);
        if (v40)
        {
          SDF_VU0__dds3ColorItoF((*h)->WorkAmbientRGB, 0);
          SDF_VU0__SCALEVECTOR(1.0 - v3);
          SDF_VU0__LOADVECTOR_B(*(v40 + 24), 0);
          SDF_VU0__SCALEVECTOR_B(v3);
          SDF_VU0__ADDVECTOR();
          SDF_VU0__SCALEVECTOR(1.0 - v43);
          SDF_VU0__LOADVECTOR_B(r_w);
          SDF_VU0__SCALEVECTOR_B(v43);
          SDF_VU0__ADDVECTOR();
        }
        SDF_VU0__VECTOR_W_SET_ZERO();
        v150 = *h;
        v150->NowAmbientRGB = SDF_VU0__dds3ColorFtoI(128.0);
        evtUpdateEx_UnitLightColorAfter(h);
        v132 = *&workdata[3].klass;
        v133 = *(&workdata[3].klass + 1);
        if (v132 >= 1.0)
        {
          v132 = (v139 * v132) + (v140 * sdfFaceDivSoften);
          v133 = (v139 * v133) + (v140 * sdfFaceDivBias);
        }
        if (v40)
        {
          v155 = *&v40[3].klass;
          if (v155 >= 1.0)
          {
            v157 = *(&v40[3].klass + 1);
            v132 = (v43 * v132) + ((1.0 - v43) * ((v3 * v155) + ((1.0 - v3) * sdfFaceDivSoften)));
            v133 = (v43 * v133) + ((1.0 - v43) * ((v3 * v157) + ((1.0 - v3) * sdfFaceDivBias)));
          }
        }
        v131 = *h;
        goto LABEL_275;
      }
    }
    if (v39)
    {
      dds3Ambient = *(workdata + 24);
    }
    else
    {
    }
    SDF_VU0__LOADVECTOR(dds3Ambient);
    v160 = *h;
    v160->WorkAmbientRGB = SDF_VU0__dds3ColorFtoI(128.0);
    if (!v106)
      goto LABEL_230;
    goto LABEL_244;
  }
  SDF_VU0__LOADVECTOR(v107->WorkLightDir);
  SDF_VU0__LOADVECTOR_B(r_v);
  dds3RotationArc();
  SDF_VU0__COPYVECTOR_A_TO_B();
  SDF_VU0__LOADVECTOR(v167);
  Lerp(v43, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR((*h)->WorkLightDir, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&r_w);
  if (v40)
  {
    SDF_VU0__LOADVECTOR((*h)->WorkLightDir, 0);
    SDF_VU0__LOADVECTOR_B(r_v2);
    dds3RotationArc();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR(v167);
    Lerp(1.0, 0);
    ToMatrix();
    SDF_VU0__LOADVECTOR((*h)->WorkLightDir, 0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(&r_w2);
    SDF_VU0__LOADVECTOR_B(r_w);
    dds3RotationArc();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADVECTOR(v167);
    Lerp(v43, 0);
    ToMatrix();
    SDF_VU0__LOADVECTOR(r_w2);
    SDF_VU0__APPLYMATRIX();
  }
  SDF_VU0__STOREVECTOR(&(*h)->NowLightDir, 0);
  v115 = *h;
  v116 = (*h)->Flag;
  if ((v116 & 0x1800) == 0)
    goto LABEL_205;
LABEL_199:
  v117 = 1.0;
  if (v115->LightRGBAnimeFrame)
    v117 = 1.0 / v115->LightRGBAnimeFrame;
  SDF_VU0__dds3ColorItoF(v115->BaseLightRGB);
  SDF_VU0__SCALEVECTOR(1.0 - v117);
  SDF_VU0__COPYVECTOR_A_TO_B();
  if (((*h)->Flag & 0x800) != 0)
  {
    SDF_VU0__dds3ColorItoF((*h)->TargetLightRGB, 0);
  }
  else
  {
    if (v39)
    {
      v119 = workdata[1].klass;
    }
    else
    {
      v122 = dds3DirLights;
      v119 = v122->m_Items[0];
    }
    SDF_VU0__LOADVECTOR(v119[1]);
  }
  SDF_VU0__SCALEVECTOR(v117);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__VECTOR_W_SET_ZERO();
  v124 = *h;
  v125 = SDF_VU0__dds3ColorFtoI(128.0);
  v124->BaseLightRGB = v125;
  v124->WorkLightRGB = v125;
  SDF_VU0__dds3ColorItoF((*h)->BaseAmbientRGB, 0);
  SDF_VU0__SCALEVECTOR(1.0 - v117);
  SDF_VU0__COPYVECTOR_A_TO_B();
  if (((*h)->Flag & 0x800) != 0)
  {
    SDF_VU0__dds3ColorItoF((*h)->TargetAmbientRGB, 0);
  }
  else
  {
    if (v39)
    {
      v176 = *(workdata + 24);
    }
    else
    {
      v176 = dds3Ambient;
    }
    SDF_VU0__LOADVECTOR(v176);
  }
  SDF_VU0__SCALEVECTOR(v117);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__VECTOR_W_SET_ONE();
  v128 = *h;
  v129 = SDF_VU0__dds3ColorFtoI(128.0);
  v128->BaseAmbientRGB = v129;
  v128->WorkAmbientRGB = v129;
  v130 = *h;
  if (!(*h)->LightRGBAnimeFrame)
  {
    v134 = v130->Flag;
    if ((v134 & 0x1000) != 0)
    {
      v130->Flag = v134 & 0xFFFFFCFF;
      v130 = *h;
      v134 = (*h)->Flag;
    }
    v130->Flag = v134 & 0xFFFFE7FF;
    if (!v106)
      goto LABEL_230;
    goto LABEL_244;
  }
  v130->LightRGBAnimeFrame = (*h)->LightRGBAnimeFrame - 1;
  if (v106)
    goto LABEL_244;
LABEL_230:
  (*h)->NowLightRGB = (*h)->WorkLightRGB;
  (*h)->NowAmbientRGB = (*h)->WorkAmbientRGB;
  v131 = *h;
  if (((*h)->Flag & 0x1000000) != 0)
    return;
  v132 = 0.0;
  v133 = 0.0;
LABEL_275:
  v131->soften = v132;
  (*h)->bias = v133;
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
LABEL_6:
  if (Stat != 2 || v3->Frame < 1)
    return 0;
  return mdlChkMotionEndForUnity(h, 0) != 0;
}

// 0x19577c0
evtUnitHandle_t *evtCreateUnitHandle(dds3Basic_t **owner, dds3ModelHandle_t *model) {
  u64 *v5;
  u64 *v6;
  u64 *v7;
  UnityEngine_Vector4_o v9;

  *&v9.x = 0;
  *&v9.z = 0;
  sub_854690(&v9.x, 0.0, 1.0, 0.5, 0.0);
  v5 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v5);
  v6 = Allocate(evtUnitManager_t);
  evtUnitManager_t___ctor(v6);
  evtUnitHandle_t__Clear(v6);
  *(v6 + 56) = 0x10000;
  *(v6 + 59) = 1065353216;
  *(v6 + 242) = 655360;
  *(v6 + 62) = 0;
  v6[19] = *owner;
  v6[22] = model;
  SDF_VU0__LOADVECTOR(v9);
  SDF_VU0__STOREVECTOR(v6 + 2);
  SDF_VU0__STOREVECTOR(v6 + 5);
  *(v6 + 7) = 11711154;
  *(v6 + 4) = 11711154;
  *(v6 + 27) = -2144325584;
  *(v6 + 24) = -2144325584;
  v7 = Allocate(sdf3DLightParallelPacket_t);
  sdf3DLightParallelPacket_t___ctor(v7);
  v6[15] = v7;
  v6[16] = 0;
  return v6;
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
    goto LABEL_9;
  }
  if (Ratio != 0.0)
  {
LABEL_9:
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
  UnityEngine_Vector4_o v3;

  *&v3.x = 0;
  *&v3.z = 0;
  sub_854690(&v3.x, 0.0, 0.0, 0.0, 0.0);
  SDF_VU0__LOADVECTOR((*h)->Owner->poseset->rot, 0);
  ToMatrix();
  SDF_VU0__STORE_ROW2(&v3);
  sub_854930(&v3, 1u);
  sub_854930(&v3, 3u);
  SDF_VU0__LOADVECTOR(v3);
  SDF_VU0__NORMALIZE();
  SDF_VU0__SCALEVECTOR(-1.0);
}

// 0x1957570
evtUnitHandle_t *evtGetUnitHandle(s32 serial) {
  evtUnitHandle_t_o *result;
  evtUnitHandle_t_o **v5;
  evtUnitHandle_t_o *v6;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  dds3Basic_t_o *ActiveScene;
  u64 v11[3];

  ActiveScene = 0;
  ActiveScene = dds3GetActiveScene();
  result = dds3SearchSceneBasic(&ActiveScene, serial, 5u);
  if (result)
  {
    v5 = *&result->BaseLightDir.z;
    v6 = *v5;
    if (LOBYTE((*v5)->ExBefore) < typeHierarchyDepth
      || *(*&v6->Sin + 8 * typeHierarchyDepth - 8) != dds3UnitObjectBasicWorkData_t)
    {
      sub_8FC2C0(*&v6->TargetLightDir.x, dds3UnitObjectBasicWorkData_t, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
    return v5[4];
  }
  return result;
}

// 0x19576c0
evtUnitHandle_t *evtGetUnitHandle2(dds3Basic_t *unit) {
  evtUnitHandle_t_o **workdata;
  evtUnitHandle_t_o *v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  if (!unit)
    return 0;
  workdata = unit->workdata;
  v4 = *workdata;
  if (LOBYTE((*workdata)->ExBefore) < typeHierarchyDepth
    || *(*&v4->Sin + 8 * typeHierarchyDepth - 8) != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(*&v4->TargetLightDir.x, dds3UnitObjectBasicWorkData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[4];
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
LABEL_17:
        if (movesys)
          goto LABEL_22;
        v19 = 0;
        (*h)->Flag &= ~2u;
LABEL_21:
        (*h)->MoveType = v19;
LABEL_22:
        if (movedir)
        {
          if (movedir != 1)
            goto LABEL_27;
          v20 = *h;
          v21 = (*h)->Flag | 4;
        }
        else
        {
          v20 = *h;
          v21 = (*h)->Flag & 0xFFFFFFFB;
        }
        v20->Flag = v21;
LABEL_27:
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
LABEL_35:
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
        goto LABEL_35;
      }
    }
    else
    {
      dds3PathBasicControlSetRatio(&pControl, 0.0);
      dds3PathBasicControlAlterMode(&pControl, 0);
      if (movesys != 1)
        goto LABEL_17;
    }
    (*h)->Flag |= 2u;
    v19 = 3;
    goto LABEL_21;
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
LABEL_14:
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
    goto LABEL_14;
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
  long f64 v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 v8;
  s8 v9;
  Il2CppObject *v10;
  dds3UnitObjectBasicWorkData_t_c *v11;
  Il2CppClass *v12;
  s64 v13;
  evtUnitHandle_t_o *v14;
  struct dds3Basic_t_o *Owner;
  s8 v16;
  u32 Flag;
  u32 EVTFLAG;
  u32 v20;
  struct System_Byte_array *ExFlags;
  char *max_length;
  u64 v23;
  evtUnitHandle_t_o *v26;
  u32 v27;
  UnityEngine_Object_o *modelobj;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *Child;
  UnityEngine_Animator_o *modelanm;
  s32 v32;
  datUnitWork_t_o *v34;
  struct datUnitMotion_s_array *v35;
  u32 v36;
  f32 motionsp;
  f32 WaitSpeed;
  f32 v42;
  evtUnitHandle_t_ActionDelegate_o *v43;
  u32 v44;
  evtUnitHandle_t_o *v45;
  f32 Ratio;
  UnityEngine_Object_o *v47;
  s32 v48;
  s32 v49;
  s32 v50;
  s32 v51;
  evtUnitHandle_t_o *v52;
  s32 v53;
  s32 v54;
  s32 v55;
  s32 v56;
  s32 NowMotion;
  s32 NowBefore;
  s32 NowSmooth;
  UnityEngine_Transform_o *v60;
  UnityEngine_Transform_o *v61;
  UnityEngine_Animator_o *v62;
  s32 v63;
  s32 v64;
  s32 v66;
  s32 v67;
  s32 WaitBefore;
  s32 WaitSmooth;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  s16 MovePara1;
  s32 v75;
  s32 v76;
  s32 v77;
  s32 v78;
  s32 v80;
  s32 v81;
  s32 v82;
  evtUnitHandle_t_o *v83;
  u32 MoveType;
  bool v85;
  evtUnitHandle_t_ActionDelegate_o *Action;
  evtUnitHandle_t_o *v87;
  f32 v88;
  struct dds3Basic_t_o *v89;
  s64 i;
  struct System_Byte_array *v91;
  u64 v92;
  struct System_Byte_array *v94;
  evtUnitHandle_t_o *v96;
  s32 IsSpeakStart;
  struct System_Byte_array *v98;
  struct System_Byte_array *v100;
  char *v102;
  s32 v103;
  u64 *v104;
  struct System_Int16_array *ExNowMotion;
  Il2CppObject *v106;
  u64 *v109;
  struct System_Byte_array *v111;
  char *v113;
  struct System_Int16_array *v114;
  struct System_Int16_array *ExBefore;
  s32 v117;
  struct System_Int16_array *ExSmooth;
  s32 v120;
  s32 v122;
  UnityEngine_Object_o *KutiManager;
  struct System_Byte_array *v125;
  struct System_Byte_array *v128;
  struct System_Int16_array *ExWaitMotion;
  s32 v132;
  evtUnitHandle_t_o *v133;
  u32 v134;
  s32 Frame;
  s32 MoveTimer;
  s32 StopTimer;
  s16 v138;
  struct dds3Basic_t_o *v139;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Component_o *Animator;
  UnityEngine_GUILayer_o *Component_GUILayer;
  nbMainProcessData_t_o *MainProcessData;
  nbMainProcessData_t_o *v146;
  u64 j;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v150;
  s32 v151;
  datUnitWork_t_o *v152;
  UnityEngine_GameObject_o *v153;
  datUnitWork_t_o *v154;
  Il2CppObject *Component_object;
  bool v157;
  UnityEngine_Transform_o *v158;
  UnityEngine_Component_o *v159;
  UnityEngine_GUILayer_o *v160;
  s32 WaitMotion;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 id;
  struct datUnitMotion_s_array *motion;
  s32 v169;
  s32 MotionFrameForUnity_26969536;
  evtUnitHandle_t_o *v171;
  s32 v172;
  f32 v174;
  char *v175;
  s64 *v176;
  char *v177;
  s64 *v178;
  s32 v179;
  s32 v180;
  s16 v181;
  evtUnitHandle_t_o *h;
  char v183[16];
  char *v184;
  UnityEngine_Vector4_o v185;

  h = 0;
  workdata = basic->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v183);
    if ((v183[0] & 1) != 0)
      v175 = v184;
    else
      v175 = &v183[1];
    v176 = sub_8C4940(v175);
  }
  v8 = workdata[4].klass;
  v9 = fldProcCheckFlag(0x40u);
  v10 = basic->workdata;
  v12 = v10->klass;
  if (v10->klass->_2.typeHierarchyDepth < v13
    || v12->_2.typeHierarchy[v13 - 1] != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(v12->_1.element_class, dds3UnitObjectBasicWorkData_t, v183);
    if ((v183[0] & 1) != 0)
      v177 = v184;
    else
      v177 = &v183[1];
    v178 = sub_8C4940(v177);
  }
  v14 = v10[2].klass;
  h = v14;
  if (!v14)
    return 0;
  Owner = v14->Owner;
  v16 = v9;
  if (!Owner)
  {
LABEL_14:
    if ((Owner & (v16 != 0)) == 0)
      goto LABEL_29;
LABEL_17:
    Flag = v14->Flag;
    if ((EVTFLAG & Flag) != 0)
    {
      v20 = v14->Flag;
      ExFlags = v14->ExFlags;
      v14->Flag = v20 & ~EVTFLAG;
      max_length = ExFlags->max_length;
      if (max_length >= 1)
      {
        v23 = 0;
        do
        {
          max_length = ExFlags + v23++;
          max_length[32] = 0;
          ExFlags = h->ExFlags;
          LODWORD(max_length) = ExFlags->max_length;
        }
        while (v23 < max_length);
      }
    }
    goto LABEL_29;
  }
  if (IsNullOrEmpty(Owner->name))
  {
    LOBYTE(Owner) = 0;
    goto LABEL_14;
  }
  if (op_Equality(v14->Owner->name, "PLAYER_UNIT", 0) && v16 != 0)
    goto LABEL_17;
LABEL_29:
  UnitAnime(&h, v11);
  v26 = h;
  switch (h->Stat)
  {
    case 0:
    case 3:
      v27 = h->Flag;
      if ((v27 & 0x80) != 0)
      {
        if (v8)
        {
          mdlAnimSetBattle(&h, h->NowMotion);
        }
        else
        {
          NowMotion = h->NowMotion;
          NowBefore = h->NowBefore;
          NowSmooth = h->NowSmooth;
          if ((v27 & 1) != 0)
          {
            mdlSmoothLoopMotionForUnity(&h, 0, NowMotion, NowBefore, NowSmooth, 0, 0);
          }
          else
          {
            mdlSmoothSingleMotionForUnity(&h, 0, NowMotion, NowBefore, NowSmooth, 0);
          }
        }
        h->Flag &= ~0x80u;
      }
      else
      {
        if ((v27 & 0x20) == 0)
          goto LABEL_135;
        if (v8)
        {
          modelobj = h->modelobj;
          if (op_Equality(modelobj, 0, 0))
            return 0;
          transform = get_transform(h->modelobj, 0);
          Child = GetChild(transform, 0);
          modelanm = h->modelanm;
          if (mdlChkMotionEndBattleDying(h, Child, modelanm))
            goto LABEL_41;
          WaitMotion = h->WaitMotion;
          if (mdlGetMotionMinorNumForUnity(&h, 0) != WaitMotion
            && mdlChkMotionEndBattle(h, Child, modelanm))
          {
            formindex = h->formindex;
            UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
            if (!h->WaitMotion)
            {
              if (datCheckDying(UnitWorkFromFormindex))
              {
                id = UnitWorkFromFormindex->id;
                if (!UnitWorkFromFormindex->id)
                  goto LABEL_345;
                motion = Get(id, 0)->motion;
                if (motion->m_Items[22]->motion_no)
LABEL_345:
                  h->WaitMotion = 22;
              }
            }
            if (h->WaitMotion == 22)
            {
              if (!datCheckDying(UnitWorkFromFormindex))
                h->WaitMotion = 0;
            }
LABEL_41:
            v32 = h->formindex;
            v34 = nbGetUnitWorkFromFormindex(v32);
            v35 = nbGetUnitVisual(v34)->motion;
            v36 = h->WaitMotion;
            motionsp = v35->m_Items[h->WaitMotion]->motionsp;
            mdlAnimSetBattle(&h, v36);
            WaitSpeed = h->WaitSpeed;
            mdlSetMotionSpeedForUnity(&h, 0, WaitSpeed);
            if (motionsp == h->WaitSpeed)
              v42 = h->WaitSpeed;
            else
              v42 = motionsp;
            mdlSetMotionSpeedAnimator(modelanm, v42);
LABEL_129:
            h->Frame = 0;
            goto LABEL_135;
          }
          v169 = h->WaitMotion;
          if (mdlGetMotionMinorNumForUnity(&h, 0) == v169
            && mdlChkMotionEndBattle(h, Child, modelanm))
          {
            goto LABEL_41;
          }
        }
        else
        {
          v64 = h->WaitMotion;
          if (mdlGetMotionMinorNumForUnity(&h, 0) != v64)
          {
            if (mdlChkMotionEndForUnity(&h, 0))
              goto LABEL_125;
          }
          v66 = h->WaitMotion;
          if (mdlGetMotionMinorNumForUnity(&h, 0) == v66)
          {
            if (mdlChkMotionEndForUnity(&h, 0))
            {
LABEL_125:
              v67 = h->WaitMotion;
              WaitBefore = h->WaitBefore;
              WaitSmooth = h->WaitSmooth;
              mdlSmoothLoopMotionForUnity(&h, 0, v67, WaitBefore, WaitSmooth, 0, 0);
              mdlSetMotionSpeedForUnity(&h, 0, h->WaitSpeed);
              goto LABEL_129;
            }
          }
        }
      }
LABEL_135:
      v44 = (h->Flag >> 6) & 1;
      if (h->Stat != 3)
        goto LABEL_142;
      x = h->PosTarget.x;
      y = h->PosTarget.y;
      z = h->PosTarget.z;
      w = h->PosTarget.w;
      MovePara1 = h->MovePara1;
      v185.x = x;
      v185.y = y;
      v185.z = z;
      v185.w = w;
      if (!evtUnitRotationQuat(&h, v185, MovePara1 / 100.0, v26))
      {
LABEL_142:
        v49 = 0;
        goto LABEL_190;
      }
LABEL_140:
      v49 = 0;
LABEL_141:
      h->Stat = 0;
      goto LABEL_190;
    case 1:
      if (evtCheckMoveEnd(&h, v26) != 1)
        goto LABEL_158;
      v45 = h;
      if (h->Stat != 1 || h->TargetType != 2)
        goto LABEL_108;
      Ratio = dds3PathBasicControlGetRatio(&h->Path);
      v45 = h;
      if ((h->Flag & 4) != 0)
      {
        if (Ratio == 0.0)
          goto LABEL_108;
      }
      else if (Ratio == 1.0)
      {
        goto LABEL_108;
      }
      dds3PathBasicControlSetRatio(
        &h->Path,
        fminf(fmaxf(Ratio + h->PathStep, 0.0), 1.0),
        0);
      dds3PathBasicControlGetPos(&h->Path);
      SDF_VU0__STOREVECTOR(&h->PosTarget);
LABEL_158:
      v78 = h->NowMotion;
      if (mdlGetMotionMinorNumForUnity(&h, 0) == v78)
        goto LABEL_176;
      v80 = h->NowMotion;
      v81 = h->NowBefore;
      v82 = h->NowSmooth;
      if ((h->Flag & 1) != 0)
      {
        mdlSmoothLoopMotionForUnity(&h, 0, v80, v81, v82, 0, 0);
LABEL_176:
        v83 = h;
        MoveType = h->MoveType;
        v85 = MoveType == 2;
        if (MoveType < 2)
        {
LABEL_167:
          evtUnitMoveType0(&h);
          v49 = 1;
          v26 = h;
          Action = h->Action;
          if (!Action)
            goto LABEL_189;
          goto LABEL_187;
        }
      }
      else
      {
        mdlSmoothSingleMotionForUnity(&h, 0, v80, v81, v82, 0);
        v83 = h;
        MoveType = h->MoveType;
        v85 = MoveType == 2;
        if (MoveType < 2)
          goto LABEL_167;
      }
      if (v85)
      {
        v49 = 0;
        v26 = h;
        Action = h->Action;
        if (!Action)
          goto LABEL_189;
      }
      else if (MoveType == 3)
      {
        evtUnitMoveTypePathTrace(&h);
        v49 = 1;
        v26 = h;
        Action = h->Action;
        if (!Action)
          goto LABEL_189;
      }
      else
      {
        v49 = 0;
        v83->Stat = 0;
        v26 = h;
        Action = h->Action;
        if (!Action)
          goto LABEL_189;
      }
LABEL_187:
      if (evtUnitHandle_t_ActionDelegate__Invoke(Action, v26, 0) == 1)
      {
        v44 = 0;
        goto LABEL_141;
      }
LABEL_189:
      v44 = 0;
      goto LABEL_190;
    case 2:
      if (v8)
      {
        v47 = h->modelobj;
        if (op_Equality(v47, 0, 0))
          return 0;
        v60 = get_transform(h->modelobj, 0);
        v61 = GetChild(v60, 0);
        if (h->Frame)
        {
          v62 = h->modelanm;
          v63 = mdlChkMotionEndBattle(h, v61, v62);
          v45 = h;
          if (v63)
          {
LABEL_108:
            v44 = 0;
            v49 = 0;
            v45->Stat = 0;
            goto LABEL_190;
          }
          if ((h->Flag & 0x800000) == 0)
          {
LABEL_150:
            v44 = 0;
            v49 = 0;
            goto LABEL_190;
          }
          MotionFrameForUnity_26969536 = mdlGetMotionFrameForUnity_26969536(&h, 0);
          v171 = h;
          v44 = 0;
          v49 = 0;
          if (MotionFrameForUnity_26969536 < h->MotEndFrame)
            goto LABEL_190;
          h->Flag &= ~0x800000u;
          v171->Stat = 4;
          v172 = v171->WaitMotion;
          v44 = 0;
          v49 = 0;
          if (mdlGetMotionMinorNumForUnity(&h, 0) == v172)
            goto LABEL_190;
          mdlAnimSetBattle(&h, h->WaitMotion);
          v174 = h->WaitSpeed;
          mdlSetMotionSpeedForUnity(&h, 0, v174);
          mdlSetMotionSpeedAnimator(v62, h->WaitSpeed);
          goto LABEL_370;
        }
        mdlAnimSetBattle(&h, h->NowMotion);
LABEL_155:
        v44 = 0;
        v49 = 0;
        h->Flag &= ~0x80u;
        goto LABEL_190;
      }
      if (!h->Frame)
      {
        v75 = h->NowMotion;
        v76 = h->NowBefore;
        v77 = h->NowSmooth;
        if ((h->Flag & 1) != 0)
        {
          mdlSmoothLoopMotionForUnity(&h, 0, v75, v76, v77, 0, 0);
        }
        else
        {
          mdlSmoothSingleMotionForUnity(&h, 0, v75, v76, v77, 0);
        }
        goto LABEL_155;
      }
      v50 = mdlChkMotionEndForUnity(&h, 0);
      v45 = h;
      if (v50)
        goto LABEL_108;
      if ((h->Flag & 0x800000) == 0)
        goto LABEL_150;
      v51 = mdlGetMotionFrameForUnity_26969536(&h, 0);
      v52 = h;
      v44 = 0;
      v49 = 0;
      if (v51 < h->MotEndFrame)
        goto LABEL_190;
      h->Flag &= ~0x800000u;
      v52->Stat = 4;
      v53 = v52->WaitMotion;
      v44 = 0;
      v49 = 0;
      if (mdlGetMotionMinorNumForUnity(&h, 0) == v53)
        goto LABEL_190;
      v54 = h->WaitMotion;
      v55 = h->WaitBefore;
      v56 = h->WaitSmooth;
      mdlSmoothLoopMotionForUnity(&h, 0, v54, v55, v56, 0, 0);
      mdlSetMotionSpeedForUnity(&h, 0, h->WaitSpeed);
LABEL_370:
      v44 = 0;
      v49 = 0;
      h->Frame = 0;
LABEL_190:
      v87 = h;
      v179 = v49;
      if (h->Flag & 0x400000 | v44)
      {
        v88 = h->Sin + 0.0;
        v89 = h->Owner;
        if (v88 >= 6.2832)
          v88 = v88 + -6.2832;
        h->Sin = v88;
        v89->poseset->flag |= 1u;
        v87->Owner->poseset->flag &= ~2u;
      }
      v180 = v8;
      for (i = 0; ; ++i)
      {
        v91 = v87->ExFlags;
        v92 = i + 1;
        if ((v91->m_Items[i + 1] & 1) != 0)
        {
          v94 = h->ExFlags;
          if ((v94->m_Items[i + 1] & 2) != 0)
          {
            v96 = h;
            if (v92 == h->KutiGroup)
            {
              IsSpeakStart = IsSpeakStart();
              v98 = h->ExFlags;
              if ((((v98->m_Items[i + 1] & 0x24) == 0) & ~IsSpeakStart) != 0)
                goto LABEL_230;
              v96 = h;
            }
            v100 = v96->ExFlags;
            v102 = v100 + i;
            v103 = i + 1;
            v102[33] &= ~2u;
            *v183 = i + 1;
            v104 = sub_8D3950(s32, v183);
            ExNowMotion = h->ExNowMotion;
            v106 = v104;
            v181 = ExNowMotion->m_Items[i + 1];
            v109 = sub_8D3950(s16, &v181);
            Write_2930752("set exmot {0:D}_{1:D}\n", v106, v109);
            v111 = h->ExFlags;
            v113 = v111 + i;
            v114 = h->ExNowMotion;
            ExBefore = h->ExBefore;
            v117 = v114->m_Items[i + 1];
            ExSmooth = h->ExSmooth;
            v120 = ExBefore->m_Items[i + 1];
            v122 = ExSmooth->m_Items[i + 1];
            if ((v113[33] & 8) != 0)
            {
              mdlSmoothLoopMotionForUnity(&h, v103, v117, v120, v122, 0, 0);
              if (v92 != h->KutiGroup)
                goto LABEL_257;
              goto LABEL_231;
            }
            mdlSmoothSingleMotionForUnity(&h, v103, v117, v120, v122, 0);
          }
LABEL_230:
          if (v92 != h->KutiGroup)
            goto LABEL_257;
LABEL_231:
          KutiManager = GetKutiManager();
          if (op_Equality(KutiManager, 0, 0) || !Contains(KutiManager, 0))
          {
            else if (IsSpeaking(0))
            {
              goto LABEL_257;
            }
            v125 = h->ExFlags;
            if ((v125->m_Items[i + 1] & 0x24) == 0)
            {
              mdlMotionStopKutiForUnity(&h, i + 1, 0);
                goto LABEL_258;
              goto LABEL_249;
            }
          }
LABEL_257:
          {
LABEL_258:
            if (mdlChkMotionEndForUnity(&h, i + 1))
            {
              v128 = h->ExFlags;
              if ((v128->m_Items[i + 1] & 4) != 0)
              {
                ExWaitMotion = h->ExWaitMotion;
                v132 = ExWaitMotion->m_Items[i + 1];
                mdlSmoothLoopMotionForUnity(&h, i + 1, v132, 0, 0, 0, 0);
              }
            }
            goto LABEL_268;
          }
LABEL_249:
          goto LABEL_258;
        }
LABEL_268:
        if (i == 10)
          break;
        v87 = h;
      }
      v133 = h;
      v134 = h->Flag;
      v48 = v179;
      if ((v134 & 0x20000) == 0)
      {
        h->PublicLightPacket = 0;
        if ((v134 & 0x40700) != 0)
        {
          SDF_VU0__dds3ColorItoF(v133->NowLightRGB);
          SDF_VU0__LOADVECTOR(h->NowLightDir);
          SDF_VU0__dds3ColorItoF(h->NowAmbientRGB);
          v133 = h;
          h->PublicLightPacket = h->PrivateLightPacket;
        }
      }
      Frame = v133->Frame;
      if (Frame != 0x7FFF)
        v133->Frame = Frame + 1;
      if (v179)
      {
        MoveTimer = v133->MoveTimer;
        if (MoveTimer != 0x7FFF)
          v133->MoveTimer = MoveTimer + 1;
        v133->StopTimer = 0;
        if ((v133->modeflg & 1) == 0)
          goto LABEL_299;
LABEL_286:
        ++v133->modeframe;
        v139 = v133->Owner;
        if (v139)
        {
          gameObject = v139->gameObject;
          if (op_Inequality(gameObject, 0, 0))
          {
            Animator = GetAnimator(gameObject);
            Component_GUILayer = GetComponent_GUILayer_(Animator);
            if (op_Inequality(Component_GUILayer, 0, 0))
              SetFrame(Component_GUILayer, h->modeframe, 0);
          }
        }
        goto LABEL_299;
      }
      StopTimer = v133->StopTimer;
      if (StopTimer == 0x7FFF || (v138 = StopTimer + 1, v133->StopTimer = v138, v138 >= 6))
        v133->MoveTimer = 0;
      if ((v133->modeflg & 1) != 0)
        goto LABEL_286;
LABEL_299:
      if (v180 == 1)
      {
        MainProcessData = nbGetMainProcessData();
        if (MainProcessData)
        {
          LODWORD(v3) = 1.0;
          v146 = MainProcessData;
          for (j = 0; j != 32; ++j)
          {
            form = v146->form;
            v150 = form->m_Items[j];
            v151 = v150->formindex;
            v152 = nbGetUnitWorkFromFormindex(v151);
            if ((v150->anime & 0x80) != 0)
            {
              v153 = v150->modelobj;
              v154 = v152;
              {
              }
              if (op_Inequality(v153, 0, 0))
              {
                Component_object = GetComponent_object_(v153);
                {
                }
                v157 = op_Inequality(Component_object, 0, 0);
                if (v154 && v157 && (v154->badstatus & 0x400) != 0)
                  (Component_object->klass->vtable[24].methodPtr)(
                    Component_object,
                    Component_object->klass->vtable[24].v3);
                v158 = get_transform(v153, 0);
                v159 = GetChild(v158, 0);
                v160 = GetComponent_GUILayer_(v159);
                set_speed(v160, 0.0);
              }
            }
          }
        }
      }
      return v48;
    case 4:
      v43 = h->Action;
      if (!v43)
      {
        v44 = 0;
        v49 = 0;
        h->Stat = 0;
        goto LABEL_190;
      }
      if (evtUnitHandle_t_ActionDelegate__Invoke(v43, h, 0) != 1)
        goto LABEL_150;
      v44 = 0;
      goto LABEL_140;
    default:
      return 0;
  }
}

// 0x1958960
s32 evtUnitMoveType0(evtUnitHandle_t **h) {
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  s16 MovePara2;
  int16x4_t v10;
  dds3Basic_t_o **p_Owner;
  s64 v13;
  f32 v14;
  f32 v15;
  UnityEngine_Vector4_o v17;
  UnityEngine_Vector4_o v18;
  UnityEngine_Vector4_o v19;

  *&v17.x = 0;
  *&v17.z = 0;
  sub_854690(&v17.x, 0.0, 0.0, 0.0, 0.0);
  x = (*h)->PosTarget.x;
  y = (*h)->PosTarget.y;
  z = (*h)->PosTarget.z;
  w = (*h)->PosTarget.w;
  MovePara2 = (*h)->MovePara2;
  v18.x = x;
  v18.y = y;
  v18.z = z;
  v18.w = w;
  evtUnitRotationTarget(h, v18, MovePara2 * 0.01);
  if ((*h)->MovePara2)
  {
    evtGetUnitDirVector(h);
  }
  else
  {
    SDF_VU0__LOADVECTOR((*h)->PosTarget, 0);
    SDF_VU0__LOADVECTOR_B((*h)->Owner->poseset->pos, 0);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__NORMALIZE();
  }
  v10.n64_u16[0] = (*h)->MovePara1;
  SDF_VU0__SCALEVECTOR(vmovl_s16(v10).n128_i32[0] * 0.1, 0);
  SDF_VU0__STOREVECTOR(&v17);
  p_Owner = &(*h)->Owner;
  v13 = *&v17.x;
  v15 = v17.z;
  v14 = v17.w;
  *&v19.x = v13;
  v19.z = v15;
  v19.w = v14;
  dds3AddPosPoseSet(p_Owner, v19);
  return 1;
}

// 0x1958b30
s32 evtUnitMoveTypePathTrace(evtUnitHandle_t **h) {
  dds3Basic_t_o **p_Owner;
  s64 v5;
  s64 v6;
  dds3Basic_t_o **v8;
  s64 v9;
  s64 v10;
  UnityEngine_Vector4_o v12;
  UnityEngine_Vector4_o v13;
  UnityEngine_Vector4_o v14;

  *&v12.x = 0;
  *&v12.z = 0;
  sub_854690(&v12.x, 0.0, 0.0, 0.0, 0.0);
  dds3PathBasicControlNextStep(&(*h)->Path, 0);
  dds3PathBasicControlGetPos(&(*h)->Path, 0);
  SDF_VU0__STOREVECTOR(&v12);
  p_Owner = &(*h)->Owner;
  v5 = *&v12.x;
  v6 = *&v12.z;
  *&v13.x = v5;
  *&v13.z = v6;
  dds3SetPosPoseSet(p_Owner, v13);
  if (((*h)->Flag & 0x10) != 0)
  {
    dds3PathBasicControlGetRot(&(*h)->Path, 0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    FromEuler(0.0, 3.1416, 0.0);
    Mult();
    SDF_VU0__STOREVECTOR(&v12);
    v8 = &(*h)->Owner;
    v9 = *&v12.x;
    v10 = *&v12.z;
    *&v14.x = v9;
    *&v14.z = v10;
    dds3SetRotPoseSet(v8, v14);
  }
  return 1;
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
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  struct dds3PoseSet_t_o *poseset;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v18;
  f32 v19;
  f32 v20;
  dds3Basic_t_o **p_Owner;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o zero;
  UnityEngine_Vector4_o v31;
  UnityEngine_Vector4_o v32;
  UnityEngine_Vector4_o v33;
  UnityEngine_Vector4_o v34;

  w = pos.w;
  z = pos.z;
  y = pos.y;
  x = pos.x;
  *&v31.x = 0;
  *&v31.z = 0;
  *&zero.x = 0;
  *&zero.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  sub_854690(&v31.x, 0.0, 1.0, 0.0, 1.0);
  zero = get_zero();
  p = get_zero();
  evtGetUnitDirVector(h);
  SDF_VU0__COPYVECTOR_A_TO_C();
  poseset = (*h)->Owner->poseset;
  v12 = poseset->pos.x;
  v13 = poseset->pos.y;
  v32.x = x;
  v15 = poseset->pos.z;
  v14 = poseset->pos.w;
  v32.y = y;
  v32.z = z;
  v32.w = w;
  SDF_VU0__LOADVECTOR(v32);
  v33.x = v12;
  v33.y = v13;
  v33.z = v15;
  v33.w = v14;
  SDF_VU0__LOADVECTOR_B(v33);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__SETVECTOR_Y(0.0);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__LOADVECTOR_B(v31);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__COPYVECTOR_C_TO_B();
  v16 = SDF_VU0__INNERPRODUCT();
  SDF_VU0__LOADVECTOR(p);
  v18 = SDF_VU0__INNERPRODUCT();
  if (v18 >= 0.9998)
    return 1;
  v19 = acosf(v18);
  if (v16 > 0.0)
    v19 = -v19;
  v20 = v19 * radio;
  if (((*h)->Flag & 0x200000) == 0)
  {
    v20 = fmaxf(v20, -0.15708);
    if (v20 > 0.15708)
      v20 = 0.15708;
  }
  SDF_VU0__LOADVECTOR(v31);
  FromRotation(v20);
  SDF_VU0__STOREVECTOR(&zero);
  p_Owner = &(*h)->Owner;
  v24 = zero.x;
  v23 = zero.y;
  v26 = zero.z;
  v25 = zero.w;
  v34.x = v24;
  v34.y = v23;
  v34.z = v26;
  v34.w = v25;
  dds3AddRotPoseSet(p_Owner, v34);
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
