#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3PathBasicControl_t dds3PathBasicControl_t;
typedef struct effSpline_t effSpline_t;
typedef struct fldResourceLightPath_t fldResourceLightPath_t;
typedef struct fldResourcePathData_t fldResourcePathData_t;

void GetElement(u32 *segment, f32 *weight, fldResourcePathData_t *pData, f32 frame);
void Lerp(f32 aRatio);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
f32 SDF_VU0__GETVECTOR_W(void);
f32 SDF_VU0__GETVECTOR_X(void);
f32 SDF_VU0__GETVECTOR_Y(void);
f32 SDF_VU0__GETVECTOR_Z(void);
void SDF_VU0__LOADIDENTITYVECTOR(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SETVECTOR_W(f32 v);
void SDF_VU0__SETVECTOR_X(f32 v);
void SDF_VU0__SETVECTOR_Y(f32 v);
void SDF_VU0__SETVECTOR_Z(f32 v);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
dds3Basic_t *dds3AddSceneBasicData(u32 type);
void dds3PathBasicControl_t__Clear(dds3PathBasicControl_t *this);
effSpline_t *effSplInitialize2(sdfVector3_t **ppoint, u32 numpoint, s32 bogus);

// 0x14f73e0
void GetElement(u32 *segment, f32 *weight, fldResourcePathData_t *pData, f32 frame) {
  u32 v5;
  struct System_UInt32_array *pKey;
  f32 v7;
  u64 v8;
  char *v10;
  u64 v11;
  u64 v12;
  f64 v13;
  u32 v15;
  f64 v16;
  u32 nKey;
  f32 v18;
  u32 max_length;
  f64 v22;
  f32 v24;

  if (pData->nKey == 1)
  {
    v5 = -1;
LABEL_12:
    v18 = 1.0;
    *segment = v5;
  }
  else
  {
    pKey = pData->pKey;
    v7 = frame;
    v8 = 0;
    while (1)
    {
      v10 = pKey + 4 * v8;
      LODWORD(v11) = *(v10 + 8);
      v12 = v8 + 1;
      v13 = v11;
      frame = v13;
      if (frame <= v7)
      {
        v15 = *(v10 + 9);
        v16 = v15;
        frame = v15;
        if (frame > v7)
          break;
      }
      nKey = pData->nKey;
      ++v8;
      if (v12 >= nKey - 1)
      {
        v5 = nKey - 2;
        goto LABEL_12;
      }
    }
    max_length = pKey->max_length;
    v22 = (v15 - *(v10 + 8));
    *&v22 = v22;
    *weight = 1.0 / *&v22;
    *segment = v8;
    LODWORD(v22) = *(v10 + 8);
    v24 = *&v22;
    v18 = *weight * (v7 - v24);
  }
  *weight = v18;
}

// 0x14f7570
dds3Basic_t *dds3AddPathBasic(u32 serialID, void *pData, char *pName) {
  dds3Basic_t_o *result;

  result = dds3AddSceneBasicData(0x10u, pData);
  result->serialID = serialID;
  result->name = pName;
  result->workdata = pData;
  return result;
}

// 0x14f7600
void dds3PathBasicControlAlterMode(dds3PathBasicControl_t **pControl, u32 mode) {
  (*pControl)->mode = mode;
}

// 0x14ec7a0
f32 dds3PathBasicControlGetFovy(dds3PathBasicControl_t **pControl) {
  dds3PathBasicControl_t_o *v3;
  fldResourcePathData_t_o *pFovy;
  fldResourcePathData_t_c *klass;
  u32 namespaze;
  s64 v9;
  f32 v11;
  f32 v12;
  s64 weight;

  weight = 0;
  v3 = *pControl;
  if (((*pControl)->flag & 4) == 0)
    return 0.0;
  pFovy = v3->pFovy;
  GetElement(&weight + 1, &weight, pFovy, v3->frame);
  klass = pFovy[1].klass;
  if (HIDWORD(weight) == -1)
  {
    v12 = 1.0 - *&weight;
    v11 = *&weight * *&klass->_1.byval_arg.data;
  }
  else
  {
    namespaze = klass->_1.namespaze;
    v9 = SHIDWORD(weight) + 1LL;
    v11 = *&weight * *(&klass->_1.byval_arg.data + v9);
    v12 = *(&klass->_1.byval_arg.data + HIDWORD(weight)) * (1.0 - *&weight);
  }
  return v12 + v11;
}

// 0x14ec8a0
void dds3PathBasicControlGetLight(dds3PathBasicControl_t **pControl, fldResourceLightPath_t **resource) {
  dds3PathBasicControl_t_o *v4;
  fldResourcePathData_t_o *pLight;
  fldResourceLightPath_t_o *v6;
  fldResourcePathData_t_c *klass;
  s64 v8;
  u32 v9;
  void **v11;
  void **v12;
  f32 *v13;
  f32 v17;
  void **v19;
  char *v20;
  f32 *v21;
  f32 v25;
  s64 weight;

  weight = 0;
  v4 = *pControl;
  if (((*pControl)->flag & 0x10) != 0)
  {
    pLight = v4->pLight;
    v6 = *resource;
    GetElement(&weight + 1, &weight, pLight, v4->frame);
    klass = pLight[1].klass;
    v8 = HIDWORD(weight);
    v9 = HIDWORD(weight) + 1;
    v11 = &klass->_1.gc_desc + HIDWORD(weight);
    v13 = v11[4];
    v12 = v11 + 4;
    SDF_VU0__SETVECTOR_X(v13[4]);
    SDF_VU0__SETVECTOR_Y(*(*v12 + 5), 0);
    SDF_VU0__SETVECTOR_Z(*(*v12 + 6), 0);
    SDF_VU0__SETVECTOR_W(*(*v12 + 7), 0);
    v17 = *&weight;
    SDF_VU0__SCALEVECTOR(*&weight);
    SDF_VU0__COPYVECTOR_A_TO_B();
    v19 = &klass->_1.image + v8;
    v21 = v19[4];
    v20 = (v19 + 4);
    SDF_VU0__SETVECTOR_X(v21[4]);
    SDF_VU0__SETVECTOR_Y(*(*v20 + 20LL), 0);
    SDF_VU0__SETVECTOR_Z(*(*v20 + 24LL), 0);
    SDF_VU0__SETVECTOR_W(*(*v20 + 28LL), 0);
    v25 = 1.0 - v17;
    SDF_VU0__SCALEVECTOR(1.0 - v17);
    SDF_VU0__ADDVECTOR();
    v6->InsideR = SDF_VU0__GETVECTOR_X();
    v6->OutsideR = SDF_VU0__GETVECTOR_Y();
    v6->Soften = SDF_VU0__GETVECTOR_Z();
    v6->Bias = SDF_VU0__GETVECTOR_W();
    SDF_VU0__SETVECTOR_X(*(*v12 + 8), 0);
    SDF_VU0__SETVECTOR_Y(*(*v12 + 9), 0);
    SDF_VU0__SETVECTOR_Z(*(*v12 + 10), 0);
    SDF_VU0__SCALEVECTOR(v17);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__SETVECTOR_X(*(*v20 + 32LL), 0);
    SDF_VU0__SETVECTOR_Y(*(*v20 + 36LL), 0);
    SDF_VU0__SETVECTOR_Z(*(*v20 + 40LL), 0);
    SDF_VU0__SCALEVECTOR(v25);
    SDF_VU0__ADDVECTOR();
    v6->DiffuseR = SDF_VU0__GETVECTOR_X();
    v6->DiffuseG = SDF_VU0__GETVECTOR_Y();
    v6->DiffuseB = SDF_VU0__GETVECTOR_Z();
    SDF_VU0__SETVECTOR_X(*(*v12 + 11), 0);
    SDF_VU0__SETVECTOR_Y(*(*v12 + 12), 0);
    SDF_VU0__SETVECTOR_Z(*(*v12 + 13), 0);
    SDF_VU0__SCALEVECTOR(v17);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__SETVECTOR_X(*(*v20 + 44LL), 0);
    SDF_VU0__SETVECTOR_Y(*(*v20 + 48LL), 0);
    SDF_VU0__SETVECTOR_Z(*(*v20 + 52LL), 0);
    SDF_VU0__SCALEVECTOR(v25);
    SDF_VU0__ADDVECTOR();
    v6->AmbientR = SDF_VU0__GETVECTOR_X();
    v6->AmbientG = SDF_VU0__GETVECTOR_Y();
    v6->AmbientB = SDF_VU0__GETVECTOR_Z();
  }
}

// 0x14ec4d0
void dds3PathBasicControlGetPos(dds3PathBasicControl_t **pControl) {
  dds3PathBasicControl_t_o *v4;
  fldResourcePathData_t_o *pTransrate;
  f32 *klass;
  s64 v8;
  u32 v9;
  f32 *v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 *v16;
  f32 z;
  f32 y;
  f32 x;
  f32 v21;
  s64 weight;
  UnityEngine_Vector3_o zero;

  weight = 0;
  v4 = *pControl;
  if (((*pControl)->flag & 1) != 0)
  {
    pTransrate = v4->pTransrate;
    GetElement(&weight + 1, &weight, pTransrate, v4->frame);
    klass = pTransrate[1].klass;
    if (HIDWORD(weight) == -1)
    {
      v14 = klass[8];
      v13 = klass[9];
      v12 = klass[10];
      zero = get_zero();
      x = zero.x;
      y = zero.y;
      z = zero.z;
    }
    else
    {
      v8 = SHIDWORD(weight) + 1LL;
      v9 = *(klass + 6);
      v11 = &klass[3 * v8];
      v12 = v11[10];
      v14 = v11[8];
      v13 = v11[9];
      v16 = &klass[3 * HIDWORD(weight)];
      z = v16[10];
      x = v16[8];
      y = v16[9];
    }
    SDF_VU0__SETVECTOR_X(v14);
    SDF_VU0__SETVECTOR_Y(v13);
    SDF_VU0__SETVECTOR_Z(v12);
    v21 = *&weight;
    SDF_VU0__SCALEVECTOR(*&weight);
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__SETVECTOR_X(x);
    SDF_VU0__SETVECTOR_Y(y);
    SDF_VU0__SETVECTOR_Z(z);
    SDF_VU0__SCALEVECTOR(1.0 - v21);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__VECTOR_W_SET_ZERO();
  }
  else
  {
    SDF_VU0__LOADIDENTITYVECTOR();
  }
}

// 0x14f7640
f32 dds3PathBasicControlGetRatio(dds3PathBasicControl_t **pControl) {
  return (*pControl)->frame / (*pControl)->frameMax;
}

// 0x14ec6b0
void dds3PathBasicControlGetRot(dds3PathBasicControl_t **pControl) {
  dds3PathBasicControl_t_o *v3;
  fldResourcePathData_t_o *pRotation;
  s32 v5;
  fldResourcePathData_t_c *klass;
  s64 v8;
  s64 weight;

  weight = 0;
  v3 = *pControl;
  if (((*pControl)->flag & 2) != 0)
  {
    pRotation = v3->pRotation;
    GetElement(&weight + 1, &weight, pRotation, v3->frame);
    v5 = HIDWORD(weight);
    klass = pRotation[1].klass;
    if (HIDWORD(weight) == -1)
    {
      SDF_VU0__LOADIDENTITYVECTOR();
    }
    else
    {
      SDF_VU0__LOADVECTOR(*(&klass->_1.byval_arg + HIDWORD(weight)), 0);
    }
    v8 = v5 + 1LL;
    SDF_VU0__LOADVECTOR_B(*(&klass->_1.byval_arg + v8), 0);
    Lerp(*&weight, 0);
  }
  else
  {
    SDF_VU0__LOADIDENTITYVECTOR();
  }
}

// 0x14ece10
u32 dds3PathBasicControlNextStep(dds3PathBasicControl_t **pControl) {
  dds3PathBasicControl_t_o *v2;
  u32 flag;
  u32 mode;
  f32 v5;
  f32 frame;

  v2 = *pControl;
  flag = (*pControl)->flag;
  if ((flag & 8) != 0)
    return 1;
  mode = v2->mode;
  if (mode == 1)
  {
    frame = v2->frame;
    if (frame > 0.0)
    {
      v2->frame = frame + -1.0;
      return 1;
    }
    if ((flag & 0x20) == 0)
      return 0;
    v2->frame = v2->frameMax;
    return 1;
  }
  if (mode)
    return 1;
  v5 = v2->frame;
  if (v2->frameMax <= v5)
  {
    if ((flag & 0x20) != 0)
    {
      v2->frame = 0.0;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v2->frame = v5 + 1.0;
    return 1;
  }
}

// 0x14f7620
void dds3PathBasicControlSetRatio(dds3PathBasicControl_t **pControl, f32 ratio) {
  (*pControl)->frame = (*pControl)->frameMax * ratio;
}

// 0x14ed870
void dds3PathBasicFreeControl(dds3PathBasicControl_t **pControl) {
  ;
}

// 0x14f76b0
void dds3PathBasicLoopOff(dds3PathBasicControl_t **pControl) {
  (*pControl)->flag &= ~0x20u;
}

// 0x14f7690
void dds3PathBasicLoopOn(dds3PathBasicControl_t **pControl) {
  (*pControl)->flag |= 0x20u;
}

// 0x14ed880
dds3PathBasicControl_t *dds3PathBasicMakeControl(dds3Basic_t **pBasic) {
  u64 *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 *v9;
  f64 v11;
  u64 v12;
  u64 v13;
  u64 v14;
  u64 *monitor;
  s64 v17;
  u64 v18;
  s64 v19;
  s64 v20;
  char *v21;
  s64 *v22;
  UnityEngine_Vector3_array *v23;
  u32 v24;
  s64 v25;
  s64 v26;
  char *v27;
  s64 *v28;
  s64 v29;
  s64 v30;
  char *v31;
  s64 *v32;
  s64 v33;
  s64 v34;
  char *v35;
  s64 *v36;
  s64 v37;
  s64 v38;
  u64 v41[2];
  char *v42;

  v3 = Allocate(fldResourcePathData_t);
  fldResourcePathData_t___ctor(v3);
  workdata = (*pBasic)->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fldResourcePathTableInfo_t)
    {
      sub_8FC2C0(klass->_1.element_class, fldResourcePathTableInfo_t, v41);
      if ((v41[0] & 1) != 0)
        v7 = v42;
      else
        v7 = v41 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  if (!LODWORD(workdata[1].klass))
    return 0;
  v9 = Allocate(dds3PathBasicControl_t);
  dds3PathBasicControl_t___ctor(v9);
  dds3PathBasicControl_t__Clear(v9);
  *(v9 + 4) = 0;
  v9[3] = 0;
  if (LODWORD(workdata[1].klass))
  {
    v12 = 0;
    do
    {
      monitor = workdata[1].monitor;
      v17 = monitor[v12 + 4];
      v18 = *(v17 + 24);
      switch (*(v17 + 16))
      {
        case 0:
          *(v9 + 5) |= 1u;
          if (v18)
          {
            v19 = *v18;
            if (*(*v18 + 288LL) < v20
              || *(*(v19 + 200) + 8 * v20 - 8) != fldResourcePathData_t_Vector3)
            {
              sub_8FC2C0(*(v19 + 64), fldResourcePathData_t_Vector3, v41);
              if ((v41[0] & 1) != 0)
                v21 = v42;
              else
                v21 = v41 + 1;
              v22 = sub_8C4940(v21);
            }
            v13 = v18;
          }
          else
          {
            v13 = 0;
          }
          v9[5] = v13;
          v23 = *(v13 + 40);
          v24 = *(v13 + 16);
          v9[4] = effSplInitialize2(v23, v24, 1);
          break;
        case 2:
          *(v9 + 5) |= 2u;
          if (v18)
          {
            v25 = *v18;
            if (*(*v18 + 288LL) < v26
              || *(*(v25 + 200) + 8 * v26 - 8) != fldResourcePathData_t_Vector4)
            {
              sub_8FC2C0(*(v25 + 64), fldResourcePathData_t_Vector4, v41);
              if ((v41[0] & 1) != 0)
                v27 = v42;
              else
                v27 = v41 + 1;
              v28 = sub_8C4940(v27);
            }
            v9[6] = v18;
          }
          else
          {
            v9[6] = 0;
          }
          break;
        case 4:
          *(v9 + 5) |= 4u;
          if (v18)
          {
            v29 = *v18;
            if (*(*v18 + 288LL) < v30 || *(*(v29 + 200) + 8 * v30 - 8) != fldResourcePathData_t_Float)
            {
              sub_8FC2C0(*(v29 + 64), fldResourcePathData_t_Float, v41);
              if ((v41[0] & 1) != 0)
                v31 = v42;
              else
                v31 = v41 + 1;
              v32 = sub_8C4940(v31);
            }
            v14 = v18;
          }
          else
          {
            v14 = 0;
          }
          v9[7] = v14;
          break;
        case 5:
          *(v9 + 5) |= 0x10u;
          if (v18)
          {
            v33 = *v18;
            if (*(*v18 + 288LL) < v34 || *(*(v33 + 200) + 8 * v34 - 8) != fldResourcePathData_t_Light)
            {
              sub_8FC2C0(*(v33 + 64), fldResourcePathData_t_Light, v41);
              if ((v41[0] & 1) != 0)
                v35 = v42;
              else
                v35 = v41 + 1;
              v36 = sub_8C4940(v35);
            }
            v9[8] = v18;
          }
          else
          {
            v9[8] = 0;
          }
          break;
        default:
          break;
      }
      v37 = *(v18 + 32);
      v38 = *(v18 + 16) - 1LL;
      LODWORD(v11) = *(v37 + 4 * v38 + 32);
      v11 = *&v11;
      *&v11 = v11;
      if (*(v9 + 6) < *&v11)
        *(v9 + 6) = LODWORD(v11);
      ++v12;
    }
    while (v12 < LODWORD(workdata[1].klass));
  }
  return v9;
}

// 0x14f7610
u32 dds3PathBasicPathControlGetMode(dds3PathBasicControl_t **pControl) {
  return (*pControl)->mode;
}

// 0x14f7650
void dds3PathBasicPause(dds3PathBasicControl_t **pControl) {
  (*pControl)->flag |= 8u;
}

// 0x14f7670
void dds3PathBasicPauseOff(dds3PathBasicControl_t **pControl) {
  (*pControl)->flag &= ~8u;
}
