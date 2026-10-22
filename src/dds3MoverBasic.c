#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3MoverBasicObjFunc_t dds3MoverBasicObjFunc_t;
typedef struct dds3MoverBasicWorkData_t dds3MoverBasicWorkData_t;
typedef struct dds3PathBasicControl_t dds3PathBasicControl_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct fldResourceLightPath_t fldResourceLightPath_t;

static s32 movername;
static char *movernamestr[10];

u32 DDS3_GETBASICTYPEL(dds3Basic_t *pAreaBasic);
s32 MoverBasicMainprocuder(dds3Basic_t *pBasic);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void dds3AddPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3AddRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3AddSclPoseSet(dds3Basic_t **pBasic, sdfVector4_t scl);
void dds3InitPoseSetValue(dds3PoseSet_t **pPoseSet);
void dds3MoverBasicFreePath(dds3Basic_t **pMoverBasic);
void dds3MoverBasicWorkData_t__Clear(dds3MoverBasicWorkData_t *this);
dds3Basic_t *dds3ObjectBaseSetControlBasicType(dds3Basic_t **pObjectBasic, dds3Basic_t **pItemBasic, u32 itemType);
f32 dds3PathBasicControlGetFovy(dds3PathBasicControl_t **pControl);
void dds3PathBasicControlGetLight(dds3PathBasicControl_t **pControl, fldResourceLightPath_t **resource);
void dds3PathBasicControlGetPos(dds3PathBasicControl_t **pControl);
void dds3PathBasicControlGetRot(dds3PathBasicControl_t **pControl);
dds3PathBasicControl_t *dds3PathBasicMakeControl(dds3Basic_t **pBasic);
u32 dds3SerializeID(void);
void dds3SetLightObjectPathResoruce(dds3Basic_t **basic, fldResourceLightPath_t *resource);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void update_hoji_position(dds3Basic_t *basic);

// 0x14eb9a0
s32 MoverBasicConstructor(dds3Basic_t *pBasic) {
  u64 *v3;
  u64 v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v9[3];

  v3 = Allocate(dds3MoverBasicWorkData_t);
  dds3MoverBasicWorkData_t___ctor(v3);
  pBasic->workdata = v3;
  if (v3)
  {
    v4 = *v3;
    if (*(*v3 + 288) < typeHierarchyDepth
      || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != dds3MoverBasicWorkData_t)
    {
      sub_8FC2C0(*(v4 + 64), dds3MoverBasicWorkData_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  dds3MoverBasicWorkData_t__Clear(v3);
  return 1;
}

// 0x14ebac0
s32 MoverBasicDestructor(dds3Basic_t *pBasic) {
  dds3Basic_t_o **workdata;
  dds3MoverBasicWorkData_t_c *v4;
  dds3Basic_t_o *v5;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  dds3Basic_t_o *pItemBasic;
  dds3Basic_t_o *pMoverBasic;
  u64 v13[3];

  pMoverBasic = pBasic;
  pItemBasic = 0;
  workdata = pBasic->workdata;
  if (workdata)
  {
    v5 = *workdata;
    if (LOBYTE((*workdata)[2].flag) < typeHierarchyDepth
      || *(v5[1].poseset + typeHierarchyDepth - 1) != dds3MoverBasicWorkData_t)
    {
      sub_8FC2C0(v5->poseset, dds3MoverBasicWorkData_t, v13);
      if ((v13[0] & 1) != 0)
        v7 = v13[2];
      else
        v7 = v13 + 1;
      v8 = sub_8C4940(v7);
    }
    dds3MoverBasicFreePath(&pMoverBasic, v4);
    pItemBasic = 0;
    dds3ObjectBaseSetControlBasicType(workdata + 2, &pItemBasic, 1u);
  }
  return 0;
}

// 0x14ebdf0
s32 MoverBasicMainprocuder(dds3Basic_t *pBasic) {
  u64 *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct dds3PoseSet_t_o *poseset;
  u8 *monitor;
  dds3PathBasicControl_t_o **p_monitor;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  Il2CppObject *v18;
  Il2CppClass *v19;
  s64 v20;
  char *v21;
  s64 *v22;
  u32 flag;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  dds3Basic_t_o *v29;
  f32 *v30;
  f32 Fovy;
  s64 v32;
  s64 v33;
  Il2CppObject *v34;
  Il2CppClass *v35;
  s64 rgctx_data_low;
  dds3Basic_t_o *v37;
  dds3Basic_t_o *v40;
  dds3PathBasicControl_t_o *v41;
  u32 v42;
  u32 mode;
  f32 frame;
  f32 v45;
  dds3MoverBasicObjFunc_t_o *v46;
  char *v47;
  s64 *v48;
  u64 *v49;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 v55;
  char *v57;
  s64 *v58;
  char *v59;
  s64 *v60;
  dds3PoseSet_t_o *pValue;
  fldResourceLightPath_t_o *resource;
  dds3Basic_t_o *pBasica;
  UnityEngine_Vector4_o p;
  u64 v65[2];
  char *v66;
  UnityEngine_Vector4_o v67;
  UnityEngine_Vector4_o v68;
  UnityEngine_Vector4_o v69;

  *&p.x = 0;
  *&p.z = 0;
  pBasica = 0;
  pValue = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  v3 = Allocate(fldResourceLightPath_t);
  fldResourceLightPath_t___ctor(v3);
  resource = v3;
  workdata = pBasic->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MoverBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MoverBasicWorkData_t, v65);
      if ((v65[0] & 1) != 0)
        v8 = v66;
      else
        v8 = v65 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  pBasica = workdata[1].klass;
  poseset = pBasica->poseset;
  p_monitor = &workdata[1].monitor;
  monitor = workdata[1].monitor;
  if (monitor)
  {
    if ((monitor[20] & 1) != 0)
    {
      dds3PathBasicControlGetPos(p_monitor);
      SDF_VU0__STOREVECTOR(&p);
      x = p.x;
      y = p.y;
      z = p.z;
      w = p.w;
      v67.x = x;
      v67.y = y;
      v67.z = z;
      v67.w = w;
      dds3SetPosPoseSet(&pBasica, v67);
      if (DDS3_GETBASICTYPEL(pBasica) == 6)
      {
        v18 = pBasica->workdata;
        if (v18)
        {
          v19 = v18->klass;
          if (v18->klass->_2.typeHierarchyDepth < v20
            || v19->_2.typeHierarchy[v20 - 1] != dds3MatterObjectBasicWorkData_t)
          {
            sub_8FC2C0(v19->_1.element_class, dds3MatterObjectBasicWorkData_t, v65);
            if ((v65[0] & 1) != 0)
              v21 = v66;
            else
              v21 = v65 + 1;
            v22 = sub_8C4940(v21);
          }
        }
        SDF_VU0__COPYVECTOR((&v18[3].klass + 4), p, 0);
      }
    }
    flag = (*p_monitor)->flag;
    if ((flag & 2) != 0)
    {
      dds3PathBasicControlGetRot(p_monitor);
      SDF_VU0__STOREVECTOR(&p);
      v26 = p.x;
      v25 = p.y;
      v28 = p.z;
      v27 = p.w;
      v68.x = v26;
      v68.y = v25;
      v68.z = v28;
      v68.w = v27;
      dds3SetRotPoseSet(&pBasica, v68);
      flag = (*p_monitor)->flag;
    }
    if ((flag & 4) != 0)
    {
      v29 = pBasica;
      if (DDS3_GETBASICTYPEL(v29) == 4)
      {
        v30 = pBasica->workdata;
        Fovy = dds3PathBasicControlGetFovy(p_monitor);
        v32 = *v30;
        if (*(*v30 + 288LL) < v33 || *(*(v32 + 200) + 8 * v33 - 8) != dds3CameraObjectBasicWorkData_t)
        {
          sub_8FC2C0(*(v32 + 64), dds3CameraObjectBasicWorkData_t, v65);
          if ((v65[0] & 1) != 0)
            v57 = v66;
          else
            v57 = v65 + 1;
          v58 = sub_8C4940(v57);
        }
        v30[26] = Fovy;
        v34 = pBasica->workdata;
        v35 = v34->klass;
        rgctx_data_low = LOBYTE(v4[3].rgctx_data);
        if (v34->klass->_2.typeHierarchyDepth < rgctx_data_low || v35->_2.typeHierarchy[rgctx_data_low - 1] != v4)
        {
          sub_8FC2C0(v35->_1.element_class, v65);
          if ((v65[0] & 1) != 0)
            v59 = v66;
          else
            v59 = v65 + 1;
          v60 = sub_8C4940(v59);
        }
        HIDWORD(v34[6].klass) |= 1u;
      }
    }
    if (((*p_monitor)->flag & 0x10) != 0)
    {
      v37 = pBasica;
      if (DDS3_GETBASICTYPEL(v37) == 9)
      {
        dds3PathBasicControlGetLight(p_monitor, &resource);
        dds3SetLightObjectPathResoruce(&pBasica, v3);
      }
    }
    v40 = pBasica;
    update_hoji_position(v40);
    v41 = *p_monitor;
    v42 = (*p_monitor)->flag;
    if ((v42 & 8) == 0)
    {
      mode = v41->mode;
      if (mode == 1)
      {
        frame = v41->frame;
        if (frame > 0.0)
        {
          v45 = -1.0;
          goto LABEL_67;
        }
        if ((v42 & 0x20) != 0)
          v41->frame = v41->frameMax;
      }
      else if (!mode)
      {
        frame = v41->frame;
        if (v41->frameMax > frame)
        {
          v45 = 1.0;
LABEL_67:
          v41->frame = frame + v45;
          return 1;
        }
        if ((v42 & 0x20) != 0)
          v41->frame = 0.0;
      }
    }
  }
  else if (poseset)
  {
    poseset->frameFall = 0.0;
    v46 = workdata[2].klass;
    if (v46)
    {
      if (v46->klass != dds3MoverBasicObjFunc_t)
      {
        sub_8FC2C0(v46->klass->_1.element_class, dds3MoverBasicObjFunc_t, v65);
        if ((v65[0] & 1) != 0)
          v47 = v66;
        else
          v47 = v65 + 1;
        v48 = sub_8C4940(v47);
      }
      v49 = Allocate(dds3PoseSet_t);
      dds3PoseSet_t___ctor(v49);
      pValue = v49;
      dds3InitPoseSetValue(&pValue);
      if (dds3MoverBasicObjFunc_t__Invoke(v46, pValue, pBasica) == 1)
      {
        v52 = pValue->scl.x;
        v53 = pValue->scl.y;
        v54 = pValue->scl.z;
        v55 = pValue->scl.w;
        v69.x = v52;
        v69.y = v53;
        v69.z = v54;
        v69.w = v55;
        dds3AddSclPoseSet(&pBasica, v69);
        dds3AddRotPoseSet(&pBasica, pValue->rot);
        dds3AddPosPoseSet(&pBasica, pValue->pos);
      }
    }
  }
  return 1;
}

// 0x14ed380
dds3Basic_t *dds3AddMoverBasic(dds3Basic_t **pObjectBasic) {
  dds3Basic_t_o *v3;
  Il2CppObject *workdata;
  dds3Basic_t_o *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  struct System_String_array *movernamestr;
  s64 movername;
  u64 v18[3];

  v3 = dds3AddSceneBasicData(3u);
  workdata = v3->workdata;
  v6 = v3;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MoverBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MoverBasicWorkData_t, v18);
      if ((v18[0] & 1) != 0)
        v9 = v18[2];
      else
        v9 = v18 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  v6->serialID = dds3SerializeID();
  workdata[1].klass = *pObjectBasic;
  v6->name = movernamestr->m_Items[movername];
  ++movername;
  movername %= 10;
  return v6;
}

// 0x14ebbf0
void dds3MoverBasicFreePath(dds3Basic_t **pMoverBasic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  workdata = (*pMoverBasic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MoverBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3MoverBasicWorkData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  if (workdata[1].monitor)
    workdata[1].monitor = 0;
}

// 0x14edd80
dds3PathBasicControl_t *dds3MoverBasicGetPathControl(dds3Basic_t **pMoverBasic) {
  dds3PathBasicControl_t_o **workdata;
  dds3PathBasicControl_t_o *v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  workdata = (*pMoverBasic)->workdata;
  v4 = *workdata;
  if (LOBYTE((*workdata)[4].klass) < typeHierarchyDepth
    || *(v4[2].pFovy + typeHierarchyDepth - 1) != dds3MoverBasicWorkData_t)
  {
    sub_8FC2C0(v4->pLight, dds3MoverBasicWorkData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[3];
}

// 0x14ed770
void dds3MoverBasicMakePath(dds3Basic_t **pMoverBasic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  workdata = (*pMoverBasic)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MoverBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MoverBasicWorkData_t, v8);
      if ((v8[0] & 1) != 0)
        v6 = v8[2];
      else
        v6 = v8 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  workdata[1].monitor = dds3PathBasicMakeControl(&workdata[2].monitor);
}

// 0x14ed570
void dds3MoverBasicSetCallBackPrimaryControl(dds3Basic_t **mover, dds3MoverBasicObjFunc_t *func) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  workdata = (*mover)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MoverBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3MoverBasicWorkData_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  workdata[2].klass = func;
}

// 0x14ed670
void dds3MoverBasicSetPath(dds3Basic_t **pMoverBasic, dds3Basic_t **pPathBasic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  workdata = (*pMoverBasic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MoverBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3MoverBasicWorkData_t, v10);
    if ((v10[0] & 1) != 0)
      v8 = v10[2];
    else
      v8 = v10 + 1;
    v9 = sub_8C4940(v8);
  }
  workdata[2].monitor = *pPathBasic;
}

// 0x14ede70
s32 dds3MoverBasicUpdate(dds3Basic_t **pBasic) {
  dds3Basic_t_o *v3;

  v3 = *pBasic;
  MoverBasicMainprocuder(v3);
  return 1;
}

// 0x14ecd90
void updatePositionForUnity(dds3Basic_t *basic) {
  dds3Basic_t_o *v3;

  else
  {
    v3 = basic;
  }
  update_hoji_position(v3);
}

// 0x14ecea0
void update_hoji_position(dds3Basic_t *basic) {
  Il2CppObject *v3;
  UnityEngine_GameObject_o *FildMapObj;
  UnityEngine_Object_o *Component_object;
  dds3ModelFileTable_t_array *klass;
  u64 *v12;
  s32 Index_dds3ModelFileTable_t;
  UnityEngine_Object_c *v15;
  UnityEngine_Object_o *v17;
  dds3ModelFileTable_t_array *v20;
  u64 *v21;
  s32 v22;
  UnityEngine_Object_c *v24;
  dds3ModelFileTable_t_array *monitor;
  u64 *v28;
  s32 v29;
  u32 *v30;
  s32 v32;
  UnityEngine_Transform_o *transform;
  struct fldGlobalWork_t_o *fldGb;
  struct dds3PoseSet_t_o *poseset;
  f32 x;
  f32 z;
  f32 w;
  f32 v42;
  UnityEngine_Quaternion_o v43;
  UnityEngine_Vector3_o v44;

  v44.z = 0.0;
  *&v44.x = 0;
  v3 = Allocate(dds3MoverBasic___c__DisplayClass4_0);
  _ctor(v3, 0);
  if (DDS3_GETBASICTYPEL(basic) == 6)
  {
    if (!op_Equality(FildMapObj, 0, 0) && basic->name)
    {
      get_transform(FildMapObj, 0);
      v3[1].klass = ToUpper(basic->name, 0);
      if (!op_Equality(FildMapObj, 0, 0))
      {
        Component_object = GetComponent_object_(FildMapObj);
        if (!op_Equality(Component_object, 0, 0))
        {
          klass = Component_object[1].klass;
          v12 = Allocate(System_Predicate_GameObject_);
          __ctor(
            v12,
            v3,
            Method_dds3MoverBasic___c__DisplayClass4_0__update_hoji_position_b__0__);
          Index_dds3ModelFileTable_t = FindIndex_dds3ModelFileTable_t_(klass, v12);
          if (Index_dds3ModelFileTable_t == -1)
          {
            v17 = 0;
              goto LABEL_31;
          }
          else
          {
            v15 = Component_object[1].klass;
            v17 = *(&v15->_1.byval_arg.data + Index_dds3ModelFileTable_t);
            {
LABEL_31:
              if (!op_Equality(v17, 0, 0))
                goto LABEL_46;
              v20 = Component_object[1].klass;
              v21 = Allocate(System_Predicate_GameObject_);
              __ctor(
                v21,
                v3,
                Method_dds3MoverBasic___c__DisplayClass4_0__update_hoji_position_b__1__);
              v22 = FindIndex_dds3ModelFileTable_t_(v20, v21);
              if (v22 == -1)
              {
                v17 = 0;
                  goto LABEL_40;
              }
              else
              {
                v24 = Component_object[1].klass;
                v17 = *(&v24->_1.byval_arg.data + v22);
                {
LABEL_40:
                  if (op_Equality(v17, 0, 0))
                  {
                    monitor = Component_object[1].monitor;
                    v28 = Allocate(System_Predicate_GameObject_);
                    __ctor(
                      v28,
                      v3,
                      Method_dds3MoverBasic___c__DisplayClass4_0__update_hoji_position_b__2__);
                    v29 = FindIndex_dds3ModelFileTable_t_(monitor, v28);
                    if (v29 != -1)
                    {
                      v30 = Component_object[1].monitor;
                      v17 = *&v30[2 * v29 + 8];
                      v32 = 0;
                        goto LABEL_50;
                      goto LABEL_47;
                    }
                    v32 = 0;
                    v17 = 0;
                    {
LABEL_50:
                      if (!op_Equality(v17, 0, 0))
                      {
                        transform = get_transform(v17, 0);
                        sub_8524C0(&v44.x, basic->poseset->pos.x / -100.0, basic->poseset->pos.y / -100.0, basic->poseset->pos.z / -100.0);
                        set_localPosition(transform, v44);
                        if (v32 == 31)
                        {
                          if ((fldGb->areaID - 17) <= 2 && fldGb->fieldID == 20)
                          {
                            poseset = basic->poseset;
                            x = poseset->rot.x;
                            z = poseset->rot.z;
                            w = poseset->rot.w;
                            v42 = -poseset->rot.y;
                            *&v43.x = 0;
                            *&v43.z = 0;
                            sub_1A1BDD0(&v43.x, -x, v42, -z, w);
                            set_localRotation(transform, v43);
                          }
                        }
                      }
                      return;
                    }
LABEL_47:
                    goto LABEL_50;
                  }
LABEL_46:
                  v32 = 31;
                    goto LABEL_50;
                  goto LABEL_47;
                }
              }
              goto LABEL_40;
            }
          }
          goto LABEL_31;
        }
      }
    }
  }
}
