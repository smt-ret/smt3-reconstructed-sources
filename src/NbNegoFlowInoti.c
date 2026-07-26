#include "types.h"

typedef struct NbNegoFlowInoti_procfuncDelegate NbNegoFlowInoti_procfuncDelegate;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static NbNegoFlowInoti_procfuncDelegate *procfunc[24];

u8 Get(s32 id);
void datAddItem(s32 id, s32 num);
void datAddMaka(s32 addmaka);
s32 datCheckItemFull(s32 id);
s32 datCheckStockFull(void);
s32 datGetPlayerLevel(void);
s32 datGetRace(datUnitWork_t *work);
s32 datSearchDevilStock(s32 id);
u32 dds3GetRandIntA(u32 aLimit, char *name);
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);
s32 nbGetInfoMsg(s32 infotype);
s32 nbGetNegoYaruItemB(datUnitWork_t **w);
s32 nbGetNegoYaruMakkaB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
void nbSetMesItem(s32 msgid, s32 it);
void nbSetMesMakka(s32 msgid, s32 i);
s32 nbSetNegoYesMotion(nbNegoProcessData_t **n, nbFormation_t **form);

// 0x53b5a0
s32 Flow15_1(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;

  nbAddNegoIdKouho(n, 0x1001Fu);
  workid = (*n)->workid;
  workid->m_Items[3] = 983045;
  return 0;
}

// 0x53bef0
s32 Flow15_10(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  nbNegoProcessData_t_o *v6;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v10;
  nbNegoProcessData_t_o *v11;
  struct System_UInt32_array *nextkouho;
  u32 v14;
  struct System_Int32_array *v15;
  s64 v16;
  s32 v18;
  struct System_UInt32_array *v19;
  struct System_Int32_array *v21;
  s64 v22;
  s32 v24;
  struct System_UInt32_array *v25;
  struct System_Int32_array *v27;
  s64 v28;
  s32 v30;
  struct System_UInt32_array *v31;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xF000Bu);
    nbAddNegoIdKouho(n, 0xF000Cu);
    nbAddNegoIdKouho(n, 0xF000Du);
    nbAddNegoIdKouho(n, 0xF000Eu);
    v6 = *n;
    switch ((*n)->requesttype)
    {
      case 0:
        flowmsg = v6->flowmsg;
        ekucyo = v6->ekucyo;
        v10 = flowmsg->m_Items[ekucyo];
        nbDispNegoMessage(n, v10, 279, 0);
        v11 = *n;
        nextkouho = v11->nextkouho;
        v14 = nextkouho->m_Items[0];
      case 1:
        v15 = v6->flowmsg;
        v16 = v6->ekucyo;
        v18 = v15->m_Items[v16];
        nbDispNegoMessage(n, v18, 271, 0);
        v11 = *n;
        v19 = v11->nextkouho;
        v14 = v19->m_Items[1];
      case 2:
        v21 = v6->flowmsg;
        v22 = v6->ekucyo;
        v24 = v21->m_Items[v22];
        nbDispNegoMessage(n, v24, 271, 0);
        v11 = *n;
        v25 = v11->nextkouho;
        v14 = v25->m_Items[2];
      case 3:
        v27 = v6->flowmsg;
        v28 = v6->ekucyo;
        v30 = v27->m_Items[v28];
        nbDispNegoMessage(n, v30, 271, 0);
        v11 = *n;
        v31 = v11->nextkouho;
        v14 = v31->m_Items[3];
        v11->nextnegoid = v14;
        break;
      default:
        return 0;
    }
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0x53c260
s32 Flow15_11(nbNegoProcessData_t **n) {
  s32 helpmsg;

  helpmsg = (*n)->helpmsg;
  nbDispNegoMessage(n, helpmsg, 2, 0);
  return 3;
}

// 0x53c2f0
s32 Flow15_12(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xF0011u);
  nbDispNegoMessage(n, (*n)->helpmsg, 3, 0, 0);
  return 0;
}

// 0x53c3b0
s32 Flow15_13(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xF0012u);
  nbDispNegoMessage(n, (*n)->helpmsg, 5, 0, 0);
  return 0;
}

// 0x53c470
s32 Flow15_14(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v5;
  s32 getinfotype;

  nbAddNegoIdKouho(n, 0xF0013u);
  (*n)->getinfotype = 2 * (dds3GetRandIntA(2u, StringLiteral_5315) != 0);
  v5 = *n;
  getinfotype = (*n)->getinfotype;
  v5->getinfomsg = nbGetInfoMsg(getinfotype);
  return 0;
}

// 0x53c590
s32 Flow15_17(nbNegoProcessData_t **n) {
  s32 requestdata;

  nbAddNegoIdKouho(n, 0xA001Du);
  requestdata = (*n)->requestdata;
  datAddMaka(requestdata);
  return 0;
}

// 0x53c660
s32 Flow15_18(nbNegoProcessData_t **n) {
  s32 requestdata;

  nbAddNegoIdKouho(n, 0xA001Du);
  requestdata = (*n)->requestdata;
  if ((requestdata - 1) <= 0x9E)
  {
    datAddItem(requestdata, 1);
  }
  return 0;
}

// 0x53c740
s32 Flow15_19(nbNegoProcessData_t **n) {
  struct System_Int32_array *infomsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0xA001Cu);
  infomsg = (*n)->infomsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, infomsg->m_Items[ekucyo], (*n)->getinfomsg, 0, 0);
  return 0;
}

// 0x53c830
s32 Flow15_20(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  if ((*n)->nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xF0016u);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 270, 0);
  }
  return 0;
}

// 0x53c930
s32 Flow15_22(nbNegoProcessData_t **n) {
  return 4;
}

// 0x53c940
s32 Flow15_23(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v6;

  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v6 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v6, 277, 0);
  return 7;
}

// 0x53b670
s32 Flow15_5(nbNegoProcessData_t **n) {
    nbAddNegoIdKouho(0, 0);
    dds3GetRandIntA(0, 0);
    datGetRace(0);
    datSearchDevilStock(0);
    datCheckStockFull();
    datGetPlayerLevel();
    nbGetNegoYaruMakkaB(0, 0, 0);
    nbGetNegoYaruItemB(0);
    datCheckItemFull(0);
    return 0;
}

// 0x53b9b0
s32 Flow15_6(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  s32 v5;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  char *v9;
  s32 requestdata;
  s32 v11;
  struct System_Int32_array *v12;
  s64 v13;
  char *v15;
  s32 v16;
  s32 v17;
  struct System_Int32_array *v18;
  s64 v19;
  s32 v21;

  nbAddNegoIdKouho(n, 0xF0007u);
  v4 = *n;
  v5 = 266;
  switch ((*n)->requesttype)
  {
    case 0:
      break;
    case 1:
      flowmsg = v4->flowmsg;
      ekucyo = v4->ekucyo;
      v9 = flowmsg + 4 * ekucyo;
      requestdata = v4->requestdata;
      v11 = *(v9 + 8);
      nbSetMesMakka(v11, requestdata);
      nbSetMesMakka((*n)->helpmsg, (*n)->requestdata, 0);
      v5 = 267;
      break;
    case 2:
      v12 = v4->flowmsg;
      v13 = v4->ekucyo;
      v15 = v12 + 4 * v13;
      v16 = v4->requestdata;
      v17 = *(v15 + 8);
      nbSetMesItem(v17, v16);
      nbSetMesItem((*n)->helpmsg, (*n)->requestdata, 0);
      v5 = 268;
      break;
    case 3:
      v5 = 269;
      break;
    default:
      v5 = 0;
      break;
  }
  v18 = (*n)->flowmsg;
  v19 = (*n)->ekucyo;
  v21 = v18->m_Items[v19];
  nbDispNegoMessage(n, v21, v5, 0);
  return 0;
}

// 0x53bbe0
s32 Flow15_7(nbNegoProcessData_t **n) {
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
    nbAddNegoIdKouho(n, 0xF0008u);
    nbAddNegoIdKouho(n, 0xF0017u);
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
    nbDispNegoMessage(n, v8, 210, 1);
  }
  return 0;
}

// 0x53bd60
s32 Flow15_8(nbNegoProcessData_t **n) {
  s32 id;
  s32 v6;
  signed s32 RandIntA;
  nbNegoProcessData_t_o *v8;
  u32 *nextkouho;
  u32 v10;
  u32 *v12;

  nbAddNegoIdKouho(n, 0xF000Au);
  nbAddNegoIdKouho(n, 0xF0014u);
  id = (*n)->ework->id;
  if (Get(id, 0)->honboutype == 1)
    v6 = 40;
  else
    v6 = 85;
  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_5314);
  v8 = *n;
  nextkouho = v8->nextkouho;
  v10 = nextkouho[6];
  if (RandIntA >= v6)
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

// 0x53b580
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0x53b590
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0x53ca00
s32 nbNegoFlowInoti(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowInoti_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
