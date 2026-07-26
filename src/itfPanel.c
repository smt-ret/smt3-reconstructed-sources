#include "types.h"

typedef struct _FRQ _FRQ;
typedef struct itfPanelTypeWork_t itfPanelTypeWork_t;
typedef struct itfPanel_g_pdrawDelegate itfPanel_g_pdrawDelegate;
typedef struct itfpanel_t itfpanel_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrOt_t sdfGrOt_t;
typedef struct sdfIVector2_t sdfIVector2_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static sdfIVector4_t *g_uv_top;
static sdfIVector4_t *g_uv_mid;
static sdfIVector4_t *g_uv_btm;
static sdfIVector4_t *g_uv_all;
static s32 CreateVertexMesWin_plinestep[3];
static sdfIVector4_t *CreateColorMesWin_pratio[6];
static sdfIVector4_t *CreateColorSelWin_pratio[4];
static sdfIVector4_t *CreateColorPlain_pratio_back[1];
static sdfIVector4_t *CreateColorPlain_pratio[2];
static u8 *DrawNormal_s_ppindexlist[3];
static u8 *DrawNormal_s_ppcolorlist[3];
static u8 *DrawMesWin_s_ppindexlist[3];
static u8 *DrawMesWin_s_ppcolorlist[3];
static u8 DrawMesWin_s_plinevertlist[4];
static u8 *DrawMesWin_s_pplinecollist[6];
static u8 *DrawSelWin_s_ppindexlist[3];
static u8 *DrawSelWin_s_ppcolorlist[3];
static u8 DrawSelWin_s_plinevertlist[4];
static u8 *DrawSelWin_s_pplinecollist[4];
static u8 DrawPlain_s_pindexlist[4];
static u8 DrawPlain_s_pcolorlist[4];
static u8 *DrawPlain_s_ppindexlistframe[3];
static u8 *DrawPlain_s_ppcolorlistframe[3];
static u8 DrawPera1_s_pindexlist[4];
static u8 DrawPera1_s_pcolorlist[4];
static u8 DrawLeftFade_s_pindexlist[6];
static u8 DrawLeftFade_s_pcolorlist[6];
static u8 *DrawFacility_ppindexlist[3];
static u8 *DrawFacility_ppcolorlist[3];
static itfPanel_g_pdrawDelegate *g_pdraw[9];

s32 CMP_X(s32 a);
s32 CMP_XM(s32 a);
void CreateColorFacility(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha);
void CreateColorLeftFade(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha);
void CreateColorMesWin(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha);
void CreateColorNormal(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha);
void CreateColorPera1(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha);
void CreateColorPlain(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha);
void CreateColorSelWin(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha);
void CreateVertexFacility(itfPanelTypeWork_t *pwork, s32 x0, s32 y0, s32 x1, s32 y1);
void CreateVertexLeftFade(itfPanelTypeWork_t *pwork, s32 x0, s32 y0, s32 x1, s32 y1);
void CreateVertexMesWin(itfPanelTypeWork_t *pwork, s32 x0, s32 y0, s32 x1, s32 y1);
void CreateVertexNormal(itfPanelTypeWork_t *pwork, s32 x0, s32 y0, s32 x1, s32 y1);
void CreateVertexPlain(itfPanelTypeWork_t *pwork, s32 x0, s32 y0, s32 x1, s32 y1);
void CreateVertexSelWin(itfPanelTypeWork_t *pwork, s32 x0, s32 y0, s32 x1, s32 y1);
void Draw(s32 x, s32 y, _FRQ *frq, s32 colno);
void DrawTestAlphaPrim(sdfDrawTag_t *pdrawtag);
s32 SDF_GS_SET_ALPHA(s32 a, s32 b, s32 c, s32 d, s32 fix);
u64 SDF_GS_SET_TEST(u8 ate, u8 atst, u8 aref, u8 afail, u8 date, u8 datm, u8 zte, u32 ztst);
void itfMiscDrawAlphaPrim(sdfDrawTag_t *pdrawtag, s32 tp, s32 context);
void itfMiscDrawLineStripPrim(sdfIVector2_t **pvertex_top, s32 off, sdfIVector4_t **pcolor_top, u8 **pvertindex, u8 **pcolorindex, s32 num, u32 z, sdfDrawTag_t *pdrawtag);
void itfMiscDrawRectanglePrim(sdfIVector2_t **pvertex_top, s32 off, sdfIVector4_t **pcolor_top, u8 **pvertindex, u8 **pcolorindex, u32 z, sdfDrawTag_t *pdrawtag);
void itfMiscDrawSpritePrim(sdfIVector4_t *pos, sdfIVector4_t *uv, sdfIVector4_t *color, u32 z, sdfTexHandle_t *texhandle, s32 context, sdfDrawTag_t *pdrawtag);
void itfMiscDrawTriangleStripPrim(sdfIVector2_t **pvertex_top, s32 off, sdfIVector4_t **pcolor_top, u8 **pvertindex, u8 **pcolorindex, s32 num, u32 z, sdfDrawTag_t *pdrawtag);
void itfMiscSetRatioRGB(sdfIVector4_t ***pout, s32 off, s32 red, s32 green, s32 blue, s32 alpha, sdfIVector4_t **pratio, s32 num);
s32 sdfDrawTagInit(sdfDrawTag_t *a);

// 0x159e410
void CreateColorFacility(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha) {
  struct sdfIVector4_t_array *pcolor;
  struct System_Int32_array *pm;
  struct System_Int32_array *v8;
  struct System_Int32_array *v11;
  struct System_Int32_array *v14;
  struct System_Int32_array *v15;
  struct System_Int32_array *v17;
  struct System_Int32_array *v20;
  struct System_Int32_array *v23;

  pcolor = pwork->pcolor;
  pm = pcolor->m_Items[0]->pm;
  pm->m_Items[0] = 115;
  v8 = pcolor->m_Items[0]->pm;
  v8->m_Items[1] = 135;
  v11 = pcolor->m_Items[0]->pm;
  v11->m_Items[2] = 255;
  v14 = pcolor->m_Items[0]->pm;
  v14->m_Items[3] = 0;
  v15 = pcolor->m_Items[1]->pm;
  v15->m_Items[0] = 115;
  v17 = pcolor->m_Items[1]->pm;
  v17->m_Items[1] = 135;
  v20 = pcolor->m_Items[1]->pm;
  v20->m_Items[2] = 255;
  v23 = pcolor->m_Items[1]->pm;
  v23->m_Items[3] = 0;
}

// 0x159e170
void CreateColorLeftFade(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha) {
  struct sdfIVector4_t_array *pcolor;
  struct System_Int32_array *pm;
  struct System_Int32_array *v8;
  struct System_Int32_array *v11;
  struct System_Int32_array *v14;
  struct System_Int32_array *v15;
  struct System_Int32_array *v17;
  struct System_Int32_array *v20;
  struct System_Int32_array *v23;

  pcolor = pwork->pcolor;
  pm = pcolor->m_Items[0]->pm;
  pm->m_Items[0] = red;
  v8 = pcolor->m_Items[0]->pm;
  v8->m_Items[1] = green;
  v11 = pcolor->m_Items[0]->pm;
  v11->m_Items[2] = blue;
  v14 = pcolor->m_Items[0]->pm;
  v14->m_Items[3] = 0;
  v15 = pcolor->m_Items[1]->pm;
  v15->m_Items[0] = red;
  v17 = pcolor->m_Items[1]->pm;
  v17->m_Items[1] = green;
  v20 = pcolor->m_Items[1]->pm;
  v20->m_Items[2] = blue;
  v23 = pcolor->m_Items[1]->pm;
  v23->m_Items[3] = alpha;
}

// 0x159d760
void CreateColorMesWin(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha) {
  struct sdfIVector4_t_array *pcolor;
  struct System_Int32_array *pm;
  struct System_Int32_array *v13;
  struct System_Int32_array *v16;
  struct System_Int32_array *v19;
  struct System_Int32_array *v21;
  struct System_Int32_array *v23;
  struct System_Int32_array *v26;
  struct System_Int32_array *v29;
  sdfIVector4_t_array *CreateColorMesWin_pratio;
  sdfIVector4_t_array *pout;

  if ((byte_3F59E8C & 1) != 0)
  {
    pcolor = pwork->pcolor;
    pout = pcolor;
    if (LODWORD(pcolor->max_length))
  }
  pcolor = pwork->pcolor;
  pout = pcolor;
  if (!LODWORD(pcolor->max_length))
  pm = pcolor->m_Items[0]->pm;
  pm->m_Items[0] = red;
  v13 = pcolor->m_Items[0]->pm;
  v13->m_Items[1] = green;
  v16 = pcolor->m_Items[0]->pm;
  v16->m_Items[2] = blue;
  v19 = pcolor->m_Items[0]->pm;
  v19->m_Items[3] = 1;
  v21 = pcolor->m_Items[1]->pm;
  v21->m_Items[0] = red;
  v23 = pcolor->m_Items[1]->pm;
  v23->m_Items[1] = green;
  v26 = pcolor->m_Items[1]->pm;
  v26->m_Items[2] = blue;
  v29 = pcolor->m_Items[1]->pm;
  v29->m_Items[3] = alpha;
  itfMiscSetRatioRGB(&pout, 2, red, blue, alpha, alpha, CreateColorMesWin_pratio, 6);
}

// 0x159d4c0
void CreateColorNormal(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha) {
  struct sdfIVector4_t_array *pcolor;
  struct System_Int32_array *pm;
  struct System_Int32_array *v8;
  struct System_Int32_array *v11;
  struct System_Int32_array *v14;
  struct System_Int32_array *v15;
  struct System_Int32_array *v17;
  struct System_Int32_array *v20;
  struct System_Int32_array *v23;

  pcolor = pwork->pcolor;
  pm = pcolor->m_Items[0]->pm;
  pm->m_Items[0] = red;
  v8 = pcolor->m_Items[0]->pm;
  v8->m_Items[1] = green;
  v11 = pcolor->m_Items[0]->pm;
  v11->m_Items[2] = blue;
  v14 = pcolor->m_Items[0]->pm;
  v14->m_Items[3] = 0;
  v15 = pcolor->m_Items[1]->pm;
  v15->m_Items[0] = red;
  v17 = pcolor->m_Items[1]->pm;
  v17->m_Items[1] = green;
  v20 = pcolor->m_Items[1]->pm;
  v20->m_Items[2] = blue;
  v23 = pcolor->m_Items[1]->pm;
  v23->m_Items[3] = alpha;
}

// 0x159e010
void CreateColorPera1(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha) {
  struct sdfIVector4_t_array *pcolor;
  struct System_Int32_array *pm;
  struct System_Int32_array *v8;
  struct System_Int32_array *v11;
  struct System_Int32_array *v14;

  pcolor = pwork->pcolor;
  pm = pcolor->m_Items[0]->pm;
  pm->m_Items[0] = red;
  v8 = pcolor->m_Items[0]->pm;
  v8->m_Items[1] = green;
  v11 = pcolor->m_Items[0]->pm;
  v11->m_Items[2] = blue;
  v14 = pcolor->m_Items[0]->pm;
  v14->m_Items[3] = alpha;
}

// 0x159dde0
void CreateColorPlain(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha) {
  struct sdfIVector4_t_array *pcolor;
  struct System_Int32_array *pm;
  struct System_Int32_array *v13;
  struct System_Int32_array *v16;
  struct System_Int32_array *v19;
  sdfIVector4_t_array *CreateColorPlain_pratio_back;
  s32 v23;
  s32 v24;
  sdfIVector4_t_array *pout;

  if ((byte_3F59E8E & 1) != 0)
  {
    pcolor = pwork->pcolor;
    pout = pcolor;
    if (LODWORD(pcolor->max_length))
  }
  pcolor = pwork->pcolor;
  pout = pcolor;
  if (!LODWORD(pcolor->max_length))
  pm = pcolor->m_Items[0]->pm;
  pm->m_Items[0] = red;
  v13 = pcolor->m_Items[0]->pm;
  v13->m_Items[1] = green;
  v16 = pcolor->m_Items[0]->pm;
  v16->m_Items[2] = blue;
  v19 = pcolor->m_Items[0]->pm;
  v19->m_Items[3] = alpha;
  itfMiscSetRatioRGB(&pout, 1, red, blue, alpha, alpha, CreateColorPlain_pratio_back, 1);
  itfMiscSetRatioRGB(&pout, 2, red, v23, v24, 128, CreateColorPlain_pratio, 2);
}

// 0x159daa0
void CreateColorSelWin(itfPanelTypeWork_t *pwork, s32 red, s32 green, s32 blue, s32 alpha) {
  struct sdfIVector4_t_array *pcolor;
  struct System_Int32_array *pm;
  struct System_Int32_array *v13;
  struct System_Int32_array *v16;
  struct System_Int32_array *v19;
  struct System_Int32_array *v21;
  struct System_Int32_array *v23;
  struct System_Int32_array *v26;
  struct System_Int32_array *v29;
  sdfIVector4_t_array *CreateColorSelWin_pratio;
  sdfIVector4_t_array *pout;

  if ((byte_3F59E8D & 1) != 0)
  {
    pcolor = pwork->pcolor;
    pout = pcolor;
    if (LODWORD(pcolor->max_length))
  }
  pcolor = pwork->pcolor;
  pout = pcolor;
  if (!LODWORD(pcolor->max_length))
  pm = pcolor->m_Items[0]->pm;
  pm->m_Items[0] = red;
  v13 = pcolor->m_Items[0]->pm;
  v13->m_Items[1] = green;
  v16 = pcolor->m_Items[0]->pm;
  v16->m_Items[2] = blue;
  v19 = pcolor->m_Items[0]->pm;
  v19->m_Items[3] = 1;
  v21 = pcolor->m_Items[1]->pm;
  v21->m_Items[0] = red;
  v23 = pcolor->m_Items[1]->pm;
  v23->m_Items[1] = green;
  v26 = pcolor->m_Items[1]->pm;
  v26->m_Items[2] = blue;
  v29 = pcolor->m_Items[1]->pm;
  v29->m_Items[3] = alpha;
  itfMiscSetRatioRGB(&pout, 2, red, blue, alpha, alpha, CreateColorSelWin_pratio, 4);
}

// 0x159d100
void CreateVertexFacility(itfPanelTypeWork_t *pwork, s32 x0, s32 y0, s32 x1, s32 y1) {
  u32 *v9;
  u32 *v10;
  struct sdfIVector2_t_array *pvertex;
  u32 v12;
  u32 v14;
  s32 v15;
  s32 v16;
  u64 v18;
  u64 v19;
  sdfIVector2_t_o **v20;
  u32 *v21;
  struct System_Int32_array *pm;
  struct System_Int32_array *v30;
  struct System_Int32_array *v33;
  struct System_Int32_array *v35;
  u64 v37;

  v9 = NewSpecific(s32, 4u);
  v10 = NewSpecific(s32, 2u);
  pvertex = pwork->pvertex;
  v12 = v9[6];
  v9[8] = 416;
  v9[9] = 1152;
  v9[10] = 7024;
  v9[11] = 7760;
  v14 = v10[6];
  v15 = y0 + 352;
  v10[8] = v15;
  v16 = y1 - 320;
  v18 = 0;
  v19 = 0;
  v10[9] = v16;
  v20 = &pvertex->m_Items[1];
  v21 = v9 + 8;
  do
  {
    pm = (*(v20 - 1))->pm;
    pm->m_Items[0] = v21[v19];
    v30 = (*(v20 - 1))->pm;
    v30->m_Items[1] = v10[8];
    v33 = (*v20)->pm;
    v33->m_Items[0] = v21[v19];
    v35 = (*v20)->pm;
    v37 = v18 + 2;
    v35->m_Items[1] = v10[9];
    ++v19;
    v20 += 2;
    v18 += 2LL;
  }
  while (v37 != 8);
}

// 0x159cca0
void CreateVertexLeftFade(itfPanelTypeWork_t *pwork, s32 x0, s32 y0, s32 x1, s32 y1) {
  struct sdfIVector2_t_array *pvertex;
  u32 *v12;
  u32 *v13;
  u32 v14;
  u32 v15;
  u64 v17;
  u64 v18;
  u64 v27;
  Il2CppClass **v29;
  const char *name;
  u32 *v32;
  const char *v33;
  u64 v36;
  const char *v38;
  const char *v40;
  u64 v43;
  const char *v45;
  const char *v47;
  s32 v48;

  pvertex = pwork->pvertex;
  v12 = NewSpecific(s32, 3u);
  v13 = NewSpecific(s32, 2u);
  v14 = v12[6];
  v12[8] = x0;
  v12[9] = x1 - 1440;
  v12[10] = x1;
  v15 = v13[6];
  v13[8] = y0;
  v17 = 0;
  v18 = 0;
  v13[9] = y1;
  do
  {
    v27 = v18;
    v29 = &pvertex->obj.klass + v17;
    name = v29[4]->_1.name;
    *(name + 8) = v12[8];
    v32 = &v13[v18 + 8];
    v33 = v29[4]->_1.name;
    *(v33 + 9) = *v32;
    v36 = v17 + 1;
    v38 = v29[5]->_1.name;
    *(v38 + 8) = v12[9];
    v40 = v29[5]->_1.name;
    *(v40 + 9) = *v32;
    v43 = v36 + 1;
    v45 = v29[6]->_1.name;
    *(v45 + 8) = v12[10];
    v47 = v29[6]->_1.name;
    v48 = *v32;
    v17 = v43 + 1;
    v18 = 1;
    *(v47 + 9) = v48;
  }
  while (!v27);
}

// 0x159abd0
void CreateVertexMesWin(itfPanelTypeWork_t *pwork, s32 x0, s32 y0, s32 x1, s32 y1) {
}

// 0x159a810
void CreateVertexNormal(itfPanelTypeWork_t *pwork, s32 x0, s32 y0, s32 x1, s32 y1) {
  u32 *v10;
  struct sdfIVector2_t_array *pvertex;
  u32 v12;
  s32 v13;
  s32 v14;
  s32 v19;
  u32 v20;
  u64 v23;
  u64 v24;
  sdfIVector2_t_o **v25;
  u32 *v26;
  struct System_Int32_array *pm;
  struct System_Int32_array *v34;
  struct System_Int32_array *v37;
  struct System_Int32_array *v39;
  bool v41;

  v10 = NewSpecific(s32, 4u);
  pvertex = pwork->pvertex;
  v12 = v10[6];
  v10[8] = x0;
  v10[9] = x0 + 512;
  v10[10] = x1 - 512;
  v14 = v10[9];
  v13 = v10[10];
  v10[11] = x1;
  if (v14 > v13)
  {
    v19 = x0 + ((x1 - x0) >> 1);
    v20 = v10[6];
    v10[9] = v19;
    v10[10] = v19;
  }
  v23 = 0;
  v24 = 0;
  v25 = &pvertex->m_Items[1];
  v26 = v10 + 8;
  do
  {
    pm = (*(v25 - 1))->pm;
    pm->m_Items[0] = v26[v24];
    v34 = (*(v25 - 1))->pm;
    v34->m_Items[1] = y0;
    v37 = (*v25)->pm;
    v37->m_Items[0] = v26[v24];
    v39 = (*v25)->pm;
    ++v24;
    v25 += 2;
    v41 = v23 == 6;
    v23 += 2LL;
    v39->m_Items[1] = y1;
  }
  while (!v41);
}

// 0x159c9a0
void CreateVertexPlain(itfPanelTypeWork_t *pwork, s32 x0, s32 y0, s32 x1, s32 y1) {
  struct sdfIVector2_t_array *pvertex;
  struct System_Int32_array *pm;
  struct System_Int32_array *v8;
  struct System_Int32_array *v9;
  struct System_Int32_array *v11;
  struct System_Int32_array *v12;
  struct System_Int32_array *v14;
  struct System_Int32_array *v15;
  struct System_Int32_array *v17;

  pvertex = pwork->pvertex;
  pm = pvertex->m_Items[0]->pm;
  pm->m_Items[0] = x0;
  v8 = pvertex->m_Items[0]->pm;
  v8->m_Items[1] = y0;
  v9 = pvertex->m_Items[1]->pm;
  v9->m_Items[0] = x1;
  v11 = pvertex->m_Items[1]->pm;
  v11->m_Items[1] = y0;
  v12 = pvertex->m_Items[2]->pm;
  v12->m_Items[0] = x1;
  v14 = pvertex->m_Items[2]->pm;
  v14->m_Items[1] = y1;
  v15 = pvertex->m_Items[3]->pm;
  v15->m_Items[0] = x0;
  v17 = pvertex->m_Items[3]->pm;
  v17->m_Items[1] = y1;
}

// 0x159bae0
void CreateVertexSelWin(itfPanelTypeWork_t *pwork, s32 x0, s32 y0, s32 x1, s32 y1) {
  u32 *v11;
  u32 *v12;
  struct sdfIVector2_t_array *pvertex;
  u32 v14;
  u32 v17;
  u64 v21;
  il2cpp_array_size_t *p_max_length;
  sdfIVector2_t_o **v23;
  struct System_Int32_array *pm;
  struct System_Int32_array *v38;
  struct System_Int32_array *v41;
  struct System_Int32_array *v43;
  struct System_Int32_array *v46;
  struct System_Int32_array *v48;
  struct System_Int32_array *v52;
  struct System_Int32_array *v54;
  bool v56;
  u32 v57;
  u64 v60;
  s32 v61;
  s32 v76;
  Il2CppClass **v78;
  const char *name;
  const char *v81;
  s32 v82;
  u64 v85;
  const char *v87;
  const char *v88;
  u64 v90;
  const char *v92;
  const char *v93;
  u64 v95;
  const char *v97;
  const char *v98;
  s32 v99;
  u64 v102;
  s32 v103;
  s32 v118;
  Il2CppClass **v120;
  const char *v121;
  const char *v123;
  s32 v124;
  u64 v127;
  const char *v129;
  const char *v130;
  u64 v132;
  const char *v134;
  const char *v135;
  u64 v137;
  const char *v139;
  const char *v140;
  s32 v141;
  s32 v149;
  s32 v150;
  s32 v151;

  v11 = NewSpecific(s32, 4u);
  v12 = NewSpecific(s32, 4u);
  pvertex = pwork->pvertex;
  v14 = v11[6];
  v11[8] = x0 - 256;
  v11[9] = x0 + 512;
  v11[10] = x1 - 512;
  v11[11] = x1 + 256;
  v17 = v12[6];
  v150 = x1;
  v12[8] = y0 - 128;
  v12[9] = y0 + 128;
  v149 = x1 + 256;
  v151 = y1;
  v12[10] = y1 - 128;
  v21 = 0;
  v12[11] = y1 + 128;
  p_max_length = &pvertex->max_length;
  v23 = &pvertex->m_Items[3];
  do
  {
    pm = (*(v23 - 3))->pm;
    pm->m_Items[0] = v11[8];
    v38 = (*(v23 - 3))->pm;
    v38->m_Items[1] = v12[8];
    v41 = (*(v23 - 2))->pm;
    v41->m_Items[0] = v11[9];
    v43 = (*(v23 - 2))->pm;
    v43->m_Items[1] = v12[9];
    v46 = (*(v23 - 1))->pm;
    v46->m_Items[0] = v11[10];
    v48 = (*(v23 - 1))->pm;
    v48->m_Items[1] = v12[10];
    v52 = (*v23)->pm;
    v52->m_Items[0] = v11[11];
    v54 = (*v23)->pm;
    v23 += 4;
    v56 = v21 == 12;
    v21 += 4LL;
    v54->m_Items[1] = v12[11];
  }
  while (!v56);
  v57 = v11[6];
  v11[8] = x0 - 256;
  v11[9] = x0 + 1024;
  v11[10] = v150 - 1024;
  v11[11] = v149;
  v60 = 0;
  v61 = 0;
  v12[8] = y0;
  do
  {
    v76 = v61;
    v78 = &pvertex->obj.klass + v60;
    name = v78[4]->_1.name;
    *(name + 8) = v11[8];
    v81 = v78[4]->_1.name;
    v82 = 8 * v61;
    *(v81 + 9) = v12[8] + v82;
    v85 = v60 + 1;
    v87 = v78[5]->_1.name;
    *(v87 + 8) = v11[9];
    v88 = v78[5]->_1.name;
    *(v88 + 9) = v12[8] + v82;
    v90 = v85 + 1;
    v92 = v78[6]->_1.name;
    *(v92 + 8) = v11[10];
    v93 = v78[6]->_1.name;
    *(v93 + 9) = v12[8] + v82;
    v95 = v90 + 1;
    v97 = v78[7]->_1.name;
    *(v97 + 8) = v11[11];
    v98 = v78[7]->_1.name;
    v99 = v12[8] + v82;
    v60 = v95 + 1;
    v61 = 1;
    *(v98 + 9) = v99;
  }
  while (!v76);
  v102 = 0;
  v103 = 0;
  v12[8] = v151;
  do
  {
    v118 = v103;
    v120 = &pvertex->obj.klass + v102;
    v121 = v120[4]->_1.name;
    *(v121 + 8) = v11[8];
    v123 = v120[4]->_1.name;
    v124 = 8 * v103;
    *(v123 + 9) = v12[8] - v124;
    v127 = v102 + 1;
    v129 = v120[5]->_1.name;
    *(v129 + 8) = v11[9];
    v130 = v120[5]->_1.name;
    *(v130 + 9) = v12[8] - v124;
    v132 = v127 + 1;
    v134 = v120[6]->_1.name;
    *(v134 + 8) = v11[10];
    v135 = v120[6]->_1.name;
    *(v135 + 9) = v12[8] - v124;
    v137 = v132 + 1;
    v139 = v120[7]->_1.name;
    *(v139 + 8) = v11[11];
    v140 = v120[7]->_1.name;
    v141 = v12[8] - v124;
    v102 = v137 + 1;
    v103 = 1;
    *(v140 + 9) = v141;
  }
  while (!v118);
}

// 0x15a1110
void DrawFacility(itfpanel_t *handle, sdfDrawTag_t *pdrawtag) {
  struct itfPanelTypeWork_t_o *pwork;
  struct sdfIVector4_t_array *pcolor;
  sdfIVector2_t_array *pvertex;
  struct System_Int32_array *pm;
  struct System_Int32_array *v11;
  s32 v13;
  struct itfPanel_StaticFields *static_fields;
  struct System_Byte_array_array *DrawFacility_ppindexlist;
  struct System_Byte_array_array *DrawFacility_ppcolorlist;
  System_Byte_array *v18;
  System_Byte_array *v19;
  u32 z;
  itfPanel_c *v23;
  struct itfPanel_StaticFields *v24;
  struct System_Byte_array_array *v25;
  struct System_Byte_array_array *v27;
  System_Byte_array *v28;
  System_Byte_array *v30;
  u32 v31;
  itfPanel_c *v34;
  struct itfPanel_StaticFields *v35;
  struct System_Byte_array_array *v36;
  struct System_Byte_array_array *v38;
  System_Byte_array *v39;
  System_Byte_array *v41;
  u32 v42;
  struct System_Int32_array *v45;
  struct sdfIVector4_t_o *pos;
  sdfIVector4_t_o *g_uv_all;
  struct sdfIVector4_t_o *color;
  u32 v51;
  sdfTexHandle_t_o *texhandle;
  sdfIVector4_t_o *v53;
  sdfIVector4_t_o *g_uv_btm;
  sdfIVector4_t_o *v55;
  u32 v56;
  sdfTexHandle_t_o *v57;
  Il2CppObject *v58;
  struct System_Int32_array *v61;
  il2cpp_array_size_t max_length;
  s32 v63;
  Il2CppClass *klass;
  struct System_Int32_array *v65;
  Il2CppClass *v66;
  s32 v68;
  struct System_Int32_array *v70;
  Il2CppClass *v71;
  s32 v73;
  Il2CppClass *v75;
  sdfIVector4_t_o *g_uv_top;
  sdfIVector4_t_o *v79;
  u32 v80;
  sdfTexHandle_t_o *v81;
  Il2CppClass *v83;
  Il2CppClass *v85;
  s32 v86;
  Il2CppClass *v88;
  struct System_Int32_array *v90;
  Il2CppClass *v91;
  s32 v93;
  s32 v100;

  pwork = handle->pwork;
  pvertex = pwork->pvertex;
  pcolor = pwork->pcolor;
  pm = pcolor->m_Items[1]->pm;
  v11 = handle->color->pm;
  v13 = v11->m_Items[3] >> 2;
  pm->m_Items[3] = v13;
  static_fields = itfPanel->static_fields;
  DrawFacility_ppindexlist = static_fields->DrawFacility_ppindexlist;
  if (!LODWORD(DrawFacility_ppindexlist->max_length))
  DrawFacility_ppcolorlist = static_fields->DrawFacility_ppcolorlist;
  v18 = DrawFacility_ppindexlist->m_Items[0];
  v19 = DrawFacility_ppcolorlist->m_Items[0];
  z = handle->z;
  itfMiscDrawRectanglePrim(pvertex, 0, pcolor, v18, v19, z >> 4, pdrawtag);
  v24 = v23->static_fields;
  v25 = v24->DrawFacility_ppindexlist;
  v27 = v24->DrawFacility_ppcolorlist;
  v28 = v25->m_Items[1];
  v30 = v27->m_Items[1];
  v31 = handle->z;
  itfMiscDrawRectanglePrim(pvertex, 0, pcolor, v28, v30, v31 >> 4, pdrawtag);
  v35 = v34->static_fields;
  v36 = v35->DrawFacility_ppindexlist;
  v38 = v35->DrawFacility_ppcolorlist;
  v39 = v36->m_Items[2];
  v41 = v38->m_Items[2];
  v42 = handle->z;
  itfMiscDrawRectanglePrim(pvertex, 0, pcolor, v39, v41, v42 >> 4, pdrawtag);
  v45 = handle->pos->pm;
  if (v45->m_Items[3] - v45->m_Items[1] < 1385)
  {
    pos = handle->pos;
    color = handle->color;
    v51 = handle->z;
    texhandle = pwork->texhandle;
    v53 = pos;
    g_uv_btm = g_uv_all;
    v55 = color;
    v56 = v51;
    v57 = texhandle;
  }
  else
  {
    v58 = Allocate(sdfIVector4_t);
    v58[1].klass = NewSpecific(s32, 4u);
    _ctor(v58, 0);
    v61 = handle->pos->pm;
    max_length = v61->max_length;
    v63 = v61->m_Items[1];
    klass = v58[1].klass;
    v100 = handle->pos->pm->m_Items[3];
    LODWORD(klass->_1.byval_arg.data) = handle->pos->pm->m_Items[0];
    v65 = handle->pos->pm;
    v66 = v58[1].klass;
    v68 = v65->m_Items[1];
    HIDWORD(v66->_1.byval_arg.data) = v68;
    v70 = handle->pos->pm;
    v71 = v58[1].klass;
    v73 = v63 + 692;
    v71->_1.byval_arg.bits = v70->m_Items[2];
    v75 = v58[1].klass;
    *(&v75->_1.byval_arg.bits + 1) = v73;
    v79 = handle->color;
    v80 = handle->z;
    v81 = pwork->texhandle;
    itfMiscDrawSpritePrim(v58, g_uv_top, v79, v80, v81, 0, pdrawtag);
    v83 = v58[1].klass;
    HIDWORD(v83->_1.byval_arg.data) = v73;
    v85 = v58[1].klass;
    v86 = v100 - 692;
    *(&v85->_1.byval_arg.bits + 1) = v86;
    itfMiscDrawSpritePrim(v58, g_uv_mid, handle->color, handle->z, pwork->texhandle, 0, pdrawtag);
    v88 = v58[1].klass;
    HIDWORD(v88->_1.byval_arg.data) = v86;
    v90 = handle->pos->pm;
    v91 = v58[1].klass;
    v93 = v90->m_Items[3];
    *(&v91->_1.byval_arg.bits + 1) = v93;
    v55 = handle->color;
    v56 = handle->z;
    v57 = pwork->texhandle;
    v53 = v58;
  }
  itfMiscDrawSpritePrim(v53, g_uv_btm, v55, v56, v57, 0, pdrawtag);
}

// 0x159fe40
void DrawLeftFade(itfpanel_t *handle, sdfDrawTag_t *pdrawtag) {
  struct System_Int32_array *pm;
  s32 v8;
  struct sdfIVector4_t_array *pcolor;
  struct System_Int32_array *v11;
  sdfIVector2_t_array *pvertex;

  pm = handle->color->pm;
  v8 = pm->m_Items[3];
  pcolor = handle->pwork->pcolor;
  v11 = pcolor->m_Items[1]->pm;
  v11->m_Items[3] = v8;
  pvertex = handle->pwork->pvertex;
  itfMiscDrawAlphaPrim(pdrawtag, 2, 0);
  itfMiscDrawTriangleStripPrim(pvertex, 0, pcolor, DrawLeftFade_s_pindexlist, DrawLeftFade_s_pcolorlist, 6, handle->z, pdrawtag);
  itfMiscDrawAlphaPrim(pdrawtag, 0, 0);
}

// 0x159e9c0
void DrawMesWin(itfpanel_t *handle, sdfDrawTag_t *pdrawtag) {
  struct System_Int32_array *pm;
  struct sdfIVector4_t_array *pcolor;
  s32 v7;
  struct System_Int32_array *v9;
  struct System_Int32_array *v12;
  struct System_Int32_array *v15;
  struct System_Int32_array *v18;
  struct System_Int32_array *v21;
  struct System_Int32_array *v24;
  struct System_Int32_array *v27;
  sdfIVector2_t_array *pvertex;
  struct itfPanel_StaticFields *static_fields;
  struct System_Byte_array_array *DrawMesWin_s_ppindexlist;
  System_Byte_array *v32;
  struct System_Byte_array_array *DrawMesWin_s_ppcolorlist;
  System_Byte_array *v34;
  u32 z;
  itfPanel_c *v37;
  struct itfPanel_StaticFields *v38;
  struct System_Byte_array_array *v39;
  System_Byte_array *v41;
  struct System_Byte_array_array *v42;
  System_Byte_array *v44;
  u32 v45;
  itfPanel_c *v47;
  struct itfPanel_StaticFields *v48;
  struct System_Byte_array_array *v49;
  System_Byte_array *v51;
  struct System_Byte_array_array *v52;
  System_Byte_array *v54;
  u32 v55;
  u64 v57;
  s32 v58;
  itfPanel_c *v59;
  struct itfPanel_StaticFields *v60;
  System_Byte_array *DrawMesWin_s_plinevertlist;
  struct System_Byte_array_array *DrawMesWin_s_pplinecollist;
  System_Byte_array *v64;
  u32 v65;

  pm = handle->color->pm;
  pcolor = handle->pwork->pcolor;
  v7 = pm->m_Items[3];
  v9 = pcolor->m_Items[1]->pm;
  v9->m_Items[3] = v7;
  v12 = pcolor->m_Items[2]->pm;
  v12->m_Items[3] = v7;
  v15 = pcolor->m_Items[3]->pm;
  v15->m_Items[3] = v7;
  v18 = pcolor->m_Items[4]->pm;
  v18->m_Items[3] = v7;
  v21 = pcolor->m_Items[5]->pm;
  v21->m_Items[3] = v7;
  v24 = pcolor->m_Items[6]->pm;
  v24->m_Items[3] = v7;
  v27 = pcolor->m_Items[7]->pm;
  v27->m_Items[3] = v7;
  pvertex = handle->pwork->pvertex;
  static_fields = itfPanel->static_fields;
  DrawMesWin_s_ppindexlist = static_fields->DrawMesWin_s_ppindexlist;
  if (!LODWORD(DrawMesWin_s_ppindexlist->max_length))
  v32 = DrawMesWin_s_ppindexlist->m_Items[0];
  DrawMesWin_s_ppcolorlist = static_fields->DrawMesWin_s_ppcolorlist;
  v34 = DrawMesWin_s_ppcolorlist->m_Items[0];
  z = handle->z;
  itfMiscDrawTriangleStripPrim(pvertex, 0, pcolor, v32, v34, 8, z, pdrawtag);
  v38 = v37->static_fields;
  v39 = v38->DrawMesWin_s_ppindexlist;
  v41 = v39->m_Items[1];
  v42 = v38->DrawMesWin_s_ppcolorlist;
  v44 = v42->m_Items[1];
  v45 = handle->z;
  itfMiscDrawTriangleStripPrim(pvertex, 0, pcolor, v41, v44, 8, v45, pdrawtag);
  v48 = v47->static_fields;
  v49 = v48->DrawMesWin_s_ppindexlist;
  v51 = v49->m_Items[2];
  v52 = v48->DrawMesWin_s_ppcolorlist;
  v54 = v52->m_Items[2];
  v55 = handle->z;
  itfMiscDrawTriangleStripPrim(pvertex, 0, pcolor, v51, v54, 8, v55, pdrawtag);
  v57 = 0;
  v58 = 16;
  do
  {
    v60 = v59->static_fields;
    DrawMesWin_s_plinevertlist = v60->DrawMesWin_s_plinevertlist;
    DrawMesWin_s_pplinecollist = v60->DrawMesWin_s_pplinecollist;
    v64 = DrawMesWin_s_pplinecollist->m_Items[v57];
    v65 = handle->z;
    itfMiscDrawLineStripPrim(pvertex, v58, pcolor, DrawMesWin_s_plinevertlist, v64, 4, v65, pdrawtag);
    ++v57;
    v58 += 4;
  }
  while (v57 != 6);
}

// 0x159ffa0
void DrawMesWin2(itfpanel_t *handle, sdfDrawTag_t *pdrawtag) {
    sdfDrawTagInit(0);
    DrawTestAlphaPrim(0);
    itfMiscDrawSpritePrim(0, 0, 0, 0, 0, 0, 0);
    Draw(0, 0, 0, 0);
}

// 0x159e6b0
void DrawNormal(itfpanel_t *handle, sdfDrawTag_t *pdrawtag) {
  struct itfPanelTypeWork_t_o *pwork;
  struct sdfIVector4_t_array *pcolor;
  sdfIVector2_t_array *pvertex;
  struct System_Int32_array *pm;
  struct System_Int32_array *v11;
  s32 v13;
  struct itfPanel_StaticFields *static_fields;
  struct System_Byte_array_array *DrawNormal_s_ppindexlist;
  struct System_Byte_array_array *DrawNormal_s_ppcolorlist;
  System_Byte_array *v18;
  System_Byte_array *v19;
  u32 z;
  itfPanel_c *v23;
  struct itfPanel_StaticFields *v24;
  struct System_Byte_array_array *v25;
  struct System_Byte_array_array *v27;
  System_Byte_array *v28;
  System_Byte_array *v30;
  u32 v31;
  itfPanel_c *v34;
  struct itfPanel_StaticFields *v35;
  struct System_Byte_array_array *v36;
  struct System_Byte_array_array *v38;
  System_Byte_array *v39;
  System_Byte_array *v41;
  u32 v42;

  pwork = handle->pwork;
  pvertex = pwork->pvertex;
  pcolor = pwork->pcolor;
  pm = pcolor->m_Items[1]->pm;
  v11 = handle->color->pm;
  v13 = v11->m_Items[3];
  pm->m_Items[3] = v13;
  static_fields = itfPanel->static_fields;
  DrawNormal_s_ppindexlist = static_fields->DrawNormal_s_ppindexlist;
  if (!LODWORD(DrawNormal_s_ppindexlist->max_length))
  DrawNormal_s_ppcolorlist = static_fields->DrawNormal_s_ppcolorlist;
  v18 = DrawNormal_s_ppindexlist->m_Items[0];
  v19 = DrawNormal_s_ppcolorlist->m_Items[0];
  z = handle->z;
  itfMiscDrawRectanglePrim(pvertex, 0, pcolor, v18, v19, z >> 4, pdrawtag);
  v24 = v23->static_fields;
  v25 = v24->DrawNormal_s_ppindexlist;
  v27 = v24->DrawNormal_s_ppcolorlist;
  v28 = v25->m_Items[1];
  v30 = v27->m_Items[1];
  v31 = handle->z;
  itfMiscDrawRectanglePrim(pvertex, 0, pcolor, v28, v30, v31 >> 4, pdrawtag);
  v35 = v34->static_fields;
  v36 = v35->DrawNormal_s_ppindexlist;
  v38 = v35->DrawNormal_s_ppcolorlist;
  v39 = v36->m_Items[2];
  v41 = v38->m_Items[2];
  v42 = handle->z;
  itfMiscDrawRectanglePrim(pvertex, 0, pcolor, v39, v41, v42 >> 4, pdrawtag);
}

// 0x159fd00
void DrawPera1(itfpanel_t *handle, sdfDrawTag_t *pdrawtag) {
  struct itfPanelTypeWork_t_o *pwork;
  struct sdfIVector4_t_array *pcolor;
  sdfIVector2_t_array *pvertex;
  struct System_Int32_array *pm;
  struct System_Int32_array *v11;
  s32 v13;
  itfPanel_c *v15;
  struct itfPanel_StaticFields *static_fields;
  System_Byte_array *DrawPera1_s_pindexlist;
  System_Byte_array *DrawPera1_s_pcolorlist;
  u32 z;

  pwork = handle->pwork;
  pvertex = pwork->pvertex;
  pcolor = pwork->pcolor;
  pm = pcolor->m_Items[0]->pm;
  v11 = handle->color->pm;
  v13 = v11->m_Items[3];
  pm->m_Items[3] = v13;
  static_fields = v15->static_fields;
  DrawPera1_s_pindexlist = static_fields->DrawPera1_s_pindexlist;
  DrawPera1_s_pcolorlist = static_fields->DrawPera1_s_pcolorlist;
  z = handle->z;
  itfMiscDrawRectanglePrim(pvertex, 0, pcolor, DrawPera1_s_pindexlist, DrawPera1_s_pcolorlist, z >> 4, pdrawtag);
}

// 0x159f480
void DrawPlain(itfpanel_t *handle, sdfDrawTag_t *pdrawtag) {
  sdfIVector2_t_array *v3;
  struct itfPanelTypeWork_t_o *pwork;
  u64 v7;
  struct sdfIVector2_t_array *pvertex;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  sdfIVector2_t_o **v13;
  struct System_Int32_array *pm;
  struct System_Int32_array *v28;
  struct System_Int32_array *v30;
  struct System_Int32_array *v32;
  s32 v34;
  struct System_Int32_array *v37;
  struct System_Int32_array *v38;
  s32 v39;
  struct System_Int32_array *v41;
  struct System_Int32_array *v43;
  s32 v45;
  struct System_Int32_array *v48;
  struct System_Int32_array *v49;
  s32 v50;
  struct System_Int32_array *v52;
  struct System_Int32_array *v54;
  s32 v56;
  struct System_Int32_array *v59;
  struct System_Int32_array *v60;
  s32 v61;
  struct System_Int32_array *v63;
  struct System_Int32_array *v65;
  s32 v67;
  itfPanel_c *v69;
  sdfDrawTag_t_o *v70;
  itfpanel_t_o *v71;
  sdfIVector4_t_array *v72;
  struct itfPanel_StaticFields *static_fields;
  System_Byte_array *DrawPlain_s_pindexlist;
  System_Byte_array *DrawPlain_s_pcolorlist;
  u32 z;
  struct itfPanel_StaticFields *v78;
  struct System_Byte_array_array *DrawPlain_s_ppindexlistframe;
  System_Byte_array *v80;
  struct System_Byte_array_array *DrawPlain_s_ppcolorlistframe;
  System_Byte_array *v82;
  u32 v83;
  itfPanel_c *v85;
  struct itfPanel_StaticFields *v86;
  struct System_Byte_array_array *v87;
  System_Byte_array *v89;
  struct System_Byte_array_array *v90;
  System_Byte_array *v92;
  u32 v93;
  itfPanel_c *v95;
  struct itfPanel_StaticFields *v96;
  struct System_Byte_array_array *v97;
  System_Byte_array *v99;
  struct System_Byte_array_array *v100;
  System_Byte_array *v102;
  u32 v103;
  sdfIVector4_t_array *pcolor_top;
  sdfIVector2_t_array *pvertex_top;

  v3 = NewSpecific(sdfIVector2_t, 0xCu);
  pwork = handle->pwork;
  v7 = 0;
  pvertex = pwork->pvertex;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = &v3->m_Items[3];
  pcolor_top = pwork->pcolor;
  pvertex_top = v3;
  do
  {
    pm = (*(v13 - 3))->pm;
    v28 = pvertex->m_Items[0]->pm;
    pm->m_Items[0] = v10 + v28->m_Items[0];
    v30 = (*(v13 - 3))->pm;
    v32 = pvertex->m_Items[0]->pm;
    v34 = v12 + v32->m_Items[1];
    v30->m_Items[1] = v34;
    v37 = (*(v13 - 2))->pm;
    v38 = pvertex->m_Items[1]->pm;
    v39 = v9 + v38->m_Items[0];
    v37->m_Items[0] = v39;
    v41 = (*(v13 - 2))->pm;
    v43 = pvertex->m_Items[1]->pm;
    v45 = v12 + v43->m_Items[1];
    v41->m_Items[1] = v45;
    v48 = (*(v13 - 1))->pm;
    v49 = pvertex->m_Items[2]->pm;
    v50 = v9 + v49->m_Items[0];
    v48->m_Items[0] = v50;
    v52 = (*(v13 - 1))->pm;
    v54 = pvertex->m_Items[2]->pm;
    v56 = v11 + v54->m_Items[1];
    v52->m_Items[1] = v56;
    v59 = (*v13)->pm;
    v60 = pvertex->m_Items[3]->pm;
    v61 = v10 + v60->m_Items[0];
    v59->m_Items[0] = v61;
    v63 = (*v13)->pm;
    v65 = pvertex->m_Items[3]->pm;
    v67 = v11 + v65->m_Items[1];
    v7 += 4LL;
    v12 += 8;
    v11 -= 8;
    v10 += 16;
    v9 -= 16;
    v63->m_Items[1] = v67;
    v13 += 4;
  }
  while (v7 != 12);
  {
    v70 = pdrawtag;
    v71 = handle;
    v72 = pcolor_top;
  }
  else
  {
    v70 = pdrawtag;
    v71 = handle;
    v72 = pcolor_top;
  }
  static_fields = v69->static_fields;
  DrawPlain_s_pindexlist = static_fields->DrawPlain_s_pindexlist;
  DrawPlain_s_pcolorlist = static_fields->DrawPlain_s_pcolorlist;
  z = v71->z;
  itfMiscDrawRectanglePrim(pvertex, 0, v72, DrawPlain_s_pindexlist, DrawPlain_s_pcolorlist, z >> 4, v70);
  v78 = itfPanel->static_fields;
  DrawPlain_s_ppindexlistframe = v78->DrawPlain_s_ppindexlistframe;
  if (!LODWORD(DrawPlain_s_ppindexlistframe->max_length))
  v80 = DrawPlain_s_ppindexlistframe->m_Items[0];
  DrawPlain_s_ppcolorlistframe = v78->DrawPlain_s_ppcolorlistframe;
  v82 = DrawPlain_s_ppcolorlistframe->m_Items[0];
  v83 = v71->z;
  itfMiscDrawLineStripPrim(pvertex_top, 0, v72, v80, v82, 5, v83, v70);
  v86 = v85->static_fields;
  v87 = v86->DrawPlain_s_ppindexlistframe;
  v89 = v87->m_Items[1];
  v90 = v86->DrawPlain_s_ppcolorlistframe;
  v92 = v90->m_Items[1];
  v93 = v71->z;
  itfMiscDrawLineStripPrim(pvertex_top, 0, v72, v89, v92, 5, v93, v70);
  v96 = v95->static_fields;
  v97 = v96->DrawPlain_s_ppindexlistframe;
  v99 = v97->m_Items[2];
  v100 = v96->DrawPlain_s_ppcolorlistframe;
  v102 = v100->m_Items[2];
  v103 = v71->z;
  itfMiscDrawLineStripPrim(pvertex_top, 0, v72, v99, v102, 5, v103, v70);
}

// 0x159ef20
void DrawSelWin(itfpanel_t *handle, sdfDrawTag_t *pdrawtag) {
    itfMiscDrawTriangleStripPrim(0, 0, 0, 0, 0, 0, 0, 0);
    itfMiscDrawLineStripPrim(0, 0, 0, 0, 0, 0, 0, 0);
}

// 0x15a0800
void DrawSpkWin2(itfpanel_t *handle, sdfDrawTag_t *pdrawtag) {
    CMP_XM(0);
    CMP_X(0);
    sdfDrawTagInit(0);
    DrawTestAlphaPrim(0);
    itfMiscDrawSpritePrim(0, 0, 0, 0, 0, 0, 0);
    Draw(0, 0, 0, 0);
}

// 0x15a0720
void DrawTestAlphaPrim(sdfDrawTag_t *pdrawtag) {
  packettestalpha_tag_o *v2;
  u64 *v3;
  struct sdfGrTagStdReg_t_o *test;
  struct sdfGrTagStdReg_t_o *alpha;

  v2 = Allocate(packettestalpha_tag);
  _ctor(v2, 0);
  v3 = Allocate(packettestalpha_tag);
  _ctor(v3, 0);
  test = v2->test;
  test->data = SDF_GS_SET_TEST(1u, 5u, 1u, 1u, 0, 0, 1u, 2u);
  v2->test->reg = 71;
  alpha = v2->alpha;
  alpha->data = SDF_GS_SET_ALPHA(0, 1u, 0, 1u, 0);
  v2->alpha->reg = 66;
}

// 0x15a2b70
void itfPnlDraw(itfpanel_t *handle, sdfGrOt_t *pot) {
  ;
}

// 0x15a2b80
void itfPnlDrawTag(itfpanel_t *handle, sdfDrawTag_t *pdrawtag) {
  struct itfPanel_g_pdrawDelegate_array *g_pdraw;
  s64 type;

  type = handle->type;
  Invoke(g_pdraw->m_Items[type], handle, pdrawtag);
}

// 0x15a1870
itfpanel_t *itfPnlRegist2(s32 type, sdfTexHandle_t *texhandle) {
  itfpanel_t_o *v5;
  itfPanelTypeWork_t_o *v6;

  v5 = Allocate(itfpanel_t);
  itfpanel_t___ctor(v5);
  v5->type = type;
  v6 = Allocate(itfPanelTypeWork_t);
  _ctor(v6);
  v5->pwork = v6;
  if (texhandle && (type == 8 || type == 7 || type == 6))
    v6->texhandle = texhandle;
  return v5;
}

// 0x15a1be0
void itfPnlRelease(itfpanel_t *handle) {
  u64 *v3;

  v3 = Allocate(sdfMemHandle_t);
  _ctor(v3, 0);
  if (handle)
  {
    if (handle->pwork)
      handle->pwork = 0;
  }
}

// 0x15a2840
void itfPnlSetColor(itfpanel_t *handle, s32 r, s32 g, s32 b, s32 a) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v13;
  struct System_Int32_array *v15;
  struct System_Int32_array *v17;
  itfPanelTypeWork_t_o *pwork;
  itfPanelTypeWork_t_o *v20;
  itfPanelTypeWork_t_o *v21;
  itfPanelTypeWork_t_o *v22;
  itfPanelTypeWork_t_o *v23;
  itfPanelTypeWork_t_o *v24;
  itfPanelTypeWork_t_o *v25;

  pm = handle->color->pm;
  pm->m_Items[0] = r;
  v13 = handle->color->pm;
  v13->m_Items[1] = g;
  v15 = handle->color->pm;
  v15->m_Items[2] = b;
  v17 = handle->color->pm;
  v17->m_Items[3] = a;
  switch (handle->type)
  {
    case 0:
      pwork = handle->pwork;
      CreateColorNormal(pwork, r, g, b, a);
      break;
    case 1:
      v20 = handle->pwork;
      CreateColorMesWin(v20, r, g, b, a);
      break;
    case 2:
      v21 = handle->pwork;
      CreateColorSelWin(v21, r, g, b, a);
      break;
    case 3:
      v22 = handle->pwork;
      CreateColorPlain(v22, r, g, b, a);
      break;
    case 4:
      v23 = handle->pwork;
      CreateColorPera1(v23, r, g, b, a);
      break;
    case 5:
      v24 = handle->pwork;
      CreateColorLeftFade(v24, r, g, b, a);
      break;
    case 8:
      v25 = handle->pwork;
      CreateColorFacility(v25, r, g, b, a);
      break;
    default:
      return;
  }
}

// 0x15a1c60
void itfPnlSetPosition(itfpanel_t *handle, s32 x0, s32 y0, s32 x1, s32 y1, u32 z) {
  struct System_Int32_array *pm;
  struct System_Int32_array *v15;
  struct System_Int32_array *v17;
  struct System_Int32_array *v19;
  s32 type;
  itfPanelTypeWork_t_o *v22;
  itfPanelTypeWork_t_o *pwork;
  itfPanelTypeWork_t_o *v24;
  itfPanelTypeWork_t_o *v25;
  itfPanelTypeWork_t_o *v26;
  itfPanelTypeWork_t_o *v27;

  pm = handle->pos->pm;
  pm->m_Items[0] = x0;
  v15 = handle->pos->pm;
  v15->m_Items[1] = y0;
  v17 = handle->pos->pm;
  v17->m_Items[2] = x1;
  v19 = handle->pos->pm;
  v19->m_Items[3] = y1;
  type = handle->type;
  handle->z = z;
  switch (type)
  {
    case 0:
      pwork = handle->pwork;
      CreateVertexNormal(pwork, x0, y0, x1, y1, *&z);
      break;
    case 1:
      v24 = handle->pwork;
      CreateVertexMesWin(v24, x0, y0, x1, y1, *&z);
      break;
    case 2:
      v25 = handle->pwork;
      CreateVertexSelWin(v25, x0, y0, x1, y1, *&z);
      break;
    case 3:
    case 4:
      v22 = handle->pwork;
      CreateVertexPlain(v22, x0, y0, x1, y1, *&z);
      break;
    case 5:
      v26 = handle->pwork;
      CreateVertexLeftFade(v26, x0, y0, x1, y1, *&z);
      break;
    case 8:
      v27 = handle->pwork;
      CreateVertexFacility(v27, x0, y0, x1, y1, *&z);
      break;
    default:
      return;
  }
}

// 0x15a1f70
void itfPnlSetPositionOffset(itfpanel_t *handle, s32 x0, s32 y0, s32 x1, s32 y1, u32 z) {
  struct sdfIVector4_t_o **p_pos;
  struct System_Int32_array *pm;
  struct System_Int32_array *v15;
  struct System_Int32_array *v17;
  struct System_Int32_array *v19;
  s32 type;
  itfPanelTypeWork_t_o *v22;
  struct System_Int32_array *v23;
  u32 v24;
  struct System_Int32_array *v25;
  s32 v26;
  struct System_Int32_array *v27;
  s32 v28;
  struct System_Int32_array *v29;
  s32 v30;
  s32 v32;
  itfPanelTypeWork_t_o *pwork;
  struct System_Int32_array *v35;
  u32 max_length;
  struct System_Int32_array *v37;
  s32 v38;
  struct System_Int32_array *v39;
  s32 v40;
  struct System_Int32_array *v41;
  s32 v42;
  s32 v44;
  itfPanelTypeWork_t_o *v45;
  struct System_Int32_array *v46;
  u32 v47;
  struct System_Int32_array *v48;
  s32 v49;
  struct System_Int32_array *v50;
  s32 v51;
  struct System_Int32_array *v52;
  s32 v53;
  s32 v55;
  itfPanelTypeWork_t_o *v56;
  struct System_Int32_array *v57;
  u32 v58;
  struct System_Int32_array *v59;
  s32 v60;
  struct System_Int32_array *v61;
  s32 v62;
  struct System_Int32_array *v63;
  s32 v64;
  s32 v66;
  itfPanelTypeWork_t_o *v67;
  struct System_Int32_array *v68;
  u32 v69;
  struct System_Int32_array *v70;
  s32 v71;
  struct System_Int32_array *v72;
  s32 v73;
  struct System_Int32_array *v74;
  s32 v75;
  s32 v77;
  itfPanelTypeWork_t_o *v78;
  struct System_Int32_array *v79;
  u32 v80;
  struct System_Int32_array *v81;
  s32 v82;
  s32 v84;

  p_pos = &handle->pos;
  pm = handle->pos->pm;
  pm->m_Items[0] += x0;
  v15 = (*p_pos)->pm;
  v15->m_Items[1] += y0;
  v17 = (*p_pos)->pm;
  v17->m_Items[2] += x1;
  v19 = (*p_pos)->pm;
  v19->m_Items[3] += y1;
  type = handle->type;
  handle->z += z;
  switch (type)
  {
    case 0:
      pwork = handle->pwork;
      v35 = handle->pos->pm;
      max_length = v35->max_length;
      v37 = v35;
      v38 = v35->m_Items[0];
      v39 = v37;
      v40 = v37->m_Items[1];
      v41 = v39;
      v42 = v39->m_Items[2];
      v44 = v41->m_Items[3];
      CreateVertexNormal(pwork, v38, v40, v42, v44, *&z);
      break;
    case 1:
      v45 = handle->pwork;
      v46 = handle->pos->pm;
      v47 = v46->max_length;
      v48 = v46;
      v49 = v46->m_Items[0];
      v50 = v48;
      v51 = v48->m_Items[1];
      v52 = v50;
      v53 = v50->m_Items[2];
      v55 = v52->m_Items[3];
      CreateVertexMesWin(v45, v49, v51, v53, v55, *&z);
      break;
    case 2:
      v56 = handle->pwork;
      v57 = handle->pos->pm;
      v58 = v57->max_length;
      v59 = v57;
      v60 = v57->m_Items[0];
      v61 = v59;
      v62 = v59->m_Items[1];
      v63 = v61;
      v64 = v61->m_Items[2];
      v66 = v63->m_Items[3];
      CreateVertexSelWin(v56, v60, v62, v64, v66, *&z);
      break;
    case 3:
    case 4:
      v22 = handle->pwork;
      v23 = handle->pos->pm;
      v24 = v23->max_length;
      v25 = v23;
      v26 = v23->m_Items[0];
      v27 = v25;
      v28 = v25->m_Items[1];
      v29 = v27;
      v30 = v27->m_Items[2];
      v32 = v29->m_Items[3];
      CreateVertexPlain(v22, v26, v28, v30, v32, *&z);
      break;
    case 5:
      v67 = handle->pwork;
      v68 = handle->pos->pm;
      v69 = v68->max_length;
      v70 = v68;
      v71 = v68->m_Items[0];
      v72 = v70;
      v73 = v70->m_Items[1];
      v74 = v72;
      v75 = v72->m_Items[2];
      v77 = v74->m_Items[3];
      CreateVertexLeftFade(v67, v71, v73, v75, v77, *&z);
      break;
    case 8:
      v78 = handle->pwork;
      v79 = handle->pos->pm;
      v80 = v79->max_length;
      v81 = v79;
      v82 = v79->m_Items[1];
      v84 = v81->m_Items[3];
      CreateVertexFacility(v78, x0, v82, x1, v84, *&z);
      break;
    default:
      return;
  }
}
