#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fldResourceLightPath_t fldResourceLightPath_t;
typedef struct fldResourceLight_t fldResourceLight_t;

void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SCALEVECTOR_B(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p);
u32 SDF_VU0__dds3ColorFtoI(f32 ratio);
void SDF_VU0__dds3ColorItoF(u32 rgba);
dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
void dds3FreePoseSet(dds3Basic_t **basic);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
s32 dds3InitPoseSet(dds3Basic_t **basic);
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseFreeControlWorkData(dds3ObjectBaseControlWorkData_t **pControl);
dds3ObjectBaseControlWorkData_t *dds3ObjectBaseInitControlWorkData(dds3Basic_t **pObjectBasic);
void evtLinkLightObjectBasic(evtUnitHandle_t **h, dds3Basic_t **light, s32 frame);
void evtUnlinkLightObjectBasic(evtUnitHandle_t **h, s32 frame);

// 0x14e5d30
dds3Basic_t *dds3AddLightObjectBasic(u32 serial) {
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = 0;
  pObjectBasic = dds3AddSceneBasicData(9u);
  pObjectBasic->serialID = serial;
  dds3ObjectBaseCreateMover(&pObjectBasic);
  return pObjectBasic;
}

// 0x14e6070
void dds3DeleteLightObjectBasic(dds3Basic_t **basic) {
  dds3Basic_t_o **v3;

  else
  {
    v3 = basic;
  }
  dds3DeleteSceneBasicData(v3);
}

// 0x14e5c40
dds3ObjectBaseControlWorkData_t *dds3LightObjectBasicGetControlWorkData(dds3Basic_t **basic) {
  dds3ObjectBaseControlWorkData_t_o **workdata;
  dds3ObjectBaseControlWorkData_t_o *v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  workdata = (*basic)->workdata;
  v4 = *workdata;
  if (LOBYTE((*workdata)[2].MotMode) < typeHierarchyDepth
    || *(v4[1].sdwnodeidx + typeHierarchyDepth - 1) != dds3LightObjectBasicWorkData_t)
  {
    sub_8FC2C0(v4->pModelRangeRootNode, dds3LightObjectBasicWorkData_t, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  return workdata[10];
}

// 0x14e65c0
void dds3LinkLightObjectToUnitObject(dds3Basic_t **lightbasic, dds3Basic_t **unitbasic, u32 frame) {
  dds3Basic_t_o **v5;
  evtUnitHandle_t_o **workdata;
  evtUnitHandle_t_o *v8;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  evtUnitHandle_t_o **v12;
  u64 v13[3];

  v5 = unitbasic;
  workdata = (*v5)->workdata;
  if (workdata)
  {
    v8 = *workdata;
    if (LOBYTE((*workdata)->ExBefore) < typeHierarchyDepth
      || *(*&v8->Sin + 8 * typeHierarchyDepth - 8) != dds3UnitObjectBasicWorkData_t)
    {
      sub_8FC2C0(*&v8->TargetLightDir.x, dds3UnitObjectBasicWorkData_t, v13);
      if ((v13[0] & 1) != 0)
        v10 = v13[2];
      else
        v10 = v13 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  v12 = workdata + 4;
  evtLinkLightObjectBasic(v12, lightbasic, frame);
}

// 0x14e6300
void dds3LinkSceneLight(dds3Basic_t **basic, u32 frame) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  s32 monitor_high;
  struct sdf3DLight_t_array *dds3DirLights;
  u64 v15[3];

  if (*basic)
  {
    workdata = (*basic)->workdata;
    if (workdata)
    {
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3LightObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3LightObjectBasicWorkData_t, v15);
        if ((v15[0] & 1) != 0)
          v9 = v15[2];
        else
          v9 = v15 + 1;
        v10 = sub_8C4940(v9);
      }
      monitor_high = HIDWORD(workdata[3].monitor);
      HIDWORD(workdata[3].monitor) = monitor_high | 1;
      if (frame)
      {
        HIDWORD(workdata[3].monitor) = monitor_high | 3;
        LOWORD(workdata[4].monitor) = frame;
        SDF_VU0__LOADVECTOR(dds3DirLights->m_Items[0]->color);
        LODWORD(workdata[4].klass) = SDF_VU0__dds3ColorFtoI(128.0);
        SDF_VU0__LOADVECTOR(dds3Ambient);
        HIDWORD(workdata[4].klass) = SDF_VU0__dds3ColorFtoI(128.0);
      }
      else
      {
        HIDWORD(workdata[3].monitor) = monitor_high & 0xFFFFFFFC | 1;
      }
    }
  }
}

// 0x14e6a30
void dds3SetLightObjectPathResoruce(dds3Basic_t **basic, fldResourceLightPath_t *resource) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s64 p_monitor;
  char *v9;
  s64 *v10;
  u64 v11[3];

  workdata = (*basic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3LightObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3LightObjectBasicWorkData_t, v11);
    if ((v11[0] & 1) != 0)
      v9 = v11[2];
    else
      v9 = v11 + 1;
    v10 = sub_8C4940(v9);
  }
  *&workdata[2].monitor = resource->InsideR;
  HIDWORD(workdata[2].monitor) = LODWORD(resource->OutsideR);
  *&workdata[3].klass = resource->Soften;
  HIDWORD(workdata[3].klass) = LODWORD(resource->Bias);
  sub_854930(&workdata[1].klass->_1.name, 0);
  sub_854930(&workdata[1].klass->_1.name, 1u);
  sub_854930(&workdata[1].klass->_1.name, 2u);
  sub_854930(&workdata[1].klass->_1.name, 3u);
  p_monitor = &workdata[1].monitor;
  sub_854930(p_monitor, 0);
  sub_854930(p_monitor, 1u);
  sub_854930(p_monitor, 2u);
  sub_854930(p_monitor, 3u);
}

// 0x14e6830
void dds3SetLightObjectResoruce(dds3Basic_t **basic, fldResourceLight_t *resource) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u32 v10;
  s64 p_monitor;
  u64 v12[3];

  if (*basic)
  {
    workdata = (*basic)->workdata;
    if (workdata)
    {
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3LightObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3LightObjectBasicWorkData_t, v12);
        if ((v12[0] & 1) != 0)
          v8 = v12[2];
        else
          v8 = v12 + 1;
        v9 = sub_8C4940(v8);
      }
      HIDWORD(workdata[3].monitor) = 0;
      v10 = resource->Flag & 1;
      HIDWORD(workdata[3].monitor) = v10;
      if ((resource->Flag & 2) != 0)
        HIDWORD(workdata[3].monitor) = v10 | 4;
      LODWORD(workdata[3].monitor) = resource->AnimeType;
      *&workdata[2].monitor = resource->InsideR;
      HIDWORD(workdata[2].monitor) = LODWORD(resource->OutsideR);
      *&workdata[3].klass = resource->Soften;
      HIDWORD(workdata[3].klass) = LODWORD(resource->Bias);
      sub_854930(&workdata[1].klass->_1.name, 0);
      sub_854930(&workdata[1].klass->_1.name, 1u);
      sub_854930(&workdata[1].klass->_1.name, 2u);
      sub_854930(&workdata[1].klass->_1.name, 3u);
      p_monitor = &workdata[1].monitor;
      sub_854930(p_monitor, 0);
      sub_854930(p_monitor, 1u);
      sub_854930(p_monitor, 2u);
      sub_854930(p_monitor, 3u);
    }
  }
}

// 0x14e6700
void dds3UnlinkLightObjectFromUnitObject(dds3Basic_t **unitbasic, u32 frame) {
  s32 v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  evtUnitHandle_t_o **v10;
  u64 v11[3];

  v3 = frame;
  workdata = (*unitbasic)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = &workdata[2];
  evtUnlinkLightObjectBasic(v10, v3);
}

// 0x14e64d0
void dds3UnlinkSceneLight(dds3Basic_t **basic) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v8[3];

  workdata = (*basic)->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3LightObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3LightObjectBasicWorkData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  HIDWORD(workdata[3].monitor) &= 0xFFFFFFFC;
}

// 0x14e5160
s32 lightconstructor(dds3Basic_t *basic) {
  u64 *v2;
  dds3ObjectBaseControlWorkData_t_o *BaseControlWorkData;
  s64 v6;
  u64 *v7;
  dds3Basic_t_o *basica;

  basica = basic;
  dds3InitPoseSet(&basica);
  v2 = Allocate(dds3LightObjectBasicWorkData_t);
  dds3LightObjectBasicWorkData_t___ctor(v2);
  basica->workdata = v2;
  v2[10] = dds3ObjectBaseInitControlWorkData(&basica);
  BaseControlWorkData = dds3GetBaseControlWorkData(&basica);
  BaseControlWorkData->flag |= 0x62u;
  v6 = v2[2] + 16;
  *(v2 + 15) = 0;
  sub_854930(v6, 0);
  sub_854930(v2[2] + 16, 1u);
  sub_854930(v2[2] + 16, 2u);
  sub_854930(v2[2] + 16, 3u);
  sub_854930(v2[2] + 32, 0);
  sub_854930(v2[2] + 32, 1u);
  sub_854930(v2[2] + 32, 2u);
  sub_854930(v2[2] + 32, 3u);
  sub_854930((v2 + 3), 0);
  sub_854930((v2 + 3), 1u);
  sub_854930((v2 + 3), 2u);
  sub_854930((v2 + 3), 3u);
  v2[5] = 0x4448000042C80000LL;
  v2[6] = 1088421888;
  v7 = Allocate(sdf3DLightParallelPacket_t);
  sdf3DLightParallelPacket_t___ctor(v7);
  v2[11] = v7;
  return 1;
}

// 0x14e5610
s32 lightdestructor(dds3Basic_t *basic) {
  dds3ObjectBaseControlWorkData_t_o **workdata;
  dds3ObjectBaseControlWorkData_t_o *v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3Basic_t_o *v10;
  u64 v11[3];

  v10 = basic;
  workdata = basic->workdata;
  if (workdata)
  {
    v4 = *workdata;
    if (LOBYTE((*workdata)[2].MotMode) < typeHierarchyDepth
      || *(v4[1].sdwnodeidx + typeHierarchyDepth - 1) != dds3LightObjectBasicWorkData_t)
    {
      sub_8FC2C0(v4->pModelRangeRootNode, dds3LightObjectBasicWorkData_t, v11);
      if ((v11[0] & 1) != 0)
        v6 = v11[2];
      else
        v6 = v11 + 1;
      v7 = sub_8C4940(v6);
    }
    dds3ObjectBaseFreeControlWorkData(workdata + 10, dds3LightObjectBasicWorkData_t);
    basic->workdata = 0;
    dds3FreePoseSet(&v10);
  }
  return 0;
}

// 0x14e5c30
s32 lightdrawprocedure(dds3Basic_t *basic) {
  return 1;
}

// 0x14e5920
s32 lightmainprocedure(dds3Basic_t *basic) {
  u64 *v3;
  Il2CppObject *workdata;
  u64 *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s32 monitor_high;
  u32 monitor_low;
  f32 v13;
  struct sdf3DLight_t_array *dds3DirLights;
  s64 *v16;
  u64 v20[3];

  v3 = NewSpecific(sdf3DLight_t, 3u);
  workdata = basic->workdata;
  v5 = v3;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3LightObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3LightObjectBasicWorkData_t, v20);
      if ((v20[0] & 1) != 0)
        v8 = v20[2];
      else
        v8 = v20 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  monitor_high = HIDWORD(workdata[3].monitor);
  if ((monitor_high & 1) != 0)
  {
    if ((monitor_high & 2) != 0)
    {
      monitor_low = LOWORD(workdata[4].monitor);
      if (LOWORD(workdata[4].monitor))
      {
        v13 = 1.0 / monitor_low;
        LOWORD(workdata[4].monitor) = monitor_low - 1;
      }
      else
      {
        HIDWORD(workdata[3].monitor) = monitor_high & 0xFFFFFFFD;
        v13 = 1.0;
      }
      SDF_VU0__dds3ColorItoF(workdata[4].klass);
      SDF_VU0__SCALEVECTOR(1.0 - v13);
      SDF_VU0__LOADVECTOR_B(*&workdata[1].klass->_1.name);
      SDF_VU0__SCALEVECTOR_B(v13);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_C();
      LODWORD(workdata[4].klass) = SDF_VU0__dds3ColorFtoI(128.0);
      SDF_VU0__dds3ColorItoF(HIDWORD(workdata[4].klass), 0);
      SDF_VU0__SCALEVECTOR(1.0 - v13);
      SDF_VU0__LOADVECTOR_B(*(workdata + 24), 0);
      SDF_VU0__SCALEVECTOR_B(v13);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__COPYVECTOR_A_TO_B();
      HIDWORD(workdata[4].klass) = SDF_VU0__dds3ColorFtoI(128.0);
      SDF_VU0__COPYVECTOR_C_TO_A();
    }
    else
    {
      SDF_VU0__LOADVECTOR(*&workdata[1].klass->_1.name);
      SDF_VU0__LOADVECTOR_B(*(workdata + 24), 0);
    }
    else
    {
      if (!LODWORD(dds3DirLights->max_length))
        goto LABEL_20;
    }
    SDF_VU0__STOREVECTOR(&dds3DirLights->m_Items[0]->color);
    SDF_VU0__STOREVECTOR_B(&dds3Ambient);
  }
  v16 = workdata[1].klass;
  v5[4] = v16;
  return 1;
}
