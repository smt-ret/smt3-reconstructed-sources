#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct Sprite3D_t Sprite3D_t;
typedef struct _FRQ _FRQ;
typedef struct dbgConsCtl_tag dbgConsCtl_tag;
typedef struct fldDraw_DrawText fldDraw_DrawText;
typedef struct sdfDevPrintCB_t sdfDevPrintCB_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct fldDraw_DrawText {
    char *DrawTxt;
    s32 color;
};

static void *FldDbgMenuObj;
static void *FldDbgMenuList[22];
static void *FldDbgMenuTxt[22];
static void *FldDrawText[22];
static void *Line3D;
static u8 GLOW1_TMX[640];
static sdfMat_t *ooyTest_mat;
static sdfMat_t *ooyTest_mat2;
static sdfTexHandle_t *ooyTest_texHandle;
static s32 ooyTest_OT_Offset;
static s32 fldDrawInit_fast;
static sdfVector4_t ooyline3d_points[2];
static u32 ooyline3d_colors[2];
static u32 ooyTest_TriangleFaceIndex[16];
static u32 ooyTest_TriangleFaceIndexR[2];
static void *gFld_zbuffImage;

void Draw(s32 x, s32 y, _FRQ *frq, s32 colno);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
char *RepColTag(char *txt, void **LegacyParamArray);
_FRQ *frDestroyFontRequestAfter(_FRQ *pFRQ);
s32 frDrawFont(_FRQ *pFRQ);
_FRQ *frwGetSmallFontFRQ(s32 X, s32 Y, s32 Pri, u32 Color, u8 **pStr, _FRQ *pFRQ);
_FRQ *frwGetSmallFontFRQ_20602048(s32 X, s32 Y, s32 Pri, u32 Col, char *pStr, _FRQ *pFRQ, s32 ftype);
void *sdfDevPrintfEx(sdfDevPrintCB_t *aCB, char *aStr, void **LegacyParamArray);
void sdfDevSetPrintCB(sdfDevPrintCB_t *aCB, s32 aX, s32 aY, u32 aZ, s32 aAttr);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);

// 0x1038c90
void DrwSprite2D(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, s32 rgba, sdfTexHandle_t *th) {
    Draw(0, 0, 0, 0);
}

// 0x1038e70
void DrwSprite2DC(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, s32 rgba0, s32 rgba1, s32 rgba2, s32 rgba3, sdfTexHandle_t *th) {
  ;
}

// 0x1038e80
void DrwSprite2DF(f32 x, f32 y, f32 w, f32 h, s32 u, s32 v, s32 uw, s32 vh, s32 rgba, sdfTexHandle_t *th) {
}

// 0x1038d80
void DrwSprite2D_17010048(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, u32 rgba, sdfTexHandle_t *th) {
    Draw(0, 0, 0, 0);
}

// 0x10394b0
sdfColor_t GetRgbColor(u32 color) {
    return (sdfColor_t){0};
}

// 0x1039770
void LF(dbgConsCtl_tag *cons) {
  cons->cy += 96;
}

// 0x1038f90
void aDrawBoxF(s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b, s32 a) {
  ;
}

// 0x1038fa0
void aDrawBoxFZ(s32 x, s32 y, s32 w, s32 h, s32 z, s32 r, s32 g, s32 b, s32 a) {
  ;
}

// 0x1038fb0
void aDrawBoxF_Direct(s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b, s32 a) {
  ;
}

// 0x1038fd0
void aDrawBoxG(s32 x, s32 y, s32 w, s32 h, s32 r0, s32 g0, s32 b0, s32 a0, s32 r1, s32 g1, s32 b1, s32 a1, s32 r2, s32 g2, s32 b2, s32 a2, s32 r3, s32 g3, s32 b3, s32 a3) {
  ;
}

// 0x1038fe0
void aDrawBoxGF(f32 x, f32 y, f32 w, f32 h, s32 r0, s32 g0, s32 b0, s32 a0, s32 r1, s32 g1, s32 b1, s32 a1, s32 r2, s32 g2, s32 b2, s32 a2, s32 r3, s32 g3, s32 b3, s32 a3) {
  ;
}

// 0x1038ff0
void aDrawBoxZF(s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b, s32 a, s32 z) {
  ;
}

// 0x1038f80
void aDrawLineDirect(s32 x0, s32 y0, s32 x1, s32 y1, s32 r, s32 g, s32 b) {
  ;
}

// 0x1038f70
void aDrawLineStripPrim(s32 x0, s32 y0, s32 x1, s32 y1, s32 r, s32 g, s32 b) {
  ;
}

// 0x1038fc0
void aDrawTriG(s32 x0, s32 y0, s32 x1, s32 y1, s32 x2, s32 y2, s32 r0, s32 g0, s32 b0, s32 a0, s32 r1, s32 g1, s32 b1, s32 a1, s32 r2, s32 g2, s32 b2, s32 a2) {
  ;
}

// 0x10387e0
void deleteFldMenuObj(void) {
  UnityEngine_Object_o *FldDbgMenuObj;
  s64 i;
  u64 v7;
  struct System_Collections_Generic_List_fldDraw_DrawText__array *FldDrawText;
  struct System_Collections_Generic_List_fldDraw_DrawText__array *v11;

  Destroy_27360000(FldDbgMenuObj);
  if (FldDrawText)
  {
    for (i = 4; i != 26; ++i)
    {
      v7 = i - 4;
      if (*(&FldDrawText->obj.klass + i))
      {
        v11 = FldDrawText;
        _Clear(
          *(&v11->obj.klass + i));
      }
    }
  }
  FldDrawText = 0;
  FldDbgMenuTxt = 0;
  FldDbgMenuList = 0;
  FldDbgMenuObj = 0;
}

// 0x1038980
void deleteFldMenuSub(s32 second) {
  struct UnityEngine_GameObject_array *FldDbgMenuList;
  s64 v5;
  UnityEngine_Object_o *v7;
  struct UnityEngine_GameObject_array *v10;
  struct System_Collections_Generic_List_fldDraw_DrawText__array *FldDrawText;
  struct System_Collections_Generic_List_fldDraw_DrawText__array *v16;
  struct TMPro_TextMeshProUGUI_array *FldDbgMenuTxt;
  UnityEngine_Object_o *v21;
  struct TMPro_TextMeshProUGUI_array *v24;

  if ((second - 2) <= 0x14)
  {
    else
    {
      if (!FldDbgMenuList)
        return;
    }
    v5 = second - 1LL;
    v7 = FldDbgMenuList->m_Items[v5];
    if (op_Inequality(v7, 0, 0))
    {
      v10 = FldDbgMenuList;
      SetActive(v10->m_Items[v5], 0, 0);
    }
    if (FldDrawText->m_Items[v5])
    {
      v16 = FldDrawText;
      _Clear(v16->m_Items[v5]);
    }
    v21 = FldDbgMenuTxt->m_Items[v5];
    if (op_Inequality(v21, 0, 0))
    {
      v24 = FldDbgMenuTxt;
      set_text(v24->m_Items[v5], StringLiteral_416);
    }
  }
}

// 0x1039000
void drawSprite3D(sdfTexHandle_t *th, Sprite3D_t *spr3d) {
  ;
}

// 0x10397a0
void fldDbgPrint2D(s32 x, s32 y, char **str) {
  ;
}

// 0x10397b0
void fldDbgPrint2DC(s32 x, s32 y, s32 col, char **str) {
  ;
}

// 0x1039790
void fldDbgPrint3D(f32 x, f32 y, f32 z, s32 num) {
  ;
}

// 0x10397c0
void fldDbgPrintNum2D(s32 x, s32 y, s32 num) {
  ;
}

// 0x10397d0
void fldDbgPrintNum2DH(s32 x, s32 y, s32 num) {
  ;
}

// 0x10397e0
void fldDbgPrintStr2D(s32 x, s32 y, char *str) {
    sdfDevSetPrintCB(0, 0, 0, 0, 0);
    sdfDevPrintfEx(0, 0, 0);
    sdfDrawTagLink(0, 0);
}

// 0x1039990
void fldDbgPrintStr2DC(s32 x, s32 y, s32 col, char *str, s32 second) {
    LoadPrefab_16624656(0, 0, 0, 0);
    RepColTag(0, 0);
}

// 0x103a340
void fldDbgPrintStr2DCF(f32 x, f32 y, s32 col, char **str) {
  ;
}

// 0x10395b0
void fldDraw2DBar(s32 x, s32 y, s32 w, s32 h) {
  ;
}

// 0x1039580
void fldDrawBokasi(void) {
  ;
}

// 0x1038c80
sdfGrOt_t *fldDrawGetOt(void) {
  return 0;
}

// 0x1038c70
void fldDrawInit(void) {
  ;
}

// 0x103a350
void fldDrawMaruKage(f32 x, f32 y, f32 z, f32 r, s32 a) {
  ;
}

// 0x1039590
void fldDrawPos(sdfVector4_t pos) {
  ;
}

// 0x10395a0
void fldDrawPosCol(sdfVector4_t pos, s32 rgba) {
  ;
}

// 0x1039570
void fldDrawTexPoly4(f32 x0, f32 y0, f32 z0, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 x3, f32 y3, f32 z3, f32 s0, f32 t0, f32 s1, f32 t1, u32 col0, u32 col1, u32 col2, u32 col3, sdfTexHandle_t *th) {
  ;
}

// 0x10395c0
void fldDrwZAlloc(void) {
  ;
}

// 0x10395d0
void fldDrwZFree(void) {
  ;
}

// 0x10395f0
void fldDrwZLoad(void) {
  ;
}

// 0x10395e0
void fldDrwZSave(void) {
  ;
}

// 0x1039600
void fldKanjiDraw(s32 x, s32 y, u32 rgba, u8 **moji) {
  _FRQ_o *SmallFontFRQ;

  SmallFontFRQ = frwGetSmallFontFRQ(16 * x, 16 * y, 0, rgba, moji, 0);
  frDrawFont(SmallFontFRQ);
  frDestroyFontRequestAfter(SmallFontFRQ);
}

// 0x10396c0
void fldKanjiDraw_17012416(s32 x, s32 y, u32 rgba, char *moji, s32 ftype) {
  _FRQ_o *SmallFontFRQ_20602048;

  SmallFontFRQ_20602048 = frwGetSmallFontFRQ_20602048(16 * x, 16 * y, 0, rgba, moji, 0, ftype);
  frDestroyFontRequestAfter(SmallFontFRQ_20602048);
}

// 0x1038e90
void fldPoint3To2(f32 x3, f32 y3, f32 z3, f32 *x2, f32 *y2) {
  ;
}

// 0x1038ea0
void fldPoint3To2H(f32 x3, f32 y3, f32 z3, f32 *x2, f32 *y2) {
  ;
}

// 0x1038eb0
void fldPoint3To2_A(void) {
  ;
}

// 0x1038ec0
void fldPoint3To2_B(f32 x3, f32 y3, f32 z3, f32 *x2, f32 *y2) {
  ;
}

// 0x1039780
void initDrawTag(dbgConsCtl_tag *cons) {
  ;
}

// 0x1039030
void ooyTestLine3D(f32 x0, f32 y0, f32 z0, u32 col0, f32 x1, f32 y1, f32 z1, u32 col1) {
  ;
}

// 0x1039040
void ooyTestLine3DForUnity(void **parent, char *pName, char *cName, u32 col, s32 size, sdfVector3_t **pos) {
    LoadPrefab_16624656(0, 0, 0, 0);
}

// 0x1039550
void ooyTestPoly3(f32 x0, f32 y0, f32 z0, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, u32 col0, u32 col1, u32 col2) {
  ;
}

// 0x1039560
void ooyTestPoly4(f32 x0, f32 y0, f32 z0, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 x3, f32 y3, f32 z3, u32 col0, u32 col1, u32 col2, u32 col3) {
  ;
}

// 0x1039020
void ooyTestRGBMaskOff(void) {
  ;
}

// 0x1039010
void ooyTestRGBMaskOn(void) {
  ;
}

// 0x1038f60
void rsetAlpha(s32 mode) {
  ;
}

// 0x1038ed0
void rsetOtOfs(s32 otofs) {
  ooyTest_OT_Offset = otofs;
}

// 0x1038f50
void rsetTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst) {
  ;
}

// 0x1038f40
void rsetTexa(s32 ta0, s32 aem, s32 ta1) {
  ;
}
