#include "types.h"

typedef struct TMPEffect TMPEffect;
typedef struct TMPEffect_FADEMODE TMPEffect_FADEMODE;
typedef struct TMPEffect_TMPData TMPEffect_TMPData;
typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;

struct TMPEffect_TMPData {
    s32 type;
    s32 s_type;
    void *obj;
    void *scr;
    sdfColor_t color;
    f32 radd;
    f32 gadd;
    f32 badd;
    s32 count;
};

struct TMPEffect_FADEMODE {
    s32 value__;
};

static s32 TABLEMAX;
static f32 FADEFRAME;
static sdfColor32_t pC1;
static sdfColor32_t pC2;

bool IsAlready(TMPEffect *this, void *obj, s32 mode, s32 type);
void SetColor(XRD773Unity_CommonMesh *this, void col, s32 length);

// 0x1344d10
void Clear(TMPEffect_TMPData *this) {
  *&this->color.r = 0;
  *&this->color.b = 0;
  this->scr = 0;
  *(this + 7) = 0;
  *(this + 8) = 0;
}

// 0x1344020
bool IsAlready(TMPEffect *this, void *obj, s32 mode, s32 type) {
  s64 v9;
  u64 v10;
  struct TMPEffect_TMPData_array *list;
  struct TMPEffect_TMPData_array *v14;
  struct TMPEffect_TMPData_array *v16;
  struct TMPEffect_TMPData_array *v18;

  v9 = 0;
  v10 = 0;
  {
  }
  while (v10 < TABLEMAX)
  {
    list = this->list;
    if (list->m_Items[v9].type)
    {
      v14 = this->list;
      if (v14->m_Items[v9].type == mode)
      {
        v16 = this->list;
        if (v16->m_Items[v9].s_type == type)
        {
          v18 = this->list;
          if (((v18->m_Items[v9].obj->klass->vtable._0_Equals.methodPtr)(
                  v18->m_Items[v9].obj,
                  obj,
                  v18->m_Items[v9].obj->klass->vtable._0_Equals.*&type)
              & 1) != 0)
            return 1;
        }
      }
    }
    ++v10;
    ++v9;
  }
  return 0;
}

// 0x1342e00
void ResetTMPEffect(TMPEffect *this) {
}

// 0x1344360
void Scroll(TMPEffect *this, void *obj, s32 top, s32 dir) {
}

// 0x13425a0
void Start(TMPEffect *this) {
  s64 v3;
  u64 v4;
  u64 *v6;
  struct TMPEffect_TMPData_array *list;
  u64 *v9;
  struct TMPEffect_TMPData_array *v10;

  v3 = 0;
  v4 = 0;
  {
  }
  while (v4 < TABLEMAX)
  {
    list = this->list;
    v9 = (&list->obj.klass + v3);
    v9[9] = 0;
    v9[10] = 0;
    v9[7] = 0;
    v9[8] = 0;
    v9[4] = 0;
    v9[5] = 0;
    v9[6] = 0;
    v10 = this->list;
    v6 = (&v10->obj.klass + v3);
    ++v4;
    v3 += 56;
    v6[5] = 0;
    v6[6] = 0;
    v6[4] = 0;
    v6[9] = 0;
    v6[10] = 0;
  }
  _Clear(this->table);
}

// 0x1343250
void StartEffect(TMPEffect *this, void *obj, s32 mode, s32 tp) {
    IsAlready(0, 0, 0, 0);
}

// 0x13441b0
void StopEffect(TMPEffect *this, void *obj) {
  s64 v5;
  u64 v6;
  struct TMPEffect_TMPData_array *list;
  struct TMPEffect_TMPData_array *v10;
  struct TMPEffect_TMPData_array *v12;
  u64 *v14;

  v5 = 0;
  v6 = 0;
  {
  }
  while (v6 < TABLEMAX)
  {
    list = this->list;
    if (list->m_Items[v5].type)
    {
      v10 = this->list;
      if (((v10->m_Items[v5].obj->klass->vtable._0_Equals.methodPtr)(
              v10->m_Items[v5].obj,
              obj,
              v10->m_Items[v5].obj->klass->vtable._0_Equals.method)
          & 1) != 0)
      {
        break;
      }
    }
    ++v6;
    ++v5;
  }
  else if (TABLEMAX == v6)
  {
    return;
  }
  v12 = this->list;
  v14 = (&v12->obj.klass + v5 * 56);
  v14[5] = 0;
  v14[6] = 0;
  v14[4] = 0;
  v14[9] = 0;
  v14[10] = 0;
  _Remove(
    this->table,
    v6);
}

// 0x13426c0
void Update(TMPEffect *this) {
    SetColor(0, 0, 0);
}
