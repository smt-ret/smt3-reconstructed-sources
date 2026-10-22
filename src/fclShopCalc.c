#include "types.h"

typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclDataShop_t fclDataShop_t;

void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetProcessStat(dds3ProcessID_t **id);
bool evtBitCheck(s32 no);
s8 fclChkDbgProcess(void);
s8 fclChkItemHearts(u16 ItemID);
s8 fclChkSignal(s8 Idx);
s32 fclClearPanelTimer(void *a);
void fclClearSignal(s8 Idx);
dds3ProcessID_t *fclScriptStart(u8 **pScriptData, s32 StartNo, dds3ProcessID_t **pPID);
s8 fclSetVal(s8 Idx, s32 Val);
void fclShopEventStart(s8 Signal);
s32 shpCalcItemPrice(s32 Index, s8 Mode);
s8 shpCalcPayOfMoney(s32 Index, s8 Mode);
u16 shpGetItemID(s32 Index, s8 Mode);
s32 shpGetPackID(s32 Place);
s32 shpGetShopItemNums(s32 Place);

// 0x19a0560
void *shpCalc(dds3ProcessID_t *PID) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct fclDataShop_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  struct fclDataShop_t_o *v16;
  dds3ProcessID_t_o **p_ScriptPID;
  struct fclDataShop_t_o *v19;
  System_Byte_array *pScriptData;
  struct cmpSeqInfo_t_o *v22;
  dds3ProcessID_t_o *pPID;
  dds3ProcessID_t_o *id;
  u64 v25[3];

  id = PID;
  pPID = 0;
  ProcessData = dds3GetProcessData(&id);
  else
  {
    if (!ProcessData)
      goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclDataShop_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclDataShop_t, v25);
    if ((v25[0] & 1) != 0)
      v7 = v25[2];
    else
      v7 = v25 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_15:
  GBWK = ProcessData;
  else if (fclChkDbgProcess())
  {
    return 0;
  }
  else if (GBWK->InitFlag)
  {
    goto LABEL_30;
  }
  fclShopEventStart(1);
  GBWK->InitFlag = 1;
LABEL_30:
  if (fclChkSignal(1))
  {
    SeqInfo = GBWK->SeqInfo;
    if (SeqInfo->Current == 8)
    {
      if (SeqInfo->Change == 1)
      {
        fclClearSignal(2);
      }
    }
    else if (!SeqInfo->Current)
    {
      fclClearPanelTimer(GBWK->BackPanel);
      v16 = GBWK;
      if (v16->SeqInfo->Change == 1)
      {
        p_ScriptPID = &v16->ScriptPID;
        if (dds3GetProcessStat(p_ScriptPID) != 2)
        {
          pPID = 0;
          v19 = GBWK;
          pScriptData = v19->pScriptData;
          v19->ScriptPID = fclScriptStart(pScriptData, 0, &pPID);
            goto LABEL_69;
          goto LABEL_67;
        }
      }
    }
    {
LABEL_69:
      GBWK->SeqInfo->Change = 0;
      v22 = GBWK->SeqInfo;
      if ((v22->Flag & 0x10) != 0)
      {
        cmpUpdateTerminate(v22);
        id->func_ans = -1;
      }
      return 0;
    }
LABEL_67:
    goto LABEL_69;
  }
  return 0;
}

// 0x199fd80
s32 shpCalcItemPrice(s32 Index, s8 Mode) {
  u16 ItemID;
  struct datItem_t_array *tbl;
  u8 PackID;
  struct fclShopItemPack_t_array *fclShopItemPackTbl;
  u32 BaseRate;
  struct fclShopItemBase_t_array *ItemList;
  s64 Rate;
  struct datItem_t_array *v22;
  u64 v24;

  ItemID = shpGetItemID(Index, Mode);
  if (Mode)
  {
    return tbl->m_Items[ItemID]->price >> 1;
  }
  else
  {
    PackID = shpGetPackID(GBWK->Place);
    BaseRate = fclShopItemPackTbl->m_Items[PackID]->BaseRate;
    ItemList = fclShopItemPackTbl->m_Items[PackID]->ItemList;
    if (ItemList->m_Items[Index]->Rate)
      Rate = ItemList->m_Items[Index]->Rate;
    else
      Rate = BaseRate;
    v22 = tbl;
    v24 = v22->m_Items[ItemID]->price * Rate / 0x64;
    if (cfgGetBit(9u) == 2)
      return 3 * v24;
    else
      return v24;
  }
}

// 0x19a0000
s8 shpCalcPayOfMoney(s32 Index, s8 Mode) {
  s32 v7;
  bool v8;
  struct System_Byte_array *v9;
  u16 ItemID;
  struct System_Byte_array *item;
  cmpCursorInfo_t_o *CursorInfo;

  if ((Index & 0x80000000) == 0)
  {
    v7 = shpCalcItemPrice(Index, Mode);
    v8 = Mode == 0;
    LOBYTE(v9) = -1;
    if (!v8)
      return v9;
    goto LABEL_6;
  }
  CursorInfo = GBWK->ListWindow->CursorInfo;
  Index = cmpGetCursorIndex(CursorInfo);
  v7 = shpCalcItemPrice(Index, Mode);
  GBWK->PayMoney = v7 * GBWK->ChoiceNums;
  v8 = Mode == 0;
  LOBYTE(v9) = -1;
  if (v8)
  {
LABEL_6:
    if (v7 >= 1)
    {
      if (DDS3_GBWK->maka / v7 >= 99)
        LODWORD(v9) = 99;
      else
        LODWORD(v9) = DDS3_GBWK->maka / v7;
      ItemID = shpGetItemID(Index, 0);
      item = DDS3_GBWK->item;
      if (v9 + item->m_Items[ItemID] >= 100)
      {
        v9 = DDS3_GBWK->item;
        LOBYTE(v9) = 99 - v9->m_Items[ItemID];
      }
    }
  }
  return v9;
}

// 0x19a0230
s8 shpChkChoiceMax(s32 Index, s8 Mode, s8 CalcMode) {
  struct fclDataShop_t_o *GBWK;
  s32 PayMoney;
  cmpCursorInfo_t_o *CursorInfo;
  s32 CursorIndex;
  struct System_UInt16_array *ItemIdx;
  s64 v18;
  struct System_Byte_array *item;
  cmpCursorInfo_t_o *v22;
  s32 v24;
  struct System_UInt16_array *BuyItemList;
  u16 v28;
  s32 v29;

  PayMoney = GBWK->PayMoney;
  if (Mode)
  {
    shpCalcPayOfMoney(Index, 1, CalcMode);
    CursorInfo = GBWK->ListWindow->CursorInfo;
    CursorIndex = cmpGetCursorIndex(CursorInfo);
    ItemIdx = GBWK->SellItemList->ItemIdx;
    v18 = ItemIdx->m_Items[CursorIndex];
    item = DDS3_GBWK->item;
    LOBYTE(v18) = item->m_Items[v18];
    if (!CalcMode)
      return v18;
LABEL_47:
    GBWK->PayMoney = PayMoney;
    return v18;
  }
  v22 = GBWK->ListWindow->CursorInfo;
  v24 = cmpGetCursorIndex(v22);
  BuyItemList = GBWK->BuyItemList;
  v28 = BuyItemList->m_Items[v24];
  v29 = fclChkItemHearts(v28);
  LODWORD(v18) = shpCalcPayOfMoney(Index, 0);
  if (v29 && v18 >= 1)
    LOBYTE(v18) = 1;
  if (CalcMode)
    goto LABEL_47;
  return v18;
}

// 0x199fb80
void shpCreateItemList(fclDataShop_t *pData) {
  u8 PackID;
  u8 v4;
  u64 v7;
  s64 v8;
  struct fclShopItemPack_t_array *fclShopItemPackTbl;
  struct fclShopItemBase_t_array *ItemList;
  u16 ID;
  s8 v15;
  s8 v17;
  u32 BuyItemCnt;
  struct System_UInt16_array *BuyItemList;
  s32 HeartsFlag;

  PackID = shpGetPackID(pData->Place);
  *&pData->BuyItemCnt = 0;
  v4 = PackID;
  if (shpGetShopItemNums(pData->Place) >= 1)
  {
    v7 = 0;
    v8 = v4;
    do
    {
      ItemList = fclShopItemPackTbl->m_Items[v8]->ItemList;
      ID = ItemList->m_Items[v7]->ID;
      v15 = fclChkItemHearts(ID);
      if (v15)
      {
        v17 = v15;
        if (cmbChkGetHearts(v17))
          goto LABEL_24;
        pData->HeartsFlag = 1;
      }
      BuyItemCnt = pData->BuyItemCnt;
      BuyItemList = pData->BuyItemList;
      ++pData->BuyItemCnt;
      BuyItemList->m_Items[BuyItemCnt] = ID;
LABEL_24:
      ++v7;
    }
    while (v7 < shpGetShopItemNums(pData->Place));
  }
  HeartsFlag = pData->HeartsFlag;
  fclSetVal(4, HeartsFlag);
}

// 0x199f830
u16 shpGetItemID(s32 Index, s8 Mode) {
  struct System_UInt16_array *ItemIdx;
  s64 v7;

  if (Mode)
  {
    ItemIdx = GBWK->SellItemList->ItemIdx;
    v7 = Index;
    if (LODWORD(ItemIdx->max_length) <= Index)
      goto LABEL_8;
  }
  else
  {
    ItemIdx = GBWK->BuyItemList;
    v7 = Index;
    if (LODWORD(ItemIdx->max_length) <= Index)
    {
LABEL_8:
    }
  }
  return ItemIdx->m_Items[v7];
}

// 0x199f920
s32 shpGetPackID(s32 Place) {
  struct fclShopTbl_t_array *fclShopTbl;
  struct System_Int16_array *EventBitPos;
  s32 v7;
  _BOOL8 v8;
  struct fclShopTbl_t_array *v11;
  struct System_Byte_array *ItemPackID;

  EventBitPos = fclShopTbl->m_Items[Place]->EventBitPos;
  v7 = EventBitPos->m_Items[0];
  if (v7 < 0)
  {
    v8 = 0;
      goto LABEL_15;
  }
  else
  {
    v8 = evtBitCheck(v7);
      goto LABEL_15;
  }
LABEL_15:
  v11 = fclShopTbl;
  ItemPackID = v11->m_Items[Place]->ItemPackID;
  return ItemPackID->m_Items[v8];
}

// 0x199fa80
s32 shpGetShopItemNums(s32 Place) {
  u8 PackID;
  u64 v5;
  s32 v6;
  s64 v7;
  struct fclShopItemPack_t_array *fclShopItemPackTbl;
  struct fclShopItemBase_t_array *ItemList;
  s64 v13;

  PackID = shpGetPackID(Place);
  v5 = 0;
  v6 = 0;
  v7 = PackID;
  do
  {
    ItemList = fclShopItemPackTbl->m_Items[v7]->ItemList;
    v13 = ItemList + 8 * v5++;
    if (*(*(v13 + 32) + 16LL))
      ++v6;
  }
  while (v5 != 32);
  return v6;
}

// 0x199f7f0
s32 shpIncSelectNums(s32 Val, s8 Inc) {
  s32 v3;

  v3 = Val % Inc;
  if (!v3)
    return Inc + Val;
  if (Inc < 0)
    return Val - v3;
  return Inc + Val - v3;
}
