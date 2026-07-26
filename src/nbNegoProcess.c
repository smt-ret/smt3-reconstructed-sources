#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbActionProcessData_t nbActionProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbNegoProcessData_t nbNegoProcessData_t;
typedef struct nbNegoProcess_SELECTINFO nbNegoProcess_SELECTINFO;
typedef struct nbNegoProcess_flowDelegate nbNegoProcess_flowDelegate;
typedef struct nbParty_t nbParty_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;

struct nbNegoProcess_SELECTINFO {
    s32 value__;
};

static nbNegoProcess_flowDelegate *flow[17];
static u32 anynextId;
static s32 anymax;

bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
u8 Get(s32 id);
void *GetMsgList(s32 ekucyo, s32 idx);
nbNegoProcessData_t *InitNegoProcessData(nbActionProcessData_t **actdata, s32 pformindex, s32 eformindex, s32 negotype, u32 skillid);
s32 NegoDebug(nbNegoProcessData_t **n);
void NegoDebugDraw(nbNegoProcessData_t **n);
void NegoDebugSelectDraw(nbNegoProcessData_t **n);
void WindowDispOff(bool sw);
s32 datCheckTalk(datUnitWork_t *work);
s32 datGetParam(datUnitWork_t *work, s32 paratype);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetRandIntA(u32 aLimit, char *name);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
s32 dds3SelectMenu(s32 pad, s32 listsx, s32 listsy, s32 winsx, s32 winsy, s32 *basex, s32 *basey, s32 *x, s32 *y);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
s32 itfMesMngGetPhase(s32 msgid);
s32 itfMesMngGetSelPhase(s32 msgid);
s32 itfMesMngGetSelectNo(s32 msgid);
s32 itfMesMngInitialize(void *presource, char **master_text, char *key);
void itfMesMngMarkBitStat(s32 id, u32 flag);
void itfMesMngMsgWndCls(s32 msgid);
void itfMesMngRelease(s32 id);
s32 itfMesMngRequestMessage(s32 id, s32 message, s32 page, s32 callmode);
void itfMesMngRequestSelect(s32 id, s32 select);
void itfMesMngRequestSelectRelease(s32 id);
void itfMesMngSetPhase(s32 msgid, s32 phase);
void itfMesMngSetSelPhase(s32 msgid, s32 phase);
void itfMesMngSetVar(s32 id, s32 index, s32 num, s32 type);
nbKoukaPacket_t *nbAddMotionKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 motion);
nbKoukaPacket_t *nbAddSePacket2(s32 startframe, s32 uniqueid, u32 se);
s32 nbCheckNegoMessage(nbNegoProcessData_t **n);
s32 nbCheckSelectMesJoukenAri(s32 msg_no, s32 field_no);
u32 nbGetNegoMIDI(nbFormation_t *form);
nbParty_t *nbGetPartyFromFormindex(s32 formindex);
s32 nbGetUniqueIdKoukaPacketCnt(s32 uniqueid);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
datUnitWork_t *nbGetUnitWorkPointer(nbMainProcessData_t *data, nbParty_t *party);
s32 nbSelectKureItemA(s32 lv_idx);
s32 nbSelectKureItemB(s32 lv_idx);
void nbSetAllHojoSkillWork(nbNegoProcessData_t **n);
void nbSetNegoMesVar(s32 msgid, datUnitWork_t **p, datUnitWork_t **e);
void nbSetNegoWaitMotion(nbFormation_t **form);
void p2sdBGMVolHalfDown(void);
void p2sdBGMVolHalfUp(void);
void *sdfDevPrintf(s32 aX, s32 aY, u32 aZ, s32 aAttr, char *aStr, void **LegacyParamArray);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);

// 0x1213810
s32 GET_NEGO_FLOWID(u32 x) {
  return HIWORD(x);
}

// 0x1213800
s32 GET_NEGO_PROCID(u32 x) {
  return x;
}

// 0x1213840
void *GetMsgList(s32 ekucyo, s32 idx) {
    return 0;
}

// 0x121aee0
nbNegoProcessData_t *InitNegoProcessData(nbActionProcessData_t **actdata, s32 pformindex, s32 eformindex, s32 negotype, u32 skillid) {
    nbGetUnitWorkFromFormindex(0);
    nbGetPartyFromFormindex(0);
    Get(0);
    GetMsgList(0, 0);
    itfMesMngInitialize(0, 0, 0);
    nbSetNegoMesVar(0, 0, 0);
    return 0;
}

// 0x1213820
u32 MAKE_NEGOID(s32 x, s32 y) {
  return y | (x << 16);
}

// 0x1215570
s32 NegoDebug(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nextkouhocnt;
  s32 v6;
  s32 v8;
  nbNegoProcess_c *v9;
  struct nbNegoProcess_StaticFields *static_fields;
  nbNegoProcessData_t_o *v11;
  s64 selectcur;
  s32 result;
  struct nbNegoProcess_StaticFields *v14;
  u32 anynextId;
  s32 v16;
  s32 v17;
  struct System_UInt32_array *nextkouho;
  bool v22;
  nbNegoProcessData_t_o *v23;
  struct System_UInt32_array *v24;
  s32 v25;
  u32 RandIntA;
  s32 y;
  s32 basey;
  s32 basex;

  basex = 0;
  basey = 0;
  y = 0;
  v3 = *n;
  nextkouhocnt = (*n)->nextkouhocnt;
  if (!nextkouhocnt)
  {
    return DDS3_PADCHECK_TRIG(1);
  }
  basex = 0;
  basey = 0;
  y = 0;
  else
  {
    v6 = nextkouhocnt;
  }
  v8 = dds3SelectMenu(0, anymax + nextkouhocnt, 0, v6 + anymax, 0, &basex, &basey, &v3->selectcur, &y);
  if (v8 == 1)
  {
    static_fields = v9->static_fields;
    v11 = *n;
    selectcur = v11->selectcur;
    if (static_fields->anymax && selectcur == v11->nextkouhocnt)
    {
      v11->nextnegoid = static_fields->anynextId;
    }
    else
    {
      nextkouho = v11->nextkouho;
      v11->nextnegoid = nextkouho->m_Items[selectcur];
    }
    return 1;
  }
  v14 = v9->static_fields;
  if (v14->anymax)
  {
    anynextId = v14->anynextId;
    v16 = anynextId;
    v17 = HIWORD(anynextId);
    if (DDS3_PADCHECK_REP(8))
    {
      if (v17 - 1 <= 0)
        v17 = 16;
      else
        --v17;
      anynextId = v16 | (v17 << 16);
    }
    if (DDS3_PADCHECK_REP(10))
    {
      if ((v17 + 1) < 0x11)
        ++v17;
      else
        v17 = 1;
    }
    else
    {
      if (!DDS3_PADCHECK_REP(6))
      {
        v16 += DDS3_PADCHECK_REP(7);
      }
      if (v16 - 1 <= 1)
        v16 = 1;
      else
        --v16;
    }
  }
  v22 = DDS3_PADCHECK_TRIG(0);
  result = 0;
  if (v22)
  {
    v23 = *n;
    v24 = (*n)->nextkouho;
    v25 = (*n)->nextkouhocnt;
    RandIntA = dds3GetRandIntA(v25, StringLiteral_416);
    v23->nextnegoid = v24->m_Items[RandIntA];
    return 1;
  }
  return result;
}

// 0x12147d0
void NegoDebugDraw(nbNegoProcessData_t **n) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x1214e20
void NegoDebugSelectDraw(nbNegoProcessData_t **n) {
    sdfDevPrintf(0, 0, 0, 0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x1215cf0
void nbAddNegoIdKouho(nbNegoProcessData_t **n, u32 id) {
  s64 nextkouhocnt;
  struct System_UInt32_array *nextkouho;

  nextkouhocnt = (*n)->nextkouhocnt;
  if (nextkouhocnt <= 7)
  {
    nextkouho = (*n)->nextkouho;
    nextkouho->m_Items[nextkouhocnt] = id;
    ++(*n)->nextkouhocnt;
  }
}

// 0x1216010
s32 nbCheckNegoMessage(nbNegoProcessData_t **n) {
  nbNegoProcessData_t_o *v3;
  s32 nowmsgid;
  s32 v8;
  s32 v9;
  nbNegoProcessData_t_o *v10;

  v3 = *n;
  nowmsgid = (*n)->nowmsgid;
  if (nowmsgid < 0)
  if ((v3->stat & 4) == 0)
  {
    else if ((itfMesMngGetPhase(nowmsgid) & 0x80000000) == 0)
    {
      return 0;
    }
    v8 = (*n)->nowmsgid;
    itfMesMngSetPhase(v8, 0);
  }
  else if ((itfMesMngGetSelPhase(nowmsgid) & 0x80000000) == 0)
  {
    return 0;
  }
  v9 = (*n)->nowmsgid;
  itfMesMngSetSelPhase(v9, 0);
  v10 = *n;
  v10->nowselect = itfMesMngGetSelectNo((*n)->nowmsgid, 0);
  itfMesMngRequestSelectRelease((*n)->nowmsgid, 0);
  v3 = *n;
  v3->nowmsgid = -1;
  return 1;
}

// 0x1219e00
s32 nbCheckSelectMesJoukenAri(s32 msg_no, s32 field_no) {
  struct datInfoSelectTable_t_array *InfoSelectTable;
  struct System_Int16_array *flagcheck;
  s32 result;
  struct datInfoSelectTable_t_array *v12;
  struct System_Int16_array *v14;
  struct datInfoSelectTable_t_array *v17;
  struct System_Int16_array *v19;

  flagcheck = InfoSelectTable->m_Items[msg_no]->flagcheck;
  result = flagcheck->m_Items[0];
  if (flagcheck->m_Items[0])
  {
    if (!evtBitCheck(result))
      return 0;
    v12 = InfoSelectTable;
    v14 = v12->m_Items[msg_no]->flagcheck;
    if (!v14->m_Items[1])
      return 1;
    if (!evtBitCheck(v14->m_Items[1]))
      return 0;
    v17 = InfoSelectTable;
    v19 = v17->m_Items[msg_no]->flagcheck;
    return !v19->m_Items[2] || evtBitCheck(v19->m_Items[2]);
  }
  return result;
}

// 0x1215f30
void nbClsNegoMessage(nbNegoProcessData_t **n) {
  s32 msgwndid;

  msgwndid = (*n)->msgwndid;
  if ((msgwndid & 0x80000000) == 0)
  {
    itfMesMngMsgWndCls(msgwndid);
    (*n)->msgwndid = -1;
  }
}

// 0x1215fc0
void nbDispNegoMessage(nbNegoProcessData_t **n, s32 msgid, s32 msgno, s32 sel) {
  nbNegoProcessData_t_o *v5;
  u32 stat;

  (*n)->nowmsgid = msgid;
  (*n)->nowmsgno = msgno;
  (*n)->nowselect = 0;
  v5 = *n;
  stat = (*n)->stat;
  if (sel)
  {
    v5->stat = stat | 4;
  }
  else
  {
    v5->stat = stat & 0xFFFFFFFB;
    (*n)->nowmes = msgno;
  }
}

// 0x1215db0
u32 nbGetBackNoNegoId(nbNegoProcessData_t **n, s32 a) {
  struct System_UInt32_array *history;
  s32 v4;

  history = (*n)->history;
  v4 = (15 - a + (*n)->historyindex) % 14;
  return history->m_Items[v4];
}

// 0x1217d30
s32 nbGetHojoSkillWorkCnt(nbNegoProcessData_t **n) {
  u64 v2;
  s32 v3;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v6;
  s64 i;
  struct nbParty_t_array *v9;
  u64 v10;
  struct System_UInt16_array *hojoskill;
  struct nbParty_t_array *v14;
  struct System_UInt16_array *v16;

  v2 = 0;
  v3 = 0;
  do
  {
    party = (*n)->data->party;
    if ((party->m_Items[v2]->flag & 1) != 0)
    {
      v6 = (*n)->data->party;
      if ((v6->m_Items[v2]->flag & 0x80) == 0)
      {
        for (i = 16; i != 24; ++i)
        {
          v9 = (*n)->data->party;
          v10 = i - 16;
          hojoskill = v9->m_Items[v2]->hojoskill;
          if (*(&hojoskill->obj.klass + i))
          {
            v14 = (*n)->data->party;
            v16 = v14->m_Items[v2]->hojoskill;
            v3 += (*(&v16->obj.klass + i) >> 15) ^ 1;
          }
        }
      }
    }
    ++v2;
  }
  while (v2 != 4);
  return v3;
}

// 0x1219a70
s32 nbGetInfoMsg(s32 infotype) {
    nbCheckSelectMesJoukenAri(0, 0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0x121a2d0
s32 nbGetInnenNegoID(nbNegoProcessData_t **n) {
    return 0;
}

// 0x1216b20
s32 nbGetKureItemA(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b) {
  s32 v5;
  s32 v7;
  struct System_Byte_array_array_array *datNegoReqItemListA;
  System_Byte_array_array *v10;
  s32 v11;
  System_Byte_array *v13;

  v5 = (*b)->level - 1;
  if (v5 > 0x62)
    return 0;
  v7 = v5 / 5;
  v10 = datNegoReqItemListA->m_Items[v7];
  v11 = nbSelectKureItemA(v7, a);
  v13 = v10->m_Items[v11];
  return v13->m_Items[0];
}

// 0x1216e60
s32 nbGetKureItemB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b) {
  s32 v5;
  s32 v7;
  struct System_Byte_array_array_array *datNegoReqItemListB;
  System_Byte_array_array *v10;
  s32 v11;
  System_Byte_array *v13;

  v5 = (*b)->level - 1;
  if (v5 > 0x62)
    return 0;
  v7 = v5 / 5;
  v10 = datNegoReqItemListB->m_Items[v7];
  v11 = nbSelectKureItemB(v7, a);
  v13 = v10->m_Items[v11];
  return v13->m_Items[0];
}

// 0x1216860
s32 nbGetNegoKureHpA(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b) {
  bool v6;
  s32 maxhp;
  s32 v8;
  u32 v9;

  v6 = evtBitCheck(8);
  maxhp = (*b)->maxhp;
  if (v6)
  {
    v8 = 20;
    v9 = 10;
  }
  else
  {
    v8 = 14;
    v9 = 8;
  }
  return ((dds3GetRandIntA(v9, StringLiteral_21493) + v8) * maxhp) / 100;
}

// 0x1216940
s32 nbGetNegoKureHpB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b) {
  s32 maxhp;

  maxhp = (*b)->maxhp;
  return ((dds3GetRandIntA(0xAu, StringLiteral_21494) + 10) * maxhp) / 100;
}

// 0x12165f0
s32 nbGetNegoKureMakkaA(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b) {
  s32 level;
  s32 v6;

  level = (*b)->level;
  v6 = 10 * (((((dds3GetRandIntA(0xAu, StringLiteral_21491) + 21) * level) * 0.8) + 5) / 10);
  if (v6)
    return v6;
  else
    return 1;
}

// 0x12166c0
s32 nbGetNegoKureMakkaB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b) {
  s32 level;
  s32 v7;
  s32 v8;
  s64 v9;
  s32 v10;

  level = (*b)->level;
  v7 = 10 * (((((dds3GetRandIntA(0xAu, StringLiteral_21491) + 21) * level) * 0.8) + 5) / 10);
  if (v7)
    v8 = v7;
  else
    v8 = 1;
  v9 = 1717986919LL * (((dds3GetRandIntA(0x14u, StringLiteral_21492) + 50) * v8) / 100 + 5);
  v10 = 10 * ((v9 >> 34) + (v9 >> 63));
  if (v10)
    return v10;
  else
    return 1;
}

// 0x12169e0
s32 nbGetNegoKureMpA(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b) {
  s32 maxmp;

  maxmp = (*b)->maxmp;
  return ((dds3GetRandIntA(0x1Eu, StringLiteral_21495) + 10) * maxmp) / 100;
}

// 0x1216a80
s32 nbGetNegoKureMpB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b) {
  s32 maxmp;

  maxmp = (*b)->maxmp;
  return ((dds3GetRandIntA(0xAu, StringLiteral_21496) + 10) * maxmp) / 100;
}

// 0x1217460
s32 nbGetNegoRequestType(s32 reqtype) {
  signed s32 RandIntA;
  u64 v5;
  s32 v6;
  struct System_Byte_array_array *datNegoReqTable;
  System_Byte_array *v10;
  struct System_Byte_array_array *v13;
  System_Byte_array *v15;

  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_21499);
  v5 = 0;
  v6 = 0;
  while (1)
  {
    v10 = datNegoReqTable->m_Items[reqtype];
    if (RandIntA < v6 + v10->m_Items[v5])
      break;
    v13 = datNegoReqTable;
    v15 = v13->m_Items[reqtype];
    v6 += v15->m_Items[v5];
    if (v5++ > 3)
    {
      LODWORD(v5) = 0;
      return v5;
    }
  }
  return v5;
}

// 0x1217610
s32 nbGetNegoTuikaRequestType(s32 tuikareqtype) {
  signed s32 RandIntA;
  struct System_Byte_array_array *datNegoTuikaReqtype;
  System_Byte_array *v7;
  struct System_Byte_array_array *v9;
  System_Byte_array *v10;
  s32 v12;
  struct System_Byte_array_array *v17;
  System_Byte_array *v19;
  struct System_Byte_array_array *v23;
  System_Byte_array *v25;
  s32 v28;
  struct System_Byte_array_array *v29;
  s32 v31;
  System_Byte_array *v32;
  struct System_Byte_array_array *v35;

  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_21500);
  v7 = datNegoTuikaReqtype->m_Items[tuikareqtype];
  if (RandIntA >= v7->m_Items[0])
  {
    v9 = datNegoTuikaReqtype;
    v10 = v9->m_Items[tuikareqtype];
    v12 = v10->m_Items[0];
    v17 = datNegoTuikaReqtype;
    v19 = v17->m_Items[tuikareqtype];
    if (RandIntA < v12 + v19->m_Items[1])
      return 1;
    v23 = datNegoTuikaReqtype;
    v25 = v23->m_Items[tuikareqtype];
    v28 = v25->m_Items[1];
    v29 = datNegoTuikaReqtype;
    v31 = v12 + v28;
    v32 = v29->m_Items[tuikareqtype];
    if (RandIntA < v31 + v32->m_Items[2])
      return 2;
    v35 = datNegoTuikaReqtype;
  }
  return 0;
}

// 0x1219320
s32 nbGetNegoYaruItemA(datUnitWork_t **w) {
  s32 id;
  datDevilNegoFormat_t_o *v5;
  signed s32 RandIntA;
  struct datNegoPresent_s_array *itema;
  s64 max_length_low;
  signed s32 ritu;
  datNegoPresent_s_o *v10;
  struct datNegoPresent_s_array *v13;
  s32 v14;
  struct datNegoPresent_s_array *v16;
  s32 v17;
  struct datNegoPresent_s_array *v19;

  id = (*w)->id;
  v5 = Get(id, 0);
  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_21503);
  itema = v5->itema;
  max_length_low = LODWORD(itema->max_length);
  ritu = itema->m_Items[0]->ritu;
  v10 = v5->itema->m_Items[0];
  if (RandIntA < ritu)
    return v10->item;
  v13 = v5->itema;
  v14 = v10->ritu;
  v10 = v13->m_Items[1];
  if (RandIntA < v14 + v10->ritu)
    return v10->item;
  v16 = v5->itema;
  v17 = v14 + v10->ritu;
  v10 = v5->itema->m_Items[2];
  if (RandIntA < v17 + v16->m_Items[2]->ritu)
    return v10->item;
  v19 = v5->itema;
  if (RandIntA < v17 + v10->ritu + v19->m_Items[3]->ritu)
  {
    v10 = v5->itema->m_Items[3];
    return v10->item;
  }
  return 0;
}

// 0x1219590
s32 nbGetNegoYaruItemB(datUnitWork_t **w) {
  s32 id;
  datDevilNegoFormat_t_o *v5;
  signed s32 RandIntA;
  struct datNegoPresent_s_array *itemb;
  s64 max_length_low;
  signed s32 ritu;
  datNegoPresent_s_o *v10;
  struct datNegoPresent_s_array *v13;
  s32 v14;
  struct datNegoPresent_s_array *v16;
  s32 v17;
  struct datNegoPresent_s_array *v19;

  id = (*w)->id;
  v5 = Get(id, 0);
  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_21504);
  itemb = v5->itemb;
  max_length_low = LODWORD(itemb->max_length);
  ritu = itemb->m_Items[0]->ritu;
  v10 = v5->itemb->m_Items[0];
  if (RandIntA < ritu)
    return v10->item;
  v13 = v5->itemb;
  v14 = v10->ritu;
  v10 = v13->m_Items[1];
  if (RandIntA < v14 + v10->ritu)
    return v10->item;
  v16 = v5->itemb;
  v17 = v14 + v10->ritu;
  v10 = v5->itemb->m_Items[2];
  if (RandIntA < v17 + v16->m_Items[2]->ritu)
    return v10->item;
  v19 = v5->itemb;
  if (RandIntA < v17 + v10->ritu + v19->m_Items[3]->ritu)
  {
    v10 = v5->itemb->m_Items[3];
    return v10->item;
  }
  return 0;
}

// 0x1216360
s32 nbGetNegoYaruMakkaA(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b) {
  s32 id;
  s32 dropmakka;
  s64 v8;
  s32 v9;

  id = (*b)->id;
  dropmakka = Get(id, 1, 0)->dropmakka;
  v8 = 1717986919LL * ((dds3GetRandIntA(4u, StringLiteral_21489) + 5) * dropmakka + 5);
  v9 = 10 * ((v8 >> 34) + (v8 >> 63));
  if (v9)
    return v9;
  else
    return 1;
}

// 0x1216450
s32 nbGetNegoYaruMakkaB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b) {
  s32 level;
  s32 v7;
  s32 v8;
  s64 v9;
  s32 v10;

  level = (*b)->level;
  v7 = 10 * (((((dds3GetRandIntA(0xAu, StringLiteral_21491) + 21) * level) * 0.8) + 5) / 10);
  if (v7)
    v8 = v7;
  else
    v8 = 1;
  v9 = 1717986919LL * (((dds3GetRandIntA(0x1Eu, StringLiteral_21490) + 40) * v8) / 100 + 5);
  v10 = 10 * ((v9 >> 34) + (v9 >> 63));
  if (v10)
    return v10;
  else
    return 1;
}

// 0x1219800
s32 nbGetNegoYaruStone(datUnitWork_t **w) {
  s32 id;
  datDevilNegoFormat_t_o *v5;
  signed s32 RandIntA;
  struct datNegoPresent_s_array *stone;
  s64 max_length_low;
  signed s32 ritu;
  datNegoPresent_s_o *v10;
  struct datNegoPresent_s_array *v13;
  s32 v14;
  struct datNegoPresent_s_array *v16;
  s32 v17;
  struct datNegoPresent_s_array *v19;

  id = (*w)->id;
  v5 = Get(id, 0);
  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_21505);
  stone = v5->stone;
  max_length_low = LODWORD(stone->max_length);
  ritu = stone->m_Items[0]->ritu;
  v10 = v5->stone->m_Items[0];
  if (RandIntA < ritu)
    return v10->item;
  v13 = v5->stone;
  v14 = v10->ritu;
  v10 = v13->m_Items[1];
  if (RandIntA < v14 + v10->ritu)
    return v10->item;
  v16 = v5->stone;
  v17 = v14 + v10->ritu;
  v10 = v5->stone->m_Items[2];
  if (RandIntA < v17 + v16->m_Items[2]->ritu)
    return v10->item;
  v19 = v5->stone;
  if (RandIntA < v17 + v10->ritu + v19->m_Items[3]->ritu)
  {
    v10 = v5->stone->m_Items[3];
    return v10->item;
  }
  return 0;
}

// 0x1215d60
u32 nbGetPrevNegoId(nbNegoProcessData_t **n) {
  struct System_UInt32_array *history;
  s64 historyindex;

  history = (*n)->history;
  historyindex = (*n)->historyindex;
  return history->m_Items[historyindex];
}

// 0x1218a90
s32 nbGetQuestionType(datUnitWork_t **w) {
  u64 *v3;
  s32 id;
  s32 v7;
  s64 privateselindex;
  signed s32 RandIntA;
  u64 v12;
  s32 v13;
  struct System_Byte_array_array *datNegoPrivateQues;
  System_Byte_array *v17;
  struct System_Byte_array_array *v20;
  System_Byte_array *v22;
  struct System_Byte_array *negoques;
  s32 v27;
  struct System_Byte_array *v29;
  s32 v31;
  struct System_Byte_array *v32;
  s32 v33;
  s32 v34;
  s32 v36;
  struct System_Byte_array *v37;
  struct System_Byte_array *v42;
  u32 max_length;
  u32 v45;
  bool v47;
  u32 v48;
  u32 v49;
  struct System_Byte_array *v50;
  u32 v51;
  u32 v52;
  bool v55;
  u32 v56;
  struct System_Byte_array *v57;
  u32 v58;
  u32 v59;
  u32 v62;
  bool v63;
  u32 v64;
  u32 v65;
  u32 v66;
  u32 v69;
  _BOOL4 v73;
  u32 v74;
  signed s32 v76;
  signed s32 v77;
  u32 v79;

  v3 = NewSpecific(s32, 3u);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__C25EB217AA9ADCFE616A75BFBF77BBC4F69643F2);
  id = (*w)->id;
  if (Get(id, 0)->privatesel == 1)
  {
    v7 = (*w)->id;
    privateselindex = Get(v7, 0)->privateselindex;
    RandIntA = dds3GetRandIntA(0x64u, StringLiteral_21502);
    v12 = 0;
    v13 = 0;
    while (1)
    {
      v17 = datNegoPrivateQues->m_Items[privateselindex];
      if (RandIntA < v13 + v17->m_Items[v12])
        return v12;
      v20 = datNegoPrivateQues;
      v22 = v20->m_Items[privateselindex];
      v13 += v22->m_Items[v12];
      if (v12++ > 2)
    }
  }
  negoques = DDS3_GBWK->negoques;
  v27 = negoques->m_Items[1];
  v29 = DDS3_GBWK->negoques;
  v31 = v29->m_Items[2];
  v32 = DDS3_GBWK->negoques;
  v33 = v27 + v31;
  v34 = v32->m_Items[3];
  v36 = v33 + v34;
  v37 = DDS3_GBWK->negoques;
  if (v37->m_Items[0] >= (2 * v36))
  {
    if (dds3GetRandIntA(0x64u, StringLiteral_21502) >= 80)
  }
  else
  {
    if (dds3GetRandIntA(2u, StringLiteral_21502))
    {
      LODWORD(v12) = 0;
      return v12;
    }
  }
  v42 = DDS3_GBWK->negoques;
  max_length = v42->max_length;
  v45 = v42->m_Items[1];
  v47 = v45 >= DDS3_GBWK->negoques->m_Items[2];
  if (v45 < DDS3_GBWK->negoques->m_Items[2])
    v48 = 1;
  else
    v48 = 2;
  if (v47)
    v49 = 1;
  else
    v49 = 2;
  v50 = DDS3_GBWK->negoques;
  v51 = v50->max_length;
  v52 = v50->m_Items[v49];
  v55 = v52 >= DDS3_GBWK->negoques->m_Items[3];
  if (v52 >= DDS3_GBWK->negoques->m_Items[3])
    v56 = v48;
  else
    v56 = v49;
  if (v55)
    v48 = v49;
  v57 = DDS3_GBWK->negoques;
  v58 = v57->max_length;
  v59 = v57->m_Items[v56];
  v62 = DDS3_GBWK->negoques->m_Items[3];
  v63 = v59 >= v62;
  if (v59 >= v62)
    v64 = 3;
  else
    v64 = v56;
  if (v63)
    v65 = v56;
  else
    v65 = 3;
  if (v48 != v65 || v48 != v64)
  {
    if (v48 == v65 && v48 > v64)
    {
      v69 = *(v3 + 6);
      *(v3 + 8) = 15;
      *(v3 + 9) = 15;
      if (v69 <= 2)
    }
    else
    {
      v73 = v48 > v65 && v65 == v64;
      v74 = *(v3 + 6);
      *(v3 + 8) = 0;
      if (v73)
      {
        *(v3 + 9) = 50;
        *(v3 + 10) = 50;
      }
      *(v3 + 9) = 30;
    }
    *(v3 + 10) = 70;
  }
  v66 = *(v3 + 6);
  *(v3 + 8) = 33;
  *(v3 + 9) = 33;
  *(v3 + 10) = 34;
  {
  }
  v76 = dds3GetRandIntA(0x64u, StringLiteral_21502);
  v77 = *(v3 + 8);
  if (v76 < v77)
  {
    LODWORD(v12) = 1;
    return v12;
  }
  v79 = *(v3 + 6);
  if (v76 < *(v3 + 9) + v77)
    return 2;
  else
    return 3;
}

// 0x121b7c0
void nbInitNegoProcess(nbActionProcessData_t **actdata, s32 pformindex, s32 eformindex, s32 negotype, s32 skillid) {
  nbNegoProcessData_t_o *data;
  u64 *v14;
  u64 *v15;
  dds3ProcessID_t_o *target;
  nbNegoProcessData_t_o *n;

  n = 0;
  target = 0;
  data = InitNegoProcessData(actdata, pformindex, eformindex, negotype, skillid);
  n = data;
  nbSetNegoWaitMotion(&data->eform);
  nbSetAllHojoSkillWork(&n);
  p2sdBGMVolHalfDown();
  v14 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v14,
    0,
    Method_nbNegoProcess_nbNegoProcess1__);
  v15 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v15,
    0,
    Method_nbNegoProcess_nbNegoShutdown__);
  target = dds3StartProcess(StringLiteral_21516, 0x3F9u, 1, 1, v14, 0, v15, 0, data, 0);
  dds3LinkProcess(&(*actdata)->data->MainProcessID, &target, 0);
  (*actdata)->data->NegoProcessID = target;
}

// 0x1213830
s32 nbMemoryLoadNegoSe(nbFormation_t *form) {
  return 0;
}

// 0x12142f0
void *nbNegoProcess1(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    nbGetUniqueIdKoukaPacketCnt(0);
    NegoDebugDraw(0);
    NegoDebugSelectDraw(0);
    NegoDebug(0);
    return 0;
}

// 0x121a930
void *nbNegoProcessEnd(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    return 0;
}

// 0x121a6b0
void *nbNegoProcessMessage(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    NegoDebugDraw(0);
    itfMesMngMsgWndCls(0);
    itfMesMngMarkBitStat(0, 0);
    itfMesMngRequestSelect(0, 0);
    itfMesMngRequestMessage(0, 0, 0, 0);
    return 0;
}

// 0x121a4a0
void *nbNegoProcessMessageChk(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    NegoDebugDraw(0);
    nbCheckNegoMessage(0);
    return 0;
}

// 0x121aa60
void *nbNegoShutdown(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    itfMesMngRelease(0);
    p2sdBGMVolHalfUp();
    WindowDispOff(0);
    return 0;
}

// 0x1217eb0
u32 nbSearchHojoSkillWork(nbNegoProcessData_t **n, s32 type) {
    nbGetUnitWorkPointer(0, 0);
    datGetParam(0, 0);
    Get(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0x1216c70
s32 nbSelectKureItemA(s32 lv_idx) {
  signed s32 RandIntA;
  u64 v5;
  s32 v6;
  struct System_Byte_array_array_array *datNegoReqItemListA;
  System_Byte_array_array *v10;
  System_Byte_array *v12;
  struct System_Byte_array_array_array *v15;
  System_Byte_array_array *v17;
  System_Byte_array *v19;

  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_21497);
  v5 = 0;
  v6 = 0;
  while (1)
  {
    v10 = datNegoReqItemListA->m_Items[lv_idx];
    v12 = v10->m_Items[v5];
    if (RandIntA < v6 + v12->m_Items[1])
      break;
    v15 = datNegoReqItemListA;
    v17 = v15->m_Items[lv_idx];
    v19 = v17->m_Items[v5];
    v6 += v19->m_Items[1];
    if (v5++ > 2)
    {
      LODWORD(v5) = 0;
      return v5;
    }
  }
  return v5;
}

// 0x1216fb0
s32 nbSelectKureItemB(s32 lv_idx) {
  signed s32 RandIntA;
  struct System_Byte_array_array_array *datNegoReqItemListB;
  System_Byte_array_array *v7;
  System_Byte_array *v8;
  struct System_Byte_array_array_array *v10;
  System_Byte_array_array *v11;
  System_Byte_array *v12;
  s32 v14;
  struct System_Byte_array_array_array *v22;
  System_Byte_array_array *v24;
  System_Byte_array *v25;
  struct System_Byte_array_array_array *v29;
  System_Byte_array_array *v31;
  System_Byte_array *v32;
  s32 v34;
  struct System_Byte_array_array_array *v37;
  System_Byte_array_array *v39;
  s32 v41;
  System_Byte_array *v42;
  struct System_Byte_array_array_array *v45;
  System_Byte_array_array *v47;

  RandIntA = dds3GetRandIntA(0x64u, StringLiteral_21498);
  v7 = datNegoReqItemListB->m_Items[lv_idx];
  v8 = v7->m_Items[0];
  if (RandIntA < v8->m_Items[1])
    return 0;
  v10 = datNegoReqItemListB;
  v11 = v10->m_Items[lv_idx];
  v12 = v11->m_Items[0];
  v14 = v12->m_Items[1];
  v22 = datNegoReqItemListB;
  v24 = v22->m_Items[lv_idx];
  v25 = v24->m_Items[1];
  if (RandIntA < v14 + v25->m_Items[1])
    return 1;
  v29 = datNegoReqItemListB;
  v31 = v29->m_Items[lv_idx];
  v32 = v31->m_Items[1];
  v34 = v32->m_Items[1];
  v37 = datNegoReqItemListB;
  v39 = v37->m_Items[lv_idx];
  v41 = v14 + v34;
  v42 = v39->m_Items[2];
  if (RandIntA >= v41 + v42->m_Items[1])
  {
    v45 = datNegoReqItemListB;
    v47 = v45->m_Items[lv_idx];
    return 0;
  }
  return 2;
}

// 0x12179a0
void nbSetAllHojoSkillWork(nbNegoProcessData_t **n) {
  u64 v3;
  u64 i;
  s64 v5;
  struct nbParty_t_array *party;
  nbParty_t_o *v8;
  struct System_UInt16_array *hojoskill;
  struct nbParty_t_array *v11;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *v14;
  nbParty_t_o *v16;
  datUnitWork_t_o *UnitWorkPointer;
  u32 v19;
  s64 v20;
  u64 v22;
  struct System_Int32_array *skill;
  struct datSkill_t_array *tbl;
  s64 v26;
  struct System_Int32_array *v29;
  struct datNegoSkill_t_array *v30;
  s64 v32;
  struct nbParty_t_array *v34;
  struct System_Int32_array *v36;
  struct System_UInt16_array *v37;
  char *v40;
  s64 v41;

  v3 = 0;
  for (i = 0; ; i = 0)
  {
    while (1)
    {
      party = (*n)->data->party;
      v8 = party->m_Items[v3];
      if (i == 8)
        break;
      hojoskill = v8->hojoskill;
      v5 = hojoskill + 2 * i++;
      *(v5 + 32) = 0;
    }
    v8->flag &= ~0x80u;
    if (v3 <= 3)
    {
      v11 = (*n)->data->party;
      if ((v11->m_Items[v3]->flag & 1) != 0 && v3 != (*n)->ppartyindex)
      {
        data = (*n)->data;
        v14 = data->party;
        v16 = v14->m_Items[v3];
        UnitWorkPointer = nbGetUnitWorkPointer(data, v16);
        if (datCheckTalk(UnitWorkPointer) && UnitWorkPointer->skillcnt >= 1)
        {
          v19 = 0;
          v20 = 8;
          do
          {
            v22 = v20 - 8;
            skill = UnitWorkPointer->skill;
            v26 = *(&skill->obj.klass + v20);
            if (tbl->m_Items[v26]->type == 2)
            {
              v29 = UnitWorkPointer->skill;
              v30 = tbl;
              v32 = *(&v29->obj.klass + v20) - 384LL;
              if (v30->m_Items[v32]->type == 7)
              {
                v34 = (*n)->data->party;
                v36 = UnitWorkPointer->skill;
                v37 = v34->m_Items[v3]->hojoskill;
                v40 = v37 + 2 * v19++;
                *(v40 + 16) = *(&v36->obj.klass + v20);
              }
            }
            v41 = v20 - 7;
            ++v20;
          }
          while (v41 < UnitWorkPointer->skillcnt);
        }
      }
    }
    if (++v3 == 14)
      break;
  }
}

// 0x1215eb0
void nbSetMesItem(s32 msgid, s32 it) {
  itfMesMngSetVar(msgid, 2, it, 3);
}

// 0x1215e30
void nbSetMesMakka(s32 msgid, s32 i) {
  itfMesMngSetVar(msgid, 3, i, 0);
}

// 0x12161a0
void nbSetNegoMesVar(s32 msgid, datUnitWork_t **p, datUnitWork_t **e) {
  s32 id;
  s32 v9;
  datDevilFormat_t_o *v10;
  s32 v12;
  s32 v14;
  s32 v15;
  s32 race;

  id = (*e)->id;
  itfMesMngSetVar(msgid, 0, id, 1);
  v9 = (*e)->id;
  v10 = Get(v9, 1, 0);
  itfMesMngSetVar(msgid, 4, v10->race, 8);
  if (((*p)->flag & 4) != 0)
  {
    itfMesMngSetVar(msgid, 1, 0, 10);
    v15 = 0;
  }
  else
  {
    v12 = (*p)->id;
    itfMesMngSetVar(msgid, 1, v12, 1);
    v14 = (*p)->id;
    v15 = v14;
  }
  race = Get(v15, 1, 0)->race;
  itfMesMngSetVar(msgid, 5, race, 8);
}

// 0x121a010
s32 nbSetNegoNoMotion(nbNegoProcessData_t **n, nbFormation_t **form) {
  nbActionProcessData_t_o *v5;
  s32 msgwndid;
  nbFormation_t_o *v9;
  u32 NegoMIDI;

  v5 = Allocate(nbActionProcessData_t);
  nbActionProcessData_t___ctor(v5);
  msgwndid = (*n)->msgwndid;
  if ((msgwndid & 0x80000000) == 0)
  {
    itfMesMngMsgWndCls(msgwndid);
    (*n)->msgwndid = -1;
  }
  nbAddMotionKoukaPacket(0, v5->uniqueid, form, 15);
  v9 = *form;
  NegoMIDI = nbGetNegoMIDI(v9);
  nbAddSePacket2(0, v5->uniqueid, NegoMIDI + 1);
  return 15;
}

// 0x121a170
s32 nbSetNegoYesMotion(nbNegoProcessData_t **n, nbFormation_t **form) {
  nbActionProcessData_t_o *v5;
  s32 msgwndid;
  nbFormation_t_o *v9;
  u32 NegoMIDI;

  v5 = Allocate(nbActionProcessData_t);
  nbActionProcessData_t___ctor(v5);
  msgwndid = (*n)->msgwndid;
  if ((msgwndid & 0x80000000) == 0)
  {
    itfMesMngMsgWndCls(msgwndid);
    (*n)->msgwndid = -1;
  }
  nbAddMotionKoukaPacket(0, v5->uniqueid, form, 14);
  v9 = *form;
  NegoMIDI = nbGetNegoMIDI(v9);
  nbAddSePacket2(0, v5->uniqueid, NegoMIDI);
  return 15;
}
