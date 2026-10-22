#include "types.h"

typedef struct NbNegoFlowQuestion_procfuncDelegate NbNegoFlowQuestion_procfuncDelegate;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static NbNegoFlowQuestion_procfuncDelegate *procfunc[27];

void datAddKotowariPoint(s32 type, s32 point);
s32 datGetParam(datUnitWork_t *work, s32 paratype);
u32 dds3GetRandIntA(u32 aLimit, char *name);
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);
s32 nbGetQuestionType(datUnitWork_t **w);
s32 nbSetNegoNoMotion(nbNegoProcessData_t **n, nbFormation_t **form);
s32 nbSetNegoYesMotion(nbNegoProcessData_t **n, nbFormation_t **form);

// 0xeefed0
s32 Flow7_1(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x70003u);
  return 0;
}

// 0xef01d0
s32 Flow7_11(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  s32 qtype;
  bool v6;
  s32 v7;
  s32 v8;
  s32 v9;
  bool v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 questionmsg;
  s32 v15;
  s32 v16;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase != 1)
  {
    if (nownegophase)
      return 0;
    qtype = v3->qtype;
    switch (qtype)
    {
      case 3:
        v6 = v3->qindex == 0;
        v7 = 29;
        v8 = 27;
        break;
      case 2:
        v6 = v3->qindex == 0;
        v7 = 37;
        v8 = 35;
        break;
      case 1:
        v6 = v3->qindex == 0;
        v7 = 33;
        v8 = 31;
        break;
      default:
        v13 = 0;
LABEL_19:
        questionmsg = v3->questionmsg;
        nbDispNegoMessage(n, questionmsg, v13, 0);
        return 0;
    }
    if (v6)
      v13 = v8;
    else
      v13 = v7;
    goto LABEL_19;
  }
  v9 = v3->qtype;
  switch (v9)
  {
    case 3:
      v10 = v3->qindex == 0;
      v11 = 30;
      v12 = 28;
      goto LABEL_25;
    case 2:
      v10 = v3->qindex == 0;
      v11 = 38;
      v12 = 36;
LABEL_25:
      if (v10)
        v15 = v12;
      else
        v15 = v11;
      goto LABEL_29;
    case 1:
      v10 = v3->qindex == 0;
      v11 = 34;
      v12 = 32;
      goto LABEL_25;
  }
  v15 = 0;
LABEL_29:
  v16 = v3->questionmsg;
  nbDispNegoMessage(n, v16, v15, 1);
  nbAddNegoIdKouho(n, 0x70016u);
  return 0;
}

// 0xef03a0
s32 Flow7_15(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  u32 v5;
  s32 v6;
  s32 v7;
  u32 qindex;
  s32 questionmsg;
  s32 v10;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    qindex = v3->qindex;
    questionmsg = v3->questionmsg;
    if (qindex >= 5)
      v10 = 0;
    else
      v10 = 6 * qindex + 42;
    nbDispNegoMessage(n, questionmsg, v10, 1);
    nbAddNegoIdKouho(n, 0x70014u);
  }
  else if (!nownegophase)
  {
    v5 = v3->qindex;
    v6 = v3->questionmsg;
    if (v5 >= 5)
      v7 = 0;
    else
      v7 = 6 * v5 + 41;
    nbDispNegoMessage(n, v6, v7, 0);
  }
  return 0;
}

// 0xef04e0
s32 Flow7_20(nbNegoProcessData_t **n) {
  struct datNegoNormalQuesInfo_t_array_array *datNegoNormalQuesInfo;
  nbNegoProcessData_t_o *v6;
  s64 ekucyo;
  datNegoNormalQuesInfo_t_array *v9;
  s64 v10;
  s32 type;
  struct datNegoNormalQuesInfo_t_array_array *v13;
  s64 v14;
  datNegoNormalQuesInfo_t_array *v16;
  s64 v17;
  Il2CppClass **v19;
  s64 v20;
  s32 v21;
  struct datNegoNormalQuesInfo_t_array_array *v22;
  datNegoNormalQuesInfo_t_array *v24;
  s64 v25;
  s32 ritu2;
  datUnitWork_t_o *pwork;
  s32 Param;
  s32 v30;
  s32 nowselect;
  s32 v32;
  signed s32 RandIntA;
  nbNegoProcessData_t_o *v34;
  u32 *nextkouho;
  u32 v36;
  u32 *v38;

  nbAddNegoIdKouho(n, 0x70017u);
  nbAddNegoIdKouho(n, 0x70018u);
  v6 = *n;
  ekucyo = (*n)->ekucyo;
  v9 = datNegoNormalQuesInfo->m_Items[ekucyo];
  v10 = v6->qindex + 2LL;
  type = v9->m_Items[v10]->type;
  v13 = datNegoNormalQuesInfo;
  v14 = v6->ekucyo;
  v16 = v13->m_Items[v14];
  v17 = v6->qindex + 2LL;
  v19 = &v16->obj.klass + v17;
  v20 = v6->ekucyo;
  v21 = BYTE2(v19[4]->_1.name);
  v22 = datNegoNormalQuesInfo;
  v24 = v22->m_Items[v20];
  v25 = v6->qindex + 2LL;
  ritu2 = v24->m_Items[v25]->ritu2;
  if (type == 1)
  {
    nowselect = (*n)->nowselect;
    if ((*n)->pwork->level >= (*n)->ework->level)
    {
LABEL_30:
      if (nowselect)
        v32 = 100 - v21;
      else
        v32 = v21;
      goto LABEL_38;
    }
  }
  else
  {
    if (type)
    {
      v32 = 50;
      goto LABEL_38;
    }
    pwork = (*n)->pwork;
    Param = datGetParam(pwork, 1);
    v30 = datGetParam((*n)->ework, 1, 0);
    nowselect = (*n)->nowselect;
    if (Param >= v30)
      goto LABEL_30;
  }
  if (nowselect)
    v32 = 100 - ritu2;
  else
    v32 = ritu2;
LABEL_38:
  RandIntA = dds3GetRandIntA(0x64u, "7_20");
  v34 = *n;
  nextkouho = v34->nextkouho;
  v36 = nextkouho[6];
  if (RandIntA >= v32)
  {
    v38 = nextkouho + 9;
  }
  else
  {
    v38 = nextkouho + 8;
  }
  v34->nextnegoid = *v38;
  return 0;
}

// 0xef0840
s32 Flow7_22(nbNegoProcessData_t **n) {
  datUnitWork_t_o *pwork;
  s32 Param;
  s32 v7;
  nbNegoProcessData_t_o *v8;
  s32 aisyo;
  s32 v10;
  s32 qtype;
  struct System_Byte_array_array_array_array *v13;
  s64 v14;
  System_Byte_array_array_array *v16;
  s64 v17;
  s64 v19;
  s64 v20;
  s64 v21;
  s64 v23;
  struct System_Byte_array_array_array_array *v25;
  nbNegoProcessData_t_o *v26;
  s64 v27;
  s32 v28;
  System_Byte_array_array_array *v30;
  s64 v31;
  struct System_Byte_array_array_array_array *datNegoKotowariQuesInfo;
  s64 ekucyo;
  System_Byte_array_array_array *v36;
  s64 v37;
  s64 v39;
  s64 nowselect;
  s64 v41;
  s64 v43;
  struct System_Byte_array_array_array_array *v45;
  s64 v46;
  Il2CppClass **v49;
  s64 v50;
  Il2CppClass *v51;
  struct System_Byte_array_array_array_array *v55;
  s64 v56;
  System_Byte_array_array_array *v58;
  s64 v59;
  s64 v61;
  s64 v62;
  s64 v63;
  s64 v65;
  struct System_Byte_array_array_array_array *v67;
  s64 v68;
  signed s32 RandIntA;
  nbNegoProcessData_t_o *v71;
  u32 *nextkouho;
  u32 v73;
  u32 *v75;

  nbAddNegoIdKouho(n, 0x70019u);
  nbAddNegoIdKouho(n, 0x7001Au);
  pwork = (*n)->pwork;
  Param = datGetParam(pwork, 1);
  if (datGetParam((*n)->ework, 1, 0) <= Param)
    v7 = 70;
  else
    v7 = 30;
  v8 = *n;
  aisyo = (*n)->aisyo;
  if (aisyo == 2)
    v7 = 20;
  if (aisyo == 1)
    v10 = 80;
  else
    v10 = v7;
  qtype = v8->qtype;
  if (qtype == 3)
  {
    ekucyo = v8->ekucyo;
    v36 = datNegoKotowariQuesInfo->m_Items[ekucyo];
    v37 = v8->qindex + 3LL;
    v39 = v36 + 8 * v37;
    nowselect = v8->nowselect;
    v41 = *(v39 + 32);
    v43 = *(v41 + 8 * nowselect + 32);
    v45 = datNegoKotowariQuesInfo;
    v26 = *n;
    v46 = (*n)->ekucyo;
    v28 = *(v43 + 32);
    v30 = v45->m_Items[v46];
    v31 = v26->qindex + 3LL;
    if (v31 < LODWORD(v30->max_length))
      goto LABEL_53;
    goto LABEL_52;
  }
  if (qtype == 2)
  {
    v55 = datNegoKotowariQuesInfo;
    v56 = v8->ekucyo;
    v58 = v55->m_Items[v56];
    v59 = v8->qindex + 7LL;
    v61 = v58 + 8 * v59;
    v62 = v8->nowselect;
    v63 = *(v61 + 32);
    v65 = *(v63 + 8 * v62 + 32);
    v67 = datNegoKotowariQuesInfo;
    v26 = *n;
    v68 = (*n)->ekucyo;
    v28 = *(v65 + 32);
    v30 = v67->m_Items[v68];
    v31 = v26->qindex + 7LL;
    if (v31 < LODWORD(v30->max_length))
      goto LABEL_53;
LABEL_52:
  }
  if (qtype != 1)
  {
    v28 = 0;
    goto LABEL_73;
  }
  v13 = datNegoKotowariQuesInfo;
  v14 = v8->ekucyo;
  v16 = v13->m_Items[v14];
  v17 = v8->qindex + 5LL;
  v19 = v16 + 8 * v17;
  v20 = v8->nowselect;
  v21 = *(v19 + 32);
  v23 = *(v21 + 8 * v20 + 32);
  v25 = datNegoKotowariQuesInfo;
  v26 = *n;
  v27 = (*n)->ekucyo;
  v28 = *(v23 + 32);
  v30 = v25->m_Items[v27];
  v31 = v26->qindex + 5LL;
  if (v31 >= LODWORD(v30->max_length))
    goto LABEL_52;
LABEL_53:
  v49 = &v30->obj.klass + v31;
  v50 = v26->nowselect;
  v51 = v49[4];
LABEL_73:
  if (((*n)->qtype - 1) <= 2)
  {
    datAddKotowariPoint(v28, 1);
  }
  RandIntA = dds3GetRandIntA(0x64u, "7_22");
  v71 = *n;
  nextkouho = v71->nextkouho;
  v73 = nextkouho[6];
  if (RandIntA >= v10)
  {
    v75 = nextkouho + 9;
  }
  else
  {
    v75 = nextkouho + 8;
  }
  v71->nextnegoid = *v75;
  return 0;
}

// 0xef0e30
s32 Flow7_23(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_UInt32_array *workid;
  u32 v7;
  nbNegoProcessData_t_o *v9;
  bool v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 questionmsg;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    workid = v3->workid;
    v7 = workid->m_Items[4];
    nbAddNegoIdKouho(n, v7);
    v9 = *n;
    switch ((*n)->qindex)
    {
      case 0:
        v10 = v9->nowselect == 0;
        v11 = 45;
        v12 = 43;
        goto LABEL_23;
      case 1:
        v10 = v9->nowselect == 0;
        v11 = 51;
        v12 = 49;
        goto LABEL_23;
      case 2:
        v10 = v9->nowselect == 0;
        v11 = 57;
        v12 = 55;
        goto LABEL_23;
      case 3:
        v10 = v9->nowselect == 0;
        v11 = 63;
        v12 = 61;
        goto LABEL_23;
      case 4:
        v10 = v9->nowselect == 0;
        v11 = 69;
        v12 = 67;
LABEL_23:
        if (v10)
          v13 = v12;
        else
          v13 = v11;
        questionmsg = v9->questionmsg;
          goto LABEL_27;
        goto LABEL_17;
      default:
        v13 = 0;
        questionmsg = v9->questionmsg;
        {
LABEL_17:
        }
LABEL_27:
        nbDispNegoMessage(n, questionmsg, v13, 0);
        break;
    }
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0xef1000
s32 Flow7_24(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_UInt32_array *workid;
  u32 v7;
  struct System_UInt32_array *v9;
  nbNegoProcessData_t_o *v11;
  bool v12;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 questionmsg;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    workid = v3->workid;
    v7 = workid->m_Items[5];
    nbAddNegoIdKouho(n, v7);
    v9 = (*n)->workid;
    v9->m_Items[2] = 393285;
    v11 = *n;
    switch ((*n)->qindex)
    {
      case 0:
        v12 = v11->nowselect == 0;
        v13 = 46;
        v14 = 44;
        goto LABEL_28;
      case 1:
        v12 = v11->nowselect == 0;
        v13 = 52;
        v14 = 50;
        goto LABEL_28;
      case 2:
        v12 = v11->nowselect == 0;
        v13 = 58;
        v14 = 56;
        goto LABEL_28;
      case 3:
        v12 = v11->nowselect == 0;
        v13 = 64;
        v14 = 62;
        goto LABEL_28;
      case 4:
        v12 = v11->nowselect == 0;
        v13 = 70;
        v14 = 68;
LABEL_28:
        if (v12)
          v15 = v14;
        else
          v15 = v13;
        questionmsg = v11->questionmsg;
          goto LABEL_32;
        goto LABEL_22;
      default:
        v15 = 0;
        questionmsg = v11->questionmsg;
        {
LABEL_22:
        }
LABEL_32:
        nbDispNegoMessage(n, questionmsg, v15, 0);
        break;
    }
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0xef1220
s32 Flow7_25(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_UInt32_array *workid;
  u32 v7;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    workid = v3->workid;
    v7 = workid->m_Items[4];
    nbAddNegoIdKouho(n, v7);
    nbDispNegoMessage(n, (*n)->questionmsg, 39, 0, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0xef1330
s32 Flow7_26(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_UInt32_array *workid;
  u32 v7;
  struct System_UInt32_array *v9;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    workid = v3->workid;
    v7 = workid->m_Items[5];
    nbAddNegoIdKouho(n, v7);
    v9 = (*n)->workid;
    v9->m_Items[2] = 393285;
    nbDispNegoMessage(n, (*n)->questionmsg, 40, 0, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0xeeff70
s32 Flow7_3(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  struct System_Byte_array *negoques;
  s64 qtype;
  struct System_Byte_array *v10;
  s64 v11;
  nbNegoProcessData_t_o *v13;
  nbNegoProcessData_t_o *v14;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  struct System_UInt32_array *v18;

  nbAddNegoIdKouho(n, 0x7000Fu);
  nbAddNegoIdKouho(n, 0x7000Bu);
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
  v13 = *n;
  if ((*n)->qtype)
  {
    v13->qindex = dds3GetRandIntA(2u, "7_3");
    v14 = *n;
    nextkouho = v14->nextkouho;
    m_Items = &nextkouho->m_Items[1];
  }
  else
  {
    v13->qindex = dds3GetRandIntA(5u, "7_3");
    v14 = *n;
    v18 = v14->nextkouho;
    m_Items = v18->m_Items;
  }
  v14->nextnegoid = *m_Items;
  return 0;
}

// 0xeefeb0
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0xeefec0
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0xef1490
s32 nbNegoFlowQuestion(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowQuestion_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
