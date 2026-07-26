#include "types.h"

typedef struct Resolution Resolution;
typedef struct Resolution__Loop_d__6 Resolution__Loop_d__6;

struct Resolution__Loop_d__6 {
    s32 __1__state;
    void *__2__current;
    f32 _real_5__2;
    s32 _count_5__3;
};

static void *loop;
static bool _auto;
static f32 level;

// 0x1891e90
void *Loop(Resolution *this) {
  u64 *v2;

  v2 = Allocate(Resolution__Loop_d__6);
  _ctor(v2, 0);
  *(v2 + 4) = 0;
  return v2;
}

// 0x1891ef0
void OnDestroy(Resolution *this) {
  UnityEngine_Coroutine_o *loop;

  if (loop)
  {
    StopCoroutine_27344864(this, loop);
    loop = 0;
  }
}

// 0x1891fd0
void SetAuto(bool act) {
  else
  {
    _auto = act;
    if (act)
      return;
  }
  level = 1.0;
}

// 0x1892080
void SetLevel(f32 lv) {
  level = lv;
}

// 0x1891d50
void Start(Resolution *this) {
  UnityEngine_Component_o *transform;
  UnityEngine_Camera_o *Component_GUILayer;
  u64 *v6;
  UnityEngine_Coroutine_o *started;

  transform = get_transform(this, 0);
  Component_GUILayer = GetComponent_GUILayer_(transform);
  set_allowDynamicResolution(Component_GUILayer, 1);
  else if (loop)
  {
    return;
  }
  v6 = Allocate(Resolution__Loop_d__6);
  _ctor(v6, 0);
  *(v6 + 4) = 0;
  started = StartCoroutine_27343696(this, v6);
  loop = started;
}
