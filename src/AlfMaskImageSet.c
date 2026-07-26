#include "types.h"

typedef struct AlfMaskImageSet AlfMaskImageSet;

// 0xfd6270
void Awake(AlfMaskImageSet *this) {
  Il2CppObject *Component_object;
  Il2CppObject *v4;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v6;
  UnityEngine_Material_o *v7;
  UnityEngine_Sprite_o *sprite;
  UnityEngine_Texture_o *texture;
  UnityEngine_Vector3_o localPosition;

  Component_object = GetComponent_object_(this->maskobject);
  v4 = GetComponent_object_(this->moveobject);
  transform = get_transform(this->maskobject, 0);
  get_localPosition(transform);
  v6 = get_transform(this->moveobject, 0);
  localPosition = get_localPosition(v6);
  v7 = (v4->klass->vtable[32].methodPtr)(
         v4,
         v4->klass->vtable[32].localPosition.x,
         localPosition.y,
         localPosition.z);
  sprite = get_sprite(Component_object);
  texture = get_texture(sprite);
  SetTexture(v7, StringLiteral_4569, texture, 0);
  SetFloat(v7, StringLiteral_4570, 1.0);
}

// 0xfd6370
void Update(AlfMaskImageSet *this) {
  Il2CppObject *Component_object;
  UnityEngine_Transform_o *transform;
  f32 x;
  UnityEngine_Material_o *v6;

  Component_object = GetComponent_object_(this->moveobject);
  transform = get_transform(this->moveobject, 0);
  x = get_localPosition(transform).x;
  v6 = (Component_object->klass->vtable[32].methodPtr)(Component_object, Component_object->klass->vtable[32].method);
  SetFloat(v6, StringLiteral_4571, (x + this->lr_offset) * 0.00048828, 0);
}
