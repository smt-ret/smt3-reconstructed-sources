#include "types.h"

typedef struct SoundCoroutine SoundCoroutine;

static SoundCoroutine *Instance;

void _AddFadeCoroutineListAndStart(SoundCoroutine *this, s32 idx, void *routine);
void _StopFadeCoroutine(SoundCoroutine *this, s32 idx);

// 0x13359b0
void AddFadeCoroutineListAndStart(s32 idx, void *routine) {
  _AddFadeCoroutineListAndStart(Instance, idx, routine);
}

// 0x1335c80
void AddFadeCoroutineStartSE(void *routine) {
  UnityEngine_MonoBehaviour_o **static_fields;
  UnityEngine_MonoBehaviour_o *v4;
  UnityEngine_Coroutine_o *klass;

  static_fields = SoundCoroutine->static_fields;
  v4 = *static_fields;
  klass = (*static_fields)[2].klass;
  if (klass)
  {
    StopCoroutine_27344864(*static_fields, klass);
    v4[2].klass = 0;
  }
  v4[2].klass = StartCoroutine_27343696(v4, routine);
}

// 0x1335f20
void AddFadeOutCoroutineListAndStart(void *routine) {
  StartCoroutine_27343696(Instance, routine);
}

// 0x1335d50
void AddVoiceCoroutineListAndStart(void *routine) {
  UnityEngine_MonoBehaviour_o **static_fields;
  UnityEngine_MonoBehaviour_o *v4;
  UnityEngine_Coroutine_o *monitor;

  static_fields = SoundCoroutine->static_fields;
  v4 = *static_fields;
  monitor = (*static_fields)[1].monitor;
  if (monitor)
  {
    StopCoroutine_27344864(*static_fields, monitor);
    v4[1].monitor = 0;
  }
  v4[1].monitor = StartCoroutine_27343696(v4, routine);
}

// 0x1335910
void Awake(SoundCoroutine *this) {
  struct UnityEngine_Coroutine_array *bgmCoroutineList;
  struct UnityEngine_Coroutine_array *v5;

  Instance = this;
  bgmCoroutineList = this->bgmCoroutineList;
  bgmCoroutineList->m_Items[0] = 0;
  v5 = this->bgmCoroutineList;
  v5->m_Items[1] = 0;
  this->seCoroutine_FadeOut = 0;
}

// 0x1335eb0
void SetVoiceCoroutineCB(void) {
  Instance->voiceCoroutine = 0;
}

// 0x1335b60
void StopFadeCoroutine(s32 idx) {
  _StopFadeCoroutine(Instance, idx);
}

// 0x1335e20
void StopVoiceCoroutine(void) {
  UnityEngine_MonoBehaviour_o **static_fields;
  UnityEngine_Coroutine_o *monitor;

  static_fields = SoundCoroutine->static_fields;
  monitor = (*static_fields)[1].monitor;
  if (monitor)
    StopCoroutine_27344864(*static_fields, monitor);
}

// 0x1335a20
void _AddFadeCoroutineListAndStart(SoundCoroutine *this, s32 idx, void *routine) {
  struct UnityEngine_Coroutine_array *bgmCoroutineList;
  s64 v8;
  struct UnityEngine_Coroutine_array *v10;
  struct UnityEngine_Coroutine_array *v12;
  struct UnityEngine_Coroutine_array *v14;
  s64 *started;
  s64 *v16;

  bgmCoroutineList = this->bgmCoroutineList;
  v8 = idx;
  if (bgmCoroutineList->m_Items[idx])
  {
    v10 = this->bgmCoroutineList;
    StopCoroutine_27344864(this, v10->m_Items[idx]);
    v12 = this->bgmCoroutineList;
    v12->m_Items[v8] = 0;
  }
  v14 = this->bgmCoroutineList;
  started = StartCoroutine_27343696(this, routine);
  v16 = started;
  v14->m_Items[v8] = v16;
}

// 0x1335d00
void _AddFadeCoroutineStartSE(SoundCoroutine *this, void *routine) {
  UnityEngine_Coroutine_o *seCoroutine_FadeOut;

  seCoroutine_FadeOut = this->seCoroutine_FadeOut;
  if (seCoroutine_FadeOut)
  {
    StopCoroutine_27344864(this, seCoroutine_FadeOut);
    this->seCoroutine_FadeOut = 0;
  }
  this->seCoroutine_FadeOut = StartCoroutine_27343696(this, routine);
}

// 0x1335f80
void _AddFadeOutCoroutineListAndStart(SoundCoroutine *this, void *routine) {
  StartCoroutine_27343696(this, routine);
}

// 0x1335dd0
void _AddVoiceCoroutineListAndStart(SoundCoroutine *this, void *routine) {
  UnityEngine_Coroutine_o *voiceCoroutine;

  voiceCoroutine = this->voiceCoroutine;
  if (voiceCoroutine)
  {
    StopCoroutine_27344864(this, voiceCoroutine);
    this->voiceCoroutine = 0;
  }
  this->voiceCoroutine = StartCoroutine_27343696(this, routine);
}

// 0x1335f10
void _SetVoiceCoroutineCB(SoundCoroutine *this) {
  this->voiceCoroutine = 0;
}

// 0x1335bc0
void _StopFadeCoroutine(SoundCoroutine *this, s32 idx) {
  struct UnityEngine_Coroutine_array *bgmCoroutineList;
  s64 v6;
  struct UnityEngine_Coroutine_array *v8;
  struct UnityEngine_Coroutine_array *v10;

  bgmCoroutineList = this->bgmCoroutineList;
  v6 = idx;
  if (bgmCoroutineList->m_Items[idx])
  {
    v8 = this->bgmCoroutineList;
    StopCoroutine_27344864(this, v8->m_Items[idx]);
  }
  v10 = this->bgmCoroutineList;
  v10->m_Items[v6] = 0;
}

// 0x1335e90
void _StopVoiceCoroutine(SoundCoroutine *this) {
  UnityEngine_Coroutine_o *voiceCoroutine;

  voiceCoroutine = this->voiceCoroutine;
  if (voiceCoroutine)
    StopCoroutine_27344864(this, voiceCoroutine);
}
