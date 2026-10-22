#include "types.h"

typedef struct UiHDMesh UiHDMesh;

f32 GetConfigBright(void);
void SetLightAll(UiHDMesh *this, void *rootobj);
void SetMatInit(UiHDMesh *this, void *rootobj);

// 0x1349010
void Awake(UiHDMesh *this) {
  u64 *v3;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v6;

  v3 = Allocate(System_Collections_Generic_List_Material_);
  __ctor(v3);
  this->mat_list = v3;
  gameObject = get_gameObject(this);
  SetMatInit(this, gameObject);
  get_gameObject(this);
  SetLightAll(this, v6);
  this->id_Config_Bright = -1;
}

// 0x1349150
void SetLightAll(UiHDMesh *this, void *rootobj) {
  f32 ConfigBright;
  s32 v5;
  System_WeakReference_o *Item;
  s32 id_Config_Bright;

  ConfigBright = GetConfigBright();
  if (_get_Count(this->mat_list) >= 1)
  {
    v5 = 0;
    do
    {
      Item = _get_Item(
               this->mat_list,
               v5);
      if (HasProperty_27243776(Item, "_Config_Bright"))
      {
        id_Config_Bright = this->id_Config_Bright;
        if (id_Config_Bright == -1)
        {
          id_Config_Bright = PropertyToID("_Config_Bright");
          this->id_Config_Bright = id_Config_Bright;
        }
        SetFloat_27246832(Item, id_Config_Bright, ConfigBright);
      }
      ++v5;
    }
    while (v5 < _get_Count(this->mat_list));
  }
}

// 0x13490b0
void SetMatInit(UiHDMesh *this, void *rootobj) {
  UnityEngine_Transform_o *transform;
  s32 v6;
  UnityEngine_Transform_o *v7;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v11;

  transform = get_transform(rootobj, 0);
  if (get_childCount(transform) >= 1)
  {
    v6 = 0;
    do
    {
      v7 = get_transform(rootobj, 0);
      Child = GetChild(v7, v6);
      gameObject = get_gameObject(Child);
      SetMatInit(this, gameObject);
      ++v6;
      v11 = get_transform(rootobj, 0);
    }
    while (v6 < get_childCount(v11));
  }
}

// 0x1349350
void SetMatrial(UiHDMesh *this, void *mat) {
  _Add(this->mat_list, mat);
}

// 0x13493b0
void SetOutLineChk(UiHDMesh *this, bool chk) {
  this->outlinechk = chk;
}

// 0x1349270
void Start(UiHDMesh *this) {
  _BOOL4 outlinechk;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;

  outlinechk = this->outlinechk;
  this->outline = 0;
  if (outlinechk)
  {
    gameObject = get_gameObject(this);
    Component_object = GetComponent_object_(gameObject);
    if (op_Inequality(Component_object, 0, 0))
      this->outline = 1;
  }
}

// 0x1349320
void Update(UiHDMesh *this) {
  UnityEngine_GameObject_o *v3;

  get_gameObject(this);
  SetLightAll(this, v3);
}
