#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclRagDevil_t fclRagDevil_t;
typedef struct fclRagExchangeRate_t fclRagExchangeRate_t;

dds3Basic_t *dds3GetActiveScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetProcessStat(dds3ProcessID_t **id);
void dds3VisibleSceneBasic(dds3Basic_t **basic, s32 visible);
s8 fclChkDbgProcess(void);
void fclRagEventStart(s8 Signal);
dds3ProcessID_t *fclScriptStart(u8 **pScriptData, s32 StartNo, dds3ProcessID_t **pPID);
void ragCalcSeqStatus(void);

// 0x13cdc80
s8 fclRagChkExchange(fclRagExchangeRate_t **pRate) {
  fclRagExchangeRate_t_o *v3;
  s64 ItemID;
  struct System_Byte_array *item;
  s32 v8;
  fclRagExchangeRate_t_o *v9;
  s64 v10;
  struct System_Byte_array *v15;
  s32 v17;
  fclRagExchangeRate_t_o *v19;
  s64 v20;
  struct System_Byte_array *v22;
  s32 v24;

  if ((byte_3F596F3 & 1) != 0)
  {
    if (LODWORD(pRate->max_length))
      goto LABEL_3;
LABEL_6:
  }
  if (!LODWORD(pRate->max_length))
    goto LABEL_6;
LABEL_3:
  v3 = pRate->m_Items[0];
  ItemID = v3->ItemID;
  if (v3->ItemID)
  {
    item = DDS3_GBWK->item;
    v8 = item->m_Items[ItemID];
    if (v8 < pRate->m_Items[0]->Nums)
      return 0;
  }
  v9 = pRate->m_Items[1];
  v10 = v9->ItemID;
  if (v9->ItemID)
  {
    v15 = DDS3_GBWK->item;
    v17 = v15->m_Items[v10];
    if (v17 < pRate->m_Items[1]->Nums)
      return 0;
  }
  v19 = pRate->m_Items[2];
  v20 = v19->ItemID;
  if (!v19->ItemID)
    return 1;
  v22 = DDS3_GBWK->item;
  v24 = v22->m_Items[v20];
  return v24 >= pRate->m_Items[2]->Nums;
}

// 0x13ce370
void *ragCalc(dds3ProcessID_t *PID) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct System_SByte_array *gFclSignal;
  fclRagInit_c *v15;
  struct fclDataRag_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  struct fclDataRag_t_o *v20;
  dds3ProcessID_t_o **p_ScriptPID;
  struct fclDataRag_t_o *v24;
  System_Byte_array *pScriptData;
  struct System_SByte_array *v27;
  struct cmpSeqInfo_t_o *v29;
  dds3ProcessID_t_o *v30;
  dds3Basic_t_o *basic;
  dds3ProcessID_t_o *id;
  u64 v33[3];

  id = PID;
  basic = 0;
  v30 = 0;
  ProcessData = dds3GetProcessData(&id);
  else
  {
    if (!ProcessData)
      goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclDataRag_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclDataRag_t, v33);
    if ((v33[0] & 1) != 0)
      v7 = v33[2];
    else
      v7 = v33 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_15:
  GBWK = ProcessData;
  else if (fclChkDbgProcess())
  {
    return 0;
  }
  else if (!GBWK->InitFlag)
  {
    goto LABEL_25;
  }
  if (gFclSignal->m_Items[1])
  {
    SeqInfo = GBWK->SeqInfo;
    switch (SeqInfo->Current)
    {
      case 0:
        GBWK->BackPanel->Timer = 0;
        v20 = GBWK;
        if (v20->SeqInfo->Change != 1)
          goto LABEL_94;
        p_ScriptPID = &v20->ScriptPID;
        if (dds3GetProcessStat(p_ScriptPID) == 2)
          goto LABEL_94;
        v30 = 0;
        v24 = GBWK;
        pScriptData = v24->pScriptData;
        v24->ScriptPID = fclScriptStart(pScriptData, 0, &v30);
          goto LABEL_95;
        break;
      case 2:
      case 3:
        basic = dds3GetActiveScene();
        if (basic)
        {
          dds3VisibleSceneBasic(&basic, 1);
        }
        cmpModelFreeResource();
        cmpModelEnd();
          goto LABEL_95;
        break;
      case 7:
        ragCalcSeqStatus(v15);
          goto LABEL_95;
        break;
      case 8:
        if (SeqInfo->Change)
        {
          v27 = gFclSignal;
          v27->m_Items[2] = 0;
        }
        goto LABEL_94;
      default:
LABEL_94:
        {
LABEL_95:
        }
        break;
    }
    GBWK->SeqInfo->Change = 0;
    v29 = GBWK->SeqInfo;
    if ((v29->Flag & 0x10) != 0)
    {
      cmpUpdateTerminate(v29);
      id->func_ans = -1;
    }
  }
  return 0;
}

// 0x13ce290
void ragCalcSeqStatus(void) {
  dds3Basic_t_o *basic;

  basic = 0;
  if (GBWK->SeqInfo->Change)
  {
    basic = dds3GetActiveScene();
    if (basic)
    {
      dds3VisibleSceneBasic(&basic, 0);
    }
  }
}

// 0x13cdf30
void ragCreateDevilData(fclRagDevil_t *pDevil, datUnitWork_t *pData) {
  datUnitWork_t_o *v3;
  u16 DevilID;
  struct fclRagDevilParam_t_o *Param;
  struct System_SByte_array *v8;
  struct System_SByte_array *v9;
  s8 v10;
  struct System_SByte_array *v11;
  struct System_SByte_array *v12;
  s8 v13;
  struct System_SByte_array *v14;
  struct System_SByte_array *v15;
  s8 v17;
  struct System_SByte_array *v19;
  struct System_SByte_array *v20;
  s8 v21;
  struct System_SByte_array *v22;
  struct System_SByte_array *v23;
  s8 v25;
  struct System_SByte_array *v27;
  struct System_SByte_array *v28;
  s8 v30;
  u64 v32;
  struct System_UInt16_array *Skill;
  struct System_Int32_array *v34;
  s32 v36;
  struct System_Int32_array *v38;
  s32 level;
  datUnitWork_t_o *pStock;

  v3 = pData;
  pStock = pData;
  DevilID = pDevil->DevilID;
  cmbCopyDefaultDevilToStock(DevilID, v3);
  if (pDevil->ParamFlag)
  {
    Param = pDevil->Param;
    v3->level = Param->Level;
    v8 = Param->Param;
    v9 = v3->param;
    v10 = v8->m_Items[0];
    v9->m_Items[0] = v10;
    v11 = Param->Param;
    v12 = v3->param;
    v13 = v11->m_Items[1];
    v12->m_Items[1] = v13;
    v14 = Param->Param;
    v15 = v3->param;
    v17 = v14->m_Items[2];
    v15->m_Items[2] = v17;
    v19 = Param->Param;
    v20 = v3->param;
    v21 = v19->m_Items[3];
    v20->m_Items[3] = v21;
    v22 = Param->Param;
    v23 = v3->param;
    v25 = v22->m_Items[4];
    v23->m_Items[4] = v25;
    v27 = Param->Param;
    v28 = v3->param;
    v30 = v27->m_Items[5];
    v32 = 0;
    v28->m_Items[5] = v30;
    v3->skillcnt = 0;
    do
    {
      Skill = Param->Skill;
      v34 = v3->skill;
      v36 = Skill->m_Items[v32];
      v34->m_Items[v32] = v36;
      v3 = pStock;
      v38 = pStock->skill;
      if (v38->m_Items[v32])
        ++pStock->skillcnt;
      ++v32;
    }
    while (v32 != 8);
    level = v3->level;
    v3->exp = cmbCalcLevelUpExp(&pStock, level);
  }
}

// 0x13cdb00
fclRagExchangeRate_t **ragGetExchangeRate(s8 Type, u8 Index) {
  struct fclRagItem_t_array *fclRagItemTbl;
  fclRagExchangeRate_t_array **p_Rate;
  struct fclRagDevil_t_array *fclRagMitamaTbl;
  s64 v11;

  switch (Type)
  {
    case 2:
      v11 = Index;
      if (LODWORD(fclRagMitamaTbl->max_length) <= Index)
      {
LABEL_21:
      }
LABEL_22:
      p_Rate = &fclRagMitamaTbl->m_Items[v11]->Rate;
      return *p_Rate;
    case 1:
      fclRagMitamaTbl = fclRagSeireiTbl;
      v11 = Index;
      if (LODWORD(fclRagMitamaTbl->max_length) <= Index)
        goto LABEL_21;
      goto LABEL_22;
    case 0:
      p_Rate = &fclRagItemTbl->m_Items[Index]->Rate;
      return *p_Rate;
  }
  return 0;
}
