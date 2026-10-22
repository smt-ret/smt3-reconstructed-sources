#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effBTLCutHandle_t effBTLCutHandle_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbE903_funcDelegate nbE903_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

static s32 NB_HELP_TYPE_TXTCONV;
static nbE903_funcDelegate *func[8];
static dds3Basic_t *pPBCameraBasicCurrent;
static dds3Basic_t *pPBCameraBasic00;
static dds3Basic_t *pPBCameraBasic01;
static dds3Basic_t *pPBCameraBasic02;
static s32 pPBCameraBasicIndex;

u8 Get(s32 id);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
u32 effBTLCutGetFrame(effBTLCutHandle_t **hBTLCutEffect);
void effBTLCutSetDrawEndFrame(effBTLCutHandle_t **hBTLCutEffect, u32 frame);
u8 **evtGetResorceData(s32 eventno, s32 rid);
s32 evtRegistBEUnit(s32 eventno, s32 rid);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
nbKoukaPacket_t *nbAddMotionKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 motion);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket3(s32 startframe, s32 uniqueid, u8 **bed, s32 cutno, nbFormation_t **form);
nbKoukaPacket_t *nbAddUnitAKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 a, s32 frame);
void nbAddUnitStock(nbMainProcessData_t **data, s32 side, s32 stockno, s32 formindex);
void nbAllFormDispOn(void);
s32 nbAppendEnemyDevilWork(nbMainProcessData_t *data, s32 id, s32 formindex);
void nbCameraHelperModelSet(dds3ModelHandle_t *hModel);
void nbCameraSetState(u16 state);
s32 nbCheckLoadGroup(s32 side);
void nbDispText(char *text1, char *text2, s32 type, s32 max, u32 col, bool type_skill);
void nbEventPbRead(s32 event_no, s32 index);
void nbEventPrefabDelete(dds3Basic_t **pathbasic);
void nbEventPrefabRead(dds3Basic_t **pathbasic, s32 event_no, s32 index);
void nbFormDispOn(s32 formindex);
nbFormation_t *nbGetEventForm(void);
void nbGroupFormDispOff(s32 side);
void nbLoadUnit(nbFormation_t **form, s32 stop, s32 anime);
void nbPanelAllHide(void);
void nbResetFormPosRot(nbFormation_t **form);
void nbSetFormPos(nbFormation_t **form, sdfVector4_t pos);
void nbUpdateEventProcessData(dds3ProcessID_t **id);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);

// 0x16f1a10
s32 EffDel(nbEventProcessData_t *ed) {
  dds3ProcessID_t_o **p_KoukaProcessID;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *i;
  u32 Frame;
  char *v11;
  s64 *v12;
  u64 v13[3];

  if (ed->seqtime == 75)
  {
    p_KoukaProcessID = &ed->data->KoukaProcessID;
    ProcessData = dds3GetProcessData(p_KoukaProcessID);
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbKoukaProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbKoukaProcessData_t, v13);
      if ((v13[0] & 1) != 0)
        v11 = v13[2];
      else
        v11 = v13 + 1;
      v12 = sub_8C4940(v11);
    }
    for (i = ProcessData[2].klass; i; i = i->_1.byval_arg.data)
    {
      if (LODWORD(i->_1.namespaze) == 1 && BYTE4(i->_1.name) == 43 && i->_1.declaringType)
      {
        Frame = effBTLCutGetFrame(&i->_1.declaringType);
        effBTLCutSetDrawEndFrame(&i->_1.declaringType, Frame + 12);
      }
    }
    if (ed)
      *&ed->seq = (ed->seq + 1);
  }
  return 0;
}

// 0x16f1be0
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 31)
    return 0;
  Write("アルビオンパーツ生み出し\n", 0);
  ed->data->stat |= 0x2000u;
  return 1;
}

// 0x16f0900
s32 Hatudo(nbEventProcessData_t *ed) {
  System_String_o *v8;
  s32 NB_HELP_TYPE_TXTCONV;
  nbFormation_t_o *form;

  form = 0;
  nbPanelAllHide();
  form = nbGetEventForm();
  nbAddMotionKoukaPacket(0, 0, &form, 4);
  nbResetFormPosRot(&form);
  v8 = Get(236, 0, 0);
  nbDispText(v8, 0, NB_HELP_TYPE_TXTCONV, 90, 0x89FEFF80, 0);
  if (ed)
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f0b70
s32 Parts1(nbEventProcessData_t *ed) {
  nbFormation_t_o *form;

  form = 0;
  form = nbGetEventForm();
  nbAddMotionKoukaPacket(0, 0, &form, 16);
  if (ed)
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f0c10
s32 PartsEffect1(nbEventProcessData_t *ed) {
  u64 *v3;
  System_Array_o *v4;
  s32 seqtime;
  nbEventProcessData_t_Fields *p_fields;
  struct nbMainProcessData_t_o *data;
  struct nbFormation_t_array *v9;
  s64 v11;
  nbFormation_t_o *v13;
  nbMainProcessData_t_o *v14;
  s32 v16;
  s32 formindex;
  s32 appended;
  struct nbFormation_t_array *v20;
  s64 v22;
  nbFormation_t_o *v24;
  nbMainProcessData_t_o *v25;
  s32 v27;
  s32 v28;
  s32 v29;
  struct nbFormation_t_array *v31;
  s64 v33;
  nbFormation_t_o *v35;
  nbMainProcessData_t_o *v36;
  s32 v38;
  s32 v39;
  s32 v40;
  struct nbFormation_t_array *v42;
  s64 v44;
  nbFormation_t_o *v46;
  nbMainProcessData_t_o *v47;
  s32 v49;
  s32 v50;
  s32 v51;
  struct nbFormation_t_array *v52;
  nbFormation_t_o **v54;
  s32 v55;
  struct nbFormation_t_array *v56;
  struct nbFormation_t_array *v58;
  nbFormation_t_o *v60;
  u64 v61;
  System_Array_o *v62;
  struct nbFormation_t_array *v63;
  s64 v65;
  s32 v68;
  evtUnitHandle_t_o **p_hunit;
  struct nbFormation_t_array *v71;
  struct nbFormation_t_array *v73;
  sdfModelRootNode_t_o *modelRoot;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  System_Byte_array *ResorceData;
  nbFormation_t_o *v86;
  nbFormation_t_o *form;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v89;

  v86 = 0;
  form = 0;
  *&p.x = 0;
  *&p.z = 0;
  v3 = NewSpecific(s32, 4u);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__2022FB80865CA39DF593F9A59964801E4F044BF2);
  v4 = NewSpecific(s32, 4u);
  InitializeArray_1543888(v4, Field__PrivateImplementationDetails__2D9F10F6B76B71F204C153E93F77FC483ABB3B9B);
  seqtime = ed->seqtime;
  if (seqtime == 1)
  {
    data = ed->data;
    p_fields = &ed->fields;
    v9 = data->form;
    v11 = SLODWORD(v4[2].klass) + 4LL;
    v13 = v9->m_Items[v11];
    form = v13;
    v14 = p_fields->data;
    v16 = *(v3 + 8);
    formindex = v13->formindex;
    appended = nbAppendEnemyDevilWork(v14, v16, formindex);
    nbAddUnitStock(&p_fields->data, 1, appended, form->formindex);
    nbLoadUnit(&form, 0, 0);
    v20 = p_fields->data->form;
    v22 = SHIDWORD(v4[2].klass) + 4LL;
    v24 = v20->m_Items[v22];
    form = v24;
    v25 = p_fields->data;
    v27 = *(v3 + 9);
    v28 = v24->formindex;
    v29 = nbAppendEnemyDevilWork(v25, v27, v28);
    nbAddUnitStock(&p_fields->data, 1, v29, form->formindex);
    nbLoadUnit(&form, 0, 0);
    v31 = p_fields->data->form;
    v33 = SLODWORD(v4[2].monitor) + 4LL;
    v35 = v31->m_Items[v33];
    form = v35;
    v36 = p_fields->data;
    v38 = *(v3 + 10);
    v39 = v35->formindex;
    v40 = nbAppendEnemyDevilWork(v36, v38, v39);
    nbAddUnitStock(&p_fields->data, 1, v40, form->formindex);
    nbLoadUnit(&form, 0, 0);
    v42 = p_fields->data->form;
    v44 = SHIDWORD(v4[2].monitor) + 4LL;
    v46 = v42->m_Items[v44];
    form = v46;
    v47 = p_fields->data;
    v49 = *(v3 + 11);
    v50 = v46->formindex;
    v51 = nbAppendEnemyDevilWork(v47, v49, v50);
    nbAddUnitStock(&p_fields->data, 1, v51, form->formindex);
    nbLoadUnit(&form, 0, 0);
    return 0;
  }
  if (seqtime <= 61)
  {
    if (seqtime == 34)
    {
      v71 = ed->data->form;
      v55 = 0;
      v54 = &v71->m_Items[4];
    }
    else
    {
      if (seqtime != 61)
        return 0;
      v56 = ed->data->form;
      v54 = &v56->m_Items[5];
      v55 = 1;
    }
  }
  else if (seqtime == 88)
  {
    v58 = ed->data->form;
    v54 = &v58->m_Items[7];
    v55 = 2;
  }
  else
  {
    if (seqtime != 111)
    {
      v60 = 0;
      v55 = 0;
      if (seqtime < 136)
        goto LABEL_80;
      goto LABEL_56;
    }
    v52 = ed->data->form;
    v54 = &v52->m_Items[8];
    v55 = 3;
  }
  v60 = *v54;
  form = *v54;
  if (ed->seqtime < 136)
  {
LABEL_80:
    if (!v60)
      return 0;
    goto LABEL_81;
  }
LABEL_56:
  if (nbCheckLoadGroup(1))
    goto LABEL_80;
  v61 = 0;
  v62 = v4 + 2;
  do
  {
    v63 = ed->data->form;
    v65 = *(&v62->klass + v61) + 4LL;
    v86 = v63->m_Items[v65];
    v68 = *(&v62->klass + v61);
    nbFormDispOn(v68 + 4);
    nbAddUnitAKoukaPacket(0, 0, &v86, 0, 0);
    nbAddUnitAKoukaPacket(1, 0, &v86, 0x80000000, 0);
    p_hunit = &v86->hunit;
    evtSetUnitMotion(p_hunit, 17, 0, 0, 0);
    ++v61;
  }
  while (v61 != 4);
  *&ed->seq = (ed->seq + 1);
  if (form)
  {
LABEL_81:
    v73 = ed->data->form;
    modelRoot = v73->m_Items[6]->hunit->Model->modelRoot;
    sdfModelGetMarkPosUnity(modelRoot, v55 + 30);
    SDF_VU0__STOREVECTOR(&p);
    sub_854930(&p, 1u);
    x = p.x;
    y = p.y;
    z = p.z;
    w = p.w;
    v89.x = x;
    v89.y = y;
    v89.z = z;
    v89.w = w;
    nbSetFormPos(&form, v89);
    nbEventPbRead(903, v55 + 1);
    ResorceData = evtGetResorceData(903, v55 + 1);
    nbAddSkillEffectKoukaPacket3(0, 1, ResorceData, 2, &form);
  }
  return 0;
}

// 0x16f16f0
s32 PartsEffect2(nbEventProcessData_t *ed) {
  System_Array_o *v3;
  struct nbFormation_t_array *v5;
  s64 v7;
  System_Byte_array *ResorceData;
  struct nbFormation_t_array *v11;
  s64 v13;
  System_Byte_array *v15;
  struct nbFormation_t_array *v17;
  s64 v19;
  System_Byte_array *v21;
  struct nbFormation_t_array *v23;
  s64 v25;
  System_Byte_array *v27;
  nbFormation_t_o *form;

  form = 0;
  v3 = NewSpecific(s32, 4u);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__2D9F10F6B76B71F204C153E93F77FC483ABB3B9B);
  v5 = ed->data->form;
  v7 = SLODWORD(v3[2].klass) + 4LL;
  form = v5->m_Items[v7];
  ResorceData = evtGetResorceData(903, 5);
  nbAddSkillEffectKoukaPacket3(0, 0, ResorceData, 2, &form);
  v11 = ed->data->form;
  v13 = SHIDWORD(v3[2].klass) + 4LL;
  form = v11->m_Items[v13];
  v15 = evtGetResorceData(903, 6);
  nbAddSkillEffectKoukaPacket3(0, 0, v15, 2, &form);
  v17 = ed->data->form;
  v19 = SLODWORD(v3[2].monitor) + 4LL;
  form = v17->m_Items[v19];
  v21 = evtGetResorceData(903, 7);
  nbAddSkillEffectKoukaPacket3(0, 0, v21, 2, &form);
  v23 = ed->data->form;
  v25 = SHIDWORD(v3[2].monitor) + 4LL;
  form = v23->m_Items[v25];
  v27 = evtGetResorceData(903, 8);
  nbAddSkillEffectKoukaPacket3(0, 0, v27, 2, &form);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f1650
s32 PartsWait(nbEventProcessData_t *ed) {
  if ((byte_3F5A409 & 1) != 0)
  {
    if (ed->seqtime < 9)
      return 0;
  }
  else
  {
    if (ed->seqtime < 9)
      return 0;
  }
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f0aa0
s32 Wait1(nbEventProcessData_t *ed) {
  s32 seqtime;

  nbGetEventForm();
  seqtime = ed->seqtime;
  else if (seqtime < 31)
  {
    return 0;
  }
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16f08f0
u16 mdlGetMotionLength(dds3ModelHandle_t *aHandle) {
  return 30;
}

// 0x16f1c90
void *nbE903Process_1(dds3ProcessID_t *id) {
  u64 *v2;
  Il2CppObject *ProcessData;
  nbEventProcessData_t_o *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  struct nbE903_funcDelegate_array *func;
  s64 seq;
  s32 time;
  dds3ModelHandle_t_o *Model;
  s32 v28;
  s32 v30;
  struct dds3Basic_t_o *v31;
  s32 v35;
  s32 v37;
  struct dds3Basic_t_o **p_pPBCameraBasic02;
  s32 eventrid;
  s32 v44;
  dds3Basic_t_o *v47;
  s32 v49;
  s32 pPBCameraBasicIndex;
  s32 v54;
  s32 v56;
  dds3Basic_t_o *v59;
  s32 v61;
  s32 v63;
  dds3Basic_t_o *ActiveScene;
  evtUnitHandle_t_o *h;
  dds3ProcessID_t_o *ida;
  u64 v70[3];

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
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v70);
      if ((v70[0] & 1) != 0)
        v11 = v70[2];
      else
        v11 = v70 + 1;
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
  if (time == 190)
  {
    eventrid = v8->eventrid;
    v44 = evtRegistBEUnit(eventrid, 11);
    v47 = dds3SearchSceneBasic(&ActiveScene, v44, 5u);
    pPBCameraBasic02 = v47;
    pPBCameraBasicIndex = 11;
    v49 = v8->eventrid;
    nbEventPrefabRead(&pPBCameraBasic02, v49, pPBCameraBasicIndex);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic02);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    p_pPBCameraBasic02 = &pPBCameraBasic02;
  }
  else if (time == 50)
  {
    v54 = v8->eventrid;
    v56 = evtRegistBEUnit(v54, 10);
    v59 = dds3SearchSceneBasic(&ActiveScene, v56, 5u);
    pPBCameraBasic01 = v59;
    pPBCameraBasicIndex = 10;
    v61 = v8->eventrid;
    v63 = pPBCameraBasicIndex;
    nbEventPrefabRead(&pPBCameraBasic01, v61, v63);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic01);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    p_pPBCameraBasic02 = &pPBCameraBasic01;
  }
  else
  {
    if (time)
      goto LABEL_149;
    nbCameraSetState(0x17u);
    nbAllFormDispOn();
    nbGroupFormDispOff(0);
    pPBCameraBasicCurrent = 0;
    pPBCameraBasic00 = 0;
    pPBCameraBasic01 = 0;
    pPBCameraBasic02 = 0;
    v28 = v8->eventrid;
    v30 = evtRegistBEUnit(v28, 9);
    v31 = dds3SearchSceneBasic(&ActiveScene, v30, 5u);
    pPBCameraBasic00 = v31;
    pPBCameraBasicIndex = 9;
    v35 = v8->eventrid;
    v37 = pPBCameraBasicIndex;
    nbEventPrefabRead(&pPBCameraBasic00, v35, v37);
    h = dds3GetUnitHandleObjectBasic(&pPBCameraBasic00);
    evtSetUnitMotion(&h, 0, 0, 0, 2);
    p_pPBCameraBasic02 = &pPBCameraBasic00;
  }
  pPBCameraBasicCurrent = *p_pPBCameraBasic02;
LABEL_149:
  nbUpdateEventProcessData(&ida);
  return 0;
}
