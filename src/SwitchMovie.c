#include "types.h"

typedef struct SwitchMovie SwitchMovie;
typedef struct SwitchMovie_MvFIT SwitchMovie_MvFIT;
typedef struct SwitchMovie_MvSTAT SwitchMovie_MvSTAT;

struct SwitchMovie_MvFIT {
    s32 value__;
};

struct SwitchMovie_MvSTAT {
    s32 value__;
};

void ClrDrawFlag(u32 flag);
void FilterDelete(void);
void FldChrObjSw(bool sw);
void Log(char *fmt, void **parray);
void loadmovie(SwitchMovie *this, char *filename, s32 Layer);
void loadwait(SwitchMovie *this);
s32 scrCommand_BLUR_ALLOFF(void);
s32 scrCommand_FILTER_ALLOFF(void);

// 0x1340770
void Awake(SwitchMovie *this) {
    Log(0, 0);
}

// 0x13423e0
f32 GetVolume(SwitchMovie *this) {
  bool Float;
  f32 v5;
  f32 v6;
  f32 value;

  value = 0.0;
  Float = GetFloat(
            Instance->Mixer,
            StringLiteral_12182,
            &value,
            0);
  v5 = value;
  v6 = 0.0;
  if (Float)
    v6 = v5 / 20.0;
  return powf(10.0, v6);
}

// 0x1340bd0
void OnDestroy(SwitchMovie *this) {
  System_Object_array *v3;
  struct UnityEngine_Switch_SwitchVideoPlayer_o *video;
  UnityEngine_Switch_SwitchVideoPlayer_o **p_video;
  struct UnityEngine_UI_RawImage_o *images;
  System_String_o *v13;
  System_Object_array *v15;
  u64 *v16;
  UnityEngine_Object_o *v19;

  v3 = NewSpecific(object, 5u);
  v3->m_Items[0] = StringLiteral_12196;
  p_video = &this->video;
  video = this->video;
  v3->m_Items[1] = video;
  v3->m_Items[2] = StringLiteral_100;
  images = this->images;
  v3->m_Items[3] = images;
  v3->m_Items[4] = StringLiteral_12197;
  v13 = Concat_5270224(v3);
  v15 = Empty_string_();
  Log(v13, v15, 0);
  if (*p_video)
  {
    Stop(*p_video);
    Terminate(*p_video);
    Dispose(*p_video, 0);
  }
  v16 = Allocate(UnityEngine_Switch_SwitchVideoPlayer_MovieEventDelegate);
  _ctor(v16, this, Method_SwitchMovie_OnMovieEvent__, 0);
  {
  }
  remove_OnMovieEvent(v16);
  this->lumaTex = 0;
  this->chromaTex = 0;
  *p_video = 0;
  v19 = this->images;
  if (op_Inequality(v19, 0, 0))
  {
    (this->images->klass->vtable._37_Rebuild.methodPtr)(
      this->images,
      0,
      this->images->klass->vtable._37_Rebuild.method);
    this->images = 0;
  }
  *&this->prepared = 0;
}

// 0x13420e0
void OnMovieEvent(SwitchMovie *this, s32 FMVevent) {
    Log(0, 0);
    FldChrObjSw(0);
}

// 0x1341ff0
void Pause(SwitchMovie *this) {
  UnityEngine_Switch_SwitchVideoPlayer_o *video;

  if (this->Status == 3)
  {
    video = this->video;
    if (video)
    {
      Pause(video, 1, 0);
      this->Status = 4;
    }
  }
}

// 0x1341410
void Play(SwitchMovie *this, char *filename, s32 Layer) {
  this->FileName = filename;
  loadmovie(this, filename, Layer);
  this->Status = 1;
}

// 0x1342040
void Resume(SwitchMovie *this) {
  UnityEngine_Switch_SwitchVideoPlayer_o *video;

  if (this->Status == 4)
  {
    video = this->video;
    if (video)
    {
      Pause(video, 0, 0);
      this->Status = 3;
    }
  }
}

// 0x1342210
void SetOffset(SwitchMovie *this, f32 ofs) {
    Log(0, 0);
}

// 0x1340b30
void Start(SwitchMovie *this) {
  u64 *v3;

  v3 = Allocate(UnityEngine_Switch_SwitchVideoPlayer_MovieEventDelegate);
  _ctor(v3, this, Method_SwitchMovie_OnMovieEvent__, 0);
  {
  }
  add_OnMovieEvent(v3);
}

// 0x1342090
void Stop(SwitchMovie *this) {
  UnityEngine_Switch_SwitchVideoPlayer_o *video;

  video = this->video;
  if (video)
  {
    Stop(video);
    Terminate(this->video);
    Dispose(this->video, 0);
    this->video = 0;
    this->Status = 5;
  }
}

// 0x1340f60
void Update(SwitchMovie *this) {
  s32 Status;
  UnityEngine_Switch_SwitchVideoPlayer_o *video;
  UnityEngine_Switch_SwitchVideoPlayer_o *v5;
  System_Object_array *v7;

  Status = this->Status;
  switch (Status)
  {
    case 3:
      video = this->video;
      if (video)
        Update(video, 0);
      if (this->finished)
        this->Status = 5;
      break;
    case 2:
      v5 = this->video;
      if (v5)
        Update(v5, 0);
      this->Status = 3;
      v7 = Empty_string_();
      Log(StringLiteral_12209, v7, 0);
      break;
    case 1:
      loadwait(this);
      break;
  }
}

// 0x13413d0
void draw(SwitchMovie *this) {
  UnityEngine_Switch_SwitchVideoPlayer_o *video;

  video = this->video;
  if (video)
    Update(video, 0);
  if (this->finished)
    this->Status = 5;
}

// 0x1341440
void loadmovie(SwitchMovie *this, char *filename, s32 Layer) {
    Log(0, 0);
}

// 0x1341060
void loadwait(SwitchMovie *this) {
  System_Object_array *v4;
  UnityEngine_Switch_SwitchVideoPlayer_o *video;
  System_String_o *v7;
  System_Object_array *v9;
  UnityEngine_Object_o *images;
  System_Object_array *v14;
  System_Object_array *v18;
  s64 *v19;

  v4 = Empty_string_();
  Log(StringLiteral_12204, v4, 0);
  video = this->video;
  if (video)
    Update(video, 0);
  if (this->prepared)
  {
    v7 = Concat_5269984(StringLiteral_12205, this->images, StringLiteral_4866);
    v9 = Empty_string_();
    Log(v7, v9, 0);
    images = this->images;
    if (op_Inequality(images, 0, 0))
    {
      set_enabled(this->images, 1);
      this->Status = 3;
    }
    FilterDelete();
    v14 = Empty_string_();
    Log(StringLiteral_12206, v14, 0);
    FldChrObjSw(0);
    if (PlayingNo == 12)
    {
      scrCommand_FILTER_ALLOFF();
      scrCommand_BLUR_ALLOFF();
    }
    v18 = Empty_string_();
    v19 = &StringLiteral_12207;
  }
  else
  {
    ClrDrawFlag(0x2000000u);
    v18 = Empty_string_();
    v19 = &StringLiteral_12208;
  }
  Log(*v19, v18, 0);
}

// 0x1341330
void playinit(SwitchMovie *this) {
  UnityEngine_Switch_SwitchVideoPlayer_o *video;
  System_Object_array *v5;

  video = this->video;
  if (video)
    Update(video, 0);
  this->Status = 3;
  v5 = Empty_string_();
  Log(StringLiteral_12209, v5, 0);
}
