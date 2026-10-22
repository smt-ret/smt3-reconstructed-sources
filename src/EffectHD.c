#include "types.h"

typedef struct EffectHD EffectHD;
typedef struct UiHDMesh UiHDMesh;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct nbFormation_t nbFormation_t;

static s32 id_Use_MainTexture;
static s32 id_Use_LightOff;

void SetLightAll(UiHDMesh *this, void *rootobj);

// 0xfe69c0
void AddMatList(EffectHD *this, void *mat) {
  s32 id_SpecularTex;
  f32 v9;
  f32 Float;

  SetTexture_27248080(mat, id_SpecularTex, kernelObject->SpecularTexture);
  v9 = -1.0;
  if (HasProperty(mat, id_ModeOp))
  {
    Float = GetFloat(mat, id_ModeOp, 0);
    if (Float == 3.0)
    {
      SetInt_27247136(mat, id_SrcBlend, 5);
      SetInt_27247136(mat, id_DstBlend, 1);
    }
    else
    {
      v9 = Float;
    }
  }
  _Add(this->modeop_list, v9);
  if (HasProperty(mat, id_Use_FogOff))
  {
    SetFloat_27246832(mat, id_Use_FogOff, 1.0);
  }
}

// 0xfe6530
void Awake(EffectHD *this) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v7;

  v3 = Allocate(System_Collections_Generic_Dictionary_string__GameObject_);
  PropertySheet____ctor(v3);
  this->allobject = v3;
  v4 = Allocate(System_Collections_Generic_List_Material_);
  __ctor(v4);
  this->mat_list = v4;
  v5 = Allocate(System_Collections_Generic_List_float_);
  __ctor(v5);
  this->modeop_list = v5;
  gameObject = get_gameObject(this);
  (this->klass->vtable._16_SetMatInit.methodPtr)(this, gameObject, this->klass->vtable._16_SetMatInit.method);
  get_gameObject(this);
  SetLightAll(this, v7);
  *&this->renderqueue_semi = 0xC1C00000BB8LL;
  this->renderqueue_sub = 3200;
  (this->klass->vtable._15_ChangeRenderQueue.methodPtr)(this, this->klass->vtable._15_ChangeRenderQueue.method);
  this->update_rot = 1;
  this->frame = 0;
}

// 0xfe6c30
void SetForm(EffectHD *this, nbFormation_t *form) {
  this->unit_form = form;
  if (form)
    this->hunit = form->hunit;
}

// 0xfe6660
void SetLightAll(EffectHD *this, void *rootobj) {
  struct sdf3DLight_t_array *dds3DirLights;
  f32 z;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  s32 v14;
  System_WeakReference_o *Item;
  s32 id_LightColor;
  s32 id_ColorAmbient;
  s32 id_LightVector;
  UnityEngine_Vector4_o v21;
  UnityEngine_Color_o v22;
  UnityEngine_Color_o v23;
  f32 y;
  f32 x;

  if (!dds3DirLights->max_length)
    goto LABEL_8;
LABEL_6:
  x = dds3DirLights->m_Items[0]->color.x;
  y = dds3DirLights->m_Items[0]->color.y;
  z = dds3DirLights->m_Items[0]->color.z;
  v8 = dds3DirLights->m_Items[0]->v.x;
  v9 = dds3DirLights->m_Items[0]->v.y;
  v10 = dds3Ambient.z;
  v11 = dds3Ambient.x;
  v12 = dds3Ambient.y;
  v13 = dds3DirLights->m_Items[0]->v.z;
  if (_get_Count(this->mat_list) >= 1)
  {
    v14 = 0;
    do
    {
      Item = _get_Item(
               this->mat_list,
               v14);
      *&v23.r = 0;
      *&v23.b = 0;
      sub_19EC630(&v23.r, x, y, z, 1.0);
      SetColor_27247456(Item, id_LightColor, v23);
      *&v22.r = 0;
      *&v22.b = 0;
      sub_19EC630(&v22.r, v11, v12, v10, 1.0);
      SetColor_27247456(Item, id_ColorAmbient, v22);
      *&v21.x = 0;
      *&v21.z = 0;
      sub_854690(&v21.x, -v8, v9, -v13, 0.0);
      SetVector_27247776(Item, id_LightVector, v21);
      ++v14;
    }
    while (v14 < _get_Count(this->mat_list));
  }
}

// 0xfe6c50
void SetUpdateRot(EffectHD *this, s32 rot) {
  this->update_rot = rot;
}

// 0xfe6c20
void SethFrom(EffectHD *this, nbFormation_t *sFrom) {
  this->hFrom = sFrom;
}

// 0xfe6c10
void SethModel(EffectHD *this, dds3ModelHandle_t *sModel) {
  this->hModel = sModel;
}

// 0xfe6bd0
void Update(EffectHD *this) {
  UnityEngine_GameObject_o *v3;

  if (!this->blur)
  {
    get_gameObject(this);
    SetLightAll(this, v3);
  }
}
