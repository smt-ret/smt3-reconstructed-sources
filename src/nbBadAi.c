#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbActionProcessData_t nbActionProcessData_t;
typedef struct nbDebugProcessData_t nbDebugProcessData_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

static s32 *ritulist[10];
static s32 ritulistcnt;

void AddRituList(s32 type, s32 ritu);
s32 BadAttack(nbActionProcessData_t **a);
s32 BadBadWait(nbActionProcessData_t **a);
s32 BadKaifuku(nbActionProcessData_t **a);
s32 BadKaja(nbActionProcessData_t **a);
s32 BadMaka(nbActionProcessData_t **a);
s32 BadNego(nbActionProcessData_t **a);
s32 BadReturn(nbActionProcessData_t **a);
u8 Get(s32 id);
s32 GetBadActionSkill(nbActionProcessData_t **a, s32 type);
s32 GetBadAiAction(nbActionProcessData_t **a);
void MakeRituList(nbActionProcessData_t **a);
void SetGroupTarget(nbActionProcessData_t **a);
void SetSingleTarget(nbActionProcessData_t **a);
void SetTarget(nbDebugProcessData_t **d);
u32 dds3GetRandIntA(u32 aLimit, char *name);
u32 nbGetSelectBit(nbMainProcessData_t *data);
void nbGetTargetTypeRuleArea(nbActionProcessData_t *a, datUnitWork_t *work, s32 *ctype, s32 *crule, s32 *carea, s32 rev);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
void nbSetJyokyoMes(nbActionProcessData_t **a, s32 jyokyomes, s32 var_id, s32 var_ind);
s32 nbSetSelectOkMark(s32 partyindex, s32 ctype, s32 crule, s32 carea);

// 0xfacd50
void AddRituList(s32 type, s32 ritu) {
  s32 *static_fields;
  s64 v7;
  s64 v9;
  s64 ritulistcnt;
  System_Int32_array *v14;

  v7 = static_fields[2];
  v9 = *(*static_fields + 8 * v7 + 32);
  *(v9 + 32) = type;
  v14 = ritulist->m_Items[ritulistcnt];
  v14->m_Items[1] = ritu;
  ++ritulistcnt;
}

// 0xfac170
s32 BadAttack(nbActionProcessData_t **a) {
  s32 v4;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct datUnitWork_t_o *work;
  s32 v10;
  s32 id;
  s32 v12;

  (*a)->work->nowcommand = 0;
  (*a)->work->nowindex = 0;
  v4 = 1;
  if (SetTarget(a, 1))
  {
    formindex = (*a)->form->formindex;
    else
    {
      UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
      if (UnitWorkFromFormindex)
        goto LABEL_12;
    }
    work = (*a)->work;
    v10 = work->badstatus & 0xFFF;
    if (v10 != 128)
    {
LABEL_14:
      if (v10 != 8)
      {
LABEL_30:
        v4 = 0;
        (*a)->stat |= 0x200u;
        return v4;
      }
      id = work->id;
      v12 = 46;
LABEL_29:
      nbSetJyokyoMes(a, v12, 1, id);
      goto LABEL_30;
    }
LABEL_25:
    id = work->id;
    v12 = 54;
    goto LABEL_29;
  }
  return v4;
}

// 0xfac860
s32 BadBadWait(nbActionProcessData_t **a) {
  struct datUnitWork_t_o *work;
  s32 v4;
  s32 id;
  nbActionProcessData_t_o **v6;
  s32 v7;

  (*a)->work->nowcommand = 8;
  (*a)->work->nowindex = 0;
  work = (*a)->work;
  v4 = work->badstatus & 0xFFF;
  if (v4 == 128)
  {
    id = work->id;
    v6 = a;
    v7 = 56;
    goto LABEL_13;
  }
  if (v4 == 8)
  {
    id = work->id;
    v6 = a;
    v7 = 48;
LABEL_13:
    nbSetJyokyoMes(v6, v7, 1, id);
  }
  return 0;
}

// 0xfac950
s32 BadDamage(nbActionProcessData_t **a) {
  s32 id;

  (*a)->work->nowcommand = 10;
  (*a)->work->nowindex = 0;
  id = (*a)->work->id;
  nbSetJyokyoMes(a, 76, 1, id);
  return 0;
}

// 0xfac020
s32 BadKaifuku(nbActionProcessData_t **a) {
  s32 BadActionSkill;
  s32 v7;
  struct datUnitWork_t_o *work;
  s32 v10;
  s32 id;
  s32 v12;

  BadActionSkill = GetBadActionSkill(a, 2);
  v7 = 1;
  if ((BadActionSkill & 0x80000000) == 0)
  {
    (*a)->work->nowcommand = 1;
    (*a)->work->nowindex = BadActionSkill;
    v7 = 1;
    if (SetTarget(a, 1))
    {
      work = (*a)->work;
      v10 = work->badstatus & 0xFFF;
      if (v10 == 128)
      {
        id = work->id;
        v12 = 54;
      }
      else
      {
        if (v10 != 8)
          return 0;
        id = work->id;
        v12 = 46;
      }
      nbSetJyokyoMes(a, v12, 1, id);
      return 0;
    }
  }
  return v7;
}

// 0xfabed0
s32 BadKaja(nbActionProcessData_t **a) {
  s32 BadActionSkill;
  s32 v7;
  struct datUnitWork_t_o *work;
  s32 v10;
  s32 id;
  s32 v12;

  BadActionSkill = GetBadActionSkill(a, 3);
  v7 = 1;
  if ((BadActionSkill & 0x80000000) == 0)
  {
    (*a)->work->nowcommand = 1;
    (*a)->work->nowindex = BadActionSkill;
    v7 = 1;
    if (SetTarget(a, 1))
    {
      work = (*a)->work;
      v10 = work->badstatus & 0xFFF;
      if (v10 == 128)
      {
        id = work->id;
        v12 = 54;
      }
      else
      {
        if (v10 != 8)
          return 0;
        id = work->id;
        v12 = 46;
      }
      nbSetJyokyoMes(a, v12, 1, id);
      return 0;
    }
  }
  return v7;
}

// 0xfac3f0
s32 BadMaka(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v4;
  struct datUnitWork_t_o *work;
  struct nbParty_t_o *party;
  s32 result;

  v4 = *a;
  if ((*a)->form->formindex <= 3)
  {
    else if (DDS3_GBWK->maka)
    {
LABEL_7:
      v4 = *a;
      goto LABEL_8;
    }
    return 1;
  }
LABEL_8:
  work = v4->work;
  party = v4->party;
  result = 1;
  if ((work->flag & 0x20) == 0 || (party->flag & 0x800) == 0)
  {
    party->flag |= 0x800u;
    (*a)->work->nowcommand = 1;
    (*a)->work->nowindex = 247;
    else if (SetTarget(a, 0))
    {
      goto LABEL_13;
    }
    return 1;
  }
  return result;
}

// 0xfac5d0
s32 BadNego(nbActionProcessData_t **a) {
  struct datUnitWork_t_o *work;

  if ((*a)->form->formindex > 3)
    return 1;
  (*a)->work->nowcommand = 4;
  (*a)->work->nowindex = 384;
  (*a)->negotype = 6;
  else if (SetTarget(a, 0))
  {
    goto LABEL_7;
  }
  return 1;
}

// 0xfac740
s32 BadReturn(nbActionProcessData_t **a) {
  struct datUnitWork_t_o *work;
  struct datUnitWork_t_o *v4;
  s32 v5;
  s32 result;
  s32 id;
  s32 v8;

  work = (*a)->work;
  if ((work->flag & 4) != 0)
    return 1;
  if (work->id > 0xFFu)
    return 1;
  work->nowcommand = 7;
  (*a)->work->nowindex = 0;
  v4 = (*a)->work;
  v5 = v4->badstatus & 0xFFF;
  if (v5 == 128)
  {
    id = v4->id;
    v8 = 54;
    goto LABEL_18;
  }
  result = 0;
  if (v5 == 8)
  {
    id = v4->id;
    v8 = 46;
LABEL_18:
    nbSetJyokyoMes(a, v8, 1, id);
    return 0;
  }
  return result;
}

// 0xfab970
s32 CheckBadActionSkill(s32 skill, s32 type) {
  if (type == 3)
  {
    if ((skill - 64) < 5)
      return 1;
  }
  else if (type == 2 && (skill - 36) < 6)
  {
    return 1;
  }
  return 0;
}

// 0xfab9b0
s32 GetBadActionSkill(nbActionProcessData_t **a, s32 type) {
  u64 *v5;
  struct datUnitWork_t_o *work;
  u64 *v8;
  s32 id;
  u64 v10;
  u32 v11;
  u64 v12;
  struct datDevilAITbl_s_array_array *v13;
  datDevilAITbl_s_array *v15;
  s32 v17;
  bool v18;
  char *v20;
  u64 i;
  struct datDevilAITbl_s_array_array *aitable;
  datDevilAITbl_s_array *v24;
  s32 skill;
  bool v27;
  char *v29;
  u32 RandIntA;
  s32 v32;
  u64 v33;
  struct System_Int32_array *v34;
  s32 v36;
  char *v38;
  u64 v40;
  struct System_Int32_array *v41;
  s32 v43;
  char *v45;
  s32 v46;

  v5 = NewSpecific(s16, 0x40u);
  work = (*a)->work;
  v8 = v5;
  if ((*a)->form->formindex > 3)
  {
    id = work->id;
    v10 = 0;
    v11 = 0;
    while (type != 2)
    {
      for (i = 0; i != 5; ++i)
      {
        aitable = Get(id, 0)->aitable;
        v24 = aitable->m_Items[v10];
        skill = v24->m_Items[i]->skill;
        if (skill)
          v27 = (skill & 0x8000) == 0;
        else
          v27 = 0;
        if (v27)
        {
          if (type == 3 && (skill - 64) <= 4)
          {
            v29 = v8 + 2 * v11++;
            *(v29 + 16) = skill;
          }
        }
      }
LABEL_51:
      if (++v10 == 3)
        goto LABEL_52;
    }
    v12 = 0;
    while (1)
    {
      v13 = Get(id, 0)->aitable;
      v15 = v13->m_Items[v10];
      v17 = v15->m_Items[v12]->skill;
      if (v17)
        v18 = (v17 & 0x8000) == 0;
      else
        v18 = 0;
      if (!v18)
        goto LABEL_27;
      else if ((v17 - 36) <= 5)
      {
LABEL_24:
        v20 = v8 + 2 * v11++;
        *(v20 + 16) = v17;
      }
LABEL_27:
      if (++v12 == 5)
        goto LABEL_51;
    }
  }
  if (work->skillcnt < 1)
    return -1;
  if (type == 2)
  {
    v40 = 0;
    v11 = 0;
    while (1)
    {
      v41 = work->skill;
      v43 = v41->m_Items[v40];
      else if ((v43 - 36) <= 5)
      {
LABEL_85:
        v45 = v8 + 2 * v11++;
        *(v45 + 16) = v43;
      }
      work = (*a)->work;
      if (++v40 >= work->skillcnt)
      {
LABEL_52:
        if (v11)
        {
          RandIntA = dds3GetRandIntA(v11, "GetBadActionSkill");
          return *(v8 + RandIntA + 16);
        }
        return -1;
      }
    }
  }
  if (type == 3)
  {
    v33 = 0;
    v11 = 0;
    while (1)
    {
      v34 = work->skill;
      v36 = v34->m_Items[v33];
      else if ((v36 - 64) <= 4)
      {
LABEL_70:
        v38 = v8 + 2 * v11++;
        *(v38 + 16) = v36;
      }
      work = (*a)->work;
      if (++v33 >= work->skillcnt)
        goto LABEL_52;
    }
  }
  v46 = 0;
  v32 = -1;
  do
  {
    work = (*a)->work;
    ++v46;
  }
  while (v46 < work->skillcnt);
  return v32;
}

// 0xfaca00
s32 GetBadAiAction(nbActionProcessData_t **a) {
  u64 v2;
  u32 v3;
  s32 *static_fields;
  struct System_Int32_array_array *ritulist;
  System_Int32_array *v8;
  signed s32 RandIntA;
  signed s32 v12;
  s64 v13;
  s32 v14;
  u64 v16;
  s32 *v17;
  struct System_Int32_array_array *v18;
  s64 v19;
  struct System_Int32_array_array *v21;
  s64 v22;
  struct System_Int32_array_array *v28;
  s64 v30;

  v2 = 0;
  v3 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    if (v2 >= static_fields[2])
      break;
    else
    {
      ritulist = *static_fields;
      if (v2 >= *(*static_fields + 24LL))
        goto LABEL_12;
    }
    v8 = ritulist->m_Items[v2];
    v3 += v8->m_Items[1];
    ++v2;
      goto LABEL_6;
  }
  if (!v3)
    return -1;
  RandIntA = dds3GetRandIntA(v3, "GetBadAiAction");
  v12 = 0;
  v13 = 4;
  v14 = 9;
  v16 = 0;
  {
LABEL_24:
  }
  while (1)
  {
    if (v16 >= v17[2])
      return v14;
    else
    {
      v18 = *v17;
      if (v16 >= *(*v17 + 24LL))
        goto LABEL_42;
    }
    v19 = *(&v18->obj.klass + v13);
    if (*(v19 + 36))
    {
      v21 = ritulist;
      v22 = *(&v21->obj.klass + v13);
      v12 += *(v22 + 36);
      if (RandIntA < v12)
      {
        v28 = ritulist;
        v30 = *(&v28->obj.klass + v13);
        return *(v30 + 32);
      }
    }
    ++v13;
    v16 = v13 - 4;
      goto LABEL_24;
  }
}

// 0xface80
void MakeRituList(nbActionProcessData_t **a) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 v7;
  s32 v8;
  s32 v9;
  datUnitWork_t_o *v10;
  s32 v12;
  nbActionProcessData_t_o *v13;
  u32 flag;
  s32 v15;
  s32 v16;
  s32 v17;
  s64 v18;
  u64 v20;

  formindex = (*a)->form->formindex;
  else
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    if (!UnitWorkFromFormindex)
      goto LABEL_12;
  }
  v7 = UnitWorkFromFormindex->badstatus & 0xFFF;
  if (v7 == 8)
    goto LABEL_18;
  if (v7 == 128)
  {
    v8 = 1;
    goto LABEL_19;
  }
LABEL_12:
  v9 = (*a)->form->formindex;
  v10 = nbGetUnitWorkFromFormindex(v9);
  if (!v10)
    goto LABEL_18;
LABEL_17:
  if ((v10->badstatus & 0x80000000) == 0)
    goto LABEL_18;
  v8 = 2;
LABEL_19:
  v12 = 0;
  ritulistcnt = 0;
  while (1)
  {
    if (v8 == 2)
    {
      if (v12 == 7)
      {
        v15 = 7;
      }
      else
      {
        if (v12 != 1)
          goto LABEL_87;
        v15 = 1;
      }
      v16 = 50;
      goto LABEL_86;
    }
    if (v8 == 1)
    {
      switch (v12)
      {
        case 1:
          v15 = 1;
          v16 = 40;
          goto LABEL_86;
        case 2:
          v15 = 2;
          v16 = 20;
          goto LABEL_86;
        case 3:
          v15 = 3;
          v16 = 20;
          goto LABEL_86;
        case 9:
          goto LABEL_89;
        default:
          goto LABEL_87;
      }
    }
    v13 = *a;
    flag = (*a)->work->flag;
    if ((flag & 4) != 0)
    {
      if (v12 != 4)
      {
        if (v12 == 5)
        {
          if ((v13->data->stat & 1) == 0)
          {
            v15 = 5;
            v16 = 30;
            goto LABEL_86;
          }
        }
        else if (v12 == 9)
        {
LABEL_89:
          v17 = 20;
          goto LABEL_93;
        }
        goto LABEL_87;
      }
LABEL_65:
      v15 = 4;
      v16 = 20;
LABEL_86:
      AddRituList(v15, v16);
      goto LABEL_87;
    }
    if ((flag & 0x20) == 0)
    {
      switch (v12)
      {
        case 4:
          goto LABEL_65;
        case 5:
          if ((v13->data->stat & 1) != 0)
            goto LABEL_87;
          v15 = 5;
          v16 = 20;
          break;
        case 6:
          v15 = 6;
          v16 = 10;
          goto LABEL_86;
        case 9:
          goto LABEL_89;
        default:
          goto LABEL_87;
      }
      goto LABEL_86;
    }
    if (v12 == 4)
    {
      v15 = 4;
      v16 = 30;
      goto LABEL_86;
    }
    if (v12 == 6)
    {
      v15 = 6;
      v16 = 20;
      goto LABEL_86;
    }
    if (v12 == 9)
      break;
LABEL_87:
    if (++v12 == 10)
      goto LABEL_94;
  }
  v17 = 40;
LABEL_93:
  AddRituList(9, v17);
LABEL_94:
  v18 = 4;
  v20 = 0;
    goto LABEL_99;
LABEL_95:
  else
  {
    if (v20 < ritulistcnt)
      goto LABEL_100;
  }
}

// 0xfab740
void SetGroupTarget(nbActionProcessData_t **a) {
  s64 i;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v5;

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
    v5 = (*a)->data->form;
    *(*(&v5->obj.klass + i) + 136LL) |= 8u;
  }
}

// 0xfab590
void SetSingleTarget(nbActionProcessData_t **a) {
  u64 *v3;
  u64 *v5;
  u64 v6;
  signed s32 v7;
  struct nbFormation_t_array *form;
  s64 v10;
  u32 RandIntA;
  struct nbFormation_t_array *v14;
  s64 v15;

  v3 = NewSpecific(sbyte, 0x20u);
  v5 = v3;
  v6 = 0;
  v7 = 0;
  do
  {
    while (1)
    {
      form = (*a)->data->form;
      if ((form->m_Items[v6]->stat & 4) != 0)
        break;
      if (++v6 == 16)
        goto LABEL_12;
    }
    v10 = v7;
    ++v7;
    *(v3 + v10 + 32) = v6++;
  }
  while (v6 != 16);
LABEL_12:
  if (v7 >= 1)
  {
    RandIntA = dds3GetRandIntA(v7, "SetSingleTarget");
    v14 = (*a)->data->form;
    v15 = *(v5 + RandIntA + 32);
    v14->m_Items[v15]->stat |= 8u;
  }
}

// 0xfab800
s32 SetTarget(nbActionProcessData_t **a, s32 rev) {
  nbActionProcessData_t_o *v5;
  datUnitWork_t_o *work;
  s32 result;
  nbActionProcessData_t_o *v9;
  nbMainProcessData_t_o *data;
  s32 carea;
  s32 crule[2];

  *crule = 0;
  carea = 0;
  v5 = *a;
  work = (*a)->work;
  nbGetTargetTypeRuleArea(v5, work, &crule[1], crule, &carea, rev);
  result = nbSetSelectOkMark((*a)->partyindex, crule[1], crule[0], carea, 0);
  if (result)
  {
    if (crule[1])
    {
      if ((crule[1] - 1) <= 1)
      {
        SetGroupTarget(a);
      }
    }
    else
    {
      SetSingleTarget(a);
    }
    v9 = *a;
    data = (*a)->data;
    v9->select = nbGetSelectBit(data);
    return 1;
  }
  return result;
}

// 0xfad500
s32 nbRunBadAi(nbActionProcessData_t **a) {
  s32 v4;
  s32 v5;
  nbActionProcessData_t_o **v6;
  s32 BadAiAction;
  s64 v8;
  u64 v10;
  s32 *static_fields;
  struct System_Int32_array_array *ritulist;
  s64 v13;
  struct System_Int32_array_array *v17;
  s64 v19;
  s32 id;

  MakeRituList(a);
  v4 = 0;
  v5 = 1;
  while (1)
  {
    BadAiAction = GetBadAiAction(v6);
    switch (BadAiAction)
    {
      case 0:
      case 9:
        BadBadWait(a);
        v5 = 0;
        if (++v4 >= 0xB)
          goto LABEL_92;
        goto LABEL_76;
      case 1:
        else
        {
          v5 = BadAttack(a);
          if (BadAiAction < 0)
            goto LABEL_75;
        }
        break;
      case 2:
        else
        {
          v5 = BadKaifuku(a);
          if (BadAiAction < 0)
            goto LABEL_75;
        }
        break;
      case 3:
        else
        {
          v5 = BadKaja(a);
          if (BadAiAction < 0)
            goto LABEL_75;
        }
        break;
      case 4:
        else
        {
          v5 = BadMaka(a);
          if (BadAiAction < 0)
            goto LABEL_75;
        }
        break;
      case 5:
        else
        {
          v5 = BadNego(a);
          if (BadAiAction < 0)
            goto LABEL_75;
        }
        break;
      case 6:
        else
        {
          v5 = BadReturn(a);
          if (BadAiAction < 0)
            goto LABEL_75;
        }
        break;
      case 7:
        if ((byte_3F58691 & 1) == 0)
          goto LABEL_70;
LABEL_71:
        (*a)->work->nowcommand = 10;
        (*a)->work->nowindex = 0;
        id = (*a)->work->id;
        nbSetJyokyoMes(a, 76, 1, id);
        v5 = 0;
        goto LABEL_75;
      case 8:
        goto LABEL_17;
      default:
        v5 = 1;
LABEL_17:
        if ((BadAiAction & 0x80000000) == 0)
          break;
        goto LABEL_75;
    }
    if (!v5)
      goto LABEL_75;
    v8 = 4;
    v10 = 0;
      goto LABEL_24;
LABEL_22:
    while (1)
    {
LABEL_24:
      if (v10 >= static_fields[2])
        goto LABEL_75;
      else
      {
        ritulist = *static_fields;
        if (v10 >= *(*static_fields + 24LL))
          goto LABEL_32;
      }
      v13 = *(&ritulist->obj.klass + v8);
      if (*(v13 + 32) == BadAiAction)
        break;
      ++v8;
      v10 = v8 - 4;
        goto LABEL_22;
    }
    v17 = ritulist;
    v19 = *(&v17->obj.klass + v8);
    *(v19 + 36) = 0;
    if (++v4 >= 0xB)
      break;
LABEL_76:
    if (!v5)
      return 0;
  }
LABEL_92:
  BadBadWait(a);
  return 0;
}
