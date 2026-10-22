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
    goto LABEL_9;
  BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic);
  if (!BaseControlWorkData)
    goto LABEL_9;
  pBasic = BaseControlWorkData->pBasic;
  if (!pBasic->m_Items[1])
  {
LABEL_9:
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
        else if (v8 >= LODWORD(v12->max_length))
        {
LABEL_22:
        }
        dds3DeleteSceneBasicData((v12 + v9));
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
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  Il2CppObject **p_pModel;
  dds3ObjectBaseControlWorkData_t_o *v6;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  evtUnitHandle_t_o **v10;
  Il2CppClass *v11;
  char *v12;
  s64 *v13;
  u64 v14[3];

  BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic);
  p_pModel = &BaseControlWorkData->pModel;
  if (BaseControlWorkData->pModel)
  {
    v6 = BaseControlWorkData;
    if (!BaseControlWorkData->modelType)
    {
      mdlFreeSub(p_pModel);
      workdata = (*pObjectBasic)->workdata;
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v14);
        if ((v14[0] & 1) != 0)
          v12 = v14[2];
        else
          v12 = v14 + 1;
        v13 = sub_8C4940(v12);
      }
      v11 = workdata[2].klass;
      v10 = &workdata[2];
      if (v11)
      {
        evtDeleteUnitHandle(v10);
        *v10 = 0;
      }
    }
    v6->modelType = 3;
    v6->pModel = 0;
  }
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
  u64 *v7;
  dds3ModelHandle_t_o *v10;
  u64 *v11;
  u64 *v46;
  u64 *v65;
  u64 *v84;
  u64 *v119;
  u64 *v138;
  u64 *v173;
  u64 *v193;
  u64 *v228;
  u64 *v248;
  u64 *v267;
  u64 *v302;
  u64 *v337;
  Il2CppObject *v356;
  struct sdfModelNodeList_t_o *nodeList;
  s32 count;
  s32 v369;
  s32 v370;
  u64 *v372;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v517;
  s64 *v518;
  s32 v519;
  s32 v520;
  u64 *v521;
  u64 *v522;
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  dds3Basic_t_o **pBasic;
  dds3ModelHandle_t_o *model;
  UnityEngine_Vector4_o p;
  u64 v527[3];
  UnityEngine_Vector4_o v528;

  *&p.x = 0;
  *&p.z = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  v7 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v7);
  BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic);
  if (BaseControlWorkData->pModel)
  {
    mdlFreeSub(&BaseControlWorkData->pModel);
  }
  v519 = minor;
  v10 = mdlLoad(major, minor, 0, 0, 0);
  v11 = NewSpecific(string, 0x12u);
  v11[4] = "hijri";
  v11[5] = "Bip ÒÅ1";
  v11[6] = "Bip ÒÅ3";
  v11[7] = "Bip ÒÅ4";
  v11[8] = "Bip ñ";
  v11[9] = "Bip Head";
  v11[10] = "Bip L Thigh";
  v11[11] = "Bip L Calf";
  v11[12] = "Bip L Foot";
  v11[13] = "Bip R Thigh";
  v11[14] = "Bip R Calf";
  v11[15] = "Bip R Foot";
  v11[16] = "Bip L UpperArm";
  v11[17] = "Bip L Forearm";
  v11[18] = "Bip L Hand";
  v11[19] = "Bip R UpperArm";
  v11[20] = "Bip R Forearm";
  pBasic = pObjectBasic;
  v11[21] = "Bip R Hand";
  v46 = NewSpecific(string, 0x12u);
  v46[4] = "hij_b";
  v46[5] = "hij ÒÅ1";
  v46[6] = "hij ÒÅ3";
  v46[7] = "hij ÒÅ4";
  v46[8] = "hij ñ";
  v46[9] = "hij Head";
  v46[10] = "hij L Thigh";
  v46[11] = "hij L Calf";
  v46[12] = "hij L Foot";
  v46[13] = "hij R Thigh";
  v46[14] = "hij R Calf";
  v46[15] = "hij R Foot";
  v46[16] = "hij L UpperArm";
  v46[17] = "hij L Forearm";
  v46[18] = "hij L Hand";
  v46[19] = "hij R UpperArm";
  v46[20] = "hij R Forearm";
  v46[21] = "hij R Hand";
  v65 = NewSpecific(string, 0x12u);
  v65[4] = "player_b";
  v65[5] = "p_b";
  v65[6] = "p_b ÒÅ1";
  v65[7] = "p_b ÒÅ2";
  v65[8] = "p_b ñ";
  v65[9] = "p_b Head";
  v65[10] = "p_b L Thigh";
  v65[11] = "p_b L Calf";
  v65[12] = "p_b L Foot";
  v65[13] = "p_b R Thigh";
  v65[14] = "p_b R Calf";
  v65[15] = "p_b R Foot";
  v65[16] = "p_b L UpperArm";
  v65[17] = "p_b L Forearm";
  v65[18] = "p_b L Hand";
  v65[19] = "p_b R UpperArm";
  v65[20] = "p_b R Forearm";
  v65[21] = "p_b R Hand";
  v84 = NewSpecific(string, 0x12u);
  v84[4] = "tiaki";
  v84[5] = "Bip ÒÅ1";
  v84[6] = "Bip ÒÅ3";
  v84[7] = "Bip ÒÅ4";
  v84[8] = "Bip ñ";
  v84[9] = "Bip Head";
  v84[10] = "Bip L Thigh";
  v84[11] = "Bip L Calf";
  v84[12] = "Bip L Foot";
  v84[13] = "Bip R Thigh";
  v84[14] = "Bip R Calf";
  v84[15] = "Bip R Foot";
  v84[16] = "Bip L UpperArm";
  v84[17] = "Bip L Forearm";
  v84[18] = "Bip L Hand";
  v84[19] = "Bip R UpperArm";
  v84[20] = "Bip R Forearm";
  v84[21] = "Bip R Hand";
  v119 = NewSpecific(string, 0x12u);
  v119[4] = "yuuko";
  v119[5] = "yuuko_bip ÒÅ1";
  v119[6] = "yuuko_bip ÒÅ3";
  v119[7] = "yuuko_bip ÒÅ4";
  v119[8] = "yuuko_bip ñ";
  v119[9] = "yuuko_bip Head";
  v119[10] = "yuuko_bip L Thigh";
  v119[11] = "yuuko_bip L Calf";
  v119[12] = "yuuko_bip L Foot";
  v119[13] = "yuuko_bip R Thigh";
  v119[14] = "yuuko_bip R Calf";
  v119[15] = "yuuko_bip R Foot";
  v119[16] = "yuuko_bip L UpperArm";
  v119[17] = "yuuko_bip L Forearm";
  v119[18] = "yuuko_bip L Hand";
  v119[19] = "yuuko_bip R UpperArm";
  v119[20] = "yuuko_bip R Forearm";
  v119[21] = "yuuko_bip R Hand";
  v138 = NewSpecific(string, 0x12u);
  v138[4] = "isamu";
  v138[5] = "Bip ÒÅ1";
  v138[6] = "Bip ÒÅ3";
  v138[7] = "Bip ÒÅ4";
  v138[8] = "Bip ñ";
  v138[9] = "Bip Head";
  v138[10] = "Bip L Thigh";
  v138[11] = "Bip L Calf";
  v138[12] = "Bip L Foot";
  v138[13] = "Bip R Thigh";
  v138[14] = "Bip R Calf";
  v138[15] = "Bip R Foot";
  v138[16] = "Bip L UpperArm";
  v138[17] = "Bip L Forearm";
  v138[18] = "Bip L Hand";
  v138[19] = "Bip R UpperArm";
  v138[20] = "Bip R Forearm";
  v521 = v65;
  v138[21] = "Bip R Hand";
  v173 = NewSpecific(string, 0x12u);
  v173[4] = "isamu_f";
  v173[5] = "isam_f_b";
  v173[6] = "isam_f_ ÒÅ3";
  v173[7] = "isam_f_ ÒÅ4";
  v173[8] = "isam_f_ ñ";
  v173[9] = "isam_f_ Head";
  v173[10] = "isam_f_ L Thigh";
  v173[11] = "isam_f_ L Calf";
  v173[12] = "isam_f_ L Foot";
  v173[13] = "isam_f_ R Thigh";
  v173[14] = "isam_f_ R Calf";
  v173[15] = "isam_f_ R Foot";
  v173[16] = "isam_f_ L UpperArm";
  v173[17] = "isam_f_ L Forearm";
  v173[18] = "isam_f_ L Hand";
  v173[19] = "isam_f_ R UpperArm";
  v173[20] = "isam_f_ R Forearm";
  v520 = major;
  v173[21] = "isam_f_ R Hand";
  v193 = NewSpecific(string, 0x12u);
  v193[4] = "isamu_fz";
  v193[5] = "Bip ÒÅ1";
  v193[6] = "Bip ÒÅ3";
  v193[7] = "Bip ÒÅ4";
  v193[8] = "Bip ñ";
  v193[9] = "Bip Head";
  v193[10] = "Bip L Thigh";
  v193[11] = "Bip L Calf";
  v193[12] = "Bip L Foot";
  v193[13] = "Bip R Thigh";
  v193[14] = "Bip R Calf";
  v193[15] = "Bip R Foot";
  v193[16] = "Bip L UpperArm";
  v193[17] = "Bip L Forearm";
  v193[18] = "Bip L Hand";
  v193[19] = "Bip R UpperArm";
  v193[20] = "Bip R Forearm";
  v522 = v11;
  v193[21] = "Bip R Hand";
  v228 = NewSpecific(string, 0x12u);
  v228[4] = "hikawa";
  v228[5] = "hik ÒÅ1";
  v228[6] = "hik ÒÅ3";
  v228[7] = "hik ÒÅ4";
  v228[8] = "hik ñ";
  v228[9] = "hik Head";
  v228[10] = "hik L Thigh";
  v228[11] = "hik L Calf";
  v228[12] = "hik L Foot";
  v228[13] = "hik R Thigh";
  v228[14] = "hik R Calf";
  v228[15] = "hik R Foot";
  v228[16] = "hik L UpperArm";
  v228[17] = "hik L Forearm";
  v228[18] = "hik L Hand";
  v228[19] = "hik R UpperArm";
  v228[20] = "hik R Forearm";
  model = v10;
  v228[21] = "hik R Hand";
  v248 = NewSpecific(string, 0x12u);
  v248[4] = "0x113";
  v248[5] = "Body";
  v248[6] = "B Spine";
  v248[7] = "B Spine1";
  v248[8] = "B Neck";
  v248[9] = "B Head";
  v248[10] = "B L Thigh";
  v248[11] = "B L Calf";
  v248[12] = "B L Foot";
  v248[13] = "B R Thigh";
  v248[14] = "B R Calf";
  v248[15] = "B R Foot";
  v248[16] = "B L UpperArm";
  v248[17] = "B L Forearm";
  v248[18] = "B L Hand";
  v248[19] = "B R UpperArm";
  v248[20] = "B R Forearm";
  v248[21] = "B R Hand";
  v267 = NewSpecific(string, 0x12u);
  v267[4] = "tiaki_b";
  v267[5] = "Bip ÒÅ1";
  v267[6] = "Bip ÒÅ3";
  v267[7] = "Bip ÒÅ4";
  v267[8] = "Bip ñ";
  v267[9] = "Bip Head";
  v267[10] = "Bip L Thigh";
  v267[11] = "Bip L Calf";
  v267[12] = "Bip L Foot";
  v267[13] = "Bip R Thigh";
  v267[14] = "Bip R Calf";
  v267[15] = "Bip R Foot";
  v267[16] = "Bip L UpperArm";
  v267[17] = "Bip L Forearm";
  v267[18] = "Bip L Hand";
  v267[19] = "Bip R UpperArm";
  v267[20] = "Bip R Forearm";
  v267[21] = "Bip R Hand";
  v302 = NewSpecific(string, 0x12u);
  v302[4] = "majyo";
  v302[5] = "Bip ÒÅ1";
  v302[6] = "Bip ÒÅ3";
  v302[7] = "Bip ÒÅ4";
  v302[8] = "Bip ñ";
  v302[9] = "Bip Head";
  v302[10] = "Bip L Thigh";
  v302[11] = "Bip L Calf";
  v302[12] = "Bip L Foot";
  v302[13] = "Bip R Thigh";
  v302[14] = "Bip R Calf";
  v302[15] = "Bip R Foot";
  v302[16] = "Bip L UpperArm";
  v302[17] = "Bip L Forearm";
  v302[18] = "Bip L Hand";
  v302[19] = "Bip R UpperArm";
  v302[20] = "Bip R Forearm";
  v302[21] = "Bip R Hand";
  v337 = NewSpecific(string, 0x12u);
  v337[4] = "hutomimi";
  v337[5] = "hbk ÒÅ1";
  v337[6] = "hbk ÒÅ3";
  v337[7] = "hbk ÒÅ4";
  v337[8] = "hbk ñ";
  v337[9] = "hb Head";
  v337[10] = "hb L Thigh";
  v337[11] = "hb L Calf";
  v337[12] = "hb L Foot";
  v337[13] = "hb R Thigh";
  v337[14] = "hb R Calf";
  v337[15] = "hb R Foot";
  v337[16] = "hb L UpperArm";
  v337[17] = "hb L Forearm";
  v337[18] = "hb L Hand";
  v337[19] = "hb R UpperArm";
  v337[20] = "hb R Forearm";
  v337[21] = "hb R Hand";
  v356 = "";
  if (Compare("", v337[4], 0))
  {
    if (Compare(v356, v302[4], 0))
    {
      if (Compare(v356, v248[4], 0))
      {
        if (Compare(v356, v228[4], 0) && Compare(v356, "hikawa_j", 0))
        {
          if (Compare(v356, v138[4], 0) && Compare(v356, "isam_f", 0))
          {
            if (Compare(v356, v193[4], 0))
            {
              if (Compare(v356, v119[4], 0)
                && Compare(v356, "aradia", 0)
                && Compare(v356, "yuuko_p", 0))
              {
                if (Compare(v356, v84[4], 0)
                  && Compare(v356, "chiaki", 0)
                  && Compare(v356, "tiaki_a", 0))
                {
                  if (Compare(v356, v267[4], 0))
                  {
                    if (Compare(v356, v522[4], 0)
                      && !Equals_5234480(v356, "TESTTEST")
                      && Compare(v356, "player_j", 0)
                      && Compare(v356, "player_aj", 0)
                      && Compare(v356, "player84", 0)
                      && Compare(v356, "player86", 0)
                      && Compare(v356, "player88", 0))
                    {
                      if (Compare(v356, v521[4], 0))
                      {
                        if (Compare(v356, "player_z", 0))
                        {
                          if (v520 == 3 && v519 == 1)
                          {
                            nodeList = model->modelRoot->nodeList;
                            if (nodeList)
                            {
                              count = nodeList->count;
                              if (count >= 1)
                              {
                                v369 = 0;
                                v370 = -count;
                                do
                                {
                                  if (!v369)
                                  {
                                    LODWORD(v527[0]) = 0;
                                    v372 = sub_8D3950(s32, v527);
                                    {
                                    }
                                    Write_2930752("{0:D2}:pName:[{1}]\n", v372, v356);
                                  }
                                  --v369;
                                }
                                while (v370 != v369);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  v528.x = x;
  v528.y = y;
  v528.z = z;
  v528.w = w;
  dds3SetSclPoseSet(pBasic, v528);
  dds3GetRotPoseSetMCR(pBasic);
  dds3GetPosPoseSetMCR(pBasic);
  BaseControlWorkData->modelType = 0;
  BaseControlWorkData->pModel = model;
  BaseControlWorkData->svs = 0;
  workdata = (*pBasic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v527);
    if ((v527[0] & 1) != 0)
      v517 = v527[2];
    else
      v517 = v527 + 1;
    v518 = sub_8C4940(v517);
  }
  if (!workdata[2].klass)
  {
    workdata[2].klass = evtCreateUnitHandle(pBasic, model);
  }
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
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  dds3ModelHandle_t_o *pModel;
  u32 modelType;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v12;
  dds3ModelHandle_t_c *v13;
  s64 v14;
  char *v15;
  s64 *v16;
  UnityEngine_GameObject_o *v17;
  char *v18;
  s64 *v19;
  dds3ModelHandle_t_o *aHandle;
  sdfModelOt_t_o *aModelOt;
  u64 v22[2];
  char *v23;

  aHandle = 0;
  aModelOt = 0;
  BaseControlWorkData = dds3GetBaseControlWorkData(pObjectBasic, pObjectBasic);
  if ((dds3GetBaseControlWorkData(pObjectBasic)->flag & 1) == 0)
  {
    pModel = BaseControlWorkData->pModel;
    if (pModel)
    {
      modelType = BaseControlWorkData->modelType;
      if (modelType == 1)
      {
        hoji_animationset(BaseControlWorkData, *pObjectBasic);
      }
      else if (!modelType)
      {
        workdata = (*pObjectBasic)->workdata;
        klass = workdata->klass;
        if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
        {
          sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v22);
          if ((v22[0] & 1) != 0)
            v18 = v23;
          else
            v18 = v22 + 1;
          v19 = sub_8C4940(v18);
        }
        v12 = workdata[2].klass;
        aModelOt = 0;
        v13 = pModel->klass;
        if (pModel->klass->_2.typeHierarchyDepth < v14
          || v13->_2.typeHierarchy[v14 - 1] != dds3ModelHandle_t)
        {
          sub_8FC2C0(v13->_1.element_class, dds3ModelHandle_t, v22);
          if ((v22[0] & 1) != 0)
            v15 = v23;
          else
            v15 = v22 + 1;
          v16 = sub_8C4940(v15);
        }
        aHandle = pModel;
        v17 = v12->vtable[1].method;
        mdlLinkSub(&aHandle, &aModelOt, v17, 0);
      }
    }
  }
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
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 monitor;
  s32 v10;
  dds3Basic_t_o *v11;
  s32 MotMode;
  f32 MotSpeed;
  struct sdfMotionCtrlr_t_o *pMot;
  f32 *p_MotSpeed;
  f32 v17;
  f32 v18;
  dds3ObjectBaseControlWorkData_t_o *v19;
  f32 v20;
  f32 v21;
  f32 v22;
  struct sdfMotionCtrlr_t_o *v23;
  char *v24;
  s64 *v25;
  u64 v26[3];

  if (HIBYTE(pObjectBasic->color))
  {
    workdata = pObjectBasic->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MatterObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MatterObjectBasicWorkData_t, v26);
      if ((v26[0] & 1) != 0)
        v24 = v26[2];
      else
        v24 = v26 + 1;
      v25 = sub_8C4940(v24);
    }
    monitor = workdata[1].monitor;
    if (monitor < 1)
    {
      MotSpeed = pControl->MotSpeed;
      if (MotSpeed > 0.0)
      {
        pMot = pControl->pMot;
        if (pMot)
          pMot->speed = MotSpeed;
      }
    }
    else
    {
      v10 = fldGbChkAnime(fldGb->fieldID, fldGb->areaID + 1, monitor);
      MotMode = pControl->MotMode;
      if (v10)
      {
        switch (MotMode)
        {
          case 0:
          case 1:
          case 2:
            *&pControl->MotMode = 3;
            break;
          case 3:
            goto LABEL_22;
          case 4:
            v18 = pControl->MotSpeed + -0.05;
            pControl->MotSpeed = v18;
            if (v18 < 0.0)
              goto LABEL_22;
            break;
          case 5:
            v17 = pControl->MotSpeed + -0.02;
            pControl->MotSpeed = v17;
            if (v17 >= 0.0)
              break;
LABEL_22:
            pControl->MotSpeed = 0.0;
            break;
          default:
            break;
        }
      }
      else
      {
        switch (MotMode)
        {
          case 0:
            p_MotSpeed = &pControl->MotSpeed;
            goto LABEL_26;
          case 1:
            v19 = pControl;
            v20 = 0.05;
            goto LABEL_25;
          case 2:
            v19 = pControl;
            v20 = 0.025;
LABEL_25:
            v21 = v19->MotSpeed;
            p_MotSpeed = &v19->MotSpeed;
            v22 = v21 + v20;
            *p_MotSpeed = v21 + v20;
            if ((v21 + v20) <= 1.0)
              goto LABEL_29;
LABEL_26:
            v22 = 1.0;
            *p_MotSpeed = 1.0;
            v23 = pControl->pMot;
            if (!v23)
              break;
            goto LABEL_31;
          case 6:
            break;
          default:
            v22 = pControl->MotSpeed;
LABEL_29:
            if (v22 > 0.0)
            {
              v23 = pControl->pMot;
              if (v23)
LABEL_31:
                v23->speed = v22;
            }
            break;
        }
      }
      HojiAnimation(pControl, v11, pObjectBasic->gameObject);
    }
  }
}
