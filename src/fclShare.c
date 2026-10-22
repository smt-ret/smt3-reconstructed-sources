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
  s32 v9;

  v9 = 0;
  return sub_8D3950(s32, &v9);
}

// 0x199d180
void fclCalcRotPos(s32 pBufX, s32 pBufY, s32 DistX, s32 DistY, s32 CenterX, s32 CenterY, f32 Angle) {
  s32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  s32 v18;
  f32 v19;
  s32 v20;
  f32 v21;
  s32 v22;

  if (DistX >= 0)
    v13 = DistX;
  else
    v13 = DistX + 1;
  v14 = Angle * 0.017453;
  v15 = (v13 >> 1);
  v16 = DistY * 0.0;
  v17 = sdfCos(v14);
  v18 = ((v17 * v15) - (v16 * sdfSin(v14)));
  v19 = sdfSin(v14);
  v22 = CenterX + 2 * v18;
  v20 = ((v19 * v15) + (v16 * sdfCos(v14)));
  sub_8D3950(s32, &v22);
  v21 = (v20 / 0.0) + CenterY;
  sub_8D3950(f32, &v21);
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
LABEL_7:
  if ((byte_3F5ABF1 & 1) == 0)
    goto LABEL_16;
LABEL_10:
    return;
LABEL_11:
}

// 0x199d310
void fclDrawSpriteAngleCore(s32 X, s32 Y, s32 W, s32 H, f32 Angle, u32 **pCol, fclSprite_t *pSprite, u8 FlipFlag, u8 AlphaFlag, u8 FilterFlag, u32 OtNo) {
  u32 *v21;
  struct sdfTexHandle_t_o *TexHandle;
  sdfTexHandle_t_o *v23;
  s32 v24;
  s32 v26;
  Il2CppObject *v28;
  Il2CppObject *v29;
  Il2CppObject *v30;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v33;
  s64 *v34;
  s32 v36;
  s32 v37;
  s32 v38;
  s32 v39;
  s32 v40;
  s32 v41;
  s32 v43;
  s32 v44;
  s32 v46;
  s32 v47;
  s32 v49;
  s32 v50;
  struct System_UInt16_array *UV;
  s32 v53;
  struct System_UInt16_array *v54;
  s32 v56;
  struct System_UInt16_array *v58;
  s32 v60;
  struct System_UInt16_array *v62;
  s32 v64;
  u64 *v66;
  u64 *v68;
  s64 v71;
  s64 v74;
  u32 max_length;
  s64 monitor;
  u32 v79;
  u32 v83;
  u32 v85;
  u64 *v91;
  s32 *v93;
  Il2CppObject *v94;
  sdfDrawTag_t_o *v96;
  Il2CppClass *v97;
  s64 v98;
  char *v99;
  s64 *v100;
  u32 v107;
  u32 v109;
  u32 v111;
  Il2CppObject *aPacket;
  u8 v124[4];
  s32 v125;
  s32 v126;
  s32 v127;
  char v128[16];
  char *v129;
  s32 v130;
  s32 v131;

  v21 = NewSpecific(s32, 4u);
  TexHandle = pSprite->TexHandle;
  if (FilterFlag)
  {
    v23 = TexHandle;
    v24 = 1;
  }
  else
  {
    v23 = TexHandle;
    v24 = 0;
  }
  sdfTexSetFilter(v23, v24, 1);
  v26 = sdf2DGetPrimPacketSize(3, 4);
  v28 = sdfGrAllocPacketBuff(v26);
  sdf2DMakePrimPacketHeader_24943632(v28, 348, 3, 0, 4);
  v29 = sdf2DGetPrimPtr(v28);
  v30 = v29;
  aPacket = v28;
  if (v29)
  {
    klass = v29->klass;
    if (v29->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != fclShare_AnonymousClass)
    {
      sub_8FC2C0(klass->_1.element_class, fclShare_AnonymousClass, v128);
      if ((v128[0] & 1) != 0)
        v33 = v129;
      else
        v33 = &v128[1];
      v34 = sub_8C4940(v33);
    }
  }
  v36 = FCL_OFS_X + X;
  v37 = FCL_OFS_Y + Y;
  *v128 = v36 + 16 * W;
  sub_8D3950(s32, v128);
  v131 = v37 + 8 * H;
  sub_8D3950(s32, &v131);
  if (v36 >= 0)
    v38 = v36;
  else
    v38 = v36 + 1;
  v130 = -(v38 >> 1);
  sub_8D3950(s32, &v130);
  if (v37 >= 0)
    v39 = v37;
  else
    v39 = v37 + 1;
  v127 = -(v39 >> 1);
  sub_8D3950(s32, &v127);
  v126 = v36;
  sub_8D3950(s32, &v126);
  v125 = v37;
  v40 = sub_8D3950(s32, &v125);
  fclCalcRotPos(v40, v41, 0, 0, 0, 0, Angle);
  fclCalcRotPos(v43, v44, 0, 0, 0, 0, Angle);
  fclCalcRotPos(v46, v47, 0, 0, 0, 0, Angle);
  fclCalcRotPos(v49, v50, 0, 0, 0, 0, Angle);
  UV = pSprite->Base->UV;
  v53 = UV->m_Items[0];
  v21[8] = v53;
  v54 = pSprite->Base->UV;
  v56 = v54->m_Items[2];
  v21[10] = v56;
  v58 = pSprite->Base->UV;
  v60 = v58->m_Items[1];
  v21[9] = v60;
  v62 = pSprite->Base->UV;
  v64 = v62->m_Items[3];
  v21[11] = v64;
  v124[0] = FlipFlag;
  v66 = sub_8D3950(qword_3F088F8, v124);
  if (*il2cp::SizeOf(v66, bool))
  {
    *v128 = v36;
    sub_8D3950(s32, v128);
    v131 = 0;
    sub_8D3950(s32, &v131);
    v130 = 0;
    sub_8D3950(s32, &v130);
    v127 = 0;
    sub_8D3950(s32, &v127);
    v126 = 0;
    sub_8D3950(s32, &v126);
    v125 = 0;
    sub_8D3950(s32, &v125);
  }
  v128[0] = FlipFlag;
  v68 = sub_8D3950(qword_3F088F8, v128);
  if (*il2cp::SizeOf(v68, bool))
  {
    *v128 = v37;
    sub_8D3950(s32, v128);
    v131 = 0;
    sub_8D3950(s32, &v131);
    v130 = 0;
    sub_8D3950(s32, &v130);
    v127 = 0;
    sub_8D3950(s32, &v127);
    v126 = 0;
    sub_8D3950(s32, &v126);
    v125 = 0;
    sub_8D3950(s32, &v125);
  }
  if (pCol)
  {
    v71 = v30[1].klass;
    il2cp::SizeOf(v71, s32);
    il2cp::SizeOf(v30[2].monitor, s32);
    il2cp::SizeOf(v30[4].klass, s32);
    il2cp::SizeOf(v30[5].monitor, s32);
    monitor = v30[1].monitor;
    v79 = v21[6];
    if (!v79)
      goto LABEL_71;
  }
  else
  {
    v74 = v30[1].klass;
    max_length = pSprite->Col->max_length;
    il2cp::SizeOf(v74, s32);
    v107 = pSprite->Col->max_length;
    il2cp::SizeOf(v30[2].monitor, s32);
    v109 = pSprite->Col->max_length;
    il2cp::SizeOf(v30[4].klass, s32);
    v111 = pSprite->Col->max_length;
    il2cp::SizeOf(v30[5].monitor, s32);
    monitor = v30[1].monitor;
    v79 = v21[6];
    if (!v79)
    {
LABEL_71:
    }
  }
  il2cp::SizeOf(monitor, s32);
  il2cp::SizeOf(v30[2].klass, s32);
  il2cp::SizeOf(v30[3].klass, s32);
  il2cp::SizeOf(v30[3].monitor, s32);
  v83 = v21[6];
  il2cp::SizeOf(v30[4].monitor, s32);
  il2cp::SizeOf(v30[5].klass, s32);
  v85 = v21[6];
  il2cp::SizeOf(v30[6].klass, s32);
  il2cp::SizeOf(v30[6].monitor, s32);
  if (AlphaFlag == 2)
  {
      goto LABEL_92;
  }
  else
  {
      goto LABEL_92;
  }
LABEL_92:
  v91 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v91);
  v93 = il2cp::SizeOf(v91, s32);
  v94 = sdfGrAllocPacketBuff(*v93);
  v96 = v94;
  if (v94)
  {
    v97 = v94->klass;
    if (v94->klass->_2.typeHierarchyDepth < v98 || v97->_2.typeHierarchy[v98 - 1] != sdfDrawTag_t)
    {
      sub_8FC2C0(v97->_1.element_class, sdfDrawTag_t, v128);
      if ((v128[0] & 1) != 0)
        v99 = v129;
      else
        v99 = &v128[1];
      v100 = sub_8C4940(v99);
    }
  }
  sdf2DLinkTexPacket(v96, pSprite->TexHandle, 0);
  sdfDrawTagLink(v96, aPacket);
}

// 0x199d170
void fclDrawSpriteCore(s32 X, s32 Y, s32 W, s32 H, u32 **pCol, fclSprite_t *pSprite, u8 FlipFlag, u8 AlphaFlag, u8 FilterFlag, u32 OtNo) {
  ;
}

// 0x199d040
void fclDrawSpriteEx(s32 X, s32 Y, s32 W, s32 H, fclSprite_t *pSprite, u32 OtNo) {
  if ((byte_3F5ABF1 & 1) == 0)
    goto LABEL_10;
LABEL_6:
    return;
LABEL_7:
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
  u64 *v5;
  s64 v6;
  sdfFileCmdCallback_t_o *v7;
  System_String_o *v8;
  u64 *v10;
  char *v11;
  s64 *v12;
  s32 v13;
  u64 v14[3];

  v5 = Allocate(fclShare_fclFileCallback_a);
  v6 = Method_fclShare_fclFileCallback__;
  v5[2] = *Method_fclShare_fclFileCallback__;
  v7 = v5;
  v5[4] = 0;
  v5[5] = v6;
  v8 = *pFileName;
  v13 = 0;
  v10 = sub_8D3950(s32, &v13);
  else if (!v7)
  {
    goto LABEL_11;
  }
  if (v7->klass != sdfFileCmdCallback_t)
  {
    sub_8FC2C0(v7->klass->_1.element_class, sdfFileCmdCallback_t, v14);
    if ((v14[0] & 1) != 0)
      v11 = v14[2];
    else
      v11 = v14 + 1;
    v12 = sub_8C4940(v11);
  }
LABEL_11:
  sdfFileCmdReadFile(v8, v10, -1, v7, &pBuf->obj);
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
      goto LABEL_14;
    goto LABEL_8;
  }
  UV = Base->UV;
  Base->W = UV->m_Items[2];
  Base = pSprite->Base;
  if (!Base->H)
  {
LABEL_8:
    v18 = Base->UV;
    Base->H = v18->m_Items[3];
    Base = pSprite->Base;
  }
LABEL_14:
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
