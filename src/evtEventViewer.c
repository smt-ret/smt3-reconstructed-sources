#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3Effect_Blur_t dds3Effect_Blur_t;
typedef struct dds3Effect_DistortionBlurParam_t dds3Effect_DistortionBlurParam_t;
typedef struct dds3Effect_Filter_t dds3Effect_Filter_t;
typedef struct dds3Effect_PartialMultiBlurParam_t dds3Effect_PartialMultiBlurParam_t;
typedef struct dds3Effect_PartialMultiFilterParam_t dds3Effect_PartialMultiFilterParam_t;
typedef struct dds3Effect_RippleBlurParam_t dds3Effect_RippleBlurParam_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtEventViewer_p4_func evtEventViewer_p4_func;
typedef struct evtEventViewer_p4_func_funcDelegate evtEventViewer_p4_func_funcDelegate;
typedef struct evtFrameInfo_t evtFrameInfo_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct evtViewerInfo_t evtViewerInfo_t;
typedef struct evtViewerObject_s evtViewerObject_s;
typedef struct pmdProcessWork_t pmdProcessWork_t;
typedef struct pmdSceneFogTable_t pmdSceneFogTable_t;
typedef struct pmdSceneLightTable_t pmdSceneLightTable_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfMotionCtrlr_t sdfMotionCtrlr_t;

struct evtEventViewer_p4_func {
    evtEventViewer_p4_func_funcDelegate *func;
};

static evtViewerInfo_t *viewerinfo;
static u16 evt_file_major;
static u16 evt_file_minor;
static s16 winoff_x;
static evtViewerObject_s *evt_camera;
static pmdSceneLightTable_t *RunFrame2_sl;
static pmdSceneFogTable_t *RunFrame2_sf;
static dds3Effect_Blur_t *RunFrame2_bl2;
static dds3Effect_PartialMultiBlurParam_t *RunFrame2_mbl;
static dds3Effect_Filter_t *RunFrame2_fl;
static dds3Effect_PartialMultiFilterParam_t *RunFrame2_mfl;
static dds3Effect_DistortionBlurParam_t *RunFrame2_dbl;
static dds3Effect_RippleBlurParam_t *RunFrame2_rbl;
static char *DrawActiveCameraName_freename;
static char *DrawActiveCameraName_gamename;
static s32 capwait;
static char *EnterMain_yesnomes[2];
static char *EnterFrameList_yesnomes[2];
static char *EnterFrameList_onoffmes[2];
static char *EnterFrameList_skymodemes[3];
static char *EnterFrameList_fademes[4];
static char *EnterFrameList_bgmmodemes[7];
static char *EnterFrameList_unitmodemes[5];
static evtEventViewer_p4_func *menuenter;

dds3Basic_t *AddBED(void *data, s32 cutno, s32 nameindex, s32 posindex, s32 baseframe);
s32 AddEffectTable2(s32 nowframe, evtViewerObject_s *obj, evtFrameInfo_t *f);
u32 DDS3_GETBASICTYPEL(dds3Basic_t *pAreaBasic);
bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_REP2(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void DelBED(evtFrameInfo_t *frame);
void DelEffectTable(s32 no);
void DelFrameInfo2(void);
void DelViewerObject(evtViewerObject_s *obj);
void DrawActiveCameraName(void);
void DrawEffect(void);
dds3Effect_Blur_t *Eve_BlurEditorGetParams(void);
void Eve_BlurSetParam2(dds3Effect_Blur_t *pParam);
dds3Effect_DistortionBlurParam_t *Eve_DistortionBlurEditorGetParams(void);
dds3Effect_DistortionBlurParam_t *Eve_DistortionBlurEditorGetParams2(void);
void Eve_DistortionBlurOFF(void);
void Eve_DistortionBlurON(void);
void Eve_DistortionBlurSetParam(dds3Effect_DistortionBlurParam_t *pParam);
void Eve_DistortionBlurSetParam2(dds3Effect_DistortionBlurParam_t *pParam);
dds3Effect_Filter_t *Eve_FilterEditorGetParams(void);
dds3Effect_Filter_t *Eve_FilterEditorGetParams2(void);
void Eve_FilterOFF(void);
void Eve_FilterON(void);
void Eve_FilterSetParam(dds3Effect_Filter_t *pParam);
void Eve_FilterSetParam2(dds3Effect_Filter_t *pParam);
dds3Effect_PartialMultiBlurParam_t *Eve_PartialMultiBlurEditorGetParams(void);
dds3Effect_PartialMultiBlurParam_t *Eve_PartialMultiBlurEditorGetParams2(void);
void Eve_PartialMultiBlurOFF(void);
void Eve_PartialMultiBlurON(void);
void Eve_PartialMultiBlurSetParam(dds3Effect_PartialMultiBlurParam_t *pParam);
void Eve_PartialMultiBlurSetParam2(dds3Effect_PartialMultiBlurParam_t *pParam);
dds3Effect_PartialMultiFilterParam_t *Eve_PartialMultiFilterEditorGetParams(void);
dds3Effect_PartialMultiFilterParam_t *Eve_PartialMultiFilterEditorGetParams2(void);
void Eve_PartialMultiFilterOFF(void);
void Eve_PartialMultiFilterON(void);
void Eve_PartialMultiFilterSetParam(dds3Effect_PartialMultiFilterParam_t *pParam);
void Eve_PartialMultiFilterSetParam2(dds3Effect_PartialMultiFilterParam_t *pParam);
dds3Effect_RippleBlurParam_t *Eve_RippleBlurEditorGetParams(void);
dds3Effect_RippleBlurParam_t *Eve_RippleBlurEditorGetParams2(void);
void Eve_RippleBlurOFF(void);
void Eve_RippleBlurON(void);
void Eve_RippleBlurSetParam(dds3Effect_RippleBlurParam_t *pParam);
void Eve_RippleBlurSetParam2(dds3Effect_RippleBlurParam_t *pParam);
void FrameSelect(void);
void LinkEffectBasic(dds3Basic_t *eff, s32 nameindex, s32 posindex, s32 baseframe);
void LinkViewerObject(evtViewerObject_s *obj);
void OutFrame1(evtViewerObject_s *obj, evtFrameInfo_t *frame, s32 nowframe, s32 length);
s32 PopMenu(void);
void PushMenu(s32 no, s32 x, s32 y);
void RunFrame1(evtViewerObject_s *obj, evtFrameInfo_t *frame, s32 nowframe, s32 length);
void RunFrame2(evtViewerObject_s *obj, evtFrameInfo_t *frame, evtFrameInfo_t *nearframe, s32 nowframe, s32 *l);
void RunFrame3(s32 nowframe);
void RunFrameUnit(evtViewerObject_s *obj, s32 nowframe);
f32 SDF_DEGtoRAD(f32 n);
f32 SDF_RADtoDEG(f32 n);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
dds3Basic_t *SearchBasicFromNameIndex(s32 nameindex);
s32 SearchNameTable(char *name);
void SelectActiveCamera(void);
void SetActiveCamera(void);
void SortFrameInfo(evtViewerObject_s *parent);
void UnlinkViewerObject(evtViewerObject_s *obj);
dds3Basic_t *dds3AddBEDEffectObjectBasic2(void *data, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddD3PEffectObjectBasic2(void *effdata, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddMG12EffectObjectBasic2(s32 type, void *effdata);
f32 dds3CameraObjectBasicGetFovy(dds3Basic_t **pBasic);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
void dds3EffectBlur(dds3Effect_Blur_t **pBlur, bool bPS2mode, s32 SkillID);
s32 dds3EffectObjectBasicLinkObject(dds3Basic_t **basic, dds3Basic_t **target);
s32 dds3EffectObjectBasicLinkObjectIndex(dds3Basic_t **basic, dds3Basic_t **target, s32 index);
void dds3EffectObjectBasicStatOn(dds3Basic_t **basic, u32 s);
void dds3EffectObjectPresetMG12(dds3Basic_t **eff);
s32 dds3EffectObjectSetMG12Pos(dds3Basic_t **eff, dds3Basic_t **p1, dds3Basic_t **p2, dds3Basic_t **p3, dds3Basic_t **p4);
void dds3FadeClear(void);
void dds3FadeSet(u32 r, u32 g, u32 b, u32 a);
dds3Basic_t *dds3GetActiveScene(void);
dds3ObjectBaseControlWorkData_t *dds3GetBaseControlWorkData(dds3Basic_t **pObjectBasic);
void *dds3GetProcessData(dds3ProcessID_t **id);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
s32 dds3KillProcessName(char *name, s32 shutdowntimer);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
dds3Basic_t *dds3SceneBasicSearchName(dds3Basic_t **scene, char *name);
dds3Basic_t *dds3SceneBasicSearchNameAndType(dds3Basic_t *scene, u32 type, char *name);
void dds3ScreenCaptureOff(void);
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic);
void dds3SetAmbientColor(u32 frame, sdfVector4_t col);
void dds3SetFogPara(u32 frame, f32 max, f32 min, f32 near, f32 far);
void dds3SetLightColor(u32 frame, u32 no, sdfVector4_t col);
void dds3SetLightDir(u32 frame, u32 no, sdfVector4_t dir);
void dds3SetQuake(s32 frame, u32 range);
void dds3SetScreenFovy(f32 fovy);
void dds3StartBEDEffectObjectBasic(dds3Basic_t **basic, u32 cutno);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void dds3StopQuake(void);
evtFrameInfo_t *evtAddFrameInfo(evtViewerObject_s *parent, s32 frame);
s32 evtAddNameTable(char *name);
s32 evtCheckSkyAlphaAnime(void);
void evtEffectLoopControl(dds3Basic_t *eff, s32 sw);
void evtFreePolygonMovieWorkData(pmdProcessWork_t *wdata);
void evtFreeStage(void);
void evtFreeViewerInfo(void);
evtFrameInfo_t *evtGetSelectFrameInfo(void);
evtUnitHandle_t *evtGetUnitHandle2(dds3Basic_t *unit);
void evtHokanBlur2(s32 hokan, f32 ratio, dds3Effect_Blur_t *key1, dds3Effect_Blur_t *key2, dds3Effect_Blur_t **d);
void evtHokanDistBlur(s32 hokan, f32 ratio, dds3Effect_DistortionBlurParam_t *key1, dds3Effect_DistortionBlurParam_t *key2, dds3Effect_DistortionBlurParam_t **d);
void evtHokanFilter(s32 hokan, f32 ratio, dds3Effect_Filter_t *key1, dds3Effect_Filter_t *key2, dds3Effect_Filter_t **d);
f32 evtHokanFloat(s32 hokan, f32 ratio, f32 f1, f32 f2);
void evtHokanMultBlur(s32 hokan, f32 ratio, dds3Effect_PartialMultiBlurParam_t *key1, dds3Effect_PartialMultiBlurParam_t *key2, dds3Effect_PartialMultiBlurParam_t **d);
void evtHokanMultFilter(s32 hokan, f32 ratio, dds3Effect_PartialMultiFilterParam_t *key1, dds3Effect_PartialMultiFilterParam_t *key2, dds3Effect_PartialMultiFilterParam_t **d);
void evtHokanRipBlur(s32 hokan, f32 ratio, dds3Effect_RippleBlurParam_t *key1, dds3Effect_RippleBlurParam_t *key2, dds3Effect_RippleBlurParam_t **d);
void evtHokanSceneFog(s32 hokan, f32 ratio, pmdSceneFogTable_t *key1, pmdSceneFogTable_t *key2, pmdSceneFogTable_t **d);
void evtHokanSceneLight(s32 hokan, f32 ratio, pmdSceneLightTable_t *key1, pmdSceneLightTable_t *key2, pmdSceneLightTable_t **d);
dds3ProcessID_t *evtInitFrameVar(void);
dds3ProcessID_t *evtInitSky(void);
void evtLinkLightObjectBasic(evtUnitHandle_t **h, dds3Basic_t **light, s32 frame);
s32 evtPathLinkAndMake(dds3Basic_t *path, dds3Basic_t *obj);
s32 evtPlaySe(s32 eventno, s32 seno);
void evtRunFrame(s32 nowframe);
void evtRunUnitMode_17839264(dds3Basic_t *unit, s32 mode);
void evtSetBokasi(s32 sw);
void evtSetSkyAlpha(s32 frame, s32 a);
void evtStopFrame(s32 sw, u32 nowframe);
void evtStopMover(dds3Basic_t *mover, s32 sw, s32 baseframe, s32 nowframe);
void evtUnRegistUnit(void);
void evtUnlinkLightObjectBasic(evtUnitHandle_t **h, s32 frame);
s32 evtViewerLoadGameData(s32 type);
s32 evtViewerMenuRun(s32 type, s32 x, s32 y);
s32 evtViewerSaveGameData(s32 type);
void evtViewerStopFrame(void);
s32 fldSkyGetAlpha(void);
void fldSkySetFilter(s32 idx, s32 mode, s32 hokan);
void mdlUnRegist(s32 aMajor, s32 aMinor);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);
void sdfMotionPause(sdfMotionCtrlr_t *aCtrlr);
void sdfMotionPauseOff(sdfMotionCtrlr_t *aCtrlr);
void sdfMotionSeek(sdfMotionCtrlr_t *aCtrlr, f32 aFrame);

// 0x136b1d0
dds3Basic_t *AddBED(void *data, s32 cutno, s32 nameindex, s32 posindex, s32 baseframe) {
  dds3Basic_t_o *v13;
  UnityEngine_Vector4_o v15;
  UnityEngine_Vector4_o v16;
  dds3Basic_t_o *basic;

  *&v16.x = 0;
  *&v16.z = 0;
  *&v15.x = 0;
  *&v15.z = 0;
  sub_854690(&v16.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v15.x, 0.0, 0.0, 0.0, 1.0);
  basic = dds3AddBEDEffectObjectBasic2(data, v16, v15);
  dds3EffectObjectBasicStatOn(&basic, 1u);
  dds3StartBEDEffectObjectBasic(&basic, cutno);
  v13 = basic;
  LinkEffectBasic(v13, nameindex, posindex, baseframe);
  return basic;
}

// 0x136ad40
s32 AddEffectTable2(s32 nowframe, evtViewerObject_s *obj, evtFrameInfo_t *f) {
  u64 v7;
  struct dds3Basic_t_array *efftable;
  s32 v11;
  s32 type;
  u64 *v14;
  struct pmdDataInfo_t_array *data;
  struct pmdDataInfo_t_array *v19;
  dds3Basic_t_o *v20;
  s16 i_high;
  u64 *v22;
  s32 v23;
  s32 v25;
  s32 frame;
  struct pmdDataInfo_t_array *v28;
  s32 i_low;
  struct pmdDataInfo_t_array *v32;
  struct pmdDataInfo_t_array *v35;
  struct pmdDataInfo_t_array *v38;
  struct pmdDataInfo_t_array *v40;
  struct dds3Basic_t_array *v42;
  dds3Basic_t_o *v43;
  s64 v47;
  dds3Basic_t_o *p4;
  dds3Basic_t_o *p3;
  dds3Basic_t_o *p2;
  dds3Basic_t_o *p1;
  dds3Basic_t_o *eff;
  UnityEngine_Vector4_o v53;
  UnityEngine_Vector4_o v54;

  *&v54.x = 0;
  *&v54.z = 0;
  *&v53.x = 0;
  *&v53.z = 0;
  p2 = 0;
  p1 = 0;
  p4 = 0;
  p3 = 0;
  sub_854690(&v54.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v53.x, 0.0, 0.0, 0.0, 1.0);
  eff = 0;
  v7 = 0;
  while (1)
  {
    efftable = viewerinfo->efftable;
    if (!efftable->m_Items[v7])
      break;
    v11 = v7 + 1;
    if (v7++ > 0x7D)
    {
      LODWORD(v7) = v11;
      break;
    }
  }
  if (v7 == 127)
  {
    LODWORD(v7) = -1;
    return v7;
  }
  type = obj->type;
  if (type == 3)
  {
    v47 = *&obj->data.c0;
    v14 = sub_8D3950(IntPtr, &v47);
    eff = dds3AddD3PEffectObjectBasic2(v14, v54, v53);
    data = f->data;
    if (LOBYTE(data->m_Items[0].i))
      dds3EffectObjectPresetMG12(&eff);
    v19 = f->data;
    v20 = eff;
    i_high = HIWORD(v19->m_Items[0].i);
    v25 = SBYTE1(v19->m_Items[0].i);
    frame = f->frame;
    LinkEffectBasic(v20, i_high, v25, frame);
      goto LABEL_52;
    goto LABEL_50;
  }
  if ((type & 0xFFFFFFFE) == 0x14)
  {
    if (type == 21)
    {
      v47 = *&obj->data.c0;
      v22 = sub_8D3950(IntPtr, &v47);
      v23 = 2;
    }
    else
    {
      if (type != 20)
      {
LABEL_34:
        v28 = f->data;
        i_low = SLOBYTE(v28->m_Items[0].i);
        p1 = SearchBasicFromNameIndex(i_low);
        v32 = f->data;
        p2 = SearchBasicFromNameIndex(SBYTE1(v32->m_Items[0].i));
        v35 = f->data;
        p3 = SearchBasicFromNameIndex(SBYTE2(v35->m_Items[0].i));
        v38 = f->data;
        p4 = SearchBasicFromNameIndex(SHIBYTE(v38->m_Items[0].i));
        dds3EffectObjectSetMG12Pos(&eff, &p1, &p2, &p3, &p4);
        v40 = f->data;
        if (v40->m_Items[0].c1)
          dds3EffectObjectPresetMG12(&eff);
        goto LABEL_49;
      }
      v47 = *&obj->data.c0;
      v22 = sub_8D3950(IntPtr, &v47);
      v23 = 1;
    }
    eff = dds3AddMG12EffectObjectBasic2(v23, v22);
    goto LABEL_34;
  }
LABEL_49:
  {
LABEL_50:
  }
LABEL_52:
  v42 = viewerinfo->efftable;
  v43 = eff;
  v42->m_Items[v7] = v43;
  if (eff)
    dds3EffectObjectBasicStatOn(&eff, 1u);
  return v7;
}

// 0x13696a0
evtFrameInfo_t *AddFrameInfo2(evtViewerObject_s *parent, s32 frame) {
  return evtAddFrameInfo(parent, frame);
}

// 0x1368690
void DelBED(evtFrameInfo_t *frame) {
  s64 *v3;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3Basic_t_o *v8;
  u64 v9[3];

  v8 = 0;
  v3 = *&frame->work.i;
  if (v3)
  {
    v4 = *v3;
    if (*(*v3 + 288) < typeHierarchyDepth
      || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != dds3Basic_t)
    {
      sub_8FC2C0(*(v4 + 64), dds3Basic_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
    v8 = *&frame->work.i;
    dds3DeleteSceneBasicData(&v8);
  }
  *&frame->work.i = 0;
}

// 0x1368530
void DelEffectTable(s32 no) {
  struct dds3Basic_t_array *efftable;
  struct dds3Basic_t_array *v7;
  struct dds3Basic_t_array *v9;

  efftable = viewerinfo->efftable;
  if (efftable->m_Items[no])
  {
    v7 = viewerinfo->efftable;
    else if (LODWORD(v7->max_length) <= no)
    {
      goto LABEL_15;
    }
    dds3DeleteSceneBasicData(&v7->m_Items[no]);
    v9 = viewerinfo->efftable;
    v9->m_Items[no] = 0;
  }
}

// 0x1369810
void DelFrameInfo(evtViewerObject_s *parent, evtFrameInfo_t *f) {
  Il2CppObject *p;
  struct System_Object_array **p_p;
  intptr_t v7;
  s32 *p_framecnt;

  p = f->p;
  if (p)
    p_p = &p[3];
  else
    p_p = &parent->p;
  *p_p = f->work.p;
  v7 = f->work.p;
  if (v7)
    p_framecnt = (v7 + 56);
  else
    p_framecnt = &parent->framecnt;
  *p_framecnt = f->p;
  f->work.p = 0;
  f->p = 0;
  --LODWORD(parent->data.p);
  if (*&f->work.i)
  {
    if (parent->type != 18)
      *&f->work.i = 0;
    *&f->work.i = 0;
  }
}

// 0x13698e0
void DelFrameInfo2(void) {
  s64 v3;
  evtFrameInfo_t_o *SelectFrameInfo;
  s32 v6;
  evtFrameInfo_t_o *v7;
  struct pmdDataInfo_t_array *data;
  struct pmdDataInfo_t_array *v11;
  s32 c0;
  Il2CppObject *p;
  intptr_t *v15;
  intptr_t v16;
  Il2CppObject **v17;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 framelist_y;
  s32 v22;

  v3 = *(v2[2].klass->_1.image + 37);
  SelectFrameInfo = evtGetSelectFrameInfo();
  v6 = *(v3 + 16);
  v7 = SelectFrameInfo;
  if (v6 == 3)
    goto LABEL_14;
  if (v6 == 18)
  {
    DelBED(v7);
      goto LABEL_25;
    goto LABEL_24;
  }
  if ((v6 & 0xFFFFFFFE) == 0x14)
  {
LABEL_14:
    data = SelectFrameInfo->data;
    if ((data->m_Items[0].c0 & 0x80000000) == 0)
    {
      v11 = SelectFrameInfo->data;
      c0 = v11->m_Items[0].c0;
      DelEffectTable(c0);
    }
  }
    goto LABEL_25;
LABEL_24:
LABEL_25:
LABEL_27:
  p = v7->p;
  if (p)
    v15 = &p[3];
  else
    v15 = (v3 + 64);
  *v15 = v7->work.p;
  v16 = v7->work.p;
  if (v16)
    v17 = (v16 + 56);
  else
    v17 = (v3 + 72);
  *v17 = v7->p;
  v7->work.p = 0;
  v7->p = 0;
  --*(v3 + 56);
  if (*&v7->work.i)
  {
    if (*(v3 + 16) != 18)
      *&v7->work.i = 0;
    *&v7->work.i = 0;
  }
  if (viewerinfo->framelist_base)
  {
    else
    {
      framelist_y = viewerinfo->framelist_y;
      if (framelist_y >= 1)
      {
LABEL_44:
        viewerinfo->framelist_y = framelist_y - 1;
        return;
      }
    }
    --viewerinfo->framelist_base;
  }
  else
  {
    v22 = viewerinfo->framelist_y;
    if (v22 >= 1)
    {
      viewerinfo->framelist_y = v22 - 1;
    }
  }
}

// 0x136a0e0
void DelViewerObject(evtViewerObject_s *obj) {
  struct System_Object_array *p;
  Il2CppObject *v6;
  struct System_Object_array **p_p;
  Il2CppObject *v8;
  s32 *p_monitor;

  p = obj->p;
  if (p)
  {
    {
      if ((byte_3F59514 & 1) == 0)
        goto LABEL_10;
LABEL_11:
      v6 = p->m_Items[3];
      if (v6)
        p_p = &v6[3];
      else
        p_p = &obj->p;
      *p_p = p->m_Items[2];
      v8 = p->m_Items[2];
      if (v8)
        p_monitor = &v8[3].monitor;
      else
        p_monitor = &obj->framecnt;
      *p_monitor = p->m_Items[3];
      p->m_Items[2] = 0;
      p->m_Items[3] = 0;
      --LODWORD(obj->data.p);
      if (p->m_Items[1])
      {
        if (obj->type != 18)
          p->m_Items[1] = 0;
        p->m_Items[1] = 0;
      }
      p = obj->p;
      if (!p)
        goto LABEL_25;
    }
    if ((byte_3F59514 & 1) != 0)
      goto LABEL_11;
LABEL_10:
    goto LABEL_11;
  }
LABEL_25:
  UnlinkViewerObject(obj);
}

// 0x136e6e0
void DrawActiveCameraName(void) {
  s16 v3;
  s32 v4;
  struct evtViewerInfo_t_o *viewerinfo;
  struct dds3Basic_t_o *activecamera;
  s64 **p_name;
  s64 *v9;
  u64 *v10;
  u64 *v11;
  u64 *v13;
  Il2CppObject *v16;
  struct sdfGrOt_t_array *dds3Ot;

  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
    activecamera = viewerinfo->activecamera;
    if (activecamera)
    {
LABEL_5:
      else if (activecamera->name)
      {
        goto LABEL_8;
      }
      p_name = &DrawActiveCameraName_freename;
      goto LABEL_27;
    }
  }
  else
  {
    v4 = 0;
    activecamera = viewerinfo->activecamera;
    if (activecamera)
      goto LABEL_5;
  }
  else if (!viewerinfo->gamecamera)
  {
    return;
  }
  p_name = &DrawActiveCameraName_gamename;
LABEL_27:
  v9 = *p_name;
  v10 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v10);
  v11 = NewSpecific(object, 1u);
  v13 = v11;
  v13[4] = v9;
  v16 = sdfDevPrintf(34432, 31168, 0xFEFFFFu, 5, "%s", v13);
  sdfDrawTagLink(v10, v16);
  sdfDrawTagLinkOt(dds3Ot->m_Items[83], v10);
}

// 0x136b300
void DrawEffect(void) {
  dds3Effect_Blur_t_o *pBlur;

  pBlur = 0;
  if (viewerinfo->drawblur2)
  {
    pBlur = Eve_BlurEditorGetParams();
    dds3EffectBlur(&pBlur, 0, 0);
  }
  if (viewerinfo->drawmblur)
  {
    Eve_PartialMultiBlurON();
    {
LABEL_22:
    }
  }
  else
  {
    Eve_PartialMultiBlurOFF();
      goto LABEL_22;
  }
  if (viewerinfo->drawmfilter)
  {
    Eve_PartialMultiFilterON();
    {
LABEL_33:
    }
  }
  else
  {
    Eve_PartialMultiFilterOFF();
      goto LABEL_33;
  }
  if (viewerinfo->drawdblur)
  {
    Eve_DistortionBlurON();
    {
LABEL_44:
    }
  }
  else
  {
    Eve_DistortionBlurOFF();
      goto LABEL_44;
  }
  if (viewerinfo->drawrblur)
  {
    Eve_RippleBlurON();
    {
LABEL_55:
    }
  }
  else
  {
    Eve_RippleBlurOFF();
      goto LABEL_55;
  }
  if (viewerinfo->drawfilter)
  {
    Eve_FilterON();
  }
  else
  {
    Eve_FilterOFF();
  }
}

// 0x1372fb0
s32 EnterBasicList(s32 s, s32 prevmenu) {
  u64 *v3;
  evtFrameInfo_t_o *SelectFrameInfo;
  evtUnitHandle_t_o *UnitHandle2;

  v3 = Allocate(evtUnitHandle_t);
  _ctor(v3, 0);
  UnitHandle2 = v3;
  SelectFrameInfo = evtGetSelectFrameInfo(evtEventViewer);
  if (SelectFrameInfo)
    goto LABEL_6;
  return 0;
}

// 0x1373830
s32 EnterData(s32 s, s32 prevmenu) {
  evtFrameInfo_t_o *SelectFrameInfo;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 framelist_type;
  UnityEngine_Vector4_o *v8;
  s64 v9;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  struct sdf3DLight_t_array *dds3DirLights;
  struct sdf3DLight_t_array *v16;
  u32 *v19;
  s64 v20;
  s64 v21;
  char *v22;
  s64 *v23;
  void *Params;
  struct pmdDataInfo_t_array *data;
  struct pmdDataInfo_t_array *v31;
  u64 v33[2];
  char *v34;

  SelectFrameInfo = evtGetSelectFrameInfo();
  switch (viewerinfo->framelist_target->type)
  {
    case 0xA:
      framelist_type = viewerinfo->framelist_type;
      if (framelist_type == 14)
      {
        data = SelectFrameInfo->data;
        *&data->m_Items[0].c0 = sdfFaceDivSoften;
        v31 = SelectFrameInfo->data;
        v31->m_Items[0].i = LODWORD(sdfFaceDivBias);
          goto LABEL_66;
      }
      else
      {
        if (framelist_type != 13)
          break;
        v8 = *&SelectFrameInfo->work.i;
        if (v8)
        {
          v9 = *&v8->x;
          if (*(*&v8->x + 288LL) < typeHierarchyDepth
            || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != pmdSceneLightTable_t)
          {
            sub_8FC2C0(*(v9 + 64), pmdSceneLightTable_t, v33);
            if ((v33[0] & 1) != 0)
              v11 = v34;
            else
              v11 = v33 + 1;
            v12 = sub_8C4940(v11);
          }
        }
        SDF_VU0__COPYVECTOR(v8 + 1, dds3DirLights->m_Items[0]->color);
        v16 = dds3DirLights;
        SDF_VU0__COPYVECTOR(v8 + 2, v16->m_Items[0]->v);
        SDF_VU0__COPYVECTOR(v8 + 3, dds3Ambient);
          goto LABEL_66;
      }
      goto LABEL_68;
    case 0xB:
      v19 = *&SelectFrameInfo->work.i;
      if (v19)
      {
        v20 = *v19;
        if (*(*v19 + 288LL) < v21 || *(*(v20 + 200) + 8 * v21 - 8) != pmdSceneFogTable_t)
        {
          sub_8FC2C0(*(v20 + 64), pmdSceneFogTable_t, v33);
          if ((v33[0] & 1) != 0)
            v22 = v34;
          else
            v22 = v33 + 1;
          v23 = sub_8C4940(v22);
        }
      }
      v19[4] = LODWORD(dds3FogParam->fogMin);
      v19[5] = LODWORD(dds3FogParam->fogMax);
      v19[6] = LODWORD(dds3FogParam->fogNear);
      v19[7] = LODWORD(dds3FogParam->fogFar);
      v19[8] = dds3FogParam->color;
        goto LABEL_66;
      goto LABEL_68;
    case 0xD:
      Params = Eve_BlurEditorGetParams();
      goto LABEL_64;
    case 0xE:
      Params = Eve_PartialMultiBlurEditorGetParams2();
      goto LABEL_64;
    case 0xF:
      Params = Eve_DistortionBlurEditorGetParams2();
      goto LABEL_64;
    case 0x10:
      Params = Eve_FilterEditorGetParams2();
      goto LABEL_64;
    case 0x11:
      Params = Eve_PartialMultiFilterEditorGetParams2();
      goto LABEL_64;
    case 0x17:
      Params = Eve_RippleBlurEditorGetParams2();
LABEL_64:
      *&SelectFrameInfo->work.i = Params;
      break;
    default:
      break;
  }
  {
LABEL_66:
  }
LABEL_68:
  evtRunFrame(viewerinfo->nowframe);
  PopMenu();
  return 0;
}

// 0x1373780
s32 EnterEventPos(s32 s, s32 prevmenu) {
  if (evtGetSelectFrameInfo())
  {
    viewerinfo->work_base = 0;
    viewerinfo->work_y = 0;
    PushMenu(10, 156, 84);
  }
  return 0;
}

// 0x1372e00
s32 EnterFilename2(s32 s, s32 prevmenu) {
  struct evtViewerInfo_t_o *viewerinfo;
  u64 *v6;
  u64 *v7;
  s32 mainmenu_y;
  s32 v11;
  u16 v13[2];
  u16 evt_file_major;

  if (viewerinfo->mainmenu_y > 2u)
    return 0;
  v6 = sub_8D3950(ushort, &evt_file_major);
  v13[0] = evt_file_minor;
  v7 = sub_8D3950(ushort, v13);
  viewerinfo->gamedata_filename = Format_5268592("E{0, 3:D}_{1:D3}", v6, v7, 0);
  mainmenu_y = viewerinfo->mainmenu_y;
  if (mainmenu_y)
  {
    else if (mainmenu_y == 1)
    {
LABEL_14:
      v11 = 0;
LABEL_23:
      evtViewerLoadGameData(v11);
      return -1;
    }
    if (mainmenu_y != 2)
      return -1;
    v11 = 1;
    goto LABEL_23;
  }
  evtViewerSaveGameData(0);
  evtViewerSaveGameData(1);
  return -1;
}

// 0x13726c0
s32 EnterFrameChange(s32 s, s32 prevmenu) {
  evtFrameInfo_t_o *SelectFrameInfo;
  evtFrameInfo_t_o *v6;
  struct evtFrameList_t_array *evtFrameList;
  struct evtViewerInfo_t_o *viewerinfo;
  s64 type;
  s64 v14;
  s64 framelist_x;
  s64 v16;
  s32 v18;
  u64 v21;
  struct evtViewerInfo_t_o *v24;
  s32 v25;
  struct pmdDataInfo_t_array *data;
  struct pmdDataInfo_t_array *v28;

  SelectFrameInfo = evtGetSelectFrameInfo();
  if (SelectFrameInfo)
  {
    v6 = SelectFrameInfo;
    type = viewerinfo->framelist_target->type;
    v14 = evtFrameList + 8 * type;
    framelist_x = viewerinfo->framelist_x;
    v16 = *(*(v14 + 32) + 24LL);
    v18 = *(v16 + framelist_x + 32);
    if (v18 == 15)
    {
      v6->length = viewerinfo->value;
        goto LABEL_52;
    }
    else
    {
      if (v18 == 9)
      {
        v24 = viewerinfo;
        v25 = v24->framelist_target->type;
        if (v25 == 3)
          goto LABEL_43;
        if (v25 == 18)
        {
          data = v6->data;
          *&data->m_Items[0].c0 = v24->value;
            goto LABEL_52;
          goto LABEL_50;
        }
        if ((v25 & 0xFFFFFFFE) == 0x14)
        {
LABEL_43:
          v28 = v6->data;
          *&v28->m_Items[0].c2 = v24->value;
        }
      }
      else if (!*(v16 + framelist_x + 32))
      {
        v6->frame = viewerinfo->value;
        SortFrameInfo(viewerinfo->framelist_target);
        evtRunFrame(viewerinfo->nowframe);
          goto LABEL_52;
        goto LABEL_50;
      }
      {
LABEL_52:
        PopMenu(v21);
        return 0;
      }
    }
LABEL_50:
    goto LABEL_52;
  }
  return 0;
}

// 0x1370c10
s32 EnterFrameList(s32 s, s32 prevmenu) {
  struct evtEventViewer_StaticFields **p_static_fields;
  struct evtViewerInfo_t_o *viewerinfo;
  struct evtViewerObject_s_o *framelist_target;
  struct evtEventViewer_StaticFields *v9;
  struct evtViewerInfo_t_o *v10;
  struct System_String_array *EnterFrameList_yesnomes;
  s32 v12;
  s32 v13;
  s32 nowframe;
  struct evtViewerInfo_t_o *v18;
  const char *name;
  s64 type;
  const char *v22;
  s64 framelist_x;
  s64 v24;
  evtFrameInfo_t_o *SelectFrameInfo;
  struct evtEventViewer_StaticFields **v29;
  struct evtViewerInfo_t_o *v30;
  s32 frame;
  s32 v32;
  struct pmdDataInfo_t_array *v33;
  char *p_i;
  struct pmdDataInfo_t_array *v36;
  f32 v39;
  struct pmdDataInfo_t_array *v40;
  s32 v42;
  struct pmdDataInfo_t_array *v43;
  s32 v45;
  struct pmdDataInfo_t_array *v46;
  s32 v48;
  struct pmdDataInfo_t_array *v49;
  s32 v52;
  struct pmdDataInfo_t_array *v53;
  struct pmdDataInfo_t_array *v55;
  struct evtViewerInfo_t_o *v57;
  s32 v58;
  s32 v59;
  struct pmdDataInfo_t_array *v60;
  s32 v62;
  pmdDataInfo_t_o *p_c2;
  struct pmdDataInfo_t_array *v64;
  u32 v66;
  struct pmdDataInfo_t_array *v67;
  s32 i_low;
  struct evtViewerInfo_t_o *v70;
  s64 *v71;
  struct pmdDataInfo_t_array *v72;
  f32 v74;
  s32 v76;
  struct pmdDataInfo_t_array *v77;
  struct pmdDataInfo_t_array *v79;
  s32 v81;
  struct pmdDataInfo_t_array *v82;
  struct pmdDataInfo_t_array *v84;
  struct pmdDataInfo_t_array *v87;
  s32 i;
  struct pmdDataInfo_t_array *v90;
  struct pmdDataInfo_t_array *v93;
  struct pmdDataInfo_t_array *v95;
  struct pmdDataInfo_t_array *v97;
  struct pmdDataInfo_t_array *v100;
  struct pmdDataInfo_t_array *v103;
  struct pmdDataInfo_t_array *v105;
  struct pmdDataInfo_t_array *v107;
  struct pmdDataInfo_t_array *v109;
  dds3Effect_Blur_t_o *v111;
  dds3Effect_Blur_t_c *klass;
  s64 v113;
  char *v114;
  s64 *v115;
  dds3Effect_Filter_t_o *v118;
  dds3Effect_Filter_t_c *v119;
  s64 v120;
  char *v121;
  s64 *v122;
  struct evtViewerInfo_t_o *v125;
  u64 *v126;
  u64 *data;
  s64 *v129;
  UnityEngine_Vector4_o *v130;
  s64 v131;
  s64 typeHierarchyDepth;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  f32 *v140;
  s64 v141;
  s64 v142;
  f32 v143;
  f32 v144;
  f32 v145;
  f32 v146;
  dds3Effect_PartialMultiFilterParam_t_o *v150;
  dds3Effect_PartialMultiFilterParam_t_c *v151;
  s64 v152;
  char *v153;
  s64 *v154;
  dds3Effect_RippleBlurParam_t_o *v158;
  dds3Effect_RippleBlurParam_t_c *v159;
  s64 v160;
  char *v161;
  s64 *v162;
  dds3Effect_PartialMultiBlurParam_t_o *v165;
  dds3Effect_PartialMultiBlurParam_t_c *v166;
  s64 v167;
  char *v168;
  s64 *v169;
  dds3Effect_DistortionBlurParam_t_o *v172;
  dds3Effect_DistortionBlurParam_t_c *v173;
  s64 v174;
  char *v175;
  s64 *v176;
  char *v179;
  s64 *v180;
  char *v181;
  s64 *v182;
  char v183[16];
  char *v184;
  UnityEngine_Vector4_o v185;

  framelist_target = viewerinfo->framelist_target;
  if (viewerinfo->framelist_y + viewerinfo->framelist_base < SLODWORD(framelist_target->data.p))
  {
    if (s == -2)
    {
      viewerinfo->framelist_type = -1;
      (*p_static_fields)->viewerinfo->select_y = 0;
      (*p_static_fields)->viewerinfo->select_max = 2;
      (*p_static_fields)->viewerinfo->select_header = "DELETE FRAME.OK? ";
      v9 = *p_static_fields;
      v10 = v9->viewerinfo;
      EnterFrameList_yesnomes = v9->EnterFrameList_yesnomes;
LABEL_12:
      v10->select_str = EnterFrameList_yesnomes;
      v12 = 216;
      v13 = 2;
LABEL_13:
      PushMenu(v13, v12, 120);
      return 0;
    }
    else
    {
      v18 = viewerinfo;
    }
    name = v17[2].klass->_1.name;
    type = v18->framelist_target->type;
    v22 = &name[8 * type];
    framelist_x = v18->framelist_x;
    v24 = *(*(v22 + 4) + 24LL);
    viewerinfo->framelist_type = *(v24 + framelist_x + 32);
    SelectFrameInfo = evtGetSelectFrameInfo();
    v30 = viewerinfo;
    switch (v30->framelist_type)
    {
      case 0:
        frame = SelectFrameInfo->frame;
        goto LABEL_246;
      case 1:
        v30->value = SelectFrameInfo->length;
        (*v29)->viewerinfo->min = 0;
        v57 = (*v29)->viewerinfo;
        v58 = 10000;
        goto LABEL_285;
      case 2:
        if (v30->framelist_target->type != 7)
          return 0;
        v55 = SelectFrameInfo->data;
        v30->value = *&v55->m_Items[0].c0;
        viewerinfo->min = 0;
        v57 = viewerinfo;
        v58 = 3000;
        goto LABEL_285;
      case 3:
        v59 = v30->framelist_target->type;
        if (v59 == 12)
        {
          v93 = SelectFrameInfo->data;
          p_c2 = &v93->m_Items[0].c2;
          v62 = -255;
        }
        else
        {
          if (v59 != 8)
            goto LABEL_236;
          v60 = SelectFrameInfo->data;
          v62 = 0;
          p_c2 = v60->m_Items;
        }
        v30->value = *&p_c2->c0;
        viewerinfo->min = v62;
        viewerinfo->max = 255;
LABEL_236:
        goto LABEL_286;
      case 4:
        v46 = SelectFrameInfo->data;
        v30->value = *&v46->m_Items[0].c2;
        viewerinfo->min = -255;
        goto LABEL_284;
      case 5:
        v66 = v30->framelist_target->type;
        if (v66 > 0x17)
          goto LABEL_149;
        if (((1 << v66) & 0x83E800) != 0)
        {
          v67 = SelectFrameInfo->data;
          i_low = *&v67->m_Items[0].c0;
        }
        else if (v66 == 8)
        {
          v109 = SelectFrameInfo->data;
          i_low = SLOWORD(v109->m_Items[0].i);
        }
        else
        {
          if (v66 != 10)
          {
LABEL_149:
            viewerinfo->select_max = 2;
            v70 = viewerinfo;
            v71 = &"HOKAN MODE   ";
LABEL_228:
            v70->select_header = *v71;
            v10 = viewerinfo;
            EnterFrameList_yesnomes = EnterFrameList_onoffmes;
            goto LABEL_12;
          }
          i_low = SelectFrameInfo->nameindex;
        }
        v30->select_y = i_low;
        goto LABEL_149;
      case 6:
        v72 = SelectFrameInfo->data;
        v74 = *&v72->m_Items[0].c0;
        v30->fvalue = SDF_RADtoDEG(v74);
        viewerinfo->fmin = 1.0;
        viewerinfo->fmax = 180.0;
        v12 = 180;
        v13 = 8;
        goto LABEL_13;
      case 7:
        v64 = SelectFrameInfo->data;
        v30->value = *&v64->m_Items[0].c2;
        viewerinfo->min = 0;
        goto LABEL_132;
      case 8:
        v76 = v30->framelist_target->type;
        if (v76 <= 5)
        {
          if (v76 == 3)
          {
            v103 = SelectFrameInfo->data;
            v30->value = SBYTE1(v103->m_Items[0].i);
            viewerinfo->min = -1;
LABEL_132:
            v57 = viewerinfo;
            v58 = 127;
            goto LABEL_285;
          }
          if (v76 != 5)
            return 0;
          v87 = SelectFrameInfo->data;
          i = *&v87->m_Items[0].c0;
        }
        else
        {
          if (v76 != 12)
          {
            if (v76 != 18)
            {
              if (v76 != 19)
                return 0;
              v77 = SelectFrameInfo->data;
              v30->value = *&v77->m_Items[0].c2;
              v79 = SelectFrameInfo->data;
              if (*&v79->m_Items[0].c0 == 3)
              {
                {
                }
                v81 = -1;
              }
              else
              {
                {
                }
                v81 = 0;
              }
              viewerinfo->min = v81;
              goto LABEL_284;
            }
            v105 = SelectFrameInfo->data;
            v30->value = SLOBYTE(v105->m_Items[0].i);
            viewerinfo->min = 0;
            v57 = viewerinfo;
            v58 = 2;
LABEL_285:
            v57->max = v58;
LABEL_286:
            v12 = 180;
            v13 = 7;
            goto LABEL_13;
          }
          v107 = SelectFrameInfo->data;
          i = v107->m_Items[0].i;
        }
        v30->value = i;
        viewerinfo->min = 0;
LABEL_284:
        v57 = viewerinfo;
        v58 = 255;
        goto LABEL_285;
      case 9:
        v52 = v30->framelist_target->type;
        if (v52 == 3)
          goto LABEL_240;
        if (v52 == 18)
        {
          v53 = SelectFrameInfo->data;
          frame = *&v53->m_Items[0].c0;
        }
        else
        {
          if ((v52 & 0xFFFFFFFE) != 0x14)
            return 0;
LABEL_240:
          v95 = SelectFrameInfo->data;
          frame = *&v95->m_Items[0].c2;
        }
LABEL_246:
        v30->value = frame;
        v12 = 180;
        v13 = 6;
        goto LABEL_13;
      case 0xA:
        v30->work_base = 0;
        (*v29)->viewerinfo->work_y = 0;
        PushMenu(10, 156, 84);
        return 0;
      case 0xB:
        v42 = v30->framelist_target->type;
        if (v42 == 22)
        {
          v90 = SelectFrameInfo->data;
          v45 = *&v90->m_Items[0].c0;
        }
        else
        {
          if (v42 != 9)
            return 0;
          v43 = SelectFrameInfo->data;
          v45 = *&v43->m_Items[0].c2;
        }
        v30->select_y = v45;
        goto LABEL_227;
      case 0xC:
        v48 = v30->framelist_target->type;
        if (v48 <= 6)
        {
          if (v48 == 1)
          {
            v100 = SelectFrameInfo->data;
            v30->select_y = v100->m_Items[0].c0;
            viewerinfo->select_max = 5;
            viewerinfo->select_header = "UNIT CONTROL TYPE ";
            v10 = viewerinfo;
            EnterFrameList_yesnomes = EnterFrameList_unitmodemes;
          }
          else
          {
            if (v48 != 6)
              return 0;
            v84 = SelectFrameInfo->data;
            v30->select_y = *&v84->m_Items[0].c0;
            viewerinfo->select_max = 4;
            viewerinfo->select_header = "FADE TYPE  ";
            v10 = viewerinfo;
            EnterFrameList_yesnomes = EnterFrameList_fademes;
          }
        }
        else if (v48 == 19)
        {
          v97 = SelectFrameInfo->data;
          v30->select_y = *&v97->m_Items[0].c0;
          viewerinfo->select_max = 7;
          viewerinfo->select_header = "CONTROL TYPE ";
          v10 = viewerinfo;
          EnterFrameList_yesnomes = EnterFrameList_bgmmodemes;
        }
        else
        {
          if (v48 != 12)
            return 0;
          v49 = SelectFrameInfo->data;
          v30->select_y = *&v49->m_Items[0].c0;
          viewerinfo->select_max = 3;
          viewerinfo->select_header = "TRANS MODE ";
          v10 = viewerinfo;
          EnterFrameList_yesnomes = EnterFrameList_skymodemes;
        }
        goto LABEL_12;
      case 0xD:
        switch (v30->framelist_target->type)
        {
          case 0xA:
            v130 = *&SelectFrameInfo->work.i;
            v131 = *&v130->x;
            if (*(*&v130->x + 288LL) < typeHierarchyDepth
              || *(*(v131 + 200) + 8 * typeHierarchyDepth - 8) != pmdSceneLightTable_t)
            {
              sub_8FC2C0(*(v131 + 64), pmdSceneLightTable_t, v183);
              if ((v183[0] & 1) != 0)
                v179 = v184;
              else
                v179 = &v183[1];
              v180 = sub_8C4940(v179);
            }
            x = v130[1].x;
            y = v130[1].y;
            z = v130[1].z;
            w = v130[1].w;
            v185.x = x;
            v185.y = y;
            v185.z = z;
            v185.w = w;
            dds3SetLightColor(0, 0, v185);
            dds3SetLightDir(0, 0, v130[2]);
            dds3SetAmbientColor(0, v130[3]);
            v125 = viewerinfo;
            v126 = Allocate(System_Func_dds3ProcessID_t__object_);
            object____ctor(
              v126,
              0,
              Method_mdlDebugLight_dds3LightEditorProcess__);
            *v183 = 1;
            data = sub_8D3950(s32, v183);
            v129 = &"slight";
            goto LABEL_365;
          case 0xB:
            v140 = *&SelectFrameInfo->work.i;
            v141 = *v140;
            if (*(*v140 + 288LL) < v142 || *(*(v141 + 200) + 8 * v142 - 8) != pmdSceneFogTable_t)
            {
              sub_8FC2C0(*(v141 + 64), pmdSceneFogTable_t, v183);
              if ((v183[0] & 1) != 0)
                v181 = v184;
              else
                v181 = &v183[1];
              v182 = sub_8C4940(v181);
            }
            v143 = v140[4];
            v144 = v140[5];
            v146 = v140[6];
            v145 = v140[7];
            dds3SetFogPara(0, v144, v143, v146, v145);
            dds3FogParam->color = v140[8];
            v125 = viewerinfo;
            v126 = Allocate(System_Func_dds3ProcessID_t__object_);
            object____ctor(
              v126,
              0,
              Method_mdlDebugFog_dds3FogEditorProcess__);
            *v183 = 1;
            data = sub_8D3950(s32, v183);
            v129 = &"sfog";
            goto LABEL_365;
          case 0xD:
            v111 = *&SelectFrameInfo->work.i;
            if (v111)
            {
              klass = v111->klass;
              if (v111->klass->_2.typeHierarchyDepth < v113
                || klass->_2.typeHierarchy[v113 - 1] != dds3Effect_Blur_t)
              {
                sub_8FC2C0(klass->_1.element_class, dds3Effect_Blur_t, v183);
                if ((v183[0] & 1) != 0)
                  v114 = v184;
                else
                  v114 = &v183[1];
                v115 = sub_8C4940(v114);
              }
            }
            Eve_BlurSetParam2(v111);
            viewerinfo->drawblur2 = 0;
            goto LABEL_366;
          case 0xE:
            v165 = *&SelectFrameInfo->work.i;
            if (v165)
            {
              v166 = v165->klass;
              if (v165->klass->_2.typeHierarchyDepth < v167
                || v166->_2.typeHierarchy[v167 - 1] != dds3Effect_PartialMultiBlurParam_t)
              {
                sub_8FC2C0(v166->_1.element_class, dds3Effect_PartialMultiBlurParam_t, v183);
                if ((v183[0] & 1) != 0)
                  v168 = v184;
                else
                  v168 = &v183[1];
                v169 = sub_8C4940(v168);
              }
            }
            Eve_PartialMultiBlurSetParam2(v165);
            viewerinfo->drawmblur = 0;
            goto LABEL_366;
          case 0xF:
            v172 = *&SelectFrameInfo->work.i;
            if (v172)
            {
              v173 = v172->klass;
              if (v172->klass->_2.typeHierarchyDepth < v174
                || v173->_2.typeHierarchy[v174 - 1] != dds3Effect_DistortionBlurParam_t)
              {
                sub_8FC2C0(v173->_1.element_class, dds3Effect_DistortionBlurParam_t, v183);
                if ((v183[0] & 1) != 0)
                  v175 = v184;
                else
                  v175 = &v183[1];
                v176 = sub_8C4940(v175);
              }
            }
            Eve_DistortionBlurSetParam2(v172);
            viewerinfo->drawdblur = 0;
            goto LABEL_366;
          case 0x10:
            v118 = *&SelectFrameInfo->work.i;
            if (v118)
            {
              v119 = v118->klass;
              if (v118->klass->_2.typeHierarchyDepth < v120
                || v119->_2.typeHierarchy[v120 - 1] != dds3Effect_Filter_t)
              {
                sub_8FC2C0(v119->_1.element_class, dds3Effect_Filter_t, v183);
                if ((v183[0] & 1) != 0)
                  v121 = v184;
                else
                  v121 = &v183[1];
                v122 = sub_8C4940(v121);
              }
            }
            Eve_FilterSetParam2(v118);
            viewerinfo->drawfilter = 0;
            v125 = viewerinfo;
            v126 = Allocate(System_Func_dds3ProcessID_t__object_);
            object____ctor(
              v126,
              0,
              Method_evtEventViewerMenu_evtFilterEditorProcess__);
            *v183 = 1;
            data = sub_8D3950(s32, v183);
            v129 = &"filter";
            goto LABEL_365;
          case 0x11:
            v150 = *&SelectFrameInfo->work.i;
            if (v150)
            {
              v151 = v150->klass;
              if (v150->klass->_2.typeHierarchyDepth < v152
                || v151->_2.typeHierarchy[v152 - 1] != dds3Effect_PartialMultiFilterParam_t)
              {
                sub_8FC2C0(v151->_1.element_class, dds3Effect_PartialMultiFilterParam_t, v183);
                if ((v183[0] & 1) != 0)
                  v153 = v184;
                else
                  v153 = &v183[1];
                v154 = sub_8C4940(v153);
              }
            }
            Eve_PartialMultiFilterSetParam2(v150);
            viewerinfo->drawmfilter = 0;
            v125 = viewerinfo;
            v126 = Allocate(System_Func_dds3ProcessID_t__object_);
            object____ctor(
              v126,
              0,
              Method_evtEventViewerMenu_evtMultiFilterEditorProcess__);
            *v183 = 1;
            data = sub_8D3950(s32, v183);
            v129 = &"mfilter";
LABEL_365:
            v125->pid = dds3StartProcess(*v129, 0x2AF9u, 1, 1, v126, 0, 0, 0, data, 0);
            goto LABEL_366;
          case 0x14:
          case 0x15:
            v30->eventpos_y = 0;
            PushMenu(12, 120, 84);
            return 0;
          case 0x17:
            v158 = *&SelectFrameInfo->work.i;
            if (v158)
            {
              v159 = v158->klass;
              if (v158->klass->_2.typeHierarchyDepth < v160
                || v159->_2.typeHierarchy[v160 - 1] != dds3Effect_RippleBlurParam_t)
              {
                sub_8FC2C0(v159->_1.element_class, dds3Effect_RippleBlurParam_t, v183);
                if ((v183[0] & 1) != 0)
                  v161 = v184;
                else
                  v161 = &v183[1];
                v162 = sub_8C4940(v161);
              }
            }
            Eve_RippleBlurSetParam2(v158);
            viewerinfo->drawrblur = 0;
            goto LABEL_366;
          default:
            return 0;
        }
      case 0xE:
        v36 = SelectFrameInfo->data;
        v39 = *&v36->m_Items[0].c0;
        sdfFaceDivSoften = v39;
        v40 = SelectFrameInfo->data;
        LODWORD(sdfFaceDivBias) = v40->m_Items[0].i;
LABEL_366:
        PushMenu(11, 0, 0);
        return 0;
      case 0xF:
        frame = SelectFrameInfo->length;
        goto LABEL_246;
      case 0x10:
        v32 = v30->framelist_target->type;
        if (v32 == 3)
        {
          v33 = SelectFrameInfo->data;
          p_i = &v33->m_Items[0].i;
        }
        else
        {
          if ((v32 & 0xFFFFFFFE) != 0x14)
            goto LABEL_201;
          v82 = SelectFrameInfo->data;
          p_i = &v82->m_Items[0].c1;
        }
        v30->select_y = *p_i;
LABEL_201:
LABEL_227:
        viewerinfo->select_max = 2;
        v70 = viewerinfo;
        v71 = &"ON/OFF MODE ";
        goto LABEL_228;
      default:
        return 0;
    }
  }
  if (s == 1)
  {
    nowframe = viewerinfo->nowframe;
    evtAddFrameInfo(framelist_target, nowframe);
  }
  return 0;
}

// 0x13729a0
s32 EnterIntFloatChange(s32 s, s32 prevmenu) {
  u64 v3;
  struct evtViewerInfo_t_o *viewerinfo;
  f32 fvalue;
  s32 value;
  evtFrameInfo_t_o *SelectFrameInfo;
  evtFrameInfo_t_o *v9;
  struct evtFrameList_t_array *evtFrameList;
  struct evtViewerInfo_t_o *v14;
  s64 type;
  s64 v17;
  s64 framelist_x;
  s64 v19;
  struct pmdDataInfo_t_array *v21;
  struct pmdDataInfo_t_array *data;
  f32 v25;
  struct pmdDataInfo_t_array *v28;
  s32 v31;
  s32 v33;
  struct pmdDataInfo_t_array *v34;
  struct pmdDataInfo_t_array *v36;
  struct pmdDataInfo_t_array *v38;

  viewerinfo = **(v3 + 184);
  fvalue = viewerinfo->fvalue;
  value = viewerinfo->value;
  if (!viewerinfo->menusw)
  {
    if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
    {
      if (viewerinfo->mainmenu_y == 5)
      {
LABEL_10:
        viewerinfo->totalframe = value + 1;
        goto LABEL_82;
      }
    }
    else if (viewerinfo->mainmenu_y == 5)
    {
      goto LABEL_10;
    }
  }
  SelectFrameInfo = evtGetSelectFrameInfo(v3);
  if (SelectFrameInfo)
  {
    v9 = SelectFrameInfo;
    v14 = viewerinfo;
    type = v14->framelist_target->type;
    v17 = evtFrameList + 8 * type;
    framelist_x = v14->framelist_x;
    v19 = *(*(v17 + 32) + 24LL);
    switch (*(v19 + framelist_x + 32))
    {
      case 1:
        v9->length = value;
          goto LABEL_33;
        goto LABEL_81;
      case 2:
        if (viewerinfo->framelist_target->type != 7)
          goto LABEL_80;
        goto LABEL_48;
      case 3:
        v31 = viewerinfo->framelist_target->type;
        if (v31 == 12)
          goto LABEL_30;
        if (v31 != 8)
          goto LABEL_80;
        goto LABEL_48;
      case 4:
      case 7:
        goto LABEL_30;
      case 6:
        data = v9->data;
        v25 = SDF_DEGtoRAD(fvalue);
        *&data->m_Items[0].c0 = v25;
          goto LABEL_81;
        goto LABEL_33;
      case 8:
        v33 = viewerinfo->framelist_target->type;
        if (v33 <= 5)
        {
          if (v33 == 3)
          {
            v34 = v9->data;
            BYTE1(v34->m_Items[0].i) = value;
              goto LABEL_33;
            goto LABEL_81;
          }
          if (v33 == 5)
          {
LABEL_48:
            v28 = v9->data;
            *&v28->m_Items[0].c0 = value;
              goto LABEL_33;
            goto LABEL_81;
          }
        }
        else
        {
          if (v33 != 12)
          {
            if (v33 == 18)
            {
              v36 = v9->data;
              LOBYTE(v36->m_Items[0].i) = value;
                goto LABEL_33;
            }
            else
            {
              if (v33 != 19)
                goto LABEL_80;
LABEL_30:
              v21 = v9->data;
              *&v21->m_Items[0].c2 = value;
              {
LABEL_33:
              }
            }
LABEL_81:
            evtRunFrame(viewerinfo->nowframe);
LABEL_82:
            PopMenu(v3);
            return 0;
          }
          v38 = v9->data;
          v38->m_Items[0].i = value;
        }
LABEL_80:
          goto LABEL_81;
        goto LABEL_33;
      default:
        goto LABEL_80;
    }
  }
  return 0;
}

// 0x1370220
s32 EnterMain(s32 s, s32 prevmenu) {
  u64 v4;
  struct evtEventViewer_StaticFields **p_static_fields;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 v7;
  s32 v8;
  s32 v9;
  s32 result;

  p_static_fields = (v4 + 184);
  viewerinfo = **(v4 + 184);
  switch (viewerinfo->mainmenu_y)
  {
    case 0:
    case 1:
    case 2:
      viewerinfo->filename_x = 0;
      v7 = 9;
      v8 = 228;
      (*p_static_fields)->viewerinfo->filename_y = 0;
      goto LABEL_15;
    case 3:
    case 4:
      viewerinfo->select_y = 0;
      (*p_static_fields)->viewerinfo->select_max = 2;
      (*p_static_fields)->viewerinfo->select_header = "FRAME SET.OK? ";
      (*p_static_fields)->viewerinfo->select_str = (*p_static_fields)->EnterMain_yesnomes;
      v8 = 228;
      v7 = 2;
LABEL_15:
      v9 = 60;
      goto LABEL_16;
    case 5:
      viewerinfo->value = viewerinfo->totalframe - 1;
      (*p_static_fields)->viewerinfo->min = (*p_static_fields)->viewerinfo->lastframe;
      (*p_static_fields)->viewerinfo->max = 10000;
      v8 = 180;
      v7 = 7;
      v9 = 120;
LABEL_16:
      PushMenu(v7, v8, v9);
      result = 0;
      break;
    case 6:
      viewerinfo->stat |= 1u;
      (*p_static_fields)->viewerinfo->nowframe = (*p_static_fields)->viewerinfo->firstframe;
      evtViewerStopFrame(v4);
      viewerinfo->nowmenu = 0;
      viewerinfo->sp = 0;
      viewerinfo->menusw = 0;
      capwait = 0;
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// 0x1370ba0
s32 EnterObjList(s32 s, s32 prevmenu) {
  PushMenu(5, 144, 72);
  return 0;
}

// 0x1370450
s32 EnterSelect(s32 s, s32 prevmenu) {
  u64 v4;
  struct evtViewerInfo_t_o *v5;
  s32 mainmenu_y;
  s16 v7;
  s32 v8;
  evtFrameInfo_t_o *SelectFrameInfo;
  u64 v12;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 framelist_type;
  s32 v15;
  struct pmdDataInfo_t_array *v16;
  u32 v19;
  s16 v20;
  struct evtViewerInfo_t_o *v22;
  s32 firstframe;
  s32 type;
  struct pmdDataInfo_t_array *data;
  s32 v28;
  struct pmdDataInfo_t_array *v29;
  struct evtViewerInfo_t_o *v32;
  s32 lastframe;
  struct pmdDataInfo_t_array *v34;
  struct pmdDataInfo_t_array *v36;
  struct pmdDataInfo_t_array *v38;
  struct pmdDataInfo_t_array *v40;

  if (prevmenu == 5)
  {
    SelectFrameInfo = evtGetSelectFrameInfo();
    framelist_type = viewerinfo->framelist_type;
    if (framelist_type > 5)
    {
      if (framelist_type == 11)
      {
        type = viewerinfo->framelist_target->type;
        if (type != 22)
        {
          if (type == 9)
          {
            data = SelectFrameInfo->data;
            *&data->m_Items[0].c2 = viewerinfo->select_y;
              goto LABEL_151;
            goto LABEL_134;
          }
          goto LABEL_150;
        }
      }
      else
      {
        if (framelist_type != 12)
        {
          if (framelist_type == 16)
          {
            v15 = viewerinfo->framelist_target->type;
            if (v15 == 3)
            {
              v16 = SelectFrameInfo->data;
              LOBYTE(v16->m_Items[0].i) = viewerinfo->select_y;
                goto LABEL_151;
              goto LABEL_134;
            }
            if ((v15 & 0xFFFFFFFE) == 0x14)
            {
              v34 = SelectFrameInfo->data;
              v34->m_Items[0].c1 = viewerinfo->select_y;
                goto LABEL_151;
              goto LABEL_134;
            }
          }
          goto LABEL_150;
        }
        v28 = viewerinfo->framelist_target->type;
        if (v28 <= 6)
        {
          if (v28 == 1)
          {
            v38 = SelectFrameInfo->data;
            v38->m_Items[0].c0 = viewerinfo->select_y;
              goto LABEL_151;
            goto LABEL_134;
          }
          if (v28 != 6)
            goto LABEL_150;
        }
        else if (v28 != 19)
        {
          if (v28 == 12)
          {
            v29 = SelectFrameInfo->data;
            *&v29->m_Items[0].c0 = viewerinfo->select_y;
            *(**(v12 + 184) + 156LL) = 0;
              goto LABEL_151;
            goto LABEL_134;
          }
          goto LABEL_150;
        }
      }
LABEL_128:
      v36 = SelectFrameInfo->data;
      *&v36->m_Items[0].c0 = viewerinfo->select_y;
        goto LABEL_151;
      goto LABEL_134;
    }
    if (framelist_type == -1)
    {
      if (!viewerinfo->select_y)
      {
        DelFrameInfo2(v12);
          goto LABEL_151;
        goto LABEL_134;
      }
    }
    else if (framelist_type == 5)
    {
      v19 = viewerinfo->framelist_target->type;
      if (v19 <= 0x17)
      {
        if (((1 << v19) & 0x83E800) == 0)
        {
          if (v19 == 8)
          {
            v40 = SelectFrameInfo->data;
            LOWORD(v40->m_Items[0].i) = viewerinfo->select_y;
          }
          else if (v19 == 10)
          {
            SelectFrameInfo->nameindex = viewerinfo->select_y;
              goto LABEL_151;
            goto LABEL_134;
          }
          goto LABEL_150;
        }
        goto LABEL_128;
      }
    }
LABEL_150:
    {
LABEL_151:
      evtRunFrame(viewerinfo->nowframe);
LABEL_152:
      PopMenu(v4);
      return 0;
    }
LABEL_134:
    goto LABEL_151;
  }
  if (prevmenu != 1)
    return 0;
  v5 = **(v4 + 184);
  mainmenu_y = v5->mainmenu_y;
  if (mainmenu_y != 4)
  {
    if (mainmenu_y == 3)
    {
      v7 = *(v4 + 294);
      if ((v7 & 0x200) != 0)
      {
        if (!*(v4 + 216))
        {
          v5 = viewerinfo;
        }
        v8 = v7 & 0x200;
        if (!v5->select_y)
          goto LABEL_51;
      }
      else
      {
        v8 = 0;
        if (!v5->select_y)
        {
LABEL_51:
          viewerinfo->firstframe = viewerinfo->nowframe;
          v22 = viewerinfo;
          firstframe = v22->firstframe;
          if (firstframe <= v22->lastframe)
            return -1;
          v22->lastframe = firstframe;
          return -1;
        }
      }
      goto LABEL_76;
    }
    return 0;
  }
  v20 = *(v4 + 294);
  if ((v20 & 0x200) != 0)
  {
    if (!*(v4 + 216))
    {
      v5 = viewerinfo;
    }
    v8 = v20 & 0x200;
    if (!v5->select_y)
      goto LABEL_104;
LABEL_76:
    goto LABEL_152;
  }
  v8 = 0;
  if (v5->select_y)
    goto LABEL_76;
LABEL_104:
  viewerinfo->lastframe = viewerinfo->nowframe;
  v32 = viewerinfo;
  lastframe = v32->lastframe;
  if (lastframe >= v32->firstframe)
    return -1;
  v32->firstframe = lastframe;
  return -1;
}

// 0x136f760
void FrameSelect(void) {
  s32 v4;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 nowframe;
  s32 firstframe;
  u64 v16;
  struct evtViewerInfo_t_o *v17;
  struct evtViewerInfo_t_o *v18;
  s32 totalframe;

  if (!DDS3_PADCHECK_REP2(4))
    goto LABEL_17;
LABEL_6:
  if (viewerinfo->nowframe <= 0)
    v4 = 0;
  else
    v4 = -1;
    goto LABEL_18;
LABEL_13:
    goto LABEL_18;
  if (!DDS3_PADCHECK_REP2(5))
    goto LABEL_24;
LABEL_19:
  if (viewerinfo->nowframe < viewerinfo->totalframe - 1)
    v4 = 1;
LABEL_24:
  if (DDS3_PADCHECK_REP2(6))
    v4 = -10;
  if (DDS3_PADCHECK_REP2(7))
    v4 = 10;
  else if (!DDS3_PADCHECK_TRIG(13))
  {
    goto LABEL_47;
  }
  nowframe = viewerinfo->nowframe;
  firstframe = viewerinfo->firstframe;
  if (nowframe == firstframe)
  {
LABEL_47:
    if (!v4)
      return;
LABEL_48:
    *(**(v16 + 184) + 52LL) += v4;
    v17 = **(v16 + 184);
    if (v17->nowframe < 0)
    {
      if ((*(v16 + 295) & 2) != 0 && !*(v16 + 216))
      {
        v17 = viewerinfo;
      }
      v17->nowframe = 0;
      if ((*(v16 + 295) & 2) == 0)
        goto LABEL_60;
    }
    else if ((*(v16 + 295) & 2) == 0)
    {
LABEL_60:
      v18 = **(v16 + 184);
      totalframe = v18->totalframe;
      if (v18->nowframe >= totalframe)
      {
        if ((*(v16 + 295) & 2) != 0 && !*(v16 + 216))
        {
          v18 = viewerinfo;
          totalframe = v18->totalframe;
        }
        v18->nowframe = totalframe - 1;
      }
      evtViewerStopFrame(v16);
      return;
    }
    goto LABEL_60;
  }
  v4 = firstframe - nowframe;
  if (firstframe != nowframe)
    goto LABEL_48;
}

// 0x136a9f0
void LinkEffectBasic(dds3Basic_t *eff, s32 nameindex, s32 posindex, s32 baseframe) {
  s32 nowframe;
  struct pmdNameTable_t_array *nametable;
  System_String_o *Name;
  dds3Basic_t_o *v16;
  dds3Basic_t_o *v18;
  u32 v19;
  dds3Basic_t_o *v21;
  dds3Basic_t_o *v22;
  struct dds3Basic_t_array *pBasic;
  dds3Basic_t_o *v25;
  u64 *v26;
  u64 *v28;
  dds3Basic_t_o *v31;
  s32 v32;
  s32 v33;
  s32 v34;
  dds3Basic_t_o *scene;
  dds3Basic_t_o *target;
  dds3Basic_t_o *basic;

  basic = eff;
  scene = 0;
  target = 0;
  if (eff)
  {
    if ((nameindex & 0x80000000) == 0)
    {
      nowframe = viewerinfo->nowframe;
      scene = dds3GetActiveScene();
      nametable = viewerinfo->nametable;
      Name = nametable->m_Items[nameindex]->Name;
      v16 = dds3SceneBasicSearchName(&scene, Name);
      target = v16;
      if (v16)
      {
        v18 = v16;
        v19 = DDS3_GETBASICTYPEL(v18);
        if (v19 <= 0x11)
        {
          if (((1 << v19) & 0x203D0) != 0)
          {
LABEL_25:
            dds3EffectObjectBasicLinkObject(&basic, &target);
            return;
          }
          if (v19 == 5)
          {
            if ((posindex & 0x80000000) == 0)
            {
              dds3EffectObjectBasicLinkObjectIndex(&basic, &target, posindex);
              return;
            }
            goto LABEL_25;
          }
          if (v19 == 16)
          {
            v21 = target;
            v22 = basic;
            evtPathLinkAndMake(v21, v22);
            pBasic = dds3GetBaseControlWorkData(&basic)->pBasic;
            v25 = pBasic->m_Items[1];
            v34 = baseframe;
            v26 = sub_8D3950(s32, &v34);
            v33 = nowframe;
            v28 = sub_8D3950(s32, &v33);
            Write_2930752("エフェクトぱすリンク!! -> ({0:D}, {1:D})\n", v26, v28, 0);
            if ((viewerinfo->stat & 1) != 0)
            {
              {
              }
              v31 = v25;
              v32 = 0;
            }
            else
            {
              {
              }
              v31 = v25;
              v32 = 1;
            }
            evtStopMover(v31, v32, baseframe, nowframe);
          }
        }
      }
    }
  }
}

// 0x13687b0
void LinkFrameInfo(evtViewerObject_s *parent, evtFrameInfo_t *f) {
  struct System_Object_array *p;
  Il2CppObject *v4;
  Il2CppObject *v5;
  Il2CppObject *v6;

  p = parent->p;
  if (p)
  {
    while (f->frame >= LOWORD(p->bounds))
    {
      p = p->m_Items[2];
      if (!p)
      {
        *(*&parent->framecnt + 48LL) = f;
        v4 = *&parent->framecnt;
        f->work.p = 0;
        f->p = v4;
        *&parent->framecnt = f;
        ++LODWORD(parent->data.p);
        return;
      }
    }
    v5 = p->m_Items[3];
    if (v5)
    {
      v5[3].klass = f;
      v6 = p->m_Items[3];
      f->work.p = p;
      f->p = v6;
      p->m_Items[3] = f;
    }
    else
    {
      parent->p = f;
      p->m_Items[3] = f;
      f->work.p = p;
      f->p = 0;
    }
    ++LODWORD(parent->data.p);
  }
  else
  {
    parent->p = f;
    *&parent->framecnt = f;
    f->work.p = 0;
    f->p = 0;
    ++LODWORD(parent->data.p);
  }
}

// 0x1369c00
void LinkViewerObject(evtViewerObject_s *obj) {
  evtEventViewer_c *v3;
  struct evtViewerInfo_t_o *viewerinfo;
  struct evtViewerObject_s_o *firstobjinfo;
  struct evtFrameInfo_t_o *lastobjinfo;
  struct evtFrameInfo_t_o *lastframeinfo;
  struct evtFrameInfo_t_o *v8;

  firstobjinfo = viewerinfo->firstobjinfo;
  if (!firstobjinfo)
    goto LABEL_18;
LABEL_6:
  while (obj->type >= firstobjinfo->type)
  {
    firstobjinfo = firstobjinfo->firstframeinfo;
    if (!firstobjinfo)
    {
      viewerinfo->lastobjinfo->firstframeinfo = obj;
      lastobjinfo = viewerinfo->lastobjinfo;
      obj->firstframeinfo = 0;
      obj->lastframeinfo = lastobjinfo;
      viewerinfo->lastobjinfo = obj;
      if ((v3->_2.bitflags2 & 2) == 0)
        goto LABEL_27;
      goto LABEL_12;
    }
  }
  lastframeinfo = firstobjinfo->lastframeinfo;
  if (lastframeinfo)
  {
    lastframeinfo[1].klass = obj;
    v8 = firstobjinfo->lastframeinfo;
    obj->firstframeinfo = firstobjinfo;
    obj->lastframeinfo = v8;
    firstobjinfo->lastframeinfo = obj;
    if ((v3->_2.bitflags2 & 2) != 0)
      goto LABEL_12;
  }
  else
  {
    viewerinfo->firstobjinfo = obj;
    firstobjinfo->lastframeinfo = obj;
    obj->firstframeinfo = firstobjinfo;
    obj->lastframeinfo = 0;
    if ((v3->_2.bitflags2 & 2) != 0)
      goto LABEL_12;
  }
LABEL_27:
  ++viewerinfo->objcnt;
}

// 0x136be80
void OutFrame1(evtViewerObject_s *obj, evtFrameInfo_t *frame, s32 nowframe, s32 length) {
  s32 type;
  struct pmdDataInfo_t_array *data;
  struct pmdDataInfo_t_array *v10;
  s32 c0;
  struct pmdDataInfo_t_array *v13;

  type = obj->type;
  if (type != 3)
  {
    if (type == 18)
    {
      DelBED(frame, frame);
      return;
    }
    if ((type & 0xFFFFFFFE) != 0x14)
      return;
  }
  data = frame->data;
  if ((data->m_Items[0].c0 & 0x80000000) == 0)
  {
    v10 = frame->data;
    c0 = v10->m_Items[0].c0;
    DelEffectTable(c0, frame);
    v13 = frame->data;
    v13->m_Items[0].c0 = -1;
  }
}

// 0x136fc90
s32 PopMenu(void) {
  s16 v3;
  s32 v4;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 sp;
  struct evtViewerInfo_t_o *v7;
  struct menuinfo_t_array *menustack;
  s64 v9;

  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
    sp = viewerinfo->sp;
    if (sp)
      goto LABEL_5;
  }
  else
  {
    v4 = 0;
    sp = viewerinfo->sp;
    if (sp)
    {
LABEL_5:
      viewerinfo->sp = sp - 1;
      v7 = viewerinfo;
      menustack = v7->menustack;
      v9 = v7->sp;
      v7->nowmenu = menustack->m_Items[v9]->menu;
      return viewerinfo->nowmenu;
    }
  }
  viewerinfo->nowmenu = 0;
  return 0;
}

// 0x136fac0
void PushMenu(s32 no, s32 x, s32 y) {
  u16 v4;
  u16 v5;
  struct evtViewerInfo_t_o *viewerinfo;
  struct menuinfo_t_array *menustack;
  s64 sp;
  struct evtViewerInfo_t_o *v12;
  struct menuinfo_t_array *v13;
  s64 v14;
  struct evtViewerInfo_t_o *v16;
  struct menuinfo_t_array *v17;
  s64 v18;
  struct System_Char_array *filename;

  v4 = y;
  v5 = x;
  ++viewerinfo->sp;
  menustack = viewerinfo->menustack;
  sp = viewerinfo->sp;
  menustack->m_Items[sp]->menu = no;
  v12 = viewerinfo;
  v13 = v12->menustack;
  v14 = v12->sp;
  v13->m_Items[v14]->x = v5;
  v16 = viewerinfo;
  v17 = v16->menustack;
  v18 = v16->sp;
  v17->m_Items[v18]->y = v4;
  viewerinfo->nowmenu = no;
  if (no == 3)
  {
    viewerinfo->filename_x = 0;
    viewerinfo->filename_y = 0;
    filename = viewerinfo->filename;
    filename->m_Items[0] = 0;
    viewerinfo->fileext = "";
  }
}

// 0x136b7f0
void RunFrame1(evtViewerObject_s *obj, evtFrameInfo_t *frame, s32 nowframe, s32 length) {
  struct pmdDataInfo_t_array *data;
  struct pmdDataInfo_t_array *v9;
  struct pmdDataInfo_t_array *v12;
  struct dds3Basic_t_array *efftable;
  s64 c0;
  dds3Basic_t_o *v17;
  struct pmdDataInfo_t_array *v19;
  struct pmdDataInfo_t_array *v21;
  s32 v24;
  struct pmdDataInfo_t_array *v25;
  u32 v27;
  u64 *v28;
  struct pmdDataInfo_t_array *v30;
  struct pmdDataInfo_t_array *v32;
  s32 v34;
  s32 v35;
  struct pmdDataInfo_t_array *v37;
  struct pmdDataInfo_t_array *v39;
  s8 v40;
  struct pmdDataInfo_t_array *v43;
  struct dds3Basic_t_array *v44;
  s64 v46;
  struct pmdDataInfo_t_array *v48;
  s32 i_low;
  struct pmdDataInfo_t_array *v52;
  struct pmdDataInfo_t_array *v55;
  struct pmdDataInfo_t_array *v58;
  s32 v61;
  struct pmdDataInfo_t_array *v62;
  s8 v63;
  s64 v66;
  dds3Basic_t_o *p4;
  dds3Basic_t_o *p3;
  dds3Basic_t_o *p2;
  dds3Basic_t_o *p1;
  dds3Basic_t_o *eff;

  p1 = 0;
  eff = 0;
  p4 = 0;
  p3 = 0;
  p2 = 0;
  switch (obj->type)
  {
    case 3:
    case 0x14:
    case 0x15:
      if (frame->frame > nowframe)
        goto LABEL_7;
      data = frame->data;
      if (data->m_Items[0].c0 < 0)
      {
        v62 = frame->data;
        v63 = AddEffectTable2(v61, obj, frame, *&length);
        v62->m_Items[0].c0 = v63;
        v9 = frame->data;
        if (!LODWORD(v9->max_length))
        {
LABEL_8:
        }
      }
      else
      {
LABEL_7:
        v9 = frame->data;
        if (!LODWORD(v9->max_length))
          goto LABEL_8;
      }
      if (v9->m_Items[0].c0 < 0)
        return;
      v12 = frame->data;
      efftable = viewerinfo->efftable;
      c0 = v12->m_Items[0].c0;
      v17 = efftable->m_Items[c0];
      eff = v17;
      if (!v17)
        return;
      if (frame->length && frame->length <= nowframe)
      {
        evtEffectLoopControl(v17, 0);
        *&frame->work.c0 = 1;
        if (obj->type != 21)
          return;
LABEL_64:
        v43 = frame->data;
        v44 = viewerinfo->efftable;
        v46 = v43->m_Items[0].c0;
        eff = v44->m_Items[v46];
        if (eff)
        {
          v48 = frame->data;
          i_low = SLOBYTE(v48->m_Items[0].i);
          p1 = SearchBasicFromNameIndex(i_low, frame);
          v52 = frame->data;
          p2 = SearchBasicFromNameIndex(SBYTE1(v52->m_Items[0].i));
          v55 = frame->data;
          p3 = SearchBasicFromNameIndex(SBYTE2(v55->m_Items[0].i));
          v58 = frame->data;
          p4 = SearchBasicFromNameIndex(SHIBYTE(v58->m_Items[0].i));
          dds3EffectObjectSetMG12Pos(&eff, &p1, &p2, &p3, &p4);
        }
        return;
      }
      if (*&frame->work.c0 == 1)
      {
        v32 = frame->data;
        v34 = v32->m_Items[0].c0;
        DelEffectTable(v34, frame);
        v37 = frame->data;
        v37->m_Items[0].c0 = -1;
        v39 = frame->data;
        v40 = AddEffectTable2(v35, obj, frame);
        v39->m_Items[0].c0 = v40;
        *&frame->work.c0 = 0;
      }
      if (obj->type == 21)
        goto LABEL_64;
      return;
    case 5:
      v19 = frame->data;
      evtPlaySe(evt_file_major, *&v19->m_Items[0].c0);
      return;
    case 7:
      if (frame->length)
        goto LABEL_35;
      v21 = frame->data;
      if (*&v21->m_Items[0].c0)
      {
LABEL_35:
        if (frame->frame == nowframe)
        {
          viewerinfo->stat |= 2u;
          v24 = frame->length;
          v25 = frame->data;
          v27 = *&v25->m_Items[0].c0;
          dds3SetQuake(v24, v27);
        }
      }
      else
      {
        viewerinfo->stat &= ~2u;
        dds3StopQuake();
      }
      return;
    case 0x12:
      if (frame->frame == nowframe)
      {
        DelBED(frame, frame);
        v66 = *&obj->data.c0;
        v28 = sub_8D3950(IntPtr, &v66);
        v30 = frame->data;
        *&frame->work.i = AddBED(
                                          v28,
                                          SLOBYTE(v30->m_Items[0].i),
                                          *&frame->data->m_Items[0].c2,
                                          -1,
                                          frame->frame);
      }
      return;
    default:
      return;
  }
}

// 0x136bfb0
void RunFrame2(evtViewerObject_s *obj, evtFrameInfo_t *frame, evtFrameInfo_t *nearframe, s32 nowframe, s32 *l) {
  evtFrameInfo_t_o *v9;
  evtEventViewer_c *v11;
  s32 firstframe;
  s32 v13;
  f32 v14;
  u32 v15;
  s32 v16;
  u32 length;
  f32 v19;
  s32 v20;
  struct pmdDataInfo_t_array *data;
  u32 v23;
  u32 v24;
  struct pmdDataInfo_t_array *v25;
  intptr_t p;
  struct pmdDataInfo_t_array *v28;
  s32 v29;
  s32 v31;
  s32 v32;
  s32 v33;
  s64 v34;
  struct pmdDataInfo_t_array *v36;
  struct pmdDataInfo_t_array *v37;
  s32 v39;
  f32 v41;
  f32 v42;
  pmdSceneLightTable_t_o *v43;
  pmdSceneLightTable_t_c *klass;
  s64 typeHierarchyDepth;
  char *v46;
  s64 *v47;
  struct pmdDataInfo_t_array *v48;
  u32 max_length;
  f32 v51;
  s32 i;
  s32 nameindex;
  pmdSceneLightTable_t_o *v55;
  pmdSceneLightTable_t_c *v56;
  s64 v57;
  char *v58;
  s64 *v59;
  struct pmdDataInfo_t_array *v60;
  u32 v61;
  pmdSceneFogTable_t_o *v64;
  pmdSceneFogTable_t_c *v65;
  s64 v66;
  char *v67;
  s64 *v68;
  struct pmdDataInfo_t_array *v69;
  s32 v71;
  evtFrameInfo_t_c *v72;
  s64 v73;
  char *v74;
  s64 *v75;
  struct pmdDataInfo_t_array *v76;
  s32 Alpha;
  struct pmdDataInfo_t_array *v81;
  s32 v83;
  struct pmdDataInfo_t_array *v84;
  s32 v86;
  dds3Effect_Blur_t_o *v87;
  dds3Effect_Blur_t_c *v88;
  s64 v89;
  char *v90;
  s64 *v91;
  struct pmdDataInfo_t_array *v92;
  s32 v94;
  evtFrameInfo_t_c *v95;
  s64 v96;
  char *v97;
  s64 *v98;
  dds3Effect_PartialMultiBlurParam_t_o *v99;
  dds3Effect_PartialMultiBlurParam_t_c *v100;
  s64 v101;
  char *v102;
  s64 *v103;
  struct pmdDataInfo_t_array *v104;
  s32 v106;
  evtFrameInfo_t_c *v107;
  s64 v108;
  char *v109;
  s64 *v110;
  dds3Effect_DistortionBlurParam_t_o *v111;
  dds3Effect_DistortionBlurParam_t_c *v112;
  s64 v113;
  char *v114;
  s64 *v115;
  struct pmdDataInfo_t_array *v116;
  s32 v118;
  evtFrameInfo_t_c *v119;
  s64 v120;
  char *v121;
  s64 *v122;
  dds3Effect_Filter_t_o *v123;
  dds3Effect_Filter_t_c *v124;
  s64 v125;
  char *v126;
  s64 *v127;
  struct pmdDataInfo_t_array *v128;
  s32 v130;
  evtFrameInfo_t_c *v131;
  s64 v132;
  char *v133;
  s64 *v134;
  dds3Effect_PartialMultiFilterParam_t_o *v135;
  dds3Effect_PartialMultiFilterParam_t_c *v136;
  s64 v137;
  char *v138;
  s64 *v139;
  struct pmdDataInfo_t_array *v140;
  s32 v142;
  evtFrameInfo_t_c *v143;
  s64 v144;
  char *v145;
  s64 *v146;
  struct pmdDataInfo_t_array *v147;
  s32 v150;
  dds3Effect_RippleBlurParam_t_o *v151;
  dds3Effect_RippleBlurParam_t_c *v152;
  s64 v153;
  char *v154;
  s64 *v155;
  struct pmdDataInfo_t_array *v156;
  s32 v158;
  evtFrameInfo_t_c *v159;
  s64 v160;
  char *v161;
  s64 *v162;
  struct pmdSceneLightTable_t_o *RunFrame2_sl;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  f32 v172;
  f32 v174;
  f32 v175;
  struct pmdSceneFogTable_t_o *RunFrame2_sf;
  f32 Min;
  f32 Max;
  f32 Far;
  f32 Near;
  dds3Effect_Blur_t_o *RunFrame2_bl2;
  dds3Effect_PartialMultiBlurParam_t_o *RunFrame2_mbl;
  dds3Effect_DistortionBlurParam_t_o *RunFrame2_dbl;
  dds3Effect_Filter_t_o *RunFrame2_fl;
  dds3Effect_PartialMultiFilterParam_t_o *RunFrame2_mfl;
  dds3Effect_RippleBlurParam_t_o *RunFrame2_rbl;
  struct pmdDataInfo_t_array *v196;
  s32 v198;
  s32 v199;
  s32 v200;
  struct pmdDataInfo_t_array *v202;
  s32 v203;
  s32 v205;
  struct pmdDataInfo_t_array *v208;
  u64 v211[2];
  char *v212;
  f32 v213;
  UnityEngine_Vector4_o v214;

  v9 = frame;
  else if (nearframe)
  {
    goto LABEL_6;
  }
  else
  {
    firstframe = viewerinfo->firstframe;
    if (!v9)
      goto LABEL_20;
  }
LABEL_7:
  v13 = v9->frame - firstframe;
  if (!v13)
    goto LABEL_24;
LABEL_8:
  v14 = (nowframe - firstframe) / v13;
  v15 = obj->type - 2;
LABEL_9:
  switch (v15)
  {
    case 0u:
      if (nearframe)
      {
        v16 = nowframe - nearframe->frame;
        if (v16 < *l)
        {
          *l = v16;
          evt_camera = obj;
        }
      }
      return;
    case 4u:
      if (nearframe)
      {
        length = nearframe->length;
        v19 = 1.0;
        if (nearframe->length)
        {
          v20 = nearframe->frame;
          if ((v20 + length) > nowframe)
            v19 = (nowframe - v20) / length;
        }
        data = nearframe->data;
        switch (*&data->m_Items[0].c0)
        {
          case 0:
            if (v19 == 1.0)
              v23 = 0;
            else
              v23 = vcvts_n_s32_f32(1.0 - v19, 7u);
            v24 = 255;
            break;
          case 1:
            if (v19 == 1.0)
            {
              v24 = 255;
              v23 = 128;
            }
            else
            {
              v23 = vcvts_n_s32_f32(v19, 7u);
              v24 = 255;
            }
            break;
          case 2:
            if (v19 == 1.0)
              goto LABEL_397;
            v24 = 0;
            v23 = vcvts_n_s32_f32(1.0 - v19, 7u);
            break;
          case 3:
            v24 = 0;
            if (v19 == 1.0)
              v23 = 128;
            else
              v23 = vcvts_n_s32_f32(v19, 7u);
            break;
          default:
LABEL_397:
            v23 = 0;
            v24 = 0;
            break;
        }
        dds3FadeSet(v24, v24, v24, v23);
      }
      else
      {
        dds3FadeClear();
      }
      return;
    case 6u:
      if (!nearframe)
      {
        if ((v11->_2.bitflags2 & 2) == 0)
          goto LABEL_389;
        goto LABEL_387;
      }
      v25 = nearframe->data;
      if (LOWORD(v25->m_Items[0].i) && (p = nearframe->work.p) != 0)
      {
        v28 = nearframe->data;
        v29 = nearframe->frame;
        v31 = nowframe - v29;
        v32 = *(p + 16) - v29;
        v33 = *&v28->m_Items[0].c0;
        v34 = *(p + 24);
        LODWORD(v36) = ((v32 - v31) * v33 + v31 * *(v34 + 32)) / v32;
        v37 = nearframe->data;
        nearframe = *(nearframe->work.p + 24);
        v39 = *&v37->m_Items[0].c2;
        LODWORD(nearframe) = ((v32 - v31) * v39 + v31 * *&nearframe->work.c2) / v32;
      }
      else
      {
        v36 = nearframe->data;
        LOWORD(v36) = *&v36->m_Items[0].c0;
        LOWORD(nearframe) = *&nearframe->data->m_Items[0].c2;
      }
      if (v36 | nearframe)
      {
        viewerinfo->stat |= 4u;
        dds3ScreenBlurFlag = 1;
        dds3ScreenBlurAlpha = v36;
        dds3ScreenBlurScale = nearframe;
        return;
      }
      {
LABEL_387:
      }
LABEL_389:
      viewerinfo->stat &= ~4u;
      dds3ScreenBlurFlag = 0;
      return;
    case 8u:
      v41 = 7.0;
      v42 = 0.0;
      if (nearframe)
      {
        v43 = *&nearframe->work.i;
        if (v43)
        {
          klass = v43->klass;
          if (v43->klass->_2.typeHierarchyDepth < typeHierarchyDepth
            || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pmdSceneLightTable_t)
          {
            sub_8FC2C0(klass->_1.element_class, pmdSceneLightTable_t, v211);
            if ((v211[0] & 1) != 0)
              v46 = v212;
            else
              v46 = v211 + 1;
            v47 = sub_8C4940(v46);
          }
        }
        v48 = nearframe->data;
        max_length = v48->max_length;
        v51 = *&v48->m_Items[0].c0;
        i = nearframe->data->m_Items[0].i;
        nameindex = nearframe->nameindex;
        if (v9)
        {
LABEL_63:
          v55 = *&v9->work.i;
          if (v55)
          {
            v56 = v55->klass;
            if (v55->klass->_2.typeHierarchyDepth < v57
              || v56->_2.typeHierarchy[v57 - 1] != pmdSceneLightTable_t)
            {
              sub_8FC2C0(v56->_1.element_class, pmdSceneLightTable_t, v211);
              if ((v211[0] & 1) != 0)
                v58 = v212;
              else
                v58 = v211 + 1;
              v59 = sub_8C4940(v58);
            }
          }
          v60 = v9->data;
          v61 = v60->max_length;
          v41 = *&v60->m_Items[0].c0;
          v42 = *&v9->data->m_Items[0].i;
          if (!(v43 | v55))
            return;
LABEL_254:
          v213 = *&i;
          evtHokanSceneLight(nameindex, v14, v43, v55, &RunFrame2_sl);
          x = RunFrame2_sl->Color.x;
          y = RunFrame2_sl->Color.y;
          z = RunFrame2_sl->Color.z;
          w = RunFrame2_sl->Color.w;
          v214.x = x;
          v214.y = y;
          v214.z = z;
          v214.w = w;
          dds3SetLightColor(0, 0, v214);
          dds3SetLightDir(0, 0, RunFrame2_sl->Dir);
          dds3SetAmbientColor(0, RunFrame2_sl->Ambient);
          v172 = evtHokanFloat(nameindex, v14, v51, v41);
          v174 = v172;
          {
            v175 = v213;
          }
          else
          {
            v175 = v213;
          }
          sdfFaceDivSoften = v174;
          sdfFaceDivBias = evtHokanFloat(nameindex, v14, v175, v42);
          return;
        }
      }
      else
      {
        v43 = 0;
        nameindex = 1;
        i = 0;
        v51 = 7.0;
        if (v9)
          goto LABEL_63;
      }
      v55 = 0;
      if (!v43)
        return;
      goto LABEL_254;
    case 9u:
      if (!nearframe)
      {
        v64 = 0;
        v71 = 1;
        if (!v9)
          goto LABEL_266;
        goto LABEL_87;
      }
      v64 = *&nearframe->work.i;
      if (v64)
      {
        v65 = v64->klass;
        if (v64->klass->_2.typeHierarchyDepth < v66
          || v65->_2.typeHierarchy[v66 - 1] != pmdSceneFogTable_t)
        {
          sub_8FC2C0(v65->_1.element_class, pmdSceneFogTable_t, v211);
          if ((v211[0] & 1) != 0)
            v67 = v212;
          else
            v67 = v211 + 1;
          v68 = sub_8C4940(v67);
        }
      }
      v69 = nearframe->data;
      v71 = *&v69->m_Items[0].c0;
      if (v9)
      {
LABEL_87:
        v9 = *&v9->work.i;
        if (v9)
        {
          v72 = v9->klass;
          if (v9->klass->_2.typeHierarchyDepth < v73
            || v72->_2.typeHierarchy[v73 - 1] != pmdSceneFogTable_t)
          {
            sub_8FC2C0(v72->_1.element_class, pmdSceneFogTable_t, v211);
            if ((v211[0] & 1) != 0)
              v74 = v212;
            else
              v74 = v211 + 1;
            v75 = sub_8C4940(v74);
          }
        }
      }
LABEL_266:
      if (v64 | v9)
      {
        evtHokanSceneFog(v71, v14, v64, v9, &RunFrame2_sf);
        Min = RunFrame2_sf->Min;
        Max = RunFrame2_sf->Max;
        Near = RunFrame2_sf->Near;
        Far = RunFrame2_sf->Far;
        dds3SetFogPara(0, Max, Min, Near, Far);
        dds3FogParam->color = RunFrame2_sf->Color;
      }
      return;
    case 0xAu:
      if (nearframe)
      {
        v76 = nearframe->data;
        if (viewerinfo->fldfilter == v76->m_Items[0].i)
        {
          if (!evtCheckSkyAlphaAnime())
          {
            Alpha = fldSkyGetAlpha();
            v81 = nearframe->data;
            if (Alpha != *&v81->m_Items[0].c2)
            {
              v83 = nearframe->length;
              v84 = nearframe->data;
              v86 = *&v84->m_Items[0].c2;
              evtSetSkyAlpha(v83, v86);
            }
          }
        }
        else
        {
          v196 = nearframe->data;
          v198 = v196->m_Items[0].i;
          v199 = *&nearframe->data->m_Items[0].c0;
          v200 = nearframe->length;
          fldSkySetFilter(v198, v199, v200);
          v202 = nearframe->data;
          v203 = nearframe->length;
          v205 = *&v202->m_Items[0].c2;
          evtSetSkyAlpha(v203, v205);
          v208 = nearframe->data;
          viewerinfo->fldfilter = v208->m_Items[0].i;
        }
      }
      else
      {
        if (viewerinfo->fldfilter)
        {
          fldSkySetFilter(0, 1, 0);
          viewerinfo->fldfilter = 0;
        }
      }
      return;
    case 0xBu:
      if (!nearframe)
      {
        v87 = 0;
        v94 = 1;
        if (!v9)
          goto LABEL_289;
        goto LABEL_128;
      }
      v87 = *&nearframe->work.i;
      if (v87)
      {
        v88 = v87->klass;
        if (v87->klass->_2.typeHierarchyDepth < v89
          || v88->_2.typeHierarchy[v89 - 1] != dds3Effect_Blur_t)
        {
          sub_8FC2C0(v88->_1.element_class, dds3Effect_Blur_t, v211);
          if ((v211[0] & 1) != 0)
            v90 = v212;
          else
            v90 = v211 + 1;
          v91 = sub_8C4940(v90);
        }
      }
      v92 = nearframe->data;
      v94 = *&v92->m_Items[0].c0;
      if (v9)
      {
LABEL_128:
        v9 = *&v9->work.i;
        if (v9)
        {
          v95 = v9->klass;
          if (v9->klass->_2.typeHierarchyDepth < v96
            || v95->_2.typeHierarchy[v96 - 1] != dds3Effect_Blur_t)
          {
            sub_8FC2C0(v95->_1.element_class, dds3Effect_Blur_t, v211);
            if ((v211[0] & 1) != 0)
              v97 = v212;
            else
              v97 = v211 + 1;
            v98 = sub_8C4940(v97);
          }
        }
      }
LABEL_289:
      if (v87 | v9)
      {
        evtHokanBlur2(v94, v14, v87, v9, &RunFrame2_bl2);
        Eve_BlurSetParam2(RunFrame2_bl2);
        viewerinfo->drawblur2 = 1;
      }
      return;
    case 0xCu:
      if (!nearframe)
      {
        v99 = 0;
        v106 = 1;
        if (!v9)
          goto LABEL_301;
        goto LABEL_146;
      }
      v99 = *&nearframe->work.i;
      if (v99)
      {
        v100 = v99->klass;
        if (v99->klass->_2.typeHierarchyDepth < v101
          || v100->_2.typeHierarchy[v101 - 1] != dds3Effect_PartialMultiBlurParam_t)
        {
          sub_8FC2C0(v100->_1.element_class, dds3Effect_PartialMultiBlurParam_t, v211);
          if ((v211[0] & 1) != 0)
            v102 = v212;
          else
            v102 = v211 + 1;
          v103 = sub_8C4940(v102);
        }
      }
      v104 = nearframe->data;
      v106 = *&v104->m_Items[0].c0;
      if (v9)
      {
LABEL_146:
        v9 = *&v9->work.i;
        if (v9)
        {
          v107 = v9->klass;
          if (v9->klass->_2.typeHierarchyDepth < v108
            || v107->_2.typeHierarchy[v108 - 1] != dds3Effect_PartialMultiBlurParam_t)
          {
            sub_8FC2C0(v107->_1.element_class, dds3Effect_PartialMultiBlurParam_t, v211);
            if ((v211[0] & 1) != 0)
              v109 = v212;
            else
              v109 = v211 + 1;
            v110 = sub_8C4940(v109);
          }
        }
      }
LABEL_301:
      if (v99 | v9)
      {
        evtHokanMultBlur(v106, v14, v99, v9, &RunFrame2_mbl);
        Eve_PartialMultiBlurSetParam(RunFrame2_mbl);
        viewerinfo->drawmblur = 1;
      }
      return;
    case 0xDu:
      if (!nearframe)
      {
        v111 = 0;
        v118 = 1;
        if (!v9)
          goto LABEL_313;
        goto LABEL_164;
      }
      v111 = *&nearframe->work.i;
      if (v111)
      {
        v112 = v111->klass;
        if (v111->klass->_2.typeHierarchyDepth < v113
          || v112->_2.typeHierarchy[v113 - 1] != dds3Effect_DistortionBlurParam_t)
        {
          sub_8FC2C0(v112->_1.element_class, dds3Effect_DistortionBlurParam_t, v211);
          if ((v211[0] & 1) != 0)
            v114 = v212;
          else
            v114 = v211 + 1;
          v115 = sub_8C4940(v114);
        }
      }
      v116 = nearframe->data;
      v118 = *&v116->m_Items[0].c0;
      if (v9)
      {
LABEL_164:
        v9 = *&v9->work.i;
        if (v9)
        {
          v119 = v9->klass;
          if (v9->klass->_2.typeHierarchyDepth < v120
            || v119->_2.typeHierarchy[v120 - 1] != dds3Effect_DistortionBlurParam_t)
          {
            sub_8FC2C0(v119->_1.element_class, dds3Effect_DistortionBlurParam_t, v211);
            if ((v211[0] & 1) != 0)
              v121 = v212;
            else
              v121 = v211 + 1;
            v122 = sub_8C4940(v121);
          }
        }
      }
LABEL_313:
      if (v111 | v9)
      {
        evtHokanDistBlur(v118, v14, v111, v9, &RunFrame2_dbl);
        Eve_DistortionBlurSetParam(RunFrame2_dbl);
        viewerinfo->drawdblur = 1;
      }
      return;
    case 0xEu:
      if (!nearframe)
      {
        v123 = 0;
        v130 = 1;
        if (!v9)
          goto LABEL_325;
        goto LABEL_182;
      }
      v123 = *&nearframe->work.i;
      if (v123)
      {
        v124 = v123->klass;
        if (v123->klass->_2.typeHierarchyDepth < v125
          || v124->_2.typeHierarchy[v125 - 1] != dds3Effect_Filter_t)
        {
          sub_8FC2C0(v124->_1.element_class, dds3Effect_Filter_t, v211);
          if ((v211[0] & 1) != 0)
            v126 = v212;
          else
            v126 = v211 + 1;
          v127 = sub_8C4940(v126);
        }
      }
      v128 = nearframe->data;
      v130 = *&v128->m_Items[0].c0;
      if (v9)
      {
LABEL_182:
        v9 = *&v9->work.i;
        if (v9)
        {
          v131 = v9->klass;
          if (v9->klass->_2.typeHierarchyDepth < v132
            || v131->_2.typeHierarchy[v132 - 1] != dds3Effect_Filter_t)
          {
            sub_8FC2C0(v131->_1.element_class, dds3Effect_Filter_t, v211);
            if ((v211[0] & 1) != 0)
              v133 = v212;
            else
              v133 = v211 + 1;
            v134 = sub_8C4940(v133);
          }
        }
      }
LABEL_325:
      if (v123 | v9)
      {
        evtHokanFilter(v130, v14, v123, v9, &RunFrame2_fl);
        Eve_FilterSetParam(RunFrame2_fl);
        viewerinfo->drawfilter = 1;
      }
      return;
    case 0xFu:
      if (!nearframe)
      {
        v135 = 0;
        v142 = 1;
        if (!v9)
          goto LABEL_337;
        goto LABEL_200;
      }
      v135 = *&nearframe->work.i;
      if (v135)
      {
        v136 = v135->klass;
        if (v135->klass->_2.typeHierarchyDepth < v137
          || v136->_2.typeHierarchy[v137 - 1] != dds3Effect_PartialMultiFilterParam_t)
        {
          sub_8FC2C0(v136->_1.element_class, dds3Effect_PartialMultiFilterParam_t, v211);
          if ((v211[0] & 1) != 0)
            v138 = v212;
          else
            v138 = v211 + 1;
          v139 = sub_8C4940(v138);
        }
      }
      v140 = nearframe->data;
      v142 = *&v140->m_Items[0].c0;
      if (v9)
      {
LABEL_200:
        v9 = *&v9->work.i;
        if (v9)
        {
          v143 = v9->klass;
          if (v9->klass->_2.typeHierarchyDepth < v144
            || v143->_2.typeHierarchy[v144 - 1] != dds3Effect_PartialMultiFilterParam_t)
          {
            sub_8FC2C0(v143->_1.element_class, dds3Effect_PartialMultiFilterParam_t, v211);
            if ((v211[0] & 1) != 0)
              v145 = v212;
            else
              v145 = v211 + 1;
            v146 = sub_8C4940(v145);
          }
        }
      }
LABEL_337:
      if (v135 | v9)
      {
        evtHokanMultFilter(v142, v14, v135, v9, &RunFrame2_mfl);
        Eve_PartialMultiFilterSetParam(RunFrame2_mfl);
        viewerinfo->drawmfilter = 1;
      }
      return;
    case 0x14u:
      if (nearframe)
      {
        v147 = nearframe->data;
        if (*&v147->m_Items[0].c0)
        {
          v150 = 1;
          goto LABEL_385;
        }
          goto LABEL_382;
      }
      else
      {
        {
LABEL_382:
        }
      }
      v150 = 0;
LABEL_385:
      evtSetBokasi(v150);
      return;
    case 0x15u:
      if (!nearframe)
      {
        v151 = 0;
        v158 = 1;
        if (!v9)
          goto LABEL_351;
        goto LABEL_226;
      }
      v151 = *&nearframe->work.i;
      if (v151)
      {
        v152 = v151->klass;
        if (v151->klass->_2.typeHierarchyDepth < v153
          || v152->_2.typeHierarchy[v153 - 1] != dds3Effect_RippleBlurParam_t)
        {
          sub_8FC2C0(v152->_1.element_class, dds3Effect_RippleBlurParam_t, v211);
          if ((v211[0] & 1) != 0)
            v154 = v212;
          else
            v154 = v211 + 1;
          v155 = sub_8C4940(v154);
        }
      }
      v156 = nearframe->data;
      v158 = *&v156->m_Items[0].c0;
      if (v9)
      {
LABEL_226:
        v9 = *&v9->work.i;
        if (v9)
        {
          v159 = v9->klass;
          if (v9->klass->_2.typeHierarchyDepth < v160
            || v159->_2.typeHierarchy[v160 - 1] != dds3Effect_RippleBlurParam_t)
          {
            sub_8FC2C0(v159->_1.element_class, dds3Effect_RippleBlurParam_t, v211);
            if ((v211[0] & 1) != 0)
              v161 = v212;
            else
              v161 = v211 + 1;
            v162 = sub_8C4940(v161);
          }
        }
      }
LABEL_351:
      if (v151 | v9)
      {
        evtHokanRipBlur(v158, v14, v151, v9, &RunFrame2_rbl);
        Eve_RippleBlurSetParam(RunFrame2_rbl);
        viewerinfo->drawrblur = 1;
      }
      return;
    default:
      return;
  }
}

// 0x136db40
void RunFrame3(s32 nowframe) {
  u64 *v3;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v10;
  dds3Basic_t_o *namespaze;
  struct evtViewerObject_s_o *firstobjinfo;
  il2cpp_array_size_t max_length;
  evtUnitHandle_t_o *UnitHandle2;
  il2cpp_array_size_t v28;
  s32 v29;
  s32 v30;
  s32 v32;
  char *v33;
  s64 *v34;
  struct System_Object_array *v35;
  evtUnitHandle_t_o *h;
  dds3Basic_t_o *light;
  u64 v38[3];

  light = 0;
  v3 = Allocate(evtUnitHandle_t);
  _ctor(v3, 0);
  h = v3;
  else if (!dds3GetActiveScene())
  {
    return;
  }
  workdata = dds3GetActiveScene()->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v38);
    if ((v38[0] & 1) != 0)
      v33 = v38[2];
    else
      v33 = v38 + 1;
    v34 = sub_8C4940(v33);
  }
  v10 = workdata[2].klass;
  namespaze = v10->_1.castClass->_1.namespaze;
  if (namespaze)
  {
    while (1)
    {
      if (!namespaze->name)
        goto LABEL_72;
      light = 0;
      else
      {
        firstobjinfo = viewerinfo->firstobjinfo;
        if (firstobjinfo)
          goto LABEL_18;
      }
      v35 = 0;
LABEL_47:
      UnitHandle2 = evtGetUnitHandle2(namespaze);
      h = UnitHandle2;
      if (v35)
      {
        v28 = v35->max_length;
        if (!*(v28 + 34))
        {
          if ((UnitHandle2->Flag & 0x140000) == 0x40000)
          {
            v32 = WORD1(v35->bounds);
            v30 = v32;
LABEL_71:
            evtUnlinkLightObjectBasic(&h, v30);
            goto LABEL_72;
          }
          goto LABEL_72;
        }
        if (UnitHandle2->BasicLight == light && (UnitHandle2->Flag & 0x40000) != 0)
          goto LABEL_72;
        v29 = WORD1(v35->bounds);
        evtLinkLightObjectBasic(&h, &light, v29);
        namespaze = namespaze->next;
        if (!namespaze)
          return;
      }
      else
      {
        if (UnitHandle2->BasicLight)
        {
          v30 = 0;
          goto LABEL_71;
        }
LABEL_72:
        namespaze = namespaze->next;
        if (!namespaze)
          return;
      }
    }
  }
}

// 0x136e000
void RunFrameUnit(evtViewerObject_s *obj, s32 nowframe) {
  struct System_Object_array *p;
  s32 v6;
  s32 v7;
  il2cpp_array_size_t max_length;
  u32 v9;
  bool v10;
  u32 v11;
  il2cpp_array_size_t v12;
  il2cpp_array_size_t v15;
  dds3Basic_t_o *basic;

  p = obj->p;
  if (p)
  {
    v6 = 0;
    v7 = 2;
    while (LOWORD(p->bounds) <= nowframe)
    {
      max_length = p->max_length;
      v9 = *(max_length + 32);
      v10 = v9 >= 2;
      v11 = v9 - 2;
      if (v10)
      {
        if (v11 <= 2)
        {
          v12 = p->max_length;
          v7 = *(v12 + 32);
        }
        p = p->m_Items[2];
        if (!p)
          break;
      }
      else
      {
        v15 = p->max_length;
        v6 = *(v15 + 32);
        p = p->m_Items[2];
        if (!p)
          break;
      }
    }
  }
  else
  {
    v6 = 0;
    v7 = 2;
  }
  basic = obj->basic;
  evtRunUnitMode_17839264(basic, v6);
  evtRunUnitMode_17839264(obj->basic, v7);
}

// 0x136a8d0
dds3Basic_t *SearchBasicFromNameIndex(s32 nameindex) {
  dds3Basic_t_o *ActiveScene;
  struct pmdNameTable_t_array *nametable;
  System_String_o *Name;

  if (nameindex < 0)
    return 0;
  ActiveScene = dds3GetActiveScene();
  nametable = viewerinfo->nametable;
  Name = nametable->m_Items[nameindex]->Name;
  return dds3SceneBasicSearchNameAndType(ActiveScene, 7u, Name);
}

// 0x136a7b0
s32 SearchNameTable(char *name) {
  u64 v3;
  s32 v4;
  struct evtViewerInfo_t_o *viewerinfo;
  struct pmdNameTable_t_array *nametable;

  v3 = 0;
  v4 = -1;
  {
LABEL_6:
  }
  while (1)
  {
    if (v3 >= viewerinfo->nametablecnt)
      return v4;
    else
    {
      nametable = viewerinfo->nametable;
      if (v3 >= LODWORD(nametable->max_length))
        goto LABEL_12;
    }
    if (!Compare(name, nametable->m_Items[v3]->Name, 0))
      return v3;
    ++v3;
      goto LABEL_6;
  }
}

// 0x136e9b0
void SelectActiveCamera(void) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 v12;
  struct evtViewerInfo_t_o *viewerinfo;
  struct dds3Basic_t_o *activecamera;
  struct dds3Basic_t_o *prev;
  s16 v18;
  struct dds3Basic_t_o *v19;
  Il2CppClass *v23;
  u64 v26[3];

  if (!dds3GetActiveScene())
    goto LABEL_29;
LABEL_6:
  else
  {
    workdata = dds3GetActiveScene()->workdata;
    if (!workdata)
      goto LABEL_15;
  }
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v26);
    if ((v26[0] & 1) != 0)
      v7 = v26[2];
    else
      v7 = v26 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_15:
  else if (DDS3_PADCHECK_TRIG(3))
  {
    goto LABEL_18;
  }
  if (DDS3_PADCHECK_TRIG(0))
  {
    if ((v18 & 0x200) != 0)
    {
      v12 = v18 & 0x200;
      v19 = viewerinfo->activecamera;
      if (!v19)
        goto LABEL_75;
    }
    else
    {
      v12 = 0;
      v19 = viewerinfo->activecamera;
      if (!v19)
        goto LABEL_75;
    }
    if (v19->next)
    {
      prev = v19->next;
      goto LABEL_80;
    }
    if (viewerinfo->gamecamera)
      goto LABEL_71;
LABEL_75:
    else
    {
      v23 = workdata[2].klass;
      if (LODWORD(v23->_1.namespaze) <= 4)
        goto LABEL_78;
    }
    prev = v23->_1.element_class->_1.namespaze;
    goto LABEL_80;
  }
}

// 0x136b630
void SetActiveCamera(void) {
  s16 v3;
  s32 v4;
  struct evtViewerInfo_t_o *viewerinfo;
  f32 Fovy;
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *pCameraBasic;

  ActiveScene = 0;
  pCameraBasic = 0;
  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
    if (viewerinfo->activecamera)
    {
LABEL_5:
      pCameraBasic = viewerinfo->activecamera;
      if (!pCameraBasic)
        return;
LABEL_21:
      ActiveScene = dds3GetActiveScene();
      dds3SetActiveCameraSceneBasic(&ActiveScene, &pCameraBasic);
      Fovy = dds3CameraObjectBasicGetFovy(&pCameraBasic);
      dds3SetScreenFovy(Fovy);
      return;
    }
  }
  else
  {
    v4 = 0;
    if (viewerinfo->activecamera)
      goto LABEL_5;
  }
  if (viewerinfo->gamecamera)
  {
    pCameraBasic = viewerinfo->gamecamera;
    if (pCameraBasic)
      goto LABEL_21;
  }
}

// 0x13688a0
void SortFrameInfo(evtViewerObject_s *parent) {
  struct System_Object_array *p;
  struct System_Object_array **p_p;
  s32 *p_framecnt;
  Il2CppObject *klass;
  Il2CppObject *v7;
  char *monitor;
  struct System_Object_array **v9;
  s32 *p_bits;
  struct System_Object_array *v11;
  void *v12;
  Il2CppObject *v13;
  Il2CppObject *v14;

  if (parent)
  {
    p_p = &parent->p;
    p = parent->p;
    if (p)
    {
      p_framecnt = &parent->framecnt;
      klass = p->m_Items[2];
      if (klass)
        goto LABEL_8;
LABEL_10:
      while (1)
      {
        p = p->m_Items[2];
        if (!p)
          break;
        while (1)
        {
          klass = p->m_Items[2];
          if (!klass)
            break;
LABEL_8:
          while (LOWORD(p->bounds) <= LOWORD(klass[1].klass))
          {
            klass = klass[3].klass;
            if (!klass)
              goto LABEL_10;
          }
          v7 = klass + 3;
          monitor = klass[3].monitor;
          if (monitor)
            v9 = (monitor + 48);
          else
            v9 = &parent->p;
          *v9 = klass[3].klass;
          if (v7->klass)
            p_bits = &v7->klass->_1.this_arg.bits;
          else
            p_bits = &parent->framecnt;
          *p_bits = klass[3].monitor;
          v7->klass = 0;
          klass[3].monitor = 0;
          --LODWORD(parent->data.p);
          v11 = parent->p;
          if (v11)
          {
            while (LOWORD(klass[1].klass) >= LOWORD(v11->bounds))
            {
              v11 = v11->m_Items[2];
              if (!v11)
              {
                *(*p_framecnt + 48LL) = klass;
                v12 = *p_framecnt;
                klass[3].klass = 0;
                klass[3].monitor = v12;
                *p_framecnt = klass;
                goto LABEL_29;
              }
            }
            v13 = v11->m_Items[3];
            if (v13)
            {
              v13[3].klass = klass;
              v14 = v11->m_Items[3];
              klass[3].klass = v11;
              klass[3].monitor = v14;
              v11->m_Items[3] = klass;
            }
            else
            {
              *p_p = klass;
              v11->m_Items[3] = klass;
              klass[3].klass = v11;
              klass[3].monitor = 0;
            }
          }
          else
          {
            *p_p = klass;
            *p_framecnt = klass;
            v7->klass = 0;
            klass[3].monitor = 0;
          }
LABEL_29:
          ++LODWORD(parent->data.p);
          p = klass[3].klass;
          if (!p)
            return;
        }
      }
    }
  }
}

// 0x1368850
void UnlinkFrameInfo(evtViewerObject_s *parent, evtFrameInfo_t *f) {
  Il2CppObject *p;
  struct System_Object_array **p_p;
  intptr_t v5;
  s32 *p_framecnt;

  p = f->p;
  if (p)
    p_p = &p[3];
  else
    p_p = &parent->p;
  *p_p = f->work.p;
  v5 = f->work.p;
  if (v5)
    p_framecnt = (v5 + 56);
  else
    p_framecnt = &parent->framecnt;
  *p_framecnt = f->p;
  f->work.p = 0;
  f->p = 0;
  --LODWORD(parent->data.p);
}

// 0x1369db0
void UnlinkViewerObject(evtViewerObject_s *obj) {
  struct evtFrameInfo_t_o *lastframeinfo;
  u64 *p_klass;
  struct evtFrameInfo_t_o **p_firstframeinfo;
  struct evtFrameInfo_t_o *firstframeinfo;
  evtEventViewer_c *v8;

  lastframeinfo = obj->lastframeinfo;
  if (lastframeinfo)
  {
    p_klass = &lastframeinfo[1].klass;
  }
  else
  {
    p_klass = &viewerinfo->firstobjinfo;
  }
  p_firstframeinfo = &obj->firstframeinfo;
  *p_klass = obj->firstframeinfo;
  firstframeinfo = obj->firstframeinfo;
  if (firstframeinfo)
  {
    firstframeinfo[1].monitor = obj->lastframeinfo;
    *p_firstframeinfo = 0;
    obj->lastframeinfo = 0;
    if ((v8->_2.bitflags2 & 2) == 0)
      goto LABEL_17;
    goto LABEL_11;
  }
  viewerinfo->lastobjinfo = obj->lastframeinfo;
  *p_firstframeinfo = 0;
  obj->lastframeinfo = 0;
  if ((v8->_2.bitflags2 & 2) != 0)
  {
LABEL_11:
  }
LABEL_17:
  --viewerinfo->objcnt;
}

// 0x1368a30
evtFrameInfo_t *evtAddFrameInfo(evtViewerObject_s *parent, s32 frame) {
  s16 v3;
  u64 *v5;
  u64 *v6;
  struct System_Object_array *p;
  u64 v9;
  Il2CppObject *v10;
  Il2CppObject *v11;
  struct pmdNameTable_t_array *v13;
  s64 v14;
  s32 v16;
  u64 v17;
  struct pmdNameTable_t_array *nametable;
  s64 nameindex;
  s32 v29;
  u64 v30;
  u64 v32;
  f32 v34;
  struct pmdNameTable_t_array *v37;
  s64 v38;
  struct pmdNameTable_t_array *v41;
  s64 v42;
  s32 v44;
  u64 v45;
  struct pmdNameTable_t_array *v52;
  s64 v53;
  s32 v55;
  u64 v56;
  u64 *v59;
  struct sdf3DLight_t_array *dds3DirLights;
  struct sdf3DLight_t_array *v64;
  u64 v68;
  u64 *v71;
  u64 v74;
  u64 *v78;
  u64 *v80;
  u64 *v82;
  u64 *v84;
  u64 *v86;
  struct pmdNameTable_t_array *v89;
  s64 v90;
  s32 v92;
  u64 v93;
  u64 *v98;

  v3 = frame;
  v5 = Allocate(evtFrameInfo_t);
  v5[3] = NewSpecific(pmdDataInfo_t, 2u);
  v6 = v5 + 3;
  _ctor(v5, 0);
  *(v5 + 8) = v3;
  *(v5 + 5) = -1;
  p = parent->p;
  if (!p)
  {
LABEL_14:
    parent->p = v5;
    *&parent->framecnt = v5;
    v5[6] = 0;
    v5[7] = 0;
    goto LABEL_16;
  }
LABEL_8:
  while (*(v5 + 8) >= LOWORD(p->bounds))
  {
    p = p->m_Items[2];
    if (!p)
    {
      *(*&parent->framecnt + 48LL) = v5;
      v9 = *&parent->framecnt;
      v5[6] = 0;
      v5[7] = v9;
      *&parent->framecnt = v5;
      goto LABEL_16;
    }
  }
  v10 = p->m_Items[3];
  if (v10)
  {
    v10[3].klass = v5;
    v11 = p->m_Items[3];
    v5[6] = p;
    v5[7] = v11;
    p->m_Items[3] = v5;
  }
  else
  {
    parent->p = v5;
    p->m_Items[3] = v5;
    v5[6] = p;
    v5[7] = 0;
  }
LABEL_16:
  ++LODWORD(parent->data.p);
  switch (parent->type)
  {
    case 1:
      nametable = viewerinfo->nametable;
      nameindex = parent->nameindex;
      v29 = evtAddNameTable(nametable->m_Items[nameindex]->Name);
      v30 = v5[3];
      *(v5 + 5) = v29;
      if (!*(v30 + 24))
        goto LABEL_43;
      goto LABEL_44;
    case 2:
      v32 = *v6;
      v34 = SDF_DEGtoRAD(30.0);
      *(v32 + 32) = v34;
      v37 = viewerinfo->nametable;
      v38 = parent->nameindex;
      *(v5 + 5) = evtAddNameTable(v37->m_Items[v38]->Name);
      return v5;
    case 3:
      v41 = viewerinfo->nametable;
      v42 = parent->nameindex;
      v44 = evtAddNameTable(v41->m_Items[v42]->Name);
      v45 = v5[3];
      *(v5 + 5) = v44;
      *(v45 + 32) = -1;
      *(*v6 + 34) = 0;
      *(*v6 + 40) = 0;
      *(*v6 + 41) = -1;
      *(*v6 + 42) = -1;
      return v5;
    case 9:
      v52 = viewerinfo->nametable;
      v53 = parent->nameindex;
      v55 = evtAddNameTable(v52->m_Items[v53]->Name);
      v56 = v5[3];
      *(v5 + 5) = v55;
      *(v56 + 32) = -1;
      *(*v6 + 34) = 1;
      return v5;
    case 0xA:
      v59 = Allocate(pmdSceneLightTable_t);
      _ctor(v59, 0);
      SDF_VU0__COPYVECTOR(v59 + 1, dds3DirLights->m_Items[0]->color);
      v64 = dds3DirLights;
      SDF_VU0__COPYVECTOR(v59 + 2, v64->m_Items[0]->v);
      SDF_VU0__COPYVECTOR(v59 + 3, dds3Ambient);
      v5[5] = v59;
      v68 = v5[3];
      *(v68 + 32) = sdfFaceDivSoften;
      *(*v6 + 40) = sdfFaceDivBias;
      *(v5 + 5) = 1;
      return v5;
    case 0xB:
      v71 = Allocate(pmdSceneFogTable_t);
      _ctor(v71, 0);
      *(v71 + 4) = LODWORD(dds3FogParam->fogMin);
      *(v71 + 5) = LODWORD(dds3FogParam->fogMax);
      *(v71 + 6) = LODWORD(dds3FogParam->fogNear);
      *(v71 + 7) = LODWORD(dds3FogParam->fogFar);
      *(v71 + 8) = dds3FogParam->color;
      v5[5] = v71;
      v74 = v5[3];
      if (!*(v74 + 24))
        goto LABEL_146;
      goto LABEL_147;
    case 0xC:
      *(*v6 + 32) = 1;
      *(*v6 + 34) = 128;
      *(*v6 + 40) = 0;
      return v5;
    case 0xD:
      v78 = Allocate(dds3Effect_Blur_t);
      dds3Effect_Blur_t___ctor(v78);
      v5[5] = v78;
      v5[5] = Eve_BlurEditorGetParams();
      v74 = v5[3];
      if (!*(v74 + 24))
        goto LABEL_146;
      goto LABEL_147;
    case 0xE:
      v80 = Allocate(dds3Effect_PartialMultiBlurParam_t);
      dds3Effect_PartialMultiBlurParam_t___ctor(v80);
      v5[5] = v80;
      v5[5] = Eve_PartialMultiBlurEditorGetParams();
      v74 = v5[3];
      if (!*(v74 + 24))
        goto LABEL_146;
      goto LABEL_147;
    case 0xF:
      v82 = Allocate(dds3Effect_DistortionBlurParam_t);
      dds3Effect_DistortionBlurParam_t___ctor(v82);
      v5[5] = v82;
      v5[5] = Eve_DistortionBlurEditorGetParams();
      v74 = v5[3];
      if (!*(v74 + 24))
        goto LABEL_146;
      goto LABEL_147;
    case 0x10:
      v84 = Allocate(dds3Effect_Filter_t);
      dds3Effect_Filter_t___ctor(v84);
      v5[5] = v84;
      v5[5] = Eve_FilterEditorGetParams();
      v74 = v5[3];
      if (!*(v74 + 24))
        goto LABEL_146;
      goto LABEL_147;
    case 0x11:
      v86 = Allocate(dds3Effect_PartialMultiFilterParam_t);
      dds3Effect_PartialMultiFilterParam_t___ctor(v86);
      v5[5] = v86;
      v5[5] = Eve_PartialMultiFilterEditorGetParams();
      v74 = v5[3];
      if (!*(v74 + 24))
        goto LABEL_146;
      goto LABEL_147;
    case 0x12:
      v89 = viewerinfo->nametable;
      v90 = parent->nameindex;
      v92 = evtAddNameTable(v89->m_Items[v90]->Name);
      v93 = v5[3];
      *(v5 + 5) = v92;
      *(v93 + 32) = 0;
      *(*v6 + 34) = -1;
      v30 = *v6;
      if (!*(*v6 + 24))
      {
LABEL_43:
      }
LABEL_44:
      *(v30 + 32) = 0;
      return v5;
    case 0x14:
    case 0x15:
      v13 = viewerinfo->nametable;
      v14 = parent->nameindex;
      v16 = evtAddNameTable(v13->m_Items[v14]->Name);
      v17 = v5[3];
      *(v5 + 5) = v16;
      *(v17 + 32) = -1;
      *(*v6 + 33) = 0;
      *(*v6 + 34) = 0;
      *(*v6 + 40) = -1;
      *(*v6 + 41) = -1;
      *(*v6 + 42) = -1;
      *(*v6 + 43) = -1;
      return v5;
    case 0x16:
      v74 = *v6;
      if (!*(*v6 + 24))
        goto LABEL_146;
      goto LABEL_147;
    case 0x17:
      v98 = Allocate(dds3Effect_RippleBlurParam_t);
      dds3Effect_RippleBlurParam_t___ctor(v98);
      v5[5] = v98;
      v5[5] = Eve_RippleBlurEditorGetParams();
      v74 = v5[3];
      if (!*(v74 + 24))
      {
LABEL_146:
      }
LABEL_147:
      *(v74 + 32) = 1;
      break;
    default:
      return v5;
  }
  return v5;
}

// 0x1369590
s32 evtAddNameTable(char *name) {
  s32 nametablecnt;
  struct evtViewerInfo_t_o *viewerinfo;
  struct pmdNameTable_t_array *nametable;

  else
  {
    nametablecnt = SearchNameTable(name);
    if ((nametablecnt & 0x80000000) == 0)
      return nametablecnt;
  }
  nametable = viewerinfo->nametable;
  nametablecnt = viewerinfo->nametablecnt;
  nametable->m_Items[nametablecnt]->Name = name;
  ++viewerinfo->nametablecnt;
  return nametablecnt;
}

// 0x1369ee0
evtViewerObject_s *evtAddViewerObject(s32 type) {
  u64 *v3;

  v3 = Allocate(evtViewerObject_s);
  _ctor(v3, 0);
  if (v3)
  {
    *(v3 + 4) = type;
    *(v3 + 20) = -1;
    LinkViewerObject(v3);
  }
  return v3;
}

// 0x1374a90
void *evtEventViewerProcess1(dds3ProcessID_t *id) {
  u64 *v3;

LABEL_7:
  viewerinfo->stat |= 1u;
  viewerinfo->totalframe = 540;
  viewerinfo->lastframe = viewerinfo->totalframe - 1;
  viewerinfo->framedisp = 1;
  v3 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v3,
    0,
    Method_evtEventViewer_evtEventViewerProcess2__);
  return v3;
}

// 0x1374980
void *evtEventViewerProcess2(dds3ProcessID_t *id) {
  u64 *v2;
  u64 *v6;
  dds3ProcessID_t_o *inited;
  dds3ProcessID_t_o *parent;

  parent = id;
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  inited = v2;
  evtRunFrame(viewerinfo->nowframe);
  inited = evtInitFrameVar();
  dds3LinkProcess(&parent, &inited);
  v6 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v6,
    0,
    Method_evtEventViewer_evtEventViewerProcess3__);
  return v6;
}

// 0x1374530
void *evtEventViewerProcess3(dds3ProcessID_t *id) {
  evtEventViewer_c *v2;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 nowframe;
  bool v8;
  u64 *v12;
  s16 v16;
  s32 v17;
  struct evtViewerInfo_t_o *v18;
  u64 v22;
  struct evtViewerInfo_t_o *v23;
  s16 v24;
  s32 v25;
  s32 v26;

  nowframe = viewerinfo->nowframe;
  if (nowframe != viewerinfo->oldframe)
  {
    evtRunFrame(nowframe);
  }
  viewerinfo->oldframe = viewerinfo->nowframe;
  DrawActiveCameraName(v2);
  DrawEffect();
  v8 = DDS3_PADCHECK_TRIG(2);
  if (v8)
  {
    *(v9[2].klass->_1.image + 6) |= 1u;
    evtViewerStopFrame();
    viewerinfo->nowmenu = 0;
    viewerinfo->sp = 0;
    viewerinfo->menusw = 0;
    PushMenu(1, 36, 24);
    v12 = Allocate(System_Func_dds3ProcessID_t__object_);
    object____ctor(
      v12,
      0,
      Method_evtEventViewer_evtEventViewerProcess4__);
    return v12;
  }
  SelectActiveCamera();
  if (viewerinfo->menusw)
    goto LABEL_36;
  if (!DDS3_PADCHECK_TRIG(1))
  {
LABEL_36:
      goto LABEL_39;
    goto LABEL_37;
  }
  if ((v16 & 0x200) != 0)
  {
    v17 = v16 & 0x200;
    v18 = viewerinfo;
    if (v18->framedisp)
      goto LABEL_32;
  }
  else
  {
    v17 = 0;
    v18 = viewerinfo;
    if (v18->framedisp)
    {
LABEL_32:
      v18->framedisp = 0;
      goto LABEL_36;
    }
  }
  v18->framedisp = 1;
  {
LABEL_37:
  }
LABEL_39:
  if (DDS3_PADCHECK_TRIG(12))
  {
    *(v21[2].klass->_1.image + 6) ^= 1u;
    evtViewerStopFrame();
  }
  if ((*(**(v22 + 184) + 24LL) & 1) != 0)
  {
    FrameSelect(v22);
  }
  if ((*(v22 + 295) & 2) == 0 || *(v22 + 216))
  {
    v23 = **(v22 + 184);
    if ((v23->stat & 1) == 0)
      goto LABEL_55;
    return 0;
  }
  v23 = viewerinfo;
  if ((v23->stat & 1) != 0)
    return 0;
LABEL_55:
  v24 = *(v22 + 294);
  if ((v24 & 0x200) != 0)
  {
    if (!*(v22 + 216))
    {
      v23 = viewerinfo;
    }
    v25 = v24 & 0x200;
    v26 = v23->nowframe;
    if (v26 >= v23->lastframe)
      goto LABEL_57;
  }
  else
  {
    v25 = 0;
    v26 = v23->nowframe;
    if (v26 >= v23->lastframe)
    {
LABEL_57:
      if (v25 && !*(v22 + 216))
      {
        v23 = viewerinfo;
      }
      v23->stat ^= 1u;
      evtViewerStopFrame(v22);
      return 0;
    }
  }
  if (v25 && !*(v22 + 216))
  {
    v23 = viewerinfo;
    v26 = v23->nowframe;
  }
  v23->nowframe = v26 + 1;
  return 0;
}

// 0x1373d70
void *evtEventViewerProcess4(dds3ProcessID_t *id) {
  s64 v4;
  s32 name_low;
  u64 v7;
  Il2CppClass **v8;
  struct evtViewerInfo_t_o *viewerinfo;
  struct menuinfo_t_array *menustack;
  s32 y;
  s32 v14;
  s32 menu;
  s32 v16;
  struct evtViewerInfo_t_o *v17;
  struct menuinfo_t_array *v18;
  s32 v19;
  struct menuinfo_t_array *v22;
  s32 winoff_x;
  struct menuinfo_t_array *v27;
  s32 v30;
  struct evtEventViewer_p4_func_array *menuenter;
  struct menuinfo_t_array *v35;
  s64 v37;
  s32 v39;
  u64 *v40;
  bool v41;
  s16 v43;
  struct evtViewerInfo_t_o *v48;
  dds3ProcessID_t_o **p_pid;
  struct evtEventViewer_StaticFields **p_static_fields;
  struct evtViewerInfo_t_o *v51;
  s32 menusw;
  struct evtEventViewer_StaticFields **v54;
  struct evtViewerInfo_t_o *v55;

  DrawEffect();
  v4 = 0;
  name_low = 0;
  v7 = 1;
  {
LABEL_9:
    goto LABEL_11;
  }
  while (1)
  {
LABEL_11:
    if (v7 > viewerinfo->sp)
      goto LABEL_58;
    menustack = viewerinfo->menustack;
    y = menustack->m_Items[v4 + 1]->y;
    v14 = winoff_x + menustack->m_Items[v4 + 1]->x;
    menu = viewerinfo->menustack->m_Items[v4 + 1]->menu;
    v16 = evtViewerMenuRun(menu, v14, y);
    v17 = viewerinfo;
    v18 = v17->menustack;
    v19 = v16;
    if (v17->nowmenu == v18->m_Items[v4 + 1]->menu)
    {
      v22 = viewerinfo->menustack;
      if (v22->m_Items[v4 + 1]->menu == 4)
      {
        evtViewerMenuRun(5, winoff_x + 144, 72);
      }
    }
    if (v19)
      break;
    v27 = viewerinfo->menustack;
    v8 = &v27->obj.klass + v4++;
    name_low = LOWORD(v8[5]->_1.name);
    v7 = v4 + 1;
      goto LABEL_9;
  }
  if (v19 != -1)
  {
    v35 = viewerinfo->menustack;
    v37 = v35->m_Items[v4 + 1]->menu;
    v39 = Invoke(menuenter->m_Items[v37].func, v19, name_low, 0);
    if (v39 == -1)
    {
      v30 = 1;
        goto LABEL_61;
    }
    else
    {
      if (v39 == 1)
      {
        v40 = Allocate(dds3ProcessFunc_t);
        dds3ProcessFunc_t___ctor(v40, 0, Method_evtEventViewer_evtEventViewerProcess5_0__);
        return v40;
      }
LABEL_58:
      v30 = 0;
        goto LABEL_61;
    }
LABEL_59:
    goto LABEL_61;
  }
  PopMenu();
  v30 = 0;
    goto LABEL_59;
LABEL_61:
  if (winoff_x <= 10)
  {
    v41 = DDS3_PADCHECK_PRESS(9);
    if (v41)
    {
      v43 = winoff_x + 10;
LABEL_81:
      winoff_x = v43;
      goto LABEL_82;
    }
  }
  else if (winoff_x < -99)
  {
    goto LABEL_82;
  }
  if (DDS3_PADCHECK_PRESS(11))
  {
    v43 = winoff_x - 10;
    goto LABEL_81;
  }
LABEL_82:
  else if (!DDS3_PADCHECK_TRIG(2))
  {
    goto LABEL_112;
  }
  v48 = viewerinfo;
  if (v48->pid)
  {
    p_pid = &v48->pid;
    dds3KillProcess(p_pid, 1);
    viewerinfo->pid = 0;
  }
  v51 = viewerinfo;
  menusw = v51->menusw;
  if (menusw == 1)
  {
    v30 = 1;
    v51->menusw = 0;
  }
  else if (!menusw)
  {
    v51->nowmenu = 0;
    (*p_static_fields)->viewerinfo->sp = 0;
    ++(*p_static_fields)->viewerinfo->menusw;
    PushMenu(4, 36, 24);
      goto LABEL_114;
    goto LABEL_113;
  }
LABEL_112:
    goto LABEL_114;
LABEL_113:
LABEL_114:
  v55 = viewerinfo;
  if (v30)
    goto LABEL_118;
LABEL_115:
  if (v55->nowmenu)
    return 0;
LABEL_118:
  v55->nowmenu = 0;
  (*v54)->viewerinfo->sp = 0;
  (*v54)->viewerinfo->menusw = 0;
  v40 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v40,
    0,
    Method_evtEventViewer_evtEventViewerProcess3__);
  return v40;
}

// 0x136fdd0
void *evtEventViewerProcess5(dds3ProcessID_t *id) {
  evtEventViewer_c *v2;
  struct evtViewerInfo_t_o *viewerinfo;
  s32 nowframe;
  u64 v9;
  s16 v10;
  s32 v11;
  struct evtViewerInfo_t_o *v12;
  s32 v13;
  struct evtEventViewer_StaticFields *static_fields;

  nowframe = viewerinfo->nowframe;
  if (nowframe != viewerinfo->oldframe)
  {
    evtRunFrame(nowframe);
  }
  viewerinfo->oldframe = viewerinfo->nowframe;
  DrawEffect(v2);
  else if (DDS3_PADCHECK_PRESS(12))
  {
    goto LABEL_17;
  }
  if ((v10 & 0x200) != 0)
  {
    v11 = v10 & 0x200;
  }
  else
  {
    v11 = 0;
  }
  v12 = **(v9 + 184);
  v13 = v12->nowframe;
  if (v13 >= v12->lastframe)
  {
    if (v11 && !*(v9 + 216))
    {
      v12 = viewerinfo;
    }
    v12->stat |= 1u;
    evtViewerStopFrame(v9);
    dds3ScreenCaptureOff();
    goto LABEL_57;
  }
  if (v11 && !*(v9 + 216))
  {
    v12 = viewerinfo;
    v13 = v12->nowframe;
  }
  v12->nowframe = v13 + 1;
  static_fields = *(v9 + 184);
  if ((viewerinfo->stat & 1) != 0)
  {
    if (capwait >= 1)
    {
      viewerinfo->stat &= ~1u;
      evtViewerStopFrame(v9);
    }
  }
  ++*(*(v9 + 184) + 104LL);
  return 0;
}

// 0x1370100
dds3ProcessFunc_t *evtEventViewerProcess5_0(dds3ProcessID_t *id) {
  s16 v3;
  s32 v4;
  struct evtEventViewer_StaticFields **p_static_fields;
  s32 capwait;
  u64 *v8;

  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
  }
  else
  {
    v4 = 0;
  }
  if (capwait == 3)
  {
    capwait = 0;
    (*p_static_fields)->viewerinfo->oldframe = (*p_static_fields)->viewerinfo->nowframe;
    v8 = Allocate(dds3ProcessFunc_t);
    dds3ProcessFunc_t___ctor(v8, 0, Method_evtEventViewer_evtEventViewerProcess5__);
    return v8;
  }
  else
  {
    capwait = capwait + 1;
    return 0;
  }
}

// 0x1374bc0
void *evtEventViewerShutdown(dds3ProcessID_t *id) {
  dds3ProcessID_t_o *ida;

  ida = id;
  evtFreeStage();
  evtUnRegistUnit();
  evtFreeViewerInfo();
  dds3GetProcessData(&ida);
  viewerinfo = 0;
  return 0;
}

// 0x136a450
void evtFreeViewerInfo(void) {
  s16 v3;
  s32 v4;
  struct evtViewerInfo_t_o *viewerinfo;
  evtViewerObject_s_o *firstobjinfo;
  pmdProcessWork_t_o *workdata;

  while (1)
  {
    if ((v3 & 0x200) != 0)
      break;
    v4 = 0;
    firstobjinfo = viewerinfo->firstobjinfo;
    if (!firstobjinfo)
      goto LABEL_12;
LABEL_6:
    DelViewerObject(firstobjinfo);
  }
  v4 = v3 & 0x200;
  firstobjinfo = viewerinfo->firstobjinfo;
  if (firstobjinfo)
    goto LABEL_6;
LABEL_12:
  else
  {
    workdata = viewerinfo->workdata;
    if (workdata)
    {
LABEL_15:
      evtFreePolygonMovieWorkData(workdata);
    }
  }
}

// 0x136a030
s32 evtGetAllFrameInfoCount(void) {
  struct evtViewerObject_s_o *firstobjinfo;
  s32 result;
  s32 p;

  firstobjinfo = viewerinfo->firstobjinfo;
  if (!firstobjinfo)
    return 0;
LABEL_6:
  result = 0;
  do
  {
    p = firstobjinfo->data.p;
    firstobjinfo = firstobjinfo->firstframeinfo;
    result += p;
  }
  while (firstobjinfo);
  return result;
}

// 0x1369720
evtFrameInfo_t *evtGetSelectFrameInfo(void) {
  evtEventViewer_c *v2;
  struct evtViewerObject_s_o *framelist_target;
  s32 v4;
  evtFrameInfo_t_o *p;

  framelist_target = viewerinfo->framelist_target;
  if (!framelist_target)
    return 0;
LABEL_6:
  v4 = 0;
  p = framelist_target->p;
  if ((v2->_2.bitflags2 & 2) == 0)
    goto LABEL_11;
LABEL_9:
LABEL_11:
  while (p
       && v4 < viewerinfo->framelist_y + viewerinfo->framelist_base)
  {
    ++v4;
    p = p->work.p;
    if ((v2->_2.bitflags2 & 2) != 0)
      goto LABEL_9;
  }
  return p;
}

// 0x1369f80
s32 evtGetViewerObjectTypeCount(s32 type) {
  struct evtViewerObject_s_o *firstobjinfo;
  s32 result;
  s32 v5;

  firstobjinfo = viewerinfo->firstobjinfo;
  if (!firstobjinfo)
    return 0;
LABEL_6:
  result = 0;
  do
  {
    v5 = firstobjinfo->type;
    firstobjinfo = firstobjinfo->firstframeinfo;
    if (v5 == type)
      ++result;
  }
  while (firstobjinfo);
  return result;
}

// 0x1374c90
void evtInitEventViewer(void) {
  u64 *v1;
  u64 *v2;
  u64 *v3;
  u64 *data;
  u64 *v10;
  u64 *v11;
  dds3ProcessID_t_o *target;
  dds3ProcessID_t_o *parent;

  v1 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v1);
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  parent = v2;
  v3 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v3);
  target = v3;
  dds3BackColor = 0x80000000;
  data = Allocate(evtViewerInfo_t);
  evtViewerInfo_t___ctor(data);
  viewerinfo = data;
  v10 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v10,
    0,
    Method_evtEventViewer_evtEventViewerProcess1__);
  v11 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v11,
    0,
    Method_evtEventViewer_evtEventViewerShutdown__);
  parent = dds3StartProcess("EventViewer", 0x3E8u, 1, 1, v10, 0, v11, 0, data, 0);
  target = evtInitSky();
  dds3LinkProcess(&parent, &target);
}

// 0x136a3a0
void evtInitViewerInfo(void) {
  viewerinfo->stat |= 1u;
  viewerinfo->totalframe = 540;
  viewerinfo->lastframe = viewerinfo->totalframe - 1;
  viewerinfo->framedisp = 1;
}

// 0x1374e90
void evtKillEventViewer(void) {
  dds3KillProcessName("EventViewer", 1);
}

// 0x136e160
void evtRunFrame(s32 nowframe) {
  s32 v3;
  u64 v7;
  evtViewerObject_s_o *firstframeinfo;
  s32 type;
  evtFrameInfo_t_o *p;
  struct pmdDataInfo_t_array *v11;
  struct pmdDataInfo_t_array *v12;
  s32 frame;
  s32 length;
  s32 v16;
  evtFrameInfo_t_o *v17;
  struct pmdDataInfo_t_array *data;
  struct pmdDataInfo_t_array *v19;
  s32 v20;
  struct pmdDataInfo_t_array *v23;
  struct pmdDataInfo_t_array *v24;
  s64 v29;
  evtFrameInfo_t_o *v30;
  evtFrameInfo_t_o *v32;
  struct evtEventViewer_StaticFields *static_fields;
  struct evtViewerObject_s_o *evt_camera;
  u32 stat;
  s32 l;

  l = 0;
  *(**(v7 + 184) + 24LL) &= ~2u;
  *(**(v7 + 184) + 24LL) &= ~4u;
  *(**(v7 + 184) + 168LL) = 0;
  *(**(v7 + 184) + 172LL) = 0;
  *(**(v7 + 184) + 180LL) = 0;
  *(**(v7 + 184) + 184LL) = 0;
  *(**(v7 + 184) + 176LL) = 0;
  *(**(v7 + 184) + 188LL) = 0;
  firstframeinfo = *(**(v7 + 184) + 104LL);
  if (firstframeinfo)
  {
    while (1)
    {
      type = firstframeinfo->type;
      if (type == 1)
      {
        RunFrameUnit(firstframeinfo, nowframe);
        goto LABEL_64;
      }
      p = firstframeinfo->p;
      if (p)
        break;
LABEL_64:
      firstframeinfo = firstframeinfo->firstframeinfo;
      if (!firstframeinfo)
      {
        goto LABEL_66;
      }
    }
    while (1)
    {
      if (type <= 9)
      {
        if (type == 3)
          goto LABEL_43;
        v17 = p;
        if (type != 9)
          goto LABEL_54;
        while (1)
        {
          v17 = v17->work.p;
          if (!v17)
            break;
          data = v17->data;
          v19 = p->data;
          v20 = *&data->m_Items[0].c0;
          if (v20 == *&v19->m_Items[0].c0)
          {
            length = v17->frame - p->frame;
            if (length)
              goto LABEL_23;
            goto LABEL_55;
          }
        }
      }
      else
      {
        if (type != 18)
        {
          if ((type & 0xFFFFFFFE) != 0x14)
          {
LABEL_54:
            length = p->length;
            if (!p->length)
              goto LABEL_55;
            goto LABEL_23;
          }
LABEL_43:
          v23 = p->data;
          if (*&v23->m_Items[0].c2)
          {
            v24 = p->data;
            frame = p->frame;
            length = *&v24->m_Items[0].c2 - frame;
            if (length < 0)
            {
LABEL_48:
              if (frame == nowframe)
                goto LABEL_26;
              goto LABEL_49;
            }
LABEL_22:
            if (!length)
              goto LABEL_55;
            goto LABEL_23;
          }
          goto LABEL_59;
        }
        v11 = p->data;
        if (*&v11->m_Items[0].c0)
        {
          v12 = p->data;
          frame = p->frame;
          length = *&v12->m_Items[0].c0 - frame;
          if (length < 0)
            goto LABEL_48;
          goto LABEL_22;
        }
      }
LABEL_59:
      length = viewerinfo->totalframe - p->frame;
      if (!length)
      {
LABEL_55:
        if (p->frame == nowframe)
          goto LABEL_26;
        goto LABEL_49;
      }
LABEL_23:
      if (length >= 1)
      {
        v16 = p->frame;
        if (v16 <= nowframe && length + v16 > nowframe)
        {
LABEL_26:
          RunFrame1(firstframeinfo, p, nowframe, v3);
          p = p->work.p;
          if (!p)
            goto LABEL_64;
          goto LABEL_14;
        }
      }
LABEL_49:
      OutFrame1(firstframeinfo, p, v3);
      p = p->work.p;
      if (!p)
        goto LABEL_64;
LABEL_14:
      type = firstframeinfo->type;
    }
  }
LABEL_66:
  l = 10000;
  *(*(v7 + 184) + 16LL) = 0;
  v29 = *(**(v7 + 184) + 104LL);
  if (v29)
  {
    while (1)
    {
      v30 = *(v29 + 64);
      if (v30)
        break;
LABEL_73:
      v30 = 0;
      v32 = *(v29 + 72);
        goto LABEL_74;
LABEL_77:
      RunFrame2(v29, v30, v32, nowframe, &l);
      v29 = *(v29 + 80);
      if (!v29)
      {
        goto LABEL_79;
      }
    }
    while (v30->frame <= nowframe)
    {
      v30 = v30->work.p;
      if (!v30)
        goto LABEL_73;
    }
    v32 = v30->p;
      goto LABEL_77;
LABEL_74:
    goto LABEL_77;
  }
LABEL_79:
  static_fields = *(v7 + 184);
  if (evt_camera)
  {
    viewerinfo->gamecamera = evt_camera->basic;
    SetActiveCamera(v7);
  }
  if ((*(v7 + 295) & 2) != 0 && !*(v7 + 216))
  RunFrame3(nowframe);
  stat = viewerinfo->stat;
  if ((stat & 1) != 0)
  {
    if ((stat & 2) == 0)
    {
      dds3StopQuake();
    }
    if ((viewerinfo->stat & 4) == 0)
    {
      dds3ScreenBlurFlag = 0;
    }
  }
}

// 0x136a240
void evtSetFirstFrame(void) {
  struct evtViewerInfo_t_o *viewerinfo;
  s32 firstframe;

  viewerinfo->firstframe = viewerinfo->nowframe;
  firstframe = viewerinfo->firstframe;
  if (firstframe > viewerinfo->lastframe)
  {
    viewerinfo->lastframe = firstframe;
  }
}

// 0x136a2f0
void evtSetLastFrame(void) {
  struct evtViewerInfo_t_o *viewerinfo;
  s32 lastframe;

  viewerinfo->lastframe = viewerinfo->nowframe;
  lastframe = viewerinfo->lastframe;
  if (lastframe < viewerinfo->firstframe)
  {
    viewerinfo->firstframe = lastframe;
  }
}

// 0x136ee60
void evtStopFrame(s32 sw, u32 nowframe) {
  Il2CppObject *workdata;
  void *v7;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v10;
  struct dds3Basic_t_o *namespaze;
  Il2CppObject *v13;
  dds3UnitObjectBasicWorkData_t_c *v14;
  Il2CppClass *v15;
  s64 v16;
  sdfMotionCtrlr_t_o **v17;
  dds3ModelHandle_t_c *v18;
  s64 v19;
  sdfMotionCtrlr_t_o *v20;
  sdfMotionCtrlr_t_o *v21;
  f32 v22;
  Il2CppObject *v23;
  s64 v24;
  sdfMotionCtrlr_t_o **v25;
  s64 v26;
  sdfMotionCtrlr_t_o *v27;
  Il2CppClass *v28;
  dds3Basic_t_o *next;
  Il2CppObject *v31;
  Il2CppClass *v32;
  s64 v33;
  sdfMotionCtrlr_t_o *castClass;
  f32 v35;
  Il2CppObject *v36;
  s64 v37;
  sdfMotionCtrlr_t_o *v38;
  Il2CppClass *v39;
  dds3Basic_t_o *v41;
  struct evtViewerObject_s_o *firstobjinfo;
  char *v62;
  s64 *v63;
  char *v64;
  s64 *v65;
  char *v66;
  s64 *v67;
  char *v68;
  s64 *v69;
  u64 v70[2];
  char *v71;
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = 0;
  else if (!dds3GetActiveScene())
  {
    return;
  }
  workdata = dds3GetActiveScene()->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v70);
    if ((v70[0] & 1) != 0)
      v68 = v71;
    else
      v68 = v70 + 1;
    v69 = sub_8C4940(v68);
  }
  v10 = workdata[2].klass;
  namespaze = v10->_1.castClass->_1.namespaze;
  pObjectBasic = namespaze;
  if (namespaze)
  {
    if (sw)
    {
      while (1)
      {
        v13 = namespaze->workdata;
        v15 = v13->klass;
        if (v13->klass->_2.typeHierarchyDepth < v16
          || v15->_2.typeHierarchy[v16 - 1] != dds3UnitObjectBasicWorkData_t)
        {
          break;
        }
        v17 = *(v13[2].monitor + 5);
        v20 = *v17;
        if (LOBYTE((*v17)[3].klass) < v19 || *(v20[2].monitor + v19 - 1) != dds3ModelHandle_t)
          goto LABEL_109;
        v21 = v17[9];
        sdfMotionPauseOff(v21);
        namespaze = pObjectBasic->next;
        pObjectBasic = namespaze;
        if (!namespaze)
          goto LABEL_34;
      }
    }
    else
    {
      while (1)
      {
        v23 = namespaze->workdata;
        v15 = v23->klass;
        if (v23->klass->_2.typeHierarchyDepth < v24
          || v15->_2.typeHierarchy[v24 - 1] != dds3UnitObjectBasicWorkData_t)
        {
          break;
        }
        v25 = *(v23[2].monitor + 5);
        v20 = *v25;
        if (LOBYTE((*v25)[3].klass) < v26 || *(v20[2].monitor + v26 - 1) != dds3ModelHandle_t)
        {
LABEL_109:
          sub_8FC2C0(*&v20->frame, v18, v70);
          if ((v70[0] & 1) != 0)
            v62 = v71;
          else
            v62 = v70 + 1;
          v63 = sub_8C4940(v62);
        }
        v27 = v25[9];
        v22 = nowframe;
        sdfMotionSeek(v27, v22);
        sdfMotionPause(v25[9]);
        namespaze = pObjectBasic->next;
        pObjectBasic = namespaze;
        if (!namespaze)
          goto LABEL_34;
      }
    }
    sub_8FC2C0(v15->_1.element_class, v14, v70);
    if ((v70[0] & 1) != 0)
      v64 = v71;
    else
      v64 = v70 + 1;
    v65 = sub_8C4940(v64);
  }
LABEL_34:
  v28 = workdata[2].klass;
  next = v28->_1.declaringType->_1.namespaze;
  pObjectBasic = next;
  if (next)
  {
    if (sw)
    {
      while (1)
      {
        v31 = next->workdata;
        v32 = v31->klass;
        if (v31->klass->_2.typeHierarchyDepth < v33
          || v32->_2.typeHierarchy[v33 - 1] != dds3MatterObjectBasicWorkData_t)
        {
          break;
        }
        castClass = v31[1].klass->_1.castClass;
        if (castClass)
        {
          sdfMotionPauseOff(castClass);
          next = pObjectBasic;
        }
        next = next->next;
        pObjectBasic = next;
        if (!next)
          goto LABEL_55;
      }
    }
    else
    {
      while (1)
      {
        v36 = next->workdata;
        v32 = v36->klass;
        if (v36->klass->_2.typeHierarchyDepth < v37
          || v32->_2.typeHierarchy[v37 - 1] != dds3MatterObjectBasicWorkData_t)
        {
          break;
        }
        v38 = v36[1].klass->_1.castClass;
        if (v38)
        {
          v35 = nowframe;
          sdfMotionSeek(v38, v35);
          sdfMotionPause(v38);
          next = pObjectBasic;
        }
        next = next->next;
        pObjectBasic = next;
        if (!next)
          goto LABEL_55;
      }
    }
    sub_8FC2C0(v32->_1.element_class, v7, v70);
    if ((v70[0] & 1) != 0)
      v66 = v71;
    else
      v66 = v70 + 1;
    v67 = sub_8C4940(v66);
  }
LABEL_55:
  v39 = workdata[2].klass;
  v41 = *(*&v39->_1.this_arg.bits + 24LL);
  for (pObjectBasic = v41; v41; pObjectBasic = v41)
  {
    evtStopMover(v41, sw, 0, nowframe);
    v41 = pObjectBasic->next;
  }
  firstobjinfo = viewerinfo->firstobjinfo;
  if (firstobjinfo)
    goto LABEL_65;
}

// 0x136a590
void evtUnRegistUnit(void) {
  evtEventViewer_c *v2;
  s64 v3;
  s64 v4;
  struct pmdProcessWork_t_o *workdata;
  struct pmdUnitTable_t_array *UnitTable;
  struct pmdUnitTable_t_array *v7;
  s32 v9;
  s32 v10;
  u64 *v11;
  u64 *v13;
  s32 v15;
  s32 v16;

  else if (!viewerinfo->workdata)
  {
    return;
  }
  v3 = 4;
  v4 = 0;
  if ((v2->_2.bitflags2 & 2) == 0)
    goto LABEL_11;
LABEL_9:
LABEL_11:
  while (1)
  {
    workdata = viewerinfo->workdata;
    if (v4 >= workdata->UnitCount)
      break;
    UnitTable = workdata->UnitTable;
    v7 = UnitTable;
    v9 = *(*(&UnitTable->obj.klass + v3) + 24LL);
    v10 = *(*(&v7->obj.klass + v3) + 28LL);
    v16 = v9;
    v11 = sub_8D3950(s32, &v16);
    v15 = v10;
    v13 = sub_8D3950(s32, &v15);
    Write_2930752("unregist {0:D}, {1:D}\n", v11, v13, 0);
    mdlUnRegist(v9, v10);
    v4 = ++v3 - 4;
      goto LABEL_9;
  }
}

// 0x136f680
void evtViewerStopFrame(void) {
  s16 v4;
  s32 v5;
  struct evtViewerInfo_t_o *viewerinfo;
  u32 nowframe;
  s32 v8;

  if ((v4 & 0x200) != 0)
  {
    v5 = v4 & 0x200;
    if ((viewerinfo->stat & 1) != 0)
      goto LABEL_5;
  }
  else
  {
    v5 = 0;
    if ((viewerinfo->stat & 1) != 0)
    {
LABEL_5:
      nowframe = viewerinfo->nowframe;
      v8 = 0;
      goto LABEL_9;
    }
  }
  nowframe = viewerinfo->nowframe;
  v8 = 1;
LABEL_9:
  evtStopFrame(v8, nowframe);
}
