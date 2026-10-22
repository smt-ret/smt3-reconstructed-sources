#include "types.h"

typedef struct nbMainProcessData_t nbMainProcessData_t;

static s32 encmax;

bool ChkLength(s32 id);
u8 Get(s32 id);
s32 GetBgmCategory(s32 encpackno, s32 encno);
s32 datGetPlayerLevel(void);
u32 dds3GetRandIntA(u32 aLimit, char *name);
bool evtBitCheck(s32 no);
s32 evtGetAgeOfMoon(void);
s32 nbCheckEncountLevel(s32 tbl);
s32 nbGetEncountJoken(s32 id);
s32 nbGetEncountMax(s32 id);
nbMainProcessData_t *nbGetMainProcessData(void);

// 0x1707bb0
s32 GetBgmCategory(s32 encpackno, s32 encno) {
  s32 btlsound;

  if (encpackno < 1)
  {
    btlsound = 0;
  }
  else
  {
    btlsound = Get(encpackno, 0)->btlsound;
  }
  if (Get(encno, 0)->btlsound)
  {
    btlsound = Get(encno, 0)->btlsound;
  }
  if (btlsound)
    return btlsound;
  else
    return 1;
}

// 0x1707dc0
s32 NB_GET_ENCNO(u32 x) {
  return x;
}

// 0x1707db0
s32 NB_GET_PACKNO(u32 x) {
  return HIBYTE(x);
}

// 0x1707ba0
s32 NB_MAKE_ENCDATA(s32 x, s32 y, s32 z) {
  return (y << 16) | (x << 24) | z;
}

// 0x1707990
s32 nbCheckEncountLevel(s32 tbl) {
  u64 v3;
  s32 v4;
  s32 v5;
  struct System_UInt16_array *devil;
  char *v8;
  s32 v9;
  s32 PlayerLevel;

  if (!tbl)
    return 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  do
  {
    devil = Get(tbl, 0)->devil;
    v8 = devil + 2 * v3;
    v9 = *(v8 + 16);
    if (*(v8 + 16))
    {
      v4 += Get(v9, 1, 0)->level;
      ++v5;
    }
    ++v3;
  }
  while (v3 != 11);
  if (!v5)
    return 0;
  PlayerLevel = datGetPlayerLevel();
  return v4 / v5 + PlayerLevel / 4 >= PlayerLevel;
}

// 0x17073d0
s32 nbEncountCalc(s32 id, f32 length) {
  s32 result;
  s32 EncountJoken;
  dds3GlobalWork_c **v9;
  s32 v10;
  dds3GlobalWork_c *v11;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  f32 v13;
  struct dds3GlobalWork_t_o *v14;
  f32 encountkyori;
  s32 v16;
  s32 v17;
  struct dds3GlobalWork_t_o *v18;
  u16 *p_encountcnt;
  u16 v20;
  u16 v21;
  u16 v23;
  u16 v24;
  s16 RandIntA;
  s16 v29;
  u16 encountcnt;
  struct dds3GlobalWork_t_o *v32;
  datEncountPack_t_o *v34;
  s32 v35;
  s32 v36;
  s64 v37;
  struct datEncountTbl_s_array *enctable;
  u64 v40;
  struct datEncountRitu_s_array *ritu;
  struct datEncountTbl_s_array *v44;
  struct datEncountRitu_s_array *v46;
  u64 *v47;
  struct datEncountTbl_s_array *v49;
  s32 v50;
  struct datEncountRitu_s_array *v52;
  signed s32 v53;
  s64 v55;
  u64 v56;
  s32 v57;
  u64 v59;
  signed s32 v60;

  result = 0;
  if (id && length != 0.0)
  {
    EncountJoken = nbGetEncountJoken(id);
    result = nbGetEncountMax(id);
    if (result)
    {
      v9 = &dds3GlobalWork;
      v10 = result;
      v13 = DDS3_GBWK->encountkyori + length;
      DDS3_GBWK->encountkyori = v13;
      if (v13 >= 100.0)
      {
        v14 = DDS3_GBWK;
        encountkyori = v14->encountkyori;
        v16 = (encountkyori / 100.0);
        v14->encountkyori = encountkyori - (v16 * 100.0);
        v17 = (v11->_2.bitflags2 >> 1) & 1;
        if (v16 >= 1)
        {
          do
          {
            v18 = DDS3_GBWK;
            if ((v18->stat & 2) != 0)
            {
              else
              {
                v24 = v18->encountcnt;
                p_encountcnt = &v18->encountcnt;
                v23 = v24;
                {
LABEL_29:
                }
              }
              RandIntA = dds3GetRandIntA(7u, "");
              v29 = v23 + 6;
              goto LABEL_35;
            }
            else
            {
              v21 = v18->encountcnt;
              p_encountcnt = &v18->encountcnt;
              v20 = v21;
                goto LABEL_24;
            }
            RandIntA = dds3GetRandIntA(3u, "");
            v29 = v20 + 2;
LABEL_35:
            *p_encountcnt = v29 + RandIntA;
            --v16;
          }
          while (v16);
        }
        v32 = DDS3_GBWK;
        if (v32->encountcnt >= 0xFDE9u)
        {
          v32->encountcnt = -536;
        }
        if (v10 <= DDS3_GBWK->encountcnt)
        {
          v34 = Get(id, 0);
          v35 = 0;
          v36 = 0;
          v37 = 4;
          v60 = dds3GetRandIntA(0x3E8u, "");
          do
          {
            enctable = v34->enctable;
            v40 = v37 - 4;
            ritu = enctable->m_Items[EncountJoken]->ritu;
            if (*(*(&ritu->obj.klass + v37) + 16LL))
            {
              v44 = v34->enctable;
              v46 = v44->m_Items[EncountJoken]->ritu;
              v47 = v9;
              v49 = v34->enctable;
              v50 = *(*(&v46->obj.klass + v37) + 18LL);
              v52 = v49->m_Items[EncountJoken]->ritu;
              v53 = v36 + v50;
              v55 = *(&v52->obj.klass + v37);
              if (v53 > v60)
              {
                v56 = *v47;
                v57 = *(v55 + 16);
                if ((*(*v47 + 295) & 2) != 0 && !*(v56 + 216))
                {
                  v56 = *v47;
                }
                if ((*(**(v56 + 184) + 76LL) & 1) == 0)
                  goto LABEL_81;
                if (!nbCheckEncountLevel(v57))
                {
                  v59 = *v47;
                  if ((*(*v47 + 295) & 2) != 0 && !*(v59 + 216))
                  {
                    v59 = *v47;
                  }
                  *(**(v59 + 184) + 156LL) = 0;
                  *(**(v59 + 184) + 160LL) = 0;
                  result = 0;
                }
                else
                {
LABEL_81:
                  result = v35 | (EncountJoken << 24) | v57;
                }
                encmax = 0;
                return result;
              }
              v36 += *(v55 + 18);
              v9 = v47;
            }
            v35 += 0x10000;
            ++v37;
          }
          while (v40 < 0xB);
        }
      }
      return 0;
    }
  }
  return result;
}

// 0x1707ca0
s32 nbGetBgmCategoryInBattle(void) {
  nbMainProcessData_t_o *MainProcessData;
  s32 encpackno;
  s32 encno;

  MainProcessData = nbGetMainProcessData();
  encpackno = MainProcessData->encpackno;
  encno = MainProcessData->encno;
  return GetBgmCategory(encpackno, encno);
}

// 0x1707d40
s32 nbGetBgmCategoryInField(u32 encdata) {
  return GetBgmCategory(HIBYTE(encdata), encdata);
}

// 0x1707360
s32 nbGetEncountCnt(void) {
  return DDS3_GBWK->encountcnt;
}

// 0x1706e30
s32 nbGetEncountJoken(s32 id) {
  datEncountPack_t_o *v5;
  s32 result;
  _BOOL4 v7;
  s32 eventbit2;
  _BOOL4 v9;
  struct System_Byte_array *table1;
  struct System_Byte_array *v12;
  struct System_Byte_array *v14;
  struct System_Byte_array *v16;

  if (!ChkLength(id))
    id = 1;
  v5 = Get(id, 0);
  if (v5->moonchk)
  {
    if (((1 << evtGetAgeOfMoon()) & v5->moonchk) != 0)
      return v5->table2;
  }
  if (v5->eventbit1)
  {
    v7 = evtBitCheck(v5->eventbit1);
    eventbit2 = v5->eventbit2;
    if (v5->eventbit2)
      goto LABEL_19;
  }
  else
  {
    v7 = 0;
    eventbit2 = v5->eventbit2;
    if (v5->eventbit2)
    {
LABEL_19:
      v9 = !evtBitCheck(eventbit2);
      if (!v9)
        goto LABEL_26;
      goto LABEL_20;
    }
  }
  v9 = 1;
LABEL_20:
  if (!v7)
  {
    table1 = v5->table1;
    return table1->m_Items[0];
  }
LABEL_26:
  if (!v7 || !v9)
  {
    if (v7 || v9)
    {
      result = 0;
      if (v7 && !v9)
      {
        v14 = v5->table1;
        return v14->m_Items[3];
      }
    }
    else
    {
      v16 = v5->table1;
      return v16->m_Items[2];
    }
  }
  else
  {
    v12 = v5->table1;
    return v12->m_Items[1];
  }
  return result;
}

// 0x1707040
s32 nbGetEncountMax(s32 id) {
  u64 v4;
  s32 v5;
  s64 EncountJoken;
  struct datEncountTbl_s_array *enctable;
  struct datEncountRitu_s_array *ritu;
  Il2CppClass **v12;
  s32 encmax;
  s32 datEncountBase;
  struct datEncountTbl_s_array *v19;
  u64 v21;
  s32 v22;
  u32 RandIntA;
  u64 *v26;
  u64 *v28;
  s32 v29;
  s32 v30;

  if (!id)
    return 0;
  if (!ChkLength(id))
    return 0;
LABEL_7:
  v4 = 0;
  v5 = 0;
  EncountJoken = nbGetEncountJoken(id);
  do
  {
    enctable = Get(id, 0)->enctable;
    ritu = enctable->m_Items[EncountJoken]->ritu;
    v12 = &ritu->obj.klass + v4++;
    v5 += WORD1(v12[4]->_1.name);
  }
  while (v4 != 12);
  if (!v5)
    return 0;
  if (encmax < 1)
  {
    v19 = Get(id, 0)->enctable;
    v21 = 65970697680LL * v19->m_Items[EncountJoken]->normalritu;
    v22 = datEncountBase - ((v21 >> 63) + (SHIDWORD(v21) >> 5));
    RandIntA = dds3GetRandIntA(2 * v22 - 32, "");
    encmax = RandIntA + 16;
    v30 = encmax;
    v26 = sub_8D3950(s32, &v30);
    v29 = v22;
    v28 = sub_8D3950(s32, &v29);
    Write_2930752("エンカウント率 {0:D}/{1:D}\n", v26, v28);
    return encmax;
  }
  return encmax;
}

// 0x1707af0
void nbResetEncountCount(void) {
  DDS3_GBWK->encountkyori = 0.0;
  DDS3_GBWK->encountcnt = 0;
  encmax = 0;
}
