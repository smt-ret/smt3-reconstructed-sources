#include "types.h"

typedef struct collision_s collision_s;
typedef struct dds3BasicArrayHandle_t dds3BasicArrayHandle_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct fldProgramHit_tag fldProgramHit_tag;
typedef struct fldResCollisionPoly_t fldResCollisionPoly_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

static s32 fldHit_LastHitIdx;
static fldProgramHit_tag gProgramHit[UNKNOWN_ARRAY_SIZE];
static s32 gProgramHitNum;
static sdfMemHandle_t *gProgramHitMH;
static collision_s gfldCollision[UNKNOWN_ARRAY_SIZE];
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
    sdfSqrt(0);
}

// 0x127f930
s32 HitPositionInside2(f32 *fret, s32 mode2D, s32 numE, sdfVector4_t pos, f32 r, collision_s *collision) {
    return 0;
}

// 0x128a760
f32 HitPositionInside3(s32 mode2D, s32 numE, sdfVector4_t pos, f32 r, collision_s *collision) {
    return 0;
}

// 0x127f0d0
f32 MATH_DotProduct(sdfVector4_t v1, sdfVector4_t v2) {
    return 0;
}

// 0x127f1a0
f32 MATH_VectorLength(sdfVector4_t v) {
    sdfSqrt(0);
    return 0;
}

// 0x1263580
void fldAddCollisionPoly(fldResCollisionPoly_t *pDataPoly, sdfVector4_t pos, s32 resID, s32 hojiID, s32 npcID) {
    fldHitAlloc();
    CalcABCD(0, 0, 0, 0, 0);
    sdfFabs(0);
}

// 0x12794a0
void fldClrCollision(void) {
}

// 0x1288ec0
void fldHitAllView(void) {
  ;
}

// 0x127ecd0
void fldHitAlloc(void) {
  struct collision_s_array *v2;
  u64 v4;
  u32 *gfldCollision;
  u64 *v6;
  struct fldProgramHit_tag_array *v9;
  struct fldProgramHit_tag_array *v11;
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
  while (1)
  {
    v6 = Allocate(collision_s);
    collision_s___ctor(v6);
    *&gfldCollision[2 * v4 + 8] = v6;
    if (v4 == 2047)
      break;
    ++v4;
  }
  v9 = NewSpecific(fldProgramHit_tag, 0x40u);
  v11 = v9;
  gProgramHit = v11;
  v13 = 0;
  while (1)
  {
    v15 = Allocate(fldProgramHit_tag);
    _ctor(v15, 0);
    v17 = 0;
    *&gProgramHit[2 * v13 + 8] = v15;
    {
    }
    while (1)
    {
      v20 = gProgramHit;
      if (v17 >= SLODWORD(v20->m_Items[v13]->Face->max_length))
        break;
      v23 = gProgramHit;
      Face = v23->m_Items[v13]->Face;
      v26 = Allocate(fldResCollisionPolyFace_t);
      fldResCollisionPolyFace_t___ctor(v26);
      v19 = &Face[2 * v17++];
      *(v19 + 4) = v26;
    }
    if (++v13 == 64)
      break;
  }
}

// 0x128ad10
s32 fldHitChkCamera(sdfVector4_t eyepos, sdfVector4_t disppos, sdfVector4_t *hitpos) {
    dds3GetControlScene();
    dds3SceneBasicGetList(0, 0);
    dds3GetBasicArrayCount(0);
    dds3SetFirstBasicArray(0);
    dds3GetBasicArray(0);
    dds3MatterObjectBasicGetAlpMode(0);
    dds3MatterObjectBasicSetAlpMode(0, 0);
    dds3SetNextBasicArray(0);
    dds3FreeBasicArrayHandle(0);
    fldGbChkHit(0, 0, 0);
    sdfFabs(0);
    HitPositionInside3(0, 0, (sdfVector4_t){0}, 0, 0);
    dds3SceneBasicSearchNameAndType(0, 0, 0);
    return 0;
}

// 0x128c2c0
s32 fldHitChkEnemy(sdfVector4_t cpos, sdfVector4_t tpos, sdfVector4_t hitpos) {
    dds3GetControlScene();
    fldGbChkHit(0, 0, 0);
    sdfFabs(0);
    HitPositionInside3(0, 0, (sdfVector4_t){0}, 0, 0);
    return 0;
}

// 0x12825b0
void fldHitChkUnit(sdfVector4_t phys_pos) {
    fldAutoMapNameD(0);
    rsetOtOfs(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    rsetAlpha(0);
    MATH_VectorLength((sdfVector4_t){0});
    sdfFabs(0);
    fldHitChkUnitElvOnly((sdfVector4_t){0});
    fldGbChkHit(0, 0, 0);
    fldGbChkNpc(0, 0, 0);
    HitPositionInside2(0, 0, 0, (sdfVector4_t){0}, 0, 0);
    fldAutoMapOpenBlock(0);
    fldAutoMapNameU(0);
    DDS3_PADCHECK_PRESS(0);
    fldSkySetTblModosu(0);
    fldSkySetTblUpper(0, 0);
}

// 0x1281840
void fldHitChkUnitDamage(sdfVector4_t phys_pos) {
    MATH_VectorLength((sdfVector4_t){0});
    sdfFabs(0);
    fldHitChkUnitElvOnly((sdfVector4_t){0});
    fldGbChkHit(0, 0, 0);
    HitPositionInside2(0, 0, 0, (sdfVector4_t){0}, 0, 0);
}

// 0x1280f60
void fldHitChkUnitElv(sdfVector4_t phys_pos) {
    fldHitChkUnitElvOnly((sdfVector4_t){0});
    fldGbChkHit(0, 0, 0);
}

// 0x127ff20
void fldHitChkUnitElvOnly(sdfVector4_t phys_pos) {
    sdfFabs(0);
    fldGbChkHit(0, 0, 0);
    fldGbChkNpc(0, 0, 0);
    HitPositionInside2(0, 0, 0, (sdfVector4_t){0}, 0, 0);
}

// 0x1285650
void fldHitChkUnitVWM(sdfVector4_t phys_pos) {
    fldAutoMapNameD(0);
    rsetOtOfs(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    rsetAlpha(0);
    MATH_VectorLength((sdfVector4_t){0});
    sdfFabs(0);
    fldHitChkUnitElvOnly((sdfVector4_t){0});
    fldGbChkHit(0, 0, 0);
    fldGbChkNpc(0, 0, 0);
    HitPositionInside2(0, 0, 0, (sdfVector4_t){0}, 0, 0);
    fldAutoMapOpenBlock(0);
    fldAutoMapNameU(0);
    DDS3_PADCHECK_PRESS(0);
    GetT_Y(0, 0, 0, 0, 0);
    fldSkySetTblModosu(0);
    fldSkySetTblUpper(0, 0);
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
    return 0;
}

// 0x1260d40
void fldHitLinkMatter(s32 HitResID, dds3Basic_t *matter) {
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
      v23 = HitEventObj;
      v24 = 0;
    }
    SetActive(v23, v24, 0);
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
    dds3SerializeID();
    fldAddCollisionPoly(0, (sdfVector4_t){0}, 0, 0, 0);
}

// 0x1289740
void fldHitWM_Mask(void) {
    rsetOtOfs(0);
    rsetTest(0, 0, 0, 0, 0, 0, 0, 0);
    rsetAlpha(0);
    ooyTestRGBMaskOn();
    aDrawBoxF(0, 0, 0, 0, 0, 0, 0, 0);
    ooyTestPoly3(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    ooyTestPoly4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    aDrawBoxFZ(0, 0, 0, 0, 0, 0, 0, 0, 0);
    ooyTestRGBMaskOff();
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
