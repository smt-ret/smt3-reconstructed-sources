#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbCamera_t nbCamera_t;
typedef struct nbE902_funcDelegate nbE902_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbParty_t nbParty_t;
typedef struct sdfRandCB_t sdfRandCB_t;

static s32 NB_HELP_TYPE_TXTCONV;
static u32 DDS3EFFECT_RAND_I;
static sdfRandCB_t *dds3Effect_Rand;
static nbE902_funcDelegate *func[9];

u8 Get(s32 id);
void SelectCopy(nbEventProcessData_t *ed);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetRandIntA(u32 aLimit, char *name);
void dds3ObjectBaseOffFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
void effBTLSkillEnd(void);
void effBTLSkillSetFormationInfo(u32 InvokeID, u32 TargetBit);
void effBTLSkillStart(u32 id, u32 stat);
s32 effPCPBossBUNSIN2GetLength(void);
bool evtBitCheck(s32 no);
s32 evtGetAgeOfMoon(void);
nbKoukaPacket_t *nbAddMotionKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 motion);
nbKoukaPacket_t *nbAddOngBunshin2Packet(s32 startframe, s32 uniqueid, nbFormation_t **sform, nbFormation_t **form1, nbFormation_t **form2, nbFormation_t **form3);
void nbAddUnitStock(nbMainProcessData_t **data, s32 side, s32 stockno, s32 formindex);
s32 nbAppendEnemyDevilWork(nbMainProcessData_t *data, s32 id, s32 formindex);
s32 nbCameraBoss_Ongy_BUNSIN_Run(nbCamera_t **pNbCamera);
s32 nbCameraBoss_Ongy_BUNSIN_Set(nbCamera_t **pNbCamera);
void nbCameraEnemyPartySet(nbCamera_t **pNbCamera, f32 angleH, f32 angleW);
s32 nbCheckLoadGroup(s32 side);
void nbDispText(char *text1, char *text2, s32 type, s32 max, u32 col, bool type_skill);
void nbFormDispOff(s32 formindex);
nbFormation_t *nbGetEventForm(void);
nbParty_t *nbGetPartyFromFormindex(s32 formindex);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
void nbGroupFormDispOn(s32 side);
void nbLoadUnitGroup(s32 side, s32 stop, s32 anime);
void nbMoveFormation(nbMainProcessData_t **data, s32 sindex, s32 dindex);
void nbSetEnemyFormation(nbMainProcessData_t **data);
s32 nbSetEnemySummonFormation(nbMainProcessData_t **data, s32 devilid);
void nbSetFormPos(nbFormation_t **form, sdfVector4_t pos);
void nbUpdateEventProcessData(dds3ProcessID_t **id);
void p2sdPlaySE_20173184(char *define_name);

// 0x16eefb0
s32 Bunshin1(nbEventProcessData_t *ed) {
  struct nbFormation_t_array *form;
  u32 max_length;
  struct nbFormation_t_array *v9;
  f32 *v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  struct nbFormation_t_array *v17;
  u32 v18;
  struct nbFormation_t_array *v21;
  UnityEngine_Vector4_o v26;

  form = ed->data->form;
  max_length = form->max_length;
  nbAddOngBunshin2Packet(0, ed->uniqueid, &form->m_Items[5], &form->m_Items[6], &form->m_Items[4], &form->m_Items[7]);
  v9 = ed->data->form;
  v11 = v9->m_Items[6];
  v12 = v11[12];
  v13 = v11[13];
  v15 = v11[14];
  v14 = v11[15];
  else if (LODWORD(v9->max_length) <= 7)
  {
    goto LABEL_15;
  }
  v26.x = v12;
  v26.y = v13;
  v26.z = v15;
  v26.w = v14;
  nbSetFormPos(&v9->m_Items[7], v26);
  v17 = ed->data->form;
  v18 = v17->max_length;
  nbSetFormPos(&v17->m_Items[6], v17->m_Items[5]->pos);
  v21 = ed->data->form;
  nbSetFormPos(&v21->m_Items[4], v21->m_Items[5]->pos);
  nbCameraBoss_Ongy_BUNSIN_Run(&nbCameraCurrent);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16eee10
s32 Copy(nbEventProcessData_t *ed) {
  nbEventProcessData_t_Fields *p_fields;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v6;
  struct nbFormation_t_array *v8;

  p_fields = &ed->fields;
  form = ed->data->form;
  form->m_Items[4]->stat |= 1u;
  v6 = p_fields->data->form;
  v6->m_Items[6]->stat |= 1u;
  v8 = p_fields->data->form;
  v8->m_Items[7]->stat |= 1u;
  nbSetEnemyFormation(&ed->data);
  nbCameraBoss_Ongy_BUNSIN_Set(&nbCameraCurrent);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16ef830
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 1)
    return 0;
  Write("オンギョウギ分身!\n", 0);
  effBTLSkillEnd();
  if (evtBitCheck(3056))
    ed->data->stat &= ~8u;
  return 1;
}

// 0x16ef4e0
s32 Hontai(nbEventProcessData_t *ed) {
  nbEventProcessData_t_Fields *p_fields;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v6;
  struct nbFormation_t_array *v8;
  struct nbFormation_t_array *v10;
  struct nbFormation_t_array *v12;
  struct nbFormation_t_array *v14;
  struct nbFormation_t_array *v16;
  struct nbFormation_t_array *v18;
  signed s32 RandIntA;
  struct nbFormation_t_array *v23;
  s64 v24;
  nbFormation_t_o *v26;

  p_fields = &ed->fields;
  form = ed->data->form;
  form->m_Items[4]->stat |= 0x1000u;
  v6 = p_fields->data->form;
  dds3ObjectBaseOffFlag(&v6->m_Items[4]->basic, 0x400u);
  v8 = p_fields->data->form;
  v8->m_Items[5]->stat |= 0x1000u;
  v10 = p_fields->data->form;
  dds3ObjectBaseOffFlag(&v10->m_Items[5]->basic, 0x400u);
  v12 = p_fields->data->form;
  v12->m_Items[6]->stat |= 0x1000u;
  v14 = p_fields->data->form;
  dds3ObjectBaseOffFlag(&v14->m_Items[6]->basic, 0x400u);
  v16 = p_fields->data->form;
  v16->m_Items[7]->stat |= 0x1000u;
  v18 = p_fields->data->form;
  dds3ObjectBaseOffFlag(&v18->m_Items[7]->basic, 0x400u);
  RandIntA = dds3GetRandIntA(4u, "");
  v23 = p_fields->data->form;
  v24 = RandIntA + 4LL;
  v26 = v23->m_Items[v24];
  v26->stat &= ~0x1000u;
  if (evtGetAgeOfMoon() == 8)
  {
LABEL_27:
    dds3ObjectBaseOnFlag(&v26->basic, 0x400u, 0);
    v26->basic->poseset->r = 200.0;
  }
LABEL_28:
  nbSetEnemyFormation(&ed->data);
  nbGroupFormDispOn(1);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16ee9f0
s32 Loading(nbEventProcessData_t *ed) {
  struct nbFormation_t_array *v4;
  struct nbFormation_t_array *v6;
  struct nbFormation_t_array *v8;
  u32 formindex;
  System_String_o *v16;
  s32 NB_HELP_TYPE_TXTCONV;
  nbFormation_t_o *form;

  form = 0;
  if (!nbCheckLoadGroup(1))
  {
    v4 = ed->data->form;
    v4->m_Items[4]->stat &= ~1u;
    v6 = ed->data->form;
    v6->m_Items[6]->stat &= ~1u;
    v8 = ed->data->form;
    v8->m_Items[7]->stat &= ~1u;
    p2sdPlaySE_20173184("BSE_E902_SE00");
    form = nbGetEventForm();
    nbAddMotionKoukaPacket(0, 0, &form, 4);
    formindex = form->formindex;
    effBTLSkillSetFormationInfo(formindex, 0);
    effBTLSkillStart(0xE9u, 0);
    v16 = Get(233, 0, 0);
    nbDispText(v16, 0, NB_HELP_TYPE_TXTCONV, 90, 0x89FEFF80, 0);
    *&ed->seq = (ed->seq + 1);
  }
  return 0;
}

// 0x16ee270
s32 Pos1(nbEventProcessData_t *ed) {
  s32 formindex;
  nbEventProcessData_t_Fields *p_fields;
  s64 i;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v11;

  formindex = nbGetEventForm()->formindex;
  p_fields = &ed->fields;
  nbMoveFormation(&ed->data, formindex, 5);
  nbSetEnemySummonFormation(&ed->data, 269);
  for (i = 8; i != 18; ++i)
  {
    while (1)
    {
      form = p_fields->data->form;
      if ((*(*(&form->obj.klass + i) + 137LL) & 8) != 0)
        break;
      if (++i == 18)
        goto LABEL_18;
    }
    v11 = p_fields->data->form;
    *(*(&v11->obj.klass + i) + 136LL) |= 8u;
  }
LABEL_18:
  SelectCopy(ed);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16ee420
void SelectCopy(nbEventProcessData_t *ed) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  nbFormation_t_o *EventForm;
  nbParty_t_o *PartyFromFormindex;
  nbEventProcessData_t_Fields *p_fields;
  u64 i;
  struct nbFormation_t_array *form;
  nbMainProcessData_t_o *data;
  s32 appended;
  struct datUnitWork_t_array *enemyunit;
  datUnitWork_t_o *v18;
  nbParty_t_o *v20;
  s64 v21;
  struct System_Int16_array *count;
  struct System_Int16_array *v23;
  s16 v24;
  s64 j;
  struct System_UInt32_array *aisyo;
  struct System_UInt32_array *v29;
  s32 v30;
  struct System_UInt16_array *hojoskill;
  struct System_UInt16_array *v34;
  u16 v35;
  struct System_UInt16_array *v36;
  struct System_UInt16_array *v37;
  u16 v38;
  struct System_UInt16_array *v39;
  struct System_UInt16_array *v40;
  u16 v42;
  struct System_UInt16_array *v44;
  struct System_UInt16_array *v45;
  u16 v46;
  struct System_UInt16_array *v47;
  struct System_UInt16_array *v48;
  u16 v50;
  struct System_UInt16_array *v52;
  struct System_UInt16_array *v53;
  u16 v55;
  struct System_UInt16_array *v57;
  struct System_UInt16_array *v58;
  u16 v60;
  struct System_UInt16_array *v62;
  struct System_UInt16_array *v63;
  u16 v64;

  formindex = nbGetEventForm()->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  EventForm = nbGetEventForm(UnitWorkFromFormindex);
  PartyFromFormindex = nbGetPartyFromFormindex(EventForm->formindex);
  p_fields = &ed->fields;
  for (i = 4; i != 14; ++i)
  {
    while (1)
    {
      form = p_fields->data->form;
      if ((form->m_Items[i]->stat & 8) != 0)
        break;
      if (++i == 14)
        goto LABEL_70;
    }
    data = p_fields->data;
    appended = nbAppendEnemyDevilWork(data, 269, i);
    enemyunit = p_fields->data->enemyunit;
    v18 = enemyunit->m_Items[appended];
    v18->flag = UnitWorkFromFormindex->flag;
    v18->hp = UnitWorkFromFormindex->hp;
    v18->maxhp = UnitWorkFromFormindex->maxhp;
    v18->mp = UnitWorkFromFormindex->mp;
    v18->maxmp = UnitWorkFromFormindex->maxmp;
    v18->badstatus = UnitWorkFromFormindex->badstatus;
    nbAddUnitStock(&p_fields->data, 1, appended, i);
    v20 = nbGetPartyFromFormindex(i);
    v21 = 16;
    v20->flag = PartyFromFormindex->flag;
    do
    {
      count = PartyFromFormindex->count;
      v23 = v20->count;
      v24 = *(&count->obj.klass + v21);
      *(&v23->obj.klass + v21++) = v24;
    }
    while (v21 != 36);
    for (j = 8; j != 24; ++j)
    {
      aisyo = PartyFromFormindex->aisyo;
      v29 = v20->aisyo;
      v30 = *(&aisyo->obj.klass + j);
      *(&v29->obj.klass + j) = v30;
    }
    hojoskill = PartyFromFormindex->hojoskill;
    v34 = v20->hojoskill;
    v35 = hojoskill->m_Items[0];
    v34->m_Items[0] = v35;
    v36 = PartyFromFormindex->hojoskill;
    v37 = v20->hojoskill;
    v38 = v36->m_Items[1];
    v37->m_Items[1] = v38;
    v39 = PartyFromFormindex->hojoskill;
    v40 = v20->hojoskill;
    v42 = v39->m_Items[2];
    v40->m_Items[2] = v42;
    v44 = PartyFromFormindex->hojoskill;
    v45 = v20->hojoskill;
    v46 = v44->m_Items[3];
    v45->m_Items[3] = v46;
    v47 = PartyFromFormindex->hojoskill;
    v48 = v20->hojoskill;
    v50 = v47->m_Items[4];
    v48->m_Items[4] = v50;
    v52 = PartyFromFormindex->hojoskill;
    v53 = v20->hojoskill;
    v55 = v52->m_Items[5];
    v53->m_Items[5] = v55;
    v57 = PartyFromFormindex->hojoskill;
    v58 = v20->hojoskill;
    v60 = v57->m_Items[6];
    v58->m_Items[6] = v60;
    v62 = PartyFromFormindex->hojoskill;
    v63 = v20->hojoskill;
    v64 = v62->m_Items[7];
    v63->m_Items[7] = v64;
  }
LABEL_70:
  nbLoadUnitGroup(1, 0, 0);
}

// 0x16eec60
s32 SetForm(nbEventProcessData_t *ed) {
  nbSetEnemyFormation(&ed->data);
  if (ed)
LABEL_9:
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16eed10
s32 Wait1(nbEventProcessData_t *ed) {
  s32 seqtime;
  struct datUnitMotion_s_array *motion;

  nbGetEventForm();
  seqtime = ed->seqtime;
  motion = Get(269, 0)->motion;
  if (seqtime > motion->m_Items[4]->actframe)
  {
    *&ed->seq = (ed->seq + 1);
  }
  return 0;
}

// 0x16ef2c0
s32 Wait2(nbEventProcessData_t *ed) {
  s32 seqtime;
  f32 v8;

  if (ed->seqtime == 1)
  {
    nbFormDispOff(5);
  }
  nbCameraBoss_Ongy_BUNSIN_Run(&nbCameraCurrent);
  seqtime = ed->seqtime;
  else if (seqtime <= effPCPBossBUNSIN2GetLength())
  {
    return 0;
  }
  if ((DDS3EFFECT_RAND_I & 1) != 0)
  {
    v8 = -0.2618;
  }
  else
  {
    v8 = 0.2618;
  }
  nbCameraEnemyPartySet(&nbCameraCurrent, -0.34907, v8);
  *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16ef910
void *nbE902Process_1(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  nbEventProcessData_t_o *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct nbE902_funcDelegate_array *func;
  s64 seq;
  dds3ProcessID_t_o *v16[3];
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
      sub_8FC2C0(klass->_1.element_class, nbEventProcessData_t, v16);
      if ((v16[0] & 1) != 0)
        v8 = v16[2];
      else
        v8 = v16 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  seq = v5->seq;
  if (Invoke(func->m_Items[seq], v5))
  {
    ida->func_ans = -1;
  }
  else
  {
    if (v5->time == 37)
    {
      dds3PadAct(0, 1u, 4u);
      dds3PadAct(1u, 0xFAu, 6u);
    }
    nbUpdateEventProcessData(&ida);
  }
  return 0;
}
