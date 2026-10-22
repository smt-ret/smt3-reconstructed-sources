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
  Il2CppObject *ProcessData;
  fclRecoverInit_c *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v12;
  struct fclDataRecover_t_o *GBWK;
  s8 Current;
  fclRecoverInit_c *v19;
  struct fclDataRecover_t_o *v20;
  s32 EventEnd;
  struct cmpSeqInfo_t_o *SeqInfo;
  u8 Flag;
  dds3Basic_t_o *ControlScene;
  struct cmpSeqInfo_t_o *v31;
  cmpSeqInfo_t_o *v32;
  dds3ProcessID_t_o *v34;
  u64 v35[3];

  v34 = PID;
  ProcessData = dds3GetProcessData(&v34);
  else
  {
    if (!ProcessData)
      goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclDataRecover_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclDataRecover_t, v35);
    if ((v35[0] & 1) != 0)
      v8 = v35[2];
    else
      v8 = v35 + 1;
    v9 = sub_8C4940(v8);
  }
LABEL_15:
  GBWK = ProcessData;
  if (GBWK->Initialized)
  {
    if ((v4->_2.bitflags2 & 2) != 0)
    {
LABEL_17:
    }
  }
  else
  {
    asset_bc = get_asset_bc();
    if (!IsLoad(asset_bc, "e801"))
      return 0;
    v12 = get_asset_bc();
    if (!IsLoad(v12, "f801"))
      return 0;
    fclRecoverUpdateInit(GBWK);
    GBWK->Initialized = 1;
    if ((v4->_2.bitflags2 & 2) != 0)
      goto LABEL_17;
  }
  Current = GBWK->SeqInfo->Current;
  if (!GBWK->EffFlag)
  {
    if (!dds3GetControlScene())
      return 0;
    ControlScene = dds3GetControlScene();
    if (!dds3SceneBasicSearchNameAndType(ControlScene, 5u, "npc_kaihuku_e801"))
      return 0;
    fclLoadPB();
  }
  rcvUpdatePanelMover(v4);
  if (fclChkSignal(1))
  {
    v20 = GBWK;
    EventEnd = v20->EventEnd;
    if (EventEnd <= 9)
    {
      v20->EventEnd = EventEnd + 1;
      if (GBWK->EventEnd >= 5)
      {
        SetButtonGuide(0, 0);
      }
    }
    SeqInfo = GBWK->SeqInfo;
    Flag = SeqInfo->Flag;
    if ((Flag & 0x40) != 0)
    {
      v34->func_ans = -1;
      return 0;
    }
    else if ((SeqInfo->Flag & 2) != 0)
    {
LABEL_55:
      if ((Flag & 1) != 0)
      {
        switch (SeqInfo->Current)
        {
          case 0:
            rcvUpdateSeqRoot(v19);
              goto LABEL_119;
            goto LABEL_117;
          case 1:
            rcvUpdateSeqAllRecover(v19);
              goto LABEL_119;
            goto LABEL_117;
          case 2:
            rcvUpdateSeqRecover(v19);
              goto LABEL_119;
            goto LABEL_117;
          case 3:
            rcvUpdateSeqStatusRecover(v19);
              goto LABEL_119;
            goto LABEL_117;
          case 4:
            rcvUpdateSeqRevive(v19);
              goto LABEL_119;
            goto LABEL_117;
          case 5:
            if (rcvUpdateSeqDispel(v19))
              goto LABEL_116;
            break;
          case 6:
            rcvUpdateSeqTalk(v19);
              goto LABEL_119;
            goto LABEL_117;
          case 7:
            if (cmpChkSeqInfo(SeqInfo) == 2)
            {
              fclClearSignal(1);
              fclSetVal(1, 0);
              v31 = GBWK->SeqInfo;
              v31->Flag |= 0x10u;
            }
            goto LABEL_116;
          default:
            goto LABEL_116;
        }
        return 0;
      }
    }
LABEL_116:
    {
LABEL_117:
    }
LABEL_119:
    v32 = GBWK->SeqInfo;
    cmpUpdateSeqInfo(v32, Current);
  }
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
      goto LABEL_87;
    case 1:
      rcvCreateLocalStock(GBWK->LocalStock, 7);
      v4 = 1;
      v6 = 8;
      goto LABEL_21;
    case 2:
      v4 = 1;
      rcvCreateLocalStock(GBWK->LocalStock, 1);
      v6 = 0;
      goto LABEL_21;
    case 3:
      rcvCreateLocalStock(GBWK->LocalStock, 2);
      v6 = 0;
      v4 = 1;
      goto LABEL_21;
    case 4:
      rcvCreateLocalStock(GBWK->LocalStock, 4);
      v4 = 3;
      v6 = 10;
      goto LABEL_21;
    case 5:
      GBWK->AttrFlag = 0;
      unitwork = DDS3_GBWK->unitwork;
      if (unitwork->m_Items[0]->badstatus < 0)
      {
        v4 = 2;
LABEL_87:
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
        Item = object___get_Item(AnimObjs, "rcvfee");
        SetInteger(Item, "insfee", 0);
        if (GBWK->SeqInfo->Current)
        {
LABEL_37:
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
LABEL_81:
          GBWK->SeqInfo->Current = 6;
          GBWK->SeqInfo->Last = 6;
LABEL_82:
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
      goto LABEL_82;
    case 7:
      rcvExit(SeqNo);
      v4 = 0;
      goto LABEL_87;
    default:
      v6 = 0;
      v4 = 0;
LABEL_21:
      LocalStock = GBWK->LocalStock;
      if (LocalStock->StockCnt + LocalStock->PartyCnt)
        goto LABEL_87;
      v13 = object___get_Item(AnimObjs, "rcvfee");
      SetInteger(v13, "insfee", 0);
      v16 = GBWK;
      if (v16->SeqInfo->Current)
        goto LABEL_37;
      v16->ismsgend = 0;
      fclClearSignal(0);
      GBWK->SeqInfo->MesFlag = 1;
      v36 = GBWK;
      v37 = v36->SeqInfo;
      v37->MesPID = fclScriptStart(v36->pScriptData, v6, &v36->ScriptPID);
      goto LABEL_81;
  }
}

// 0x1995850
s8 rcvUpdateData(void) {
  struct fclDataRecover_t_o *GBWK;
  cmpCursorInfo_t_o *CursorInfo;
  char CursorIndex;
  struct datUnitWork_t_array *v7;
  struct System_SByte_array *StockIdx;
  s64 v10;
  datUnitWork_t_o *v13;
  struct datUnitWork_t_array *unitwork;
  struct System_Int32_array *Price;
  s32 v20;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  s32 maka;
  s8 result;
  struct System_Int32_array *v27;
  s64 *v29;
  s32 Id;

  if (!GBWK->AttrFlag)
    goto LABEL_23;
LABEL_6:
  CursorInfo = GBWK->StockWindow->CursorInfo;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  v7 = DDS3_GBWK->unitwork;
  StockIdx = GBWK->LocalStock->StockIdx;
  v10 = StockIdx->m_Items[CursorIndex];
  v13 = v7->m_Items[v10];
  {
LABEL_20:
  }
LABEL_29:
  Price = GBWK->Price;
  v20 = Price->m_Items[CursorIndex];
  maka = DDS3_GBWK->maka;
  if (v20 > maka)
    return 0;
  v27 = GBWK->Price;
  DDS3_GBWK->maka = maka - v27->m_Items[CursorIndex];
  switch (GBWK->AttrFlag)
  {
    case 1u:
      v13->hp = datGetMaxHp(v13);
      v13->mp = datGetMaxMp(v13);
      goto LABEL_73;
    case 2u:
      v13->badstatus &= 0xFE9Fu;
      goto LABEL_73;
    case 4u:
      v13->badstatus &= ~0x800u;
      v13->hp = (datGetMaxHp(v13) + 9) / 0xA;
      v29 = &"SHOPSND2_SE01";
      goto LABEL_69;
    case 7u:
      rcvAppAllRecover(v13);
      v29 = &"SHOPSND2_SE00";
      goto LABEL_69;
    default:
      v13->badstatus &= ~0x8000u;
      v29 = &"SHOPSND2_SE02";
LABEL_69:
      Id = FindId(1, *v29);
      p2sdPlaySE(Id);
LABEL_73:
      result = 1;
      break;
  }
  return result;
}

// 0x19975f0
void rcvUpdatePanelMover(void) {
  _BOOL4 v3;
  struct cmpSeqInfo_t_o *SeqInfo;
  Il2CppObject *Item;
  System_String_o *v9;
  s32 v10;

  if ((GBWK->SeqInfo->Current - 1) >= 4)
  {
    v3 = GBWK->SeqInfo->Current != 5;
    if ((byte_3F5ABEC & 1) != 0)
      goto LABEL_15;
    goto LABEL_14;
  }
  v3 = 0;
  if (fclChkSignal(0))
  {
    if ((byte_3F5ABEC & 1) != 0)
    {
LABEL_15:
      SeqInfo = GBWK->SeqInfo;
      if (SeqInfo->Current == 6)
      {
        else if (SeqInfo->Last == 5)
        {
          goto LABEL_22;
        }
      }
      if (v3)
      {
        Item = object___get_Item(AnimObjs, "rcvfee");
        v9 = "insfee";
        v10 = 0;
        goto LABEL_45;
      }
        goto LABEL_39;
      goto LABEL_23;
    }
LABEL_14:
    goto LABEL_15;
  }
}

// 0x19964c0
void rcvUpdateSeqAllRecover(void) {
  u32 v4;
  struct fclDataRecover_t_o *GBWK;
  cmpSeqInfo_t_o *SeqInfo;
  cmpCursorInfo_t_o *CursorInfo;
  u32 v22;

  v4 = cmpChkCommonInput(CMP_PE_NORMAL);
  if (!GBWK->ismsgend)
    goto LABEL_30;
LABEL_9:
  SeqInfo = GBWK->SeqInfo;
  v8 = cmpChkSeqInfo(SeqInfo);
  if (v8 != 1)
  {
    if (v8 == 2)
    {
      rcvUpdateCallSeq(0);
      GBWK->SeqInfo->Change = 1;
      return;
    }
    if (v4 > 2)
    {
      if (v4 == 16)
      {
        lstMoveCursor2(GBWK->StockWindow, 255);
        v4 = 16;
      }
      else if (v4 == 32)
      {
        lstMoveCursor2(GBWK->StockWindow, 1);
        v4 = 32;
          goto LABEL_67;
        goto LABEL_65;
      }
        goto LABEL_67;
    }
    else if (v4 == 1)
    {
      if (rcvUpdateData())
      {
        v4 = 1;
        rcvUpdateCallSeq(1);
        GBWK->SeqInfo->Change = 1;
          goto LABEL_67;
      }
      else
      {
        v4 = 0x8000;
          goto LABEL_67;
      }
    }
    else
    {
      if (v4 == 2)
      {
        rcvUpdateCallSeq(0);
        v4 = 2;
        GBWK->SeqInfo->Change = 2;
          goto LABEL_67;
        goto LABEL_65;
      }
      v4 = 0;
      {
LABEL_67:
        lstMoveCursor2(GBWK->StockWindow, 0);
        CursorInfo = GBWK->StockWindow->CursorInfo;
        v22 = cmpDisablePadBitStop(CursorInfo, v4, 0x30u);
        cmpPlaySE(v22);
        return;
      }
    }
LABEL_65:
    goto LABEL_67;
  }
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
  u32 v4;
  struct fclDataRecover_t_o *GBWK;

  v4 = cmpChkCommonInput(CMP_PE_NORMAL);
  else
  {
    if (GBWK->ismsgend)
      goto LABEL_9;
  }
  if (fclChkSignal(0))
  {
    GBWK->ismsgend = 1;
    FadeOutWindow();
  }
}

// 0x1996f60
void rcvUpdateSeqRevive(void) {
  u32 v4;
  struct fclDataRecover_t_o *GBWK;

  v4 = cmpChkCommonInput(CMP_PE_NORMAL);
  else
  {
    if (GBWK->ismsgend)
      goto LABEL_9;
  }
  if (fclChkSignal(0))
  {
    GBWK->ismsgend = 1;
    FadeOutWindow();
    ButtonGuideDispSet("REC03", 0, 0, 90);
  }
}

// 0x19978c0
void rcvUpdateSeqRoot(void) {
  u32 v4;
  char CursorIndex;
  cmpCursorInfo_t_o *v12;
  cmpCursorInfo_t_o *v15;
  fclRecoverInit_c *v17;
  u64 v18;
  struct cmpLocalStock_t_o *LocalStock;
  struct System_SByte_array *StockIdx;
  u64 *v22;
  struct System_Int32_array *Price;
  Il2CppObject *v24;
  u64 *v27;
  cmpCursorInfo_t_o *v30;
  cmpCursorInfo_t_o *v31;
  u32 v32;
  cmpCursorInfo_t_o *CursorInfo;
  u64 v35;
  struct cmpLocalStock_t_o *v36;
  struct System_SByte_array *v37;
  u32 v38;
  u64 *v40;
  struct System_Int32_array *v41;
  Il2CppObject *v42;
  u64 *v45;
  s32 v46;
  s8 v47[4];
  s32 v48;
  s8 v49[4];

  v4 = cmpChkCommonInput(CMP_PE_NORMAL);
  CursorIndex = cmpGetCursorIndex(GBWK->CmdSelInfo->CursorInfo);
  fclSetVal(2, 0);
  v8 = fclChkSignal(0);
  if ()
  {
    if (v4 > 2)
    {
      if (v4 == 16)
      {
        CursorInfo = GBWK->CmdSelInfo->CursorInfo;
        cmpMoveCursor(CursorInfo, 255);
        v4 = 16;
          goto LABEL_59;
      }
      else
      {
        if (v4 == 32)
        {
          v12 = GBWK->CmdSelInfo->CursorInfo;
          cmpMoveCursor(v12, 1);
          v4 = 32;
        }
          goto LABEL_59;
      }
    }
    else if (v4 == 1)
    {
      v15 = GBWK->CmdSelInfo->CursorInfo;
      if (cmpChkCursorIndexStat(v15))
      {
        rcvUpdateCallSeq(CursorIndex + 1);
        GBWK->SeqInfo->Change = 1;
        v18 = 0;
        if ((v17->_2.bitflags2 & 2) != 0)
        {
LABEL_44:
        }
        while (1)
        {
          LocalStock = GBWK->LocalStock;
          if (v18 >= LocalStock->PartyCnt)
            break;
          else
          {
            StockIdx = LocalStock->StockIdx;
            if (v18 >= LODWORD(StockIdx->max_length))
              goto LABEL_50;
          }
          v49[0] = StockIdx->m_Items[v18];
          v22 = sub_8D3950(sbyte, v49);
          Price = GBWK->Price;
          v24 = v22;
          v48 = Price->m_Items[v18];
          v27 = sub_8D3950(s32, &v48);
          Write_2930752("P : {0:D} {1:D}\n", v24, v27);
          ++v18;
            goto LABEL_44;
        }
        v35 = 0;
        if ((v17->_2.bitflags2 & 2) == 0)
          goto LABEL_88;
LABEL_86:
LABEL_88:
        while (1)
        {
          v36 = GBWK->LocalStock;
          if (v35 >= v36->StockCnt)
            break;
          v37 = v36->StockIdx;
          v38 = v35 + v36->PartyCnt;
          v47[0] = v37->m_Items[v38];
          v40 = sub_8D3950(sbyte, v47);
          v41 = GBWK->Price;
          v42 = v40;
          v46 = v41->m_Items[v35];
          v45 = sub_8D3950(s32, &v46);
          Write_2930752("S : {0:D} {1:D}\n", v42, v45);
          ++v35;
            goto LABEL_86;
        }
        Write("\n", 0);
        v4 = 1;
          goto LABEL_59;
      }
      else
      {
        v4 = 0x8000;
          goto LABEL_59;
      }
    }
    else if (v4 == 2)
    {
      rcvExit();
        goto LABEL_59;
    }
    else
    {
      v4 = 0;
        goto LABEL_59;
    }
LABEL_59:
    if (cmpChkPadPressUpDown())
    {
LABEL_60:
      {
LABEL_70:
        v31 = GBWK->CmdSelInfo->CursorInfo;
        v32 = cmpDisablePadBitStop(v31, v4, 0x30u);
        cmpPlaySE(v32);
        return;
      }
LABEL_61:
      goto LABEL_70;
    }
LABEL_63:
    v30 = GBWK->CmdSelInfo->CursorInfo;
    cmpMoveCursor(v30, 0);
      goto LABEL_70;
    goto LABEL_61;
  }
}

// 0x1996c20
void rcvUpdateSeqStatusRecover(void) {
  u32 v4;
  struct fclDataRecover_t_o *GBWK;

  v4 = cmpChkCommonInput(CMP_PE_NORMAL);
  else
  {
    if (GBWK->ismsgend)
      goto LABEL_9;
  }
  if (fclChkSignal(0))
  {
    GBWK->ismsgend = 1;
    FadeOutWindow();
  }
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
