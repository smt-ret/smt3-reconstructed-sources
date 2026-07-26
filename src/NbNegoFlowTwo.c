#include "types.h"

typedef struct NbNegoFlowTwo_procfuncDelegate NbNegoFlowTwo_procfuncDelegate;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;
typedef struct nbParty_t nbParty_t;

static NbNegoFlowTwo_procfuncDelegate *procfunc[82];

s32 ChkAisyo(datUnitWork_t **a, datUnitWork_t **b, u32 jo, s32 sw);
u8 Get(s32 id);
void datAddItem(s32 id, s32 num);
void datAddMaka(s32 addmaka);
s32 datCheckDying(datUnitWork_t *work);
s32 datCheckItem(s32 id, s32 num);
s32 datCheckMaka(s32 maka);
s32 datCheckStockFull(void);
s32 datCheckSyojiSkill(datUnitWork_t *work, u32 skill);
s32 datGetParam(datUnitWork_t *work, s32 paratype);
s32 datGetRace(datUnitWork_t *work);
u32 dds3GetRandIntA(u32 aLimit, char *name);
bool evtBitCheck(s32 no);
s32 evtGetAgeOfMoon(void);
nbKoukaPacket_t *nbAddHomeMoveKoukaPacket(s32 startframe, s32 uniqueid, s32 partyno, f32 speed);
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id);
void nbCameraSetHojo(nbFormation_t **pHojo, nbFormation_t **pTarget1, nbFormation_t **pTarget2);
void nbCameraSetTaizi(nbFormation_t **pInvokeForm, nbFormation_t **pTargetForm);
void nbClsNegoMessage(nbNegoProcessData_t **n);
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel);
void nbDispSkillName(s32 id);
void nbFormDispOff2(nbFormation_t **form);
void nbFormDispOn2(nbFormation_t **form);
s32 nbGetHojoSkillWorkCnt(nbNegoProcessData_t **n);
s32 nbGetKureItemA(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
s32 nbGetKureItemB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
s32 nbGetNegoKureMakkaA(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
s32 nbGetNegoKureMakkaB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
s32 nbGetNegoRequestType(s32 reqtype);
s32 nbGetNegoTuikaRequestType(s32 tuikareqtype);
s32 nbGetNegoYaruMakkaA(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b);
u32 nbGetPrevNegoId(nbNegoProcessData_t **n);
datUnitWork_t *nbGetUnitWorkPointer(nbMainProcessData_t *data, nbParty_t *party);
void nbMakaDispOff(void);
void nbMakaDispOn(s32 type);
s32 nbMakeNegoBackPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, nbFormation_t **target);
s32 nbMakeNegoForwardPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, nbFormation_t **target);
s32 nbMakeNegoWorkPosPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, nbFormation_t **target);
s32 nbMakeUnitFadeInPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 col, s32 delay, s32 aframe, s32 colframe);
u32 nbSearchHojoSkillWork(nbNegoProcessData_t **n, s32 type);
void nbSetMesItem(s32 msgid, s32 it);
void nbSetMesMakka(s32 msgid, s32 i);
s32 nbSetNegoNoMotion(nbNegoProcessData_t **n, nbFormation_t **form);
s32 nbSetNegoYesMotion(nbNegoProcessData_t **n, nbFormation_t **form);

// 0xef4050
s32 ChkAisyo(datUnitWork_t **a, datUnitWork_t **b, u32 jo, s32 sw) {
  u32 v9;
  s32 v11;
  s32 v12;
  s32 id;
  s32 v14;
  u32 tokucyo;
  s32 v16;
  u32 v17;
  s32 v18;
  s32 v19;
  s32 race;
  s32 v21;
  u32 v22;
  s32 v23;
  s32 v24;
  s32 v25;

  v9 = jo ^ 0x80000000;
  if ((jo ^ 0x80000000) == 2)
  {
    if (sw)
      return 0;
    id = (*b)->id;
    return (Get(id, 0)->tokucyo & 2) != 0;
  }
  if (v9 == 1)
  {
    if ((*b)->level - 10 < (*a)->level)
      return 0;
    return dds3GetRandIntA(0x64u, StringLiteral_5342) < 70;
  }
  if (v9)
  {
    if (((*a)->flag & 4) != 0)
    {
      LOBYTE(tokucyo) = 20;
    }
    else
    {
      v14 = (*a)->id;
      tokucyo = Get(v14, 0)->tokucyo;
      if ((tokucyo & 0x20) != 0)
      {
        v16 = -1;
        while (1)
        {
          v17 = v16 + 1;
          v18 = 1 << (v16 + 1);
          if ((v18 & jo) != 0)
          {
            if (v17 > 5)
            {
              if (v17 > 7)
              {
                if (v16 == 7)
                {
                  if (((*a)->flag & 4) != 0 || ((*b)->flag & 4) != 0)
                    return 0;
                  v19 = (*a)->id;
                  race = Get(v19, 1, 0)->race;
                  if (race != Get((*b)->id, 1, 0)->race)
                    return 0;
                }
                else if (v16 == 8)
                {
                  if ((*a)->id != 143)
                    return 0;
                }
                else if (v16 == 9 && (*a)->id != 20)
                {
                  return 0;
                }
              }
              else if (v16 == 5)
              {
                if ((*b)->level + 10 > (*a)->level)
                  return 0;
              }
              else if ((*b)->level - 10 < (*a)->level)
              {
                return 0;
              }
            }
            else
            {
              if (v17 <= 3)
              {
                switch (v18)
                {
                  case 1:
                  case 3:
                  case 2:
                    if ((tokucyo & 2) == 0)
                      return 0;
                  case 4:
                    if ((tokucyo & 4) == 0)
                      return 0;
                  default:
                    if ((tokucyo & 8) != 0 || v16 != 2)
                    return 0;
                }
              }
              if (!((v16 != 3) | (tokucyo >> 4) & 1))
                return 0;
            }
          }
          v16 = v17;
          if (v17 >= 0x1E)
            return 1;
        }
      }
    }
    v21 = -1;
    while (1)
    {
      v22 = v21 + 1;
      v23 = 1 << (v21 + 1);
      if ((v23 & jo) != 0)
      {
        if (v22 >= 6)
        {
          if (v22 >= 8)
          {
            if (v21 == 7)
            {
              if (((*a)->flag & 4) != 0 || ((*b)->flag & 4) != 0)
                return 0;
              v24 = (*a)->id;
              v25 = Get(v24, 1, 0)->race;
              if (v25 != Get((*b)->id, 1, 0)->race)
                return 0;
            }
            else if (v21 == 8)
            {
              if ((*a)->id != 143)
                return 0;
            }
            else if (v21 == 9 && (*a)->id != 20)
            {
              return 0;
            }
          }
          else if (v21 == 5)
          {
            if ((*b)->level + 10 > (*a)->level)
              return 0;
          }
          else if ((*b)->level - 10 < (*a)->level)
          {
            return 0;
          }
        }
        else
        {
          if (v22 < 4)
          {
            switch (v23)
            {
              case 1:
              case 3:
              case 2:
                if ((tokucyo & 2) == 0)
                  return 0;
              case 4:
                if ((tokucyo & 4) == 0)
                  return 0;
              default:
                if ((tokucyo & 8) != 0 || v21 != 2)
                return 0;
            }
          }
          if (v21 != 3 || (tokucyo & 0x10) == 0)
            return 0;
        }
      }
      v21 = v22;
      if (v22 > 0x1D)
        return 1;
    }
  }
  if (evtGetAgeOfMoon())
    return 0;
  v11 = (*b)->id;
  v12 = 1;
  if (Get(v11, 1, 0)->race == 19)
    return 0;
  return v12;
}

// 0xef4710
s32 Flow6_1(nbNegoProcessData_t **n) {
    nbAddNegoIdKouho(0, 0);
    datCheckStockFull();
    ChkAisyo(0, 0, 0, 0);
    return 0;
}

// 0xef5c90
s32 Flow6_10(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  if ((*n)->requesttype != 4)
  {
    (*n)->requesttype = 4;
    (*n)->prevreqtype = (*n)->requesttype;
  }
  nbAddNegoIdKouho(n, 0x60046u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 66, 0);
  return 0;
}

// 0xef5da0
s32 Flow6_11(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  if ((*n)->requesttype != 3)
  {
    (*n)->requesttype = 3;
    (*n)->prevreqtype = (*n)->requesttype;
  }
  nbAddNegoIdKouho(n, 0x60046u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 65, 0);
  return 0;
}

// 0xef5eb0
s32 Flow6_12(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 level;
  s32 v6;
  s32 v7;
  signed s32 RandIntA;
  nbNegoProcessData_t_o *v9;
  u32 *nextkouho;
  u32 v11;
  u32 *v13;

  v3 = *n;
  if ((*n)->requesttype == 5
    || (v3->requesttype = 5,
        (*n)->prevreqtype = (*n)->requesttype,
        v3 = *n,
        (*n)->requesttype == 5))
  {
    v3->requestdata = nbGetNegoYaruMakkaA(n, &v3->pwork, &v3->ework);
  }
  nbAddNegoIdKouho(n, 0x6000Du);
  nbAddNegoIdKouho(n, 0x6000Eu);
  level = (*n)->pwork->level;
  v6 = (*n)->ework->level;
  if (level - 5 < v6 || level - 9 >= v6)
  {
    if (level - 10 < v6 || level - 14 >= v6)
    {
      if (level - 15 < v6 || level - 19 >= v6)
      {
        if (level - 20 < v6 || level - 24 >= v6)
        {
          if (level - 25 >= v6)
            v7 = 97;
          else
            v7 = 0;
        }
        else
        {
          v7 = 80;
        }
      }
      else
      {
        v7 = 60;
      }
    }
    else
    {
      v7 = 40;
    }
  }
  else
  {
    v7 = 20;
  }
  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_5348);
  v9 = *n;
  nextkouho = v9->nextkouho;
  v11 = nextkouho[6];
  if (RandIntA >= v7)
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

// 0xef6110
s32 Flow6_13(nbNegoProcessData_t **n) {
  struct System_UInt32_array *nextkouho;
  datUnitWork_t_o *ework;
  nbNegoProcessData_t_o *v8;
  struct System_UInt32_array *v9;

  nbAddNegoIdKouho(n, 0x60010u);
  nbAddNegoIdKouho(n, 0x6000Eu);
  nextkouho = (*n)->nextkouho;
  (*n)->nextnegoid = nextkouho->m_Items[0];
  ework = (*n)->ework;
  if (datCheckDying(ework))
  {
    if (dds3GetRandIntA(0x64u, StringLiteral_5349) <= 69)
    {
      v8 = *n;
      v9 = v8->nextkouho;
      v8->nextnegoid = v9->m_Items[1];
    }
  }
  return 0;
}

// 0xef6290
s32 Flow6_14(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  u32 PrevNegoId;
  s32 v7;
  s32 v8;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v12;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0x6000Fu);
    PrevNegoId = nbGetPrevNegoId(n);
    if (PrevNegoId == 393229)
      v7 = 69;
    else
      v7 = 0;
    if (PrevNegoId == 393228)
      v8 = 68;
    else
      v8 = v7;
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    v12 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v12, v8, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0xef6420
s32 Flow6_15(nbNegoProcessData_t **n) {
  s32 helpmsg;

  helpmsg = (*n)->helpmsg;
  nbDispNegoMessage(n, helpmsg, 1, 0);
  return 2;
}

// 0xef64b0
s32 Flow6_16(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  struct System_Int32_array *v6;
  s64 v7;

  nbAddNegoIdKouho(n, 0x60046u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbSetMesMakka(flowmsg->m_Items[ekucyo], (*n)->requestdata, 0);
  v6 = (*n)->flowmsg;
  v7 = (*n)->ekucyo;
  nbDispNegoMessage(n, v6->m_Items[v7], 67, 0);
  nbMakaDispOn(0);
  return 0;
}

// 0xef65e0
s32 Flow6_17(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  u32 requesttype;
  nbNegoProcessData_t_o *v5;
  s32 aisyo;
  struct System_UInt32_array *v7;
  u32 *m_Items;
  struct System_UInt32_array *nextkouho;
  struct System_UInt32_array *v12;

  if ((byte_3F583FA & 1) != 0)
  {
    v3 = *n;
    requesttype = (*n)->requesttype;
    if (requesttype < 2)
  }
  else
  {
    v3 = *n;
    requesttype = (*n)->requesttype;
    if (requesttype < 2)
    {
      if (requesttype != 1)
    }
  }
  (*n)->requesttype = dds3GetRandIntA(2u, StringLiteral_5350) == 0;
  (*n)->prevreqtype = (*n)->requesttype;
  v3 = *n;
  requesttype = (*n)->requesttype;
  if (requesttype != 1)
  {
    if (requesttype)
  }
  v3->requestdata = nbGetNegoKureMakkaA(n, &v3->pwork, &v3->ework);
  v3 = *n;
  if (!(*n)->requesttype)
  {
    v3->requestdata = nbGetKureItemA(n, &v3->pwork, &v3->ework);
    if (!(*n)->requestdata)
      (*n)->requestdata = 8;
  }
  nbAddNegoIdKouho(n, 0x60014u);
  nbAddNegoIdKouho(n, 0x60012u);
  nbAddNegoIdKouho(n, 0x60013u);
  v5 = *n;
  aisyo = v5->aisyo;
  switch (aisyo)
  {
    case 2:
      nextkouho = v5->nextkouho;
      m_Items = &nextkouho->m_Items[2];
    case 1:
      v12 = v5->nextkouho;
      m_Items = &v12->m_Items[1];
    case 0:
      v7 = v5->nextkouho;
      m_Items = v7->m_Items;
      v5->nextnegoid = *m_Items;
      break;
  }
  return 0;
}

// 0xef6890
s32 Flow6_18(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 requestdata;
  s32 v5;

  v3 = *n;
  if ((*n)->requesttype == 1)
  {
    requestdata = v3->requestdata;
    if (requestdata >= 0)
      v5 = requestdata;
    else
      v5 = requestdata + 1;
    v3->requestdata = v5 >> 1;
  }
  nbAddNegoIdKouho(n, 0x60014u);
  return 0;
}

// 0xef6980
s32 Flow6_19(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 requestdata;

  v3 = *n;
  if ((*n)->requesttype == 1)
  {
    requestdata = v3->requestdata;
    v3->requestdata = 2 * requestdata;
  }
  nbAddNegoIdKouho(n, 0x60014u);
  return 0;
}

// 0xef4dd0
s32 Flow6_2(nbNegoProcessData_t **n) {
  datUnitWork_t_o *pwork;
  nbNegoProcessData_t_o *v6;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  u32 RandIntA;
  nbNegoProcessData_t_o *v11;
  s32 v12;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v16;
  struct System_UInt32_array *v17;

  nbAddNegoIdKouho(n, 0x60009u);
  nbAddNegoIdKouho(n, 0x60050u);
  pwork = (*n)->pwork;
  if (datCheckSyojiSkill(pwork, 0x163u) == 1)
  {
    v6 = *n;
    nextkouho = v6->nextkouho;
    m_Items = &nextkouho->m_Items[1];
  }
  else
  {
    do
    {
      RandIntA = dds3GetRandIntA(4u, StringLiteral_5343);
      v11 = *n;
      v12 = RandIntA + 28;
    }
    while (RandIntA + 28 == (*n)->mes6_2);
    flowmsg = v11->flowmsg;
    ekucyo = v11->ekucyo;
    v16 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v16, v12, 0);
    (*n)->mes6_2 = v12;
    v6 = *n;
    v17 = v6->nextkouho;
    m_Items = v17->m_Items;
  }
  v6->nextnegoid = *m_Items;
  return 0;
}

// 0xef6a60
s32 Flow6_20(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  s32 requestdata;
  s32 v6;
  s64 v7;
  nbNegoProcessData_t_o *v8;
  s32 v9;
  s64 v10;
  s64 v11;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  char *v15;
  s32 v16;
  s32 v17;
  struct System_Int32_array *v18;
  s64 v19;
  struct System_Int32_array *v21;
  s64 v22;

  nbAddNegoIdKouho(n, 0x60046u);
  if ((*n)->requesttype == 1 && !evtBitCheck(8))
  {
    v4 = *n;
    requestdata = (*n)->requestdata;
    if (requestdata >= 0)
      v6 = requestdata;
    else
      v6 = requestdata + 1;
    v4->requestdata = v6 >> 1;
    v7 = 1717986919LL * ((*n)->requestdata + 5);
    (*n)->requestdata = 10 * ((v7 >> 34) + (v7 >> 63));
    if (!(*n)->requestdata)
      (*n)->requestdata = 1;
  }
  if ((*n)->requesttype == 1 && evtBitCheck(26) && !evtBitCheck(22))
  {
    v8 = *n;
    v9 = (*n)->requestdata;
    v8->requestdata = 8 * v9;
    v10 = 1717986919LL * (*n)->requestdata;
    (*n)->requestdata = (v10 >> 34) + (v10 >> 63);
    v11 = 1717986919LL * ((*n)->requestdata + 5);
    (*n)->requestdata = 10 * ((v11 >> 34) + (v11 >> 63));
    if (!(*n)->requestdata)
      (*n)->requestdata = 1;
  }
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v15 = flowmsg + 4 * ekucyo;
  v16 = (*n)->requestdata;
  v17 = *(v15 + 8);
  if ((*n)->requesttype == 1)
  {
    nbSetMesMakka(v17, v16);
    v18 = (*n)->flowmsg;
    v19 = (*n)->ekucyo;
    nbDispNegoMessage(n, v18->m_Items[v19], 63, 0);
    nbMakaDispOn(0);
  }
  else
  {
    nbSetMesItem(v17, v16);
    v21 = (*n)->flowmsg;
    v22 = (*n)->ekucyo;
    nbDispNegoMessage(n, v21->m_Items[v22], 64, 0);
  }
  return 0;
}

// 0xef6d80
s32 Flow6_21(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_UInt32_array *v6;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v11;
  nbNegoProcessData_t_o **v12;
  s32 v13;
  s32 v14;

  if ((*n)->requesttype != 2)
  {
    (*n)->requesttype = 2;
    (*n)->prevreqtype = (*n)->requesttype;
  }
  nbAddNegoIdKouho(n, 0x70001u);
  workid = (*n)->workid;
  workid->m_Items[4] = 393240;
  v6 = (*n)->workid;
  v6->m_Items[5] = 393281;
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  v11 = flowmsg->m_Items[ekucyo];
  if ((*n)->cnt6_37)
  {
    v12 = n;
    v13 = v11;
    v14 = 56;
  }
  else
  {
    v12 = n;
    v13 = v11;
    v14 = 62;
  }
  nbDispNegoMessage(v12, v13, v14, 0);
  return 0;
}

// 0xef73d0
s32 Flow6_22(nbNegoProcessData_t **n) {
  u32 requesttype;
  nbNegoProcessData_t_o **v4;
  nbNegoProcessData_t_o *v5;
  s32 v6;
  s32 requestdata;
  s32 v8;
  nbNegoProcessData_t_o *v10;
  struct System_UInt32_array *nextkouho;
  u32 max_length;
  s32 v14;
  s32 v15;
  s32 v16;
  nbNegoProcessData_t_o *v18;
  struct System_UInt32_array *v19;
  u32 v20;
  s32 v22;

  requesttype = (*n)->requesttype;
  if (requesttype < 2)
  {
    nbAddNegoIdKouho(n, 0x60018u);
    v4 = n;
  }
  else
  {
    if (requesttype != 5)
    nbAddNegoIdKouho(n, 0x80001u);
    v4 = n;
  }
  nbAddNegoIdKouho(v4, 0x60017u);
  v5 = *n;
  v6 = (*n)->requesttype;
  if (v6)
  {
    if (v6 == 5 || v6 == 1)
    {
      requestdata = v5->requestdata;
      v8 = datCheckMaka(requestdata);
      v10 = *n;
      nextkouho = (*n)->nextkouho;
      max_length = nextkouho->max_length;
      if (v8)
      {
        v10->nextnegoid = nextkouho->m_Items[0];
        v14 = (*n)->requestdata;
        datAddMaka(-v14);
      }
      else
      {
        v10->nextnegoid = nextkouho->m_Items[1];
      }
      nbMakaDispOff();
    }
  }
  else
  {
    v15 = v5->requestdata;
    v16 = datCheckItem(v15, 1);
    v18 = *n;
    v19 = (*n)->nextkouho;
    v20 = v19->max_length;
    if (v16)
    {
      v18->nextnegoid = v19->m_Items[0];
      v22 = (*n)->requestdata;
      datAddItem(v22, -1);
    }
    else
    {
      v18->nextnegoid = v19->m_Items[1];
    }
  }
  return 0;
}

// 0xef7690
s32 Flow6_23(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_UInt32_array *workid;
  nbNegoProcessData_t_o *v8;
  s64 requesttype;
  s32 v10;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v14;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0x60041u);
    workid = (*n)->workid;
    workid->m_Items[2] = 393285;
    v8 = *n;
    requesttype = (*n)->requesttype;
    if (requesttype > 5)
      v10 = 0;
    else
      v10 = dword_33CB478[requesttype];
    flowmsg = v8->flowmsg;
    ekucyo = v8->ekucyo;
    v14 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v14, v10, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0xef7840
s32 Flow6_24(nbNegoProcessData_t **n) {
    nbAddNegoIdKouho(0, 0);
    datGetRace(0);
    datGetParam(0, 0);
    evtBitCheck(0);
    dds3GetRandIntA(0, 0);
    nbDispNegoMessage(0, 0, 0, 0);
    return 0;
}

// 0xef8810
s32 Flow6_25(nbNegoProcessData_t **n) {
  u32 RandIntA;
  nbNegoProcessData_t_o *v5;
  s32 v6;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v10;

  nbAddNegoIdKouho(n, 0x6001Au);
  do
  {
    RandIntA = dds3GetRandIntA(4u, StringLiteral_5353);
    v5 = *n;
    v6 = RandIntA + 37;
  }
  while (RandIntA + 37 == (*n)->mes6_25);
  flowmsg = v5->flowmsg;
  ekucyo = v5->ekucyo;
  v10 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v10, v6, 0);
  (*n)->mes6_25 = v6;
  return 0;
}

// 0xef8970
s32 Flow6_26(nbNegoProcessData_t **n) {
  s32 HojoSkillWorkCnt;
  nbNegoProcessData_t_o *v4;
  u32 *nextkouho;
  u32 v6;
  u32 *v8;

  nbAddNegoIdKouho(n, 0x6001Bu);
  nbAddNegoIdKouho(n, 0x6001Cu);
  HojoSkillWorkCnt = nbGetHojoSkillWorkCnt(n);
  v4 = *n;
  nextkouho = v4->nextkouho;
  v6 = nextkouho[6];
  if (HojoSkillWorkCnt < 1)
  {
    v8 = nextkouho + 9;
  }
  else
  {
    v8 = nextkouho + 8;
  }
  v4->nextnegoid = *v8;
  return 0;
}

// 0xef8a80
s32 Flow6_27(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_UInt32_array *v5;
  u32 v7;
  nbNegoProcessData_t_o *v8;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  struct System_UInt32_array *v12;

  nbAddNegoIdKouho(n, 0x60034u);
  nbAddNegoIdKouho(n, 0x6001Cu);
  workid = (*n)->workid;
  workid->m_Items[0] = 393245;
  v5 = (*n)->workid;
  v5->m_Items[1] = 393249;
  v7 = nbSearchHojoSkillWork(n, 3);
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

// 0xef8c10
s32 Flow6_28(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  s32 cnt6_36;
  bool v6;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  s32 level;
  s32 v11;
  bool v12;
  s32 v13;
  struct datUnitWork_t_o *pwork;
  s32 v15;
  s32 v16;
  bool v17;
  u32 RandIntA;
  u32 max_length;

  nbAddNegoIdKouho(n, 0x90001u);
  nbAddNegoIdKouho(n, 0x60024u);
  v4 = *n;
  cnt6_36 = (*n)->cnt6_36;
  if (cnt6_36 <= 1)
  {
    v6 = evtBitCheck(8);
    v4 = *n;
    if (v6)
    {
      nextkouho = v4->nextkouho;
      if (LODWORD(nextkouho->max_length) <= 1)
    }
    cnt6_36 = v4->cnt6_36;
  }
  if (cnt6_36 == 3)
  {
    level = v4->ework->level;
    v11 = v4->pwork->level;
    v12 = evtBitCheck(8);
    v13 = v11 - 17;
    v4 = *n;
    if (v13 >= level && v12)
    {
      nextkouho = v4->nextkouho;
      m_Items = nextkouho->m_Items;
    }
    cnt6_36 = v4->cnt6_36;
  }
  if (cnt6_36 <= 2
    && (pwork = v4->pwork,
        v15 = v4->ework->level,
        v16 = pwork->level,
        v17 = evtBitCheck(8),
        v16 - 10 <= v15)
    && v17)
  {
    v4 = *n;
    nextkouho = (*n)->nextkouho;
    if (LODWORD(nextkouho->max_length) <= 1)
  }
  else
  {
    RandIntA = dds3GetRandIntA(0xAu, StringLiteral_5354);
    v4 = *n;
    nextkouho = (*n)->nextkouho;
    max_length = nextkouho->max_length;
    if (RandIntA < 2)
    {
      if (!max_length)
    }
  }
  m_Items = &nextkouho->m_Items[1];
  v4->nextnegoid = *m_Items;
  return 0;
}

// 0xef8e20
s32 Flow6_29(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  u32 *nextkouho;
  u32 v5;
  u32 *v7;

  nbAddNegoIdKouho(n, 0x6001Eu);
  nbAddNegoIdKouho(n, 0x60020u);
  v3 = *n;
  nextkouho = v3->nextkouho;
  v5 = nextkouho[6];
  if (v3->hojoaisyo == 1)
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

// 0xef52d0
s32 Flow6_3(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *aisyomsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0x60004u);
    aisyomsg = (*n)->aisyomsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, aisyomsg->m_Items[ekucyo], (*n)->aisyomes, 0, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoYesMotion(n, &v3->eform);
  }
  return 0;
}

// 0xef8f30
s32 Flow6_30(nbNegoProcessData_t **n) {
  struct System_Int32_array *aisyomsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x6001Fu);
  aisyomsg = (*n)->aisyomsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, aisyomsg->m_Items[ekucyo], (*n)->hojoaisyomes, 0, 0);
  return 0;
}

// 0xef9020
s32 Flow6_31(nbNegoProcessData_t **n) {
  u32 RandIntA;
  nbNegoProcessData_t_o *v5;
  u32 *nextkouho;
  u32 v7;
  u32 *v9;

  nbAddNegoIdKouho(n, 0x90001u);
  nbAddNegoIdKouho(n, 0x60023u);
  RandIntA = dds3GetRandIntA(0xAu, StringLiteral_5355);
  v5 = *n;
  nextkouho = v5->nextkouho;
  v7 = nextkouho[6];
  if (RandIntA)
  {
    v9 = nextkouho + 8;
  }
  else
  {
    v9 = nextkouho + 9;
  }
  v5->nextnegoid = *v9;
  return 0;
}

// 0xef9160
s32 Flow6_32(nbNegoProcessData_t **n) {
  u32 RandIntA;
  nbNegoProcessData_t_o *v6;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v10;
  nbNegoProcessData_t_o **v11;
  s32 v12;
  s32 v13;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  struct System_Int32_array *v17;
  s64 v18;
  s32 v20;
  struct System_Int32_array *v21;
  s64 v22;
  struct System_UInt32_array *v24;
  struct System_Int32_array *v25;
  s64 v26;
  struct System_Int32_array *v28;
  s64 v29;
  struct System_Int32_array *v31;
  s64 v32;

  nbAddNegoIdKouho(n, 0x90001u);
  nbAddNegoIdKouho(n, 0x60022u);
  RandIntA = dds3GetRandIntA(0xAu, StringLiteral_5356);
  v6 = *n;
  if (RandIntA < 2)
  {
    nextkouho = v6->nextkouho;
    m_Items = &nextkouho->m_Items[1];
  }
  else
  {
    switch (v6->hojoskillid)
    {
      case 0x19D:
        flowmsg = v6->flowmsg;
        ekucyo = v6->ekucyo;
        v10 = flowmsg->m_Items[ekucyo];
        v11 = n;
        v12 = v10;
        v13 = 112;
      case 0x19E:
        v17 = v6->flowmsg;
        v18 = v6->ekucyo;
        v20 = v17->m_Items[v18];
        v13 = 113;
      case 0x19F:
        v21 = v6->flowmsg;
        v22 = v6->ekucyo;
        v20 = v21->m_Items[v22];
        v13 = 114;
      case 0x1A2:
        v25 = v6->flowmsg;
        v26 = v6->ekucyo;
        v20 = v25->m_Items[v26];
        v13 = 110;
      case 0x1A3:
        v28 = v6->flowmsg;
        v29 = v6->ekucyo;
        v20 = v28->m_Items[v29];
        v13 = 115;
      case 0x1A4:
        v31 = v6->flowmsg;
        v32 = v6->ekucyo;
        v20 = v31->m_Items[v32];
        v13 = 111;
        v11 = n;
        v12 = v20;
        nbDispNegoMessage(v11, v12, v13, 0);
        v6 = *n;
        v24 = (*n)->nextkouho;
        if (!LODWORD(v24->max_length))
      default:
        v24 = v6->nextkouho;
        m_Items = v24->m_Items;
        break;
    }
  }
  v6->nextnegoid = *m_Items;
  return 0;
}

// 0xef94d0
s32 Flow6_33(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  u32 v5;
  bool v6;
  s64 v7;
  bool v8;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v12;
  nbNegoProcessData_t_o *v13;
  struct System_UInt32_array *v14;
  u32 *v16;
  struct System_UInt32_array *nextkouho;

  nbAddNegoIdKouho(n, 0x90001u);
  nbAddNegoIdKouho(n, 0x60022u);
  nbAddNegoIdKouho(n, 0x60026u);
  v4 = *n;
  if ((*n)->hojoskillid != 413
    || ((v5 = v4->ework->id - 58, v6 = v5 > 0x22, v7 = (1LL << v5) & 0x70000000DLL, !v6)
      ? (v8 = v7 == 0)
      : (v8 = 1),
        v8))
  {
    dds3GetRandIntA(0xAu, StringLiteral_5357);
    v13 = *n;
    nextkouho = v13->nextkouho;
    v16 = &nextkouho->m_Items[1];
  }
  else
  {
    flowmsg = v4->flowmsg;
    ekucyo = v4->ekucyo;
    v12 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v12, 142, 0);
    v13 = *n;
    v14 = v13->nextkouho;
    v16 = &v14->m_Items[2];
  }
  v13->nextnegoid = *v16;
  return 0;
}

// 0xef96d0
s32 Flow6_34(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x60026u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 71, 0);
  return 0;
}

// 0xef97c0
s32 Flow6_35(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x6004Au);
  workid = (*n)->workid;
  workid->m_Items[6] = 393255;
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 276, 0);
  return 0;
}

// 0xef98d0
s32 Flow6_36(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  u32 v4;
  bool v5;
  s64 v6;
  bool v7;
  bool v8;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  struct System_UInt32_array *v13;

  nbAddNegoIdKouho(n, 0x60026u);
  nbAddNegoIdKouho(n, 0x90001u);
  v3 = *n;
  v4 = (*n)->ework->id - 61;
  v5 = v4 > 0x24;
  v6 = (1LL << v4) & 0x10C0000001LL;
  v7 = v5 || v6 == 0;
  if (v7 || (v8 = evtBitCheck(8), v3 = *n, v8) || v3->negoreqtype || v3->cnt6_36 < 3)
  {
    nextkouho = v3->nextkouho;
    m_Items = nextkouho->m_Items;
  }
  else
  {
    v13 = v3->nextkouho;
    m_Items = &v13->m_Items[1];
  }
  v3->nextnegoid = *m_Items;
  return 0;
}

// 0xef9a30
s32 Flow6_37(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  u32 v4;
  bool v5;
  s64 v6;
  bool v8;
  struct System_UInt32_array *nextkouho;
  s32 level;
  s32 v12;
  bool v13;
  s32 v14;
  struct System_UInt32_array *v15;
  u32 *m_Items;
  struct System_UInt32_array *v18;

  nbAddNegoIdKouho(n, 0x60026u);
  nbAddNegoIdKouho(n, 0x90001u);
  v3 = *n;
  v4 = (*n)->ework->id - 61;
  v5 = v4 > 0x24;
  v6 = (1LL << v4) & 0x10C0000001LL;
  if (!v5 && v6 != 0)
  {
    v8 = evtBitCheck(8);
    v3 = *n;
    if (!v8 && !v3->negoreqtype && v3->cnt6_36 >= 3)
  }
  nextkouho = v3->nextkouho;
  v3->nextnegoid = nextkouho->m_Items[0];
  v3 = *n;
  if ((*n)->cnt6_36 != 3
    || (level = v3->ework->level,
        v12 = v3->pwork->level,
        v13 = evtBitCheck(8),
        v14 = v12 - 17,
        v3 = *n,
        v14 < level)
    || !v13)
  {
    v18 = v3->nextkouho;
    m_Items = v18->m_Items;
  }
  else
  {
    v15 = v3->nextkouho;
    m_Items = &v15->m_Items[1];
  }
  v3->nextnegoid = *m_Items;
  return 0;
}

// 0xef9bf0
s32 Flow6_38(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  nbNegoProcessData_t_o *v6;
  s32 cnt6_36;
  struct System_Int32_array *v8;
  s64 v9;
  s32 v11;
  s32 v12;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  struct System_Int32_array *v16;
  s64 v17;
  nbNegoProcessData_t_o **v19;
  s32 v20;
  struct System_Int32_array *v22;
  s64 v23;
  s32 v25;

  nbAddNegoIdKouho(n, 0x6004Au);
  workid = (*n)->workid;
  workid->m_Items[6] = 393255;
  v6 = *n;
  cnt6_36 = (*n)->cnt6_36;
  switch (cnt6_36)
  {
    case 3:
      flowmsg = v6->flowmsg;
      ekucyo = v6->ekucyo;
      v11 = flowmsg->m_Items[ekucyo];
      v12 = 95;
    case 2:
      v16 = v6->flowmsg;
      v17 = v6->ekucyo;
      v11 = v16->m_Items[v17];
      v12 = 94;
    case 1:
      v8 = v6->flowmsg;
      v9 = v6->ekucyo;
      v11 = v8->m_Items[v9];
      v12 = 93;
      v19 = n;
      v20 = v11;
  }
  if (cnt6_36 < 4)
    return 0;
  v22 = v6->flowmsg;
  v23 = v6->ekucyo;
  v25 = v22->m_Items[v23];
  v19 = n;
  v20 = v25;
  v12 = 96;
  nbDispNegoMessage(v19, v20, v12, 0);
  return 0;
}

// 0xef9e30
s32 Flow6_39(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  bool v5;
  s32 id;
  s32 tuikareqtype;
  s32 NegoTuikaRequestType;
  nbNegoProcessData_t_o *v11;
  s32 v12;
  nbNegoProcessData_t_o *v13;
  u32 RandIntA;
  nbNegoProcessData_t_o *v15;
  nbNegoProcessData_t_o *v16;
  s32 requesttype;

  nbAddNegoIdKouho(n, 0x60028u);
  v4 = *n;
  if ((*n)->ework->id != 92 || (v5 = evtBitCheck(8), v4 = *n, v5) || v4->negoreqtype)
  {
    id = v4->ework->id;
    tuikareqtype = Get(id, 0)->tuikareqtype;
    NegoTuikaRequestType = nbGetNegoTuikaRequestType(tuikareqtype);
    if (NegoTuikaRequestType != 2)
    {
      if (NegoTuikaRequestType == 1)
      {
        (*n)->requesttype = 0;
      }
      if (NegoTuikaRequestType)
      v11 = *n;
      v12 = 1;
    }
    v11 = *n;
    v12 = 3;
    v11->requesttype = v12;
  }
  if (!dds3GetRandIntA(1u, StringLiteral_5358))
  (*n)->requestdata = 0;
  v13 = *n;
  if ((*n)->negoreqtype == 4)
  {
    v13->requesttype = 0;
    v13 = *n;
  }
  if (v13->prevreqtype == 3 || v13->requesttype != 3)
  {
    v16 = *n;
    requesttype = (*n)->requesttype;
    if (requesttype != 1)
  }
  RandIntA = dds3GetRandIntA(2u, StringLiteral_5358);
  v15 = *n;
  if (RandIntA)
  {
    v15->requesttype = 0;
  }
  v15->requesttype = 1;
  v16 = *n;
  requesttype = (*n)->requesttype;
  if (requesttype != 1)
  {
    if (!requesttype)
    {
      v16->requestdata = nbGetKureItemB(n, &v16->pwork, &v16->ework);
      if (!(*n)->requestdata)
        (*n)->requestdata = 16;
    }
  }
  v16->requestdata = nbGetNegoKureMakkaB(n, &v16->pwork, &v16->ework);
  (*n)->prevreqtype = (*n)->requesttype;
  return 0;
}

// 0xef5410
s32 Flow6_4(nbNegoProcessData_t **n) {
  signed s32 RandIntA;
  nbNegoProcessData_t_o *v5;
  u32 *nextkouho;
  u32 v7;
  u32 *v9;

  nbAddNegoIdKouho(n, 0x60005u);
  nbAddNegoIdKouho(n, 0x90001u);
  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_5345);
  v5 = *n;
  nextkouho = v5->nextkouho;
  v7 = nextkouho[6];
  if (RandIntA <= 64)
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

// 0xefa120
s32 Flow6_40(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  s32 requesttype;
  s32 v6;
  struct System_Int32_array *v7;
  s64 v8;
  char *v10;
  s32 v11;
  s32 v12;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  char *v16;
  s32 requestdata;
  s32 v18;
  struct System_Int32_array *v19;
  s64 v20;
  s32 v22;

  nbAddNegoIdKouho(n, 0x60029u);
  v4 = *n;
  requesttype = (*n)->requesttype;
  if (requesttype)
  {
    if (requesttype == 1)
    {
      flowmsg = v4->flowmsg;
      ekucyo = v4->ekucyo;
      v16 = flowmsg + 4 * ekucyo;
      requestdata = v4->requestdata;
      v18 = *(v16 + 8);
      nbSetMesMakka(v18, requestdata);
      nbMakaDispOn(0);
      v6 = 74;
    }
    else if (requesttype == 3)
    {
      v6 = 76;
    }
    else
    {
      v6 = 0;
    }
  }
  else
  {
    v7 = v4->flowmsg;
    v8 = v4->ekucyo;
    v10 = v7 + 4 * v8;
    v11 = v4->requestdata;
    v12 = *(v10 + 8);
    nbSetMesItem(v12, v11);
    v6 = 75;
  }
  v19 = (*n)->flowmsg;
  v20 = (*n)->ekucyo;
  v22 = v19->m_Items[v20];
  nbDispNegoMessage(n, v22, v6, 0);
  return 0;
}

// 0xefa330
s32 Flow6_41(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x6002Au);
  return 0;
}

// 0xefa3d0
s32 Flow6_42(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v8;
  u32 v9;
  struct System_UInt32_array *workid;
  nbNegoProcessData_t_o *v13;
  struct System_UInt32_array *nextkouho;
  u32 max_length;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    if (v3->requesttype == 3)
    {
      v9 = 720897;
    }
    else
    {
      v9 = 393238;
    }
    nbAddNegoIdKouho(n, v9);
    nbAddNegoIdKouho(n, 0x60041u);
    workid = (*n)->workid;
    workid->m_Items[2] = 393255;
    v13 = *n;
    nextkouho = v13->nextkouho;
    max_length = nextkouho->max_length;
    if (v13->nowselect)
    {
      v13->nextnegoid = nextkouho->m_Items[1];
      nbMakaDispOff();
    }
    else
    {
      v13->nextnegoid = nextkouho->m_Items[0];
    }
  }
  else if (!nownegophase)
  {
    flowmsg = v3->flowmsg;
    ekucyo = v3->ekucyo;
    v8 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v8, 72, 1);
  }
  return 0;
}

// 0xefa5f0
s32 Flow6_43(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *v5;
  s64 v6;
  s32 v8;
  nbNegoProcessData_t_o *v10;
  struct System_Int32_array *v11;
  s64 v12;
  s32 v15;
  u32 RandIntA;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  u32 v19;
  nbNegoProcessData_t_o *v21;
  struct System_UInt32_array *nextkouho;
  u32 v24;
  struct System_UInt32_array *v25;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0x6002Cu);
    nbAddNegoIdKouho(n, 0x90001u);
    v10 = *n;
    if ((*n)->data->enemypcnt == 1 && v10->cnt6_36 >= 4)
    {
      RandIntA = dds3GetRandIntA(0xAu, StringLiteral_5359);
      flowmsg = (*n)->flowmsg;
      ekucyo = (*n)->ekucyo;
      v19 = RandIntA;
      v15 = flowmsg->m_Items[ekucyo];
      if (v19 <= 5)
      {
        nbDispNegoMessage(n, v15, 97, 0);
        v21 = *n;
        nextkouho = v21->nextkouho;
        v24 = nextkouho->m_Items[1];
      }
      {
        nbDispNegoMessage(n, v15, 98, 0);
        v21 = *n;
        v25 = v21->nextkouho;
        v24 = v25->m_Items[0];
        v21->nextnegoid = v24;
        return 0;
      }
    }
    else
    {
      v11 = v10->flowmsg;
      v12 = v10->ekucyo;
      v15 = v11->m_Items[v12];
    }
  }
  if (!nownegophase)
  {
    v5 = v3->flowmsg;
    v6 = v3->ekucyo;
    v8 = v5->m_Items[v6];
    nbDispNegoMessage(n, v8, 78, 0);
  }
  return 0;
}

// 0xefa8b0
s32 Flow6_44(nbNegoProcessData_t **n) {
  s32 HojoSkillWorkCnt;
  nbNegoProcessData_t_o *v4;
  u32 *nextkouho;
  u32 v6;
  u32 *v8;

  nbAddNegoIdKouho(n, 0xA0017u);
  nbAddNegoIdKouho(n, 0x6002Du);
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

// 0xefa9c0
s32 Flow6_45(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_UInt32_array *v5;
  u32 v7;
  nbNegoProcessData_t_o *v8;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  struct System_UInt32_array *v12;

  nbAddNegoIdKouho(n, 0xA0017u);
  nbAddNegoIdKouho(n, 0x60034u);
  workid = (*n)->workid;
  workid->m_Items[0] = 393262;
  v5 = (*n)->workid;
  v5->m_Items[1] = 393263;
  v7 = nbSearchHojoSkillWork(n, 2);
  v8 = *n;
  if (v7)
  {
    v8->hojopartyindex = HIWORD(v7);
    (*n)->hojoskillid = v7;
    v8 = *n;
    nextkouho = (*n)->nextkouho;
    m_Items = &nextkouho->m_Items[1];
  }
  else
  {
    v12 = v8->nextkouho;
    m_Items = v12->m_Items;
  }
  v8->nextnegoid = *m_Items;
  return 0;
}

// 0xefab50
s32 Flow6_46(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x6004Au);
  workid = (*n)->workid;
  workid->m_Items[6] = 393225;
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 79, 0);
  (*n)->cnt6_36 = 0;
  (*n)->cnt6_37 = 0;
  return 0;
}

// 0xefac70
s32 Flow6_47(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0xA001Du);
  nbDispNegoMessage(n, (*n)->helpmsg2, 9, 0, 0);
  (*n)->waitframe = 60;
  return 0;
}

// 0xefad30
s32 Flow6_48(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  u32 *nextkouho;
  u32 v5;
  u32 *v7;

  nbAddNegoIdKouho(n, 0x60031u);
  nbAddNegoIdKouho(n, 0xA0001u);
  v3 = *n;
  nextkouho = v3->nextkouho;
  v5 = nextkouho[6];
  if (v3->cnt6_58 < 3)
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

// 0xefae40
s32 Flow6_49(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  nbNegoProcessData_t_o *v5;
  u32 *nextkouho;
  u32 v7;
  u32 *v9;

  nbAddNegoIdKouho(n, 0x60032u);
  nbAddNegoIdKouho(n, 0x60041u);
  workid = (*n)->workid;
  workid->m_Items[2] = 393285;
  v5 = *n;
  nextkouho = v5->nextkouho;
  v7 = nextkouho[6];
  if (v5->requesttype == 1)
  {
    v9 = nextkouho + 8;
  }
  else
  {
    v9 = nextkouho + 9;
  }
  v5->nextnegoid = *v9;
  return 0;
}

// 0xef5550
s32 Flow6_5(nbNegoProcessData_t **n) {
  struct System_Int32_array *aisyomsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x60009u);
  aisyomsg = (*n)->aisyomsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, aisyomsg->m_Items[ekucyo], 38, 0);
  return 0;
}

// 0xefaf80
s32 Flow6_50(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  s32 HojoSkillWorkCnt;
  nbNegoProcessData_t_o *v6;
  u32 *nextkouho;
  u32 v8;
  u32 *v10;

  nbAddNegoIdKouho(n, 0x60033u);
  nbAddNegoIdKouho(n, 0x60041u);
  workid = (*n)->workid;
  workid->m_Items[2] = 393285;
  HojoSkillWorkCnt = nbGetHojoSkillWorkCnt(n);
  v6 = *n;
  nextkouho = v6->nextkouho;
  v8 = nextkouho[6];
  if (HojoSkillWorkCnt < 1)
  {
    v10 = nextkouho + 9;
  }
  else
  {
    v10 = nextkouho + 8;
  }
  v6->nextnegoid = *v10;
  return 0;
}

// 0xefb0c0
s32 Flow6_51(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_UInt32_array *v5;
  struct System_UInt32_array *v7;
  u32 v9;
  nbNegoProcessData_t_o *v10;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  struct System_UInt32_array *v14;

  nbAddNegoIdKouho(n, 0x60034u);
  nbAddNegoIdKouho(n, 0x60041u);
  workid = (*n)->workid;
  workid->m_Items[2] = 393285;
  v5 = (*n)->workid;
  v5->m_Items[0] = 393274;
  v7 = (*n)->workid;
  v7->m_Items[1] = 393279;
  v9 = nbSearchHojoSkillWork(n, 0);
  v10 = *n;
  if (v9)
  {
    v10->hojopartyindex = HIWORD(v9);
    (*n)->hojoskillid = v9;
    v10 = *n;
    nextkouho = (*n)->nextkouho;
    m_Items = nextkouho->m_Items;
  }
  else
  {
    v14 = v10->nextkouho;
    m_Items = &v14->m_Items[1];
  }
  v10->nextnegoid = *m_Items;
  return 0;
}

// 0xefb280
s32 Flow6_52(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x60035u);
  nbClsNegoMessage(n);
  (*n)->hojoseikou = 0;
  (*n)->hojoaisyo = 0;
  return 0;
}

// 0xefb340
s32 Flow6_53(nbNegoProcessData_t **n) {
    nbCameraSetHojo(0, 0, 0);
    nbDispNegoMessage(0, 0, 0, 0);
    nbClsNegoMessage(0);
    nbCameraSetTaizi(0, 0);
    nbMakeNegoBackPacket(0, 0, 0, 0);
    nbFormDispOff2(0);
    nbMakeNegoWorkPosPacket(0, 0, 0, 0);
    nbMakeUnitFadeInPacket(0, 0, 0, 0, 0, 0, 0);
    nbMakeNegoForwardPacket(0, 0, 0, 0);
    nbFormDispOn2(0);
    nbDispSkillName(0);
    nbAddNegoIdKouho(0, 0);
    return 0;
}

// 0xefbad0
s32 Flow6_54(nbNegoProcessData_t **n) {
  struct System_UInt32_array *nextkouho;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *party;
  s64 hojopartyindex;
  nbParty_t_o *v10;
  datUnitWork_t_o *UnitWorkPointer;
  nbNegoProcessData_t_o *v12;
  s32 hojoskillid;
  struct System_UInt32_array *v14;
  struct System_Int32_array *temp_param;
  struct System_Int32_array *v18;
  struct System_UInt32_array *v20;
  struct System_Int32_array *v22;
  struct System_Int32_array *v24;

  nbAddNegoIdKouho(n, 0x60038u);
  nbAddNegoIdKouho(n, 0x60037u);
  nextkouho = (*n)->nextkouho;
  (*n)->nextnegoid = nextkouho->m_Items[0];
  data = (*n)->data;
  party = data->party;
  hojopartyindex = (*n)->hojopartyindex;
  v10 = party->m_Items[hojopartyindex];
  UnitWorkPointer = nbGetUnitWorkPointer(data, v10);
  v12 = *n;
  hojoskillid = (*n)->hojoskillid;
  if (hojoskillid == 418)
  {
    if (UnitWorkPointer->id != 20)
      return 0;
    v14 = v12->nextkouho;
    v12->nextnegoid = v14->m_Items[1];
    temp_param = (*n)->temp_param;
    temp_param->m_Items[0] = 2;
    v18 = (*n)->temp_param;
    v18->m_Items[1] = 88;
    v12 = *n;
    hojoskillid = (*n)->hojoskillid;
  }
  if (hojoskillid == 419 && UnitWorkPointer->id == 15)
  {
    v20 = v12->nextkouho;
    v12->nextnegoid = v20->m_Items[1];
    v22 = (*n)->temp_param;
    v22->m_Items[0] = 6;
    v24 = (*n)->temp_param;
    v24->m_Items[1] = 89;
  }
  return 0;
}

// 0xefbd50
s32 Flow6_55(nbNegoProcessData_t **n) {
  struct System_Int32_array *temp_param;
  struct System_Int32_array *flowmsg;
  s64 v5;
  s32 v7;
  struct System_Int32_array *v8;

  nbAddNegoIdKouho(n, 0x60038u);
  temp_param = (*n)->temp_param;
  flowmsg = (*n)->flowmsg;
  v5 = temp_param->m_Items[0];
  v7 = flowmsg->m_Items[v5];
  v8 = (*n)->temp_param;
  nbDispNegoMessage(n, v7, v8->m_Items[1], 0);
  return 0;
}

// 0xefbe90
s32 Flow6_56(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v4;
  s32 hojoskillid;
  nbMainProcessData_t_o *data;
  struct nbParty_t_array *party;
  s64 hojopartyindex;
  nbParty_t_o *v10;
  s64 v13;
  s64 i;
  datUnitWork_t_o **p_ework;
  struct datNegoSkill_t_array *tbl;
  u64 v18;
  struct datNegoAisyo_s_array *killeraisyo;
  u32 v22;
  struct datNegoSkill_t_array *v23;
  struct datNegoAisyo_s_array *v25;
  u32 v27;
  nbNegoProcessData_t_o *v28;
  s32 v29;
  s32 v31;
  nbNegoProcessData_t_o *v34;
  struct datNegoSkill_t_array *v35;
  struct datNegoAisyo_s_array *v37;
  datUnitWork_t_o *a;

  a = 0;
  nbAddNegoIdKouho(n, 0x60039u);
  v4 = *n;
  hojoskillid = (*n)->hojoskillid;
  if ((hojoskillid - 412) >= 6 && (hojoskillid - 419) > 1)
  {
    v4->hojoaisyo = 0;
    return 0;
  }
  data = v4->data;
  party = data->party;
  hojopartyindex = v4->hojopartyindex;
  v10 = party->m_Items[hojopartyindex];
  a = nbGetUnitWorkPointer(data, v10);
  v13 = (*n)->hojoskillid - 384LL;
  for (i = 4; ; ++i)
  {
    v18 = i - 4;
    killeraisyo = tbl->m_Items[v13]->killeraisyo;
    v22 = *(*(&killeraisyo->obj.klass + i) + 16LL);
    v23 = tbl;
    v25 = v23->m_Items[v13]->killeraisyo;
    v27 = *(*(&v25->obj.klass + i) + 20LL);
    if (!(v27 | v22))
    v28 = *n;
    p_ework = &v28->ework;
    if ((byte_3F5845B & 1) == 0)
    v29 = ChkAisyo(&a, p_ework, v22, 1);
    v31 = ChkAisyo(p_ework, &a, v27, 1);
    if (v29 && v31 != 0)
      break;
    if (v18 > 2)
      return 0;
  }
  (*n)->hojoaisyo = 1;
  v34 = *n;
  v35 = tbl;
  v37 = v35->m_Items[v13]->killeraisyo;
  v34->hojoaisyomes = *(*(&v37->obj.klass + i) + 24LL);
  return 0;
}

// 0xefc210
s32 Flow6_57(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  u32 v5;
  struct System_UInt32_array *v6;
  s32 v9;
  datUnitWork_t_o *ework;
  s32 Param;
  s32 v12;
  signed s32 v14;
  nbNegoProcessData_t_o *v15;
  u32 v16;
  signed s32 RandIntA;
  nbNegoProcessData_t_o *v18;
  nbNegoProcessData_t_o *v19;
  struct System_UInt32_array *v20;
  u32 *m_Items;
  struct System_UInt32_array *nextkouho;

  workid = (*n)->workid;
  v5 = workid->m_Items[0];
  nbAddNegoIdKouho(n, v5);
  v6 = (*n)->workid;
  nbAddNegoIdKouho(n, v6->m_Items[1]);
  if ((*n)->hojoskillid == 418)
    v9 = 85;
  else
    v9 = 70;
  ework = (*n)->ework;
  Param = datGetParam(ework, 1);
  v12 = datGetParam((*n)->pwork, 1, 0);
  if (Param + 5 >= v12)
  {
    if (Param - 5 <= v12)
      v14 = v9;
    else
      v14 = v9 - 10;
    v15 = *n;
    if ((*n)->hojoskillid != 413)
  }
  else
  {
    v14 = v9 + 10;
    v15 = *n;
    if ((*n)->hojoskillid != 413)
  }
  v16 = v15->ework->id - 58;
  if (v16 <= 0x22 && ((1LL << v16) & 0x70000000DLL) != 0)
    v14 = 0;
  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_5361);
  v18 = *n;
  if (RandIntA >= v14)
  {
    v18->hojoseikou = 0;
    v19 = *n;
    nextkouho = v19->nextkouho;
    m_Items = &nextkouho->m_Items[1];
  }
  else
  {
    v18->hojoseikou = 1;
    v19 = *n;
    v20 = v19->nextkouho;
    m_Items = v20->m_Items;
  }
  v19->nextnegoid = *m_Items;
  return 0;
}

// 0xefc470
s32 Flow6_58(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 requestdata;
  s32 v5;

  ++(*n)->cnt6_58;
  v3 = *n;
  requestdata = (*n)->requestdata;
  if (requestdata >= 0)
    v5 = requestdata;
  else
    v5 = requestdata + 1;
  v3->requestdata = v5 >> 1;
  nbAddNegoIdKouho(n, 0x6003Bu);
  return 0;
}

// 0xefc540
s32 Flow6_59(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s64 cnt6_58;
  s64 v5;
  struct System_UInt32_array *nextkouho;

  nbAddNegoIdKouho(n, 0x60047u);
  nbAddNegoIdKouho(n, 0x60048u);
  nbAddNegoIdKouho(n, 0x60049u);
  v3 = *n;
  cnt6_58 = v3->cnt6_58;
  v5 = cnt6_58 - 1;
  if ((cnt6_58 - 1) <= 2)
  {
    nextkouho = v3->nextkouho;
    v3->nextnegoid = nextkouho->m_Items[v5];
  }
  return 0;
}

// 0xef5640
s32 Flow6_6(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_Int32_array *aisyomsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0x60007u);
    aisyomsg = (*n)->aisyomsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, aisyomsg->m_Items[ekucyo], (*n)->aisyomes, 0, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0xefc760
s32 Flow6_60(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  struct System_Int32_array *v6;
  s64 v7;

  nbAddNegoIdKouho(n, 0x60046u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbSetMesMakka(flowmsg->m_Items[ekucyo], (*n)->requestdata, 0);
  v6 = (*n)->flowmsg;
  v7 = (*n)->ekucyo;
  nbDispNegoMessage(n, v6->m_Items[v7], 85, 0);
  nbMakaDispOn(0);
  return 0;
}

// 0xefc9a0
s32 Flow6_61(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  struct System_Int32_array *v6;
  s64 v7;

  nbAddNegoIdKouho(n, 0x60046u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbSetMesMakka(flowmsg->m_Items[ekucyo], (*n)->requestdata, 0);
  v6 = (*n)->flowmsg;
  v7 = (*n)->ekucyo;
  nbDispNegoMessage(n, v6->m_Items[v7], 86, 0);
  nbMakaDispOn(0);
  return 0;
}

// 0xefcbe0
s32 Flow6_62(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  struct System_Int32_array *v6;
  s64 v7;

  nbAddNegoIdKouho(n, 0x60046u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbSetMesMakka(flowmsg->m_Items[ekucyo], (*n)->requestdata, 0);
  v6 = (*n)->flowmsg;
  v7 = (*n)->ekucyo;
  nbDispNegoMessage(n, v6->m_Items[v7], 87, 0);
  nbMakaDispOn(0);
  return 0;
}

// 0xefcd10
s32 Flow6_63(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nownegophase;
  struct System_UInt32_array *workid;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  v3 = *n;
  nownegophase = (*n)->nownegophase;
  if (nownegophase == 1)
  {
    nbAddNegoIdKouho(n, 0x6004Au);
    workid = (*n)->workid;
    workid->m_Items[6] = 393280;
    flowmsg = (*n)->flowmsg;
    ekucyo = (*n)->ekucyo;
    nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 83, 0);
  }
  else if (!nownegophase)
  {
    v3->waitframe = nbSetNegoNoMotion(n, &v3->eform);
  }
  return 0;
}

// 0xefce70
s32 Flow6_64(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  struct System_Int32_array *v6;
  s64 v7;

  nbAddNegoIdKouho(n, 0x60046u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbSetMesMakka(flowmsg->m_Items[ekucyo], (*n)->requestdata, 0);
  v6 = (*n)->flowmsg;
  v7 = (*n)->ekucyo;
  nbDispNegoMessage(n, v6->m_Items[v7], 84, 0);
  nbMakaDispOn(0);
  return 0;
}

// 0xefcfa0
s32 Flow6_65(nbNegoProcessData_t **n) {
  datUnitWork_t_o *ework;
  s32 Race;
  nbNegoProcessData_t_o *v7;
  s32 aisyo;
  s32 v9;
  datUnitWork_t_o *v11;
  datUnitWork_t_o *pwork;
  s32 Param;
  s32 v15;
  nbNegoProcessData_t_o *v16;
  struct System_UInt32_array *nextkouho;
  u32 *m_Items;
  signed s32 RandIntA;
  u32 max_length;
  u32 v22;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v27;
  struct System_UInt32_array *v28;

  nbAddNegoIdKouho(n, 0xA0001u);
  nbAddNegoIdKouho(n, 0x60042u);
  nbAddNegoIdKouho(n, 0x90001u);
  ework = (*n)->ework;
  Race = datGetRace(ework);
  v7 = *n;
  aisyo = (*n)->aisyo;
  if (Race != 19)
  {
    if (aisyo == 1)
    {
      v9 = 30;
      v11 = v7->ework;
    }
    if (aisyo == 2)
      v9 = 70;
    else
      v9 = 50;
    v11 = v7->ework;
  }
  if (aisyo != 1)
  v9 = 40;
  v11 = v7->ework;
  if (datGetRace(v11) == 19)
  pwork = (*n)->pwork;
  Param = datGetParam(pwork, 1);
  v15 = datGetParam((*n)->ework, 1, 0);
  if (v15 + 5 < Param)
  {
    v9 -= 5;
    v16 = *n;
    if ((*n)->cnt6_37)
  }
  if (Param < v15 - 5)
    v9 += 5;
  v16 = *n;
  if ((*n)->cnt6_37)
  {
    nextkouho = v16->nextkouho;
    if (!LODWORD(nextkouho->max_length))
    m_Items = nextkouho->m_Items;
  }
  if (v16->cnt6_36 < 4)
  {
    RandIntA = dds3GetRandIntA(0x64u, StringLiteral_5362);
    v16 = *n;
    nextkouho = (*n)->nextkouho;
    max_length = nextkouho->max_length;
  }
  v22 = dds3GetRandIntA(0xAu, StringLiteral_5362);
  v16 = *n;
  if (v22 < 3)
  {
    nextkouho = v16->nextkouho;
    max_length = nextkouho->max_length;
    m_Items = &nextkouho->m_Items[1];
  }
  flowmsg = v16->flowmsg;
  ekucyo = v16->ekucyo;
  v27 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v27, 297, 0);
  v16 = *n;
  v28 = (*n)->nextkouho;
  m_Items = &v28->m_Items[2];
  v16->nextnegoid = *m_Items;
  return 0;
}

// 0xefd320
s32 Flow6_66(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  u32 *nextkouho;
  u32 v5;
  u32 *v7;

  ++(*n)->cnt6_66;
  nbAddNegoIdKouho(n, 0x60043u);
  nbAddNegoIdKouho(n, 0xA0001u);
  v3 = *n;
  nextkouho = v3->nextkouho;
  v5 = nextkouho[6];
  if (v3->cnt6_66 > 3)
  {
    v7 = nextkouho + 9;
  }
  else
  {
    v7 = nextkouho + 8;
  }
  v3->nextnegoid = *v7;
  return 0;
}

// 0xefd440
s32 Flow6_67(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  u32 v5;
  u32 RandIntA;
  nbNegoProcessData_t_o *v8;
  s32 v9;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v13;

  workid = (*n)->workid;
  v5 = workid->m_Items[2];
  nbAddNegoIdKouho(n, v5);
  do
  {
    RandIntA = dds3GetRandIntA(4u, StringLiteral_5363);
    v8 = *n;
    v9 = RandIntA + 33;
  }
  while (RandIntA + 33 == (*n)->mes6_67);
  flowmsg = v8->flowmsg;
  ekucyo = v8->ekucyo;
  v13 = flowmsg->m_Items[ekucyo];
  nbDispNegoMessage(n, v13, v9, 0);
  (*n)->mes6_67 = v9;
  return 0;
}

// 0xefd5a0
s32 Flow6_69(nbNegoProcessData_t **n) {
  nbAddNegoIdKouho(n, 0x60009u);
  return 0;
}

// 0xef5780
s32 Flow6_7(nbNegoProcessData_t **n) {
  signed s32 RandIntA;
  nbNegoProcessData_t_o *v5;
  u32 *nextkouho;
  u32 v7;
  u32 *v9;

  nbAddNegoIdKouho(n, 0x60008u);
  nbAddNegoIdKouho(n, 0xA0001u);
  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_5346);
  v5 = *n;
  nextkouho = v5->nextkouho;
  v7 = nextkouho[6];
  if (RandIntA <= 69)
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

// 0xef6f30
s32 Flow6_70(nbNegoProcessData_t **n) {
    nbAddNegoIdKouho(0, 0);
    nbMakaDispOff();
    nbGetPrevNegoId(0);
    nbDispNegoMessage(0, 0, 0, 0);
    return 0;
}

// 0xefc650
s32 Flow6_71(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x6004Au);
  workid = (*n)->workid;
  workid->m_Items[6] = 393276;
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 90, 0);
  return 0;
}

// 0xefc890
s32 Flow6_72(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x6004Au);
  workid = (*n)->workid;
  workid->m_Items[6] = 393277;
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 91, 0);
  return 0;
}

// 0xefcad0
s32 Flow6_73(nbNegoProcessData_t **n) {
  struct System_UInt32_array *workid;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x6004Au);
  workid = (*n)->workid;
  workid->m_Items[6] = 393278;
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 92, 0);
  return 0;
}

// 0xefb7c0
s32 Flow6_74(nbNegoProcessData_t **n) {
  nbActionProcessData_t_o *v3;
  nbNegoProcessData_t_o *v5;
  struct System_UInt32_array *v6;
  u32 v8;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *party;
  s64 hojopartyindex;
  struct nbFormation_t_array *v12;
  s64 formindex;
  nbNegoProcessData_t_o *v16;
  s32 nownegophase;
  nbFormation_t_o **p_pform;
  nbFormation_t_o **v21;
  nbFormation_t_o **p_eform;
  struct System_UInt32_array *workid;
  u32 v25;
  nbFormation_t_o *form;

  form = 0;
  v3 = Allocate(nbActionProcessData_t);
  nbActionProcessData_t___ctor(v3);
  v5 = *n;
  if (((*n)->stat & 8) != 0)
  {
    data = v5->data;
    party = data->party;
    hojopartyindex = v5->hojopartyindex;
    v12 = data->form;
    formindex = party->m_Items[hojopartyindex]->formindex;
    form = v12->m_Items[formindex];
    v16 = *n;
    nownegophase = (*n)->nownegophase;
    if (nownegophase != 2)
    {
      if (nownegophase == 1)
      {
        nbFormDispOff2(&form);
        nbMakeUnitFadeInPacket(1, v3->uniqueid, &form, 0, 1, 1, 1);
        nbAddHomeMoveKoukaPacket(0, 0, (*n)->hojopartyindex, 1.0, 0);
        nbFormDispOn2(&(*n)->pform, 0);
        nbMakeNegoForwardPacket(0, v3->uniqueid, &(*n)->pform, &(*n)->eform, 0);
      }
      else
      {
        if (nownegophase)
          return 0;
        nbMakeNegoBackPacket(0, v3->uniqueid, &form, &v16->eform);
        p_pform = &(*n)->pform;
        nbFormDispOff2(p_pform);
        nbMakeNegoWorkPosPacket(0, v3->uniqueid, &(*n)->pform, &(*n)->eform, 0);
        v21 = &(*n)->pform;
        p_eform = &(*n)->eform;
        nbCameraSetTaizi(v21, p_eform);
      }
      (*n)->waitframe = 10;
      return 0;
    }
    workid = v16->workid;
    v25 = workid->m_Items[6];
    nbAddNegoIdKouho(n, v25);
    (*n)->stat &= ~8u;
  }
  else
  {
    v6 = v5->workid;
    v8 = v6->m_Items[6];
    nbAddNegoIdKouho(n, v8);
  }
  return 0;
}

// 0xef58c0
s32 Flow6_8(nbNegoProcessData_t **n) {
  struct System_Int32_array *aisyomsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x60009u);
  aisyomsg = (*n)->aisyomsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, aisyomsg->m_Items[ekucyo], 39, 0);
  return 0;
}

// 0xef4fe0
s32 Flow6_80(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v5;
  struct System_UInt32_array *v6;
  u32 *m_Items;
  u32 RandIntA;
  nbNegoProcessData_t_o *v10;
  s32 v11;
  struct System_Int32_array *flowmsg;
  s64 ekucyo;
  s32 v15;
  struct System_UInt32_array *nextkouho;

  nbAddNegoIdKouho(n, 0x60051u);
  nbAddNegoIdKouho(n, 0x60009u);
  if (dds3GetRandIntA(0xAu, StringLiteral_5344) >= 4)
  {
    do
    {
      RandIntA = dds3GetRandIntA(4u, StringLiteral_5344);
      v10 = *n;
      v11 = RandIntA + 28;
    }
    while (RandIntA + 28 == (*n)->mes6_2);
    flowmsg = v10->flowmsg;
    ekucyo = v10->ekucyo;
    v15 = flowmsg->m_Items[ekucyo];
    nbDispNegoMessage(n, v15, v11, 0);
    (*n)->mes6_2 = v11;
    v5 = *n;
    nextkouho = v5->nextkouho;
    m_Items = &nextkouho->m_Items[1];
  }
  else
  {
    v5 = *n;
    v6 = v5->nextkouho;
    m_Items = v6->m_Items;
  }
  v5->nextnegoid = *m_Items;
  return 0;
}

// 0xef51e0
s32 Flow6_81(nbNegoProcessData_t **n) {
  struct System_Int32_array *flowmsg;
  s64 ekucyo;

  nbAddNegoIdKouho(n, 0x60004u);
  flowmsg = (*n)->flowmsg;
  ekucyo = (*n)->ekucyo;
  nbDispNegoMessage(n, flowmsg->m_Items[ekucyo], 294, 0);
  return 0;
}

// 0xef59b0
s32 Flow6_9(nbNegoProcessData_t **n) {
    nbAddNegoIdKouho(0, 0);
    Get(0);
    nbGetNegoRequestType(0);
    return 0;
}

// 0xef4030
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0xef4040
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0xef6870
s32 MakaHosei(s32 maka, s32 hosei) {
  return hosei * maka / 100;
}

// 0xef4580
s32 nbChkNegoAisyo(nbNegoProcessData_t **n, u32 from, u32 to, s32 sw) {
  datUnitWork_t_o **p_pwork;
  datUnitWork_t_o **p_ework;
  s32 v11;

  p_pwork = &(*n)->pwork;
  p_ework = &(*n)->ework;
  v11 = ChkAisyo(p_pwork, p_ework, from, sw);
  return ChkAisyo(&(*n)->ework, &(*n)->pwork, to, sw) != 0 && v11 != 0;
}

// 0xef4650
s32 nbChkNegoAisyo2(datUnitWork_t **s, datUnitWork_t **d, u32 from, u32 to, s32 sw) {
  s32 v11;

  v11 = ChkAisyo(s, d, from, sw, *&sw);
  return ChkAisyo(d, s, to, sw) != 0 && v11 != 0;
}

// 0xefd640
s32 nbNegoFlowTwo(nbNegoProcessData_t **n) {
  s64 nownegoid_low;
  struct NbNegoFlowTwo_procfuncDelegate_array *procfunc;

  nownegoid_low = LOWORD((*n)->nownegoid);
  return Invoke(procfunc->m_Items[nownegoid_low], n);
}
