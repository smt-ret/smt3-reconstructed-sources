#include "types.h"

typedef struct BillBoardRot BillBoardRot;
typedef struct dds3DefaultMain dds3DefaultMain;

void *GetMainCamera(dds3DefaultMain *this);

// 0xfdf090
void LateUpdate(BillBoardRot *this) {
  UnityEngine_Object_o *kernelObject;
  UnityEngine_GameObject_o *MainCamera;
  Il2CppObject *Component_object;
  UnityEngine_Object_o *v11;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v13;
  UnityEngine_Transform_o *v16;
  UnityEngine_Transform_o *v17;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v19;
  UnityEngine_Vector3_o v20;
  UnityEngine_Vector3_o up;
  UnityEngine_Quaternion_o v22;
  UnityEngine_Quaternion_o rotation;
  UnityEngine_Quaternion_o v24;
  UnityEngine_Quaternion_o v25;

  if (!op_Equality(kernelObject, 0, 0))
  {
    MainCamera = GetMainCamera(kernelObject);
    if (!op_Equality(MainCamera, 0, 0))
    {
      Component_object = GetComponent_object_(MainCamera);
      this->m_TargetCamera = Component_object;
      v11 = Component_object;
      if (!op_Equality(v11, 0, 0))
      {
        transform = get_transform(MainCamera, 0);
        position = get_position(transform);
        v13 = get_transform(this, 0);
        v19 = get_position(v13);
        v20 = op_Subtraction(position, v19);
        up = get_up();
        {
        }
        v22 = LookRotation(v20, up);
        v16 = get_transform(this, 0);
        v17 = get_transform(this, 0);
        rotation = get_rotation(v17);
        v25.x = 0.0;
        v25.y = v22.y;
        v25.w = v22.w;
        v25.z = 0.0;
        v24 = Lerp(rotation, v25, this->spped, 0);
        set_rotation(v16, v24);
      }
    }
  }
}
