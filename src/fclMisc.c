#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclItemList_t fclItemList_t;
typedef struct fclPanelPos_t fclPanelPos_t;

static s8 gFclSignal[8];
static s32 gFclVal[16];
static s32 gMsgID;
static s8 gMsgFlag;
static s8 gMsgInvFlag;
static s32 gSelMsgNo;
static s8 gSelMsgPos;
static char *fclGeneralStrTbl[10];
static f32 Fovy;

void ButtonGuideDispOff(void);
void Eve_BlurOFF(void);
void Eve_DistortionBlurOFF(void);
void Eve_FilterOFF(void);
void Eve_PartialMultiBlurOFF(void);
void Eve_PartialMultiFilterOFF(void);
u8 Get(s32 id);
void *GetCampCameraObj(dds3DefaultMain *this);
void Log(char *fmt, void **parray);
void StatusTitleOff(void);
void WindowDispOn(s32 MsgID);
s32 datAddHearts(s32 id);
void datAddItem(s32 id, s32 num);
void dds3DistBlurOff(s32 frame);
dds3Basic_t *dds3GetControlScene(void);
s32 dds3GetMapNo(dds3Basic_t **scene);
u32 dds3GetProcessStat(dds3ProcessID_t **id);
u32 dds3GetRandA(char *name);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void dds3MultiBlurOff(s32 frame);
void dds3SetBlur(u32 frame, s32 alpha, s32 scale);
bool evtBitCheck(s32 no);
void evtFreeStage(void);
s32 evtLoadArea(s32 fld, s32 area);
s8 fclChkSelMessage(void);
bool fclChkStartMenu(void);
s8 fclEndMessageEx(s8 Mode);
void fclFilterOFF(void);
void fclScriptForcedEnd(dds3ProcessID_t *PID);
void fclSetMessageInvalid(s8 Mode);
void itfMesMngChangeWindowType(s32 id, s32 type, s32 alpha);
void itfMesMngClearBitStat(s32 id, u32 flag);
s32 itfMesMngGetPhase(s32 msgid);
s32 itfMesMngGetSelPhase(s32 msgid);
s32 itfMesMngGetSelectNo(s32 msgid);
s32 itfMesMngInitialize(void *presource, char **master_text, char *key);
void itfMesMngMarkBitStat(s32 id, u32 flag);
void itfMesMngMsgWndCls(s32 msgid);
void itfMesMngRelease(s32 id);
s32 itfMesMngRequestMessage(s32 id, s32 message, s32 page, s32 callmode);
void itfMesMngRequestMessageRelease(s32 id, s32 cls_speaker);
void itfMesMngRequestSelect(s32 id, s32 select);
void itfMesMngSetMesPosition(s32 id, s32 x, s32 y);
void itfMesMngSetOffsetY1(s32 msgid, s32 y1);
void itfMesMngSetPhase(s32 msgid, s32 phase);
void itfMesMngSetSelPhase(s32 msgid, s32 phase);
void itfMesMngSetSelect(s32 id, s32 selno);
s32 itfMesMngSetSelectDefKey(s32 id, s32 key, s32 index);
void itfMesMngSetVarImmediate(s32 id, s32 index, char *pstr);
s32 scrGetIntPara(s32 n);
void scrSetIntReturnValue(s32 i);
dds3ProcessID_t *scrStartScript2(s32 a, void *b, s32 c);

// 0x13c8aa0
bool CheckLevelLimit(s32 lv1, s32 lv2) {
  _BOOL4 v6;

  v6 = (lv1 > lv2) & !evtBitCheck(2208);
  if (!v6)
    return v6;
  if (!fclChkStartMenu())
    return v6;
  return CMB_GBWK->LevelLimit == 0;
}

// 0x13c8ba0
void DevilStatusMode(bool flag, bool stat) {
  UnityEngine_GameObject_o *v7;
  Il2CppObject *Component_object;
  f32 fieldOfView;
  f32 v12;
  UnityEngine_GameObject_o *v15;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Object_o *statusUIScr;
  struct cmbGlobalWork_t_o *CMB_GBWK;
  struct cmbGlobalWork_t_o *v26;
  UnityEngine_GameObject_o *v27;
  UnityEngine_Object_o *v29;
  bool activeInHierarchy;
  UnityEngine_GameObject_o *v35;
  Il2CppObject *v37;
  struct sdf3DScreenParam_t_o *dds3ScreenParam;

  SetActive(campCameraObj, 1, 0);
  if (flag)
  {
    v7 = Find(StringLiteral_5605, 0);
    Component_object = GetComponent_object_(v7);
    fieldOfView = get_fieldOfView(Component_object);
    v12 = fieldOfView;
    Fovy = (v12 * 6.2832) / 360.0;
    ButtonGuideDispOff();
    cmpModelInitFacility();
    cmpSetModelLoadFlag(1);
    cmpSetupObjUI(0x8000, 0);
    v15 = Find(StringLiteral_16274, 0);
    gameObject = get_gameObject(v15);
    if (op_Inequality(gameObject, 0, 0)
      && !get_activeInHierarchy(gameObject))
    {
      SetActive(gameObject, 1, 0);
    }
    statusUIScr = _statusUIScr;
    if (!op_Equality(statusUIScr, 0, 0))
    {
      StatusTitleOff();
      if (CMB_GBWK)
      {
        CMB_GBWK->bDrawStat = 0;
      }
    }
  }
  else
  {
    v26 = CMB_GBWK;
    if (v26)
    {
      v26->bDrawStat = 0;
    }
    v27 = Find(StringLiteral_16274, 0);
    v29 = get_gameObject(v27);
    activeInHierarchy = op_Inequality(v29, 0, 0);
    if (activeInHierarchy && !stat)
      activeInHierarchy = get_activeInHierarchy(v29);
    SetActive(campCameraObj, 0, 0);
    cmpRemoveObjUI(1);
    if (activeInHierarchy)
    {
      SetActive(v29, 0, 0);
      v35 = Find(StringLiteral_5605, 0);
      v37 = GetComponent_object_(v35);
      dds3ScreenParam->fovy = Fovy;
      set_fieldOfView(v37, (dds3ScreenParam->fovy * 360.0) / 6.2832, 0);
    }
    Fovy = -1.0;
  }
}

// 0x13c6600
s32 FCL_MAKE_COL(s32 r, s32 g, s32 b, u32 a) {
  return (g << 16) | (r << 24) | (b << 8) | a;
}

// 0x13c6620
u32 FCL_RAND(void) {
  return dds3GetRandA(StringLiteral_416);
}

// 0x13c66d0
void InitializeModelCameraForUnity(void) {
  UnityEngine_GameObject_o *CampCameraObj;

  CampCameraObj = GetCampCameraObj(kernelObject);
  campCameraObj = CampCameraObj;
}

// 0x13c6690
sdfColor32_t ToColor32(u32 c) {
    return (sdfColor32_t){0};
}

// 0x13c6830
s32 fclAddItem(u16 ItemID, s32 Nums) {
  System_Array_o *v5;
  s64 v7;
  s32 v10;

  v5 = NewSpecific(sbyte, 0x19u);
  InitializeArray_1543888(v5, Field__PrivateImplementationDetails__1611B884F9514B730E1DFD40ABEFFAC12FD56E0F);
  if ((ItemID - 64) >= 0x19u)
  {
    {
      datAddItem(ItemID, Nums);
      return 1;
    }
  }
  v7 = ItemID - 64LL;
  v10 = *(&v5[2].klass + v7);
  datAddHearts(v10);
  return 1;
}

// 0x13c6770
s8 fclChkItemHearts(u16 ItemID) {
  System_Array_o *v3;
  s64 v4;

  v3 = NewSpecific(sbyte, 0x19u);
  InitializeArray_1543888(v3, Field__PrivateImplementationDetails__1611B884F9514B730E1DFD40ABEFFAC12FD56E0F);
  if ((ItemID - 64) > 0x18u)
    return 0;
  v4 = ItemID - 64LL;
  return *(&v3[2].klass + v4);
}

// 0x13c7ee0
s8 fclChkMessage(void) {
  struct fclMisc_StaticFields *static_fields;

  static_fields = fclMisc->static_fields;
  if (static_fields->gMsgID < 0)
    return 0;
  else if (static_fields->gMsgInvFlag)
  {
    else if (static_fields->gMsgFlag == 2)
    {
      return 0;
    }
  }
  return gMsgFlag;
}

// 0x13c85c0
s8 fclChkMessageDraw(dds3ProcessID_t *PID) {
  dds3ProcessID_t_o *id;

  id = PID;
  if (dds3GetProcessStat(&id) == 1)
    return 1;
  if (dds3GetProcessStat(&id) == 2)
    return 1;
  return dds3GetProcessStat(&id) == 3;
}

// 0x13c8460
s8 fclChkMessageInvalid(void) {
  return gMsgInvFlag;
}

// 0x13c8000
s8 fclChkSelMessage(void) {
  s32 gMsgID;

  if (gMsgID < 0)
    return 0;
  return itfMesMngGetSelPhase(gMsgID) >= 0;
}

// 0x13c86a0
s8 fclChkSignal(s8 Idx) {
  struct System_SByte_array *gFclSignal;

  return gFclSignal->m_Items[Idx] != 0;
}

// 0x13c8820
s8 fclChkVal(s8 Idx) {
  struct System_Int32_array *gFclVal;

  if (Idx >= 15)
    Idx = 15;
  return gFclVal->m_Items[Idx];
}

// 0x13c6e60
void fclClearSignal(s8 Idx) {
  struct System_SByte_array *gFclSignal;

  gFclSignal->m_Items[Idx] = 0;
}

// 0x13c6f00
void fclCreateItemList(fclItemList_t *pItemList) {
  s64 i;
  u64 v5;
  struct System_Byte_array *item;
  s64 ItemCnt;
  struct System_UInt16_array *ItemIdx;

  pItemList->ItemCnt = 0;
  for (i = 33; i != 192; ++i)
  {
    v5 = i - 32;
    item = DDS3_GBWK->item;
    if (*(&item->obj.klass + i))
    {
      ItemCnt = pItemList->ItemCnt;
      ItemIdx = pItemList->ItemIdx;
      pItemList->ItemCnt = ItemCnt + 1;
      ItemIdx->m_Items[ItemCnt] = v5;
    }
  }
}

// 0x13c6ff0
void fclCreateItemListEx(fclItemList_t *pItemList, s8 Mode) {
  s64 i;
  u64 v7;
  struct System_Byte_array *item;
  s64 ItemCnt;
  struct System_UInt16_array *ItemIdx;

  pItemList->ItemCnt = 0;
  for (i = 33; i != 192; ++i)
  {
    v7 = i - 32;
    item = DDS3_GBWK->item;
    if (*(&item->obj.klass + i))
    {
      if (cmpChkItemStat(v7, Mode))
      {
        ItemCnt = pItemList->ItemCnt;
        ItemIdx = pItemList->ItemIdx;
        pItemList->ItemCnt = ItemCnt + 1;
        ItemIdx->m_Items[ItemCnt] = v7;
      }
    }
  }
}

// 0x13c7de0
s8 fclDestroyMessage(void) {
  s32 gMsgID;

  if (gMsgID < 0)
    return 0;
  itfMesMngRelease(gMsgID);
  gMsgID = -1;
  gMsgFlag = 0;
  gMsgInvFlag = 0;
  return 1;
}

// 0x13c7400
char *fclDrawDevilName(datUnitWork_t *pStock) {
  struct System_Char_array *namecode;
  s32 id;

  if ((byte_3F596C3 & 1) != 0)
  {
    namecode = pStock->namecode;
    if (LODWORD(namecode->max_length))
  }
  namecode = pStock->namecode;
  if (!LODWORD(namecode->max_length))
  if (namecode->m_Items[0])
    return CreateString_5280336(0, namecode);
  id = pStock->id;
  return Get(id, 0);
}

// 0x13c7d70
s8 fclEndMessage(void) {
  return fclEndMessageEx(1);
}

// 0x13c7a60
s8 fclEndMessageEx(s8 Mode) {
  s32 gMsgID;
  s32 v7;
  s32 v9;
  s8 v10;

  if (gMsgID < 0)
    return 0;
  itfMesMngSetPhase(gMsgID, 0);
  if (Mode)
  {
    v7 = gMsgID;
    itfMesMngMsgWndCls(v7);
  }
  v9 = gMsgID;
  itfMesMngRequestMessageRelease(v9, 0);
  v10 = 1;
  fclSetMessageInvalid(1);
  gMsgFlag = 0;
  return v10;
}

// 0x13c6aa0
void fclFilterOFF(void) {
  dds3SetBlur(0, 0, 0);
  dds3MultiBlurOff(0);
  dds3DistBlurOff(0);
  Eve_BlurOFF();
  Eve_PartialMultiBlurOFF();
  Eve_PartialMultiFilterOFF();
  Eve_DistortionBlurOFF();
  Eve_FilterOFF();
}

// 0x13c6b70
void fclFreeStage(void) {
  evtFreeStage();
  fclFilterOFF();
}

// 0x13c7500
u32 fclGetBlendColor(u32 Col1, u32 Col2, u32 Rate) {
  u32 v4;

  v4 = 512 - Rate;
  if (Rate <= 0x100)
    v4 = Rate;
  return (v4 * BYTE1(Col1) + (256 - v4) * BYTE1(Col2)) & 0xFFFFFF00
       | ((v4 * Col1 + (256 - v4) * Col2) >> 8)
       | ((v4 * BYTE2(Col1) + (256 - v4) * BYTE2(Col2)) << 8) & 0xFFFF0000
       | ((v4 * HIBYTE(Col1) + (256 - v4) * HIBYTE(Col2)) << 16) & 0xFF000000;
}

// 0x13c7910
s8 fclGetCurrentSelMessagePos(void) {
  return gSelMsgPos;
}

// 0x13c74c0
u32 fclGetFadeColor(u32 Col, u32 Rate) {
  return Col
       | (((HIBYTE(Col) * Rate) >> 8) << 24)
       | (BYTE1(Col) * Rate) & 0xFFFFFF00
       | ((BYTE2(Col) * Rate) << 8) & 0xFFFF0000;
}

// 0x13c7980
s8 fclGetSelMessagePos(void) {
  s32 gMsgID;

  if (gMsgID < 0)
    return -1;
  return itfMesMngGetSelectNo(gMsgID);
}

// 0x13c89a0
s32 fclGetVal(void) {
  s32 IntPara;
  s32 v4;
  struct System_Int32_array *gFclVal;
  s32 v8;

  IntPara = scrGetIntPara(0);
  if (IntPara >= 15)
    v4 = 15;
  else
    v4 = IntPara;
  v8 = gFclVal->m_Items[v4];
  scrSetIntReturnValue(v8);
  return 1;
}

// 0x13c7580
s8 fclInitMessage(void *pData) {
  s32 v5;

  else if ((gMsgID & 0x80000000) == 0)
  {
    return 0;
  }
  v5 = itfMesMngInitialize(pData, 0, 0);
  gMsgID = v5;
  itfMesMngChangeWindowType(gMsgID, 2, 0);
  return 1;
}

// 0x13c6c00
void fclInitPanelPos(s32 X, s32 Y, u32 Z, u16 W, u16 H, s32 Work, fclPanelPos_t *pPanelPos) {
  pPanelPos->X = X;
  pPanelPos->Y = Y;
  pPanelPos->Z = Z;
  pPanelPos->W = W;
  pPanelPos->H = H;
  pPanelPos->Work = Work;
}

// 0x13c69b0
void fclLoadStage(u32 MajorNo, u32 MinorNo) {
  dds3Basic_t_o *scene;

  scene = 0;
  scene = dds3GetControlScene();
  if (dds3GetMapNo(&scene) != (MinorNo + (MajorNo << 16)))
  {
    evtLoadArea(MajorNo, MinorNo);
  }
}

// 0x13c7130
s32 fclReplaceBuf8u(u8 **pBuf, s32 BufSize, u8 TargetVal) {
  u64 v4;
  s32 v5;
  u8 *m_Items;
  s32 v7;
  u64 max_length_low;
  s64 v11;

  if (BufSize < 1)
    return 0;
  v4 = 0;
  v5 = 0;
  m_Items = pBuf->m_Items;
  do
  {
    while (1)
    {
      v7 = m_Items[v4];
      if (v7 != TargetVal)
        break;
      if (BufSize == ++v4)
        return v5;
    }
    max_length_low = LODWORD(pBuf->max_length);
    v11 = v5;
    m_Items[v4] = 0;
    ++v5;
    pBuf->m_Items[v11] = v7;
    ++v4;
  }
  while (BufSize != v4);
  return v5;
}

// 0x13c6c20
void fclScriptForcedEnd(dds3ProcessID_t *PID) {
  dds3ProcessID_t_o *id;

  id = PID;
  if (PID)
  {
    if (dds3GetProcessStat(&id))
    {
      dds3KillProcess(&id, 0);
    }
  }
}

// 0x13c6cd0
dds3ProcessID_t *fclScriptStart(u8 **pScriptData, s32 StartNo, dds3ProcessID_t **pPID) {
    fclScriptForcedEnd(0);
    scrStartScript2(0, 0, 0);
    return 0;
}

// 0x13c7c00
void fclSetMessageInvalid(s8 Mode) {
  s32 gMsgID;
  s32 v6;

  if (Mode)
  {
    itfMesMngClearBitStat(gMsgID, 0x800000u);
    itfMesMngClearBitStat(gMsgID, 0x100000u);
    gMsgInvFlag = 0;
    itfMesMngSetPhase(gMsgID, 1);
    gMsgFlag = 1;
  }
  else
  {
    v6 = gMsgID;
    itfMesMngMarkBitStat(v6, 0x800000u);
    itfMesMngMarkBitStat(gMsgID, 0x100000u);
    gMsgInvFlag = 1;
  }
}

// 0x13c84d0
void fclSetMessagePos(s32 X, s32 Y) {
  s32 gMsgID;

  itfMesMngSetMesPosition(gMsgID, 16 * (X * 3.75), 8 * (Y * 2.25), 0);
  itfMesMngSetOffsetY1(gMsgID, 8 * Y - 2808);
}

// 0x13c83a0
void fclSetMessageVar(s8 Index, s8 pStr) {
  ;
}

// 0x13c83b0
void fclSetMessageVar_20743088(s8 Index, char *pStr) {
  s32 gMsgID;

  itfMesMngSetVarImmediate(gMsgID, Index, pStr);
}

// 0x13c7880
void fclSetSelMessagePos(s8 SelPos) {
  fclMisc_c *v3;
  struct fclMisc_StaticFields *static_fields;

  static_fields = v3->static_fields;
  if ((static_fields->gMsgID & 0x80000000) == 0)
  {
    static_fields->gSelMsgPos = SelPos;
  }
}

// 0x13c8750
s8 fclSetVal(s8 Idx, s32 Val) {
  struct System_Int32_array *gFclVal;

  if (Idx > 15)
    return 0;
  gFclVal->m_Items[Idx] = Val;
  return 1;
}

// 0x13c7260
void fclShuffleBuf8u(u8 **pBuf, s32 BufSize, s32 ShuffleCount) {
  s64 v7;
  s64 v8;
  s64 v9;
  u32 max_length;
  u8 v12;
  char *v13;
  u8 v14;
  u8 *v15;
  u8 v16;

  if (ShuffleCount >= 1)
  {
    do
    {
      v7 = dds3GetRandA(StringLiteral_416) % BufSize;
      v8 = v7;
      v9 = dds3GetRandA(StringLiteral_416) % BufSize;
      max_length = pBuf->max_length;
      v12 = pBuf->m_Items[v7];
      v13 = pBuf + v9;
      v16 = v13[32];
      v15 = (v13 + 32);
      v14 = v16;
      pBuf->m_Items[v8] = v14;
      --ShuffleCount;
      *v15 = v12;
    }
    while (ShuffleCount);
  }
}

// 0x13c88d0
s32 fclSignal(void) {
  s32 IntPara;
  struct System_SByte_array *gFclSignal;

  IntPara = scrGetIntPara(0);
  gFclSignal->m_Items[IntPara] = 1;
  return 1;
}

// 0x13c7690
s8 fclStartMessage(s32 MsgNo) {
  s32 gMsgID;
  s8 v6;

  if (gMsgID < 0)
    return 0;
  itfMesMngMarkBitStat(gMsgID, 0x200000u);
  itfMesMngRequestMessage(gMsgID, MsgNo, 0, 0);
  itfMesMngSetSelPhase(gMsgID, -1);
  v6 = 1;
  gMsgFlag = 1;
  WindowDispOn(gMsgID);
  return v6;
}

// 0x13c77d0
s8 fclStartSelMessage(s32 SelMsgNo) {
  struct fclMisc_StaticFields *static_fields;

  static_fields = fclMisc->static_fields;
  if (static_fields->gMsgID < 0)
    return 0;
  static_fields->gSelMsgNo = SelMsgNo;
  return 1;
}

// 0x13c80e0
void fclUpdateMessage(void) {
  u64 v2;
  struct fclMisc_StaticFields *static_fields;
  s32 gMsgFlag;
  s32 v5;
  fclMisc_c *v7;
  struct fclMisc_StaticFields *v8;
  char v9;
  s32 gMsgID;
  System_Object_array *v12;
  fclMisc_c *v14;

  else
  {
    static_fields = fclMisc->static_fields;
    if (static_fields->gMsgID < 0)
      return;
  }
  if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
  {
    static_fields = fclMisc->static_fields;
  }
  gMsgFlag = static_fields->gMsgFlag;
  switch (gMsgFlag)
  {
    case 3:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      fclEndMessageEx(1);
      break;
    case 2:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      {
        static_fields = fclMisc->static_fields;
      }
      if ((static_fields->gSelMsgNo & 0x80000000) == 0)
      {
        if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
        {
          static_fields = fclMisc->static_fields;
        }
        gMsgID = static_fields->gMsgID;
        itfMesMngSetSelectDefKey(gMsgID, 3, 1);
        itfMesMngSetSelect(gMsgID, gSelMsgPos);
        itfMesMngRequestSelect(gMsgID, gSelMsgNo);
        gSelMsgNo = -1;
      }
      if (!*(*(v2 + 184) + 21LL))
      {
        if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
        if (!fclChkSelMessage(v2))
        {
          v12 = Empty_string_();
          Log(StringLiteral_16273, v12, 0);
          v8 = v14->static_fields;
          v9 = 3;
        }
      }
      break;
    case 1:
      if ((*(v2 + 295) & 2) != 0 && !*(v2 + 216))
      {
        static_fields = fclMisc->static_fields;
      }
      v5 = static_fields->gMsgID;
      if (itfMesMngGetPhase(v5) < 0)
      {
        v8 = v7->static_fields;
        v9 = 2;
        v8->gMsgFlag = v9;
      }
      break;
  }
}
