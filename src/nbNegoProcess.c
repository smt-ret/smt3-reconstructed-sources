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
  void **v5;
  u32 *v6;
  Il2CppObject *result;

  switch (ekucyo)
  {
    case 0:
      switch (idx)
      {
        case 0:
          v5 = &boy_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &boy_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &boy_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &boy_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 1:
      switch (idx)
      {
        case 0:
          v5 = &girl_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &girl_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &girl_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &girl_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 2:
      switch (idx)
      {
        case 0:
          v5 = &lady_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &lady_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &lady_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &lady_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 3:
      switch (idx)
      {
        case 0:
          v5 = &witch_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &witch_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &witch_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &witch_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 4:
      switch (idx)
      {
        case 0:
          v5 = &heehaw_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &heehaw_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &heehaw_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &heehaw_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 5:
      switch (idx)
      {
        case 0:
          v5 = &beast_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &beast_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &beast_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &beast_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 6:
      switch (idx)
      {
        case 0:
          v5 = &gentle_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &gentle_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &gentle_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &gentle_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 7:
      switch (idx)
      {
        case 0:
          v5 = &punk_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &punk_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &punk_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &punk_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 8:
      switch (idx)
      {
        case 0:
          v5 = &oldman_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &oldman_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &oldman_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &oldman_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 9:
      switch (idx)
      {
        case 0:
          v5 = &oldwoman_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &oldwoman_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &oldwoman_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &oldwoman_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 10:
      switch (idx)
      {
        case 0:
          v5 = &load_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &load_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &load_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &load_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 11:
      switch (idx)
      {
        case 0:
          v5 = &manekata_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &manekata_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &manekata_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &manekata_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 12:
      switch (idx)
      {
        case 0:
          v5 = &heroine_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &heroine_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &heroine_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &heroine_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 13:
      switch (idx)
      {
        case 0:
          v5 = &samurai_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &samurai_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &samurai_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &samurai_info;
            goto LABEL_159;
          goto LABEL_161;
        default:
          result = 0;
          break;
      }
      break;
    case 14:
      switch (idx)
      {
        case 0:
          v5 = &thing_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &thing_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &thing_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &thing_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 15:
      switch (idx)
      {
        case 0:
          v5 = &yoju_flow;
            goto LABEL_161;
          goto LABEL_159;
        case 1:
          v5 = &yoju_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &yoju_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &yoju_info;
            goto LABEL_161;
          goto LABEL_159;
        default:
          result = 0;
          break;
      }
      break;
    case 16:
      switch (idx)
      {
        case 0:
          v5 = &devil_flow;
            goto LABEL_159;
          goto LABEL_161;
        case 1:
          v5 = &devil_aisyo;
            goto LABEL_161;
          goto LABEL_159;
        case 2:
          v5 = &devil_question;
            goto LABEL_161;
          goto LABEL_159;
        case 3:
          v5 = &devil_info;
            goto LABEL_161;
LABEL_159:
          if (!v6[54])
          {
            v6 = *v5;
          }
LABEL_161:
          result = **(v6 + 23);
          break;
        default:
          result = 0;
          break;
      }
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// 0x121aee0
nbNegoProcessData_t *InitNegoProcessData(nbActionProcessData_t **actdata, s32 pformindex, s32 eformindex, s32 negotype, u32 skillid) {
  u64 *v11;
  s32 v14;
  struct datNegoSkill_t_array *tbl;
  s64 v18;
  s32 v20;
  s32 v21;
  nbParty_t_o *PartyFromFormindex;
  u64 v23;
  s64 v24;
  u64 v26;
  nbParty_t_o *v27;
  u64 v29;
  s64 v30;
  u64 v32;
  s32 v33;
  s64 i;
  u64 v38;
  u64 v39;
  u64 v41;
  Il2CppObject *MsgList;
  s32 v45;
  u64 v47;
  s32 v49;
  Il2CppObject *v51;
  s32 v52;
  s64 v56;
  u64 v58;
  u64 v59;
  s64 v69;
  u64 v71;
  u64 v72;
  Il2CppObject *v83;
  s32 v84;
  s32 v87;
  s32 v90;
  s32 v94;
  s32 v98;

  v11 = Allocate(nbNegoProcessData_t);
  nbNegoProcessData_t___ctor(v11);
  v11[3] = *actdata;
  v11[2] = (*actdata)->data;
  switch (negotype)
  {
    case 0:
    case 6:
      v14 = 65543;
        goto LABEL_18;
      goto LABEL_5;
    case 1:
      v14 = 786433;
        goto LABEL_8;
      goto LABEL_17;
    case 2:
      v14 = 851969;
        goto LABEL_17;
      goto LABEL_8;
    case 3:
      v14 = 917505;
      {
LABEL_5:
      }
      goto LABEL_18;
    case 4:
      v14 = 983041;
        goto LABEL_17;
      goto LABEL_8;
    case 5:
      v14 = 1048577;
        goto LABEL_17;
LABEL_8:
LABEL_17:
      skillid = 384;
LABEL_18:
      *(v11 + 11) = v14;
      break;
    default:
      break;
  }
  *(v11 + 9) = negotype;
  *(v11 + 18) = -1;
  *(v11 + 21) = -1;
  *(v11 + 29) = -1;
  *(v11 + 148) = 0;
  v18 = skillid - 384LL;
  v20 = tbl->m_Items[v18]->type - 1;
  if (v20 > 5)
    v21 = 0;
  else
    v21 = dword_33CC774[v20];
  *(v11 + 46) = v21;
  *(v11 + 47) = skillid;
  v11[29] = nbGetUnitWorkFromFormindex(pformindex);
  PartyFromFormindex = nbGetPartyFromFormindex(pformindex);
  v23 = v11[2];
  v11[35] = PartyFromFormindex;
  v24 = *(v23 + 16);
  v26 = *(v24 + 8LL * pformindex + 32);
  v11[32] = v26;
  *(v11 + 62) = pformindex;
  *(v11 + 68) = *(v26 + 176);
  v11[30] = nbGetUnitWorkFromFormindex(eformindex);
  v27 = nbGetPartyFromFormindex(eformindex);
  v29 = v11[2];
  v11[36] = v27;
  v30 = *(v29 + 16);
  v32 = *(v30 + 8LL * eformindex + 32);
  v11[33] = v32;
  *(v11 + 63) = eformindex;
  *(v11 + 69) = *(v32 + 176);
  v33 = *(v11[29] + 20);
  *(v11 + 74) = Get(v33, 0)->kucyo;
  *(v11 + 75) = Get(*(v11[30] + 20), 0)->kucyo;
  for (i = 8; i != 39; ++i)
  {
    v38 = v11[43];
    v39 = i - 8;
    *(v38 + 4 * i) = -1;
    else if (!GetMsgList(v39, 0))
    {
      continue;
    }
    v41 = v11[43];
    MsgList = GetMsgList(v39, 0);
    v45 = itfMesMngInitialize(MsgList, 0, 0);
    *(v41 + 4 * i) = v45;
    v47 = v11[43];
    nbSetNegoMesVar(*(v47 + 4 * i), v11 + 29, v11 + 30);
  }
  v49 = *(v11 + 75);
  v51 = GetMsgList(v49, 2);
  v52 = itfMesMngInitialize(v51, 0, 0);
  *(v11 + 88) = v52;
  nbSetNegoMesVar(v52, v11 + 29, v11 + 30);
  v56 = 8;
  while (2)
  {
    v58 = v11[46];
    v59 = v56 - 8;
    *(v58 + 4 * v56) = -1;
    else if (GetMsgList(v59, 3))
    {
      goto LABEL_71;
    }
    if (++v56 != 39)
      continue;
    break;
  }
  v69 = 8;
  while (2)
  {
    v71 = v11[45];
    v72 = v69 - 8;
    *(v71 + 4 * v69) = -1;
    else if (GetMsgList(v72, 1))
    {
      goto LABEL_91;
    }
    if (++v69 != 39)
      continue;
    break;
  }
  v83 = tbl;
  v84 = itfMesMngInitialize(v83, 0, 0);
  *(v11 + 97) = v84;
  v87 = v84;
  nbSetNegoMesVar(v87, v11 + 29, v11 + 30);
  v90 = itfMesMngInitialize(tbl, 0, 0);
  *(v11 + 94) = v90;
  nbSetNegoMesVar(v90, v11 + 29, v11 + 30);
  v94 = itfMesMngInitialize(tbl, 0, 0);
  *(v11 + 95) = v94;
  nbSetNegoMesVar(v94, v11 + 29, v11 + 30);
  v98 = itfMesMngInitialize(tbl, 0, 0);
  *(v11 + 96) = v98;
  nbSetNegoMesVar(v98, v11 + 29, v11 + 30);
  return v11;
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
  nbNegoProcessData_t_o *v11;
  s64 selectcur;
  s32 result;
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
    v11 = *n;
    selectcur = v11->selectcur;
    if (anymax && selectcur == v11->nextkouhocnt)
    {
      v11->nextnegoid = anynextId;
    }
    else
    {
      nextkouho = v11->nextkouho;
      v11->nextnegoid = nextkouho->m_Items[selectcur];
    }
    return 1;
  }
  if (anymax)
  {
    v16 = anynextId;
    v17 = HIWORD(anynextId);
    if (DDS3_PADCHECK_REP(8))
    {
      if (v17 - 1 <= 0)
        v17 = 16;
      else
        --v17;
        goto LABEL_36;
LABEL_64:
      anynextId = v16 | (v17 << 16);
      goto LABEL_65;
    }
    if (DDS3_PADCHECK_REP(10))
    {
      if ((v17 + 1) < 0x11)
        ++v17;
      else
        v17 = 1;
        goto LABEL_64;
    }
    else
    {
      if (!DDS3_PADCHECK_REP(6))
      {
        v16 += DDS3_PADCHECK_REP(7);
          goto LABEL_64;
        goto LABEL_36;
      }
      if (v16 - 1 <= 1)
        v16 = 1;
      else
        --v16;
        goto LABEL_64;
    }
LABEL_36:
    goto LABEL_64;
  }
LABEL_65:
  v22 = DDS3_PADCHECK_TRIG(0);
  result = 0;
  if (v22)
  {
    v23 = *n;
    v24 = (*n)->nextkouho;
    v25 = (*n)->nextkouhocnt;
    RandIntA = dds3GetRandIntA(v25, "");
    v23->nextnegoid = v24->m_Items[RandIntA];
    return 1;
  }
  return result;
}

// 0x12147d0
void NegoDebugDraw(nbNegoProcessData_t **n) {
  u64 *v3;
  u32 nownegoid;
  System_String_o *v6;
  System_String_o *v7;
  System_String_o *v8;
  System_Object_array *v10;
  Il2CppObject *v12;
  System_Object_array *v13;
  Il2CppObject *v14;
  nbNegoProcessData_t_o *v16;
  s32 historyindex;
  s32 i;
  struct System_UInt32_array *history;
  struct System_Int32_array *historymes;
  u32 v22;
  System_String_array *v25;
  s64 *v26;
  s64 *v27;
  System_String_o *v29;
  System_String_o *v30;
  System_String_o *v31;
  s64 *v35;
  s64 *v36;
  struct System_Int32_array *v40;
  s64 *v42;
  s64 *v43;
  System_String_o *v47;
  System_Object_array *v49;
  Il2CppObject *v51;
  u32 nownegoid_low;

  nownegoid_low = 0;
  v3 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v3);
  nownegoid = (*n)->nownegoid;
  nownegoid_low = HIWORD(nownegoid);
  v6 = sub_232970(&nownegoid_low);
  nownegoid_low = LOWORD((*n)->nownegoid);
  v7 = sub_232970(&nownegoid_low);
  v8 = Concat_5271136("Now:", v6, "_", v7);
  v10 = Empty_string_();
  v12 = sdfDevPrintf(28928, 31584, 0xFFFF80u, 0, v8, v10);
  sdfDrawTagLink(v3, v12);
  v13 = Empty_string_();
  v14 = sdfDevPrintf(28928, 31872, 0xFFFF80u, 5, "HISTORY", v13);
  sdfDrawTagLink(v3, v14);
  v16 = *n;
  historyindex = (*n)->historyindex;
  for (i = 0; ; i += 96)
  {
    history = v16->history;
    historyindex = (historyindex + 1) % 14;
    historymes = v16->historymes;
    v22 = history->m_Items[historyindex];
    if (historymes->m_Items[historyindex])
    {
      v25 = NewSpecific(string, 6u);
      nownegoid_low = HIWORD(v22);
      v26 = sub_232970(&nownegoid_low);
      v27 = v26;
      v25->m_Items[0] = v27;
      v25->m_Items[1] = "_";
      nownegoid_low = v22;
      v35 = sub_232970(&nownegoid_low);
      v36 = v35;
      v25->m_Items[2] = v36;
      v25->m_Items[3] = "(";
      v40 = (*n)->historymes;
      v42 = sub_232970(&v40->m_Items[historyindex]);
      v43 = v42;
      v25->m_Items[4] = v43;
      v25->m_Items[5] = ")";
      v31 = Concat_5271600(v25);
    }
    else
    {
      nownegoid_low = HIWORD(v22);
      v29 = sub_232970(&nownegoid_low);
      nownegoid_low = v22;
      v30 = sub_232970(&nownegoid_low);
      v31 = Concat_5221536(v29, "_", v30);
    }
    v47 = v31;
    v49 = Empty_string_();
    v51 = sdfDevPrintf(28928, i + 31968, 0xFFFF80u, 0, v47, v49);
    sdfDrawTagLink(v3, v51);
    if (i == 1248)
      break;
    v16 = *n;
  }
}

// 0x1214e20
void NegoDebugSelectDraw(nbNegoProcessData_t **n) {
  System_String_array *v4;
  System_String_o *v5;
  System_Object_array *v6;
  System_String_array *v8;
  u32 nownegoid;
  s64 *v11;
  s64 *v12;
  s64 *v15;
  s64 *v16;
  System_String_o *v19;
  System_String_array *v21;
  Il2CppObject *v23;
  System_Object_array *v26;
  Il2CppObject *v28;
  u64 v29;
  s32 v30;
  s64 nextkouhocnt;
  struct System_UInt32_array *nextkouho;
  u32 anynextId;
  s32 v37;
  System_String_o *v38;
  System_String_o *v39;
  System_String_o *v40;
  System_Object_array *v42;
  Il2CppObject *v44;
  System_Object_array *v46;
  Il2CppObject *v48;
  System_Object_array *v49;
  Il2CppObject *v50;
  sdfDrawTag_t_o *aTag;
  u32 nownegoid_low;

  nownegoid_low = 0;
  aTag = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(aTag);
  if ((*n)->endid)
  {
    v4 = Empty_string_();
    v5 = "SELECT NEXT NEGO";
    v6 = v4;
  }
  else
  {
    v8 = NewSpecific(string, 5u);
    v8->m_Items[0] = "SELECT NEXT NEGO (";
    nownegoid = (*n)->nownegoid;
    nownegoid_low = HIWORD(nownegoid);
    v11 = sub_232970(&nownegoid_low);
    v12 = v11;
    v8->m_Items[1] = v12;
    v8->m_Items[2] = "_";
    nownegoid_low = LOWORD((*n)->nownegoid);
    v15 = sub_232970(&nownegoid_low);
    v16 = v15;
    v8->m_Items[3] = v16;
    v8->m_Items[4] = ")";
    v19 = Concat_5271600(v8);
    v21 = Empty_string_();
    v5 = v19;
    v6 = v21;
  }
  v23 = sdfDevPrintf(31232, 31872, 0xFFFF80u, 14, v5, v6);
  sdfDrawTagLink(aTag, v23);
  if (!(*n)->endid)
  {
    v29 = 0;
    v30 = 31232;
    nextkouhocnt = (*n)->nextkouhocnt;
      goto LABEL_51;
LABEL_49:
    while (1)
    {
LABEL_51:
      if (v29 >= anymax + nextkouhocnt)
        goto LABEL_73;
      nextkouho = (*n)->nextkouho;
      anynextId = nextkouho->m_Items[v29];
      else
      {
        if (anymax)
          goto LABEL_57;
      }
      v37 = 4 * (v29 == (*n)->selectcur);
      nownegoid_low = HIWORD(anynextId);
      v38 = sub_232970(&nownegoid_low);
      nownegoid_low = anynextId;
      v39 = sub_232970(&nownegoid_low);
      v40 = Concat_5221536(v38, "_", v39);
      v42 = Empty_string_();
      v44 = sdfDevPrintf(v30, 32064, 0xFFFF80u, v37, v40, v42);
      sdfDrawTagLink(aTag, v44);
      ++v29;
      v30 += 1152;
      nextkouhocnt = (*n)->nextkouhocnt;
        goto LABEL_49;
    }
  }
  v26 = Empty_string_();
  v28 = sdfDevPrintf(31232, 32064, 0xFFFF80u, 4, "END", v26);
  sdfDrawTagLink(aTag, v28);
LABEL_73:
  v46 = Empty_string_();
  v48 = sdfDevPrintf(31232, 32352, 0xFFFF80u, 0, "RR = ENTER", v46);
  sdfDrawTagLink(aTag, v48);
  v49 = Empty_string_();
  v50 = sdfDevPrintf(31232, 32448, 0xFFFF80u, 0, "RL = RANDOM", v49);
  sdfDrawTagLink(aTag, v50);
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
    goto LABEL_24;
  if ((v3->stat & 4) == 0)
  {
    else if ((itfMesMngGetPhase(nowmsgid) & 0x80000000) == 0)
    {
      return 0;
    }
    v8 = (*n)->nowmsgid;
    itfMesMngSetPhase(v8, 0);
    goto LABEL_23;
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
LABEL_23:
  v3 = *n;
LABEL_24:
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
  u64 *v3;
  u64 *v4;
  s64 v5;
  bool v7;
  s64 v8;
  s64 v9;
  u64 *v10;
  u32 v11;
  u64 v12;
  struct datInfoSelectTable_t_array *InfoSelectTable;
  struct System_Int16_array *flagcheck;
  s64 v18;
  s32 i;
  char *v22;
  u32 v23;
  s32 v25;
  s32 *v26;
  u32 RandIntA;
  s32 v29;
  u64 *v30;
  u64 *v32;
  u64 *v33;
  u64 *v34;
  s32 v36;
  u32 v37;
  s32 v38;
  s32 v39;

  v3 = NewSpecific(s32, 0x3Cu);
  v4 = NewSpecific(s32, 0x3Cu);
  v7 = infotype == 2;
  v8 = 30;
  if (v7)
    v9 = 30;
  else
    v9 = 0;
  v10 = v4;
  v11 = 0;
  v12 = v9;
  do
  {
    while (1)
    {
      flagcheck = InfoSelectTable->m_Items[v12]->flagcheck;
      if (!flagcheck->m_Items[0])
        break;
      ++v12;
      if (!--v8)
        goto LABEL_20;
    }
    v18 = v11;
    ++v11;
    *(v3 + v18 + 8) = v12++;
    --v8;
  }
  while (v8);
LABEL_20:
  for (i = 0; i != 30; ++i)
  {
    if (nbCheckSelectMesJoukenAri(v9 + i, v5) == 1)
    {
      v22 = v10 + 4 * v8;
      LODWORD(v8) = v8 + 1;
      *(v22 + 8) = v9 + i;
    }
  }
  if (!v8)
    goto LABEL_52;
  if (dds3GetRandIntA(0xAu, "nbGetInfoMsg") > 1)
  {
    RandIntA = dds3GetRandIntA(v8, "nbGetInfoMsg");
    v26 = v10 + RandIntA + 8;
    v25 = 1;
  }
  else
  {
LABEL_52:
    v23 = dds3GetRandIntA(v11, "nbGetInfoMsg");
    v25 = 0;
    v26 = v3 + v23 + 8;
  }
  v29 = *v26;
  v39 = v25;
  v30 = sub_8D3950(s32, &v39);
  v38 = v29;
  v32 = sub_8D3950(s32, &v38);
  Write_2930752("select info usemestype = {0:D} mesno ={1:D}\n", v30, v32);
  v37 = v11;
  v33 = sub_8D3950(s32, &v37);
  v36 = v8;
  v34 = sub_8D3950(s32, &v36);
  Write_2930752("normal_mesno = {0:D} jouken_mesno = {1:D}  \n", v33, v34);
  return v29;
}

// 0x121a2d0
s32 nbGetInnenNegoID(nbNegoProcessData_t **n) {
  s64 v3;
  s32 v4;
  u64 v6;
  struct datInnenNegoTable_t_array *InnenNegoTable;
  u64 max_length_low;
  s32 id;
  struct datInnenNegoTable_t_array *v12;
  s32 v15;
  struct datInnenNegoTable_t_array *v16;

  v3 = 4;
  v4 = -1;
  v6 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(InnenNegoTable->max_length);
    if (v6 >= max_length_low)
      return v4;
    else if (v6 >= max_length_low)
    {
      goto LABEL_12;
    }
    if (*(*(&InnenNegoTable->obj.klass + v3) + 16LL))
    {
      id = (*n)->pwork->id;
      v12 = InnenNegoTable;
      if (id == *(*(&v12->obj.klass + v3) + 18LL))
      {
        v15 = (*n)->ework->id;
        v16 = InnenNegoTable;
        if (v15 == *(*(&v16->obj.klass + v3) + 20LL))
          return v3 - 4;
      }
    }
    ++v3;
    v6 = v3 - 4;
      goto LABEL_6;
  }
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
  return ((dds3GetRandIntA(v9, "nbGetNegoKureHpA") + v8) * maxhp) / 100;
}

// 0x1216940
s32 nbGetNegoKureHpB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b) {
  s32 maxhp;

  maxhp = (*b)->maxhp;
  return ((dds3GetRandIntA(0xAu, "nbGetNegoKureHpB") + 10) * maxhp) / 100;
}

// 0x12165f0
s32 nbGetNegoKureMakkaA(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b) {
  s32 level;
  s32 v6;

  level = (*b)->level;
  v6 = 10 * (((((dds3GetRandIntA(0xAu, "nbGetNegoKureMakkaA") + 21) * level) * 0.8) + 5) / 10);
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

LABEL_7:
  level = (*b)->level;
  v7 = 10 * (((((dds3GetRandIntA(0xAu, "nbGetNegoKureMakkaA") + 21) * level) * 0.8) + 5) / 10);
  if (v7)
    v8 = v7;
  else
    v8 = 1;
  v9 = 1717986919LL * (((dds3GetRandIntA(0x14u, "nbGetNegoKureMakkaB") + 50) * v8) / 100 + 5);
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
  return ((dds3GetRandIntA(0x1Eu, "nbGetNegoKureMpA") + 10) * maxmp) / 100;
}

// 0x1216a80
s32 nbGetNegoKureMpB(nbNegoProcessData_t **n, datUnitWork_t **a, datUnitWork_t **b) {
  s32 maxmp;

  maxmp = (*b)->maxmp;
  return ((dds3GetRandIntA(0xAu, "nbGetNegoKureMpB") + 10) * maxmp) / 100;
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

  RandIntA = dds3GetRandIntA(0x64u, "nbGetNegoRequestType");
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

  RandIntA = dds3GetRandIntA(0x64u, "nbGetNegoTuikaRequestType");
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
  RandIntA = dds3GetRandIntA(0x64u, "nbGetNegoYaruItemA");
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
  RandIntA = dds3GetRandIntA(0x64u, "nbGetNegoYaruItemB");
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
  v8 = 1717986919LL * ((dds3GetRandIntA(4u, "nbGetNegoYaruMakkaA") + 5) * dropmakka + 5);
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

LABEL_7:
  level = (*b)->level;
  v7 = 10 * (((((dds3GetRandIntA(0xAu, "nbGetNegoKureMakkaA") + 21) * level) * 0.8) + 5) / 10);
  if (v7)
    v8 = v7;
  else
    v8 = 1;
  v9 = 1717986919LL * (((dds3GetRandIntA(0x1Eu, "nbGetNegoYaruMakkaB") + 40) * v8) / 100 + 5);
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
  RandIntA = dds3GetRandIntA(0x64u, "nbGetNegoYaruStone");
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
    RandIntA = dds3GetRandIntA(0x64u, "nbGetQuestionType");
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
        goto LABEL_57;
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
    if (dds3GetRandIntA(0x64u, "nbGetQuestionType") >= 80)
      goto LABEL_57;
  }
  else
  {
    if (dds3GetRandIntA(2u, "nbGetQuestionType"))
    {
LABEL_57:
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
        goto LABEL_120;
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
          goto LABEL_111;
        goto LABEL_130;
      }
      *(v3 + 9) = 30;
      if (v74 <= 2)
      {
LABEL_120:
      }
    }
    *(v3 + 10) = 70;
      goto LABEL_130;
    goto LABEL_111;
  }
  v66 = *(v3 + 6);
  *(v3 + 8) = 33;
  *(v3 + 9) = 33;
  *(v3 + 10) = 34;
  {
LABEL_111:
  }
LABEL_130:
  v76 = dds3GetRandIntA(0x64u, "nbGetQuestionType");
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
  target = dds3StartProcess("nb_nego", 0x3F9u, 1, 1, v14, 0, v15, 0, data, 0);
  dds3LinkProcess(&(*actdata)->data->MainProcessID, &target, 0);
  (*actdata)->data->NegoProcessID = target;
}

// 0x1213830
s32 nbMemoryLoadNegoSe(nbFormation_t *form) {
  return 0;
}

// 0x12142f0
void *nbNegoProcess1(dds3ProcessID_t *id) {
  nbActionProcessData_t_o *v2;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppObject *v11;
  nbNegoProcessData_t_o *v12;
  s32 waitframe;
  bool v14;
  s32 v15;
  u64 *v16;
  intptr_t *v17;
  u64 nownegoid;
  struct nbNegoProcess_flowDelegate_array *flow;
  u64 v22;
  s32 v24;
  nbNegoProcessData_t_o *v25;
  s32 nextkouhocnt;
  u64 v27;
  struct System_UInt32_array *v28;
  s32 v31;
  struct System_UInt32_array *history;
  struct System_Int32_array *historymes;
  s64 historyindex;
  u32 nextnegoid;
  struct System_UInt32_array *nextkouho;
  nbNegoProcessData_t_o *n;
  dds3ProcessID_t_o *ida;
  u64 v42[3];

  ida = id;
  n = 0;
  v2 = Allocate(nbActionProcessData_t);
  nbActionProcessData_t___ctor(v2);
  else
  {
    ProcessData = dds3GetProcessData(&ida);
    if (ProcessData)
    {
LABEL_6:
      klass = ProcessData->klass;
      if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbNegoProcessData_t)
      {
        sub_8FC2C0(klass->_1.element_class, nbNegoProcessData_t, v42);
        if ((v42[0] & 1) != 0)
          v7 = v42[2];
        else
          v7 = v42 + 1;
        v8 = sub_8C4940(v7);
      }
    }
  }
  n = ProcessData;
  v11 = 0;
  if (nbGetUniqueIdKoukaPacketCnt(v2->uniqueid) > 0)
    return v11;
  v12 = n;
  waitframe = n->waitframe;
  v14 = __OFSUB__(waitframe, 1);
  v15 = waitframe - 1;
  if (v15 < 0 == v14)
  {
    v11 = 0;
    n->waitframe = v15;
    return v11;
  }
  if ((n->nowmsgid & 0x80000000) == 0)
  {
LABEL_18:
    v16 = Allocate(System_Func_dds3ProcessID_t__object_);
    v17 = &Method_nbNegoProcess_nbNegoProcessMessage__;
    goto LABEL_19;
  }
  if ((n->data->stat & 0x400000) != 0)
  {
    NegoDebugDraw(&n);
    v12 = n;
  }
  while (1)
  {
    if ((v12->stat & 1) != 0)
    {
      NegoDebugSelectDraw(&n);
      if (NegoDebug(&n))
        n->stat &= ~1u;
    }
    else if (v12->endid != 1 && !v12->nextnegoid)
    {
      *&v12->nextnegoid = 0;
      nownegoid = v12->nownegoid;
      v22 = nownegoid >> 16;
      v24 = Invoke(flow->m_Items[v22], &n);
      v25 = n;
      ++n->nownegophase;
      if (v24)
      {
        v25->endid = 1;
        v25->endtype = v24;
      }
      if (v25->nextnegoid)
        goto LABEL_73;
      if (v25->nextkouhocnt >= 1)
      {
        nextkouho = v25->nextkouho;
        v25->nextnegoid = nextkouho->m_Items[0];
        if (v25->nextnegoid)
        {
LABEL_73:
          if ((v25->data->stat & 0x400000) != 0)
          {
            v25->stat |= 1u;
            nextkouhocnt = v25->nextkouhocnt;
            v25->selectcur = 0;
            if (nextkouhocnt >= 1)
            {
              v27 = 0;
              while (1)
              {
                v28 = v25->nextkouho;
                if (v28->m_Items[v27] == v25->nextnegoid)
                  break;
                if (++v27 >= v25->nextkouhocnt)
                  goto LABEL_50;
              }
              v25->selectcur = v27;
            }
          }
        }
      }
    }
LABEL_50:
    if (nbGetUniqueIdKoukaPacketCnt(v2->uniqueid) > 0)
      return 0;
    v12 = n;
    if (n->waitframe > 0)
      return 0;
    if ((n->nowmsgid & 0x80000000) == 0)
      goto LABEL_18;
    if ((n->stat & 1) == 0)
      break;
LABEL_61:
    v11 = 0;
    if ((v12->data->stat & 0x400000) != 0)
      return v11;
  }
  if (n->endid != 1)
  {
    if (n->nextnegoid)
    {
      v31 = (n->historyindex + 1) % 14;
      history = n->history;
      n->historyindex = v31;
      history->m_Items[v31] = v12->nownegoid;
      historymes = n->historymes;
      historyindex = n->historyindex;
      historymes->m_Items[historyindex] = n->nowmes;
      v12 = n;
      nextnegoid = n->nextnegoid;
      *&n->nownegophase = 0;
      v12->nownegoid = nextnegoid;
      v12->nextkouhocnt = 0;
      v12->nowmes = 0;
    }
    goto LABEL_61;
  }
  v16 = Allocate(System_Func_dds3ProcessID_t__object_);
  v17 = &Method_nbNegoProcess_nbNegoProcessEnd__;
LABEL_19:
  v11 = v16;
  object____ctor(v16, 0, *v17);
  return v11;
}

// 0x121a930
void *nbNegoProcessEnd(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3ProcessID_t_o *v8[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  ProcessData = dds3GetProcessData(&ida);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbNegoProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbNegoProcessData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  HIDWORD(ProcessData[1].klass->_1.interfaceOffsets) = HIDWORD(ProcessData[11].klass);
  ida->func_ans = -1;
  return 0;
}

// 0x121a6b0
void *nbNegoProcessMessage(dds3ProcessID_t *id) {
  nbNegoProcessData_t_o *ProcessData;
  nbNegoProcessData_t_c *v3;
  nbNegoProcessData_t_o *v4;
  nbNegoProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s32 msgwndid;
  s32 nowmsgid;
  s32 v12;
  s32 nowmsgno;
  u64 *v14;
  nbNegoProcessData_t_o *n;
  dds3ProcessID_t_o *ida;
  u64 v18[3];

  ida = id;
  n = 0;
  ProcessData = dds3GetProcessData(&ida);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbNegoProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbNegoProcessData_t, v18);
      if ((v18[0] & 1) != 0)
        v7 = v18[2];
      else
        v7 = v18 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  n = ProcessData;
  if ((ProcessData->data->stat & 0x400000) != 0)
  {
    NegoDebugDraw(&n, v3);
  }
  msgwndid = v4->msgwndid;
  if ((msgwndid & 0x80000000) == 0 && msgwndid != v4->nowmsgid)
  {
    itfMesMngMsgWndCls(msgwndid);
    v4->msgwndid = -1;
  }
  nowmsgid = v4->nowmsgid;
  itfMesMngMarkBitStat(nowmsgid, 0x200000u);
  v12 = v4->nowmsgid;
  nowmsgno = v4->nowmsgno;
  if ((v4->stat & 4) != 0)
  {
    itfMesMngRequestSelect(v12, nowmsgno);
  }
  else
  {
    itfMesMngRequestMessage(v12, nowmsgno, 0, 0);
  }
  v4->msgwndid = v4->nowmsgid;
  v14 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v14,
    0,
    Method_nbNegoProcess_nbNegoProcessMessageChk__);
  return v14;
}

// 0x121a4a0
void *nbNegoProcessMessageChk(dds3ProcessID_t *id) {
  nbNegoProcessData_t_o *ProcessData;
  nbNegoProcessData_t_c *v3;
  nbNegoProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *v9;
  nbNegoProcessData_t_o *v12;
  dds3ProcessID_t_o *v13[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  v12 = 0;
  else
  {
    ProcessData = dds3GetProcessData(&ida);
    if (!ProcessData)
      goto LABEL_12;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbNegoProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbNegoProcessData_t, v13);
    if ((v13[0] & 1) != 0)
      v6 = v13[2];
    else
      v6 = v13 + 1;
    v7 = sub_8C4940(v6);
  }
LABEL_12:
  v12 = ProcessData;
  if ((ProcessData->data->stat & 0x400000) != 0)
  {
    NegoDebugDraw(&v12, v3);
  }
  if (!nbCheckNegoMessage(&v12))
    return 0;
LABEL_20:
  Write("msg end\n", 0);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_nbNegoProcess_nbNegoProcess1__);
  return v9;
}

// 0x121aa60
void *nbNegoShutdown(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s64 i;
  u32 *monitor;
  u64 v11;
  u32 *v13;
  s32 v15;
  u32 *v16;
  s32 v18;
  s64 j;
  Il2CppClass *v20;
  u64 v21;
  Il2CppClass *v23;
  s32 v25;
  Il2CppClass *v26;
  s64 k;
  u32 *v29;
  u64 v30;
  u32 *v32;
  s32 v34;
  u32 *v35;
  s32 klass_high;
  s32 v38;
  s32 monitor_high;
  s32 v40;
  Il2CppClass *v41;
  dds3ProcessID_t_o *v44;
  u64 v45[3];

  v44 = id;
  ProcessData = dds3GetProcessData(&v44);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbNegoProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbNegoProcessData_t, v45);
      if ((v45[0] & 1) != 0)
        v7 = v45[2];
      else
        v7 = v45 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  for (i = 8; i != 39; ++i)
  {
    monitor = v4[21].monitor;
    v11 = i - 8;
    if ((monitor[i] & 0x80000000) == 0)
    {
      v13 = v4[21].monitor;
      v15 = v13[i];
      itfMesMngRelease(v15);
      v16 = v4[21].monitor;
      v16[i] = -1;
    }
  }
  v18 = v4[22].klass;
  if ((v18 & 0x80000000) == 0)
  {
    itfMesMngRelease(v18);
    LODWORD(v4[22].klass) = -1;
  }
  for (j = 8; j != 39; ++j)
  {
    v20 = v4[23].klass;
    v21 = j - 8;
    if ((*(&v20->_1.image + j) & 0x80000000) == 0)
    {
      v23 = v4[23].klass;
      v25 = *(&v23->_1.image + j);
      itfMesMngRelease(v25);
      v26 = v4[23].klass;
      *(&v26->_1.image + j) = -1;
    }
  }
  for (k = 8; k != 39; ++k)
  {
    v29 = v4[22].monitor;
    v30 = k - 8;
    if ((v29[k] & 0x80000000) == 0)
    {
      v32 = v4[22].monitor;
      v34 = v32[k];
      itfMesMngRelease(v34);
      v35 = v4[22].monitor;
      v35[k] = -1;
    }
  }
  klass_high = HIDWORD(v4[24].klass);
  if ((klass_high & 0x80000000) == 0)
  {
    itfMesMngRelease(klass_high);
    HIDWORD(v4[24].klass) = -1;
  }
  v38 = v4[23].monitor;
  if ((v38 & 0x80000000) == 0)
  {
    itfMesMngRelease(v38);
    LODWORD(v4[23].monitor) = -1;
  }
  monitor_high = HIDWORD(v4[23].monitor);
  if ((monitor_high & 0x80000000) == 0)
  {
    itfMesMngRelease(monitor_high);
    HIDWORD(v4[23].monitor) = -1;
  }
  v40 = v4[24].klass;
  if ((v40 & 0x80000000) == 0)
  {
    itfMesMngRelease(v40);
    LODWORD(v4[24].klass) = -1;
  }
  v41 = v4[1].klass;
  if (v41->vtable[3].methodPtr)
    v41->vtable[3].methodPtr = 0;
  p2sdBGMVolHalfUp();
  WindowDispOff(0);
  return 0;
}

// 0x1217eb0
u32 nbSearchHojoSkillWork(nbNegoProcessData_t **n, s32 type) {
  u64 *v4;
  struct nbParty_t_array *party;
  u64 *v7;
  s64 v9;
  struct nbParty_t_array *v11;
  u64 *v12;
  char *v15;
  struct nbParty_t_array *v16;
  char *v19;
  struct nbParty_t_array *v20;
  u64 *v22;
  u64 v24;
  char *v25;
  s64 v26;
  s32 *v27;
  u64 v28;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *v33;
  s64 v35;
  nbParty_t_o *v37;
  u64 v38;
  datUnitWork_t_o *UnitWorkPointer;
  struct nbParty_t_array *v40;
  datUnitWork_t_o *v41;
  s64 v43;
  datUnitWork_t_o *v46;
  s32 Param;
  u64 v48;
  s32 v49;
  u64 v51;
  struct nbParty_t_array *v52;
  char *v54;
  s64 v55;
  u32 *v56;
  s64 v57;
  nbParty_t_o *v59;
  nbMainProcessData_t_o *v60;
  datUnitWork_t_o *v61;
  signed s32 v62;
  s64 v63;
  struct System_UInt16_array *hojoskill;
  u64 v65;
  struct System_UInt16_array *v67;
  struct System_UInt16_array *v69;
  s32 v71;
  s32 id;
  s32 race;
  u32 RandIntA;
  struct System_UInt16_array *v79;
  s32 v80;
  struct System_UInt16_array *v81;
  struct System_UInt16_array *v83;
  struct System_UInt16_array *v85;
  struct System_UInt16_array *v86;
  struct System_UInt16_array *v88;
  struct System_UInt16_array *v90;
  struct System_UInt16_array *v91;
  struct System_UInt16_array *v94;
  struct System_UInt16_array *v97;
  struct System_UInt16_array *v100;
  struct System_UInt16_array *v101;
  struct System_UInt16_array *v103;
  struct System_UInt16_array *v105;
  struct System_UInt16_array *v106;
  struct System_UInt16_array *v109;
  u64 *v113;
  s32 v114;
  s64 v115;
  datUnitWork_t_o *v116;
  s64 v117;
  u32 *v118;
  s64 v119;
  u64 v120;
  u64 *v121;

  v121 = NewSpecific(s32, 4u);
  v4 = NewSpecific(s32, 8u);
  party = (*n)->data->party;
  v7 = v4;
  if ((party->m_Items[0]->flag & 1) != 0 && (*n)->ppartyindex)
  {
    v9 = 1;
    *(v121 + 8) = 0;
  }
  else
  {
    v9 = 0;
  }
  v11 = (*n)->data->party;
  if ((v11->m_Items[1]->flag & 1) != 0)
  {
    v12 = v121;
    if ((*n)->ppartyindex != 1)
    {
      v15 = v121 + 4 * v9;
      v9 = (v9 + 1);
      *(v15 + 8) = 1;
    }
  }
  else
  {
    v12 = v121;
  }
  v16 = (*n)->data->party;
  if ((v16->m_Items[2]->flag & 1) != 0 && (*n)->ppartyindex != 2)
  {
    v19 = v12 + 4 * v9;
    v9 = (v9 + 1);
    *(v19 + 8) = 2;
  }
  v20 = (*n)->data->party;
  if ((v20->m_Items[3]->flag & 1) != 0 && (*n)->ppartyindex != 3)
  {
    v22 = v121;
    *(v121 + v9 + 8) = 3;
    v9 = (v9 + 1);
  }
  else
  {
    v22 = v121;
    if (!v9)
      return 0;
  }
  v119 = 1;
  v114 = type;
  if (v9 >= 2)
  {
    v24 = 0;
    v25 = v22 + 36;
    v26 = v9 - 1;
    v113 = v4;
    v115 = (v9 - 1);
    v117 = v9;
    do
    {
      v120 = v24 + 1;
      if ((v24 + 1) < v9)
      {
        v27 = v22 + v24 + 8;
        v28 = v24;
        do
        {
          data = (*n)->data;
          v33 = data->party;
          v35 = *v27;
          v37 = v33->m_Items[v35];
          v38 = v28 + 1;
          UnitWorkPointer = nbGetUnitWorkPointer(data, v37);
          v40 = (*n)->data->party;
          v41 = UnitWorkPointer;
          v43 = *&v25[4 * v28];
          v46 = nbGetUnitWorkPointer((*n)->data, v40->m_Items[v43], 0);
          Param = datGetParam(v41, 4);
          v22 = v121;
          if (Param < datGetParam(v46, 4))
          {
            v48 = *(v121 + 6);
            v49 = *v27;
            *v27 = *&v25[4 * v28];
            *&v25[4 * v28] = v49;
          }
          ++v28;
        }
        while (v26 != v28);
      }
      v9 = v117;
      ++v24;
    }
    while (v120 != v115);
    v7 = v113;
    type = v114;
    v119 = v117;
  }
  v51 = 0;
  while (1)
  {
    v52 = (*n)->data->party;
    v54 = v22 + 4 * v51;
    v57 = *(v54 + 8);
    v56 = v54 + 32;
    v55 = v57;
    v59 = v52->m_Items[v55];
    v60 = (*n)->data;
    v61 = nbGetUnitWorkPointer(v60, v59);
    v22 = v121;
    if ((v59->flag & 0x80) == 0)
      break;
LABEL_111:
    if (++v51 >= v119)
      return 0;
  }
  v62 = 0;
  v63 = 16;
  v116 = v61;
  v118 = v56;
  while (2)
  {
    hojoskill = v59->hojoskill;
    v65 = v63 - 16;
    if (!*(&hojoskill->obj.klass + v63))
      goto LABEL_99;
    v67 = v59->hojoskill;
    if (*(&v67->obj.klass + v63) < 0)
      goto LABEL_99;
    v69 = v59->hojoskill;
    v71 = *(&v69->obj.klass + v63);
    switch (type)
    {
      case 0:
        if (v71 != 409)
          goto LABEL_99;
        goto LABEL_96;
      case 1:
        if (v71 == 410 || (v71 & 0xFFFE) == 0x1A2)
          goto LABEL_96;
        goto LABEL_99;
      case 2:
        if (v71 != 419 && v71 != 411)
          goto LABEL_99;
        goto LABEL_96;
      case 3:
        if ((v71 - 412) > 8)
          goto LABEL_99;
        if (((1 << (v71 + 100)) & 0x1BE) != 0)
        {
LABEL_96:
          *(v7 + v62 + 8) = v71;
          v22 = v121;
          ++v62;
          goto LABEL_99;
        }
        if (v71 != 412)
        {
LABEL_99:
          if (++v63 == 24)
            goto LABEL_110;
          continue;
        }
        id = v116->id;
        race = Get(id, 1, 0)->race;
        if (race == Get((*n)->ework->id, 1, 0)->race)
        {
          *(v7 + v62++ + 8) = v71;
        }
        v22 = v121;
        type = v114;
        if (++v63 != 24)
          continue;
LABEL_110:
        if (v62 < 1)
          goto LABEL_111;
        RandIntA = dds3GetRandIntA(v62, "nbSearchHojoSkillWork");
        v79 = v59->hojoskill;
        v80 = *(v7 + RandIntA + 8);
        if (v80 == v79->m_Items[0])
        {
          v81 = v59->hojoskill;
          v81->m_Items[0] |= 0x8000u;
          v83 = v59->hojoskill;
          if ((v83->max_length & 0xFFFFFFFE) == 0)
          {
LABEL_123:
          }
        }
        else
        {
          v83 = v59->hojoskill;
          if ((v83->max_length & 0xFFFFFFFE) == 0)
            goto LABEL_123;
        }
        if (v80 == v83->m_Items[1])
        {
          v94 = v59->hojoskill;
          v94->m_Items[1] |= 0x8000u;
          v85 = v59->hojoskill;
          if (LODWORD(v85->max_length) <= 2uLL)
          {
LABEL_141:
          }
        }
        else
        {
          v85 = v59->hojoskill;
          if (LODWORD(v85->max_length) <= 2uLL)
            goto LABEL_141;
        }
        if (v80 == v85->m_Items[2])
        {
          v86 = v59->hojoskill;
          v86->m_Items[2] |= 0x8000u;
          v88 = v59->hojoskill;
          if ((v88->max_length & 0xFFFFFFFC) == 0)
          {
LABEL_129:
          }
        }
        else
        {
          v88 = v59->hojoskill;
          if ((v88->max_length & 0xFFFFFFFC) == 0)
            goto LABEL_129;
        }
        if (v80 == v88->m_Items[3])
        {
          v97 = v59->hojoskill;
          v97->m_Items[3] |= 0x8000u;
          v90 = v59->hojoskill;
          if (LODWORD(v90->max_length) <= 4uLL)
          {
LABEL_147:
          }
        }
        else
        {
          v90 = v59->hojoskill;
          if (LODWORD(v90->max_length) <= 4uLL)
            goto LABEL_147;
        }
        if (v80 == v90->m_Items[4])
        {
          v91 = v59->hojoskill;
          v91->m_Items[4] |= 0x8000u;
        }
        v100 = v59->hojoskill;
        if (v80 == v100->m_Items[5])
        {
          v101 = v59->hojoskill;
          v101->m_Items[5] |= 0x8000u;
          v103 = v59->hojoskill;
          if (LODWORD(v103->max_length) <= 6uLL)
          {
LABEL_153:
          }
        }
        else
        {
          v103 = v59->hojoskill;
          if (LODWORD(v103->max_length) <= 6uLL)
            goto LABEL_153;
        }
        if (v80 == v103->m_Items[6])
        {
          v109 = v59->hojoskill;
          v109->m_Items[6] |= 0x8000u;
          v105 = v59->hojoskill;
          if ((v105->max_length & 0xFFFFFFF8) == 0)
          {
LABEL_165:
          }
        }
        else
        {
          v105 = v59->hojoskill;
          if ((v105->max_length & 0xFFFFFFF8) == 0)
            goto LABEL_165;
        }
        if (v80 == v105->m_Items[7])
        {
          v106 = v59->hojoskill;
          v106->m_Items[7] |= 0x8000u;
        }
        v59->flag |= 0x80u;
        return v80 | (*v118 << 16);
      default:
        goto LABEL_99;
    }
  }
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

  RandIntA = dds3GetRandIntA(0x64u, "nbSelectKureItemA");
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

  RandIntA = dds3GetRandIntA(0x64u, "nbSelectKureItemB");
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
LABEL_7:
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
LABEL_7:
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
