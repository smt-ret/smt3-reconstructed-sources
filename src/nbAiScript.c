#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbActionProcessData_t nbActionProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbParty_t nbParty_t;

static s32 btl_ai_rot_cnt;

void AiChkJoken(u32 c);
u8 Get(s32 id);
void *dds3GetProcessData(dds3ProcessID_t **id);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
bool evtBitCheck(s32 no);
s32 evtGetAgeOfMoon16(void);
void itfMesMngSetVar(s32 id, s32 index, s32 num, s32 type);
s32 nbAiChkJoken(nbActionProcessData_t **a, u32 jo);
void nbAllFormDispOn(void);
void nbCameraScriptSet(sdfVector4_t pPos, sdfVector4_t pQ);
void nbCameraScriptSet1Shot(nbFormation_t **pTargetForm);
void nbCameraScriptSetBougai(nbFormation_t **pTargetForm);
void nbDelAllKoukaPacketType(s32 type);
s32 nbGetAisyoTable(s32 formindex);
nbMainProcessData_t *nbGetMainProcessData(void);
nbParty_t *nbGetPartyFromFormindex(s32 formindex);
u32 nbGetSelectBit(nbMainProcessData_t *data);
void nbGroupFormDispOff(s32 side);
void nbGroupFormDispOn(s32 side);
void nbPanelAllHide(void);
void nbPanelAutoHide(void);
s32 nbRunAi(nbActionProcessData_t **a);
s32 nbRunAiSub(nbActionProcessData_t **a, s32 tbl);
s32 nbSetAiTarget(nbActionProcessData_t **a, s32 code, s32 n);
s32 nbSetEnemySummonFormation(nbMainProcessData_t **data, s32 devilid);
void nbSetNormalSkill0(datUnitWork_t *work);
void *scrGetData(void);
f32 scrGetFloatPara(s32 n);
s32 scrGetIntPara(s32 n);
void scrSetIntReturnValue(s32 i);
void scrSetUserData(dds3ProcessID_t *id, void *p);
dds3ProcessID_t *scrStartScript2(s32 a, void *b, s32 c);

// 0xfa7690
void AiChkJoken(u32 c) {
    scrGetData();
    nbAiChkJoken(0, 0);
    scrSetIntReturnValue(0);
}

// 0xfa9170
s32 nbCommand_AI(void) {
    scrGetData();
    nbRunAi(0);
    return 0;
}

// 0xfa5bb0
s32 nbCommand_AI_ACT_ATTACK(void) {
    scrGetData();
    nbSetNormalSkill0(0);
    return 0;
}

// 0xfa5cf0
s32 nbCommand_AI_ACT_ESCAPE(void) {
    scrGetData();
    return 0;
}

// 0xfa5f30
s32 nbCommand_AI_ACT_SKILL(void) {
    scrGetData();
    scrGetIntPara(0);
    return 0;
}

// 0xfa6060
s32 nbCommand_AI_ACT_SUMMON(void) {
    scrGetData();
    scrGetIntPara(0);
    nbSetEnemySummonFormation(0, 0);
    return 0;
}

// 0xfa5e10
s32 nbCommand_AI_ACT_WAIT(void) {
    scrGetData();
    return 0;
}

// 0xfa8230
s32 nbCommand_AI_CHK_BA(void) {
  AiChkJoken(0xF0000u);
  return 1;
}

// 0xfa7a10
s32 nbCommand_AI_CHK_DMGCNT(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x30000);
  return 1;
}

// 0xfa7dd0
s32 nbCommand_AI_CHK_ENALLBAD(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0xA0000);
  return 1;
}

// 0xfa7d30
s32 nbCommand_AI_CHK_ENBAD(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x90000);
  return 1;
}

// 0xfa7b50
s32 nbCommand_AI_CHK_ENCNT(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x60000);
  return 1;
}

// 0xfa8310
s32 nbCommand_AI_CHK_ENDARK(void) {
  AiChkJoken(0x110000u);
  return 1;
}

// 0xfa9060
s32 nbCommand_AI_CHK_ENHAMAMHK(void) {
  AiChkJoken(0x1B0000u);
  return 1;
}

// 0xfa7fb0
s32 nbCommand_AI_CHK_ENHOJO(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0xD0000);
  return 1;
}

// 0xfa80f0
s32 nbCommand_AI_CHK_ENHOJOMAX(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x190000);
  return 1;
}

// 0xfa7e70
s32 nbCommand_AI_CHK_ENID(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0xB0000);
  return 1;
}

// 0xfa82a0
s32 nbCommand_AI_CHK_ENLIGHT(void) {
  AiChkJoken(0x100000u);
  return 1;
}

// 0xfa8e00
s32 nbCommand_AI_CHK_ESCAPE(void) {
    scrGetData();
    Get(0);
    scrSetIntReturnValue(0);
    return 0;
}

// 0xfa7c90
s32 nbCommand_AI_CHK_FRBAD(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x80000);
  return 1;
}

// 0xfa7ab0
s32 nbCommand_AI_CHK_FRCNT(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x50000);
  return 1;
}

// 0xfa8050
s32 nbCommand_AI_CHK_FRHOJO(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0xE0000);
  return 1;
}

// 0xfa8190
s32 nbCommand_AI_CHK_FRHOJOMAX(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x1A0000);
  return 1;
}

// 0xfa7970
s32 nbCommand_AI_CHK_FRHP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x20000);
  return 1;
}

// 0xfa7f10
s32 nbCommand_AI_CHK_FRID(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0xC0000);
  return 1;
}

// 0xfa7bf0
s32 nbCommand_AI_CHK_MYBAD(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x70000);
  return 1;
}

// 0xfa7830
s32 nbCommand_AI_CHK_MYHP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x10000);
  return 1;
}

// 0xfa78d0
s32 nbCommand_AI_CHK_MYMP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x180000);
  return 1;
}

// 0xfa83f0
s32 nbCommand_AI_CHK_PLV(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x130000);
  return 1;
}

// 0xfa8380
s32 nbCommand_AI_CHK_POW(void) {
  AiChkJoken(0x120000u);
  return 1;
}

// 0xfa8490
s32 nbCommand_AI_CHK_PPARTYLV(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x140000);
  return 1;
}

// 0xfa90d0
s32 nbCommand_AI_CHK_SKILLNOMP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  AiChkJoken(IntPara | 0x1C0000);
  return 1;
}

// 0xfa8650
s32 nbCommand_AI_GET_ALLKOUDO(void) {
    scrGetData();
    nbGetPartyFromFormindex(0);
    scrSetIntReturnValue(0);
    return 0;
}

// 0xfa8d60
s32 nbCommand_AI_GET_FUREA(void) {
  s32 AgeOfMoon16;
  s32 v4;

  AgeOfMoon16 = evtGetAgeOfMoon16();
  if (AgeOfMoon16 >= 0)
    v4 = AgeOfMoon16;
  else
    v4 = AgeOfMoon16 + 1;
  scrSetIntReturnValue(v4 >> 1);
  return 1;
}

// 0xfa8a90
s32 nbCommand_AI_GET_MYAISYO(void) {
    scrGetData();
    nbGetAisyoTable(0);
    scrSetIntReturnValue(0);
    return 0;
}

// 0xfa8970
s32 nbCommand_AI_GET_MYLV(void) {
    scrGetData();
    scrSetIntReturnValue(0);
    return 0;
}

// 0xfa87e0
s32 nbCommand_AI_GET_PRESSKOUDO(void) {
    scrGetData();
    nbGetPartyFromFormindex(0);
    scrSetIntReturnValue(0);
    return 0;
}

// 0xfa8530
s32 nbCommand_AI_GET_TURN(void) {
    scrGetData();
    scrSetIntReturnValue(0);
    return 0;
}

// 0xfa6210
s32 nbCommand_AI_SET_CRITICAL(void) {
    scrGetData();
    return 0;
}

// 0xfa6330
s32 nbCommand_AI_TAR_AI(void) {
    scrGetData();
    nbSetAiTarget(0, 0, 0);
    nbGetSelectBit(0);
    return 0;
}

// 0xfa6690
s32 nbCommand_AI_TAR_BAARLV(void) {
    scrGetData();
    nbSetAiTarget(0, 0, 0);
    nbGetSelectBit(0);
    return 0;
}

// 0xfa6a10
s32 nbCommand_AI_TAR_BAD(void) {
    scrGetData();
    scrGetIntPara(0);
    nbSetAiTarget(0, 0, 0);
    nbGetSelectBit(0);
    return 0;
}

// 0xfa6f90
s32 nbCommand_AI_TAR_DARK(void) {
    scrGetData();
    nbSetAiTarget(0, 0, 0);
    nbGetSelectBit(0);
    return 0;
}

// 0xfa6bf0
s32 nbCommand_AI_TAR_ID(void) {
    scrGetData();
    scrGetIntPara(0);
    nbSetAiTarget(0, 0, 0);
    nbGetSelectBit(0);
    return 0;
}

// 0xfa74d0
s32 nbCommand_AI_TAR_JOKEN(void) {
    scrGetData();
    nbSetAiTarget(0, 0, 0);
    nbGetSelectBit(0);
    return 0;
}

// 0xfa64d0
s32 nbCommand_AI_TAR_LIFEMIN(void) {
    scrGetData();
    nbSetAiTarget(0, 0, 0);
    nbGetSelectBit(0);
    return 0;
}

// 0xfa6dd0
s32 nbCommand_AI_TAR_LIGHT(void) {
    scrGetData();
    nbSetAiTarget(0, 0, 0);
    nbGetSelectBit(0);
    return 0;
}

// 0xfa6850
s32 nbCommand_AI_TAR_LVMIN(void) {
    scrGetData();
    nbSetAiTarget(0, 0, 0);
    nbGetSelectBit(0);
    return 0;
}

// 0xfa7150
s32 nbCommand_AI_TAR_PLAYER(void) {
    scrGetData();
    nbSetAiTarget(0, 0, 0);
    nbGetSelectBit(0);
    return 0;
}

// 0xfa7310
s32 nbCommand_AI_TAR_RND(void) {
    scrGetData();
    nbSetAiTarget(0, 0, 0);
    nbGetSelectBit(0);
    return 0;
}

// 0xfa92c0
s32 nbCommand_AI_TBL(void) {
    scrGetIntPara(0);
    scrGetData();
    nbRunAiSub(0, 0);
    return 0;
}

// 0xfaa300
s32 nbCommand_BTL_AI_CHANGE_OFF(void) {
  nbMainProcessData_t_o *MainProcessData;

  MainProcessData = nbGetMainProcessData();
  MainProcessData->stat |= 0x40000u;
  return 1;
}

// 0xfaa380
s32 nbCommand_BTL_AI_CHANGE_ON(void) {
  nbMainProcessData_t_o *MainProcessData;

  MainProcessData = nbGetMainProcessData();
  MainProcessData->stat &= ~0x40000u;
  return 1;
}

// 0xfaa130
s32 nbCommand_BTL_AI_ROT_CLR(void) {
  btl_ai_rot_cnt = 0;
  return 1;
}

// 0xfaa260
s32 nbCommand_BTL_AI_ROT_GET(void) {
  s32 btl_ai_rot_cnt;

  scrSetIntReturnValue(btl_ai_rot_cnt);
  return 1;
}

// 0xfaa1a0
s32 nbCommand_BTL_AI_ROT_NEXT(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  ++btl_ai_rot_cnt;
  btl_ai_rot_cnt %= IntPara;
  return 1;
}

// 0xfa9c00
s32 nbCommand_BTL_ALLTAIKYO(void) {
    scrGetData();
    return 0;
}

// 0xfa9600
s32 nbCommand_BTL_CAM_1SHOT(void) {
    scrGetData();
    nbCameraScriptSet1Shot(0);
    return 0;
}

// 0xfa9750
s32 nbCommand_BTL_CAM_2SHOT(void) {
  return 1;
}

// 0xfa9760
s32 nbCommand_BTL_CAM_BOUGAI(void) {
    scrGetData();
    nbCameraScriptSetBougai(0);
    return 0;
}

// 0xfa95f0
s32 nbCommand_BTL_CAM_ORG(void) {
  return 1;
}

// 0xfa9410
s32 nbCommand_BTL_CAM_SET(void) {
    scrGetData();
    scrGetFloatPara(0);
    nbCameraScriptSet((sdfVector4_t){0}, (sdfVector4_t){0});
    return 0;
}

// 0xfa99a0
s32 nbCommand_BTL_EVENT(void) {
    scrGetData();
    scrGetIntPara(0);
    return 0;
}

// 0xfa9fc0
s32 nbCommand_BTL_FORM_ALL_ON(void) {
  nbAllFormDispOn();
  return 1;
}

// 0xfaa0b0
s32 nbCommand_BTL_FORM_ENE_ON(void) {
  nbGroupFormDispOff(0);
  nbGroupFormDispOn(1);
  return 1;
}

// 0xfaa030
s32 nbCommand_BTL_FORM_PLY_ON(void) {
  nbGroupFormDispOn(0);
  nbGroupFormDispOff(1);
  return 1;
}

// 0xfa9e80
s32 nbCommand_BTL_NAKAMA(void) {
    scrGetData();
    return 0;
}

// 0xfa98b0
s32 nbCommand_BTL_PNL_OFF(void) {
  nbMainProcessData_t_o *MainProcessData;

  nbPanelAllHide();
  nbPanelAutoHide();
  else
  {
    MainProcessData = nbGetMainProcessData();
    if (!MainProcessData)
      return 1;
  }
  if (MainProcessData->encno == 93)
  {
    nbDelAllKoukaPacketType(16);
    nbDelAllKoukaPacketType(22);
    return 1;
  }
  return 1;
}

// 0xfa9990
s32 nbCommand_BTL_PNL_ON(void) {
  return 1;
}

// 0xfa9d40
s32 nbCommand_BTL_PRESS(void) {
    scrGetData();
    return 0;
}

// 0xfa9ac0
s32 nbCommand_BTL_TAIKYO(void) {
    scrGetData();
    return 0;
}

// 0xfaa400
void nbInitAiScript(nbActionProcessData_t **a, s32 no) {
    evtBitCheck(0);
    scrStartScript2(0, 0, 0);
    scrSetUserData(0, 0);
    dds3GetProcessData(0);
    itfMesMngSetVar(0, 0, 0, 0);
    dds3LinkProcess(0, 0);
}
