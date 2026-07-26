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
    nbGetEventForm();
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    nbSetFormPos(0, (sdfVector4_t){0});
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
    }
    v11 = v7;
    ++v7;
    *(v4 + v11 + 8) = i - 4;
  }
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
      RandIntA = dds3GetRandIntA(0xFu, StringLiteral_416);
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
    dds3GetActiveScene();
    evtGetResorceData(0, 0);
    evtRegistBEUnit(0, 0);
    dds3SearchSceneBasic(0, 0, 0);
    nbEventPrefabRead(0, 0, 0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
    dds3GetUnitHandleObjectBasic(0);
    evtSetUnitMotion(0, 0, 0, 0, 0);
    dds3AddBEDEffectObjectBasic2(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    dds3EffectObjectBasicStatOn(0, 0);
    return 0;
}

// 0x16ebe60
s32 SyuGo(nbEventProcessData_t **ed) {
    nbEventPrefabDelete(0);
    nbCameraBoss_Sp_DOUTYO_TPFix_Set(0);
    dds3GetUnitHandleObjectBasic(0);
    sdfModelGetMarkPosUnity(0, 0);
    SDF_VU0__STOREVECTOR(0);
    nbSetFormPos(0, (sdfVector4_t){0});
    evtUnitRotationTarget(0, (sdfVector4_t){0}, 0);
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
        if (seqtime < 49)
          return 0;
      }
    }
    else    dds3StartBEDEffectObjectBasic(&bedbasic, 2u);
    v3 = *ed;
    if ((*ed)->seqtime >= 49)
    {
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
    ++v3->seq;
    (*ed)->seqtime = 0;
  }
  return 0;
}

// 0x16ecc50
s32 Syutugen2(nbEventProcessData_t **ed) {
    nbGetEventForm();
    nbAddHitEffKoukaPacket(0, 0, 0, 0);
    dds3SetQuake(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    nbSetFormPos(0, (sdfVector4_t){0});
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__STOREVECTOR(0);
    nbCameraBoss_Sp_DOUTYO_Set(0);
    nbCameraBoss_Sp_DOUTYO_Run(0);
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
    dds3GetProcessData(0);
    effPadVibeFadeOUT(0, 0, 0);
    dds3PadAct(0, 0, 0);
    nbUpdateEventProcessData(0);
    return 0;
}
