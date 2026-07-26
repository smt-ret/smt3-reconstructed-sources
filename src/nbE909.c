#include "types.h"

typedef struct NB_FILEHANDLE_T NB_FILEHANDLE_T;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fileHandle_t fileHandle_t;
typedef struct nbE909_funcDelegate nbE909_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

static s16 count[20];
static u16 Model1Start_name_a[64];
static char *Model1Start_name;
static nbE909_funcDelegate *func[9];

void SetAuto(bool act);
void SetDrawFlag(u32 flag, u32 cnt);
void SetLevel(f32 lv);
void *dds3GetProcessData(dds3ProcessID_t **id);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
void effPadVibeFadeOUT(u32 mode, u8 power, s32 frame);
bool evtBitCheck(s32 no);
u8 **evtGetResorceData(s32 eventno, s32 rid);
void evtSetAgeOfMoon(s32 age);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
void mdlPackDecode(s32 major, s32 minor, u32 regFlags, void *buff, s32 leng);
nbKoukaPacket_t *nbAddFadeInKoukaPacket(s32 startframe, s32 uniqueid, s32 length, s32 coltype);
nbKoukaPacket_t *nbAddFadeOutKoukaPacket(s32 startframe, s32 uniqueid, s32 length, s32 coltype);
nbKoukaPacket_t *nbAddFormOnOffPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 sw);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket3(s32 startframe, s32 uniqueid, u8 **bed, s32 cutno, nbFormation_t **form);
nbKoukaPacket_t *nbAddUnitAKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 a, s32 frame);
void nbAddUnitStock(nbMainProcessData_t **data, s32 side, s32 stockno, s32 formindex);
s32 nbAppendEnemyDevilWork(nbMainProcessData_t *data, s32 id, s32 formindex);
void nbBgmFadeOut(void);
void nbBgmLoad(s32 encdata);
s32 nbBgmLoadChk(void);
void nbBgmPlay(void);
void nbCameraBoss_Kagu_E909_Run(void);
void nbCameraBoss_Kagu_E909_Set(void);
void nbCameraSetState(u16 state);
nbFormation_t *nbGetEventForm(void);
void nbLoadUnit(nbFormation_t **form, s32 stop, s32 anime);
void nbPanelAllHide(void);
void nbReturnAllEnemyUnit(void);
void nbSetEnemyFormation(nbMainProcessData_t **data);
void nbSetOrderSide(s32 side);
void nbSetPlayerFormation(nbMainProcessData_t **data, s32 empty);
void nbSetUnitPackFileHandle(nbFormation_t **form, NB_FILEHANDLE_T *fh);
void nbUpdateEventProcessData(dds3ProcessID_t **id);

// 0x16fcef0
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 26)
    return 0;
  Write(StringLiteral_21334, 0);
  ed->data->stat &= ~8u;
  SetAuto(0);
  return 1;
}

// 0x16fbdf0
s32 Model1Start(nbEventProcessData_t *ed) {
    nbPanelAllHide();
    nbSetOrderSide(0);
    nbGetEventForm();
    evtSetUnitMotion(0, 0, 0, 0, 0);
    evtGetResorceData(0, 0);
    nbAddSkillEffectKoukaPacket3(0, 0, 0, 0, 0);
    evtBitCheck(0);
    nbBgmFadeOut();
    SetAuto(0);
    SetLevel(0);
    return 0;
}

// 0x16fc3f0
s32 Model1Wait(nbEventProcessData_t *ed) {
  if ((byte_3F5A430 & 1) != 0)
  {
    if (ed->seqtime < 100)
      return 0;
  }
  else
  {
    if (ed->seqtime < 100)
      return 0;
  }
  if (!evtBitCheck(3087))
  {
    ed->mem = 0;
    ed->file = 0;
  }
  nbAddFadeOutKoukaPacket(0, 0, 10, 1);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16fc4f0
s32 Model1Wait_2(nbEventProcessData_t *ed) {
    nbReturnAllEnemyUnit();
    evtBitCheck(0);
    mdlPackDecode(0, 0, 0, 0, 0);
    return 0;
}

// 0x16fc5f0
s32 Model2Start(nbEventProcessData_t *ed) {
  nbEventProcessData_t_Fields *p_fields;
  struct nbMainProcessData_t_o *data;
  struct nbFormation_t_array *v5;
  nbFormation_t_o *v7;
  s32 formindex;
  s32 appended;
  NB_FILEHANDLE_T_o *pfile;
  struct nbParty_t_array *party;
  struct System_Int16_array *count;
  struct System_Int16_array *v16;
  s16 v18;
  struct nbParty_t_array *v20;
  struct System_Int16_array *v23;
  struct System_Int16_array *v24;
  s16 v26;
  struct nbParty_t_array *v28;
  struct System_Int16_array *v31;
  struct System_Int16_array *v32;
  s16 v34;
  struct nbParty_t_array *v36;
  struct System_Int16_array *v39;
  struct System_Int16_array *v40;
  s16 v41;
  struct nbParty_t_array *v42;
  struct System_Int16_array *v45;
  struct System_Int16_array *v46;
  s16 v48;
  System_Byte_array *ResorceData;
  nbFormation_t_o *form;

  form = 0;
  p_fields = &ed->fields;
  data = ed->data;
  v5 = data->form;
  v7 = v5->m_Items[4];
  form = v7;
  formindex = v7->formindex;
  appended = nbAppendEnemyDevilWork(data, 264, formindex);
  nbAddUnitStock(&ed->data, 1, appended, v7->formindex);
  nbLoadUnit(&form, 0, 0);
  if (evtBitCheck(3087))
  {
    pfile = ed->pfile;
    nbSetUnitPackFileHandle(&form, pfile);
    ed->pfile = 0;
  }
  party = p_fields->data->party;
  count = party->m_Items[form->partyindex]->count;
  v16 = count;
  v18 = v16->m_Items[4];
  count->m_Items[4] = v18;
  v20 = p_fields->data->party;
  v23 = v20->m_Items[form->partyindex]->count;
  v24 = count;
  v26 = v24->m_Items[5];
  v23->m_Items[5] = v26;
  v28 = p_fields->data->party;
  v31 = v28->m_Items[form->partyindex]->count;
  v32 = count;
  v34 = v32->m_Items[6];
  v31->m_Items[6] = v34;
  v36 = p_fields->data->party;
  v39 = v36->m_Items[form->partyindex]->count;
  v40 = count;
  v41 = v40->m_Items[7];
  v39->m_Items[7] = v41;
  v42 = p_fields->data->party;
  v45 = v42->m_Items[form->partyindex]->count;
  v46 = count;
  v48 = v46->m_Items[8];
  v45->m_Items[8] = v48;
  nbAddFormOnOffPacket(0, 0, &form, 1);
  nbAddUnitAKoukaPacket(0, 0, &form, 0, 0);
  nbAddUnitAKoukaPacket(0, 0, &form, 0x80000000, 0);
  ResorceData = evtGetResorceData(909, 2);
  nbAddSkillEffectKoukaPacket3(0, 0, ResorceData, 2, &form);
  SetDrawFlag(0x2000000u, 1u);
  nbSetEnemyFormation(&ed->data);
  evtSetAgeOfMoon(8);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16fcbc0
s32 Model2Wait_1(nbEventProcessData_t *ed) {
  nbGetEventForm();
  SetDrawFlag(0x2000000u, 1u);
  ed->data->encno = 782;
  nbBgmLoad(0);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16fcca0
s32 Model2Wait_15(nbEventProcessData_t *ed) {
  nbFormation_t_o *EventForm;

  EventForm = nbGetEventForm();
  if (EventForm && EventForm->hunit)
  {
    if (ed)
      *&ed->seq = (ed->seq + 1);
    nbAddFadeInKoukaPacket(3, 0, 10, 1);
  }
  return 0;
}

// 0x16fcd60
s32 Model2Wait_16(nbEventProcessData_t *ed) {
  evtUnitHandle_t_o **p_hunit;

  p_hunit = &nbGetEventForm()->hunit;
  evtSetUnitMotion(p_hunit, 17, 0, 0, 0);
  if (ed)
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16fce20
s32 Model2Wait_2(nbEventProcessData_t *ed) {
  if (ed->seqtime >= 81)
  {
    if (nbBgmLoadChk())
    {
      nbBgmPlay();
      *&ed->seq = (ed->seq + 1);
    }
  }
  return 0;
}

// 0x16fbdc0
s32 NB_FILECHECKEND(NB_FILEHANDLE_T *x) {
  return 1;
}

// 0x16fbdb0
s32 fileCheckEnd(NB_FILEHANDLE_T *fileHandle) {
  return 0;
}

// 0x16fbde0
sdfMemHandle_t *fileGetMemHandle(fileHandle_t *fileHandle) {
  return 0;
}

// 0x16fbdd0
s32 fileHandleFree(fileHandle_t *fileHandle) {
  return 0;
}

// 0x16fbda0
fileHandle_t *fileLoad(char *filename) {
  return 0;
}

// 0x16fcfc0
void *nbE909Process_1(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    nbCameraSetState(0);
    nbSetEnemyFormation(0);
    nbSetPlayerFormation(0, 0);
    nbCameraBoss_Kagu_E909_Set();
    nbCameraBoss_Kagu_E909_Run();
    dds3PadAct(0, 0, 0);
    effPadVibeFadeOUT(0, 0, 0);
    nbUpdateEventProcessData(0);
    return 0;
}
