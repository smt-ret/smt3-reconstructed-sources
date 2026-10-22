#include "types.h"

typedef struct FlipAnimation FlipAnimation;

// 0x113d520
void Start(FlipAnimation *this) {
  UnityEngine_Renderer_o *Component_GUILayer;
  struct UnityEngine_Material_o *sharedMaterial;
  struct UnityEngine_Texture_array *Images;
  il2cpp_array_size_t max_length;

  Component_GUILayer = GetComponent_GUILayer_(this);
  sharedMaterial = get_sharedMaterial(Component_GUILayer);
  Images = this->Images;
  this->mat = sharedMaterial;
  this->stepcnt = 0;
  max_length = Images->max_length;
  this->StartFlag = 0;
  this->max = max_length;
  SetTexture(sharedMaterial, "_MainTex", Images->m_Items[0], 0);
}

// 0x113d5d0
void Update(FlipAnimation *this) {
  s32 max;
  s64 stepcnt;
  s64 v5;
  UnityEngine_Material_o *mat;
  struct UnityEngine_Texture_array *Images;

  max = this->max;
  stepcnt = this->stepcnt;
  v5 = stepcnt + 1;
  this->stepcnt = stepcnt + 1;
  if (stepcnt + 1 < max)
  {
    mat = this->mat;
    Images = this->Images;
    SetTexture(mat, "_MainTex", Images->m_Items[v5], 0);
  }
}
