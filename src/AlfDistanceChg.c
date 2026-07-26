#include "types.h"

typedef struct AlfDistanceChg AlfDistanceChg;
typedef struct dds3DefaultMain dds3DefaultMain;

static s32 id_AlfDistanceMode;
static s32 id_AlfDistanceCalc;

void *GetMainCamera(dds3DefaultMain *this);

// 0xfd5ca0
void Start(AlfDistanceChg *this) {
  u64 *v3;
  UnityEngine_GameObject_o *gameObject;
  s64 v5;

  v3 = Allocate(System_Collections_Generic_List_Material_);
  __ctor(v3);
  this->mat_list = v3;
  gameObject = get_gameObject(this);
  (this->klass->vtable._16_SetMatInit.methodPtr)(this, gameObject, this->klass->vtable._16_SetMatInit.method);
  v5 = (this->klass->vtable._20_GetRoot.methodPtr)(this, this->klass->vtable._20_GetRoot.method);
  (*(*v5 + 648LL))(v5, this, *(*v5 + 656LL));
}

// 0xfd5d50
void Update(AlfDistanceChg *this) {
    GetMainCamera(0);
}
