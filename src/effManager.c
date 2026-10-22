#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct dds3Effect_t dds3Effect_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effHandle_t effHandle_t;
typedef struct effManager_dds3EffectMajorTable_t effManager_dds3EffectMajorTable_t;
typedef struct effManager_dds3EffectMajorTable_t_CopyDelegate effManager_dds3EffectMajorTable_t_CopyDelegate;
typedef struct effManager_dds3EffectMajorTable_t_CreateDelegate effManager_dds3EffectMajorTable_t_CreateDelegate;
typedef struct effManager_dds3EffectMajorTable_t_DeleteDelegate effManager_dds3EffectMajorTable_t_DeleteDelegate;
typedef struct effManager_dds3EffectMajorTable_t_DrawDelegate effManager_dds3EffectMajorTable_t_DrawDelegate;
typedef struct effManager_dds3EffectMajorTable_t_GetLoopDelegate effManager_dds3EffectMajorTable_t_GetLoopDelegate;
typedef struct effManager_dds3EffectMajorTable_t_GetStateDelegate effManager_dds3EffectMajorTable_t_GetStateDelegate;
typedef struct effManager_dds3EffectMajorTable_t_GetUseMeshDelegate effManager_dds3EffectMajorTable_t_GetUseMeshDelegate;
typedef struct effManager_dds3EffectMajorTable_t_ResetDelegate effManager_dds3EffectMajorTable_t_ResetDelegate;
typedef struct effManager_dds3EffectMajorTable_t_SetLoopDelegate effManager_dds3EffectMajorTable_t_SetLoopDelegate;
typedef struct effManager_dds3EffectMajorTable_t_SetPosDelegate effManager_dds3EffectMajorTable_t_SetPosDelegate;
typedef struct effManager_dds3EffectMajorTable_t_SetRGBADelegate effManager_dds3EffectMajorTable_t_SetRGBADelegate;
typedef struct effManager_dds3EffectMajorTable_t_SetRotateMatrixDelegate effManager_dds3EffectMajorTable_t_SetRotateMatrixDelegate;
typedef struct effManager_dds3EffectMajorTable_t_SetScaleDelegate effManager_dds3EffectMajorTable_t_SetScaleDelegate;
typedef struct sdfRandCB_t sdfRandCB_t;

struct effManager_dds3EffectMajorTable_t {
    effManager_dds3EffectMajorTable_t_CreateDelegate *Create;
    effManager_dds3EffectMajorTable_t_DrawDelegate *Draw;
    effManager_dds3EffectMajorTable_t_DeleteDelegate *Delete;
    effManager_dds3EffectMajorTable_t_ResetDelegate *Reset;
    effManager_dds3EffectMajorTable_t_GetStateDelegate *GetState;
    effManager_dds3EffectMajorTable_t_SetPosDelegate *SetPos;
    effManager_dds3EffectMajorTable_t_SetRotateMatrixDelegate *SetRotateMatrix;
    effManager_dds3EffectMajorTable_t_SetRGBADelegate *SetRGBA;
    effManager_dds3EffectMajorTable_t_SetLoopDelegate *SetLoop;
    effManager_dds3EffectMajorTable_t_GetLoopDelegate *GetLoop;
    effManager_dds3EffectMajorTable_t_CopyDelegate *Copy;
    effManager_dds3EffectMajorTable_t_SetScaleDelegate *SetScale;
    effManager_dds3EffectMajorTable_t_DrawDelegate *DrawOff;
    effManager_dds3EffectMajorTable_t_GetUseMeshDelegate *GetUseMesh;
};

static sdfRandCB_t *dds3Effect_Rand;
static effManager_dds3EffectMajorTable_t *EffMajorTable[5];

void Eve_EffectDraw(void);
void Eve_EffectInit(void);
s32 SDF_GS_SET_ALPHA(s32 a, s32 b, s32 c, s32 d, s32 fix);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void dds3BillboardLinkOt(void);
void dds3BillboardManagerExit(void);
void dds3BillboardManagerInit(void);
effHandle_t *dds3EffectCreate(u16 major, u16 minor, void *pData, s32 bPos);
void dds3Effect_t__pCopy(dds3Effect_t *this, u8 **bytedata, s32 *pos);
void dds3MultiBillboardLinkOt(void);
void dds3ParticleManagerExit(void);
void dds3ParticleManagerInit(void);
void dds3PolygonLinkOt(void);
void dds3PolygonManagerExit(void);
void dds3PolygonManagerInit(void);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void dds3TrackPolyLinkOt(void);
u32 sdfGetRand(sdfRandCB_t **aCB);
f32 sdfGetRandFloat(sdfRandCB_t **aCB);
void sdfRandomizeByTime(sdfRandCB_t **aCB);

// 0x16b5f50
u64 DDS3EFFECT_BLEND_ADD(void) {
  return SDF_GS_SET_ALPHA(0, 2u, 0, 1u, 0);
}

// 0x16b5f90
u64 DDS3EFFECT_BLEND_NEG(void) {
  return SDF_GS_SET_ALPHA(2u, 1u, 0, 0, 0);
}

// 0x16b5f30
u64 DDS3EFFECT_BLEND_SEMI(void) {
  return SDF_GS_SET_ALPHA(0, 1u, 0, 1u, 0);
}

// 0x16b5f70
u64 DDS3EFFECT_BLEND_SUB(void) {
  return SDF_GS_SET_ALPHA(2u, 0, 0, 1u, 0);
}

// 0x16aa4f0
f32 DDS3EFFECT_RAND_F(void) {
  return sdfGetRandFloat(&dds3Effect_Rand);
}

// 0x16aa580
f32 DDS3EFFECT_RAND_FA(f32 r) {
  return (1.0 - r) + (sdfGetRandFloat(&dds3Effect_Rand) * r);
}

// 0x16ab370
u32 DDS3EFFECT_RAND_I(void) {
  return sdfGetRand(&dds3Effect_Rand);
}

// 0x16abc40
f32 DDS3EFFECT_RAND_PM(void) {
  f32 RandFloat;

  RandFloat = sdfGetRandFloat(&dds3Effect_Rand);
  return (RandFloat + -0.5) + (RandFloat + -0.5);
}

// 0x16b5f20
void dds3CrossfadeRun(void) {
  ;
}

// 0x16babe0
effHandle_t *dds3EffectCopy(void **pData, s32 bPos, bool tbldata) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  effHandle_t_o *v11;
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s64 klass_low;
  struct effManager_dds3EffectMajorTable_t_array *v19;
  s64 v20;
  u64 v23[3];

  v6 = *pData;
  if (!*pData)
    return 0;
  klass = v6->klass;
  if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, effHandle_t, v23);
    if ((v23[0] & 1) != 0)
      v9 = v23[2];
    else
      v9 = v23 + 1;
    v10 = sub_8C4940(v9);
  }
  v11 = Allocate(effHandle_t);
  effHandle_t___ctor(v11);
  v11->major = v6[1].klass;
  v11->minor = HIDWORD(v6[1].klass);
  klass_low = LODWORD(v6[1].klass);
  if (EffMajorTable->m_Items[klass_low]->Copy)
  {
    v19 = EffMajorTable;
    v20 = LODWORD(v6[1].klass);
    v11->pwork = Invoke(
                          v19->m_Items[v20]->Copy,
                          &v6[1].monitor,
                          bPos);
  }
  return v11;
}

// 0x16b64d0
effHandle_t *dds3EffectCreate(u16 major, u16 minor, void *pData, s32 bPos) {
  s64 v8;
  u64 *v9;
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s32 max_length;
  struct effManager_dds3EffectMajorTable_t_array *v17;

  LOWORD(v8) = major;
  v9 = Allocate(effHandle_t);
  effHandle_t___ctor(v9);
  *(v9 + 4) = v8;
  *(v9 + 5) = minor;
  *(v9 + 8) = 1065604874;
  max_length = EffMajorTable->max_length;
  if (max_length <= v8)
    return 0;
  else
  {
    if (max_length <= v8)
      goto LABEL_10;
  }
  if (EffMajorTable->m_Items[v8]->Create)
  {
    v17 = EffMajorTable;
    v9[3] = Invoke(
              v17->m_Items[v8]->Create,
              minor,
              pData,
              bPos);
  }
  return v9;
}

// 0x16babc0
void dds3EffectDataRevision(void *pD3P, s32 bPos) {
  ;
}

// 0x16b6a70
void dds3EffectDelete(void **pData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject **p_monitor;
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s64 klass_low;
  u64 v14[3];

  v4 = *pData;
  if (*pData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effHandle_t, v14);
      if ((v14[0] & 1) != 0)
        v7 = v14[2];
      else
        v7 = v14 + 1;
      v8 = sub_8C4940(v7);
    }
    p_monitor = &v4[1].monitor;
    if (v4[1].monitor)
    {
      klass_low = LODWORD(v4[1].klass);
      Invoke(
        EffMajorTable->m_Items[klass_low]->Delete,
        p_monitor);
    }
  }
}

// 0x16b6f90
void dds3EffectDraw(void **pData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject **p_monitor;
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s64 klass_low;
  u64 v14[3];

  v4 = *pData;
  if (*pData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effHandle_t, v14);
      if ((v14[0] & 1) != 0)
        v7 = v14[2];
      else
        v7 = v14 + 1;
      v8 = sub_8C4940(v7);
    }
    p_monitor = &v4[1].monitor;
    if (v4[1].monitor)
    {
      klass_low = LODWORD(v4[1].klass);
      Invoke(
        EffMajorTable->m_Items[klass_low]->Draw,
        p_monitor);
    }
  }
}

// 0x16b74b0
void dds3EffectDrawOff(void **pData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject **p_monitor;
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s64 klass_low;
  u64 v14[3];

  v4 = *pData;
  if (*pData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effHandle_t, v14);
      if ((v14[0] & 1) != 0)
        v7 = v14[2];
      else
        v7 = v14 + 1;
      v8 = sub_8C4940(v7);
    }
    p_monitor = &v4[1].monitor;
    if (v4[1].monitor)
    {
      klass_low = LODWORD(v4[1].klass);
      Invoke(
        EffMajorTable->m_Items[klass_low]->DrawOff,
        p_monitor);
    }
  }
}

// 0x16babd0
effHandle_t *dds3EffectFileLoad(char *pFilename) {
  return 0;
}

// 0x16ba480
u8 dds3EffectGetLoop(effHandle_t **hEffect) {
  effHandle_t_o *v4;
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s64 major;
  effHandle_t_o *v9;
  struct effManager_dds3EffectMajorTable_t_array *v11;
  s64 v12;

  v4 = *hEffect;
  if (!*hEffect)
    return 0;
  major = v4->major;
  if (!EffMajorTable->m_Items[major]->GetLoop)
    return 0;
  v9 = *hEffect;
  if (!(*hEffect)->pwork)
    return 0;
  v11 = EffMajorTable;
  v12 = v9->major;
  return Invoke(
           v11->m_Items[v12]->GetLoop,
           &v9->pwork);
}

// 0x16b8580
u16 dds3EffectGetState(effHandle_t *hEffect) {
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s64 major;
  Il2CppObject **p_pwork;
  struct effManager_dds3EffectMajorTable_t_array *v10;
  s64 v11;

  if (!hEffect)
    return 0;
  major = hEffect->major;
  if (!EffMajorTable->m_Items[major]->GetState)
    return 0;
  p_pwork = &hEffect->pwork;
  if (!hEffect->pwork)
    return 0;
  v10 = EffMajorTable;
  v11 = hEffect->major;
  return Invoke(v10->m_Items[v11]->GetState, p_pwork);
}

// 0x16b7620
XRD773Unity_CommonMesh **dds3EffectGetUseMesh(void **pData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject **p_monitor;
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s64 klass_low;
  u64 v15[3];

  v4 = *pData;
  if (!*pData)
    return 0;
  klass = v4->klass;
  if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, effHandle_t, v15);
    if ((v15[0] & 1) != 0)
      v7 = v15[2];
    else
      v7 = v15 + 1;
    v8 = sub_8C4940(v7);
  }
  p_monitor = &v4[1].monitor;
  if (!v4[1].monitor)
    return 0;
  klass_low = LODWORD(v4[1].klass);
  return Invoke(
           EffMajorTable->m_Items[klass_low]->GetUseMesh,
           p_monitor);
}

// 0x16ba950
effHandle_t *dds3EffectLoad(void **pD3P, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *v6;
  s64 *Interface;
  char *v8;
  s64 *v9;
  effHandle_t_o *v10;
  u32 major;
  u32 minor;
  Il2CppObject *v15;
  s32 v16;
  effHandle_t_o *v17;
  effHandle_t_o *v18;
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v22;
  s64 *v23;
  u64 v25[2];
  char *v26;
  s32 pos;

  pos = bPos;
  v5 = *pD3P;
  if (!*pD3P)
    return 0;
  Interface = QueryInterface(*pD3P, byte);
  if (!Interface)
  {
    sub_8FC2C0(v5->klass->_1.element_class, v6, v25);
    if ((v25[0] & 1) != 0)
      v8 = v26;
    else
      v8 = v25 + 1;
    v9 = sub_8C4940(v8);
  }
  v10 = Allocate(effHandle_t);
  effHandle_t___ctor(v10);
  dds3Effect_t__pCopy(v10, Interface, &pos);
  if (v10->version < 1.03
  {
  }
  major = v10->major;
  minor = v10->minor;
  v15 = *pD3P;
  v16 = pos;
  v17 = dds3EffectCreate(major, minor, v15, v16);
  v18 = v17;
  if (v10->version <= 1.02)
  {
    pwork = v17->pwork;
    if (pwork)
    {
      klass = pwork->klass;
      if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Particle_Basic_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3Particle_Basic_t, v25);
        if ((v25[0] & 1) != 0)
          v22 = v26;
        else
          v22 = v25 + 1;
        v23 = sub_8C4940(v22);
      }
    }
    if (v17->major <= 2)
      SDF_VU0__STOREIDENTITY(&pwork[6].monitor);
  }
  return v18;
}

// 0x16b6210
void *dds3EffectManagerExit(dds3ProcessID_t *ProcessID) {
  dds3ParticleManagerExit();
  dds3PolygonManagerExit();
  dds3BillboardManagerExit();
  return 0;
}

// 0x16b5fb0
void dds3EffectManagerInit(void) {
  u64 *v1;
  u64 *v7;
  u64 *v9;
  u64 *v10;

  v1 = Allocate(sdfRandCB_t);
  sdfRandCB_t___ctor(v1);
  dds3Effect_Rand = v1;
  sdfRandomizeByTime(&dds3Effect_Rand);
  dds3BillboardManagerInit();
  dds3PolygonManagerInit();
  dds3ParticleManagerInit();
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_effManager_dds3EffectManagerRunF__);
  dds3StartProcess("effect_f", 0x2B04u, 0, 0, v7, 0, 0, 0, 0, 0);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_effManager_dds3EffectManagerRun__);
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_effManager_dds3EffectManagerExit__);
  dds3StartProcess("effect", 0x2B18u, 0, 0, v9, 0, v10, 0, 0, 0);
  Eve_EffectInit();
}

// 0x16b62e0
void *dds3EffectManagerRun(dds3ProcessID_t *ProcessID) {
  dds3PolygonLinkOt();
  dds3TrackPolyLinkOt();
  dds3BillboardLinkOt();
  dds3MultiBillboardLinkOt();
  Eve_EffectDraw();
  return 0;
}

// 0x16b62d0
void *dds3EffectManagerRunF(dds3ProcessID_t *ProcessID) {
  return 0;
}

// 0x16b6410
u8 dds3EffectPCFGetLoop(void **hData) {
  return 1;
}

// 0x16b6490
u16 dds3EffectPCFGetState(void **hData) {
  return 1;
}

// 0x16b6450
void dds3EffectPCFReset(void **hData) {

}

// 0x16b63d0
void dds3EffectPCFSetLoop(void **hData, u8 loop) {

}

// 0x16b7b30
void dds3EffectReset(effHandle_t *hEffect) {
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s64 major;

  if (hEffect)
  {
    major = hEffect->major;
    Invoke(
      EffMajorTable->m_Items[major]->Reset,
      &hEffect->pwork);
  }
}

// 0x16b9f50
void dds3EffectSetLoop(effHandle_t **hEffect, u8 loop) {
  effHandle_t_o *v6;
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s64 major;
  effHandle_t_o *v11;
  struct effManager_dds3EffectMajorTable_t_array *v13;
  s64 v14;

  v6 = *hEffect;
  if (*hEffect)
  {
    major = v6->major;
    if (EffMajorTable->m_Items[major]->SetLoop)
    {
      v11 = *hEffect;
      if ((*hEffect)->pwork)
      {
        v13 = EffMajorTable;
        v14 = v11->major;
        Invoke(
          v13->m_Items[v14]->SetLoop,
          &v11->pwork,
          loop);
      }
    }
  }
}

// 0x16b8a40
void dds3EffectSetPosition(void **pData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppObject *v9;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s64 klass_low;
  Il2CppObject **p_monitor;
  struct effManager_dds3EffectMajorTable_t_array *v21;
  s64 v22;
  u64 v24[3];
  UnityEngine_Vector4_o v25;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  v9 = *pData;
  if (*pData)
  {
    klass = v9->klass;
    if (v9->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effHandle_t, v24);
      if ((v24[0] & 1) != 0)
        v13 = v24[2];
      else
        v13 = v24 + 1;
      v14 = sub_8C4940(v13);
    }
    klass_low = LODWORD(v9[1].klass);
    if (EffMajorTable->m_Items[klass_low]->SetPos)
    {
      p_monitor = &v9[1].monitor;
      if (v9[1].monitor)
      {
        v21 = EffMajorTable;
        v22 = LODWORD(v9[1].klass);
        v25.x = x;
        v25.y = y;
        v25.z = z;
        v25.w = w;
        Invoke(v21->m_Items[v22]->SetPos, p_monitor, v25);
      }
    }
  }
}

// 0x16b9990
void dds3EffectSetRGBA(void **pData, u32 abgr) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s64 klass_low;
  Il2CppObject **p_monitor;
  struct effManager_dds3EffectMajorTable_t_array *v18;
  s64 v19;
  u64 v21[3];

  v6 = *pData;
  if (*pData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effHandle_t, v21);
      if ((v21[0] & 1) != 0)
        v10 = v21[2];
      else
        v10 = v21 + 1;
      v11 = sub_8C4940(v10);
    }
    klass_low = LODWORD(v6[1].klass);
    if (EffMajorTable->m_Items[klass_low]->SetRGBA)
    {
      p_monitor = &v6[1].monitor;
      if (v6[1].monitor)
      {
        v18 = EffMajorTable;
        v19 = LODWORD(v6[1].klass);
        Invoke(
          v18->m_Items[v19]->SetRGBA,
          p_monitor,
          abgr);
      }
    }
  }
}

// 0x16b90e0
void dds3EffectSetRotateMatrix(void **pData, sdfMatrix4_t *pMatrix) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s64 klass_low;
  Il2CppObject **p_monitor;
  struct effManager_dds3EffectMajorTable_t_array *v18;
  s64 v19;
  s64 v21;
  s64 v22;
  s64 v23;
  effManager_dds3EffectMajorTable_t_SetRotateMatrixDelegate_o *SetRotateMatrix;
  s64 v25;
  s64 v26;
  s64 v27;
  UnityEngine_Matrix4x4_o v28;
  u64 v29[3];

  v6 = *pData;
  if (*pData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effHandle_t, v29);
      if ((v29[0] & 1) != 0)
        v10 = v29[2];
      else
        v10 = v29 + 1;
      v11 = sub_8C4940(v10);
    }
    klass_low = LODWORD(v6[1].klass);
    if (EffMajorTable->m_Items[klass_low]->SetRotateMatrix)
    {
      p_monitor = &v6[1].monitor;
      if (v6[1].monitor)
      {
        v18 = EffMajorTable;
        v19 = LODWORD(v6[1].klass);
        v21 = *&pMatrix->m00;
        v22 = *&pMatrix->m20;
        v23 = *&pMatrix->m21;
        SetRotateMatrix = v18->m_Items[v19]->SetRotateMatrix;
        *&v28.m01 = *&pMatrix->m01;
        *&v28.m21 = v23;
        *&v28.m00 = v21;
        *&v28.m20 = v22;
        v25 = *&pMatrix->m02;
        v26 = *&pMatrix->m22;
        v27 = *&pMatrix->m23;
        *&v28.m03 = *&pMatrix->m03;
        *&v28.m23 = v27;
        *&v28.m02 = v25;
        *&v28.m22 = v26;
        Invoke(SetRotateMatrix, p_monitor, &v28);
      }
    }
  }
}

// 0x16b7fa0
void dds3EffectSetScale(void **pData, f32 scale) {
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  struct effManager_dds3EffectMajorTable_t_array *EffMajorTable;
  s64 klass_low;
  Il2CppObject **p_monitor;
  struct effManager_dds3EffectMajorTable_t_array *v18;
  s64 v19;
  u64 v21[3];

  v6 = *pData;
  if (*pData)
  {
    klass = v6->klass;
    if (v6->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, effHandle_t, v21);
      if ((v21[0] & 1) != 0)
        v10 = v21[2];
      else
        v10 = v21 + 1;
      v11 = sub_8C4940(v10);
    }
    klass_low = LODWORD(v6[1].klass);
    if (EffMajorTable->m_Items[klass_low]->SetScale)
    {
      p_monitor = &v6[1].monitor;
      if (v6[1].monitor)
      {
        v18 = EffMajorTable;
        v19 = LODWORD(v6[1].klass);
        Invoke(
          v18->m_Items[v19]->SetScale,
          p_monitor,
          scale);
      }
    }
  }
}
