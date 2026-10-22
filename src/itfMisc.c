#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct _FRQ _FRQ;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct itfmisclinkstack_t itfmisclinkstack_t;
typedef struct mesflow_tag mesflow_tag;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfIVector2_t sdfIVector2_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfPrm sdfPrm;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 ITF_MISC_SCREEN_OFFSET_X;
static s32 ITF_MISC_SCREEN_OFFSET_Y;
static u64 itfMiscDrawAlphaPrim_palphadata[3];
static u8 *itfMiscDrawGauge_ppidxvert[2];
static u8 itfMiscDrawGauge_pidxcolor[4];
static u8 *itfMiscDrawGauge_ppidxlinevert[2];
static u8 *itfMiscDrawGauge_ppidxlinecolor[2];
static sdfIVector4_t *itfMiscDrawGauge_pcolorratio[4];
static dds3ModelHandle_t *itfCampModelGlobal;

char *CheckPictureID715(char *filename);
char *GetDLCTag(s32 eventno);
bool IsDLC(void);
bool IsDLCField(s32 area);
void **LoadSprite(AssetBundleCtrl *this, char *key, char *path, char *name);
void Log(char *fmt, void **parray);
u64 SDF_GIFTAG_REGS2(s32 r0, s32 r1);
s32 SDF_GIFTAG_REGS3(s32 a, s32 b, s32 c);
u64 SDF_GIFTAG_REGS4(s32 r0, s32 r1, s32 r2, s32 r3);
s32 SDF_GIFTAG_REGS5(s32 r0, s32 r1, s32 r2, s32 r3, s32 r4);
s32 SDF_GIF_SET_RGBA(s32 pkt, s32 r, s32 g, s32 b, s32 a);
void SDF_GIF_SET_STQ(sdfPrm **pkt, s32 *index, f32 s, f32 t, f32 q);
s32 SDF_GIF_SET_UV(s32 pkt, s32 u, s32 v);
s32 SDF_GIF_SET_XYZ2(s32 a, s32 b, s32 c, s32 d, s32 e);
u64 SDF_GS_SET_CLAMP(u8 wms, u8 wmt, u16 minu, u16 maxu, u16 minv, u16 maxv);
s32 SDF_GS_SET_PRIM(s32 prim, s32 iip, s32 tme, s32 fge, s32 abe, s32 aa1, s32 fst, s32 ctxt, s32 fix);
void dds3AdminiExitSequence(void);
s32 dds3AdminiGetActiveSequence(void);
void itfMiscDrawLineStripPrim(sdfIVector2_t **pvertex_top, s32 off, sdfIVector4_t **pcolor_top, u8 **pvertindex, u8 **pcolorindex, s32 num, u32 z, sdfDrawTag_t *pdrawtag);
void itfMiscDrawRectanglePrim(sdfIVector2_t **pvertex_top, s32 off, sdfIVector4_t **pcolor_top, u8 **pvertindex, u8 **pcolorindex, u32 z, sdfDrawTag_t *pdrawtag);
void itfMiscSetRatioRGB(sdfIVector4_t ***pout, s32 off, s32 red, s32 green, s32 blue, s32 alpha, sdfIVector4_t **pratio, s32 num);
void *sdf2DLinkTexPacket(sdfDrawTag_t *aTag, sdfTexHandle_t *aTexHndl, s32 aCtx);
void *sdf2DMakePrimPacketHeader(sdfGrPacketHeader_t *aPacketPtr, s32 aPrimReg, s32 aNumOfRegs, u64 aGifRegs, s32 aNumOfPrim);
void *sdf2DMakeStdPacket(void *aPacket, s32 aLeng);
void sdfDrawTagLink(sdfDrawTag_t *aTag, void *aPacket);

// 0x1596a30
char *CheckPictureID715(char *filename) {
  s32 IndexOf;
  s32 v4;
  s32 Length;
  System_String_o *v6;
  System_String_o *v7;
  System_String_o *v8;
  bool v9;
  s64 *v10;
  s32 v13;
  s32 result;

  result = 0;
  v13 = 0;
  result = 0;
  if (!IsDLC())
    goto LABEL_18;
LABEL_6:
  IndexOf = LastIndexOf(filename, 0x2Fu, 0);
  if (IndexOf == -1)
    goto LABEL_18;
  v4 = IndexOf;
  Length = get_Length(filename);
  v6 = Substring_5248048(filename, v4 + 1, Length + ~v4);
  v7 = Substring_5248048(v6, 1, 3);
  if (!TryParse(v7, &result, 0))
    goto LABEL_18;
  v13 = 0;
  v8 = Substring_5248048(v6, 6, 3);
  v9 = TryParse(v8, &v13, 0);
  v10 = &"";
  if (v9)
  {
    v10 = &"m";
    if ((result != 715 || v13 != 6) && (v13 != 22 || result != 716))
      v10 = &"";
  }
  return *v10;
}

// 0x1599f60
sdfColor_t UintToColor(u32 color) {
  f32 v2;
  f32 v3;
  f32 v4;
  f32 v5;
  s64 v10;
  s64 v11;
  UnityEngine_Color_o result;

  v10 = 0;
  v11 = 0;
  v2 = color;
  v3 = HIBYTE(color);
  v4 = BYTE2(color);
  v5 = BYTE1(color);
  sub_19EC630(&v10, v3 / 255.0, v4 / 255.0, v5 / 255.0, v2 / 255.0);
  result.g = *(&v10 + 1);
  LODWORD(result.r) = v10;
  result.a = *(&v11 + 1);
  LODWORD(result.b) = v11;
  return result;
}

// 0x1599eb0
dds3ProcessFunc_t *dds3DebugDevDumpProcess(dds3ProcessID_t *proc_id) {
  return 0;
}

// 0x1599ec0
s32 itfCamp(void) {
  return 1;
}

// 0x1599ed0
void itfCampStartProcess(void) {
  if (dds3AdminiGetActiveSequence() != 7)
    dds3AdminiExitSequence();
  Write("Camp process halted.\n", 0);
}

// 0x1596150
void itfMiscChangeFontAlpha(_FRQ *pfont, u32 alpha) {
  struct _TEXT_o *str;
  _TEXT_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  for (; pfont; pfont = pfont->prev)
  {
    str = pfont->str;
    if (str)
    {
      klass = str->klass;
      if (str->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != _TEXT)
      {
        sub_8FC2C0(klass->_1.element_class, _TEXT, v10);
        if ((v10[0] & 1) != 0)
          v8 = v10[2];
        else
          v8 = v10 + 1;
        v9 = sub_8C4940(v8);
      }
      do
      {
        str->color = str->color & 0xFFFFFF00 | alpha;
        str = str->next;
      }
      while (str);
    }
  }
}

// 0x1596030
void itfMiscChangeFontVertexColor(_FRQ *pfont, u32 color) {
  struct _TEXT_o *str;
  _TEXT_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  for (; pfont; pfont = pfont->prev)
  {
    str = pfont->str;
    if (str)
    {
      klass = str->klass;
      if (str->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != _TEXT)
      {
        sub_8FC2C0(klass->_1.element_class, _TEXT, v10);
        if ((v10[0] & 1) != 0)
          v8 = v10[2];
        else
          v8 = v10 + 1;
        v9 = sub_8C4940(v8);
      }
      do
      {
        str->color = color;
        str = str->next;
      }
      while (str);
    }
  }
}

// 0x1598c70
void itfMiscDrawAlphaPrim(sdfDrawTag_t *pdrawtag, s32 tp, s32 context) {
  packetregist_tag_o *v7;
  struct sdfGrTagStdReg_t_o *regist;
  struct System_UInt64_array *itfMiscDrawAlphaPrim_palphadata;
  s64 v13;

  v7 = Allocate(packetregist_tag);
  _ctor(v7, 0);
  regist = v7->regist;
  regist->data = itfMiscDrawAlphaPrim_palphadata->m_Items[tp];
  v13 = 66;
  if (context)
    v13 = 67;
  v7->regist->reg = v13;
  sdfDrawTagLink(pdrawtag, v7);
}

// 0x1598d90
void itfMiscDrawClampPrim(sdfDrawTag_t *pdrawtag, s32 context, s32 wms, s32 wmt, s32 min_u, s32 max_u, s32 min_v, s32 max_v) {
  u16 v9;
  u16 v10;
  u16 v11;
  u16 v12;
  u8 v13;
  u8 v14;
  u64 *v16;
  Il2CppObject *v17;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *monitor;
  Il2CppObject *v21;
  s64 v23;
  char *v24;
  s64 *v25;
  u64 v27[3];

  v9 = max_v;
  v10 = min_v;
  v11 = max_u;
  v12 = min_u;
  v13 = wmt;
  v14 = wms;
  v16 = Allocate(packetregist_tag);
  _ctor(v16, 0);
  v17 = sdf2DMakeStdPacket(v16, 0);
  klass = v17->klass;
  if (v17->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != packetregist_tag)
  {
    sub_8FC2C0(klass->_1.element_class, packetregist_tag, v27);
    if ((v27[0] & 1) != 0)
      v24 = v27[2];
    else
      v24 = v27 + 1;
    v25 = sub_8C4940(v24);
  }
  monitor = v17[2].monitor;
  v21 = v17;
  monitor[3] = SDF_GS_SET_CLAMP(v14, v13, v12, v11, v10, v9);
  v23 = 8;
  if (context)
    v23 = 9;
  *(v21[2].monitor + 4) = v23;
  sdfDrawTagLink(pdrawtag, v16);
}

// 0x1598f40
void itfMiscDrawGauge(s32 portion, s32 entire, s32 shadow, sdfIVector4_t *pos, u32 z, sdfIVector4_t **pcolor_portion, sdfIVector4_t **pcolor_entire, sdfDrawTag_t *pdrawtag) {
  sdfIVector2_t_array *v13;
  struct System_Int32_array *pm;
  s32 v15;
  struct System_Int32_array *v16;
  s32 v18;
  Il2CppObject *v19;
  struct System_Int32_array *v20;
  Il2CppClass *klass;
  s32 v22;
  struct System_Int32_array *v23;
  struct System_Int32_array *v24;
  Il2CppObject *v27;
  Il2CppClass *v36;
  s32 v37;
  struct System_Int32_array *v39;
  struct System_Int32_array *v40;
  Il2CppObject *v43;
  struct System_Int32_array *v47;
  Il2CppClass *v48;
  s32 v49;
  struct System_Int32_array *v51;
  struct System_Int32_array *v52;
  s32 v54;
  Il2CppObject *v56;
  struct System_Int32_array *v57;
  Il2CppClass *v58;
  s32 v63;
  struct System_Int32_array *v65;
  struct System_Int32_array *v66;
  s32 v68;
  Il2CppObject *v70;
  Il2CppClass *v71;
  struct System_Int32_array *v77;
  struct System_Int32_array *v78;
  s32 v80;
  Il2CppObject *v82;
  struct System_Int32_array *v86;
  Il2CppClass *v87;
  s32 v88;
  struct System_Int32_array *v90;
  struct System_Int32_array *v91;
  s32 v93;
  Il2CppObject *v95;
  struct System_Byte_array_array *itfMiscDrawGauge_ppidxvert;
  struct System_Byte_array_array *v105;
  s32 v108;
  s32 v109;
  struct System_Int32_array *v110;
  s32 v111;
  struct System_Int32_array *v116;
  s32 v119;
  struct System_Byte_array_array *itfMiscDrawGauge_ppidxlinevert;
  System_Byte_array *v122;
  struct System_Byte_array_array *itfMiscDrawGauge_ppidxlinecolor;
  struct System_Byte_array_array *v125;
  struct System_Byte_array_array *v127;
  sdfIVector4_t_array *v144;
  s32 v145;
  sdfIVector4_t_array *pout;

  v13 = NewSpecific(sdfIVector2_t, 6u);
  pout = NewSpecific(sdfIVector4_t, 1u);
  pm = pos->pm;
  v144 = pout;
  v15 = pm->m_Items[2];
  if (entire < 1)
  {
    v145 = 0;
    v16 = pos->pm;
    if (!LODWORD(v16->max_length))
    {
LABEL_6:
    }
  }
  else
  {
    v145 = (((v15 - pos->pm->m_Items[0]) >> 4) * ((portion << 16) / entire)) >> 12;
    v16 = pos->pm;
    if (!LODWORD(v16->max_length))
      goto LABEL_6;
  }
  v18 = v16->m_Items[0];
  v19 = Allocate(sdfIVector2_t);
  v19[1].klass = NewSpecific(s32, 2u);
  _ctor(v19, 0);
  v13->m_Items[0] = v19;
  v20 = pos->pm;
  klass = v19[1].klass;
  v22 = v20->m_Items[0];
  LODWORD(klass->_1.byval_arg.data) = v22;
  v23 = pos->pm;
  v24 = v13->m_Items[0]->pm;
  v24->m_Items[1] = v23->m_Items[1];
  v27 = Allocate(sdfIVector2_t);
  v27[1].klass = NewSpecific(s32, 2u);
  _ctor(v27, 0);
  v13->m_Items[1] = v27;
  v36 = v27[1].klass;
  v37 = v18 + v145;
  LODWORD(v36->_1.byval_arg.data) = v37;
  v39 = pos->pm;
  v40 = v13->m_Items[1]->pm;
  v40->m_Items[1] = v39->m_Items[1];
  v43 = Allocate(sdfIVector2_t);
  v43[1].klass = NewSpecific(s32, 2u);
  _ctor(v43, 0);
  v13->m_Items[2] = v43;
  v47 = pos->pm;
  v48 = v43[1].klass;
  v49 = v47->m_Items[2];
  LODWORD(v48->_1.byval_arg.data) = v49;
  v51 = pos->pm;
  v52 = v13->m_Items[2]->pm;
  v54 = v51->m_Items[1];
  v52->m_Items[1] = v54;
  v56 = Allocate(sdfIVector2_t);
  v56[1].klass = NewSpecific(s32, 2u);
  _ctor(v56, 0);
  v13->m_Items[3] = v56;
  v57 = pos->pm;
  v58 = v56[1].klass;
  v63 = v57->m_Items[0];
  LODWORD(v58->_1.byval_arg.data) = v63;
  v65 = pos->pm;
  v66 = v13->m_Items[3]->pm;
  v68 = v65->m_Items[3];
  v66->m_Items[1] = v68;
  v70 = Allocate(sdfIVector2_t);
  v70[1].klass = NewSpecific(s32, 2u);
  _ctor(v70, 0);
  v13->m_Items[4] = v70;
  v71 = v70[1].klass;
  LODWORD(v71->_1.byval_arg.data) = v37;
  v77 = pos->pm;
  v78 = v13->m_Items[4]->pm;
  v80 = v77->m_Items[3];
  v78->m_Items[1] = v80;
  v82 = Allocate(sdfIVector2_t);
  v82[1].klass = NewSpecific(s32, 2u);
  _ctor(v82, 0);
  v13->m_Items[5] = v82;
  v86 = pos->pm;
  v87 = v82[1].klass;
  v88 = v86->m_Items[2];
  LODWORD(v87->_1.byval_arg.data) = v88;
  v90 = pos->pm;
  v91 = v13->m_Items[5]->pm;
  v93 = v90->m_Items[3];
  v91->m_Items[1] = v93;
  v95 = Allocate(sdfIVector4_t);
  v95[1].klass = NewSpecific(s32, 4u);
  _ctor(v95, 0);
  v144->m_Items[0] = v95;
  itfMiscDrawRectanglePrim(v13, 0, pcolor_portion, itfMiscDrawGauge_ppidxvert->m_Items[0], itfMiscDrawGauge_pidxcolor, z, pdrawtag);
  v105 = itfMiscDrawGauge_ppidxvert;
  itfMiscDrawRectanglePrim(v13, 0, pcolor_entire, v105->m_Items[1], itfMiscDrawGauge_pidxcolor, z, pdrawtag);
  if (shadow && v145 >= 3)
  {
    v110 = pcolor_portion->m_Items[0]->pm;
    v111 = v110->m_Items[0];
    v116 = pcolor_portion->m_Items[0]->pm;
    v119 = v116->m_Items[3];
    itfMiscSetRatioRGB(&pout, 0, v111, v108, v109, v119, itfMiscDrawGauge_pcolorratio, 4);
    v122 = itfMiscDrawGauge_ppidxlinevert->m_Items[0];
    itfMiscDrawLineStripPrim(v13, 0, v144, v122, itfMiscDrawGauge_ppidxlinecolor->m_Items[0], 3, z, pdrawtag);
    v125 = itfMiscDrawGauge_ppidxlinevert;
    v127 = itfMiscDrawGauge_ppidxlinecolor;
    itfMiscDrawLineStripPrim(v13, 0, v144, v125->m_Items[1], v127->m_Items[1], 3, z, pdrawtag);
  }
}

// 0x1598740
void itfMiscDrawLinePrim(sdfIVector2_t **pvertex_top, s32 off, sdfIVector4_t **pcolor_top, u8 **pvertindex, u8 **pcolorindex, s32 num, u32 z, sdfDrawTag_t *pdrawtag) {
  sdf2DTexPacket_t_o *v13;
  s32 v14;
  u64 v15;
  sdfPrm_array *primitive;
  s64 v18;
  u8 *v19;
  u8 *v20;
  s64 v25;
  s64 v27;
  sdfIVector4_t_o *v30;
  struct System_Int32_array *pm;
  u32 max_length;
  sdfPrm_array *v33;
  s32 v34;
  struct System_Int32_array *v35;
  s32 v36;
  s32 v37;
  s32 v39;
  struct System_Int32_array *v41;
  s32 v43;
  struct System_Int32_array *v45;
  Il2CppObject *v47;
  sdfIVector2_t_array *v49;
  sdfIVector4_t_array *v50;
  u16 za;
  sdfIVector2_t_o *v54;
  s32 index;

  za = z;
  v13 = Allocate(sdf2DTexPacket_t);
  _ctor(v13, 0);
  v13->primitive = NewSpecific(sdfPrm, (4 * num));
  v14 = SDF_GS_SET_PRIM(1u, 1u, 0, 0, 1u, 0, 0, 0, 0);
  v15 = SDF_GIFTAG_REGS2(1, 5);
  sdf2DMakePrimPacketHeader(v13, v14, 2, v15, num);
  primitive = v13->primitive;
  v47 = v13;
  index = 0;
  if (num >= 1)
  {
    v18 = off + 32LL;
    v49 = pvertex_top;
    v50 = pcolor_top;
    v19 = pvertindex + v18;
    v20 = pcolorindex + v18;
    do
    {
      v25 = *v19;
      v27 = *v20;
      v54 = pvertex_top->m_Items[v25];
      v30 = pcolor_top->m_Items[v27];
      pm = v30->pm;
      max_length = pm->max_length;
      v33 = primitive;
      v34 = pm->m_Items[0];
      v35 = v30->pm;
      v36 = v30->pm->m_Items[1];
      v37 = v35->m_Items[2];
      v39 = v35->m_Items[3];
      primitive = v33;
      SDF_GIF_SET_RGBA(v33, &index, v34, v36, v37, v39, 0);
      v41 = v54->pm;
      v43 = v41->m_Items[0];
      pcolor_top = v50;
      v45 = v54->pm;
      SDF_GIF_SET_XYZ2(
        primitive,
        &index,
        ITF_MISC_SCREEN_OFFSET_X + v43,
        ITF_MISC_SCREEN_OFFSET_Y + v45->m_Items[1],
        za,
        0,
        0);
      pvertex_top = v49;
      ++v19;
      ++v20;
      ++off;
      --num;
    }
    while (num);
  }
  sdfDrawTagLink(pdrawtag, v47);
}

// 0x15983b0
void itfMiscDrawLineStripPrim(sdfIVector2_t **pvertex_top, s32 off, sdfIVector4_t **pcolor_top, u8 **pvertindex, u8 **pcolorindex, s32 num, u32 z, sdfDrawTag_t *pdrawtag) {
  sdf2DTexPacket_t_o *v13;
  s32 v14;
  u64 v15;
  sdfPrm_array *primitive;
  s64 v18;
  u8 *v19;
  u8 *v20;
  s64 v26;
  s64 v28;
  sdfIVector4_t_o *v31;
  struct System_Int32_array *pm;
  u32 max_length;
  sdfPrm_array *v34;
  s32 v35;
  struct System_Int32_array *v36;
  s32 v37;
  s32 v38;
  s32 v40;
  struct System_Int32_array *v41;
  u32 v42;
  s32 v43;
  Il2CppObject *v45;
  sdfIVector2_t_array *v47;
  sdfIVector4_t_array *v48;
  u16 za;
  sdfIVector2_t_o *v52;
  s32 index;

  za = z;
  v13 = Allocate(sdf2DTexPacket_t);
  _ctor(v13, 0);
  v13->primitive = NewSpecific(sdfPrm, (4 * num));
  v14 = SDF_GS_SET_PRIM(2u, 1u, 0, 0, 1u, 0, 1u, 0, 0);
  v15 = SDF_GIFTAG_REGS2(1, 5);
  sdf2DMakePrimPacketHeader(v13, v14, 2, v15, num);
  primitive = v13->primitive;
  v45 = v13;
  index = 0;
  if (num >= 1)
  {
    v18 = off + 32LL;
    v47 = pvertex_top;
    v48 = pcolor_top;
    v19 = pvertindex + v18;
    v20 = pcolorindex + v18;
    do
    {
      v26 = *v19;
      v28 = *v20;
      v52 = pvertex_top->m_Items[v26];
      v31 = pcolor_top->m_Items[v28];
      pm = v31->pm;
      max_length = pm->max_length;
      v34 = primitive;
      v35 = pm->m_Items[0];
      v36 = v31->pm;
      v37 = v31->pm->m_Items[1];
      v38 = v36->m_Items[2];
      v40 = v36->m_Items[3];
      primitive = v34;
      SDF_GIF_SET_RGBA(v34, &index, v35, v37, v38, v40, 0);
      v41 = v52->pm;
      v42 = v41->max_length;
      v43 = v41->m_Items[0];
      pcolor_top = v48;
      SDF_GIF_SET_XYZ2(v34, &index, v43 + 28672, v52->pm->m_Items[1] + 30976, za, 0, 0);
      pvertex_top = v47;
      ++v19;
      ++v20;
      ++off;
      --num;
    }
    while (num);
  }
  sdfDrawTagLink(pdrawtag, v45);
}

// 0x1596bb0
void itfMiscDrawRectanglePrim(sdfIVector2_t **pvertex_top, s32 off, sdfIVector4_t **pcolor_top, u8 **pvertindex, u8 **pcolorindex, u32 z, sdfDrawTag_t *pdrawtag) {
  sdf2DTexPacket_t_o *v11;
  s32 v12;
  u64 v13;
  s64 v14;
  sdfPrm_array *primitive;
  s64 v16;
  s64 v21;
  s64 v23;
  sdfIVector2_t_o *v25;
  sdfIVector4_t_o *v27;
  struct System_Int32_array *pm;
  u32 max_length;
  struct System_Int32_array *v32;
  s32 v34;
  struct System_Int32_array *v36;
  Il2CppObject *v39;
  char *v41;
  char *v42;
  u16 za;
  s32 index;

  za = z;
  v11 = Allocate(sdf2DTexPacket_t);
  _ctor(v11, 0);
  v11->primitive = NewSpecific(sdfPrm, 0x10u);
  v12 = SDF_GS_SET_PRIM(5u, 1u, 0, 0, 1u, 0, 0, 0, 0);
  v13 = SDF_GIFTAG_REGS2(1, 5);
  sdf2DMakePrimPacketHeader(v11, v12, 2, v13, 4);
  v14 = off + 32LL;
  v42 = pvertindex + v14;
  primitive = v11->primitive;
  index = 0;
  v16 = 0;
  v39 = v11;
  v41 = pcolorindex + v14;
  do
  {
    v21 = v42[v16];
    v23 = v41[v16];
    v25 = pvertex_top->m_Items[v21];
    v27 = pcolor_top->m_Items[v23];
    pm = v27->pm;
    max_length = pm->max_length;
    SDF_GIF_SET_RGBA(
      primitive,
      &index,
      pm->m_Items[0],
      v27->pm->m_Items[1],
      v27->pm->m_Items[2],
      v27->pm->m_Items[3],
      0);
    v32 = v25->pm;
    v34 = v32->m_Items[0];
    v36 = v25->pm;
    SDF_GIF_SET_XYZ2(
      primitive,
      &index,
      ITF_MISC_SCREEN_OFFSET_X + v34,
      ITF_MISC_SCREEN_OFFSET_Y + v36->m_Items[1],
      za,
      0,
      0);
    ++v16;
  }
  while (v16 != 4);
  sdfDrawTagLink(pdrawtag, v39);
}

// 0x1597c90
void itfMiscDrawSpritePlanePrim(sdfIVector4_t *pos, sdfIVector4_t *color, u32 z, s32 context, sdfDrawTag_t *pdrawtag) {
  u16 v8;
  sdf2DTexPacket_t_o *v11;
  s32 v12;
  u64 v13;
  sdfPrm_array *primitive;
  struct System_Int32_array *pm;
  u32 max_length;
  s32 v17;
  struct System_Int32_array *v20;
  s32 v23;
  struct System_Int32_array *v24;
  struct System_Int32_array *v26;
  u32 v27;
  s32 index;

  v8 = z;
  v11 = Allocate(sdf2DTexPacket_t);
  _ctor(v11, 0);
  v11->primitive = NewSpecific(sdfPrm, 6u);
  v12 = SDF_GS_SET_PRIM(6u, 0, 0, 0, 1u, 0, 0, context, 0);
  v13 = SDF_GIFTAG_REGS3(1, 5, 5);
  sdf2DMakePrimPacketHeader(v11, v12, 5, v13, 1);
  primitive = v11->primitive;
  index = 0;
  pm = color->pm;
  max_length = pm->max_length;
  v17 = pm->m_Items[0];
  SDF_GIF_SET_RGBA(
    primitive,
    &index,
    v17,
    color->pm->m_Items[1],
    color->pm->m_Items[2],
    color->pm->m_Items[3],
    0);
  v20 = pos->pm;
  v23 = v20->m_Items[0];
  v24 = pos->pm;
  SDF_GIF_SET_XYZ2(
    primitive,
    &index,
    ITF_MISC_SCREEN_OFFSET_X + v23,
    ITF_MISC_SCREEN_OFFSET_Y + v24->m_Items[1],
    v8,
    0,
    0);
  v26 = pos->pm;
  v27 = v26->max_length;
  SDF_GIF_SET_XYZ2(
    primitive,
    &index,
    ITF_MISC_SCREEN_OFFSET_X + v26->m_Items[2],
    ITF_MISC_SCREEN_OFFSET_Y + pos->pm->m_Items[3],
    v8,
    0,
    0);
  sdfDrawTagLink(pdrawtag, v11);
}

// 0x1597390
void itfMiscDrawSpritePrim(sdfIVector4_t *pos, sdfIVector4_t *uv, sdfIVector4_t *color, u32 z, sdfTexHandle_t *texhandle, s32 context, sdfDrawTag_t *pdrawtag) {
  sdf2DTexPacket_t_o *v12;
  s32 v13;
  u64 v14;
  struct System_Int32_array *pm;
  struct System_Int32_array *v20;
  u32 max_length;
  s32 v23;
  s32 ITF_MISC_SCREEN_OFFSET_Y;
  s32 v27;
  sdfPrm_array *primitive;
  struct System_Int32_array *v29;
  u32 v30;
  s32 v32;
  struct System_Int32_array *v33;
  u32 v34;
  s32 v35;
  struct System_Int32_array *v37;
  u32 v38;
  s32 v40;
  s32 v47;
  s32 v48;
  s32 v49;
  s32 ITF_MISC_SCREEN_OFFSET_X;
  s32 v51;
  sdfIVector4_t_o *v52;
  u16 za;
  s32 aCtx;
  s32 index;

  za = z;
  index = 0;
  v12 = Allocate(sdf2DTexPacket_t);
  _ctor(v12, 0);
  v12->primitive = NewSpecific(sdfPrm, 0xAu);
  aCtx = context;
  v13 = SDF_GS_SET_PRIM(6u, 0, 1u, 0, 1u, 0, 1u, context, 0);
  v14 = SDF_GIFTAG_REGS5(1, 3, 5, 3, 5);
  sdf2DMakePrimPacketHeader(v12, v13, 5, v14, 1);
  pm = pos->pm;
  v51 = pm->m_Items[0];
  v20 = pos->pm;
  max_length = v20->max_length;
  v52 = uv;
  v23 = v20->m_Items[1];
  v48 = ITF_MISC_SCREEN_OFFSET_X;
  v49 = pos->pm->m_Items[2];
  v27 = ITF_MISC_SCREEN_OFFSET_Y;
  v47 = pos->pm->m_Items[3];
  primitive = v12->primitive;
  index = 0;
  v29 = color->pm;
  v30 = v29->max_length;
  v32 = ITF_MISC_SCREEN_OFFSET_Y + v23;
  SDF_GIF_SET_RGBA(
    primitive,
    &index,
    v29->m_Items[0],
    color->pm->m_Items[1],
    color->pm->m_Items[2],
    color->pm->m_Items[3],
    0);
  v33 = v52->pm;
  v34 = v33->max_length;
  v35 = v33->m_Items[0];
  SDF_GIF_SET_UV(primitive, &index, v35, v52->pm->m_Items[1], 0);
  SDF_GIF_SET_XYZ2(primitive, &index, ITF_MISC_SCREEN_OFFSET_X + v51, v32, za, 0, 0);
  v37 = v52->pm;
  v38 = v37->max_length;
  v40 = v37->m_Items[2];
  SDF_GIF_SET_UV(primitive, &index, v40, v52->pm->m_Items[3], 0);
  SDF_GIF_SET_XYZ2(primitive, &index, v48 + v49, v27 + v47, za, 0, 0);
  sdf2DLinkTexPacket(pdrawtag, texhandle, aCtx);
  sdfDrawTagLink(pdrawtag, v12);
}

// 0x1597820
void itfMiscDrawSpritePrim2(sdfIVector4_t *pos, sdfIVector4_t *uv, sdfIVector4_t *color, u32 z, s32 context, sdfDrawTag_t *pdrawtag) {
  sdf2DTexPacket_t_o *v11;
  s32 v12;
  u64 v13;
  struct System_Int32_array *pm;
  struct System_Int32_array *v19;
  u32 max_length;
  struct System_Int32_array *v21;
  s32 v23;
  s32 ITF_MISC_SCREEN_OFFSET_Y;
  s32 v27;
  sdfPrm_array *klass;
  struct System_Int32_array *v29;
  u32 v30;
  s32 v32;
  struct System_Int32_array *v33;
  u32 v34;
  s32 v36;
  struct System_Int32_array *v37;
  u32 v38;
  s32 v46;
  s32 v47;
  s32 v48;
  s32 ITF_MISC_SCREEN_OFFSET_X;
  s32 v50;
  u16 za;
  Il2CppObject *v53;
  s32 index;

  za = z;
  index = 0;
  v11 = Allocate(sdf2DTexPacket_t);
  _ctor(v11, 0);
  v11->primitive = NewSpecific(sdfPrm, 0xAu);
  v12 = SDF_GS_SET_PRIM(6u, 1u, 1u, 0, 1u, 0, 1u, context, 0);
  v13 = SDF_GIFTAG_REGS5(1, 3, 5, 3, 5);
  v53 = v11;
  sdf2DMakePrimPacketHeader(v11, v12, 5, v13, 1);
  pm = pos->pm;
  v50 = pm->m_Items[0];
  v19 = pos->pm;
  max_length = v19->max_length;
  v21 = pos->pm;
  v23 = v19->m_Items[1];
  v47 = ITF_MISC_SCREEN_OFFSET_X;
  v48 = v21->m_Items[2];
  v27 = ITF_MISC_SCREEN_OFFSET_Y;
  v46 = v21->m_Items[3];
  klass = v53[2].klass;
  index = 0;
  v29 = color->pm;
  v30 = v29->max_length;
  v32 = ITF_MISC_SCREEN_OFFSET_Y + v23;
  SDF_GIF_SET_RGBA(
    klass,
    &index,
    v29->m_Items[0],
    color->pm->m_Items[1],
    color->pm->m_Items[2],
    color->pm->m_Items[3],
    0);
  v33 = uv->pm;
  v34 = v33->max_length;
  v36 = v27 + v46;
  SDF_GIF_SET_UV(klass, &index, v33->m_Items[0], uv->pm->m_Items[1], 0);
  SDF_GIF_SET_XYZ2(klass, &index, ITF_MISC_SCREEN_OFFSET_X + v50, v32, za, 0, 0);
  v37 = uv->pm;
  v38 = v37->max_length;
  SDF_GIF_SET_UV(klass, &index, v37->m_Items[2], uv->pm->m_Items[3], 0);
  SDF_GIF_SET_XYZ2(klass, &index, v47 + v48, v36, za, 0, 0);
  sdfDrawTagLink(pdrawtag, v53);
}

// 0x1598b00
void itfMiscDrawTestPrim(sdfDrawTag_t *pdrawtag, u64 para, s32 context) {
  u64 *v7;
  Il2CppObject *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s64 v12;
  char *v13;
  s64 *v14;
  u64 v15[3];

  v7 = Allocate(packetregist_tag);
  _ctor(v7, 0);
  v8 = sdf2DMakeStdPacket(v7, 0);
  klass = v8->klass;
  if (v8->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != packetregist_tag)
  {
    sub_8FC2C0(klass->_1.element_class, packetregist_tag, v15);
    if ((v15[0] & 1) != 0)
      v13 = v15[2];
    else
      v13 = v15 + 1;
    v14 = sub_8C4940(v13);
  }
  *(v8[2].monitor + 3) = para;
  v12 = 71;
  if (context)
    v12 = 72;
  *(v8[2].monitor + 4) = v12;
  sdfDrawTagLink(pdrawtag, v7);
}

// 0x1596f70
void itfMiscDrawTexPoly(sdfIVector2_t **pvertex, sdfVector4_t pstq, sdfIVector4_t **pcolor, u32 z, s32 context, sdfDrawTag_t *pdrawtag) {
  sdf2DTexPacket_t_o *v9;
  s32 v10;
  u64 v11;
  sdfPrm_array *primitive;
  u64 v13;
  sdfIVector2_t_o **m_Items;
  sdfIVector4_t_o **v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  struct System_Int32_array *pm;
  s32 v22;
  struct System_Int32_array *v24;
  s32 v26;
  struct System_Int32_array *v28;
  s32 v30;
  struct System_Int32_array *v32;
  struct System_Int32_array *v35;
  s32 v37;
  struct System_Int32_array *v43;
  Il2CppObject *v46;
  u16 za;
  s32 index;
  UnityEngine_Vector4_o v51;

  za = z;
  v51 = pstq;
  v9 = Allocate(sdf2DTexPacket_t);
  _ctor(v9, 0);
  v9->primitive = NewSpecific(sdfPrm, 0x18u);
  v10 = SDF_GS_SET_PRIM(5u, 1u, 1u, 0, 1u, 0, 0, context, 0);
  v11 = SDF_GIFTAG_REGS3(2, 1, 5);
  sdf2DMakePrimPacketHeader(v9, v10, 3, v11, 4);
  v46 = v9;
  primitive = v9->primitive;
  index = 0;
  v13 = 0;
  m_Items = pvertex->m_Items;
  v15 = pcolor->m_Items;
  do
  {
    sub_854710(&v51, 0);
    v17 = v16;
    sub_854710(&v51, 1u);
    v19 = v18;
    sub_854710(&v51, 2u);
    SDF_GIF_SET_STQ(primitive, &index, v17, v19, v20);
    pm = v15[v13]->pm;
    v22 = pm->m_Items[0];
    v24 = v15[v13]->pm;
    v26 = v24->m_Items[1];
    v28 = v15[v13]->pm;
    v30 = v28->m_Items[2];
    v32 = v15[v13]->pm;
    SDF_GIF_SET_RGBA(primitive, &index, v22, v26, v30, v32->m_Items[3], 0);
    v35 = m_Items[v13]->pm;
    v37 = v35->m_Items[0];
    v43 = m_Items[v13]->pm;
    SDF_GIF_SET_XYZ2(
      primitive,
      &index,
      ITF_MISC_SCREEN_OFFSET_X + v37,
      ITF_MISC_SCREEN_OFFSET_Y + v43->m_Items[1],
      za,
      0,
      0);
    ++v13;
  }
  while (v13 != 4);
  sdfDrawTagLink(pdrawtag, v46);
}

// 0x1596ba0
void itfMiscDrawTrianglePrim(sdfIVector2_t **pvertex, sdfIVector4_t **pcolor, s32 x, s32 y, u32 z, sdfDrawTag_t *pdrawtag) {
  ;
}

// 0x1597fe0
void itfMiscDrawTriangleStripPrim(sdfIVector2_t **pvertex_top, s32 off, sdfIVector4_t **pcolor_top, u8 **pvertindex, u8 **pcolorindex, s32 num, u32 z, sdfDrawTag_t *pdrawtag) {
  sdf2DTexPacket_t_o *v13;
  s32 v14;
  u64 v15;
  sdfPrm_array *primitive;
  s64 v18;
  u8 *v19;
  u8 *v20;
  s64 v25;
  s64 v27;
  sdfIVector4_t_o *v30;
  struct System_Int32_array *pm;
  u32 max_length;
  sdfPrm_array *v33;
  s32 v34;
  struct System_Int32_array *v35;
  s32 v36;
  s32 v37;
  s32 v39;
  struct System_Int32_array *v41;
  s32 v43;
  struct System_Int32_array *v45;
  Il2CppObject *v47;
  sdfIVector2_t_array *v49;
  sdfIVector4_t_array *v50;
  u16 za;
  sdfIVector2_t_o *v54;
  s32 index;

  za = z;
  v13 = Allocate(sdf2DTexPacket_t);
  _ctor(v13, 0);
  v13->primitive = NewSpecific(sdfPrm, (8 * (num >> 1)));
  v14 = SDF_GS_SET_PRIM(4u, 1u, 0, 0, 1u, 0, 0, 0, 0);
  v15 = SDF_GIFTAG_REGS4(1, 5, 1, 5);
  sdf2DMakePrimPacketHeader(v13, v14, 4, v15, num >> 1);
  primitive = v13->primitive;
  v47 = v13;
  index = 0;
  if (num >= 1)
  {
    v18 = off + 32LL;
    v49 = pvertex_top;
    v50 = pcolor_top;
    v19 = pvertindex + v18;
    v20 = pcolorindex + v18;
    do
    {
      v25 = *v19;
      v27 = *v20;
      v54 = pvertex_top->m_Items[v25];
      v30 = pcolor_top->m_Items[v27];
      pm = v30->pm;
      max_length = pm->max_length;
      v33 = primitive;
      v34 = pm->m_Items[0];
      v35 = v30->pm;
      v36 = v30->pm->m_Items[1];
      v37 = v35->m_Items[2];
      v39 = v35->m_Items[3];
      primitive = v33;
      SDF_GIF_SET_RGBA(v33, &index, v34, v36, v37, v39, 0);
      v41 = v54->pm;
      v43 = v41->m_Items[0];
      pcolor_top = v50;
      v45 = v54->pm;
      SDF_GIF_SET_XYZ2(
        primitive,
        &index,
        ITF_MISC_SCREEN_OFFSET_X + v43,
        ITF_MISC_SCREEN_OFFSET_Y + v45->m_Items[1],
        za,
        0,
        0);
      pvertex_top = v49;
      ++v19;
      ++v20;
      ++off;
      --num;
    }
    while (num);
  }
  sdfDrawTagLink(pdrawtag, v47);
}

// 0x1595b90
void itfMiscLinkGive(mesflow_tag *pelem, itfmisclinkstack_t *pstack) {
  struct itfmisclinkheader_t_o *linkheader;
  Il2CppObject *pprev;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  struct mesflow_tag_o *pnext;
  mesflow_tag_c *v12;
  s64 v13;
  char *v14;
  s64 *v15;
  struct mesflow_tag_o **p_fields;
  Il2CppObject *pdisuse_tail;
  struct mesflow_tag_o *pdisuse_top;
  u64 v19[2];
  char *v20;

  linkheader = pelem->linkheader;
  pprev = linkheader->pprev;
  if (pprev)
  {
    klass = pprev->klass;
    if (pprev->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != mesflow_tag)
    {
      sub_8FC2C0(klass->_1.element_class, mesflow_tag, v19);
      if ((v19[0] & 1) != 0)
        v9 = v20;
      else
        v9 = v19 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  pnext = linkheader->pnext;
  if (pnext)
  {
    v12 = pnext->klass;
    if (pnext->klass->_2.typeHierarchyDepth < v13 || v12->_2.typeHierarchy[v13 - 1] != mesflow_tag)
    {
      sub_8FC2C0(v12->_1.element_class, mesflow_tag, v19);
      if ((v19[0] & 1) != 0)
        v14 = v20;
      else
        v14 = v19 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  if (pprev)
  {
    pprev[1].klass->_1.namespaze = pnext;
    if (pnext)
    {
LABEL_19:
      p_fields = &pnext->linkheader->fields;
      goto LABEL_22;
    }
  }
  else
  {
    pstack->puse_top = pnext;
    if (pnext)
      goto LABEL_19;
  }
  p_fields = &pstack->puse_tail;
LABEL_22:
  *p_fields = pprev;
  pelem->linkheader->pnext = 0;
  pdisuse_tail = pstack->pdisuse_tail;
  pelem->linkheader->pprev = pdisuse_tail;
  if (pdisuse_tail)
    pdisuse_tail[1].klass->_1.namespaze = pelem;
  pdisuse_top = pstack->pdisuse_top;
  pstack->pdisuse_tail = pelem;
  if (!pdisuse_top)
    pstack->pdisuse_top = pelem;
}

// 0x1595840
void itfMiscLinkInitialize(itfmisclinkstack_t *pstack, mesflow_tag ***ptop, s32 numelem) {
  u64 v4;
  Il2CppObject *v5;
  Il2CppObject *v8;
  Il2CppClass **v12;
  s64 v14;

  if (numelem >= 1)
  {
    v4 = 0;
    v5 = 0;
    do
    {
      (*ptop)->m_Items[v4]->linkheader->pprev = v5;
      if (numelem - 1 == v4)
      {
        v8 = 0;
      }
      else
      {
        v8 = (*ptop)->m_Items[v4 + 1];
      }
      (*ptop)->m_Items[v4]->linkheader->pnext = v8;
      (*ptop)->m_Items[v4]->linkheader->id = v4;
      v12 = &(*ptop)->obj.klass + v4++;
      v5 = v12[4];
    }
    while (numelem != v4);
  }
  pstack->puse_top = 0;
  pstack->puse_tail = 0;
  pstack->pdisuse_top = (*ptop)->m_Items[0];
  v14 = numelem - 1LL;
  pstack->pdisuse_tail = (*ptop)->m_Items[v14];
}

// 0x15959f0
mesflow_tag *itfMiscLinkTake(itfmisclinkstack_t *pstack) {
  Il2CppObject *pdisuse_top;
  Il2CppClass *klass;
  struct mesflow_tag_o *namespaze;
  mesflow_tag_c *v6;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  pdisuse_top = pstack->pdisuse_top;
  if (pdisuse_top)
  {
    klass = pdisuse_top[1].klass;
    namespaze = klass->_1.namespaze;
    if (namespaze)
    {
      v6 = namespaze->klass;
      if (namespaze->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || v6->_2.typeHierarchy[typeHierarchyDepth - 1] != mesflow_tag)
      {
        sub_8FC2C0(v6->_1.element_class, mesflow_tag, v11);
        if ((v11[0] & 1) != 0)
          v8 = v11[2];
        else
          v8 = v11 + 1;
        v9 = sub_8C4940(v8);
      }
    }
    if (pstack->puse_top)
    {
      klass->_1.name = pstack->puse_tail;
      pstack->puse_tail->linkheader->pnext = pdisuse_top;
      pdisuse_top[1].klass->_1.namespaze = 0;
      pstack->puse_tail = pdisuse_top;
      if (namespaze)
      {
LABEL_13:
        namespaze->linkheader->pprev = 0;
LABEL_20:
        pstack->pdisuse_top = namespaze;
        return pdisuse_top;
      }
    }
    else
    {
      klass->_1.name = 0;
      pstack->puse_top = pdisuse_top;
      pdisuse_top[1].klass->_1.namespaze = 0;
      pstack->puse_tail = pdisuse_top;
      if (namespaze)
        goto LABEL_13;
    }
    pstack->pdisuse_tail = 0;
    goto LABEL_20;
  }
  Write("未使用がもうない\n", 0);
  return pdisuse_top;
}

// 0x15962a0
sdfTexHandle_t *itfMiscLoadTexture(char *filename) {
  sdfTexHandle_t_o *v3;
  s32 IndexOf;
  s32 v5;
  System_String_o *DLCTag;
  s32 Length;
  s32 v8;
  s64 *v9;
  s32 v10;
  System_String_o *v11;
  System_String_o *v12;
  s32 v14;
  s32 fieldID;
  bool IsDLCField;
  s64 *v18;
  System_String_o *v19;
  System_String_o *v20;
  System_String_o *v21;
  s32 v23;
  s64 *v24;
  System_String_o *v25;
  System_String_o *v26;
  s32 v27;
  s32 v28;
  System_String_o *v29;
  s64 *v30;
  s32 v31;
  s64 *v32;
  System_String_array *v33;
  System_String_o *v40;
  System_Object_array *v42;
  AssetBundleCtrl_o *asset_bc;
  UnityEngine_Sprite_array *Sprite;
  struct UnityEngine_Texture2D_array *v46;
  u32 *image;
  s64 v48;
  u64 v49;
  s64 *texture;
  s64 *v52;
  u32 max_length;
  s32 result;

  result = 0;
  v3 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v3);
  IndexOf = LastIndexOf(filename, 0x2Fu, 0);
  v5 = LastIndexOf(filename, 0x2Eu, 0);
  DLCTag = "";
  Length = v5;
  v8 = IndexOf_5260400(filename, "/", 1);
  v9 = &"common";
  if (v8 == -1)
    goto LABEL_33;
  v10 = v8;
  v11 = Substring_5248048(filename, 1, v8 - 1);
  v12 = ToUpper(v11, 0);
  if (!Equals_5234480(v12, "FLD"))
  {
    if (Equals_5234480(v12, "EVENT"))
    {
      v20 = Substring_5248048(filename, v10 + 1, 4);
      result = 0;
      v21 = Substring_5248048(v20, 1, 3);
      if (TryParse(v21, &result, 0))
      {
        v23 = result;
        DLCTag = GetDLCTag(v23);
      }
      if (result == 714)
        DLCTag = "";
      if (result == 715)
      {
        DLCTag = CheckPictureID715(filename);
      }
      v19 = v20;
      goto LABEL_28;
    }
    if (Equals_5234480(v12, "BATTLE"))
      v9 = &"extrar_o";
LABEL_33:
    v24 = *v9;
    v25 = filename;
    goto LABEL_34;
  }
  v14 = IndexOf_5260400(filename, "/", v10 + 1);
  fieldID = fldGb->fieldID;
  IsDLCField = IsDLCField(fieldID);
  v18 = &"m";
  if (!IsDLCField)
    v18 = &"";
  DLCTag = *v18;
  v19 = Substring_5248048(filename, v14 + 1, 4);
LABEL_28:
  v24 = Concat_5224608(v19, DLCTag);
  if (Length == -1)
    Length = get_Length(filename);
  v25 = Substring_5248048(filename, IndexOf + 1, Length + ~IndexOf);
LABEL_34:
  v3->hashname = v25;
  v26 = Concat_5224608("dds3data", filename);
  v27 = LastIndexOf(v26, 0x2Eu, 0);
  if (v27 != -1)
    v26 = Substring_5248048(v26, 0, v27);
  v28 = LastIndexOf(v26, 0x2Fu, 0);
  if (v28 == -1)
  {
    v30 = "";
  }
  else
  {
    v29 = Substring_5248048(v26, 0, v28);
    v30 = Concat_5224608(v29, DLCTag);
  }
  v31 = get_Length(v26);
  v32 = Substring_5248048(v26, v28 + 1, v31 + ~v28);
  v33 = NewSpecific(string, 6u);
  v33->m_Items[0] = "LoadEventPicture : ";
  v33->m_Items[1] = v24;
  v33->m_Items[2] = ",";
  v33->m_Items[3] = v30;
  v33->m_Items[4] = ",";
  v33->m_Items[5] = v32;
  v40 = Concat_5271600(v33);
  v42 = Empty_string_();
  Log(v40, v42, 0);
  asset_bc = get_asset_bc();
  Sprite = LoadSprite(asset_bc, v24, v30, v32);
  v46 = NewSpecific(UnityEngine_Texture2D, LODWORD(Sprite->max_length));
  v3->image = v46;
  if (Sprite->max_length >= 1)
  {
    image = v46;
    v48 = 4;
    v49 = 0;
    while (1)
    {
      texture = get_texture(*(&Sprite->obj.klass + v48), 0);
      v52 = texture;
      *&image[2 * v48] = v52;
      max_length = Sprite->max_length;
      if (v48 - 3 >= max_length)
        break;
      image = v3->image;
      v49 = ++v48 - 4;
    }
  }
  return v3;
}

// 0x1596270
void itfMiscMoveFontPosition(_FRQ *pfont, s32 ofsx, s32 ofsy) {
  s32 y;

  for (; pfont; pfont = pfont->prev)
  {
    y = pfont->y;
    pfont->x += ofsx;
    pfont->y = y + ofsy;
  }
}

// 0x1595d80
void itfMiscSetRatioRGB(sdfIVector4_t ***pout, s32 off, s32 red, s32 green, s32 blue, s32 alpha, sdfIVector4_t **pratio, s32 num) {
  s64 v9;
  s64 v10;
  char *v11;
  s32 v12;
  u32 v15;
  s64 v19;
  sdfIVector4_t_array *v21;
  s32 v22;
  const char *name;
  s32 v25;
  const char *v28;
  const char *v31;
  const char *v34;

  if (num >= 1)
  {
    v9 = 8LL * off + 32;
    v10 = 0;
    v11 = pratio + v9;
    v12 = num + 1;
    do
    {
      v15 = off + v10;
      v19 = *(*&v11[8 * v10] + 16LL);
      v21 = *pout;
      if (*(v19 + 40) * red >= 16711680)
        v22 = 16711680;
      else
        v22 = *(v19 + 40) * red;
      name = (*(&v21->obj.klass + 8 * v10 + v9))->_1.name;
      v25 = v22 >> 16;
      *(name + 8) = v25;
      v28 = (*(&(*pout)->obj.klass + 8 * v10 + v9))->_1.name;
      *(v28 + 9) = 0;
      v31 = (*(&(*pout)->obj.klass + 8 * v10 + v9))->_1.name;
      *(v31 + 10) = 0;
      v34 = (*(&(*pout)->obj.klass + 8 * v10 + v9))->_1.name;
      --v12;
      ++v10;
      *(v34 + 11) = alpha;
    }
    while (v12 > 1);
  }
}
