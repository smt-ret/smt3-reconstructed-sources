#include "types.h"

typedef struct PostBlur PostBlur;
typedef struct PostBlur_BlendType PostBlur_BlendType;

struct PostBlur_BlendType {
    s32 value__;
};

f32 GetConfigBright(void);
void dds3FadeColorGet(u32 *r, u32 *g, u32 *b, u32 *a);
u32 dds3GetKernelCount(void);
s32 encModeGet(void);
f32 perlinNoise(PostBlur *this, sdfVector2_t *uv, sdfVector2_t *size);

// 0x188e590
void Awake(PostBlur *this) {
    perlinNoise(0, 0, 0);
}

// 0x188f520
void OnDisable(PostBlur *this) {
  UnityEngine_Object_o *accumTexture;
  struct UnityEngine_RenderTexture_o **p_accumTexture;
  UnityEngine_Object_o *v6;
  UnityEngine_Object_o *material;
  UnityEngine_Object_o *v9;
  UnityEngine_Object_o *Adjust_material;
  UnityEngine_Object_o *v12;
  UnityEngine_Object_o *Encount1st_material;
  UnityEngine_Object_o *v15;

  accumTexture = this->accumTexture;
  p_accumTexture = &this->accumTexture;
  if (op_Inequality(accumTexture, 0, 0))
  {
    v6 = *p_accumTexture;
    DestroyImmediate_27360336(v6);
  }
  material = this->material;
  if (op_Inequality(material, 0, 0))
  {
    v9 = this->material;
    DestroyImmediate_27360336(v9);
  }
  *p_accumTexture = 0;
  this->material = 0;
  Adjust_material = this->Adjust_material;
  if (op_Inequality(Adjust_material, 0, 0))
  {
    v12 = this->Adjust_material;
    DestroyImmediate_27360336(v12);
  }
  this->Adjust_material = 0;
  Encount1st_material = this->Encount1st_material;
  if (op_Inequality(Encount1st_material, 0, 0))
  {
    v15 = this->Encount1st_material;
    DestroyImmediate_27360336(v15);
  }
  this->Encount1st_material = 0;
}

// 0x188f420
void OnEnable(PostBlur *this) {
  UnityEngine_Shader_o *shader;
  u64 *v4;
  UnityEngine_Shader_o *Adjust_shader;
  u64 *v6;
  UnityEngine_Shader_o *Encount1st_shader;
  u64 *v8;

  shader = this->shader;
  v4 = Allocate(UnityEngine_Material);
  _ctor(v4, shader, 0);
  this->material = v4;
  set_hideFlags(v4, 61);
  Adjust_shader = this->Adjust_shader;
  v6 = Allocate(UnityEngine_Material);
  _ctor(v6, Adjust_shader, 0);
  this->Adjust_material = v6;
  set_hideFlags(v6, 61);
  Encount1st_shader = this->Encount1st_shader;
  v8 = Allocate(UnityEngine_Material);
  _ctor(v8, Encount1st_shader, 0);
  this->Encount1st_material = v8;
  set_hideFlags(v8, 61);
  SetTexture_27248080(this->material, this->_DistortionTexID, this->distTexture);
}

// 0x188fd20
void OnRenderImage(PostBlur *this, void *source, void *destination) {
    dds3FadeColorGet(0, 0, 0, 0);
    GetConfigBright();
    encModeGet();
}

// 0x188f6e0
void Update(PostBlur *this) {
    dds3GetKernelCount();
}

// 0x188e4e0
sdfVector3_t normalNoise(PostBlur *this, sdfVector2_t *uv, sdfVector2_t *size) {
  f32 y;
  f32 v5;
  UnityEngine_Vector2_o *p_normalNoise_uv2;
  UnityEngine_Vector2_o *p_normalNoise_size2;
  f32 v11;
  f32 v12;
  UnityEngine_Vector3_o result;

  y = uv->y;
  this->normalNoise_uv2.x = uv->x;
  this->normalNoise_uv2.y = y;
  v5 = size->y;
  p_normalNoise_uv2 = &this->normalNoise_uv2;
  p_normalNoise_size2 = &this->normalNoise_size2;
  this->normalNoise_size2.x = size->x;
  this->normalNoise_size2.y = v5;
  this->normalNoise_ret.x = perlinNoise(this, &this->normalNoise_uv2, &this->normalNoise_size2);
  v11 = uv->y;
  this->normalNoise_uv2.x = uv->x + 2.0;
  this->normalNoise_uv2.y = v11 + 2.0;
  v12 = size->y;
  this->normalNoise_size2.x = size->x;
  this->normalNoise_size2.y = v12;
  result.y = perlinNoise(this, p_normalNoise_uv2, p_normalNoise_size2);
  this->normalNoise_ret.y = result.y;
  this->normalNoise_ret.z = 1.0;
  result.x = this->normalNoise_ret.x;
  result.z = 1.0;
  return result;
}

// 0x188e2f0
f32 perlinNoise(PostBlur *this, sdfVector2_t *uv, sdfVector2_t *size) {
  f32 y;
  f32 x;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  UnityEngine_Vector2_o v24;
  UnityEngine_Vector2_o v25;
  UnityEngine_Vector2_o v26;
  UnityEngine_Vector2_o v27;
  UnityEngine_Vector2_o v28;

  x = uv->x;
  y = uv->y;
  v28.x = x;
  v28.y = y;
  v24 = op_Multiply_8725248(v28, 2.0);
  this->perlinNoise_uv2 = v24;
  v10 = size->x;
  v11 = size->y;
  this->perlinNoise_size2.x = size->x;
  this->perlinNoise_size2.y = v11;
  v12 = v10;
  v13 = v11;
  v14 = PerlinNoise(v24.x * v12, v24.y * v13);
  v25 = op_Multiply_8725248(*uv, 4.0);
  this->perlinNoise_uv2 = v25;
  v15 = size->y;
  v16 = v25.x * size->x;
  this->perlinNoise_size2.x = size->x;
  this->perlinNoise_size2.y = v15;
  v17 = PerlinNoise(v16, v25.y * v15);
  v26 = op_Multiply_8725248(*uv, 8.0);
  this->perlinNoise_uv2 = v26;
  v18 = size->y;
  v19 = v26.x * size->x;
  this->perlinNoise_size2.x = size->x;
  this->perlinNoise_size2.y = v18;
  v20 = PerlinNoise(v19, v26.y * v18);
  v27 = op_Multiply_8725248(*uv, 16.0);
  this->perlinNoise_uv2 = v27;
  v21 = size->y;
  v22 = v27.x * size->x;
  this->perlinNoise_size2.x = size->x;
  this->perlinNoise_size2.y = v21;
  return ((((v14 * 0.5) + 0.0) + (v17 * 0.25)) + (v20 * 0.125))
       + (PerlinNoise(v22, v27.y * v21) * 0.0625);
}
