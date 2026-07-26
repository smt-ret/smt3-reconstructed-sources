#include "types.h"

typedef struct XRD773Unity_CommonSprite XRD773Unity_CommonSprite;

// 0x130f440
void Awake(XRD773Unity_CommonSprite *this) {
  u64 *v3;

  v3 = Allocate(UnityEngine_MaterialPropertyBlock);
  _ctor(v3, 0);
  this->block = v3;
}

// 0x130f810
void SetColor(XRD773Unity_CommonSprite *this, f32 r, f32 g, f32 b) {
}

// 0x130f860
void SetColor_19986528(XRD773Unity_CommonSprite *this, s32 r, s32 g, s32 b) {
}

// 0x130f8d0
void SetColor_19986640(XRD773Unity_CommonSprite *this, s32 lv) {
}

// 0x130f940
void SetSprite(XRD773Unity_CommonSprite *this, void *sprite) {
  set_sprite(this->_renderer, sprite);
}

// 0x130f4a0
void Setting(XRD773Unity_CommonSprite *this) {
  UnityEngine_MaterialPropertyBlock_o *block;
  s32 main_tex_id;
  UnityEngine_Sprite_o *sprite;
  UnityEngine_Texture_o *texture;
  UnityEngine_MaterialPropertyBlock_o *v11;

  Clear_27250688(this->block);
  block = this->block;
  {
  }
  sprite = get_sprite(this->_renderer);
  texture = get_texture(sprite);
  SetTexture_27252016(block, main_tex_id, texture);
  if (this->use_palette)
  {
    v11 = this->block;
    {
    }
    SetTexture_27252016(v11, palette_id, this->palette);
  }
  SetPropertyBlock(this->_renderer, this->block);
}

// 0x130f5b0
void _SetDrawMode(XRD773Unity_CommonSprite *this, s32 mode) {
  struct UnityEngine_Material_array *palette_mat;
  s64 v7;

  if (this->use_palette)
  {
    {
    }
    palette_mat = get_Instance()->palette_mat;
    v7 = mode;
    if (LODWORD(palette_mat->max_length) <= mode)
  }
  else
  {
    {
    }
    palette_mat = get_Instance()->commonmesh_mat;
    v7 = mode;
  }
  (this->klass->vtable._5__SetMaterial.methodPtr)(
    this,
    palette_mat->m_Items[v7],
    this->klass->vtable._5__SetMaterial.method);
}

// 0x130f5a0
void _SetMaterial(XRD773Unity_CommonSprite *this, void *material) {
  set_sharedMaterial(this->_renderer, material);
}
