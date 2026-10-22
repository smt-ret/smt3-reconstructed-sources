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
    char *tga_fname;
    nbActionProcess_SOBED_PB *pbdata;
};

struct nbActionProcess_SOBED_PB {
    s32 type;
    s32 reversePB;
    char *prefab_name;
};

static u32 StkSelId;
static char *SetAction_READY_str;
static SOBED_PB_LIST *sobed_pb_all;
static nbActionProcess_nbActionFunc_t *ActionFunc;
static s32 nba_uniqueid;
static nbActionProcess_SOBED *sobedtbl;
static nbActionProcess_SOBED *sobedtbl_dante;
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
        goto LABEL_19;
      if (BadStat != 1024)
        goto LABEL_18;
    }
    nbMakePressPacket(0, (*a)->uniqueid, -1.0, 0);
    nbMakeNewPressPacket(0, (*a)->uniqueid, 0, &(*a)->form, 0);
    v8 = *a;
    if (((*a)->data->stat & 8) != 0)
      goto LABEL_27;
    goto LABEL_31;
  }
  if (BadStat - 1 < 2)
  {
    nbMakePressPacket(0, (*a)->uniqueid, -1.0, 0);
    nbMakeNewPressPacket(0, (*a)->uniqueid, 0, &(*a)->form, 0);
    nbMakeBadKaifukuPacket(5, (*a)->uniqueid, &(*a)->form, 0);
    v8 = *a;
    if (((*a)->data->stat & 8) != 0)
      goto LABEL_27;
    goto LABEL_31;
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
LABEL_27:
      nbCameraSetState(0x19u);
      v8 = *a;
    }
LABEL_31:
    formindex = v8->form->formindex;
    SetTimeList(a, formindex, 0, 30, 30);
    v10 = 18;
    goto LABEL_35;
  }
  if (BadStat == 8)
    goto LABEL_19;
LABEL_18:
  if (nbCheckBadCurse((*a)->form->formindex, 0))
  {
LABEL_19:
    nbRunBadAi(a);
    v10 = 11;
LABEL_35:
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
      goto LABEL_15;
    return 0;
  }
  if (v8->seqtime < 0x1Fu)
    return 0;
LABEL_15:
  v8->nextseq = 7;
  (*a)->jyokyomes = 0;
  return 1;
}

// 0xf40130
s32 CheckAction_CHECK1(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v3;
  u32 packettime;
  s32 v7;
  nbActionProcessData_t_o *v9;
  s32 formindex;
  struct nbTimeList_t_array *timelist;
  nbActionProcessData_t_o *v13;
  s32 v14;
  struct nbTimeList_t_array *v15;
  nbActionProcessData_t_o *v17;
  s32 v18;
  struct nbTimeList_t_array *v19;
  struct nbFormation_t_o *form;
  nbMainProcessData_t_o *data;
  nbParty_t_o *party;
  datUnitWork_t_o *UnitWorkPointer;
  struct nbMainProcessData_t_o *v27;
  datUnitWork_t_o *v28;
  u64 *v30;
  s32 nowcommand;
  s16 v32;
  s32 v33;
  u16 nowindex;

  v3 = *a;
  if (((*a)->stat & 0x10) == 0)
  {
    packettime = v3->packettime;
    if (packettime >= 0x10)
    {
      v3->packettime = packettime - 1;
      return 0;
    }
    nbUpdateOrder();
    v9 = *a;
    formindex = (*a)->form->formindex;
    timelist = v9->timelist;
    if (timelist->m_Items[formindex]->hp || (nbGetDevilFormatFlag(formindex) & 0x100) != 0)
    {
      CheckInotiNego(a);
    }
    v13 = *a;
    v14 = (*a)->form->formindex;
    v15 = v13->timelist;
    if (v15->m_Items[v14]->hp || (nbGetDevilFormatFlag(v14) & 0x100) != 0)
    {
      CheckBinjoNego(a);
    }
    v17 = *a;
    v18 = (*a)->form->formindex;
    v19 = v17->timelist;
    if (v19->m_Items[v18]->hp || (nbGetDevilFormatFlag(v18) & 0x100) != 0)
    {
      form = (*a)->form;
      if (form->motendtype == 3)
        form->stat |= 0x4000u;
    }
    CheckDeadScript(a);
    data = (*a)->data;
    party = (*a)->party;
    UnitWorkPointer = nbGetUnitWorkPointer(data, party);
    v27 = (*a)->data;
    if (!UnitWorkPointer)
    {
      v27->previndex = 0;
      (*a)->data->prevcommand = 0;
      (*a)->data->prevcommind = 0;
      (*a)->data->prevflag = 0;
        goto LABEL_76;
      goto LABEL_78;
    }
    v27->previndex = (*a)->partyindex;
    (*a)->data->prevcommand = UnitWorkPointer->nowcommand;
    (*a)->data->prevcommind = UnitWorkPointer->nowindex;
    nowindex = UnitWorkPointer->nowindex;
    v28 = UnitWorkPointer;
    v30 = sub_8D3950(ushort, &nowindex);
    Write_2930400("prev commind = {0:D}\n", v30);
    (*a)->data->prevflag = 0;
    if (((*a)->stat & 8) != 0)
      (*a)->data->prevflag |= 1u;
    nowcommand = v28->nowcommand;
    v32 = v28->nowcommand;
    if (!v32 || nowcommand == 3)
    {
      v28->prevcommand = v32;
      v28->previndex = v28->nowindex;
    }
    else
    {
      if (nowcommand != 1)
      {
LABEL_64:
        datClearCommMemory(v28);
          goto LABEL_78;
        goto LABEL_76;
      }
      v33 = v28->nowindex;
      if ((v33 - 164) < 3)
        goto LABEL_75;
      if ((v33 - 49) < 2)
        goto LABEL_64;
      if (v33 == 247)
      {
LABEL_75:
        {
LABEL_76:
        }
LABEL_78:
        (*a)->nextseq = 20;
        return 1;
      }
      v28->prevcommand = v32;
      v28->previndex = v33;
    }
    *&v28->prevtarea = *&v28->nowtarea;
    goto LABEL_75;
  }
  else if (DDS3_PADCHECK_TRIG(1))
  {
    goto LABEL_80;
  }
  if (DDS3_PADCHECK_TRIG(3))
    goto LABEL_80;
LABEL_12:
  v7 = 1;
LABEL_84:
  nbOnOffKoukaPacketFlag(14, 2u, v7);
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
  struct nbMainProcessData_t_o *data;
  s32 v6;
  nbActionProcessData_t_o *v7;
  u32 stat;
  nbMainProcessData_t_o *v10;
  nbParty_t_o *party;
  datUnitWork_t_o *UnitWorkPointer;
  nbActionProcessData_t_o *v14;
  char v15;
  s32 v16;
  datUnitWork_t_o *v17;
  s32 nowindex;
  nbActionProcessData_t_Fields *p_fields;
  nbActionProcessData_t_o *v20;
  s32 v21;
  s32 ItemSkillNo;
  s32 v23;
  u64 *v25;
  u64 *v26;
  nbActionProcessData_t_Fields *v29;
  s32 v30;
  struct datNormalSkill_t_array *tbl;
  u64 *v37;
  Il2CppObject *v39;
  struct datNormalSkill_t_array *v42;
  s32 nbCommSelGameCnt;
  s32 v45;
  u16 v46;

  else if (!dds3DebugSign)
  {
    goto LABEL_21;
  }
  else if (!DDS3_PADCHECK_PRESS(9))
  {
    goto LABEL_21;
  }
  else if (DDS3_PADCHECK_PRESS(11))
  {
    goto LABEL_12;
  }
LABEL_21:
  else if (!dds3DebugSign)
  {
    goto LABEL_47;
  }
  else if (!DDS3_PADCHECK_PRESS(9))
  {
    goto LABEL_47;
  }
  else if (DDS3_PADCHECK_PRESS(3))
  {
    goto LABEL_30;
  }
LABEL_47:
  v7 = *a;
  if (((*a)->data->stat & 0x40) != 0)
  {
    stat = v7->stat;
    if ((stat & 0x80) == 0)
    {
      v7->stat = stat | 0x80;
      nbSetAutoCommSel();
    }
  }
  if (nbGetCommSelStat() != 3)
    return 0;
LABEL_56:
  v10 = (*a)->data;
  party = (*a)->party;
  UnitWorkPointer = nbGetUnitWorkPointer(v10, party);
  switch (UnitWorkPointer->nowcommand)
  {
    case 0:
      goto LABEL_114;
    case 1:
    case 5:
      v17 = UnitWorkPointer;
      if (UnitWorkPointer->nowcommand != 1)
        goto LABEL_72;
      nowindex = UnitWorkPointer->nowindex;
      if ((nowindex & 0xFFFE) != 0xDE && nowindex != 252 && (nowindex - 226) > 4)
        goto LABEL_97;
      p_fields = &(*a)->fields;
      nbSetPlayerSummonFormation(&p_fields->data);
      nbSetEnemySummonFormation(&(*a)->data, 0, 0);
      if (v17->nowcommand == 1)
      {
LABEL_97:
        v23 = v17->nowindex;
      }
      else
      {
LABEL_72:
        v20 = *a;
        v21 = v17->nowindex;
        ItemSkillNo = nbGetItemSkillNo(v20, v21);
        v46 = v17->nowindex;
        v23 = ItemSkillNo;
        v25 = sub_8D3950(ushort, &v46);
        Write_2930400("item no = {0:D}\n", v25);
        v45 = v23;
        v26 = sub_8D3950(s32, &v45);
        Write_2930400("skill no = {0:D}\n", v26);
      }
      v30 = nbCheckBattleSkillError1(v23);
      v14 = *a;
      if (v30 && (v14->stat & 0x80) == 0)
      {
        nbDispSkillErrorMessage(v30);
        nbSetCommSelStat(2);
        return 0;
      }
      if ((v14->party->flag & 6) != 0)
      {
          goto LABEL_118;
        goto LABEL_116;
      }
      if ((tbl->m_Items[v23]->targetarea & 1) == 0)
      {
LABEL_114:
          goto LABEL_117;
        goto LABEL_115;
      }
      v42 = tbl;
      if ((v42->m_Items[v23]->targetarea & 0xC) != 0)
      {
          goto LABEL_117;
LABEL_115:
LABEL_116:
LABEL_117:
        v14 = *a;
LABEL_118:
        v16 = 0;
        v15 = 5;
        goto LABEL_119;
      }
      v14 = *a;
      v15 = 6;
      v16 = 0;
LABEL_119:
      v14->nextseq = v15;
      v6 = 1;
LABEL_120:
      if (((*a)->stat & 0x80) == 0)
      {
LABEL_121:
        nbPlaySe(8);
        v37 = sub_8D3950(s32, &nbCommSelGameCnt);
        v39 = Concat("111:nbCommSelGameCnt:", v37);
        Log(v39, 0);
      }
LABEL_131:
      if (v16)
      {
LABEL_133:
        nbCloseCommSel();
      }
      return v6;
    case 2:
    case 7:
    case 8:
      v14 = *a;
      v15 = 7;
      v16 = 1;
      goto LABEL_119;
    case 3:
      (*a)->nextseq = 7;
      v16 = 1;
      v6 = 1;
      if (!wait_se2)
        goto LABEL_120;
      goto LABEL_133;
    case 4:
      (*a)->negotype = 0;
        goto LABEL_117;
      goto LABEL_115;
    case 6:
      v29 = &(*a)->fields;
      nbSetPlayerSummonFormation(&v29->data);
      nbSetEnemySummonFormation(&(*a)->data, 0, 0);
      goto LABEL_114;
    default:
      v16 = 0;
      v6 = 0;
      if (((*a)->stat & 0x80) != 0)
        goto LABEL_131;
      goto LABEL_121;
  }
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
    goto LABEL_18;
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
LABEL_18:
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
  struct nbMainProcessData_t_o *data;
  u64 *v6;
  s32 negoresult;

  data = (*a)->data;
  if (data->NegoProcessID)
    return 0;
  negoresult = data->negoresult;
  v6 = sub_8D3950(s32, &negoresult);
  Write_2930400("nego result = {0:D}\n", v6);
  (*a)->nextseq = 10;
  nbPanelDraw(1);
  if (datCheckPlayerDead())
    (*a)->data->negoresult = 8;
  return 1;
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
    goto LABEL_34;
  }
  switch (v6->type)
  {
    case 1:
      v7 = 4;
      v6->work->nowcommand = 4;
      (*a)->work->nowindex = 386;
      v8 = *a;
      goto LABEL_18;
    case 2:
      v6->work->nowcommand = 4;
      (*a)->work->nowindex = (*a)->data->prevcommind;
      v8 = *a;
      v7 = 3;
      goto LABEL_18;
    case 3:
      v6->work->nowcommand = 4;
      (*a)->work->nowindex = 386;
      v8 = *a;
      v7 = 5;
LABEL_18:
      v8->negotype = v7;
      target = (*a)->target;
      SetTargetParty(a, target);
      goto LABEL_22;
    case 4:
      v6->work->nowcommand = 1;
      (*a)->work->nowindex = (*a)->adata;
      v16 = (*a)->target;
      SetTargetParty(a, v16);
      v18 = *a;
      data = (*a)->data;
      v18->select = nbGetSelectBit(data);
      (*a)->stat |= 4u;
      goto LABEL_33;
    case 5:
      else
      {
        v9 = 19;
      }
      goto LABEL_34;
    default:
      nbSetHojoAddCounter(v6->form->formindex, 17, 1, 0);
      nbSetHojoAddCounter((*a)->form->formindex, 18, 1, 0, 0);
      BadStat = nbGetBadStat((*a)->form->formindex, 0);
      if (BadStat <= 4)
      {
        if (((1 << BadStat) & 0x16) == 0)
          goto LABEL_45;
LABEL_41:
        v6 = *a;
        v9 = 4;
        goto LABEL_34;
      }
      if (BadStat == 16 || BadStat == 1024 || BadStat == 128)
        goto LABEL_41;
LABEL_45:
      v6 = *a;
      flag = (*a)->party->flag;
      if ((flag & 2) == 0)
      {
        if ((flag & 4) == 0)
        {
            goto LABEL_48;
          goto LABEL_50;
        }
        else
        {
          v9 = 21;
        }
        goto LABEL_34;
      }
      if (CheckMukanNego(a))
      {
        (*a)->work->nowcommand = 4;
        (*a)->work->nowindex = 386;
        (*a)->negotype = 1;
          goto LABEL_68;
        goto LABEL_66;
      }
      if (CheckSenseiNego(a))
      {
        (*a)->work->nowcommand = 4;
        (*a)->work->nowindex = 386;
        (*a)->negotype = 2;
          goto LABEL_68;
LABEL_66:
LABEL_68:
        SetTargetPlayer(a);
LABEL_22:
        v14 = *a;
        v15 = (*a)->data;
        v14->select = nbGetSelectBit(v15);
LABEL_33:
        v6 = *a;
        v9 = 7;
        goto LABEL_34;
      }
      v6 = *a;
      if (dds3DebugSign == 1 && (v6->data->stat & 0x10000000) != 0)
      {
        {
LABEL_48:
        }
LABEL_50:
        v9 = 1;
        goto LABEL_34;
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
LABEL_34:
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
        goto LABEL_35;
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
LABEL_35:
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
            goto LABEL_62;
          case 2:
            v25 = 13;
            goto LABEL_62;
          case 3:
          case 8:
          case 9:
          case 0xA:
            else
            {
              v25 = 12;
            }
            goto LABEL_62;
          case 4:
            v25 = 9;
            goto LABEL_62;
          case 7:
            v25 = 14;
LABEL_62:
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
  u32 StkSelId;
  s32 v38;
  nbMainProcessData_t_o *data;
  nbMainProcessData_t_o *v44;
  u32 v46;

  else
  {
    if (StkSelId != -1)
      goto LABEL_6;
  }
  v44 = (*a)->data;
  v46 = nbPanelStockSelect(v44, 1u);
  v38 = 0;
  StkSelId = v46;
  return v38;
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
        v44 = Find(transform, "bmenu/normal_command/bmenu_cursur", 0);
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
    goto LABEL_76;
  work = v49->work;
  nowcommand = work->nowcommand;
  if (nowcommand == 1)
  {
    nowindex = work->nowindex;
  }
  else
  {
    if (nowcommand != 5)
      goto LABEL_72;
    v53 = work->nowindex;
    nowindex = nbGetItemSkillNo(v49, v53);
    if (nowindex < 0)
      goto LABEL_72;
  }
  v55 = nbCheckBattleSkillError2(nowindex, v50);
  if (!v55)
  {
LABEL_72:
    nbPlaySe(8);
LABEL_76:
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
      goto LABEL_24;
  }
  else
  {
    v9 = 0;
    if (!evtBitCheck(2130))
      goto LABEL_24;
  }
  if (((*a)->stat & 0x20000) != 0)
    v9 = 1;
LABEL_24:
  if (evtBitCheck(2131))
  {
    if (((*a)->stat & 0x40000) != 0)
      v9 = 1;
    if (!evtBitCheck(2132))
    {
LABEL_28:
      if (evtBitCheck(2133))
        goto LABEL_29;
LABEL_38:
      if (!evtBitCheck(2134))
        goto LABEL_32;
LABEL_39:
      if (!((*a)->stat & 0x200000 | v9))
        return 0;
      goto LABEL_40;
    }
  }
  else if (!evtBitCheck(2132))
  {
    goto LABEL_28;
  }
  if (((*a)->stat & 0x80000) != 0)
    v9 = 1;
  if (!evtBitCheck(2133))
    goto LABEL_38;
LABEL_29:
  if (((*a)->stat & 0x100000) != 0)
    v9 = 1;
  if (evtBitCheck(2134))
    goto LABEL_39;
LABEL_32:
  if (!v9)
    return 0;
LABEL_40:
  partyindex = EventForm->partyindex;
  v13 = (*a)->partyindex;
  nbPushAction(4, partyindex, v13, 243);
  Write("アーリマンカウンター発生!!!\n", 0);
  return 1;
}

// 0xf34630
s32 CheckBinjoNego(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v3;
  struct nbMainProcessData_t_o *data;
  s32 result;
  datUnitWork_t_o *work;
  s64 v9;
  struct nbFormation_t_array *form;
  u64 v11;
  s64 v13;
  struct nbParty_t_array *party;
  struct nbParty_t_array *v16;
  struct nbParty_t_array *v18;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct nbTimeList_t_array *timelist;
  s32 id;
  struct datUnitWork_t_o *v24;
  s32 v25;
  signed s32 v26;
  struct nbParty_t_array *v27;
  nbParty_t_o *v29;
  s32 v30;
  s32 partyindex;
  u64 *v33;
  char v34[4];

  v3 = *a;
  data = (*a)->data;
  if (data->StageMajor - 240 < 7
    || (data->stat & 1) != 0
    || (v3->party->flag & 6) != 0
    || v3->partyindex > 3
    || (v3->stat & 8) == 0)
  {
    return 0;
  }
  if (evtGetAgeOfMoon() == 8)
    return 0;
  work = (*a)->work;
  result = datCheckTalk(work);
  if (result)
  {
    v9 = 8;
    do
    {
      form = (*a)->data->form;
      v11 = v9 - 4;
      v13 = *(&form->obj.klass + v9);
      if ((*(v13 + 136) & 0x49) != 0x41)
        goto LABEL_64;
      party = (*a)->data->party;
      if ((party->m_Items[*(v13 + 176)]->flag & 1) == 0)
        goto LABEL_64;
      v16 = (*a)->data->party;
      if ((v16->m_Items[*(v13 + 176)]->flag & 0x20) != 0)
        goto LABEL_64;
      v18 = (*a)->data->party;
      if ((v18->m_Items[*(v13 + 176)]->flag & 0x40) != 0)
        goto LABEL_64;
      UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(v11);
      timelist = (*a)->timelist;
      if (!*(*(&timelist->obj.klass + v9) + 20LL) && (nbGetDevilFormatFlag(v11) & 0x100) == 0)
        goto LABEL_64;
      id = UnitWorkFromFormindex->id;
      if (!Get(id, 0)->binjotype)
        goto LABEL_64;
      v24 = (*a)->work;
      if ((v24->flag & 4) != 0)
      {
        v25 = UnitWorkFromFormindex->id;
      }
      else
      {
        v25 = UnitWorkFromFormindex->id;
        if (v24->id == v25)
          goto LABEL_64;
      }
      if (datSearchDevilStock(v25) < 0)
      {
        if (datCheckTalk(UnitWorkFromFormindex))
        {
          if (((*a)->data->stat & 0x2000000) != 0)
            v26 = 100;
          else
            v26 = 2;
          if (dds3GetRandIntA(0x64u, "CheckBinjoNego") < v26)
          {
            v27 = (*a)->data->party;
            v29 = v27->m_Items[*(v13 + 176)];
            v29->flag |= 0x40u;
            v30 = *(v13 + 176);
            partyindex = (*a)->partyindex;
            nbPushAction(2, v30, partyindex, 0);
            *v34 = *(v13 + 176);
            v33 = sub_8D3950(s16, v34);
            Write_2930400("binjo party = {0:D}\n", v33);
            return 1;
          }
        }
      }
LABEL_64:
      result = 0;
      ++v9;
    }
    while (v11 < 0xD);
  }
  return result;
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
    goto LABEL_21;
  }
  if (v15 - 1 < 2)
    return 0;
  result = 0;
  if ((badstatus & 0xFFF) != 4 && (badstatus & 0xFFF) != 0x10)
  {
LABEL_21:
    v38 = v8;
    v39 = from;
    v18 = 0;
    v19 = v7 + 2;
    if (!LODWORD(v7[1].monitor))
    {
LABEL_22:
    }
    while (1)
    {
      v21 = *(&v19->klass + v18);
      if ((v21 & 0x80000000) != 0)
        return 0;
      if (datCheckSyojiSkill(v16, v21))
      {
        v26 = *(&v19->klass + v18) - 288LL;
        v28 = 100 / tbl->m_Items[v26]->n;
        if (v28 > dds3GetRandIntA(0x64u, "CheckCounter"))
        {
          v30 = *(&v38[2].klass + v18);
          if (v30)
          {
            form = (*a)->data->form;
            max_length = form->max_length;
            partyindex = form->m_Items[v39]->partyindex;
            v36 = (*a)->data->form->m_Items[to]->partyindex;
            nbPushAction(4, partyindex, v36, v30);
            Write("カウンター発生!!!\n", 0);
            return 1;
          }
          return 0;
        }
      }
      if (++v18 >= LODWORD(v7[1].monitor))
        goto LABEL_22;
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
              goto LABEL_23;
          }
          v11 = v10;
          v12 = *(v7 + 176);
          nbPushAction(5, v12, 0, v11);
        }
      }
LABEL_23:
      if (i == 17)
        return;
      v3 = *a;
    }
  }
}

// 0xf34100
s32 CheckInotiNego(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v3;
  struct nbMainProcessData_t_o *data;
  s32 result;
  datUnitWork_t_o *work;
  u32 nowcommand;
  struct nbMainProcessData_t_o *v10;
  s64 i;
  struct nbFormation_t_array *form;
  u64 v13;
  s64 v15;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct nbParty_t_array *party;
  datUnitWork_t_o *v18;
  struct nbParty_t_array *v20;
  struct nbTimeList_t_array *timelist;
  s32 id;
  nbActionProcessData_t_o *v25;
  struct nbTimeList_t_array *v26;
  struct datUnitWork_t_o *v28;
  u32 stat;
  struct datUnitWork_t_array *unitwork;
  signed s32 v33;
  s32 v34;
  s32 partyindex;
  u64 *v36;
  Il2CppObject *v37;
  u64 *v39;
  u16 v40[2];
  char v41[4];

  v3 = *a;
  data = (*a)->data;
  if (data->StageMajor - 240 < 7
    || (data->stat & 1) != 0
    || (v3->party->flag & 6) != 0
    || v3->partyindex > 3)
  {
    return 0;
  }
  if (evtGetAgeOfMoon() == 8)
    return 0;
  work = (*a)->work;
  result = datCheckTalk(work);
  if (result)
  {
    nowcommand = (*a)->work->nowcommand;
    result = 0;
    if (nowcommand <= 5 && ((1 << nowcommand) & 0x23) != 0)
    {
      v10 = (*a)->data;
      if (v10->enemypcnt != 1)
        return 0;
      for (i = 8; ; ++i)
      {
        form = v10->form;
        v13 = i - 4;
        v15 = *(&form->obj.klass + i);
        if ((~*(v15 + 136) & 0x49) == 0)
        {
          UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(v13);
          party = (*a)->data->party;
          v18 = UnitWorkFromFormindex;
          if ((party->m_Items[*(v15 + 176)]->flag & 1) != 0)
          {
            v20 = (*a)->data->party;
            if ((v20->m_Items[*(v15 + 176)]->flag & 0x20) == 0)
            {
              timelist = (*a)->timelist;
              if (*(*(&timelist->obj.klass + i) + 20LL) || (nbGetDevilFormatFlag(v13) & 0x100) != 0)
              {
                id = v18->id;
                {
                }
                if (Get(id, 0)->inotitype && v18->id - 368 >= 0x20)
                {
                  v25 = *a;
                  if (((*a)->data->stat & 0x2000000) == 0)
                  {
                    v26 = v25->timelist;
                    if ((100 * *(*(&v26->obj.klass + i) + 20LL) / v18->maxhp) > 24)
                      goto LABEL_72;
                    v25 = *a;
                  }
                  v28 = v25->work;
                  if ((v28->flag & 4) != 0 || v28->id != v18->id)
                  {
                    if (datCheckTalk(v18))
                    {
                      stat = (*a)->data->stat;
                      if ((stat & 0x2000000) == 0)
                      {
                        {
                        }
                        unitwork = DDS3_GBWK->unitwork;
                        if (unitwork->m_Items[0]->level < v18->level)
                          goto LABEL_72;
                        stat = (*a)->data->stat;
                      }
                      if ((stat & 0x2000000) != 0)
                        v33 = 100;
                      else
                        v33 = 6;
                      {
                      }
                      if (dds3GetRandIntA(0x64u, "CheckInotiNego") < v33)
                      {
                        v34 = *(v15 + 176);
                        partyindex = (*a)->partyindex;
                        {
                        }
                        nbPushAction(1, v34, partyindex, 0);
                        *v41 = *(v15 + 176);
                        v36 = sub_8D3950(s16, v41);
                        v40[0] = v18->id;
                        v37 = v36;
                        v39 = sub_8D3950(ushort, v40);
                        {
                        }
                        Write_2930752("inoti party = {0:D} ({1:X})\n", v37, v39, 0);
                        return 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
LABEL_72:
        if (v13 > 0xC)
          return 0;
        v10 = (*a)->data;
      }
    }
  }
  return result;
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
                goto LABEL_36;
            }
            else if (v20 == 16 || v20 == 256 || v20 == 1024)
            {
              goto LABEL_36;
            }
            v21 = v7;
            ++v7;
            *(v6 + v21 + 32) = *(v12 + 176);
          }
        }
      }
    }
LABEL_36:
    if (i == 17)
      break;
    v5 = *a;
  }
  if (!v7)
    return 0;
  RandIntA = dds3GetRandIntA(v7, "CheckKoketaNego1");
  v26 = *(v6 + RandIntA + 32);
  partyindex = (*a)->partyindex;
  nbPushAction(3, v26, partyindex, 0);
  Write("escape err party\n", 0);
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
  if (dds3GetRandIntA(0x64u, "CheckMukanNego") >= v26)
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
      if (dds3GetRandIntA(0x64u, "CheckSenseiNego") >= v16)
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
  u64 *v8;
  u64 i;
  s64 *v11;
  s64 *v13;
  u64 v15;
  System_SByte_array **m_Items;
  il2cpp_array_size_t *p_max_length;
  System_SByte_array *v18;
  System_SByte_array *v19;
  struct datNormalSkill_t_array *tbl;
  s32 targetcntmin;
  u32 targetcntmax;
  u64 *v29;
  u64 *v31;
  s64 j;
  u64 v34;
  s32 v35;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v38;
  struct nbMainProcessData_t_o *data;
  struct nbFormation_t_array *v41;
  s64 v43;
  struct nbParty_t_array *party;
  u32 v45;
  struct nbTimeList_t_array *timelist;
  struct datNormalSkill_t_array *v50;
  s32 v52;
  signed s32 v53;
  u64 *v57;
  s64 *v58;
  s64 v59;
  s64 v60;
  s64 v61;
  u32 RandIntA;
  s32 v65;
  s32 v66;
  u32 v67;
  u32 v68;
  u64 *v69;
  u64 *v70;
  s64 v71;
  s64 v72;
  s32 v75;
  u32 v76;
  u64 *v78;
  s64 v79;
  s64 v80;
  s64 v84;
  s32 v86;
  u64 k;
  System_SByte_array *v88;
  Il2CppClass **v92;
  s64 *v93;
  Il2CppClass *v94;
  Il2CppClass *v95;
  s64 v98;
  System_SByte_array *v102;
  s64 v105;
  s32 v107;
  s32 v108;
  s64 v109;
  u64 v110;
  struct nbFormation_t_array *v111;
  struct nbFormation_t_array *v113;
  struct nbFormation_t_array *v115;
  s32 v117;
  datUnitWork_t_o *UnitWorkFromFormindex;
  signed s32 v119;
  s64 v121;
  s64 v124;
  s64 v126;
  System_SByte_array *v128;
  s64 v129;
  s8 v130;
  System_SByte_array *v131;
  u32 animetype;
  s32 v135;
  s32 v136;
  u32 v137;
  Il2CppClass **v141;
  s64 *v142;
  Il2CppClass *v143;
  Il2CppClass *v144;
  s64 v145;
  s32 v147;
  u32 v148;
  System_SByte_array **v149;
  u32 v150;
  s8 v151;
  System_SByte_array *v152;
  System_SByte_array **v153;
  s8 v154;
  System_SByte_array *v155;
  s32 v176;
  s32 v177;
  u32 v178;
  Il2CppClass **v180;
  s64 *v181;
  Il2CppClass *v182;
  Il2CppClass *v183;
  s64 v186;
  u32 v188;
  s32 m;
  Il2CppClass **v191;
  s64 *v192;
  Il2CppClass *v193;
  Il2CppClass *v194;
  s64 v197;
  signed s32 v199;
  s32 v200;
  char v201;
  s32 id;
  u32 v204;
  s32 v205;

  v8 = NewSpecific(sbyte__, 0x10u);
  for (i = 0; i != 16; ++i)
  {
    v11 = NewSpecific(sbyte, 2u);
    v13 = v11;
    v8[i + 4] = v13;
  }
  v15 = 0;
  m_Items = koukalist->m_Items;
  p_max_length = &koukalist->max_length;
  do
  {
    v18 = m_Items[v15];
    v18->m_Items[0] = -1;
    v19 = m_Items[v15];
    ++v15;
    v19->m_Items[1] = 0;
  }
  while (v15 != 32);
  if ((*a)->runerr)
    return;
  targetcntmin = tbl->m_Items[nskill]->targetcntmin;
  targetcntmax = tbl->m_Items[nskill]->targetcntmax;
  if (targetcntmin < targetcntmax)
  {
    targetcntmin += dds3GetRandIntA(1 - targetcntmin + targetcntmax, "GetKoukaList0");
  }
  v201 = targetcntmin;
  v205 = targetcntmin;
  v204 = select;
  v29 = sub_8D3950(s32, &v205);
  v31 = sub_8D3950(uint, &v204);
  Write_2930752("反映回数={0:D}, select = 0x{1:X8}\n", v29, v31, 0);
  for (j = 4; j != 20; ++j)
  {
    v34 = j - 4;
    v35 = 1 << (j - 4);
    if ((v35 & select) != 0)
    {
      form = (*a)->data->form;
      if ((*(*(&form->obj.klass + j) + 136LL) & 1) != 0)
      {
        v38 = (*a)->data->form;
        if ((*(*(&v38->obj.klass + j) + 136LL) & 0x40) != 0)
        {
          data = (*a)->data;
          v41 = data->form;
          v43 = *(&v41->obj.klass + j);
          party = data->party;
          v45 = *(v43 + 176);
          if ((party->m_Items[v45]->flag & 0x20) != 0)
            goto LABEL_56;
          timelist = (*a)->timelist;
          if (!*(*(&timelist->obj.klass + j) + 20LL) && (nbGetDevilFormatFlag(v34) & 0x100) == 0)
LABEL_56:
            select &= ~v35;
        }
      }
    }
  }
  v50 = tbl;
  if (v50->m_Items[nskill]->targetrandom == 1)
  {
    v52 = 0;
    v53 = 0;
    do
    {
      if (((1 << v52) & select) != 0)
      {
        v57 = &v8[v53];
        v60 = v57[4];
        v58 = v57 + 4;
        v59 = v60;
        *(v59 + 32) = v52;
        v61 = *v58;
        ++v53;
        *(v61 + 33) = 0;
      }
      ++v52;
    }
    while (v52 != 32);
    if (!v53)
      return;
    RandIntA = dds3GetRandIntA(2u, "GetKoukaList1");
    if (targetcntmin < 1)
      return;
    v199 = RandIntA + v53;
    v200 = 0;
    v65 = -1;
    v66 = 0;
    while (1)
    {
      while (1)
      {
        id = v66;
        if (v53 < 2)
        {
          v76 = dds3GetRandIntA(v53, "GetKoukaList2");
          v68 = v76;
          v78 = &v8[v76];
          v80 = v78[4];
          v70 = v78 + 4;
          v79 = v80;
          v75 = *(v79 + 32);
          if (v76 >= *(v8 + 6))
          {
LABEL_101:
          }
        }
        else
        {
          do
          {
            v67 = dds3GetRandIntA(v53, "GetKoukaList2");
            v68 = v67;
            v69 = &v8[v67];
            v72 = v69[4];
            v70 = v69 + 4;
            v71 = v72;
          }
          while (v65 == *(v71 + 32));
          v75 = *(v71 + 32);
          if (v67 >= *(v8 + 6))
            goto LABEL_101;
        }
        v65 = v75;
        if (v199 > *(*v70 + 33LL))
          break;
LABEL_128:
        v66 = id + 1;
        if (id + 1 == targetcntmin)
          return;
      }
      v84 = *v70;
      ++*(v84 + 33);
      v86 = v200;
      if (v200 < 1)
      {
        LODWORD(k) = 0;
        if (!v200)
          goto LABEL_119;
      }
      else
      {
        for (k = 0; k < v200; ++k)
        {
          v88 = koukalist->m_Items[k];
          if (v88->m_Items[0] == v75)
            break;
        }
        v86 = v200;
        if (k == v200)
        {
LABEL_119:
          v92 = &koukalist->obj.klass + v86;
          v95 = v92[4];
          v93 = (v92 + 4);
          v94 = v95;
          LOBYTE(v94->_1.byval_arg.data) = v75;
          v98 = *v93;
          *(v98 + 33) = 1;
          ++v200;
          goto LABEL_128;
        }
      }
      v102 = koukalist->m_Items[k];
      ++v102->m_Items[1];
      v66 = id + 1;
      if (id + 1 == targetcntmin)
        return;
    }
  }
  if ((nskill & 0xFFFFFFFE) != 0x9E)
  {
    animetype = Get(nskill, 0)->animetype;
    if (nskill == 204 && ((*a)->data->stat & 8) != 0)
    {
      if (animetype > 0xF)
        return;
      v135 = 1 << animetype;
      if ((v135 & 0xF0F) == 0)
      {
        if ((v135 & 0xF0) == 0)
          goto LABEL_192;
        goto LABEL_265;
      }
    }
    else
    {
      if (animetype > 0xF)
        return;
      v176 = 1 << animetype;
      if (!v176)
      {
        if ((v176 & 0xF00) == 0)
        {
LABEL_192:
          v136 = 0;
          v137 = 0;
          do
          {
            if (((1 << v136) & select) != 0)
            {
              v141 = &koukalist->obj.klass + v137;
              v144 = v141[4];
              v142 = (v141 + 4);
              v143 = v144;
              LOBYTE(v143->_1.byval_arg.data) = v136;
              v145 = *v142;
              ++v137;
              *(v145 + 33) = v201;
            }
            ++v136;
          }
          while (v136 != 32);
          if (v137 >= 2)
          {
            v147 = 32;
            do
            {
              v148 = dds3GetRandIntA(v137, "GetKoukaList4");
              v149 = &koukalist->m_Items[v148];
              v150 = dds3GetRandIntA(v137, "GetKoukaList5");
              v151 = (*v149)->m_Items[0];
              v152 = *v149;
              v153 = &koukalist->m_Items[v150];
              v152->m_Items[0] = (*v153)->m_Items[0];
              (*v153)->m_Items[0] = v151;
              v154 = (*v149)->m_Items[1];
              v155 = *v149;
              v155->m_Items[1] = (*v153)->m_Items[1];
              --v147;
              (*v153)->m_Items[1] = v154;
            }
            while (v147);
          }
          return;
        }
LABEL_265:
        v188 = 0;
        for (m = 31; m != -1; --m)
        {
          if (((1 << m) & select) != 0)
          {
            v191 = &koukalist->obj.klass + v188;
            v194 = v191[4];
            v192 = (v191 + 4);
            v193 = v194;
            LOBYTE(v193->_1.byval_arg.data) = m;
            v197 = *v192;
            ++v188;
            *(v197 + 33) = v201;
          }
        }
        return;
      }
    }
    v177 = 0;
    v178 = 0;
    do
    {
      if (((1 << v177) & select) != 0)
      {
        v180 = &koukalist->obj.klass + v178;
        v183 = v180[4];
        v181 = (v180 + 4);
        v182 = v183;
        LOBYTE(v182->_1.byval_arg.data) = v177;
        v186 = *v181;
        ++v178;
        *(v186 + 33) = v201;
      }
      ++v177;
    }
    while (v177 != 32);
    return;
  }
  v105 = v8[4];
  v107 = 0;
  v108 = 101;
  v109 = 4;
  *(v105 + 32) = 0;
  do
  {
    while (1)
    {
      v110 = v109 - 4;
      if (((1 << (v109 - 4)) & select) == 0)
        goto LABEL_170;
      v111 = (*a)->data->form;
      if ((*(*(&v111->obj.klass + v109) + 136LL) & 1) == 0)
        goto LABEL_170;
      v113 = (*a)->data->form;
      if ((*(*(&v113->obj.klass + v109) + 136LL) & 0x40) == 0)
        goto LABEL_170;
      v115 = (*a)->data->form;
      v117 = *(*(&v115->obj.klass + v109) + 178LL);
      UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(v117);
      if (!UnitWorkFromFormindex->hp)
        goto LABEL_170;
      v119 = 100 * UnitWorkFromFormindex->hp / UnitWorkFromFormindex->maxhp;
      if (v108 > v119)
        break;
      if (v108 == v119)
      {
        v124 = v8[v107 + 4];
        ++v107;
        *(v124 + 32) = v110;
      }
LABEL_170:
      if (++v109 == 20)
        goto LABEL_171;
    }
    v121 = v8[4];
    *(v121 + 32) = v110;
    v107 = 1;
    v108 = v119;
    ++v109;
  }
  while (v109 != 20);
LABEL_171:
  if (v107 < 1)
  {
    v126 = 0;
    if (!*p_max_length)
      goto LABEL_176;
  }
  else
  {
    v126 = dds3GetRandIntA(10 * v107, "GetKoukaList3") % v107;
    if (!*p_max_length)
    {
LABEL_176:
    }
  }
  v128 = koukalist->m_Items[0];
  v129 = v8[v126 + 4];
  v130 = *(v129 + 32);
  v128->m_Items[0] = v130;
  v131 = koukalist->m_Items[0];
  v131->m_Items[1] = 1;
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
        goto LABEL_11;
    }
  }
  else
  {
LABEL_11:
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
LABEL_6:
  se0_str = GetSOBED(x)->se0_str;
  return FindId(1, se0_str);
}

// 0xf3e160
s32 MAKE_SKILL_SE01(s32 x) {
  System_String_o *se1_str;

  se1_str = GetSOBED(x)->se1_str;
  if (!se1_str)
    return -1;
LABEL_6:
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
  nbActionProcessData_t_o *v3;
  s32 formindex;
  struct nbTimeList_t_array *timelist;
  s32 v10;
  nbActionProcessData_t_o *v12;
  u16 *work;
  s32 v14;
  s32 v17;
  s64 i;
  struct nbTimeList_t_array *v19;
  struct nbTimeList_t_array *v21;
  nbActionProcessData_t_o *v23;
  u64 v24;
  s64 v25;
  struct nbFormation_t_array *form;
  struct nbFormation_t_array *v28;
  struct nbTimeList_t_array *v30;
  struct nbMainProcessData_t_o *data;
  struct nbFormation_t_array *v33;
  struct nbParty_t_array *party;
  s64 partyindex;
  u64 *v39;
  struct nbFormation_t_array *v40;
  s32 v46;
  struct nbTimeList_t_array *v47;
  s32 v49;
  s64 j;
  struct nbTimeList_t_array *v51;
  struct nbTimeList_t_array *v53;
  s32 v55;
  s64 k;
  struct nbTimeList_t_array *v57;
  struct nbTimeList_t_array *v59;
  struct nbFormation_t_o *v61;
  s32 motendtype;
  s32 v63;
  s32 v64;
  nbActionProcessData_t_o **v65;
  s32 v66;
  s32 v67;
  s32 v68;
  s32 v69;
  s32 v70;
  nbActionProcessData_t_o *v71;
  s32 v72;
  s64 m;
  struct nbTimeList_t_array *v74;
  struct nbTimeList_t_array *v76;
  nbActionProcessData_t_o *v78;
  u64 *v80;
  u32 packettime;
  s32 v82;

  v3 = *a;
  formindex = (*a)->form->formindex;
  timelist = v3->timelist;
  if ((timelist->m_Items[formindex]->hp || (nbGetDevilFormatFlag(formindex) & 0x100) != 0)
    && nbGetBadStat((*a)->form->formindex, 0) == 64)
  {
    v10 = (*a)->form->formindex;
    else if (CheckTimeListDeadEnemyParty(a, v10))
    {
      goto LABEL_24;
    }
    v12 = *a;
    if (!(*a)->data->endtype)
    {
      work = v12->work;
      if ((work[44] != 5 || work[45] != 1) && (v12->party->flag & 0x20) == 0)
      {
        v14 = work[12] >> 3;
        SetDamagePacket(a, v14);
          goto LABEL_27;
        goto LABEL_25;
      }
    }
  }
LABEL_24:
  {
LABEL_25:
  }
LABEL_27:
  v17 = 0;
  for (i = 4; i != 36; ++i)
  {
    while (1)
    {
      v19 = (*a)->timelist;
      if (v17 < *(*(&v19->obj.klass + i) + 16LL))
        break;
      if (++i == 36)
        goto LABEL_36;
    }
    v21 = (*a)->timelist;
    v17 = *(*(&v21->obj.klass + i) + 16LL);
  }
LABEL_36:
  v23 = *a;
  v24 = 0;
  v25 = 32;
  do
  {
    form = v23->data->form;
    if ((form->m_Items[v24]->stat & 1) != 0)
    {
      v28 = (*a)->data->form;
      if ((v28->m_Items[v24]->stat & 0x40) != 0)
      {
        v30 = (*a)->timelist;
        if (!v30->m_Items[v24]->hp && (nbGetDevilFormatFlag(v24) & 0x100) == 0)
        {
          data = (*a)->data;
          v33 = data->form;
          party = data->party;
          partyindex = v33->m_Items[v24]->partyindex;
          if ((party->m_Items[partyindex]->flag & 0x20) == 0)
          {
            v82 = v24;
            v39 = sub_8D3950(s32, &v82);
            Write_2930400("dead formindex = {0:D}!!\n", v39);
            v40 = (*a)->data->form;
            nbMakeDeadVisualPacket(v17, (*a)->uniqueid, (v40 + v25), 0, 1, 0);
            SetTimeList(a, v24, v17, 30, 30);
            SetDeadPacket(a, v24);
            SetTimeList(a, v24, v17, 20, 20);
          }
        }
      }
    }
    v23 = *a;
    ++v24;
    v25 += 8;
  }
  while (v24 != 16);
  v46 = v23->form->formindex;
  v47 = v23->timelist;
  if (v47->m_Items[v46]->hp || (nbGetDevilFormatFlag(v46) & 0x100) != 0)
  {
    v49 = 0;
    for (j = 4; j != 36; ++j)
    {
      while (1)
      {
        v51 = (*a)->timelist;
        if (v49 < *(*(&v51->obj.klass + j) + 18LL))
          break;
        if (++j == 36)
          goto LABEL_84;
      }
      v53 = (*a)->timelist;
      v49 = *(*(&v53->obj.klass + j) + 18LL);
    }
LABEL_84:
    v55 = 0;
    for (k = 4; k != 36; ++k)
    {
      while (1)
      {
        v57 = (*a)->timelist;
        if (v55 < *(*(&v57->obj.klass + k) + 16LL))
          break;
        if (++k == 36)
          goto LABEL_93;
      }
      v59 = (*a)->timelist;
      v55 = *(*(&v59->obj.klass + k) + 16LL);
    }
LABEL_93:
    v61 = (*a)->form;
    motendtype = v61->motendtype;
    if (motendtype == 2)
    {
      v63 = 0;
      if ((v61->stat & 0x10) == 0)
        goto LABEL_112;
    }
    else
    {
      if (((*a)->stat & 0x100) != 0)
        v63 = 0;
      else
        v63 = 3;
      if ((v61->stat & 0x10) == 0)
        goto LABEL_112;
    }
    v64 = v61->formindex;
    if (motendtype == 2)
    {
      v65 = a;
      v66 = v64;
      v67 = v49;
      v68 = 6;
      v69 = 6;
    }
    else
    {
      v68 = v63 + 1;
      v65 = a;
      v66 = v64;
      v67 = v49;
      v69 = v63 + 1;
    }
    SetTimeList(v65, v66, v67, v68, v69);
    if ((*a)->form->motendtype == 2)
    {
      v70 = v63 + v49;
      nbMakeUnitFadeInPacket(v70, (*a)->uniqueid, &(*a)->form, 0, 2, 4, 4, 0);
      nbAddFormOnOffPacket(v70, (*a)->uniqueid, &(*a)->form, 0, 0);
      if ((*a)->form->motendtype == 2)
        nbAddMotionStopClearPacket(v70, (*a)->uniqueid, &(*a)->form, 0);
    }
  }
LABEL_112:
  v71 = *a;
  v72 = 0;
  for (m = 4; m != 36; ++m)
  {
    while (1)
    {
      v74 = (*a)->timelist;
      if (v72 < *(*(&v74->obj.klass + m) + 18LL))
        break;
      if (++m == 36)
        goto LABEL_124;
    }
    v76 = (*a)->timelist;
    v72 = *(*(&v76->obj.klass + m) + 18LL);
  }
LABEL_124:
  v71->packettime = v72;
  nbAddHatudoEffectEndPacket(70 * (*a)->packettime / 0x64, (*a)->uniqueid, 0);
  v78 = *a;
  if (((*a)->stat & 0x400) != 0)
  {
    nbAddPanelStockFadeOutPacket(
      (v78->packettime - 10) & ~((v78->packettime - 10) >> 31),
      v78->uniqueid,
      0);
    nbAddPanelStockEndPacket((*a)->packettime - 1, (*a)->uniqueid, 0);
    v78 = *a;
  }
  packettime = v78->packettime;
  v80 = sub_8D3950(uint, &packettime);
  Write_2930400("allframe {0:D}\n", v80);
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
      goto LABEL_3;
LABEL_5:
    v3->stat |= 0x80u;
    goto LABEL_6;
  }
  v3 = *a;
  if (((*a)->data->stat & 0x40) != 0)
    goto LABEL_5;
LABEL_3:
  nbDelAllKoukaPacketType(38);
LABEL_6:
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
  s64 v3;
  s32 v4;
  struct nbFormation_t_array *form;
  u64 v6;
  struct nbFormation_t_array *v8;
  struct nbFormation_t_array *v10;
  struct nbFormation_t_array *v12;
  s32 formindex;
  struct nbFormation_t_o *v15;
  u32 stat;
  u64 *v17;
  u64 *v19;
  s32 negotype;
  s32 nowindex;
  s32 v24;
  s32 v25;

  v3 = 4;
  v4 = -1;
  do
  {
    form = (*a)->data->form;
    v6 = v3 - 4;
    if ((*(*(&form->obj.klass + v3) + 136LL) & 1) != 0)
    {
      v8 = (*a)->data->form;
      if ((*(*(&v8->obj.klass + v3) + 136LL) & 8) != 0)
      {
        v10 = (*a)->data->form;
        if ((*(*(&v10->obj.klass + v3) + 137LL) & 1) != 0)
        {
          formindex = v3 - 4;
          v4 = -1;
          v15 = (*a)->form;
          stat = v15->stat;
          if ((stat & 0x100) != 0)
            goto LABEL_21;
          goto LABEL_18;
        }
        v12 = (*a)->data->form;
        if ((*(*(&v12->obj.klass + v3) + 137LL) & 2) != 0)
        {
          v4 = v3 - 4;
          formindex = -1;
          v15 = (*a)->form;
          stat = v15->stat;
          if ((stat & 0x100) != 0)
            goto LABEL_21;
          goto LABEL_18;
        }
      }
    }
    ++v3;
  }
  while (v6 <= 0xE);
  formindex = -1;
  v15 = (*a)->form;
  stat = v15->stat;
  if ((stat & 0x100) != 0)
  {
LABEL_21:
    formindex = v15->formindex;
    goto LABEL_22;
  }
LABEL_18:
  if ((stat & 0x200) != 0)
    v4 = v15->formindex;
LABEL_22:
  v25 = formindex;
  v17 = sub_8D3950(s32, &v25);
  v24 = v4;
  v19 = sub_8D3950(s32, &v24);
  Write_2930752("NEGO p:{0:D} e:{1:D}\n", v17, v19);
  nbPanelDraw(0);
  (*a)->data->negopformindex = formindex;
  (*a)->data->negoeformindex = v4;
  negotype = (*a)->negotype;
  nowindex = (*a)->work->nowindex;
  nbInitNegoProcess(a, formindex, v4, negotype, nowindex);
}

// 0xf3e760
void SetAction_NEGORESULT(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v3;
  struct nbMainProcessData_t_o *data;
  s32 v5;
  s32 v6;
  s32 v7;
  s32 v8;
  s32 negoeformindex;
  s32 v12;
  nbActionProcessData_t_o *v13;
  s32 v14;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 v19;
  s32 v20;
  s32 id;
  u64 v22;
  s64 i;
  struct nbParty_t_array *v24;
  struct nbParty_t_array *v26;
  struct nbParty_t_array *v28;
  struct nbMainProcessData_t_o *v30;
  struct nbParty_t_array *v31;
  nbParty_t_o *v33;
  s32 RandIntA;
  struct nbParty_t_array *v35;
  s32 v36;
  struct nbParty_t_array *v39;
  struct nbParty_t_array *v41;
  s32 v43;
  s32 v44;
  datUnitWork_t_o *v46;
  u64 v47;
  s64 j;
  struct nbParty_t_array *v49;
  struct nbParty_t_array *v51;
  struct nbParty_t_array *v53;
  s32 v55;
  struct nbParty_t_array *v56;
  s32 v57;
  struct nbParty_t_array *v60;
  struct nbParty_t_array *v62;
  s32 v64;
  nbActionProcessData_t_o *v65;
  u32 negotype;
  s32 v67;
  struct nbMainProcessData_t_o *v68;
  struct nbFormation_t_array *v69;
  u32 v70;
  nbActionProcessData_t_o *v72;
  nbFormation_t_o **p_form;
  struct nbMainProcessData_t_o *v74;
  struct nbFormation_t_array *v75;
  s64 v76;
  s32 v78;
  s64 k;
  struct nbParty_t_array *v80;
  struct nbParty_t_array *v82;
  nbFormation_t_o *form;
  nbParty_t_o *party;

  party = 0;
  form = 0;
  v3 = *a;
  data = (*a)->data;
  v5 = 0;
  v6 = 0;
  v7 = 1;
  v8 = 1;
  switch (data->negoresult)
  {
    case 1:
      v6 = 1;
      v5 = 12;
      v3->press = -1.0;
      goto LABEL_23;
    case 2:
      negoeformindex = data->negoeformindex;
      party = nbGetPartyFromFormindex(negoeformindex);
      nbMakeReturnPacket(0, (*a)->uniqueid, &party, 0);
      v12 = (*a)->data->negoeformindex;
      SetTimeList(a, v12, 0, 40, 40);
      v13 = *a;
      goto LABEL_58;
    case 3:
      v14 = data->negoeformindex;
      party = nbGetPartyFromFormindex(v14);
      UnitWorkFromFormindex = nbGetUnitWorkFromFormindex((*a)->data->negoeformindex, 0);
      nbGetNakama(UnitWorkFromFormindex);
      nbMakeReturnPacket(0, (*a)->uniqueid, &party, 0);
      v19 = (*a)->data->negoeformindex;
      SetTimeList(a, v19, 0, 40, 40);
      v7 = 0;
      v5 = 11;
      v8 = 1;
      (*a)->press = -1.0;
      v6 = 1;
      goto LABEL_94;
    case 4:
      v6 = 1;
      v3->press = -10.0;
      v5 = 13;
LABEL_23:
      v7 = 1;
      goto LABEL_93;
    case 5:
      v20 = data->negoeformindex;
      id = nbGetUnitWorkFromFormindex(v20)->id;
      v13 = *a;
      v22 = 4;
      for (i = 64; i != 144; i += 8)
      {
        v24 = v13->data->party;
        if (((*(&v24->obj.klass + i))->_1.name & 1) != 0)
        {
          v26 = (*a)->data->party;
          if (((*(&v26->obj.klass + i))->_1.name & 2) != 0)
          {
            v28 = (*a)->data->party;
            if (((*(&v28->obj.klass + i))->_1.name & 0x20) == 0)
            {
              v30 = (*a)->data;
              v31 = v30->party;
              v33 = *(&v31->obj.klass + i);
              if (nbGetUnitWorkPointer(v30, v33)->id == id)
              {
                RandIntA = dds3GetRandIntA(0x14u, "SetAction_NEGORESULT0");
                v35 = (*a)->data->party;
                v36 = RandIntA;
                nbMakeReturnPacket(RandIntA, (*a)->uniqueid, (v35 + i), 0);
                v39 = (*a)->data->party;
                if (((*(&v39->obj.klass + i))->_1.name & 8) == 0)
                {
                  v41 = (*a)->data->party;
                  v43 = SWORD1((*(&v41->obj.klass + i))->_1.name);
                  SetTimeList(a, v43, v36, 40, 40);
                }
              }
            }
          }
        }
        v13 = *a;
        ++v22;
      }
LABEL_58:
      v7 = 0;
      v13->press = -1.0;
      v6 = 1;
      v5 = 12;
      goto LABEL_93;
    case 6:
      goto LABEL_67;
    case 7:
      goto LABEL_94;
    case 8:
      v5 = 0;
      v6 = 0;
      v7 = 0;
      v8 = 0;
      goto LABEL_94;
    case 9:
      v44 = data->negoeformindex;
      v46 = nbGetUnitWorkFromFormindex(v44);
      nbGetNakama(v46);
LABEL_67:
      v47 = 4;
      for (j = 64; j != 144; j += 8)
      {
        v49 = (*a)->data->party;
        if (((*(&v49->obj.klass + j))->_1.name & 1) != 0)
        {
          v51 = (*a)->data->party;
          if (((*(&v51->obj.klass + j))->_1.name & 2) != 0)
          {
            v53 = (*a)->data->party;
            if (((*(&v53->obj.klass + j))->_1.name & 0x20) == 0)
            {
              v55 = dds3GetRandIntA(0x14u, "SetAction_NEGORESULT1");
              v56 = (*a)->data->party;
              v57 = v55;
              nbMakeReturnPacket(v55, (*a)->uniqueid, (v56 + j), 0);
              v60 = (*a)->data->party;
              if (((*(&v60->obj.klass + j))->_1.name & 8) == 0)
              {
                v62 = (*a)->data->party;
                v64 = SWORD1((*(&v62->obj.klass + j))->_1.name);
                SetTimeList(a, v64, v57, 40, 40);
              }
            }
          }
        }
        ++v47;
      }
      break;
    default:
      break;
  }
  v5 = 0;
  v6 = 0;
  v7 = 0;
LABEL_93:
  v8 = 1;
LABEL_94:
  v65 = *a;
  negotype = (*a)->negotype;
  if (negotype - 3 < 2)
  {
    if (!v6 || v65->data->negoresult != 4)
      goto LABEL_102;
  }
  else if (negotype - 1 > 1)
  {
    if (!v6)
      goto LABEL_102;
  }
  else if (!v6 || (v65->data->negoresult - 2) > 2)
  {
    goto LABEL_102;
  }
  nbMakePressPacket(0, v65->uniqueid, v65->press);
  nbMakeNewPressPacket(0, (*a)->uniqueid, v5, &(*a)->form, 0);
LABEL_102:
  if (v7)
  {
    v67 = (*a)->data->negoeformindex;
    nbGetUnitWorkFromFormindex(v67);
    v68 = (*a)->data;
    v69 = v68->form;
    v70 = v68->negoeformindex;
    form = v69->m_Items[v70];
    nbSetWaitMotion(&form, 0, 1.0);
    nbSetUnitMotion(&form, 0, 1, 1.0);
  }
  if (v8)
  {
    v72 = *a;
    if (!(*a)->negotype)
    {
      p_form = &v72->form;
      if ((v72->form->stat & 0x10) != 0)
      {
        v74 = v72->data;
        v75 = v74->form;
        v76 = v74->negoeformindex;
        nbCameraSetTaizi(p_form, &v75->m_Items[v76]);
      }
    }
  }
  v78 = 0;
  for (k = 8; k != 18; ++k)
  {
    while (1)
    {
      v80 = (*a)->data->party;
      if ((*(*(&v80->obj.klass + k) + 16LL) & 1) != 0)
        break;
      if (++k == 18)
        goto LABEL_127;
    }
    v82 = (*a)->data->party;
    v78 += ((*(*(&v82->obj.klass + k) + 16LL) >> 5) & 1) == 0;
  }
LABEL_127:
  if (!v78)
    (*a)->data->endtype = 9;
}

// 0xf35ca0
void SetAction_NON(nbActionProcessData_t **a) {
  ;
}

// 0xf38600
void SetAction_READY(nbActionProcessData_t **a) {
  datUnitWork_t_o *work;
  datUnitVisual_t_o *UnitVisual;
  nbActionProcessData_t_o *v11;
  u32 stat;
  nbActionProcessData_t_o *v13;
  u32 v14;
  f32 v15;
  f32 v16;
  nbActionProcessData_t_o *v17;
  struct datUnitWork_t_o *v18;
  s32 nowindex;
  s32 v20;
  nbActionProcessData_t_o **v21;
  s32 v22;
  nbActionProcessData_t_o **v23;
  s32 v24;
  s32 v25;
  nbActionProcessData_t_o *v26;
  struct datUnitWork_t_o *v27;
  u32 nowcommand;
  s64 v31;
  s32 v33;
  nbActionProcessData_t_o *v34;
  u32 v35;
  nbActionProcess_SOBED_o *SOBED;
  System_String_o *v38;
  System_Byte_array **p_hBed;
  UnityEngine_Texture_c *v42;
  il2cpp_array_size_t max_length;
  nbActionProcessData_t_o *v44;
  s64 v45;
  s64 v46;
  u32 *pTexture;
  u64 v48;
  AssetBundleCtrl_o *asset_bc;
  struct System_String_array *tga_fname;
  System_String_o *v53;
  s64 *FileObject;
  s64 *v55;
  s64 v56;
  s64 typeHierarchyDepth;
  char *v58;
  s64 *v59;
  s64 v61;
  s64 v62;
  char *v63;
  s64 *v64;
  s64 v66;
  s64 v68;
  struct SOBED_PB_LIST_array *v69;
  nbActionProcess_c *v70;
  u64 v71;
  s64 v72;
  u32 *sobed_pb_all;
  u64 *v74;
  struct nbActionProcess_SOBED_PB_array *pbdata;
  struct nbActionProcess_SOBED_PB_array *v80;
  struct nbActionProcess_SOBED_PB_array *v83;
  struct nbActionProcess_SOBED_PB_array *v85;
  struct SOBED_PB_LIST_array *v88;
  SOBED_PB_LIST_o *v90;
  AssetBundleCtrl_o *v91;
  struct nbActionProcess_SOBED_PB_array *v93;
  System_String_o *prefab_name;
  System_String_o *v96;
  System_String_o *v97;
  struct SOBED_PB_LIST_array *v99;
  UnityEngine_GameObject_o *Prefab_16624656;
  struct SOBED_PB_LIST_array *v104;
  struct nbActionProcess_SOBED_PB_array *v107;
  struct SOBED_PB_LIST_array *v110;
  SOBED_PB_LIST_o *v112;
  struct nbActionProcess_SOBED_PB_array *v113;
  s32 v116;
  nbActionProcess_SOBED_o *v118;
  struct datUnitWork_t_o *v119;
  s32 v120;
  s32 motion;
  s32 MotionNoOrg;
  s32 MotionNo;
  s32 v124;
  System_String_o *v125;
  System_String_o *v126;
  nbActionProcessData_t_o *v127;
  struct nbFormation_t_o *v128;
  u32 v129;
  struct nbFormation_t_o *v130;
  struct nbFormation_t_o *v131;
  s32 motenddata;
  f32 MotionSpeed;
  nbActionProcessData_t_o *v134;
  nbFormation_t_o *v135;
  u32 v136;
  struct datUnitMotion_s_array *v137;
  s32 movetype;
  u16 v141;
  u64 *v143;
  struct datNormalSkill_t_array *tbl;
  s32 costtype;
  datUnitWork_t_o *v149;
  s32 v150;
  s32 v152;
  struct datNormalSkill_t_array *v154;
  datUnitWork_t_o *v156;
  s32 v157;
  s32 SkillCost;
  s32 v159;
  nbActionProcessData_t_o *v160;
  u32 formindex;
  struct nbTimeList_t_array *timelist;
  s32 v164;
  nbTimeList_t_o *v165;
  nbActionProcessData_t_o *v166;
  s32 v167;
  s32 timer;
  s32 uniqueid;
  nbFormation_t_o **p_form;
  s32 v171;
  datNormalSkillVisual_t_o *v172;
  struct datUnitWork_t_o *v173;
  s32 v175;
  u64 *v177;
  u64 *v179;
  nbActionProcessData_t_o *v181;
  s32 v182;
  struct datNormalSkill_t_array *v184;
  u64 v186;
  struct nbFormation_t_array *v187;
  nbFormation_t_o *v189;
  s32 v190;
  struct nbParty_t_array *party;
  s64 i;
  struct nbFormation_t_array *v194;
  u64 v195;
  struct nbFormation_t_array *v197;
  struct nbFormation_t_array *v199;
  struct nbFormation_t_array *v201;
  struct nbFormation_t_array *v203;
  struct nbFormation_t_array *v205;
  struct nbFormation_t_array *v207;
  struct nbFormation_t_array *v209;
  struct nbFormation_t_array *v211;
  struct nbFormation_t_array *v213;
  struct nbFormation_t_array *v215;
  struct nbFormation_t_array *v217;
  struct nbFormation_t_array *v219;
  struct nbFormation_t_array *v221;
  struct nbFormation_t_array *v223;
  nbActionProcessData_t_o *v226;
  struct datUnitWork_t_o *v227;
  s32 v228;
  s32 v229;
  s32 v230;
  s32 v231;
  struct datUnitWork_t_o *v233;
  s32 v235;
  s32 v236;
  s32 v238;
  s32 v239;
  u32 v240;
  s32 id;
  s32 v242;
  s32 v243;
  nbFormation_t_o *TargetFormation;
  s32 v245;
  datUnitVisual_t_o *v246;
  s16 v247;
  nbFormation_t_o *form;
  s32 no;
  char v250[16];
  char *v251;

  form = 0;
  no = 0;
  nbBgmTrans();
  (*a)->press = 0.0;
  (*a)->runerr = 0;
  (*a)->jyokyomes = 0;
  (*a)->skilltime = 0;
  (*a)->autoskill = 0;
  (*a)->allhpdamage = 0;
  (*a)->allmpdamage = 0;
  (*a)->form->motendtype = 0;
  (*a)->form->motenddata = 0;
  ClearTimeList(a);
  SetHpForTimeList(a);
  work = (*a)->work;
  UnitVisual = nbGetUnitVisual(work);
  else if (!cfgGetBit(0xCu))
  {
    goto LABEL_24;
  }
  v11 = *a;
  stat = (*a)->stat;
  if ((stat & 0x80) != 0 && !v11->work->nowcommand)
  {
    v11->stat = stat | 0x100;
    v13 = *a;
    v14 = (*a)->stat;
    if ((v14 & 0x100) != 0)
      goto LABEL_18;
    goto LABEL_25;
  }
LABEL_24:
  v13 = *a;
  v14 = (*a)->stat;
  if ((v14 & 0x100) != 0)
  {
LABEL_18:
    if (v13->work->id == 192)
      v15 = 1.0;
    else
      v15 = 3.0;
    v16 = 1.5;
    if ((v14 & 4) != 0)
      goto LABEL_34;
    goto LABEL_26;
  }
LABEL_25:
  v16 = 1.0;
  v15 = 1.0;
  if ((v14 & 4) != 0)
    goto LABEL_34;
LABEL_26:
  v13->stat = v14 | 4;
  if (nbGetBadStat((*a)->form->formindex, 0) == 8
    && (*a)->type != 3
    && nbCheckBadPanicAction((*a)->work, 0))
  {
    goto LABEL_510;
  }
  if (nbCheckBadCurse((*a)->form->formindex, 0))
  {
    if (!dds3GetRandIntA(4u, "SetAction_READY"))
    {
LABEL_510:
      v21 = a;
      v20 = 4;
LABEL_43:
      SetActionSeq(v21, v20);
      return;
    }
  }
LABEL_34:
  v17 = *a;
  v18 = (*a)->work;
  nowindex = 0;
  switch (v18->nowcommand)
  {
    case 0xFFFF:
      v20 = 18;
      v21 = a;
      goto LABEL_43;
    case 1:
      nowindex = v18->nowindex;
      no = nowindex;
      v22 = nbCheckSkillUse(v17->form->formindex, nowindex);
      switch (v22)
      {
        case 3:
          (*a)->runerr = 1;
          v23 = a;
          v24 = 12;
          break;
        case 2:
          (*a)->runerr = 1;
          v23 = a;
          v24 = 14;
          break;
        case 1:
          (*a)->runerr = 1;
          v23 = a;
          v24 = 60;
          break;
        default:
          goto LABEL_65;
      }
      nbSetJyokyoMes(v23, v24, -1, 0);
LABEL_65:
      v26 = *a;
      v27 = (*a)->work;
      nowcommand = v27->nowcommand;
      if (nowcommand >= 2 && nowcommand - 4 > 2 || v26->select)
      {
        if (v27->nowcommand != 5)
          goto LABEL_83;
        goto LABEL_69;
      }
      v26->runerr = 3;
      nbSetJyokyoMes(a, 62, -1, 0);
      v27 = (*a)->work;
      if (v27->nowcommand == 5)
      {
LABEL_69:
        v31 = v27->nowindex;
        if ((tbl->m_Items[v31]->flag & 4) != 0)
        {
          v33 = (*a)->work->nowindex;
          datAddItem(v33, -1);
        }
      }
LABEL_83:
      (*a)->stat &= ~1u;
      v34 = *a;
      v35 = (*a)->work->nowcommand;
      if (v35 > 6 || ((1 << v35) & 0x62) == 0)
        goto LABEL_209;
      v246 = UnitVisual;
      v34->hBed = 0;
      if (!Get(nowindex, 0)->bedno)
        goto LABEL_200;
      SOBED = GetSOBED(nowindex);
      v38 = Concat_5224608("dds3data/sobed/", SOBED->bed_fname);
      sdfDevLoadFileUnity_25061072(v38, &(*a)->hBed, 0, "sobed", 0);
      p_hBed = &(*a)->hBed;
      MarkTmxIndex(p_hBed);
      MarkPibIndex(&(*a)->hBed, 0);
      max_length = GetSOBED(nowindex)->tga_fname->max_length;
      if (max_length)
      {
        v44 = *a;
        v44->pTexture = NewSpecific(UnityEngine_Texture, max_length);
        if (max_length >= 1)
        {
          v45 = 4;
          v46 = max_length;
          do
          {
            pTexture = (*a)->pTexture;
            v48 = v45 - 4;
            asset_bc = get_asset_bc();
            tga_fname = GetSOBED(no)->tga_fname;
            v53 = Concat_5224608("dds3data/sobed/", *(&tga_fname->obj.klass + v45), 0);
            FileObject = LoadFileObject(asset_bc, "sobed", v53);
            v55 = FileObject;
            if (FileObject)
            {
              v56 = *FileObject;
              if (*(*FileObject + 288) < typeHierarchyDepth
                || *(*(v56 + 200) + 8 * typeHierarchyDepth - 8) != UnityEngine_Texture)
              {
                sub_8FC2C0(*(v56 + 64), UnityEngine_Texture, v250);
                if ((v250[0] & 1) != 0)
                  v58 = v251;
                else
                  v58 = &v250[1];
                v59 = sub_8C4940(v58);
              }
              v61 = *v55;
              if (*(*v55 + 288) < v62 || *(*(v61 + 200) + 8 * v62 - 8) != UnityEngine_Texture)
              {
                sub_8FC2C0(*(v61 + 64), UnityEngine_Texture, v250);
                if ((v250[0] & 1) != 0)
                  v63 = v251;
                else
                  v63 = &v250[1];
                v64 = sub_8C4940(v63);
              }
            }
            v66 = v45 - 3;
            *&pTexture[2 * v45++] = v55;
          }
          while (v66 < v46);
          nowindex = no;
        }
      }
      v67 = GetSOBED(nowindex, v42);
      v68 = *(v67->genericMethod + 3);
      SobedClear();
      if (v68)
      {
        v69 = NewSpecific(SOBED_PB_LIST, v68);
        sobed_pb_all = v69;
        if (v68 >= 1)
        {
          v71 = 0;
          v72 = v68 - 1LL;
          if ((v70->_2.bitflags2 & 2) == 0)
            goto LABEL_137;
LABEL_134:
          while (1)
          {
LABEL_137:
            v74 = Allocate(SOBED_PB_LIST);
            SOBED_PB_LIST___ctor(v74);
            *&sobed_pb_all[2 * v71 + 8] = v74;
            pbdata = GetSOBED(no)->pbdata;
            if (pbdata->m_Items[v71]->prefab_name)
            {
              v80 = GetSOBED(no)->pbdata;
              if (!v80->m_Items[v71]->type)
                break;
            }
            v83 = GetSOBED(no)->pbdata;
            if (v83->m_Items[v71]->prefab_name)
            {
              v85 = GetSOBED(no)->pbdata;
              if (v85->m_Items[v71]->type == 1)
              {
                v88 = sobed_pb_all;
                v90 = v88->m_Items[v71];
                v91 = get_asset_bc();
                v93 = GetSOBED(no)->pbdata;
                prefab_name = v93->m_Items[v71]->prefab_name;
                v96 = "sobed_pb";
                v97 = "charactor/b";
LABEL_191:
                Prefab_16624656 = LoadPrefab_16624656(v91, v96, v97, prefab_name);
                goto LABEL_192;
              }
            }
            v99 = sobed_pb_all;
            v90 = v99->m_Items[v71];
            Prefab_16624656 = 0;
LABEL_192:
            v90->gobj = Prefab_16624656;
            v110 = sobed_pb_all;
            v112 = v110->m_Items[v71];
            v113 = GetSOBED(no)->pbdata;
            v112->reversePB = v113->m_Items[v71]->reversePB;
            if (v72 == v71)
              goto LABEL_200;
            ++v71;
              goto LABEL_134;
          }
          v104 = sobed_pb_all;
          v90 = v104->m_Items[v71];
          v91 = get_asset_bc();
          v107 = GetSOBED(no)->pbdata;
          prefab_name = v107->m_Items[v71]->prefab_name;
          v96 = "sobed_pb";
          v97 = "dds3data";
          goto LABEL_191;
        }
LABEL_200:
        v116 = no;
          goto LABEL_201;
      }
      else
      {
        sobed_pb_all = 0;
        v116 = no;
        {
LABEL_201:
        }
      }
      v118 = GetSOBED(v116);
      (*a)->se0_name = v118->se0_str;
      (*a)->se1_name = v118->se1_str;
      v34 = *a;
      UnitVisual = v246;
      if ((*a)->se0_name)
      {
        if (v34->se1_name)
          goto LABEL_209;
      }
      else
      {
        v125 = sub_232A70(&no, "X3");
        v34->se0_name = Concat_5221536("SKIL", v125, "_SE00");
        v34 = *a;
        if ((*a)->se1_name)
          goto LABEL_209;
      }
      v126 = sub_232A70(&no, "X3");
      v34->se1_name = Concat_5221536("SKIL", v126, "_SE01");
      v34 = *a;
LABEL_209:
      v119 = v34->work;
      v120 = -1;
      motion = 3;
      MotionNoOrg = -1;
      MotionNo = -1;
      switch (v119->nowcommand)
      {
        case 0:
          goto LABEL_218;
        case 1:
          v124 = v119->nowindex;
          {
          }
          motion = Get(v124, 0)->motion;
          v34 = *a;
          goto LABEL_218;
        case 2:
        case 3:
        case 4:
          break;
        case 5:
          motion = 25;
          goto LABEL_218;
        case 6:
          motion = 24;
LABEL_218:
          nbDelAllMojiNumEffectKoukaPacket(&v34->form, motion);
          nbAddFormFlagOnOffPacket(0, (*a)->uniqueid, &(*a)->form, 0, 0x2000u, 0);
          v127 = *a;
          v128 = (*a)->form;
          v129 = v128->stat;
          if ((v129 & 0x4000) != 0)
          {
            v128->stat = v129 & 0xFFFFBFFF;
            v127 = *a;
            v128 = (*a)->form;
          }
          v128->motendtype = nbGetMotionEndType(&v127->form, motion);
          v130 = (*a)->form;
          v130->motenddata = nbGetMotionEndData(&(*a)->form, motion, 0);
          MotionNo = nbGetMotionNo(&(*a)->form, motion, 0);
          MotionNoOrg = nbGetMotionNoOrg(&(*a)->form, motion, 0);
          nbAddSkillMotionKoukaPacket(
            0,
            (*a)->uniqueid,
            &(*a)->form,
            motion,
            (*a)->form->motendtype,
            v15,
            0);
          v34 = *a;
          v131 = (*a)->form;
          if (v131->motendtype == 2)
          {
            motenddata = v131->motenddata;
            if ((motenddata & 0x80000000) == 0)
            {
              MotionSpeed = nbGetMotionSpeed(&(*a)->form, motion, v15, 0);
              nbMakeUnitFadeOutPacket(
                (motenddata / MotionSpeed),
                (*a)->uniqueid,
                &(*a)->form,
                0,
                2,
                4,
                4,
                0);
              v34 = *a;
            }
          }
          v120 = motion;
          break;
        default:
          MotionNoOrg = -1;
          MotionNo = -1;
          break;
      }
      v34->form->motcate = v120;
      (*a)->motion = MotionNo;
      (*a)->motionO = MotionNoOrg;
      v134 = *a;
      if (((*a)->stat & 0x100) == 0)
      {
        v135 = v134->form;
        v134->motse = nbMemoryLoadMotionSe(v135, MotionNoOrg);
        v134 = *a;
      }
      v136 = v134->work->nowcommand;
      if (v136 > 6)
        goto LABEL_241;
      if (((1 << v136) & 0x63) != 0)
      {
        v134->timer = nbGetMotionActframe(&v134->form, v120, v15);
        v137 = UnitVisual->motion;
        if (no == 115 && (*a)->work->nowcommand == 1)
          movetype = 2;
        else
          movetype = v137->m_Items[v120]->movetype;
      }
      else if (v136 == 4)
      {
        switch (v134->negotype)
        {
          case 0u:
          case 5u:
          case 6u:
            goto LABEL_241;
          case 1u:
          case 3u:
          case 4u:
            v134->timer = 35;
            v141 = 3;
            goto LABEL_251;
          case 2u:
            v134->timer = 35;
            v141 = 21;
LABEL_251:
            nbCameraSetState(v141);
            nbAddMojiEffKoukaPacket(0, 30, (*a)->uniqueid, &(*a)->form, 0, 0);
            break;
          default:
            break;
        }
        movetype = 0;
      }
      else
      {
LABEL_241:
        movetype = 0;
        v134->timer = 0;
      }
      *v250 = (*a)->timer;
      v143 = sub_8D3950(uint, v250);
      Write_2930400("acttime = {0:D}\n", v143);
      if (!(*a)->runerr && (*a)->work->nowcommand == 1)
      {
        costtype = tbl->m_Items[no]->costtype;
        if (costtype == 2)
        {
          v156 = (*a)->work;
          v157 = no;
          SkillCost = datGetSkillCost(v156, v157);
          nbAddHpMpKoukaPacket(1, (*a)->uniqueid, &(*a)->form, -SkillCost, 1, 0);
        }
        else if (costtype == 1)
        {
          v149 = (*a)->work;
          v150 = no;
          v152 = datGetSkillCost(v149, v150);
          v154 = tbl;
          if ((v154->m_Items[no]->flag & 8) != 0)
          {
            if ((no - 115) <= 1)
              v159 = 83;
            else
              v159 = 60;
            nbAddHpMpKoukaPacket(
              v159 + (*a)->timer,
              (*a)->uniqueid,
              &(*a)->form,
              -32767,
              0,
              0);
            v152 = 0x7FFF;
          }
          else
          {
            nbAddHpMpKoukaPacket(1, (*a)->uniqueid, &(*a)->form, -v152, 0, 0);
          }
          v160 = *a;
          formindex = (*a)->form->formindex;
          if ((v160->data->stat & 0x20000) == 0)
          {
            timelist = v160->timelist;
            v164 = timelist->m_Items[formindex]->hp - v152;
            v165 = timelist->m_Items[formindex];
            if (v164 < 0)
              v165->hp = 0;
            else
              v165->hp = v164;
          }
        }
      }
      v166 = *a;
      v167 = (*a)->work->nowcommand;
      if ((v167 - 5) < 2)
        goto LABEL_295;
      if (v167 == 7)
      {
        nbAddHitEffKoukaPacket(0, v166->uniqueid, &v166->form, 5);
      }
      else if (v167 == 1)
      {
LABEL_295:
        timer = v166->timer;
        uniqueid = v166->uniqueid;
        p_form = &v166->form;
        v171 = no;
        v172 = Get(v171, 0);
        nbAddHatudoEffectKoukaPacket(
          0,
          timer,
          uniqueid,
          p_form,
          v172->hatudo,
          (*a)->form->motcate,
          no,
          0);
      }
      v173 = (*a)->work;
      switch (v173->nowcommand)
      {
        case 0:
          nbSetNormalSkill0(v173);
          nbDelAllKoukaPacketType(14);
          effBTLSkillEnd();
          effBTLSkillSetFormationInfo((*a)->party->formindex, LOWORD((*a)->select), 0);
          v175 = 0;
          goto LABEL_315;
        case 1:
        case 5:
        case 6:
          nbSetNormalSkill0(v173);
          nbDelAllKoukaPacketType(14);
          effBTLSkillEnd();
          effBTLSkillSetFormationInfo((*a)->party->formindex, LOWORD((*a)->select), 0);
          v175 = no;
LABEL_315:
          effBTLSkillStart(v175, 0);
          break;
        case 3:
          nbCameraSetState(3u);
          break;
        default:
          break;
      }
      v247 = (*a)->party->formindex;
      v177 = sub_8D3950(s16, &v247);
      *v250 = (*a)->select;
      v179 = sub_8D3950(uint, v250);
      Write_2930752("select {0:D} -> {1:X8}\n", v177, v179);
      v181 = *a;
      v182 = (*a)->work->nowcommand;
      if (v182 != 4)
      {
        if (movetype == 2)
        {
          if ((v182 | 4) == 5)
          {
            v184 = tbl;
            if (v184->m_Items[no]->targettype)
            {
              if (v184->m_Items[no]->targettype - 1 <= 1)
                movetype = 5;
              else
                movetype = 2;
            }
            else
            {
              movetype = 4;
            }
          }
          else
          {
            movetype = 2;
          }
        }
        nbMakeUnitMovePacket(
          1,
          (*a)->uniqueid,
          &(*a)->form,
          LOWORD((*a)->select),
          movetype,
          v16,
          0);
        v181 = *a;
      }
      v186 = 0;
      break;
    case 5:
      v25 = v18->nowindex;
      nowindex = nbGetItemSkillNo(v17, v25);
      no = nowindex;
      goto LABEL_65;
    case 6:
      nowindex = 255;
      no = 255;
      goto LABEL_65;
    default:
      goto LABEL_65;
  }
  do
  {
    while (1)
    {
      if ((v181->select & (1 << v186)) == 0)
        goto LABEL_350;
      v187 = v181->data->form;
      v189 = v187->m_Items[v186];
      form = v189;
      v190 = v181->work->nowcommand;
      if (v190 == 6)
        break;
      if (v190 != 4)
        goto LABEL_350;
      nbMakeUnitMovePacket(0, v181->uniqueid, &form, 1 << v181->form->formindex, 1, 1.0);
      v181 = *a;
      if (++v186 == 16)
        goto LABEL_351;
    }
    if ((~v189->stat & 0x41) == 0)
    {
      party = v181->data->party;
      nbMakeReturnPacket(0, v181->uniqueid, &party->m_Items[v189->partyindex]);
      nbAddHitEffKoukaPacket(0, (*a)->uniqueid, &form, 5, 0);
    }
LABEL_350:
    v181 = *a;
    ++v186;
  }
  while (v186 != 16);
LABEL_351:
  if (!v181->runerr)
  {
    if ((v181->party->flag & 2) != 0)
    {
      v201 = v181->data->form;
      if ((v201->m_Items[0]->stat & 1) != 0)
      {
        v203 = (*a)->data->form;
        if ((v203->m_Items[0]->stat & 0x40) != 0)
        {
          v205 = (*a)->data->form;
          if ((v205->m_Items[0]->stat & 8) != 0)
            nbSetHojoAddCounter(0, 16, 1, 0);
        }
      }
      v207 = (*a)->data->form;
      if ((v207->m_Items[1]->stat & 1) != 0)
      {
        v209 = (*a)->data->form;
        if ((v209->m_Items[1]->stat & 0x40) != 0)
        {
          v211 = (*a)->data->form;
          if ((v211->m_Items[1]->stat & 8) != 0)
            nbSetHojoAddCounter(1, 16, 1, 0);
        }
      }
      v213 = (*a)->data->form;
      if ((v213->m_Items[2]->stat & 1) != 0)
      {
        v215 = (*a)->data->form;
        if ((v215->m_Items[2]->stat & 0x40) != 0)
        {
          v217 = (*a)->data->form;
          if ((v217->m_Items[2]->stat & 8) != 0)
            nbSetHojoAddCounter(2, 16, 1, 0);
        }
      }
      v219 = (*a)->data->form;
      if ((v219->m_Items[3]->stat & 1) != 0)
      {
        v221 = (*a)->data->form;
        if ((v221->m_Items[3]->stat & 0x40) != 0)
        {
          v223 = (*a)->data->form;
          if ((v223->m_Items[3]->stat & 8) != 0)
            nbSetHojoAddCounter(3, 16, 1, 0);
        }
      }
    }
    else
    {
      for (i = 8; ; ++i)
      {
        v194 = v181->data->form;
        v195 = i - 4;
        if ((*(*(&v194->obj.klass + i) + 136LL) & 1) != 0)
        {
          v197 = (*a)->data->form;
          if ((*(*(&v197->obj.klass + i) + 136LL) & 0x40) != 0)
          {
            v199 = (*a)->data->form;
            if ((*(*(&v199->obj.klass + i) + 136LL) & 8) != 0)
              nbSetHojoAddCounter(i - 4, 16, 1, 0);
          }
        }
        if (i == 17)
          break;
        v181 = *a;
      }
    }
  }
  if (((*a)->stat & 0x400) == 0)
  {
    nbPanelAllShow();
  }
  nbPanelPressGaugeShow();
  v226 = *a;
  v227 = (*a)->work;
  v228 = v227->nowcommand;
  if (v228 != 3)
    goto LABEL_422;
  if ((v226->data->stat & 8) != 0)
  {
    nbCameraSetState(0x19u);
    v226 = *a;
    v227 = (*a)->work;
    LOWORD(v228) = v227->nowcommand;
LABEL_422:
    v229 = v228;
    switch (v228)
    {
      case 0:
        v231 = nbHatudoCheckSkill(v227, 304);
        v233 = (*a)->work;
        if (!v231)
          goto LABEL_473;
        if ((v233->badstatus & 0x80) != 0)
        {
          v243 = v233->nowcommand;
          nbDispMiscActionNameComm(v243);
          if (((*a)->work->badstatus & 0x80000000) == 0)
            return;
        }
        else
        {
          nbDispSkillName(304);
          if (((*a)->work->badstatus & 0x80000000) == 0)
            return;
        }
        TargetFormation = effBTLSkillGetTargetFormation(0);
        if (nbCheckFormationPlayerSide(TargetFormation->formindex))
        {
          v233 = (*a)->work;
          goto LABEL_473;
        }
        v236 = 304;
LABEL_498:
        nbDispSkillName(v236);
        return;
      case 1:
        switch (v227->id)
        {
          case 0x159u:
            v235 = v227->nowindex;
            if (v235 != 226)
              goto LABEL_493;
            v236 = 499;
            goto LABEL_498;
          case 0x15Au:
            v235 = v227->nowindex;
            if (v235 != 226)
              goto LABEL_493;
            v236 = 496;
            goto LABEL_498;
          case 0x15Bu:
            v235 = v227->nowindex;
            if (v235 != 226)
              goto LABEL_493;
            v236 = 497;
            goto LABEL_498;
          case 0x15Cu:
            v235 = v227->nowindex;
            if (v235 != 226)
              goto LABEL_493;
            v236 = 498;
            goto LABEL_498;
          default:
            v235 = v227->nowindex;
LABEL_493:
            if (v235 == 247)
              return;
              goto LABEL_495;
            goto LABEL_497;
        }
      case 2:
        v230 = 2;
        goto LABEL_427;
      case 3:
      case 6:
        goto LABEL_423;
      case 4:
        if (v226->negotype)
          return;
        v235 = v227->nowindex;
        {
LABEL_495:
        }
LABEL_497:
        v236 = v235;
        goto LABEL_498;
      case 5:
        v238 = v227->nowindex;
        nbDispItemName(v238);
        return;
      case 7:
        v239 = nbCheckFormationPlayerSide(v226->form->formindex);
        v240 = (*a)->stat;
        v233 = (*a)->work;
        if (v239)
        {
          if ((v240 & 0x20) == 0)
          {
LABEL_473:
            v245 = v233->nowcommand;
            v230 = v245;
            goto LABEL_427;
          }
          id = v233->id;
          v242 = 50;
        }
        else
        {
          id = v233->id;
          if ((v240 & 0x20) != 0)
          {
            v242 = 52;
          }
          else
          {
            v242 = 10;
          }
        }
        nbSetJyokyoMes(a, v242, 1, id);
        return;
      default:
        return;
    }
  }
  v229 = 3;
LABEL_423:
  v230 = v229;
LABEL_427:
  nbDispMiscActionNameComm(v230);
}

// 0xf3f610
void SetAction_RETURN(nbActionProcessData_t **a) {
  nbActionProcessData_t_o *v4;
  s32 formindex;

  Write("帰還します\n", 0);
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
  System_SByte_array_array *v3;
  u64 v4;
  il2cpp_array_size_t *p_max_length;
  s64 *v7;
  s64 *v10;
  nbActionProcessData_t_o *v12;
  nbActionProcessData_t_o *v13;
  f32 v14;
  effBTL_t_o **p_hEffBTL;
  f32 v16;
  s32 v17;
  s64 motcate;
  s32 CutEndFrame;
  nbFormation_t_o *form;
  u64 *v22;
  u64 *v24;
  s32 formindex;
  nbActionProcessData_t_o *v28;
  struct nbFormation_t_o *v29;
  f32 MotionSpeed;
  s32 MotionActframe;
  struct nbFormation_t_o *v34;
  int16x4_t v35;
  s32 v36;
  s32 v37;
  struct datUnitWork_t_o *work;
  s32 nowcommand;
  s16 v40;
  s32 nowindex;
  s32 v42;
  s32 ItemSkillNo;
  u64 v46;
  s32 v47;
  System_SByte_array **v49;
  struct nbTimeList_t_array *timelist;
  s64 v54;
  Il2CppClass **v56;
  s32 lockframe;
  struct nbTimeList_t_array *v58;
  s64 v61;
  s32 v65;
  u64 *v67;
  nbActionProcessData_t_o *v69;
  effBTL_t_o **v70;
  u32 v71;
  u32 v72;
  s32 v73;
  u64 *v74;
  u64 *v76;
  s32 v81;
  s32 v82;
  struct nbFormation_t_array *v83;
  s64 v86;
  s32 v88;
  Il2CppClass **v89;
  nbFormation_t_o **v90;
  s32 v91;
  u32 v92;
  bool v93;
  s64 v94;
  s32 v97;
  s32 v101;
  s32 v102;
  s32 v103;
  s32 v104;
  s32 v106;
  s32 v107;
  s32 v108;
  s32 v114;
  s32 v116;
  s32 v120;
  s32 v121;
  s32 v123;
  s32 v126;
  s32 v130;
  s32 v137;
  s32 v139;
  s32 v143;
  s32 v152;
  s32 v155;
  struct nbTimeList_t_array *v156;
  s32 v158;
  struct nbFormation_t_array *v159;
  s64 v162;
  s32 v165;
  f32 GensyoRitu;
  f32 v171;
  struct datNormalSkill_t_array *tbl;
  s32 v176;
  s32 v177;
  s32 v186;
  s32 v187;
  u32 v198;
  s32 v199;
  s32 v200;
  bool v210;
  bool v211;
  nbActionProcessData_t_o *v212;
  s32 v213;
  struct nbTimeList_t_array *v214;
  s32 v216;
  s64 j;
  struct nbTimeList_t_array *v218;
  struct nbTimeList_t_array *v219;
  s32 allhpdamage;
  struct datSpecialSkill_t_array *v224;
  s32 v226;
  s32 v227;
  s32 v228;
  s32 v229;
  bool v230;
  nbActionProcessData_t_o *v233;
  u32 v234;
  struct nbTimeList_t_array *v235;
  u32 max_length;
  nbActionProcessData_t_o *v237;
  s32 v238;
  struct nbTimeList_t_array *v239;
  s64 i;
  struct nbTimeList_t_array *v242;
  s64 v244;
  struct nbTimeList_t_array *v245;
  s32 maxhp;
  struct datNormalSkill_t_array *v249;
  s32 v251;
  s32 v252;
  nbActionProcessData_t_o *v253;
  u32 v254;
  struct nbTimeList_t_array *v255;
  s32 v257;
  nbTimeList_t_o *v258;
  s32 v260;
  nbTimeList_t_o *v262;
  s32 v263;
  nbActionProcessData_t_o *v264;
  s32 v265;
  struct nbTimeList_t_array *v266;
  s32 v268;
  s64 k;
  struct nbTimeList_t_array *v270;
  struct nbTimeList_t_array *v271;
  s32 maxmp;
  struct datNormalSkill_t_array *v276;
  s32 v278;
  char v279;
  s32 v282;
  s32 v284;
  s32 v285;
  s64 m;
  struct nbTimeList_t_array *v287;
  struct nbTimeList_t_array *v288;
  s32 v291;
  struct nbFormation_t_o *v292;
  struct nbTimeList_t_array *v293;
  u32 v294;
  s64 v295;
  struct nbTimeList_t_array *v297;
  struct nbTimeList_t_array *v299;
  s64 v300;
  s32 v304;
  nbActionProcessData_t_o *v306;
  s32 v307;
  struct nbTimeList_t_array *v308;
  u64 *v310;
  u64 *v312;
  u64 *v313;
  s32 v315;
  s64 n;
  struct nbTimeList_t_array *v317;
  struct nbTimeList_t_array *v318;
  u64 *v321;
  s32 v324;
  s32 v325;
  nbActionProcessData_t_o *v326;
  s32 v327;
  s32 v328;
  s32 v329;
  s32 v332;
  s32 v334;
  nbActionProcessData_t_o **v335;
  s32 v336;
  u64 v337;
  nbActionProcessData_t_o *v339;
  s32 jyokyomes;
  nbActionProcessData_t_o *v341;
  u64 *v343;
  nbActionProcessData_t_o *v344;
  s32 newaddpresstype;
  int16x4_t v346;
  nbActionProcessData_t_o *v347;
  struct nbMainProcessData_t_o *data;
  s64 v349;
  s32 uniqueid;
  s32 v351;
  s64 v352;
  System_SByte_array **m_Items;
  s32 v354;
  u32 state;
  s32 nskill;
  s32 v357;
  s32 v358;
  s64 v359;
  s32 v360;
  s32 v361;
  s32 startframe;
  s32 v363;
  s32 v364;
  s32 allmpdamage;
  f32 press;
  effBTLCutHandle_t_o *v367;
  effBTLCutHandle_t_o *hBTLCutEffect;

  v367 = 0;
  hBTLCutEffect = 0;
  v3 = NewSpecific(sbyte__, 0x20u);
  v4 = 0;
  p_max_length = &v3->max_length;
  do
  {
    v7 = NewSpecific(sbyte, 2u);
    v10 = v7;
    v3->m_Items[v4++] = v10;
  }
  while (v4 != 32);
  v12 = *a;
  v12->newpresstype = 0;
  uniqueid = v12->uniqueid;
  (*a)->data->d31_kantuu = 0;
  v13 = *a;
  v14 = 1.0;
  p_hEffBTL = &(*a)->hEffBTL;
  if (((*a)->stat & 0x100) != 0)
    v16 = 3.0;
  else
    v16 = 1.0;
  if ((*a)->hEffBTL && !v13->runerr)
  {
    form = v13->form;
    hBTLCutEffect = effBTLCutCreate(p_hEffBTL, 1u, form, 1u);
    press = COERCE_FLOAT(effBTLCutGetMotionChangeFrame(&hBTLCutEffect));
    CutEndFrame = effBTLCutGetCutEndFrame(&hBTLCutEffect);
    v22 = sub_8D3950(s32, &press);
    allmpdamage = CutEndFrame;
    v24 = sub_8D3950(s32, &allmpdamage);
    Write_2930752("mot {0:D}, cut {1:D}\n", v22, v24, 0);
    formindex = (*a)->form->formindex;
    SetTimeList(a, formindex, 0, CutEndFrame, CutEndFrame);
  }
  else
  {
    v17 = v13->form->formindex;
    SetTimeList(a, v17, 0, (10.0 / v16), (10.0 / v16));
    CutEndFrame = 0;
  }
  v28 = *a;
  v29 = (*a)->form;
  if (v29->motendtype == 2)
  {
    motcate = v29->motcate;
    if ((motcate & 0x80000000) == 0 && (v29->motenddata & 0x80000000) == 0)
    {
      MotionSpeed = nbGetMotionSpeed(&(*a)->form, motcate, v16, 0);
      MotionActframe = nbGetMotionActframe(&(*a)->form, (*a)->form->motcate, v16, 0);
      v34 = (*a)->form;
      v35.n64_u16[0] = v34->motenddata;
      v36 = v34->formindex;
      v37 = (vmovl_s16(v35).n128_i32[0] / MotionSpeed) - MotionActframe;
      OverwriteTimeList(a, v36, 0, v37 + (10.0 / v16), v37 + (10.0 / v16));
      v28 = *a;
    }
  }
  work = v28->work;
  nowcommand = work->nowcommand;
  v40 = work->nowcommand;
  switch (nowcommand)
  {
    case 1:
      nowindex = work->nowindex;
      break;
    case 5:
      v42 = work->nowindex;
      ItemSkillNo = nbGetItemSkillNo(v28, v42);
      v40 = (*a)->work->nowcommand;
      nowindex = ItemSkillNo;
      break;
    case 6:
      nowindex = 255;
      break;
    default:
      nowindex = 0;
      break;
  }
  SetNowActionStat(a, v40, nowindex);
  GetKoukaList(a, v3, (*a)->select, nowindex);
  v352 = nowindex;
  m_Items = v3->m_Items;
  v354 = 1;
  state = 0;
  v46 = 0;
  v47 = CutEndFrame;
  v351 = 0;
  v359 = 0;
  v358 = 0;
  v360 = 1;
  v361 = 1;
  nskill = nowindex;
  while (2)
  {
    v49 = &m_Items[v46];
    if ((*v49)->m_Items[0] < 0)
    {
      startframe = v47;
      break;
    }
    timelist = (*a)->timelist;
    v54 = (*v49)->m_Items[0];
    v56 = &timelist->obj.klass + v54;
    lockframe = CutEndFrame;
    if (CutEndFrame < LOWORD(v56[4]->_1.name))
    {
      v58 = (*a)->timelist;
      v61 = (*v49)->m_Items[0];
      lockframe = v58->m_Items[v61]->lockframe;
    }
    press = COERCE_FLOAT(nbGetKoukaType(nowindex, (*a)->form->formindex, (*v49)->m_Items[0], 0));
    v65 = LODWORD(press);
    v67 = sub_8D3950(s32, &press);
    v357 = CutEndFrame;
    Write_2930400("スキル効果タイプ = {0:D}\n", v67);
    v69 = *a;
    if ((*a)->type == 4 && (v65 - 1) < 2)
      v65 = 3;
    v70 = &v69->hEffBTL;
    v71 = 0;
    if (v46 <= 0xF && v69->hEffBTL)
    {
      if (v65 && (v65 - 3) > 0xB)
      {
        v71 = 0;
      }
      else
      {
        v71 = effBTLGetMotionChangeFrame(v70, 2u);
        v72 = effBTLGetCutEndFrame(&(*a)->hEffBTL, 2u, 0);
        press = *&v71;
        v73 = v72;
        v74 = sub_8D3950(s32, &press);
        v351 = v73;
        allmpdamage = v73;
        v76 = sub_8D3950(s32, &allmpdamage);
        Write_2930752("cut3 mottime:{0:D}  endtime:{1:D}\n", v74, v76);
        v81 = (*v49)->m_Items[0];
        SetTimeList(a, v81, lockframe, 0, v73 + 1);
        v69 = *a;
      }
    }
    v82 = v69->uniqueid;
    v83 = v69->data->form;
    startframe = v71 + lockframe;
    v86 = (*v49)->m_Items[0];
    v88 = v359;
    if (!v65)
      v88 = 1;
    LODWORD(v359) = v88;
    v89 = &v83->obj.klass + v86;
    v47 = v71 + lockframe;
    v90 = (v89 + 4);
    v91 = v358;
    v92 = v65 & 0xFFFFFFFE;
    if (v65)
      v93 = v92 == 2;
    else
      v93 = 1;
    if (v93)
      v91 = 1;
    v358 = v91;
    nbAddFormFlagOnOffPacket(startframe, v82, v90, 0, 0x2000u);
    v101 = v360;
    if ((v65 - 1) >= 2)
      v101 = 0;
    v360 = v101;
    if (v65 == 2)
      v102 = v361;
    else
      v102 = 0;
    v361 = v102;
    nowindex = nskill;
    switch (v65)
    {
      case 0:
      case 1:
      case 2:
      case 3:
        v103 = (*a)->form->formindex;
        v104 = (*v49)->m_Items[0];
        v106 = (*v49)->m_Items[1];
        v107 = v106;
        v47 = startframe;
        v108 = v103;
        nowindex = nskill;
        SetAllPacket(a, v65, nskill, v108, v104, v107, startframe, v14);
        if (!v65)
          goto LABEL_127;
        break;
      case 4:
        v114 = (*v49)->m_Items[0];
        SetSakePacket(a, nskill, v114, v97, startframe);
        if (!v65)
          goto LABEL_127;
        break;
      case 5:
        v116 = (*v49)->m_Items[0];
        SetMissPacket(a, v94, v116, v97, startframe);
        if (!v65)
          goto LABEL_127;
        break;
      case 6:
        v120 = (*v49)->m_Items[0];
        v121 = SetPlayerSummonPacket(a, v94, v120, startframe);
        v123 = v354;
        if (!v121)
          v123 = 0;
        v354 = v123;
        Write("summon!!\n", 0);
        if (!v65)
          goto LABEL_127;
        break;
      case 7:
        v126 = (*v49)->m_Items[0];
        SetAnalyzePacket(a, v126, startframe);
        Write("analyze!!\n", 0);
        if (!v65)
          goto LABEL_127;
        break;
      case 8:
        v130 = (*v49)->m_Items[0];
        SetTorafuPacket(a, v130, startframe);
        Write("escape!!\n", 0);
        if (!v65)
          goto LABEL_127;
        break;
      case 9:
        SetMakaPacket(a, v94, startframe);
        Write("maka!!\n", 0);
        if (!v65)
          goto LABEL_127;
        break;
      case 10:
        v137 = (*v49)->m_Items[0];
        SetEnemyEscapePacket(a, v137, startframe);
        Write("enemy escape!!\n", 0);
        if (!v65)
          goto LABEL_127;
        break;
      case 11:
        v139 = (*v49)->m_Items[0];
        SetOngShadowPacket(a, v94, v139, v97, startframe);
        if (!v65)
          goto LABEL_127;
        break;
      case 12:
        v143 = (*v49)->m_Items[0];
        SetAuroraPacket(a, v143);
        Write("aurora !!\n", 0);
        if (!v65)
          goto LABEL_127;
        break;
      case 13:
        SetAddPressPacket(a, nskill);
        Write("press kaifuku !!\n", 0);
        if (!v65)
          goto LABEL_127;
        break;
      case 14:
        nbAddFlareChargePacket(startframe, (*a)->uniqueid, 2, 0);
        Write("flare charge !!\n", 0);
        if (!v65)
          goto LABEL_127;
        break;
      default:
        nowindex = nskill;
        if (!v65)
        {
LABEL_127:
          if (((*a)->data->stat & 0x400) != 0)
          {
            if ((*v49)->m_Items[0] >= 4)
            {
              if ((*v49)->m_Items[0] <= 13 && nbGetNormalSkillAttr(nowindex) != 14)
              {
                v152 = (*v49)->m_Items[0];
                SetOngShadowPacket2(a, v152, v47 + 5);
              }
            }
          }
        }
        break;
    }
    if (v354 && v46 <= 0xF && (*a)->hEffBTL && (!v65 || (v65 - 3) <= 0xB && (nowindex != 263 || v65 != 3)))
    {
      v155 = (*v49)->m_Items[0];
      v156 = (*a)->timelist;
      if (v156->m_Items[v155]->hp || (nbGetDevilFormatFlag(v155) & 0x100) != 0)
      {
        if (v92 == 4)
          v158 = 32;
        else
          v158 = 1;
      }
      else
      {
        v158 = 3;
      }
      v159 = (*a)->data->form;
      v162 = (*v49)->m_Items[0];
      nbAddSkillEffectKoukaPacket2(
        lockframe,
        v351,
        uniqueid,
        &(*a)->hEffBTL,
        2,
        &v159->m_Items[v162],
        v158,
        0);
      nowindex = nskill;
      v165 = MAKE_SKILL_SE01(nskill);
      v47 = startframe;
      if ((v165 & 0x80000000) == 0)
        nbAddSePacket(lockframe, uniqueid, v165);
    }
    GensyoRitu = nbGetGensyoRitu(nowindex, (*a)->form->formindex, (*v49)->m_Items[0], 0);
    v171 = GensyoRitu;
    CutEndFrame = v357;
    if (tbl->m_Items[v352]->koukatype)
    {
      if (v65 != 3)
        goto LABEL_340;
    }
    else
    {
      nbSetHojoCounter((*a)->form->formindex, 15, 0, 0);
      if (v65 != 3)
        goto LABEL_340;
    }
    switch (nbGetNormalSkillAttr(nowindex))
    {
      case 1:
        v176 = (*v49)->m_Items[0];
        v177 = 10;
        goto LABEL_339;
      case 2:
        v176 = (*v49)->m_Items[0];
        v177 = 9;
        goto LABEL_339;
      case 6:
        v176 = (*v49)->m_Items[0];
        v177 = 12;
        goto LABEL_339;
      case 7:
        v176 = (*v49)->m_Items[0];
        v177 = 11;
LABEL_339:
        nbSetHojoCounter(v176, v177, 0);
        break;
      default:
        break;
    }
LABEL_340:
    if ((nowindex - 259) >= 2)
    {
      if (nowindex != 272 || evtBitCheck(3712))
        goto LABEL_374;
      if (cfgGetBit(9u) != 2)
        goto LABEL_374;
      nbSetHojoCounter((*v49)->m_Items[0], 4, 0, 0);
      nbSetHojoCounter((*v49)->m_Items[0], 5, 0, 0);
      nbSetHojoCounter((*v49)->m_Items[0], 6, 0, 0);
      nbSetHojoCounter((*v49)->m_Items[0], 7, 0, 0);
      v186 = (*v49)->m_Items[0];
      v187 = 8;
    }
    else
    {
      v186 = (*v49)->m_Items[0];
      v187 = 11;
    }
    nbSetHojoCounter(v186, v187, 0);
LABEL_374:
    v198 = v65 - 1;
    if (v65 == 1)
      nbAddHatudoEffectEndPacket(v47, (*a)->uniqueid, 0);
    switch (Get(nowindex, 0)->animetype)
    {
      case 1u:
      case 5u:
      case 9u:
      case 0xDu:
        CutEndFrame = v357 + 5;
        goto LABEL_381;
      case 2u:
      case 6u:
      case 0xAu:
      case 0xEu:
        CutEndFrame = v357 + 8;
        if (v198 > 4)
          goto LABEL_394;
        goto LABEL_381;
      case 3u:
      case 7u:
      case 0xBu:
      case 0xFu:
        CutEndFrame = v357 + 10;
        if (v198 > 4)
          goto LABEL_394;
        goto LABEL_381;
      case 4u:
      case 8u:
      case 0xCu:
        CutEndFrame = v357 + 1;
        if (v198 > 4)
          goto LABEL_394;
        goto LABEL_381;
      default:
LABEL_381:
        switch (v65)
        {
          case 1:
            v199 = state | 4;
            goto LABEL_393;
          case 2:
            v199 = state | 8;
            goto LABEL_393;
          case 3:
            v199 = state | 0x10;
            goto LABEL_393;
          case 4:
            v199 = state | 0x20;
            goto LABEL_393;
          case 5:
            v199 = state | 0x40;
LABEL_393:
            state = v199;
            break;
          default:
            break;
        }
LABEL_394:
        v14 = v14 * v171;
        v200 = HIDWORD(v359);
        if ((v65 - 1) > 1)
          v200 = 1;
        v230 = v46++ > 0x1E;
        HIDWORD(v359) = v200;
        if (!v230)
          continue;
        LODWORD(v46) = 1;
        break;
    }
    break;
  }
  v210 = nowindex == 264;
  v211 = (nowindex & 0xFFFFFFFE) == 262;
  if (nowindex == 286)
  {
    v237 = *a;
    if ((*a)->autoskill)
      goto LABEL_531;
    v238 = v237->form->formindex;
    v239 = v237->timelist;
    if (!v239->m_Items[v238]->hp && (nbGetDevilFormatFlag(v238) & 0x100) == 0 || (*a)->runerr)
      goto LABEL_531;
    (*a)->autoskill = 302;
    v216 = 0;
    for (i = 4; i != 36; ++i)
    {
      v242 = (*a)->timelist;
      v244 = *(&v242->obj.klass + i);
      v227 = nskill;
      if (v216 < *(v244 + 18))
      {
        v245 = (*a)->timelist;
        v216 = *(*(&v245->obj.klass + i) + 18LL);
      }
    }
    (*a)->autoskill = 0;
    maxhp = (*a)->work->maxhp;
    v249 = tbl;
    v251 = v249->m_Items[v352]->hojopoint * maxhp;
    if ((v251 + 99) >= 0xC7)
    {
      v252 = v251 / 100;
      if (v251 / 100 >= 1)
      {
        nbMakeKaifukuPacket(v216, (*a)->uniqueid, &(*a)->form, 0, v252, -1, 0, 0);
        v253 = *a;
        v254 = (*a)->form->formindex;
        if ((v253->data->stat & 0x20000) == 0)
        {
          v255 = v253->timelist;
          v257 = v252 + v255->m_Items[v254]->hp;
          v258 = v255->m_Items[v254];
          v227 = nskill;
          v258->hp = v257 & ~(v257 >> 31);
        }
        goto LABEL_497;
      }
    }
  }
  else
  {
    if (nowindex == 265)
      goto LABEL_502;
    if (nowindex || (*a)->autoskill || !nbHatudoCheckSkill((*a)->work, 302, 0))
      goto LABEL_531;
    v212 = *a;
    v213 = (*a)->form->formindex;
    v214 = v212->timelist;
    if (!v214->m_Items[v213]->hp && (nbGetDevilFormatFlag(v213) & 0x100) == 0)
    {
LABEL_531:
      v279 = 0;
      goto LABEL_538;
    }
    (*a)->autoskill = 302;
    v216 = 0;
    for (j = 4; j != 36; ++j)
    {
      while (1)
      {
        v218 = (*a)->timelist;
        if (v216 < *(*(&v218->obj.klass + j) + 18LL))
          break;
        if (++j == 36)
          goto LABEL_433;
      }
      v219 = (*a)->timelist;
      v216 = *(*(&v219->obj.klass + j) + 18LL);
    }
LABEL_433:
    allhpdamage = (*a)->allhpdamage;
    v224 = tbl;
    v226 = allhpdamage / v224->m_Items[14]->n;
    v227 = nskill;
    if (v226)
      v228 = v226;
    else
      v228 = -1;
    if ((*a)->allmpdamage / tbl->m_Items[14]->m)
      v229 = (*a)->allmpdamage / tbl->m_Items[14]->m;
    else
      v229 = -1;
    v230 = v228 <= 0 && v229 < 1;
    if (!v230)
    {
      nbMakeKaifukuPacket(v216, (*a)->uniqueid, &(*a)->form, 3, v228, v229, 0, 0);
      if (v228 >= 1)
      {
        v233 = *a;
        v234 = (*a)->form->formindex;
        if ((v233->data->stat & 0x20000) == 0)
        {
          v235 = v233->timelist;
          max_length = v235->max_length;
          v260 = v228 + v235->m_Items[v234]->hp;
          v262 = v235->m_Items[v234];
          v227 = nskill;
          if (v260 < 0)
            v262->hp = 0;
          else
            v262->hp = v260;
        }
      }
LABEL_497:
      v263 = (*a)->form->formindex;
      SetTimeList(a, v263, v216, (20.0 / v16), (20.0 / v16));
    }
  }
  if (v227 != 265)
    goto LABEL_531;
LABEL_502:
  v264 = *a;
  if (!(*a)->autoskill)
  {
    v265 = v264->form->formindex;
    v266 = v264->timelist;
    if ((v266->m_Items[v265]->hp || (nbGetDevilFormatFlag(v265) & 0x100) != 0)
      && !(*a)->runerr)
    {
      (*a)->autoskill = 302;
      v268 = 0;
      for (k = 4; k != 36; ++k)
      {
        while (1)
        {
          v270 = (*a)->timelist;
          if (v268 < *(*(&v270->obj.klass + k) + 18LL))
            break;
          if (++k == 36)
            goto LABEL_523;
        }
        v271 = (*a)->timelist;
        v268 = *(*(&v271->obj.klass + k) + 18LL);
      }
LABEL_523:
      (*a)->autoskill = 0;
      maxmp = (*a)->work->maxmp;
      v276 = tbl;
      v278 = v276->m_Items[265]->mpn * maxmp;
      if ((v278 + 99) >= 0xC7 && v278 / 100 >= 1)
      {
        nbMakeKaifukuPacket(v268, (*a)->uniqueid, &(*a)->form, 0, -1, v278 / 100, 0, 0);
        v282 = (*a)->form->formindex;
        SetTimeList(a, v282, v268, (20.0 / v16), (20.0 / v16));
      }
    }
  }
  v279 = 1;
LABEL_538:
  effBTLSkillSetState(state);
  v284 = 0;
  v285 = v211 && v361 != 0 || v210 && v360 != 0;
  for (m = 4; m != 36; ++m)
  {
    while (1)
    {
      v287 = (*a)->timelist;
      if (v284 < *(*(&v287->obj.klass + m) + 18LL))
        break;
      if (++m == 36)
        goto LABEL_553;
    }
    v288 = (*a)->timelist;
    v284 = *(*(&v288->obj.klass + m) + 18LL);
  }
LABEL_553:
  v291 = (v284 * 0.8);
  if ((v291 & 0x80000000) == 0)
  {
    v292 = (*a)->form;
    v293 = (*a)->timelist;
    v294 = v292->formindex;
    v295 = v292->formindex;
    if (v291 > v293->m_Items[v295]->lockframe)
    {
      v297 = (*a)->timelist;
      v297->m_Items[v295]->lockframe = v291;
    }
  }
  v299 = (*a)->timelist;
  v300 = (*a)->form->formindex;
  if (!v299->m_Items[v300]->hp
    && (nbGetDevilFormatFlag(v300) & 0x100) == 0
    && ((*a)->party->flag & 0x20) == 0)
  {
    nbMakeDeadVisualPacket(startframe, (*a)->uniqueid, &(*a)->form, 0, 1, 0);
    v304 = (*a)->form->formindex;
    SetTimeList(a, v304, startframe, 30, 30);
    SetDeadPacket(a, (*a)->form->formindex);
  }
  v306 = *a;
  v307 = (*a)->form->formindex;
  v308 = v306->timelist;
  if ((v308->m_Items[v307]->hp || (nbGetDevilFormatFlag(v307) & 0x100) != 0) && !(*a)->type)
  {
    CheckArrCounter(a);
  }
  press = *&(*a)->allhpdamage;
  v310 = sub_8D3950(s32, &press);
  allmpdamage = (*a)->allmpdamage;
  v312 = sub_8D3950(s32, &allmpdamage);
  Write_2930752("トータルダメージ HP={0:D}, MP={1:D}\n", v310, v312, 0);
  v364 = v284;
  v313 = sub_8D3950(s32, &v364);
  Write_2930400("skill kouka end time = {0:D}\n", v313);
  v315 = 0;
  for (n = 4; n != 36; ++n)
  {
    while (1)
    {
      v317 = (*a)->timelist;
      if (v315 < *(*(&v317->obj.klass + n) + 16LL))
        break;
      if (++n == 36)
        goto LABEL_596;
    }
    v318 = (*a)->timelist;
    v315 = *(*(&v318->obj.klass + n) + 16LL);
  }
LABEL_596:
  v363 = v315;
  v321 = sub_8D3950(s32, &v363);
  Write_2930400("skill kouka unlock time = {0:D}\n", v321);
  v324 = startframe;
  if (!(*a)->runerr)
  {
    switch ((*a)->autoskill)
    {
      case 0x12B:
        v325 = 299;
        goto LABEL_614;
      case 0x12C:
        v325 = 300;
        goto LABEL_614;
      case 0x12D:
        v325 = 301;
        goto LABEL_614;
      case 0x12E:
        v325 = 302;
LABEL_614:
        nbDispSkillName(v325);
        break;
      default:
        break;
    }
  }
  if ((*a)->runerr)
    goto LABEL_616;
  v332 = nskill;
  if (nskill <= 206)
  {
    switch (nskill)
    {
      case 52:
        v335 = a;
        v336 = 16;
        goto LABEL_732;
      case 53:
        v336 = 20;
        goto LABEL_731;
      case 54:
        v336 = 18;
        goto LABEL_731;
      case 57:
LABEL_675:
        v336 = 22;
        goto LABEL_731;
      case 64:
        v335 = a;
        v336 = 24;
        goto LABEL_732;
      case 65:
        v336 = 26;
        goto LABEL_731;
      case 66:
        v335 = a;
        v336 = 28;
        goto LABEL_732;
      case 67:
        v335 = a;
        v336 = 30;
        goto LABEL_732;
      case 68:
        v335 = a;
        v336 = 32;
        goto LABEL_732;
      case 69:
        v336 = 36;
        goto LABEL_731;
      case 70:
        v336 = 34;
        goto LABEL_731;
      case 77:
LABEL_660:
        v336 = 92;
        goto LABEL_731;
      case 203:
        v336 = 80;
        goto LABEL_731;
      case 204:
        v336 = 82;
        goto LABEL_731;
      case 205:
        v336 = 84;
        goto LABEL_731;
      case 206:
        v336 = 86;
        goto LABEL_731;
      default:
LABEL_664:
        if (!v359 || !(*a)->data->d31_kantuu)
          break;
        v336 = 100;
LABEL_731:
        v335 = a;
LABEL_732:
        nbSetJyokyoMes(v335, v336, -1, 0);
        break;
    }
  }
  else if ((v279 & 1) != 0)
  {
    nbSetJyokyoMes(a, 84, -1, 0);
    v332 = nskill;
  }
  else
  {
    v332 = nskill;
    HIDWORD(v337) = nskill - 272;
    LODWORD(v337) = nskill - 272;
    switch ((v337 >> 1))
    {
      case 0u:
        v335 = a;
        v336 = 96;
        goto LABEL_732;
      case 1u:
        goto LABEL_660;
      case 2u:
        v336 = 98;
        goto LABEL_731;
      case 5u:
        if (v358)
          goto LABEL_675;
        break;
      default:
        goto LABEL_664;
    }
  }
  if (nbCheckBattleSkillError3(v332, (*a)->select, 0))
  {
    Write("Kereijyou Koukaga nai ---------------------\n", 0);
    nbSetJyokyoMes(a, 68, -1, 0);
  }
  v339 = *a;
  jyokyomes = (*a)->jyokyomes;
  if (jyokyomes < 1 || (v339->stat & 0x20) == 0)
  {
LABEL_616:
    v326 = *a;
    v327 = (*a)->jyokyomes;
    if (v327 < 1)
      goto LABEL_747;
    goto LABEL_617;
  }
  if ((jyokyomes & 1) != 0)
  {
    v339->jyokyomes = jyokyomes - 1;
    v326 = *a;
    v327 = (*a)->jyokyomes;
    if (v327 < 1)
      goto LABEL_747;
LABEL_617:
    v328 = nskill;
    if ((nskill - 49) <= 1)
    {
      v329 = v326->form->formindex;
      v324 = startframe + 20;
      SetTimeList(a, v329, v324, 40, 40);
      v326 = *a;
      v327 = (*a)->jyokyomes;
    }
    nbAddJyokyoHelpPacket(v324, v326->uniqueid, v327, v326->jyo_varid, v326->jyo_varind);
    (*a)->jyokyomes = 0;
    if (!hBTLCutEffect)
      goto LABEL_748;
    goto LABEL_623;
  }
  v339->jyokyomes = jyokyomes + 1;
  v326 = *a;
  v327 = (*a)->jyokyomes;
  if (v327 >= 1)
    goto LABEL_617;
LABEL_747:
  v328 = nskill;
  if (!hBTLCutEffect)
  {
LABEL_748:
    nbAddSkillColorOffPacket(v284, uniqueid);
    goto LABEL_749;
  }
LABEL_623:
  effBTLCutSetDrawEndFrame(&hBTLCutEffect, v284);
  nbAddSkillColorOffPacket(v284, uniqueid);
  if (!HIDWORD(v359) && ((v285 ^ 1) & 1) != 0)
  {
    v367 = hBTLCutEffect;
    effBTLCutSetCameraState(&v367);
    goto LABEL_749;
  }
  nbAddSkillEffectKoukaPacket(0, v284, uniqueid, &hBTLCutEffect);
  if (v328 == 262 && v361)
  {
    v334 = MAKE_SKILL_SE01(262);
    if (v334 < 0)
      goto LABEL_749;
LABEL_654:
    nbAddSePacket(0, uniqueid, v334);
    goto LABEL_749;
  }
  v334 = MAKE_SKILL_SE00(v328);
  if ((v334 & 0x80000000) == 0)
    goto LABEL_654;
LABEL_749:
  v341 = *a;
  if ((*a)->form->motendtype == 1)
  {
    nbAddMotionStopClearPacket(60 * v284 / 100, v341->uniqueid, &(*a)->form, 0);
    v341 = *a;
  }
  if (!v46)
  {
    nbMakePressPacket(v324, v341->uniqueid, -1.0);
    nbMakeNewPressPacket(v324, (*a)->uniqueid, 0, &(*a)->form, 0);
LABEL_759:
    v344 = *a;
    newaddpresstype = (*a)->newaddpresstype;
    if (newaddpresstype < 1)
      goto LABEL_761;
LABEL_760:
    nbMakeNewPressPacket(v324 + 20, v344->uniqueid, newaddpresstype, &v344->form);
    v344 = *a;
    goto LABEL_761;
  }
  if (v341->type)
    goto LABEL_759;
  nbMakePressPacket(v324, v341->uniqueid, v341->press);
  nbMakeNewPressPacket(v324, (*a)->uniqueid, (*a)->newpresstype, &(*a)->form, 0);
  press = (*a)->press;
  v343 = sub_8D3950(f32, &press);
  Write_2930400("press {0:f}\n", v343);
  v344 = *a;
  newaddpresstype = (*a)->newaddpresstype;
  if (newaddpresstype >= 1)
    goto LABEL_760;
LABEL_761:
  if (v344->hitstopframe >= 1 && evtBitCheck(3081))
  {
    v347 = *a;
    data = (*a)->data;
    v349 = 42;
    if ((data->stat & 8) == 0)
      v349 = 40;
    v346.n64_u16[0] = *(&data->klass + v349);
    if (((data->press3 + (v347->press / vmovl_s16(v346).n128_i32[0])) * 100.0) <= 0)
      nbAddHitStopPacket(v347->hitstopframe, v347->uniqueid);
  }
  SetAuto(1);
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
  nbActionProcessData_t_o **v3;

  else
  {
    v3 = a;
  }
  SetTarget(v3);
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
LABEL_12:
      nbMakeNewPressPacket(0, uniqueid, v9, p_form);
      formindex = (*a)->form->formindex;
      SetTimeList(a, formindex, 0, 5, 5);
      return;
    case 8:
      nbMakePressPacket(0, v4->uniqueid, -1.0);
      uniqueid = (*a)->uniqueid;
      p_form = &(*a)->form;
      v9 = 0;
      goto LABEL_12;
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
  f32 CriticalPow;
  u32 KoukaBadDamage;
  s32 autoskill;
  s32 HitType;
  nbActionProcessData_t_o *v20;
  f32 v21;
  struct nbFormation_t_array *v22;
  s32 v24;
  s32 v25;
  s32 NormalSkillAttr;
  u32 Aisyo;
  u32 v28;
  s32 v29;
  s32 hitstopframe;
  s32 v31;
  s32 v32;
  s32 v33;
  s32 v34;
  struct nbFormation_t_array *form;
  s32 v37;
  s32 v38;
  s32 BadStatusAttr;
  s32 v40;
  struct nbMainProcessData_t_o *data;
  struct nbFormation_t_array *v42;
  struct nbParty_t_array *party;
  s64 partyindex;
  s32 v47;
  struct nbTimeList_t_array *timelist;
  struct nbTimeList_t_array *v50;
  s32 v52;
  s32 v53;
  s32 v54;
  s32 KoukaHp;
  s32 v56;
  u32 hp;
  s32 v59;
  u64 *v60;
  u64 *v62;
  s32 KoukaMp;
  s32 v64;
  s32 v65;
  u64 *v66;
  u64 *v67;
  s32 v68;
  struct nbFormation_t_array *v69;
  s32 v72;
  _BOOL4 v73;
  s32 v74;
  nbActionProcessData_t_o *v76;
  struct nbTimeList_t_array *v77;
  s32 v78;
  s32 uniqueid;
  s32 v81;
  s32 v82;
  s32 v83;
  s32 v84;
  struct datNormalSkill_t_array *tbl;
  s32 v88;
  struct nbTimeList_t_array *v89;
  s32 v91;
  nbActionProcessData_t_o *v92;
  struct nbTimeList_t_array *v93;
  struct nbTimeList_t_array *v95;
  s32 v97;
  struct nbTimeList_t_array *v98;
  f32 HpDrainRitu;
  struct nbTimeList_t_array *v102;
  s32 v104;
  struct nbTimeList_t_array *v105;
  s32 v107;
  s32 v108;
  s32 v109;
  s32 v110;
  s32 v111;
  s32 v112;
  f32 MpDrainRitu;
  s32 v114;
  bool v115;
  u32 v116;
  bool v117;
  nbActionProcessData_t_o *v118;
  s32 dead;
  s32 v120;
  struct nbFormation_t_array *v121;
  nbFormation_t_o **v123;
  struct datUnitWork_t_o *work;
  u32 attackinterval;
  u32 v129;
  nbActionProcessData_t_o *v131;
  struct nbTimeList_t_array *v132;
  struct nbTimeList_t_array *v134;
  s32 v135;
  s32 v137;
  s32 id;
  s32 v139;
  datUnitWork_t_o *UnitWorkFromFormindex;
  struct nbFormation_t_array *v142;
  f32 GensyoRitu;
  f32 v145;
  struct datNormalSkill_t_array *v147;
  s32 v150;
  s32 v151;
  s32 v152;
  s32 v153;
  s32 v154;
  s32 v155;
  nbActionProcessData_t_o *v156;
  s32 v157;
  s32 v158;
  struct nbFormation_t_array *v159;
  struct nbTimeList_t_array *v163;
  u32 max_length;
  struct nbFormation_t_array *v165;
  s32 v167;
  s32 v168;
  s32 v170;
  nbTimeList_t_o *v172;
  struct datNormalSkill_t_array *v174;
  s64 v175;
  u32 hojotype;
  s32 v178;
  struct nbFormation_t_array *v180;
  struct datNormalSkill_t_array *v181;
  s32 hojopoint;
  struct nbFormation_t_array *v187;
  s32 v188;
  s32 v189;
  s64 v190;
  struct nbTimeList_t_array *v194;
  s32 v196;
  nbTimeList_t_o *v197;
  datUnitWork_t_o *v200;
  s32 v202;
  s32 v203;
  s32 v204;
  s32 v205;
  nbActionProcessData_t_o *v208;
  s32 v209;
  nbActionProcessData_t_o *v211;
  f32 press;
  f32 v216;
  s32 formindex2;
  u32 v218;
  s32 v219;
  s64 v220;
  u32 badstat;
  s32 v222;
  s64 v223;
  s32 type[2];
  s64 v225;
  u32 v226;
  s32 v228;
  s32 v229;
  s32 v230;
  s32 v231;
  s32 v232;
  s32 deadtype;
  s64 v234;
  s32 v235;
  s32 v236;
  s32 v237;
  s32 v238;
  s32 v242;
  s32 v243[3];
  s32 v244;
  s32 v245;

  CriticalPow = nbGetAisyoRitu(nskill, sformindex, dformindex) * koukaritu;
  KoukaBadDamage = nbGetKoukaBadDamage(nskill, sformindex, dformindex, CriticalPow, 0);
  badstat = nbGetKoukaBadKaifuku(nskill, sformindex, dformindex, CriticalPow, 0);
  autoskill = (*a)->autoskill;
  HitType = nbGetHitType(*a, nskill, sformindex, dformindex);
  v218 = koukatype - 1;
  if (koukatype == 1)
    (*a)->autoskill = autoskill;
  if (HitType == 1)
    CriticalPow = nbGetCriticalPow(sformindex, CriticalPow);
  v20 = *a;
  if (((*a)->stat & 0x100) != 0)
    v21 = 3.0;
  else
    v21 = 1.0;
  formindex2 = dformindex;
  switch (koukatype)
  {
    case 3:
      hitstopframe = v20->hitstopframe;
      v31 = frame + 7;
      type[1] = HitType;
      if (hitstopframe && hitstopframe <= v31)
      {
        LODWORD(v225) = 0;
        type[0] = 0;
        KoukaBadDamage = 0;
      }
      else
      {
        KoukaBadDamage = 0;
        LODWORD(v225) = 0;
        type[0] = 0;
        v20->hitstopframe = v31;
      }
      cnt = 1;
      HIDWORD(v225) = 0x10000;
      v33 = dformindex;
      v34 = nskill;
      if (v33 > 15)
        goto LABEL_116;
      goto LABEL_109;
    case 2:
      switch (nskill)
      {
        case 264:
          v32 = frame + 90;
          break;
        case 263:
          if (evtBitCheck(3712))
            v32 = frame + 60;
          else
            v32 = frame + 120;
          break;
        case 262:
          v32 = frame + 8;
          break;
        default:
          goto LABEL_80;
      }
      frame = v32;
LABEL_80:
      if (dformindex <= 15)
      {
        form = (*a)->data->form;
        nbAddHitEffKoukaPacket(frame, (*a)->uniqueid, &form->m_Items[dformindex], 2, 0);
      }
      v37 = frame + 7;
      v38 = (*a)->hitstopframe;
      type[1] = HitType;
      if (!v38 || v38 > v37)
        (*a)->hitstopframe = v37;
      SetTimeList(a, dformindex, frame, 15, 30);
      v225 = 1;
      type[0] = 0;
      KoukaBadDamage = 0;
      frame += 13;
      cnt = 1;
      v33 = dformindex;
      v34 = nskill;
      if (v33 > 15)
        goto LABEL_116;
      goto LABEL_109;
    case 1:
      if (nskill == 275)
      {
        nbGetMainProcessData()->d31_andahansya = 1;
        if (dformindex <= 15)
          goto LABEL_21;
      }
      else
      {
        if (nskill == 264)
        {
          frame += 90;
          if (dformindex > 15)
            goto LABEL_24;
          goto LABEL_21;
        }
        if (nskill == 263)
        {
          frame += 8;
          nbGetMainProcessData()->d31_rebehansya = 1;
        }
        if (dformindex <= 15)
        {
LABEL_21:
          v22 = (*a)->data->form;
          nbAddHitEffKoukaPacket(frame, (*a)->uniqueid, &v22->m_Items[dformindex], 1, 0);
        }
      }
LABEL_24:
      v24 = frame + 7;
      v25 = (*a)->hitstopframe;
      if (!v25 || v25 > v24)
        (*a)->hitstopframe = v24;
      SetTimeList(a, dformindex, frame, 15, 30);
      NormalSkillAttr = nbGetNormalSkillAttr(nskill);
      Aisyo = nbGetAisyo(-1, sformindex, NormalSkillAttr);
      if ((Aisyo & 0x70000) != 0)
        v28 = 0;
      else
        v28 = KoukaBadDamage;
      v29 = ((Aisyo & 0x70000) != 0) << 16;
      if (v28 > 0x80)
      {
        if (v28 > 0x400)
        {
          if (v28 > 0x1000)
          {
            if (v28 != 0x4000 && v28 != 0x2000)
              goto LABEL_100;
          }
          else if (v28 != 2048 && v28 != 4096)
          {
            goto LABEL_100;
          }
        }
        else if (v28 != 256 && v28 != 512 && v28 != 1024)
        {
          goto LABEL_100;
        }
      }
      else if (v28 > 8)
      {
        if (v28 > 0x20)
        {
          if (v28 != 64 && v28 != 128)
            goto LABEL_100;
        }
        else if (v28 != 16 && v28 != 32)
        {
          goto LABEL_100;
        }
      }
      else if (((1 << v28) & 0x116) == 0)
      {
        KoukaBadDamage = v28;
        goto LABEL_100;
      }
      BadStatusAttr = datGetBadStatusAttr(v28);
      if ((nbGetAisyo(nskill, sformindex, BadStatusAttr) & 0x170000) != 0)
        KoukaBadDamage = 0;
      else
        KoukaBadDamage = v28;
LABEL_100:
      frame += 13;
      if (((*a)->data->stat & 0x400) != 0 && !nbCheckFormationPlayerSide(sformindex))
      {
        KoukaBadDamage = 0;
        v29 = 0x10000;
      }
      v34 = nskill;
      if (nskill == 212)
        v40 = 0x10000;
      else
        v40 = v29;
      LODWORD(v225) = 0;
      HIDWORD(v225) = v40;
      *type = 0;
      if (nskill == 212)
        KoukaBadDamage = 0;
      v33 = sformindex;
      cnt = 1;
      if (sformindex > 15)
        goto LABEL_116;
      goto LABEL_109;
  }
  v225 = 0;
  type[0] = 1;
  type[1] = HitType;
  v33 = dformindex;
  v34 = nskill;
  if (v33 <= 15)
  {
LABEL_109:
    data = (*a)->data;
    v42 = data->form;
    party = data->party;
    partyindex = v42->m_Items[v33]->partyindex;
    v47 = cnt;
    if ((party->m_Items[partyindex]->flag & 0x20) != 0)
      v47 = 0;
    cnt = v47;
  }
LABEL_116:
  timelist = (*a)->timelist;
  if (frame < timelist->m_Items[v33]->lockframe)
  {
    v50 = (*a)->timelist;
    frame = v50->m_Items[v33]->lockframe;
  }
  if (koukatype == 1 && (v225 & 0x1000000000000LL) == 0)
  {
    if ((*a)->form->motendtype == 2)
    {
      nbMakeUnitFadeInPacket(frame, (*a)->uniqueid, &(*a)->form, 0, 2, 4, 4, 0);
      (*a)->form->motendtype = 0;
    }
  }
  v229 = koukatype;
  v226 = sformindex;
  if (cnt < 1)
  {
    v222 = 0;
    v154 = 0;
    v150 = 0;
    v151 = 0;
    v152 = 0;
    v153 = 0;
    HIDWORD(v220) = 0;
    v219 = 0;
    goto LABEL_360;
  }
  v52 = 0;
  v222 = 0;
  v223 = v34;
  v219 = 0;
  v220 = 0;
  v230 = 0;
  v234 = 0;
  deadtype = 0;
  v237 = 1;
  while (1)
  {
    v53 = v52;
    if (KoukaBadDamage == 2048)
    {
      deadtype = nbGetDeadType(v34, sformindex, v33);
      v54 = 1;
      KoukaHp = nbGetKoukaHp(1, v34, sformindex, v33, CriticalPow, cnt);
      v56 = nbGetKoukaHp(0, v34, sformindex, v33, CriticalPow, cnt);
      v238 = 2048;
    }
    else
    {
      KoukaHp = nbGetKoukaHp(1, v34, sformindex, v33, CriticalPow, cnt);
      v56 = nbGetKoukaHp(0, v34, sformindex, v33, CriticalPow, cnt);
      if (KoukaBadDamage == 4096)
      {
        v54 = 0;
        v238 = 0;
        KoukaHp = nbGetUnitWorkFromFormindex(v33)->hp >> 1;
      }
      else
      {
        if (KoukaBadDamage == 0x2000)
        {
          hp = nbGetUnitWorkFromFormindex(v33)->hp;
          v54 = 0;
          v238 = 0;
          v59 = hp >> 2 ? -(hp >> 2) : -1;
        }
        else
        {
          if (KoukaBadDamage != 0x4000)
          {
            v238 = KoukaBadDamage;
            v54 = 0;
            goto LABEL_160;
          }
          hp = nbGetUnitWorkFromFormindex(v33)->hp;
          v54 = 0;
          v238 = 0;
          v59 = hp > 9 ? -(hp / 0xA) : -1;
        }
        KoukaHp = (v59 + hp) & ~((v59 + hp) >> 31);
      }
    }
LABEL_160:
    v245 = KoukaHp;
    v60 = sub_8D3950(s32, &v245);
    v236 = v56;
    v244 = v56;
    v62 = sub_8D3950(s32, &v244);
    Write_2930752("HP damage = {0:D}, kaifuku = {1:D}\n", v60, v62, 0);
    KoukaMp = nbGetKoukaMp(1, v34, sformindex, v33, CriticalPow, cnt);
    v64 = nbGetKoukaMp(0, v34, sformindex, v33, CriticalPow, cnt);
    v243[0] = KoukaMp;
    v65 = v64;
    v66 = sub_8D3950(s32, v243);
    v235 = v65;
    v242 = v65;
    v67 = sub_8D3950(s32, &v242);
    Write_2930752("MP damage = {0:D}, kaifuku = {1:D}\n", v66, v67, 0);
    if (v225)
    {
      if ((KoukaHp & 0x80000000) == 0)
        v236 = KoukaHp + (v56 & ~(v56 >> 31));
      v68 = v53;
      v54 = 0;
      if ((KoukaMp & 0x80000000) == 0)
        v235 = (v235 & ~(v235 >> 31)) + KoukaMp;
      KoukaHp = -1;
      KoukaMp = -1;
      if (HIDWORD(v225) != 0x10000)
      {
LABEL_172:
        v228 = 0;
        goto LABEL_177;
      }
    }
    else
    {
      v68 = v53;
      if (HIDWORD(v225) != 0x10000)
        goto LABEL_172;
    }
    if (v33 <= 15)
    {
      v69 = (*a)->data->form;
      nbAddMojiEffKoukaPacket(frame, 45, (*a)->uniqueid, &v69->m_Items[v33], 4, 0);
      v54 = 0;
      v228 = 1;
    }
    else
    {
      v228 = 0;
      v54 = 0;
    }
    KoukaHp = -1;
    KoukaMp = -1;
LABEL_177:
    v232 = nbCheckHitEffect(v34, sformindex, v33);
    if (cnt == v237 && v238)
    {
      v72 = v238;
      v73 = 1;
    }
    else
    {
      v72 = v68 & ((KoukaHp & KoukaMp) >> 31);
      v73 = (KoukaHp & KoukaMp) >= 0;
    }
    if (v54)
      v74 = 0;
    else
      v74 = v72;
    v231 = v73 | v54;
    if (!(v73 | v54))
    {
      v84 = v235;
      v83 = v236;
      v52 = v74;
      goto LABEL_338;
    }
    if (v229)
    {
      if (!v54)
        goto LABEL_206;
    }
    else
    {
      v88 = v222;
      sformindex = v226;
      if (!tbl->m_Items[v223]->koukatype)
        v88 = 1;
      v222 = v88;
      if (!v54)
      {
LABEL_206:
        if (KoukaHp < 1)
        {
          v91 = 0;
LABEL_261:
          v78 = v230;
          goto LABEL_262;
        }
        v89 = (*a)->timelist;
        v78 = v230;
        if (KoukaHp >= v89->m_Items[v33]->hp)
        {
          if (nbCheckKuisibariSkill(v33))
          {
            v92 = *a;
            v93 = (*a)->timelist;
            if (v33 >= LODWORD(v93->max_length))
            {
LABEL_223:
            }
            goto LABEL_224;
          }
          if (nbCheckKuisibari2Skill(v33))
          {
            v76 = *a;
            v77 = (*a)->timelist;
            if (v33 >= LODWORD(v77->max_length))
            {
LABEL_195:
            }
            goto LABEL_196;
          }
        }
        v91 = 0;
        if (!type[0])
        {
LABEL_240:
          HpDrainRitu = nbGetHpDrainRitu(v34, sformindex, v33);
          if (HpDrainRitu > 0.0)
            v219 += (HpDrainRitu * KoukaHp);
          if (((*a)->data->stat & 0x20000) == 0)
          {
            v102 = (*a)->timelist;
            sformindex = v226;
            v104 = v102->m_Items[v33]->hp - KoukaHp;
            (*a)->timelist->m_Items[v33]->hp = v104 & ~(v104 >> 31);
          }
          v105 = (*a)->timelist;
          if (v105->m_Items[v33]->hp || (nbGetDevilFormatFlag(v33) & 0x100) != 0)
          {
            v109 = nbCheckStoneDead(v34, v33);
            v110 = deadtype;
            if (v109)
            {
              v91 = 1;
              v110 = 1;
            }
            deadtype = v110;
          }
          else
          {
            v107 = nbGetDeadType(v34, sformindex, v33);
            if (nbGetBadStat(v33) == 1024)
              v108 = 1;
            else
              v108 = v107;
            v91 = 1;
            deadtype = v108;
          }
          goto LABEL_261;
        }
LABEL_227:
        v95 = (*a)->timelist;
        v97 = KoukaHp;
        if (KoukaHp > v95->m_Items[v33]->hp)
        {
          v98 = (*a)->timelist;
          v97 = v98->m_Items[v33]->hp;
        }
        LODWORD(v220) = v97 + v220;
        goto LABEL_240;
      }
    }
    if (nbCheckKuisibari2Skill(v33))
    {
      if (v74 == 2048)
        v72 = 0;
      else
        v72 = v74;
      v76 = *a;
      v77 = (*a)->timelist;
      v78 = v230;
      if (v33 >= LODWORD(v77->max_length))
        goto LABEL_195;
LABEL_196:
      uniqueid = v76->uniqueid;
      v81 = frame;
      KoukaHp = v77->m_Items[v33]->hp - 1;
      v82 = 360;
      goto LABEL_225;
    }
    if (nbCheckKuisibariSkill(v33))
    {
      if (v74 == 2048)
        v72 = 0;
      else
        v72 = v74;
      v92 = *a;
      v93 = (*a)->timelist;
      v78 = v230;
      if (v33 >= LODWORD(v93->max_length))
        goto LABEL_223;
LABEL_224:
      uniqueid = v92->uniqueid;
      v81 = frame;
      KoukaHp = v93->m_Items[v33]->hp - 1;
      v82 = 345;
LABEL_225:
      nbAddSkillNamePacket(v81, uniqueid, v82);
      v91 = 0;
      if (KoukaHp < 1)
        goto LABEL_262;
LABEL_226:
      if (!type[0])
        goto LABEL_240;
      goto LABEL_227;
    }
    v78 = v230;
    v72 = 0;
    v91 = 1;
    if (KoukaHp >= 1)
      goto LABEL_226;
LABEL_262:
    if (KoukaMp < 1)
    {
      v114 = v72;
    }
    else
    {
      if (type[0])
        v111 = KoukaMp;
      else
        v111 = 0;
      v112 = v111 + v78;
      MpDrainRitu = nbGetMpDrainRitu(v34, sformindex, v33);
      v114 = v72;
      v230 = v112;
      if (MpDrainRitu > 0.0)
        HIDWORD(v220) += (MpDrainRitu * KoukaMp);
    }
    v115 = ((*a)->data->stat & 0x20000) == 0 || v91 == 0;
    if (!v115)
      v91 = 0;
    v116 = nbGetDevilFormatFlag(v33) & 0x100;
    if (v91)
      v117 = v116 == 0;
    else
      v117 = 1;
    v118 = *a;
    if (v117)
      dead = v91;
    else
      dead = 0;
    v120 = v118->uniqueid;
    v121 = v118->data->form;
    v123 = &v121->m_Items[v33];
    if (v229 != 1)
    {
      v52 = v114;
      nbMakeDamagePacket(frame, v120, v123, type[1], KoukaHp, KoukaMp, v114, v232, dead, deadtype, 1, 0);
      v34 = nskill;
      v84 = v235;
      v83 = v236;
      if (v218 >= 2 && ((nskill - 164) < 3 || !nskill))
      {
        if (type[1] == 1)
          v129 = 65539;
        else
          v129 = 65538;
        nbAddSePacket(frame, (*a)->uniqueid, v129, 0);
      }
      if (dead)
        goto LABEL_304;
LABEL_286:
      work = (*a)->work;
      sformindex = v226;
      attackinterval = 10;
      if ((work->flag & 4) == 0)
      {
        if (work->nowcommand != 1)
        {
          attackinterval = 10;
          if (work->nowcommand)
            goto LABEL_321;
LABEL_317:
          id = work->id;
          attackinterval = Get(id, 1, 0)->attackinterval;
          goto LABEL_321;
        }
        attackinterval = 10;
        if ((work->nowindex & 0xFFFC) == 0xA4)
          goto LABEL_317;
      }
LABEL_321:
      if ((attackinterval / v21) <= 5)
        v139 = 5;
      else
        v139 = (attackinterval / v21);
      SetTimeList(a, v33, frame, v139, v139);
      frame += v139;
      if (!v52)
      {
        if (v33 <= 15)
        {
          UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(v33);
          if (nbCheckBadKaifuku(UnitWorkFromFormindex, 2))
          {
            v142 = (*a)->data->form;
            nbMakeBadKaifukuPacket(frame, (*a)->uniqueid, &v142->m_Items[v33], 0);
          }
        }
        v52 = 0;
      }
      v54 = 0;
      goto LABEL_338;
    }
    nbMakeDamagePacket(frame, v120, v123, type[1], KoukaHp, KoukaMp, v114, v232, dead, deadtype, 1, 2);
    v52 = v114;
    nbAddSePacket(frame, (*a)->uniqueid, 0x10002u, 0);
    v34 = nskill;
    v84 = v235;
    v83 = v236;
    if (!dead)
      goto LABEL_286;
LABEL_304:
    SetTimeList(a, v33, frame, 30, 30);
    v131 = *a;
    v132 = (*a)->timelist;
    sformindex = v226;
    if ((v131->data->stat & 0x20000) == 0)
    {
      v134 = v131->timelist;
      v135 = v132->m_Items[v33]->hp;
      v137 = v134->m_Items[v33]->hp - v135;
      v134->m_Items[v33]->hp = v137 & ~(v137 >> 31);
      v84 = v235;
      v83 = v236;
    }
    frame += 30;
    v54 = 1;
LABEL_338:
    LODWORD(v234) = (v83 & ~(v83 >> 31)) + v234;
    HIDWORD(v234) += v84 & ~(v84 >> 31);
    GensyoRitu = nbGetGensyoRitu(v34, sformindex, v33);
    if (v54)
    {
      v154 = 1;
      goto LABEL_358;
    }
    KoukaBadDamage = v238;
    v145 = GensyoRitu;
    if (v84 <= 0 && v83 <= 0 && !v231)
    {
      v147 = tbl;
      if (!(v228 | badstat | v147->m_Items[v223]->hojotype))
        break;
    }
    CriticalPow = CriticalPow * v145;
    if (v237++ >= cnt)
    {
      v154 = 0;
LABEL_358:
      v151 = v234;
      v150 = HIDWORD(v234);
      v152 = v230;
      goto LABEL_359;
    }
  }
  Write("MISS!!!\n", 0);
  v165 = (*a)->data->form;
  v151 = v234;
  v150 = HIDWORD(v234);
  v152 = v230;
  nbAddMojiEffKoukaPacket(frame, 45, (*a)->uniqueid, &v165->m_Items[v33], 3, 0);
  v167 = frame + 7;
  v168 = (*a)->hitstopframe;
  if (v168 && v168 <= v167)
  {
    v154 = 0;
    type[1] = 0;
  }
  else
  {
    v154 = 0;
    type[1] = 0;
    (*a)->hitstopframe = v167;
  }
LABEL_359:
  v153 = v220;
LABEL_360:
  (*a)->allhpdamage += v153;
  (*a)->allmpdamage += v152;
  if ((v154 & 1) == 0)
  {
    if (badstat || v150 > 0 || (v155 = frame, v151 >= 1))
    {
      v156 = *a;
      if (v151 <= 0)
        v157 = -1;
      else
        v157 = v151;
      if (v150 <= 0)
        v158 = -1;
      else
        v158 = v150;
      v159 = v156->data->form;
      nbMakeKaifukuPacket(frame, v156->uniqueid, &v159->m_Items[v33], 0, v157, v158, badstat);
      if (badstat)
        nbSetBadStat(v33, 0, badstat);
      v34 = nskill;
      if (v157 >= 1)
      {
        if (((*a)->data->stat & 0x20000) == 0)
        {
          v163 = (*a)->timelist;
          max_length = v163->max_length;
          v170 = v157 + v163->m_Items[v33]->hp;
          v172 = v163->m_Items[v33];
          if (v170 < 0)
            v172->hp = 0;
          else
            v172->hp = v170;
        }
      }
      SetTimeList(a, v33, frame, 15, 20);
      v155 = frame + 15;
      if (v33 <= 15)
        goto LABEL_405;
    }
    else
    {
      if (v33 > 15)
        goto LABEL_422;
LABEL_405:
      v174 = tbl;
      v175 = v34;
      hojotype = v174->m_Items[v34]->hojotype;
      if (hojotype)
      {
        v178 = (*a)->uniqueid;
        v180 = (*a)->data->form;
        v181 = tbl;
        hojopoint = v181->m_Items[v175]->hojopoint;
        nbAddHojoKoukaPacket(v155, v178, &v180->m_Items[v33], hojotype, hojopoint);
        SetTimeList(a, v33, v155, 10, 15);
        v34 = nskill;
      }
    }
  }
LABEL_422:
  if (type[0] && (SHIDWORD(v220) >= 1 || v219 >= 1))
  {
    v187 = (*a)->data->form;
    if (v219 <= 0)
      v188 = -1;
    else
      v188 = v219;
    if (SHIDWORD(v220) <= 0)
      v189 = -1;
    else
      v189 = HIDWORD(v220);
    v190 = sformindex;
    nbMakeKaifukuPacket(
      frame + 15,
      (*a)->uniqueid,
      &v187->m_Items[sformindex],
      2,
      v188,
      v189,
      0,
      0);
    sformindex = v226;
    v34 = nskill;
    if (v188 >= 1)
    {
      if (((*a)->data->stat & 0x20000) == 0)
      {
        v194 = (*a)->timelist;
        v196 = v188 + v194->m_Items[v190]->hp;
        v197 = v194->m_Items[v190];
        if (v196 < 0)
          v197->hp = 0;
        else
          v197->hp = v196;
        v34 = nskill;
      }
    }
    SetTimeList(a, v226, frame + 5, 15, 20);
  }
  if (v154 & 1 | (v222 == 0) || (*a)->type)
  {
    nbSetKuisibariStop(v33);
    if (v154)
      goto LABEL_450;
  }
  else
  {
    CheckCounter(a, v33, sformindex);
    nbSetKuisibariStop(v33);
    if (v154)
    {
LABEL_450:
      SetDeadPacket(a, v33);
    }
  }
  v200 = nbGetUnitWorkFromFormindex(v33);
  if ((v34 - 49) < 2)
  {
    v204 = v200->id;
    v202 = formindex2;
    v203 = type[1];
    v205 = 78;
    goto LABEL_468;
  }
  v115 = v34 == 224;
  v202 = formindex2;
  v203 = type[1];
  if (v115)
  {
    v204 = v200->id;
    v205 = 88;
LABEL_468:
    nbSetJyokyoMes(a, v205, 1, v204);
  }
  switch (v229)
  {
    case 0:
      switch (v203)
      {
        case 2:
          Write("weak hit!\n", 0);
          v208 = *a;
          press = (*a)->press;
          if (press >= -1.0 && (press < -0.5 || press == 0.0))
          {
            v208->press = -0.5;
            v208 = *a;
          }
          if (v208->newpresstype <= 1)
          {
            v209 = 2;
            goto LABEL_546;
          }
          break;
        case 1:
          Write("critical hit!\n", 0);
          v208 = *a;
          v216 = (*a)->press;
          if (v216 >= -1.0 && (v216 < -0.5 || v216 == 0.0))
          {
            v208->press = -0.5;
            v208 = *a;
          }
          if (v208->newpresstype <= 2)
          {
            v209 = 3;
            goto LABEL_546;
          }
          break;
        case 0:
          Write("normal hit!\n", 0);
          goto LABEL_500;
      }
      break;
    case 1:
      if (nbCheckFormationFriend(sformindex, v202))
        goto LABEL_500;
      Write("hansya hit!\n", 0);
      v208 = *a;
      if ((*a)->press > -4.0)
      {
        v208->press = -4.0;
        v208 = *a;
      }
      if (v208->newpresstype <= 5)
      {
        v209 = 6;
        goto LABEL_546;
      }
      break;
    case 2:
      if (nbCheckFormationFriend(sformindex, v202))
        goto LABEL_500;
      Write("kyusyu hit!\n", 0);
      v208 = *a;
      if ((*a)->press > -4.0)
      {
        v208->press = -4.0;
        v208 = *a;
      }
      if (v208->newpresstype <= 6)
      {
        v209 = 7;
        goto LABEL_546;
      }
      break;
    case 3:
      if (nbCheckFormationFriend(sformindex, v202))
      {
LABEL_500:
        v211 = *a;
        if ((*a)->press == 0.0)
        {
          v211->press = -1.0;
          v211 = *a;
        }
        if (v211->newpresstype < 0)
          v211->newpresstype = 0;
      }
      else
      {
        Write("mukou hit!\n", 0);
        v208 = *a;
        if ((*a)->press > -2.0)
        {
          v208->press = -2.0;
          v208 = *a;
        }
        if (v208->newpresstype <= 4)
        {
          v209 = 5;
LABEL_546:
          v208->newpresstype = v209;
        }
      }
      break;
    default:
      return;
  }
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
        goto LABEL_15;
    }
    v9 = (*a)->timelist;
    v5 = *(*(&v9->obj.klass + i) + 16LL);
  }
LABEL_15:
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
LABEL_43:
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
        goto LABEL_43;
      }
    }
  }
  v31 = *a;
  v32 = (*a)->form->formindex;
  else if ((v31->data->stat & 0x20000) != 0)
  {
    goto LABEL_53;
  }
  v33 = v31->timelist;
  max_length = v33->max_length;
  v35 = v33;
  v37 = v33->m_Items[v32]->hp - v3;
  v35->m_Items[v32]->hp = v37 & ~(v37 >> 31);
LABEL_53:
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
  s32 MakaBaramaki;
  dds3GlobalWork_c *v9;
  s32 formindex;
  u64 *v12;
  s32 v15;
  s32 v16;

  MakaBaramaki = nbGetMakaBaramaki((*a)->work, 0);
  if (nbCheckFormationPlayerSide((*a)->form->formindex, 0))
  {
    if (MakaBaramaki > DDS3_GBWK->maka)
    {
      if ((v9->_2.bitflags2 & 2) != 0)
      {
        MakaBaramaki = DDS3_GBWK->maka;
      }
      else
      {
        MakaBaramaki = DDS3_GBWK->maka;
      }
    }
  }
  formindex = (*a)->form->formindex;
  SetTimeList(a, formindex, sframe, 30, 30);
  v16 = MakaBaramaki;
  v12 = sub_8D3950(s32, &v16);
  Write_2930400("ばらまき = {0:D}\n", v12);
  nbSetJyokyoMes(a, 44, 0, MakaBaramaki);
  if (nbCheckFormationPlayerSide((*a)->form->formindex, 0))
  {
    v15 = -MakaBaramaki;
  }
  else
  {
    v15 = MakaBaramaki;
  }
  datAddMaka(v15);
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
      goto LABEL_102;
    }
    v56 = tbl;
    if ((v56->m_Items[nskill]->program & 0xFFFFFFFE) == 2)
LABEL_102:
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
  Write("オンギョウジ影消滅(1)\n", 0);
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
  Write("オンギョウジ影消滅(ALL)\n", 0);
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
      goto LABEL_22;
  }
  else
  {
    enemyunit = DDS3_GBWK->unitwork;
    v27 = nowindex;
    if (nowindex >= LODWORD(enemyunit->max_length))
    {
LABEL_22:
    }
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
LABEL_8:
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
      goto LABEL_8;
  }
  if (v4 == 0.0)
    goto LABEL_8;
}

// 0xf2ef50
void SetSakePacket(nbActionProcessData_t **a, s32 nskill, s32 sformindex, s32 dformindex, s32 cnt, s32 frame) {
  struct nbFormation_t_array *form;
  nbActionProcessData_t_o *v15;
  s32 hitstopframe;
  s32 v17;
  nbActionProcessData_t_o **v20;
  s32 v21;
  nbActionProcessData_t_o *v22;

  form = (*a)->data->form;
  nbAddSakeKoukaPacket(frame, (*a)->uniqueid, &form->m_Items[dformindex], 0);
  else
  {
    v15 = *a;
    hitstopframe = (*a)->hitstopframe;
    v17 = frame + 7;
    if (hitstopframe)
      goto LABEL_8;
  }
  v15->hitstopframe = v17;
LABEL_10:
  SetTimeList(a, dformindex, frame, 10, 20);
  if (nbCheckSingleTargetSkill(nskill))
  {
    if (nbCheckFormationPlayerSide(dformindex))
    {
      v20 = a;
      v21 = 2;
    }
    else
    {
      v20 = a;
      v21 = 4;
    }
    nbSetJyokyoMes(v20, v21, -1, 0);
  }
  v22 = *a;
  if ((*a)->press > -2.0)
  {
    v22->press = -2.0;
    v22 = *a;
  }
  if (v22->newpresstype <= 3)
    v22->newpresstype = 4;
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
  nbActionProcess_c *v2;
  s64 v3;
  s16 v4;
  u64 v5;
  s32 i;
  struct SOBED_PB_LIST_array *sobed_pb_all;
  u64 max_length_low;
  UnityEngine_Object_o *v11;
  struct SOBED_PB_LIST_array *v13;

  if (sobed_pb_all)
  {
    v3 = 4;
    v4 = *&v2->_2.bitflags1;
    v5 = 0;
    if ((v4 & 0x200) != 0)
      goto LABEL_11;
LABEL_10:
    for (i = 0; ; i = v4 & 0x200)
    {
      max_length_low = LODWORD(sobed_pb_all->max_length);
      if (v5 >= max_length_low)
        break;
      else if (v5 >= max_length_low)
      {
        goto LABEL_18;
      }
      v11 = *(*(&sobed_pb_all->obj.klass + v3) + 16LL);
      if (op_Inequality(v11, 0, 0))
      {
        v13 = sobed_pb_all;
        *(*(&v13->obj.klass + v3) + 16LL) = 0;
      }
      ++v3;
      v5 = v3 - 4;
      if ((v4 & 0x200) == 0)
        goto LABEL_10;
LABEL_11:
    }
    sobed_pb_all = 0;
  }
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
  return "";
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
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  nbMainProcessData_t_o *v8;
  u32 PrevActionSeq;
  nbActionProcessData_t_o *v13;
  u32 stat;
  s64 v15;
  _BOOL4 v16;
  struct nbActionProcess_nbActionFunc_t_array *ActionFunc;
  u32 seq;
  s32 v21;
  nbActionProcessData_t_o *v22;
  s32 seqtime;
  s32 nextseq;
  nbActionProcessData_t_o *UnnamedParameter;
  dds3ProcessID_t_o *ida;
  u64 v28[3];

  ida = id;
  UnnamedParameter = 0;
  else
  {
    ProcessData = dds3GetProcessData(&ida);
    if (!ProcessData)
      goto LABEL_12;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v28);
    if ((v28[0] & 1) != 0)
      v6 = v28[2];
    else
      v6 = v28 + 1;
    v7 = sub_8C4940(v6);
  }
LABEL_12:
  UnnamedParameter = ProcessData;
  if ((BYTE1(ProcessData[1].monitor) & 4) != 0)
  {
    v8 = ProcessData[1].klass;
    nbPanelStockSelect(v8, 0);
  }
  PrevActionSeq = nbGetPrevActionSeq();
  v13 = UnnamedParameter;
  stat = UnnamedParameter->stat;
  v15 = 32;
  if ((stat & 2) != 0)
    v15 = 33;
  if (*(&UnnamedParameter->klass + v15) != 7)
    goto LABEL_27;
  v16 = PrevActionSeq > 0x12;
  Write("AD-PCM再生中!\n", 0);
  v13 = UnnamedParameter;
  stat = UnnamedParameter->stat;
  if (v16)
  {
LABEL_27:
    if ((stat & 0x40) == 0)
    {
      if ((stat & 2) != 0)
      {
        if (v13->seq == 22)
        {
          ida->func_ans = -1;
        }
        else
        {
          nextseq = v13->nextseq;
          SetActionSeq(&UnnamedParameter, nextseq);
          UnnamedParameter->stat &= ~2u;
        }
      }
      else
      {
        seq = v13->seq;
        v21 = Invoke(
                ActionFunc->m_Items[seq]->check,
                &UnnamedParameter,
                0);
        v22 = UnnamedParameter;
        if (v21)
          UnnamedParameter->stat |= 2u;
        seqtime = v22->seqtime;
        if (seqtime != 0xFFFF)
          v22->seqtime = seqtime + 1;
      }
    }
  }
  return 0;
}

// 0xf40df0
void *nbActionShutdown(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppMethodPointer methodPtr;
  Il2CppMethodPointer v10;
  Il2CppMethodPointer v13;
  Il2CppMethodPointer v15;
  Il2CppMethodPointer v17;
  Il2CppMethodPointer v19;
  Il2CppMethodPointer v21;
  effBTL_t_o **v22;
  u64 *monitor;
  char *v24;
  u64 v25;
  Il2CppMethodPointer v29;
  Il2CppObject *v31;
  Il2CppClass *v32;
  s64 v33;
  char *v34;
  s64 *v35;
  u64 v37[2];
  char *v38;
  dds3ProcessID_t_o *ida;

  ida = id;
  ProcessData = dds3GetProcessData(&ida);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != nbActionProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, nbActionProcessData_t, v37);
      if ((v37[0] & 1) != 0)
        v7 = v38;
      else
        v7 = v37 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  methodPtr = ProcessData[1].klass->vtable[0].methodPtr;
  if (*(methodPtr + 4) == ida)
  {
    v10 = ProcessData[1].klass->vtable[0].methodPtr;
    *(v10 + 4) = 0;
  }
  v13 = ProcessData[1].klass->vtable[0].methodPtr;
  if (*(v13 + 5) == ida)
  {
    v15 = ProcessData[1].klass->vtable[0].methodPtr;
    *(v15 + 5) = 0;
  }
  v17 = ProcessData[1].klass->vtable[0].methodPtr;
  if (*(v17 + 6) == ida)
  {
    v19 = ProcessData[1].klass->vtable[0].methodPtr;
    *(v19 + 6) = 0;
  }
  v21 = ProcessData[1].klass->vtable[0].methodPtr;
  if (*(v21 + 7) == ida)
  {
    v29 = ProcessData[1].klass->vtable[0].methodPtr;
    *(v29 + 7) = 0;
    v22 = &ProcessData[10];
    if (!ProcessData[10].klass)
    {
LABEL_35:
      monitor = ProcessData[13].monitor;
      if (monitor)
        goto LABEL_36;
LABEL_51:
        goto LABEL_53;
      goto LABEL_52;
    }
  }
  else
  {
    v22 = &ProcessData[10];
    if (!ProcessData[10].klass)
      goto LABEL_35;
  }
  effBTLDelete(v22);
  monitor = v4[13].monitor;
  if (!monitor)
    goto LABEL_51;
LABEL_36:
  v24 = monitor[3];
  if (v24 >= 1)
  {
    v25 = 0;
    do
    {
      v24 = &monitor[v25++];
      *(v24 + 4) = 0;
      monitor = v4[13].monitor;
      LODWORD(v24) = *(monitor + 6);
    }
    while (v25 < v24);
  }
  v4[13].monitor = 0;
  {
LABEL_53:
    v31 = dds3GetProcessData(&ida);
    if (!v31)
      return 0;
    goto LABEL_54;
  }
LABEL_52:
    goto LABEL_53;
  v31 = dds3GetProcessData(&ida);
  if (!v31)
    return 0;
LABEL_54:
  v32 = v31->klass;
  if (v31->klass->_2.typeHierarchyDepth < v33
    || v32->_2.typeHierarchy[v33 - 1] != nbActionProcessData_t)
  {
    sub_8FC2C0(v32->_1.element_class, nbActionProcessData_t, v37);
    if ((v37[0] & 1) != 0)
      v34 = v38;
    else
      v34 = v37 + 1;
    v35 = sub_8C4940(v34);
  }
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
LABEL_6:
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
  char *ProcessData;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  dds3ProcessID_t_o *v9;
  u64 v10[3];

  v9 = id;
  if (!id)
    return 0;
  ProcessData = dds3GetProcessData(&v9);
  v4 = *ProcessData;
  if (*(*ProcessData + 288LL) < typeHierarchyDepth
    || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != nbActionProcessData_t)
  {
    sub_8FC2C0(*(v4 + 64), nbActionProcessData_t, v10);
    if ((v10[0] & 1) != 0)
      v7 = v10[2];
    else
      v7 = v10 + 1;
    v8 = sub_8C4940(v7);
  }
  return ProcessData[32];
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
  target = dds3StartProcess("nb_action", 0x3F8u, 1, 1, v15, 0, v16, 0, inited, 0);
  dds3LinkProcess(&(*data)->MainProcessID, &target, 0);
  v18 = *data;
  v19 = target;
  ActionProcessID = v18->ActionProcessID;
  v21 = v18->NowActionProcess;
  ActionProcessID->m_Items[v21] = v19;
}
