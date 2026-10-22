#include "types.h"

typedef struct smnUI smnUI;
typedef struct smnUI_Mode smnUI_Mode;

struct smnUI_Mode {
    s32 value__;
};

// 0x168d1c0
void Awake(smnUI *this) {
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_GUILayer_o *v4;
  UnityEngine_RectTransform_o *tfm;
  struct UnityEngine_Vector2_o v6;
  UnityEngine_Vector2_o v7;

  Component_GUILayer = GetComponent_GUILayer_(this);
  this->canv = Component_GUILayer;
  *&this->alpha = 0;
  set_alpha(Component_GUILayer, 0.0);
  v4 = GetComponent_GUILayer_(this);
  this->cnv = v4;
  set_sortingOrder(v4, 1);
  this->tfm = GetComponent_GUILayer_(this);
  v6 = 0;
  sub_851710(&v6, 672.0, -58.0);
  v7 = v6;
  tfm = this->tfm;
  this->pos = v6;
  set_anchoredPosition(tfm, v7);
  this->step = 0;
}

// 0x168d4b0
void Display(smnUI *this, bool sw) {
  UnityEngine_CanvasGroup_o *canv;
  UnityEngine_RectTransform_o *tfm;
  UnityEngine_Canvas_o *cnv;
  s32 v8;
  UnityEngine_Vector2_o v9;
  UnityEngine_Vector2_o v10;

  if ((this->wnd_mode | 1) == 3 && sw)
  {
    canv = this->canv;
    this->alpha = 0.0;
    set_alpha(canv, 0.0);
    tfm = this->tfm;
    v9 = 0;
    sub_851710(&v9, 672.0, -58.0);
    v10 = v9;
    this->pos.x = v9.x;
    this->pos.y = v10.y;
    set_anchoredPosition(tfm, v10);
    cnv = this->cnv;
    this->wnd_mode = 3;
    this->step = 0;
    set_sortingOrder(cnv, 1);
  }
  if (sw)
    v8 = 1;
  else
    v8 = 3;
  this->wnd_mode = v8;
}

// 0x168d660
void DisplayOff(smnUI *this) {
  UnityEngine_Object_o *canv;
  UnityEngine_CanvasGroup_o *v4;
  UnityEngine_RectTransform_o *tfm;
  UnityEngine_Canvas_o *cnv;
  UnityEngine_Vector2_o v7;
  UnityEngine_Vector2_o v8;

  canv = this->canv;
  if (!op_Equality(canv, 0, 0))
  {
    v4 = this->canv;
    this->alpha = 0.0;
    set_alpha(v4, 0.0);
    tfm = this->tfm;
    v7 = 0;
    sub_851710(&v7, 672.0, -58.0);
    v8 = v7;
    this->pos.x = v7.x;
    this->pos.y = v8.y;
    set_anchoredPosition(tfm, v8);
    cnv = this->cnv;
    this->step = 15;
    this->wnd_mode = 3;
    set_sortingOrder(cnv, 1);
  }
}

// 0x168d570
void DisplayOn(smnUI *this) {
  UnityEngine_Object_o *canv;
  UnityEngine_CanvasGroup_o *v4;
  UnityEngine_RectTransform_o *tfm;
  UnityEngine_Canvas_o *cnv;
  UnityEngine_Vector2_o v7;
  UnityEngine_Vector2_o v8;

  canv = this->canv;
  if (!op_Equality(canv, 0, 0))
  {
    v4 = this->canv;
    this->alpha = 1.0;
    set_alpha(v4, 1.0);
    tfm = this->tfm;
    v7 = 0;
    sub_851710(&v7, 4.0, -58.0);
    v8 = v7;
    this->pos.x = v7.x;
    this->pos.y = v8.y;
    set_anchoredPosition(tfm, v8);
    cnv = this->cnv;
    this->step = 15;
    this->wnd_mode = 2;
    set_sortingOrder(cnv, 21);
  }
}

// 0x168d750
s32 GetDisplayStatus(smnUI *this) {
  return this->wnd_mode;
}

// 0x168d2b0
void Update(smnUI *this) {
  s32 wnd_mode;
  f32 alpha;
  UnityEngine_Canvas_o *cnv;
  s32 v6;
  UnityEngine_RectTransform_o *tfm;
  f32 v8;
  f32 v9;
  s32 step;
  f32 v11;
  f32 y;
  f32 v13;
  f32 v14;
  UnityEngine_RectTransform_o *v15;
  UnityEngine_RectTransform_o *v16;
  UnityEngine_Canvas_o *v17;
  UnityEngine_RectTransform_o *v18;
  UnityEngine_Vector2_o v19;
  UnityEngine_Vector2_o v20;
  UnityEngine_Vector2_o v21;
  UnityEngine_Vector2_o v22;
  UnityEngine_Vector2_o v23;

  wnd_mode = this->wnd_mode;
  if (wnd_mode == 1)
  {
    alpha = get_alpha(this->canv);
    cnv = this->cnv;
    v6 = this->step + 1;
    this->alpha = alpha;
    this->step = v6;
    set_sortingOrder(cnv, 21);
    if (this->step <= 15)
    {
      tfm = this->tfm;
      v21.y = this->pos.y;
      v8 = this->pos.x + -44.533;
      this->alpha = fminf(this->alpha + 0.066667, 1.0);
      v21.x = fmaxf(v8, 4.0);
      this->pos.x = v21.x;
      set_anchoredPosition(tfm, v21);
    }
    set_alpha(this->canv, this->alpha);
    if (this->step >= 15)
    {
      v18 = this->tfm;
      v19 = 0;
      sub_851710(&v19, 4.0, -58.0);
      v23 = v19;
      this->pos.x = v19.x;
      this->pos.y = v23.y;
      set_anchoredPosition(v18, v23);
      this->wnd_mode = 2;
      this->step = 0;
      return;
    }
    wnd_mode = this->wnd_mode;
  }
  if (wnd_mode == 3)
  {
    v9 = get_alpha(this->canv);
    step = this->step;
    this->alpha = v9;
    this->step = step + 1;
    if (step <= 14)
    {
      v11 = v9 + -0.066667;
      y = this->pos.y;
      v13 = this->pos.x + 44.533;
      if (v11 <= 0.0)
        v11 = 0.0;
      this->alpha = v11;
      v14 = fminf(v13, 672.0);
      v15 = this->tfm;
      this->pos.x = v14;
      v20.x = v14;
      v20.y = y;
      set_anchoredPosition(v15, v20);
      v9 = this->alpha;
    }
    set_alpha(this->canv, v9);
    if (this->step >= 15)
    {
      v16 = this->tfm;
      v19 = 0;
      sub_851710(&v19, 672.0, -58.0);
      v22 = v19;
      this->pos.x = v19.x;
      this->pos.y = v22.y;
      set_anchoredPosition(v16, v22);
      v17 = this->cnv;
      this->wnd_mode = 0;
      this->step = 0;
      set_sortingOrder(v17, 1);
    }
  }
}
