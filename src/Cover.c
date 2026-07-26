#include "types.h"

typedef struct COVER_Blinder COVER_Blinder;
typedef struct COVER_LoadMark COVER_LoadMark;
typedef struct Cover Cover;
typedef struct Cover__Loading_d__3 Cover__Loading_d__3;

struct Cover__Loading_d__3 {
    s32 __1__state;
    void *__2__current;
    char *scene;
    Cover *__4__this;
};

static Cover *__scene;
static COVER_Blinder *__blinder;
static COVER_LoadMark *__load_mark;
static bool open;
static void *op;

// 0xfe3ee0
void Awake(Cover *this) {
  UnityEngine_Object_o *gameObject;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *v8;
  UnityEngine_Transform_o *v9;
  UnityEngine_Component_o *v10;

  gameObject = get_gameObject(this);
  DontDestroyOnLoad(gameObject);
  __scene = this;
  transform = get_transform(this, 0);
  v8 = Find(transform, StringLiteral_4660, 0);
  __blinder = GetComponent_GUILayer_(v8);
  v9 = get_transform(this, 0);
  v10 = Find(v9, StringLiteral_4661, 0);
  __load_mark = GetComponent_GUILayer_(v10);
}

// 0xfe4000
void Load(Cover *this, char *scene) {
  u64 *v5;

  this->is_load = 1;
  v5 = Allocate(Cover__Loading_d__3);
  _ctor(v5, 0);
  *(v5 + 4) = 0;
  v5[4] = scene;
  v5[5] = this;
  StartCoroutine_27343696(this, v5);
}

// 0xfe4080
void *Loading(Cover *this, char *scene) {
  u64 *v5;

  v5 = Allocate(Cover__Loading_d__3);
  _ctor(v5, 0);
  *(v5 + 4) = 0;
  v5[4] = scene;
  v5[5] = this;
  return v5;
}

// 0xfe4130
void WaitOpen(Cover *this, bool wait) {
  Cover_c *v4;
  struct Cover_StaticFields *static_fields;
  UnityEngine_AsyncOperation_o *op;

  open = !wait;
  static_fields = v4->static_fields;
  op = static_fields->op;
  if (op)
  {
    set_allowSceneActivation(op, static_fields->open);
  }
}
