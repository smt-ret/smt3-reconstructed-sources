#include "types.h"

typedef struct DarkZoneChk DarkZoneChk;

s32 fldLightMaChk(void);

// 0xfe4fb0
void AddMatList(DarkZoneChk *this, void *mat) {
  System_Collections_Generic_List_float__o *alf_list;
  f32 Float;
  System_Collections_Generic_List_float__o *bri_list;
  f32 v9;

  alf_list = this->alf_list;
  Float = GetFloat(mat, id_AlfPower, 0);
  _Add(alf_list, Float);
  bri_list = this->bri_list;
  v9 = GetFloat(mat, id_Adj_Bright, 0);
  _Add(bri_list, v9);
}

// 0xfe4c80
void Start(DarkZoneChk *this) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  UnityEngine_GameObject_o *gameObject;
  s64 v7;

  v3 = Allocate(System_Collections_Generic_List_Material_);
  __ctor(v3);
  this->mat_list = v3;
  v4 = Allocate(System_Collections_Generic_List_float_);
  __ctor(v4);
  this->alf_list = v4;
  v5 = Allocate(System_Collections_Generic_List_float_);
  __ctor(v5);
  this->bri_list = v5;
  gameObject = get_gameObject(this);
  (this->klass->vtable._16_SetMatInit.methodPtr)(this, gameObject, this->klass->vtable._16_SetMatInit.method);
  v7 = (this->klass->vtable._20_GetRoot.methodPtr)(this, this->klass->vtable._20_GetRoot.method);
  (*(*v7 + 648LL))(v7, this, *(*v7 + 656LL));
  (this->klass->vtable._21_UpdateOption.methodPtr)(this, this->klass->vtable._21_UpdateOption.method);
}

// 0xfe4d90
void UpdateOption(DarkZoneChk *this) {
  s32 v3;
  s32 v4;
  s32 v5;
  s32 v6;
  System_WeakReference_o *Item;
  s32 task_type;
  UnityEngine_Material_o *v10;
  f32 v11;
  s32 id_AlfPower;

  v3 = fldLightMaChk();
  v4 = v3 != 1;
  if (this->chg_mode != v4)
  {
    this->chg_mode = v4;
    v5 = v3;
    if (_get_Count(this->mat_list) >= 1)
    {
      v6 = 0;
      while (1)
      {
        Item = _get_Item(
                 this->mat_list,
                 v6);
        task_type = this->task_type;
        v10 = Item;
        if (task_type == 2 || task_type == 1)
          break;
        if (!task_type)
        {
          v11 = 0.0;
          if (v5 == 1)
            v11 = _get_Item(
                    this->alf_list,
                    v6);
LABEL_24:
          SetFloat_27246832(v10, id_AlfPower, v11);
        }
        if (++v6 >= _get_Count(this->mat_list))
          return;
      }
      v11 = 2.0;
      if (v5 == 1)
        v11 = _get_Item(
                this->bri_list,
                v6);
      SetFloat_27246832(v10, id_Adj_Bright, v11);
      SetFloat_27246832(v10, id_Adj_ColorR, v11);
      SetFloat_27246832(v10, id_Adj_ColorG, v11);
      id_AlfPower = id_Adj_ColorB;
      goto LABEL_24;
    }
  }
}
