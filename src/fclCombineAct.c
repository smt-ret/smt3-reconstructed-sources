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
    fclCombineAct_cmbActTimeTable_t pTimeTable[UNKNOWN_ARRAY_SIZE];
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
    v23 = Concat_5221536(StringLiteral_4874, PBname, StringLiteral_4739);
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
    dds3GetActiveScene();
    dds3SceneBasicSearchNameAndType_1(0, 0, 0);
}

// 0x196a640
bool IsMovieSkip(void) {
  if (!fclChkStartMenu())
    return 0;
  return CMB_GBWK->MovieSkip != 0;
}

// 0x196c920
void SetLight_From_evtCommand(char *light_name) {
  if (fldGb->fieldID == 807
    && Equals_5234480(light_name, StringLiteral_15219))
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
    GetAkey(0);
    IsLoad(0, 0);
    GetFname(0);
    Log(0, 0);
    LoadPrefab_16624656(0, 0, 0, 0);
    mdlSetHD(0, 0, 0, 0);
    ChkUseMarukage(0);
    SetLayerAll2(0, 0, 0);
    GetPBname(0);
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    CombineAct_ModelLoadEffectForUnity(0, 0, 0, 0);
    return 0;
}
