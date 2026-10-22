#include "types.h"

typedef struct Gfx2DSpr Gfx2DSpr;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;

// 0x1140d00
void Awake(Gfx2DSpr *this) {
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_GUILayer_o *v4;
  UnityEngine_RectTransform_o *tfm;
  UnityEngine_RectTransform_o *v6;
  UnityEngine_Vector2_o v7;
  UnityEngine_Vector2_o v8;
  UnityEngine_Vector2_o v9;

  this->pic = 0;
  this->tex = 0;
  this->tex_old = 0;
  Component_GUILayer = GetComponent_GUILayer_(this);
  this->img = Component_GUILayer;
  set_enabled(Component_GUILayer, 0);
  this->canv = GetComponent_GUILayer_(this);
  v4 = GetComponent_GUILayer_(this);
  this->tfm = v4;
  v9 = 0;
  sub_851710(&v9, 0.0, 1.0);
  set_anchorMin(v4, v9);
  tfm = this->tfm;
  v8 = 0;
  sub_851710(&v8, 0.0, 1.0);
  set_anchorMax(tfm, v8);
  v6 = this->tfm;
  v7 = 0;
  sub_851710(&v7, 0.0, 1.0);
  set_pivot(v6, v7);
}

// 0x1140e40
void Draw(Gfx2DSpr *this, sdfGrPacketHeader_t *pkt) {
  sdfGrPacketHeader_t_c *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  sdfGrPacketHeader_t_o *v9;
  u64 parm;
  u64 *v11;
  u64 *v12;
  struct sdfPrm_array *primitive;
  s64 v15;
  struct sdfGifTag_t_o *giftag;
  u64 *v17;
  u64 regs;
  u64 v19;
  struct sdfTexHandle_t_o *tex;
  s64 v22;
  s64 v23;
  u8 *p_b5;
  s32 v25;
  u64 max_length_low;
  s64 v27;
  char v29;
  Il2CppClass **v31;
  s32 v32;
  s32 v33;
  s64 v34;
  u32 v36;
  char *v38;
  u64 *v39;
  char *v40;
  Il2CppClass **v42;
  char *v43;
  s64 v44;
  u32 v45;
  s64 v49;
  f32 v53;
  sdfIVector2_t_o *v54;
  u64 *v57;
  u64 *v58;
  struct System_Int32_array *pm;
  Il2CppClass **v62;
  char *v63;
  u32 v64;
  s32 v65;
  s64 v68;
  s32 v70;
  Gfx2DSpr_o *v72;
  struct sdfTexHandle_t_o *v73;
  u64 *v74;
  struct System_Int32_array *v75;
  s64 v76;
  s32 v77;
  struct System_Int32_array *v78;
  s64 v79;
  s32 v81;
  struct System_Int32_array *v83;
  s64 v84;
  s32 v85;
  struct System_Int32_array *v87;
  s64 v89;
  s32 v91;
  struct sdfTexHandle_t_o *v93;
  struct UnityEngine_Texture2D_array *image;
  s64 texId;
  UnityEngine_Texture2D_o *v97;
  s32 v98;
  s32 v99;
  s64 v100;
  s64 v102;
  s64 v104;
  s32 v105;
  s64 v106;
  s64 v108;
  s32 v110;
  s64 v112;
  s64 v114;
  s64 v115;
  UnityEngine_Object_o *_27456544;
  System_String_o *name;
  struct System_Int32_array *olduv;
  s32 v120;
  s64 v121;
  struct System_Int32_array *v122;
  s32 v124;
  s64 v126;
  struct System_Int32_array *v128;
  s32 v129;
  s64 v130;
  struct System_Int32_array *v150;
  s32 v152;
  s64 v154;
  struct UnityEngine_UI_Image_o *img;
  f32 v157;
  f32 v158;
  f32 v159;
  f32 v160;
  UnityEngine_Object_o *sprite;
  f32 v163;
  f32 v164;
  UnityEngine_Sprite_o *v165;
  f32 v166;
  UnityEngine_Sprite_o *v167;
  f32 v168;
  UnityEngine_Transform_o *tfm;
  UnityEngine_RectTransform_o *v171;
  f32 v173;
  UnityEngine_Transform_o *v174;
  f32 v175;
  Gfx2DSpr_o *v177;
  u64 *v178;
  char v179;
  s64 v180;
  u64 *v181;
  u32 v182;
  struct sdfPrm_array *v183;
  s64 v184;
  s64 v185;
  u32 v186;
  s64 v187;
  char v188;
  s64 v189;
  s32 v190;
  UnityEngine_Rect_o rect;
  s64 v192;
  s64 v193;
  UnityEngine_Color32_o c;
  UnityEngine_Vector3_o v195;
  char *v196;
  UnityEngine_Color_o v197;
  UnityEngine_Rect_o v198;
  UnityEngine_Color_o cyan;

  c.rgba = 0;
  v192 = 0;
  v193 = 0;
  *&rect.m_XMin = 0;
  *&rect.m_Width = 0;
  if (pkt)
  {
    klass = pkt->klass;
    if (pkt->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdf2DTexPacket_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdf2DTexPacket_t, &v195);
      if ((LOBYTE(v195.x) & 1) != 0)
        v7 = v196;
      else
        v7 = &v195.x + 1;
      v8 = sub_8C4940(v7);
    }
    v9 = pkt;
  }
  else
  {
    v9 = 0;
  }
  parm = v9->giftag->parm;
  v195.z = 0.0;
  *&v195.x = 0;
  sub_17A6190(&v195, parm);
  cyan = get_cyan();
  c.rgba = op_Implicit(cyan, 0).rgba;
  v11 = NewSpecific(sdfIVector2_t, 2u);
  v12 = NewSpecific(UnityEngine_Vector3, 4u);
  primitive = v9->primitive;
  v15 = BYTE1(v195.x);
  giftag = pkt->giftag;
  v17 = v12;
  regs = giftag->regs;
  v19 = giftag->parm;
  v190 = 0;
  v189 = 0;
  sub_17A6190(&v189, v19);
  v188 = 0;
  v187 = 0;
  sub_17A6CD0(&v187, HIWORD(v189));
  tex = this->tex;
  if (tex && tex != this->tex_old && tex->image->max_length)
    this->pic = 1;
  v181 = v11;
  v177 = this;
  if (v15)
  {
    v22 = 0;
    v23 = 0;
    p_b5 = &primitive->m_Items[0].b5;
    v186 = 0;
    v179 = 0;
    v182 = 0;
    v183 = primitive;
    v180 = v15;
    v178 = v17;
    do
    {
      if ((regs & 0xF) <= 5)
      {
        v25 = regs & 0xF;
        if ((v25 - 4) < 2)
        {
          v184 = v23;
          v36 = v23;
          v38 = v17 + 12 * v23;
          v39 = v17;
          *(v38 + 4) = 0;
          v40 = v38 + 32;
          *(v40 + 2) = 0;
          v42 = &primitive->obj.klass + v186;
          v45 = *(v42 + 8);
          v43 = (v42 + 4);
          v44 = v45;
          *v40 = ((v44 - ITF_MISC_SCREEN_OFFSET_X) / 16);
          v49 = *(v43 + 1);
          v15 = v180;
          v17 = v39;
          *(v39 + 3 * v184 + 9) = ((v49 - ITF_MISC_SCREEN_OFFSET_Y) / 8);
          primitive = v183;
          v53 = *(&v183->m_Items[0].b1 + 2 * v186);
          *(v39 + 3 * v184 + 10) = v53;
          v23 = v36 + 1;
          v186 += 2;
        }
        else if (v25 == 3)
        {
          v185 = v23;
          v54 = Allocate(sdfIVector2_t);
          sdfIVector2_t___ctor(v54);
          v57 = &v181[v182];
          v57[4] = v54;
          v58 = v57 + 4;
          pm = v54->pm;
          v62 = &primitive->obj.klass + v186;
          v64 = *(v62 + 8);
          v63 = (v62 + 4);
          v65 = v64 >> 4;
          pm->m_Items[0] = v65;
          primitive = v183;
          v68 = *(*v58 + 16LL);
          v70 = *(v63 + 1) >> 4;
          *(v68 + 36) = v70;
          v23 = v185;
          ++v186;
          ++v182;
        }
        else if (v25 == 1)
        {
          max_length_low = LODWORD(primitive->max_length);
          v27 = v23;
          if (2 * *p_b5 >= 255)
            v29 = -1;
          else
            v29 = 2 * *p_b5;
          v31 = &primitive->obj.klass + v186;
          v32 = *(v31 + 8);
          v33 = *(v31 + 9);
          v34 = v186 + 1LL;
          sub_19ED4B0(&c, v32, v33, *(&primitive->m_Items[0].l + 2 * v34), v29);
          v15 = v180;
          v23 = v27;
          v17 = v178;
          v186 += 2;
          v179 = 1;
        }
      }
      ++v22;
      regs >>= 4;
      p_b5 += 8;
    }
    while (v15 != v22);
    v72 = v177;
    if (v177->pic == 1)
      goto LABEL_72;
  }
  else
  {
    v179 = 0;
    v72 = this;
    if (this->pic == 1)
    {
LABEL_72:
      v73 = v72->tex;
      v74 = v181;
      goto LABEL_73;
    }
  }
  v74 = v181;
  if (!v181[4])
    goto LABEL_167;
  if (!v181[5])
    goto LABEL_167;
  olduv = v72->olduv;
  v120 = olduv->m_Items[0];
  v121 = *(v181[4] + 16LL);
  if (v120 == *(v121 + 32))
  {
    v122 = v72->olduv;
    v124 = v122->m_Items[1];
    v126 = *(v181[4] + 16LL);
    if (v124 == *(v126 + 36))
    {
      v128 = v72->olduv;
      v129 = v128->m_Items[2];
      v130 = *(v181[5] + 16LL);
      if (v129 == *(v130 + 32))
      {
        v150 = v72->olduv;
        v152 = v150->m_Items[3];
        v154 = *(v181[5] + 16LL);
        if (v152 == *(v154 + 36))
          goto LABEL_167;
      }
    }
  }
  v73 = v72->tex;
  if (!v73 || !v73->image->max_length)
  {
LABEL_167:
    if ((v179 & 1) == 0)
      goto LABEL_171;
    if (!get_enabled(v72->img))
    {
      set_enabled(v72->img, 1);
      set_overrideSorting(v72->canv, 1);
      set_sortingOrder(v72->canv, 0);
    }
    goto LABEL_170;
  }
LABEL_73:
  v72->tex_old = v73;
  v75 = v72->olduv;
  v76 = *(v74[4] + 16LL);
  v77 = *(v76 + 32);
  v75->m_Items[0] = v77;
  v78 = v72->olduv;
  v79 = *(v74[4] + 16LL);
  v81 = *(v79 + 36);
  v78->m_Items[1] = v81;
  v83 = v72->olduv;
  v84 = *(v74[5] + 16LL);
  v85 = *(v84 + 32);
  v83->m_Items[2] = v85;
  v87 = v72->olduv;
  v89 = *(v74[5] + 16LL);
  v91 = *(v89 + 36);
  v87->m_Items[3] = v91;
  v93 = v72->tex;
  image = v93->image;
  texId = v93->texId;
  v97 = image->m_Items[texId];
  (v97->klass->vtable._4_get_width.methodPtr)(v97, v97->klass->vtable._4_get_width.method);
  v98 = (v97->klass->vtable._6_get_height.methodPtr)(v97, v97->klass->vtable._6_get_height.method);
  v192 = 0;
  v193 = 0;
  v99 = v98;
  v100 = *(v74[4] + 16LL);
  sub_1A1D840(&v192, *(v100 + 32));
  v102 = *(v74[5] + 16LL);
  sub_1A1D880(&v192, (v99 - *(v102 + 36)));
  v104 = *(v74[5] + 16LL);
  v105 = *(v104 + 32);
  v106 = *(v74[4] + 16LL);
  sub_1A1DAE0(&v192, (v105 - *(v106 + 32)));
  v108 = *(v74[5] + 16LL);
  v110 = *(v108 + 36);
  v112 = *(v74[4] + 16LL);
  sub_1A1DB20(&v192, (v110 - *(v112 + 36)));
  if (sub_1A1DAC0(&v192) != 0.0 && sub_1A1DB00(&v192) != 0.0)
  {
    v114 = v192;
    v115 = v193;
    *&v195.x = 0;
    sub_851710(&v195.x, 0.5, 0.5);
    *&v198.m_XMin = v114;
    *&v198.m_Width = v115;
    _27456544 = Create_27456544(v97, v198, *&v195.x);
    name = get_name(v97);
    set_name(_27456544, name);
    set_sprite(v72->img, _27456544);
    (v72->img->klass->vtable._49_CrossFadeAlpha.methodPtr)(
      v72->img,
      v72->img->klass->vtable._49_CrossFadeAlpha.method);
    set_enabled(v72->img, 1);
    set_overrideSorting(v72->canv, 1);
    set_sortingOrder(v72->canv, 0);
  }
  v72->pic = 0;
  if ((v179 & 1) != 0)
  {
LABEL_170:
    img = v72->img;
    v197 = op_Implicit_27186704(c.rgba);
    (img->klass->vtable._27_SetLayoutDirty.methodPtr)(
      img,
      img->klass->vtable._27_SetLayoutDirty.v197.r,
      v197.g,
      v197.b,
      v197.a);
  }
LABEL_171:
  v157 = *(v17 + 11);
  v158 = *(v17 + 8);
  v159 = *(v17 + 12);
  v160 = *(v17 + 9);
  sprite = get_sprite(v72->img);
  v163 = v157 - v158;
  v164 = v159 - v160;
  if (op_Inequality(sprite, 0, 0))
  {
    v165 = get_sprite(v72->img);
    rect = get_rect(v165);
    v166 = v163 / sub_1A1DAC0(&rect);
    v167 = get_sprite(v72->img);
    rect = get_rect(v167);
    v168 = sub_1A1DB00(&rect);
    tfm = v72->tfm;
    v195.z = 0.0;
    *&v195.x = 0;
    sub_8524C0(&v195.x, v166, v164 / v168, 1.0);
    set_localScale(tfm, v195);
    if (!v17[3])
    {
LABEL_180:
    }
  }
  else
  {
    v171 = v72->tfm;
    *&v195.x = 0;
    sub_851710(&v195.x, v163, v164);
    set_sizeDelta(v171, *&v195.x);
    if (!v17[3])
      goto LABEL_180;
  }
  v173 = -*(v17 + 9);
  v174 = v72->tfm;
  v175 = *(v17 + 8);
  v195.z = 0.0;
  *&v195.x = 0;
  sub_8524C0(&v195.x, v175, v173, 0.0);
  set_localPosition(v174, v195);
  set_sortingOrder(v72->canv, 0xFFFF - *(v17 + 10), 0);
}
