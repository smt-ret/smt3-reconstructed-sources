#include "types.h"

typedef struct NbNegoFlowOk_procfuncDelegate NbNegoFlowOk_procfuncDelegate;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static NbNegoFlowOk_procfuncDelegate *procfunc[23];

u8 Get(s32 id);
void datAddItem(s32 id, s32 num);
void datAddMaka(s32 addmaka);
s32 datCheckItemFull(s32 id);
s32 datCheckStockFull(void);
s32 datGetPlayerLevel(void);
s32 datGetRace(datUnitWork_t *work);
u32 dds3GetRandIntA(u32 aLimit, char *name);
bool evtBitCheck(s32 no);
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbCameraSetTarget(nbFormation_t **pTargetForm);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);
s32 nbGetInfoMsg(s32 infotype);
s32 nbGetNegoYaruItemA(datUnitWork_t **w);
s32 nbGetNegoYaruMakkaA(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
s32 nbGetNegoYaruStone(datUnitWork_t **w);
void nbSetMesItem(s32 msgid, s32 it);
void nbSetMesMakka(s32 msgid, s32 i);
s32 nbSetNegoYesMotion(nbNegoProcessData_t **n, nbFormation_t **form);

// 0x546ad0
s32 Flow9_1(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  datUnitWork_t_o *ework;
  datUnitWork_t_o *v8;
  datUnitWork_t_o *v9;
  nbNegoProcessData_t_o *v10;
  s32 id;
  nbNegoProcessData_t_o *v12;
  struct System_UInt32_array *v13;
  u32 *m_Items;
  nbFormation_t_o **p_eform;
  s32 negoreqtype;
  struct System_UInt32_array *v18;
  struct System_UInt32_array *v21;
  struct System_UInt32_array *nextkouho;

  nbAddNegoIdKouho(n, 0x90002u);
  nbAddNegoIdKouho(n, 0x9000Bu);
  nbAddNegoIdKouho(n, 0x90013u);
  nbAddNegoIdKouho(n, 0x6004Au);
  workid = (*n)->workid;
  workid->m_Items[6] = 393237;
  ework = (*n)->ework;
  if (datGetRace(ework) != 23)
  {
    v8 = (*n)->ework;
    if (datGetRace(v8) != 22)
    {
      v9 = (*n)->ework;
      if (datGetRace(v9) != 21)
        ++(*n)->cnt6_37;
    }
  }
  v10 = *n;
  if ((*n)->negoreqtype)
    goto LABEL_37;
  if (v10->cnt6_36 < 2)
    goto LABEL_37;
  if (v10->cnt6_37 != 1)
    goto LABEL_37;
  if (!evtBitCheck(8))
    goto LABEL_37;
  id = (*n)->ework->id;
  if (id == 92 || id == 97)
    goto LABEL_37;
  if (dds3GetRandIntA(0xAu, "9_1") > 7)
  {
LABEL_37:
    p_eform = &(*n)->eform;
    nbCameraSetTarget(p_eform);
    v12 = *n;
    negoreqtype = v12->negoreqtype;
    if ((negoreqtype - 1) >= 5)
    {
      if (negoreqtype == 6)
      {
        nextkouho = v12->nextkouho;
        m_Items = &nextkouho->m_Items[2];
      }
      else
      {
        if (negoreqtype)
          return 0;
        v21 = v12->nextkouho;
        m_Items = v21->m_Items;
      }
    }
    else
    {
      v18 = v12->nextkouho;
      m_Items = &v18->m_Items[1];
    }
  }
  else
  {
    v12 = *n;
    v13 = v12->nextkouho;
    m_Items = &v13->m_Items[3];
  }
  v12->nextnegoid = *m_Items;
  return 0;
}

// 0x547500
s32 Flow9_10(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0xA001Du);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 173, 0);
  return 0;
}

// 0x5475f0
s32 Flow9_11(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  struct System_UInt32_array *nextkouho;
  u32 v7;
  struct System_UInt32_array *v8;
  struct System_UInt32_array *v10;
  u32 RandIntA;

  nbAddNegoIdKouho(n, 0x9000Du);
  nbAddNegoIdKouho(n, 0x90010u);
  v4 = *n;
  switch (v4->negoreqtype)
  {
    case 1:
    case 5:
      nextkouho = v4->nextkouho;
      v7 = nextkouho->m_Items[0];
      goto LABEL_23;
    case 2:
      v10 = v4->nextkouho;
      RandIntA = dds3GetRandIntA(2u, "9_11");
      v7 = v10->m_Items[RandIntA];
      goto LABEL_23;
    case 3:
    case 4:
      v8 = v4->nextkouho;
      v7 = v8->m_Items[1];
LABEL_23:
      v4->nextnegoid = v7;
      break;
    default:
      v4->negoreqtype = 1;
      break;
  }
  return 0;
}

// 0x547790
s32 Flow9_13(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  nbNegoProcessData_t_o *v5;
  nbNegoProcessData_t_o *v7;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  char *v11;
  s32 getmakka;
  s32 v13;
  struct System_Int32_array *v14;
  s64 v15;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0x9000Eu);
    v5 = *n;
    v5->getmakka = nbGetNegoYaruMakkaA(n, &(*n)->pwork, &(*n)->ework, 0);
    v7 = *n;
    if ((*n)->negoskillid == 401)
    {
      v7->getmakka = 3 * v7->getmakka / 2;
      v7 = *n;
    }
    flowmsg = v7->flowmsg;
    ekucyo = v7->ekucyo;
    v11 = flowmsg + 4 * ekucyo;
    getmakka = v7->getmakka;
    v13 = *(v11 + 8);
    nbSetMesMakka(v13, getmakka);
    v14 = (*n)->flowmsg;
    v15 = (*n)->ekucyo;
    nbDispNegoMessage(n, v14->m_Items[v15], 168, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0x547970
s32 Flow9_14(nbNegoProcessData_t **n) {
  (*n)->actdata->stat |= 8u;
  nbAddNegoIdKouho(n, 0x9000Fu);
  nbSetMesMakka((*n)->helpmsg, (*n)->getmakka, 0);
  nbDispNegoMessage(n, (*n)->helpmsg, 3, 0, 0);
  return 0;
}

// 0x547a50
s32 Flow9_15(nbNegoProcessData_t **n) {
  s32 getmakka;
  nbNegoProcessData_t_o *v6;
  struct System_Byte_array *syakkincnt;
  s32 id;
  s64 race;
  struct System_Byte_array *v14;
  s32 v15;
  s64 v16;

  nbAddNegoIdKouho(n, 0xA001Cu);
  getmakka = (*n)->getmakka;
  datAddMaka(getmakka);
  v6 = *n;
  if ((*n)->negoskillid == 401)
  {
    syakkincnt = DDS3_GBWK->syakkincnt;
    id = v6->ework->id;
    race = Get(id, 1, 0)->race;
    if (syakkincnt->m_Items[race] != 255)
    {
      v14 = DDS3_GBWK->syakkincnt;
      v15 = (*n)->ework->id;
      v16 = Get(v15, 1, 0)->race;
      ++v14->m_Items[v16];
    }
  }
  return 0;
}

// 0x547c70
s32 Flow9_16(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  nbNegoProcessData_t_o *v6;
  s32 v7;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  struct System_Int32_array *v11;
  s64 v12;
  s32 getitem;
  struct System_Int32_array *v16;
  s64 v17;
  char *v19;
  s32 v20;
  s32 v21;
  struct System_Int32_array *v22;
  s64 v23;
  nbNegoProcessData_t_o *v25;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 2)
  {
    nbAddNegoIdKouho(n, 0x90011u);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbSetMesItem(flowmsg->m_Items[ekucyo], (*n)->getitem, 0);
    v11 = (*n)->flowmsg;
    v12 = (*n)->ekucyo;
    nbDispNegoMessage(n, v11->m_Items[v12], 169, 0);
  }
  else
  {
    if (nownegophase != 1)
    {
      if (nownegophase)
        return 0;
      if (v3->negoreqtype == 3)
      {
        v3->getitem = nbGetNegoYaruStone(&v3->ework);
        v6 = *n;
        if ((*n)->getitem)
          goto LABEL_33;
        v7 = 106;
      }
      else
      {
        v3->getitem = nbGetNegoYaruItemA(&v3->ework);
        v6 = *n;
        if ((*n)->getitem)
          goto LABEL_33;
        v7 = 6;
      }
      v6->getitem = v7;
LABEL_33:
      getitem = (*n)->getitem;
      if (datCheckItemFull(getitem))
      {
        v16 = (*n)->flowmsg;
        v17 = (*n)->ekucyo;
        v19 = v16 + 4 * v17;
        v20 = (*n)->getitem;
        v21 = *(v19 + 8);
        nbSetMesItem(v21, v20);
        v22 = (*n)->flowmsg;
        v23 = (*n)->ekucyo;
        nbDispNegoMessage(n, v22->m_Items[v23], 151, 0);
        v25 = *n;
        v25->getmakka = nbGetNegoYaruMakkaA(n, &(*n)->pwork, &(*n)->ework, 0);
        nbAddNegoIdKouho(n, 0x9000Eu);
      }
      return 0;
    }
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0x547fb0
s32 Flow9_17(nbNegoProcessData_t **n) {
  (*n)->actdata->stat |= 8u;
  nbAddNegoIdKouho(n, 0x90012u);
  nbSetMesItem((*n)->helpmsg, (*n)->getitem, 0);
  nbDispNegoMessage(n, (*n)->helpmsg, 5, 0, 0);
  return 0;
}

// 0x548090
s32 Flow9_18(nbNegoProcessData_t **n) {
  s32 getitem;

  nbAddNegoIdKouho(n, 0xA001Cu);
  getitem = (*n)->getitem;
  datAddItem(getitem, 1);
  return 0;
}

// 0x548160
s32 Flow9_19(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0x90014u);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 170, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0x546e10
s32 Flow9_2(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0x90003u);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 167, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0x5482a0
s32 Flow9_20(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *v5;
  s64 v6;
  s32 v8;
  s32 v9;
  nbNegoProcessData_t_o **v10;
  s32 v11;
  s32 v12;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v16;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  switch (nownegophase)
  {
    case 2:
      v3->getinfotype = 2 * (v3->nowselect != 0);
      nbAddNegoIdKouho(n, 0x90015u);
      break;
    case 1:
      flowmsg = v3->flowmsg;
      ekucyo = v3->ekucyo;
      v16 = flowmsg->m_Items[ekucyo];
      v9 = 275;
      v10 = n;
      v11 = v16;
      v12 = 1;
      goto LABEL_25;
    case 0:
      v5 = v3->flowmsg;
      v6 = v3->ekucyo;
      v8 = v5->m_Items[v6];
      v9 = 274;
      v10 = n;
      v11 = v8;
      v12 = 0;
LABEL_25:
      nbDispNegoMessage(v10, v11, v9, v12);
      break;
  }
  return 0;
}

// 0x548440
s32 Flow9_21(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;

  (*n)->actdata->stat |= 8u;
  nbAddNegoIdKouho(n, 0x90016u);
  v3 = *n;
  v3->getinfomsg = nbGetInfoMsg(v3->getinfotype);
  return 0;
}

// 0x548500
s32 Flow9_22(nbNegoProcessData_t **n) {
  struct System_Int32_array *infomsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0xA001Cu);
  infomsg = (*n)->infomsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, infomsg->m_Items[ekucyo], (*n)->getinfomsg, 0, 0);
  return 0;
}

// 0x546f50
s32 Flow9_3(nbNegoProcessData_t **n) {
  s32 v4;
  nbNegoProcessData_t_o *v5;
  u32 *nextkouho;
  u32 v7;
  u32 *v9;

  nbAddNegoIdKouho(n, 0x90004u);
  nbAddNegoIdKouho(n, 0x90006u);
  v4 = datCheckStockFull();
  v5 = *n;
  nextkouho = v5->nextkouho;
  v7 = nextkouho[6];
  if (v4)
  {
    v9 = nextkouho + 9;
  }
  else
  {
    v9 = nextkouho + 8;
  }
  v5->nextnegoid = *v9;
  return 0;
}

// 0x547080
s32 Flow9_4(nbNegoProcessData_t **n) {
  u64 *v4;
  Il2CppObject *v5;
  u64 *v7;
  s32 v8;
  nbNegoProcessData_t_o *v9;
  u32 *nextkouho;
  u32 v11;
  u32 *v13;
  u16 v16[2];
  s32 PlayerLevel;

  nbAddNegoIdKouho(n, 0x90005u);
  nbAddNegoIdKouho(n, 0x90009u);
  PlayerLevel = datGetPlayerLevel();
  v4 = sub_8D3950(s32, &PlayerLevel);
  v16[0] = (*n)->ework->level;
  v5 = v4;
  v7 = sub_8D3950(ushort, v16);
  Write_2930752("plv = {0:D}, elv = {1:D}\n", v5, v7, 0);
  v8 = datGetPlayerLevel();
  v9 = *n;
  nextkouho = v9->nextkouho;
  v11 = nextkouho[6];
  if (v8 >= v9->ework->level)
  {
    v13 = nextkouho + 8;
  }
  else
  {
    v13 = nextkouho + 9;
  }
  v9->nextnegoid = *v13;
  return 0;
}

// 0x547240
s32 Flow9_5(nbNegoProcessData_t **n) {
  (*n)->actdata->stat |= 8u;
  nbAddNegoIdKouho(n, 0x90007u);
  nbDispNegoMessage(n, (*n)->helpmsg, 2, 0, 0);
  return 0;
}

// 0x547310
s32 Flow9_6(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x9000Au);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 171, 0);
  return 0;
}

// 0x547400
s32 Flow9_7(nbNegoProcessData_t **n) {
  return 9;
}

// 0x547410
s32 Flow9_9(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x9000Au);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 172, 0);
  return 0;
}

// 0x546ab0
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0x546ac0
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0x5485f0
s32 nbNegoFlowOk(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowOk_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
