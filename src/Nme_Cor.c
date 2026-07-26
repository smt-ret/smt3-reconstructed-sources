#include "types.h"

typedef struct Nme_Cor Nme_Cor;
typedef struct Nme_Cor__Capture_d__10 Nme_Cor__Capture_d__10;
typedef struct Nme_Cor__Do_d__7 Nme_Cor__Do_d__7;

struct Nme_Cor__Do_d__7 {
    s32 __1__state;
    void *__2__current;
    void *src;
};

struct Nme_Cor__Capture_d__10 {
    s32 __1__state;
    void *__2__current;
};

static bool Running;
static void *BackImageTex;
static void *obj;
static Nme_Cor *component;
static sdfVector2_t size;

void CorStart(void *coroutine);

// 0xf00560
void *Capture(Nme_Cor *this) {
  u64 *v2;

  v2 = Allocate(Nme_Cor__Capture_d__10);
  _ctor(v2, 0);
  *(v2 + 4) = 0;
  return v2;
}

// 0xf001f0
void CorStart(void *coroutine) {
  UnityEngine_Object_o *obj;
  Il2CppObject *v7;
  UnityEngine_Object_o *component;
  UnityEngine_MonoBehaviour_o *v12;
  u64 *v13;

  op_Equality(obj, 0, 0);
  v7 = AddComponent_object_(Filter);
  component = v7;
  if (op_Inequality(component, 0, 0))
  {
    v12 = component;
    v13 = Allocate(Nme_Cor__Do_d__7);
    _ctor(v13, 0);
    *(v13 + 4) = 0;
    v13[4] = coroutine;
    StartCoroutine_27343696(v12, v13);
  }
}

// 0xf00400
void *Do(Nme_Cor *this, void *src) {
  u64 *v4;

  v4 = Allocate(Nme_Cor__Do_d__7);
  _ctor(v4, 0);
  *(v4 + 4) = 0;
  v4[4] = src;
  return v4;
}

// 0xf00690
void OnPostRender(Nme_Cor *this) {
}

// 0xf004a0
void Start(Nme_Cor *this) {
    CorStart(0);
}

// 0xf005c0
void Update(Nme_Cor *this) {
  if (Fadeflag)
    StopCoroutine_27345440(this, StringLiteral_5364);
}
