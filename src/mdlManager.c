#include "types.h"

typedef struct AnimChecker AnimChecker;
typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct EffectHD EffectHD;
typedef struct FieldChrHD FieldChrHD;
typedef struct GunHD GunHD;
typedef struct ModelHD ModelHD;
typedef struct SwitchMovie SwitchMovie;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct btlKutiManager btlKutiManager;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ModelEffectCtrlr_t dds3ModelEffectCtrlr_t;
typedef struct dds3ModelFileIndex_t dds3ModelFileIndex_t;
typedef struct dds3ModelFileKindTable_t dds3ModelFileKindTable_t;
typedef struct dds3ModelFileTableDef_t dds3ModelFileTableDef_t;
typedef struct dds3ModelFileTable_t dds3ModelFileTable_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ModelResrc_t dds3ModelResrc_t;
typedef struct evtAnimCheck evtAnimCheck;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fileCb_t fileCb_t;
typedef struct fileHandle_t fileHandle_t;
typedef struct mdlEffectResrcList_t mdlEffectResrcList_t;
typedef struct mdlLoadingTag_t mdlLoadingTag_t;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;
typedef struct mdlManager_mdlFileItem_tag mdlManager_mdlFileItem_tag;
typedef struct mdlManager_mdlFileLoadCb_t mdlManager_mdlFileLoadCb_t;
typedef struct mdlManager_mdlFileLoadCb_t_callbackDelegate mdlManager_mdlFileLoadCb_t_callbackDelegate;
typedef struct mdlManager_mdlTbMbAbLoadCb_t mdlManager_mdlTbMbAbLoadCb_t;
typedef struct mdlSetDef_t mdlSetDef_t;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct pacFileCb_t pacFileCb_t;
typedef struct pacFileEndCallback_t pacFileEndCallback_t;
typedef struct pacFileHandle_t pacFileHandle_t;
typedef struct sdf3DLightParallelPacket_t sdf3DLightParallelPacket_t;
typedef struct sdf3DLight_t sdf3DLight_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelDef_t sdfModelDef_t;
typedef struct sdfModelOt_t sdfModelOt_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfModelTexList_t sdfModelTexList_t;
typedef struct sdfMotionCtrlr_t sdfMotionCtrlr_t;
typedef struct sdfMotionPlayBook_t sdfMotionPlayBook_t;
typedef struct sdfPacCallback_t sdfPacCallback_t;
typedef struct sdfPacDecodeResrc_t sdfPacDecodeResrc_t;
typedef struct sdf_PacDecode2_sdfPac2DecodeResrc_t sdf_PacDecode2_sdfPac2DecodeResrc_t;

struct mdlManager_mdlFileItem_tag {
    mdlManager_mdlFileItem_tag *next;
    char *filename;
    u8 activeFile[3];
    u8 *extChar[3];
};

struct mdlManager_AbHeaderParm_t {
    u32 dataSize;
    u32 addrInfoSize;
    u16 group;
    u16 playGroup;
    s16 firstMotion;
    u16 flags;
};

struct mdlManager_mdlTbMbAbLoadCb_t {
    u16 major;
    u16 minor;
    u8 loadTB;
    u8 loadMB;
    u8 loadAB;
    u8 pad;
    u32 regFlags;
    mdlSetDef_t *modelSet;
};

struct mdlManager_mdlFileLoadCb_t {
    u16 major;
    u16 minor;
    u32 regFlags;
    pacFileCb_t *pacHandle;
    mdlManager_mdlFileLoadCb_t_callbackDelegate *callback;
    void *callbackParm;
};

static s32 id_anim;
static void *ci;
static dds3ModelFileKindTable_t *modelFileKindTable[7];
static dds3ModelFileTableDef_t *modelFileTable;
static dds3ModelResrc_t *mdlResrcMajorList[8];
static mdlLoadingTag_t *mdlLoadingMajorList[8];
static s32 mdlDbSemaId;
static char *mdlSetFileName_work_dir;
static mdlManager_mdlFileItem_tag *mdlHddFileListHead;
static sdfMemHandle_t *mdlHddFileIndexHandle;
static dds3ModelFileIndex_t *mdlHddFileIndex;
static sdfMemHandle_t *mdlHddFileTableHandle;
static dds3ModelFileTable_t *mdlHddFileTable;
static void *dante_btl_voice;

void AddDanteGun(void *obj, FieldChrHD *fhdobj, evtUnitHandle_t *hunit);
char *GetAkey(s32 no);
void *GetAnimator(void *obj);
ModelHD *GetCopy(void *rootobj);
void *GetMainCamera(dds3DefaultMain *this);
char *GetPBname(s32 no);
u8 **GetPibArray(u8 **bData, s32 bPos);
bool IsFinished2(AnimChecker *this, s32 LayerIndex);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name);
void MultMatrixRev(sdfMatrix4_t *aMatrix);
void MultMatrixRevNoArg(void);
void Play(SwitchMovie *this, char *filename, s32 Layer);
void PlayFrameControl(AnimChecker *this, s32 motion);
void ResetFlag(evtAnimCheck *this, evtUnitHandle_t *hndl, s32 LayerIndex);
void RetTransparent(void *obj);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYMATRIX_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__PERSVECTOR(void);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SCALE_XYZ(void);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STORE_ROW0(sdfVector4_t *p);
void SDF_VU0__STORE_ROW1(sdfVector4_t *p);
void SDF_VU0__STORE_ROW2(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void SDF_VU0__dds3ColorItoF(u32 rgba);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetBattle(FieldChrHD *this, f32 flg);
void SetEveUnit(GunHD *this, evtUnitHandle_t *hunit_tmp);
s32 SetForm(nbEventProcessData_t *ed);
void SetKutiName(btlKutiManager *this, char *name);
void SetLayer(FieldChrHD *this, s32 layer_tmp);
void SetModelObject(FieldChrHD *this, void *chr, void *kage);
void SetRasterLevel(FieldChrHD *this, f32 val);
void SetTransparent(void *obj, u32 rgba, f32 alfrgb);
void SetUpdateRot(EffectHD *this, s32 rot);
sdfMotionPlayBook_t *SetsdfMotionPlayBook(u8 **pData, s32 addr);
void StopKUTI(AnimChecker *this, s32 LayerIndex, s32 ExMot);
char *StrRChr(char *stringToSearch, u16 charToFind);
void TbMbAbLoadEnd(mdlManager_mdlTbMbAbLoadCb_t **tmaCb);
void ToMatrix(void);
void UpdateGlobal(FieldChrHD *this);
void billAlfRaitoSet(f32 raito);
void billCutRaitoSet(f32 raito);
bool evtBitCheck(s32 no);
void *fileGetLoadPtr(fileCb_t *fileHandle);
sdfMemHandle_t *fileGetMemHandle(fileHandle_t *fileHandle);
s32 fileHandleFree(fileHandle_t *fileHandle);
s32 fileManager(void);
s8 fldProcCheckFlag(u32 flag);
void fpCutRaitoSet(s32 raito);
s32 getframe_for_unity(void *anim, s32 index);
s32 is_devil(void *obj);
s32 is_eventdevil(char *name);
s32 mdlChkMotionEndForUnity_26964128(void *obj, s32 index);
void mdlCreateEffectResrc_D3P(mdlEffectResrcList_t **listPtr, void *data, void **pTexture);
sdfMotionCtrlr_t *mdlCreateMotion(dds3ModelHandle_t **aHandle, s32 aGroup);
void mdlEffectCreatePipeForUnity(s32 aMajor, s32 aMinor, mdlEffectResrcList_t **efc_res_list);
void mdlEffectCreateUnity(s32 aMajor, s32 aMinor, mdlEffectResrcList_t **efc_res_list, bool loadf);
void mdlEffectResrcListFree(mdlEffectResrcList_t *efcResList);
s32 mdlFileLoad(s32 major, s32 minor, u32 regFlags, char *filename, mdlManager_mdlFileLoadCb_t_callbackDelegate *callback, void *parm);
void mdlFree(dds3ModelHandle_t **aHandle);
void mdlFreeEffect(dds3ModelEffectCtrlr_t *aCtrlr);
void mdlFreeMotionCtrlr(dds3ModelHandle_t **aHandle, sdfMotionCtrlr_t *aCtrlr);
bool mdlGenEffect(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aPlayGroup);
void mdlLinkBlur(dds3ModelHandle_t **aHandle);
void mdlLinkEffect(dds3ModelHandle_t **aHandle, dds3ModelEffectCtrlr_t **aEffect, void *modelobj);
void mdlLinkEffectOff(dds3ModelHandle_t **aHandle, dds3ModelEffectCtrlr_t **aEffect, void *modelobj);
void mdlMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, s32 aType, f32 aBeforeLeng, f32 aSmoothLeng);
sdfPacDecodeResrc_t *mdlPackSet(sdfPacDecodeResrc_t **resrc, s32 major, s32 minor, u32 regFlags);
s32 mdlPibGetMotionCount(void *data, s32 bPos);
void mdlRegLoading(s32 aMajor, s32 aMinor);
void mdlRegist(s32 aMajor, s32 aMinor, s32 aFlag, sdfModelTexList_t **aTexList, sdfModelDef_t **aData, sdfMemHandle_t **aHandle);
void mdlRegistModelSet(s32 aMajor, s32 aMinor, s32 aFlag, mdlSetDef_t *aSet);
void mdlRegistMotion(s32 aMajor, s32 aMinor, s32 aFlags, s32 aFirstMotion, s32 aGroup, s32 aPlayGroup, sdfMotionPlayBook_t **aData, sdfMemHandle_t **aHandle);
void mdlSetEffectColorSub(dds3ModelHandle_t **aHandle, dds3ModelEffectCtrlr_t **aEffect, u32 aColor);
void mdlSetEffectScaleSub(dds3ModelHandle_t **aHandle, dds3ModelEffectCtrlr_t **aEffect, f32 aScale);
void mdlStopEffect(dds3ModelHandle_t **aHandle, s32 aPlayGroup);
void mdlUnRegist(s32 aMajor, s32 aMinor);
void mdlUnRegistResrc(dds3ModelResrc_t **resrc_p);
void mdlUnRegistResrcMotion(dds3ModelResrc_t **aResrc, s32 aGroup);
void mdlUnlinkResrc(dds3ModelHandle_t **aHandle);
dds3ModelResrc_t *mdlWaitLoadEnd(s32 aMajor, s32 aMinor);
s32 pacFileHandleFree(pacFileCb_t *pacHandle);
pacFileCb_t *pacLoadEx(char *filename, s32 headOrTail, sdfPacCallback_t *callback, pacFileEndCallback_t *pendCallback, void *callbackParm);
void pacSync(pacFileHandle_t *pacFileHandle);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);
sdfModelDef_t *sdfFixupModelBinary(void *aData);
sdfMotionPlayBook_t *sdfFixupMotionBinary(void *aData);
void sdfModelEvalTm(sdfModelRootNode_t **aRoot);
void sdfModelLinkOt(sdfModelOt_t **aOt, sdfModelRootNode_t **aRoot);
sdfModelRootNode_t *sdfModelMakeUnity(sdfModelTexList_t *aTexList, u8 **bData, s32 bPos);
void sdfModelRootFree(sdfModelRootNode_t **aRoot, s32 aReleaseNodes, s32 aReleaseMatList);
void sdfMotionChangeBlend(sdfMotionCtrlr_t *aCtrlr, s32 aCutNum, s32 aType, f32 aPreFrame, f32 aBlendLeng);
void sdfMotionCtrlrFree(sdfMotionCtrlr_t **aCtrlr);
sdfMotionCtrlr_t *sdfMotionCtrlrNew(sdfModelRootNode_t *aModel, sdfMotionPlayBook_t *aBook);
s32 sdfMotionNext(sdfMotionCtrlr_t *aCtrlr);
void sdfMotionPause(sdfMotionCtrlr_t *aCtrlr);
void sdfMotionPauseOff(sdfMotionCtrlr_t *aCtrlr);
sdf_PacDecode2_sdfPac2DecodeResrc_t *sdfPacFreeResrc(sdf_PacDecode2_sdfPac2DecodeResrc_t *resrc);
void sdfTexListFree(sdfModelTexList_t *aList, s32 aReleaseItems);
void sdfTexListSetClutColor(sdfModelTexList_t *aList, u32 aColor, f32 aRatio);
sdfModelTexList_t *sdfTexSetTB(void *aData);

// 0x19ace30
void AbLoadCallback(fileHandle_t **fileHandle, mdlManager_mdlTbMbAbLoadCb_t *parm) {
  struct mdlSetDef_t_o *modelSet;
  fileCb_t_o *v6;
  struct mdlSetDef_t_o *v7;
  Il2CppObject *LoadPtr;
  mdlManager_mdlTbMbAbLoadCb_t_o *tmaCb;

  tmaCb = parm;
  modelSet = parm->modelSet;
  v6 = *fileHandle;
  modelSet->playbookHandle = fileGetMemHandle(v6);
  v7 = parm->modelSet;
  LoadPtr = fileGetLoadPtr(*fileHandle);
  v7->playbookPtr = sdfFixupMotionBinary(LoadPtr);
  fileHandleFree(*fileHandle);
  TbMbAbLoadEnd(&tmaCb);
}

// 0x19b8a00
void AddDanteGun(void *obj, FieldChrHD *fhdobj, evtUnitHandle_t *hunit) {
  System_String_o *name;
  UnityEngine_GameObject_o *v9;
  System_String_o *v10;
  Il2CppObject *v12;

  if (op_Inequality(obj, 0, 0))
  {
    if (op_Inequality(fhdobj, 0, 0))
    {
      name = get_name(obj);
      v9 = 0;
      if (op_Equality(name, "dante_e728", 0))
        v9 = (fhdobj->klass->vtable._6_GetGameObjectByName.methodPtr)(
               fhdobj,
               "ivory",
               fhdobj->klass->vtable._6_GetGameObjectByName.method);
      v10 = get_name(obj);
      if (op_Equality(v10, "dante_e729", 0))
        v9 = (fhdobj->klass->vtable._6_GetGameObjectByName.methodPtr)(
               fhdobj,
               "ivory (1)",
               fhdobj->klass->vtable._6_GetGameObjectByName.method);
      if (op_Inequality(v9, 0, 0))
      {
        v12 = AddComponent_object_(v9);
        SetEveUnit(v12, hunit);
      }
    }
  }
}

// 0x19b4bd0
bool ChkMdlHandle(dds3ModelHandle_t *aHandle) {
  if (aHandle)
    LOBYTE(aHandle) = aHandle->modelRoot != 0;
  return aHandle;
}

// 0x19ad650
void Clear(mdlManager_mdlTbMbAbLoadCb_t *this) {
  u64 *v3;

  this->regFlags = 0;
  *&this->major = 0;
  v3 = Allocate(mdlSetDef_t);
  _ctor(v3, 0);
  this->modelSet = v3;
}

// 0x19b8c70
void DanteBattleVoiceCall(char *newtag) {
  UnityEngine_Object_o *dante_btl_voice;
  Il2CppObject *Component_object;

  if (op_Inequality(dante_btl_voice, 0, 0))
  {
    Component_object = GetComponent_object_(dante_btl_voice);
    if (op_Inequality(Component_object, 0, 0))
      SetKutiName(Component_object, newtag);
  }
}

// 0x19b8da0
void DanteBattleVoiceClear(void) {
  dante_btl_voice = 0;
}

// 0x19b8ba0
void DanteBattleVoiceInit(s32 unitid, void *obj) {
  else if (!evtBitCheck(3712))
  {
    return;
  }
  if ((unitid - 339) < 3 || unitid == 192)
  {
    dante_btl_voice = obj;
  }
}

// 0x19b86a0
s32 GetAnimNum(void *obj) {
  UnityEngine_Object_o *Animator;

  Animator = GetAnimator(obj);
  if (op_Equality(Animator, 0, 0))
    return 0;
  return GetInteger_8773456(Animator, id_anim);
}

// 0x19aaed0
void *GetAnimator(void *obj) {
  UnityEngine_Object_o *Component_object;
  UnityEngine_Object_o *monitor;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  s32 v11;
  UnityEngine_Component_o *v12;
  s64 v13;
  UnityEngine_GameObject_o *gameObject;

  Component_object = GetComponent_object_(obj);
  if (!op_Inequality(Component_object, 0, 0))
    goto LABEL_11;
  monitor = Component_object[2].monitor;
  if (!op_Inequality(monitor, 0, 0))
  {
LABEL_11:
    monitor = GetComponent_object_(obj);
    if (!op_Inequality(monitor, 0, 0))
    {
      transform = get_transform(obj, 0);
      Child = GetChild(transform, 0);
      monitor = GetComponent_GUILayer_(Child);
      if (!op_Inequality(monitor, 0, 0) && get_childCount(Child) >= 1)
      {
        v11 = 0;
        do
        {
          v12 = GetChild(Child, v11);
          gameObject = get_gameObject(v12);
          monitor = get_animator(gameObject, v13);
          if (op_Inequality(monitor, 0, 0))
            break;
          ++v11;
        }
        while (v11 < get_childCount(Child));
      }
    }
  }
  return monitor;
}

// 0x19b4bf0
void *GetMdlObjectUnity(dds3ModelHandle_t *aHandle) {
  struct sdfModelRootNode_t_o *modelRoot;

  if (aHandle)
  {
    modelRoot = aHandle->modelRoot;
    if (modelRoot)
      return modelRoot->modelobj;
    else
      return 0;
  }
  return aHandle;
}

// 0x19b5740
bool IsModelDante(s32 id) {
  bool result;

  if (!evtBitCheck(3712))
    return 0;
  result = 1;
  if ((id - 339) >= 3 && id != 192)
    return 0;
  return result;
}

// 0x19b57a0
bool IsModelRaido(s32 id) {
  bool result;

  if (evtBitCheck(3712))
    return 0;
  result = 1;
  if ((id - 339) >= 3 && id != 192)
    return 0;
  return result;
}

// 0x19aae10
void LockAnim(void *obj) {
  UnityEngine_Animator_o *Animator;

  Animator = GetAnimator(obj);
  if (!op_Equality(Animator, 0, 0))
    set_keepAnimatorControllerStateOnDisable(Animator, 1);
}

// 0x19aac00
bool MDL_CHECK_READY(dds3ModelResrc_t *st) {
  return st != 0;
}

// 0x19acd40
void MbLoadCallback(fileHandle_t **fileHandle, mdlManager_mdlTbMbAbLoadCb_t *parm) {
  struct mdlSetDef_t_o *modelSet;
  fileCb_t_o *v6;
  struct mdlSetDef_t_o *v7;
  Il2CppObject *LoadPtr;
  mdlManager_mdlTbMbAbLoadCb_t_o *tmaCb;

  tmaCb = parm;
  modelSet = parm->modelSet;
  v6 = *fileHandle;
  modelSet->modelDefHandle = fileGetMemHandle(v6);
  v7 = parm->modelSet;
  LoadPtr = fileGetLoadPtr(*fileHandle);
  v7->modelDefPtr = sdfFixupModelBinary(LoadPtr);
  fileHandleFree(*fileHandle);
  if (!parm->loadAB)
  {
    TbMbAbLoadEnd(&tmaCb);
  }
}

// 0x19b90d0
void RetTransparent(void *obj) {
  Il2CppObject *Component_object;

  if (!op_Equality(obj, 0, 0))
  {
    Component_object = GetComponent_object_(obj);
    if (op_Inequality(Component_object, 0, 0))
      RetTransparent(Component_object, 0);
  }
}

// 0x19aab80
u32 SDF_PAC_FOURCC_(s32 a, s32 b, s32 c, s32 d) {
  return a | (b << 8) | (c << 16) | (d << 24);
}

// 0x19b96e0
void Set(mdlManager_AbHeaderParm_t *this, u8 **src) {
  this->dataSize = ToUInt32(src, 0, 0);
  this->addrInfoSize = ToUInt32(src, 4, 0);
  this->group = ToUInt16(src, 8);
  this->playGroup = ToUInt16(src, 10);
  this->firstMotion = ToInt16(src, 12, 0);
  this->flags = ToUInt16(src, 14);
}

// 0x19b8fd0
void SetTransparent(void *obj, u32 rgba, f32 alfrgb) {
  Il2CppObject *Component_object;

  if (!op_Equality(obj, 0, 0))
  {
    Component_object = GetComponent_object_(obj);
    if (op_Inequality(Component_object, 0, 0))
      SetTransparent(Component_object, rgba, alfrgb, 0, 0);
  }
}

// 0x19acca0
void TbLoadCallback(fileHandle_t **fileHandle, mdlManager_mdlTbMbAbLoadCb_t *parm) {
  struct mdlSetDef_t_o *modelSet;
  fileCb_t_o *v6;
  Il2CppObject *LoadPtr;

  modelSet = parm->modelSet;
  v6 = *fileHandle;
  LoadPtr = fileGetLoadPtr(v6);
  modelSet->texList = sdfTexSetTB(LoadPtr);
  fileHandleFree(*fileHandle);
}

// 0x19acb70
void TbMbAbLoadEnd(mdlManager_mdlTbMbAbLoadCb_t **tmaCb) {
  s32 major;
  s32 minor;
  s32 regFlags;
  mdlSetDef_t_o *modelSet;
  s64 v9;
  s32 v10;
  struct mdlLoadingTag_t_array *mdlLoadingMajorList;
  mdlLoadingTag_t_o **p_next;
  mdlLoadingTag_t_o *v15;
  s32 v16;

  major = (*tmaCb)->major;
  minor = (*tmaCb)->minor;
  regFlags = (*tmaCb)->regFlags;
  modelSet = (*tmaCb)->modelSet;
  mdlRegistModelSet(major, minor, regFlags, modelSet);
  v9 = (*tmaCb)->major;
  v10 = (*tmaCb)->minor;
  p_next = &mdlLoadingMajorList->m_Items[v9];
  do
  {
    v15 = *p_next;
    if (!v15)
      break;
    v16 = v15->minor;
    p_next = &v15->next;
  }
  while (v16 != v10);
}

// 0x19ab0f0
void UnlockAnim(void *obj) {
  UnityEngine_Animator_o *Animator;

  Animator = GetAnimator(obj);
  if (!op_Equality(Animator, 0, 0))
    set_keepAnimatorControllerStateOnDisable(Animator, 0);
}

// 0x19b8430
s32 getframe_for_unity(void *anim, s32 index) {
  UnityEngine_GameObject_o *gameObject;
  bool activeSelf;
  s32 result;
  UnityEngine_AnimatorClipInfo_array *CurrentAnimatorClipInfo;
  UnityEngine_AnimatorClipInfo_array *v9;
  UnityEngine_RuntimeAnimatorController_o *runtimeAnimatorController;
  f32 v11;
  s32 v12;
  f32 v14;
  f32 v16;
  UnityEngine_AnimatorStateInfo_o v17;
  UnityEngine_AnimatorStateInfo_o v18;

  memset(&v18, 0, sizeof(v18));
  gameObject = get_gameObject(anim);
  activeSelf = get_activeSelf(gameObject);
  result = 0;
  if (activeSelf)
  {
    CurrentAnimatorClipInfo = GetCurrentAnimatorClipInfo(anim, index);
    if (!CurrentAnimatorClipInfo->max_length)
      return 0;
    v9 = CurrentAnimatorClipInfo;
    GetCurrentAnimatorStateInfo(&v17, anim, index);
    v18 = v17;
    GetCurrentAnimatorClipInfoCount(anim, index);
    runtimeAnimatorController = get_runtimeAnimatorController(anim);
    get_animationClips(runtimeAnimatorController);
    if (!v9)
      return 0;
    if (v9->max_length
      && (v11 = sub_85FB60(&v18), (v12 = (v11 * get_targetFrameRate())) != 0))
    {
      v14 = sub_85FB40(&v18);
      v16 = v14;
      GetInteger_8773456(anim, id_anim);
      return fmodf(v16 * v12, v12);
    }
    else
    {
      return 0;
    }
  }
  return result;
}

// 0x19b7c20
s32 is_devil(void *obj) {
  UnityEngine_Animator_o *Animator;
  UnityEngine_Object_o *runtimeAnimatorController;
  s32 result;
  UnityEngine_Object_o *v7;
  System_String_o *name;
  System_String_o *v9;
  bool v10;

  Animator = GetAnimator(obj);
  runtimeAnimatorController = get_runtimeAnimatorController(Animator);
  if (op_Equality(runtimeAnimatorController, 0, 0))
    return -1;
  v7 = get_runtimeAnimatorController(Animator);
  name = get_name(v7);
  if (get_Length(name) < 5)
    return -1;
  v9 = Substring_5248048(name, 0, 5);
  v10 = Equals_5239888(v9, "mothe", 5);
  result = 0;
  if (!v10)
    return ~Equals_5239888(v9, "devil", 5) << 31 >> 31;
  return result;
}

// 0x19b82b0
s32 is_eventdevil(char *name) {
  s32 Length;
  System_String_o *v4;
  s32 v5;
  s32 v6;
  System_String_o *v7;
  s32 result;

  result = 0;
  Length = get_Length(name);
  if (Length < 7)
    return -1;
  v4 = Substring_5248048(name, Length - 6, 4);
  v5 = -1;
  if (get_Chars(v4, 0) == 101)
  {
    v6 = get_Length(v4);
    v7 = Substring(v4, v6 - 3);
    result = -1;
    return ~TryParse(v7, &result, 0) << 31 >> 31;
  }
  return v5;
}

// 0x19b6cd0
void mdlAttachModelForUnity(dds3Basic_t **bas, s32 major, s32 minor) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v11;
  struct dds3ModelResrc_t_array *mdlResrcMajorList;
  dds3ModelResrc_t_o *i;
  char *v16;
  s64 *v17;
  u64 v18[3];

  workdata = (*bas)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v18);
    if ((v18[0] & 1) != 0)
      v16 = v18[2];
    else
      v16 = v18 + 1;
    v17 = sub_8C4940(v16);
  }
  v11 = workdata[2].klass;
LABEL_9:
  for (i = mdlResrcMajorList->m_Items[major]; i; i = i->next)
  {
    if (i->minor == minor)
      break;
  }
  *(v11->_1.interfaceOffsets + 5) = i;
}

// 0x19ab920
s32 mdlCheckLoading(s32 aMajor, s32 aMinor) {
  struct mdlLoadingTag_t_array *mdlLoadingMajorList;
  mdlLoadingTag_t_o *next;

  next = mdlLoadingMajorList->m_Items[aMajor];
  if (!next)
    return 0;
  while (next->minor != aMinor)
  {
    next = next->next;
    if (!next)
      return 0;
  }
  return 1;
}

// 0x19aae00
s32 mdlChkHide(dds3ModelHandle_t *mdl) {
  return mdl->stat & 1;
}

// 0x19aab90
bool mdlChkMotionEnd(dds3ModelHandle_t *HNDL) {
  return HNDL->motionCtrlr->stat == 5;
}

// 0x19b4690
s32 mdlChkMotionEndEx(dds3ModelHandle_t **aHandle, s32 aGroup) {
  struct sdfMotionCtrlr_t_o *motion;

  motion = (*aHandle)->modelRoot->motion;
  if (!motion)
    return 2;
LABEL_6:
  while (motion->userId != aGroup)
  {
    motion = motion->next;
    if (!motion)
      return 2;
  }
  return motion->stat == 5;
}

// 0x19b6fd0
s32 mdlChkMotionEndForUnity(evtUnitHandle_t **h, s32 index) {
  struct dds3Basic_t_o *Owner;
  UnityEngine_Object_o *gameObject;
  UnityEngine_GameObject_o *v10;

  if (!*h)
    return 1;
  Owner = (*h)->Owner;
  gameObject = Owner->gameObject;
  if (op_Equality(gameObject, 0, 0))
    return 1;
  v10 = Owner->gameObject;
  return mdlChkMotionEndForUnity_26964128(v10, index);
}

// 0x19b70a0
s32 mdlChkMotionEndForUnity_26964128(void *obj, s32 index) {
  UnityEngine_Component_o *transform;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Object_o *Animator;
  UnityEngine_Object_o *Component_GUILayer;

  if (op_Equality(obj, 0, 0))
    return 1;
  transform = get_transform(obj, 0);
  gameObject = get_gameObject(transform);
  Animator = GetAnimator(gameObject);
  if (op_Equality(Animator, 0, 0))
    return 1;
  Component_GUILayer = GetComponent_GUILayer_(Animator);
  return op_Equality(Component_GUILayer, 0, 0)
      || IsFinished2(Component_GUILayer, index);
}

// 0x19ac310
sdfMotionCtrlr_t *mdlCreateMotion(dds3ModelHandle_t **aHandle, s32 aGroup) {
  struct dds3ModelResrcPlayBook_t_array *playbooks;
  u32 max_length;
  struct dds3ModelResrcPlayBook_t_array *v7;
  sdfMotionPlayBook_t_o *ptr;
  s64 playGroup;
  sdfModelRootNode_t_o *modelRoot;
  s32 v13;
  sdfMotionCtrlr_t_o *v14;
  struct sdfMotionCtrlr_t_array *motions;
  struct sdfMotionCtrlr_t_o *v16;

  playbooks = (*aHandle)->resrc->playbooks;
  max_length = playbooks->max_length;
  v7 = (*aHandle)->resrc->playbooks;
  ptr = playbooks->m_Items[aGroup]->ptr;
  playGroup = v7->m_Items[aGroup]->playGroup;
  modelRoot = (*aHandle)->modelRoot;
  v13 = v7->m_Items[aGroup]->playGroup;
  v14 = sdfMotionCtrlrNew(modelRoot, ptr);
  v14->userId = aGroup;
  v14->userId2 = v13;
  motions = (*aHandle)->motions;
  v16 = v14;
  motions->m_Items[playGroup] = v16;
  if (!v13)
    (*aHandle)->motionCtrlr = v16;
  return v16;
}

// 0x19b73b0
void mdlDevilLoopMotionForUnity(void *h, s32 motion) {
  UnityEngine_Component_o *transform;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Component_o *Animator;
  UnityEngine_GameObject_o *v10;
  Il2CppObject *Component_object;
  u64 *v13;
  u64 *v16;
  System_String_o *v18;
  s32 v19;
  s32 v20;

  if (!op_Equality(h, 0, 0))
  {
    transform = get_transform(h, 0);
    gameObject = get_gameObject(transform);
    Animator = GetAnimator(gameObject);
    if (!op_Equality(Animator, 0, 0))
    {
      v10 = get_gameObject(Animator);
      Component_object = GetComponent_object_(v10);
      if (op_Inequality(Component_object, 0, 0))
        ResetFlag(Component_object, 0, 0);
      v20 = motion;
      v13 = sub_8D3950(s32, &v20);
      Format("{0:D2}", v13, 0);
      if (get_parameterCount(Animator))
      {
        SetInteger_8774000(Animator, id_anim, motion);
      }
      v19 = motion;
      v16 = sub_8D3950(s32, &v19);
      v18 = Format("b{0:D2}", v16, 0);
      if (op_Inequality(Component_object, 0, 0))
        Play(Component_object, v18, motion, 0, 0.0, 0, 0, 1, 3, 0);
      else
        Play_8777152(Animator, v18, 0, 0.0);
    }
  }
}

// 0x19b2c70
void mdlEffectCreatePipeForUnity(s32 aMajor, s32 aMinor, mdlEffectResrcList_t **efc_res_list) {
  u64 *v8;
  AssetBundleCtrl_o *v9;
  s64 *v10;
  s64 *v11;
  s64 v12;
  s64 v13;
  char *v14;
  s64 *v15;
  AssetBundleCtrl_o *asset_bc;
  s64 *FileObject;
  s64 *v19;
  s64 v20;
  s64 typeHierarchyDepth;
  char *v22;
  s64 *v23;
  s64 v25;
  s64 v26;
  char *v27;
  s64 *v28;
  AssetBundleCtrl_o *v30;
  System_Byte_array *v32;
  AssetBundleCtrl_o *v33;
  System_String_o *v34;
  s64 *v35;
  s64 v37;
  s64 v38;
  char *v39;
  s64 *v40;
  AssetBundleCtrl_o *v42;
  System_Byte_array *FileByte;
  System_Byte_array *v45;
  u64 v46[2];
  char *v47;

  if (aMajor == 2)
  {
    if (aMinor == 33)
    {
      v8 = NewSpecific(UnityEngine_Texture, 1u);
      asset_bc = get_asset_bc();
      FileObject = LoadFileObject(asset_bc, "pipe_common", "dds3data/pipe/jewel1_t00.tga");
      v19 = FileObject;
      if (FileObject)
      {
        v20 = *FileObject;
        if (*(*FileObject + 288) < typeHierarchyDepth
          || *(*(v20 + 200) + 8 * typeHierarchyDepth - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v20 + 64), UnityEngine_Texture, v46);
          if ((v46[0] & 1) != 0)
            v22 = v47;
          else
            v22 = v46 + 1;
          v23 = sub_8C4940(v22);
        }
        v37 = *v19;
        if (*(*v19 + 288) < v38 || *(*(v37 + 200) + 8 * v38 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v37 + 64), UnityEngine_Texture, v46);
          if ((v46[0] & 1) != 0)
            v39 = v47;
          else
            v39 = v46 + 1;
          v40 = sub_8C4940(v39);
        }
      }
      v8[4] = v19;
      v42 = get_asset_bc();
      FileByte = LoadFileByte(v42, "pipe_common", "dds3data/pipe/jewel_lost.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &FileByte->obj, v8);
      v33 = get_asset_bc();
      v34 = "pipe_common";
      v35 = &"dds3data/pipe/jewel_lost_2.D3P.bytes";
    }
    else
    {
      if (aMinor != 15)
        return;
      v8 = NewSpecific(UnityEngine_Texture, 1u);
      v9 = get_asset_bc();
      v10 = LoadFileObject(v9, "pipe_common", "dds3data/pipe/jewel1_t00.tga");
      v11 = v10;
      if (v10)
      {
        v12 = *v10;
        if (*(*v10 + 288) < v13 || *(*(v12 + 200) + 8 * v13 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v12 + 64), UnityEngine_Texture, v46);
          if ((v46[0] & 1) != 0)
            v14 = v47;
          else
            v14 = v46 + 1;
          v15 = sub_8C4940(v14);
        }
        v25 = *v11;
        if (*(*v11 + 288) < v26 || *(*(v25 + 200) + 8 * v26 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v25 + 64), UnityEngine_Texture, v46);
          if ((v46[0] & 1) != 0)
            v27 = v47;
          else
            v27 = v46 + 1;
          v28 = sub_8C4940(v27);
        }
      }
      v8[4] = v11;
      v30 = get_asset_bc();
      v32 = LoadFileByte(v30, "pipe_common", "dds3data/pipe/jewel1.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v32->obj, v8);
      v33 = get_asset_bc();
      v34 = "pipe_common";
      v35 = &"dds3data/pipe/jewel1_2.D3P.bytes";
    }
    v45 = LoadFileByte(v33, v34, *v35);
    mdlCreateEffectResrc_D3P(efc_res_list, &v45->obj, v8);
  }
}

// 0x19ae5a0
void mdlEffectCreateUnity(s32 aMajor, s32 aMinor, mdlEffectResrcList_t **efc_res_list, bool loadf) {
  _BOOL4 v5;
  bool v9;
  System_String_o *Akey;
  UnityEngine_Texture_array *v13;
  AssetBundleCtrl_o *asset_bc;
  s64 *FileObject;
  s64 *v16;
  s64 v17;
  s64 typeHierarchyDepth;
  char *v19;
  s64 *v20;
  s64 v22;
  s64 v23;
  char *v24;
  s64 *v25;
  AssetBundleCtrl_o *v27;
  System_Byte_array *FileByte;
  AssetBundleCtrl_o *v30;
  System_Byte_array *v31;
  AssetBundleCtrl_o *v32;
  System_Byte_array *v33;
  System_String_o *v34;
  UnityEngine_Texture_array *v37;
  AssetBundleCtrl_o *v38;
  s64 *v39;
  s64 *v40;
  s64 v41;
  s64 v42;
  char *v43;
  s64 *v44;
  s64 v46;
  s64 v47;
  char *v48;
  s64 *v49;
  AssetBundleCtrl_o *v51;
  System_Byte_array *v53;
  AssetBundleCtrl_o *v54;
  System_Byte_array *v55;
  System_String_o *v56;
  AssetBundleCtrl_o *v59;
  System_Byte_array *v61;
  System_String_o *v62;
  AssetBundleCtrl_o *v65;
  System_Byte_array *v67;
  AssetBundleCtrl_o *v68;
  System_Byte_array *v69;
  AssetBundleCtrl_o *v70;
  System_Byte_array *v71;
  AssetBundleCtrl_o *v72;
  System_Byte_array *v73;
  AssetBundleCtrl_o *v74;
  System_Byte_array *v75;
  AssetBundleCtrl_o *v76;
  System_Byte_array *v77;
  AssetBundleCtrl_o *v78;
  System_Byte_array *v79;
  AssetBundleCtrl_o *v80;
  System_Byte_array *v81;
  AssetBundleCtrl_o *v82;
  System_Byte_array *v83;
  System_String_o *v84;
  AssetBundleCtrl_o *v86;
  System_Byte_array *v88;
  System_String_o *v89;
  AssetBundleCtrl_o *v91;
  System_Byte_array *v93;
  AssetBundleCtrl_o *v94;
  System_Byte_array *v95;
  AssetBundleCtrl_o *v96;
  System_Byte_array *v97;
  AssetBundleCtrl_o *v98;
  System_Byte_array *v99;
  System_String_o *v100;
  AssetBundleCtrl_o *v102;
  System_Byte_array *v104;
  AssetBundleCtrl_o *v105;
  System_Byte_array *v106;
  AssetBundleCtrl_o *v107;
  System_Byte_array *v108;
  System_String_o *v109;
  AssetBundleCtrl_o *v112;
  System_Byte_array *v114;
  AssetBundleCtrl_o *v115;
  System_Byte_array *v116;
  System_String_o *v117;
  AssetBundleCtrl_o *v119;
  System_Byte_array *v121;
  AssetBundleCtrl_o *v122;
  System_Byte_array *v123;
  AssetBundleCtrl_o *v124;
  System_Byte_array *v125;
  System_String_o *v126;
  AssetBundleCtrl_o *v128;
  System_Byte_array *v130;
  AssetBundleCtrl_o *v131;
  System_Byte_array *v132;
  AssetBundleCtrl_o *v133;
  System_Byte_array *v134;
  System_String_o *v135;
  UnityEngine_Texture_array *v138;
  AssetBundleCtrl_o *v139;
  s64 *v140;
  s64 *v141;
  s64 v142;
  s64 v143;
  char *v144;
  s64 *v145;
  s64 v147;
  s64 v148;
  char *v149;
  s64 *v150;
  AssetBundleCtrl_o *v152;
  System_Byte_array *v154;
  AssetBundleCtrl_o *v155;
  System_Byte_array *v156;
  System_String_o *v157;
  AssetBundleCtrl_o *v159;
  System_Byte_array *v161;
  System_String_o *v162;
  UnityEngine_Texture_array *v165;
  AssetBundleCtrl_o *v166;
  s64 *v167;
  s64 *v168;
  s64 v169;
  s64 v170;
  char *v171;
  s64 *v172;
  s64 v174;
  s64 v175;
  char *v176;
  s64 *v177;
  AssetBundleCtrl_o *v179;
  System_Byte_array *v181;
  System_String_o *v182;
  AssetBundleCtrl_o *v184;
  System_Byte_array *v186;
  AssetBundleCtrl_o *v187;
  System_Byte_array *v188;
  System_String_o *v189;
  AssetBundleCtrl_o *v191;
  System_Byte_array *v193;
  System_String_o *v194;
  AssetBundleCtrl_o *v196;
  System_Byte_array *v198;
  AssetBundleCtrl_o *v199;
  System_Byte_array *v200;
  AssetBundleCtrl_o *v201;
  System_Byte_array *v202;
  System_String_o *v203;
  UnityEngine_Texture_array *v206;
  AssetBundleCtrl_o *v207;
  s64 *v208;
  s64 *v209;
  s64 v210;
  s64 v211;
  char *v212;
  s64 *v213;
  s64 v215;
  s64 v216;
  char *v217;
  s64 *v218;
  AssetBundleCtrl_o *v220;
  System_Byte_array *v222;
  System_String_o *v223;
  AssetBundleCtrl_o *v225;
  System_Byte_array *v227;
  System_String_o *v228;
  AssetBundleCtrl_o *v230;
  System_Byte_array *v232;
  System_String_o *v233;
  UnityEngine_Texture_array *v236;
  AssetBundleCtrl_o *v237;
  s64 *v238;
  s64 *v239;
  s64 v240;
  s64 v241;
  char *v242;
  s64 *v243;
  s64 v245;
  s64 v246;
  char *v247;
  s64 *v248;
  AssetBundleCtrl_o *v250;
  System_Byte_array *v252;
  AssetBundleCtrl_o *v253;
  System_Byte_array *v254;
  System_String_o *v255;
  UnityEngine_Texture_array *v258;
  AssetBundleCtrl_o *v259;
  s64 *v260;
  s64 *v261;
  s64 v262;
  s64 v263;
  char *v264;
  s64 *v265;
  s64 v267;
  s64 v268;
  char *v269;
  s64 *v270;
  AssetBundleCtrl_o *v272;
  System_Byte_array *v274;
  AssetBundleCtrl_o *v275;
  System_Byte_array *v276;
  System_String_o *v277;
  AssetBundleCtrl_o *v279;
  System_Byte_array *v281;
  AssetBundleCtrl_o *v282;
  System_Byte_array *v283;
  System_String_o *v284;
  UnityEngine_Texture_array *v287;
  AssetBundleCtrl_o *v288;
  s64 *v289;
  s64 *v290;
  s64 v291;
  s64 v292;
  char *v293;
  s64 *v294;
  s64 v296;
  s64 v297;
  char *v298;
  s64 *v299;
  AssetBundleCtrl_o *v301;
  System_Byte_array *v303;
  UnityEngine_Texture_array *v304;
  AssetBundleCtrl_o *v305;
  s64 *v306;
  s64 *v307;
  s64 v308;
  s64 v309;
  char *v310;
  s64 *v311;
  s64 v313;
  s64 v314;
  char *v315;
  s64 *v316;
  AssetBundleCtrl_o *v318;
  System_Byte_array *v319;
  System_String_o *v320;
  UnityEngine_Texture_array *v323;
  AssetBundleCtrl_o *v324;
  s64 *v325;
  s64 *v326;
  s64 v327;
  s64 v328;
  char *v329;
  s64 *v330;
  s64 v332;
  s64 v333;
  char *v334;
  s64 *v335;
  AssetBundleCtrl_o *v337;
  System_Byte_array *v339;
  AssetBundleCtrl_o *v340;
  System_Byte_array *v341;
  System_String_o *v342;
  UnityEngine_Texture_array *v345;
  AssetBundleCtrl_o *v346;
  s64 *v347;
  s64 *v348;
  s64 v349;
  s64 v350;
  char *v351;
  s64 *v352;
  s64 v354;
  s64 v355;
  char *v356;
  s64 *v357;
  AssetBundleCtrl_o *v359;
  System_Byte_array *v361;
  System_String_o *v362;
  UnityEngine_Texture_array *v365;
  AssetBundleCtrl_o *v366;
  s64 *v367;
  s64 *v368;
  s64 v369;
  s64 v370;
  char *v371;
  s64 *v372;
  s64 v374;
  s64 v375;
  char *v376;
  s64 *v377;
  AssetBundleCtrl_o *v379;
  System_Byte_array *v381;
  System_String_o *v382;
  UnityEngine_Texture_array *v385;
  AssetBundleCtrl_o *v386;
  s64 *v387;
  s64 *v388;
  s64 v389;
  s64 v390;
  char *v391;
  s64 *v392;
  s64 v394;
  s64 v395;
  char *v396;
  s64 *v397;
  AssetBundleCtrl_o *v399;
  System_Byte_array *v401;
  System_String_o *v402;
  UnityEngine_Texture_array *v405;
  AssetBundleCtrl_o *v406;
  s64 *v407;
  s64 *v408;
  s64 v409;
  s64 v410;
  char *v411;
  s64 *v412;
  s64 v414;
  s64 v415;
  char *v416;
  s64 *v417;
  AssetBundleCtrl_o *v419;
  System_Byte_array *v421;
  System_String_o *v422;
  AssetBundleCtrl_o *v424;
  System_Byte_array *v426;
  System_String_o *v427;
  AssetBundleCtrl_o *v430;
  System_Byte_array *v432;
  AssetBundleCtrl_o *v433;
  System_Byte_array *v434;
  System_String_o *v435;
  AssetBundleCtrl_o *v437;
  System_Byte_array *v439;
  AssetBundleCtrl_o *v440;
  System_Byte_array *v441;
  AssetBundleCtrl_o *v442;
  System_Byte_array *v443;
  AssetBundleCtrl_o *v444;
  System_Byte_array *v445;
  AssetBundleCtrl_o *v446;
  System_Byte_array *v447;
  System_String_o *v448;
  AssetBundleCtrl_o *v450;
  System_Byte_array *v452;
  AssetBundleCtrl_o *v453;
  System_Byte_array *v454;
  AssetBundleCtrl_o *v455;
  System_Byte_array *v456;
  AssetBundleCtrl_o *v457;
  System_Byte_array *v458;
  AssetBundleCtrl_o *v459;
  System_Byte_array *v460;
  System_String_o *v461;
  AssetBundleCtrl_o *v463;
  System_Byte_array *v465;
  AssetBundleCtrl_o *v466;
  System_Byte_array *v467;
  AssetBundleCtrl_o *v468;
  System_Byte_array *v469;
  AssetBundleCtrl_o *v470;
  System_Byte_array *v471;
  AssetBundleCtrl_o *v472;
  System_Byte_array *v473;
  System_String_o *v474;
  AssetBundleCtrl_o *v476;
  System_Byte_array *v478;
  AssetBundleCtrl_o *v479;
  System_Byte_array *v480;
  AssetBundleCtrl_o *v481;
  System_Byte_array *v482;
  AssetBundleCtrl_o *v483;
  System_Byte_array *v484;
  AssetBundleCtrl_o *v485;
  System_Byte_array *v486;
  AssetBundleCtrl_o *v487;
  System_Byte_array *v488;
  AssetBundleCtrl_o *v489;
  System_Byte_array *v490;
  System_String_o *v491;
  AssetBundleCtrl_o *v494;
  System_Byte_array *v496;
  AssetBundleCtrl_o *v497;
  System_Byte_array *v498;
  AssetBundleCtrl_o *v500;
  System_Byte_array *v501;
  System_String_o *v502;
  AssetBundleCtrl_o *v504;
  System_Byte_array *v506;
  System_String_o *v507;
  AssetBundleCtrl_o *v509;
  System_Byte_array *v511;
  System_String_o *v512;
  AssetBundleCtrl_o *v514;
  System_Byte_array *v516;
  System_String_o *v517;
  UnityEngine_Texture_array *v519;
  AssetBundleCtrl_o *v520;
  s64 *v521;
  s64 *v522;
  s64 v523;
  s64 v524;
  char *v525;
  s64 *v526;
  s64 v528;
  s64 v529;
  char *v530;
  s64 *v531;
  AssetBundleCtrl_o *v533;
  System_Byte_array *v535;
  AssetBundleCtrl_o *v536;
  System_Byte_array *v537;
  AssetBundleCtrl_o *v538;
  System_Byte_array *v539;
  System_String_o *v540;
  UnityEngine_Texture_array *v542;
  AssetBundleCtrl_o *v543;
  s64 *v544;
  s64 *v545;
  s64 v546;
  s64 v547;
  char *v548;
  s64 *v549;
  s64 v551;
  s64 v552;
  char *v553;
  s64 *v554;
  AssetBundleCtrl_o *v556;
  System_Byte_array *v558;
  AssetBundleCtrl_o *v559;
  System_Byte_array *v560;
  System_String_o *v561;
  AssetBundleCtrl_o *v563;
  System_Byte_array *v565;
  System_String_o *v566;
  AssetBundleCtrl_o *v568;
  System_Byte_array *v570;
  System_String_o *v571;
  AssetBundleCtrl_o *v573;
  System_Byte_array *v575;
  System_String_o *v576;
  AssetBundleCtrl_o *v578;
  System_Byte_array *v580;
  u64 v581[2];
  char *v582;
  s32 v583;
  _BOOL4 v584;

  v5 = loadf;
  v9 = aMajor == 1 || v5;
  v584 = v5;
  if (aMajor == 1 || v5)
  {
    v583 = aMajor;
    Akey = GetAkey(aMinor);
    if (Equals_5234480(Akey, "dvl0x03"))
    {
      v13 = NewSpecific(UnityEngine_Texture, 1u);
      asset_bc = get_asset_bc();
      FileObject = LoadFileObject(asset_bc, "battle", "dds3data/battle/dvleff/dvleff_0x03/AMATE0.tga");
      v16 = FileObject;
      if (FileObject)
      {
        v17 = *FileObject;
        if (*(*FileObject + 288) < typeHierarchyDepth
          || *(*(v17 + 200) + 8 * typeHierarchyDepth - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v17 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v19 = v582;
          else
            v19 = v581 + 1;
          v20 = sub_8C4940(v19);
        }
        v22 = *v16;
        if (*(*v16 + 288) < v23 || *(*(v22 + 200) + 8 * v23 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v22 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v24 = v582;
          else
            v24 = v581 + 1;
          v25 = sub_8C4940(v24);
        }
      }
      v13->m_Items[0] = v16;
      v27 = get_asset_bc();
      FileByte = LoadFileByte(v27, "battle", "dds3data/battle/dvleff/dvleff_0x03/AMATE0.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &FileByte->obj, v13);
      v30 = get_asset_bc();
      v31 = LoadFileByte(v30, "battle", "dds3data/battle/dvleff/dvleff_0x03/FPSE.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v31->obj, 0);
      v32 = get_asset_bc();
      v33 = LoadFileByte(v32, "battle", "dds3data/battle/dvleff/dvleff_0x03/FPSE.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v33->obj, 0);
    }
    v34 = GetAkey(aMinor);
    if (Equals_5234480(v34, "dvl0x06"))
    {
      v37 = NewSpecific(UnityEngine_Texture, 1u);
      v38 = get_asset_bc();
      v39 = LoadFileObject(v38, "battle", "dds3data/battle/dvleff/dvleff_0x06/HORS.tga");
      v40 = v39;
      if (v39)
      {
        v41 = *v39;
        if (*(*v39 + 288) < v42 || *(*(v41 + 200) + 8 * v42 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v41 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v43 = v582;
          else
            v43 = v581 + 1;
          v44 = sub_8C4940(v43);
        }
        v46 = *v40;
        if (*(*v40 + 288) < v47 || *(*(v46 + 200) + 8 * v47 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v46 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v48 = v582;
          else
            v48 = v581 + 1;
          v49 = sub_8C4940(v48);
        }
      }
      v37->m_Items[0] = v40;
      v51 = get_asset_bc();
      v53 = LoadFileByte(v51, "battle", "dds3data/battle/dvleff/dvleff_0x06/HORS.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v53->obj, v37);
      v54 = get_asset_bc();
      v55 = LoadFileByte(v54, "battle", "dds3data/battle/dvleff/dvleff_0x06/FPSE.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v55->obj, 0);
    }
    v56 = GetAkey(aMinor);
    if (Equals_5234480(v56, "dvl0x0a"))
    {
      billAlfRaitoSet(3.0);
      billCutRaitoSet(35.0);
      v59 = get_asset_bc();
      v61 = LoadFileByte(v59, "battle", "dds3data/battle/dvleff/dvleff_0x0a/SATY.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v61->obj, 0);
    }
    v62 = GetAkey(aMinor);
    if (Equals_5234480(v62, "dvl0x0e"))
    {
      billAlfRaitoSet(2.0);
      v65 = get_asset_bc();
      v67 = LoadFileByte(v65, "battle", "dds3data/battle/dvleff/dvleff_0x0e/KINTO.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v67->obj, 0);
      billAlfRaitoSet(2.0);
      v68 = get_asset_bc();
      v69 = LoadFileByte(v68, "battle", "dds3data/battle/dvleff/dvleff_0x0e/KINTO.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v69->obj, 0);
      billAlfRaitoSet(2.0);
      v70 = get_asset_bc();
      v71 = LoadFileByte(v70, "battle", "dds3data/battle/dvleff/dvleff_0x0e/KINTO2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v71->obj, 0);
      billAlfRaitoSet(2.0);
      v72 = get_asset_bc();
      v73 = LoadFileByte(v72, "battle", "dds3data/battle/dvleff/dvleff_0x0e/KINTO3.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v73->obj, 0);
      billAlfRaitoSet(2.0);
      v74 = get_asset_bc();
      v75 = LoadFileByte(v74, "battle", "dds3data/battle/dvleff/dvleff_0x0e/KINTO2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v75->obj, 0);
      billAlfRaitoSet(2.0);
      v76 = get_asset_bc();
      v77 = LoadFileByte(v76, "battle", "dds3data/battle/dvleff/dvleff_0x0e/KINTO4.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v77->obj, 0);
      billAlfRaitoSet(2.0);
      v78 = get_asset_bc();
      v79 = LoadFileByte(v78, "battle", "dds3data/battle/dvleff/dvleff_0x0e/KINTO5.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v79->obj, 0);
      billAlfRaitoSet(2.0);
      v80 = get_asset_bc();
      v81 = LoadFileByte(v80, "battle", "dds3data/battle/dvleff/dvleff_0x0e/KINTO6.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v81->obj, 0);
      billAlfRaitoSet(2.0);
      v82 = get_asset_bc();
      v83 = LoadFileByte(v82, "battle", "dds3data/battle/dvleff/dvleff_0x0e/KINTO5.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v83->obj, 0);
    }
    v84 = GetAkey(aMinor);
    if (Equals_5234480(v84, "dvl0x24"))
    {
      v86 = get_asset_bc();
      v88 = LoadFileByte(v86, "battle", "dds3data/battle/dvleff/dvleff_0x24/FRAME1.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v88->obj, 0);
    }
    v89 = GetAkey(aMinor);
    if (Equals_5234480(v89, "dvl0x25"))
    {
      v91 = get_asset_bc();
      v93 = LoadFileByte(v91, "battle", "dds3data/battle/dvleff/dvleff_0x25/AQUA1.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v93->obj, 0);
      v94 = get_asset_bc();
      v95 = LoadFileByte(v94, "battle", "dds3data/battle/dvleff/dvleff_0x25/AQUA2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v95->obj, 0);
      v96 = get_asset_bc();
      v97 = LoadFileByte(v96, "battle", "dds3data/battle/dvleff/dvleff_0x25/AQUA3.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v97->obj, 0);
      v98 = get_asset_bc();
      v99 = LoadFileByte(v98, "battle", "dds3data/battle/dvleff/dvleff_0x25/AQUA4.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v99->obj, 0);
    }
    v100 = GetAkey(aMinor);
    if (Equals_5234480(v100, "dvl0x26"))
    {
      v102 = get_asset_bc();
      v104 = LoadFileByte(v102, "battle", "dds3data/battle/dvleff/dvleff_0x26/AEPOS3.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v104->obj, 0);
      v105 = get_asset_bc();
      v106 = LoadFileByte(v105, "battle", "dds3data/battle/dvleff/dvleff_0x26/AEROS2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v106->obj, 0);
      v107 = get_asset_bc();
      v108 = LoadFileByte(v107, "battle", "dds3data/battle/dvleff/dvleff_0x26/AEROS4.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v108->obj, 0);
    }
    v109 = GetAkey(aMinor);
    if (Equals_5234480(v109, "dvl0x27"))
    {
      billAlfRaitoSet(2.0);
      v112 = get_asset_bc();
      v114 = LoadFileByte(v112, "battle", "dds3data/battle/dvleff/dvleff_0x27/IWA.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v114->obj, 0);
      billAlfRaitoSet(2.0);
      v115 = get_asset_bc();
      v116 = LoadFileByte(v115, "battle", "dds3data/battle/dvleff/dvleff_0x27/IWA1.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v116->obj, 0);
    }
    v117 = GetAkey(aMinor);
    if (Equals_5234480(v117, "dvl0x2c"))
    {
      v119 = get_asset_bc();
      v121 = LoadFileByte(v119, "battle", "dds3data/battle/dvleff/dvleff_0x2c/IFREET.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v121->obj, 0);
      v122 = get_asset_bc();
      v123 = LoadFileByte(v122, "battle", "dds3data/battle/dvleff/dvleff_0x2c/IFREETM.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v123->obj, 0);
      v124 = get_asset_bc();
      v125 = LoadFileByte(v124, "battle", "dds3data/battle/dvleff/dvleff_0x2c/IFREETS.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v125->obj, 0);
    }
    v126 = GetAkey(aMinor);
    if (Equals_5234480(v126, "dvl0x2f"))
    {
      v128 = get_asset_bc();
      v130 = LoadFileByte(v128, "battle", "dds3data/battle/dvleff/dvleff_0x2f/JIN.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v130->obj, 0);
      v131 = get_asset_bc();
      v132 = LoadFileByte(v131, "battle", "dds3data/battle/dvleff/dvleff_0x2f/JINM.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v132->obj, 0);
      v133 = get_asset_bc();
      v134 = LoadFileByte(v133, "battle", "dds3data/battle/dvleff/dvleff_0x2f/JINS.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v134->obj, 0);
    }
    v135 = GetAkey(aMinor);
    if (Equals_5234480(v135, "dvl0x3a"))
    {
      v138 = NewSpecific(UnityEngine_Texture, 1u);
      v139 = get_asset_bc();
      v140 = LoadFileObject(v139, "battle", "dds3data/battle/dvleff/dvleff_0x3a/RANTAN01.tga");
      v141 = v140;
      if (v140)
      {
        v142 = *v140;
        if (*(*v140 + 288) < v143 || *(*(v142 + 200) + 8 * v143 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v142 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v144 = v582;
          else
            v144 = v581 + 1;
          v145 = sub_8C4940(v144);
        }
        v147 = *v141;
        if (*(*v141 + 288) < v148 || *(*(v147 + 200) + 8 * v148 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v147 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v149 = v582;
          else
            v149 = v581 + 1;
          v150 = sub_8C4940(v149);
        }
      }
      v138->m_Items[0] = v141;
      v152 = get_asset_bc();
      v154 = LoadFileByte(v152, "battle", "dds3data/battle/dvleff/dvleff_0x3a/RANTAN01.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v154->obj, v138);
      v155 = get_asset_bc();
      v156 = LoadFileByte(v155, "battle", "dds3data/battle/dvleff/dvleff_0x3a/RAN.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v156->obj, 0);
    }
    v157 = GetAkey(aMinor);
    if (Equals_5234480(v157, "dvl0x3e"))
    {
      v159 = get_asset_bc();
      v161 = LoadFileByte(v159, "battle", "dds3data/battle/dvleff/dvleff_0x3e/SOLONE.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v161->obj, 0);
    }
    v162 = GetAkey(aMinor);
    if (Equals_5234480(v162, "dvl0x5c"))
    {
      v165 = NewSpecific(UnityEngine_Texture, 1u);
      v166 = get_asset_bc();
      v167 = LoadFileObject(v166, "battle", "dds3data/battle/dvleff/dvleff_0x5c/KDAMA.tga");
      v168 = v167;
      if (v167)
      {
        v169 = *v167;
        if (*(*v167 + 288) < v170 || *(*(v169 + 200) + 8 * v170 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v169 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v171 = v582;
          else
            v171 = v581 + 1;
          v172 = sub_8C4940(v171);
        }
        v174 = *v168;
        if (*(*v168 + 288) < v175 || *(*(v174 + 200) + 8 * v175 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v174 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v176 = v582;
          else
            v176 = v581 + 1;
          v177 = sub_8C4940(v176);
        }
      }
      v165->m_Items[0] = v168;
      v179 = get_asset_bc();
      v181 = LoadFileByte(v179, "battle", "dds3data/battle/dvleff/dvleff_0x5c/KDAMA.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v181->obj, v165);
    }
    v182 = GetAkey(aMinor);
    if (Equals_5234480(v182, "dvl0x68"))
    {
      v184 = get_asset_bc();
      v186 = LoadFileByte(v184, "battle", "dds3data/battle/dvleff/dvleff_0x68/MADA2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v186->obj, 0);
      v187 = get_asset_bc();
      v188 = LoadFileByte(v187, "battle", "dds3data/battle/dvleff/dvleff_0x68/MADA.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v188->obj, 0);
    }
    v189 = GetAkey(aMinor);
    if (Equals_5234480(v189, "dvl0x6c"))
    {
      v191 = get_asset_bc();
      v193 = LoadFileByte(v191, "battle", "dds3data/battle/dvleff/dvleff_0x6c/BAFOMET.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v193->obj, 0);
    }
    v194 = GetAkey(aMinor);
    if (Equals_5234480(v194, "dvl0x6f"))
    {
      v196 = get_asset_bc();
      v198 = LoadFileByte(v196, "battle", "dds3data/battle/dvleff/dvleff_0x6f/SLUTO.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v198->obj, 0);
      v199 = get_asset_bc();
      v200 = LoadFileByte(v199, "battle", "dds3data/battle/dvleff/dvleff_0x6f/SLUTO2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v200->obj, 0);
      v201 = get_asset_bc();
      v202 = LoadFileByte(v201, "battle", "dds3data/battle/dvleff/dvleff_0x6f/SLUTO3.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v202->obj, 0);
    }
    v203 = GetAkey(aMinor);
    if (Equals_5234480(v203, "dvl0x79"))
    {
      v206 = NewSpecific(UnityEngine_Texture, 1u);
      v207 = get_asset_bc();
      v208 = LoadFileObject(v207, "battle", "dds3data/battle/dvleff/dvleff_0x79/FRES.tga");
      v209 = v208;
      if (v208)
      {
        v210 = *v208;
        if (*(*v208 + 288) < v211 || *(*(v210 + 200) + 8 * v211 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v210 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v212 = v582;
          else
            v212 = v581 + 1;
          v213 = sub_8C4940(v212);
        }
        v215 = *v209;
        if (*(*v209 + 288) < v216 || *(*(v215 + 200) + 8 * v216 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v215 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v217 = v582;
          else
            v217 = v581 + 1;
          v218 = sub_8C4940(v217);
        }
      }
      v206->m_Items[0] = v209;
      v220 = get_asset_bc();
      v222 = LoadFileByte(v220, "battle", "dds3data/battle/dvleff/dvleff_0x79/FRES.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v222->obj, v206);
    }
    v223 = GetAkey(aMinor);
    if (Equals_5234480(v223, "dvl0x7e"))
    {
      v225 = get_asset_bc();
      v227 = LoadFileByte(v225, "battle", "dds3data/battle/dvleff/dvleff_0x7e/TIN01.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v227->obj, 0);
    }
    v228 = GetAkey(aMinor);
    if (Equals_5234480(v228, "dvl0x82"))
    {
      v230 = get_asset_bc();
      v232 = LoadFileByte(v230, "battle", "dds3data/battle/dvleff/dvleff_0x82/CORO.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v232->obj, 0);
    }
    v233 = GetAkey(aMinor);
    if (Equals_5234480(v233, "dvl0x84"))
    {
      v236 = NewSpecific(UnityEngine_Texture, 1u);
      v237 = get_asset_bc();
      v238 = LoadFileObject(v237, "battle", "dds3data/battle/dvleff/dvleff_0x84/SHADOW.tga");
      v239 = v238;
      if (v238)
      {
        v240 = *v238;
        if (*(*v238 + 288) < v241 || *(*(v240 + 200) + 8 * v241 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v240 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v242 = v582;
          else
            v242 = v581 + 1;
          v243 = sub_8C4940(v242);
        }
        v245 = *v239;
        if (*(*v239 + 288) < v246 || *(*(v245 + 200) + 8 * v246 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v245 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v247 = v582;
          else
            v247 = v581 + 1;
          v248 = sub_8C4940(v247);
        }
      }
      v236->m_Items[0] = v239;
      v250 = get_asset_bc();
      v252 = LoadFileByte(v250, "battle", "dds3data/battle/dvleff/dvleff_0x84/SHADOW.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v252->obj, v236);
      v253 = get_asset_bc();
      v254 = LoadFileByte(v253, "battle", "dds3data/battle/dvleff/dvleff_0x84/SHADOW2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v254->obj, 0);
    }
    v255 = GetAkey(aMinor);
    if (Equals_5234480(v255, "dvl0x88"))
    {
      v258 = NewSpecific(UnityEngine_Texture, 1u);
      v259 = get_asset_bc();
      v260 = LoadFileObject(v259, "battle", "dds3data/battle/dvleff/dvleff_0x88/MORYO.tga");
      v261 = v260;
      if (v260)
      {
        v262 = *v260;
        if (*(*v260 + 288) < v263 || *(*(v262 + 200) + 8 * v263 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v262 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v264 = v582;
          else
            v264 = v581 + 1;
          v265 = sub_8C4940(v264);
        }
        v267 = *v261;
        if (*(*v261 + 288) < v268 || *(*(v267 + 200) + 8 * v268 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v267 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v269 = v582;
          else
            v269 = v581 + 1;
          v270 = sub_8C4940(v269);
        }
      }
      v258->m_Items[0] = v261;
      v272 = get_asset_bc();
      v274 = LoadFileByte(v272, "battle", "dds3data/battle/dvleff/dvleff_0x88/MORYO.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v274->obj, v258);
      v275 = get_asset_bc();
      v276 = LoadFileByte(v275, "battle", "dds3data/battle/dvleff/dvleff_0x88/MORYO2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v276->obj, 0);
    }
    v277 = GetAkey(aMinor);
    if (Equals_5234480(v277, "dvl0x89"))
    {
      v279 = get_asset_bc();
      v281 = LoadFileByte(v279, "battle", "dds3data/battle/dvleff/dvleff_0x89/WISP5.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v281->obj, 0);
      v282 = get_asset_bc();
      v283 = LoadFileByte(v282, "battle", "dds3data/battle/dvleff/dvleff_0x89/OPTION2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v283->obj, 0);
    }
    v284 = GetAkey(aMinor);
    if (Equals_5234480(v284, "dvl0xb1"))
    {
      billAlfRaitoSet(2.0);
      v287 = NewSpecific(UnityEngine_Texture, 1u);
      v288 = get_asset_bc();
      v289 = LoadFileObject(v288, "battle", "dds3data/battle/dvleff/dvleff_0xb1/RANTAN2.tga");
      v290 = v289;
      if (v289)
      {
        v291 = *v289;
        if (*(*v289 + 288) < v292 || *(*(v291 + 200) + 8 * v292 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v291 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v293 = v582;
          else
            v293 = v581 + 1;
          v294 = sub_8C4940(v293);
        }
        v296 = *v290;
        if (*(*v290 + 288) < v297 || *(*(v296 + 200) + 8 * v297 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v296 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v298 = v582;
          else
            v298 = v581 + 1;
          v299 = sub_8C4940(v298);
        }
      }
      v287->m_Items[0] = v290;
      v301 = get_asset_bc();
      v303 = LoadFileByte(v301, "battle", "dds3data/battle/dvleff/dvleff_0xb1/SKUL.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v303->obj, v287);
      billAlfRaitoSet(4.0);
      v304 = NewSpecific(UnityEngine_Texture, 1u);
      v305 = get_asset_bc();
      v306 = LoadFileObject(v305, "battle", "dds3data/battle/dvleff/dvleff_0xb1/RANTAN2.tga");
      v307 = v306;
      if (v306)
      {
        v308 = *v306;
        if (*(*v306 + 288) < v309 || *(*(v308 + 200) + 8 * v309 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v308 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v310 = v582;
          else
            v310 = v581 + 1;
          v311 = sub_8C4940(v310);
        }
        v313 = *v307;
        if (*(*v307 + 288) < v314 || *(*(v313 + 200) + 8 * v314 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v313 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v315 = v582;
          else
            v315 = v581 + 1;
          v316 = sub_8C4940(v315);
        }
        if (!LODWORD(v304->max_length))
        {
LABEL_422:
        }
      }
      else if (!LODWORD(v304->max_length))
      {
        goto LABEL_422;
      }
      v304->m_Items[0] = v307;
      v318 = get_asset_bc();
      v319 = LoadFileByte(v318, "battle", "dds3data/battle/dvleff/dvleff_0xb1/SKUL1.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v319->obj, v304);
    }
    v320 = GetAkey(aMinor);
    if (Equals_5234480(v320, "dvl0xb2"))
    {
      v323 = NewSpecific(UnityEngine_Texture, 1u);
      v324 = get_asset_bc();
      v325 = LoadFileObject(v324, "battle", "dds3data/battle/dvleff/dvleff_0xb2/PHANTOM.tga");
      v326 = v325;
      if (v325)
      {
        v327 = *v325;
        if (*(*v325 + 288) < v328 || *(*(v327 + 200) + 8 * v328 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v327 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v329 = v582;
          else
            v329 = v581 + 1;
          v330 = sub_8C4940(v329);
        }
        v332 = *v326;
        if (*(*v326 + 288) < v333 || *(*(v332 + 200) + 8 * v333 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v332 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v334 = v582;
          else
            v334 = v581 + 1;
          v335 = sub_8C4940(v334);
        }
      }
      v323->m_Items[0] = v326;
      v337 = get_asset_bc();
      v339 = LoadFileByte(v337, "battle", "dds3data/battle/dvleff/dvleff_0xb2/PHANTOM.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v339->obj, v323);
      v340 = get_asset_bc();
      v341 = LoadFileByte(v340, "battle", "dds3data/battle/dvleff/dvleff_0xb2/PHOPT.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v341->obj, 0);
    }
    v342 = GetAkey(aMinor);
    if (Equals_5234480(v342, "dvl0xc3"))
    {
      v345 = NewSpecific(UnityEngine_Texture, 1u);
      v346 = get_asset_bc();
      v347 = LoadFileObject(v346, "battle", "dds3data/battle/dvleff/dvleff_0xc5/SMOKE03.tga");
      v348 = v347;
      if (v347)
      {
        v349 = *v347;
        if (*(*v347 + 288) < v350 || *(*(v349 + 200) + 8 * v350 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v349 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v351 = v582;
          else
            v351 = v581 + 1;
          v352 = sub_8C4940(v351);
        }
        v354 = *v348;
        if (*(*v348 + 288) < v355 || *(*(v354 + 200) + 8 * v355 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v354 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v356 = v582;
          else
            v356 = v581 + 1;
          v357 = sub_8C4940(v356);
        }
      }
      v345->m_Items[0] = v348;
      v359 = get_asset_bc();
      v361 = LoadFileByte(v359, "battle", "dds3data/battle/dvleff/dvleff_0xc5/SMOKE03B.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v361->obj, v345);
    }
    v362 = GetAkey(aMinor);
    if (Equals_5234480(v362, "dvl0xc4"))
    {
      v365 = NewSpecific(UnityEngine_Texture, 1u);
      v366 = get_asset_bc();
      v367 = LoadFileObject(v366, "battle", "dds3data/battle/dvleff/dvleff_0xc5/SMOKE03.tga");
      v368 = v367;
      if (v367)
      {
        v369 = *v367;
        if (*(*v367 + 288) < v370 || *(*(v369 + 200) + 8 * v370 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v369 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v371 = v582;
          else
            v371 = v581 + 1;
          v372 = sub_8C4940(v371);
        }
        v374 = *v368;
        if (*(*v368 + 288) < v375 || *(*(v374 + 200) + 8 * v375 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v374 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v376 = v582;
          else
            v376 = v581 + 1;
          v377 = sub_8C4940(v376);
        }
      }
      v365->m_Items[0] = v368;
      v379 = get_asset_bc();
      v381 = LoadFileByte(v379, "battle", "dds3data/battle/dvleff/dvleff_0xc5/SMOKE03B.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v381->obj, v365);
    }
    v382 = GetAkey(aMinor);
    if (Equals_5234480(v382, "dvl0xc5"))
    {
      v385 = NewSpecific(UnityEngine_Texture, 1u);
      v386 = get_asset_bc();
      v387 = LoadFileObject(v386, "battle", "dds3data/battle/dvleff/dvleff_0xc5/SMOKE03.tga");
      v388 = v387;
      if (v387)
      {
        v389 = *v387;
        if (*(*v387 + 288) < v390 || *(*(v389 + 200) + 8 * v390 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v389 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v391 = v582;
          else
            v391 = v581 + 1;
          v392 = sub_8C4940(v391);
        }
        v394 = *v388;
        if (*(*v388 + 288) < v395 || *(*(v394 + 200) + 8 * v395 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v394 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v396 = v582;
          else
            v396 = v581 + 1;
          v397 = sub_8C4940(v396);
        }
      }
      v385->m_Items[0] = v388;
      v399 = get_asset_bc();
      v401 = LoadFileByte(v399, "battle", "dds3data/battle/dvleff/dvleff_0xc5/SMOKE03B.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v401->obj, v385);
    }
    v402 = GetAkey(aMinor);
    if (Equals_5234480(v402, "dvl0xc6"))
    {
      v405 = NewSpecific(UnityEngine_Texture, 1u);
      v406 = get_asset_bc();
      v407 = LoadFileObject(v406, "battle", "dds3data/battle/dvleff/dvleff_0xc5/SMOKE03.tga");
      v408 = v407;
      if (v407)
      {
        v409 = *v407;
        if (*(*v407 + 288) < v410 || *(*(v409 + 200) + 8 * v410 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v409 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v411 = v582;
          else
            v411 = v581 + 1;
          v412 = sub_8C4940(v411);
        }
        v414 = *v408;
        if (*(*v408 + 288) < v415 || *(*(v414 + 200) + 8 * v415 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v414 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v416 = v582;
          else
            v416 = v581 + 1;
          v417 = sub_8C4940(v416);
        }
      }
      v405->m_Items[0] = v408;
      v419 = get_asset_bc();
      v421 = LoadFileByte(v419, "battle", "dds3data/battle/dvleff/dvleff_0xc5/SMOKE03B.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v421->obj, v405);
    }
    v422 = GetAkey(aMinor);
    if (Equals_5234480(v422, "dvl0x100"))
    {
      v424 = get_asset_bc();
      v426 = LoadFileByte(v424, "battle", "dds3data/battle/dvleff/dvleff_0x100/MIZUCHI.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v426->obj, 0);
    }
    v427 = GetAkey(aMinor);
    if (Equals_5234480(v427, "dvl0x101"))
    {
      billAlfRaitoSet(0.75);
      v430 = get_asset_bc();
      v432 = LoadFileByte(v430, "battle", "dds3data/battle/dvleff/dvleff_0x101/SOPTION.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v432->obj, 0);
      billAlfRaitoSet(0.75);
      v433 = get_asset_bc();
      v434 = LoadFileByte(v433, "battle", "dds3data/battle/dvleff/dvleff_0x101/SPECTOR.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v434->obj, 0);
    }
    v435 = GetAkey(aMinor);
    if (Equals_5234480(v435, "dvl0x126"))
    {
      v437 = get_asset_bc();
      v439 = LoadFileByte(v437, "battle", "dds3data/battle/dvleff/dvleff_0x126/d0x126_eff0.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v439->obj, 0);
      v440 = get_asset_bc();
      v441 = LoadFileByte(v440, "battle", "dds3data/battle/dvleff/dvleff_0x126/d0x126_eff1.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v441->obj, 0);
      v442 = get_asset_bc();
      v443 = LoadFileByte(v442, "battle", "dds3data/battle/dvleff/dvleff_0x126/d0x126_eff2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v443->obj, 0);
      v444 = get_asset_bc();
      v445 = LoadFileByte(v444, "battle", "dds3data/battle/dvleff/dvleff_0x126/d0x126_eff3.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v445->obj, 0);
      v446 = get_asset_bc();
      v447 = LoadFileByte(v446, "battle", "dds3data/battle/dvleff/dvleff_0x126/d0x126_eff4.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v447->obj, 0);
    }
    v448 = GetAkey(aMinor);
    if (Equals_5234480(v448, "dvl0x127"))
    {
      v450 = get_asset_bc();
      v452 = LoadFileByte(v450, "battle", "dds3data/battle/dvleff/dvleff_0x127/d0x127_eff0.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v452->obj, 0);
      v453 = get_asset_bc();
      v454 = LoadFileByte(v453, "battle", "dds3data/battle/dvleff/dvleff_0x127/d0x127_eff1.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v454->obj, 0);
      v455 = get_asset_bc();
      v456 = LoadFileByte(v455, "battle", "dds3data/battle/dvleff/dvleff_0x127/d0x127_eff2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v456->obj, 0);
      v457 = get_asset_bc();
      v458 = LoadFileByte(v457, "battle", "dds3data/battle/dvleff/dvleff_0x127/d0x127_eff3.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v458->obj, 0);
      v459 = get_asset_bc();
      v460 = LoadFileByte(v459, "battle", "dds3data/battle/dvleff/dvleff_0x127/d0x127_eff4.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v460->obj, 0);
    }
    v461 = GetAkey(aMinor);
    if (Equals_5234480(v461, "dvl0x128"))
    {
      v463 = get_asset_bc();
      v465 = LoadFileByte(v463, "battle", "dds3data/battle/dvleff/dvleff_0x128/d0x128_eff0.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v465->obj, 0);
      v466 = get_asset_bc();
      v467 = LoadFileByte(v466, "battle", "dds3data/battle/dvleff/dvleff_0x128/d0x128_eff1.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v467->obj, 0);
      v468 = get_asset_bc();
      v469 = LoadFileByte(v468, "battle", "dds3data/battle/dvleff/dvleff_0x128/d0x128_eff2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v469->obj, 0);
      v470 = get_asset_bc();
      v471 = LoadFileByte(v470, "battle", "dds3data/battle/dvleff/dvleff_0x128/d0x128_eff3.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v471->obj, 0);
      v472 = get_asset_bc();
      v473 = LoadFileByte(v472, "battle", "dds3data/battle/dvleff/dvleff_0x128/d0x128_eff4.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v473->obj, 0);
    }
    v474 = GetAkey(aMinor);
    if (Equals_5234480(v474, "dvl0x108"))
    {
      v476 = get_asset_bc();
      v478 = LoadFileByte(v476, "battle", "dds3data/battle/dvleff/dvleff_0x108/KAGCENT1.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v478->obj, 0);
      v479 = get_asset_bc();
      v480 = LoadFileByte(v479, "battle", "dds3data/battle/dvleff/dvleff_0x108/FPS3.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v480->obj, 0);
      v481 = get_asset_bc();
      v482 = LoadFileByte(v481, "battle", "dds3data/battle/dvleff/dvleff_0x108/FPSE.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v482->obj, 0);
      v483 = get_asset_bc();
      v484 = LoadFileByte(v483, "battle", "dds3data/battle/dvleff/dvleff_0x108/KAG1.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v484->obj, 0);
      v485 = get_asset_bc();
      v486 = LoadFileByte(v485, "battle", "dds3data/battle/dvleff/dvleff_0x108/ex1.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v486->obj, 0);
      v487 = get_asset_bc();
      v488 = LoadFileByte(v487, "battle", "dds3data/battle/dvleff/dvleff_0x108/ex2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v488->obj, 0);
      v489 = get_asset_bc();
      v490 = LoadFileByte(v489, "battle", "dds3data/battle/dvleff/dvleff_0x108/ex3.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v490->obj, 0);
    }
    v491 = GetAkey(aMinor);
    if (Equals_5234480(v491, "dvl0x125"))
    {
      fpCutRaitoSet(10);
      v494 = get_asset_bc();
      v496 = LoadFileByte(v494, "battle", "dds3data/battle/dvleff/dvleff_0x125/FPSE2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v496->obj, 0);
      v497 = get_asset_bc();
      v498 = LoadFileByte(v497, "battle", "dds3data/battle/dvleff/dvleff_0x125/FPSE2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v498->obj, 0);
      billAlfRaitoSet(0.75);
      v500 = get_asset_bc();
      v501 = LoadFileByte(v500, "battle", "dds3data/battle/dvleff/dvleff_0x125/TEST2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v501->obj, 0);
      fpCutRaitoSet(0);
    }
    v502 = GetAkey(aMinor);
    if (Equals_5234480(v502, "dvl0x146"))
    {
      v504 = get_asset_bc();
      v506 = LoadFileByte(v504, "battle", "dds3data/battle/dvleff/dvleff_0x146/eff0x146.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v506->obj, 0);
    }
    v507 = GetAkey(aMinor);
    if (Equals_5234480(v507, "dvl0x147"))
    {
      v509 = get_asset_bc();
      v511 = LoadFileByte(v509, "battle", "dds3data/battle/dvleff/dvleff_0x147/eff0x147.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v511->obj, 0);
    }
    v512 = GetAkey(aMinor);
    if (Equals_5234480(v512, "dvl0x148"))
    {
      v514 = get_asset_bc();
      v516 = LoadFileByte(v514, "battle", "dds3data/battle/dvleff/dvleff_0x148/eff0x148.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v516->obj, 0);
    }
    v517 = GetAkey(aMinor);
    aMajor = v583;
    if (Equals_5234480(v517, "dvl0x14a"))
    {
      v519 = NewSpecific(UnityEngine_Texture, 1u);
      v520 = get_asset_bc();
      v521 = LoadFileObject(v520, "battle", "dds3data/battle/dvleff/dvleff_0x14a/MASA0.tga");
      v522 = v521;
      if (v521)
      {
        v523 = *v521;
        if (*(*v521 + 288) < v524 || *(*(v523 + 200) + 8 * v524 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v523 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v525 = v582;
          else
            v525 = v581 + 1;
          v526 = sub_8C4940(v525);
        }
        v528 = *v522;
        if (*(*v522 + 288) < v529 || *(*(v528 + 200) + 8 * v529 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v528 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v530 = v582;
          else
            v530 = v581 + 1;
          v531 = sub_8C4940(v530);
        }
      }
      v519->m_Items[0] = v522;
      v533 = get_asset_bc();
      v535 = LoadFileByte(v533, "battle", "dds3data/battle/dvleff/dvleff_0x14a/MASA0.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v535->obj, v519);
      v536 = get_asset_bc();
      v537 = LoadFileByte(v536, "battle", "dds3data/battle/dvleff/dvleff_0x14a/FPSE.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v537->obj, 0);
      v538 = get_asset_bc();
      v539 = LoadFileByte(v538, "battle", "dds3data/battle/dvleff/dvleff_0x14a/FPSE2.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v539->obj, 0);
    }
  }
  if (v584 || aMajor == 6 || aMajor == 1)
  {
    v540 = GetAkey(aMinor);
    if (Equals_5234480(v540, "dvl0x150"))
    {
      v542 = NewSpecific(UnityEngine_Texture, 1u);
      v543 = get_asset_bc();
      v544 = LoadFileObject(v543, "battle", "dds3data/battle/dvleff/dvleff_0x150/RANTAN01.tga");
      v545 = v544;
      if (v544)
      {
        v546 = *v544;
        if (*(*v544 + 288) < v547 || *(*(v546 + 200) + 8 * v547 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v546 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v548 = v582;
          else
            v548 = v581 + 1;
          v549 = sub_8C4940(v548);
        }
        v551 = *v545;
        if (*(*v545 + 288) < v552 || *(*(v551 + 200) + 8 * v552 - 8) != UnityEngine_Texture)
        {
          sub_8FC2C0(*(v551 + 64), UnityEngine_Texture, v581);
          if ((v581[0] & 1) != 0)
            v553 = v582;
          else
            v553 = v581 + 1;
          v554 = sub_8C4940(v553);
        }
      }
      v542->m_Items[0] = v545;
      v556 = get_asset_bc();
      v558 = LoadFileByte(v556, "battle", "dds3data/battle/dvleff/dvleff_0x150/RANTAN01.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v558->obj, v542);
      v559 = get_asset_bc();
      v560 = LoadFileByte(v559, "battle", "dds3data/battle/dvleff/dvleff_0x150/RAN.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v560->obj, 0);
    }
  }
  if (v9)
  {
    v561 = GetAkey(aMinor);
    if (Equals_5234480(v561, "dvl0x152"))
    {
      v563 = get_asset_bc();
      v565 = LoadFileByte(v563, "battle", "dds3data/battle/dvleff/dvleff_0x152/KAGE.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v565->obj, 0);
    }
    v566 = GetAkey(aMinor);
    if (Equals_5234480(v566, "dvl0x15e"))
    {
      v568 = get_asset_bc();
      v570 = LoadFileByte(v568, "battle", "dds3data/battle/dvleff/dvleff_0x15e/FIRE07.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v570->obj, 0);
    }
    v571 = GetAkey(aMinor);
    if (Equals_5234480(v571, "dvl0x160"))
    {
      v573 = get_asset_bc();
      v575 = LoadFileByte(v573, "battle", "dds3data/battle/dvleff/dvleff_0x160/MOTHER3.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v575->obj, 0);
    }
    v576 = GetAkey(aMinor);
    if (Equals_5234480(v576, "dvl0xca"))
    {
      v578 = get_asset_bc();
      v580 = LoadFileByte(v578, "battle", "dds3data/battle/dvleff/dvleff_0x160/MOTHER3.D3P.bytes");
      mdlCreateEffectResrc_D3P(efc_res_list, &v580->obj, 0);
    }
  }
}

// 0x19b8e10
void mdlEffectUpdateRot(void *obj, s32 rot) {
  Il2CppObject *Component_object;

  if (!op_Equality(obj, 0, 0))
  {
    Component_object = GetComponent_object_(obj);
    if (op_Inequality(Component_object, 0, 0))
      SetUpdateRot(Component_object, rot);
  }
}

// 0x19b6080
void mdlFileCbFree(mdlManager_mdlFileLoadCb_t **cb) {
  pacFileCb_t_o *pacHandle;

  pacHandle = (*cb)->pacHandle;
  pacFileHandleFree(pacHandle);
}

// 0x19ad450
s32 mdlFileLoad(s32 major, s32 minor, u32 regFlags, char *filename, mdlManager_mdlFileLoadCb_t_callbackDelegate *callback, void *parm) {
  s16 v11;
  s16 v12;
  u64 *v13;
  u64 *v14;
  u64 *v15;
  pacFileCb_t_o *v17;
  pacFileCb_t_o *v19;
  pacFileCb_t_o *v21;

  v11 = minor;
  v12 = major;
  v13 = Allocate(mdlManager_mdlFileLoadCb_t);
  v14 = Allocate(pacFileCb_t);
  pacFileCb_t___ctor(v14);
  v13[3] = v14;
  _ctor(v13, 0);
  *(v13 + 8) = v12;
  *(v13 + 9) = v11;
  *(v13 + 5) = regFlags;
  v13[4] = callback;
  v13[5] = parm;
  v15 = Allocate(pacFileEndCallback_t);
  pacFileEndCallback_t___ctor(v15, 0, Method_mdlManager_mdlFileLoadCallback__);
  v17 = pacLoadEx(filename, 0, 0, v15, v13);
  v13[3] = v17;
  if (!callback)
  {
    v19 = v17;
    pacSync(v19);
    v21 = v13[3];
    pacFileHandleFree(v21);
  }
  return 0;
}

// 0x19b60f0
void mdlFileLoadCallback(pacFileCb_t *pacHandle, void *data) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s32 klass_low;
  s32 v11;
  sdfPacDecodeResrc_t_o **p_resrcHead;
  u32 klass_high;
  s64 v16;
  s32 v17;
  struct mdlLoadingTag_t_array *mdlLoadingMajorList;
  mdlLoadingTag_t_o **p_next;
  mdlLoadingTag_t_o *v22;
  s32 minor;
  mdlManager_mdlFileLoadCb_t_callbackDelegate_o *v24;
  pacFileCb_t_o *monitor;
  u64 v27[3];

  v4 = data;
  if (v4)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != mdlManager_mdlFileLoadCb_t)
    {
      sub_8FC2C0(klass->_1.element_class, mdlManager_mdlFileLoadCb_t, v27);
      if ((v27[0] & 1) != 0)
        v8 = v27[2];
      else
        v8 = v27 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v4[1].monitor = pacHandle;
  klass_low = LOWORD(v4[1].klass);
  v11 = WORD1(v4[1].klass);
  p_resrcHead = &pacHandle->decodeCb->resrcHead;
  klass_high = HIDWORD(v4[1].klass);
  mdlPackSet(p_resrcHead, klass_low, v11, klass_high);
  v16 = LOWORD(v4[1].klass);
  v17 = WORD1(v4[1].klass);
  p_next = &mdlLoadingMajorList->m_Items[v16];
  do
  {
    v22 = *p_next;
    if (!v22)
      break;
    minor = v22->minor;
    p_next = &v22->next;
  }
  while (minor != v17);
  v24 = v4[2].klass;
  if (v24)
  {
    Invoke(v24, v4[2].monitor);
    monitor = v4[1].monitor;
    pacFileHandleFree(monitor);
  }
}

// 0x19abfc0
void mdlFree(dds3ModelHandle_t **aHandle) {
  struct sdfModelRootNode_t_o *modelRoot;
  sdfModelTexList_t_o *texList;
  struct dds3ModelEffectCtrlr_t_o *effects;
  dds3ModelEffectCtrlr_t_o *v7;
  dds3ModelHandle_t_o *v8;
  struct dds3ModelBlurCb_t_o *blur;
  struct dds3ModelBlurInstance_t_o *instants;
  struct dds3ModelBlurInstance_t_o *v11;
  UnityEngine_Object_o *modelobj;
  sdfModelRootNode_t_o *aRoot;

  modelRoot = (*aHandle)->modelRoot;
  aRoot = modelRoot;
  while (modelRoot->motion)
  {
    sdfMotionCtrlrFree(&modelRoot->motion);
  }
  texList = modelRoot->texList;
  sdfTexListFree(texList, 1);
  effects = (*aHandle)->effects;
  while (effects)
  {
    while (1)
    {
      v7 = effects;
      effects = effects->next;
        break;
      mdlFreeEffect(v7);
      if (!effects)
        goto LABEL_17;
    }
    mdlFreeEffect(v7);
  }
LABEL_17:
LABEL_21:
  v8 = *aHandle;
  blur = (*aHandle)->blur;
  if (blur)
  {
    instants = blur->instants;
    if (instants)
    {
      do
      {
        v11 = instants;
        instants = instants->next;
        modelobj = v11->modelobj;
        Destroy_27360000(modelobj);
        v11->modelobj = 0;
      }
      while (instants);
      v8 = *aHandle;
    }
    v8->blur = 0;
  }
  sdfModelRootFree(&aRoot, 1, 1);
  mdlUnlinkResrc(aHandle);
}

// 0x19ad9d0
void mdlFreeBlur(dds3ModelHandle_t **aHandle) {
  dds3ModelHandle_t_o *v3;
  struct dds3ModelBlurCb_t_o *blur;
  struct dds3ModelBlurInstance_t_o *instants;
  struct dds3ModelBlurInstance_t_o *v6;
  UnityEngine_Object_o *modelobj;

  v3 = *aHandle;
  blur = (*aHandle)->blur;
  if (blur)
  {
    instants = blur->instants;
    if (instants)
    {
      do
      {
        v6 = instants;
        instants = instants->next;
        modelobj = v6->modelobj;
        Destroy_27360000(modelobj);
        v6->modelobj = 0;
      }
      while (instants);
      v3 = *aHandle;
    }
    v3->blur = 0;
  }
}

// 0x19b6ea0
void mdlFreeFileItem(mdlManager_mdlFileItem_tag **aItem) {
  ;
}

// 0x19ac580
void mdlFreeMotion(dds3ModelHandle_t **aHandle, s32 aGroup) {
  struct sdfMotionCtrlr_t_o *motion;

  motion = (*aHandle)->modelRoot->motion;
  if (motion)
  {
    while (motion->userId != aGroup)
    {
      motion = motion->next;
      if (!motion)
        return;
    }
    mdlFreeMotionCtrlr(aHandle, motion);
  }
}

// 0x19ac490
void mdlFreeMotionCtrlr(dds3ModelHandle_t **aHandle, sdfMotionCtrlr_t *aCtrlr) {
  struct sdfMotionCtrlr_t_array *motions;
  u32 userId2;
  s64 v7;
  struct sdfMotionCtrlr_t_array *v9;
  sdfMotionCtrlr_t_o *aCtrlra;

  aCtrlra = aCtrlr;
  motions = (*aHandle)->motions;
  userId2 = aCtrlr->userId2;
  v7 = aCtrlr->userId2;
  if (motions->m_Items[v7] == aCtrlr)
  {
    v9 = (*aHandle)->motions;
    v9->m_Items[v7] = 0;
  }
  sdfMotionCtrlrFree(&aCtrlra);
}

// 0x19b3160
void mdlFreeSub(void **pData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  dds3ModelEffectCtrlr_t_o *monitor;
  dds3ModelEffectCtrlr_t_o *v10;
  u64 *v11;
  s64 i;
  s64 v13;
  UnityEngine_Object_o *v14;
  u64 v15[3];

  v3 = *pData;
  if (*pData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3ModelHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3ModelHandle_t, v15);
      if ((v15[0] & 1) != 0)
        v7 = v15[2];
      else
        v7 = v15 + 1;
      v8 = sub_8C4940(v7);
    }
    monitor = v3[3].monitor;
    while (monitor)
    {
      while (1)
      {
        v10 = monitor;
        monitor = monitor->next;
          break;
        mdlFreeEffect(v10);
        if (!monitor)
          goto LABEL_16;
      }
      mdlFreeEffect(v10);
    }
LABEL_16:
    v11 = v3[5].monitor;
    if (v11)
    {
      for (i = v11[2]; i; *(v13 + 24) = 0)
      {
        v13 = i;
        i = *(i + 16);
        v14 = *(v13 + 24);
        Destroy_27360000(v14);
      }
      v3[5].monitor = 0;
    }
  }
}

// 0x19b4f30
u32 mdlGetColor(dds3ModelHandle_t **aHandle) {
  dds3ModelHandle_t_o *v3;

  v3 = *aHandle;
  if (!v3)
    return 0;
LABEL_6:
  if (v3->modelRoot)
    return (*aHandle)->modelRoot->color;
  else
    return 0;
}

// 0x19b5ae0
void mdlGetFilebase(s32 aMajor, s32 aMinor, char **aName, s32 aNameLeng) {
  struct dds3ModelFileKindTable_t_array *modelFileKindTable;
  struct dds3ModelFileIndex_t_array *indexTable;
  dds3ModelFileIndex_t_o *v13;
  s64 major;
  s64 minor;
  struct dds3ModelFileTableDef_t_array *modelFileTable;
  struct dds3ModelFileTable_t_array *fileTable;

  indexTable = modelFileKindTable->m_Items[aMajor]->indexTable;
  v13 = indexTable->m_Items[aMinor];
  major = v13->major;
  minor = v13->minor;
  fileTable = modelFileTable->m_Items[major]->fileTable;
  *aName = fileTable->m_Items[minor]->fname;
}

// 0x19b5720
s32 mdlGetMajorNum(dds3ModelHandle_t **aHandle) {
  return (*aHandle)->resrc->major;
}

// 0x19b5730
s32 mdlGetMinorNum(dds3ModelHandle_t **aHandle) {
  return (*aHandle)->resrc->minor;
}

// 0x19b4110
sdfMotionCtrlr_t *mdlGetMotionCtrlr(dds3ModelHandle_t **aHandle, s32 aGroup) {
  sdfMotionCtrlr_t_o *result;

  for (result = (*aHandle)->modelRoot->motion; result; result = result->next)
  {
    if (result->userId == aGroup)
      break;
  }
  return result;
}

// 0x19b44a0
s32 mdlGetMotionFrame(dds3ModelHandle_t **aHandle) {
  struct sdfMotionCtrlr_t_o *motion;

LABEL_7:
  motion = (*aHandle)->modelRoot->motion;
  if (!motion)
    return 0;
LABEL_10:
  while (motion->userId)
  {
    motion = motion->next;
    if (!motion)
      return 0;
  }
  return motion->frame;
}

// 0x19b45c0
s32 mdlGetMotionFrameEx(dds3ModelHandle_t **aHandle, s32 aGroup) {
  struct sdfMotionCtrlr_t_o *motion;

  motion = (*aHandle)->modelRoot->motion;
  if (!motion)
    return 0;
LABEL_6:
  while (motion->userId != aGroup)
  {
    motion = motion->next;
    if (!motion)
      return 0;
  }
  return motion->frame;
}

// 0x19b8360
s32 mdlGetMotionFrameForUnity(void *obj) {
  UnityEngine_Object_o *Animator;

  Animator = GetAnimator(obj);
  if (op_Equality(Animator, 0, 0))
    return 0;
  return getframe_for_unity(Animator, 0);
}

// 0x19b85c0
s32 mdlGetMotionFrameForUnity_26969536(evtUnitHandle_t **h, s32 index) {
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Object_o *Animator;

  gameObject = (*h)->Owner->gameObject;
  Animator = GetAnimator(gameObject, *&index);
  if (op_Equality(Animator, 0, 0))
    return 0;
  return getframe_for_unity(Animator, 0);
}

// 0x19b4210
s32 mdlGetMotionLengthEx(dds3ModelHandle_t **aHandle, s32 aGroup) {
  struct sdfMotionCtrlr_t_o *motion;

  motion = (*aHandle)->modelRoot->motion;
  if (!motion)
    return 0;
LABEL_6:
  while (motion->userId != aGroup)
  {
    motion = motion->next;
    if (!motion)
      return 0;
  }
  return motion->frameLength;
}

// 0x19b42e0
s32 mdlGetMotionLengthUnity(dds3ModelHandle_t *aHandle) {
  struct sdfModelRootNode_t_o *modelRoot;
  UnityEngine_Object_o *modelobj;
  UnityEngine_GameObject_o *v6;
  UnityEngine_Object_o *Animator;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_AnimatorClipInfo_array *CurrentAnimatorClipInfo;
  UnityEngine_AnimatorClipInfo_array *v11;
  UnityEngine_RuntimeAnimatorController_o *runtimeAnimatorController;
  UnityEngine_AnimatorStateInfo_o v14;
  UnityEngine_AnimatorStateInfo_o v15;

  memset(&v15, 0, sizeof(v15));
  if (!aHandle)
    return 0;
  modelRoot = aHandle->modelRoot;
  if (!modelRoot)
    return 0;
  modelobj = modelRoot->modelobj;
  if (op_Equality(modelobj, 0, 0))
    return 0;
  v6 = aHandle->modelRoot->modelobj;
  Animator = GetAnimator(v6);
  if (op_Equality(Animator, 0, 0))
    return 0;
  gameObject = get_gameObject(Animator);
  if (!get_activeSelf(gameObject))
    return 0;
  CurrentAnimatorClipInfo = GetCurrentAnimatorClipInfo(Animator, 0);
  if (CurrentAnimatorClipInfo->max_length
    && (v11 = CurrentAnimatorClipInfo,
        GetCurrentAnimatorStateInfo(&v14, Animator, 0),
        v15 = v14,
        v11->max_length)
    && (GetCurrentAnimatorClipInfoCount(Animator, 0),
        runtimeAnimatorController = get_runtimeAnimatorController(Animator),
        get_animationClips(runtimeAnimatorController),
        v11->max_length))
  {
    return (sub_85FB60(&v15) * 30.0);
  }
  else
  {
    return 0;
  }
}

// 0x19b5a20
s32 mdlGetMotionMajorNum(dds3ModelHandle_t **aHandle) {
  return (*aHandle)->motionMajorNum;
}

// 0x19b5a30
s32 mdlGetMotionMinorNum(dds3ModelHandle_t **aHandle) {
  return (*aHandle)->motionMinorNum;
}

// 0x19b8780
s32 mdlGetMotionMinorNumForUnity(evtUnitHandle_t **h, s32 layer) {
  struct dds3ModelHandle_t_o *Model;

  if (!*h)
    return 0;
  Model = (*h)->Model;
  if (Model)
    return Model->motionMinorNum;
  else
    return 0;
}

// 0x19b4140
s32 mdlGetMotionNum(dds3ModelHandle_t **aHandle, s32 aGroup) {
  struct sdfMotionCtrlr_t_o *motion;
  s32 result;

  motion = (*aHandle)->modelRoot->motion;
  if (!motion)
    return -1;
LABEL_6:
  result = -1;
  while (motion->userId != aGroup)
  {
    motion = motion->next;
    if (!motion)
      return result;
  }
  return motion->cutNumber;
}

// 0x19b4ae0
f32 mdlGetMotionSpeedAnimator(void *mAnimator) {
  UnityEngine_GUILayer_o *Component_GUILayer;

  if (!op_Inequality(mAnimator, 0, 0))
    return 0.0;
  Component_GUILayer = GetComponent_GUILayer_(mAnimator);
  if (op_Inequality(Component_GUILayer, 0, 0))
    return *&Component_GUILayer[1].monitor;
  else
    return get_speed(mAnimator);
}

// 0x19b4760
f32 mdlGetMotionSpeedEx(dds3ModelHandle_t **aHandle, s32 aGroup) {
  struct sdfMotionCtrlr_t_o *motion;
  f32 result;

  motion = (*aHandle)->modelRoot->motion;
  result = 0.0;
  if (motion)
  {
    while (motion->userId != aGroup)
    {
      motion = motion->next;
      if (!motion)
        return result;
    }
    return motion->speed;
  }
  return result;
}

// 0x19b5910
s32 mdlGetNumOfCut(dds3ModelHandle_t **aHandle, s32 aGroup) {
  struct sdfMotionCtrlr_t_o *motion;
  struct sdfMotionPlayBook_t_o *playbook;

  motion = (*aHandle)->modelRoot->motion;
  if (!motion)
    return 0;
LABEL_6:
  while (motion->userId != aGroup)
  {
    motion = motion->next;
    if (!motion)
      return 0;
  }
  playbook = motion->playbook;
  if (playbook)
    return playbook->numOfCut;
  else
    return 0;
}

// 0x19b5800
s32 mdlGetNumOfMajor(void) {
  return modelFileKindTable->max_length;
}

// 0x19b5870
s32 mdlGetNumOfMinor(s32 aMajor) {
  struct dds3ModelFileKindTable_t_array *modelFileKindTable;

  return modelFileKindTable->m_Items[aMajor]->numOfIndex;
}

// 0x19b4c10
void mdlGetPosition(dds3ModelHandle_t **aHandle) {
  UnityEngine_Vector4_o v2;

  sub_1A00880(&(*aHandle)->modelRoot->tm, 3u);
  SDF_VU0__LOADVECTOR(v2);
}

// 0x19b4d00
void mdlGetRotate(dds3ModelHandle_t **aHandle) {
  SDF_VU0__LOADVECTOR((*aHandle)->modelRoot->rotate, 0);
}

// 0x19b4e50
void mdlGetScale(dds3ModelHandle_t **aHandle) {
  SDF_VU0__LOADVECTOR((*aHandle)->modelRoot->scale, 0);
}

// 0x19b5360
void mdlGetScreenOffset(dds3ModelHandle_t **aHandle, sdfVector4_t aOfs) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  struct sdf3DScreenParam_t_o *dds3ScreenParam;
  s64 v19;
  s64 v20;
  s64 v21;
  s64 v22;
  s64 v23;
  s64 v24;
  s64 v25;
  struct sdfModelRootNode_t_o *modelRoot;
  s64 v27;
  s64 v28;
  s64 v29;
  s64 v30;
  s64 v31;
  s64 v32;
  s64 v33;
  UnityEngine_Matrix4x4_o v34;
  UnityEngine_Matrix4x4_o v35;
  UnityEngine_Matrix4x4_o v36;
  UnityEngine_Matrix4x4_o v37;
  UnityEngine_Vector4_o v38;

  w = aOfs.w;
  z = aOfs.z;
  y = aOfs.y;
  x = aOfs.x;
  v10 = *&dds3CameraTM.m00;
  v11 = *&dds3CameraTM.m20;
  v12 = *&dds3CameraTM.m21;
  *&v37.m01 = *&dds3CameraTM.m01;
  *&v37.m21 = v12;
  *&v37.m00 = v10;
  *&v37.m20 = v11;
  v13 = *&dds3CameraTM.m02;
  v14 = *&dds3CameraTM.m22;
  v16 = *&dds3CameraTM.m03;
  v15 = *&dds3CameraTM.m23;
  *&v37.m03 = v16;
  *&v37.m23 = v15;
  *&v37.m02 = v13;
  *&v37.m22 = v14;
  SDF_VU0__LOADMATRIX(&v37);
  v19 = *&dds3ScreenParam->TM.m00;
  v20 = *&dds3ScreenParam->TM.m20;
  v21 = *&dds3ScreenParam->TM.m21;
  *&v36.m01 = *&dds3ScreenParam->TM.m01;
  *&v36.m21 = v21;
  *&v36.m00 = v19;
  *&v36.m20 = v20;
  v22 = *&dds3ScreenParam->TM.m02;
  v23 = *&dds3ScreenParam->TM.m22;
  v25 = *&dds3ScreenParam->TM.m03;
  v24 = *&dds3ScreenParam->TM.m23;
  *&v36.m03 = v25;
  *&v36.m23 = v24;
  *&v36.m02 = v22;
  *&v36.m22 = v23;
  v35 = v36;
  MultMatrixRev(&v35);
  SDF_VU0__COPYMATRIX_A_TO_B();
  modelRoot = (*aHandle)->modelRoot;
  v27 = *&modelRoot->tm.m00;
  v28 = *&modelRoot->tm.m20;
  v29 = *&modelRoot->tm.m21;
  *&v34.m01 = *&modelRoot->tm.m01;
  *&v34.m21 = v29;
  *&v34.m00 = v27;
  *&v34.m20 = v28;
  v30 = *&modelRoot->tm.m02;
  v31 = *&modelRoot->tm.m22;
  v33 = *&modelRoot->tm.m03;
  v32 = *&modelRoot->tm.m23;
  *&v34.m03 = v33;
  *&v34.m23 = v32;
  *&v34.m02 = v30;
  *&v34.m22 = v31;
  SDF_VU0__LOADMATRIX(&v34);
  SDF_VU0__SCALE_XYZ();
  MultMatrixRevNoArg();
  v38.x = x;
  v38.y = y;
  v38.z = z;
  v38.w = w;
  SDF_VU0__LOADVECTOR(v38);
  SDF_VU0__PERSVECTOR();
  SDF_VU0__LOADVECTOR_B(dds3ScreenParam->scale);
  SDF_VU0__MULVECTOR();
  SDF_VU0__LOADVECTOR_B(dds3ScreenParam->trans);
  SDF_VU0__ADDVECTOR();
}

// 0x19b5a00
bool mdlHasMotion(dds3ModelHandle_t **aHandle) {
  return (*aHandle)->motionCtrlr != 0;
}

// 0x19b5670
s32 mdlHasMotionEx(dds3ModelHandle_t **aHandle, s32 aGroup) {
  struct sdfMotionCtrlr_t_o *motion;

  else
  {
    motion = (*aHandle)->modelRoot->motion;
    if (!motion)
      return motion != 0;
  }
  do
  {
    if (motion->userId == aGroup)
      break;
    motion = motion->next;
  }
  while (motion);
  return motion != 0;
}

// 0x19aac10
void mdlHide(dds3ModelHandle_t *mdl) {
  struct dds3Basic_t_o *Owner;
  UnityEngine_GameObject_o *gameObject;

  mdl->stat |= 1u;
  Owner = mdl->Owner;
  if (Owner)
  {
    gameObject = Owner->gameObject;
    if (op_Inequality(gameObject, 0, 0))
      SetActive(gameObject, 0, 0);
  }
}

// 0x19b38d0
void mdlHideAllNode(dds3ModelHandle_t **aHandle) {
  struct sdfModelNodeList_t_o *nodeList;
  s64 count;
  struct sdfModelNode_t_array *items;
  u64 v5;
  s64 v6;
  sdfModelNode_t_o *v8;

  nodeList = (*aHandle)->modelRoot->nodeList;
  count = nodeList->count;
  if (count >= 1)
  {
    items = nodeList->items;
    v5 = 0;
    v6 = count;
    do
    {
      v8 = items->m_Items[v5++];
      v8->flags = 1;
    }
    while (v6 != v5);
  }
}

// 0x19ab850
void mdlInitManager(void) {
  s64 i;
  u64 v4;
  struct dds3ModelResrc_t_array *mdlResrcMajorList;
  struct mdlLoadingTag_t_array *mdlLoadingMajorList;

  for (i = 4; i != 12; ++i)
  {
    v4 = i - 4;
    *(&mdlResrcMajorList->obj.klass + i) = 0;
    *(&mdlLoadingMajorList->obj.klass + i) = 0;
  }
}

// 0x19b3350
void mdlLink(dds3ModelHandle_t **aHandle, sdfModelOt_t **aModelOt) {
  struct sdfMotionCtrlr_t_array *motions;
  sdfMotionCtrlr_t_o *v7;
  struct sdfMotionCtrlr_t_array *v8;
  sdfMotionCtrlr_t_o *v10;
  struct sdfMotionCtrlr_t_array *v11;
  sdfMotionCtrlr_t_o *v13;
  struct sdfMotionCtrlr_t_array *v14;
  sdfMotionCtrlr_t_o *v16;
  dds3ModelHandle_t_o *v18;
  u32 stat;
  dds3ModelEffectCtrlr_t_o *aEffect;
  sdfModelRootNode_t_o *aRoot;

  aRoot = 0;
  aEffect = 0;
  motions = (*aHandle)->motions;
  v7 = motions->m_Items[0];
  if (v7 && v7->stat)
  {
    sdfMotionNext(v7);
  }
  v8 = (*aHandle)->motions;
  v10 = v8->m_Items[1];
  if (v10 && v10->stat)
  {
    sdfMotionNext(v10);
  }
  v11 = (*aHandle)->motions;
  v13 = v11->m_Items[2];
  if (v13 && v13->stat)
  {
    sdfMotionNext(v13);
  }
  v14 = (*aHandle)->motions;
  v16 = v14->m_Items[3];
  if (v16 && v16->stat)
  {
    sdfMotionNext(v16);
  }
  if (((*aHandle)->stat & 1) == 0)
  {
    aRoot = (*aHandle)->modelRoot;
    sdfModelEvalTm(&aRoot);
    sdfModelLinkOt(aModelOt, &aRoot);
    v18 = *aHandle;
    stat = (*aHandle)->stat;
    if ((stat & 2) == 0 && ((stat & 4) == 0 || (aRoot->flags & 0x10) != 0))
    {
      aEffect = v18->effects;
      if (aEffect)
      {
        do
        {
          mdlLinkEffect(aHandle, &aEffect, 0);
          aEffect = aEffect->next;
        }
        while (aEffect);
        v18 = *aHandle;
      }
      if (v18->blur)
      {
        mdlLinkBlur(aHandle);
      }
    }
  }
}

// 0x19adb30
void mdlLinkBlur(dds3ModelHandle_t **aHandle) {
  struct sdfModelRootNode_t_o *modelRoot;
  struct dds3ModelBlurCb_t_o *blur;
  s16 spawnCount;
  void *instants;
  s32 v9;
  UnityEngine_GameObject_o *gameObject;
  s32 keepCount;
  ModelHD_o *Copy;
  s32 v16;
  Il2CppObject *Component_object;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  s16 interval;
  u64 *v24;
  UnityEngine_Vector4_o v25;
  UnityEngine_Vector4_o v26;
  UnityEngine_Vector4_o v27;
  UnityEngine_Vector4_o v28;
  UnityEngine_Vector4_o v29;

  modelRoot = (*aHandle)->modelRoot;
  blur = (*aHandle)->blur;
  v25 = SDF_VU0__Retdds3ColorItoF(modelRoot->color, 128.0);
  spawnCount = blur->spawnCount;
  if (spawnCount)
  {
    if (--blur->intervalCount == 0)
    {
      interval = blur->interval;
      blur->spawnCount = spawnCount - 1;
      blur->intervalCount = interval;
      v24 = Allocate(dds3ModelBlurInstance_t);
      _ctor(v24, 0);
      v24[3] = 0;
      *(v24 + 8) = 1;
      v24[2] = blur->instants;
      blur->instants = v24;
      instants = v24;
      if (!v24)
        return;
LABEL_6:
      while (1)
      {
        v9 = *(instants + 8);
        gameObject = *(instants + 3);
        keepCount = v9 - 1;
        if (v9 == 1)
          break;
        *(instants + 8) = keepCount;
          goto LABEL_8;
LABEL_24:
        if (op_Inequality(gameObject, 0, 0))
        {
          v16 = keepCount - 1;
          Component_object = GetComponent_object_(gameObject);
          x = blur->colorDelta.x;
          y = blur->colorDelta.y;
          z = blur->colorDelta.z;
          w = blur->colorDelta.w;
          v27.x = x;
          v27.y = y;
          v27.z = z;
          v27.w = w;
          v28 = op_Multiply(v27, v16, 0);
          v29 = op_Addition(v28, blur->colorBase);
          v26 = Scale(v29, v25);
          (Component_object->klass->vtable[11].methodPtr)(
            Component_object,
            Component_object->klass->vtable[11].v26.x,
            v26.y,
            v26.z,
            v26.w);
          SetActive(Component_object, 1, 0);
        }
        instants = *(instants + 2);
        if (!instants)
          return;
      }
      if (op_Inequality(gameObject, 0, 0))
      {
        Destroy_27360000(gameObject);
        gameObject = 0;
      }
      Copy = GetCopy(modelRoot->modelobj);
      if (op_Inequality(Copy, 0, 0))
      {
        Copy->blur = 1;
        SetAutoHide(Copy, 1);
        gameObject = get_gameObject(Copy);
      }
      *(instants + 3) = gameObject;
      keepCount = blur->keepCount;
      *(instants + 8) = keepCount;
        goto LABEL_24;
LABEL_8:
      goto LABEL_24;
    }
  }
  instants = blur->instants;
  if (instants)
    goto LABEL_6;
}

// 0x19b3620
void mdlLinkSub(dds3ModelHandle_t **aHandle, sdfModelOt_t **aModelOt, void *modelobj, bool camera_identity) {
  UnityEngine_GameObject_o *MainCamera;
  UnityEngine_Transform_o *transform;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  UnityEngine_Transform_o *v18;
  dds3ModelHandle_t_o *v19;
  u32 stat;
  struct dds3ModelEffectCtrlr_t_o *effects;
  struct System_Object_array *work;
  UnityEngine_Transform_o *v24;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  dds3ModelEffectCtrlr_t_o *aEffect;
  UnityEngine_Quaternion_o v30;
  UnityEngine_Quaternion_o rotation;
  UnityEngine_Quaternion_o v33;
  UnityEngine_Quaternion_o v34;

  aEffect = 0;
  MainCamera = GetMainCamera(kernelObject);
  else
  {
    v30 = get_identity(0);
    x = v30.x;
    y = v30.y;
    z = v30.z;
    w = v30.w;
    if (camera_identity)
    {
LABEL_9:
      transform = get_transform(MainCamera, 0);
      rotation = get_rotation(transform);
      v13 = rotation.x;
      v14 = rotation.y;
      v15 = rotation.z;
      v16 = rotation.w;
      v18 = get_transform(MainCamera, 0);
      {
      }
      v34 = get_identity(0);
      set_rotation(v18, v34);
      v19 = *aHandle;
      stat = (*aHandle)->stat;
      if ((stat & 1) != 0)
        goto LABEL_13;
      goto LABEL_21;
    }
  }
  v13 = x;
  v14 = y;
  v15 = z;
  v16 = w;
  v19 = *aHandle;
  stat = (*aHandle)->stat;
  if ((stat & 1) != 0)
  {
LABEL_13:
    for (aEffect = v19->effects; aEffect; aEffect = aEffect->next)
    {
      mdlLinkEffectOff(aHandle, &aEffect, 0);
    }
    goto LABEL_38;
  }
LABEL_21:
  if ((stat & 6) == 0)
  {
    effects = v19->effects;
    aEffect = effects;
    if (effects)
    {
      do
      {
        work = effects->work;
        if (work->m_Items[0])
        {
          mdlLinkEffect(aHandle, &aEffect, modelobj);
        }
        effects = aEffect->next;
        aEffect = effects;
      }
      while (effects);
      v19 = *aHandle;
    }
    if (v19->blur)
    {
      mdlLinkBlur(aHandle);
    }
  }
LABEL_38:
  if (camera_identity)
  {
    v24 = get_transform(MainCamera, 0);
    v33.x = v13;
    v33.y = v14;
    v33.z = v15;
    v33.w = v16;
    set_rotation(v24, v33);
  }
}

// 0x19ade30
dds3ModelHandle_t *mdlLoad(s32 aMajor, s32 aMinor, u8 **byteData, s32 bPos) {
  dds3ModelHandle_t_o *v9;
  dds3ModelResrc_t_o *v11;
  struct dds3ModelResrc_t_o *resrc;
  struct dds3ModelResrc_t_o *v14;
  Il2CppObject *v15;
  u64 *v16;
  s32 v19;
  System_String_o *Akey;
  System_String_o *v21;
  System_String_o *v22;
  System_Byte_array *v24;
  dds3ModelHandle_t_o *v25;
  dds3ModelHandle_t_o *v26;
  struct dds3ModelResrc_t_o *v28;
  mdlEffectResrcList_t_o *v29;
  System_String_o *PBname;
  System_String_o *v32;
  s64 *v33;
  dds3ModelHandle_t_o *v35;
  System_Byte_array *v36;
  dds3ModelHandle_t_o *v39;
  mdlEffectResrcList_t_o *effectResrcList;
  System_Byte_array *bData;
  mdlEffectResrcList_t_o *efc_res_list;
  System_Byte_array *aTopPtr;
  dds3ModelHandle_t_o *aHandle;

  efc_res_list = 0;
  aTopPtr = 0;
  effectResrcList = 0;
  bData = 0;
  v9 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v9);
  aHandle = v9;
  v11 = Allocate(dds3ModelResrc_t);
  dds3ModelResrc_t___ctor(v11);
  v9->resrc = v11;
  v11->major = aMajor;
  v9->resrc->minor = aMinor;
  resrc = v9->resrc;
  v9->effects = 0;
  resrc->effectData = 0;
  v14 = v9->resrc;
  v15 = Allocate(mdlEffectResrcList_t);
  v16 = Allocate(System_Collections_Generic_List_mdlEffectResrcItem_t_);
  __ctor(
    v16);
  v15[2].klass = v16;
  _ctor(v15, 0);
  v14->effectResrcList = v15;
  if (aMajor == 1)
    goto LABEL_9;
  if (aMajor == 7)
  {
    v9->modelRoot = sdfModelMakeUnity(0, byteData, bPos);
    v9->resrc->effectData = GetPibArray(byteData, bPos);
    goto LABEL_44;
  }
  if (aMajor != 6)
  {
    if (aMajor != 2 || aMinor != 15 && aMinor != 33)
      goto LABEL_44;
    PBname = GetPBname(aMinor);
    v32 = Concat_5221536("dds3data/dvl_pb/", PBname, ".bytes");
    bData = 0;
    if (aMinor == 33)
    {
      v33 = &"dds3data/pipe/jewel_lost.PB.bytes";
    }
    else
    {
      if (aMinor != 15)
        goto LABEL_36;
      v33 = &"dds3data/pipe/jewel1.PB.bytes";
    }
    v32 = *v33;
LABEL_36:
    sdfDevLoadFileUnity_25061072(v32, &bData, 0, "pipe_common");
    v35 = aHandle;
    v36 = bData;
    v35->modelRoot = sdfModelMakeUnity(0, v36, bPos);
    v39 = aHandle;
    aHandle->resrc->effectData = &bData->obj;
    effectResrcList = v39->resrc->effectResrcList;
    mdlEffectCreatePipeForUnity(2, aMinor, &effectResrcList);
    v28 = aHandle->resrc;
    v29 = effectResrcList;
    goto LABEL_43;
  }
  if (aMinor == 336)
  {
LABEL_9:
    v19 = convDLCDevilNumber(aMinor);
    Akey = GetAkey(v19);
    v21 = GetPBname(v19);
    v22 = Concat_5221536("dds3data/dvl_pb/", v21, ".bytes");
    aTopPtr = 0;
    sdfDevLoadFileUnity_25061072(v22, &aTopPtr, 0, Akey);
    v24 = aTopPtr;
    v25 = aHandle;
    v25->modelRoot = sdfModelMakeUnity(0, v24, bPos);
    v26 = aHandle;
    aHandle->resrc->effectData = &aTopPtr->obj;
    efc_res_list = v26->resrc->effectResrcList;
    mdlEffectCreateUnity(aMajor, v19, &efc_res_list, 0);
    v28 = aHandle->resrc;
    v29 = efc_res_list;
LABEL_43:
    v28->effectResrcList = v29;
  }
LABEL_44:
  mdlGenEffect(&aHandle, -1, -1);
  return aHandle;
}

// 0x19b3b50
void mdlLoopMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber) {
  mdlMotion(aHandle, aGroup, aNumber, 1, 0.0, 0.0);
}

// 0x19b3e90
void mdlLoopMotionForUnity(void *obj, char *name, s32 value) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;

  if (!op_Equality(obj, 0, 0))
  {
    transform = get_transform(obj, 0);
    Child = GetChild(transform, 0);
    gameObject = get_gameObject(Child);
    Component_object = GetComponent_object_(gameObject);
    if (!op_Equality(Component_object, 0, 0))
      SetInteger(Component_object, name, value);
  }
}

// 0x19b6ed0
void mdlMakeHddFileList(void) {
  ;
}

// 0x19b6ec0
void mdlMakeHddFileListDummy(void) {
  ;
}

// 0x19b3960
void mdlMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, s32 aType, f32 aBeforeLeng, f32 aSmoothLeng) {
  struct sdfMotionCtrlr_t_o *motion;
  sdfMotionCtrlr_t_o *v14;
  u32 userId2;
  struct sdfMotionCtrlr_t_array *motions;
  s64 v18;

  motion = (*aHandle)->modelRoot->motion;
  if (motion)
  {
    while (motion->userId != aGroup)
    {
      motion = motion->next;
      if (!motion)
        goto LABEL_6;
    }
    userId2 = motion->userId2;
    motions = (*aHandle)->motions;
    LOWORD(v18) = motion->userId2;
    goto LABEL_12;
  }
LABEL_6:
  v14 = mdlCreateMotion(aHandle, aGroup, *&aNumber);
  userId2 = v14->userId2;
  motion = v14;
  motions = (*aHandle)->motions;
  LOWORD(v18) = v14->userId2;
  if (v14)
  {
LABEL_12:
  }
  motions->m_Items[v18] = motion;
  if (!v18)
    (*aHandle)->motionCtrlr = motion;
  sdfMotionChangeBlend(motion, aNumber, aType, aBeforeLeng, aSmoothLeng);
  (*aHandle)->motionMajorNum = aGroup;
  (*aHandle)->motionMinorNum = aNumber;
  mdlStopEffect(aHandle, userId2);
  mdlGenEffect(aHandle, aNumber, userId2);
}

// 0x19b5550
void mdlMotionPause(dds3ModelHandle_t **aHandle) {
  struct sdfMotionCtrlr_t_o *i;

  for (i = (*aHandle)->modelRoot->motion; i; i = i->next)
  {
    sdfMotionPause(i);
  }
}

// 0x19b55e0
void mdlMotionPauseOff(dds3ModelHandle_t **aHandle) {
  struct sdfMotionCtrlr_t_o *i;

  for (i = (*aHandle)->modelRoot->motion; i; i = i->next)
  {
    sdfMotionPauseOff(i);
  }
}

// 0x19b7200
void mdlMotionStopKutiForUnity(evtUnitHandle_t **h, s32 index, bool sw) {
  struct dds3Basic_t_o *Owner;
  UnityEngine_Object_o *gameObject;
  UnityEngine_Component_o *transform;
  UnityEngine_GameObject_o *v11;
  UnityEngine_Component_o *Animator;
  UnityEngine_GUILayer_o *Component_GUILayer;
  struct System_Int16_array *ExWaitMotion;

  if (*h && !sw)
  {
    Owner = (*h)->Owner;
    gameObject = Owner->gameObject;
    if (!op_Equality(gameObject, 0, 0))
    {
      transform = get_transform(Owner->gameObject, 0);
      v11 = get_gameObject(transform);
      Animator = GetAnimator(v11);
      if (!op_Equality(Animator, 0, 0))
      {
        Component_GUILayer = GetComponent_GUILayer_(Animator);
        if (!op_Equality(Component_GUILayer, 0, 0))
        {
          ExWaitMotion = (*h)->ExWaitMotion;
          StopKUTI(Component_GUILayer, index, ExWaitMotion->m_Items[index]);
        }
      }
    }
  }
}

// 0x19b3db0
void mdlMotionSub(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber) {
  struct dds3ModelResrcPlayBook_t_array *playbooks;
  s32 playGroup;

  playbooks = (*aHandle)->resrc->playbooks;
  playGroup = playbooks->m_Items[aGroup]->playGroup;
  (*aHandle)->motionMajorNum = aGroup;
  (*aHandle)->motionMinorNum = aNumber;
  mdlStopEffect(aHandle, playGroup);
  mdlGenEffect(aHandle, aNumber, playGroup);
}

// 0x19b5c20
s32 mdlPackCheck(sdfPacDecodeResrc_t **resrc) {
  struct sdfPacStdBlockHeader_t_o *header;
  u32 magicCode;

  header = (*resrc)->header;
  if (header->fileType != 1)
    return 0;
  magicCode = header->magicCode;
  return magicCode == 809650512;
}

// 0x19b6e90
void mdlPackDecode(s32 major, s32 minor, u32 regFlags, void *buff, s32 leng) {
  ;
}

// 0x19b5cd0
sdfPacDecodeResrc_t *mdlPackSet(sdfPacDecodeResrc_t **resrc, s32 major, s32 minor, u32 regFlags) {
  struct sdfPacStdBlockHeader_t_o *header;
  u32 magicCode;
  Il2CppObject *ptr;
  Il2CppObject *v12;
  sdfPacDecodeResrc_t_o *v13;
  Il2CppClass *handle;
  u64 *image;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  Il2CppClass *v19;
  u64 *v20;
  s64 v21;
  char *v22;
  s64 *v23;
  Il2CppObject *v24;
  Il2CppClass *klass;
  s64 v26;
  char *v27;
  s64 *v28;
  u64 v32[2];
  char *v33;

LABEL_7:
  header = (*resrc)->header;
  if (header->fileType == 1)
  {
    magicCode = header->magicCode;
    else if (magicCode == 809650512)
    {
LABEL_11:
      ptr = (*resrc)->ptr;
      v12 = Allocate(mdlSetDef_t);
      _ctor(v12, 0);
      v12[3].monitor = ptr;
      v13 = sdfPacFreeResrc(*resrc);
      *resrc = v13;
      if (v13->header->fileType == 9)
      {
        handle = v13->handle;
        if (handle)
        {
          image = handle->_1.image;
          if (*(handle->_1.image + 288) < typeHierarchyDepth
            || *(image[25] + 8 * typeHierarchyDepth - 8) != sdfModelTexList_t)
          {
            sub_8FC2C0(image[8], sdfModelTexList_t, v32);
            if ((v32[0] & 1) != 0)
              v17 = v33;
            else
              v17 = v32 + 1;
            v18 = sub_8C4940(v17);
          }
        }
        v12[1].klass = handle;
        v13 = sdfPacFreeResrc(*resrc);
        *resrc = v13;
      }
      v19 = v13->handle;
      if (v19)
      {
        v20 = v19->_1.image;
        if (*(v19->_1.image + 288) < v21 || *(v20[25] + 8 * v21 - 8) != sdfMemHandle_t)
        {
          sub_8FC2C0(v20[8], sdfMemHandle_t, v32);
          if ((v32[0] & 1) != 0)
            v22 = v33;
          else
            v22 = v32 + 1;
          v23 = sub_8C4940(v22);
        }
      }
      v12[2].klass = v19;
      v24 = (*resrc)->ptr;
      if (v24)
      {
        klass = v24->klass;
        if (v24->klass->_2.typeHierarchyDepth < v26
          || klass->_2.typeHierarchy[v26 - 1] != sdfModelDef_t)
        {
          sub_8FC2C0(klass->_1.element_class, sdfModelDef_t, v32);
          if ((v32[0] & 1) != 0)
            v27 = v33;
          else
            v27 = v32 + 1;
          v28 = sub_8C4940(v27);
        }
      }
      v12[1].monitor = v24;
      *resrc = sdfPacFreeResrc(*resrc);
      mdlRegistModelSet(major, minor, regFlags, v12);
      return *resrc;
    }
  }
  return *resrc;
}

// 0x19b5cc0
sdfPacDecodeResrc_t *mdlPackSetOld(sdfPacDecodeResrc_t **resrc, s32 major, s32 minor, u32 regFlags) {
  return *resrc;
}

// 0x19acf20
dds3ModelResrc_t *mdlPrepare(s32 aMajor, s32 aMinor, s32 aBlockMode) {
  struct dds3ModelResrc_t_array *mdlResrcMajorList;
  dds3ModelResrc_t_o *result;
  struct mdlLoadingTag_t_array *mdlLoadingMajorList;
  mdlLoadingTag_t_o *next;
  struct dds3ModelFileKindTable_t_array *modelFileKindTable;
  struct dds3ModelFileIndex_t_array *indexTable;
  dds3ModelFileIndex_t_o *v20;
  s64 major;
  s64 minor;
  struct dds3ModelFileTableDef_t_array *modelFileTable;
  struct dds3ModelFileTable_t_array *fileTable;
  dds3ModelFileTable_t_o *v28;
  System_String_o *v31;
  System_String_o *modelFile;
  u64 *v40;
  u64 *v41;

LABEL_7:
  result = mdlResrcMajorList->m_Items[aMajor];
  if (!result)
  {
LABEL_15:
    else if ((byte_3F5AC74 & 1) != 0)
    {
LABEL_19:
      next = mdlLoadingMajorList->m_Items[aMajor];
      if (next)
      {
        while (next->minor != aMinor)
        {
          next = next->next;
          if (!next)
            goto LABEL_27;
        }
        if (aBlockMode)
        {
          return mdlWaitLoadEnd(aMajor, aMinor, *&aBlockMode);
        }
        return 0;
      }
LABEL_27:
      if ((aMajor & 0x80000000) == 0
      {
      }
      indexTable = modelFileKindTable->m_Items[aMajor]->indexTable;
      v20 = indexTable->m_Items[aMinor];
      major = v20->major;
      minor = v20->minor;
      fileTable = modelFileTable->m_Items[major]->fileTable;
      v28 = fileTable->m_Items[minor];
      v31 = StrRChr(v28->modelFile, 0x2Eu);
      if (v31)
      {
        LODWORD(v31) = (ci->klass->vtable._7_Compare.methodPtr)(
                         ci,
                         v31,
                         ".PB",
                         1,
                         ci->klass->vtable._7_Compare.method) == 0;
      }
      else
      {
        mdlRegLoading(aMajor, aMinor);
        if (v31)
          goto LABEL_53;
      }
      v40 = Allocate(mdlManager_mdlTbMbAbLoadCb_t);
      _ctor(v40, 0);
      *(v40 + 6) = 0;
      v40[2] = 0;
      v41 = Allocate(mdlSetDef_t);
      _ctor(v41, 0);
      v40[4] = v41;
      *(v40 + 8) = aMajor;
      *(v40 + 9) = aMinor;
      *(v40 + 6) = 257;
      if (v28->motionFile)
        *(v40 + 22) = 1;
      if (v28->texFile)
      {
        *(v40 + 20) = 1;
      }
      *(v40 + 21) = 1;
      if (v28->motionFile
      {
        if (!aBlockMode)
          return 0;
        goto LABEL_58;
      }
LABEL_57:
      if (!aBlockMode)
        return 0;
LABEL_58:
      return mdlWaitLoadEnd(aMajor, aMinor);
    }
    goto LABEL_19;
  }
  while (result->minor != aMinor)
  {
    result = result->next;
    if (!result)
      goto LABEL_15;
  }
  return result;
}

// 0x19b8ef0
void mdlRasterLevel(void *obj, f32 val) {
  Il2CppObject *Component_object;

  if (!op_Equality(obj, 0, 0))
  {
    Component_object = GetComponent_object_(obj);
    if (op_Inequality(Component_object, 0, 0))
      SetRasterLevel(Component_object, val);
  }
}

// 0x19ab9f0
void mdlRegLoading(s32 aMajor, s32 aMinor) {
  u64 *v5;
  struct mdlLoadingTag_t_array *mdlLoadingMajorList;
  struct mdlLoadingTag_t_array *v10;

  v5 = Allocate(mdlLoadingTag_t);
  _ctor(v5, 0);
  v5[2] = mdlLoadingMajorList->m_Items[aMajor];
  *(v5 + 6) = aMinor;
  v10 = mdlLoadingMajorList;
  v10->m_Items[aMajor] = v5;
}

// 0x19ab380
void mdlRegist(s32 aMajor, s32 aMinor, s32 aFlag, sdfModelTexList_t **aTexList, sdfModelDef_t **aData, sdfMemHandle_t **aHandle) {
  char v10;
  u64 *v13;
  struct dds3ModelResrc_t_array *mdlResrcMajorList;
  dds3ModelResrc_t_o *v18;
  struct dds3ModelResrc_t_array *v19;
  sdfMemHandle_t_o *v22;
  s64 v23;
  u64 v24;
  u64 v25;
  u64 v27;
  u64 v29;
  s64 v31;

  v10 = aFlag;
  mdlUnRegist(aMajor, aMinor, *&aFlag);
  v13 = Allocate(dds3ModelResrc_t);
  dds3ModelResrc_t___ctor(v13);
  v18 = mdlResrcMajorList->m_Items[aMajor];
  if (v18)
    v18->prev = v13;
  else
  {
    v19 = mdlResrcMajorList;
    if (!v13)
      goto LABEL_16;
  }
LABEL_16:
  v19->m_Items[aMajor] = v13;
  *(v13 + 16) = aMajor;
  v13[2] = v18;
  v13[3] = 0;
  *(v13 + 17) = aMinor;
  v13[6] = 0;
  v13[7] = *aTexList;
  v13[8] = *aData;
  v22 = *aHandle;
  v23 = 4;
  v13[9] = v22;
  do
  {
    v24 = v13[10];
    v25 = v23 - 4;
    *(*(v24 + 8 * v23) + 16LL) = 0;
    v27 = v13[10];
    *(*(v27 + 8 * v23) + 24LL) = 0;
    v29 = v13[10];
    v31 = *(v29 + 8 * v23++);
    *(v31 + 32) = 0;
  }
  while (v23 != 12);
  *(v13 + 36) = v10 & 1;
  v13[11] = 0;
  v13[12] = 0;
  v13[13] = 0;
  v13[14] = 0x42C800003F800000LL;
}

// 0x19ab1b0
void mdlRegistModelSet(s32 aMajor, s32 aMinor, s32 aFlag, mdlSetDef_t *aSet) {
  mdlRegist(aMajor, aMinor, aFlag, &aSet->texList, &aSet->modelDefPtr, &aSet->modelDefHandle);
  if (aSet->playbookPtr)
  {
    mdlRegistMotion(aMajor, aMinor, aFlag, 0, 0, 0, &aSet->playbookPtr, &aSet->playbookHandle);
  }
  if (aSet->effectData)
  {
    else if ((byte_3F5AC73 & 1) != 0)
    {
      goto LABEL_16;
    }
    goto LABEL_16;
  }
}

// 0x19ab5d0
void mdlRegistMotion(s32 aMajor, s32 aMinor, s32 aFlags, s32 aFirstMotion, s32 aGroup, s32 aPlayGroup, sdfMotionPlayBook_t **aData, sdfMemHandle_t **aHandle) {
  s16 v11;
  s16 v13;
  s16 v14;
  struct dds3ModelResrc_t_array *mdlResrcMajorList;
  dds3ModelResrc_t_o *i;
  struct dds3ModelResrcPlayBook_t_array *playbooks;
  dds3ModelResrcPlayBook_t_o *v23;
  s32 v24;
  dds3ModelResrc_t_o *aResrc;

  v11 = aPlayGroup;
  v13 = aFirstMotion;
  v14 = aFlags;
  aResrc = 0;
LABEL_7:
  for (i = mdlResrcMajorList->m_Items[aMajor]; i; i = i->next)
  {
    if (i->minor == aMinor)
      break;
  }
  aResrc = i;
  mdlUnRegistResrcMotion(&aResrc, aGroup, *&aFlags);
  playbooks = i->playbooks;
  v23 = playbooks->m_Items[aGroup];
  v23->flags = 0;
  v23->playGroup = v11;
  v23->firstMotion = v13;
  v23->ptr = *aData;
  v23->handle = *aHandle;
  if ((v14 & 0x300) != 0)
  {
    if ((v14 & 0x100) != 0)
      v24 = 3;
    else
      v24 = 2;
    if ((v14 & 0x200) == 0)
      v24 = 1;
    v23->flags = v24;
  }
}

// 0x19b6eb0
void mdlReleaseHddFileList(void) {
  ;
}

// 0x19ab790
dds3ModelResrc_t *mdlSearchResrc(s32 aMajor, s32 aMinor) {
  struct dds3ModelResrc_t_array *mdlResrcMajorList;
  dds3ModelResrc_t_o *result;

  for (result = mdlResrcMajorList->m_Items[aMajor]; result; result = result->next)
  {
    if (result->minor == aMinor)
      break;
  }
  return result;
}

// 0x19ad790
void mdlSetBlur(dds3ModelHandle_t **aHandle, s32 interval, s32 count, u32 startColor, u32 endColor) {
  dds3ModelHandle_t_o *v11;
  struct dds3ModelBlurCb_t_o *blur;
  struct dds3ModelBlurInstance_t_o *instants;
  struct dds3ModelBlurInstance_t_o *v14;
  UnityEngine_Object_o *modelobj;
  u64 *v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  u64 v22;
  s64 v23;
  u64 v24;
  s64 v25;

LABEL_7:
  v11 = *aHandle;
  blur = (*aHandle)->blur;
  if (blur)
  {
    instants = blur->instants;
    if (instants)
    {
      do
      {
        v14 = instants;
        instants = instants->next;
        modelobj = v14->modelobj;
        Destroy_27360000(modelobj);
        v14->modelobj = 0;
      }
      while (instants);
      v11 = *aHandle;
    }
    v11->blur = 0;
  }
  if (count >= 1)
  {
    v16 = Allocate(dds3ModelBlurCb_t);
    _ctor(v16, 0);
    *(v16 + 8) = 0;
    v16[2] = 0;
    v16[3] = 0;
    v24 = 0;
    v25 = 0;
    sub_854690(&v24, 0.0, 0.0, 0.0, 0.0);
    v18 = v25;
    v17 = HIDWORD(v25);
    *(v16 + 36) = v24;
    *(v16 + 11) = v18;
    *(v16 + 12) = v17;
    v22 = 0;
    v23 = 0;
    sub_854690(&v22, 0.0, 0.0, 0.0, 0.0);
    v20 = v23;
    v19 = HIDWORD(v23);
    *(v16 + 52) = v22;
    *(v16 + 15) = v20;
    *(v16 + 16) = v19;
    (*aHandle)->blur = v16;
    *(v16 + 12) = count;
    *(v16 + 13) = count;
    v21 = count * interval;
    *(v16 + 15) = 1;
    *(v16 + 14) = interval;
    *(v16 + 8) = v21;
    SDF_VU0__dds3ColorItoF(endColor);
    SDF_VU0__STOREVECTOR((v16 + 36), 0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__dds3ColorItoF(startColor);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__SCALEVECTOR(1.0 / v21);
    SDF_VU0__STOREVECTOR((v16 + 52), 0);
  }
}

// 0x19b5a40
void mdlSetClutColor(dds3ModelHandle_t **aHandle, u32 aColor, f32 aRatio) {
  sdfModelTexList_t_o *texList;

  texList = (*aHandle)->modelRoot->texList;
  sdfTexListSetClutColor(texList, aColor, aRatio);
}

// 0x19b5070
void mdlSetColor(dds3ModelHandle_t **aHandle, u32 aColor) {
  dds3ModelHandle_t_o *v5;
  u32 v6;
  dds3ModelEffectCtrlr_t_o *aEffect;

  v5 = *aHandle;
  if (v5 && v5->modelRoot)
  {
    (*aHandle)->modelRoot->color = aColor;
    aEffect = (*aHandle)->effects;
    if (aEffect)
    {
      v6 = aColor & 0xFF000000 | 0x808080;
      do
      {
        mdlSetEffectColorSub(aHandle, &aEffect, v6);
        aEffect = aEffect->next;
      }
      while (aEffect);
    }
  }
}

// 0x19b51a0
void mdlSetColorWithEffect(dds3ModelHandle_t **aHandle, u32 aColor) {
  dds3ModelHandle_t_o *v5;
  dds3ModelEffectCtrlr_t_o *aEffect;

  v5 = *aHandle;
  if (v5 && v5->modelRoot)
  {
    (*aHandle)->modelRoot->color = aColor;
    for (aEffect = (*aHandle)->effects; aEffect; aEffect = aEffect->next)
    {
      mdlSetEffectColorSub(aHandle, &aEffect, aColor);
    }
  }
}

// 0x19b4fd0
void mdlSetEffectColor(dds3ModelHandle_t **aHandle, u32 aColor) {
  dds3ModelEffectCtrlr_t_o *aEffect;

  for (aEffect = (*aHandle)->effects; aEffect; aEffect = aEffect->next)
  {
    mdlSetEffectColorSub(aHandle, &aEffect, aColor);
  }
}

// 0x19b52c0
void mdlSetEffectScale(dds3ModelHandle_t **aHandle, f32 aScale) {
  dds3ModelEffectCtrlr_t_o *aEffect;

  for (aEffect = (*aHandle)->effects; aEffect; aEffect = aEffect->next)
  {
    mdlSetEffectScaleSub(aHandle, &aEffect, aScale);
  }
}

// 0x19acf10
void mdlSetFileName(char **buff, char *fname) {
  *buff = fname;
}

// 0x19b88e0
FieldChrHD *mdlSetHD(void *obj, s32 mode, evtUnitHandle_t *hunit, s32 layer) {
  Il2CppObject *v9;
  s32 v10;

  v9 = AddComponent_object_(obj);
  set_layer(obj, layer);
  v10 = get_layer(obj);
  SetLayer(v9, v10);
  SetModelObject(v9, obj, 0);
  SetForm(v9, 0, 0);
  SetBattle(v9, mode);
  SetEveUnit(v9, hunit);
  AddDanteGun(obj, v9, hunit);
  return v9;
}

// 0x19aabb0
void mdlSetLight(dds3ModelHandle_t **HNDL, sdf3DLightParallelPacket_t *LIGHT) {
  struct sdfModelRootNode_t_o *modelRoot;

  if (*HNDL)
  {
    modelRoot = (*HNDL)->modelRoot;
    if (modelRoot)
      modelRoot->light = LIGHT;
  }
}

// 0x19aabd0
void mdlSetLightUnity(dds3ModelHandle_t **HNDL, sdf3DLight_t **uLight, sdfVector4_t uAmbient) {
  dds3ModelHandle_t_o *v4;

  v4 = *HNDL;
  if (*HNDL)
  {
    if (v4->modelRoot)
    {
      v4->uLight = uLight;
      (*HNDL)->uAmbient = uAmbient;
    }
  }
}

// 0x19b6970
void mdlSetMotionForUnity(dds3ModelHandle_t *mhdl, sdfPacDecodeResrc_t *resrc, s32 major, s32 minor, u32 regFlags) {
  sdfPacDecodeResrc_t_o *next;
  sdfPacDecodeResrc_t_Fields *p_fields;
  struct sdfPacStdBlockHeader_t_o *header;
  u32 magicCode;
  sdfPacDecodeResrc_t_o *v13;
  struct sdfPacDecodeResrc_t_o *v14;
  Il2CppObject *handle;
  u64 *v16;
  s64 *ptr;
  Il2CppClass *v19;
  s64 *Interface;
  char *v21;
  s64 *v22;
  sdfMotionPlayBook_t_o *v24;
  struct dds3ModelResrc_t_array *mdlResrcMajorList;
  s64 v28;
  s64 v29;
  s32 v30;
  s64 v31;
  u64 v33[3];

  next = resrc;
  p_fields = &next->fields;
  if (!next->next)
  {
LABEL_18:
    handle = next->handle;
    mdlPibGetMotionCount(handle, 0);
    if (next->header->fileType == 8)
      goto LABEL_25;
LABEL_50:
    next = next->next;
    if (!next)
      return;
    while (1)
    {
      if (next->header->fileType != 8)
        goto LABEL_50;
LABEL_25:
      v16 = Allocate(sdfMotionPlayBook_t);
      sdfMotionPlayBook_t___ctor(v16);
      ptr = next->ptr;
      else if (!ptr)
      {
        goto LABEL_34;
      }
      Interface = QueryInterface(ptr, byte);
      if (!Interface)
      {
        sub_8FC2C0(*(*ptr + 64), v19, v33);
        if ((v33[0] & 1) != 0)
          v21 = v33[2];
        else
          v21 = v33 + 1;
        v22 = sub_8C4940(v21);
      }
LABEL_35:
      v24 = SetsdfMotionPlayBook(Interface, 0);
      if ((byte_3F5AC73 & 1) == 0)
        goto LABEL_38;
LABEL_39:
      v28 = &mdlResrcMajorList->m_Items[major];
      do
      {
        v29 = *v28;
        v30 = *(*v28 + 34LL);
        v28 = *v28 + 16LL;
      }
      while (v30 != minor);
      v31 = *(v29 + 80);
      *(*(v31 + 32) + 24LL) = v24;
      mhdl->motionMajorNum = major;
      mhdl->motionMinorNum = minor;
    }
  }
  do
  {
    if ((byte_3F5AC8A & 1) == 0)
      goto LABEL_10;
LABEL_11:
    header = next->header;
    if (header->fileType == 1)
    {
      magicCode = header->magicCode;
      if (magicCode == 809650512)
        goto LABEL_18;
    }
    next = p_fields->next;
    v13 = p_fields->next;
    v14 = v13->next;
    p_fields = &v13->fields;
  }
  while (v14);
  if (next)
    goto LABEL_18;
}

// 0x19b4810
void mdlSetMotionSpeed(dds3ModelHandle_t **aHandle, f32 speed) {
  struct sdfMotionCtrlr_t_o *motion;

LABEL_7:
  else
  {
    motion = (*aHandle)->modelRoot->motion;
    if (motion)
      goto LABEL_10;
  }
}

// 0x19b49d0
void mdlSetMotionSpeedAnimator(void *mAnimator, f32 speed) {
  UnityEngine_GUILayer_o *Component_GUILayer;

  if (op_Inequality(mAnimator, 0, 0))
  {
    Component_GUILayer = GetComponent_GUILayer_(mAnimator);
    if (op_Inequality(Component_GUILayer, 0, 0))
    {
      *&Component_GUILayer[1].monitor = speed;
      if (speed == 0.0)
        return;
LABEL_14:
      set_keepAnimatorControllerStateOnDisable(mAnimator, 0);
      return;
    }
    set_speed(mAnimator, speed);
    if (speed != 0.0)
      goto LABEL_14;
  }
}

// 0x19b4910
void mdlSetMotionSpeedEx(dds3ModelHandle_t **aHandle, s32 aGroup, f32 speed) {
  struct sdfMotionCtrlr_t_o *motion;

  else
  {
    motion = (*aHandle)->modelRoot->motion;
    if (motion)
      goto LABEL_6;
  }
}

// 0x19b87b0
void mdlSetMotionSpeedForUnity(evtUnitHandle_t **h, s32 layer, f32 speed) {
  ;
}

// 0x19b87c0
void mdlSetMotionSpeedForUnity_26970048(void *obj, s32 layer, f32 speed) {
  UnityEngine_Component_o *Animator;
  UnityEngine_GUILayer_o *Component_GUILayer;

  Animator = GetAnimator(obj, *&layer);
  if (!op_Equality(Animator, 0, 0))
  {
    Component_GUILayer = GetComponent_GUILayer_(Animator);
    if (op_Inequality(Component_GUILayer, 0, 0))
      *&Component_GUILayer[1].monitor = speed;
    else
      set_speed(Animator, speed);
  }
}

// 0x19b4c40
void mdlSetPosition(dds3ModelHandle_t **aHandle) {
  dds3ModelHandle_t_o *v3;
  UnityEngine_Vector4_o v4;

  *&v4.x = 0;
  *&v4.z = 0;
  v3 = *aHandle;
  else if (!v3)
  {
    return;
  }
  if (v3->modelRoot)
  {
    SDF_VU0__VECTOR_W_SET_ONE();
    *&v4.x = 0;
    *&v4.z = 0;
    SDF_VU0__STOREVECTOR(&v4);
    sub_1A00AD0(&(*aHandle)->modelRoot->tm, 3u);
  }
}

// 0x19b4d20
void mdlSetRotate(dds3ModelHandle_t **aHandle) {
  dds3ModelHandle_t_o *v3;
  UnityEngine_Vector4_o v4;
  UnityEngine_Vector4_o v5;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  *&v5.x = 0;
  *&v5.z = 0;
  *&v4.x = 0;
  *&v4.z = 0;
  v3 = *aHandle;
  else if (!v3)
  {
    return;
  }
  if (v3->modelRoot)
  {
    SDF_VU0__STOREVECTOR(&(*aHandle)->modelRoot->rotate, 0);
    ToMatrix();
    SDF_VU0__STORE_ROW0(&p);
    SDF_VU0__STORE_ROW1(&v5);
    SDF_VU0__STORE_ROW2(&v4);
    sub_1A00AD0(&(*aHandle)->modelRoot->tm, 0);
    sub_1A00AD0(&(*aHandle)->modelRoot->tm, 1u);
    sub_1A00AD0(&(*aHandle)->modelRoot->tm, 2u);
  }
}

// 0x19b4e70
void mdlSetScale(dds3ModelHandle_t **aHandle) {
  dds3ModelHandle_t_o *v3;

  v3 = *aHandle;
  else if (!v3)
  {
    return;
  }
  if (v3->modelRoot)
    SDF_VU0__STOREVECTOR(&(*aHandle)->modelRoot->scale, 0);
}

// 0x19b4f00
void mdlSetScaleHD(void *modelobj) {
  UnityEngine_Vector4_o v2;

  *&v2.x = 0;
  *&v2.z = 0;
  SDF_VU0__STOREVECTOR(&v2);
}

// 0x19aacc0
void mdlShow(dds3ModelHandle_t *mdl) {
  struct dds3Basic_t_o *Owner;
  UnityEngine_GameObject_o *gameObject;
  System_String_o *name;
  System_String_o *v6;
  Il2CppObject *Component_object;

  mdl->stat &= ~1u;
  Owner = mdl->Owner;
  if (Owner)
  {
    gameObject = Owner->gameObject;
    if (op_Inequality(gameObject, 0, 0))
    {
      SetActive(gameObject, 1, 0);
      name = get_name(gameObject);
      if (Contains(name, "raidou_e730", 0)
        || (v6 = get_name(gameObject), Contains(v6, "dante_e730", 0)))
      {
        Component_object = GetComponent_object_(gameObject);
        if (op_Inequality(Component_object, 0, 0))
          UpdateGlobal(Component_object);
      }
    }
  }
}

// 0x19b3be0
void mdlSingleMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber) {
  mdlMotion(aHandle, aGroup, aNumber, 0, 0.0, 0.0);
}

// 0x19b3fa0
void mdlSingleMotionForUnity(void *obj, char *name, s32 value, bool reset, s32 index) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  UnityEngine_GUILayer_o *Component_GUILayer;

  if (!op_Equality(obj, 0, 0))
  {
    transform = get_transform(obj, 0);
    Child = GetChild(transform, 0);
    gameObject = get_gameObject(Child);
    Component_object = GetComponent_object_(gameObject);
    if (!op_Equality(Component_object, 0, 0))
    {
      SetInteger(Component_object, name, value);
      if (reset)
      {
        Component_GUILayer = GetComponent_GUILayer_(Component_object);
        if (!op_Equality(Component_GUILayer, 0, 0))
          ResetFlag(Component_GUILayer, index, 0);
      }
    }
  }
}

// 0x19b3c70
void mdlSmoothLoopMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, f32 aBeforeLeng, f32 aSmoothLeng) {
  mdlMotion(aHandle, aGroup, aNumber, 1, aBeforeLeng, aSmoothLeng);
}

// 0x19b7d80
void mdlSmoothLoopMotionForUnity(evtUnitHandle_t **h, s32 layer, s32 motion, s32 before, s32 wait, bool btl) {
  struct dds3Basic_t_o *Owner;
  UnityEngine_Object_o *gameObject;
  UnityEngine_Component_o *transform;
  UnityEngine_GameObject_o *v17;
  UnityEngine_Component_o *Animator;
  UnityEngine_GameObject_o *v20;
  Il2CppObject *Component_object;
  struct dds3ModelHandle_t_o *Model;
  u64 *v24;
  u64 *v25;
  System_String_o *v27;
  char v28;
  u64 *v29;
  UnityEngine_GameObject_o *v30;
  u64 *v34;
  System_String_o *v35;
  System_String_o *name;
  s32 v38;
  dds3Basic_t_o **p_Owner;
  u64 *v43;
  s32 v44;
  s32 v45;
  s32 v46;
  s32 v47;
  dds3Basic_t_o *basic;

  basic = 0;
  if (*h)
  {
    Owner = (*h)->Owner;
    basic = Owner;
    gameObject = Owner->gameObject;
    if (!op_Equality(gameObject, 0, 0))
      goto LABEL_18;
    if (check_player(&basic))
    {
LABEL_18:
      transform = get_transform(Owner->gameObject, 0);
      v17 = get_gameObject(transform);
      Animator = GetAnimator(v17);
      if (!op_Equality(Animator, 0, 0))
      {
        v44 = before;
        v45 = wait;
        v20 = get_gameObject(Animator);
        Component_object = GetComponent_object_(v20);
        if (op_Inequality(Component_object, 0, 0))
          ResetFlag(Component_object, layer, 0);
        if (layer || (Model = (*h)->Model) == 0)
        {
          if (layer)
          {
            v47 = layer;
            v24 = sub_8D3950(s32, &v47);
            v46 = motion;
            v25 = sub_8D3950(s32, &v46);
            v27 = Format_5268592("{0:D2}_{1:D2}", v24, v25);
            v28 = 1;
            goto LABEL_30;
          }
        }
        else
        {
          Model->motionMajorNum = 0;
          (*h)->Model->motionMinorNum = motion;
        }
        v47 = motion;
        v29 = sub_8D3950(s32, &v47);
        v27 = Format("{0:D2}", v29, 0);
        v28 = 0;
LABEL_30:
        v30 = Owner->gameObject;
        if (v28 & 1 | (is_devil(v30) == -1))
          goto LABEL_43;
        if (get_parameterCount(Animator))
        {
          SetInteger_8774000(Animator, id_anim, motion);
        }
        v47 = motion;
        v34 = sub_8D3950(s32, &v47);
        v35 = Format("b{0:D2}", v34, 0);
        name = (*h)->Owner->name;
        v27 = v35;
        if (is_eventdevil(name) == -1)
        {
          if (motion)
            v38 = 3;
          else
            v38 = 1;
        }
        else
        {
LABEL_43:
          v38 = 0;
        }
        p_Owner = &(*h)->Owner;
        if (check_player(p_Owner))
        {
          if (!motion)
          {
            if (!fldProcCheckFlag(0x40u) && get_parameterCount(Animator))
            {
              SetInteger_8774000(Animator, id_anim, 0);
            }
          }
          v47 = motion;
          v43 = sub_8D3950(s32, &v47);
          v27 = Format("{0:D2}", v43, 0);
          if (((*h)->Flag & 1) != 0)
            v38 = 3;
          else
            v38 |= 1u;
        }
        if (op_Inequality(Component_object, 0, 0))
        {
          if ((*h)->e723sp)
          {
            PlayFrameControl(Component_object, motion);
            (*h)->e723sp = 0;
          }
          else
          {
            Play(Component_object, v27, motion, layer, 0.0, v44, v45, 1, v38, 0);
          }
        }
        else
        {
          Play_8777152(Animator, v27, layer, 0.0);
        }
      }
    }
  }
}

// 0x19b3d10
void mdlSmoothSingleMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, f32 aBeforeLeng, f32 aSmoothLeng) {
  mdlMotion(aHandle, aGroup, aNumber, 0, aBeforeLeng, aSmoothLeng);
}

// 0x19b7620
void mdlSmoothSingleMotionForUnity(evtUnitHandle_t **h, s32 layer, s32 motion, s32 before, s32 wait, bool btl) {
  struct dds3Basic_t_o *Owner;
  UnityEngine_Object_o *gameObject;
  UnityEngine_Component_o *transform;
  UnityEngine_GameObject_o *v17;
  UnityEngine_Component_o *Animator;
  UnityEngine_GameObject_o *v20;
  Il2CppObject *Component_object;
  struct dds3ModelHandle_t_o *Model;
  u64 *v24;
  u64 *v25;
  System_String_o *v27;
  s32 v28;
  u64 *v29;
  UnityEngine_GameObject_o *v30;
  evtUnitHandle_t_o *v32;
  s32 v33;
  u64 *v35;
  System_String_o *v36;
  dds3Basic_t_o **p_Owner;
  u64 *v41;
  s32 v42;
  s32 v43;
  s32 v44;
  s32 v45;
  dds3Basic_t_o *basic;

  basic = 0;
  if (*h)
  {
    Owner = (*h)->Owner;
    basic = Owner;
    gameObject = Owner->gameObject;
    if (!op_Equality(gameObject, 0, 0))
      goto LABEL_18;
    if (check_player(&basic))
    {
LABEL_18:
      transform = get_transform(Owner->gameObject, 0);
      v17 = get_gameObject(transform);
      Animator = GetAnimator(v17);
      if (!op_Equality(Animator, 0, 0))
      {
        v42 = before;
        v43 = wait;
        v20 = get_gameObject(Animator);
        Component_object = GetComponent_object_(v20);
        if (op_Inequality(Component_object, 0, 0))
          ResetFlag(Component_object, layer, 0);
        if (layer || (Model = (*h)->Model) == 0)
        {
          if (layer)
          {
            v45 = layer;
            v24 = sub_8D3950(s32, &v45);
            v44 = motion;
            v25 = sub_8D3950(s32, &v44);
            v27 = Format_5268592("{0:D2}_{1:D2}", v24, v25);
            v28 = 1;
            goto LABEL_30;
          }
        }
        else
        {
          Model->motionMajorNum = 0;
          (*h)->Model->motionMinorNum = motion;
        }
        v45 = motion;
        v29 = sub_8D3950(s32, &v45);
        v27 = Format("{0:D2}", v29, 0);
        v28 = 0;
LABEL_30:
        v30 = Owner->gameObject;
        if (((is_devil(v30) != -1) & ~v28) != 0)
        {
          SetInteger_8774000(Animator, id_anim, motion);
          v45 = motion;
          v35 = sub_8D3950(s32, &v45);
          v36 = Format("b{0:D2}", v35, 0);
          v32 = *h;
          v27 = v36;
          if (((*h)->Flag & 1) != 0)
            v33 = 3;
          else
            v33 = 1;
        }
        else
        {
          v32 = *h;
          v33 = 0;
        }
        p_Owner = &v32->Owner;
        if (check_player(p_Owner))
        {
          if (!motion)
          {
            if (!fldProcCheckFlag(0x40u))
            {
              SetInteger_8774000(Animator, id_anim, 0);
            }
          }
          v45 = motion;
          v41 = sub_8D3950(s32, &v45);
          v27 = Format("{0:D2}", v41, 0);
          if (((*h)->Flag & 1) != 0)
            v33 = 3;
          else
            v33 |= 1u;
        }
        if (op_Inequality(Component_object, 0, 0))
        {
          if ((*h)->e723sp)
          {
            PlayFrameControl(Component_object, motion);
            (*h)->e723sp = 0;
          }
          else
          {
            Play(Component_object, v27, motion, layer, 0.0, v42, v43, 0, v33, 0);
          }
        }
        else
        {
          Play_8777152(Animator, v27, layer, 0.0);
        }
      }
    }
  }
}

// 0x19abb40
void mdlUnRegLoading(s32 aMajor, s32 aMinor) {
  struct mdlLoadingTag_t_array *mdlLoadingMajorList;
  mdlLoadingTag_t_o **p_next;
  mdlLoadingTag_t_o *v9;
  s32 minor;

  p_next = &mdlLoadingMajorList->m_Items[aMajor];
  do
  {
    v9 = *p_next;
    if (!v9)
      break;
    minor = v9->minor;
    p_next = &v9->next;
  }
  while (minor != aMinor);
}

// 0x19abc00
void mdlUnRegist(s32 aMajor, s32 aMinor) {
  struct dds3ModelResrc_t_array *mdlResrcMajorList;
  dds3ModelResrc_t_o *i;
  dds3ModelResrc_t_o *resrc_p;

  resrc_p = 0;
LABEL_7:
  for (i = mdlResrcMajorList->m_Items[aMajor]; i; i = i->next)
  {
    if (i->minor == aMinor)
      break;
  }
  resrc_p = i;
  mdlUnRegistResrc(&resrc_p, *&aMinor);
}

// 0x19ac1e0
void mdlUnRegistAll(void) {
  u64 v2;
  struct dds3ModelResrc_t_array *mdlResrcMajorList;
  u64 max_length_low;
  dds3ModelResrc_t_o *next;
  dds3ModelResrc_t_o *resrc_p;

  resrc_p = 0;
  v2 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(mdlResrcMajorList->max_length);
    if (v2 >= max_length_low)
      break;
    else if (v2 >= max_length_low)
    {
      goto LABEL_12;
    }
    next = mdlResrcMajorList->m_Items[v2];
    for (resrc_p = next; next; resrc_p = next)
    {
      next = next->next;
      mdlUnRegistResrc(&resrc_p);
    }
    ++v2;
      goto LABEL_6;
  }
}

// 0x19ac830
void mdlUnRegistMotion(s32 aMajor, s32 aMinor, s32 aGroup) {
  struct dds3ModelResrc_t_array *mdlResrcMajorList;
  dds3ModelResrc_t_o *i;
  dds3ModelResrc_t_o *aResrc;

  aResrc = 0;
LABEL_7:
  for (i = mdlResrcMajorList->m_Items[aMajor]; i; i = i->next)
  {
    if (i->minor == aMinor)
      break;
  }
  aResrc = i;
  mdlUnRegistResrcMotion(&aResrc, aGroup, *&aGroup);
}

// 0x19abe40
void mdlUnRegistResrc(dds3ModelResrc_t **resrc_p) {
  dds3ModelResrc_t_o *v3;
  s64 *next;
  struct dds3ModelResrc_t_o *prev;
  dds3ModelResrc_t_o *v6;
  dds3ModelHandle_t_o **i;
  mdlEffectResrcList_t_o *effectResrcList;
  struct dds3ModelResrc_t_array *mdlResrcMajorList;
  s64 major;

  v3 = *resrc_p;
  if (*resrc_p)
  {
    next = v3->next;
    prev = v3->prev;
    if (prev)
    {
      prev->next = next;
      if (!next)
      {
LABEL_7:
        (*resrc_p)->autoFreeFlag = 0;
        v6 = *resrc_p;
        for (i = &(*resrc_p)->models; *i; i = &(*resrc_p)->models)
        {
          mdlFree(i);
          v6 = *resrc_p;
        }
        effectResrcList = v6->effectResrcList;
        mdlEffectResrcListFree(effectResrcList);
        (*resrc_p)->effectData = 0;
        return;
      }
    }
    else
    {
      major = v3->major;
      mdlResrcMajorList->m_Items[major] = next;
      if (!next)
        goto LABEL_7;
    }
    next[3] = prev;
    goto LABEL_7;
  }
}

// 0x19ac630
void mdlUnRegistResrcMotion(dds3ModelResrc_t **aResrc, s32 aGroup) {
  struct dds3ModelResrcPlayBook_t_array *playbooks;
  dds3ModelResrc_t_o *v7;
  struct dds3ModelHandle_t_o *models;
  sdfMotionCtrlr_t_o *motion;
  struct dds3ModelResrcPlayBook_t_array *v11;
  struct dds3ModelResrcPlayBook_t_array *v13;
  dds3ModelHandle_t_o *aHandle;

  aHandle = 0;
  if (*aResrc)
  {
    playbooks = (*aResrc)->playbooks;
    if (playbooks->m_Items[aGroup]->ptr)
    {
      v7 = *aResrc;
      models = (*aResrc)->models;
      aHandle = models;
      if (models)
      {
        {
          if ((byte_3F5AC77 & 1) == 0)
            goto LABEL_19;
LABEL_20:
          motion = models->modelRoot->motion;
          if (motion)
          {
            while (motion->userId != aGroup)
            {
              motion = motion->next;
              if (!motion)
                goto LABEL_23;
            }
            mdlFreeMotionCtrlr(&aHandle, motion);
            models = models->next;
            aHandle = models;
            if (!models)
            {
LABEL_24:
              v7 = *aResrc;
              goto LABEL_25;
            }
          }
          else
          {
LABEL_23:
            models = models->next;
            aHandle = models;
            if (!models)
              goto LABEL_24;
          }
        }
        if ((byte_3F5AC77 & 1) != 0)
          goto LABEL_20;
LABEL_19:
        goto LABEL_20;
      }
LABEL_25:
      v11 = v7->playbooks;
      v11->m_Items[aGroup]->ptr = 0;
      v13 = (*aResrc)->playbooks;
      v13->m_Items[aGroup]->handle = 0;
    }
  }
}

// 0x19ad6c0
void mdlUnlinkResrc(dds3ModelHandle_t **aHandle) {
  struct dds3ModelHandle_t_o *next;
  struct dds3ModelHandle_t_o *prev;
  struct dds3ModelResrc_t_o *resrc;
  s32 autoFreeFlag;
  dds3ModelResrc_t_o *resrc_p;

  resrc_p = 0;
  next = (*aHandle)->next;
  prev = (*aHandle)->prev;
  if (next)
    next->prev = prev;
  if (prev)
  {
    prev->next = next;
  }
  else
  {
    resrc = (*aHandle)->resrc;
    resrc_p = resrc;
    if (next)
    {
      resrc->models = next;
    }
    else
    {
      autoFreeFlag = resrc->autoFreeFlag;
      resrc->models = 0;
      if (autoFreeFlag)
      {
        mdlUnRegistResrc(&resrc_p);
      }
    }
  }
}

// 0x19ac960
dds3ModelResrc_t *mdlWaitLoadEnd(s32 aMajor, s32 aMinor) {
  mdlLoadingTag_t_o *next;
  struct dds3ModelResrc_t_array *mdlResrcMajorList;
  dds3ModelResrc_t_o *result;

    goto LABEL_6;
LABEL_7:
LABEL_27:
  for (result = mdlResrcMajorList->m_Items[aMajor]; result; result = result->next)
  {
    if (result->minor == aMinor)
      break;
  }
  return result;
}
