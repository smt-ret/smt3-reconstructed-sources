#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effBTLCutHandle_t effBTLCutHandle_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct evtUnitHandle_t_ActionDelegate evtUnitHandle_t_ActionDelegate;
typedef struct nbE912_funcDelegate nbE912_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

static s32 NB_HELP_TYPE_TXTCONV;
static s8 formlist[4];
static sdfVector4_t *pos[4];
static sdfVector4_t cen;
static sdfVector4_t off;
static nbKoukaPacket_t *Effect1_pKoukaPacketEff[3];
static nbE912_funcDelegate *func[5];
static dds3Basic_t *pPBCameraBasicCurrent;
static dds3Basic_t *pPBCameraBasic00;
static dds3Basic_t *pPBCameraBasic01;
static s32 pPBCameraBasicIndex;

u8 Get(s32 id);
void MoveSub(nbEventProcessData_t *ed);
void SDF_VU0__ADDVECTOR(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
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
void evtSetUnitMove1(evtUnitHandle_t **h, s32 movetype, sdfVector4_t pos, s32 motion, s32 para1, s32 para2, evtUnitHandle_t_ActionDelegate *func, void *data);
s32 evtUnitRotationTarget(evtUnitHandle_t **h, sdfVector4_t pos, f32 radio);
nbKoukaPacket_t *nbAddMotionKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 motion);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket3(s32 startframe, s32 uniqueid, u8 **bed, s32 cutno, nbFormation_t **form);
nbKoukaPacket_t *nbAddUnitAKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 a, s32 frame);
void nbAddUnitStock(nbMainProcessData_t **data, s32 side, s32 stockno, s32 formindex);
void nbAllFormDispOn(void);
s32 nbAppendEnemyDevilWork(nbMainProcessData_t *data, s32 id, s32 formindex);
void nbCameraBoss_BSALBI_E912_Run(void);
void nbCameraBoss_BSALBI_E912_Set(void);
void nbCameraHelperModelSet(dds3ModelHandle_t *hModel);
void nbCameraSetState(u16 state);
s32 nbCheckLoadGroup(s32 side);
void nbDispText(char *text1, char *text2, s32 type, s32 max, u32 col, bool type_skill);
void nbEventPbRead(s32 event_no, s32 index);
void nbEventPrefabDelete(dds3Basic_t **pathbasic);
void nbEventPrefabRead(dds3Basic_t **pathbasic, s32 event_no, s32 index);
void nbFormDispOn(s32 formindex);
void nbGroupFormDispOff(s32 side);
void nbLoadUnit(nbFormation_t **form, s32 stop, s32 anime);
void nbPanelAllHide(void);
void nbSetFormPosRot(nbFormation_t **form, sdfVector4_t pos, sdfVector4_t rot);
void nbSetFormRot(nbFormation_t **form, sdfVector4_t rot, bool look2);
void nbUpdateEventProcessData(dds3ProcessID_t **id);

// 0x1701590
s32 Effect1(nbEventProcessData_t *ed) {
  struct nbFormation_t_array *v4;
  s32 seqtime;
  struct nbKoukaPacket_t_array *v8;
  effBTLCutHandle_t_o **p_cuteff;
  u32 Frame;
  struct nbKoukaPacket_t_array *v12;
  struct nbKoukaPacket_t_array *v14;
  u32 v16;
  struct nbKoukaPacket_t_array *v17;
  System_Byte_array *v20;
  s64 i;
  u64 v24;
  struct nbFormation_t_array *v25;
  struct System_SByte_array *formlist;
  s64 v28;
  struct nbFormation_t_array *v31;
  struct System_SByte_array *v32;
  struct nbKoukaPacket_t_array *Effect1_pKoukaPacketEff;
  System_Byte_array *ResorceData;
  s64 *Packet__nbAddSkillEffectKoukaPacket3;
  s64 *v40;
  struct nbKoukaPacket_t_array *v45;
  System_Byte_array *v46;
  s64 *v47;
  s64 *v48;
  evtUnitHandle_t_o **p_hunit;
  nbFormation_t_o *form;

  form = 0;
  v4 = ed->data->form;
  form = v4->m_Items[6];
  seqtime = ed->seqtime;
  if (seqtime <= 2)
  {
    if (seqtime == 2)
    {
      nbEventPbRead(912, 1);
      ResorceData = evtGetResorceData(912, 1);
      Packet__nbAddSkillEffectKoukaPacket3 = nbAddSkillEffectKoukaPacket3(0, 0, ResorceData, 2, &form);
      v40 = Packet__nbAddSkillEffectKoukaPacket3;
      if (Packet__nbAddSkillEffectKoukaPacket3
        && !QueryInterface(
              Packet__nbAddSkillEffectKoukaPacket3,
              Effect1_pKoukaPacketEff->obj.klass->_1.element_class))
      {
      }
      Effect1_pKoukaPacketEff->m_Items[0] = v40;
    }
    else if (seqtime == 1)
    {
      for (i = 32; i != 36; ++i)
      {
        while (1)
        {
          v24 = i - 32;
          v25 = ed->data->form;
          v28 = *(&formlist->obj.klass + i);
          if ((v25->m_Items[v28]->stat & 1) != 0)
            break;
          if (++i == 36)
        }
        v31 = ed->data->form;
        v32 = formlist;
        nbAddMotionKoukaPacket(0, 0, &v31->m_Items[*(&v32->obj.klass + i)], 16, 0);
      }
      nbAddUnitAKoukaPacket(0, 0, &form, 0, 0);
    }
  }
  else
  {
    switch (seqtime)
    {
      case '\'':
        nbEventPbRead(912, 2);
        v45 = Effect1_pKoukaPacketEff;
        v46 = evtGetResorceData(912, 2);
        v47 = nbAddSkillEffectKoukaPacket3(0, 0, v46, 2, &form);
        v48 = v47;
        v45->m_Items[1] = v48;
        break;
      case '6':
        nbAddUnitAKoukaPacket(1, 0, &form, 0x80000000, 0);
        nbFormDispOn(6);
        p_hunit = &form->hunit;
        evtSetUnitMotion(p_hunit, 17, 0, 0, 0);
        break;
      case 'm':
        v8 = Effect1_pKoukaPacketEff;
        p_cuteff = &v8->m_Items[0]->cuteff;
        Frame = effBTLCutGetFrame(p_cuteff);
        v12 = Effect1_pKoukaPacketEff;
        effBTLCutSetDrawEndFrame(&v12->m_Items[0]->cuteff, Frame + 32);
        v14 = Effect1_pKoukaPacketEff;
        v16 = effBTLCutGetFrame(&v14->m_Items[1]->cuteff);
        v17 = Effect1_pKoukaPacketEff;
        effBTLCutSetDrawEndFrame(&v17->m_Items[1]->cuteff, v16 + 32);
        v20 = evtGetResorceData(912, 3);
        nbAddSkillEffectKoukaPacket3(0, 0, v20, 2, &form);
        *&ed->seq = (ed->seq + 1);
        break;
    }
  }
  return 0;
}

// 0x1701bd0
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 51)
    return 0;
  Write(StringLiteral_21337, 0);
  ed->data->stat &= ~8u;
  return 1;
}

// 0x1700af0
s32 Hatudo(nbEventProcessData_t *ed) {
    nbPanelAllHide();
    nbAddMotionKoukaPacket(0, 0, 0, 0);
    nbSetFormRot(0, (sdfVector4_t){0}, 0);
    Get(0);
    nbDispText(0, 0, 0, 0, 0, 0);
    nbSetFormPosRot(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    nbAppendEnemyDevilWork(0, 0, 0);
    nbAddUnitStock(0, 0, 0, 0);
    nbLoadUnit(0, 0, 0);
    return 0;
}

// 0x17014c0
s32 Move1(nbEventProcessData_t *ed) {
  MoveSub(ed);
  if (ed->seqtime != 85 || nbCheckLoadGroup(1))
    return 0;
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x1701010
void MoveSub(nbEventProcessData_t *ed) {
  u64 *v3;
  u64 *v5;
  s32 v6;
  s64 i;
  u64 v9;
  struct nbFormation_t_array *form;
  struct System_SByte_array *formlist;
  s64 v13;
  struct System_SByte_array *v16;
  s32 v18;
  s64 v19;
  s64 v21;
  s64 v22;
  u64 j;
  struct nbFormation_t_array *v24;
  s64 v26;
  nbFormation_t_o *v28;
  struct UnityEngine_Vector4_array_array *pos;
  UnityEngine_Vector4_array *v32;
  f32 v34;
  f32 v36;
  s32 v37;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  f32 *p_NB_HELP_TYPE_TXTCONV;
  f32 v44;
  f32 v45;
  f32 v46;
  f32 v47;
  evtUnitHandle_t_o *h;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v50;
  UnityEngine_Vector4_o v51;

  *&p.x = 0;
  *&p.z = 0;
  v3 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v3);
  h = v3;
  v5 = NewSpecific(s32, 4u);
  v6 = 0;
  for (i = 32; i != 36; ++i)
  {
    while (1)
    {
      v9 = i - 32;
      form = ed->data->form;
      v13 = *(&formlist->obj.klass + i);
      if ((form->m_Items[v13]->stat & 1) != 0)
        break;
      if (++i == 36)
    }
    v16 = formlist;
    v18 = *(&v16->obj.klass + i);
    v19 = v6;
    ++v6;
    *(v5 + v19 + 8) = v18;
  }
  if (v6 >= 1)
  {
    v21 = v6 - 1LL;
    v22 = 0;
    for (j = 0; j != v6; ++j)
    {
      while (1)
      {
        v24 = ed->data->form;
        v26 = *(v5 + j + 8);
        v28 = v24->m_Items[v26];
        h = v28->hunit;
        v32 = pos->m_Items[v21];
        SDF_VU0__LOADVECTOR(v32->m_Items[v22]);
        SDF_VU0__LOADVECTOR_B(cen);
        SDF_VU0__ADDVECTOR();
        SDF_VU0__LOADVECTOR_B(off);
        SDF_VU0__ADDVECTOR();
        SDF_VU0__STOREVECTOR(&p);
        SDF_VU0__LOADVECTOR_B(v28->orgpos);
        SDF_VU0__SUBVECTOR();
        v34 = SDF_VU0__GETLENGTH();
        SDF_VU0__LOADVECTOR(p);
        SDF_VU0__LOADVECTOR_B(v28->pos);
        SDF_VU0__SUBVECTOR();
        v36 = SDF_VU0__GETLENGTH();
        if (v36 <= 20.0)
          break;
        v37 = (v34 / 6.0);
        if (v36 <= 50.0)
          v37 = ((v36 * v37) / 50.0);
        x = p.x;
        y = p.y;
        z = p.z;
        w = p.w;
        v50.x = x;
        v50.y = y;
        v50.z = z;
        v50.w = w;
        evtSetUnitMove1(&h, 0, v50, -1, v37, 9, 0, 0);
        ++j;
        ++v22;
        if (v6 == j)
          return;
      }
      p_NB_HELP_TYPE_TXTCONV = &NB_HELP_TYPE_TXTCONV;
      v44 = p_NB_HELP_TYPE_TXTCONV[6];
      v45 = p_NB_HELP_TYPE_TXTCONV[7];
      v46 = p_NB_HELP_TYPE_TXTCONV[8];
      v47 = p_NB_HELP_TYPE_TXTCONV[9];
      v51.x = v44;
      v51.y = v45;
      v51.z = v46;
      v51.w = v47;
      evtUnitRotationTarget(&h, v51, 0.1);
      ++v22;
    }
  }
}

// 0x1700f70
s32 Wait1(nbEventProcessData_t *ed) {
  if ((byte_3F5A445 & 1) != 0)
  {
    if (ed->seqtime < 61)
      return 0;
  }
  else
  {
    if (ed->seqtime < 61)
      return 0;
  }
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x1701c80
dds3ProcessFunc_t *nbE912Process_1(dds3ProcessID_t *id) {
    dds3GetActiveScene();
    dds3GetProcessData(0);
    nbEventPrefabDelete(0);
    dds3DeleteSceneBasicData(0);
    dds3GetUnitHandleObjectBasic(0);
    nbCameraHelperModelSet(0);
    evtRegistBEUnit(0, 0);
    dds3SearchSceneBasic(0, 0, 0);
    nbEventPrefabRead(0, 0, 0);
    evtSetUnitMotion(0, 0, 0, 0, 0);
    nbCameraSetState(0);
    nbCameraBoss_BSALBI_E912_Run();
    nbAllFormDispOn();
    nbGroupFormDispOff(0);
    nbCameraBoss_BSALBI_E912_Set();
    nbUpdateEventProcessData(0);
    return 0;
}
