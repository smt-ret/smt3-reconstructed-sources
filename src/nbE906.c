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
  Write("アーリマン死亡\n", 0);
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
  u64 *v2;
  Il2CppObject *ProcessData;
  nbEventProcessData_t_o *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  struct nbE906_funcDelegate_array *func;
  s64 seq;
  s32 time;
  dds3ModelHandle_t_o *Model;
  s32 v26;
  s32 v28;
  dds3Basic_t_o *v31;
  s32 v33;
  s32 v35;
  struct dds3Basic_t_o **p_pPBCameraBasic01;
  s32 eventrid;
  s32 v42;
  dds3Basic_t_o *v45;
  s32 v47;
  s32 pPBCameraBasicIndex;
  s32 v53;
  s32 v55;
  struct dds3Basic_t_o *v56;
  s32 v60;
  s32 v62;
  s32 v65;
  s32 v67;
  dds3Basic_t_o *v70;
  s32 v72;
  s32 v74;
  u8 v78;
  u32 v79;
  u32 v80;
  dds3Basic_t_o *ActiveScene;
  evtUnitHandle_t_o *h;
  dds3ProcessID_t_o *ida;
  u64 v85[3];

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
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v85);
      if ((v85[0] & 1) != 0)
        v11 = v85[2];
      else
        v11 = v85 + 1;
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
    if (pPBCameraBasic03)
    {
      nbEventPrefabDelete(&pPBCameraBasic03);
      dds3DeleteSceneBasicData(&pPBCameraBasic03);
      pPBCameraBasic03 = 0;
    }
    ida->func_ans = -1;
    return 0;
  }
  time = v8->time;
  if (time < 1)
    goto LABEL_117;
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
  if (time <= 43)
  {
LABEL_117:
    if (time)
    {
      if (time != 43)
        goto LABEL_177;
      eventrid = v8->eventrid;
      v42 = evtRegistBEUnit(eventrid, 4);
      v45 = dds3SearchSceneBasic(&ActiveScene, v42, 5u);
      pPBCameraBasic01 = v45;
      pPBCameraBasicIndex = 4;
      v47 = v8->eventrid;
      nbEventPrefabRead(&pPBCameraBasic01, v47, pPBCameraBasicIndex);
      h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic01);
      p_pPBCameraBasic01 = &pPBCameraBasic01;
    }
    else
    {
      nbCameraSetState(0x17u);
      pPBCameraBasicCurrent = 0;
      pPBCameraBasic00 = 0;
      pPBCameraBasic01 = 0;
      pPBCameraBasic02 = 0;
      pPBCameraBasic03 = 0;
      v53 = v8->eventrid;
      v55 = evtRegistBEUnit(v53, 3);
      v56 = dds3SearchSceneBasic(&ActiveScene, v55, 5u);
      pPBCameraBasic00 = v56;
      pPBCameraBasicIndex = 3;
      v60 = v8->eventrid;
      v62 = pPBCameraBasicIndex;
      nbEventPrefabRead(&pPBCameraBasic00, v60, v62);
      h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic00);
      evtSetUnitMotion(&h, 0, 0, 0, 2);
      p_pPBCameraBasic01 = &pPBCameraBasic00;
    }
  }
  else if (time == 200)
  {
    v65 = v8->eventrid;
    v67 = evtRegistBEUnit(v65, 5);
    v70 = dds3SearchSceneBasic(&ActiveScene, v67, 5u);
    pPBCameraBasic02 = v70;
    pPBCameraBasicIndex = 5;
    v72 = v8->eventrid;
    v74 = pPBCameraBasicIndex;
    nbEventPrefabRead(&pPBCameraBasic02, v72, v74);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic02);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    p_pPBCameraBasic01 = &pPBCameraBasic02;
  }
  else
  {
    if (time != 220)
      goto LABEL_178;
    v26 = v8->eventrid;
    v28 = evtRegistBEUnit(v26, 6);
    v31 = dds3SearchSceneBasic(&ActiveScene, v28, 5u);
    pPBCameraBasic03 = v31;
    pPBCameraBasicIndex = 6;
    v33 = v8->eventrid;
    v35 = pPBCameraBasicIndex;
    nbEventPrefabRead(&pPBCameraBasic03, v33, v35);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic03);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    p_pPBCameraBasic01 = &pPBCameraBasic03;
  }
  pPBCameraBasicCurrent = *p_pPBCameraBasic01;
LABEL_177:
  time = v8->time;
  if (time)
  {
LABEL_178:
    if (time > 276)
      goto LABEL_179;
LABEL_192:
    if (time <= 210)
    {
      if (time <= 45)
      {
        if (time)
        {
          if (time != 45)
            goto LABEL_252;
          dds3PadAct(0, 1u, 0xFu);
          v78 = -1;
          v79 = 15;
          goto LABEL_251;
        }
        v80 = 210;
      }
      else
      {
        if (time != 54)
        {
          if (time != 210)
            goto LABEL_252;
          dds3SetQuake(25, 0x12Cu);
          dds3PadAct(0, 1u, 0x1Eu);
          v78 = -1;
          v79 = 30;
          goto LABEL_251;
        }
        v80 = 160;
      }
      dds3PadAct(0, 0, v80);
      v78 = -116;
      v79 = v80;
LABEL_251:
      dds3PadAct(1u, v78, v79);
      goto LABEL_252;
    }
    if (time <= 246)
    {
      if (time != 240)
      {
        if (time != 246)
          goto LABEL_252;
        goto LABEL_221;
      }
      goto LABEL_225;
    }
    if (time != 260)
    {
      if (time != 270)
      {
        if (time == 276)
          goto LABEL_221;
        goto LABEL_252;
      }
LABEL_225:
      dds3PadAct(0, 1u, 8u);
      v78 = -56;
LABEL_229:
      v79 = 7;
      goto LABEL_251;
    }
LABEL_232:
    dds3PadAct(0, 1u, 8u);
    v78 = -56;
    v79 = 6;
    goto LABEL_251;
  }
  dds3PadAct(0, 0, 0x14u);
  dds3PadAct(1u, 0xAAu, 0x14u);
  time = v8->time;
  if (time <= 276)
    goto LABEL_192;
LABEL_179:
  if (time > 330)
  {
    if (time <= 350)
    {
      if (time != 336)
      {
        if (time != 350)
          goto LABEL_252;
        dds3PadAct(0, 1u, 8u);
        v78 = -76;
        goto LABEL_229;
      }
    }
    else if (time != 356)
    {
      if (time != 370)
      {
        if (time == 376)
        {
          effPadVibeFadeOUT(0, 1u, 70);
          effPadVibeFadeOUT(1u, 0x64u, 70);
        }
        goto LABEL_252;
      }
      dds3PadAct(0, 1u, 8u);
      v78 = -96;
      goto LABEL_229;
    }
LABEL_221:
    dds3PadAct(0, 1u, 0xFu);
    v78 = 100;
    v79 = 15;
    goto LABEL_251;
  }
  if (time <= 300)
  {
    if (time != 290 && time != 300)
      goto LABEL_252;
    goto LABEL_232;
  }
  switch (time)
  {
    case 310:
      goto LABEL_225;
    case 316:
      goto LABEL_221;
    case 330:
      goto LABEL_225;
  }
LABEL_252:
  nbUpdateEventProcessData(&ida);
  return 0;
}
