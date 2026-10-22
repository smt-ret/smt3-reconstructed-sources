#include "types.h"

typedef struct AnimCheckerPMV AnimCheckerPMV;

// 0xfd9800
void Awake(AnimCheckerPMV *this) {
  this->bMovie = 0;
  this->anim = GetComponent_GUILayer_(this);
}

// 0xfd9860
void FixedUpdate(AnimCheckerPMV *this) {
  UnityEngine_Object_o *anim;
  s32 Frame;
  f32 v5;
  UnityEngine_Animator_o *v6;
  s32 v7;
  UnityEngine_AnimatorStateInfo_o v8;
  UnityEngine_AnimatorStateInfo_o v9;

  memset(&v9, 0, sizeof(v9));
  if (this->bMovie)
  {
    anim = this->anim;
    if (!op_Equality(anim, 0, 0))
    {
      GetCurrentAnimatorStateInfo(&v8, this->anim, 0);
      v9 = v8;
      Frame = this->Frame;
      v5 = (1.0 / get_targetFrameRate()) * (Frame + 1);
      if (v5 >= sub_85FB60(&v9))
        v5 = sub_85FB60(&v9);
      v6 = this->anim;
      v7 = sub_85FB00(&v9);
      PlayInFixedTime_8776992(v6, v7, 0, v5);
      set_speed(this->anim, 1.0);
    }
  }
}

// 0xfd99b0
void SetFrame(AnimCheckerPMV *this, s32 frame, bool linkage) {
  UnityEngine_Object_o *anim;

  this->bMovie = linkage;
  this->Frame = frame;
  anim = this->anim;
  op_Equality(anim, 0, 0);
}
