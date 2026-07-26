#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbE906_funcDelegate nbE906_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;

static nbE906_funcDelegate *func[2];
static dds3Basic_t *pPBCameraBasicCurrent;
static dds3Basic_t *pPBCameraBasic00;
static dds3Basic_t *pPBCameraBasic01;
static dds3Basic_t *pPBCameraBasic02;
static dds3Basic_t *pPBCameraBasic03;
static s32 pPBCameraBasicIndex;

void billCutRaitoSet2(f32 raito);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void dds3SetQuake(s32 frame, u32 range);
void effPadVibeFadeOUT(u32 mode, u8 power, s32 frame);
u8 **evtGetResorceData(s32 eventno, s32 rid);
s32 evtRegistBEUnit(s32 eventno, s32 rid);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
void fpCutRaitoSet(s32 raito);
nbKoukaPacket_t *nbAddFadeOutKoukaPacket(s32 startframe, s32 uniqueid, s32 length, s32 coltype);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket3(s32 startframe, s32 uniqueid, u8 **bed, s32 cutno, nbFormation_t **form);
void nbCameraHelperModelSet(dds3ModelHandle_t *hModel);
void nbCameraSetState(u16 state);
void nbEventPrefabDelete(dds3Basic_t **pathbasic);
void nbEventPrefabRead(dds3Basic_t **pathbasic, s32 event_no, s32 index);
nbFormation_t *nbGetEventForm(void);
void nbPanelAllHide(void);
void nbSingleFormExceptedDispOff(nbFormation_t **form);
void nbUpdateEventProcessData(dds3ProcessID_t **id);

// 0x16f7180
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 421)
    return 0;
  Write(StringLiteral_21331, 0);
  ed->data->endtype = 1;
  return 1;
}

// 0x16f6f50
s32 Test(nbEventProcessData_t *ed) {
  evtUnitHandle_t_o **p_hunit;
  System_Byte_array *ResorceData;
  System_Byte_array *v12;
  nbFormation_t_o *form;

  form = 0;
  form = nbGetEventForm();
  nbPanelAllHide();
  nbSingleFormExceptedDispOff(&form);
  p_hunit = &form->hunit;
  evtSetUnitMotion(p_hunit, 23, 0, 0, 2);
  billCutRaitoSet2(80.0);
  fpCutRaitoSet(80);
  ResorceData = evtGetResorceData(906, 1);
  nbAddSkillEffectKoukaPacket3(0, 0, ResorceData, 2, &form);
  v12 = evtGetResorceData(906, 2);
  nbAddSkillEffectKoukaPacket3(0, 0, v12, 2, &form);
  billCutRaitoSet2(0.0);
  fpCutRaitoSet(0);
  nbAddFadeOutKoukaPacket(320, 0, 70, 1);
  if (ed)
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f7220
void *nbE906Process_1(dds3ProcessID_t *id) {
    dds3GetActiveScene();
    dds3GetProcessData(0);
    nbEventPrefabDelete(0);
    dds3DeleteSceneBasicData(0);
    dds3GetUnitHandleObjectBasic(0);
    nbCameraHelperModelSet(0);
    evtRegistBEUnit(0, 0);
    dds3SearchSceneBasic(0, 0, 0);
    nbEventPrefabRead(0, 0, 0);
    nbCameraSetState(0);
    evtSetUnitMotion(0, 0, 0, 0, 0);
    dds3PadAct(0, 0, 0);
    dds3SetQuake(0, 0);
    effPadVibeFadeOUT(0, 0, 0);
    nbUpdateEventProcessData(0);
    return 0;
}
