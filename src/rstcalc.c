#include "types.h"

typedef struct AnimCheckerBattle AnimCheckerBattle;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct rstSkillInfo_t rstSkillInfo_t;

static s8 EventStart;

u32 FCL_RAND(void);
u8 Get(s32 id);
void *GetAnimator(void *obj);
bool IsRstMotionFinished(AnimCheckerBattle *this);
void SetAnimator(void *obj, char *animkey, s32 animno);
void SetPointAnime(s32 point);
void UpdateNormalizeTime(AnimCheckerBattle *this);
u32 datGetMaxHp(datUnitWork_t *work);
u32 datGetMaxMp(datUnitWork_t *work);
s32 datGetParam(datUnitWork_t *work, s32 paratype);
void datUnitWork_t__Copy(datUnitWork_t *this, datUnitWork_t *dat);
s32 dds3FadeCheck(void);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
void *dds3GetProcessData(dds3ProcessID_t **id);
void dds3PadAct(u32 mode, u8 pow, u32 frame);
bool evtBitCheck(s32 no);
void fclSetMessageVar_20743088(s8 Index, char *pStr);
s8 fclStartMessage(s32 MsgNo);
s8 fclStartSelMessage(s32 SelMsgNo);
void mdlSmoothLoopMotionForUnity(evtUnitHandle_t **h, s32 layer, s32 motion, s32 before, s32 wait, bool btl);
void mdlSmoothSingleMotionForUnity(evtUnitHandle_t **h, s32 layer, s32 motion, s32 before, s32 wait, bool btl);
s32 p2sdPlayBGM(s32 a);
s32 p2sdPlaySE(s32 a);
void p2sdSndStop(s32 MidiNo);
void rstAddAsignParam(datUnitWork_t **pStock);
void rstAutoAsignDevilParam(void);
s8 rstCalcEventInfo(u16 *pParamBuf);
s8 rstCalcEvo(void);
s8 rstCalcHeartsEvent(void);
s8 rstCalcHeartsMaster(void);
s8 rstCalcSeqDestroySkill(void);
s32 rstCalcSeqDevilLevelUp(void);
s8 rstCalcSeqEvoAt(void);
s8 rstCalcSeqGift(void);
s8 rstCalcSeqPlayerLevelUp(void);
s8 rstCalcSkillPowerUp(void);
s8 rstCalcSkillPowerUpCore(void);
s8 rstChkAddSkill(u16 SkillID);
s8 rstChkBeforeSkillOwner(u16 SkillID, s16 LevelOfs, datUnitWork_t *pStock);
s8 rstChkEvoEvent(datUnitWork_t *pStock, datUnitWork_t *pEvoDevil, s32 EvtBufIdx);
u16 rstChkHeartsSkill(datUnitWork_t **pStock);
bool rstChkMotionEnd(void *obj, s32 index);
s32 rstChkParamLimitAll(datUnitWork_t *pStock, bool paramSet);
s8 rstChkPartyDevilSkillPowerUp(void);
s8 rstChkSkillPowerUp1(void);
s8 rstChkSkillPowerUp2(void);
void rstCreateBeforeSkillList(s8 HeartsID, datUnitWork_t *pStock, s16 SkillLevOfs, rstSkillInfo_t *pInfo);
s8 rstGetDefaultSkill(void);
void rstInitEvoAct(void);
void rstInitSkillAct(s8 Pos);
void rstInitWorkStock(s8 IkenieChk);
void rstMotionReq(void);
u16 rstRndGetPowerUpSkill(datUnitWork_t *pStock, s8 *pIdx);
s8 rstSetCurrentDevil(void);
void rstSetDestroySkillMaxHpMp(void);
s8 rstSetLevelUpCount(datUnitWork_t *pStock);
void rstSetMaxHpMp(s8 Mode, datUnitWork_t **pStock);
void rstSetMotionReqFromTbl(s8 Type);
void rstSmoothMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, f32 aBeforeLeng, f32 aSmoothLeng);

// 0x155ef30
void rstAddLevel(s32 Val, datUnitWork_t *pStock) {
  u32 level;

  level = pStock->level;
  if (level <= 0xFE)
    pStock->level = level + Val;
}

// 0x1561a70
void rstAutoAsignDevilParam(void) {
  u64 *v1;
  struct System_SByte_array *ParamOfs;
  datUnitWork_t_o *pCurrentStock;
  s32 v9;
  s32 v11;
  s32 Param;
  struct System_SByte_array *v14;
  struct System_SByte_array *v17;
  datUnitWork_t_o *pStock;

  v1 = Allocate(datUnitWork_t);
  datUnitWork_t___ctor(v1);
  pStock = v1;
  ParamOfs = GBWK->ParamOfs;
  Clear(ParamOfs, 0, ParamOfs->max_length, 0);
  pCurrentStock = GBWK->pCurrentStock;
  cmbCopyCustomDevilToStock(v1, pCurrentStock);
  v9 = 0;
  {
  }
  while (v9 < GBWK->AsignParamMax)
  {
    v11 = cmbAddLevelUpParamEx(&pStock, 0);
    if ((v11 & 0x80000000) == 0)
    {
      Param = datGetParam(v1, v11);
      v14 = GBWK->ParamOfs;
      if (Param + v14->m_Items[v11] <= 39)
      {
        v17 = GBWK->ParamOfs;
        ++v17->m_Items[v11];
      }
    }
    ++v9;
  }
}

// 0x1564f80
void *rstCalc(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    rstCalcSeqPlayerLevelUp();
    rstChkHeartsSkill(0);
    rstChkAddSkill(0);
    rstCalcHeartsEvent();
    rstCalcSkillPowerUpCore();
    dds3PadAct(0, 0, 0);
    Get(0);
    fclSetMessageVar_20743088(0, 0);
    fclStartMessage(0);
    fclStartSelMessage(0);
    rstCalcHeartsMaster();
    rstInitWorkStock(0);
    rstGetDefaultSkill();
    rstInitSkillAct(0);
    rstCalcSkillPowerUp();
    Get(0);
    rstCalcSeqGift();
    rstCalcEvo();
    Get(0);
    rstCalcSeqEvoAt();
    rstAddAsignParam(0);
    rstCalcSeqDevilLevelUp();
    rstInitEvoAct();
    rstCalcSeqDestroySkill();
    rstMotionReq();
    dds3FadeCheck();
    return 0;
}

// 0x1561cf0
s8 rstCalcEventInfo(u16 *pParamBuf) {
    return 0;
}

// 0x1563840
s8 rstCalcEvo(void) {
  u16 *p_EventParam;
  s32 v4;
  u32 EventOfs;
  fclSkillParam_t_array *v7;
  struct fclSkillParam_t_array *pEvent;
  fclSkillParam_t_array *v11;
  s64 *v13;
  struct fclSkillParam_t_array *v15;
  s64 *v17;
  struct rstData_t_o *GBWK;
  datUnitWork_t_o *pCurrentStock;
  s8 v21;
  datUnitWork_t_o *EvoDevil;
  struct datUnitWork_t_o *v24;
  s32 id;
  struct datUnitWork_t_array *unitwork;
  s64 v28;
  datUnitWork_t_o *v30;
  struct rstData_t_o *v35;
  datUnitWork_t_o *v36;
  datUnitWork_t_o *v37;
  s8 v38;
  struct rstData_t_o *v41;
  s8 v42;
  char v43;
  s32 v46;
  System_String_o *v48;
  datUnitWork_t_o *v50;
  s32 v52;
  fclSkillParam_t_array *v54;
  s32 v56;
  struct fclSkillParam_t_array *Event;
  s64 *v59;
  struct fclSkillParam_t_array *v64;
  s64 v65;
  s64 *v67;
  struct rstData_t_o *v70;
  datUnitWork_t_o *v71;
  datUnitWork_t_o *v72;
  struct datUnitWork_t_o *v74;
  s32 v75;
  struct datUnitWork_t_array *v77;
  s64 v78;
  datUnitWork_t_o *v80;
  struct rstData_t_o *v83;
  datUnitWork_t_o *v84;
  datUnitWork_t_o *v85;

  while (1)
  {
    p_EventParam = &GBWK->EventParam;
    v4 = rstCalcEventInfo(p_EventParam);
    if (v4 < 0)
      break;
    if (v4 == 5)
    {
      EventOfs = GBWK->EventOfs;
      v7 = NewSpecific(fclSkillParam_t, 2u);
      pEvent = GBWK->pEvent;
      v11 = v7;
      v13 = pEvent->m_Items[EventOfs - 1];
      v11->m_Items[0] = v13;
      v15 = GBWK->pEvent;
      v17 = v15->m_Items[EventOfs];
      v11->m_Items[1] = v17;
      pCurrentStock = GBWK->pCurrentStock;
      v21 = GBWK->EventNums > EventOfs;
      EvoDevil = GBWK->EvoDevil;
      cmbCalcEvoEvent(pCurrentStock, v11, v21, EvoDevil);
      v24 = GBWK->EvoDevil;
      id = v24->id;
      if (v24->id)
      {
        unitwork = DDS3_GBWK->unitwork;
        v28 = 0;
        while (1)
        {
          v30 = unitwork->m_Items[v28];
          if ((v30->flag & 1) != 0)
          {
            if (v30->id == id)
              break;
          }
          if (++v28 >= 0x10)
        }
        if ((v28 & 0x80000000) == 0)
          continue;
        v35 = GBWK;
        v36 = v35->EvoDevil;
        v37 = v35->pCurrentStock;
        v38 = rstChkEvoEvent(v37, v36, -1);
        if (v38 != 3)
        v41 = GBWK;
        v42 = 0;
        v43 = 3;
        v41->EvoFlag = v43;
        return v42;
      }
    }
  }
  v50 = GBWK->pCurrentStock;
  v52 = cmbChkCancelEvo(v50);
  if (v52 < 0)
  v54 = NewSpecific(fclSkillParam_t, 2u);
  v56 = GBWK->pCurrentStock->id;
  Event = Get(v56, 0)->Event;
  v59 = Event->m_Items[v52];
  v54->m_Items[0] = v59;
  v64 = Get(GBWK->pCurrentStock->id, 0)->Event;
  v65 = v52 + 1LL;
  v67 = v64->m_Items[v65];
  v54->m_Items[1] = v67;
  v70 = GBWK;
  v71 = v70->pCurrentStock;
  v72 = v70->EvoDevil;
  cmbCalcEvoEvent(v71, v54, v52 < 23, v72);
  v74 = GBWK->EvoDevil;
  v75 = v74->id;
  if (!v74->id)
  {
    v41 = GBWK;
    v42 = 0;
    v43 = -1;
  }
  v77 = DDS3_GBWK->unitwork;
  v78 = 0;
  while (1)
  {
    v80 = v77->m_Items[v78];
    if ((v80->flag & 1) != 0)
    {
      if (v80->id == v75)
        break;
    }
    if (++v78 >= 0x10)
  }
  if ((v78 & 0x80000000) == 0)
  v83 = GBWK;
  v84 = v83->EvoDevil;
  v85 = v83->pCurrentStock;
  v38 = rstChkEvoEvent(v85, v84, v52);
  if (v38 == 3)
  if (v38 == 2)
  {
    v41 = GBWK;
    v42 = 0;
    v43 = 2;
  }
  if (v38 == 1)
  {
    v41 = GBWK;
    v42 = 0;
    v43 = 1;
  }
  GBWK->EvoFlag = 0;
  v46 = GBWK->pCurrentStock->id;
  v48 = Get(v46, 0);
  v42 = 1;
  fclSetMessageVar_20743088(1, v48);
  fclStartMessage(21);
  fclStartSelMessage(43);
  return v42;
}

// 0x1564970
s8 rstCalcHeartsEvent(void) {
  struct dds3GlobalWork_t_o *v2;
  s64 heartsequip;
  struct System_Byte_array *heartsskcnt;
  s16 HeartsSkillNums;
  struct System_Byte_array *v10;
  u64 v13;
  u32 v15;
  struct fclHearts_t_array *fclHeartsTbl;
  struct System_Byte_array *Event;
  struct dds3GlobalWork_t_o *DDS3_GBWK;

  v2 = DDS3_GBWK;
  heartsequip = v2->heartsequip;
  if (!v2->heartsequip)
  heartsskcnt = DDS3_GBWK->heartsskcnt;
  if (heartsskcnt->m_Items[heartsequip] < 0)
  HeartsSkillNums = cmbGetHeartsSkillNums(heartsequip);
  v10 = DDS3_GBWK->heartsskcnt;
  if ((v10->m_Items[heartsequip] & 0xF) >= HeartsSkillNums)
  if (FCL_RAND() % 3 > 1)
  v13 = 0;
  v15 = FCL_RAND() % 0xFF;
  while (1)
  {
    Event = fclHeartsTbl->m_Items[heartsequip]->Event;
    if (v15 < Event->m_Items[v13])
      return v13;
    if (v13++ >= 7)
  }
}

// 0x1564d30
s8 rstCalcHeartsMaster(void) {
  struct dds3GlobalWork_t_o *v2;
  s64 heartsequip;
  struct System_Byte_array *heartsskcnt;
  s16 HeartsSkillNums;
  struct System_Byte_array *v10;
  struct dds3GlobalWork_t_o *DDS3_GBWK;

  v2 = DDS3_GBWK;
  heartsequip = v2->heartsequip;
  if (!v2->heartsequip)
    return -1;
  heartsskcnt = DDS3_GBWK->heartsskcnt;
  if (heartsskcnt->m_Items[heartsequip] < 0)
    return -1;
  HeartsSkillNums = cmbGetHeartsSkillNums(heartsequip);
  v10 = DDS3_GBWK->heartsskcnt;
  if ((v10->m_Items[heartsequip] & 0xF) >= HeartsSkillNums)
    return 0;
  else
    return -1;
}

// 0x15642b0
s8 rstCalcSeqDestroySkill(void) {
  cmpStatSetTimer(0, 2);
  rstSetDestroySkillMaxHpMp();
  return 1;
}

// 0x15623c0
s32 rstCalcSeqDevilLevelUp(void) {
    rstSetCurrentDevil();
    rstAutoAsignDevilParam();
    rstSetMotionReqFromTbl(0);
    p2sdSndStop(0);
    p2sdPlayBGM(0);
    Get(0);
    fclSetMessageVar_20743088(0, 0);
    dds3FadeOut(0, 0, 0, 0);
    return 0;
}

// 0x1564140
s8 rstCalcSeqEvoAt(void) {
  datUnitWork_t_o *pCurrentStock;
  struct datUnitWork_t_array *unitwork;
  s32 level;
  datUnitWork_t_o *v10;

  pCurrentStock = GBWK->pCurrentStock;
  if (cmbChkEvoAttention(pCurrentStock) < 0)
    return -1;
  unitwork = DDS3_GBWK->unitwork;
  level = unitwork->m_Items[0]->level;
  v10 = GBWK->pCurrentStock;
  if (level + 6 >= cmbChkDevilEvo(v10))
    return 0;
  else
    return -1;
}

// 0x1562850
s8 rstCalcSeqGift(void) {
  u32 v2;
  bool v4;
  s8 v6;
  u16 id;
  s8 v8;
  s8 v10;
  rstinit_c *v11;
  struct rstinit_StaticFields *static_fields;
  struct rstData_t_o *GBWK;
  rstinit_c *v15;
  struct rstData_t_o *v16;
  s32 v17;
  struct rstData_t_o *v19;
  u8 GiftMesType;

  v2 = FCL_RAND();
  v4 = v2 == 3 * (v2 / 3);
  if (!v4)
  {
    v6 = 0;
    GBWK->GiftItemID = 0;
    return v6;
  }
  id = GBWK->pCurrentStock->id;
  else
  {
    v8 = cmbChkGiftHeartsDevil(id);
    if (!v8)
  }
  v10 = v8;
  if (cmbChkGetHearts(v10))
  {
    GBWK->GiftType = 0;
    static_fields = v11->static_fields;
    GBWK = static_fields->GBWK;
    GBWK->GiftItemID = cmbGetGiftItem();
  }
  GBWK->GiftType = 1;
  GBWK->GiftItemID = v10;
  if ((v15->_2.bitflags2 & 2) == 0)
  v16 = GBWK;
  v17 = v16->pCurrentStock->id;
  v16->GiftMesType = 4 * LOBYTE(Get(v17, 0)->kucyo);
  v19 = GBWK;
  GiftMesType = v19->GiftMesType;
  v19->GiftMesType = (FCL_RAND() & 3) + GiftMesType;
  GBWK->GiftMesType += 44;
  return 1;
}

// 0x15620b0
s8 rstCalcSeqPlayerLevelUp(void) {
    rstSetLevelUpCount(0);
    rstChkParamLimitAll(0, 0);
    fclStartMessage(0);
    return 0;
}

// 0x1564960
void rstCalcSeqTakeAway(datUnitWork_t *pStock) {
  ;
}

// 0x15635e0
s8 rstCalcSkillPowerUp(void) {
  if (!rstChkSkillPowerUp1(rstcalc))
    return 0;
  return rstCalcSkillPowerUpCore();
}

// 0x15632a0
s8 rstCalcSkillPowerUpCore(void) {
  struct rstData_t_o *GBWK;
  datUnitWork_t_o *pCurrentStock;
  struct rstData_t_o *v8;
  u16 PUpSkillID;
  s16 LevelUpCnt;
  datUnitWork_t_o *v11;
  s8 v13;
  s8 result;
  s32 v18;
  struct rstData_t_o *v20;
  s32 v21;
  datUnitWork_t_o *v22;
  struct datUnitWork_t_o *v25;
  s8 v27;
  struct rstData_t_o *v30;
  datUnitWork_t_o *v31;
  u32 PUpSkillIndex;
  struct System_Int32_array *skill;
  s32 v35;
  u16 MutationSkill;
  u16 v38;

  pCurrentStock = GBWK->pCurrentStock;
  GBWK->PUpSkillID = rstRndGetPowerUpSkill(pCurrentStock, &GBWK->PUpSkillIndex);
  v8 = GBWK;
  PUpSkillID = v8->PUpSkillID;
  if (!PUpSkillID)
    return 0;
  LevelUpCnt = v8->LevelUpCnt;
  v11 = v8->pCurrentStock;
  v13 = rstChkBeforeSkillOwner(PUpSkillID, -LevelUpCnt, v11);
  result = 0;
  if (!v13)
  {
    v18 = rstChkSkillPowerUp2();
    if (v18 == 1)
    if (v18)
      return 3;
    v20 = GBWK;
    LOWORD(v21) = v20->PUpSkillID;
    v22 = v20->pCurrentStock;
    LOBYTE(v21) = cmbChkSkillOwner(v21, v22);
    v25 = GBWK->pCurrentStock;
    if ((v25->flag & 0x40) == 0)
    {
      v27 = rstChkPartyDevilSkillPowerUp();
      if (v21 < 0 && !v27)
      {
        GBWK->pCurrentStock->flag |= 0x40u;
        return 1;
      }
      v30 = GBWK;
      v31 = v30->pCurrentStock;
      PUpSkillIndex = v30->PUpSkillIndex;
      skill = v31->skill;
      v35 = skill->m_Items[PUpSkillIndex];
      MutationSkill = cmbGetMutationSkill(v35, v31);
      if (MutationSkill)
      {
        v38 = MutationSkill;
        GBWK->PUpSkillID = v38;
        return 2;
      }
      return 3;
    }
    return 0;
  }
  return result;
}

// 0x155ff60
void rstCancelMotionReq(void) {
  GBWK->MotionReqMode = 2;
}

// 0x1564ca0
s8 rstCheckHeartsEvent(void) {
  return FCL_RAND() % 3 < 2;
}

// 0x15627d0
s8 rstCheckSeqGift(void) {
  u32 v2;

  v2 = FCL_RAND();
  return v2 != 3 * (v2 / 3);
}

// 0x15601f0
s8 rstChkAddSkill(u16 SkillID) {
  datUnitWork_t_o *pCurrentStock;

  pCurrentStock = GBWK->pCurrentStock;
  if ((cmbChkSkillOwner(SkillID, pCurrentStock) & 0x80000000) == 0)
    return 0;
  if (GBWK->pCurrentStock->skillcnt <= 7)
    return 1;
  else
    return 2;
}

// 0x15618e0
s8 rstChkBeforeSkillOwner(u16 SkillID, s16 LevelOfs, datUnitWork_t *pStock) {
  u64 *v7;
  s8 heartsequip;
  u64 v12;
  u64 v13;

  v7 = Allocate(rstSkillInfo_t);
  v7[3] = NewSpecific(byte, 0x18u);
  v7[4] = NewSpecific(ushort, 0x18u);
  _ctor(v7, 0);
  heartsequip = DDS3_GBWK->heartsequip;
  rstCreateBeforeSkillList(heartsequip, pStock, LevelOfs, v7);
  if (*(v7 + 16) < 1)
    return 0;
  v12 = 0;
  while (1)
  {
    v13 = v7[4];
    if (*(v13 + 2 * v12 + 32) == SkillID)
      break;
    if (++v12 >= *(v7 + 16))
      return 0;
  }
  return 1;
}

// 0x1563190
s8 rstChkDevilSkillPowerUp(datUnitWork_t *pStock) {
  return (pStock->flag >> 6) & 1;
}

// 0x1563690
s8 rstChkEvoEvent(datUnitWork_t *pStock, datUnitWork_t *pEvoDevil, s32 EvtBufIdx) {
  s32 id;
  struct fclSkillParam_t_array *Event;
  s32 TargetLevel;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v14;
  s32 v15;
  u16 v17;

  if (EvtBufIdx < 0)
  {
    TargetLevel = -1;
  }
  else
  {
    id = pStock->id;
    Event = Get(id, 0)->Event;
    TargetLevel = Event->m_Items[EvtBufIdx]->TargetLevel;
  }
  unitwork = DDS3_GBWK->unitwork;
  v14 = unitwork->m_Items[0];
  else if ((TargetLevel & 0x80000000) == 0)
  {
    v15 = TargetLevel + 99 - pStock->level;
  }
  v15 = 255;
  if (v15 >= pEvoDevil->level - 4 - v14->level)
    v15 = pEvoDevil->level - 4 - v14->level;
  if (v15 < 1)
  {
    v17 = pEvoDevil->id;
    if (cmbChkEvoNeedFlag(v17, pEvoDevil))
      return 3;
    else
      return 0;
  }
  else if (v15 <= 2)
  {
    return 1;
  }
  else
  {
    return 2;
  }
}

// 0x1564350
u16 rstChkHeartsSkill(datUnitWork_t **pStock) {
  u64 *v3;
  datUnitWork_t_o *v5;
  u8 heartsequip;
  u16 HeartsSkill;
  u16 v12;
  datUnitWork_t_o *v13;

  v3 = Allocate(datUnitWork_t);
  datUnitWork_t___ctor(v3);
  v5 = *pStock;
  cmbCopyCustomDevilToStock(v3, v5);
  heartsequip = DDS3_GBWK->heartsequip;
  HeartsSkill = cmbChkGetHeartsSkill(heartsequip, v3);
  if (!HeartsSkill)
    return 0;
  v12 = HeartsSkill;
  if (HeartsSkill == 357 && !evtBitCheck(2241))
    return 0;
  v13 = *pStock;
  if ((cmbChkSkillOwner(v12, v13) & 0x80000000) == 0)
    return 0;
  if (GBWK->HeartsSkFlag >= GBWK->LevelUpCnt)
    return 0;
  else
    return v12;
}

// 0x155fb30
bool rstChkMotionEnd(void *obj, s32 index) {
  UnityEngine_Object_o *Animator;
  UnityEngine_Object_o *Component_GUILayer;

  if (op_Equality(obj, 0, 0))
    return 1;
  Animator = GetAnimator(obj);
  if (op_Equality(Animator, 0, 0))
    return 1;
  Component_GUILayer = GetComponent_GUILayer_(Animator);
  return op_Equality(Component_GUILayer, 0, 0)
      || IsRstMotionFinished(Component_GUILayer);
}

// 0x155f0b0
s8 rstChkMotionReq(void) {
  return (~GBWK->MotionReq >> 7) & 1;
}

// 0x1560b20
s32 rstChkParamLimitAll(datUnitWork_t *pStock, bool paramSet) {
  s32 ParamBase;
  s32 result;
  s32 v16;
  datUnitWork_t_o *pStocka;

  pStocka = pStock;
  ParamBase = cmbGetParamBase(&pStocka, 0);
  result = 0;
  if (ParamBase > 39)
  {
    if (cmbGetParamBase(&pStocka, 2) < 40)
    {
      return 0;
    }
    else
    {
      if (cmbGetParamBase(&pStocka, 3) < 40)
      {
        return 0;
      }
      else
      {
        if (cmbGetParamBase(&pStocka, 4) < 40)
        {
          return 0;
        }
        else
        {
          v16 = cmbGetParamBase(&pStocka, 5);
          result = v16 > 39;
          if (v16 >= 40 && paramSet)
          {
            rstSetMaxHpMp(0, &pStocka);
            return 1;
          }
        }
      }
    }
  }
  return result;
}

// 0x15631a0
s8 rstChkPartyDevilSkillPowerUp(void) {
  u64 v2;
  s32 v3;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v7;
  u32 flag;

  v2 = 0;
  v3 = 0;
  do
  {
    unitwork = DDS3_GBWK->unitwork;
    v7 = unitwork->m_Items[v2];
    flag = v7->flag;
    if ((flag & 7) == 3)
    {
      v3 |= (flag >> 6) & 1;
    }
    ++v2;
  }
  while (v2 != 16);
  return v3;
}

// 0x1562d10
s8 rstChkSkillPowerUp1(void) {
  struct datUnitWork_t_array *unitwork;

  unitwork = DDS3_GBWK->unitwork;
  if (unitwork->m_Items[0]->level < 7u)
    return 0;
  if (GBWK->pCurrentStock->id)
  {
    return (FCL_RAND() & 3) == 0;
  }
  else
  {
    FCL_RAND();
    return 1;
  }
}

// 0x1562e60
s8 rstChkSkillPowerUp2(void) {
  if (GBWK->pCurrentStock->id)
  {
    return FCL_RAND() % 0xFE > 0x7F;
  }
  else
  {
    return FCL_RAND() % 0xFE > 0x6F;
  }
}

// 0x1561450
void rstCreateBeforeSkillList(s8 HeartsID, datUnitWork_t *pStock, s16 SkillLevOfs, rstSkillInfo_t *pInfo) {
  s32 id;
  fclSkill_t_o *v11;
  s32 v12;
  s64 i;
  struct fclSkillParam_t_array *Event;
  u64 v15;
  s32 v17;
  _BOOL4 v18;
  _BOOL4 v19;
  struct fclSkillParam_t_array *v20;
  s32 v22;
  struct fclSkillParam_t_array *v23;
  u16 v25;
  struct System_Byte_array *TargetLevel;
  u32 SkillCnt;
  struct System_UInt16_array *SkillID;
  struct System_Byte_array *heartsskcnt;
  u8 v34;
  s64 v35;
  u32 v36;
  s64 v37;
  struct fclHearts_t_array *fclHeartsTbl;
  u64 v40;
  struct fclHeartsSkill_t_array *Skill;
  u8 v44;
  struct fclHearts_t_array *v45;
  struct fclHeartsSkill_t_array *v47;
  u16 v49;
  struct System_Byte_array *v50;
  u32 v52;
  struct System_UInt16_array *v53;

  if (pStock)
  {
    pInfo->SkillCnt = 0;
    id = pStock->id;
    if (pStock->id)
    {
      v11 = Get(id, 0);
      v12 = SkillLevOfs;
      for (i = 4; i != 28; ++i)
      {
        while (1)
        {
          Event = v11->Event;
          v15 = i - 4;
          v17 = *(*(&Event->obj.klass + i) + 17LL);
          v18 = v17 == 1;
          v19 = v17 == 6;
          if (!pStock->hensinmae)
            v19 = v18;
          if (v19)
          {
            v20 = v11->Event;
            v22 = *(*(&v20->obj.klass + i) + 16LL);
            if (pStock->level + v12 < v22)
            {
              v23 = v11->Event;
              v25 = *(*(&v23->obj.klass + i) + 18LL);
              {
              }
              if (cmbChkSkillOwner(v25, pStock) < 0)
                break;
            }
          }
          if (++i == 28)
            return;
        }
        TargetLevel = pInfo->TargetLevel;
        TargetLevel->m_Items[pInfo->SkillCnt] = v22;
        SkillCnt = pInfo->SkillCnt;
        SkillID = pInfo->SkillID;
        ++pInfo->SkillCnt;
        SkillID->m_Items[SkillCnt] = v25;
      }
    }
    else if (HeartsID)
    {
      heartsskcnt = DDS3_GBWK->heartsskcnt;
      v34 = heartsskcnt->m_Items[HeartsID];
      if ((v34 & 8) == 0)
      {
        v35 = HeartsID;
        v36 = HeartsID;
        v37 = (v34 & 0xF) + 4LL;
        do
        {
          while (1)
          {
            v40 = v37 - 4;
            Skill = fclHeartsTbl->m_Items[v35]->Skill;
            v44 = *(*(&Skill->obj.klass + v37) + 16LL);
            v45 = fclHeartsTbl;
            v47 = v45->m_Items[v35]->Skill;
            v49 = *(*(&v47->obj.klass + v37) + 18LL);
            if (v49)
            {
              {
              }
              if (cmbChkSkillOwner(v49, pStock) < 0)
                break;
            }
            ++v37;
            if (v40 > 6)
              return;
          }
          v50 = pInfo->TargetLevel;
          v50->m_Items[pInfo->SkillCnt] = v44;
          v52 = pInfo->SkillCnt;
          v53 = pInfo->SkillID;
          ++pInfo->SkillCnt;
          v53->m_Items[v52] = v49;
          ++v37;
        }
        while (v40 <= 6);
      }
    }
  }
}

// 0x1562b50
s8 rstGetDefaultSkill(void) {
  u16 EventParam;
  s8 result;
  u16 *p_EventParam;
  s32 v8;

  while (1)
  {
    p_EventParam = &GBWK->EventParam;
    v8 = rstCalcEventInfo(p_EventParam);
    if (v8 < 0)
      return 0;
    if (v8 == 1)
    {
      if (!GBWK->pCurrentStock->hensinmae)
      {
        EventParam = GBWK->EventParam;
        result = rstChkAddSkill(EventParam);
        if (result)
          return result;
        --GBWK->LevelUpCnt;
      }
    }
    else if (v8 == 6)
    {
      if (GBWK->pCurrentStock->hensinmae)
    }
  }
}

// 0x15602f0
s16 rstGetEquipHeartsAisyo(void) {
  s64 heartsequip;
  struct fclHearts_t_array *fclHeartsTbl;

  heartsequip = DDS3_GBWK->heartsequip;
  if (!heartsequip)
    return 0;
  return fclHeartsTbl->m_Items[heartsequip]->AisyoID;
}

// 0x1564880
void rstInitSkillAct(s8 Pos) {
  cmpStatSetTimer(0, 1);
  cmpStatSetSkillEffectPos(Pos);
  GBWK->MessageWait = 30;
  p2sdPlaySE(2818051);
}

// 0x1561290
void rstInitWorkStock(s8 IkenieChk) {
  datUnitWork_t_o *v3;
  struct rstData_t_o *GBWK;
  datUnitWork_t_o *pCurrentStock;
  datUnitWork_t_o *WorkStock;
  struct datUnitWork_t_o *v12;
  u16 id;

  v3 = Allocate(datUnitWork_t);
  datUnitWork_t___ctor(v3);
  GBWK->EventNums = 0;
  EventStart = 0;
  pCurrentStock = GBWK->pCurrentStock;
  WorkStock = GBWK->WorkStock;
  cmbCopyCustomDevilToStock(WorkStock, pCurrentStock);
  GBWK->WorkStock->level = GBWK->StartLevel
                                                                        + 1;
  if (IkenieChk)
  {
    v12 = GBWK->pCurrentStock;
    if ((v12->flag & 0x200) != 0)
    {
      id = v12->id;
      cmbCopyDefaultDevilToStock(id, v3);
      GBWK->WorkStock->level = v3->level;
    }
  }
}

// 0x1564860
void rstLoadHeartsSkill(s8 HeartsID, datUnitWork_t *pStock) {
  ;
}

// 0x155ef50
void rstModelPrep(void) {
  struct rstData_t_o *GBWK;
  s8 TargetCnt;
  s32 TargetPos;
  struct datUnitWork_t_array *pTargetList;
  s32 id;

  else
  {
    TargetCnt = GBWK->TargetCnt;
    if (!TargetCnt)
      return;
  }
  else
  {
    TargetPos = GBWK->TargetPos;
    if (TargetPos >= TargetCnt)
      return;
  }
  pTargetList = GBWK->pTargetList;
  GBWK->TargetPos = TargetPos + 1;
  id = pTargetList->m_Items[TargetPos]->id;
  cmpModelPrepare(6, id, 0);
}

// 0x155f1e0
void rstMotionReq(void) {
  u64 *v2;
  struct rstData_t_o *GBWK;
  s64 v7;
  f32 v10;
  f32 v11;
  struct rstData_t_o *v13;
  UnityEngine_GameObject_o *cmpMdlObj;
  s64 v16;
  bool v18;
  f32 v19;
  f32 v20;
  rstinit_c *v21;
  struct rstinit_StaticFields *static_fields;
  dds3ModelHandle_t_o **v23;
  s32 MotionReq;
  dds3ModelHandle_t_o **v27;
  s32 v28;
  f32 MotionReqAfterFrame;

  else if (cmpChkStatusModelLoadStat())
  {
    return;
  }
  v2 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v2);
  cmpGetStatusModelHandle();
  if ((GBWK->MotionReq & 0x80000000) == 0)
  {
    if (GBWK->pCurrentStock->id)
    {
      if (cmpGetStatusModelHandle())
      {
        v13 = GBWK;
        if (v13->MotionReqMode)
        {
          v18 = rstChkMotionEnd(cmpMdlObj, v7);
          if (v18)
          if (GBWK->MotionReqMode == 2)
          {
            static_fields = v21->static_fields;
            MotionReq = static_fields->GBWK->MotionReq;
            rstSmoothMotion(v23, v16, MotionReq, v19, v20);
            GBWK->MotionReq = -1;
            GBWK->MotionReqBeforeFrame = 0.0;
            GBWK->MotionReqAfterFrame = 0.0;
            GBWK->MotionReqMode = 0;
          }
        }
        else
        {
          v28 = v13->MotionReq;
          rstSmoothMotion(v27, v7, v28, v10, v11);
          MotionReqAfterFrame = GBWK->MotionReqAfterFrame;
          GBWK->MotionReq = 0;
          GBWK->MotionReqBeforeFrame = MotionReqAfterFrame;
          GBWK->MotionReqAfterFrame = 0.0;
          GBWK->MotionReqMode = 1;
        }
      }
    }
  }
}

// 0x1564f10
void rstPadActStart(void) {
  dds3PadAct(1u, 0xFFu, 0x1Eu);
}

// 0x15644f0
void rstRecalcHeartsSkill(u16 SkillID) {
}

// 0x1562f70
u16 rstRndGetPowerUpSkill(datUnitWork_t *pStock, s8 *pIdx) {
  u64 *v5;
  u64 *v6;
  u64 *v8;
  u64 v9;
  char v10;
  u16 PowerUpSkill;
  struct System_Int32_array *skill;
  s32 v15;
  s64 v16;
  s64 v19;

  v5 = NewSpecific(ushort, 0x18u);
  v6 = NewSpecific(sbyte, 0x18u);
  if (pStock->skillcnt < 1)
    return 0;
  v8 = v6;
  v9 = 0;
  v10 = 0;
  do
  {
    skill = pStock->skill;
    v15 = skill->m_Items[v9];
    if (v15)
    {
      else
      {
        PowerUpSkill = cmbGetPowerUpSkill(v15);
        if (!PowerUpSkill)
      }
      v16 = v10;
      *(v5 + v10 + 16) = PowerUpSkill;
      ++v10;
      *(v8 + v16 + 32) = v9;
    }
    ++v9;
  }
  while (v9 < pStock->skillcnt);
  if (!v10)
    return 0;
  v19 = (FCL_RAND() % v10);
  *pIdx = *(v8 + v19 + 32);
  return *(v5 + v19 + 16);
}

// 0x1561080
s8 rstSetCurrentDevil(void) {
  struct System_Int32_array *stocklist;
  struct rstData_t_o *GBWK;
  u32 v6;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v11;
  bool v14;
  s8 v17;

  do
  {
    while (1)
    {
      do
      {
        if (GBWK->TargetIndex > 15)
          return 0;
        stocklist = DDS3_GBWK->stocklist;
        v6 = GBWK->TargetIndex++;
        LODWORD(stocklist) = stocklist->m_Items[v6];
      }
      while ((stocklist & 0x80) != 0);
      unitwork = DDS3_GBWK->unitwork;
      v11 = unitwork->m_Items[stocklist];
        break;
      if (rstSetLevelUpCount(v11))
    }
  }
  while (!rstSetLevelUpCount(v11));
  v14 = rstChkParamLimitAll(v11, 1) == 0;
  if (v14)
    v17 = 1;
  else
    v17 = 2;
  GBWK->pCurrentStock = v11;
  return v17;
}

// 0x1560420
void rstSetDestroySkillMaxHpMp(void) {
    datUnitWork_t__Copy(0, 0);
    datGetMaxHp(0);
    datGetMaxMp(0);
}

// 0x1560ce0
s8 rstSetLevelUpCount(datUnitWork_t *pStock) {
  datUnitWork_t_o *v3;
  struct rstData_t_o *GBWK;
  struct rstData_t_o *v9;
  s16 LevelUpCnt;
  s16 v14;
  u16 id;
  s16 v17;
  u32 level;
  rstinit_c *v19;
  struct rstinit_StaticFields **p_static_fields;
  struct rstData_t_o *v21;
  s16 v22;
  datUnitWork_t_o *pStocka;

  pStocka = pStock;
  v3 = Allocate(datUnitWork_t);
  datUnitWork_t___ctor(v3);
  GBWK->StartLevel = pStock->level;
  GBWK->LevelUpCnt = cmbGetLevelUpCount(&pStocka, 0);
  v9 = GBWK;
  LevelUpCnt = v9->LevelUpCnt;
  v9->AsignParam = LevelUpCnt;
  v9->AsignParamMax = LevelUpCnt;
  SetPointAnime(GBWK->AsignParamMax);
  v14 = 0;
  if ((pStock->flag & 0x200) != 0)
  {
    id = pStock->id;
    cmbCopyDefaultDevilToStock(id, v3);
    v14 = pStock->level - v3->level;
  }
  v17 = GBWK->LevelUpCnt;
  level = pStock->level;
  if (level <= 0xFE)
    pStock->level = level + v17;
  if ((pStock->badstatus & 0x800) != 0)
    return 0;
  p_static_fields = &v19->static_fields;
  v21 = GBWK;
  v22 = v21->LevelUpCnt;
  if (!v22)
    return 0;
  v21->LevelUpCnt = v22 + v14;
  (*p_static_fields)->GBWK->StartLevel -= v14;
  rstSetMaxHpMp(0, &pStocka);
  return 1;
}

// 0x1560690
void rstSetMaxHpMp(s8 Mode, datUnitWork_t **pStock) {
  datUnitWork_t_o *v5;
  datUnitWork_t_o *v7;
  struct System_SByte_array *param;
  s8 v12;
  struct System_SByte_array *ParamOfs;
  struct System_SByte_array *v15;
  s8 v17;
  struct System_SByte_array *v19;
  struct System_SByte_array *v21;
  s8 v24;
  struct System_SByte_array *v25;
  struct System_SByte_array *v27;
  s8 v29;
  struct System_SByte_array *v31;
  struct System_SByte_array *v33;
  s8 v36;
  struct System_SByte_array *v37;
  struct System_SByte_array *v39;
  s8 v42;
  struct System_SByte_array *v43;
  datUnitWork_t_o *v45;
  datUnitWork_t_o *v46;
  u16 MaxMp;
  datUnitWork_t_o *v49;
  u16 MaxHp;
  datUnitWork_t_o *v51;
  u32 v52;
  u32 v53;

  v5 = Allocate(datUnitWork_t);
  datUnitWork_t___ctor(v5);
  v7 = *pStock;
  cmbCopyCustomDevilToStock(v5, v7);
  param = v5->param;
  v12 = param->m_Items[0];
  ParamOfs = GBWK->ParamOfs;
  param->m_Items[0] = ParamOfs->m_Items[0] + v12;
  v15 = v5->param;
  v17 = v15->m_Items[1];
  v19 = GBWK->ParamOfs;
  v15->m_Items[1] = v19->m_Items[1] + v17;
  v21 = v5->param;
  v24 = v21->m_Items[2];
  v25 = GBWK->ParamOfs;
  v21->m_Items[2] = v25->m_Items[2] + v24;
  v27 = v5->param;
  v29 = v27->m_Items[3];
  v31 = GBWK->ParamOfs;
  v27->m_Items[3] = v31->m_Items[3] + v29;
  v33 = v5->param;
  v36 = v33->m_Items[4];
  v37 = GBWK->ParamOfs;
  v33->m_Items[4] = v37->m_Items[4] + v36;
  v39 = v5->param;
  v42 = v39->m_Items[5];
  v43 = GBWK->ParamOfs;
  v39->m_Items[5] = v43->m_Items[5] + v42;
  if (Mode)
  if (!GBWK->RecoverFlag)
  {
    v45 = *pStock;
    v45->maxhp = datGetMaxHp(v5);
    v46 = *pStock;
    MaxMp = datGetMaxMp(v5);
  }
  else
  {
    v49 = *pStock;
    MaxHp = datGetMaxHp(v5);
    v49->hp = MaxHp;
    v49->maxhp = MaxHp;
    v46 = *pStock;
    MaxMp = datGetMaxMp(v5);
    v46->mp = MaxMp;
  }
  v46->maxmp = MaxMp;
  v51 = *pStock;
  v52 = (*pStock)->maxhp;
  if ((*pStock)->hp > v52)
  {
    v51->hp = v52;
    v51 = *pStock;
  }
  v53 = v51->maxmp;
  if (v51->mp > v53)
    v51->mp = v53;
}

// 0x155f130
void rstSetMotionReq(s8 MotionNo, f32 BeforeFrame, f32 AfterFrame, s8 Mode) {
  GBWK->MotionReq = MotionNo;
  GBWK->MotionReqBeforeFrame = BeforeFrame;
  GBWK->MotionReqAfterFrame = AfterFrame;
  GBWK->MotionReqMode = Mode;
}

// 0x155ffd0
void rstSetMotionReqFromTbl(s8 Type) {
  s32 id;
  s32 v6;
  struct rstMotionTbl_t_array *rstMotionTbl;
  u32 max_length;
  struct rstMotionTbl_t_array *v9;
  s8 MotionNo;
  u32 BeforeFrame;
  u32 AfterFrame;

  id = GBWK->pCurrentStock->id;
  v6 = 7 * id + Type;
  max_length = rstMotionTbl->max_length;
  v9 = rstMotionTbl;
  MotionNo = rstMotionTbl->m_Items[v6]->MotionNo;
  BeforeFrame = v9->m_Items[v6]->BeforeFrame;
  AfterFrame = v9->m_Items[v6]->AfterFrame;
  GBWK->MotionReq = MotionNo;
  GBWK->MotionReqBeforeFrame = BeforeFrame;
  GBWK->MotionReqAfterFrame = AfterFrame;
  GBWK->MotionReqMode = 0;
}

// 0x155fe40
void rstSmoothLoopMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, f32 aBeforeLeng, f32 aSmoothLeng) {
  evtUnitHandle_t_o *v10;
  dds3Basic_t_o *v11;
  evtUnitHandle_t_o *h;

  v10 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v10);
  h = v10;
  v11 = Allocate(dds3Basic_t);
  dds3Basic_t___ctor(v11);
  v10->Owner = v11;
  v11->gameObject = cmpMdlObj;
  mdlSmoothLoopMotionForUnity(&h, aGroup, aNumber, aBeforeLeng, aSmoothLeng, 0, 0);
}

// 0x155f580
void rstSmoothMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, f32 aBeforeLeng, f32 aSmoothLeng) {
  evtUnitHandle_t_o *v7;
  dds3Basic_t_o *v8;
  UnityEngine_Object_o *gameObject;
  UnityEngine_GameObject_o *v13;
  UnityEngine_Component_o *Animator;
  AnimCheckerBattle_o *Component_GUILayer;
  UnityEngine_GameObject_o *v19;
  s32 MotionNo;
  struct cmpStatusModel_t_array *tbl;
  s64 id;
  s32 v27;
  struct datUnitMotion_s_array *motion;
  s32 motion_no;
  s32 Integer;
  rstinit_c *v33;
  s16 v34;
  s32 v35;
  s32 v36;
  s32 v37;
  s32 v38;
  UnityEngine_Animator_o *v39;
  s32 v40;

  v7 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v7);
  v8 = Allocate(dds3Basic_t);
  dds3Basic_t___ctor(v8);
  v7->Owner = v8;
  v8->gameObject = cmpMdlObj;
  gameObject = v7->Owner->gameObject;
  if (!op_Equality(gameObject, 0, 0))
  {
    if (!get_activeSelf(v7->Owner->gameObject))
      SetActive(v7->Owner->gameObject, 1, 0);
    v13 = v7->Owner->gameObject;
    Animator = GetAnimator(v13);
    if (!op_Equality(Animator, 0, 0))
    {
      Component_GUILayer = GetComponent_GUILayer_(Animator);
      if (op_Equality(Component_GUILayer, 0, 0))
      {
        v19 = get_gameObject(Animator);
        Component_GUILayer = AddComponent_object_(v19);
        SetAnimator(Component_GUILayer, Animator, 0);
      }
      MotionNo = aNumber;
      if (!aNumber)
      {
        if (GBWK->pCurrentStock->id == 192)
        {
          MotionNo = 0;
        }
        else
        {
          id = GBWK->pCurrentStock->id;
          MotionNo = tbl->m_Items[id]->MotionNo;
        }
      }
      v27 = GBWK->pCurrentStock->id;
      motion = Get(v27, 0)->motion;
      motion_no = motion->m_Items[MotionNo]->motion_no;
      Integer = GetInteger(Animator, StringLiteral_4572);
      if (motion_no == 1)
      {
        v36 = GBWK->pCurrentStock->id;
        if (v36 == 60)
        if (v36 == 206)
        {
          v37 = 201;
          if ((v33->_2.bitflags2 & 2) != 0)
        }
        else
        {
          v37 = 101;
          if ((v33->_2.bitflags2 & 2) != 0)
        }
      }
      else
      {
        if (motion_no == 13)
        {
          if ((v34 & 0x200) != 0)
          {
            v35 = v34 & 0x200;
          }
          else
          {
            v35 = 0;
          }
          v38 = GBWK->pCurrentStock->id;
          if (v38 == 75)
            v37 = 313;
          else
            v37 = 113;
          if (v38 == 117)
            v37 = 213;
          if ((v33->_2.bitflags2 & 2) == 0)
        }
        v37 = motion_no + 100;
        {
        }
      }
      if (GBWK->pCurrentStock->id == 192 && !evtBitCheck(3712))
      {
        if (aNumber == 6)
        {
          v37 = 106;
        }
        else if ((aNumber - 7) <= 1)
        {
          v37 = 107;
        }
        else
        {
          v37 = 300;
        }
        if (GetInteger(Animator, StringLiteral_4572) == 13
          || !GetInteger(Animator, StringLiteral_4572))
        {
          Play_8777392(Animator, StringLiteral_21931);
        }
        motion_no = v37;
      }
      if (Integer != v37)
      {
        if (GetInteger(Animator, StringLiteral_4572))
        {
          v39 = Animator;
          v40 = v37;
        }
        else
        {
          v39 = Animator;
          v40 = motion_no;
        }
        SetInteger(v39, StringLiteral_4572, v40);
      }
      UpdateNormalizeTime(Component_GUILayer);
    }
  }
}

// 0x155fc60
void rstSmoothSingleMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, f32 aBeforeLeng, f32 aSmoothLeng) {
  evtUnitHandle_t_o *v10;
  dds3Basic_t_o *v11;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Component_o *Animator;
  UnityEngine_Object_o *Component_GUILayer;
  UnityEngine_GameObject_o *v20;
  evtUnitHandle_t_o *h;

  v10 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v10);
  h = v10;
  v11 = Allocate(dds3Basic_t);
  dds3Basic_t___ctor(v11);
  v10->Owner = v11;
  v11->gameObject = cmpMdlObj;
  gameObject = v10->Owner->gameObject;
  Animator = GetAnimator(gameObject);
  if (!op_Equality(Animator, 0, 0))
  {
    Component_GUILayer = GetComponent_GUILayer_(Animator);
    if (op_Equality(Component_GUILayer, 0, 0))
    {
      v20 = get_gameObject(Animator);
      AddComponent_object_(v20);
    }
    mdlSmoothSingleMotionForUnity(&h, aGroup, aNumber, aBeforeLeng, aSmoothLeng, 0);
  }
}

// 0x1564870
void rstStoreHeartsSkill(s8 HeartsID, datUnitWork_t *pStock) {
  ;
}
