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
}
