#include "types.h"

typedef struct NbNegoFlowDouchara_procfuncDelegate NbNegoFlowDouchara_procfuncDelegate;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static NbNegoFlowDouchara_procfuncDelegate *procfunc[14];

void datAddItem(s32 id, s32 num);
void datAddMaka(s32 addmaka);
s32 datCheckItemFull(s32 id);
u32 dds3GetRandIntA(u32 aLimit, char *name);
nbKoukaPacket_t *nbAddHitEffKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type);
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbClsNegoMessage(nbNegoProcessData_t **n);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);
s32 nbGetNegoYaruItemB(datUnitWork_t **w);
s32 nbGetNegoYaruMakkaB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
u32 nbGetPrevNegoId(nbNegoProcessData_t **n);
s32 nbMakeKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type, s32 hp, s32 mp, u32 badstat);
void nbPanelDraw(s32 flag);
void nbSetMesItem(s32 msgid, s32 it);
void nbSetMesMakka(s32 msgid, s32 i);

// 0x12ad2a0
s32 Flow4_1(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  s32 id;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v9;
  s32 v10;
  struct System_Int32_array *v11;
  s64 v12;
  struct System_Int32_array *v14;
  s64 v15;
  struct System_Int32_array *v17;
  s64 v18;
  struct System_Int32_array *v20;
  s64 v21;
  struct System_Int32_array *v23;
  s64 v24;
  struct System_Int32_array *v26;
  s64 v27;
  struct System_Int32_array *v29;
  s64 v30;
  struct System_Int32_array *v32;
  s64 v33;
  struct System_Int32_array *v35;
  s64 v36;
  struct System_Int32_array *v38;
  s64 v39;
  struct System_Int32_array *v41;
  s64 v42;
  struct System_Int32_array *v44;
  s64 v45;
  s32 result;
  struct System_Int32_array *v48;
  s64 v49;
  s32 v51;

  nbAddNegoIdKouho(n, 0x40002u);
  v4 = *n;
  id = (*n)->ework->id;
  switch ((*n)->ework->id)
  {
    case 0x38u:
      if (v4->pwork->id != id)
        goto LABEL_102;
      v4->waitframe = 15;
      flowmsg = (*n)->flowmsg;
      ekucyo = (*n)->ekucyo;
      v9 = flowmsg->m_Items[ekucyo];
      v10 = 141;
      goto LABEL_101;
    case 0x59u:
      if (v4->pwork->id != 89)
        goto LABEL_102;
      v4->waitframe = 15;
      v11 = (*n)->flowmsg;
      v12 = (*n)->ekucyo;
      v9 = v11->m_Items[v12];
      v10 = 140;
      goto LABEL_101;
    case 0x68u:
      if (v4->pwork->id != id)
        goto LABEL_102;
      v4->waitframe = 15;
      v14 = (*n)->flowmsg;
      v15 = (*n)->ekucyo;
      v9 = v14->m_Items[v15];
      v10 = 129;
      goto LABEL_101;
    case 0x69u:
      if (v4->pwork->id != id)
        goto LABEL_102;
      v4->waitframe = 15;
      v17 = (*n)->flowmsg;
      v18 = (*n)->ekucyo;
      v9 = v17->m_Items[v18];
      v10 = 130;
      goto LABEL_101;
    case 0x6Au:
      if (v4->pwork->id != id)
        goto LABEL_102;
      v4->waitframe = 15;
      v20 = (*n)->flowmsg;
      v21 = (*n)->ekucyo;
      v9 = v20->m_Items[v21];
      v10 = 131;
      goto LABEL_101;
    case 0x6Bu:
      if (v4->pwork->id != id)
        goto LABEL_102;
      v4->waitframe = 15;
      v23 = (*n)->flowmsg;
      v24 = (*n)->ekucyo;
      v9 = v23->m_Items[v24];
      v10 = 132;
      goto LABEL_101;
    case 0x6Cu:
      if (v4->pwork->id != id)
        goto LABEL_102;
      v4->waitframe = 15;
      v26 = (*n)->flowmsg;
      v27 = (*n)->ekucyo;
      v9 = v26->m_Items[v27];
      v10 = 133;
      goto LABEL_101;
    case 0x6Du:
      if (v4->pwork->id != id)
        goto LABEL_102;
      v4->waitframe = 15;
      v29 = (*n)->flowmsg;
      v30 = (*n)->ekucyo;
      v9 = v29->m_Items[v30];
      v10 = 134;
      goto LABEL_101;
    case 0x6Eu:
      if (v4->pwork->id != id)
        goto LABEL_102;
      v4->waitframe = 15;
      v32 = (*n)->flowmsg;
      v33 = (*n)->ekucyo;
      v9 = v32->m_Items[v33];
      v10 = 135;
      goto LABEL_101;
    case 0x6Fu:
      if (v4->pwork->id != id)
        goto LABEL_102;
      v4->waitframe = 15;
      v35 = (*n)->flowmsg;
      v36 = (*n)->ekucyo;
      v9 = v35->m_Items[v36];
      v10 = 136;
      goto LABEL_101;
    case 0x70u:
      if (v4->pwork->id != id)
        goto LABEL_102;
      v4->waitframe = 15;
      v38 = (*n)->flowmsg;
      v39 = (*n)->ekucyo;
      v9 = v38->m_Items[v39];
      v10 = 137;
      goto LABEL_101;
    case 0x71u:
      if (v4->pwork->id != id)
        goto LABEL_102;
      v4->waitframe = 15;
      v41 = (*n)->flowmsg;
      v42 = (*n)->ekucyo;
      v9 = v41->m_Items[v42];
      v10 = 138;
      goto LABEL_101;
    case 0x9Au:
      if (v4->pwork->id != id)
        goto LABEL_102;
      v4->waitframe = 15;
      v44 = (*n)->flowmsg;
      v45 = (*n)->ekucyo;
      v9 = v44->m_Items[v45];
      v10 = 139;
LABEL_101:
      nbDispNegoMessage(n, v9, v10, 0);
      result = 2;
      break;
    default:
LABEL_102:
      v4->waitframe = 15;
      v48 = (*n)->flowmsg;
      v49 = (*n)->ekucyo;
      v51 = v48->m_Items[v49];
      nbDispNegoMessage(n, v51, 49, 0);
      result = 0;
      break;
  }
  return result;
}

// 0x12ae200
s32 Flow4_10(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x4000Bu);
  nbClsNegoMessage(n);
  nbPanelDraw(1);
  nbMakeKaifukuPacket(0, 0, &(*n)->pform, 0, (*n)->pwork->maxhp, -1, 0, 0);
  nbAddHitEffKoukaPacket(0, 0, &(*n)->pform, 8, 0);
  (*n)->waitframe = 0;
  return 0;
}

// 0x12ae320
s32 Flow4_11(nbNegoProcessData_t **n) {
  u32 PrevNegoId;
  s32 v6;
  s32 getmakka;
  s32 v8;
  nbNegoProcessData_t_o **v9;
  s32 v10;
  s32 helpmsg2;
  s32 helpmsg;
  s32 getitem;

  nbAddNegoIdKouho(n, 0x4000Cu);
  nbPanelDraw(0);
  PrevNegoId = nbGetPrevNegoId(n);
  switch (PrevNegoId)
  {
    case 0x4000Au:
      helpmsg2 = (*n)->helpmsg2;
      nbDispNegoMessage(n, helpmsg2, 7, 0);
      (*n)->waitframe = 60;
      break;
    case 0x40009u:
      helpmsg = (*n)->helpmsg;
      getitem = (*n)->getitem;
      nbSetMesItem(helpmsg, getitem);
      v8 = (*n)->helpmsg;
      v10 = 5;
      v9 = n;
      goto LABEL_27;
    case 0x40008u:
      v6 = (*n)->helpmsg;
      getmakka = (*n)->getmakka;
      nbSetMesMakka(v6, getmakka);
      v8 = (*n)->helpmsg;
      v9 = n;
      v10 = 3;
LABEL_27:
      nbDispNegoMessage(v9, v8, v10, 0);
      break;
  }
  return 0;
}

// 0x12ae510
s32 Flow4_12(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x4000Du);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 50, 0);
  return 0;
}

// 0x12ae600
s32 Flow4_13(nbNegoProcessData_t **n) {
  s32 helpmsg;

  helpmsg = (*n)->helpmsg;
  nbDispNegoMessage(n, helpmsg, 1, 0);
  return 2;
}

// 0x12ad950
s32 Flow4_2(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  struct System_UInt32_array *nextkouho;
  u32 RandIntA;

  nbAddNegoIdKouho(n, 0x40003u);
  nbAddNegoIdKouho(n, 0x4000Cu);
  v4 = *n;
  nextkouho = v4->nextkouho;
  RandIntA = dds3GetRandIntA(2u, "4_2");
  v4->nextnegoid = nextkouho->m_Items[RandIntA];
  return 0;
}

// 0x12ada70
s32 Flow4_3(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x40004u);
  return 0;
}

// 0x12adb10
s32 Flow4_4(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  struct System_UInt32_array *nextkouho;
  u32 RandIntA;

  nbAddNegoIdKouho(n, 0x40005u);
  nbAddNegoIdKouho(n, 0x40006u);
  nbAddNegoIdKouho(n, 0x40007u);
  v4 = *n;
  nextkouho = v4->nextkouho;
  RandIntA = dds3GetRandIntA(3u, "4_4");
  v4->nextnegoid = nextkouho->m_Items[RandIntA];
  return 0;
}

// 0x12adc40
s32 Flow4_5(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  struct System_Int32_array *v7;
  s64 v8;

  nbAddNegoIdKouho(n, 0x40008u);
  v3 = *n;
  v3->getmakka = nbGetNegoYaruMakkaB(n, &(*n)->pwork, &(*n)->ework, 0);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbSetMesMakka(flowmsg->m_Items[ekucyo], (*n)->getmakka, 0);
  v7 = (*n)->flowmsg;
  v8 = (*n)->ekucyo;
  nbDispNegoMessage(n, v7->m_Items[v8], 51, 0);
  return 0;
}

// 0x12add80
s32 Flow4_6(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 getitem;
  s32 v6;
  nbNegoProcessData_t_o *v8;
  struct System_UInt32_array *nextkouho;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v14;
  s32 v15;
  struct System_Int32_array *v16;
  s64 v17;

  nbAddNegoIdKouho(n, 0x40009u);
  nbAddNegoIdKouho(n, 0x40005u);
  v3 = *n;
  v3->getitem = nbGetNegoYaruItemB(&(*n)->ework, 0);
  getitem = (*n)->getitem;
  if (!getitem)
  {
    (*n)->getitem = 18;
    getitem = (*n)->getitem;
  }
  v6 = datCheckItemFull(getitem);
  v8 = *n;
  if (v6)
  {
    nextkouho = v8->nextkouho;
    v8->nextnegoid = nextkouho->m_Items[1];
  }
  else
  {
    flowmsg = v8->flowmsg;
    ekucyo = v8->ekucyo;
    v14 = flowmsg->m_Items[ekucyo];
    v15 = v8->getitem;
    nbSetMesItem(v14, v15);
    v16 = (*n)->flowmsg;
    v17 = (*n)->ekucyo;
    nbDispNegoMessage(n, v16->m_Items[v17], 52, 0);
  }
  return 0;
}

// 0x12adf70
s32 Flow4_7(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x4000Au);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 53, 0);
  return 0;
}

// 0x12ae060
s32 Flow4_8(nbNegoProcessData_t **n) {
  s32 getmakka;

  nbAddNegoIdKouho(n, 0x4000Bu);
  getmakka = (*n)->getmakka;
  datAddMaka(getmakka);
  return 0;
}

// 0x12ae130
s32 Flow4_9(nbNegoProcessData_t **n) {
  s32 getitem;

  nbAddNegoIdKouho(n, 0x4000Bu);
  getitem = (*n)->getitem;
  datAddItem(getitem, 1);
  return 0;
}

// 0x12ad280
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0x12ad290
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0x12ae690
s32 nbNegoFlowDouchara(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowDouchara_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n, 0);
}
