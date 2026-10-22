#include "types.h"

typedef struct NbNegoFlowNg_procfuncDelegate NbNegoFlowNg_procfuncDelegate;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;

static NbNegoFlowNg_procfuncDelegate *procfunc[34];

void datAddItem(s32 id, s32 num);
void datAddMaka(s32 addmaka);
s32 datCheckItemFull(s32 id);
s32 datGetAisyoFlag(datUnitWork_t *work, s32 attr);
s32 datGetRace(datUnitWork_t *work);
u32 dds3GetRandIntA(u32 aLimit, char *name);
bool evtBitCheck(s32 no);
nbKoukaPacket_t *nbAddHitEffKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type);
nbKoukaPacket_t *nbAddMojiEffKoukaPacket(s32 startframe, s32 frame, s32 uniqueid, nbFormation_t **form, s32 type);
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbCameraSetTaizi(nbFormation_t **pInvokeForm, nbFormation_t **pTargetForm);
void nbCameraSetTarget(nbFormation_t **pTargetForm);
void nbClsNegoMessage(nbNegoProcessData_t **n);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);
s32 nbGetHojoSkillWorkCnt(nbNegoProcessData_t **n);
s32 nbGetNegoYaruItemB(datUnitWork_t **w);
s32 nbGetNegoYaruMakkaB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
s32 nbMakeBadDamagePacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 bad);
s32 nbMakeKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type, s32 hp, s32 mp, u32 badstat);
void nbPanelDraw(s32 flag);
u32 nbSearchHojoSkillWork(nbNegoProcessData_t **n, s32 type);
void nbSetMesItem(s32 msgid, s32 it);
void nbSetMesMakka(s32 msgid, s32 i);
s32 nbSetNegoNoMotion(nbNegoProcessData_t **n, nbFormation_t **form);

// 0x5429d0
s32 CheckSkillShinoKeiyaku(nbNegoProcessData_t **n) {
  return (*n)->negoskillid == 395 && (*n)->pwork->hp != 0;
}

// 0x542a00
s32 Flow10_1(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  u32 v5;
  bool v6;
  s64 v7;
  bool v9;
  u32 RandIntA;
  struct System_UInt32_array *nextkouho;
  u32 max_length;
  u32 *v14;
  struct System_UInt32_array *v15;
  u32 v16;
  datUnitWork_t_o *ework;

  nbAddNegoIdKouho(n, 0xA0002u);
  nbAddNegoIdKouho(n, 0xA000Bu);
  nbAddNegoIdKouho(n, 0x6002Bu);
  v4 = *n;
  v5 = (*n)->ework->id - 61;
  v6 = v5 > 0x24;
  v7 = (1LL << v5) & 0x1080000001LL;
  if (!v6 && v7 != 0)
  {
    v9 = evtBitCheck(8);
    v4 = *n;
    if (!v9 && !v4->negoreqtype)
      goto LABEL_33;
  }
  if (v4->cnt6_37)
  {
    RandIntA = dds3GetRandIntA(0xAu, "10_1");
    v4 = *n;
    nextkouho = (*n)->nextkouho;
    max_length = nextkouho->max_length;
    if (RandIntA <= 5)
    {
      v14 = &nextkouho->m_Items[2];
LABEL_37:
      v4->nextnegoid = *v14;
      return 0;
    }
LABEL_34:
    v14 = &nextkouho->m_Items[1];
    goto LABEL_37;
  }
  v15 = v4->nextkouho;
  v16 = dds3GetRandIntA(2u, "10_1");
  v4->nextnegoid = v15->m_Items[v16];
  ework = (*n)->ework;
  if (datGetRace(ework) == 33)
  {
    v4 = *n;
LABEL_33:
    nextkouho = v4->nextkouho;
    max_length = nextkouho->max_length;
    goto LABEL_34;
  }
  return 0;
}

// 0x543b80
s32 Flow10_10(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  nbNegoProcessData_t_o *v6;
  struct System_Int32_array *aisyomsg;
  s64 ekucyo;
  char *v10;
  s32 hojoaisyomes;
  s32 v12;
  nbNegoProcessData_t_o **v13;
  s32 v14;
  s32 v15;
  struct System_Int32_array *flowmsg;
  s64 v17;
  s32 v19;

  nbAddNegoIdKouho(n, 0x6004Au);
  workid = (*n)->workid;
  workid->m_Items[6] = 393225;
  (*n)->cnt6_36 = 0;
  (*n)->cnt6_37 = 0;
  v6 = *n;
  if ((*n)->hojoaisyo == 1)
  {
    aisyomsg = v6->aisyomsg;
    ekucyo = v6->ekucyo;
    v10 = aisyomsg + 4 * ekucyo;
    hojoaisyomes = v6->hojoaisyomes;
    v12 = *(v10 + 8);
    v13 = n;
    v14 = v12;
    v15 = hojoaisyomes;
  }
  else
  {
    flowmsg = v6->flowmsg;
    v17 = v6->ekucyo;
    v19 = flowmsg->m_Items[v17];
    v15 = 217;
    v13 = n;
    v14 = v19;
  }
  nbDispNegoMessage(v13, v14, v15, 0);
  return 0;
}

// 0x543d30
s32 Flow10_11(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0xA000Cu);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 224, 0);
  return 0;
}

// 0x543e20
s32 Flow10_12(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  s32 aisyo;
  s32 v6;
  s32 v7;
  signed s32 RandIntA;
  struct System_UInt32_array *nextkouho;
  u32 max_length;
  u32 *m_Items;

  nbAddNegoIdKouho(n, 0xA000Du);
  nbAddNegoIdKouho(n, 0xA0015u);
  v4 = *n;
  aisyo = (*n)->aisyo;
  if (aisyo == 2)
    v6 = 0;
  else
    v6 = 40;
  if (aisyo == 1)
    v7 = 70;
  else
    v7 = v6;
  if (v4->cnt6_36)
  {
    RandIntA = dds3GetRandIntA(0x64u, "10_12");
    v4 = *n;
    nextkouho = (*n)->nextkouho;
    max_length = nextkouho->max_length;
    if (RandIntA < v7)
    {
      m_Items = nextkouho->m_Items;
      goto LABEL_27;
    }
  }
  else
  {
    nextkouho = v4->nextkouho;
    max_length = nextkouho->max_length;
  }
  m_Items = &nextkouho->m_Items[1];
LABEL_27:
  v4->nextnegoid = *m_Items;
  return 0;
}

// 0x543f90
s32 Flow10_13(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  struct System_UInt32_array *nextkouho;
  u32 RandIntA;

  nbAddNegoIdKouho(n, 0xA0010u);
  nbAddNegoIdKouho(n, 0xA0010u);
  nbAddNegoIdKouho(n, 0xA0011u);
  v4 = *n;
  nextkouho = v4->nextkouho;
  RandIntA = dds3GetRandIntA(3u, "10_13");
  v4->nextnegoid = nextkouho->m_Items[RandIntA];
  return 0;
}

// 0x5440c0
s32 Flow10_15(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  nbFormation_t_o **p_eform;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  struct System_Int32_array *v9;
  s64 v10;

  nbAddNegoIdKouho(n, 0xA0012u);
  v3 = *n;
  v3->getmakka = nbGetNegoYaruMakkaB(n, &(*n)->pwork, &(*n)->ework, 0);
  p_eform = &(*n)->eform;
  nbCameraSetTarget(p_eform);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbSetMesMakka(flowmsg->m_Items[ekucyo], (*n)->getmakka, 0);
  v9 = (*n)->flowmsg;
  v10 = (*n)->ekucyo;
  nbDispNegoMessage(n, v9->m_Items[v10], 226, 0);
  return 0;
}

// 0x544240
s32 Flow10_16(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 getitem;
  s32 v6;
  nbNegoProcessData_t_o *v8;
  struct System_UInt32_array *nextkouho;
  u32 max_length;
  nbFormation_t_o **p_eform;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  char *v18;
  s32 v19;
  s32 v20;
  struct System_Int32_array *v21;
  s64 v22;

  nbAddNegoIdKouho(n, 0xA0013u);
  nbAddNegoIdKouho(n, 0xA0011u);
  v3 = *n;
  v3->getitem = nbGetNegoYaruItemB(&(*n)->ework, 0);
  getitem = (*n)->getitem;
  if (!getitem)
  {
    (*n)->getitem = 36;
    getitem = (*n)->getitem;
  }
  v6 = datCheckItemFull(getitem);
  v8 = *n;
  nextkouho = (*n)->nextkouho;
  max_length = nextkouho->max_length;
  if (v6)
  {
    v8->nextnegoid = nextkouho->m_Items[1];
  }
  else
  {
    v8->nextnegoid = nextkouho->m_Items[0];
    p_eform = &(*n)->eform;
    nbCameraSetTarget(p_eform);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    v18 = flowmsg + 4 * ekucyo;
    v19 = (*n)->getitem;
    v20 = *(v18 + 8);
    nbSetMesItem(v20, v19);
    v21 = (*n)->flowmsg;
    v22 = (*n)->ekucyo;
    nbDispNegoMessage(n, v21->m_Items[v22], 225, 0);
  }
  return 0;
}

// 0x544480
s32 Flow10_17(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0xA0014u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 227, 0);
  return 0;
}

// 0x544570
s32 Flow10_18(nbNegoProcessData_t **n) {
  s32 getmakka;

  nbAddNegoIdKouho(n, 0xA001Eu);
  getmakka = (*n)->getmakka;
  datAddMaka(getmakka);
  return 0;
}

// 0x544640
s32 Flow10_19(nbNegoProcessData_t **n) {
  s32 getitem;

  nbAddNegoIdKouho(n, 0xA001Fu);
  getitem = (*n)->getitem;
  datAddItem(getitem, 1);
  return 0;
}

// 0x542c60
s32 Flow10_2(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  u32 RandIntA;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xA0003u);
    RandIntA = dds3GetRandIntA(2u, "10_2");
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], RandIntA + 215, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0x544710
s32 Flow10_20(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xA0020u);
  nbClsNegoMessage(n);
  nbPanelDraw(1);
  nbMakeKaifukuPacket(0, 0, &(*n)->pform, 0, (*n)->pwork->maxhp, -1, 0, 0);
  nbAddHitEffKoukaPacket(0, 0, &(*n)->pform, 8, 0);
  (*n)->waitframe = 0;
  return 0;
}

// 0x544830
s32 Flow10_21(nbNegoProcessData_t **n) {
  u32 v4;
  bool v5;
  s64 v6;
  bool v7;
  u32 RandIntA;
  nbNegoProcessData_t_o *v9;
  u32 *nextkouho;
  u32 v11;
  u32 *v13;

  nbAddNegoIdKouho(n, 0xA0018u);
  nbAddNegoIdKouho(n, 0xA001Cu);
  v4 = (*n)->ework->id - 61;
  v5 = v4 > 0x24;
  v6 = (1LL << v4) & 0x1080000001LL;
  v7 = v5 || v6 == 0;
  if (v7 || evtBitCheck(8))
  {
    RandIntA = dds3GetRandIntA(0xAu, "10_21");
    v9 = *n;
    nextkouho = v9->nextkouho;
    v11 = nextkouho[6];
    if (RandIntA >= 5)
    {
      v13 = nextkouho + 8;
      goto LABEL_25;
    }
  }
  else
  {
    v9 = *n;
    nextkouho = v9->nextkouho;
    v11 = nextkouho[6];
  }
  v13 = nextkouho + 9;
LABEL_25:
  v9->nextnegoid = *v13;
  return 0;
}

// 0x5449c0
s32 Flow10_22(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0xA0017u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 234, 0);
  return 0;
}

// 0x544ab0
s32 Flow10_23(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xA001Du);
  nbDispNegoMessage(n, (*n)->helpmsg, 1, 0, 0);
  return 0;
}

// 0x544b70
s32 Flow10_24(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 negoreqtype;
  struct System_UInt32_array *v5;
  u32 *m_Items;
  struct System_UInt32_array *v9;
  struct System_UInt32_array *nextkouho;

  nbAddNegoIdKouho(n, 0xA0019u);
  nbAddNegoIdKouho(n, 0xA001Au);
  nbAddNegoIdKouho(n, 0xA001Bu);
  v3 = *n;
  negoreqtype = v3->negoreqtype;
  if ((negoreqtype - 1) >= 5)
  {
    if (negoreqtype == 6)
    {
      nextkouho = v3->nextkouho;
      m_Items = &nextkouho->m_Items[2];
    }
    else
    {
      if (negoreqtype)
        return 0;
      v9 = v3->nextkouho;
      m_Items = &v9->m_Items[1];
    }
  }
  else
  {
    v5 = v3->nextkouho;
    m_Items = v5->m_Items;
  }
  v3->nextnegoid = *m_Items;
  return 0;
}

// 0x544cd0
s32 Flow10_25(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 v4;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v8;
  nbNegoProcessData_t_o *v10;
  struct System_Int32_array *temp_param;

  v3 = *n;
  v4 = 230;
  switch ((*n)->negoreqtype)
  {
    case 1:
    case 5:
      break;
    case 2:
      if (dds3GetRandIntA(2u, "10_25"))
        v4 = 232;
      else
        v4 = 230;
      v3 = *n;
      break;
    case 3:
      v4 = 231;
      break;
    case 4:
      v4 = 232;
      break;
    default:
      v4 = 0;
      break;
  }
  flowmsg = v3->flowmsg;
  ekucyo = v3->ekucyo;
  v8 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v8, v4, 0);
  v10 = *n;
  if ((*n)->negoskillid != 395)
    return 1;
LABEL_22:
  if (!v10->pwork->hp)
    return 1;
  nbAddNegoIdKouho(n, 0xA0021u);
  temp_param = (*n)->temp_param;
  temp_param->m_Items[0] = 1;
  return 0;
}

// 0x544ef0
s32 Flow10_26(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v6;
  nbNegoProcessData_t_o *v8;
  struct System_Int32_array *temp_param;

  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v6 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v6, 229, 0);
  v8 = *n;
  if ((*n)->negoskillid != 395)
    return 1;
LABEL_11:
  if (!v8->pwork->hp)
    return 1;
  else
  {
      goto LABEL_15;
  }
  nbAddNegoIdKouho(n, 0xA0021u);
  temp_param = (*n)->temp_param;
  temp_param->m_Items[0] = 1;
  return 0;
}

// 0x5450a0
s32 Flow10_27(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v6;
  nbNegoProcessData_t_o *v8;
  struct System_Int32_array *temp_param;

  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v6 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v6, 233, 0);
  v8 = *n;
  if ((*n)->negoskillid != 395)
    return 1;
LABEL_11:
  if (!v8->pwork->hp)
    return 1;
  else
  {
      goto LABEL_15;
  }
  nbAddNegoIdKouho(n, 0xA0021u);
  temp_param = (*n)->temp_param;
  temp_param->m_Items[0] = 1;
  return 0;
}

// 0x545250
s32 Flow10_28(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0xA0017u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 228, 0);
  return 0;
}

// 0x545340
s32 Flow10_29(nbNegoProcessData_t **n) {
  return 2;
}

// 0x542dd0
s32 Flow10_3(nbNegoProcessData_t **n) {
  s32 HojoSkillWorkCnt;
  nbNegoProcessData_t_o *v4;
  u32 *nextkouho;
  u32 v6;
  u32 *v8;

  nbAddNegoIdKouho(n, 0xA0006u);
  nbAddNegoIdKouho(n, 0xA0004u);
  HojoSkillWorkCnt = nbGetHojoSkillWorkCnt(n);
  v4 = *n;
  nextkouho = v4->nextkouho;
  v6 = nextkouho[6];
  if (HojoSkillWorkCnt < 1)
  {
    v8 = nextkouho + 8;
  }
  else
  {
    v8 = nextkouho + 9;
  }
  v4->nextnegoid = *v8;
  return 0;
}

// 0x545350
s32 Flow10_30(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xA0016u);
  nbSetMesMakka((*n)->helpmsg, (*n)->getmakka, 0);
  nbDispNegoMessage(n, (*n)->helpmsg, 3, 0, 0);
  return 0;
}

// 0x545420
s32 Flow10_31(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xA0016u);
  nbSetMesItem((*n)->helpmsg, (*n)->getitem, 0);
  nbDispNegoMessage(n, (*n)->helpmsg, 5, 0, 0);
  return 0;
}

// 0x5454f0
s32 Flow10_32(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xA0016u);
  nbDispNegoMessage(n, (*n)->helpmsg2, 7, 0, 0);
  nbPanelDraw(0);
  (*n)->waitframe = 60;
  return 0;
}

// 0x5438f0
s32 Flow10_33(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  nbFormation_t_o **p_pform;
  nbFormation_t_o **p_eform;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v10;
  datUnitWork_t_o *ework;
  s32 AisyoFlag;
  nbFormation_t_o **v13;
  struct System_Int32_array *temp_param;
  nbFormation_t_o **v16;
  s32 v17;

  v3 = *n;
  switch ((*n)->nownegophase)
  {
    case 0:
      p_pform = &v3->pform;
      p_eform = &v3->eform;
      nbCameraSetTaizi(p_pform, p_eform);
      return 0;
    case 1:
      flowmsg = v3->flowmsg;
      ekucyo = v3->ekucyo;
      v10 = flowmsg->m_Items[ekucyo];
      nbDispNegoMessage(n, v10, 290, 0);
      return 0;
    case 2:
      ework = v3->ework;
      AisyoFlag = datGetAisyoFlag(ework, 7);
      if ((AisyoFlag & 0x20000) != 0)
      {
        v16 = &(*n)->eform;
        v17 = 1;
      }
      else if ((AisyoFlag & 0x40000) != 0)
      {
        v16 = &(*n)->eform;
        v17 = 2;
      }
      else
      {
        v13 = &(*n)->eform;
        if ((*&AisyoFlag & 0x110000LL) != 0)
        {
          nbAddHitEffKoukaPacket(0, 0, v13, 3);
          nbAddMojiEffKoukaPacket(0, 45, 0, &(*n)->eform, 4, 0);
          return 0;
        }
        nbMakeBadDamagePacket(0, 0, v13, 0x400u);
        v16 = &(*n)->eform;
        v17 = 10;
      }
      nbAddHitEffKoukaPacket(0, 0, v16, v17);
      return 0;
    case 3:
      v3->waitframe = 45;
      return 0;
    case 4:
      temp_param = v3->temp_param;
      return temp_param->m_Items[0];
    default:
      return 0;
  }
}

// 0x542ee0
s32 Flow10_4(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_UInt32_array *v5;
  u32 v7;
  nbNegoProcessData_t_o *v8;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  struct System_UInt32_array *v12;

  nbAddNegoIdKouho(n, 0x60034u);
  nbAddNegoIdKouho(n, 0xA0006u);
  workid = (*n)->workid;
  workid->m_Items[0] = 655370;
  v5 = (*n)->workid;
  v5->m_Items[1] = 655365;
  v7 = nbSearchHojoSkillWork(n, 1);
  v8 = *n;
  if (v7)
  {
    v8->hojopartyindex = HIWORD(v7);
    (*n)->hojoskillid = v7;
    v8 = *n;
    nextkouho = (*n)->nextkouho;
    m_Items = nextkouho->m_Items;
  }
  else
  {
    v12 = v8->nextkouho;
    m_Items = &v12->m_Items[1];
  }
  v8->nextnegoid = *m_Items;
  return 0;
}

// 0x543070
s32 Flow10_5(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  nbFormation_t_o **p_eform;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0xA0006u);
    p_eform = &(*n)->eform;
    nbCameraSetTarget(p_eform);
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 218, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0x5431e0
s32 Flow10_6(nbNegoProcessData_t **n) {
  nbFormation_t_o **p_eform;
  nbNegoProcessData_t_o *v5;
  s32 negoreqtype;
  struct System_UInt32_array *v7;
  u32 *m_Items;
  struct System_UInt32_array *v11;
  struct System_UInt32_array *nextkouho;

  nbAddNegoIdKouho(n, 0xA0007u);
  nbAddNegoIdKouho(n, 0xA0008u);
  nbAddNegoIdKouho(n, 0xA0009u);
  p_eform = &(*n)->eform;
  nbCameraSetTarget(p_eform);
  v5 = *n;
  negoreqtype = v5->negoreqtype;
  if ((negoreqtype - 1) >= 5)
  {
    if (negoreqtype == 6)
    {
      nextkouho = v5->nextkouho;
      m_Items = &nextkouho->m_Items[2];
    }
    else
    {
      if (negoreqtype)
        return 0;
      v11 = v5->nextkouho;
      m_Items = &v11->m_Items[1];
    }
  }
  else
  {
    v7 = v5->nextkouho;
    m_Items = v7->m_Items;
  }
  v5->nextnegoid = *m_Items;
  return 0;
}

// 0x543370
s32 Flow10_7(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 v4;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v8;
  nbNegoProcessData_t_o *v10;
  struct System_Int32_array *temp_param;

  v3 = *n;
  v4 = 220;
  switch ((*n)->negoreqtype)
  {
    case 1:
    case 5:
      break;
    case 2:
      if (dds3GetRandIntA(2u, "10_7"))
        v4 = 222;
      else
        v4 = 220;
      v3 = *n;
      break;
    case 3:
      v4 = 221;
      break;
    case 4:
      v4 = 222;
      break;
    default:
      v4 = 0;
      break;
  }
  flowmsg = v3->flowmsg;
  ekucyo = v3->ekucyo;
  v8 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v8, v4, 0);
  v10 = *n;
  if ((*n)->negoskillid != 395)
    return 4;
LABEL_22:
  if (!v10->pwork->hp)
    return 4;
  nbAddNegoIdKouho(n, 0xA0021u);
  temp_param = (*n)->temp_param;
  temp_param->m_Items[0] = 4;
  return 0;
}

// 0x543590
s32 Flow10_8(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v6;
  nbNegoProcessData_t_o *v8;
  struct System_Int32_array *temp_param;

  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v6 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v6, 219, 0);
  v8 = *n;
  if ((*n)->negoskillid != 395)
    return 4;
LABEL_11:
  if (!v8->pwork->hp)
    return 4;
  else
  {
      goto LABEL_15;
  }
  nbAddNegoIdKouho(n, 0xA0021u);
  temp_param = (*n)->temp_param;
  temp_param->m_Items[0] = 4;
  return 0;
}

// 0x543740
s32 Flow10_9(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v6;
  nbNegoProcessData_t_o *v8;
  struct System_Int32_array *temp_param;

  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v6 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v6, 223, 0);
  v8 = *n;
  if ((*n)->negoskillid != 395)
    return 4;
LABEL_11:
  if (!v8->pwork->hp)
    return 4;
  else
  {
      goto LABEL_15;
  }
  nbAddNegoIdKouho(n, 0xA0021u);
  temp_param = (*n)->temp_param;
  temp_param->m_Items[0] = 4;
  return 0;
}

// 0x5429b0
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0x5429c0
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0x5455e0
s32 nbNegoFlowNg(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowNg_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
