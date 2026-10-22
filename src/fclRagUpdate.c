#include "types.h"

typedef struct AssetBundles AssetBundles;
typedef struct RippleEffect RippleEffect;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclDataRag_t fclDataRag_t;
typedef struct fclPanelMover_t fclPanelMover_t;
typedef struct fclRagDevil_t fclRagDevil_t;
typedef struct fclRagExchangeRate_t fclRagExchangeRate_t;
typedef struct lstListWindow_t lstListWindow_t;

void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
void DevilStatusMode(bool flag, bool stat);
void FadeOutWindow(void);
s32 FindId(s32 type, char *name);
void GetCurrentParam(void);
bool IsLoad(AssetBundles *this, char *key);
void RemakeFldSky(void);
void SetButtonGuide(s32 mode, bool sw);
void Update(RippleEffect *this);
void UpdateList(s32 mode);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetProcessStat(dds3ProcessID_t **id);
s32 fclAddItem(u16 ItemID, s32 Nums);
s8 fclChkDbgProcess(void);
s8 fclChkItemHearts(u16 ItemID);
s8 fclChkSignal(s8 Idx);
void fclClearSignal(s8 Idx);
s32 fclEncycRegist(datUnitWork_t *punit, s32 overwrite, bool update);
s8 fclRagChkExchange(fclRagExchangeRate_t **pRate);
void fclRagUpdateInit(fclDataRag_t *data);
void fclScriptForcedEnd(dds3ProcessID_t *PID);
dds3ProcessID_t *fclScriptStart(u8 **pScriptData, s32 StartNo, dds3ProcessID_t **pPID);
s8 fclSetVal(s8 Idx, s32 Val);
s32 fclUpdatePanelMover(fclPanelMover_t *pMover);
void lstMoveCursor(lstListWindow_t *pListWindow, s8 Dir);
s32 p2sdPlaySE(s32 a);
s8 ragChkDevilErr(u16 DevilID);
s8 ragChkDevilLevelErr(datUnitWork_t *pStock);
s8 ragChkItemErr(u16 ItemID);
void ragCreateAllList(s32 Mode, s32 Place, fclDataRag_t *pData);
void ragCreateDevilData(fclRagDevil_t *pDevil, datUnitWork_t *pData);
void ragExit(void);
fclRagExchangeRate_t **ragGetExchangeRate(s8 Type, u8 Index);
u16 ragGetSelectID(s8 SeqNo);
s8 ragGetSelectIdx(s8 SeqNo);
void ragSetSelectDevil(s8 SeqNo);
s8 ragUpdateCallSeq(s8 SeqNo);
void ragUpdatePanelMover(void);
void ragUpdateReturn(void);
s8 ragUpdateSeqConfirm(void);
void ragUpdateSeqErr(void);
void ragUpdateSeqItem(void);
void ragUpdateSeqMitama(void);
void ragUpdateSeqRoot(void);
void ragUpdateSeqSeirei(void);
void ragUpdateSeqStatus(void);
void ragUpdateSeqTalk(void);

// 0x198bdf0
s8 ragChkDevilErr(u16 DevilID) {
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  datUnitWork_t_array *unitwork;
  s32 maxstock;
  datUnitWork_t_array *v9;
  struct fclDataRag_t_o *v12;
  struct cmpSeqInfo_t_o *v13;
  System_Byte_array *v14;
  dds3ProcessID_t_o **v15;
  struct cmpSeqInfo_t_o *v18;
  struct cmpSeqInfo_t_o *v19;
  struct fclDataRag_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;
  struct cmpSeqInfo_t_o *v29;
  struct cmpSeqInfo_t_o *v30;

  unitwork = DDS3_GBWK->unitwork;
  maxstock = DDS3_GBWK->maxstock;
  if (cmbGetEmptyStockIndex(unitwork, maxstock, 4) < 0)
  {
    GBWK->ismsgend = 0;
    GBWK->SeqInfo->MesFlag = 1;
    SeqInfo = GBWK->SeqInfo;
    pScriptData = GBWK->pScriptData;
    p_ScriptPID = &GBWK->ScriptPID;
    SeqInfo->MesPID = fclScriptStart(pScriptData, 6, p_ScriptPID);
    v29 = GBWK->SeqInfo;
    v29->Next = v29->Current;
    v30 = GBWK->SeqInfo;
    v30->Last = v30->Current;
    GBWK->SeqInfo->Current = 6;
    GBWK->SeqInfo->Change = -1;
    SetButtonGuide(8, 0);
    ButtonGuideDispOff();
    return 1;
  }
  else
  {
    v9 = DDS3_GBWK->unitwork;
    if (cmbGetStockDevilIndex(DevilID, v9, 0x10u) < 0)
    {
      return 0;
    }
    else
    {
      GBWK->ismsgend = 0;
      GBWK->SeqInfo->MesFlag = 1;
      v12 = GBWK;
      v13 = v12->SeqInfo;
      v14 = v12->pScriptData;
      v15 = &v12->ScriptPID;
      v13->MesPID = fclScriptStart(v14, 5, v15);
      v18 = GBWK->SeqInfo;
      v18->Next = v18->Current;
      v19 = GBWK->SeqInfo;
      v19->Last = v19->Current;
      GBWK->SeqInfo->Current = 6;
      GBWK->SeqInfo->Change = -1;
      SetButtonGuide(0, 0);
      ButtonGuideDispOff();
      return 2;
    }
  }
}

// 0x198cd70
s8 ragChkDevilLevelErr(datUnitWork_t *pStock) {
  u32 level;
  struct datUnitWork_t_array *unitwork;
  struct fclDataRag_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;
  struct cmpSeqInfo_t_o *v13;
  struct cmpSeqInfo_t_o *v14;

  level = pStock->level;
  unitwork = DDS3_GBWK->unitwork;
  if (level <= unitwork->m_Items[0]->level)
    return 0;
  GBWK->ismsgend = 0;
  GBWK->SeqInfo->MesFlag = 1;
  SeqInfo = GBWK->SeqInfo;
  pScriptData = GBWK->pScriptData;
  p_ScriptPID = &GBWK->ScriptPID;
  SeqInfo->MesPID = fclScriptStart(pScriptData, 7, p_ScriptPID);
  v13 = GBWK->SeqInfo;
  v13->Next = v13->Last;
  v14 = GBWK->SeqInfo;
  v14->Last = v14->Current;
  GBWK->SeqInfo->Current = 6;
  GBWK->SeqInfo->Change = -1;
  SetButtonGuide(0, 0);
  ButtonGuideDispOff();
  return 1;
}

// 0x198b430
s8 ragChkItemErr(u16 ItemID) {
  struct System_Byte_array *item;
  struct fclDataRag_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;
  struct cmpSeqInfo_t_o *v13;
  struct cmpSeqInfo_t_o *v14;

  item = DDS3_GBWK->item;
  if (item->m_Items[ItemID] < 0x63u)
    return 0;
  GBWK->ismsgend = 0;
  GBWK->SeqInfo->MesFlag = 1;
  SeqInfo = GBWK->SeqInfo;
  pScriptData = GBWK->pScriptData;
  p_ScriptPID = &GBWK->ScriptPID;
  SeqInfo->MesPID = fclScriptStart(pScriptData, 4, p_ScriptPID);
  v13 = GBWK->SeqInfo;
  v13->Next = v13->Current;
  v14 = GBWK->SeqInfo;
  v14->Last = v14->Current;
  GBWK->SeqInfo->Current = 6;
  GBWK->SeqInfo->Change = -1;
  SetButtonGuide(6, 0);
  return 1;
}

// 0x198d870
void ragExit(void) {
  cmpCursorInfo_t_o *CursorInfo;
  struct fclDataRag_t_o *GBWK;
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
  SeqInfo->MesPID = fclScriptStart(pScriptData, 12, p_ScriptPID);
  GBWK->SeqInfo->Current = 5;
  SetButtonGuide(5, 0);
}

// 0x198b310
u16 ragGetSelectID(s8 SeqNo) {
  s8 SelectIdx;
  s8 v5;
  struct fclRagItem_t_array *fclRagItemTbl;

  SelectIdx = ragGetSelectIdx(SeqNo);
  if (SeqNo == 1)
  {
    v5 = SelectIdx;
    return fclRagItemTbl->m_Items[v5]->ItemID;
  }
  else if ((SeqNo & 0xFE) == 2)
  {
    return GBWK->Devil->id;
  }
  else
  {
    return 0;
  }
}

// 0x198b1a0
s8 ragGetSelectIdx(s8 SeqNo) {
  struct fclDataRag_t_o *v4;
  struct System_SByte_array *MitamaList;
  struct lstListWindow_t_o *MitamaWindow;
  struct fclDataRag_t_o *GBWK;
  struct fclDataRag_t_o *v10;
  cmpCursorInfo_t_o *CursorInfo;
  s32 CursorIndex;

  switch (SeqNo)
  {
    case 3:
      MitamaList = GBWK->MitamaList;
      MitamaWindow = GBWK->MitamaWindow;
      break;
    case 2:
      v10 = GBWK;
      MitamaList = v10->SeireiList;
      MitamaWindow = v10->SeireiWindow;
      break;
    case 1:
      v4 = GBWK;
      MitamaList = v4->ItemList;
      MitamaWindow = v4->ItemWindow;
      break;
    default:
      return 0;
  }
  CursorInfo = MitamaWindow->CursorInfo;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  return MitamaList->m_Items[CursorIndex];
}

// 0x198bbc0
void ragSetSelectDevil(s8 SeqNo) {
  cmpCursorInfo_t_o *v4;
  s64 v6;
  struct fclRagDevil_t_array *fclRagMitamaTbl;
  struct System_SByte_array *MitamaList;
  cmpCursorInfo_t_o *CursorInfo;
  s64 v15;

  if (SeqNo == 3)
  {
    CursorInfo = GBWK->MitamaWindow->CursorInfo;
    LOBYTE(v6) = cmpGetCursorIndex(CursorInfo);
    MitamaList = GBWK->MitamaList;
    if (v6 < LODWORD(MitamaList->max_length))
      goto LABEL_27;
LABEL_26:
  }
  if (SeqNo != 2)
    return;
  v4 = GBWK->SeireiWindow->CursorInfo;
  LOBYTE(v6) = cmpGetCursorIndex(v4);
  fclRagMitamaTbl = fclRagSeireiTbl;
  MitamaList = GBWK->SeireiList;
  if (v6 >= LODWORD(MitamaList->max_length))
    goto LABEL_26;
LABEL_27:
  v15 = MitamaList->m_Items[v6];
  ragCreateDevilData(fclRagMitamaTbl->m_Items[v15], GBWK->Devil);
}

// 0x198e550
void *ragUpdate(dds3ProcessID_t *PID) {
  Il2CppObject *ProcessData;
  fclRagInit_c *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v14;
  s8 Current;
  fclRagInit_c *v20;
  struct fclRagInit_StaticFields **p_static_fields;
  struct fclDataRag_t_o *GBWK;
  s32 EventEnd;
  struct cmpSeqInfo_t_o *SeqInfo;
  u8 Flag;
  cmpSeqInfo_t_o *v27;
  struct cmpSeqInfo_t_o *v29;
  dds3ProcessID_t_o *v30;
  u64 v31[3];

  v30 = PID;
  else if (fclChkDbgProcess())
  {
    return 0;
  }
  ProcessData = dds3GetProcessData(&v30);
  else
  {
    if (!ProcessData)
      goto LABEL_20;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclDataRag_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclDataRag_t, v31);
    if ((v31[0] & 1) != 0)
      v10 = v31[2];
    else
      v10 = v31 + 1;
    v11 = sub_8C4940(v10);
  }
LABEL_20:
  GBWK = ProcessData;
  if (GBWK->Initialized)
  {
    if ((v6->_2.bitflags2 & 2) == 0)
    {
LABEL_36:
      Current = GBWK->SeqInfo->Current;
      ragUpdatePanelMover(v6);
      if (fclChkSignal(1))
      {
        if ((GBWK->SeqInfo->Flag & 0x40) != 0)
        {
          v30->func_ans = -1;
        }
        else
        {
          EventEnd = GBWK->EventEnd;
          if (EventEnd <= 9)
          {
            GBWK->EventEnd = EventEnd + 1;
            if ((*p_static_fields)->GBWK->EventEnd >= 5)
            {
              SetButtonGuide(0, 0);
            }
            if (GBWK->EventEnd == 10)
            {
              GetCurrentParam();
            }
          }
          SeqInfo = GBWK->SeqInfo;
          Flag = SeqInfo->Flag;
          if ((Flag & 2) != 0)
          {
            if ((Flag & 1) != 0)
            {
              switch (SeqInfo->Current)
              {
                case 0:
                  ragUpdateSeqRoot(v20);
                    goto LABEL_75;
                  goto LABEL_73;
                case 1:
                  ragUpdateSeqItem(v20);
                    goto LABEL_75;
                  goto LABEL_73;
                case 2:
                  ragUpdateSeqSeirei(v20);
                    goto LABEL_75;
                  goto LABEL_73;
                case 3:
                  ragUpdateSeqMitama(v20);
                    goto LABEL_75;
                  goto LABEL_73;
                case 4:
                  ragUpdateSeqTalk(v20);
                    goto LABEL_75;
                  goto LABEL_73;
                case 5:
                  if (cmpChkSeqInfo(SeqInfo) != 2)
                    break;
                  fclClearSignal(1);
                  fclSetVal(1, 0);
                  v29 = GBWK->SeqInfo;
                  v29->Flag |= 0x10u;
                    goto LABEL_75;
                  goto LABEL_73;
                case 6:
                  ragUpdateSeqErr(v20);
                    goto LABEL_75;
                  goto LABEL_73;
                case 7:
                  ragUpdateSeqStatus(v20);
                    goto LABEL_75;
                  goto LABEL_73;
                case 8:
                  if (ragUpdateSeqConfirm(v20))
                    break;
                  return 0;
                default:
                  break;
              }
            }
          }
          {
LABEL_73:
          }
LABEL_75:
          v27 = GBWK->SeqInfo;
          cmpUpdateSeqInfo(v27, Current);
        }
      }
      return 0;
    }
LABEL_22:
    goto LABEL_36;
  }
  asset_bc = get_asset_bc();
  if (IsLoad(asset_bc, "e803"))
  {
    v14 = get_asset_bc();
    if (IsLoad(v14, "f803"))
    {
      fclRagUpdateInit(GBWK);
      GBWK->Initialized = 1;
      if ((v6->_2.bitflags2 & 2) == 0)
        goto LABEL_36;
      goto LABEL_22;
    }
  }
  return 0;
}

// 0x198d9d0
s8 ragUpdateCallSeq(s8 SeqNo) {
  cmpCursorInfo_t_o *CursorInfo;
  struct fclDataRag_t_o *GBWK;
  s32 v13;
  struct fclDataRag_t_o *v16;
  struct fclDataRag_t_o *v21;
  struct fclDataRag_t_o *v26;
  struct cmpSeqInfo_t_o *SeqInfo;

  ragCreateAllList(1, GBWK->Place, GBWK);
  GBWK->ismsgend = 0;
  CursorInfo = GBWK->CmdSelInfo->CursorInfo;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  switch ()
  {
    case 0:
      fclClearSignal(0);
      GBWK->ismsgend = 0;
      GBWK->ScriptPID = fclScriptStart(GBWK->pScriptData, 1, &GBWK->ScriptPID);
      GBWK->SeqInfo->Current = 1;
      GBWK->SeqInfo->Change = 1;
      v13 = 1;
      goto LABEL_50;
    case 1:
      fclClearSignal(0);
      GBWK->ismsgend = 0;
      v16 = GBWK;
      v16->ScriptPID = fclScriptStart(v16->pScriptData, 2, &v16->ScriptPID);
      GBWK->SeqInfo->Current = 2;
      GBWK->SeqInfo->Change = 1;
      v13 = 2;
      goto LABEL_50;
    case 2:
      fclClearSignal(0);
      GBWK->ismsgend = 0;
      v21 = GBWK;
      v21->ScriptPID = fclScriptStart(v21->pScriptData, 3, &v21->ScriptPID);
      GBWK->SeqInfo->Current = 3;
      GBWK->SeqInfo->Change = 1;
      v13 = 3;
      goto LABEL_50;
    case 3:
      fclSetVal(2, 1);
      GBWK->ismsgend = 0;
      GBWK->SeqInfo->MesFlag = 1;
      v26 = GBWK;
      SeqInfo = v26->SeqInfo;
      SeqInfo->MesPID = fclScriptStart(v26->pScriptData, 11, &v26->ScriptPID);
      GBWK->SeqInfo->Current = 4;
      GBWK->SeqInfo->Last = 4;
      GBWK->SeqInfo->Change = -1;
      GBWK->SeqInfo->Next = 0;
      v13 = 4;
LABEL_50:
      SetButtonGuide(v13, 0);
      break;
    case 4:
      ragExit();
      break;
    default:
      return 1;
  }
  return 1;
}

// 0x198de30
void ragUpdatePanelMover(void) {
  struct fclPanelMover_t_array *PanelMover;

  PanelMover = GBWK->PanelMover;
  fclUpdatePanelMover(PanelMover->m_Items[0]);
}

// 0x198c750
void ragUpdateReturn(void) {
  struct fclRagInit_StaticFields **p_static_fields;
  struct fclDataRag_t_o *GBWK;
  s32 Last;
  struct fclDataRag_t_o *v6;
  System_Byte_array *v7;
  dds3ProcessID_t_o **v8;
  s32 v10;
  struct fclDataRag_t_o *v11;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;
  struct fclDataRag_t_o *v15;
  System_Byte_array *v16;
  dds3ProcessID_t_o **v17;

  Last = GBWK->SeqInfo->Last;
  switch (Last)
  {
    case 3:
      GBWK->ismsgend = 0;
      v11 = (*p_static_fields)->GBWK;
      pScriptData = v11->pScriptData;
      p_ScriptPID = &v11->ScriptPID;
      *p_ScriptPID = fclScriptStart(pScriptData, 3, p_ScriptPID);
      GBWK->SeqInfo->Current = 3;
      v10 = 3;
      goto LABEL_39;
    case 2:
      GBWK->ismsgend = 0;
      v15 = (*p_static_fields)->GBWK;
      v16 = v15->pScriptData;
      v17 = &v15->ScriptPID;
      *v17 = fclScriptStart(v16, 2, v17);
      GBWK->SeqInfo->Current = 2;
      v10 = 2;
      goto LABEL_39;
    case 1:
      GBWK->ismsgend = 0;
      v6 = (*p_static_fields)->GBWK;
      v7 = v6->pScriptData;
      v8 = &v6->ScriptPID;
      *v8 = fclScriptStart(v7, 1, v8);
      GBWK->SeqInfo->Current = 1;
      v10 = 1;
LABEL_39:
      SetButtonGuide(v10, 0);
      break;
  }
  GBWK->SeqInfo->Change = 1;
}

// 0x198cf80
s8 ragUpdateSeqConfirm(void) {
  cmpSeqInfo_t_o *SeqInfo;
  s32 Current;
  dds3ProcessID_t_o **p_ScriptPID;
  s32 v15;
  s32 v19;
  s32 Last;
  s8 v23;
  fclRagExchangeRate_t_array *ExchangeRate;
  datUnitWork_t_o *Devil;
  s8 SelectIdx;
  s8 v29;
  struct fclDataRag_t_o *GBWK;
  datUnitWork_t_array *unitwork;
  s32 Id;
  fclRagExchangeRate_t_o *v39;
  u16 ItemID;
  struct datUnitWork_t_array *v42;
  struct datUnitWork_t_array *v44;
  struct datUnitWork_t_array *v46;
  datUnitWork_t_o *v48;
  s32 Nums;
  fclRagExchangeRate_t_o *v53;
  u16 v54;
  s32 v56;
  fclRagExchangeRate_t_o *v58;
  u16 v59;
  s32 v61;
  struct fclDataRag_t_o *v63;
  struct cmpSeqInfo_t_o *v64;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **v66;

  SeqInfo = GBWK->SeqInfo;
  v4 = cmpChkSeqInfo(SeqInfo);
  if (v4 != 1)
  {
    if (v4 == 2)
    {
      ragUpdateReturn();
      DevilStatusMode(0, 0);
      RemakeFldSky();
      Current = GBWK->SeqInfo->Current;
      UpdateList(Current);
LABEL_24:
      LOBYTE() = 1;
      return v4;
    }
    p_ScriptPID = &GBWK->ScriptPID;
    if (dds3GetProcessStat(p_ScriptPID) == 2)
    {
      LOBYTE() = 0;
      return v4;
    }
    v15 = fclChkSignal(2);
    if (v15 > 1)
      goto LABEL_24;
    if (v15)
    {
      if (v15 == 1)
      {
        DevilStatusMode(0, 0);
        RemakeFldSky();
        v19 = GBWK->SeqInfo->Current;
        UpdateList(v19);
        ragUpdateReturn();
      }
      goto LABEL_24;
    }
    Last = GBWK->SeqInfo->Last;
    if (Last == 3)
    {
      SelectIdx = ragGetSelectIdx(3);
      v29 = 2;
    }
    else
    {
      if (Last != 2)
      {
        if (Last == 1)
        {
          v23 = ragGetSelectIdx(1);
          ExchangeRate = ragGetExchangeRate(0, v23);
          LOWORD(Devil) = ragGetSelectID(1);
          fclAddItem(Devil, 1);
          LOBYTE(Devil) = 0;
        }
        else
        {
          LOBYTE(Devil) = 0;
          ExchangeRate = 0;
        }
        goto LABEL_76;
      }
      SelectIdx = ragGetSelectIdx(2);
      v29 = 1;
    }
    ExchangeRate = ragGetExchangeRate(v29, SelectIdx);
    Devil = GBWK->Devil;
    unitwork = DDS3_GBWK->unitwork;
    LOBYTE(Devil) = cmbAddCustomDevilToStock(Devil, unitwork, 0xCu, 4);
LABEL_76:
    Id = FindId(1, "P2SDREQ_ITEMGET");
    p2sdPlaySE(Id);
    if (Devil < 0)
      goto LABEL_128;
    if ((GBWK->SeqInfo->Last & 0xFE) == 2)
    {
      v42 = DDS3_GBWK->unitwork;
      v42->m_Items[Devil]->hp = DDS3_GBWK->unitwork->m_Items[Devil]->maxhp;
      v44 = DDS3_GBWK->unitwork;
      v44->m_Items[Devil]->mp = DDS3_GBWK->unitwork->m_Items[Devil]->maxmp;
      v46 = DDS3_GBWK->unitwork;
      v48 = v46->m_Items[Devil];
      fclEncycRegist(v48, 0, 0);
      if (LODWORD(ExchangeRate->max_length))
        goto LABEL_88;
    }
    else if (LODWORD(ExchangeRate->max_length))
    {
LABEL_88:
      v39 = ExchangeRate->m_Items[0];
      ItemID = v39->ItemID;
      if (ItemID)
      {
        Nums = v39->Nums;
        fclAddItem(ItemID, -Nums);
      }
      v53 = ExchangeRate->m_Items[1];
      v54 = v53->ItemID;
      if (v54)
      {
        v56 = v53->Nums;
        fclAddItem(v54, -v56);
      }
      v58 = ExchangeRate->m_Items[2];
      v59 = v58->ItemID;
      if (v59)
      {
        v61 = v58->Nums;
        fclAddItem(v59, -v61);
      }
LABEL_128:
      GBWK->ismsgend = 0;
      GBWK->SeqInfo->MesFlag = 1;
      v63 = GBWK;
      v64 = v63->SeqInfo;
      pScriptData = v63->pScriptData;
      v66 = &v63->ScriptPID;
      v64->MesPID = fclScriptStart(pScriptData, 9, v66);
      LOBYTE() = 0;
      return v4;
    }
  }
  return v4;
}

// 0x198e3d0
void ragUpdateSeqErr(void) {
  cmpSeqInfo_t_o *SeqInfo;
  s8 v5;
  s32 Current;

  SeqInfo = GBWK->SeqInfo;
  if (cmpChkSeqInfo(SeqInfo) == 2)
  {
    ragUpdateCallSeq(v5);
    GBWK->SeqInfo->Change = 1;
    DevilStatusMode(0, 0);
    RemakeFldSky();
    Current = GBWK->SeqInfo->Current;
    UpdateList(Current);
  }
}

// 0x198ab80
void ragUpdateSeqItem(void) {
  u16 v3;
  s8 SelectIdx;
  fclRagExchangeRate_t_array *ExchangeRate;
  struct fclRagInit_StaticFields **p_static_fields;
  struct fclDataRag_t_o *GBWK;
  struct fclDataRag_t_o *v11;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;
  cmpCursorInfo_t_o *v15;
  s32 v18;
  lstListWindow_t_o *ItemWindow;
  s8 v23;
  s8 v25;
  struct fclRagItem_t_array *fclRagItemTbl;
  s8 v28;
  u16 ItemID;
  s8 v32;
  s8 v33;
  s8 Hearts;
  u16 v35;
  cmpCursorInfo_t_o *CursorInfo;
  u16 v41;
  u16 SelectID;
  u16 v45;
  struct fclDataRag_t_o *v48;

  v3 = cmpChkCommonInput(CMP_PE_NORMAL);
  SelectIdx = ragGetSelectIdx(1);
  ExchangeRate = ragGetExchangeRate(0, SelectIdx);
  if (GBWK->ismsgend)
  {
    if (v3 > 2u)
    {
      if (v3 == 16)
      {
        ItemWindow = GBWK->ItemWindow;
        v23 = -1;
      }
      else
      {
        if (v3 != 32)
          goto LABEL_68;
        ItemWindow = GBWK->ItemWindow;
        v23 = 1;
      }
      lstMoveCursor(ItemWindow, v23);
      goto LABEL_68;
    }
    if (v3 == 1)
    {
      v25 = fclRagChkExchange(ExchangeRate);
      v28 = ragGetSelectIdx(1);
      ItemID = fclRagItemTbl->m_Items[v28]->ItemID;
      v32 = fclChkItemHearts(ItemID);
      if (v32)
      {
        v33 = v32;
        Hearts = cmbChkGetHearts(v33);
        v35 = 0x8000;
        if (Hearts || !v25)
        {
LABEL_69:
            goto LABEL_72;
LABEL_70:
LABEL_72:
          if (cmpChkPadPressUpDown())
          {
            {
LABEL_80:
              CursorInfo = GBWK->ItemWindow->CursorInfo;
              v41 = cmpDisablePadBitStop(CursorInfo, v35, 0x30u);
              cmpPlaySE(v41);
              return;
            }
          }
          else
          {
            lstMoveCursor(GBWK->ItemWindow, 0);
              goto LABEL_80;
          }
          goto LABEL_80;
        }
      }
      else if (!v25)
      {
        v35 = 0x8000;
          goto LABEL_72;
        goto LABEL_70;
      }
      SelectID = ragGetSelectID(1);
      if (!ragChkItemErr(SelectID))
      {
        v45 = ragGetSelectID(1);
        fclSetVal(8, v45);
        fclSetVal(9, 0);
        GBWK->ismsgend = 0;
        v48 = GBWK;
        v48->ScriptPID = fclScriptStart(v48->pScriptData, 8, &v48->ScriptPID);
        GBWK->SeqInfo->Current = 8;
        GBWK->SeqInfo->Change = 1;
        v18 = 8;
        goto LABEL_26;
      }
    }
    else if (v3 == 2)
    {
      GBWK->ismsgend = 0;
      v11 = (*p_static_fields)->GBWK;
      pScriptData = v11->pScriptData;
      p_ScriptPID = &v11->ScriptPID;
      *p_ScriptPID = fclScriptStart(pScriptData, 10, p_ScriptPID);
      v15 = GBWK->ItemWindow->CursorInfo;
      cmpResetCursorInfo(v15);
      GBWK->SeqInfo->Current = 0;
      GBWK->SeqInfo->Change = 2;
      v18 = 0;
LABEL_26:
      SetButtonGuide(v18, 0);
    }
LABEL_68:
    v35 = v3;
    goto LABEL_69;
  }
  if (fclChkSignal(0))
  {
    GBWK->ismsgend = 1;
    FadeOutWindow();
    ButtonGuideDispSet("RAG02", 0, 0, 90);
  }
}

// 0x198c1a0
void ragUpdateSeqMitama(void) {
  u16 v3;
  s8 SelectIdx;
  fclRagExchangeRate_t_array *ExchangeRate;
  struct fclRagInit_StaticFields **p_static_fields;
  struct fclDataRag_t_o *GBWK;
  struct fclDataRag_t_o *v11;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;
  cmpCursorInfo_t_o *v15;
  lstListWindow_t_o *MitamaWindow;
  s8 v23;
  dds3ProcessID_t_o *ScriptPID;
  u16 id;
  cmpCursorInfo_t_o *CursorInfo;
  u16 v36;

  v3 = cmpChkCommonInput(CMP_PE_NORMAL);
  SelectIdx = ragGetSelectIdx(3);
  ExchangeRate = ragGetExchangeRate(2, SelectIdx);
  if (GBWK->ismsgend)
  {
    if (v3 > 2u)
    {
      if (v3 == 16)
      {
        MitamaWindow = GBWK->MitamaWindow;
        v23 = -1;
      }
      else
      {
        if (v3 != 32)
          goto LABEL_72;
        MitamaWindow = GBWK->MitamaWindow;
        v23 = 1;
      }
      lstMoveCursor(MitamaWindow, v23);
    }
    else if (v3 == 1)
    {
      if (!fclRagChkExchange(ExchangeRate))
      {
        v3 = 0x8000;
          goto LABEL_75;
        goto LABEL_73;
      }
      ragSetSelectDevil(3);
      if (!ragChkDevilErr(GBWK->Devil->id))
      {
        ScriptPID = GBWK->ScriptPID;
        fclScriptForcedEnd(ScriptPID);
        GBWK->SeqInfo->Current = 7;
        GBWK->SeqInfo->Change = 1;
        DevilStatusMode(1, 0);
        SetButtonGuide(7, 0);
        Update(0);
        id = GBWK->Devil->id;
        cmpModelSetup(id, 0);
        {
LABEL_75:
          if (cmpChkPadPressUpDown())
          {
            {
LABEL_83:
              CursorInfo = GBWK->MitamaWindow->CursorInfo;
              v36 = cmpDisablePadBitStop(CursorInfo, v3, 0x30u);
              cmpPlaySE(v36);
              return;
            }
          }
          else
          {
            lstMoveCursor(GBWK->MitamaWindow, 0);
              goto LABEL_83;
          }
          goto LABEL_83;
        }
LABEL_73:
        goto LABEL_75;
      }
    }
    else if (v3 == 2)
    {
      GBWK->ismsgend = 0;
      v11 = (*p_static_fields)->GBWK;
      pScriptData = v11->pScriptData;
      p_ScriptPID = &v11->ScriptPID;
      *p_ScriptPID = fclScriptStart(pScriptData, 10, p_ScriptPID);
      v15 = GBWK->MitamaWindow->CursorInfo;
      cmpResetCursorInfo(v15);
      GBWK->SeqInfo->Current = 0;
      GBWK->SeqInfo->Change = 2;
      SetButtonGuide(0, 0);
        goto LABEL_75;
      goto LABEL_73;
    }
LABEL_72:
      goto LABEL_75;
    goto LABEL_73;
  }
  if (fclChkSignal(0))
  {
    GBWK->ismsgend = 1;
    FadeOutWindow();
    ButtonGuideDispSet("RAG06", 0, 0, 90);
  }
}

// 0x198dec0
void ragUpdateSeqRoot(void) {
  u16 v4;
  u32 v7;
  cmpCursorInfo_t_o *v10;
  cmpCursorInfo_t_o *v11;
  s8 v12;
  cmpCursorInfo_t_o *v14;
  s8 CursorIndex;
  cmpCursorInfo_t_o *CursorInfo;

  v4 = cmpChkCommonInput(CMP_PE_NORMAL);
  fclSetVal(2, 0);
  v5 = fclChkSignal(0);
  if ()
  {
    v7 = v4;
    if (v4 > 2u)
    {
      if (v4 == 16)
      {
        CursorInfo = GBWK->CmdSelInfo->CursorInfo;
        v11 = CursorInfo;
        v12 = -1;
      }
      else
      {
        if (v4 != 32)
          goto LABEL_41;
        v10 = GBWK->CmdSelInfo->CursorInfo;
        v11 = v10;
        v12 = 1;
      }
      cmpMoveCursor(v11, v12);
    }
    else
    {
      if (v4 == 1)
      {
        v14 = GBWK->CmdSelInfo->CursorInfo;
        CursorIndex = cmpGetCursorIndex(v14);
        ragUpdateCallSeq(CursorIndex);
          goto LABEL_43;
        goto LABEL_42;
      }
      if (v4 == 2)
      {
        ragExit();
          goto LABEL_43;
        goto LABEL_42;
      }
    }
LABEL_41:
      goto LABEL_43;
LABEL_42:
LABEL_43:
    if (!cmpChkPadPressUpDown())
      goto LABEL_44;
    goto LABEL_52;
  }
}

// 0x198b610
void ragUpdateSeqSeirei(void) {
  u16 v3;
  s8 SelectIdx;
  fclRagExchangeRate_t_array *ExchangeRate;
  struct fclRagInit_StaticFields **p_static_fields;
  struct fclDataRag_t_o *GBWK;
  struct fclDataRag_t_o *v11;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;
  cmpCursorInfo_t_o *v15;
  lstListWindow_t_o *SeireiWindow;
  s8 v23;
  dds3ProcessID_t_o *ScriptPID;
  u16 id;
  cmpCursorInfo_t_o *CursorInfo;
  u16 v36;

  v3 = cmpChkCommonInput(CMP_PE_NORMAL);
  SelectIdx = ragGetSelectIdx(2);
  ExchangeRate = ragGetExchangeRate(1, SelectIdx);
  if (GBWK->ismsgend)
  {
    if (v3 > 2u)
    {
      if (v3 == 16)
      {
        SeireiWindow = GBWK->SeireiWindow;
        v23 = -1;
      }
      else
      {
        if (v3 != 32)
          goto LABEL_72;
        SeireiWindow = GBWK->SeireiWindow;
        v23 = 1;
      }
      lstMoveCursor(SeireiWindow, v23);
    }
    else if (v3 == 1)
    {
      if (!fclRagChkExchange(ExchangeRate))
      {
        v3 = 0x8000;
          goto LABEL_75;
        goto LABEL_73;
      }
      ragSetSelectDevil(2);
      if (!ragChkDevilErr(GBWK->Devil->id))
      {
        ScriptPID = GBWK->ScriptPID;
        fclScriptForcedEnd(ScriptPID);
        GBWK->SeqInfo->Current = 7;
        GBWK->SeqInfo->Change = 1;
        DevilStatusMode(1, 0);
        SetButtonGuide(7, 0);
        Update(0);
        id = GBWK->Devil->id;
        cmpModelSetup(id, 0);
        {
LABEL_75:
          if (cmpChkPadPressUpDown())
          {
            {
LABEL_83:
              CursorInfo = GBWK->SeireiWindow->CursorInfo;
              v36 = cmpDisablePadBitStop(CursorInfo, v3, 0x30u);
              cmpPlaySE(v36);
              return;
            }
          }
          else
          {
            lstMoveCursor(GBWK->SeireiWindow, 0);
              goto LABEL_83;
          }
          goto LABEL_83;
        }
LABEL_73:
        goto LABEL_75;
      }
    }
    else if (v3 == 2)
    {
      GBWK->ismsgend = 0;
      v11 = (*p_static_fields)->GBWK;
      pScriptData = v11->pScriptData;
      p_ScriptPID = &v11->ScriptPID;
      *p_ScriptPID = fclScriptStart(pScriptData, 10, p_ScriptPID);
      v15 = GBWK->SeireiWindow->CursorInfo;
      cmpResetCursorInfo(v15);
      GBWK->SeqInfo->Current = 0;
      GBWK->SeqInfo->Change = 2;
      SetButtonGuide(0, 0);
        goto LABEL_75;
      goto LABEL_73;
    }
LABEL_72:
      goto LABEL_75;
    goto LABEL_73;
  }
  if (fclChkSignal(0))
  {
    GBWK->ismsgend = 1;
    FadeOutWindow();
    ButtonGuideDispSet("RAG04", 0, 0, 90);
  }
}

// 0x198ca20
void ragUpdateSeqStatus(void) {
  u16 v4;
  s32 Current;
  s32 id;
  struct fclDataRag_t_o *GBWK;

  v4 = cmpChkCommonInput(CMP_PE_NORMAL);
  else
  {
    Stat = cmpChkStatusModelLoadStat();
    if ()
      goto LABEL_9;
  }
  if (v4 > 2u)
  {
    if (v4 == 16 || v4 == 32)
    {
      v4 = 0;
      {
LABEL_10:
      }
LABEL_33:
      cmpPlaySE(v4);
      return;
    }
LABEL_9:
      goto LABEL_10;
    goto LABEL_33;
  }
  if (v4 != 1)
  {
    if (v4 == 2)
    {
      ragUpdateReturn();
      DevilStatusMode(0, 0);
      RemakeFldSky();
      Current = GBWK->SeqInfo->Current;
      UpdateList(Current);
        goto LABEL_33;
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  if (!ragChkDevilLevelErr(GBWK->Devil))
  {
    id = GBWK->Devil->id;
    fclSetVal(8, id);
    fclSetVal(9, 1);
    GBWK->ismsgend = 0;
    GBWK->ScriptPID = fclScriptStart(GBWK->pScriptData, 8, &GBWK->ScriptPID);
    GBWK->SeqInfo->Current = 8;
    GBWK->SeqInfo->Change = -1;
    SetButtonGuide(8, 0);
      goto LABEL_33;
    goto LABEL_10;
  }
}

// 0x198e200
void ragUpdateSeqTalk(void) {
  cmpSeqInfo_t_o *SeqInfo;
  struct fclDataRag_t_o *GBWK;
  struct cmpSeqInfo_t_o *v11;
  s32 Next;

  fclSetVal(2, 0);
  SeqInfo = GBWK->SeqInfo;
  if (cmpChkSeqInfo(SeqInfo) == 2)
  {
    fclSetVal(2, 2);
    GBWK->ismsgend = 0;
    GBWK->ScriptPID = fclScriptStart(GBWK->pScriptData, 10, &GBWK->ScriptPID);
    v11 = GBWK->SeqInfo;
    v11->Current = v11->Next;
    GBWK->SeqInfo->Change = -1;
    Next = GBWK->SeqInfo->Next;
    SetButtonGuide(Next, 0);
  }
}
