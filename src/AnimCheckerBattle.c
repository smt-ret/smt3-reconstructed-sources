#include "types.h"

typedef struct AnimCheckerBattle AnimCheckerBattle;

u8 Get(s32 id);
void UpdateNormalizeTime(AnimCheckerBattle *this);

// 0xfd9460
bool AnimClipSearch(AnimCheckerBattle *this, s32 dvlno, s32 animno) {
  datUnitVisual_t_o *v6;
  struct datUnitMotion_s_array *motion;
  il2cpp_array_size_t max_length;
  struct datUnitVisual_t_array *datHumanVisual;
  u64 v13;
  u32 motion_no;

  if (!animno)
    return 1;
  if (dvlno)
  {
    v6 = Get(dvlno, 0);
    motion = v6->motion;
    max_length = motion->max_length;
    if (max_length < 1)
      return 0;
  }
  else
  {
    v6 = datHumanVisual->m_Items[0];
    motion = v6->motion;
    max_length = motion->max_length;
    if (max_length < 1)
      return 0;
  }
  v13 = 0;
  while (1)
  {
    motion_no = motion->m_Items[v13]->motion_no;
    if (motion_no && motion_no == animno)
      break;
    motion = v6->motion;
    LODWORD(max_length) = motion->max_length;
    if (++v13 >= max_length)
      return 0;
  }
  return 1;
}

// 0xfd8ba0
void Awake(AnimCheckerBattle *this) {
  PropertySheet___Clear(this->allstate);
  this->initflg = 0;
}

// 0xfd9440
f32 GetStateNormalizedTimeOffset(AnimCheckerBattle *this) {
  return this->nowStateNormalizedTimeOffset;
}

// 0xfd9700
bool IsBtlMotionFinished(AnimCheckerBattle *this) {
    return 0;
}

// 0xfd95d0
bool IsRstMotionFinished(AnimCheckerBattle *this) {
    return 0;
}

// 0xfd9770
void ResetStateNormalizedTimeOffset(AnimCheckerBattle *this) {
  this->nowStateNormalizedTimeOffset = 1.0;
}

// 0xfd9450
void SetAnimator(AnimCheckerBattle *this, void *mAnim) {
  this->mAnimator = mAnim;
}

// 0xfd8c00
void Start(AnimCheckerBattle *this) {
  ;
}

// 0xfd8c10
void Update(AnimCheckerBattle *this) {
    UpdateNormalizeTime(0);
}

// 0xfd92d0
void UpdateNormalizeTime(AnimCheckerBattle *this) {
}
