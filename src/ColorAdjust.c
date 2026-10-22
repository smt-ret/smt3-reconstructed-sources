#include "types.h"

typedef struct ColorAdjust ColorAdjust;

static s32 id_Adj_ColorRGBA;

// 0xfe2c30
void Awake(ColorAdjust *this) {
  ;
}

// 0xfe2e10
void OnDisable(ColorAdjust *this) {
  UnityEngine_Object_o *material;
  UnityEngine_Object_o *v5;

  material = this->material;
  if (op_Inequality(material, 0, 0))
  {
    v5 = this->material;
    DestroyImmediate_27360336(v5);
  }
  this->material = 0;
}

// 0xfe2d90
void OnEnable(ColorAdjust *this) {
  UnityEngine_Shader_o *shader;
  u64 *v4;

  shader = this->shader;
  v4 = Allocate(UnityEngine_Material);
  _ctor(v4, shader, 0);
  this->material = v4;
  set_hideFlags(v4, 61);
}

// 0xfe2ec0
void OnRenderImage(ColorAdjust *this, void *source, void *dest) {
  UnityEngine_Material_o *material;

  material = this->material;
  Blit_27233792(source, dest, material);
}

// 0xfe2c40
void Update(ColorAdjust *this) {
  UnityEngine_Object_o *material;
  UnityEngine_Material_o *v6;
  UnityEngine_Material_o *v9;
  s32 id_Adj_ColorRGBA;
  f32 *static_fields;
  f32 v13;
  f32 v14;
  f32 v15;
  UnityEngine_Color_o v16;

  material = this->material;
  if (op_Inequality(material, 0, 0))
  {
    v6 = this->material;
    if (HasProperty(v6, id_Adj_ColorRGBA))
    {
      v9 = this->material;
      v13 = static_fields[192];
      v14 = static_fields[193];
      v15 = static_fields[194];
      *&v16.r = 0;
      *&v16.b = 0;
      sub_19EC630(&v16.r, v13, v14, v15, 1.0);
      SetColor_27247456(v9, id_Adj_ColorRGBA, v16);
    }
  }
}
