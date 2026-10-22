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
  sdfIVector4_t_o *v11;
  sdfIVector4_t_o *v12;
  struct System_Int32_array *pm;
  s64 num;
  u64 i;
  struct fclribbon_elem_t_array *pelem;
  fclribbon_elem_t_o *v24;
  struct System_Int32_array *v25;
  struct System_Int32_array *v26;
  s32 v27;
  struct System_Int32_array *v28;
  struct System_Int32_array *v29;
  s32 v31;
  struct System_Int32_array *v33;
  struct System_Int32_array *v34;
  s32 v36;
  struct System_Int32_array *v38;
  struct System_Int32_array *v39;
  s32 v41;
  sdfIVector4_t_o *uv_deact;
  struct sdfTexHandle_t_array *tex;
  sdfTexHandle_t_o *v44;
  struct System_Int32_array *v47;
  struct System_Int32_array *v48;
  s32 v49;
  struct System_Int32_array *v50;
  struct System_Int32_array *v51;
  s32 v53;
  struct System_Int32_array *v55;
  struct System_Int32_array *v56;
  s32 v58;
  struct System_Int32_array *v60;
  struct System_Int32_array *v61;
  s32 v63;
  sdfIVector4_t_o *uv_act;
  struct sdfTexHandle_t_array *v66;
  sdfTexHandle_t_o *v68;
  struct fclribbon_elem_t_array *v69;
  fclribbon_elem_t_o *v71;
  struct System_Int32_array *v72;
  struct System_Int32_array *v74;
  struct System_Int32_array *v75;
  s32 v76;
  struct System_Int32_array *v77;
  struct System_Int32_array *v78;
  s32 v80;
  struct System_Int32_array *v82;
  struct System_Int32_array *v83;
  s32 v85;
  struct System_Int32_array *v87;
  struct System_Int32_array *v88;
  s32 v90;
  sdfIVector4_t_o *v92;
  struct sdfTexHandle_t_array *v93;
  sdfTexHandle_t_o *v95;
  s32 ctr;
  struct fclribbon_elem_t_array *v99;
  s32 ctr_act;
  fclribbon_elem_t_o *v102;
  struct System_Int32_array *v103;
  struct System_Int32_array *v105;
  struct System_Int32_array *v106;
  s32 v108;
  s32 v109;
  struct System_Int32_array *v111;
  struct System_Int32_array *v112;
  s32 v114;
  s32 v115;
  struct System_Int32_array *v117;
  struct System_Int32_array *v118;
  s32 v120;
  struct System_Int32_array *v122;
  struct System_Int32_array *v123;
  s32 v125;
  sdfIVector4_t_o *v127;
  struct sdfTexHandle_t_array *v128;
  sdfTexHandle_t_o *v130;
  struct fclribbon_elem_t_array *v131;
  fclribbon_elem_t_o *v133;
  struct System_Int32_array *v134;
  s32 v136;
  struct System_Int32_array *v137;
  struct System_Int32_array *v138;
  s32 v140;
  s32 v141;
  struct System_Int32_array *v143;
  struct System_Int32_array *v144;
  s32 v146;
  s32 v147;
  struct System_Int32_array *v149;
  struct System_Int32_array *v150;
  s32 v152;
  struct System_Int32_array *v154;
  struct System_Int32_array *v155;
  s32 v157;
  sdfIVector4_t_o *v159;
  struct sdfTexHandle_t_array *v160;
  sdfTexHandle_t_o *v162;
  s32 v165;
  sdfIVector4_t_o *v167;

  v11 = sdfIVector4_t__Create(128, 128, 128, 128);
  v12 = Allocate(sdfIVector4_t);
  sdfIVector4_t___ctor(v12);
  v167 = v11;
  pm = v11->pm;
  pm->m_Items[3] = alpha;
  num = phandle->num;
  v165 = alpha;
  if (num >= 1)
  {
    for (i = 0; i != num; ++i)
    {
      pelem = phandle->pelem;
      v24 = pelem->m_Items[i];
      v25 = v24->pos_deact->pm;
      v26 = v12->pm;
      v27 = v25->m_Items[0] + x;
      v26->m_Items[0] = v27;
      v28 = v24->pos_deact->pm;
      v29 = v12->pm;
      v31 = v28->m_Items[1] + y;
      v29->m_Items[1] = v31;
      v33 = v24->pos_deact->pm;
      v34 = v12->pm;
      v36 = v33->m_Items[2] + x;
      v34->m_Items[2] = v36;
      v38 = v24->pos_deact->pm;
      v39 = v12->pm;
      v41 = v38->m_Items[3] + y;
      v39->m_Items[3] = v41;
      uv_deact = v24->uv_deact;
      tex = v24->tex;
      v44 = tex->m_Items[0];
      itfMiscDrawSpritePrim(v12, uv_deact, v167, z, v44, 0, pdrawtag);
      if (i == phandle->act)
      {
        v47 = v24->pos_act->pm;
        v48 = v12->pm;
        v49 = v47->m_Items[0] + x;
        v48->m_Items[0] = v49;
        v50 = v24->pos_act->pm;
        v51 = v12->pm;
        v53 = v50->m_Items[1] + y;
        v51->m_Items[1] = v53;
        v55 = v24->pos_act->pm;
        v56 = v12->pm;
        v58 = v55->m_Items[2] + x;
        v56->m_Items[2] = v58;
        v60 = v24->pos_act->pm;
        v61 = v12->pm;
        v63 = v60->m_Items[3] + y;
        v61->m_Items[3] = v63;
        uv_act = v24->uv_act;
        v66 = v24->tex;
        v68 = v66->m_Items[1];
        itfMiscDrawSpritePrim(v12, uv_act, v167, z, v68, 0, pdrawtag);
      }
    }
  }
  if ((phandle->stat & 2) != 0)
  {
    v69 = phandle->pelem;
    v71 = v69->m_Items[phandle->deact];
    v72 = v167->pm;
    v72->m_Items[3] = (phandle->ctr_deact * v165) >> 7;
    v74 = v71->pos_act->pm;
    v75 = v12->pm;
    v76 = v74->m_Items[0] + x;
    v75->m_Items[0] = v76;
    v77 = v71->pos_act->pm;
    v78 = v12->pm;
    v80 = v77->m_Items[1] + y;
    v78->m_Items[1] = v80;
    v82 = v71->pos_act->pm;
    v83 = v12->pm;
    v85 = v82->m_Items[2] + x;
    v83->m_Items[2] = v85;
    v87 = v71->pos_act->pm;
    v88 = v12->pm;
    v90 = v87->m_Items[3] + y;
    v88->m_Items[3] = v90;
    v92 = v71->uv_act;
    v93 = v71->tex;
    v95 = v93->m_Items[1];
    itfMiscDrawSpritePrim(v12, v92, v167, z, v95, 0, pdrawtag);
  }
  itfMiscDrawAlphaPrim(pdrawtag, 1, 0);
  if ((phandle->stat & 1) != 0)
  {
    v99 = phandle->pelem;
    ctr_act = phandle->ctr_act;
    v102 = v99->m_Items[phandle->act];
    v103 = v167->pm;
    v103->m_Items[3] = (ctr_act * v165) >> 7;
    v105 = v102->pos_act->pm;
    v106 = v12->pm;
    v108 = v105->m_Items[0];
    v109 = 2 * ctr_act;
    v106->m_Items[0] = x - 2 * ctr_act + v108;
    v111 = v102->pos_act->pm;
    v112 = v12->pm;
    v114 = ctr_act >> 1;
    v115 = y - v114 + v111->m_Items[1];
    v112->m_Items[1] = v115;
    v117 = v102->pos_act->pm;
    v118 = v12->pm;
    v120 = v109 + x + v117->m_Items[2];
    v118->m_Items[2] = v120;
    v122 = v102->pos_act->pm;
    v123 = v12->pm;
    v125 = v114 + y + v122->m_Items[3];
    v123->m_Items[3] = v125;
    v127 = v102->uv_act;
    v128 = v102->tex;
    v130 = v128->m_Items[1];
    itfMiscDrawSpritePrim(v12, v127, v167, z, v130, 0, pdrawtag);
    ctr = phandle->ctr;
    if (ctr > 63)
    {
LABEL_84:
        goto LABEL_139;
      goto LABEL_85;
    }
  }
  else
  {
    ctr = phandle->ctr;
    if (ctr > 63)
      goto LABEL_84;
  }
  v131 = phandle->pelem;
  v133 = v131->m_Items[phandle->act];
  v134 = v167->pm;
  v134->m_Items[3] = (ctr * v165) >> 7;
  v136 = 64 - phandle->ctr;
  v137 = v133->pos_act->pm;
  v138 = v12->pm;
  v140 = v137->m_Items[0];
  v141 = 2 * v136;
  v138->m_Items[0] = x - 2 * v136 + v140;
  v143 = v133->pos_act->pm;
  v144 = v12->pm;
  v146 = v136 >> 1;
  v147 = y - v146 + v143->m_Items[1];
  v144->m_Items[1] = v147;
  v149 = v133->pos_act->pm;
  v150 = v12->pm;
  v152 = v141 + x + v149->m_Items[2];
  v150->m_Items[2] = v152;
  v154 = v133->pos_act->pm;
  v155 = v12->pm;
  v157 = v146 + y + v154->m_Items[3];
  v155->m_Items[3] = v157;
  v159 = v133->uv_act;
  v160 = v133->tex;
  v162 = v160->m_Items[1];
  itfMiscDrawSpritePrim(v12, v159, v167, z, v162, 0, pdrawtag);
  {
LABEL_85:
  }
LABEL_139:
  itfMiscDrawAlphaPrim(pdrawtag, 0, 0);
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
          goto LABEL_31;
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
        if (LODWORD(v33->max_length) <= 2)
        {
LABEL_31:
        }
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
      goto LABEL_13;
  }
  else if ((stat & 2) == 0)
  {
    goto LABEL_13;
  }
  v6 = phandle->ctr_deact - 16;
  v5 = phandle->ctr_deact == 16;
  phandle->ctr_deact = v6;
  if (v6 < 0 || v5)
  {
    phandle->ctr_deact = 0;
    phandle->stat = stat & 0xFFFFFFFD;
  }
LABEL_13:
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
  u64 *v10;
  s64 v11;
  u64 *v12;
  u64 v14;
  u64 v15;
  u64 v19;
  u32 *v21;
  u64 *v22;
  u32 *v24;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v27;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v29;
  UnityEngine_Component_o *v30;
  UnityEngine_GameObject_o *v31;
  UnityEngine_Transform_o *v32;
  UnityEngine_Transform_o *v33;
  u64 *v34;
  System_String_o *v35;
  UnityEngine_Component_o *v36;
  UnityEngine_GameObject_o *v37;
  UnityEngine_Transform_o *v38;
  UnityEngine_Transform_o *v39;
  UnityEngine_Transform_o *parent;
  UnityEngine_Component_o *v41;
  UnityEngine_GameObject_o *v42;
  UnityEngine_GUILayer_o *Component_GUILayer;
  u64 *v44;
  System_String_o *v45;
  UnityEngine_Component_o *v46;
  UnityEngine_GameObject_o *v47;
  UnityEngine_Transform_o *v48;
  UnityEngine_Transform_o *v49;
  UnityEngine_Transform_o *v50;
  UnityEngine_Component_o *v51;
  UnityEngine_GameObject_o *v52;
  UnityEngine_GUILayer_o *v53;
  u64 *v54;
  System_String_o *v55;
  UnityEngine_Component_o *v56;
  UnityEngine_GameObject_o *v57;
  UnityEngine_Transform_o *v58;
  UnityEngine_Transform_o *v59;
  UnityEngine_Transform_o *v60;
  UnityEngine_Component_o *v61;
  UnityEngine_GameObject_o *v62;
  UnityEngine_GUILayer_o *v63;
  u64 *v64;
  System_String_o *v65;
  UnityEngine_Component_o *v66;
  UnityEngine_GameObject_o *v67;
  UnityEngine_Transform_o *v68;
  UnityEngine_Transform_o *v69;
  UnityEngine_Transform_o *v70;
  UnityEngine_Component_o *v71;
  UnityEngine_GameObject_o *v72;
  UnityEngine_GUILayer_o *v73;
  s32 v76;
  UnityEngine_Color_o gray;
  UnityEngine_Color_o v78;
  UnityEngine_Color_o v79;
  UnityEngine_Color_o v80;

  SDF_ASSERT(num > 0);
  SDF_ASSERT(act < num && act >= 0);
  v10 = Allocate(fclRibbon_t);
  fclRibbon_t___ctor(v10);
  v11 = num;
  v12 = NewSpecific(fclribbon_elem_t, num);
  v14 = v10[2];
  v10[6] = v12;
  *(v14 + 32) = tex0;
  v15 = v10[2];
  *(v15 + 40) = tex1;
  *(v10 + 6) = 0;
  *(v10 + 14) = act;
  *(v10 + 15) = -1;
  v10[4] = 0;
  *(v10 + 10) = 0;
  *(v10 + 11) = num;
  if (num >= 1)
  {
    v19 = 0;
    do
    {
      v21 = v10[6];
      v22 = Allocate(fclribbon_elem_t);
      fclribbon_elem_t___ctor(v22);
      v24 = &v21[2 * v19++];
      *(v24 + 4) = v22;
    }
    while (v11 != v19);
  }
  transform = get_transform(_statusUIScr, 0);
  v27 = Find(transform, "comstatus_parts", 0);
  gameObject = get_gameObject(v27);
  v29 = get_transform(gameObject, 0);
  v30 = Find(v29, "commode", 0);
  v31 = get_gameObject(v30);
  v32 = get_transform(v31, 0);
  v76 = 1;
  v33 = Find(v32, "commode_menu", 0);
  v34 = sub_8D3950(s32, &v76);
  v35 = Format("commode{0:D2}", v34, 0);
  v36 = Find(v33, v35, 0);
  v37 = get_gameObject(v36);
  GetComponent_object_(v37);
  v38 = get_transform(v37, 0);
  v39 = Find(v38, "stretch_off/TextTM", 0);
  parent = get_parent(v39);
  v41 = get_parent(parent);
  v42 = get_gameObject(v41);
  Component_GUILayer = GetComponent_GUILayer_(v39);
  gray = get_gray();
  (Component_GUILayer->klass[1].vtable._0_Equals.method)(
    Component_GUILayer,
    Component_GUILayer->klass[1].vtable._1_Finalize.methodPtr,
    gray.r,
    gray.g,
    gray.b,
    gray.a);
  if (get_activeSelf(v42))
    SetActive(v42, 0, 0);
  v76 = 2;
  v44 = sub_8D3950(s32, &v76);
  v45 = Format("commode{0:D2}", v44, 0);
  v46 = Find(v33, v45, 0);
  v47 = get_gameObject(v46);
  GetComponent_object_(v47);
  v48 = get_transform(v47, 0);
  v49 = Find(v48, "stretch_off/TextTM", 0);
  v50 = get_parent(v49);
  v51 = get_parent(v50);
  v52 = get_gameObject(v51);
  v53 = GetComponent_GUILayer_(v49);
  v78 = get_gray();
  (v53->klass[1].vtable._0_Equals.method)(
    v53,
    v53->klass[1].vtable._1_Finalize.methodPtr,
    v78.r,
    v78.g,
    v78.b,
    v78.a);
  if (get_activeSelf(v52))
    SetActive(v52, 0, 0);
  v76 = 3;
  v54 = sub_8D3950(s32, &v76);
  v55 = Format("commode{0:D2}", v54, 0);
  v56 = Find(v33, v55, 0);
  v57 = get_gameObject(v56);
  GetComponent_object_(v57);
  v58 = get_transform(v57, 0);
  v59 = Find(v58, "stretch_off/TextTM", 0);
  v60 = get_parent(v59);
  v61 = get_parent(v60);
  v62 = get_gameObject(v61);
  v63 = GetComponent_GUILayer_(v59);
  v79 = get_gray();
  (v63->klass[1].vtable._0_Equals.method)(
    v63,
    v63->klass[1].vtable._1_Finalize.methodPtr,
    v79.r,
    v79.g,
    v79.b,
    v79.a);
  if (get_activeSelf(v62))
    SetActive(v62, 0, 0);
  v76 = 4;
  v64 = sub_8D3950(s32, &v76);
  v65 = Format("commode{0:D2}", v64, 0);
  v66 = Find(v33, v65, 0);
  v67 = get_gameObject(v66);
  GetComponent_object_(v67);
  v68 = get_transform(v67, 0);
  v69 = Find(v68, "stretch_off/TextTM", 0);
  v70 = get_parent(v69);
  v71 = get_parent(v70);
  v72 = get_gameObject(v71);
  v73 = GetComponent_GUILayer_(v69);
  v80 = get_gray();
  (v73->klass[1].vtable._0_Equals.method)(
    v73,
    v73->klass[1].vtable._1_Finalize.methodPtr,
    v80.r,
    v80.g,
    v80.b,
    v80.a);
  if (get_activeSelf(v72))
    SetActive(v72, 0, 0);
  return v10;
}

// 0x1998790
fclRibbon_t *fclRbnInitSort(s32 act) {
  u64 *v3;
  long f64 v5;
  long f64 v6;
  long f64 v7;
  long f64 v8;
  System_String_o *LocalizeText;
  System_Object_array *v10;
  s64 *v11;
  s64 *v13;
  System_String_o *v16;
  Il2CppObject *Item;
  Il2CppObject *v19;
  Il2CppObject *v20;
  Il2CppObject *v21;
  long f64 v23;
  long f64 v24;
  long f64 v25;
  long f64 v26;
  System_String_o *v27;
  System_Object_array *v28;
  s64 *v29;
  s64 *v31;
  System_String_o *v36;
  Il2CppObject *v38;
  Il2CppObject *v39;
  Il2CppObject *v40;
  Il2CppObject *v41;
  u64 *v42;
  u64 *v43;
  u64 *v44;
  u64 v46;
  u64 *v47;
  long f64 v52;
  long f64 v53;
  long f64 v54;
  long f64 v55;
  long f64 v56;
  long f64 v57;
  long f64 v58;
  long f64 v59;
  _BOOL4 v60;
  _BOOL4 v61;
  UnityEngine_Color_o gray;
  UnityEngine_Color_o white;
  UnityEngine_Color_o v64;
  UnityEngine_Color_o v65;

  v3 = Allocate(fclRibbon_t);
  fclRibbon_t___ctor(v3);
  if (act)
  {
    gray = get_gray();
    *&v52 = gray.r;
    *&v53 = gray.g;
    *&v54 = gray.b;
    *&v55 = gray.a;
  }
  else
  {
    white = get_white();
    *&v52 = white.r;
    *&v53 = white.g;
    *&v54 = white.b;
    *&v55 = white.a;
  }
  v5 = v52;
  v6 = v53;
  v7 = v54;
  v8 = v55;
  LocalizeText = GetLocalizeText("<COMBINE_L0025>");
  v61 = act == 0;
  v10 = NewSpecific(object, 1u);
  v11 = sub_8D3950(s32, &v61);
  v13 = v11;
  v10->m_Items[0] = v13;
  v16 = RepColTag(LocalizeText, v10);
  Item = object___get_Item(TextObjs, "dlistsum_race1");
  (Item->klass->vtable[23].methodPtr)(Item, Item->klass->vtable[23].v5, v6, v7, v8);
  v19 = object___get_Item(TextObjs, "dlistsum_race1");
  set_text(v19, v16);
  v20 = object___get_Item(TextObjs, "dlistsum_race2");
  (v20->klass->vtable[23].methodPtr)(v20, v20->klass->vtable[23].v5, v6, v7, v8);
  v21 = object___get_Item(TextObjs, "dlistsum_race2");
  set_text(v21, v16);
  if (act == 1)
  {
    v64 = get_white();
    *&v56 = v64.r;
    *&v57 = v64.g;
    *&v58 = v64.b;
    *&v59 = v64.a;
  }
  else
  {
    v65 = get_gray();
    *&v56 = v65.r;
    *&v57 = v65.g;
    *&v58 = v65.b;
    *&v59 = v65.a;
  }
  v23 = v56;
  v24 = v57;
  v25 = v58;
  v26 = v59;
  v27 = GetLocalizeText("<COMBINE_L0026>");
  v28 = NewSpecific(object, 1u);
  v60 = act == 1;
  v29 = sub_8D3950(s32, &v60);
  v31 = v29;
  v28->m_Items[0] = v31;
  v36 = RepColTag(v27, v28);
  v38 = object___get_Item(TextObjs, "dlistsum_level1");
  (v38->klass->vtable[23].methodPtr)(v38, v38->klass->vtable[23].v23, v24, v25, v26);
  v39 = object___get_Item(TextObjs, "dlistsum_level1");
  set_text(v39, v36);
  v40 = object___get_Item(TextObjs, "dlistsum_level2");
  (v40->klass->vtable[23].methodPtr)(v40, v40->klass->vtable[23].v23, v24, v25, v26);
  v41 = object___get_Item(TextObjs, "dlistsum_level2");
  set_text(v41, v36);
  v42 = NewSpecific(fclribbon_elem_t, 2u);
  *(v3 + 15) = -1;
  *(v3 + 6) = 0;
  *(v3 + 14) = act;
  v3[4] = 0;
  v43 = v42;
  v3[5] = 0x200000000LL;
  v3[6] = v42;
  v44 = Allocate(fclribbon_elem_t);
  fclribbon_elem_t___ctor(v44);
  v43[4] = v44;
  v46 = v3[6];
  v47 = Allocate(fclribbon_elem_t);
  fclribbon_elem_t___ctor(v47);
  *(v46 + 40) = v47;
  return v3;
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
  s32 act;
  u32 stat;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v10;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v13;
  UnityEngine_Component_o *v14;
  UnityEngine_GameObject_o *v15;
  UnityEngine_Transform_o *v16;
  UnityEngine_Transform_o *v17;
  s32 num;
  UnityEngine_Transform_o *v19;
  s32 v20;
  u64 *v21;
  System_String_o *v22;
  UnityEngine_Component_o *v23;
  UnityEngine_Component_o *Component_GUILayer;
  UnityEngine_GameObject_o *v26;
  s32 v27;

  SDF_ASSERT(phandle != 0);
  if ((index & 0x80000000) == 0 && phandle->num > index)
  {
    act = phandle->act;
    if (act != index)
    {
      phandle->deact = act;
      *&phandle->ctr_act = 0x8000000040LL;
      stat = phandle->stat;
      phandle->act = index;
      phandle->ctr = 0;
      phandle->stat = stat | 3;
      transform = get_transform(_statusUIScr, 0);
      v10 = Find(transform, "comstatus_parts", 0);
      gameObject = get_gameObject(v10);
      if (!op_Equality(gameObject, 0, 0))
      {
        if (!get_activeSelf(gameObject))
          SetActive(gameObject, 1, 0);
        v13 = get_transform(gameObject, 0);
        v14 = Find(v13, "commode", 0);
        v15 = get_gameObject(v14);
        v16 = get_transform(v15, 0);
        v17 = Find(v16, "commode_menu", 0);
        num = phandle->num;
        if (num >= 1)
        {
          v19 = v17;
          v20 = 0;
          do
          {
            while (v20 != phandle->deact)
            {
              if (++v20 >= num)
                return;
            }
            v27 = ++v20;
            v21 = sub_8D3950(s32, &v27);
            v22 = Format("commode{0:D2}/stretch_off/TextTM", v21, 0);
            v23 = Find(v19, v22, 0);
            Component_GUILayer = GetComponent_GUILayer_(v23);
            v26 = get_gameObject(Component_GUILayer);
            StartEffect(v26, 2, 1, 0);
            num = phandle->num;
          }
          while (v20 < num);
        }
      }
    }
  }
}

// 0x1998d40
void fclRbnSwitchActiveSort(fclRibbon_t *phandle, s32 index) {
  long f64 v3;
  long f64 v4;
  long f64 v5;
  long f64 v6;
  System_String_o *LocalizeText;
  System_Object_array *v11;
  System_Object_array *v12;
  s64 *v13;
  s64 *v15;
  System_String_o *v19;
  Il2CppObject *Item;
  Il2CppObject *v22;
  Il2CppObject *v23;
  Il2CppObject *v24;
  Il2CppObject *v27;
  UnityEngine_GameObject_o *gameObject;
  s32 v30;
  Il2CppObject *v31;
  UnityEngine_GameObject_o *v32;
  Il2CppObject *v34;
  UnityEngine_GameObject_o *v36;
  Il2CppObject *v37;
  UnityEngine_GameObject_o *v38;
  System_String_o *v39;
  System_Object_array *v40;
  s64 *v41;
  s64 *v43;
  System_String_o *v47;
  Il2CppObject *v49;
  Il2CppObject *v50;
  Il2CppObject *v51;
  Il2CppObject *v52;
  Il2CppObject *v55;
  UnityEngine_GameObject_o *v57;
  Il2CppObject *v58;
  UnityEngine_GameObject_o *v59;
  Il2CppObject *v60;
  UnityEngine_GameObject_o *v62;
  Il2CppObject *v63;
  UnityEngine_GameObject_o *v64;
  s16 act;
  u32 v66;
  long f64 v67;
  long f64 v68;
  long f64 v69;
  long f64 v70;
  long f64 v71;
  long f64 v72;
  long f64 v73;
  long f64 v74;
  s64 v75;
  s64 v76;
  UnityEngine_Color_o white;
  UnityEngine_Color_o v78;

  SDF_ASSERT(phandle != 0);
  if ((index & 0x80000000) == 0 && phandle->num > index && phandle->act != index)
  {
    if (index)
    {
      v75 = 0;
      v76 = 0;
      sub_19EC670(&v75, 162.0, 151.0, 255.0);
      LODWORD(v3) = HIDWORD(v75);
      LODWORD(v4) = v75;
      LODWORD(v5) = HIDWORD(v76);
      LODWORD(v6) = v76;
    }
    else
    {
      white = get_white();
      *&v67 = white.r;
      *&v68 = white.g;
      *&v69 = white.b;
      *&v70 = white.a;
      v4 = v67;
      v3 = v68;
      v6 = v69;
      v5 = v70;
    }
    LocalizeText = GetLocalizeText("<COMBINE_L0025>");
    v11 = NewSpecific(object, 1u);
    LODWORD(v75) = index == 0;
    v12 = v11;
    v13 = sub_8D3950(s32, &v75);
    v15 = v13;
    v12->m_Items[0] = v15;
    v19 = RepColTag(LocalizeText, v12);
    Item = object___get_Item(TextObjs, "dlistsum_race1");
    v22 = object___get_Item(TextObjs, "dlistsum_race2");
    (v22->klass->vtable[23].methodPtr)(v22, v22->klass->vtable[23].v4, v3, v6, v5);
    (Item->klass->vtable[23].methodPtr)(Item, Item->klass->vtable[23].v4, v3, v6, v5);
    v23 = object___get_Item(TextObjs, "dlistsum_race1");
    v24 = object___get_Item(TextObjs, "dlistsum_race2");
    set_text(v24, v19);
    set_text(v23, v19);
    if (index == 1)
    {
      v27 = object___get_Item(TextObjs, "dlistsum_race1");
      gameObject = get_gameObject(v27);
      v30 = 1;
      StartEffect(gameObject, 2, 1, 0);
      v31 = object___get_Item(TextObjs, "dlistsum_race2");
      v32 = get_gameObject(v31);
      StartEffect(v32, 2, 1, 0);
      v78 = get_white();
      *&v71 = v78.r;
      *&v72 = v78.g;
      *&v73 = v78.b;
      *&v74 = v78.a;
      v4 = v71;
      v3 = v72;
      v6 = v73;
      v5 = v74;
    }
    else
    {
      v34 = object___get_Item(TextObjs, "dlistsum_race1");
      v36 = get_gameObject(v34);
      StopEffect(v36, 0);
      v37 = object___get_Item(TextObjs, "dlistsum_race2");
      v38 = get_gameObject(v37);
      StopEffect(v38, 0);
      v75 = 0;
      v76 = 0;
      sub_19EC670(&v75, 162.0, 151.0, 255.0);
      LODWORD(v3) = HIDWORD(v75);
      LODWORD(v4) = v75;
      v30 = 0;
      LODWORD(v5) = HIDWORD(v76);
      LODWORD(v6) = v76;
    }
    v39 = GetLocalizeText("<COMBINE_L0026>");
    v40 = NewSpecific(object, 1u);
    LODWORD(v75) = v30;
    v41 = sub_8D3950(s32, &v75);
    v43 = v41;
    v40->m_Items[0] = v43;
    v47 = RepColTag(v39, v40);
    v49 = object___get_Item(TextObjs, "dlistsum_level1");
    v50 = object___get_Item(TextObjs, "dlistsum_level2");
    (v50->klass->vtable[23].methodPtr)(v50, v50->klass->vtable[23].v4, v3, v6, v5);
    (v49->klass->vtable[23].methodPtr)(v49, v49->klass->vtable[23].v4, v3, v6, v5);
    v51 = object___get_Item(TextObjs, "dlistsum_level1");
    v52 = object___get_Item(TextObjs, "dlistsum_level2");
    set_text(v52, v47);
    set_text(v51, v47);
    if (index)
    {
      v55 = object___get_Item(TextObjs, "dlistsum_level1");
      v57 = get_gameObject(v55);
      StopEffect(v57, 0);
      v58 = object___get_Item(TextObjs, "dlistsum_level2");
      v59 = get_gameObject(v58);
      StopEffect(v59, 0);
    }
    else
    {
      v60 = object___get_Item(TextObjs, "dlistsum_level1");
      v62 = get_gameObject(v60);
      StartEffect(v62, 2, 1, 0);
      v63 = object___get_Item(TextObjs, "dlistsum_level2");
      v64 = get_gameObject(v63);
      StartEffect(v64, 2, 1, 0);
    }
    act = phandle->act;
    phandle->act = index;
    phandle->deact = act;
    *&phandle->ctr_act = 0x8000000040LL;
    v66 = phandle->stat | 3;
    phandle->ctr = 0;
    phandle->stat = v66;
  }
}
