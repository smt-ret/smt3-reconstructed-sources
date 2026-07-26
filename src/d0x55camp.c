#include "types.h"

typedef struct FieldChrHD FieldChrHD;
typedef struct d0x55camp d0x55camp;

f32 GetBattle(FieldChrHD *this);
void SetCampD0x55(FieldChrHD *this);

// 0x161f220
void Start(d0x55camp *this) {
  this->chg = 0;
}

// 0x161f230
void Update(d0x55camp *this) {
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;

  gameObject = get_gameObject(this);
  Component_object = GetComponent_object_(gameObject);
  if (op_Inequality(Component_object, 0, 0)
    && GetBattle(Component_object) == 3.0
    && !this->chg)
  {
    SetCampD0x55(Component_object);
  }
}
