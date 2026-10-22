#include "types.h"

typedef struct FLD_SEED_WORK_t FLD_SEED_WORK_t;
typedef struct Sprite3D_t Sprite3D_t;
typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct fldUnitControl_t fldUnitControl_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

static FLD_SEED_WORK_t *gFldSeedBuff;
static sdfMemHandle_t *mhFldSeedBuff;
static s32 gFldSnowMode;
static f32 gFldSnowX;
static f32 gFldSnowZ;
static f32 gFldSnowY;
static f32 gFldSnowYD;
static f32 gFldSnowSpd;
static s32 gFldSnowLife;
static f32 gFldSnowW;
static XRD773Unity_CommonMesh *pMesh;
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
  fldSnow_c *v2;
  u64 v3;
  s32 v4;
  struct FLD_SEED_WORK_t_array *gFldSeedBuff;
  Il2CppClass **v7;
  u32 v8;
  s64 v11;
  s16 v12;
  u64 v13;
  s32 i;
  struct XRD773Unity_CommonMesh_array *pMesh;
  u64 max_length_low;
  UnityEngine_Object_o *v19;
  struct XRD773Unity_CommonMesh_array *v21;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v25;

  if (gFldSeedBuff)
  {
    v3 = 0;
    v4 = (v2->_2.bitflags2 >> 1) & 1;
    do
    {
      v7 = &gFldSeedBuff->obj.klass + v3++;
      v7[4] = 0;
      v4 = (v8 >> 9) & 1;
    }
    while (v3 != 700);
    gFldSeedBuff = 0;
    mhFldSeedBuff = 0;
    gFldSeedBuff = 0;
    if (pMesh)
    {
      v11 = 4;
      v13 = 0;
      if ((v12 & 0x200) != 0)
        goto LABEL_22;
LABEL_21:
      for (i = 0; ; i = v12 & 0x200)
      {
        max_length_low = LODWORD(pMesh->max_length);
        if (v13 >= max_length_low)
          break;
        else if (v13 >= max_length_low)
        {
          goto LABEL_29;
        }
        v19 = *(&pMesh->obj.klass + v11);
        if (op_Inequality(v19, 0, 0))
        {
          v21 = pMesh;
          gameObject = get_gameObject(*(&v21->obj.klass + v11), 0);
          Destroy_27360000(gameObject);
          v25 = pMesh;
          *(&v25->obj.klass + v11) = 0;
        }
        ++v11;
        v13 = v11 - 4;
        if ((v12 & 0x200) == 0)
          goto LABEL_21;
LABEL_22:
      }
      pMesh = 0;
    }
  }
}

// 0x1777680
void fldSnowInit(void) {
  s16 v4;
  s32 v5;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
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
LABEL_74:
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
            if (fldGb->areaID == 21)
            {
              gFldSnowW = 15.0;
            }
            gFldSnowX = (gFldSnowW * 256.0) * -0.5;
            gFldSnowZ = (gFldSnowW * 256.0) * -0.5;
            goto LABEL_74;
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
  struct FLD_SEED_WORK_t_array *v21;
  struct FLD_SEED_WORK_t_array *v23;
  struct FLD_SEED_WORK_t_array *v25;
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
      goto LABEL_12;
LABEL_10:
    while (1)
    {
LABEL_12:
      if (gFldSeedBuff->m_Items[v9])
        break;
      v14 = gFldSeedBuff;
      v15 = Allocate(FLD_SEED_WORK_t);
      _ctor(v15, 0);
      *&v14[2 * v9 + 8] = v15;
        goto LABEL_15;
LABEL_26:
      v17 = gFldSeedBuff;
      if (!v17->m_Items[v9]->flg)
      {
        v21 = gFldSeedBuff;
        v21->m_Items[v9]->x = x;
        v23 = gFldSeedBuff;
        v23->m_Items[v9]->y = y;
        v25 = gFldSeedBuff;
        v25->m_Items[v9]->z = z;
        gFldSeedBuff->m_Items[v9]->life = gFldSnowLife;
        v29 = gFldSeedBuff;
        v29->m_Items[v9]->flg = 1;
        v31 = gFldSeedBuff;
        v31->m_Items[v9]->alp = 128;
        v33 = gFldSeedBuff;
        v35 = v33->m_Items[v9];
        v35->spd = dds3GetRandA("") & 0x1F;
        v36 = gFldSeedBuff;
        v38 = v36->m_Items[v9];
        v38->rgbofs = dds3GetRandA("") & 0xF;
        return;
      }
      if (v9 > 0x2BA)
        return;
      ++v9;
        goto LABEL_10;
    }
      goto LABEL_26;
LABEL_15:
    goto LABEL_26;
  }
}

// 0x17797a0
void fldSnowSeedDel(s32 i) {
  struct FLD_SEED_WORK_t_array *gFldSeedBuff;
  s64 v5;

  if (gFldSeedBuff)
  {
    else
    {
      v5 = i;
      if (LODWORD(gFldSeedBuff->max_length) <= i)
        goto LABEL_10;
    }
    gFldSeedBuff->m_Items[v5]->flg = 0;
  }
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
    goto LABEL_11;
LABEL_9:
  while (1)
  {
LABEL_11:
    v4 = v3 - 4;
    v6 = Allocate(FLD_SEED_WORK_t);
    _ctor(v6, 0);
    *&gFldSeedBuff[2 * v3] = v6;
    v8 = gFldSeedBuff;
    *(*(&v8->obj.klass + v3) + 28LL) = 0;
    if (v3 == 703)
      break;
    ++v3;
      goto LABEL_9;
  }
}

// 0x1777c90
void fldSnowSeedReset(void) {
  fldSnow_c *v2;
  s32 v4;
  f32 gFldSnowX;
  u8 RandA;
  u8 v11;
  f32 gFldSnowZ;
  f32 gFldSnowW;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v19;
  u8 v20;
  u8 v22;
  f32 v23;
  f32 v24;
  f32 v26;
  f32 v27;
  u64 i;
  struct FLD_SEED_WORK_t_array *gFldSeedBuff;
  struct FLD_SEED_WORK_t_array *v33;
  f32 *v35;
  s64 v37;
  struct FLD_SEED_WORK_t_array *v38;
  struct FLD_SEED_WORK_t_array *v41;
  struct FLD_SEED_WORK_t_array *v44;
  struct FLD_SEED_WORK_t_array *v47;
  fldUnitControl_t_o *UnitControl;
  dds3Basic_t_o **p_handle;
  s32 v53;
  s32 v55;
  f32 v56;
  struct fldGlobalWork_t_o *fldGb;
  f32 v59;
  struct fldGlobalWork_t_o *v60;
  f32 v61;
  f32 v64;
  f32 v65;
  f32 v66;
  u8 v67;
  f32 v68;
  u8 v69;
  f32 v70;
  f32 v71;
  f32 v72;
  f32 v74;
  f32 v75;
  u64 j;
  struct FLD_SEED_WORK_t_array *v78;
  struct FLD_SEED_WORK_t_array *v81;
  f32 *v83;
  s64 v85;
  struct FLD_SEED_WORK_t_array *v86;
  struct FLD_SEED_WORK_t_array *v89;
  struct FLD_SEED_WORK_t_array *v92;
  struct FLD_SEED_WORK_t_array *v95;
  UnityEngine_Vector4_o v97;

  *&v97.x = 0;
  *&v97.z = 0;
  if (gFldSeedBuff)
  {
    else if (!gFldSnowMode)
    {
LABEL_10:
      v4 = 0;
      if ((v2->_2.bitflags2 & 2) == 0)
        goto LABEL_15;
LABEL_13:
      while (1)
      {
LABEL_15:
        if (v4 >= gFldSnowLife)
          goto LABEL_77;
        if ((dds3GetRandA("") & 3) != 0)
          break;
        RandA = dds3GetRandA("");
        v11 = RandA;
        v14 = dds3GetRandA("");
        v15 = v14;
        v16 = v11;
        fldSnowSeedAdd(
          gFldSnowX + (gFldSnowW * v16),
          gFldSnowY,
          gFldSnowZ + (gFldSnowW * v15));
          goto LABEL_21;
LABEL_30:
        if ((dds3GetRandA("") & 3) == 0)
        {
          v19 = gFldSnowX;
          v20 = dds3GetRandA("");
          v22 = v20;
          v23 = gFldSnowZ;
          v24 = gFldSnowW;
          v25 = dds3GetRandA("");
          v26 = v25;
          v27 = v22;
          fldSnowSeedAdd(
            v19 + (v24 * v27),
            gFldSnowY,
            v23 + (gFldSnowW * v26));
        }
        for (i = 0; i != 700; ++i)
        {
          while (1)
          {
            if ((gFldSeedBuff->m_Items[i]->flg & 1) != 0)
            {
              v33 = gFldSeedBuff;
              --v33->m_Items[i]->life;
              v37 = *(*v35 + 8 * i + 32);
              LOWORD(v17) = *(v37 + 30);
              v17 = *(v37 + 20) + (v35[9] + (LODWORD(v17) * 0.125));
              *(v37 + 20) = v17;
              v38 = gFldSeedBuff;
              if (v38->m_Items[i]->life <= 63)
              {
                v41 = gFldSeedBuff;
                v41->m_Items[i]->alp -= 2;
              }
              v44 = gFldSeedBuff;
              if (v44->m_Items[i]->life <= 0)
                break;
            }
            if (++i == 700)
              goto LABEL_12;
          }
          v47 = gFldSeedBuff;
          v47->m_Items[i]->flg = 0;
        }
LABEL_12:
        ++v4;
          goto LABEL_13;
      }
        goto LABEL_30;
LABEL_21:
      goto LABEL_30;
    }
LABEL_77:
    else if (gFldSnowMode != 1)
    {
      return;
    }
    sub_854690(&v97.x, 0.0, 0.0, 0.0, 1.0);
    UnitControl = fldGetUnitControl();
    if (UnitControl)
    {
      p_handle = &UnitControl->handle;
      dds3GetPosPoseSet(p_handle);
      SDF_VU0__STOREVECTOR(&v97);
    }
    v53 = 0;
    {
LABEL_91:
    }
    while (v53 < 2 * gFldSnowLife)
    {
      v55 = 12;
      do
      {
        while (1)
        {
          if ((dds3GetRandA("") & 3) == 0)
            break;
          if (!--v55)
            goto LABEL_111;
        }
        sub_854710(&v97, 0);
        fldGb->playerX = v59;
        v60 = fldGb;
        sub_854710(&v97, 2u);
        v60->playerZ = v61;
        sub_854710(&v97, 0);
        v65 = v64;
        v66 = gFldSnowX;
        v67 = dds3GetRandA("");
        v68 = gFldSnowW;
        v69 = v67;
        sub_854710(&v97, 2u);
        v70 = gFldSnowZ;
        v72 = v71;
        v73 = dds3GetRandA("");
        v74 = v73;
        v75 = v69;
        fldSnowSeedAdd(
          (v65 + v66) + (v68 * v75),
          gFldSnowY,
          (v72 + v70) + (gFldSnowW * v74));
        --v55;
      }
      while (v55);
LABEL_111:
      for (j = 0; j != 700; ++j)
      {
        while (1)
        {
          v78 = gFldSeedBuff;
          if ((v78->m_Items[j]->flg & 1) != 0)
          {
            v81 = gFldSeedBuff;
            --v81->m_Items[j]->life;
            v85 = *(*v83 + 8 * j + 32);
            LOWORD(v56) = *(v85 + 30);
            v56 = *(v85 + 20) + (v83[9] + (LODWORD(v56) * -0.125));
            *(v85 + 20) = v56;
            v86 = gFldSeedBuff;
            if (v86->m_Items[j]->life <= 63)
            {
              v89 = gFldSeedBuff;
              v89->m_Items[j]->alp -= 2;
            }
            v92 = gFldSeedBuff;
            if (v92->m_Items[j]->life <= 0)
              break;
          }
          if (++j == 700)
            goto LABEL_90;
        }
        v95 = gFldSeedBuff;
        v95->m_Items[j]->flg = 0;
      }
LABEL_90:
      ++v53;
        goto LABEL_91;
    }
  }
}

// 0x17789d0
void fldSnowSprite3D(Sprite3D_t *spr3d) {
  struct XRD773Unity_CommonMesh_array *pMesh;
  s32 UseIndex;
  struct XRD773Unity_CommonMesh_array *v7;
  s32 v8;
  s32 UseIndexMax;
  struct XRD773Unity_CommonMesh_array *v11;
  s32 v12;
  u32 v13;
  struct XRD773Unity_CommonMesh_array *v17;
  Sprite3D_t_o *v18;
  XRD773Unity_CommonMesh_o *v20;
  u64 v21;
  UnityEngine_Vector3_array *v22;
  struct XRD773Unity_CommonMesh_array *v23;
  XRD773Unity_CommonMesh_o *v25;
  System_Int32_array *v26;
  struct XRD773Unity_CommonMesh_array *v27;
  XRD773Unity_CommonMesh_o *v29;
  UnityEngine_Color_array *v30;
  struct XRD773Unity_CommonMesh_array *v31;
  XRD773Unity_CommonMesh_o *v33;
  UnityEngine_Vector2_array *v34;
  struct XRD773Unity_CommonMesh_array *v35;
  UnityEngine_Vector3_array *Position;
  struct XRD773Unity_CommonMesh_array *v38;
  UnityEngine_Vector3_array *v39;
  long f64 v41;
  struct XRD773Unity_CommonMesh_array *v42;
  long f64 v44;
  s32 v45;
  s32 v46;
  long f64 v47;
  s32 v48;
  u32 *v50;
  struct XRD773Unity_CommonMesh_array *v51;
  long f64 v53;
  s32 v54;
  s32 v55;
  long f64 v56;
  s64 v57;
  u32 *v59;
  struct XRD773Unity_CommonMesh_array *v60;
  long f64 v62;
  s32 v63;
  s32 v64;
  long f64 v65;
  u32 *v67;
  struct XRD773Unity_CommonMesh_array *v68;
  long f64 v71;
  s32 v72;
  s32 v73;
  u32 *v75;
  char *v76;
  s64 v77;
  f32 *p_z;
  u32 *v79;
  u32 v80;
  UnityEngine_Vector3_array *v83;
  UnityEngine_Color_array *v85;
  Sprite3D_t_o *v86;
  s32 v87;
  s32 v88;
  s32 v89;
  struct XRD773Unity_CommonMesh_array *v92;
  System_Int32_array *IndexTable;
  s32 v95;
  s64 v97;
  s64 v102;
  struct XRD773Unity_CommonMesh_array *v104;
  UnityEngine_Vector2_array *UvTable;
  Il2CppClass **v108;
  Il2CppClass **v111;
  Il2CppClass **v114;
  Il2CppClass **v117;
  struct XRD773Unity_CommonMesh_array *v119;
  s64 v121;
  s64 v122;
  s64 v123;
  s64 v124;
  s64 v125;
  s32 v126;
  s32 v127;
  s64 v128;
  s64 v129;
  UnityEngine_Color_array *Color;
  UnityEngine_Vector4_o v131;

  v128 = 0;
  v129 = 0;
  ++SnowDispCount;
  UseIndex = GetUseIndex(pMesh->m_Items[0]);
  v7 = pMesh;
  v8 = UseIndex;
  UseIndexMax = GetUseIndexMax(v7->m_Items[0]);
  v11 = pMesh;
  v12 = UseIndexMax;
  v13 = 4 * UseIndexMax;
  if (v13 > SLODWORD(GetPosition(v11->m_Items[0])->max_length))
  {
    v17 = pMesh;
    v18 = spr3d;
    v20 = v17->m_Items[0];
    v21 = v13;
    v22 = NewSpecific(UnityEngine_Vector3, v13);
    SetPosition_20241056(v20, v22);
    v23 = pMesh;
    v25 = v23->m_Items[0];
    v26 = NewSpecific(s32, (6 * v12));
    SetIndexTable(v25, v26);
    v27 = pMesh;
    v29 = v27->m_Items[0];
    v30 = NewSpecific(UnityEngine_Color, v21);
    SetColor_20241296(v29, v30);
    v31 = pMesh;
    v33 = v31->m_Items[0];
    v34 = NewSpecific(UnityEngine_Vector2, v21);
    SetUvTable_20243232(v33, v34);
    spr3d = v18;
  }
  else
  {
    v35 = pMesh;
    if (!LODWORD(v35->max_length))
      goto LABEL_28;
  }
  Position = GetPosition(v35->m_Items[0]);
  v38 = pMesh;
  v39 = Position;
  Color = GetColor(v38->m_Items[0], 0);
  v131 = SDF_VU0__Retdds3ColorItoF(spr3d->col, 128.0);
  sub_19EC630(&v128, v131.x, v131.y, v131.z, v131.w);
  v42 = pMesh;
  v44 = sub_1A00CF0(&v42->m_Items[0]->mat.m00, spr3d->vt0->x / 100.0, spr3d->vt0->y / -100.0, 0.0, v41);
  v48 = 4 * v8;
  v50 = (v39 + 48 * v8);
  v50[8] = LODWORD(v44);
  v50[9] = v45;
  v50[10] = v46;
  v51 = pMesh;
  v53 = sub_1A00CF0(&v51->m_Items[0]->mat.m00, spr3d->vt1->x / 100.0, spr3d->vt1->y / -100.0, 0.0, v47);
  v57 = v48 | 1LL;
  v59 = (v39 + 12 * v57);
  v59[8] = LODWORD(v53);
  v59[9] = v54;
  v59[10] = v55;
  v60 = pMesh;
  v62 = sub_1A00CF0(&v60->m_Items[0]->mat.m00, spr3d->vt2->x / 100.0, spr3d->vt2->y / -100.0, 0.0, v56);
  v67 = (v39 + 12 * (v48 | 2LL));
  v67[8] = LODWORD(v62);
  v67[9] = v63;
  v67[10] = v64;
  v68 = pMesh;
  v123 = v48 | 2LL;
  v124 = v48 | 1LL;
  v71 = sub_1A00CF0(&v68->m_Items[0]->mat.m00, spr3d->vt3->x / 100.0, spr3d->vt3->y / -100.0, 0.0, v65);
  v121 = v8;
  v122 = v48 | 3LL;
  v75 = (v39 + 12 * v122);
  v125 = 4LL * v8;
  v126 = v8;
  v76 = Color + 64 * v8;
  v77 = 0;
  v75[8] = LODWORD(v71);
  v75[9] = v72;
  v75[10] = v73;
  p_z = &v39->m_Items[4 * v8].z;
  v79 = v76 + 44;
  v127 = 4 * v8;
  do
  {
    v80 = v127 + v77;
    *(p_z - 2) = *(p_z - 2) + (spr3d->pos.x / 100.0);
    *(p_z - 1) = *(p_z - 1) + (spr3d->pos.y / -100.0);
    v83 = v39;
    v85 = Color;
    v86 = spr3d;
    *p_z = *p_z + (spr3d->pos.z / 100.0);
    v87 = HIDWORD(v128);
    v88 = v129;
    v89 = HIDWORD(v129);
    ++v77;
    *(v79 - 3) = v128;
    *(v79 - 2) = v87;
    p_z += 3;
    *(v79 - 1) = v88;
    *v79 = v89;
    v79 += 4;
    spr3d = v86;
    v39 = v83;
  }
  while (v77 != 4);
  v92 = pMesh;
  IndexTable = GetIndexTable(v92->m_Items[0]);
  v95 = 6 * v121;
  v97 = v95 | 1LL;
  IndexTable->m_Items[6 * v121] = v125;
  IndexTable->m_Items[v97] = v124;
  IndexTable->m_Items[v95 + 2] = v122;
  IndexTable->m_Items[v95 + 3] = v124;
  IndexTable->m_Items[v95 + 4] = v123;
  v102 = v95 + 5LL;
  IndexTable->m_Items[v102] = v122;
  v104 = pMesh;
  UvTable = GetUvTable(v104->m_Items[0]);
  v108 = &UvTable->obj.klass + v125;
  *(v108 + 8) = 0;
  *(v108 + 9) = 0;
  v111 = &UvTable->obj.klass + v124;
  *(v111 + 8) = 1065353216;
  *(v111 + 9) = 0;
  v114 = &UvTable->obj.klass + v123;
  *(v114 + 8) = 1065353216;
  *(v114 + 9) = 1065353216;
  v117 = &UvTable->obj.klass + v122;
  *(v117 + 8) = 0;
  *(v117 + 9) = 1065353216;
  v119 = pMesh;
  SetUseIndex(v119->m_Items[0], v126 + 1);
}

// 0x17789c0
void fldSnowSpriteTex(void **th) {
  ;
}

// 0x1779880
void fldSnowTask(void) {
  u64 *v1;
  f32 gFldSnowX;
  f32 gFldSnowW;
  f32 gFldSnowZ;
  f32 v21;
  u8 v22;
  u8 v24;
  f32 v25;
  f32 v26;
  f32 v28;
  f32 v29;
  f32 v31;
  u8 v32;
  u8 v34;
  f32 v35;
  f32 v36;
  f32 v38;
  f32 v39;
  struct FLD_SEED_WORK_t_array *gFldSeedBuff;
  u64 v151[2];

  v151[0] = 0;
  v151[1] = 0;
  v1 = Allocate(Sprite3D_t);
  Sprite3D_t___ctor(v1);
  SnowDispCount = 0;
  if (gFldSeedBuff)
  {
    else if (gFldSnowMode)
    {
      goto LABEL_10;
    }
    if ((dds3GetRandA("") & 3) == 0)
    {
      v21 = gFldSnowX;
      v22 = dds3GetRandA("");
      v24 = v22;
      v25 = gFldSnowZ;
      v26 = gFldSnowW;
      v27 = dds3GetRandA("");
      v28 = v27;
      v29 = v24;
      fldSnowSeedAdd(
        v21 + (v26 * v29),
        gFldSnowY,
        v25 + (gFldSnowW * v28));
    }
    if ((dds3GetRandA("") & 3) == 0)
    {
      v31 = gFldSnowX;
      v32 = dds3GetRandA("");
      v34 = v32;
      v35 = gFldSnowZ;
      v36 = gFldSnowW;
      v37 = dds3GetRandA("");
      v38 = v37;
      v39 = v34;
      fldSnowSeedAdd(
        v31 + (v36 * v39),
        gFldSnowY,
        v35 + (gFldSnowW * v38));
    }
    goto LABEL_51;
  }
}
