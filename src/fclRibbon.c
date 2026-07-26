#include "types.h"

typedef struct TMPEffect TMPEffect;
typedef struct fclRibbon_t fclRibbon_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfIVector3_t sdfIVector3_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

void DrawBack(fclRibbon_t *phandle, s32 x, s32 y, u32 z, s32 alpha, sdfDrawTag_t *pdrawtag);
void DrawBackFrame(fclRibbon_t *phandle, s32 x, s32 y, u32 z, s32 alpha, s32 flag, sdfDrawTag_t *pdrawtag);
void DrawElem(fclRibbon_t *phandle, s32 x, s32 y, u32 z, s32 alpha, sdfDrawTag_t *pdrawtag);
void DrawHexagon(fclRibbon_t *phandle, s32 x, s32 y, u32 z, s32 alpha, s32 width, s32 isfix, sdfDrawTag_t *pdrawtag);
void DrawHexagonElem(sdfIVector3_t *std_pos, sdfIVector4_t *color, u32 z, sdfDrawTag_t *pdrawtag);
char *GetLocalizeText(char *ID);
char *RepColTag(char *txt, void **LegacyParamArray);
void SDF_ASSERT(bool result);
void StartEffect(TMPEffect *this, void *obj, s32 mode, s32 tp);
void StopEffect(TMPEffect *this, void *obj);
void itfMiscDrawAlphaPrim(sdfDrawTag_t *pdrawtag, s32 tp, s32 context);
void itfMiscDrawSpritePrim(sdfIVector4_t *pos, sdfIVector4_t *uv, sdfIVector4_t *color, u32 z, sdfTexHandle_t *texhandle, s32 context, sdfDrawTag_t *pdrawtag);
void itfMiscDrawSpritePrim2(sdfIVector4_t *pos, sdfIVector4_t *uv, sdfIVector4_t *color, u32 z, s32 context, sdfDrawTag_t *pdrawtag);
void *sdf2DLinkTexPacket(sdfDrawTag_t *aTag, sdfTexHandle_t *aTexHndl, s32 aCtx);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
s32 sdfDrawTagLinkOt(s32 a, sdfDrawTag_t *b);
void sdfIVector4_t__Copy(sdfIVector4_t *this, sdfIVector4_t *v);
sdfIVector4_t *sdfIVector4_t__Create(s32 x, s32 y, s32 z, s32 w);

// 0x199a460
void DrawBack(fclRibbon_t *phandle, s32 x, s32 y, u32 z, s32 alpha, sdfDrawTag_t *pdrawtag) {
  sdfIVector4_t_o *v13;
  sdfIVector4_t_o *v14;
  sdfIVector4_t_o *v15;
  struct System_Int32_array *pm;
  struct System_Int32_array *v19;
  struct System_Int32_array *v21;
  struct System_Int32_array *v23;
  struct System_Int32_array *v25;
  struct sdfTexHandle_t_array *tex;
  sdfTexHandle_t_o *v29;
  struct System_Int32_array *v30;
  struct System_Int32_array *v32;
  struct System_Int32_array *v34;
  struct System_Int32_array *v36;
  struct System_Int32_array *v38;
  struct System_Int32_array *v40;
  s32 v41;
  struct System_Int32_array *v43;
  struct System_Int32_array *v45;
  s32 v46;
  sdfIVector4_t_o *uv;
  sdfIVector4_t_o *v49;

  v13 = sdfIVector4_t__Create(16, 432, 1776, 464);
  uv = sdfIVector4_t__Create(16, 16, 848, 416);
  v49 = sdfIVector4_t__Create(832, 16, 1664, 416);
  v14 = sdfIVector4_t__Create(128, 128, 128, 128);
  v15 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v15);
  pm = v14->pm;
  pm->m_Items[3] = alpha;
  v19 = v15->pm;
  v19->m_Items[0] = x;
  v21 = v15->pm;
  v21->m_Items[1] = y + 144;
  v23 = v15->pm;
  v23->m_Items[2] = x + 1760;
  v25 = v15->pm;
  v25->m_Items[3] = y + 160;
  tex = phandle->tex;
  v29 = tex->m_Items[0];
  itfMiscDrawSpritePrim(v15, v13, v14, z, v29, 0, pdrawtag);
  v30 = v15->pm;
  v30->m_Items[0] = x + 0x2000;
  v32 = v15->pm;
  v32->m_Items[2] = x + 6432;
  itfMiscDrawSpritePrim2(v15, v13, v14, z, 0, pdrawtag);
  v34 = v15->pm;
  v34->m_Items[0] = x + 480;
  v36 = v15->pm;
  v36->m_Items[1] = y + 48;
  v38 = v15->pm;
  v38->m_Items[2] = x + 1280;
  v40 = v15->pm;
  v41 = y + 248;
  v40->m_Items[3] = v41;
  itfMiscDrawSpritePrim2(v15, uv, v14, z, 0, pdrawtag);
  v43 = v15->pm;
  v43->m_Items[0] = x + 6912;
  v45 = v15->pm;
  v46 = x + 7712;
  v45->m_Items[2] = v46;
  itfMiscDrawSpritePrim2(v15, v49, v14, z, 0, pdrawtag);
}

// 0x1999f00
void DrawBackFrame(fclRibbon_t *phandle, s32 x, s32 y, u32 z, s32 alpha, s32 flag, sdfDrawTag_t *pdrawtag) {
  char v9;
  sdfIVector4_t_o *v15;
  sdfIVector4_t_o *v16;
  sdfIVector4_t_o *v17;
  struct System_Int32_array *v19;
  struct System_Int32_array *v21;
  struct System_Int32_array *v23;
  struct System_Int32_array *v25;
  s32 v26;
  struct System_Int32_array *v28;
  struct sdfTexHandle_t_array *v30;
  sdfTexHandle_t_o *v32;
  struct System_Int32_array *v33;
  struct System_Int32_array *v35;
  s32 v36;
  struct System_Int32_array *v38;
  struct System_Int32_array *v40;
  struct System_Int32_array *v42;
  struct System_Int32_array *v44;
  struct System_Int32_array *pm;
  struct System_Int32_array *v48;
  struct System_Int32_array *v50;
  struct System_Int32_array *v52;
  s32 v53;
  struct sdfTexHandle_t_array *tex;
  sdfTexHandle_t_o *v57;
  struct System_Int32_array *v58;
  struct System_Int32_array *v60;
  struct System_Int32_array *v62;
  struct System_Int32_array *v64;
  struct System_Int32_array *v66;
  struct System_Int32_array *v68;
  s32 v70;
  sdfIVector4_t_o *uv;

  v9 = flag;
  v15 = sdfIVector4_t__Create(2352, 480, 4048, 1072);
  uv = sdfIVector4_t__Create(4032, 480, 4048, 1072);
  v16 = sdfIVector4_t__Create(128, 128, 128, 128);
  v17 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v17);
  if ((v9 & 1) != 0)
  {
    pm = v17->pm;
    pm->m_Items[0] = 0;
    v48 = v17->pm;
    v48->m_Items[1] = y;
    v50 = v17->pm;
    v50->m_Items[2] = 1696;
    v52 = v17->pm;
    v53 = y + 296;
    v52->m_Items[3] = v53;
    tex = phandle->tex;
    v57 = tex->m_Items[0];
    itfMiscDrawSpritePrim(v17, v15, v16, z, v57, 0, pdrawtag);
    v58 = v17->pm;
    v58->m_Items[0] = 0x2000;
    v60 = v17->pm;
    v60->m_Items[2] = 6496;
    itfMiscDrawSpritePrim2(v17, v15, v16, z, 0, pdrawtag);
    v62 = v17->pm;
    v62->m_Items[0] = 1696;
    v64 = v17->pm;
    v64->m_Items[1] = y;
    v66 = v17->pm;
    v66->m_Items[2] = 6496;
    v68 = v17->pm;
    v68->m_Items[3] = v53;
  }
  else
  {
    if (alpha < 1)
      return;
    v19 = v16->pm;
    v19->m_Items[3] = alpha;
    v21 = v17->pm;
    v21->m_Items[0] = x;
    v23 = v17->pm;
    v23->m_Items[1] = y;
    v25 = v17->pm;
    v26 = x + 1696;
    v25->m_Items[2] = v26;
    v28 = v17->pm;
    v70 = y + 296;
    v28->m_Items[3] = v70;
    v30 = phandle->tex;
    v32 = v30->m_Items[0];
    itfMiscDrawSpritePrim(v17, v15, v16, z, v32, 0, pdrawtag);
    v33 = v17->pm;
    v33->m_Items[0] = x + 0x2000;
    v35 = v17->pm;
    v36 = x + 6496;
    v35->m_Items[2] = v36;
    itfMiscDrawSpritePrim2(v17, v15, v16, z, 0, pdrawtag);
    v38 = v17->pm;
    v38->m_Items[0] = v26;
    v40 = v17->pm;
    v40->m_Items[1] = y;
    v42 = v17->pm;
    v42->m_Items[2] = v36;
    v44 = v17->pm;
    v44->m_Items[3] = v70;
  }
  itfMiscDrawSpritePrim2(v17, uv, v16, z, 0, pdrawtag);
}

// 0x199ab90
void DrawElem(fclRibbon_t *phandle, s32 x, s32 y, u32 z, s32 alpha, sdfDrawTag_t *pdrawtag) {
    sdfIVector4_t__Create(0, 0, 0, 0);
    itfMiscDrawSpritePrim(0, 0, 0, 0, 0, 0, 0);
    itfMiscDrawAlphaPrim(0, 0, 0);
}

// 0x199a830
void DrawHexagon(fclRibbon_t *phandle, s32 x, s32 y, u32 z, s32 alpha, s32 width, s32 isfix, sdfDrawTag_t *pdrawtag) {
  sdfIVector4_t_o *v12;
  sdfIVector3_t_o *v13;
  struct System_Int32_array *pm;
  struct sdfTexHandle_t_array *tex;
  s64 num;
  u64 v20;
  s32 v21;
  s32 v22;
  struct System_Int32_array *v23;
  struct System_Int32_array *v24;
  s32 v26;
  struct System_Int32_array *v28;
  struct System_Int32_array *v29;
  s32 v31;
  struct System_Int32_array *v33;
  struct fclribbon_elem_t_array *pelem;
  fclribbon_elem_t_o *v38;
  struct System_Int32_array *v39;
  il2cpp_array_size_t max_length;
  struct System_Int32_array *v41;
  s32 v42;
  struct System_Int32_array *v43;
  s32 v44;
  struct System_Int32_array *v46;
  s32 v47;
  s32 v50;
  s32 v51;

  v12 = sdfIVector4_t__Create(128, 128, 128, 128);
  v13 = Allocate(sdfIVector3_t);
  sdfIVector3_t___ctor(v13);
  pm = v12->pm;
  pm->m_Items[3] = alpha;
  tex = phandle->tex;
  sdf2DLinkTexPacket(pdrawtag, tex->m_Items[1], 0);
  num = phandle->num;
  if (num >= 1)
  {
    v20 = 0;
    v21 = width >> 1;
    v22 = y + 72;
    v50 = width + x;
    v51 = x - width;
    do
    {
      pelem = phandle->pelem;
      v38 = pelem->m_Items[v20];
      if (isfix)
      {
        v39 = v38->pos_deact->pm;
        max_length = v39->max_length;
        v41 = v39;
        v42 = v39->m_Items[0];
        v43 = v13->pm;
        v44 = v42 + x + ((v41->m_Items[2] - v41->m_Items[0]) >> 1);
        v43->m_Items[0] = v44 - v21;
        v46 = v13->pm;
        v47 = v44 + v21;
        v46->m_Items[1] = v47;
        v33 = v13->pm;
        if (LODWORD(v33->max_length) <= 2)
      }
      else
      {
        v23 = v38->pos_deact->pm;
        v24 = v13->pm;
        v26 = v51 + v23->m_Items[0];
        v24->m_Items[0] = v26;
        v28 = v38->pos_deact->pm;
        v29 = v13->pm;
        v31 = v50 + v28->m_Items[2];
        v29->m_Items[1] = v31;
        v33 = v13->pm;
      }
      v33->m_Items[2] = v22;
      DrawHexagonElem(v13, v12, z, pdrawtag);
      ++v20;
    }
    while (num != v20);
  }
}

// 0x199bc60
void DrawHexagonElem(sdfIVector3_t *std_pos, sdfIVector4_t *color, u32 z, sdfDrawTag_t *pdrawtag) {
  sdfIVector4_t_o *v9;
  sdfIVector4_t_o *v10;
  sdfIVector4_t_o *v11;
  struct System_Int32_array *pm;
  struct System_Int32_array *v14;
  s32 v15;
  struct System_Int32_array *v16;
  struct System_Int32_array *v17;
  s32 v19;
  struct System_Int32_array *v21;
  struct System_Int32_array *v22;
  s32 v23;
  struct System_Int32_array *v25;
  struct System_Int32_array *v26;
  s32 v28;
  struct System_Int32_array *v30;
  struct System_Int32_array *v31;
  s32 v32;
  struct System_Int32_array *v33;
  struct System_Int32_array *v34;
  s32 v36;
  struct System_Int32_array *v38;
  struct System_Int32_array *v39;
  s32 v41;
  struct System_Int32_array *v43;
  struct System_Int32_array *v44;
  s32 v46;

  v9 = sdfIVector4_t__Create(2704, 16, 3008, 336);
  v10 = sdfIVector4_t__Create(2992, 16, 3008, 336);
  v11 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v11);
  pm = std_pos->pm;
  v14 = v11->pm;
  v15 = pm->m_Items[0] - 320;
  v14->m_Items[0] = v15;
  v16 = std_pos->pm;
  v17 = v11->pm;
  v19 = v16->m_Items[2];
  v17->m_Items[1] = v19;
  v21 = std_pos->pm;
  v22 = v11->pm;
  v23 = v21->m_Items[0];
  v22->m_Items[2] = v23;
  v25 = std_pos->pm;
  v26 = v11->pm;
  v28 = v25->m_Items[2] + 160;
  v26->m_Items[3] = v28;
  itfMiscDrawSpritePrim2(v11, v9, color, z, 0, pdrawtag);
  v30 = std_pos->pm;
  v31 = v11->pm;
  v32 = v30->m_Items[0];
  v31->m_Items[0] = v32;
  v33 = std_pos->pm;
  v34 = v11->pm;
  v36 = v33->m_Items[1];
  v34->m_Items[2] = v36;
  itfMiscDrawSpritePrim2(v11, v10, color, z, 0, pdrawtag);
  v38 = std_pos->pm;
  v39 = v11->pm;
  v41 = v38->m_Items[1] + 320;
  v39->m_Items[0] = v41;
  v43 = std_pos->pm;
  v44 = v11->pm;
  v46 = v43->m_Items[1];
  v44->m_Items[2] = v46;
  itfMiscDrawSpritePrim2(v11, v9, color, z, 0, pdrawtag);
}

// 0x1999c70
void MoveActive(fclRibbon_t *phandle) {
  s32 v2;
  bool v3;
  u32 v4;

  v2 = phandle->ctr_act - 8;
  v3 = phandle->ctr_act == 8;
  phandle->ctr_act = v2;
  if (v2 < 0 || v3)
  {
    v4 = phandle->stat & 0xFFFFFFFE;
    phandle->ctr_act = 0;
    phandle->stat = v4;
  }
}

// 0x1999ca0
void MoveDeactive(fclRibbon_t *phandle) {
  s32 v2;
  bool v3;
  u32 v4;

  v2 = phandle->ctr_deact - 16;
  v3 = phandle->ctr_deact == 16;
  phandle->ctr_deact = v2;
  if (v2 < 0 || v3)
  {
    v4 = phandle->stat & 0xFFFFFFFD;
    phandle->ctr_deact = 0;
    phandle->stat = v4;
  }
}

// 0x1999b90
void fclRbnCalc(fclRibbon_t *phandle) {
  u32 stat;
  s32 v4;
  bool v5;
  s32 v6;

  SDF_ASSERT(phandle != 0);
  stat = phandle->stat;
  if ((stat & 1) != 0
    && (v4 = phandle->ctr_act - 8, v5 = phandle->ctr_act == 8, phandle->ctr_act = v4, v4 < 0 || v5))
  {
    stat &= ~1u;
    phandle->ctr_act = 0;
    phandle->stat = stat;
    if ((stat & 2) == 0)
  }
  else  v6 = phandle->ctr_deact - 16;
  v5 = phandle->ctr_deact == 16;
  phandle->ctr_deact = v6;
  if (v6 < 0 || v5)
  {
    phandle->ctr_deact = 0;
    phandle->stat = stat & 0xFFFFFFFD;
  }
  phandle->ctr = (phandle->ctr + 126) & 0x7F;
}

// 0x1999cd0
void fclRbnDraw(fclRibbon_t *phandle, s32 x, s32 y, u32 z, s32 alpha, s32 flag, s32 widthofs, s32 ot_index) {
  u64 *v17;
  struct sdfGrOt_t_array *dds3Ot;
  sdfGrOt_t_o *v27;

  v17 = Allocate(sdfDrawTag_t);
  sdfDrawTag_t___ctor(v17);
  SDF_ASSERT(phandle != 0);
  if (flag & 1 | alpha)
  {
    sdfDrawTagInit(v17);
    DrawBackFrame(phandle, x, y, z, alpha, flag, v17);
    if (alpha >= 1)
    {
      if ((flag & 2) == 0)
        DrawBack(phandle, x, y, z, alpha, v17);
      DrawHexagon(phandle, x, y, z, alpha, widthofs, (flag >> 2) & 1, v17);
      DrawElem(phandle, x, y, z, alpha, v17);
    }
    v27 = dds3Ot->m_Items[ot_index];
    sdfDrawTagLinkOt(v27, v17);
  }
}

// 0x1999510
fclRibbon_t *fclRbnInit(s32 num, s32 act, sdfTexHandle_t *tex0, sdfTexHandle_t *tex1) {
    SDF_ASSERT(0);
    return 0;
}

// 0x1998790
fclRibbon_t *fclRbnInitSort(s32 act) {
    GetLocalizeText(0);
    RepColTag(0, 0);
    return 0;
}

// 0x1999b80
void fclRbnRelease(fclRibbon_t *phandle) {
  ;
}

// 0x199b9d0
void fclRbnSetPara(fclRibbon_t *phandle, s32 index, sdfIVector4_t *ppos_act, sdfIVector4_t *ppos_deact, sdfIVector4_t *puv_act, sdfIVector4_t *puv_deact, sdfTexHandle_t *tex_act, sdfTexHandle_t *tex_deact) {
  struct fclribbon_elem_t_array *pelem;
  struct fclribbon_elem_t_array *v19;
  struct fclribbon_elem_t_array *v21;
  struct fclribbon_elem_t_array *v23;
  struct fclribbon_elem_t_array *v25;
  struct sdfTexHandle_t_array *tex;
  struct fclribbon_elem_t_array *v29;
  struct sdfTexHandle_t_array *v31;

  SDF_ASSERT(phandle != 0);
  if ((index & 0x80000000) == 0 && phandle->num > index)
  {
    pelem = phandle->pelem;
    sdfIVector4_t__Copy(pelem->m_Items[index]->pos_act, ppos_act);
    v19 = phandle->pelem;
    sdfIVector4_t__Copy(v19->m_Items[index]->pos_deact, ppos_deact);
    v21 = phandle->pelem;
    sdfIVector4_t__Copy(v21->m_Items[index]->uv_act, puv_act);
    v23 = phandle->pelem;
    sdfIVector4_t__Copy(v23->m_Items[index]->uv_deact, puv_deact);
    v25 = phandle->pelem;
    tex = v25->m_Items[index]->tex;
    tex->m_Items[0] = tex_act;
    v29 = phandle->pelem;
    v31 = v29->m_Items[index]->tex;
    v31->m_Items[1] = tex_deact;
  }
}

// 0x199b730
void fclRbnSwitchActive(fclRibbon_t *phandle, s32 index) {
    SDF_ASSERT(0);
    StartEffect(0, 0, 0, 0);
}

// 0x1998d40
void fclRbnSwitchActiveSort(fclRibbon_t *phandle, s32 index) {
    SDF_ASSERT(0);
    GetLocalizeText(0);
    RepColTag(0, 0);
    StartEffect(0, 0, 0, 0);
    StopEffect(0, 0);
}
