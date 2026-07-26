#include "types.h"

typedef struct FieldChrHD FieldChrHD;
typedef struct Zanzou Zanzou;
typedef struct Zanzou__Zanzou1_d__14 Zanzou__Zanzou1_d__14;
typedef struct Zanzou__ZanzouMake_d__13 Zanzou__ZanzouMake_d__13;

struct Zanzou__ZanzouMake_d__13 {
    s32 __1__state;
    void *__2__current;
    Zanzou *__4__this;
    f32 waitTime;
    s32 _i_5__2;
};

struct Zanzou__Zanzou1_d__14 {
    s32 __1__state;
    void *__2__current;
    Zanzou *__4__this;
    s32 i;
    f32 _alf_speed_5__2;
    s32 _queue_5__3;
    f32 _alf_5__4;
};

bool ChkMotion(FieldChrHD *this, s32 motion);
void SetTransparent(void *obj, u32 rgba, f32 alfrgb);

// 0x1310cf0
void *GetOptionMaterial(Zanzou *this, s32 idx) {
  struct System_Collections_Generic_List_Material__array *mat_list_d;
  il2cpp_array_size_t max_length;
  u64 v7;
  System_Collections_Generic_List_datEncount_t__o *v9;
  s32 Count;

  mat_list_d = this->mat_list_d;
  if (!mat_list_d)
    return 0;
  max_length = mat_list_d->max_length;
  if (max_length < 1)
    return 0;
  v7 = 0;
  while (1)
  {
    v9 = mat_list_d->m_Items[v7];
    if (_get_Count(v9) > idx)
      break;
    Count = _get_Count(v9);
    LODWORD(max_length) = mat_list_d->max_length;
    ++v7;
    idx -= Count;
    if (v7 >= max_length)
      return 0;
  }
  return _get_Item(
           v9,
           idx);
}

// 0x1310750
void OnDestroy(Zanzou *this) {
  struct System_Collections_Generic_List_Material__array *mat_list_d;
  u64 v4;
  s32 v5;
  s32 Count;
  struct System_Collections_Generic_List_Material__array *v8;
  s32 v9;
  System_Collections_Generic_List_PostProcessVolume__o *v11;

  mat_list_d = this->mat_list_d;
  if (mat_list_d && SLODWORD(mat_list_d->max_length) >= 1)
  {
    v4 = 0;
    v5 = 0;
    while (1)
    {
      while (1)
      {
        Count = _get_Count(mat_list_d->m_Items[v4]);
        v8 = this->mat_list_d;
        v9 = Count;
        v11 = v8->m_Items[v4];
        if (v5 >= v9)
          break;
        _set_Item(v11, v5, 0);
        mat_list_d = this->mat_list_d;
        ++v5;
        if (v4 >= LODWORD(mat_list_d->max_length))
      }
      _Clear(v11);
      mat_list_d = this->mat_list_d;
      if (++v4 >= SLODWORD(mat_list_d->max_length))
        break;
      v5 = 0;
      if (v4 >= LODWORD(mat_list_d->max_length))
    }
  }
}

// 0x13108a0
void OnEnable(Zanzou *this) {
  struct System_Collections_Generic_List_Material__array *mat_list_d;
  s32 v5;

  if (this->dvlno == 90)
  {
    mat_list_d = this->mat_list_d;
    this->isRunning = 0;
    if (mat_list_d)
    {
      if (SLODWORD(mat_list_d->max_length) >= 1)
      {
        v5 = 0;
        do
          SetTransparent(this, 0.0, 3000, v5++);
        while (v5 < SLODWORD(this->mat_list_d->max_length));
      }
    }
  }
}

// 0x1310930
void SetTransparent(Zanzou *this, f32 alf, s32 queue, s32 idx) {
  s32 v9;
  struct System_Collections_Generic_List_Material__array *mat_list_d;
  struct System_Collections_Generic_List_Material__array *v12;
  System_WeakReference_o *Item;

  v9 = 0;
  mat_list_d = this->mat_list_d;
  while (v9 < _get_Count(mat_list_d->m_Items[idx]))
  {
    v12 = this->mat_list_d;
    Item = _get_Item(
             v12->m_Items[idx],
             v9);
    SetOverrideTag(Item, StringLiteral_4782, StringLiteral_4783);
    SetInt_27247136(Item, id_BlendOp, 0);
    SetInt_27247136(Item, id_SrcBlend, 5);
    SetInt_27247136(Item, id_DstBlend, 10);
    SetInt_27247136(Item, id_ZWrite, 1);
    DisableKeyword(Item, StringLiteral_4784);
    EnableKeyword(Item, StringLiteral_4785);
    DisableKeyword(Item, StringLiteral_4786);
    DisableKeyword(Item, StringLiteral_4787);
    set_renderQueue(Item, queue);
    SetFloat_27246832(Item, id_AlfPower, alf);
    ++v9;
    mat_list_d = this->mat_list_d;
    if (LODWORD(mat_list_d->max_length) <= idx)
  }
}

// 0x13103f0
void Start(Zanzou *this) {
  struct System_Collections_Generic_List_Material__array *v3;
  struct UnityEngine_GameObject_array *zanzou_obj;
  s64 v5;
  u64 *v7;
  struct UnityEngine_GameObject_array *v8;
  u32 *mat_list_d;
  struct System_Collections_Generic_List_Material__o *mat_list;
  s64 v13;
  Il2CppObject *Component_object;

  v3 = NewSpecific(
         System_Collections_Generic_List_Material_,
         LODWORD(this->zanzou_obj->max_length));
  zanzou_obj = this->zanzou_obj;
  this->mat_list_d = v3;
  if (SLODWORD(zanzou_obj->max_length) >= 1)
  {
    v5 = 4;
    do
    {
      v7 = Allocate(System_Collections_Generic_List_Material_);
      __ctor(v7);
      this->mat_list = v7;
      v8 = this->zanzou_obj;
      (this->klass->vtable._16_SetMatInit.methodPtr)(
        this,
        *(&v8->obj.klass + v5),
        this->klass->vtable._16_SetMatInit.method);
      mat_list_d = this->mat_list_d;
      mat_list = this->mat_list;
      *&mat_list_d[2 * v5] = mat_list;
      v13 = v5 - 3;
      ++v5;
    }
    while (v13 < SLODWORD(this->zanzou_obj->max_length));
  }
  this->mat_list = 0;
  Component_object = GetComponent_object_(this->dvl_obj);
  if (op_Inequality(Component_object, 0, 0))
    (Component_object->klass->vtable[22].methodPtr)(Component_object, this, Component_object->klass->vtable[22].method);
}

// 0x13105e0
void Update(Zanzou *this) {
    ChkMotion(0, 0);
}

// 0x1310c40
void *Zanzou1(Zanzou *this, s32 i) {
  u64 *v5;

  v5 = Allocate(Zanzou__Zanzou1_d__14);
  _ctor(v5, 0);
  *(v5 + 4) = 0;
  v5[4] = this;
  *(v5 + 10) = i;
  return v5;
}

// 0x1310b90
void *ZanzouMake(Zanzou *this, f32 waitTime) {
  u64 *v5;

  v5 = Allocate(Zanzou__ZanzouMake_d__13);
  _ctor(v5, 0);
  *(v5 + 4) = 0;
  v5[4] = this;
  *(v5 + 10) = waitTime;
  return v5;
}
