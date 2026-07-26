#include "types.h"

typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbE913_funcDelegate nbE913_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;

static nbE913_funcDelegate *func[2];

void *dds3GetProcessData(dds3ProcessID_t **id);
u8 **evtGetResorceData(s32 eventno, s32 rid);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
nbKoukaPacket_t *nbAddFadeOutKoukaPacket(s32 startframe, s32 uniqueid, s32 length, s32 coltype);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket3(s32 startframe, s32 uniqueid, u8 **bed, s32 cutno, nbFormation_t **form);
void nbCameraBoss_Foru_E913_Run(void);
void nbCameraBoss_Foru_E913_Set(void);
void nbCameraSetState(u16 state);
void nbDelAllKoukaPacketType(s32 type);
nbFormation_t *nbGetEventForm(void);
void nbPanelAllHide(void);
void nbSingleFormExceptedDispOff(nbFormation_t **form);
void nbUpdateEventProcessData(dds3ProcessID_t **id);

// 0x1703430
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 211)
    return 0;
  Write(StringLiteral_21338, 0);
  nbDelAllKoukaPacketType(43);
  ed->data->endtype = 1;
  return 1;
}

// 0x17032a0
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
  ResorceData = evtGetResorceData(913, 1);
  nbAddSkillEffectKoukaPacket3(0, 0, ResorceData, 2, &form);
  nbAddFadeOutKoukaPacket(145, 0, 40, 1);
  if (ed)
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x17034e0
void *nbE913Process_1(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    nbCameraSetState(0);
    nbCameraBoss_Foru_E913_Set();
    nbCameraBoss_Foru_E913_Run();
    nbUpdateEventProcessData(0);
    return 0;
}
