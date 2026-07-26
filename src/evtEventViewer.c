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
static evtEventViewer_p4_func menuenter[UNKNOWN_ARRAY_SIZE];

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
    dds3AddBEDEffectObjectBasic2(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3EffectObjectBasicStatOn(0, 0);
    dds3StartBEDEffectObjectBasic(0, 0);
    LinkEffectBasic(0, 0, 0, 0);
    return 0;
}

// 0x136ad40
s32 AddEffectTable2(s32 nowframe, evtViewerObject_s *obj, evtFrameInfo_t *f) {
    dds3AddD3PEffectObjectBasic2(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3EffectObjectPresetMG12(0);
    LinkEffectBasic(0, 0, 0, 0);
    SearchBasicFromNameIndex(0);
    dds3EffectObjectSetMG12Pos(0, 0, 0, 0, 0);
    dds3AddMG12EffectObjectBasic2(0, 0);
    dds3EffectObjectBasicStatOn(0, 0);
    return 0;
}

// 0x13696a0
evtFrameInfo_t *AddFrameInfo2(evtViewerObject_s *parent, s32 frame) {
  return evtAddFrameInfo(parent, frame);
}

// 0x1368690
void DelBED(evtFrameInfo_t *frame) {
    dds3DeleteSceneBasicData(0);
}

// 0x1368530
void DelEffectTable(s32 no) {
    dds3DeleteSceneBasicData(0);
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
  if (v6 == 18)
  {
    DelBED(v7);
  }
  if ((v6 & 0xFFFFFFFE) == 0x14)
  {
    data = SelectFrameInfo->data;
    if ((data->m_Items[0].c0 & 0x80000000) == 0)
    {
      v11 = SelectFrameInfo->data;
      c0 = v11->m_Items[0].c0;
      DelEffectTable(c0);
    }
  }
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
    }
    if ((byte_3F59514 & 1) != 0)
  }
  UnlinkViewerObject(obj);
}

// 0x136e6e0
void DrawActiveCameraName(void) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
    sdfDrawTagLinkOt(0, 0);
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
    }
  }
  else
  {
    Eve_PartialMultiBlurOFF();
  }
  if (viewerinfo->drawmfilter)
  {
    Eve_PartialMultiFilterON();
    {
    }
  }
  else
  {
    Eve_PartialMultiFilterOFF();
  }
  if (viewerinfo->drawdblur)
  {
    Eve_DistortionBlurON();
    {
    }
  }
  else
  {
    Eve_DistortionBlurOFF();
  }
  if (viewerinfo->drawrblur)
  {
    Eve_RippleBlurON();
    {
    }
  }
  else
  {
    Eve_RippleBlurOFF();
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
    evtGetSelectFrameInfo();
    dds3GetActiveScene();
    evtAddNameTable(0);
    dds3SceneBasicSearchNameAndType(0, 0, 0);
    evtGetUnitHandle2(0);
    evtUnlinkLightObjectBasic(0, 0);
    evtRunFrame(0);
    PopMenu();
    return 0;
}

// 0x1373830
s32 EnterData(s32 s, s32 prevmenu) {
    evtGetSelectFrameInfo();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    Eve_BlurEditorGetParams();
    Eve_PartialMultiBlurEditorGetParams2();
    Eve_DistortionBlurEditorGetParams2();
    Eve_FilterEditorGetParams2();
    Eve_PartialMultiFilterEditorGetParams2();
    Eve_RippleBlurEditorGetParams2();
    evtRunFrame(0);
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
    evtViewerLoadGameData(0);
    evtViewerSaveGameData(0);
    return 0;
}

// 0x13726c0
s32 EnterFrameChange(s32 s, s32 prevmenu) {
  evtFrameInfo_t_o *SelectFrameInfo;
  evtFrameInfo_t_o *v6;
  evtEventViewerMenu_c *v7;
  struct evtEventViewerMenu_StaticFields *static_fields;
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
    static_fields = v7->static_fields;
    evtFrameList = static_fields->evtFrameList;
    type = viewerinfo->framelist_target->type;
    v14 = evtFrameList + 8 * type;
    framelist_x = viewerinfo->framelist_x;
    v16 = *(*(v14 + 32) + 24LL);
    v18 = *(v16 + framelist_x + 32);
    if (v18 == 15)
    {
      v6->length = viewerinfo->value;
    }
    else
    {
      if (v18 == 9)
      {
        v24 = viewerinfo;
        v25 = v24->framelist_target->type;
        if (v25 == 3)
        if (v25 == 18)
        {
          data = v6->data;
          *&data->m_Items[0].c0 = v24->value;
        }
        if ((v25 & 0xFFFFFFFE) == 0x14)
        {
          v28 = v6->data;
          *&v28->m_Items[0].c2 = v24->value;
        }
      }
      else if (!*(v16 + framelist_x + 32))
      {
        v6->frame = viewerinfo->value;
        SortFrameInfo(viewerinfo->framelist_target);
        evtRunFrame(viewerinfo->nowframe);
      }
      {
        PopMenu(v21);
        return 0;
      }
    }
    if (!*(v21 + 216))
  }
  return 0;
}

// 0x1370c10
s32 EnterFrameList(s32 s, s32 prevmenu) {
    PushMenu(0, 0, 0);
    evtGetSelectFrameInfo();
    SDF_RADtoDEG(0);
    dds3SetLightColor(0, 0, (sdfVector4_t){0});
    dds3SetLightDir(0, 0, (sdfVector4_t){0});
    dds3SetAmbientColor(0, (sdfVector4_t){0});
    dds3SetFogPara(0, 0, 0, 0, 0);
    Eve_BlurSetParam2(0);
    Eve_PartialMultiBlurSetParam2(0);
    Eve_DistortionBlurSetParam2(0);
    Eve_FilterSetParam2(0);
    Eve_PartialMultiFilterSetParam2(0);
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    Eve_RippleBlurSetParam2(0);
    evtAddFrameInfo(0, 0);
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
  evtEventViewerMenu_c *v10;
  struct evtEventViewerMenu_StaticFields *static_fields;
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
        viewerinfo->totalframe = value + 1;
      }
    }
    else  }
  if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
  SelectFrameInfo = evtGetSelectFrameInfo(v3);
  if (SelectFrameInfo)
  {
    v9 = SelectFrameInfo;
    static_fields = v10->static_fields;
    evtFrameList = static_fields->evtFrameList;
    v14 = viewerinfo;
    type = v14->framelist_target->type;
    v17 = evtFrameList + 8 * type;
    framelist_x = v14->framelist_x;
    v19 = *(*(v17 + 32) + 24LL);
    switch (*(v19 + framelist_x + 32))
    {
      case 1:
        v9->length = value;
      case 2:
        if (viewerinfo->framelist_target->type != 7)
      case 3:
        v31 = viewerinfo->framelist_target->type;
        if (v31 == 12)
        if (v31 != 8)
      case 4:
      case 7:
      case 6:
        data = v9->data;
        v25 = SDF_DEGtoRAD(fvalue);
        *&data->m_Items[0].c0 = v25;
      case 8:
        v33 = viewerinfo->framelist_target->type;
        if (v33 <= 5)
        {
          if (v33 == 3)
          {
            v34 = v9->data;
            BYTE1(v34->m_Items[0].i) = value;
          }
          if (v33 == 5)
          {
            v28 = v9->data;
            *&v28->m_Items[0].c0 = value;
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
            }
            else
            {
              if (v33 != 19)
              v21 = v9->data;
              *&v21->m_Items[0].c2 = value;
              {
              }
            }
            evtRunFrame(viewerinfo->nowframe);
            PopMenu(v3);
            return 0;
          }
          v38 = v9->data;
          v38->m_Items[0].i = value;
        }
      default:
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
      if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
      {
        p_static_fields = &evtEventViewer->static_fields;
      }
      viewerinfo->filename_x = 0;
      v7 = 9;
      v8 = 228;
      (*p_static_fields)->viewerinfo->filename_y = 0;
    case 3:
    case 4:
      if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
      {
        p_static_fields = &evtEventViewer->static_fields;
      }
      viewerinfo->select_y = 0;
      (*p_static_fields)->viewerinfo->select_max = 2;
      (*p_static_fields)->viewerinfo->select_header = StringLiteral_15795;
      (*p_static_fields)->viewerinfo->select_str = (*p_static_fields)->EnterMain_yesnomes;
      v8 = 228;
      v7 = 2;
      v9 = 60;
    case 5:
      if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
      {
        p_static_fields = &evtEventViewer->static_fields;
      }
      viewerinfo->value = viewerinfo->totalframe - 1;
      (*p_static_fields)->viewerinfo->min = (*p_static_fields)->viewerinfo->lastframe;
      (*p_static_fields)->viewerinfo->max = 10000;
      v8 = 180;
      v7 = 7;
      v9 = 120;
      PushMenu(v7, v8, v9);
      result = 0;
      break;
    case 6:
      if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
      {
        p_static_fields = &evtEventViewer->static_fields;
      }
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
          }
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
            }
            if ((v15 & 0xFFFFFFFE) == 0x14)
            {
              v34 = SelectFrameInfo->data;
              v34->m_Items[0].c1 = viewerinfo->select_y;
            }
          }
        }
        v28 = viewerinfo->framelist_target->type;
        if (v28 <= 6)
        {
          if (v28 == 1)
          {
            v38 = SelectFrameInfo->data;
            v38->m_Items[0].c0 = viewerinfo->select_y;
          }
          if (v28 != 6)
        }
        else if (v28 != 19)
        {
          if (v28 == 12)
          {
            v29 = SelectFrameInfo->data;
            *&v29->m_Items[0].c0 = viewerinfo->select_y;
            *(**(v12 + 184) + 156LL) = 0;
          }
        }
      }
      v36 = SelectFrameInfo->data;
      *&v36->m_Items[0].c0 = viewerinfo->select_y;
    }
    if (framelist_type == -1)
    {
      if (!viewerinfo->select_y)
      {
        if ((*(v12 + 295) & 2) != 0 && !*(v12 + 216))
        DelFrameInfo2(v12);
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
          }
        }
      }
    }
    {
      evtRunFrame(viewerinfo->nowframe);
      PopMenu(v4);
      return 0;
    }
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
      }
      else
      {
        v8 = 0;
        if (!v5->select_y)
        {
          if (v8 && !*(v4 + 216))
          viewerinfo->firstframe = viewerinfo->nowframe;
          v22 = viewerinfo;
          firstframe = v22->firstframe;
          if (firstframe <= v22->lastframe)
            return -1;
          v22->lastframe = firstframe;
          return -1;
        }
      }
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
    if (v8 && !*(v4 + 216))
  }
  v8 = 0;
  if (v5->select_y)
  if (v8 && !*(v4 + 216))
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
  if (viewerinfo->nowframe <= 0)
    v4 = 0;
  else
    v4 = -1;
  if (!DDS3_PADCHECK_REP2(5))
  if (viewerinfo->nowframe < viewerinfo->totalframe - 1)
    v4 = 1;
  if (DDS3_PADCHECK_REP2(6))
    v4 = -10;
  if (DDS3_PADCHECK_REP2(7))
    v4 = 10;
  else  nowframe = viewerinfo->nowframe;
  firstframe = viewerinfo->firstframe;
  if (nowframe == firstframe)
  {
    if (!v4)
      return;
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
    }
    else if ((*(v16 + 295) & 2) == 0)
    {
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
      if ((*(v16 + 295) & 2) != 0 && !*(v16 + 216))
      evtViewerStopFrame(v16);
      return;
    }
  }
  v4 = firstframe - nowframe;
  if (firstframe != nowframe)
}

// 0x136a9f0
void LinkEffectBasic(dds3Basic_t *eff, s32 nameindex, s32 posindex, s32 baseframe) {
    dds3GetActiveScene();
    dds3SceneBasicSearchName(0, 0);
    DDS3_GETBASICTYPEL(0);
    dds3EffectObjectBasicLinkObject(0, 0);
    dds3EffectObjectBasicLinkObjectIndex(0, 0, 0);
    evtPathLinkAndMake(0, 0);
    dds3GetBaseControlWorkData(0);
    evtStopMover(0, 0, 0, 0);
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
  }
  else
  {
    v4 = 0;
    sp = viewerinfo->sp;
    if (sp)
    {
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
    viewerinfo->fileext = StringLiteral_416;
  }
}

// 0x136b7f0
void RunFrame1(evtViewerObject_s *obj, evtFrameInfo_t *frame, s32 nowframe, s32 length) {
    AddEffectTable2(0, 0, 0);
    evtEffectLoopControl(0, 0);
    SearchBasicFromNameIndex(0);
    dds3EffectObjectSetMG12Pos(0, 0, 0, 0, 0);
    DelEffectTable(0);
    evtPlaySe(0, 0);
    dds3SetQuake(0, 0);
    dds3StopQuake();
    DelBED(0);
    AddBED(0, 0, 0, 0, 0);
}

// 0x136bfb0
void RunFrame2(evtViewerObject_s *obj, evtFrameInfo_t *frame, evtFrameInfo_t *nearframe, s32 nowframe, s32 *l) {
    dds3FadeSet(0, 0, 0, 0);
    dds3FadeClear();
    evtHokanSceneLight(0, 0, 0, 0, 0);
    dds3SetLightColor(0, 0, (sdfVector4_t){0});
    dds3SetLightDir(0, 0, (sdfVector4_t){0});
    dds3SetAmbientColor(0, (sdfVector4_t){0});
    evtHokanFloat(0, 0, 0, 0);
    evtHokanSceneFog(0, 0, 0, 0, 0);
    dds3SetFogPara(0, 0, 0, 0, 0);
    evtCheckSkyAlphaAnime();
    fldSkyGetAlpha();
    evtSetSkyAlpha(0, 0);
    fldSkySetFilter(0, 0, 0);
    evtHokanBlur2(0, 0, 0, 0, 0);
    Eve_BlurSetParam2(0);
    evtHokanMultBlur(0, 0, 0, 0, 0);
    Eve_PartialMultiBlurSetParam(0);
    evtHokanDistBlur(0, 0, 0, 0, 0);
    Eve_DistortionBlurSetParam(0);
    evtHokanFilter(0, 0, 0, 0, 0);
    Eve_FilterSetParam(0);
    evtHokanMultFilter(0, 0, 0, 0, 0);
    Eve_PartialMultiFilterSetParam(0);
    evtSetBokasi(0);
    evtHokanRipBlur(0, 0, 0, 0, 0);
    Eve_RippleBlurSetParam(0);
}

// 0x136db40
void RunFrame3(s32 nowframe) {
    dds3GetActiveScene();
    dds3SceneBasicSearchNameAndType(0, 0, 0);
    evtGetUnitHandle2(0);
    evtUnlinkLightObjectBasic(0, 0);
    evtLinkLightObjectBasic(0, 0, 0);
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
    return 0;
}

// 0x136e9b0
void SelectActiveCamera(void) {
    dds3GetActiveScene();
    DDS3_PADCHECK_TRIG(0);
    SetActiveCamera();
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
      pCameraBasic = viewerinfo->activecamera;
      if (!pCameraBasic)
        return;
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
  }
  if (viewerinfo->gamecamera)
  {
    pCameraBasic = viewerinfo->gamecamera;
    if (pCameraBasic)
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
          while (LOWORD(p->bounds) <= LOWORD(klass[1].klass))
          {
            klass = klass[3].klass;
            if (!klass)
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
  }
  viewerinfo->lastobjinfo = obj->lastframeinfo;
  *p_firstframeinfo = 0;
  obj->lastframeinfo = 0;
  --viewerinfo->objcnt;
}

// 0x1368a30
evtFrameInfo_t *evtAddFrameInfo(evtViewerObject_s *parent, s32 frame) {
    evtAddNameTable(0);
    SDF_DEGtoRAD(0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    Eve_BlurEditorGetParams();
    Eve_PartialMultiBlurEditorGetParams();
    Eve_DistortionBlurEditorGetParams();
    Eve_FilterEditorGetParams();
    Eve_PartialMultiFilterEditorGetParams();
    Eve_RippleBlurEditorGetParams();
    return 0;
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
  if ((v16 & 0x200) != 0)
  {
    v17 = v16 & 0x200;
    v18 = viewerinfo;
    if (v18->framedisp)
  }
  else
  {
    v17 = 0;
    v18 = viewerinfo;
    if (v18->framedisp)
    {
      v18->framedisp = 0;
    }
  }
  v18->framedisp = 1;
  {
  }
  if (DDS3_PADCHECK_TRIG(12))
  {
    *(v21[2].klass->_1.image + 6) ^= 1u;
    evtViewerStopFrame();
  }
  if ((*(**(v22 + 184) + 24LL) & 1) != 0)
  {
    if ((*(v22 + 295) & 2) != 0 && !*(v22 + 216))
    FrameSelect(v22);
  }
  if ((*(v22 + 295) & 2) == 0 || *(v22 + 216))
  {
    v23 = **(v22 + 184);
    if ((v23->stat & 1) == 0)
    return 0;
  }
  v23 = viewerinfo;
  if ((v23->stat & 1) != 0)
    return 0;
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
  }
  else
  {
    v25 = 0;
    v26 = v23->nowframe;
    if (v26 >= v23->lastframe)
    {
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
  evtEventViewer_c *v6;
  u64 v7;
  Il2CppClass **v8;
  struct evtEventViewer_StaticFields *static_fields;
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
  evtEventViewer_c *v31;
  evtEventViewer_c *v32;
  struct evtEventViewer_StaticFields *v33;
  struct evtEventViewer_p4_func_array *menuenter;
  struct menuinfo_t_array *v35;
  s64 v37;
  s32 v39;
  u64 *v40;
  bool v41;
  struct evtEventViewer_StaticFields *v42;
  s16 v43;
  evtEventViewer_c *v44;
  evtEventViewer_c *v47;
  struct evtViewerInfo_t_o *v48;
  dds3ProcessID_t_o **p_pid;
  struct evtEventViewer_StaticFields **p_static_fields;
  struct evtViewerInfo_t_o *v51;
  s32 menusw;
  evtEventViewer_c *v53;
  struct evtEventViewer_StaticFields **v54;
  struct evtViewerInfo_t_o *v55;

  DrawEffect();
  v4 = 0;
  name_low = 0;
  v7 = 1;
  {
  }
  while (1)
  {
    static_fields = v6->static_fields;
    viewerinfo = static_fields->viewerinfo;
    if (v7 > static_fields->viewerinfo->sp)
    menustack = viewerinfo->menustack;
    y = menustack->m_Items[v4 + 1]->y;
    v14 = static_fields->winoff_x + menustack->m_Items[v4 + 1]->x;
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
  }
  if (v19 != -1)
  {
    v33 = v32->static_fields;
    menuenter = v33->menuenter;
    v35 = v33->viewerinfo->menustack;
    v37 = v35->m_Items[v4 + 1]->menu;
    v39 = Invoke(menuenter->m_Items[v37].func, v19, name_low, 0);
    if (v39 == -1)
    {
      v30 = 1;
    }
    else
    {
      if (v39 == 1)
      {
        v40 = Allocate(dds3ProcessFunc_t);
        dds3ProcessFunc_t___ctor(v40, 0, Method_evtEventViewer_evtEventViewerProcess5_0__);
        return v40;
      }
      v30 = 0;
    }
  }
  PopMenu();
  v30 = 0;
  if (winoff_x <= 10)
  {
    v41 = DDS3_PADCHECK_PRESS(9);
    if (v41)
    {
      v42 = v31->static_fields;
      v43 = v42->winoff_x + 10;
      v42->winoff_x = v43;
    }
  }
  else  if (DDS3_PADCHECK_PRESS(11))
  {
    v42 = v44->static_fields;
    v43 = v42->winoff_x - 10;
  }
  else  v48 = viewerinfo;
  if (v48->pid)
  {
    p_pid = &v48->pid;
    dds3KillProcess(p_pid, 1);
    viewerinfo->pid = 0;
  }
  p_static_fields = &v47->static_fields;
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
  }
  v54 = &v53->static_fields;
  v55 = viewerinfo;
  if (v30)
  if (v55->nowmenu)
    return 0;
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
    evtRunFrame(0);
    DrawEffect();
    DDS3_PADCHECK_PRESS(0);
    dds3ScreenCaptureOff();
    evtViewerStopFrame();
    return 0;
}

// 0x1370100
dds3ProcessFunc_t *evtEventViewerProcess5_0(dds3ProcessID_t *id) {
  evtEventViewer_c *v2;
  s16 v3;
  s32 v4;
  struct evtEventViewer_StaticFields *static_fields;
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
  p_static_fields = &v2->static_fields;
  static_fields = v2->static_fields;
  capwait = static_fields->capwait;
  if (capwait == 3)
  {
    static_fields->capwait = 0;
    (*p_static_fields)->viewerinfo->oldframe = (*p_static_fields)->viewerinfo->nowframe;
    v8 = Allocate(dds3ProcessFunc_t);
    dds3ProcessFunc_t___ctor(v8, 0, Method_evtEventViewer_evtEventViewerProcess5__);
    return v8;
  }
  else
  {
    static_fields->capwait = capwait + 1;
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
    DelViewerObject(firstobjinfo);
  }
  v4 = v3 & 0x200;
  firstobjinfo = viewerinfo->firstobjinfo;
  if (firstobjinfo)
  else
  {
    workdata = viewerinfo->workdata;
    if (workdata)
    {
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
  v4 = 0;
  p = framelist_target->p;
  if ((v2->_2.bitflags2 & 2) == 0)
  while (p
       && v4 < viewerinfo->framelist_y + viewerinfo->framelist_base)
  {
    ++v4;
    p = p->work.p;
    if ((v2->_2.bitflags2 & 2) != 0)
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
  parent = dds3StartProcess(StringLiteral_15807, 0x3E8u, 1, 1, v10, 0, v11, 0, data, 0);
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
  dds3KillProcessName(StringLiteral_15807, 1);
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
      }
      p = firstframeinfo->p;
      if (p)
        break;
      firstframeinfo = firstframeinfo->firstframeinfo;
    }
    while (1)
    {
      if (type <= 9)
      {
        if (type == 3)
        v17 = p;
        if (type != 9)
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
          }
        }
      }
      else
      {
        if (type != 18)
        {
          if ((type & 0xFFFFFFFE) != 0x14)
          {
            length = p->length;
            if (!p->length)
          }
          v23 = p->data;
          if (*&v23->m_Items[0].c2)
          {
            v24 = p->data;
            frame = p->frame;
            length = *&v24->m_Items[0].c2 - frame;
            if (length < 0)
            {
              if (frame == nowframe)
            }
            if (!length)
          }
        }
        v11 = p->data;
        if (*&v11->m_Items[0].c0)
        {
          v12 = p->data;
          frame = p->frame;
          length = *&v12->m_Items[0].c0 - frame;
          if (length < 0)
        }
      }
      length = viewerinfo->totalframe - p->frame;
      if (!length)
      {
        if (p->frame == nowframe)
      }
      if (length >= 1)
      {
        v16 = p->frame;
        if (v16 <= nowframe && length + v16 > nowframe)
        {
          RunFrame1(firstframeinfo, p, nowframe, v3);
          p = p->work.p;
          if (!p)
        }
      }
      OutFrame1(firstframeinfo, p, v3);
      p = p->work.p;
      if (!p)
      type = firstframeinfo->type;
    }
  }
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
      v30 = 0;
      v32 = *(v29 + 72);
      RunFrame2(v29, v30, v32, nowframe, &l);
      v29 = *(v29 + 80);
    }
    while (v30->frame <= nowframe)
    {
      v30 = v30->work.p;
      if (!v30)
    }
    v32 = v30->p;
  }
  static_fields = *(v7 + 184);
  evt_camera = static_fields->evt_camera;
  if (evt_camera)
  {
    if ((*(v7 + 295) & 2) != 0 && !*(v7 + 216))
    {
      static_fields = evtEventViewer->static_fields;
      evt_camera = static_fields->evt_camera;
    }
    static_fields->viewerinfo->gamecamera = evt_camera->basic;
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
    dds3GetActiveScene();
    sdfMotionPauseOff(0);
    sdfMotionSeek(0, 0);
    sdfMotionPause(0);
    evtStopMover(0, 0, 0, 0);
    dds3GetBaseControlWorkData(0);
}

// 0x136a590
void evtUnRegistUnit(void) {
    mdlUnRegist(0, 0);
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
  }
  else
  {
    v5 = 0;
    if ((viewerinfo->stat & 1) != 0)
    {
      nowframe = viewerinfo->nowframe;
      v8 = 0;
    }
  }
  nowframe = viewerinfo->nowframe;
  v8 = 1;
  evtStopFrame(v8, nowframe);
}
