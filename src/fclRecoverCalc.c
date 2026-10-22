#include "types.h"

typedef struct cmpLocalStock_t cmpLocalStock_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

u32 datGetMaxHp(datUnitWork_t *work);
u32 datGetMaxMp(datUnitWork_t *work);
void *dds3GetProcessData(dds3ProcessID_t **id);
u32 dds3GetProcessStat(dds3ProcessID_t **id);
s8 fclChkSignal(s8 Idx);
s32 fclClearPanelTimer(void *a);
void fclClearSignal(s8 Idx);
dds3ProcessID_t *fclScriptStart(u8 **pScriptData, s32 StartNo, dds3ProcessID_t **pPID);
s32 rcvCalcPriceRecover(datUnitWork_t *pStock);
s32 rcvGetDevilAttr(datUnitWork_t *pStock);

// 0x198ef90
void rcvAppAllRecover(datUnitWork_t *pStock) {
  u16 MaxMp;
  u16 v5;

  pStock->badstatus &= ~0x800u;
  pStock->hp = (datGetMaxHp(pStock) + 9) / 0xA;
  pStock->hp = datGetMaxHp(pStock);
  MaxMp = datGetMaxMp(pStock);
  v5 = pStock->badstatus & 0xFE9F;
  pStock->mp = MaxMp;
  pStock->badstatus = v5;
}

// 0x198ef80
void rcvAppDispel(datUnitWork_t *pStock) {
  pStock->badstatus &= ~0x8000u;
}

// 0x198ee40
s8 rcvAppRecover(datUnitWork_t *pStock) {
  pStock->hp = datGetMaxHp(pStock);
  pStock->mp = datGetMaxMp(pStock);
  return 1;
}

// 0x198eef0
void rcvAppRevive(datUnitWork_t *pStock) {
  pStock->badstatus &= ~0x800u;
  pStock->hp = (datGetMaxHp(pStock) + 9) / 0xA;
}

// 0x198eed0
void rcvAppStatusRecover(datUnitWork_t *pStock) {
  pStock->badstatus &= 0xFE9Fu;
}

// 0x198fb80
dds3ProcessFunc_t *rcvCalc(dds3ProcessID_t *PID) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  struct fclDataRecover_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  cmpCursorInfo_t_o *CursorInfo;
  struct fclDataRecover_t_o *v15;
  dds3ProcessID_t_o **p_ScriptPID;
  struct fclDataRecover_t_o *v18;
  System_Byte_array *pScriptData;
  struct System_Int32_array *Price;
  struct cmpSeqInfo_t_o *v23;
  dds3ProcessID_t_o *v25;
  dds3ProcessID_t_o *v26[3];
  dds3ProcessID_t_o *id;

  id = PID;
  v25 = 0;
  ProcessData = dds3GetProcessData(&id);
  else
  {
    if (!ProcessData)
      goto LABEL_15;
  }
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclDataRecover_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclDataRecover_t, v26);
    if ((v26[0] & 1) != 0)
      v7 = v26[2];
    else
      v7 = v26 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_15:
  GBWK = ProcessData;
  if (fclChkSignal(1))
  {
    SeqInfo = GBWK->SeqInfo;
    if (SeqInfo->Current == 5)
    {
      if (SeqInfo->Change == 1)
      {
        Price = GBWK->Price;
        Price->m_Items[0] = 400;
        fclClearSignal(2);
      }
    }
    else if (!SeqInfo->Current)
    {
      fclClearPanelTimer(GBWK->BackPanel);
      CursorInfo = GBWK->CmdSelInfo->CursorInfo;
      cmpInitCursorEff(CursorInfo);
      v15 = GBWK;
      if (v15->SeqInfo->Change == 1)
      {
        p_ScriptPID = &v15->ScriptPID;
        if (dds3GetProcessStat(p_ScriptPID) != 2)
        {
          v25 = 0;
          v18 = GBWK;
          pScriptData = v18->pScriptData;
          v18->ScriptPID = fclScriptStart(pScriptData, 0, &v25);
            goto LABEL_62;
          goto LABEL_60;
        }
      }
    }
    {
LABEL_62:
      GBWK->SeqInfo->Change = 0;
      v23 = GBWK->SeqInfo;
      if ((v23->Flag & 0x10) != 0)
      {
        cmpUpdateTerminate(v23);
        id->func_ans = -1;
      }
      return 0;
    }
LABEL_60:
    goto LABEL_62;
  }
  return 0;
}

// 0x198ed80
s32 rcvCalcPrice(datUnitWork_t *pStock, s32 Flag) {
  s32 result;
  s32 v5;
  s32 badstatus;
  bool v7;
  s32 v8;
  s32 v9;

  result = -1;
  switch (Flag)
  {
    case 1:
      result = rcvCalcPriceRecover(pStock, *&Flag);
      break;
    case 2:
      if ((pStock->badstatus & 0x160) != 0)
        result = 100;
      else
        result = 0;
      break;
    case 4:
      result = (HIBYTE(pStock->badstatus) << 28 >> 31) & 0x190;
      break;
    case 7:
      v5 = rcvCalcPriceRecover(pStock, *&Flag);
      badstatus = pStock->badstatus;
      v7 = (badstatus & 0x160) == 0;
      v8 = badstatus << 20;
      if (v7)
        v9 = 0;
      else
        v9 = 100;
      result = v9 + v5 + ((v8 >> 31) & 0x190);
      break;
    default:
      return result;
  }
  return result;
}

// 0x198ed30
s32 rcvCalcPriceAllRecover(datUnitWork_t *pStock) {
  s32 v3;
  s32 badstatus;
  bool v5;
  s32 v6;
  s32 v7;

  v3 = rcvCalcPriceRecover(pStock);
  badstatus = pStock->badstatus;
  v5 = (badstatus & 0x160) == 0;
  v6 = badstatus << 20;
  if (v5)
    v7 = 0;
  else
    v7 = 100;
  return v7 + v3 + ((v6 >> 31) & 0x190);
}

// 0x198ed20
s32 rcvCalcPriceDispel(void) {
  return 400;
}

// 0x198ebd0
s32 rcvCalcPriceRecover(datUnitWork_t *pStock) {
  s32 v3;
  u32 MaxHp;
  s32 hp;
  u32 v6;
  f32 v7;

  if ((pStock->badstatus & 0x800) != 0)
  {
    v3 = (datGetMaxHp(pStock) + 9) / -10;
  }
  else
  {
    v3 = 0;
  }
  MaxHp = datGetMaxHp(pStock);
  hp = pStock->hp;
  v6 = MaxHp;
  v7 = (datGetMaxMp(pStock) - pStock->mp);
  return v6 + v3 - hp + (v7 * 2.5);
}

// 0x198ed00
s32 rcvCalcPriceRevive(datUnitWork_t *pStock) {
  return (HIBYTE(pStock->badstatus) << 28 >> 31) & 0x190;
}

// 0x198ece0
s32 rcvCalcPriceStatusRecover(datUnitWork_t *pStock) {
  if ((pStock->badstatus & 0x160) != 0)
    return 100;
  else
    return 0;
}

// 0x198f180
void rcvCreateLocalStock(cmpLocalStock_t *pLocalStock, s32 Flag) {
  struct System_SByte_array *StockIdx;
  struct System_SByte_array *v7;
  struct System_SByte_array *v9;
  struct System_SByte_array *v11;
  struct System_SByte_array *v13;
  struct System_SByte_array *v15;
  struct System_SByte_array *v17;
  struct System_SByte_array *v19;
  struct System_SByte_array *v21;
  struct System_SByte_array *v23;
  struct System_SByte_array *v25;
  struct System_SByte_array *v27;
  struct System_SByte_array *v29;
  struct System_SByte_array *v31;
  struct System_SByte_array *v33;
  struct System_SByte_array *v35;
  u64 v37;
  dds3GlobalWork_c *v38;
  struct dds3GlobalWork_t_o *DDS3_GBWK;
  struct System_Int32_array *stocklist;
  char *v42;
  struct datUnitWork_t_array *unitwork;
  s64 v44;
  struct datUnitWork_t_array *v47;
  struct datUnitWork_t_array *v50;
  s64 PartyCnt;
  struct System_Int32_array *Price;
  struct datUnitWork_t_array *v57;
  s32 v59;
  Il2CppClass **v60;
  Il2CppClass *v61;
  struct System_SByte_array *v63;
  s32 v65;
  s32 namespaze_high;
  bool v67;
  s32 v68;
  s32 v69;
  u64 v70;
  struct dds3GlobalWork_t_o *v71;
  struct System_Int32_array *v72;
  char *v74;
  struct datUnitWork_t_array *v75;
  s64 v76;
  struct datUnitWork_t_array *v79;
  struct datUnitWork_t_array *v82;
  s64 v84;
  s64 StockCnt;
  struct System_Int32_array *v89;
  s64 v90;
  struct datUnitWork_t_array *v91;
  s32 v93;
  Il2CppClass **v94;
  Il2CppClass *v95;
  struct System_SByte_array *v97;
  s32 v99;
  s32 v100;
  s32 v101;
  s32 v102;
  cmpCursorInfo_t_o *CursorInfo;
  s8 v106;
  s8 v107;
  u8 LISTMAX;

  StockIdx = pLocalStock->StockIdx;
  StockIdx->m_Items[0] = -1;
  v7 = pLocalStock->StockIdx;
  v7->m_Items[1] = -1;
  v9 = pLocalStock->StockIdx;
  v9->m_Items[2] = -1;
  v11 = pLocalStock->StockIdx;
  v11->m_Items[3] = -1;
  v13 = pLocalStock->StockIdx;
  v13->m_Items[4] = -1;
  v15 = pLocalStock->StockIdx;
  v15->m_Items[5] = -1;
  v17 = pLocalStock->StockIdx;
  v17->m_Items[6] = -1;
  v19 = pLocalStock->StockIdx;
  v19->m_Items[7] = -1;
  v21 = pLocalStock->StockIdx;
  v21->m_Items[8] = -1;
  v23 = pLocalStock->StockIdx;
  v23->m_Items[9] = -1;
  v25 = pLocalStock->StockIdx;
  v25->m_Items[10] = -1;
  v27 = pLocalStock->StockIdx;
  v27->m_Items[11] = -1;
  v29 = pLocalStock->StockIdx;
  v29->m_Items[12] = -1;
  v31 = pLocalStock->StockIdx;
  v31->m_Items[13] = -1;
  v33 = pLocalStock->StockIdx;
  v33->m_Items[14] = -1;
  v35 = pLocalStock->StockIdx;
  v37 = 0;
  v35->m_Items[15] = -1;
  *&pLocalStock->PartyCnt = 0;
  {
LABEL_38:
  }
  while (1)
  {
    if (v37 >= DDS3_GBWK->stockcnt)
      break;
    else
    {
      stocklist = DDS3_GBWK->stocklist;
      if (v37 >= LODWORD(stocklist->max_length))
        goto LABEL_44;
    }
    v42 = stocklist + 4 * v37;
    unitwork = DDS3_GBWK->unitwork;
    v44 = *(v42 + 8);
    if ((unitwork->m_Items[v44]->flag & 2) != 0)
    {
      if ((Flag & 4) != 0 || (Flag & 7) == 0)
        goto LABEL_55;
      v47 = DDS3_GBWK->unitwork;
      if ((v47->m_Items[v44]->badstatus & 0x800) == 0)
      {
LABEL_55:
        v50 = DDS3_GBWK->unitwork;
        if ((rcvGetDevilAttr(v50->m_Items[v44], *&Flag) & Flag) != 0)
        {
          PartyCnt = pLocalStock->PartyCnt;
          Price = GBWK->Price;
          v57 = DDS3_GBWK->unitwork;
          v59 = -1;
          v60 = &v57->obj.klass + v44;
          v61 = v60[4];
          switch (Flag)
          {
            case 1:
              v59 = rcvCalcPriceRecover(v60[4], *&Flag);
              goto LABEL_71;
            case 2:
              if ((HIWORD(v61->_1.namespaze) & 0x160) != 0)
                v59 = 100;
              else
                v59 = 0;
              if (PartyCnt < LODWORD(Price->max_length))
                goto LABEL_73;
              goto LABEL_72;
            case 4:
              v59 = (HIBYTE(v61->_1.namespaze) << 28 >> 31) & 0x190;
              if (PartyCnt < LODWORD(Price->max_length))
                goto LABEL_73;
              goto LABEL_72;
            case 7:
              v65 = rcvCalcPriceRecover(v60[4], *&Flag);
              namespaze_high = HIWORD(v61->_1.namespaze);
              v67 = (namespaze_high & 0x160) == 0;
              v68 = namespaze_high << 20;
              if (v67)
                v69 = 0;
              else
                v69 = 100;
              v59 = v69 + v65 + ((v68 >> 31) & 0x190);
              if (PartyCnt < LODWORD(Price->max_length))
                goto LABEL_73;
              goto LABEL_72;
            default:
LABEL_71:
              if (PartyCnt >= LODWORD(Price->max_length))
              {
LABEL_72:
              }
LABEL_73:
              Price->m_Items[PartyCnt] = v59;
              v63 = pLocalStock->StockIdx;
              v63->m_Items[PartyCnt] = v44;
              ++pLocalStock->PartyCnt;
              break;
          }
        }
      }
    }
    ++v37;
      goto LABEL_38;
  }
  v70 = 0;
  if ((v38->_2.bitflags2 & 2) == 0)
    goto LABEL_95;
LABEL_93:
LABEL_95:
  while (1)
  {
    v71 = DDS3_GBWK;
    if (v70 >= v71->stockcnt)
      break;
    else
    {
      v72 = v71->stocklist;
      if (v70 >= LODWORD(v72->max_length))
        goto LABEL_99;
    }
    v74 = v72 + 4 * v70;
    v75 = v71->unitwork;
    v76 = *(v74 + 8);
    if ((v75->m_Items[v76]->flag & 2) == 0)
    {
      if ((Flag & 4) != 0 || (Flag & 7) == 0)
        goto LABEL_110;
      v79 = DDS3_GBWK->unitwork;
      if ((v79->m_Items[v76]->badstatus & 0x800) == 0)
      {
LABEL_110:
        v82 = DDS3_GBWK->unitwork;
        if ((rcvGetDevilAttr(v82->m_Items[v76], *&Flag) & Flag) != 0)
        {
          v84 = pLocalStock->PartyCnt;
          StockCnt = pLocalStock->StockCnt;
          v89 = GBWK->Price;
          v90 = StockCnt + v84;
          v91 = DDS3_GBWK->unitwork;
          v93 = -1;
          v94 = &v91->obj.klass + v76;
          v95 = v94[4];
          switch (Flag)
          {
            case 1:
              v93 = rcvCalcPriceRecover(v94[4], *&Flag);
              goto LABEL_126;
            case 2:
              if ((HIWORD(v95->_1.namespaze) & 0x160) != 0)
                v93 = 100;
              else
                v93 = 0;
              if (v90 < LODWORD(v89->max_length))
                goto LABEL_128;
              goto LABEL_127;
            case 4:
              v93 = (HIBYTE(v95->_1.namespaze) << 28 >> 31) & 0x190;
              if (v90 < LODWORD(v89->max_length))
                goto LABEL_128;
              goto LABEL_127;
            case 7:
              v99 = rcvCalcPriceRecover(v94[4], *&Flag);
              v100 = HIWORD(v95->_1.namespaze);
              v67 = (v100 & 0x160) == 0;
              v101 = v100 << 20;
              if (v67)
                v102 = 0;
              else
                v102 = 100;
              v93 = v102 + v99 + ((v101 >> 31) & 0x190);
              if (v90 < LODWORD(v89->max_length))
                goto LABEL_128;
              goto LABEL_127;
            default:
LABEL_126:
              if (v90 >= LODWORD(v89->max_length))
              {
LABEL_127:
              }
LABEL_128:
              v89->m_Items[v90] = v93;
              v97 = pLocalStock->StockIdx;
              v97->m_Items[v90] = v76;
              ++pLocalStock->StockCnt;
              break;
          }
        }
      }
    }
    ++v70;
      goto LABEL_93;
  }
  GBWK->AttrFlag = Flag;
  CursorInfo = GBWK->StockWindow->CursorInfo;
  v106 = pLocalStock->PartyCnt;
  v107 = pLocalStock->StockCnt;
  cmpInitCursorInfo(CursorInfo, v107 + v106, LISTMAX, 0);
  cmpResetCursorInfo(GBWK->StockWindow->CursorInfo);
}

// 0x198f0a0
s32 rcvGetDevilAttr(datUnitWork_t *pStock) {
  u32 hp;
  u32 MaxHp;
  u32 mp;
  u32 MaxMp;
  u32 badstatus;
  s32 v9;
  bool v10;
  u32 v11;

  hp = pStock->hp;
  MaxHp = datGetMaxHp(pStock);
  mp = pStock->mp;
  MaxMp = datGetMaxMp(pStock);
  badstatus = pStock->badstatus;
  v9 = MaxHp > hp || MaxMp > mp;
  v10 = (badstatus & 0x160) == 0;
  v11 = badstatus >> 9;
  if (!v10)
    v9 |= 2u;
  return v9 | v11 & 4;
}
