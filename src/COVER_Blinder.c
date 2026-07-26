#include "types.h"

typedef struct COVER_Blinder COVER_Blinder;
typedef struct COVER_Blinder__Fade_d__7 COVER_Blinder__Fade_d__7;
typedef struct COVER_LoadMark COVER_LoadMark;

struct COVER_Blinder__Fade_d__7 {
    s32 __1__state;
    void *__2__current;
    COVER_Blinder *__4__this;
};

void SetDisp(COVER_LoadMark *this, bool act);

// 0xfe1380
void *Fade(COVER_Blinder *this) {
  u64 *v3;

  v3 = Allocate(COVER_Blinder__Fade_d__7);
  _ctor(v3, 0);
  *(v3 + 4) = 0;
  v3[4] = this;
  return v3;
}

// 0xfe13f0
void FadeIn(COVER_Blinder *this) {
  u64 *v4;

  SetDisp(this, 1);
  this->time = this->max;
  this->vec = -1.0;
  this->_IsActive_k__BackingField = 1;
  v4 = Allocate(COVER_Blinder__Fade_d__7);
  _ctor(v4, 0);
  *(v4 + 4) = 0;
  v4[4] = this;
  StartCoroutine_27343696(this, v4);
}

// 0xfe12f0
void FadeOut(COVER_Blinder *this) {
  u64 *v4;

  SetDisp(this, 1);
  *&this->time = 0x3F80000000000000LL;
  this->_IsActive_k__BackingField = 1;
  v4 = Allocate(COVER_Blinder__Fade_d__7);
  _ctor(v4, 0);
  *(v4 + 4) = 0;
  v4[4] = this;
  StartCoroutine_27343696(this, v4);
}

// 0xfe12c0
void SetColor(COVER_Blinder *this, sdfColor_t color) {
  this->col = color;
}

// 0xfe1170
void SetDisp(COVER_Blinder *this, bool act) {
  _BOOL4 v3;
  UnityEngine_Component_o *transform;
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v8;

  v3 = act;
  this->col.a = 1.0;
  transform = get_transform(this, 0);
  Component_GUILayer = GetComponent_GUILayer_(transform);
  (Component_GUILayer->klass[1].vtable._0_Equals.method)(
    Component_GUILayer,
    Component_GUILayer->klass[1].vtable._1_Finalize.methodPtr,
    this->col.r,
    this->col.g,
    this->col.b,
    this->col.a);
  gameObject = get_gameObject(this);
  if (((get_activeSelf(gameObject) ^ v3) & 1) != 0)
  {
    v8 = get_gameObject(this);
    SetActive(v8, v3, 0);
  }
}

// 0xfe12e0
void SetFadeTime(COVER_Blinder *this, f32 sec) {
  this->max = sec;
}

// 0xfe1250
void SetImage(COVER_Blinder *this, void *sprite) {
  UnityEngine_Component_o *transform;
  UnityEngine_GUILayer_o *Component_GUILayer;

  transform = get_transform(this, 0);
  Component_GUILayer = GetComponent_GUILayer_(transform);
  set_sprite(Component_GUILayer, sprite);
}
