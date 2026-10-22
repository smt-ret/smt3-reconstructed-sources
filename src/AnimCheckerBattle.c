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
  UnityEngine_AnimatorStateInfo_o v3;
  UnityEngine_AnimatorStateInfo_o v4;

  memset(&v4, 0, sizeof(v4));
  GetCurrentAnimatorStateInfo(&v3, this->mAnimator, 0);
  v4 = v3;
  return !sub_85FBA0(&v4);
}

// 0xfd95d0
bool IsRstMotionFinished(AnimCheckerBattle *this) {
  UnityEngine_GUILayer_o *Component_GUILayer;
  f32 v5;
  f32 v6;
  UnityEngine_AnimatorStateInfo_o v8;
  UnityEngine_AnimatorStateInfo_o v9;

  memset(&v9, 0, sizeof(v9));
  GetCurrentAnimatorStateInfo(&v8, this->mAnimator, 0);
  v9 = v8;
  if (!this->rstInitflg)
  {
    this->nowStateNormalizedTimeOffset = 1.0;
    this->rstInitflg = 1;
  }
  Component_GUILayer = GetComponent_GUILayer_(this->mAnimator);
  if (op_Inequality(Component_GUILayer, 0, 0))
    v5 = *(&Component_GUILayer[2].klass + 1);
  else
    v5 = 0.0;
  v6 = sub_85FB40(&v9);
  return (v6 - v5) >= (1.0 / sub_85FB80(&v9));
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
  UnityEngine_Object_o *mAnimator;
  UnityEngine_RuntimeAnimatorController_o *runtimeAnimatorController;
  UnityEngine_AnimationClip_array *animationClips;
  s32 max_length;
  UnityEngine_AnimationClip_o **m_Items;
  UnityEngine_AnimationClip_array *v8;
  s64 v9;
  UnityEngine_Object_o *v11;
  struct System_Collections_Generic_Dictionary_string__string__o *allstate;
  System_String_o *name;
  struct System_Collections_Generic_Dictionary_string__string__o *v14;
  System_String_o *v15;
  System_String_o *v16;
  System_Object_array *v17;
  s64 *v20;
  s64 *v21;
  s64 *v26;
  s64 *v27;
  s64 *v32;
  s64 *v33;
  s64 *v38;
  s64 *v39;
  Il2CppObject *v43;
  UnityEngine_AnimatorStateInfo_o v45;
  UnityEngine_AnimatorStateInfo_o v46;
  s64 v47;

  v47 = 0;
  memset(&v46, 0, sizeof(v46));
  mAnimator = this->mAnimator;
  if (op_Inequality(mAnimator, 0, 0))
  {
    if (!this->initflg)
    {
      runtimeAnimatorController = get_runtimeAnimatorController(this->mAnimator);
      animationClips = get_animationClips(runtimeAnimatorController);
      HIDWORD(v47) = 0;
      max_length = animationClips->max_length;
      if (max_length >= 1)
      {
        m_Items = animationClips->m_Items;
        v8 = animationClips;
        v9 = 0;
        do
        {
          v11 = m_Items[v9];
          allstate = this->allstate;
          name = get_name(v11);
          if (!Animator___ContainsKey(allstate, name))
          {
            v14 = this->allstate;
            v15 = get_name(v11);
            v16 = get_name(v11);
            PropertySheet___Add(v14, v15, v16);
          }
          max_length = v8->max_length;
          ++v9;
        }
        while (v9 < max_length);
        HIDWORD(v47) = v9;
      }
      this->initflg = 1;
    }
    GetCurrentAnimatorStateInfo(&v45, this->mAnimator, 0);
    v46 = v45;
    if (sub_85FB00(&v46) != this->nowFullPathHash)
    {
      v17 = NewSpecific(object, 8u);
      v17->m_Items[0] = "[";
      HIDWORD(v47) = get_frameCount();
      v20 = sub_232A70(&v47 + 1, "00000");
      v21 = v20;
      v17->m_Items[1] = v21;
      v17->m_Items[2] = "]AnimCheckerBattle#StateChange(";
      v26 = get_name(this);
      v27 = v26;
      v17->m_Items[3] = v27;
      v17->m_Items[4] = "/";
      v45.m_Name = sub_85FB00(&v46);
      v32 = sub_8D3950(s32, &v45);
      v33 = v32;
      v17->m_Items[5] = v33;
      v17->m_Items[6] = ")=";
      LODWORD(v47) = sub_85FB40(&v46);
      v38 = sub_4FDBB0(&v47);
      v39 = v38;
      v17->m_Items[7] = v39;
      v43 = Concat_5270224(v17);
      Log(v43, 0);
      UpdateNormalizeTime(this);
    }
  }
}

// 0xfd92d0
void UpdateNormalizeTime(AnimCheckerBattle *this) {
  f32 nowStateNormalizedTimeOffset;
  f32 v4;
  UnityEngine_AnimatorStateInfo_o v5;
  UnityEngine_AnimatorStateInfo_o v6;

  memset(&v6, 0, sizeof(v6));
  GetCurrentAnimatorStateInfo(&v5, this->mAnimator, 0);
  v6 = v5;
  nowStateNormalizedTimeOffset = this->nowStateNormalizedTimeOffset;
  if (nowStateNormalizedTimeOffset <= sub_85FB40(&v6))
    v4 = sub_85FB40(&v6);
  else
    v4 = 0.0;
  this->nowStateNormalizedTimeOffset = v4;
  this->nowFullPathHash = sub_85FB00(&v6);
}
