#include "types.h"

typedef struct NbNegoFlowOne_procfuncDelegate NbNegoFlowOne_procfuncDelegate;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;
typedef struct nbParty_t nbParty_t;

static NbNegoFlowOne_procfuncDelegate *procfunc[40];

u8 Get(s32 id);
void datAddMaka(s32 addmaka);
s32 datCheckDying(datUnitWork_t *work);
s32 datCheckTalk(datUnitWork_t *work);
s32 datGet3Zokusei(datUnitWork_t *work);
s32 datGetPlayerLevel(void);
s32 datGetRace(datUnitWork_t *work);
s32 datSearchDevilStock(s32 id);
u32 dds3GetRandIntA(u32 aLimit, char *name);
bool evtBitCheck(s32 no);
s32 evtGetAgeOfMoon(void);
nbKoukaPacket_t *nbAddMojiEffKoukaPacket(s32 startframe, s32 frame, s32 uniqueid, nbFormation_t **form, s32 type);
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbCameraSetBougai(nbFormation_t **pTargetForm);
void nbCameraSetTaizi(nbFormation_t **pInvokeForm, nbFormation_t **pTargetForm);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);
void nbFormDispOn2(nbFormation_t **form);
s32 nbGetInnenNegoID(nbNegoProcessData_t **n);
s32 nbGetMotionNo(nbFormation_t **form, s32 motion);
datUnitWork_t *nbGetUnitWorkPointer(nbMainProcessData_t *data, nbParty_t *party);
s32 nbMakeUnitMovePacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 select, s32 movetype, f32 ritu);
void nbResetFormPosRot(nbFormation_t **form);
void nbSetMesMakka(s32 msgid, s32 i);
void nbSetNegoMesVar(s32 msgid, datUnitWork_t **p, datUnitWork_t **e);
s32 nbSetNegoNoMotion(nbNegoProcessData_t **n, nbFormation_t **form);

// 0x549e20
s32 Flow1_10(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_UInt32_array *nextkouho;
  u32 max_length;
  u32 *m_Items;
  nbNegoProcessData_t_o *v10;
  struct nbMainProcessData_t_o *data;
  struct System_UInt32_array *v12;
  struct System_UInt32_array *v14;

  nbAddNegoIdKouho(n, 0x1001Fu);
  nbAddNegoIdKouho(n, 0x1001Au);
  workid = (*n)->workid;
  workid->m_Items[3] = 65547;
  nextkouho = (*n)->nextkouho;
  max_length = nextkouho->max_length;
  if ((*n)->ework->id < 0x100u)
  {
    m_Items = &nextkouho->m_Items[1];
  }
  else
  {
    m_Items = nextkouho->m_Items;
  }
  (*n)->nextnegoid = *m_Items;
  v10 = *n;
  data = (*n)->data;
  if ((data->stat & 1) != 0)
  {
    v12 = v10->nextkouho;
    v10->nextnegoid = v12->m_Items[0];
    v10 = *n;
    data = (*n)->data;
  }
  if (data->StageMajor - 240 <= 6)
  {
    v14 = v10->nextkouho;
    v10->nextnegoid = v14->m_Items[0];
  }
  return 0;
}

// 0x549fd0
s32 Flow1_11(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  s32 result;
  s32 StageMajor;
  u32 id;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v11;
  s32 v12;
  bool v13;
  nbNegoProcessData_t_o **v15;
  s32 v16;
  s32 bossmsg;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    StageMajor = v3->data->StageMajor;
    if ((StageMajor - 240) > 6)
    {
      id = v3->ework->id;
      if (id >= 0x170)
      {
        if (id <= 0x18E)
        {
          bossmsg = v3->bossmsg;
          v15 = n;
          v16 = bossmsg;
          v12 = 8;
          goto LABEL_34;
        }
      }
      else if (id < 0x100)
      {
        flowmsg = v3->flowmsg;
        ekucyo = v3->ekucyo;
        v11 = flowmsg->m_Items[ekucyo];
        v12 = 298;
LABEL_33:
        v15 = n;
        v16 = v11;
        goto LABEL_34;
      }
      v11 = v3->bossmsg;
      v12 = id - 256;
      goto LABEL_33;
    }
    if (StageMajor == 243)
    {
      v13 = evtBitCheck(3712);
      v11 = (*n)->bossmsg;
      if (!v13)
      {
        v12 = 121;
        goto LABEL_33;
      }
      {
LABEL_28:
        v15 = n;
        v16 = v11;
        v12 = 128;
LABEL_34:
        nbDispNegoMessage(v15, v16, v12, 0);
        return 1;
      }
    }
    else
    {
      v11 = v3->bossmsg;
        goto LABEL_28;
    }
    goto LABEL_28;
  }
  result = 0;
  if (!nownegophase)
    v3->waitframe = 30;
  return result;
}

// 0x54abe0
s32 Flow1_12(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_UInt32_array *nextkouho;
  struct System_Byte_array *syakkincnt;
  s32 id;
  s64 race;
  u32 v14;
  signed s32 v16;
  nbNegoProcessData_t_o *v17;
  struct System_UInt32_array *v18;

  nbAddNegoIdKouho(n, 0x1001Fu);
  nbAddNegoIdKouho(n, 0x10027u);
  workid = (*n)->workid;
  workid->m_Items[3] = 65551;
  nextkouho = (*n)->nextkouho;
  (*n)->nextnegoid = nextkouho->m_Items[1];
  syakkincnt = DDS3_GBWK->syakkincnt;
  id = (*n)->ework->id;
  race = Get(id, 1, 0)->race;
  v14 = syakkincnt->m_Items[race];
  if (v14 >= 3)
  {
    if (DDS3_GBWK->maka >= 500)
    {
      if (v14 - 3 < 3)
      {
        v16 = 30;
      }
      else if (v14 - 6 <= 4)
      {
        v16 = 50;
      }
      else
      {
        v16 = 70;
      }
      if (dds3GetRandIntA(0x64u, "1_12") < v16)
      {
        v17 = *n;
        v18 = v17->nextkouho;
        v17->nextnegoid = v18->m_Items[0];
      }
    }
  }
  return 0;
}

// 0x54ae40
s32 Flow1_13(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x1000Eu);
  nbAddNegoIdKouho(n, 0x1000Fu);
  return 0;
}

// 0x54aef0
s32 Flow1_14(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x1000Fu);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 6, 0);
  return 0;
}

// 0x54afe0
s32 Flow1_15(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0x10010u);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 7, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0x54b120
s32 Flow1_16(nbNegoProcessData_t **n) {
  u64 v5;
  struct System_Byte_array *syakkincnt;
  s32 id;
  s64 race;

  nbAddNegoIdKouho(n, 0x10011u);
  v5 = 1431655766LL * DDS3_GBWK->maka;
  (*n)->getmakka = HIDWORD(v5) + (v5 >> 63);
  syakkincnt = DDS3_GBWK->syakkincnt;
  id = (*n)->ework->id;
  race = Get(id, 1, 0)->race;
  syakkincnt->m_Items[race] = 0;
  return 0;
}

// 0x54b280
s32 Flow1_17(nbNegoProcessData_t **n) {
  s32 helpmsg;
  s32 getmakka;
  s32 v6;

  helpmsg = (*n)->helpmsg;
  getmakka = (*n)->getmakka;
  nbSetMesMakka(helpmsg, getmakka);
  nbDispNegoMessage(n, (*n)->helpmsg, 4, 0, 0);
  v6 = (*n)->getmakka;
  datAddMaka(-v6);
  return 1;
}

// 0x54b360
s32 Flow1_18(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  nbNegoProcessData_t_o *v6;
  struct datUnitWork_t_o *ework;
  u32 id;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  s32 AgeOfMoon;
  u32 max_length;

  nbAddNegoIdKouho(n, 0x10021u);
  nbAddNegoIdKouho(n, 0x1001Fu);
  workid = (*n)->workid;
  workid->m_Items[3] = 131073;
  v6 = *n;
  ework = (*n)->ework;
  id = ework->id;
  if (id <= 0x1E && ((1 << id) & 0x61012538) != 0 || id == 153 || id == 150)
  {
    nextkouho = v6->nextkouho;
    if (LODWORD(nextkouho->max_length) > 1)
      goto LABEL_15;
LABEL_14:
  }
  if (datGetRace(ework) == 33)
  {
    v6 = *n;
    nextkouho = (*n)->nextkouho;
    if (!LODWORD(nextkouho->max_length))
      goto LABEL_24;
LABEL_25:
    m_Items = nextkouho->m_Items;
    goto LABEL_16;
  }
  AgeOfMoon = evtGetAgeOfMoon();
  v6 = *n;
  nextkouho = (*n)->nextkouho;
  max_length = nextkouho->max_length;
  if (AgeOfMoon != 8)
  {
    if (!max_length)
    {
LABEL_24:
    }
    goto LABEL_25;
  }
  if (max_length <= 1)
    goto LABEL_14;
LABEL_15:
  m_Items = &nextkouho->m_Items[1];
LABEL_16:
  v6->nextnegoid = *m_Items;
  return 0;
}

// 0x54b560
s32 Flow1_19(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_UInt32_array *nextkouho;
  nbNegoProcessData_t_o *v7;
  struct datUnitWork_t_o *pwork;
  struct datUnitWork_t_o *ework;
  struct System_UInt32_array *v10;

  nbAddNegoIdKouho(n, 0x10014u);
  nbAddNegoIdKouho(n, 0x1001Fu);
  workid = (*n)->workid;
  workid->m_Items[3] = 262145;
  nextkouho = (*n)->nextkouho;
  (*n)->nextnegoid = nextkouho->m_Items[0];
  v7 = *n;
  pwork = (*n)->pwork;
  if ((pwork->flag & 4) == 0)
  {
    ework = v7->ework;
    if ((ework->flag & 4) == 0 && pwork->id == ework->id)
    {
      v10 = v7->nextkouho;
      v7->nextnegoid = v10->m_Items[1];
      (*n)->flag1_6 = 0;
    }
  }
  return 0;
}

// 0x54b6d0
s32 Flow1_20(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_UInt32_array *nextkouho;
  struct datUnitWork_t_o *ework;
  s32 id;
  nbNegoProcessData_t_o *v10;
  struct System_UInt32_array *v11;

  nbAddNegoIdKouho(n, 0x10015u);
  nbAddNegoIdKouho(n, 0x1001Fu);
  workid = (*n)->workid;
  workid->m_Items[3] = 196609;
  nextkouho = (*n)->nextkouho;
  (*n)->nextnegoid = nextkouho->m_Items[0];
  ework = (*n)->ework;
  if ((ework->flag & 4) == 0)
  {
    id = ework->id;
    if ((datSearchDevilStock(id) & 0x80000000) == 0)
    {
      v10 = *n;
      if (!(*n)->negoreqtype)
      {
        v11 = v10->nextkouho;
        v10->nextnegoid = v11->m_Items[1];
        (*n)->flag1_6 = 0;
      }
    }
  }
  return 0;
}

// 0x54b860
s32 Flow1_21(nbNegoProcessData_t **n) {
  struct System_UInt32_array *nextkouho;
  u32 max_length;
  u32 *m_Items;
  nbNegoProcessData_t_o *v8;
  struct System_UInt32_array *v9;

  nbAddNegoIdKouho(n, 0x10016u);
  nbAddNegoIdKouho(n, 0x1001Bu);
  nextkouho = (*n)->nextkouho;
  max_length = nextkouho->max_length;
  if ((*n)->data->enemypcnt == 1)
  {
    m_Items = &nextkouho->m_Items[1];
  }
  else
  {
    m_Items = nextkouho->m_Items;
  }
  (*n)->nextnegoid = *m_Items;
  v8 = *n;
  if ((v8->data->stat & 0x800000) == 0)
  {
    v9 = v8->nextkouho;
    v8->nextnegoid = v9->m_Items[1];
  }
  return 0;
}

// 0x54b9b0
s32 Flow1_22(nbNegoProcessData_t **n) {
  u64 *v3;
  u64 *v4;
  u64 *v6;
  struct System_UInt32_array *nextkouho;
  signed s32 v10;
  s64 v11;
  struct nbParty_t_array *party;
  s64 v13;
  nbParty_t_o *v15;
  nbMainProcessData_t_o *data;
  datUnitWork_t_o *UnitWorkPointer;
  s32 id;
  s64 v20;
  u32 RandIntA;
  nbNegoProcessData_t_o *v24;
  struct System_UInt32_array *v25;

  v3 = Allocate(nbParty_t);
  nbParty_t___ctor(v3);
  v4 = Allocate(datUnitWork_t);
  datUnitWork_t___ctor(v4);
  v6 = NewSpecific(byte, 0x20u);
  nbAddNegoIdKouho(n, 0x10018u);
  nbAddNegoIdKouho(n, 0x10017u);
  nextkouho = (*n)->nextkouho;
  v10 = 0;
  v11 = 8;
  (*n)->nextnegoid = nextkouho->m_Items[0];
  do
  {
    party = (*n)->data->party;
    v13 = v11 - 4;
    v15 = *(&party->obj.klass + v11);
    if ((v15->flag & 0x3B) == 3 && v13 != (*n)->epartyindex)
    {
      data = (*n)->data;
      UnitWorkPointer = nbGetUnitWorkPointer(data, v15);
      else if (!datCheckTalk(UnitWorkPointer))
      {
        goto LABEL_31;
      }
      id = UnitWorkPointer->id;
      if (Get(id, 0)->tokuboutype == 1)
      {
        v20 = v10;
        ++v10;
        *(v6 + v20 + 32) = v13;
      }
    }
LABEL_31:
    ++v11;
  }
  while (v11 != 18);
  if (v10 >= 1)
  {
    RandIntA = dds3GetRandIntA(v10, "1_22");
    (*n)->boupartyindex = *(v6 + RandIntA + 32);
    v24 = *n;
    v25 = v24->nextkouho;
    v24->nextnegoid = v25->m_Items[1];
  }
  return 0;
}

// 0x54bce0
s32 Flow1_23(nbNegoProcessData_t **n) {
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *party;
  s64 boupartyindex;
  nbParty_t_o *v7;
  datUnitWork_t_o *UnitWorkPointer;
  nbNegoProcessData_t_o *v10;
  s32 nownegophase;
  datUnitWork_t_o *v13;
  s32 id;
  s32 v16;
  datDevilNegoFormat_t_o *v17;
  struct System_Int32_array *flowmsg;
  s64 kucyo;
  s32 v22;
  datUnitWork_t_o **p_pwork;
  struct System_Int32_array *v24;
  datUnitWork_t_o *e;

  e = 0;
  data = (*n)->data;
  party = data->party;
  boupartyindex = (*n)->boupartyindex;
  v7 = party->m_Items[boupartyindex];
  UnitWorkPointer = nbGetUnitWorkPointer(data, v7);
  e = UnitWorkPointer;
  v10 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    v13 = UnitWorkPointer;
    id = UnitWorkPointer->id;
    if (Get(id, 0)->tokuboutype == 1)
    {
      v16 = v13->id;
      v17 = Get(v16, 0);
      flowmsg = (*n)->flowmsg;
      kucyo = v17->kucyo;
      v22 = flowmsg->m_Items[kucyo];
      p_pwork = &(*n)->pwork;
      nbSetNegoMesVar(v22, p_pwork, &e);
      v24 = (*n)->flowmsg;
      nbDispNegoMessage(n, v24->m_Items[kucyo], 16, 0);
    }
    return 4;
  }
  else if (nownegophase)
  {
    return 0;
  }
  else
  {
    v10->waitframe = nbSetNegoNoMotion(n, &v10->eform);
    return 0;
  }
}

// 0x54bf20
s32 Flow1_24(nbNegoProcessData_t **n) {
  struct System_UInt32_array *nextkouho;
  struct nbMainProcessData_t_o *data;
  s32 v7;
  s64 i;
  struct nbParty_t_array *party;
  u64 v10;
  nbParty_t_o *v12;
  nbMainProcessData_t_o *v13;
  datUnitWork_t_o *UnitWorkPointer;
  s32 id;
  nbNegoProcessData_t_o *v17;
  struct System_UInt32_array *v18;

  nbAddNegoIdKouho(n, 0x1001Bu);
  nbAddNegoIdKouho(n, 0x10019u);
  nextkouho = (*n)->nextkouho;
  (*n)->nextnegoid = nextkouho->m_Items[0];
  data = (*n)->data;
  v7 = 50 / (data->enemypcnt - 1);
  for (i = 8; ; ++i)
  {
    party = data->party;
    v10 = i - 4;
    v12 = *(&party->obj.klass + i);
    if ((v12->flag & 0x3B) == 3 && v10 != (*n)->epartyindex)
    {
      v13 = (*n)->data;
      UnitWorkPointer = nbGetUnitWorkPointer(v13, v12);
      else if (!datCheckTalk(UnitWorkPointer))
      {
        goto LABEL_31;
      }
      id = UnitWorkPointer->id;
      if (Get(id, 0)->tokuboutype != 2)
      {
        if (dds3GetRandIntA(0x64u, "1_24") < v7)
          break;
      }
    }
LABEL_31:
    if (v10 > 0xC)
      return 0;
    data = (*n)->data;
  }
  (*n)->boupartyindex = i - 4;
  v17 = *n;
  v18 = v17->nextkouho;
  v17->nextnegoid = v18->m_Items[1];
  return 0;
}

// 0x54c1d0
s32 Flow1_25(nbNegoProcessData_t **n) {
  nbActionProcessData_t_o *v3;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *party;
  s64 boupartyindex;
  nbParty_t_o *v9;
  struct nbMainProcessData_t_o *v11;
  struct nbParty_t_array *v12;
  s64 v13;
  struct nbFormation_t_array *form;
  datUnitWork_t_o *v15;
  s64 formindex;
  s32 nownegophase;
  s32 id;
  datDevilNegoFormat_t_o *v25;
  struct System_Int32_array *flowmsg;
  s64 kucyo;
  struct System_Int32_array *v29;
  nbFormation_t_o *v31;
  datUnitWork_t_o *e;

  v31 = 0;
  e = 0;
  v3 = Allocate(nbActionProcessData_t);
  nbActionProcessData_t___ctor(v3);
  data = (*n)->data;
  party = data->party;
  boupartyindex = (*n)->boupartyindex;
  v9 = party->m_Items[boupartyindex];
  e = nbGetUnitWorkPointer(data, v9);
  v11 = (*n)->data;
  v12 = v11->party;
  v13 = (*n)->boupartyindex;
  form = v11->form;
  v15 = e;
  formindex = v12->m_Items[v13]->formindex;
  v31 = form->m_Items[formindex];
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbSetNegoNoMotion(n, &v31);
    id = v15->id;
    v25 = Get(id, 0);
    flowmsg = (*n)->flowmsg;
    kucyo = v25->kucyo;
    nbSetNegoMesVar(flowmsg->m_Items[kucyo], &(*n)->pwork, &e, 0);
    v29 = (*n)->flowmsg;
    nbDispNegoMessage(n, v29->m_Items[kucyo], 17, 0);
    return 4;
  }
  else
  {
    if (!nownegophase)
    {
      nbAddMojiEffKoukaPacket(0, 30, v3->uniqueid, &v31, 0);
      nbCameraSetBougai(&v31);
    }
    return 0;
  }
}

// 0x54c490
s32 Flow1_26(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  nbNegoProcessData_t_o *v7;
  struct System_UInt32_array *nextkouho;
  s32 InnenNegoID;
  nbNegoProcessData_t_o *v11;
  struct System_UInt32_array *v12;
  u32 max_length;

  nbAddNegoIdKouho(n, 0x10012u);
  nbAddNegoIdKouho(n, 0x1001Fu);
  workid = (*n)->workid;
  workid->m_Items[3] = 327681;
  else if (evtGetAgeOfMoon() == 8)
  {
LABEL_14:
    v7 = *n;
    nextkouho = v7->nextkouho;
    v7->nextnegoid = nextkouho->m_Items[0];
    return 0;
  }
  InnenNegoID = nbGetInnenNegoID(n);
  v11 = *n;
  v12 = (*n)->nextkouho;
  max_length = v12->max_length;
  if (InnenNegoID == -1)
  {
    v11->nextnegoid = v12->m_Items[0];
  }
  else
  {
    v11->nextnegoid = v12->m_Items[1];
    (*n)->innen_id = InnenNegoID;
    (*n)->flag1_6 = 0;
  }
  return 0;
}

// 0x54c670
s32 Flow1_27(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  s32 id;
  datDevilNegoFormat_t_o *v7;
  nbNegoProcessData_t_o *v8;
  u32 *nextkouho;
  u32 v10;
  u32 *v12;

  nbAddNegoIdKouho(n, 0x1001Fu);
  nbAddNegoIdKouho(n, 0x1001Cu);
  workid = (*n)->workid;
  workid->m_Items[3] = 65566;
  id = (*n)->ework->id;
  v7 = Get(id, 0);
  v8 = *n;
  nextkouho = v8->nextkouho;
  v10 = nextkouho[6];
  if (v7->honboutype == 1)
  {
    v12 = nextkouho + 9;
  }
  else
  {
    v12 = nextkouho + 8;
  }
  v8->nextnegoid = *v12;
  return 0;
}

// 0x54c7e0
s32 Flow1_28(nbNegoProcessData_t **n) {
  u32 v3;
  struct System_UInt32_array *workid;
  struct System_UInt32_array *nextkouho;
  datUnitWork_t_o *ework;
  nbNegoProcessData_t_o *v11;
  struct System_UInt32_array *v12;

  if ((*n)->negotype == 3)
  {
    nbAddNegoIdKouho(n, 0x1001Du);
    v3 = 65566;
  }
  else
  {
    nbAddNegoIdKouho(n, 0x1001Du);
    v3 = 65567;
  }
  nbAddNegoIdKouho(n, v3);
  workid = (*n)->workid;
  else if (LODWORD(workid->max_length) <= 3)
  {
    goto LABEL_21;
  }
  workid->m_Items[3] = 65566;
  nextkouho = (*n)->nextkouho;
  (*n)->nextnegoid = nextkouho->m_Items[1];
  ework = (*n)->ework;
  else if (datCheckDying((*n)->ework, 0))
  {
    return 0;
  }
  if (dds3GetRandIntA(0x64u, "1_28") <= 49)
  {
    v11 = *n;
    v12 = v11->nextkouho;
    v11->nextnegoid = v12->m_Items[0];
  }
  return 0;
}

// 0x54ca20
s32 Flow1_29(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v9;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    flowmsg = v3->flowmsg;
    ekucyo = v3->ekucyo;
    v9 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v9, 18, 0);
    return 4;
  }
  else if (nownegophase)
  {
    return 0;
  }
  else
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
    return 0;
  }
}

// 0x549520
s32 Flow1_3(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  datUnitWork_t_o *pwork;
  s32 v7;
  nbNegoProcessData_t_o *v8;
  struct System_UInt32_array *v9;
  u32 *m_Items;
  struct System_UInt32_array *nextkouho;

  nbAddNegoIdKouho(n, 0x10005u);
  nbAddNegoIdKouho(n, 0x1001Fu);
  workid = (*n)->workid;
  workid->m_Items[3] = 65540;
  pwork = (*n)->pwork;
  v7 = datCheckTalk(pwork);
  v8 = *n;
  if (!v7 && (v8->actdata->stat & 0x20) != 0)
  {
    nextkouho = v8->nextkouho;
    m_Items = &nextkouho->m_Items[1];
  }
  else
  {
    v9 = v8->nextkouho;
    m_Items = v9->m_Items;
  }
  v8->nextnegoid = *m_Items;
  return 0;
}

// 0x54cb50
s32 Flow1_30(nbNegoProcessData_t **n) {
  s32 nownegophase;
  nbNegoProcessData_t_o *v5;
  s32 negoreqtype;
  s32 v7;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v11;

  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0x10022u);
    v5 = *n;
    negoreqtype = (*n)->negoreqtype;
    v7 = negoreqtype + 19;
    if (!negoreqtype && v5->data->enemypcnt == 1)
      v7 = 15;
    flowmsg = v5->flowmsg;
    ekucyo = v5->ekucyo;
    v11 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v11, v7, 0);
  }
  else if (!nownegophase)
  {
    (*n)->waitframe = 15;
  }
  return 0;
}

// 0x54cca0
s32 Flow1_31(nbNegoProcessData_t **n) {
  nbActionProcessData_t_o *v3;
  nbNegoProcessData_t_o *v5;
  s32 nownegophase;
  nbNegoProcessData_t_o *v7;
  s32 uniqueid;
  nbFormation_t_o **p_pform;
  struct System_UInt32_array *workid;
  u32 v12;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  char *v16;
  struct System_Int32_array *temp_param;
  s32 v18;
  s32 v20;
  struct System_Int32_array *v21;
  s64 v22;
  char *v24;
  struct System_Int32_array *v25;
  s32 v26;
  s32 v28;
  nbFormation_t_o **v31;
  nbFormation_t_o **p_eform;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v36;
  struct nbFormation_t_array *v39;
  struct nbFormation_t_array *v42;
  nbFormation_t_o **v45;

  v3 = Allocate(nbActionProcessData_t);
  nbActionProcessData_t___ctor(v3);
  v5 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 3)
  {
    workid = v5->workid;
    v12 = workid->m_Items[3];
    nbAddNegoIdKouho(n, v12);
    return 0;
  }
  if (nownegophase != 2)
  {
    if (!nownegophase)
    {
      switch (v5->negotype)
      {
        case 0:
        case 6:
          nbGetMotionNo(&v5->pform, 0);
          (*n)->pform->cr = 100.0 / (*n)->pform->scl;
          (*n)->eform->cr = 100.0 / (*n)->eform->scl;
          v7 = *n;
          uniqueid = v3->uniqueid;
          p_pform = &(*n)->pform;
          goto LABEL_33;
        case 1:
        case 2:
        case 3:
        case 4:
          nbGetMotionNo(&v5->eform, 0);
          (*n)->pform->cr = 100.0 / (*n)->pform->scl;
          (*n)->eform->cr = 100.0 / (*n)->eform->scl;
          v7 = *n;
          uniqueid = v3->uniqueid;
          p_pform = &(*n)->eform;
LABEL_33:
          nbMakeUnitMovePacket(0, uniqueid, p_pform, LOWORD(v7->actdata->select), 3, 1.0, 0);
          v31 = &(*n)->pform;
          p_eform = &(*n)->eform;
          nbCameraSetTaizi(v31, p_eform);
          break;
        default:
          break;
      }
      form = (*n)->data->form;
      nbResetFormPosRot(form->m_Items);
      v36 = (*n)->data->form;
      nbResetFormPosRot(&v36->m_Items[1]);
      v39 = (*n)->data->form;
      nbResetFormPosRot(&v39->m_Items[2]);
      v42 = (*n)->data->form;
      nbResetFormPosRot(&v42->m_Items[3]);
      v45 = &(*n)->pform;
      nbFormDispOn2(v45);
      nbFormDispOn2(&(*n)->eform, 0);
    }
    return 0;
  }
  if (v5->flag1_6 == 1)
  {
    flowmsg = v5->flowmsg;
    ekucyo = v5->ekucyo;
    v16 = flowmsg + 4 * ekucyo;
    temp_param = v5->temp_param;
    v18 = *(v16 + 8);
    v20 = temp_param->m_Items[0];
    nbDispNegoMessage(n, v18, v20, 0);
    (*n)->flag1_6 = 0;
    v5 = *n;
  }
  if (v5->flag1_39 != 1)
    return 0;
  v21 = v5->flowmsg;
  v22 = v5->ekucyo;
  v24 = v21 + 4 * v22;
  v25 = v5->temp_param;
  v26 = *(v24 + 8);
  v28 = v25->m_Items[0];
  nbDispNegoMessage(n, v26, v28, 0);
  return 1;
}

// 0x54a400
s32 Flow1_32(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  struct datUnitWork_t_o *ework;
  s32 id;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v9;
  s32 v10;
  struct System_Int32_array *v11;
  s64 v12;
  s32 v14;
  nbNegoProcessData_t_o **v15;
  s32 v16;
  datUnitWork_t_o *v18;
  nbNegoProcessData_t_o *v19;
  struct System_Int32_array *v20;
  s64 v21;
  s32 v23;
  nbNegoProcessData_t_o **v24;
  s32 v25;
  s32 v26;
  struct System_Int32_array *v27;
  s64 v28;
  struct System_Int32_array *v30;
  s64 v31;
  struct System_Int32_array *v33;
  s64 v34;
  struct System_Int32_array *v36;
  s64 v37;
  s32 v39;
  struct System_Int32_array *v40;
  s64 v41;
  struct System_Int32_array *v43;
  s64 v44;
  struct System_Int32_array *v46;
  s64 v47;
  struct System_Int32_array *v49;
  s64 v50;
  s32 v52;
  struct System_Int32_array *v53;
  s64 v54;
  struct System_Int32_array *v57;
  s64 v58;
  s32 v60;
  struct System_Int32_array *v61;
  s64 v62;
  s32 v64;
  struct System_Int32_array *v65;
  s64 v66;
  s32 v68;

  v3 = *n;
  ework = (*n)->ework;
  id = ework->id;
  switch (ework->id)
  {
    case 3u:
      if (v3->pwork->id != 3)
        goto LABEL_108;
      v3->waitframe = 15;
      flowmsg = (*n)->flowmsg;
      ekucyo = (*n)->ekucyo;
      v9 = flowmsg->m_Items[ekucyo];
      v10 = 116;
      goto LABEL_99;
    case 4u:
      if (v3->pwork->id != id)
        goto LABEL_108;
      v3->waitframe = 15;
      v27 = (*n)->flowmsg;
      v28 = (*n)->ekucyo;
      v9 = v27->m_Items[v28];
      v10 = 117;
      goto LABEL_99;
    case 5u:
      if (v3->pwork->id != id)
        goto LABEL_108;
      v3->waitframe = 15;
      v30 = (*n)->flowmsg;
      v31 = (*n)->ekucyo;
      v9 = v30->m_Items[v31];
      v10 = 118;
      goto LABEL_99;
    case 6u:
    case 7u:
    case 9u:
    case 0xBu:
    case 0xCu:
    case 0xEu:
    case 0xFu:
    case 0x11u:
    case 0x12u:
    case 0x13u:
    case 0x14u:
    case 0x15u:
    case 0x16u:
    case 0x17u:
    case 0x19u:
    case 0x1Au:
    case 0x1Bu:
    case 0x1Cu:
      goto LABEL_20;
    case 8u:
      if (v3->pwork->id != id)
        goto LABEL_108;
      v3->waitframe = 15;
      v33 = (*n)->flowmsg;
      v34 = (*n)->ekucyo;
      v9 = v33->m_Items[v34];
      v10 = 119;
      goto LABEL_99;
    case 0xAu:
      if (v3->pwork->id != id)
        goto LABEL_108;
      v3->waitframe = 15;
      v36 = (*n)->flowmsg;
      v37 = (*n)->ekucyo;
      v39 = v36->m_Items[v37];
      v15 = n;
      v16 = v39;
      v10 = 120;
      goto LABEL_100;
    case 0xDu:
      if (v3->pwork->id != id)
        goto LABEL_108;
      v3->waitframe = 15;
      v40 = (*n)->flowmsg;
      v41 = (*n)->ekucyo;
      v9 = v40->m_Items[v41];
      v10 = 121;
      goto LABEL_99;
    case 0x10u:
      if (v3->pwork->id != id)
        goto LABEL_108;
      v3->waitframe = 15;
      v43 = (*n)->flowmsg;
      v44 = (*n)->ekucyo;
      v9 = v43->m_Items[v44];
      v10 = 122;
      goto LABEL_99;
    case 0x18u:
      if (v3->pwork->id != id)
        goto LABEL_108;
      v3->waitframe = 15;
      v46 = (*n)->flowmsg;
      v47 = (*n)->ekucyo;
      v9 = v46->m_Items[v47];
      v10 = 123;
      goto LABEL_99;
    case 0x1Du:
      if (v3->pwork->id != id)
        goto LABEL_108;
      v3->waitframe = 15;
      v49 = (*n)->flowmsg;
      v50 = (*n)->ekucyo;
      v52 = v49->m_Items[v50];
      v15 = n;
      v16 = v52;
      v10 = 124;
      goto LABEL_100;
    case 0x1Eu:
      if (v3->pwork->id != id)
        goto LABEL_108;
      v3->waitframe = 15;
      v53 = (*n)->flowmsg;
      v54 = (*n)->ekucyo;
      v9 = v53->m_Items[v54];
      v10 = 125;
LABEL_99:
      v15 = n;
      v16 = v9;
      goto LABEL_100;
    default:
      if (id == 150)
      {
        if (v3->pwork->id == 150)
        {
          v3->waitframe = 15;
          v57 = (*n)->flowmsg;
          v58 = (*n)->ekucyo;
          v60 = v57->m_Items[v58];
          v15 = n;
          v16 = v60;
          v10 = 126;
          goto LABEL_100;
        }
        goto LABEL_108;
      }
      if (id == 153)
      {
        if (v3->pwork->id == 153)
        {
          v3->waitframe = 15;
          v11 = (*n)->flowmsg;
          v12 = (*n)->ekucyo;
          v14 = v11->m_Items[v12];
          v15 = n;
          v16 = v14;
          v10 = 127;
LABEL_100:
          nbDispNegoMessage(v15, v16, v10, 0);
          return 2;
        }
LABEL_108:
        v3->waitframe = 15;
        v61 = (*n)->flowmsg;
        v62 = (*n)->ekucyo;
        v64 = v61->m_Items[v62];
        v24 = n;
        v25 = v64;
        v26 = 128;
        goto LABEL_114;
      }
LABEL_20:
      if (datGetRace(ework) != 19)
      {
        v18 = (*n)->ework;
        if (datGetRace(v18) != 18)
        {
          v19 = *n;
          if ((*n)->ework->id != 154)
            goto LABEL_30;
        }
      }
      v19 = *n;
      if (!(*n)->negoreqtype)
      {
        v19->waitframe = 15;
        v65 = (*n)->flowmsg;
        v66 = (*n)->ekucyo;
        v68 = v65->m_Items[v66];
        v26 = 295;
        v24 = n;
        v25 = v68;
      }
      else
      {
LABEL_30:
        v19->waitframe = 15;
        v20 = (*n)->flowmsg;
        v21 = (*n)->ekucyo;
        v23 = v20->m_Items[v21];
        v24 = n;
        v25 = v23;
        v26 = 32;
      }
LABEL_114:
      nbDispNegoMessage(v24, v25, v26, 0);
      return 1;
  }
}

// 0x54a1d0
s32 Flow1_33(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  nbNegoProcessData_t_o *v6;
  struct datUnitWork_t_o *ework;
  datUnitWork_t_o *v9;
  struct datUnitWork_t_o *v10;
  s32 v11;
  u32 *nextkouho;
  u32 *v14;
  u32 v17;

  nbAddNegoIdKouho(n, 0x1000Cu);
  nbAddNegoIdKouho(n, 0x1001Fu);
  workid = (*n)->workid;
  workid->m_Items[3] = 65568;
  v6 = *n;
  ework = (*n)->ework;
  if ((*n)->pwork->id != ework->id)
  {
    if (datGetRace(ework) == 19)
      goto LABEL_21;
    v9 = (*n)->ework;
    if (datGetRace(v9) == 18 || (v10 = (*n)->ework, v10->id == 154))
    {
LABEL_21:
      v6 = *n;
      if (!(*n)->negoreqtype)
      {
        nextkouho = v6->nextkouho;
        if (nextkouho[6] > 1)
          goto LABEL_32;
        goto LABEL_31;
      }
      v10 = v6->ework;
    }
    v11 = datGet3Zokusei(v10);
    v6 = *n;
    if ((v11 & 0x80000000) == 0)
      goto LABEL_27;
    nextkouho = v6->nextkouho;
    v17 = nextkouho[6];
    if (v6->negoskillid == 421)
    {
      if (!v17)
      {
LABEL_28:
      }
      goto LABEL_29;
    }
    if (v17 > 1)
    {
LABEL_32:
      v14 = nextkouho + 9;
      goto LABEL_33;
    }
LABEL_31:
  }
LABEL_27:
  nextkouho = v6->nextkouho;
  if (!nextkouho[6])
    goto LABEL_28;
LABEL_29:
  v14 = nextkouho + 8;
LABEL_33:
  v6->nextnegoid = *v14;
  return 0;
}

// 0x54d150
s32 Flow1_34(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v5;
  struct datNegoSkill_t_array *tbl;
  s64 v7;
  u32 *nextkouho;
  u32 v10;
  u32 *v12;

  nbAddNegoIdKouho(n, 0x10023u);
  nbAddNegoIdKouho(n, 0x10026u);
  v5 = *n;
  v7 = (*n)->negoskillid - 384LL;
  nextkouho = v5->nextkouho;
  v10 = nextkouho[6];
  if (tbl->m_Items[v7]->type)
  {
    v12 = nextkouho + 9;
  }
  else
  {
    v12 = nextkouho + 8;
  }
  v5->nextnegoid = *v12;
  return 0;
}

// 0x54d2c0
s32 Flow1_35(nbNegoProcessData_t **n) {
  s32 PlayerLevel;
  s32 id;
  datDevilFormat_t_o *v7;
  nbNegoProcessData_t_o *v8;
  u32 *nextkouho;
  u32 v10;
  u32 *v12;

  nbAddNegoIdKouho(n, 0x10024u);
  nbAddNegoIdKouho(n, 0x10025u);
  PlayerLevel = datGetPlayerLevel();
  id = (*n)->ework->id;
  v7 = Get(id, 1, 0);
  v8 = *n;
  nextkouho = v8->nextkouho;
  v10 = nextkouho[6];
  if (PlayerLevel >= v7->level)
  {
    v12 = nextkouho + 9;
  }
  else
  {
    v12 = nextkouho + 8;
  }
  v8->nextnegoid = *v12;
  return 0;
}

// 0x54d440
s32 Flow1_36(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v6;

  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v6 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v6, 54, 0);
  return 1;
}

// 0x54d500
s32 Flow1_37(nbNegoProcessData_t **n) {
  s32 id;
  s32 race;
  s32 v6;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v10;

  id = (*n)->ework->id;
  race = Get(id, 1, 0)->race;
  switch (race)
  {
    case 7:
      v6 = 101;
      goto LABEL_12;
    case 8:
      v6 = 102;
      goto LABEL_12;
    case 33:
      v6 = 55;
LABEL_12:
      flowmsg = (*n)->flowmsg;
      ekucyo = (*n)->ekucyo;
      v10 = flowmsg->m_Items[ekucyo];
      nbDispNegoMessage(n, v10, v6, 0);
      return 1;
  }
  nbAddNegoIdKouho(n, 0x60001u);
  return 0;
}

// 0x54d690
s32 Flow1_38(nbNegoProcessData_t **n) {
  s32 id;
  nbNegoProcessData_t_o *v5;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v9;

  id = (*n)->ework->id;
  if (Get(id, 1, 0)->race == 33 && (v5 = *n, (*n)->negoskillid == 403))
  {
    flowmsg = v5->flowmsg;
    ekucyo = v5->ekucyo;
    v9 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v9, 100, 0);
    return 1;
  }
  else
  {
    nbAddNegoIdKouho(n, 0x60001u);
    return 0;
  }
}

// 0x54d800
s32 Flow1_39(nbNegoProcessData_t **n) {
  s32 id;
  u32 RandIntA;
  struct System_Int32_array *temp_param;
  s32 max_length;

  id = (*n)->ework->id;
  if (Get(id, 1, 0)->race == 33 && !(*n)->negoreqtype)
  {
    (*n)->flag1_39 = 1;
    nbAddNegoIdKouho(n, 0x1001Fu);
    RandIntA = dds3GetRandIntA(2u, "1_39");
    temp_param = (*n)->temp_param;
    max_length = temp_param->max_length;
    if (RandIntA)
    {
      temp_param->m_Items[0] = 43;
      return 0;
    }
    else
    {
      temp_param->m_Items[0] = 44;
      return 0;
    }
  }
  else
  {
    nbAddNegoIdKouho(n, 0x10013u);
    return 0;
  }
}

// 0x5496a0
s32 Flow1_4(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  s32 result;
  u32 id;
  bool v7;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v11;
  s32 v12;
  s32 AgeOfMoon;
  struct System_Int32_array *v14;
  s64 v15;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    id = v3->ework->id;
    v7 = id > 0x1E || ((1 << id) & 0x61012538) == 0;
    if (!v7 || id == 150 || id == 153)
      goto LABEL_11;
    AgeOfMoon = evtGetAgeOfMoon();
    v3 = *n;
    if (AgeOfMoon != 8)
    {
LABEL_11:
      flowmsg = v3->flowmsg;
      ekucyo = v3->ekucyo;
      v11 = flowmsg->m_Items[ekucyo];
      v12 = 273;
    }
    else
    {
      v14 = v3->flowmsg;
      v15 = v3->ekucyo;
      v11 = v14->m_Items[v15];
      v12 = 152;
    }
    nbDispNegoMessage(n, v11, v12, 0);
    return 1;
  }
  else
  {
    result = 0;
    if (!nownegophase)
      v3->waitframe = 30;
  }
  return result;
}

// 0x549840
s32 Flow1_5(nbNegoProcessData_t **n) {
  struct System_UInt32_array *nextkouho;
  nbNegoProcessData_t_o *v5;
  u32 negoskillid;
  struct System_UInt32_array *v7;
  struct System_Int32_array *temp_param;
  s32 v11;
  struct System_UInt32_array *v12;
  struct System_UInt32_array *v15;

  nbAddNegoIdKouho(n, 0x10006u);
  nbAddNegoIdKouho(n, 0x1000Au);
  nextkouho = (*n)->nextkouho;
  (*n)->nextnegoid = nextkouho->m_Items[1];
  v5 = *n;
  negoskillid = (*n)->negoskillid;
  if (negoskillid == 393)
  {
    if (v5->pwork->id == 143)
    {
      v12 = v5->nextkouho;
      v5->nextnegoid = v12->m_Items[0];
      temp_param = (*n)->temp_param;
      v11 = 3;
      goto LABEL_32;
    }
  }
  else if (negoskillid == 394)
  {
    if (v5->pwork->id == 113)
    {
      v15 = v5->nextkouho;
      v5->nextnegoid = v15->m_Items[0];
      temp_param = (*n)->temp_param;
      v11 = 4;
      goto LABEL_32;
    }
  }
  else if (negoskillid == 395 && v5->pwork->id == 2)
  {
    v7 = v5->nextkouho;
    v5->nextnegoid = v7->m_Items[0];
    temp_param = (*n)->temp_param;
    v11 = 5;
LABEL_32:
    temp_param->m_Items[0] = v11;
  }
  return 0;
}

// 0x549a60
s32 Flow1_6(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x1000Au);
  (*n)->flag1_6 = 1;
  return 0;
}

// 0x549b10
s32 Flow1_7(nbNegoProcessData_t **n) {
  datUnitWork_t_o *ework;
  s32 v5;
  nbNegoProcessData_t_o *v6;
  u32 *nextkouho;
  u32 v8;
  u32 *v10;

  nbAddNegoIdKouho(n, 0x10008u);
  nbAddNegoIdKouho(n, 0x10003u);
  ework = (*n)->ework;
  v5 = datCheckTalk(ework);
  v6 = *n;
  nextkouho = v6->nextkouho;
  v8 = nextkouho[6];
  if (v5)
  {
    v10 = nextkouho + 9;
  }
  else
  {
    v10 = nextkouho + 8;
  }
  v6->nextnegoid = *v10;
  return 0;
}

// 0x549c40
s32 Flow1_8(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;

  nbAddNegoIdKouho(n, 0x1001Fu);
  workid = (*n)->workid;
  workid->m_Items[3] = 65545;
  return 0;
}

// 0x549d10
s32 Flow1_9(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s64 v4;
  s32 v5;
  s32 v6;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v10;

  v3 = *n;
  v4 = (*n)->ework->badstatus & 0xFFF;
  if (v4 <= 8)
  {
    if ((v4 - 1) >= 4)
    {
      if (v4 == 8)
        v6 = 13;
      else
        v6 = 8;
    }
    else
    {
      v6 = dword_32C3B40[v4 - 1];
    }
  }
  else
  {
    if (v4 == 512)
      v5 = 9;
    else
      v5 = 8;
    if (v4 == 16)
      v6 = 12;
    else
      v6 = v5;
  }
  flowmsg = v3->flowmsg;
  ekucyo = v3->ekucyo;
  v10 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v10, v6, 0);
  return 1;
}

// 0x5494f0
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0x549510
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0x549500
s32 nbMemoryLoadNegoSe(nbFormation_t *form) {
  return 0;
}

// 0x54d9f0
s32 nbNegoFlowOne(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowOne_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n, 0);
}
