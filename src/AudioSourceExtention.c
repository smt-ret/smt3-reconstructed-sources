#include "types.h"

typedef struct AudioSourceExtention__PlayBGM_FadeIn_d__3 AudioSourceExtention__PlayBGM_FadeIn_d__3;
typedef struct AudioSourceExtention__PlayVoiceCallback_d__6 AudioSourceExtention__PlayVoiceCallback_d__6;
typedef struct AudioSourceExtention__StopBGM_FadeOut_d__4 AudioSourceExtention__StopBGM_FadeOut_d__4;
typedef struct AudioSourceExtention__StopSE_FadeOut_d__5 AudioSourceExtention__StopSE_FadeOut_d__5;
typedef struct AudioSourceExtention__StopVOICE_FadeOut_d__7 AudioSourceExtention__StopVOICE_FadeOut_d__7;

struct AudioSourceExtention__PlayBGM_FadeIn_d__3 {
    s32 __1__state;
    void *__2__current;
    f32 targetVolume;
    void *audioClip;
    void *audioSource;
    f32 startTime;
    f32 fadeTime;
    f32 _aFadeTime_5__2;
};

struct AudioSourceExtention__StopBGM_FadeOut_d__4 {
    s32 __1__state;
    void *__2__current;
    void *audioSource;
    f32 fadeTime;
};

struct AudioSourceExtention__StopSE_FadeOut_d__5 {
    s32 __1__state;
    void *__2__current;
    void *audioSource;
    f32 fadeTime;
};

struct AudioSourceExtention__PlayVoiceCallback_d__6 {
    s32 __1__state;
    void *__2__current;
    void *audioClip;
    void *audioSource;
    f32 volume;
    void *compCallback;
    f32 _timer_5__2;
};

struct AudioSourceExtention__StopVOICE_FadeOut_d__7 {
    s32 __1__state;
    void *__2__current;
    void *audioSource;
    f32 fadeTime;
};

static bool bHalfMode;
static bool bHalfMode_Voice;
static f32 HalfVolumePar;

// 0xfdd640
void *PlayBGM_FadeIn(void *audioSource, void *audioClip, f32 targetVolume, f32 fadeTime, f32 startTime) {
  u64 *v11;

  v11 = Allocate(AudioSourceExtention__PlayBGM_FadeIn_d__3);
  _ctor(v11, 0);
  *(v11 + 4) = 0;
  v11[5] = audioClip;
  v11[6] = audioSource;
  *(v11 + 8) = targetVolume;
  *(v11 + 15) = fadeTime;
  *(v11 + 14) = startTime;
  return v11;
}

// 0xfdd870
void *PlayVoiceCallback(void *audioSource, void *audioClip, f32 volume, void *compCallback) {
  u64 *v9;

  v9 = Allocate(AudioSourceExtention__PlayVoiceCallback_d__6);
  _ctor(v9, 0);
  *(v9 + 4) = 0;
  v9[4] = audioClip;
  v9[5] = audioSource;
  *(v9 + 12) = volume;
  v9[7] = compCallback;
  return v9;
}

// 0xfdd9e0
void SetHalf(void *audioSource, bool bHalf) {
  bHalfMode = bHalf;
}

// 0xfdda50
void SetHalf_Voice(void *audioSource, bool bHalf) {
  bHalfMode_Voice = bHalf;
}

// 0xfdd710
void *StopBGM_FadeOut(void *audioSource, f32 fadeTime) {
  u64 *v5;

  v5 = Allocate(AudioSourceExtention__StopBGM_FadeOut_d__4);
  _ctor(v5, 0);
  *(v5 + 4) = 0;
  v5[4] = audioSource;
  *(v5 + 10) = fadeTime;
  return v5;
}

// 0xfdd7c0
void *StopSE_FadeOut(void *audioSource, f32 fadeTime) {
  u64 *v5;

  v5 = Allocate(AudioSourceExtention__StopSE_FadeOut_d__5);
  _ctor(v5, 0);
  *(v5 + 4) = 0;
  v5[4] = audioSource;
  *(v5 + 10) = fadeTime;
  return v5;
}

// 0xfdd930
void *StopVOICE_FadeOut(void *audioSource, f32 fadeTime) {
  u64 *v5;

  v5 = Allocate(AudioSourceExtention__StopVOICE_FadeOut_d__7);
  _ctor(v5, 0);
  *(v5 + 4) = 0;
  v5[4] = audioSource;
  *(v5 + 10) = fadeTime;
  return v5;
}
