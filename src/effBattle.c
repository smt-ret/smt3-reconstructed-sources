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
static effBTL_FieldColorTable_t *effBTL_FieldColorTable;
static effBTL_FieldBaseColorTable_t *effBTL_FieldBaseColorTable;

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
  Write("effBTL:handle create\n", 0);
  return v3;
}

// 0x1812260
effBTLCutHandle_t *effBTLCutCreate(effBTL_t **hBTLEffect, u16 CutNum, nbFormation_t *pFormation, u32 stat) {
  effBTLCutHandle_t_o *v9;
  struct effBTL_SkillCutTable_t_array *cut;
  _BOOL8 v12;
  effBTL_SkillCutTable_t_o *v14;
  u32 *p_frame;
  u32 v16;
  struct effBTL_SkillParts_t_o *parts;
  u64 number;
  bool v19;
  s64 v20;
  struct effPartHandle_t_array *hPart;
  u64 v24;
  struct effBTL_SkillPartsList_t_array *list;
  s64 v28;
  u32 *v29;
  effPartHandle_t_o *v30;
  s64 *v31;
  s64 v32;
  s64 typeHierarchyDepth;
  char *v34;
  s64 *v35;
  f32 ScalePtr;
  u32 *v39;
  u64 v41;
  u64 *v42;
  struct effBTL_t_o *v43;
  Il2CppObject *v44;
  u64 *v46;
  u16 v48;
  effPartHandle_t_o *hEffPartSrc;
  effPartHandle_t_o *v50[3];
  effPartHandle_t_o *hEffPart;

  hEffPart = 0;
  hEffPartSrc = 0;
  v9 = Allocate(effBTLCutHandle_t);
  effBTLCutHandle_t___ctor(v9);
  effBTLCutHandle_t__Clear(v9);
  v9->hBTLEffect = *hBTLEffect;
  v9->hCutListNext = (*hBTLEffect)->hCutListTop;
  (*hBTLEffect)->hCutListTop = v9;
  v9->cut = CutNum;
  cut = (*hBTLEffect)->Skill->cut;
  v12 = CutNum > 1u;
  v14 = cut->m_Items[v12];
  v9->pSkillCut = v14;
  p_frame = &v14->frame;
  v9->cut_frame = v14->frame;
  if (CutNum != 2)
    p_frame = &v14->parts->life;
  v16 = *p_frame;
  v9->pFormation = pFormation;
  v9->draw_frame = v16;
  v9->stat = stat;
  parts = v14->parts;
  number = parts->number;
  if (parts->number)
  {
    v19 = pFormation == 0 || parts->scaling == 0;
    v20 = 4;
    do
    {
      hPart = v9->hPart;
      v24 = v20 - 4;
      hEffPart = *(&hPart->obj.klass + v20);
      list = v9->pSkillCut->parts->list;
      v28 = *(&list->obj.klass + v20);
      if (*(v28 + 16) == -2)
      {
        hEffPart = 0;
        v29 = v9->hPart;
        v30 = 0;
        if (v24 >= v29[6])
          goto LABEL_40;
      }
      else
      {
        v31 = *(v28 + 24);
        if (v31)
        {
          v32 = *v31;
          if (*(*v31 + 288) < typeHierarchyDepth
            || *(*(v32 + 200) + 8 * typeHierarchyDepth - 8) != effPartHandle_t)
          {
            sub_8FC2C0(*(v32 + 64), effPartHandle_t, v50);
            if ((v50[0] & 1) != 0)
              v34 = v50[2];
            else
              v34 = v50 + 1;
            v35 = sub_8C4940(v34);
          }
        }
        hEffPartSrc = *(v28 + 24);
        v30 = dds3EffectPartCopy(&hEffPartSrc, 0, 0);
        hEffPart = v30;
        if (!v19 && (*(*(v28 + 40) + 16LL) | 4) == 4)
        {
          ScalePtr = effBTLPartGetScalePtr(&v9->pFormation);
          dds3EffectPartSetScale(&hEffPart, ScalePtr);
          v30 = hEffPart;
        }
        v29 = v9->hPart;
        if (v24 >= v29[6])
        {
LABEL_40:
        }
      }
      *&v29[2 * v20] = v30;
      v39 = v9->pSkillCut->parts->list;
      v41 = v20 - 3;
      *&v39[2 * v20++] = v28;
    }
    while (v41 < number);
    CutNum = v9->cut;
  }
  v9->frame = 0;
  v48 = CutNum;
  v42 = sub_8D3950(ushort, &v48);
  v43 = v9->hBTLEffect;
  LODWORD(v50[0]) = v43->CutCount;
  v44 = v42;
  v46 = sub_8D3950(uint, v50);
  Write_2930912("effBTL:cut {0:D} handle create(%p)[{2:D}]\n", v44, v43, v46, 0);
  ++v9->hBTLEffect->CutCount;
  return v9;
}

// 0x1811ae0
void effBTLCutDelete(effBTLCutHandle_t **hBTLCutEffect) {
  effBTLCutHandle_t_o *v3;
  s64 i;
  struct effPartHandle_t_array *hPart;
  struct effPartHandle_t_array *v7;
  struct effBTLCutHandle_t_o **p_hCutListTop;
  effBTLCutHandle_t_o *v10;
  bool v11;
  u64 *v12;
  struct effBTL_t_o *hBTLEffect;
  Il2CppObject *v14;
  u64 *v16;
  u32 CutCount;
  u16 cut;
  effPartHandle_t_o *hEffPart;

  hEffPart = 0;
  v3 = *hBTLCutEffect;
  if (*hBTLCutEffect)
  {
    for (i = 4; ; ++i)
    {
      hPart = v3->hPart;
      hEffPart = *(&hPart->obj.klass + i);
      if (hEffPart)
      {
        dds3EffectPartDelete(&hEffPart);
      }
      v7 = (*hBTLCutEffect)->hPart;
      *(&v7->obj.klass + i) = 0;
      if (i == 63)
        break;
      v3 = *hBTLCutEffect;
    }
    p_hCutListTop = &(*hBTLCutEffect)->hBTLEffect->hCutListTop;
    do
    {
      v10 = *p_hCutListTop;
      if (!*p_hCutListTop)
        break;
      v11 = v10 == *hBTLCutEffect;
      p_hCutListTop = &v10->hCutListNext;
      (*hBTLCutEffect)->hBTLEffect->hCutListTop = v10->hCutListNext;
    }
    while (!v11);
    --(*hBTLCutEffect)->hBTLEffect->CutCount;
    cut = (*hBTLCutEffect)->cut;
    v12 = sub_8D3950(ushort, &cut);
    hBTLEffect = (*hBTLCutEffect)->hBTLEffect;
    CutCount = hBTLEffect->CutCount;
    v14 = v12;
    v16 = sub_8D3950(uint, &CutCount);
    Write_2930912("effBTL:cut {0:D} handle delete(%p)[{2:D}]\n", v14, hBTLEffect, v16, 0);
  }
}

// 0x1812a60
void effBTLCutDraw(effBTLCutHandle_t **hBTLCutEffect) {
  f32 m10;
  f32 m00;
  f32 m30;
  f32 m20;
  u32 frame;
  struct effBTL_SkillCutTable_t_o *pSkillCut;
  u16 *shake;
  u32 v12;
  u64 *v14;
  s32 life;
  u32 v17;
  struct nbFormation_t_o *pInvokeForm;
  u32 draw_frame;
  u32 AllPartColor;
  struct effBTL_SkillParts_t_o *parts;
  u32 stat;
  u64 v28;
  u64 v29;
  s64 v30;
  struct effBTL_SkillPartsList_t_array *list;
  effBTL_SkillPartsList_t_o *v34;
  s32 reverberations;
  _BOOL4 v36;
  struct effPartHandle_t_array *hPart;
  struct effBTL_SkillPositionPtr_t_o **p_pos_ptr;
  struct effPartHandle_t_array *v41;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  struct effPartHandle_t_array *v48;
  UnityEngine_Matrix4x4_o *v50;
  u32 *v51;
  u32 height;
  struct effPartHandle_t_array *v59;
  f32 RadiusPtr;
  struct effPartHandle_t_array *v62;
  struct effPartHandle_t_array *v64;
  struct effPartHandle_t_array *v66;
  effBTLCutHandle_t_MotionChangeCallbackDelegate_o *MotionChangeCallback;
  effBTLCutHandle_t_o *v70;
  effBTLCutHandle_t_CutEndCallbackDelegate_o *CutEndCallback;
  u32 abgr;
  UnityEngine_Matrix4x4_o v73;
  UnityEngine_Matrix4x4_o v74;
  UnityEngine_Matrix4x4_o v75;
  UnityEngine_Matrix4x4_o v76;
  UnityEngine_Matrix4x4_o v77;
  UnityEngine_Matrix4x4_o v78;
  UnityEngine_Matrix4x4_o v79;
  UnityEngine_Vector4_o v80;
  UnityEngine_Vector4_o p;
  nbFormation_t_o *pFormation;
  UnityEngine_Matrix4x4_o v83;
  UnityEngine_Matrix4x4_o pMatrix;
  UnityEngine_Matrix4x4_o v85;
  UnityEngine_Matrix4x4_o v86;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector4_o pPos;
  UnityEngine_Vector4_o v89;
  UnityEngine_Vector4_o v90;
  UnityEngine_Vector4_o v91;

  *&pPos.x = 0;
  *&pPos.z = 0;
  *&v80.x = 0;
  *&p.z = 0;
  pFormation = 0;
  *&v80.z = 0;
  *&p.x = 0;
  sub_854690(&pPos.x, 0.0, 0.0, 0.0, 0.0);
  memset(&v86, 0, sizeof(v86));
  memset(&v85, 0, sizeof(v85));
  memset(&pMatrix, 0, sizeof(pMatrix));
  memset(&aMatrix, 0, sizeof(aMatrix));
  memset(&v83, 0, sizeof(v83));
  *&v79.m00 = 0;
  *&v79.m20 = 0;
  sub_854690(&v79.m00, 0.0, 1.0, 0.0, 0.0);
  sub_854690(&p.x, 0.0, 1.0, 0.0, 0.0);
  sub_854690(&v80.x, 0.0, 0.0, 0.0, 1.0);
  m10 = v79.m10;
  m00 = v79.m00;
  m30 = v79.m30;
  m20 = v79.m20;
  frame = (*hBTLCutEffect)->frame;
  pSkillCut = (*hBTLCutEffect)->pSkillCut;
  pFormation = (*hBTLCutEffect)->pFormation;
  if (!frame)
  {
    effBTLCutSetCameraState(hBTLCutEffect);
    effBTLPointLightSet(&pSkillCut->light, &pFormation);
    effBTLModelColorSet(&pSkillCut->model, &pFormation);
  }
  shake = pSkillCut->camera->shake;
  v12 = shake[8];
  if (shake[8] && frame == shake[9])
  {
    if (v12 <= 0x1E)
    {
      life = shake[10];
      v17 = 10 * v12;
    }
    else
    {
      LOWORD(v79.m00) = shake[8];
      v14 = sub_8D3950(ushort, &v79);
      Write_2930400("effBattle : shake over[{0:D}]\n", v14);
      life = pSkillCut->camera->shake->life;
      v17 = 300;
    }
    dds3SetQuake(life, v17);
  }
  SDF_VU0__LOADVECTOR(pFormation->rot);
  v89.x = m00;
  v89.y = m10;
  v89.z = m20;
  v89.w = m30;
  SDF_VU0__LOADVECTOR_B(v89);
  Mult();
  ToMatrix();
  SDF_VU0__STOREMATRIX(&aMatrix);
LABEL_30:
  pInvokeForm = effBTLSkillInfo->pInvokeForm;
  if (pInvokeForm)
    goto LABEL_33;
LABEL_36:
  SDF_VU0__LOADVECTOR(p);
  ToMatrix();
  SDF_VU0__STOREMATRIX(&v86);
  v90 = v80;
LABEL_43:
  SDF_VU0__LOADVECTOR(v90);
  ToMatrix();
  SDF_VU0__STOREMATRIX(&v85);
  draw_frame = (*hBTLCutEffect)->draw_frame;
  AllPartColor = effBTLCutGetAllPartColor(frame, draw_frame);
  parts = pSkillCut->parts;
  abgr = AllPartColor;
  if (parts->number)
  {
    stat = (*hBTLCutEffect)->stat;
    v28 = 0;
    v29 = 0;
    v30 = 8LL * parts->number - 8;
    list = parts->list;
    if (!LODWORD(list->max_length))
    {
LABEL_54:
    }
    while (1)
    {
      v34 = list->m_Items[v28 / 8];
      if (v34->timing < frame)
        break;
      v51 = pSkillCut->parts->list;
      if (v34)
        goto LABEL_121;
LABEL_122:
      *&v51[v28 / 4 + 8] = v34;
LABEL_125:
      if (v30 == v28)
        goto LABEL_126;
      ++v29;
      v28 += 8LL;
      list = pSkillCut->parts->list;
      if (v29 >= LODWORD(list->max_length))
        goto LABEL_54;
    }
    reverberations = v34->reverberations;
    if (v34->reverberations)
    {
      if ((stat & 1) == 0)
        goto LABEL_125;
      v36 = (stat & 2) == 0;
      if (v36 && reverberations == 2 || !v36 && reverberations == 1)
        goto LABEL_125;
    }
    hPart = (*hBTLCutEffect)->hPart;
    if (hPart->m_Items[v28 / 8])
    {
      p_pos_ptr = &v34->pos_ptr;
      effBTLPartGetPositionPtr(&pFormation, &v34->pos_ptr, &pPos);
      v41 = (*hBTLCutEffect)->hPart;
      x = pPos.x;
      y = pPos.y;
      z = pPos.z;
      w = pPos.w;
      else if (v29 >= LODWORD(v41->max_length))
      {
        goto LABEL_70;
      }
      v91.x = x;
      v91.y = y;
      v91.z = z;
      v91.w = w;
      dds3EffectPartSetPosition(&v41->m_Items[v28 / 8], v91);
      switch ((*p_pos_ptr)->target)
      {
        case 0u:
        case 4u:
          v48 = (*hBTLCutEffect)->hPart;
          v79 = aMatrix;
          else if (v29 >= LODWORD(v48->max_length))
          {
LABEL_75:
          }
          v50 = &v78;
          v78 = v79;
LABEL_105:
          dds3EffectPartSetRotateMatrix(&v48->m_Items[v28 / 8], v50);
LABEL_106:
          effBTLPartGetRotateMatrixPtr(&v34->pos_ptr, &pMatrix);
          v59 = (*hBTLCutEffect)->hPart;
          v79 = pMatrix;
          else if (v29 >= LODWORD(v59->max_length))
          {
LABEL_112:
          }
          v73 = v79;
          dds3EffectPartSetDirection(&v59->m_Items[v28 / 8], &v73);
          RadiusPtr = effBTLPartGetRadiusPtr(&pFormation, &v34->pos_ptr);
          v62 = (*hBTLCutEffect)->hPart;
          dds3EffectPartSetArea(&v62->m_Items[v28 / 8], RadiusPtr);
          v64 = (*hBTLCutEffect)->hPart;
          dds3EffectPartSetColor(&v64->m_Items[v28 / 8], abgr);
          v66 = (*hBTLCutEffect)->hPart;
          dds3EffectPartDraw(&v66->m_Items[v28 / 8]);
          break;
        case 1u:
          v48 = (*hBTLCutEffect)->hPart;
          v79 = v86;
          v50 = &v77;
          v77 = v79;
          goto LABEL_105;
        case 2u:
          v48 = (*hBTLCutEffect)->hPart;
          v79 = v85;
          v50 = &v76;
          v76 = v79;
          goto LABEL_105;
        case 5u:
          height = (*p_pos_ptr)->height;
          effBTLModelGetMarkMatrix2(&pFormation, height);
          v75 = aMatrix;
          SDF_VU0__LOADMATRIX_B(&v75);
          MultMatrixNoArg();
          SDF_VU0__STOREMATRIX(&v83);
          v48 = (*hBTLCutEffect)->hPart;
          v79 = v83;
          v50 = &v74;
          v74 = v79;
          goto LABEL_105;
        default:
          goto LABEL_106;
      }
    }
    v51 = pSkillCut->parts->list;
LABEL_121:
    goto LABEL_122;
  }
LABEL_126:
  if (pSkillCut->model->motion_timing == frame)
  {
    MotionChangeCallback = (*hBTLCutEffect)->MotionChangeCallback;
    if (MotionChangeCallback)
      effBTLCutHandle_t_MotionChangeCallbackDelegate__Invoke(MotionChangeCallback, *hBTLCutEffect);
  }
  v70 = *hBTLCutEffect;
  if ((*hBTLCutEffect)->cut_frame == frame)
  {
    CutEndCallback = v70->CutEndCallback;
    if (CutEndCallback)
      effBTLCutHandle_t_CutEndCallbackDelegate__Invoke(CutEndCallback, v70);
  }
  ++(*hBTLCutEffect)->frame;
}

// 0x1812820
u32 effBTLCutGetAllPartColor(u32 frame, u32 frame_end) {
  u32 v5;
  f32 v6;
  f32 v7;
  f32 v9;
  UnityEngine_Vector4_o v10;
  UnityEngine_Vector4_o v11;

  *&v11.x = 0;
  *&v11.z = 0;
  *&v10.x = 0;
  *&v10.z = 0;
  sub_854690(&v11.x, 1.0, 1.0, 1.0, 1.0);
  sub_854690(&v10.x, 1.0, 1.0, 1.0, 0.0);
  v5 = frame_end - frame;
  if (frame_end <= frame)
    return 8421504;
  if (frame_end <= 5)
  {
    v6 = v5;
    v7 = frame_end;
LABEL_7:
    v9 = v6 / v7;
    goto LABEL_8;
  }
  v9 = 1.0;
  if (frame_end - 6 < frame)
  {
    v6 = v5;
    v7 = 6.0;
    goto LABEL_7;
  }
LABEL_8:
  SDF_VU0__LOADVECTOR(v10);
  SDF_VU0__LOADVECTOR_B(v11);
  SDF_VU0__SCALEVECTOR(1.0 - v9);
  SDF_VU0__SCALEVECTOR_B(v9);
  SDF_VU0__ADDVECTOR();
  return SDF_VU0__dds3ColorFtoI(128.0);
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
      goto LABEL_8;
LABEL_9:
    if (v5 >= LODWORD(hPart->max_length))
    {
LABEL_10:
    }
    while (1)
    {
      dds3EffectPartSetScale((hPart + v7), scale, 0);
      if (v6 == v5)
        break;
      ++v5;
      v7 += 8;
      hPart = (*hBTLCutEffect)->hPart;
        goto LABEL_9;
LABEL_8:
        goto LABEL_9;
      if (v5 >= LODWORD(hPart->max_length))
        goto LABEL_10;
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
            goto LABEL_10;
        }
        effBTLCutDelete(&hBTLCutEffect);
        hBTLCutEffect = hCutListTop;
      }
      while (hCutListTop);
LABEL_10:
      v3 = *hBTLEffect;
    }
    p_Skill = &v3->Skill;
    effBTLPartDelete(p_Skill);
    Write("effBTL:handle delete\n", 0);
  }
}

// 0x18167c0
void effBTLFieldColorDraw(void) {
  effBattle_c *v3;

  else if (!effBTLFieldColorProcess)
  {
    return;
  }
LABEL_10:
  if (HIBYTE(effBTLFieldColorFilter->filter->abgr)
    && (v3->_2.bitflags2 & 2) != 0
  {
  }
}

// 0x1815520
void effBTLFieldColorEnd(void) {
  if (effBTLFieldColorProcess)
  {
    effBTLFieldColorProcess = 4;
  }
}

// 0x1815250
void effBTLFieldColorGetBaseColor(void) {
  nbMainProcessData_t_o *MainProcessData;
  s16 v4;
  s32 StageMinor;
  struct effBTL_FieldBaseColorTable_t_array *effBTL_FieldBaseColorTable;
  u32 max_length;
  u32 v9;
  struct UnityEngine_Vector4_array *light;
  UnityEngine_Vector4_o v13;
  UnityEngine_Vector4_o v14;

  *&v13.x = 0;
  *&v13.z = 0;
  sub_854690(&v13.x, 1.0, 1.0, 1.0, 1.0);
  MainProcessData = nbGetMainProcessData();
  v4 = MainProcessData->StageMajor - 200;
  if (v4 < 0)
    goto LABEL_27;
  StageMinor = MainProcessData->StageMinor;
  max_length = effBTL_FieldBaseColorTable->max_length;
  if (v4 >= max_length || (v9 = StageMinor - 1, v9 >= 0xA))
  {
LABEL_27:
    Write("effBTLFieldColorGetBaseColor:DummyColorLoad\n", 0);
    v14 = v13;
  }
  else
  {
    light = effBTL_FieldBaseColorTable->m_Items[v4]->light;
    v14 = light->m_Items[v9];
  }
  SDF_VU0__LOADVECTOR(v14);
}

// 0x18151e0
void effBTLFieldColorInit(void) {
  effBTLFieldColorProcess = 0;
}

// 0x18142e0
void effBTLFieldColorOFF(void) {
LABEL_7:
  if (effBTLFieldColorProcess)
  {
    effBTLFieldColorProcess = 4;
  }
}

// 0x1813bf0
void effBTLFieldColorON(u32 id) {
  u64 v4;
  s64 v5;
  struct effBTL_FieldColorTable_t_array *effBTL_FieldColorTable;
  f32 *v10;
  System_Object_array *v11;
  System_Object_array *v12;
  s64 *v13;
  s64 *v14;
  s64 *v16;
  s64 *v17;
  s64 *v20;
  s64 *v21;
  struct effBTL_FieldColorTable_t_array *v24;
  s32 v26;
  s64 *v27;
  s64 *v28;
  struct effBTL_FieldColorTable_t_array *v31;
  s32 v33;
  s64 *v34;
  s64 *v35;
  struct effBTL_FieldColorTable_t_array *v38;
  s32 v40;
  s64 *v41;
  s64 *v43;
  f32 w;
  f32 v50;
  struct effBTL_FieldColorTable_t_array *v52;
  s32 v55;
  s32 v56;
  s32 v57;
  f32 z;
  u64 v59[2];
  UnityEngine_Vector4_o p;
  f32 y;
  f32 x;
  UnityEngine_Vector4_o v63;

  *&p.x = 0;
  *&p.z = 0;
  v59[0] = 0;
  v59[1] = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(v59, 0.0, 0.0, 0.0, 0.0);
  *(*(v4 + 184) + 32LL) = id;
  v5 = *(*(v4 + 184) + 160LL);
  if (*(*(v5 + 8LL * id + 32) + 16LL) != 0.0)
  {
    if ((*(v4 + 294) & 0x200) != 0)
    {
      {
      }
    }
    effBTLFieldColorGetBaseColor(v4);
    v10 = effBTL_FieldColorTable->m_Items[id];
    v63.y = v10[6];
    v63.z = v10[7];
    v63.w = v10[8];
    p.x = v10[5];
    v63.x = p.x;
    p.y = v63.y;
    p.z = v63.z;
    p.w = v63.w;
    SDF_VU0__LOADVECTOR_B(v63);
    SDF_VU0__MULVECTOR();
    SDF_VU0__STOREVECTOR(&p);
    v11 = NewSpecific(object, 6u);
    x = p.x;
    v12 = v11;
    v13 = sub_8D3950(f32, &x);
    v14 = v13;
    v12->m_Items[0] = v14;
    y = p.y;
    v16 = sub_8D3950(f32, &y);
    v17 = v16;
    v12->m_Items[1] = v17;
    z = p.z;
    v20 = sub_8D3950(f32, &z);
    v21 = v20;
    v12->m_Items[2] = v21;
    v24 = effBTL_FieldColorTable;
    sub_854710(&v24->m_Items[id]->light, 1u);
    v57 = v26;
    v27 = sub_8D3950(f32, &v57);
    v28 = v27;
    v12->m_Items[3] = v28;
    v31 = effBTL_FieldColorTable;
    sub_854710(&v31->m_Items[id]->light, 2u);
    v56 = v33;
    v34 = sub_8D3950(f32, &v56);
    v35 = v34;
    v12->m_Items[4] = v35;
    v38 = effBTL_FieldColorTable;
    sub_854710(&v38->m_Items[id]->light, 3u);
    v55 = v40;
    v41 = sub_8D3950(f32, &v55);
    v43 = v41;
    v12->m_Items[5] = v43;
    Write_2930544("FieldColor:{0:f},{1:f},{2:f}({3:f},{4:f},{5:f})\n", v12, 0);
    v50 = p.z;
    w = p.w;
    *&effBTLFieldColorDiffuse.x = *&p.x;
    effBTLFieldColorDiffuse.z = v50;
    effBTLFieldColorDiffuse.w = w;
    v52 = effBTL_FieldColorTable;
    effBTLFieldColorFilterABGR = v52->m_Items[id]->filter;
    effBTLFieldColorStart();
LABEL_61:
      goto LABEL_64;
    goto LABEL_62;
  }
  if ((*(v4 + 294) & 0x200) == 0 || *(v4 + 216))
    goto LABEL_61;
    goto LABEL_64;
LABEL_62:
LABEL_64:
  effBTLFieldLightAnimFrame = 0;
  effBTLFieldLightAnimFrameEnd = 0;
  effBTLFieldLightAnimRotate = 0.0;
}

// 0x1815d60
void effBTLFieldColorRun(void) {
  u64 v2;
  struct effBattle_StaticFields *v3;
  nbMainProcessData_t_o *v5;
  struct fldResourceLight_t_o *v8;
  f32 v9;
  struct fldResourceLight_t_o *v11;
  f32 v12;
  struct fldResourceLight_t_o *v14;
  f32 v15;
  struct fldResourceLight_t_o *v17;
  f32 v18;
  struct fldResourceLight_t_o *v20;
  f32 v21;
  struct fldResourceLight_t_o *v23;
  f32 v24;
  dds3Basic_t_o **v25;
  struct sdf3DLight_t_array *v28;
  s32 v31;
  struct sdf3DLight_t_array *dds3DirLights;
  struct sdf3DLight_t_array *v35;
  nbMainProcessData_t_o *MainProcessData;
  struct fldResourceLight_t_o *effBTLFieldColorSceneLight;
  f32 v42;
  struct fldResourceLight_t_o *v44;
  f32 v45;
  struct fldResourceLight_t_o *v47;
  f32 v48;
  dds3Basic_t_o **p_niidalight;
  struct sdf3DLight_t_array *v53;
  struct sdf3DLight_t_array *v55;
  struct sdf3DLight_t_array *v57;
  s32 Alpha;
  s32 v60;
  f32 x;
  f32 effBTLFieldLightAnimRotate;
  f32 y;
  f32 z;
  f32 w;
  struct sdf3DLight_t_array *v68;
  struct sdf3DLight_t_array *v70;
  dds3Basic_t_o **v72;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v78;
  s64 *v79;
  u64 v80[3];
  UnityEngine_Vector4_o v81;

  v3 = *(v2 + 184);
  switch (effBTLFieldColorProcess)
  {
    case 0u:
      return;
    case 1u:
      SDF_VU0__COPYVECTOR(&effBTLFieldColorDirectionBase, dds3DirLights->m_Items[0]->v);
      v35 = dds3DirLights;
      SDF_VU0__COPYVECTOR(&effBTLFieldColorDiffuseBase, v35->m_Items[0]->color);
      SDF_VU0__COPYVECTOR(&effBTLFieldColorAmbientBase, dds3Ambient);
      goto LABEL_44;
    case 2u:
LABEL_44:
      MainProcessData = nbGetMainProcessData();
      sub_854710(&effBTLFieldColorDiffuse, 0);
      effBTLFieldColorSceneLight->DiffuseR = v42;
      v44 = effBTLFieldColorSceneLight;
      sub_854710(&effBTLFieldColorDiffuse, 1u);
      v44->DiffuseG = v45;
      v47 = effBTLFieldColorSceneLight;
      sub_854710(&effBTLFieldColorDiffuse, 2u);
      v47->DiffuseB = v48;
      effBTLFieldColorSceneLight->AmbientR = effBTLFieldColorSceneLight->DiffuseR;
      effBTLFieldColorSceneLight->AmbientG = effBTLFieldColorSceneLight->DiffuseG;
      effBTLFieldColorSceneLight->AmbientB = effBTLFieldColorSceneLight->DiffuseB;
      effBTLFieldColorSceneLight->InsideR = 0.0;
      effBTLFieldColorSceneLight->OutsideR = 0.0;
      effBTLFieldColorSceneLight->Soften = 0.0;
      effBTLFieldColorSceneLight->Bias = 0.0;
      effBTLFieldColorSceneLight->resv = 0;
      effBTLFieldColorSceneLight->Flag = 0;
      effBTLFieldColorSceneLight->AnimeType = 0;
      p_niidalight = &MainProcessData->niidalight;
      dds3SetLightObjectResoruce(p_niidalight, effBTLFieldColorSceneLight);
      dds3LinkSceneLight(p_niidalight, 0xCu);
      v53 = dds3DirLights;
      v53->m_Items[0]->v.x = -0.73;
      v55 = dds3DirLights;
      v55->m_Items[0]->v.y = 1.55;
      v57 = dds3DirLights;
      v57->m_Items[0]->v.z = 0.24;
      Alpha = fldSkyGetAlpha();
      *(*(v2 + 184) + 144LL) = Alpha;
      *(*(v2 + 184) + 140LL) = 64;
      *(*(v2 + 184) + 148LL) = 12;
      *(*(v2 + 184) + 150LL) = 12;
      v60 = *(*(v2 + 184) + 36LL);
      *(*(*(v2 + 184) + 152LL) + 32LL) = 12;
      *(*(*(v2 + 184) + 152LL) + 34LL) = 12;
      *(*(*(v2 + 184) + 152LL) + 24LL) = *(*(*(*(v2 + 184) + 152LL) + 16LL) + 16LL);
      *(*(*(v2 + 184) + 152LL) + 28LL) = v60;
      *(*(v2 + 184) + 28LL) = 3;
      if ((*(v2 + 295) & 2) == 0)
        goto LABEL_111;
      goto LABEL_109;
    case 3u:
      if (effBTLFieldLightAnimFrameEnd < effBTLFieldLightAnimFrame)
        goto LABEL_108;
      x = effBTLFieldLightAnimAxis.x;
      y = effBTLFieldLightAnimAxis.y;
      z = effBTLFieldLightAnimAxis.z;
      w = effBTLFieldLightAnimAxis.w;
      v81.x = x;
      v81.y = y;
      v81.z = z;
      v81.w = w;
      SetRotateMatrixAxis(-effBTLFieldLightAnimRotate, v81);
      v68 = dds3DirLights;
      SDF_VU0__LOADVECTOR(v68->m_Items[0]->v);
      SDF_VU0__APPLYMATRIX();
      v70 = dds3DirLights;
      SDF_VU0__STOREVECTOR(&v70->m_Items[0]->v);
      ++effBTLFieldLightAnimFrame;
      if ((*(v2 + 295) & 2) == 0)
        goto LABEL_111;
      goto LABEL_109;
    case 4u:
      v5 = nbGetMainProcessData();
      v8 = effBTLFieldColorSceneLight;
      sub_854710(&effBTLFieldColorDiffuseBase, 0);
      v8->DiffuseR = v9;
      v11 = effBTLFieldColorSceneLight;
      sub_854710(&effBTLFieldColorDiffuseBase, 1u);
      v11->DiffuseG = v12;
      v14 = effBTLFieldColorSceneLight;
      sub_854710(&effBTLFieldColorDiffuseBase, 2u);
      v14->DiffuseB = v15;
      v17 = effBTLFieldColorSceneLight;
      sub_854710(&effBTLFieldColorAmbientBase, 0);
      v17->AmbientR = v18;
      v20 = effBTLFieldColorSceneLight;
      sub_854710(&effBTLFieldColorAmbientBase, 1u);
      v20->AmbientG = v21;
      v23 = effBTLFieldColorSceneLight;
      sub_854710(&effBTLFieldColorAmbientBase, 2u);
      v23->AmbientB = v24;
      v25 = &v5->niidalight;
      dds3SetLightObjectResoruce(v25, effBTLFieldColorSceneLight);
      dds3LinkSceneLight(v25, 0xCu);
      v28 = dds3DirLights;
      SDF_VU0__COPYVECTOR(&v28->m_Items[0]->v, effBTLFieldColorDirectionBase);
      v31 = fldSkyGetAlpha();
      *(*(v2 + 184) + 144LL) = v31;
      *(*(v2 + 184) + 140LL) = 128;
      *(*(v2 + 184) + 148LL) = 12;
      *(*(v2 + 184) + 150LL) = 12;
      *(*(*(v2 + 184) + 152LL) + 32LL) = 12;
      *(*(*(v2 + 184) + 152LL) + 34LL) = 12;
      *(*(*(v2 + 184) + 152LL) + 24LL) = *(*(*(*(v2 + 184) + 152LL) + 16LL) + 16LL);
      *(*(*(v2 + 184) + 152LL) + 28LL) = 0;
      *(*(v2 + 184) + 28LL) = 5;
      if ((*(v2 + 295) & 2) == 0)
        goto LABEL_111;
      goto LABEL_109;
    case 5u:
      v72 = &nbGetMainProcessData()->niidalight;
      workdata = (*v72)->workdata;
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3LightObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3LightObjectBasicWorkData_t, v80);
        if ((v80[0] & 1) != 0)
          v78 = v80[2];
        else
          v78 = v80 + 1;
        v79 = sub_8C4940(v78);
      }
      if (!LOWORD(workdata[4].monitor))
      {
        effBTLFieldColorFilter->frame = 0;
        effBTLFieldColorFilter->filter->abgr = 0;
        dds3UnlinkSceneLight(v72);
        effBTLFieldColorProcess = 0;
      }
      goto LABEL_108;
    default:
LABEL_108:
      if ((*(v2 + 295) & 2) != 0)
      {
LABEL_109:
      }
LABEL_111:
      effBTLSkyFilterRun(v2);
      effBTLFieldFilterRun();
      return;
  }
}

// 0x1815410
void effBTLFieldColorStart(void) {
  s32 v3;

  {
    else
    {
      if (effBTLFieldColorProcess)
        goto LABEL_5;
    }
LABEL_11:
    if (v3)
    {
      else
      {
        effBTLFieldColorProcess = 1;
      }
    }
    else
    {
      effBTLFieldColorProcess = 1;
    }
    return;
  }
  v3 = 0;
  if (!effBTLFieldColorProcess)
    goto LABEL_11;
LABEL_5:
  effBTLFieldColorProcess = 2;
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
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  struct sdf3DLight_t_array *dds3DirLights;
  UnityEngine_Vector4_o v9;

  w = pDir.w;
  z = pDir.z;
  y = pDir.y;
  x = pDir.x;
  else
  {
    if (!LODWORD(dds3DirLights->max_length))
      goto LABEL_6;
  }
  v9.z = z;
  v9.w = w;
  v9.x = x;
  v9.y = y;
  SDF_VU0__COPYVECTOR(&dds3DirLights->m_Items[0]->v, v9);
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
  u64 v4;
  u64 v5;
  struct effBTL_SkillCutTable_t_array *cut;
  struct effBTL_SkillParts_t_o *parts;
  u64 number;
  s64 v10;
  u64 v12;
  u32 v13;
  struct effBTL_SkillCutTable_t_array *v14;
  struct effBTL_SkillPartsList_t_array *v16;
  effBTL_SkillPartsList_t_o *v18;
  Il2CppObject *pHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v22;
  s64 *v23;
  effPartHandle_t_o *v24;
  s32 type;
  Il2CppObject *p_obj;
  s32 v27;
  struct effBTL_SkillCutTable_t_array *v28;
  u64 v29;
  struct effBTL_SkillPartsList_t_array *list;
  s64 v33;
  u32 v34;
  effPartHandle_t_o *v35;
  s32 v36;
  struct effBTL_SkillCutTable_t_array *v37;
  u32 *v39;
  u64 v41;
  System_Byte_array *bytedata;
  effPartHandle_t_o *hEffPartSrc;
  u64 v44[3];

  bytedata = pData;
  v4 = 0;
  hEffPartSrc = 0;
  do
  {
    v5 = v4;
    cut = (*pSkill)->cut;
    parts = cut->m_Items[v4]->parts;
    number = parts->number;
    if (parts->number)
    {
      v10 = 4;
      do
      {
        v28 = (*pSkill)->cut;
        v29 = v10 - 4;
        list = v28->m_Items[v5]->parts->list;
        v33 = *(&list->obj.klass + v10);
        v27 = *(v33 + 16);
        if (v27 != 65534)
        {
          v34 = *(v33 + 32);
          switch (*(v33 + 16))
          {
            case 0:
            case 1:
            case 2:
            case 4:
            case 5:
            case 6:
              p_obj = &bytedata->obj;
              goto LABEL_38;
            case 3:
              p_obj = &bytedata->obj;
              SobedPbSet(bytedata, v34);
              LOWORD(v27) = *(v33 + 16);
              goto LABEL_38;
            default:
              if (v27 == 0xFFFF)
              {
                v12 = v34 / 0x3CuLL;
                v13 = v34 % 0x3C;
                v14 = (*pSkill)->cut;
                v16 = v14->m_Items[v12]->parts->list;
                v18 = v16->m_Items[v13];
                pHandle = v18->pHandle;
                if (pHandle)
                {
                  klass = pHandle->klass;
                  if (pHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
                    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPartHandle_t)
                  {
                    sub_8FC2C0(klass->_1.element_class, effPartHandle_t, v44);
                    if ((v44[0] & 1) != 0)
                      v22 = v44[2];
                    else
                      v22 = v44 + 1;
                    v23 = sub_8C4940(v22);
                  }
                }
                hEffPartSrc = v18->pHandle;
                v24 = dds3EffectPartCopy(&hEffPartSrc, 0, 0);
                type = v18->type;
                *(v33 + 16) = type;
                *(v33 + 24) = v24;
                if (!type)
                  goto LABEL_42;
              }
              else
              {
                p_obj = 0;
LABEL_38:
                v35 = dds3EffectPartCreate(v27, p_obj, v34, 0);
                v36 = *(v33 + 16);
                *(v33 + 24) = v35;
                if (!v36)
                {
LABEL_42:
                  ++*(v33 + 48);
                  break;
                }
              }
              break;
          }
        }
        v37 = (*pSkill)->cut;
        v39 = v37->m_Items[v5]->parts->list;
        v41 = v10 - 3;
        *&v39[2 * v10++] = v33;
      }
      while (v41 < number);
    }
    v4 = 1;
  }
  while (!v5);
}

// 0x1811cd0
void effBTLPartDelete(effBTL_SkillData_t **pSkill) {
  struct effBTL_SkillCutTable_t_array *cut;
  struct effBTL_SkillParts_t_o *parts;
  u32 number;
  u64 v7;
  struct effBTL_SkillCutTable_t_array *v8;
  struct effBTL_SkillPartsList_t_array *list;
  struct effBTL_SkillCutTable_t_array *v12;
  struct effBTL_SkillPartsList_t_array *v14;
  Il2CppObject *pHandle;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v19;
  s64 *v20;
  struct effBTL_SkillCutTable_t_array *v21;
  struct effBTL_SkillParts_t_o *v22;
  u32 v23;
  s64 v25;
  struct effBTL_SkillCutTable_t_array *v26;
  u64 v27;
  struct effBTL_SkillPartsList_t_array *v29;
  struct effBTL_SkillCutTable_t_array *v31;
  struct effBTL_SkillPartsList_t_array *v33;
  s64 *v35;
  s64 v36;
  s64 v37;
  char *v38;
  s64 *v39;
  Il2CppObject *v40;
  u64 v41[2];
  char *v42;

  v40 = 0;
  cut = (*pSkill)->cut;
  parts = cut->m_Items[0]->parts;
  number = parts->number;
  if (parts->number)
  {
    v7 = 0;
    while (1)
    {
      v8 = (*pSkill)->cut;
      list = v8->m_Items[0]->parts->list;
      if (list->m_Items[v7]->type == -2)
        goto LABEL_24;
      v12 = (*pSkill)->cut;
      v14 = v12->m_Items[0]->parts->list;
      pHandle = v14->m_Items[v7]->pHandle;
      if (pHandle)
      {
        klass = pHandle->klass;
        if (pHandle->klass->_2.typeHierarchyDepth < typeHierarchyDepth
          || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPartHandle_t)
        {
          sub_8FC2C0(klass->_1.element_class, effPartHandle_t, v41);
          if ((v41[0] & 1) != 0)
            v19 = v42;
          else
            v19 = v41 + 1;
          v20 = sub_8C4940(v19);
        }
        v40 = v14->m_Items[v7]->pHandle;
        dds3EffectPartDelete(&v40);
        if (++v7 >= number)
          break;
      }
      else
      {
        v40 = 0;
LABEL_24:
        if (++v7 >= number)
          break;
      }
    }
  }
  v21 = (*pSkill)->cut;
  v22 = v21->m_Items[1]->parts;
  v23 = v22->number;
  if (v22->number)
  {
    v25 = 4;
    while (1)
    {
      v26 = (*pSkill)->cut;
      v27 = v25 - 4;
      v29 = v26->m_Items[1]->parts->list;
      if (*(*(&v29->obj.klass + v25) + 16LL) == -2)
        goto LABEL_52;
      v31 = (*pSkill)->cut;
      v33 = v31->m_Items[1]->parts->list;
      v35 = *(*(&v33->obj.klass + v25) + 24LL);
      if (v35)
      {
        v36 = *v35;
        if (*(*v35 + 288) < v37 || *(*(v36 + 200) + 8 * v37 - 8) != effPartHandle_t)
        {
          sub_8FC2C0(*(v36 + 64), effPartHandle_t, v41);
          if ((v41[0] & 1) != 0)
            v38 = v42;
          else
            v38 = v41 + 1;
          v39 = sub_8C4940(v38);
        }
        v40 = *(*(&v33->obj.klass + v25) + 24LL);
        dds3EffectPartDelete(&v40);
        if (++v25 - 4 >= v23)
          return;
      }
      else
      {
        v40 = 0;
LABEL_52:
        if (++v25 - 4 >= v23)
          return;
      }
    }
  }
}

// 0x1814a60
s32 effBTLSkillCheckRun(void) {
  return effBTLSkillRun;
}

// 0x1814ad0
bool effBTLSkillCheckRun2(u32 skillid) {
LABEL_7:
  if (!effBTLSkillRun)
    return 0;
LABEL_10:
LABEL_14:
  return effBTLSkillID == skillid;
}

// 0x1814d40
bool effBTLSkillCheckRun3(u32 modelID) {
  effBattle_c *v3;

LABEL_7:
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

LABEL_7:
  else if (!effBTLSkillRun)
  {
    return 0;
  }
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
  Write("effBTL:Skill End\n", 0);
}

// 0x1814c30
u32 effBTLSkillGetID(void) {
  return effBTLSkillID;
}

// 0x1814600
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx) {
  struct effBattle_effBTLSkill_Info_tag_o *effBTLSkillInfo;
  nbFormation_t_o **p_pInvokeForm;
  nbMainProcessData_t_o *MainProcessData;
  struct nbFormation_t_array *form;

  else
  {
    if (effBTLSkillInfo->pInvokeForm)
      goto LABEL_6;
  }
  MainProcessData = nbGetMainProcessData();
  Write("effBTL:InvokeForm == NULL ****** !!\n", 0);
  form = MainProcessData->form;
  p_pInvokeForm = &form->m_Items[idx];
  return *p_pInvokeForm;
}

// 0x1813730
u32 effBTLSkillGetInvokeParty(void) {
  struct nbFormation_t_o *pInvokeForm;

  pInvokeForm = effBTLSkillInfo->pInvokeForm;
  if (!pInvokeForm)
    return 256;
LABEL_6:
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
  struct effBattle_effBTLSkill_Info_tag_o *effBTLSkillInfo;
  nbFormation_t_o **p_pInvokeForm;

  else
  {
    if (effBTLSkillInfo->target_number)
      goto LABEL_6;
  }
  Write("error: effBTLSkillInfo.target_number == 0\n", 0);
  p_pInvokeForm = &effBTLSkillInfo->pInvokeForm;
  return *p_pInvokeForm;
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
  Write("effBTLSkillInit \n", 0);
}

// 0x18143c0
void effBTLSkillSetFormationInfo(u32 InvokeID, u32 TargetBit) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbFormation_t_array *form;
  u64 v10;
  u32 v11;
  s32 v12;
  struct nbFormation_t_array *v13;
  s64 *v15;
  struct nbFormation_t_array *pTargetForm;
  Il2CppClass **v19;

  MainProcessData = nbGetMainProcessData();
  form = MainProcessData->form;
  effBTLSkillInfo->pInvokeForm = form->m_Items[InvokeID];
  v10 = 0;
  v11 = 0;
  v12 = 1;
  effBTLSkillInfo->target_bit = TargetBit;
  do
  {
    v13 = MainProcessData->form;
    if ((v12 & TargetBit) != 0)
    {
      v15 = v13->m_Items[v10];
      else
      {
        pTargetForm = effBTLSkillInfo->pTargetForm;
        if (v15)
          goto LABEL_18;
      }
      v19 = &pTargetForm->obj.klass + v11++;
      v19[4] = v15;
    }
    ++v10;
    v12 *= 2;
  }
  while (v10 != 32);
  effBTLSkillInfo->target_number = v11;
  Write("effBTL:Skill Set Formation Info\n", 0);
}

// 0x18150a0
void effBTLSkillSetState(u32 state) {
  u64 *v5;
  u32 effBTLSkillState;

  effBTLSkillState = state;
  v5 = sub_8D3950(uint, &effBTLSkillState);
  Write_2930400("effBTL:Set Stat[{0:X}]\n", v5);
}

// 0x18139f0
void effBTLSkillStart(u32 id, u32 stat) {
  u32 effBTLSkillID;
  u16 v8;
  u64 *v13;
  u64 *v14;
  u32 v15;
  u32 v16;

  effBTLSkillID = id;
  effBTLFieldColorON(effBTLSkillID, *&stat);
  if (effBTLSkillID <= 0x1FF)
  {
    if (effBTLSkillID)
    {
      v8 = 6;
    }
    else
    {
      v8 = 5;
    }
    nbCameraSetState(v8);
  }
  effBTLPointLightON();
  effBTLPartPtrGetAllModelCenterOffset();
  effBTLSkillRun = 1;
  v16 = stat;
  v13 = sub_8D3950(uint, &v16);
  Write_2930400("effBTL:Set Stat[{0:X}]\n", v13);
  v15 = id;
  v14 = sub_8D3950(uint, &v15);
  Write_2930400("effBTL:Skill Start[{0:X}]\n", v14);
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
  u32 effBTLSkyFilterFrame;
  s32 effBTLSkyFilterAlphaTarget;
  s32 effBTLSkyFilterAlphaBase;
  f32 v8;

  if (effBTLSkyFilterFrame)
  {
    LOWORD(v2) = effBTLSkyFilterFrameMax;
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
  target = dds3StartProcess("nb_effect", 0x3F9u, 2, 1, v7, 0, v8, 0, 0, 0);
  dds3LinkProcess(&(*data)->MainProcessID, &target, 0);
  (*data)->EffectProcessID = target;
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_effBattle_nbEffectDraw__);
  started = dds3StartProcess("nb_effect_draw", 0x2B0Eu, 1, 1, v10, 0, 0, 0, 0, 0);
  dds3LinkProcess(&target, &started);
  effBTLSkillInit();
  effBTLFieldColorProcess = 0;
  effBTLPointLightInit();
  effBTLModelShowInit();
  effBTLSystemPartHandleCreate();
}
