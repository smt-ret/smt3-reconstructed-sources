#include "types.h"

typedef struct ChangeTex ChangeTex;
typedef struct CounterCtr CounterCtr;
typedef struct buttonguideUI buttonguideUI;

void Change(buttonguideUI *this, s32 setNum, s32 setSpr);
void ChangeSprite(ChangeTex *this, void **sprData, char *loadPath, bool checkPlatform);

// 0xfe2fd0
void Awake(CounterCtr *this) {
  u64 *v3;

  v3 = Allocate(ChangeTex);
  v3[8] = StringLiteral_4649;
  _ctor(v3, 0);
  ChangeSprite(v3, this->number, this->texPath, 0);
  this->numberSpr = v3[6];
}

// 0xfe30b0
void Change(CounterCtr *this) {
}

// 0xfe37f0
bool CheckColChange(CounterCtr *this) {
  s32 colorIndex;

  colorIndex = this->colorIndex;
  return colorIndex >= 1 && colorIndex < 7;
}

// 0xfe3090
void Set(CounterCtr *this, s32 val, sdfColor_t col, s32 colidx) {
  this->value = val;
  this->colorIndex = colidx;
  this->color = col;
  Change(this, *&val);
}

// 0xfe36a0
void Set2(CounterCtr *this, s32 val, sdfColor_t col, s32 colidx) {
  s32 colorIndex;
  long f64 v6;
  long f64 v7;
  long f64 v8;
  _BOOL4 v10;
  s32 v12;
  struct UnityEngine_UI_Image_array *image;
  il2cpp_array_size_t max_length;
  u64 v16;
  UnityEngine_Color_o color;
  UnityEngine_Color_o v19;

  colorIndex = this->colorIndex;
  v6 = *&col.a;
  v7 = *&col.b;
  v8 = *&col.g;
  color = this->color;
  v19.r = col.r;
  v10 = this->value != val;
  v19.g = *&v8;
  v19.b = *&v7;
  v19.a = *&v6;
  this->value = val;
  this->colorIndex = colidx;
  v12 = val == 0 || v10 || colorIndex != colidx;
  if (op_Inequality(color, v19, 0))
  {
    image = this->image;
    max_length = image->max_length;
    if (max_length >= 1)
    {
      v16 = 0;
      do
      {
        (image->m_Items[v16]->klass->vtable._27_SetLayoutDirty.methodPtr)(
          image->m_Items[v16],
          image->m_Items[v16]->klass->vtable._27_SetLayoutDirty.*&col,
          v8,
          v7,
          v6);
        image = this->image;
        LODWORD(max_length) = image->max_length;
        ++v16;
      }
      while (v16 < max_length);
    }
  }
  this->color.r = col.r;
  this->color.g = *&v8;
  this->color.b = *&v7;
  this->color.a = *&v6;
  if (v12)
    Change(this);
}

// 0xfe37d0
void SetColor(CounterCtr *this, sdfColor_t col) {
  this->color = col;
  Change(this);
}

// 0xfe3820
void SetInstitutionColor(CounterCtr *this, s32 val, s32 colidx) {
}
