#include "types.h"

typedef struct FrameAnime FrameAnime;

// 0x113de40
void Awake(FrameAnime *this) {
  UnityEngine_GUILayer_o *Component_GUILayer;

  Component_GUILayer = GetComponent_GUILayer_(this);
  this->animator = Component_GUILayer;
  this->speed = get_speed(Component_GUILayer);
}

// 0x113df40
void LateUpdate(FrameAnime *this) {
  set_speed(this->animator, 0.0);
  this->time = 0.033333;
  this->step = 1;
}

// 0x113deb0
void OnDestroy(FrameAnime *this) {
  UnityEngine_Object_o *animator;

  animator = this->animator;
  if (op_Inequality(animator, 0, 0))
    set_speed(this->animator, this->speed);
}

// 0x113df80
void StepFrame(FrameAnime *this) {
  if (this->step)
  {
    set_speed(this->animator, this->speed);
    Update(this->animator, this->time, 0);
    set_speed(this->animator, 0.0);
    this->step = 0;
  }
}
