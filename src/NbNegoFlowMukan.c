#include "types.h"

typedef struct NbNegoFlowMukan_procfuncDelegate NbNegoFlowMukan_procfuncDelegate;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static NbNegoFlowMukan_procfuncDelegate *procfunc[50];

u8 Get(s32 id);
void datAddItem(s32 id, s32 num);
void datAddMaka(s32 addmaka);
s32 datCheckItemFull(s32 id);
s32 datCheckStockFull(void);
s32 datGetParam(datUnitWork_t *work, s32 paratype);
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
s32 nbSetNegoNoMotion(nbNegoProcessData_t **n, nbFormation_t **form);
s32 nbSetNegoYesMotion(nbNegoProcessData_t **n, nbFormation_t **form);

// 0x53e1c0
s32 Flow12_1(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;

  nbAddNegoIdKouho(n, 0x1001Fu);
  workid = (*n)->workid;
  workid->m_Items[3] = 786434;
  return 0;
}

// 0x53efb0
s32 Flow12_16(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xC001Au);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 238, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0x53f0f0
s32 Flow12_17(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xC002Eu);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 239, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0x53f230
s32 Flow12_18(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xC001Au);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 240, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0x53f370
s32 Flow12_19(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xC002Eu);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 241, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0x53e290
s32 Flow12_2(nbNegoProcessData_t **n) {
  s32 id;
  s64 mukanindex;
  signed s32 RandIntA;
  struct System_Byte_array_array *datNegoMukanTypeList;
  System_Byte_array *v11;
  s64 v12;
  struct System_Byte_array_array *v16;
  System_Byte_array *v17;
  s32 v19;
  struct System_Byte_array_array *v22;
  System_Byte_array *v24;
  struct System_Byte_array_array *v27;
  System_Byte_array *v29;
  s32 v32;
  struct System_Byte_array_array *v33;
  s32 v35;
  System_Byte_array *v36;
  nbNegoProcessData_t_o *v38;
  struct System_UInt32_array *nextkouho;
  struct System_Byte_array_array *v43;

  nbAddNegoIdKouho(n, 0xC0003u);
  nbAddNegoIdKouho(n, 0xC0004u);
  nbAddNegoIdKouho(n, 0xC0018u);
  id = (*n)->ework->id;
  mukanindex = Get(id, 0)->mukanindex;
  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_5316);
  v11 = datNegoMukanTypeList->m_Items[mukanindex];
  if (RandIntA < v11->m_Items[0])
  {
    v12 = 0;
    v38 = *n;
    nextkouho = v38->nextkouho;
    v38->nextnegoid = nextkouho->m_Items[v12];
    return 0;
  }
  v16 = datNegoMukanTypeList;
  v17 = v16->m_Items[mukanindex];
  v19 = v17->m_Items[0];
  v22 = datNegoMukanTypeList;
  v24 = v22->m_Items[mukanindex];
  if (RandIntA < v19 + v24->m_Items[1])
  {
    v12 = 1;
  }
  v27 = datNegoMukanTypeList;
  v29 = v27->m_Items[mukanindex];
  v32 = v29->m_Items[1];
  v33 = datNegoMukanTypeList;
  v35 = v19 + v32;
  v36 = v33->m_Items[mukanindex];
  if (RandIntA < v35 + v36->m_Items[2])
  {
    v12 = 2;
  }
  v43 = datNegoMukanTypeList;
  return 0;
}

// 0x53f4b0
s32 Flow12_20(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xC001Au);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 242, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0x53f5f0
s32 Flow12_21(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xC002Eu);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 243, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0x53f730
s32 Flow12_22(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xC001Au);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 244, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0x53f870
s32 Flow12_23(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xC002Eu);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 245, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0x53edb0
s32 Flow12_24(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xC0019u);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 237, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0x53eef0
s32 Flow12_25(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xA001Du);
  nbDispNegoMessage(n, (*n)->helpmsg, 1, 0, 0);
  return 0;
}

// 0x53f9b0
s32 Flow12_26(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xC001Bu);
  return 0;
}

// 0x53fa50
s32 Flow12_27(nbNegoProcessData_t **n) {
    nbAddNegoIdKouho(0, 0);
    dds3GetRandIntA(0, 0);
    datGetRace(0);
    datSearchDevilStock(0);
    datCheckStockFull();
    datGetPlayerLevel();
    return 0;
}

// 0x53ff50
s32 Flow12_28(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v7;
  s32 v8;

  nbAddNegoIdKouho(n, 0xC001Du);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v7 = flowmsg->m_Items[ekucyo];
  if ((*n)->negotype == 2)
  {
    v8 = 261;
  }
  else
  {
    v8 = 249;
  }
  nbDispNegoMessage(n, v7, v8, 0);
  return 0;
}

// 0x540080
s32 Flow12_29(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v8;
  nbNegoProcessData_t_o *v9;
  struct System_UInt32_array *nextkouho;
  s64 nowselect;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xC001Eu);
    nbAddNegoIdKouho(n, 0xC0026u);
    v9 = *n;
    nextkouho = v9->nextkouho;
    nowselect = v9->nowselect;
    v9->nextnegoid = nextkouho->m_Items[nowselect];
  }
  else if (!nownegophase)
  {
    flowmsg = v3->flowmsg;
    ekucyo = v3->ekucyo;
    v8 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v8, 212, 1);
  }
  return 0;
}

// 0x53e710
s32 Flow12_3(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *v5;
  s64 v6;
  s32 v8;
  s32 v9;
  nbNegoProcessData_t_o **v10;
  s32 v11;
  s32 v12;
  struct datUnitWork_t_o *pwork;
  u32 level;
  s32 Param;
  struct datUnitWork_t_o *ework;
  u32 v18;
  s32 v19;
  s32 v21;
  bool v22;
  s32 v23;
  signed s32 RandIntA;
  nbNegoProcessData_t_o *v25;
  struct System_UInt32_array *nextkouho;
  u32 max_length;
  u32 v29;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v33;
  signed s32 v34;
  struct System_UInt32_array *v35;
  u32 v36;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  switch (nownegophase)
  {
    case 2:
      nbAddNegoIdKouho(n, 0xC0010u);
      nbAddNegoIdKouho(n, 0xC0011u);
      nbAddNegoIdKouho(n, 0xC0012u);
      nbAddNegoIdKouho(n, 0xC0013u);
      pwork = (*n)->pwork;
      level = pwork->level;
      Param = datGetParam(pwork, 1);
      ework = (*n)->ework;
      v18 = ework->level;
      v19 = datGetParam(ework, 1);
      if (level >= v18)
        v21 = 40;
      else
        v21 = 20;
      if (Param < v19)
      {
        v22 = 0;
      }
      else
      {
        v21 = 60;
        v22 = level >= v18;
      }
      if (v22)
        v23 = 80;
      else
        v23 = v21;
      if ((*n)->nowselect)
      {
        RandIntA = dds3GetRandIntA(0x64u, StringLiteral_5317);
        v25 = *n;
        nextkouho = v25->nextkouho;
        max_length = nextkouho->max_length;
        if (RandIntA >= 100 - v23)
        {
          v29 = nextkouho->m_Items[3];
        }
        else
        {
          v29 = nextkouho->m_Items[2];
        }
      }
      else
      {
        v34 = dds3GetRandIntA(0x64u, StringLiteral_5317);
        v25 = *n;
        v35 = v25->nextkouho;
        v36 = v35->max_length;
        if (v34 >= v23)
        {
          v29 = v35->m_Items[1];
        }
        else
        {
          v29 = v35->m_Items[0];
        }
      }
      v25->nextnegoid = v29;
      break;
    case 1:
      flowmsg = v3->flowmsg;
      ekucyo = v3->ekucyo;
      v33 = flowmsg->m_Items[ekucyo];
      v9 = 213;
      v10 = n;
      v11 = v33;
      v12 = 1;
    case 0:
      v5 = v3->flowmsg;
      v6 = v3->ekucyo;
      v8 = v5->m_Items[v6];
      v9 = 235;
      v10 = n;
      v11 = v8;
      v12 = 0;
      nbDispNegoMessage(v10, v11, v9, v12);
      break;
  }
  return 0;
}

// 0x5401f0
s32 Flow12_30(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  u32 RandIntA;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v11;
  s32 v12;
  u32 v13;
  struct System_Int32_array *v15;
  s64 v16;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xC001Fu);
    if ((*n)->negotype == 2)
    {
      RandIntA = dds3GetRandIntA(2u, StringLiteral_5321);
      flowmsg = (*n)->flowmsg;
      ekucyo = (*n)->ekucyo;
      v11 = flowmsg->m_Items[ekucyo];
      if (RandIntA)
      {
        v12 = 263;
      }
      else
      {
        v12 = 262;
      }
    }
    else
    {
      v13 = dds3GetRandIntA(2u, StringLiteral_5321);
      v15 = (*n)->flowmsg;
      v16 = (*n)->ekucyo;
      v11 = v15->m_Items[v16];
      if (v13)
      {
        v12 = 251;
      }
      else
      {
        v12 = 250;
      }
    }
    nbDispNegoMessage(n, v11, v12, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0x540450
s32 Flow12_31(nbNegoProcessData_t **n) {
  s32 helpmsg;

  helpmsg = (*n)->helpmsg;
  nbDispNegoMessage(n, helpmsg, 2, 0);
  return 9;
}

// 0x5404e0
s32 Flow12_35(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v7;
  s32 v8;

  nbAddNegoIdKouho(n, 0xC0024u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v7 = flowmsg->m_Items[ekucyo];
  if ((*n)->negotype == 2)
  {
    v8 = 258;
  }
  else
  {
    v8 = 246;
  }
  nbDispNegoMessage(n, v7, v8, 0);
  return 0;
}

// 0x540610
s32 Flow12_36(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v5;
  s32 getinfotype;

  nbAddNegoIdKouho(n, 0xC0025u);
  (*n)->getinfotype = 2 * (dds3GetRandIntA(2u, StringLiteral_5322) != 0);
  v5 = *n;
  getinfotype = (*n)->getinfotype;
  v5->getinfomsg = nbGetInfoMsg(getinfotype);
  return 0;
}

// 0x540730
s32 Flow12_37(nbNegoProcessData_t **n) {
  struct System_Int32_array *infomsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0xA001Cu);
  infomsg = (*n)->infomsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, infomsg->m_Items[ekucyo], (*n)->getinfomsg, 0, 0);
  return 0;
}

// 0x540820
s32 Flow12_38(nbNegoProcessData_t **n) {
  u32 RandIntA;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v9;
  s32 v10;

  nbAddNegoIdKouho(n, 0xC0027u);
  RandIntA = dds3GetRandIntA(2u, StringLiteral_5323);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v9 = flowmsg->m_Items[ekucyo];
  if (RandIntA)
  {
    v10 = 265;
  }
  else
  {
    v10 = 264;
  }
  nbDispNegoMessage(n, v9, v10, 0);
  return 0;
}

// 0x540980
s32 Flow12_39(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xA001Du);
  nbDispNegoMessage(n, (*n)->helpmsg, 1, 0, 0);
  return 0;
}

// 0x53ea60
s32 Flow12_4(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *v5;
  s64 v6;
  s32 v8;
  s32 v9;
  nbNegoProcessData_t_o **v10;
  s32 v11;
  s32 v12;
  struct datUnitWork_t_o *pwork;
  u32 level;
  s32 Param;
  struct datUnitWork_t_o *ework;
  u32 v18;
  s32 v19;
  s32 v21;
  bool v22;
  s32 v23;
  signed s32 RandIntA;
  nbNegoProcessData_t_o *v25;
  struct System_UInt32_array *nextkouho;
  u32 max_length;
  u32 v29;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v33;
  signed s32 v34;
  struct System_UInt32_array *v35;
  u32 v36;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  switch (nownegophase)
  {
    case 2:
      nbAddNegoIdKouho(n, 0xC0014u);
      nbAddNegoIdKouho(n, 0xC0015u);
      nbAddNegoIdKouho(n, 0xC0016u);
      nbAddNegoIdKouho(n, 0xC0017u);
      pwork = (*n)->pwork;
      level = pwork->level;
      Param = datGetParam(pwork, 1);
      ework = (*n)->ework;
      v18 = ework->level;
      v19 = datGetParam(ework, 1);
      if (level >= v18)
        v21 = 40;
      else
        v21 = 20;
      if (Param < v19)
      {
        v22 = 0;
      }
      else
      {
        v21 = 60;
        v22 = level >= v18;
      }
      if (v22)
        v23 = 80;
      else
        v23 = v21;
      if ((*n)->nowselect)
      {
        RandIntA = dds3GetRandIntA(0x64u, StringLiteral_5318);
        v25 = *n;
        nextkouho = v25->nextkouho;
        max_length = nextkouho->max_length;
        if (RandIntA >= 100 - v23)
        {
          v29 = nextkouho->m_Items[3];
        }
        else
        {
          v29 = nextkouho->m_Items[2];
        }
      }
      else
      {
        v34 = dds3GetRandIntA(0x64u, StringLiteral_5318);
        v25 = *n;
        v35 = v25->nextkouho;
        v36 = v35->max_length;
        if (v34 >= v23)
        {
          v29 = v35->m_Items[1];
        }
        else
        {
          v29 = v35->m_Items[0];
        }
      }
      v25->nextnegoid = v29;
      break;
    case 1:
      flowmsg = v3->flowmsg;
      ekucyo = v3->ekucyo;
      v33 = flowmsg->m_Items[ekucyo];
      v9 = 214;
      v10 = n;
      v11 = v33;
      v12 = 1;
    case 0:
      v5 = v3->flowmsg;
      v6 = v3->ekucyo;
      v8 = v5->m_Items[v6];
      v9 = 236;
      v10 = n;
      v11 = v8;
      v12 = 0;
      nbDispNegoMessage(v10, v11, v9, v12);
      break;
  }
  return 0;
}

// 0x540a40
s32 Flow12_40(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v7;
  s32 v8;
  nbNegoProcessData_t_o *v10;
  datUnitWork_t_o **p_pwork;
  datUnitWork_t_o **p_ework;

  nbAddNegoIdKouho(n, 0xC0029u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v7 = flowmsg->m_Items[ekucyo];
  if ((*n)->negotype == 2)
  {
    v8 = 259;
  }
  else
  {
    v8 = 247;
  }
  nbDispNegoMessage(n, v7, v8, 0);
  v10 = *n;
  p_pwork = &(*n)->pwork;
  p_ework = &(*n)->ework;
  v10->getmakka = nbGetNegoYaruMakkaB(n, p_pwork, p_ework);
  return 0;
}

// 0x540bb0
s32 Flow12_41(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xC002Au);
  nbSetMesMakka((*n)->helpmsg, (*n)->getmakka, 0);
  nbDispNegoMessage(n, (*n)->helpmsg, 3, 0, 0);
  return 0;
}

// 0x540c80
s32 Flow12_42(nbNegoProcessData_t **n) {
  s32 getmakka;

  nbAddNegoIdKouho(n, 0xA001Du);
  getmakka = (*n)->getmakka;
  datAddMaka(getmakka);
  return 0;
}

// 0x540d50
s32 Flow12_43(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 getitem;
  s32 v6;
  nbNegoProcessData_t_o *v8;
  struct System_UInt32_array *nextkouho;
  struct System_Int32_array *flowmsg;
  s32 negotype;
  s64 ekucyo;
  s32 v15;
  s32 v16;
  nbNegoProcessData_t_o **v17;
  s32 v18;

  nbAddNegoIdKouho(n, 0xC002Cu);
  nbAddNegoIdKouho(n, 0xC0028u);
  v3 = *n;
  v3->getitem = nbGetNegoYaruItemB(&(*n)->ework, 0);
  getitem = (*n)->getitem;
  if (!getitem)
  {
    (*n)->getitem = 1;
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
    negotype = v8->negotype;
    ekucyo = v8->ekucyo;
    v15 = flowmsg->m_Items[ekucyo];
    if (negotype == 2)
    {
      v16 = 260;
      v17 = n;
      v18 = v15;
    }
    else
    {
      v17 = n;
      v18 = v15;
      v16 = 248;
    }
    nbDispNegoMessage(v17, v18, v16, 0);
  }
  return 0;
}

// 0x540f30
s32 Flow12_44(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xC002Du);
  nbSetMesItem((*n)->helpmsg, (*n)->getitem, 0);
  nbDispNegoMessage(n, (*n)->helpmsg, 5, 0, 0);
  return 0;
}

// 0x541000
s32 Flow12_45(nbNegoProcessData_t **n) {
  s32 getitem;

  nbAddNegoIdKouho(n, 0xA001Du);
  getitem = (*n)->getitem;
  datAddItem(getitem, 1);
  return 0;
}

// 0x5410d0
s32 Flow12_46(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xC002Fu);
  return 0;
}

// 0x541170
s32 Flow12_47(nbNegoProcessData_t **n) {
  u32 RandIntA;
  nbNegoProcessData_t_o *v5;
  u32 *nextkouho;
  u32 v7;
  u32 *v9;

  nbAddNegoIdKouho(n, 0xC0030u);
  nbAddNegoIdKouho(n, 0xC0031u);
  RandIntA = dds3GetRandIntA(2u, StringLiteral_5324);
  v5 = *n;
  nextkouho = v5->nextkouho;
  v7 = nextkouho[6];
  if (RandIntA)
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

// 0x5412b0
s32 Flow12_48(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xA001Du);
  return 0;
}

// 0x541350
s32 Flow12_49(nbNegoProcessData_t **n) {
  return 4;
}

// 0x53e1a0
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0x53e1b0
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0x541360
s32 nbNegoFlowMukan(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowMukan_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
