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
    nbCheckLoad(0);
    nbFormDispOn(0);
    nbAddUnitAKoukaPacket(0, 0, 0, 0, 0);
    nbMakeUnitFadeInPacket(0, 0, 0, 0, 0, 0, 0);
    nbAddHitEffKoukaPacket(0, 0, 0, 0);
    dds3SetQuake(0, 0);
    return 0;
}

// 0x16ff470
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 2)
    return 0;
  Write(StringLiteral_21336, 0);
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
    effBTL_SkillLight_t__Clear(0);
    effBTL_SkillModel_t__Clear(0);
    dds3GetActiveScene();
    dds3GetProcessData(0);
    nbEventPrefabDelete(0);
    dds3DeleteSceneBasicData(0);
    effBTLSkillEnd();
    dds3GetUnitHandleObjectBasic(0);
    nbCameraHelperModelSet(0);
    evtRegistBEUnit(0, 0);
    dds3SearchSceneBasic(0, 0, 0);
    nbEventPrefabRead(0, 0, 0);
    evtSetUnitMotion(0, 0, 0, 0, 0);
    nbCameraSetState(0);
    effBTLPointLightSet(0, 0);
    effBTLModelColorSet(0, 0);
    effBTLSkillStart(0, 0);
    effPadVibeFadeOUT(0, 0, 0);
    dds3PadAct(0, 0, 0);
    nbUpdateEventProcessData(0);
    return 0;
}
