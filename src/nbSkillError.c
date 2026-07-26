#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbParty_t nbParty_t;

s32 CheckDeadUnit(void);
s32 CheckHojo(nbParty_t **list, s32 cnt, u32 hojo);
void nbDispMsgHelp(s32 msgid, s32 no, s32 msgtype);
s32 nbGetHojoCounterMax(s32 hojotype);
s32 nbGetHojoCounterMin(s32 hojotype);
nbMainProcessData_t *nbGetMainProcessData(void);
nbParty_t *nbGetPartyFromFormindex(s32 formindex);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
s32 p2sdPlaySE(s32 a);

// 0x157dc60
s32 CheckBad(datUnitWork_t **list, s32 cnt, u32 bad) {
  u64 v4;

  if (cnt < 1)
    return 0;
  v4 = 0;
  while (1)
  {
    if ((list->m_Items[v4]->badstatus & bad & 0xFFF) != 0)
      break;
    if (++v4 >= cnt)
      return 0;
  }
  return 1;
}

// 0x157d910
s32 CheckDeadUnit(void) {
  s64 i;
  u64 v4;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v8;

  for (i = 4; ; ++i)
  {
    v4 = i - 4;
    unitwork = DDS3_GBWK->unitwork;
    if ((*(*(&unitwork->obj.klass + i) + 16LL) & 1) != 0)
    {
      v8 = DDS3_GBWK->unitwork;
      if ((*(*(&v8->obj.klass + i) + 30LL) & 0xFFF) == 0x800)
        break;
    }
    if (v4 >= 0xF)
      return 0;
  }
  return 1;
}

// 0x157da30
s32 CheckDeadUnit2(datUnitWork_t **list, s32 cnt) {
  u64 v3;

  if (cnt < 1)
    return 0;
  v3 = 0;
  while (1)
  {
    if ((list->m_Items[v3]->badstatus & 0xFFF) == 0x800)
      break;
    if (++v3 >= cnt)
      return 0;
  }
  return 1;
}

// 0x157dcf0
s32 CheckHojo(nbParty_t **list, s32 cnt, u32 hojo) {
  u64 v6;
  signed s64 v7;
  nbParty_t_o **m_Items;
  nbParty_t_o *v10;
  struct System_Int16_array *count;
  s32 v13;
  struct System_Int16_array *v14;
  s32 v16;
  struct System_Int16_array *v17;
  s32 v19;
  struct System_Int16_array *v20;
  s32 v22;
  struct System_Int16_array *v23;
  s32 v25;
  struct System_Int16_array *v26;
  s32 v28;
  struct System_Int16_array *v29;
  s32 v31;
  struct System_Int16_array *v32;
  s32 v34;
  struct System_Int16_array *v35;
  s32 v37;
  struct System_Int16_array *v38;
  s32 v40;
  struct System_Int16_array *v41;
  s32 v43;
  struct System_Int16_array *v44;
  s32 v46;
  struct System_Int16_array *v47;
  s32 v49;
  struct System_Int16_array *v50;
  s32 v52;
  struct System_Int16_array *v53;
  s32 v55;
  struct System_Int16_array *v56;
  s32 v58;
  struct System_Int16_array *v59;
  s32 v61;

  if (cnt < 1)
    return 0;
  v6 = 0;
  v7 = cnt;
  m_Items = list->m_Items;
  while (1)
  {
    v10 = m_Items[v6];
    if ((hojo & 1) != 0)
    {
      count = v10->count;
      v13 = count->m_Items[4];
      if (nbGetHojoCounterMax(4) != v13)
        break;
    }
    if ((hojo & 2) != 0)
    {
      v14 = v10->count;
      v16 = v14->m_Items[4];
      if (nbGetHojoCounterMin(4) != v16)
        break;
    }
    if ((hojo & 4) != 0)
    {
      v17 = v10->count;
      v19 = v17->m_Items[5];
      if (nbGetHojoCounterMax(5) != v19)
        break;
    }
    if ((hojo & 8) != 0)
    {
      v20 = v10->count;
      v22 = v20->m_Items[5];
      if (nbGetHojoCounterMin(5) != v22)
        break;
    }
    if ((hojo & 0x10) != 0)
    {
      v23 = v10->count;
      v25 = v23->m_Items[6];
      if (nbGetHojoCounterMax(6) != v25)
        break;
    }
    if ((hojo & 0x20) != 0)
    {
      v26 = v10->count;
      v28 = v26->m_Items[6];
      if (nbGetHojoCounterMin(6) != v28)
        break;
    }
    if ((hojo & 0x40) != 0)
    {
      v29 = v10->count;
      v31 = v29->m_Items[7];
      if (nbGetHojoCounterMax(7) != v31)
        break;
    }
    if ((hojo & 0x80) != 0)
    {
      v32 = v10->count;
      v34 = v32->m_Items[7];
      if (nbGetHojoCounterMin(7) != v34)
        break;
    }
    if ((hojo & 0x100) != 0)
    {
      v35 = v10->count;
      v37 = v35->m_Items[8];
      if (nbGetHojoCounterMax(8) != v37)
        break;
    }
    if ((hojo & 0x200) != 0)
    {
      v38 = v10->count;
      v40 = v38->m_Items[8];
      if (nbGetHojoCounterMin(8) != v40)
        break;
    }
    if ((hojo & 0x1000) != 0)
    {
      v41 = v10->count;
      v43 = v41->m_Items[9];
      if (nbGetHojoCounterMax(9) != v43)
        break;
    }
    if ((hojo & 0x2000) != 0)
    {
      v44 = v10->count;
      v46 = v44->m_Items[10];
      if (nbGetHojoCounterMax(10) != v46)
        break;
    }
    if ((hojo & 0x4000) != 0)
    {
      v47 = v10->count;
      v49 = v47->m_Items[11];
      if (nbGetHojoCounterMax(11) != v49)
        break;
    }
    if ((hojo & 0x8000) != 0)
    {
      v50 = v10->count;
      v52 = v50->m_Items[12];
      if (nbGetHojoCounterMax(12) != v52)
        break;
    }
    if ((hojo & 0x10000) != 0)
    {
      v53 = v10->count;
      v55 = v53->m_Items[13];
      if (nbGetHojoCounterMax(13) != v55)
        break;
    }
    if ((hojo & 0x20000) != 0)
    {
      v56 = v10->count;
      v58 = v56->m_Items[14];
      if (nbGetHojoCounterMax(14) != v58)
        break;
    }
    if ((hojo & 0x1000000) != 0)
    {
      v59 = v10->count;
      v61 = v59->m_Items[15];
      if (nbGetHojoCounterMax(15) != v61)
        break;
    }
    if (++v6 >= v7)
      return 0;
  }
  return 1;
}

// 0x157dac0
s32 CheckMaxHp(datUnitWork_t **list, s32 cnt) {
  u64 v3;

  if (cnt < 1)
    return 1;
  v3 = 0;
  while (1)
  {
    if (list->m_Items[v3]->hp < list->m_Items[v3]->maxhp)
      break;
    if (++v3 >= cnt)
      return 1;
  }
  return 0;
}

// 0x157db90
s32 CheckMaxMp(datUnitWork_t **list, s32 cnt) {
  u64 v3;

  if (cnt < 1)
    return 1;
  v3 = 0;
  while (1)
  {
    if (list->m_Items[v3]->mp < list->m_Items[v3]->maxmp)
      break;
    if (++v3 >= cnt)
      return 1;
  }
  return 0;
}

// 0x157e380
s32 nbCheckBattleSkillError1(s32 nskill) {
  if ((nskill - 49) > 1 || CheckDeadUnit(*&nskill))
    return 0;
  else
    return 2;
}

// 0x157e3b0
s32 nbCheckBattleSkillError2(s32 nskill, u32 select) {
    nbGetMainProcessData();
    nbGetUnitWorkFromFormindex(0);
    nbGetPartyFromFormindex(0);
    CheckHojo(0, 0, 0);
    return 0;
}

// 0x157eb70
s32 nbCheckBattleSkillError3(s32 nskill, u32 select) {
  u32 *v4;
  nbParty_t_array *v6;
  u32 v9;
  s32 v10;
  s32 i;
  s64 *UnitWorkFromFormindex;
  s64 *PartyFromFormindex;
  s64 *v17;
  u32 *v19;
  s64 *v20;
  Il2CppClass **v22;
  struct datNormalSkill_t_array *tbl;

  v4 = NewSpecific(datUnitWork_t, 0x20u);
  v6 = NewSpecific(nbParty_t, 0x20u);
  nbGetMainProcessData();
  v9 = 0;
  v10 = 0;
  for (i = 0; i != 16; ++i)
  {
    if (((1 << i) & select) == 0)
      continue;
    else
    {
      UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(i);
      if (!UnitWorkFromFormindex)
    }
    v17 = UnitWorkFromFormindex;
    v19 = &v4[2 * v9++];
    *(v19 + 4) = v17;
    else
    {
      PartyFromFormindex = nbGetPartyFromFormindex(i);
      if (!PartyFromFormindex)
        continue;
    }
    v20 = PartyFromFormindex;
    v22 = &v6->obj.klass + v10++;
    v22[4] = v20;
  }
  if (!v9)
    return 0;
  if (nskill <= 67)
  {
    if ((nskill - 52) >= 3 && (nskill & 0xFFFFFFFC) != 0x40)
      return 0;
    if (CheckHojo(v6, v10, tbl->m_Items[nskill]->hojotype))
      return 0;
    else
      return 3;
  }
  else
  {
    if ((nskill - 203) < 4 || nskill == 276 || nskill == 265)
    return 0;
  }
}

// 0x157ee60
s32 nbCheckCampSkillError(s32 nskill, u32 select) {
  u64 *v6;
  u64 v7;
  s32 v8;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v13;
  u64 *v15;
  s32 result;
  u64 v18;
  struct datNormalSkill_t_array *tbl;
  u64 v23;
  u16 v24;
  u64 v26;
  u64 v28;
  u64 v30;
  u64 v32;

  v6 = NewSpecific(datUnitWork_t, 0x20u);
  v7 = 0;
  v8 = 0;
  do
  {
    if (((1 << v7) & select) != 0)
    {
      unitwork = DDS3_GBWK->unitwork;
      v13 = unitwork->m_Items[v7];
      if ((v13->flag & 1) != 0)
      {
        v15 = &v6[v8++];
        v15[4] = v13;
      }
    }
    ++v7;
  }
  while (v7 != 16);
  if ((nskill - 49) < 2)
  if ((nskill - 73) >= 4 && v8 == 1)
  {
    if ((*(v6[4] + 30LL) & 0xFFF) == 0x800)
      return 1;
  }
  if (nskill <= 240)
  {
    result = 0;
    switch (nskill)
    {
      case '$':
      case '%':
      case '&':
      case '\'':
      case '(':
      case ')':
      case 'Q':
      case '^':
        if (v8 < 1)
          return 1;
        v18 = 0;
        while (1)
        {
          if (*(v6[v18 + 4] + 22LL) < *(v6[v18 + 4] + 24LL))
            break;
          if (++v18 >= v8)
            return 1;
        }
        return 0;
      case '*':
      case 'R':
      case 'S':
      case 'T':
      case ']':
        if (v8 < 1)
          return 1;
        v26 = 0;
        while (1)
        {
          if (*(v6[v26 + 4] + 26LL) < *(v6[v26 + 4] + 28LL))
            break;
          ++v26;
          result = 1;
          if (v26 >= v8)
            return result;
        }
        return 0;
      case '+':
      case ',':
      case '-':
      case '.':
      case '/':
      case '0':
      case 'X':
        if (v8 < 1)
          return 1;
        v23 = 0;
        v24 = tbl->m_Items[nskill]->basstatus & 0xFFF;
        while (1)
        {
          if ((v24 & *(v6[v23 + 4] + 30LL)) != 0)
            break;
          ++v23;
          result = 1;
          if (v23 >= v8)
            return result;
        }
        return 0;
      case '1':
      case '2':
        if (v8 < 1)
          return 1;
        v28 = 0;
        break;
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case ':':
      case ';':
      case '<':
      case '=':
      case '>':
      case '?':
      case '@':
      case 'A':
      case 'B':
      case 'C':
      case 'D':
      case 'E':
      case 'F':
      case 'G':
      case 'H':
      case 'M':
      case 'N':
      case 'O':
      case 'W':
      case 'Y':
      case 'Z':
      case '[':
        return result;
      case 'I':
        if ((DDS3_GBWK->stat & 1) == 0)
          return 0;
        return 4;
      case 'J':
        if ((DDS3_GBWK->stat & 2) == 0)
          return 0;
        return 4;
      case 'K':
        if ((DDS3_GBWK->stat & 4) == 0)
          return 0;
        return 4;
      case 'L':
        if ((DDS3_GBWK->stat & 8) == 0)
          return 0;
        return 4;
      case 'P':
      case 'U':
      case 'V':
      case '\\':
      default:
        if ((nskill - 237) <= 3)
        return 0;
    }
    while (1)
    {
      if ((*(v6[v28 + 4] + 30LL) & 0xFFF) == 0x800)
        break;
      ++v28;
      result = 1;
      if (v28 >= v8)
        return result;
    }
    return 0;
  }
  if (nskill == 246 || nskill == 248)
  {
    if (v8 >= 1)
    {
      v30 = 0;
      while (1)
      {
        if (*(v6[v30 + 4] + 22LL) < *(v6[v30 + 4] + 24LL))
          break;
        if (++v30 >= v8)
        {
          v32 = 0;
          while (1)
          {
            if (*(v6[v32 + 4] + 26LL) < *(v6[v32 + 4] + 28LL))
              break;
            if (++v32 >= v8)
              return 1;
          }
          return 0;
        }
      }
      return 0;
    }
    return 1;
  }
  return 0;
}

// 0x157e190
void nbDispSkillErrorMessage(s32 err) {
  nbMainProcessData_t_o *MainProcessData;
  s32 jyokyomsgid;
  s32 v6;

  MainProcessData = nbGetMainProcessData();
  if (err == 4)
  if (err == 2)
  {
    jyokyomsgid = MainProcessData->jyokyomsgid;
    v6 = 66;
    nbDispMsgHelp(jyokyomsgid, v6, 3);
  }
  if ((err - 1) > 1)
    return;
  p2sdPlaySE(13);
}
