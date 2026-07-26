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
        v21 = &StringLiteral_8992;
        type = 13;
      case 0x124u:
        if (skillid == 169)
        {
          v13 += 10;
          type = 20;
        }
        v20 = 15;
        break;
      case 0x125u:
        v21 = &StringLiteral_8999;
        type = 17;
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
      case 0x156u:
        v21 = &StringLiteral_9003;
        type = 22;
      case 0x157u:
        v21 = &StringLiteral_9005;
        type = 23;
      case 0x158u:
      default:
        if (id != 264)
        v21 = &StringLiteral_9000;
        type = 18;
    }
  }
  if (!id)
  {
    if (mottype == 12)
    {
      v22 = 65547;
      type = 19;
      v13 = 0x7FFF;
      k = 0;
      v23 = nbCheckSePacket(startframe, v22, 5);
      if (!v23)
      {
        k = nbGetKoukaProcessData();
        v25 = nbAddKoukaPacket(&k, startframe, 0, uniqueid);
        v25->type = 25;
        v25->data1->i = v22;
      }
      v20 = type;
    }
  }
  if (id == 258)
  {
    v21 = &StringLiteral_8993;
    type = 14;
  }
  if (id != 259)
  {
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
      case 3:
        v22 = 65548;
      case 4:
        v22 = 65549;
      case 5:
        v22 = 65550;
      case 6:
        v22 = 65551;
      case 13:
      case 14:
      case 15:
      case 16:
      case 17:
      case 18:
      case 20:
      case 21:
      case 22:
      case 23:
      default:
    }
  }
  if (skillid != 170)
  {
    v20 = 16;
  }
  v13 += 10;
  type = 21;
  v21 = &StringLiteral_8996;
  v22 = FindId(1, *v21);
  v20 = type;
  if (v22)
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
    nbGetKoukaProcessData();
    nbAddKoukaPacket(0, 0, 0, 0);
    effBTLSystemCreate(0, 0);
    effBTLSystemGetLength(0);
    nbCheckSePacket(0, 0, 0);
    return 0;
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
      }
      else
      {
        if (!first)
        {
          if (type != 4)
        }
      }
    }
    if (v15->uniqueid == uniqueid)
    {
      s = v15->data1->s;
      v14 = s->m_Items[0];
    }
  }
  v14 = 0;
  if (type != 4)
  k = 0;
  v20 = nbCheckSePacket(v10, 65546, 5);
  if (!v20)
  {
    k = nbGetKoukaProcessData();
    v22 = nbAddKoukaPacket(&k, v10, 0, uniqueid);
    v22->type = 25;
    v22->data1->i = 65546;
  }
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
  v32 = Find(transform, StringLiteral_21418, 0);
  gameObject = get_gameObject(v32);
  SetActive(gameObject, 0, 0);
  v34 = get_transform(HitNum, 0);
  v35 = Find(v34, StringLiteral_21419, 0);
  v36 = get_gameObject(v35);
  SetActive(v36, 0, 0);
  v37 = get_transform(HitNum, 0);
  v38 = Find(v37, StringLiteral_21420, 0);
  v39 = get_gameObject(v38);
  SetActive(v39, 0, 0);
  v40 = get_transform(HitNum, 0);
  v41 = Find(v40, StringLiteral_21421, 0);
  v42 = get_gameObject(v41);
  SetActive(v42, 0, 0);
  v43 = get_transform(HitNum, 0);
  v44 = Find(v43, StringLiteral_21422, 0);
  v45 = get_gameObject(v44);
  SetActive(v45, 0, 0);
  v46 = get_transform(HitNum, 0);
  v47 = Find(v46, StringLiteral_21423, 0);
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
        if (!first)
      }
      v19 = v18->form;
      v20 = *form;
      if (v18->uniqueid == uniqueid && v19 == v20)
      {
        v21 = v18->startframe;
        if (v18->framelength + v21 <= startframe)
        v18->framelength = (startframe - v21) & ~((startframe - v21) >> 15);
        if (!first)
          break;
      }
      else
      {
        if (v19 != v20)
        s = v18->data1->s;
        _Add(v14, s->m_Items[0]);
        if (!first)
          break;
      }
    }
  }
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
  v30->m_Items[0] = v28;
  formindex = (*form)->formindex;
  HitNum = GetHitNum(formindex, v28);
  SetActive(HitNum, 1, 0);
  transform = get_transform(HitNum, 0);
  v34 = Find(transform, StringLiteral_21418, 0);
  gameObject = get_gameObject(v34);
  SetActive(gameObject, 0, 0);
  v36 = get_transform(HitNum, 0);
  v37 = Find(v36, StringLiteral_21419, 0);
  v38 = get_gameObject(v37);
  SetActive(v38, 0, 0);
  v39 = get_transform(HitNum, 0);
  v40 = Find(v39, StringLiteral_21420, 0);
  v41 = get_gameObject(v40);
  SetActive(v41, 0, 0);
  v42 = get_transform(HitNum, 0);
  v43 = Find(v42, StringLiteral_21421, 0);
  v44 = get_gameObject(v43);
  SetActive(v44, 0, 0);
  v45 = get_transform(HitNum, 0);
  v46 = Find(v45, StringLiteral_21422, 0);
  v47 = get_gameObject(v46);
  SetActive(v47, 0, 0);
  v48 = get_transform(HitNum, 0);
  v49 = Find(v48, StringLiteral_21423, 0);
  v50 = get_gameObject(v49);
  SetActive(v50, 0, 0);
  if ((type & 0xFFFFFFFE) == 4)
  {
    v53 = (*form)->formindex;
    v54 = GetHitNum(v53, v28 + 1);
    SetActive(v54, 1, 0);
    v55 = get_transform(v54, 0);
    v56 = Find(v55, StringLiteral_21418, 0);
    v57 = get_gameObject(v56);
    SetActive(v57, 0, 0);
    v58 = get_transform(v54, 0);
    v59 = Find(v58, StringLiteral_21419, 0);
    v60 = get_gameObject(v59);
    SetActive(v60, 0, 0);
    v61 = get_transform(v54, 0);
    v62 = Find(v61, StringLiteral_21420, 0);
    v63 = get_gameObject(v62);
    SetActive(v63, 0, 0);
    v64 = get_transform(v54, 0);
    v65 = Find(v64, StringLiteral_21421, 0);
    v66 = get_gameObject(v65);
    SetActive(v66, 0, 0);
    v67 = get_transform(v54, 0);
    v68 = Find(v67, StringLiteral_21422, 0);
    v69 = get_gameObject(v68);
    SetActive(v69, 0, 0);
    v70 = get_transform(v54, 0);
    v71 = Find(v70, StringLiteral_21423, 0);
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
    effBTLCreate(0);
    effBTLCutCreate(0, 0, 0, 0);
    effBTLGetCutEndFrame(0, 0);
    nbGetKoukaProcessData();
    nbAddKoukaPacket(0, 0, 0, 0);
    return 0;
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
    }
    if (v9 <= 0x100)
    {
      if (v9 != 64 && v9 != 128 && v9 != 256)
        return 1;
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
  if (dead)
  {
    *&startframe = nbMakeDeadVisualPacket(startframe, uniqueid, form, deadtype, 1, *&mp);
    if (!hiteff)
    if (type != 2)
    {
      if (type == 1)
      {
        v21 = v19;
        v22 = uniqueid;
        v23 = form;
        v24 = 7;
      }
      if (type)
    }
    v21 = v19;
    v22 = uniqueid;
    v23 = form;
    v24 = 0;
    *&startframe = nbAddHitEffKoukaPacket(v21, v22, v23, v24, *&hp);
  }
  if (badstat <= 32)
  {
    if (badstat <= 4)
    {
      if (badstat > 4 || ((1 << badstat) & 0x16) == 0)
    }
    else    *&startframe = nbMakeBadDamagePacket(startframe, uniqueid, form, badstat, *&hp);
  }
  if (badstat <= 256)
  {
    if (badstat != 64 && badstat != 128 && badstat != 256)
  }
  if (badstat == 512)
  {
    k = nbGetKoukaProcessData(*&startframe);
    *&startframe = nbAddKoukaPacket(&k, v19, 0, uniqueid);
    *(*&startframe + 20LL) = 45;
    *(*&startframe + 48LL) = *form;
    *(*(*&startframe + 88LL) + 32LL) = 0;
    if (hiteff)
  }
  if (badstat == 2048 || badstat == 1024)
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
      }
    }
    if (!hiteff)
  }
  k = nbGetKoukaProcessData(*&startframe);
  *&startframe = nbAddKoukaPacket(&k, v19, 0, uniqueid);
  *(*&startframe + 20LL) = 9;
  *(*&startframe + 48LL) = *form;
  *(*(*&startframe + 88LL) + 36LL) = 1099431936;
  *(*(*&startframe + 96LL) + 32LL) = 1;
  if (hiteff)
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
    v30->form = *form;
    v30->data1->i = 1;
    v30->data2->i = v28;
  }
  if ((mp & 0x80000000) == 0)
  {
    if (moji && formindex <= 15)
      *&startframe = nbAddNumEffKoukaPacket(v25, 45, uniqueid, form, mp, 0, 1, *&hiteff);
    v28 = -mp;
    k = nbGetKoukaProcessData(*&startframe);
    v30 = nbAddKoukaPacket(&k, v19, 0, uniqueid);
    v30->type = 17;
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
  }
  if (moji)
  {
    if (type == 2)
    {
      v32 = v19 + animeoff + 1;
      v33 = uniqueid;
      v34 = form;
      v35 = 1;
    }
    if (type == 1)
    {
      v32 = v19 + animeoff + 1;
      v33 = uniqueid;
      v34 = form;
      v35 = 2;
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
    }
    if (deadchk == 1 || (v19->flag & 4) == 0)
    {
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
    nbGetMainProcessData();
    nbCheckEventDead(0);
    nbGetUnitWorkFromFormindex(0);
    nbGetKoukaProcessData();
    nbAddKoukaPacket(0, 0, 0, 0);
    nbAddHitEffKoukaPacket(0, 0, 0, 0);
    Get(0);
    nbMakeBadKaifukuPacket(0, 0, 0);
    nbCheckDeadEvent(0);
    nbGetDeadEventFadeTime(0);
    nbGetDeadEventFadeOutFrame(0);
    nbGetDeadEventFadeStopFrame(0);
    nbGetDeadEventFadeInFrame(0);
    nbAddDeadPcmPacket(0, 0, 0);
    nbCheckSePacket(0, 0, 0);
    nbAddPadShockPacket(0, 0, 0, 0, 0);
    return 0;
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
    }
    if (type == 1)
      *&startframe = nbAddHitEffKoukaPacket(startframe, uniqueid, form, 2, *&hp);
  }
  if (((mp | hp) & 0x80000000) == 0)
  {
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
    v19->form = *form;
    v19->data1->i = 1;
    v19->data2->i = mp;
  }
  if ((mp & 0x80000000) == 0)
  {
    if (formindex <= 15)
      *&startframe = nbAddNumEffKoukaPacket(v15 + 1, 45, uniqueid, form, mp, 0, 3);
    k = nbGetKoukaProcessData(*&startframe);
    v19 = nbAddKoukaPacket(&k, v15, 0, uniqueid);
    v19->type = 17;
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
    return 1;
  }
  if (badstat)
    nbMakeBadKaifukuPacket(v15 + 1, uniqueid, form, *&type);
  return 1;
}

// 0x198a6c0
s32 nbMakeNegoBackPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, nbFormation_t **target) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    nbMakeUnitMoveGetCyDist(0, 0);
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    nbGetKoukaProcessData();
    nbAddKoukaPacket(0, 0, 0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    return 0;
}

// 0x198a900
s32 nbMakeNegoForwardPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, nbFormation_t **target) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    nbMakeUnitMoveGetCyDist(0, 0);
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    nbGetKoukaProcessData();
    nbAddKoukaPacket(0, 0, 0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    return 0;
}

// 0x198a3d0
s32 nbMakeNegoWorkPosPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, nbFormation_t **target) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    nbMakeUnitMoveGetCyDist(0, 0);
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    nbGetKoukaProcessData();
    nbAddKoukaPacket(0, 0, 0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    return 0;
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
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__ADDVECTOR();
    SDF_VU0__STOREVECTOR(0);
    sdfFabs(0);
    sdfAtan2(0, 0);
    return 0;
}

// 0x1989510
s32 nbMakeUnitMovePacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 select, s32 movetype, f32 ritu) {
    nbGetMainProcessData();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    nbGetFormCenter(0);
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__SETVECTOR_Y(0);
    SDF_VU0__NORMALIZE();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__ADDVECTOR();
    nbMakeUnitMoveGetCyDist(0, 0);
    SDF_VU0__VECTOR_W_SET_ZERO();
    SDF_VU0__COPYVECTOR_A_TO_B();
    SDF_VU0__LOADIDENTITYVECTOR();
    SDF_VU0__SETVECTOR_Z(0);
    SDF_VU0__ADDVECTOR_B_A();
    SDF_VU0__STOREVECTOR_B(0);
    nbGetKoukaProcessData();
    nbAddKoukaPacket(0, 0, 0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__INNERPRODUCT();
    SDF_DEGtoRAD(0);
    sdfCos(0);
    dds3RotationArc();
    sdfAcos(0);
    Lerp(0);
    return 0;
}
