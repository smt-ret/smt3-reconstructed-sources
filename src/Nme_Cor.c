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
  Nme_Cor_c *v8;
  UnityEngine_Object_o *component;
  UnityEngine_MonoBehaviour_o *v12;
  u64 *v13;

  op_Equality(obj, 0, 0);
  if (!op_Equality(component, 0, 0))
  {
      goto LABEL_20;
    goto LABEL_17;
  }
  v7 = AddComponent_object_(Filter);
  component = v7;
  if ((v8->_2.bitflags2 & 2) != 0)
  {
LABEL_17:
  }
LABEL_20:
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
  UnityEngine_Object_o *BackImageTex;
  s32 width;
  s32 height;
  f32 v10;
  f32 x;
  f32 y;
  u64 *v14;
  f32 v17;
  f32 v18;
  UnityEngine_Texture2D_o *v19;
  UnityEngine_Rect_o v21;
  s64 v22;

  if (op_Equality(BackImageTex, 0, 0))
  {
    width = get_width(0);
    height = get_height(0);
    v22 = 0;
    sub_851710(&v22, width, height);
    v10 = *(&v22 + 1);
    LODWORD(size.x) = v22;
    size.y = v10;
    x = size.x;
    y = size.y;
    v14 = Allocate(UnityEngine_Texture2D);
    _ctor_27469040(v14, x, y, 5, 0);
    BackImageTex = v14;
    v17 = size.x;
    v18 = size.y;
    v19 = BackImageTex;
    *&v21.m_XMin = 0;
    *&v21.m_Width = 0;
    sub_1A1D780(&v21.m_XMin, 0.0, 0.0, v17, v18);
    ReadPixels_27473280(v19, v21, 0, 0);
  }
  Apply_27472496(BackImageTex);
  Running = 1;
}

// 0xf004a0
void Start(Nme_Cor *this) {
  u64 *v2;
  System_Collections_IEnumerator_o *v4;

  v2 = Allocate(Nme_Cor__Capture_d__10);
  _ctor(v2, 0);
  *(v2 + 4) = 0;
  else
  {
    v4 = v2;
  }
  CorStart(v4);
}

// 0xf005c0
void Update(Nme_Cor *this) {
  if (Fadeflag)
LABEL_6:
    StopCoroutine_27345440(this, "NameCor");
}
