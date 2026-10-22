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
        goto LABEL_20;
    }
    goto LABEL_13;
  }
  GetHeartsSkill = GBWK->EventParam;
  if ((v2->_2.bitflags2 & 2) != 0)
  {
LABEL_13:
  }
LABEL_20:
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
LABEL_10:
    cmpStatResetFlashFlag(1);
    GBWK->MessageWait = 1;
    v5 = *&v4->_2.bitflags1;
    if ((v5 & 0x200) != 0)
      goto LABEL_17;
    goto LABEL_23;
  }
  if ((v5 & 0x200) != 0)
  {
LABEL_17:
    v6 = v5 & 0x200;
    goto LABEL_24;
  }
LABEL_23:
  v6 = 0;
LABEL_24:
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
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v6;
  u16 v7;
  u16 v9;
  s64 skillcnt;
  struct System_Int32_array *skill;
  s64 heartsequip;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct System_Byte_array *heartsskcnt;
  s64 v19;
  struct System_UInt16_array_array *hearts_sk;
  s64 v21;
  s64 v22;
  System_UInt16_array *v24;
  struct dds3GlobalWork_t_o *v26;
  struct System_Byte_array *v27;
  s64 v28;
  u64 *v32;
  u16 v35;
  datUnitWork_t_o *pStock;

  pStock = 0;
  unitwork = DDS3_GBWK->unitwork;
  v6 = unitwork->m_Items[0];
  pStock = v6;
  v7 = rstChkHeartsSkill(&pStock);
  if (!v7)
    return 0;
LABEL_11:
  v9 = v7;
  if (!Mode)
  {
    skillcnt = v6->skillcnt;
    skill = v6->skill;
    v6->skillcnt = skillcnt + 1;
    skill->m_Items[skillcnt] = v7;
      goto LABEL_18;
    goto LABEL_13;
  }
  {
LABEL_13:
  }
LABEL_18:
  heartsequip = DDS3_GBWK->heartsequip;
  heartsskcnt = DDS3_GBWK->heartsskcnt;
  v19 = heartsskcnt + heartsequip;
  hearts_sk = DDS3_GBWK->hearts_sk;
  v21 = DDS3_GBWK->heartsequip;
  v22 = *(v19 + 32) & 0xF;
  v24 = hearts_sk->m_Items[v21];
  v24->m_Items[v22] = v9;
  v26 = DDS3_GBWK;
  v27 = v26->heartsskcnt;
  v28 = v26->heartsequip;
  ++v27->m_Items[v28];
  if (!Mode)
  {
    ++GBWK->HeartsSkFlag;
  }
  v35 = v9;
  v32 = sub_8D3950(ushort, &v35);
  Write_2930400("New hearts skill ID : {0:x2}\n", v32);
  return 1;
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
  SetInteger(Component_object, "sskill", 2);
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
  struct rstData_t_o *GBWK;
  struct datUnitWork_t_array *unitwork;
  struct System_SByte_array *levelupparam;
  s64 HeartsEventData;
  struct datUnitWork_t_array *v10;
  struct System_SByte_array *param;
  s64 v13;
  struct datUnitWork_t_array *v17;
  datUnitWork_t_o *v19;
  datUnitWork_t_o *v20;
  u32 v21;
  struct datUnitWork_t_array *v23;
  datUnitWork_t_o *v25;
  struct datUnitWork_t_array *v27;
  datUnitWork_t_o *v29;
  struct datUnitWork_t_array *v31;
  datUnitWork_t_o *v33;

  switch (GBWK->HeartsEventMode)
  {
    case 0:
      Clear(GBWK->ParamOfs, 0, GBWK->ParamOfs->max_length, 0);
      unitwork = DDS3_GBWK->unitwork;
      levelupparam = unitwork->m_Items[0]->levelupparam;
      HeartsEventData = GBWK->HeartsEventData;
      ++levelupparam->m_Items[HeartsEventData];
      v10 = DDS3_GBWK->unitwork;
      param = v10->m_Items[0]->param;
      v13 = GBWK->HeartsEventData;
      ++param->m_Items[v13];
        goto LABEL_52;
      goto LABEL_69;
    case 2:
      v17 = DDS3_GBWK->unitwork;
      v19 = v17->m_Items[0];
      v20 = v19;
      v21 = 64;
      goto LABEL_50;
    case 3:
      v23 = DDS3_GBWK->unitwork;
      v25 = v23->m_Items[0];
      v20 = v25;
      v21 = 256;
      goto LABEL_50;
    case 4:
      v27 = DDS3_GBWK->unitwork;
      v29 = v27->m_Items[0];
      v20 = v29;
      v21 = 0x8000;
LABEL_50:
      datOverwriteBadStat(v20, v21);
      goto LABEL_51;
    case 5:
      else
      {
        rstSetHeartsRecover(rstupdate);
          goto LABEL_69;
      }
LABEL_52:
LABEL_69:
      GBWK->HeartsEventMode = -1;
      return;
    case 6:
      v31 = DDS3_GBWK->unitwork;
      v33 = v31->m_Items[0];
      v33->hp = v33->maxhp;
      v33->mp = v33->maxmp;
      v33->badstatus &= 0x8000u;
        goto LABEL_69;
      goto LABEL_52;
    default:
LABEL_51:
        goto LABEL_52;
      goto LABEL_69;
  }
}

// 0x156f750
void rstSetHeartsRecover(void) {
  u64 v3;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct System_Int32_array *stocklist;
  struct datUnitWork_t_array *unitwork;
  s64 v9;
  datUnitWork_t_o *v11;

  GBWK->RecoverFlag = 1;
  v3 = 0;
  {
LABEL_9:
  }
  while (1)
  {
    if (v3 >= DDS3_GBWK->stockcnt)
      break;
    else
    {
      stocklist = DDS3_GBWK->stocklist;
      if (v3 >= LODWORD(stocklist->max_length))
        goto LABEL_15;
    }
    unitwork = DDS3_GBWK->unitwork;
    v9 = SLOBYTE(stocklist->m_Items[v3]);
    v11 = unitwork->m_Items[v9];
    if ((v11->flag & 2) != 0)
    {
      v11->hp = v11->maxhp;
      v11->mp = v11->maxmp;
      v11->badstatus &= 0x8000u;
    }
    ++v3;
      goto LABEL_9;
  }
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
        fclSetMessageVar_20743088(9, "1");
        fclStartMessage(30);
        if (EventType != 7)
          goto LABEL_65;
      }
      goto LABEL_89;
    case 1:
      if (rstStandbyHeartsSkillPowerUp())
        goto LABEL_64;
      return 0;
    case 2:
      fclStartMessage(33);
      id = GBWK->pCurrentStock->id;
      v18 = id;
      v19 = 64;
      goto LABEL_63;
    case 3:
      fclStartMessage(34);
      v22 = GBWK->pCurrentStock->id;
      v18 = v22;
      v19 = 256;
      goto LABEL_63;
    case 4:
      fclStartMessage(35);
      v25 = GBWK->pCurrentStock->id;
      v18 = v25;
      v19 = 0x8000;
LABEL_63:
      cmpBadEffSetup(v18, v19);
      goto LABEL_64;
    case 5:
      v27 = 36;
      goto LABEL_76;
    case 6:
      v27 = 37;
LABEL_76:
      fclStartMessage(v27);
      p2sdPlaySE(16);
      v34 = *static_fields;
      EndCol = static_fields[1];
      GBWK->PanelEffID = cmpAddQuePanelEff(0, 0, 0, 0, 0, 8u, 0, v34, EndCol, 4u);
      if (EventType == 7)
        goto LABEL_89;
      goto LABEL_65;
    default:
LABEL_64:
      if (EventType != 7)
      {
LABEL_65:
          goto LABEL_93;
        goto LABEL_66;
      }
LABEL_89:
      fclStartMessage(38);
      {
LABEL_66:
      }
LABEL_93:
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
LABEL_6:
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
        goto LABEL_55;
      v6 = 31;
    }
    fclStartMessage(v6);
LABEL_55:
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
  v19 = GBWK;
  v20 = GBWK->PUpSkillResult;
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
  struct rstinit_StaticFields **p_static_fields;
  struct rstData_t_o *GBWK;
  s32 EvoActFrame;

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
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  s8 Current;
  struct rstData_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  u8 Flag;
  u64 v18;
  struct rstData_t_o *v19;
  cmpSeqInfo_t_o *v22;
  struct datUnitWork_t_array *unitwork;
  struct cmpSeqInfo_t_o *v34;
  dds3ProcessID_t_o *v43[3];
  dds3ProcessID_t_o *id;

  id = PID;
  ProcessData = dds3GetProcessData(&id);
  else
  {
    if (!ProcessData)
      goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != rstData_t)
  {
    sub_8FC2C0(klass->_1.element_class, rstData_t, v43);
    if ((v43[0] & 1) != 0)
      v7 = v43[2];
    else
      v7 = v43 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_15:
  GBWK = ProcessData;
  Current = GBWK->SeqInfo->Current;
  else if (dds3FadeCheck())
  {
LABEL_18:
    if (GBWK->SeqInfo->Current != 20)
      return 0;
  }
  else if (cmpChkStatusModelLoadStat())
  {
    return 0;
  }
  SeqInfo = GBWK->SeqInfo;
  Flag = SeqInfo->Flag;
  if ((Flag & 0x40) != 0)
  {
    id->func_ans = -1;
  }
  else
  {
    if ((Flag & 2) == 0)
      goto LABEL_37;
    if ((Flag & 1) != 0)
    {
      switch (SeqInfo->Current)
      {
        case 0:
          if (GBWK->AsignParamMax)
          {
            unitwork = DDS3_GBWK->unitwork;
            rstUpdateSeqAsignPlayerParam(unitwork->m_Items);
          }
          else
          {
            rstUpdateSeqPlayerLevelUpOnly();
          }
          goto LABEL_37;
        case 1:
          rstUpdateSeqHeartsSkill();
          goto LABEL_37;
        case 3:
          rstUpdateSeqHeartsEvent();
          goto LABEL_37;
        case 5:
          rstUpdateSeqHeartsMaster();
          goto LABEL_37;
        case 6:
          rstUpdateSeqDevilParam();
          goto LABEL_37;
        case 8:
          rstUpdateSeqDefaultSkill();
          goto LABEL_37;
        case 0xA:
          rstUpdateSeqSkillPowerUp();
          goto LABEL_37;
        case 0xB:
          if (!fclChkMessage())
          {
            v34 = GBWK->SeqInfo;
            ++v34->Current;
            GBWK->SeqInfo->Change = 1;
          }
          goto LABEL_37;
        case 0xD:
          rstUpdateSeqGift();
          goto LABEL_37;
        case 0x11:
          rstUpdateSeqEvo();
          goto LABEL_37;
        case 0x12:
          rstUpdateSeqEvoAt();
          goto LABEL_37;
        case 0x14:
          rstUpdateSeqEvoAct();
          goto LABEL_37;
        case 0x15:
          rstUpdateSeqDestroySkill();
          goto LABEL_37;
        case 0x16:
          if (rstUpdateSeqDestroyConfirm())
            goto LABEL_37;
          break;
        case 0x18:
          if (rstUpdateSeqConfirm())
            goto LABEL_37;
          break;
        default:
          goto LABEL_37;
      }
    }
    else
    {
LABEL_37:
      fclUpdateMessage();
      ++*(**(v18 + 184) + 216LL);
      v19 = **(v18 + 184);
      if (v19->BgTimer >= 0x900)
      {
        if ((*(v18 + 295) & 2) != 0 && !*(v18 + 216))
        {
          v19 = GBWK;
        }
        v19->BgTimer = 0;
      }
      rstUpdateEvoBgFade(v18);
      v22 = GBWK->SeqInfo;
      cmpUpdateSeqInfo(v22, Current);
    }
  }
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
    goto LABEL_28;
  }
  else
  {
    EvoBgFade = GBWK->EvoBgFade;
    if (EvoBgFade > 0x31)
      goto LABEL_16;
  }
  GBWK->EvoBgFade = EvoBgFade + 1;
LABEL_16:
  if (GBWK->EvoBgFade >= 0x33)
  {
    v4 = 50;
LABEL_28:
    GBWK->EvoBgFade = v4;
  }
}

// 0x1566490
void rstUpdateNewParam(void) {
  struct rstData_t_o *GBWK;
  datUnitWork_t_o **p_pCurrentStock;
  datUnitWork_t_o **v5;

  p_pCurrentStock = &GBWK->pCurrentStock;
  else
  {
    v5 = &GBWK->pCurrentStock;
  }
  rstAddAsignParam(v5);
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
      goto LABEL_33;
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
        goto LABEL_82;
      }
      if (v4 == 64)
      {
        v46 = GBWK->ParamOfs;
        if (v46->m_Items[v65] < 1)
          goto LABEL_112;
        v49 = GBWK->ParamOfs;
        --v49->m_Items[v65];
        v52 = GBWK;
        v53 = v52->AsignParam + 1;
LABEL_111:
        v52->AsignParam = v53;
        SetPointAnime(GBWK->AsignParam);
        goto LABEL_112;
      }
      if (v4 != 128)
        goto LABEL_112;
    }
    else
    {
      v30 = v4;
      if (v4 != 1)
      {
        if (v4 == 2)
        {
          rstResetAsignParam();
          goto LABEL_112;
        }
        if (v4 == 16)
        {
          v32 = GBWK->ParamCursor;
          v33 = v32;
          v34 = -1;
LABEL_82:
          cmpMoveCursor(v33, v34);
          v40 = cmpGetCursorIndex(GBWK->ParamCursor);
          statusUIScr = _statusUIScr;
          v43 = statusUIScr->stsCursor;
          ObjStsBar = statusUIScr->ObjStsBar;
          cmpMenuCursor(v40, v43, ObjStsBar);
        }
LABEL_112:
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
      goto LABEL_112;
    }
    v55 = GBWK;
    if (v55->AsignParam < 1)
      goto LABEL_112;
    v56 = v55->ParamOfs;
    ++v56->m_Items[v65];
    v52 = GBWK;
    v53 = v52->AsignParam - 1;
    goto LABEL_111;
  }
LABEL_33:
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
  s32 v3;
  s32 EventParam;
  System_String_o *v13;

  else
  {
    v3 = rstChkSkillAct(rstupdate);
    if (v3 != 2)
      goto LABEL_6;
  }
  EventParam = GBWK->EventParam;
  v13 = Get(EventParam, 0, 0);
  fclSetMessageVar_20743088(10, v13);
  fclStartMessage(6);
  cmpStatResetFlashFlag(1);
}

// 0x156e730
s8 rstUpdateSeqDestroyConfirm(void) {
  rstinit_c *v2;
  struct rstData_t_o *GBWK;
  s32 Flag;
  s16 v5;
  s32 v6;
  struct rstData_t_o *v8;
  s32 SelMessagePos;
  cmpCursorInfo_t_o *SkillCursor;
  s32 CursorIndex;
  datUnitWork_t_o **p_pCurrentStock;
  char v25;
  s64 v26;
  struct System_Int32_array *skill;
  s32 SelectSkillID;
  System_String_o *v33;

  Flag = GBWK->Flag;
  if (Flag < 1)
    goto LABEL_51;
  LOBYTE(Flag) = GBWK->Flag;
  if ((Flag - 1) < 2)
    goto LABEL_18;
LABEL_10:
  if (Flag == 3)
  {
    if (fclChkMessage())
      return 1;
    if ((v5 & 0x200) != 0)
    {
      v6 = v5 & 0x200;
    }
    else
    {
      v6 = 0;
    }
    v8 = GBWK;
    if (v8->pCurrentStock->id)
    {
      v8->SeqInfo->Current = 8;
      GBWK->SeqInfo->Change = 1;
      if ((v2->_2.bitflags2 & 2) == 0)
        goto LABEL_50;
    }
    else
    {
      v8->SeqInfo->Current = 1;
      GBWK->SeqInfo->Change = 1;
      if ((v2->_2.bitflags2 & 2) == 0)
        goto LABEL_50;
    }
    goto LABEL_35;
  }
LABEL_34:
  if ((v2->_2.bitflags2 & 2) != 0)
  {
LABEL_35:
  }
LABEL_50:
  GBWK->Flag = 3;
LABEL_51:
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
        fclEndMessage();
        GBWK->SeqInfo->Current = 21;
        GBWK->SeqInfo->Change = 2;
      }
    }
    else
    {
      fclEndMessage();
      if (!GBWK->pCurrentStock->id)
      {
        rstGetHeartsSkill(1);
      }
      SkillCursor = GBWK->SkillCursor;
      CursorIndex = cmpGetCursorIndex(SkillCursor);
      if (CursorIndex << 24 <= 117440512)
      {
        LOBYTE(v26) = CursorIndex;
        skill = GBWK->pCurrentStock->skill;
        skill->m_Items[v26] = 0;
        v30 = rstReplaceSkill();
        rstAddSkill();
        v25 = 1;
      }
      else
      {
        p_pCurrentStock = &GBWK->pCurrentStock;
        rstSetMaxHpMp(1, p_pCurrentStock);
        --GBWK->LevelUpCnt;
        v25 = 2;
      }
      GBWK->Flag = v25;
      SelectSkillID = GBWK->SelectSkillID;
      v33 = Get(SelectSkillID, 0, 0);
      fclSetMessageVar_20743088(10, v33);
    }
  }
  return 1;
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
      goto LABEL_72;
    }
    if (v4 != 64)
    {
      if (v4 != 128)
        goto LABEL_54;
      if (CursorIndex > 7u)
      {
        GBWK->SkillCursor->CursorPos->Shift = 0;
          goto LABEL_55;
        goto LABEL_93;
      }
      if (CursorIndex <= 3u)
      {
        CursorPos = GBWK->SkillCursor->CursorPos;
        CursorPos->Shift += 4;
          goto LABEL_55;
        goto LABEL_93;
      }
LABEL_89:
      GBWK->SkillCursor->CursorPos->Shift = 8;
        goto LABEL_55;
LABEL_93:
      if (!cmpChkPadPressUpDown())
        goto LABEL_94;
      goto LABEL_101;
    }
    if (CursorIndex <= 7u)
    {
      if (CursorIndex <= 3u)
        goto LABEL_89;
      {
LABEL_87:
        v37 = GBWK->SkillCursor->CursorPos;
        v37->Shift -= 4;
          goto LABEL_55;
        goto LABEL_93;
      }
    }
    else
    {
        goto LABEL_87;
    }
    goto LABEL_87;
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
    goto LABEL_54;
  }
  if (v4 == 2)
    return 0;
  if (v4 != 16)
  {
LABEL_54:
      goto LABEL_93;
    goto LABEL_55;
  }
  v13 = GBWK->SkillCursor;
  if (cmpGetCursorIndex(v13) == 8)
    return 0;
  v16 = GBWK->SkillCursor;
  v17 = v16;
  v18 = -1;
LABEL_72:
  cmpMoveCursor(v17, v18);
    goto LABEL_93;
LABEL_55:
    goto LABEL_93;
  if (!cmpChkPadPressUpDown())
  {
LABEL_94:
    v39 = GBWK->SkillCursor;
    cmpMoveCursor(v39, 0);
  }
LABEL_101:
  cmpPlaySE(v11);
  return 1;
}

// 0x156a8a0
void rstUpdateSeqDevilParam(void) {
  System_Char_array *v1;
  s32 id;
  System_String_o *v7;
  s64 Flag;
  s64 v13;
  struct System_SByte_array *ParamOfs;
  s64 v16;
  struct rstData_t_o *v17;
  datUnitWork_t_o **p_pCurrentStock;
  struct cmpSeqInfo_t_o *SeqInfo;
  u32 v21;
  System_String_o *ParamName;
  struct System_SByte_array *v26;
  u64 *v28;
  System_String_o *v29;
  s32 v31;
  struct rstData_t_o *GBWK;
  char v35;
  char v38[4];

  v1 = NewSpecific(char, 0x10u);
  CreateString_5280336(0, v1);
  else if (fclChkMessage())
  {
    return;
  }
  id = GBWK->pCurrentStock->id;
  v7 = Get(id, 0);
  fclSetMessageVar_20743088(1, v7);
  Flag = GBWK->Flag;
  if (Flag <= 5)
  {
    v13 = Flag + 32;
    while (1)
    {
      ParamOfs = GBWK->ParamOfs;
      if (*(&ParamOfs->obj.klass + v13) >= 1)
        break;
      v16 = v13 - 32;
      ++v13;
      if (v16 >= 5)
        goto LABEL_24;
    }
    v21 = v13 - 32;
    ParamName = cmpGetParamName(v21);
    fclSetMessageVar_20743088(8, ParamName);
    v26 = GBWK->ParamOfs;
    v38[0] = *(&v26->obj.klass + v13);
    v28 = sub_8D3950(sbyte, v38);
    v29 = Format("{0:D}", v28, 0);
    fclSetMessageVar_20743088(9, v29);
    if (GBWK->Flag)
    {
      v31 = 5;
    }
    else
    {
      v31 = 3;
    }
    fclStartMessage(v31);
    v35 = v13 - 31;
    goto LABEL_68;
  }
LABEL_24:
  v17 = GBWK;
  if (!v17->Flag)
    goto LABEL_53;
LABEL_27:
  p_pCurrentStock = &v17->pCurrentStock;
  rstSetMaxHpMp(0, p_pCurrentStock);
  SeqInfo = GBWK->SeqInfo;
  ++SeqInfo->Current;
  GBWK->SeqInfo->Change = 1;
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
    goto LABEL_55;
  if (Flag == 3)
  {
    if (!fclChkMessage())
    {
      if (!dds3SearchProcessName("e809_main"))
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
    goto LABEL_49;
  }
  if (Flag != 1)
    goto LABEL_51;
  fclStartMessage(22);
  GBWK->SeqInfo->MesFlag = 1;
LABEL_51:
  GBWK->Flag = 3;
LABEL_55:
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
      goto LABEL_100;
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
      v22 = Find(transform, "statusChara", 0);
      v24 = get_gameObject(v22);
      statusCharaObj = v24;
      v26 = get_transform(statusCharaObj, 0);
      startPos = get_localPosition(v26);
      v27 = GBWK;
      v28 = 1;
LABEL_100:
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
  f32 y;
  f32 z;
  f32 v21;
  UnityEngine_Transform_o *transform;
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
        goto LABEL_57;
      }
      if (!IsSelectWindowDispOff())
      {
        if (!IsFadeOutWindow())
          goto LABEL_57;
      }
      goto LABEL_55;
    case 1:
        goto LABEL_56;
      goto LABEL_54;
    case 2:
      rstStartEvoActSE();
      if (!fclChkSignal(0))
        goto LABEL_57;
      id = GBWK->EvoDevil->id;
      cmpModelSetup(id, 1);
      goto LABEL_54;
    case 3:
      if (!fclChkSignal(1))
        goto LABEL_57;
      v12 = GBWK->EvoDevil->id;
      rstStartIntroduce(v12);
      goto LABEL_54;
    case 4:
      if (fclChkMessage())
        return;
      GBWK->EvoActStatFlag = 1;
      fclSetVal(3, 0);
LABEL_54:
LABEL_55:
      EvoActFlag = GBWK->EvoActFlag;
LABEL_56:
      GBWK->EvoActFlag = EvoActFlag + 1;
LABEL_57:
      dds3ScreenParam->ox = ((dds3ScreenParam->ox + -2048.0) / 1.2)
                                                     + 2048.0;
      y = startPos.y;
      z = startPos.z;
      v21 = startPos.x - ((2188.0 - dds3ScreenParam->ox) * movePos);
      transform = get_transform(statusCharaObj, 0);
      startPos.x = v21;
      startPos.y = y;
      startPos.z = z;
      break;
    case 5:
      if (dds3SearchProcessName("e809_main"))
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
      SetInteger(_statusUIScr->infoAnim, "sinfo", 1);
      transform = get_transform(statusCharaObj, 0);
      break;
    default:
      goto LABEL_57;
  }
  set_localPosition(transform, startPos);
}

// 0x156d8c0
void rstUpdateSeqEvoAt(void) {
  if (!GBWK->Flag)
    goto LABEL_32;
LABEL_6:
LABEL_10:
  if (!dds3SearchProcessName("e809_main"))
  {
    evtBitOff(3717);
    if (!fclChkMessage())
    {
      evtFreeStage();
      fclFilterOFF();
      cmpModelInitCore2();
      GBWK->Flag = 2;
      GBWK->SeqInfo->Current = 17;
      GBWK->SeqInfo->Change = 1;
      goto LABEL_32;
    }
  }
}

// 0x156ace0
void rstUpdateSeqGift(void) {
  struct rstData_t_o *GBWK;
  s32 SelMessagePos;
  s32 id;
  System_String_o *v10;
  struct rstData_t_o *v12;
  s32 GiftItemID;
  System_String_o *v15;
  s32 v17;
  rstupdate_c *v20;
  s16 v21;
  s32 v22;
  struct rstupdate_StaticFields **p_static_fields;
  s32 gAiboMode;
  s32 gAiboX;
  s16 v27;
  s32 v28;
  dds3ProcessID_t_o *v29;
  s32 Flag;
  s32 v34;
  dds3ProcessID_t_o *thAibo;
  s32 v37;
  s8 v58;
  s32 v59;
  System_String_o *v61;
  s32 v63;

  if (evtBitCheck(3712))
    goto LABEL_4;
  if ((v21 & 0x200) != 0)
  {
    v22 = v21 & 0x200;
  }
  else
  {
    v22 = 0;
  }
  if (gAiboMode == 1)
  {
    else
    {
      if (gAiboX > 31)
      {
LABEL_49:
        gAiboX = 32;
        (*p_static_fields)->gAiboMode = 2;
        if ((v20->_2.bitflags2 & 2) == 0)
          goto LABEL_115;
        goto LABEL_53;
      }
    }
    gAiboX = gAiboX + 16;
    if ((v20->_2.bitflags2 & 2) == 0)
      goto LABEL_115;
LABEL_53:
LABEL_115:
    v37 = gAiboX;
    evtPictureSetPos(thAibo, v37, 192, 96, 192, 6);
    return;
  }
  if (gAiboMode == 2)
    goto LABEL_4;
  v27 = *&v20->_2.bitflags1;
  if ((v27 & 0x200) == 0)
  {
    v28 = 0;
    if (gAiboMode != 3)
      goto LABEL_61;
LABEL_101:
    v34 = gAiboX;
    if (v34 >= -127)
    {
      gAiboX = v34 - 32;
      if ((v20->_2.bitflags2 & 2) == 0)
        goto LABEL_115;
    }
    else
    {
      gAiboX = -128;
      (*p_static_fields)->gAiboMode = 4;
      if ((v20->_2.bitflags2 & 2) == 0)
        goto LABEL_115;
    }
    goto LABEL_53;
  }
  v28 = v27 & 0x200;
  if (gAiboMode == 3)
    goto LABEL_101;
LABEL_61:
  if (gAiboMode == 4)
  {
    v29 = thAibo;
    if (v29)
    {
      evtKillPictureProcess(v29);
      thAibo = 0;
      set_sortingOrder(canvUI, 10);
      canvUI = 0;
    }
    gAiboMode = 0;
    return;
  }
LABEL_4:
  if (!GBWK->GiftItemID)
    goto LABEL_81;
LABEL_7:
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
      GBWK->GiftItemID = 0;
      GBWK->GiftStep = 1;
      v58 = 4;
      goto LABEL_248;
    }
    if (!SelMessagePos)
    {
      fclEndMessage();
      id = GBWK->pCurrentStock->id;
      v10 = Get(id, 0);
      fclSetMessageVar_20743088(1, v10);
      v12 = GBWK;
      if (v12->GiftType)
      {
        GiftItemID = v12->GiftItemID;
        v15 = Get(GiftItemID, 0);
        fclSetMessageVar_20743088(2, v15);
        v17 = GBWK->GiftItemID;
        datAddHearts(v17);
          goto LABEL_264;
      }
      else
      {
        v59 = v12->GiftItemID;
        v61 = Get(v59, 0);
        fclSetMessageVar_20743088(2, v61);
        v63 = GBWK->GiftItemID;
        datAddItem(v63, 1);
          goto LABEL_264;
      }
LABEL_264:
      GBWK->Flag = 1;
      GBWK->GiftItemID = 0;
      GBWK->GiftStep = 0;
      v58 = 1;
LABEL_248:
      rstSetMotionReqFromTbl(v58);
    }
  }
}

// 0x1570360
void rstUpdateSeqHeartsEvent(void) {
  rstinit_c *v2;
  struct rstData_t_o *GBWK;
  s32 Flag;
  s8 HeartsEventMode;
  s32 PanelEffID;
  s8 v10;
  s32 SelMessagePos;

  Flag = GBWK->Flag;
  if (Flag < 1)
    goto LABEL_51;
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
      goto LABEL_50;
    goto LABEL_48;
  }
  if ((v2->_2.bitflags2 & 2) != 0)
  {
LABEL_48:
  }
LABEL_50:
  GBWK->Flag = 3;
LABEL_51:
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
  struct rstData_t_o *GBWK;
  s32 Flag;
  struct System_SByte_array *param;
  struct System_SByte_array *ParamOfs;
  struct rstData_t_o *v11;
  struct System_SByte_array *v12;
  struct System_SByte_array *v14;
  struct rstData_t_o *v16;
  struct System_SByte_array *v17;
  struct System_SByte_array *v19;
  struct rstData_t_o *v21;
  struct System_SByte_array *v22;
  struct System_SByte_array *v24;
  struct rstData_t_o *v26;
  struct System_SByte_array *v27;
  struct System_SByte_array *v29;
  struct rstData_t_o *v31;
  struct System_SByte_array *v32;
  struct System_SByte_array *v34;
  datUnitWork_t_o **p_pCurrentStock;
  struct System_SByte_array *v37;

  else if (fclChkMessage())
  {
    return;
  }
  Flag = GBWK->Flag;
  if (!GBWK->Flag)
    goto LABEL_62;
LABEL_9:
  if (Flag == 1)
  {
    param = GBWK->pCurrentStock->param;
    ParamOfs = GBWK->ParamOfs;
    param->m_Items[0] += ParamOfs->m_Items[0];
    v11 = GBWK;
    v12 = v11->pCurrentStock->param;
    v14 = v11->ParamOfs;
    v12->m_Items[1] += v14->m_Items[1];
    v16 = GBWK;
    v17 = v16->pCurrentStock->param;
    v19 = v16->ParamOfs;
    v17->m_Items[2] += v19->m_Items[2];
    v21 = GBWK;
    v22 = v21->pCurrentStock->param;
    v24 = v21->ParamOfs;
    v22->m_Items[3] += v24->m_Items[3];
    v26 = GBWK;
    v27 = v26->pCurrentStock->param;
    v29 = v26->ParamOfs;
    v27->m_Items[4] += v29->m_Items[4];
    v31 = GBWK;
    v32 = v31->pCurrentStock->param;
    v34 = v31->ParamOfs;
    v32->m_Items[5] += v34->m_Items[5];
    p_pCurrentStock = &GBWK->pCurrentStock;
    rstSetMaxHpMp(0, p_pCurrentStock);
    v37 = GBWK->ParamOfs;
    Clear(v37, 0, v37->max_length, 0);
    GBWK->HeartsEventMode = -1;
    GBWK->SeqInfo->Change = 1;
    return;
  }
LABEL_125:
  ++GBWK->Flag;
}

// 0x156ed20
void rstUpdateSeqHeartsSkill(void) {
  s32 v3;
  s32 GetHeartsSkill;
  System_String_o *v13;

  else
  {
    v3 = rstChkSkillAct(rstupdate);
    if (v3 != 2)
      goto LABEL_6;
  }
  GetHeartsSkill = GBWK->GetHeartsSkill;
  v13 = Get(GetHeartsSkill, 0, 0);
  fclSetMessageVar_20743088(10, v13);
  fclStartMessage(6);
  cmpStatResetFlashFlag(1);
}

// 0x156a730
void rstUpdateSeqPlayerLevelUpOnly(void) {
  else if (GBWK->Flag)
  {
    goto LABEL_14;
  }
  fclStartMessage(1);
  GBWK->Flag = 1;
LABEL_14:
  else if (fclChkMessage())
  {
    return;
  }
  GBWK->SeqInfo->Current = 1;
  GBWK->SeqInfo->Change = 1;
}

// 0x156c0e0
void rstUpdateSeqSkillPowerUp(void) {
  s32 SelMessagePos;
  rstinit_c *v7;
  struct rstData_t_o *GBWK;
  s32 PUpSkillResult;
  struct System_Int32_array *v10;
  s64 v11;
  u16 v12;
  s32 Flag;
  struct System_Int32_array *skill;
  s64 PUpSkillIndex;
  u16 PUpSkillID;

  if (GBWK->PUpSkillResult < 0)
    goto LABEL_37;
LABEL_6:
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
      rstSetMotionReqFromTbl(3);
      GBWK->Flag = 4;
      goto LABEL_124;
    }
    if (!SelMessagePos)
    {
      fclEndMessage();
      PUpSkillResult = GBWK->PUpSkillResult;
      if (PUpSkillResult == 2)
      {
        skill = GBWK->pCurrentStock->skill;
        PUpSkillIndex = GBWK->PUpSkillIndex;
        PUpSkillID = GBWK->PUpSkillID;
        rstOverWriteSkill(&skill->m_Items[PUpSkillIndex], PUpSkillID);
        rstSetMotionReqFromTbl(2);
        rstInitSkillAct(GBWK->PUpSkillIndex);
        GBWK->Flag = 2;
        if ((v7->_2.bitflags2 & 2) == 0)
          goto LABEL_124;
      }
      else if (PUpSkillResult == 1)
      {
        v10 = GBWK->pCurrentStock->skill;
        v11 = GBWK->PUpSkillIndex;
        v12 = GBWK->PUpSkillID;
        rstOverWriteSkill(&v10->m_Items[v11], v12);
        rstSetMotionReqFromTbl(2);
        rstInitSkillAct(GBWK->PUpSkillIndex);
        GBWK->Flag = 1;
        if ((v7->_2.bitflags2 & 2) == 0)
          goto LABEL_124;
      }
      else
      {
        GBWK->Flag = 3;
        if ((v7->_2.bitflags2 & 2) == 0)
          goto LABEL_124;
      }
LABEL_124:
      GBWK->PUpSkillResult = -1;
    }
  }
}
