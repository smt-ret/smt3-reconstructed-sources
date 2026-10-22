#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbCamera_t nbCamera_t;
typedef struct nbE901_funcDelegate nbE901_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

static s32 NB_HELP_TYPE_TXTCONV;
static dds3Basic_t *pathbasic;
static dds3Basic_t *bedbasic;
static s32 encno;
static s32 dvlno;
static nbE901_funcDelegate *func[12];

u8 Get(s32 id);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
dds3Basic_t *dds3AddBEDEffectObjectBasic2(void *data, sdfVector4_t pos, sdfVector4_t rot);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
void dds3EffectObjectBasicStatOn(dds3Basic_t **basic, u32 s);
dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetRandIntA(u32 aLimit, char *name);
evtUnitHandle_t *dds3GetUnitHandleObjectBasic(dds3Basic_t **b);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetQuake(s32 frame, u32 range);
void dds3StartBEDEffectObjectBasic(dds3Basic_t **basic, u32 cutno);
void effBTLSkillEnd(void);
void effBTLSkillStart(u32 id, u32 stat);
void effPadVibeFadeOUT(u32 mode, u8 power, s32 frame);
u8 **evtGetResorceData(s32 eventno, s32 rid);
s32 evtRegistBEUnit(s32 eventno, s32 rid);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
s32 evtUnitRotationTarget(evtUnitHandle_t **h, sdfVector4_t pos, f32 radio);
nbKoukaPacket_t *nbAddHitEffKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type);
nbKoukaPacket_t *nbAddMotionKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 motion);
s32 nbCameraBoss_Sp_DOUTYO_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Sp_DOUTYO_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Sp_DOUTYO_TPFix_Set(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Sp_DOUTYO_TP_Set(nbCamera_t **pNbCamera);
s32 nbCheckLoadGroup(s32 side);
void nbDispText(char *text1, char *text2, s32 type, s32 max, u32 col, bool type_skill);
void nbEventPrefabDelete(dds3Basic_t **pathbasic);
void nbEventPrefabRead(dds3Basic_t **pathbasic, s32 event_no, s32 index);
nbFormation_t *nbGetEventForm(void);
void nbLoadUnitGroup(s32 side, s32 stop, s32 anime);
void nbPanelAllShow(void);
void nbResetAllFormPosRot(void);
void nbReturnAllEnemyUnit(void);
void nbSetEnemyStartData(nbMainProcessData_t *data, s32 enc);
void nbSetFormPos(nbFormation_t **form, sdfVector4_t pos);
void nbSetRenzokuEncount(s32 enc);
void nbUpdateEventProcessData(dds3ProcessID_t **id);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);

// 0x16ec4b0
s32 Cls1(nbEventProcessData_t **ed) {
  nbEventProcessData_t_o *v4;

  nbReturnAllEnemyUnit();
  v4 = *ed;
  if (*ed)
  {
LABEL_6:
    ++v4->seq;
    (*ed)->seqtime = 0;
  }
  return 0;
}

// 0x16ec550
s32 Daisupe(nbEventProcessData_t **ed) {
  s32 encno;
  nbEventProcessData_t_o *v6;

  nbSetRenzokuEncount(encno);
  nbSetEnemyStartData((*ed)->data, encno, 0);
  nbLoadUnitGroup(1, 0, 1);
  v6 = *ed;
  if (*ed)
  {
LABEL_12:
    ++v6->seq;
    (*ed)->seqtime = 0;
  }
  return 0;
}

// 0x16ecfb0
s32 End(nbEventProcessData_t **ed) {
  nbCameraBoss_Sp_DOUTYO_Run(&nbCameraCurrent);
  if ((*ed)->seqtime < 111)
    return 0;
  effBTLSkillEnd();
  nbResetAllFormPosRot();
  dds3DeleteSceneBasicData(&bedbasic);
  (*ed)->data->stat |= 8u;
  (*ed)->data->press4_p = 0;
  (*ed)->data->press4_ten = 0;
  return 1;
}

// 0x16ec670
s32 ReadWait2(nbEventProcessData_t **ed) {
  nbFormation_t_o *EventForm;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  nbFormation_t_o *form;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v14;

  form = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  else
  {
    EventForm = nbGetEventForm(nbEventProcess);
    form = EventForm;
    if (EventForm->type)
      return 0;
  }
  SDF_VU0__COPYVECTOR(&dst, EventForm->pos);
  sub_854710(&dst, 1u);
  sub_854930(&dst, 1u);
  x = dst.x;
  y = dst.y;
  z = dst.z;
  w = dst.w;
  v14.x = x;
  v14.y = y;
  v14.z = z;
  v14.w = w;
  nbSetFormPos(&form, v14);
  if (*ed)
  {
    ++(*ed)->seq;
    (*ed)->seqtime = 0;
  }
  return 0;
}

// 0x16eb0d0
s32 RunUgou(nbEventProcessData_t **ed) {
  u64 *v4;
  s32 v7;
  s64 i;
  struct nbFormation_t_array *v9;
  s64 v11;
  s32 v13;
  s64 v14;
  char *v16;
  u32 *v17;
  s64 v18;
  s64 v19;
  struct nbFormation_t_array *v20;
  s32 v23;
  s32 v24;
  s64 v25;
  s32 v26;
  s64 v28;
  u32 RandIntA;
  struct nbFormation_t_array *v30;
  s64 v32;
  System_String_o *v37;
  s32 NB_HELP_TYPE_TXTCONV;
  nbFormation_t_o *form;

  form = 0;
  v4 = NewSpecific(s32, 0x10u);
  nbPanelAllShow();
  nbResetAllFormPosRot();
  v7 = 0;
  for (i = 8; i != 18; ++i)
  {
    while (1)
    {
      v9 = (*ed)->data->form;
      if ((*(*(&v9->obj.klass + i) + 136LL) & 1) != 0)
        break;
      if (++i == 18)
        goto LABEL_18;
    }
    v11 = v7;
    ++v7;
    *(v4 + v11 + 8) = i - 4;
  }
LABEL_18:
  if (v7 >= 0)
    v13 = v7;
  else
    v13 = v7 + 1;
  v14 = v13 >> 1;
  v16 = v4 + 4 * v14;
  v19 = *(v16 + 8);
  v17 = v16 + 32;
  v18 = v19;
  v20 = (*ed)->data->form;
  form = v20->m_Items[v18];
  if (v7 <= 3)
  {
    v23 = 296;
    v24 = 274;
  }
  else
  {
    if (v7 <= 5)
    {
      v23 = 295;
      v24 = 273;
    }
    else
    {
      v23 = 294;
      v24 = 272;
    }
  }
  encno = v24;
  dvlno = v23;
  v25 = v4[3];
  v26 = *(v4 + 8);
  *(v4 + 8) = *v17;
  *v17 = v26;
  nbAddMotionKoukaPacket(0, 0, &form, 16);
  if (v7 >= 2)
  {
    v28 = 0;
    do
    {
      RandIntA = dds3GetRandIntA(0xFu, "");
      v30 = (*ed)->data->form;
      v32 = *(v4 + v28 + 9);
      nbAddMotionKoukaPacket(RandIntA + 15, 0, &v30->m_Items[v32], 16);
      ++v28;
    }
    while (v7 - 1LL != v28);
  }
  effBTLSkillStart(0xE8u, 0);
  nbCameraBoss_Sp_DOUTYO_TP_Set(&nbCameraCurrent);
  v37 = Get(232, 0, 0);
  nbDispText(v37, 0, NB_HELP_TYPE_TXTCONV, 90, 0x89FEFF80, 0);
  if (*ed)
  {
    ++(*ed)->seq;
    (*ed)->seqtime = 0;
  }
  return 0;
}

// 0x16eb6d0
s32 SetUp1(nbEventProcessData_t **ed) {
  u64 *v3;
  System_Byte_array *ResorceData;
  s32 v8;
  dds3Basic_t_o *v11;
  s32 eventrid;
  s64 v15;
  s64 v16;
  dds3Basic_t_o *pBasic;
  evtUnitHandle_t_o *h;
  UnityEngine_Vector4_o v22;
  UnityEngine_Vector4_o v23;
  dds3Basic_t_o *basic;
  UnityEngine_Vector4_o v25;

  *&v23.x = 0;
  *&v23.z = 0;
  *&v22.x = 0;
  *&v22.z = 0;
  pBasic = 0;
  sub_854690(&v23.x, 0.0, -600.0, 0.0, 0.0);
  sub_854690(&v22.x, 0.0, 0.0, 0.0, 1.0);
  v3 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v3);
  h = v3;
  pBasic = dds3GetActiveScene();
  ResorceData = evtGetResorceData(901, 2);
  v8 = evtRegistBEUnit((*ed)->eventrid, 1, 0);
  v11 = dds3SearchSceneBasic(&pBasic, v8, 5u);
  pathbasic = v11;
  eventrid = (*ed)->eventrid;
  nbEventPrefabRead(&pathbasic, eventrid, 2);
  sub_854930(&v23, 0);
  sub_854930(&v23, 1u);
  sub_854930(&v23, 2u);
  v15 = *&v23.x;
  v16 = *&v23.z;
  *&v25.x = v15;
  *&v25.z = v16;
  dds3SetPosPoseSet(&pathbasic, v25);
  h = dds3GetUnitHandleObjectBasic(&pathbasic);
  evtSetUnitMotion(&h, 0, 0, 0, 2);
  basic = dds3AddBEDEffectObjectBasic2(&ResorceData->obj, v23, v22);
  dds3EffectObjectBasicStatOn(&basic, 1u);
  bedbasic = basic;
  if (*ed)
  {
    ++(*ed)->seq;
    (*ed)->seqtime = 0;
  }
  return 0;
}

// 0x16ebe60
s32 SyuGo(nbEventProcessData_t **ed) {
  u64 *v3;
  nbEventProcessData_t_o *v5;
  s32 seqtime;
  evtUnitHandle_t_o *UnitHandleObjectBasic;
  s32 v9;
  s64 i;
  struct nbFormation_t_array *v11;
  sdfModelRootNode_t_o *modelRoot;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  struct evtUnitHandle_t_o **p_hunit;
  s64 v21;
  s64 v22;
  f32 v23;
  evtUnitHandle_t_o **v24;
  s64 v25;
  s64 v26;
  nbFormation_t_o *form;
  s64 v30;
  s64 v31;
  s64 v32;
  s64 v33;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v37;
  UnityEngine_Vector4_o v38;

  form = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  *&p.x = 0;
  *&p.z = 0;
  sub_854690(&v32, 0.0, 0.0, -100.0, 0.0);
  sub_854690(&v30, 0.0, 0.0, -5000.0, 0.0);
  v3 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v3);
  v5 = *ed;
  seqtime = (*ed)->seqtime;
  if (seqtime != 2)
  {
    if (seqtime != 5)
      goto LABEL_5;
LABEL_42:
    v5->data->press4_p = 0;
    (*ed)->data->press4_ten = 0;
    v5 = *ed;
    if ((*ed)->seqtime < 56)
      goto LABEL_6;
LABEL_43:
    if (v5)
    {
      ++v5->seq;
      (*ed)->seqtime = 0;
    }
    nbEventPrefabDelete(&pathbasic);
    return 0;
  }
  nbCameraBoss_Sp_DOUTYO_TPFix_Set(&nbCameraCurrent);
  v5 = *ed;
  seqtime = (*ed)->seqtime;
  if (seqtime == 5)
    goto LABEL_42;
LABEL_5:
  if (seqtime >= 56)
    goto LABEL_43;
LABEL_6:
  UnitHandleObjectBasic = dds3GetUnitHandleObjectBasic(&pathbasic);
  v9 = 5;
  for (i = 8; i != 14; ++i)
  {
    while (1)
    {
      v11 = (*ed)->data->form;
      form = *(&v11->obj.klass + i);
      if ((form->stat & 1) != 0)
        break;
      ++i;
      --v9;
      if (i == 14)
        return 0;
    }
    modelRoot = UnitHandleObjectBasic->Model->modelRoot;
    sdfModelGetMarkPosUnity(modelRoot, v9);
    SDF_VU0__STOREVECTOR(&p);
    x = p.x;
    y = p.y;
    z = p.z;
    w = p.w;
    v37.x = x;
    v37.y = y;
    v37.z = z;
    v37.w = w;
    nbSetFormPos(&form, v37);
    p_hunit = &form->hunit;
    if ((*ed)->seqtime <= 50)
    {
      v25 = v32;
      v26 = v33;
      v24 = p_hunit;
      *&v38.x = v25;
      *&v38.z = v26;
      v23 = 0.08;
    }
    else
    {
      v21 = v30;
      v22 = v31;
      *&v38.x = v21;
      *&v38.z = v22;
      v23 = 0.05;
      v24 = p_hunit;
    }
    evtUnitRotationTarget(v24, v38, v23);
    --v9;
  }
  return 0;
}

// 0x16ec320
s32 SyuGo2(nbEventProcessData_t **ed) {
  nbEventProcessData_t_o *v3;
  s32 seqtime;
  u64 v5;
  s64 i;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v9;

  v3 = *ed;
  seqtime = (*ed)->seqtime;
  if (seqtime >= 11)
  {
    if (seqtime == 11)
    {
      v5 = 4;
      for (i = 64; i != 144; i += 8)
      {
        form = v3->data->form;
        if (((*(&form->obj.klass + i))->_1.events & 1) != 0)
        {
          v9 = (*ed)->data->form;
          nbAddMotionKoukaPacket(0, 0, (v9 + i), 4, 0);
        }
        v3 = *ed;
        ++v5;
      }
      seqtime = v3->seqtime;
      if (seqtime != 25)
      {
LABEL_6:
        if (seqtime < 49)
          return 0;
        goto LABEL_21;
      }
    }
    else if (seqtime != 25)
    {
      goto LABEL_6;
    }
    dds3StartBEDEffectObjectBasic(&bedbasic, 2u);
    v3 = *ed;
    if ((*ed)->seqtime >= 49)
    {
LABEL_21:
      if (v3)
      {
        ++v3->seq;
        (*ed)->seqtime = 0;
      }
    }
  }
  return 0;
}

// 0x16ecbc0
s32 Syutugen(nbEventProcessData_t **ed) {
  nbEventProcessData_t_o *v3;

  v3 = *ed;
  if (*ed)
  {
LABEL_6:
    ++v3->seq;
    (*ed)->seqtime = 0;
  }
  return 0;
}

// 0x16ecc50
s32 Syutugen2(nbEventProcessData_t **ed) {
  s32 seqtime;
  u64 v6;
  f32 v8;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  s32 v14;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  nbFormation_t_o *EventForm;
  nbFormation_t_o *form;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v26;
  UnityEngine_Vector4_o v27;

  EventForm = 0;
  form = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  EventForm = nbGetEventForm();
  seqtime = (*ed)->seqtime;
  if (seqtime == 3)
  {
    nbAddHitEffKoukaPacket(0, 0, &EventForm, 4);
    if ((*ed)->seqtime != 5)
    {
LABEL_8:
        goto LABEL_16;
      goto LABEL_9;
    }
  }
  else if (seqtime != 5)
  {
    goto LABEL_8;
  }
  dds3SetQuake(30, 0x258u);
  {
LABEL_9:
  }
LABEL_16:
  form = nbGetEventForm(v6);
  SDF_VU0__COPYVECTOR(&dst, form->pos);
  sub_854710(&dst, 1u);
  sub_854930(&dst, 1u);
  sub_854710(&dst, 1u);
  if (v8 > 0.0)
  {
    sub_854930(&dst, 1u);
    if (*ed)
    {
      ++(*ed)->seq;
      (*ed)->seqtime = 0;
    }
  }
  x = dst.x;
  y = dst.y;
  z = dst.z;
  w = dst.w;
  v26.x = x;
  v26.y = y;
  v26.z = z;
  v26.w = w;
  nbSetFormPos(&form, v26);
  v14 = (*ed)->seqtime;
  if (v14 >= 4)
  {
    if (v14 == 4)
    {
      SDF_VU0__LOADVECTOR(form->pos);
      SDF_VU0__STOREVECTOR(&dst);
      SDF_VU0__STOREVECTOR(&p);
      sub_854930(&dst, 1u);
      v17 = dst.x;
      v16 = dst.y;
      v19 = dst.z;
      v18 = dst.w;
      v27.x = v17;
      v27.y = v16;
      v27.z = v19;
      v27.w = v18;
      nbSetFormPos(&form, v27);
      nbCameraBoss_Sp_DOUTYO_Set(&nbCameraCurrent);
      nbSetFormPos(&form, p);
    }
    else
    {
      nbCameraBoss_Sp_DOUTYO_Run(&nbCameraCurrent);
    }
  }
  return 0;
}

// 0x16eb640
s32 Wait1(nbEventProcessData_t **ed) {
  nbEventProcessData_t_o *v3;

  v3 = *ed;
  if ((*ed)->seqtime >= 66)
  {
    if (v3)
    {
      ++v3->seq;
      (*ed)->seqtime = 0;
    }
  }
  return 0;
}

// 0x16ecb20
s32 Wait2(nbEventProcessData_t **ed) {
  if ((*ed)->seqtime >= 31 && !nbCheckLoadGroup(1))
  {
    if (*ed)
    {
      ++(*ed)->seq;
      (*ed)->seqtime = 0;
    }
  }
  return 0;
}

// 0x16ed140
void *nbE901Process_1(dds3ProcessID_t *id) {
  nbEventProcessData_t_o *ProcessData;
  nbEventProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct nbE901_funcDelegate_array *func;
  s64 seq;
  s32 time;
  nbEventProcessData_t_o *UnnamedParameter;
  dds3ProcessID_t_o *ida;
  u64 v18[3];

  ida = id;
  UnnamedParameter = 0;
  else
  {
    ProcessData = dds3GetProcessData(&ida);
    if (!ProcessData)
      goto LABEL_12;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbEventProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v18);
    if ((v18[0] & 1) != 0)
      v7 = v18[2];
    else
      v7 = v18 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_12:
  UnnamedParameter = ProcessData;
  seq = ProcessData->seq;
  if (Invoke(func->m_Items[seq], &UnnamedParameter))
  {
    ida->func_ans = -1;
  }
  else
  {
    time = UnnamedParameter->time;
    if (time == 222)
    {
      effPadVibeFadeOUT(0, 1u, 45);
      effPadVibeFadeOUT(1u, 0x8Cu, 45);
    }
    else if (time == 212)
    {
      dds3PadAct(0, 1u, 0xAu);
      dds3PadAct(1u, 0xE1u, 0xAu);
    }
    nbUpdateEventProcessData(&ida);
  }
  return 0;
}
