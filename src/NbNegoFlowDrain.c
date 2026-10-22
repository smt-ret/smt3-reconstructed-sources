#include "types.h"

typedef struct NbNegoFlowDrain_procfuncDelegate NbNegoFlowDrain_procfuncDelegate;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbActionProcessData_t nbActionProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static NbNegoFlowDrain_procfuncDelegate *procfunc[10];

u32 dds3GetRandIntA(u32 aLimit, char *name);
nbKoukaPacket_t *nbAddHitEffKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type);
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
nbKoukaPacket_t *nbAddSkillNamePacket(s32 startframe, s32 uniqueid, s32 id);
s32 nbAddTimeListHp(nbActionProcessData_t **a, s32 formindex, s32 add);
s32 nbCheckKuisibari2Skill(s32 formindex);
s32 nbCheckKuisibariSkill(s32 formindex);
void nbClsNegoMessage(nbNegoProcessData_t **n);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);
u32 nbGetBackNoNegoId(nbNegoProcessData_t **n, s32 a);
s32 nbGetNegoKureHpA(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
s32 nbGetNegoKureHpB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
s32 nbGetNegoKureMpA(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
s32 nbGetNegoKureMpB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
u32 nbGetPrevNegoId(nbNegoProcessData_t **n);
s32 nbMakeDamagePacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type, s32 hp, s32 mp, s32 badstat, s32 hiteff, s32 dead, s32 deadtype, s32 moji, s32 animeoff);
s32 nbMakeDeadPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 deadchk);
s32 nbMakeKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type, s32 hp, s32 mp, u32 badstat);
void nbPanelPartyHide(void);
void nbPanelPartyShow(void);
void nbSetKuisibariStop(s32 formindex);
s32 nbSetNegoNoMotion(nbNegoProcessData_t **n, nbFormation_t **form);

// 0x532ee0
s32 Flow11_1(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xB0002u);
  return 0;
}

// 0x532f80
s32 Flow11_2(nbNegoProcessData_t **n) {
  u32 RandIntA;
  nbNegoProcessData_t_o *v6;
  u32 BackNoNegoId;
  nbNegoProcessData_t_o *v9;
  datUnitWork_t_o **p_pwork;
  datUnitWork_t_o **p_ework;
  s32 NegoKureMpB;
  u32 v14;
  datUnitWork_t_o **v15;
  datUnitWork_t_o **v16;

  nbAddNegoIdKouho(n, 0xB0003u);
  RandIntA = dds3GetRandIntA(1u, "11_2");
  v6 = *n;
  if (RandIntA)
  {
    v6->requesthpmp = 1;
    BackNoNegoId = nbGetBackNoNegoId(n, 2);
    v9 = *n;
    p_pwork = &(*n)->pwork;
    p_ework = &(*n)->ework;
    if (BackNoNegoId == 393258)
    {
      NegoKureMpB = nbGetNegoKureMpB(n, p_pwork, p_ework);
    }
    else
    {
      NegoKureMpB = nbGetNegoKureMpA(n, p_pwork, p_ework);
    }
  }
  else
  {
    v6->requesthpmp = 0;
    v14 = nbGetBackNoNegoId(n, 2);
    v9 = *n;
    v15 = &(*n)->pwork;
    v16 = &(*n)->ework;
    if (v14 == 393258)
    {
      NegoKureMpB = nbGetNegoKureHpB(n, v15, v16);
    }
    else
    {
      NegoKureMpB = nbGetNegoKureHpA(n, v15, v16);
    }
  }
  v9->requestdata = NegoKureMpB;
  if (((*n)->data->stat & 0x20000) != 0)
    (*n)->requestdata = 0;
  return 0;
}

// 0x533200
s32 Flow11_3(nbNegoProcessData_t **n) {
  nbActionProcessData_t_o *v3;
  u64 *v7;
  nbNegoProcessData_t_o *v9;
  nbNegoProcessData_t_o *v10;
  s32 v11;
  s32 v12;
  struct datUnitWork_t_o *ework;
  s32 hp;
  nbActionProcessData_t_o **p_actdata;
  s32 eformindex;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v22;
  s32 uniqueid;
  s32 v24;
  s32 v25;
  s32 v26;
  nbActionProcessData_t_o **v27;
  s32 pformindex;
  s32 v29;
  s32 v30;
  s32 requestdata;

  v3 = Allocate(nbActionProcessData_t);
  nbActionProcessData_t___ctor(v3);
  nbAddNegoIdKouho(n, 0xB0004u);
  nbClsNegoMessage(n);
  nbPanelPartyShow();
  requestdata = (*n)->requestdata;
  v7 = sub_8D3950(s32, &requestdata);
  Write_2930400("drain = {0:D}\n", v7);
  v9 = *n;
  if ((*n)->requesthpmp)
  {
    nbMakeKaifukuPacket(15, v3->uniqueid, &v9->eform, 0, -1, v9->requestdata, 0);
    nbMakeDamagePacket(
      45,
      v3->uniqueid,
      &(*n)->pform,
      3,
      -1,
      (*n)->requestdata,
      0,
      0,
      0,
      0,
      1,
      0,
      0);
    v10 = *n;
    v11 = (*n)->requestdata;
    if (v11 < 1)
      v12 = 100;
    else
      v12 = 100 * v10->pwork->mp / v11;
    v10->requestdata = v12;
    goto LABEL_43;
  }
  ework = v9->ework;
  hp = ework->hp;
  LODWORD(ework) = ework->maxhp;
  p_actdata = &v9->actdata;
  eformindex = v9->eformindex;
  v17 = v9->requestdata + hp;
  v18 = ework - hp;
  if (v17 <= ework)
    v19 = v9->requestdata;
  else
    v19 = v18;
  nbAddTimeListHp(p_actdata, eformindex, v19);
  nbMakeKaifukuPacket(0, 0, &(*n)->eform, 0, (*n)->requestdata, -1, 0, 0);
  nbAddHitEffKoukaPacket(0, 0, &(*n)->eform, 9, 0);
  v20 = (*n)->requestdata;
  if (nbCheckKuisibariSkill((*n)->pformindex, 0))
  {
    if (v20 >= 1)
    {
      v22 = (*n)->pwork->hp;
      if (v20 >= v22)
      {
        uniqueid = v3->uniqueid;
        v20 = v22 - 1;
        v24 = 345;
LABEL_34:
        nbAddSkillNamePacket(45, uniqueid, v24);
        nbSetKuisibariStop((*n)->pformindex, 0);
      }
    }
  }
  else
  {
    v25 = nbCheckKuisibari2Skill((*n)->pformindex, 0);
    if (v20 >= 1)
    {
      if (v25)
      {
        v26 = (*n)->pwork->hp;
        if (v20 >= v26)
        {
          uniqueid = v3->uniqueid;
          v20 = v26 - 1;
          v24 = 360;
          goto LABEL_34;
        }
      }
    }
  }
  v27 = &(*n)->actdata;
  pformindex = (*n)->pformindex;
  v29 = (*n)->pwork->hp;
  if (v20 <= v29)
    v30 = v20;
  else
    v30 = (*n)->pwork->hp;
  nbAddTimeListHp(v27, pformindex, -v30);
  nbMakeDamagePacket(
    45,
    v3->uniqueid,
    &(*n)->pform,
    3,
    v20,
    -1,
    0,
    0,
    v20 >= v29,
    0,
    1,
    0,
    0);
  if (v20 >= v29)
    nbMakeDeadPacket(75, v3->uniqueid, &(*n)->pform, 0, 0);
LABEL_43:
  (*n)->waitframe = 20;
  return 0;
}

// 0x533610
s32 Flow11_4(nbNegoProcessData_t **n) {
  u64 *v5;
  nbNegoProcessData_t_o *v6;
  u32 *nextkouho;
  u32 v8;
  u32 *v10;
  u16 hp;

  nbAddNegoIdKouho(n, 0xB0006u);
  nbAddNegoIdKouho(n, 0xB0005u);
  nbPanelPartyHide();
  hp = (*n)->pwork->hp;
  v5 = sub_8D3950(ushort, &hp);
  Write_2930400("pwork hp = {0:D}\n", v5);
  v6 = *n;
  nextkouho = v6->nextkouho;
  v8 = nextkouho[6];
  if (v6->pwork->hp)
  {
    v10 = nextkouho + 8;
  }
  else
  {
    v10 = nextkouho + 9;
  }
  v6->nextnegoid = *v10;
  return 0;
}

// 0x5337b0
s32 Flow11_5(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  u32 *nextkouho;
  u32 v5;
  u32 *v7;

  nbAddNegoIdKouho(n, 0x80013u);
  nbAddNegoIdKouho(n, 0xB0009u);
  v3 = *n;
  nextkouho = v3->nextkouho;
  v5 = nextkouho[6];
  if ((v3->pwork->flag & 4) != 0)
  {
    v7 = nextkouho + 8;
  }
  else
  {
    v7 = nextkouho + 9;
  }
  v3->nextnegoid = *v7;
  return 0;
}

// 0x5338c0
s32 Flow11_6(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  u32 *nextkouho;
  u32 v5;
  u32 *v7;

  nbAddNegoIdKouho(n, 0xB0007u);
  nbAddNegoIdKouho(n, 0xB0008u);
  v3 = *n;
  nextkouho = v3->nextkouho;
  v5 = nextkouho[6];
  if (v3->requesthpmp == 1)
  {
    v7 = nextkouho + 8;
  }
  else
  {
    v7 = nextkouho + 9;
  }
  v3->nextnegoid = *v7;
  return 0;
}

// 0x5339d0
s32 Flow11_7(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  struct System_UInt32_array *v4;
  u32 *m_Items;
  struct System_UInt32_array *nextkouho;

  nbAddNegoIdKouho(n, 0xB0009u);
  nbAddNegoIdKouho(n, 0x60018u);
  v3 = *n;
  if (v3->pwork->mp || v3->requestdata > 49)
  {
    nextkouho = v3->nextkouho;
    m_Items = &nextkouho->m_Items[1];
  }
  else
  {
    v4 = v3->nextkouho;
    m_Items = v4->m_Items;
  }
  v3->nextnegoid = *m_Items;
  return 0;
}

// 0x533af0
s32 Flow11_8(nbNegoProcessData_t **n) {
  s32 v5;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v9;

  nbAddNegoIdKouho(n, 0x60018u);
  if (dds3GetRandIntA(2u, "11_8"))
    v5 = 156;
  else
    v5 = 153;
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v9 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v9, v5, 0);
  return 0;
}

// 0x533c40
s32 Flow11_9(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v8;
  s32 v10;
  u32 PrevNegoId;
  nbNegoProcessData_t_o *v12;
  struct System_UInt32_array *v13;
  u32 v15;
  struct System_UInt32_array *nextkouho;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xA0001u);
    nbAddNegoIdKouho(n, 0xA0018u);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    if ((*n)->requesthpmp)
      v8 = 158;
    else
      v8 = 157;
    v10 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v10, v8, 0);
    PrevNegoId = nbGetPrevNegoId(n);
    if (PrevNegoId == 720903)
    {
      v12 = *n;
      nextkouho = v12->nextkouho;
      v15 = nextkouho->m_Items[0];
    }
    else
    {
      if (PrevNegoId != 720901)
        return 0;
      v12 = *n;
      v13 = v12->nextkouho;
      v15 = v13->m_Items[1];
    }
    v12->nextnegoid = v15;
    return 0;
  }
  if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0x532ec0
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0x532ed0
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0x533e40
s32 nbNegoFlowDrain(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowDrain_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
