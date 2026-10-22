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
  u64 *v11;
  GfxManager_o *gfxMgr;
  u64 *v15;
  System_String_o *v16;
  s32 v17;

  v11 = Allocate(sdf2DSpriteParm_t);
  sdf2DSpriteParm_t___ctor(v11);
  if (th)
  {
    v17 = (th->klass->vtable._2_GetHashCode.methodPtr)(th, th->klass->vtable._2_GetHashCode.method);
    v15 = sub_8D3950(s32, &v17);
    v16 = Format("DrawSpr{0:X8}", v15, 0);
    Draw(gfxMgr, v16, 0x4000000u, v11, 0);
  }
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
  u64 *v11;
  GfxManager_o *gfxMgr;
  u64 *v15;
  System_String_o *v16;
  s32 v17;

  v11 = Allocate(sdf2DSpriteParm_t);
  sdf2DSpriteParm_t___ctor(v11);
  if (th)
  {
    v17 = (th->klass->vtable._2_GetHashCode.methodPtr)(th, th->klass->vtable._2_GetHashCode.method);
    v15 = sub_8D3950(s32, &v17);
    v16 = Format("DrawSpr{0:X8}", v15, 0);
    Draw(gfxMgr, v16, 0x4000000u, v11, 0);
  }
}

// 0x10394b0
sdfColor_t GetRgbColor(u32 color) {
  s64 v2;
  s64 v3;
  u32 v4;
  f32 v5;
  f32 v6;
  u32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  UnityEngine_Color_o result;

  if (HIBYTE(color))
  {
    v4 = HIWORD(color);
    v5 = HIBYTE(color);
    v6 = v5 * 0.0039216;
    LOBYTE(v7) = color;
  }
  else
  {
    v6 = 1.0;
    v7 = HIWORD(color);
    LOBYTE(v4) = color;
  }
  v17 = v2;
  v18 = v3;
  v8 = v7;
  v9 = BYTE1(color);
  v10 = v4;
  v15 = 0;
  v16 = 0;
  sub_19EC630(&v15, v8 * 0.0039216, v9 * 0.0039216, v10 * 0.0039216, v6);
  result.g = *(&v15 + 1);
  LODWORD(result.r) = v15;
  result.a = *(&v16 + 1);
  LODWORD(result.b) = v16;
  return result;
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
      set_text(v24->m_Items[v5], "");
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
  u64 *v7;
  u64 *v8;
  s32 v10;
  s32 v11;
  u32 v12;
  System_Object_array *v13;
  Il2CppObject *v15;
  sdfDrawTag_t_o *v16;

  v7 = Allocate(dbgConsCtl_tag);
  _ctor(v7, 0);
  v8 = Allocate(sdfDevPrintCB_t);
  sdfDevPrintCB_t___ctor(v8);
  v7[6] = 0xFFFFF8000007900LL;
  v7[4] = 0x600000000FFFFF7FLL;
  v7[5] = 0x700040806020LL;
  v7[2] = 0x790000007000LL;
  v7[3] = 6720;
  else
  {
    v10 = 28672;
    v11 = 30976;
    v12 = 268435328;
  }
  sdfDevSetPrintCB(v8, v10 + 16 * x, v11 + 8 * y, v12, 0);
  v13 = Empty_string_();
  v15 = sdfDevPrintfEx(v8, str, v13);
  v16 = v7[7];
  sdfDrawTagLink(v16, v15);
  *(v7 + 12) += 96;
}

// 0x1039990
void fldDbgPrintStr2DC(s32 x, s32 y, s32 col, char *str, s32 second) {
  UnityEngine_Object_o *FldDbgMenuObj;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v16;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v20;
  u64 v22;
  u64 v26;
  System_String_o *v27;
  System_String_o *v29;
  u32 *FldDbgMenuList;
  UnityEngine_Transform_o *v33;
  UnityEngine_Component_o *v34;
  s64 *gameObject;
  s64 *v36;
  struct UnityEngine_GameObject_array *v39;
  u32 *FldDbgMenuTxt;
  UnityEngine_Transform_o *v42;
  UnityEngine_Component_o *v43;
  s64 *Component_GUILayer;
  s64 *v45;
  u32 *FldDrawText;
  u64 *v48;
  struct System_Collections_Generic_List_fldDraw_DrawText__array *v50;
  struct UnityEngine_GameObject_array *v52;
  System_String_o *v55;
  s32 v56;
  struct System_Collections_Generic_List_fldDraw_DrawText__array *v58;
  s64 v59;
  s64 v61;
  struct TMPro_TextMeshProUGUI_array *v62;
  System_Collections_Generic_List_fldDraw_DrawText__o *v63;
  s64 v65;
  struct UnityEngine_GameObject_array *v66;
  UnityEngine_GameObject_o *v68;
  struct System_Collections_Generic_List_fldDraw_DrawText__array *v70;
  struct TMPro_TextMeshProUGUI_array *v71;
  TMPro_TMP_Text_o *v72;
  struct UnityEngine_GameObject_array *v73;
  s32 Count;
  s32 v76;
  s32 v77;
  s64 v78;
  struct System_String_o *v79;
  struct System_String_o *v80;
  System_String_o *v81;
  s32 i;
  System_String_o *v83;
  System_String_o *v84;
  System_String_o *v85;
  System_String_o *v86;
  System_String_o *DrawTxt;
  System_String_o *v88;
  System_String_o *v89;
  System_Object_array *v90;
  s64 *v91;
  s64 *v93;
  System_String_o *v95;
  System_String_o *str1;
  u32 item;
  s32 v101;
  TMPro_TMP_Text_o *v102;
  s32 v103;
  s32 v104;
  fldDraw_DrawText_o v105;
  fldDraw_DrawText_o v106;
  fldDraw_DrawText_o v107;

  item = col;
  str1 = str;
  v104 = 0;
  v101 = y;
  if (op_Equality(FldDbgMenuObj, 0, 0))
  {
    asset_bc = get_asset_bc();
    Prefab_16624656 = LoadPrefab_16624656(asset_bc, "debug", "debug", "FldDbgMenu");
    v16 = Find("Canvas_UI", 0);
    transform = get_transform(v16, 0);
    v20 = Instantiate_object__425520(Prefab_16624656, transform);
    FldDbgMenuObj = v20;
    FldDbgMenuList = NewSpecific(UnityEngine_GameObject, 0x16u);
    FldDbgMenuTxt = NewSpecific(TMPro_TextMeshProUGUI, 0x16u);
    FldDrawText = NewSpecific(
                                                     System_Collections_Generic_List_fldDraw_DrawText_,
                                                     0x16u);
    v22 = 0;
    do
    {
      v26 = v22 + 1;
      v104 = v22 + 1;
      v27 = sub_232A70(&v104, "D2");
      v29 = Concat_5224608("menu", v27);
      v33 = get_transform(FldDbgMenuObj, 0);
      v34 = Find(v33, v29, 0);
      gameObject = get_gameObject(v34);
      v36 = gameObject;
      *&FldDbgMenuList[2 * v22 + 8] = v36;
      v39 = FldDbgMenuList;
      v42 = get_transform(v39->m_Items[v22], 0);
      v43 = Find(v42, "text", 0);
      Component_GUILayer = GetComponent_GUILayer_(v43);
      v45 = Component_GUILayer;
      *&FldDbgMenuTxt[2 * v22 + 8] = v45;
      v48 = Allocate(System_Collections_Generic_List_fldDraw_DrawText_);
      __ctor(
        v48);
      *&FldDrawText[2 * v22 + 8] = v48;
      v50 = FldDrawText;
      _Clear(v50->m_Items[v22]);
      v52 = FldDbgMenuList;
      SetActive(v52->m_Items[v22++], 0, 0);
    }
    while (v26 != 22);
  }
  v55 = "";
  v56 = v101 / 12;
  if ((second - 2) >= 0x15)
  {
    v70 = FldDrawText;
    v63 = v70->m_Items[0];
    v71 = FldDbgMenuTxt;
    v72 = v71->m_Items[0];
    v73 = FldDbgMenuList;
    v102 = v72;
    v68 = v73->m_Items[0];
  }
  else
  {
    v58 = FldDrawText;
    v59 = second - 1LL;
    v61 = v58 + 8 * v59;
    v62 = FldDbgMenuTxt;
    v63 = *(v61 + 32);
    v65 = v62 + 8 * v59;
    v66 = FldDbgMenuList;
    v102 = *(v65 + 32);
    v68 = v66->m_Items[v59];
  }
  SetActive(v68, 1, 0);
  if (_get_Count(v63) < v56)
  {
    Count = _get_Count(v63);
    if (Count < v56)
    {
      v76 = v56 - Count;
      do
      {
        v105.DrawTxt = "";
        *&v105.color = 0;
        _Add(v63, v105);
        --v76;
      }
      while (v76);
    }
  }
  if (x >= 12)
  {
    v77 = x / 12;
    do
    {
      v55 = Concat_5224608(v55, " ");
      --v77;
    }
    while (v77);
  }
  if (_get_Count(v63) <= v56)
  {
    v80 = Concat_5224608(v55, str1);
    *&v106.color = item;
    v106.DrawTxt = v80;
    _Add(v63, v106);
  }
  else
  {
    v78 = *&_get_Item(
              v63,
              v56).color;
    v79 = Concat_5224608(v55, str1);
    *&v107.color = v78 & 0xFFFFFFFF00000000LL | item;
    v107.DrawTxt = v79;
    _set_Item(v63, v56, v107);
  }
  v81 = "";
  if (_get_Count(v63) >= 1)
  {
    for (i = 0;
          i < _get_Count(v63);
          ++i)
    {
      if (_get_Item(
             v63,
             i).color)
      {
        if (_get_Item(
               v63,
               i).color != 6)
        {
          v104 = _get_Item(
                   v63,
                   i).color
               & 0xFFFFFF;
          v85 = sub_232A70(&v104, "X");
          v84 = Concat_5271136(v81, "<color=#", v85, ">");
          goto LABEL_82;
        }
        v83 = "<color=#008080>";
      }
      else
      {
        v83 = "<color=#808080>";
      }
      v84 = Concat_5224608(v81, v83);
LABEL_82:
      v86 = v84;
      DrawTxt = _get_Item(
                  v63,
                  i).DrawTxt;
      v88 = Concat_5224608(v86, DrawTxt);
      v89 = Concat_5224608(v88, "</color>");
      v81 = Concat_5224608(v89, "\n");
    }
  }
  v103 = 0;
  v90 = NewSpecific(object, 1u);
  v91 = sub_8D3950(s32, &v103);
  v93 = v91;
  v90->m_Items[0] = v93;
  v95 = RepColTag(v81, v90);
  set_text(v102, v95);
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
  System_String_o *v13;
  UnityEngine_Object_o *v15;
  u64 *v17;
  UnityEngine_Transform_o *transform;
  UnityEngine_GameObject_o *v19;
  UnityEngine_Transform_o *v20;
  u32 v21;
  f64 v22;
  u32 v23;
  f32 v24;
  u32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  s64 v29;
  s64 v30;
  Il2CppObject *Item;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *Prefab_16624656;
  UnityEngine_GameObject_o *v36;
  UnityEngine_Transform_o *v38;
  Il2CppObject *Component_object;
  u64 v43;
  f32 *p_z;
  f32 v46;
  s64 v48;
  s64 v49;
  UnityEngine_Vector3_o v50;
  UnityEngine_Color_o v51;
  UnityEngine_Color_o v52;

  v13 = Concat_5224608("Field/", pName);
  v15 = Find(v13, 0);
  if (op_Equality(v15, 0, 0))
  {
    v17 = Allocate(UnityEngine_GameObject);
    _ctor(v17, pName, 0);
    *parent = v17;
    transform = get_transform(v17, 0);
    v19 = Find("Field", 0);
    v20 = get_transform(v19, 0);
    set_parent(transform, v20);
  }
  else
  {
    v21 = HIBYTE(col);
    if (HIBYTE(col))
    {
LABEL_11:
      v22 = v21;
      v23 = HIWORD(col);
      *&v22 = v22;
      v24 = *&v22 * 0.0039216;
      LOBYTE(v25) = col;
      goto LABEL_14;
    }
  }
  v24 = 1.0;
  v25 = HIWORD(col);
  LOBYTE(v23) = col;
LABEL_14:
  v26 = v25;
  v27 = BYTE1(col);
  v28 = v23;
  v48 = 0;
  v49 = 0;
  sub_19EC630(&v48, v26 * 0.0039216, v27 * 0.0039216, v28 * 0.0039216, v24);
  v29 = v48;
  v30 = v49;
  if (Animator___ContainsKey(Line3D, cName))
  {
    Item = object___get_Item(Line3D, cName);
  }
  else
  {
    if (!pos || *(&v30 + 1) == 0.0)
      return;
    asset_bc = get_asset_bc();
    Prefab_16624656 = LoadPrefab_16624656(asset_bc, "debug", "debug", "FldLine3D");
    v36 = Find(v13, 0);
    v38 = get_transform(v36, 0);
    Item = Instantiate_object__425520(Prefab_16624656, v38);
    set_name(Item, cName);
    PropertySheet___Add(Line3D, cName, Item);
  }
  Component_object = GetComponent_object_(Item);
  set_startWidth(Component_object, 0.05);
  set_endWidth(Component_object, 0.05);
  *&v51.r = v29;
  *&v51.b = v30;
  set_startColor(Component_object, v51);
  *&v52.r = v29;
  *&v52.b = v30;
  set_endColor(Component_object, v52);
  set_positionCount(Component_object, size);
  if (size >= 1)
  {
    v43 = 0;
    p_z = &pos->m_Items[0].z;
    do
    {
      v50.x = *(p_z - 2);
      v50.y = *(p_z - 1);
      v46 = *p_z;
      p_z += 3;
      v50.z = v46;
      SetPosition(Component_object, v43++, v50);
    }
    while (size != v43);
  }
  AttributeUsageAttribute___set_Item(Line3D, cName, Item);
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
