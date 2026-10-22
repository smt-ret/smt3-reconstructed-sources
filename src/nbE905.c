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
      Write("アーリマン変身\n", 0);
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
  nbFormation_t_o *v6;
  struct System_Int16_array *count;
  struct nbParty_t_array *party;
  struct System_Int16_array *v12;
  s16 v13;
  struct System_Int16_array *v17;
  struct nbParty_t_array *v18;
  struct System_Int16_array *v20;
  s16 v22;
  struct System_Int16_array *v25;
  struct nbParty_t_array *v26;
  struct System_Int16_array *v28;
  s16 v29;
  struct System_Int16_array *v33;
  struct nbParty_t_array *v34;
  struct System_Int16_array *v36;
  s16 v37;
  struct System_Int16_array *v41;
  struct nbParty_t_array *v42;
  s64 partyindex;
  struct System_Int16_array *v45;
  s16 v47;
  System_Byte_array *ResorceData;
  u64 *v51;
  System_String_o *v52;
  s32 v55;
  nbFormation_t_o *form;

  form = 0;
  nbPanelAllHide();
  form = nbGetEventForm();
  v6 = form;
  evtSetUnitMotion(&form->hunit, 16, 10, 0, 2);
  party = ed->data->party;
  v12 = party->m_Items[form->partyindex]->count;
  v13 = v12->m_Items[4];
  count->m_Items[4] = v13;
  v17 = count;
  v18 = ed->data->party;
  v20 = v18->m_Items[v6->partyindex]->count;
  v22 = v20->m_Items[5];
  v17->m_Items[5] = v22;
  v25 = count;
  v26 = ed->data->party;
  v28 = v26->m_Items[v6->partyindex]->count;
  v29 = v28->m_Items[6];
  v25->m_Items[6] = v29;
  v33 = count;
  v34 = ed->data->party;
  v36 = v34->m_Items[v6->partyindex]->count;
  v37 = v36->m_Items[7];
  v33->m_Items[7] = v37;
  v41 = count;
  v42 = ed->data->party;
  partyindex = v6->partyindex;
  v45 = v42->m_Items[partyindex]->count;
  v47 = v45->m_Items[8];
  v41->m_Items[8] = v47;
  ResorceData = evtGetResorceData(905, 1);
  nbAddSkillEffectKoukaPacket3(0, 0, ResorceData, 2, &form);
  if (!evtBitCheck(3087))
  {
    v55 = 258;
    v51 = sub_8D3950(s32, &v55);
    v52 = Format("/model/devil/boss/0x{0:x}.PB", v51, 0);
    Model1Start_name = v52;
    ed->file = 0;
  }
  *&ed->seq = (ed->seq + 1);
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
  u64 *v3;
  s32 seqtime;
  Il2CppObject *v5;
  s32 v8;

  v8 = 0;
  v3 = sub_8D3950(s32, &v8);
  seqtime = ed->seqtime;
  v5 = v3;
  if (seqtime == 30)
  {
    nbReturnAllEnemyUnit();
    seqtime = ed->seqtime;
  }
  if (seqtime >= 32)
  {
    if (!evtBitCheck(3087))
    {
      mdlPackDecode(1, 258, 0x101u, v5, 0, 0);
    }
    *&ed->seq = (ed->seq + 1);
  }
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
LABEL_6:
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
  u64 *v2;
  Il2CppObject *ProcessData;
  nbEventProcessData_t_o *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  struct nbE905_funcDelegate_array *func;
  s64 seq;
  s32 time;
  dds3ModelHandle_t_o *Model;
  s32 eventrid;
  s32 v30;
  struct dds3Basic_t_o *v31;
  s32 v35;
  s32 pPBCameraBasicIndex;
  struct dds3Basic_t_o *pPBCameraBasic00;
  s32 v42;
  s32 v44;
  dds3Basic_t_o *v47;
  s32 v49;
  s32 v51;
  s32 v54;
  s32 v56;
  dds3Basic_t_o *v59;
  s32 v61;
  s32 v63;
  u8 v66;
  u32 v67;
  dds3Basic_t_o *ActiveScene;
  evtUnitHandle_t_o *h;
  dds3ProcessID_t_o *ida;
  u64 v72[3];

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
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v72);
      if ((v72[0] & 1) != 0)
        v11 = v72[2];
      else
        v11 = v72 + 1;
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
    if (pPBCameraBasic01)
    {
      nbEventPrefabDelete(&pPBCameraBasic01);
      dds3DeleteSceneBasicData(&pPBCameraBasic01);
      pPBCameraBasic01 = 0;
    }
    if (pPBCameraBasic02)
    {
      nbEventPrefabDelete(&pPBCameraBasic02);
      dds3DeleteSceneBasicData(&pPBCameraBasic02);
      pPBCameraBasic02 = 0;
    }
    ida->func_ans = -1;
    return 0;
  }
  time = v8->time;
  if (time < 1)
    goto LABEL_92;
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
  if (time <= 1)
  {
LABEL_92:
    if (time)
    {
      if (time == 1)
      {
        nbCameraSetState(0x17u);
        nbAllFormDispOn();
        nbSetEnemyFormation(&v8->data);
        nbSetPlayerFormation(&v8->data, 0);
      }
      goto LABEL_159;
    }
    pPBCameraBasicCurrent = 0;
    pPBCameraBasic00 = 0;
    pPBCameraBasic01 = 0;
    pPBCameraBasic02 = 0;
    eventrid = v8->eventrid;
    v30 = evtRegistBEUnit(eventrid, 2);
    v31 = dds3SearchSceneBasic(&ActiveScene, v30, 5u);
    pPBCameraBasic00 = v31;
    pPBCameraBasicIndex = 2;
    v35 = v8->eventrid;
    nbEventPrefabRead(&pPBCameraBasic00, v35, pPBCameraBasicIndex);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic00);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    goto LABEL_158;
  }
  if (time == 160)
  {
    v42 = v8->eventrid;
    v44 = evtRegistBEUnit(v42, 3);
    v47 = dds3SearchSceneBasic(&ActiveScene, v44, 5u);
    pPBCameraBasic01 = v47;
    pPBCameraBasicIndex = 3;
    v49 = v8->eventrid;
    v51 = pPBCameraBasicIndex;
    nbEventPrefabRead(&pPBCameraBasic01, v49, v51);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic01);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    pPBCameraBasic00 = pPBCameraBasic01;
    goto LABEL_158;
  }
  if (time == 175)
  {
    v54 = v8->eventrid;
    v56 = evtRegistBEUnit(v54, 4);
    v59 = dds3SearchSceneBasic(&ActiveScene, v56, 5u);
    pPBCameraBasic02 = v59;
    pPBCameraBasicIndex = 4;
    v61 = v8->eventrid;
    v63 = pPBCameraBasicIndex;
    nbEventPrefabRead(&pPBCameraBasic02, v61, v63);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic02);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    pPBCameraBasic00 = pPBCameraBasic02;
LABEL_158:
    pPBCameraBasicCurrent = pPBCameraBasic00;
    goto LABEL_159;
  }
  if (time != 260)
    goto LABEL_160;
  pPBCameraBasicCurrent = 0;
  nbCameraBoss_Bsnet_E905_Set();
LABEL_159:
  time = v8->time;
LABEL_160:
  if (time > 166)
  {
    if (time <= 185)
    {
      if (time == 174)
      {
        dds3PadAct(0, 0, 0);
        v66 = 100;
        v67 = 5;
      }
      else
      {
        if (time != 185)
          goto LABEL_217;
        dds3PadAct(0, 1u, 0x12u);
        v66 = -18;
        v67 = 15;
      }
    }
    else if (time == 200)
    {
      dds3PadAct(0, 0, 0);
      v66 = 100;
      v67 = 30;
    }
    else
    {
      if (time != 210)
      {
        if (time == 230)
        {
          effPadVibeFadeOUT(0, 0, 0);
          effPadVibeFadeOUT(1u, 0xC8u, 40);
        }
        goto LABEL_217;
      }
      dds3PadAct(0, 0, 0);
      v66 = -56;
      v67 = 40;
    }
    goto LABEL_216;
  }
  if (time > 20)
  {
    switch (time)
    {
      case 77:
        dds3PadAct(0, 1u, 0xAu);
        v66 = -86;
        break;
      case 85:
        dds3PadAct(0, 0, 0);
        v66 = 100;
        v67 = 100;
        goto LABEL_216;
      case 166:
        dds3PadAct(0, 1u, 0xAu);
        v66 = -18;
        break;
      default:
        goto LABEL_217;
    }
    v67 = 8;
LABEL_216:
    dds3PadAct(1u, v66, v67);
    goto LABEL_217;
  }
  if (!time)
  {
    goto LABEL_217;
  }
  if (time == 20)
  {
    dds3PadAct(0, 0, 0);
    v66 = 100;
    v67 = 152;
    goto LABEL_216;
  }
LABEL_217:
  nbUpdateEventProcessData(&ida);
  return 0;
}
