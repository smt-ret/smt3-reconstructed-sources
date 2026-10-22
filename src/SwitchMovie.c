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
  System_Object_array *v4;
  UnityEngine_GameObject_o *gameObject;
  System_Object_array *v6;
  struct UnityEngine_UI_RawImage_o *images;
  UnityEngine_GameObject_o *v12;
  s64 *v13;
  s64 *v14;
  System_String_o *v16;
  System_Object_array *v17;
  struct UnityEngine_UI_RawImage_o *v18;
  Il2CppObject *object;
  Il2CppObject *v20;
  System_String_o *v21;
  System_Object_array *v22;
  UnityEngine_GameObject_o *v23;
  Il2CppObject *v24;
  u64 *v25;
  bool v29[4];

  v29[0] = 0;
  v4 = Empty_string_();
  Log("@@@@ Awake Movie @@@@", v4, 0);
  *&this->Fit = 0;
  *&this->prepared = 0;
  gameObject = get_gameObject(this);
  this->images = AddComponent_object_(gameObject);
  v6 = NewSpecific(object, 4u);
  v6->m_Items[0] = "images = ";
  images = this->images;
  v6->m_Items[1] = images;
  v6->m_Items[2] = ",";
  v12 = get_gameObject(this);
  v29[0] = get_activeSelf(v12);
  v13 = sub_3C0020(v29);
  v14 = v13;
  v6->m_Items[3] = v14;
  v16 = Concat_5270224(v6);
  v17 = Empty_string_();
  Log(v16, v17, 0);
  v18 = this->images;
  object = Load_object_("FMVTexture");
  (v18->klass->vtable._37_Rebuild.methodPtr)(v18, object, v18->klass->vtable._37_Rebuild.method);
  v20 = (this->images->klass->vtable._36_OnCullingChanged.methodPtr)(
          this->images,
          this->images->klass->vtable._36_OnCullingChanged.method);
  v21 = Concat("material = ", v20);
  v22 = Empty_string_();
  Log(v21, v22, 0);
  set_enabled(this->images, 0);
  v23 = get_gameObject(this);
  v24 = AddComponent_object_(v23);
  set_overrideSorting(v24, 1);
  set_sortingOrder(v24, -1);
  v25 = Allocate(UnityEngine_Switch_SwitchVideoPlayer);
  _ctor(v25, 0, 0, 0);
  this->video = v25;
  this->Multiply = 0.0;
  this->prepared_step = 0;
}

// 0x13423e0
f32 GetVolume(SwitchMovie *this) {
  bool Float;
  f32 v5;
  f32 v6;
  f32 value;

LABEL_7:
  value = 0.0;
  Float = GetFloat(
            Instance->Mixer,
            "MovieVolume",
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
  v3->m_Items[0] = "@@@@ OnDestroy : ";
  p_video = &this->video;
  video = this->video;
  v3->m_Items[1] = video;
  v3->m_Items[2] = ",";
  images = this->images;
  v3->m_Items[3] = images;
  v3->m_Items[4] = " @@@@";
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
  u64 *v5;
  System_String_o *v6;
  System_Object_array *v8;
  s32 v10;

  v10 = FMVevent;
  v5 = sub_8D3950(s32, &v10);
  v6 = Concat_5269984("@@@@@ OnMovieEvent = ", v5, " @@@@@");
  v8 = Empty_string_();
  Log(v6, v8, 0);
  if (FMVevent == 2)
  {
    FldChrObjSw(1);
    this->finished = 1;
  }
  else if (FMVevent == 4)
  {
    this->prepared = 1;
  }
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
  if (this->video)
  {
    else if ((byte_3F59407 & 1) != 0)
    {
      goto LABEL_8;
    }
    goto LABEL_8;
  }
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
      Log("@@@@@ PLAYINIT @@@@@", v7, 0);
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
  UnityEngine_Switch_SwitchVideoPlayer_o *video;
  u64 *v8;
  s32 Width;
  s32 Height;
  System_Object_array *v11;
  UnityEngine_Object_o *Texture;
  s64 *name;
  s64 *v15;
  UnityEngine_Texture_o *v18;
  s64 *v19;
  s64 *v20;
  UnityEngine_Object_o *v23;
  s64 *v24;
  s64 *v25;
  System_String_o *v27;
  System_Object_array *v29;
  u64 *v30;
  s32 v31;
  s32 v32;
  s32 v33;
  System_Object_array *v34;
  UnityEngine_Object_o *v36;
  s64 *v37;
  s64 *v38;
  UnityEngine_Texture_o *v41;
  s64 *v42;
  s64 *v43;
  UnityEngine_Object_o *v46;
  s64 *v47;
  s64 *v48;
  System_String_o *v50;
  System_Object_array *v51;
  UnityEngine_Material_o *v52;
  UnityEngine_Texture_o *v53;
  UnityEngine_Material_o *v54;
  UnityEngine_Texture_o *v55;
  UnityEngine_GUILayer_o *Component_GUILayer;
  f32 v57;
  UnityEngine_Transform_o *v58;
  f32 v59;
  f32 v60;
  UnityEngine_Vector2_o v98;
  UnityEngine_Vector3_o v99;
  s32 hideFlags;
  f32 v101;
  UnityEngine_Vector3_o one;

  video = this->video;
  if (video)
  {
    *&this->Width = 0x43800000780LL;
    this->prepared_step = 0;
    GetTrackInfo(video, filename, &this->Width, &this->Height);
    SetContainerType(this->video, 1);
    v8 = Allocate(UnityEngine_Switch_SwitchFMVTexture);
    _ctor(v8, 0);
    Width = this->Width;
    Height = this->Height;
    this->lumaTex = v8;
    Create(v8, Width, Height, 1, 0);
    v11 = NewSpecific(object, 6u);
    v11->m_Items[0] = "@@@@@ lumaTex : ";
    Texture = GetTexture(this->lumaTex, 0);
    name = get_name(Texture);
    v15 = name;
    v11->m_Items[1] = v15;
    v11->m_Items[2] = ",";
    v18 = GetTexture(this->lumaTex, 0);
    LODWORD(v99.x) = (v18->klass->vtable._4_get_width.methodPtr)(v18, v18->klass->vtable._4_get_width.method);
    v19 = sub_8D3950(s32, &v99);
    v20 = v19;
    v11->m_Items[3] = v20;
    v11->m_Items[4] = ",";
    v23 = GetTexture(this->lumaTex, 0);
    LODWORD(v98.x) = get_hideFlags(v23);
    v24 = sub_8D3950(UnityEngine_HideFlags, &v98);
    v25 = v24;
    v11->m_Items[5] = v25;
    v27 = Concat_5270224(v11);
    v29 = Empty_string_();
    Log(v27, v29, 0);
    v30 = Allocate(UnityEngine_Switch_SwitchFMVTexture);
    _ctor(v30, 0);
    v31 = this->Height;
    v32 = this->Width;
    if (v31 >= 0)
      v33 = this->Height;
    else
      v33 = v31 + 1;
    this->chromaTex = v30;
    Create(v30, v32 / 2, v33 >> 1, 2, 0);
    v34 = NewSpecific(object, 6u);
    v34->m_Items[0] = "@@@@@ chromaTex : ";
    v36 = GetTexture(this->chromaTex, 0);
    v37 = get_name(v36);
    v38 = v37;
    v34->m_Items[1] = v38;
    v34->m_Items[2] = ",";
    v41 = GetTexture(this->chromaTex, 0);
    LODWORD(v101) = (v41->klass->vtable._4_get_width.methodPtr)(v41, v41->klass->vtable._4_get_width.method);
    v42 = sub_8D3950(s32, &v101);
    v43 = v42;
    v34->m_Items[3] = v43;
    v34->m_Items[4] = ",";
    v46 = GetTexture(this->chromaTex, 0);
    hideFlags = get_hideFlags(v46);
    v47 = sub_8D3950(UnityEngine_HideFlags, &hideFlags);
    v48 = v47;
    v34->m_Items[5] = v48;
    v50 = Concat_5270224(v34);
    v51 = Empty_string_();
    Log(v50, v51, 0);
    Init(this->video, this->lumaTex, this->chromaTex, 0);
    v52 = (this->images->klass->vtable._36_OnCullingChanged.methodPtr)(
            this->images,
            this->images->klass->vtable._36_OnCullingChanged.method);
    v53 = GetTexture(this->lumaTex, 0);
    set_mainTexture(v52, v53);
    v54 = (this->images->klass->vtable._36_OnCullingChanged.methodPtr)(
            this->images,
            this->images->klass->vtable._36_OnCullingChanged.method);
    v55 = GetTexture(this->chromaTex, 0);
    SetTexture(v54, "_ChromaTex", v55, 0);
    Component_GUILayer = GetComponent_GUILayer_(this);
    if (Layer == -1)
      v57 = -100.0;
    else
      v57 = 0.0;
    v58 = Component_GUILayer;
    v99.z = 0.0;
    *&v99.x = 0;
    sub_8524C0(&v99.x, 0.0, 0.0, v57);
    set_localPosition(v58, v99);
    v59 = this->Height;
    v60 = this->Width;
    v98 = 0;
    sub_851710(&v98, v60, v59);
    set_sizeDelta(v58, v98);
    one = get_one();
    set_localScale(v58, one);
    else if ((byte_3F59407 & 1) != 0)
    {
      goto LABEL_68;
    }
    goto LABEL_68;
  }
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
  Log("@@@@@ loadwait @@@@@@", v4, 0);
  video = this->video;
  if (video)
    Update(video, 0);
  if (this->prepared)
  {
    v7 = Concat_5269984("@@@@@ Prepared : ", this->images, " @@@@@");
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
    Log("FilterDelete", v14, 0);
    FldChrObjSw(0);
    if (PlayingNo == 12)
    {
      scrCommand_FILTER_ALLOFF();
      scrCommand_BLUR_ALLOFF();
    }
    v18 = Empty_string_();
    v19 = &"FldChrObjSw";
  }
  else
  {
    ClrDrawFlag(0x2000000u);
    v18 = Empty_string_();
    v19 = &"@@@@@ STOP1 @@@@@";
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
  Log("@@@@@ PLAYINIT @@@@@", v5, 0);
}
