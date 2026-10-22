#include "types.h"

typedef struct AssetBundles AssetBundles;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclDataShop_t fclDataShop_t;
typedef struct fclItemList_t fclItemList_t;
typedef struct lstListWindow_t lstListWindow_t;

void ButtonGuideDispOff(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
void DispInsfee(s32 sw);
u32 FCL_RAND(void);
void FadeOutWindow(void);
bool IsLoad(AssetBundles *this, char *key);
void SetButtonGuide(s32 mode, bool sw);
s32 datAddHearts(s32 id);
void datAddItem(s32 id, s32 num);
void datAddMaka(s32 addmaka);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetProcessStat(dds3ProcessID_t **id);
bool evtBitCheck(s32 no);
s32 fclAddItem(u16 ItemID, s32 Nums);
s8 fclChkDbgProcess(void);
s8 fclChkItemHearts(u16 ItemID);
s8 fclChkSignal(s8 Idx);
s8 fclChkVal(s8 Idx);
void fclClearSignal(s8 Idx);
void fclCreateItemListEx(fclItemList_t *pItemList, s8 Mode);
dds3ProcessID_t *fclScriptStart(u8 **pScriptData, s32 StartNo, dds3ProcessID_t **pPID);
s8 fclSetVal(s8 Idx, s32 Val);
void fclShopUpdateInit(fclDataShop_t *data);
void lstMoveCursor2(lstListWindow_t *pListWindow, s8 Dir);
void p2sdPlaySE_20173184(char *define_name);
s32 shpAddServiceTicket(s32 Nums);
s8 shpCalcPayOfMoney(s32 Index, s8 Mode);
s8 shpChkChoiceMax(s32 Index, s8 Mode, s8 CalcMode);
void shpCreateItemList(fclDataShop_t *pData);
void shpExit(void);
u16 shpGetItemFromItemBox(s32 BoxNo);
u16 shpGetItemID(s32 Index, s8 Mode);
void shpInitItemWindow(lstListWindow_t *pListWindow);
void shpServiceTicket(void);
void shpServiceTicketItem(void);
void shpUpdatePanelMover(void);
void shpUpdateSeqBuy(void);
void shpUpdateSeqBuyNums(void);
s8 shpUpdateSeqConfirm(s8 Mode);
void shpUpdateSeqErr(void);
void shpUpdateSeqPay(void);
void shpUpdateSeqRoot(void);
void shpUpdateSeqSell(void);
void shpUpdateSeqSellNums(void);
void shpUpdateSeqTalk(void);
void shpUpdateServiceTicket(void);
void shpUpdateServiceTicketItem(void);

// 0x19a6720
s32 shpAddServiceTicket(s32 Nums) {
  struct System_Byte_array *item;

  datAddItem(61, Nums);
  item = DDS3_GBWK->item;
  return item->m_Items[61];
}

// 0x19a6c90
void shpExit(void) {
  cmpCursorInfo_t_o *CursorInfo;
  struct fclDataShop_t_o *GBWK;
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
  SeqInfo->MesPID = fclScriptStart(pScriptData, 10, p_ScriptPID);
  GBWK->SeqInfo->Current = 4;
  SetButtonGuide(4, 0);
}

// 0x19a67e0
u16 shpGetItemFromItemBox(s32 BoxNo) {
  struct fclShopItemBox_t_array_array *fclShopItemBoxTbl;
  il2cpp_array_size_t max_length;
  u32 *v7;
  s32 v8;
  s32 v9;
  s64 v10;
  struct fclShopItemBox_t_array_array *v13;
  u64 v14;
  fclShopItemBox_t_array *v16;
  s32 v18;
  s8 v19;
  s8 v20;
  s32 Hearts;
  bool v22;
  fclShopItemBox_t_o *v23;
  u32 *v25;
  u32 *v26;
  struct fclShopItemBox_t_array_array *v29;
  fclShopItemBox_t_array *v31;
  struct fclShopItemBox_t_array_array *v34;
  fclShopItemBox_t_array *v36;
  u32 v39;
  u64 v40;
  s32 v41;
  s64 v43;
  s64 v46;

  else
  {
    if (!LODWORD(fclShopItemBoxTbl->max_length))
      goto LABEL_6;
  }
  max_length = fclShopItemBoxTbl->m_Items[0]->max_length;
  v7 = NewSpecific(fclShopItemBox_t, max_length);
  if (max_length >= 1)
  {
    v8 = 0;
    v9 = 0;
    v10 = 4;
    v46 = -max_length;
    while (1)
    {
      v13 = fclShopItemBoxTbl;
      v14 = v10 - 4;
      v16 = v13->m_Items[BoxNo];
      v18 = *(*(&v16->obj.klass + v10) + 18LL);
      v19 = fclChkItemHearts(v18);
      if (v19)
        break;
      if (v18)
        goto LABEL_30;
LABEL_52:
      ++v10;
      if (v46 + v10 == 4)
        goto LABEL_55;
    }
    v20 = v19;
    Hearts = cmbChkGetHearts(v20);
    if (v18)
      v22 = Hearts == 0;
    else
      v22 = 0;
    if (!v22)
      goto LABEL_52;
LABEL_30:
    v23 = Allocate(fclShopItemBox_t);
    fclShopItemBox_t___ctor(v23);
    v25 = &v7[2 * v9];
    *(v25 + 4) = v23;
    v26 = v25 + 8;
    v29 = fclShopItemBoxTbl;
    v31 = v29->m_Items[BoxNo];
    v23->Rate = *(*(&v31->obj.klass + v10) + 16LL);
    v34 = fclShopItemBoxTbl;
    v36 = v34->m_Items[BoxNo];
    *(*v26 + 18LL) = *(*(&v36->obj.klass + v10) + 18LL);
    ++v9;
    v8 += *(*v26 + 16LL);
    goto LABEL_52;
  }
  v9 = 0;
  v8 = 0;
LABEL_55:
  v39 = FCL_RAND();
  if (v9 < 1)
    return 0;
LABEL_58:
  v40 = 0;
  v41 = 0;
  while (1)
  {
    v43 = *&v7[2 * v40 + 8];
    v41 += *(v43 + 16);
    if (v41 > (v39 % v8))
      break;
    if (++v40 >= v9)
      return 0;
  }
  return *(v43 + 18);
}

// 0x19a9320
void shpServiceTicket(void) {
  u64 *v4;
  cmpCursorInfo_t_o *CursorInfo;
  u16 ItemFromItemBox;
  u16 v11;
  u16 v13;
  struct fclDataShop_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;
  s32 PayTotal;

  PayTotal = GBWK->PayTotal;
  v4 = sub_8D3950(s32, &PayTotal);
  Write_2930400("Total pay : {0:D}\n", v4);
  CursorInfo = GBWK->CmdSelInfo->CursorInfo;
  cmpMoveCursorListEnd(CursorInfo);
  fclClearSignal(4);
  fclClearSignal(5);
  ItemFromItemBox = shpGetItemFromItemBox(0);
  fclSetVal(4, ItemFromItemBox);
  v11 = shpGetItemFromItemBox(1);
  fclSetVal(5, v11);
  v13 = shpGetItemFromItemBox(2);
  fclSetVal(6, v13);
  if (GBWK->Place == 1)
  {
    updated = evtBitCheck(2353);
    if ((updated & 1) == 0)
    {
LABEL_23:
      shpExit();
      return;
    }
  }
  if (GBWK->PayTotal >= 1000)
  {
    shpAddServiceTicket(1);
    GBWK->ismsgend = 0;
    GBWK->SeqInfo->MesFlag = 1;
    SeqInfo = GBWK->SeqInfo;
    pScriptData = GBWK->pScriptData;
    p_ScriptPID = &GBWK->ScriptPID;
    SeqInfo->MesPID = fclScriptStart(pScriptData, 11, p_ScriptPID);
    GBWK->SeqInfo->Current = 10;
    SetButtonGuide(10, 0);
  }
  else
  {
    updated = shpAddServiceTicket(0);
    if (updated < 10)
      goto LABEL_23;
    shpServiceTicketItem();
  }
}

// 0x19a9200
void shpServiceTicketItem(void) {
  struct fclDataShop_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;

  GBWK->ismsgend = 0;
  GBWK->SeqInfo->MesFlag = 1;
  SeqInfo = GBWK->SeqInfo;
  pScriptData = GBWK->pScriptData;
  p_ScriptPID = &GBWK->ScriptPID;
  SeqInfo->MesPID = fclScriptStart(pScriptData, 12, p_ScriptPID);
  GBWK->SeqInfo->Current = 11;
  SetButtonGuide(11, 0);
}

// 0x19aa450
void *shpUpdate(dds3ProcessID_t *PID) {
  Il2CppObject *ProcessData;
  fclShopInit_c *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v14;
  AssetBundleCtrl_o *v19;
  s8 Current;
  fclShopInit_c *v25;
  struct fclShopInit_StaticFields **p_static_fields;
  struct fclDataShop_t_o *GBWK;
  s32 EventEnd;
  struct cmpSeqInfo_t_o *SeqInfo;
  u8 Flag;
  cmpSeqInfo_t_o *v32;
  struct cmpSeqInfo_t_o *v34;
  dds3ProcessID_t_o *v35;
  u64 v36[3];

  v35 = PID;
  else if (fclChkDbgProcess())
  {
    return 0;
  }
  ProcessData = dds3GetProcessData(&v35);
  else
  {
    if (!ProcessData)
      goto LABEL_20;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclDataShop_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclDataShop_t, v36);
    if ((v36[0] & 1) != 0)
      v10 = v36[2];
    else
      v10 = v36 + 1;
    v11 = sub_8C4940(v10);
  }
LABEL_20:
  GBWK = ProcessData;
  if (GBWK->Initialized)
  {
    if ((v6->_2.bitflags2 & 2) == 0)
    {
LABEL_47:
      Current = GBWK->SeqInfo->Current;
      shpUpdatePanelMover(v6);
      if (fclChkSignal(1))
      {
        if ((GBWK->SeqInfo->Flag & 0x40) != 0)
        {
          v35->func_ans = -1;
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
                  shpUpdateSeqRoot(v25);
                    goto LABEL_78;
                  goto LABEL_76;
                case 1:
                  shpUpdateSeqBuy(v25);
                    goto LABEL_78;
                  goto LABEL_76;
                case 2:
                  shpUpdateSeqSell(v25);
                    goto LABEL_78;
                  goto LABEL_76;
                case 3:
                  shpUpdateSeqTalk(v25);
                    goto LABEL_78;
                  goto LABEL_76;
                case 4:
                  if (cmpChkSeqInfo(SeqInfo) != 2)
                    break;
                  fclClearSignal(1);
                  fclSetVal(1, 0);
                  v34 = GBWK->SeqInfo;
                  v34->Flag |= 0x10u;
                    goto LABEL_78;
                  goto LABEL_76;
                case 5:
                  shpUpdateSeqBuyNums(v25);
                    goto LABEL_78;
                  goto LABEL_76;
                case 6:
                  shpUpdateSeqSellNums(v25);
                    goto LABEL_78;
                  goto LABEL_76;
                case 7:
                  shpUpdateSeqErr(v25);
                    goto LABEL_78;
                  goto LABEL_76;
                case 8:
                  if (shpUpdateSeqConfirm(SeqInfo->Last != 5))
                    break;
                  return 0;
                case 9:
                  shpUpdateSeqPay(v25);
                    goto LABEL_78;
                  goto LABEL_76;
                case 0xA:
                  shpUpdateServiceTicket(v25);
                    goto LABEL_78;
                  goto LABEL_76;
                case 0xB:
                  shpUpdateServiceTicketItem(v25);
                    goto LABEL_78;
                  goto LABEL_76;
                default:
                  break;
              }
            }
          }
          {
LABEL_76:
          }
LABEL_78:
          v32 = GBWK->SeqInfo;
          cmpUpdateSeqInfo(v32, Current);
        }
      }
      return 0;
    }
LABEL_22:
    goto LABEL_47;
  }
  asset_bc = get_asset_bc();
  if (IsLoad(asset_bc, "e802"))
  {
    v14 = get_asset_bc();
    if (IsLoad(v14, "f802"))
    {
      if (IsNullOrEmpty(VoiceName))
        goto LABEL_43;
      v19 = get_asset_bc();
      if (IsLoad(v19, VoiceName))
      {
LABEL_43:
        fclShopUpdateInit(GBWK);
        GBWK->Initialized = 1;
        if ((v6->_2.bitflags2 & 2) == 0)
          goto LABEL_47;
        goto LABEL_22;
      }
    }
  }
  return 0;
}

// 0x19aa370
void shpUpdatePanelMover(void) {
  u32 Current;
  s32 v5;

  Current = GBWK->SeqInfo->Current;
  if (Current > 9 || ((1 << Current) & 0x360) == 0)
  {
    else
    {
      v5 = 0;
    }
  }
  else
  {
    v5 = 1;
  }
  DispInsfee(v5);
}

// 0x19a6df0
void shpUpdateSeqBuy(void) {
  u16 v4;
  struct fclDataShop_t_o *GBWK;

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
    ButtonGuideDispSet("SHOP02", 0, 0, 90);
  }
}

// 0x19a7a80
void shpUpdateSeqBuyNums(void) {
  u16 v5;
  struct fclDataShop_t_o *GBWK;

  v5 = cmpChkCommonInput(CMP_PE_NORMAL | 0x300);
  else
  {
    if (GBWK->ismsgend)
      goto LABEL_9;
  }
  if (fclChkSignal(0))
  {
    GBWK->ismsgend = 1;
    FadeOutWindow();
    ButtonGuideDispSet("SHOP03", 0, 0, 90);
  }
}

// 0x19a86c0
s8 shpUpdateSeqConfirm(s8 Mode) {
  dds3ProcessID_t_o **p_ScriptPID;
  s32 v8;
  struct fclDataShop_t_o *v10;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **v12;
  s32 v15;
  struct fclDataShop_t_o *GBWK;
  struct fclDataShop_t_o *v18;
  System_Byte_array *v19;
  dds3ProcessID_t_o **v20;

  p_ScriptPID = &GBWK->ScriptPID;
  if (dds3GetProcessStat(p_ScriptPID) == 2)
    return 0;
  v8 = fclChkSignal(2);
  if (v8 <= 1)
  {
    if (!v8)
    {
      GBWK->IncVal = GBWK->PayMoney / 20;
      if (!GBWK->IncVal)
      {
        GBWK->IncVal = 1;
      }
      GBWK->SeqInfo->Current = 9;
      GBWK->SeqInfo->Change = -1;
      v15 = 9;
      goto LABEL_53;
    }
    if (v8 == 1)
    {
      if (Mode)
      {
        GBWK->ismsgend = 0;
        v10 = GBWK;
        pScriptData = v10->pScriptData;
        v12 = &v10->ScriptPID;
        *v12 = fclScriptStart(pScriptData, 4, v12);
        GBWK->SeqInfo->Current = 6;
        GBWK->SeqInfo->Change = 2;
        v15 = 6;
      }
      else
      {
        GBWK->ismsgend = 0;
        v18 = GBWK;
        v19 = v18->pScriptData;
        v20 = &v18->ScriptPID;
        *v20 = fclScriptStart(v19, 2, v20);
        GBWK->SeqInfo->Current = 5;
        GBWK->SeqInfo->Change = 2;
        v15 = 5;
      }
LABEL_53:
      SetButtonGuide(v15, 0);
    }
  }
  return 1;
}

// 0x19aa1d0
void shpUpdateSeqErr(void) {
  cmpSeqInfo_t_o *SeqInfo;
  struct fclDataShop_t_o *GBWK;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;
  struct cmpSeqInfo_t_o *v11;
  s32 Next;

  SeqInfo = GBWK->SeqInfo;
  if (cmpChkSeqInfo(SeqInfo) == 2)
  {
    GBWK->ismsgend = 0;
    pScriptData = GBWK->pScriptData;
    p_ScriptPID = &GBWK->ScriptPID;
    *p_ScriptPID = fclScriptStart(pScriptData, 1, p_ScriptPID);
    v11 = GBWK->SeqInfo;
    v11->Current = v11->Next;
    GBWK->SeqInfo->Change = 1;
    Next = GBWK->SeqInfo->Next;
    SetButtonGuide(Next, 0);
  }
}

// 0x19a8a30
void shpUpdateSeqPay(void) {
  struct fclDataShop_t_o *GBWK;
  cmpCursorInfo_t_o *CursorInfo;
  s32 Last;
  s32 CursorIndex;
  u16 ItemID;
  s32 v12;
  struct fclDataShop_t_o *v15;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;
  s32 v20;
  struct fclDataShop_t_o *v21;
  s32 PayMoney;
  s32 IncVal;
  fclItemList_t_o *SellItemList;
  struct fclDataShop_t_o *v26;
  u8 ItemCnt;
  cmpCursorInfo_t_o *v28;
  struct fclShopInit_StaticFields **p_static_fields;
  struct fclDataShop_t_o *v31;
  struct fclDataShop_t_o *v32;
  System_Byte_array *v33;
  dds3ProcessID_t_o **v34;
  s32 ChoiceNums;
  u16 v38;
  s32 v39;
  struct fclDataShop_t_o *v40;
  System_Byte_array *v41;
  dds3ProcessID_t_o **v42;
  s32 v45;
  struct fclDataShop_t_o *v48;
  struct cmpSeqInfo_t_o *SeqInfo;
  System_Byte_array *v50;
  dds3ProcessID_t_o **v51;

  CursorInfo = GBWK->ListWindow->CursorInfo;
  Last = GBWK->SeqInfo->Last;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  ItemID = shpGetItemID(CursorIndex, Last != 5);
  v12 = cmpChkSeqInfo(GBWK->SeqInfo);
  if (v12 != 1)
  {
    if (v12 == 2)
    {
      if (Last == 5)
      {
        GBWK->ChoiceNums = 1;
        GBWK->ismsgend = 0;
        v15 = GBWK;
        pScriptData = v15->pScriptData;
        p_ScriptPID = &v15->ScriptPID;
        *p_ScriptPID = fclScriptStart(pScriptData, 1, p_ScriptPID);
        GBWK->SeqInfo->Current = 1;
        GBWK->SeqInfo->Change = 1;
        v20 = 1;
      }
      else
      {
        GBWK->ChoiceNums = 1;
        SellItemList = GBWK->SellItemList;
        fclCreateItemListEx(SellItemList, 1);
        v26 = GBWK;
        ItemCnt = v26->SellItemList->ItemCnt;
        v28 = v26->ListWindow->CursorInfo;
        cmpChangeCursorListNums(ItemCnt, v28);
        v31 = GBWK;
        if (v31->SellItemList->ItemCnt)
        {
          v31->ismsgend = 0;
          v32 = (*p_static_fields)->GBWK;
          v33 = v32->pScriptData;
          v34 = &v32->ScriptPID;
          *v34 = fclScriptStart(v33, 3, v34);
          GBWK->SeqInfo->Current = 2;
          GBWK->SeqInfo->Change = 1;
          v20 = 2;
        }
        else
        {
          v31->ismsgend = 0;
          v40 = (*p_static_fields)->GBWK;
          v41 = v40->pScriptData;
          v42 = &v40->ScriptPID;
          *v42 = fclScriptStart(v41, 8, v42);
          GBWK->SeqInfo->Current = 0;
          GBWK->SeqInfo->Change = 1;
          v20 = 0;
        }
      }
      SetButtonGuide(v20, 0);
      return;
    }
    v21 = GBWK;
    PayMoney = v21->PayMoney;
    if (PayMoney >= 1)
    {
      else
      {
        IncVal = v21->IncVal;
        if (IncVal > PayMoney)
        {
LABEL_32:
          if (Last == 5)
          {
            PayMoney = -PayMoney;
          }
          {
            PayMoney = GBWK->PayMoney;
          }
          datAddMaka(PayMoney);
          if (Last == 5)
          {
            GBWK->PayTotal += GBWK->PayMoney;
          }
          GBWK->PayMoney = 0;
LABEL_126:
          p2sdPlaySE_20173184("COMSE_SE05");
          return;
        }
      }
      if (Last == 5)
      {
        IncVal = -IncVal;
      }
      {
        IncVal = GBWK->IncVal;
      }
      datAddMaka(IncVal);
      if (Last == 5)
      {
        GBWK->PayTotal += GBWK->IncVal;
      }
      GBWK->PayMoney -= GBWK->IncVal;
      goto LABEL_126;
    }
    if (Last == 5)
    {
      ChoiceNums = v21->ChoiceNums;
      v38 = ItemID;
      v39 = ChoiceNums;
    }
    else
    {
      v45 = v21->ChoiceNums;
      v39 = -v45;
      v38 = ItemID;
    }
    fclAddItem(v38, v39);
    GBWK->ismsgend = 0;
    GBWK->SeqInfo->MesFlag = 1;
    v48 = GBWK;
    SeqInfo = v48->SeqInfo;
    v50 = v48->pScriptData;
    v51 = &v48->ScriptPID;
    SeqInfo->MesPID = fclScriptStart(v50, 7, v51);
  }
}

// 0x19a98e0
void shpUpdateSeqRoot(void) {
  u16 v4;
  u32 v7;
  cmpCursorInfo_t_o *v10;
  cmpCursorInfo_t_o *v11;
  s8 v12;
  cmpCursorInfo_t_o *v16;
  struct fclDataShop_t_o *GBWK;
  u8 BuyItemCnt;
  cmpCursorInfo_t_o *v20;
  struct fclDataShop_t_o *v24;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o **p_ScriptPID;
  s32 v29;
  cmpCursorInfo_t_o *CursorInfo;
  cmpCursorInfo_t_o *v34;
  cmpCursorInfo_t_o *v36;
  u16 v37;
  fclItemList_t_o *SellItemList;
  struct fclDataShop_t_o *v41;
  u8 ItemCnt;
  cmpCursorInfo_t_o *v43;
  struct fclDataShop_t_o *v46;
  struct fclDataShop_t_o *v49;
  System_Byte_array *v50;
  dds3ProcessID_t_o **v51;
  struct fclDataShop_t_o *v56;
  struct cmpSeqInfo_t_o *SeqInfo;

  v4 = cmpChkCommonInput(CMP_PE_NORMAL);
  fclSetVal(2, 0);
  CursorIndex = fclChkSignal(0);
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
          goto LABEL_52;
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
        shpInitItemWindow(GBWK->ListWindow);
        shpCreateItemList(GBWK);
        v16 = GBWK->CmdSelInfo->CursorInfo;
        CursorIndex = cmpGetCursorIndex(v16);
        switch ()
        {
          case 0:
            BuyItemCnt = GBWK->BuyItemCnt;
            v20 = GBWK->ListWindow->CursorInfo;
            cmpChangeCursorListNums(BuyItemCnt, v20);
            GBWK->ChoiceNums = 1;
            shpCalcPayOfMoney(-1, 0);
            GBWK->ismsgend = 0;
            v24 = GBWK;
            pScriptData = v24->pScriptData;
            p_ScriptPID = &v24->ScriptPID;
            *p_ScriptPID = fclScriptStart(pScriptData, 1, p_ScriptPID);
            GBWK->SeqInfo->Current = 1;
            GBWK->SeqInfo->Change = 1;
            v29 = 1;
            goto LABEL_101;
          case 1:
            SellItemList = GBWK->SellItemList;
            fclCreateItemListEx(SellItemList, 1);
            v41 = GBWK;
            ItemCnt = v41->SellItemList->ItemCnt;
            v43 = v41->ListWindow->CursorInfo;
            cmpChangeCursorListNums(ItemCnt, v43);
            v46 = GBWK;
            if (!v46->SellItemList->ItemCnt)
              return;
            v46->ChoiceNums = 1;
            shpCalcPayOfMoney(-1, 1);
            GBWK->ismsgend = 0;
            v49 = GBWK;
            v50 = v49->pScriptData;
            v51 = &v49->ScriptPID;
            *v51 = fclScriptStart(v50, 3, v51);
            GBWK->SeqInfo->Current = 2;
            GBWK->SeqInfo->Change = 1;
            v29 = 2;
LABEL_101:
            SetButtonGuide(v29, 0);
              goto LABEL_55;
            goto LABEL_53;
          case 2:
            fclSetVal(2, 1);
            GBWK->ismsgend = 0;
            GBWK->SeqInfo->MesFlag = 1;
            v56 = GBWK;
            SeqInfo = v56->SeqInfo;
            SeqInfo->MesPID = fclScriptStart(v56->pScriptData, 9, &v56->ScriptPID);
            GBWK->SeqInfo->Current = 3;
            GBWK->SeqInfo->Last = 3;
            GBWK->SeqInfo->Change = -1;
            GBWK->SeqInfo->Next = 0;
            v29 = 3;
            goto LABEL_101;
          case 3:
            goto LABEL_13;
          default:
            goto LABEL_52;
        }
      }
      if (v4 == 2)
      {
LABEL_13:
        shpServiceTicket();
          goto LABEL_55;
        goto LABEL_53;
      }
    }
LABEL_52:
    {
LABEL_55:
      if (!cmpChkPadPressUpDown())
      {
        v34 = GBWK->CmdSelInfo->CursorInfo;
        cmpMoveCursor(v34, 0);
      }
      v36 = GBWK->CmdSelInfo->CursorInfo;
      v37 = cmpDisablePadBitStop(v36, v7, 0x30u);
      cmpPlaySE(v37);
      return;
    }
LABEL_53:
    goto LABEL_55;
  }
}

// 0x19a7500
void shpUpdateSeqSell(void) {
  u16 v4;
  s32 CursorIndex;
  struct fclDataShop_t_o *GBWK;
  struct System_UInt16_array *ItemIdx;
  struct fclDataShop_t_o *v13;
  s32 v16;
  lstListWindow_t_o *ListWindow;
  s8 v21;
  u16 v22;
  cmpCursorInfo_t_o *CursorInfo;
  u16 v27;
  struct fclDataShop_t_o *v29;

  v4 = cmpChkCommonInput(CMP_PE_NORMAL);
  CursorIndex = cmpGetCursorIndex(GBWK->ListWindow->CursorInfo);
  ItemIdx = GBWK->SellItemList->ItemIdx;
  if (GBWK->ismsgend)
  {
    if (v4 > 2u)
    {
      if (v4 == 16)
      {
        ListWindow = GBWK->ListWindow;
        v21 = -1;
      }
      else
      {
        if (v4 != 32)
          goto LABEL_67;
        ListWindow = GBWK->ListWindow;
        v21 = 1;
      }
      lstMoveCursor2(ListWindow, v21);
    }
    else
    {
      if (v4 == 1)
      {
        v22 = ItemIdx->m_Items[CursorIndex];
        shpCalcPayOfMoney(-1, 1);
        if (cmpChkItemStat(v22, 1))
        {
          if (cmpChkDoNotBuyItemTokusyu(v22) != 1)
          {
            GBWK->ismsgend = 0;
            fclClearSignal(0);
            v29 = GBWK;
            v29->ScriptPID = fclScriptStart(v29->pScriptData, 4, &v29->ScriptPID);
            GBWK->SeqInfo->Current = 6;
            GBWK->SeqInfo->Change = 1;
            v16 = 6;
LABEL_82:
            SetButtonGuide(v16, 0);
              goto LABEL_68;
LABEL_60:
            goto LABEL_68;
          }
        }
        v4 = 0x8000;
          goto LABEL_60;
LABEL_68:
        lstMoveCursor2(GBWK->ListWindow, 0);
        CursorInfo = GBWK->ListWindow->CursorInfo;
        v27 = cmpDisablePadBitStop(CursorInfo, v4, 0x30u);
        cmpPlaySE(v27);
        return;
      }
      if (v4 == 2)
      {
        GBWK->ismsgend = 0;
        fclClearSignal(0);
        v13 = GBWK;
        v13->ScriptPID = fclScriptStart(v13->pScriptData, 8, &v13->ScriptPID);
        GBWK->SeqInfo->Current = 0;
        GBWK->SeqInfo->Change = 2;
        v16 = 0;
        goto LABEL_82;
      }
    }
LABEL_67:
      goto LABEL_60;
    goto LABEL_68;
  }
  if (fclChkSignal(0))
  {
    GBWK->ismsgend = 1;
    FadeOutWindow();
    ButtonGuideDispSet("SHOP05", 0, 0, 90);
  }
}

// 0x19a8020
void shpUpdateSeqSellNums(void) {
  u16 v5;
  struct fclDataShop_t_o *GBWK;

  v5 = cmpChkCommonInput(CMP_PE_NORMAL | 0x300);
  else
  {
    if (GBWK->ismsgend)
      goto LABEL_9;
  }
  if (fclChkSignal(0))
  {
    GBWK->ismsgend = 1;
    FadeOutWindow();
    ButtonGuideDispSet("SHOP06", 0, 0, 90);
  }
}

// 0x19aa000
void shpUpdateSeqTalk(void) {
  cmpSeqInfo_t_o *SeqInfo;
  struct fclDataShop_t_o *GBWK;
  struct cmpSeqInfo_t_o *v10;
  s32 Next;

  fclSetVal(2, 0);
  SeqInfo = GBWK->SeqInfo;
  if (cmpChkSeqInfo(SeqInfo) == 2)
  {
    GBWK->ismsgend = 0;
    fclSetVal(2, 2);
    GBWK->ScriptPID = fclScriptStart(GBWK->pScriptData, 8, &GBWK->ScriptPID);
    v10 = GBWK->SeqInfo;
    v10->Current = v10->Next;
    GBWK->SeqInfo->Change = -1;
    Next = GBWK->SeqInfo->Next;
    SetButtonGuide(Next, 0);
  }
}

// 0x19a9600
void shpUpdateServiceTicket(void) {
  cmpSeqInfo_t_o *SeqInfo;

  SeqInfo = GBWK->SeqInfo;
  if (cmpChkSeqInfo(SeqInfo) == 2)
  {
    updated = shpAddServiceTicket(0);
    if (updated < 10)
      shpExit();
    else
      shpServiceTicketItem();
  }
}

// 0x19a96d0
void shpUpdateServiceTicketItem(void) {
  cmpSeqInfo_t_o *SeqInfo;
  _BOOL4 v6;
  s32 v8;
  s8 v9;
  u16 v11;
  s8 v12;
  s32 v14;

  SeqInfo = GBWK->SeqInfo;
  if (cmpChkSeqInfo(SeqInfo) == 2)
  {
    v6 = fclChkSignal(4) != 0;
    if (fclChkSignal(5))
      v8 = 2;
    else
      v8 = v6;
    if (v8)
    {
      if (v8 == 1)
      {
        v9 = 5;
      }
      else
      {
        v9 = 6;
      }
    }
    else
    {
      v9 = 4;
    }
    v11 = fclChkVal(v9);
    v12 = fclChkItemHearts(v11);
    if (v12)
    {
      v14 = v12;
      datAddHearts(v14);
    }
    else
    {
      datAddItem(v11, 1);
    }
    updated = shpAddServiceTicket(-10);
    shpExit();
  }
}
