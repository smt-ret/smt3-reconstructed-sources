#include "types.h"

typedef struct NbNegoFlowFight_procfuncDelegate NbNegoFlowFight_procfuncDelegate;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static NbNegoFlowFight_procfuncDelegate *procfunc[20];

u32 dds3GetRandIntA(u32 aLimit, char *name);
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);
void nbSetMesMakka(s32 msgid, s32 i);
s32 nbSetNegoNoMotion(nbNegoProcessData_t **n, nbFormation_t **form);

// 0x534810
s32 Flow8_1(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x80002u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 159, 0);
  return 0;
}

// 0x534f90
s32 Flow8_10(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x8000Eu);
  nbAddNegoIdKouho(n, 0x8000Du);
  return 0;
}

// 0x535040
s32 Flow8_11(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x8000Cu);
  nbAddNegoIdKouho(n, 0x8000Du);
  return 0;
}

// 0x5350f0
s32 Flow8_12(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  u32 RandIntA;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v10;
  s32 v12;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    RandIntA = dds3GetRandIntA(2u, StringLiteral_5305);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    v10 = RandIntA + 164;
    v12 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v12, v10, 0);
    return 1;
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

// 0x535260
s32 Flow8_13(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x80011u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 166, 0);
  return 0;
}

// 0x535350
s32 Flow8_14(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  struct System_UInt32_array *nextkouho;
  u32 RandIntA;

  nbAddNegoIdKouho(n, 0x8000Fu);
  nbAddNegoIdKouho(n, 0x80010u);
  v4 = *n;
  nextkouho = v4->nextkouho;
  RandIntA = dds3GetRandIntA(2u, StringLiteral_5306);
  v4->nextnegoid = nextkouho->m_Items[RandIntA];
  return 0;
}

// 0x535470
s32 Flow8_15(nbNegoProcessData_t **n) {
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
    nbDispNegoMessage(n, v9, 163, 0);
    return 1;
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

// 0x5355a0
s32 Flow8_16(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v6;

  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v6 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v6, 162, 0);
  return 1;
}

// 0x535660
s32 Flow8_17(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x80012u);
  return 0;
}

// 0x535700
s32 Flow8_18(nbNegoProcessData_t **n) {
  s32 helpmsg;

  helpmsg = (*n)->helpmsg;
  nbSetMesMakka(helpmsg, 6600);
  nbDispNegoMessage(n, (*n)->helpmsg, 4, 0, 0);
  return 1;
}

// 0x5357a0
s32 Flow8_19(nbNegoProcessData_t **n) {
  return 4;
}

// 0x534900
s32 Flow8_2(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x80003u);
  return 0;
}

// 0x5349a0
s32 Flow8_3(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x80004u);
  nbAddNegoIdKouho(n, 0x80008u);
  nbAddNegoIdKouho(n, 0x8000Bu);
  return 0;
}

// 0x534a60
s32 Flow8_4(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x80005u);
  return 0;
}

// 0x534b00
s32 Flow8_5(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  struct System_UInt32_array *nextkouho;
  u32 RandIntA;

  nbAddNegoIdKouho(n, 0x80006u);
  nbAddNegoIdKouho(n, 0x80007u);
  v4 = *n;
  nextkouho = v4->nextkouho;
  RandIntA = dds3GetRandIntA(2u, StringLiteral_5304);
  v4->nextnegoid = nextkouho->m_Items[RandIntA];
  return 0;
}

// 0x534c20
s32 Flow8_6(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x90001u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 160, 0);
  return 0;
}

// 0x534d10
s32 Flow8_7(nbNegoProcessData_t **n) {
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
    nbDispNegoMessage(n, v9, 161, 0);
    return 2;
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

// 0x534e40
s32 Flow8_8(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x80009u);
  return 0;
}

// 0x534ee0
s32 Flow8_9(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x8000Au);
  nbAddNegoIdKouho(n, 0x80013u);
  return 0;
}

// 0x5347f0
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0x534800
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0x5357b0
s32 nbNegoFlowFight(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowFight_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
