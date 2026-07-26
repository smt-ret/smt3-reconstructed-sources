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
    return 0;
}

// 0x16b64d0
effHandle_t *dds3EffectCreate(u16 major, u16 minor, void *pData, s32 bPos) {
    return 0;
}

// 0x16babc0
void dds3EffectDataRevision(void *pD3P, s32 bPos) {
  ;
}

// 0x16b6a70
void dds3EffectDelete(void **pData) {
}

// 0x16b6f90
void dds3EffectDraw(void **pData) {
}

// 0x16b74b0
void dds3EffectDrawOff(void **pData) {
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
    return 0;
}

// 0x16ba950
effHandle_t *dds3EffectLoad(void **pD3P, s32 bPos, bool tbldata) {
    dds3Effect_t__pCopy(0, 0, 0);
    dds3EffectCreate(0, 0, 0, 0);
    SDF_VU0__STOREIDENTITY(0);
    return 0;
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
  dds3StartProcess(StringLiteral_15517, 0x2B04u, 0, 0, v7, 0, 0, 0, 0, 0);
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
  dds3StartProcess(StringLiteral_15518, 0x2B18u, 0, 0, v9, 0, v10, 0, 0, 0);
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
}

// 0x16b9990
void dds3EffectSetRGBA(void **pData, u32 abgr) {
}

// 0x16b90e0
void dds3EffectSetRotateMatrix(void **pData, sdfMatrix4_t *pMatrix) {
}

// 0x16b7fa0
void dds3EffectSetScale(void **pData, f32 scale) {
}
