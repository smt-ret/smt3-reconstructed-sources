#include "types.h"

typedef struct NbNegoFlowFullMoon_procfuncDelegate NbNegoFlowFullMoon_procfuncDelegate;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static NbNegoFlowFullMoon_procfuncDelegate *procfunc[17];

void datAddKotowariPoint(s32 type, s32 point);
void datAddMaka(s32 addmaka);
s32 datCheckStockFull(void);
s32 datGetParam(datUnitWork_t *work, s32 paratype);
s32 datGetPlayerLevel(void);
s32 datGetRace(datUnitWork_t *work);
s32 datSearchDevilStock(s32 id);
u32 dds3GetRandIntA(u32 aLimit, char *name);
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbCameraSetTarget(nbFormation_t **pTargetForm);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);
s32 nbGetNegoYaruMakkaB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
s32 nbGetQuestionType(datUnitWork_t **w);
void nbSetMesMakka(s32 msgid, s32 i);
s32 nbSetNegoNoMotion(nbNegoProcessData_t **n, nbFormation_t **form);
s32 nbSetNegoYesMotion(nbNegoProcessData_t **n, nbFormation_t **form);

// 0x536650
s32 Flow2_1(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  struct datUnitWork_t_o *ework;
  u32 id;
  bool v7;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  datUnitWork_t_o *v13;
  struct System_UInt32_array *v15;
  struct datUnitWork_t_o *v17;
  u32 v18;
  datUnitWork_t_o *v20;
  u32 RandIntA;
  u32 max_length;

  nbAddNegoIdKouho(n, 0x20003u);
  nbAddNegoIdKouho(n, 0x20002u);
  nbAddNegoIdKouho(n, 0x10020u);
  v4 = *n;
  ework = (*n)->ework;
  id = ework->id;
  v7 = id > 0x1E || ((1 << id) & 0x61012538) == 0;
  if (!v7 || id == 153 || id == 150)
  {
    nextkouho = v4->nextkouho;
    m_Items = &nextkouho->m_Items[2];
  }
  else
  {
    if (datGetRace(ework) == 19)
    v13 = (*n)->ework;
    if (datGetRace(v13) == 18)
    {
      v4 = *n;
      v15 = (*n)->nextkouho;
      if (LODWORD(v15->max_length) <= 1)
    }
    v4 = *n;
    v17 = (*n)->ework;
    v18 = v17->id;
    if (v18 > 0x6D)
    {
      if (v18 == 110 || v18 == 144)
      {
        v15 = v4->nextkouho;
        m_Items = &v15->m_Items[1];
      }
      if (v18 == 154)
    }
    else    if (datGetRace(v17) == 7)
    v20 = (*n)->ework;
    if (datGetRace(v20) == 8)
    RandIntA = dds3GetRandIntA(0x64u, StringLiteral_5307);
    v4 = *n;
    v15 = (*n)->nextkouho;
    max_length = v15->max_length;
    if (RandIntA <= 0x31)
    {
      if (max_length <= 1)
    }
    m_Items = v15->m_Items;
  }
  v4->nextnegoid = *m_Items;
  return 0;
}

// 0x537940
s32 Flow2_10(nbNegoProcessData_t **n) {
  datUnitWork_t_o *ework;
  datUnitWork_t_o *v6;
  datUnitWork_t_o *v7;
  s32 v8;
  s32 id;
  s32 v11;
  bool v13;
  s32 level;
  datUnitWork_t_o *v16;
  datUnitWork_t_o *v18;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v23;
  u32 RandIntA;
  struct System_Int32_array *v25;
  s64 v26;
  signed s32 v27;
  nbNegoProcessData_t_o *v29;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  struct System_UInt32_array *v34;

  nbAddNegoIdKouho(n, 0x2000Bu);
  nbAddNegoIdKouho(n, 0x2000Cu);
  ework = (*n)->ework;
  if (datGetRace(ework) == 21)
  v6 = (*n)->ework;
  if (datGetRace(v6) == 22)
  v7 = (*n)->ework;
  if (datGetRace(v7) == 23)
    v8 = 0;
  else
    v8 = 70;
  id = (*n)->ework->id;
  v11 = datSearchDevilStock(id);
  if (datCheckStockFull())
    v13 = 0;
  else
    v13 = v11 < 0;
  if (!v13)
    v8 = 100;
  level = (*n)->ework->level;
  if (datGetPlayerLevel() < level)
    v8 = 100;
  v16 = (*n)->ework;
  if (datGetRace(v16) == 19)
  v18 = (*n)->ework;
  if (datGetRace(v18) == 18)
  {
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    v23 = flowmsg->m_Items[ekucyo];
  }
  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_5311);
  v25 = (*n)->flowmsg;
  v26 = (*n)->ekucyo;
  v27 = RandIntA;
  v23 = v25->m_Items[v26];
  if (v27 < v8)
  {
    {
      nbDispNegoMessage(n, v23, 41, 0);
      v29 = *n;
      nextkouho = v29->nextkouho;
      m_Items = nextkouho->m_Items;
    }
  }
  nbDispNegoMessage(n, v23, 42, 0);
  v29 = *n;
  v34 = v29->nextkouho;
  m_Items = &v34->m_Items[1];
  v29->nextnegoid = *m_Items;
  return 0;
}

// 0x537d10
s32 Flow2_11(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 getmakka;

  nbAddNegoIdKouho(n, 0xA001Cu);
  v3 = *n;
  v3->getmakka = nbGetNegoYaruMakkaB(n, &(*n)->pwork, &(*n)->ework, 0);
  nbSetMesMakka((*n)->helpmsg, (*n)->getmakka, 0);
  nbDispNegoMessage(n, (*n)->helpmsg, 3, 0, 0);
  getmakka = (*n)->getmakka;
  datAddMaka(getmakka);
  return 0;
}

// 0x537e30
s32 Flow2_12(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x90007u);
  nbDispNegoMessage(n, (*n)->helpmsg, 9, 0, 0);
  return 0;
}

// 0x537ef0
s32 Flow2_13(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  nbNegoProcessData_t_o *v6;
  s32 qtype;
  s32 v8;
  s32 questionmsg;
  s32 v11;
  s32 v12;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0x2000Eu);
    v6 = *n;
    qtype = (*n)->qtype;
    if (qtype)
    {
      if ((qtype - 1) <= 2)
        v8 = 10;
      else
        v8 = 0;
      questionmsg = v6->questionmsg;
    }
    else
    {
      if (v6->nowselect)
        v11 = 22;
      else
        v11 = 20;
      if (v6->nowselect)
        v12 = 16;
      else
        v12 = 14;
      if (v6->qindex)
        v8 = v11;
      else
        v8 = v12;
      questionmsg = v6->questionmsg;
      {
      }
    }
    nbDispNegoMessage(n, questionmsg, v8, 0);
    return 0;
  }
  if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0x538070
s32 Flow2_14(nbNegoProcessData_t **n) {
  nbFormation_t_o **p_eform;
  u32 RandIntA;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v11;
  nbNegoProcessData_t_o *v12;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  struct System_UInt32_array *v16;

  nbAddNegoIdKouho(n, 0x2000Fu);
  nbAddNegoIdKouho(n, 0x20010u);
  p_eform = &(*n)->eform;
  nbCameraSetTarget(p_eform);
  RandIntA = dds3GetRandIntA(2u, StringLiteral_5312);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v11 = flowmsg->m_Items[ekucyo];
  if (RandIntA)
  {
    nbDispNegoMessage(n, v11, 46, 0);
    v12 = *n;
    nextkouho = v12->nextkouho;
    m_Items = nextkouho->m_Items;
  }
  else
  {
    nbDispNegoMessage(n, v11, 47, 0);
    v12 = *n;
    v16 = v12->nextkouho;
    m_Items = &v16->m_Items[1];
  }
  v12->nextnegoid = *m_Items;
  return 0;
}

// 0x538280
s32 Flow2_15(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xA001Du);
  nbDispNegoMessage(n, (*n)->helpmsg, 1, 0, 0);
  return 0;
}

// 0x538340
s32 Flow2_16(nbNegoProcessData_t **n) {
  struct System_Int32_array *temp_param;

  if ((*n)->negoskillid != 395)
    return 4;
  if (!(*n)->pwork->hp)
    return 4;
  nbAddNegoIdKouho(n, 0xA0021u);
  temp_param = (*n)->temp_param;
  temp_param->m_Items[0] = 4;
  return 0;
}

// 0x536930
s32 Flow2_2(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  s32 result;
  s32 id;
  u32 v7;
  bool v8;
  s64 v9;
  u32 RandIntA;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v15;
  s32 v17;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    RandIntA = dds3GetRandIntA(2u, StringLiteral_5308);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    v15 = RandIntA + 26;
    v17 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v17, v15, 0);
    return 1;
  }
  else
  {
    result = 0;
    if (!nownegophase)
    {
      id = v3->ework->id;
      if ((id - 36) >= 4)
      {
        v7 = id - 110;
        v8 = v7 > 0x2C;
        v9 = (1LL << v7) & 0x100400000001LL;
        if (v8 || v9 == 0)
        {
          v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
          return 0;
        }
      }
    }
  }
  return result;
}

// 0x536ad0
s32 Flow2_3(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x20004u);
  return 0;
}

// 0x536b70
s32 Flow2_4(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  struct System_Byte_array *negoques;
  s64 qtype;
  struct System_Byte_array *v10;
  s64 v11;

  nbAddNegoIdKouho(n, 0x20005u);
  v3 = *n;
  v3->qtype = nbGetQuestionType(&(*n)->ework, 0);
  negoques = DDS3_GBWK->negoques;
  qtype = (*n)->qtype;
  if (negoques->m_Items[qtype] != 255)
  {
    v10 = DDS3_GBWK->negoques;
    v11 = (*n)->qtype;
    ++v10->m_Items[v11];
  }
  return 0;
}

// 0x536cf0
s32 Flow2_5(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  nbNegoProcessData_t_o *v5;
  s32 v6;
  s32 v7;
  s32 v8;
  s32 questionmsg;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    v7 = 6;
    switch (v3->qtype)
    {
      case 0:
        if (v3->qindex)
          v7 = 18;
        else
          v7 = 12;
        break;
      case 1:
        break;
      case 2:
        v7 = 8;
        break;
      case 3:
        v7 = 4;
        break;
      default:
        v7 = 0;
        break;
    }
    questionmsg = v3->questionmsg;
    nbDispNegoMessage(n, questionmsg, v7, 1);
    nbAddNegoIdKouho(n, 0x20006u);
  }
  else if (!nownegophase)
  {
    v3->qindex = 0;
    v5 = *n;
    v6 = 5;
    switch ((*n)->qtype)
    {
      case 0:
        v5->qindex = dds3GetRandIntA(2u, StringLiteral_5309);
        v5 = *n;
        if ((*n)->qindex)
          v6 = 17;
        else
          v6 = 11;
        break;
      case 1:
        break;
      case 2:
        v6 = 7;
        break;
      case 3:
        v6 = 3;
        break;
      default:
        v6 = 0;
        break;
    }
    v8 = v5->questionmsg;
    nbDispNegoMessage(n, v8, v6, 0);
  }
  return 0;
}

// 0x536ef0
s32 Flow2_6(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  s32 qtype;
  s32 v6;
  struct datNegoNormalQuesInfo_t_array_array *datNegoNormalQuesInfo;
  s64 ekucyo;
  Il2CppClass **v11;
  s64 qindex;
  Il2CppClass *v13;
  s32 v15;
  struct datNegoNormalQuesInfo_t_array_array *v16;
  s64 v17;
  Il2CppClass **v19;
  s64 v20;
  Il2CppClass *v21;
  s64 v23;
  s64 v24;
  struct datNegoNormalQuesInfo_t_array_array *v25;
  Il2CppClass **v27;
  s64 v28;
  Il2CppClass *v29;
  s32 v31;
  datUnitWork_t_o *pwork;
  s32 Param;
  s32 v34;
  s32 nowselect;
  s32 v36;
  datUnitWork_t_o *v37;
  s32 v38;
  u32 RandIntA;
  nbNegoProcessData_t_o *v41;
  s32 v42;
  signed s32 v43;
  struct System_Byte_array_array_array_array *v45;
  s64 v46;
  System_Byte_array_array_array *v48;
  System_Byte_array_array *v50;
  s64 v51;
  System_Byte_array *v53;
  struct System_Byte_array_array_array_array *v55;
  s64 v56;
  System_Byte_array_array_array *v58;
  System_Byte_array_array *v60;
  struct System_Byte_array_array_array_array *datNegoKotowariQuesInfo;
  s64 v63;
  System_Byte_array_array_array *v65;
  System_Byte_array_array *v67;
  s64 v68;
  System_Byte_array *v70;
  struct System_Byte_array_array_array_array *v72;
  s64 v73;
  System_Byte_array_array_array *v75;
  struct System_Byte_array_array_array_array *v78;
  s64 v79;
  System_Byte_array_array_array *v81;
  System_Byte_array_array *v83;
  s64 v84;
  System_Byte_array *v86;
  struct System_Byte_array_array_array_array *v88;
  s64 v89;
  System_Byte_array_array_array *v91;
  s64 v93;
  nbNegoProcessData_t_o *v96;
  u32 *nextkouho;
  u32 v98;
  u32 *v100;

  nbAddNegoIdKouho(n, 0x20007u);
  nbAddNegoIdKouho(n, 0x2000Du);
  v4 = *n;
  qtype = (*n)->qtype;
  if (!qtype)
  {
    ekucyo = v4->ekucyo;
    v11 = &datNegoNormalQuesInfo->obj.klass + ekucyo;
    qindex = v4->qindex;
    v13 = v11[4];
    v15 = *(*(&v13->_1.byval_arg.data + qindex) + 16LL);
    v16 = datNegoNormalQuesInfo;
    v17 = v4->ekucyo;
    v19 = &v16->obj.klass + v17;
    v20 = v4->qindex;
    v21 = v19[4];
    v23 = v21 + 8 * v20;
    v24 = v4->ekucyo;
    v6 = *(*(v23 + 32) + 18LL);
    v25 = datNegoNormalQuesInfo;
    v27 = &v25->obj.klass + v24;
    v28 = v4->qindex;
    v29 = v27[4];
    v31 = *(*(&v29->_1.byval_arg.data + v28) + 19LL);
    if (v15 == 1)
    {
      nowselect = (*n)->nowselect;
      if ((*n)->pwork->level < (*n)->ework->level)
      {
        if (nowselect)
          v36 = 100 - v31;
        else
          v36 = v31;
      }
    }
    else
    {
      if (v15)
      pwork = (*n)->pwork;
      Param = datGetParam(pwork, 1);
      v34 = datGetParam((*n)->ework, 1, 0);
      nowselect = (*n)->nowselect;
      if (Param < v34)
    }
    if (nowselect)
      v36 = 100 - v6;
    else
      v36 = v6;
  }
  if ((qtype - 1) > 2)
  {
    v6 = 0;
    v36 = 50;
  }
  v37 = v4->pwork;
  v38 = datGetParam(v37, 1);
  v6 = 0;
  if (v38 >= datGetParam((*n)->ework, 1, 0))
    v36 = 70;
  else
    v36 = 30;
  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_5310);
  v41 = *n;
  v42 = (*n)->qtype;
  v43 = RandIntA;
  switch (v42)
  {
    case 3:
      v63 = v41->ekucyo;
      v65 = datNegoKotowariQuesInfo->m_Items[v63];
      v67 = v65->m_Items[0];
      v68 = (*n)->nowselect;
      v70 = v67->m_Items[v68];
      v72 = datNegoKotowariQuesInfo;
      v73 = (*n)->ekucyo;
      v6 = v70->m_Items[0];
      v75 = v72->m_Items[v73];
      v60 = v75->m_Items[0];
      break;
    case 2:
      v78 = datNegoKotowariQuesInfo;
      v79 = v41->ekucyo;
      v81 = v78->m_Items[v79];
      v83 = v81->m_Items[2];
      v84 = (*n)->nowselect;
      v86 = v83->m_Items[v84];
      v88 = datNegoKotowariQuesInfo;
      v89 = (*n)->ekucyo;
      v6 = v86->m_Items[0];
      v91 = v88->m_Items[v89];
      v60 = v91->m_Items[2];
      break;
    case 1:
      v45 = datNegoKotowariQuesInfo;
      v46 = v41->ekucyo;
      v48 = v45->m_Items[v46];
      v50 = v48->m_Items[1];
      v51 = (*n)->nowselect;
      v53 = v50->m_Items[v51];
      v55 = datNegoKotowariQuesInfo;
      v56 = (*n)->ekucyo;
      v6 = v53->m_Items[0];
      v58 = v55->m_Items[v56];
      v60 = v58->m_Items[1];
      break;
    default:
  }
  v93 = (*n)->nowselect;
  v96 = *n;
  if (((*n)->qtype - 1) <= 2)
  {
    datAddKotowariPoint(v6, 1);
    v96 = *n;
  }
  nextkouho = v96->nextkouho;
  v98 = nextkouho[6];
  if (v43 >= v36)
  {
    v100 = nextkouho + 9;
  }
  else
  {
    v100 = nextkouho + 8;
  }
  v96->nextnegoid = *v100;
  return 0;
}

// 0x5376c0
s32 Flow2_7(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;

  nbAddNegoIdKouho(n, 0x20008u);
  v3 = *n;
  v3->waitframe = nbSetNegoYesMotion(n, &(*n)->eform, 0);
  return 0;
}

// 0x537770
s32 Flow2_8(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x20009u);
  return 0;
}

// 0x537810
s32 Flow2_9(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  s32 qtype;
  s32 v6;
  s32 questionmsg;
  s32 v9;
  s32 v10;

  nbAddNegoIdKouho(n, 0x2000Au);
  v4 = *n;
  qtype = (*n)->qtype;
  if (qtype)
  {
    if ((qtype - 1) <= 2)
      v6 = 9;
    else
      v6 = 0;
    questionmsg = v4->questionmsg;
    {
    }
  }
  else
  {
    if (v4->nowselect)
      v9 = 21;
    else
      v9 = 19;
    if (v4->nowselect)
      v10 = 15;
    else
      v10 = 13;
    if (v4->qindex)
      v6 = v9;
    else
      v6 = v10;
    questionmsg = v4->questionmsg;
  }
  nbDispNegoMessage(n, questionmsg, v6, 0);
  return 0;
}

// 0x536630
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0x536640
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0x538440
s32 nbNegoFlowFullMoon(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowFullMoon_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
