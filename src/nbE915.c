#include "types.h"

typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbE915_funcDelegate nbE915_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

static nbE915_funcDelegate *func[2];

void billClrTexture(bool allclear);
void *dds3GetProcessData(dds3ProcessID_t **id);
void effBTLSkillStart(u32 id, u32 stat);
u8 **evtGetResorceData(s32 eventno, s32 rid);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
nbKoukaPacket_t *nbAddFadeOutKoukaPacket(s32 startframe, s32 uniqueid, s32 length, s32 coltype);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket3(s32 startframe, s32 uniqueid, u8 **bed, s32 cutno, nbFormation_t **form);
void nbCameraBoss_BSBERU_E915_0_Set(void);
void nbCameraBoss_BSBERU_E915_1_Set(void);
void nbCameraBoss_BSBERU_E915_2_Set(void);
void nbCameraBoss_BSBERU_E915_Init(void);
void nbCameraSetState(u16 state);
void nbDelAllKoukaPacketType(s32 type);
void nbFormDispOff2(nbFormation_t **form);
nbFormation_t *nbGetEventForm(void);
void nbPanelAllHide(void);
void nbSetEnemyFormation(nbMainProcessData_t **data);
void nbSetPlayerFormation(nbMainProcessData_t **data, s32 empty);
void nbSingleFormExceptedDispOff(nbFormation_t **form);
void nbUpdateEventProcessData(dds3ProcessID_t **id);

// 0x17051f0
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 371)
    return 0;
  Write("ベルゼブブ死亡\n", 0);
  nbDelAllKoukaPacketType(43);
  ed->data->endtype = 1;
  return 1;
}

// 0x1705020
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
  billClrTexture(0);
  ResorceData = evtGetResorceData(915, 1);
  nbAddSkillEffectKoukaPacket3(0, 0, ResorceData, 2, &form);
  nbAddFadeOutKoukaPacket(330, 0, 40, 1);
  if (ed)
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x1705010
void nbBgmStop(void) {
  ;
}

// 0x17052a0
void *nbE915Process_1(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  nbEventProcessData_t_o *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct nbE915_funcDelegate_array *func;
  s64 seq;
  s32 time;
  nbFormation_t_o *EventForm;
  dds3ProcessID_t_o *v22[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  EventForm = 0;
  ProcessData = dds3GetProcessData(&ida);
  v5 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbEventProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v22);
      if ((v22[0] & 1) != 0)
        v8 = v22[2];
      else
        v8 = v22 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  seq = v5->seq;
  if (Invoke(func->m_Items[seq], v5))
  {
    ida->func_ans = -1;
    return 0;
  }
  time = v5->time;
  if (time)
  {
    if (time > 109)
      goto LABEL_22;
LABEL_35:
    if (!time)
    {
      nbCameraBoss_BSBERU_E915_Init();
    }
    nbCameraBoss_BSBERU_E915_0_Set();
    goto LABEL_44;
  }
  nbCameraSetState(0x17u);
  nbSetEnemyFormation(&v5->data);
  nbSetPlayerFormation(&v5->data, 0);
  time = v5->time;
  if (time <= 109)
    goto LABEL_35;
LABEL_22:
  if (time == 110)
  {
    nbCameraBoss_BSBERU_E915_1_Set();
    if (v5->time)
      goto LABEL_49;
    goto LABEL_45;
  }
  if (time >= 250)
  {
    if (time == 250)
    {
      EventForm = nbGetEventForm();
      nbFormDispOff2(&EventForm);
      nbCameraBoss_BSBERU_E915_Init();
    }
    nbCameraBoss_BSBERU_E915_2_Set();
    if (v5->time)
      goto LABEL_49;
    goto LABEL_45;
  }
LABEL_44:
  if (!v5->time)
  {
LABEL_45:
    effBTLSkillStart(0x203u, 0);
  }
LABEL_49:
  nbUpdateEventProcessData(&ida);
  return 0;
}
