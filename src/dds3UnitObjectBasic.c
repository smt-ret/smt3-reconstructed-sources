#include "types.h"

typedef struct FieldChrHD FieldChrHD;
typedef struct ModelHD ModelHD;
typedef struct dds3BasicArrayHandle_t dds3BasicArrayHandle_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct dds3UnitObjectBasicWorkData_t dds3UnitObjectBasicWorkData_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct sdfModelOt_t sdfModelOt_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

static sdfVector4_t r_q;
static sdfVector4_t r_v;
static dds3PoseSet_t *r_update;

void FromRotation(f32 aAngle);
f32 GetBattle(FieldChrHD *this);
void KageSet_Battle(FieldChrHD *this, f32 x, f32 z, f32 size, f32 alp);
void Mult(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__LOADIDENTITYVECTOR(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__SETVECTOR_X(f32 v);
void SDF_VU0__SETVECTOR_Y(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
void StepFrame(ModelHD *this);
void dds3AddPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3AddRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3AddSclPoseSet(dds3Basic_t **pBasic, sdfVector4_t scl);
dds3Basic_t *dds3AreaBasicGetFastArea(void);
void dds3BackupPoseSet(dds3PoseSet_t **pPoseSet);
s32 dds3CheckPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
void dds3FreeBasicArrayHandle(dds3BasicArrayHandle_t **hndl);
void dds3FreePoseSet(dds3Basic_t **basic);
dds3Basic_t *dds3GetBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3GetBasicArrayCount(dds3BasicArrayHandle_t **hndl);
dds3Basic_t *dds3GetControlScene(void);
void dds3GetPos2PoseSetMCR(dds3Basic_t **pBasic);
void dds3GetPosPoseSetMCR(dds3Basic_t **pBasic);
void dds3GetRotPoseSetMCR(dds3Basic_t **pBasic);
void dds3GetSclPoseSetMCR(dds3Basic_t *pBasic);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
s32 dds3InitPoseSet(dds3Basic_t **basic);
void dds3InitPoseSetValue(dds3PoseSet_t **pPoseSet);
void dds3LinkLightObjectToUnitObject(dds3Basic_t **lightbasic, dds3Basic_t **unitbasic, u32 frame);
s32 dds3ObjectBaseCheckFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseFreeControlWorkData(dds3ObjectBaseControlWorkData_t **pControl);
void dds3ObjectBaseFreeModelHandle(dds3Basic_t **pObjectBasic);
dds3ObjectBaseControlWorkData_t *dds3ObjectBaseInitControlWorkData(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseModelLinkOt(sdfModelOt_t *pModelOt, dds3Basic_t **pObjectBasic);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
s32 dds3ObjectBaseRegistArea(dds3Basic_t **pObjectBasic);
dds3Basic_t *dds3ObjectBaseSetControlBasicType(dds3Basic_t **pObjectBasic, dds3Basic_t **pItemBasic, u32 itemType);
void dds3OffPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag);
s32 dds3RadiusCheckPoseSet2(dds3PoseSet_t **p1, dds3PoseSet_t **p2);
dds3BasicArrayHandle_t *dds3SceneBasicGetList(dds3Basic_t **pBasic, u32 type);
s32 dds3SetFirstBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3SetNextBasicArray(dds3BasicArrayHandle_t **hndl);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void dds3UnitObjectBasicEL_Link(dds3Basic_t **unitBasic);
void dds3UnitObjectBasicEL_LinkFree(dds3Basic_t **unitBasic);
dds3ObjectBaseControlWorkData_t *dds3UnitObjectBasicGetControlWorkData(dds3Basic_t **pBasic);
void dds3UnitObjectBasicWorkData_t__Clear(dds3UnitObjectBasicWorkData_t *this);
void dds3UnlinkLightObjectFromUnitObject(dds3Basic_t **unitbasic, u32 frame);
s32 evtDeleteUnitHandle(evtUnitHandle_t **h);
s32 evtUnitManagerPrimaryFunc(dds3PoseSet_t *pose, dds3Basic_t *basic);
dds3Basic_t *fldCamNowEveCamera(bool nc);
void fldSdwDraw(dds3Basic_t *pObjectBasic);
s32 mdlChkHide(dds3ModelHandle_t *mdl);
s32 mdlGetMajorNum(dds3ModelHandle_t **aHandle);
s32 mdlGetMinorNum(dds3ModelHandle_t **aHandle);
void mdlGetPosition(dds3ModelHandle_t **aHandle);
void mdlGetRotate(dds3ModelHandle_t **aHandle);
void mdlGetScale(dds3ModelHandle_t **aHandle);
void mdlSetPosition(dds3ModelHandle_t **aHandle);
void mdlSetRotate(dds3ModelHandle_t **aHandle);
void mdlSetScale(dds3ModelHandle_t **aHandle);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);
f32 sdfSin(f32 aRadius);
void update_position(dds3Basic_t **basic);

// 0x1003a10
dds3Basic_t *dds3AddUnitObjectBasic(u32 serialID, sdfVector4_t aPos, sdfVector4_t aRot) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  dds3Basic_t_o *result;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v18;
  s64 *v19;
  dds3Basic_t_o *pItemBasic;
  dds3Basic_t_o *pObjectBasic;
  u64 v22[3];
  UnityEngine_Vector4_o v23;
  UnityEngine_Vector4_o v24;

  w = aRot.w;
  z = aRot.z;
  y = aRot.y;
  x = aRot.x;
  v8 = aPos.w;
  v9 = aPos.z;
  v10 = aPos.y;
  v11 = aPos.x;
  pObjectBasic = 0;
  pItemBasic = 0;
  result = dds3AddSceneBasicData(5u);
  pObjectBasic = result;
  if (result)
  {
    result->serialID = serialID;
    dds3ObjectBaseCreateMover(&pObjectBasic);
    v23.x = v11;
    v23.y = v10;
    v23.z = v9;
    v23.w = v8;
    dds3SetPosPoseSet(&pObjectBasic, v23);
    v24.x = x;
    v24.y = y;
    v24.z = z;
    v24.w = w;
    dds3SetRotPoseSet(&pObjectBasic, v24);
    dds3BackupPoseSet(&pObjectBasic->poseset);
    workdata = pObjectBasic->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v22);
      if ((v22[0] & 1) != 0)
        v18 = v22[2];
      else
        v18 = v22 + 1;
      v19 = sub_8C4940(v18);
    }
    LODWORD(workdata[1].klass) = -1;
    LODWORD(v22[0]) = 0;
    workdata[1].monitor = sub_8D3950(s32, v22);
    LODWORD(workdata[4].klass) = 0;
    pItemBasic = dds3AreaBasicGetFastArea();
    dds3ObjectBaseSetControlBasicType(&pObjectBasic, &pItemBasic, 5u);
    dds3ObjectBaseRegistArea(&pObjectBasic);
    return pObjectBasic;
  }
  return result;
}

// 0x1003c40
void dds3DeleteUnitObjectBasic(dds3Basic_t **aPtr) {
  dds3DeleteSceneBasicData(aPtr);
}

// 0x1003cb0
s32 dds3GetStatusUnitObjectBasic(dds3Basic_t **aPtr) {
  s32 *workdata;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  workdata = (*aPtr)->workdata;
  v4 = *workdata;
  if (*(*workdata + 288LL) < typeHierarchyDepth
    || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(*(v4 + 64), dds3UnitObjectBasicWorkData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[4];
}

// 0x1003830
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b) {
  evtUnitHandle_t_o **workdata;
  evtUnitHandle_t_o *v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  workdata = (*b)->workdata;
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

// 0x1001bb0
s32 dds3UnitObjectBasicConstructor(dds3Basic_t *aPtr) {
  dds3Basic_t_o *v2;
  u64 *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject *v9;
  Il2CppClass *v10;
  s64 v11;
  char *v12;
  s64 *v13;
  dds3ObjectBaseControlWorkData_t_o *inited;
  u64 v16[2];
  char *v17;
  dds3Basic_t_o *basic;

  basic = aPtr;
  dds3InitPoseSet(&basic);
  v2 = basic;
  v3 = Allocate(dds3UnitObjectBasicWorkData_t);
  dds3UnitObjectBasicWorkData_t___ctor(v3);
  v2->workdata = v3;
  workdata = basic->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v16);
      if ((v16[0] & 1) != 0)
        v7 = v17;
      else
        v7 = v16 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  dds3UnitObjectBasicWorkData_t__Clear(workdata);
  v9 = basic->workdata;
  if (v9)
  {
    v10 = v9->klass;
    if (v9->klass->_2.typeHierarchyDepth < v11
      || v10->_2.typeHierarchy[v11 - 1] != dds3UnitObjectBasicWorkData_t)
    {
      sub_8FC2C0(v10->_1.element_class, dds3UnitObjectBasicWorkData_t, v16);
      if ((v16[0] & 1) != 0)
        v12 = v17;
      else
        v12 = v16 + 1;
      v13 = sub_8C4940(v12);
    }
  }
  inited = dds3ObjectBaseInitControlWorkData(&basic);
  v9[2].klass = 0;
  v9[2].monitor = inited;
  v9[3].klass = -1LL;
  dds3ObjectBaseOnFlag(&basic, 0x42u, 0);
  return 1;
}

// 0x1001dc0
s32 dds3UnitObjectBasicDestructor(dds3Basic_t *aPtr) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  evtUnitHandle_t_o **v9;
  dds3Basic_t_o *v11;
  u64 v12[3];

  v11 = aPtr;
  dds3UnitObjectBasicEL_LinkFree(&v11);
  dds3FreePoseSet(&v11);
  workdata = v11->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v12);
      if ((v12[0] & 1) != 0)
        v7 = v12[2];
      else
        v7 = v12 + 1;
      v8 = sub_8C4940(v7);
    }
    if (LODWORD(workdata[1].klass) != -1)
      LODWORD(workdata[1].klass) = -1;
    v9 = &workdata[2];
    if (workdata[2].klass)
    {
      evtDeleteUnitHandle(v9);
      *v9 = 0;
    }
    dds3ObjectBaseFreeModelHandle(&v11);
    dds3ObjectBaseFreeControlWorkData(&workdata[2].monitor);
  }
  return 0;
}

// 0x1002fd0
s32 dds3UnitObjectBasicDrawProcedure(dds3Basic_t *aPtr) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  evtUnitHandle_t_o *UnitHandleObjectBasic;
  s32 v10;
  dds3ModelHandle_t_o *Model;
  dds3Basic_t_o *v13;
  UnityEngine_Object_o *v14;
  Il2CppObject *Component_object;
  s64 *v18;
  s64 v19;
  s64 v20;
  char *v21;
  s64 *v22;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *Child;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 *p_SDF_CC_NDNM;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  u64 *v43;
  Il2CppObject *pModel;
  Il2CppClass *v46;
  s64 v47;
  s32 element_class_high;
  sdfModelRootNode_t_o *v49;
  f32 v52;
  f32 r;
  f32 v54;
  bool v55;
  f32 v56;
  f32 v57;
  u32 klass_high;
  struct sdfModelOt_t_array *v60;
  sdfModelOt_t_o *v62;
  struct sdfModelOt_t_array *dds3ModelOt;
  char *v66;
  s64 *v67;
  UnityEngine_Vector4_o v68;
  UnityEngine_Vector4_o v69;
  UnityEngine_Vector4_o v70;
  UnityEngine_Vector4_o p;
  dds3ModelHandle_t_o *aHandle;
  dds3Basic_t_o *pObjectBasic;
  UnityEngine_Quaternion_o v74;
  char *v75;
  UnityEngine_Vector3_o v76;
  UnityEngine_Quaternion_o v77;
  UnityEngine_Vector3_o v78;
  UnityEngine_Vector3_o v79;
  UnityEngine_Vector3_o v80;
  UnityEngine_Vector3_o v81;
  UnityEngine_Vector3_o v82;
  UnityEngine_Vector4_o v83;
  UnityEngine_Quaternion_o v84;
  UnityEngine_Quaternion_o v85;
  UnityEngine_Quaternion_o v86;
  UnityEngine_Quaternion_o v87;

  pObjectBasic = aPtr;
  *&p.z = 0;
  aHandle = 0;
  *&v68.x = 0;
  *&v70.z = 0;
  *&p.x = 0;
  *&v69.z = 0;
  *&v70.x = 0;
  *&v68.z = 0;
  *&v69.x = 0;
  workdata = aPtr->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, &v74);
      if ((LOBYTE(v74.x) & 1) != 0)
        v6 = v75;
      else
        v6 = &v74.x + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (!dds3ObjectBaseCheckFlag(&pObjectBasic, 1u))
  {
    UnitHandleObjectBasic = dds3GetUnitHandleObjectBasic(&pObjectBasic);
    v10 = dds3ObjectBaseCheckFlag(&pObjectBasic, 0x200u);
    if (UnitHandleObjectBasic && v10)
    {
      Model = UnitHandleObjectBasic->Model;
      if (!mdlChkHide(Model))
      {
        v13 = pObjectBasic;
        fldSdwDraw(v13);
      }
    }
    v14 = workdata[2].klass->vtable[1].method;
    if (op_Inequality(v14, 0, 0))
    {
      Component_object = GetComponent_object_(workdata[2].klass->vtable[1].Method_UnityEngine_GameObject_GetComponent_FieldChrHD___);
      if (op_Inequality(Component_object, 0, 0)
        && GetBattle(Component_object) == 1.0)
      {
        v18 = *(workdata[2].monitor + 5);
        if (v18)
        {
          v19 = *v18;
          if (*(*v18 + 288) < v20 || *(*(v19 + 200) + 8 * v20 - 8) != dds3ModelHandle_t)
          {
            sub_8FC2C0(*(v19 + 64), dds3ModelHandle_t, &v74);
            if ((LOBYTE(v74.x) & 1) != 0)
              v21 = v75;
            else
              v21 = &v74.x + 1;
            v22 = sub_8C4940(v21);
          }
        }
        aHandle = *(workdata[2].monitor + 5);
        transform = get_transform(workdata[2].klass->vtable[1].0);
        Child = GetChild(transform, 0);
        mdlGetPosition(&aHandle);
        SDF_VU0__STOREVECTOR(&p);
        x = p.x;
        y = p.y;
        z = p.z;
        w = p.w;
        v83.x = x;
        v83.y = y;
        v83.z = z;
        v83.w = w;
        v76 = op_Implicit_8738992(v83);
        p_SDF_CC_NDNM = &SDF_CC_NDNM;
        v34 = p_SDF_CC_NDNM[41];
        v35 = p_SDF_CC_NDNM[42];
        v36 = p_SDF_CC_NDNM[43];
        v82.x = v34;
        v82.y = v35;
        v82.z = v36;
        v78 = Scale(v76, v82);
        v79 = op_Addition(v78, *&workdata[2].klass->vtable[3].0);
        p = op_Implicit(v79, 0);
        v80 = op_Implicit_8738992(p);
        set_position(Child, v80);
        v38 = mod_quat.x;
        v39 = mod_quat.y;
        v40 = mod_quat.z;
        v41 = mod_quat.w;
        mdlGetRotate(&aHandle);
        SDF_VU0__STOREVECTOR(&v70);
        *&v74.x = 0;
        *&v74.z = 0;
        sub_1A1BDD0(&v74.x, v70.x, v70.y, v70.z, v70.w);
        {
        }
        v86 = Inverse(v74, 0);
        v84.x = v38;
        v84.y = v39;
        v84.z = v40;
        v84.w = v41;
        v77 = op_Multiply(v84, v86, 0);
        v87 = Euler(
                *&workdata[2].klass->vtable[2].methodPtr,
                *(&workdata[2].klass->vtable[2].methodPtr + 1),
                *&workdata[2].klass->vtable[2].0);
        v85 = op_Multiply(v77, v87, 0);
        set_rotation(Child, v85);
        mdlGetScale(&aHandle);
        SDF_VU0__STOREVECTOR(&v69);
        v81 = op_Implicit_8738992(v69);
        set_localScale(Child, v81);
        StepFrame(Component_object);
        if (dds3ObjectBaseCheckFlag(&pObjectBasic, 0x2000u))
        {
          v43 = Allocate(dds3ModelHandle_t);
          dds3ModelHandle_t___ctor(v43);
          pModel = dds3UnitObjectBasicGetControlWorkData(&pObjectBasic)->pModel;
          v46 = pModel->klass;
          if (pModel->klass->_2.typeHierarchyDepth < v47
            || v46->_2.typeHierarchy[v47 - 1] != dds3ModelHandle_t)
          {
            sub_8FC2C0(v46->_1.element_class, dds3ModelHandle_t, &v74);
            if ((LOBYTE(v74.x) & 1) != 0)
              v66 = v75;
            else
              v66 = &v74.x + 1;
            v67 = sub_8C4940(v66);
          }
          element_class_high = HIBYTE(pModel[4].klass->_1.element_class);
          *&v68.x = 0;
          *&v68.z = 0;
          v49 = *(workdata[2].klass->_1.interfaceOffsets + 8);
          if (sdfModelGetMarkPosUnity(v49, 0))
          {
            SDF_VU0__STOREVECTOR(&v68);
            v52 = (element_class_high * 0.0078125) * BattleMarukageAlpMul;
            r = pObjectBasic->poseset->r;
            if (r <= 299.0)
            {
              if (r <= 199.0)
              {
                if (r <= 99.0)
                  v54 = 1.5;
                else
                  v54 = 2.0;
              }
              else
              {
                v54 = 2.5;
              }
            }
            else
            {
              v54 = 3.0;
            }
            v55 = dds3ObjectBaseCheckFlag(&pObjectBasic, 0x4000u) == 0;
            if (v55)
              v56 = v52;
            else
              v56 = v52 * 0.4;
            if (v55)
              v57 = v54;
            else
              v57 = v54 * 0.7;
            KageSet_Battle(Component_object, v68.x / 100.0, v68.z / 100.0, v57, v56);
          }
        }
      }
    }
    klass_high = HIDWORD(workdata[3].klass);
    if (klass_high == -1)
    {
      v62 = dds3ModelOt->m_Items[0];
    }
    else
    {
      v60 = dds3ModelOt;
      v62 = v60->m_Items[klass_high];
    }
    dds3ObjectBaseModelLinkOt(v62, &pObjectBasic);
  }
  return 1;
}

// 0x1002810
void dds3UnitObjectBasicEL_Link(dds3Basic_t **unitBasic) {
  u64 *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s32 BasicArrayCount;
  dds3Basic_t_o *BasicArray;
  Il2CppObject *v17;
  s64 v19;
  Il2CppClass *v20;
  dds3PoseSet_t_o **p_poseset;
  dds3PoseSet_t_o **v22;
  dds3Basic_t_o *v25;
  Il2CppObject *v26;
  s64 v28;
  Il2CppClass *v29;
  dds3PoseSet_t_o **v30;
  dds3PoseSet_t_o **v31;
  char *v32;
  s64 *v33;
  char *v34;
  s64 *v35;
  dds3Basic_t_o *ControlScene;
  dds3Basic_t_o *lightbasic;
  dds3BasicArrayHandle_t_o *hndl;
  u64 v39[2];
  char *v40;

  ControlScene = 0;
  lightbasic = 0;
  v3 = Allocate(dds3BasicArrayHandle_t);
  dds3BasicArrayHandle_t___ctor(v3);
  hndl = v3;
  workdata = (*unitBasic)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v39);
      if ((v39[0] & 1) != 0)
        v8 = v40;
      else
        v8 = v39 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  else
  {
    ControlScene = dds3GetControlScene();
    if (!ControlScene)
      return;
  }
  hndl = dds3SceneBasicGetList(&ControlScene, 9u);
  if (hndl)
  {
    BasicArrayCount = dds3GetBasicArrayCount(&hndl);
    if (!BasicArrayCount)
    {
      {
LABEL_76:
        dds3FreeBasicArrayHandle(&hndl);
        return;
      }
LABEL_72:
      goto LABEL_76;
    }
    if (dds3SetFirstBasicArray(&hndl))
    {
      do
      {
        while (1)
        {
          BasicArray = dds3GetBasicArray(&hndl);
          lightbasic = BasicArray;
          v17 = BasicArray->workdata;
          v20 = v17->klass;
          if (v17->klass->_2.typeHierarchyDepth < v19
            || v20->_2.typeHierarchy[v19 - 1] != dds3LightObjectBasicWorkData_t)
          {
            sub_8FC2C0(v20->_1.element_class, dds3LightObjectBasicWorkData_t, v39);
            if ((v39[0] & 1) != 0)
              v32 = v40;
            else
              v32 = v39 + 1;
            v33 = sub_8C4940(v32);
          }
          if ((BYTE4(v17[3].monitor) & 4) == 0)
          {
            p_poseset = &BasicArray->poseset;
            v22 = &(*unitBasic)->poseset;
            if (!dds3RadiusCheckPoseSet2(v22, p_poseset)
              && LODWORD(workdata[3].klass) == lightbasic->serialID)
            {
              dds3UnlinkLightObjectFromUnitObject(unitBasic, 0xAu);
              LODWORD(workdata[3].klass) = -1;
            }
          }
            break;
          if (!dds3SetNextBasicArray(&hndl))
            goto LABEL_42;
        }
      }
      while (dds3SetNextBasicArray(&hndl));
    }
LABEL_42:
    dds3FreeBasicArrayHandle(&hndl);
    if (LODWORD(workdata[3].klass) == -1)
    {
      hndl = dds3SceneBasicGetList(&ControlScene, 9u);
      if (dds3SetFirstBasicArray(&hndl))
      {
        while (1)
        {
          v25 = dds3GetBasicArray(&hndl);
          lightbasic = v25;
          v26 = v25->workdata;
          v29 = v26->klass;
          if (v26->klass->_2.typeHierarchyDepth < v28
            || v29->_2.typeHierarchy[v28 - 1] != dds3LightObjectBasicWorkData_t)
          {
            sub_8FC2C0(v29->_1.element_class, dds3LightObjectBasicWorkData_t, v39);
            if ((v39[0] & 1) != 0)
              v34 = v40;
            else
              v34 = v39 + 1;
            v35 = sub_8C4940(v34);
          }
          if ((BYTE4(v26[3].monitor) & 4) == 0)
          {
            v30 = &v25->poseset;
            v31 = &(*unitBasic)->poseset;
            if (dds3RadiusCheckPoseSet2(v31, v30))
              break;
          }
          else if (!dds3SetNextBasicArray(&hndl))
          {
            goto LABEL_75;
          }
        }
        dds3LinkLightObjectToUnitObject(&lightbasic, unitBasic, 0xAu);
        LODWORD(workdata[3].klass) = lightbasic->serialID;
      }
LABEL_75:
        goto LABEL_76;
      goto LABEL_72;
    }
  }
}

// 0x1001f70
void dds3UnitObjectBasicEL_LinkFree(dds3Basic_t **unitBasic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  workdata = (*unitBasic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  if (LODWORD(workdata[3].klass) != -1)
  {
    dds3UnlinkLightObjectFromUnitObject(unitBasic, 0xAu);
    LODWORD(workdata[3].klass) = -1;
  }
}

// 0x1003920
dds3ObjectBaseControlWorkData_t *dds3UnitObjectBasicGetControlWorkData(dds3Basic_t **pBasic) {
  dds3ObjectBaseControlWorkData_t_o **workdata;
  dds3ObjectBaseControlWorkData_t_o *v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  workdata = (*pBasic)->workdata;
  v4 = *workdata;
  if (LOBYTE((*workdata)[2].MotMode) < typeHierarchyDepth
    || *(v4[1].sdwnodeidx + typeHierarchyDepth - 1) != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(v4->pModelRangeRootNode, dds3UnitObjectBasicWorkData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[5];
}

// 0x1002080
s32 dds3UnitObjectBasicMainProcedure(dds3Basic_t *aPtr) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3PoseSet_t_o *r_update;
  f32 *v12;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  s64 *v17;
  s64 v18;
  s64 v19;
  char *v20;
  s64 *v21;
  dds3PoseSet_t_o **p_poseset;
  dds3PoseSet_t_o **v26;
  Il2CppClass *v28;
  u32 v29;
  s32 v30;
  s32 v31;
  s32 MinorNum;
  _BOOL4 v34;
  dds3Basic_t_o *v36;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v47;
  f32 v48;
  dds3PoseSet_t_o **v51;
  dds3PoseSet_t_o **v56;
  dds3ModelHandle_t_o *aHandle;
  dds3Basic_t_o *basic;
  u64 v59[2];
  char *v60;
  UnityEngine_Vector4_o v61;

  basic = aPtr;
  aHandle = 0;
  workdata = aPtr->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v59);
      if ((v59[0] & 1) != 0)
        v6 = v60;
      else
        v6 = v59 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (workdata[2].klass)
  {
    dds3InitPoseSetValue(&r_update);
    if (evtUnitManagerPrimaryFunc(r_update, basic))
    {
      v12 = r_update;
      v13 = v12[14];
      v14 = v12[15];
      v15 = v12[16];
      v16 = v12[17];
      v61.x = v13;
      v61.y = v14;
      v61.z = v15;
      v61.w = v16;
      dds3AddSclPoseSet(&basic, v61);
      dds3AddRotPoseSet(&basic, r_update->rot);
      dds3AddPosPoseSet(&basic, r_update->pos);
    }
  }
  v17 = *(workdata[2].monitor + 5);
  if (!v17)
  {
    aHandle = 0;
    goto LABEL_36;
  }
  v18 = *v17;
  if (*(*v17 + 288) < v19 || *(*(v18 + 200) + 8 * v19 - 8) != dds3ModelHandle_t)
  {
    sub_8FC2C0(*(v18 + 64), dds3ModelHandle_t, v59);
    if ((v59[0] & 1) != 0)
      v20 = v60;
    else
      v20 = v59 + 1;
    v21 = sub_8C4940(v20);
  }
  aHandle = *(workdata[2].monitor + 5);
  p_poseset = &basic->poseset;
  if (dds3CheckPoseSetFlag(p_poseset, 1u) == 1)
  {
    v26 = &basic->poseset;
    dds3OffPoseSetFlag(v26, 1u);
    v28 = workdata[2].klass;
    if (v28)
    {
      if (LOWORD(v28->_2.cctor_thread) && LOWORD(v28->_2.cctor_thread) != 3)
      {
        v30 = 0;
      }
      else
      {
        v30 = (v29 >> 6) & 1;
      }
      if ((v29 & 0x400000) != 0)
        v31 = 1;
      else
        v31 = v30;
    }
    else
    {
      v31 = 0;
    }
    if (mdlGetMajorNum(&aHandle) == 1)
    {
      MinorNum = mdlGetMinorNum(&aHandle);
      v34 = MinorNum == 192 || (MinorNum - 339) < 3;
      v36 = basic;
      {
LABEL_73:
        dds3GetSclPoseSetMCR(v36);
        if (!v34 && v31 && workdata[2].klass)
        {
          SDF_VU0__COPYVECTOR_A_TO_B();
          SDF_VU0__LOADIDENTITYVECTOR();
          SDF_VU0__VECTOR_W_SET_ZERO();
          v39 = *&workdata[2].klass->_2.typeHierarchy;
          v40 = sdfSin(v39);
          SDF_VU0__SETVECTOR_X(v40 * 0.01);
          v41 = sdfSin(*&workdata[2].klass->_2.typeHierarchy);
          SDF_VU0__SETVECTOR_Y(v41 * 0.004);
          SDF_VU0__MULVECTOR();
          SDF_VU0__ADDVECTOR();
        }
        mdlSetScale(&aHandle);
        dds3GetRotPoseSetMCR(&basic);
        if (!v34 && v31 && workdata[2].klass)
        {
          SDF_VU0__COPYVECTOR_A_TO_B();
          SDF_VU0__LOADVECTOR(r_v);
          v47 = *&workdata[2].klass->_2.typeHierarchy;
          v48 = sdfSin(v47);
          FromRotation(v48 * 0.006);
          Mult();
        }
        if ((workdata[3].monitor & 1) != 0)
        {
          SDF_VU0__LOADVECTOR_B(r_q);
          Mult();
        }
        mdlSetRotate(&aHandle);
        v51 = &basic->poseset;
        if (dds3CheckPoseSetFlag(v51, 8u))
        {
          dds3GetPos2PoseSetMCR(&basic);
            goto LABEL_119;
        }
        else
        {
          dds3GetPosPoseSetMCR(&basic);
            goto LABEL_119;
        }
LABEL_119:
        mdlSetPosition(&aHandle);
        v56 = &basic->poseset;
        dds3BackupPoseSet(v56);
        goto LABEL_36;
      }
    }
    else
    {
      v34 = 0;
      v36 = basic;
        goto LABEL_73;
    }
    goto LABEL_73;
  }
LABEL_36:
  if (!dds3ObjectBaseCheckFlag(&basic, 0x100u))
  {
    dds3UnitObjectBasicEL_Link(&basic);
  }
  update_position(&basic);
  return 1;
}

// 0x1003da0
void dds3UnitObjectBasicSetOt(dds3Basic_t **aPtr, s32 idx) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  workdata = (*aPtr)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  HIDWORD(workdata[3].klass) = idx;
}

// 0x1002d90
void update_position(dds3Basic_t **basic) {
  System_String_o *name;
  System_String_o *v5;
  UnityEngine_Object_o *gameObject;
  System_String_o *v7;
  System_String_o *v8;
  UnityEngine_Transform_o *transform;
  struct dds3PoseSet_t_o *poseset;
  f32 z;
  f32 y;
  f32 v15;
  struct dds3PoseSet_t_o *v16;
  f32 v17;
  f32 x;
  f32 v19;
  UnityEngine_Vector3_o v20;
  UnityEngine_Vector3_o v21;
  UnityEngine_Quaternion_o v22;

  *&v22.x = 0;
  *&v22.z = 0;
  if (*basic)
  {
    name = (*basic)->name;
    if (name)
    {
      v5 = ToUpper(name, 0);
      gameObject = (*basic)->gameObject;
      if (!op_Equality(gameObject, 0, 0))
      {
        v7 = get_name((*basic)->gameObject, 0);
        v8 = ToUpper(v7, 0);
        if (Equals_5234480(v8, v5))
        {
          transform = get_transform((*basic)->gameObject, 0);
          if (!op_Equality(transform, 0, 0))
          {
            if (!op_Equality(v5, "PLAYER_UNIT", 0))
              goto LABEL_19;
            if (fldCamNowEveCamera(0))
            {
LABEL_19:
              poseset = (*basic)->poseset;
              z = poseset->pos.z;
              y = poseset->pos.y;
              v15 = poseset->pos.x / 100.0;
              v21.z = 0.0;
              *&v21.x = 0;
              sub_8524C0(&v21.x, v15, y / -100.0, z / 100.0);
              set_localPosition(transform, v21);
              sub_1A1BDD0(
                &v22.x,
                (*basic)->poseset->rot.x,
                -(*basic)->poseset->rot.y,
                (*basic)->poseset->rot.z,
                (*basic)->poseset->rot.w);
              set_localRotation(transform, v22);
              Rotate_27486992(transform, 0.0, 180.0, 0.0);
              v16 = (*basic)->poseset;
              v17 = v16->scl.z;
              x = v16->scl.x;
              v19 = v16->scl.y;
              v20.z = 0.0;
              *&v20.x = 0;
              sub_8524C0(&v20.x, x, v19, v17);
              set_localScale(transform, v20);
            }
          }
        }
      }
    }
  }
}
