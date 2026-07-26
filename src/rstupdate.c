#include "types.h"

typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

static s32 CMP_PANELEFFCOL_START_NOTARGET2;
static s32 CMP_PANELEFFCOL_END_NOTARGET2;
static void *statusCharaObj;
static f32 movePos;
static sdfVector3_t startPos;
static dds3ProcessID_t *thAibo;
static s32 gAiboX;
static s32 gAiboMode;
static s32 raidou_msg2;
static void *canvUI;

bool DDS3_PADCHECK_TRIG(s32 id);
u8 Get(s32 id);
bool IsFadeOutWindow(void);
bool IsSelectWindowDispOff(void);
void SetPointAnime(s32 point);
s32 datAddHearts(s32 id);
void datAddItem(s32 id, s32 num);
void datOverwriteBadStat(datUnitWork_t *work, u32 badstat);
s32 dds3FadeCheck(void);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void *dds3GetProcessData(dds3ProcessID_t **id);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void draw_status_off(bool sw);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtFreeStage(void);
void evtKillPictureProcess(dds3ProcessID_t *id);
void evtPictureDrawOn(dds3ProcessID_t *id);
void evtPictureSetAlpha(dds3ProcessID_t *id, s32 alp0, s32 alp1, s32 time);
void evtPictureSetPos(dds3ProcessID_t *id, s32 x0, s32 y0, s32 x1, s32 y1, s32 time);
void evtPictureSetSize(dds3ProcessID_t *id, s32 sw, s32 sh, s32 tw, s32 th);
dds3ProcessID_t *evtStartPictureProcess(s32 priority, char *texpath);
s8 fclChkMessage(void);
s8 fclChkSelMessage(void);
s8 fclChkSignal(s8 Idx);
s32 fclEncycRegist(datUnitWork_t *punit, s32 overwrite, bool update);
s8 fclEndMessage(void);
void fclFilterOFF(void);
void fclFreeStage(void);
s8 fclGetSelMessagePos(void);
void fclSetMessageVar_20743088(s8 Index, char *pStr);
s8 fclSetVal(s8 Idx, s32 Val);
s8 fclStartMessage(s32 MsgNo);
s8 fclStartSelMessage(s32 SelMsgNo);
void fclUpdateMessage(void);
s32 p2sdPlaySE(s32 a);
void rstAddAsignParam(datUnitWork_t **pStock);
void rstAddSkill(void);
u16 rstChkHeartsSkill(datUnitWork_t **pStock);
s8 rstChkSkillAct(void);
u16 rstGetCursorPosSkillID(datUnitWork_t **pStock, cmpCursorInfo_t **pCursorInfo);
s8 rstGetHeartsSkill(s8 Mode);
void rstInitSkillAct(s8 Pos);
void rstOverWriteSkill(s32 *pSkill, u16 NewSkillID);
s8 rstReplaceSkill(void);
void rstResetAsignParam(void);
void rstSetHeartsEvent(s8 EventType);
void rstSetHeartsRecover(void);
void rstSetMaxHpMp(s8 Mode, datUnitWork_t **pStock);
void rstSetMotionReqFromTbl(s8 Type);
s32 rstStandbyHeartsAddPoint(void);
s8 rstStandbyHeartsEvent(s8 EventType);
s8 rstStandbyHeartsSkillPowerUp(void);
void rstStartEvoActSE(void);
void rstStartIntroduce(u16 DevilID);
void rstUpdateEvoBgFade(void);
void rstUpdateSeqAsignPlayerParam(datUnitWork_t **pStock);
s8 rstUpdateSeqConfirm(void);
void rstUpdateSeqDefaultSkill(void);
s8 rstUpdateSeqDestroyConfirm(void);
s8 rstUpdateSeqDestroySkill(void);
void rstUpdateSeqDevilParam(void);
void rstUpdateSeqEvo(void);
void rstUpdateSeqEvoAct(void);
void rstUpdateSeqEvoAt(void);
void rstUpdateSeqGift(void);
void rstUpdateSeqHeartsEvent(void);
void rstUpdateSeqHeartsMaster(void);
void rstUpdateSeqHeartsSkill(void);
void rstUpdateSeqPlayerLevelUpOnly(void);
void rstUpdateSeqSkillPowerUp(void);

// 0x1569ba0
void rstAddAsignParam(datUnitWork_t **pStock) {
  struct System_SByte_array *param;
  s8 v6;
  struct System_SByte_array *ParamOfs;
  struct System_SByte_array *v9;
  s8 v11;
  struct System_SByte_array *v13;
  struct System_SByte_array *v15;
  s8 v18;
  struct System_SByte_array *v19;
  struct System_SByte_array *v21;
  s8 v23;
  struct System_SByte_array *v25;
  struct System_SByte_array *v27;
  s8 v30;
  struct System_SByte_array *v31;
  struct System_SByte_array *v33;
  s8 v36;
  struct System_SByte_array *v37;

  param = (*pStock)->param;
  v6 = param->m_Items[0];
  ParamOfs = GBWK->ParamOfs;
  param->m_Items[0] = ParamOfs->m_Items[0] + v6;
  v9 = (*pStock)->param;
  v11 = v9->m_Items[1];
  v13 = GBWK->ParamOfs;
  v9->m_Items[1] = v13->m_Items[1] + v11;
  v15 = (*pStock)->param;
  v18 = v15->m_Items[2];
  v19 = GBWK->ParamOfs;
  v15->m_Items[2] = v19->m_Items[2] + v18;
  v21 = (*pStock)->param;
  v23 = v21->m_Items[3];
  v25 = GBWK->ParamOfs;
  v21->m_Items[3] = v25->m_Items[3] + v23;
  v27 = (*pStock)->param;
  v30 = v27->m_Items[4];
  v31 = GBWK->ParamOfs;
  v27->m_Items[4] = v31->m_Items[4] + v30;
  v33 = (*pStock)->param;
  v36 = v33->m_Items[5];
  v37 = GBWK->ParamOfs;
  v33->m_Items[5] = v37->m_Items[5] + v36;
}

// 0x15695b0
void rstAddSkill(void) {
  rstinit_c *v2;
  s16 v3;
  s32 v4;
  struct rstData_t_o *GBWK;
  u16 GetHeartsSkill;
  datUnitWork_t_o *pCurrentStock;
  s32 v10;
  datUnitWork_t_o *v12;
  datUnitWork_t_o **p_pCurrentStock;

  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
  }
  else
  {
    v4 = 0;
  }
  if (!GBWK->pCurrentStock->id)
  {
    else
    {
      GetHeartsSkill = GBWK->GetHeartsSkill;
      if ((v2->_2.bitflags2 & 2) == 0)
    }
  }
  GetHeartsSkill = GBWK->EventParam;
  --GBWK->LevelUpCnt;
  pCurrentStock = GBWK->pCurrentStock;
  cmbAddSkill(GetHeartsSkill, pCurrentStock);
  v10 = cmbChkKeisyoSkillOwner(GetHeartsSkill, GBWK->pCurrentStock);
  if ((v10 & 0x80000000) == 0)
  {
    v12 = GBWK->pCurrentStock;
    cmbDeleteKeisyoSkill(v12, v10);
  }
  p_pCurrentStock = &GBWK->pCurrentStock;
  rstSetMaxHpMp(1, p_pCurrentStock);
}

// 0x1569940
s8 rstChkSkillAct(void) {
  rstinit_c *v4;
  s16 v5;
  s32 v6;
  struct rstData_t_o *GBWK;
  s32 MessageWait;

  if (GBWK->MessageWait < 1)
    return 0;
  else if (DDS3_PADCHECK_TRIG(1))
  {
    cmpStatResetFlashFlag(1);
    GBWK->MessageWait = 1;
    v5 = *&v4->_2.bitflags1;
    if ((v5 & 0x200) != 0)
  }
  if ((v5 & 0x200) != 0)
  {
    v6 = v5 & 0x200;
  }
  v6 = 0;
  MessageWait = GBWK->MessageWait;
  if (MessageWait == 1)
  {
    GBWK->MessageWait = 0;
    return 2;
  }
  else
  {
    GBWK->MessageWait = MessageWait - 1;
    return 1;
  }
}

// 0x1566f10
u16 rstGetCursorPosSkillID(datUnitWork_t **pStock, cmpCursorInfo_t **pCursorInfo) {
  cmpCursorInfo_t_o *v5;
  char CursorIndex;
  struct System_Int32_array *skill;
  s32 v10;
  s16 v12;
  s32 v13;
  struct rstData_t_o *GBWK;

  v5 = *pCursorInfo;
  CursorIndex = cmpGetCursorIndex(v5);
  if ((*pStock)->skillcnt <= CursorIndex)
  {
    if ((v12 & 0x200) != 0)
    {
      v13 = v12 & 0x200;
    }
    else
    {
      v13 = 0;
    }
    if (GBWK->pCurrentStock->id)
    {
      LOWORD(v10) = GBWK->EventParam;
    }
    else
    {
      LOWORD(v10) = GBWK->GetHeartsSkill;
    }
  }
  else
  {
    skill = (*pStock)->skill;
    return skill->m_Items[CursorIndex];
  }
  return v10;
}

// 0x156e3f0
s8 rstGetHeartsSkill(s8 Mode) {
    rstChkHeartsSkill(0);
    return 0;
}

// 0x1569470
void rstOverWriteSkill(s32 *pSkill, u16 NewSkillID) {
  datUnitWork_t_o **p_pCurrentStock;
  struct UnityEngine_GameObject_array *obtainedObj;
  s64 PUpSkillIndex;
  Il2CppObject *Component_object;

  *pSkill = NewSkillID;
  p_pCurrentStock = &GBWK->pCurrentStock;
  rstSetMaxHpMp(1, p_pCurrentStock);
  obtainedObj = _statusUIScr->obtainedObj;
  PUpSkillIndex = GBWK->PUpSkillIndex;
  Component_object = GetComponent_object_(obtainedObj->m_Items[PUpSkillIndex]);
  SetInteger(Component_object, StringLiteral_12358, 2);
}

// 0x15697d0
s8 rstReplaceSkill(void) {
  struct datUnitWork_t_o *pCurrentStock;
  s8 v4;
  s64 v5;
  struct System_Int32_array *skill;
  struct System_Int32_array *v8;
  s32 v10;
  struct System_Int32_array *v11;
  s64 v13;
  s64 v14;

  pCurrentStock = GBWK->pCurrentStock;
  if (pCurrentStock->skillcnt < 1)
  {
    v4 = 0;
  }
  else
  {
    v4 = 0;
    v5 = 8;
    do
    {
      skill = pCurrentStock->skill;
      if (*(&skill->obj.klass + v5))
      {
        v8 = pCurrentStock->skill;
        v10 = *(&v8->obj.klass + 2 * v5);
        *(&pCurrentStock->skill->obj.klass + v5) = 0;
        v11 = pCurrentStock->skill;
        v13 = v11 + 4 * v4++;
        *(v13 + 32) = v10;
      }
      v14 = v5 - 7;
      ++v5;
    }
    while (v14 < pCurrentStock->skillcnt);
  }
  pCurrentStock->skillcnt = v4;
  return v4;
}

// 0x1569b00
void rstResetAsignParam(void) {
  struct System_SByte_array *ParamOfs;

  GBWK->AsignParam = GBWK->AsignParamMax;
  ParamOfs = GBWK->ParamOfs;
  Clear(ParamOfs, 0, ParamOfs->max_length, 0);
  SetPointAnime(GBWK->AsignParam);
}

// 0x156fef0
void rstSetHeartsEvent(s8 EventType) {
    datOverwriteBadStat(0, 0);
    rstSetHeartsRecover();
}

// 0x156f750
void rstSetHeartsRecover(void) {
}

// 0x156f8d0
void rstSetHeartsRecoverPlayer(void) {
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v5;

  unitwork = DDS3_GBWK->unitwork;
  v5 = unitwork->m_Items[0];
  v5->hp = v5->maxhp;
  v5->mp = v5->maxmp;
  v5->badstatus &= 0x8000u;
}

// 0x156f150
s32 rstStandbyHeartsAddPoint(void) {
  u64 *v1;
  datUnitWork_t_o *pCurrentStock;
  s32 v9;
  datUnitWork_t_o **p_pCurrentStock;
  struct System_SByte_array *ParamOfs;
  datUnitWork_t_o **v18;
  s32 v19;
  datUnitWork_t_o *pStock;

  v1 = Allocate(datUnitWork_t);
  datUnitWork_t___ctor(v1);
  pStock = v1;
  pCurrentStock = GBWK->pCurrentStock;
  cmbCopyCustomDevilToStock(v1, pCurrentStock);
  v9 = cmbAddLevelUpParamEx(&pStock, 0);
  if (v9 < 0)
    return 0;
  p_pCurrentStock = &GBWK->pCurrentStock;
  if (cmbGetParamBase(p_pCurrentStock, v9) > 39)
    return 0;
  ParamOfs = GBWK->ParamOfs;
  ParamOfs->m_Items[v9] = 1;
  GBWK->HeartsEventData = v9;
  v18 = &GBWK->pCurrentStock;
  v19 = 1;
  rstSetMaxHpMp(1, v18);
  return v19;
}

// 0x156f980
s8 rstStandbyHeartsEvent(s8 EventType) {
  s32 heartsequip;
  System_String_o *v8;
  u16 HeartsEventData;
  System_String_o *ParamName;
  u16 id;
  u16 v18;
  u32 v19;
  u16 v22;
  u16 v25;
  s32 v27;
  struct rstData_t_o *GBWK;
  rstupdate_c *v32;
  u32 *static_fields;
  u32 v34;
  u32 EndCol;

  GBWK->PanelEffID = -1;
  switch (EventType)
  {
    case 0:
      if (rstStandbyHeartsAddPoint())
      {
        heartsequip = DDS3_GBWK->heartsequip;
        v8 = Get(heartsequip, 0);
        fclSetMessageVar_20743088(12, v8);
        HeartsEventData = GBWK->HeartsEventData;
        ParamName = cmpGetParamName(HeartsEventData);
        fclSetMessageVar_20743088(8, ParamName);
        fclSetMessageVar_20743088(9, StringLiteral_1525);
        fclStartMessage(30);
        if (EventType != 7)
      }
    case 1:
      if (rstStandbyHeartsSkillPowerUp())
      return 0;
    case 2:
      fclStartMessage(33);
      id = GBWK->pCurrentStock->id;
      v18 = id;
      v19 = 64;
    case 3:
      fclStartMessage(34);
      v22 = GBWK->pCurrentStock->id;
      v18 = v22;
      v19 = 256;
    case 4:
      fclStartMessage(35);
      v25 = GBWK->pCurrentStock->id;
      v18 = v25;
      v19 = 0x8000;
      cmpBadEffSetup(v18, v19);
    case 5:
      v27 = 36;
    case 6:
      v27 = 37;
      fclStartMessage(v27);
      p2sdPlaySE(16);
      static_fields = v32->static_fields;
      v34 = *static_fields;
      EndCol = static_fields[1];
      GBWK->PanelEffID = cmpAddQuePanelEff(0, 0, 0, 0, 0, 8u, 0, v34, EndCol, 4u);
      if (EventType == 7)
    default:
      fclStartMessage(38);
      {
      }
      GBWK->SeqInfo->MesFlag = 1;
      return 1;
  }
}

// 0x156f370
s8 rstStandbyHeartsSkillPowerUp(void) {
  s32 v3;
  s32 PUpSkillResult;
  s32 v6;
  struct rstData_t_o *GBWK;
  struct datUnitWork_t_o *pCurrentStock;
  u32 PUpSkillIndex;
  struct System_Int32_array *skill;
  s32 v12;
  System_String_o *v14;
  System_String_o *v15;
  struct rstinit_StaticFields *static_fields;
  struct rstData_t_o *v19;
  s32 v20;
  s8 v21;
  s64 v22;
  u16 PUpSkillID;
  struct System_Int32_array *v24;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct System_UInt16_array_array *hearts_sk;
  s64 heartsequip;
  System_UInt16_array *v32;
  struct rstData_t_o *v33;
  s8 v35;

  v3 = rstChkSkillAct();
  if (v3 == 1)
    return 0;
  if (v3 == 2)
  {
    PUpSkillResult = GBWK->PUpSkillResult;
    if (PUpSkillResult == 2)
    {
      v6 = 32;
    }
    else
    {
      if (PUpSkillResult != 1)
      v6 = 31;
    }
    fclStartMessage(v6);
    cmpStatResetFlashFlag(1);
    GBWK->PUpSkillResult = -1;
    return 1;
  }
  pCurrentStock = GBWK->pCurrentStock;
  PUpSkillIndex = GBWK->PUpSkillIndex;
  skill = pCurrentStock->skill;
  v12 = skill->m_Items[PUpSkillIndex];
  v14 = Get(v12, 0, 0);
  fclSetMessageVar_20743088(15, v14);
  v15 = Get(GBWK->PUpSkillID, 0, 0);
  fclSetMessageVar_20743088(16, v15);
  static_fields = rstinit->static_fields;
  v19 = static_fields->GBWK;
  v20 = static_fields->GBWK->PUpSkillResult;
  if (v20 == 2 || (v21 = 0, v20 == 1))
  {
    v22 = v19->PUpSkillIndex;
    PUpSkillID = v19->PUpSkillID;
    v24 = v19->pCurrentStock->skill;
    rstOverWriteSkill(&v24->m_Items[v22], PUpSkillID);
    hearts_sk = DDS3_GBWK->hearts_sk;
    heartsequip = DDS3_GBWK->heartsequip;
    v32 = hearts_sk->m_Items[heartsequip];
    v33 = GBWK;
    v32->m_Items[v33->PUpSkillIndex] = v33->PUpSkillID;
    v35 = GBWK->PUpSkillIndex;
    rstInitSkillAct(v35);
    return 0;
  }
  return v21;
}

// 0x156ca50
void rstStartEvoActSE(void) {
  rstinit_c *v2;
  struct rstinit_StaticFields **p_static_fields;
  struct rstData_t_o *GBWK;
  s32 EvoActFrame;

  p_static_fields = &v2->static_fields;
  EvoActFrame = GBWK->EvoActFrame;
  if ((EvoActFrame & 0x80000000) == 0)
  {
    GBWK->EvoActFrame = EvoActFrame + 1;
    if ((*p_static_fields)->GBWK->EvoActFrame == 40)
    {
      p2sdPlaySE(2818049);
      GBWK->EvoActFrame = -1;
    }
  }
}

// 0x156c740
void rstStartIntroduce(u16 DevilID) {
  System_String_o *v4;
  s32 race;
  System_String_o *v8;
  s32 v10;
  u32 kucyo;

  v4 = Get(DevilID, 0);
  fclSetMessageVar_20743088(0, v4);
  race = Get(DevilID, 1, 0)->race;
  v8 = Get(race, 0, 0);
  fclSetMessageVar_20743088(4, v8);
  if (DevilID == 207)
  {
    v10 = 198;
  }
  else
  {
    kucyo = Get(DevilID, 0)->kucyo;
    v10 = kucyo + 168;
  }
  fclStartMessage(v10);
}

// 0x1571000
dds3ProcessFunc_t *rstUpdate(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    dds3FadeCheck();
    rstUpdateSeqAsignPlayerParam(0);
    rstUpdateSeqPlayerLevelUpOnly();
    rstUpdateSeqHeartsSkill();
    rstUpdateSeqHeartsEvent();
    rstUpdateSeqHeartsMaster();
    rstUpdateSeqDevilParam();
    rstUpdateSeqDefaultSkill();
    rstUpdateSeqSkillPowerUp();
    fclChkMessage();
    rstUpdateSeqGift();
    rstUpdateSeqEvo();
    rstUpdateSeqEvoAt();
    rstUpdateSeqEvoAct();
    rstUpdateSeqDestroySkill();
    rstUpdateSeqDestroyConfirm();
    rstUpdateSeqConfirm();
    fclUpdateMessage();
    rstUpdateEvoBgFade();
    return 0;
}

// 0x1570f50
void rstUpdateBgTimer(void) {
  struct rstData_t_o *GBWK;

  ++GBWK->BgTimer;
  if (GBWK->BgTimer >= 0x900)
  {
    GBWK->BgTimer = 0;
  }
}

// 0x156c8e0
void rstUpdateEvoBgFade(void) {
  s16 v3;
  s32 v4;
  struct rstData_t_o *GBWK;
  u32 EvoBgFade;

  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
  }
  else
  {
    v4 = 0;
  }
  if (GBWK->SeqInfo->Current != 20)
  {
    if (v4)
    {
      v4 = 0;
    }
  }
  else
  {
    EvoBgFade = GBWK->EvoBgFade;
    if (EvoBgFade > 0x31)
  }
  GBWK->EvoBgFade = EvoBgFade + 1;
  if (GBWK->EvoBgFade >= 0x33)
  {
    v4 = 50;
    GBWK->EvoBgFade = v4;
  }
}

// 0x1566490
void rstUpdateNewParam(void) {
    rstAddAsignParam(0);
}

// 0x1569ef0
void rstUpdateSeqAsignPlayerParam(datUnitWork_t **pStock) {
  u16 v4;
  u64 *v6;
  s8 CursorIndex;
  u64 v11;
  s32 v12;
  s32 ParamBase;
  struct System_SByte_array *ParamOfs;
  s32 v17;
  struct rstData_t_o *GBWK;
  UnityEngine_GameObject_o *v25;
  UnityEngine_GameObject_o *stsCursor;
  u16 v30;
  cmpCursorInfo_t_o *v32;
  cmpCursorInfo_t_o *v33;
  s8 v34;
  cmpCursorInfo_t_o *ParamCursor;
  s32 v40;
  struct statusUI_o *statusUIScr;
  UnityEngine_GameObject_o *v43;
  UnityEngine_GameObject_array *ObjStsBar;
  struct System_SByte_array *v46;
  struct System_SByte_array *v49;
  struct rstData_t_o *v52;
  s16 v53;
  struct rstData_t_o *v55;
  struct System_SByte_array *v56;
  cmpCursorInfo_t_o *v61;
  cmpCursorInfo_t_o *v63;
  u16 v64;
  s8 v65;

  v4 = cmpChkCommonInput(CMP_PE_NORMAL | 0xC0);
  v6 = NewSpecific(s32, 6u);
  CursorIndex = cmpGetCursorIndex(GBWK->ParamCursor);
  v65 = cmpExchgParamIndex(CursorIndex);
  v11 = 0;
  v12 = 1;
  do
  {
    if (v11 != 1)
    {
      ParamBase = cmbGetParamBase(pStock, v11);
      ParamOfs = GBWK->ParamOfs;
      v17 = ParamBase + ParamOfs->m_Items[v11];
      *(v6 + v11 + 8) = v17;
      if (v17 <= 39)
        v12 = 0;
    }
    ++v11;
  }
  while (v11 != 6);
  else
  {
    if (v12)
  }
  if (GBWK->AsignParam)
  {
    else if (fclChkMessage())
    {
      return;
    }
    stsCursor = _statusUIScr->stsCursor;
    cmpSetupObject(stsCursor, 1);
    if (v4 > 0x10u)
    {
      v30 = v4;
      if (v4 == 32)
      {
        ParamCursor = GBWK->ParamCursor;
        v33 = ParamCursor;
        v34 = 1;
      }
      if (v4 == 64)
      {
        v46 = GBWK->ParamOfs;
        if (v46->m_Items[v65] < 1)
        v49 = GBWK->ParamOfs;
        --v49->m_Items[v65];
        v52 = GBWK;
        v53 = v52->AsignParam + 1;
        v52->AsignParam = v53;
        SetPointAnime(GBWK->AsignParam);
      }
      if (v4 != 128)
    }
    else
    {
      v30 = v4;
      if (v4 != 1)
      {
        if (v4 == 2)
        {
          rstResetAsignParam();
        }
        if (v4 == 16)
        {
          v32 = GBWK->ParamCursor;
          v33 = v32;
          v34 = -1;
          cmpMoveCursor(v33, v34);
          v40 = cmpGetCursorIndex(GBWK->ParamCursor);
          statusUIScr = _statusUIScr;
          v43 = statusUIScr->stsCursor;
          ObjStsBar = statusUIScr->ObjStsBar;
          cmpMenuCursor(v40, v43, ObjStsBar);
        }
        rstSetMaxHpMp(0, pStock);
        if (!cmpChkPadPressUpDown())
        {
          v61 = GBWK->ParamCursor;
          cmpMoveCursor(v61, 0);
        }
        v63 = GBWK->ParamCursor;
        v64 = cmpDisablePadBitStop(v63, v30, 0x30u);
        cmpPlaySE(v64);
        return;
      }
    }
    if (*(v6 + v65 + 8) > 39)
    {
      v30 = 0x8000;
    }
    v55 = GBWK;
    if (v55->AsignParam < 1)
    v56 = v55->ParamOfs;
    ++v56->m_Items[v65];
    v52 = GBWK;
    v53 = v52->AsignParam - 1;
  }
  GBWK->AsignParam = 0;
  fclStartMessage(2);
  fclStartSelMessage(43);
  GBWK->SeqInfo->Current = 24;
  GBWK->SeqInfo->Change = 1;
  v25 = _statusUIScr->stsCursor;
  cmpSetupObject(v25, 0);
}

// 0x156db60
s8 rstUpdateSeqConfirm(void) {
  s32 SelMessagePos;
  datUnitWork_t_o **p_pCurrentStock;
  struct System_SByte_array *ParamOfs;
  UnityEngine_GameObject_o *lvUpBase;

  else if (fclChkSelMessage())
  {
    return 0;
  }
  SelMessagePos = fclGetSelMessagePos();
  if (SelMessagePos <= 1)
  {
    if (SelMessagePos)
    {
      if (SelMessagePos == 1)
      {
        rstResetAsignParam();
        fclEndMessage();
        GBWK->SeqInfo->Current = 0;
        GBWK->SeqInfo->Change = 2;
      }
    }
    else
    {
      p_pCurrentStock = &GBWK->pCurrentStock;
      rstAddAsignParam(p_pCurrentStock);
      ParamOfs = GBWK->ParamOfs;
      Clear(ParamOfs, 0, ParamOfs->max_length, 0);
      fclEndMessage();
      GBWK->SeqInfo->Current = 1;
      GBWK->SeqInfo->Change = 1;
      lvUpBase = _statusUIScr->lvUpBase;
      cmpSetupObject(lvUpBase, 0);
    }
  }
  return 1;
}

// 0x156bd00
void rstUpdateSeqDefaultSkill(void) {
    rstChkSkillAct();
    fclChkMessage();
    fclEndMessage();
    fclStartMessage(0);
    rstAddSkill();
    Get(0);
    fclSetMessageVar_20743088(0, 0);
}

// 0x156e730
s8 rstUpdateSeqDestroyConfirm(void) {
    fclStartMessage(0);
    fclChkMessage();
    fclChkSelMessage();
    fclGetSelMessagePos();
    fclEndMessage();
    rstGetHeartsSkill(0);
    rstReplaceSkill();
    rstAddSkill();
    rstSetMaxHpMp(0, 0);
    Get(0);
    fclSetMessageVar_20743088(0, 0);
    return 0;
}

// 0x156de40
s8 rstUpdateSeqDestroySkill(void) {
  u16 v4;
  u8 CursorIndex;
  u32 v11;
  cmpCursorInfo_t_o *v13;
  cmpCursorInfo_t_o *v16;
  cmpCursorInfo_t_o *v17;
  s8 v18;
  struct rstData_t_o *GBWK;
  s32 SelectSkillID;
  System_String_o *v26;
  cmpCursorInfo_t_o *SkillCursor;
  cmpCursorInfo_t_o *v33;
  struct cmpCursorPos_t_o *CursorPos;
  struct cmpCursorPos_t_o *v37;
  cmpCursorInfo_t_o *v39;

  v4 = cmpChkCommonInput(CMP_PE_NORMAL | 0xC0);
  CursorIndex = cmpGetCursorIndex(GBWK->SkillCursor);
  else if (fclChkMessage())
  {
    return 0;
  }
  v11 = v4;
  if (v4 > 0x10u)
  {
    if (v4 == 32)
    {
      SkillCursor = GBWK->SkillCursor;
      if (cmpGetCursorIndex(SkillCursor) == 8)
        return 0;
      v33 = GBWK->SkillCursor;
      v17 = v33;
      v18 = 1;
    }
    if (v4 != 64)
    {
      if (v4 != 128)
      if (CursorIndex > 7u)
      {
        GBWK->SkillCursor->CursorPos->Shift = 0;
      }
      if (CursorIndex <= 3u)
      {
        CursorPos = GBWK->SkillCursor->CursorPos;
        CursorPos->Shift += 4;
      }
      GBWK->SkillCursor->CursorPos->Shift = 8;
      if (!cmpChkPadPressUpDown())
    }
    if (CursorIndex <= 7u)
    {
      if (CursorIndex <= 3u)
      {
        v37 = GBWK->SkillCursor->CursorPos;
        v37->Shift -= 4;
      }
    }
    else
    {
    }
  }
  if (v4 == 1)
  {
    GBWK->SelectSkillID = rstGetCursorPosSkillID(&GBWK->pCurrentStock, &GBWK->SkillCursor);
    SelectSkillID = GBWK->SelectSkillID;
    v26 = Get(SelectSkillID, 0, 0);
    fclSetMessageVar_20743088(10, v26);
    fclStartMessage(8);
    fclStartSelMessage(43);
    GBWK->SeqInfo->Current = 22;
    GBWK->SeqInfo->Change = 1;
  }
  if (v4 == 2)
    return 0;
  v13 = GBWK->SkillCursor;
  if (cmpGetCursorIndex(v13) == 8)
    return 0;
  v16 = GBWK->SkillCursor;
  v17 = v16;
  v18 = -1;
  cmpMoveCursor(v17, v18);
  if (!cmpChkPadPressUpDown())
  {
    v39 = GBWK->SkillCursor;
    cmpMoveCursor(v39, 0);
  }
  cmpPlaySE(v11);
  return 1;
}

// 0x156a8a0
void rstUpdateSeqDevilParam(void) {
    fclChkMessage();
    Get(0);
    fclSetMessageVar_20743088(0, 0);
    fclStartMessage(0);
    rstSetMaxHpMp(0, 0);
}

// 0x156d2c0
void rstUpdateSeqEvo(void) {
  struct rstData_t_o *GBWK;
  s32 Flag;
  s32 id;
  System_String_o *v11;
  s32 SelMessagePos;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v22;
  UnityEngine_GameObject_o *v24;
  UnityEngine_Transform_o *v26;
  struct rstData_t_o *v27;
  char v28;

  Flag = GBWK->Flag;
  if (Flag < 1)
  if (Flag == 3)
  {
    if (!fclChkMessage())
    {
      if (!dds3SearchProcessName(StringLiteral_21934))
      {
        evtBitOff(3717);
        fclFreeStage();
        GBWK->EvoFlag = -1;
        GBWK->SeqInfo->Change = 1;
      }
    }
    return;
  }
  if (Flag == 2)
  {
    id = GBWK->pCurrentStock->id;
    v11 = Get(id, 0);
    fclSetMessageVar_20743088(1, v11);
    fclStartMessage(23);
  }
  if (Flag != 1)
  fclStartMessage(22);
  GBWK->SeqInfo->MesFlag = 1;
  GBWK->Flag = 3;
  else if (fclChkSelMessage())
  {
    return;
  }
  SelMessagePos = fclGetSelMessagePos();
  if (SelMessagePos <= 1)
  {
    if (SelMessagePos == 1)
    {
      fclEndMessage();
      fclSetVal(1, 1);
      fclSetVal(2, 0);
      cmpModelInitCore2();
      v27 = GBWK;
      v28 = 2;
    }
    if (!SelMessagePos)
    {
      fclEndMessage();
      GBWK->MotionReqMode = 2;
      GBWK->SeqInfo->Current = 20;
      GBWK->SeqInfo->Change = 1;
      fclSetVal(1, 0);
      fclSetVal(2, 0);
      draw_status_off(1);
      gameObject = get_gameObject(_statusUIScr);
      transform = get_transform(gameObject, 0);
      v22 = Find(transform, StringLiteral_16220, 0);
      v24 = get_gameObject(v22);
      statusCharaObj = v24;
      v26 = get_transform(statusCharaObj, 0);
      startPos = get_localPosition(v26);
      v27 = GBWK;
      v28 = 1;
      v27->Flag = v28;
    }
  }
}

// 0x156cb60
void rstUpdateSeqEvoAct(void) {
  struct rstData_t_o *GBWK;
  s8 EvoActFlag;
  struct rstData_t_o *v5;
  u8 StatAlpha;
  u16 id;
  u16 v12;
  struct rstinit_StaticFields *static_fields;
  rstupdate_c *v17;
  struct rstupdate_StaticFields *v18;
  f32 y;
  f32 z;
  f32 v21;
  UnityEngine_Transform_o *transform;
  rstinit_c *v25;
  s32 v30;
  System_String_o *v32;
  System_String_o *v33;
  struct System_SByte_array *ParamOfs;
  struct rstData_t_o *v37;
  datUnitWork_t_o **p_pCurrentStock;
  datUnitWork_t_o **p_EvoDevil;
  datUnitWork_t_o *pCurrentStock;
  UnityEngine_Vector3_o startPos;

  EvoActFlag = GBWK->EvoActFlag;
  switch (EvoActFlag)
  {
    case 0:
      GBWK->EvoActFrame = 0;
      v5 = GBWK;
      StatAlpha = v5->StatAlpha;
      if (StatAlpha)
      {
        v5->StatAlpha = StatAlpha - 4;
      }
      if (!IsSelectWindowDispOff())
      {
        if (!IsFadeOutWindow())
      }
      static_fields = v25->static_fields;
    case 1:
    case 2:
      rstStartEvoActSE();
      if (!fclChkSignal(0))
      id = GBWK->EvoDevil->id;
      cmpModelSetup(id, 1);
    case 3:
      if (!fclChkSignal(1))
      v12 = GBWK->EvoDevil->id;
      rstStartIntroduce(v12);
    case 4:
      if (fclChkMessage())
        return;
      GBWK->EvoActStatFlag = 1;
      fclSetVal(3, 0);
      static_fields = rstinit->static_fields;
      GBWK = static_fields->GBWK;
      EvoActFlag = GBWK->EvoActFlag;
      GBWK->EvoActFlag = EvoActFlag + 1;
      dds3ScreenParam->ox = ((dds3ScreenParam->ox + -2048.0) / 1.2)
                                                     + 2048.0;
      v18 = v17->static_fields;
      y = v18->startPos.y;
      z = v18->startPos.z;
      v21 = v18->startPos.x - ((2188.0 - dds3ScreenParam->ox) * v18->movePos);
      transform = get_transform(v18->statusCharaObj, 0);
      startPos.x = v21;
      startPos.y = y;
      startPos.z = z;
      break;
    case 5:
      if (dds3SearchProcessName(StringLiteral_21934))
        return;
      evtBitOff(3717);
      GBWK->StatAlpha = 0x80;
      cmpModelInitCore();
      dds3FadeIn(0, 0, 0, 0xFu);
      v30 = GBWK->pCurrentStock->id;
      v32 = Get(v30, 0);
      fclSetMessageVar_20743088(17, v32);
      v33 = Get(GBWK->EvoDevil->id, 0);
      fclSetMessageVar_20743088(18, v33);
      ParamOfs = GBWK->ParamOfs;
      Clear(ParamOfs, 0, ParamOfs->max_length, 0);
      v37 = GBWK;
      p_pCurrentStock = &v37->pCurrentStock;
      p_EvoDevil = &v37->EvoDevil;
      cmbCopyEvoDevilToStock(p_pCurrentStock, p_EvoDevil);
      pCurrentStock = GBWK->pCurrentStock;
      fclEncycRegist(pCurrentStock, 0, 0);
      GBWK->SeqInfo->Current = 17;
      draw_status_off(0);
      SetInteger(_statusUIScr->infoAnim, StringLiteral_12357, 1);
      transform = get_transform(statusCharaObj, 0);
      break;
    default:
  }
  set_localPosition(transform, startPos);
}

// 0x156d8c0
void rstUpdateSeqEvoAt(void) {
    fclChkMessage();
    fclSetVal(0, 0);
    dds3SearchProcessName(0);
    evtBitOff(0);
    evtFreeStage();
    fclFilterOFF();
}

// 0x156ace0
void rstUpdateSeqGift(void) {
    evtBitCheck(0);
    evtPictureSetPos(0, 0, 0, 0, 0, 0);
    evtKillPictureProcess(0);
    fclStartMessage(0);
    fclChkMessage();
    p2sdPlaySE(0);
    evtStartPictureProcess(0, 0);
    evtPictureSetSize(0, 0, 0, 0, 0);
    evtPictureSetAlpha(0, 0, 0, 0);
    evtPictureDrawOn(0);
    fclChkSelMessage();
    fclGetSelMessagePos();
    fclEndMessage();
    Get(0);
    fclSetMessageVar_20743088(0, 0);
    Get(0);
    datAddHearts(0);
    Get(0);
    datAddItem(0, 0);
    rstSetMotionReqFromTbl(0);
}

// 0x1570360
void rstUpdateSeqHeartsEvent(void) {
  struct rstData_t_o *GBWK;
  s32 Flag;
  s8 HeartsEventMode;
  s32 PanelEffID;
  s8 v10;
  s32 SelMessagePos;

  Flag = GBWK->Flag;
  if (Flag < 1)
  if (Flag == 3)
  {
    if (!fclChkMessage())
    {
      PanelEffID = GBWK->PanelEffID;
      if (!cmpChkQuePanelEff(PanelEffID))
      {
        rstSetHeartsEvent(v10);
        GBWK->SeqInfo->Change = 1;
      }
    }
    return;
  }
  if (Flag == 2)
  {
    fclStartMessage(29);
    GBWK->SeqInfo->MesFlag = 1;
  }
  else if (Flag == 1)
  {
    HeartsEventMode = GBWK->HeartsEventMode;
    if (!rstStandbyHeartsEvent(HeartsEventMode))
      return;
  }
  GBWK->Flag = 3;
  else if (fclChkSelMessage())
  {
    return;
  }
  SelMessagePos = fclGetSelMessagePos();
  if (SelMessagePos <= 1)
  {
    if (SelMessagePos == 1)
    {
      fclEndMessage();
      GBWK->Flag = 2;
      GBWK->HeartsEventMode = -1;
    }
    else if (!SelMessagePos)
    {
      fclEndMessage();
      GBWK->Flag = 1;
    }
  }
}

// 0x1570730
void rstUpdateSeqHeartsMaster(void) {
    fclChkMessage();
    Get(0);
    fclSetMessageVar_20743088(0, 0);
    fclStartMessage(0);
    rstSetMaxHpMp(0, 0);
}

// 0x156ed20
void rstUpdateSeqHeartsSkill(void) {
    rstChkSkillAct();
    fclChkMessage();
    fclEndMessage();
    fclStartMessage(0);
    rstGetHeartsSkill(0);
    rstSetMaxHpMp(0, 0);
    Get(0);
    fclSetMessageVar_20743088(0, 0);
}

// 0x156a730
void rstUpdateSeqPlayerLevelUpOnly(void) {
    fclStartMessage(0);
    fclChkMessage();
}

// 0x156c0e0
void rstUpdateSeqSkillPowerUp(void) {
    rstChkSkillAct();
    fclChkMessage();
    fclStartMessage(0);
    fclChkSelMessage();
    fclGetSelMessagePos();
    fclEndMessage();
    rstSetMotionReqFromTbl(0);
    rstOverWriteSkill(0, 0);
    rstInitSkillAct(0);
}
