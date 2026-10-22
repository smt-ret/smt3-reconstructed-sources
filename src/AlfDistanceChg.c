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
  UnityEngine_Object_o *MainCamera;
  UnityEngine_GameObject_o *fldPlayerObj;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v11;
  f32 v13;
  UnityEngine_GameObject_o *v15;
  UnityEngine_Transform_o *v16;
  UnityEngine_Transform_o *v17;
  f32 v19;
  UnityEngine_Material_o *v21;
  s32 *static_fields;
  s32 v24;
  f32 v25;
  System_Collections_Generic_List_Enumerator_T__o v26;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v28;
  UnityEngine_Vector3_o v29;
  UnityEngine_Vector3_o v30;

  memset(&v26, 0, sizeof(v26));
  MainCamera = GetMainCamera(kernelObject);
  if (!op_Inequality(MainCamera, 0, 0))
  {
    v13 = 1000.0;
      goto LABEL_20;
    goto LABEL_17;
  }
  gameObject = get_gameObject(this);
  transform = get_transform(gameObject, 0);
  position = get_position(transform);
  v11 = get_transform(MainCamera, 0);
  v28 = get_position(v11);
  v13 = Distance(position, v28);
  {
LABEL_17:
  }
LABEL_20:
  if (op_Inequality(fldPlayerObj, 0, 0))
  {
    v15 = get_gameObject(this);
    v16 = get_transform(v15, 0);
    v29 = get_position(v16);
    v17 = get_transform(fldPlayerObj, 0);
    v30 = get_position(v17);
    v19 = Distance(v29, v30);
  }
  else
  {
    v19 = 1000.0;
  }
  __GetEnumerator(&v26, this->mat_list);
  while ((sub_1A11200(&v26) & 1) != 0)
  {
    v21 = sub_1A11350(&v26);
    v24 = static_fields[1];
    if (GetFloat(v21, *static_fields, 0) == 1.0)
      v25 = v19;
    else
      v25 = v13;
    SetFloat_27246832(v21, v24, v25);
  }
  nullsub_111(&v26);
}
