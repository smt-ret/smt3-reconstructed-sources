#include "types.h"

typedef struct CounterCtr CounterCtr;
typedef struct RippleEffect RippleEffect;
typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpCursorPos_t cmpCursorPos_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct lstListWindow_t lstListWindow_t;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;

static char *gRecoverCaptionStr[5];
static void *ListObjs;
static void *TextObjs;
static void *CCtrObjs;
static void *BImgObjs;
static void *AnimObjs;
static s32 ChildCount;
static void *MatCols;
static s32 CsrMoveSw;

void DrawBackPanel(char *name);
void DrawCaption2(char *name, char *caption, void *txt);
void DrawCommandSelectMenu(cmpCursorInfo_t *csr, s32 mid, s32 style);
void DrawPayMoney(char *name, CounterCtr *ctr, u32 col, s32 val);
void DrawScrollBar(void *obj, char *name, cmpCursorPos_t *cp);
void DrawTotalMoney(char *name, CounterCtr *ctr);
u8 Get(s32 id);
void *GetGameObject(char *name);
char *RepColTag(char *txt, void **LegacyParamArray);
void ScrollEffect(void *obj);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void Update(RippleEffect *this);
void UpdateDrawFlag(char *name);
void UpdateItemCursor(void *csrobj, cmpCursorPos_t *csr, f32 y, f32 ofsy);
void *dds3GetProcessData(dds3ProcessID_t **id);
s8 fclChkSignal(s8 Idx);
char *frGetCNameString(s8 TargetNo);
void lstDrawListWindowCursor(lstListWindow_t *pListWindow, u32 OtNo);
void rcvDrawPayMoney(u32 Color, s32 Val);
void rcvDrawSeqAllRecover(void);
void rcvDrawSeqRecover(void);
void rcvDrawSeqRoot(s32 Mode);
void rcvDrawStockWindow(lstListWindow_t *window, s8 mode);
void rcvDrawStockWindowList(void *obj, u32 Col, s8 localstockidx, bool curidx);

// 0x19911b0
void DispInsfee(s32 sw) {
  Il2CppObject *Item;

  Item = object___get_Item(AnimObjs, StringLiteral_16348);
  SetInteger(Item, StringLiteral_16353, sw);
}

// 0x19910c0
void FinalizeGameObject(void) {
  PropertySheet___Clear(AnimObjs);
  PropertySheet___Clear(BImgObjs);
  PropertySheet___Clear(CCtrObjs);
  PropertySheet___Clear(TextObjs);
  PropertySheet___Clear(ListObjs);
}

// 0x198ffd0
void InitializeGameObject(void) {
    GetGameObject(0);
}

// 0x1992850
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

// 0x19931c0
dds3ProcessFunc_t *rcvDraw(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    fclChkSignal(0);
    rcvDrawPayMoney(0, 0);
    rcvDrawSeqRoot(0);
    rcvDrawSeqAllRecover();
    rcvDrawSeqRecover();
    return 0;
}

// 0x1991250
void rcvDrawPayMoney(u32 Color, s32 Val) {
  Il2CppObject *Item;

  Item = object___get_Item(CCtrObjs, StringLiteral_16348);
  DrawPayMoney(StringLiteral_16348, Item, 0xFFFFFFFF, Val);
}

// 0x19928d0
void rcvDrawSeqAllRecover(void) {
  u64 *v1;
  bool v3;
  s8 v7;
  lstListWindow_t_o *StockWindow;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *v11;
  Il2CppObject *Item;

  v1 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v1);
  v3 = fclChkSignal(0) == 0;
  v7 = v3;
  StockWindow = GBWK->StockWindow;
  rcvDrawStockWindow(StockWindow, v7);
  static_fields = fclRecoverDraw->static_fields;
  v11 = *&(*static_fields)->count;
  Item = object___get_Item(static_fields[2], StringLiteral_16351);
  DrawCaption2(StringLiteral_16351, v11, Item);
  Update(0);
}

// 0x1992ec0
void rcvDrawSeqDispel(void) {
  u64 *v1;
  Il2CppObject *Item;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *values;
  Il2CppObject *v9;

  v1 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v1);
  Item = object___get_Item(CCtrObjs, StringLiteral_16089);
  DrawTotalMoney(StringLiteral_16350, Item);
  static_fields = fclRecoverDraw->static_fields;
  values = (*static_fields)->values;
  v9 = object___get_Item(static_fields[2], StringLiteral_16351);
  DrawCaption2(StringLiteral_16351, values, v9);
  Update(0);
}

// 0x1992a50
void rcvDrawSeqRecover(void) {
  u64 *v1;
  bool v3;
  s8 v7;
  lstListWindow_t_o *StockWindow;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *v11;
  Il2CppObject *Item;

  v1 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v1);
  v3 = fclChkSignal(0) == 0;
  v7 = v3;
  StockWindow = GBWK->StockWindow;
  rcvDrawStockWindow(StockWindow, v7);
  static_fields = fclRecoverDraw->static_fields;
  v11 = *&(*static_fields)->freeList;
  Item = object___get_Item(static_fields[2], StringLiteral_16351);
  DrawCaption2(StringLiteral_16351, v11, Item);
  Update(0);
}

// 0x1992d50
void rcvDrawSeqRevive(void) {
  bool v2;
  s8 v6;
  lstListWindow_t_o *StockWindow;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *keys;
  Il2CppObject *Item;

  v2 = fclChkSignal(0) == 0;
  v6 = v2;
  StockWindow = GBWK->StockWindow;
  rcvDrawStockWindow(StockWindow, v6);
  static_fields = fclRecoverDraw->static_fields;
  keys = (*static_fields)->keys;
  Item = object___get_Item(static_fields[2], StringLiteral_16351);
  DrawCaption2(StringLiteral_16351, keys, Item);
  Update(0);
}

// 0x1993010
void rcvDrawSeqRoot(s32 Mode) {
  u64 *v3;
  s32 v5;
  Il2CppObject *Item;

  v3 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v3);
  if (Mode)
  {
    v5 = 0;
    if (!fclChkSignal(0))
    {
      if (GBWK->SeqInfo->Last == 6)
        v5 = 1;
      else
        v5 = 2;
    }
  }
  else
  {
    v5 = 1;
  }
  Item = object___get_Item(CCtrObjs, StringLiteral_16089);
  DrawTotalMoney(StringLiteral_16350, Item);
  DrawCommandSelectMenu(GBWK->CmdSelInfo->CursorInfo, 0, v5);
  Update(0);
}

// 0x1992bd0
void rcvDrawSeqStatusRecover(void) {
  u64 *v1;
  bool v3;
  s8 v7;
  lstListWindow_t_o *StockWindow;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *comparer;
  Il2CppObject *Item;

  v1 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v1);
  v3 = fclChkSignal(0) == 0;
  v7 = v3;
  StockWindow = GBWK->StockWindow;
  rcvDrawStockWindow(StockWindow, v7);
  static_fields = fclRecoverDraw->static_fields;
  comparer = (*static_fields)->comparer;
  Item = object___get_Item(static_fields[2], StringLiteral_16351);
  DrawCaption2(StringLiteral_16351, comparer, Item);
  Update(0);
}

// 0x1992000
void rcvDrawStockWindow(lstListWindow_t *window, s8 mode) {
    DrawBackPanel(0);
    GetGameObject(0);
    DrawScrollBar(0, 0, 0);
    ScrollEffect(0);
    rcvDrawStockWindowList(0, 0, 0, 0);
    UpdateItemCursor(0, 0, 0, 0);
    DrawTotalMoney(0, 0);
    lstDrawListWindowCursor(0, 0);
    UpdateDrawFlag(0);
}

// 0x1991320
void rcvDrawStockWindowList(void *obj, u32 Col, s8 localstockidx, bool curidx) {
    frGetCNameString(0);
    Get(0);
    RepColTag(0, 0);
    Set(0, 0);
}
