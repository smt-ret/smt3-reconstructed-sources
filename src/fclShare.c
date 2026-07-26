#include "types.h"

typedef struct _FRQ _FRQ;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct debug_tag debug_tag;
typedef struct fclPanel_t fclPanel_t;
typedef struct fclSprTblArry_t fclSprTblArry_t;
typedef struct fclSpriteBase_t fclSpriteBase_t;
typedef struct fclSprite_t fclSprite_t;
typedef struct lstListWindow_t lstListWindow_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfFileCmdCallback_t sdfFileCmdCallback_t;
typedef struct sdfFileCmdHandle_t sdfFileCmdHandle_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfModelOt_t sdfModelOt_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 UV;
static s32 XYZ2;
static s32 XYZF2;
static s32 RGBAQ;
static s32 FCL_RAND;
static s32 SHOPSN10_BGM00;
static s32 P2SDREQ_ITEMGET;
static s32 SHOPSN10_SE00;
static s32 SHOPSND2_BGM00;
static s32 SHOPSND2_SE00;
static s32 SHOPSND2_SE01;
static s32 SHOPSND2_SE02;
static s32 FCL_SCREEN_WIDTH;
static s32 FCL_SCREEN_HEIGHT;
static s32 FCL_OFS_X;
static s32 FCL_OFS_Y;
static s32 FCL_RAG_CAPCOL_ITEM;
static s32 FCL_RAG_ITEM_MAX;
static s32 FCL_RAG_WINCOL_HELP;
static s32 FCL_RAG_ULINECOL_MAIN;
static s32 FCL_PANELHELP_GRAD_COL;
static s32 FCL_PANELDEF_GRAD_COL;
static s32 FCL_RAG_WINCOL_SYOJI;
static s32 FCL_RAG_CAPCOL_HELP;
static s32 FCL_RAG_CAPCOL_EXCHG;
static s32 FCL_RAG_ULINECOL_EXCHG;
static s32 dds3Ot[1];
static u32 CMB_LOCAL_OT;
static u32 CMB_UPINFO_COL;
static u32 CMP_CMD_DEFAULT_OT;
static u32 CMB_LOCAL_Z;
static u32 FCL_DEFWIN_COL;
static u32 FCL_DEFAULT_Z;
static u32 FCL_DEFAULT_OT;
static u32 FCL_DEVSEL_MAIN_LINECOL;
static u32 FCL_RECOVER_CAPCOL_MAIN;
static u32 FCL_RECOVER_ULINECOL_MAIN;
static u32 CMP_PE_NORMAL;
static u8 gCommandFlag[4];
static fclSprTblArry_t *fclRagSprTblArry;
static sdfModelOt_t *dds3ModelOt[11];

bool DDS3_PADCHECK_TRIG(s32 id);
void fclCalcRotPos(s32 pBufX, s32 pBufY, s32 DistX, s32 DistY, s32 CenterX, s32 CenterY, f32 Angle);
void fclSetSprite(fclSprite_t *pSprite, s32 Xsize, s32 Ysize, s32 Z, s32 U1, s32 V1, s32 U2, s32 V2, u32 Col, sdfTexHandle_t *TexHandle);
void fclSetSpriteColor(fclSprite_t *pSprite, u32 Col);
s32 sdf2DGetPrimPacketSize(s32 aNumOfRegs, s32 aNumOfPrim);
void *sdf2DGetPrimPtr(void *aPacketPtr);
void *sdf2DLinkTexPacket(sdfDrawTag_t *aTag, sdfTexHandle_t *aTexHndl, s32 aCtx);
void *sdf2DMakePrimPacketHeader_24943632(void *aPacketPtr, s32 aPrimReg, s32 aNumOfRegs, u64 aGifRegs, s32 aNumOfPrim);
f32 sdfCos(f32 aRadius);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);
sdfFileCmdHandle_t *sdfFileCmdReadFile(char *aFileName, void *aBuffer, s32 aLength, sdfFileCmdCallback_t *aCallback, void *aUserData);
void *sdfGrAllocPacketBuff(s32 aSize);
f32 sdfSin(f32 aRadius);
sdfTexHandle_t *sdfTexSet(void *aTex);
void sdfTexSetFilter(sdfTexHandle_t *aHandle, s32 aMagMode, s32 aMinMode);

// 0x199c1b0
s32 CopyFrom(void *a) {
  return 0;
}

// 0x199c0a0
s32 FCL_ARRY_SIZE(s32 **ptr) {
  s32 v4;

  v4 = ptr->m_Items[0];
  return *il2cp::SizeOf(ptr, s32) / v4;
}

// 0x199c140
s32 FCL_BLEND_ALPHA(s64 src, s64 dst) {
  return ((dst * src) >> 7) | src & 0xFFFFFF00;
}

// 0x199c160
s32 FCL_MAKE_COL(s32 r, s32 g, s32 b, u32 a) {
  return (g << 16) | (r << 24) | (b << 8) | a;
}

// 0x199c2f0
s8 SDF_ARRAYCOUNT(s8 **n) {
  s32 v4;

  v4 = n->m_Items[0];
  return *il2cp::SizeOf(n, sbyte) / v4;
}

// 0x199c2a0
f32 SDF_DEGtoRAD(f32 n) {
  return n * 0.017453;
}

// 0x199c040
s32 SDF_GIFTAG_REGS3(s32 a, s32 b, s32 c) {
  return 0;
}

// 0x199c050
s32 SDF_GIFTAG_REGS5(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4) {
  return 0;
}

// 0x199c030
s32 SDF_GIF_SET_RGBA(s32 pkt, s32 r, s32 g, s32 b, s32 a) {
  return 0;
}

// 0x199c020
s32 SDF_GIF_SET_UV(s32 pkt, s32 u, s32 v) {
  return 0;
}

// 0x199c010
s32 SDF_GIF_SET_XYZ2(s32 a, s32 b, s32 c, s32 d, s32 e) {
  return 0;
}

// 0x199c060
s32 SDF_GIF_SET_XYZF2(s32 pkt, s32 x, s32 y, s32 z, s32 f, s32 adc) {
  return 0;
}

// 0x199c120
s32 SDF_GS_SET_ALPHA(s32 a, s32 b, s32 c, s32 d, s32 fix) {
  return a | (4 * b) | (16 * c) | fix | (d << 6);
}

// 0x199c070
s32 SDF_GS_SET_PRIM(s32 prim, s32 iip, s32 tme, s32 fge, s32 abe, s32 aa1, s32 fst, s32 ctxt, s32 fix) {
  return prim | (8 * iip) | (16 * tme) | (32 * fge) | (abe << 6) | (aa1 << 7) | (fst << 8) | (ctxt << 9) | (fix << 10);
}

// 0x199c260
u32 dds3GetProcessStat(dds3ProcessID_t **id) {
  return 0;
}

// 0x199c3b0
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p) {
    return 0;
}

// 0x199d180
void fclCalcRotPos(s32 pBufX, s32 pBufY, s32 DistX, s32 DistY, s32 CenterX, s32 CenterY, f32 Angle) {
    sdfCos(0);
    sdfSin(0);
}

// 0x199c240
s32 fclClearPanelTimer(void *a) {
  return 0;
}

// 0x199c5b0
void fclDrawPanel(fclPanel_t *pPanel, u32 OtNo) {
  ;
}

// 0x199c5c0
void fclDrawPanelGrad(fclPanel_t *pPanel, u32 Color, u32 Type, u32 OtNo) {
  ;
}

// 0x199c640
void fclDrawParts(s32 X, s32 Y, u32 Z, u32 **pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t **pTexHandle, fclSprTblArry_t *pSprTblArry, u32 OtNo) {
  ;
}

// 0x199c660
void fclDrawParts_26855008(s32 X, s32 Y, u32 Z, u32 pCol, u8 TblNo, u16 PartsNo, sdfTexHandle_t *pTexHandle, fclSprTblArry_t *pSprTblArry, u32 OtNo) {
  ;
}

// 0x199cf30
void fclDrawSprite(s32 X, s32 Y, fclSprite_t *pSprite) {
  if ((byte_3F5ABF1 & 1) == 0)
    return;
}

// 0x199d310
void fclDrawSpriteAngleCore(s32 X, s32 Y, s32 W, s32 H, f32 Angle, u32 **pCol, fclSprite_t *pSprite, u8 FlipFlag, u8 AlphaFlag, u8 FilterFlag, u32 OtNo) {
    sdfTexSetFilter(0, 0, 0);
    sdf2DGetPrimPacketSize(0, 0);
    sdfGrAllocPacketBuff(0);
    sdf2DMakePrimPacketHeader_24943632(0, 0, 0, 0, 0);
    sdf2DGetPrimPtr(0);
    fclCalcRotPos(0, 0, 0, 0, 0, 0, 0);
    sdf2DLinkTexPacket(0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x199d170
void fclDrawSpriteCore(s32 X, s32 Y, s32 W, s32 H, u32 **pCol, fclSprite_t *pSprite, u8 FlipFlag, u8 AlphaFlag, u8 FilterFlag, u32 OtNo) {
  ;
}

// 0x199d040
void fclDrawSpriteEx(s32 X, s32 Y, s32 W, s32 H, fclSprite_t *pSprite, u32 OtNo) {
  if ((byte_3F5ABF1 & 1) == 0)
    return;
}

// 0x199d100
void fclDrawSpriteEx2(s32 X, s32 Y, s32 W, s32 H, u32 **pCol, fclSprite_t *pSprite, u8 FlipFlag, u32 OtNo) {

}

// 0x199c700
s32 fclFileCallback(sdfFileCmdHandle_t *aHandle, s32 aCause, void *aBuffer, s32 aLength, void *aUserData) {
  return 0;
}

// 0x199c710
void fclFileLoad(char **pFileName, void **pBuf) {
    sdfFileCmdReadFile(0, 0, 0, 0, 0);
}

// 0x199c890
sdfTexHandle_t *fclLoadTexture(char *pFileName) {
  u64 *v2;
  u64 *v3;
  u64 *v4;

  v2 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v2);
  v3 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v3);
  v4 = Allocate(object);
  _ctor(v4, 0);
  return sdfTexSet(v4);
}

// 0x199cce0
void fclSetSprite(fclSprite_t *pSprite, s32 Xsize, s32 Ysize, s32 Z, s32 U1, s32 V1, s32 U2, s32 V2, u32 Col, sdfTexHandle_t *TexHandle) {
  s16 v11;
  s16 v12;
  s16 v13;
  s16 v14;
  u16 v16;
  u16 v17;
  struct fclSpriteBase_t_o *Base;
  u16 v20;
  struct System_UInt16_array *UV;
  struct System_UInt16_array *v23;
  u16 v24;
  struct System_UInt16_array *v26;
  u16 v27;
  struct System_UInt16_array *v29;
  u16 v30;

  v11 = V2;
  v12 = U2;
  v13 = V1;
  v14 = U1;
  v16 = Ysize;
  v17 = Xsize;
  Base = pSprite->Base;
  pSprite->TexHandle = TexHandle;
  *&pSprite->X = 0;
  pSprite->Z = Z;
  v20 = 16 * v14;
  Base->W = v17;
  pSprite->Base->H = v16;
  UV = pSprite->Base->UV;
  UV->m_Items[0] = v20;
  v23 = pSprite->Base->UV;
  v24 = 16 * v13;
  v23->m_Items[1] = v24;
  v26 = pSprite->Base->UV;
  v27 = 16 * v12;
  v26->m_Items[2] = v27;
  v29 = pSprite->Base->UV;
  v30 = 16 * v11;
  v29->m_Items[3] = v30;
  fclSetSpriteColor(pSprite, Col, *&Ysize);
}

// 0x199c960
void fclSetSpriteColor(fclSprite_t *pSprite, u32 Col) {
  struct System_Byte_array *v3;
  struct System_Byte_array *v5;
  struct System_Byte_array *v7;
  struct System_Byte_array *v9;

  v3 = pSprite->Col;
  v3->m_Items[0] = HIBYTE(Col);
  v5 = pSprite->Col;
  v5->m_Items[1] = BYTE2(Col);
  v7 = pSprite->Col;
  v7->m_Items[2] = BYTE1(Col);
  v9 = pSprite->Col;
  v9->m_Items[3] = Col;
}

// 0x199ca20
void fclSetSpriteEx(fclSprite_t *pSprite, fclSpriteBase_t *pSpriteBase, s32 X, s32 Y, s32 Z, u32 Col, u8 Flag, sdfTexHandle_t *TexHandle) {
  u64 *v16;
  struct fclSpriteBase_t_o *Base;
  struct System_UInt16_array *v18;
  struct System_UInt16_array *UV;
  struct System_UInt16_array *v22;
  struct System_UInt16_array *v24;
  struct System_UInt16_array *v26;
  struct System_UInt16_array *v28;
  struct System_UInt16_array *v30;
  struct System_UInt16_array *v32;

  pSprite->TexHandle = TexHandle;
  pSprite->X = 16 * X;
  pSprite->Y = 8 * Y;
  pSprite->Z = Z;
  pSprite->Flag = Flag;
  fclSetSpriteColor(pSprite, Col, *&X);
  v16 = Allocate(fclSpriteBase_t);
  fclSpriteBase_t___ctor(v16);
  Base = pSprite->Base;
  if (Base->W)
  {
    if (Base->H)
  }
  UV = Base->UV;
  Base->W = UV->m_Items[2];
  Base = pSprite->Base;
  if (!Base->H)
  {
    v18 = Base->UV;
    Base->H = v18->m_Items[3];
    Base = pSprite->Base;
  }
  v22 = Base->UV;
  v22->m_Items[2] += v22->m_Items[0];
  v24 = pSprite->Base->UV;
  v24->m_Items[3] += v24->m_Items[1];
  v26 = pSprite->Base->UV;
  v26->m_Items[0] *= 16;
  v28 = pSprite->Base->UV;
  v28->m_Items[1] *= 16;
  v30 = pSprite->Base->UV;
  v30->m_Items[2] *= 16;
  v32 = pSprite->Base->UV;
  v32->m_Items[3] *= 16;
}

// 0x199ce60
void fclSetSpriteNormal(fclSprite_t *pSprite, s32 Xsize, s32 Ysize, s32 Z, s32 U1, s32 V1, u32 Col, sdfTexHandle_t *TexHandle) {
  fclSetSprite(pSprite, Xsize, Ysize, Z, U1, V1, U1 + Xsize, V1 + Ysize, Col, TexHandle);
}

// 0x199df90
s32 fclStatusPadCheck(s32 Mode) {
  if (Mode)
  {
    else if (DDS3_PADCHECK_TRIG(2))
    {
      return 1;
    }
    return 0;
  }
  else if (DDS3_PADCHECK_TRIG(2))
  {
    return 1;
  }
  return 0;
}

// 0x199c5a0
void fclUpdatePanel(fclPanel_t *pPanel) {
  ;
}

// 0x199c250
s32 frDrawFontEx2(_FRQ *pFRQ, s8 Mode, u32 Ot) {
  return 0;
}

// 0x199c670
_FRQ *frGetCNameFRQ(s8 TargetNo, s8 Style, _FRQ *pFRQ) {
  return 0;
}

// 0x199c6d0
_FRQ *frwGetNumFontFRQ(s32 X, s32 Y, s32 Pri, u32 Color, u8 pStr, _FRQ *pFRQ) {
  return 0;
}

// 0x199c6e0
_FRQ *frwGetSmallFontFRQ2(s32 X, s32 Y, s32 Pri, u32 Color, u8 **pStr, _FRQ *pFRQ) {
  return 0;
}

// 0x199c6c0
_FRQ *frwGetSmallNumFontFRQ(s32 X, s32 Y, s32 Pri, u32 Color, u8 pStr, _FRQ *pFRQ) {
  return 0;
}

// 0x199c430
void itfMiscDrawAlphaPrim(sdfDrawTag_t *pdrawtag, s32 tp, s32 context) {
  ;
}

// 0x199c460
void itfMiscDrawSpritePrim(sdfIVector4_t *pos, sdfIVector4_t *uv, sdfIVector4_t *color, u32 z, sdfTexHandle_t *texhandle, s32 context, sdfDrawTag_t *pdrawtag) {
  ;
}

// 0x199c470
void itfMiscDrawSpritePrim2(sdfIVector4_t *pos, sdfIVector4_t *uv, sdfIVector4_t *color, u32 z, s32 context, sdfDrawTag_t *pdrawtag) {
  ;
}

// 0x199c450
void lstDrawListWindow(lstListWindow_t *pListWindow, s8 Mode, u32 OtNo) {
  ;
}

// 0x199c420
void lstDrawListWindowCursor(lstListWindow_t *pListWindow, u32 OtNo) {
  ;
}

// 0x199c480
void lstInitListWindow(s32 X, s32 Y, u32 Z, s32 W, s32 H, u32 Col, s8 Style, lstListWindow_t *pListWindow) {
  ;
}

// 0x199c410
void lstMoveCursor(lstListWindow_t *pListWindow, s8 Dir) {
  ;
}

// 0x199c440
void lstMoveCursor2(lstListWindow_t *pListWindow, s8 Dir) {
  ;
}

// 0x199c1f0
s32 memcpy(void *a, void *b, void *c) {
  return 0;
}

// 0x199c1d0
s32 memmove(void *a, void *b, s32 c) {
  return 0;
}

// 0x199c1e0
s32 memset(void *a, s32 b, void *c) {
  return 0;
}

// 0x199c210
s32 p2sdFadeIn(s32 a) {
  return 0;
}

// 0x199c200
s32 p2sdFadeOut(s32 a) {
  return 0;
}

// 0x199c220
s32 p2sdPlayBGM(s32 a) {
  return 0;
}

// 0x199c230
s32 p2sdPlaySE(s32 a) {
  return 0;
}

// 0x199c6f0
void qsort(s16 a, s32 num, u16 b, s32 c) {
  ;
}

// 0x199c5d0
void sdfChipFree(void *aPtr) {
  ;
}

// 0x199c6b0
sdfMemHandle_t *sdfDevLoadFile(char *aFilename, void *aTopPtr, s32 aSizePtr) {
  return 0;
}

// 0x199c190
s32 sdfDrawTagInit(sdfDrawTag_t *a) {
  return 0;
}

// 0x199c1a0
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b) {
  return 0;
}

// 0x199c6a0
sdfMemHandle_t *sdfMemAlloc(void *aSize) {
  return 0;
}

// 0x199c180
s32 sdfMemFree(sdfMemHandle_t *a) {
  return 0;
}

// 0x199c680
debug_tag *sdfMemLock(void *aHandle) {
  return 0;
}
