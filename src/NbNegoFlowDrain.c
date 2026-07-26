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
  RandIntA = dds3GetRandIntA(1u, StringLiteral_5300);
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
    nbAddNegoIdKouho(0, 0);
    nbClsNegoMessage(0);
    nbPanelPartyShow();
    nbMakeKaifukuPacket(0, 0, 0, 0, 0, 0, 0);
    nbMakeDamagePacket(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    nbAddTimeListHp(0, 0, 0);
    nbAddHitEffKoukaPacket(0, 0, 0, 0);
    nbCheckKuisibariSkill(0);
    nbAddSkillNamePacket(0, 0, 0);
    nbSetKuisibariStop(0);
    nbCheckKuisibari2Skill(0);
    nbMakeDeadPacket(0, 0, 0, 0);
    return 0;
}

// 0x533610
s32 Flow11_4(nbNegoProcessData_t **n) {
    nbAddNegoIdKouho(0, 0);
    nbPanelPartyHide();
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
  if (dds3GetRandIntA(2u, StringLiteral_5303))
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
