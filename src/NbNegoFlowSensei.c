#include "types.h"

typedef struct NbNegoFlowSensei_procfuncDelegate NbNegoFlowSensei_procfuncDelegate;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static NbNegoFlowSensei_procfuncDelegate *procfunc[13];

void datAddItem(s32 id, s32 num);
s32 datCheckItem(s32 id, s32 num);
s32 datGetRace(datUnitWork_t *work);
u32 dds3GetRandIntA(u32 aLimit, char *name);
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);
s32 nbGetKureItemA(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
void nbSetMesItem(s32 msgid, s32 it);
s32 nbSetNegoNoMotion(nbNegoProcessData_t **n, nbFormation_t **form);
s32 nbSetNegoYesMotion(nbNegoProcessData_t **n, nbFormation_t **form);

// 0xef1ed0
s32 Flow13_1(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;

  nbAddNegoIdKouho(n, 0x1001Fu);
  workid = (*n)->workid;
  workid->m_Items[3] = 851970;
  return 0;
}

// 0xef2bf0
s32 Flow13_10(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v9;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase)
  {
    if (nownegophase == 1)
    {
      flowmsg = v3->flowmsg;
      ekucyo = v3->ekucyo;
      v9 = flowmsg->m_Items[ekucyo];
      nbDispNegoMessage(n, v9, 256, 0);
    }
    else if (nownegophase == 2)
    {
      return 1;
    }
    return 0;
  }
  else
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
    return 0;
  }
}

// 0xef2d20
s32 Flow13_11(nbNegoProcessData_t **n) {
  return 1;
}

// 0xef2810
s32 Flow13_12(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0xA001Cu);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 278, 0);
  return 0;
}

// 0xef1fa0
s32 Flow13_2(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  struct System_UInt32_array *nextkouho;
  u32 RandIntA;
  datUnitWork_t_o *ework;
  datUnitWork_t_o *v11;
  datUnitWork_t_o *v13;
  nbNegoProcessData_t_o *v14;
  struct System_UInt32_array *v15;

  nbAddNegoIdKouho(n, 0xD0003u);
  nbAddNegoIdKouho(n, 0xD0004u);
  v4 = *n;
  nextkouho = (*n)->nextkouho;
  RandIntA = dds3GetRandIntA(2u, "");
  v4->nextnegoid = nextkouho->m_Items[RandIntA];
  ework = (*n)->ework;
  if (datGetRace(ework) == 21)
    goto LABEL_26;
  v11 = (*n)->ework;
  if (datGetRace(v11) == 22)
    goto LABEL_26;
  v13 = (*n)->ework;
  if (datGetRace(v13) == 23)
  {
LABEL_26:
    v14 = *n;
    v15 = v14->nextkouho;
    v14->nextnegoid = v15->m_Items[1];
  }
  return 0;
}

// 0xef2190
s32 Flow13_3(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_UInt32_array *v5;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x70001u);
  workid = (*n)->workid;
  workid->m_Items[4] = 786458;
  v5 = (*n)->workid;
  v5->m_Items[5] = 851979;
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 254, 0);
  return 0;
}

// 0xef22e0
s32 Flow13_4(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  struct System_Int32_array *v7;
  s64 v8;

  nbAddNegoIdKouho(n, 0xD0005u);
  (*n)->requesttype = 0;
  v3 = *n;
  v3->requestdata = nbGetKureItemA(n, &(*n)->pwork, &(*n)->ework, 0);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbSetMesItem(flowmsg->m_Items[ekucyo], (*n)->requestdata, 0);
  v7 = (*n)->flowmsg;
  v8 = (*n)->ekucyo;
  nbDispNegoMessage(n, v7->m_Items[v8], 255, 0);
  return 0;
}

// 0xef2430
s32 Flow13_5(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v8;
  nbNegoProcessData_t_o *v9;
  struct System_UInt32_array *nextkouho;
  u32 max_length;
  u32 v13;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xD0006u);
    nbAddNegoIdKouho(n, 0xD0007u);
    v9 = *n;
    nextkouho = v9->nextkouho;
    max_length = nextkouho->max_length;
    if (v9->nowselect)
    {
      v13 = nextkouho->m_Items[1];
    }
    else
    {
      v13 = nextkouho->m_Items[0];
    }
    v9->nextnegoid = v13;
  }
  else if (!nownegophase)
  {
    flowmsg = v3->flowmsg;
    ekucyo = v3->ekucyo;
    v8 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v8, 211, 1);
  }
  return 0;
}

// 0xef25b0
s32 Flow13_6(nbNegoProcessData_t **n) {
  s32 requestdata;
  s32 v5;
  nbNegoProcessData_t_o *v6;
  u32 *nextkouho;
  u32 v8;
  u32 *v10;

  nbAddNegoIdKouho(n, 0xD0009u);
  nbAddNegoIdKouho(n, 0xD0008u);
  requestdata = (*n)->requestdata;
  v5 = datCheckItem(requestdata, 1);
  v6 = *n;
  nextkouho = v6->nextkouho;
  v8 = nextkouho[6];
  if (v5)
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

// 0xef26f0
s32 Flow13_7(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  struct System_UInt32_array *nextkouho;
  u32 RandIntA;

  nbAddNegoIdKouho(n, 0xD000Au);
  nbAddNegoIdKouho(n, 0xD000Cu);
  v4 = *n;
  nextkouho = v4->nextkouho;
  RandIntA = dds3GetRandIntA(2u, "");
  v4->nextnegoid = nextkouho->m_Items[RandIntA];
  return 0;
}

// 0xef2900
s32 Flow13_8(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 result;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v8;
  s32 v9;
  struct System_Int32_array *v10;
  s64 v11;

  v3 = *n;
  result = 1;
  switch ((*n)->nownegophase)
  {
    case 0:
      v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
      return 0;
    case 1:
      flowmsg = v3->flowmsg;
      ekucyo = v3->ekucyo;
      v8 = flowmsg->m_Items[ekucyo];
      v9 = 81;
      goto LABEL_20;
    case 2:
      v10 = v3->flowmsg;
      v11 = v3->ekucyo;
      v8 = v10->m_Items[v11];
      v9 = 299;
LABEL_20:
      nbDispNegoMessage(n, v8, v9, 0);
      return 0;
    case 3:
      return result;
    default:
      return 0;
  }
}

// 0xef2a80
s32 Flow13_9(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 requestdata;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xC001Au);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 257, 0);
    requestdata = (*n)->requestdata;
    datAddItem(requestdata, -1);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0xef1eb0
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0xef1ec0
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0xef2d30
s32 nbNegoFlowSensei(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowSensei_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
