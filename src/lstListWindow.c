#include "types.h"

typedef struct fclPanelPos_t fclPanelPos_t;
typedef struct fclPanel_t fclPanel_t;
typedef struct lstListWindow_t lstListWindow_t;

s32 CMP_X(s32 a);
s32 CMP_Y(s32 b);
s32 SDF_ABORT1(char *a);
u64 SDF_GS_SET_TEST(u8 ate, u8 atst, u8 aref, u8 afail, u8 date, u8 datm, u8 zte, u32 ztst);
void fclDrawPanel(fclPanel_t *pPanel, u32 OtNo);
u32 fclGetPanelFlag(fclPanel_t *panel);
void fclInitPanel(fclPanel_t *pPanel, s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Type, s8 Spd);
void fclInitPanelPos(s32 X, s32 Y, u32 Z, u16 W, u16 H, s32 Work, fclPanelPos_t *pPanelPos);
void fclSetPanelFlag(fclPanel_t *panel, u32 flag);
void fclUpdatePanel(fclPanel_t *pPanel);
void lstDrawUpDownCursor(lstListWindow_t *pListWindow, u32 OtNo);
void lstMoveCursor(lstListWindow_t *pListWindow, s8 Dir);

// 0xdf70a0
void lstDisableItemAttr(s32 Pos, u8 Attr, lstListWindow_t *pListWindow) {
  struct System_Byte_array *ItemAttr;

  if (Pos >= 256)
  {
    SDF_ABORT1(StringLiteral_17068);
  }
  ItemAttr = pListWindow->ItemAttr;
  ItemAttr->m_Items[Pos] &= ~Attr;
}

// 0xdf74f0
void lstDrawListWindow(lstListWindow_t *pListWindow, s8 Mode, u32 OtNo) {
  u64 v8;
  u32 v9;
  u64 v12;
  cmpCursorInfo_t_o *CursorInfo;

  fclDrawPanel(pListWindow->Panel, OtNo);
  v8 = SDF_GS_SET_TEST(1u, 0, 0, 3u, 0, 0, 1u, 2u);
  cmpSetRegTEST(v8, OtNo);
  if (!Mode)
    lstDrawUpDownCursor(pListWindow, v9);
  v12 = SDF_GS_SET_TEST(1u, 5u, 1u, 1u, 0, 0, 1u, 2u);
  cmpSetRegTEST(v12, OtNo);
  CursorInfo = pListWindow->CursorInfo;
  cmpUpdateCursorEff(CursorInfo);
  fclUpdatePanel(pListWindow->Panel);
}

// 0xdf7660
void lstDrawListWindowCursor(lstListWindow_t *pListWindow, u32 OtNo) {
  s32 X;
  s32 v6;
  s32 v7;
  s32 Y;
  s32 v9;
  s32 v10;
  struct cmpCursorInfo_t_o *pCursorInfo;
  u32 Z;
  struct cmpCursorSize_t_o *CursorSize;
  s32 v15;
  s32 H;
  s32 W;

  X = pListWindow->Panel->X;
  v6 = pListWindow->CursorInfo->CursorSize->X;
  v7 = CMP_X(v6);
  Y = pListWindow->Panel->Y;
  v9 = v7;
  v10 = CMP_Y(pListWindow->CursorInfo->CursorSize->Y);
  pCursorInfo = pListWindow->CursorInfo;
  Z = pListWindow->Panel->Z;
  CursorSize = pCursorInfo->CursorSize;
  v15 = v10;
  W = CursorSize->W;
  H = CursorSize->H;
  cmpDrawCommandCursor(v9 + X, v15 + Y, Z, W, H, 0x80808080, 256, 0, pCursorInfo, 0, OtNo);
}

// 0xdf7420
void lstDrawUpDownCursor(lstListWindow_t *pListWindow, u32 OtNo) {
  u32 v5;
  cmpCursorInfo_t_o *CursorInfo;
  s32 v8;
  cmpCursorInfo_t_o *v9;
  u32 v10;

  v5 = fclGetPanelFlag(pListWindow->Panel) & 0xFFFF0000;
  CursorInfo = pListWindow->CursorInfo;
  v8 = v5 | (cmpChkListTop(CursorInfo) == 0);
  v9 = pListWindow->CursorInfo;
  if (cmpChkListBottom(v9))
    v10 = v8;
  else
    v10 = v8 | 2;
  fclSetPanelFlag(pListWindow->Panel, v10);
}

// 0xdf6fe0
void lstEnableItemAttr(s32 Pos, u8 Attr, lstListWindow_t *pListWindow) {
  struct System_Byte_array *ItemAttr;

  if (Pos >= 256)
  {
    SDF_ABORT1(StringLiteral_17068);
  }
  ItemAttr = pListWindow->ItemAttr;
  ItemAttr->m_Items[Pos] |= Attr;
}

// 0xdf6e50
void lstInitListWindow(s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Style, lstListWindow_t *pListWindow) {
  fclPanel_t_o *Panel;
  fclPanelPos_t_o *Pos;
  struct System_Byte_array *ItemAttr;
  char *max_length;
  u64 v22;

  Panel = pListWindow->Panel;
  if (Style)
    fclInitPanel(Panel, X, Y, Z, W, H, 0, 3, 16);
  else
    fclInitPanel(Panel, X, Y, Z, W, H, 0, 1, 16);
  Pos = pListWindow->Pos;
  fclInitPanelPos(X, Y, Z, W, H, 0, Pos);
  pListWindow->Col = Col;
  ItemAttr = pListWindow->ItemAttr;
  pListWindow->Style = 0;
  max_length = ItemAttr->max_length;
  if (max_length >= 1)
  {
    v22 = 0;
    do
    {
      max_length = ItemAttr + v22++;
      max_length[32] = 1;
      ItemAttr = pListWindow->ItemAttr;
      LODWORD(max_length) = ItemAttr->max_length;
    }
    while (v22 < max_length);
  }
}

// 0xdf7160
void lstMoveCursor(lstListWindow_t *pListWindow, s8 Dir) {
  cmpCursorInfo_t_o *CursorInfo;
  s32 CursorIndex;
  s32 v8;
  cmpCursorInfo_t_o *v9;
  cmpCursorInfo_t_o *v11;
  s32 v12;
  struct System_Byte_array *ItemAttr;
  cmpCursorInfo_t_o *v15;

  CursorInfo = pListWindow->CursorInfo;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  if (Dir)
  {
    v8 = CursorIndex;
    do
    {
      v9 = pListWindow->CursorInfo;
      if (!cmpMoveCursor(v9, Dir))
        break;
      v11 = pListWindow->CursorInfo;
      v12 = cmpGetCursorIndex(v11);
      if (v12 == v8)
        break;
      ItemAttr = pListWindow->ItemAttr;
    }
    while ((ItemAttr->m_Items[v12] & 1) == 0);
  }
  else
  {
    v15 = pListWindow->CursorInfo;
    cmpMoveCursor(v15, 0);
  }
}

// 0xdf72c0
void lstMoveCursor2(lstListWindow_t *pListWindow, s8 Dir) {
  cmpCursorInfo_t_o *CursorInfo;
  s32 CursorIndex;
  s32 v8;
  cmpCursorInfo_t_o *v9;
  cmpCursorInfo_t_o *v11;
  s32 v12;
  struct System_Byte_array *ItemAttr;
  cmpCursorInfo_t_o *v15;

  CursorInfo = pListWindow->CursorInfo;
  CursorIndex = cmpGetCursorIndex(CursorInfo);
  if (Dir)
  {
    v8 = CursorIndex;
    do
    {
      v9 = pListWindow->CursorInfo;
      if (!cmpMoveCursor2(v9, Dir))
        break;
      v11 = pListWindow->CursorInfo;
      v12 = cmpGetCursorIndex(v11);
      if (v12 == v8)
        break;
      ItemAttr = pListWindow->ItemAttr;
    }
    while ((ItemAttr->m_Items[v12] & 1) == 0);
  }
  else
  {
    v15 = pListWindow->CursorInfo;
    cmpMoveCursor2(v15, 0);
  }
}

// 0xdf7810
s32 lstPageDown(lstListWindow_t *plistwin) {
  struct cmpCursorInfo_t_o *CursorInfo;
  struct cmpCursorPos_t_o *CursorPos;
  u32 ShiftMax;
  u32 v7;

  CursorInfo = plistwin->CursorInfo;
  CursorPos = CursorInfo->CursorPos;
  ShiftMax = CursorPos->ShiftMax;
  if (!CursorPos->ShiftMax)
    return 0;
  v7 = 0;
  do
  {
    if (CursorInfo->StopFlag)
      break;
    lstMoveCursor(plistwin, 1);
    ++v7;
  }
  while (v7 < ShiftMax);
  return v7;
}

// 0xdf77a0
s32 lstPageUp(lstListWindow_t *plistwin) {
  struct cmpCursorInfo_t_o *CursorInfo;
  struct cmpCursorPos_t_o *CursorPos;
  u32 ShiftMax;
  u32 v7;

  CursorInfo = plistwin->CursorInfo;
  CursorPos = CursorInfo->CursorPos;
  ShiftMax = CursorPos->ShiftMax;
  if (!CursorPos->ShiftMax)
    return 0;
  v7 = 0;
  do
  {
    if (CursorInfo->StopFlag)
      break;
    lstMoveCursor(plistwin, 255);
    ++v7;
  }
  while (v7 < ShiftMax);
  return v7;
}
