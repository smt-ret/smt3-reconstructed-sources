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
  Write("カグツチ変身\n", 0);
  ed->data->stat &= ~8u;
  SetAuto(0);
  return 1;
}

// 0x16fbdf0
s32 Model1Start(nbEventProcessData_t *ed) {
  nbFormation_t_o *v7;
  struct System_Int16_array *count;
  struct nbParty_t_array *party;
  struct System_Int16_array *v13;
  s16 v14;
  struct System_Int16_array *v18;
  struct nbParty_t_array *v19;
  struct System_Int16_array *v21;
  s16 v23;
  struct System_Int16_array *v26;
  struct nbParty_t_array *v27;
  struct System_Int16_array *v29;
  s16 v30;
  struct System_Int16_array *v34;
  struct nbParty_t_array *v35;
  struct System_Int16_array *v37;
  s16 v38;
  struct System_Int16_array *v42;
  struct nbParty_t_array *v43;
  s64 partyindex;
  struct System_Int16_array *v46;
  s16 v48;
  System_Byte_array *ResorceData;
  u64 *v52;
  System_String_o *v53;
  s32 v57;
  nbFormation_t_o *form;

  form = 0;
  nbPanelAllHide();
  nbSetOrderSide(0);
  form = nbGetEventForm();
  v7 = form;
  evtSetUnitMotion(&form->hunit, 17, 0, 0, 2);
  party = ed->data->party;
  v13 = party->m_Items[form->partyindex]->count;
  v14 = v13->m_Items[4];
  count->m_Items[4] = v14;
  v18 = count;
  v19 = ed->data->party;
  v21 = v19->m_Items[v7->partyindex]->count;
  v23 = v21->m_Items[5];
  v18->m_Items[5] = v23;
  v26 = count;
  v27 = ed->data->party;
  v29 = v27->m_Items[v7->partyindex]->count;
  v30 = v29->m_Items[6];
  v26->m_Items[6] = v30;
  v34 = count;
  v35 = ed->data->party;
  v37 = v35->m_Items[v7->partyindex]->count;
  v38 = v37->m_Items[7];
  v34->m_Items[7] = v38;
  v42 = count;
  v43 = ed->data->party;
  partyindex = v7->partyindex;
  v46 = v43->m_Items[partyindex]->count;
  v48 = v46->m_Items[8];
  v42->m_Items[8] = v48;
  ResorceData = evtGetResorceData(909, 1);
  nbAddSkillEffectKoukaPacket3(0, 0, ResorceData, 2, &form);
  if (!evtBitCheck(3087))
  {
    v57 = 264;
    v52 = sub_8D3950(s32, &v57);
    v53 = Format("/model/devil/boss/0x{0:x}.PB", v52, 0);
    Model1Start_name = v53;
    ed->file = 0;
  }
  nbBgmFadeOut();
  ++ed->seq;
  ed->seqtime = 0;
  SetAuto(1);
  SetLevel(0.5);
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
  u64 *v3;
  s32 seqtime;
  Il2CppObject *v5;
  s32 v8;

  v8 = 0;
  v3 = sub_8D3950(s32, &v8);
  seqtime = ed->seqtime;
  v5 = v3;
  if (seqtime == 10)
  {
    nbReturnAllEnemyUnit();
    seqtime = ed->seqtime;
  }
  if (seqtime >= 30)
  {
    if (!evtBitCheck(3087))
    {
      mdlPackDecode(1, 264, 0x101u, v5, 0, 0);
    }
    *&ed->seq = (ed->seq + 1);
  }
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
  Il2CppObject *ProcessData;
  nbEventProcessData_t_o *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct nbE909_funcDelegate_array *func;
  s64 seq;
  s32 time;
  s32 v19;
  u8 v20;
  u32 v21;
  dds3ProcessID_t_o *v23[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  ProcessData = dds3GetProcessData(&ida);
  v5 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbEventProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v23);
      if ((v23[0] & 1) != 0)
        v8 = v23[2];
      else
        v8 = v23 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  seq = v5->seq;
  if (Invoke(func->m_Items[seq], v5))
  {
    ida->func_ans = -1;
    return 0;
  }
  if (!v5->time)
  {
    nbCameraSetState(0x17u);
    nbSetEnemyFormation(&v5->data);
    nbSetPlayerFormation(&v5->data, 0);
    nbCameraBoss_Kagu_E909_Set();
  }
  nbCameraBoss_Kagu_E909_Run();
  time = v5->time;
  if (time <= 100)
  {
    if (time <= 40)
    {
      if (time == 20)
      {
        dds3PadAct(0, 0, 0);
        v20 = 110;
      }
      else
      {
        if (time != 40)
          goto LABEL_91;
        dds3PadAct(0, 0, 0);
        v20 = -106;
      }
    }
    else
    {
      if (time != 60)
      {
        if (time != 80)
        {
          if (time != 100)
            goto LABEL_91;
          effPadVibeFadeOUT(0, 0, 0);
          v19 = 40;
          goto LABEL_51;
        }
        dds3PadAct(0, 0, 0);
        v20 = -46;
        v21 = 10;
        goto LABEL_90;
      }
      dds3PadAct(0, 0, 0);
      v20 = -66;
    }
    v21 = 7;
  }
  else
  {
    if (time <= 150)
    {
      if (time != 144)
      {
        if (time != 150)
          goto LABEL_91;
        dds3PadAct(0, 1u, 0xCu);
        v20 = -36;
        v21 = 12;
        goto LABEL_90;
      }
      dds3PadAct(0, 1u, 5u);
      v20 = -56;
    }
    else
    {
      if (time == 166)
      {
        dds3PadAct(0, 0, 0);
        v20 = 120;
        v21 = 60;
        goto LABEL_90;
      }
      if (time != 202)
      {
        if (time != 207)
          goto LABEL_91;
        effPadVibeFadeOUT(0, 1u, 30);
        v19 = 30;
LABEL_51:
        effPadVibeFadeOUT(1u, 0xFFu, v19);
        goto LABEL_91;
      }
      dds3PadAct(0, 1u, 5u);
      v20 = -1;
    }
    v21 = 5;
  }
LABEL_90:
  dds3PadAct(1u, v20, v21);
LABEL_91:
  nbUpdateEventProcessData(&ida);
  return 0;
}
