#include "types.h"

typedef struct AnimCheckerPMV AnimCheckerPMV;

// 0xfd9800
void Awake(AnimCheckerPMV *this) {
  this->bMovie = 0;
  this->anim = GetComponent_GUILayer_(this);
}

// 0xfd9860
void FixedUpdate(AnimCheckerPMV *this) {
}

// 0xfd99b0
void SetFrame(AnimCheckerPMV *this, s32 frame, bool linkage) {
  UnityEngine_Object_o *anim;

  this->bMovie = linkage;
  this->Frame = frame;
  anim = this->anim;
  op_Equality(anim, 0, 0);
}
