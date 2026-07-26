#include "types.h"

typedef struct datUnitVisual_s datUnitVisual_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbActionProcessData_t nbActionProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbParty_t nbParty_t;

u8 Get(s32 id);
s16 GetFailpoint(s32 nskill);
bool IsNOCTURNE(void);
u32 datAddHp(datUnitWork_t *work, s32 hp);
u32 datAddMp(datUnitWork_t *work, s32 mp);
s32 datBossRashChk(s32 eid);
s32 datCheckSkillInParty(s32 skillid);
s32 datCheckSyojiSkill(datUnitWork_t *work, u32 skill);
s32 datGet3Zokusei(datUnitWork_t *work);
u32 datGetAisyo(datUnitWork_t *work, s32 attr);
s32 datGetBadStatusAttr(s32 bad);
s32 datGetBaseMaxHp(datUnitWork_t *work);
s32 datGetDefPow(datUnitWork_t *work);
s32 datGetMagicHitPow(datUnitWork_t *work);
s32 datGetNormalAtkPow(datUnitWork_t *work);
s32 datGetParam(datUnitWork_t *work, s32 paratype);
s32 datGetPlayerLevel(void);
s32 datGetSakePow(datUnitWork_t *work);
s32 datGetSkillCost(datUnitWork_t *w, s32 nskill);
void datResetBadStat(datUnitWork_t *work, u32 badstat);
void datSetBadStat(datUnitWork_t *work, u32 badstat);
f32 dds3GetRandFloatA(char *name);
u32 dds3GetRandIntA(u32 aLimit, char *name);
bool evtBitCheck(s32 no);
s32 evtGetAgeOfMoon(void);
s32 nbCheckKoukaJyoken(s32 nskill, s32 sformindex, s32 dformindex);
s32 nbCheckSkillCost(s32 formindex, s32 nskill);
s32 nbGet3Zokusei(s32 formindex);
u32 nbGetAisyo(s32 nskill, s32 formindex, s32 attr);
f32 nbGetAisyoRitu(s32 nskill, s32 sformindex, s32 dformindex);
s32 nbGetButuriAttack(s32 nskill, s32 sformindex, s32 dformindex, s32 waza);
u32 nbGetDevilFormatFlag(s32 formindex);
f32 nbGetHojoRitu(s32 formindex, s32 type);
u32 nbGetKoukaBadDamage(s32 nskill, s32 sformindex, s32 dformindex, f32 ai, s32 nvirtual);
u32 nbGetKoukaBadKaifuku(s32 nskill, s32 sformindex, s32 dformindex, f32 ai, s32 nvirtual);
s32 nbGetKoukaHp(s32 sw, s32 nskill, s32 sformindex, s32 dformindex, f32 ritu, s32 cnt);
s32 nbGetKoukaMp(s32 sw, s32 nskill, s32 sformindex, s32 dformindex, f32 ritu, s32 cnt);
s32 nbGetLvAvg2(nbMainProcessData_t *data, s32 side);
s32 nbGetMagicAttack(s32 nskill, s32 sformindex, s32 dformindex, s32 waza);
s32 nbGetMagicKaifuku(s32 nskill, s32 sformindex, s32 dformindex, s32 waza);
nbMainProcessData_t *nbGetMainProcessData(void);
s32 nbGetMaxHpWazaPoint(s32 nskill, s32 sformindex, s32 dformindex, s32 waza);
s32 nbGetParamAvg(nbMainProcessData_t *data, s32 side, s32 paratype);
s32 nbGetParamAvg2(nbMainProcessData_t *data, s32 side, s32 paratype);
nbParty_t *nbGetPartyFromFormindex(s32 formindex);
datUnitVisual_t *nbGetUnitVisual(datUnitWork_t *work);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
datUnitWork_t *nbGetUnitWorkPointer(nbMainProcessData_t *data, nbParty_t *party);
s32 nbHatudoCheckSkill(datUnitWork_t *work, s32 skill);
s32 nbSetHojoAddCounter(s32 formindex, s32 type, s32 point, s32 nvirtual);
s32 nbSetHojoKouka(s32 formindex, u32 hojotype, s32 hojopoint, s32 nvirtual);
void nbSetRenzokuEncount(s32 enc);
f32 sdfFabs(f32 c);

// 0xfade70
s16 GetFailpoint(s32 nskill) {
  struct datNormalSkill_t_array *tbl;

  else  if ((nskill - 131) <= 0x20 && ((1LL << (nskill + 125)) & 0x120013001LL) != 0)
    return 30;
  return tbl->m_Items[nskill]->failpoint;
}

// 0xfb0b80
void nbAddHpMp(s32 formindex, s32 type, s32 n) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v9;

  else
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    if (!UnitWorkFromFormindex)
      return;
  }
  v9 = UnitWorkFromFormindex;
  if (type == 1)
  {
    datAddMp(v9, n);
  }
  else if (!type)
  {
    datAddHp(v9, n);
  }
}

// 0xfb6d40
s32 nbCheckBackAttack(nbMainProcessData_t *data) {
    Get(0);
    nbGetLvAvg2(0, 0);
    nbGetParamAvg2(0, 0, 0);
    datGetParam(0, 0);
    dds3GetRandIntA(0, 0);
    datCheckSkillInParty(0);
    return 0;
}

// 0xfac360
s32 nbCheckBadCurse(s32 formindex) {
  datUnitWork_t_o *UnitWorkFromFormindex;

  else
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    if (UnitWorkFromFormindex)
      LODWORD(UnitWorkFromFormindex) = UnitWorkFromFormindex->badstatus >> 15;
  }
  return UnitWorkFromFormindex;
}

// 0xfb41c0
s32 nbCheckBadKaifuku(datUnitWork_t *work, s32 type) {
    datGetParam(0, 0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfb8350
s32 nbCheckBadPanicAction(datUnitWork_t *w) {
  u32 flag;
  s32 v4;
  s32 v5;

  flag = w->flag;
  if ((flag & 0x20) != 0)
    v4 = 10;
  else
    v4 = 30;
  if ((flag & 4) != 0)
    v5 = 30;
  else
    v5 = v4;
  return v5 <= dds3GetRandIntA(0x64u, StringLiteral_21150);
}

// 0xfb83f0
s32 nbCheckBadStatusGameOver(nbMainProcessData_t *data) {
    nbGetUnitWorkFromFormindex(0);
    return 0;
}

// 0xfb7170
s32 nbCheckEscape(nbMainProcessData_t *data) {
    Get(0);
    nbGetUnitWorkFromFormindex(0);
    nbGetParamAvg(0, 0, 0);
    datCheckSkillInParty(0);
    dds3GetRandIntA(0, 0);
    evtGetAgeOfMoon();
    return 0;
}

// 0xfb8010
s32 nbCheckFormationFriend(s32 formindex1, s32 formindex2) {
  return (formindex1 > 3) ^ (formindex2 < 4);
}

// 0xfabec0
s32 nbCheckFormationPlayerSide(s32 formindex) {
  return formindex < 4;
}

// 0xfb3d80
u32 nbCheckHitEffect(s32 nskill, s32 sformindex, s32 dformindex) {
  return Get(nskill, 0)->bedno == 0;
}

// 0xfafba0
s32 nbCheckKoukaJyoken(s32 nskill, s32 sformindex, s32 dformindex) {
  struct datNormalSkill_t_array *tbl;
  u8 hittype;
  s32 v10;

  hittype = tbl->m_Items[nskill]->hittype;
  v10 = nbGet3Zokusei(dformindex, *&sformindex);
  if ((hittype & 1) != 0 || !v10 && (hittype & 2) != 0 || v10 == 1 && (hittype & 4) != 0)
    return 1;
  else
    return (v10 == 2) & ((hittype & 8) >> 3);
}

// 0xfb7dc0
s32 nbCheckKuisibari2Skill(s32 formindex) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 result;
  nbParty_t_o *PartyFromFormindex;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  result = datCheckSyojiSkill(UnitWorkFromFormindex, 0x168u);
  if (result)
  {
    PartyFromFormindex = nbGetPartyFromFormindex(formindex);
    if ((PartyFromFormindex->flag & 0x400) != 0)
    {
      return 0;
    }
    else
    {
      PartyFromFormindex->flag |= 0x200u;
      return 1;
    }
  }
  return result;
}

// 0xfb7cc0
s32 nbCheckKuisibariSkill(s32 formindex) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 result;
  nbParty_t_o *PartyFromFormindex;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  result = datCheckSyojiSkill(UnitWorkFromFormindex, 0x159u);
  if (result)
  {
    PartyFromFormindex = nbGetPartyFromFormindex(formindex);
    if ((PartyFromFormindex->flag & 0x400) != 0)
    {
      return 0;
    }
    else
    {
      PartyFromFormindex->flag |= 0x200u;
      return 1;
    }
  }
  return result;
}

// 0xfb7970
s32 nbCheckRenzokuEncount(nbMainProcessData_t *data) {
    Get(0);
    nbSetRenzokuEncount(0);
    Get(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfb6740
s32 nbCheckSensei(nbMainProcessData_t *data) {
    Get(0);
    nbGetLvAvg2(0, 0);
    nbGetParamAvg2(0, 0, 0);
    datGetParam(0, 0);
    Get(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfb7f60
s32 nbCheckSingleTargetSkill(s32 skillid) {
  struct datNormalSkill_t_array *tbl;

  return tbl->m_Items[skillid]->targettype == 0;
}

// 0xfa12e0
s32 nbCheckSkillCost(s32 formindex, s32 nskill) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct datNormalSkill_t_array *tbl;
  struct datNormalSkill_t_array *v12;
  struct datNormalSkill_t_array *v15;
  s32 costtype;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  if (tbl->m_Items[nskill]->koukatype == 1 && (UnitWorkFromFormindex->badstatus & 0xFFF) == 0x20)
    return 3;
  v12 = tbl;
  if ((v12->m_Items[nskill]->flag & 4) != 0)
    return 0;
  v15 = tbl;
  costtype = v15->m_Items[nskill]->costtype;
  if (costtype != 2)
  {
    if (costtype == 1)
    {
      return datGetSkillCost(UnitWorkFromFormindex, nskill) >= UnitWorkFromFormindex->hp;
    }
    return 0;
  }
  return 2 * (datGetSkillCost(UnitWorkFromFormindex, nskill) > UnitWorkFromFormindex->mp);
}

// 0xfa3eb0
s32 nbCheckSkillUse(s32 formindex, s32 nskill) {
  struct datNormalSkill_t_array *tbl;
  s32 v11;

  if ((nbGetUnitWorkFromFormindex(formindex)->badstatus & 0xFFF) == 0x20)
  {
    if (tbl->m_Items[nskill]->koukatype == 1)
      return 1;
  }
  v11 = nbCheckSkillCost(formindex, nskill);
  if (v11 == 1)
    return 2;
  if (v11 == 2)
    return 3;
  return 0;
}

// 0xfb3e10
s32 nbCheckStoneDead(s32 nskill, s32 dformindex) {
    nbGetUnitWorkFromFormindex(0);
    datGetParam(0, 0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfafae0
s32 nbGet3Zokusei(s32 formindex) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 v5;
  s32 v6;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  v5 = datGet3Zokusei(UnitWorkFromFormindex);
  if (v5 == 1)
    v6 = 2;
  else
    v6 = 1;
  if (v5 == -1)
    return 0;
  else
    return v6;
}

// 0xfae660
u32 nbGetAisyo(s32 nskill, s32 formindex, s32 attr) {
    nbGetUnitWorkFromFormindex(0);
    nbGetPartyFromFormindex(0);
    Get(0);
    datCheckSyojiSkill(0, 0);
    datGetAisyo(0, 0);
    return 0;
}

// 0xfb0ca0
f32 nbGetAisyoRitu(s32 nskill, s32 sformindex, s32 dformindex) {
  nbMainProcessData_t_o *MainProcessData;
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v11;
  struct datSkill_t_array *tbl;
  s32 skillattr;
  f32 v17;
  u32 Aisyo;
  bool v20;
  s32 v21;
  struct datNormalSkill_t_array *v23;
  bool v25;
  struct datNormalSkill_t_array *v27;
  s32 v31;
  f32 result;
  u32 v33;

  MainProcessData = nbGetMainProcessData();
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(sformindex);
  v11 = nbGetUnitWorkFromFormindex(dformindex);
  skillattr = tbl->m_Items[nskill]->skillattr;
  if (skillattr != -1 && (skillattr - 12) >= 3)
  {
    Aisyo = nbGetAisyo(nskill, dformindex, skillattr);
    if (Aisyo)
      v20 = 1;
    else
      v20 = (Aisyo & 0x60000) == 0;
    if (v20)
      v21 = Aisyo;
    else
      v21 = 100;
    if ((v11->badstatus & 0xFFF) == 2)
    {
      v23 = tbl;
      if (v23->m_Items[nskill]->koukatype)
        v25 = 1;
      else
        v25 = v21 > 0x63;
      if (!v25)
        v21 = 100;
    }
    if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x165u))
    if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x169u))
    {
      v27 = tbl;
      if (v21 <= 99 && v27->m_Items[nskill]->koukatype == 0)
      {
        v21 = 100;
        MainProcessData->d31_kantuu = 1;
      }
    }
    v17 = v21 * 0.01;
  }
  else
  {
    v17 = 1.0;
  }
  if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x169u))
    return v17 * 1.5;
  switch (skillattr)
  {
    case 1:
      v31 = datCheckSyojiSkill(UnitWorkFromFormindex, 0x135u);
      result = v17 * 1.5;
      if (!v31)
        return v17;
      return result;
    case 2:
      v33 = 310;
    case 3:
      v33 = 311;
    case 4:
      v33 = 312;
      if (datCheckSyojiSkill(UnitWorkFromFormindex, v33))
        v17 = v17 * 1.5;
      break;
    default:
      return v17;
  }
  return v17;
}

// 0xfa8bb0
s32 nbGetAisyoTable(s32 formindex) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 id;
  s32 aisyoid;
  nbParty_t_o *PartyFromFormindex;
  struct System_Int16_array *count;
  s32 v9;
  s32 v10;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  if ((UnitWorkFromFormindex->flag & 4) != 0)
  {
    aisyoid = 0;
    if ((byte_3F5869F & 1) != 0)
  }
  id = UnitWorkFromFormindex->id;
  aisyoid = Get(id, 1, 0)->aisyoid;
  if ((byte_3F5869F & 1) == 0)
  else
  {
    PartyFromFormindex = nbGetPartyFromFormindex(formindex);
    if (!PartyFromFormindex)
  }
  count = PartyFromFormindex->count;
  v9 = count->m_Items[19];
  if (v9 <= 0)
  {
    v9 = aisyoid;
    v10 = UnitWorkFromFormindex->badstatus & 0xFFF;
    if (v10 == 512)
      return 247;
  }
  v10 = UnitWorkFromFormindex->badstatus & 0xFFF;
  if (v10 == 512)
    return 247;
  if (v10 == 1024)
    return 246;
  else
    return v9;
}

// 0xfad470
u32 nbGetBadStat(s32 formindex) {
  datUnitWork_t_o *UnitWorkFromFormindex;

  else
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    if (UnitWorkFromFormindex)
      LODWORD(UnitWorkFromFormindex) = UnitWorkFromFormindex->badstatus & 0xFFF;
  }
  return UnitWorkFromFormindex;
}

// 0xfb1cc0
s32 nbGetButuriAttack(s32 nskill, s32 sformindex, s32 dformindex, s32 waza) {
    nbGetUnitWorkFromFormindex(0);
    nbGetHojoRitu(0, 0);
    datGetNormalAtkPow(0);
    datGetDefPow(0);
    datGetParam(0, 0);
    evtBitCheck(0);
    return 0;
}

// 0xfb1900
s32 nbGetButuriKaifuku(s32 nskill, s32 sformindex, s32 dformindex, s32 waza) {
  return nbGetButuriAttack(nskill, sformindex, dformindex, waza);
}

// 0xfb8660
f32 nbGetCriticalPow(s32 sformindex, f32 pow) {
  return pow * 1.5;
}

// 0xfb3e00
s32 nbGetDeadType(s32 nskill, s32 sformindex, s32 dformindex) {
  return 0;
}

// 0xfb0840
u32 nbGetDevilFormatFlag(s32 formindex) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 id;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  if (UnitWorkFromFormindex)
  {
    if ((UnitWorkFromFormindex->flag & 4) != 0)
    {
      LODWORD(UnitWorkFromFormindex) = 0;
    }
    else
    {
      id = UnitWorkFromFormindex->id;
      LODWORD(UnitWorkFromFormindex) = Get(id, 1, 0)->flag;
    }
  }
  return UnitWorkFromFormindex;
}

// 0xfb5490
void nbGetEncountTableItem(nbMainProcessData_t *data) {
  s32 encno;
  s32 v5;
  s32 item;
  datEncount_t_o *v7;
  u8 itemcnt;
  struct System_Byte_array *v9;
  s64 v10;
  struct System_Byte_array *v11;
  struct System_Byte_array *v14;
  struct System_Byte_array *v16;
  struct System_Byte_array *v18;
  struct System_Byte_array *v20;
  struct System_Byte_array *v22;
  struct System_Byte_array *v24;
  struct System_Byte_array *v26;
  struct System_Byte_array *v28;
  u64 max_length_low;
  struct System_Byte_array *v32;
  u64 v33;
  struct System_Byte_array *v36;
  u64 v37;
  struct System_Byte_array *v40;
  u64 v41;
  struct System_Byte_array *v42;
  struct System_Byte_array *v43;
  struct System_Byte_array *v44;
  struct System_Byte_array *v45;
  s64 v46;
  struct System_Byte_array *v47;
  struct System_Byte_array *v49;

  if (data->encno < 1)
    return;
  else if (!IsNOCTURNE())
  {
    encno = data->encno;
    if (datBossRashChk(encno))
      return;
  }
  v5 = data->encno;
  item = Get(v5, 0)->item;
  v7 = Get(data->encno, 0);
  if (item)
  {
    itemcnt = v7->itemcnt;
    if (itemcnt)
    {
      v9 = data->item;
      if (v9->m_Items[0] == item)
      {
        v10 = 0;
        v11 = data->itemcnt;
        if (!LODWORD(v11->max_length))
      }
      v14 = data->item;
      if (v14->m_Items[1] == item)
      {
        v10 = 1;
        v11 = data->itemcnt;
        if (LODWORD(v11->max_length) > 1)
        {
          v11->m_Items[v10] += itemcnt;
          return;
        }
      }
      v16 = data->item;
      if (v16->m_Items[2] == item)
      {
        v10 = 2;
        v11 = data->itemcnt;
        if (LODWORD(v11->max_length) > 2)
      }
      v18 = data->item;
      if (v18->m_Items[3] == item)
      {
        v10 = 3;
        v11 = data->itemcnt;
        if (LODWORD(v11->max_length) > 3)
      }
      v20 = data->item;
      if (v20->m_Items[0])
      {
        v22 = data->item;
        if (v22->m_Items[1])
        {
          v24 = data->item;
          if (v24->m_Items[2])
          {
            v26 = data->item;
            if (v26->m_Items[3])
            {
              v28 = data->item;
              max_length_low = LODWORD(v28->max_length);
              v28->m_Items[3] = v28->m_Items[2];
              v32 = data->itemcnt;
              v33 = LODWORD(v32->max_length);
              v32->m_Items[3] = v32->m_Items[2];
              v36 = data->item;
              v37 = LODWORD(v36->max_length);
              v36->m_Items[2] = v36->m_Items[1];
              v40 = data->itemcnt;
              v41 = LODWORD(v40->max_length);
              v40->m_Items[2] = v40->m_Items[1];
              v42 = data->item;
              v42->m_Items[1] = v42->m_Items[0];
              v43 = data->itemcnt;
              v43->m_Items[1] = v43->m_Items[0];
              v44 = data->item;
              v44->m_Items[0] = item;
              v45 = data->itemcnt;
              v45->m_Items[0] = itemcnt;
              return;
            }
            v46 = 3;
            v47 = data->item;
          }
          else
          {
            v46 = 2;
            v47 = data->item;
            if (LODWORD(v47->max_length) <= 2)
          }
        }
        else
        {
          v46 = 1;
          v47 = data->item;
          if (LODWORD(v47->max_length) <= 1)
        }
      }
      else
      {
        v46 = 0;
        v47 = data->item;
        if (!LODWORD(v47->max_length))
      }
      v47->m_Items[v46] = item;
      v49 = data->itemcnt;
      v49->m_Items[v46] = itemcnt;
    }
  }
}

// 0xfa8fc0
s32 nbGetEscapeSwitch(nbMainProcessData_t *data) {
  s32 encno;

  if ((data->stat & 1) != 0)
    return 0;
  encno = data->encno;
  return Get(encno, 0)->esc != 1;
}

// 0xfb5a60
void nbGetExpMakaItem(datUnitWork_t *w) {
  nbMainProcessData_t_o *MainProcessData;
  s32 encno;
  s32 v7;
  s32 id;
  datDevilFormat_t_o *v9;
  u32 dropexp;
  datDevilFormat_t_o *v11;
  s32 PlayerLevel;
  u32 level;
  s32 v15;
  f32 v16;
  u32 dropmakka;
  s32 Bit;
  u32 v20;
  s32 v21;
  _BOOL4 v22;
  u32 v23;
  s32 specialitem;
  s64 v25;
  struct System_Byte_array *dropitem;
  u64 v27;
  signed s32 RandIntA;
  struct System_Byte_array *droppoint;
  struct System_Byte_array *v32;
  bool v36;
  s32 v37;
  struct System_Byte_array *item;
  s64 v39;
  struct System_Byte_array *itemcnt;
  char *v42;
  char v43;
  struct System_Byte_array *v45;
  struct System_Byte_array *v47;
  struct System_Byte_array *v49;
  struct System_Byte_array *v51;
  struct System_Byte_array *v53;
  struct System_Byte_array *v55;
  struct System_Byte_array *v57;
  s64 v59;
  struct System_Byte_array *v60;
  struct System_Byte_array *v62;

  if ((w->flag & 4) != 0)
    return;
  MainProcessData = nbGetMainProcessData();
  encno = MainProcessData->encno;
  v7 = datBossRashChk(encno);
  id = w->id;
  v9 = Get(id, 1, 0);
  dropexp = v9->dropexp;
  v11 = v9;
  PlayerLevel = datGetPlayerLevel();
  level = w->level;
  v15 = PlayerLevel - level;
  if (level > 0x45)
  {
    if (v15 < 6)
    v16 = 1.3;
  }
  if (v15 < 6)
  if (v15 <= 11)
  v16 = 1.8;
  dropexp = (dropexp / v16);
  dropmakka = v11->dropmakka;
  Bit = cfgGetBit(9u);
  v20 = 5 * dropmakka;
  if (Bit)
  {
    v20 = dropmakka;
    v21 = dropexp;
  }
  else
  {
    v21 = 3 * dropexp;
  }
  v22 = v7 == 0;
  if (v7)
  {
    v21 /= 10;
    v20 /= 0xAu;
  }
  else
  {
    v22 = 1;
  }
  v23 = MainProcessData->exp + v21;
  MainProcessData->maka += v20;
  MainProcessData->exp = v23;
  if (!v22)
    return;
  if (v11->specialbit && !evtBitCheck(v11->specialbit) || !v11->specialitem)
  if (dds3GetRandIntA(0x64u, StringLiteral_21133) >= v11->specialpoint
    || (specialitem = v11->specialitem) == 0)
  {
    v25 = 32;
    do
    {
      dropitem = v11->dropitem;
      v27 = v25 - 32;
      if (!*(&dropitem->obj.klass + v25))
      RandIntA = dds3GetRandIntA(0x64u, StringLiteral_21134);
      droppoint = v11->droppoint;
      if (RandIntA < *(&droppoint->obj.klass + v25))
      {
        v32 = v11->dropitem;
        specialitem = *(&v32->obj.klass + v25);
        if ((v25 - 31) > 1)
          break;
      }
      else
      {
        specialitem = 0;
        if ((v25 - 31) > 1)
          break;
      }
      ++v25;
    }
    while (!specialitem);
  }
  if (dds3GetRandIntA(0x64u, StringLiteral_21135) < v11->hougyokupoint && specialitem == 0)
    specialitem = 4;
  v36 = dds3GetRandIntA(0x64u, StringLiteral_21136) < v11->masekipoint && specialitem == 0;
  v37 = v36 ? 3 : specialitem;
  if (!v37)
    return;
  item = MainProcessData->item;
  if (v37 == item->m_Items[0])
  {
    v39 = 0;
    itemcnt = MainProcessData->itemcnt;
    if (!LODWORD(itemcnt->max_length))
  }
  v45 = MainProcessData->item;
  if (v37 == v45->m_Items[1])
  {
    v39 = 1;
    itemcnt = MainProcessData->itemcnt;
    if (LODWORD(itemcnt->max_length) > 1)
    {
      v42 = itemcnt + v39;
      v43 = itemcnt->m_Items[v39] + 1;
      v42[32] = v43;
      return;
    }
  }
  v47 = MainProcessData->item;
  if (v37 == v47->m_Items[2])
  {
    v39 = 2;
    itemcnt = MainProcessData->itemcnt;
    if (LODWORD(itemcnt->max_length) > 2)
  }
  v49 = MainProcessData->item;
  if (v37 == v49->m_Items[3])
  {
    v39 = 3;
    itemcnt = MainProcessData->itemcnt;
    if (LODWORD(itemcnt->max_length) > 3)
  }
  v51 = MainProcessData->item;
  if (!v51->m_Items[0])
  {
    v59 = 0;
    v60 = MainProcessData->item;
    if (!LODWORD(v60->max_length))
  }
  v53 = MainProcessData->item;
  if (!v53->m_Items[1])
  {
    v59 = 1;
    v60 = MainProcessData->item;
    if (LODWORD(v60->max_length) > 1)
  }
  v55 = MainProcessData->item;
  if (!v55->m_Items[2])
  {
    v59 = 2;
    v60 = MainProcessData->item;
    if (LODWORD(v60->max_length) <= 2)
    v60->m_Items[v59] = v37;
    v62 = MainProcessData->itemcnt;
    v42 = v62 + v59;
    v43 = 1;
  }
  v57 = MainProcessData->item;
  if (!v57->m_Items[3])
  {
    v59 = 3;
    v60 = MainProcessData->item;
    if (LODWORD(v60->max_length) > 3)
  }
}

// 0xfb2e40
f32 nbGetGensyoRitu(s32 nskill, s32 sformindex, s32 dformindex) {
  u32 v4;
  struct datNormalSkill_t_array *tbl;

  LOWORD(v4) = tbl->m_Items[nskill]->minus;
  return v4 / 100.0;
}

// 0xfadf90
s32 nbGetHitType(nbActionProcessData_t *ad, s32 nskill, s32 sformindex, s32 dformindex) {
    nbGetUnitWorkFromFormindex(0);
    nbGetAisyo(0, 0, 0);
    nbHatudoCheckSkill(0, 0);
    nbGetPartyFromFormindex(0);
    datCheckSyojiSkill(0, 0);
    datGetParam(0, 0);
    GetFailpoint(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xf9d810
s32 nbGetHojoCounter(s32 formindex, s32 type) {
  nbParty_t_o *PartyFromFormindex;
  struct System_Int16_array *count;

  else
  {
    PartyFromFormindex = nbGetPartyFromFormindex(formindex);
    if (!PartyFromFormindex)
      return PartyFromFormindex;
  }
  count = PartyFromFormindex->count;
  LODWORD(PartyFromFormindex) = count->m_Items[type];
  return PartyFromFormindex;
}

// 0xf9fb00
s32 nbGetHojoCounterMax(s32 hojotype) {
  if (hojotype > 0x13)
    return 0;
  else
    return dword_33CBA08[hojotype];
}

// 0xf9fb20
s32 nbGetHojoCounterMin(s32 hojotype) {
  if ((hojotype - 4) >= 5)
    return 0;
  else
    return -4;
}

// 0xfb0900
f32 nbGetHojoRitu(s32 formindex, s32 type) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  nbParty_t_o *PartyFromFormindex;
  struct System_Int16_array *count;
  s32 v11;
  s32 AgeOfMoon;
  s32 v13;
  s32 v14;
  f32 v15;
  nbParty_t_o *v16;
  struct System_Int16_array *v17;
  f32 result;
  f32 v20;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  PartyFromFormindex = nbGetPartyFromFormindex(formindex);
  if (!PartyFromFormindex)
  count = PartyFromFormindex->count;
  v11 = count->m_Items[type];
  if (UnitWorkFromFormindex->id != 293)
  AgeOfMoon = evtGetAgeOfMoon();
  v13 = AgeOfMoon - 4;
  if (AgeOfMoon - 4 < 0)
    v13 = AgeOfMoon - 3;
  v11 += v13 >> 1;
  if ((type & 0xFFFFFFFE) != 6)
  {
    if (v11 < 0)
    {
      v20 = v11;
    }
    if (v11)
    {
      v14 = 2 * v11;
      v20 = v14;
      v15 = (v20 + 8.0) * 0.125;
      if (type != 4)
        return v15;
    }
  }
  if (v11 < 0)
  {
    v14 = -2 * v11;
  }
  if (v11)
  {
    v14 = -v11;
  }
  v15 = 1.0;
  if (type != 4)
    return v15;
  v16 = nbGetPartyFromFormindex(formindex);
  if (!v16)
    return v15;
  v17 = v16->count;
  result = v15 * 2.5;
  if (v17->m_Items[15] < 1)
    return v15;
  return result;
}

// 0xfb2cc0
f32 nbGetHpDrainRitu(s32 nskill, s32 sformindex, s32 dformindex) {
  struct datNormalSkill_t_array *tbl;
  f32 result;

  result = 0.0;
  if ((tbl->m_Items[nskill]->hptype & 0xFFFE) == 0xC)
    return 1.0;
  return result;
}

// 0xfb8670
s32 nbGetKakutokuExp(nbMainProcessData_t *data) {
  s32 result;
  s32 encno;

  result = data->exp;
  encno = data->encno;
  if ((encno == 284 || encno == 267) && result >= 20000)
    return 20000;
  return result;
}

// 0xfb86a0
s32 nbGetKakutokuMaka(nbMainProcessData_t *data) {
  s32 result;
  s32 encno;

  result = data->maka;
  encno = data->encno;
  if ((encno == 284 || encno == 267) && result >= 10000)
    return 10000;
  return result;
}

// 0xfb2ef0
u32 nbGetKoukaBadDamage(s32 nskill, s32 sformindex, s32 dformindex, f32 ai, s32 nvirtual) {
    nbGetMainProcessData();
    nbGetUnitWorkFromFormindex(0);
    dds3GetRandIntA(0, 0);
    datGetBadStatusAttr(0);
    nbGetAisyo(0, 0, 0);
    return 0;
}

// 0xfb3a20
u32 nbGetKoukaBadKaifuku(s32 nskill, s32 sformindex, s32 dformindex, f32 ai, s32 nvirtual) {
    nbGetUnitWorkFromFormindex(0);
    datGetParam(0, 0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfb1110
s32 nbGetKoukaHp(s32 sw, s32 nskill, s32 sformindex, s32 dformindex, f32 ritu, s32 cnt) {
    nbGetUnitWorkFromFormindex(0);
    nbGetMagicAttack(0, 0, 0, 0);
    nbGetButuriAttack(0, 0, 0, 0);
    dds3GetRandFloatA(0);
    nbGetMagicKaifuku(0, 0, 0, 0);
    nbGetMaxHpWazaPoint(0, 0, 0, 0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfb25b0
s32 nbGetKoukaMp(s32 sw, s32 nskill, s32 sformindex, s32 dformindex, f32 ritu, s32 cnt) {
  datNormalSkill_c *v15;
  struct datNormalSkill_t_array *tbl;
  u32 mpn;
  s32 mpbase;
  struct datNormalSkill_t_array *v21;
  s32 MagicAttack;
  s32 v25;
  s32 v26;
  datNormalSkill_c *v28;
  struct datNormalSkill_t_array *v29;
  u32 MagicKaifuku;
  signed s32 mp;
  s32 maxmp;
  s32 v34;
  struct datNormalSkill_t_array *v36;
  struct datNormalSkill_t_array *v38;
  u32 mptype;
  struct datNormalSkill_t_array *v42;
  s64 *v44;
  f32 RandFloatA;
  s32 Bit;
  f32 v47;
  f32 v48;
  datUnitWork_t_o *UnitWorkFromFormindex;

  nbGetUnitWorkFromFormindex(sformindex);
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(dformindex);
  mpn = tbl->m_Items[nskill]->mpn;
  mpbase = tbl->m_Items[nskill]->mpbase;
  switch (tbl->m_Items[nskill]->mptype)
  {
    case 1u:
    case 0xCu:
    case 0xEu:
      v21 = tbl;
      if (v21->m_Items[nskill]->koukatype == 1)
      {
        MagicAttack = nbGetMagicAttack(nskill, sformindex, dformindex, mpn);
      }
      else if (v21->m_Items[nskill]->koukatype)
      {
        MagicAttack = 0;
      }
      else
      {
        MagicAttack = nbGetButuriAttack(nskill, sformindex, dformindex, mpn);
      }
      v25 = MagicAttack + mpbase;
      v36 = tbl;
      v26 = -1;
      if (cnt < 2 || v36->m_Items[nskill]->mptype != 14)
      v26 = -1;
      v25 /= cnt;
      v38 = tbl;
      mptype = v38->m_Items[nskill]->mptype;
      if (mptype > 7)
      {
        if ((mptype | 2) != 0xE)
        if (v25 < 1)
      }
      if (mptype - 1 < 2)
      if (v25 < 1 || (mptype & 0xFFFE) != 6)
      v42 = tbl;
      if (v42->m_Items[nskill]->koukatype == 1)
      {
        v44 = &StringLiteral_21115;
      }
      else
      {
        if (v42->m_Items[nskill]->koukatype)
        v44 = &StringLiteral_21114;
      }
      RandFloatA = dds3GetRandFloatA(*v44);
      v25 = (((((RandFloatA + -0.5) + (RandFloatA + -0.5)) * 0.05) * v25) + v25);
      v25 = ((v25 & ~(v25 >> 31)) * ritu);
      Bit = cfgGetBit(9u);
      if (Bit == 1)
      {
        if (sformindex < 4)
        v47 = v25;
        v48 = 0.7;
      }
      else
      {
        if (Bit)
        v47 = v25;
        if (sformindex < 4)
        {
          if (dformindex <= 3)
            v48 = 0.25;
          else
            v48 = 2.25;
        }
        else
        {
          v48 = 0.3;
        }
      }
      v25 = (v47 * v48);
      if (!sw)
        return v26;
      if (v25 <= UnitWorkFromFormindex->mp)
        return v25;
      return UnitWorkFromFormindex->mp;
    case 2u:
      v29 = tbl;
      if (v29->m_Items[nskill]->koukatype == 1)
      {
        MagicKaifuku = nbGetMagicKaifuku(v28, sformindex, dformindex, mpn);
      }
      else if (v29->m_Items[nskill]->koukatype)
      {
        MagicKaifuku = 0;
      }
      else
      {
        MagicKaifuku = nbGetButuriAttack(nskill, sformindex, dformindex, mpn);
      }
    case 3u:
      mp = UnitWorkFromFormindex->mp;
      if ((mpbase + mpn) >= mp)
        v25 = -1;
      else
        v25 = mp - (mpbase + mpn);
    case 4u:
    case 0xDu:
      v25 = mpbase + mpn;
    case 5u:
      v26 = mpbase + mpn;
      v25 = -1;
    case 6u:
      v25 = nbGetMaxHpWazaPoint(v15, sformindex, dformindex, mpn) + mpbase;
    case 7u:
      MagicKaifuku = nbGetMaxHpWazaPoint(v15, sformindex, dformindex, mpn);
    case 8u:
      maxmp = UnitWorkFromFormindex->mp;
    case 9u:
      v34 = UnitWorkFromFormindex->mp;
    case 0xAu:
      maxmp = UnitWorkFromFormindex->maxmp;
      v25 = (maxmp * mpn) / 100 + mpbase;
      v26 = -1;
    case 0xBu:
      v34 = UnitWorkFromFormindex->maxmp;
      v26 = (v34 * mpn) / 100 + mpbase;
      v25 = -1;
    case 0xFu:
      MagicKaifuku = dds3GetRandIntA(mpn, StringLiteral_21113);
      v26 = MagicKaifuku + mpbase;
      v25 = -1;
    default:
      v26 = -1;
      v25 = -1;
  }
}

// 0xfafc90
s32 nbGetKoukaType(s32 nskill, s32 sformindex, s32 dformindex) {
    nbGetMainProcessData();
    nbGetUnitWorkFromFormindex(0);
    nbGetDevilFormatFlag(0);
    nbGetAisyo(0, 0, 0);
    IsNOCTURNE();
    datCheckSyojiSkill(0, 0);
    nbCheckKoukaJyoken(0, 0, 0);
    nbGetHojoRitu(0, 0);
    datGetSakePow(0);
    datGetMagicHitPow(0);
    datGetParam(0, 0);
    GetFailpoint(0);
    dds3GetRandIntA(0, 0);
    return 0;
}

// 0xfa0dc0
s32 nbGetLvAvg(nbMainProcessData_t *data, s32 side) {
  s32 v5;
  s32 v6;
  s64 v7;
  struct nbParty_t_array *party;
  u64 v9;
  struct nbParty_t_array *v11;
  struct nbParty_t_array *v13;
  struct nbParty_t_array *v15;
  nbParty_t_o *v17;
  struct nbParty_t_array *v18;
  u64 v19;
  struct nbParty_t_array *v21;
  struct nbParty_t_array *v23;
  struct nbParty_t_array *v25;
  nbParty_t_o *v27;

  v5 = 0;
  v6 = 0;
  v7 = 4;
  if (side)
  {
    do
    {
      party = data->party;
      v9 = v7 - 4;
      if ((*(*(&party->obj.klass + v7) + 16LL) & 1) != 0)
      {
        v11 = data->party;
        if ((*(*(&v11->obj.klass + v7) + 16LL) & 4) == 0)
        {
          v13 = data->party;
          if ((*(*(&v13->obj.klass + v7) + 16LL) & 2) != 0)
          {
            v15 = data->party;
            v17 = *(&v15->obj.klass + v7);
            ++v6;
            v5 += nbGetUnitWorkPointer(data, v17)->level;
          }
        }
      }
      ++v7;
    }
    while (v7 != 18);
  }
  else
  {
    do
    {
      v18 = data->party;
      v19 = v7 - 4;
      if ((*(*(&v18->obj.klass + v7) + 16LL) & 1) != 0)
      {
        v21 = data->party;
        if ((*(*(&v21->obj.klass + v7) + 16LL) & 4) == 0)
        {
          v23 = data->party;
          if ((*(*(&v23->obj.klass + v7) + 16LL) & 2) == 0)
          {
            v25 = data->party;
            v27 = *(&v25->obj.klass + v7);
            ++v6;
            v5 += nbGetUnitWorkPointer(data, v27)->level;
          }
        }
      }
      ++v7;
    }
    while (v7 != 18);
  }
  if (v6)
    return v5 / v6;
  else
    return 0;
}

// 0xfb60b0
s32 nbGetLvAvg2(nbMainProcessData_t *data, s32 side) {
  u64 v5;
  s32 v6;
  s32 v7;
  s32 encno;
  struct System_UInt16_array *devil;
  char *v11;
  s32 v12;
  u64 v13;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v17;

  if (side)
  {
    v5 = 0;
    v6 = 0;
    v7 = 0;
    do
    {
      encno = data->encno;
      devil = Get(encno, 0)->devil;
      v11 = devil + 2 * v5;
      v12 = *(v11 + 16);
      if (*(v11 + 16))
      {
        ++v7;
        v6 += Get(v12, 1, 0)->level;
      }
      ++v5;
    }
    while (v5 != 11);
  }
  else
  {
    v13 = 0;
    v6 = 0;
    v7 = 0;
    do
    {
      unitwork = DDS3_GBWK->unitwork;
      v17 = unitwork->m_Items[v13];
      if ((~v17->flag & 3) == 0)
      {
        ++v7;
        v6 += v17->level;
      }
      ++v13;
    }
    while (v13 != 16);
  }
  if (v7)
    return v6 / v7;
  else
    return 0;
}

// 0xfb2040
s32 nbGetMagicAttack(s32 nskill, s32 sformindex, s32 dformindex, s32 waza) {
    nbGetUnitWorkFromFormindex(0);
    nbGetHojoRitu(0, 0);
    datGetParam(0, 0);
    IsNOCTURNE();
    evtBitCheck(0);
    return 0;
}

// 0xfb1910
s32 nbGetMagicKaifuku(s32 nskill, s32 sformindex, s32 dformindex, s32 waza) {
    nbGetUnitWorkFromFormindex(0);
    nbGetHojoRitu(0, 0);
    dds3GetRandIntA(0, 0);
    datGetParam(0, 0);
    return 0;
}

// 0xfb8030
s32 nbGetMakaBaramaki(datUnitWork_t *w) {
    datGetParam(0, 0);
    Get(0);
    sdfFabs(0);
    dds3GetRandFloatA(0);
    return 0;
}

// 0xfb1ae0
s32 nbGetMaxHpWazaPoint(s32 nskill, s32 sformindex, s32 dformindex, s32 waza) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  f32 HojoRitu;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v17;
  f32 v18;
  s32 Bit;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(sformindex);
  nbGetUnitWorkFromFormindex(dformindex);
  HojoRitu = nbGetHojoRitu(sformindex, 4);
  v13 = nbGetHojoRitu(dformindex, 7);
  v14 = v13;
  if ((UnitWorkFromFormindex->flag & 0x20) != 0)
  {
    v17 = ((datGetBaseMaxHp(UnitWorkFromFormindex) / 69.6) * waza) * 0.6;
    v18 = -50.0 / (UnitWorkFromFormindex->level + 10);
    v15 = v17 + v18;
    Bit = cfgGetBit(9u);
    if (Bit == 3)
    {
      if (evtBitCheck(2208))
        v15 = v15 * 1.34;
    }
    else if (Bit == 2)
    {
      v15 = v15 * 1.34;
    }
  }
  else
  {
    LOWORD(v13) = UnitWorkFromFormindex->maxhp;
    v15 = ((LODWORD(v13) / 69.6) * waza) * 0.8;
  }
  return (v14 * (HojoRitu * v15));
}

// 0xfb2d80
f32 nbGetMpDrainRitu(s32 nskill, s32 sformindex, s32 dformindex) {
  struct datNormalSkill_t_array *tbl;
  f32 result;

  result = 0.0;
  if ((tbl->m_Items[nskill]->mptype & 0xFFFE) == 0xC)
    return 1.0;
  return result;
}

// 0xfae5c0
s32 nbGetNormalSkillAttr(s32 nskill) {
  struct datSkill_t_array *tbl;

  return tbl->m_Items[nskill]->skillattr;
}

// 0xfb6260
s32 nbGetParamAvg(nbMainProcessData_t *data, s32 side, s32 paratype) {
  s32 v7;
  s32 v8;
  s64 v9;
  struct nbParty_t_array *party;
  u64 v11;
  struct nbParty_t_array *v13;
  struct nbParty_t_array *v15;
  struct nbParty_t_array *v17;
  nbParty_t_o *v19;
  datUnitWork_t_o *UnitWorkPointer;
  struct nbParty_t_array *v22;
  u64 v23;
  struct nbParty_t_array *v25;
  struct nbParty_t_array *v27;
  struct nbParty_t_array *v29;
  nbParty_t_o *v31;
  datUnitWork_t_o *v33;

  v7 = 0;
  v8 = 0;
  v9 = 4;
  if (side)
  {
    do
    {
      party = data->party;
      v11 = v9 - 4;
      if ((*(*(&party->obj.klass + v9) + 16LL) & 1) != 0)
      {
        v13 = data->party;
        if ((*(*(&v13->obj.klass + v9) + 16LL) & 4) == 0)
        {
          v15 = data->party;
          if ((*(*(&v15->obj.klass + v9) + 16LL) & 2) != 0)
          {
            v17 = data->party;
            v19 = *(&v17->obj.klass + v9);
            UnitWorkPointer = nbGetUnitWorkPointer(data, v19);
            ++v8;
            v7 += datGetParam(UnitWorkPointer, paratype);
          }
        }
      }
      ++v9;
    }
    while (v9 != 18);
  }
  else
  {
    do
    {
      v22 = data->party;
      v23 = v9 - 4;
      if ((*(*(&v22->obj.klass + v9) + 16LL) & 1) != 0)
      {
        v25 = data->party;
        if ((*(*(&v25->obj.klass + v9) + 16LL) & 4) == 0)
        {
          v27 = data->party;
          if ((*(*(&v27->obj.klass + v9) + 16LL) & 2) == 0)
          {
            v29 = data->party;
            v31 = *(&v29->obj.klass + v9);
            v33 = nbGetUnitWorkPointer(data, v31);
            ++v8;
            v7 += datGetParam(v33, paratype);
          }
        }
      }
      ++v9;
    }
    while (v9 != 18);
  }
  if (v8)
    return v7 / v8;
  else
    return 0;
}

// 0xfb6530
s32 nbGetParamAvg2(nbMainProcessData_t *data, s32 side, s32 paratype) {
  u64 v7;
  s32 v8;
  s32 v9;
  s32 encno;
  struct System_UInt16_array *devil;
  char *v13;
  s32 v14;
  struct System_SByte_array *param;
  u64 v17;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v21;

  if (side)
  {
    v7 = 0;
    v8 = 0;
    v9 = 0;
    do
    {
      encno = data->encno;
      devil = Get(encno, 0)->devil;
      v13 = devil + 2 * v7;
      v14 = *(v13 + 16);
      if (*(v13 + 16))
      {
        ++v9;
        param = Get(v14, 1, 0)->param;
        v8 += param->m_Items[paratype];
      }
      ++v7;
    }
    while (v7 != 11);
  }
  else
  {
    v17 = 0;
    v8 = 0;
    v9 = 0;
    do
    {
      unitwork = DDS3_GBWK->unitwork;
      v21 = unitwork->m_Items[v17];
      if ((~v21->flag & 3) == 0)
      {
        ++v9;
        v8 += datGetParam(v21, paratype);
      }
      ++v17;
    }
    while (v17 != 16);
  }
  if (v9)
    return v8 / v9;
  else
    return 0;
}

// 0xfa2a40
s32 nbGetVirtualAisyo(s32 nskill, s32 sformindex, s32 dformindex) {
  struct datSkill_t_array *tbl;
  s32 skillattr;
  u32 Aisyo;

  skillattr = tbl->m_Items[nskill]->skillattr;
  if (skillattr == -1 || (skillattr - 12) < 3)
    return 0;
  Aisyo = nbGetAisyo(nskill, dformindex, skillattr);
  if ((Aisyo & 0x20000) != 0)
    return 0x20000;
  if ((Aisyo & 0x40000) != 0)
    return 0x40000;
  if ((Aisyo & 0x10000) == 0)
    return 0;
  return 0x10000;
}

// 0xfa2780
s32 nbGetVirtualKoukaPoint(s32 nskill, s32 sformindex, s32 dformindex) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  f32 AisyoRitu;
  u32 KoukaBadDamage;
  u32 KoukaBadKaifuku;
  s32 v17;
  s32 KoukaMp;
  s32 v22;
  struct datNormalSkill_t_array *tbl;
  u32 hojotype;
  struct datNormalSkill_t_array *v28;
  s32 v30;
  _BOOL4 v31;
  s32 v32;
  s32 v33;
  s32 v34;
  s32 v35;
  s32 v36;
  s32 v37;
  s32 v38;
  s32 v39;
  s32 KoukaHp;

  nbGetUnitWorkFromFormindex(sformindex);
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(dformindex);
  AisyoRitu = nbGetAisyoRitu(nskill, sformindex, dformindex);
  KoukaBadDamage = nbGetKoukaBadDamage(nskill, sformindex, dformindex, AisyoRitu, 1);
  KoukaBadKaifuku = nbGetKoukaBadKaifuku(nskill, sformindex, dformindex, AisyoRitu, 1);
  KoukaHp = nbGetKoukaHp(1, nskill, sformindex, dformindex, AisyoRitu, 1);
  v17 = nbGetKoukaHp(0, nskill, sformindex, dformindex, AisyoRitu, 1);
  if (v17 >= 1 && v17 > UnitWorkFromFormindex->maxhp - UnitWorkFromFormindex->hp)
    v17 = UnitWorkFromFormindex->maxhp - UnitWorkFromFormindex->hp;
  KoukaMp = nbGetKoukaMp(1, nskill, sformindex, dformindex, AisyoRitu, 1);
  v22 = nbGetKoukaMp(0, nskill, sformindex, dformindex, AisyoRitu, 1);
  if (v22 >= 1 && v22 > UnitWorkFromFormindex->maxmp - UnitWorkFromFormindex->mp)
    v22 = UnitWorkFromFormindex->maxmp - UnitWorkFromFormindex->mp;
  hojotype = tbl->m_Items[nskill]->hojotype;
  if (hojotype)
  {
    v28 = tbl;
    v30 = nbSetHojoKouka(dformindex, hojotype, v28->m_Items[nskill]->hojopoint, 1);
  }
  else
  {
    v30 = 0;
  }
  v31 = KoukaBadDamage != 0;
  if (KoukaBadDamage)
    v32 = 2;
  else
    v32 = 1;
  if (KoukaBadKaifuku)
    v31 = v32;
  if (KoukaHp >= 2)
    v33 = KoukaHp;
  else
    v33 = 0;
  v34 = v33 + v31;
  if (v17 >= 2)
    v35 = v17;
  else
    v35 = 0;
  v36 = v34 + v35;
  if (KoukaMp >= 2)
    v37 = KoukaMp;
  else
    v37 = 0;
  v38 = v36 + v37;
  if (v22 >= 2)
    v39 = v22;
  else
    v39 = 0;
  return v38 + v39 + v30;
}

// 0xfaf9d0
s32 nbHatudoCheckSkill(datUnitWork_t *work, s32 skill) {
  s32 result;

  result = datCheckSyojiSkill(work, skill);
  if (result)
  {
    if (skill == 301)
    {
      return evtGetAgeOfMoon() == 0;
    }
    else
    {
      if (skill != 300)
        return 1;
      return evtGetAgeOfMoon() == 8;
    }
  }
  return result;
}

// 0xfb40c0
void nbSetBadStat(s32 formindex, s32 sw, s32 badstat) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v9;

  else
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    if (!UnitWorkFromFormindex)
      return;
  }
  v9 = UnitWorkFromFormindex;
  if (sw)
  {
    datSetBadStat(v9, badstat);
  }
  else
  {
    datResetBadStat(v9, badstat);
  }
}

// 0xfb44a0
s32 nbSetHojoAddCounter(s32 formindex, s32 type, s32 point, s32 nvirtual) {
  nbParty_t_o *PartyFromFormindex;
  struct System_Int16_array *count;
  s32 v12;
  s32 v13;
  s32 v14;
  struct System_Int16_array *v15;

  PartyFromFormindex = nbGetPartyFromFormindex(formindex);
  if (PartyFromFormindex)
  {
    count = PartyFromFormindex->count;
    v12 = count->m_Items[type];
    v13 = v12 + point;
    if (type <= 0x13)
    {
      if (v13 > dword_33CBA08[type])
      {
        v13 = dword_33CBA08[type];
        if (!nvirtual)
      }
      if ((type - 4) >= 5)
        v14 = 0;
      else
        v14 = -4;
      if (v13 < v14)
        v13 = v14;
    }
    if (!nvirtual)
    {
      v15 = PartyFromFormindex->count;
      v15->m_Items[type] = v13;
    }
    LODWORD(PartyFromFormindex) = v13 - v12;
  }
  return PartyFromFormindex;
}

// 0xf9da80
void nbSetHojoCounter(s32 formindex, s32 type, s32 point) {
  s16 v4;
  nbParty_t_o *PartyFromFormindex;
  struct System_Int16_array *count;

  v4 = point;
  else
  {
    PartyFromFormindex = nbGetPartyFromFormindex(formindex);
    if (!PartyFromFormindex)
      return;
  }
  count = PartyFromFormindex->count;
  count->m_Items[type] = v4;
}

// 0xfb45f0
s32 nbSetHojoKouka(s32 formindex, u32 hojotype, s32 hojopoint, s32 nvirtual) {
    nbSetHojoAddCounter(0, 0, 0, 0);
    nbGetPartyFromFormindex(0);
    return 0;
}

// 0xfb8580
void nbSetHpScale(nbFormation_t *form) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  u32 v6;
  datUnitWork_t_o *v7;
  f32 v8;

  formindex = form->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  if (UnitWorkFromFormindex)
  {
    v7 = UnitWorkFromFormindex;
    if (UnitWorkFromFormindex->hp)
    {
      LOWORD(v6) = UnitWorkFromFormindex->maxhp;
      v8 = UnitWorkFromFormindex->hp / v6;
      form->scl = (v8 * (nbGetUnitVisual(v7)->formscale + -0.5)) + 0.5;
    }
  }
}

// 0xfb7ec0
void nbSetKuisibariStop(s32 formindex) {
  nbParty_t_o *PartyFromFormindex;

  else
  {
    PartyFromFormindex = nbGetPartyFromFormindex(formindex);
    if (!PartyFromFormindex)
      return;
  }
  if ((PartyFromFormindex->flag & 0x200) != 0)
    PartyFromFormindex->flag |= 0x400u;
}
