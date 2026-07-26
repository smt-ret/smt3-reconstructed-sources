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
static dds3ModelFileTableDef_t modelFileTable[UNKNOWN_ARRAY_SIZE];
static dds3ModelResrc_t *mdlResrcMajorList[8];
static mdlLoadingTag_t *mdlLoadingMajorList[8];
static s32 mdlDbSemaId;
static char *mdlSetFileName_work_dir;
static mdlManager_mdlFileItem_tag *mdlHddFileListHead;
static sdfMemHandle_t *mdlHddFileIndexHandle;
static dds3ModelFileIndex_t mdlHddFileIndex[UNKNOWN_ARRAY_SIZE];
static sdfMemHandle_t *mdlHddFileTableHandle;
static dds3ModelFileTable_t mdlHddFileTable[UNKNOWN_ARRAY_SIZE];
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
      if (op_Equality(name, StringLiteral_15283, 0))
        v9 = (fhdobj->klass->vtable._6_GetGameObjectByName.methodPtr)(
               fhdobj,
               StringLiteral_19046,
               fhdobj->klass->vtable._6_GetGameObjectByName.method);
      v10 = get_name(obj);
      if (op_Equality(v10, StringLiteral_15390, 0))
        v9 = (fhdobj->klass->vtable._6_GetGameObjectByName.methodPtr)(
               fhdobj,
               StringLiteral_19047,
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
  monitor = Component_object[2].monitor;
  if (!op_Inequality(monitor, 0, 0))
  {
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
    return 0;
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
  v10 = Equals_5239888(v9, StringLiteral_19044, 5);
  result = 0;
  if (!v10)
    return ~Equals_5239888(v9, StringLiteral_19045, 5) << 31 >> 31;
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
    GetAnimator(0);
    ResetFlag(0, 0, 0);
    Play(0, 0, 0);
}

// 0x19b2c70
void mdlEffectCreatePipeForUnity(s32 aMajor, s32 aMinor, mdlEffectResrcList_t **efc_res_list) {
    LoadFileObject(0, 0, 0);
    LoadFileByte(0, 0, 0);
    mdlCreateEffectResrc_D3P(0, 0, 0);
}

// 0x19ae5a0
void mdlEffectCreateUnity(s32 aMajor, s32 aMinor, mdlEffectResrcList_t **efc_res_list, bool loadf) {
    GetAkey(0);
    LoadFileObject(0, 0, 0);
    LoadFileByte(0, 0, 0);
    mdlCreateEffectResrc_D3P(0, 0, 0);
    billAlfRaitoSet(0);
    billCutRaitoSet(0);
    fpCutRaitoSet(0);
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
    mdlPackSet(0, 0, 0, 0);
    pacFileHandleFree(0);
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
    }
    mdlFreeEffect(v7);
  }
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
    mdlFreeEffect(0);
}

// 0x19b4f30
u32 mdlGetColor(dds3ModelHandle_t **aHandle) {
  dds3ModelHandle_t_o *v3;

  v3 = *aHandle;
  if (!v3)
    return 0;
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

  motion = (*aHandle)->modelRoot->motion;
  if (!motion)
    return 0;
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
    GetAnimator(0);
    return 0;
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
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
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
  dds3KernelDraw_c *v8;
  struct dds3KernelDraw_StaticFields *static_fields;
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
  static_fields = v8->static_fields;
  v10 = *&static_fields->dds3CameraTM.m00;
  v11 = *&static_fields->dds3CameraTM.m20;
  v12 = *&static_fields->dds3CameraTM.m21;
  *&v37.m01 = *&static_fields->dds3CameraTM.m01;
  *&v37.m21 = v12;
  *&v37.m00 = v10;
  *&v37.m20 = v11;
  v13 = *&static_fields->dds3CameraTM.m02;
  v14 = *&static_fields->dds3CameraTM.m22;
  v16 = *&static_fields->dds3CameraTM.m03;
  v15 = *&static_fields->dds3CameraTM.m23;
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
      while (1)
      {
        v9 = *(instants + 8);
        gameObject = *(instants + 3);
        keepCount = v9 - 1;
        if (v9 == 1)
          break;
        *(instants + 8) = keepCount;
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
    }
  }
  instants = blur->instants;
  if (instants)
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
    for (aEffect = v19->effects; aEffect; aEffect = aEffect->next)
    {
      mdlLinkEffectOff(aHandle, &aEffect, 0);
    }
  }
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
  if (aMajor == 7)
  {
    v9->modelRoot = sdfModelMakeUnity(0, byteData, bPos);
    v9->resrc->effectData = GetPibArray(byteData, bPos);
  }
  if (aMajor != 6)
  {
    if (aMajor != 2 || aMinor != 15 && aMinor != 33)
    PBname = GetPBname(aMinor);
    v32 = Concat_5221536(StringLiteral_4874, PBname, StringLiteral_4739);
    bData = 0;
    if (aMinor == 33)
    {
      v33 = &StringLiteral_19041;
    }
    else
    {
      if (aMinor != 15)
      v33 = &StringLiteral_19040;
    }
    v32 = *v33;
    sdfDevLoadFileUnity_25061072(v32, &bData, 0, StringLiteral_19042);
    v35 = aHandle;
    v36 = bData;
    v35->modelRoot = sdfModelMakeUnity(0, v36, bPos);
    v39 = aHandle;
    aHandle->resrc->effectData = &bData->obj;
    effectResrcList = v39->resrc->effectResrcList;
    mdlEffectCreatePipeForUnity(2, aMinor, &effectResrcList);
    v28 = aHandle->resrc;
    v29 = effectResrcList;
  }
  if (aMinor == 336)
  {
    v19 = convDLCDevilNumber(aMinor);
    Akey = GetAkey(v19);
    v21 = GetPBname(v19);
    v22 = Concat_5221536(StringLiteral_4874, v21, StringLiteral_4739);
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
    v28->effectResrcList = v29;
  }
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
    }
    userId2 = motion->userId2;
    motions = (*aHandle)->motions;
    LOWORD(v18) = motion->userId2;
  }
  v14 = mdlCreateMotion(aHandle, aGroup, *&aNumber);
  userId2 = v14->userId2;
  motion = v14;
  motions = (*aHandle)->motions;
  LOWORD(v18) = v14->userId2;
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
    sdfPacFreeResrc(0);
    mdlRegistModelSet(0, 0, 0, 0);
    return 0;
}

// 0x19b5cc0
sdfPacDecodeResrc_t *mdlPackSetOld(sdfPacDecodeResrc_t **resrc, s32 major, s32 minor, u32 regFlags) {
  return *resrc;
}

// 0x19acf20
dds3ModelResrc_t *mdlPrepare(s32 aMajor, s32 aMinor, s32 aBlockMode) {
    mdlWaitLoadEnd(0, 0);
    StrRChr(0, 0);
    mdlRegLoading(0, 0);
    mdlFileLoad(0, 0, 0, 0, 0, 0);
    return 0;
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
  }
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
    mdlRegist(0, 0, 0, 0, 0, 0);
    mdlRegistMotion(0, 0, 0, 0, 0, 0, 0, 0);
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
    SDF_VU0__dds3ColorItoF(0);
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__SUBVECTOR();
    SDF_VU0__SCALEVECTOR(0);
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
    mdlPibGetMotionCount(0, 0);
    SetsdfMotionPlayBook(0, 0);
}

// 0x19b4810
void mdlSetMotionSpeed(dds3ModelHandle_t **aHandle, f32 speed) {
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
      set_keepAnimatorControllerStateOnDisable(mAnimator, 0);
      return;
    }
    set_speed(mAnimator, speed);
    if (speed != 0.0)
  }
}

// 0x19b4910
void mdlSetMotionSpeedEx(dds3ModelHandle_t **aHandle, s32 aGroup, f32 speed) {
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
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__STOREVECTOR(0);
}

// 0x19b4d20
void mdlSetRotate(dds3ModelHandle_t **aHandle) {
    SDF_VU0__STOREVECTOR(0);
    ToMatrix();
    SDF_VU0__STORE_ROW0(0);
    SDF_VU0__STORE_ROW1(0);
    SDF_VU0__STORE_ROW2(0);
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
      if (Contains(name, StringLiteral_4811, 0)
        || (v6 = get_name(gameObject), Contains(v6, StringLiteral_4812, 0)))
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
    GetAnimator(0);
    ResetFlag(0, 0, 0);
    is_devil(0);
    is_eventdevil(0);
    fldProcCheckFlag(0);
    PlayFrameControl(0, 0);
    Play(0, 0, 0);
}

// 0x19b3d10
void mdlSmoothSingleMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, f32 aBeforeLeng, f32 aSmoothLeng) {
  mdlMotion(aHandle, aGroup, aNumber, 0, aBeforeLeng, aSmoothLeng);
}

// 0x19b7620
void mdlSmoothSingleMotionForUnity(evtUnitHandle_t **h, s32 layer, s32 motion, s32 before, s32 wait, bool btl) {
    GetAnimator(0);
    ResetFlag(0, 0, 0);
    is_devil(0);
    fldProcCheckFlag(0);
    PlayFrameControl(0, 0);
    Play(0, 0, 0);
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
    mdlUnRegistResrc(0);
}

// 0x19ac830
void mdlUnRegistMotion(s32 aMajor, s32 aMinor, s32 aGroup) {
  struct dds3ModelResrc_t_array *mdlResrcMajorList;
  dds3ModelResrc_t_o *i;
  dds3ModelResrc_t_o *aResrc;

  aResrc = 0;
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
    }
    next[3] = prev;
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
          motion = models->modelRoot->motion;
          if (motion)
          {
            while (motion->userId != aGroup)
            {
              motion = motion->next;
              if (!motion)
            }
            mdlFreeMotionCtrlr(&aHandle, motion);
            models = models->next;
            aHandle = models;
            if (!models)
            {
              v7 = *aResrc;
            }
          }
          else
          {
            models = models->next;
            aHandle = models;
            if (!models)
          }
        }
        if ((byte_3F5AC77 & 1) != 0)
      }
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

  for (result = mdlResrcMajorList->m_Items[aMajor]; result; result = result->next)
  {
    if (result->minor == aMinor)
      break;
  }
  return result;
}
