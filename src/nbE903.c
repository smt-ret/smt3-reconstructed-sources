#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effBTLCutHandle_t effBTLCutHandle_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbE903_funcDelegate nbE903_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

static s32 NB_HELP_TYPE_TXTCONV;
static nbE903_funcDelegate *func[8];
static dds3Basic_t *pPBCameraBasicCurrent;
static dds3Basic_t *pPBCameraBasic00;
static dds3Basic_t *pPBCameraBasic01;
static dds3Basic_t *pPBCameraBasic02;
static s32 pPBCameraBasicIndex;

u8 Get(s32 id);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
u32 effBTLCutGetFrame(effBTLCutHandle_t **hBTLCutEffect);
void effBTLCutSetDrawEndFrame(effBTLCutHandle_t **hBTLCutEffect, u32 frame);
u8 **evtGetResorceData(s32 eventno, s32 rid);
s32 evtRegistBEUnit(s32 eventno, s32 rid);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
nbKoukaPacket_t *nbAddMotionKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 motion);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket3(s32 startframe, s32 uniqueid, u8 **bed, s32 cutno, nbFormation_t **form);
nbKoukaPacket_t *nbAddUnitAKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 a, s32 frame);
void nbAddUnitStock(nbMainProcessData_t **data, s32 side, s32 stockno, s32 formindex);
void nbAllFormDispOn(void);
s32 nbAppendEnemyDevilWork(nbMainProcessData_t *data, s32 id, s32 formindex);
void nbCameraHelperModelSet(dds3ModelHandle_t *hModel);
void nbCameraSetState(u16 state);
s32 nbCheckLoadGroup(s32 side);
void nbDispText(char *text1, char *text2, s32 type, s32 max, u32 col, bool type_skill);
void nbEventPbRead(s32 event_no, s32 index);
void nbEventPrefabDelete(dds3Basic_t **pathbasic);
void nbEventPrefabRead(dds3Basic_t **pathbasic, s32 event_no, s32 index);
void nbFormDispOn(s32 formindex);
nbFormation_t *nbGetEventForm(void);
void nbGroupFormDispOff(s32 side);
void nbLoadUnit(nbFormation_t **form, s32 stop, s32 anime);
void nbPanelAllHide(void);
void nbResetFormPosRot(nbFormation_t **form);
void nbSetFormPos(nbFormation_t **form, sdfVector4_t pos);
void nbUpdateEventProcessData(dds3ProcessID_t **id);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);

// 0x16f1a10
s32 EffDel(nbEventProcessData_t *ed) {
    dds3GetProcessData(0);
    effBTLCutGetFrame(0);
    effBTLCutSetDrawEndFrame(0, 0);
    return 0;
}

// 0x16f1be0
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 31)
    return 0;
  Write(StringLiteral_21327, 0);
  ed->data->stat |= 0x2000u;
  return 1;
}

// 0x16f0900
s32 Hatudo(nbEventProcessData_t *ed) {
  System_String_o *v8;
  s32 NB_HELP_TYPE_TXTCONV;
  nbFormation_t_o *form;

  form = 0;
  nbPanelAllHide();
  form = nbGetEventForm();
  nbAddMotionKoukaPacket(0, 0, &form, 4);
  nbResetFormPosRot(&form);
  v8 = Get(236, 0, 0);
  nbDispText(v8, 0, NB_HELP_TYPE_TXTCONV, 90, 0x89FEFF80, 0);
  if (ed)
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f0b70
s32 Parts1(nbEventProcessData_t *ed) {
  nbFormation_t_o *form;

  form = 0;
  form = nbGetEventForm();
  nbAddMotionKoukaPacket(0, 0, &form, 16);
  if (ed)
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f0c10
s32 PartsEffect1(nbEventProcessData_t *ed) {
    nbAppendEnemyDevilWork(0, 0, 0);
    nbAddUnitStock(0, 0, 0, 0);
    nbLoadUnit(0, 0, 0);
    nbCheckLoadGroup(0);
    nbFormDispOn(0);
    nbAddUnitAKoukaPacket(0, 0, 0, 0, 0);
    evtSetUnitMotion(0, 0, 0, 0, 0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    nbSetFormPos(0, (sdfVector4_t){0});
    nbEventPbRead(0, 0);
    evtGetResorceData(0, 0);
    nbAddSkillEffectKoukaPacket3(0, 0, 0, 0, 0);
    return 0;
}

// 0x16f16f0
s32 PartsEffect2(nbEventProcessData_t *ed) {
  System_Array_o *v3;
  struct nbFormation_t_array *v5;
  s64 v7;
  System_Byte_array *ResorceData;
  struct nbFormation_t_array *v11;
  s64 v13;
  System_Byte_array *v15;
  struct nbFormation_t_array *v17;
  s64 v19;
  System_Byte_array *v21;
  struct nbFormation_t_array *v23;
  s64 v25;
  System_Byte_array *v27;
  nbFormation_t_o *form;

  form = 0;
  v3 = NewSpecific(s32, 4u);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__2D9F10F6B76B71F204C153E93F77FC483ABB3B9B);
  v5 = ed->data->form;
  v7 = SLODWORD(v3[2].klass) + 4LL;
  form = v5->m_Items[v7];
  ResorceData = evtGetResorceData(903, 5);
  nbAddSkillEffectKoukaPacket3(0, 0, ResorceData, 2, &form);
  v11 = ed->data->form;
  v13 = SHIDWORD(v3[2].klass) + 4LL;
  form = v11->m_Items[v13];
  v15 = evtGetResorceData(903, 6);
  nbAddSkillEffectKoukaPacket3(0, 0, v15, 2, &form);
  v17 = ed->data->form;
  v19 = SLODWORD(v3[2].monitor) + 4LL;
  form = v17->m_Items[v19];
  v21 = evtGetResorceData(903, 7);
  nbAddSkillEffectKoukaPacket3(0, 0, v21, 2, &form);
  v23 = ed->data->form;
  v25 = SHIDWORD(v3[2].monitor) + 4LL;
  form = v23->m_Items[v25];
  v27 = evtGetResorceData(903, 8);
  nbAddSkillEffectKoukaPacket3(0, 0, v27, 2, &form);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f1650
s32 PartsWait(nbEventProcessData_t *ed) {
  if ((byte_3F5A409 & 1) != 0)
  {
    if (ed->seqtime < 9)
      return 0;
  }
  else
  {
    if (ed->seqtime < 9)
      return 0;
  }
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f0aa0
s32 Wait1(nbEventProcessData_t *ed) {
  s32 seqtime;

  nbGetEventForm();
  seqtime = ed->seqtime;
  else if (seqtime < 31)
  {
    return 0;
  }
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f08f0
u16 mdlGetMotionLength(dds3ModelHandle_t *aHandle) {
  return 30;
}

// 0x16f1c90
void *nbE903Process_1(dds3ProcessID_t *id) {
    dds3GetActiveScene();
    dds3GetProcessData(0);
    nbEventPrefabDelete(0);
    dds3DeleteSceneBasicData(0);
    dds3GetUnitHandleObjectBasic(0);
    nbCameraHelperModelSet(0);
    evtRegistBEUnit(0, 0);
    dds3SearchSceneBasic(0, 0, 0);
    nbEventPrefabRead(0, 0, 0);
    evtSetUnitMotion(0, 0, 0, 0, 0);
    nbCameraSetState(0);
    nbAllFormDispOn();
    nbGroupFormDispOff(0);
    nbUpdateEventProcessData(0);
    return 0;
}
