#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbE908_funcDelegate nbE908_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

static nbE908_funcDelegate *func[2];
static dds3Basic_t *pPBCameraBasicCurrent;
static dds3Basic_t *pPBCameraBasic00;
static s32 pPBCameraBasicIndex;

void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
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
nbFormation_t *nbGetEventForm(void);
void nbGroupFormDispOff(s32 side);
void nbGroupFormDispOn(s32 side);
void nbPanelAllHide(void);
void nbSetEnemyFormation(nbMainProcessData_t **data);
void nbSetPlayerFormation(nbMainProcessData_t **data, s32 empty);
void nbSingleFormExceptedDispOff(nbFormation_t **form);
void nbUpdateEventProcessData(dds3ProcessID_t **id);

// 0x16faf40
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 271)
    return 0;
  Write("漂流神死亡\n", 0);
  ed->data->endtype = 1;
  return 1;
}

// 0x16fadb0
s32 Test(nbEventProcessData_t *ed) {
  evtUnitHandle_t_o **p_hunit;
  System_Byte_array *ResorceData;
  nbFormation_t_o *form;

  form = 0;
  form = nbGetEventForm();
  nbPanelAllHide();
  nbSingleFormExceptedDispOff(&form);
  p_hunit = &form->hunit;
  evtSetUnitMotion(p_hunit, 23, 0, 0, 2);
  ResorceData = evtGetResorceData(908, 1);
  nbAddSkillEffectKoukaPacket3(0, 0, ResorceData, 2, &form);
  nbAddFadeOutKoukaPacket(190, 0, 70, 1);
  if (ed)
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16fafe0
void *nbE908Process_1(dds3ProcessID_t *id) {
  u64 *v2;
  Il2CppObject *ProcessData;
  nbEventProcessData_t_o *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  struct nbE908_funcDelegate_array *func;
  s64 seq;
  s32 time;
  dds3ModelHandle_t_o *Model;
  s32 eventrid;
  s32 v28;
  struct dds3Basic_t_o *v29;
  s32 v33;
  s32 pPBCameraBasicIndex;
  dds3Basic_t_o *ActiveScene;
  evtUnitHandle_t_o *h;
  dds3ProcessID_t_o *ida;
  u64 v42[3];

  ida = id;
  ActiveScene = 0;
  v2 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v2);
  h = v2;
  ActiveScene = dds3GetActiveScene();
  ProcessData = dds3GetProcessData(&ida);
  v8 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbEventProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v42);
      if ((v42[0] & 1) != 0)
        v11 = v42[2];
      else
        v11 = v42 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  seq = v8->seq;
  if (Invoke(func->m_Items[seq], v8))
  {
    pPBCameraBasicCurrent = 0;
    if (pPBCameraBasic00)
    {
      nbEventPrefabDelete(&pPBCameraBasic00);
      dds3DeleteSceneBasicData(&pPBCameraBasic00);
      pPBCameraBasic00 = 0;
    }
    ida->func_ans = -1;
    return 0;
  }
  time = v8->time;
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
    time = v8->time;
  }
  if (!time)
  {
    nbCameraSetState(0x17u);
    pPBCameraBasicCurrent = 0;
    pPBCameraBasic00 = 0;
    nbGroupFormDispOff(0);
    nbGroupFormDispOn(1);
    nbSetEnemyFormation(&v8->data);
    nbSetPlayerFormation(&v8->data, 0);
    eventrid = v8->eventrid;
    v28 = evtRegistBEUnit(eventrid, 2);
    v29 = dds3SearchSceneBasic(&ActiveScene, v28, 5u);
    pPBCameraBasic00 = v29;
    pPBCameraBasicIndex = 2;
    v33 = v8->eventrid;
    nbEventPrefabRead(&pPBCameraBasic00, v33, pPBCameraBasicIndex);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic00);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    pPBCameraBasicCurrent = pPBCameraBasic00;
    time = v8->time;
    if (time != 220)
      goto LABEL_56;
LABEL_86:
    effPadVibeFadeOUT(0, 0, 70);
    effPadVibeFadeOUT(1u, 0xAAu, 70);
    goto LABEL_90;
  }
  if (time == 220)
    goto LABEL_86;
LABEL_56:
  if (!time)
  {
    dds3PadAct(0, 0, 0);
    dds3PadAct(1u, 0xAAu, 0x12Cu);
  }
LABEL_90:
  nbUpdateEventProcessData(&ida);
  return 0;
}
