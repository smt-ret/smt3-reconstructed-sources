#include "types.h"

typedef struct CounterCtr CounterCtr;
typedef struct RippleEffect RippleEffect;
typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpCursorPos_t cmpCursorPos_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fclPanelPos_t fclPanelPos_t;
typedef struct lstListWindow_t lstListWindow_t;
typedef struct mdlManager_AbHeaderParm_t mdlManager_AbHeaderParm_t;

static char *gShopCaptionStr[2];
static void *ListObjs;
static void *TextObjs;
static void *CCtrObjs;
static void *AnimFee;
static s32 ChildCount;
static void *MatCols;
static s32 CsrMoveSw;

s32 CMP_Y(s32 b);
void DispItemList(void *obj, bool sw);
void DispItemUD(void *obj, s32 val, s32 mode);
void DrawBackPanel(char *name);
void DrawCaption2(char *name, char *caption, void *txt);
void DrawCommandSelectMenu(cmpCursorInfo_t *csr, s32 mid, s32 style);
void DrawHelp(char *path, s32 itemid);
void DrawPayMoney(char *name, CounterCtr *ctr, u32 col, s32 val);
void DrawScrollBar(void *obj, char *name, cmpCursorPos_t *cp);
void DrawTotalMoney(char *name, CounterCtr *ctr);
u8 Get(s32 id);
void *GetGameObject(char *name);
char *GetLocalizeText(char *ID);
char *RepColTag(char *txt, void **LegacyParamArray);
void ScrollEffect(void *obj);
void Set(mdlManager_AbHeaderParm_t *this, u8 **src);
void SetInstitutionColor(CounterCtr *this, s32 val, s32 colidx);
void Update(RippleEffect *this);
void UpdateDrawFlag(char *name);
void UpdateItemCursor(void *csrobj, cmpCursorPos_t *csr, f32 y, f32 ofsy);
void *dds3GetProcessData(dds3ProcessID_t **id);
s8 fclChkDbgProcess(void);
s8 fclChkItemHearts(u16 ItemID);
s8 fclChkSignal(s8 Idx);
void fclInitPanelPos(s32 X, s32 Y, u32 Z, u16 W, u16 H, s32 Work, fclPanelPos_t *pPanelPos);
void lstDrawListWindowCursor(lstListWindow_t *pListWindow, u32 OtNo);
void shopClearNumControl(void);
s32 shpCalcItemPrice(s32 Index, s8 Mode);
s8 shpChkChoiceMax(s32 Index, s8 Mode, s8 CalcMode);
void shpDrawBuyItem(s8 Place, lstListWindow_t *pListWindow, s8 mode);
void shpDrawItem(char *path, u32 col, u16 item, s32 price);
void shpDrawNumsControl(cmpCursorInfo_t *csr, s32 val, s8 mode);
void shpDrawPanelParts(s32 mode);
void shpDrawPayMoney(u32 Color, s32 Val);
void shpDrawSellItem(s8 Place, lstListWindow_t *pListWindow, s8 Mode);
void shpDrawSeqBuy(s8 Mode);
void shpDrawSeqConfirm(s8 Mode);
void shpDrawSeqRoot(s32 Mode);
void shpDrawSeqSelect(s8 Mode);
void shpDrawSeqSell(s8 Mode);

// 0x19a18f0
void DispInsfee(s32 sw) {
  UnityEngine_Object_o *AnimFee;

  if (op_Inequality(AnimFee, 0, 0))
  {
    SetInteger(AnimFee, StringLiteral_16353, sw);
  }
}

// 0x19a1ab0
void DispItemList(void *obj, bool sw) {
  _BOOL4 v3;
  System_String_o *name;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  Il2CppObject *v9;
  Il2CppObject *Item;
  System_Collections_Generic_Dictionary_object__object__o *v13;
  Il2CppObject *v14;
  Il2CppObject *v15;
  System_Collections_Generic_Dictionary_object__object__o *v18;
  Il2CppObject *v19;
  Il2CppObject *v20;

  v3 = sw;
  name = get_name(obj);
  v9 = Concat_5224608(name, StringLiteral_16393);
  Item = object___get_Item(ListObjs, v9);
  if (((get_activeSelf(Item) ^ v3) & 1) != 0)
    SetActive(Item, v3, 0);
  v13 = ListObjs;
  v14 = Concat_5224608(name, StringLiteral_16395);
  v15 = object___get_Item(v13, v14);
  if (((get_activeSelf(v15) ^ v3) & 1) != 0)
    SetActive(v15, v3, 0);
  v18 = ListObjs;
  v19 = Concat_5224608(name, StringLiteral_16403);
  v20 = object___get_Item(v18, v19);
  if (((get_activeSelf(v20) ^ v3) & 1) != 0)
    SetActive(v20, v3, 0);
}

// 0x19a1c90
void DispItemUD(void *obj, s32 val, s32 mode) {
  System_String_o *name;
  System_Collections_Generic_Dictionary_object__object__o *ListObjs;
  Il2CppObject *v10;
  Il2CppObject *Item;
  System_Collections_Generic_Dictionary_object__object__o *v14;
  Il2CppObject *v15;
  Il2CppObject *v16;
  System_Collections_Generic_Dictionary_object__object__o *v19;
  Il2CppObject *v20;
  Il2CppObject *v21;
  u32 v22;

  name = get_name(obj);
  v10 = Concat_5224608(name, StringLiteral_16397);
  Item = object___get_Item(ListObjs, v10);
  if (!get_activeSelf(Item))
    SetActive(Item, 1, 0);
  v14 = ListObjs;
  v15 = Concat_5224608(name, StringLiteral_16399);
  v16 = object___get_Item(v14, v15);
  if (((mode ^ get_activeSelf(v16)) & 1) != 0)
    SetActive(v16, mode & 1, 0);
  v19 = ListObjs;
  v20 = Concat_5224608(name, StringLiteral_16401);
  v21 = object___get_Item(v19, v20);
  v22 = mode & 2;
  if (get_activeSelf(v21) != v22 >> 1)
    SetActive(v21, v22 != 0, 0);
}

// 0x19a1870
void FinalizeGameObject(void) {
  PropertySheet___Clear(ListObjs);
}

// 0x19a0a80
void InitializeGameObject(void) {
    GetGameObject(0);
}

// 0x19a30a0
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

// 0x19a1e70
void shopClearNumControl(void) {
    DispItemList(0, 0);
}

// 0x19a4210
void *shpDraw(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    fclChkDbgProcess();
    fclChkSignal(0);
    shpDrawPayMoney(0, 0);
    shpDrawSeqBuy(0);
    shpDrawSeqSell(0);
    shpDrawSeqSelect(0);
    shpDrawSeqConfirm(0);
    shpDrawSeqRoot(0);
    return 0;
}

// 0x19a2840
void shpDrawBuyItem(s8 Place, lstListWindow_t *pListWindow, s8 mode) {
    shpDrawPanelParts(0);
    GetGameObject(0);
    DrawScrollBar(0, 0, 0);
    ScrollEffect(0);
    shpCalcItemPrice(0, 0);
    fclChkItemHearts(0);
    shpDrawItem(0, 0, 0, 0);
    DrawHelp(0, 0);
    UpdateItemCursor(0, 0, 0, 0);
}

// 0x19a23e0
void shpDrawItem(char *path, u32 col, u16 item, s32 price) {
    Get(0);
    GetLocalizeText(0);
    RepColTag(0, 0);
    Set(0, 0);
}

// 0x19a1fa0
void shpDrawNumsControl(cmpCursorInfo_t *csr, s32 val, s8 mode) {
    DispItemList(0, 0);
    SetInstitutionColor(0, 0, 0);
    DispItemUD(0, 0, 0);
}

// 0x19a2230
void shpDrawPanelParts(s32 mode) {
  Il2CppObject *Item;
  Il2CppObject *v6;
  bool activeSelf;
  UnityEngine_GameObject_o *v9;
  bool v10;

  DrawBackPanel(StringLiteral_16424);
  DrawBackPanel(StringLiteral_16425);
  Item = object___get_Item(ListObjs, StringLiteral_16412);
  v6 = object___get_Item(ListObjs, StringLiteral_16414);
  activeSelf = get_activeSelf(Item);
  if (mode)
  {
    if (!activeSelf)
      SetActive(Item, 1, 0);
    if (get_activeSelf(v6))
    {
      v9 = v6;
      v10 = 0;
      SetActive(v9, v10, 0);
    }
  }
  else
  {
    if (activeSelf)
      SetActive(Item, 0, 0);
    if (!get_activeSelf(v6))
    {
      v9 = v6;
      v10 = 1;
    }
  }
  UpdateDrawFlag(StringLiteral_16391);
}

// 0x19a19e0
void shpDrawPayMoney(u32 Color, s32 Val) {
  Il2CppObject *Item;

  Item = object___get_Item(CCtrObjs, StringLiteral_16420);
  DrawPayMoney(StringLiteral_16420, Item, 0xFFFFFFFF, Val);
}

// 0x19a3120
void shpDrawSellItem(s8 Place, lstListWindow_t *pListWindow, s8 Mode) {
    shpDrawPanelParts(0);
    GetGameObject(0);
    DrawScrollBar(0, 0, 0);
    ScrollEffect(0);
    shpCalcItemPrice(0, 0);
    shpDrawItem(0, 0, 0, 0);
    DrawHelp(0, 0);
    UpdateItemCursor(0, 0, 0, 0);
    lstDrawListWindowCursor(0, 0);
}

// 0x19a3a80
void shpDrawSeqBuy(s8 Mode) {
    DrawCaption2(0, 0, 0);
    DrawTotalMoney(0, 0);
    shopClearNumControl();
    shpDrawBuyItem(0, 0, 0);
    Update(0);
}

// 0x19a4020
void shpDrawSeqConfirm(s8 Mode) {
  u64 *v3;
  struct fclDataShop_t_o *GBWK;
  cmpCursorInfo_t_o *CursorInfo;
  s32 ChoiceNums;

  v3 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v3);
  if (Mode)
  {
    shpDrawSeqSell(2);
  }
  else
  {
    shpDrawSeqBuy(2);
  }
  CursorInfo = GBWK->ListWindow->CursorInfo;
  ChoiceNums = GBWK->ChoiceNums;
  shpDrawNumsControl(CursorInfo, ChoiceNums, 4);
}

// 0x19a4130
void shpDrawSeqErr(void) {
  shpDrawSeqBuy(1);
}

// 0x19a38f0
void shpDrawSeqRoot(s32 Mode) {
  s32 v3;
  Il2CppObject *Item;

  if (Mode)
  {
    v3 = 0;
    if (!fclChkSignal(0))
    {
      if (GBWK->SeqInfo->Last == 3)
        v3 = 1;
      else
        v3 = 2;
    }
  }
  else
  {
    v3 = 1;
  }
  Item = object___get_Item(CCtrObjs, StringLiteral_16089);
  DrawTotalMoney(StringLiteral_16419, Item);
  DrawCommandSelectMenu(GBWK->CmdSelInfo->CursorInfo, 0, v3);
  Update(0);
}

// 0x19a3d90
void shpDrawSeqSelect(s8 Mode) {
  u64 *v3;
  s16 v8;
  s32 v9;
  s32 ChoiceNums;
  s32 v11;
  s32 v13;
  s16 v15;
  s32 v16;
  struct fclDataShop_t_o *GBWK;
  s32 v18;
  s32 v19;
  s8 v20;
  struct lstListWindow_t_o *ListWindow;
  struct cmpCursorInfo_t_o *CursorInfo;
  struct fclPanelPos_t_o *Pos;
  s32 X;
  s32 Y;
  s32 Shift;
  s32 StepY;
  s32 v29;
  struct fclDataShop_t_o *v32;
  s32 v33;
  cmpCursorInfo_t_o *v34;

  v3 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v3);
  if (Mode)
  {
    shpDrawSeqSell(1);
  }
  else
  {
    shpDrawSeqBuy(1);
  }
  if ((v8 & 0x200) != 0)
  {
    v9 = v8 & 0x200;
  }
  else
  {
    v9 = 0;
  }
  ChoiceNums = GBWK->ChoiceNums;
  v11 = ChoiceNums == 1;
  if (ChoiceNums == 99)
    v11 = 2;
  v13 = shpChkChoiceMax(-1, Mode, 1);
  if ((v15 & 0x200) != 0)
  {
    v16 = v15 & 0x200;
  }
  else
  {
    v16 = 0;
  }
  if (v11 == 1)
    v18 = 4;
  else
    v18 = 2;
  if (v13 <= GBWK->ChoiceNums)
    v19 = v18;
  else
    v19 = v11;
  if (v19)
    v20 = v19;
  else
    v20 = 3;
  ListWindow = GBWK->ListWindow;
  CursorInfo = ListWindow->CursorInfo;
  Pos = ListWindow->Pos;
  X = Pos->X;
  Y = Pos->Y;
  Shift = CursorInfo->CursorPos->Shift;
  StepY = CursorInfo->StepY;
  v29 = CMP_Y(StepY * Shift);
  fclInitPanelPos(X, v29 + Y, 0xFFFFFu, 0, 0, 0, v3);
  v32 = GBWK;
  v33 = v32->ChoiceNums;
  v34 = v32->ListWindow->CursorInfo;
  shpDrawNumsControl(v34, v33, v20);
}

// 0x19a3c10
void shpDrawSeqSell(s8 Mode) {
  fclShopDraw_c *v3;
  System_Collections_Generic_Dictionary_object__object__o **static_fields;
  System_String_o *v6;
  Il2CppObject *Item;
  Il2CppObject *v9;
  fclShopInit_c *v13;

  static_fields = v3->static_fields;
  v6 = *&(*static_fields)->freeList;
  Item = object___get_Item(static_fields[2], StringLiteral_16421);
  DrawCaption2(StringLiteral_16421, v6, Item);
  v9 = object___get_Item(CCtrObjs, StringLiteral_16089);
  DrawTotalMoney(StringLiteral_16419, v9);
  shopClearNumControl();
  shpDrawSellItem(v13, GBWK->ListWindow, Mode);
  Update(0);
}

// 0x19a41a0
void shpDrawServiceTicket(void) {
  shpDrawSeqRoot(0);
}
