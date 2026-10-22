#include "types.h"

typedef struct GunHD GunHD;
typedef struct UiHDMesh UiHDMesh;
typedef struct evtUnitHandle_t evtUnitHandle_t;

sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SetLightAll(UiHDMesh *this, void *rootobj);

// 0x1148c50
void SetEveUnit(GunHD *this, evtUnitHandle_t *hunit_tmp) {
  this->hunit = hunit_tmp;
}

// 0x1148ae0
void SetLightAll(GunHD *this) {
  s32 v3;
  System_WeakReference_o *Item;
  UnityEngine_Vector4_o v7;
  UnityEngine_Color_o v8;

  *&v8.r = 0;
  *&v8.b = 0;
  *&v7.x = 0;
  *&v7.z = 0;
  sub_19EC630(&v8.r, this->l0_r, this->l0_g, this->l0_b, this->l0_a);
  sub_854690(&v7.x, this->v0_x, this->v0_y, this->v0_z, 0.0);
  if (_get_Count(this->mat_list) >= 1)
  {
    v3 = 0;
    do
    {
      Item = _get_Item(
               this->mat_list,
               v3);
      SetColor_27247456(Item, id_LightColor, v8);
      SetVector_27247776(Item, id_LightVector, v7);
      SetFloat_27246832(Item, id_ToonType, 8.0);
      ++v3;
    }
    while (v3 < _get_Count(this->mat_list));
  }
}

// 0x11489a0
void Start(GunHD *this) {
  u64 *v3;
  UnityEngine_GameObject_o *gameObject;
  s64 v5;

  v3 = Allocate(System_Collections_Generic_List_Material_);
  __ctor(v3);
  this->mat_list = v3;
  gameObject = get_gameObject(this);
  (this->klass->vtable._16_SetMatInit.methodPtr)(this, gameObject, this->klass->vtable._16_SetMatInit.method);
  v5 = (this->klass->vtable._20_GetRoot.methodPtr)(this, this->klass->vtable._20_GetRoot.method);
  (*(*v5 + 648LL))(v5, this, *(*v5 + 656LL));
}

// 0x1148a50
void UpdateOption(GunHD *this) {
  struct evtUnitHandle_t_o *hunit;
  struct evtUnitHandle_t_o *v4;
  f32 z;
  UnityEngine_Vector4_o v6;

  hunit = this->hunit;
  if (hunit)
  {
    v6 = SDF_VU0__Retdds3ColorItoF(hunit->NowLightRGB, 128.0);
    this->l0_a = 1.0;
    v4 = this->hunit;
    this->l0_r = v6.x;
    this->l0_g = v6.y;
    this->l0_b = v6.z;
    this->v0_x = v4->NowLightDir.x / -100.0;
    this->v0_y = v4->NowLightDir.y / -100.0;
    z = v4->NowLightDir.z;
    this->_ToonTypeStart_Offset = 0.15;
    this->v0_z = z / -100.0;
  }
  SetLightAll(this);
}
