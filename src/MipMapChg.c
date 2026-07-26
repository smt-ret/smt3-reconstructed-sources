#include "types.h"

typedef struct MipMapChg MipMapChg;
typedef struct dds3DefaultMain dds3DefaultMain;

static s32 id_AlfDistanceMode;
static s32 id_MipDistance;

void *GetMainCamera(dds3DefaultMain *this);

// 0x1294880
void Start(MipMapChg *this) {
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

// 0x1294930
void Update(MipMapChg *this) {
    GetMainCamera(0);
}
