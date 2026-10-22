#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbActionProcessData_t nbActionProcessData_t;
typedef struct nbCommSelProcessData_t nbCommSelProcessData_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbParty_t nbParty_t;
typedef struct nbTarSelProcessData_t nbTarSelProcessData_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

void AnimeTargetCursor(nbTarSelProcessData_t **tar);
s32 CheckFormCursor(s32 formindex, s32 ctype, s32 crule, s32 carea, s32 targetindex);
void CursorSelect(nbTarSelProcessData_t **t);
bool DDS3_PADCHECK_REP(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void DispTargetHelp(nbTarSelProcessData_t **t);
void *GetBattleUI(s32 index);
nbTarSelProcessData_t *GetTarSelProcessData(void);
void MemoryCommand(nbCommSelProcessData_t **s);
void OnOffTargetCursor(nbTarSelProcessData_t **t);
void SetCursor(nbTarSelProcessData_t **tar);
void UpdateSelect(nbTarSelProcessData_t **t);
s32 dds3CheckConfigBit(u32 Type);
void *dds3GetProcessData(dds3ProcessID_t **id);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void nbDispDevilName(s32 id);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
datUnitWork_t *nbGetUnitWorkPointer(nbMainProcessData_t *data, nbParty_t *party);
s32 nbSetSelectOkMark(s32 partyindex, s32 ctype, s32 crule, s32 carea);
void nbTarSelProcessData_t__Clear(nbTarSelProcessData_t *this);
s32 p2sdPlaySE(s32 a);

// 0x1584360
void AnimeTargetCursor(nbTarSelProcessData_t **tar) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  u64 *v6;
  nbTarSelProcessData_t_o *v7;
  s32 time;
  s32 v9;
  f32 v10;
  u32 v11;
  f32 v13;
  s64 v14;
  f32 v16;
  u32 v17;
  u32 v20;
  u32 v23;
  nbTarSelProcessData_t_o *v24;

  v3 = NewSpecific(f32, 7u);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__23BC09D0ACF246766A15E9F11E18035AC55B2A90);
  v4 = NewSpecific(f32, 7u);
  InitializeArray_1543888(v4, Field__PrivateImplementationDetails__048746382B9F9CBFB73003A95DC374E849A41876);
  v5 = NewSpecific(f32, 7u);
  InitializeArray_1543888(v5, Field__PrivateImplementationDetails__8FCBC886908E7B3509F4D48DE683A50103A135B1);
  v6 = NewSpecific(f32, 7u);
  InitializeArray_1543888(v6, Field__PrivateImplementationDetails__EC85459D36A848F72CB71C7EEBFAC1B651043026);
  ++(*tar)->time;
  v7 = *tar;
  time = (*tar)->time;
  if (time >= 30)
  {
    v7->time = 0;
    v7 = *tar;
    time = (*tar)->time;
  }
  v9 = time / 5;
  v10 = (time % 5);
  v11 = *(v3 + 6);
  v13 = v10 / 5.0;
  v14 = v9 + 1LL;
  v16 = 1.0 - v13;
  v7->alpha_a = (((1.0 - v13) * *(v3 + v9 + 8)) + (v13 * *(v3 + v14 + 8)));
  v17 = *(v4 + 6);
  (*tar)->scale_a = ((v16 * *(v4 + v9 + 8)) + (v13 * *(v4 + v14 + 8)));
  v20 = *(v5 + 6);
  (*tar)->alpha_b = ((v16 * *(v5 + v9 + 8)) + (v13 * *(v5 + v14 + 8)));
  v23 = *(v6 + 6);
  v24 = *tar;
  v24->scale_b = ((v16 * *(v6 + v9 + 8)) + (v13 * *(v6 + v14 + 8)));
}

// 0x1584170
s32 CheckEnemy(nbTarSelProcessData_t **t, s32 formindex) {
  if (((*t)->data->stat & 8) != 0)
  {
    if (formindex < 4)
      return 1;
  }
  else if ((formindex - 4) < 0xA)
  {
    return 1;
  }
  return 0;
}

// 0x1584650
s32 CheckFormCursor(s32 formindex, s32 ctype, s32 crule, s32 carea, s32 targetindex) {
  char v7;
  char v8;
  struct nbMainProcessData_t_o *data;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v14;
  u32 stat;
  _BOOL4 v16;
  u32 v17;
  s32 v18;
  s32 v20;
  bool v21;
  struct nbParty_t_array *party;

  v7 = carea;
  v8 = crule;
  data = GetTarSelProcessData(*&formindex)->data;
  form = data->form;
  v14 = form->m_Items[targetindex];
  if (ctype == 2 || (stat = data->stat, (v7 & 2) != 0) && (v7 & 1) != 0)
  {
    v16 = 1;
    goto LABEL_7;
  }
  if ((v7 & 1) != 0)
  {
    if ((stat & 8) == 0)
    {
LABEL_18:
      v16 = targetindex < 4;
      goto LABEL_7;
    }
  }
  else
  {
    if ((v7 & 2) == 0)
    {
      v16 = 0;
      goto LABEL_7;
    }
    if ((stat & 8) != 0)
      goto LABEL_18;
  }
  v16 = (targetindex - 4) < 0xA;
LABEL_7:
  if ((v8 & 1) != 0 && v16)
    v16 = formindex == targetindex;
  if ((v8 & 2) != 0 && v16)
    v16 = formindex != targetindex;
  if (!v16)
    return 0;
  v17 = v14->stat;
  if ((v17 & 1) != 0)
  {
    v20 = 1;
  }
  else
  {
    if ((v8 & 4) == 0)
      return 0;
    v20 = (v17 >> 11) & 1;
  }
  if (v20)
    v21 = (v8 & 8) == 0;
  else
    v21 = 1;
  if (v21)
    v18 = v20;
  else
    v18 = !(v17 & 1);
  if (!v18 || (v17 & 0x40) == 0)
    return v18;
  party = data->party;
  if ((party->m_Items[v14->partyindex]->flag & 0x38) != 0)
    return 0;
  else
    return v18;
}

// 0x1584130
s32 CheckFriend(nbTarSelProcessData_t **t, s32 formindex) {
  if (((*t)->data->stat & 8) != 0)
  {
    if ((formindex - 4) < 0xA)
      return 1;
  }
  else if (formindex < 4)
  {
    return 1;
  }
  return 0;
}

// 0x15852e0
void CursorSelect(nbTarSelProcessData_t **t) {
  nbTarSelProcessData_t_o *v5;
  s32 nowcarea;
  s8 enemycnt;
  s32 v9;
  s32 v10;
  bool v12;
  s32 v13;
  bool v15;
  s32 nowno;
  bool v18;
  nbTarSelProcessData_t_o *v19;
  bool v20;
  s32 v21;
  bool v22;
  s32 v23;
  nbTarSelProcessData_t_o *v25;
  s32 v26;
  char v27;

  if (((*t)->data->stat & 0x200000) == 0 && (*t)->stat == 1)
  {
    else if (DDS3_PADCHECK_REP(1))
    {
LABEL_8:
      MemoryCommand(t);
      (*t)->stat = 0;
      return;
    }
    if (DDS3_PADCHECK_TRIG(3))
    {
      (*t)->stat = 2;
      p2sdPlaySE(10);
    }
    v5 = *t;
    if ((*t)->ctype != 2)
    {
      nowcarea = v5->nowcarea;
      if (nowcarea == 2)
      {
        enemycnt = v5->enemycnt;
        if (!LODWORD(v5->enemyno->max_length))
          goto LABEL_29;
      }
      else if (nowcarea == 1)
      {
        enemycnt = v5->friendcnt;
        if (!LODWORD(v5->friendno->max_length))
        {
LABEL_29:
        }
      }
      else
      {
        enemycnt = 0;
      }
      if ((*t)->friendcnt < 1 || (*t)->enemycnt < 1)
      {
        v9 = 0;
        v10 = enemycnt - 1;
        if (enemycnt > 1)
          goto LABEL_34;
      }
      else
      {
        v9 = 1;
        v10 = enemycnt - 1;
        if (enemycnt > 1)
        {
LABEL_34:
          if (DDS3_PADCHECK_TRIG(5))
            goto LABEL_43;
          v12 = DDS3_PADCHECK_TRIG(7);
          if (!v9 && v12)
          {
LABEL_43:
            if (v10 == (*t)->nowno)
            {
              (*t)->nowno = 0;
              goto LABEL_59;
            }
          }
          if (DDS3_PADCHECK_REP(5))
            goto LABEL_57;
          v15 = DDS3_PADCHECK_REP(7);
          v13 = 0;
          if (!v9 && v15)
          {
LABEL_57:
            nowno = (*t)->nowno;
            if (v10 > nowno)
            {
              (*t)->nowno = nowno + 1;
LABEL_59:
              v13 = 1;
                goto LABEL_65;
              goto LABEL_63;
            }
            v13 = 0;
          }
            goto LABEL_65;
LABEL_63:
LABEL_65:
          if (!DDS3_PADCHECK_TRIG(4))
          {
            v18 = DDS3_PADCHECK_TRIG(6);
            if (v9 || !v18)
              goto LABEL_113;
          }
          v19 = *t;
          if (!(*t)->nowno)
          {
            LOBYTE(v23) = enemycnt - 1;
          }
          else
          {
LABEL_113:
            if (!DDS3_PADCHECK_REP(4))
            {
              v20 = DDS3_PADCHECK_REP(6);
              if (v9 || !v20)
                goto LABEL_86;
            }
            v19 = *t;
            v21 = (*t)->nowno;
            v22 = __OFSUB__(v21, 1);
            v23 = v21 - 1;
            if (v23 < 0 != v22)
            {
LABEL_86:
                goto LABEL_89;
              goto LABEL_87;
            }
          }
          v13 = 1;
          v19->nowno = v23;
          goto LABEL_86;
        }
      }
      v13 = 0;
        goto LABEL_89;
LABEL_87:
LABEL_89:
      if (DDS3_PADCHECK_TRIG(6))
        goto LABEL_94;
      if (DDS3_PADCHECK_TRIG(7))
      {
LABEL_94:
        v25 = *t;
        v26 = (*t)->nowcarea;
        if (v26 == 2)
        {
          if (v25->friendcnt > 0)
          {
            v27 = 1;
            goto LABEL_100;
          }
        }
        else if (v26 == 1 && v25->enemycnt >= 1)
        {
          v27 = 2;
LABEL_100:
          v25->nowcarea = v27;
          (*t)->nowno = 0;
LABEL_102:
          UpdateSelect(t);
          p2sdPlaySE(3);
          (*t)->jyokyotime = 0;
          return;
        }
      }
      if (!v13)
        return;
      goto LABEL_102;
    }
  }
}

// 0x15857f0
void CursorSelectAuto(nbTarSelProcessData_t **t) {
  if ((*t)->stat == 1)
  {
    MemoryCommand(t);
    (*t)->stat = 0;
  }
}

// 0x15850a0
void DispTargetHelp(nbTarSelProcessData_t **t) {
  u64 v3;
  nbTarSelProcessData_t_o *v4;
  struct nbFormation_t_array *form;
  nbTarSelProcessData_t_o *v8;
  s32 jyokyotime;
  bool v10;
  s32 v11;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 id;
  s32 v16;
  s32 v17;

  v3 = 0;
  while (1)
  {
    v4 = *t;
    if ((*t)->stat == 1 && !v4->ctype)
    {
      form = v4->data->form;
      if ((form->m_Items[v3]->anime & 8) != 0)
        break;
    }
    if (v3++ > 0xE)
      goto LABEL_11;
  }
  if ((*t)->jyokyotime)
    goto LABEL_11;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(v3);
  if (!UnitWorkFromFormindex)
  {
LABEL_11:
    v8 = *t;
    jyokyotime = (*t)->jyokyotime;
    v10 = __OFSUB__(jyokyotime, 1);
    v11 = jyokyotime - 1;
    if (v11 < 0 != v10)
      return;
    goto LABEL_12;
  }
  id = UnitWorkFromFormindex->id;
  v16 = convDLCDevilNumber(id);
  nbDispDevilName(v16);
  v8 = *t;
  v17 = (*t)->jyokyotime;
  v10 = __OFSUB__(v17, 1);
  v11 = v17 - 1;
  if (v11 < 0 == v10)
LABEL_12:
    v8->jyokyotime = v11;
}

// 0x15841b0
nbTarSelProcessData_t *GetTarSelProcessData(void) {
  nbTarSelProcessData_t_o *result;
  nbTarSelProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  dds3ProcessID_t_o *v7[3];
  dds3ProcessID_t_o *id;

  id = 0;
  id = dds3SearchProcessName("nb_tarsel");
  result = dds3GetProcessData(&id);
  if (result)
  {
    klass = result->klass;
    if (result->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbTarSelProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbTarSelProcessData_t, v7);
      if ((v7[0] & 1) != 0)
        v5 = v7[2];
      else
        v5 = v7 + 1;
      v6 = sub_8C4940(v5);
    }
  }
  return result;
}

// 0x1585b10
nbTarSelProcessData_t *InitTarSelProcessData(nbMainProcessData_t **data) {
  u64 *v3;
  nbMainProcessData_t_o *v4;

  v3 = Allocate(nbTarSelProcessData_t);
  nbTarSelProcessData_t___ctor(v3);
  nbTarSelProcessData_t__Clear(v3);
  v3[3] = 0;
  v4 = *data;
  v3[9] = 0x8000000080LL;
  v3[10] = 0x3F8000003F800000LL;
  *(v3 + 32) = 0;
  v3[2] = v4;
  return v3;
}

// 0x1585210
void MemoryCommand(nbTarSelProcessData_t **t) {
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *party;
  nbParty_t_o *v6;
  datUnitWork_t_o *UnitWorkPointer;

  data = (*t)->data;
  party = data->party;
  v6 = party->m_Items[(*t)->partyindex];
  UnitWorkPointer = nbGetUnitWorkPointer(data, v6);
  UnitWorkPointer->nowtarea = (*t)->nowcarea;
  UnitWorkPointer->nowtform = (*t)->nowform;
}

// 0x1584fd0
void OnOffTargetCursor(nbTarSelProcessData_t **t) {
  s64 v2;
  nbTarSelProcessData_t_o *v3;
  u64 v4;
  struct nbFormation_t_array *form;
  s32 v7;
  struct nbFormation_t_array *v8;
  s64 v10;
  s32 v11;
  u32 v12;
  s32 v13;

  v2 = 4;
  do
  {
    v3 = *t;
    v4 = v2 - 4;
    if ((*t)->stat == 1)
    {
      form = v3->data->form;
      v7 = (*(*(&form->obj.klass + v2) + 136LL) >> 3) & 1;
    }
    else
    {
      v7 = 0;
    }
    v8 = v3->data->form;
    v10 = *(&v8->obj.klass + v2++);
    v11 = *(v10 + 144);
    v12 = v11 & 0xFFFFFFF7;
    v13 = v11 | 8;
    if (!v7)
      v13 = v12;
    *(v10 + 144) = v13;
  }
  while (v2 != 20);
}

// 0x1584bf0
void SetCursor(nbTarSelProcessData_t **tar) {
  u8 v3;
  struct nbMainProcessData_t_o *data;
  struct nbParty_t_array *party;
  nbParty_t_o *v7;
  datUnitWork_t_o *UnitWorkPointer;
  s32 prevtarea;
  nbTarSelProcessData_t_o *v11;
  u64 v12;
  struct System_SByte_array *friendno;
  nbTarSelProcessData_t_o *v15;
  struct System_SByte_array *enemyno;

  if ((*tar)->friendcnt >= 1)
    v3 = 1;
  else
    v3 = 2;
  (*tar)->nowcarea = v3;
  (*tar)->nowno = 0;
  data = (*tar)->data;
  party = data->party;
  v7 = party->m_Items[(*tar)->partyindex];
  UnitWorkPointer = nbGetUnitWorkPointer(data, v7);
  prevtarea = UnitWorkPointer->prevtarea;
  LOWORD(data) = UnitWorkPointer->prevtform;
  if ((*tar)->act)
  {
    else if (dds3CheckConfigBit(0xBu))
    {
      goto LABEL_18;
    }
    if (((*tar)->act->stat & 0x80) == 0)
      return;
  }
LABEL_18:
  if (prevtarea == 2)
  {
    if ((*tar)->enemycnt >= 1)
    {
      (*tar)->nowcarea = 2;
      v15 = *tar;
      if ((*tar)->enemycnt >= 1)
      {
        v12 = 0;
        LODWORD(data) = data;
        while (1)
        {
          enemyno = v15->enemyno;
          if (data == enemyno->m_Items[v12])
            break;
          v15 = *tar;
          if (++v12 >= (*tar)->enemycnt)
            return;
        }
        goto LABEL_36;
      }
    }
  }
  else if (prevtarea == 1 && (*tar)->friendcnt >= 1)
  {
    (*tar)->nowcarea = 1;
    v11 = *tar;
    if ((*tar)->friendcnt >= 1)
    {
      v12 = 0;
      LODWORD(data) = data;
      while (1)
      {
        friendno = v11->friendno;
        if (data == friendno->m_Items[v12])
          break;
        v11 = *tar;
        if (++v12 >= (*tar)->friendcnt)
          return;
      }
LABEL_36:
      (*tar)->nowno = v12;
    }
  }
}

// 0x1583f70
void UpdateSelect(nbTarSelProcessData_t **t) {
  u64 i;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v5;
  nbTarSelProcessData_t_o *v7;
  s32 ctype;
  s32 nowcarea;
  struct System_SByte_array *enemyno;
  s32 v11;
  u32 nowno;
  struct nbFormation_t_array *v14;

  for (i = 0; i != 16; ++i)
  {
    while (1)
    {
      form = (*t)->data->form;
      form->m_Items[i]->stat &= ~8u;
      v5 = (*t)->data->form;
      if ((v5->m_Items[i]->stat & 4) == 0)
        goto LABEL_25;
      v7 = *t;
      ctype = (*t)->ctype;
      if (ctype == 2)
        goto LABEL_28;
      if (ctype == 1)
        break;
      if (!(*t)->ctype)
      {
        nowcarea = v7->nowcarea;
        if (nowcarea == 2)
        {
          enemyno = v7->enemyno;
        }
        else
        {
          if (nowcarea != 1)
            goto LABEL_25;
          enemyno = v7->friendno;
        }
        nowno = v7->nowno;
        if (i == enemyno->m_Items[nowno])
        {
          (*t)->nowform = i;
          goto LABEL_28;
        }
      }
LABEL_25:
      if (++i == 16)
        return;
    }
    v11 = v7->nowcarea;
    if (v11 == 2)
    {
      if ((v7->data->stat & 8) != 0)
        goto LABEL_27;
      if ((i - 4) > 9)
        goto LABEL_25;
    }
    else
    {
      if (v11 != 1)
        goto LABEL_25;
      if ((v7->data->stat & 8) == 0)
      {
LABEL_27:
        if (i >= 4)
          goto LABEL_25;
        goto LABEL_28;
      }
      if ((i - 4) >= 0xA)
        goto LABEL_25;
    }
LABEL_28:
    v14 = (*t)->data->form;
    v14->m_Items[i]->stat |= 8u;
  }
}

// 0x15842e0
s32 nbGetTarSelStat(void) {
  return GetTarSelProcessData()->stat;
}

// 0x1585ba0
void nbInitTarSelProcess(nbMainProcessData_t *data) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  dds3ProcessID_t_o *target;

  target = 0;
  v3 = Allocate(nbTarSelProcessData_t);
  nbTarSelProcessData_t___ctor(v3);
  nbTarSelProcessData_t__Clear(v3);
  *(v3 + 32) = 0;
  v3[2] = data;
  v3[3] = 0;
  v3[9] = 0x8000000080LL;
  v3[10] = 0x3F8000003F800000LL;
  v4 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v4,
    0,
    Method_nbTarSelProcess_nbTarSelProcess1__);
  v5 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v5,
    0,
    Method_nbTarSelProcess_nbTarSelShutdown__);
  target = dds3StartProcess("nb_tarsel", 0x3F9u, 1, 1, v4, 0, v5, 0, v3, 0);
  dds3LinkProcess(&data->MainProcessID, &target);
  data->TarSelProcessID = target;
}

// 0x1583f60
void nbPnlSprite(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, s32 rgba, sdfTexHandle_t *th) {
  ;
}

// 0x15847e0
s32 nbSetSelectOkMark(s32 partyindex, s32 ctype, s32 crule, s32 carea) {
  nbTarSelProcessData_t_o *TarSelProcessData;
  s64 v11;
  struct nbFormation_t_array *form;
  u64 v13;
  struct nbFormation_t_array *v15;
  struct nbParty_t_array *party;
  struct nbFormation_t_array *v19;
  struct System_SByte_array *friendno;
  struct System_SByte_array *enemyno;
  s64 enemycnt;
  u64 v26;
  s64 v27;
  signed s64 v28;
  s64 v29;
  struct System_SByte_array *v32;
  struct nbFormation_t_array *v33;
  u64 v35;
  s64 v36;
  struct System_SByte_array *v38;
  f32 v39;
  f32 v40;
  struct nbFormation_t_array *v41;
  s64 v43;
  f32 v45;
  struct System_SByte_array *v46;
  u64 max_length_low;
  s8 v48;
  struct System_SByte_array *v50;
  s64 v52;

  TarSelProcessData = GetTarSelProcessData(*&partyindex);
  v11 = 4;
  *&TarSelProcessData->friendcnt = 0;
  do
  {
    while (1)
    {
      form = TarSelProcessData->data->form;
      v13 = v11 - 4;
      *(*(&form->obj.klass + v11) + 136LL) &= ~4u;
      v15 = TarSelProcessData->data->form;
      *(*(&v15->obj.klass + v11) + 136LL) &= ~8u;
      party = TarSelProcessData->data->party;
      if (!CheckFormCursor(party->m_Items[partyindex]->formindex, ctype, crule, carea, v11 - 4))
        goto LABEL_17;
      v19 = TarSelProcessData->data->form;
      *(*(&v19->obj.klass + v11) + 136LL) |= 4u;
      if (v13 <= 3)
        break;
      if (v13 <= 0xD)
      {
        if ((TarSelProcessData->data->stat & 8) != 0)
          goto LABEL_14;
        goto LABEL_20;
      }
LABEL_17:
      if (++v11 == 20)
        goto LABEL_23;
    }
    if ((TarSelProcessData->data->stat & 8) == 0)
    {
LABEL_14:
      friendno = TarSelProcessData->friendno;
      friendno->m_Items[TarSelProcessData->friendcnt++] = v13;
      goto LABEL_17;
    }
LABEL_20:
    enemyno = TarSelProcessData->enemyno;
    enemyno->m_Items[TarSelProcessData->enemycnt++] = v13;
    ++v11;
  }
  while (v11 != 20);
LABEL_23:
  LODWORD(enemycnt) = TarSelProcessData->enemycnt;
  if (enemycnt >= 2)
  {
    v26 = 0;
    v27 = 33;
    do
    {
      v28 = v26 + 1;
      if ((v26 + 1) < enemycnt)
      {
        v29 = v27;
        do
        {
          v32 = TarSelProcessData->enemyno;
          v33 = TarSelProcessData->data->form;
          v35 = v29 - 32;
          v36 = v32->m_Items[v26];
          sub_854710(&v33->m_Items[v36]->fields, 0);
          v38 = TarSelProcessData->enemyno;
          v40 = v39;
          v41 = TarSelProcessData->data->form;
          v43 = *(&v38->obj.klass + v29);
          sub_854710(&v41->m_Items[v43]->fields, 0);
          if (v40 > v45)
          {
            v46 = TarSelProcessData->enemyno;
            max_length_low = LODWORD(v46->max_length);
            v48 = v46->m_Items[v26];
            TarSelProcessData->enemyno->m_Items[v26] = *(&TarSelProcessData->enemyno->obj.klass + v29);
            v50 = TarSelProcessData->enemyno;
            *(&v50->obj.klass + v29) = v48;
          }
          enemycnt = TarSelProcessData->enemycnt;
          v52 = v29 - 31;
          ++v29;
        }
        while (v52 < enemycnt);
      }
      ++v27;
      ++v26;
    }
    while (v28 < enemycnt - 1);
    LODWORD(enemycnt) = enemycnt;
  }
  return enemycnt + TarSelProcessData->friendcnt != 0;
}

// 0x1584330
void nbSetTarSelJyokyoTime(s32 time) {
  GetTarSelProcessData(*&time)->jyokyotime = time;
}

// 0x1584300
void nbSetTarSelStat(s32 stat) {
  GetTarSelProcessData(*&stat)->stat = stat;
}

// 0x1584e40
s32 nbSetTargetProcess(nbActionProcessData_t *act, s32 partyindex, s32 ctype, s32 crule, s32 carea) {
  nbActionProcessData_t_o *v10;
  nbTarSelProcessData_t_o *TarSelProcessData;
  s32 result;
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v20;
  UnityEngine_GameObject_o *gameObject;
  nbTarSelProcessData_t_o *tar;

  v10 = act;
  TarSelProcessData = GetTarSelProcessData(act);
  tar = TarSelProcessData;
  result = nbSetSelectOkMark(partyindex, ctype, crule, carea);
  if (result)
  {
    *&TarSelProcessData->time = 0x8000000000LL;
    TarSelProcessData->alpha_b = 128;
    TarSelProcessData->act = v10;
    TarSelProcessData->jyokyotime = 0;
    TarSelProcessData->partyindex = partyindex;
    TarSelProcessData->ctype = ctype;
    TarSelProcessData->crule = crule;
    TarSelProcessData->carea = carea;
    *&TarSelProcessData->scale_a = 0x3F8000003F800000LL;
    SetCursor(&tar);
    UpdateSelect(&tar);
    TarSelProcessData->stat = 1;
    BattleUI = GetBattleUI(0);
    if (op_Inequality(BattleUI, 0, 0))
    {
      transform = get_transform(BattleUI, 0);
      v20 = Find(transform, "bmenu/normal_command/bmenu_cursur", 0);
      gameObject = get_gameObject(v20);
      if (get_activeSelf(gameObject))
        SetActive(gameObject, 0, 0);
    }
    return 1;
  }
  return result;
}

// 0x1585830
void *nbTarSelProcess1(dds3ProcessID_t *id) {
  nbTarSelProcessData_t_o *ProcessData;
  nbTarSelProcessData_t_c *v3;
  nbTarSelProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct nbActionProcessData_t_o *act;
  nbTarSelProcessData_t_o *v14;
  dds3ProcessID_t_o *v15[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  v14 = 0;
  else
  {
    ProcessData = dds3GetProcessData(&ida);
    if (!ProcessData)
      goto LABEL_12;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbTarSelProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbTarSelProcessData_t, v15);
    if ((v15[0] & 1) != 0)
      v6 = v15[2];
    else
      v6 = v15 + 1;
    v7 = sub_8C4940(v6);
  }
LABEL_12:
  v14 = ProcessData;
  act = ProcessData->act;
  if (act && (act->stat & 0x80) != 0)
  {
    if (ProcessData->stat == 1)
    {
      MemoryCommand(&v14, v3);
      v14->stat = 0;
    }
    goto LABEL_19;
  }
  if (ProcessData->stat != 1 || (CursorSelect(&v14, v3), v14->stat))
  {
LABEL_19:
    AnimeTargetCursor(&v14, v3);
    OnOffTargetCursor(&v14);
    DispTargetHelp(&v14);
    return 0;
  }
  v14->stat = 1;
  AnimeTargetCursor(&v14, v3);
  OnOffTargetCursor(&v14);
  DispTargetHelp(&v14);
  v14->stat = 0;
  return 0;
}

// 0x15859f0
void *nbTarSelShutdown(dds3ProcessID_t *id) {
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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbTarSelProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbTarSelProcessData_t, v8);
    if ((v8[0] & 1) != 0)
      v6 = v8[2];
    else
      v6 = v8 + 1;
    v7 = sub_8C4940(v6);
  }
  ProcessData[1].klass->vtable[1].method = 0;
  return 0;
}
