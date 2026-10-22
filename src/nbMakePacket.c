#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct effBTLCutHandle_t effBTLCutHandle_t;
typedef struct effBTLSysHandle_t effBTLSysHandle_t;
typedef struct effBTL_t effBTL_t;
typedef struct effPCPBossBUNSIN2Param_t effPCPBossBUNSIN2Param_t;
typedef struct effPCPBossBUNSIN2_t effPCPBossBUNSIN2_t;
typedef struct effPCPBossBUNSINParam_t effPCPBossBUNSINParam_t;
typedef struct effPCPBossBUNSIN_t effPCPBossBUNSIN_t;
typedef struct effPCPBossONGY2Param_t effPCPBossONGY2Param_t;
typedef struct effPCPBossONGY2_t effPCPBossONGY2_t;
typedef struct effPCPBossONGYParam_t effPCPBossONGYParam_t;
typedef struct effPCPBossONGY_t effPCPBossONGY_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbKoukaProcessData_t nbKoukaProcessData_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbParty_t nbParty_t;

s32 FindId(s32 type, char *name);
u8 Get(s32 id);
void *GetHitNum(s32 idx, s32 copyNumber);
void Lerp(f32 aRatio);
f32 SDF_DEGtoRAD(f32 n);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_B_A(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__INNERPRODUCT(void);
void SDF_VU0__LOADIDENTITYVECTOR(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__SETVECTOR_Y(f32 v);
void SDF_VU0__SETVECTOR_Z(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
void ToMatrix(void);
void dds3RotationArc(void);
effBTL_t *effBTLCreate(u8 **pData);
effBTLCutHandle_t *effBTLCutCreate(effBTL_t **hBTLEffect, u16 CutNum, nbFormation_t *pFormation, u32 stat);
void effBTLCutSetCutEndFrame(effBTLCutHandle_t **hBTLCutEffect, u32 frame);
u32 effBTLGetCutEndFrame(effBTL_t **hBTLEffect, u16 CutNum);
effBTLSysHandle_t *effBTLSystemCreate(nbFormation_t **pFormation, u32 id);
effBTLCutHandle_t *effBTLSystemCut1Create(nbFormation_t **pFormation, u32 index);
u32 effBTLSystemGetLength(effBTLSysHandle_t **hEffBTLSys);
effPCPBossBUNSIN2_t *effPCPBossBUNSIN2Create(effPCPBossBUNSIN2Param_t *pParam);
s32 effPCPBossBUNSIN2GetLength(void);
effPCPBossBUNSIN_t *effPCPBossBUNSINCreate(effPCPBossBUNSINParam_t *pParam);
s32 effPCPBossBUNSINGetLength(void);
effPCPBossONGY2_t *effPCPBossONGY2Create(effPCPBossONGY2Param_t *pParam);
s32 effPCPBossONGY2GetLength(void);
effPCPBossONGY_t *effPCPBossONGYCreate(effPCPBossONGYParam_t *pParam);
s32 effPCPBossONGYGetLength(void);
nbKoukaPacket_t *nbAddDeadPcmPacket(s32 startframe, s32 uniqueid, nbFormation_t **form);
nbKoukaPacket_t *nbAddHitEffKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type);
nbKoukaPacket_t *nbAddKoukaPacket(nbKoukaProcessData_t **k, s32 startframe, s32 framelength, s32 uniqueid);
nbKoukaPacket_t *nbAddMojiEffKoukaPacket(s32 startframe, s32 frame, s32 uniqueid, nbFormation_t **form, s32 type);
nbKoukaPacket_t *nbAddNewPressPacket(s32 startframe, s32 uniqueid, s32 press_p, s32 press_ten);
nbKoukaPacket_t *nbAddNumEffKoukaPacket(s32 startframe, s32 frame, s32 uniqueid, nbFormation_t **form, s32 n, s32 n2, s32 type);
nbKoukaPacket_t *nbAddPadShockPacket(s32 startframe, s32 uniqueid, s32 mode, s32 pow, s32 time);
nbKoukaPacket_t *nbAddSummonKoukaPacket(s32 startframe, s32 uniqueid, s32 side, s32 stockno, s32 formindex);
s32 nbCheckDeadEvent(nbFormation_t *form);
s32 nbCheckEventDead(nbFormation_t *form);
s32 nbCheckSePacket(s32 start, s32 se, s32 frame);
void nbDelAllMojiNumEffectKoukaPacket(nbFormation_t **form, s32 motno);
u32 nbGetBadStat(s32 formindex);
s32 nbGetDeadEventFadeInFrame(s32 eventno);
s32 nbGetDeadEventFadeOutFrame(s32 eventno);
s32 nbGetDeadEventFadeStopFrame(s32 eventno);
s32 nbGetDeadEventFadeTime(s32 eventno);
void nbGetFormCenter(nbFormation_t *form);
nbKoukaProcessData_t *nbGetKoukaProcessData(void);
nbMainProcessData_t *nbGetMainProcessData(void);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
datUnitWork_t *nbGetUnitWorkPointer(nbMainProcessData_t *data, nbParty_t *party);
s32 nbMakeBadDamagePacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 bad);
s32 nbMakeBadKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t **form);
s32 nbMakeDeadVisualPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 deadtype, s32 deadpcm);
f32 nbMakeUnitMoveGetCyDist(nbFormation_t **i_form, nbFormation_t **t_form);
f32 sdfAcos(f32 aX);
f32 sdfAtan2(f32 aY, f32 aX);
f32 sdfCos(f32 aRadius);
f32 sdfFabs(f32 c);

// 0x1984be0
s32 mdlGetNumOfCut(dds3ModelHandle_t *aHandle, s32 aGroup) {
  return 0;
}

// 0x1986f90
nbKoukaPacket_t *nbAddAnalyzePacket(s32 startframe, s32 uniqueid, nbFormation_t **form) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 2, uniqueid);
  result->type = 34;
  result->form = *form;
  return result;
}

// 0x1985c30
nbKoukaPacket_t *nbAddBadDmgMotKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, f32 range, s32 badstat) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 10;
  result->form = *form;
  result->data1->f = range;
  result->data2->i = badstat;
  return result;
}

// 0x1986190
nbKoukaPacket_t *nbAddBadEffKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t **form) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 24;
  result->form = *form;
  return result;
}

// 0x19861f0
nbKoukaPacket_t *nbAddBadEffKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 bad) {
  nbKoukaPacket_t_o *result;
  s32 v11;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 23;
  result->form = *form;
  if (bad > 0x20)
  {
    if (bad > 0x80)
    {
      switch (bad)
      {
        case 0x100u:
          v11 = 9;
          break;
        case 0x200u:
          v11 = 10;
          break;
        case 0x400u:
          v11 = 11;
          break;
        default:
          v11 = 0;
          break;
      }
    }
    else
    {
      v11 = 8 * (bad == 128);
      if (bad == 64)
        v11 = 7;
    }
  }
  else if (bad > 8)
  {
    if (bad == 32)
      v11 = 6;
    else
      v11 = 0;
    if (bad == 16)
      v11 = 5;
  }
  else if (bad - 1 >= 4)
  {
    v11 = 4 * (bad == 8);
  }
  else
  {
    v11 = dword_32C3BF0[bad - 1];
  }
  result->data1->i = v11;
  return result;
}

// 0x1986dc0
nbKoukaPacket_t *nbAddBadMotKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t **form) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 20;
  result->form = *form;
  return result;
}

// 0x1985cb0
nbKoukaPacket_t *nbAddBadMotKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 badstat) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 37;
  result->form = *form;
  result->data2->i = badstat;
  return result;
}

// 0x1986d40
nbKoukaPacket_t *nbAddBadStatKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 badstat, s32 sw) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 19;
  result->form = *form;
  result->data1->i = sw;
  result->data2->i = badstat;
  return result;
}

// 0x1987640
nbKoukaPacket_t *nbAddDeadEventKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 eventno) {
  nbKoukaProcessData_t_o *KoukaProcessData;
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  KoukaProcessData = nbGetKoukaProcessData(*&startframe);
  k = KoukaProcessData;
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  KoukaProcessData->data->actionstackp = 0;
  KoukaProcessData->data->eventno = result->data1->i;
  KoukaProcessData->data->endtype = 7;
  result->type = 46;
  result->form = *form;
  result->data1->i = eventno;
  return result;
}

// 0x197e1c0
nbKoukaPacket_t *nbAddDeadPcmPacket(s32 startframe, s32 uniqueid, nbFormation_t **form) {
  s32 formindex;
  nbKoukaPacket_t_o *result;
  nbKoukaPacket_t_o *v9;
  s32 v11;
  nbKoukaProcessData_t_o *k;

  k = 0;
  formindex = (*form)->formindex;
  else
  {
    result = nbGetUnitWorkFromFormindex(formindex, *&uniqueid);
    if (!result)
      return result;
  }
  v9 = result;
  k = nbGetKoukaProcessData(result);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 36;
  result->form = *form;
  if ((*(&v9->uniqueid + 3) & 0xFFF) == 0x200)
    v11 = 255;
  else
    v11 = *&v9->type;
  result->data1->i = v11;
  return result;
}

// 0x1985b30
nbKoukaPacket_t *nbAddDmgMotKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, f32 range, s32 week) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 9;
  result->form = *form;
  result->data1->f = range;
  result->data2->i = week;
  return result;
}

// 0x1985bb0
nbKoukaPacket_t *nbAddEasyDmgMotKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, f32 range) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 53;
  result->form = *form;
  result->data1->f = range;
  return result;
}

// 0x1987750
nbKoukaPacket_t *nbAddFadeInKoukaPacket(s32 startframe, s32 uniqueid, s32 length, s32 coltype) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 48;
  result->data1->i = length;
  result->data2->i = coltype;
  return result;
}

// 0x19876e0
nbKoukaPacket_t *nbAddFadeOutKoukaPacket(s32 startframe, s32 uniqueid, s32 length, s32 coltype) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 47;
  result->data1->i = length;
  result->data2->i = coltype;
  return result;
}

// 0x1987840
nbKoukaPacket_t *nbAddFlareChargePacket(s32 startframe, s32 uniqueid, s32 point) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 51;
  result->data1->i = point;
  return result;
}

// 0x1987200
nbKoukaPacket_t *nbAddFlyKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 45;
  result->form = *form;
  result->data1->i = 0;
  return result;
}

// 0x1987180
nbKoukaPacket_t *nbAddFormFlagOnOffPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 sw, u32 flag) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 44;
  result->form = *form;
  result->data1->i = sw;
  result->data2->i = flag;
  return result;
}

// 0x1987110
nbKoukaPacket_t *nbAddFormOnOffPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 sw) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 38;
  result->form = *form;
  result->data1->i = sw;
  return result;
}

// 0x1984f20
void nbAddHatudoEffectEndPacket(s32 startframe, s32 uniqueid) {
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  nbAddKoukaPacket(&k, startframe, 0, uniqueid)->type = 58;
}

// 0x1984f70
nbKoukaPacket_t *nbAddHatudoEffectKoukaPacket(s32 startframe, s32 framelength, s32 uniqueid, nbFormation_t **form, s32 type, s32 mottype, s32 skillid) {
  s32 v13;
  s32 formindex;
  u32 id;
  nbKoukaPacket_t_o *result;
  s32 v20;
  s64 *v21;
  s32 v22;
  nbKoukaPacket_t_o *v25;
  effBTLCutHandle_t_o *v29;
  nbKoukaProcessData_t_o *k;

  v13 = framelength;
  v29 = 0;
  if (!type)
    return 0;
  formindex = (*form)->formindex;
  id = nbGetUnitWorkFromFormindex(formindex, *&framelength)->id;
  if (id > 0x103)
  {
    v20 = 24;
    switch (id)
    {
      case 0x123u:
LABEL_15:
        v21 = &"BSE_E905_SE02";
        type = 13;
        goto LABEL_51;
      case 0x124u:
        if (skillid == 169)
        {
          v13 += 10;
          type = 20;
          goto LABEL_43;
        }
        v20 = 15;
        break;
      case 0x125u:
LABEL_28:
        v21 = &"BSE_E909_SE02";
        type = 17;
        goto LABEL_51;
      case 0x126u:
      case 0x127u:
      case 0x128u:
      case 0x129u:
      case 0x12Au:
      case 0x12Bu:
      case 0x12Cu:
      case 0x12Du:
      case 0x12Eu:
      case 0x12Fu:
      case 0x130u:
      case 0x131u:
      case 0x132u:
      case 0x133u:
      case 0x134u:
      case 0x135u:
      case 0x136u:
      case 0x137u:
      case 0x138u:
      case 0x139u:
      case 0x13Au:
      case 0x13Bu:
      case 0x13Cu:
      case 0x13Du:
      case 0x13Eu:
      case 0x13Fu:
      case 0x140u:
      case 0x141u:
      case 0x142u:
      case 0x143u:
      case 0x144u:
      case 0x145u:
      case 0x146u:
      case 0x147u:
      case 0x148u:
      case 0x149u:
      case 0x14Au:
      case 0x14Bu:
      case 0x14Cu:
      case 0x14Du:
      case 0x14Eu:
      case 0x14Fu:
      case 0x150u:
      case 0x151u:
      case 0x152u:
      case 0x153u:
      case 0x154u:
      case 0x155u:
        goto LABEL_22;
      case 0x156u:
LABEL_32:
        v21 = &"BSE_E914_SE01";
        type = 22;
        goto LABEL_51;
      case 0x157u:
LABEL_36:
        v21 = &"BSE_E915_SE01";
        type = 23;
        goto LABEL_51;
      case 0x158u:
        goto LABEL_55;
      default:
        if (id != 264)
          goto LABEL_22;
LABEL_47:
        v21 = &"BSE_E909_SE03";
        type = 18;
        goto LABEL_51;
    }
    goto LABEL_55;
  }
  if (!id)
  {
    if (mottype == 12)
    {
      v22 = 65547;
      type = 19;
      v13 = 0x7FFF;
LABEL_52:
      k = 0;
      v23 = nbCheckSePacket(startframe, v22, 5);
      if (!v23)
      {
        k = nbGetKoukaProcessData();
        v25 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
        v25->type = 25;
        v25->data1->i = v22;
      }
LABEL_54:
      v20 = type;
      goto LABEL_55;
    }
    goto LABEL_22;
  }
  if (id == 258)
  {
LABEL_24:
    v21 = &"BSE_E905_SE03";
    type = 14;
    goto LABEL_51;
  }
  if (id != 259)
  {
LABEL_22:
    v22 = 65547;
    v20 = type;
    switch (type)
    {
      case 1:
      case 2:
      case 7:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      case 19:
        goto LABEL_52;
      case 3:
        v22 = 65548;
        goto LABEL_52;
      case 4:
        v22 = 65549;
        goto LABEL_52;
      case 5:
        v22 = 65550;
        goto LABEL_52;
      case 6:
        v22 = 65551;
        goto LABEL_52;
      case 13:
        goto LABEL_15;
      case 14:
        goto LABEL_24;
      case 15:
      case 16:
        goto LABEL_55;
      case 17:
        goto LABEL_28;
      case 18:
        goto LABEL_47;
      case 20:
      case 21:
        goto LABEL_43;
      case 22:
        goto LABEL_32;
      case 23:
        goto LABEL_36;
      default:
        goto LABEL_54;
    }
    goto LABEL_55;
  }
  if (skillid != 170)
  {
    v20 = 16;
    goto LABEL_55;
  }
  v13 += 10;
  type = 21;
LABEL_43:
  v21 = &"BSE_E907_SE02";
LABEL_51:
  v22 = FindId(1, *v21);
  v20 = type;
  if (v22)
    goto LABEL_52;
LABEL_55:
  v29 = effBTLSystemCut1Create(form, v20);
  effBTLCutSetCutEndFrame(&v29, v13);
  k = nbGetKoukaProcessData();
  result = nbAddKoukaPacket(&k, startframe, v13, uniqueid);
  result->type = 26;
  result->cuteff = v29;
  return result;
}

// 0x1985f30
nbKoukaPacket_t *nbAddHitEffKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type) {
  s32 v8;
  nbKoukaPacket_t_o *v9;
  nbKoukaPacket_t_o *v11;
  s32 v13;
  s32 v14;
  u32 v15;
  s16 Length;
  u64 *v18;
  nbKoukaPacket_t_o *v22;
  struct nbKoukaData_t_o *data1;
  Il2CppObject *v25;
  nbKoukaProcessData_t_o *k;
  nbKoukaProcessData_t_o *KoukaProcessData;

  v8 = startframe;
  v25 = 0;
  k = 0;
  v9 = 0;
  if (((*form)->stat & 1) != 0)
  {
    k = nbGetKoukaProcessData(*&startframe);
    v11 = nbAddKoukaPacket(&k, v8, 0, uniqueid);
    v11->type = 15;
    v11->form = *form;
    v9 = v11;
    v13 = type;
    v11->data1->i = type;
    v14 = 0;
    v15 = 25;
    switch (v13)
    {
      case 0:
        v14 = 0;
        v15 = 24;
        goto LABEL_15;
      case 1:
        v14 = 65544;
        v15 = 17;
        goto LABEL_15;
      case 2:
        v14 = 65545;
        v15 = 18;
        goto LABEL_15;
      case 3:
        v11->framelength = 0;
        return v9;
      case 4:
        v15 = 26;
        v14 = 65537;
        goto LABEL_15;
      case 5:
        v15 = 20;
        v14 = 0x10000;
        goto LABEL_15;
      case 6:
        v14 = 0;
        v15 = 14;
        goto LABEL_15;
      case 7:
        goto LABEL_15;
      case 8:
        v14 = 65541;
        v15 = 27;
        goto LABEL_15;
      case 9:
        v14 = 65543;
        v15 = 28;
        goto LABEL_15;
      case 10:
        v14 = 65542;
        v15 = 29;
LABEL_15:
        v25 = effBTLSystemCreate(form, v15);
        v9->data2->p = v25;
        v9->framelength = 0;
        Length = effBTLSystemGetLength(&v25);
        v9->framelength = Length;
        LOWORD(KoukaProcessData) = Length;
        v18 = sub_8D3950(s16, &KoukaProcessData);
        Write_2930400("length = {0:D}\n", v18);
        if (v14)
        {
          KoukaProcessData = 0;
          v20 = nbCheckSePacket(v8, v14, 5);
          if (!v20)
          {
            KoukaProcessData = nbGetKoukaProcessData();
            v22 = nbAddKoukaPacket(&KoukaProcessData, v8, 0, uniqueid);
            data1 = v22->data1;
            v22->type = 25;
            data1->i = v14;
          }
        }
        break;
      default:
        return v9;
    }
  }
  return v9;
}

// 0x1986f40
nbKoukaPacket_t *nbAddHitStopPacket(s32 startframe, s32 uniqueid) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 2, uniqueid);
  result->type = 30;
  return result;
}

// 0x19877c0
nbKoukaPacket_t *nbAddHojoKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 hojotype, s32 hojopoint) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 50;
  result->form = *form;
  result->data1->i = hojotype;
  result->data2->i = hojopoint;
  return result;
}

// 0x19854b0
nbKoukaPacket_t *nbAddHomeMoveKoukaPacket(s32 startframe, s32 uniqueid, s32 partyno, f32 speed) {
  nbKoukaPacket_t_o *result;
  struct nbKoukaData_t_o *data1;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 2;
  data1 = result->data1;
  result->partyno = partyno;
  data1->f = speed;
  return result;
}

// 0x19855d0
nbKoukaPacket_t *nbAddHomeRotKoukaPacket(s32 startframe, s32 uniqueid, s32 partyno, s32 speed) {
  nbKoukaPacket_t_o *result;
  struct nbKoukaData_t_o *data1;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 4;
  data1 = result->data1;
  result->partyno = partyno;
  data1->i = speed;
  return result;
}

// 0x1986bb0
nbKoukaPacket_t *nbAddHpMpKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 n, s32 type) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 17;
  result->form = *form;
  result->data1->i = type;
  result->data2->i = n;
  return result;
}

// 0x1986ff0
nbKoukaPacket_t *nbAddJyokyoHelpPacket(s32 startframe, s32 uniqueid, s32 no, s32 var_id, s32 var_ind) {
  s16 v7;
  s16 v8;
  nbKoukaPacket_t_o *result;
  struct System_Int16_array *s;
  struct System_Int16_array *v15;
  nbKoukaProcessData_t_o *k;

  v7 = var_id;
  v8 = no;
  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 35;
  s = result->data1->s;
  s->m_Items[0] = v8;
  v15 = result->data1->s;
  v15->m_Items[1] = v7;
  result->data2->i = var_ind;
  return result;
}

// 0x1986840
nbKoukaPacket_t *nbAddMojiEffKoukaPacket(s32 startframe, s32 frame, s32 uniqueid, nbFormation_t **form, s32 type) {
  s32 v10;
  struct nbKoukaPacket_t_o *first;
  s32 v14;
  struct nbKoukaPacket_t_o *v15;
  s32 v16;
  s32 v17;
  struct System_Int16_array *s;
  nbKoukaPacket_t_o *v22;
  nbKoukaPacket_t_o *v23;
  struct System_Int16_array *v26;
  nbKoukaPacket_t_o *v27;
  s32 formindex;
  UnityEngine_GameObject_o *HitNum;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v32;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v34;
  UnityEngine_Component_o *v35;
  UnityEngine_GameObject_o *v36;
  UnityEngine_Transform_o *v37;
  UnityEngine_Component_o *v38;
  UnityEngine_GameObject_o *v39;
  UnityEngine_Transform_o *v40;
  UnityEngine_Component_o *v41;
  UnityEngine_GameObject_o *v42;
  UnityEngine_Transform_o *v43;
  UnityEngine_Component_o *v44;
  UnityEngine_GameObject_o *v45;
  UnityEngine_Transform_o *v46;
  UnityEngine_Component_o *v47;
  UnityEngine_GameObject_o *v48;
  nbKoukaProcessData_t_o *KoukaProcessData;
  nbKoukaProcessData_t_o *k;

  v10 = startframe;
  KoukaProcessData = nbGetKoukaProcessData(*&startframe);
  first = KoukaProcessData->first;
  if (first)
  {
    v14 = 0;
    while (1)
    {
      v15 = first;
      first = first->next;
      v16 = v15->type;
      if (v16 == 16)
        break;
      if (v16 == 22
        && v15->uniqueid == uniqueid
        && v15->form == *form
        && (v17 = v15->startframe, v15->framelength + v17 > v10))
      {
        v15->framelength = (v10 - v17) & ~((v10 - v17) >> 15);
        if (!first)
          goto LABEL_17;
      }
      else
      {
LABEL_16:
        if (!first)
        {
LABEL_17:
          if (type != 4)
            goto LABEL_22;
          goto LABEL_20;
        }
      }
    }
    if (v15->uniqueid == uniqueid)
    {
      s = v15->data1->s;
      v14 = s->m_Items[0];
    }
    goto LABEL_16;
  }
  v14 = 0;
  if (type != 4)
    goto LABEL_22;
LABEL_20:
  k = 0;
  v20 = nbCheckSePacket(v10, 65546, 5);
  if (!v20)
  {
    k = nbGetKoukaProcessData();
    v22 = nbAddKoukaPacket(&k, v10, 0, uniqueid);
    v22->type = 25;
    v22->data1->i = 65546;
  }
LABEL_22:
  v23 = nbAddKoukaPacket(&KoukaProcessData, v10, frame, uniqueid);
  v23->type = 22;
  v23->form = *form;
  v23->data1->i = type;
  v26 = v23->data1->s;
  v27 = v23;
  v26->m_Items[0] = v14;
  formindex = (*form)->formindex;
  HitNum = GetHitNum(formindex, v14);
  SetActive(HitNum, 1, 0);
  GetComponent_object_(HitNum);
  transform = get_transform(HitNum, 0);
  v32 = Find(transform, "num_damage", 0);
  gameObject = get_gameObject(v32);
  SetActive(gameObject, 0, 0);
  v34 = get_transform(HitNum, 0);
  v35 = Find(v34, "critical", 0);
  v36 = get_gameObject(v35);
  SetActive(v36, 0, 0);
  v37 = get_transform(HitNum, 0);
  v38 = Find(v37, "weakpoint", 0);
  v39 = get_gameObject(v38);
  SetActive(v39, 0, 0);
  v40 = get_transform(HitNum, 0);
  v41 = Find(v40, "miss", 0);
  v42 = get_gameObject(v41);
  SetActive(v42, 0, 0);
  v43 = get_transform(HitNum, 0);
  v44 = Find(v43, "block", 0);
  v45 = get_gameObject(v44);
  SetActive(v45, 0, 0);
  v46 = get_transform(HitNum, 0);
  v47 = Find(v46, "talk", 0);
  v48 = get_gameObject(v47);
  SetActive(v48, 0, 0);
  return v27;
}

// 0x19859e0
nbKoukaPacket_t *nbAddMotionKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 motion) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 27;
  result->form = *form;
  result->data1->i = motion;
  return result;
}

// 0x1985980
nbKoukaPacket_t *nbAddMotionStopClearPacket(s32 startframe, s32 uniqueid, nbFormation_t **form) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 33;
  result->form = *form;
  return result;
}

// 0x1985920
nbKoukaPacket_t *nbAddMotionStopPacket(s32 startframe, s32 uniqueid, nbFormation_t **form) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 32;
  result->form = *form;
  return result;
}

// 0x1986c90
nbKoukaPacket_t *nbAddNewPressPacket(s32 startframe, s32 uniqueid, s32 press_p, s32 press_ten) {
  s16 v5;
  s16 v6;
  nbKoukaPacket_t_o *result;
  struct System_Int16_array *s;
  struct System_Int16_array *v13;
  nbKoukaProcessData_t_o *k;

  v5 = press_ten;
  v6 = press_p;
  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 31;
  s = result->data1->s;
  s->m_Items[0] = v6;
  v13 = result->data1->s;
  v13->m_Items[1] = v5;
  return result;
}

// 0x1986310
nbKoukaPacket_t *nbAddNumEffKoukaPacket(s32 startframe, s32 frame, s32 uniqueid, nbFormation_t **form, s32 n, s32 n2, s32 type) {
  u64 *v14;
  struct nbKoukaPacket_t_o *first;
  struct nbKoukaPacket_t_o *v18;
  nbFormation_t_o *v19;
  nbFormation_t_o *v20;
  s32 v21;
  struct System_Int16_array *s;
  nbKoukaPacket_t_o *v24;
  nbKoukaPacket_t_o *v25;
  s32 v28;
  s32 Count;
  struct System_Int16_array *v30;
  s32 formindex;
  UnityEngine_GameObject_o *HitNum;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v34;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v36;
  UnityEngine_Component_o *v37;
  UnityEngine_GameObject_o *v38;
  UnityEngine_Transform_o *v39;
  UnityEngine_Component_o *v40;
  UnityEngine_GameObject_o *v41;
  UnityEngine_Transform_o *v42;
  UnityEngine_Component_o *v43;
  UnityEngine_GameObject_o *v44;
  UnityEngine_Transform_o *v45;
  UnityEngine_Component_o *v46;
  UnityEngine_GameObject_o *v47;
  UnityEngine_Transform_o *v48;
  UnityEngine_Component_o *v49;
  UnityEngine_GameObject_o *v50;
  s32 v53;
  UnityEngine_GameObject_o *v54;
  UnityEngine_Transform_o *v55;
  UnityEngine_Component_o *v56;
  UnityEngine_GameObject_o *v57;
  UnityEngine_Transform_o *v58;
  UnityEngine_Component_o *v59;
  UnityEngine_GameObject_o *v60;
  UnityEngine_Transform_o *v61;
  UnityEngine_Component_o *v62;
  UnityEngine_GameObject_o *v63;
  UnityEngine_Transform_o *v64;
  UnityEngine_Component_o *v65;
  UnityEngine_GameObject_o *v66;
  UnityEngine_Transform_o *v67;
  UnityEngine_Component_o *v68;
  UnityEngine_GameObject_o *v69;
  UnityEngine_Transform_o *v70;
  UnityEngine_Component_o *v71;
  UnityEngine_GameObject_o *v72;
  nbKoukaProcessData_t_o *k;

  v14 = Allocate(System_Collections_Generic_List_int_);
  __ctor(v14);
  k = nbGetKoukaProcessData();
  first = k->first;
  if (first)
  {
    while (1)
    {
      while (1)
      {
        v18 = first;
        first = first->next;
        if (v18->type == 16)
          break;
LABEL_11:
        if (!first)
          goto LABEL_16;
      }
      v19 = v18->form;
      v20 = *form;
      if (v18->uniqueid == uniqueid && v19 == v20)
      {
        v21 = v18->startframe;
        if (v18->framelength + v21 <= startframe)
          goto LABEL_11;
        v18->framelength = (startframe - v21) & ~((startframe - v21) >> 15);
        if (!first)
          break;
      }
      else
      {
        if (v19 != v20)
          goto LABEL_11;
        s = v18->data1->s;
        _Add(v14, s->m_Items[0]);
        if (!first)
          break;
      }
    }
  }
LABEL_16:
  v24 = nbAddKoukaPacket(&k, startframe, frame, uniqueid);
  v24->type = 16;
  v24->form = *form;
  v24->data1->i = type;
  v24->data2->i = n;
  v24->partyno = n2;
  v25 = v24;
  if (!_get_Count(v14)
    || _get_Count(v14) < 1)
  {
    v28 = 0;
    v30 = v25->data1->s;
    if (LODWORD(v30->max_length))
      goto LABEL_23;
LABEL_33:
  }
  v28 = 0;
  while (_Contains(v14, v28))
  {
    Count = _get_Count(v14);
    if (++v28 >= _get_Count(v14))
    {
      v28 = Count;
      break;
    }
  }
  v30 = v25->data1->s;
  if (!LODWORD(v30->max_length))
    goto LABEL_33;
LABEL_23:
  v30->m_Items[0] = v28;
  formindex = (*form)->formindex;
  HitNum = GetHitNum(formindex, v28);
  SetActive(HitNum, 1, 0);
  transform = get_transform(HitNum, 0);
  v34 = Find(transform, "num_damage", 0);
  gameObject = get_gameObject(v34);
  SetActive(gameObject, 0, 0);
  v36 = get_transform(HitNum, 0);
  v37 = Find(v36, "critical", 0);
  v38 = get_gameObject(v37);
  SetActive(v38, 0, 0);
  v39 = get_transform(HitNum, 0);
  v40 = Find(v39, "weakpoint", 0);
  v41 = get_gameObject(v40);
  SetActive(v41, 0, 0);
  v42 = get_transform(HitNum, 0);
  v43 = Find(v42, "miss", 0);
  v44 = get_gameObject(v43);
  SetActive(v44, 0, 0);
  v45 = get_transform(HitNum, 0);
  v46 = Find(v45, "block", 0);
  v47 = get_gameObject(v46);
  SetActive(v47, 0, 0);
  v48 = get_transform(HitNum, 0);
  v49 = Find(v48, "talk", 0);
  v50 = get_gameObject(v49);
  SetActive(v50, 0, 0);
  if ((type & 0xFFFFFFFE) == 4)
  {
    v53 = (*form)->formindex;
    v54 = GetHitNum(v53, v28 + 1);
    SetActive(v54, 1, 0);
    v55 = get_transform(v54, 0);
    v56 = Find(v55, "num_damage", 0);
    v57 = get_gameObject(v56);
    SetActive(v57, 0, 0);
    v58 = get_transform(v54, 0);
    v59 = Find(v58, "critical", 0);
    v60 = get_gameObject(v59);
    SetActive(v60, 0, 0);
    v61 = get_transform(v54, 0);
    v62 = Find(v61, "weakpoint", 0);
    v63 = get_gameObject(v62);
    SetActive(v63, 0, 0);
    v64 = get_transform(v54, 0);
    v65 = Find(v64, "miss", 0);
    v66 = get_gameObject(v65);
    SetActive(v66, 0, 0);
    v67 = get_transform(v54, 0);
    v68 = Find(v67, "block", 0);
    v69 = get_gameObject(v68);
    SetActive(v69, 0, 0);
    v70 = get_transform(v54, 0);
    v71 = Find(v70, "talk", 0);
    v72 = get_gameObject(v71);
    SetActive(v72, 0, 0);
  }
  return v25;
}

// 0x1987350
nbKoukaPacket_t *nbAddOngBunshin2Packet(s32 startframe, s32 uniqueid, nbFormation_t **sform, nbFormation_t **form1, nbFormation_t **form2, nbFormation_t **form3) {
  effPCPBossBUNSIN2Param_t_o *v13;
  s32 Length;
  nbKoukaPacket_t_o *v18;
  nbKoukaPacket_t_o *v19;
  effPCPBossBUNSIN2_t_o *v20;
  nbKoukaProcessData_t_o *k;

  v13 = Allocate(effPCPBossBUNSIN2Param_t);
  effPCPBossBUNSIN2Param_t___ctor(v13);
  k = nbGetKoukaProcessData();
  Length = effPCPBossBUNSIN2GetLength();
  v18 = nbAddKoukaPacket(&k, startframe, Length, uniqueid);
  v13->pStartForm = *sform;
  v13->pForm1 = *form1;
  v13->pForm2L = *form2;
  v19 = v18;
  v13->pForm2R = *form3;
  v20 = effPCPBossBUNSIN2Create(v13);
  v19->type = 40;
  v19->data1->p = v20;
  return v19;
}

// 0x1987260
nbKoukaPacket_t *nbAddOngBunshinPacket(s32 startframe, s32 uniqueid, nbFormation_t **sform, nbFormation_t **dform) {
  effPCPBossBUNSINParam_t_o *v9;
  s32 v12;
  nbKoukaPacket_t_o *v14;
  nbKoukaPacket_t_o *v15;
  effPCPBossBUNSIN_t_o *v16;
  nbKoukaProcessData_t_o *k;

  v9 = Allocate(effPCPBossBUNSINParam_t);
  effPCPBossBUNSINParam_t___ctor(v9);
  k = nbGetKoukaProcessData();
  v12 = effPCPBossBUNSINGetLength();
  v14 = nbAddKoukaPacket(&k, startframe, v12, uniqueid);
  v9->pStartForm = *sform;
  v15 = v14;
  v9->pEndForm = *dform;
  v16 = effPCPBossBUNSINCreate(v9);
  v15->type = 39;
  v15->data1->p = v16;
  return v15;
}

// 0x1987550
nbKoukaPacket_t *nbAddOngOut2Packet(s32 startframe, s32 uniqueid, nbFormation_t **form) {
  effPCPBossONGY2Param_t_o *v7;
  s32 Length;
  nbKoukaPacket_t_o *v12;
  effPCPBossONGY2_t_o *v13;
  nbKoukaProcessData_t_o *k;

  v7 = Allocate(effPCPBossONGY2Param_t);
  effPCPBossONGY2Param_t___ctor(v7);
  k = nbGetKoukaProcessData();
  Length = effPCPBossONGY2GetLength();
  v12 = nbAddKoukaPacket(&k, startframe, Length, uniqueid);
  v7->pFormation = *form;
  v13 = effPCPBossONGY2Create(v7);
  v12->type = 42;
  v12->data1->p = v13;
  return v12;
}

// 0x1987460
nbKoukaPacket_t *nbAddOngOutPacket(s32 startframe, s32 uniqueid, nbFormation_t **form) {
  effPCPBossONGYParam_t_o *v7;
  s32 v10;
  nbKoukaPacket_t_o *v12;
  effPCPBossONGY_t_o *v13;
  nbKoukaProcessData_t_o *k;

  v7 = Allocate(effPCPBossONGYParam_t);
  effPCPBossONGYParam_t___ctor(v7);
  k = nbGetKoukaProcessData();
  v10 = effPCPBossONGYGetLength();
  v12 = nbAddKoukaPacket(&k, startframe, v10, uniqueid);
  v7->pFormation = *form;
  v13 = effPCPBossONGYCreate(v7);
  v12->type = 41;
  v12->data1->p = v13;
  return v12;
}

// 0x197e2c0
nbKoukaPacket_t *nbAddPadShockPacket(s32 startframe, s32 uniqueid, s32 mode, s32 pow, s32 time) {
  s16 v6;
  s16 v7;
  s16 v8;
  nbKoukaPacket_t_o *result;
  struct System_Int16_array *s;
  struct System_Int16_array *v15;
  struct System_Int16_array *v17;
  nbKoukaProcessData_t_o *k;

  v6 = time;
  v7 = pow;
  v8 = mode;
  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 52;
  s = result->data1->s;
  s->m_Items[0] = v8;
  v15 = result->data1->s;
  v15->m_Items[1] = v7;
  v17 = result->data2->s;
  v17->m_Items[0] = v6;
  return result;
}

// 0x19878f0
void nbAddPanelStockEndPacket(s32 startframe, s32 uniqueid) {
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  nbAddKoukaPacket(&k, startframe, 0, uniqueid)->type = 57;
}

// 0x19878a0
void nbAddPanelStockFadeOutPacket(s32 startframe, s32 uniqueid) {
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  nbAddKoukaPacket(&k, startframe, 0, uniqueid)->type = 56;
}

// 0x1986c30
nbKoukaPacket_t *nbAddPressPacket(s32 startframe, s32 uniqueid, f32 press) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 18;
  result->data1->f = press;
  return result;
}

// 0x1985d20
nbKoukaPacket_t *nbAddReturnKoukaPacket(s32 startframe, s32 uniqueid, nbParty_t **party, s32 dead) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 11;
  result->party = *party;
  result->data1->i = dead;
  return result;
}

// 0x1985520
nbKoukaPacket_t *nbAddRotKoukaPacket(s32 startframe, s32 uniqueid, s32 partyno, sdfVector4_t v, s32 speed) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  nbKoukaPacket_t_o *v15;
  nbKoukaPacket_t_o *v16;
  nbKoukaProcessData_t_o *k;
  UnityEngine_Vector4_o v19;

  w = v.w;
  z = v.z;
  y = v.y;
  x = v.x;
  k = nbGetKoukaProcessData(*&startframe);
  v15 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v19.x = x;
  v19.y = y;
  v19.z = z;
  v19.w = w;
  v16 = v15;
  v15->type = 3;
  v15->partyno = partyno;
  SDF_VU0__COPYVECTOR(&v15->v, v19);
  v16->data1->i = speed;
  return v16;
}

// 0x1985820
nbKoukaPacket_t *nbAddSakeKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form) {
  nbKoukaPacket_t_o *v8;
  f32 v9;
  nbKoukaPacket_t_o *v10;
  nbKoukaPacket_t_o *v14;
  nbKoukaProcessData_t_o *k;
  nbKoukaProcessData_t_o *KoukaProcessData;

  k = nbGetKoukaProcessData(*&startframe);
  v8 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v9 = (*form)->r * 0.9;
  v8->type = 13;
  v8->form = *form;
  v8->data1->f = fminf(v9, 100.0);
  v10 = v8;
  v8->data2->f = 0.3;
  KoukaProcessData = 0;
  v12 = nbCheckSePacket(startframe, 65552, 5);
  if (!v12)
  {
    KoukaProcessData = nbGetKoukaProcessData();
    v14 = nbAddKoukaPacket(&KoukaProcessData, startframe, 0, uniqueid);
    v14->type = 25;
    v14->data1->i = 65552;
  }
  return v10;
}

// 0x1985360
nbKoukaPacket_t *nbAddSePacket(s32 startframe, s32 uniqueid, u32 se) {
  s32 v7;
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = 0;
  v7 = nbCheckSePacket(startframe, se, 5);
  result = 0;
  if (!v7)
  {
    k = nbGetKoukaProcessData();
    result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
    result->type = 25;
    result->data1->i = se;
  }
  return result;
}

// 0x1986e20
nbKoukaPacket_t *nbAddSePacket2(s32 startframe, s32 uniqueid, u32 se) {
  s32 v7;
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = 0;
  v7 = nbCheckSePacket(startframe, se, 5);
  result = 0;
  if (!v7)
  {
    k = nbGetKoukaProcessData();
    result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
    result->type = 28;
    result->data1->i = se;
  }
  return result;
}

// 0x1986eb0
nbKoukaPacket_t *nbAddSePacketLock(s32 startframe, s32 uniqueid, u32 se) {
  s32 v7;
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = 0;
  v7 = nbCheckSePacket(startframe, se, 5);
  result = 0;
  if (!v7)
  {
    k = nbGetKoukaProcessData();
    result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
    result->type = 29;
    result->data1->i = se;
  }
  return result;
}

// 0x1985ee0
nbKoukaPacket_t *nbAddSkillColorOffPacket(s32 startframe, s32 uniqueid) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 14;
  return result;
}

// 0x1985e70
nbKoukaPacket_t *nbAddSkillColorOnPacket(s32 startframe, s32 uniqueid, s32 skillid, s32 para) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 54;
  result->data1->i = skillid;
  result->data2->i = para;
  return result;
}

// 0x1984bf0
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket(s32 startframe, s32 framelength, s32 uniqueid, effBTLCutHandle_t **cuteff) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, framelength, uniqueid);
  result->type = 0;
  result->cuteff = *cuteff;
  return result;
}

// 0x1984eb0
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket1(s32 startframe, s32 framelength, s32 uniqueid, effBTLCutHandle_t **cuteff) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, framelength, uniqueid);
  result->type = 26;
  result->cuteff = *cuteff;
  return result;
}

// 0x1984dc0
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket2(s32 startframe, s32 framelength, s32 uniqueid, effBTL_t **hbtl, s32 cutno, nbFormation_t **form, s32 j) {
  s16 v8;
  s16 v10;
  nbKoukaPacket_t_o *result;
  struct System_Int16_array *s;
  struct System_Int16_array *v19;
  nbKoukaProcessData_t_o *k;

  v8 = j;
  v10 = cutno;
  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, framelength, uniqueid);
  if (!framelength)
    result->flag |= 1u;
  result->type = 21;
  result->cuteff = 0;
  result->data1->p = *hbtl;
  s = result->data2->s;
  s->m_Items[0] = v10;
  v19 = result->data2->s;
  v19->m_Items[1] = v8;
  result->form = *form;
  return result;
}

// 0x1984c50
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket3(s32 startframe, s32 uniqueid, u8 **bed, s32 cutno, nbFormation_t **form) {
  u16 v7;
  struct effBTLCutHandle_t_o *v11;
  s32 v12;
  u64 *v14;
  nbKoukaPacket_t_o *result;
  u32 v18;
  effBTL_t_o *hBTLEffect;
  nbKoukaProcessData_t_o *k;

  v7 = cutno;
  k = 0;
  hBTLEffect = 0;
  hBTLEffect = effBTLCreate(bed);
  v11 = effBTLCutCreate(&hBTLEffect, v7, *form, 1u);
  v18 = effBTLGetCutEndFrame(&hBTLEffect, v7);
  v12 = v18;
  v14 = sub_8D3950(s32, &v18);
  Write_2930400("カット長 = {0:D}\n", v14);
  k = nbGetKoukaProcessData();
  result = nbAddKoukaPacket(&k, startframe, v12, uniqueid);
  result->type = 43;
  result->cuteff = 0;
  result->data1->p = hBTLEffect;
  result->form = *form;
  result->cuteff = v11;
  return result;
}

// 0x1985a50
nbKoukaPacket_t *nbAddSkillMotionKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 motion, s32 endtype, f32 ritu) {
  s16 v8;
  s16 v9;
  nbKoukaPacket_t_o *result;
  struct System_Int16_array *s;
  struct System_Int16_array *v17;
  nbKoukaProcessData_t_o *k;

  v8 = endtype;
  v9 = motion;
  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 55;
  result->form = *form;
  s = result->data1->s;
  s->m_Items[0] = v9;
  v17 = result->data1->s;
  v17->m_Items[1] = v8;
  result->data2->f = ritu;
  return result;
}

// 0x19870b0
nbKoukaPacket_t *nbAddSkillNamePacket(s32 startframe, s32 uniqueid, s32 id) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 49;
  result->data1->i = id;
  return result;
}

// 0x1985d90
nbKoukaPacket_t *nbAddSummonKoukaPacket(s32 startframe, s32 uniqueid, s32 side, s32 stockno, s32 formindex) {
  s16 v6;
  s16 v7;
  s16 v8;
  nbKoukaPacket_t_o *result;
  struct System_Int16_array *s;
  struct System_Int16_array *v15;
  struct System_Int16_array *v17;
  nbKoukaProcessData_t_o *k;

  v6 = formindex;
  v7 = stockno;
  v8 = side;
  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 12;
  s = result->data1->s;
  s->m_Items[0] = v8;
  v15 = result->data1->s;
  v15->m_Items[1] = v7;
  v17 = result->data2->s;
  v17->m_Items[0] = v6;
  return result;
}

// 0x19853f0
nbKoukaPacket_t *nbAddTargetMoveKoukaPacket(s32 startframe, s32 uniqueid, s32 partyno, sdfVector4_t pos, f32 speed) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  nbKoukaPacket_t_o *v15;
  nbKoukaPacket_t_o *v16;
  nbKoukaProcessData_t_o *k;
  UnityEngine_Vector4_o v19;

  w = pos.w;
  z = pos.z;
  y = pos.y;
  x = pos.x;
  k = nbGetKoukaProcessData(*&startframe);
  v15 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v19.x = x;
  v19.y = y;
  v19.z = z;
  v19.w = w;
  v16 = v15;
  v15->type = 1;
  v15->partyno = partyno;
  SDF_VU0__COPYVECTOR(&v15->v, v19);
  v16->data1->f = speed;
  return v16;
}

// 0x1985730
nbKoukaPacket_t *nbAddUnitAKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 a, s32 frame) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 7;
  result->form = *form;
  result->data1->i = frame;
  result->data2->i = a;
  return result;
}

// 0x1985640
nbKoukaPacket_t *nbAddUnitColKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 col, s32 frame) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 5;
  result->form = *form;
  result->data1->i = frame;
  result->data2->i = col;
  return result;
}

// 0x19857b0
nbKoukaPacket_t *nbAddUnitHomeAKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 frame) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 8;
  result->form = *form;
  result->data1->i = frame;
  return result;
}

// 0x19856c0
nbKoukaPacket_t *nbAddUnitHomeColKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 frame) {
  nbKoukaPacket_t_o *result;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  result = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  result->type = 6;
  result->form = *form;
  result->data1->i = frame;
  return result;
}

// 0x1988910
s32 nbMakeBadDamagePacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 bad) {
  nbKoukaPacket_t_o *v10;
  nbKoukaPacket_t_o *v12;
  s32 v13;
  nbKoukaPacket_t_o *v15;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  v10 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v10->type = 10;
  v10->form = *form;
  v10->data1->f = 17.0;
  v10->data2->i = bad;
  k = nbGetKoukaProcessData(v10);
  v12 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v12->type = 23;
  v12->form = *form;
  if (bad > 0x20)
  {
    if (bad > 0x80)
    {
      switch (bad)
      {
        case 0x100u:
          v13 = 9;
          break;
        case 0x200u:
          v13 = 10;
          break;
        case 0x400u:
          v13 = 11;
          break;
        default:
          v13 = 0;
          break;
      }
    }
    else
    {
      v13 = 8 * (bad == 128);
      if (bad == 64)
        v13 = 7;
    }
  }
  else if (bad > 8)
  {
    if (bad == 32)
      v13 = 6;
    else
      v13 = 0;
    if (bad == 16)
      v13 = 5;
  }
  else if (bad - 1 >= 4)
  {
    v13 = 4 * (bad == 8);
  }
  else
  {
    v13 = dword_32C3BF0[bad - 1];
  }
  v12->data1->i = v13;
  k = nbGetKoukaProcessData(v12);
  v15 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v15->type = 19;
  v15->form = *form;
  v15->data1->i = 1;
  v15->data2->i = bad;
  return 1;
}

// 0x197efc0
s32 nbMakeBadKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t **form) {
  s32 formindex;
  nbKoukaPacket_t_o *BadStat;
  u32 v9;
  nbKoukaPacket_t_o *v12;
  nbKoukaPacket_t_o *v14;
  nbKoukaProcessData_t_o *k;

  formindex = (*form)->formindex;
  BadStat = nbGetBadStat(formindex);
  v9 = BadStat;
  if (BadStat)
  {
    k = nbGetKoukaProcessData(BadStat);
    BadStat = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
    BadStat->type = 19;
    BadStat->form = *form;
    BadStat->data1->i = 0;
    BadStat->data2->i = 4095;
  }
  if (formindex <= 15)
  {
    if (v9 <= 0x20)
    {
      if (v9 > 4)
      {
        if (((1LL << v9) & 0x100010100LL) == 0)
          return 1;
      }
      else if (((1 << v9) & 0x16) == 0)
      {
        return 1;
      }
      goto LABEL_18;
    }
    if (v9 <= 0x100)
    {
      if (v9 != 64 && v9 != 128 && v9 != 256)
        return 1;
LABEL_18:
      k = nbGetKoukaProcessData(BadStat);
      v12 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
      v12->type = 20;
      v12->form = *form;
      k = nbGetKoukaProcessData(v12);
      v14 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
      v14->type = 24;
      v14->form = *form;
      return 1;
    }
    if (v9 == 512 || v9 == 2048 || v9 == 1024)
      goto LABEL_18;
  }
  return 1;
}

// 0x1988490
s32 nbMakeDamagePacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type, s32 hp, s32 mp, s32 badstat, s32 hiteff, s32 dead, s32 deadtype, s32 moji, s32 animeoff) {
  s32 formindex;
  s32 v19;
  s32 v21;
  s32 v22;
  nbFormation_t_o **v23;
  s32 v24;
  s32 v25;
  nbKoukaPacket_t_o *v27;
  s32 v28;
  nbKoukaPacket_t_o *v30;
  s32 v32;
  s32 v33;
  nbFormation_t_o **v34;
  s32 v35;
  nbKoukaPacket_t_o *v39;
  struct nbKoukaData_t_o *data1;
  nbKoukaProcessData_t_o *k;

  formindex = (*form)->formindex;
  v19 = startframe;
  if (formindex > 15)
    goto LABEL_28;
  if (dead)
  {
    *&startframe = nbMakeDeadVisualPacket(startframe, uniqueid, form, deadtype, 1, *&mp);
    if (!hiteff)
      goto LABEL_28;
LABEL_22:
    if (type != 2)
    {
      if (type == 1)
      {
        v21 = v19;
        v22 = uniqueid;
        v23 = form;
        v24 = 7;
        goto LABEL_27;
      }
      if (type)
        goto LABEL_28;
    }
    v21 = v19;
    v22 = uniqueid;
    v23 = form;
    v24 = 0;
LABEL_27:
    *&startframe = nbAddHitEffKoukaPacket(v21, v22, v23, v24, *&hp);
    goto LABEL_28;
  }
  if (badstat <= 32)
  {
    if (badstat <= 4)
    {
      if (badstat > 4 || ((1 << badstat) & 0x16) == 0)
        goto LABEL_52;
    }
    else if (((1LL << badstat) & 0x100010100LL) == 0)
    {
      goto LABEL_52;
    }
LABEL_20:
    *&startframe = nbMakeBadDamagePacket(startframe, uniqueid, form, badstat, *&hp);
    goto LABEL_21;
  }
  if (badstat <= 256)
  {
    if (badstat != 64 && badstat != 128 && badstat != 256)
      goto LABEL_52;
    goto LABEL_20;
  }
  if (badstat == 512)
  {
    k = nbGetKoukaProcessData(*&startframe);
    *&startframe = nbAddKoukaPacket(&k, v19, 0, uniqueid);
    *(*&startframe + 20LL) = 45;
    *(*&startframe + 48LL) = *form;
    *(*(*&startframe + 88LL) + 32LL) = 0;
    if (hiteff)
      goto LABEL_22;
    goto LABEL_28;
  }
  if (badstat == 2048 || badstat == 1024)
    goto LABEL_20;
LABEL_52:
  if ((type - 1) >= 2 && type)
  {
    if (type == 3)
    {
      k = nbGetKoukaProcessData(*&startframe);
      v39 = nbAddKoukaPacket(&k, v19, 0, uniqueid);
      v39->type = 53;
      data1 = v39->data1;
      v39->form = *form;
      data1->f = 10.0;
      k = 0;
      *&startframe = nbCheckSePacket(v19, 65538, 5);
      if (!startframe)
      {
        k = nbGetKoukaProcessData(*&startframe);
        *&startframe = nbAddKoukaPacket(&k, v19, 0, uniqueid);
        *(*&startframe + 20LL) = 25;
        *(*(*&startframe + 88LL) + 32LL) = 65538;
        if (hiteff)
          goto LABEL_22;
        goto LABEL_28;
      }
    }
LABEL_21:
    if (!hiteff)
      goto LABEL_28;
    goto LABEL_22;
  }
  k = nbGetKoukaProcessData(*&startframe);
  *&startframe = nbAddKoukaPacket(&k, v19, 0, uniqueid);
  *(*&startframe + 20LL) = 9;
  *(*&startframe + 48LL) = *form;
  *(*(*&startframe + 88LL) + 36LL) = 1099431936;
  *(*(*&startframe + 96LL) + 32LL) = 1;
  if (hiteff)
    goto LABEL_22;
LABEL_28:
  v25 = v19 + animeoff + 1;
  if (((mp | hp) & 0x80000000) == 0)
  {
    if (moji && formindex <= 15)
      *&startframe = nbAddNumEffKoukaPacket(v25, 45, uniqueid, form, hp, mp, 4, *&hiteff);
    k = nbGetKoukaProcessData(*&startframe);
    v27 = nbAddKoukaPacket(&k, v19, 0, uniqueid);
    v27->type = 17;
    v27->form = *form;
    v27->data1->i = 0;
    v27->data2->i = -hp;
    v28 = -mp;
    k = nbGetKoukaProcessData(v27);
    v30 = nbAddKoukaPacket(&k, v19, 0, uniqueid);
    v30->type = 17;
LABEL_38:
    v30->form = *form;
    v30->data1->i = 1;
LABEL_39:
    v30->data2->i = v28;
    goto LABEL_40;
  }
  if ((mp & 0x80000000) == 0)
  {
    if (moji && formindex <= 15)
      *&startframe = nbAddNumEffKoukaPacket(v25, 45, uniqueid, form, mp, 0, 1, *&hiteff);
    v28 = -mp;
    k = nbGetKoukaProcessData(*&startframe);
    v30 = nbAddKoukaPacket(&k, v19, 0, uniqueid);
    v30->type = 17;
    goto LABEL_38;
  }
  if ((hp & 0x80000000) == 0)
  {
    if (moji && formindex <= 15)
      *&startframe = nbAddNumEffKoukaPacket(v25, 45, uniqueid, form, hp, 0, 0, *&hiteff);
    v28 = -hp;
    k = nbGetKoukaProcessData(*&startframe);
    v30 = nbAddKoukaPacket(&k, v19, 0, uniqueid);
    v30->type = 17;
    v30->form = *form;
    v30->data1->i = 0;
    goto LABEL_39;
  }
LABEL_40:
  if (moji)
  {
    if (type == 2)
    {
      v32 = v19 + animeoff + 1;
      v33 = uniqueid;
      v34 = form;
      v35 = 1;
      goto LABEL_45;
    }
    if (type == 1)
    {
      v32 = v19 + animeoff + 1;
      v33 = uniqueid;
      v34 = form;
      v35 = 2;
LABEL_45:
      nbAddMojiEffKoukaPacket(v32, 45, v33, v34, v35, *&mp);
    }
  }
  return 1;
}

// 0x1988de0
s32 nbMakeDeadPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 deadchk) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbParty_t_array *party;
  nbMainProcessData_t_o *v14;
  nbParty_t_o *v16;
  datUnitWork_t_o *UnitWorkPointer;
  datUnitWork_t_o *v19;
  nbFormation_t_o *v20;
  nbKoukaPacket_t_o *v23;
  struct nbKoukaData_t_o *data1;
  nbKoukaProcessData_t_o *k;

  MainProcessData = nbGetMainProcessData();
  if ((~(*form)->stat & 0x41) == 0)
  {
    party = MainProcessData->party;
    v14 = MainProcessData;
    v16 = party->m_Items[(*form)->partyindex];
    UnitWorkPointer = nbGetUnitWorkPointer(v14, v16);
    v16->flag |= 0x30u;
    v19 = UnitWorkPointer;
    v20 = *form;
    v21 = nbCheckEventDead(v20);
    if ()
    {
      if (deadchk != 1)
        return 1;
      goto LABEL_20;
    }
    if (deadchk == 1 || (v19->flag & 4) == 0)
    {
LABEL_20:
      k = nbGetKoukaProcessData();
      v23 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
      v23->type = 11;
      data1 = v23->data1;
      v23->party = v16;
      data1->i = 1;
    }
  }
  return 1;
}

// 0x1987e10
s32 nbMakeDeadVisualPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 deadtype, s32 deadpcm) {
  nbFormation_t_o *v13;
  s32 v17;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  nbKoukaPacket_t_o *v22;
  nbKoukaPacket_t_o *v24;
  s32 v25;
  nbKoukaPacket_t_o *v27;
  s32 v29;
  datUnitWork_t_o *v30;
  s32 v35;
  s32 id;
  struct datUnitMotion_s_array *motion;
  u32 motion_no;
  nbKoukaPacket_t_o *v44;
  struct nbKoukaData_t_o *data1;
  s32 v47;
  nbFormation_t_o *v48;
  s32 v49;
  s32 v50;
  s32 DeadEventFadeTime;
  s32 DeadEventFadeOutFrame;
  s32 DeadEventFadeStopFrame;
  s32 v55;
  s32 v56;
  nbKoukaPacket_t_o *v58;
  s32 v59;
  nbKoukaProcessData_t_o *KoukaProcessData;
  nbKoukaPacket_t_o *v63;
  s32 v65;
  nbFormation_t_o *v68;
  s32 v69;
  s32 v71;
  s32 v72;
  s32 v73;
  s32 v74;
  nbKoukaPacket_t_o *v76;
  nbKoukaProcessData_t_o *k;

  nbGetMainProcessData();
  v13 = *form;
  v14 = nbCheckEventDead(v13);
  if ()
    v17 = 2;
  else
    v17 = deadtype;
  if (v17)
  {
    if (v17 != 2)
    {
      if (v17 == 1)
      {
        formindex = (*form)->formindex;
        UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
        if ((UnitWorkFromFormindex->flag & 4) == 0)
        {
          k = nbGetKoukaProcessData(UnitWorkFromFormindex);
          v22 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
          v22->type = 5;
          v22->form = *form;
          v22->data1->i = 2;
          v22->data2->i = 0;
          k = nbGetKoukaProcessData(v22);
          v24 = nbAddKoukaPacket(&k, startframe + 2, 0, uniqueid);
          v24->type = 7;
          v24->form = *form;
          v24->data1->i = 2;
          v24->data2->i = 0;
        }
        nbAddHitEffKoukaPacket(startframe + 1, uniqueid, form, 6);
        v25 = 65540;
        if (!deadpcm)
          goto LABEL_56;
      }
      else
      {
        v25 = 0;
        if (!deadpcm)
          goto LABEL_56;
      }
      goto LABEL_54;
    }
    v35 = (*form)->formindex;
    id = nbGetUnitWorkFromFormindex(v35)->id;
    motion = Get(id, 0)->motion;
    motion_no = motion->m_Items[23]->motion_no;
    BadKaifukuPacket = nbMakeBadKaifukuPacket(startframe, uniqueid, form);
    k = nbGetKoukaProcessData();
    v44 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
    if (motion_no)
    {
      v44->type = 27;
      v44->form = *form;
      data1 = v44->data1;
      v47 = 1;
    }
    else
    {
      v44->type = 10;
      v44->form = *form;
      v44->data1->f = 30.0;
      data1 = v44->data2;
      v47 = -1;
    }
    data1->i = v47;
    v48 = *form;
    else
    {
      v49 = nbCheckDeadEvent(*form);
      if (v49)
      {
LABEL_43:
        v50 = v49;
        DeadEventFadeTime = nbGetDeadEventFadeTime(v50);
        DeadEventFadeOutFrame = nbGetDeadEventFadeOutFrame(v50);
        DeadEventFadeStopFrame = nbGetDeadEventFadeStopFrame(v50);
        DeadEventFadeInFrame = nbGetDeadEventFadeInFrame(v50);
        v55 = DeadEventFadeInFrame;
        v56 = DeadEventFadeTime + startframe;
        k = nbGetKoukaProcessData();
        v58 = nbAddKoukaPacket(&k, v56, 0, uniqueid);
        v58->type = 47;
        v58->data1->i = DeadEventFadeOutFrame;
        v59 = DeadEventFadeOutFrame + v56;
        v58->data2->i = 1;
        if (v55 >= 1)
        {
          k = nbGetKoukaProcessData(v58);
          v58 = nbAddKoukaPacket(&k, v59 + DeadEventFadeStopFrame + 2, 0, uniqueid);
          v58->type = 48;
          v58->data1->i = v55;
          v58->data2->i = 1;
        }
        KoukaProcessData = nbGetKoukaProcessData(v58);
        k = KoukaProcessData;
        v63 = nbAddKoukaPacket(&k, v59 + DeadEventFadeStopFrame - 3, 0, uniqueid);
        KoukaProcessData->data->actionstackp = 0;
        KoukaProcessData->data->eventno = v63->data1->i;
        KoukaProcessData->data->endtype = 7;
        v63->type = 46;
        v63->form = *form;
        v63->data1->i = v50;
        v25 = 0x10000;
        if (!deadpcm)
          goto LABEL_56;
        goto LABEL_54;
      }
    }
    goto LABEL_53;
  }
  k = nbGetKoukaProcessData();
  v27 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v27->type = 10;
  v27->form = *form;
  v27->data1->f = 17.0;
  v27->data2->i = 0;
  v29 = (*form)->formindex;
  else
  {
    v30 = nbGetUnitWorkFromFormindex(v29);
    if ((v30->flag & 4) == 0)
      goto LABEL_25;
  }
LABEL_53:
  v25 = 0x10000;
  if (!deadpcm)
    goto LABEL_56;
LABEL_54:
  v65 = startframe + 7;
  nbAddDeadPcmPacket(startframe + 7, uniqueid, form);
  if (v25)
  {
    k = 0;
    v67 = nbCheckSePacket(v65, v25, 5);
    if (!v67)
    {
      k = nbGetKoukaProcessData();
      v76 = nbAddKoukaPacket(&k, v65, 0, uniqueid);
      v76->type = 25;
      v76->data1->i = v25;
      v68 = *form;
      if (((*form)->stat & 0x100) == 0)
        return 1;
LABEL_57:
      v69 = v68->formindex;
      else if ((nbGetUnitWorkFromFormindex(v69)->flag & 4) == 0)
      {
LABEL_60:
        v71 = 150;
        v72 = 20;
        v73 = startframe;
        v74 = uniqueid;
LABEL_65:
        nbAddPadShockPacket(v73, v74, 1, v71, v72);
        return 1;
      }
      v71 = 250;
      v73 = startframe;
      v74 = uniqueid;
      v72 = 30;
      goto LABEL_65;
    }
  }
LABEL_56:
  v68 = *form;
  if (((*form)->stat & 0x100) != 0)
    goto LABEL_57;
  return 1;
}

// 0x1988ab0
s32 nbMakeFlyBadPacket(s32 startframe, s32 uniqueid, nbFormation_t **form) {
  nbKoukaPacket_t_o *v8;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  v8 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v8->type = 45;
  v8->form = *form;
  v8->data1->i = 0;
  return 1;
}

// 0x1988b20
s32 nbMakeKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type, s32 hp, s32 mp, u32 badstat) {
  s32 formindex;
  s32 v15;
  nbKoukaPacket_t_o *v17;
  nbKoukaPacket_t_o *v19;
  nbKoukaPacket_t_o *v21;
  nbKoukaPacket_t_o *v26;
  nbKoukaProcessData_t_o *k;

  formindex = (*form)->formindex;
  v15 = startframe;
  if (formindex <= 15)
  {
    if (type == 3)
    {
      k = nbGetKoukaProcessData(*&startframe);
      v21 = nbAddKoukaPacket(&k, v15, 0, uniqueid);
      v21->type = 5;
      v21->form = *form;
      v21->data1->i = 10;
      v21->data2->i = -2138641509;
      k = nbGetKoukaProcessData(v21);
      *&startframe = nbAddKoukaPacket(&k, v15 + 10, 0, uniqueid);
      *(*&startframe + 20LL) = 6;
      *(*&startframe + 48LL) = *form;
      *(*(*&startframe + 88LL) + 32LL) = 10;
      if (((mp | hp) & 0x80000000) == 0)
        goto LABEL_6;
      goto LABEL_12;
    }
    if (type == 1)
      *&startframe = nbAddHitEffKoukaPacket(startframe, uniqueid, form, 2, *&hp);
  }
  if (((mp | hp) & 0x80000000) == 0)
  {
LABEL_6:
    if (formindex <= 15)
    {
      if ((type & 0xFFFFFFFE) != 2)
        nbDelAllMojiNumEffectKoukaPacket(form, 0, form);
      *&startframe = nbAddNumEffKoukaPacket(v15 + 1, 45, uniqueid, form, hp, mp, 5);
    }
    k = nbGetKoukaProcessData(*&startframe);
    v17 = nbAddKoukaPacket(&k, v15, 0, uniqueid);
    v17->type = 17;
    v17->form = *form;
    v17->data1->i = 0;
    v17->data2->i = hp;
    k = nbGetKoukaProcessData(v17);
    v19 = nbAddKoukaPacket(&k, v15, 0, uniqueid);
    v19->type = 17;
LABEL_16:
    v19->form = *form;
    v19->data1->i = 1;
    v19->data2->i = mp;
    goto LABEL_17;
  }
LABEL_12:
  if ((mp & 0x80000000) == 0)
  {
    if (formindex <= 15)
      *&startframe = nbAddNumEffKoukaPacket(v15 + 1, 45, uniqueid, form, mp, 0, 3);
    k = nbGetKoukaProcessData(*&startframe);
    v19 = nbAddKoukaPacket(&k, v15, 0, uniqueid);
    v19->type = 17;
    goto LABEL_16;
  }
  if ((hp & 0x80000000) == 0)
  {
    if (formindex <= 15)
      *&startframe = nbAddNumEffKoukaPacket(v15 + 1, 45, uniqueid, form, hp, 0, 2);
    k = nbGetKoukaProcessData(*&startframe);
    v26 = nbAddKoukaPacket(&k, v15, 0, uniqueid);
    v26->type = 17;
    v26->form = *form;
    v26->data1->i = 0;
    v26->data2->i = hp;
    if (badstat)
      goto LABEL_18;
    return 1;
  }
LABEL_17:
  if (badstat)
LABEL_18:
    nbMakeBadKaifukuPacket(v15 + 1, uniqueid, form, *&type);
  return 1;
}

// 0x198a6c0
s32 nbMakeNegoBackPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, nbFormation_t **target) {
  s64 v10;
  s64 v11;
  s32 partyindex;
  nbKoukaPacket_t_o *v15;
  nbKoukaPacket_t_o *v16;
  nbKoukaPacket_t_o *v19;
  nbKoukaPacket_t_o *v21;
  UnityEngine_Vector4_o v23;
  UnityEngine_Vector4_o v24;
  UnityEngine_Vector4_o p;
  nbKoukaProcessData_t_o *k;
  UnityEngine_Vector4_o v27;

  *&p.x = 0;
  *&p.z = 0;
  *&v24.x = 0;
  *&v24.z = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v24.x, 0.0, 0.0, 0.0, 0.0);
  *&v23.x = 0;
  *&v23.z = 0;
  sub_854690(&v23.x, 0.0, 0.0, 1.0, 0.0);
  SDF_VU0__LOADVECTOR((*target)->rot, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR(v23);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&p);
  nbMakeUnitMoveGetCyDist(form, target);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__SCALEVECTOR((*form)->r * (*form)->scl, 0);
  SDF_VU0__LOADVECTOR_B((*form)->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v24);
  v10 = *&v24.x;
  v11 = *&v24.z;
  partyindex = (*form)->partyindex;
  k = nbGetKoukaProcessData();
  v15 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  *&v27.x = v10;
  *&v27.z = v11;
  v16 = v15;
  v15->type = 1;
  v15->partyno = partyindex;
  SDF_VU0__COPYVECTOR(&v15->v, v27);
  v16->data1->f = 0.05;
  k = nbGetKoukaProcessData();
  v19 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v19->type = 5;
  v19->form = *form;
  v19->data1->i = 5;
  v19->data2->i = 0;
  k = nbGetKoukaProcessData(v19);
  v21 = nbAddKoukaPacket(&k, startframe + 4, 0, uniqueid);
  v21->type = 7;
  v21->form = *form;
  v21->data1->i = 5;
  v21->data2->i = 0;
  return 1;
}

// 0x198a900
s32 nbMakeNegoForwardPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, nbFormation_t **target) {
  f32 CyDist;
  s64 v11;
  s64 v12;
  s32 partyindex;
  nbKoukaPacket_t_o *v16;
  nbKoukaPacket_t_o *v17;
  nbKoukaPacket_t_o *v20;
  nbKoukaPacket_t_o *v22;
  nbKoukaPacket_t_o *v24;
  UnityEngine_Vector4_o v26;
  UnityEngine_Vector4_o v27;
  UnityEngine_Vector4_o p;
  nbKoukaProcessData_t_o *k;
  UnityEngine_Vector4_o v30;

  *&p.x = 0;
  *&p.z = 0;
  *&v27.x = 0;
  *&v27.z = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v27.x, 0.0, 0.0, 0.0, 0.0);
  *&v26.x = 0;
  *&v26.z = 0;
  sub_854690(&v26.x, 0.0, 0.0, 1.0, 0.0);
  SDF_VU0__LOADVECTOR((*target)->rot, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR(v26);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&p);
  CyDist = nbMakeUnitMoveGetCyDist(form, target);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__SCALEVECTOR(CyDist + (((*target)->r * (*target)->scl) + 100.0), 0);
  SDF_VU0__LOADVECTOR_B((*target)->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v27);
  v11 = *&v27.x;
  v12 = *&v27.z;
  partyindex = (*form)->partyindex;
  k = nbGetKoukaProcessData();
  v16 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  *&v30.x = v11;
  *&v30.z = v12;
  v17 = v16;
  v16->type = 1;
  v16->partyno = partyindex;
  SDF_VU0__COPYVECTOR(&v16->v, v30);
  v17->data1->f = 0.05;
  k = nbGetKoukaProcessData();
  v20 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v20->type = 5;
  v20->form = *form;
  v20->data1->i = 0;
  v20->data2->i = 0;
  k = nbGetKoukaProcessData(v20);
  v22 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v22->type = 8;
  v22->form = *form;
  v22->data1->i = 5;
  k = nbGetKoukaProcessData(v22);
  v24 = nbAddKoukaPacket(&k, startframe + 4, 0, uniqueid);
  v24->type = 6;
  v24->form = *form;
  v24->data1->i = 5;
  return 1;
}

// 0x198a3d0
s32 nbMakeNegoWorkPosPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, nbFormation_t **target) {
  f32 CyDist;
  s64 v11;
  s64 v12;
  s32 partyindex;
  nbKoukaPacket_t_o *v16;
  nbKoukaPacket_t_o *v17;
  s64 v18;
  s64 v19;
  s32 v20;
  nbKoukaPacket_t_o *v23;
  nbKoukaPacket_t_o *v24;
  nbKoukaPacket_t_o *v27;
  nbKoukaPacket_t_o *v29;
  UnityEngine_Vector4_o v31;
  UnityEngine_Vector4_o v32;
  UnityEngine_Vector4_o p;
  nbKoukaProcessData_t_o *k;
  UnityEngine_Vector4_o v35;
  UnityEngine_Vector4_o v36;

  *&p.x = 0;
  *&p.z = 0;
  *&v32.x = 0;
  *&v32.z = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v32.x, 0.0, 0.0, 0.0, 0.0);
  *&v31.x = 0;
  *&v31.z = 0;
  sub_854690(&v31.x, 0.0, 0.0, 1.0, 0.0);
  SDF_VU0__LOADVECTOR((*target)->rot, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR(v31);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&p);
  CyDist = nbMakeUnitMoveGetCyDist(form, target);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__SCALEVECTOR(
    CyDist
  + ((((*target)->r * (*target)->scl)
    + (((*form)->r * (*form)->scl) + ((*form)->r * (*form)->scl)))
   + 100.0),
    0);
  SDF_VU0__LOADVECTOR_B((*target)->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v32);
  v11 = *&v32.x;
  v12 = *&v32.z;
  partyindex = (*form)->partyindex;
  k = nbGetKoukaProcessData();
  v16 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  *&v35.x = v11;
  *&v35.z = v12;
  v17 = v16;
  v16->type = 1;
  v16->partyno = partyindex;
  SDF_VU0__COPYVECTOR(&v16->v, v35);
  v17->data1->f = 1.0;
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__SCALEVECTOR(-1.0);
  SDF_VU0__STOREVECTOR(&v32);
  v18 = *&v32.x;
  v19 = *&v32.z;
  v20 = (*form)->partyindex;
  k = nbGetKoukaProcessData();
  v23 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  *&v36.x = v18;
  *&v36.z = v19;
  v24 = v23;
  v23->type = 3;
  v23->partyno = v20;
  SDF_VU0__COPYVECTOR(&v23->v, v36);
  v24->data1->i = 100;
  k = nbGetKoukaProcessData();
  v27 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v27->type = 5;
  v27->form = *form;
  v27->data1->i = 0;
  v27->data2->i = 0;
  k = nbGetKoukaProcessData(v27);
  v29 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v29->type = 7;
  v29->form = *form;
  v29->data1->i = 0;
  v29->data2->i = 0;
  return 1;
}

// 0x1989050
s32 nbMakeNewPressPacket(s32 startframe, s32 uniqueid, s32 ptype, nbFormation_t **form) {
  nbMainProcessData_t_o *MainProcessData;
  s32 press4_p;
  s32 press4_ten;
  s32 v13;
  s32 v14;
  bool v15;
  _BOOL4 v16;
  s32 v17;
  s32 v18;
  s32 v19;
  s32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  s32 v24;
  s32 v25;
  s32 v26;
  s32 v27;

  MainProcessData = nbGetMainProcessData();
  press4_p = MainProcessData->press4_p;
  press4_ten = MainProcessData->press4_ten;
  v13 = 8 - press4_p;
  v14 = 8 - press4_ten;
  *&MainProcessData->press4_hansya = 0;
  if (ptype)
  {
    if (ptype == 1)
    {
      v15 = press4_p < press4_ten;
      v16 = press4_p < press4_ten;
      v17 = press4_p - (press4_p >= press4_ten);
      if (v15)
        v18 = -1;
      else
        v18 = 0;
      if (v15)
        v19 = 0;
      else
        v19 = -1;
      v20 = press4_ten - v16;
      if (v17 >= 9)
        v21 = v13;
      else
        v21 = v19;
      if (v20 >= 9)
        v22 = v14;
      else
        v22 = v18;
    }
    else
    {
      v25 = 0;
      v26 = 2;
      switch (ptype)
      {
        case 2:
        case 3:
          if (press4_p)
            v26 = 0;
          else
            v26 = -1;
          if (press4_p)
            v25 = -1;
          else
            v25 = 0;
          break;
        case 4:
        case 5:
          if (press4_p >= press4_ten)
          {
            v25 = -2;
          }
          else
          {
            v25 = press4_ten - 2 - press4_p;
            if (press4_ten - 2 >= press4_p)
              v25 = 0;
          }
          MainProcessData->press4_miss = 1;
          v26 = -2;
          break;
        case 6:
        case 7:
        case 13:
        case 14:
          v26 = -10;
          MainProcessData->press4_hansya = 1;
          v25 = -10;
          break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
          if (press4_p < press4_ten)
            v25 = 0;
          else
            v25 = -1;
          v26 = -1;
          break;
        case 15:
          break;
        case 16:
          v25 = 0;
          v26 = 4;
          break;
        case 17:
          v25 = 0;
          v26 = 3;
          break;
        default:
          v26 = 0;
          v25 = 0;
          break;
      }
      v27 = v26 + press4_ten;
      if (v25 + press4_p >= 9)
        v21 = 8 - press4_p;
      else
        v21 = v25;
      if (v27 >= 9)
        v22 = v14;
      else
        v22 = v26;
    }
  }
  else
  {
    v15 = press4_p < press4_ten;
    v23 = press4_p - (press4_p >= press4_ten);
    if (v15)
      v24 = 0;
    else
      v24 = -1;
    if (v23 >= 9)
      v21 = v13;
    else
      v21 = v24;
    if (press4_ten < 10)
      v22 = -1;
    else
      v22 = 8 - press4_ten;
  }
  nbAddNewPressPacket(startframe, uniqueid, v21, v22);
  return 1;
}

// 0x1988f70
s32 nbMakePressPacket(s32 startframe, s32 uniqueid, f32 press) {
  nbMainProcessData_t_o *MainProcessData;
  int16x4_t v9;
  s64 v10;
  f32 v11;
  nbKoukaPacket_t_o *v13;
  nbKoukaProcessData_t_o *k;

  MainProcessData = nbGetMainProcessData();
  v10 = 42;
  if ((MainProcessData->stat & 8) == 0)
    v10 = 40;
  v9.n64_u16[0] = *(&MainProcessData->klass + v10);
  v11 = press / vmovl_s16(v9).n128_i32[0];
  k = nbGetKoukaProcessData(MainProcessData);
  v13 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v13->type = 18;
  v13->data1->f = v11;
  return 1;
}

// 0x1987bc0
s32 nbMakeReturnPacket(s32 startframe, s32 uniqueid, nbParty_t **party) {
  const char *name;
  struct nbFormation_t_o *v11;
  nbKoukaPacket_t_o *v13;
  struct nbKoukaData_t_o *data1;
  nbKoukaPacket_t_o *v16;
  struct nbKoukaData_t_o *v17;
  nbKoukaPacket_t_o *v19;
  nbKoukaProcessData_t_o *k;

  MainProcessData = nbGetMainProcessData();
  name = MainProcessData->name;
  v11 = *&name[8 * (*party)->formindex + 32];
  (*party)->flag |= 0x20u;
  k = nbGetKoukaProcessData();
  v13 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v13->type = 5;
  data1 = v13->data1;
  v13->form = v11;
  data1->i = 6;
  v13->data2->i = 0;
  k = nbGetKoukaProcessData(v13);
  v16 = nbAddKoukaPacket(&k, startframe + 6, 0, uniqueid);
  v16->type = 7;
  v17 = v16->data1;
  v16->form = v11;
  v17->i = 6;
  v16->data2->i = 0;
  k = nbGetKoukaProcessData(v16);
  v19 = nbAddKoukaPacket(&k, startframe + 13, 0, uniqueid);
  v19->type = 11;
  v19->party = *party;
  v19->data1->i = 0;
  return 1;
}

// 0x1987940
s32 nbMakeSummonPacket(s32 startframe, s32 uniqueid, s32 side, s32 stockno, s32 formindex) {
  struct nbFormation_t_array *form;
  struct nbFormation_t_o *v15;
  nbKoukaPacket_t_o *Packet__nbAddSummonKoukaPacket;
  nbKoukaPacket_t_o *v18;
  struct nbKoukaData_t_o *data1;
  nbKoukaPacket_t_o *v21;
  struct nbKoukaData_t_o *v22;
  nbKoukaPacket_t_o *v24;
  struct nbKoukaData_t_o *v25;
  nbKoukaProcessData_t_o *k;

  form = nbGetMainProcessData()->form;
  v15 = form->m_Items[formindex];
  Packet__nbAddSummonKoukaPacket = nbAddSummonKoukaPacket(startframe, uniqueid, side, stockno, formindex);
  k = nbGetKoukaProcessData(Packet__nbAddSummonKoukaPacket);
  v18 = nbAddKoukaPacket(&k, startframe + 1, 0, uniqueid);
  v18->type = 5;
  data1 = v18->data1;
  v18->form = v15;
  data1->i = 0;
  v18->data2->i = 0;
  k = nbGetKoukaProcessData(v18);
  v21 = nbAddKoukaPacket(&k, startframe + 1, 0, uniqueid);
  v21->type = 8;
  v22 = v21->data1;
  v21->form = v15;
  v22->i = 15;
  k = nbGetKoukaProcessData(v21);
  v24 = nbAddKoukaPacket(&k, startframe + 16, 0, uniqueid);
  v24->type = 6;
  v25 = v24->data1;
  v24->form = v15;
  v25->i = 20;
  return 1;
}

// 0x1987ac0
s32 nbMakeUnitFadeInPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 col, s32 delay, s32 aframe, s32 colframe) {
  nbKoukaPacket_t_o *v16;
  nbKoukaPacket_t_o *v18;
  nbKoukaPacket_t_o *v20;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  v16 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v16->type = 5;
  v16->form = *form;
  v16->data1->i = 0;
  v16->data2->i = col;
  k = nbGetKoukaProcessData(v16);
  v18 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v18->type = 8;
  v18->form = *form;
  v18->data1->i = aframe;
  k = nbGetKoukaProcessData(v18);
  v20 = nbAddKoukaPacket(&k, delay + startframe, 0, uniqueid);
  v20->type = 6;
  v20->form = *form;
  v20->data1->i = colframe;
  return 1;
}

// 0x1987d40
s32 nbMakeUnitFadeOutPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 col, s32 delay, s32 colframe, s32 aframe) {
  nbKoukaPacket_t_o *v16;
  nbKoukaPacket_t_o *v18;
  nbKoukaProcessData_t_o *k;

  k = nbGetKoukaProcessData(*&startframe);
  v16 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
  v16->type = 5;
  v16->form = *form;
  v16->data1->i = colframe;
  v16->data2->i = col;
  k = nbGetKoukaProcessData(v16);
  v18 = nbAddKoukaPacket(&k, delay + startframe, 0, uniqueid);
  v18->type = 7;
  v18->form = *form;
  v18->data1->i = aframe;
  v18->data2->i = 0;
  return 1;
}

// 0x1989210
f32 nbMakeUnitMoveGetCyDist(nbFormation_t **i_form, nbFormation_t **t_form) {
  f32 v5;
  f32 v6;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 scl;
  f32 r;
  f32 v19;
  f32 result;
  unsigned __int128 v21;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  v21 = 0u;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v21, 0.0, 0.0, 0.0, 0.0);
  SDF_VU0__LOADVECTOR((*i_form)->rot, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR((*i_form)->center, 0);
  SDF_VU0__SCALEVECTOR((*i_form)->scl, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__LOADVECTOR_B((*i_form)->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v21);
  sub_854710(&v21, 1u);
  sub_854930(&v21, 1u);
  SDF_VU0__LOADVECTOR((*t_form)->rot, 0);
  ToMatrix();
  SDF_VU0__LOADVECTOR((*t_form)->center, 0);
  SDF_VU0__SCALEVECTOR((*t_form)->scl, 0);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__LOADVECTOR_B((*t_form)->pos, 0);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  sub_854710(&p, 1u);
  sub_854930(&p, 1u);
  sub_854710(&p, 1u);
  v6 = v5;
  sub_854710(&v21, 1u);
  v9 = v8;
  v10 = sdfFabs(v6 - v9);
  v11 = sdfAtan2(v10, 100.0);
  sub_854710(&p, 1u);
  v13 = v12;
  sub_854710(&v21, 1u);
  if (v13 >= v14)
  {
    v15 = v11 * 100.0;
    if ((v11 * 100.0) > 100.0)
      v15 = 100.0;
  }
  else
  {
    v15 = v11 * 50.0;
    if ((v11 * 50.0) > 50.0)
      v15 = 50.0;
  }
  v16 = v15 + 100.0;
  sub_854710(&(*i_form)->center, 2u);
  scl = (*i_form)->scl;
  r = (*i_form)->r;
  result = v16 + (v19 * scl);
  if (result < (scl * (r - (*i_form)->cr)))
    return scl * (r - (*i_form)->cr);
  return result;
}

// 0x1989510
s32 nbMakeUnitMovePacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 select, s32 movetype, f32 ritu) {
  f32 CyDist;
  nbMainProcessData_t_o *MainProcessData;
  nbFormation_t_o *v16;
  u64 *v18;
  nbMainProcessData_t_o *v20;
  u32 v22;
  u32 v23;
  s32 v24;
  s32 v25;
  s32 v26;
  s32 v27;
  s32 v28;
  s32 v29;
  f32 v31;
  nbFormation_t_o *v32;
  struct nbFormation_t_array *v33;
  f32 v35;
  f32 v37;
  f32 v40;
  nbFormation_t_o *v41;
  s32 formindex;
  _BOOL4 v43;
  s32 v44;
  s64 i;
  struct nbFormation_t_array *v46;
  u64 v47;
  struct nbFormation_t_array *v49;
  struct nbFormation_t_array *v51;
  struct nbFormation_t_array *v53;
  struct nbFormation_t_array *v56;
  u32 max_length;
  struct nbFormation_t_array *v58;
  struct nbFormation_t_array *v60;
  u32 v61;
  f32 v62;
  f32 v65;
  f32 v67;
  f32 v70;
  s32 partyindex;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  nbKoukaPacket_t_o *v77;
  nbKoukaPacket_t_o *v78;
  s32 v80;
  f32 v81;
  f32 v82;
  s32 v83;
  f32 v84;
  f32 v85;
  s32 v86;
  nbKoukaPacket_t_o *v88;
  nbKoukaPacket_t_o *v89;
  s32 v91;
  System_Object_array *v92;
  s32 v93;
  s64 *v94;
  s64 *v95;
  s32 v98;
  s64 *v99;
  s64 *v100;
  s32 v103;
  s64 *v104;
  s64 *v105;
  s32 v108;
  s64 *v109;
  s64 *v111;
  f32 v114;
  f32 v115;
  f32 v116;
  f32 v117;
  s32 v118;
  nbKoukaPacket_t_o *v121;
  nbKoukaPacket_t_o *v122;
  s32 v123;
  s32 v124;
  s32 v125;
  s32 v126;
  UnityEngine_Vector4_o v127;
  UnityEngine_Vector4_o v128;
  UnityEngine_Vector4_o v129;
  UnityEngine_Vector4_o v130;
  UnityEngine_Vector4_o v131;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v133;
  UnityEngine_Vector4_o v134;
  nbKoukaProcessData_t_o *k;
  UnityEngine_Vector4_o v136;
  UnityEngine_Vector4_o v137;
  UnityEngine_Vector4_o v138;
  UnityEngine_Vector4_o v139;

  CyDist = 0.0;
  *&v134.x = 0;
  *&v134.z = 0;
  *&v133.x = 0;
  *&v133.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v131.x = 0;
  *&v131.z = 0;
  *&v130.x = 0;
  *&v130.z = 0;
  *&v129.x = 0;
  *&v129.z = 0;
  *&v128.x = 0;
  *&v128.z = 0;
  *&v127.x = 0;
  *&v127.z = 0;
  sub_854690(&v134.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v133.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&p.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v131.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v130.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v129.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v128.x, 0.0, 0.0, 1.0, 0.0);
  else
  {
    MainProcessData = nbGetMainProcessData(nbMainProcess);
    v16 = *form;
    if (((*form)->stat & 0x40) == 0)
    {
LABEL_6:
      LOWORD(k) = v16->formindex;
      v18 = sub_8D3950(s16, &k);
      Write_2930400("formindex = {0:D}\n", v18);
      while (1)
        ;
    }
  }
  v20 = MainProcessData;
  SDF_VU0__LOADVECTOR(v16->orgrot);
  ToMatrix();
  SDF_VU0__LOADVECTOR(v128);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(&p);
  v22 = (select >> 1) & 1;
  v23 = (select & 1)
      + v22
      + ((select & 4) >> 2)
      + ((select & 8) >> 3)
      + ((select & 0x10) >> 4)
      + ((select & 0x20) >> 5)
      + ((select & 0x40) >> 6)
      + ((select & 0x80) >> 7);
  if ((select & 4) != 0)
    v22 = 2;
  if ((select & 8) != 0)
    v22 = 3;
  if ((select & 0x10) != 0)
    v22 = 4;
  if ((select & 0x20) != 0)
    v22 = 5;
  if ((select & 0x40) != 0)
    v22 = 6;
  v24 = v23 + ((select & 0x100) >> 8) + ((select & 0x200) >> 9) + ((select & 0x400) >> 10);
  if ((select & 0x80) != 0)
    v22 = 7;
  if ((select & 0x100) != 0)
    v22 = 8;
  if ((select & 0x200) != 0)
    v22 = 9;
  v25 = v24 + ((select & 0x800) >> 11) + ((select & 0x1000) >> 12);
  if ((select & 0x400) != 0)
    v22 = 10;
  if ((select & 0x800) != 0)
    v22 = 11;
  v26 = v25 + ((select & 0x2000) >> 13);
  if ((select & 0x1000) != 0)
    v22 = 12;
  v27 = v26 + ((select & 0x4000) >> 14);
  if ((select & 0x2000) != 0)
    v22 = 13;
  if ((select & 0x4000) != 0)
    v22 = 14;
  if ((select & 0x8000) != 0)
    v28 = 15;
  else
    v28 = v22;
  v29 = v27 + ((select & 0x8000) >> 15);
  if (v29)
  {
    if (movetype != 1)
    {
      if (movetype == 4)
        goto LABEL_70;
      if (movetype == 5)
        goto LABEL_45;
      if ((movetype - 2) > 3)
        return 1;
      if (v29 == 1)
      {
LABEL_70:
        v41 = *form;
        formindex = (*form)->formindex;
        if (formindex <= 3)
          v43 = v28 < 4;
        else
          v43 = (v28 - 4) < 0xA && formindex < 14;
        nbGetFormCenter(v41);
        SDF_VU0__STOREVECTOR(&v131);
        v53 = v20->form;
        nbGetFormCenter(v53->m_Items[v28]);
        SDF_VU0__STOREVECTOR(&v130);
        if (v43)
        {
          SDF_VU0__LOADVECTOR(v131);
          SDF_VU0__LOADVECTOR_B(v130);
          SDF_VU0__SUBVECTOR();
          SDF_VU0__SETVECTOR_Y(0.0);
          SDF_VU0__NORMALIZE();
          v56 = v20->form;
          max_length = v56->max_length;
          SDF_VU0__SCALEVECTOR(
            (v56->m_Items[v28]->r * v56->m_Items[v28]->scl) + ((*form)->cr * (*form)->scl),
            0);
          SDF_VU0__LOADVECTOR_B(v130);
          SDF_VU0__ADDVECTOR();
          sub_854710(&(*form)->fields, 1u);
          SDF_VU0__SETVECTOR_Y(v65);
          SDF_VU0__STOREVECTOR(&v134);
          SDF_VU0__LOADVECTOR(v130);
          SDF_VU0__LOADVECTOR_B(v131);
          SDF_VU0__SUBVECTOR();
          SDF_VU0__SETVECTOR_Y(0.0);
          SDF_VU0__NORMALIZE();
          SDF_VU0__STOREVECTOR(&v133);
          v67 = 40.0;
          goto LABEL_114;
        }
        if (movetype == 3)
        {
          v58 = v20->form;
          CyDist = nbMakeUnitMoveGetCyDist(form, &v58->m_Items[v28]);
        }
        SDF_VU0__LOADVECTOR(v131);
        SDF_VU0__LOADVECTOR_B(v130);
        SDF_VU0__SUBVECTOR();
        SDF_VU0__VECTOR_W_SET_ZERO();
        SDF_VU0__SETVECTOR_Y(0.0);
        SDF_VU0__NORMALIZE();
        v60 = v20->form;
        v61 = v60->max_length;
        SDF_VU0__SCALEVECTOR(
          CyDist
        + ((v60->m_Items[v28]->r * v60->m_Items[v28]->scl) + ((*form)->cr * (*form)->scl)),
          0);
        SDF_VU0__LOADVECTOR_B(v130);
        SDF_VU0__ADDVECTOR();
        sub_854710(&(*form)->fields, 1u);
        SDF_VU0__SETVECTOR_Y(v70);
        SDF_VU0__STOREVECTOR(&v134);
        SDF_VU0__COPYVECTOR_A_TO_B();
        SDF_VU0__LOADVECTOR(v130);
        SDF_VU0__SUBVECTOR();
        SDF_VU0__SETVECTOR_Y(0.0);
        SDF_VU0__NORMALIZE();
      }
      else
      {
LABEL_45:
        SDF_VU0__LOADIDENTITYVECTOR();
        if (((*form)->stat & 0x200) != 0)
          v31 = 200.0;
        else
          v31 = -200.0;
        SDF_VU0__SETVECTOR_Z(v31);
        SDF_VU0__VECTOR_W_SET_ZERO();
        SDF_VU0__STOREVECTOR(&v134);
        sub_854690(&v127.x, 0.0, 0.0, 0.0, 0.0);
        v136.w = v127.w;
        v136.x = 0.0;
        v136.y = 0.0;
        v136.z = 0.0;
        *&v127.x = 0;
        v127.z = 0.0;
        SDF_VU0__LOADVECTOR_B(v136);
        v44 = 0;
        for (i = 4; i != 20; ++i)
        {
          v46 = v20->form;
          v47 = i - 4;
          if ((*(*(&v46->obj.klass + i) + 136LL) & 8) != 0)
          {
            v49 = v20->form;
            if ((*(*(&v49->obj.klass + i) + 136LL) & 1) != 0)
            {
              v51 = v20->form;
              SDF_VU0__LOADVECTOR(*(*(&v51->obj.klass + i) + 16LL), 0);
              SDF_VU0__ADDVECTOR_B_A();
              ++v44;
            }
          }
        }
        SDF_VU0__STOREVECTOR_B(&v127);
        if (v44)
        {
          sub_854710(&v127, 0);
          sub_854930(&v127, 0);
          sub_854710(&v127, 1u);
          sub_854930(&v127, 1u);
          sub_854710(&v127, 2u);
          sub_854930(&v127, 2u);
          SDF_VU0__LOADVECTOR(v127);
          SDF_VU0__LOADVECTOR_B(v134);
          SDF_VU0__SUBVECTOR();
          SDF_VU0__SETVECTOR_Y(0.0);
          SDF_VU0__NORMALIZE();
          SDF_VU0__STOREVECTOR(&v133);
        }
        else
        {
          SDF_VU0__LOADIDENTITYVECTOR();
          if (((*form)->stat & 0x200) != 0)
            v62 = -1.0;
          else
            v62 = 1.0;
          SDF_VU0__SETVECTOR_Z(v62);
        }
      }
      SDF_VU0__STOREVECTOR(&v133);
      v67 = 20.0;
LABEL_114:
      partyindex = (*form)->partyindex;
      x = v134.x;
      y = v134.y;
      z = v134.z;
      w = v134.w;
      k = nbGetKoukaProcessData();
      v77 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
      v137.x = x;
      v137.y = y;
      v137.z = z;
      v137.w = w;
      v78 = v77;
      v77->type = 1;
      v77->partyno = partyindex;
      SDF_VU0__COPYVECTOR(&v77->v, v137);
      v78->data1->f = ritu * 0.2;
      v80 = (v67 * ritu);
      v82 = v133.x;
      v81 = v133.y;
      v83 = (*form)->partyindex;
      v85 = v133.z;
      v84 = v133.w;
      if (v80 >= 100)
        v86 = 100;
      else
        v86 = v80;
      k = nbGetKoukaProcessData();
      v88 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
      v138.x = v82;
      v138.y = v81;
      v138.z = v85;
      v138.w = v84;
      v89 = v88;
      v88->type = 3;
      v88->partyno = v83;
      SDF_VU0__COPYVECTOR(&v88->v, v138);
      v89->data1->i = v86;
      return 1;
    }
    if (v29 == 1)
    {
      v32 = *form;
      if (v28 != (*form)->formindex)
      {
        nbGetFormCenter(v32);
        SDF_VU0__COPYVECTOR_A_TO_C();
        v33 = v20->form;
        nbGetFormCenter(v33->m_Items[v28]);
        SDF_VU0__COPYVECTOR_C_TO_B();
        SDF_VU0__SUBVECTOR();
        SDF_VU0__SETVECTOR_Y(0.0);
        SDF_VU0__NORMALIZE();
        SDF_VU0__COPYVECTOR_A_TO_B();
        SDF_VU0__LOADVECTOR((*form)->orgrot, 0);
        ToMatrix();
        SDF_VU0__LOADVECTOR(v128);
        SDF_VU0__APPLYMATRIX();
        v35 = SDF_VU0__INNERPRODUCT();
        SDF_VU0__STOREVECTOR(&v129);
        v37 = SDF_DEGtoRAD(70.0);
        if (v35 >= sdfCos(v37))
        {
          SDF_VU0__STOREVECTOR_B(&v133);
        }
        else
        {
          dds3RotationArc();
          v40 = sdfAcos(v35);
          Lerp(70.0 / v40, 0);
          ToMatrix();
          SDF_VU0__LOADVECTOR(v129);
          SDF_VU0__APPLYMATRIX();
          SDF_VU0__STOREVECTOR(&v133);
        }
        if ((ritu * 25.0) >= 100)
          v91 = 100;
        else
          v91 = (ritu * 25.0);
        v92 = NewSpecific(object, 4u);
        sub_854710(&v133, 0);
        v126 = v93;
        v94 = sub_8D3950(f32, &v126);
        v95 = v94;
        v92->m_Items[0] = v95;
        sub_854710(&v133, 1u);
        v125 = v98;
        v99 = sub_8D3950(f32, &v125);
        v100 = v99;
        v92->m_Items[1] = v100;
        sub_854710(&v133, 2u);
        v124 = v103;
        v104 = sub_8D3950(f32, &v124);
        v105 = v104;
        v92->m_Items[2] = v105;
        sub_854710(&v133, 3u);
        v123 = v108;
        v109 = sub_8D3950(f32, &v123);
        v111 = v109;
        v92->m_Items[3] = v111;
        Write_2930544("rotv_rot {0:f}, {1:f}, {2:f}, {3:f}\n", v92, 0);
        v115 = v133.x;
        v114 = v133.y;
        v117 = v133.z;
        v116 = v133.w;
        v118 = (*form)->partyindex;
        k = nbGetKoukaProcessData();
        v121 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
        v139.x = v115;
        v139.y = v114;
        v139.z = v117;
        v139.w = v116;
        v122 = v121;
        v121->type = 3;
        v121->partyno = v118;
        SDF_VU0__COPYVECTOR(&v121->v, v139);
        v122->data1->i = v91;
      }
    }
  }
  return 1;
}
