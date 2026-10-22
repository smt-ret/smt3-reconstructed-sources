#include "types.h"

typedef struct AssetBundles AssetBundles;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

bool IsLoad(AssetBundles *this, char *key);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void *dds3GetProcessData(dds3ProcessID_t **id);
s8 fclChkDbgProcess(void);
void fclClearSignal(s8 Idx);
dds3ProcessID_t *fclScriptStart(u8 **pScriptData, s32 StartNo, dds3ProcessID_t **pPID);
s8 trmChkEventWait(void);
void trmStartBGM(s32 TerminalType, s32 TerminalNo, bool nocheck);
s8 trmStartEvent(void);

// 0xf78030
dds3ProcessFunc_t *trmCalc(dds3ProcessID_t *PID) {
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  AssetBundleCtrl_o *asset_bc;
  u64 v14;
  struct fclDataTerminal_t_o *GBWK;
  struct cmpSeqInfo_t_o *SeqInfo;
  s32 Current;
  s32 v18;
  struct cmpSeqInfo_t_o *v21;
  struct fclDataTerminal_t_o *v25;
  System_Byte_array *pScriptData;
  dds3ProcessID_t_o *pPID;
  dds3ProcessID_t_o *id;
  u64 v31[3];

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
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclDataTerminal_t)
  {
    sub_8FC2C0(klass->_1.element_class, fclDataTerminal_t, v31);
    if ((v31[0] & 1) != 0)
      v7 = v31[2];
    else
      v7 = v31 + 1;
    v8 = sub_8C4940(v7);
  }
LABEL_15:
  GBWK = ProcessData;
  if (fclChkDbgProcess() == 1)
    return 0;
  if (trmChkEventWait() == 1)
    return 0;
  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, "e804"))
    return 0;
  GBWK = *(*(v14 + 184) + 8LL);
  SeqInfo = GBWK->SeqInfo;
  if (SeqInfo->Change != 1)
  {
LABEL_53:
    {
LABEL_56:
      GBWK->SeqInfo->Change = 0;
      v21 = GBWK->SeqInfo;
      if ((v21->Flag & 0x10) != 0)
      {
        cmpUpdateTerminate(v21);
        id->func_ans = -1;
      }
      return 0;
    }
LABEL_54:
    goto LABEL_56;
  }
  if ((*(v14 + 295) & 2) != 0 && !*(v14 + 216))
  {
    SeqInfo = GBWK->SeqInfo;
  }
  Current = SeqInfo->Current;
  if (Current == 6)
  {
    *(*(*(v14 + 184) + 8LL) + 66LL) = -1;
    *(*(*(v14 + 184) + 8LL) + 67LL) = 0;
      goto LABEL_56;
    goto LABEL_54;
  }
  if (Current == 5)
  {
    fclClearSignal(2);
    goto LABEL_53;
  }
  if (Current)
    goto LABEL_53;
  if ((*(v14 + 295) & 2) == 0)
  {
    v18 = GBWK->TerminalType != 0;
    if (trmStartEvent(v14))
      return 0;
LABEL_71:
    pPID = 0;
    v25 = GBWK;
    pScriptData = v25->pScriptData;
    v25->ScriptPID = fclScriptStart(pScriptData, v18, &pPID);
    trmStartBGM(GBWK->TerminalType, GBWK->TerminalNo, 1);
    if (!gCallMode)
    {
      dds3FadeIn(0, 0, 0, 0x14u);
        goto LABEL_56;
      goto LABEL_54;
    }
    goto LABEL_53;
  }
  if (*(v14 + 216))
  {
    v18 = GBWK->TerminalType != 0;
  }
  else
  {
    v18 = GBWK->TerminalType != 0;
  }
  if (!trmStartEvent(v14))
    goto LABEL_71;
  return 0;
}

// 0xf77fb0
void trmCalcAct(void) {
  GBWK->ActFlag = -1;
  GBWK->ActStartFlag = 0;
}
