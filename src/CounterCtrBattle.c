#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct CounterCtrBattle CounterCtrBattle;
typedef struct buttonguideUI buttonguideUI;

void Change(buttonguideUI *this, s32 setNum, s32 setSpr);
void **LoadSprite(AssetBundleCtrl *this, char *key, char *path, char *name);

// 0xfe3c10
void Awake(CounterCtrBattle *this) {
  AssetBundleCtrl_o *asset_bc;

  asset_bc = get_asset_bc();
  this->numberSpr = LoadSprite(asset_bc, StringLiteral_4611, StringLiteral_4658, StringLiteral_4659);
}

// 0xfe3cd0
void Change(CounterCtrBattle *this) {
  struct UnityEngine_Sprite_array *number;
  struct UnityEngine_UI_Image_array *image;
  s64 v4;
  s32 value;
  s32 max_length;
  s32 v7;
  u32 v8;
  bool v9;
  s32 v11;
  s32 v12;
  u64 v13;
  UnityEngine_GameObject_o *gameObject;
  struct UnityEngine_UI_Image_array *v16;
  UnityEngine_GameObject_o *v18;
  struct UnityEngine_UI_Image_array *v19;
  UnityEngine_UI_Image_o *v21;
  u32 v22;
  struct UnityEngine_UI_Image_array *v24;
  s32 v26;
  s64 v27;

  image = this->image;
  number = this->number;
  v4 = 4;
  value = this->value;
  max_length = number->max_length;
  v7 = 10 * this->colorIndex;
  v8 = image->max_length;
  v9 = v7 + 9 < max_length && v7 < max_length;
  v11 = 1;
  if (v9)
    v12 = 10 * this->colorIndex;
  else
    v12 = 0;
  do
  {
    v13 = v4 - 4;
    gameObject = get_gameObject(*(&image->obj.klass + v4), 0);
    if (((v11 ^ get_activeSelf(gameObject)) & 1) != 0)
    {
      v16 = this->image;
      v18 = get_gameObject(*(&v16->obj.klass + v4), 0);
      SetActive(v18, v11 & 1, 0);
    }
    if ((v11 & 1) != 0)
    {
      v19 = this->image;
      v21 = *(&v19->obj.klass + v4);
      v22 = value % 10 + v12;
      set_sprite(v21, number->m_Items[v22]);
      v24 = this->image;
      (*(**(&v24->obj.klass + v4) + 664LL))(
        *(&v24->obj.klass + v4),
        *(**(&v24->obj.klass + v4) + 672LL),
        this->color.r,
        this->color.g,
        this->color.b,
        this->color.a);
      v9 = value <= 9;
      value /= 10;
      v26 = !v9;
      v11 = v26 | !this->blank;
    }
    else
    {
      v11 = 0;
    }
    image = this->image;
    v8 = image->max_length;
    v27 = v4 - 3;
    ++v4;
  }
  while (v27 < v8);
}

// 0xfe3eb0
bool CheckColChange(CounterCtrBattle *this) {
  s32 colorIndex;

  colorIndex = this->colorIndex;
  return colorIndex >= 1 && colorIndex < 6;
}

// 0xfe3cb0
void Set(CounterCtrBattle *this, s32 val, sdfColor_t col, s32 colidx) {
  this->value = val;
  this->colorIndex = colidx;
  this->color = col;
  Change(this, *&val);
}
