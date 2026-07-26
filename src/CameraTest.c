#include "types.h"

typedef struct CameraTest CameraTest;

// 0xfe1ca0
void Start(CameraTest *this) {
  struct UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *myTransform;
  UnityEngine_Vector3_o position;

  transform = get_transform(this, 0);
  this->myTransform = transform;
  position = get_position(transform);
  myTransform = this->myTransform;
  this->camera_pos = position;
  this->camera_rot = get_localEulerAngles(myTransform);
}

// 0xfe1d00
void Update(CameraTest *this) {
  ;
}
