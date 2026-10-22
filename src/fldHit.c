#include "types.h"

typedef struct collision_s collision_s;
typedef struct dds3BasicArrayHandle_t dds3BasicArrayHandle_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct fldProgramHit_tag fldProgramHit_tag;
typedef struct fldResCollisionPoly_t fldResCollisionPoly_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

static s32 fldHit_LastHitIdx;
static fldProgramHit_tag *gProgramHit;
static s32 gProgramHitNum;
static sdfMemHandle_t *gProgramHitMH;
static collision_s *gfldCollision;
static sdfMemHandle_t *gfldCollisionMH;
static s32 gfldCollsionNum;
static s32 gfldCollsionBlkNum;
static sdfVector4_t phys_oldpos;
static s32 fldHitAllView_anm;
static void *LineFrameObj;
static void *HitPlanObj;
static void *HitDesiObj;
static void *HitUnitObj;
static void *HitVWMObj;
static void *HitEventObj;

void CalcABCD(sdfVector4_t **v, f32 *a, f32 *b, f32 *c, f32 *d);
bool DDS3_PADCHECK_PRESS(s32 id);
f32 GetT_Y(f32 px, f32 pz, f32 **tx, f32 **ty, f32 **tz);
s32 HitPositionInside2(f32 *fret, s32 mode2D, s32 numE, sdfVector4_t pos, f32 r, collision_s *collision);
f32 HitPositionInside3(s32 mode2D, s32 numE, sdfVector4_t pos, f32 r, collision_s *collision);
f32 MATH_VectorLength(sdfVector4_t v);
void aDrawBoxF(s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b, s32 a);
void aDrawBoxFZ(s32 x, s32 y, s32 w, s32 h, s32 z, s32 r, s32 g, s32 b, s32 a);
void dds3FreeBasicArrayHandle(dds3BasicArrayHandle_t **hndl);
dds3Basic_t *dds3GetBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3GetBasicArrayCount(dds3BasicArrayHandle_t **hndl);
dds3Basic_t *dds3GetControlScene(void);
s32 dds3MatterObjectBasicGetAlpMode(dds3Basic_t **aPtr);
void dds3MatterObjectBasicSetAlpMode(dds3Basic_t **aPtr, s32 alpmode);
dds3BasicArrayHandle_t *dds3SceneBasicGetList(dds3Basic_t **pBasic, u32 type);
dds3Basic_t *dds3SceneBasicSearchNameAndType(dds3Basic_t *scene, u32 type, char *name);
u32 dds3SerializeID(void);
s32 dds3SetFirstBasicArray(dds3BasicArrayHandle_t **hndl);
s32 dds3SetNextBasicArray(dds3BasicArrayHandle_t **hndl);
void deleteFldMenuSub(s32 second);
void fldAddCollisionPoly(fldResCollisionPoly_t *pDataPoly, sdfVector4_t pos, s32 resID, s32 hojiID, s32 npcID);
void fldAutoMapNameD(s32 nameID);
void fldAutoMapNameU(s32 nameID);
void fldAutoMapOpenBlock(s32 blockID);
s32 fldGbChkHit(s32 fld, s32 area, s32 blk);
s32 fldGbChkNpc(s32 fld, s32 area, s32 hojiID);
void fldHitAlloc(void);
void fldHitChkUnitElvOnly(sdfVector4_t phys_pos);
void fldSkySetTblModosu(s32 hokan);
void fldSkySetTblUpper(s32 idx, s32 hokan);
void ooyTestPoly3(f32 x0, f32 y0, f32 z0, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, u32 col0, u32 col1, u32 col2);
void ooyTestPoly4(f32 x0, f32 y0, f32 z0, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 x3, f32 y3, f32 z3, u32 col0, u32 col1, u32 col2, u32 col3);
void ooyTestRGBMaskOff(void);
void ooyTestRGBMaskOn(void);
void rsetAlpha(s32 mode);
void rsetOtOfs(s32 otofs);
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
f32 sdfFabs(f32 c);
f32 sdfSqrt(f32 aValue);

// 0x127f2c0
void CalcABCD(sdfVector4_t **v, f32 *a, f32 *b, f32 *c, f32 *d) {
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  f32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  f32 v46;
  f32 v47;
  f32 v48;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 v55;
  f32 v56;
  f32 v57;
  f32 v58;
  f32 v59;
  f32 v60;
  f32 v61;
  f32 v62;
  f32 v63;
  f32 v65;
  f32 v66;
  f32 v67;
  f32 v68;
  f32 v69;
  f32 v70;
  f32 v71;
  f32 v72;
  f32 v73;
  f32 v74;
  f32 v75;
  f32 v76;
  f32 v77;
  f32 v78;
  f32 v79;
  u64 v80[2];
  u64 v81[2];
  u64 v82[2];

  v82[0] = 0;
  v82[1] = 0;
  v81[0] = 0;
  v81[1] = 0;
  v80[0] = 0;
  v80[1] = 0;
  sub_854710(v->m_Items, 0);
  sub_854930(v82, 0);
  sub_854710(v->m_Items, 1u);
  sub_854930(v82, 1u);
  sub_854710(v->m_Items, 2u);
  sub_854930(v82, 2u);
  sub_854710(&v->m_Items[1], 0);
  sub_854930(v81, 0);
  sub_854710(&v->m_Items[1], 1u);
  sub_854930(v81, 1u);
  sub_854710(&v->m_Items[1], 2u);
  sub_854930(v81, 2u);
  sub_854710(&v->m_Items[2], 0);
  sub_854930(v80, 0);
  sub_854710(&v->m_Items[2], 1u);
  sub_854930(v80, 1u);
  sub_854710(&v->m_Items[2], 2u);
  sub_854930(v80, 2u);
  sub_854710(v81, 1u);
  v21 = v20;
  sub_854710(v82, 1u);
  v23 = v22;
  sub_854710(v80, 2u);
  v25 = v24;
  sub_854710(v81, 2u);
  v27 = v26;
  sub_854710(v81, 2u);
  v29 = v28;
  sub_854710(v82, 2u);
  v31 = v30;
  sub_854710(v80, 1u);
  v33 = v32;
  sub_854710(v81, 1u);
  *a = ((v21 - v23) * (v25 - v27)) - ((v29 - v31) * (v33 - v34));
  sub_854710(v81, 2u);
  v36 = v35;
  sub_854710(v82, 2u);
  v38 = v37;
  sub_854710(v80, 0);
  v40 = v39;
  sub_854710(v81, 0);
  v42 = v41;
  sub_854710(v81, 0);
  v44 = v43;
  sub_854710(v82, 0);
  v46 = v45;
  sub_854710(v80, 2u);
  v48 = v47;
  sub_854710(v81, 2u);
  *b = ((v36 - v38) * (v40 - v42)) - ((v44 - v46) * (v48 - v49));
  sub_854710(v81, 0);
  v51 = v50;
  sub_854710(v82, 0);
  v53 = v52;
  sub_854710(v80, 1u);
  v55 = v54;
  sub_854710(v81, 1u);
  v57 = v56;
  sub_854710(v81, 1u);
  v59 = v58;
  sub_854710(v82, 1u);
  v61 = v60;
  sub_854710(v80, 0);
  v63 = v62;
  sub_854710(v81, 0);
  v66 = ((v51 - v53) * (v55 - v57)) - ((v59 - v61) * (v63 - v65));
  *c = v66;
  v67 = *a;
  v68 = *b;
  v69 = sdfSqrt((v66 * v66) + ((v67 * v67) + (v68 * v68)), 0);
  *a = *a * (1.0 / v69);
  *b = (1.0 / v69) * *b;
  *c = (1.0 / v69) * *c;
  if (*a <= -0.0001)
  {
    if (v69 <= 0.0)
      goto LABEL_33;
LABEL_29:
    v70 = *b;
    if (*b <= -0.0001)
      goto LABEL_34;
    goto LABEL_30;
  }
  if (v69 > 0.0 && *a >= 0.0001)
    goto LABEL_29;
LABEL_33:
  *a = 0.0;
  v70 = *b;
  if (*b <= -0.0001)
  {
LABEL_34:
    if (v69 > 0.0)
      goto LABEL_35;
LABEL_39:
    *b = 0.0;
    v71 = *c;
    if (*c > -0.0001)
      goto LABEL_36;
    goto LABEL_40;
  }
LABEL_30:
  if (v69 <= 0.0 || v70 < 0.0001)
    goto LABEL_39;
LABEL_35:
  v71 = *c;
  if (*c > -0.0001)
  {
LABEL_36:
    if (v69 <= 0.0 || v71 < 0.0001)
      goto LABEL_41;
    goto LABEL_42;
  }
LABEL_40:
  if (v69 <= 0.0)
LABEL_41:
    *c = 0.0;
LABEL_42:
  v72 = *a;
  sub_854710(v80, 0);
  v73 = *b;
  v75 = v74;
  sub_854710(v80, 1u);
  v76 = *c;
  v78 = v77;
  sub_854710(v80, 2u);
  *d = -(((v72 * v75) + (v73 * v78)) + (v76 * v79));
}

// 0x127f930
s32 HitPositionInside2(f32 *fret, s32 mode2D, s32 numE, sdfVector4_t pos, f32 r, collision_s *collision) {
  f32 *v11;
  u32 v12;
  s32 v13;
  u32 v15;
  s32 v16;
  s32 v19;
  f32 v21;
  s64 v22;
  u64 v23;
  s32 result;
  struct UnityEngine_Vector4_array *e_normal;
  s32 v26;
  s32 v27;
  s32 v28;
  s32 v29;
  char *v31;
  f32 y;
  f32 x;
  f32 z;
  s32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  f32 v46;
  struct System_Single_array *e_num;
  f32 v48;
  f32 v50;
  struct System_Single_array *min;
  struct System_Single_array *v52;
  struct System_Single_array *max;
  struct System_Single_array *v54;
  f32 v59;
  f32 *v64;
  f32 v65;
  signed s64 v67;
  s32 v68;
  f32 *v69;
  collision_s_o *v70;
  s32 v71;
  s64 v72;
  s64 v73;
  UnityEngine_Vector4_o v74;
  u32 v75[4];
  u32 v76[6];

  v74 = pos;
  v72 = 0;
  v73 = 0;
  v11 = NewSpecific(f32, 2u);
  if (mode2D == 1)
  {
    sub_854710(&v74, 0);
    sub_854930(&v72, 0);
    sub_854930(&v72, 1u);
    sub_854710(&v74, 2u);
    sub_854930(&v72, 2u);
    v12 = 0;
    goto LABEL_7;
  }
  if (!mode2D)
  {
    sub_854930(&v72, 0);
    sub_854710(&v74, 1u);
    sub_854930(&v72, 1u);
    sub_854710(&v74, 2u);
    sub_854930(&v72, 2u);
    v12 = 1;
LABEL_7:
    sub_854710(&v74, v12);
    *(v11 + 8) = v13;
    v15 = 2;
    goto LABEL_13;
  }
  sub_854710(&v74, 0);
  sub_854930(&v72, 0);
  sub_854710(&v74, 1u);
  sub_854930(&v72, 1u);
  sub_854930(&v72, 2u);
  sub_854710(&v74, 0);
  v15 = 1;
  *(v11 + 8) = v16;
LABEL_13:
  sub_854710(&v74, v15);
  *(v11 + 9) = v19;
  if (numE < 1)
  {
    result = 0;
    v21 = r;
LABEL_56:
    v64 = fret;
    v65 = -1.0;
    if (v21 >= 0.001)
      v65 = v21;
  }
  else
  {
    v67 = numE;
    v69 = v11;
    v70 = collision;
    v21 = r;
    v22 = 0;
    v23 = 0;
    result = 0;
    v68 = mode2D;
    while (1)
    {
      e_normal = collision->e_normal;
      v27 = v72;
      v26 = HIDWORD(v72);
      v71 = result;
      v29 = v73;
      v28 = HIDWORD(v73);
      v31 = e_normal + v22 * 16;
      x = e_normal->m_Items[v22].x;
      y = e_normal->m_Items[v22].y;
      z = e_normal->m_Items[v22].z;
      v35 = *(v31 + 11);
      v76[0] = v27;
      v76[1] = v26;
      v76[2] = v29;
      v76[3] = v28;
      *v75 = x;
      *&v75[1] = y;
      *&v75[2] = z;
      v75[3] = v35;
      sub_854710(v76, 0);
      v37 = v36;
      sub_854710(v75, 0);
      v39 = v38;
      sub_854710(v76, 1u);
      v41 = v40;
      sub_854710(v75, 1u);
      v43 = v42;
      sub_854710(v76, 2u);
      v45 = v44;
      sub_854710(v75, 2u);
      collision = v70;
      e_num = v70->e_num;
      v48 = ((v37 * v39) + (v41 * v43)) + (v45 * v46);
      v50 = v48 - e_num->m_Items[v23];
      if ((v50 + r) < 0.0)
        break;
      min = v70->min;
      if ((min->m_Items[0] - r) > v69[8])
        break;
      v52 = v70->min;
      if ((v52->m_Items[1] - r) > v69[9])
        break;
      max = v70->max;
      if ((max->m_Items[0] + r) < v69[8])
        break;
      v54 = v70->max;
      if ((v54->m_Items[1] + r) < v69[9])
        break;
      v59 = v50 + 45.0;
      if (v68 != 1)
        v59 = v50 + r;
      result = v71;
      if (v50 < 0.0)
        v21 = v59;
      ++v23;
      if (v50 < 0.0)
        result = 1;
      ++v22;
      if (v23 >= v67)
        goto LABEL_56;
    }
    v64 = fret;
    result = -1;
    v65 = -1.0;
  }
  *v64 = v65;
  return result;
}

// 0x128a760
f32 HitPositionInside3(s32 mode2D, s32 numE, sdfVector4_t pos, f32 r, collision_s *collision) {
  f32 *v10;
  u32 v11;
  s32 v12;
  u32 v14;
  s32 v15;
  s32 v18;
  f32 v20;
  f32 v21;
  s64 v22;
  u64 v23;
  struct UnityEngine_Vector4_array *e_normal;
  s32 v25;
  s32 v26;
  s32 v27;
  s32 v28;
  char *v30;
  f32 y;
  f32 x;
  s32 v33;
  s32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  struct System_Single_array *e_num;
  f32 v47;
  f32 v49;
  struct System_Single_array *min;
  struct System_Single_array *v51;
  struct System_Single_array *max;
  struct System_Single_array *v53;
  signed s64 v63;
  f32 *v64;
  collision_s_o *v65;
  s64 v66;
  s64 v67;
  UnityEngine_Vector4_o v68;
  u32 v69[4];
  u32 v70[4];

  v68 = pos;
  v66 = 0;
  v67 = 0;
  v10 = NewSpecific(f32, 2u);
  if (mode2D == 1)
  {
    sub_854710(&v68, 0);
    sub_854930(&v66, 0);
    sub_854930(&v66, 1u);
    sub_854710(&v68, 2u);
    sub_854930(&v66, 2u);
    v11 = 0;
    goto LABEL_7;
  }
  if (!mode2D)
  {
    sub_854930(&v66, 0);
    sub_854710(&v68, 1u);
    sub_854930(&v66, 1u);
    sub_854710(&v68, 2u);
    sub_854930(&v66, 2u);
    v11 = 1;
LABEL_7:
    sub_854710(&v68, v11);
    *(v10 + 8) = v12;
    v14 = 2;
    goto LABEL_13;
  }
  sub_854710(&v68, 0);
  sub_854930(&v66, 0);
  sub_854710(&v68, 1u);
  sub_854930(&v66, 1u);
  sub_854930(&v66, 2u);
  sub_854710(&v68, 0);
  v14 = 1;
  *(v10 + 8) = v15;
LABEL_13:
  sub_854710(&v68, v14);
  *(v10 + 9) = v18;
  if (numE < 1)
  {
    v21 = r;
LABEL_51:
    if (v21 >= 0.001)
      return v21;
    else
      return -1.0;
  }
  else
  {
    v20 = -1.0;
    v21 = r;
    v22 = 0;
    v23 = 0;
    v65 = collision;
    v63 = numE;
    v64 = v10;
    while (1)
    {
      e_normal = collision->e_normal;
      v25 = v66;
      v26 = HIDWORD(v66);
      v27 = v67;
      v28 = HIDWORD(v67);
      v30 = e_normal + v22 * 16;
      x = e_normal->m_Items[v22].x;
      y = e_normal->m_Items[v22].y;
      v34 = *(v30 + 10);
      v33 = *(v30 + 11);
      v70[0] = v25;
      v70[1] = v26;
      v70[2] = v27;
      v70[3] = v28;
      *v69 = x;
      *&v69[1] = y;
      v69[2] = v34;
      v69[3] = v33;
      sub_854710(v70, 0);
      v36 = v35;
      sub_854710(v69, 0);
      v38 = v37;
      sub_854710(v70, 1u);
      v40 = v39;
      sub_854710(v69, 1u);
      v42 = v41;
      sub_854710(v70, 2u);
      v44 = v43;
      sub_854710(v69, 2u);
      collision = v65;
      e_num = v65->e_num;
      v47 = ((v36 * v38) + (v40 * v42)) + (v44 * v45);
      v49 = v47 - e_num->m_Items[v23];
      if ((v49 + r) < 0.0)
        break;
      min = v65->min;
      if ((min->m_Items[0] - r) > v64[8])
        break;
      v51 = v65->min;
      if ((v51->m_Items[1] - r) > v64[9])
        break;
      max = v65->max;
      if ((max->m_Items[0] + r) < v64[8])
        break;
      v53 = v65->max;
      if ((v53->m_Items[1] + r) < v64[9])
        break;
      ++v23;
      ++v22;
      if (v49 < 0.0)
        v21 = v49 + r;
      if (v23 >= v63)
        goto LABEL_51;
    }
  }
  return v20;
}

// 0x127f0d0
f32 MATH_DotProduct(sdfVector4_t v1, sdfVector4_t v2) {
  f32 v3;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  UnityEngine_Vector4_o v15;
  UnityEngine_Vector4_o v16;

  v16 = v1;
  v15 = v2;
  sub_854710(&v16, 0);
  v4 = v3;
  sub_854710(&v15, 0);
  v6 = v5;
  sub_854710(&v16, 1u);
  v8 = v7;
  sub_854710(&v15, 1u);
  v10 = v9;
  sub_854710(&v16, 2u);
  v12 = v11;
  sub_854710(&v15, 2u);
  return ((v4 * v6) + (v8 * v10)) + (v12 * v13);
}

// 0x127f1a0
f32 MATH_VectorLength(sdfVector4_t v) {
  f32 v2;
  f32 v3;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v13;
  f32 v14;
  UnityEngine_Vector4_o v16;

  v16 = v;
  sub_854710(&v16, 0);
  v3 = v2;
  sub_854710(&v16, 0);
  v5 = v4;
  sub_854710(&v16, 1u);
  v7 = v6;
  sub_854710(&v16, 1u);
  v9 = v8;
  sub_854710(&v16, 2u);
  v11 = v10;
  sub_854710(&v16, 2u);
  v14 = v13;
  return sdfSqrt(((v3 * v5) + (v7 * v9)) + (v11 * v14), 0);
}

// 0x1263580
void fldAddCollisionPoly(fldResCollisionPoly_t *pDataPoly, sdfVector4_t pos, s32 resID, s32 hojiID, s32 npcID) {
  u64 *v6;
  u64 *v7;
  u64 *v8;
  u64 *v10;
  u32 *v12;
  s64 v13;
  s64 v14;
  u64 v15;
  u32 v29;
  u32 v36;
  u32 v61;
  u32 v67;
  u32 v74;
  u32 v80;
  u32 v87;
  u32 v95;
  u32 v100;
  u32 v106;
  u32 v111;
  struct collision_s_array *gfldCollision;
  s64 gfldCollsionNum;
  collision_s_o *v121;
  s16 v123;
  Il2CppClass **v125;
  s32 *data;
  s64 v128;
  s64 v130;
  s64 v137;
  s64 v139;
  s64 v141;
  s64 v148;
  s64 v150;
  s64 v152;
  collision_s_o *v178;
  s64 v181;
  s64 v183;
  s64 v185;
  s64 v191;
  u64 v192;
  s64 v193;
  f32 *v200;
  u32 *v201;
  u32 v202;
  s64 p_normal;
  u64 v209;
  s64 v210;
  struct UnityEngine_Vector4_array *point;
  struct UnityEngine_Vector4_array *v214;
  struct UnityEngine_Vector4_array *v217;
  struct UnityEngine_Vector4_array *v220;
  f32 *v222;
  u32 x_low;
  u32 y_low;
  u32 z_low;
  u32 w_low;
  u32 v228;
  u32 v229;
  f32 v230;
  f32 v231;
  f32 v232;
  f32 v233;
  f32 v234;
  f32 v235;
  f32 v236;
  f32 v237;
  f32 v238;
  f32 v239;
  f32 v240;
  f32 v241;
  f32 v242;
  f32 v244;
  f32 v245;
  f32 v246;
  f32 v247;
  f32 v248;
  f32 v249;
  f32 v250;
  f32 v251;
  f32 v252;
  f32 v253;
  f32 v257;
  f32 v258;
  s32 v260;
  s32 v261;
  s32 v264;
  s32 v265;
  s64 v267;
  u64 v268;
  s32 v270;
  s32 v272;
  s32 v276;
  f32 v282;
  f32 v284;
  f32 v285;
  f32 v287;
  f32 v288;
  f32 v290;
  f32 v291;
  f32 v293;
  s32 v295;
  struct System_Single_array *min;
  struct System_Single_array *v298;
  struct System_Single_array *max;
  struct System_Single_array *v302;
  s32 numedges;
  s32 v313;
  s32 v314;
  s32 v317;
  s32 v318;
  s64 v320;
  u64 v321;
  s32 v323;
  s32 v325;
  s32 v329;
  f32 v335;
  f32 v337;
  f32 v338;
  f32 v340;
  f32 v341;
  f32 v343;
  f32 v344;
  f32 v346;
  s32 v348;
  struct System_Single_array *v350;
  struct System_Single_array *v351;
  struct System_Single_array *v354;
  struct System_Single_array *v355;
  s32 v358;
  f32 v365;
  struct UnityEngine_Vector4_array *e_normal;
  s64 *p_e_normal;
  s64 v390;
  s64 v393;
  struct UnityEngine_Vector4_array *v396;
  struct System_Single_array *e_num;
  u32 v398;
  u32 v399;
  u32 v400;
  u32 v401;
  u64 v402;
  f32 z;
  f32 w;
  f32 v405;
  f32 v406;
  f32 v407;
  f32 v408;
  f32 v409;
  f32 v410;
  f32 v411;
  f32 v412;
  f32 v413;
  f32 v414;
  f32 v415;
  f32 v416;
  struct UnityEngine_Vector4_array *v418;
  s64 v419;
  u64 v421;
  f32 v422;
  f32 v423;
  f32 v424;
  f32 v425;
  f32 v426;
  f32 v427;
  f32 v428;
  f32 v429;
  f32 v430;
  f32 v431;
  f32 v432;
  f32 v433;
  f32 v434;
  struct System_Single_array *v435;
  f32 v436;
  f32 v438;
  u32 *v439;
  f32 *v440;
  il2cpp_array_size_t *v441;
  s64 v442;
  struct UnityEngine_Vector4_array *v443;
  struct UnityEngine_Vector4_array *v444;
  struct UnityEngine_Vector4_array *v447;
  struct UnityEngine_Vector4_array *v451;
  struct System_Single_array *v452;
  u32 v454;
  u32 v455;
  u32 v456;
  u32 v457;
  f32 y;
  f32 x;
  f32 v461;
  f32 v462;
  f32 v463;
  f32 v464;
  f32 v465;
  f32 v466;
  f32 v467;
  f32 v468;
  f32 v469;
  f32 v470;
  f32 v471;
  f32 v472;
  f32 v473;
  f32 v474;
  struct UnityEngine_Vector4_array *v493;
  struct UnityEngine_Vector4_array *v495;
  struct UnityEngine_Vector4_array *v498;
  struct System_Single_array *v501;
  struct UnityEngine_Vector4_array *v502;
  u32 v504;
  u32 v505;
  u32 v506;
  u32 v507;
  u64 v509;
  f32 v510;
  f32 v511;
  f32 v512;
  f32 v513;
  f32 v514;
  f32 v515;
  f32 v516;
  f32 v517;
  f32 v518;
  f32 v519;
  f32 v520;
  f32 v521;
  f32 v522;
  f32 v523;
  struct UnityEngine_Vector4_array *v525;
  s64 v526;
  u64 v528;
  f32 v529;
  f32 v530;
  f32 v531;
  f32 v532;
  f32 v533;
  f32 v534;
  f32 v535;
  f32 v536;
  f32 v537;
  f32 v538;
  f32 v539;
  f32 v540;
  f32 v541;
  struct System_Single_array *v542;
  f32 v543;
  f32 v545;
  s64 v546;
  s64 v547;
  il2cpp_array_size_t *v548;
  struct UnityEngine_Vector4_array *v549;
  struct UnityEngine_Vector4_array *v551;
  struct UnityEngine_Vector4_array *v554;
  struct UnityEngine_Vector4_array *v558;
  struct System_Single_array *v559;
  u32 v561;
  u32 v562;
  u32 v563;
  u32 v564;
  f32 v566;
  f32 v567;
  f32 v568;
  f32 v569;
  f32 v570;
  f32 v571;
  f32 v572;
  f32 v573;
  f32 v574;
  f32 v575;
  f32 v576;
  f32 v577;
  f32 v578;
  f32 v579;
  f32 v580;
  f32 v581;
  s32 v583;
  u32 v590;
  u32 *v591;
  f32 *v592;
  s64 *v605;
  u32 v606;
  s32 v608;
  s32 v609;
  s32 v612;
  s32 v613;
  s64 v615;
  u64 v616;
  s32 v618;
  s32 v620;
  s32 v624;
  f32 v630;
  f32 v632;
  f32 v633;
  f32 v635;
  f32 v636;
  f32 v638;
  f32 v639;
  f32 v641;
  s32 v643;
  struct System_Single_array *v645;
  struct System_Single_array *v646;
  struct System_Single_array *v649;
  struct System_Single_array *v650;
  s32 v653;
  struct UnityEngine_Vector4_array *v671;
  struct UnityEngine_Vector4_array *v673;
  struct UnityEngine_Vector4_array *v676;
  struct System_Single_array *v679;
  struct UnityEngine_Vector4_array *v680;
  u32 v682;
  u32 v683;
  u32 v684;
  u32 v685;
  u64 v687;
  f32 v688;
  f32 v689;
  f32 v690;
  f32 v691;
  f32 v692;
  f32 v693;
  f32 v694;
  f32 v695;
  f32 v696;
  f32 v697;
  f32 v698;
  f32 v699;
  f32 v700;
  f32 v701;
  struct UnityEngine_Vector4_array *v703;
  s64 v704;
  u64 v706;
  f32 v707;
  f32 v708;
  f32 v709;
  f32 v710;
  f32 v711;
  f32 v712;
  f32 v713;
  f32 v714;
  f32 v715;
  f32 v716;
  f32 v717;
  f32 v718;
  f32 v719;
  struct System_Single_array *v720;
  f32 v721;
  f32 v723;
  s64 v724;
  s64 v725;
  u32 *v726;
  f32 *v727;
  il2cpp_array_size_t *v728;
  struct UnityEngine_Vector4_array *v729;
  struct UnityEngine_Vector4_array *v731;
  struct UnityEngine_Vector4_array *v734;
  struct UnityEngine_Vector4_array *v738;
  struct System_Single_array *v739;
  u32 v741;
  u32 v742;
  u32 v743;
  u32 v744;
  f32 v746;
  f32 v747;
  f32 v748;
  f32 v749;
  f32 v750;
  f32 v751;
  f32 v752;
  f32 v753;
  f32 v754;
  f32 v755;
  f32 v756;
  f32 v757;
  f32 v758;
  f32 v759;
  f32 v760;
  f32 v761;
  s64 *v781;
  u32 v782;
  struct UnityEngine_Vector4_array *v818;
  s64 *v819;
  s64 v820;
  s64 v823;
  struct UnityEngine_Vector4_array *v826;
  struct System_Single_array *v827;
  u32 v828;
  u32 v829;
  u32 v830;
  u32 v831;
  u64 v832;
  f32 v833;
  f32 v834;
  f32 v835;
  f32 v836;
  f32 v837;
  f32 v838;
  f32 v839;
  f32 v840;
  f32 v841;
  f32 v842;
  f32 v843;
  f32 v844;
  f32 v845;
  f32 v846;
  struct UnityEngine_Vector4_array *v848;
  s64 v849;
  u64 v851;
  f32 v852;
  f32 v853;
  f32 v854;
  f32 v855;
  f32 v856;
  f32 v857;
  f32 v858;
  f32 v859;
  f32 v860;
  f32 v861;
  f32 v862;
  f32 v863;
  f32 v864;
  struct System_Single_array *v865;
  f32 v866;
  f32 v868;
  u32 *v869;
  f32 *v870;
  il2cpp_array_size_t *v871;
  s64 v872;
  struct UnityEngine_Vector4_array *v873;
  struct UnityEngine_Vector4_array *v874;
  struct UnityEngine_Vector4_array *v877;
  struct UnityEngine_Vector4_array *v881;
  struct System_Single_array *v882;
  u32 v884;
  u32 v885;
  u32 v886;
  u32 v887;
  f32 v889;
  f32 v890;
  f32 v891;
  f32 v892;
  f32 v893;
  f32 v894;
  f32 v895;
  f32 v896;
  f32 v897;
  f32 v898;
  f32 v899;
  f32 v900;
  f32 v901;
  f32 v902;
  f32 v903;
  f32 v904;
  struct UnityEngine_Vector4_array *v923;
  struct UnityEngine_Vector4_array *v925;
  struct UnityEngine_Vector4_array *v928;
  struct System_Single_array *v931;
  struct UnityEngine_Vector4_array *v932;
  u32 v934;
  u32 v935;
  u32 v936;
  u32 v937;
  u64 v939;
  f32 v940;
  f32 v941;
  f32 v942;
  f32 v943;
  f32 v944;
  f32 v945;
  f32 v946;
  f32 v947;
  f32 v948;
  f32 v949;
  f32 v950;
  f32 v951;
  f32 v952;
  f32 v953;
  struct UnityEngine_Vector4_array *v955;
  s64 v956;
  u64 v958;
  f32 v959;
  f32 v960;
  f32 v961;
  f32 v962;
  f32 v963;
  f32 v964;
  f32 v965;
  f32 v966;
  f32 v967;
  f32 v968;
  f32 v969;
  f32 v970;
  f32 v971;
  struct System_Single_array *v972;
  f32 v973;
  f32 v975;
  s64 v976;
  s64 v977;
  il2cpp_array_size_t *v978;
  struct UnityEngine_Vector4_array *v979;
  struct UnityEngine_Vector4_array *v982;
  struct UnityEngine_Vector4_array *v985;
  struct UnityEngine_Vector4_array *v989;
  struct System_Single_array *v990;
  u32 v992;
  u32 v993;
  u32 v994;
  u32 v995;
  f32 v997;
  f32 v998;
  f32 v999;
  f32 v1000;
  f32 v1001;
  f32 v1002;
  f32 v1003;
  f32 v1004;
  f32 v1005;
  f32 v1006;
  f32 v1007;
  f32 v1008;
  f32 v1009;
  f32 v1010;
  f32 v1011;
  f32 v1012;
  s32 v1014;
  u32 v1020;
  struct UnityEngine_Vector4_array *v1033;
  struct UnityEngine_Vector4_array *v1035;
  s64 v1038;
  struct UnityEngine_Vector4_array *v1061;
  s64 *v1062;
  s64 v1063;
  s64 v1066;
  struct UnityEngine_Vector4_array *v1069;
  struct System_Single_array *v1070;
  u32 v1071;
  u32 v1072;
  u32 v1073;
  u32 v1074;
  u64 v1075;
  f32 v1076;
  f32 v1077;
  f32 v1078;
  f32 v1079;
  f32 v1080;
  f32 v1081;
  f32 v1082;
  f32 v1083;
  f32 v1084;
  f32 v1085;
  f32 v1086;
  f32 v1087;
  f32 v1088;
  f32 v1089;
  struct UnityEngine_Vector4_array *v1091;
  s64 v1092;
  u64 v1094;
  f32 v1095;
  f32 v1096;
  f32 v1097;
  f32 v1098;
  f32 v1099;
  f32 v1100;
  f32 v1101;
  f32 v1102;
  f32 v1103;
  f32 v1104;
  f32 v1105;
  f32 v1106;
  f32 v1107;
  struct System_Single_array *v1108;
  f32 v1109;
  f32 v1111;
  u32 *v1112;
  f32 *v1113;
  il2cpp_array_size_t *v1114;
  s64 v1115;
  struct UnityEngine_Vector4_array *v1116;
  struct UnityEngine_Vector4_array *v1117;
  struct UnityEngine_Vector4_array *v1120;
  struct UnityEngine_Vector4_array *v1124;
  struct System_Single_array *v1125;
  u32 v1127;
  u32 v1128;
  u32 v1129;
  u32 v1130;
  f32 v1132;
  f32 v1133;
  f32 v1134;
  f32 v1135;
  f32 v1136;
  f32 v1137;
  f32 v1138;
  f32 v1139;
  f32 v1140;
  f32 v1141;
  f32 v1142;
  f32 v1143;
  f32 v1144;
  f32 v1145;
  f32 v1146;
  f32 v1147;
  struct UnityEngine_Vector4_array *v1166;
  struct UnityEngine_Vector4_array *v1168;
  struct UnityEngine_Vector4_array *v1171;
  struct System_Single_array *v1174;
  struct UnityEngine_Vector4_array *v1175;
  u32 v1177;
  u32 v1178;
  u32 v1179;
  u32 v1180;
  u64 v1182;
  f32 v1183;
  f32 v1184;
  f32 v1185;
  f32 v1186;
  f32 v1187;
  f32 v1188;
  f32 v1189;
  f32 v1190;
  f32 v1191;
  f32 v1192;
  f32 v1193;
  f32 v1194;
  f32 v1195;
  f32 v1196;
  struct UnityEngine_Vector4_array *v1198;
  s64 v1199;
  u64 v1201;
  f32 v1202;
  f32 v1203;
  f32 v1204;
  f32 v1205;
  f32 v1206;
  f32 v1207;
  f32 v1208;
  f32 v1209;
  f32 v1210;
  f32 v1211;
  f32 v1212;
  f32 v1213;
  f32 v1214;
  struct System_Single_array *v1215;
  f32 v1216;
  f32 v1218;
  s64 v1219;
  s64 v1220;
  il2cpp_array_size_t *v1221;
  struct UnityEngine_Vector4_array *v1222;
  struct UnityEngine_Vector4_array *v1225;
  struct UnityEngine_Vector4_array *v1228;
  struct UnityEngine_Vector4_array *v1232;
  struct System_Single_array *v1233;
  u32 v1235;
  u32 v1236;
  u32 v1237;
  u32 v1238;
  f32 v1240;
  f32 v1241;
  f32 v1242;
  f32 v1243;
  f32 v1244;
  f32 v1245;
  f32 v1246;
  f32 v1247;
  f32 v1248;
  f32 v1249;
  f32 v1250;
  f32 v1251;
  f32 v1252;
  f32 v1253;
  f32 v1254;
  f32 v1255;
  s32 v1257;
  u32 v1263;
  u64 v1326;
  struct fldResCollisionPolyFace_t_array *v1327;
  struct UnityEngine_Vector4_array *v1379;
  struct UnityEngine_Vector4_array *v1381;
  struct UnityEngine_Vector4_array *v1384;
  struct System_Single_array *v1387;
  struct UnityEngine_Vector4_array *v1388;
  u32 v1390;
  u32 v1391;
  u32 v1392;
  u32 v1393;
  u64 v1395;
  f32 v1396;
  f32 v1397;
  f32 v1398;
  f32 v1399;
  f32 v1400;
  f32 v1401;
  f32 v1402;
  f32 v1403;
  f32 v1404;
  f32 v1405;
  f32 v1406;
  f32 v1407;
  f32 v1408;
  f32 v1409;
  struct UnityEngine_Vector4_array *v1411;
  s64 v1412;
  u64 v1414;
  f32 v1415;
  f32 v1416;
  f32 v1417;
  f32 v1418;
  f32 v1419;
  f32 v1420;
  f32 v1421;
  f32 v1422;
  f32 v1423;
  f32 v1424;
  f32 v1425;
  f32 v1426;
  f32 v1427;
  struct System_Single_array *v1428;
  f32 v1429;
  f32 v1431;
  s64 v1432;
  s64 v1433;
  u32 *v1434;
  f32 *v1435;
  il2cpp_array_size_t *v1436;
  struct UnityEngine_Vector4_array *v1437;
  struct UnityEngine_Vector4_array *v1439;
  struct UnityEngine_Vector4_array *v1442;
  struct UnityEngine_Vector4_array *v1446;
  struct System_Single_array *v1447;
  u32 v1449;
  u32 v1450;
  u32 v1451;
  u32 v1452;
  f32 v1454;
  f32 v1455;
  f32 v1456;
  f32 v1457;
  f32 v1458;
  f32 v1459;
  f32 v1460;
  f32 v1461;
  f32 v1462;
  f32 v1463;
  f32 v1464;
  f32 v1465;
  f32 v1466;
  f32 v1467;
  f32 v1468;
  f32 v1469;
  struct UnityEngine_Vector4_array *v1488;
  struct UnityEngine_Vector4_array *v1490;
  s64 v1493;
  struct UnityEngine_Vector4_array *v1506;
  struct UnityEngine_Vector4_array *v1508;
  struct UnityEngine_Vector4_array *v1511;
  struct System_Single_array *v1514;
  struct UnityEngine_Vector4_array *v1515;
  u32 v1517;
  u32 v1518;
  u32 v1519;
  u32 v1520;
  u64 v1522;
  f32 v1523;
  f32 v1524;
  f32 v1525;
  f32 v1526;
  f32 v1527;
  f32 v1528;
  f32 v1529;
  f32 v1530;
  f32 v1531;
  f32 v1532;
  f32 v1533;
  f32 v1534;
  f32 v1535;
  f32 v1536;
  struct UnityEngine_Vector4_array *v1538;
  s64 v1539;
  u64 v1541;
  f32 v1542;
  f32 v1543;
  f32 v1544;
  f32 v1545;
  f32 v1546;
  f32 v1547;
  f32 v1548;
  f32 v1549;
  f32 v1550;
  f32 v1551;
  f32 v1552;
  f32 v1553;
  f32 v1554;
  struct System_Single_array *v1555;
  f32 v1556;
  f32 v1558;
  s64 v1559;
  s64 v1560;
  il2cpp_array_size_t *v1561;
  struct UnityEngine_Vector4_array *v1562;
  struct UnityEngine_Vector4_array *v1564;
  struct UnityEngine_Vector4_array *v1567;
  struct UnityEngine_Vector4_array *v1571;
  struct System_Single_array *v1572;
  u32 v1574;
  u32 v1575;
  u32 v1576;
  u32 v1577;
  f32 v1579;
  f32 v1580;
  f32 v1581;
  f32 v1582;
  f32 v1583;
  f32 v1584;
  f32 v1585;
  f32 v1586;
  f32 v1587;
  f32 v1588;
  f32 v1589;
  f32 v1590;
  f32 v1591;
  f32 v1592;
  f32 v1593;
  f32 v1594;
  s64 v1612;
  s64 v1614;
  struct System_Single_array *v1619;
  struct UnityEngine_Vector4_array *v1620;
  u32 v1622;
  u32 v1623;
  u32 v1624;
  u32 v1625;
  u64 v1627;
  f32 v1628;
  f32 v1629;
  f32 v1630;
  f32 v1631;
  f32 v1632;
  f32 v1633;
  f32 v1634;
  f32 v1635;
  f32 v1636;
  f32 v1637;
  f32 v1638;
  f32 v1639;
  f32 v1640;
  f32 v1641;
  struct UnityEngine_Vector4_array *v1643;
  u64 v1645;
  f32 v1646;
  f32 v1647;
  f32 v1648;
  f32 v1649;
  f32 v1650;
  f32 v1651;
  f32 v1652;
  f32 v1653;
  f32 v1654;
  f32 v1655;
  f32 v1656;
  f32 v1657;
  f32 v1658;
  struct System_Single_array *v1659;
  f32 v1660;
  f32 v1662;
  struct UnityEngine_Vector4_array *v1663;
  struct UnityEngine_Vector4_array *v1666;
  struct UnityEngine_Vector4_array *v1669;
  struct UnityEngine_Vector4_array *v1673;
  struct System_Single_array *v1674;
  u32 v1676;
  u32 v1677;
  u32 v1678;
  u32 v1679;
  f32 v1681;
  f32 v1682;
  f32 v1683;
  f32 v1684;
  f32 v1685;
  f32 v1686;
  f32 v1687;
  f32 v1688;
  f32 v1689;
  f32 v1690;
  f32 v1691;
  f32 v1692;
  f32 v1693;
  f32 v1694;
  f32 v1695;
  f32 v1696;
  struct fldResCollPolyTome_t_o *pTome;
  u64 *v1706;
  u64 *v1707;
  s64 nFace;
  u32 *v1709;
  s64 v1710;
  s64 v1711;
  s64 v1712;
  u32 *v1713;
  struct UnityEngine_Vector4_array **v1714;
  s64 v1715;
  s32 v1716;
  s64 v1717;
  u64 *v1718;
  signed s32 n3;
  s64 v1720;
  s64 v1721;
  f32 *d;
  s64 v1723;
  s64 m_Items;
  u64 v1725;
  s64 v1726;
  f32 *v1727;
  u32 *v1728;
  struct UnityEngine_Vector4_array *pVertex;
  UnityEngine_Vector4_array *v;
  il2cpp_array_size_t *p_max_length;
  char *v1732;
  struct fldResCollisionPolyFace_t_array *pFace;
  f32 *v1734;
  f32 *v1735;
  collision_s_o *v1736;
  u32 *v1737;
  u64 v1738;
  u64 v1739;
  UnityEngine_Vector4_o v1740;
  u64 v1741;
  f32 v1742;
  f32 v1743;
  u64 v1744;
  u64 v1745;

  v1740 = pos;
  v6 = NewSpecific(UnityEngine_Vector4, 4u);
  v7 = NewSpecific(UnityEngine_Vector4, 4u);
  v = NewSpecific(UnityEngine_Vector4, 4u);
  v1738 = 0;
  v1739 = 0;
  v1718 = NewSpecific(f32, 4u);
  v8 = NewSpecific(f32, 2u);
  v10 = NewSpecific(f32, 2u);
  else if (!gfldCollision)
  {
    goto LABEL_6;
  }
  v1720 = (v6 + 8);
  v1706 = v10;
  v1707 = v8;
  v1726 = (v6 + 10);
  v1728 = (v1718 + 3);
  v1727 = (v1718 + 4);
  v1735 = v1718 + 9;
  d = v1718 + 11;
  v1709 = v8 + 3;
  v1737 = v10 + 3;
  v1734 = (v1718 + 5);
  p_max_length = &v->max_length;
  m_Items = v->m_Items;
  v1721 = &v->m_Items[2];
  v1717 = (v7 + 4);
  v1712 = (v7 + 6);
  v1710 = &v->m_Items[1];
  v1711 = (v7 + 8);
  v12 = (v6 + 3);
  v13 = (v6 + 4);
  v14 = (v6 + 6);
  v1716 = 0;
  v1713 = (v6 + 3);
  v1723 = (v6 + 4);
  v1715 = (v6 + 6);
  do
  {
    nFace = pDataPoly->nFace;
    if (pDataPoly->nFace >= 1)
    {
      pVertex = pDataPoly->pVertex;
      pFace = pDataPoly->pFace;
      v15 = 0;
      pTome = pDataPoly->pTome;
      n3 = pDataPoly->n3;
      while (1)
      {
        v121 = gfldCollision->m_Items[gfldCollsionNum];
        if (n3-- < 1)
          v123 = 4;
        else
          v123 = 3;
        v121->numedges = v123;
        v1736 = v121;
        v125 = &pFace->obj.klass + v15;
        data = v125[4]->_1.byval_arg.data;
        v1732 = (v125 + 4);
        v128 = data[8];
        v130 = &pVertex->m_Items[v128];
        sub_854710(v130, 0);
        sub_854710(&v1740, 0);
        sub_854930(v13, 0);
        sub_854710(v130, 1u);
        sub_854710(&v1740, 1u);
        sub_854930(v13, 1u);
        sub_854710(v130, 2u);
        sub_854710(&v1740, 2u);
        sub_854930(v13, 2u);
        v137 = *(*v1732 + 32LL);
        v139 = *(v137 + 36);
        v141 = &pVertex->m_Items[v139];
        sub_854710(v141, 0);
        sub_854710(&v1740, 0);
        sub_854930(v14, 0);
        sub_854710(v141, 1u);
        sub_854710(&v1740, 1u);
        sub_854930(v14, 1u);
        sub_854710(v141, 2u);
        sub_854710(&v1740, 2u);
        sub_854930(v14, 2u);
        v148 = *(*v1732 + 32LL);
        v150 = *(v148 + 40);
        v152 = &pVertex->m_Items[v150];
        sub_854710(v152, 0);
        sub_854710(&v1740, 0);
        sub_854930(v1720, 0);
        sub_854710(v152, 1u);
        sub_854710(&v1740, 1u);
        sub_854930(v1720, 1u);
        sub_854710(v152, 2u);
        sub_854710(&v1740, 2u);
        sub_854930(v1720, 2u);
        v1725 = v15;
        if (v1736->numedges == 3)
        {
          sub_854710(v13, 0);
          sub_854930(v1717, 0);
          sub_854710(v13, 1u);
          sub_854930(v1717, 1u);
          sub_854710(v13, 2u);
          sub_854930(v1717, 2u);
          sub_854710(v14, 0);
          sub_854930(v1712, 0);
          sub_854710(v14, 1u);
          sub_854930(v1712, 1u);
          sub_854710(v14, 2u);
          sub_854930(v1712, 2u);
          sub_854710(v1720, 0);
          sub_854930(v1711, 0);
          sub_854710(v1720, 1u);
          sub_854930(v1711, 1u);
          sub_854710(v1720, 2u);
          sub_854930(v1711, 2u);
          v178 = v1736;
            goto LABEL_230;
        }
        else
        {
          v181 = *(*v1732 + 32LL);
          v178 = v1736;
          v183 = *(v181 + 44);
          v185 = &pVertex->m_Items[v183];
          sub_854710(v185, 0);
          sub_854710(&v1740, 0);
          sub_854930(v1726, 0);
          sub_854710(v185, 1u);
          sub_854710(&v1740, 1u);
          sub_854930(v1726, 1u);
          sub_854710(v185, 2u);
          sub_854710(&v1740, 2u);
          sub_854930(v1726, 2u);
          v191 = (v7 + 4);
          v192 = 0;
          v193 = v13;
          do
          {
            sub_854710(v193, 0);
            sub_854930(v191, 0);
            sub_854710(v193, 1u);
            sub_854930(v191, 1u);
            sub_854710(v193, 2u);
            sub_854930(v191, 2u);
            ++v192;
            v191 += 16;
            v193 += 16;
          }
          while (v192 != 4);
            goto LABEL_230;
        }
LABEL_230:
        v200 = (v1718 + 4);
        v201 = v1718 + 3;
        v202 = *v1728;
        if (!*v1728)
          goto LABEL_273;
LABEL_231:
        CalcABCD(v7, v200, v1735, v1734, d);
        p_normal = &v178->normal;
        sub_854930(&v178->normal, 0);
        sub_854930(&v178->normal, 1u);
        sub_854930(&v178->normal, 2u);
        sub_854930(&v178->normal, 3u);
        if (v178->numedges > 0)
        {
          v209 = 0;
          v210 = 4;
          do
          {
            point = v178->point;
            sub_854710(&v7[v210], 0);
            sub_854930(point + v210 * 8, 0);
            v214 = v178->point;
            sub_854710(&v7[v210], 1u);
            sub_854930(v214 + v210 * 8, 1u);
            v217 = v178->point;
            sub_854710(&v7[v210], 2u);
            sub_854930(v217 + v210 * 8, 2u);
            v220 = v178->point;
            sub_854930(v220 + v210 * 8, 3u);
            ++v209;
            v210 += 2;
          }
          while (v209 < v178->numedges);
        }
        v222 = v178->point;
        x_low = LODWORD(v178->normal.x);
        y_low = LODWORD(v178->normal.y);
        z_low = LODWORD(v178->normal.z);
        w_low = LODWORD(v178->normal.w);
        v229 = *(v222 + 8);
        v228 = *(v222 + 9);
        v231 = v222[10];
        v230 = v222[11];
        v1744 = __PAIR64__(y_low, x_low);
        v1745 = __PAIR64__(w_low, z_low);
        v1741 = __PAIR64__(v228, v229);
        v1742 = v231;
        v1743 = v230;
        sub_854710(&v1744, 0);
        v233 = v232;
        sub_854710(&v1741, 0);
        v235 = v234;
        sub_854710(&v1744, 1u);
        v237 = v236;
        sub_854710(&v1741, 1u);
        v239 = v238;
        sub_854710(&v1744, 2u);
        v241 = v240;
        sub_854710(&v1741, 2u);
        v1736->num = ((v233 * v235) + (v237 * v239)) + (v241 * v242);
        sub_854710(p_normal, 0);
        v245 = v244;
        v246 = sdfFabs(v245);
        sub_854710(p_normal, 1u);
        v248 = sdfFabs(v247);
        sub_854710(p_normal, 2u);
        v250 = sdfFabs(v249);
        v251 = v250;
        v12 = v1713;
        v13 = v1723;
        v14 = v1715;
        switch (v1716)
        {
          case 0:
            if (v248 <= v246)
              goto LABEL_1598;
            if (v248 <= v250)
              goto LABEL_1598;
            sub_854710(p_normal, 1u);
            if (v252 > 0.0)
              goto LABEL_1598;
            sub_854710(p_normal, 1u);
            if (v253 > -0.98)
              goto LABEL_1598;
            goto LABEL_283;
          case 1:
            if (v248 <= v246)
              goto LABEL_1598;
            if (v248 <= v250)
              goto LABEL_1598;
            sub_854710(p_normal, 1u);
            if (v257 > 0.0)
              goto LABEL_1598;
            sub_854710(p_normal, 1u);
            if (v258 <= -0.98)
              goto LABEL_1598;
            goto LABEL_283;
          case 2:
            if (v246 >= v248 && v246 >= v250)
              goto LABEL_283;
            goto LABEL_1598;
          case 3:
            if (v250 <= v246 || v250 < v248)
              goto LABEL_1598;
            goto LABEL_283;
          case 4:
            if (v248 < v246)
              goto LABEL_1598;
            if (v248 < v250)
              goto LABEL_1598;
            sub_854710(p_normal, 1u);
            if (v365 <= 0.0)
              goto LABEL_1598;
            goto LABEL_283;
          default:
LABEL_283:
            if (v246 >= v248 && v246 >= v251)
            {
              v1736->mode2D = 0;
              sub_854710(v1723, 1u);
              *(v1707 + 8) = v260;
              sub_854710(v1723, 2u);
              *(v1707 + 9) = v261;
              sub_854710(v1723, 1u);
              *(v1706 + 8) = v264;
              sub_854710(v1723, 2u);
              *(v1706 + 9) = v265;
              if (v1736->numedges >= 2)
              {
                v267 = v1715;
                v268 = 1;
                do
                {
                  v282 = *(v1707 + 8);
                  sub_854710(v267, 1u);
                  if (v282 > v284)
                  {
                    sub_854710(v267, 1u);
                    *(v1707 + 8) = v270;
                    if (*v1709 <= 1u)
                    {
LABEL_318:
                    }
                  }
                  else if (*v1709 <= 1u)
                  {
                    goto LABEL_318;
                  }
                  v285 = *(v1707 + 9);
                  sub_854710(v267, 2u);
                  if (v285 > v287)
                  {
                    sub_854710(v267, 2u);
                    *(v1707 + 9) = v272;
                    if (!*v1737)
                    {
LABEL_309:
                    }
                  }
                  else if (!*v1737)
                  {
                    goto LABEL_309;
                  }
                  v288 = *(v1706 + 8);
                  sub_854710(v267, 1u);
                  if (v288 < v290)
                  {
                    sub_854710(v267, 1u);
                    *(v1706 + 8) = v276;
                    if (*v1737 <= 1u)
                    {
LABEL_315:
                    }
                  }
                  else if (*v1737 <= 1u)
                  {
                    goto LABEL_315;
                  }
                  v291 = *(v1706 + 9);
                  sub_854710(v267, 2u);
                  if (v291 < v293)
                  {
                    sub_854710(v267, 2u);
                    *(v1706 + 9) = v295;
                  }
                  ++v268;
                  v267 += 16;
                }
                while (v268 < v1736->numedges);
              }
              min = v1736->min;
              min->m_Items[0] = *(v1707 + 8);
              v298 = v1736->min;
              v298->m_Items[1] = *(v1707 + 9);
              max = v1736->max;
              max->m_Items[0] = *(v1706 + 8);
              v302 = v1736->max;
              v302->m_Items[1] = *(v1706 + 9);
              numedges = v1736->numedges;
              sub_854930(&v1738, 0);
              sub_854710(v1723, 1u);
              sub_854710(v1715, 1u);
              sub_854710(v1720, 1u);
              if (numedges == 3)
              {
                sub_854930(&v1738, 1u);
                sub_854710(v1723, 2u);
                sub_854710(v1715, 2u);
                sub_854710(v1720, 2u);
              }
              else
              {
                sub_854710(v1726, 1u);
                sub_854930(&v1738, 1u);
                sub_854710(v1723, 2u);
                sub_854710(v1715, 2u);
                sub_854710(v1720, 2u);
                sub_854710(v1726, 2u);
              }
              sub_854930(&v1738, 2u);
              sub_854930(m_Items, 0);
              sub_854710(v1723, 1u);
              sub_854930(m_Items, 1u);
              sub_854710(v1723, 2u);
              sub_854930(m_Items, 2u);
              sub_854930(v1710, 0);
              sub_854710(v1715, 1u);
              sub_854930(v1710, 1u);
              sub_854710(v1715, 2u);
              sub_854930(v1710, 2u);
              sub_854930(v1721, 0);
              sub_854710(v1710, 1u);
              sub_854930(v1721, 1u);
              sub_854710(v1710, 2u);
              sub_854930(v1721, 2u);
              else
              {
                v29 = *v1728;
                if (!*v1728)
                {
LABEL_27:
                }
              }
              CalcABCD(v, v1727, v1735, v1734, d);
              p_e_normal = &v1736->e_normal;
              e_normal = v1736->e_normal;
              sub_854930(e_normal->m_Items, 0);
              v390 = *p_e_normal;
              sub_854930(v390 + 32, 1u);
              v393 = *p_e_normal;
              v1714 = &v1736->e_normal;
              sub_854930(v393 + 32, 2u);
              v396 = v1736->e_normal;
              e_num = v1736->e_num;
              v399 = LODWORD(v396->m_Items[0].x);
              v398 = LODWORD(v396->m_Items[0].y);
              v401 = LODWORD(v396->m_Items[0].z);
              v400 = LODWORD(v396->m_Items[0].w);
              v402 = *&v->m_Items[0].x;
              z = v->m_Items[0].z;
              w = v->m_Items[0].w;
              v1744 = __PAIR64__(v398, v399);
              v1745 = __PAIR64__(v400, v401);
              v1741 = v402;
              v1742 = z;
              v1743 = w;
              sub_854710(&v1744, 0);
              v406 = v405;
              sub_854710(&v1741, 0);
              v408 = v407;
              sub_854710(&v1744, 1u);
              v410 = v409;
              sub_854710(&v1741, 1u);
              v412 = v411;
              sub_854710(&v1744, 2u);
              v414 = v413;
              sub_854710(&v1741, 2u);
              v416 = v414 * v415;
              e_num->m_Items[0] = ((v406 * v408) + (v410 * v412)) + v416;
              v418 = *v1714;
              v419 = v1720;
              v421 = *&v418->m_Items[0].x;
              v422 = v418->m_Items[0].z;
              v423 = v418->m_Items[0].w;
              v1744 = v1738;
              v1745 = v1739;
              v1741 = v421;
              v1742 = v422;
              v1743 = v423;
              sub_854710(&v1744, 0);
              v425 = v424;
              sub_854710(&v1741, 0);
              v427 = v426;
              sub_854710(&v1744, 1u);
              v429 = v428;
              sub_854710(&v1741, 1u);
              v431 = v430;
              sub_854710(&v1744, 2u);
              v433 = v432;
              sub_854710(&v1741, 2u);
              v435 = v1736->e_num;
              v436 = ((v425 * v427) + (v429 * v431)) + (v433 * v434);
              v438 = v435->m_Items[0];
              v440 = (v1718 + 4);
              v439 = (v1718 + 3);
              v441 = &v->max_length;
              v442 = v->m_Items;
              if ((v436 - v438) < 0.0)
              {
                v443 = *v1714;
                sub_854930(v443->m_Items, 0);
                v444 = *v1714;
                sub_854930(v444->m_Items, 1u);
                v447 = *v1714;
                sub_854930(v447->m_Items, 2u);
                v451 = v1736->e_normal;
                v452 = v1736->e_num;
                v455 = LODWORD(v451->m_Items[0].x);
                v454 = LODWORD(v451->m_Items[0].y);
                v456 = LODWORD(v451->m_Items[0].z);
                v457 = LODWORD(v451->m_Items[0].w);
                x = v->m_Items[0].x;
                y = v->m_Items[0].y;
                v462 = v->m_Items[0].z;
                v461 = v->m_Items[0].w;
                v1744 = __PAIR64__(v454, v455);
                v1745 = __PAIR64__(v457, v456);
                v1741 = __PAIR64__(LODWORD(y), LODWORD(x));
                v1742 = v462;
                v1743 = v461;
                sub_854710(&v1744, 0);
                v464 = v463;
                sub_854710(&v1741, 0);
                v466 = v465;
                sub_854710(&v1744, 1u);
                v468 = v467;
                sub_854710(&v1741, 1u);
                v470 = v469;
                sub_854710(&v1744, 2u);
                v472 = v471;
                sub_854710(&v1741, 2u);
                v474 = v472 * v473;
                v452->m_Items[0] = ((v464 * v466) + (v468 * v470)) + v474;
                v12 = v1713;
                v14 = v1715;
                v419 = v1720;
                v440 = (v1718 + 4);
                v439 = (v1718 + 3);
                v441 = &v->max_length;
                v442 = v->m_Items;
              }
              sub_854930(v442, 0);
              sub_854710(v14, 1u);
              sub_854930(v442, 1u);
              sub_854710(v14, 2u);
              sub_854930(v442, 2u);
              sub_854930(v1710, 0);
              sub_854710(v419, 1u);
              sub_854930(v1710, 1u);
              sub_854710(v419, 2u);
              sub_854930(v1710, 2u);
              sub_854930(v1721, 0);
              sub_854710(v1710, 1u);
              sub_854930(v1721, 1u);
              sub_854710(v1710, 2u);
              sub_854930(v1721, 2u);
              else
              {
                v36 = *v439;
                if (!*v439)
                {
LABEL_33:
                }
              }
              CalcABCD(v, v440, v1735, v1734, d);
              v493 = *v1714;
              sub_854930(&v493->m_Items[1], 0);
              v495 = *v1714;
              sub_854930(&v495->m_Items[1], 1u);
              v498 = *v1714;
              sub_854930(&v498->m_Items[1], 2u);
              v502 = v1736->e_normal;
              v501 = v1736->e_num;
              v504 = LODWORD(v502->m_Items[1].x);
              v505 = LODWORD(v502->m_Items[1].y);
              v506 = LODWORD(v502->m_Items[1].z);
              v507 = LODWORD(v502->m_Items[1].w);
              v509 = *&v->m_Items[1].x;
              v510 = v->m_Items[1].z;
              v511 = v->m_Items[1].w;
              v1744 = __PAIR64__(v505, v504);
              v1745 = __PAIR64__(v507, v506);
              v1741 = v509;
              v1742 = v510;
              v1743 = v511;
              sub_854710(&v1744, 0);
              v513 = v512;
              sub_854710(&v1741, 0);
              v515 = v514;
              sub_854710(&v1744, 1u);
              v517 = v516;
              sub_854710(&v1741, 1u);
              v519 = v518;
              sub_854710(&v1744, 2u);
              v521 = v520;
              sub_854710(&v1741, 2u);
              v523 = v521 * v522;
              v501->m_Items[1] = ((v513 * v515) + (v517 * v519)) + v523;
              v525 = *v1714;
              v526 = &v->m_Items[2];
              v528 = *&v525->m_Items[1].x;
              v529 = v525->m_Items[1].z;
              v530 = v525->m_Items[1].w;
              v1744 = v1738;
              v1745 = v1739;
              v1741 = v528;
              v1742 = v529;
              v1743 = v530;
              sub_854710(&v1744, 0);
              v532 = v531;
              sub_854710(&v1741, 0);
              v534 = v533;
              sub_854710(&v1744, 1u);
              v536 = v535;
              sub_854710(&v1741, 1u);
              v538 = v537;
              sub_854710(&v1744, 2u);
              v540 = v539;
              sub_854710(&v1741, 2u);
              v542 = v1736->e_num;
              v543 = ((v532 * v534) + (v536 * v538)) + (v540 * v541);
              v545 = v542->m_Items[1];
              v546 = v1723;
              v547 = v->m_Items;
              v548 = &v->max_length;
              if ((v543 - v545) < 0.0)
              {
                v549 = *v1714;
                sub_854930(&v549->m_Items[1], 0);
                v551 = *v1714;
                sub_854930(&v551->m_Items[1], 1u);
                v554 = *v1714;
                sub_854930(&v554->m_Items[1], 2u);
                v558 = v1736->e_normal;
                v559 = v1736->e_num;
                v561 = LODWORD(v558->m_Items[1].x);
                v562 = LODWORD(v558->m_Items[1].y);
                v564 = LODWORD(v558->m_Items[1].z);
                v563 = LODWORD(v558->m_Items[1].w);
                v567 = v->m_Items[1].x;
                v566 = v->m_Items[1].y;
                v569 = v->m_Items[1].z;
                v568 = v->m_Items[1].w;
                v1744 = __PAIR64__(v562, v561);
                v1745 = __PAIR64__(v563, v564);
                v1741 = __PAIR64__(LODWORD(v566), LODWORD(v567));
                v1742 = v569;
                v1743 = v568;
                sub_854710(&v1744, 0);
                v571 = v570;
                sub_854710(&v1741, 0);
                v573 = v572;
                sub_854710(&v1744, 1u);
                v575 = v574;
                sub_854710(&v1741, 1u);
                v577 = v576;
                sub_854710(&v1744, 2u);
                v579 = v578;
                sub_854710(&v1741, 2u);
                v581 = v579 * v580;
                v559->m_Items[1] = ((v571 * v573) + (v575 * v577)) + v581;
                v12 = v1713;
                v546 = v1723;
                v547 = v->m_Items;
                v419 = v1720;
                v526 = &v->m_Items[2];
                v548 = &v->max_length;
              }
              v583 = v1736->numedges;
              sub_854930(v547, 0);
              sub_854710(v419, 1u);
              sub_854930(v547, 1u);
              sub_854710(v419, 2u);
              sub_854930(v547, 2u);
              sub_854930(v1710, 0);
              v590 = *v12;
              if (v583 == 3)
              {
                v592 = (v1718 + 4);
                v591 = (v1718 + 3);
                sub_854710(v546, 1u);
                sub_854930(v1710, 1u);
                sub_854710(v546, 2u);
                sub_854930(v1710, 2u);
                sub_854930(v526, 0);
                sub_854710(v1710, 1u);
                sub_854930(v526, 1u);
                sub_854710(v1710, 2u);
                sub_854930(v526, 2u);
                v605 = &v1736->e_normal;
                  goto LABEL_657;
                goto LABEL_1272;
              }
              sub_854710(v1726, 1u);
              sub_854930(v1710, 1u);
              sub_854710(v1726, 2u);
              sub_854930(v1710, 2u);
              sub_854930(v526, 0);
              sub_854710(v1710, 1u);
              sub_854930(v526, 1u);
              sub_854710(v1710, 2u);
              sub_854930(v526, 2u);
              else
              {
                v61 = *v1728;
                if (!*v1728)
                {
LABEL_57:
                }
              }
              CalcABCD(v, v1727, v1735, v1734, d);
              v671 = *v1714;
              sub_854930(&v671->m_Items[2], 0);
              v673 = *v1714;
              sub_854930(&v673->m_Items[2], 1u);
              v676 = *v1714;
              sub_854930(&v676->m_Items[2], 2u);
              v680 = v1736->e_normal;
              v679 = v1736->e_num;
              v682 = LODWORD(v680->m_Items[2].x);
              v683 = LODWORD(v680->m_Items[2].y);
              v684 = LODWORD(v680->m_Items[2].z);
              v685 = LODWORD(v680->m_Items[2].w);
              v687 = *&v->m_Items[2].x;
              v688 = v->m_Items[2].z;
              v689 = v->m_Items[2].w;
              v1744 = __PAIR64__(v683, v682);
              v1745 = __PAIR64__(v685, v684);
              v1741 = v687;
              v1742 = v688;
              v1743 = v689;
              sub_854710(&v1744, 0);
              v691 = v690;
              sub_854710(&v1741, 0);
              v693 = v692;
              sub_854710(&v1744, 1u);
              v695 = v694;
              sub_854710(&v1741, 1u);
              v697 = v696;
              sub_854710(&v1744, 2u);
              v699 = v698;
              sub_854710(&v1741, 2u);
              v701 = v699 * v700;
              v679->m_Items[2] = ((v691 * v693) + (v695 * v697)) + v701;
              v703 = *v1714;
              v704 = &v->m_Items[2];
              v706 = *&v703->m_Items[2].x;
              v707 = v703->m_Items[2].z;
              v708 = v703->m_Items[2].w;
              v1744 = v1738;
              v1745 = v1739;
              v1741 = v706;
              v1742 = v707;
              v1743 = v708;
              sub_854710(&v1744, 0);
              v710 = v709;
              sub_854710(&v1741, 0);
              v712 = v711;
              sub_854710(&v1744, 1u);
              v714 = v713;
              sub_854710(&v1741, 1u);
              v716 = v715;
              sub_854710(&v1744, 2u);
              v718 = v717;
              sub_854710(&v1741, 2u);
              v720 = v1736->e_num;
              v721 = ((v710 * v712) + (v714 * v716)) + (v718 * v719);
              v723 = v720->m_Items[2];
              v724 = v1723;
              v725 = v->m_Items;
              v727 = (v1718 + 4);
              v726 = (v1718 + 3);
              v728 = &v->max_length;
              if ((v721 - v723) < 0.0)
              {
                v729 = *v1714;
                sub_854930(&v729->m_Items[2], 0);
                v731 = *v1714;
                sub_854930(&v731->m_Items[2], 1u);
                v734 = *v1714;
                sub_854930(&v734->m_Items[2], 2u);
                v738 = v1736->e_normal;
                v739 = v1736->e_num;
                v742 = LODWORD(v738->m_Items[2].x);
                v741 = LODWORD(v738->m_Items[2].y);
                v743 = LODWORD(v738->m_Items[2].z);
                v744 = LODWORD(v738->m_Items[2].w);
                v747 = v->m_Items[2].x;
                v746 = v->m_Items[2].y;
                v749 = v->m_Items[2].z;
                v748 = v->m_Items[2].w;
                v1744 = __PAIR64__(v741, v742);
                v1745 = __PAIR64__(v744, v743);
                v1741 = __PAIR64__(LODWORD(v746), LODWORD(v747));
                v1742 = v749;
                v1743 = v748;
                sub_854710(&v1744, 0);
                v751 = v750;
                sub_854710(&v1741, 0);
                v753 = v752;
                sub_854710(&v1744, 1u);
                v755 = v754;
                sub_854710(&v1741, 1u);
                v757 = v756;
                sub_854710(&v1744, 2u);
                v759 = v758;
                sub_854710(&v1741, 2u);
                v761 = v759 * v760;
                v739->m_Items[2] = ((v751 * v753) + (v755 * v757)) + v761;
                v12 = v1713;
                v724 = v1723;
                v725 = v->m_Items;
                v727 = (v1718 + 4);
                v726 = (v1718 + 3);
                v728 = &v->max_length;
                v704 = &v->m_Items[2];
              }
              sub_854930(v725, 0);
              sub_854710(v1726, 1u);
              sub_854930(v725, 1u);
              sub_854710(v1726, 2u);
              sub_854930(v725, 2u);
              sub_854930(v1710, 0);
              sub_854710(v724, 1u);
              sub_854930(v1710, 1u);
              sub_854710(v724, 2u);
              sub_854930(v1710, 2u);
              sub_854930(v704, 0);
              sub_854710(v1710, 1u);
              sub_854930(v704, 1u);
              sub_854710(v1710, 2u);
              sub_854930(v704, 2u);
              v781 = &v1736->e_normal;
                goto LABEL_841;
LABEL_1542:
              v782 = *v726;
              if (!*v726)
              {
LABEL_14:
              }
              goto LABEL_1543;
            }
            if (v248 < v246 || v248 < v251)
            {
              v1736->mode2D = 2;
              sub_854710(v1723, 0);
              *(v1707 + 8) = v608;
              sub_854710(v1723, 1u);
              *(v1707 + 9) = v609;
              sub_854710(v1723, 0);
              *(v1706 + 8) = v612;
              sub_854710(v1723, 1u);
              *(v1706 + 9) = v613;
              if (v1736->numedges >= 2)
              {
                v615 = v1715;
                v616 = 1;
                do
                {
                  v630 = *(v1707 + 8);
                  sub_854710(v615, 0);
                  if (v630 > v632)
                  {
                    sub_854710(v615, 0);
                    *(v1707 + 8) = v618;
                    if (*v1709 <= 1u)
                    {
LABEL_693:
                    }
                  }
                  else if (*v1709 <= 1u)
                  {
                    goto LABEL_693;
                  }
                  v633 = *(v1707 + 9);
                  sub_854710(v615, 1u);
                  if (v633 > v635)
                  {
                    sub_854710(v615, 1u);
                    *(v1707 + 9) = v620;
                    if (!*v1737)
                    {
LABEL_684:
                    }
                  }
                  else if (!*v1737)
                  {
                    goto LABEL_684;
                  }
                  v636 = *(v1706 + 8);
                  sub_854710(v615, 0);
                  if (v636 < v638)
                  {
                    sub_854710(v615, 0);
                    *(v1706 + 8) = v624;
                    if (*v1737 <= 1u)
                    {
LABEL_690:
                    }
                  }
                  else if (*v1737 <= 1u)
                  {
                    goto LABEL_690;
                  }
                  v639 = *(v1706 + 9);
                  sub_854710(v615, 1u);
                  if (v639 < v641)
                  {
                    sub_854710(v615, 1u);
                    *(v1706 + 9) = v643;
                  }
                  ++v616;
                  v615 += 16;
                }
                while (v616 < v1736->numedges);
              }
              v645 = v1736->min;
              v645->m_Items[0] = *(v1707 + 8);
              v646 = v1736->min;
              v646->m_Items[1] = *(v1707 + 9);
              v649 = v1736->max;
              v649->m_Items[0] = *(v1706 + 8);
              v650 = v1736->max;
              v650->m_Items[1] = *(v1706 + 9);
              v653 = v1736->numedges;
              sub_854710(v1723, 0);
              sub_854710(v1715, 0);
              sub_854710(v1720, 0);
              if (v653 == 3)
              {
                sub_854930(&v1738, 0);
                sub_854710(v1723, 1u);
                sub_854710(v1715, 1u);
                sub_854710(v1720, 1u);
              }
              else
              {
                sub_854710(v1726, 0);
                sub_854930(&v1738, 0);
                sub_854710(v1723, 1u);
                sub_854710(v1715, 1u);
                sub_854710(v1720, 1u);
                sub_854710(v1726, 1u);
              }
              sub_854930(&v1738, 1u);
              sub_854930(&v1738, 2u);
              sub_854710(v1723, 0);
              sub_854930(m_Items, 0);
              sub_854710(v1723, 1u);
              sub_854930(m_Items, 1u);
              sub_854930(m_Items, 2u);
              sub_854710(v1715, 0);
              sub_854930(v1710, 0);
              sub_854710(v1715, 1u);
              sub_854930(v1710, 1u);
              sub_854930(v1710, 2u);
              sub_854710(v1710, 0);
              sub_854930(v1721, 0);
              sub_854710(v1710, 1u);
              sub_854930(v1721, 1u);
              sub_854930(v1721, 2u);
              else
              {
                v80 = *v1728;
                if (!*v1728)
                {
LABEL_73:
                }
              }
              CalcABCD(v, v1727, v1735, v1734, d);
              v1062 = &v1736->e_normal;
              v1061 = v1736->e_normal;
              sub_854930(v1061->m_Items, 0);
              v1063 = *v1062;
              sub_854930(v1063 + 32, 1u);
              v1066 = *v1062;
              v1714 = &v1736->e_normal;
              sub_854930(v1066 + 32, 2u);
              v1069 = v1736->e_normal;
              v1070 = v1736->e_num;
              v1072 = LODWORD(v1069->m_Items[0].x);
              v1071 = LODWORD(v1069->m_Items[0].y);
              v1074 = LODWORD(v1069->m_Items[0].z);
              v1073 = LODWORD(v1069->m_Items[0].w);
              v1075 = *&v->m_Items[0].x;
              v1076 = v->m_Items[0].z;
              v1077 = v->m_Items[0].w;
              v1744 = __PAIR64__(v1071, v1072);
              v1745 = __PAIR64__(v1073, v1074);
              v1741 = v1075;
              v1742 = v1076;
              v1743 = v1077;
              sub_854710(&v1744, 0);
              v1079 = v1078;
              sub_854710(&v1741, 0);
              v1081 = v1080;
              sub_854710(&v1744, 1u);
              v1083 = v1082;
              sub_854710(&v1741, 1u);
              v1085 = v1084;
              sub_854710(&v1744, 2u);
              v1087 = v1086;
              sub_854710(&v1741, 2u);
              v1089 = v1087 * v1088;
              v1070->m_Items[0] = ((v1079 * v1081) + (v1083 * v1085)) + v1089;
              v1091 = *v1714;
              v1092 = v1720;
              v1094 = *&v1091->m_Items[0].x;
              v1095 = v1091->m_Items[0].z;
              v1096 = v1091->m_Items[0].w;
              v1744 = v1738;
              v1745 = v1739;
              v1741 = v1094;
              v1742 = v1095;
              v1743 = v1096;
              sub_854710(&v1744, 0);
              v1098 = v1097;
              sub_854710(&v1741, 0);
              v1100 = v1099;
              sub_854710(&v1744, 1u);
              v1102 = v1101;
              sub_854710(&v1741, 1u);
              v1104 = v1103;
              sub_854710(&v1744, 2u);
              v1106 = v1105;
              sub_854710(&v1741, 2u);
              v1108 = v1736->e_num;
              v1109 = ((v1098 * v1100) + (v1102 * v1104)) + (v1106 * v1107);
              v1111 = v1108->m_Items[0];
              v1113 = (v1718 + 4);
              v1112 = (v1718 + 3);
              v1114 = &v->max_length;
              v1115 = v->m_Items;
              if ((v1109 - v1111) < 0.0)
              {
                v1116 = *v1714;
                sub_854930(v1116->m_Items, 0);
                v1117 = *v1714;
                sub_854930(v1117->m_Items, 1u);
                v1120 = *v1714;
                sub_854930(v1120->m_Items, 2u);
                v1124 = v1736->e_normal;
                v1125 = v1736->e_num;
                v1128 = LODWORD(v1124->m_Items[0].x);
                v1127 = LODWORD(v1124->m_Items[0].y);
                v1129 = LODWORD(v1124->m_Items[0].z);
                v1130 = LODWORD(v1124->m_Items[0].w);
                v1133 = v->m_Items[0].x;
                v1132 = v->m_Items[0].y;
                v1135 = v->m_Items[0].z;
                v1134 = v->m_Items[0].w;
                v1744 = __PAIR64__(v1127, v1128);
                v1745 = __PAIR64__(v1130, v1129);
                v1741 = __PAIR64__(LODWORD(v1132), LODWORD(v1133));
                v1742 = v1135;
                v1743 = v1134;
                sub_854710(&v1744, 0);
                v1137 = v1136;
                sub_854710(&v1741, 0);
                v1139 = v1138;
                sub_854710(&v1744, 1u);
                v1141 = v1140;
                sub_854710(&v1741, 1u);
                v1143 = v1142;
                sub_854710(&v1744, 2u);
                v1145 = v1144;
                sub_854710(&v1741, 2u);
                v1147 = v1145 * v1146;
                v1125->m_Items[0] = ((v1137 * v1139) + (v1141 * v1143)) + v1147;
                v12 = v1713;
                v14 = v1715;
                v1092 = v1720;
                v1113 = (v1718 + 4);
                v1112 = (v1718 + 3);
                v1114 = &v->max_length;
                v1115 = v->m_Items;
              }
              sub_854710(v14, 0);
              sub_854930(v1115, 0);
              sub_854710(v14, 1u);
              sub_854930(v1115, 1u);
              sub_854930(v1115, 2u);
              sub_854710(v1092, 0);
              sub_854930(v1710, 0);
              sub_854710(v1092, 1u);
              sub_854930(v1710, 1u);
              sub_854930(v1710, 2u);
              sub_854710(v1710, 0);
              sub_854930(v1721, 0);
              sub_854710(v1710, 1u);
              sub_854930(v1721, 1u);
              sub_854930(v1721, 2u);
              else
              {
                v87 = *v1112;
                if (!*v1112)
                {
LABEL_79:
                }
              }
              CalcABCD(v, v1113, v1735, v1734, d);
              v1166 = *v1714;
              sub_854930(&v1166->m_Items[1], 0);
              v1168 = *v1714;
              sub_854930(&v1168->m_Items[1], 1u);
              v1171 = *v1714;
              sub_854930(&v1171->m_Items[1], 2u);
              v1175 = v1736->e_normal;
              v1174 = v1736->e_num;
              v1177 = LODWORD(v1175->m_Items[1].x);
              v1178 = LODWORD(v1175->m_Items[1].y);
              v1179 = LODWORD(v1175->m_Items[1].z);
              v1180 = LODWORD(v1175->m_Items[1].w);
              v1182 = *&v->m_Items[1].x;
              v1183 = v->m_Items[1].z;
              v1184 = v->m_Items[1].w;
              v1744 = __PAIR64__(v1178, v1177);
              v1745 = __PAIR64__(v1180, v1179);
              v1741 = v1182;
              v1742 = v1183;
              v1743 = v1184;
              sub_854710(&v1744, 0);
              v1186 = v1185;
              sub_854710(&v1741, 0);
              v1188 = v1187;
              sub_854710(&v1744, 1u);
              v1190 = v1189;
              sub_854710(&v1741, 1u);
              v1192 = v1191;
              sub_854710(&v1744, 2u);
              v1194 = v1193;
              sub_854710(&v1741, 2u);
              v1196 = v1194 * v1195;
              v1174->m_Items[1] = ((v1186 * v1188) + (v1190 * v1192)) + v1196;
              v1198 = *v1714;
              v1199 = &v->m_Items[2];
              v1201 = *&v1198->m_Items[1].x;
              v1202 = v1198->m_Items[1].z;
              v1203 = v1198->m_Items[1].w;
              v1744 = v1738;
              v1745 = v1739;
              v1741 = v1201;
              v1742 = v1202;
              v1743 = v1203;
              sub_854710(&v1744, 0);
              v1205 = v1204;
              sub_854710(&v1741, 0);
              v1207 = v1206;
              sub_854710(&v1744, 1u);
              v1209 = v1208;
              sub_854710(&v1741, 1u);
              v1211 = v1210;
              sub_854710(&v1744, 2u);
              v1213 = v1212;
              sub_854710(&v1741, 2u);
              v1215 = v1736->e_num;
              v1216 = ((v1205 * v1207) + (v1209 * v1211)) + (v1213 * v1214);
              v1218 = v1215->m_Items[1];
              v1219 = v1723;
              v1220 = v->m_Items;
              v1221 = &v->max_length;
              if ((v1216 - v1218) < 0.0)
              {
                v1222 = *v1714;
                sub_854930(&v1222->m_Items[1], 0);
                v1225 = *v1714;
                sub_854930(&v1225->m_Items[1], 1u);
                v1228 = *v1714;
                sub_854930(&v1228->m_Items[1], 2u);
                v1232 = v1736->e_normal;
                v1233 = v1736->e_num;
                v1235 = LODWORD(v1232->m_Items[1].x);
                v1236 = LODWORD(v1232->m_Items[1].y);
                v1238 = LODWORD(v1232->m_Items[1].z);
                v1237 = LODWORD(v1232->m_Items[1].w);
                v1241 = v->m_Items[1].x;
                v1240 = v->m_Items[1].y;
                v1243 = v->m_Items[1].z;
                v1242 = v->m_Items[1].w;
                v1744 = __PAIR64__(v1236, v1235);
                v1745 = __PAIR64__(v1237, v1238);
                v1741 = __PAIR64__(LODWORD(v1240), LODWORD(v1241));
                v1742 = v1243;
                v1743 = v1242;
                sub_854710(&v1744, 0);
                v1245 = v1244;
                sub_854710(&v1741, 0);
                v1247 = v1246;
                sub_854710(&v1744, 1u);
                v1249 = v1248;
                sub_854710(&v1741, 1u);
                v1251 = v1250;
                sub_854710(&v1744, 2u);
                v1253 = v1252;
                sub_854710(&v1741, 2u);
                v1255 = v1253 * v1254;
                v1233->m_Items[1] = ((v1245 * v1247) + (v1249 * v1251)) + v1255;
                v12 = v1713;
                v1219 = v1723;
                v1220 = v->m_Items;
                v1092 = v1720;
                v1199 = &v->m_Items[2];
                v1221 = &v->max_length;
              }
              v1257 = v1736->numedges;
              sub_854710(v1092, 0);
              sub_854930(v1220, 0);
              sub_854710(v1092, 1u);
              sub_854930(v1220, 1u);
              sub_854930(v1220, 2u);
              v1263 = *v12;
              if (v1257 == 3)
              {
                sub_854710(v1219, 0);
                v592 = (v1718 + 4);
                v591 = (v1718 + 3);
                sub_854930(v1710, 0);
                sub_854710(v1219, 1u);
                sub_854930(v1710, 1u);
                sub_854930(v1710, 2u);
                sub_854710(v1710, 0);
                sub_854930(v1199, 0);
                sub_854710(v1710, 1u);
                sub_854930(v1199, 1u);
                v605 = &v1736->e_normal;
                sub_854930(v1199, 2u);
                  goto LABEL_1272;
LABEL_657:
LABEL_1272:
                v606 = *v591;
                if (!*v591)
                {
LABEL_1321:
                }
                goto LABEL_1273;
              }
              sub_854710(v1726, 0);
              sub_854930(v1710, 0);
              sub_854710(v1726, 1u);
              sub_854930(v1710, 1u);
              sub_854930(v1710, 2u);
              sub_854710(v1710, 0);
              sub_854930(v1199, 0);
              sub_854710(v1710, 1u);
              sub_854930(v1199, 1u);
              sub_854930(v1199, 2u);
              else
              {
                v111 = *v1728;
                if (!*v1728)
                {
LABEL_99:
                }
              }
              CalcABCD(v, v1727, v1735, v1734, d);
              v1506 = *v1714;
              sub_854930(&v1506->m_Items[2], 0);
              v1508 = *v1714;
              sub_854930(&v1508->m_Items[2], 1u);
              v1511 = *v1714;
              sub_854930(&v1511->m_Items[2], 2u);
              v1515 = v1736->e_normal;
              v1514 = v1736->e_num;
              v1517 = LODWORD(v1515->m_Items[2].x);
              v1518 = LODWORD(v1515->m_Items[2].y);
              v1519 = LODWORD(v1515->m_Items[2].z);
              v1520 = LODWORD(v1515->m_Items[2].w);
              v1522 = *&v->m_Items[2].x;
              v1523 = v->m_Items[2].z;
              v1524 = v->m_Items[2].w;
              v1744 = __PAIR64__(v1518, v1517);
              v1745 = __PAIR64__(v1520, v1519);
              v1741 = v1522;
              v1742 = v1523;
              v1743 = v1524;
              sub_854710(&v1744, 0);
              v1526 = v1525;
              sub_854710(&v1741, 0);
              v1528 = v1527;
              sub_854710(&v1744, 1u);
              v1530 = v1529;
              sub_854710(&v1741, 1u);
              v1532 = v1531;
              sub_854710(&v1744, 2u);
              v1534 = v1533;
              sub_854710(&v1741, 2u);
              v1536 = v1534 * v1535;
              v1514->m_Items[2] = ((v1526 * v1528) + (v1530 * v1532)) + v1536;
              v1538 = *v1714;
              v1539 = &v->m_Items[2];
              v1541 = *&v1538->m_Items[2].x;
              v1542 = v1538->m_Items[2].z;
              v1543 = v1538->m_Items[2].w;
              v1744 = v1738;
              v1745 = v1739;
              v1741 = v1541;
              v1742 = v1542;
              v1743 = v1543;
              sub_854710(&v1744, 0);
              v1545 = v1544;
              sub_854710(&v1741, 0);
              v1547 = v1546;
              sub_854710(&v1744, 1u);
              v1549 = v1548;
              sub_854710(&v1741, 1u);
              v1551 = v1550;
              sub_854710(&v1744, 2u);
              v1553 = v1552;
              sub_854710(&v1741, 2u);
              v1555 = v1736->e_num;
              v1556 = ((v1545 * v1547) + (v1549 * v1551)) + (v1553 * v1554);
              v1558 = v1555->m_Items[2];
              v1559 = v1723;
              v1560 = v->m_Items;
              v727 = (v1718 + 4);
              v726 = (v1718 + 3);
              v1561 = &v->max_length;
              if ((v1556 - v1558) < 0.0)
              {
                v1562 = *v1714;
                sub_854930(&v1562->m_Items[2], 0);
                v1564 = *v1714;
                sub_854930(&v1564->m_Items[2], 1u);
                v1567 = *v1714;
                sub_854930(&v1567->m_Items[2], 2u);
                v1571 = v1736->e_normal;
                v1572 = v1736->e_num;
                v1575 = LODWORD(v1571->m_Items[2].x);
                v1574 = LODWORD(v1571->m_Items[2].y);
                v1576 = LODWORD(v1571->m_Items[2].z);
                v1577 = LODWORD(v1571->m_Items[2].w);
                v1580 = v->m_Items[2].x;
                v1579 = v->m_Items[2].y;
                v1582 = v->m_Items[2].z;
                v1581 = v->m_Items[2].w;
                v1744 = __PAIR64__(v1574, v1575);
                v1745 = __PAIR64__(v1577, v1576);
                v1741 = __PAIR64__(LODWORD(v1579), LODWORD(v1580));
                v1742 = v1582;
                v1743 = v1581;
                sub_854710(&v1744, 0);
                v1584 = v1583;
                sub_854710(&v1741, 0);
                v1586 = v1585;
                sub_854710(&v1744, 1u);
                v1588 = v1587;
                sub_854710(&v1741, 1u);
                v1590 = v1589;
                sub_854710(&v1744, 2u);
                v1592 = v1591;
                sub_854710(&v1741, 2u);
                v1594 = v1592 * v1593;
                v1572->m_Items[2] = ((v1584 * v1586) + (v1588 * v1590)) + v1594;
                v12 = v1713;
                v1559 = v1723;
                v1560 = v->m_Items;
                v727 = (v1718 + 4);
                v726 = (v1718 + 3);
                v1561 = &v->max_length;
                v1539 = &v->m_Items[2];
              }
              sub_854710(v1726, 0);
              sub_854930(v1560, 0);
              sub_854710(v1726, 1u);
              sub_854930(v1560, 1u);
              sub_854930(v1560, 2u);
              sub_854710(v1559, 0);
              sub_854930(v1710, 0);
              sub_854710(v1559, 1u);
              sub_854930(v1710, 1u);
              sub_854930(v1710, 2u);
              sub_854710(v1710, 0);
              sub_854930(v1539, 0);
              sub_854710(v1710, 1u);
              sub_854930(v1539, 1u);
              v781 = &v1736->e_normal;
              sub_854930(v1539, 2u);
                goto LABEL_1542;
LABEL_841:
                goto LABEL_1542;
              v782 = *v726;
              if (!*v726)
                goto LABEL_14;
LABEL_1543:
              CalcABCD(v, v727, v1735, v1734, d);
              v1612 = *v781;
              sub_854930(v1612 + 80, 0);
              v1614 = *v781;
              sub_854930(v1614 + 80, 1u);
              v1493 = *v781;
              if (*v726 <= 2)
                goto LABEL_1555;
              goto LABEL_1556;
            }
            v1736->mode2D = 1;
            sub_854710(v1723, 0);
            *(v1707 + 8) = v313;
            sub_854710(v1723, 2u);
            *(v1707 + 9) = v314;
            sub_854710(v1723, 0);
            *(v1706 + 8) = v317;
            sub_854710(v1723, 2u);
            *(v1706 + 9) = v318;
            if (v1736->numedges >= 2)
            {
              v320 = v1715;
              v321 = 1;
              do
              {
                v335 = *(v1707 + 8);
                sub_854710(v320, 0);
                if (v335 > v337)
                {
                  sub_854710(v320, 0);
                  *(v1707 + 8) = v323;
                  if (*v1709 <= 1u)
                  {
LABEL_402:
                  }
                }
                else if (*v1709 <= 1u)
                {
                  goto LABEL_402;
                }
                v338 = *(v1707 + 9);
                sub_854710(v320, 2u);
                if (v338 > v340)
                {
                  sub_854710(v320, 2u);
                  *(v1707 + 9) = v325;
                  if (!*v1737)
                  {
LABEL_393:
                  }
                }
                else if (!*v1737)
                {
                  goto LABEL_393;
                }
                v341 = *(v1706 + 8);
                sub_854710(v320, 0);
                if (v341 < v343)
                {
                  sub_854710(v320, 0);
                  *(v1706 + 8) = v329;
                  if (*v1737 <= 1u)
                  {
LABEL_399:
                  }
                }
                else if (*v1737 <= 1u)
                {
                  goto LABEL_399;
                }
                v344 = *(v1706 + 9);
                sub_854710(v320, 2u);
                if (v344 < v346)
                {
                  sub_854710(v320, 2u);
                  *(v1706 + 9) = v348;
                }
                ++v321;
                v320 += 16;
              }
              while (v321 < v1736->numedges);
            }
            v350 = v1736->min;
            v350->m_Items[0] = *(v1707 + 8);
            v351 = v1736->min;
            v351->m_Items[1] = *(v1707 + 9);
            v354 = v1736->max;
            v354->m_Items[0] = *(v1706 + 8);
            v355 = v1736->max;
            v355->m_Items[1] = *(v1706 + 9);
            v358 = v1736->numedges;
            sub_854710(v1723, 0);
            sub_854710(v1715, 0);
            sub_854710(v1720, 0);
            if (v358 == 3)
            {
              sub_854930(&v1738, 0);
              sub_854930(&v1738, 1u);
              sub_854710(v1723, 2u);
              sub_854710(v1715, 2u);
              sub_854710(v1720, 2u);
            }
            else
            {
              sub_854710(v1726, 0);
              sub_854930(&v1738, 0);
              sub_854930(&v1738, 1u);
              sub_854710(v1723, 2u);
              sub_854710(v1715, 2u);
              sub_854710(v1720, 2u);
              sub_854710(v1726, 2u);
            }
            sub_854930(&v1738, 2u);
            sub_854710(v1723, 0);
            sub_854930(m_Items, 0);
            sub_854930(m_Items, 1u);
            sub_854710(v1723, 2u);
            sub_854930(m_Items, 2u);
            sub_854710(v1715, 0);
            sub_854930(v1710, 0);
            sub_854930(v1710, 1u);
            sub_854710(v1715, 2u);
            sub_854930(v1710, 2u);
            sub_854710(v1715, 0);
            sub_854930(v1721, 0);
            sub_854930(v1721, 1u);
            sub_854710(v1715, 2u);
            sub_854930(v1721, 2u);
            else
            {
              v67 = *v1728;
              if (!*v1728)
              {
LABEL_62:
              }
            }
            CalcABCD(v, v1727, v1735, v1734, d);
            v819 = &v1736->e_normal;
            v818 = v1736->e_normal;
            sub_854930(v818->m_Items, 0);
            v820 = *v819;
            sub_854930(v820 + 32, 1u);
            v823 = *v819;
            v1714 = &v1736->e_normal;
            sub_854930(v823 + 32, 2u);
            v826 = v1736->e_normal;
            v827 = v1736->e_num;
            v829 = LODWORD(v826->m_Items[0].x);
            v828 = LODWORD(v826->m_Items[0].y);
            v831 = LODWORD(v826->m_Items[0].z);
            v830 = LODWORD(v826->m_Items[0].w);
            v832 = *&v->m_Items[0].x;
            v833 = v->m_Items[0].z;
            v834 = v->m_Items[0].w;
            v1744 = __PAIR64__(v828, v829);
            v1745 = __PAIR64__(v830, v831);
            v1741 = v832;
            v1742 = v833;
            v1743 = v834;
            sub_854710(&v1744, 0);
            v836 = v835;
            sub_854710(&v1741, 0);
            v838 = v837;
            sub_854710(&v1744, 1u);
            v840 = v839;
            sub_854710(&v1741, 1u);
            v842 = v841;
            sub_854710(&v1744, 2u);
            v844 = v843;
            sub_854710(&v1741, 2u);
            v846 = v844 * v845;
            v827->m_Items[0] = ((v836 * v838) + (v840 * v842)) + v846;
            v848 = *v1714;
            v849 = v1720;
            v851 = *&v848->m_Items[0].x;
            v852 = v848->m_Items[0].z;
            v853 = v848->m_Items[0].w;
            v1744 = v1738;
            v1745 = v1739;
            v1741 = v851;
            v1742 = v852;
            v1743 = v853;
            sub_854710(&v1744, 0);
            v855 = v854;
            sub_854710(&v1741, 0);
            v857 = v856;
            sub_854710(&v1744, 1u);
            v859 = v858;
            sub_854710(&v1741, 1u);
            v861 = v860;
            sub_854710(&v1744, 2u);
            v863 = v862;
            sub_854710(&v1741, 2u);
            v865 = v1736->e_num;
            v866 = ((v855 * v857) + (v859 * v861)) + (v863 * v864);
            v868 = v865->m_Items[0];
            v870 = (v1718 + 4);
            v869 = (v1718 + 3);
            v871 = &v->max_length;
            v872 = v->m_Items;
            if ((v866 - v868) < 0.0)
            {
              v873 = *v1714;
              sub_854930(v873->m_Items, 0);
              v874 = *v1714;
              sub_854930(v874->m_Items, 1u);
              v877 = *v1714;
              sub_854930(v877->m_Items, 2u);
              v881 = v1736->e_normal;
              v882 = v1736->e_num;
              v885 = LODWORD(v881->m_Items[0].x);
              v884 = LODWORD(v881->m_Items[0].y);
              v886 = LODWORD(v881->m_Items[0].z);
              v887 = LODWORD(v881->m_Items[0].w);
              v890 = v->m_Items[0].x;
              v889 = v->m_Items[0].y;
              v892 = v->m_Items[0].z;
              v891 = v->m_Items[0].w;
              v1744 = __PAIR64__(v884, v885);
              v1745 = __PAIR64__(v887, v886);
              v1741 = __PAIR64__(LODWORD(v889), LODWORD(v890));
              v1742 = v892;
              v1743 = v891;
              sub_854710(&v1744, 0);
              v894 = v893;
              sub_854710(&v1741, 0);
              v896 = v895;
              sub_854710(&v1744, 1u);
              v898 = v897;
              sub_854710(&v1741, 1u);
              v900 = v899;
              sub_854710(&v1744, 2u);
              v902 = v901;
              sub_854710(&v1741, 2u);
              v904 = v902 * v903;
              v882->m_Items[0] = ((v894 * v896) + (v898 * v900)) + v904;
              v12 = v1713;
              v14 = v1715;
              v849 = v1720;
              v870 = (v1718 + 4);
              v869 = (v1718 + 3);
              v871 = &v->max_length;
              v872 = v->m_Items;
            }
            sub_854710(v14, 0);
            sub_854930(v872, 0);
            sub_854930(v872, 1u);
            sub_854710(v14, 2u);
            sub_854930(v872, 2u);
            sub_854710(v849, 0);
            sub_854930(v1710, 0);
            sub_854930(v1710, 1u);
            sub_854710(v849, 2u);
            sub_854930(v1710, 2u);
            sub_854710(v849, 0);
            sub_854930(v1721, 0);
            sub_854930(v1721, 1u);
            sub_854710(v849, 2u);
            sub_854930(v1721, 2u);
            else
            {
              v74 = *v869;
              if (!*v869)
              {
LABEL_68:
              }
            }
            CalcABCD(v, v870, v1735, v1734, d);
            v923 = *v1714;
            sub_854930(&v923->m_Items[1], 0);
            v925 = *v1714;
            sub_854930(&v925->m_Items[1], 1u);
            v928 = *v1714;
            sub_854930(&v928->m_Items[1], 2u);
            v932 = v1736->e_normal;
            v931 = v1736->e_num;
            v934 = LODWORD(v932->m_Items[1].x);
            v935 = LODWORD(v932->m_Items[1].y);
            v936 = LODWORD(v932->m_Items[1].z);
            v937 = LODWORD(v932->m_Items[1].w);
            v939 = *&v->m_Items[1].x;
            v940 = v->m_Items[1].z;
            v941 = v->m_Items[1].w;
            v1744 = __PAIR64__(v935, v934);
            v1745 = __PAIR64__(v937, v936);
            v1741 = v939;
            v1742 = v940;
            v1743 = v941;
            sub_854710(&v1744, 0);
            v943 = v942;
            sub_854710(&v1741, 0);
            v945 = v944;
            sub_854710(&v1744, 1u);
            v947 = v946;
            sub_854710(&v1741, 1u);
            v949 = v948;
            sub_854710(&v1744, 2u);
            v951 = v950;
            sub_854710(&v1741, 2u);
            v953 = v951 * v952;
            v931->m_Items[1] = ((v943 * v945) + (v947 * v949)) + v953;
            v955 = *v1714;
            v956 = &v->m_Items[2];
            v958 = *&v955->m_Items[1].x;
            v959 = v955->m_Items[1].z;
            v960 = v955->m_Items[1].w;
            v1744 = v1738;
            v1745 = v1739;
            v1741 = v958;
            v1742 = v959;
            v1743 = v960;
            sub_854710(&v1744, 0);
            v962 = v961;
            sub_854710(&v1741, 0);
            v964 = v963;
            sub_854710(&v1744, 1u);
            v966 = v965;
            sub_854710(&v1741, 1u);
            v968 = v967;
            sub_854710(&v1744, 2u);
            v970 = v969;
            sub_854710(&v1741, 2u);
            v972 = v1736->e_num;
            v973 = ((v962 * v964) + (v966 * v968)) + (v970 * v971);
            v975 = v972->m_Items[1];
            v976 = v1723;
            v977 = v->m_Items;
            v978 = &v->max_length;
            if ((v973 - v975) < 0.0)
            {
              v979 = *v1714;
              sub_854930(&v979->m_Items[1], 0);
              v982 = *v1714;
              sub_854930(&v982->m_Items[1], 1u);
              v985 = *v1714;
              sub_854930(&v985->m_Items[1], 2u);
              v989 = v1736->e_normal;
              v990 = v1736->e_num;
              v992 = LODWORD(v989->m_Items[1].x);
              v993 = LODWORD(v989->m_Items[1].y);
              v995 = LODWORD(v989->m_Items[1].z);
              v994 = LODWORD(v989->m_Items[1].w);
              v998 = v->m_Items[1].x;
              v997 = v->m_Items[1].y;
              v1000 = v->m_Items[1].z;
              v999 = v->m_Items[1].w;
              v1744 = __PAIR64__(v993, v992);
              v1745 = __PAIR64__(v994, v995);
              v1741 = __PAIR64__(LODWORD(v997), LODWORD(v998));
              v1742 = v1000;
              v1743 = v999;
              sub_854710(&v1744, 0);
              v1002 = v1001;
              sub_854710(&v1741, 0);
              v1004 = v1003;
              sub_854710(&v1744, 1u);
              v1006 = v1005;
              sub_854710(&v1741, 1u);
              v1008 = v1007;
              sub_854710(&v1744, 2u);
              v1010 = v1009;
              sub_854710(&v1741, 2u);
              v1012 = v1010 * v1011;
              v990->m_Items[1] = ((v1002 * v1004) + (v1006 * v1008)) + v1012;
              v12 = v1713;
              v976 = v1723;
              v977 = v->m_Items;
              v849 = v1720;
              v956 = &v->m_Items[2];
              v978 = &v->max_length;
            }
            v1014 = v1736->numedges;
            sub_854710(v849, 0);
            sub_854930(v977, 0);
            sub_854930(v977, 1u);
            sub_854710(v849, 2u);
            sub_854930(v977, 2u);
            v1020 = *v12;
            if (v1014 == 3)
            {
              sub_854710(v976, 0);
              sub_854930(v1710, 0);
              sub_854930(v1710, 1u);
              sub_854710(v976, 2u);
              sub_854930(v1710, 2u);
              sub_854710(v976, 0);
              sub_854930(v956, 0);
              sub_854930(v956, 1u);
              sub_854710(v976, 2u);
              sub_854930(v956, 2u);
              else
              {
                v95 = *v1728;
                if (!*v1728)
                {
LABEL_86:
                }
              }
              CalcABCD(v, v1727, v1735, v1734, d);
              v1033 = *v1714;
              sub_854930(&v1033->m_Items[2], 0);
              v1035 = *v1714;
              sub_854930(&v1035->m_Items[2], 1u);
              v1038 = *v1714;
              if (*v1728 <= 2)
              {
LABEL_1285:
              }
              goto LABEL_1286;
            }
            sub_854710(v1726, 0);
            sub_854930(v1710, 0);
            sub_854930(v1710, 1u);
            sub_854710(v1726, 2u);
            sub_854930(v1710, 2u);
            sub_854710(v1726, 0);
            sub_854930(v956, 0);
            sub_854930(v956, 1u);
            sub_854710(v1726, 2u);
            sub_854930(v956, 2u);
            else
            {
              v100 = *v1728;
              if (!*v1728)
              {
LABEL_90:
              }
            }
            CalcABCD(v, v1727, v1735, v1734, d);
            v1379 = *v1714;
            sub_854930(&v1379->m_Items[2], 0);
            v1381 = *v1714;
            sub_854930(&v1381->m_Items[2], 1u);
            v1384 = *v1714;
            sub_854930(&v1384->m_Items[2], 2u);
            v1388 = v1736->e_normal;
            v1387 = v1736->e_num;
            v1390 = LODWORD(v1388->m_Items[2].x);
            v1391 = LODWORD(v1388->m_Items[2].y);
            v1392 = LODWORD(v1388->m_Items[2].z);
            v1393 = LODWORD(v1388->m_Items[2].w);
            v1395 = *&v->m_Items[2].x;
            v1396 = v->m_Items[2].z;
            v1397 = v->m_Items[2].w;
            v1744 = __PAIR64__(v1391, v1390);
            v1745 = __PAIR64__(v1393, v1392);
            v1741 = v1395;
            v1742 = v1396;
            v1743 = v1397;
            sub_854710(&v1744, 0);
            v1399 = v1398;
            sub_854710(&v1741, 0);
            v1401 = v1400;
            sub_854710(&v1744, 1u);
            v1403 = v1402;
            sub_854710(&v1741, 1u);
            v1405 = v1404;
            sub_854710(&v1744, 2u);
            v1407 = v1406;
            sub_854710(&v1741, 2u);
            v1409 = v1407 * v1408;
            v1387->m_Items[2] = ((v1399 * v1401) + (v1403 * v1405)) + v1409;
            v1411 = *v1714;
            v1412 = &v->m_Items[2];
            v1414 = *&v1411->m_Items[2].x;
            v1415 = v1411->m_Items[2].z;
            v1416 = v1411->m_Items[2].w;
            v1744 = v1738;
            v1745 = v1739;
            v1741 = v1414;
            v1742 = v1415;
            v1743 = v1416;
            sub_854710(&v1744, 0);
            v1418 = v1417;
            sub_854710(&v1741, 0);
            v1420 = v1419;
            sub_854710(&v1744, 1u);
            v1422 = v1421;
            sub_854710(&v1741, 1u);
            v1424 = v1423;
            sub_854710(&v1744, 2u);
            v1426 = v1425;
            sub_854710(&v1741, 2u);
            v1428 = v1736->e_num;
            v1429 = ((v1418 * v1420) + (v1422 * v1424)) + (v1426 * v1427);
            v1431 = v1428->m_Items[2];
            v1432 = v1723;
            v1433 = v->m_Items;
            v1435 = (v1718 + 4);
            v1434 = (v1718 + 3);
            v1436 = &v->max_length;
            if ((v1429 - v1431) < 0.0)
            {
              v1437 = *v1714;
              sub_854930(&v1437->m_Items[2], 0);
              v1439 = *v1714;
              sub_854930(&v1439->m_Items[2], 1u);
              v1442 = *v1714;
              sub_854930(&v1442->m_Items[2], 2u);
              v1446 = v1736->e_normal;
              v1447 = v1736->e_num;
              v1450 = LODWORD(v1446->m_Items[2].x);
              v1449 = LODWORD(v1446->m_Items[2].y);
              v1451 = LODWORD(v1446->m_Items[2].z);
              v1452 = LODWORD(v1446->m_Items[2].w);
              v1455 = v->m_Items[2].x;
              v1454 = v->m_Items[2].y;
              v1457 = v->m_Items[2].z;
              v1456 = v->m_Items[2].w;
              v1744 = __PAIR64__(v1449, v1450);
              v1745 = __PAIR64__(v1452, v1451);
              v1741 = __PAIR64__(LODWORD(v1454), LODWORD(v1455));
              v1742 = v1457;
              v1743 = v1456;
              sub_854710(&v1744, 0);
              v1459 = v1458;
              sub_854710(&v1741, 0);
              v1461 = v1460;
              sub_854710(&v1744, 1u);
              v1463 = v1462;
              sub_854710(&v1741, 1u);
              v1465 = v1464;
              sub_854710(&v1744, 2u);
              v1467 = v1466;
              sub_854710(&v1741, 2u);
              v1469 = v1467 * v1468;
              v1447->m_Items[2] = ((v1459 * v1461) + (v1463 * v1465)) + v1469;
              v12 = v1713;
              v1432 = v1723;
              v1433 = v->m_Items;
              v1435 = (v1718 + 4);
              v1434 = (v1718 + 3);
              v1436 = &v->max_length;
              v1412 = &v->m_Items[2];
            }
            sub_854710(v1726, 0);
            sub_854930(v1433, 0);
            sub_854930(v1433, 1u);
            sub_854710(v1726, 2u);
            sub_854930(v1433, 2u);
            sub_854710(v1432, 0);
            sub_854930(v1710, 0);
            sub_854930(v1710, 1u);
            sub_854710(v1432, 2u);
            sub_854930(v1710, 2u);
            sub_854710(v1432, 0);
            sub_854930(v1412, 0);
            sub_854930(v1412, 1u);
            sub_854710(v1432, 2u);
            sub_854930(v1412, 2u);
            else
            {
              v106 = *v1434;
              if (!*v1434)
              {
LABEL_95:
              }
            }
            CalcABCD(v, v1435, v1735, v1734, d);
            v1488 = *v1714;
            sub_854930(&v1488->m_Items[3], 0);
            v1490 = *v1714;
            sub_854930(&v1490->m_Items[3], 1u);
            v1493 = *v1714;
            if (*v1434 <= 2)
            {
LABEL_1555:
            }
LABEL_1556:
            sub_854930(v1493 + 80, 2u);
            v1620 = v1736->e_normal;
            v1619 = v1736->e_num;
            v1622 = LODWORD(v1620->m_Items[3].x);
            v1623 = LODWORD(v1620->m_Items[3].y);
            v1624 = LODWORD(v1620->m_Items[3].z);
            v1625 = LODWORD(v1620->m_Items[3].w);
            v1627 = *&v->m_Items[2].x;
            v1628 = v->m_Items[2].z;
            v1629 = v->m_Items[2].w;
            v1744 = __PAIR64__(v1623, v1622);
            v1745 = __PAIR64__(v1625, v1624);
            v1741 = v1627;
            v1742 = v1628;
            v1743 = v1629;
            sub_854710(&v1744, 0);
            v1631 = v1630;
            sub_854710(&v1741, 0);
            v1633 = v1632;
            sub_854710(&v1744, 1u);
            v1635 = v1634;
            sub_854710(&v1741, 1u);
            v1637 = v1636;
            sub_854710(&v1744, 2u);
            v1639 = v1638;
            sub_854710(&v1741, 2u);
            v1641 = v1639 * v1640;
            v1619->m_Items[3] = ((v1631 * v1633) + (v1635 * v1637)) + v1641;
            v14 = v1715;
            v1643 = *v1714;
            v1645 = *&v1643->m_Items[3].x;
            v1646 = v1643->m_Items[3].z;
            v1647 = v1643->m_Items[3].w;
            v1744 = v1738;
            v1745 = v1739;
            v1741 = v1645;
            v1742 = v1646;
            v1743 = v1647;
            sub_854710(&v1744, 0);
            v1649 = v1648;
            sub_854710(&v1741, 0);
            v1651 = v1650;
            sub_854710(&v1744, 1u);
            v1653 = v1652;
            sub_854710(&v1741, 1u);
            v1655 = v1654;
            sub_854710(&v1744, 2u);
            v1657 = v1656;
            sub_854710(&v1741, 2u);
            v1659 = v1736->e_num;
            v1660 = ((v1649 * v1651) + (v1653 * v1655)) + (v1657 * v1658);
            v1662 = v1659->m_Items[3];
            v1326 = v1725;
            v13 = v1723;
            v1327 = pFace;
            if ((v1660 - v1662) < 0.0)
            {
              v1663 = *v1714;
              sub_854930(&v1663->m_Items[3], 0);
              v1666 = *v1714;
              sub_854930(&v1666->m_Items[3], 1u);
              v1669 = *v1714;
              sub_854930(&v1669->m_Items[3], 2u);
              v1673 = v1736->e_normal;
              v1674 = v1736->e_num;
              v1676 = LODWORD(v1673->m_Items[3].x);
              v1677 = LODWORD(v1673->m_Items[3].y);
              v1678 = LODWORD(v1673->m_Items[3].z);
              v1679 = LODWORD(v1673->m_Items[3].w);
              v1682 = v->m_Items[2].x;
              v1681 = v->m_Items[2].y;
              v1684 = v->m_Items[2].z;
              v1683 = v->m_Items[2].w;
              v1744 = __PAIR64__(v1677, v1676);
              v1745 = __PAIR64__(v1679, v1678);
              v1741 = __PAIR64__(LODWORD(v1681), LODWORD(v1682));
              v1742 = v1684;
              v1743 = v1683;
              sub_854710(&v1744, 0);
              v1686 = v1685;
              sub_854710(&v1741, 0);
              v1688 = v1687;
              sub_854710(&v1744, 1u);
              v1690 = v1689;
              sub_854710(&v1741, 1u);
              v1692 = v1691;
              sub_854710(&v1744, 2u);
              v1694 = v1693;
              sub_854710(&v1741, 2u);
              v1696 = v1694 * v1695;
              v1674->m_Items[3] = ((v1686 * v1688) + (v1690 * v1692)) + v1696;
              goto LABEL_1591;
            }
LABEL_1592:
            v1736->blockID = gfldCollsionBlkNum;
            v1736->resID = resID;
            v1736->matter = 0;
            v1736->pFace = *v1732;
            v1736->pTome = pTome;
            v1736->hojiID = hojiID;
            v1736->npcID = npcID;
            v1736->hitflag = 0;
            ++gfldCollsionNum;
LABEL_1598:
            v15 = v1725 + 1;
            if (v1725 + 1 == nFace)
              goto LABEL_1599;
            break;
        }
      }
    }
LABEL_1599:
    ++v1716;
  }
  while (v1716 != 5);
  ++gfldCollsionBlkNum;
}

// 0x12794a0
void fldClrCollision(void) {
  u64 v2;
  fldHit_c *v3;
  s16 v4;
  Il2CppClass **v5;
  s32 v6;
  struct fldHit_StaticFields *i;
  struct collision_s_array *gfldCollision;

  v2 = 0;
  if ((v4 & 0x200) != 0)
    goto LABEL_11;
LABEL_6:
  v6 = 0;
  for (i = v3->static_fields; v2 < i->gfldCollsionNum; i = v3->static_fields)
  {
    else
    {
      gfldCollision = i->gfldCollision;
      if (v2 >= LODWORD(gfldCollision->max_length))
        goto LABEL_10;
    }
    v5 = &gfldCollision->obj.klass + v2++;
    v5[4]->_1.typeDefinition = 0;
    if ((v4 & 0x200) == 0)
      goto LABEL_6;
LABEL_11:
    v6 = v4 & 0x200;
  }
  i->gfldCollsionNum = 0;
  ooyTestYukaHitIdx = -1;
  gfldCollsionBlkNum = 0;
  gProgramHitNum = 0;
  fldHit_LastHitIdx = -1;
  if (gfldCollision)
  {
    else if ((byte_3F5918C & 1) != 0)
    {
LABEL_28:
      gfldCollision = 0;
      gProgramHit = 0;
      return;
    }
    goto LABEL_28;
  }
}

// 0x1288ec0
void fldHitAllView(void) {
  ;
}

// 0x127ecd0
void fldHitAlloc(void) {
  struct collision_s_array *v2;
  fldHit_c *v3;
  u64 v4;
  u32 *gfldCollision;
  u64 *v6;
  struct fldProgramHit_tag_array *v9;
  struct fldProgramHit_tag_array *v11;
  fldHit_c *v12;
  u64 v13;
  u32 *gProgramHit;
  u64 *v15;
  u64 v17;
  u32 *v19;
  struct fldProgramHit_tag_array *v20;
  struct fldProgramHit_tag_array *v23;
  u32 *Face;
  u64 *v26;

  v2 = NewSpecific(collision_s, 0x800u);
  gfldCollision = v2;
  v4 = 0;
  if ((v3->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
    goto LABEL_11;
  }
  while (1)
  {
LABEL_11:
    v6 = Allocate(collision_s);
    collision_s___ctor(v6);
    *&gfldCollision[2 * v4 + 8] = v6;
    if (v4 == 2047)
      break;
    ++v4;
      goto LABEL_9;
  }
  v9 = NewSpecific(fldProgramHit_tag, 0x40u);
  v11 = v9;
  gProgramHit = v11;
  v13 = 0;
  if ((v12->_2.bitflags2 & 2) != 0)
  {
LABEL_24:
    goto LABEL_26;
  }
  while (1)
  {
LABEL_26:
    v15 = Allocate(fldProgramHit_tag);
    _ctor(v15, 0);
    v17 = 0;
    *&gProgramHit[2 * v13 + 8] = v15;
    {
LABEL_33:
      goto LABEL_35;
    }
    while (1)
    {
LABEL_35:
      v20 = gProgramHit;
      if (v17 >= SLODWORD(v20->m_Items[v13]->Face->max_length))
        break;
      v23 = gProgramHit;
      Face = v23->m_Items[v13]->Face;
      v26 = Allocate(fldResCollisionPolyFace_t);
      fldResCollisionPolyFace_t___ctor(v26);
      v19 = &Face[2 * v17++];
      *(v19 + 4) = v26;
        goto LABEL_33;
    }
    if (++v13 == 64)
      break;
      goto LABEL_24;
  }
}

// 0x128ad10
s32 fldHitChkCamera(sdfVector4_t eyepos, sdfVector4_t disppos, sdfVector4_t *hitpos) {
  s32 fieldID;
  u64 *v7;
  u64 v15;
  struct collision_s_array *gfldCollision;
  struct collision_s_array *v21;
  struct collision_s_array *v24;
  struct fldGlobalWork_t_o *fldGb;
  s32 areaID;
  s32 v31;
  struct collision_s_array *v32;
  struct collision_s_array *v35;
  struct collision_s_array *v39;
  struct collision_s_array *v41;
  struct collision_s_array *v43;
  struct collision_s_array *v45;
  struct collision_s_array *v47;
  struct collision_s_array *v49;
  s32 v51;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  struct collision_s_array *v58;
  collision_s_o *v60;
  s64 v61;
  f32 v62;
  f32 v63;
  f32 v64;
  f32 v65;
  f32 v66;
  f32 v67;
  f32 v68;
  f32 v69;
  f32 v70;
  f32 v71;
  f32 v72;
  f32 v73;
  f32 v74;
  struct collision_s_array *v75;
  f32 num;
  collision_s_o *v78;
  s64 v79;
  f32 v80;
  f32 v81;
  f32 v82;
  f32 v83;
  f32 v84;
  f32 v85;
  f32 v86;
  f32 v87;
  f32 v88;
  f32 v89;
  f32 v90;
  f32 v91;
  f32 v92;
  struct collision_s_array *v93;
  f32 v94;
  f32 v96;
  struct collision_s_array *v101;
  struct collision_s_array *v104;
  struct collision_s_array *v109;
  struct collision_s_array *v111;
  struct collision_s_array *v113;
  struct collision_s_array *v115;
  struct collision_s_array *v117;
  struct collision_s_array *v119;
  struct collision_s_array *v122;
  struct fldResCollPolyTomeName_t_array *TomeName;
  dds3Basic_t_o *v125;
  s64 TomeIdx;
  System_String_o *Name;
  s32 v131;
  dds3BasicArrayHandle_t_o *hndl;
  dds3Basic_t_o *aPtr;
  u64 v134[2];
  u64 v135;
  u64 v136;
  UnityEngine_Vector4_o v137;
  u64 v138[2];
  u64 v139[2];
  u64 v140[2];
  UnityEngine_Vector4_o v141;
  UnityEngine_Vector4_o v142;
  s64 v143;
  f32 v144;
  s32 v145;
  u64 v146;
  u64 v147;
  dds3Basic_t_o *pBasic;

  v142 = eyepos;
  v141 = disppos;
  pBasic = 0;
  hndl = 0;
  aPtr = 0;
  v140[0] = 0;
  v140[1] = 0;
  v139[0] = 0;
  v139[1] = 0;
  v138[0] = 0;
  v138[1] = 0;
  *&v137.x = 0;
  *&v137.z = 0;
  v135 = 0;
  v136 = 0;
  v134[0] = 0;
  v134[1] = 0;
  pBasic = dds3GetControlScene();
  fieldID = fldGb->fieldID;
  if (fieldID < 200)
    goto LABEL_164;
  if (fieldID >= 500)
  {
LABEL_164:
    v7 = Allocate(dds3BasicArrayHandle_t);
    dds3BasicArrayHandle_t___ctor(v7);
    hndl = v7;
    hndl = dds3SceneBasicGetList(&pBasic, 6u);
    if (dds3GetBasicArrayCount(&hndl))
    {
      dds3SetFirstBasicArray(&hndl);
      do
      {
        while (1)
        {
          aPtr = dds3GetBasicArray(&hndl);
          if (dds3MatterObjectBasicGetAlpMode(&aPtr) == 4)
            dds3MatterObjectBasicSetAlpMode(&aPtr, 3);
            break;
          if (!dds3SetNextBasicArray(&hndl))
            goto LABEL_35;
        }
      }
      while (dds3SetNextBasicArray(&hndl));
LABEL_35:
      dds3FreeBasicArrayHandle(&hndl);
    }
  }
  sub_854710(&v142, 0);
  sub_854930(v140, 0);
  sub_854710(&v142, 1u);
  sub_854930(v140, 1u);
  sub_854710(&v142, 2u);
  sub_854930(v140, 2u);
  sub_854710(&v141, 0);
  sub_854930(v139, 0);
  sub_854710(&v141, 1u);
  sub_854930(v139, 1u);
  sub_854710(&v141, 2u);
  sub_854930(v139, 2u);
  v131 = -1;
  v15 = 0;
    goto LABEL_44;
LABEL_42:
LABEL_44:
  while (v15 < gfldCollsionNum)
  {
    else if (ooyCamKakudoY != 0.0)
    {
      goto LABEL_62;
    }
    if (gfldCollision->m_Items[v15]->mode2D == 1)
    {
      v21 = gfldCollision;
      if ((v21->m_Items[v15]->pFace->Attr & 0x100) == 0)
        goto LABEL_41;
    }
LABEL_62:
    v24 = gfldCollision;
    if ((v24->m_Items[v15]->pFace->Attr & 0xA01) != 0)
      goto LABEL_41;
    v31 = fldGb->fieldID;
    areaID = fldGb->areaID;
    v32 = gfldCollision;
    if (fldGbChkHit(v31, areaID + 1, v32->m_Items[v15]->hojiID))
      goto LABEL_41;
    v35 = gfldCollision;
    if (v35->m_Items[v15]->matter)
    {
      sub_854710(v140, 0);
      v39 = gfldCollision;
      sub_854710(&v39->m_Items[v15]->matter->poseset->pos, 0);
      sub_854930(v140, 0);
      sub_854710(v140, 1u);
      v41 = gfldCollision;
      sub_854710(&v41->m_Items[v15]->matter->poseset->pos, 1u);
      sub_854930(v140, 1u);
      sub_854710(v140, 2u);
      v43 = gfldCollision;
      sub_854710(&v43->m_Items[v15]->matter->poseset->pos, 2u);
      sub_854930(v140, 2u);
      sub_854710(v139, 0);
      v45 = gfldCollision;
      sub_854710(&v45->m_Items[v15]->matter->poseset->pos, 0);
      sub_854930(v139, 0);
      sub_854710(v139, 1u);
      v47 = gfldCollision;
      sub_854710(&v47->m_Items[v15]->matter->poseset->pos, 1u);
      sub_854930(v139, 1u);
      sub_854710(v139, 2u);
      v49 = gfldCollision;
      sub_854710(&v49->m_Items[v15]->matter->poseset->pos, 2u);
      sub_854930(v139, 2u);
      v51 = 1;
    }
    else
    {
      v51 = 0;
    }
    sub_854710(v140, 0);
    sub_854930(&v137, 0);
    sub_854710(v140, 1u);
    sub_854930(&v137, 1u);
    sub_854710(v140, 2u);
    sub_854930(&v137, 2u);
    sub_854710(v139, 0);
    sub_854930(&v135, 0);
    sub_854710(v139, 1u);
    sub_854930(&v135, 1u);
    sub_854710(v139, 2u);
    sub_854930(&v135, 2u);
    x = v137.x;
    y = v137.y;
    z = v137.z;
    w = v137.w;
    v58 = gfldCollision;
    v60 = v58->m_Items[v15];
    v61 = *&v60->normal.x;
    v62 = v60->normal.z;
    *&v60 = v60->normal.w;
    v146 = __PAIR64__(LODWORD(y), LODWORD(x));
    v147 = __PAIR64__(LODWORD(w), LODWORD(z));
    v143 = v61;
    v144 = v62;
    v145 = v60;
    sub_854710(&v146, 0);
    v64 = v63;
    sub_854710(&v143, 0);
    v66 = v65;
    sub_854710(&v146, 1u);
    v68 = v67;
    sub_854710(&v143, 1u);
    v70 = v69;
    sub_854710(&v146, 2u);
    v72 = v71;
    sub_854710(&v143, 2u);
    v74 = (v64 * v66) + (v68 * v70);
    v75 = gfldCollision;
    num = v75->m_Items[v15]->num;
    v78 = gfldCollision->m_Items[v15];
    v79 = *&v78->normal.x;
    v80 = v78->normal.z;
    *&v78 = v78->normal.w;
    v146 = v135;
    v147 = v136;
    v81 = (v74 + (v72 * v73)) - num;
    v143 = v79;
    v144 = v80;
    v145 = v78;
    sub_854710(&v146, 0);
    v83 = v82;
    sub_854710(&v143, 0);
    v85 = v84;
    sub_854710(&v146, 1u);
    v87 = v86;
    sub_854710(&v143, 1u);
    v89 = v88;
    sub_854710(&v146, 2u);
    v91 = v90;
    sub_854710(&v143, 2u);
    v93 = gfldCollision;
    v94 = ((v83 * v85) + (v87 * v89)) + (v91 * v92);
    v96 = v94 - v93->m_Items[v15]->num;
    if (v81 < 0.0 && v96 >= 0.0 || v81 >= 0.0 && v96 < 0.0)
    {
      sub_854710(&v137, 0);
      sub_854930(v134, 0);
      sub_854710(&v137, 1u);
      sub_854930(v134, 1u);
      sub_854710(&v137, 2u);
      sub_854930(v134, 2u);
      sub_854710(&v135, 0);
      sub_854710(&v137, 0);
      sub_854930(v138, 0);
      sub_854710(&v135, 1u);
      sub_854710(&v137, 1u);
      sub_854930(v138, 1u);
      sub_854710(&v135, 2u);
      sub_854710(&v137, 2u);
      sub_854930(v138, 2u);
      sdfFabs(v81);
      sdfFabs(v81);
      sdfFabs(v96);
      sub_854710(&v137, 0);
      sub_854710(v138, 0);
      sub_854930(&v137, 0);
      sub_854710(&v137, 1u);
      sub_854710(v138, 1u);
      sub_854930(&v137, 1u);
      sub_854710(&v137, 2u);
      sub_854710(v138, 2u);
      sub_854930(&v137, 2u);
      v101 = gfldCollision;
      if (HitPositionInside3(v101->m_Items[v15]->mode2D, gfldCollision->m_Items[v15]->numedges, v137, 2.0, gfldCollision->m_Items[v15]) >= 0.0)
      {
        v104 = gfldCollision;
        if ((v104->m_Items[v15]->pFace->Attr & 0x400) != 0)
        {
          v122 = gfldCollision;
          TomeName = v122->m_Items[v15]->pTome->TomeName;
          v125 = pBasic;
          TomeIdx = gfldCollision->m_Items[v15]->pFace->TomeIdx;
          Name = TomeName->m_Items[TomeIdx]->Name;
          aPtr = dds3SceneBasicSearchNameAndType(v125, 6u, Name);
          dds3MatterObjectBasicSetAlpMode(&aPtr, 4);
          if (!v51)
            goto LABEL_41;
LABEL_133:
          sub_854710(v140, 0);
          v109 = gfldCollision;
          sub_854710(&v109->m_Items[v15]->matter->poseset->pos, 0);
          sub_854930(v140, 0);
          sub_854710(v140, 1u);
          v111 = gfldCollision;
          sub_854710(&v111->m_Items[v15]->matter->poseset->pos, 1u);
          sub_854930(v140, 1u);
          sub_854710(v140, 2u);
          v113 = gfldCollision;
          sub_854710(&v113->m_Items[v15]->matter->poseset->pos, 2u);
          sub_854930(v140, 2u);
          sub_854710(v139, 0);
          v115 = gfldCollision;
          sub_854710(&v115->m_Items[v15]->matter->poseset->pos, 0);
          sub_854930(v139, 0);
          sub_854710(v139, 1u);
          v117 = gfldCollision;
          sub_854710(&v117->m_Items[v15]->matter->poseset->pos, 1u);
          sub_854930(v139, 1u);
          sub_854710(v139, 2u);
          v119 = gfldCollision;
          sub_854710(&v119->m_Items[v15]->matter->poseset->pos, 2u);
          sub_854930(v139, 2u);
          goto LABEL_41;
        }
        sub_854710(&v135, 0);
        sub_854710(v134, 0);
        sub_854930(v138, 0);
        sub_854710(&v135, 1u);
        sub_854710(v134, 1u);
        sub_854930(v138, 1u);
        sub_854710(&v135, 2u);
        sub_854710(v134, 2u);
        sub_854930(v138, 2u);
        sdfFabs(v81);
        sdfFabs(v81);
        sdfFabs(v96);
        sub_854710(v134, 0);
        sub_854710(v138, 0);
        sub_854930(v134, 0);
        sub_854710(v134, 1u);
        sub_854710(v138, 1u);
        sub_854930(v134, 1u);
        sub_854710(v134, 2u);
        sub_854710(v138, 2u);
        sub_854930(v134, 2u);
        sub_854710(v134, 0);
        sub_854930(&v137, 0);
        sub_854710(v134, 1u);
        sub_854930(&v137, 1u);
        sub_854710(v134, 2u);
        sub_854930(&v137, 2u);
        sub_854710(&v137, 0);
        sub_854930(v140, 0);
        sub_854710(&v137, 1u);
        sub_854930(v140, 1u);
        sub_854710(&v137, 2u);
        sub_854930(v140, 2u);
        v131 = v15;
      }
    }
    if (v51)
      goto LABEL_133;
LABEL_41:
    ++v15;
      goto LABEL_42;
  }
  sub_854710(v140, 0);
  sub_854930(hitpos, 0);
  sub_854710(v140, 1u);
  sub_854930(hitpos, 1u);
  sub_854710(v140, 2u);
  sub_854930(hitpos, 2u);
  return v131;
}

// 0x128c2c0
s32 fldHitChkEnemy(sdfVector4_t cpos, sdfVector4_t tpos, sdfVector4_t hitpos) {
  u64 v6;
  struct collision_s_array *gfldCollision;
  struct collision_s_array *v12;
  struct collision_s_array *v15;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  struct collision_s_array *v23;
  struct collision_s_array *v26;
  struct collision_s_array *v30;
  struct collision_s_array *v32;
  struct collision_s_array *v34;
  struct collision_s_array *v36;
  struct collision_s_array *v38;
  struct collision_s_array *v40;
  s32 v42;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  struct collision_s_array *v49;
  collision_s_o *v51;
  s64 v52;
  f32 v53;
  f32 v54;
  f32 v55;
  f32 v56;
  f32 v57;
  f32 v58;
  f32 v59;
  f32 v60;
  f32 v61;
  f32 v62;
  f32 v63;
  f32 v64;
  f32 v65;
  struct collision_s_array *v66;
  f32 num;
  collision_s_o *v69;
  s64 v70;
  f32 v71;
  f32 v72;
  f32 v73;
  f32 v74;
  f32 v75;
  f32 v76;
  f32 v77;
  f32 v78;
  f32 v79;
  f32 v80;
  f32 v81;
  f32 v82;
  f32 v83;
  struct collision_s_array *v84;
  f32 v85;
  f32 v87;
  struct collision_s_array *v92;
  struct collision_s_array *v97;
  struct collision_s_array *v99;
  struct collision_s_array *v101;
  struct collision_s_array *v103;
  struct collision_s_array *v105;
  struct collision_s_array *v107;
  u64 v110[2];
  u64 v111;
  u64 v112;
  UnityEngine_Vector4_o v113;
  u64 v114[2];
  u64 v115[2];
  u64 v116[2];
  u64 v117[2];
  UnityEngine_Vector4_o v118;
  UnityEngine_Vector4_o v119;
  s64 v120;
  f32 v121;
  s32 v122;
  u64 v123;
  u64 v124;
  s32 v125;
  s64 v126;
  s64 v127;

  v119 = cpos;
  v118 = tpos;
  v117[0] = v126;
  v117[1] = v127;
  v116[0] = 0;
  v116[1] = 0;
  v115[0] = 0;
  v115[1] = 0;
  v114[0] = 0;
  v114[1] = 0;
  *&v113.x = 0;
  *&v113.z = 0;
  v111 = 0;
  v112 = 0;
  v110[0] = 0;
  v110[1] = 0;
  dds3GetControlScene();
  sub_854710(&v119, 0);
  sub_854930(v116, 0);
  sub_854710(&v119, 1u);
  sub_854930(v116, 1u);
  sub_854710(&v119, 2u);
  sub_854930(v116, 2u);
  sub_854710(&v118, 0);
  sub_854930(v115, 0);
  sub_854710(&v118, 1u);
  sub_854930(v115, 1u);
  sub_854710(&v118, 2u);
  sub_854930(v115, 2u);
  v125 = -1;
  v6 = 0;
  {
LABEL_9:
  }
  while (1)
  {
    if (v6 >= gfldCollsionNum)
      break;
    else
    {
      if (v6 >= LODWORD(gfldCollision->max_length))
        goto LABEL_15;
    }
    if (gfldCollision->m_Items[v6]->mode2D != 1)
      goto LABEL_23;
    v12 = gfldCollision;
    if ((v12->m_Items[v6]->pFace->Attr & 0x100) != 0)
    {
LABEL_23:
      v15 = gfldCollision;
      if ((v15->m_Items[v6]->pFace->Attr & 0xE01) == 0)
      {
        fieldID = fldGb->fieldID;
        areaID = fldGb->areaID;
        v23 = gfldCollision;
        if (!fldGbChkHit(fieldID, areaID + 1, v23->m_Items[v6]->hojiID))
        {
          v26 = gfldCollision;
          if (v26->m_Items[v6]->matter)
          {
            sub_854710(v116, 0);
            v30 = gfldCollision;
            sub_854710(&v30->m_Items[v6]->matter->poseset->pos, 0);
            sub_854930(v116, 0);
            sub_854710(v116, 1u);
            v32 = gfldCollision;
            sub_854710(&v32->m_Items[v6]->matter->poseset->pos, 1u);
            sub_854930(v116, 1u);
            sub_854710(v116, 2u);
            v34 = gfldCollision;
            sub_854710(&v34->m_Items[v6]->matter->poseset->pos, 2u);
            sub_854930(v116, 2u);
            sub_854710(v115, 0);
            v36 = gfldCollision;
            sub_854710(&v36->m_Items[v6]->matter->poseset->pos, 0);
            sub_854930(v115, 0);
            sub_854710(v115, 1u);
            v38 = gfldCollision;
            sub_854710(&v38->m_Items[v6]->matter->poseset->pos, 1u);
            sub_854930(v115, 1u);
            sub_854710(v115, 2u);
            v40 = gfldCollision;
            sub_854710(&v40->m_Items[v6]->matter->poseset->pos, 2u);
            sub_854930(v115, 2u);
            v42 = 1;
          }
          else
          {
            v42 = 0;
          }
          sub_854710(v116, 0);
          sub_854930(&v113, 0);
          sub_854710(v116, 1u);
          sub_854930(&v113, 1u);
          sub_854710(v116, 2u);
          sub_854930(&v113, 2u);
          sub_854710(v115, 0);
          sub_854930(&v111, 0);
          sub_854710(v115, 1u);
          sub_854930(&v111, 1u);
          sub_854710(v115, 2u);
          sub_854930(&v111, 2u);
          x = v113.x;
          y = v113.y;
          z = v113.z;
          w = v113.w;
          v49 = gfldCollision;
          v51 = v49->m_Items[v6];
          v52 = *&v51->normal.x;
          v53 = v51->normal.z;
          *&v51 = v51->normal.w;
          v123 = __PAIR64__(LODWORD(y), LODWORD(x));
          v124 = __PAIR64__(LODWORD(w), LODWORD(z));
          v120 = v52;
          v121 = v53;
          v122 = v51;
          sub_854710(&v123, 0);
          v55 = v54;
          sub_854710(&v120, 0);
          v57 = v56;
          sub_854710(&v123, 1u);
          v59 = v58;
          sub_854710(&v120, 1u);
          v61 = v60;
          sub_854710(&v123, 2u);
          v63 = v62;
          sub_854710(&v120, 2u);
          v65 = (v55 * v57) + (v59 * v61);
          v66 = gfldCollision;
          num = v66->m_Items[v6]->num;
          v69 = gfldCollision->m_Items[v6];
          v70 = *&v69->normal.x;
          v71 = v69->normal.z;
          *&v69 = v69->normal.w;
          v123 = v111;
          v124 = v112;
          v72 = (v65 + (v63 * v64)) - num;
          v120 = v70;
          v121 = v71;
          v122 = v69;
          sub_854710(&v123, 0);
          v74 = v73;
          sub_854710(&v120, 0);
          v76 = v75;
          sub_854710(&v123, 1u);
          v78 = v77;
          sub_854710(&v120, 1u);
          v80 = v79;
          sub_854710(&v123, 2u);
          v82 = v81;
          sub_854710(&v120, 2u);
          v84 = gfldCollision;
          v85 = ((v74 * v76) + (v78 * v80)) + (v82 * v83);
          v87 = v85 - v84->m_Items[v6]->num;
          if (v72 < 0.0 && v87 >= 0.0 || v72 >= 0.0 && v87 < 0.0)
          {
            sub_854710(&v113, 0);
            sub_854930(v110, 0);
            sub_854710(&v113, 1u);
            sub_854930(v110, 1u);
            sub_854710(&v113, 2u);
            sub_854930(v110, 2u);
            sub_854710(&v111, 0);
            sub_854710(&v113, 0);
            sub_854930(v114, 0);
            sub_854710(&v111, 1u);
            sub_854710(&v113, 1u);
            sub_854930(v114, 1u);
            sub_854710(&v111, 2u);
            sub_854710(&v113, 2u);
            sub_854930(v114, 2u);
            sdfFabs(v72);
            sdfFabs(v72);
            sdfFabs(v87);
            sub_854710(&v113, 0);
            sub_854710(v114, 0);
            sub_854930(&v113, 0);
            sub_854710(&v113, 1u);
            sub_854710(v114, 1u);
            sub_854930(&v113, 1u);
            sub_854710(&v113, 2u);
            sub_854710(v114, 2u);
            sub_854930(&v113, 2u);
            v92 = gfldCollision;
            if (HitPositionInside3(v92->m_Items[v6]->mode2D, gfldCollision->m_Items[v6]->numedges, v113, 70.0, gfldCollision->m_Items[v6]) >= 0.0)
            {
              sub_854710(&v111, 0);
              sub_854710(v110, 0);
              sub_854930(v114, 0);
              sub_854710(&v111, 1u);
              sub_854710(v110, 1u);
              sub_854930(v114, 1u);
              sub_854710(&v111, 2u);
              sub_854710(v110, 2u);
              sub_854930(v114, 2u);
              sdfFabs(v72);
              sdfFabs(v72);
              sdfFabs(v87);
              sub_854710(v110, 0);
              sub_854710(v114, 0);
              sub_854930(v110, 0);
              sub_854710(v110, 1u);
              sub_854710(v114, 1u);
              sub_854930(v110, 1u);
              sub_854710(v110, 2u);
              sub_854710(v114, 2u);
              sub_854930(v110, 2u);
              sub_854710(v110, 0);
              sub_854930(&v113, 0);
              sub_854710(v110, 1u);
              sub_854930(&v113, 1u);
              sub_854710(v110, 2u);
              sub_854930(&v113, 2u);
              sub_854710(&v113, 0);
              sub_854930(v116, 0);
              sub_854710(&v113, 1u);
              sub_854930(v116, 1u);
              sub_854710(&v113, 2u);
              sub_854930(v116, 2u);
              v125 = v6;
            }
          }
          if (v42)
          {
            sub_854710(v116, 0);
            v97 = gfldCollision;
            sub_854710(&v97->m_Items[v6]->matter->poseset->pos, 0);
            sub_854930(v116, 0);
            sub_854710(v116, 1u);
            v99 = gfldCollision;
            sub_854710(&v99->m_Items[v6]->matter->poseset->pos, 1u);
            sub_854930(v116, 1u);
            sub_854710(v116, 2u);
            v101 = gfldCollision;
            sub_854710(&v101->m_Items[v6]->matter->poseset->pos, 2u);
            sub_854930(v116, 2u);
            sub_854710(v115, 0);
            v103 = gfldCollision;
            sub_854710(&v103->m_Items[v6]->matter->poseset->pos, 0);
            sub_854930(v115, 0);
            sub_854710(v115, 1u);
            v105 = gfldCollision;
            sub_854710(&v105->m_Items[v6]->matter->poseset->pos, 1u);
            sub_854930(v115, 1u);
            sub_854710(v115, 2u);
            v107 = gfldCollision;
            sub_854710(&v107->m_Items[v6]->matter->poseset->pos, 2u);
            sub_854930(v115, 2u);
          }
        }
      }
    }
    ++v6;
      goto LABEL_9;
  }
  sub_854710(v116, 0);
  sub_854930(v117, 0);
  sub_854710(v116, 1u);
  sub_854930(v117, 1u);
  sub_854710(v116, 2u);
  sub_854930(v117, 2u);
  return v125;
}

// 0x12825b0
void fldHitChkUnit(sdfVector4_t phys_pos) {
  struct fldDebug_t_o *fldDbg;
  s32 HitView;
  s32 ElvIdx;
  struct collision_s_array *gfldCollision;
  struct collision_s_array *v14;
  struct collision_s_array *v16;
  struct collision_s_array *v18;
  struct collision_s_array *v20;
  struct collision_s_array *v22;
  struct collision_s_array *v24;
  s32 fieldID;
  f32 v32;
  s64 v35;
  s64 v36;
  struct UnityEngine_Vector4_o *p_phys_oldpos;
  u64 v39;
  Il2CppClass **v41;
  struct collision_s_array *v43;
  f32 v46;
  f32 v47;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 v55;
  f32 v58;
  _BOOL4 v59;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  s32 v64;
  char v67;
  u64 v68;
  char v69;
  struct collision_s_array *v73;
  struct collision_s_array *v76;
  struct fldGlobalWork_t_o *fldGb;
  s32 areaID;
  s32 v83;
  struct collision_s_array *v84;
  struct collision_s_array *v87;
  struct fldGlobalWork_t_o *v92;
  s32 v93;
  s32 v94;
  struct collision_s_array *v95;
  struct collision_s_array *v99;
  struct collision_s_array *v103;
  struct collision_s_array *v105;
  struct collision_s_array *v107;
  struct collision_s_array *v109;
  struct collision_s_array *v111;
  struct collision_s_array *v113;
  struct collision_s_array *v115;
  f32 v118;
  f32 v119;
  f32 v120;
  f32 v121;
  struct collision_s_array *v122;
  collision_s_o *v124;
  s64 v125;
  f32 v126;
  f32 v127;
  f32 v128;
  f32 v129;
  f32 v130;
  f32 v131;
  f32 v132;
  f32 v133;
  f32 v134;
  f32 v135;
  f32 v136;
  f32 v138;
  struct collision_s_array *v139;
  f32 v140;
  f32 v142;
  f32 v144;
  struct collision_s_array *v145;
  f32 v146;
  struct collision_s_array *v149;
  struct collision_s_array *v152;
  struct collision_s_array *v155;
  struct collision_s_array *v158;
  struct collision_s_array *v161;
  struct collision_s_array *v164;
  struct collision_s_array *v167;
  struct collision_s_array *v170;
  struct collision_s_array *v173;
  f32 v176;
  struct collision_s_array *v178;
  struct collision_s_array *v181;
  u8 Myuka;
  u32 v184;
  s32 v185;
  struct collision_s_array *v187;
  struct collision_s_array *v190;
  s32 Basyo;
  struct collision_s_array *v194;
  struct fldGlobalWork_t_o *v199;
  struct collision_s_array *v200;
  struct collision_s_array *v203;
  struct fldGlobalWork_t_o *v208;
  struct collision_s_array *v209;
  struct fldGlobalWork_t_o *v211;
  struct collision_s_array *v213;
  struct collision_s_array *v216;
  s32 Spc1;
  struct collision_s_array *v220;
  struct collision_s_array *v223;
  struct collision_s_array *v226;
  s32 Amap0;
  struct collision_s_array *v229;
  struct collision_s_array *v232;
  s32 Amap1;
  struct fldGlobalWork_t_o *v238;
  struct collision_s_array *v239;
  struct UnityEngine_Vector4_array *point;
  f32 v243;
  struct collision_s_array *v245;
  struct collision_s_array *v250;
  struct collision_s_array *v252;
  struct collision_s_array *v254;
  struct collision_s_array *v256;
  f32 v258;
  struct collision_s_array *v262;
  struct collision_s_array *v264;
  struct collision_s_array *v266;
  s32 v269;
  struct collision_s_array *v271;
  struct collision_s_array *v274;
  struct collision_s_array *v276;
  struct collision_s_array *v278;
  struct collision_s_array *v283;
  struct collision_s_array *v285;
  struct collision_s_array *v287;
  struct collision_s_array *v289;
  struct collision_s_array *v291;
  struct collision_s_array *v293;
  struct fldGlobalWork_t_o *v296;
  f32 v297;
  struct fldGlobalWork_t_o *v298;
  f32 v299;
  struct fldGlobalWork_t_o *v300;
  f32 v301;
  struct collision_s_array *v303;
  struct collision_s_array *v307;
  struct collision_s_array *v309;
  struct collision_s_array *v311;
  struct collision_s_array *v313;
  struct collision_s_array *v315;
  struct collision_s_array *v317;
  s64 v321;
  s64 v322;
  s32 v323;
  s32 idx;
  s32 v325;
  u64 v326[2];
  f32 fret;
  u64 v328[2];
  u64 v329[2];
  u64 v330[2];
  s64 v331;
  s64 v332;
  u64 v333[2];
  u64 v334[2];
  UnityEngine_Vector4_o v335;
  UnityEngine_Vector4_o v336;
  s64 v337;
  f32 v338;
  s32 v339;
  u32 v340[6];
  UnityEngine_Vector4_o v341;
  UnityEngine_Vector4_o v342;
  UnityEngine_Vector4_o v343;

  v336 = phys_pos;
  v326[0] = 0;
  v326[1] = 0;
  *&v335.x = 0;
  *&v335.z = 0;
  v334[0] = 0;
  v334[1] = 0;
  fret = 0.0;
  v333[0] = 0;
  v333[1] = 0;
  v331 = 0;
  v332 = 0;
  v330[0] = 0;
  v330[1] = 0;
  v329[0] = 0;
  v329[1] = 0;
  v328[0] = 0;
  v328[1] = 0;
  sub_854690(v326, 0.0, 0.0, 0.0, 1.0);
  HitView = fldDbg->HitView;
  ooyTestKeisyaHitIdx = -1;
  ooyTestYukaHitIdx = -1;
  fldAutoMapNameD(-1);
  fldGb->FootSEUp = 0;
  ElvIdx = fldGb->ElvIdx;
  if (ElvIdx != -1)
  {
    if (gfldCollision->m_Items[ElvIdx]->matter)
    {
      v14 = gfldCollision;
      sub_854710(&v14->m_Items[ElvIdx]->matter->poseset->pos, 0);
      v16 = gfldCollision;
      sub_854710(&v16->m_Items[ElvIdx]->elv, 0);
      sub_854930(v326, 0);
      v18 = gfldCollision;
      sub_854710(&v18->m_Items[ElvIdx]->matter->poseset->pos, 1u);
      v20 = gfldCollision;
      sub_854710(&v20->m_Items[ElvIdx]->elv, 1u);
      sub_854930(v326, 1u);
      v22 = gfldCollision;
      sub_854710(&v22->m_Items[ElvIdx]->matter->poseset->pos, 2u);
      v24 = gfldCollision;
      sub_854710(&v24->m_Items[ElvIdx]->elv, 2u);
      sub_854930(v326, 2u);
    }
    fldGb->ElvIdx = -1;
  }
  if (HitView)
  {
    rsetOtOfs(81);
    rsetTest(1, 5, 128, 1, 0, 0, 1, 2);
    rsetAlpha(0);
  }
  sub_854710(&v336, 0);
  sub_854930(&v335, 0);
  sub_854710(&v336, 1u);
  sub_854930(&v335, 1u);
  sub_854710(&v336, 2u);
  sub_854930(&v335, 2u);
  sub_854710(&phys_oldpos, 0);
  sub_854930(v334, 0);
  sub_854710(&phys_oldpos, 1u);
  sub_854930(v334, 1u);
  sub_854710(&phys_oldpos, 2u);
  sub_854930(v334, 2u);
  sub_854710(&v335, 0);
  sub_854710(v326, 0);
  sub_854930(&v335, 0);
  sub_854710(&v335, 1u);
  sub_854710(v326, 1u);
  sub_854930(&v335, 1u);
  sub_854710(&v335, 2u);
  sub_854710(v326, 2u);
  sub_854930(&v335, 2u);
  fieldID = fldGb->fieldID;
  if (fieldID == 1)
  {
    sub_854710(&v335, 1u);
    sub_854930(&v335, 1u);
    v32 = 25.0;
  }
  else
  {
    sub_854710(&v335, 1u);
    sub_854930(&v335, 1u);
    if (fieldID <= 9)
      v32 = 30.0;
    else
      v32 = 45.0;
  }
  sub_854710(&v335, 0);
  sub_854710(v334, 0);
  sub_854930(&v331, 0);
  sub_854710(&v335, 1u);
  sub_854710(v334, 1u);
  sub_854930(&v331, 1u);
  sub_854710(&v335, 2u);
  sub_854710(v334, 2u);
  sub_854930(&v331, 2u);
  v35 = v331;
  v36 = v332;
  *&v341.x = v35;
  *&v341.z = v36;
  if (MATH_VectorLength(v341) < 0.1)
  {
    sub_854710(v334, 0);
    sub_854930(&v336, 0);
    sub_854710(v334, 1u);
    sub_854930(&v336, 1u);
    sub_854710(v334, 2u);
    p_phys_oldpos = &v336;
    goto LABEL_491;
  }
  v39 = 0;
  {
LABEL_72:
  }
  while (1)
  {
    if (v39 >= gfldCollsionNum)
      break;
    else
    {
      v43 = gfldCollision;
      if (v39 >= LODWORD(v43->max_length))
        goto LABEL_78;
    }
    v41 = &v43->obj.klass + v39++;
    WORD1(v41[4]->_1.generic_class) = 0;
      goto LABEL_72;
  }
  fldGb->WaterIdx = -1;
  fldGb->EncPIDUpper = 0;
  sub_854710(&v335, 0);
  v47 = v46;
  sub_854710(v334, 0);
  v50 = v49;
  sdfFabs(v47 - v50);
  sub_854930(v328, 0);
  sub_854710(&v335, 2u);
  v52 = v51;
  sub_854710(v334, 2u);
  sdfFabs(v52 - v53);
  sub_854930(v328, 2u);
  sub_854710(v328, 0);
  v55 = v54;
  sub_854710(v328, 2u);
  v59 = v55 <= v58;
  x = v336.x;
  y = v336.y;
  z = v336.z;
  w = v336.w;
  v342.x = x;
  v342.y = y;
  v342.z = z;
  v342.w = w;
  v64 = 2 * v59;
  fldHitChkUnitElvOnly(v342);
  v67 = 1;
  v323 = -1;
  idx = -1;
  do
  {
    v68 = 0;
    v69 = v67;
      goto LABEL_96;
LABEL_94:
LABEL_96:
    while (v68 < gfldCollsionNum)
    {
      if (fldGb->fieldID >= 11)
      {
        v73 = gfldCollision;
        v32 = flt_32C3168[v73->m_Items[v68]->mode2D == 1];
      }
      if ((v69 & 1) != 0)
      {
        v76 = gfldCollision;
        if (v64 == v76->m_Items[v68]->mode2D)
          goto LABEL_93;
      }
      else
      {
        v115 = gfldCollision;
        if (v64 != v115->m_Items[v68]->mode2D)
          goto LABEL_93;
      }
      v83 = fldGb->fieldID;
      areaID = fldGb->areaID;
      v84 = gfldCollision;
      if (!fldGbChkHit(v83, areaID + 1, v84->m_Items[v68]->hojiID))
      {
        v87 = gfldCollision;
        if (v87->m_Items[v68]->npcID < 1)
          goto LABEL_138;
        v92 = fldGb;
        v94 = v92->fieldID;
        v93 = v92->areaID;
        v95 = gfldCollision;
        if (!fldGbChkNpc(v94, v93 + 1, v95->m_Items[v68]->npcID))
        {
LABEL_138:
          sub_854710(&v335, 0);
          sub_854930(v330, 0);
          sub_854710(&v335, 1u);
          sub_854930(v330, 1u);
          sub_854710(&v335, 2u);
          sub_854930(v330, 2u);
          sub_854710(v334, 0);
          sub_854930(v329, 0);
          sub_854710(v334, 1u);
          sub_854930(v329, 1u);
          sub_854710(v334, 2u);
          sub_854930(v329, 2u);
          v99 = gfldCollision;
          if (v99->m_Items[v68]->matter)
          {
            sub_854710(&v335, 0);
            v103 = gfldCollision;
            sub_854710(&v103->m_Items[v68]->matter->poseset->pos, 0);
            sub_854930(&v335, 0);
            sub_854710(&v335, 1u);
            v105 = gfldCollision;
            sub_854710(&v105->m_Items[v68]->matter->poseset->pos, 1u);
            sub_854930(&v335, 1u);
            sub_854710(&v335, 2u);
            v107 = gfldCollision;
            sub_854710(&v107->m_Items[v68]->matter->poseset->pos, 2u);
            sub_854930(&v335, 2u);
            sub_854710(v334, 0);
            v109 = gfldCollision;
            sub_854710(&v109->m_Items[v68]->matter->poseset->pos, 0);
            sub_854930(v334, 0);
            sub_854710(v334, 1u);
            v111 = gfldCollision;
            sub_854710(&v111->m_Items[v68]->matter->poseset->pos, 1u);
            sub_854930(v334, 1u);
            sub_854710(v334, 2u);
            v113 = gfldCollision;
            sub_854710(&v113->m_Items[v68]->matter->poseset->pos, 2u);
            sub_854930(v334, 2u);
            v325 = 1;
          }
          else
          {
            v325 = 0;
          }
          v118 = v335.x;
          v119 = v335.y;
          v121 = v335.z;
          v120 = v335.w;
          v122 = gfldCollision;
          v124 = v122->m_Items[v68];
          v125 = *&v124->normal.x;
          v126 = v124->normal.z;
          *&v124 = v124->normal.w;
          *v340 = v118;
          *&v340[1] = v119;
          *&v340[2] = v121;
          *&v340[3] = v120;
          v337 = v125;
          v338 = v126;
          v339 = v124;
          sub_854710(v340, 0);
          v128 = v127;
          sub_854710(&v337, 0);
          v130 = v129;
          sub_854710(v340, 1u);
          v132 = v131;
          sub_854710(&v337, 1u);
          v134 = v133;
          sub_854710(v340, 2u);
          v136 = v135;
          sub_854710(&v337, 2u);
          v139 = gfldCollision;
          v140 = ((v128 * v130) + (v132 * v134)) + (v136 * v138);
          v142 = v140 - v139->m_Items[v68]->num;
          v144 = sdfFabs(v142);
          v145 = gfldCollision;
          v146 = v144;
          if ((v145->m_Items[v68]->pFace->Attr & 0x40) != 0)
          {
            if (v144 >= v32)
              goto LABEL_93;
            v178 = gfldCollision;
            HitPositionInside2(&fret, v178->m_Items[v68]->mode2D, gfldCollision->m_Items[v68]->numedges, v335, v32, gfldCollision->m_Items[v68]);
            if (fret < 0.0)
              goto LABEL_93;
            v181 = gfldCollision;
            Myuka = v181->m_Items[v68]->pFace->Myuka;
            v184 = gfldCollision->m_Items[v68]->pFace->Myuka;
            v185 = 10 * (Myuka & 0xF) + (v184 >> 4);
LABEL_271:
            fldAutoMapNameD(v185);
            goto LABEL_93;
          }
          v149 = gfldCollision;
          if ((v149->m_Items[v68]->pFace->Attr & 0x1000) != 0)
          {
            if (v146 >= v32)
              goto LABEL_93;
            v187 = gfldCollision;
            HitPositionInside2(&fret, v187->m_Items[v68]->mode2D, gfldCollision->m_Items[v68]->numedges, v335, v32, gfldCollision->m_Items[v68]);
            if (fret < 0.0)
              goto LABEL_93;
            v190 = gfldCollision;
            Basyo = v190->m_Items[v68]->pFace->Basyo;
            v185 = Basyo;
            goto LABEL_271;
          }
          v152 = gfldCollision;
          if ((v152->m_Items[v68]->pFace->Attr & 0x2000) != 0)
          {
            if (v146 < v32)
            {
              v194 = gfldCollision;
              HitPositionInside2(&fret, v194->m_Items[v68]->mode2D, gfldCollision->m_Items[v68]->numedges, v335, v32, gfldCollision->m_Items[v68]);
              if (fret >= 0.0)
              {
                v199 = fldGb;
                v200 = gfldCollision;
                v199->EncPIDUpper = v200->m_Items[v68]->pFace->EncIdx;
              }
            }
            goto LABEL_93;
          }
          v155 = gfldCollision;
          if ((v155->m_Items[v68]->pFace->Attr & 0x200) != 0)
          {
            if (v146 < v32)
            {
              v203 = gfldCollision;
              HitPositionInside2(&fret, v203->m_Items[v68]->mode2D, gfldCollision->m_Items[v68]->numedges, v335, v32, gfldCollision->m_Items[v68]);
              if (fret >= 0.0)
              {
                v208 = fldGb;
                v209 = gfldCollision;
                v208->FootSEUp = v209->m_Items[v68]->pFace->Se;
                v211 = fldGb;
                if (v211->FootSEUp == 3)
                {
                  v211->WaterIdx = v68;
                }
              }
            }
            goto LABEL_93;
          }
          v158 = gfldCollision;
          if ((v158->m_Items[v68]->pFace->Attr & 0x8000) != 0)
          {
            if (v146 < v32)
            {
              v213 = gfldCollision;
              HitPositionInside2(&fret, v213->m_Items[v68]->mode2D, gfldCollision->m_Items[v68]->numedges, v335, v32, gfldCollision->m_Items[v68]);
              if (fret >= 0.0)
              {
                v216 = gfldCollision;
                Spc1 = v216->m_Items[v68]->pFace->Spc1;
                if (Spc1 == 3)
                {
                  v238 = fldGb;
                  v239 = gfldCollision;
                  point = v239->m_Items[v68]->point;
                  sub_854710(point->m_Items, 1u);
                  v238->WaterY = v243;
                }
                else if (Spc1 == 1)
                {
                  v220 = gfldCollision;
                  idx = v220->m_Items[v68]->pFace->Spc2;
                }
              }
            }
            goto LABEL_93;
          }
          v161 = gfldCollision;
          if ((v161->m_Items[v68]->pFace->Attr & 0x400) == 0)
          {
            v164 = gfldCollision;
            if ((v164->m_Items[v68]->pFace->Attr & 0x800) != 0)
            {
              if (v146 < v32)
              {
                v223 = gfldCollision;
                HitPositionInside2(&fret, v223->m_Items[v68]->mode2D, gfldCollision->m_Items[v68]->numedges, v335, v32, gfldCollision->m_Items[v68]);
                if (fret >= 0.0)
                {
                  v226 = gfldCollision;
                  Amap0 = v226->m_Items[v68]->pFace->Amap0;
                  fldAutoMapOpenBlock(Amap0);
                  v229 = gfldCollision;
                  if (v229->m_Items[v68]->pFace->Amap1)
                  {
                    v232 = gfldCollision;
                    Amap1 = v232->m_Items[v68]->pFace->Amap1;
                    fldAutoMapNameU(Amap1);
                  }
                }
              }
              goto LABEL_93;
            }
            v167 = gfldCollision;
            if ((v167->m_Items[v68]->pFace->Attr & 0x4000) == 0)
            {
              v170 = gfldCollision;
              if ((v170->m_Items[v68]->pFace->Attr & 0x100) != 0)
              {
                if (v146 < v32)
                {
                  v245 = gfldCollision;
                  HitPositionInside2(&fret, v245->m_Items[v68]->mode2D, gfldCollision->m_Items[v68]->numedges, v335, v32, gfldCollision->m_Items[v68]);
                  if (fret >= 0.0)
                  {
                    ooyTestKeisyaHitIdx = v68;
                  }
                }
                goto LABEL_93;
              }
              if (v146 < v32)
              {
                v173 = gfldCollision;
                HitPositionInside2(&fret, v173->m_Items[v68]->mode2D, gfldCollision->m_Items[v68]->numedges, v335, v32, gfldCollision->m_Items[v68]);
                if (fret < 0.0)
                {
                  if (v325)
                    goto LABEL_461;
                  goto LABEL_93;
                }
                {
                  v176 = -0.75;
                  if (fldDbg->NoClip)
                    goto LABEL_382;
                  goto LABEL_386;
                }
                v176 = -0.75;
                if (!fldDbg->NoClip)
                  goto LABEL_386;
LABEL_382:
                if (!DDS3_PADCHECK_PRESS(11))
                {
LABEL_386:
                  sub_854710(&v335, 0);
                  v250 = gfldCollision;
                  sub_854710(&v250->m_Items[v68]->normal, 0);
                  sub_854930(v333, 0);
                  sub_854710(&v335, 1u);
                  v252 = gfldCollision;
                  sub_854710(&v252->m_Items[v68]->normal, 1u);
                  sub_854930(v333, 1u);
                  sub_854710(&v335, 2u);
                  v254 = gfldCollision;
                  sub_854710(&v254->m_Items[v68]->normal, 2u);
                  sub_854930(v333, 2u);
                  v256 = gfldCollision;
                  sub_854710(&v256->m_Items[v68]->normal, 1u);
                  if (v258 < v176)
                  {
                    ooyTestYukaHitIdx = v68;
                    if ((v323 & 0x80000000) == 0 && v146 > fret)
                      fret = v146;
                    sub_854710(v333, 0);
                    v262 = gfldCollision;
                    sub_854710(&v262->m_Items[v68]->normal, 0);
                    sub_854930(&v335, 0);
                    sub_854710(v333, 1u);
                    v264 = gfldCollision;
                    sub_854710(&v264->m_Items[v68]->normal, 1u);
                    sub_854930(&v335, 1u);
                    sub_854710(v333, 2u);
                    v266 = gfldCollision;
                    sub_854710(&v266->m_Items[v68]->normal, 2u);
                    sub_854930(&v335, 2u);
                    v269 = v323;
                    if (fret == v32)
                      v269 = v68;
                    v323 = v269;
                    v271 = gfldCollision;
                    if (v68 >= LODWORD(v271->max_length))
                      goto LABEL_433;
                    goto LABEL_434;
                  }
                  if (v142 >= 0.0)
                  {
                    if (v146 > fret)
                      fret = v146;
                    sub_854710(v333, 0);
                    v274 = gfldCollision;
                    sub_854710(&v274->m_Items[v68]->normal, 0);
                    sub_854930(&v335, 0);
                    sub_854710(v333, 1u);
                    v276 = gfldCollision;
                    sub_854710(&v276->m_Items[v68]->normal, 1u);
                    sub_854930(&v335, 1u);
                    sub_854710(v333, 2u);
                    v278 = gfldCollision;
                    sub_854710(&v278->m_Items[v68]->normal, 2u);
                    sub_854930(&v335, 2u);
                    v271 = gfldCollision;
                    if (v68 >= LODWORD(v271->max_length))
                    {
LABEL_433:
                    }
LABEL_434:
                    if (v271->m_Items[v68]->matter)
                    {
                      sub_854710(&v335, 0);
                      v283 = gfldCollision;
                      sub_854710(&v283->m_Items[v68]->matter->poseset->pos, 0);
                      sub_854930(&v335, 0);
                      sub_854710(&v335, 1u);
                      v285 = gfldCollision;
                      sub_854710(&v285->m_Items[v68]->matter->poseset->pos, 1u);
                      sub_854930(&v335, 1u);
                      sub_854710(&v335, 2u);
                      v287 = gfldCollision;
                      sub_854710(&v287->m_Items[v68]->matter->poseset->pos, 2u);
                      sub_854930(&v335, 2u);
                      sub_854710(v334, 0);
                      v289 = gfldCollision;
                      sub_854710(&v289->m_Items[v68]->matter->poseset->pos, 0);
                      sub_854930(v334, 0);
                      sub_854710(v334, 1u);
                      v291 = gfldCollision;
                      sub_854710(&v291->m_Items[v68]->matter->poseset->pos, 1u);
                      sub_854930(v334, 1u);
                      sub_854710(v334, 2u);
                      v293 = gfldCollision;
                      sub_854710(&v293->m_Items[v68]->matter->poseset->pos, 2u);
                      sub_854930(v334, 2u);
                      v325 = 0;
                    }
                    fldGb->HitUpdate = 1;
                    v296 = fldGb;
                    sub_854710(&v335, 0);
                    v296->playerNewX = v297;
                    v298 = fldGb;
                    sub_854710(&v335, 1u);
                    v298->playerNewY = v299;
                    v300 = fldGb;
                    sub_854710(&v335, 2u);
                    v300->playerNewZ = v301;
                    v303 = gfldCollision;
                    v303->m_Items[v68]->hitflag = 1;
                    fldHit_LastHitIdx = v68;
                  }
                }
              }
              if (v325)
              {
LABEL_461:
                sub_854710(&v335, 0);
                v307 = gfldCollision;
                sub_854710(&v307->m_Items[v68]->matter->poseset->pos, 0);
                sub_854930(&v335, 0);
                sub_854710(&v335, 1u);
                v309 = gfldCollision;
                sub_854710(&v309->m_Items[v68]->matter->poseset->pos, 1u);
                sub_854930(&v335, 1u);
                sub_854710(&v335, 2u);
                v311 = gfldCollision;
                sub_854710(&v311->m_Items[v68]->matter->poseset->pos, 2u);
                sub_854930(&v335, 2u);
                sub_854710(v334, 0);
                v313 = gfldCollision;
                sub_854710(&v313->m_Items[v68]->matter->poseset->pos, 0);
                sub_854930(v334, 0);
                sub_854710(v334, 1u);
                v315 = gfldCollision;
                sub_854710(&v315->m_Items[v68]->matter->poseset->pos, 1u);
                sub_854930(v334, 1u);
                sub_854710(v334, 2u);
                v317 = gfldCollision;
                sub_854710(&v317->m_Items[v68]->matter->poseset->pos, 2u);
                sub_854930(v334, 2u);
              }
            }
          }
        }
      }
LABEL_93:
      ++v68;
        goto LABEL_94;
    }
    v67 = 0;
  }
  while ((v69 & 1) != 0);
  if (idx == -1)
  {
    fldSkySetTblModosu(5);
  }
  else
  {
    fldSkySetTblUpper(idx, 5);
  }
  sub_854710(&v335, 0);
  sub_854710(v334, 0);
  sub_854930(&v331, 0);
  sub_854710(&v335, 1u);
  sub_854710(v334, 1u);
  sub_854930(&v331, 1u);
  sub_854710(&v335, 2u);
  sub_854710(v334, 2u);
  sub_854930(&v331, 2u);
  v321 = v331;
  v322 = v332;
  *&v343.x = v321;
  *&v343.z = v322;
  MATH_VectorLength(v343);
  sub_854710(&v335, 0);
  sub_854930(&v336, 0);
  sub_854710(&v335, 1u);
  sub_854930(&v336, 1u);
  sub_854710(&v335, 2u);
  sub_854930(&v336, 2u);
  sub_854710(&v335, 0);
  sub_854930(&phys_oldpos, 0);
  sub_854710(&v335, 1u);
  sub_854930(&phys_oldpos, 1u);
  sub_854710(&v335, 2u);
  p_phys_oldpos = &phys_oldpos;
LABEL_491:
  sub_854930(p_phys_oldpos, 2u);
}

// 0x1281840
void fldHitChkUnitDamage(sdfVector4_t phys_pos) {
  s32 fieldID;
  f32 v8;
  s64 v11;
  s64 v12;
  f32 v13;
  f32 v14;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v25;
  _BOOL4 v26;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  s32 v31;
  char v34;
  u64 v35;
  char v36;
  struct collision_s_array *gfldCollision;
  struct collision_s_array *v43;
  struct fldGlobalWork_t_o *fldGb;
  s32 v49;
  s32 areaID;
  struct collision_s_array *v51;
  struct collision_s_array *v55;
  struct collision_s_array *v59;
  struct collision_s_array *v61;
  struct collision_s_array *v63;
  struct collision_s_array *v65;
  struct collision_s_array *v67;
  struct collision_s_array *v69;
  f32 v72;
  f32 v73;
  f32 v74;
  f32 v75;
  struct collision_s_array *v76;
  collision_s_o *v78;
  s64 v79;
  f32 v80;
  f32 v81;
  f32 v82;
  f32 v83;
  f32 v84;
  f32 v85;
  f32 v86;
  f32 v87;
  f32 v88;
  f32 v89;
  f32 v90;
  f32 v92;
  f32 v93;
  struct collision_s_array *v94;
  f32 v96;
  f32 num;
  f32 v99;
  struct collision_s_array *v100;
  struct collision_s_array *v103;
  struct collision_s_array *v106;
  f32 fret;
  u64 v109[2];
  u64 v110[2];
  u64 v111[2];
  s64 v112;
  s64 v113;
  u64 v114[2];
  UnityEngine_Vector4_o v115;
  UnityEngine_Vector4_o v116;
  s64 v117;
  f32 v118;
  s32 v119;
  u32 v120[6];
  UnityEngine_Vector4_o v121;
  UnityEngine_Vector4_o v122;

  v116 = phys_pos;
  *&v115.x = 0;
  *&v115.z = 0;
  v114[0] = 0;
  v114[1] = 0;
  v112 = 0;
  v113 = 0;
  v111[0] = 0;
  v111[1] = 0;
  fret = 0.0;
  v110[0] = 0;
  v110[1] = 0;
  v109[0] = 0;
  v109[1] = 0;
  fldGb->DmgOn = 0;
  sub_854710(&v116, 0);
  sub_854930(&v115, 0);
  sub_854710(&v116, 1u);
  sub_854930(&v115, 1u);
  sub_854710(&v116, 2u);
  sub_854930(&v115, 2u);
  sub_854710(&phys_oldpos, 0);
  sub_854930(v114, 0);
  sub_854710(&phys_oldpos, 1u);
  sub_854930(v114, 1u);
  sub_854710(&phys_oldpos, 2u);
  sub_854930(v114, 2u);
  fieldID = fldGb->fieldID;
  if (fieldID == 1)
  {
    sub_854710(&v115, 1u);
    sub_854930(&v115, 1u);
    v8 = 25.0;
  }
  else
  {
    sub_854710(&v115, 1u);
    sub_854930(&v115, 1u);
    if (fieldID <= 9)
      v8 = 30.0;
    else
      v8 = 45.0;
  }
  sub_854710(&v115, 0);
  sub_854710(v114, 0);
  sub_854930(&v112, 0);
  sub_854710(&v115, 1u);
  sub_854710(v114, 1u);
  sub_854930(&v112, 1u);
  sub_854710(&v115, 2u);
  sub_854710(v114, 2u);
  sub_854930(&v112, 2u);
  v11 = v112;
  v12 = v113;
  *&v121.x = v11;
  *&v121.z = v12;
  if (MATH_VectorLength(v121) < 0.1)
  {
    sub_854710(v114, 0);
    sub_854930(&v116, 0);
    sub_854710(v114, 1u);
    sub_854930(&v116, 1u);
    sub_854710(v114, 2u);
    sub_854930(&v116, 2u);
    return;
  }
  sub_854710(&v115, 0);
  v14 = v13;
  sub_854710(v114, 0);
  v17 = v16;
  sdfFabs(v14 - v17);
  sub_854930(v109, 0);
  sub_854710(&v115, 2u);
  v19 = v18;
  sub_854710(v114, 2u);
  sdfFabs(v19 - v20);
  sub_854930(v109, 2u);
  sub_854710(v109, 0);
  v22 = v21;
  sub_854710(v109, 2u);
  v26 = v22 <= v25;
  x = v116.x;
  y = v116.y;
  z = v116.z;
  w = v116.w;
  v122.x = x;
  v122.y = y;
  v122.z = z;
  v122.w = w;
  v31 = 2 * v26;
  fldHitChkUnitElvOnly(v122);
  v34 = 1;
  do
  {
    v35 = 0;
    v36 = v34;
      goto LABEL_34;
LABEL_32:
LABEL_34:
    while (v35 < gfldCollsionNum)
    {
      if (fldGb->fieldID >= 11)
      {
        v8 = flt_32C3168[gfldCollision->m_Items[v35]->mode2D == 1];
      }
      if ((v36 & 1) != 0)
      {
        v43 = gfldCollision;
        if (v31 == v43->m_Items[v35]->mode2D)
          goto LABEL_31;
      }
      else
      {
        v106 = gfldCollision;
        if (v31 != v106->m_Items[v35]->mode2D)
          goto LABEL_31;
      }
      v49 = fldGb->fieldID;
      areaID = fldGb->areaID;
      v51 = gfldCollision;
      if (!fldGbChkHit(v49, areaID + 1, v51->m_Items[v35]->hojiID))
      {
        sub_854710(&v115, 0);
        sub_854930(v111, 0);
        sub_854710(&v115, 1u);
        sub_854930(v111, 1u);
        sub_854710(&v115, 2u);
        sub_854930(v111, 2u);
        sub_854710(v114, 0);
        sub_854930(v110, 0);
        sub_854710(v114, 1u);
        sub_854930(v110, 1u);
        sub_854710(v114, 2u);
        sub_854930(v110, 2u);
        v55 = gfldCollision;
        if (v55->m_Items[v35]->matter)
        {
          sub_854710(&v115, 0);
          v59 = gfldCollision;
          sub_854710(&v59->m_Items[v35]->matter->poseset->pos, 0);
          sub_854930(&v115, 0);
          sub_854710(&v115, 1u);
          v61 = gfldCollision;
          sub_854710(&v61->m_Items[v35]->matter->poseset->pos, 1u);
          sub_854930(&v115, 1u);
          sub_854710(&v115, 2u);
          v63 = gfldCollision;
          sub_854710(&v63->m_Items[v35]->matter->poseset->pos, 2u);
          sub_854930(&v115, 2u);
          sub_854710(v114, 0);
          v65 = gfldCollision;
          sub_854710(&v65->m_Items[v35]->matter->poseset->pos, 0);
          sub_854930(v114, 0);
          sub_854710(v114, 1u);
          v67 = gfldCollision;
          sub_854710(&v67->m_Items[v35]->matter->poseset->pos, 1u);
          sub_854930(v114, 1u);
          sub_854710(v114, 2u);
          v69 = gfldCollision;
          sub_854710(&v69->m_Items[v35]->matter->poseset->pos, 2u);
          sub_854930(v114, 2u);
        }
        v72 = v115.x;
        v73 = v115.y;
        v75 = v115.z;
        v74 = v115.w;
        v76 = gfldCollision;
        v78 = v76->m_Items[v35];
        v79 = *&v78->normal.x;
        v80 = v78->normal.z;
        *&v78 = v78->normal.w;
        *v120 = v72;
        *&v120[1] = v73;
        *&v120[2] = v75;
        *&v120[3] = v74;
        v117 = v79;
        v118 = v80;
        v119 = v78;
        sub_854710(v120, 0);
        v82 = v81;
        sub_854710(&v117, 0);
        v84 = v83;
        sub_854710(v120, 1u);
        v86 = v85;
        sub_854710(&v117, 1u);
        v88 = v87;
        sub_854710(v120, 2u);
        v90 = v89;
        sub_854710(&v117, 2u);
        v93 = (v82 * v84) + (v86 * v88);
        v94 = gfldCollision;
        v96 = v93 + (v90 * v92);
        num = v94->m_Items[v35]->num;
        v99 = sdfFabs(v96 - num);
        v100 = gfldCollision;
        if (v99 < v8 && (v100->m_Items[v35]->pFace->Attr & 0x4000) != 0)
        {
          v103 = gfldCollision;
          HitPositionInside2(&fret, v103->m_Items[v35]->mode2D, gfldCollision->m_Items[v35]->numedges, v115, v8, gfldCollision->m_Items[v35]);
          if (fret >= 0.0)
          {
            fldGb->DmgOn = 1;
          }
        }
      }
LABEL_31:
      ++v35;
        goto LABEL_32;
    }
    v34 = 0;
  }
  while ((v36 & 1) != 0);
}

// 0x1280f60
void fldHitChkUnitElv(sdfVector4_t phys_pos) {
  fldGlobal_c *v4;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  s64 ElvIdx;
  struct collision_s_array *gfldCollision;
  struct collision_s_array *v15;
  struct collision_s_array *v17;
  struct collision_s_array *v19;
  struct collision_s_array *v21;
  struct collision_s_array *v23;
  struct collision_s_array *v25;
  struct collision_s_array *v27;
  s64 p_elv;
  struct collision_s_array *v30;
  s64 v32;
  struct collision_s_array *v33;
  s64 v35;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  struct collision_s_array *v42;
  struct fldGlobalWork_t_o *v48;
  f32 v49;
  struct fldGlobalWork_t_o *v50;
  f32 v51;
  struct fldGlobalWork_t_o *v52;
  f32 v53;
  u64 v54[2];
  u64 v55[2];
  u64 v56[2];
  UnityEngine_Vector4_o v57;
  UnityEngine_Vector4_o v58;

  v57 = phys_pos;
  v54[0] = 0;
  v54[1] = 0;
  v56[0] = 0;
  v56[1] = 0;
  v55[0] = 0;
  v55[1] = 0;
  sub_854690(v54, 0.0, 0.0, 0.0, 1.0);
  fldGb->HitUpdate = 0;
  if (fldGb->ElvIdx != -1)
  {
    if ((v4->_2.bitflags2 & 2) == 0)
      goto LABEL_14;
    goto LABEL_8;
  }
  x = v57.x;
  y = v57.y;
  z = v57.z;
  w = v57.w;
  v58.x = x;
  v58.y = y;
  v58.z = z;
  v58.w = w;
  fldHitChkUnitElvOnly(v58);
  {
LABEL_8:
  }
LABEL_14:
  ElvIdx = fldGb->ElvIdx;
  if (ElvIdx != -1)
  {
    if (gfldCollision->m_Items[ElvIdx]->matter)
    {
      v15 = gfldCollision;
      sub_854710(&v15->m_Items[ElvIdx]->matter->poseset->pos, 0);
      v17 = gfldCollision;
      sub_854710(&v17->m_Items[ElvIdx]->elv, 0);
      sub_854930(v54, 0);
      v19 = gfldCollision;
      sub_854710(&v19->m_Items[ElvIdx]->matter->poseset->pos, 1u);
      v21 = gfldCollision;
      sub_854710(&v21->m_Items[ElvIdx]->elv, 1u);
      sub_854930(v54, 1u);
      v23 = gfldCollision;
      sub_854710(&v23->m_Items[ElvIdx]->matter->poseset->pos, 2u);
      v25 = gfldCollision;
      sub_854710(&v25->m_Items[ElvIdx]->elv, 2u);
      sub_854930(v54, 2u);
      v27 = gfldCollision;
      p_elv = &v27->m_Items[ElvIdx]->elv;
      sub_854710(&gfldCollision->m_Items[ElvIdx]->matter->poseset->pos, 0);
      sub_854930(p_elv, 0);
      v30 = gfldCollision;
      v32 = &v30->m_Items[ElvIdx]->elv;
      sub_854710(&gfldCollision->m_Items[ElvIdx]->matter->poseset->pos, 1u);
      sub_854930(v32, 1u);
      v33 = gfldCollision;
      v35 = &v33->m_Items[ElvIdx]->elv;
      sub_854710(&gfldCollision->m_Items[ElvIdx]->matter->poseset->pos, 2u);
      sub_854930(v35, 2u);
    }
    fieldID = fldGb->fieldID;
    areaID = fldGb->areaID;
    v42 = gfldCollision;
    if (!fldGbChkHit(fieldID, areaID + 1, v42->m_Items[ElvIdx]->hojiID))
    {
      sub_854710(&v57, 0);
      sub_854930(v56, 0);
      sub_854710(&v57, 1u);
      sub_854930(v56, 1u);
      sub_854710(&v57, 2u);
      sub_854930(v56, 2u);
      sub_854710(&phys_oldpos, 0);
      sub_854930(v55, 0);
      sub_854710(&phys_oldpos, 1u);
      sub_854930(v55, 1u);
      sub_854710(&phys_oldpos, 2u);
      sub_854930(v55, 2u);
      sub_854710(v56, 0);
      sub_854710(v54, 0);
      sub_854930(v56, 0);
      sub_854710(v56, 1u);
      sub_854710(v54, 1u);
      sub_854930(v56, 1u);
      sub_854710(v56, 2u);
      sub_854710(v54, 2u);
      sub_854930(v56, 2u);
      fldGb->HitUpdate = 1;
      v48 = fldGb;
      sub_854710(v56, 0);
      v48->playerNewX = v49;
      v50 = fldGb;
      sub_854710(v56, 1u);
      v50->playerNewY = v51;
      v52 = fldGb;
      sub_854710(v56, 2u);
      v52->playerNewZ = v53;
      sub_854710(v56, 0);
      sub_854930(&v57, 0);
      sub_854710(v56, 1u);
      sub_854930(&v57, 1u);
      sub_854710(v56, 2u);
      sub_854930(&v57, 2u);
      sub_854710(v56, 0);
      sub_854930(&phys_oldpos, 0);
      sub_854710(v56, 1u);
      sub_854930(&phys_oldpos, 1u);
      sub_854710(v56, 2u);
      sub_854930(&phys_oldpos, 2u);
    }
  }
}

// 0x127ff20
void fldHitChkUnitElvOnly(sdfVector4_t phys_pos) {
  s32 fieldID;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  u64 v18;
  struct collision_s_array *gfldCollision;
  struct fldGlobalWork_t_o *fldGb;
  s32 v27;
  s32 areaID;
  struct collision_s_array *v29;
  struct collision_s_array *v32;
  struct fldGlobalWork_t_o *v37;
  s32 v38;
  s32 v39;
  struct collision_s_array *v40;
  struct collision_s_array *v44;
  struct collision_s_array *v48;
  struct collision_s_array *v50;
  struct collision_s_array *v52;
  struct collision_s_array *v54;
  struct collision_s_array *v56;
  struct collision_s_array *v58;
  s32 v60;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  struct collision_s_array *v66;
  collision_s_o *v68;
  s64 v69;
  f32 v70;
  f32 v71;
  f32 v72;
  f32 v73;
  f32 v74;
  f32 v75;
  f32 v76;
  f32 v77;
  f32 v78;
  f32 v79;
  f32 v80;
  f32 v82;
  f32 v83;
  struct collision_s_array *v84;
  f32 v86;
  f32 num;
  struct collision_s_array *v90;
  struct collision_s_array *v93;
  struct collision_s_array *v97;
  s64 p_elv;
  struct collision_s_array *v100;
  s64 v102;
  struct collision_s_array *v103;
  s64 v105;
  struct collision_s_array *v108;
  struct collision_s_array *v110;
  struct collision_s_array *v112;
  struct collision_s_array *v114;
  struct collision_s_array *v116;
  struct collision_s_array *v118;
  f32 fret;
  u64 v121[2];
  u64 v122[2];
  u64 v123[2];
  u64 v124[2];
  UnityEngine_Vector4_o v125;
  UnityEngine_Vector4_o v126;
  s64 v127;
  f32 v128;
  s32 v129;
  u32 v130[6];

  v126 = phys_pos;
  *&v125.x = 0;
  *&v125.z = 0;
  fret = 0.0;
  v124[0] = 0;
  v124[1] = 0;
  v123[0] = 0;
  v123[1] = 0;
  v122[0] = 0;
  v122[1] = 0;
  v121[0] = 0;
  v121[1] = 0;
  sub_854710(&v126, 0);
  sub_854930(&v125, 0);
  sub_854710(&v126, 1u);
  sub_854930(&v125, 1u);
  sub_854710(&v126, 2u);
  sub_854930(&v125, 2u);
  sub_854710(&phys_oldpos, 0);
  sub_854930(v124, 0);
  sub_854710(&phys_oldpos, 1u);
  sub_854930(v124, 1u);
  sub_854710(&phys_oldpos, 2u);
  sub_854930(v124, 2u);
  fieldID = fldGb->fieldID;
  if (fieldID == 1)
  {
    sub_854710(&v125, 1u);
    sub_854930(&v125, 1u);
    v7 = 25.0;
  }
  else
  {
    sub_854710(&v125, 1u);
    sub_854930(&v125, 1u);
    if (fieldID <= 9)
      v7 = 30.0;
    else
      v7 = 45.0;
  }
  sub_854710(&v125, 0);
  v9 = v8;
  sub_854710(v124, 0);
  v12 = v11;
  sdfFabs(v9 - v12);
  sub_854930(v121, 0);
  sub_854710(&v125, 2u);
  v14 = v13;
  sub_854710(v124, 2u);
  sdfFabs(v14 - v15);
  sub_854930(v121, 2u);
  sub_854710(v121, 0);
  sub_854710(v121, 2u);
  v18 = 0;
  {
LABEL_23:
  }
  while (1)
  {
    if (v18 >= gfldCollsionNum)
      break;
    else
    {
      if (v18 >= LODWORD(gfldCollision->max_length))
        goto LABEL_29;
    }
    if ((gfldCollision->m_Items[v18]->pFace->Attr & 0x80) != 0)
    {
      v27 = fldGb->fieldID;
      areaID = fldGb->areaID;
      v29 = gfldCollision;
      if (!fldGbChkHit(v27, areaID + 1, v29->m_Items[v18]->hojiID))
      {
        v32 = gfldCollision;
        if (v32->m_Items[v18]->npcID < 1)
          goto LABEL_55;
        v37 = fldGb;
        v38 = v37->fieldID;
        v39 = v37->areaID;
        v40 = gfldCollision;
        if (!fldGbChkNpc(v38, v39 + 1, v40->m_Items[v18]->npcID))
        {
LABEL_55:
          sub_854710(&v125, 0);
          sub_854930(v123, 0);
          sub_854710(&v125, 1u);
          sub_854930(v123, 1u);
          sub_854710(&v125, 2u);
          sub_854930(v123, 2u);
          sub_854710(v124, 0);
          sub_854930(v122, 0);
          sub_854710(v124, 1u);
          sub_854930(v122, 1u);
          sub_854710(v124, 2u);
          sub_854930(v122, 2u);
          v44 = gfldCollision;
          if (v44->m_Items[v18]->matter)
          {
            sub_854710(&v125, 0);
            v48 = gfldCollision;
            sub_854710(&v48->m_Items[v18]->matter->poseset->pos, 0);
            sub_854930(&v125, 0);
            sub_854710(&v125, 1u);
            v50 = gfldCollision;
            sub_854710(&v50->m_Items[v18]->matter->poseset->pos, 1u);
            sub_854930(&v125, 1u);
            sub_854710(&v125, 2u);
            v52 = gfldCollision;
            sub_854710(&v52->m_Items[v18]->matter->poseset->pos, 2u);
            sub_854930(&v125, 2u);
            sub_854710(v124, 0);
            v54 = gfldCollision;
            sub_854710(&v54->m_Items[v18]->matter->poseset->pos, 0);
            sub_854930(v124, 0);
            sub_854710(v124, 1u);
            v56 = gfldCollision;
            sub_854710(&v56->m_Items[v18]->matter->poseset->pos, 1u);
            sub_854930(v124, 1u);
            sub_854710(v124, 2u);
            v58 = gfldCollision;
            sub_854710(&v58->m_Items[v18]->matter->poseset->pos, 2u);
            sub_854930(v124, 2u);
            v60 = 1;
          }
          else
          {
            v60 = 0;
          }
          x = v125.x;
          y = v125.y;
          z = v125.z;
          w = v125.w;
          v66 = gfldCollision;
          v68 = v66->m_Items[v18];
          v69 = *&v68->normal.x;
          v70 = v68->normal.z;
          *&v68 = v68->normal.w;
          *v130 = x;
          *&v130[1] = y;
          *&v130[2] = z;
          *&v130[3] = w;
          v127 = v69;
          v128 = v70;
          v129 = v68;
          sub_854710(v130, 0);
          v72 = v71;
          sub_854710(&v127, 0);
          v74 = v73;
          sub_854710(v130, 1u);
          v76 = v75;
          sub_854710(&v127, 1u);
          v78 = v77;
          sub_854710(v130, 2u);
          v80 = v79;
          sub_854710(&v127, 2u);
          v83 = (v72 * v74) + (v76 * v78);
          v84 = gfldCollision;
          v86 = v83 + (v80 * v82);
          num = v84->m_Items[v18]->num;
          if (sdfFabs(v86 - num) < v7)
          {
            v90 = gfldCollision;
            HitPositionInside2(&fret, v90->m_Items[v18]->mode2D, gfldCollision->m_Items[v18]->numedges, v125, v7, gfldCollision->m_Items[v18]);
            if (fret >= 0.0)
            {
              v93 = gfldCollision;
              if (v93->m_Items[v18]->matter)
              {
                fldGb->ElvIdx = v18;
                v97 = gfldCollision;
                p_elv = &v97->m_Items[v18]->elv;
                sub_854710(&gfldCollision->m_Items[v18]->matter->poseset->pos, 0);
                sub_854930(p_elv, 0);
                v100 = gfldCollision;
                v102 = &v100->m_Items[v18]->elv;
                sub_854710(&gfldCollision->m_Items[v18]->matter->poseset->pos, 1u);
                sub_854930(v102, 1u);
                v103 = gfldCollision;
                v105 = &v103->m_Items[v18]->elv;
                sub_854710(&gfldCollision->m_Items[v18]->matter->poseset->pos, 2u);
                sub_854930(v105, 2u);
              }
            }
          }
          if (v60)
          {
            sub_854710(&v125, 0);
            v108 = gfldCollision;
            sub_854710(&v108->m_Items[v18]->matter->poseset->pos, 0);
            sub_854930(&v125, 0);
            sub_854710(&v125, 1u);
            v110 = gfldCollision;
            sub_854710(&v110->m_Items[v18]->matter->poseset->pos, 1u);
            sub_854930(&v125, 1u);
            sub_854710(&v125, 2u);
            v112 = gfldCollision;
            sub_854710(&v112->m_Items[v18]->matter->poseset->pos, 2u);
            sub_854930(&v125, 2u);
            sub_854710(v124, 0);
            v114 = gfldCollision;
            sub_854710(&v114->m_Items[v18]->matter->poseset->pos, 0);
            sub_854930(v124, 0);
            sub_854710(v124, 1u);
            v116 = gfldCollision;
            sub_854710(&v116->m_Items[v18]->matter->poseset->pos, 1u);
            sub_854930(v124, 1u);
            sub_854710(v124, 2u);
            v118 = gfldCollision;
            sub_854710(&v118->m_Items[v18]->matter->poseset->pos, 2u);
            sub_854930(v124, 2u);
          }
        }
      }
    }
    ++v18;
      goto LABEL_23;
  }
}

// 0x1285650
void fldHitChkUnitVWM(sdfVector4_t phys_pos) {
  System_Single_array *v2;
  u64 *v3;
  u64 *v5;
  struct fldDebug_t_o *fldDbg;
  s32 HitView;
  s32 ElvIdx;
  struct collision_s_array *gfldCollision;
  struct collision_s_array *v17;
  struct collision_s_array *v19;
  struct collision_s_array *v21;
  struct collision_s_array *v23;
  struct collision_s_array *v25;
  struct collision_s_array *v27;
  s32 fieldID;
  f32 v35;
  s64 v38;
  s64 v39;
  struct UnityEngine_Vector4_o *p_phys_oldpos;
  u64 v42;
  Il2CppClass **v44;
  struct collision_s_array *v46;
  f32 v49;
  f32 v50;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 v55;
  f32 v56;
  f32 v57;
  f32 v58;
  f32 v61;
  _BOOL4 v62;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  s32 v67;
  char v70;
  u64 v71;
  char v72;
  struct collision_s_array *v75;
  struct fldGlobalWork_t_o *fldGb;
  s32 areaID;
  s32 v82;
  struct collision_s_array *v83;
  struct collision_s_array *v86;
  struct fldGlobalWork_t_o *v91;
  s32 v92;
  s32 v93;
  struct collision_s_array *v94;
  struct collision_s_array *v98;
  struct collision_s_array *v102;
  struct collision_s_array *v104;
  struct collision_s_array *v106;
  struct collision_s_array *v108;
  struct collision_s_array *v110;
  struct collision_s_array *v112;
  struct collision_s_array *v114;
  f32 v117;
  f32 v118;
  f32 v119;
  f32 v120;
  struct collision_s_array *v121;
  collision_s_o *v123;
  s64 v124;
  f32 v125;
  f32 v126;
  f32 v127;
  f32 v128;
  f32 v129;
  f32 v130;
  f32 v131;
  f32 v132;
  f32 v133;
  f32 v134;
  f32 v135;
  f32 v137;
  struct collision_s_array *v138;
  f32 v139;
  f32 v141;
  f32 v143;
  struct collision_s_array *v144;
  f32 v145;
  struct collision_s_array *v148;
  struct collision_s_array *v151;
  struct collision_s_array *v154;
  struct collision_s_array *v157;
  struct collision_s_array *v160;
  struct collision_s_array *v163;
  struct collision_s_array *v166;
  struct collision_s_array *v169;
  struct collision_s_array *v172;
  struct collision_s_array *v176;
  struct collision_s_array *v179;
  u8 Myuka;
  u32 v182;
  s32 v183;
  struct collision_s_array *v185;
  struct collision_s_array *v188;
  s32 Basyo;
  struct collision_s_array *v192;
  struct fldGlobalWork_t_o *v197;
  struct collision_s_array *v198;
  struct collision_s_array *v201;
  struct fldGlobalWork_t_o *v206;
  struct collision_s_array *v207;
  struct fldGlobalWork_t_o *v209;
  struct collision_s_array *v211;
  struct collision_s_array *v214;
  s32 Spc1;
  struct collision_s_array *v218;
  struct collision_s_array *v221;
  struct collision_s_array *v224;
  s32 Amap0;
  struct collision_s_array *v227;
  struct collision_s_array *v230;
  s32 Amap1;
  struct fldGlobalWork_t_o *v236;
  struct collision_s_array *v237;
  struct UnityEngine_Vector4_array *point;
  f32 v241;
  struct collision_s_array *v243;
  struct collision_s_array *v247;
  struct collision_s_array *v250;
  struct UnityEngine_Vector4_array *v252;
  f32 v254;
  struct collision_s_array *v256;
  struct UnityEngine_Vector4_array *v258;
  s32 v260;
  struct collision_s_array *v262;
  struct UnityEngine_Vector4_array *v264;
  s32 v266;
  struct collision_s_array *v268;
  struct UnityEngine_Vector4_array *v270;
  f32 v272;
  struct collision_s_array *v274;
  struct UnityEngine_Vector4_array *v276;
  s32 v278;
  struct collision_s_array *v280;
  struct UnityEngine_Vector4_array *v282;
  s32 v284;
  struct collision_s_array *v286;
  struct UnityEngine_Vector4_array *v288;
  f32 v290;
  struct collision_s_array *v292;
  struct UnityEngine_Vector4_array *v294;
  s32 v296;
  struct collision_s_array *v298;
  struct UnityEngine_Vector4_array *v300;
  s32 v302;
  f32 v304;
  f32 v305;
  f32 v307;
  f32 v308;
  struct fldGlobalWork_t_o *v311;
  f32 v312;
  struct fldGlobalWork_t_o *v313;
  f32 v314;
  struct fldGlobalWork_t_o *v315;
  f32 v316;
  struct collision_s_array *v318;
  struct collision_s_array *v323;
  struct collision_s_array *v325;
  struct collision_s_array *v327;
  struct collision_s_array *v329;
  f32 v331;
  struct collision_s_array *v335;
  struct collision_s_array *v337;
  struct collision_s_array *v339;
  s32 v342;
  struct collision_s_array *v344;
  struct collision_s_array *v347;
  struct collision_s_array *v349;
  struct collision_s_array *v351;
  struct collision_s_array *v356;
  struct collision_s_array *v358;
  struct collision_s_array *v360;
  struct collision_s_array *v362;
  struct collision_s_array *v364;
  struct collision_s_array *v366;
  struct fldGlobalWork_t_o *v369;
  f32 v370;
  struct fldGlobalWork_t_o *v371;
  f32 v372;
  struct fldGlobalWork_t_o *v373;
  f32 v374;
  struct collision_s_array *v376;
  struct collision_s_array *v380;
  struct collision_s_array *v382;
  struct collision_s_array *v384;
  struct collision_s_array *v386;
  struct collision_s_array *v388;
  struct collision_s_array *v390;
  s64 v394;
  s64 v395;
  s32 v396;
  u64 *v397;
  u64 *v398;
  System_Single_array *tx;
  s32 idx;
  s32 v401;
  u64 v402[2];
  f32 fret;
  u64 v404[2];
  u64 v405[2];
  u64 v406[2];
  s64 v407;
  s64 v408;
  u64 v409[2];
  u64 v410[2];
  UnityEngine_Vector4_o v411;
  UnityEngine_Vector4_o v412;
  s64 v413;
  f32 v414;
  s32 v415;
  u32 v416[6];
  UnityEngine_Vector4_o v417;
  UnityEngine_Vector4_o v418;
  UnityEngine_Vector4_o v419;

  v412 = phys_pos;
  v402[0] = 0;
  v402[1] = 0;
  *&v411.x = 0;
  *&v411.z = 0;
  v410[0] = 0;
  v410[1] = 0;
  fret = 0.0;
  v409[0] = 0;
  v409[1] = 0;
  v407 = 0;
  v408 = 0;
  v406[0] = 0;
  v406[1] = 0;
  v405[0] = 0;
  v405[1] = 0;
  v404[0] = 0;
  v404[1] = 0;
  sub_854690(v402, 0.0, 0.0, 0.0, 1.0);
  v2 = NewSpecific(f32, 3u);
  v3 = NewSpecific(f32, 3u);
  v5 = NewSpecific(f32, 3u);
  HitView = fldDbg->HitView;
  v397 = v5;
  v398 = v3;
  ooyTestKeisyaHitIdx = -1;
  tx = v2;
  ooyTestYukaHitIdx = -1;
  fldAutoMapNameD(-1);
  fldGb->FootSEUp = 0;
  ElvIdx = fldGb->ElvIdx;
  if (ElvIdx != -1)
  {
    if (gfldCollision->m_Items[ElvIdx]->matter)
    {
      v17 = gfldCollision;
      sub_854710(&v17->m_Items[ElvIdx]->matter->poseset->pos, 0);
      v19 = gfldCollision;
      sub_854710(&v19->m_Items[ElvIdx]->elv, 0);
      sub_854930(v402, 0);
      v21 = gfldCollision;
      sub_854710(&v21->m_Items[ElvIdx]->matter->poseset->pos, 1u);
      v23 = gfldCollision;
      sub_854710(&v23->m_Items[ElvIdx]->elv, 1u);
      sub_854930(v402, 1u);
      v25 = gfldCollision;
      sub_854710(&v25->m_Items[ElvIdx]->matter->poseset->pos, 2u);
      v27 = gfldCollision;
      sub_854710(&v27->m_Items[ElvIdx]->elv, 2u);
      sub_854930(v402, 2u);
    }
    fldGb->ElvIdx = -1;
  }
  if (HitView)
  {
    rsetOtOfs(81);
    rsetTest(1, 5, 128, 1, 0, 0, 1, 2);
    rsetAlpha(0);
  }
  sub_854710(&v412, 0);
  sub_854930(&v411, 0);
  sub_854710(&v412, 1u);
  sub_854930(&v411, 1u);
  sub_854710(&v412, 2u);
  sub_854930(&v411, 2u);
  sub_854710(&phys_oldpos, 0);
  sub_854930(v410, 0);
  sub_854710(&phys_oldpos, 1u);
  sub_854930(v410, 1u);
  sub_854710(&phys_oldpos, 2u);
  sub_854930(v410, 2u);
  sub_854710(&v411, 0);
  sub_854710(v402, 0);
  sub_854930(&v411, 0);
  sub_854710(&v411, 1u);
  sub_854710(v402, 1u);
  sub_854930(&v411, 1u);
  sub_854710(&v411, 2u);
  sub_854710(v402, 2u);
  sub_854930(&v411, 2u);
  fieldID = fldGb->fieldID;
  if (fieldID == 1)
  {
    sub_854710(&v411, 1u);
    sub_854930(&v411, 1u);
    v35 = 25.0;
  }
  else
  {
    sub_854710(&v411, 1u);
    sub_854930(&v411, 1u);
    if (fieldID <= 9)
      v35 = 30.0;
    else
      v35 = 45.0;
  }
  sub_854710(&v411, 0);
  sub_854710(v410, 0);
  sub_854930(&v407, 0);
  sub_854710(&v411, 1u);
  sub_854710(v410, 1u);
  sub_854930(&v407, 1u);
  sub_854710(&v411, 2u);
  sub_854710(v410, 2u);
  sub_854930(&v407, 2u);
  v38 = v407;
  v39 = v408;
  *&v417.x = v38;
  *&v417.z = v39;
  if (MATH_VectorLength(v417) < 0.1)
  {
    sub_854710(v410, 0);
    sub_854930(&v412, 0);
    sub_854710(v410, 1u);
    sub_854930(&v412, 1u);
    sub_854710(v410, 2u);
    p_phys_oldpos = &v412;
    goto LABEL_556;
  }
  v42 = 0;
  {
LABEL_72:
  }
  while (1)
  {
    if (v42 >= gfldCollsionNum)
      break;
    else
    {
      v46 = gfldCollision;
      if (v42 >= LODWORD(v46->max_length))
        goto LABEL_78;
    }
    v44 = &v46->obj.klass + v42++;
    WORD1(v44[4]->_1.generic_class) = 0;
      goto LABEL_72;
  }
  fldGb->WaterIdx = -1;
  fldGb->EncPIDUpper = 0;
  sub_854710(&v411, 0);
  v50 = v49;
  sub_854710(v410, 0);
  v53 = v52;
  sdfFabs(v50 - v53);
  sub_854930(v404, 0);
  sub_854710(&v411, 2u);
  v55 = v54;
  sub_854710(v410, 2u);
  sdfFabs(v55 - v56);
  sub_854930(v404, 2u);
  sub_854710(v404, 0);
  v58 = v57;
  sub_854710(v404, 2u);
  v62 = v58 <= v61;
  x = v412.x;
  y = v412.y;
  z = v412.z;
  w = v412.w;
  v418.x = x;
  v418.y = y;
  v418.z = z;
  v418.w = w;
  v67 = 2 * v62;
  fldHitChkUnitElvOnly(v418);
  v70 = 1;
  v396 = -1;
  idx = -1;
  do
  {
    v71 = 0;
    v72 = v70;
      goto LABEL_96;
LABEL_94:
LABEL_96:
    while (1)
    {
      if (v71 >= gfldCollsionNum)
        break;
      if ((v72 & 1) != 0)
      {
        else
        {
          v75 = gfldCollision;
          if (v71 >= LODWORD(v75->max_length))
            goto LABEL_101;
        }
        if (v67 == v75->m_Items[v71]->mode2D)
          goto LABEL_93;
      }
      else
      {
        else
        {
          v114 = gfldCollision;
          if (v71 >= LODWORD(v114->max_length))
            goto LABEL_152;
        }
        if (v67 != v114->m_Items[v71]->mode2D)
          goto LABEL_93;
      }
      v82 = fldGb->fieldID;
      areaID = fldGb->areaID;
      v83 = gfldCollision;
      if (fldGbChkHit(v82, areaID + 1, v83->m_Items[v71]->hojiID))
        goto LABEL_93;
      v86 = gfldCollision;
      if (v86->m_Items[v71]->npcID >= 1)
      {
        v91 = fldGb;
        v93 = v91->fieldID;
        v92 = v91->areaID;
        v94 = gfldCollision;
        if (fldGbChkNpc(v93, v92 + 1, v94->m_Items[v71]->npcID))
          goto LABEL_93;
      }
      sub_854710(&v411, 0);
      sub_854930(v406, 0);
      sub_854710(&v411, 1u);
      sub_854930(v406, 1u);
      sub_854710(&v411, 2u);
      sub_854930(v406, 2u);
      sub_854710(v410, 0);
      sub_854930(v405, 0);
      sub_854710(v410, 1u);
      sub_854930(v405, 1u);
      sub_854710(v410, 2u);
      sub_854930(v405, 2u);
      v98 = gfldCollision;
      if (v98->m_Items[v71]->matter)
      {
        sub_854710(&v411, 0);
        v102 = gfldCollision;
        sub_854710(&v102->m_Items[v71]->matter->poseset->pos, 0);
        sub_854930(&v411, 0);
        sub_854710(&v411, 1u);
        v104 = gfldCollision;
        sub_854710(&v104->m_Items[v71]->matter->poseset->pos, 1u);
        sub_854930(&v411, 1u);
        sub_854710(&v411, 2u);
        v106 = gfldCollision;
        sub_854710(&v106->m_Items[v71]->matter->poseset->pos, 2u);
        sub_854930(&v411, 2u);
        sub_854710(v410, 0);
        v108 = gfldCollision;
        sub_854710(&v108->m_Items[v71]->matter->poseset->pos, 0);
        sub_854930(v410, 0);
        sub_854710(v410, 1u);
        v110 = gfldCollision;
        sub_854710(&v110->m_Items[v71]->matter->poseset->pos, 1u);
        sub_854930(v410, 1u);
        sub_854710(v410, 2u);
        v112 = gfldCollision;
        sub_854710(&v112->m_Items[v71]->matter->poseset->pos, 2u);
        sub_854930(v410, 2u);
        v401 = 1;
      }
      else
      {
        v401 = 0;
      }
      v117 = v411.x;
      v118 = v411.y;
      v120 = v411.z;
      v119 = v411.w;
      v121 = gfldCollision;
      v123 = v121->m_Items[v71];
      v124 = *&v123->normal.x;
      v125 = v123->normal.z;
      *&v123 = v123->normal.w;
      *v416 = v117;
      *&v416[1] = v118;
      *&v416[2] = v120;
      *&v416[3] = v119;
      v413 = v124;
      v414 = v125;
      v415 = v123;
      sub_854710(v416, 0);
      v127 = v126;
      sub_854710(&v413, 0);
      v129 = v128;
      sub_854710(v416, 1u);
      v131 = v130;
      sub_854710(&v413, 1u);
      v133 = v132;
      sub_854710(v416, 2u);
      v135 = v134;
      sub_854710(&v413, 2u);
      v138 = gfldCollision;
      v139 = ((v127 * v129) + (v131 * v133)) + (v135 * v137);
      v141 = v139 - v138->m_Items[v71]->num;
      v143 = sdfFabs(v141);
      v144 = gfldCollision;
      v145 = v143;
      if ((v144->m_Items[v71]->pFace->Attr & 0x40) != 0)
      {
        if (v143 >= v35)
          goto LABEL_93;
        v176 = gfldCollision;
        HitPositionInside2(&fret, v176->m_Items[v71]->mode2D, gfldCollision->m_Items[v71]->numedges, v411, v35, gfldCollision->m_Items[v71]);
        if (fret < 0.0)
          goto LABEL_93;
        v179 = gfldCollision;
        Myuka = v179->m_Items[v71]->pFace->Myuka;
        v182 = gfldCollision->m_Items[v71]->pFace->Myuka;
        v183 = 10 * (Myuka & 0xF) + (v182 >> 4);
LABEL_263:
        fldAutoMapNameD(v183);
        goto LABEL_93;
      }
      v148 = gfldCollision;
      if ((v148->m_Items[v71]->pFace->Attr & 0x1000) != 0)
      {
        if (v145 >= v35)
          goto LABEL_93;
        v185 = gfldCollision;
        HitPositionInside2(&fret, v185->m_Items[v71]->mode2D, gfldCollision->m_Items[v71]->numedges, v411, v35, gfldCollision->m_Items[v71]);
        if (fret < 0.0)
          goto LABEL_93;
        v188 = gfldCollision;
        Basyo = v188->m_Items[v71]->pFace->Basyo;
        v183 = Basyo;
        goto LABEL_263;
      }
      v151 = gfldCollision;
      if ((v151->m_Items[v71]->pFace->Attr & 0x2000) != 0)
      {
        if (v145 < v35)
        {
          v192 = gfldCollision;
          HitPositionInside2(&fret, v192->m_Items[v71]->mode2D, gfldCollision->m_Items[v71]->numedges, v411, v35, gfldCollision->m_Items[v71]);
          if (fret >= 0.0)
          {
            v197 = fldGb;
            v198 = gfldCollision;
            v197->EncPIDUpper = v198->m_Items[v71]->pFace->EncIdx;
          }
        }
        goto LABEL_93;
      }
      v154 = gfldCollision;
      if ((v154->m_Items[v71]->pFace->Attr & 0x200) != 0)
      {
        if (v145 < v35)
        {
          v201 = gfldCollision;
          HitPositionInside2(&fret, v201->m_Items[v71]->mode2D, gfldCollision->m_Items[v71]->numedges, v411, v35, gfldCollision->m_Items[v71]);
          if (fret >= 0.0)
          {
            v206 = fldGb;
            v207 = gfldCollision;
            v206->FootSEUp = v207->m_Items[v71]->pFace->Se;
            v209 = fldGb;
            if (v209->FootSEUp == 3)
            {
              v209->WaterIdx = v71;
            }
          }
        }
        goto LABEL_93;
      }
      v157 = gfldCollision;
      if ((v157->m_Items[v71]->pFace->Attr & 0x8000) != 0)
      {
        if (v145 < v35)
        {
          v211 = gfldCollision;
          HitPositionInside2(&fret, v211->m_Items[v71]->mode2D, gfldCollision->m_Items[v71]->numedges, v411, v35, gfldCollision->m_Items[v71]);
          if (fret >= 0.0)
          {
            v214 = gfldCollision;
            Spc1 = v214->m_Items[v71]->pFace->Spc1;
            if (Spc1 == 3)
            {
              v236 = fldGb;
              v237 = gfldCollision;
              point = v237->m_Items[v71]->point;
              sub_854710(point->m_Items, 1u);
              v236->WaterY = v241;
            }
            else if (Spc1 == 1)
            {
              v218 = gfldCollision;
              idx = v218->m_Items[v71]->pFace->Spc2;
            }
          }
        }
        goto LABEL_93;
      }
      v160 = gfldCollision;
      if ((v160->m_Items[v71]->pFace->Attr & 0x400) == 0)
      {
        v163 = gfldCollision;
        if ((v163->m_Items[v71]->pFace->Attr & 0x800) != 0)
        {
          if (v145 < v35)
          {
            v221 = gfldCollision;
            HitPositionInside2(&fret, v221->m_Items[v71]->mode2D, gfldCollision->m_Items[v71]->numedges, v411, v35, gfldCollision->m_Items[v71]);
            if (fret >= 0.0)
            {
              v224 = gfldCollision;
              Amap0 = v224->m_Items[v71]->pFace->Amap0;
              fldAutoMapOpenBlock(Amap0);
              v227 = gfldCollision;
              if (v227->m_Items[v71]->pFace->Amap1)
              {
                v230 = gfldCollision;
                Amap1 = v230->m_Items[v71]->pFace->Amap1;
                fldAutoMapNameU(Amap1);
              }
            }
          }
          goto LABEL_93;
        }
        v166 = gfldCollision;
        if ((v166->m_Items[v71]->pFace->Attr & 0x4000) == 0)
        {
          v169 = gfldCollision;
          if ((v169->m_Items[v71]->pFace->Attr & 0x100) != 0)
          {
            if (v145 < v35)
            {
              v243 = gfldCollision;
              HitPositionInside2(&fret, v243->m_Items[v71]->mode2D, gfldCollision->m_Items[v71]->numedges, v411, v35, gfldCollision->m_Items[v71]);
              if (fret >= 0.0)
              {
                ooyTestKeisyaHitIdx = v71;
              }
            }
            goto LABEL_93;
          }
          if (v145 < v35)
          {
            v172 = gfldCollision;
            HitPositionInside2(&fret, v172->m_Items[v71]->mode2D, gfldCollision->m_Items[v71]->numedges, v411, v35, gfldCollision->m_Items[v71]);
            if (fret < 0.0)
            {
              if (v401)
                goto LABEL_526;
              goto LABEL_93;
            }
            {
              if (fldDbg->NoClip)
                goto LABEL_374;
              goto LABEL_378;
            }
            if (!fldDbg->NoClip)
              goto LABEL_378;
LABEL_374:
            if (!DDS3_PADCHECK_PRESS(11))
            {
LABEL_378:
              v247 = gfldCollision;
              if (v247->m_Items[v71]->mode2D == 1)
              {
                v250 = gfldCollision;
                v252 = v250->m_Items[v71]->point;
                sub_854710(v252->m_Items, 0);
                tx->m_Items[0] = v254;
                v256 = gfldCollision;
                v258 = v256->m_Items[v71]->point;
                sub_854710(v258->m_Items, 1u);
                *(v398 + 8) = v260;
                v262 = gfldCollision;
                v264 = v262->m_Items[v71]->point;
                sub_854710(v264->m_Items, 2u);
                *(v397 + 8) = v266;
                v268 = gfldCollision;
                v270 = v268->m_Items[v71]->point;
                sub_854710(&v270->m_Items[1], 0);
                tx->m_Items[1] = v272;
                v274 = gfldCollision;
                v276 = v274->m_Items[v71]->point;
                sub_854710(&v276->m_Items[1], 1u);
                *(v398 + 9) = v278;
                v280 = gfldCollision;
                v282 = v280->m_Items[v71]->point;
                sub_854710(&v282->m_Items[1], 2u);
                *(v397 + 9) = v284;
                v286 = gfldCollision;
                v288 = v286->m_Items[v71]->point;
                sub_854710(&v288->m_Items[2], 0);
                tx->m_Items[2] = v290;
                v292 = gfldCollision;
                v294 = v292->m_Items[v71]->point;
                sub_854710(&v294->m_Items[2], 1u);
                *(v398 + 10) = v296;
                v298 = gfldCollision;
                v300 = v298->m_Items[v71]->point;
                sub_854710(&v300->m_Items[2], 2u);
                *(v397 + 10) = v302;
                sub_854710(&v411, 0);
                v305 = v304;
                sub_854710(&v411, 2u);
                v308 = v307;
                GetT_Y(v305, v308, tx, v398, v397);
                ooyTestYukaHitIdx = v71;
                sub_854930(&v411, 1u);
                fldGb->HitUpdate = 1;
                v311 = fldGb;
                sub_854710(&v411, 0);
                v311->playerNewX = v312;
                v313 = fldGb;
                sub_854710(&v411, 1u);
                v313->playerNewY = v314;
                v315 = fldGb;
                sub_854710(&v411, 2u);
                v315->playerNewZ = v316;
                v318 = gfldCollision;
                v318->m_Items[v71]->hitflag = 1;
                goto LABEL_524;
              }
              sub_854710(&v411, 0);
              v323 = gfldCollision;
              sub_854710(&v323->m_Items[v71]->normal, 0);
              sub_854930(v409, 0);
              sub_854710(&v411, 1u);
              v325 = gfldCollision;
              sub_854710(&v325->m_Items[v71]->normal, 1u);
              sub_854930(v409, 1u);
              sub_854710(&v411, 2u);
              v327 = gfldCollision;
              sub_854710(&v327->m_Items[v71]->normal, 2u);
              sub_854930(v409, 2u);
              v329 = gfldCollision;
              sub_854710(&v329->m_Items[v71]->normal, 1u);
              if (v331 >= -0.75)
              {
                if (v141 >= 0.0)
                {
                  if (v145 > fret)
                    fret = v145;
                  sub_854710(v409, 0);
                  v347 = gfldCollision;
                  sub_854710(&v347->m_Items[v71]->normal, 0);
                  sub_854930(&v411, 0);
                  sub_854710(v409, 1u);
                  v349 = gfldCollision;
                  sub_854710(&v349->m_Items[v71]->normal, 1u);
                  sub_854930(&v411, 1u);
                  sub_854710(v409, 2u);
                  v351 = gfldCollision;
                  sub_854710(&v351->m_Items[v71]->normal, 2u);
                  sub_854930(&v411, 2u);
                  v344 = gfldCollision;
                  if (v71 >= LODWORD(v344->max_length))
                  {
LABEL_497:
                  }
                  goto LABEL_498;
                }
              }
              else
              {
                ooyTestYukaHitIdx = v71;
                if ((v396 & 0x80000000) == 0 && v145 > fret)
                  fret = v145;
                sub_854710(v409, 0);
                v335 = gfldCollision;
                sub_854710(&v335->m_Items[v71]->normal, 0);
                sub_854930(&v411, 0);
                sub_854710(v409, 1u);
                v337 = gfldCollision;
                sub_854710(&v337->m_Items[v71]->normal, 1u);
                sub_854930(&v411, 1u);
                sub_854710(v409, 2u);
                v339 = gfldCollision;
                sub_854710(&v339->m_Items[v71]->normal, 2u);
                sub_854930(&v411, 2u);
                v342 = v396;
                if (fret == v35)
                  v342 = v71;
                v396 = v342;
                v344 = gfldCollision;
                if (v71 >= LODWORD(v344->max_length))
                  goto LABEL_497;
LABEL_498:
                if (v344->m_Items[v71]->matter)
                {
                  sub_854710(&v411, 0);
                  v356 = gfldCollision;
                  sub_854710(&v356->m_Items[v71]->matter->poseset->pos, 0);
                  sub_854930(&v411, 0);
                  sub_854710(&v411, 1u);
                  v358 = gfldCollision;
                  sub_854710(&v358->m_Items[v71]->matter->poseset->pos, 1u);
                  sub_854930(&v411, 1u);
                  sub_854710(&v411, 2u);
                  v360 = gfldCollision;
                  sub_854710(&v360->m_Items[v71]->matter->poseset->pos, 2u);
                  sub_854930(&v411, 2u);
                  sub_854710(v410, 0);
                  v362 = gfldCollision;
                  sub_854710(&v362->m_Items[v71]->matter->poseset->pos, 0);
                  sub_854930(v410, 0);
                  sub_854710(v410, 1u);
                  v364 = gfldCollision;
                  sub_854710(&v364->m_Items[v71]->matter->poseset->pos, 1u);
                  sub_854930(v410, 1u);
                  sub_854710(v410, 2u);
                  v366 = gfldCollision;
                  sub_854710(&v366->m_Items[v71]->matter->poseset->pos, 2u);
                  sub_854930(v410, 2u);
                  v401 = 0;
                }
                fldGb->HitUpdate = 1;
                v369 = fldGb;
                sub_854710(&v411, 0);
                v369->playerNewX = v370;
                v371 = fldGb;
                sub_854710(&v411, 1u);
                v371->playerNewY = v372;
                v373 = fldGb;
                sub_854710(&v411, 2u);
                v373->playerNewZ = v374;
                v376 = gfldCollision;
                v376->m_Items[v71]->hitflag = 1;
LABEL_524:
                fldHit_LastHitIdx = v71;
              }
            }
          }
          if (v401)
          {
LABEL_526:
            sub_854710(&v411, 0);
            v380 = gfldCollision;
            sub_854710(&v380->m_Items[v71]->matter->poseset->pos, 0);
            sub_854930(&v411, 0);
            sub_854710(&v411, 1u);
            v382 = gfldCollision;
            sub_854710(&v382->m_Items[v71]->matter->poseset->pos, 1u);
            sub_854930(&v411, 1u);
            sub_854710(&v411, 2u);
            v384 = gfldCollision;
            sub_854710(&v384->m_Items[v71]->matter->poseset->pos, 2u);
            sub_854930(&v411, 2u);
            sub_854710(v410, 0);
            v386 = gfldCollision;
            sub_854710(&v386->m_Items[v71]->matter->poseset->pos, 0);
            sub_854930(v410, 0);
            sub_854710(v410, 1u);
            v388 = gfldCollision;
            sub_854710(&v388->m_Items[v71]->matter->poseset->pos, 1u);
            sub_854930(v410, 1u);
            sub_854710(v410, 2u);
            v390 = gfldCollision;
            sub_854710(&v390->m_Items[v71]->matter->poseset->pos, 2u);
            sub_854930(v410, 2u);
          }
        }
      }
LABEL_93:
      ++v71;
        goto LABEL_94;
    }
    v70 = 0;
  }
  while ((v72 & 1) != 0);
  if (idx == -1)
  {
    fldSkySetTblModosu(5);
  }
  else
  {
    fldSkySetTblUpper(idx, 5);
  }
  sub_854710(&v411, 0);
  sub_854710(v410, 0);
  sub_854930(&v407, 0);
  sub_854710(&v411, 1u);
  sub_854710(v410, 1u);
  sub_854930(&v407, 1u);
  sub_854710(&v411, 2u);
  sub_854710(v410, 2u);
  sub_854930(&v407, 2u);
  v394 = v407;
  v395 = v408;
  *&v419.x = v394;
  *&v419.z = v395;
  MATH_VectorLength(v419);
  sub_854710(&v411, 0);
  sub_854930(&v412, 0);
  sub_854710(&v411, 1u);
  sub_854930(&v412, 1u);
  sub_854710(&v411, 2u);
  sub_854930(&v412, 2u);
  sub_854710(&v411, 0);
  sub_854930(&phys_oldpos, 0);
  sub_854710(&v411, 1u);
  sub_854930(&phys_oldpos, 1u);
  sub_854710(&v411, 2u);
  p_phys_oldpos = &phys_oldpos;
LABEL_556:
  sub_854930(p_phys_oldpos, 2u);
}

// 0x1289730
void fldHitDesiView(void) {
  ;
}

// 0x127f060
void fldHitFree(void) {
  gfldCollision = 0;
  gProgramHit = 0;
}

// 0x1260be0
dds3Basic_t *fldHitGetMatter(s32 HitResID) {
  s64 v3;
  u64 v5;
  struct collision_s_array *gfldCollision;
  struct collision_s_array *v11;

  v3 = 4;
  v5 = 0;
  {
LABEL_6:
    goto LABEL_8;
  }
  while (1)
  {
LABEL_8:
    if (v5 >= gfldCollsionNum)
      return 0;
    else
    {
      if (v5 >= LODWORD(gfldCollision->max_length))
        goto LABEL_12;
    }
    if (*(*(&gfldCollision->obj.klass + v3) + 100LL) == HitResID)
      break;
    ++v3;
    v5 = v3 - 4;
      goto LABEL_6;
  }
  v11 = gfldCollision;
  return *(*(&v11->obj.klass + v3) + 104LL);
}

// 0x1260d40
void fldHitLinkMatter(s32 HitResID, dds3Basic_t *matter) {
  s64 v5;
  u64 v7;
  struct collision_s_array *gfldCollision;
  struct collision_s_array *v12;

  v5 = 4;
  v7 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    if (v7 >= gfldCollsionNum)
      break;
    else
    {
      if (v7 >= LODWORD(gfldCollision->max_length))
        goto LABEL_12;
    }
    if (*(*(&gfldCollision->obj.klass + v5) + 100LL) == HitResID)
    {
      v12 = gfldCollision;
      *(*(&v12->obj.klass + v5) + 104LL) = matter;
    }
    ++v5;
    v7 = v5 - 4;
      goto LABEL_6;
  }
}

// 0x1289720
void fldHitPlanView(void) {
  ;
}

// 0x1288ed0
void fldHitPlanViewForUnity(s32 disp) {
  UnityEngine_Object_o *v4;
  UnityEngine_Object_o *v8;
  UnityEngine_Object_o *v12;
  UnityEngine_Object_o *v16;
  UnityEngine_Object_o *v20;
  UnityEngine_GameObject_o *v23;
  bool v24;
  UnityEngine_Object_o *v26;
  UnityEngine_Object_o *v30;
  UnityEngine_Object_o *v34;
  UnityEngine_Object_o *v38;
  UnityEngine_Object_o *v42;
  UnityEngine_Object_o *HitPlanObj;
  UnityEngine_Object_o *HitDesiObj;
  UnityEngine_Object_o *HitUnitObj;
  UnityEngine_Object_o *HitVWMObj;
  UnityEngine_Object_o *HitEventObj;

  if (disp != 2)
  {
    if (disp == 1)
    {
      if (op_Inequality(HitPlanObj, 0, 0))
      {
        SetActive(HitPlanObj, 1, 0);
      }
      if (op_Inequality(HitDesiObj, 0, 0))
      {
        SetActive(HitDesiObj, 0, 0);
      }
      if (op_Inequality(HitUnitObj, 0, 0))
      {
        SetActive(HitUnitObj, 1, 0);
      }
      if (op_Inequality(HitVWMObj, 0, 0))
      {
        SetActive(HitVWMObj, 1, 0);
      }
      if (!op_Inequality(HitEventObj, 0, 0))
        goto LABEL_173;
      v23 = HitEventObj;
      v24 = 1;
    }
    else
    {
      if (disp)
        return;
      v4 = HitPlanObj;
      if (op_Inequality(v4, 0, 0))
      {
        SetActive(HitPlanObj, 0, 0);
      }
      v8 = HitDesiObj;
      if (op_Inequality(v8, 0, 0))
      {
        SetActive(HitDesiObj, 0, 0);
      }
      v12 = HitUnitObj;
      if (op_Inequality(v12, 0, 0))
      {
        SetActive(HitUnitObj, 0, 0);
      }
      v16 = HitVWMObj;
      if (op_Inequality(v16, 0, 0))
      {
        SetActive(HitVWMObj, 0, 0);
      }
      v20 = HitEventObj;
      if (!op_Inequality(v20, 0, 0))
        goto LABEL_173;
      v23 = HitEventObj;
      v24 = 0;
    }
    SetActive(v23, v24, 0);
LABEL_173:
    deleteFldMenuSub(6);
    return;
  }
  v26 = HitPlanObj;
  if (op_Inequality(v26, 0, 0))
  {
    SetActive(HitPlanObj, 0, 0);
  }
  v30 = HitDesiObj;
  if (op_Inequality(v30, 0, 0))
  {
    SetActive(HitDesiObj, 1, 0);
  }
  v34 = HitUnitObj;
  if (op_Inequality(v34, 0, 0))
  {
    SetActive(HitUnitObj, 1, 0);
  }
  v38 = HitVWMObj;
  if (op_Inequality(v38, 0, 0))
  {
    SetActive(HitVWMObj, 1, 0);
  }
  v42 = HitEventObj;
  if (op_Inequality(v42, 0, 0))
  {
    SetActive(HitEventObj, 0, 0);
  }
}

// 0x128d530
void fldHitProgramAdd(f32 x, f32 y, f32 z, f32 r, f32 h, s32 npcID) {
  struct fldProgramHit_tag_array *gProgramHit;
  s64 gProgramHitNum;
  struct fldProgramHit_tag_array *v14;
  struct fldProgramHit_tag_array *v16;
  struct fldProgramHit_tag_array *v18;
  struct fldProgramHit_tag_array *v20;
  struct fldProgramHit_tag_array *v22;
  struct fldProgramHit_tag_array *v24;
  struct UnityEngine_Vector4_array *Vertex;
  struct fldProgramHit_tag_array *v28;
  struct UnityEngine_Vector4_array *v30;
  struct fldProgramHit_tag_array *v32;
  struct UnityEngine_Vector4_array *v34;
  struct fldProgramHit_tag_array *v36;
  struct UnityEngine_Vector4_array *v38;
  struct fldProgramHit_tag_array *v40;
  struct UnityEngine_Vector4_array *v42;
  struct fldProgramHit_tag_array *v44;
  struct UnityEngine_Vector4_array *v46;
  struct fldProgramHit_tag_array *v48;
  struct UnityEngine_Vector4_array *v50;
  struct fldProgramHit_tag_array *v52;
  struct UnityEngine_Vector4_array *v54;
  struct fldProgramHit_tag_array *v56;
  struct UnityEngine_Vector4_array *v58;
  struct fldProgramHit_tag_array *v60;
  struct UnityEngine_Vector4_array *v62;
  struct fldProgramHit_tag_array *v64;
  struct UnityEngine_Vector4_array *v66;
  struct fldProgramHit_tag_array *v68;
  struct UnityEngine_Vector4_array *v70;
  struct fldProgramHit_tag_array *v72;
  struct UnityEngine_Vector4_array *v74;
  struct fldProgramHit_tag_array *v76;
  struct UnityEngine_Vector4_array *v78;
  struct fldProgramHit_tag_array *v80;
  struct UnityEngine_Vector4_array *v82;
  struct fldProgramHit_tag_array *v84;
  struct UnityEngine_Vector4_array *v86;
  struct fldProgramHit_tag_array *v88;
  struct UnityEngine_Vector4_array *v90;
  struct fldProgramHit_tag_array *v92;
  struct UnityEngine_Vector4_array *v94;
  struct fldProgramHit_tag_array *v96;
  struct UnityEngine_Vector4_array *v98;
  struct fldProgramHit_tag_array *v100;
  struct UnityEngine_Vector4_array *v102;
  struct fldProgramHit_tag_array *v104;
  struct UnityEngine_Vector4_array *v106;
  struct fldProgramHit_tag_array *v108;
  struct UnityEngine_Vector4_array *v110;
  struct fldProgramHit_tag_array *v112;
  struct UnityEngine_Vector4_array *v114;
  struct fldProgramHit_tag_array *v116;
  struct UnityEngine_Vector4_array *v118;
  struct fldProgramHit_tag_array *v120;
  struct UnityEngine_Vector4_array *v122;
  struct fldProgramHit_tag_array *v124;
  struct UnityEngine_Vector4_array *v126;
  struct fldProgramHit_tag_array *v128;
  struct UnityEngine_Vector4_array *v130;
  struct fldProgramHit_tag_array *v132;
  struct UnityEngine_Vector4_array *v134;
  struct fldProgramHit_tag_array *v136;
  struct UnityEngine_Vector4_array *v138;
  struct fldProgramHit_tag_array *v140;
  struct UnityEngine_Vector4_array *v142;
  struct fldProgramHit_tag_array *v144;
  struct UnityEngine_Vector4_array *v146;
  struct fldProgramHit_tag_array *v148;
  struct UnityEngine_Vector4_array *v150;
  struct fldProgramHit_tag_array *v153;
  struct fldResCollisionPolyFace_t_array *Face;
  struct fldProgramHit_tag_array *v157;
  struct fldResCollisionPolyFace_t_array *v159;
  struct fldProgramHit_tag_array *v161;
  struct fldResCollisionPolyFace_t_array *v163;
  struct fldProgramHit_tag_array *v165;
  struct fldResCollisionPolyFace_t_array *v167;
  struct fldProgramHit_tag_array *v169;
  struct fldResCollisionPolyFace_t_array *v171;
  struct fldProgramHit_tag_array *v173;
  struct fldResCollisionPolyFace_t_array *v175;
  struct fldProgramHit_tag_array *v177;
  struct fldResCollisionPolyFace_t_array *v179;
  struct fldProgramHit_tag_array *v181;
  struct fldResCollisionPolyFace_t_array *v183;
  struct System_UInt32_array *VtxIdx;
  struct fldProgramHit_tag_array *v185;
  struct fldResCollisionPolyFace_t_array *v187;
  struct System_UInt32_array *v189;
  struct fldProgramHit_tag_array *v191;
  struct fldResCollisionPolyFace_t_array *v193;
  struct System_UInt32_array *v195;
  struct fldProgramHit_tag_array *v197;
  struct fldResCollisionPolyFace_t_array *v199;
  struct System_UInt32_array *v201;
  struct fldProgramHit_tag_array *v203;
  struct fldResCollisionPolyFace_t_array *v205;
  struct fldProgramHit_tag_array *v207;
  struct fldResCollisionPolyFace_t_array *v209;
  struct fldProgramHit_tag_array *v211;
  struct fldResCollisionPolyFace_t_array *v213;
  struct fldProgramHit_tag_array *v215;
  struct fldResCollisionPolyFace_t_array *v217;
  struct fldProgramHit_tag_array *v219;
  struct fldResCollisionPolyFace_t_array *v221;
  struct fldProgramHit_tag_array *v223;
  struct fldResCollisionPolyFace_t_array *v225;
  struct fldProgramHit_tag_array *v227;
  struct fldResCollisionPolyFace_t_array *v229;
  struct fldProgramHit_tag_array *v231;
  struct fldResCollisionPolyFace_t_array *v233;
  struct fldProgramHit_tag_array *v235;
  struct fldResCollisionPolyFace_t_array *v237;
  struct fldProgramHit_tag_array *v239;
  struct fldResCollisionPolyFace_t_array *v241;
  struct fldProgramHit_tag_array *v243;
  struct fldResCollisionPolyFace_t_array *v245;
  struct fldProgramHit_tag_array *v247;
  struct fldResCollisionPolyFace_t_array *v249;
  struct System_UInt32_array *v251;
  struct fldProgramHit_tag_array *v253;
  struct fldResCollisionPolyFace_t_array *v255;
  struct System_UInt32_array *v257;
  struct fldProgramHit_tag_array *v259;
  struct fldResCollisionPolyFace_t_array *v261;
  struct System_UInt32_array *v263;
  struct fldProgramHit_tag_array *v265;
  struct fldResCollisionPolyFace_t_array *v267;
  struct System_UInt32_array *v269;
  struct fldProgramHit_tag_array *v271;
  struct fldResCollisionPolyFace_t_array *v273;
  struct fldProgramHit_tag_array *v275;
  struct fldResCollisionPolyFace_t_array *v277;
  struct fldProgramHit_tag_array *v279;
  struct fldResCollisionPolyFace_t_array *v281;
  struct fldProgramHit_tag_array *v283;
  struct fldResCollisionPolyFace_t_array *v285;
  struct fldProgramHit_tag_array *v287;
  struct fldResCollisionPolyFace_t_array *v289;
  struct fldProgramHit_tag_array *v291;
  struct fldResCollisionPolyFace_t_array *v293;
  struct fldProgramHit_tag_array *v295;
  struct fldResCollisionPolyFace_t_array *v297;
  struct fldProgramHit_tag_array *v299;
  struct fldResCollisionPolyFace_t_array *v301;
  struct fldProgramHit_tag_array *v303;
  struct fldResCollisionPolyFace_t_array *v305;
  struct fldProgramHit_tag_array *v307;
  struct fldResCollisionPolyFace_t_array *v309;
  struct fldProgramHit_tag_array *v311;
  struct fldResCollisionPolyFace_t_array *v313;
  struct fldProgramHit_tag_array *v315;
  struct fldResCollisionPolyFace_t_array *v317;
  struct System_UInt32_array *v319;
  struct fldProgramHit_tag_array *v321;
  struct fldResCollisionPolyFace_t_array *v323;
  struct System_UInt32_array *v325;
  struct fldProgramHit_tag_array *v327;
  struct fldResCollisionPolyFace_t_array *v329;
  struct System_UInt32_array *v331;
  struct fldProgramHit_tag_array *v333;
  struct fldResCollisionPolyFace_t_array *v335;
  struct System_UInt32_array *v337;
  struct fldProgramHit_tag_array *v339;
  struct fldResCollisionPolyFace_t_array *v341;
  struct fldProgramHit_tag_array *v343;
  struct fldResCollisionPolyFace_t_array *v345;
  struct fldProgramHit_tag_array *v347;
  struct fldResCollisionPolyFace_t_array *v349;
  struct fldProgramHit_tag_array *v351;
  struct fldResCollisionPolyFace_t_array *v353;
  struct fldProgramHit_tag_array *v355;
  struct fldResCollisionPolyFace_t_array *v357;
  struct fldProgramHit_tag_array *v359;
  struct fldResCollisionPolyFace_t_array *v361;
  struct fldProgramHit_tag_array *v363;
  struct fldResCollisionPolyFace_t_array *v365;
  struct fldProgramHit_tag_array *v367;
  struct fldResCollisionPolyFace_t_array *v369;
  struct fldProgramHit_tag_array *v371;
  struct fldResCollisionPolyFace_t_array *v373;
  struct fldProgramHit_tag_array *v375;
  struct fldResCollisionPolyFace_t_array *v377;
  struct fldProgramHit_tag_array *v379;
  struct fldResCollisionPolyFace_t_array *v381;
  struct fldProgramHit_tag_array *v383;
  struct fldResCollisionPolyFace_t_array *v385;
  struct System_UInt32_array *v387;
  struct fldProgramHit_tag_array *v389;
  struct fldResCollisionPolyFace_t_array *v391;
  struct System_UInt32_array *v393;
  struct fldProgramHit_tag_array *v395;
  struct fldResCollisionPolyFace_t_array *v397;
  struct System_UInt32_array *v399;
  struct fldProgramHit_tag_array *v401;
  struct fldResCollisionPolyFace_t_array *v403;
  struct System_UInt32_array *v405;
  struct fldProgramHit_tag_array *v407;
  struct fldResCollisionPolyFace_t_array *v409;
  struct fldProgramHit_tag_array *v411;
  struct fldResCollisionPolyFace_t_array *v413;
  struct fldProgramHit_tag_array *v415;
  struct fldResCollisionPolyFace_t_array *v417;
  struct fldProgramHit_tag_array *v419;
  struct fldResCollisionPolyFace_t_array *v421;
  struct fldProgramHit_tag_array *v423;
  fldResCollisionPoly_t_o *DataPoly;
  s64 v426;
  s64 v427;
  s32 v428;
  s64 v432;
  s64 v433;
  UnityEngine_Vector4_o v434;

  v432 = 0;
  v433 = 0;
  sub_854690(&v432, 0.0, 0.0, 0.0, 1.0);
  gProgramHit->m_Items[gProgramHitNum]->DataPoly->nVertex = 8;
  v14 = gProgramHit;
  v14->m_Items[gProgramHitNum]->DataPoly->nFace = 4;
  v16 = gProgramHit;
  v16->m_Items[gProgramHitNum]->DataPoly->n3 = 0;
  v18 = gProgramHit;
  v18->m_Items[gProgramHitNum]->DataPoly->pVertex = gProgramHit->m_Items[gProgramHitNum]->Vertex;
  v20 = gProgramHit;
  v20->m_Items[gProgramHitNum]->DataPoly->pFace = gProgramHit->m_Items[gProgramHitNum]->Face;
  v22 = gProgramHit;
  v22->m_Items[gProgramHitNum]->DataPoly->pTome = 0;
  v24 = gProgramHit;
  Vertex = v24->m_Items[gProgramHitNum]->Vertex;
  sub_854930(Vertex->m_Items, 0);
  v28 = gProgramHit;
  v30 = v28->m_Items[gProgramHitNum]->Vertex;
  sub_854930(v30->m_Items, 1u);
  v32 = gProgramHit;
  v34 = v32->m_Items[gProgramHitNum]->Vertex;
  sub_854930(v34->m_Items, 2u);
  v36 = gProgramHit;
  v38 = v36->m_Items[gProgramHitNum]->Vertex;
  sub_854930(v38->m_Items, 3u);
  v40 = gProgramHit;
  v42 = v40->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v42->m_Items[1], 0);
  v44 = gProgramHit;
  v46 = v44->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v46->m_Items[1], 1u);
  v48 = gProgramHit;
  v50 = v48->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v50->m_Items[1], 2u);
  v52 = gProgramHit;
  v54 = v52->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v54->m_Items[1], 3u);
  v56 = gProgramHit;
  v58 = v56->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v58->m_Items[2], 0);
  v60 = gProgramHit;
  v62 = v60->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v62->m_Items[2], 1u);
  v64 = gProgramHit;
  v66 = v64->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v66->m_Items[2], 2u);
  v68 = gProgramHit;
  v70 = v68->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v70->m_Items[2], 3u);
  v72 = gProgramHit;
  v74 = v72->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v74->m_Items[3], 0);
  v76 = gProgramHit;
  v78 = v76->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v78->m_Items[3], 1u);
  v80 = gProgramHit;
  v82 = v80->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v82->m_Items[3], 2u);
  v84 = gProgramHit;
  v86 = v84->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v86->m_Items[3], 3u);
  v88 = gProgramHit;
  v90 = v88->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v90->m_Items[4], 0);
  v92 = gProgramHit;
  v94 = v92->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v94->m_Items[4], 1u);
  v96 = gProgramHit;
  v98 = v96->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v98->m_Items[4], 2u);
  v100 = gProgramHit;
  v102 = v100->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v102->m_Items[4], 3u);
  v104 = gProgramHit;
  v106 = v104->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v106->m_Items[5], 0);
  v108 = gProgramHit;
  v110 = v108->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v110->m_Items[5], 1u);
  v112 = gProgramHit;
  v114 = v112->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v114->m_Items[5], 2u);
  v116 = gProgramHit;
  v118 = v116->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v118->m_Items[5], 3u);
  v120 = gProgramHit;
  v122 = v120->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v122->m_Items[6], 0);
  v124 = gProgramHit;
  v126 = v124->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v126->m_Items[6], 1u);
  v128 = gProgramHit;
  v130 = v128->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v130->m_Items[6], 2u);
  v132 = gProgramHit;
  v134 = v132->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v134->m_Items[6], 3u);
  v136 = gProgramHit;
  v138 = v136->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v138->m_Items[7], 0);
  v140 = gProgramHit;
  v142 = v140->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v142->m_Items[7], 1u);
  v144 = gProgramHit;
  v146 = v144->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v146->m_Items[7], 2u);
  v148 = gProgramHit;
  v150 = v148->m_Items[gProgramHitNum]->Vertex;
  sub_854930(&v150->m_Items[7], 3u);
  v153 = gProgramHit;
  Face = v153->m_Items[gProgramHitNum]->Face;
  Face->m_Items[0]->Attr = 128;
  v157 = gProgramHit;
  v159 = v157->m_Items[gProgramHitNum]->Face;
  v159->m_Items[0]->Myuka = 0;
  v161 = gProgramHit;
  v163 = v161->m_Items[gProgramHitNum]->Face;
  v163->m_Items[0]->Se = 0;
  v165 = gProgramHit;
  v167 = v165->m_Items[gProgramHitNum]->Face;
  v167->m_Items[0]->TomeIdx = 0;
  v169 = gProgramHit;
  v171 = v169->m_Items[gProgramHitNum]->Face;
  v171->m_Items[0]->Basyo = 0;
  v173 = gProgramHit;
  v175 = v173->m_Items[gProgramHitNum]->Face;
  v175->m_Items[0]->Amap0 = 0;
  v177 = gProgramHit;
  v179 = v177->m_Items[gProgramHitNum]->Face;
  v179->m_Items[0]->Amap1 = 0;
  v181 = gProgramHit;
  v183 = v181->m_Items[gProgramHitNum]->Face;
  VtxIdx = v183->m_Items[0]->VtxIdx;
  VtxIdx->m_Items[0] = 0;
  v185 = gProgramHit;
  v187 = v185->m_Items[gProgramHitNum]->Face;
  v189 = v187->m_Items[0]->VtxIdx;
  v189->m_Items[1] = 1;
  v191 = gProgramHit;
  v193 = v191->m_Items[gProgramHitNum]->Face;
  v195 = v193->m_Items[0]->VtxIdx;
  v195->m_Items[2] = 5;
  v197 = gProgramHit;
  v199 = v197->m_Items[gProgramHitNum]->Face;
  v201 = v199->m_Items[0]->VtxIdx;
  v201->m_Items[3] = 4;
  v203 = gProgramHit;
  v205 = v203->m_Items[gProgramHitNum]->Face;
  v205->m_Items[0]->EncType = 0;
  v207 = gProgramHit;
  v209 = v207->m_Items[gProgramHitNum]->Face;
  v209->m_Items[0]->EncIdx = 0;
  v211 = gProgramHit;
  v213 = v211->m_Items[gProgramHitNum]->Face;
  v213->m_Items[0]->Spc1 = 0;
  v215 = gProgramHit;
  v217 = v215->m_Items[gProgramHitNum]->Face;
  v217->m_Items[0]->Spc2 = 0;
  v219 = gProgramHit;
  v221 = v219->m_Items[gProgramHitNum]->Face;
  v221->m_Items[1]->Attr = 128;
  v223 = gProgramHit;
  v225 = v223->m_Items[gProgramHitNum]->Face;
  v225->m_Items[1]->Myuka = 0;
  v227 = gProgramHit;
  v229 = v227->m_Items[gProgramHitNum]->Face;
  v229->m_Items[1]->Se = 0;
  v231 = gProgramHit;
  v233 = v231->m_Items[gProgramHitNum]->Face;
  v233->m_Items[1]->TomeIdx = 0;
  v235 = gProgramHit;
  v237 = v235->m_Items[gProgramHitNum]->Face;
  v237->m_Items[1]->Basyo = 0;
  v239 = gProgramHit;
  v241 = v239->m_Items[gProgramHitNum]->Face;
  v241->m_Items[1]->Amap0 = 0;
  v243 = gProgramHit;
  v245 = v243->m_Items[gProgramHitNum]->Face;
  v245->m_Items[1]->Amap1 = 0;
  v247 = gProgramHit;
  v249 = v247->m_Items[gProgramHitNum]->Face;
  v251 = v249->m_Items[1]->VtxIdx;
  v251->m_Items[0] = 1;
  v253 = gProgramHit;
  v255 = v253->m_Items[gProgramHitNum]->Face;
  v257 = v255->m_Items[1]->VtxIdx;
  v257->m_Items[1] = 3;
  v259 = gProgramHit;
  v261 = v259->m_Items[gProgramHitNum]->Face;
  v263 = v261->m_Items[1]->VtxIdx;
  v263->m_Items[2] = 7;
  v265 = gProgramHit;
  v267 = v265->m_Items[gProgramHitNum]->Face;
  v269 = v267->m_Items[1]->VtxIdx;
  v269->m_Items[3] = 5;
  v271 = gProgramHit;
  v273 = v271->m_Items[gProgramHitNum]->Face;
  v273->m_Items[1]->EncType = 0;
  v275 = gProgramHit;
  v277 = v275->m_Items[gProgramHitNum]->Face;
  v277->m_Items[1]->EncIdx = 0;
  v279 = gProgramHit;
  v281 = v279->m_Items[gProgramHitNum]->Face;
  v281->m_Items[1]->Spc1 = 0;
  v283 = gProgramHit;
  v285 = v283->m_Items[gProgramHitNum]->Face;
  v285->m_Items[1]->Spc2 = 0;
  v287 = gProgramHit;
  v289 = v287->m_Items[gProgramHitNum]->Face;
  v289->m_Items[2]->Attr = 128;
  v291 = gProgramHit;
  v293 = v291->m_Items[gProgramHitNum]->Face;
  v293->m_Items[2]->Myuka = 0;
  v295 = gProgramHit;
  v297 = v295->m_Items[gProgramHitNum]->Face;
  v297->m_Items[2]->Se = 0;
  v299 = gProgramHit;
  v301 = v299->m_Items[gProgramHitNum]->Face;
  v301->m_Items[2]->TomeIdx = 0;
  v303 = gProgramHit;
  v305 = v303->m_Items[gProgramHitNum]->Face;
  v305->m_Items[2]->Basyo = 0;
  v307 = gProgramHit;
  v309 = v307->m_Items[gProgramHitNum]->Face;
  v309->m_Items[2]->Amap0 = 0;
  v311 = gProgramHit;
  v313 = v311->m_Items[gProgramHitNum]->Face;
  v313->m_Items[2]->Amap1 = 0;
  v315 = gProgramHit;
  v317 = v315->m_Items[gProgramHitNum]->Face;
  v319 = v317->m_Items[2]->VtxIdx;
  v319->m_Items[0] = 3;
  v321 = gProgramHit;
  v323 = v321->m_Items[gProgramHitNum]->Face;
  v325 = v323->m_Items[2]->VtxIdx;
  v325->m_Items[1] = 2;
  v327 = gProgramHit;
  v329 = v327->m_Items[gProgramHitNum]->Face;
  v331 = v329->m_Items[2]->VtxIdx;
  v331->m_Items[2] = 6;
  v333 = gProgramHit;
  v335 = v333->m_Items[gProgramHitNum]->Face;
  v337 = v335->m_Items[2]->VtxIdx;
  v337->m_Items[3] = 7;
  v339 = gProgramHit;
  v341 = v339->m_Items[gProgramHitNum]->Face;
  v341->m_Items[2]->EncType = 0;
  v343 = gProgramHit;
  v345 = v343->m_Items[gProgramHitNum]->Face;
  v345->m_Items[2]->EncIdx = 0;
  v347 = gProgramHit;
  v349 = v347->m_Items[gProgramHitNum]->Face;
  v349->m_Items[2]->Spc1 = 0;
  v351 = gProgramHit;
  v353 = v351->m_Items[gProgramHitNum]->Face;
  v353->m_Items[2]->Spc2 = 0;
  v355 = gProgramHit;
  v357 = v355->m_Items[gProgramHitNum]->Face;
  v357->m_Items[3]->Attr = 128;
  v359 = gProgramHit;
  v361 = v359->m_Items[gProgramHitNum]->Face;
  v361->m_Items[3]->Myuka = 0;
  v363 = gProgramHit;
  v365 = v363->m_Items[gProgramHitNum]->Face;
  v365->m_Items[3]->Se = 0;
  v367 = gProgramHit;
  v369 = v367->m_Items[gProgramHitNum]->Face;
  v369->m_Items[3]->TomeIdx = 0;
  v371 = gProgramHit;
  v373 = v371->m_Items[gProgramHitNum]->Face;
  v373->m_Items[3]->Basyo = 0;
  v375 = gProgramHit;
  v377 = v375->m_Items[gProgramHitNum]->Face;
  v377->m_Items[3]->Amap0 = 0;
  v379 = gProgramHit;
  v381 = v379->m_Items[gProgramHitNum]->Face;
  v381->m_Items[3]->Amap1 = 0;
  v383 = gProgramHit;
  v385 = v383->m_Items[gProgramHitNum]->Face;
  v387 = v385->m_Items[3]->VtxIdx;
  v387->m_Items[0] = 2;
  v389 = gProgramHit;
  v391 = v389->m_Items[gProgramHitNum]->Face;
  v393 = v391->m_Items[3]->VtxIdx;
  v393->m_Items[1] = 0;
  v395 = gProgramHit;
  v397 = v395->m_Items[gProgramHitNum]->Face;
  v399 = v397->m_Items[3]->VtxIdx;
  v399->m_Items[2] = 4;
  v401 = gProgramHit;
  v403 = v401->m_Items[gProgramHitNum]->Face;
  v405 = v403->m_Items[3]->VtxIdx;
  v405->m_Items[3] = 6;
  v407 = gProgramHit;
  v409 = v407->m_Items[gProgramHitNum]->Face;
  v409->m_Items[3]->EncType = 0;
  v411 = gProgramHit;
  v413 = v411->m_Items[gProgramHitNum]->Face;
  v413->m_Items[3]->EncIdx = 0;
  v415 = gProgramHit;
  v417 = v415->m_Items[gProgramHitNum]->Face;
  v417->m_Items[3]->Spc1 = 0;
  v419 = gProgramHit;
  v421 = v419->m_Items[gProgramHitNum]->Face;
  v421->m_Items[3]->Spc2 = 0;
  v423 = gProgramHit;
  DataPoly = v423->m_Items[gProgramHitNum]->DataPoly;
  v426 = v432;
  v427 = v433;
  v428 = dds3SerializeID();
  *&v434.x = v426;
  *&v434.z = v427;
  fldAddCollisionPoly(DataPoly, v434, v428, 0, npcID);
  ++gProgramHitNum;
}

// 0x1289740
void fldHitWM_Mask(void) {
  u64 v3;
  struct collision_s_array *gfldCollision;
  struct collision_s_array *v9;
  struct collision_s_array *v11;
  struct collision_s_array *v13;
  struct collision_s_array *v16;
  struct collision_s_array *v19;
  struct collision_s_array *v22;
  struct collision_s_array *v25;
  struct collision_s_array *v27;
  struct UnityEngine_Vector4_array *point;
  f32 v31;
  struct collision_s_array *v32;
  f32 v33;
  struct UnityEngine_Vector4_array *v35;
  f32 v37;
  struct collision_s_array *v38;
  f32 v39;
  struct UnityEngine_Vector4_array *v41;
  f32 v43;
  struct collision_s_array *v44;
  f32 v45;
  struct UnityEngine_Vector4_array *v47;
  f32 v49;
  struct collision_s_array *v50;
  f32 v51;
  struct UnityEngine_Vector4_array *v53;
  f32 v55;
  struct collision_s_array *v56;
  f32 v57;
  struct UnityEngine_Vector4_array *v59;
  f32 v61;
  f32 v62;
  struct collision_s_array *v63;
  f32 v64;
  f32 v65;
  struct UnityEngine_Vector4_array *v67;
  f32 v69;
  f32 v70;
  struct collision_s_array *v71;
  f32 v72;
  f32 v73;
  struct UnityEngine_Vector4_array *v75;
  f32 v77;
  f32 v78;
  struct collision_s_array *v79;
  f32 v80;
  f32 v81;
  struct UnityEngine_Vector4_array *v83;
  f32 v85;
  f32 v86;
  f32 v88;
  f32 v89;
  struct collision_s_array *v90;
  struct UnityEngine_Vector4_array *v92;
  f32 v94;
  struct collision_s_array *v95;
  f32 v96;
  struct UnityEngine_Vector4_array *v98;
  f32 v100;
  struct collision_s_array *v101;
  f32 v102;
  struct UnityEngine_Vector4_array *v104;
  f32 v106;
  struct collision_s_array *v107;
  f32 v108;
  struct UnityEngine_Vector4_array *v110;
  f32 v112;
  struct collision_s_array *v113;
  f32 v114;
  struct UnityEngine_Vector4_array *v116;
  f32 v118;
  struct collision_s_array *v119;
  f32 v120;
  struct UnityEngine_Vector4_array *v122;
  f32 v124;
  struct collision_s_array *v125;
  f32 v126;
  struct UnityEngine_Vector4_array *v128;
  f32 v130;
  struct collision_s_array *v131;
  f32 v132;
  struct UnityEngine_Vector4_array *v134;
  f32 v136;
  struct collision_s_array *v137;
  f32 v138;
  struct UnityEngine_Vector4_array *v140;
  f32 v142;
  f32 v143;
  struct collision_s_array *v144;
  f32 v145;
  f32 v146;
  struct UnityEngine_Vector4_array *v148;
  f32 v150;
  f32 v151;
  struct collision_s_array *v152;
  f32 v153;
  f32 v154;
  struct UnityEngine_Vector4_array *v156;
  f32 v158;
  f32 v159;
  struct collision_s_array *v160;
  f32 v161;
  f32 v162;
  struct UnityEngine_Vector4_array *v164;
  f32 v166;
  f32 v167;
  f32 v169;
  f32 v170;
  f32 v171;
  f32 v172;
  f32 v173;
  f32 v174;
  f32 v175;
  f32 v176;
  f32 v177;
  f32 v178;
  f32 v179;
  f32 v180;
  f32 v181;
  f32 v182;
  f32 v183;
  f32 v184;
  f32 v185;
  f32 v186;
  f32 v187;
  f32 v188;
  f32 v189;
  f32 v190;
  f32 v191;
  f32 v192;
  f32 v193;
  f32 v194;
  f32 v195;
  f32 v196;
  u64 v197[2];

  v197[0] = 0;
  v197[1] = 0;
  rsetOtOfs(47);
  rsetTest(1, 0, 128, 1, 0, 0, 1, 1);
  rsetAlpha(1);
  ooyTestRGBMaskOn();
  aDrawBoxF(0, 0, 512, 224, 128, 0, 0, 16);
  sub_854930(v197, 0);
  sub_854930(v197, 1u);
  sub_854930(v197, 2u);
  sub_854930(v197, 3u);
  v3 = 0;
  {
LABEL_9:
  }
  while (1)
  {
    if (v3 >= gfldCollsionNum)
      break;
    else
    {
      if (v3 >= LODWORD(gfldCollision->max_length))
        goto LABEL_15;
    }
    if (gfldCollision->m_Items[v3]->matter)
    {
      v9 = gfldCollision;
      sub_854710(&v9->m_Items[v3]->matter->poseset->pos, 0);
      sub_854930(v197, 0);
      v11 = gfldCollision;
      sub_854710(&v11->m_Items[v3]->matter->poseset->pos, 1u);
      sub_854930(v197, 1u);
      v13 = gfldCollision;
      sub_854710(&v13->m_Items[v3]->matter->poseset->pos, 2u);
      sub_854930(v197, 2u);
    }
    v16 = gfldCollision;
    if ((v16->m_Items[v3]->pFace->Attr & 0x8000) != 0)
    {
      v19 = gfldCollision;
      if (v19->m_Items[v3]->pFace->Spc1 != 1)
      {
        v22 = gfldCollision;
        if (v22->m_Items[v3]->pFace->Spc1 != 3)
        {
          v25 = gfldCollision;
          if (v25->m_Items[v3]->numedges == 3)
          {
            v27 = gfldCollision;
            point = v27->m_Items[v3]->point;
            sub_854710(point->m_Items, 0);
            v195 = v31;
            sub_854710(v197, 0);
            v32 = gfldCollision;
            v193 = v33;
            v35 = v32->m_Items[v3]->point;
            sub_854710(v35->m_Items, 1u);
            v191 = v37;
            sub_854710(v197, 1u);
            v38 = gfldCollision;
            v189 = v39;
            v41 = v38->m_Items[v3]->point;
            sub_854710(v41->m_Items, 2u);
            v187 = v43;
            sub_854710(v197, 2u);
            v44 = gfldCollision;
            v185 = v45;
            v47 = v44->m_Items[v3]->point;
            sub_854710(&v47->m_Items[1], 0);
            v183 = v49;
            sub_854710(v197, 0);
            v50 = gfldCollision;
            v181 = v51;
            v53 = v50->m_Items[v3]->point;
            sub_854710(&v53->m_Items[1], 1u);
            v179 = v55;
            sub_854710(v197, 1u);
            v56 = gfldCollision;
            v177 = v57;
            v59 = v56->m_Items[v3]->point;
            sub_854710(&v59->m_Items[1], 2u);
            v62 = v61;
            sub_854710(v197, 2u);
            v63 = gfldCollision;
            v65 = v64;
            v67 = v63->m_Items[v3]->point;
            sub_854710(&v67->m_Items[2], 0);
            v70 = v69;
            sub_854710(v197, 0);
            v71 = gfldCollision;
            v73 = v72;
            v75 = v71->m_Items[v3]->point;
            sub_854710(&v75->m_Items[2], 1u);
            v78 = v77;
            sub_854710(v197, 1u);
            v79 = gfldCollision;
            v81 = v80;
            v83 = v79->m_Items[v3]->point;
            sub_854710(&v83->m_Items[2], 2u);
            v86 = v85;
            sub_854710(v197, 2u);
            v89 = v88;
            ooyTestPoly3(v195 + v193, v191 + v189, v187 + v185, v183 + v181, v179 + v177, v62 + v65, v70 + v73, v78 + v81, v86 + v89, 0x80000000, 0x80000000, 0x80000000);
          }
          else
          {
            v90 = gfldCollision;
            v92 = v90->m_Items[v3]->point;
            sub_854710(v92->m_Items, 0);
            v196 = v94;
            sub_854710(v197, 0);
            v95 = gfldCollision;
            v194 = v96;
            v98 = v95->m_Items[v3]->point;
            sub_854710(v98->m_Items, 1u);
            v192 = v100;
            sub_854710(v197, 1u);
            v101 = gfldCollision;
            v190 = v102;
            v104 = v101->m_Items[v3]->point;
            sub_854710(v104->m_Items, 2u);
            v188 = v106;
            sub_854710(v197, 2u);
            v107 = gfldCollision;
            v186 = v108;
            v110 = v107->m_Items[v3]->point;
            sub_854710(&v110->m_Items[1], 0);
            v184 = v112;
            sub_854710(v197, 0);
            v113 = gfldCollision;
            v182 = v114;
            v116 = v113->m_Items[v3]->point;
            sub_854710(&v116->m_Items[1], 1u);
            v180 = v118;
            sub_854710(v197, 1u);
            v119 = gfldCollision;
            v178 = v120;
            v122 = v119->m_Items[v3]->point;
            sub_854710(&v122->m_Items[1], 2u);
            v176 = v124;
            sub_854710(v197, 2u);
            v125 = gfldCollision;
            v175 = v126;
            v128 = v125->m_Items[v3]->point;
            sub_854710(&v128->m_Items[2], 0);
            v174 = v130;
            sub_854710(v197, 0);
            v131 = gfldCollision;
            v173 = v132;
            v134 = v131->m_Items[v3]->point;
            sub_854710(&v134->m_Items[2], 1u);
            v172 = v136;
            sub_854710(v197, 1u);
            v137 = gfldCollision;
            v171 = v138;
            v140 = v137->m_Items[v3]->point;
            sub_854710(&v140->m_Items[2], 2u);
            v143 = v142;
            sub_854710(v197, 2u);
            v144 = gfldCollision;
            v146 = v145;
            v148 = v144->m_Items[v3]->point;
            sub_854710(&v148->m_Items[3], 0);
            v151 = v150;
            sub_854710(v197, 0);
            v152 = gfldCollision;
            v154 = v153;
            v156 = v152->m_Items[v3]->point;
            sub_854710(&v156->m_Items[3], 1u);
            v159 = v158;
            sub_854710(v197, 1u);
            v160 = gfldCollision;
            v162 = v161;
            v164 = v160->m_Items[v3]->point;
            sub_854710(&v164->m_Items[3], 2u);
            v167 = v166;
            sub_854710(v197, 2u);
            v170 = v169;
            ooyTestPoly4(v196 + v194, v192 + v190, v188 + v186, v184 + v182, v180 + v178, v176 + v175, v174 + v173, v172 + v171, v143 + v146, v151 + v154, v159 + v162, v167 + v170, 0x80000000, 0x80000000, 0x80000000, 0x80000000);
          }
        }
      }
    }
    ++v3;
      goto LABEL_9;
  }
  rsetTest(1, 0, 128, 2, 1, 1, 1, 1);
  rsetAlpha(0);
  aDrawBoxFZ(0, 0, 512, 224, -1, 128, 128, 128, 128);
  ooyTestRGBMaskOff();
  rsetTest(1, 5, 128, 1, 0, 0, 1, 2);
  rsetAlpha(0);
}

// 0x1288d50
void fldLineFrameViewForUnity(bool disp) {
  UnityEngine_Object_o *LineFrameObj;
  UnityEngine_Object_o *FildMapObj;
  bool v11;

  if (op_Inequality(LineFrameObj, 0, 0))
  {
    SetActive(LineFrameObj, disp, 0);
  }
  if (op_Inequality(FildMapObj, 0, 0))
  {
    v11 = !disp;
    SetActive(FildMapObj, v11, 0);
  }
}
