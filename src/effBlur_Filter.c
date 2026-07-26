#include "types.h"

typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct dds3Effect_DistBlurPart_tag dds3Effect_DistBlurPart_tag;
typedef struct dds3Effect_DistortionBlurParam_t dds3Effect_DistortionBlurParam_t;
typedef struct dds3Effect_Filter_t dds3Effect_Filter_t;
typedef struct dds3Effect_PartialMultiBlurParam_t dds3Effect_PartialMultiBlurParam_t;
typedef struct dds3Effect_PartialMultiBlur_t dds3Effect_PartialMultiBlur_t;
typedef struct dds3Effect_PartialMultiFilterParam_t dds3Effect_PartialMultiFilterParam_t;
typedef struct dds3Effect_PartialMultiFilter_t dds3Effect_PartialMultiFilter_t;
typedef struct dds3Effect_RipBlurPart_tag dds3Effect_RipBlurPart_tag;
typedef struct dds3Effect_RippleBlurParam_t dds3Effect_RippleBlurParam_t;
typedef struct effDistortionBlurHandle_t effDistortionBlurHandle_t;
typedef struct effPkt2DTriStripParm_t effPkt2DTriStripParm_t;
typedef struct effRippleBlurHandle_t effRippleBlurHandle_t;
typedef struct mdlManager_mdlTbMbAbLoadCb_t mdlManager_mdlTbMbAbLoadCb_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 DDS3_SCREEN_OFFX;
static s32 DDS3_SCREEN_OFFY;
static f32 DDS3EFFECT_MULTIFILTER_GETEX_SCALE;
static bool EventMode;
static s32 EventNo;
static f32 FldEve_Pow;
static s32 FldEve_UnityEx_ID;
static f32 FldEve_UnityEx_CntF;
static f32 E601_alp_CntF;
static f32 E601_area_CntF;
static s32 E628_pm_CntI;
static f32 E655_After_CntF;
static f32 E655_After_CntF2;
static f32 E674_aradia_CntF;
static f32 E674_aradia_CntF2;
static s32 E674_aradia_fdof_CntI;
static f32 E748_alp;
static f32 Majin_CntF;
static void *DistortionBlur_Sprite;
static bool evePicFlag;
static bool UpdateFlg_AllOff;
static bool UpdateFlg_blur;
static bool UpdateFlg_distortionblur;
static bool UpdateFlg_multiblur;
static bool UpdateFlg_filter;
static bool UpdateFlg_multifilter;
static void *dbg_fps;

bool ChkNbEventRun(void);
void Clear(mdlManager_mdlTbMbAbLoadCb_t *this);
void ClrDrawFlag(u32 flag);
u32 DDS3EFFECT_RAND_I(void);
f32 DDS3EFFECT_RAND_PM(void);
void DrawStopExec(void);
u32 GetDrawFlag(void);
char *GetEventCamName(void);
void *GetMainCamera(dds3DefaultMain *this);
char *GetNowCameraName(void);
char *GetNowName_SCR_RUN(void);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void ScreenStop1(void);
void SetDrawFlag(u32 flag, u32 cnt);
sdfTexHandle_t *dds3BillboardGetGeneralTex(s32 number);
void dds3EffectRipBlurPartInit(dds3Effect_RippleBlurParam_t *pParam, dds3Effect_RipBlurPart_tag **pPart);
f32 dds3FadeGetAlphaF(void);
f32 dds3FadeGetColAverageF(void);
void effBTLModelGetSphereCenter(nbFormation_t **pFormation);
bool effBTLSkillCheckRun2(u32 skillid);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
bool evtBitCheck(s32 no);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);

// 0x137d1b0
void FldEve_Blur_Pow(f32 pow) {
  FldEve_Pow = pow;
}

// 0x137a030
f32 HD_X(f32 valx) {
  return valx;
}

// 0x137a040
f32 HD_Y(f32 valy) {
  return valy;
}

// 0x13867f0
void Set_EventID(s32 eno) {
  EventNo = eno;
}

// 0x1386780
void Set_EventMode(bool onoff) {
  EventMode = onoff;
}

// 0x1383d60
void Set_PicFlag(bool flag) {
  evePicFlag = flag;
}

// 0x137a020
s32 blur_SCREEN_HEIGHT(void) {
  return 1080;
}

// 0x137a010
s32 blur_SCREEN_WIDTH(void) {
  return 1920;
}

// 0x137a3c0
void dds3EffectBlur(dds3Effect_Blur_t **pBlur, bool bPS2mode, s32 SkillID) {
    ChkNbEventRun();
    GetEventCamName();
    evtBitCheck(0);
    GetNowCameraName();
}

// 0x137a050
void dds3EffectBlur_AlphaMultiParmSet(dds3Effect_Blur_t **pBlur, effPkt2DTriStripParm_t **pSpriteParm) {
  struct sdfGrTagXYZ2_t_o *xyz0;
  struct sdfIVector2_t_array *xy;
  struct System_Int32_array *pm;
  struct sdfIVector2_t_array *v9;
  struct System_Int32_array *v11;
  struct sdfIVector2_t_array *v13;
  struct System_Int32_array *v15;
  struct sdfIVector2_t_array *v17;
  struct System_Int32_array *v19;

  (*pSpriteParm)->rgba->r = 128;
  (*pSpriteParm)->rgba->g = 128;
  (*pSpriteParm)->rgba->b = 128;
  (*pSpriteParm)->rgba->a = HIBYTE((*pBlur)->abgr);
  xyz0 = (*pSpriteParm)->xyz0;
  xy = (*pBlur)->xy;
  pm = xy->m_Items[0]->pm;
  xyz0->x = DDS3_SCREEN_OFFX + 16 * pm->m_Items[0];
  v9 = (*pBlur)->xy;
  v11 = v9->m_Items[0]->pm;
  (*pSpriteParm)->xyz0->y = DDS3_SCREEN_OFFY + 8 * v11->m_Items[1];
  (*pSpriteParm)->xyz1->x = (*pSpriteParm)->xyz0->x;
  v13 = (*pBlur)->xy;
  v15 = v13->m_Items[1]->pm;
  (*pSpriteParm)->xyz1->y = DDS3_SCREEN_OFFY + 8 * v15->m_Items[1];
  v17 = (*pBlur)->xy;
  v19 = v17->m_Items[1]->pm;
  (*pSpriteParm)->xyz2->x = DDS3_SCREEN_OFFX
                                        + 16 * v19->m_Items[0];
  (*pSpriteParm)->xyz2->y = (*pSpriteParm)->xyz0->y;
  (*pSpriteParm)->xyz3->x = (*pSpriteParm)->xyz2->x;
  (*pSpriteParm)->xyz3->y = (*pSpriteParm)->xyz1->y;
  (*pSpriteParm)->stq0->s = 0.0;
  (*pSpriteParm)->stq0->t = 0.0;
  (*pSpriteParm)->stq1->s = 0.0;
  (*pSpriteParm)->stq1->t = 1.0;
  (*pSpriteParm)->stq2->s = 1.0;
  (*pSpriteParm)->stq2->t = 0.0;
  (*pSpriteParm)->stq3->s = 1.0;
  (*pSpriteParm)->stq3->t = 1.0;
  (*pSpriteParm)->xyz0->z = 0;
  (*pSpriteParm)->xyz0->adc = 0;
  (*pSpriteParm)->xyz1->z = 0;
  (*pSpriteParm)->xyz1->adc = 0;
  (*pSpriteParm)->xyz2->z = 0;
  (*pSpriteParm)->xyz2->adc = 0;
  (*pSpriteParm)->xyz3->z = 0;
  (*pSpriteParm)->xyz3->adc = 0;
}

// 0x137f3f0
void dds3EffectDistBlurPartInit(dds3Effect_DistortionBlurParam_t *pParam, dds3Effect_DistBlurPart_tag **pPart) {
  dds3Effect_DistBlurPart_tag_o *v5;
  struct dds3Effect_Blur_t_o *Blur;
  u64 *v7;
  struct sdfIVector2_t_array *v8;
  struct sdfIVector2_t_o *center;
  s32 width;
  struct System_Int32_array *pm;
  struct System_Int32_array *v13;
  s32 v15;
  f32 area;
  f32 v17;
  s32 v18;
  struct System_Int32_array *v20;
  struct System_Int32_array *v21;
  f32 v23;
  s32 v24;
  struct System_Int32_array *v26;
  u32 max_length;
  s32 v28;
  s32 v30;
  struct sdfIVector2_t_array *xy;
  u64 *v32;
  struct sdfIVector2_t_array *v34;
  s32 v35;
  s32 v36;
  struct System_Int32_array *v38;
  s32 v39;
  struct sdfIVector2_t_array *v41;
  s32 v42;
  struct System_Int32_array *v44;
  struct sdfIVector2_t_array *v46;
  u64 *v47;
  struct sdfIVector2_t_array *v49;
  struct System_Int32_array *v51;
  struct sdfIVector2_t_array *v53;
  struct System_Int32_array *v55;
  s32 v56;

  v5 = *pPart;
  v5->wait = DDS3EFFECT_RAND_I() % (pParam->interval + 1);
  (*pPart)->radiun = -3.1416;
  Blur = (*pPart)->Blur;
  Blur->abgr = pParam->abgr;
  Blur->blend = pParam->blend;
  Blur->rotate = pParam->rotate;
  v7 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v7);
  Blur->center = v7;
  v8 = NewSpecific(sdfIVector2_t, 2u);
  center = Blur->center;
  Blur->xy = v8;
  width = pParam->width;
  pm = center->pm;
  v13 = pParam->center->pm;
  v15 = v13->m_Items[0];
  area = pParam->area;
  v17 = area;
  v18 = (DDS3EFFECT_RAND_PM() * v17) + v15;
  pm->m_Items[0] = v18;
  v20 = Blur->center->pm;
  v21 = pParam->center->pm;
  v23 = v21->m_Items[1];
  v24 = (DDS3EFFECT_RAND_PM() * v17) + v23;
  v20->m_Items[1] = v24;
  v26 = Blur->center->pm;
  max_length = v26->max_length;
  v28 = v26->m_Items[0];
  v30 = Blur->center->pm->m_Items[1];
  xy = Blur->xy;
  v32 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v32);
  xy->m_Items[0] = v32;
  v34 = Blur->xy;
  v35 = width >> 1;
  v36 = v28 + 960;
  v38 = v34->m_Items[0]->pm;
  v39 = v35;
  v38->m_Items[0] = v36 - v39;
  v41 = Blur->xy;
  v42 = v30 + 540;
  v44 = v41->m_Items[0]->pm;
  v44->m_Items[1] = v42 - v39;
  v46 = Blur->xy;
  v47 = Allocate(sdfIVector2_t);
  sdfIVector2_t___ctor(v47);
  v46->m_Items[1] = v47;
  v49 = Blur->xy;
  v51 = v49->m_Items[1]->pm;
  v51->m_Items[0] = v36 + v39;
  v53 = Blur->xy;
  v55 = v53->m_Items[1]->pm;
  v56 = v42 + v39;
  v55->m_Items[1] = v56;
}

// 0x137f870
effDistortionBlurHandle_t *dds3EffectDistortionBlurCreate(dds3Effect_DistortionBlurParam_t *pParam) {
  effDistortionBlurHandle_t_o *v3;

  v3 = Allocate(effDistortionBlurHandle_t);
  effDistortionBlurHandle_t___ctor(v3);
  v3->param = pParam;
  return v3;
}

// 0x137f8e0
void dds3EffectDistortionBlurDelete(effDistortionBlurHandle_t **hDistortionBlur) {
  ;
}

// 0x137f8f0
void dds3EffectDistortionBlurDraw(effDistortionBlurHandle_t **hDistortionBlur, bool bPS2mode, s32 SkillID) {
    ChkNbEventRun();
    GetEventCamName();
    evtBitCheck(0);
    GetNowName_SCR_RUN();
    dds3FadeGetAlphaF();
    dds3FadeGetColAverageF();
}

// 0x1383dd0
void dds3EffectDistortionBlurSetParam(effDistortionBlurHandle_t **hDistortionBlur, dds3Effect_DistortionBlurParam_t *pParam) {
  u32 number;

  number = (*hDistortionBlur)->param->number;
  (*hDistortionBlur)->param = pParam;
  (*hDistortionBlur)->param->number = number;
}

// 0x1383bf0
void dds3EffectDistortionBlur_SetArea(f32 area_x, f32 area_y) {
  Postblur_distortionblur_area_x = area_x;
  Postblur_distortionblur_area_y = area_y;
}

// 0x1383c70
void dds3EffectDistortionBlur_SetFldEvent(s32 feve_UnityEx_id) {
  FldEve_UnityEx_ID = feve_UnityEx_id;
}

// 0x1383ce0
void dds3EffectDistortionBlur_SetFldEventCntF(f32 feve_UnityEx_cntF) {
  FldEve_UnityEx_CntF = feve_UnityEx_cntF;
}

// 0x1383b70
void dds3EffectDistortionBlur_SetMoya(f32 moyaalp) {
  Postblur_distortionblur_moyaalp = moyaalp;
}

// 0x1386300
void dds3EffectEncountBlur(void) {
  dds3KernelDraw_c *v2;
  struct dds3KernelDraw_StaticFields *static_fields;

  Postblur_blur_rotation = 0.0002;
  Postblur_blur_scale = 0.99;
  Postblur_blur_blend = 1;
  Postblur_blur_r = 1.0;
  Postblur_blur_g = 1.0;
  Postblur_blur_b = 1.0;
  Postblur_blur_a = 0.05;
  UpdateFlg_blur = 1;
  static_fields = v2->static_fields;
  if (static_fields->Postblur_encountblur_blend)
  {
    if ((v2->_2.bitflags2 & 2) == 0)
  }
  static_fields->Postblur_Encount1st = 1;
  Postblur_encountblur_blend = 1;
}

// 0x1386460
void dds3EffectEncountBlur1(f32 scale, f32 area) {
  Postblur_multiblur_blend = 2;
  Postblur_multiblur_rotation = 0.01;
  Postblur_multiblur_scale = 1.02;
  Postblur_multiblur_r = 1.0;
  Postblur_multiblur_g = 1.0;
  Postblur_multiblur_b = 1.0;
  Postblur_multiblur_a = 0.0078125;
  Postblur_multiblur_area = 300.0;
  Postblur_multiblur_center_x = 0.5;
  Postblur_multiblur_center_y = 0.5;
  UpdateFlg_multiblur = 1;
}

// 0x1386570
void dds3EffectEncountBlur2(void) {
  Postblur_filter_blend = 1;
  Postblur_filter_r = 0.0;
  Postblur_filter_g = 0.0;
  Postblur_filter_b = 0.0;
  Postblur_filter_a = 0.015625;
  UpdateFlg_filter = 1;
}

// 0x1386630
void dds3EffectEncountBlur3(s32 alp) {
  s32 v5;

  Postblur_blur_rotation = 0.0002;
  Postblur_blur_scale = 0.99;
  Postblur_blur_blend = 1;
  Postblur_blur_r = 1.0;
  Postblur_blur_g = 1.0;
  Postblur_blur_b = 1.0;
  Postblur_blur_a = alp * 0.0078125;
  UpdateFlg_blur = 1;
  if (alp < 113)
  {
    v5 = 0;
  }
  {
    v5 = 1;
  }
  else
  {
    v5 = 1;
  }
  Postblur_encountblur_blend = v5;
}

// 0x1384ce0
void dds3EffectFilter(dds3Effect_Filter_t **pFilter, s32 SkillID) {
    GetEventCamName();
}

// 0x137d230
dds3Effect_PartialMultiBlur_t *dds3EffectPartialMultiBlurCreate(dds3Effect_PartialMultiBlurParam_t *pParam) {
  dds3Effect_PartialMultiBlur_t_o *v3;

  v3 = Allocate(dds3Effect_PartialMultiBlur_t);
  dds3Effect_PartialMultiBlur_t___ctor(v3);
  v3->param = pParam;
  return v3;
}

// 0x137d2a0
void dds3EffectPartialMultiBlurDelete(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur) {
  ;
}

// 0x137d2b0
void dds3EffectPartialMultiBlurDraw(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur, bool bPS2mode, s32 SkillID) {
    ChkNbEventRun();
    GetEventCamName();
    evtBitCheck(0);
    effBTLSkillCheckRun2(0);
    effBTLSkillGetInvokeFormation(0);
    sdfModelGetMarkPosUnity(0, 0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    GetMainCamera(0);
}

// 0x137f350
void dds3EffectPartialMultiBlurSetParam(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur, dds3Effect_PartialMultiBlurParam_t *pParam) {
  (*hPartialMultiBlur)->param = pParam;
}

// 0x137f360
void dds3EffectPartialMultiBlurSetTex(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur, sdfTexHandle_t *hTex) {
  (*hPartialMultiBlur)->hAlphaTex = hTex;
}

// 0x137f370
void dds3EffectPartialMultiBlurSetTexDef(dds3Effect_PartialMultiBlur_t **hPartialMultiBlur) {
  dds3Effect_PartialMultiBlur_t_o *v3;

  v3 = *hPartialMultiBlur;
  v3->hAlphaTex = dds3BillboardGetGeneralTex(2);
}

// 0x1385be0
dds3Effect_PartialMultiFilter_t *dds3EffectPartialMultiFilterCreate(dds3Effect_PartialMultiFilterParam_t *pParam) {
  dds3Effect_PartialMultiFilter_t_o *v3;

  v3 = Allocate(dds3Effect_PartialMultiFilter_t);
  dds3Effect_PartialMultiFilter_t___ctor(v3);
  v3->param = pParam;
  return v3;
}

// 0x1385c50
void dds3EffectPartialMultiFilterDelete(dds3Effect_PartialMultiFilter_t *hPartialMultiFilter) {
  ;
}

// 0x1385c60
void dds3EffectPartialMultiFilterDraw(dds3Effect_PartialMultiFilter_t **hPartialMultiFilter) {
    effBTLSkillCheckRun2(0);
    effBTLSkillGetInvokeFormation(0);
    sdfModelGetMarkPosUnity(0, 0);
    effBTLModelGetSphereCenter(0);
    SDF_VU0__STOREVECTOR(0);
    GetMainCamera(0);
}

// 0x1383df0
void dds3EffectRipBlurPartAreaSet(dds3Effect_RippleBlurParam_t *pParam, dds3Effect_RipBlurPart_tag **pPart) {
  struct System_Int32_array *pm;
  u32 max_length;
  s32 v5;
  s32 v7;
  s32 v8;
  struct sdfIVector2_t_array *xy;
  struct System_Int32_array *v11;
  struct sdfIVector2_t_array *v13;
  struct System_Int32_array *v15;
  struct sdfIVector2_t_array *v17;
  struct System_Int32_array *v19;
  s32 v20;
  struct sdfIVector2_t_array *v22;
  struct System_Int32_array *v24;
  s32 v25;

  pm = pParam->center->pm;
  max_length = pm->max_length;
  v5 = pm->m_Items[0];
  v7 = pParam->center->pm->m_Items[1];
  v8 = ((*pPart)->scale * pParam->area);
  xy = (*pPart)->Blur->xy;
  v11 = xy->m_Items[0]->pm;
  v11->m_Items[0] = v5 - v8;
  v13 = (*pPart)->Blur->xy;
  v15 = v13->m_Items[0]->pm;
  v15->m_Items[1] = v7 - v8;
  v17 = (*pPart)->Blur->xy;
  v19 = v17->m_Items[1]->pm;
  v20 = v5 + v8;
  v19->m_Items[0] = v20;
  v22 = (*pPart)->Blur->xy;
  v24 = v22->m_Items[1]->pm;
  v25 = v7 + v8;
  v24->m_Items[1] = v25;
}

// 0x1383ff0
void dds3EffectRipBlurPartInit(dds3Effect_RippleBlurParam_t *pParam, dds3Effect_RipBlurPart_tag **pPart) {
  struct dds3Effect_Blur_t_o *Blur;
  struct System_Int32_array *pm;
  struct System_Int32_array *v5;
  s32 v6;
  struct System_Int32_array *v7;
  struct System_Int32_array *v8;
  s32 v10;

  (*pPart)->radiun = 0.0;
  (*pPart)->scale = 0.0;
  Blur = (*pPart)->Blur;
  Blur->abgr = pParam->abgr;
  Blur->blend = pParam->blend;
  Blur->rotate = pParam->rotate;
  pm = Blur->center->pm;
  v5 = pParam->center->pm;
  v6 = v5->m_Items[0];
  pm->m_Items[0] = v6;
  v7 = Blur->center->pm;
  v8 = pParam->center->pm;
  v10 = v8->m_Items[1];
  v7->m_Items[1] = v10;
}

// 0x1384210
effRippleBlurHandle_t *dds3EffectRippleBlurCreate(dds3Effect_RippleBlurParam_t *pParam) {
  u64 number;
  effRippleBlurHandle_t_o *v4;
  u64 i;
  u32 *pwork;
  u64 *v9;
  struct dds3Effect_RipBlurPart_tag_array *v11;
  dds3Effect_RipBlurPart_tag_o *v13;
  dds3Effect_RippleBlurParam_t_o *param;
  f32 v17;
  dds3Effect_RipBlurPart_tag_o *pPart;

  pPart = 0;
  number = pParam->number;
  v4 = Allocate(effRippleBlurHandle_t);
  effRippleBlurHandle_t___ctor(v4);
  v4->hMem = 0;
  v4->pwork = NewSpecific(dds3Effect_RipBlurPart_tag, number);
  v4->param = pParam;
  v4->hAlphaTex = dds3BillboardGetGeneralTex(3);
  if (number >= 1)
  {
    for (i = 0; i != number; ++i)
    {
      pwork = v4->pwork;
      v9 = Allocate(dds3Effect_RipBlurPart_tag);
      _ctor(v9, 0);
      *&pwork[2 * i + 8] = v9;
      v11 = v4->pwork;
      v13 = v11->m_Items[i];
      pPart = v13;
      Clear(v13, 0);
      param = v4->param;
      dds3EffectRipBlurPartInit(param, &pPart);
      v17 = -(v4->param->interval * i);
      v13->scale = v17;
    }
  }
  return v4;
}

// 0x1384400
void dds3EffectRippleBlurDelete(effRippleBlurHandle_t **hRippleBlur) {
  effRippleBlurHandle_t_o *v3;
  s32 number;
  s32 v5;
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;

  v3 = *hRippleBlur;
  if (*hRippleBlur)
  {
    number = v3->param->number;
    if (number >= 1)
    {
      v5 = 0;
      while (number - 1 != v5)
      {
        if (++v5 >= LODWORD((*hRippleBlur)->pwork->max_length))
      }
    }
  }
  MainCamera = GetMainCamera(kernelObject);
  Component_object = GetComponent_object_(MainCamera);
  if (op_Inequality(Component_object, 0, 0))
  {
    Destroy_27360000(Component_object);
  }
}

// 0x1384560
void dds3EffectRippleBlurDraw(effRippleBlurHandle_t **hRippleBlur, bool UnityCalc) {
    GetMainCamera(0);
    dds3EffectRipBlurPartInit(0, 0);
}

// 0x13840f0
void dds3EffectRippleBlurReset(effRippleBlurHandle_t **hRippleBlur) {
  effRippleBlurHandle_t_o *v4;
  s64 number;
  u64 v6;
  s64 v7;
  struct dds3Effect_RipBlurPart_tag_array *pwork;
  dds3Effect_RipBlurPart_tag_o *v10;
  dds3Effect_RippleBlurParam_t_o *param;
  dds3Effect_RipBlurPart_tag_o *pPart;

  pPart = 0;
  v4 = *hRippleBlur;
  number = (*hRippleBlur)->param->number;
  if (number >= 1)
  {
    v6 = 0;
    v7 = number - 1;
    pwork = v4->pwork;
    while (1)
    {
      v10 = pwork->m_Items[v6];
      pPart = v10;
      param = v4->param;
      dds3EffectRipBlurPartInit(param, &pPart);
      v10->scale = -((*hRippleBlur)->param->interval * v6);
      if (v7 == v6)
        break;
      v4 = *hRippleBlur;
      ++v6;
      pwork = (*hRippleBlur)->pwork;
      if (v6 >= LODWORD(pwork->max_length))
    }
  }
}

// 0x1386860
void dds3Effect_UpdateBigin(void) {
    GetDrawFlag();
    ClrDrawFlag(0);
}

// 0x1386cc0
void dds3Effect_UpdateEnd(void) {
    GetDrawFlag();
    ScreenStop1();
    DrawStopExec();
    SetDrawFlag(0, 0);
    ClrDrawFlag(0);
}

// 0x137a000
s32 dds3ScreenCaptureGetMode(void) {
  return 0;
}
