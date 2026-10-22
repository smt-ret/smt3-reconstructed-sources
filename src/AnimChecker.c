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
  struct AnimChecker_ANIMSTATE_array *v3;
  u64 v4;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  Il2CppClass **v9;
  struct AnimChecker_ANIMSTATE_array *state;
  Il2CppArrayBounds *v11;
  il2cpp_array_size_t v13;
  char *v15;
  struct AnimChecker_ANIMSTATE_array *v16;
  Il2CppArrayBounds *v17;
  il2cpp_array_size_t v19;
  Il2CppClass **v21;
  struct AnimChecker_ANIMSTATE_array *v22;
  Il2CppArrayBounds *v23;
  il2cpp_array_size_t v25;
  char *v27;
  s64 v28[2];

  *&this->CharaType = 0xFFFFFFFF00000002LL;
  this->MouthMotion = 0;
  this->anim = GetComponent_GUILayer_(this);
  v28[0] = 12;
  v28[1] = 2;
  v3 = sub_8DB0C0(AnimChecker_ANIMSTATE_, v28, 0);
  v4 = 0;
  this->state = v3;
  bounds = v3->bounds;
  if (!LODWORD(bounds->length))
  {
LABEL_6:
  }
  while (1)
  {
    length = bounds[1].length;
    v9 = &v3->obj.klass + 7 * length * v4;
    v9[4] = 0;
    v9[9] = 0;
    v9[10] = 0;
    v9[7] = 0;
    v9[8] = 0;
    v9[5] = 0;
    v9[6] = 0;
    state = this->state;
    v11 = state->bounds;
    v13 = v11[1].length;
    v15 = state + 56 * v13 * v4;
    *(v15 + 38) = 0;
    *(v15 + 4) = 0;
    *(v15 + 20) = 0;
    *(v15 + 8) = 0;
    *(v15 + 9) = 0;
    *(v15 + 6) = 0;
    *(v15 + 7) = 0;
    v16 = this->state;
    v17 = v16->bounds;
    v19 = v17[1].length;
    v21 = &v16->obj.klass + 7 * v19 * v4;
    v21[11] = 0;
    v21[16] = 0;
    v21[17] = 0;
    v21[14] = 0;
    v21[15] = 0;
    v21[12] = 0;
    v21[13] = 0;
    v22 = this->state;
    v23 = v22->bounds;
    v25 = v23[1].length;
    v27 = v22 + 56 * v25 * v4;
    *(v27 + 94) = 0;
    *(v27 + 11) = 0;
    *(v27 + 34) = 0;
    *(v27 + 15) = 0;
    *(v27 + 16) = 0;
    *(v27 + 13) = 0;
    *(v27 + 14) = 0;
    if (v4 == 11)
      break;
    v3 = this->state;
    ++v4;
    bounds = v3->bounds;
    if (v4 >= LODWORD(bounds->length))
      goto LABEL_6;
  }
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
  UnityEngine_Object_o *anim;
  s32 MotFrame;
  f32 v5;
  UnityEngine_Animator_o *v6;
  s32 v7;
  UnityEngine_AnimatorStateInfo_o v8;
  UnityEngine_AnimatorStateInfo_o v9;

  memset(&v9, 0, sizeof(v9));
  if (this->FrameCtrl)
  {
    anim = this->anim;
    if (!op_Equality(anim, 0, 0))
    {
      GetCurrentAnimatorStateInfo(&v8, this->anim, 0);
      v9 = v8;
      MotFrame = this->MotFrame;
      v5 = (1.0 / get_targetFrameRate()) * MotFrame;
      if (v5 >= sub_85FB60(&v9))
        v5 = sub_85FB60(&v9);
      v6 = this->anim;
      v7 = sub_85FB00(&v9);
      PlayInFixedTime_8776992(v6, v7, 0, v5);
      set_speed(this->anim, 1.0);
    }
  }
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
  struct AnimChecker_ANIMSTATE_array *state;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  s64 v9;
  Il2CppArrayBounds *v11;
  struct AnimChecker_ANIMSTATE_array *v14;
  Il2CppArrayBounds *v15;
  il2cpp_array_size_t v17;
  System_String_o *LayerName;
  struct AnimChecker_ANIMSTATE_array *v20;
  Il2CppArrayBounds *v21;
  il2cpp_array_size_t v23;
  System_String_o *v25;
  s32 v26;
  struct AnimChecker_ANIMSTATE_array *v27;
  Il2CppArrayBounds *v28;
  il2cpp_array_size_t v30;
  System_String_o *v32;
  struct AnimChecker_ANIMSTATE_array *v33;
  Il2CppArrayBounds *v34;
  System_String_o *v35;
  il2cpp_array_size_t v37;
  u64 *v39;
  System_String_o *v40;
  System_String_o *v41;
  s32 v42;
  struct AnimChecker_ANIMSTATE_array *v43;
  Il2CppArrayBounds *v44;
  il2cpp_array_size_t v46;
  s32 v48;
  struct AnimChecker_ANIMSTATE_array *v49;
  Il2CppArrayBounds *v50;
  il2cpp_array_size_t v52;
  struct AnimChecker_ANIMSTATE_array *v54;
  Il2CppArrayBounds *v55;
  il2cpp_array_size_t v57;
  UnityEngine_AnimatorClipInfo_array *CurrentAnimatorClipInfo;
  il2cpp_array_size_t max_length;
  UnityEngine_AnimationClip_o *v63;
  struct AnimChecker_ANIMSTATE_array *v64;
  Il2CppArrayBounds *v65;
  il2cpp_array_size_t v67;
  struct AnimChecker_ANIMSTATE_array *v69;
  Il2CppArrayBounds *v70;
  il2cpp_array_size_t v72;
  UnityEngine_AnimatorStateInfo_o v74;
  UnityEngine_AnimatorStateInfo_o v75;

  memset(&v75, 0, sizeof(v75));
  state = this->state;
  if (!state)
    return 0;
  bounds = state->bounds;
  length = bounds[1].length;
  v9 = LayerIndex;
  if (state->m_Items[length * LayerIndex].started == 1
    || get_layerCount(this->anim) <= LayerIndex)
  {
    return 1;
  }
  GetCurrentAnimatorStateInfo(&v74, this->anim, LayerIndex);
  v75 = v74;
  get_runtimeAnimatorController(this->anim);
  sub_85FB40(&v75);
  v11 = this->state->bounds;
  v14 = this->state;
  v15 = v14->bounds;
  v17 = v15[1].length;
  if (!v14->m_Items[v17 * LayerIndex].bused)
    return 0;
  LayerName = GetLayerName(this->anim, LayerIndex);
  v20 = this->state;
  v21 = v20->bounds;
  v23 = v21[1].length;
  v25 = Concat_5221536(LayerName, ".", v20->m_Items[v23 * LayerIndex].name);
  StringToHash(v25);
  v26 = sub_85FB00(&v75);
  v27 = this->state;
  v28 = v27->bounds;
  v30 = v28[1].length;
  if (v26 == v27->m_Items[v30 * LayerIndex].fullHash)
    goto LABEL_39;
  if (this->CharaType != 2)
    return 0;
  v32 = GetLayerName(this->anim, LayerIndex);
  v33 = this->state;
  v34 = v33->bounds;
  v35 = v32;
  v37 = v34[1].length;
  v74.m_Name = v33->m_Items[v37 * LayerIndex].motion;
  v39 = sub_8D3950(s32, &v74);
  v40 = Format("b{0:x2}", v39, 0);
  v41 = Concat_5221536(v35, ".", v40);
  v42 = StringToHash(v41);
  if (sub_85FB00(&v75) != v42)
    return 0;
  v43 = this->state;
  v44 = v43->bounds;
  v46 = v44[1].length;
  v43->m_Items[v46 * LayerIndex].fullHash = v42;
LABEL_39:
  v48 = sub_85FB00(&v75);
  v49 = this->state;
  v50 = v49->bounds;
  v52 = v50[1].length;
  if (v48 != v49->m_Items[v52 * LayerIndex].fullHash)
    return 0;
  v54 = this->state;
  v55 = v54->bounds;
  v57 = v55[1].length;
  if (v54->m_Items[v57 * LayerIndex].started == 1)
    return 1;
  CurrentAnimatorClipInfo = GetCurrentAnimatorClipInfo(this->anim, LayerIndex);
  max_length = CurrentAnimatorClipInfo->max_length;
  if (!max_length)
    return 0;
  if (CurrentAnimatorClipInfo)
  {
    v63 = sub_85F130(CurrentAnimatorClipInfo->m_Items);
    set_wrapMode(v63, 1);
  }
  v64 = this->state;
  v65 = v64->bounds;
  v67 = v65[1].length;
  v64->m_Items[v67 * LayerIndex].timer = 0.0;
  v69 = this->state;
  v70 = v69->bounds;
  v72 = v70[1].length;
  v69->m_Items[v72 * v9].started = 1;
  return 1;
}

// 0xfd7700
bool IsFinished(AnimChecker *this, s32 LayerIndex) {
  return IsFinished2(this, LayerIndex);
}

// 0xfd8220
bool IsFinished2(AnimChecker *this, s32 LayerIndex) {
  bool v6;
  struct AnimChecker_ANIMSTATE_array *state;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  s64 v11;
  struct AnimChecker_ANIMSTATE_array *v14;
  Il2CppArrayBounds *v15;
  il2cpp_array_size_t v17;
  struct AnimChecker_ANIMSTATE_array *v19;
  Il2CppArrayBounds *v20;
  il2cpp_array_size_t v22;
  struct AnimChecker_ANIMSTATE_array *v24;
  Il2CppArrayBounds *v25;
  il2cpp_array_size_t v27;
  UnityEngine_AnimatorStateInfo_o v29;
  UnityEngine_AnimatorStateInfo_o v30;

  memset(&v30, 0, sizeof(v30));
  if (!this->state || !IsAnimStarted(this, LayerIndex))
    return 0;
  if (this->CharaType == 1)
    return IsFinishedP(this, LayerIndex);
  state = this->state;
  bounds = state->bounds;
  length = bounds[1].length;
  v11 = LayerIndex;
  if (!state->m_Items[length * LayerIndex].reflect)
    return 0;
  GetCurrentAnimatorStateInfo(&v29, this->anim, LayerIndex);
  v30 = v29;
  if (sub_85FB40(&v30) < 1.0)
    return 0;
  v14 = this->state;
  v15 = v14->bounds;
  v17 = v15[1].length;
  v14->m_Items[v17 * LayerIndex].loophead = sub_85FB40(&v30) + -1.0;
  v19 = this->state;
  v20 = v19->bounds;
  v22 = v20[1].length;
  ++v19->m_Items[v22 * LayerIndex].end_cnt;
  v24 = this->state;
  v25 = v24->bounds;
  v27 = v25[1].length;
  v6 = 1;
  v24->m_Items[v27 * v11].finished = 1;
  return v6;
}

// 0xfd8450
bool IsFinishedP(AnimChecker *this, s32 LayerIndex) {
  s32 HashCode;
  struct AnimChecker_ANIMSTATE_array *state;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  s64 v11;
  struct AnimChecker_ANIMSTATE_array *v13;
  Il2CppArrayBounds *v14;
  il2cpp_array_size_t v16;
  struct AnimChecker_ANIMSTATE_array *v18;
  Il2CppArrayBounds *v19;
  il2cpp_array_size_t v21;
  UnityEngine_AnimatorStateInfo_o v23;
  UnityEngine_AnimatorStateInfo_o v24;

  memset(&v24, 0, sizeof(v24));
  GetCurrentAnimatorStateInfo(&v23, this->anim, LayerIndex);
  v24 = v23;
  HashCode = this->HashCode;
  if (HashCode != sub_85FB00(&v24))
  {
    if (sub_85FB40(&v24) >= 1.0)
      return 0;
    this->HashCode = sub_85FB00(&v24);
  }
  if (sub_85FB40(&v24) < 1.0)
    return 0;
  state = this->state;
  bounds = state->bounds;
  length = bounds[1].length;
  v11 = LayerIndex;
  state->m_Items[length * LayerIndex].loophead = sub_85FB40(&v24) + -1.0;
  v13 = this->state;
  v14 = v13->bounds;
  v16 = v14[1].length;
  ++v13->m_Items[v16 * LayerIndex].end_cnt;
  v18 = this->state;
  v19 = v18->bounds;
  v21 = v19[1].length;
  v18->m_Items[v21 * v11].finished = 1;
  return 1;
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
  struct AnimChecker_ANIMSTATE_array *state;
  UnityEngine_Object_o *anim;
  s32 CharaType;
  struct AnimChecker_ANIMSTATE_array *v22;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  s64 v26;
  struct AnimChecker_ANIMSTATE_array *v28;
  Il2CppArrayBounds *v29;
  il2cpp_array_size_t v31;
  s32 v33;
  char v34;
  struct AnimChecker_ANIMSTATE_array *v35;
  Il2CppArrayBounds *v36;
  il2cpp_array_size_t v38;
  struct AnimChecker_ANIMSTATE_array *v40;
  Il2CppArrayBounds *v41;
  il2cpp_array_size_t v43;
  struct AnimChecker_ANIMSTATE_array *v45;
  Il2CppArrayBounds *v46;
  il2cpp_array_size_t v48;
  struct AnimChecker_ANIMSTATE_array *v50;
  Il2CppArrayBounds *v51;
  il2cpp_array_size_t v53;
  struct AnimChecker_ANIMSTATE_array *v55;
  Il2CppArrayBounds *v56;
  il2cpp_array_size_t v58;
  struct AnimChecker_ANIMSTATE_array *v60;
  Il2CppArrayBounds *v61;
  il2cpp_array_size_t v63;
  char v64;
  struct AnimChecker_ANIMSTATE_array *v66;
  Il2CppArrayBounds *v67;
  s32 v68;
  il2cpp_array_size_t v70;
  s32 v71;
  bool v73;
  struct AnimChecker_ANIMSTATE_array *v74;
  Il2CppArrayBounds *v75;
  il2cpp_array_size_t v77;
  struct AnimChecker_ANIMSTATE_array *v79;
  Il2CppArrayBounds *v80;
  il2cpp_array_size_t v82;
  struct AnimChecker_ANIMSTATE_array *v84;
  Il2CppArrayBounds *v85;
  il2cpp_array_size_t v87;
  struct AnimChecker_ANIMSTATE_array *v89;
  Il2CppArrayBounds *v90;
  il2cpp_array_size_t v92;
  struct AnimChecker_ANIMSTATE_array *v94;
  Il2CppArrayBounds *v95;
  il2cpp_array_size_t v97;
  struct AnimChecker_ANIMSTATE_array *v99;
  Il2CppArrayBounds *v100;
  il2cpp_array_size_t v102;
  System_String_o *LayerName;
  struct AnimChecker_ANIMSTATE_array *v105;
  Il2CppArrayBounds *v106;
  il2cpp_array_size_t v108;
  System_String_o *v110;
  s32 v111;
  struct AnimChecker_ANIMSTATE_array *v112;
  Il2CppArrayBounds *v113;
  il2cpp_array_size_t v115;
  s32 targetFrameRate;
  UnityEngine_Animator_o *v118;
  struct AnimChecker_ANIMSTATE_array *v119;
  Il2CppArrayBounds *v120;
  il2cpp_array_size_t v122;
  System_String_o *stateName;
  UnityEngine_AnimatorStateInfo_o v125;
  UnityEngine_AnimatorStateInfo_o v126;
  s32 v127;
  s32 v128;

  memset(&v126, 0, sizeof(v126));
  state = this->state;
  this->FrameCtrl = 0;
  *&this->MotFrame = 0;
  if (state)
  {
    anim = this->anim;
    if (!op_Equality(anim, 0, 0)
      && get_layerCount(this->anim) > LayerIndex)
    {
      CharaType = this->CharaType;
      if (CharaType == 1)
      {
        SetInteger(this->anim, "anim", motion);
        CharaType = this->CharaType;
      }
      v127 = smooth;
      if (CharaType == 2)
      {
        v22 = this->state;
        bounds = v22->bounds;
        length = bounds[1].length;
        v26 = LayerIndex;
        if (v22->m_Items[length * LayerIndex].motion != motion)
          SetInteger(this->anim, "anim", motion);
      }
      else
      {
        v26 = LayerIndex;
      }
      v28 = this->state;
      v29 = v28->bounds;
      v31 = v29[1].length;
      stateName = v28->m_Items[v31 * v26].name;
      v128 = isp;
      if (LayerIndex)
      {
        v33 = before;
        v34 = 0;
LABEL_49:
        v55 = this->state;
        v56 = v55->bounds;
        v58 = v56[1].length;
        v55->m_Items[v58 * v26].name = name;
        v60 = this->state;
        v61 = v60->bounds;
        v63 = v61[1].length;
        v64 = v34;
        v60->m_Items[v63 * v26].motion = motion;
        v66 = this->state;
        v67 = v66->bounds;
        v68 = v33;
        v70 = v67[1].length;
        v71 = v128;
        v73 = v128 == 3;
        if (v128 <= 1)
          v73 = loop;
        v66->m_Items[v70 * v26].loop = v73;
        if ((v64 & 1) == 0)
        {
          v74 = this->state;
          v75 = v74->bounds;
          v77 = v75[1].length;
          v74->m_Items[v77 * v26].started = 0;
        }
        v79 = this->state;
        v80 = v79->bounds;
        v82 = v80[1].length;
        v79->m_Items[v82 * v26].bused = 1;
        v84 = this->state;
        v85 = v84->bounds;
        v87 = v85[1].length;
        v84->m_Items[v87 * v26].end_cnt = 0;
        v89 = this->state;
        v90 = v89->bounds;
        v92 = v90[1].length;
        v89->m_Items[v92 * v26].finished = 0;
        v94 = this->state;
        v95 = v94->bounds;
        v97 = v95[1].length;
        v94->m_Items[v97 * v26].reflect = 0;
        v99 = this->state;
        v100 = v99->bounds;
        v102 = v100[1].length;
        v99->m_Items[v102 * v26].isp = v71;
        GetCurrentAnimatorStateInfo(&v125, this->anim, LayerIndex);
        v126 = v125;
        LayerName = GetLayerName(this->anim, LayerIndex);
        v105 = this->state;
        v106 = v105->bounds;
        v108 = v106[1].length;
        v110 = Concat_5221536(LayerName, ".", v105->m_Items[v108 * v26].name);
        v111 = StringToHash(v110);
        v112 = this->state;
        v113 = v112->bounds;
        v115 = v113[1].length;
        v112->m_Items[v115 * v26].fullHash = v111;
        sub_85FB40(&v126);
        sub_85FB40(&v126);
        sub_85FB60(&v126);
        sub_85FB60(&v126);
        targetFrameRate = get_targetFrameRate();
        if ((v64 & 1) != 0)
        {
          if (v71 == 3 || (v71 & 1) == 0)
            Play_8777152(this->anim, stateName, LayerIndex, time);
        }
        else
        {
          v119 = this->state;
          v118 = this->anim;
          v120 = v119->bounds;
          v122 = v120[1].length;
          CrossFadeInFixedTime(
            v118,
            v119->m_Items[v122 * v26].name,
            ((1.0 / targetFrameRate) * v68) + ((1.0 / targetFrameRate) * v127),
            LayerIndex,
            0);
        }
        return;
      }
      v35 = this->state;
      v36 = v35->bounds;
      v38 = v36[1].length;
      if (IsNullOrEmpty(v35->m_Items[v38 * v26].name))
      {
        v33 = before;
        v34 = 0;
        if (v127 | v33)
          goto LABEL_49;
      }
      else
      {
        v40 = this->state;
        v41 = v40->bounds;
        v43 = v41[1].length;
        if (Equals_5234480(v40->m_Items[v43 * v26].name, name))
        {
          v33 = before;
          v34 = 1;
          if (v127 | v33)
            goto LABEL_49;
        }
        else
        {
          v45 = this->state;
          v46 = v45->bounds;
          v48 = v46[1].length;
          v33 = before;
          v34 = 0;
          v45->m_Items[v48 * v26].smooth = 1;
          if (v127 | v33)
            goto LABEL_49;
        }
      }
      v50 = this->state;
      v51 = v50->bounds;
      v53 = v51[1].length;
      v50->m_Items[v53 * v26].smooth = 0;
      goto LABEL_49;
    }
  }
}

// 0xfd86c0
void PlayFrameControl(AnimChecker *this, s32 motion) {
  UnityEngine_Object_o *anim;
  s32 MotFrame;
  s32 targetFrameRate;
  UnityEngine_Animator_o *v8;
  f32 v9;
  u64 *v10;
  System_String_o *v11;
  s32 v12;

  this->FrameCtrl = 1;
  this->MotFrame = 0;
  this->MotID = motion;
  anim = this->anim;
  if (op_Inequality(anim, 0, 0))
  {
    MotFrame = this->MotFrame;
    targetFrameRate = get_targetFrameRate();
    v8 = this->anim;
    v12 = motion;
    v9 = (1.0 / targetFrameRate) * (MotFrame + 1);
    v10 = sub_8D3950(s32, &v12);
    v11 = Format("{0:D2}", v10, 0);
    PlayInFixedTime(v8, v11, 0, v9);
  }
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
  UnityEngine_Object_o *anim;
  struct AnimChecker_ANIMSTATE_array *state;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  s64 v13;
  struct AnimChecker_ANIMSTATE_array *v15;
  Il2CppArrayBounds *v16;
  il2cpp_array_size_t v18;
  u64 *v20;
  u64 *v21;
  System_String_o *v22;
  UnityEngine_Animator_o *v23;
  struct AnimChecker_ANIMSTATE_array *v24;
  Il2CppArrayBounds *v25;
  il2cpp_array_size_t v27;
  struct AnimChecker_ANIMSTATE_array *v29;
  Il2CppArrayBounds *v30;
  il2cpp_array_size_t v32;
  s32 MouthMotion;
  UnityEngine_AnimatorStateInfo_o v35;

  if (this->state)
  {
    anim = this->anim;
    if (!op_Equality(anim, 0, 0)
      && IsAnimStarted(this, LayerIndex)
      && get_layerCount(this->anim) > LayerIndex)
    {
      GetCurrentAnimatorStateInfo(&v35, this->anim, LayerIndex);
      get_runtimeAnimatorController(this->anim);
      if (ExMot)
      {
        state = this->state;
        bounds = state->bounds;
        length = bounds[1].length;
        v13 = LayerIndex;
        if (state->m_Items[length * LayerIndex].motion == ExMot)
          goto LABEL_31;
      }
      else
      {
        v13 = LayerIndex;
      }
      v15 = this->state;
      v16 = v15->bounds;
      v18 = v16[1].length;
      if (v15->m_Items[v18 * v13].bused)
      {
        if (this->MouthMotion)
        {
          v35.m_Name = LayerIndex;
          v20 = sub_8D3950(s32, &v35);
          MouthMotion = this->MouthMotion;
          v21 = sub_8D3950(s32, &MouthMotion);
          v22 = Format_5268592("{0:D2}_{1:D2}", v20, v21);
          v23 = this->anim;
        }
        else
        {
          v23 = this->anim;
          v22 = "default";
        }
        Play_8777152(v23, v22, LayerIndex, 0.0);
        v24 = this->state;
        v25 = v24->bounds;
        v27 = v25[1].length;
        v24->m_Items[v27 * v13].name = 0;
LABEL_31:
        v29 = this->state;
        v30 = v29->bounds;
        v32 = v30[1].length;
        v29->m_Items[v32 * v13].bused = 0;
      }
    }
  }
}

// 0xfd6680
void Update(AnimChecker *this) {
  UnityEngine_Object_o *anim;
  UnityEngine_GameObject_o *gameObject;
  s32 layerCount;
  s32 parameterCount;
  UnityEngine_AnimatorControllerParameter_array *parameters;
  UnityEngine_AnimatorControllerParameter_array *v8;
  u64 v9;
  signed s64 v10;
  UnityEngine_Animator_o *v11;
  System_String_o *name;
  s32 Integer;
  struct AnimChecker_ANIMSTATE_array *state;
  Il2CppArrayBounds *bounds;
  s32 v17;
  struct AnimChecker_ANIMSTATE_array *v18;
  Il2CppArrayBounds *v19;
  struct AnimChecker_ANIMSTATE_array *v22;
  Il2CppArrayBounds *v23;
  f32 v28;
  f32 v29;
  struct AnimChecker_ANIMSTATE_array *v30;
  Il2CppArrayBounds *v31;
  f32 v32;
  il2cpp_array_size_t length;
  f32 timer;
  f32 v37;
  struct AnimChecker_ANIMSTATE_array *v38;
  Il2CppArrayBounds *v39;
  f32 v40;
  il2cpp_array_size_t v41;
  struct AnimChecker_ANIMSTATE_array *v44;
  Il2CppArrayBounds *v45;
  il2cpp_array_size_t v46;
  struct AnimChecker_ANIMSTATE_array *v49;
  Il2CppArrayBounds *v50;
  il2cpp_array_size_t v51;
  struct AnimChecker_ANIMSTATE_array *v54;
  Il2CppArrayBounds *v55;
  il2cpp_array_size_t v57;
  struct AnimChecker_ANIMSTATE_array *v59;
  Il2CppArrayBounds *v60;
  il2cpp_array_size_t v62;
  bool v64;
  struct AnimChecker_ANIMSTATE_array *v66;
  Il2CppArrayBounds *v67;
  il2cpp_array_size_t v68;
  char *v69;
  f32 v70;
  s32 v71;
  struct AnimChecker_ANIMSTATE_array *v72;
  Il2CppArrayBounds *v73;
  il2cpp_array_size_t v75;
  struct AnimChecker_ANIMSTATE_array *v79;
  Il2CppArrayBounds *v80;
  il2cpp_array_size_t v82;
  struct AnimChecker_ANIMSTATE_array *v84;
  System_String_o *v85;
  Il2CppArrayBounds *v86;
  il2cpp_array_size_t v88;
  struct AnimChecker_ANIMSTATE_array *v90;
  s32 motion;
  Il2CppArrayBounds *v92;
  il2cpp_array_size_t v94;
  f32 *v96;
  struct AnimChecker_ANIMSTATE_array *v97;
  f32 v98;
  Il2CppArrayBounds *v99;
  il2cpp_array_size_t v101;
  UnityEngine_AnimatorStateInfo_o v104;
  UnityEngine_AnimatorStateInfo_o v105;

  memset(&v105, 0, sizeof(v105));
  if (!this->FrameCtrl)
  {
    anim = this->anim;
    if (!op_Equality(anim, 0, 0))
    {
      gameObject = get_gameObject(this->anim);
      if (get_activeSelf(gameObject))
      {
        if (GetCurrentAnimatorClipInfo(this->anim, 0)->max_length)
        {
          layerCount = get_layerCount(this->anim);
          parameterCount = get_parameterCount(this->anim);
          parameters = get_parameters(this->anim);
          if (layerCount >= 1)
          {
            v8 = parameters;
            v9 = 0;
            v10 = layerCount;
            do
            {
              if (parameterCount && !v9 && this->CharaType)
              {
                v11 = this->anim;
                name = get_name(v8->m_Items[0]);
                Integer = GetInteger(v11, name);
                state = this->state;
                bounds = state->bounds;
                v17 = Integer;
                if (IsNullOrEmpty(state->m_Items[0].name))
                {
                  v22 = this->state;
                  v23 = v22->bounds;
                  v22->m_Items[0].started = 1;
                  v18 = this->state;
                  v19 = v18->bounds;
                  if (!LODWORD(v19->length))
                  {
LABEL_31:
                  }
                }
                else
                {
                  v18 = this->state;
                  v19 = v18->bounds;
                  if (!LODWORD(v19->length))
                    goto LABEL_31;
                }
                if (v17 != v18->m_Items[0].motion)
                  return;
              }
              GetCurrentAnimatorStateInfo(&v104, this->anim, v9);
              v105 = v104;
              v28 = sub_85FB40(&v105);
              v29 = fmodf(v28, 1.0);
              v30 = this->state;
              v31 = v30->bounds;
              v32 = v29;
              length = v31[1].length;
              timer = v30->m_Items[length * v9].timer;
              v37 = fmodf(timer, 1.0);
              v38 = this->state;
              v39 = v38->bounds;
              v40 = v37;
              v41 = v39[1].length;
              if (v38->m_Items[v41 * v9].bused)
              {
                v44 = this->state;
                v45 = v44->bounds;
                v46 = v45[1].length;
                if (!v44->m_Items[v46 * v9].reflect)
                {
                  v49 = this->state;
                  v50 = v49->bounds;
                  v51 = v50[1].length;
                  if (!v49->m_Items[v51 * v9].loop && sub_85FB40(&v105) >= 1.0)
                    goto LABEL_97;
                  v54 = this->state;
                  v55 = v54->bounds;
                  v57 = v55[1].length;
                  v54->m_Items[v57 * v9].reflect = 1;
                }
                v59 = this->state;
                v60 = v59->bounds;
                v62 = v60[1].length;
                v59->m_Items[v62 * v9].timer = sub_85FB40(&v105);
                v64 = sub_85FBA0(&v105);
                v66 = this->state;
                v67 = v66->bounds;
                v68 = v67[1].length;
                v69 = v66 + 56 * v68 * v9;
                if (v64)
                {
                  if ((v69[80] & 1) != 0)
                    goto LABEL_97;
                  v70 = v28 - v32;
                  v71 = sub_85FB00(&v105);
                  v72 = this->state;
                  v73 = v72->bounds;
                  v75 = v73[1].length;
                  if (v70 <= (timer - v40) || v71 != v72->m_Items[v75 * v9].fullHash)
                    goto LABEL_97;
LABEL_80:
                  v79 = this->state;
                  v80 = v79->bounds;
                  v82 = v80[1].length;
                  v84 = this->state;
                  v85 = v79->m_Items[v82 * v9].name;
                  v86 = v84->bounds;
                  v88 = v86[1].length;
                  v90 = this->state;
                  motion = v84->m_Items[v88 * v9].motion;
                  v92 = v90->bounds;
                  v94 = v92[1].length;
                  v96 = (v90 + 56 * v94 * v9);
                  v97 = this->state;
                  v98 = v96[13];
                  v99 = v97->bounds;
                  v101 = v99[1].length;
                  Play(this, v85, motion, v9, v98, 0, 0, 1, v97->m_Items[v101 * v9].isp);
                  goto LABEL_97;
                }
                if (v69[44] && IsFinished2(this, v9))
                  goto LABEL_80;
              }
LABEL_97:
              ++v9;
            }
            while (v9 < v10);
          }
        }
      }
    }
  }
}
