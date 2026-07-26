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
  nbBadAi_c *v5;
  s32 *static_fields;
  s64 v7;
  s64 v9;
  struct nbBadAi_StaticFields *v11;
  s64 ritulistcnt;
  System_Int32_array *v14;

  static_fields = v5->static_fields;
  v7 = static_fields[2];
  v9 = *(*static_fields + 8 * v7 + 32);
  *(v9 + 32) = type;
  v11 = nbBadAi->static_fields;
  ritulistcnt = v11->ritulistcnt;
  v14 = v11->ritulist->m_Items[ritulistcnt];
  v14->m_Items[1] = ritu;
  ++ritulistcnt;
}

// 0xfac170
s32 BadAttack(nbActionProcessData_t **a) {
    SetTarget(0);
    nbGetUnitWorkFromFormindex(0);
    nbSetJyokyoMes(0, 0, 0, 0);
    return 0;
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
  }
  if (v4 == 8)
  {
    id = work->id;
    v6 = a;
    v7 = 48;
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
    SetTarget(0);
    nbSetJyokyoMes(0, 0, 0, 0);
    return 0;
}

// 0xfac5d0
s32 BadNego(nbActionProcessData_t **a) {
    SetTarget(0);
    nbSetJyokyoMes(0, 0, 0, 0);
    return 0;
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
  }
  result = 0;
  if (v5 == 8)
  {
    id = v4->id;
    v8 = 46;
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
      if (++v10 == 3)
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
      else if ((v17 - 36) <= 5)
      {
        v20 = v8 + 2 * v11++;
        *(v20 + 16) = v17;
      }
      if (++v12 == 5)
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
        v45 = v8 + 2 * v11++;
        *(v45 + 16) = v43;
      }
      work = (*a)->work;
      if (++v40 >= work->skillcnt)
      {
        if (v11)
        {
          RandIntA = dds3GetRandIntA(v11, StringLiteral_21100);
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
        v38 = v8 + 2 * v11++;
        *(v38 + 16) = v36;
      }
      work = (*a)->work;
      if (++v33 >= work->skillcnt)
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
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xface80
void MakeRituList(nbActionProcessData_t **a) {
    nbGetUnitWorkFromFormindex(0);
    AddRituList(0, 0);
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
    }
    v10 = v7;
    ++v7;
    *(v3 + v10 + 32) = v6++;
  }
  while (v6 != 16);
  if (v7 >= 1)
  {
    RandIntA = dds3GetRandIntA(v7, StringLiteral_21099);
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
    MakeRituList(0);
    GetBadAiAction(0);
    BadBadWait(0);
    BadAttack(0);
    BadKaifuku(0);
    BadKaja(0);
    BadMaka(0);
    BadNego(0);
    BadReturn(0);
    nbSetJyokyoMes(0, 0, 0, 0);
    return 0;
}
