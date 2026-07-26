#include "types.h"

typedef struct FldNameData FldNameData;
typedef struct RippleEffect RippleEffect;
typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct cmpCursorPos_t cmpCursorPos_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;

static char *gTerminalCaptionStr[2];
static void *ListObjs;
static void *TextObjs;
static void *AnimObjs;
static s32 ChildCount;
static void *MatCols;
static s32 CsrMoveSw;

void DrawCaption2(char *name, char *caption, void *txt);
void DrawCommandSelectMenu(cmpCursorInfo_t *csr, s32 mid, s32 style);
void DrawScrollBar(void *obj, char *name, cmpCursorPos_t *cp);
void *GetGameObject(char *name);
char *GetSaveNmlName(FldNameData *this, s32 TmnlId);
char *GetSaveSmlName(FldNameData *this, s32 TmnlId);
char *RepColTag(char *txt, void **LegacyParamArray);
void ScrollEffect(void *obj);
void Update(RippleEffect *this);
void UpdateDrawFlag(char *name);
void *dds3GetProcessData(dds3ProcessID_t **id);
s8 fclChkDbgProcess(void);
s8 fclChkSignal(s8 Idx);
s8 trmChkEventWait(void);
void trmDrawSeqConfirm(void);
void trmDrawSeqRoot(s8 CursorStyle);
void trmDrawSeqTrans(void);
void trmDrawTerminalName(void *obj, void *txt, char *name, u32 color);
void trmDrawTerminalNamePanel(void);
char *trmGetTerminalName(s32 TerminalNo, s32 TerminalType);

// 0xf791a0
void FinalizeGameObject(void) {
  PropertySheet___Clear(AnimObjs);
  PropertySheet___Clear(ListObjs);
  PropertySheet___Clear(TextObjs);
}

// 0xf78af0
void InitializeGameObject(void) {
    GetGameObject(0);
}

// 0xf7a570
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

// 0xf7ad90
dds3ProcessFunc_t *trmDraw(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    fclChkDbgProcess();
    trmChkEventWait();
    trmDrawSeqConfirm();
    trmDrawSeqTrans();
    fclChkSignal(0);
    trmDrawSeqRoot(0);
    Update(0);
    return 0;
}

// 0xf7a5f0
void trmDrawSeqConfirm(void) {
  struct fclDataTerminal_t_o *GBWK;
  cmpCursorInfo_t_o *CursorInfo;

  trmDrawTerminalNamePanel();
  else
  {
    if (!GBWK->TerminalType)
      return;
  }
  CursorInfo = GBWK->CmdSelInfo->CursorInfo;
  DrawCommandSelectMenu(CursorInfo, 0, 1);
}

// 0xf7acc0
void trmDrawSeqRoot(s8 CursorStyle) {
  cmpCursorInfo_t_o *CursorInfo;

  CursorInfo = GBWK->CmdSelInfo->CursorInfo;
  DrawCommandSelectMenu(CursorInfo, 0, CursorStyle);
  trmDrawTerminalNamePanel();
}

// 0xf79760
void trmDrawSeqTrans(void) {
    DrawCaption2(0, 0, 0);
    trmDrawTerminalNamePanel();
    GetGameObject(0);
    DrawScrollBar(0, 0, 0);
    ScrollEffect(0);
    GetSaveNmlName(0, 0);
    trmDrawTerminalName(0, 0, 0, 0);
    UpdateDrawFlag(0);
}

// 0xf795f0
void trmDrawTerminalName(void *obj, void *txt, char *name, u32 color) {
    RepColTag(0, 0);
}

// 0xf79310
void trmDrawTerminalNamePanel(void) {
  UnityEngine_GameObject_o *GameObject;
  TMPro_TMP_Text_o *monitor;
  struct fclDataTerminal_t_o *GBWK;
  s32 TerminalNo;
  s32 TerminalType;
  System_String_o *TerminalName;

  GameObject = GetGameObject(StringLiteral_16464);
  if (!op_Equality(GameObject, 0, 0))
  {
    if (!get_activeSelf(GameObject))
      SetActive(GameObject, 1, 0);
    monitor = GetComponent_object_(GameObject)[1].monitor;
    TerminalNo = GBWK->TerminalNo;
    TerminalType = GBWK->TerminalType;
    TerminalName = trmGetTerminalName(TerminalNo, TerminalType);
    set_text(monitor, TerminalName);
    UpdateDrawFlag(StringLiteral_16464);
  }
}

// 0xf79250
char *trmGetTerminalName(s32 TerminalNo, s32 TerminalType) {
  if (TerminalType)
  {
    return GetSaveSmlName(fldNameData, TerminalNo);
  }
  else
  {
    return GetSaveNmlName(fldNameData, TerminalNo);
  }
}
