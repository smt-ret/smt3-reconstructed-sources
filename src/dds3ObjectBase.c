#include "types.h"

typedef struct dds3BasicArrayHandle_t dds3BasicArrayHandle_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3MoverBasicObjFunc_t dds3MoverBasicObjFunc_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PathBasicControl_t dds3PathBasicControl_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct sdfModelOt_t sdfModelOt_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfMotionCtrlr_t sdfMotionCtrlr_t;

u32 DDS3_GETBASICTYPEL(dds3Basic_t *pAreaBasic);
void HojiAnimation(dds3ObjectBaseControlWorkData_t *pControl, dds3Basic_t *pObjectBasic, void *obj);
void LockAnim(void *obj);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void UnlockAnim(void *obj);
dds3Basic_t *dds3AddMoverBasic(dds3Basic_t **pObjectBasic);
void dds3AreaBasicRegistItem(dds3Basic_t **pAreaBasic, dds3Basic_t **pItemBasic);
void dds3AreaBasicReleaseItem(dds3Basic_t **pAreaBasic, dds3Basic_t **pItemBasic);
dds3ObjectBaseControlWorkData_t *dds3CameraObjectBasicGetControlWorkData(dds3Basic_t **pBasic);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3ObjectBaseControlWorkData_t *dds3EffectObjectBasicGetControlWorkData(dds3Basic_t **pBasic);
dds3ObjectBaseControlWorkData_t *dds3EventObjectBasicGetControlWorkData(dds3Basic_t **pBasic);
void dds3FreeBasicArrayHandle(dds3BasicArrayHandle_t **hndl);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
dds3BasicArrayHandle_t *dds3GetBasicArrayHandle(s32 bufcnt);
void dds3GetPosPoseSetMCR(dds3Basic_t **pBasic);
void dds3GetRotPoseSetMCR(dds3Basic_t **pBasic);
void dds3GetTMPoseSet(dds3Basic_t **pBasic);
dds3ObjectBaseControlWorkData_t *dds3LightObjectBasicGetControlWorkData(dds3Basic_t **basic);
dds3ObjectBaseControlWorkData_t *dds3MatterObjectBasicGetControlWorkData(dds3Basic_t **pBasic);
sdfMotionCtrlr_t *dds3ModelBasicMakeMotion(dds3Basic_t **pBasic, sdfModelRootNode_t *pRootNode);
sdfModelRootNode_t *dds3ModelBasicMakeRootNode(dds3Basic_t **pBasic);
void dds3MoverBasicFreePath(dds3Basic_t **pMoverBasic);
dds3PathBasicControl_t *dds3MoverBasicGetPathControl(dds3Basic_t **pMoverBasic);
void dds3MoverBasicMakePath(dds3Basic_t **pMoverBasic);
void dds3MoverBasicSetCallBackPrimaryControl(dds3Basic_t **mover, dds3MoverBasicObjFunc_t *func);
void dds3MoverBasicSetPath(dds3Basic_t **pMoverBasic, dds3Basic_t **pPathBasic);
void dds3ObjectBaseControlWorkData_t__Clear(dds3ObjectBaseControlWorkData_t *this);
void dds3ObjectBaseFreeModelHandle(dds3Basic_t **pObjectBasic);
dds3Basic_t *dds3ObjectBaseSetControlBasic(dds3Basic_t **pObjectBasic, dds3Basic_t **pItemBasic);
dds3Basic_t *dds3ObjectBaseSetControlBasicType(dds3Basic_t **pObjectBasic, dds3Basic_t **pItemBasic, u32 itemType);
s32 dds3ObjectBaseSetPrimaryControl(dds3Basic_t **basic, dds3MoverBasicObjFunc_t *func);
void dds3SetSclPoseSet(dds3Basic_t **pBasic, sdfVector4_t scl);
dds3ObjectBaseControlWorkData_t *dds3UnitObjectBasicGetControlWorkData(dds3Basic_t **pBasic);
bool evtBitCheck(s32 no);
evtUnitHandle_t *evtCreateUnitHandle(dds3Basic_t **owner, dds3ModelHandle_t *model);
s32 evtDeleteUnitHandle(evtUnitHandle_t **h);
s32 fldGbChkAnime(s32 fld, s32 area, s32 blk);
void hoji_animationset(dds3ObjectBaseControlWorkData_t *pControl, dds3Basic_t *pObjectBasic);
void mdlFreeSub(void **pData);
void mdlLinkSub(dds3ModelHandle_t **aHandle, sdfModelOt_t **aModelOt, void *modelobj, bool camera_identity);
dds3ModelHandle_t *mdlLoad(s32 aMajor, s32 aMinor, u8 **byteData, s32 bPos);

// 0x14ee510
u32 BasicTypeToItemType(u32 type) {
  if (type - 2 > 0xB)
    return 0;
  else
    return dword_33CCE8C[type - 2];
}

// 0x14f50d0
void HojiAnimation(dds3ObjectBaseControlWorkData_t *pControl, dds3Basic_t *pObjectBasic, void *obj) {
  struct fldGlobalWork_t_o *fldGb;
  f32 MotSpeed;
  u32 fieldID;
  s32 areaID;
  bool v12;
  bool v13;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *parent;
  UnityEngine_GUILayer_o *Component_GUILayer;

  if (!op_Equality(obj, 0, 0))
  {
    MotSpeed = pControl->MotSpeed;
    fieldID = fldGb->fieldID;
    areaID = fldGb->areaID;
    v12 = fieldID == 20 && areaID == 4;
    if (v12
      || (fieldID <= 0x23 ? (v13 = ((1LL << fieldID) & 0xC80000000LL) == 0) : (v13 = 1), !v13 || fieldID - 38 <= 7))
    {
      transform = get_transform(obj, 0);
      parent = get_parent(transform);
      Component_GUILayer = GetComponent_GUILayer_(parent);
      if (!op_Equality(Component_GUILayer, 0, 0))
        set_animator(Component_GUILayer, obj, MotSpeed, pControl->MotMode, 1);
    }
  }
}

// 0x14ee740
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic) {
  dds3Basic_t_o *v3;
  dds3ObjectBaseControlWorkData_t_o *result;

  v3 = *pObjectBasic;
  switch (DDS3_GETBASICTYPEL(v3))
  {
    case 4u:
      result = dds3CameraObjectBasicGetControlWorkData(pObjectBasic);
      break;
    case 5u:
      result = dds3UnitObjectBasicGetControlWorkData(pObjectBasic);
      break;
    case 6u:
      result = dds3MatterObjectBasicGetControlWorkData(pObjectBasic);
      break;
    case 7u:
      result = dds3EffectObjectBasicGetControlWorkData(pObjectBasic);
      break;
    case 8u:
      result = dds3EventObjectBasicGetControlWorkData(pObjectBasic);
      break;
    case 9u:
      result = dds3LightObjectBasicGetControlWorkData(pObjectBasic);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// 0x14ea410
s32 dds3ObjectBaseCheckFlag(dds3Basic_t **pObjectBasic, u32 flag) {
  return (dds3GetBaseControlWorkData(pObjectBasic, *&flag)->flag & flag) != 0;
}

// 0x14e5f90
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic) {
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  struct dds3Basic_t_array *pBasic;
  dds3Basic_t_o *pItemBasic;

  pItemBasic = 0;
  if (!*pObjectBasic)
  BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic);
  if (!BaseControlWorkData)
  pBasic = BaseControlWorkData->pBasic;
  if (!pBasic->m_Items[1])
  {
    pItemBasic = dds3AddMoverBasic(pObjectBasic);
    dds3ObjectBaseSetControlBasic(pObjectBasic, &pItemBasic);
  }
}

// 0x14e5740
void dds3ObjectBaseFreeControlWorkData(dds3ObjectBaseControlWorkData_t **pControl) {
  struct dds3Basic_t_array *pBasic;
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  struct dds3Basic_t_array *v5;
  u64 v8;
  s64 v9;
  struct dds3Basic_t_array *v10;
  struct dds3Basic_t_array *v12;
  dds3BasicArrayHandle_t_o **p_hEventBasicArray;
  dds3Basic_t_o *pObjectBasic;
  dds3Basic_t_o *pAreaBasic;

  pAreaBasic = 0;
  pObjectBasic = 0;
  pBasic = (*pControl)->pBasic;
  pObjectBasic = pBasic->m_Items[0];
  if (pObjectBasic && (BaseControlWorkData = dds3GetBaseControlWorkData(&pObjectBasic)) != 0)
  {
    v5 = BaseControlWorkData->pBasic;
    pAreaBasic = v5->m_Items[5];
    if (pAreaBasic)
      dds3AreaBasicReleaseItem(&pAreaBasic, &pObjectBasic);
  }
  else
  {
    pAreaBasic = 0;
  }
  v8 = 0;
  v9 = 32;
  do
  {
    if ((v8 - 1) <= 1)
    {
      v10 = (*pControl)->pBasic;
      if (v10->m_Items[v8])
      {
        v12 = (*pControl)->pBasic;
        else        dds3DeleteSceneBasicData((v12 + v9));
      }
    }
    ++v8;
    v9 += 8;
  }
  while (v8 != 8);
  dds3ObjectBaseFreeModelHandle(&pObjectBasic);
  p_hEventBasicArray = &(*pControl)->hEventBasicArray;
  dds3FreeBasicArrayHandle(p_hEventBasicArray);
}

// 0x14ee5c0
void dds3ObjectBaseFreeModelHandle(dds3Basic_t **pObjectBasic) {
    dds3GetBaseControlWorkData(0);
    mdlFreeSub(0);
    evtDeleteUnitHandle(0);
}

// 0x14f5420
void dds3ObjectBaseFreePath(dds3Basic_t **pObjectBasic) {
  dds3Basic_t_o *v3;
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  struct dds3Basic_t_array *pBasic;
  dds3Basic_t_o *pMoverBasic;

  pMoverBasic = 0;
  v3 = *pObjectBasic;
  if (*pObjectBasic)
  {
    BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic);
    if (BaseControlWorkData)
    {
      pBasic = BaseControlWorkData->pBasic;
      v3 = pBasic->m_Items[1];
    }
    else
    {
      v3 = 0;
    }
  }
  pMoverBasic = v3;
  dds3MoverBasicFreePath(&pMoverBasic);
}

// 0x14ee540
dds3Basic_t *dds3ObjectBaseGetControlBasic(dds3Basic_t **pObjectBasic, u32 itemType) {
  dds3Basic_t_o *result;
  Il2CppObject *staticdata;

  if (!*pObjectBasic)
    return 0;
  result = dds3GetBaseControlWorkData(pObjectBasic, *&itemType);
  if (result)
  {
    staticdata = result->staticdata;
    return *(&staticdata[2].klass + itemType);
  }
  return result;
}

// 0x14eeaa0
dds3BasicArrayHandle_t *dds3ObjectBaseGetEventArray(dds3Basic_t **pObjectBasic) {
  return dds3GetBaseControlWorkData(pObjectBasic)->hEventBasicArray;
}

// 0x14e9f50
void *dds3ObjectBaseGetModelHandle(dds3Basic_t **pObjectBasic) {
  return dds3GetBaseControlWorkData(pObjectBasic)->pModel;
}

// 0x14f54e0
dds3PathBasicControl_t *dds3ObjectBaseGetPathControl(dds3Basic_t **pObjectBasic) {
  dds3Basic_t_o *v3;
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  struct dds3Basic_t_array *pBasic;
  dds3Basic_t_o *pMoverBasic;

  pMoverBasic = 0;
  v3 = *pObjectBasic;
  if (*pObjectBasic)
  {
    BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic);
    if (BaseControlWorkData)
    {
      pBasic = BaseControlWorkData->pBasic;
      v3 = pBasic->m_Items[1];
    }
    else
    {
      v3 = 0;
    }
  }
  pMoverBasic = v3;
  return dds3MoverBasicGetPathControl(&pMoverBasic);
}

// 0x14ee9c0
void *dds3ObjectBaseGetUserValue(dds3Basic_t **pObjectBasic) {
  return dds3GetBaseControlWorkData(pObjectBasic)->pUserValue;
}

// 0x14e53b0
dds3ObjectBaseControlWorkData_t *dds3ObjectBaseInitControlWorkData(dds3Basic_t **pObjectBasic) {
  dds3ObjectBaseControlWorkData_t_o *v3;
  struct dds3Basic_t_array *pBasic;
  s64 *v6;
  u64 v8;
  struct System_Int32_array *sdwnodeidx;
  char *v11;

  v3 = Allocate(dds3ObjectBaseControlWorkData_t);
  dds3ObjectBaseControlWorkData_t___ctor(v3);
  dds3ObjectBaseControlWorkData_t__Clear(v3);
  v3->modelType = 3;
  v3->hEventBasicArray = dds3GetBasicArrayHandle(0);
  pBasic = v3->pBasic;
  v6 = *pObjectBasic;
  v8 = 0;
  pBasic->m_Items[0] = v6;
  do
  {
    sdwnodeidx = v3->sdwnodeidx;
    v11 = sdwnodeidx + 4 * v8++;
    *(v11 + 8) = -1;
  }
  while (v8 != 24);
  return v3;
}

// 0x14f4c30
void dds3ObjectBaseMakeMatter(dds3Basic_t **pObjectBasic) {
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  dds3Basic_t_o *v5;
  dds3ObjectBaseControlWorkData_t_o *v6;
  dds3ObjectBaseControlWorkData_t_o *v7;
  struct dds3Basic_t_array *v8;
  sdfModelRootNode_t_o *RootNode;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic);
  v5 = *pObjectBasic;
  v6 = BaseControlWorkData;
  if (*pObjectBasic)
  {
    v7 = dds3GetBaseControlWorkData(pObjectBasic);
    if (v7)
    {
      v8 = v7->pBasic;
      v5 = v8->m_Items[3];
    }
    else
    {
      v5 = 0;
    }
  }
  pBasic = v5;
  RootNode = dds3ModelBasicMakeRootNode(&pBasic);
  dds3ModelBasicMakeMotion(&pBasic, RootNode);
  dds3GetTMPoseSet(pObjectBasic);
  SDF_VU0__STOREMATRIX(&RootNode->tm);
  v6->pModel = RootNode;
  v6->modelType = 1;
  v6->pMot = 0;
  *&v6->MotMode = 0x3F80000000000000LL;
  v6->svs = 0;
}

// 0x14f5350
void dds3ObjectBaseMakePath(dds3Basic_t **pObjectBasic, dds3Basic_t **pPathBasic) {
  dds3Basic_t_o *v5;
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  struct dds3Basic_t_array *pBasic;
  dds3Basic_t_o *pMoverBasic;

  pMoverBasic = 0;
  v5 = *pObjectBasic;
  if (*pObjectBasic)
  {
    BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic, pPathBasic);
    if (BaseControlWorkData)
    {
      pBasic = BaseControlWorkData->pBasic;
      v5 = pBasic->m_Items[1];
    }
    else
    {
      v5 = 0;
    }
  }
  pMoverBasic = v5;
  dds3MoverBasicSetPath(&pMoverBasic, pPathBasic);
  dds3MoverBasicMakePath(pObjectBasic);
}

// 0x14eeac0
void dds3ObjectBaseMakeUnit(dds3Basic_t **pObjectBasic, s32 major, s32 minor) {
    dds3GetBaseControlWorkData(0);
    mdlFreeSub(0);
    mdlLoad(0, 0, 0, 0);
    SDF_VU0__STOREVECTOR(0);
    dds3SetSclPoseSet(0, (sdfVector4_t){0});
    dds3GetRotPoseSetMCR(0);
    dds3GetPosPoseSetMCR(0);
    evtCreateUnitHandle(0, 0);
}

// 0x14f4d40
void dds3ObjectBaseMatterAnimeSpeed(dds3Basic_t **pObjectBasic, s32 mode) {
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  f32 v5;

  BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic, *&mode);
  if (mode <= 7)
  {
    v5 = flt_32C2134[mode];
    BaseControlWorkData->MotMode = mode;
    BaseControlWorkData->MotSpeed = v5;
  }
}

// 0x14ea200
void dds3ObjectBaseModelLinkOt(sdfModelOt_t *pModelOt, dds3Basic_t **pObjectBasic) {
    dds3GetBaseControlWorkData(0);
    hoji_animationset(0, 0);
    mdlLinkSub(0, 0, 0, 0);
}

// 0x14f4e30
void dds3ObjectBaseModelLinkOtSvs(sdfModelOt_t *pModelOt, dds3Basic_t **pObjectBasic) {
  dds3GetBaseControlWorkData(pObjectBasic, pObjectBasic);
  evtBitCheck(2800);
}

// 0x14ee870
void dds3ObjectBaseOffFlag(dds3Basic_t **pObjectBasic, u32 flag) {
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  UnityEngine_Object_o *gameObject;
  UnityEngine_GameObject_o *v9;

  BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic, *&flag);
  if (flag == 1)
  {
    gameObject = (*pObjectBasic)->gameObject;
    if (op_Inequality(gameObject, 0, 0)
      && !get_activeSelf((*pObjectBasic)->gameObject, 0))
    {
      SetActive((*pObjectBasic)->gameObject, 1, 0);
      v9 = (*pObjectBasic)->gameObject;
      UnlockAnim(v9);
    }
  }
  BaseControlWorkData->flag &= ~flag;
}

// 0x14e54f0
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock) {
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  UnityEngine_Object_o *gameObject;
  UnityEngine_GameObject_o *v11;

  BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic, *&flag);
  if (flag == 1)
  {
    gameObject = (*pObjectBasic)->gameObject;
    if (op_Inequality(gameObject, 0, 0)
      && get_activeSelf((*pObjectBasic)->gameObject, 0))
    {
      if (alock)
      {
        v11 = (*pObjectBasic)->gameObject;
        LockAnim(v11);
      }
      SetActive((*pObjectBasic)->gameObject, 0, 0);
    }
  }
  BaseControlWorkData->flag |= flag;
}

// 0x14f4d80
s32 dds3ObjectBaseRegistArea(dds3Basic_t **pObjectBasic) {
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  struct dds3Basic_t_array *pBasic;
  dds3Basic_t_o *pAreaBasic;

  pAreaBasic = 0;
  if (*pObjectBasic && (BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic)) != 0)
  {
    pBasic = BaseControlWorkData->pBasic;
    pAreaBasic = pBasic->m_Items[5];
    if (pAreaBasic)
    {
      dds3AreaBasicRegistItem(&pAreaBasic, pObjectBasic);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    pAreaBasic = 0;
    return 0;
  }
}

// 0x14ee9e0
dds3Basic_t *dds3ObjectBaseSetControlBasic(dds3Basic_t **pObjectBasic, dds3Basic_t **pItemBasic) {
  dds3Basic_t_o *v5;
  u32 v7;
  u32 v8;

  v5 = *pItemBasic;
  if (!*pItemBasic)
    return 0;
  v7 = DDS3_GETBASICTYPEL(v5) - 2;
  if (v7 > 0xB)
    v8 = 0;
  else
    v8 = dword_33CCE8C[v7];
  return dds3ObjectBaseSetControlBasicType(pObjectBasic, pItemBasic, v8);
}

// 0x14f55a0
void dds3ObjectBaseSetControlBasicSvs(dds3Basic_t **pObjectBasic, s32 svs) {
  dds3GetBaseControlWorkData(pObjectBasic, *&svs)->svs = svs;
}

// 0x14ebce0
dds3Basic_t *dds3ObjectBaseSetControlBasicType(dds3Basic_t **pObjectBasic, dds3Basic_t **pItemBasic, u32 itemType) {
  dds3ObjectBaseControlWorkData_t_o *v7;
  struct dds3Basic_t_array *pBasic;
  dds3Basic_t_o *v10;
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  struct dds3Basic_t_array *v12;
  s64 *v13;

  if (*pObjectBasic && (v7 = dds3GetBaseControlWorkData(pObjectBasic, pItemBasic)) != 0)
  {
    pBasic = v7->pBasic;
    v10 = pBasic->m_Items[itemType];
    BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic, pItemBasic);
    if (!BaseControlWorkData)
      return 0;
  }
  else
  {
    v10 = 0;
    BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic, pItemBasic);
    if (!BaseControlWorkData)
      return 0;
  }
  v12 = BaseControlWorkData->pBasic;
  v13 = *pItemBasic;
  v12->m_Items[itemType] = v13;
  return v10;
}

// 0x14f5250
s32 dds3ObjectBaseSetPadControl(dds3Basic_t **pObjectBasic, dds3MoverBasicObjFunc_t *pFuncPadControl) {
  return dds3ObjectBaseSetPrimaryControl(pObjectBasic, pFuncPadControl);
}

// 0x14f5260
s32 dds3ObjectBaseSetPrimaryControl(dds3Basic_t **basic, dds3MoverBasicObjFunc_t *func) {
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  struct dds3Basic_t_array *pBasic;
  dds3Basic_t_o *mover;

  mover = 0;
  if (*basic && (BaseControlWorkData = dds3GetBaseControlWorkData(basic, func)) != 0)
  {
    pBasic = BaseControlWorkData->pBasic;
    mover = pBasic->m_Items[1];
    if (mover)
    {
      dds3MoverBasicSetCallBackPrimaryControl(&mover, func);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    mover = 0;
    return 0;
  }
}

// 0x14ee980
void *dds3ObjectBaseSetUserValue(dds3Basic_t **pObjectBasic, void *pUserValue) {
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  Il2CppObject *result;

  BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic, pUserValue);
  result = dds3GetBaseControlWorkData(pObjectBasic)->pUserValue;
  BaseControlWorkData->pUserValue = pUserValue;
  return result;
}

// 0x14f4e50
void hoji_animationset(dds3ObjectBaseControlWorkData_t *pControl, dds3Basic_t *pObjectBasic) {
    fldGbChkAnime(0, 0, 0);
    HojiAnimation(0, 0, 0);
}
