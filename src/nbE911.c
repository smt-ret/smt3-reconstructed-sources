#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effBTL_SkillLight_t effBTL_SkillLight_t;
typedef struct effBTL_SkillModel_t effBTL_SkillModel_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbE911_funcDelegate nbE911_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

static s32 NB_HELP_TYPE_TXTCONV;
static dds3Basic_t *basic1;
static dds3Basic_t *basic2;
static nbE911_funcDelegate *func[4];
static dds3Basic_t *pPBCameraBasicCurrent;
static dds3Basic_t *pPBCameraBasic00;
static dds3Basic_t *pPBCameraBasic01;
static dds3Basic_t *pPBCameraBasic02;
static s32 pPBCameraBasicIndex;

u8 Get(s32 id);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void dds3SetQuake(s32 frame, u32 range);
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
nbKoukaPacket_t *nbAddHitEffKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket3(s32 startframe, s32 uniqueid, u8 **bed, s32 cutno, nbFormation_t **form);
nbKoukaPacket_t *nbAddUnitAKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 a, s32 frame);
void nbAddUnitStock(nbMainProcessData_t **data, s32 side, s32 stockno, s32 formindex);
void nbAllFormDispOn(void);
s32 nbAppendEnemyDevilWork(nbMainProcessData_t *data, s32 id, s32 formindex);
void nbCameraHelperModelSet(dds3ModelHandle_t *hModel);
void nbCameraSetState(u16 state);
s32 nbCheckLoad(nbFormation_t **form);
void nbDispText(char *text1, char *text2, s32 type, s32 max, u32 col, bool type_skill);
void nbEventPrefabDelete(dds3Basic_t **pathbasic);
void nbEventPrefabRead(dds3Basic_t **pathbasic, s32 event_no, s32 index);
void nbFormDispOn(s32 formindex);
nbFormation_t *nbGetEventForm(void);
void nbGroupFormDispOff(s32 side);
void nbLoadUnit(nbFormation_t **form, s32 stop, s32 anime);
s32 nbMakeUnitFadeInPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 col, s32 delay, s32 aframe, s32 colframe);
void nbPanelAllShow(void);
void nbSetEnemyFormation(nbMainProcessData_t **data);
void nbUpdateEventProcessData(dds3ProcessID_t **id);

// 0x16feb00
u32 DDS3EFFECT_RGBA(u32 r, u32 g, u32 b, u32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x16feb10
s32 Effect1(nbEventProcessData_t *ed) {
  nbEventProcessData_t_Fields *p_fields;
  struct nbMainProcessData_t_o *data;
  struct nbFormation_t_array *v9;
  nbFormation_t_o *v11;
  s32 formindex;
  s32 appended;
  nbMainProcessData_t_o *v14;
  struct nbFormation_t_array *v15;
  s32 v17;
  System_Byte_array *ResorceData;
  System_String_o *v22;
  s32 NB_HELP_TYPE_TXTCONV;
  nbFormation_t_o *form;
  nbFormation_t_o *EventForm;

  EventForm = 0;
  form = 0;
  nbPanelAllShow();
  EventForm = nbGetEventForm();
  evtSetUnitMotion(&EventForm->hunit, 16, 0, 0, 2);
  p_fields = &ed->fields;
  data = ed->data;
  v9 = data->form;
  v11 = v9->m_Items[4];
  form = v11;
  formindex = v11->formindex;
  appended = nbAppendEnemyDevilWork(data, 290, formindex);
  nbAddUnitStock(&ed->data, 1, appended, v11->formindex);
  nbLoadUnit(&form, 0, 0);
  v14 = p_fields->data;
  v15 = p_fields->data->form;
  form = v15->m_Items[6];
  v17 = nbAppendEnemyDevilWork(v14, 289, form->formindex);
  nbAddUnitStock(&ed->data, 1, v17, form->formindex);
  nbLoadUnit(&form, 0, 0);
  ResorceData = evtGetResorceData(911, 1);
  nbAddSkillEffectKoukaPacket3(0, 1, ResorceData, 2, &EventForm);
  v22 = Get(230, 0, 0);
  nbDispText(v22, 0, NB_HELP_TYPE_TXTCONV, 90, 0x89FEFF80, 0);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16feef0
s32 Effect2(nbEventProcessData_t *ed) {
  s32 seqtime;
  struct nbFormation_t_array *v5;
  nbFormation_t_o *v7;
  struct nbFormation_t_array *v8;
  s32 v10;
  s32 formindex;
  struct dds3Basic_t_o *basic1;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u8 *monitor;
  s64 v19;
  s64 v20;
  s32 v21;
  struct dds3Basic_t_o *basic2;
  Il2CppObject *v24;
  Il2CppClass *v25;
  s64 v26;
  u8 *v27;
  s64 v28;
  s64 v29;
  char *v31;
  s64 *v32;
  char *v33;
  s64 *v34;
  char *v35;
  s64 *v36;
  char *v37;
  s64 *v38;
  u64 v39[2];
  char *v40;
  nbFormation_t_o *form;

  form = 0;
  seqtime = ed->seqtime;
  if (seqtime < 10)
    goto LABEL_22;
  switch (seqtime)
  {
    case 140:
      *&ed->seq = (ed->seq + 1);
      goto LABEL_22;
    case 83:
      v8 = ed->data->form;
      v7 = v8->m_Items[6];
      break;
    case 75:
      v5 = ed->data->form;
      v7 = v5->m_Items[4];
      break;
    default:
      goto LABEL_22;
  }
  form = v7;
  if (!nbCheckLoad(&form))
  {
LABEL_22:
    if (form)
    {
      formindex = form->formindex;
      nbFormDispOn(formindex);
      nbAddUnitAKoukaPacket(0, 0, &form, 0, 0);
      nbMakeUnitFadeInPacket(1, 0, &form, 0, 15, 15, 20);
      nbAddHitEffKoukaPacket(1, 0, &form, 4);
      dds3SetQuake(10, 0x258u);
    }
    v10 = ed->seqtime;
    if ((v10 - 61) > 0xB)
      goto LABEL_42;
    goto LABEL_31;
  }
  v10 = ed->seqtime - 1;
  ed->seqtime = v10;
  form = 0;
  if ((v10 - 61) > 0xB)
    goto LABEL_42;
LABEL_31:
  else
  {
    if (!basic1)
      goto LABEL_42;
  }
  workdata = basic1->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v39);
    if ((v39[0] & 1) != 0)
      v31 = v40;
    else
      v31 = v39 + 1;
    v32 = sub_8C4940(v31);
  }
  monitor = workdata[4].monitor;
  v19 = *monitor;
  if (*(*monitor + 288LL) < v20 || *(*(v19 + 200) + 8 * v20 - 8) != effEveBEDParams_t)
  {
    sub_8FC2C0(*(v19 + 64), effEveBEDParams_t, v39);
    if ((v39[0] & 1) != 0)
      v33 = v40;
    else
      v33 = v39 + 1;
    v34 = sub_8C4940(v33);
  }
  monitor[63] = (9216 - (v10 << 7)) / 12;
LABEL_42:
  v21 = ed->seqtime;
  if ((v21 - 69) <= 0xB)
  {
    else
    {
      if (!basic2)
        return 0;
    }
    v24 = basic2->workdata;
    v25 = v24->klass;
    if (v24->klass->_2.typeHierarchyDepth < v26
      || v25->_2.typeHierarchy[v26 - 1] != dds3EffectObjectBasicWorkData_t)
    {
      sub_8FC2C0(v25->_1.element_class, dds3EffectObjectBasicWorkData_t, v39);
      if ((v39[0] & 1) != 0)
        v35 = v40;
      else
        v35 = v39 + 1;
      v36 = sub_8C4940(v35);
    }
    v27 = v24[4].monitor;
    v28 = *v27;
    if (*(*v27 + 288LL) < v29 || *(*(v28 + 200) + 8 * v29 - 8) != effEveBEDParams_t)
    {
      sub_8FC2C0(*(v28 + 64), effEveBEDParams_t, v39);
      if ((v39[0] & 1) != 0)
        v37 = v40;
      else
        v37 = v39 + 1;
      v38 = sub_8C4940(v37);
    }
    v27[63] = (10240 - (v21 << 7)) / 12;
  }
  return 0;
}

// 0x16ff470
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 2)
    return 0;
  Write("バアル魔王の号令\n", 0);
  return 1;
}

// 0x16fee10
s32 Wait1(nbEventProcessData_t *ed) {
  if ((byte_3F5A43F & 1) != 0)
  {
    if (ed->seqtime != 1)
      return 0;
  }
  else
  {
    if (ed->seqtime != 1)
      return 0;
  }
  nbSetEnemyFormation(&ed->data);
  nbAllFormDispOn();
  nbGroupFormDispOff(0);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16ff510
void *nbE911Process_1(dds3ProcessID_t *id) {
  u64 *v2;
  u64 *v3;
  u64 *v4;
  Il2CppObject *ProcessData;
  nbEventProcessData_t_o *v10;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  struct nbE911_funcDelegate_array *func;
  s64 seq;
  s32 time;
  dds3ModelHandle_t_o *Model;
  s32 v29;
  s32 v31;
  struct dds3Basic_t_o *v32;
  s32 v36;
  s32 v38;
  struct dds3Basic_t_o **p_pPBCameraBasic02;
  s32 eventrid;
  s32 v45;
  dds3Basic_t_o *v48;
  s32 v50;
  s32 pPBCameraBasicIndex;
  s32 v55;
  s32 v57;
  dds3Basic_t_o *v59;
  evtUnitHandle_t_o *UnitHandleObjectBasic;
  s32 v65;
  s32 v67;
  s32 v69;
  struct nbFormation_t_array *form;
  effBTL_SkillLight_t_o *v72;
  effBTL_SkillLight_t_o *v73;
  effBTL_SkillModel_t_o *v74;
  u8 v75;
  s32 v76;
  u32 v77;
  u8 v78;
  u32 v79;
  dds3Basic_t_o *pBasic;
  nbFormation_t_o *pFormation;
  effBTL_SkillModel_t_o *pModel;
  effBTL_SkillLight_t_o *pLight;
  evtUnitHandle_t_o *h;
  dds3ProcessID_t_o *ida;
  u64 v87[3];

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
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v87);
      if ((v87[0] & 1) != 0)
        v13 = v87[2];
      else
        v13 = v87 + 1;
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
    if (pPBCameraBasic02)
    {
      nbEventPrefabDelete(&pPBCameraBasic02);
      dds3DeleteSceneBasicData(&pPBCameraBasic02);
      pPBCameraBasic02 = 0;
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
  if (time == 75)
  {
    eventrid = v10->eventrid;
    v45 = evtRegistBEUnit(eventrid, 4);
    v48 = dds3SearchSceneBasic(&pBasic, v45, 5u);
    pPBCameraBasic02 = v48;
    pPBCameraBasicIndex = 4;
    v50 = v10->eventrid;
    nbEventPrefabRead(&pPBCameraBasic02, v50, pPBCameraBasicIndex);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic02);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    p_pPBCameraBasic02 = &pPBCameraBasic02;
  }
  else if (time == 40)
  {
    v55 = v10->eventrid;
    v57 = evtRegistBEUnit(v55, 3);
    v59 = dds3SearchSceneBasic(&pBasic, v57, 5u);
    pPBCameraBasic01 = v59;
    UnitHandleObjectBasic = dds3GetUnitHandleObjectBasic(&pPBCameraBasic01);
    h = UnitHandleObjectBasic;
    pPBCameraBasicIndex = 3;
    v65 = v10->eventrid;
    v67 = pPBCameraBasicIndex;
    nbEventPrefabRead(&pPBCameraBasic01, v65, v67);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    p_pPBCameraBasic02 = &pPBCameraBasic01;
  }
  else
  {
    if (time)
      goto LABEL_149;
    nbCameraSetState(0x17u);
    pPBCameraBasicCurrent = 0;
    pPBCameraBasic00 = 0;
    pPBCameraBasic01 = 0;
    pPBCameraBasic02 = 0;
    v29 = v10->eventrid;
    v31 = evtRegistBEUnit(v29, 2);
    v32 = dds3SearchSceneBasic(&pBasic, v31, 5u);
    pPBCameraBasic00 = v32;
    pPBCameraBasicIndex = 2;
    v36 = v10->eventrid;
    v38 = pPBCameraBasicIndex;
    nbEventPrefabRead(&pPBCameraBasic00, v36, v38);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic00);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    p_pPBCameraBasic02 = &pPBCameraBasic00;
  }
  pPBCameraBasicCurrent = *p_pPBCameraBasic02;
LABEL_149:
  v69 = v10->time;
  if (v69 == 1)
  {
    form = v10->data->form;
    v72 = pLight;
    pFormation = form->m_Items[5];
    pLight->pos_ptr->target = 0;
    v72->pos_ptr->height = 2;
    v72->pos_ptr->direction = 5;
    v72->pos_ptr->radius = 500;
    v73 = v72;
    {
      v73 = v72;
    }
    v72->diffuse = -2140904348;
    v73->ambient = -2142885848;
    v73->color_anim->fade_in_frame = 0;
    v73->color_anim->fade_in_pattern = 2;
    v73->color_anim->fade_out_frame = 80;
    v73->color_anim->fade_out_pattern = 0;
    v74 = pModel;
    pModel->color = -2137750902;
    v74->color_anim->fade_in_frame = 1;
    v74->color_anim->fade_in_pattern = 0;
    v74->color_anim->fade_out_frame = 60;
    v74->color_anim->fade_out_pattern = 2;
    effBTLPointLightSet(&pLight, &pFormation);
    effBTLModelColorSet(&pModel, &pFormation);
  }
  else
  {
    if (v69)
      goto LABEL_165;
    effBTLSkillStart(0xE6u, 0);
  }
  v69 = v10->time;
LABEL_165:
  if (v69 > 55)
  {
    if (v69 != 76)
    {
      if (v69 != 82)
      {
        if (v69 != 88)
          goto LABEL_200;
        effPadVibeFadeOUT(0, 1u, 30);
        v75 = -1;
        v76 = 30;
        goto LABEL_199;
      }
      dds3PadAct(0, 1u, 6u);
      v78 = -1;
      v79 = 6;
LABEL_194:
      dds3PadAct(1u, v78, v79);
      goto LABEL_200;
    }
    v77 = 5;
    dds3PadAct(0, 1u, 5u);
    v78 = -1;
LABEL_193:
    v79 = v77;
    goto LABEL_194;
  }
  if (!v69)
  {
    v77 = 40;
LABEL_192:
    dds3PadAct(0, 0, v77);
    v78 = -126;
    goto LABEL_193;
  }
  if (v69 != 40)
  {
    if (v69 != 55)
      goto LABEL_200;
    v77 = 18;
    goto LABEL_192;
  }
  effPadVibeFadeOUT(0, 1u, 15);
  v75 = -56;
  v76 = 15;
LABEL_199:
  effPadVibeFadeOUT(1u, v75, v76);
LABEL_200:
  nbUpdateEventProcessData(&ida);
  return 0;
}
