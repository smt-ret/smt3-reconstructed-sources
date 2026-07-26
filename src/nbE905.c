#include "types.h"

typedef struct NB_FILEHANDLE_T NB_FILEHANDLE_T;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct fileHandle_t fileHandle_t;
typedef struct nbE905_funcDelegate nbE905_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

static s16 count[20];
static u16 Model1Start_name_a[64];
static char *Model1Start_name;
static nbE905_funcDelegate *func[8];
static dds3Basic_t *pPBCameraBasicCurrent;
static dds3Basic_t *pPBCameraBasic00;
static dds3Basic_t *pPBCameraBasic01;
static dds3Basic_t *pPBCameraBasic02;
static s32 pPBCameraBasicIndex;

void SetDrawFlag(u32 flag, u32 cnt);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void dds3SetQuake(s32 frame, u32 range);
void effPadVibeFadeOUT(u32 mode, u8 power, s32 frame);
bool evtBitCheck(s32 no);
u8 **evtGetResorceData(s32 eventno, s32 rid);
s32 evtRegistBEUnit(s32 eventno, s32 rid);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
void mdlPackDecode(s32 major, s32 minor, u32 regFlags, void *buff, s32 leng);
nbKoukaPacket_t *nbAddFadeInKoukaPacket(s32 startframe, s32 uniqueid, s32 length, s32 coltype);
nbKoukaPacket_t *nbAddFadeOutKoukaPacket(s32 startframe, s32 uniqueid, s32 length, s32 coltype);
nbKoukaPacket_t *nbAddFormOnOffPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 sw);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket3(s32 startframe, s32 uniqueid, u8 **bed, s32 cutno, nbFormation_t **form);
nbKoukaPacket_t *nbAddUnitAKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 a, s32 frame);
void nbAddUnitStock(nbMainProcessData_t **data, s32 side, s32 stockno, s32 formindex);
void nbAllFormDispOn(void);
s32 nbAppendEnemyDevilWork(nbMainProcessData_t *data, s32 id, s32 formindex);
void nbBgmFadeOut(void);
void nbBgmLoad(s32 encdata);
s32 nbBgmLoadChk(void);
void nbBgmPlay(void);
void nbCameraBoss_Bsnet_E905_Set(void);
void nbCameraHelperModelSet(dds3ModelHandle_t *hModel);
void nbCameraSetState(u16 state);
s32 nbCheckLoad(nbFormation_t **form);
void nbEventPrefabDelete(dds3Basic_t **pathbasic);
void nbEventPrefabRead(dds3Basic_t **pathbasic, s32 event_no, s32 index);
nbFormation_t *nbGetEventForm(void);
void nbLoadUnit(nbFormation_t **form, s32 stop, s32 anime);
void nbPanelAllHide(void);
void nbPanelPressTurnOmit(void);
void nbReturnAllEnemyUnit(void);
void nbSetEnemyFormation(nbMainProcessData_t **data);
void nbSetPlayerFormation(nbMainProcessData_t **data, s32 empty);
void nbSetUnitPackFileHandle(nbFormation_t **form, NB_FILEHANDLE_T *fh);
void nbUpdateEventProcessData(dds3ProcessID_t **id);

// 0x16f4680
u32 DDS3EFFECT_RGBA(u32 r, u32 g, u32 b, u32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x16f55f0
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime >= 36)
  {
    if (nbBgmLoadChk())
    {
      Write(StringLiteral_21330, 0);
      nbBgmPlay();
      *&ed->seq = (ed->seq + 1);
    }
  }
  return 0;
}

// 0x16f56f0
s32 End0(nbEventProcessData_t *ed) {
  nbPanelPressTurnOmit();
  return 1;
}

// 0x16f46f0
s32 Model1Start(nbEventProcessData_t *ed) {
    nbPanelAllHide();
    nbGetEventForm();
    evtSetUnitMotion(0, 0, 0, 0, 0);
    evtGetResorceData(0, 0);
    nbAddSkillEffectKoukaPacket3(0, 0, 0, 0, 0);
    evtBitCheck(0);
    return 0;
}

// 0x16f4c60
s32 Model1Wait(nbEventProcessData_t *ed) {
  s32 seqtime;

  seqtime = ed->seqtime;
  if (seqtime == 185 || seqtime == 172)
  {
    dds3SetQuake(30, 0x1F4u);
    if (ed->seqtime < 240)
      return 0;
  }
  else if (seqtime == 1)
  {
    nbBgmFadeOut();
    if (ed->seqtime < 240)
      return 0;
  }
  else if (seqtime < 240)
  {
    return 0;
  }
  if (!evtBitCheck(3087))
  {
    ed->mem = 0;
    ed->file = 0;
  }
  nbAddFadeOutKoukaPacket(0, 0, 15, 1);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f4dd0
s32 Model1Wait_2(nbEventProcessData_t *ed) {
    nbReturnAllEnemyUnit();
    evtBitCheck(0);
    mdlPackDecode(0, 0, 0, 0, 0);
    return 0;
}

// 0x16f4ed0
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
  nbFormation_t_o *form;

  form = 0;
  p_fields = &ed->fields;
  data = ed->data;
  v5 = data->form;
  v7 = v5->m_Items[4];
  form = v7;
  formindex = v7->formindex;
  appended = nbAppendEnemyDevilWork(data, 258, formindex);
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
  SetDrawFlag(0x2000000u, 1u);
  nbSetEnemyFormation(&ed->data);
  p_fields->data->encno = 992;
  nbBgmLoad(0);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f5460
s32 Model2Wait_1(nbEventProcessData_t *ed) {
  struct nbFormation_t_array *v3;
  nbFormation_t_o *form;

  form = 0;
  v3 = ed->data->form;
  form = v3->m_Items[4];
  if (!nbCheckLoad(&form))
  {
    SetDrawFlag(0x2000000u, 1u);
    *&ed->seq = (ed->seq + 1);
  }
  return 0;
}

// 0x16f5550
s32 Model2Wait_15(nbEventProcessData_t *ed) {
  nbAddFadeInKoukaPacket(0, 0, 10, 1);
  if (ed)
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f46c0
s32 NB_FILECHECKEND(fileHandle_t *x) {
  return 1;
}

// 0x16f46a0
void effPadVibeFadeIN(u32 mode, u8 power, s32 frame) {
  ;
}

// 0x16f46b0
s32 fileCheckEnd(fileHandle_t *fileHandle) {
  return 0;
}

// 0x16f46e0
sdfMemHandle_t *fileGetMemHandle(fileHandle_t *fileHandle) {
  return 0;
}

// 0x16f46d0
s32 fileHandleFree(fileHandle_t *fileHandle) {
  return 0;
}

// 0x16f4690
fileHandle_t *fileLoad(char *filename) {
  return 0;
}

// 0x16f5760
void *nbE905Process_1(dds3ProcessID_t *id) {
    dds3GetActiveScene();
    dds3GetProcessData(0);
    nbEventPrefabDelete(0);
    dds3DeleteSceneBasicData(0);
    dds3GetUnitHandleObjectBasic(0);
    nbCameraHelperModelSet(0);
    nbCameraSetState(0);
    nbAllFormDispOn();
    nbSetEnemyFormation(0);
    nbSetPlayerFormation(0, 0);
    evtRegistBEUnit(0, 0);
    dds3SearchSceneBasic(0, 0, 0);
    nbEventPrefabRead(0, 0, 0);
    evtSetUnitMotion(0, 0, 0, 0, 0);
    nbCameraBoss_Bsnet_E905_Set();
    dds3PadAct(0, 0, 0);
    effPadVibeFadeOUT(0, 0, 0);
    nbUpdateEventProcessData(0);
    return 0;
}
