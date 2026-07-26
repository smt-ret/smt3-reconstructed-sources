#include "types.h"

typedef struct FLD_SEED_WORK_t FLD_SEED_WORK_t;
typedef struct Sprite3D_t Sprite3D_t;
typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct fldUnitControl_t fldUnitControl_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

static FLD_SEED_WORK_t gFldSeedBuff[UNKNOWN_ARRAY_SIZE];
static sdfMemHandle_t *mhFldSeedBuff;
static s32 gFldSnowMode;
static f32 gFldSnowX;
static f32 gFldSnowZ;
static f32 gFldSnowY;
static f32 gFldSnowYD;
static f32 gFldSnowSpd;
static s32 gFldSnowLife;
static f32 gFldSnowW;
static XRD773Unity_CommonMesh pMesh[UNKNOWN_ARRAY_SIZE];
static s32 SnowDispCount;
static sdfMatrix4_t pMeshMatrix;

void ClearUseIndex(XRD773Unity_CommonMesh *this);
sdfColor_t **GetColor(XRD773Unity_CommonMesh *this);
s32 **GetIndexTable(XRD773Unity_CommonMesh *this);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
sdfVector3_t **GetPosition(XRD773Unity_CommonMesh *this);
s32 GetUseIndex(XRD773Unity_CommonMesh *this);
s32 GetUseIndexMax(XRD773Unity_CommonMesh *this);
sdfVector2_t **GetUvTable(XRD773Unity_CommonMesh *this);
void LookAtMatrix(sdfVector4_t aTarget, sdfVector4_t aEye, sdfVector4_t aDown);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetMatTexture(XRD773Unity_CommonMesh *this, void *texture);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
void SetUseIndex(XRD773Unity_CommonMesh *this, s32 index);
void SetUseIndexMax(XRD773Unity_CommonMesh *this, s32 index);
void SetUvTable_20243232(XRD773Unity_CommonMesh *this, sdfVector2_t **pos);
void dds3GetPosPoseSet(dds3Basic_t **pBasic);
u32 dds3GetRandA(char *name);
bool evtBitCheck(s32 no);
fldUnitControl_t *fldGetUnitControl(void);
void fldSnowSeedAdd(f32 x, f32 y, f32 z);
void fldSnowSeedInit(void);
void fldSnowSeedReset(void);
void fldSnowSprite3D(Sprite3D_t *spr3d);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);

// 0x177aba0
s32 CCOL(s32 r, s32 g, s32 b, s32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x177ab80
f32 CROT(f32 a) {
  return (a * 3.14) / 180.0;
}

// 0x177ab60
u16 CUV(s32 a) {
  return 16 * a;
}

// 0x177ab70
f32 CVT(f32 a) {
  return a * 0.0625;
}

// 0x1778700
void fldSnowFree(void) {
}

// 0x1777680
void fldSnowInit(void) {
  fldGlobal_c *v3;
  s16 v4;
  s32 v5;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  struct fldGlobal_StaticFields *static_fields;
  u64 *v17;

  else if (gFldSeedBuff)
  {
    return;
  }
  if (evtBitCheck(22) && !evtBitCheck(62))
  {
    if ((v4 & 0x200) != 0)
    {
      v5 = v4 & 0x200;
    }
    else
    {
      v5 = 0;
    }
    fieldID = fldGb->fieldID;
    if (fieldID == 31)
    {
      if (fldGb->areaID != 14)
      {
        gFldSnowMode = 0;
        gFldSnowX = -640.0;
        gFldSnowZ = -640.0;
        gFldSnowY = -6900.0;
        gFldSnowYD = 10000.0;
        gFldSnowSpd = 4.0;
        gFldSnowLife = 1500;
        gFldSnowW = 5.0;
        if (!fldGb->areaID)
        {
          gFldSnowYD = 10.0;
        }
        v17 = NewSpecific(FLD_SEED_WORK_t, 0x2BCu);
        v18[2].klass->_1.image = v17;
        fldSnowSeedInit();
        fldSnowSeedReset();
      }
    }
    else
    {
      if (fieldID == 24)
      {
        areaID = fldGb->areaID;
        if (areaID != 17)
        {
          if (areaID != 24)
          {
            gFldSnowMode = 1;
            gFldSnowY = 100.0;
            gFldSnowYD = 10000.0;
            gFldSnowSpd = -3.0;
            gFldSnowLife = 240;
            gFldSnowW = 25.0;
            if (fldGb->areaID == 5)
            {
              gFldSnowY = 800.0;
              gFldSnowLife = 450;
            }
            if (fldGb->areaID == 9)
            {
              gFldSnowLife = 300;
              gFldSnowW = 23.0;
            }
            static_fields = v3->static_fields;
            if (static_fields->fldGb->areaID == 21)
            {
              gFldSnowW = 15.0;
            }
            gFldSnowX = (gFldSnowW * 256.0) * -0.5;
            gFldSnowZ = (gFldSnowW * 256.0) * -0.5;
          }
        }
      }
    }
  }
}

// 0x1779380
void fldSnowSeedAdd(f32 x, f32 y, f32 z) {
  fldSnow_c *v8;
  u64 v9;
  struct FLD_SEED_WORK_t_array *gFldSeedBuff;
  u32 *v14;
  u64 *v15;
  struct FLD_SEED_WORK_t_array *v17;
  fldSnow_c *v20;
  struct FLD_SEED_WORK_t_array *v21;
  struct FLD_SEED_WORK_t_array *v23;
  struct FLD_SEED_WORK_t_array *v25;
  struct fldSnow_StaticFields *static_fields;
  struct FLD_SEED_WORK_t_array *v29;
  struct FLD_SEED_WORK_t_array *v31;
  struct FLD_SEED_WORK_t_array *v33;
  FLD_SEED_WORK_t_o *v35;
  struct FLD_SEED_WORK_t_array *v36;
  FLD_SEED_WORK_t_o *v38;

  if (gFldSeedBuff)
  {
    v9 = 0;
    if ((v8->_2.bitflags2 & 2) == 0)
    while (1)
    {
      if (gFldSeedBuff->m_Items[v9])
        break;
      v14 = gFldSeedBuff;
      v15 = Allocate(FLD_SEED_WORK_t);
      _ctor(v15, 0);
      *&v14[2 * v9 + 8] = v15;
      v17 = gFldSeedBuff;
      if (!v17->m_Items[v9]->flg)
      {
        v21 = gFldSeedBuff;
        v21->m_Items[v9]->x = x;
        v23 = gFldSeedBuff;
        v23->m_Items[v9]->y = y;
        v25 = gFldSeedBuff;
        v25->m_Items[v9]->z = z;
        static_fields = v20->static_fields;
        static_fields->gFldSeedBuff->m_Items[v9]->life = static_fields->gFldSnowLife;
        v29 = gFldSeedBuff;
        v29->m_Items[v9]->flg = 1;
        v31 = gFldSeedBuff;
        v31->m_Items[v9]->alp = 128;
        v33 = gFldSeedBuff;
        v35 = v33->m_Items[v9];
        v35->spd = dds3GetRandA(StringLiteral_416) & 0x1F;
        v36 = gFldSeedBuff;
        v38 = v36->m_Items[v9];
        v38->rgbofs = dds3GetRandA(StringLiteral_416) & 0xF;
        return;
      }
      if (v9 > 0x2BA)
        return;
      ++v9;
    }
  }
}

// 0x17797a0
void fldSnowSeedDel(s32 i) {
}

// 0x1777b10
void fldSnowSeedInit(void) {
  fldSnow_c *v2;
  s64 v3;
  u64 v4;
  u32 *gFldSeedBuff;
  u64 *v6;
  struct FLD_SEED_WORK_t_array *v8;

  else if (!gFldSeedBuff)
  {
    return;
  }
  v3 = 4;
  if ((v2->_2.bitflags2 & 2) == 0)
  while (1)
  {
    v4 = v3 - 4;
    v6 = Allocate(FLD_SEED_WORK_t);
    _ctor(v6, 0);
    *&gFldSeedBuff[2 * v3] = v6;
    v8 = gFldSeedBuff;
    *(*(&v8->obj.klass + v3) + 28LL) = 0;
    if (v3 == 703)
      break;
    ++v3;
  }
}

// 0x1777c90
void fldSnowSeedReset(void) {
    dds3GetRandA(0);
    fldSnowSeedAdd(0, 0, 0);
    fldGetUnitControl();
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
}

// 0x17789d0
void fldSnowSprite3D(Sprite3D_t *spr3d) {
    GetUseIndex(0);
    GetUseIndexMax(0);
    GetPosition(0);
    SetPosition_20241056(0, 0);
    SetIndexTable(0, 0);
    SetColor_20241296(0, 0);
    SetUvTable_20243232(0, 0);
    GetColor(0);
    SDF_VU0__Retdds3ColorItoF(0, 0);
    GetIndexTable(0);
    GetUvTable(0);
    SetUseIndex(0, 0);
}

// 0x17789c0
void fldSnowSpriteTex(void **th) {
  ;
}

// 0x1779880
void fldSnowTask(void) {
    dds3GetRandA(0);
    fldSnowSeedAdd(0, 0, 0);
    rsetOtOfs(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    rsetAlpha(0);
    GetMesh(0, 0, 0);
    SetUseIndexMax(0, 0);
    ClearUseIndex(0);
    SetMatTexture(0, 0);
    LookAtMatrix((sdfVector4_t){0}, (sdfVector4_t){0}, (sdfVector4_t){0});
    SDF_VU0__STOREMATRIX(0);
    fldSnowSprite3D(0);
}
