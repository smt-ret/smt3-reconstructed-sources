#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct FieldChrHD FieldChrHD;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3Effect_Filter_t dds3Effect_Filter_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fclCombineAct_cmbActCallback_t fclCombineAct_cmbActCallback_t;
typedef struct fclCombineAct_cmbActTimeTableArry_t fclCombineAct_cmbActTimeTableArry_t;
typedef struct fclCombineAct_cmbActTimeTable_t fclCombineAct_cmbActTimeTable_t;
typedef struct mdlEffectResrcList_t mdlEffectResrcList_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;

struct fclCombineAct_cmbActTimeTable_t {
    u32 Frame;
    s8 CallbackType;
    fclCombineAct_cmbActCallback_t *Callback;
};

struct fclCombineAct_cmbActTimeTableArry_t {
    fclCombineAct_cmbActTimeTable_t *pTimeTable;
    s8 Size;
};

static f32 gModelColRate[3];
static f32 gIkenieOfsY;
static s32 gLightMode;
static s32 gLightIkenie;
static s32 gTanjyouDelayCnt;
static dds3Effect_Filter_t *gBlurFilterBuff;
static s32 gModelLoaded;
static char *gModelPosName[4];
static s32 ikenie_effect_cnt;
static fclCombineAct_cmbActTimeTable_t *cmbActTimeTable00[4];
static fclCombineAct_cmbActTimeTable_t *cmbActTimeTable01[7];
static fclCombineAct_cmbActTimeTableArry_t *cmbActTimeTableArry[2];
static s8 gCurrentTimeTableNo;
static s8 gTerminateFlag;
static s8 gSkipSe;
static s8 gSkipSeZiko;
static u32 testcol;

s32 ChkUseMarukage(s32 deveilID);
void CombineAct_ModelLoadEffectForUnity(dds3ModelHandle_t *modelHandle, void *obj, s32 MajorNo, s32 MinorNo);
char *GetAkey(s32 no);
char *GetFname(s32 no);
char *GetPBname(s32 no);
bool IsLoad(AssetBundles *this, char *key);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void Log(char *fmt, void **parray);
void SetLayerAll2(FieldChrHD *this, void *rootobj, s32 setlayer);
dds3Basic_t *dds3GetActiveScene(void);
dds3Basic_t *dds3SceneBasicSearchNameAndType_1(dds3Basic_t *scene, u32 type, char *name);
bool fclChkStartMenu(void);
void mdlEffectCreateUnity(s32 aMajor, s32 aMinor, mdlEffectResrcList_t **efc_res_list, bool loadf);
void mdlFree(dds3ModelHandle_t **aHandle);
bool mdlGenEffect(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aPlayGroup);
FieldChrHD *mdlSetHD(void *obj, s32 mode, evtUnitHandle_t *hunit, s32 layer);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);
sdfModelRootNode_t *sdfModelMakeUnity(sdfModelTexList_t *aTexList, u8 **bData, s32 bPos);

// 0x1965a90
void CombineAct_ModelFreeEffectForUnity(dds3ModelHandle_t *modelHandle) {
  dds3ModelHandle_t_o *v3;
  struct dds3ModelResrc_t_o *resrc;
  dds3ModelHandle_t_o *aHandle;

  aHandle = modelHandle;
  if (modelHandle && modelHandle->resrc)
  {
    mdlFree(&aHandle);
    v3 = aHandle;
    resrc = aHandle->resrc;
    aHandle->effects = 0;
    resrc->effectData = 0;
    v3->resrc->effectResrcList = 0;
    v3->modelRoot->modelobj = 0;
  }
}

// 0x19657c0
void CombineAct_ModelLoadEffectForUnity(dds3ModelHandle_t *modelHandle, void *obj, s32 MajorNo, s32 MinorNo) {
  struct dds3ModelFileKindTable_t_array *modelFileKindTable;
  s32 v11;
  struct dds3ModelFileIndex_t_array *indexTable;
  s32 minor;
  System_String_o *Akey;
  dds3ModelResrc_t_o *v17;
  struct dds3ModelResrc_t_o *resrc;
  struct dds3ModelResrc_t_o *v19;
  u64 *v20;
  s32 v21;
  System_String_o *PBname;
  System_String_o *v23;
  System_Byte_array *v25;
  dds3ModelHandle_t_o *v26;
  mdlEffectResrcList_t_o *efc_res_list;
  System_Byte_array *aTopPtr;
  dds3ModelHandle_t_o *aHandle;

  aHandle = modelHandle;
  efc_res_list = 0;
  aTopPtr = 0;
  if (modelHandle)
  {
    if (MajorNo == 202)
      v11 = 352;
    else
      v11 = MajorNo;
    indexTable = modelFileKindTable->m_Items[v11]->indexTable;
    if (indexTable->m_Items[MinorNo]->minor == 202)
      minor = 352;
    else
      minor = indexTable->m_Items[MinorNo]->minor;
    Akey = GetAkey(minor);
    v17 = Allocate(dds3ModelResrc_t);
    dds3ModelResrc_t___ctor(v17);
    modelHandle->resrc = v17;
    v17->major = MajorNo;
    modelHandle->resrc->minor = MinorNo;
    resrc = modelHandle->resrc;
    modelHandle->effects = 0;
    resrc->effectData = 0;
    v19 = modelHandle->resrc;
    v20 = Allocate(mdlEffectResrcList_t);
    mdlEffectResrcList_t___ctor(v20);
    if (MinorNo == 202)
      v21 = 352;
    else
      v21 = MinorNo;
    v19->effectResrcList = v20;
    PBname = GetPBname(v21);
    v23 = Concat_5221536("dds3data/dvl_pb/", PBname, ".bytes");
    aTopPtr = 0;
    sdfDevLoadFileUnity_25061072(v23, &aTopPtr, 0, Akey);
    v25 = aTopPtr;
    v26 = modelHandle;
    {
      v26 = modelHandle;
    }
    modelHandle->modelRoot = sdfModelMakeUnity(0, v25, 0);
    v26->resrc->effectData = &aTopPtr->obj;
    efc_res_list = v26->resrc->effectResrcList;
    mdlEffectCreateUnity(MajorNo, MinorNo, &efc_res_list, 1);
    v26->resrc->effectResrcList = efc_res_list;
    v26->modelRoot->modelobj = obj;
    mdlGenEffect(&aHandle, -1, -1);
  }
}

// 0x196c0e0
void GetLight(f32 *l0_r, f32 *l0_g, f32 *l0_b, f32 *a0_r, f32 *a0_g, f32 *a0_b, f32 *bias, f32 *v0_x, f32 *v0_y, f32 *v0_z, f32 unity_x, f32 unity_y, f32 unity_z) {
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *v27;
  s32 gLightMode;
  s64 *v34;
  dds3Basic_t_o *v35;
  Il2CppObject *workdata;
  dds3Basic_t_o *v37;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v40;
  s64 *v41;
  s32 v42;
  s32 v43;
  s32 v44;
  s32 v45;
  s32 v46;
  s32 v48;
  f32 v49;
  f32 v51;
  f32 v53;
  struct fldGlobalWork_t_o *fldGb;
  f32 v55;
  f32 v56;
  f32 v57;
  f32 v59;
  f32 v60;
  struct fldGlobalWork_t_o *v61;
  f32 v63;
  f32 v64;
  f32 v65;
  f32 v66;
  f32 v67;
  struct fldGlobalWork_t_o *v70;
  f32 v72;
  s64 v73;
  s32 v74;
  s64 v75;
  f32 v76;
  u64 v77;
  f32 v78;
  u64 v79[3];

  v78 = 0.0;
  v77 = 0;
  v76 = 0.0;
  v75 = 0;
  v74 = 0;
  v73 = 0;
  else
  {
    ActiveScene = dds3GetActiveScene();
    if (!ActiveScene)
      return;
  }
  v27 = ActiveScene;
  else
  {
    if (gLightMode == 2)
      goto LABEL_9;
  }
  else if (gLightMode != 3)
  {
    return;
  }
  v34 = &"light03";
LABEL_39:
  v35 = dds3SceneBasicSearchNameAndType_1(v27, 9u, *v34);
  if (!v35)
    return;
  workdata = v35->workdata;
  v37 = v35;
  if (!workdata)
    return;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3LightObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3LightObjectBasicWorkData_t, v79);
    if ((v79[0] & 1) != 0)
      v40 = v79[2];
    else
      v40 = v79 + 1;
    v41 = sub_8C4940(v40);
  }
  sub_854710(&workdata[1].klass->_1.name, 0);
  *l0_r = v42;
  sub_854710(&workdata[1].klass->_1.name, 1u);
  *l0_g = v43;
  sub_854710(&workdata[1].klass->_1.name, 2u);
  *l0_b = v44;
  sub_854710(&workdata[1].monitor, 0);
  *a0_r = v45;
  sub_854710(&workdata[1].monitor, 1u);
  *a0_g = v46;
  sub_854710(&workdata[1].monitor, 2u);
  *a0_b = v48;
  v49 = (*&workdata[3].klass + -7.0) * 0.125;
  v51 = Clamp01(v49);
  v53 = v51;
  v55 = unity_x * 100.0;
  v56 = unity_y * -100.0;
  v57 = unity_z * 100.0;
  if (fldGb->fieldID != 800)
    goto LABEL_104;
  if (fldGb->areaID != 79)
  {
LABEL_104:
    v61 = fldGb;
    if (v61->fieldID == 800)
    {
      if (v61->areaID == 79)
      {
        if (gLightIkenie)
        {
          v60 = 0.7;
          *l0_g = *l0_g * 0.7;
          *l0_b = *l0_b * 0.7;
          goto LABEL_76;
        }
        a0_b = l0_b;
        v72 = 1.0 - (v53 * 0.2);
        v64 = (v53 * 0.2) + 1.0;
        *l0_r = v72 * *l0_r;
        *l0_g = v72 * *l0_g;
        v67 = *l0_b;
LABEL_84:
        v63 = v64 * v67;
        goto LABEL_85;
      }
    }
    if (fldGb->fieldID != 807)
      goto LABEL_86;
    v64 = (v53 * -0.4) + 1.0;
    *a0_r = v64 * *a0_r;
    *a0_g = v64 * *a0_g;
LABEL_83:
    v67 = *a0_b;
    goto LABEL_84;
  }
  v59 = *l0_r;
  if (!gLightIkenie)
  {
    v65 = (v53 * -0.1) + 1.0;
    *l0_r = v65 * v59;
    *l0_g = v65 * *l0_g;
    v64 = 1.0 - (v53 * 0.2);
    *l0_b = ((v53 * 0.2) + 1.0) * *l0_b;
    v66 = (v53 * -0.4) + 1.0;
    *a0_r = v66 * *a0_r;
    *a0_g = v66 * *a0_g;
    goto LABEL_83;
  }
  *l0_r = v59 * 1.1;
  *l0_g = *l0_g * 0.65;
  *l0_b = *l0_b * 0.65;
  v60 = 0.6;
  *a0_r = *a0_r * 1.1;
LABEL_76:
  *a0_g = *a0_g * v60;
  v63 = *a0_b * v60;
LABEL_85:
  *a0_b = v63;
LABEL_86:
  *bias = *(&workdata[3].klass + 1);
  sub_8524C0(&v77, v37->poseset->pos.x / 100.0, v37->poseset->pos.y / -100.0, v37->poseset->pos.z / 100.0);
  sub_8524C0(&v75, v55 / 100.0, v56 / -100.0, v57 / 100.0);
  v70 = fldGb;
  if (v70->fieldID == 800)
  {
    if (v70->areaID == 79)
    {
      if (gLightIkenie)
      {
        v77 = 0xC080000000000000LL;
        v78 = 2.0;
      }
    }
  }
  sub_8524C0(&v73, *&v75 - *&v77, *(&v75 + 1) - *(&v77 + 1), v76 - v78);
  sub_8531D0(&v73, 0);
  *v0_x = v73;
  *v0_y = *(&v73 + 1);
  *v0_z = v74;
}

// 0x196a640
bool IsMovieSkip(void) {
  if (!fclChkStartMenu())
    return 0;
LABEL_6:
  return CMB_GBWK->MovieSkip != 0;
}

// 0x196c920
void SetLight_From_evtCommand(char *light_name) {
  if (fldGb->fieldID == 807
    && Equals_5234480(light_name, "light03"))
  {
    gLightMode = 3;
  }
}

// 0x1964c90
s32 _MDC(s32 no) {
  if (no == 202)
    return 352;
  return no;
}

// 0x1964e20
bool model_loaded(void) {
  struct cmbGlobalWork_t_o *CMB_GBWK;
  struct cmbModelPack_t_array *ModelPack;
  s64 gModelLoaded;
  u32 DevilID;
  s32 v9;
  System_String_o *Akey;
  System_String_o *v12;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *Fname;
  System_String_o *v16;
  System_String_o *v17;
  System_Object_array *v19;
  AssetBundleCtrl_o *v21;
  System_String_o *v22;
  Il2CppObject *Prefab_16624656;
  struct cmbModelPack_t_array *v29;
  s64 v30;
  cmbModelPack_t_o *v32;
  UnityEngine_GameObject_o *v33;
  UnityEngine_Transform_o *transform;
  struct cmbModelPack_t_array *v36;
  s64 v37;
  UnityEngine_Transform_o *v39;
  struct cmbModelPack_t_array *v40;
  s64 v41;
  UnityEngine_Transform_o *v44;
  UnityEngine_Transform_o *v45;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  f32 v52;
  f32 v53;
  FieldChrHD_o *v56;
  s32 v57;
  System_String_o *PBname;
  System_String_o *v60;
  struct cmbModelPack_t_array *v62;
  s64 v64;
  struct cmbModelPack_t_array *v66;
  s64 v67;
  struct cmbModelPack_t_array *v72;
  s64 v73;
  struct cmbModelPack_t_array *v76;
  s64 v77;
  struct cmbModelPack_t_array *v79;
  s64 v80;
  UnityEngine_Vector3_o v85;
  UnityEngine_Quaternion_o localRotation;
  UnityEngine_Vector3_o zero;
  UnityEngine_Quaternion_o v88;
  UnityEngine_Quaternion_o v89;

  *&localRotation.x = 0;
  *&localRotation.z = 0;
  ModelPack = CMB_GBWK->ModelPack;
  DevilID = ModelPack->m_Items[gModelLoaded]->DevilID;
  if (DevilID == 202)
    v9 = 352;
  else
    v9 = DevilID;
  else
  {
    Akey = GetAkey(v9);
    if (!DevilID)
      goto LABEL_113;
  }
  v12 = Akey;
  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, v12))
    return 0;
  Fname = GetFname(v9);
  if (!Fname)
    goto LABEL_113;
LABEL_27:
  v16 = Fname;
  if (!get_Length(Fname))
    goto LABEL_113;
  v17 = Concat_5271136("====fname:", v16, " :Akey=", v12);
  v19 = Empty_string_();
  Log(v17, v19, 0);
  v21 = get_asset_bc();
  v22 = Concat_5224608("charactor/b/", v16);
  Prefab_16624656 = LoadPrefab_16624656(v21, v12, v22, v16);
  if (op_Inequality(Prefab_16624656, 0, 0))
  {
    v29 = CMB_GBWK->ModelPack;
    v30 = gModelLoaded;
    v32 = v29->m_Items[v30];
    v33 = Find("Character", 0);
    transform = get_transform(v33, 0);
    v32->DevilObj = Instantiate_object__425520(Prefab_16624656, transform);
    v36 = CMB_GBWK->ModelPack;
    v37 = gModelLoaded;
    Prefab_16624656 = v36->m_Items[v37]->DevilObj;
    v39 = get_transform(Prefab_16624656, 0);
    v85.z = 0.0;
    *&v85.x = 0;
    sub_8524C0(&v85.x, 0.0, -10000.0, 0.0);
    set_localPosition(v39, v85);
    v40 = CMB_GBWK->ModelPack;
    v41 = gModelLoaded;
    v40->m_Items[v41]->bEnabled = 0;
    SetActive(Prefab_16624656, 1, 0);
    v44 = get_transform(Prefab_16624656, 0);
    v88 = Euler(0.0, 180.0, 0.0);
    set_localRotation(v44, v88);
    v45 = get_transform(Prefab_16624656, 0);
    Child = GetChild(v45, 0);
    gameObject = get_gameObject(Child);
    AddComponent_object_(gameObject);
    zero = get_zero();
    set_localPosition(Child, zero);
    localRotation = get_localRotation(Child);
    sub_1A1CAE0(&localRotation.x, 0);
    v89 = Euler(v52, 0.0, v53);
    set_localRotation(Child, v89);
    v56 = mdlSetHD(Prefab_16624656, 6, 0, 15);
    v57 = ChkUseMarukage(DevilID);
    if (v57 == 1 || v57 == -1)
      SetLayerAll2(v56, Prefab_16624656, 14);
  }
  PBname = GetPBname(v9);
  v60 = Concat_5221536("dds3data/dvl_pb/", PBname, ".bytes");
  v62 = CMB_GBWK->ModelPack;
  v64 = gModelLoaded;
  v62->m_Items[v64]->pData = 0;
  v66 = CMB_GBWK->ModelPack;
  v67 = gModelLoaded;
  sdfDevLoadFileUnity_25061072(v60, &v66->m_Items[v67]->pData, 0, v12);
  if (gModelLoaded <= 2)
  {
    v76 = CMB_GBWK->ModelPack;
    v77 = gModelLoaded;
    CombineAct_ModelLoadEffectForUnity(v76->m_Items[v77]->Model, Prefab_16624656, 6, DevilID);
    v79 = CMB_GBWK->ModelPack;
    v80 = gModelLoaded;
    v79->m_Items[v80]->cmbAct_MdlEffectSkip = 0;
      goto LABEL_96;
  }
  else
  {
    v72 = CMB_GBWK->ModelPack;
    v73 = gModelLoaded;
    v72->m_Items[v73]->cmbAct_MdlEffectSkip = 1;
    {
LABEL_96:
    }
  }
LABEL_114:
  ++gModelLoaded;
  if (gModelLoaded != LODWORD(CMB_GBWK->ModelPack->max_length))
    return 0;
  gModelLoaded = 0;
  CMB_GBWK->ActFlag = 0;
  return 1;
}
