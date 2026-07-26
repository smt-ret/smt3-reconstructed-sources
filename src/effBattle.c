#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3Effect_Filter_t dds3Effect_Filter_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effBTLCutHandle_t effBTLCutHandle_t;
typedef struct effBTLCutHandle_t_CutEndCallbackDelegate effBTLCutHandle_t_CutEndCallbackDelegate;
typedef struct effBTLCutHandle_t_MotionChangeCallbackDelegate effBTLCutHandle_t_MotionChangeCallbackDelegate;
typedef struct effBTL_FieldBaseColorTable_t effBTL_FieldBaseColorTable_t;
typedef struct effBTL_FieldColorTable_t effBTL_FieldColorTable_t;
typedef struct effBTL_SkillData_t effBTL_SkillData_t;
typedef struct effBTL_SkillLight_t effBTL_SkillLight_t;
typedef struct effBTL_SkillModel_t effBTL_SkillModel_t;
typedef struct effBTL_SkillPositionPtr_t effBTL_SkillPositionPtr_t;
typedef struct effBTL_t effBTL_t;
typedef struct effBattle_effBTLSkill_Info_tag effBattle_effBTLSkill_Info_tag;
typedef struct effBattle_effBTL_FieldColor_Filter_tag effBattle_effBTL_FieldColor_Filter_tag;
typedef struct effPartHandle_t effPartHandle_t;
typedef struct fldResourceLight_t fldResourceLight_t;
typedef struct mdlManager_mdlTbMbAbLoadCb_t mdlManager_mdlTbMbAbLoadCb_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

struct effBattle_effBTLSkill_Info_tag {
    nbFormation_t *pInvokeForm;
    nbFormation_t *pTargetForm[32];
    u32 target_number;
    u32 target_bit;
};

struct effBattle_effBTL_FieldColor_Filter_tag {
    dds3Effect_Filter_t *filter;
    u32 abgr_base;
    u32 abgr_target;
    u16 frame;
    u16 frame_max;
};

static u32 effBTLDebug_Field_LightABGR;
static u32 effBTLDebug_Field_LightABGRBas;
static effBattle_effBTLSkill_Info_tag *effBTLSkillInfo;
static u32 effBTLSkillID;
static u32 effBTLSkillState;
static s32 effBTLSkillRun;
static u32 effBTLFieldColorProcess;
static u32 effBTLFieldColorSkillID;
static u32 effBTLFieldColorFilterABGR;
static sdfVector4_t effBTLFieldColorDiffuse;
static sdfVector4_t effBTLFieldColorDirectionBase;
static sdfVector4_t effBTLFieldColorDiffuseBase;
static sdfVector4_t effBTLFieldColorAmbientBase;
static fldResourceLight_t *effBTLFieldColorSceneLight;
static s32 effBTLFieldLightAnimFrameEnd;
static s32 effBTLFieldLightAnimFrame;
static f32 effBTLFieldLightAnimRotate;
static sdfVector4_t effBTLFieldLightAnimAxis;
static s32 effBTLSkyFilterAlphaTarget;
static s32 effBTLSkyFilterAlphaBase;
static u16 effBTLSkyFilterFrame;
static u16 effBTLSkyFilterFrameMax;
static effBattle_effBTL_FieldColor_Filter_tag *effBTLFieldColorFilter;
static effBTL_FieldColorTable_t effBTL_FieldColorTable[UNKNOWN_ARRAY_SIZE];
static effBTL_FieldBaseColorTable_t effBTL_FieldBaseColorTable[UNKNOWN_ARRAY_SIZE];

void Clear(mdlManager_mdlTbMbAbLoadCb_t *this);
s32 GetMID(void);
bool IsModelDante(s32 id);
void Mult(void);
void MultMatrixNoArg(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADMATRIX_B(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SCALEVECTOR_B(f32 v);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
u32 SDF_VU0__dds3ColorFtoI(f32 ratio);
void SetRotateMatrixAxis(f32 aAngle, sdfVector4_t aAxis);
void SobedPbSet(u8 **bytedata, s32 bPos);
void ToMatrix(void);
effPartHandle_t *dds3EffectPartCopy(effPartHandle_t **hEffPartSrc);
effPartHandle_t *dds3EffectPartCreate(u16 type, void *pData);
void dds3EffectPartDelete(effPartHandle_t **hEffPart);
void dds3EffectPartDraw(effPartHandle_t **hEffPart);
void dds3EffectPartSetArea(effPartHandle_t **hEffPart, f32 area);
void dds3EffectPartSetColor(effPartHandle_t **hEffPart, u32 abgr);
void dds3EffectPartSetDirection(effPartHandle_t **hEffPart, sdfMatrix4_t *pMatrix);
void dds3EffectPartSetPosition(effPartHandle_t **hEffPart, sdfVector4_t pPos);
void dds3EffectPartSetRotateMatrix(effPartHandle_t **hEffPart, sdfMatrix4_t *pMatrix);
void dds3EffectPartSetScale(effPartHandle_t **hEffPart, f32 scale);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3LinkSceneLight(dds3Basic_t **basic, u32 frame);
void dds3SetLightObjectResoruce(dds3Basic_t **basic, fldResourceLight_t *resource);
void dds3SetQuake(s32 frame, u32 range);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void dds3UnlinkSceneLight(dds3Basic_t **basic);
void effBTLCutDelete(effBTLCutHandle_t **hBTLCutEffect);
u32 effBTLCutGetAllPartColor(u32 frame, u32 frame_end);
void effBTLCutHandle_t__Clear(effBTLCutHandle_t *this);
void effBTLCutSetCameraState(effBTLCutHandle_t **hBTLCutEffect);
void effBTLFieldColorDraw(void);
void effBTLFieldColorGetBaseColor(void);
void effBTLFieldColorOFF(void);
void effBTLFieldColorON(u32 id);
void effBTLFieldColorRun(void);
void effBTLFieldColorStart(void);
void effBTLFieldFilterRun(void);
void effBTLModelColorSet(effBTL_SkillModel_t **pModel, nbFormation_t **pFormation);
u32 effBTLModelGetID(nbFormation_t **pFormation);
void effBTLModelGetMarkMatrix2(nbFormation_t **pFormation, u32 mark);
void effBTLModelShowInit(void);
void effBTLPartCreate(effBTL_SkillData_t **pSkill, u8 **pData);
void effBTLPartDelete(effBTL_SkillData_t **pSkill);
void effBTLPartGetPositionPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr, sdfVector4_t *pPos);
f32 effBTLPartGetRadiusPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr);
void effBTLPartGetRotateMatrixPtr(effBTL_SkillPositionPtr_t **pPosPtr, sdfMatrix4_t *pMatrix);
f32 effBTLPartGetScalePtr(nbFormation_t **pFormation);
void effBTLPartPtrGetAllModelCenterOffset(void);
void effBTLPartPtrResetAllModelCenterOffset(void);
void effBTLPointLightInit(void);
void effBTLPointLightOFF(void);
void effBTLPointLightON(void);
void effBTLPointLightRun(void);
void effBTLPointLightSet(effBTL_SkillLight_t **pLight, nbFormation_t **pFormation);
bool effBTLSkillCheckRun2(u32 skillid);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
void effBTLSkillInit(void);
void effBTLSkyFilterRun(void);
void effBTLSystemPartHandleCreate(void);
void effBTLSystemPartHandleDelete(void);
void effBTL_SkillData_t__CopyByte(effBTL_SkillData_t *this, u8 **bytedata);
void effBTL_t__Clear(effBTL_t *this);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
s32 fldSkyGetAlpha(void);
void nbCameraSetState(u16 state);
nbMainProcessData_t *nbGetMainProcessData(void);
void nbStageFilterAlp(s32 alp);

// 0x14ba650
void Clear(effBattle_effBTLSkill_Info_tag *this) {
  u64 *v3;
  struct nbFormation_t_array *pTargetForm;
  u64 v5;
  u64 *v6;

  v3 = Allocate(nbFormation_t);
  nbFormation_t___ctor(v3);
  this->pInvokeForm = v3;
  pTargetForm = NewSpecific(nbFormation_t, 0x20u);
  v5 = 0;
  this->pTargetForm = pTargetForm;
  while (1)
  {
    v6 = Allocate(nbFormation_t);
    nbFormation_t___ctor(v6);
    pTargetForm->m_Items[v5] = v6;
    if (v5 == 31)
      break;
    pTargetForm = this->pTargetForm;
    ++v5;
  }
  *&this->target_number = 0;
}

// 0x1814ca0
s32 GetMID(void) {
  nbFormation_t_o *pFormation;

  pFormation = 0;
  pFormation = effBTLSkillGetInvokeFormation(0);
  return effBTLModelGetID(&pFormation);
}

// 0x1811490
void dds3EffectFilter(dds3Effect_Filter_t *pFilter) {
  ;
}

// 0x18114f0
effBTL_t *effBTLCreate(u8 **pData) {
  effBTL_t_o *v3;

  v3 = Allocate(effBTL_t);
  effBTL_t___ctor(v3);
  effBTL_t__Clear(v3);
  effBTL_SkillData_t__CopyByte(v3->Skill, pData);
  effBTLPartCreate(&v3->Skill, pData);
  v3->CutCount = 0;
  v3->hCutListTop = 0;
  Write(StringLiteral_15400, 0);
  return v3;
}

// 0x1812260
effBTLCutHandle_t *effBTLCutCreate(effBTL_t **hBTLEffect, u16 CutNum, nbFormation_t *pFormation, u32 stat) {
    effBTLCutHandle_t__Clear(0);
    dds3EffectPartCopy(0);
    effBTLPartGetScalePtr(0);
    dds3EffectPartSetScale(0, 0);
    return 0;
}

// 0x1811ae0
void effBTLCutDelete(effBTLCutHandle_t **hBTLCutEffect) {
    dds3EffectPartDelete(0);
}

// 0x1812a60
void effBTLCutDraw(effBTLCutHandle_t **hBTLCutEffect) {
    effBTLCutSetCameraState(0);
    effBTLPointLightSet(0, 0);
    effBTLModelColorSet(0, 0);
    dds3SetQuake(0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    Mult();
    ToMatrix();
    SDF_VU0__STOREMATRIX(0);
    effBTLCutGetAllPartColor(0, 0);
    effBTLPartGetPositionPtr(0, 0, 0);
    dds3EffectPartSetPosition(0, (sdfVector4_t){0});
    dds3EffectPartSetRotateMatrix(0, 0);
    effBTLPartGetRotateMatrixPtr(0, 0);
    dds3EffectPartSetDirection(0, 0);
    effBTLPartGetRadiusPtr(0, 0);
    dds3EffectPartSetArea(0, 0);
    dds3EffectPartSetColor(0, 0);
    dds3EffectPartDraw(0);
    effBTLModelGetMarkMatrix2(0, 0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
}

// 0x1812820
u32 effBTLCutGetAllPartColor(u32 frame, u32 frame_end) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__SCALEVECTOR_B(0);
    SDF_VU0__ADDVECTOR();
    SDF_VU0__dds3ColorFtoI(0);
    return 0;
}

// 0x18127b0
u32 effBTLCutGetCutEndFrame(effBTLCutHandle_t **hBTLCutEffect) {
  return (*hBTLCutEffect)->cut_frame;
}

// 0x1812720
u16 effBTLCutGetCutNumber(effBTLCutHandle_t **hBTLCutEffect) {
  return (*hBTLCutEffect)->cut;
}

// 0x18127f0
u32 effBTLCutGetDrawEndFrame(effBTLCutHandle_t **hBTLCutEffect) {
  return (*hBTLCutEffect)->draw_frame;
}

// 0x1812740
nbFormation_t *effBTLCutGetFormation(effBTLCutHandle_t **hBTLCutEffect) {
  return (*hBTLCutEffect)->pFormation;
}

// 0x1812730
u32 effBTLCutGetFrame(effBTLCutHandle_t **hBTLCutEffect) {
  return (*hBTLCutEffect)->frame;
}

// 0x1812770
u32 effBTLCutGetMotionChangeFrame(effBTLCutHandle_t **hBTLCutEffect) {
  return (*hBTLCutEffect)->pSkillCut->model->motion_timing;
}

// 0x1812810
void *effBTLCutGetUserData(effBTLCutHandle_t **hBTLCutEffect) {
  return (*hBTLCutEffect)->pUserData;
}

// 0x1812220
void effBTLCutListRelease(effBTLCutHandle_t **hBTLCutEffect) {
  struct effBTLCutHandle_t_o **p_hCutListTop;
  effBTLCutHandle_t_o *v3;
  bool v4;

  p_hCutListTop = &(*hBTLCutEffect)->hBTLEffect->hCutListTop;
  do
  {
    v3 = *p_hCutListTop;
    if (!*p_hCutListTop)
      break;
    v4 = v3 == *hBTLCutEffect;
    p_hCutListTop = &v3->hCutListNext;
    (*hBTLCutEffect)->hBTLEffect->hCutListTop = v3->hCutListNext;
  }
  while (!v4);
}

// 0x1812940
void effBTLCutSetCameraState(effBTLCutHandle_t **hBTLCutEffect) {
  System_Array_o *v3;
  u64 cut;
  u16 v8;

  v3 = NewSpecific(ushort, 3u);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__A8B20F5DC7F0A207098A6D581E43008451984303);
  else if ((nbGetMainProcessData()->stat & 0x1000) != 0)
  {
    return;
  }
  cut = (*hBTLCutEffect)->cut;
  if (cut <= 2)
  {
    v8 = *(&v3[2].klass + cut);
    nbCameraSetState(v8);
  }
}

// 0x1812760
void effBTLCutSetCutEndCallbackFunc(effBTLCutHandle_t **hBTLCutEffect, effBTLCutHandle_t_CutEndCallbackDelegate *pCallbackFunc) {
  (*hBTLCutEffect)->CutEndCallback = pCallbackFunc;
}

// 0x1812790
void effBTLCutSetCutEndFrame(effBTLCutHandle_t **hBTLCutEffect, u32 frame) {
  (*hBTLCutEffect)->cut_frame = frame;
  if (!(*hBTLCutEffect)->cut)
    (*hBTLCutEffect)->draw_frame = frame;
}

// 0x18127c0
void effBTLCutSetDrawEndFrame(effBTLCutHandle_t **hBTLCutEffect, u32 frame) {
  effBTLCutHandle_t_o *v3;

  v3 = *hBTLCutEffect;
  if ((*hBTLCutEffect)->cut != 1 || v3->draw_frame > frame)
    v3->draw_frame = frame;
}

// 0x1812750
void effBTLCutSetMotionChangeCallbackFunc(effBTLCutHandle_t **hBTLCutEffect, effBTLCutHandle_t_MotionChangeCallbackDelegate *pCallbackFunc) {
  (*hBTLCutEffect)->MotionChangeCallback = pCallbackFunc;
}

// 0x18137f0
void effBTLCutSetScale(effBTLCutHandle_t **hBTLCutEffect, f32 scale) {
  u64 v5;
  s64 v6;
  s64 v7;
  struct effPartHandle_t_array *hPart;

  if (scale != 1.0 && (*hBTLCutEffect)->pSkillCut->parts->number)
  {
    v5 = 0;
    v6 = (*hBTLCutEffect)->pSkillCut->parts->number - 1LL;
    v7 = 32;
    hPart = (*hBTLCutEffect)->hPart;
    while (1)
    {
      dds3EffectPartSetScale((hPart + v7), scale, 0);
      if (v6 == v5)
        break;
      ++v5;
      v7 += 8;
      hPart = (*hBTLCutEffect)->hPart;
      if (v5 >= LODWORD(hPart->max_length))
    }
  }
}

// 0x1812800
void effBTLCutSetUserData(effBTLCutHandle_t **hBTLCutEffect, void *pData) {
  (*hBTLCutEffect)->pUserData = pData;
}

// 0x18114e0
s32 effBTLDebugCheckBEDFileFix(void) {
  return 0;
}

// 0x18114c0
void effBTLDebugCutFrameInit(void) {
  ;
}

// 0x18114d0
void effBTLDebugCutFrameOFF(void) {
  ;
}

// 0x18114b0
void effBTLDebugCutFrameON(void) {
  ;
}

// 0x18114a0
void effBTLDebugCutFrameSet(u8 cutNum, u32 frame) {
  ;
}

// 0x18119d0
void effBTLDelete(effBTL_t **hBTLEffect) {
  effBTL_t_o *v3;
  effBTLCutHandle_t_o *hCutListTop;
  effBTL_SkillData_t_o **p_Skill;
  effBTLCutHandle_t_o *hBTLCutEffect;

  hBTLCutEffect = 0;
  v3 = *hBTLEffect;
  if (*hBTLEffect)
  {
    hCutListTop = v3->hCutListTop;
    hBTLCutEffect = hCutListTop;
    if (hCutListTop)
    {
      do
      {
        while (1)
        {
          hCutListTop = hCutListTop->hCutListNext;
            break;
          effBTLCutDelete(&hBTLCutEffect);
          hBTLCutEffect = hCutListTop;
          if (!hCutListTop)
        }
        effBTLCutDelete(&hBTLCutEffect);
        hBTLCutEffect = hCutListTop;
      }
      while (hCutListTop);
      v3 = *hBTLEffect;
    }
    p_Skill = &v3->Skill;
    effBTLPartDelete(p_Skill);
    Write(StringLiteral_15401, 0);
  }
}

// 0x18167c0
void effBTLFieldColorDraw(void) {
  effBattle_c *v3;

  else if (!effBTLFieldColorProcess)
  {
    return;
  }
  if (HIBYTE(effBTLFieldColorFilter->filter->abgr)
    && (v3->_2.bitflags2 & 2) != 0
  {
  }
}

// 0x1815520
void effBTLFieldColorEnd(void) {
  effBattle_c *v2;
  struct effBattle_StaticFields *static_fields;

  static_fields = v2->static_fields;
  if (static_fields->effBTLFieldColorProcess)
  {
    static_fields->effBTLFieldColorProcess = 4;
  }
}

// 0x1815250
void effBTLFieldColorGetBaseColor(void) {
    nbGetMainProcessData();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
}

// 0x18151e0
void effBTLFieldColorInit(void) {
  effBTLFieldColorProcess = 0;
}

// 0x18142e0
void effBTLFieldColorOFF(void) {
  effBattle_c *v2;
  struct effBattle_StaticFields *static_fields;

  static_fields = v2->static_fields;
  if (static_fields->effBTLFieldColorProcess)
  {
    static_fields->effBTLFieldColorProcess = 4;
  }
}

// 0x1813bf0
void effBTLFieldColorON(u32 id) {
    effBTLFieldColorGetBaseColor();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__MULVECTOR();
    SDF_VU0__STOREVECTOR(0);
    effBTLFieldColorStart();
}

// 0x1815d60
void effBTLFieldColorRun(void) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    nbGetMainProcessData();
    dds3SetLightObjectResoruce(0, 0);
    dds3LinkSceneLight(0, 0);
    fldSkyGetAlpha();
    SetRotateMatrixAxis(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    dds3UnlinkSceneLight(0);
    effBTLSkyFilterRun();
    effBTLFieldFilterRun();
}

// 0x1815410
void effBTLFieldColorStart(void) {
  s32 v3;
  struct effBattle_StaticFields *static_fields;

  {
    else
    {
      static_fields = effBattle->static_fields;
      if (static_fields->effBTLFieldColorProcess)
    }
    if (v3)
    {
      else
      {
        effBTLFieldColorProcess = 1;
      }
    }
    else
    {
      static_fields->effBTLFieldColorProcess = 1;
    }
    return;
  }
  v3 = 0;
  static_fields = effBattle->static_fields;
  if (!static_fields->effBTLFieldColorProcess)
  static_fields->effBTLFieldColorProcess = 2;
}

// 0x1815cd0
void effBTLFieldFilterDraw(void) {
  effBattle_c *v2;

  if (HIBYTE(effBTLFieldColorFilter->filter->abgr)
    && (v2->_2.bitflags2 & 2) != 0
  {
  }
}

// 0x1815b20
void effBTLFieldFilterOFF(u16 frame) {
  if (frame)
  {
    effBTLFieldColorFilter->frame = frame;
    effBTLFieldColorFilter->frame_max = frame;
    effBTLFieldColorFilter->abgr_base = effBTLFieldColorFilter->filter->abgr;
    effBTLFieldColorFilter->abgr_target = 0;
  }
  else
  {
    effBTLFieldColorFilter->frame = 0;
    effBTLFieldColorFilter->filter->abgr = 0;
  }
}

// 0x1815a30
void effBTLFieldFilterON(u32 abgr, u16 frame) {
  if (frame)
  {
    effBTLFieldColorFilter->frame = frame;
    effBTLFieldColorFilter->frame_max = frame;
    effBTLFieldColorFilter->abgr_base = effBTLFieldColorFilter->filter->abgr;
    effBTLFieldColorFilter->abgr_target = abgr;
  }
  else
  {
    effBTLFieldColorFilter->frame = 0;
    effBTLFieldColorFilter->filter->abgr = abgr;
  }
}

// 0x1815c00
void effBTLFieldFilterRun(void) {
  u32 v2;
  struct effBattle_effBTL_FieldColor_Filter_tag_o *effBTLFieldColorFilter;
  u32 frame;
  struct dds3Effect_Filter_t_o *filter;

  frame = effBTLFieldColorFilter->frame;
  if (effBTLFieldColorFilter->frame)
  {
    LOWORD(v2) = effBTLFieldColorFilter->frame_max;
    filter = effBTLFieldColorFilter->filter;
    filter->abgr = effColorBlend(effBTLFieldColorFilter->abgr_target, effBTLFieldColorFilter->abgr_base, frame / v2);
    --effBTLFieldColorFilter->frame;
  }
}

// 0x1815720
void effBTLFieldLightAnimationSet(s32 frame, f32 angle) {
  effBTLFieldLightAnimFrameEnd = frame;
  effBTLFieldLightAnimFrame = 0;
  effBTLFieldLightAnimRotate = angle / frame;
}

// 0x1815680
void effBTLFieldLightAxisSet(sdfVector4_t pAxis) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  UnityEngine_Vector4_o v8;

  w = pAxis.w;
  z = pAxis.z;
  y = pAxis.y;
  x = pAxis.x;
  v8.z = z;
  v8.w = w;
  v8.x = x;
  v8.y = y;
  SDF_VU0__COPYVECTOR(&effBTLFieldLightAnimAxis, v8);
}

// 0x18155b0
void effBTLFieldLightDirectionSet(sdfVector4_t pDir) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x1812140
u32 effBTLGetCutEndFrame(effBTL_t **hBTLEffect, u16 CutNum) {
  _BOOL8 v3;
  struct effBTL_SkillCutTable_t_array *cut;

  v3 = CutNum > 1u;
  cut = (*hBTLEffect)->Skill->cut;
  return cut->m_Items[v3]->frame;
}

// 0x18121a0
u32 effBTLGetDrawEndFrame(effBTL_t **hBTLEffect, u16 CutNum) {
  struct effBTL_SkillCutTable_t_array *cut;
  _BOOL8 v4;
  effBTL_SkillCutTable_t_o *v6;
  u32 *p_frame;

  cut = (*hBTLEffect)->Skill->cut;
  v4 = CutNum > 1u;
  v6 = cut->m_Items[v4];
  if (CutNum == 2)
    p_frame = &v6->frame;
  else
    p_frame = &v6->parts->life;
  return *p_frame;
}

// 0x18120e0
u32 effBTLGetMotionChangeFrame(effBTL_t **hBTLEffect, u16 CutNum) {
  _BOOL8 v3;
  struct effBTL_SkillCutTable_t_array *cut;

  v3 = CutNum > 1u;
  cut = (*hBTLEffect)->Skill->cut;
  return cut->m_Items[v3]->model->motion_timing;
}

// 0x18115e0
void effBTLPartCreate(effBTL_SkillData_t **pSkill, u8 **pData) {
    SobedPbSet(0, 0);
    dds3EffectPartCopy(0);
    dds3EffectPartCreate(0, 0);
}

// 0x1811cd0
void effBTLPartDelete(effBTL_SkillData_t **pSkill) {
    dds3EffectPartDelete(0);
}

// 0x1814a60
s32 effBTLSkillCheckRun(void) {
  return effBTLSkillRun;
}

// 0x1814ad0
bool effBTLSkillCheckRun2(u32 skillid) {
  if (!effBTLSkillRun)
    return 0;
  return effBTLSkillID == skillid;
}

// 0x1814d40
bool effBTLSkillCheckRun3(u32 modelID) {
  effBattle_c *v3;

  else if (!effBTLSkillRun)
  {
    return 0;
  }
  else if (GetMID(v3) == modelID)
  {
    return 1;
  }
  return 0;
}

// 0x1814e60
bool effBTLSkillCheckRunDante(void) {
  u64 v2;
  s32 MID;

  else if (!effBTLSkillRun)
  {
    return 0;
  }
  if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
  MID = GetMID(v2);
  else if (!IsModelDante(MID))
  {
    return 0;
  }
  else if (effBTLSkillCheckRun2(0x107u))
  {
    return 1;
  }
  if (effBTLSkillCheckRun2(0x108u))
    return 1;
  if (effBTLSkillCheckRun2(0x10Bu))
    return 1;
  if (effBTLSkillCheckRun2(0x10Cu))
    return 1;
  return effBTLSkillCheckRun2(0x10Du);
}

// 0x1814190
void effBTLSkillEnd(void) {
  effBTLFieldColorOFF();
  if (effBTLSkillID <= 0x1FF)
  {
    nbCameraSetState(0xAu);
  }
  effBTLPointLightOFF();
  effBTLPartPtrResetAllModelCenterOffset();
  effBTLSkillRun = 0;
  Write(StringLiteral_15408, 0);
}

// 0x1814c30
u32 effBTLSkillGetID(void) {
  return effBTLSkillID;
}

// 0x1814600
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx) {
    nbGetMainProcessData();
    return 0;
}

// 0x1813730
u32 effBTLSkillGetInvokeParty(void) {
  struct nbFormation_t_o *pInvokeForm;

  pInvokeForm = effBTLSkillInfo->pInvokeForm;
  if (!pInvokeForm)
    return 256;
  return pInvokeForm->stat & 0x700;
}

// 0x1815170
u32 effBTLSkillGetState(void) {
  return effBTLSkillState;
}

// 0x18149f0
u32 effBTLSkillGetTargetBit(void) {
  return effBTLSkillInfo->target_bit;
}

// 0x1814750
nbFormation_t *effBTLSkillGetTargetFormation(u32 number) {
    return 0;
}

// 0x1814980
u32 effBTLSkillGetTargetNumber(void) {
  return effBTLSkillInfo->target_number;
}

// 0x1814890
u32 effBTLSkillGetTargetParty(void) {
  struct nbFormation_t_array *pTargetForm;
  struct nbFormation_t_array *v5;

  pTargetForm = effBTLSkillInfo->pTargetForm;
  if (!pTargetForm->m_Items[0])
    return 256;
  v5 = effBTLSkillInfo->pTargetForm;
  return v5->m_Items[0]->stat & 0x700;
}

// 0x1813910
void effBTLSkillInit(void) {
  u64 *v1;

  v1 = Allocate(effBattle_effBTLSkill_Info_tag);
  _ctor(v1, 0);
  effBTLSkillInfo = v1;
  Clear(effBTLSkillInfo, 0);
  effBTLSkillRun = 0;
  effBTLSkillState = 0;
  Write(StringLiteral_15405, 0);
}

// 0x18143c0
void effBTLSkillSetFormationInfo(u32 InvokeID, u32 TargetBit) {
    nbGetMainProcessData();
}

// 0x18150a0
void effBTLSkillSetState(u32 state) {
}

// 0x18139f0
void effBTLSkillStart(u32 id, u32 stat) {
    effBTLFieldColorON(0);
    nbCameraSetState(0);
    effBTLPointLightON();
    effBTLPartPtrGetAllModelCenterOffset();
}

// 0x1815870
void effBTLSkyFilterOFF(u16 frame) {
  s32 Alpha;

  Alpha = fldSkyGetAlpha();
  effBTLSkyFilterAlphaBase = Alpha;
  effBTLSkyFilterAlphaTarget = 128;
  effBTLSkyFilterFrame = frame;
  effBTLSkyFilterFrameMax = frame;
}

// 0x18157b0
void effBTLSkyFilterON(s32 alpha, u16 frame) {
  s32 v6;

  v6 = fldSkyGetAlpha();
  effBTLSkyFilterAlphaBase = v6;
  effBTLSkyFilterAlphaTarget = alpha;
  effBTLSkyFilterFrame = frame;
  effBTLSkyFilterFrameMax = frame;
}

// 0x1815930
void effBTLSkyFilterRun(void) {
  u32 v2;
  effBattle_c *v3;
  struct effBattle_StaticFields *static_fields;
  u32 effBTLSkyFilterFrame;
  s32 effBTLSkyFilterAlphaTarget;
  s32 effBTLSkyFilterAlphaBase;
  f32 v8;

  static_fields = v3->static_fields;
  effBTLSkyFilterFrame = static_fields->effBTLSkyFilterFrame;
  if (static_fields->effBTLSkyFilterFrame)
  {
    LOWORD(v2) = static_fields->effBTLSkyFilterFrameMax;
    effBTLSkyFilterAlphaTarget = static_fields->effBTLSkyFilterAlphaTarget;
    effBTLSkyFilterAlphaBase = static_fields->effBTLSkyFilterAlphaBase;
    v8 = effBTLSkyFilterFrame / v2;
    nbStageFilterAlp(
      effBTLSkyFilterAlphaTarget + (v8 * (effBTLSkyFilterAlphaBase - effBTLSkyFilterAlphaTarget)),
      0);
    --effBTLSkyFilterFrame;
  }
}

// 0x1816990
void *nbEffectDraw(dds3ProcessID_t *id) {
  effBTLFieldColorDraw();
  return 0;
}

// 0x18168d0
void *nbEffectProcess(dds3ProcessID_t *id) {
  if (setenv)
  {
    effBTLFieldColorRun();
    effBTLPointLightRun();
  }
  return 0;
}

// 0x1816a00
void *nbEffectShutdown(dds3ProcessID_t *id) {
  effBTLSystemPartHandleDelete();
  nbGetMainProcessData()->EffectProcessID = 0;
  return 0;
}

// 0x1816aa0
void nbInitEffectProcess(nbMainProcessData_t **data) {
  u64 *v3;
  u64 *v7;
  u64 *v8;
  u64 *v10;
  dds3ProcessID_t_o *started;
  dds3ProcessID_t_o *target;

  target = 0;
  started = 0;
  v3 = Allocate(fldResourceLight_t);
  fldResourceLight_t___ctor(v3);
  effBTLFieldColorSceneLight = v3;
  setenv = 0;
  v7 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v7,
    0,
    Method_effBattle_nbEffectProcess__);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_effBattle_nbEffectShutdown__);
  target = dds3StartProcess(StringLiteral_15414, 0x3F9u, 2, 1, v7, 0, v8, 0, 0, 0);
  dds3LinkProcess(&(*data)->MainProcessID, &target, 0);
  (*data)->EffectProcessID = target;
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_effBattle_nbEffectDraw__);
  started = dds3StartProcess(StringLiteral_15415, 0x2B0Eu, 1, 1, v10, 0, 0, 0, 0, 0);
  dds3LinkProcess(&target, &started);
  effBTLSkillInit();
  effBTLFieldColorProcess = 0;
  effBTLPointLightInit();
  effBTLModelShowInit();
  effBTLSystemPartHandleCreate();
}
