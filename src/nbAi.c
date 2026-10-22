#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbActionProcessData_t nbActionProcessData_t;
typedef struct nbAi_nbaifunc_t nbAi_nbaifunc_t;
typedef struct nbAi_nbaifunc_t_funcDelegate nbAi_nbaifunc_t_funcDelegate;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbParty_t nbParty_t;

struct nbAi_nbaifunc_t {
    nbAi_nbaifunc_t_funcDelegate *func;
};

static nbAi_nbaifunc_t *nbaifunc[29];

s32 AiChk(nbActionProcessData_t **a, s32 n);
s32 ChkAiHojo(s32 formindex, s32 n);
s32 ChkAiHojoMax(s32 formindex, s32 n);
s32 ChkClose(nbActionProcessData_t **a);
s32 ChkCost(nbActionProcessData_t **a);
u8 Get(s32 id);
s32 GetKoudou(nbActionProcessData_t **a, s32 tbl);
s32 Sel_AI(nbActionProcessData_t **a, s32 n, s32 gr);
void Sel_BAARLV(nbActionProcessData_t **a, s32 n);
void Sel_BAD(nbActionProcessData_t **a, s32 n);
void Sel_DARK(nbActionProcessData_t **a, s32 n);
void Sel_ID(nbActionProcessData_t **a, s32 n);
void Sel_JOKEN(nbActionProcessData_t **a, s32 n);
void Sel_LIFEMIN(nbActionProcessData_t **a, s32 n);
void Sel_LIGHT(nbActionProcessData_t **a, s32 n);
void Sel_LVMIN(nbActionProcessData_t **a, s32 n);
void Sel_PLAYER(nbActionProcessData_t **a, s32 n);
s32 SetGroupTarget2(nbActionProcessData_t **a, s32 code, s32 n);
void SetKoudou(nbActionProcessData_t **a, s32 tbl, s32 kou);
s32 SetSingleTarget2(nbActionProcessData_t **a, s32 code, s32 n);
s32 datGet3Zokusei(datUnitWork_t *work);
u32 datGetAisyo(datUnitWork_t *work, s32 attr);
s32 datGetPlayerLevel(void);
u32 dds3GetRandIntA(u32 aLimit, char *name);
s32 nbAiChkJoken(nbActionProcessData_t **a, u32 jo);
s32 nbCheckSkillCost(s32 formindex, s32 nskill);
s32 nbCheckSkillUse(s32 formindex, s32 nskill);
s32 nbGetLvAvg(nbMainProcessData_t *data, s32 side);
nbParty_t *nbGetPartyFromFormindex(s32 formindex);
u32 nbGetSelectBit(nbMainProcessData_t *data);
void nbGetTargetTypeRuleArea(nbActionProcessData_t *a, datUnitWork_t *work, s32 *ctype, s32 *crule, s32 *carea, s32 rev);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
datUnitWork_t *nbGetUnitWorkPointer(nbMainProcessData_t *data, nbParty_t *party);
s32 nbGetVirtualAisyo(s32 nskill, s32 sformindex, s32 dformindex);
s32 nbGetVirtualKoukaPoint(s32 nskill, s32 sformindex, s32 dformindex);
s32 nbRunAiSub(nbActionProcessData_t **a, s32 tbl);
s32 nbSetAiTarget(nbActionProcessData_t **a, s32 code, s32 n);
s32 nbSetEnemySummonFormation(nbMainProcessData_t **data, s32 devilid);
void nbSetNormalSkill0(datUnitWork_t *work);
s32 nbSetSelectOkMark(s32 partyindex, s32 ctype, s32 crule, s32 carea);

// 0xfa19d0
s32 AiChk(nbActionProcessData_t **a, s32 n) {
  s32 id;
  struct datDevilAIChk_s_array *aichk;
  s64 v7;
  struct System_UInt32_array *check;
  u32 v11;
  struct datDevilAIChk_s_array *v14;
  struct System_UInt32_array *v16;
  u32 v18;
  s32 result;
  s32 formindex;
  nbParty_t_o *PartyFromFormindex;
  struct System_Int16_array *count;

  (*a)->aiselect = 0;
  id = (*a)->work->id;
  aichk = Get(id, 0)->aichk;
  v7 = n;
  check = aichk->m_Items[n]->check;
  v11 = check->m_Items[0];
  v14 = Get((*a)->work->id, 0)->aichk;
  v16 = v14->m_Items[n]->check;
  v18 = v16->m_Items[1];
  (*a)->aijokentbl = n;
  result = nbAiChkJoken(a, v11);
  if (result)
  {
    result = nbAiChkJoken(a, v18);
    if (result)
    {
      if ((v11 & 0xFFFF0000) == 0x40000 || (v18 & 0xFFFF0000) == 0x40000)
      {
        formindex = (*a)->form->formindex;
        PartyFromFormindex = nbGetPartyFromFormindex(formindex);
        if (PartyFromFormindex)
        {
          count = PartyFromFormindex->count;
          count->m_Items[v7 + 1] = 0;
        }
      }
      return 1;
    }
  }
  return result;
}

// 0xf9e990
s32 ChkAiHojo(s32 formindex, s32 n) {
  nbParty_t_o *PartyFromFormindex;
  struct System_Int16_array *count;
  s32 v7;
  struct System_Int16_array *v8;
  struct System_Int16_array *v10;
  struct System_Int16_array *v12;
  struct System_Int16_array *v14;
  struct System_Int16_array *v16;
  struct System_Int16_array *v18;
  struct System_Int16_array *v20;
  struct System_Int16_array *v22;
  struct System_Int16_array *v24;
  struct System_Int16_array *v26;
  struct System_Int16_array *v28;
  struct System_Int16_array *v30;
  struct System_Int16_array *v32;
  struct System_Int16_array *v34;
  struct System_Int16_array *v36;
  struct System_Int16_array *v38;

  LODWORD(PartyFromFormindex) = 0;
  switch (n)
  {
    case 0:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        count = PartyFromFormindex->count;
        v7 = count->m_Items[4];
        goto LABEL_155;
      }
      break;
    case 1:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v8 = PartyFromFormindex->count;
        LODWORD(PartyFromFormindex) = v8->m_Items[4] >> 15;
      }
      break;
    case 2:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v10 = PartyFromFormindex->count;
        v7 = v10->m_Items[5];
        goto LABEL_155;
      }
      break;
    case 3:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v12 = PartyFromFormindex->count;
        LODWORD(PartyFromFormindex) = v12->m_Items[5] >> 15;
      }
      break;
    case 4:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v14 = PartyFromFormindex->count;
        v7 = v14->m_Items[6];
        goto LABEL_155;
      }
      break;
    case 5:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v16 = PartyFromFormindex->count;
        LODWORD(PartyFromFormindex) = v16->m_Items[6] >> 15;
      }
      break;
    case 6:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v18 = PartyFromFormindex->count;
        v7 = v18->m_Items[7];
        goto LABEL_155;
      }
      break;
    case 7:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v20 = PartyFromFormindex->count;
        LODWORD(PartyFromFormindex) = v20->m_Items[7] >> 15;
      }
      break;
    case 8:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v22 = PartyFromFormindex->count;
        v7 = v22->m_Items[8];
        goto LABEL_155;
      }
      break;
    case 9:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v24 = PartyFromFormindex->count;
        LODWORD(PartyFromFormindex) = v24->m_Items[8] >> 15;
      }
      break;
    case 11:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v26 = PartyFromFormindex->count;
        v7 = v26->m_Items[9];
        goto LABEL_155;
      }
      break;
    case 12:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v28 = PartyFromFormindex->count;
        v7 = v28->m_Items[10];
        goto LABEL_155;
      }
      break;
    case 13:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v30 = PartyFromFormindex->count;
        v7 = v30->m_Items[11];
        goto LABEL_155;
      }
      break;
    case 14:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v32 = PartyFromFormindex->count;
        v7 = v32->m_Items[12];
        goto LABEL_155;
      }
      break;
    case 15:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v34 = PartyFromFormindex->count;
        v7 = v34->m_Items[13];
        goto LABEL_155;
      }
      break;
    case 16:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v36 = PartyFromFormindex->count;
        v7 = v36->m_Items[14];
        goto LABEL_155;
      }
      break;
    case 17:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v38 = PartyFromFormindex->count;
        v7 = v38->m_Items[15];
LABEL_155:
        LODWORD(PartyFromFormindex) = v7 > 0;
      }
      break;
    default:
      return PartyFromFormindex;
  }
  return PartyFromFormindex;
}

// 0xf9f250
s32 ChkAiHojoMax(s32 formindex, s32 n) {
  nbParty_t_o *PartyFromFormindex;
  struct System_Int16_array *count;
  bool v7;
  struct System_Int16_array *v8;
  s32 v10;
  struct System_Int16_array *v11;
  struct System_Int16_array *v13;
  struct System_Int16_array *v15;
  struct System_Int16_array *v17;
  struct System_Int16_array *v19;
  struct System_Int16_array *v21;
  struct System_Int16_array *v23;
  struct System_Int16_array *v25;
  struct System_Int16_array *v27;
  s32 v29;
  struct System_Int16_array *v30;
  struct System_Int16_array *v32;
  struct System_Int16_array *v34;
  struct System_Int16_array *v36;
  struct System_Int16_array *v38;
  struct System_Int16_array *v40;

  LODWORD(PartyFromFormindex) = 0;
  switch (n)
  {
    case 0:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        count = PartyFromFormindex->count;
        v7 = count->m_Items[4] <= 3;
        goto LABEL_157;
      }
      break;
    case 1:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v8 = PartyFromFormindex->count;
        v10 = v8->m_Items[4];
        goto LABEL_92;
      }
      break;
    case 2:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v11 = PartyFromFormindex->count;
        v7 = v11->m_Items[5] <= 3;
        goto LABEL_157;
      }
      break;
    case 3:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v13 = PartyFromFormindex->count;
        v10 = v13->m_Items[5];
        goto LABEL_92;
      }
      break;
    case 4:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v15 = PartyFromFormindex->count;
        v7 = v15->m_Items[6] <= 3;
        goto LABEL_157;
      }
      break;
    case 5:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v17 = PartyFromFormindex->count;
        v10 = v17->m_Items[6];
        goto LABEL_92;
      }
      break;
    case 6:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v19 = PartyFromFormindex->count;
        v7 = v19->m_Items[7] <= 3;
        goto LABEL_157;
      }
      break;
    case 7:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v21 = PartyFromFormindex->count;
        v10 = v21->m_Items[7];
        goto LABEL_92;
      }
      break;
    case 8:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v23 = PartyFromFormindex->count;
        v7 = v23->m_Items[8] <= 3;
        goto LABEL_157;
      }
      break;
    case 9:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v25 = PartyFromFormindex->count;
        v10 = v25->m_Items[8];
LABEL_92:
        LODWORD(PartyFromFormindex) = v10 < -3;
      }
      break;
    case 11:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v27 = PartyFromFormindex->count;
        v29 = v27->m_Items[9];
        goto LABEL_156;
      }
      break;
    case 12:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v30 = PartyFromFormindex->count;
        v29 = v30->m_Items[10];
        goto LABEL_156;
      }
      break;
    case 13:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v32 = PartyFromFormindex->count;
        v29 = v32->m_Items[11];
        goto LABEL_156;
      }
      break;
    case 14:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v34 = PartyFromFormindex->count;
        v29 = v34->m_Items[12];
        goto LABEL_156;
      }
      break;
    case 15:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v36 = PartyFromFormindex->count;
        v29 = v36->m_Items[13];
        goto LABEL_156;
      }
      break;
    case 16:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v38 = PartyFromFormindex->count;
        v29 = v38->m_Items[14];
        goto LABEL_156;
      }
      break;
    case 17:
      PartyFromFormindex = nbGetPartyFromFormindex(formindex);
      if (PartyFromFormindex)
      {
        v40 = PartyFromFormindex->count;
        v29 = v40->m_Items[15];
LABEL_156:
        v7 = v29 <= 0;
LABEL_157:
        LODWORD(PartyFromFormindex) = !v7;
      }
      break;
    default:
      return PartyFromFormindex;
  }
  return PartyFromFormindex;
}

// 0xfa3dd0
s32 ChkClose(nbActionProcessData_t **a) {
  struct datUnitWork_t_o *work;
  s32 nowcommand;
  s32 nowindex;
  s32 id;
  datDevilAI_t_o *v10;

  work = (*a)->work;
  nowcommand = work->nowcommand;
  if (work->nowcommand)
  {
    if (nowcommand != 5 && nowcommand != 1)
      return 1;
    nowindex = work->nowindex;
  }
  else
  {
    nowindex = 0;
  }
  if (nbCheckSkillUse((*a)->form->formindex, nowindex) >= 1)
  {
    id = (*a)->work->id;
    v10 = Get(id, 0);
    if (v10->ailevel)
      return v10->ailevel - 1 > 1;
  }
  return 1;
}

// 0xfa3cf0
s32 ChkCost(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v4;
  struct datUnitWork_t_o *work;
  s32 nowcommand;
  bool v7;
  s32 id;

  v4 = *a;
  work = (*a)->work;
  nowcommand = work->nowcommand;
  if (!work->nowcommand)
  {
    if (nbCheckSkillCost(v4->form->formindex, 0))
      goto LABEL_10;
    return 0;
  }
  v7 = nowcommand == 5 || nowcommand == 1;
  if (!v7 || !nbCheckSkillCost(v4->form->formindex, work->nowindex))
    return 0;
LABEL_10:
  id = (*a)->work->id;
  return Get(id, 0)->ailevel - 1 < 2;
}

// 0xfa03e0
s32 Chk_BA(nbActionProcessData_t **a, s32 n) {
  struct nbMainProcessData_t_o *data;
  u64 v5;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v8;
  struct nbParty_t_array *v10;
  struct nbParty_t_array *v12;
  struct nbParty_t_array *v14;

  data = (*a)->data;
  if ((data->stat & 0x10) == 0)
    return 0;
  v5 = 0;
  party = data->party;
  if (!LODWORD(party->max_length))
  {
LABEL_6:
  }
  while (1)
  {
    if ((party->m_Items[v5]->flag & 1) != 0)
    {
      v8 = (*a)->data->party;
      if ((v8->m_Items[v5]->flag & 8) == 0)
      {
        v10 = (*a)->data->party;
        if ((v10->m_Items[v5]->flag & 0x10) == 0)
        {
          v12 = (*a)->data->party;
          if ((v12->m_Items[v5]->flag & 0x20) == 0)
          {
            v14 = (*a)->data->party;
            (*a)->aiselect |= 1 << v14->m_Items[v5]->formindex;
          }
        }
      }
    }
    if (v5 == 3)
      return 1;
    ++v5;
    party = (*a)->data->party;
    if (v5 >= LODWORD(party->max_length))
      goto LABEL_6;
  }
}

// 0xf9d8d0
s32 Chk_CHKCNT(nbActionProcessData_t **a, s32 n) {
  s64 aijokentbl;
  s32 formindex;
  nbParty_t_o *PartyFromFormindex;
  s64 v9;
  struct System_Int16_array *count;
  s32 v12;
  s64 v13;
  s32 v14;
  nbParty_t_o *v15;
  struct System_Int16_array *v16;

  aijokentbl = (*a)->aijokentbl;
  formindex = (*a)->form->formindex;
  PartyFromFormindex = nbGetPartyFromFormindex(formindex);
  if (!PartyFromFormindex)
    goto LABEL_11;
LABEL_6:
  v9 = aijokentbl + 1;
  count = PartyFromFormindex->count;
  v12 = count->m_Items[v9];
  if (v12 <= 126)
    goto LABEL_12;
LABEL_13:
  v13 = (*a)->aijokentbl;
  v14 = (*a)->form->formindex;
  else
  {
    v15 = nbGetPartyFromFormindex(v14);
    if (!v15)
      goto LABEL_21;
  }
  v16 = v15->count;
  v16->m_Items[v13 + 1] = v12;
LABEL_21:
  if (v12 < n)
    return 0;
  (*a)->aiselect = 1 << (*a)->form->formindex;
  return 1;
}

// 0xf9d710
s32 Chk_DMGCNT(nbActionProcessData_t **a, s32 n) {
  s32 formindex;
  nbParty_t_o *PartyFromFormindex;

  formindex = (*a)->form->formindex;
  else
  {
    PartyFromFormindex = nbGetPartyFromFormindex(formindex);
    if (PartyFromFormindex)
      goto LABEL_6;
  }
  if (n > 0)
    return 0;
LABEL_12:
  (*a)->aiselect = 1 << (*a)->form->formindex;
  return 1;
}

// 0xf9e300
s32 Chk_ENALLBAD(nbActionProcessData_t **a, s32 n) {
  struct nbMainProcessData_t_o *data;
  u64 v6;
  s32 v7;
  u32 v8;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v11;
  struct nbParty_t_array *v13;
  struct nbParty_t_array *v15;
  struct nbMainProcessData_t_o *v17;
  struct nbParty_t_array *v18;
  nbParty_t_o *v20;
  struct nbParty_t_array *v21;

  data = (*a)->data;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  do
  {
    party = data->party;
    if ((party->m_Items[v6]->flag & 1) != 0)
    {
      v11 = (*a)->data->party;
      if ((v11->m_Items[v6]->flag & 8) == 0)
      {
        v13 = (*a)->data->party;
        if ((v13->m_Items[v6]->flag & 0x10) == 0)
        {
          v15 = (*a)->data->party;
          if ((v15->m_Items[v6]->flag & 0x20) == 0)
          {
            v17 = (*a)->data;
            v18 = v17->party;
            v20 = v18->m_Items[v6];
            if ((nbGetUnitWorkPointer(v17, v20)->badstatus & 0xFFF) == n)
            {
              v21 = (*a)->data->party;
              ++v7;
              v8 |= 1 << v21->m_Items[v6]->formindex;
            }
          }
        }
      }
    }
    data = (*a)->data;
    ++v6;
  }
  while (v6 != 4);
  if (v7 != data->playerpcnt)
    return 0;
  (*a)->aiselect = v8;
  return 1;
}

// 0xf9e0e0
s32 Chk_ENBAD(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v5;
  u64 i;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v9;
  struct nbParty_t_array *v11;
  struct nbParty_t_array *v13;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *v16;
  nbParty_t_o *v18;
  struct nbParty_t_array *v19;

  v5 = *a;
  for (i = 0; i != 4; ++i)
  {
    party = v5->data->party;
    if ((party->m_Items[i]->flag & 1) != 0)
    {
      v9 = (*a)->data->party;
      if ((v9->m_Items[i]->flag & 8) == 0)
      {
        v11 = (*a)->data->party;
        if ((v11->m_Items[i]->flag & 0x10) == 0)
        {
          v13 = (*a)->data->party;
          if ((v13->m_Items[i]->flag & 0x20) == 0)
          {
            data = (*a)->data;
            v16 = data->party;
            v18 = v16->m_Items[i];
            if ((nbGetUnitWorkPointer(data, v18)->badstatus & 0xFFF) == n)
            {
              v19 = (*a)->data->party;
              (*a)->aiselect |= 1 << v19->m_Items[i]->formindex;
            }
          }
        }
      }
    }
    v5 = *a;
  }
  return v5->aiselect != 0;
}

// 0xf9dce0
s32 Chk_ENCNT(nbActionProcessData_t **a, s32 n) {
  struct nbMainProcessData_t_o *data;
  u64 v5;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v8;
  struct nbParty_t_array *v10;
  struct nbParty_t_array *v12;
  struct nbParty_t_array *v14;

  data = (*a)->data;
  if (data->playerpcnt > n)
    return 0;
  v5 = 0;
  party = data->party;
  if (!LODWORD(party->max_length))
  {
LABEL_6:
  }
  while (1)
  {
    if ((party->m_Items[v5]->flag & 1) != 0)
    {
      v8 = (*a)->data->party;
      if ((v8->m_Items[v5]->flag & 8) == 0)
      {
        v10 = (*a)->data->party;
        if ((v10->m_Items[v5]->flag & 0x10) == 0)
        {
          v12 = (*a)->data->party;
          if ((v12->m_Items[v5]->flag & 0x20) == 0)
          {
            v14 = (*a)->data->party;
            (*a)->aiselect |= 1 << v14->m_Items[v5]->formindex;
          }
        }
      }
    }
    if (v5 == 3)
      return 1;
    ++v5;
    party = (*a)->data->party;
    if (v5 >= LODWORD(party->max_length))
      goto LABEL_6;
  }
}

// 0xfa0960
s32 Chk_ENDARK(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v4;
  u64 i;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v8;
  struct nbParty_t_array *v10;
  struct nbParty_t_array *v12;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *v15;
  nbParty_t_o *v17;
  datUnitWork_t_o *UnitWorkPointer;
  datUnitWork_t_o *v19;
  struct nbParty_t_array *v20;

  v4 = *a;
  for (i = 0; i != 4; ++i)
  {
    while (1)
    {
      party = v4->data->party;
      if ((party->m_Items[i]->flag & 1) != 0)
      {
        v8 = (*a)->data->party;
        if ((v8->m_Items[i]->flag & 8) == 0)
        {
          v10 = (*a)->data->party;
          if ((v10->m_Items[i]->flag & 0x10) == 0)
          {
            v12 = (*a)->data->party;
            if ((v12->m_Items[i]->flag & 0x20) == 0)
            {
              data = (*a)->data;
              v15 = data->party;
              v17 = v15->m_Items[i];
              UnitWorkPointer = nbGetUnitWorkPointer(data, v17);
              if ((UnitWorkPointer->flag & 4) == 0)
              {
                v19 = UnitWorkPointer;
                if (datGet3Zokusei(v19) == -1)
                  break;
              }
            }
          }
        }
      }
      v4 = *a;
      if (++i == 4)
        return v4->aiselect != 0;
    }
    v20 = (*a)->data->party;
    (*a)->aiselect |= 1 << v20->m_Items[i]->formindex;
    v4 = *a;
  }
  return v4->aiselect != 0;
}

// 0xfa1040
s32 Chk_ENHAMAMHK(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v4;
  u64 i;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v8;
  struct nbParty_t_array *v10;
  struct nbParty_t_array *v12;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *v15;
  nbParty_t_o *v17;
  datUnitWork_t_o *UnitWorkPointer;
  struct nbParty_t_array *v20;

  v4 = *a;
  for (i = 0; i != 4; ++i)
  {
    while (1)
    {
      party = v4->data->party;
      if ((party->m_Items[i]->flag & 1) != 0)
      {
        v8 = (*a)->data->party;
        if ((v8->m_Items[i]->flag & 8) == 0)
        {
          v10 = (*a)->data->party;
          if ((v10->m_Items[i]->flag & 0x10) == 0)
          {
            v12 = (*a)->data->party;
            if ((v12->m_Items[i]->flag & 0x20) == 0)
            {
              data = (*a)->data;
              v15 = data->party;
              v17 = v15->m_Items[i];
              UnitWorkPointer = nbGetUnitWorkPointer(data, v17);
              if ((datGetAisyo(UnitWorkPointer, 6) & 0x70000) == 0)
                break;
            }
          }
        }
      }
      v4 = *a;
      if (++i == 4)
        return v4->aiselect != 0;
    }
    v20 = (*a)->data->party;
    (*a)->aiselect |= 1 << v20->m_Items[i]->formindex;
    v4 = *a;
  }
  return v4->aiselect != 0;
}

// 0xf9fb40
s32 Chk_ENHOJO(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v5;
  u64 i;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v10;
  struct nbParty_t_array *v12;
  struct nbParty_t_array *v14;
  struct nbParty_t_array *v16;
  s32 formindex;
  struct nbParty_t_array *v19;

  v5 = *a;
  for (i = 0; i != 4; ++i)
  {
    party = v5->data->party;
    if ((party->m_Items[i]->flag & 1) != 0)
    {
      v10 = (*a)->data->party;
      if ((v10->m_Items[i]->flag & 8) == 0)
      {
        v12 = (*a)->data->party;
        if ((v12->m_Items[i]->flag & 0x10) == 0)
        {
          v14 = (*a)->data->party;
          if ((v14->m_Items[i]->flag & 0x20) == 0)
          {
            v16 = (*a)->data->party;
            formindex = v16->m_Items[i]->formindex;
            else if (!ChkAiHojo(formindex, n))
            {
              goto LABEL_26;
            }
            v19 = (*a)->data->party;
            (*a)->aiselect |= 1 << v19->m_Items[i]->formindex;
          }
        }
      }
    }
LABEL_26:
    v5 = *a;
  }
  return v5->aiselect != 0;
}

// 0xf9ff90
s32 Chk_ENHOJOMAX(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v5;
  u64 i;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v10;
  struct nbParty_t_array *v12;
  struct nbParty_t_array *v14;
  struct nbParty_t_array *v16;
  s32 formindex;
  struct nbParty_t_array *v19;

  v5 = *a;
  for (i = 0; i != 4; ++i)
  {
    party = v5->data->party;
    if ((party->m_Items[i]->flag & 1) != 0)
    {
      v10 = (*a)->data->party;
      if ((v10->m_Items[i]->flag & 8) == 0)
      {
        v12 = (*a)->data->party;
        if ((v12->m_Items[i]->flag & 0x10) == 0)
        {
          v14 = (*a)->data->party;
          if ((v14->m_Items[i]->flag & 0x20) == 0)
          {
            v16 = (*a)->data->party;
            formindex = v16->m_Items[i]->formindex;
            else if (!ChkAiHojoMax(formindex, n))
            {
              goto LABEL_26;
            }
            v19 = (*a)->data->party;
            (*a)->aiselect |= 1 << v19->m_Items[i]->formindex;
          }
        }
      }
    }
LABEL_26:
    v5 = *a;
  }
  return v5->aiselect != 0;
}

// 0xf9e540
s32 Chk_ENID(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v5;
  u64 i;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v9;
  struct nbParty_t_array *v11;
  struct nbParty_t_array *v13;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *v16;
  nbParty_t_o *v18;
  datUnitWork_t_o *UnitWorkPointer;
  struct nbParty_t_array *v20;

  v5 = *a;
  for (i = 0; i != 4; ++i)
  {
    party = v5->data->party;
    if ((party->m_Items[i]->flag & 1) != 0)
    {
      v9 = (*a)->data->party;
      if ((v9->m_Items[i]->flag & 8) == 0)
      {
        v11 = (*a)->data->party;
        if ((v11->m_Items[i]->flag & 0x10) == 0)
        {
          v13 = (*a)->data->party;
          if ((v13->m_Items[i]->flag & 0x20) == 0)
          {
            data = (*a)->data;
            v16 = data->party;
            v18 = v16->m_Items[i];
            UnitWorkPointer = nbGetUnitWorkPointer(data, v18);
            if ((UnitWorkPointer->flag & 4) == 0 && UnitWorkPointer->id == n)
            {
              v20 = (*a)->data->party;
              (*a)->aiselect |= 1 << v20->m_Items[i]->formindex;
            }
          }
        }
      }
    }
    v5 = *a;
  }
  return v5->aiselect != 0;
}

// 0xfa0720
s32 Chk_ENLIGHT(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v4;
  u64 i;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v8;
  struct nbParty_t_array *v10;
  struct nbParty_t_array *v12;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *v15;
  nbParty_t_o *v17;
  datUnitWork_t_o *UnitWorkPointer;
  datUnitWork_t_o *v19;
  struct nbParty_t_array *v20;

  v4 = *a;
  for (i = 0; i != 4; ++i)
  {
    party = v4->data->party;
    if ((party->m_Items[i]->flag & 1) != 0)
    {
      v8 = (*a)->data->party;
      if ((v8->m_Items[i]->flag & 8) == 0)
      {
        v10 = (*a)->data->party;
        if ((v10->m_Items[i]->flag & 0x10) == 0)
        {
          v12 = (*a)->data->party;
          if ((v12->m_Items[i]->flag & 0x20) == 0)
          {
            data = (*a)->data;
            v15 = data->party;
            v17 = v15->m_Items[i];
            UnitWorkPointer = nbGetUnitWorkPointer(data, v17);
            if ((UnitWorkPointer->flag & 4) == 0)
            {
              v19 = UnitWorkPointer;
              if (datGet3Zokusei(v19) == 1)
              {
                v20 = (*a)->data->party;
                (*a)->aiselect |= 1 << v20->m_Items[i]->formindex;
              }
            }
          }
        }
      }
    }
    v4 = *a;
  }
  return v4->aiselect != 0;
}

// 0xf9dec0
s32 Chk_FRBAD(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v5;
  s64 i;
  struct nbParty_t_array *party;
  u64 v8;
  struct nbParty_t_array *v10;
  struct nbParty_t_array *v12;
  struct nbParty_t_array *v14;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *v17;
  nbParty_t_o *v19;
  struct nbParty_t_array *v20;

  v5 = *a;
  for (i = 0; i != 10; ++i)
  {
    party = v5->data->party;
    v8 = i + 4;
    if ((party->m_Items[i + 4]->flag & 1) != 0)
    {
      v10 = (*a)->data->party;
      if ((v10->m_Items[i + 4]->flag & 8) == 0)
      {
        v12 = (*a)->data->party;
        if ((v12->m_Items[i + 4]->flag & 0x10) == 0)
        {
          v14 = (*a)->data->party;
          if ((v14->m_Items[i + 4]->flag & 0x20) == 0)
          {
            data = (*a)->data;
            v17 = data->party;
            v19 = v17->m_Items[i + 4];
            if ((nbGetUnitWorkPointer(data, v19)->badstatus & 0xFFF) == n)
            {
              v20 = (*a)->data->party;
              (*a)->aiselect |= 1 << v20->m_Items[i + 4]->formindex;
            }
          }
        }
      }
    }
    v5 = *a;
  }
  return v5->aiselect != 0;
}

// 0xf9db40
s32 Chk_FRCNT(nbActionProcessData_t **a, s32 n) {
  struct nbMainProcessData_t_o *data;
  s64 i;
  struct nbParty_t_array *party;
  u64 v7;
  struct nbParty_t_array *v9;
  struct nbParty_t_array *v11;
  struct nbParty_t_array *v13;
  struct nbParty_t_array *v15;

  data = (*a)->data;
  if (data->enemypcnt > n)
    return 0;
  for (i = 0; ; ++i)
  {
    party = data->party;
    v7 = i + 4;
    if ((party->m_Items[i + 4]->flag & 1) != 0)
    {
      v9 = (*a)->data->party;
      if ((v9->m_Items[i + 4]->flag & 8) == 0)
      {
        v11 = (*a)->data->party;
        if ((v11->m_Items[i + 4]->flag & 0x10) == 0)
        {
          v13 = (*a)->data->party;
          if ((v13->m_Items[i + 4]->flag & 0x20) == 0)
          {
            v15 = (*a)->data->party;
            (*a)->aiselect |= 1 << v15->m_Items[i + 4]->formindex;
          }
        }
      }
    }
    if (i == 9)
      break;
    data = (*a)->data;
  }
  return 1;
}

// 0xf9fd60
s32 Chk_FRHOJO(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v5;
  s64 i;
  struct nbParty_t_array *party;
  u64 v9;
  struct nbParty_t_array *v11;
  struct nbParty_t_array *v13;
  struct nbParty_t_array *v15;
  struct nbParty_t_array *v17;
  s32 formindex;
  struct nbParty_t_array *v20;

  v5 = *a;
  for (i = 0; i != 10; ++i)
  {
    party = v5->data->party;
    v9 = i + 4;
    if ((party->m_Items[i + 4]->flag & 1) != 0)
    {
      v11 = (*a)->data->party;
      if ((v11->m_Items[i + 4]->flag & 8) == 0)
      {
        v13 = (*a)->data->party;
        if ((v13->m_Items[i + 4]->flag & 0x10) == 0)
        {
          v15 = (*a)->data->party;
          if ((v15->m_Items[i + 4]->flag & 0x20) == 0)
          {
            v17 = (*a)->data->party;
            formindex = v17->m_Items[i + 4]->formindex;
            else if (!ChkAiHojo(formindex, n))
            {
              goto LABEL_26;
            }
            v20 = (*a)->data->party;
            (*a)->aiselect |= 1 << v20->m_Items[i + 4]->formindex;
          }
        }
      }
    }
LABEL_26:
    v5 = *a;
  }
  return v5->aiselect != 0;
}

// 0xfa01b0
s32 Chk_FRHOJOMAX(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v5;
  s64 i;
  struct nbParty_t_array *party;
  u64 v9;
  struct nbParty_t_array *v11;
  struct nbParty_t_array *v13;
  struct nbParty_t_array *v15;
  struct nbParty_t_array *v17;
  s32 formindex;
  struct nbParty_t_array *v20;

  v5 = *a;
  for (i = 0; i != 10; ++i)
  {
    party = v5->data->party;
    v9 = i + 4;
    if ((party->m_Items[i + 4]->flag & 1) != 0)
    {
      v11 = (*a)->data->party;
      if ((v11->m_Items[i + 4]->flag & 8) == 0)
      {
        v13 = (*a)->data->party;
        if ((v13->m_Items[i + 4]->flag & 0x10) == 0)
        {
          v15 = (*a)->data->party;
          if ((v15->m_Items[i + 4]->flag & 0x20) == 0)
          {
            v17 = (*a)->data->party;
            formindex = v17->m_Items[i + 4]->formindex;
            else if (!ChkAiHojoMax(formindex, n))
            {
              goto LABEL_26;
            }
            v20 = (*a)->data->party;
            (*a)->aiselect |= 1 << v20->m_Items[i + 4]->formindex;
          }
        }
      }
    }
LABEL_26:
    v5 = *a;
  }
  return v5->aiselect != 0;
}

// 0xf9d4e0
s32 Chk_FRHP(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v5;
  s64 i;
  struct nbParty_t_array *party;
  u64 v8;
  struct nbParty_t_array *v10;
  struct nbParty_t_array *v12;
  struct nbParty_t_array *v14;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *v17;
  nbParty_t_o *v19;
  datUnitWork_t_o *UnitWorkPointer;
  struct nbParty_t_array *v21;

  v5 = *a;
  for (i = 0; i != 10; ++i)
  {
    party = v5->data->party;
    v8 = i + 4;
    if ((party->m_Items[i + 4]->flag & 1) != 0)
    {
      v10 = (*a)->data->party;
      if ((v10->m_Items[i + 4]->flag & 8) == 0)
      {
        v12 = (*a)->data->party;
        if ((v12->m_Items[i + 4]->flag & 0x10) == 0)
        {
          v14 = (*a)->data->party;
          if ((v14->m_Items[i + 4]->flag & 0x20) == 0)
          {
            data = (*a)->data;
            v17 = data->party;
            v19 = v17->m_Items[i + 4];
            UnitWorkPointer = nbGetUnitWorkPointer(data, v19);
            if ((100 * UnitWorkPointer->hp / UnitWorkPointer->maxhp) <= n)
            {
              v21 = (*a)->data->party;
              (*a)->aiselect |= 1 << v21->m_Items[i + 4]->formindex;
            }
          }
        }
      }
    }
    v5 = *a;
  }
  return v5->aiselect != 0;
}

// 0xf9e760
s32 Chk_FRID(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v5;
  s64 i;
  u64 v7;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v10;
  struct nbParty_t_array *v12;
  struct nbParty_t_array *v14;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *v17;
  nbParty_t_o *v19;
  struct nbParty_t_array *v20;

  v5 = *a;
  for (i = 0; i != 10; ++i)
  {
    v7 = i + 4;
    if (i + 4 != v5->partyindex)
    {
      party = v5->data->party;
      if ((party->m_Items[i + 4]->flag & 1) != 0)
      {
        v10 = (*a)->data->party;
        if ((v10->m_Items[i + 4]->flag & 8) == 0)
        {
          v12 = (*a)->data->party;
          if ((v12->m_Items[i + 4]->flag & 0x10) == 0)
          {
            v14 = (*a)->data->party;
            if ((v14->m_Items[i + 4]->flag & 0x20) == 0)
            {
              data = (*a)->data;
              v17 = data->party;
              v19 = v17->m_Items[i + 4];
              if (nbGetUnitWorkPointer(data, v19)->id == n)
              {
                v20 = (*a)->data->party;
                (*a)->aiselect |= 1 << v20->m_Items[i + 4]->formindex;
              }
            }
          }
        }
      }
    }
    v5 = *a;
  }
  return v5->aiselect != 0;
}

// 0xf9de80
s32 Chk_MYBAD(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v3;

  v3 = *a;
  if (((*a)->work->badstatus & 0xFFF) != n)
    return 0;
  v3->aiselect = 1 << v3->form->formindex;
  return 1;
}

// 0xf9d450
s32 Chk_MYHP(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v3;

  v3 = *a;
  if ((100 * (*a)->work->hp / (*a)->work->maxhp) > n)
    return 0;
  v3->aiselect = 1 << v3->form->formindex;
  return 1;
}

// 0xf9d4a0
s32 Chk_MYMP(nbActionProcessData_t **a, s32 n) {
  nbActionProcessData_t_o *v3;

  v3 = *a;
  if ((*a)->work->mp > n)
    return 0;
  v3->aiselect = 1 << v3->form->formindex;
  return 1;
}

// 0xfa0d10
s32 Chk_PLV(nbActionProcessData_t **a, s32 n) {
  return datGetPlayerLevel() >= n;
}

// 0xfa0bc0
s32 Chk_POW(nbActionProcessData_t **a, s32 n) {
  s32 formindex;
  nbParty_t_o *PartyFromFormindex;
  struct System_Int16_array *count;

  formindex = (*a)->form->formindex;
LABEL_7:
  else
  {
    PartyFromFormindex = nbGetPartyFromFormindex(formindex);
    if (!PartyFromFormindex)
      return PartyFromFormindex;
  }
  count = PartyFromFormindex->count;
  if (count->m_Items[15] < 1)
  {
    LODWORD(PartyFromFormindex) = 0;
  }
  else
  {
    (*a)->aiselect = 1 << (*a)->form->formindex;
    LODWORD(PartyFromFormindex) = 1;
  }
  return PartyFromFormindex;
}

// 0xfa0d80
s32 Chk_PPARTYLV(nbActionProcessData_t **a, s32 n) {
  return nbGetLvAvg((*a)->data, 0) >= n;
}

// 0xfa0580
s32 Chk_SENSEI(nbActionProcessData_t **a, s32 n) {
  struct nbMainProcessData_t_o *data;
  u64 v5;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v8;
  struct nbParty_t_array *v10;
  struct nbParty_t_array *v12;
  struct nbParty_t_array *v14;

  data = (*a)->data;
  if ((data->stat & 0x80) == 0)
    return 0;
  v5 = 0;
  party = data->party;
  if (!LODWORD(party->max_length))
  {
LABEL_6:
  }
  while (1)
  {
    if ((party->m_Items[v5]->flag & 1) != 0)
    {
      v8 = (*a)->data->party;
      if ((v8->m_Items[v5]->flag & 8) == 0)
      {
        v10 = (*a)->data->party;
        if ((v10->m_Items[v5]->flag & 0x10) == 0)
        {
          v12 = (*a)->data->party;
          if ((v12->m_Items[v5]->flag & 0x20) == 0)
          {
            v14 = (*a)->data->party;
            (*a)->aiselect |= 1 << v14->m_Items[v5]->formindex;
          }
        }
      }
    }
    if (v5 == 3)
      return 1;
    ++v5;
    party = (*a)->data->party;
    if (v5 >= LODWORD(party->max_length))
      goto LABEL_6;
  }
}

// 0xfa1290
s32 Chk_SKILLNOMP(nbActionProcessData_t **a, s32 n) {
  s32 result;

  result = nbCheckSkillCost((*a)->form->formindex, n);
  if (result)
  {
    (*a)->aiselect = 1 << (*a)->form->formindex;
    return 1;
  }
  return result;
}

// 0xfa1020
s32 Chk_TURN(nbActionProcessData_t **a, s32 n) {
  return (*a)->data->turn >= n;
}

// 0xfa1c20
s32 GetKoudou(nbActionProcessData_t **a, s32 tbl) {
  u64 *v6;
  u64 v7;
  s32 v8;
  u32 v9;
  s32 id;
  struct datDevilAITbl_s_array_array *aitable;
  datDevilAITbl_s_array *v13;
  datDevilAITbl_s_o *v15;
  struct System_SByte_array *aichktbl;
  s32 result;
  u32 RandIntA;
  signed s32 v22;
  u64 v23;
  signed s32 v24;
  s32 v25;
  struct datDevilAITbl_s_array_array *v26;
  datDevilAITbl_s_array *v28;
  s64 v30;
  signed s64 v33;

  v6 = NewSpecific(s32, 5u);
  v7 = 0;
  v8 = 0;
  v9 = 0;
  do
  {
    while (1)
    {
      id = (*a)->work->id;
      aitable = Get(id, 0)->aitable;
      v13 = aitable->m_Items[tbl];
      v15 = v13->m_Items[v7];
      aichktbl = (*a)->aichktbl;
      if (aichktbl->m_Items[v7] <= 0)
        break;
      if (++v7 == 5)
        goto LABEL_19;
    }
    *(v6 + v8 + 8) = v7;
    v9 += v15->ritu;
    ++v8;
    ++v7;
  }
  while (v7 != 5);
LABEL_19:
  result = -1;
  if (v9 && v8)
  {
    RandIntA = dds3GetRandIntA(v9, "GetKoudou");
    if (v8 < 1)
    {
      return -1;
    }
    else
    {
      v22 = RandIntA;
      v23 = 0;
      v24 = 0;
      v33 = v8;
      while (1)
      {
        v25 = (*a)->work->id;
        v26 = Get(v25, 0)->aitable;
        v28 = v26->m_Items[tbl];
        v30 = *(v6 + v23 + 8);
        v24 += v28->m_Items[v30]->ritu;
        if (v22 < v24)
          break;
        if (++v23 >= v33)
          return -1;
      }
      return *(v6 + v23 + 8);
    }
  }
  return result;
}

// 0xfa21f0
s32 Sel_AI(nbActionProcessData_t **a, s32 n, s32 gr) {
  u64 *v7;
  s32 id;
  datDevilAI_t_o *v9;
  s64 v10;
  nbActionProcessData_t_o *v12;
  struct datUnitWork_t_o *work;
  s32 ailevel;
  s32 nowindex;
  s64 i;
  struct nbFormation_t_array *v17;
  struct nbFormation_t_array *v19;
  s32 v21;
  u64 v22;
  struct nbFormation_t_array *form;
  s32 VirtualAisyo;
  s32 VirtualKoukaPoint;
  s64 v27;
  u64 v29;
  struct nbFormation_t_array *v30;
  s32 v32;
  s64 v33;
  s64 k;
  struct nbFormation_t_array *v36;
  struct nbFormation_t_array *v38;
  u64 v41;
  s32 v42;
  s32 v43;
  s32 v46;
  s64 j;
  struct nbFormation_t_array *v48;
  u64 v49;
  struct nbFormation_t_array *v51;

  v7 = NewSpecific(s32, 0x20u);
  id = (*a)->work->id;
  v9 = Get(id, 0);
  v12 = *a;
  work = (*a)->work;
  ailevel = v9->ailevel;
  if (!work->nowcommand)
  {
    nowindex = 0;
    if (ailevel != 2)
      goto LABEL_9;
LABEL_24:
    v22 = 0;
    v21 = 0;
    while (1)
    {
      form = v12->data->form;
      if ((form->m_Items[v22]->stat & 4) == 0
        || (VirtualAisyo = nbGetVirtualAisyo(nowindex, v10, v22), VirtualAisyo == 0x10000)
        || VirtualAisyo == 0x20000
        || VirtualAisyo == 0x40000
        || (VirtualKoukaPoint = nbGetVirtualKoukaPoint(nowindex, (*a)->form->formindex, v22)) == 0)
      {
        if (v22 == 15)
          goto LABEL_53;
      }
      else
      {
        v27 = v21;
        ++v21;
        *(v7 + v27 + 8) = VirtualKoukaPoint;
        if (v22 == 15)
          goto LABEL_53;
      }
      v12 = *a;
      ++v22;
    }
  }
  if (work->nowcommand != 1)
  {
    Write("no skill\n", 0);
    return 0;
  }
  nowindex = work->nowindex;
  if (ailevel == 2)
    goto LABEL_24;
LABEL_9:
  if (ailevel == 1)
  {
    v29 = 0;
    v21 = 0;
    while (1)
    {
      v30 = v12->data->form;
      if ((v30->m_Items[v29]->stat & 4) != 0)
      {
        v32 = nbGetVirtualKoukaPoint(nowindex, (*a)->form->formindex, v29);
        v33 = v21;
        ++v21;
        *(v7 + v33 + 8) = v32;
        if (v29 == 15)
          goto LABEL_53;
      }
      else if (v29 == 15)
      {
        goto LABEL_53;
      }
      v12 = *a;
      ++v29;
    }
  }
  if (!v9->ailevel)
  {
    for (i = 4; ; ++i)
    {
      v17 = v12->data->form;
      if ((*(*(&v17->obj.klass + i) + 136LL) & 4) != 0)
      {
        v19 = (*a)->data->form;
        *(*(&v19->obj.klass + i) + 136LL) |= 8u;
        if (i == 19)
          break;
      }
      else if (i == 19)
      {
        break;
      }
      v12 = *a;
    }
  }
  v21 = 0;
  if ((ailevel - 1) > 1)
    return 0;
LABEL_53:
  if (v21)
  {
    if (!gr)
    {
      if (v21 < 1)
      {
        v43 = 0;
      }
      else
      {
        v41 = 0;
        v42 = 0;
        v43 = 0;
        do
        {
          while (1)
          {
            if (v42 < *(v7 + v41 + 8))
              break;
            if (v21 == ++v41)
              goto LABEL_81;
          }
          v43 = v41;
          v42 = *(v7 + v41++ + 8);
        }
        while (v21 != v41);
      }
LABEL_81:
      v46 = 0;
      for (j = 4; ; ++j)
      {
        v48 = (*a)->data->form;
        v49 = j - 4;
        if ((*(*(&v48->obj.klass + j) + 136LL) & 4) != 0)
        {
          if (v46 == v43)
          {
            v51 = (*a)->data->form;
            *(*(&v51->obj.klass + j) + 136LL) |= 8u;
            return 0;
          }
          ++v46;
        }
        if (v49 >= 0xF)
          return 0;
      }
    }
    for (k = 4; k != 20; ++k)
    {
      while (1)
      {
        v36 = (*a)->data->form;
        if ((*(*(&v36->obj.klass + k) + 136LL) & 4) != 0)
          break;
        if (++k == 20)
          return 0;
      }
      v38 = (*a)->data->form;
      *(*(&v38->obj.klass + k) + 136LL) |= 8u;
    }
    return 0;
  }
  Write("taisyo nashi!!!\n", 0);
  return -1;
}

// 0xfa2c90
void Sel_BAARLV(nbActionProcessData_t **a, s32 n) {
  u64 v4;
  s32 v5;
  s32 level;
  struct nbFormation_t_array *form;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct nbFormation_t_array *v10;
  nbFormation_t_o *v12;

  v4 = 0;
  v5 = -1;
  level = 10000;
  do
  {
    form = (*a)->data->form;
    if ((form->m_Items[v4]->stat & 4) != 0)
    {
      UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(v4);
      if ((UnitWorkFromFormindex->badstatus & 0xFFF) != 0x200 && level > UnitWorkFromFormindex->level)
      {
        v5 = v4;
        level = UnitWorkFromFormindex->level;
      }
    }
    ++v4;
  }
  while (v4 != 16);
  if ((v5 & 0x80000000) == 0)
  {
    v10 = (*a)->data->form;
    v12 = v10->m_Items[v5];
    v12->stat |= 8u;
  }
}

// 0xfa2f00
void Sel_BAD(nbActionProcessData_t **a, s32 n) {
  u64 i;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v8;

  for (i = 0; i != 16; ++i)
  {
    form = (*a)->data->form;
    if ((form->m_Items[i]->stat & 4) != 0)
    {
      if ((nbGetUnitWorkFromFormindex(i)->badstatus & 0xFFF) == n)
      {
        v8 = (*a)->data->form;
        v8->m_Items[i]->stat |= 8u;
      }
    }
  }
}

// 0xfa3280
void Sel_DARK(nbActionProcessData_t **a, s32 n) {
  u64 i;
  struct nbFormation_t_array *form;
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v8;
  struct nbFormation_t_array *v9;

  for (i = 0; i != 16; ++i)
  {
    while (1)
    {
      form = (*a)->data->form;
      if ((form->m_Items[i]->stat & 4) != 0)
      {
        UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(i);
        if ((UnitWorkFromFormindex->flag & 4) == 0)
        {
          v8 = UnitWorkFromFormindex;
          if (datGet3Zokusei(v8) == -1)
            break;
        }
      }
      if (++i == 16)
        return;
    }
    v9 = (*a)->data->form;
    v9->m_Items[i]->stat |= 8u;
  }
}

// 0xfa3020
void Sel_ID(nbActionProcessData_t **a, s32 n) {
  u64 i;
  struct nbFormation_t_array *form;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct nbFormation_t_array *v9;

  for (i = 0; i != 16; ++i)
  {
    form = (*a)->data->form;
    if ((form->m_Items[i]->stat & 4) != 0)
    {
      UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(i);
      if ((UnitWorkFromFormindex->flag & 4) == 0 && UnitWorkFromFormindex->id == n)
      {
        v9 = (*a)->data->form;
        v9->m_Items[i]->stat |= 8u;
      }
    }
  }
}

// 0xfa34d0
void Sel_JOKEN(nbActionProcessData_t **a, s32 n) {
  u64 i;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v6;

  for (i = 0; i != 16; ++i)
  {
    form = (*a)->data->form;
    if ((form->m_Items[i]->stat & 4) != 0 && ((*a)->aiselect & (1 << i)) != 0)
    {
      v6 = (*a)->data->form;
      v6->m_Items[i]->stat |= 8u;
    }
  }
}

// 0xfa2b50
void Sel_LIFEMIN(nbActionProcessData_t **a, s32 n) {
  u64 v4;
  s32 v5;
  s32 v6;
  struct nbFormation_t_array *form;
  s32 hp;
  struct nbFormation_t_array *v10;
  nbFormation_t_o *v12;

  v4 = 0;
  v5 = -1;
  v6 = 10000;
  do
  {
    while (1)
    {
      form = (*a)->data->form;
      if ((form->m_Items[v4]->stat & 4) != 0)
        break;
      if (++v4 == 16)
        goto LABEL_15;
    }
    hp = nbGetUnitWorkFromFormindex(v4)->hp;
    if (v6 > hp)
    {
      v5 = v4;
      v6 = hp;
    }
    ++v4;
  }
  while (v4 != 16);
LABEL_15:
  if ((v5 & 0x80000000) == 0)
  {
    v10 = (*a)->data->form;
    v12 = v10->m_Items[v5];
    v12->stat |= 8u;
  }
}

// 0xfa3140
void Sel_LIGHT(nbActionProcessData_t **a, s32 n) {
  u64 i;
  struct nbFormation_t_array *form;
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v8;
  struct nbFormation_t_array *v9;

  for (i = 0; i != 16; ++i)
  {
    form = (*a)->data->form;
    if ((form->m_Items[i]->stat & 4) != 0)
    {
      UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(i);
      if ((UnitWorkFromFormindex->flag & 4) == 0)
      {
        v8 = UnitWorkFromFormindex;
        if (datGet3Zokusei(v8) == 1)
        {
          v9 = (*a)->data->form;
          v9->m_Items[i]->stat |= 8u;
        }
      }
    }
  }
}

// 0xfa2dc0
void Sel_LVMIN(nbActionProcessData_t **a, s32 n) {
  u64 v4;
  s32 v5;
  s32 v6;
  struct nbFormation_t_array *form;
  s32 level;
  struct nbFormation_t_array *v10;
  nbFormation_t_o *v12;

  v4 = 0;
  v5 = -1;
  v6 = 10000;
  do
  {
    while (1)
    {
      form = (*a)->data->form;
      if ((form->m_Items[v4]->stat & 4) != 0)
        break;
      if (++v4 == 16)
        goto LABEL_15;
    }
    level = nbGetUnitWorkFromFormindex(v4)->level;
    if (v6 > level)
    {
      v5 = v4;
      v6 = level;
    }
    ++v4;
  }
  while (v4 != 16);
LABEL_15:
  if ((v5 & 0x80000000) == 0)
  {
    v10 = (*a)->data->form;
    v12 = v10->m_Items[v5];
    v12->stat |= 8u;
  }
}

// 0xfa33d0
void Sel_PLAYER(nbActionProcessData_t **a, s32 n) {
  u64 i;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v7;

  for (i = 0; i != 16; ++i)
  {
    form = (*a)->data->form;
    if ((form->m_Items[i]->stat & 4) != 0)
    {
      if ((nbGetUnitWorkFromFormindex(i)->flag & 4) != 0)
      {
        v7 = (*a)->data->form;
        v7->m_Items[i]->stat |= 8u;
      }
    }
  }
}

// 0xfa3590
void Sel_RND(nbActionProcessData_t **a, s32 n) {
  s64 i;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v6;

  for (i = 4; i != 20; ++i)
  {
    while (1)
    {
      form = (*a)->data->form;
      if ((*(*(&form->obj.klass + i) + 136LL) & 4) != 0)
        break;
      if (++i == 20)
        return;
    }
    v6 = (*a)->data->form;
    *(*(&v6->obj.klass + i) + 136LL) |= 8u;
  }
}

// 0xfa3b40
s32 SetGroupTarget2(nbActionProcessData_t **a, s32 code, s32 n) {
  s32 v6;
  s64 i;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v10;
  u64 v12;
  struct nbFormation_t_array *v13;
  s32 v15;

  v6 = 0;
  if (code && (code - 1) <= 9)
  {
    for (i = 4; i != 20; ++i)
    {
      while (1)
      {
        form = (*a)->data->form;
        if ((*(*(&form->obj.klass + i) + 136LL) & 4) != 0)
          break;
        if (++i == 20)
          goto LABEL_14;
      }
      v10 = (*a)->data->form;
      *(*(&v10->obj.klass + i) + 136LL) |= 8u;
    }
LABEL_14:
    v6 = code;
  }
  v12 = 0;
  while (1)
  {
    v13 = (*a)->data->form;
    if ((v13->m_Items[v12]->stat & 8) != 0)
      break;
    v15 = v12 + 1;
    if (v12++ > 0xE)
    {
      LODWORD(v12) = v15;
      break;
    }
  }
  if (v6 && v12 != 16)
    return 0;
  return Sel_AI(a, code, 1);
}

// 0xfa1f20
void SetKoudou(nbActionProcessData_t **a, s32 tbl, s32 kou) {
  s32 id;
  struct datDevilAITbl_s_array_array *aitable;
  datDevilAITbl_s_array *v11;
  datDevilAITbl_s_o *v13;
  u16 skill;
  datUnitWork_t_o *work;
  u32 v16;
  u32 v17;
  struct datUnitWork_t_o *v18;
  s16 v19;

  id = (*a)->work->id;
  aitable = Get(id, 0)->aitable;
  v11 = aitable->m_Items[tbl];
  v13 = v11->m_Items[kou];
  (*a)->work->nowcommand = 0;
  (*a)->work->nowindex = 0;
  skill = v13->skill;
  switch (skill)
  {
    case 0x8000u:
      (*a)->work->nowcommand = 0;
      work = (*a)->work;
      nbSetNormalSkill0(work);
      return;
    case 0x8001u:
      (*a)->work->nowcommand = 7;
      return;
    case 0x8002u:
      (*a)->work->nowcommand = 3;
      return;
    case 0x8003u:
      (*a)->work->nowcommand = 9;
      return;
    default:
      (*a)->work->nowcommand = 1;
      if ((skill & 0x80000000) == 0)
      {
        (*a)->work->nowindex = v13->skill;
        return;
      }
      v16 = v13->skill;
      v17 = v16 & 0xF000;
      if (v17 <= 0xB000)
      {
        switch (v17)
        {
          case 0x9000u:
            v18 = (*a)->work;
            v19 = 226;
            break;
          case 0xA000u:
            v18 = (*a)->work;
            v19 = 227;
            break;
          case 0xB000u:
            v18 = (*a)->work;
            v19 = 229;
            break;
          default:
            goto LABEL_37;
        }
        goto LABEL_36;
      }
      if (v17 <= 0xD000)
      {
        if (v17 == 49152)
        {
          v18 = (*a)->work;
          v19 = 230;
        }
        else
        {
          if (v17 != 53248)
            goto LABEL_37;
          v18 = (*a)->work;
          v19 = 252;
        }
        goto LABEL_36;
      }
      if (v17 == 57344)
      {
        (*a)->work->nowcommand = 9;
        (*a)->data->eventno = v13->skill & 0xFFF;
        goto LABEL_37;
      }
      if (v16 >= 0xF000)
      {
        v18 = (*a)->work;
        v19 = 222;
LABEL_36:
        v18->nowindex = v19;
      }
LABEL_37:
      (*a)->aisummonid = v13->skill & 0xFFF;
      return;
  }
}

// 0xfa3650
s32 SetSingleTarget2(nbActionProcessData_t **a, s32 code, s32 n) {
  s64 v7;
  u64 *v10;
  s32 v11;
  s64 v12;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v15;
  u64 v17;
  struct nbFormation_t_array *v18;
  s32 v20;
  s32 v22;
  u64 v23;
  signed s32 v24;
  struct nbFormation_t_array *v25;
  s64 v27;
  u32 RandIntA;
  u64 v31;
  s64 v32;
  struct nbFormation_t_array *v33;

  v10 = NewSpecific(sbyte, 0x20u);
  switch (code)
  {
    case 1:
      Sel_LIFEMIN(a, v7);
      goto LABEL_54;
    case 2:
      Sel_BAD(a, n);
      goto LABEL_54;
    case 3:
      Sel_ID(a, n);
      goto LABEL_54;
    case 4:
      Sel_LIGHT(a, v7);
      goto LABEL_54;
    case 5:
      Sel_DARK(a, v7);
      goto LABEL_54;
    case 6:
      Sel_PLAYER(a, v7);
      goto LABEL_54;
    case 7:
      Sel_JOKEN(a, v7);
      goto LABEL_54;
    case 8:
      v12 = 4;
      v11 = 10;
      break;
    case 9:
      Sel_BAARLV(a, v7);
      goto LABEL_54;
    case 10:
      Sel_LVMIN(a, v7);
LABEL_54:
      v11 = 10;
      goto LABEL_55;
    default:
      v11 = 0;
      goto LABEL_55;
  }
  do
  {
    while (1)
    {
      form = (*a)->data->form;
      if ((*(*(&form->obj.klass + v12) + 136LL) & 4) != 0)
        break;
      if (++v12 == 20)
        goto LABEL_55;
    }
    v15 = (*a)->data->form;
    *(*(&v15->obj.klass + v12++) + 136LL) |= 8u;
  }
  while (v12 != 20);
LABEL_55:
  v17 = 0;
  while (1)
  {
    v18 = (*a)->data->form;
    if ((v18->m_Items[v17]->stat & 8) != 0)
      break;
    v20 = v17 + 1;
    if (v17++ > 0xE)
    {
      LODWORD(v17) = v20;
      break;
    }
  }
  if (!v11 || v17 == 16)
  {
    v22 = Sel_AI(a, v7, 0);
  }
  else
  {
    v22 = 0;
  }
  v23 = 0;
  v24 = 0;
  do
  {
    while (1)
    {
      v25 = (*a)->data->form;
      if ((v25->m_Items[v23]->stat & 8) != 0)
        break;
      if (++v23 == 16)
        goto LABEL_78;
    }
    v27 = v24;
    ++v24;
    *(v10 + v27 + 32) = v23++;
  }
  while (v23 != 16);
LABEL_78:
  if (v24 >= 1)
  {
    RandIntA = dds3GetRandIntA(v24, "SetSingleTarget2");
    v31 = 0;
    v32 = *(v10 + RandIntA + 32) & 0xFFFFFFFFLL;
    do
    {
      if (v32 != v31)
      {
        v33 = (*a)->data->form;
        v33->m_Items[v31]->stat &= ~8u;
      }
      ++v31;
    }
    while (v31 != 16);
  }
  return v22;
}

// 0xfa1510
s32 nbAiChkJoken(nbActionProcessData_t **a, u32 jo) {
  s64 v6;
  u32 aiselect;
  struct nbAi_nbaifunc_t_array *nbaifunc;
  s32 result;

  v6 = HIWORD(jo);
  if (!v6)
    return 1;
  aiselect = (*a)->aiselect;
  (*a)->aiselect = 0;
  result = Invoke(nbaifunc->m_Items[v6]->func, a, jo);
  if (result)
  {
    if (aiselect)
      (*a)->aiselect &= aiselect;
    return 1;
  }
  return result;
}

// 0xfa4570
s32 nbRunAi(nbActionProcessData_t **a) {
  s64 v6;
  s32 id;
  struct datDevilAIChk_s_array *aichk;
  s32 table;
  u64 *v13;
  s32 v17;

  v6 = 0;
  if (AiChk(a, 0))
    goto LABEL_15;
  v6 = 1;
  if (AiChk(a, 1))
    goto LABEL_15;
  v6 = 2;
  if (AiChk(a, 2))
  {
LABEL_15:
    id = (*a)->work->id;
    aichk = Get(id, 0)->aichk;
    table = aichk->m_Items[v6]->table;
  }
  else
  {
    table = 0;
  }
  v17 = table;
  v13 = sub_8D3950(s32, &v17);
  Write_2930400("AItbl = {0:D}\n", v13);
  nbRunAiSub(a, table);
  return 0;
}

// 0xfa41d0
s32 nbRunAiSub(nbActionProcessData_t **a, s32 tbl) {
  struct System_SByte_array *aichktbl;
  struct System_SByte_array *v7;
  struct System_SByte_array *v9;
  struct System_SByte_array *v11;
  struct System_SByte_array *v13;
  s32 Koudou;
  u64 *v18;
  s32 id;
  struct datDevilAITbl_s_array_array *aitable;
  datDevilAITbl_s_array *v27;
  u32 target;
  s32 v30;
  s32 v31;
  struct System_SByte_array *v32;
  nbActionProcessData_t_o *v36;
  nbMainProcessData_t_o *data;
  s32 v38;

  aichktbl = (*a)->aichktbl;
  aichktbl->m_Items[0] = 0;
  v7 = (*a)->aichktbl;
  v7->m_Items[1] = 0;
  v9 = (*a)->aichktbl;
  v9->m_Items[2] = 0;
  v11 = (*a)->aichktbl;
  v11->m_Items[3] = 0;
  v13 = (*a)->aichktbl;
  v13->m_Items[4] = 0;
  {
LABEL_16:
    goto LABEL_18;
  }
  while (1)
  {
LABEL_18:
    Koudou = GetKoudou(a, tbl);
    v38 = Koudou;
    v18 = sub_8D3950(s32, &v38);
    Write_2930400("Koukatbl = {0:D}\n", v18);
    if (Koudou < 0)
    {
      (*a)->select = 0;
      (*a)->work->nowcommand = 3;
      (*a)->work->nowindex = 0;
      return 0;
    }
    SetKoudou(a, tbl, Koudou);
    if (ChkCost(a))
      goto LABEL_40;
      break;
    if (ChkClose(a, *&tbl))
      goto LABEL_29;
LABEL_40:
    v32 = (*a)->aichktbl;
    v32->m_Items[Koudou] = 1;
      goto LABEL_16;
  }
  if (!ChkClose(a))
    goto LABEL_40;
LABEL_29:
  id = (*a)->work->id;
  aitable = Get(id, 0)->aitable;
  v27 = aitable->m_Items[tbl];
  target = v27->m_Items[Koudou]->target;
  v30 = HIWORD(target);
  v31 = target;
  if (nbSetAiTarget(a, v30, v31))
    goto LABEL_40;
  v36 = *a;
  data = (*a)->data;
  v36->select = nbGetSelectBit(data);
  return 0;
}

// 0xfa3fe0
s32 nbSetAiTarget(nbActionProcessData_t **a, s32 code, s32 n) {
  s32 v5;
  nbActionProcessData_t_o *v7;
  struct datUnitWork_t_o *work;
  s32 nowcommand;
  bool v10;
  s32 result;
  s32 nowindex;
  bool v13;
  nbMainProcessData_t_o **p_data;
  s32 aisummonid;
  s32 carea;
  s32 crule[2];

  v5 = code;
  *crule = 0;
  carea = 0;
  v7 = *a;
  work = (*a)->work;
  nowcommand = work->nowcommand;
  if (work->nowcommand)
    v10 = nowcommand == 5;
  else
    v10 = 1;
  if (!v10)
  {
    result = 0;
    if (nowcommand != 1)
      return result;
    nowindex = work->nowindex;
    if (nowindex == 222 || (nowindex != 252 ? (v13 = (nowindex - 226) > 4) : (v13 = 0), !v13))
    {
      p_data = &v7->data;
      aisummonid = v7->aisummonid;
      nbSetEnemySummonFormation(p_data, aisummonid);
      v7 = *a;
      work = (*a)->work;
      v5 = 8;
    }
  }
  nbGetTargetTypeRuleArea(v7, work, &crule[1], crule, &carea, 0);
  nbSetSelectOkMark((*a)->partyindex, crule[1], crule[0], carea, 0);
  if (!crule[1])
  {
    result = SetSingleTarget2(a, v5, n);
    if (!result)
      return result;
LABEL_27:
    (*a)->work->nowcommand = 3;
    (*a)->work->nowindex = 0;
    return result;
  }
  if ((crule[1] - 1) > 1)
    return 0;
  result = SetGroupTarget2(a, v5, n);
  if (result)
    goto LABEL_27;
  return result;
}
