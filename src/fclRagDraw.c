#include "types.h"

typedef struct CounterCtr CounterCtr;
typedef struct RippleEffect RippleEffect;
typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpCursorPos_t cmpCursorPos_t;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclRagExchangeRate_t fclRagExchangeRate_t;
typedef struct fclSprite_t fclSprite_t;
typedef struct lstListWindow_t lstListWindow_t;

static char *gRagCaptionStr[3];
static void *ListObjs;
static void *TextObjs;
static void *CCtrObjs;
static void *MatCols;
static void *d_path;
static void *d_name;
static s32 CsrMoveSw;

s32 CMP_XM(s32 a);
s32 CMP_YM(s32 b);
void DrawBackPanel(char *name);
void DrawCaption2(char *name, char *caption, void *txt);
void DrawCommandSelectMenu(cmpCursorInfo_t *csr, s32 mid, s32 style);
void DrawHelp2(char *path, s32 itemid);
void DrawScrollBar(void *obj, char *name, cmpCursorPos_t *cp);
u8 Get(s32 id);
void *GetGameObject(char *name);
char *RepColTag(char *txt, void **LegacyParamArray);
void ScrollEffect(void *obj);
void Set2(CounterCtr *this, s32 val, sdfColor_t col, s32 colidx);
void SetInstitutionColor(CounterCtr *this, s32 val, s32 colidx);
void Update(RippleEffect *this);
void UpdateDrawFlag(char *name);
void UpdateItemCursor(void *csrobj, cmpCursorPos_t *csr, f32 y, f32 ofsy);
s32 datGetParam(datUnitWork_t *work, s32 paratype);
void *dds3GetProcessData(dds3ProcessID_t **id);
s8 fclChkDbgProcess(void);
void fclDrawBG(fclSprite_t *pSprite, u32 OtNo);
s8 fclRagChkExchange(fclRagExchangeRate_t **pRate);
void ragDrawDevilPanelParts(void);
void ragDrawDevilWindow(lstListWindow_t *pListWindow, u8 Type, s8 **pIdxList, s32 top, s8 Mode);
void ragDrawExchangeRate(u8 type, u8 index);
void ragDrawItemPanelParts(void);
void ragDrawItemWindow(lstListWindow_t *pListWindow, u8 Type, s8 **pIdxList, s32 top, s8 Mode);
void ragDrawSeqConfirm(void);
void ragDrawSeqErr(void);
void ragDrawSeqItem(s8 Mode);
void ragDrawSeqMitama(s8 Mode);
void ragDrawSeqRoot(s32 Mode);
void ragDrawSeqSeirei(s8 Mode);
void ragDrawSeqStatus(void);
fclRagExchangeRate_t **ragGetExchangeRate(s8 Type, u8 Index);

// 0x13cf670
void FinalizeGameObject(void) {
  PropertySheet___Clear(CCtrObjs);
  PropertySheet___Clear(TextObjs);
  PropertySheet___Clear(ListObjs);
}

// 0x13ceb20
void InitializeGameObject(void) {
    GetGameObject(0);
}

// 0x13d0b20
void SetCursorEffect(cmpCursorInfo_t *ci, void *list, char *bas, s32 len, s32 **matcol) {
  struct cmpCursorPos_t_o *CursorPos;
  s32 Shift;

  CursorPos = ci->CursorPos;
  if (CursorPos->EffFlag)
  {
    Shift = CursorPos->Shift;
    CsrMoveSw = Shift;
  }
}

// 0x13d2e00
void UpdateList(s32 mode) {
  struct System_SByte_array *v4;
  s32 v6;
  struct System_SByte_array *gFclSignal;
  s32 v10;
  struct System_SByte_array *v12;
  s32 v14;

  switch (mode)
  {
    case 3:
      v10 = gFclSignal->m_Items[0];
      ragDrawSeqMitama(v10 == 0);
      break;
    case 2:
      v12 = gFclSignal;
      v14 = v12->m_Items[0];
      ragDrawSeqSeirei(v14 == 0);
      break;
    case 1:
      v4 = gFclSignal;
      v6 = v4->m_Items[0];
      ragDrawSeqItem(v6 == 0);
      break;
  }
}

// 0x13d27a0
void *ragDraw(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    fclChkDbgProcess();
    ragDrawSeqRoot(0);
    ragDrawSeqItem(0);
    ragDrawSeqSeirei(0);
    ragDrawSeqMitama(0);
    ragDrawSeqErr();
    ragDrawSeqStatus();
    ragDrawSeqConfirm();
    return 0;
}

// 0x13cfe50
void ragDrawDevilPanelParts(void) {
  Il2CppObject *Item;
  Il2CppObject *v5;

  DrawBackPanel(StringLiteral_16296);
  DrawBackPanel(StringLiteral_16297);
  Item = object___get_Item(ListObjs, StringLiteral_16285);
  v5 = object___get_Item(ListObjs, StringLiteral_16286);
  if (!get_activeSelf(v5))
  {
    if (get_activeSelf(Item))
      return;
    SetActive(Item, 1, 0);
    return;
  }
  SetActive(v5, 0, 0);
  if (!get_activeSelf(Item))
}

// 0x13d0ba0
void ragDrawDevilWindow(lstListWindow_t *pListWindow, u8 Type, s8 **pIdxList, s32 top, s8 Mode) {
    ragDrawDevilPanelParts();
    GetGameObject(0);
    DrawScrollBar(0, 0, 0);
    ScrollEffect(0);
    ragGetExchangeRate(0, 0);
    fclRagChkExchange(0);
    Get(0);
    RepColTag(0, 0);
    Get(0);
    Set2(0, 0, (sdfColor_t){0}, 0);
    UpdateItemCursor(0, 0, 0, 0);
    DrawBackPanel(0);
}

// 0x13cf720
void ragDrawExchangeRate(u8 type, u8 index) {
    GetGameObject(0);
    ragGetExchangeRate(0, 0);
    Get(0);
    RepColTag(0, 0);
    SetInstitutionColor(0, 0, 0);
    UpdateDrawFlag(0);
}

// 0x13cfcf0
void ragDrawItemPanelParts(void) {
  Il2CppObject *Item;
  Il2CppObject *v5;

  DrawBackPanel(StringLiteral_16296);
  DrawBackPanel(StringLiteral_16297);
  Item = object___get_Item(ListObjs, StringLiteral_16285);
  v5 = object___get_Item(ListObjs, StringLiteral_16286);
  if (!get_activeSelf(Item))
  {
    if (get_activeSelf(v5))
      return;
    SetActive(v5, 1, 0);
    return;
  }
  SetActive(Item, 0, 0);
  if (!get_activeSelf(v5))
}

// 0x13cffb0
void ragDrawItemWindow(lstListWindow_t *pListWindow, u8 Type, s8 **pIdxList, s32 top, s8 Mode) {
    ragDrawItemPanelParts();
    GetGameObject(0);
    DrawScrollBar(0, 0, 0);
    ScrollEffect(0);
    ragGetExchangeRate(0, 0);
    fclRagChkExchange(0);
    Get(0);
    RepColTag(0, 0);
    UpdateItemCursor(0, 0, 0, 0);
    DrawBackPanel(0);
}

// 0x13d22c0
void ragDrawSeqConfirm(void) {
  s32 Last;
  UnityEngine_Object_o *statusUIScr;

  Last = GBWK->SeqInfo->Last;
  if (Last == 3 || Last == 2)
  {
    statusUIScr = _statusUIScr;
    if (op_Inequality(statusUIScr, 0, 0))
    {
      ragDrawSeqStatus();
    }
  }
  else if (Last == 1)
  {
    ragDrawSeqItem(1);
  }
}

// 0x13d25c0
void ragDrawSeqErr(void) {
  UnityEngine_Object_o *statusUIScr;

  switch (GBWK->SeqInfo->Last)
  {
    case 1:
      ragDrawSeqItem(1);
      break;
    case 2:
      ragDrawSeqSeirei(1);
      break;
    case 3:
      ragDrawSeqMitama(1);
      break;
    case 7:
      statusUIScr = _statusUIScr;
      if (op_Inequality(statusUIScr, 0, 0))
      {
        ragDrawSeqStatus();
      }
      break;
    default:
      return;
  }
}

// 0x13d1900
void ragDrawSeqItem(s8 Mode) {
    DrawCaption2(0, 0, 0);
    ragDrawItemWindow(0, 0, 0, 0, 0);
    ragDrawExchangeRate(0, 0);
    DrawHelp2(0, 0);
    Update(0);
}

// 0x13d1d20
void ragDrawSeqMitama(s8 Mode) {
  struct fclDataRag_t_o *GBWK;
  struct System_SByte_array *MitamaList;
  cmpCursorInfo_t_o *CursorInfo;
  s32 Index;
  s32 CursorIndex;
  s64 v10;
  fclRagDraw_c *v12;
  u8 v13;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *comparer;
  Il2CppObject *Item;

  MitamaList = GBWK->MitamaList;
  CursorInfo = GBWK->MitamaWindow->CursorInfo;
  Index = CursorInfo->CursorPos->Index;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  v10 = CursorIndex;
  v13 = MitamaList->m_Items[v10];
  static_fields = v12->static_fields;
  comparer = (*static_fields)->comparer;
  Item = object___get_Item(static_fields[2], StringLiteral_16294);
  DrawCaption2(StringLiteral_16294, comparer, Item);
  ragDrawDevilWindow(GBWK->MitamaWindow, 2u, MitamaList, Index, Mode);
  ragDrawExchangeRate(2u, v13);
  Update(0);
}

// 0x13d2420
void ragDrawSeqRoot(s32 Mode) {
  struct System_SByte_array *gFclSignal;
  s32 v4;
  cmpCursorInfo_t_o *CursorInfo;

  if (!Mode)
  {
    v4 = 1;
  }
  if (!LODWORD(gFclSignal->max_length))
  if (gFclSignal->m_Items[0])
  {
    v4 = 0;
  }
  else
  {
    if (GBWK->SeqInfo->Last == 4)
      v4 = 1;
    else
      v4 = 2;
  }
  CursorInfo = GBWK->CmdSelInfo->CursorInfo;
  DrawCommandSelectMenu(CursorInfo, 0, v4);
  Update(0);
}

// 0x13d1b50
void ragDrawSeqSeirei(s8 Mode) {
  struct fclDataRag_t_o *GBWK;
  struct System_SByte_array *SeireiList;
  cmpCursorInfo_t_o *CursorInfo;
  s32 Index;
  s32 CursorIndex;
  s64 v10;
  fclRagDraw_c *v12;
  u8 v13;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *v16;
  Il2CppObject *Item;

  SeireiList = GBWK->SeireiList;
  CursorInfo = GBWK->SeireiWindow->CursorInfo;
  Index = CursorInfo->CursorPos->Index;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  v10 = CursorIndex;
  v13 = SeireiList->m_Items[v10];
  static_fields = v12->static_fields;
  v16 = *&(*static_fields)->freeList;
  Item = object___get_Item(static_fields[2], StringLiteral_16294);
  DrawCaption2(StringLiteral_16294, v16, Item);
  ragDrawDevilWindow(GBWK->SeireiWindow, 1u, SeireiList, Index, Mode);
  ragDrawExchangeRate(1u, v13);
  Update(0);
}

// 0x13d1ef0
void ragDrawSeqStatus(void) {
  System_SByte_array *v1;
  datUnitWork_t_o *v2;
  datUnitWork_t_o *v3;
  fclSprite_t_o *SpriteBG;
  s32 v9;
  s32 v11;
  s32 Z;
  u16 id;
  u16 maxhp;
  u64 v17;
  s8 *m_Items;
  char Param;
  struct System_SByte_array *v20;
  struct System_SByte_array *v23;
  char *v25;
  s8 v27;

  v1 = NewSpecific(sbyte, 6u);
  v2 = Allocate(datUnitWork_t);
  datUnitWork_t___ctor(v2);
  v3 = Allocate(datUnitWork_t);
  datUnitWork_t___ctor(v3);
  cmpModelInitCore();
  SpriteBG = GBWK->SpriteBG;
  fclDrawBG(SpriteBG, 7u);
  v9 = CMP_XM(0);
  v11 = CMP_YM(51);
  Z = GBWK->SpriteBG->Z;
  cmpDrawBoxF(v9, v11, Z, 512, 360, 0x33u, 7u);
  id = GBWK->Devil->id;
  cmbCopyDefaultDevilToStock(id, v3);
  cmbCopyCustomDevilToStock(v2, GBWK->Devil);
  maxhp = v2->maxhp;
  v2->mp = v2->maxmp;
  v2->hp = maxhp;
  v17 = 0;
  m_Items = v1->m_Items;
  do
  {
    Param = datGetParam(v2, v17);
    v20 = v3->param;
    m_Items[v17] = Param - v20->m_Items[v17];
    v23 = v2->param;
    v25 = v23 + v17;
    v27 = m_Items[v17++];
    v25[32] -= v27;
  }
  while (v17 != 6);
  cmpStatSetCompareUnit(v3);
  cmpDrawStatusComEx(v2, 0x80u, 255, 2, v1, 0, 0xA09DC380, 3, 2, 2);
  cmpStatSetCompareUnit(0);
  Update(0);
}
