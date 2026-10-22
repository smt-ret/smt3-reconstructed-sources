#include "types.h"

typedef struct talkChoice talkChoice;
typedef struct talkChoice_Mode talkChoice_Mode;

struct talkChoice_Mode {
    s32 value__;
};

void Log(char *fmt, void **parray);

// 0x169cf10
void Awake(talkChoice *this) {
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_RectTransform_o *tfm;
  UnityEngine_Vector2_o v5;
  UnityEngine_Vector2_o v6;

  Component_GUILayer = GetComponent_GUILayer_(this);
  this->canv = Component_GUILayer;
  *&this->alpha = 0;
  set_alpha(Component_GUILayer, 0.0);
  this->tfm = GetComponent_GUILayer_(this);
  v5 = 0;
  sub_851710(&v5, 1500.0, 322.0);
  v6 = v5;
  tfm = this->tfm;
  this->pos.x = v5.x;
  this->pos.y = v6.y;
  set_anchoredPosition(tfm, v6);
  this->step = 0;
}

// 0x169d1f0
void Display(talkChoice *this, bool sw) {
  UnityEngine_CanvasGroup_o *canv;
  f32 v6;
  s32 v7;
  s64 v8;

  if ((this->wnd_mode | 1) == 3 && sw)
  {
    canv = this->canv;
    this->alpha = 0.0;
    set_alpha(canv, 0.0);
    v8 = 0;
    sub_851710(&v8, 1500.0, 322.0);
    v6 = *(&v8 + 1);
    LODWORD(this->pos.x) = v8;
    this->pos.y = v6;
    this->wnd_mode = 3;
    this->step = 0;
  }
  if (sw)
    v7 = 1;
  else
    v7 = 3;
  this->wnd_mode = v7;
}

// 0x169d290
void DisplayOff(talkChoice *this) {
  UnityEngine_Object_o *canv;
  UnityEngine_CanvasGroup_o *v4;
  u64 *v5;
  System_String_o *v6;
  System_Object_array *v8;
  f32 v9;
  f32 v10;
  s64 v11;
  f32 alpha;

  canv = this->canv;
  if (!op_Equality(canv, 0, 0))
  {
    v4 = this->canv;
    this->alpha = 0.0;
    set_alpha(v4, 0.0);
    alpha = this->alpha;
    v5 = sub_8D3950(f32, &alpha);
    v6 = Concat("choiceDisplayOff : ", v5);
    v8 = Empty_string_();
    Log(v6, v8, 0);
    v11 = 0;
    sub_851710(&v11, 1500.0, 322.0);
    v10 = *&v11;
    v9 = *(&v11 + 1);
    this->step = 15;
    this->pos.x = v10;
    this->pos.y = v9;
    this->wnd_mode = 3;
  }
}

// 0x169d3e0
s32 GetDisplayStatus(talkChoice *this) {
  return this->wnd_mode;
}

// 0x169cfd0
void Update(talkChoice *this) {
  s32 wnd_mode;
  f32 alpha;
  s32 step;
  f32 v6;
  f32 v7;
  UnityEngine_RectTransform_o *tfm;
  f32 v9;
  s32 v10;
  UnityEngine_RectTransform_o *v12;
  UnityEngine_RectTransform_o *v13;
  f32 v14;
  f32 v15;
  UnityEngine_RectTransform_o *v16;
  UnityEngine_Vector2_o v17;
  UnityEngine_Vector2_o v18;
  UnityEngine_Vector2_o pos;
  UnityEngine_Vector2_o v20;
  UnityEngine_Vector2_o v21;

  wnd_mode = this->wnd_mode;
  if (wnd_mode == 1)
  {
    alpha = get_alpha(this->canv);
    step = this->step;
    this->alpha = alpha;
    this->step = step + 1;
    if (step <= 9)
    {
      v18.y = this->pos.y;
      v7 = this->pos.x + -59.4;
      this->alpha = fminf(alpha + 0.1, 1.0);
      v18.x = fmaxf(v7, 906.0);
      tfm = this->tfm;
      this->pos.x = v18.x;
      set_anchoredPosition(tfm, v18);
      v6 = this->alpha;
    }
    else
    {
      v6 = get_alpha(this->canv) + -0.0208;
      this->alpha = v6;
      if (v6 < 0.896)
      {
        v6 = 0.896;
        this->alpha = 0.896;
      }
    }
    set_alpha(this->canv, v6);
    if (this->step >= 15)
    {
      v13 = this->tfm;
      v17 = 0;
      sub_851710(&v17, 906.0, 322.0);
      v20 = v17;
      this->pos.x = v17.x;
      this->pos.y = v20.y;
      set_anchoredPosition(v13, v20);
      this->wnd_mode = 2;
LABEL_17:
      this->step = 0;
      return;
    }
    wnd_mode = this->wnd_mode;
  }
  if (wnd_mode == 3)
  {
    v9 = get_alpha(this->canv);
    v10 = this->step;
    this->alpha = v9;
    this->step = v10 + 1;
    if (v10 <= 9)
    {
      v14 = v9 + -0.1;
      pos.y = this->pos.y;
      v15 = this->pos.x + 59.4;
      if (v14 <= 0.0)
        v14 = 0.0;
      this->alpha = v14;
      pos.x = fminf(v15, 1500.0);
      v12 = this->tfm;
      this->pos.x = pos.x;
    }
    else
    {
      pos = this->pos;
      v12 = this->tfm;
    }
    set_anchoredPosition(v12, pos);
    set_alpha(this->canv, this->alpha);
    if (this->step >= 15)
    {
      v16 = this->tfm;
      v17 = 0;
      sub_851710(&v17, 1500.0, 322.0);
      v21 = v17;
      this->pos = v17;
      set_anchoredPosition(v16, v21);
      this->wnd_mode = 0;
      goto LABEL_17;
    }
  }
}
