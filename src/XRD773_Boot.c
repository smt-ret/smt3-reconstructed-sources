#include "types.h"

typedef struct XRD773_Boot XRD773_Boot;
typedef struct XRD773_Boot__Coroutine_d__1 XRD773_Boot__Coroutine_d__1;

struct XRD773_Boot__Coroutine_d__1 {
    s32 __1__state;
    void *__2__current;
};

// 0x134c6b0
void *Coroutine(XRD773_Boot *this) {
  u64 *v2;

  v2 = Allocate(XRD773_Boot__Coroutine_d__1);
  _ctor(v2, 0);
  *(v2 + 4) = 0;
  return v2;
}

// 0x134c640
void Start(XRD773_Boot *this) {
  u64 *v3;

  v3 = Allocate(XRD773_Boot__Coroutine_d__1);
  _ctor(v3, 0);
  *(v3 + 4) = 0;
  StartCoroutine_27343696(this, v3);
}
