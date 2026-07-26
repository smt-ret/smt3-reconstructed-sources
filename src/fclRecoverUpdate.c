#include "types.h"

typedef struct AssetBundles AssetBundles;
typedef struct cmpLocalStock_t cmpLocalStock_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclDataRecover_t fclDataRecover_t;
typedef struct lstListWindow_t lstListWindow_t;

void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
void FadeOutWindow(void);
s32 FindId(s32 type, char *name);
bool IsLoad(AssetBundles *this, char *key);
void SetButtonGuide(s32 mode, bool sw);
u32 datGetMaxHp(datUnitWork_t *work);
u32 datGetMaxMp(datUnitWork_t *work);
dds3Basic_t *dds3GetControlScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetProcessStat(dds3ProcessID_t **id);
dds3Basic_t *dds3SceneBasicSearchNameAndType(dds3Basic_t *scene, u32 type, char *name);
s8 fclChkSignal(s8 Idx);
void fclClearSignal(s8 Idx);
void fclLoadPB(void);
void fclRecoverUpdateInit(fclDataRecover_t *data);
dds3ProcessID_t *fclScriptStart(u8 **pScriptData, s32 StartNo, dds3ProcessID_t **pPID);
s8 fclSetVal(s8 Idx, s32 Val);
void lstMoveCursor2(lstListWindow_t *pListWindow, s8 Dir);
s32 p2sdPlaySE(s32 a);
void rcvAppAllRecover(datUnitWork_t *pStock);
void rcvCreateLocalStock(cmpLocalStock_t *pLocalStock, s32 Flag);
void rcvExit(void);
s8 rcvUpdateCallSeq(s8 SeqNo);
s8 rcvUpdateData(void);
void rcvUpdatePanelMover(void);
void rcvUpdateSeqAllRecover(void);
s32 rcvUpdateSeqDispel(s32 Mode);
void rcvUpdateSeqRecover(void);
void rcvUpdateSeqRevive(void);
void rcvUpdateSeqRoot(void);
void rcvUpdateSeqStatusRecover(void);
void rcvUpdateSeqTalk(void);

// 0x19936b0
s32 fclChkDispelMakaErr(void) {
  struct cmpSeqInfo_t_o *SeqInfo;

  SeqInfo = GBWK->SeqInfo;
  if (SeqInfo->Current == 6)
  {
    else if (SeqInfo->Last == 5)
    {
      return 1;
    }
  }
  return 0;
}

// 0x19956f0
void rcvExit(void) {
  cmpCursorInfo_t_o *CursorInfo;
  struct fclDataRecover_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;

  CursorInfo = GBWK->CmdSelInfo->CursorInfo;
  cmpMoveCursorListEnd(CursorInfo);
  GBWK->ismsgend = 0;
  GBWK->SeqInfo->MesFlag = 1;
  SeqInfo = GBWK->SeqInfo;
  pScriptData = GBWK->pScriptData;
  p_ScriptPID = &GBWK->ScriptPID;
  SeqInfo->MesPID = fclScriptStart(pScriptData, 7, p_ScriptPID);
  GBWK->SeqInfo->Current = 7;
  SetButtonGuide(7, 0);
}

// 0x19980e0
void *rcvUpdate(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    IsLoad(0, 0);
    fclRecoverUpdateInit(0);
    dds3GetControlScene();
    dds3SceneBasicSearchNameAndType(0, 0, 0);
    fclLoadPB();
    rcvUpdatePanelMover();
    fclChkSignal(0);
    SetButtonGuide(0, 0);
    rcvUpdateSeqRoot();
    rcvUpdateSeqAllRecover();
    rcvUpdateSeqRecover();
    rcvUpdateSeqStatusRecover();
    rcvUpdateSeqRevive();
    rcvUpdateSeqDispel(0);
    rcvUpdateSeqTalk();
    fclClearSignal(0);
    fclSetVal(0, 0);
    return 0;
}

// 0x1995d40
s8 rcvUpdateCallSeq(s8 SeqNo) {
  s8 v3;
  s32 v4;
  s32 v6;
  struct cmpLocalStock_t_o *LocalStock;
  Il2CppObject *v13;
  struct fclDataRecover_t_o *v16;
  struct datUnitWork_t_array *unitwork;
  Il2CppObject *Item;
  struct fclDataRecover_t_o *v27;
  struct cmpSeqInfo_t_o *SeqInfo;
  struct fclDataRecover_t_o *v33;
  struct cmpSeqInfo_t_o *v34;
  struct fclDataRecover_t_o *v36;
  struct cmpSeqInfo_t_o *v37;
  fclRecoverInit_c *v38;
  struct fclRecoverInit_StaticFields **p_static_fields;
  struct fclDataRecover_t_o *GBWK;
  struct fclDataRecover_t_o *v41;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;

  v3 = SeqNo;
  v4 = 5;
  switch (v3)
  {
    case 0:
    case 1:
      rcvCreateLocalStock(GBWK->LocalStock, 7);
      v4 = 1;
      v6 = 8;
    case 2:
      v4 = 1;
      rcvCreateLocalStock(GBWK->LocalStock, 1);
      v6 = 0;
    case 3:
      rcvCreateLocalStock(GBWK->LocalStock, 2);
      v6 = 0;
      v4 = 1;
    case 4:
      rcvCreateLocalStock(GBWK->LocalStock, 4);
      v4 = 3;
      v6 = 10;
    case 5:
      GBWK->AttrFlag = 0;
      unitwork = DDS3_GBWK->unitwork;
      if (unitwork->m_Items[0]->badstatus < 0)
      {
        v4 = 2;
        p_static_fields = &v38->static_fields;
        if (GBWK->SeqInfo->Current != v3)
        {
          GBWK->ismsgend = 0;
          v41 = (*p_static_fields)->GBWK;
          pScriptData = v41->pScriptData;
          p_ScriptPID = &v41->ScriptPID;
          *p_ScriptPID = fclScriptStart(pScriptData, v4, p_ScriptPID);
        }
        GBWK->SeqInfo->Current = v3;
        SetButtonGuide(v3, 0);
        return 1;
      }
      else
      {
        Item = object___get_Item(AnimObjs, StringLiteral_16348);
        SetInteger(Item, StringLiteral_16353, 0);
        if (GBWK->SeqInfo->Current)
        {
          rcvUpdateCallSeq(0);
          return 0;
        }
        else
        {
          fclClearSignal(0);
          GBWK->ismsgend = 0;
          GBWK->SeqInfo->MesFlag = 1;
          v27 = GBWK;
          SeqInfo = v27->SeqInfo;
          SeqInfo->MesPID = fclScriptStart(v27->pScriptData, 9, &v27->ScriptPID);
          GBWK->SeqInfo->Current = 6;
          GBWK->SeqInfo->Last = 6;
          GBWK->SeqInfo->Change = -1;
          GBWK->SeqInfo->Next = 0;
          SetButtonGuide(6, 0);
          return 0;
        }
      }
    case 6:
      fclSetVal(2, 1);
      GBWK->ismsgend = 0;
      GBWK->SeqInfo->MesFlag = 1;
      v33 = GBWK;
      v34 = v33->SeqInfo;
      v34->MesPID = fclScriptStart(v33->pScriptData, 6, &v33->ScriptPID);
      GBWK->SeqInfo->Current = 6;
      GBWK->SeqInfo->Last = 6;
    case 7:
      rcvExit(SeqNo);
      v4 = 0;
    default:
      v6 = 0;
      v4 = 0;
      LocalStock = GBWK->LocalStock;
      if (LocalStock->StockCnt + LocalStock->PartyCnt)
      v13 = object___get_Item(AnimObjs, StringLiteral_16348);
      SetInteger(v13, StringLiteral_16353, 0);
      v16 = GBWK;
      if (v16->SeqInfo->Current)
      v16->ismsgend = 0;
      fclClearSignal(0);
      GBWK->SeqInfo->MesFlag = 1;
      v36 = GBWK;
      v37 = v36->SeqInfo;
      v37->MesPID = fclScriptStart(v36->pScriptData, v6, &v36->ScriptPID);
  }
}

// 0x1995850
s8 rcvUpdateData(void) {
    datGetMaxHp(0);
    datGetMaxMp(0);
    rcvAppAllRecover(0);
    FindId(0, 0);
    p2sdPlaySE(0);
    return 0;
}

// 0x19975f0
void rcvUpdatePanelMover(void) {
    fclChkSignal(0);
}

// 0x19964c0
void rcvUpdateSeqAllRecover(void) {
    fclChkSignal(0);
    FadeOutWindow();
    ButtonGuideDispSet(0, 0, 0, 0);
    rcvUpdateCallSeq(0);
    lstMoveCursor2(0, 0);
    rcvUpdateData();
}

// 0x19972e0
s32 rcvUpdateSeqDispel(s32 Mode) {
  dds3ProcessID_t_o **p_ScriptPID;
  bool v9;
  struct fclDataRecover_t_o *v13;
  struct cmpSeqInfo_t_o *v14;
  char v17;
  struct cmpSeqInfo_t_o *v18;
  struct fclDataRecover_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;

  p_ScriptPID = &GBWK->ScriptPID;
  if (dds3GetProcessStat(p_ScriptPID) == 2)
    return 0;
  v6 = fclChkSignal(2);
  if (v6 > 1)
    return 1;
  if ()
  {
    if (v6 == 1)
    {
      rcvUpdateCallSeq(GBWK->SeqInfo->Last);
      GBWK->SeqInfo->Change = 2;
    }
    return 1;
  }
  v9 = rcvUpdateData() == 0;
  if (v9)
  {
    GBWK->ismsgend = 0;
    fclClearSignal(0);
    GBWK->SeqInfo->MesFlag = 1;
    SeqInfo = GBWK->SeqInfo;
    SeqInfo->MesPID = fclScriptStart(GBWK->pScriptData, 11, &GBWK->ScriptPID);
    GBWK->SeqInfo->Current = 6;
    v18 = GBWK->SeqInfo;
    v17 = 5;
  }
  else
  {
    GBWK->ismsgend = 0;
    fclClearSignal(0);
    GBWK->SeqInfo->MesFlag = 1;
    v13 = GBWK;
    v14 = v13->SeqInfo;
    v14->MesPID = fclScriptStart(v13->pScriptData, 4, &v13->ScriptPID);
    v17 = 6;
    GBWK->SeqInfo->Current = 6;
    v18 = GBWK->SeqInfo;
  }
  v18->Last = v17;
  GBWK->SeqInfo->Change = -1;
  GBWK->SeqInfo->Next = 0;
  SetButtonGuide(6, 0);
  return 1;
}

// 0x19968e0
void rcvUpdateSeqRecover(void) {
    lstMoveCursor2(0, 0);
    rcvUpdateData();
    rcvUpdateCallSeq(0);
    fclChkSignal(0);
    FadeOutWindow();
}

// 0x1996f60
void rcvUpdateSeqRevive(void) {
    lstMoveCursor2(0, 0);
    rcvUpdateData();
    rcvUpdateCallSeq(0);
    fclChkSignal(0);
    FadeOutWindow();
    ButtonGuideDispSet(0, 0, 0, 0);
}

// 0x19978c0
void rcvUpdateSeqRoot(void) {
    fclSetVal(0, 0);
    fclChkSignal(0);
    rcvUpdateCallSeq(0);
    rcvExit();
}

// 0x1996c20
void rcvUpdateSeqStatusRecover(void) {
    lstMoveCursor2(0, 0);
    rcvUpdateData();
    rcvUpdateCallSeq(0);
    fclChkSignal(0);
    FadeOutWindow();
}

// 0x1997f60
void rcvUpdateSeqTalk(void) {
  cmpSeqInfo_t_o *SeqInfo;

  fclSetVal(2, 0);
  SeqInfo = GBWK->SeqInfo;
  if (cmpChkSeqInfo(SeqInfo) == 2)
  {
    if (GBWK->SeqInfo->Current == 6)
    {
      fclSetVal(2, 2);
    }
    rcvUpdateCallSeq(GBWK->SeqInfo->Next);
    GBWK->SeqInfo->Change = -1;
  }
}
