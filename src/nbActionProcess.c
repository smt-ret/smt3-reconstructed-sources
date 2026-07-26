#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct SOBED_PB_LIST SOBED_PB_LIST;
typedef struct datUnitVisual_s datUnitVisual_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effBTLCutHandle_t effBTLCutHandle_t;
typedef struct effBTL_t effBTL_t;
typedef struct fileHandle_t fileHandle_t;
typedef struct nbActionProcessData_t nbActionProcessData_t;
typedef struct nbActionProcess_SOBED nbActionProcess_SOBED;
typedef struct nbActionProcess_SOBED_PB nbActionProcess_SOBED_PB;
typedef struct nbActionProcess_nbActionFunc_t nbActionProcess_nbActionFunc_t;
typedef struct nbActionProcess_nbActionFunc_t_checkDelegate nbActionProcess_nbActionFunc_t_checkDelegate;
typedef struct nbActionProcess_nbActionFunc_t_setDelegate nbActionProcess_nbActionFunc_t_setDelegate;
typedef struct nbDebugProcessData_t nbDebugProcessData_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbKoukaPacket_t nbKoukaPacket_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbParty_t nbParty_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;

struct nbActionProcess_nbActionFunc_t {
    nbActionProcess_nbActionFunc_t_setDelegate *set;
    nbActionProcess_nbActionFunc_t_checkDelegate *check;
};

struct nbActionProcess_SOBED {
    char *keyname;
    char *bed_fname;
    char *se0_str;
    char *se1_str;
    char tga_fname[UNKNOWN_ARRAY_SIZE];
    nbActionProcess_SOBED_PB pbdata[UNKNOWN_ARRAY_SIZE];
};

struct nbActionProcess_SOBED_PB {
    s32 type;
    s32 reversePB;
    char *prefab_name;
};

static u32 StkSelId;
static char *SetAction_READY_str;
static SOBED_PB_LIST sobed_pb_all[UNKNOWN_ARRAY_SIZE];
static nbActionProcess_nbActionFunc_t ActionFunc[UNKNOWN_ARRAY_SIZE];
static s32 nba_uniqueid;
static nbActionProcess_SOBED sobedtbl[UNKNOWN_ARRAY_SIZE];
static nbActionProcess_SOBED sobedtbl_dante[UNKNOWN_ARRAY_SIZE];
static SOBED_PB_LIST *pb_list;

s32 CheckArrCounter(nbActionProcessData_t **a);
s32 CheckBinjoNego(nbActionProcessData_t **a);
s32 CheckCounter(nbActionProcessData_t **a, s32 from, s32 to);
void CheckDeadScript(nbActionProcessData_t **a);
s32 CheckInotiNego(nbActionProcessData_t **a);
s32 CheckKoketaNego(nbActionProcessData_t **a);
s32 CheckMukanNego(nbActionProcessData_t **a);
s32 CheckSenseiNego(nbActionProcessData_t **a);
s32 CheckTimeListDeadEnemyParty(nbActionProcessData_t **a, s32 formindex);
void ClearTimeList(nbActionProcessData_t **a);
bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void DokodemoPoa(nbActionProcessData_t **a);
s32 FindId(s32 type, char *name);
u8 Get(s32 id);
void *GetBattleUI(s32 index);
void GetKoukaList(nbActionProcessData_t **a, s8 ***koukalist, u32 select, s32 nskill);
s32 GetPibIndex(u8 **bData, s32 bPos);
nbActionProcess_SOBED *GetSOBED(s32 no);
nbActionProcessData_t *InitActionProcessData(nbMainProcessData_t **data, s32 type, s32 from, s32 to, s32 d);
void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name);
void LoadKeysSE1(s32 type, char *key, char *se_name);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
s32 MAKE_SKILL_SE00(s32 x);
s32 MAKE_SKILL_SE01(s32 x);
void MarkPibIndex(u8 ***bData);
void MarkTmxIndex(u8 ***bData);
void OverwriteTimeList(nbActionProcessData_t **a, s32 formindex, s32 start, s32 locktime, s32 endtime);
void SetActionSeq(nbActionProcessData_t **a, s32 seq);
void SetAddPressPacket(nbActionProcessData_t **a, s32 nskill);
void SetAllPacket(nbActionProcessData_t **a, s32 koukatype, s32 nskill, s32 sformindex, s32 dformindex, s32 cnt, s32 frame, f32 koukaritu);
void SetAnalyzePacket(nbActionProcessData_t **a, s32 dformindex, s32 sframe);
void SetAuroraPacket(nbActionProcessData_t **a, s32 dformindex, s32 sframe);
void SetAuto(bool act);
void SetDamagePacket(nbActionProcessData_t **a, s32 hp);
void SetDeadPacket(nbActionProcessData_t **a, s32 formindex);
void SetEnemyEscapePacket(nbActionProcessData_t **a, s32 dformindex, s32 sframe);
void SetHpForTimeList(nbActionProcessData_t **a);
void SetMakaPacket(nbActionProcessData_t **a, s32 dformindex, s32 sframe);
void SetMissPacket(nbActionProcessData_t **a, s32 nskill, s32 sformindex, s32 dformindex, s32 cnt, s32 frame);
void SetNowActionStat(nbActionProcessData_t **a, s32 comm, s32 nskill);
void SetOngShadowPacket(nbActionProcessData_t **a, s32 nskill, s32 sformindex, s32 dformindex, s32 cnt, s32 frame);
void SetOngShadowPacket2(nbActionProcessData_t **a, s32 dformindex, s32 frame);
s32 SetPlayerSummonPacket(nbActionProcessData_t **a, s32 nskill, s32 sformindex, s32 dformindex, s32 sframe);
void SetSakePacket(nbActionProcessData_t **a, s32 nskill, s32 sformindex, s32 dformindex, s32 cnt, s32 frame);
void SetTarget(nbDebugProcessData_t **d);
void SetTargetParty(nbActionProcessData_t **a, s32 partyindex);
void SetTargetPlayer(nbActionProcessData_t **a);
void SetTimeList(nbActionProcessData_t **a, s32 formindex, s32 start, s32 locktime, s32 endtime);
void SetTorafuPacket(nbActionProcessData_t **a, s32 dformindex, s32 sframe);
void SobedClear(void);
void billSetTexture(void **pTexture);
void datAddItem(s32 id, s32 num);
void datAddMaka(s32 addmaka);
s32 datCheckPlayerDead(void);
s32 datCheckSyojiSkill(datUnitWork_t *work, u32 skill);
s32 datCheckTalk(datUnitWork_t *work);
void datClearCommMemory(datUnitWork_t *work);
s32 datGetBadStatusAttr(s32 bad);
s32 datGetItemSkillNo(s32 itemid);
s32 datGetSkillCost(datUnitWork_t *w, s32 nskill);
s32 datSearchDevilStock(s32 id);
s32 dds3ExistProcess(dds3ProcessID_t **id);
void dds3FadeColorSet(u32 r, u32 g, u32 b);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetRandIntA(u32 aLimit, char *name);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
effBTL_t *effBTLCreate(u8 **pData);
effBTLCutHandle_t *effBTLCutCreate(effBTL_t **hBTLEffect, u16 CutNum, nbFormation_t *pFormation, u32 stat);
u32 effBTLCutGetCutEndFrame(effBTLCutHandle_t **hBTLCutEffect);
u32 effBTLCutGetMotionChangeFrame(effBTLCutHandle_t **hBTLCutEffect);
void effBTLCutSetCameraState(effBTLCutHandle_t **hBTLCutEffect);
void effBTLCutSetDrawEndFrame(effBTLCutHandle_t **hBTLCutEffect, u32 frame);
void effBTLDelete(effBTL_t **hBTLEffect);
u32 effBTLGetCutEndFrame(effBTL_t **hBTLEffect, u16 CutNum);
u32 effBTLGetMotionChangeFrame(effBTL_t **hBTLEffect, u16 CutNum);
void effBTLSkillEnd(void);
nbFormation_t *effBTLSkillGetTargetFormation(u32 number);
void effBTLSkillSetFormationInfo(u32 InvokeID, u32 TargetBit);
void effBTLSkillSetState(u32 state);
void effBTLSkillStart(u32 id, u32 stat);
s32 effPCPBossONGY2GetLength(void);
s32 effPCPBossONGYGetLength(void);
bool evtBitCheck(s32 no);
s32 evtGetAgeOfMoon(void);
void nbActionProcessData_t__Clear(nbActionProcessData_t *this);
nbKoukaPacket_t *nbAddAnalyzePacket(s32 startframe, s32 uniqueid, nbFormation_t **form);
nbKoukaPacket_t *nbAddFlareChargePacket(s32 startframe, s32 uniqueid, s32 point);
nbKoukaPacket_t *nbAddFormFlagOnOffPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 sw, u32 flag);
nbKoukaPacket_t *nbAddFormOnOffPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 sw);
void nbAddHatudoEffectEndPacket(s32 startframe, s32 uniqueid);
nbKoukaPacket_t *nbAddHatudoEffectKoukaPacket(s32 startframe, s32 framelength, s32 uniqueid, nbFormation_t **form, s32 type, s32 mottype, s32 skillid);
nbKoukaPacket_t *nbAddHitEffKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type);
nbKoukaPacket_t *nbAddHitStopPacket(s32 startframe, s32 uniqueid);
nbKoukaPacket_t *nbAddHojoKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 hojotype, s32 hojopoint);
nbKoukaPacket_t *nbAddHpMpKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 n, s32 type);
nbKoukaPacket_t *nbAddJyokyoHelpPacket(s32 startframe, s32 uniqueid, s32 no, s32 var_id, s32 var_ind);
nbKoukaPacket_t *nbAddMojiEffKoukaPacket(s32 startframe, s32 frame, s32 uniqueid, nbFormation_t **form, s32 type);
nbKoukaPacket_t *nbAddMotionKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 motion);
nbKoukaPacket_t *nbAddMotionStopClearPacket(s32 startframe, s32 uniqueid, nbFormation_t **form);
nbKoukaPacket_t *nbAddOngOut2Packet(s32 startframe, s32 uniqueid, nbFormation_t **form);
nbKoukaPacket_t *nbAddOngOutPacket(s32 startframe, s32 uniqueid, nbFormation_t **form);
void nbAddPanelStockEndPacket(s32 startframe, s32 uniqueid);
void nbAddPanelStockFadeOutPacket(s32 startframe, s32 uniqueid);
nbKoukaPacket_t *nbAddReturnKoukaPacket(s32 startframe, s32 uniqueid, nbParty_t **party, s32 dead);
nbKoukaPacket_t *nbAddSakeKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form);
nbKoukaPacket_t *nbAddSePacket(s32 startframe, s32 uniqueid, u32 se);
nbKoukaPacket_t *nbAddSePacket2(s32 startframe, s32 uniqueid, u32 se);
nbKoukaPacket_t *nbAddSkillColorOffPacket(s32 startframe, s32 uniqueid);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket(s32 startframe, s32 framelength, s32 uniqueid, effBTLCutHandle_t **cuteff);
nbKoukaPacket_t *nbAddSkillEffectKoukaPacket2(s32 startframe, s32 framelength, s32 uniqueid, effBTL_t **hbtl, s32 cutno, nbFormation_t **form, s32 j);
nbKoukaPacket_t *nbAddSkillMotionKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 motion, s32 endtype, f32 ritu);
nbKoukaPacket_t *nbAddSkillNamePacket(s32 startframe, s32 uniqueid, s32 id);
nbKoukaPacket_t *nbAddUnitAKoukaPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 a, s32 frame);
s32 nbAppendEnemyDevilWork(nbMainProcessData_t *data, s32 id, s32 formindex);
void nbBgmTrans(void);
void nbCameraSetState(u16 state);
void nbCameraSetTaizi(nbFormation_t **pInvokeForm, nbFormation_t **pTargetForm);
s32 nbCheckBadCurse(s32 formindex);
s32 nbCheckBadKaifuku(datUnitWork_t *work, s32 type);
s32 nbCheckBadPanicAction(datUnitWork_t *w);
s32 nbCheckBattleSkillError1(s32 nskill);
s32 nbCheckBattleSkillError2(s32 nskill, u32 select);
s32 nbCheckBattleSkillError3(s32 nskill, u32 select);
s32 nbCheckDeadScript(nbFormation_t *form);
s32 nbCheckEscape(nbMainProcessData_t *data);
s32 nbCheckFormationFriend(s32 formindex1, s32 formindex2);
s32 nbCheckFormationPlayerSide(s32 formindex);
u32 nbCheckHitEffect(s32 nskill, s32 sformindex, s32 dformindex);
s32 nbCheckKuisibari2Skill(s32 formindex);
s32 nbCheckKuisibariSkill(s32 formindex);
s32 nbCheckSingleTargetSkill(s32 skillid);
s32 nbCheckSkillUse(s32 formindex, s32 nskill);
s32 nbCheckStoneDead(s32 nskill, s32 dformindex);
void nbCloseCommSel(void);
void nbDelAllKoukaPacketType(s32 type);
void nbDelAllMojiNumEffectKoukaPacket(nbFormation_t **form, s32 motno);
void nbDispItemName(s32 id);
void nbDispJyokyoHelp(s32 msgid, s32 no, s32 var_id, s32 var_ind);
void nbDispMiscActionNameComm(s32 id);
void nbDispSkillErrorMessage(s32 err);
void nbDispSkillName(s32 id);
s32 nbGetActionSeq(dds3ProcessID_t *id);
u32 nbGetAisyo(s32 nskill, s32 formindex, s32 attr);
f32 nbGetAisyoRitu(s32 nskill, s32 sformindex, s32 dformindex);
u32 nbGetBadStat(s32 formindex);
s32 nbGetCommSelStat(void);
f32 nbGetCriticalPow(s32 sformindex, f32 pow);
s32 nbGetDeadType(s32 nskill, s32 sformindex, s32 dformindex);
u32 nbGetDevilFormatFlag(s32 formindex);
nbFormation_t *nbGetEventForm(void);
void nbGetExpMakaItem(datUnitWork_t *w);
f32 nbGetGensyoRitu(s32 nskill, s32 sformindex, s32 dformindex);
s32 nbGetHitType(nbActionProcessData_t *ad, s32 nskill, s32 sformindex, s32 dformindex);
s32 nbGetHojoCounter(s32 formindex, s32 type);
f32 nbGetHpDrainRitu(s32 nskill, s32 sformindex, s32 dformindex);
s32 nbGetItemSkillNo(nbActionProcessData_t *a, s32 itemid);
u32 nbGetKoukaBadDamage(s32 nskill, s32 sformindex, s32 dformindex, f32 ai, s32 nvirtual);
u32 nbGetKoukaBadKaifuku(s32 nskill, s32 sformindex, s32 dformindex, f32 ai, s32 nvirtual);
s32 nbGetKoukaHp(s32 sw, s32 nskill, s32 sformindex, s32 dformindex, f32 ritu, s32 cnt);
s32 nbGetKoukaMp(s32 sw, s32 nskill, s32 sformindex, s32 dformindex, f32 ritu, s32 cnt);
s32 nbGetKoukaType(s32 nskill, s32 sformindex, s32 dformindex);
nbMainProcessData_t *nbGetMainProcessData(void);
s32 nbGetMakaBaramaki(datUnitWork_t *w);
s32 nbGetMotionActframe(nbFormation_t **form, s32 motion, f32 ritu);
s32 nbGetMotionEndData(nbFormation_t **form, s32 motion);
s32 nbGetMotionEndType(nbFormation_t **form, s32 motion);
u32 nbGetMotionMIDI(nbFormation_t *form, s32 mot);
s32 nbGetMotionNo(nbFormation_t **form, s32 motion);
s32 nbGetMotionNoOrg(nbFormation_t **form, s32 motion);
f32 nbGetMotionSpeed(nbFormation_t **form, s32 motion, f32 ritu);
f32 nbGetMpDrainRitu(s32 nskill, s32 sformindex, s32 dformindex);
s32 nbGetNakama(datUnitWork_t *s);
s32 nbGetNormalSkillAttr(s32 nskill);
nbParty_t *nbGetPartyFromFormindex(s32 formindex);
s32 nbGetPrevActionSeq(void);
s32 nbGetRandamStock(void);
u32 nbGetSelectBit(nbMainProcessData_t *data);
s32 nbGetTarSelStat(void);
void nbGetTargetTypeRuleArea(nbActionProcessData_t *a, datUnitWork_t *work, s32 *ctype, s32 *crule, s32 *carea, s32 rev);
s32 nbGetUniqueIdKoukaPacketCnt(s32 uniqueid);
datUnitVisual_t *nbGetUnitVisual(datUnitWork_t *work);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
datUnitWork_t *nbGetUnitWorkPointer(nbMainProcessData_t *data, nbParty_t *party);
s32 nbHatudoCheckSkill(datUnitWork_t *work, s32 skill);
void nbInitAiScript(nbActionProcessData_t **a, s32 no);
void nbInitCommSelProcess(nbMainProcessData_t *data, nbParty_t *my, nbActionProcessData_t *act);
void nbInitNegoProcess(nbActionProcessData_t **actdata, s32 pformindex, s32 eformindex, s32 negotype, s32 skillid);
s32 nbMakeBadKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t **form);
s32 nbMakeDamagePacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type, s32 hp, s32 mp, s32 badstat, s32 hiteff, s32 dead, s32 deadtype, s32 moji, s32 animeoff);
s32 nbMakeDeadPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 deadchk);
s32 nbMakeDeadVisualPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 deadtype, s32 deadpcm);
s32 nbMakeKaifukuPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, s32 type, s32 hp, s32 mp, u32 badstat);
s32 nbMakeNewPressPacket(s32 startframe, s32 uniqueid, s32 ptype, nbFormation_t **form);
s32 nbMakePressPacket(s32 startframe, s32 uniqueid, f32 press);
s32 nbMakeReturnPacket(s32 startframe, s32 uniqueid, nbParty_t **party);
s32 nbMakeSummonPacket(s32 startframe, s32 uniqueid, s32 side, s32 stockno, s32 formindex);
s32 nbMakeUnitFadeInPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 col, s32 delay, s32 aframe, s32 colframe);
s32 nbMakeUnitFadeOutPacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 col, s32 delay, s32 colframe, s32 aframe);
s32 nbMakeUnitMovePacket(s32 startframe, s32 uniqueid, nbFormation_t **form, u32 select, s32 movetype, f32 ritu);
s32 nbMemoryLoadMotionSe(nbFormation_t *form, s32 mot);
void nbOnOffKoukaPacketFlag(s32 type, u32 flg, s32 sw);
void nbPanelAllShow(void);
void nbPanelAnalyzeEnd(void);
void nbPanelAnalyzeStart(void);
void nbPanelDraw(s32 flag);
void nbPanelPressGaugeShow(void);
void nbPanelStockEnd(void);
void nbPanelStockHide(void);
u32 nbPanelStockSelect(nbMainProcessData_t *pMainData, u32 pad);
void nbPanelStockSelectInit(void);
void nbPlaySe(s32 no);
void nbPushAction(s32 type, s32 from, s32 to, s32 d);
s32 nbRunAi(nbActionProcessData_t **a);
s32 nbRunBadAi(nbActionProcessData_t **a);
void nbSetAutoCommSel(void);
void nbSetBadStat(s32 formindex, s32 sw, s32 badstat);
void nbSetCommSelStat(s32 stat);
s32 nbSetEnemySummonFormation(nbMainProcessData_t **data, s32 devilid);
s32 nbSetHojoAddCounter(s32 formindex, s32 type, s32 point, s32 nvirtual);
void nbSetHojoCounter(s32 formindex, s32 type, s32 point);
void nbSetJyokyoMes(nbActionProcessData_t **a, s32 jyokyomes, s32 var_id, s32 var_ind);
void nbSetKuisibariStop(s32 formindex);
void nbSetNormalSkill0(datUnitWork_t *work);
void nbSetPlayerSummonFormation(nbMainProcessData_t **data);
void nbSetTarSelJyokyoTime(s32 time);
void nbSetTarSelStat(s32 stat);
s32 nbSetTargetProcess(nbActionProcessData_t *act, s32 partyindex, s32 ctype, s32 crule, s32 carea);
void nbSetUnitMotion(nbFormation_t **form, s32 motion2, s32 mode, f32 ritu);
void nbSetWaitMotion(nbFormation_t **form, s32 motion, f32 ritu);
void nbUpdateOrder(void);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);

// 0xf2d8b0
s32 AddTimeListHp(nbActionProcessData_t **a, s32 formindex, s32 add) {
  struct nbTimeList_t_array *timelist;
  u32 max_length;
  s32 v8;

  if (((*a)->data->stat & 0x20000) != 0)
    return 0;
  timelist = (*a)->timelist;
  max_length = timelist->max_length;
  v8 = timelist->m_Items[formindex]->hp + add;
  timelist->m_Items[formindex]->hp = v8 & ~(v8 >> 31);
  return v8 >> 31;
}

// 0xf36c90
s32 CheckAction_AI(nbActionProcessData_t **a) {
  (*a)->nextseq = 7;
  return 1;
}

// 0xf36dd0
s32 CheckAction_AISCR(nbActionProcessData_t **a) {
  dds3ProcessID_t_o **p_AiScriptProcessID;
  nbActionProcessData_t_o *v6;
  char v8;

  p_AiScriptProcessID = &(*a)->data->AiScriptProcessID;
  else if (dds3ExistProcess(&(*a)->data->AiScriptProcessID, 0))
  {
    return 0;
  }
  (*a)->data->AiScriptProcessID = 0;
  v6 = *a;
  if ((*a)->data->negoresult)
  {
    ClearTimeList(a);
    SetHpForTimeList(a);
    v6 = *a;
    v8 = 10;
  }
  else
  {
    v8 = 7;
  }
  v6->nextseq = v8;
  return 1;
}

// 0xf40770
s32 CheckAction_ATO(nbActionProcessData_t **a) {
  effBTL_t_o **p_hEffBTL;

  p_hEffBTL = &(*a)->hEffBTL;
  if (*p_hEffBTL)
  {
    effBTLDelete(p_hEffBTL);
    (*a)->hEffBTL = 0;
  }
  (*a)->nextseq = 22;
  return 1;
}

// 0xf37150
s32 CheckAction_BAD(nbActionProcessData_t **a) {
  u32 BadStat;
  nbActionProcessData_t_o *v8;
  s8 v10;
  s32 formindex;

  ClearTimeList(a);
  SetHpForTimeList(a);
  (*a)->jyokyomes = 0;
  BadStat = nbGetBadStat((*a)->form->formindex, 0);
  if (BadStat > 8)
  {
    if (BadStat != 16)
    {
      if (BadStat == 128)
      if (BadStat != 1024)
    }
    nbMakePressPacket(0, (*a)->uniqueid, -1.0, 0);
    nbMakeNewPressPacket(0, (*a)->uniqueid, 0, &(*a)->form, 0);
    v8 = *a;
    if (((*a)->data->stat & 8) != 0)
  }
  if (BadStat - 1 < 2)
  {
    nbMakePressPacket(0, (*a)->uniqueid, -1.0, 0);
    nbMakeNewPressPacket(0, (*a)->uniqueid, 0, &(*a)->form, 0);
    nbMakeBadKaifukuPacket(5, (*a)->uniqueid, &(*a)->form, 0);
    v8 = *a;
    if (((*a)->data->stat & 8) != 0)
  }
  if (BadStat == 4)
  {
    nbMakePressPacket(0, (*a)->uniqueid, -1.0, 0);
    nbMakeNewPressPacket(0, (*a)->uniqueid, 0, &(*a)->form, 0);
    nbMakeKaifukuPacket(
      10,
      (*a)->uniqueid,
      &(*a)->form,
      0,
      (*a)->work->maxhp >> 3,
      (*a)->work->maxmp >> 3,
      0,
      0);
    v8 = *a;
    if (((*a)->data->stat & 8) != 0)
    {
      nbCameraSetState(0x19u);
      v8 = *a;
    }
    formindex = v8->form->formindex;
    SetTimeList(a, formindex, 0, 30, 30);
    v10 = 18;
  }
  if (BadStat == 8)
  if (nbCheckBadCurse((*a)->form->formindex, 0))
  {
    nbRunBadAi(a);
    v10 = 11;
    (*a)->nextseq = v10;
  }
  return 1;
}

// 0xf374d0
s32 CheckAction_BADWAIT(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v3;
  s32 jyokyomes;
  s32 jyokyomsgid;
  s32 jyo_varind;
  s32 jyo_varid;
  nbActionProcessData_t_o *v8;

  v3 = *a;
  if ((*a)->seqtime == 5)
  {
    jyokyomes = v3->jyokyomes;
    if (jyokyomes >= 1)
    {
      jyokyomsgid = v3->data->jyokyomsgid;
      jyo_varid = v3->jyo_varid;
      jyo_varind = v3->jyo_varind;
      nbDispJyokyoHelp(jyokyomsgid, jyokyomes, jyo_varid, jyo_varind);
    }
  }
  v8 = *a;
  if (((*a)->work->nowcommand | 2) != 0xA)
  {
    if (v8->seqtime > 0x28u || !v8->jyokyomes)
    return 0;
  }
  if (v8->seqtime < 0x1Fu)
    return 0;
  v8->nextseq = 7;
  (*a)->jyokyomes = 0;
  return 1;
}

// 0xf40130
s32 CheckAction_CHECK1(nbActionProcessData_t **a) {
    nbUpdateOrder();
    nbGetDevilFormatFlag(0);
    CheckInotiNego(0);
    CheckBinjoNego(0);
    CheckDeadScript(0);
    nbGetUnitWorkPointer(0, 0);
    datClearCommMemory(0);
    DDS3_PADCHECK_TRIG(0);
    nbPanelAnalyzeEnd();
    nbOnOffKoukaPacketFlag(0, 0, 0);
    return 0;
}

// 0xf40690
s32 CheckAction_CHECK3(nbActionProcessData_t **a) {
  if (nbGetUniqueIdKoukaPacketCnt((*a)->uniqueid, 0) > 0)
    return 0;
  if (((*a)->stat & 0x400) != 0)
  {
    nbPanelStockHide();
  }
  (*a)->nextseq = 21;
  return 1;
}

// 0xf36370
s32 CheckAction_COMM(nbActionProcessData_t **a) {
    DDS3_PADCHECK_PRESS(0);
    DokodemoPoa(0);
    dds3KillProcess(0, 0);
    nbSetAutoCommSel();
    nbGetCommSelStat();
    nbGetUnitWorkPointer(0, 0);
    nbSetPlayerSummonFormation(0);
    nbSetEnemySummonFormation(0, 0);
    nbGetItemSkillNo(0, 0);
    nbCheckBattleSkillError1(0);
    nbDispSkillErrorMessage(0);
    nbSetCommSelStat(0);
    nbPlaySe(0);
    nbCloseCommSel();
    return 0;
}

// 0xf36fa0
s32 CheckAction_DEADSCRIPT(nbActionProcessData_t **a) {
  dds3ProcessID_t_o **p_AiScriptProcessID;
  s32 exist;
  s32 formindex;

  p_AiScriptProcessID = &(*a)->data->AiScriptProcessID;
  else
  {
    exist = dds3ExistProcess(&(*a)->data->AiScriptProcessID, 0);
    if (exist)
      return 0;
  }
  (*a)->data->AiScriptProcessID = 0;
  nbMakeUnitFadeOutPacket(exist, (*a)->uniqueid, &(*a)->form, 0, 10, 10, 10, 0);
  nbAddReturnKoukaPacket(25, (*a)->uniqueid, &(*a)->party, 1, 0);
  formindex = (*a)->form->formindex;
  SetTimeList(a, formindex, 0, 30, 30);
  (*a)->nextseq = 18;
  return 1;
}

// 0xf40890
s32 CheckAction_END(nbActionProcessData_t **a) {
  return 1;
}

// 0xf3f480
s32 CheckAction_ESCAPE(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v3;
  s32 seqtime;
  s32 formindex;

  v3 = *a;
  seqtime = (*a)->seqtime;
  if ((seqtime - 15) < 0xF)
  {
    if (v3->data->endtype == 3)
      return 0;
    v3->packettime = 0;
  }
  if ((seqtime - 30) >= 0xF)
    return 0;
  if (v3->data->endtype == 3)
  {
    v3->packettime = 30;
    dds3FadeOut(0xFFu, 0xFFu, 0xFFu, 0x14u);
    nbAddSePacket(0, (*a)->uniqueid, 0x10000u, 0);
    formindex = (*a)->form->formindex;
    SetTimeList(a, formindex, 0, 17, 17);
    (*a)->nextseq = 18;
    return 1;
  }
  return 0;
}

// 0xf3f7d0
s32 CheckAction_INVISIBLE(nbActionProcessData_t **a) {
  (*a)->nextseq = 18;
  return 1;
}

// 0xf3e600
s32 CheckAction_NEGO(nbActionProcessData_t **a) {
    nbPanelDraw(0);
    datCheckPlayerDead();
    return 0;
}

// 0xf3f110
s32 CheckAction_NEGORESULT(nbActionProcessData_t **a) {
  (*a)->nextseq = 18;
  return 1;
}

// 0xf35cb0
s32 CheckAction_NON(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v3;
  nbActionProcessData_t_o *v6;
  s32 v7;
  nbActionProcessData_t_o *v8;
  char v9;
  u32 BadStat;
  s32 target;
  nbActionProcessData_t_o *v14;
  nbMainProcessData_t_o *v15;
  s32 v16;
  nbActionProcessData_t_o *v18;
  nbMainProcessData_t_o *data;
  s16 flag;
  s32 id;

  (*a)->data->negoresult = 0;
  (*a)->data->negopformindex = 0;
  (*a)->data->negoeformindex = 0;
  (*a)->data->stat &= ~0x4000u;
  v3 = *a;
  v3->massuruid = datGetItemSkillNo(1);
  (*a)->form->motendtype = 0;
  (*a)->party->flag &= ~0x100u;
  v6 = *a;
  if (((*a)->party->flag & 8) != 0)
  {
    else
    {
      v9 = 15;
    }
  }
  switch (v6->type)
  {
    case 1:
      v7 = 4;
      v6->work->nowcommand = 4;
      (*a)->work->nowindex = 386;
      v8 = *a;
    case 2:
      v6->work->nowcommand = 4;
      (*a)->work->nowindex = (*a)->data->prevcommind;
      v8 = *a;
      v7 = 3;
    case 3:
      v6->work->nowcommand = 4;
      (*a)->work->nowindex = 386;
      v8 = *a;
      v7 = 5;
      v8->negotype = v7;
      target = (*a)->target;
      SetTargetParty(a, target);
    case 4:
      v6->work->nowcommand = 1;
      (*a)->work->nowindex = (*a)->adata;
      v16 = (*a)->target;
      SetTargetParty(a, v16);
      v18 = *a;
      data = (*a)->data;
      v18->select = nbGetSelectBit(data);
      (*a)->stat |= 4u;
    case 5:
      else
      {
        v9 = 19;
      }
    default:
      nbSetHojoAddCounter(v6->form->formindex, 17, 1, 0);
      nbSetHojoAddCounter((*a)->form->formindex, 18, 1, 0, 0);
      BadStat = nbGetBadStat((*a)->form->formindex, 0);
      if (BadStat <= 4)
      {
        if (((1 << BadStat) & 0x16) == 0)
        v6 = *a;
        v9 = 4;
      }
      if (BadStat == 16 || BadStat == 1024 || BadStat == 128)
      v6 = *a;
      flag = (*a)->party->flag;
      if ((flag & 2) == 0)
      {

        {
          v9 = 21;
        }
      }
      if (CheckMukanNego(a))
      {
        (*a)->work->nowcommand = 4;
        (*a)->work->nowindex = 386;
        (*a)->negotype = 1;
      }
      if (CheckSenseiNego(a))
      {
        (*a)->work->nowcommand = 4;
        (*a)->work->nowindex = 386;
        (*a)->negotype = 2;
        SetTargetPlayer(a);
        v14 = *a;
        v15 = (*a)->data;
        v14->select = nbGetSelectBit(v15);
        v6 = *a;
        v9 = 7;
      }
      v6 = *a;
      if (dds3DebugSign == 1 && (v6->data->stat & 0x10000000) != 0)
      {
        {
        }
        v9 = 1;
      }
      id = v6->work->id;
      if (Get(id, 0)->scriptid)
      {
        v6 = *a;
        v9 = 3;
      }
      else
      {
        v6 = *a;
        v9 = 2;
      }
      v6->nextseq = v9;
      return 1;
  }
}

// 0xf3abd0
s32 CheckAction_READY(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v3;
  s32 result;
  nbActionProcessData_t_o *v5;
  s32 uniqueid;
  nbFormation_t_o *form;
  s32 motionO;
  u32 MotionMIDI;
  nbActionProcessData_t_o *v10;
  bool IsNullOrEmpty;
  nbActionProcessData_t_o *v12;
  System_String_o *SKILLSE_AKEY;
  System_String_o *se0_name;
  System_String_o *v17;
  System_String_o *se1_name;
  UnityEngine_Texture_array *pTexture;
  nbActionProcessData_t_o *v21;
  System_Byte_array *hBed;
  effBTL_t_o *v23;
  u32 timer;
  char v25;
  nbActionProcessData_t_o *v26;
  s32 jyokyomes;
  s32 jyokyomsgid;
  s32 jyo_varind;
  s32 jyo_varid;

  v3 = *a;
  result = 0;
  switch ((*a)->seqcnt)
  {
    case 0:
      ++v3->skilltime;
      v5 = *a;
      if ((*a)->motse)
      {
        v5->data->stat &= ~0x200u;
        uniqueid = (*a)->uniqueid;
        form = (*a)->form;
        motionO = (*a)->motionO;
        MotionMIDI = nbGetMotionMIDI(form, motionO);
        nbAddSePacket2(0, uniqueid, MotionMIDI);
        v5 = *a;
      }
      v5->hEffBTL = 0;
      v10 = *a;
      if (!(*a)->hBed && !v10->hSkillSe)
      {
        result = 0;
      }
      IsNullOrEmpty = IsNullOrEmpty(v10->se0_name);
      v12 = *a;
      if (IsNullOrEmpty)
        v12->seqcnt = 3;
      else
        v12->seqcnt = 1;
      result = 0;
      break;
    case 1:
      se0_name = v3->se0_name;
      LoadKeysSE1(3, SKILLSE_AKEY, se0_name);
      (*a)->seqcnt = 2;
      result = 0;
      break;
    case 2:
      v17 = SKILLSE_AKEY;
      se1_name = v3->se1_name;
      LoadKeysSE1(3, v17, se1_name);
      (*a)->seqcnt = 3;
      result = 0;
      break;
    case 3:
      ++v3->skilltime;
      pTexture = (*a)->pTexture;
      billSetTexture(pTexture);
      v21 = *a;
      hBed = (*a)->hBed;
      v23 = effBTLCreate(hBed);
      result = 0;
      v21->hEffBTL = v23;
      (*a)->hBed = 0;
      v10 = *a;
      v10->seqcnt = 5;
      break;
    case 5:
      timer = v3->timer;
      if (timer && timer > v3->seqtime)
      {
        result = 0;
      }
      else
      {
        switch (v3->work->nowcommand)
        {
          case 0:
          case 1:
          case 5:
          case 6:
            else
            {
              v25 = 8;
            }
          case 2:
            v25 = 13;
          case 3:
          case 8:
          case 9:
          case 0xA:
            else
            {
              v25 = 12;
            }
          case 4:
            v25 = 9;
          case 7:
            v25 = 14;
            v3->nextseq = v25;
            break;
          default:
            break;
        }
        v26 = *a;
        jyokyomes = (*a)->jyokyomes;
        if (jyokyomes >= 1)
        {
          jyokyomsgid = v26->data->jyokyomsgid;
          jyo_varid = v26->jyo_varid;
          jyo_varind = v26->jyo_varind;
          nbDispJyokyoHelp(jyokyomsgid, jyokyomes, jyo_varid, jyo_varind);
          (*a)->jyokyomes = 0;
        }
        result = 1;
      }
      break;
    default:
      return result;
  }
  return result;
}

// 0xf3f750
s32 CheckAction_RETURN(nbActionProcessData_t **a) {
  (*a)->nextseq = 18;
  return 1;
}

// 0xf3e300
s32 CheckAction_SKILL(nbActionProcessData_t **a) {
  (*a)->nextseq = 18;
  return 1;
}

// 0xf37e30
s32 CheckAction_STKSEL(nbActionProcessData_t **a) {
    nbSetCommSelStat(0);
    nbPlaySe(0);
    nbPanelStockEnd();
    nbPanelStockSelect(0, 0);
    nbCloseCommSel();
    return 0;
}

// 0xf376a0
s32 CheckAction_TARSEL(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v3;
  u32 stat;
  s32 TarSelStat;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v10;
  struct nbFormation_t_array *v12;
  struct nbFormation_t_array *v14;
  struct nbFormation_t_array *v16;
  struct nbFormation_t_array *v18;
  struct nbFormation_t_array *v20;
  struct nbFormation_t_array *v22;
  struct nbFormation_t_array *v24;
  struct nbFormation_t_array *v26;
  struct nbFormation_t_array *v28;
  struct nbFormation_t_array *v30;
  struct nbFormation_t_array *v32;
  struct nbFormation_t_array *v34;
  struct nbFormation_t_array *v36;
  struct nbFormation_t_array *v38;
  UnityEngine_GameObject_o *BattleUI;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v44;
  UnityEngine_GameObject_o *gameObject;
  nbMainProcessData_t_o *data;
  u32 SelectBit;
  nbActionProcessData_t_o *v49;
  u32 v50;
  struct datUnitWork_t_o *work;
  s32 nowcommand;
  s32 v53;
  s32 nowindex;
  s32 v55;
  s32 v56;

  v3 = *a;
  if (((*a)->data->stat & 0x40) != 0)
  {
    stat = v3->stat;
    if ((stat & 0x80) == 0)
    {
      v3->stat = stat | 0x80;
      nbSetCommSelStat(2);
      nbSetAutoCommSel();
      (*a)->seq = 1;
      return 0;
    }
  }
  TarSelStat = nbGetTarSelStat();
  if (TarSelStat)
  {
    if (TarSelStat == 2)
    {
      form = (*a)->data->form;
      form->m_Items[0]->stat &= ~8u;
      v10 = (*a)->data->form;
      v10->m_Items[1]->stat &= ~8u;
      v12 = (*a)->data->form;
      v12->m_Items[2]->stat &= ~8u;
      v14 = (*a)->data->form;
      v14->m_Items[3]->stat &= ~8u;
      v16 = (*a)->data->form;
      v16->m_Items[4]->stat &= ~8u;
      v18 = (*a)->data->form;
      v18->m_Items[5]->stat &= ~8u;
      v20 = (*a)->data->form;
      v20->m_Items[6]->stat &= ~8u;
      v22 = (*a)->data->form;
      v22->m_Items[7]->stat &= ~8u;
      v24 = (*a)->data->form;
      v24->m_Items[8]->stat &= ~8u;
      v26 = (*a)->data->form;
      v26->m_Items[9]->stat &= ~8u;
      v28 = (*a)->data->form;
      v28->m_Items[10]->stat &= ~8u;
      v30 = (*a)->data->form;
      v30->m_Items[11]->stat &= ~8u;
      v32 = (*a)->data->form;
      v32->m_Items[12]->stat &= ~8u;
      v34 = (*a)->data->form;
      v34->m_Items[13]->stat &= ~8u;
      v36 = (*a)->data->form;
      v36->m_Items[14]->stat &= ~8u;
      v38 = (*a)->data->form;
      v38->m_Items[15]->stat &= ~8u;
      nbSetCommSelStat(2);
      (*a)->seq = 1;
      BattleUI = GetBattleUI(0);
      if (op_Inequality(BattleUI, 0, 0))
      {
        transform = get_transform(BattleUI, 0);
        v44 = Find(transform, StringLiteral_19226, 0);
        gameObject = get_gameObject(v44);
        if (!get_activeSelf(gameObject))
          SetActive(gameObject, 1, 0);
      }
    }
    return 0;
  }
  data = (*a)->data;
  SelectBit = nbGetSelectBit(data);
  v49 = *a;
  v50 = SelectBit;
  if (((*a)->stat & 0x80) != 0)
  work = v49->work;
  nowcommand = work->nowcommand;
  if (nowcommand == 1)
  {
    nowindex = work->nowindex;
  }
  else
  {
    if (nowcommand != 5)
    v53 = work->nowindex;
    nowindex = nbGetItemSkillNo(v49, v53);
    if (nowindex < 0)
  }
  v55 = nbCheckBattleSkillError2(nowindex, v50);
  if (!v55)
  {
    nbPlaySe(8);
    nbCloseCommSel();
    (*a)->select = v50;
    (*a)->nextseq = 7;
    return 1;
  }
  v56 = v55;
  nbDispSkillErrorMessage(v55);
  if (v56 == 4)
    nbSetTarSelJyokyoTime(29);
  nbSetTarSelStat(1);
  return 0;
}

// 0xf3f310
s32 CheckAction_WAIT(nbActionProcessData_t **a) {
  (*a)->nextseq = 18;
  return 1;
}

// 0xf2df30
s32 CheckArrCounter(nbActionProcessData_t **a) {
  nbFormation_t_o *EventForm;
  s32 formindex;
  struct nbTimeList_t_array *timelist;
  s32 v8;
  u32 v9;
  s32 partyindex;
  s32 v13;

  if ((*a)->partyindex > 3)
    return 0;
  EventForm = nbGetEventForm();
  formindex = EventForm->formindex;
  timelist = (*a)->timelist;
  if (!timelist->m_Items[formindex]->hp && (nbGetDevilFormatFlag(formindex) & 0x100) == 0)
    return 0;
  v8 = EventForm->formindex;
  if (nbGetUnitWorkFromFormindex(v8)->id != 291)
    return 0;
  if (evtBitCheck(2129))
  {
    v9 = HIWORD((*a)->stat) & 1;
    if (!evtBitCheck(2130))
  }
  else
  {
    v9 = 0;
    if (!evtBitCheck(2130))
  }
  if (((*a)->stat & 0x20000) != 0)
    v9 = 1;
  if (evtBitCheck(2131))
  {
    if (((*a)->stat & 0x40000) != 0)
      v9 = 1;
    if (!evtBitCheck(2132))
    {
      if (evtBitCheck(2133))
      if (!evtBitCheck(2134))
      if (!((*a)->stat & 0x200000 | v9))
        return 0;
    }
  }
  else  if (((*a)->stat & 0x80000) != 0)
    v9 = 1;
  if (!evtBitCheck(2133))
  if (((*a)->stat & 0x100000) != 0)
    v9 = 1;
  if (evtBitCheck(2134))
  if (!v9)
    return 0;
  partyindex = EventForm->partyindex;
  v13 = (*a)->partyindex;
  nbPushAction(4, partyindex, v13, 243);
  Write(StringLiteral_19195, 0);
  return 1;
}

// 0xf34630
s32 CheckBinjoNego(nbActionProcessData_t **a) {
    evtGetAgeOfMoon();
    datCheckTalk(0);
    nbGetUnitWorkFromFormindex(0);
    nbGetDevilFormatFlag(0);
    Get(0);
    datSearchDevilStock(0);
    dds3GetRandIntA(0, 0);
    nbPushAction(0, 0, 0, 0);
    return 0;
}

// 0xf2daf0
s32 CheckCounter(nbActionProcessData_t **a, s32 from, s32 to) {
  System_Array_o *v7;
  System_Array_o *v8;
  struct nbTimeList_t_array *timelist;
  datUnitWork_t_o *UnitWorkFromFormindex;
  u16 badstatus;
  u32 v15;
  datUnitWork_t_o *v16;
  s32 result;
  u64 v18;
  System_Array_o *v19;
  u32 v21;
  struct datSpecialSkill_t_array *tbl;
  s64 v26;
  s32 v28;
  s32 v30;
  struct nbFormation_t_array *form;
  u32 max_length;
  s32 partyindex;
  s32 v36;
  System_Array_o *v38;
  s32 v39;

  v7 = NewSpecific(s32, 4u);
  InitializeArray_1543888(v7, Field__PrivateImplementationDetails__4797B38EFD2D49FD8EEBD799EA2B1A2EA7AD3D1A);
  v8 = NewSpecific(s32, 3u);
  InitializeArray_1543888(v8, Field__PrivateImplementationDetails__849DAB0CDCCBC47FD6B5C48A28BDB3C51B91146F);
  timelist = (*a)->timelist;
  if (!timelist->m_Items[to]->hp && (nbGetDevilFormatFlag(to) & 0x100) == 0)
    return 0;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(from);
  badstatus = UnitWorkFromFormindex->badstatus;
  v15 = badstatus & 0xFFF;
  v16 = UnitWorkFromFormindex;
  if (v15 > 0x10)
  {
    result = 0;
    if (v15 == 128 || v15 == 256 || v15 == 1024)
      return result;
  }
  if (v15 - 1 < 2)
    return 0;
  result = 0;
  if ((badstatus & 0xFFF) != 4 && (badstatus & 0xFFF) != 0x10)
  {
    v38 = v8;
    v39 = from;
    v18 = 0;
    v19 = v7 + 2;
    while (1)
    {
      v21 = *(&v19->klass + v18);
      if ((v21 & 0x80000000) != 0)
        return 0;
      if (datCheckSyojiSkill(v16, v21))
      {
        v26 = *(&v19->klass + v18) - 288LL;
        v28 = 100 / tbl->m_Items[v26]->n;
        if (v28 > dds3GetRandIntA(0x64u, StringLiteral_19193))
        {
          v30 = *(&v38[2].klass + v18);
          if (v30)
          {
            form = (*a)->data->form;
            max_length = form->max_length;
            partyindex = form->m_Items[v39]->partyindex;
            v36 = (*a)->data->form->m_Items[to]->partyindex;
            nbPushAction(4, partyindex, v36, v30);
            Write(StringLiteral_19194, 0);
            return 1;
          }
          return 0;
        }
      }
      if (++v18 >= LODWORD(v7[1].monitor))
    }
  }
  return result;
}

// 0xf34ae0
void CheckDeadScript(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v3;
  s64 i;
  struct nbFormation_t_array *form;
  s64 v7;
  struct nbTimeList_t_array *timelist;
  s32 v10;
  s32 v11;
  s32 v12;

  v3 = *a;
  if ((*a)->type != 5)
  {
    for (i = 8; ; ++i)
    {
      form = v3->data->form;
      v7 = *(&form->obj.klass + i);
      if ((*(v7 + 136) & 1) != 0)
      {
        timelist = (*a)->timelist;
        if (!*(*(&timelist->obj.klass + i) + 20LL) && (nbGetDevilFormatFlag(i - 4) & 0x100) == 0)
        {
          else
          {
            v10 = nbCheckDeadScript(v7);
            if (!v10)
          }
          v11 = v10;
          v12 = *(v7 + 176);
          nbPushAction(5, v12, 0, v11);
        }
      }
      if (i == 17)
        return;
      v3 = *a;
    }
  }
}

// 0xf34100
s32 CheckInotiNego(nbActionProcessData_t **a) {
    evtGetAgeOfMoon();
    datCheckTalk(0);
    nbGetUnitWorkFromFormindex(0);
    nbGetDevilFormatFlag(0);
    Get(0);
    dds3GetRandIntA(0, 0);
    nbPushAction(0, 0, 0, 0);
    return 0;
}

// 0xf34c90
s32 CheckKoketaNego(nbActionProcessData_t **a) {
  u64 *v3;
  nbActionProcessData_t_o *v5;
  u64 *v6;
  u32 v7;
  s64 i;
  struct nbFormation_t_array *form;
  u64 v10;
  s64 v12;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v15;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct nbTimeList_t_array *timelist;
  u32 v20;
  s64 v21;
  u32 RandIntA;
  s32 v26;
  s32 partyindex;

  v3 = NewSpecific(sbyte, 0x20u);
  v5 = *a;
  if (((*a)->party->flag & 6) != 0 || v5->partyindex > 3)
    return 0;
  v6 = v3;
  v7 = 0;
  for (i = 8; ; ++i)
  {
    form = v5->data->form;
    v10 = i - 4;
    v12 = *(&form->obj.klass + i);
    if ((~*(v12 + 136) & 0x41) == 0)
    {
      party = (*a)->data->party;
      if ((party->m_Items[*(v12 + 176)]->flag & 1) != 0)
      {
        v15 = (*a)->data->party;
        if ((v15->m_Items[*(v12 + 176)]->flag & 0x20) == 0)
        {
          UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(v10);
          timelist = (*a)->timelist;
          if (*(*(&timelist->obj.klass + i) + 20LL) || (nbGetDevilFormatFlag(v10) & 0x100) != 0)
          {
            v20 = UnitWorkFromFormindex->badstatus & 0xFFF;
            if (v20 <= 4)
            {
              if (v20 == 4 || v20 - 1 < 2)
            }
            else            v21 = v7;
            ++v7;
            *(v6 + v21 + 32) = *(v12 + 176);
          }
        }
      }
    }
    if (i == 17)
      break;
    v5 = *a;
  }
  if (!v7)
    return 0;
  RandIntA = dds3GetRandIntA(v7, StringLiteral_19221);
  v26 = *(v6 + RandIntA + 32);
  partyindex = (*a)->partyindex;
  nbPushAction(3, v26, partyindex, 0);
  Write(StringLiteral_19222, 0);
  return 1;
}

// 0xf33b10
s32 CheckMukanNego(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v3;
  struct nbMainProcessData_t_o *data;
  s32 id;
  s32 v7;
  datUnitWork_t_o *work;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v15;
  s32 v17;
  struct nbMainProcessData_t_o *v19;
  s32 v20;
  s64 i;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v24;
  s32 v26;
  nbActionProcessData_t_o *v27;

  v3 = *a;
  data = (*a)->data;
  if (data->StageMajor - 240 < 7 || (data->stat & 1) != 0 || (v3->party->flag & 2) == 0)
    return 0;
  id = v3->work->id;
  if (!Get(id, 0)->mukantype)
    return 0;
  v7 = (*a)->work->id;
  if ((datSearchDevilStock(v7) & 0x80000000) == 0)
    return 0;
  if (evtGetAgeOfMoon() == 8)
    return 0;
  work = (*a)->work;
  if (!datCheckTalk(work))
    return 0;
  unitwork = DDS3_GBWK->unitwork;
  v15 = unitwork->m_Items[0];
  if (!datCheckTalk(v15))
    return 0;
  if ((*a)->data->enemypcnt < 2)
    return 0;
  if (nbGetHojoCounter((*a)->form->formindex, 16, 0))
    return 0;
  v19 = (*a)->data;
  if ((v19->stat & 0x2000000) == 0 && v19->turn < 3u)
    return 0;
  v20 = 0;
  for (i = 8; ; ++i)
  {
    form = v19->form;
    if ((*(*(&form->obj.klass + i) + 136LL) & 1) != 0)
    {
      v24 = (*a)->data->form;
      if ((*(*(&v24->obj.klass + i) + 136LL) & 0x40) != 0 && !nbGetHojoCounter(i - 4, 16))
        ++v20;
    }
    if (i == 17)
      break;
    v19 = (*a)->data;
  }
  if (v20 != 1)
    return 0;
  v26 = ((*a)->data->stat & 0x2000000) != 0 ? 100 : 5;
  if (dds3GetRandIntA(0x64u, StringLiteral_19215) >= v26)
    return 0;
  v27 = *a;
  v17 = 1;
  nbSetHojoAddCounter(v27->form->formindex, 16, 1, 0);
  return v17;
}

// 0xf33e50
s32 CheckSenseiNego(nbActionProcessData_t **a) {
  struct nbMainProcessData_t_o *data;
  s32 result;
  s32 id;
  struct datUnitWork_t_o *work;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v13;
  struct nbMainProcessData_t_o *v15;
  s32 v16;

  data = (*a)->data;
  if (data->StageMajor - 240 < 7)
    return 0;
  if ((data->stat & 0x191) != 0x80)
    return 0;
  else if (evtGetAgeOfMoon() == 8)
  {
    return 0;
  }
  id = (*a)->work->id;
  if (!Get(id, 0)->senseitype)
    return 0;
  work = (*a)->work;
  if (work->id - 368 < 0x20)
    return 0;
  result = datCheckTalk(work);
  if (result)
  {
    unitwork = DDS3_GBWK->unitwork;
    v13 = unitwork->m_Items[0];
    result = datCheckTalk(v13);
    if (result)
    {
      v15 = (*a)->data;
      if ((v15->stat & 0x2000000) != 0)
        v16 = 100;
      else
        v16 = 21 / v15->enemypcnt;
      if (dds3GetRandIntA(0x64u, StringLiteral_19216) >= v16)
      {
        return 0;
      }
      else
      {
        (*a)->data->stat |= 0x100u;
        return 1;
      }
    }
  }
  return result;
}

// 0xf2da60
s32 CheckTimeListDead(nbActionProcessData_t **a, s32 formindex) {
  struct nbTimeList_t_array *timelist;

  timelist = (*a)->timelist;
  return !timelist->m_Items[formindex]->hp && ((nbGetDevilFormatFlag(formindex) >> 8) & 1) == 0;
}

// 0xf31dd0
s32 CheckTimeListDeadEnemyParty(nbActionProcessData_t **a, s32 formindex) {
  u64 v5;
  u64 v6;
  struct nbFormation_t_array *form;
  struct nbTimeList_t_array *timelist;

  if (formindex <= 3)
    v5 = 14;
  else
    v5 = 4;
  v6 = 4LL * (formindex < 4);
  while (1)
  {
    form = (*a)->data->form;
    if ((form->m_Items[v6]->stat & 1) != 0)
    {
      timelist = (*a)->timelist;
      if (timelist->m_Items[v6]->hp || (nbGetDevilFormatFlag(v6) & 0x100) != 0)
        break;
    }
    if (++v6 >= v5)
      return 1;
  }
  return 0;
}

// 0xf31b40
void ClearTimeList(nbActionProcessData_t **a) {
  s64 i;
  struct nbTimeList_t_array *timelist;
  u64 v4;
  struct nbTimeList_t_array *v6;
  struct nbTimeList_t_array *v8;
  s64 v10;

  for (i = 4; i != 36; ++i)
  {
    timelist = (*a)->timelist;
    v4 = i - 4;
    *(*(&timelist->obj.klass + i) + 16LL) = 0;
    v6 = (*a)->timelist;
    *(*(&v6->obj.klass + i) + 18LL) = 0;
    v8 = (*a)->timelist;
    v10 = *(&v8->obj.klass + i);
    *(v10 + 20) = 0;
  }
}

// 0xf350a0
void DokodemoPoa(nbActionProcessData_t **a) {
  s64 v3;
  struct nbMainProcessData_t_o *data;
  struct nbFormation_t_array *v5;
  dds3ProcessID_t_o **p_CommSelProcessID;
  nbFormation_t_o *form;

  form = 0;
  v3 = 8;
  data = (*a)->data;
  do
  {
    v5 = data->form;
    form = *(&v5->obj.klass + v3);
    if ((~form->stat & 0x41) == 0)
    {
      nbMakeDeadVisualPacket(0, (*a)->uniqueid, &form, 0, 1, 0);
      SetTimeList(a, v3 - 4, 0, 30, 30);
      SetDeadPacket(a, v3 - 4);
    }
    data = (*a)->data;
    ++v3;
  }
  while (v3 != 18);
  if (data->CommSelProcessID)
  {
    p_CommSelProcessID = &data->CommSelProcessID;
    dds3KillProcess(p_CommSelProcessID, 0);
  }
}

// 0xf32240
s32 GetAllEndTime(nbActionProcessData_t **a) {
  s32 v2;
  s64 i;
  struct nbTimeList_t_array *timelist;
  struct nbTimeList_t_array *v6;

  v2 = 0;
  for (i = 4; i != 36; ++i)
  {
    while (1)
    {
      timelist = (*a)->timelist;
      if (v2 < *(*(&timelist->obj.klass + i) + 18LL))
        break;
      if (++i == 36)
        return v2;
    }
    v6 = (*a)->timelist;
    v2 = *(*(&v6->obj.klass + i) + 18LL);
  }
  return v2;
}

// 0xf32310
s32 GetAllUnlockTime(nbActionProcessData_t **a) {
  s32 v2;
  s64 i;
  struct nbTimeList_t_array *timelist;
  struct nbTimeList_t_array *v6;

  v2 = 0;
  for (i = 4; i != 36; ++i)
  {
    while (1)
    {
      timelist = (*a)->timelist;
      if (v2 < *(*(&timelist->obj.klass + i) + 16LL))
        break;
      if (++i == 36)
        return v2;
    }
    v6 = (*a)->timelist;
    v2 = *(*(&v6->obj.klass + i) + 16LL);
  }
  return v2;
}

// 0xf2da10
s32 GetEndTime(nbActionProcessData_t **a, s32 formindex) {
  struct nbTimeList_t_array *timelist;

  timelist = (*a)->timelist;
  return timelist->m_Items[formindex]->endframe;
}

// 0xf323e0
void GetKoukaList(nbActionProcessData_t **a, s8 ***koukalist, u32 select, s32 nskill) {
    dds3GetRandIntA(0, 0);
    nbGetDevilFormatFlag(0);
    Get(0);
    nbGetUnitWorkFromFormindex(0);
}

// 0xf41680
SOBED_PB_LIST *GetPbList(void) {
  return pb_list;
}

// 0xf3a830
nbActionProcess_SOBED *GetSOBED(s32 no) {
  struct nbActionProcess_SOBED_array *sobedtbl_dante;
  nbActionProcess_SOBED_o **m_Items;
  struct nbActionProcess_SOBED_array *sobedtbl;
  struct nbActionProcess_SOBED_array *v13;
  struct nbActionProcess_SOBED_array *v16;
  struct nbActionProcess_SOBED_array *v19;
  struct nbActionProcess_SOBED_array *v22;
  struct nbActionProcess_SOBED_array *v25;
  struct nbActionProcess_SOBED_array *v28;
  struct nbActionProcess_SOBED_array *v31;
  struct nbActionProcess_SOBED_array *v34;

  if (evtBitCheck(3712))
  {
    switch (no)
    {
      case 262:
        m_Items = sobedtbl_dante->m_Items;
        break;
      case 263:
        v13 = sobedtbl_dante;
        m_Items = &v13->m_Items[1];
        break;
      case 264:
        v16 = sobedtbl_dante;
        m_Items = &v16->m_Items[2];
        break;
      case 265:
        v19 = sobedtbl_dante;
        m_Items = &v19->m_Items[3];
        break;
      case 266:
        v22 = sobedtbl_dante;
        m_Items = &v22->m_Items[4];
        break;
      case 267:
        v25 = sobedtbl_dante;
        m_Items = &v25->m_Items[5];
        break;
      case 268:
        v28 = sobedtbl_dante;
        m_Items = &v28->m_Items[6];
        break;
      case 269:
        v31 = sobedtbl_dante;
        m_Items = &v31->m_Items[7];
        break;
      case 274:
        v34 = sobedtbl_dante;
        m_Items = &v34->m_Items[8];
        break;
      default:
    }
  }
  else
  {
    m_Items = &sobedtbl->m_Items[no];
  }
  return *m_Items;
}

// 0xf2d970
s32 GetTimeListHp(nbActionProcessData_t **a, s32 formindex) {
  struct nbTimeList_t_array *timelist;

  timelist = (*a)->timelist;
  return timelist->m_Items[formindex]->hp;
}

// 0xf2d9c0
s32 GetUnlockTime(nbActionProcessData_t **a, s32 formindex) {
  struct nbTimeList_t_array *timelist;

  timelist = (*a)->timelist;
  return timelist->m_Items[formindex]->lockframe;
}

// 0xf41220
nbActionProcessData_t *InitActionProcessData(nbMainProcessData_t **data, s32 type, s32 from, s32 to, s32 d) {
  u64 *v11;
  struct nbParty_t_array *party;
  nbParty_t_o *v16;
  struct nbFormation_t_array *form;
  nbMainProcessData_t_o *v19;
  nbActionProcessData_t_o *a;

  v11 = Allocate(nbActionProcessData_t);
  nbActionProcessData_t___ctor(v11);
  a = v11;
  nbActionProcessData_t__Clear(v11);
  *(v11 + 7) = ++nba_uniqueid;
  v11[2] = *data;
  *(v11 + 32) = 0;
  party = (*data)->party;
  v16 = party->m_Items[from];
  v11[8] = v16;
  if ((v16->flag & 8) != 0)
  {
    v11[9] = 0;
  }
  else
  {
    form = (*data)->form;
    v11[9] = form->m_Items[v16->formindex];
  }
  v19 = *data;
  v11[10] = nbGetUnitWorkPointer(v19, v16);
  *(v11 + 22) = from;
  *(v11 + 23) = type;
  *(v11 + 24) = to;
  *(v11 + 31) = d;
  *(v11 + 44) = 3212836864LL;
  ClearTimeList(&a);
  return v11;
}

// 0xf34ff0
void KyouseiPress(nbActionProcessData_t **a) {
  struct nbMainProcessData_t_o *data;
  dds3ProcessID_t_o **p_CommSelProcessID;

  (*a)->data->press4_p = 0;
  (*a)->data->press4_ten = 0;
  data = (*a)->data;
  if (data->CommSelProcessID)
  {
    p_CommSelProcessID = &data->CommSelProcessID;
    dds3KillProcess(p_CommSelProcessID, 0);
  }
}

// 0xf2d4f0
u32 MAKE_SKILL_MIDI(u32 x) {
  return 0;
}

// 0xf41600
u32 MAKE_SKILL_MIDI_15996416(s32 x) {
  return (x << 16) + 0x2000000;
}

// 0xf3e220
s32 MAKE_SKILL_SE00(s32 x) {
  System_String_o *se0_str;

  if (!GetSOBED(x)->se0_str)
    return -1;
  se0_str = GetSOBED(x)->se0_str;
  return FindId(1, se0_str);
}

// 0xf3e160
s32 MAKE_SKILL_SE01(s32 x) {
  System_String_o *se1_str;

  se1_str = GetSOBED(x)->se1_str;
  if (!se1_str)
    return -1;
  return FindId(1, se1_str);
}

// 0xf32020
void OverwriteTimeList(nbActionProcessData_t **a, s32 formindex, s32 start, s32 locktime, s32 endtime) {
  struct nbTimeList_t_array *timelist;
  struct nbTimeList_t_array *v8;
  struct nbTimeList_t_array *v10;
  struct nbTimeList_t_array *v12;
  struct nbTimeList_t_array *v14;
  struct nbTimeList_t_array *v16;

  if ((locktime & 0x80000000) == 0)
  {
    timelist = (*a)->timelist;
    if (locktime + start > timelist->m_Items[formindex]->lockframe)
    {
      v8 = (*a)->timelist;
      v8->m_Items[formindex]->lockframe = locktime + start;
    }
  }
  if ((endtime & 0x80000000) == 0)
  {
    v10 = (*a)->timelist;
    if (endtime + start > v10->m_Items[formindex]->endframe)
    {
      v12 = (*a)->timelist;
      v12->m_Items[formindex]->endframe = endtime + start;
    }
    v14 = (*a)->timelist;
    if (v14->m_Items[formindex]->endframe < (*a)->timelist->m_Items[formindex]->lockframe)
    {
      v16 = (*a)->timelist;
      v16->m_Items[formindex]->endframe = (*a)->timelist->m_Items[formindex]->lockframe;
    }
  }
}

// 0xf2d540
void SetActionSeq(nbActionProcessData_t **a, s32 seq) {
  s8 v3;
  struct nbActionProcess_nbActionFunc_t_array *ActionFunc;

  v3 = seq;
  (*a)->seq = v3;
  (*a)->seqtime = 0;
  (*a)->nextseq = 0;
  (*a)->seqcnt = 0;
  Invoke(ActionFunc->m_Items[(*a)->seq]->set, a, 0);
}

// 0xf36c00
void SetAction_AI(nbActionProcessData_t **a) {
  (*a)->work->nowcommand = -1;
  (*a)->work->nowindex = 0;
  nbRunAi(a);
}

// 0xf36d00
void SetAction_AISCR(nbActionProcessData_t **a) {
  s32 id;
  s32 scriptid;

  (*a)->work->nowcommand = -1;
  (*a)->work->nowindex = 0;
  id = (*a)->work->id;
  scriptid = Get(id, 0)->scriptid;
  nbInitAiScript(a, scriptid);
}

// 0xf40760
void SetAction_ATO(nbActionProcessData_t **a) {
  ;
}

// 0xf370e0
void SetAction_BAD(nbActionProcessData_t **a) {
  nbPanelAllShow();
  nbPanelPressGaugeShow();
}

// 0xf37420
void SetAction_BADWAIT(nbActionProcessData_t **a) {
  (*a)->stat |= 0x20u;
  if (((*a)->data->stat & 8) != 0)
  {
    nbCameraSetState(0x19u);
  }
  else
  {
    nbCameraSetState(3u);
  }
}

// 0xf3f840
void SetAction_CHECK1(nbActionProcessData_t **a) {
    nbGetDevilFormatFlag(0);
    nbGetBadStat(0);
    CheckTimeListDeadEnemyParty(0, 0);
    SetDamagePacket(0, 0);
    nbMakeDeadVisualPacket(0, 0, 0, 0, 0);
    SetTimeList(0, 0, 0, 0, 0);
    SetDeadPacket(0, 0);
    nbMakeUnitFadeInPacket(0, 0, 0, 0, 0, 0, 0);
    nbAddFormOnOffPacket(0, 0, 0, 0);
    nbAddMotionStopClearPacket(0, 0, 0);
    nbAddHatudoEffectEndPacket(0, 0);
    nbAddPanelStockFadeOutPacket(0, 0);
    nbAddPanelStockEndPacket(0, 0);
}

// 0xf40680
void SetAction_CHECK3(nbActionProcessData_t **a) {
  ;
}

// 0xf36280
void SetAction_COMM(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v3;
  nbActionProcessData_t_o *v5;
  nbMainProcessData_t_o *data;
  nbParty_t_o *party;

  if ((byte_3F58489 & 1) == 0)
  {
    v3 = *a;
    if (((*a)->data->stat & 0x40) == 0)
    v3->stat |= 0x80u;
  }
  v3 = *a;
  if (((*a)->data->stat & 0x40) != 0)
  nbDelAllKoukaPacketType(38);
  nbPanelAllShow();
  nbPanelPressGaugeShow();
  v5 = *a;
  data = v5->data;
  party = v5->party;
  nbInitCommSelProcess(data, party, v5);
}

// 0xf36ef0
void SetAction_DEADSCRIPT(nbActionProcessData_t **a) {
  s32 adata;

  ClearTimeList(a);
  SetHpForTimeList(a);
  adata = (*a)->adata;
  nbInitAiScript(a, adata);
}

// 0xf40820
void SetAction_END(nbActionProcessData_t **a) {
  SetAuto(0);
}

// 0xf3f380
void SetAction_ESCAPE(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v3;
  struct nbMainProcessData_t_o *data;
  s32 esccnt;
  nbActionProcessData_t_o **v7;

  v3 = *a;
  data = (*a)->data;
  esccnt = data->esccnt;
  if (esccnt != 255)
  {
    data->esccnt = esccnt + 1;
    v3 = *a;
  }
  nbMakePressPacket(0, v3->uniqueid, -10.0);
  nbMakeNewPressPacket(0, (*a)->uniqueid, 8, &(*a)->form, 0);
  if (nbCheckEscape((*a)->data, 0))
  {
    (*a)->data->endtype = 3;
  }
  else
  {
    else
    {
      v7 = a;
    }
    CheckKoketaNego(v7);
  }
}

// 0xf3f7c0
void SetAction_INVISIBLE(nbActionProcessData_t **a) {
  ;
}

// 0xf3e370
void SetAction_NEGO(nbActionProcessData_t **a) {
    nbPanelDraw(0);
    nbInitNegoProcess(0, 0, 0, 0, 0);
}

// 0xf3e760
void SetAction_NEGORESULT(nbActionProcessData_t **a) {
    nbGetPartyFromFormindex(0);
    nbMakeReturnPacket(0, 0, 0);
    SetTimeList(0, 0, 0, 0, 0);
    nbGetUnitWorkFromFormindex(0);
    nbGetNakama(0);
    nbGetUnitWorkPointer(0, 0);
    dds3GetRandIntA(0, 0);
    nbMakePressPacket(0, 0, 0);
    nbMakeNewPressPacket(0, 0, 0, 0);
    nbSetWaitMotion(0, 0, 0);
    nbSetUnitMotion(0, 0, 0, 0);
    nbCameraSetTaizi(0, 0);
}

// 0xf35ca0
void SetAction_NON(nbActionProcessData_t **a) {
  ;
}

// 0xf38600
void SetAction_READY(nbActionProcessData_t **a) {
    nbBgmTrans();
    ClearTimeList(0);
    SetHpForTimeList(0);
    nbGetUnitVisual(0);
    nbGetBadStat(0);
    nbCheckBadPanicAction(0);
    nbCheckBadCurse(0);
    dds3GetRandIntA(0, 0);
    SetActionSeq(0, 0);
    nbCheckSkillUse(0, 0);
    nbSetJyokyoMes(0, 0, 0, 0);
    datAddItem(0, 0);
    Get(0);
    GetSOBED(0);
    sdfDevLoadFileUnity_25061072(0, 0, 0, 0);
    MarkTmxIndex(0);
    MarkPibIndex(0);
    LoadFileObject(0, 0, 0);
    SobedClear();
    LoadPrefab_16624656(0, 0, 0, 0);
    nbDelAllMojiNumEffectKoukaPacket(0, 0);
    nbAddFormFlagOnOffPacket(0, 0, 0, 0, 0);
    nbGetMotionEndType(0, 0);
    nbGetMotionEndData(0, 0);
    nbGetMotionNo(0, 0);
    nbGetMotionNoOrg(0, 0);
    nbAddSkillMotionKoukaPacket(0, 0, 0, 0, 0, 0);
    nbGetMotionSpeed(0, 0, 0);
    nbMakeUnitFadeOutPacket(0, 0, 0, 0, 0, 0, 0);
    nbMemoryLoadMotionSe(0, 0);
    nbGetMotionActframe(0, 0, 0);
    nbCameraSetState(0);
    nbAddMojiEffKoukaPacket(0, 0, 0, 0, 0);
    datGetSkillCost(0, 0);
    nbAddHpMpKoukaPacket(0, 0, 0, 0, 0);
    nbAddHitEffKoukaPacket(0, 0, 0, 0);
    nbAddHatudoEffectKoukaPacket(0, 0, 0, 0, 0, 0, 0);
    nbSetNormalSkill0(0);
    nbDelAllKoukaPacketType(0);
    effBTLSkillEnd();
    effBTLSkillSetFormationInfo(0, 0);
    effBTLSkillStart(0, 0);
    nbMakeUnitMovePacket(0, 0, 0, 0, 0, 0);
    nbGetItemSkillNo(0, 0);
    nbMakeReturnPacket(0, 0, 0);
    nbSetHojoAddCounter(0, 0, 0, 0);
    nbPanelAllShow();
    nbPanelPressGaugeShow();
    nbHatudoCheckSkill(0, 0);
    nbDispMiscActionNameComm(0);
    nbDispSkillName(0);
    effBTLSkillGetTargetFormation(0);
    nbCheckFormationPlayerSide(0);
    nbDispItemName(0);
}

// 0xf3f610
void SetAction_RETURN(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v4;
  s32 formindex;

  Write(StringLiteral_19254, 0);
  v4 = *a;
  if (((*a)->data->stat & 8) != 0)
  {
    nbCameraSetState(0x15u);
    v4 = *a;
  }
  nbMakeReturnPacket(0, v4->uniqueid, &v4->party);
  formindex = (*a)->form->formindex;
  SetTimeList(a, formindex, 0, 40, 40);
  nbMakePressPacket(10, (*a)->uniqueid, -0.5, 0);
  nbMakeNewPressPacket(10, (*a)->uniqueid, 9, &(*a)->form, 0);
}

// 0xf3b040
void SetAction_SKILL(nbActionProcessData_t **a) {
    effBTLCutCreate(0, 0, 0, 0);
    effBTLCutGetMotionChangeFrame(0);
    effBTLCutGetCutEndFrame(0);
    SetTimeList(0, 0, 0, 0, 0);
    nbGetMotionSpeed(0, 0, 0);
    nbGetMotionActframe(0, 0, 0);
    OverwriteTimeList(0, 0, 0, 0, 0);
    nbGetItemSkillNo(0, 0);
    SetNowActionStat(0, 0, 0);
    GetKoukaList(0, 0, 0, 0);
    nbGetKoukaType(0, 0, 0);
    effBTLGetMotionChangeFrame(0, 0);
    effBTLGetCutEndFrame(0, 0);
    nbAddFormFlagOnOffPacket(0, 0, 0, 0, 0);
    SetAllPacket(0, 0, 0, 0, 0, 0, 0, 0);
    SetSakePacket(0, 0, 0, 0, 0, 0);
    SetMissPacket(0, 0, 0, 0, 0, 0);
    SetPlayerSummonPacket(0, 0, 0, 0, 0);
    SetAnalyzePacket(0, 0, 0);
    SetTorafuPacket(0, 0, 0);
    SetMakaPacket(0, 0, 0);
    SetEnemyEscapePacket(0, 0, 0);
    SetOngShadowPacket(0, 0, 0, 0, 0, 0);
    SetAuroraPacket(0, 0, 0);
    SetAddPressPacket(0, 0);
    nbAddFlareChargePacket(0, 0, 0);
    nbGetNormalSkillAttr(0);
    SetOngShadowPacket2(0, 0, 0);
    nbGetDevilFormatFlag(0);
    nbAddSkillEffectKoukaPacket2(0, 0, 0, 0, 0, 0, 0);
    MAKE_SKILL_SE01(0);
    nbAddSePacket(0, 0, 0);
    nbGetGensyoRitu(0, 0, 0);
    nbSetHojoCounter(0, 0, 0);
    evtBitCheck(0);
    nbAddHatudoEffectEndPacket(0, 0);
    Get(0);
    nbMakeKaifukuPacket(0, 0, 0, 0, 0, 0, 0);
    nbHatudoCheckSkill(0, 0);
    effBTLSkillSetState(0);
    nbMakeDeadVisualPacket(0, 0, 0, 0, 0);
    SetDeadPacket(0, 0);
    CheckArrCounter(0);
    nbDispSkillName(0);
    nbSetJyokyoMes(0, 0, 0, 0);
    nbCheckBattleSkillError3(0, 0);
    nbAddJyokyoHelpPacket(0, 0, 0, 0, 0);
    nbAddSkillColorOffPacket(0, 0);
    effBTLCutSetDrawEndFrame(0, 0);
    effBTLCutSetCameraState(0);
    nbAddSkillEffectKoukaPacket(0, 0, 0, 0);
    MAKE_SKILL_SE00(0);
    nbAddMotionStopClearPacket(0, 0, 0);
    nbMakePressPacket(0, 0, 0);
    nbMakeNewPressPacket(0, 0, 0, 0);
    nbAddHitStopPacket(0, 0);
    SetAuto(0);
}

// 0xf37d70
void SetAction_STKSEL(nbActionProcessData_t **a) {
  (*a)->select = 0;
  nbPanelStockSelectInit();
  nbPanelStockSelect((*a)->data, 0, 0);
  StkSelId = -1;
}

// 0xf37620
void SetAction_TARSEL(nbActionProcessData_t **a) {
    SetTarget(0);
}

// 0xf3f180
void SetAction_WAIT(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v4;
  struct datUnitWork_t_o *work;
  s32 nowcommand;
  s32 uniqueid;
  nbFormation_t_o **p_form;
  s32 v9;
  s32 v10;
  s32 formindex;

  v4 = *a;
  work = (*a)->work;
  nowcommand = work->nowcommand;
  switch (nowcommand)
  {
    case 3:
      nbMakePressPacket(0, v4->uniqueid, -0.5);
      uniqueid = (*a)->uniqueid;
      p_form = &(*a)->form;
      v9 = 1;
      nbMakeNewPressPacket(0, uniqueid, v9, p_form);
      formindex = (*a)->form->formindex;
      SetTimeList(a, formindex, 0, 5, 5);
      return;
    case 8:
      nbMakePressPacket(0, v4->uniqueid, -1.0);
      uniqueid = (*a)->uniqueid;
      p_form = &(*a)->form;
      v9 = 0;
    case 10:
      v10 = 15 * work->maxhp / 0x64;
      SetDamagePacket(a, v10);
      nbMakePressPacket(0, (*a)->uniqueid, -1.0, 0);
      nbMakeNewPressPacket(0, (*a)->uniqueid, 0, &(*a)->form, 0);
      break;
  }
}

// 0xf2e800
void SetAddFlareChargePacket(nbActionProcessData_t **a, s32 start) {
  nbAddFlareChargePacket(start, (*a)->uniqueid, 2, 0);
}

// 0xf2e6c0
void SetAddPressPacket(nbActionProcessData_t **a, s32 nskill) {
  struct datNormalSkill_t_array *tbl;
  struct datNormalSkill_t_array *v9;
  s32 hojopoint;
  nbActionProcessData_t_o *v12;
  s32 v13;

  if (tbl->m_Items[nskill]->program == 13)
  {
    v9 = tbl;
    hojopoint = v9->m_Items[nskill]->hojopoint;
    switch (hojopoint)
    {
      case 4:
        v12 = *a;
        v13 = 16;
        break;
      case 3:
        v12 = *a;
        v13 = 17;
        break;
      case 2:
        v12 = *a;
        v13 = 15;
        break;
      default:
        return;
    }
    v12->newaddpresstype = v13;
  }
}

// 0xf2f780
void SetAllPacket(nbActionProcessData_t **a, s32 koukatype, s32 nskill, s32 sformindex, s32 dformindex, s32 cnt, s32 frame, f32 koukaritu) {
    nbGetAisyoRitu(0, 0, 0);
    nbGetKoukaBadDamage(0, 0, 0, 0, 0);
    nbGetKoukaBadKaifuku(0, 0, 0, 0, 0);
    nbGetHitType(0, 0, 0, 0);
    nbGetCriticalPow(0, 0);
    evtBitCheck(0);
    nbAddHitEffKoukaPacket(0, 0, 0, 0);
    SetTimeList(0, 0, 0, 0, 0);
    nbGetMainProcessData();
    nbGetNormalSkillAttr(0);
    nbGetAisyo(0, 0, 0);
    datGetBadStatusAttr(0);
    nbCheckFormationPlayerSide(0);
    nbMakeUnitFadeInPacket(0, 0, 0, 0, 0, 0, 0);
    nbGetDeadType(0, 0, 0);
    nbGetKoukaHp(0, 0, 0, 0, 0, 0);
    nbGetUnitWorkFromFormindex(0);
    nbGetKoukaMp(0, 0, 0, 0, 0, 0);
    nbAddMojiEffKoukaPacket(0, 0, 0, 0, 0);
    nbCheckHitEffect(0, 0, 0);
    nbCheckKuisibariSkill(0);
    nbCheckKuisibari2Skill(0);
    nbGetHpDrainRitu(0, 0, 0);
    nbGetDevilFormatFlag(0);
    nbCheckStoneDead(0, 0);
    nbGetBadStat(0);
    nbAddSkillNamePacket(0, 0, 0);
    nbGetMpDrainRitu(0, 0, 0);
    nbMakeDamagePacket(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    nbAddSePacket(0, 0, 0);
    Get(0);
    nbCheckBadKaifuku(0, 0);
    nbMakeBadKaifukuPacket(0, 0, 0);
    nbGetGensyoRitu(0, 0, 0);
    nbMakeKaifukuPacket(0, 0, 0, 0, 0, 0, 0);
    nbSetBadStat(0, 0, 0);
    nbAddHojoKoukaPacket(0, 0, 0, 0, 0);
    nbSetKuisibariStop(0);
    CheckCounter(0, 0, 0);
    SetDeadPacket(0, 0);
    nbSetJyokyoMes(0, 0, 0, 0);
    nbCheckFormationFriend(0, 0);
}

// 0xf2eb60
void SetAnalyzePacket(nbActionProcessData_t **a, s32 dformindex, s32 sframe) {
  nbActionProcessData_t_o *v7;
  struct nbFormation_t_array *v8;
  nbFormation_t_o *form;

  form = 0;
  v7 = *a;
  v8 = (*a)->data->form;
  form = v8->m_Items[dformindex];
  nbAddAnalyzePacket(sframe + 2, v7->uniqueid, &form);
  nbPanelAnalyzeStart();
  (*a)->stat |= 0x10u;
}

// 0xf2e580
void SetAuroraPacket(nbActionProcessData_t **a, s32 dformindex, s32 sframe) {
  s32 HojoCounter;
  s32 v7;
  s32 id;

  nbGetPartyFromFormindex(dformindex);
  HojoCounter = nbGetHojoCounter(dformindex, 19);
  v7 = 248;
  switch (HojoCounter)
  {
    case 248:
      v7 = 249;
      break;
    case 249:
      v7 = 250;
      break;
    case 250:
      v7 = 251;
      break;
    case 251:
      break;
    default:
      if (HojoCounter)
        v7 = HojoCounter;
      break;
  }
  nbSetHojoCounter(dformindex, 19, v7);
  id = nbGetUnitWorkFromFormindex(dformindex)->id;
  nbSetJyokyoMes(a, 90, 1, id);
}

// 0xf35780
void SetDamagePacket(nbActionProcessData_t **a, s32 hp) {
  s32 v3;
  s32 v5;
  s64 i;
  struct nbTimeList_t_array *timelist;
  struct nbTimeList_t_array *v9;
  nbActionProcessData_t_o *v12;
  u32 formindex;
  struct nbTimeList_t_array *v14;
  nbActionProcessData_t_o *v16;
  u32 v17;
  struct nbTimeList_t_array *v18;
  s32 uniqueid;
  s32 v21;
  s32 v22;
  nbActionProcessData_t_o *v23;
  u32 v24;
  struct nbTimeList_t_array *v25;
  nbActionProcessData_t_o *v27;
  u32 v28;
  struct nbTimeList_t_array *v29;
  nbActionProcessData_t_o *v31;
  u32 v32;
  struct nbTimeList_t_array *v33;
  u32 max_length;
  struct nbTimeList_t_array *v35;
  s32 v37;
  struct nbTimeList_t_array *v39;
  s64 v40;
  s32 dead;
  s32 v45;
  s32 v47;
  s32 v48;
  nbActionProcessData_t_o **v49;
  s32 v50;
  s32 v51;
  s32 v52;

  v3 = hp;
  v5 = 0;
  for (i = 4; i != 36; ++i)
  {
    while (1)
    {
      timelist = (*a)->timelist;
      if (v5 < *(*(&timelist->obj.klass + i) + 16LL))
        break;
      if (++i == 36)
    }
    v9 = (*a)->timelist;
    v5 = *(*(&v9->obj.klass + i) + 16LL);
  }
  if (nbCheckKuisibariSkill((*a)->form->formindex, 0))
  {
    if (v3 >= 1)
    {
      v12 = *a;
      formindex = (*a)->form->formindex;
      v14 = v12->timelist;
      if (v14->m_Items[formindex]->hp <= v3)
      {
        v16 = *a;
        v17 = (*a)->form->formindex;
        v18 = v16->timelist;
        uniqueid = v16->uniqueid;
        v3 = v18->m_Items[v17]->hp - 1;
        v21 = 345;
        nbAddSkillNamePacket(v5, uniqueid, v21);
        nbSetKuisibariStop((*a)->form->formindex, 0);
      }
    }
  }
  else
  {
    v22 = nbCheckKuisibari2Skill((*a)->form->formindex, 0);
    if (v3 >= 1 && v22)
    {
      v23 = *a;
      v24 = (*a)->form->formindex;
      v25 = v23->timelist;
      if (v25->m_Items[v24]->hp <= v3)
      {
        v27 = *a;
        v28 = (*a)->form->formindex;
        v29 = v27->timelist;
        uniqueid = v27->uniqueid;
        v3 = v29->m_Items[v28]->hp - 1;
        v21 = 360;
      }
    }
  }
  v31 = *a;
  v32 = (*a)->form->formindex;
  else  v33 = v31->timelist;
  max_length = v33->max_length;
  v35 = v33;
  v37 = v33->m_Items[v32]->hp - v3;
  v35->m_Items[v32]->hp = v37 & ~(v37 >> 31);
  v39 = (*a)->timelist;
  v40 = (*a)->form->formindex;
  dead = !v39->m_Items[v40]->hp && (nbGetDevilFormatFlag(v40) & 0x100) == 0;
  nbMakeDamagePacket(v5, (*a)->uniqueid, &(*a)->form, 3, v3, -1, 0, 0, dead, 0, 1, 0, 0);
  if (dead)
  {
    v45 = (*a)->form->formindex;
    SetTimeList(a, v45, v5, 30, 30);
    SetDeadPacket(a, (*a)->form->formindex);
  }
  v47 = (*a)->form->formindex;
  if (dead)
  {
    v48 = 20;
    v49 = a;
    v50 = v47;
    v51 = v5;
    v52 = 20;
  }
  else
  {
    v49 = a;
    v50 = v47;
    v51 = v5;
    v48 = 30;
    v52 = 30;
  }
  SetTimeList(v49, v50, v51, v48, v52);
}

// 0xf2e260
void SetDeadPacket(nbActionProcessData_t **a, s32 formindex) {
  struct nbMainProcessData_t_o *data;
  struct nbFormation_t_array *form;
  struct nbParty_t_array *party;
  s64 partyindex;
  nbParty_t_o *v11;
  struct nbTimeList_t_array *timelist;
  s32 endframe;
  nbMainProcessData_t_o *v15;
  datUnitWork_t_o *UnitWorkPointer;
  nbActionProcessData_t_o *v17;
  s32 uniqueid;
  struct nbFormation_t_array *v19;

  data = (*a)->data;
  form = data->form;
  party = data->party;
  partyindex = form->m_Items[formindex]->partyindex;
  v11 = party->m_Items[partyindex];
  if ((v11->flag & 0x20) == 0)
  {
    timelist = (*a)->timelist;
    endframe = timelist->m_Items[formindex]->endframe;
    v15 = (*a)->data;
    UnitWorkPointer = nbGetUnitWorkPointer(v15, v11);
    if ((UnitWorkPointer->flag & 0x20) != 0)
      nbGetExpMakaItem(UnitWorkPointer);
    v17 = *a;
    uniqueid = (*a)->uniqueid;
    v19 = v17->data->form;
    nbMakeDeadPacket(endframe, uniqueid, &v19->m_Items[formindex], 0);
  }
}

// 0xf2e4a0
void SetEnemyEscapePacket(nbActionProcessData_t **a, s32 dformindex, s32 sframe) {
  nbParty_t_o *party;

  party = 0;
  party = nbGetPartyFromFormindex(dformindex);
  nbMakeReturnPacket(sframe, (*a)->uniqueid, &party, 0);
  SetTimeList(a, dformindex, sframe, 30, 30);
}

// 0xf2e480
void SetHitStopFrame(nbActionProcessData_t **a, s32 frame) {
  s32 hitstopframe;
  s32 v4;
  bool v5;

  hitstopframe = (*a)->hitstopframe;
  v4 = frame + 7;
  if (hitstopframe)
    v5 = hitstopframe <= v4;
  else
    v5 = 0;
  if (!v5)
    (*a)->hitstopframe = v4;
}

// 0xf31c00
void SetHpForTimeList(nbActionProcessData_t **a) {
  u64 i;
  struct nbTimeList_t_array *timelist;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v8;
  struct nbMainProcessData_t_o *data;
  struct nbFormation_t_array *v11;
  struct nbParty_t_array *party;
  s64 partyindex;
  nbParty_t_o *v16;
  datUnitWork_t_o *UnitWorkPointer;
  struct nbTimeList_t_array *v18;

  for (i = 0; i != 16; ++i)
  {
    timelist = (*a)->timelist;
    timelist->m_Items[i]->hp = 0;
    form = (*a)->data->form;
    if ((form->m_Items[i]->stat & 1) != 0)
    {
      v8 = (*a)->data->form;
      if ((v8->m_Items[i]->stat & 0x40) != 0)
      {
        data = (*a)->data;
        v11 = data->form;
        party = data->party;
        partyindex = v11->m_Items[i]->partyindex;
        v16 = party->m_Items[partyindex];
        UnitWorkPointer = nbGetUnitWorkPointer(data, v16);
        v18 = (*a)->timelist;
        v18->m_Items[i]->hp = UnitWorkPointer->hp;
      }
    }
  }
}

// 0xf2e820
void SetMakaPacket(nbActionProcessData_t **a, s32 dformindex, s32 sframe) {
    nbGetMakaBaramaki(0);
    nbCheckFormationPlayerSide(0);
    SetTimeList(0, 0, 0, 0, 0);
    nbSetJyokyoMes(0, 0, 0, 0);
    datAddMaka(0);
}

// 0xf2f130
void SetMissPacket(nbActionProcessData_t **a, s32 nskill, s32 sformindex, s32 dformindex, s32 cnt, s32 frame) {
  struct nbFormation_t_array *form;
  nbActionProcessData_t_o *v14;

  form = (*a)->data->form;
  nbAddMojiEffKoukaPacket(frame, 45, (*a)->uniqueid, &form->m_Items[dformindex], 3, 0);
  SetTimeList(a, dformindex, frame, 10, 20);
  v14 = *a;
  if ((*a)->press > -2.0)
  {
    v14->press = -2.0;
    v14 = *a;
  }
  if (v14->newpresstype <= 3)
    v14->newpresstype = 4;
}

// 0xf2e460
void SetNewPress(nbActionProcessData_t **a, s32 presstype) {
  if ((*a)->newpresstype < presstype)
    (*a)->newpresstype = presstype;
}

// 0xf2d620
void SetNextActionSeq(nbActionProcessData_t **a, s32 nextseq) {
  (*a)->nextseq = nextseq;
}

// 0xf35200
void SetNowActionStat(nbActionProcessData_t **a, s32 comm, s32 nskill) {
  char v7;
  struct datNormalSkill_t_array *tbl;
  struct datNormalSkill_t_array *v12;
  u32 hptype;
  bool v15;
  s32 v16;
  struct datNormalSkill_t_array *v19;
  u32 mptype;
  s32 v22;
  struct datNormalSkill_t_array *v25;
  struct datNormalSkill_t_array *v28;
  u32 v30;
  s32 v31;
  struct datNormalSkill_t_array *v34;
  u32 v36;
  struct datNormalSkill_t_array *v38;
  struct datNormalSkill_t_array *v41;
  u32 v43;
  s32 v44;
  struct datNormalSkill_t_array *v47;
  u32 v49;
  s32 v50;
  struct datNormalSkill_t_array *v53;
  struct datNormalSkill_t_array *v56;

  if ((*a)->partyindex <= 3)
  {
    if (comm == 1)
    {
      if (!tbl->m_Items[nskill]->koukatype)
      {
        v12 = tbl;
        hptype = v12->m_Items[nskill]->hptype;
        v15 = hptype > 0xE;
        v16 = (1 << hptype) & 0x755A;
        if (!v15 && v16 != 0)
          (*a)->stat |= 0x10000u;
        v19 = tbl;
        mptype = v19->m_Items[nskill]->mptype;
        v15 = mptype > 0xE;
        v22 = (1 << mptype) & 0x755A;
        if (!v15 && v22 != 0)
          (*a)->stat |= 0x10000u;
      }
      v25 = tbl;
      if (v25->m_Items[nskill]->koukatype == 1)
      {
        v28 = tbl;
        v30 = v28->m_Items[nskill]->hptype;
        v15 = v30 > 0xE;
        v31 = (1 << v30) & 0x755A;
        if (!v15 && v31 != 0)
          (*a)->stat |= 0x20000u;
        v34 = tbl;
        v36 = v34->m_Items[nskill]->mptype;
        if (v36 <= 0xE && ((1 << v36) & 0x755A) != 0)
          (*a)->stat |= 0x20000u;
        v38 = tbl;
        if ((v38->m_Items[nskill]->badtype | 2) == 3)
          (*a)->stat |= 0x20000u;
      }
      v7 = 1;
    }
    else
    {
      v7 = 0;
      if (!comm)
        (*a)->stat |= 0x10000u;
    }
    v41 = tbl;
    v43 = v41->m_Items[nskill]->hptype;
    v15 = v43 > 0xF;
    v44 = (1 << v43) & 0x8AA4;
    if (!v15 && v44 != 0)
      (*a)->stat |= 0x40000u;
    v47 = tbl;
    v49 = v47->m_Items[nskill]->mptype;
    v15 = v49 > 0xF;
    v50 = (1 << v49) & 0x8AA4;
    if (!v15 && v50 != 0)
      (*a)->stat |= 0x40000u;
    if ((v7 & 1) != 0)
    {
      v53 = tbl;
      if (v53->m_Items[nskill]->koukatype == 1)
        (*a)->stat |= 0x80000u;
    }
    if (comm == 5)
      (*a)->stat |= 0x100000u;
    if ((v7 & 1) == 0)
    {
      if (comm != 6)
        return;
    }
    v56 = tbl;
    if ((v56->m_Items[nskill]->program & 0xFFFFFFFE) == 2)
      (*a)->stat |= 0x200000u;
  }
}

// 0xf2f250
void SetOngShadowPacket(nbActionProcessData_t **a, s32 nskill, s32 sformindex, s32 dformindex, s32 cnt, s32 frame) {
  struct nbFormation_t_array *v10;
  struct nbFormation_t_array *v12;
  struct nbFormation_t_array *v14;
  s32 v17;
  struct nbFormation_t_array *v18;
  s64 v22;
  s32 v24;
  struct nbFormation_t_array *v25;
  nbActionProcessData_t_o *v29;
  nbFormation_t_o *form;

  form = 0;
  Write(StringLiteral_19197, 0);
  v10 = (*a)->data->form;
  nbAddMojiEffKoukaPacket(frame, 45, (*a)->uniqueid, &v10->m_Items[dformindex], 4, 0);
  v12 = (*a)->data->form;
  nbAddOngOutPacket(frame, (*a)->uniqueid, &v12->m_Items[dformindex], 0);
  v14 = (*a)->data->form;
  nbAddUnitAKoukaPacket(frame + 1, (*a)->uniqueid, &v14->m_Items[dformindex], 0, 0, 0);
  v17 = effPCPBossONGYGetLength();
  v18 = (*a)->data->form;
  nbMakeDeadPacket(v17 + frame, (*a)->uniqueid, &v18->m_Items[dformindex], 1, 0);
  SetTimeList(a, dformindex, frame, 30, 30);
  v22 = 0;
  v24 = effPCPBossONGYGetLength() + frame;
  do
  {
    if (dformindex - 4LL != v22)
    {
      v25 = (*a)->data->form;
      form = v25->m_Items[v22 + 4];
      if ((~form->stat & 3) == 0)
      {
        nbAddMotionKoukaPacket(v24, (*a)->uniqueid, &form, 14, 0);
        SetTimeList(a, v22 + 4, v24, 20, 20);
      }
    }
    ++v22;
  }
  while (v22 != 10);
  v29 = *a;
  if ((*a)->press > -2.0)
  {
    v29->press = -2.0;
    v29 = *a;
  }
  if (v29->newpresstype <= 13)
    v29->newpresstype = 14;
}

// 0xf2f590
void SetOngShadowPacket2(nbActionProcessData_t **a, s32 dformindex, s32 frame) {
  s64 v7;
  s32 v8;
  s32 v9;
  struct nbFormation_t_array *v10;
  s32 Length;
  nbFormation_t_o *form;

  form = 0;
  Write(StringLiteral_19198, 0);
  v7 = 0;
  v8 = 0;
  v9 = frame + 1;
  do
  {
    if (dformindex - 4LL != v7)
    {
      v10 = (*a)->data->form;
      form = v10->m_Items[v7 + 4];
      if ((~form->stat & 3) == 0)
      {
        nbAddUnitAKoukaPacket(v9, (*a)->uniqueid, &form, 0, 0, 0);
        Length = effPCPBossONGY2GetLength();
        nbMakeDeadPacket(v9 + Length, (*a)->uniqueid, &form, 1, 0);
        nbAddOngOut2Packet(frame, (*a)->uniqueid, &form, 0);
        SetTimeList(a, v7 + 4, frame, 30, 30);
        ++v8;
      }
    }
    ++v7;
  }
  while (v7 != 10);
  if (v8 >= 1)
    (*a)->data->stat |= 0x4000u;
}

// 0xf41610
void SetPbList(SOBED_PB_LIST *gList) {
  pb_list = gList;
}

// 0xf2ec50
s32 SetPlayerSummonPacket(nbActionProcessData_t **a, s32 nskill, s32 sformindex, s32 dformindex, s32 sframe) {
  nbActionProcessData_t_o *v9;
  s32 v10;
  nbMainProcessData_t_o *data;
  s32 aisummonid;
  s32 appended;
  struct nbMainProcessData_t_o *v15;
  s32 nakamayobi;
  s32 nowindex;
  bool v18;
  s32 v19;
  struct datUnitWork_t_o *work;
  s32 formindex;
  struct datUnitWork_t_array *enemyunit;
  s64 v27;
  datUnitWork_t_o *v29;
  struct nbTimeList_t_array *timelist;
  s32 id;
  s32 v33;
  nbActionProcessData_t_o **v34;
  s32 v35;

  v9 = *a;
  v10 = ((*a)->party->flag >> 1) & 1;
  if (v10)
  {
    data = v9->data;
    aisummonid = v9->aisummonid;
    appended = nbAppendEnemyDevilWork(data, aisummonid, dformindex);
    v15 = (*a)->data;
    nakamayobi = v15->nakamayobi;
    nowindex = appended;
    v18 = __OFSUB__(nakamayobi, 1);
    v19 = nakamayobi - 1;
    if (v19 < 0 == v18)
      v15->nakamayobi = v19;
  }
  else
  {
    work = v9->work;
    nowindex = work->nowindex;
    if (work->nowcommand == 1 && nowindex == 223)
    {
      nowindex = nbGetRandamStock();
      if (nowindex < 0)
      {
        nbSetJyokyoMes(a, 62, -1, 0);
        return 0;
      }
    }
  }
  nbMakeSummonPacket(sframe, (*a)->uniqueid, v10, nowindex, dformindex, 0);
  formindex = (*a)->form->formindex;
  SetTimeList(a, formindex, sframe, 15, 20);
  if (v10)
  {
    enemyunit = (*a)->data->enemyunit;
    v27 = nowindex;
    if (nowindex >= LODWORD(enemyunit->max_length))
  }
  else
  {
    enemyunit = DDS3_GBWK->unitwork;
    v27 = nowindex;
  }
  v29 = enemyunit->m_Items[v27];
  timelist = (*a)->timelist;
  timelist->m_Items[dformindex]->hp = v29->hp;
  id = v29->id;
  if (v10)
  {
    v33 = 1;
    v34 = a;
    v35 = 64;
  }
  else
  {
    v33 = 1;
    v34 = a;
    v35 = 8;
  }
  nbSetJyokyoMes(v34, v35, 1, id);
  return v33;
}

// 0xf2e410
void SetPress(nbActionProcessData_t **a, f32 press) {
  nbActionProcessData_t_o *v3;
  f32 v4;

  if (press < -1.0)
  {
    v3 = *a;
    if ((*a)->press <= press)
      return;
    v3->press = press;
    return;
  }
  v3 = *a;
  v4 = (*a)->press;
  if (press > -1.0)
  {
    if (v4 < -1.0)
      return;
    if (v4 < press)
  }
  if (v4 == 0.0)
}

// 0xf2ef50
void SetSakePacket(nbActionProcessData_t **a, s32 nskill, s32 sformindex, s32 dformindex, s32 cnt, s32 frame) {
    nbAddSakeKoukaPacket(0, 0, 0);
    SetTimeList(0, 0, 0, 0, 0);
    nbCheckSingleTargetSkill(0);
    nbCheckFormationPlayerSide(0);
    nbSetJyokyoMes(0, 0, 0, 0);
}

// 0xf31a30
s32 SetTarget(nbActionProcessData_t **a) {
  struct datUnitWork_t_o *work;
  s32 nowcommand;
  s32 v5;
  nbActionProcessData_t_o *v6;
  datUnitWork_t_o *v7;
  s32 carea;
  s32 crule;
  s32 ctype;

  ctype = 0;
  crule = 0;
  carea = 0;
  work = (*a)->work;
  nowcommand = work->nowcommand;
  v5 = nowcommand == 6 || nowcommand == 1 && work->nowindex == 223;
  (*a)->data->TarSelType = v5;
  (*a)->select = 0;
  v6 = *a;
  v7 = (*a)->work;
  nbGetTargetTypeRuleArea(v6, v7, &ctype, &crule, &carea, 0);
  return nbSetTargetProcess(*a, (*a)->partyindex, ctype, crule, carea, 0);
}

// 0xf33960
void SetTargetParty(nbActionProcessData_t **a, s32 partyindex) {
  s64 i;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v6;
  s64 v8;
  s64 j;
  struct nbFormation_t_array *v10;
  u64 v11;
  struct nbFormation_t_array *v13;
  struct nbFormation_t_array *v15;
  struct nbFormation_t_array *v17;

  for (i = 4; i != 20; ++i)
  {
    form = (*a)->data->form;
    *(*(&form->obj.klass + i) + 136LL) &= ~4u;
    v6 = (*a)->data->form;
    v8 = *(&v6->obj.klass + i);
    *(v8 + 136) &= ~8u;
  }
  for (j = 4; ; ++j)
  {
    v10 = (*a)->data->form;
    v11 = j - 4;
    if ((*(*(&v10->obj.klass + j) + 136LL) & 1) != 0)
    {
      v13 = (*a)->data->form;
      if ((*(*(&v13->obj.klass + j) + 136LL) & 0x40) != 0)
      {
        v15 = (*a)->data->form;
        if (*(*(&v15->obj.klass + j) + 176LL) == partyindex)
          break;
      }
    }
    if (v11 >= 0xF)
      return;
  }
  v17 = (*a)->data->form;
  *(*(&v17->obj.klass + j) + 136LL) |= 8u;
}

// 0xf33760
void SetTargetPlayer(nbActionProcessData_t **a) {
  s64 i;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v6;
  s64 v8;
  s64 j;
  struct nbFormation_t_array *v10;
  u64 v11;
  struct nbFormation_t_array *v13;
  struct nbFormation_t_array *v15;
  struct nbFormation_t_array *v17;

  for (i = 4; i != 20; ++i)
  {
    form = (*a)->data->form;
    *(*(&form->obj.klass + i) + 136LL) &= ~4u;
    v6 = (*a)->data->form;
    v8 = *(&v6->obj.klass + i);
    *(v8 + 136) &= ~8u;
  }
  for (j = 4; ; ++j)
  {
    v10 = (*a)->data->form;
    v11 = j - 4;
    if ((*(*(&v10->obj.klass + j) + 136LL) & 1) != 0)
    {
      v13 = (*a)->data->form;
      if ((*(*(&v13->obj.klass + j) + 136LL) & 0x40) != 0)
      {
        v15 = (*a)->data->form;
        if ((*(*(&v15->obj.klass + j) + 137LL) & 1) != 0)
        {
          if ((nbGetUnitWorkFromFormindex(j - 4)->flag & 4) != 0)
            break;
        }
      }
    }
    if (v11 >= 0xF)
      return;
  }
  v17 = (*a)->data->form;
  *(*(&v17->obj.klass + j) + 136LL) |= 8u;
}

// 0xf2d630
void SetTimeList(nbActionProcessData_t **a, s32 formindex, s32 start, s32 locktime, s32 endtime) {
  struct nbTimeList_t_array *timelist;
  s32 lockframe;
  struct nbTimeList_t_array *v9;
  struct nbTimeList_t_array *v11;
  struct nbTimeList_t_array *v13;
  struct nbTimeList_t_array *v15;
  u16 v17;
  struct nbTimeList_t_array *v18;
  struct nbTimeList_t_array *v20;
  struct nbTimeList_t_array *v22;

  timelist = (*a)->timelist;
  lockframe = start;
  if (timelist->m_Items[formindex]->lockframe > start)
  {
    v9 = (*a)->timelist;
    lockframe = v9->m_Items[formindex]->lockframe;
  }
  if ((locktime & 0x80000000) == 0)
  {
    v11 = (*a)->timelist;
    if (lockframe + locktime > v11->m_Items[formindex]->lockframe)
    {
      v13 = (*a)->timelist;
      v13->m_Items[formindex]->lockframe = lockframe + locktime;
    }
  }
  if ((endtime & 0x80000000) == 0)
  {
    v15 = (*a)->timelist;
    v17 = lockframe + endtime;
    if (lockframe + endtime > v15->m_Items[formindex]->endframe)
    {
      v18 = (*a)->timelist;
      v18->m_Items[formindex]->endframe = v17;
    }
    v20 = (*a)->timelist;
    if (v20->m_Items[formindex]->endframe < (*a)->timelist->m_Items[formindex]->lockframe)
    {
      v22 = (*a)->timelist;
      v22->m_Items[formindex]->endframe = (*a)->timelist->m_Items[formindex]->lockframe;
    }
  }
}

// 0xf2ea40
void SetTorafuPacket(nbActionProcessData_t **a, s32 dformindex, s32 sframe) {
  nbActionProcessData_t_o *v7;
  struct nbFormation_t_array *v8;
  nbFormation_t_o *form;

  form = 0;
  v7 = *a;
  v8 = (*a)->data->form;
  form = v8->m_Items[dformindex];
  nbMakeUnitFadeOutPacket(sframe, v7->uniqueid, &form, 0, 6, 6, 6);
  nbAddFormOnOffPacket(sframe + 12, (*a)->uniqueid, &form, 0, 0);
  (*a)->data->endtype = 3;
  dds3FadeColorSet(0, 0, 0);
}

// 0xf38440
void SobedClear(void) {
}

// 0xf416f0
void SobedPbSet(u8 **bytedata, s32 bPos) {
  s32 PibIndex;
  struct SOBED_PB_LIST_array *sobed_pb_all;
  s32 max_length;
  struct SOBED_PB_LIST_o *v12;

  if (sobed_pb_all)
  {
    PibIndex = GetPibIndex(bytedata, bPos);
    max_length = sobed_pb_all->max_length;
    if (PibIndex < max_length)
    {
      v12 = sobed_pb_all->m_Items[PibIndex];
      pb_list = v12;
    }
  }
}

// 0xf2e1f0
void UnitKyoseiDisp(nbActionProcessData_t **a, s32 start) {
  if ((*a)->form->motendtype == 2)
  {
    nbMakeUnitFadeInPacket(start, (*a)->uniqueid, &(*a)->form, 0, 2, 4, 4, 0);
    (*a)->form->motendtype = 0;
  }
}

// 0xf2d490
char *effBTLDebugGetBEDFileCut23(u32 id) {
  return StringLiteral_416;
}

// 0xf2d500
s32 fileCheckEnd(fileHandle_t *fileHandle) {
  return 0;
}

// 0xf2d520
s32 fileGetLoadSize(fileHandle_t *fileHandle) {
  return 0;
}

// 0xf2d510
sdfMemHandle_t *fileGetMemHandle(fileHandle_t *fileHandle) {
  return 0;
}

// 0xf2d530
s32 fileHandleFree(fileHandle_t *fileHandle) {
  return 0;
}

// 0xf2d4e0
fileHandle_t *fileLoad(char *filename) {
  return 0;
}

// 0xf40af0
void *nbActionProcess1(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    nbPanelStockSelect(0, 0);
    nbGetPrevActionSeq();
    SetActionSeq(0, 0);
    return 0;
}

// 0xf40df0
void *nbActionShutdown(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    effBTLDelete(0);
    return 0;
}

// 0xf31f00
s32 nbAddTimeListHp(nbActionProcessData_t **a, s32 formindex, s32 add) {
  nbActionProcessData_t_o *v7;
  struct nbTimeList_t_array *timelist;
  s32 v10;

  v7 = *a;
  if (((*a)->data->stat & 0x20000) != 0)
    return 0;
  timelist = v7->timelist;
  v10 = timelist->m_Items[formindex]->hp + add;
  timelist->m_Items[formindex]->hp = v10 & ~(v10 >> 31);
  return v10 >> 31;
}

// 0xf2d480
void nbBgmTrans(void) {
  ;
}

// 0xf408a0
s32 nbGetActionSeq(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    return 0;
}

// 0xf409d0
s32 nbGetPrevActionSeq(void) {
  nbMainProcessData_t_o *MainProcessData;
  s32 NowActionProcess;
  struct dds3ProcessID_t_array *ActionProcessID;
  s32 v6;
  struct dds3ProcessID_t_array *v8;
  dds3ProcessID_t_o *v10;

  MainProcessData = nbGetMainProcessData();
  NowActionProcess = MainProcessData->NowActionProcess;
  ActionProcessID = MainProcessData->ActionProcessID;
  if (NowActionProcess <= 0)
    v6 = 3;
  else
    v6 = NowActionProcess - 1;
  if (!ActionProcessID->m_Items[v6])
    return -1;
  v8 = MainProcessData->ActionProcessID;
  v10 = v8->m_Items[v6];
  return nbGetActionSeq(v10);
}

// 0xf41400
void nbInitActionProcess(nbMainProcessData_t **data, s32 type, s32 from, s32 to, s32 d) {
  s32 NowActionProcess;
  s32 v12;
  s32 v13;
  Il2CppObject *inited;
  u64 *v15;
  u64 *v16;
  nbMainProcessData_t_o *v18;
  dds3ProcessID_t_o *v19;
  struct dds3ProcessID_t_array *ActionProcessID;
  s64 v21;
  dds3ProcessID_t_o *target;

  target = 0;
  NowActionProcess = (*data)->NowActionProcess;
  v12 = NowActionProcess + 1;
  if (NowActionProcess + 1 >= 0)
    v13 = NowActionProcess + 1;
  else
    v13 = NowActionProcess + 4;
  (*data)->NowActionProcess = v12 - (v13 & 0xFFFFFFFC);
  inited = InitActionProcessData(data, type, from, to, d);
  v15 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v15,
    0,
    Method_nbActionProcess_nbActionProcess1__);
  v16 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v16,
    0,
    Method_nbActionProcess_nbActionShutdown__);
  target = dds3StartProcess(StringLiteral_19259, 0x3F8u, 1, 1, v15, 0, v16, 0, inited, 0);
  dds3LinkProcess(&(*data)->MainProcessID, &target, 0);
  v18 = *data;
  v19 = target;
  ActionProcessID = v18->ActionProcessID;
  v21 = v18->NowActionProcess;
  ActionProcessID->m_Items[v21] = v19;
}
