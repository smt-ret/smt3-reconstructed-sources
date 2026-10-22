#include "types.h"

typedef struct talkUI talkUI;
typedef struct talkUI_Mode talkUI_Mode;

struct talkUI_Mode {
    s32 value__;
};

void Log(char *fmt, void **parray);

// 0x169d400
void Awake(talkUI *this) {
  UnityEngine_GUILayer_o *Component_GUILayer;

  Component_GUILayer = GetComponent_GUILayer_(this);
  this->canv = Component_GUILayer;
  *&this->alpha = 0;
  set_alpha(Component_GUILayer, 0.0);
}

// 0x169d520
void Display(talkUI *this, bool sw) {
  s32 v3;

  if (sw)
    v3 = 1;
  else
    v3 = 3;
  this->wnd_mode = v3;
}

// 0x169d540
void DisplayOff(talkUI *this) {
  UnityEngine_Object_o *canv;
  u64 *v4;
  System_String_o *v5;
  System_Object_array *v7;
  s32 wnd_mode;
  f32 alpha;

  canv = this->canv;
  if (!op_Equality(canv, 0, 0))
  {
    alpha = this->alpha;
    v4 = sub_8D3950(f32, &alpha);
    v5 = Concat("DisplayOff : ", v4);
    v7 = Empty_string_();
    Log(v5, v7, 0);
    set_alpha(this->canv, 0.0);
    wnd_mode = this->wnd_mode;
    this->alpha = 0.0;
    if (wnd_mode != 1)
      this->wnd_mode = 0;
  }
}

// 0x169d660
s32 GetDisplayStatus(talkUI *this) {
  return this->wnd_mode;
}

// 0x169d670
void Hide(talkUI *this) {
  set_alpha(this->canv, 0.0);
}

// 0x169d460
void Update(talkUI *this) {
  s32 wnd_mode;
  f32 v4;
  f32 v5;

  wnd_mode = this->wnd_mode;
  if (wnd_mode == 1)
  {
    v4 = get_alpha(this->canv) + 0.13333;
    this->alpha = v4;
    if (v4 >= 1.0)
    {
      v4 = 1.0;
      *&this->alpha = 0x23F800000LL;
    }
    set_alpha(this->canv, v4);
    wnd_mode = this->wnd_mode;
  }
  if (wnd_mode == 3)
  {
    v5 = get_alpha(this->canv) + -0.13333;
    this->alpha = v5;
    if (v5 <= 0.0)
    {
      v5 = 0.0;
      *&this->alpha = 0;
    }
    set_alpha(this->canv, v5);
  }
}
