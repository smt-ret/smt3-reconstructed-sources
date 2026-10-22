#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effBTL_SkillLight_t effBTL_SkillLight_t;
typedef struct effBTL_SkillModel_t effBTL_SkillModel_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbE904_funcDelegate nbE904_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;

static nbE904_funcDelegate *func[2];
static dds3Basic_t *pPBCameraBasicCurrent;
static dds3Basic_t *pPBCameraBasic00;
static dds3Basic_t *pPBCameraBasic01;
static s32 pPBCameraBasicIndex;

void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void effBTLModelColorSet(effBTL_SkillModel_t **pModel, nbFormation_t **pFormation);
void effBTLPointLightSet(effBTL_SkillLight_t **pLight, nbFormation_t **pFormation);
void effBTLSkillEnd(void);
void effBTLSkillStart(u32 id, u32 stat);
void effBTL_SkillLight_t__Clear(effBTL_SkillLight_t *this);
void effBTL_SkillModel_t__Clear(effBTL_SkillModel_t *this);
void effPadVibeFadeOUT(u32 mode, u8 power, s32 frame);
u8 **evtGetResorceData(s32 eventno, s32 rid);
s32 evtRegistBEUnit(s32 eventno, s32 rid);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
nbKoukaPacket_t *nbAddFadeOutKoukaPacket(s32 startframe, s32 uniqueid, s32 length, s32 coltype);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket3(s32 startframe, s32 uniqueid, u8 **bed, s32 cutno, nbFormation_t **form);
void nbCameraHelperModelSet(dds3ModelHandle_t *hModel);
void nbCameraSetState(u16 state);
void nbEventPrefabDelete(dds3Basic_t **pathbasic);
void nbEventPrefabRead(dds3Basic_t **pathbasic, s32 event_no, s32 index);
void nbPanelAllHide(void);
void nbResetFormPosRot(nbFormation_t **form);
void nbSetFormPos(nbFormation_t **form, sdfVector4_t pos);
void nbSingleFormExceptedDispOff(nbFormation_t **form);
void nbUpdateEventProcessData(dds3ProcessID_t **id);

// 0x16f30c0
u32 DDS3EFFECT_RGBA(u32 r, u32 g, u32 b, u32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x16f32e0
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 191)
    return 0;
  Write("バアル死亡\n", 0);
  ed->data->endtype = 1;
  return 1;
}

// 0x16f30d0
s32 Test(nbEventProcessData_t *ed) {
  struct nbFormation_t_array *v3;
  evtUnitHandle_t_o **p_hunit;
  System_Byte_array *ResorceData;
  System_Byte_array *v10;
  nbFormation_t_o *form;
  UnityEngine_Vector4_o v14;

  form = 0;
  v3 = ed->data->form;
  form = v3->m_Items[5];
  nbPanelAllHide();
  nbSingleFormExceptedDispOff(&form);
  p_hunit = &form->hunit;
  evtSetUnitMotion(p_hunit, 23, 0, 0, 2);
  ResorceData = evtGetResorceData(904, 1);
  nbAddSkillEffectKoukaPacket3(0, 0, ResorceData, 2, &form);
  v10 = evtGetResorceData(904, 2);
  nbAddSkillEffectKoukaPacket3(0, 0, v10, 2, &form);
  nbAddFadeOutKoukaPacket(90, 0, 70, 1);
  nbResetFormPosRot(&form);
  v14.x = -111.43;
  v14.y = 0.0;
  v14.z = 394.81;
  v14.w = 0.0;
  nbSetFormPos(&form, v14);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f3380
void *nbE904Process_1(dds3ProcessID_t *id) {
  u64 *v2;
  u64 *v3;
  u64 *v4;
  Il2CppObject *ProcessData;
  nbEventProcessData_t_o *v10;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  struct nbE904_funcDelegate_array *func;
  s64 seq;
  s32 time;
  dds3ModelHandle_t_o *Model;
  s32 v28;
  s32 v30;
  struct dds3Basic_t_o *v31;
  s32 v35;
  s32 v37;
  struct dds3Basic_t_o **p_pPBCameraBasic01;
  s32 eventrid;
  s32 v44;
  dds3Basic_t_o *v47;
  s32 v49;
  s32 pPBCameraBasicIndex;
  s32 v54;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v57;
  effBTL_SkillLight_t_o *v58;
  effBTL_SkillLight_t_o *v59;
  effBTL_SkillModel_t_o *v60;
  u8 v62;
  u32 v63;
  dds3Basic_t_o *pBasic;
  nbFormation_t_o *pFormation;
  effBTL_SkillModel_t_o *pModel;
  effBTL_SkillLight_t_o *pLight;
  evtUnitHandle_t_o *h;
  dds3ProcessID_t_o *ida;
  u64 v71[3];

  ida = id;
  pBasic = 0;
  pFormation = 0;
  v2 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v2);
  h = v2;
  v3 = Allocate(effBTL_SkillLight_t);
  effBTL_SkillLight_t___ctor(v3);
  pLight = v3;
  effBTL_SkillLight_t__Clear(v3);
  v4 = Allocate(effBTL_SkillModel_t);
  effBTL_SkillModel_t___ctor(v4);
  pModel = v4;
  effBTL_SkillModel_t__Clear(v4);
  pBasic = dds3GetActiveScene();
  ProcessData = dds3GetProcessData(&ida);
  v10 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbEventProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v71);
      if ((v71[0] & 1) != 0)
        v13 = v71[2];
      else
        v13 = v71 + 1;
      v14 = sub_8C4940(v13);
    }
  }
  seq = v10->seq;
  if (Invoke(func->m_Items[seq], v10))
  {
    pPBCameraBasicCurrent = 0;
    if (pPBCameraBasic00)
    {
      nbEventPrefabDelete(&pPBCameraBasic00);
      dds3DeleteSceneBasicData(&pPBCameraBasic00);
      pPBCameraBasic00 = 0;
    }
    if (pPBCameraBasic01)
    {
      nbEventPrefabDelete(&pPBCameraBasic01);
      dds3DeleteSceneBasicData(&pPBCameraBasic01);
      pPBCameraBasic01 = 0;
    }
    effBTLSkillEnd();
    ida->func_ans = -1;
    return 0;
  }
  time = v10->time;
  if (time >= 1)
  {
    if (pPBCameraBasicCurrent)
    {
      h = dds3GetUnitHandleObjectBasic(&pPBCameraBasicCurrent);
      Model = h->Model;
      if (Model)
      {
        nbCameraHelperModelSet(Model);
      }
    }
    time = v10->time;
  }
  if (time == 20)
  {
    eventrid = v10->eventrid;
    v44 = evtRegistBEUnit(eventrid, 4);
    v47 = dds3SearchSceneBasic(&pBasic, v44, 5u);
    pPBCameraBasic01 = v47;
    pPBCameraBasicIndex = 4;
    v49 = v10->eventrid;
    nbEventPrefabRead(&pPBCameraBasic01, v49, pPBCameraBasicIndex);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic01);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    p_pPBCameraBasic01 = &pPBCameraBasic01;
  }
  else
  {
    if (time)
      goto LABEL_115;
    nbCameraSetState(0x17u);
    pPBCameraBasicCurrent = 0;
    pPBCameraBasic00 = 0;
    pPBCameraBasic01 = 0;
    v28 = v10->eventrid;
    v30 = evtRegistBEUnit(v28, 3);
    v31 = dds3SearchSceneBasic(&pBasic, v30, 5u);
    pPBCameraBasic00 = v31;
    pPBCameraBasicIndex = 3;
    v35 = v10->eventrid;
    v37 = pPBCameraBasicIndex;
    nbEventPrefabRead(&pPBCameraBasic00, v35, v37);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic00);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    p_pPBCameraBasic01 = &pPBCameraBasic00;
  }
  pPBCameraBasicCurrent = *p_pPBCameraBasic01;
LABEL_115:
  v54 = v10->time;
  if (v54 == 1)
  {
    form = v10->data->form;
    v57 = form->m_Items[5];
    v58 = pLight;
    pFormation = v57;
    pLight->pos_ptr->target = 0;
    v58->pos_ptr->height = 2;
    v58->pos_ptr->direction = 0;
    v58->pos_ptr->radius = 0;
    v59 = v58;
    {
      v59 = v58;
    }
    v58->diffuse = -2130712833;
    v59->ambient = -2145509858;
    v59->color_anim->fade_in_frame = 25;
    v59->color_anim->fade_in_pattern = 1;
    v59->color_anim->fade_out_frame = 180;
    v59->color_anim->fade_out_pattern = 1;
    v60 = pModel;
    pModel->color = -2143536068;
    v60->color_anim->fade_in_frame = 120;
    v60->color_anim->fade_in_pattern = 3;
    v60->color_anim->fade_out_frame = 200;
    v60->color_anim->fade_out_pattern = 0;
    effBTLPointLightSet(&pLight, &pFormation);
    effBTLModelColorSet(&pModel, &pFormation);
  }
  else
  {
    if (v54)
      goto LABEL_131;
    effBTLSkillStart(0x201u, 0);
  }
  v54 = v10->time;
LABEL_131:
  if (v54 <= 70)
  {
    if (v54 <= 43)
    {
      if (v54 <= 20)
      {
        if (v54)
        {
          if (v54 != 20)
            goto LABEL_186;
          goto LABEL_176;
        }
        goto LABEL_181;
      }
      if (v54 == 23)
        goto LABEL_181;
      if (v54 != 40)
      {
        if (v54 == 43)
          goto LABEL_181;
        goto LABEL_186;
      }
      goto LABEL_176;
    }
    if (v54 > 53)
    {
      if (v54 != 60)
      {
        if (v54 == 63)
          goto LABEL_181;
        if (v54 != 70)
          goto LABEL_186;
        goto LABEL_167;
      }
      goto LABEL_176;
    }
    if (v54 == 50)
      goto LABEL_167;
    if (v54 == 53)
      goto LABEL_181;
  }
  else
  {
    if (v54 > 103)
    {
      if (v54 > 122)
      {
        if (v54 != 125)
        {
          if (v54 != 140)
          {
            if (v54 == 143)
            {
              dds3PadAct(0, 0, 0x14u);
              effPadVibeFadeOUT(1u, 0x6Eu, 50);
            }
            goto LABEL_186;
          }
          goto LABEL_176;
        }
LABEL_181:
        dds3PadAct(0, 0, 0x14u);
        v62 = 110;
        v63 = 20;
        goto LABEL_185;
      }
      if (v54 != 110)
      {
        if (v54 == 113)
          goto LABEL_181;
        if (v54 != 122)
          goto LABEL_186;
LABEL_167:
        dds3PadAct(0, 1u, 4u);
        v62 = -56;
        goto LABEL_180;
      }
      goto LABEL_176;
    }
    if (v54 > 90)
    {
      if (v54 == 93)
        goto LABEL_181;
      if (v54 != 100)
      {
        if (v54 == 103)
          goto LABEL_181;
        goto LABEL_186;
      }
      goto LABEL_167;
    }
    if (v54 == 73)
      goto LABEL_181;
    if (v54 == 90)
    {
LABEL_176:
      dds3PadAct(0, 1u, 4u);
      v62 = -1;
LABEL_180:
      v63 = 3;
LABEL_185:
      dds3PadAct(1u, v62, v63);
    }
  }
LABEL_186:
  nbUpdateEventProcessData(&ida);
  return 0;
}
