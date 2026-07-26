#include "types.h"

typedef struct AnimChecker AnimChecker;
typedef struct AnimChecker_ANIMSTATE AnimChecker_ANIMSTATE;
typedef struct SwitchMovie SwitchMovie;

struct AnimChecker_ANIMSTATE {
    s32 bused;
    s32 reflect;
    s32 finished;
    bool loop;
    bool smooth;
    f32 timer;
    f32 loophead;
    char *name;
    s32 started;
    s32 fullHash;
    s32 motion;
    s32 end_cnt;
    s32 isp;
};

bool IsAnimStarted(AnimChecker *this, s32 LayerIndex);
bool IsFinished2(AnimChecker *this, s32 LayerIndex);
bool IsFinishedP(AnimChecker *this, s32 LayerIndex);
void Play(SwitchMovie *this, char *filename, s32 Layer);

// 0xfd6430
void Awake(AnimChecker *this) {
}

// 0xfd8b20
void Clear(AnimChecker_ANIMSTATE *this) {
  *(&this->loophead + 2) = 0;
  *&this->timer = 0;
  *(this + 16) = 0;
  *&this->isp = 0;
  *(this + 7) = 0;
  *&this->started = 0;
  *&this->motion = 0;
}

// 0xfd8b40
void Copy(AnimChecker_ANIMSTATE *this, AnimChecker_ANIMSTATE *st) {
  _BOOL4 loop;
  _BOOL4 smooth;
  s32 finished;
  struct System_String_o *name;
  f32 timer;
  f32 loophead;
  s32 started;
  s64 v10;
  s32 isp;

  loop = st->loop;
  smooth = st->smooth;
  finished = st->finished;
  name = st->name;
  timer = st->timer;
  loophead = st->loophead;
  started = st->started;
  v10 = *&st->motion;
  isp = st->isp;
  LODWORD(this->timer) = st->bused;
  BYTE4(this->name) = loop;
  this->isp = started;
  *(&this->isp + 1) = 0;
  LODWORD(this->name) = finished;
  BYTE5(this->name) = smooth;
  *&this->motion = name;
  *(this + 7) = v10;
  *&this->started = timer;
  *&this->fullHash = loophead;
  *(this + 16) = isp;
}

// 0xfd87d0
void FixedUpdate(AnimChecker *this) {
}

// 0xfd8630
s32 GetNowMotion(AnimChecker *this) {
  struct AnimChecker_ANIMSTATE_array *state;
  Il2CppArrayBounds *bounds;

  if (!IsAnimStarted(this, 0))
    return -1;
  state = this->state;
  bounds = state->bounds;
  return state->m_Items[0].motion;
}

// 0xfd7c90
bool IsAnimStarted(AnimChecker *this, s32 LayerIndex) {
    return 0;
}

// 0xfd7700
bool IsFinished(AnimChecker *this, s32 LayerIndex) {
  return IsFinished2(this, LayerIndex);
}

// 0xfd8220
bool IsFinished2(AnimChecker *this, s32 LayerIndex) {
    IsAnimStarted(0, 0);
    IsFinishedP(0, 0);
    return 0;
}

// 0xfd8450
bool IsFinishedP(AnimChecker *this, s32 LayerIndex) {
    return 0;
}

// 0xfd7940
bool IsPlayingKuti(AnimChecker *this, s32 LayerIndex) {
  struct AnimChecker_ANIMSTATE_array *state;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;

  state = this->state;
  bounds = state->bounds;
  length = bounds[1].length;
  return !IsNullOrEmpty(state->m_Items[length * LayerIndex].name);
}

// 0xfd6e60
void Play(AnimChecker *this, char *name, s32 motion, s32 LayerIndex, f32 time, s32 before, s32 smooth, bool loop, s32 isp) {
}

// 0xfd86c0
void PlayFrameControl(AnimChecker *this, s32 motion) {
}

// 0xfd7720
void ResetFinished(AnimChecker *this, s32 LayerIndex) {
  struct AnimChecker_ANIMSTATE_array *state;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;

  state = this->state;
  if (state)
  {
    bounds = state->bounds;
    length = bounds[1].length;
    state->m_Items[length * LayerIndex].finished = 0;
  }
}

// 0xfd77a0
void ResetFlag(AnimChecker *this, s32 LayerIndex) {
  struct AnimChecker_ANIMSTATE_array *state;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  struct AnimChecker_ANIMSTATE_array *v8;
  Il2CppArrayBounds *v9;
  il2cpp_array_size_t v11;
  struct AnimChecker_ANIMSTATE_array *v13;
  Il2CppArrayBounds *v14;
  il2cpp_array_size_t v16;
  struct AnimChecker_ANIMSTATE_array *v18;
  Il2CppArrayBounds *v19;
  il2cpp_array_size_t v21;

  state = this->state;
  if (state)
  {
    bounds = state->bounds;
    length = bounds[1].length;
    state->m_Items[length * LayerIndex].finished = 0;
    v8 = this->state;
    v9 = v8->bounds;
    v11 = v9[1].length;
    v8->m_Items[v11 * LayerIndex].loop = 0;
    v13 = this->state;
    v14 = v13->bounds;
    v16 = v14[1].length;
    v13->m_Items[v16 * LayerIndex].end_cnt = 0;
    if (this->CharaType == 1)
    {
      v18 = this->state;
      v19 = v18->bounds;
      v21 = v19[1].length;
      v18->m_Items[v21 * LayerIndex].name = 0;
    }
  }
}

// 0xfd7710
void SetCharacterType(AnimChecker *this, s32 type) {
  this->CharaType = type;
}

// 0xfd8920
void SetFrame(AnimChecker *this, s32 frm) {
  UnityEngine_Object_o *anim;

  if (this->FrameCtrl)
  {
    anim = this->anim;
    if (!op_Equality(anim, 0, 0))
      this->MotFrame = frm;
  }
}

// 0xfd7930
void SetMouthMotion(AnimChecker *this, s32 motion) {
  this->MouthMotion = motion;
}

// 0xfd79d0
void StopKUTI(AnimChecker *this, s32 LayerIndex, s32 ExMot) {
    IsAnimStarted(0, 0);
}

// 0xfd6680
void Update(AnimChecker *this) {
    Play(0, 0, 0);
    IsFinished2(0, 0);
}
