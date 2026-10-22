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
  v3[8] = "要プラットフォーム切り替え";
  _ctor(v3, 0);
  ChangeSprite(v3, this->number, this->texPath, 0);
  this->numberSpr = v3[6];
}

// 0xfe30b0
void Change(CounterCtr *this) {
  struct UnityEngine_UI_Image_array *image;
  struct UnityEngine_Sprite_array *number;
  s32 value;
  s64 **v6;
  s32 max_length;
  s32 v8;
  bool v9;
  u32 v10;
  s32 v11;
  s64 v12;
  u64 v14;
  UnityEngine_GameObject_o *gameObject;
  struct UnityEngine_UI_Image_array *v17;
  UnityEngine_GameObject_o *v19;
  Il2CppObject *v20;
  u64 *v21;
  s64 **v22;
  s64 *v23;
  u32 v36;
  s64 colorIndex;
  Il2CppObject *v40;
  u64 *v41;
  struct UnityEngine_UI_Image_array *v42;
  UnityEngine_UI_Image_o *v44;
  System_Object_array *numberSpr;
  u64 *v46;
  Il2CppObject *object;
  struct UnityEngine_UI_Image_array *v48;
  UnityEngine_UI_Image_o *v50;
  u32 v51;
  struct UnityEngine_UI_Image_array *v53;
  s32 v55;
  s64 v56;
  s32 v57;
  s32 v58;

  image = this->image;
  number = this->number;
  value = this->value;
  v6 = &"c";
  max_length = number->max_length;
  v8 = 10 * this->colorIndex;
  v9 = v8 + 9 < max_length && v8 < max_length;
  if (!v9)
    v8 = 0;
  v57 = v8;
  v10 = image->max_length;
  v11 = 1;
  v12 = 4;
  do
  {
    v14 = v12 - 4;
    gameObject = get_gameObject(*(&image->obj.klass + v12), 0);
    if (((v11 ^ get_activeSelf(gameObject)) & 1) != 0)
    {
      v17 = this->image;
      v19 = get_gameObject(*(&v17->obj.klass + v12), 0);
      SetActive(v19, v11 & 1, 0);
    }
    if ((v11 & 1) != 0)
    {
      if ((this->colorIndex - 1) >= 6)
      {
        v48 = this->image;
        v50 = *(&v48->obj.klass + v12);
        v51 = value % 10 + v57;
        set_sprite(v50, number->m_Items[v51]);
        v53 = this->image;
        (*(**(&v53->obj.klass + v12) + 664LL))(
          *(&v53->obj.klass + v12),
          *(**(&v53->obj.klass + v12) + 672LL),
          this->color.r,
          this->color.g,
          this->color.b,
          this->color.a);
      }
      else
      {
        v20 = Allocate(CounterCtr___c__DisplayClass12_0);
        _ctor(v20, 0);
        v21 = NewSpecific(string, 7u);
        v22 = v6;
        v23 = *v6;
        v21[4] = v23;
        v21[5] = "s";
        v21[6] = "y";
        v21[7] = "r";
        v21[8] = "g";
        v21[9] = "v";
        v36 = *(v21 + 6);
        v21[10] = "b";
        colorIndex = this->colorIndex;
        v40 = v21[colorIndex + 4];
        v58 = value % 10;
        v41 = sub_8D3950(s32, &v58);
        v20[1].klass = Concat_5269984("num_", v40, v41);
        v42 = this->image;
        v44 = *(&v42->obj.klass + v12);
        numberSpr = this->numberSpr;
        v46 = Allocate(System_Predicate_Sprite_);
        __ctor(
          v46,
          v20,
          Method_CounterCtr___c__DisplayClass12_0__Change_b__0__);
        object = Find_object_(numberSpr, v46);
        set_sprite(v44, object);
        v6 = v22;
      }
      v9 = value <= 9;
      value /= 10;
      v55 = !v9;
      v11 = v55 | !this->blank;
    }
    else
    {
      v11 = 0;
    }
    image = this->image;
    v10 = image->max_length;
    v56 = v12 - 3;
    ++v12;
  }
  while (v56 < v10);
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
  struct UnityEngine_Sprite_array *number;
  struct UnityEngine_UI_Image_array *image;
  s64 **v9;
  s32 max_length;
  s32 v11;
  u32 v12;
  bool v13;
  s32 v14;
  s64 v15;
  u64 v16;
  UnityEngine_GameObject_o *gameObject;
  struct UnityEngine_UI_Image_array *v19;
  UnityEngine_GameObject_o *v21;
  Il2CppObject *v22;
  u64 *v23;
  u32 v27;
  s64 colorIndex;
  Il2CppObject *v31;
  s64 **v32;
  u64 *v33;
  struct UnityEngine_UI_Image_array *v34;
  UnityEngine_UI_Image_o *v36;
  System_Object_array *numberSpr;
  u64 *v38;
  Il2CppObject *object;
  s32 v40;
  s64 v41;
  s32 v42;
  s32 v43;

  image = this->image;
  number = this->number;
  this->value = val;
  this->colorIndex = colidx;
  v9 = &"j";
  max_length = number->max_length;
  v11 = 10 * colidx;
  v12 = image->max_length;
  v13 = 10 * colidx + 9 < max_length && v11 < max_length;
  v14 = 1;
  v15 = 4;
  if (!v13)
    v11 = 0;
  v42 = v11;
  do
  {
    v16 = v15 - 4;
    gameObject = get_gameObject(*(&image->obj.klass + v15), 0);
    if (((v14 ^ get_activeSelf(gameObject)) & 1) != 0)
    {
      v19 = this->image;
      v21 = get_gameObject(*(&v19->obj.klass + v15), 0);
      SetActive(v21, v14 & 1, 0);
    }
    if ((v14 & 1) != 0)
    {
      v22 = Allocate(CounterCtr___c__DisplayClass14_0);
      _ctor(v22, 0);
      v23 = NewSpecific(string, 2u);
      v23[4] = *v9;
      v27 = *(v23 + 6);
      v23[5] = "s";
      colorIndex = this->colorIndex;
      v31 = v23[colorIndex + 4];
      v43 = val % 10 + v42;
      v32 = v9;
      v33 = sub_8D3950(s32, &v43);
      v22[1].klass = Concat_5269984("num_ins_", v31, v33);
      v34 = this->image;
      v36 = *(&v34->obj.klass + v15);
      numberSpr = this->numberSpr;
      v38 = Allocate(System_Predicate_Sprite_);
      __ctor(
        v38,
        v22,
        Method_CounterCtr___c__DisplayClass14_0__SetInstitutionColor_b__0__);
      object = Find_object_(numberSpr, v38);
      set_sprite(v36, object);
      v13 = val <= 9;
      val /= 10;
      v40 = !v13;
      v14 = v40 | !this->blank;
      v9 = v32;
    }
    else
    {
      v14 = 0;
    }
    image = this->image;
    v12 = image->max_length;
    v41 = v15 - 3;
    ++v15;
  }
  while (v41 < v12);
}
