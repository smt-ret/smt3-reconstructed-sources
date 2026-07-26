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
  Write(StringLiteral_21340, 0);
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
    dds3GetProcessData(0);
    nbCameraBoss_BSBERU_E915_Init();
    nbCameraBoss_BSBERU_E915_0_Set();
    nbCameraSetState(0);
    nbSetEnemyFormation(0);
    nbSetPlayerFormation(0, 0);
    nbCameraBoss_BSBERU_E915_1_Set();
    nbGetEventForm();
    nbFormDispOff2(0);
    nbCameraBoss_BSBERU_E915_2_Set();
    effBTLSkillStart(0, 0);
    nbUpdateEventProcessData(0);
    return 0;
}
