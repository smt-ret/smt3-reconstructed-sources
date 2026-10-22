#include "types.h"

typedef struct _FRQ _FRQ;
typedef struct cmpCursorInfo_t cmpCursorInfo_t;
typedef struct fclPanelPos_t fclPanelPos_t;
typedef struct fclSprTblArry_t fclSprTblArry_t;
typedef struct fclSpriteBase_t fclSpriteBase_t;
typedef struct fclSprite_t fclSprite_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 fclDrawBG_lev;

s32 CMP_X(s32 a);
s32 CMP_XM(s32 a);
s32 CMP_Y(s32 b);
s32 CMP_YM(s32 b);
s32 FR_STR_WIDTH(_FRQ *frq);
s8 fclChkItemHearts(u16 ItemID);
void fclCreatePartsSprite(u32 Z, fclSprite_t *pSprite, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry);
void fclDrawParts(s32 X, s32 Y, u32 Z, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t *pSprTblArry, u32 OtNo);
void fclDrawPartsEx3(s32 X, s32 Y, u32 Z, u8 FilterFlag, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry, u32 OtNo);
void fclDrawSpriteAngleCore(s32 X, s32 Y, s32 W, s32 H, f32 Angle, u32 **pCol, fclSprite_t *pSprite, u8 FlipFlag, u8 AlphaFlag, u8 FilterFlag, u32 OtNo);
void fclDrawSpriteCore(s32 X, s32 Y, s32 W, s32 H, u32 **pCol, fclSprite_t *pSprite, u8 FlipFlag, u8 AlphaFlag, u8 FilterFlag, u32 OtNo);
void fclDrawSpriteEx(s32 X, s32 Y, s32 W, s32 H, fclSprite_t *pSprite, u32 OtNo);
void fclDrawStrCenterTarget(s32 X, s32 Y, u32 Z, u16 W, u16 H, u32 Col, s8 pStr, u32 OtNo);
u32 fclGetBlendColor(u32 Col1, u32 Col2, u32 Rate);
void fclInitPanelPos(s32 X, s32 Y, u32 Z, u16 W, u16 H, s32 Work, fclPanelPos_t *pPanelPos);
void fclSetSpriteEx(fclSprite_t *pSprite, fclSpriteBase_t *pSpriteBase, s32 X, s32 Y, s32 Z, u32 Col, u8 Flag, sdfTexHandle_t *TexHandle);
_FRQ *frDestroyFontRequestAfter(_FRQ *pFRQ);
s32 frDrawFontEx2(_FRQ *pFRQ, s8 Mode, u32 Ot);
void frSetDrawPosition(_FRQ *pFRQ, s32 X, s32 Y);
void frSetMessageDefStepY(void);
void frSetMessageStepY(s32 StepY);
_FRQ *frwGetNumFontFRQ_20604240(s32 X, s32 Y, s32 Pri, u32 Color, char *pStr, _FRQ *pFRQ);
_FRQ *frwGetSmallCaptionFontFRQ(s32 X, s32 Y, s32 Pri, u32 Color, u8 pStr, _FRQ *pFRQ);
_FRQ *frwGetSmallFontFRQ2_20603280(s32 X, s32 Y, s32 Pri, u32 Color, char *pStr, _FRQ *pFRQ);
_FRQ *frwGetSmallNumFontFRQ_20603536(s32 X, s32 Y, s32 Pri, u32 Color, char *pStr, _FRQ *pFRQ);

// 0x1197ea0
s32 FCL_BLEND_ALPHA(s64 src, s64 dst) {
  return ((dst * src) >> 7) | src & 0xFFFFFF00;
}

// 0x1197ec0
s32 FCL_MAKE_COL(s32 r, s32 g, s32 b, u32 a) {
  return (g << 16) | (r << 24) | (b << 8) | a;
}

// 0x11980f0
void fclCreatePartsSprite(u32 Z, fclSprite_t *pSprite, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry) {
  u32 v13;
  Il2CppClass **v15;
  char *v16;
  Il2CppClass *v17;
  const char *namespaze;
  s64 v20;
  s64 v22;
  s64 v23;
  s64 v25;
  s32 v26;
  s32 v27;
  u8 v28;
  s64 v29;
  fclSpriteBase_t_o *v30;
  sdfTexHandle_t_o *v32;

  v13 = TblNo;
  v15 = &pSprTblArry->obj.klass + TblNo;
  v17 = v15[4];
  v16 = (v15 + 4);
  namespaze = v17->_1.namespaze;
  v20 = *&namespaze[8 * PartsNo + 32];
  v22 = *(*v16 + 16LL);
  v23 = *(v20 + 22);
  v25 = v22 + 8 * v23;
  v26 = *(v20 + 16);
  v27 = *(v20 + 18);
  v28 = *(v20 + 20);
  v29 = *(v25 + 32);
  v30 = *(v29 + 24);
  v32 = pTexHandle->m_Items[*(v29 + 16)];
  fclSetSpriteEx(pSprite, v30, v26, v27, Z, 0x80808080, v28, v32);
}

// 0x1198000
void fclDrawBG(fclSprite_t *pSprite, u32 OtNo) {
  struct fclSpriteBase_t_o *Base;
  s32 W;
  s32 H;

  if (pSprite)
  {
    Base = pSprite->Base;
    W = Base->W;
    H = Base->H;
    fclDrawSpriteEx(0, 0, W, H, pSprite, OtNo);
  }
  else
  {
    cmpDrawBoxF(0, 0, 0, 512, 448, 0x80u, OtNo);
  }
}

// 0x1199490
void fclDrawCaption(fclPanelPos_t *pPos, char *pStr, u32 OtNo) {
  s32 v7;
  s32 v8;
  _FRQ_o *SmallFontFRQ2_20603280;
  _FRQ_o *v11;
  s32 v12;
  _FRQ_o *prev;
  s32 v14;
  s32 space;
  s32 v16;
  s32 v19;
  u32 Z;
  s32 Y;

  v7 = CMP_XM(16);
  v8 = CMP_YM(2);
  SmallFontFRQ2_20603280 = frwGetSmallFontFRQ2_20603280(v7, pPos->Y + v8, pPos->Z, 0xA09DC380, pStr, 0);
  v11 = SmallFontFRQ2_20603280;
  if (!SmallFontFRQ2_20603280)
  {
    v16 = 32;
      goto LABEL_16;
    goto LABEL_13;
  }
  v12 = 0;
  prev = SmallFontFRQ2_20603280;
  do
  {
    v14 = FR_STR_WIDTH(prev);
    space = prev->space;
    prev = prev->prev;
    v12 += v14 + space + 3;
  }
  while (prev);
  v16 = v12 + 32;
  {
LABEL_13:
  }
LABEL_16:
  v19 = CMP_XM(0);
  Y = pPos->Y;
  Z = pPos->Z;
  cmpDrawBoxF(v19, Y, Z, v16, 26, 0x30303080u, OtNo);
  frDrawFontEx2(v11, 1, OtNo);
  frDestroyFontRequestAfter(v11);
}

// 0x1199670
void fclDrawCaption2(fclPanelPos_t *pPos, char *pStr, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry, u32 OtNo) {
  s32 v11;
  s32 v12;
  _FRQ_o *SmallFontFRQ2_20603280;

  v11 = CMP_X(39);
  v12 = CMP_Y(0);
  SmallFontFRQ2_20603280 = frwGetSmallFontFRQ2_20603280(v11, pPos->Y + v12, pPos->Z, 0xA09DC380, pStr, 0);
  fclDrawParts(0, 0, 0xFFFFFu, 0, 0, 0, pTexHandle, pSprTblArry, OtNo);
  frDrawFontEx2(SmallFontFRQ2_20603280, 1, OtNo);
  frDestroyFontRequestAfter(SmallFontFRQ2_20603280);
}

// 0x1199b40
void fclDrawItemNums(fclPanelPos_t *pPos, u16 ItemID, u32 OtNo) {
  u64 *v7;
  s32 X;
  s32 Y;
  u32 Z;
  s32 v14;
  s32 v16;
  u32 v17;
  _FRQ_o *NumFontFRQ_20604240;
  s32 v19;
  _FRQ_o *v20;
  s32 v22;
  struct System_Byte_array *item;
  u64 *v26;
  System_String_o *v28;
  s32 v29;
  s32 v31;
  s32 v32;
  _FRQ_o *v34;
  s32 v35;

  v7 = Allocate(fclPanelPos_t);
  fclPanelPos_t___ctor(v7);
  X = pPos->X;
  Y = pPos->Y;
  Z = pPos->Z;
  fclInitPanelPos(X, Y, Z, 0, 0, 0, v7);
  frSetMessageStepY(47);
  cmpDrawHelp(v7, ItemID, 1, 1, 256, 0x51u);
  frSetMessageDefStepY();
  v14 = CMP_XM(57);
  v16 = CMP_YM(71);
  v17 = pPos->Z;
  NumFontFRQ_20604240 = frwGetNumFontFRQ_20604240(v14 + X, v16 + Y, 16 * v17, 0xA0F0EB80, "所持数", 0);
  frDrawFontEx2(NumFontFRQ_20604240, 1, OtNo);
  frDestroyFontRequestAfter(NumFontFRQ_20604240);
  LODWORD(NumFontFRQ_20604240) = CMP_XM(150);
  v19 = CMP_YM(71);
  v20 = frwGetNumFontFRQ_20604240(NumFontFRQ_20604240 + X, v19 + Y, 16 * pPos->Z, 0xA0F0EB80, "個", 0);
  frDrawFontEx2(v20, 1, OtNo);
  frDestroyFontRequestAfter(v20);
  if (fclChkItemHearts(ItemID))
  {
    v22 = 0;
  }
  else
  {
    item = DDS3_GBWK->item;
    v22 = item->m_Items[ItemID];
  }
  v35 = v22;
  v26 = sub_8D3950(s32, &v35);
  v28 = Format("{0,2:D}", v26, 0);
  v29 = CMP_XM(123);
  v31 = CMP_YM(71);
  v32 = pPos->Z;
  v34 = frwGetNumFontFRQ_20604240(v29 + X, v31 + Y, v32, 0xA0F0EB80, v28, 0);
  frDrawFontEx2(v34, 1, OtNo);
  frDestroyFontRequestAfter(v34);
}

// 0x1199210
void fclDrawNumsCenterTargetX(s32 X, s32 Y, u32 Z, u32 Col, s32 Val, u32 OtNo) {
  u64 *v13;
  System_String_o *v14;
  _FRQ_o *SmallNumFontFRQ_20603536;
  s32 v18;
  s32 v19;
  s32 v20;

  v20 = Val;
  v13 = sub_8D3950(s32, &v20);
  v14 = Format("{0:D}", v13, 0);
  SmallNumFontFRQ_20603536 = frwGetSmallNumFontFRQ_20603536(X, Y, Z, Col, v14, 0);
  v18 = FR_STR_WIDTH(SmallNumFontFRQ_20603536);
  v19 = CMP_XM(v18 >> 1);
  frSetDrawPosition(SmallNumFontFRQ_20603536, X - v19, Y);
  frDrawFontEx2(SmallNumFontFRQ_20603536, 1, OtNo);
  frDestroyFontRequestAfter(SmallNumFontFRQ_20603536);
}

// 0x11997c0
void fclDrawPanelCaption(fclPanelPos_t *pPos, s8 Nums, s32 OfsX, s32 OfsY, s8 **pOfsH, u16 **pW, u16 **pH, s8 **pStr, u32 OtNo) {
  s32 v15;
  s32 v16;
  s32 v17;
  u64 v18;
  u16 *m_Items;
  u32 Z;
  s32 v22;
  s32 v24;
  s32 v27;
  s32 v29;
  s32 v30;
  s32 X;
  s32 v32;
  u16 v34;
  u32 v35;
  u64 v36;
  s32 v37;
  u16 *v38;
  u32 v39;
  u16 v41;
  s8 v44;
  s32 v47;
  s32 v49;
  s32 v51;
  s32 Y;
  fclPanelPos_t_o *v54;
  s64 v56;

  v15 = pPos->Y;
  v56 = Nums;
  v54 = pPos;
  if (Nums >= 1)
  {
    v51 = OfsX;
    v16 = v15 - OfsY;
    v17 = pPos->X + OfsX;
    v18 = 0;
    m_Items = pW->m_Items;
    do
    {
      Z = pPos->Z;
      v22 = m_Items[v18];
      v24 = pH->m_Items[v18];
      cmpDrawBoxF(v17, v16, Z, v22, v24, 0x60u, OtNo);
      v27 = pOfsH->m_Items[v18];
      v29 = m_Items[v18];
      v30 = CMP_XM(v29 + v27);
      pPos = v54;
      ++v18;
      v17 += v30;
    }
    while (v56 != v18);
    v15 = v54->Y;
    OfsX = v51;
  }
  X = pPos->X;
  v32 = CMP_YM(4);
  if (v56 >= 1)
  {
    Y = v15 - OfsY - v32;
    v36 = 0;
    v37 = X + OfsX;
    v38 = pW->m_Items;
    do
    {
      v39 = v54->Z;
      v41 = v38[v36];
      v44 = pStr->m_Items[v36];
      fclDrawStrCenterTarget(v37, Y, v39, v41, v34, v35, v44, OtNo);
      v47 = pOfsH->m_Items[v36];
      v49 = v38[v36];
      ++v36;
      v37 += CMP_XM(v49 + v47);
    }
    while (v56 != v36);
  }
}

// 0x1198e60
void fclDrawParts(s32 X, s32 Y, u32 Z, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry, u32 OtNo) {
  fclSprite_t_o *v18;
  struct fclSpriteBase_t_o *Base;
  s32 W;
  s32 H;
  s32 v25;
  s32 v26;
  u8 Flag;

  v18 = Allocate(fclSprite_t);
  fclSprite_t___ctor(v18);
  fclCreatePartsSprite(Z, v18, TblNo, PartsNo, pTexHandle, pSprTblArry);
  Base = v18->Base;
  W = Base->W;
  H = Base->H;
  v25 = v18->X;
  v26 = v18->Y;
  Flag = v18->Flag;
  fclDrawSpriteCore(v25 + X, v26 + Y, W, H, pCol, v18, Flag, 0, 1u, OtNo);
}

// 0x1198fb0
void fclDrawPartsBG(s32 X, s32 Y, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry) {
  fclSprite_t_o *v15;
  struct fclSpriteBase_t_o *Base;
  s32 W;
  s32 H;
  s32 v22;
  s32 v23;
  u8 Flag;

  v15 = Allocate(fclSprite_t);
  fclSprite_t___ctor(v15);
  fclCreatePartsSprite(0, v15, TblNo, PartsNo, pTexHandle, pSprTblArry);
  Base = v15->Base;
  W = Base->W;
  H = Base->H;
  v22 = v15->X;
  v23 = v15->Y;
  Flag = v15->Flag;
  fclDrawSpriteCore(v22 + X, v23 + Y, W, H, pCol, v15, Flag, 0, 1u, 7u);
}

// 0x11982a0
void fclDrawPartsEx(s32 X, s32 Y, u32 Z, s32 RateW, s32 RateH, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry, u32 OtNo) {
  fclSprite_t_o *v18;
  struct System_UInt16_array *UV;
  il2cpp_array_size_t max_length;
  u64 v24;
  struct System_UInt16_array *v26;
  u32 v27;
  s64 v30;
  struct fclSpriteBase_t_o *Base;
  u64 v33;
  struct fclSpriteBase_t_o *v34;
  u64 v35;
  struct fclSpriteBase_t_o *v36;
  struct System_UInt16_array *v37;
  u32 v38;
  struct fclSpriteBase_t_o *v40;
  struct System_UInt16_array *v41;
  u32 v42;
  struct fclSpriteBase_t_o *v45;
  s32 W;
  s32 H;
  s32 v48;
  s32 v49;
  u8 Flag;

  v18 = Allocate(fclSprite_t);
  fclSprite_t___ctor(v18);
  fclCreatePartsSprite(Z, v18, TblNo, PartsNo, pTexHandle, pSprTblArry);
  UV = v18->Base->UV;
  max_length = UV->max_length;
  v24 = 274877907LL * (v18->Base->UV->m_Items[2] - v18->Base->UV->m_Items[0]) * RateW;
  UV->m_Items[2] = UV->m_Items[0] + (v24 >> 63) + (SHIDWORD(v24) >> 6);
  v26 = v18->Base->UV;
  v27 = v26->max_length;
  v30 = 274877907LL * (v18->Base->UV->m_Items[3] - v18->Base->UV->m_Items[1]) * RateH;
  v26->m_Items[3] = v26->m_Items[1] + (v30 >> 38) + (v30 >> 63);
  Base = v18->Base;
  v33 = 274877907LL * Base->W * RateW;
  Base->W = (v33 >> 38) + (v33 >> 63);
  v34 = v18->Base;
  v35 = 274877907LL * v34->H * RateH;
  v34->H = (v35 >> 38) + (v35 >> 63);
  if (RateW)
  {
    v36 = v18->Base;
    if (v36->W <= 3u)
    {
      v36->W = 4;
      v37 = v18->Base->UV;
      v38 = v37->max_length;
      v37->m_Items[2] = v37->m_Items[0] + 64;
    }
  }
  if (RateH)
  {
    v40 = v18->Base;
    if (v40->H <= 3u)
    {
      v40->H = 4;
      v41 = v18->Base->UV;
      v42 = v41->max_length;
      v41->m_Items[3] = v41->m_Items[1] + 64;
    }
  }
  v45 = v18->Base;
  W = v45->W;
  H = v45->H;
  v48 = v18->X;
  v49 = v18->Y;
  Flag = v18->Flag;
  fclDrawSpriteCore(v48 + X, v49 + Y, W, H, pCol, v18, Flag, 0, 1u, OtNo);
}

// 0x11986b0
void fclDrawPartsEx2(s32 X, s32 Y, u32 Z, u8 AlphaFlag, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry, u32 OtNo) {
  fclSprite_t_o *v18;
  struct fclSpriteBase_t_o *Base;
  s32 W;
  s32 H;
  s32 v25;
  s32 v26;
  u8 Flag;

  v18 = Allocate(fclSprite_t);
  fclSprite_t___ctor(v18);
  fclCreatePartsSprite(Z, v18, TblNo, PartsNo, pTexHandle, pSprTblArry);
  Base = v18->Base;
  W = Base->W;
  H = Base->H;
  v25 = v18->X;
  v26 = v18->Y;
  Flag = v18->Flag;
  fclDrawSpriteCore(v25 + X, v26 + Y, W, H, pCol, v18, Flag, AlphaFlag, 1u, OtNo);
}

// 0x1198800
void fclDrawPartsEx3(s32 X, s32 Y, u32 Z, u8 FilterFlag, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry, u32 OtNo) {
  fclSprite_t_o *v18;
  struct fclSpriteBase_t_o *Base;
  s32 W;
  s32 H;
  s32 v25;
  s32 v26;
  u8 Flag;

  v18 = Allocate(fclSprite_t);
  fclSprite_t___ctor(v18);
  fclCreatePartsSprite(Z, v18, TblNo, PartsNo, pTexHandle, pSprTblArry);
  Base = v18->Base;
  W = Base->W;
  H = Base->H;
  v25 = v18->X;
  v26 = v18->Y;
  Flag = v18->Flag;
  fclDrawSpriteCore(v25 + X, v26 + Y, W, H, pCol, v18, Flag, 0, FilterFlag, OtNo);
}

// 0x1198950
void fclDrawPartsEx4(s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry, u32 OtNo) {
  fclSprite_t_o *v18;
  s32 v22;
  s32 v23;
  u8 Flag;

  v18 = Allocate(fclSprite_t);
  fclSprite_t___ctor(v18);
  fclCreatePartsSprite(Z, v18, TblNo, PartsNo, pTexHandle, pSprTblArry);
  v22 = v18->X;
  v23 = v18->Y;
  Flag = v18->Flag;
  fclDrawSpriteCore(v22 + X, v23 + Y, W, H, pCol, v18, Flag, 0, 1u, OtNo);
}

// 0x1198a90
void fclDrawPartsEx5(s32 X, s32 Y, u32 Z, s32 W, s32 H, u8 AlphaFlag, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry, u32 OtNo) {
  fclSprite_t_o *v18;
  s32 v22;
  s32 v23;
  u8 Flag;

  v18 = Allocate(fclSprite_t);
  fclSprite_t___ctor(v18);
  fclCreatePartsSprite(Z, v18, TblNo, PartsNo, pTexHandle, pSprTblArry);
  v22 = v18->X;
  v23 = v18->Y;
  Flag = v18->Flag;
  fclDrawSpriteCore(v22 + X, v23 + Y, W, H, pCol, v18, Flag, AlphaFlag, 1u, OtNo);
}

// 0x1198bd0
void fclDrawPartsEx6(s32 X, s32 Y, u32 Z, s32 W, s32 H, u8 FilterFlag, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry, u32 OtNo) {
  fclSprite_t_o *v18;
  s32 v22;
  s32 v23;
  u8 Flag;

  v18 = Allocate(fclSprite_t);
  fclSprite_t___ctor(v18);
  fclCreatePartsSprite(Z, v18, TblNo, PartsNo, pTexHandle, pSprTblArry);
  v22 = v18->X;
  v23 = v18->Y;
  Flag = v18->Flag;
  fclDrawSpriteCore(v22 + X, v23 + Y, W, H, pCol, v18, Flag, 0, FilterFlag, OtNo);
}

// 0x1198d10
void fclDrawPartsEx7(s32 X, s32 Y, u32 Z, s32 W, s32 H, f32 Angle, u8 AlphaFlag, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t **pSprTblArry, u32 OtNo) {
  fclSprite_t_o *v20;
  s32 v24;
  s32 v25;
  u8 Flag;

  v20 = Allocate(fclSprite_t);
  fclSprite_t___ctor(v20);
  fclCreatePartsSprite(Z, v20, TblNo, PartsNo, pTexHandle, pSprTblArry);
  v24 = v20->X;
  v25 = v20->Y;
  Flag = v20->Flag;
  fclDrawSpriteAngleCore(v24 + X, v25 + Y, W, H, Angle, pCol, v20, Flag, AlphaFlag, 1u, OtNo);
}

// 0x1199100
void fclDrawSelectCursor(u32 Z, u32 Col, cmpCursorInfo_t *pCI, u32 OtNo) {
  s32 X;
  s32 v9;
  s32 v10;
  struct cmpCursorSize_t_o *CursorSize;
  s32 W_low;
  s32 v14;
  s32 H_low;

  X = pCI->CursorSize->X;
  v9 = CMP_XM(X);
  v10 = CMP_YM(pCI->CursorSize->Y);
  CursorSize = pCI->CursorSize;
  W_low = LOWORD(CursorSize->W);
  v14 = v10;
  H_low = LOWORD(CursorSize->H);
  cmpDrawCommandCursor(v9, v14, Z, W_low, H_low, 0x80808080, 256, 0, pCI, 0, OtNo);
}

// 0x1197ef0
void fclDrawSpriteAngleCore(s32 X, s32 Y, s32 W, s32 H, f32 Angle, u32 pCol, fclSprite_t *pSprite, u8 FlipFlag, u8 AlphaFlag, u8 FilterFlag, u32 OtNo) {
  ;
}

// 0x1199360
void fclDrawStrCenterTarget(s32 X, s32 Y, u32 Z, u16 W, u16 H, u32 Col, s8 pStr, u32 OtNo) {
  _FRQ_o *SmallCaptionFontFRQ;
  s32 v18;
  s32 v19;

  SmallCaptionFontFRQ = frwGetSmallCaptionFontFRQ(X, Y, Z, 0xDEFFA180, pStr, 0);
  v18 = FR_STR_WIDTH(SmallCaptionFontFRQ);
  v19 = CMP_XM((W - v18) >> 1, 0);
  frSetDrawPosition(SmallCaptionFontFRQ, v19 + X, Y);
  frDrawFontEx2(SmallCaptionFontFRQ, 1, OtNo);
  frDestroyFontRequestAfter(SmallCaptionFontFRQ);
}

// 0x1199f10
void fclDrawTotalMoney(fclPanelPos_t *pPos, u32 Color, u32 OtNo) {
  System_UInt32_array *v7;
  u32 max_length;
  System_UInt32_array *v10;
  s32 v12;
  s32 Y;
  s32 v14;
  s32 v16;
  u32 Z;
  sdfTexHandle_t_array *cmpTex;
  fclSprTblArry_t_array *pSprTblArry;
  s32 v22;
  s32 v23;
  s32 v24;
  s32 v25;
  s32 v26;
  s32 v27;
  s32 v28;
  s32 v29;
  s32 v30;
  s32 v31;
  u64 *v34;
  System_String_o *v35;
  s32 v36;
  System_String_o *v37;
  s32 v38;
  s32 v39;
  s32 v40;
  s32 v41;
  _FRQ_o *NumFontFRQ_20604240;
  s32 X;
  u8 v51;
  u32 v52;
  s32 maka;

  v7 = NewSpecific(uint, 4u);
  max_length = v7->max_length;
  v10 = v7;
  v7->m_Items[0] = Color;
  v7->m_Items[1] = Color;
  v7->m_Items[2] = Color;
  v52 = OtNo;
  v7->m_Items[3] = Color;
  X = pPos->X;
  v12 = CMP_XM(269);
  Y = pPos->Y;
  v14 = v12;
  v16 = CMP_YM(15);
  Z = pPos->Z;
  v51 = Color;
  pSprTblArry = cmpSprTblArry;
  fclDrawPartsEx3(v14 + X, v16 + Y, 16 * Z, 1u, v10, 0xAu, 0, cmpTex, pSprTblArry, v52);
  v22 = pPos->X;
  v23 = CMP_XM(269);
  v24 = pPos->Y;
  v25 = v23;
  v26 = CMP_YM(15);
  fclDrawPartsEx3(v25 + v22, v26 + v24, 16 * pPos->Z, 1u, v10, 0xAu, 0xCu, cmpTex, cmpSprTblArry, v52);
  v27 = pPos->X;
  v28 = CMP_XM(484);
  v29 = pPos->Y;
  v30 = v28;
  v31 = CMP_YM(22);
  fclDrawPartsEx3(v30 + v27, v31 + v29, 16 * pPos->Z, 1u, v10, 0xAu, 1u, cmpTex, cmpSprTblArry, v52);
  maka = DDS3_GBWK->maka;
  v34 = sub_8D3950(s32, &maka);
  v35 = Format("{0,7}", v34, 0);
  v36 = pPos->X;
  v37 = v35;
  v38 = CMP_XM(388);
  v39 = pPos->X;
  v40 = v38;
  v41 = CMP_YM(22);
  NumFontFRQ_20604240 = frwGetNumFontFRQ_20604240(v40 + v36, v41 + v39, pPos->Z, v51 | 0xA09DC300, v37, 0);
  frDrawFontEx2(NumFontFRQ_20604240, 1, v52);
  frDestroyFontRequestAfter(NumFontFRQ_20604240);
}

// 0x1197f00
void fclDrawUnderLine(s32 X, s32 Y, u32 Z, u32 W, u32 H, u32 Col, u32 Mode, u32 OtNo) {
  if (Mode)
  {
    Col = fclGetBlendColor(Col, Col, 0x80u);
  }
  cmpDrawBoxF(X, Y, Z, W, H, Col, OtNo);
}
