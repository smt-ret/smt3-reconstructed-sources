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

  else if (!IsNOCTURNE())
  {
    goto LABEL_10;
  }
  if ((nskill - 131) <= 0x20 && ((1LL << (nskill + 125)) & 0x120013001LL) != 0)
    return 30;
LABEL_10:
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
  s32 encno;
  s32 backattack;
  s32 LvAvg2;
  s32 ParamAvg2;
  s32 v12;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v16;
  s32 level;
  s32 Param;
  s32 v19;
  s32 v21;
  s32 v22;
  s32 v23;
  s32 v24;
  s32 v25;
  signed s32 RandIntA;
  struct datSpecialSkill_t_array *tbl;
  s32 v31;
  s32 v32;
  System_Object_array *v33;
  s64 *v34;
  s64 *v35;
  s64 *v37;
  s64 *v38;
  s64 *v41;
  s64 *v42;
  s64 *v45;
  s64 *v47;
  signed s32 v51;
  s32 v52;
  s32 v53;
  s32 v54;

  encno = data->encno;
  backattack = Get(encno, 0)->backattack;
  if (backattack == 1)
    return 1;
  if (backattack == 255)
    return 0;
  LvAvg2 = nbGetLvAvg2(data, 1);
  ParamAvg2 = nbGetParamAvg2(data, 1, 4);
  v12 = nbGetParamAvg2(data, 1, 5);
  unitwork = DDS3_GBWK->unitwork;
  v16 = unitwork->m_Items[0];
  level = v16->level;
  Param = datGetParam(v16, 4);
  v19 = datGetParam(v16, 5);
  v21 = LvAvg2 + ParamAvg2;
  if (v19 >= 0)
    v22 = v19;
  else
    v22 = v19 + 1;
  v23 = level + Param + (v22 >> 1) + 10;
  if (v12 >= 0)
    v24 = v12;
  else
    v24 = v12 + 1;
  v25 = v21 + (v24 >> 1);
  RandIntA = dds3GetRandIntA(0x64u, "nbCheckBackAttack");
  if (datCheckSkillInParty(298))
  {
    v31 = 12 / tbl->m_Items[10]->n;
  }
  else
  {
    v31 = 12;
  }
  v32 = v25 + 10;
  v54 = v23;
  v33 = NewSpecific(object, 4u);
  v34 = sub_8D3950(s32, &v54);
  v35 = v34;
  v33->m_Items[0] = v35;
  v53 = v32;
  v37 = sub_8D3950(s32, &v53);
  v38 = v37;
  v33->m_Items[1] = v38;
  v52 = v31;
  v41 = sub_8D3950(s32, &v52);
  v42 = v41;
  v33->m_Items[2] = v42;
  v51 = RandIntA;
  v45 = sub_8D3950(s32, &v51);
  v47 = v45;
  v33->m_Items[3] = v47;
  Write_2930544("バックアタック確率 X = {0:D}, Y = {1:D}, B = {2:D} rand = {3:D}\n", v33, 0);
  return v31 > RandIntA;
}

// 0xfac360
s32 nbCheckBadCurse(s32 formindex) {
  datUnitWork_t_o *UnitWorkFromFormindex;

  else
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    if (UnitWorkFromFormindex)
LABEL_6:
      LODWORD(UnitWorkFromFormindex) = UnitWorkFromFormindex->badstatus >> 15;
  }
  return UnitWorkFromFormindex;
}

// 0xfb41c0
s32 nbCheckBadKaifuku(datUnitWork_t *work, s32 type) {
  s32 result;
  s32 v6;
  u16 badstatus;
  u32 v8;
  s32 v9;
  s32 level;
  s32 Param;
  f32 v12;
  f32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  u64 *v18;
  s32 v20;
  s32 v21;
  s32 v22;

  if (work && (work->flag & 1) != 0)
  {
    v6 = type;
    badstatus = work->badstatus;
    v8 = badstatus & 0xFFF;
    switch (v6)
    {
      case 0:
        if (v8 > 4)
        {
          v9 = badstatus & 0xFFF;
          if (v9 != 8 && v9 != 128 && v9 != 16)
            return 0;
        }
        else
        {
          if (v8 - 1 < 2)
            return 1;
          if (v8 != 4)
            return 0;
        }
        level = work->level;
        Param = datGetParam(work, 5 / ((level + 20) / 5u), 0);
        v12 = 40.0;
        v13 = 20.0;
        if (v8 < 9)
          v12 = 30.0;
        else
          v13 = 30.0;
        if (v8 >= 9)
          v14 = 128;
        else
          v14 = 8;
        if (v8 >= 9)
          v15 = 16;
        else
          v15 = 4;
        if (v8 != v14)
          v12 = 0.0;
        if (v8 == v15)
          v12 = v13;
        v16 = (v12 * Param);
        v22 = v16;
        v18 = sub_8D3950(s32, &v22);
        Write_2930400("バットステータス回復確率 = {0:D}\n", v18);
        return dds3GetRandIntA(0x64u, "nbCheckBadKaifuku") < v16;
      case 1:
        return v8 == 16;
      case 2:
        return v8 == 4;
      case 3:
        if (v8 > 8)
        {
          v20 = badstatus & 0xFFF;
          result = 1;
          if (v8 > 0x80)
          {
            if (v20 == 512 || v20 == 1024)
              return result;
          }
          else if (v20 == 16 || v20 == 128)
          {
            return result;
          }
        }
        else
        {
          if (v8 - 1 < 2)
            return 1;
          v21 = badstatus & 0xFFF;
          result = 1;
          if (v21 == 4 || v21 == 8)
            return result;
        }
        break;
      default:
        return 0;
    }
  }
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
  return v5 <= dds3GetRandIntA(0x64u, "nbCheckBadPanicAction");
}

// 0xfb83f0
s32 nbCheckBadStatusGameOver(nbMainProcessData_t *data) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v4;
  datUnitWork_t_o *v6;
  datUnitWork_t_o *v8;

  else
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(0);
    if (!UnitWorkFromFormindex)
      goto LABEL_7;
  }
  if ((UnitWorkFromFormindex->badstatus & 0xFFF) != 0x400)
    return 0;
LABEL_7:
  else
  {
    v4 = nbGetUnitWorkFromFormindex(1);
    if (!v4)
      goto LABEL_11;
  }
  if ((v4->badstatus & 0xFFF) != 0x400)
    return 0;
LABEL_11:
  else
  {
    v6 = nbGetUnitWorkFromFormindex(2);
    if (v6)
      goto LABEL_14;
  }
  else
  {
    v8 = nbGetUnitWorkFromFormindex(3);
    if (!v8)
      return 1;
  }
  return (v8->badstatus & 0xFFF) == 0x400;
}

// 0xfb7170
s32 nbCheckEscape(nbMainProcessData_t *data) {
  s32 encno;
  datUnitWork_t_o *UnitWorkFromFormindex;
  u32 v7;
  s32 v8;
  datUnitWork_t_o *v10;
  u32 v12;
  datUnitWork_t_o *v14;
  u32 v16;
  datUnitWork_t_o *v17;
  u32 v19;
  datUnitWork_t_o *v20;
  u32 v22;
  datUnitWork_t_o *v23;
  u32 v25;
  datUnitWork_t_o *v26;
  u32 v28;
  datUnitWork_t_o *v29;
  u32 v31;
  datUnitWork_t_o *v32;
  u32 v34;
  datUnitWork_t_o *v35;
  u32 v37;
  s32 result;
  s32 ParamAvg;
  s32 v41;
  s32 v43;
  s32 v45;
  s32 esccnt;
  s32 v48;
  s32 v49;
  struct datSpecialSkill_t_array *tbl;
  s32 Bit;
  u64 *v56;
  s32 v61;
  s32 v63;

  encno = data->encno;
  if ((Get(encno, 0)->flag & 0x20) != 0)
    return 1;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(4);
  if (!UnitWorkFromFormindex)
    goto LABEL_31;
LABEL_10:
  v7 = UnitWorkFromFormindex->badstatus & 0xFFF;
  v8 = 1;
  if (v7 > 4)
  {
    if (v7 == 16 || v7 == 256 || v7 == 1024)
      goto LABEL_18;
LABEL_17:
    v8 = 0;
    goto LABEL_18;
  }
  if (v7 != 4 && v7 - 1 >= 2)
    goto LABEL_17;
LABEL_18:
    goto LABEL_32;
LABEL_19:
LABEL_32:
  v10 = nbGetUnitWorkFromFormindex(5);
  if (!v10)
    goto LABEL_33;
LABEL_21:
  v12 = v10->badstatus & 0xFFF;
  if (v12 <= 4)
  {
    if (v12 == 4 || v12 - 1 < 2)
    {
LABEL_33:
        goto LABEL_36;
      goto LABEL_34;
    }
  }
  else if (v12 == 16 || v12 == 256 || v12 == 1024)
  {
    goto LABEL_33;
  }
  v8 = 0;
    goto LABEL_36;
LABEL_34:
LABEL_36:
  v14 = nbGetUnitWorkFromFormindex(6);
  if (!v14)
    goto LABEL_45;
  v16 = v14->badstatus & 0xFFF;
  if (v16 > 4)
  {
    if (v16 == 16 || v16 == 256 || v16 == 1024)
      goto LABEL_45;
LABEL_44:
    v8 = 0;
    goto LABEL_45;
  }
  if (v16 != 4 && v16 - 1 >= 2)
    goto LABEL_44;
LABEL_45:
  v17 = nbGetUnitWorkFromFormindex(7);
  if (v17)
  {
    v19 = v17->badstatus & 0xFFF;
    if (v19 > 4)
    {
      if (v19 == 16 || v19 == 256 || v19 == 1024)
        goto LABEL_57;
LABEL_56:
      v8 = 0;
      goto LABEL_57;
    }
    if (v19 != 4 && v19 - 1 >= 2)
      goto LABEL_56;
  }
LABEL_57:
  v20 = nbGetUnitWorkFromFormindex(8);
  if (v20)
  {
    v22 = v20->badstatus & 0xFFF;
    if (v22 > 4)
    {
      if (v22 == 16 || v22 == 256 || v22 == 1024)
        goto LABEL_69;
LABEL_68:
      v8 = 0;
      goto LABEL_69;
    }
    if (v22 != 4 && v22 - 1 >= 2)
      goto LABEL_68;
  }
LABEL_69:
  v23 = nbGetUnitWorkFromFormindex(9);
  if (v23)
  {
    v25 = v23->badstatus & 0xFFF;
    if (v25 > 4)
    {
      if (v25 == 16 || v25 == 256 || v25 == 1024)
        goto LABEL_81;
LABEL_80:
      v8 = 0;
      goto LABEL_81;
    }
    if (v25 != 4 && v25 - 1 >= 2)
      goto LABEL_80;
  }
LABEL_81:
  v26 = nbGetUnitWorkFromFormindex(10);
  if (v26)
  {
    v28 = v26->badstatus & 0xFFF;
    if (v28 > 4)
    {
      if (v28 == 16 || v28 == 256 || v28 == 1024)
        goto LABEL_93;
LABEL_92:
      v8 = 0;
      goto LABEL_93;
    }
    if (v28 != 4 && v28 - 1 >= 2)
      goto LABEL_92;
  }
LABEL_93:
  v29 = nbGetUnitWorkFromFormindex(11);
  if (v29)
  {
    v31 = v29->badstatus & 0xFFF;
    if (v31 > 4)
    {
      if (v31 == 16 || v31 == 256 || v31 == 1024)
        goto LABEL_105;
LABEL_104:
      v8 = 0;
      goto LABEL_105;
    }
    if (v31 != 4 && v31 - 1 >= 2)
      goto LABEL_104;
  }
LABEL_105:
  v32 = nbGetUnitWorkFromFormindex(12);
  if (v32)
  {
    v34 = v32->badstatus & 0xFFF;
    if (v34 > 4)
    {
      if (v34 == 16 || v34 == 256 || v34 == 1024)
        goto LABEL_117;
LABEL_116:
      v8 = 0;
      goto LABEL_117;
    }
    if (v34 != 4 && v34 - 1 >= 2)
      goto LABEL_116;
  }
LABEL_117:
  else
  {
    v35 = nbGetUnitWorkFromFormindex(13);
    if (!v35)
      goto LABEL_128;
  }
  v37 = v35->badstatus & 0xFFF;
  if (v37 <= 4)
  {
    if (v37 - 1 > 1 && v37 != 4)
      goto LABEL_131;
  }
  else if (v37 != 16 && v37 != 1024 && v37 != 256)
  {
    goto LABEL_131;
  }
LABEL_128:
  if (v8)
    return 1;
LABEL_131:
  ParamAvg = nbGetParamAvg(data, 0, 4);
  v41 = nbGetParamAvg(data, 0, 5);
  v43 = nbGetParamAvg(data, 1, 4);
  v45 = nbGetParamAvg(data, 1, 5);
  esccnt = data->esccnt;
  v48 = (((v41 + ParamAvg) / (v45 + v43)) * 20.0);
  v49 = v48 + 20 * esccnt;
  if (datCheckSkillInParty(296))
  {
    v49 = v49 * tbl->m_Items[8]->n / 100;
  }
  Bit = cfgGetBit(9u);
  switch (Bit)
  {
    case 0:
      return 1;
    case 2:
      return 0;
    case 1:
      v49 *= 2;
      break;
  }
  v63 = v49;
  v56 = sub_8D3950(s32, &v63);
  Write_2930400("逃走率 = {0:D}\n", v56);
  if (v49 < dds3GetRandIntA(0x64u, "nbCheckEscape0"))
    return 0;
  if (evtGetAgeOfMoon() != 8)
    return 1;
  result = dds3GetRandIntA(4u, "nbCheckEscape1");
  if (result != 1)
  {
    v61 = cfgGetBit(9u);
    if (v61)
    {
      if (v61 != 1)
        return 0;
      if ((dds3GetRandIntA(2u, "nbCheckEscape3") & 1) == 0)
        return 0;
    }
    return 1;
  }
  return result;
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
  s32 encno;
  s32 encpackno;
  datEncountPack_t_o *v6;
  struct datEncountTbl_s_array *enctable;
  s64 packno;
  datEncountPack_t_o *v10;
  Il2CppClass **v12;
  s64 packindex;
  const char *namespaze;
  const char *v16;
  struct datEncountTbl_s_array *v17;
  s32 v18;
  s64 v19;
  Il2CppClass **v21;
  s64 v22;
  const char *v23;
  s32 v26;
  s32 v27;
  u64 *v28;
  u64 *v30;
  s32 result;
  struct datEncountTbl_s_array *v34;
  s64 v35;
  struct datEncountRitu_s_array *ritu;
  s32 encountid;
  s32 v40;
  s32 v41;

  encno = data->encno;
  if ((Get(encno, 0)->flag & 0x10) != 0)
  {
    data->packindex = 1;
    encountid = 329;
LABEL_42:
    data->encno = encountid;
    nbSetRenzokuEncount(encountid);
    return 1;
  }
  encpackno = data->encpackno;
  if (encpackno < 1)
    return 0;
  v6 = Get(encpackno, 0);
  enctable = v6->enctable;
  packno = data->packno;
  v10 = v6;
  v12 = &enctable->obj.klass + packno;
  packindex = data->packindex;
  namespaze = v12[4]->_1.namespaze;
  v16 = &namespaze[8 * packindex];
  v17 = v6->enctable;
  v18 = *(*(v16 + 4) + 21LL);
  v19 = data->packno;
  v21 = &v17->obj.klass + v19;
  v22 = data->packindex;
  v23 = v21[4]->_1.namespaze;
  v26 = *(*&v23[8 * v22 + 32] + 22LL);
  if ((DDS3_GBWK->stat & 2) != 0)
    v27 = 5 * v18;
  else
    v27 = v18;
  v41 = v27;
  v28 = sub_8D3950(s32, &v41);
  v40 = v26;
  v30 = sub_8D3950(s32, &v40);
  Write_2930752("renzoku ritu = {0:D}, index = {1:D}\n", v28, v30, 0);
  result = cfgGetBit(9u);
  if (result)
  {
    if (v27 > dds3GetRandIntA(0x64u, "nbCheckRenzokuEncount0"))
    {
      data->packindex = v26;
      v34 = v10->enctable;
      v35 = data->packno;
      ritu = v34->m_Items[v35]->ritu;
      encountid = ritu->m_Items[v26]->encountid;
      goto LABEL_42;
    }
    return 0;
  }
  return result;
}

// 0xfb6740
s32 nbCheckSensei(nbMainProcessData_t *data) {
  System_Array_o *v3;
  s32 encno;
  s32 v7;
  s32 LvAvg2;
  s32 ParamAvg2;
  s32 v14;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v18;
  s32 level;
  s32 Param;
  s32 v21;
  s32 v23;
  s32 v24;
  s32 encpackno;
  s32 v26;
  s32 v27;
  s32 v28;
  struct datEncountTbl_s_array *enctable;
  s64 packno;
  struct datEncountRitu_s_array *ritu;
  s64 packindex;
  s64 sensei;
  signed s32 RandIntA;
  System_Object_array *v39;
  s64 *v40;
  s64 *v41;
  s64 *v44;
  s64 *v45;
  s64 *v48;
  s64 *v49;
  s64 *v52;
  s64 *v53;
  s64 *v56;
  s64 *v58;
  s32 Bit;
  signed s32 v65;
  s32 v66;
  s32 v67;
  s32 v68;
  s32 v69;

  v3 = NewSpecific(f32, 6u);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__30B276F56ED6E8118DD09EF0AE25BB4939010C5B);
  encno = data->encno;
  if ((Get(encno, 0)->flag & 4) != 0)
    return 0;
  v7 = data->encno;
  if ((Get(v7, 0)->flag & 2) == 0)
  {
    LvAvg2 = nbGetLvAvg2(data, 1);
    ParamAvg2 = nbGetParamAvg2(data, 1, 4);
    v14 = nbGetParamAvg2(data, 1, 5);
    unitwork = DDS3_GBWK->unitwork;
    v18 = unitwork->m_Items[0];
    level = v18->level;
    Param = datGetParam(v18, 4);
    v21 = datGetParam(v18, 5);
    if (v21 >= 0)
      v23 = v21;
    else
      v23 = v21 + 1;
    v24 = 72 - LvAvg2 - ParamAvg2;
    encpackno = data->encpackno;
    if (v14 >= 0)
      v26 = v14;
    else
      v26 = v14 + 1;
    v27 = v24 - (v26 >> 1) + level + Param + (v23 >> 1);
    if (v27 <= 70)
      v27 = 70;
    if (v27 >= 85)
      v28 = 85;
    else
      v28 = v27;
    enctable = Get(encpackno, 0)->enctable;
    packno = data->packno;
    ritu = enctable->m_Items[packno]->ritu;
    packindex = data->packindex;
    sensei = ritu->m_Items[packindex]->sensei;
    if (LvAvg2 + 15 > level)
    {
      v28 = (*(&v3[2].klass + sensei) * v28);
    }
    RandIntA = dds3GetRandIntA(0x80u, "nbCheckSensei0");
    v69 = level;
    v39 = NewSpecific(object, 5u);
    v40 = sub_8D3950(s32, &v69);
    v41 = v40;
    v39->m_Items[0] = v41;
    v68 = LvAvg2;
    v44 = sub_8D3950(s32, &v68);
    v45 = v44;
    v39->m_Items[1] = v45;
    v67 = sensei;
    v48 = sub_8D3950(uint, &v67);
    v49 = v48;
    v39->m_Items[2] = v49;
    v66 = v28;
    v52 = sub_8D3950(s32, &v66);
    v53 = v52;
    v39->m_Items[3] = v53;
    v65 = RandIntA;
    v56 = sub_8D3950(s32, &v65);
    v58 = v56;
    v39->m_Items[4] = v58;
    Write_2930544("先制率 Plv = {0:D}, Elv = {1:D}, Tbl = {2:D}, z = {3:D}, rnd = {4:D}\n", v39, 0);
    if (v28 > RandIntA)
      return 0;
    Bit = cfgGetBit(9u);
    if (Bit == 1)
    {
      if ((dds3GetRandIntA(0x80u, "nbCheckSensei2") & 1) != 0)
        return 1;
    }
    else
    {
      if (Bit)
        return 1;
      if ((dds3GetRandIntA(0x80u, "nbCheckSensei1") & 3) == 0)
        return 1;
    }
    return 0;
  }
  return 1;
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
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v7;
  datUnitWork_t_o *v8;
  struct datSkill_t_array *tbl;
  s32 Param;
  u32 v14;
  f32 v15;
  f32 v16;
  s32 v17;
  u64 *v19;
  s32 v22;

  else
  {
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(dformindex);
    if (!UnitWorkFromFormindex)
      return 0;
  }
  v7 = UnitWorkFromFormindex;
  v8 = nbGetUnitWorkFromFormindex(dformindex);
  if (!v8)
    return 0;
LABEL_11:
  if ((v8->badstatus & 0xFFF) != 0x400)
    return 0;
  if ((tbl->m_Items[nskill]->skillattr | 4) != 4)
    return 0;
  Param = datGetParam(v7, 5);
  LOWORD(v14) = v7->level;
  v15 = 20.0;
  v16 = Param / ((v14 + 20.0) / -5.0);
  if ((v7->flag & 4) != 0)
    v15 = 40.0;
  if (((v16 * v15) + 100.0) <= 20)
    v17 = 20;
  else
    v17 = ((v16 * v15) + 100.0);
  v22 = v17;
  v19 = sub_8D3950(s32, &v22);
  Write_2930400("石化一撃確率 ={0:D}\n", v19);
  return v17 > dds3GetRandIntA(0x64u, "nbCheckStoneDead");
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
  datUnitWork_t_o *UnitWorkFromFormindex;
  nbParty_t_o *PartyFromFormindex;
  struct System_UInt32_array *aisyo;
  u32 v14;
  nbParty_t_o *v15;
  struct System_Int16_array *count;
  s32 v19;
  u32 flag;
  s32 v21;
  u32 v22;
  s32 v23;
  nbParty_t_o *v24;
  struct System_Int16_array *v25;
  nbParty_t_o *v27;
  struct System_Int16_array *v28;
  nbParty_t_o *v30;
  struct System_Int16_array *v31;
  nbParty_t_o *v33;
  struct System_Int16_array *v34;
  struct datNormalSkill_t_array *tbl;
  nbParty_t_o *v39;
  struct System_Int16_array *v40;
  nbParty_t_o *v42;
  struct System_Int16_array *v43;
  s32 v45;
  struct datSpecialSkill_t_array *v51;
  datSpecialSkill_t_o *v53;
  struct datSpecialSkill_t_array *v59;
  struct datSpecialSkill_t_array *v66;
  struct datSpecialSkill_t_array *v73;
  struct datSpecialSkill_t_array *v80;
  struct datSpecialSkill_t_array *v85;
  struct datSpecialSkill_t_array *v90;
  struct datSpecialSkill_t_array *v95;
  struct datSpecialSkill_t_array *v100;
  struct datSpecialSkill_t_array *v105;
  s64 v107;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  if (formindex < 16)
  {
    PartyFromFormindex = nbGetPartyFromFormindex(formindex);
    if (attr == -1)
      return 0;
    if ((attr & 0xFFFFFFFC) == 0xC)
      return 100;
    aisyo = PartyFromFormindex->aisyo;
    v14 = aisyo->m_Items[attr];
    v15 = nbGetPartyFromFormindex(formindex);
    if (v15)
    {
      count = v15->count;
      v19 = count->m_Items[19];
      if (v19 >= 1)
      {
        flag = UnitWorkFromFormindex->flag;
        v14 = Get(v19, attr, flag, 0);
      }
    }
    v21 = UnitWorkFromFormindex->badstatus & 0xFFF;
    if (v21 == 512)
    {
      v22 = UnitWorkFromFormindex->flag;
      v23 = 247;
    }
    else
    {
      if (v21 != 1024)
        goto LABEL_44;
      v22 = UnitWorkFromFormindex->flag;
      v23 = 246;
    }
    v14 = Get(v23, attr, v22, 0);
LABEL_44:
    switch (attr)
    {
      case 1:
        v24 = nbGetPartyFromFormindex(formindex);
        if (v24)
        {
          v25 = v24->count;
          if (v25->m_Items[10] > 0)
            goto LABEL_84;
        }
        break;
      case 2:
        v27 = nbGetPartyFromFormindex(formindex);
        if (v27)
        {
          v28 = v27->count;
          if (v28->m_Items[9] > 0)
            goto LABEL_84;
        }
        break;
      case 6:
        v30 = nbGetPartyFromFormindex(formindex);
        if (v30)
        {
          v31 = v30->count;
          if (v31->m_Items[12] > 0)
            goto LABEL_84;
        }
        break;
      case 7:
        v33 = nbGetPartyFromFormindex(formindex);
        if (v33)
        {
          v34 = v33->count;
          if (v34->m_Items[11] > 0)
LABEL_84:
            v14 |= 0x10000u;
        }
        break;
      default:
        break;
    }
    if (nskill < 0 || attr == 5 || attr == 11)
      goto LABEL_115;
    if (tbl->m_Items[nskill]->koukatype == 1)
    {
      v42 = nbGetPartyFromFormindex(formindex);
      if (!v42)
        goto LABEL_115;
      v43 = v42->count;
      if (v43->m_Items[13] <= 0)
        goto LABEL_115;
    }
    else
    {
      if (tbl->m_Items[nskill]->koukatype)
        goto LABEL_115;
      v39 = nbGetPartyFromFormindex(formindex);
      if (!v39)
        goto LABEL_115;
      v40 = v39->count;
      if (v40->m_Items[14] <= 0)
        goto LABEL_115;
    }
    v14 |= 0x20000u;
LABEL_115:
    v45 = v14;
    switch (attr)
    {
      case 0:
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x143u))
          v14 |= 0x10000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x14Du))
          v14 |= 0x40000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x152u))
          v14 |= 0x20000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x139u))
        {
          v51 = tbl;
          v53 = v51->m_Items[25];
          goto LABEL_376;
        }
        break;
      case 1:
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x144u))
          v14 |= 0x10000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x14Eu))
          v14 |= 0x40000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x153u))
          v14 |= 0x20000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x13Au))
        {
          v59 = tbl;
          v53 = v59->m_Items[26];
          goto LABEL_376;
        }
        break;
      case 2:
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x145u))
          v14 |= 0x10000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x14Fu))
          v14 |= 0x40000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x154u))
          v14 |= 0x20000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x13Bu))
        {
          v66 = tbl;
          v53 = v66->m_Items[27];
          goto LABEL_376;
        }
        break;
      case 3:
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x146u))
          v14 |= 0x10000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x150u))
          v14 |= 0x40000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x155u))
          v14 |= 0x20000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x13Cu))
        {
          v73 = tbl;
          v53 = v73->m_Items[28];
          goto LABEL_376;
        }
        break;
      case 4:
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x147u))
          v14 |= 0x10000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x151u))
          v14 |= 0x40000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x156u))
          v14 |= 0x20000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x13Du))
        {
          v80 = tbl;
          v53 = v80->m_Items[29];
          goto LABEL_376;
        }
        break;
      case 6:
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x148u))
          v14 |= 0x10000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x13Eu))
        {
          v85 = tbl;
          v53 = v85->m_Items[30];
          goto LABEL_376;
        }
        break;
      case 7:
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x149u))
          v14 |= 0x10000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x13Fu))
        {
          v90 = tbl;
          v53 = v90->m_Items[31];
          goto LABEL_376;
        }
        break;
      case 8:
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x14Au))
          v14 |= 0x10000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x140u))
        {
          v95 = tbl;
          v53 = v95->m_Items[32];
          goto LABEL_376;
        }
        break;
      case 9:
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x14Bu))
          v14 |= 0x10000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x141u))
        {
          v100 = tbl;
          v53 = v100->m_Items[33];
          goto LABEL_376;
        }
        break;
      case 10:
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x14Cu))
          v14 |= 0x10000u;
        if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x142u))
        {
          v105 = tbl;
          v53 = v105->m_Items[34];
LABEL_376:
          v107 = 1374389535LL * v45 * v53->n;
          v45 = (v107 >> 37) + (v107 >> 63);
        }
        break;
      default:
        return v14 & 0xFFFF0000 | v45;
    }
    return v14 & 0xFFFF0000 | v45;
  }
  return datGetAisyo(UnitWorkFromFormindex, attr);
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
      goto LABEL_43;
    if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x169u))
    {
LABEL_43:
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
      goto LABEL_87;
    case 3:
      v33 = 311;
      goto LABEL_87;
    case 4:
      v33 = 312;
LABEL_87:
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
      goto LABEL_14;
LABEL_13:
    goto LABEL_14;
  }
  id = UnitWorkFromFormindex->id;
  aisyoid = Get(id, 1, 0)->aisyoid;
  if ((byte_3F5869F & 1) == 0)
    goto LABEL_13;
LABEL_14:
  else
  {
    PartyFromFormindex = nbGetPartyFromFormindex(formindex);
    if (!PartyFromFormindex)
      goto LABEL_23;
  }
  count = PartyFromFormindex->count;
  v9 = count->m_Items[19];
  if (v9 <= 0)
  {
LABEL_23:
    v9 = aisyoid;
    v10 = UnitWorkFromFormindex->badstatus & 0xFFF;
    if (v10 == 512)
      return 247;
    goto LABEL_24;
  }
  v10 = UnitWorkFromFormindex->badstatus & 0xFFF;
  if (v10 == 512)
    return 247;
LABEL_24:
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
LABEL_6:
      LODWORD(UnitWorkFromFormindex) = UnitWorkFromFormindex->badstatus & 0xFFF;
  }
  return UnitWorkFromFormindex;
}

// 0xfb1cc0
s32 nbGetButuriAttack(s32 nskill, s32 sformindex, s32 dformindex, s32 waza) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v10;
  f32 HojoRitu;
  f32 v15;
  u32 level;
  s32 v18;
  f32 v19;
  s32 Param;
  u32 v22;
  f32 v23;
  s32 v24;
  s32 v25;
  f32 v26;
  f32 v27;
  s32 Bit;
  u64 *v30;
  u64 *v31;
  f32 v33;
  f32 v34;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(sformindex);
  v10 = nbGetUnitWorkFromFormindex(dformindex);
  HojoRitu = nbGetHojoRitu(sformindex, 4);
  v15 = nbGetHojoRitu(dformindex, 7);
  datGetNormalAtkPow(UnitWorkFromFormindex);
  datGetDefPow(v10);
  level = UnitWorkFromFormindex->level;
  if ((UnitWorkFromFormindex->flag & 0x20) != 0)
  {
    if (nskill)
    {
      Param = datGetParam(UnitWorkFromFormindex, 0);
      v22 = 50;
      v23 = (((level + level) + (Param + Param)) * waza) / 23.2;
    }
    else
    {
      v25 = datGetParam(UnitWorkFromFormindex, 0);
      v22 = 48;
      v23 = ((level + level) + (v25 + v25)) * 1.33;
    }
    v26 = (v22 / (UnitWorkFromFormindex->level + 10));
    v27 = v23 * 0.6;
    v19 = v27 - v26;
    Bit = cfgGetBit(9u);
    if (Bit == 3)
    {
      if (evtBitCheck(2208))
        v19 = v19 * 1.34;
    }
    else if (Bit == 2)
    {
      v19 = v19 * 1.34;
    }
  }
  else if (nskill)
  {
    v18 = datGetParam(UnitWorkFromFormindex, 0);
    v19 = ((((level + level) + (v18 + v18)) * waza) / 23.2) * 0.8;
  }
  else
  {
    v24 = datGetParam(UnitWorkFromFormindex, 0);
    v19 = (((level + level) + (v24 + v24)) * 1.33) * 0.8;
  }
  v34 = HojoRitu;
  v30 = sub_8D3950(f32, &v34);
  Write_2930400("atkritu = {0:f}\n", v30);
  v33 = v15;
  v31 = sub_8D3950(f32, &v33);
  Write_2930400("defritu = {0:f}\n", v31);
  return (v15 * (HojoRitu * v19));
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
LABEL_7:
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
          goto LABEL_21;
        goto LABEL_22;
      }
      v14 = data->item;
      if (v14->m_Items[1] == item)
      {
        v10 = 1;
        v11 = data->itemcnt;
        if (LODWORD(v11->max_length) > 1)
        {
LABEL_22:
          v11->m_Items[v10] += itemcnt;
          return;
        }
LABEL_21:
      }
      v16 = data->item;
      if (v16->m_Items[2] == item)
      {
        v10 = 2;
        v11 = data->itemcnt;
        if (LODWORD(v11->max_length) > 2)
          goto LABEL_22;
        goto LABEL_21;
      }
      v18 = data->item;
      if (v18->m_Items[3] == item)
      {
        v10 = 3;
        v11 = data->itemcnt;
        if (LODWORD(v11->max_length) > 3)
          goto LABEL_22;
        goto LABEL_21;
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
            if (LODWORD(v47->max_length) <= 3)
            {
LABEL_80:
            }
          }
          else
          {
            v46 = 2;
            v47 = data->item;
            if (LODWORD(v47->max_length) <= 2)
              goto LABEL_80;
          }
        }
        else
        {
          v46 = 1;
          v47 = data->item;
          if (LODWORD(v47->max_length) <= 1)
            goto LABEL_80;
        }
      }
      else
      {
        v46 = 0;
        v47 = data->item;
        if (!LODWORD(v47->max_length))
          goto LABEL_80;
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
      goto LABEL_21;
LABEL_19:
    v16 = 1.3;
    goto LABEL_20;
  }
  if (v15 < 6)
    goto LABEL_21;
  if (v15 <= 11)
    goto LABEL_19;
  v16 = 1.8;
LABEL_20:
  dropexp = (dropexp / v16);
LABEL_21:
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
    goto LABEL_39;
  if (dds3GetRandIntA(0x64u, "nbGetExpMakaItem0") >= v11->specialpoint
    || (specialitem = v11->specialitem) == 0)
  {
LABEL_39:
    v25 = 32;
    do
    {
      dropitem = v11->dropitem;
      v27 = v25 - 32;
      if (!*(&dropitem->obj.klass + v25))
        goto LABEL_54;
      RandIntA = dds3GetRandIntA(0x64u, "nbGetExpMakaItem1");
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
LABEL_54:
        specialitem = 0;
        if ((v25 - 31) > 1)
          break;
      }
      ++v25;
    }
    while (!specialitem);
  }
  if (dds3GetRandIntA(0x64u, "nbGetExpMakaItem2") < v11->hougyokupoint && specialitem == 0)
    specialitem = 4;
  v36 = dds3GetRandIntA(0x64u, "nbGetExpMakaItem") < v11->masekipoint && specialitem == 0;
  v37 = v36 ? 3 : specialitem;
  if (!v37)
    return;
  item = MainProcessData->item;
  if (v37 == item->m_Items[0])
  {
    v39 = 0;
    itemcnt = MainProcessData->itemcnt;
    if (!LODWORD(itemcnt->max_length))
      goto LABEL_76;
    goto LABEL_77;
  }
  v45 = MainProcessData->item;
  if (v37 == v45->m_Items[1])
  {
    v39 = 1;
    itemcnt = MainProcessData->itemcnt;
    if (LODWORD(itemcnt->max_length) > 1)
    {
LABEL_77:
      v42 = itemcnt + v39;
      v43 = itemcnt->m_Items[v39] + 1;
LABEL_78:
      v42[32] = v43;
      return;
    }
LABEL_76:
  }
  v47 = MainProcessData->item;
  if (v37 == v47->m_Items[2])
  {
    v39 = 2;
    itemcnt = MainProcessData->itemcnt;
    if (LODWORD(itemcnt->max_length) > 2)
      goto LABEL_77;
    goto LABEL_76;
  }
  v49 = MainProcessData->item;
  if (v37 == v49->m_Items[3])
  {
    v39 = 3;
    itemcnt = MainProcessData->itemcnt;
    if (LODWORD(itemcnt->max_length) > 3)
      goto LABEL_77;
    goto LABEL_76;
  }
  v51 = MainProcessData->item;
  if (!v51->m_Items[0])
  {
    v59 = 0;
    v60 = MainProcessData->item;
    if (!LODWORD(v60->max_length))
      goto LABEL_111;
    goto LABEL_112;
  }
  v53 = MainProcessData->item;
  if (!v53->m_Items[1])
  {
    v59 = 1;
    v60 = MainProcessData->item;
    if (LODWORD(v60->max_length) > 1)
      goto LABEL_112;
    goto LABEL_111;
  }
  v55 = MainProcessData->item;
  if (!v55->m_Items[2])
  {
    v59 = 2;
    v60 = MainProcessData->item;
    if (LODWORD(v60->max_length) <= 2)
      goto LABEL_111;
LABEL_112:
    v60->m_Items[v59] = v37;
    v62 = MainProcessData->itemcnt;
    v42 = v62 + v59;
    v43 = 1;
    goto LABEL_78;
  }
  v57 = MainProcessData->item;
  if (!v57->m_Items[3])
  {
    v59 = 3;
    v60 = MainProcessData->item;
    if (LODWORD(v60->max_length) > 3)
      goto LABEL_112;
LABEL_111:
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
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v12;
  struct datSkill_t_array *tbl;
  s32 skillattr;
  u32 Aisyo;
  u32 v22;
  s32 v24;
  f32 v25;
  s32 v26;
  struct nbFormation_t_array *form;
  s32 Bit;
  s32 v31;
  int16x4_t v32;
  struct datSpecialSkill_t_array *v34;
  datSpecialSkill_t_o *v36;
  struct datNormalSkill_t_array *v38;
  f32 v40;
  f32 v41;
  f32 v43;
  s16 Failpoint;
  int16x4_t v47;
  struct datNormalSkill_t_array *v49;
  f32 v50;
  f32 v53;
  struct datNormalSkill_t_array *v54;
  f32 v55;
  u64 *v57;
  u64 *v58;
  u64 *v60;
  s32 v62;
  s32 v63;
  s16 criticalpoint;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(sformindex);
  v12 = nbGetUnitWorkFromFormindex(dformindex);
  skillattr = tbl->m_Items[nskill]->skillattr;
  if (skillattr == -1 || (skillattr & 0xFFFFFFFC) == 12)
    return 0;
  Aisyo = nbGetAisyo(nskill, dformindex, skillattr);
  v22 = Aisyo;
  if (!nskill)
  {
    v26 = 300;
    if (nbHatudoCheckSkill(UnitWorkFromFormindex, 300)
      || (v26 = 301, nbHatudoCheckSkill(UnitWorkFromFormindex, 301)))
    {
      ad->autoskill = v26;
      return 1;
    }
  }
  if ((v22 & 0x80000000) == 0)
  {
    if ((nbGetPartyFromFormindex(sformindex)->flag & 0x100) != 0)
      return 1;
    v24 = v12->badstatus & 0xFFF;
    if ((v24 - 1) < 2)
    {
      v25 = 100.0;
    }
    else if (v24 == 16 || v24 == 4)
    {
      v25 = 8.0;
    }
    else
    {
      v25 = 1.0;
    }
    form = ad->data->form;
    if ((form->m_Items[dformindex]->stat & 0x2000) != 0)
    {
      Bit = cfgGetBit(9u);
      if (Bit == 3 || Bit == 2)
      {
        v25 = 100.0;
      }
      else if (!Bit)
      {
        v25 = v25 * 0.7;
        if (nskill)
          goto LABEL_49;
        goto LABEL_50;
      }
    }
    if (nskill)
      goto LABEL_49;
LABEL_50:
    if (datCheckSyojiSkill(UnitWorkFromFormindex, 0x12Bu))
    {
      v34 = tbl;
      v36 = v34->m_Items[11];
      v31 = 1;
      v32.n64_u16[0] = v36->n;
      v25 = v25 * (vmovl_s16(v32).n128_i32[0] / 100.0);
LABEL_62:
      v38 = tbl;
      if (!v38->m_Items[nskill]->koukatype)
      {
        v40 = (100 * (datGetParam(UnitWorkFromFormindex, 4) / (UnitWorkFromFormindex->level / 5u + 3)));
        v41 = (100 * (datGetParam(v12, 4) / (v12->level / 5u + 3)));
        v43 = ((v40 - v41) * 0.0625) + (100 - GetFailpoint(nskill));
        Failpoint = GetFailpoint(nskill);
        v49 = tbl;
        v50 = fmaxf(v43, 50.0);
        v47.n64_u16[0] = v49->m_Items[nskill]->criticalpoint;
        v53 = (v50 / (100 - Failpoint)) * vmovl_s16(v47).n128_i32[0];
        v54 = tbl;
        v55 = v25 * v53;
        criticalpoint = v54->m_Items[nskill]->criticalpoint;
        v63 = v50;
        v57 = sub_8D3950(s16, &criticalpoint);
        v58 = sub_8D3950(s32, &v63);
        v62 = v55;
        v60 = sub_8D3950(s32, &v62);
        Write_2930912("critical p:{0:D}, z = {1:D}, a = {2:D}\n", v57, v58, v60, 0);
        if (dds3GetRandIntA(0x64u, "nbGetHitType") < v55)
        {
          if (v31)
            ad->autoskill = 299;
          return 1;
        }
      }
      return 0;
    }
LABEL_49:
    v31 = 0;
    goto LABEL_62;
  }
  return 2;
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
    goto LABEL_24;
LABEL_11:
  count = PartyFromFormindex->count;
  v11 = count->m_Items[type];
  if (UnitWorkFromFormindex->id != 293)
    goto LABEL_25;
LABEL_14:
  AgeOfMoon = evtGetAgeOfMoon();
  v13 = AgeOfMoon - 4;
  if (AgeOfMoon - 4 < 0)
    v13 = AgeOfMoon - 3;
  v11 += v13 >> 1;
  if ((type & 0xFFFFFFFE) != 6)
  {
LABEL_20:
    if (v11 < 0)
    {
      v20 = v11;
      goto LABEL_43;
    }
    if (v11)
    {
      v14 = 2 * v11;
LABEL_42:
      v20 = v14;
LABEL_43:
      v15 = (v20 + 8.0) * 0.125;
      if (type != 4)
        return v15;
      goto LABEL_30;
    }
    goto LABEL_29;
  }
LABEL_26:
  if (v11 < 0)
  {
    v14 = -2 * v11;
    goto LABEL_42;
  }
  if (v11)
  {
    v14 = -v11;
    goto LABEL_42;
  }
LABEL_29:
  v15 = 1.0;
  if (type != 4)
    return v15;
LABEL_30:
  v16 = nbGetPartyFromFormindex(formindex);
  if (!v16)
    return v15;
LABEL_35:
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
  u64 *v12;
  nbMainProcessData_t_o *MainProcessData;
  struct datNormalSkill_t_array *tbl;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct datNormalSkill_t_array *v21;
  signed s32 v23;
  s32 v24;
  u16 basstatus;
  datUnitWork_t_o *v27;
  struct datNormalSkill_t_array *v28;
  s64 v30;
  char *v32;
  char *v34;
  char *v36;
  char *v38;
  char *v40;
  char *v42;
  char *v44;
  char *v46;
  char *v48;
  char *v50;
  char *v52;
  char *v54;
  char *v56;
  u32 RandIntA;
  s32 BadStatusAttr;
  u32 Aisyo;
  s64 *v66;
  struct datNormalSkill_t_array *v68;
  struct datNormalSkill_t_array *v71;
  u32 badlevel;
  f32 v74;
  s32 Bit;
  f32 v76;
  signed s32 v77;
  System_Object_array *v78;
  s64 *v79;
  s64 *v80;
  s64 *v83;
  s64 *v84;
  s64 *v87;
  s64 *v88;
  s64 *v91;
  s64 *v93;
  datUnitWork_t_o *v96;
  signed s32 v97;
  s32 v98;
  s32 v99;
  u32 v100;

  v12 = NewSpecific(s32, 0x10u);
  MainProcessData = nbGetMainProcessData();
  if ((tbl->m_Items[nskill]->badtype | 2) != 3)
    return 0;
  nbGetUnitWorkFromFormindex(sformindex);
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(dformindex);
  v21 = tbl;
  if (nskill != 272)
  {
    basstatus = v21->m_Items[nskill]->basstatus;
    else
    {
      v27 = UnitWorkFromFormindex;
    }
    v28 = tbl;
    v24 = basstatus & 0x7FFF;
    if (v28->m_Items[nskill]->badtype != 3)
      goto LABEL_101;
    if ((v24 & 1) != 0)
    {
      v30 = 1;
      *(v12 + 8) = 0;
      if ((v24 & 2) != 0)
      {
LABEL_39:
        v32 = v12 + 4 * v30;
        v30 = (v30 + 1);
        *(v32 + 8) = 1;
        if ((v24 & 4) != 0)
        {
LABEL_42:
          v34 = v12 + 4 * v30;
          v30 = (v30 + 1);
          *(v34 + 8) = 2;
          if ((v24 & 8) != 0)
          {
LABEL_45:
            v36 = v12 + 4 * v30;
            v30 = (v30 + 1);
            *(v36 + 8) = 3;
            if ((v24 & 0x10) != 0)
            {
LABEL_48:
              v38 = v12 + 4 * v30;
              v30 = (v30 + 1);
              *(v38 + 8) = 4;
              if ((v24 & 0x20) != 0)
              {
LABEL_51:
                v40 = v12 + 4 * v30;
                v30 = (v30 + 1);
                *(v40 + 8) = 5;
                if ((v24 & 0x40) != 0)
                {
LABEL_54:
                  v42 = v12 + 4 * v30;
                  v30 = (v30 + 1);
                  *(v42 + 8) = 6;
                  if ((v24 & 0x80) != 0)
                  {
LABEL_57:
                    v44 = v12 + 4 * v30;
                    v30 = (v30 + 1);
                    *(v44 + 8) = 7;
                    if ((v24 & 0x100) != 0)
                    {
LABEL_60:
                      v46 = v12 + 4 * v30;
                      v30 = (v30 + 1);
                      *(v46 + 8) = 8;
                      if ((v24 & 0x200) != 0)
                      {
LABEL_63:
                        v48 = v12 + 4 * v30;
                        v30 = (v30 + 1);
                        *(v48 + 8) = 9;
                        if ((v24 & 0x400) != 0)
                        {
LABEL_66:
                          v50 = v12 + 4 * v30;
                          v30 = (v30 + 1);
                          *(v50 + 8) = 10;
                          if ((v24 & 0x800) != 0)
                          {
LABEL_69:
                            v52 = v12 + 4 * v30;
                            v30 = (v30 + 1);
                            *(v52 + 8) = 11;
                            if ((v24 & 0x1000) != 0)
                            {
LABEL_72:
                              v54 = v12 + 4 * v30;
                              v30 = (v30 + 1);
                              *(v54 + 8) = 12;
                              if ((v24 & 0x2000) == 0)
                                goto LABEL_95;
                              goto LABEL_75;
                            }
LABEL_94:
                            if ((v24 & 0x2000) == 0)
                            {
LABEL_95:
                              {
                              }
                              RandIntA = dds3GetRandIntA(v30, "nbGetKoukaBadDamage3");
                              v24 = 1 << *(v12 + RandIntA + 8);
LABEL_101:
                              UnitWorkFromFormindex = v27;
                              goto LABEL_102;
                            }
LABEL_75:
                            v56 = v12 + 4 * v30;
                            LODWORD(v30) = v30 + 1;
                            *(v56 + 8) = 13;
                            goto LABEL_95;
                          }
LABEL_93:
                          if ((v24 & 0x1000) != 0)
                            goto LABEL_72;
                          goto LABEL_94;
                        }
LABEL_92:
                        if ((v24 & 0x800) != 0)
                          goto LABEL_69;
                        goto LABEL_93;
                      }
LABEL_91:
                      if ((v24 & 0x400) != 0)
                        goto LABEL_66;
                      goto LABEL_92;
                    }
LABEL_90:
                    if ((v24 & 0x200) != 0)
                      goto LABEL_63;
                    goto LABEL_91;
                  }
LABEL_89:
                  if ((v24 & 0x100) != 0)
                    goto LABEL_60;
                  goto LABEL_90;
                }
LABEL_88:
                if ((v24 & 0x80) != 0)
                  goto LABEL_57;
                goto LABEL_89;
              }
LABEL_87:
              if ((v24 & 0x40) != 0)
                goto LABEL_54;
              goto LABEL_88;
            }
LABEL_86:
            if ((v24 & 0x20) != 0)
              goto LABEL_51;
            goto LABEL_87;
          }
LABEL_85:
          if ((v24 & 0x10) != 0)
            goto LABEL_48;
          goto LABEL_86;
        }
LABEL_84:
        if ((v24 & 8) != 0)
          goto LABEL_45;
        goto LABEL_85;
      }
    }
    else
    {
      v30 = 0;
      if ((v24 & 2) != 0)
        goto LABEL_39;
    }
    if ((v24 & 4) != 0)
      goto LABEL_42;
    goto LABEL_84;
  }
  v23 = dds3GetRandIntA(0x64u, "nbGetKoukaBadDamage2");
  if (v23 < 40)
  {
    v24 = 4096;
  }
  else if (v23 < 60)
  {
    v24 = 0x2000;
  }
  else if (v23 < 70)
  {
    v24 = 0x4000;
  }
  else if (v23 < 80)
  {
    v24 = 32;
  }
  else if (v23 <= 89)
  {
    v24 = 256;
  }
  else
  {
    v24 = 64;
  }
LABEL_102:
  BadStatusAttr = datGetBadStatusAttr(v24);
  Aisyo = nbGetAisyo(nskill, dformindex, BadStatusAttr);
  if ((Aisyo & 0x170000) != 0)
    return 0;
  if (v24 != 2048)
    ai = Aisyo / 100.0;
  if ((nskill - 259) < 2)
  {
    if ((nbGetAisyo(-1, dformindex, 7) & 0x70000) != 0)
    {
      v66 = &"SIBAE JYUSATU TAISEI ARI NG...\n";
      goto LABEL_130;
    }
  }
  else if (nskill == 79)
  {
    if ((UnitWorkFromFormindex->badstatus & 0x40) == 0)
    {
      v66 = &"PESTO POISON NASI NG...\n";
      goto LABEL_130;
    }
  }
  else if (nskill == 266 && (MainProcessData->stat & 1) != 0 && (UnitWorkFromFormindex->flag & 0x20) != 0)
  {
    v66 = &"DANTE SUTING BOSS NG...\n";
LABEL_130:
    Write(*v66, 0);
    return 0;
  }
  v68 = tbl;
  if (!nvirtual && v68->m_Items[nskill]->badlevel != 255)
  {
    v71 = tbl;
    badlevel = v71->m_Items[nskill]->badlevel;
    v74 = (ai * (badlevel / 100.0)) * 100.0;
    if ((UnitWorkFromFormindex->flag & 0x20) == 0)
    {
      Bit = cfgGetBit(9u);
      if (v24 == 2048)
      {
        switch (Bit)
        {
          case 0:
            if ((UnitWorkFromFormindex->flag & 4) != 0)
            {
              v76 = 0.25;
              goto LABEL_166;
            }
            goto LABEL_161;
          case 3:
          case 2:
            if ((UnitWorkFromFormindex->flag & 4) != 0)
              v76 = 1.3;
            else
              v76 = 1.5;
            goto LABEL_166;
          case 1:
            if ((UnitWorkFromFormindex->flag & 4) == 0)
            {
              v76 = 0.7;
LABEL_166:
              v74 = v74 * v76;
              break;
            }
LABEL_161:
            v76 = 0.5;
            goto LABEL_166;
        }
      }
      else
      {
        if (!Bit)
          goto LABEL_161;
        if (Bit == 1)
          v74 = v74 * 0.7;
      }
    }
    v77 = dds3GetRandIntA(0x64u, "nbGetKoukaBadDamage4");
    v100 = badlevel;
    v78 = NewSpecific(object, 4u);
    v79 = sub_8D3950(s32, &v100);
    v80 = v79;
    v78->m_Items[0] = v80;
    v99 = (ai * 100.0);
    v83 = sub_8D3950(s32, &v99);
    v84 = v83;
    v78->m_Items[1] = v84;
    v98 = v74;
    v87 = sub_8D3950(s32, &v98);
    v88 = v87;
    v78->m_Items[2] = v88;
    v97 = v77;
    v91 = sub_8D3950(s32, &v97);
    v93 = v91;
    v78->m_Items[3] = v93;
    Write_2930544("バットステータス反映確率 waza:{0:D}  aisyo:{1:D}  ritu:{2:D}  rnd:{3:D}\n", v78);
    if (v77 >= v74)
      return 0;
  }
  v96 = nbGetUnitWorkFromFormindex(dformindex);
  if (v96)
  {
    if (v24 > (v96->badstatus & 0xFFF))
      return v24;
  }
  else if (v24 > 0)
  {
    return v24;
  }
  return 0;
}

// 0xfb3a20
u32 nbGetKoukaBadKaifuku(s32 nskill, s32 sformindex, s32 dformindex, f32 ai, s32 nvirtual) {
  struct datNormalSkill_t_array *tbl;
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v16;
  struct datNormalSkill_t_array *v18;
  u16 basstatus;
  struct datNormalSkill_t_array *v22;
  u32 badlevel;
  s32 Param;
  s32 v26;
  s32 v27;
  f32 v28;
  u64 *v30;
  u32 result;
  f32 v33;

  if (tbl->m_Items[nskill]->badtype != 2)
    return 0;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(sformindex);
  v16 = nbGetUnitWorkFromFormindex(dformindex);
  v18 = tbl;
  basstatus = v18->m_Items[nskill]->basstatus;
  if (!nvirtual && tbl->m_Items[nskill]->badlevel != 255)
  {
    v22 = tbl;
    badlevel = v22->m_Items[nskill]->badlevel;
    Param = datGetParam(UnitWorkFromFormindex, 2);
    v26 = datGetParam(UnitWorkFromFormindex, 5);
    v27 = datGetParam(v16, 2);
    v28 = ((badlevel * (Param + v26 / 4)) / 100.0) * ((ai * 100.0) / (v27 + datGetParam(v16, 5) / 4));
    v33 = v28;
    v30 = sub_8D3950(f32, &v33);
    Write_2930400("bad ritu:{0:f}\n", v30);
    if (dds3GetRandIntA(0x64u, "nbGetKoukaBadKaifuku") >= v28)
      return 0;
  }
  result = basstatus & 0xFFF;
  if ((basstatus & 0xFFF & v16->badstatus) == 0)
    return 0;
  return result;
}

// 0xfb1110
s32 nbGetKoukaHp(s32 sw, s32 nskill, s32 sformindex, s32 dformindex, f32 ritu, s32 cnt) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  datNormalSkill_c *v16;
  struct datNormalSkill_t_array *tbl;
  s32 v18;
  u32 hpn;
  s32 hpbase;
  struct datNormalSkill_t_array *v23;
  s32 ButuriAttack;
  s32 v26;
  s32 MagicAttack;
  s32 v28;
  s32 v30;
  s32 v31;
  datNormalSkill_c *v33;
  struct datNormalSkill_t_array *v34;
  u32 MagicKaifuku;
  signed s32 hp;
  s32 MaxHpWazaPoint;
  s32 v39;
  s32 v40;
  s32 v41;
  s32 v42;
  s32 maxhp;
  s32 v44;
  s32 v45;
  struct datNormalSkill_t_array *v46;
  struct datNormalSkill_t_array *v48;
  u32 hptype;
  struct datNormalSkill_t_array *v52;
  f32 v54;
  f32 v55;
  f32 v56;
  f32 RandFloatA;
  s32 Bit;
  f32 v59;
  f32 v60;
  s32 v61;
  struct datNormalSkill_t_array *v63;
  s32 dformindexa;
  datUnitWork_t_o *v67;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(sformindex);
  v67 = nbGetUnitWorkFromFormindex(dformindex);
  dformindexa = dformindex;
  v18 = sw;
  hpn = tbl->m_Items[nskill]->hpn;
  hpbase = tbl->m_Items[nskill]->hpbase;
  switch (tbl->m_Items[nskill]->hptype)
  {
    case 1u:
    case 0xCu:
    case 0xEu:
      v23 = tbl;
      if (v23->m_Items[nskill]->koukatype == 1)
      {
        MagicAttack = nbGetMagicAttack(nskill, sformindex, dformindexa, hpn);
        goto LABEL_70;
      }
      if (v23->m_Items[nskill]->koukatype)
      {
        MagicAttack = 0;
          goto LABEL_76;
      }
      else
      {
        ButuriAttack = nbGetButuriAttack(nskill, sformindex, dformindexa, hpn);
        v26 = UnitWorkFromFormindex->badstatus & 0xFFF;
        MagicAttack = ButuriAttack;
        if (v26 != 512)
        {
          if (v26 == 64)
          {
            if (ButuriAttack >= 0)
              v28 = ButuriAttack;
            else
              v28 = ButuriAttack + 1;
            MagicAttack = v28 >> 1;
              goto LABEL_76;
            goto LABEL_71;
          }
LABEL_70:
            goto LABEL_76;
          goto LABEL_71;
        }
        MagicAttack = ButuriAttack / 10;
          goto LABEL_76;
      }
LABEL_71:
LABEL_76:
      v46 = tbl;
      v30 = MagicAttack + hpbase;
      v31 = -1;
      if (cnt < 2 || v46->m_Items[nskill]->hptype != 14)
        goto LABEL_85;
      v31 = -1;
      v30 /= cnt;
        goto LABEL_28;
LABEL_86:
      v48 = tbl;
      hptype = v48->m_Items[nskill]->hptype;
      if (hptype > 7)
      {
        if ((hptype | 2) != 0xE)
          goto LABEL_124;
        goto LABEL_104;
      }
      if (hptype - 1 < 2)
      {
LABEL_104:
        if (v30 < 1)
          goto LABEL_124;
        goto LABEL_92;
      }
      if (v30 < 1 || (hptype & 0xFFFE) != 6)
        goto LABEL_124;
LABEL_92:
      v52 = tbl;
      if (v52->m_Items[nskill]->koukatype == 1)
      {
        RandFloatA = dds3GetRandFloatA("nbGetKoukaHp:魔法");
        v56 = v30;
        v54 = RandFloatA + -0.5;
        v55 = 0.1;
        goto LABEL_110;
      }
      if (!v52->m_Items[nskill]->koukatype)
      {
        v54 = dds3GetRandFloatA("nbGetKoukaHp:物理") + -0.5;
        v55 = 0.05;
        v56 = v30;
LABEL_110:
        v30 = ((((v54 + v54) * v55) * v56) + v56);
      }
      v30 = ((v30 & ~(v30 >> 31)) * ritu);
      Bit = cfgGetBit(9u);
      if (Bit == 1)
      {
        if (sformindex >= 4)
        {
          v59 = v30;
          v60 = 0.7;
LABEL_123:
          v30 = (v59 * v60);
        }
      }
      else if (!Bit)
      {
        v59 = v30;
        if (sformindex < 4)
        {
          if (dformindexa <= 3)
            v60 = 0.25;
          else
            v60 = 2.25;
        }
        else
        {
          v60 = 0.3;
        }
        goto LABEL_123;
      }
LABEL_124:
      if (v30)
        v61 = v30;
      else
        v61 = 1;
      if (!v18)
        return v31;
      v63 = tbl;
      v31 = v61;
      if ((v63->m_Items[nskill]->hptype & 0xFFFE) != 0xC)
        return v31;
      if (v61 <= v67->maxhp)
        return v61;
      return v67->maxhp;
    case 2u:
      v34 = tbl;
      if (v34->m_Items[nskill]->koukatype == 1)
      {
        MagicKaifuku = nbGetMagicKaifuku(v33, sformindex, dformindexa, hpn);
      }
      else if (v34->m_Items[nskill]->koukatype)
      {
        MagicKaifuku = 0;
      }
      else
      {
        MagicKaifuku = nbGetButuriAttack(nskill, sformindex, dformindexa, hpn);
      }
      goto LABEL_84;
    case 3u:
      hp = v67->hp;
      if ((hpbase + hpn) >= hp)
        v30 = -1;
      else
        v30 = hp - (hpbase + hpn);
      goto LABEL_57;
    case 4u:
    case 0xDu:
      v30 = hpbase + hpn;
      goto LABEL_57;
    case 5u:
      v31 = hpbase + hpn;
      v30 = -1;
        goto LABEL_86;
      goto LABEL_28;
    case 6u:
      MaxHpWazaPoint = nbGetMaxHpWazaPoint(v16, sformindex, dformindexa, hpn);
      v39 = UnitWorkFromFormindex->badstatus & 0xFFF;
      if (MaxHpWazaPoint >= 0)
        v40 = MaxHpWazaPoint;
      else
        v40 = MaxHpWazaPoint + 1;
      v41 = v40 >> 1;
      if (v39 != 64)
        v41 = MaxHpWazaPoint;
      if (v39 == 512)
        v42 = MaxHpWazaPoint / 10;
      else
        v42 = v41;
      goto LABEL_56;
    case 7u:
      MagicKaifuku = nbGetMaxHpWazaPoint(v16, sformindex, dformindexa, hpn);
      goto LABEL_84;
    case 8u:
      maxhp = v67->hp;
      goto LABEL_55;
    case 9u:
      v44 = v67->hp;
      goto LABEL_60;
    case 0xAu:
      maxhp = v67->maxhp;
LABEL_55:
      v42 = (maxhp * hpn) / 100;
LABEL_56:
      v30 = v42 + hpbase;
LABEL_57:
      v31 = -1;
        goto LABEL_86;
      goto LABEL_28;
    case 0xBu:
      v44 = v67->maxhp;
LABEL_60:
      v45 = (v44 * hpn) / 100 + hpbase;
      if (v45 <= 1)
        v31 = 1;
      else
        v31 = v45;
      v30 = -1;
        goto LABEL_86;
      goto LABEL_28;
    case 0xFu:
      MagicKaifuku = dds3GetRandIntA(hpn, "nbGetKoukaHp");
LABEL_84:
      v31 = MagicKaifuku + hpbase;
      v30 = -1;
LABEL_85:
        goto LABEL_86;
      goto LABEL_28;
    default:
      v31 = -1;
      v30 = -1;
      {
LABEL_28:
      }
      goto LABEL_86;
  }
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
          goto LABEL_57;
      }
      else if (v21->m_Items[nskill]->koukatype)
      {
        MagicAttack = 0;
          goto LABEL_57;
      }
      else
      {
        MagicAttack = nbGetButuriAttack(nskill, sformindex, dformindex, mpn);
          goto LABEL_57;
      }
LABEL_57:
      v25 = MagicAttack + mpbase;
      v36 = tbl;
      v26 = -1;
      if (cnt < 2 || v36->m_Items[nskill]->mptype != 14)
        goto LABEL_71;
      v26 = -1;
      v25 /= cnt;
        goto LABEL_72;
LABEL_74:
      v38 = tbl;
      mptype = v38->m_Items[nskill]->mptype;
      if (mptype > 7)
      {
        if ((mptype | 2) != 0xE)
          goto LABEL_112;
LABEL_92:
        if (v25 < 1)
          goto LABEL_112;
        goto LABEL_80;
      }
      if (mptype - 1 < 2)
        goto LABEL_92;
      if (v25 < 1 || (mptype & 0xFFFE) != 6)
        goto LABEL_112;
LABEL_80:
      v42 = tbl;
      if (v42->m_Items[nskill]->koukatype == 1)
      {
        v44 = &"nbGetKoukaMp:魔法";
      }
      else
      {
        if (v42->m_Items[nskill]->koukatype)
          goto LABEL_99;
        v44 = &"nbGetKoukaMp:物理";
      }
      RandFloatA = dds3GetRandFloatA(*v44);
      v25 = (((((RandFloatA + -0.5) + (RandFloatA + -0.5)) * 0.05) * v25) + v25);
LABEL_99:
      v25 = ((v25 & ~(v25 >> 31)) * ritu);
      Bit = cfgGetBit(9u);
      if (Bit == 1)
      {
        if (sformindex < 4)
          goto LABEL_112;
        v47 = v25;
        v48 = 0.7;
      }
      else
      {
        if (Bit)
          goto LABEL_112;
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
LABEL_112:
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
      goto LABEL_70;
    case 3u:
      mp = UnitWorkFromFormindex->mp;
      if ((mpbase + mpn) >= mp)
        v25 = -1;
      else
        v25 = mp - (mpbase + mpn);
      goto LABEL_43;
    case 4u:
    case 0xDu:
      v25 = mpbase + mpn;
      goto LABEL_43;
    case 5u:
      v26 = mpbase + mpn;
      v25 = -1;
        goto LABEL_74;
      goto LABEL_72;
    case 6u:
      v25 = nbGetMaxHpWazaPoint(v15, sformindex, dformindex, mpn) + mpbase;
      goto LABEL_43;
    case 7u:
      MagicKaifuku = nbGetMaxHpWazaPoint(v15, sformindex, dformindex, mpn);
      goto LABEL_70;
    case 8u:
      maxmp = UnitWorkFromFormindex->mp;
      goto LABEL_42;
    case 9u:
      v34 = UnitWorkFromFormindex->mp;
      goto LABEL_46;
    case 0xAu:
      maxmp = UnitWorkFromFormindex->maxmp;
LABEL_42:
      v25 = (maxmp * mpn) / 100 + mpbase;
LABEL_43:
      v26 = -1;
        goto LABEL_74;
      goto LABEL_72;
    case 0xBu:
      v34 = UnitWorkFromFormindex->maxmp;
LABEL_46:
      v26 = (v34 * mpn) / 100 + mpbase;
      v25 = -1;
        goto LABEL_74;
      goto LABEL_72;
    case 0xFu:
      MagicKaifuku = dds3GetRandIntA(mpn, "nbGetKoukaMp");
LABEL_70:
      v26 = MagicKaifuku + mpbase;
      v25 = -1;
LABEL_71:
        goto LABEL_72;
      goto LABEL_74;
    default:
      v26 = -1;
      v25 = -1;
        goto LABEL_74;
LABEL_72:
      goto LABEL_74;
  }
}

// 0xfafc90
s32 nbGetKoukaType(s32 nskill, s32 sformindex, s32 dformindex) {
  nbMainProcessData_t_o *MainProcessData;
  struct datNormalSkill_t_array *tbl;
  u32 v12;
  datUnitWork_t_o *UnitWorkFromFormindex;
  datUnitWork_t_o *v14;
  s16 DevilFormatFlag;
  s64 v17;
  u32 stat;
  s32 result;
  struct datSkill_t_array *v22;
  s32 skillattr;
  u32 Aisyo;
  struct datNormalSkill_t_array *v28;
  struct datNormalSkill_t_array *v31;
  struct datNormalSkill_t_array *v34;
  struct nbFormation_t_array *form;
  struct datNormalSkill_t_array *v39;
  u32 program;
  u16 badstatus;
  u32 v43;
  s32 v44;
  u32 v46;
  struct datNormalSkill_t_array *v48;
  struct datNormalSkill_t_array *v51;
  f32 v53;
  f32 v54;
  u32 Bit;
  struct datNormalSkill_t_array *v59;
  struct datNormalSkill_t_array *v62;
  f32 v64;
  f32 HojoRitu;
  f32 v68;
  f32 v70;
  struct datNormalSkill_t_array *v71;
  f32 v73;
  f32 v74;
  f32 v77;
  f32 v78;
  f32 v79;
  datUnitWork_t_o *v80;
  s32 v81;
  u64 *v83;
  s64 *v85;
  f32 v86;
  s32 SakePow;
  f32 v89;
  f32 v90;
  f32 v91;
  datUnitWork_t_o *v92;
  u64 *v94;
  s16 v96;
  datUnitWork_t_o *work;
  s32 v98;
  s32 v99;

  MainProcessData = nbGetMainProcessData();
  v12 = tbl->m_Items[nskill]->program - 1;
  if (v12 < 0xE && ((0x385Fu >> v12) & 1) != 0)
    return dword_33CB9D0[v12];
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(sformindex);
  v14 = nbGetUnitWorkFromFormindex(dformindex);
  DevilFormatFlag = nbGetDevilFormatFlag(dformindex);
  stat = MainProcessData->stat;
  if ((stat & 0x40000000) != 0)
    return 1;
  if ((stat & 0x8000000) != 0)
    return 0;
  if (nskill == 159)
  {
    if ((stat & 1) != 0 && (v14->flag & 0x20) != 0)
      return 5;
  }
  else if (nskill == 158 && (stat & 1) != 0 && MainProcessData->encno != 1032 && (v14->flag & 0x20) != 0)
  {
    return 5;
  }
  v96 = DevilFormatFlag;
  v22 = tbl;
  work = UnitWorkFromFormindex;
  skillattr = v22->m_Items[nskill]->skillattr;
  if (skillattr != -1 && (skillattr - 12) >= 3)
  {
    Aisyo = nbGetAisyo(nskill, dformindex, skillattr);
    if ((v14->badstatus & 0xFFF) == 2)
    {
      v28 = tbl;
      if (!v28->m_Items[nskill]->koukatype)
        Aisyo = 0;
    }
    if ((Aisyo & 0x20000) == 0)
    {
      if (IsNOCTURNE())
      {
        if ((Aisyo & 0x40000) == 0)
        {
LABEL_50:
          if ((Aisyo & 0x10000) != 0)
            return 3;
          goto LABEL_71;
        }
      }
      else
      {
        if (datCheckSyojiSkill(work, 0x165u))
          goto LABEL_66;
        if (datCheckSyojiSkill(work, 0x169u))
        {
LABEL_66:
          v31 = tbl;
          if (!v31->m_Items[nskill]->koukatype)
          {
            if ((Aisyo & 0x50000) != 0)
              MainProcessData->d31_kantuu = 1;
            goto LABEL_71;
          }
        }
        if ((Aisyo & 0x40000) == 0)
          goto LABEL_50;
      }
      return 2;
    }
    return 1;
  }
LABEL_71:
  if ((MainProcessData->stat & 0x400) != 0 && (v14->flag & 0x20) != 0)
  {
    v34 = tbl;
    if (v34->m_Items[nskill]->targettype)
    {
      if (skillattr != 14 && MainProcessData->enemypcnt != 1)
        return 5;
    }
    else
    {
      form = MainProcessData->form;
      if ((form->m_Items[dformindex]->stat & 0x1000) != 0)
        return 11;
    }
  }
  v39 = tbl;
  program = v39->m_Items[nskill]->program;
  if (program == 15)
  {
    badstatus = v14->badstatus;
    if ((badstatus & 0xFFF) == 0x40)
      goto LABEL_98;
    return 5;
  }
  if (program == 6)
  {
    if ((v14->badstatus & 0xFFF) == 4)
      return 0;
    else
      return 5;
  }
  badstatus = v14->badstatus;
  v43 = badstatus & 0xFFF;
  if (v43 > 4)
  {
LABEL_98:
    v44 = badstatus & 0xFFF;
    result = 0;
    if (v44 == 16 || v44 == 256 || v44 == 1024)
      return result;
    goto LABEL_104;
  }
  result = 0;
  if (v43 == 4 || v43 - 1 < 2)
    return result;
LABEL_104:
  if (!nbCheckKoukaJyoken(nskill, v17, dformindex))
  {
    Write("MISS!!\n", 0);
    return 5;
  }
  v48 = tbl;
  if (v48->m_Items[nskill]->hitlevel == 255)
    return 0;
  v51 = tbl;
  LOBYTE(v46) = v51->m_Items[nskill]->hitlevel;
  v53 = v46;
  v54 = v53 * 0.01;
  Bit = cfgGetBit(9u);
  if (Bit <= 1)
  {
    v59 = tbl;
    if (v59->m_Items[nskill]->hptype == 3)
    {
      v62 = tbl;
      if (v62->m_Items[nskill]->hpn == 1 && (v14->flag & 0x20) == 0)
        v54 = v54 * 0.7;
    }
  }
  if (Bit)
  {
    if (Bit == 1 && (v14->flag & 0x20) == 0)
      v54 = v54 * 0.7;
  }
  else
  {
    if ((v14->flag & 0x20) != 0)
    {
      v64 = 2.5;
    }
    else if ((work->flag & 0x20) != 0)
    {
      v64 = 0.4;
    }
    else
    {
      v64 = 0.25;
    }
    v54 = v54 * v64;
  }
  HojoRitu = nbGetHojoRitu(sformindex, 8);
  v68 = nbGetHojoRitu(dformindex, 6);
  v70 = v68;
  v71 = tbl;
  if (v71->m_Items[nskill]->koukatype == 1)
  {
    if ((work->flag & 0x20) != 0)
    {
      v86 = 95.0;
      {
LABEL_181:
        SakePow = datGetSakePow(v14);
        v89 = v54 * (v70 * (HojoRitu * (((100 - 100 * SakePow / datGetMagicHitPow(work)) * 0.5) + v86)));
        v90 = fmaxf(v89, 1.0);
        v91 = fminf(v90, 100.0);
        v92 = nbGetUnitWorkFromFormindex(sformindex);
        if (v92 && (v92->badstatus & 0xFFF) == 0x100)
          v91 = v91 * 0.25;
        v81 = v91;
        v98 = v91;
        v94 = sub_8D3950(s32, &v98);
        Write_2930400("魔法ヒット率 = {0:D}\n", v94);
        v85 = &"nbGetKoukaType1";
        goto LABEL_196;
      }
    }
    else
    {
      v86 = 100.0;
        goto LABEL_181;
    }
    goto LABEL_181;
  }
  if (v71->m_Items[nskill]->koukatype)
    return 0;
  v73 = (100 * (datGetParam(work, 4) / (work->level / 5u + 3)));
  v74 = (100 * (datGetParam(v14, 4) / (v14->level / 5u + 3)));
  v77 = v54 * (v70 * (HojoRitu * (((v73 - v74) * 0.0625) + (100 - GetFailpoint(nskill)))));
  v78 = fmaxf(v77, 1.0);
  v79 = fminf(v78, 100.0);
  v80 = nbGetUnitWorkFromFormindex(sformindex);
  if (v80 && (v80->badstatus & 0xFFF) == 0x100)
    v79 = v79 * 0.25;
  v81 = v79;
  v99 = v79;
  v83 = sub_8D3950(s32, &v99);
  Write_2930400("物理ヒット率 = {0:D}\n", v83);
  v85 = &"nbGetKoukaType0";
LABEL_196:
  if (dds3GetRandIntA(0x64u, *v85) < v81)
    return 0;
  if ((v96 & 0x800) != 0)
    return 5;
  else
    return 4;
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
  datUnitWork_t_o *UnitWorkFromFormindex;
  f32 HojoRitu;
  int16x4_t v14;
  u32 v16;
  struct datNormalSkill_t_array *tbl;
  Il2CppClass **v19;
  s32 v20;
  int16x4_t v21;
  f32 v22;
  int16x4_t v23;
  struct datNormalSkill_t_array *v25;
  s32 level;
  f32 v28;
  int16x4_t v30;
  s32 v31;
  u32 v32;
  struct datNormalSkill_t_array *v34;
  int16x4_t v36;
  f32 v37;
  int16x4_t v38;
  struct datNormalSkill_t_array *v40;
  s32 v42;
  f32 v43;
  f32 v44;
  f32 v45;
  f32 v46;
  s32 Bit;
  u64 *v49;
  u64 *v50;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 v55;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(sformindex);
  nbGetUnitWorkFromFormindex(dformindex);
  HojoRitu = nbGetHojoRitu(sformindex, 5);
  v14.n64_f32[0] = nbGetHojoRitu(dformindex, 7);
  v16 = v14.n64_u32[0];
  v52 = *&v16;
  v53 = HojoRitu;
  v19 = &tbl->obj.klass + nskill;
  v20 = 2 * waza;
  v14.n64_u16[0] = v19[4]->_1.castClass;
  v21.n64_u64[0] = vmovl_s16(v14).n128_u64[0];
  v21.n64_f32[0] = v21.n64_i32[0];
  v22 = ((2 * waza * UnitWorkFromFormindex->level) / 21.0) + v21.n64_f32[0];
  v21.n64_u16[0] = tbl->m_Items[nskill]->magiclimit;
  v23.n64_u64[0] = vmovl_s16(v21).n128_u64[0];
  v23.n64_f32[0] = v23.n64_i32[0];
  if (v22 > v23.n64_f32[0])
  {
    v25 = tbl;
    v23.n64_u16[0] = v25->m_Items[nskill]->magiclimit;
    v22 = vmovl_s16(v23).n128_i32[0];
  }
  if (UnitWorkFromFormindex->level >= 0xA0u)
    level = 160;
  else
    level = UnitWorkFromFormindex->level;
  v28 = (v22 + ((v22 / 100.0) * ((datGetParam(UnitWorkFromFormindex, 2) - ((level / 5.0) + 4.0)) * 2.5)))
      * 0.8;
  if (!IsNOCTURNE()
    && (UnitWorkFromFormindex->flag & 0x20) == 0
    && UnitWorkFromFormindex->level >= 0x65u)
  {
    v31 = 200 * waza;
    v32 = 100;
    do
    {
      v34 = tbl;
      v30.n64_u16[0] = v34->m_Items[nskill]->magicbase;
      v36.n64_u64[0] = vmovl_s16(v30).n128_u64[0];
      v36.n64_f32[0] = v36.n64_i32[0];
      v37 = (v31 / 21.0) + v36.n64_f32[0];
      v36.n64_u16[0] = v34->m_Items[nskill]->magiclimit;
      v38.n64_u64[0] = vmovl_s16(v36).n128_u64[0];
      v38.n64_f32[0] = v38.n64_i32[0];
      if (v37 > v38.n64_f32[0])
      {
        v40 = tbl;
        v38.n64_u16[0] = v40->m_Items[nskill]->magiclimit;
        v37 = vmovl_s16(v38).n128_i32[0];
      }
      if (v32 >= 0xA0)
        v42 = 160;
      else
        v42 = v32;
      ++v32;
      v31 += v20;
      v43 = (v37 / 100.0) * ((datGetParam(UnitWorkFromFormindex, 2) - ((v42 / 5.0) + 4.0)) * 2.5);
      v30.n64_f32[0] = (v37 + v43) * 0.8;
      if (v30.n64_f32[0] > v28)
        v28 = (v37 + v43) * 0.8;
    }
    while (v32 < UnitWorkFromFormindex->level);
  }
  if ((UnitWorkFromFormindex->flag & 0x20) != 0)
  {
    v46 = -50.0 / (UnitWorkFromFormindex->level + 10);
    v28 = (v28 * 0.75) + v46;
    Bit = cfgGetBit(9u);
    v45 = v52;
    if (Bit == 3)
    {
      v44 = v53;
      if (evtBitCheck(2208))
        v28 = v28 * 1.34;
    }
    else
    {
      v44 = v53;
      if (Bit == 2)
        v28 = v28 * 1.34;
    }
  }
  else
  {
    v45 = v52;
    v44 = v53;
  }
  v55 = v44;
  v49 = sub_8D3950(f32, &v55);
  Write_2930400("atkritu = {0:f}\n", v49);
  v54 = v45;
  v50 = sub_8D3950(f32, &v54);
  Write_2930400("defritu = {0:f}\n", v50);
  return (v45 * (v44 * v28));
}

// 0xfb1910
s32 nbGetMagicKaifuku(s32 nskill, s32 sformindex, s32 dformindex, s32 waza) {
  datUnitWork_t_o *UnitWorkFromFormindex;
  f32 HojoRitu;
  u32 RandIntA;
  s32 v14;
  f32 v15;
  u64 *v16;
  u64 *v17;
  u64 *v19;
  s32 v21;
  f32 v22;
  s32 v23;

  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(sformindex);
  nbGetUnitWorkFromFormindex(dformindex);
  HojoRitu = nbGetHojoRitu(sformindex, 5);
  RandIntA = dds3GetRandIntA(8u, "nbGetMagicKaifuku");
  v14 = RandIntA + 4 * datGetParam(UnitWorkFromFormindex, 2) + UnitWorkFromFormindex->level;
  v23 = waza;
  v15 = HojoRitu * ((v14 / 10.0) * waza);
  v22 = HojoRitu;
  v16 = sub_8D3950(s32, &v23);
  v17 = sub_8D3950(f32, &v22);
  v21 = v15;
  v19 = sub_8D3950(s32, &v21);
  Write_2930912("回復 waza = {0:D}, atkritu = {1:f} 回復値={2:D}\n", v16, v17, v19, 0);
  return v15;
}

// 0xfb8030
s32 nbGetMakaBaramaki(datUnitWork_t *w) {
  u32 v2;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  s32 maka;
  f32 v7;
  f32 v9;
  s32 v11;
  f32 v12;
  f32 RandFloatA;
  f32 v24;
  s32 v25;

  if ((w->flag & 0x20) != 0)
    goto LABEL_16;
LABEL_6:
  LOWORD(v2) = w->level;
  maka = DDS3_GBWK->maka;
  v7 = (v2 / 5.0) + 4.0;
  v9 = datGetParam(w, 5) / v7;
  if (sdfFabs(v9) >= 0.001)
  {
    v12 = (maka / 20.0) / v9;
LABEL_27:
    v11 = v12;
    goto LABEL_28;
  }
  v11 = 0;
LABEL_28:
  RandFloatA = dds3GetRandFloatA("nbGetMakaBaramaki");
  v24 = ((((RandFloatA + -0.5) + (RandFloatA + -0.5)) * 0.1) * v11) + v11;
  v25 = v24;
  if (cfgGetBit(9u) <= 1 && (w->flag & 0x20) == 0)
    v25 /= 10;
  if (v25 <= 1)
    return 1;
  else
    return v25;
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
          goto LABEL_19;
        goto LABEL_22;
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
LABEL_19:
      v15 = PartyFromFormindex->count;
      v15->m_Items[type] = v13;
    }
LABEL_22:
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
  s32 v9;
  s32 v10;
  s32 v11;
  nbParty_t_o *PartyFromFormindex;
  struct System_Int16_array *count;
  s32 v16;
  nbParty_t_o *v17;
  struct System_Int16_array *v18;
  nbParty_t_o *v20;
  struct System_Int16_array *v22;
  s32 v24;
  nbParty_t_o *v25;
  struct System_Int16_array *v26;
  nbParty_t_o *v28;
  struct System_Int16_array *v30;
  s32 v32;
  nbParty_t_o *v33;
  struct System_Int16_array *v34;
  nbParty_t_o *v36;
  struct System_Int16_array *v38;
  s32 v40;
  nbParty_t_o *v41;
  struct System_Int16_array *v42;
  nbParty_t_o *v44;
  struct System_Int16_array *v45;
  s32 v47;
  nbParty_t_o *v48;
  struct System_Int16_array *v49;
  s32 v51;
  s32 v52;
  s32 v53;
  s32 v54;
  s32 v55;
  s32 v56;
  s32 v57;
  s32 v58;
  s32 v59;
  s32 v60;
  s32 v61;
  s32 v62;
  s32 v63;
  s32 v64;
  s32 v65;
  s32 v66;
  s32 v67;
  s32 v68;
  s32 v69;
  s32 v70;
  s32 v71;
  s32 v72;
  s32 v73;
  s32 v74;
  s32 v75;
  s32 v76;
  s32 v77;
  s32 v78;
  s32 v79;
  s32 v80;
  nbParty_t_o *v81;
  struct System_Int16_array *v83;
  s32 v85;
  nbParty_t_o *v86;
  struct System_Int16_array *v87;
  nbParty_t_o *v89;
  struct System_Int16_array *v91;
  s32 v93;
  nbParty_t_o *v94;
  struct System_Int16_array *v95;
  nbParty_t_o *v97;
  struct System_Int16_array *v99;
  s32 v101;
  nbParty_t_o *v102;
  struct System_Int16_array *v103;
  nbParty_t_o *v105;
  struct System_Int16_array *v107;
  s32 v109;
  nbParty_t_o *v110;
  struct System_Int16_array *v111;
  nbParty_t_o *v113;
  struct System_Int16_array *v115;
  s32 v117;
  nbParty_t_o *v118;
  struct System_Int16_array *v119;

  if ((hojotype & 1) == 0)
  {
    v9 = 0;
    if ((hojotype & 2) == 0)
      goto LABEL_19;
    goto LABEL_12;
  }
  v9 = nbSetHojoAddCounter(formindex, 4, hojopoint, nvirtual);
  if (v9 < 0)
    v9 = -v9;
  if ((hojotype & 2) != 0)
  {
LABEL_12:
    v10 = nbSetHojoAddCounter(formindex, 4, -hojopoint, nvirtual);
    if (v10 >= 0)
      v11 = v10;
    else
      v11 = -v10;
    v9 += v11;
  }
LABEL_19:
  if ((hojotype & 4) != 0)
  {
    v51 = nbSetHojoAddCounter(formindex, 5, hojopoint, nvirtual);
    if (v51 >= 0)
      v52 = v51;
    else
      v52 = -v51;
    v9 += v52;
    if ((hojotype & 8) == 0)
    {
LABEL_21:
      if ((hojotype & 0x10) == 0)
        goto LABEL_22;
      goto LABEL_140;
    }
  }
  else if ((hojotype & 8) == 0)
  {
    goto LABEL_21;
  }
  v53 = nbSetHojoAddCounter(formindex, 5, -hojopoint, nvirtual);
  if (v53 >= 0)
    v54 = v53;
  else
    v54 = -v53;
  v9 += v54;
  if ((hojotype & 0x10) == 0)
  {
LABEL_22:
    if ((hojotype & 0x20) == 0)
      goto LABEL_23;
    goto LABEL_147;
  }
LABEL_140:
  v55 = nbSetHojoAddCounter(formindex, 6, hojopoint, nvirtual);
  if (v55 >= 0)
    v56 = v55;
  else
    v56 = -v55;
  v9 += v56;
  if ((hojotype & 0x20) == 0)
  {
LABEL_23:
    if ((hojotype & 0x40) == 0)
      goto LABEL_24;
    goto LABEL_154;
  }
LABEL_147:
  v57 = nbSetHojoAddCounter(formindex, 6, -hojopoint, nvirtual);
  if (v57 >= 0)
    v58 = v57;
  else
    v58 = -v57;
  v9 += v58;
  if ((hojotype & 0x40) == 0)
  {
LABEL_24:
    if ((hojotype & 0x80) == 0)
      goto LABEL_25;
    goto LABEL_161;
  }
LABEL_154:
  v59 = nbSetHojoAddCounter(formindex, 7, hojopoint, nvirtual);
  if (v59 >= 0)
    v60 = v59;
  else
    v60 = -v59;
  v9 += v60;
  if ((hojotype & 0x80) == 0)
  {
LABEL_25:
    if ((hojotype & 0x100) == 0)
      goto LABEL_26;
    goto LABEL_168;
  }
LABEL_161:
  v61 = nbSetHojoAddCounter(formindex, 7, -hojopoint, nvirtual);
  if (v61 >= 0)
    v62 = v61;
  else
    v62 = -v61;
  v9 += v62;
  if ((hojotype & 0x100) == 0)
  {
LABEL_26:
    if ((hojotype & 0x200) == 0)
      goto LABEL_27;
    goto LABEL_175;
  }
LABEL_168:
  v63 = nbSetHojoAddCounter(formindex, 8, hojopoint, nvirtual);
  if (v63 >= 0)
    v64 = v63;
  else
    v64 = -v63;
  v9 += v64;
  if ((hojotype & 0x200) == 0)
  {
LABEL_27:
    if ((hojotype & 0x1000) == 0)
      goto LABEL_28;
    goto LABEL_182;
  }
LABEL_175:
  v65 = nbSetHojoAddCounter(formindex, 8, -hojopoint, nvirtual);
  if (v65 >= 0)
    v66 = v65;
  else
    v66 = -v65;
  v9 += v66;
  if ((hojotype & 0x1000) == 0)
  {
LABEL_28:
    if ((hojotype & 0x2000) == 0)
      goto LABEL_29;
    goto LABEL_189;
  }
LABEL_182:
  v67 = nbSetHojoAddCounter(formindex, 9, hojopoint, nvirtual);
  if (v67 >= 0)
    v68 = v67;
  else
    v68 = -v67;
  v9 += v68;
  if ((hojotype & 0x2000) == 0)
  {
LABEL_29:
    if ((hojotype & 0x4000) == 0)
      goto LABEL_30;
    goto LABEL_196;
  }
LABEL_189:
  v69 = nbSetHojoAddCounter(formindex, 10, hojopoint, nvirtual);
  if (v69 >= 0)
    v70 = v69;
  else
    v70 = -v69;
  v9 += v70;
  if ((hojotype & 0x4000) == 0)
  {
LABEL_30:
    if ((hojotype & 0x8000) == 0)
      goto LABEL_31;
    goto LABEL_203;
  }
LABEL_196:
  v71 = nbSetHojoAddCounter(formindex, 11, hojopoint, nvirtual);
  if (v71 >= 0)
    v72 = v71;
  else
    v72 = -v71;
  v9 += v72;
  if ((hojotype & 0x8000) == 0)
  {
LABEL_31:
    if ((hojotype & 0x10000) == 0)
      goto LABEL_32;
    goto LABEL_210;
  }
LABEL_203:
  v73 = nbSetHojoAddCounter(formindex, 12, hojopoint, nvirtual);
  if (v73 >= 0)
    v74 = v73;
  else
    v74 = -v73;
  v9 += v74;
  if ((hojotype & 0x10000) == 0)
  {
LABEL_32:
    if ((hojotype & 0x20000) == 0)
      goto LABEL_33;
    goto LABEL_217;
  }
LABEL_210:
  v75 = nbSetHojoAddCounter(formindex, 13, hojopoint, nvirtual);
  if (v75 >= 0)
    v76 = v75;
  else
    v76 = -v75;
  v9 += v76;
  if ((hojotype & 0x20000) == 0)
  {
LABEL_33:
    if ((hojotype & 0x1000000) == 0)
      goto LABEL_34;
    goto LABEL_224;
  }
LABEL_217:
  v77 = nbSetHojoAddCounter(formindex, 14, hojopoint, nvirtual);
  if (v77 >= 0)
    v78 = v77;
  else
    v78 = -v77;
  v9 += v78;
  if ((hojotype & 0x1000000) == 0)
  {
LABEL_34:
    if ((hojotype & 0x400) == 0)
      goto LABEL_231;
    goto LABEL_35;
  }
LABEL_224:
  v79 = nbSetHojoAddCounter(formindex, 15, hojopoint, nvirtual);
  if (v79 >= 0)
    v80 = v79;
  else
    v80 = -v79;
  v9 += v80;
  if ((hojotype & 0x400) == 0)
  {
LABEL_231:
    if ((hojotype & 0x40000) == 0)
      return v9;
    goto LABEL_232;
  }
LABEL_35:
  PartyFromFormindex = nbGetPartyFromFormindex(formindex);
  if (PartyFromFormindex)
  {
    count = PartyFromFormindex->count;
    v16 = count->m_Items[4];
    if (v16 >= 1)
    {
      v9 += v16;
      v17 = nbGetPartyFromFormindex(formindex);
      if (v17)
      {
        v18 = v17->count;
        v18->m_Items[4] = 0;
      }
    }
  }
  v20 = nbGetPartyFromFormindex(formindex);
  if (v20)
  {
    v22 = v20->count;
    v24 = v22->m_Items[5];
    if (v24 >= 1)
    {
      v9 += v24;
      v25 = nbGetPartyFromFormindex(formindex);
      if (v25)
      {
        v26 = v25->count;
        v26->m_Items[5] = 0;
      }
    }
  }
  v28 = nbGetPartyFromFormindex(formindex);
  if (v28)
  {
    v30 = v28->count;
    v32 = v30->m_Items[6];
    if (v32 >= 1)
    {
      v9 += v32;
      v33 = nbGetPartyFromFormindex(formindex);
      if (v33)
      {
        v34 = v33->count;
        v34->m_Items[6] = 0;
      }
    }
  }
  v36 = nbGetPartyFromFormindex(formindex);
  if (v36)
  {
    v38 = v36->count;
    v40 = v38->m_Items[7];
    if (v40 >= 1)
    {
      v9 += v40;
      v41 = nbGetPartyFromFormindex(formindex);
      if (v41)
      {
        v42 = v41->count;
        v42->m_Items[7] = 0;
      }
    }
  }
  v44 = nbGetPartyFromFormindex(formindex);
  if (!v44)
    goto LABEL_231;
  v45 = v44->count;
  v47 = v45->m_Items[8];
  if (v47 < 1)
    goto LABEL_231;
  v9 += v47;
  v48 = nbGetPartyFromFormindex(formindex);
  if (!v48)
    goto LABEL_231;
  v49 = v48->count;
  v49->m_Items[8] = 0;
  if ((hojotype & 0x40000) != 0)
  {
LABEL_232:
    v81 = nbGetPartyFromFormindex(formindex);
    if (v81)
    {
      v83 = v81->count;
      v85 = v83->m_Items[4];
      if (v85 < 0)
      {
        v9 -= v85;
        v86 = nbGetPartyFromFormindex(formindex);
        if (v86)
        {
          v87 = v86->count;
          v87->m_Items[4] = 0;
        }
      }
    }
    v89 = nbGetPartyFromFormindex(formindex);
    if (v89)
    {
      v91 = v89->count;
      v93 = v91->m_Items[5];
      if (v93 < 0)
      {
        v9 -= v93;
        v94 = nbGetPartyFromFormindex(formindex);
        if (v94)
        {
          v95 = v94->count;
          v95->m_Items[5] = 0;
        }
      }
    }
    v97 = nbGetPartyFromFormindex(formindex);
    if (v97)
    {
      v99 = v97->count;
      v101 = v99->m_Items[6];
      if (v101 < 0)
      {
        v9 -= v101;
        v102 = nbGetPartyFromFormindex(formindex);
        if (v102)
        {
          v103 = v102->count;
          v103->m_Items[6] = 0;
        }
      }
    }
    v105 = nbGetPartyFromFormindex(formindex);
    if (v105)
    {
      v107 = v105->count;
      v109 = v107->m_Items[7];
      if (v109 < 0)
      {
        v9 -= v109;
        v110 = nbGetPartyFromFormindex(formindex);
        if (v110)
        {
          v111 = v110->count;
          v111->m_Items[7] = 0;
        }
      }
    }
    v113 = nbGetPartyFromFormindex(formindex);
    if (v113)
    {
      v115 = v113->count;
      v117 = v115->m_Items[8];
      if (v117 < 0)
      {
        v9 -= v117;
        v118 = nbGetPartyFromFormindex(formindex);
        if (v118)
        {
          v119 = v118->count;
          v119->m_Items[8] = 0;
        }
      }
    }
  }
  return v9;
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
