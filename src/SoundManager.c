#include "types.h"

typedef struct SoundCoroutine SoundCoroutine;
typedef struct SoundManager SoundManager;
typedef struct SoundManager__ChannelWork SoundManager__ChannelWork;
typedef struct SoundManager__SoundWork SoundManager__SoundWork;
typedef struct SoundManager_eType SoundManager_eType;
typedef struct evtTexManager evtTexManager;

struct SoundManager {
    void *_object;
    void *Mixer;
    void *_sourceBgmArray[2];
    void *_sourceSeArray[16];
    void *_sourceVoiceArray[2];
    void *_sourceMovie;
    SoundManager__ChannelWork *_channelBgmArray[2];
    SoundManager__ChannelWork *_channelSeArray[16];
    void *_poolBgm;
    void *_poolSe;
    void *_poolVoice;
    s32 _3DSE_stdposx;
    s32 _3DSE_stdposy;
    s32 _3DSE_stdposz;
    s32 _3DSE_stddeg;
    bool _3DSE_se3dflag;
    s32 _3DSE_PS2DPAN_CENTER;
    s32 _3DSE_ATAN_TIMES;
    s32 _3DSE_atandim[32];
    void *gMixer_bgm;
    void *gMixer_se;
};

struct SoundManager__ChannelWork {
    char *Key_DefineName;
    s32 Key_MidiId;
    s32 status;
    s32 ps2_vol;
    s32 ps2_pan;
    s32 posx;
    s32 posy;
    s32 posz;
    s32 se3d;
    s32 lim;
    s32 pan_block;
};

struct SoundManager_eType {
    s32 value__;
};

struct SoundManager__SoundWork {
    char *DefineName;
    s32 MidiId;
    char *SoundFileName;
    void *Clip;
    bool LoopMode;
    s32 OldCount;
    f32 ContinueTime;
    char *KeyName;
    s32 Loading;
};

static SoundManager *Instance;
static char *nowPlayBgmName;
static s32 nowPlayBgmMidiId;
static bool nowVoicePlaying;

s32 Atan(SoundManager *this, s32 x, s32 y);
void ContinueBGM(char *name);
void ContinueBGM_20162336(s32 id);
void FadeinBGM(char *name, f32 fadetime);
void FadeinBGM_20161776(s32 id, f32 fadetime);
void FadeoutBGM(char *name, f32 fadeTime);
s32 FindId(s32 type, char *name);
s32 FindId_1916848(s32 type, s32 id);
bool Find_1915744(s32 type, s32 id);
u8 Get(s32 id);
void HalfBgm_Voice(SoundManager *this, bool onoff);
void Initialize(evtTexManager *this, char *key, char *path);
char *IsLocalizeKey(char *key);
void PlayBGM(char *name);
void PlayBGM_20160448(s32 id);
void *PlayBGM_FadeIn(void *audioSource, void *audioClip, f32 targetVolume, f32 fadeTime, f32 startTime);
s32 PlaySE(char *name);
void *PlayVoiceCallback(void *audioSource, void *audioClip, f32 volume, void *compCallback);
void RemoveAllData(SoundManager *this, void *src, s32 index);
void SetHalf(void *audioSource, bool bHalf);
void SetHalf_Voice(void *audioSource, bool bHalf);
void SmgTableInit(void);
void StopBGM(char *name);
void *StopBGM_FadeOut(void *audioSource, f32 fadeTime);
void StopSE(char *name);
void *StopSE_FadeOut(void *audioSource, f32 fadeTime);
void *StopVOICE_FadeOut(void *audioSource, f32 fadeTime);
void UpdateBgmSoundWork(SoundManager *this);
void UpdateVoiceSoundWork(SoundManager *this);
void _AddFadeCoroutineListAndStart(SoundCoroutine *this, s32 idx, void *routine);
void _CrossFadePlayBGM_Core(SoundManager *this, char *name, s32 id, f32 crossFadeTime, f32 startTime);
void _DeleteBGM(SoundManager *this, char *name);
void _DeleteSE(SoundManager *this, char *name);
void _DeleteVoice(SoundManager *this, char *name);
void _LoadBGM_Core(SoundManager *this, s32 id);
bool _LoadCheckBGM(SoundManager *this, s32 id);
bool _LoadCheckSE(SoundManager *this, s32 id);
void _LoadResideSE(SoundManager *this);
void _LoadSE(SoundManager *this, s32 id);
void _LoadVoice(SoundManager *this, char *name);
void _PlayBGM(SoundManager *this, s32 id, f32 fadetime, f32 starttime);
s32 _PlaySE_Core(SoundManager *this, void *audioClip, bool loop, f32 volume, f32 pan, char *name, s32 id);
s32 _PlaySE_Ex(SoundManager *this, s32 id, f32 volume, f32 pan);
void _PlayVoice(SoundManager *this, char *name);
void _SoundManagerInit(SoundManager *this);
bool _StatusSE_NameHead(SoundManager *this, char *name_char1, char *name_char2);
void _StopBGM_Core(SoundManager *this, s32 id, f32 fadeTime);
void _StopFadeCoroutine(SoundCoroutine *this, s32 idx);
void _StopSE_Core(SoundManager *this, s32 id);
void _StopVoice(SoundManager *this);
void _loadse(char *key);
bool evtBitCheck(s32 no);
void p2sdPlaySE_Pan(s32 MidiNo, s32 pan);
void p2sdPlaySE_Vol(s32 SENo, s32 vol);
void p2sdPlaySe3DEx(s32 MidiNo, f32 posx, f32 posy, f32 posz, s32 limit);
void p2sdSet3DPan(SoundManager *this, s32 ch);
void p2sdSndStop(s32 MidiNo);

// 0x133bbf0
s32 Atan(SoundManager *this, s32 x, s32 y) {
  s32 v4;
  s32 v5;
  s32 v6;
  s32 v7;
  struct System_Int32_array *v8;
  s32 v10;
  bool v11;
  s32 v12;
  struct System_Int32_array *_3DSE_atandim;

  if (x >= 0)
    v4 = x;
  else
    v4 = -x;
  if (y >= 0)
    v5 = y;
  else
    v5 = -y;
  if (v4)
  {
    if (!v5)
    {
      v11 = x < 0;
      v10 = 90;
      goto LABEL_23;
    }
    v6 = this->_3DSE_ATAN_TIMES - 1;
    if (v4 >= v5)
    {
      v12 = v6 * v5 / v4;
      _3DSE_atandim = this->_3DSE_atandim;
      v10 = 90 - _3DSE_atandim->m_Items[v12];
    }
    else
    {
      v7 = v6 * v4 / v5;
      v8 = this->_3DSE_atandim;
      v10 = v8->m_Items[v7];
    }
    if (y < 0)
      v10 = 180 - v10;
  }
  else if (y < 0)
  {
    v10 = 180;
  }
  else
  {
    v10 = 0;
  }
  v11 = x < 0;
LABEL_23:
  if (v11)
    return -v10;
  else
    return v10;
}

// 0x133cc20
void CallbackVoice(SoundManager *this) {
  HalfBgm_Voice(this, 0);
  nowVoicePlaying = 0;
}

// 0x133ce60
bool ChkVoicePlaying(void) {
LABEL_7:
  return nowVoicePlaying;
}

// 0x133a670
void ContinueBGM(char *name) {
  s32 Id;
  s32 v5;

  Id = FindId(0, name);
  else
  {
    v5 = Id;
  }
  ContinueBGM_20162336(v5);
}

// 0x133a720
void ContinueBGM_20162336(s32 id) {
  s32 nowPlayBgmMidiId;
  System_String_o *v5;
  Il2CppObject *v7;
  Il2CppObject *v9;
  s32 ida;

  ida = id;
  v5 = sub_232A70(&ida, "X8");
  if (nowPlayBgmMidiId == id)
  {
    v7 = Concat_5221536("ContinueBGM(", v5, ") 再生中と同じなのでキャンセルです", 0);
    Log(v7, 0);
  }
  else
  {
    v9 = Concat_5221536("ContinueBGM(", v5, ") BGMリクエストです", 0);
    Log(v9, 0);
    _PlayBGM(Instance, ida, 1.0, -1.0);
  }
}

// 0x13328d0
void DeleteBGM(char *name) {
  _DeleteBGM(Instance, name);
}

// 0x1332940
void DeleteSE(char *name) {
  _DeleteSE(Instance, name);
}

// 0x133c470
void DeleteVoice(char *name) {
  _DeleteVoice(Instance, name);
}

// 0x13329b0
void DeleteVoiceALL(void) {
  System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o *Keys;
  u32 Count;
  System_String_array *v5;
  System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o *v6;
  il2cpp_array_size_t max_length;
  u64 v10;
  SoundManager_o *Instance;

  Keys = string___get_Keys(Instance->_poolVoice);
  Count = string___get_Count(Keys);
  v5 = NewSpecific(string, Count);
  v6 = string___get_Keys(Instance->_poolVoice);
  string___CopyTo(v6, v5, 0);
  max_length = v5->max_length;
  if (max_length >= 1)
  {
    v10 = 0;
    do
    {
      else
      {
        if (v10 >= max_length)
        {
LABEL_13:
        }
      }
      _DeleteVoice(Instance, v5->m_Items[v10]);
      LODWORD(max_length) = v5->max_length;
      ++v10;
    }
    while (v10 < max_length);
  }
}

// 0x133a440
void FadeinBGM(char *name, f32 fadetime) {
  s32 Id;

  Id = FindId(0, name);
  FadeinBGM_20161776(Id, fadetime);
}

// 0x133a4f0
void FadeinBGM_20161776(s32 id, f32 fadetime) {
  s32 nowPlayBgmMidiId;
  System_String_o *v7;
  Il2CppObject *v9;
  Il2CppObject *v11;
  s32 ida;

  ida = id;
  v7 = sub_232A70(&ida, "X8");
  if (nowPlayBgmMidiId == id)
  {
    v9 = Concat_5221536("FadeinBGM(", v7, ") 再生中と同じなのでキャンセルです", 0);
    Log(v9, 0);
  }
  else
  {
    v11 = Concat_5221536("FadeinBGM(", v7, ") BGMリクエストです", 0);
    Log(v11, 0);
    _PlayBGM(Instance, ida, fadetime, 0.0);
  }
}

// 0x133b770
void FadeoutBGM(char *name, f32 fadeTime) {
  s32 Id;

  Id = FindId(0, name);
LABEL_10:
  _StopBGM_Core(Instance, Id, fadeTime);
}

// 0x133b880
void FadeoutBGM_20166784(s32 id, f32 fadeTime) {
  _StopBGM_Core(Instance, id, fadeTime);
}

// 0x133b900
void FadeoutBGM_ALL(f32 fadeTime) {
  _StopBGM_Core(Instance, -1, fadeTime);
}

// 0x133f550
void *GetMovieAudioSource(void) {
  return Instance->_sourceMovie;
}

// 0x133f4b0
f32 GetMovieVolume(void) {
  bool Float;
  f32 result;
  f32 value;

  value = 0.0;
  Float = GetFloat(
            Instance->Mixer,
            "MovieVolume",
            &value,
            0);
  result = value;
  if (!Float)
    return 0.0;
  return result;
}

// 0x133bab0
s32 GetPoolBgmNum(SoundManager *this) {
  return HashSet_Text____get_Count(this->_poolBgm);
}

// 0x133bb00
s32 GetPoolSeNum(SoundManager *this) {
  return HashSet_Text____get_Count(this->_poolSe);
}

// 0x133bb50
s32 GetPoolVoiceNum(SoundManager *this) {
  return HashSet_Text____get_Count(this->_poolVoice);
}

// 0x133ba10
void HalfBgm(SoundManager *this, bool onoff) {
  struct UnityEngine_AudioSource_array *sourceBgmArray;
  UnityEngine_AudioSource_o *v7;

  sourceBgmArray = this->_sourceBgmArray;
  v7 = sourceBgmArray->m_Items[0];
  SetHalf(v7, onoff);
}

// 0x13397c0
void HalfBgm_Voice(SoundManager *this, bool onoff) {
  struct UnityEngine_AudioSource_array *sourceBgmArray;
  UnityEngine_AudioSource_o *v8;

  else if (!cfgGetBit(2u))
  {
    return;
  }
  sourceBgmArray = this->_sourceBgmArray;
  v8 = sourceBgmArray->m_Items[0];
  SetHalf_Voice(v8, onoff);
}

// 0x1338f20
bool IsBGMFadeOut(void) {
  struct SoundManager_o *v2;
  struct SoundManager__ChannelWork_array **p_channelBgmArray;
  struct UnityEngine_AudioSource_array *sourceBgmArray;
  struct SoundManager_o *Instance;
  UnityEngine_AudioSource_o *v7;
  UnityEngine_Object_o *clip;
  u32 v12;
  _BOOL8 isPlaying;
  struct UnityEngine_AudioSource_array *v17;
  UnityEngine_AudioSource_o *v19;
  UnityEngine_Object_o *v22;
  _BOOL8 v24;

  {
    else
    {
      p_channelBgmArray = &Instance->_channelBgmArray;
    }
    sourceBgmArray = Instance->_sourceBgmArray;
    if (!LODWORD(sourceBgmArray->max_length))
      goto LABEL_47;
    goto LABEL_11;
  }
  v2 = Instance;
  p_channelBgmArray = &v2->_channelBgmArray;
  sourceBgmArray = v2->_sourceBgmArray;
  if (!LODWORD(sourceBgmArray->max_length))
  {
LABEL_47:
  }
LABEL_11:
  v7 = sourceBgmArray->m_Items[0];
  clip = get_clip(v7);
  if (op_Equality(clip, 0, 0))
  {
    v12 = 0;
    (*p_channelBgmArray)->m_Items[0]->status = 0;
      goto LABEL_19;
  }
  else
  {
    isPlaying = get_isPlaying(v7, 0);
    if (!isPlaying || get_volume(v7) <= 0.0)
    {
      RemoveAllData(isPlaying, v7, 0);
      v12 = 0;
        goto LABEL_28;
      goto LABEL_19;
    }
    v12 = (*p_channelBgmArray)->m_Items[0]->status == 2;
    {
LABEL_19:
    }
  }
LABEL_28:
  v17 = Instance->_sourceBgmArray;
  v19 = v17->m_Items[1];
  v22 = get_clip(v19);
  if (op_Equality(v22, 0, 0))
  {
    (*p_channelBgmArray)->m_Items[1]->status = 0;
  }
  else
  {
    v24 = get_isPlaying(v19, 0);
    if (v24 && get_volume(v19) > 0.0)
    {
      v12 = v12 & 0xFFFFFFFD | (2 * ((*p_channelBgmArray)->m_Items[1]->status == 2));
    }
    else
    {
      RemoveAllData(v24, v19, 1);
    }
  }
  return v12 != 0;
}

// 0x1339280
bool IsBGMStopped(void) {
  struct UnityEngine_AudioSource_array *sourceBgmArray;
  UnityEngine_AudioSource_o *v5;
  UnityEngine_Object_o *clip;
  struct SoundManager__ChannelWork_array *channelBgmArray;
  f32 volume;
  bool v14;
  SoundManager_o *v16;
  struct UnityEngine_AudioSource_array *v17;
  UnityEngine_AudioSource_o *v19;
  UnityEngine_Object_o *v21;
  struct SoundManager__ChannelWork_array *v24;
  f32 v28;
  SoundManager_o *v29;

  sourceBgmArray = Instance->_sourceBgmArray;
  v5 = sourceBgmArray->m_Items[0];
  clip = get_clip(v5);
  if (op_Equality(clip, 0, 0))
    goto LABEL_27;
  channelBgmArray = Instance->_channelBgmArray;
  if (channelBgmArray->m_Items[0]->Key_MidiId)
  {
LABEL_27:
    v14 = 1;
      goto LABEL_28;
    goto LABEL_21;
  }
  volume = get_volume(v5);
  if (volume <= 0.0)
  {
    RemoveAllData(v16, v5, 0);
    goto LABEL_27;
  }
  v14 = 0;
    goto LABEL_28;
LABEL_21:
LABEL_28:
  v17 = Instance->_sourceBgmArray;
  v19 = v17->m_Items[1];
  v21 = get_clip(v19);
  if (!op_Equality(v21, 0, 0))
  {
    v24 = Instance->_channelBgmArray;
    if (!v24->m_Items[1]->Key_MidiId)
    {
      v28 = get_volume(v19);
      if (v28 <= 0.0)
      {
        RemoveAllData(v29, v19, 1);
      }
      else
      {
        return 0;
      }
    }
  }
  return v14;
}

// 0x1331530
void LoadBGM(char *name) {
  s32 Id;

  Id = FindId(0, name);
  _LoadBGM_Core(Instance, Id);
}

// 0x1339ae0
void LoadBGM_20159200(s32 id) {
  _LoadBGM_Core(Instance, id);
}

// 0x1336f60
void LoadResideSE(void) {
  SoundManager_o *v2;

  _LoadResideSE(v2);
}

// 0x1331940
void LoadSE(char *name) {
  s32 Id;

  Id = FindId(1, name);
LABEL_10:
  _LoadSE(Instance, Id);
}

// 0x13371c0
void LoadSE_20148672(s32 id) {
  _LoadSE(Instance, id);
}

// 0x133c2e0
void LoadVoice(char *name) {
  _LoadVoice(Instance, name);
}

// 0x1335340
void PlayBGM(char *name) {
  s32 Id;
  s32 v5;

  Id = FindId(0, name);
  else
  {
    v5 = Id;
  }
  PlayBGM_20160448(v5);
}

// 0x1339fc0
void PlayBGM_20160448(s32 id) {
  s32 nowPlayBgmMidiId;
  System_String_o *v5;
  Il2CppObject *v7;
  Il2CppObject *v9;
  s32 ida;

  ida = id;
  v5 = sub_232A70(&ida, "X8");
  if (nowPlayBgmMidiId == id)
  {
    v7 = Concat_5221536("PlayBGM(", v5, ") 再生中と同じなのでキャンセルです", 0);
    Log(v7, 0);
  }
  else
  {
    v9 = Concat_5221536("PlayBGM(", v5, ") BGMリクエストです", 0);
    Log(v9, 0);
    _PlayBGM(Instance, ida, 0.0, 0.0);
  }
}

// 0x1335470
s32 PlaySE(char *name) {
  s32 Id;

  Id = FindId(1, name);
LABEL_10:
  return _PlaySE_Ex(Instance, Id, 1.0, 0.0);
}

// 0x13377b0
s32 PlaySE_20150192(s32 id) {
  return _PlaySE_Ex(Instance, id, 1.0, 0.0);
}

// 0x13379b0
s32 PlaySE_Ex(char *name, f32 volume, f32 pan) {
  s32 Id;

  Id = FindId(1, name);
  return _PlaySE_Ex(Instance, Id, volume, pan);
}

// 0x1337a70
s32 PlaySE_Ex_20150896(s32 id, f32 volume, f32 pan) {
  return _PlaySE_Ex(Instance, id, volume, pan);
}

// 0x1335640
void PlayVoice(char *name) {
  _PlayVoice(Instance, name);
}

// 0x133a8a0
f32 PopContinueBGM(SoundManager *this, char *name) {
  if (Animator___ContainsKey(this->_poolBgm, name))
  {
    return *&object___get_Item(this->_poolBgm, name)[3].monitor;
  }
  else
  {
    return 0.0;
  }
}

// 0x133b980
void PushContinueBGM(SoundManager *this, char *name, f32 clipTime) {
  if (Animator___ContainsKey(this->_poolBgm, name))
  {
    *&object___get_Item(this->_poolBgm, name)[3].monitor = clipTime;
  }
}

// 0x1338a70
void RemoveAllData(SoundManager *this, void *src, s32 index) {
  UnityEngine_Object_o *clip;
  u64 *v9;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  s64 v14;
  UnityEngine_Object_o *v15;
  System_String_o *name;
  UnityEngine_Object_o *v17;
  System_String_o *v18;
  s32 v20;
  System_Collections_Generic_Dictionary_Font__HashSet_Text___o *poolBgm;
  System_WeakReference_o *Item;
  struct SoundManager__ChannelWork_array *channelBgmArray;
  struct SoundManager__ChannelWork_array *v28;
  struct SoundManager__ChannelWork_array *v30;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v32;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v33;

  memset(&v33, 0, sizeof(v33));
  if (!op_Equality(src, 0, 0))
  {
    clip = get_clip(src);
    if (!op_Equality(clip, 0, 0))
    {
      Stop(src);
      _StopFadeCoroutine(Instance, index);
      v9 = Allocate(System_Collections_Generic_List_SoundManager__SoundWork_);
      __ctor(
        v9);
      _Clear(v9);
      Values = Type___get_Values(Instance->_poolBgm);
      Type___GetEnumerator(&v32, Values);
      v33 = v32;
      while ((sub_4D4B20(&v33) & 1) != 0)
      {
        v14 = sub_4D4CB0(&v33);
        v15 = *(v14 + 40);
        if (!op_Equality(v15, 0, 0))
        {
          name = get_name(*(v14 + 40), 0);
          v17 = get_clip(src);
          v18 = get_name(v17);
          if (Equals_5234480(name, v18))
            _Add(v9, v14);
        }
      }
      nullsub_48(&v33);
      if (_get_Count(v9) >= 1)
      {
        v20 = 0;
        do
        {
          poolBgm = Instance->_poolBgm;
          Item = _get_Item(
                   v9,
                   v20);
          HashSet_Text____Remove(poolBgm, *&Item->fields);
          ++v20;
        }
        while (v20 < _get_Count(v9));
      }
      set_clip(src, 0);
      channelBgmArray = Instance->_channelBgmArray;
      channelBgmArray->m_Items[index]->Key_DefineName = "";
      v28 = Instance->_channelBgmArray;
      v28->m_Items[index]->Key_MidiId = 0;
      v30 = Instance->_channelBgmArray;
      v30->m_Items[index]->status = 0;
    }
  }
}

// 0x1335ff0
void SoundManagerInit(void) {
  u64 *v4;

  Log("SoundManagerInit()です", 0);
  else if (Instance)
  {
    goto LABEL_9;
  }
  Log("Instance new です", 0);
  v4 = Allocate(SoundManager);
  _ctor(v4);
  Instance = v4;
  {
LABEL_10:
  }
LABEL_20:
  _SoundManagerInit(Instance);
}

// 0x133bba0
s32 Sqrt(SoundManager *this, s32 x) {
  s32 v3;
  s32 result;
  s32 v5;
  bool v6;

  if (x < 1)
    return -1;
  v3 = 1;
  do
  {
    result = (x / v3 + v3) / 2;
    v5 = v3 + 1;
    v6 = result == v3 - 1 || result == v3;
    v3 = (x / v3 + v3) / 2;
  }
  while (!v6 && result != v5);
  return result;
}

// 0x133b5f0
void StopBGM(char *name) {
  s32 Id;

  Id = FindId(0, name);
LABEL_10:
  _StopBGM_Core(Instance, Id, 0.1);
}

// 0x13386a0
void StopBGMALL_Compulsion(bool flg) {
  struct SoundManager_o *v3;
  struct SoundManager__ChannelWork_array **p_channelBgmArray;
  struct UnityEngine_AudioSource_array *sourceBgmArray;
  struct SoundManager_o *Instance;
  UnityEngine_AudioSource_o *v7;
  s32 Key_MidiId;
  SoundManager_o *v10;
  struct UnityEngine_AudioSource_array *v17;
  struct SoundManager__ChannelWork_array *v19;
  UnityEngine_AudioSource_o *v20;
  s32 v21;
  SoundManager_o *v24;
  SoundManager_o *v29;

  {
    else
    {
      p_channelBgmArray = &Instance->_channelBgmArray;
    }
    sourceBgmArray = Instance->_sourceBgmArray;
    if (!LODWORD(sourceBgmArray->max_length))
      goto LABEL_25;
    goto LABEL_11;
  }
  v3 = Instance;
  p_channelBgmArray = &v3->_channelBgmArray;
  sourceBgmArray = v3->_sourceBgmArray;
  if (!LODWORD(sourceBgmArray->max_length))
  {
LABEL_25:
  }
LABEL_11:
  v7 = sourceBgmArray->m_Items[0];
  Key_MidiId = (*p_channelBgmArray)->m_Items[0]->Key_MidiId;
  if (!Key_MidiId)
    goto LABEL_28;
  if (Key_MidiId != nowPlayBgmMidiId)
    goto LABEL_28;
LABEL_16:
  if (!flg || !get_isPlaying(v7, 0) || get_volume(v7) <= 0.0)
    goto LABEL_34;
  RemoveAllData(v10, v7, 0);
  nowPlayBgmName = "";
  nowPlayBgmMidiId = 0;
  {
LABEL_35:
  }
LABEL_37:
  v17 = Instance->_sourceBgmArray;
  v19 = *p_channelBgmArray;
  v20 = v17->m_Items[1];
  v21 = v19->m_Items[1]->Key_MidiId;
  if (v21)
  {
    else if (v21 == nowPlayBgmMidiId)
    {
LABEL_44:
      if (flg && get_isPlaying(v20, 0) && get_volume(v20) > 0.0)
      {
        RemoveAllData(v24, v20, 1);
        nowPlayBgmName = "";
        nowPlayBgmMidiId = 0;
      }
      return;
    }
  }
  if (!get_isPlaying(v20, 0) || get_volume(v20) == 0.0)
  {
    RemoveAllData(v29, v20, 1);
  }
}

// 0x133b6f0
void StopBGM_20166384(s32 id) {
  _StopBGM_Core(Instance, id, 0.1);
}

// 0x133b570
void StopBGM_ALL(void) {
  _StopBGM_Core(Instance, -1, 0.1);
}

// 0x1338050
void StopSE(char *name) {
  s32 Id;

  Id = FindId(1, name);
LABEL_10:
  _StopSE_Core(Instance, Id);
}

// 0x1338150
void StopSE_20152656(s32 id) {
  _StopSE_Core(Instance, id);
}

// 0x13383f0
void StopSE_ALL(void) {
  _StopSE_Core(Instance, -1);
}

// 0x133cca0
void StopVoice(void) {
  _StopVoice(Instance);
}

// 0x1339530
void StopVoice_Compulsion(void) {
  UnityEngine_MonoBehaviour_o **static_fields;
  UnityEngine_Coroutine_o *monitor;
  struct UnityEngine_AudioSource_array *sourceVoiceArray;
  il2cpp_array_size_t max_length;
  u64 v7;
  UnityEngine_AudioSource_o *v9;
  UnityEngine_Object_o *clip;
  f32 time;
  UnityEngine_AudioClip_o *v13;
  System_Collections_IEnumerator_o *v15;

  monitor = (*static_fields)[1].monitor;
  if (monitor)
    StopCoroutine_27344864(*static_fields, monitor);
  sourceVoiceArray = Instance->_sourceVoiceArray;
  max_length = sourceVoiceArray->max_length;
  if (max_length >= 1)
  {
    v7 = 0;
    while (1)
    {
      v9 = sourceVoiceArray->m_Items[v7];
      clip = get_clip(v9);
      if (op_Equality(clip, 0, 0))
        goto LABEL_25;
      time = get_time(v9, 0);
      v13 = get_clip(v9);
      if (time >= (get_length(v13) + -0.1))
      {
        Stop(v9);
        set_clip(v9, 0);
        LODWORD(max_length) = sourceVoiceArray->max_length;
        if (++v7 >= max_length)
        {
LABEL_28:
          break;
        }
      }
      else
      {
        v15 = StopVOICE_FadeOut(v9, 0.05);
        StartCoroutine_27343696(Instance, v15);
LABEL_25:
        LODWORD(max_length) = sourceVoiceArray->max_length;
        if (++v7 >= max_length)
          goto LABEL_28;
      }
    }
  }
  HalfBgm_Voice(Instance, 0);
  nowVoicePlaying = 0;
}

// 0x133f140
void UpdateAudioVolume(s32 type) {
  s32 Bit;
  s64 *v6;
  UnityEngine_Audio_AudioMixerGroup_array *MatchingGroups;
  f32 v12;
  struct SoundManager_o *Instance;
  s64 *v15;

  if (type == 2)
  {
    Bit = cfgGetBit(2u);
    else
    {
      v6 = &"Voice";
    }
  }
  else if (type == 1)
  {
    Bit = cfgGetBit(1u);
    v6 = &"SE";
  }
  else if (type)
  {
    Bit = cfgGetBit(3u);
    v6 = &"Movie";
  }
  else
  {
    Bit = cfgGetBit(0);
    else
    {
      v6 = &"BGM";
    }
  }
  MatchingGroups = FindMatchingGroups(Instance->Mixer, *v6);
  if (MatchingGroups && MatchingGroups->max_length)
  {
    if (Bit)
    {
      v12 = log10f(Bit / 5.0) * 20.0;
      if (type != 2)
        goto LABEL_39;
    }
    else
    {
      v12 = -80.0;
      if (type != 2)
      {
LABEL_39:
        if (type == 1)
        {
          v15 = &"SEVolume";
        }
        else if (type)
        {
          v15 = &"MovieVolume";
        }
        else
        {
          v15 = &"BGMVolume";
        }
LABEL_59:
        SetFloat(Instance->Mixer, *v15, v12);
        return;
      }
    }
    v15 = &"VoiceVolume";
    goto LABEL_59;
  }
}

// 0x133b320
void UpdateBgmSoundWork(SoundManager *this) {
  System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o *Keys;
  Il2CppObject *v4;
  Il2CppObject *Item;
  s32 v6;
  Il2CppObject *v7;
  bool v8;
  Il2CppObject *v10;
  UnityEngine_Object_o *monitor;
  System_Collections_Generic_Dictionary_KeyCollection_Enumerator_TKey__TValue__o v13;
  System_Collections_Generic_Dictionary_KeyCollection_Enumerator_TKey__TValue__o v14;

  memset(&v14, 0, sizeof(v14));
  Keys = string___get_Keys(this->_poolBgm);
  object___GetEnumerator(
    &v13,
    Keys);
  v14 = v13;
  while ((sub_4402C0(&v14) & 1) != 0)
  {
    v4 = sub_440450(&v14);
    Item = object___get_Item(this->_poolBgm, v4);
    v6 = HIDWORD(Item[3].klass) + 1;
    v7 = Item;
    v8 = HIDWORD(Item[3].klass) - 3 < 0;
    HIDWORD(Item[3].klass) = v6;
    if (v8 == __OFSUB__(v6, 4))
    {
      v10 = Concat_5221536("UpdateBgmSoundWork() REMOVE:[", v4, "]古いワークを破棄です", 0);
      Log(v10, 0);
      monitor = v7[2].monitor;
      if (op_Implicit(monitor, 0))
        UnloadAudioData(v7[2].monitor);
      HashSet_Text____Remove(this->_poolBgm, v4);
      break;
    }
  }
  nullsub_33(&v14);
}

// 0x133c9d0
void UpdateVoiceSoundWork(SoundManager *this) {
  System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o *Keys;
  Il2CppObject *v4;
  Il2CppObject *Item;
  s32 v6;
  Il2CppObject *v7;
  bool v8;
  Il2CppObject *v10;
  UnityEngine_Object_o *monitor;
  System_Collections_Generic_Dictionary_KeyCollection_Enumerator_TKey__TValue__o v13;
  System_Collections_Generic_Dictionary_KeyCollection_Enumerator_TKey__TValue__o v14;

  memset(&v14, 0, sizeof(v14));
  Keys = string___get_Keys(this->_poolVoice);
  object___GetEnumerator(
    &v13,
    Keys);
  v14 = v13;
  while ((sub_4402C0(&v14) & 1) != 0)
  {
    v4 = sub_440450(&v14);
    Item = object___get_Item(this->_poolVoice, v4);
    v6 = HIDWORD(Item[3].klass) + 1;
    v7 = Item;
    v8 = HIDWORD(Item[3].klass) - 2 < 0;
    HIDWORD(Item[3].klass) = v6;
    if (v8 == __OFSUB__(v6, 3))
    {
      v10 = Concat_5221536("UpdateVoiceSoundWork() REMOVE:[", v4, "]", 0);
      Log(v10, 0);
      monitor = v7[2].monitor;
      if (op_Implicit(monitor, 0))
        UnloadAudioData(v7[2].monitor);
      HashSet_Text____Remove(this->_poolVoice, v4);
      break;
    }
  }
  nullsub_33(&v14);
}

// 0x133cf20
bool _ChkVoicePlaying(SoundManager *this) {
  return nowVoicePlaying;
}

// 0x133a940
void _CrossFadePlayBGM_Core(SoundManager *this, char *name, s32 id, f32 crossFadeTime, f32 startTime) {
  struct UnityEngine_AudioSource_array *sourceBgmArray;
  UnityEngine_AudioSource_o *v13;
  struct SoundManager__ChannelWork_array *channelBgmArray;
  s32 v15;
  f32 v16;
  struct SoundManager__ChannelWork_array *v18;
  struct SoundManager__ChannelWork_array *v20;
  struct UnityEngine_AudioSource_array *v22;
  UnityEngine_AudioSource_o *v24;
  struct SoundManager__ChannelWork_array *v25;
  struct SoundManager__ChannelWork_array *v27;
  struct SoundManager__ChannelWork_array *v29;
  UnityEngine_Object_o *clip;
  System_String_o *v33;
  UnityEngine_Object_o *v35;
  System_String_o *v36;
  Il2CppObject *Item;
  UnityEngine_AudioClip_o *monitor;
  struct UnityEngine_AudioSource_array *v40;
  Il2CppObject *v41;
  UnityEngine_AudioSource_o *v43;
  System_Collections_IEnumerator_o *v46;
  struct SoundManager__ChannelWork_array *v48;
  struct SoundManager__ChannelWork_array *v50;
  struct SoundManager__ChannelWork_array *v52;
  Il2CppClass **v54;
  UnityEngine_AudioSource_o *v56;
  struct UnityEngine_AudioSource_array *v57;
  s64 v59;
  System_Collections_IEnumerator_o *v62;
  struct SoundManager__ChannelWork_array *v63;
  struct SoundManager__ChannelWork_array *v65;
  struct SoundManager__ChannelWork_array *v67;

  sourceBgmArray = this->_sourceBgmArray;
  v13 = sourceBgmArray->m_Items[0];
  if (!get_isPlaying(v13, 0))
    goto LABEL_8;
  channelBgmArray = this->_channelBgmArray;
  if (!channelBgmArray->m_Items[0]->Key_MidiId)
  {
    clip = get_clip(v13);
    v33 = get_name(clip);
    v15 = ~Contains(v33, name, 0) << 31 >> 31;
  }
  else
  {
LABEL_8:
    v15 = -1;
  }
  v16 = fmaxf(crossFadeTime, 0.1);
  if (get_isPlaying(v13, 0))
  {
    v18 = this->_channelBgmArray;
    if (v18->m_Items[0]->Key_MidiId)
    {
      v20 = this->_channelBgmArray;
      _StopBGM_Core(this, v20->m_Items[0]->Key_MidiId, v16);
    }
  }
  v22 = this->_sourceBgmArray;
  v24 = v22->m_Items[1];
  if (!get_isPlaying(v24, 0))
    goto LABEL_21;
  v25 = this->_channelBgmArray;
  if (v25->m_Items[1]->Key_MidiId)
  {
LABEL_21:
    if (!get_isPlaying(v24, 0))
      goto LABEL_34;
    goto LABEL_22;
  }
  v35 = get_clip(v24);
  v36 = get_name(v35);
  if (Contains(v36, name, 0))
    v15 = 1;
  if (get_isPlaying(v24, 0))
  {
LABEL_22:
    v27 = this->_channelBgmArray;
    if (v27->m_Items[1]->Key_MidiId)
    {
      v29 = this->_channelBgmArray;
      _StopBGM_Core(this, v29->m_Items[1]->Key_MidiId, v16);
    }
  }
LABEL_34:
  if (Animator___ContainsKey(this->_poolBgm, name))
  {
    Item = object___get_Item(this->_poolBgm, name);
    HIDWORD(Item[3].klass) = 0;
    monitor = Item[2].monitor;
    v40 = this->_sourceBgmArray;
    v41 = Item;
    if (v15 == -1)
    {
      v56 = v40->m_Items[0];
      if (get_isPlaying(v56, 0))
      {
        v57 = this->_sourceBgmArray;
        v56 = v57->m_Items[1];
        if (get_isPlaying(v56, 0))
          goto LABEL_77;
        v59 = 1;
      }
      else
      {
        v59 = 0;
      }
      set_loop(v56, v41[3].klass);
      v62 = PlayBGM_FadeIn(v56, monitor, 1.0, crossFadeTime, startTime);
      _AddFadeCoroutineListAndStart(Instance, v59, v62);
      v63 = this->_channelBgmArray;
      v63->m_Items[v59]->status = 1;
      v65 = this->_channelBgmArray;
      v65->m_Items[v59]->Key_DefineName = name;
      v67 = this->_channelBgmArray;
      v54 = &v67->obj.klass + v59;
    }
    else
    {
      v43 = v40->m_Items[v15];
      _StopFadeCoroutine(Instance, v15);
      set_loop(v43, v41[3].klass);
      v46 = PlayBGM_FadeIn(v43, monitor, 1.0, crossFadeTime, startTime);
      _AddFadeCoroutineListAndStart(Instance, v15, v46);
      v48 = this->_channelBgmArray;
      v48->m_Items[v15]->status = 1;
      v50 = this->_channelBgmArray;
      v50->m_Items[v15]->Key_DefineName = name;
      v52 = this->_channelBgmArray;
      v54 = &v52->obj.klass + v15;
    }
    LODWORD(v54[4]->_1.namespaze) = id;
    nowPlayBgmName = name;
    nowPlayBgmMidiId = id;
LABEL_77:
    UpdateBgmSoundWork(this);
  }
}

// 0x1339c90
void _DeleteBGM(SoundManager *this, char *name) {
  struct UnityEngine_AudioSource_array *sourceBgmArray;
  UnityEngine_AudioSource_o *v7;
  UnityEngine_Object_o *clip;
  System_String_o *v9;
  struct UnityEngine_AudioSource_array *v10;
  UnityEngine_Object_o *v12;
  System_String_o *v13;
  UnityEngine_Object_o *v14;
  System_String_o *v15;
  Il2CppObject *v17;
  Il2CppObject *Item;
  UnityEngine_Object_o *monitor;
  struct UnityEngine_AudioSource_array *v21;
  UnityEngine_AudioSource_o *v23;
  UnityEngine_Object_o *v25;
  UnityEngine_Object_o *v26;
  System_String_o *v27;
  struct UnityEngine_AudioSource_array *v28;
  UnityEngine_AudioSource_o *v30;
  UnityEngine_Object_o *v32;
  UnityEngine_Object_o *v33;
  System_String_o *v34;

  sourceBgmArray = this->_sourceBgmArray;
  v7 = sourceBgmArray->m_Items[0];
  if (get_isPlaying(v7, 0))
  {
    clip = get_clip(v7);
    v9 = get_name(clip);
    if (Contains(v9, name, 0))
      goto LABEL_11;
  }
  v10 = this->_sourceBgmArray;
  v7 = v10->m_Items[1];
  if (get_isPlaying(v7, 0)
    && (v12 = get_clip(v7),
        v13 = get_name(v12),
        Contains(v13, name, 0)))
  {
LABEL_11:
    v14 = get_clip(v7);
    v15 = get_name(v14);
    v17 = Concat_5224608("サウンドCLIPは再生中(FadeOut含む)なので自動破棄で処理します :", v15, 0);
    Log(v17, 0);
  }
  else if (Animator___ContainsKey(this->_poolBgm, name))
  {
    Item = object___get_Item(this->_poolBgm, name);
    monitor = Item[2].monitor;
    if (op_Implicit(monitor, 0))
      UnloadAudioData(Item[2].monitor);
    HashSet_Text____Remove(this->_poolBgm, name);
    v21 = this->_sourceBgmArray;
    v23 = v21->m_Items[0];
    v25 = get_clip(v23);
    if (op_Inequality(v25, 0, 0))
    {
      v26 = get_clip(v23);
      v27 = get_name(v26);
      if (Contains(v27, name, 0))
        set_clip(v23, 0);
    }
    v28 = this->_sourceBgmArray;
    v30 = v28->m_Items[1];
    v32 = get_clip(v30);
    if (op_Inequality(v32, 0, 0))
    {
      v33 = get_clip(v30);
      v34 = get_name(v33);
      if (Contains(v34, name, 0))
        set_clip(v30, 0);
    }
  }
}

// 0x13376b0
void _DeleteSE(SoundManager *this, char *name) {
  Il2CppObject *Item;
  UnityEngine_Object_o *monitor;

  if (Animator___ContainsKey(this->_poolSe, name))
  {
    Item = object___get_Item(this->_poolSe, name);
    monitor = Item[2].monitor;
    else if (!op_Implicit(monitor, 0))
    {
LABEL_8:
      HashSet_Text____Remove(this->_poolSe, name);
      return;
    }
    UnloadAudioData(Item[2].monitor);
    goto LABEL_8;
  }
}

// 0x133c4e0
void _DeleteVoice(SoundManager *this, char *name) {
  Il2CppObject *Item;
  UnityEngine_Object_o *monitor;

  if (Animator___ContainsKey(this->_poolVoice, name))
  {
    Item = object___get_Item(this->_poolVoice, name);
    monitor = Item[2].monitor;
    else if (!op_Implicit(monitor, 0))
    {
LABEL_8:
      HashSet_Text____Remove(this->_poolVoice, name);
      return;
    }
    UnloadAudioData(Item[2].monitor);
    goto LABEL_8;
  }
}

// 0x13398b0
void _LoadBGM_Core(SoundManager *this, s32 id) {
  bool v9;
  Il2CppObject *v12;
  Il2CppObject *v14;
  struct Smg__MidiWork_o *FindOut;
  System_String_o *DefineName;
  System_String_o *FileName;
  s32 MidiId;
  bool LoopMode;
  struct System_Collections_Generic_Dictionary_string__SoundManager__SoundWork__o *poolBgm;
  u64 *v21;

  if (Find_1915744(0, id))
  {
    v9 = _LoadCheckBGM(this, FindOut->MidiId);
    if (v9)
    {
      v12 = Concat_5221536(
              " LoadBgm(",
              FindOut->FileName,
              ") ロード済なので skip です",
              0);
      Log(v12, 0);
    }
    else
    {
      v14 = Concat_5221536(
              " LoadBgm(",
              FindOut->FileName,
              ") ロードします",
              0);
      Log(v14, 0);
      DefineName = FindOut->DefineName;
      FileName = FindOut->FileName;
      MidiId = FindOut->MidiId;
      LoopMode = FindOut->LoopMode;
      poolBgm = this->_poolBgm;
      v21 = Allocate(SoundManager__SoundWork);
      SoundWork___ctor(v21, 0, DefineName, FileName, MidiId, LoopMode);
      PropertySheet___Add(poolBgm, DefineName, v21);
    }
  }
}

// 0x1339b50
bool _LoadCheckBGM(SoundManager *this, s32 id) {
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  bool v6;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v8;

  memset(&v8, 0, sizeof(v8));
  Values = Type___get_Values(this->_poolBgm);
  Type___GetEnumerator(&v8, Values);
  while ((sub_4D4B20(&v8) & 1) != 0)
  {
    if (*(sub_4D4CB0(&v8) + 24) == id)
    {
      v6 = 1;
      goto LABEL_8;
    }
  }
  v6 = 0;
LABEL_8:
  nullsub_48(&v8);
  return v6;
}

// 0x1337400
bool _LoadCheckSE(SoundManager *this, s32 id) {
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  bool v6;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v8;

  memset(&v8, 0, sizeof(v8));
  Values = Type___get_Values(this->_poolSe);
  Type___GetEnumerator(&v8, Values);
  while ((sub_4D4B20(&v8) & 1) != 0)
  {
    if (*(sub_4D4CB0(&v8) + 24) == id)
    {
      v6 = 1;
      goto LABEL_8;
    }
  }
  v6 = 0;
LABEL_8:
  nullsub_48(&v8);
  return v6;
}

// 0x1336fd0
void _LoadResideSE(SoundManager *this) {
  System_String_o *v3;
  System_String_o *v5;
  System_String_o *v7;
  System_String_o *v9;
  System_String_o *v11;
  System_String_o *v13;

  Log("常駐SEロード です", 0);
  v3 = "common";
  v5 = IsLocalizeKey(v3);
  _loadse(v5);
  v7 = "fcmn";
  v9 = IsLocalizeKey(v7);
  _loadse(v9);
  v11 = "battle";
  v13 = IsLocalizeKey(v11);
  _loadse(v13);
}

// 0x1337230
void _LoadSE(SoundManager *this, s32 id) {
  Il2CppObject *v11;
  struct System_Collections_Generic_Dictionary_string__SoundManager__SoundWork__o *poolSe;
  struct Smg__MidiWork_o *FindOut;
  s32 MidiId;
  System_String_o *DefineName;
  System_String_o *FileName;
  bool LoopMode;
  u64 *v19;

  if (Find_1915744(1, id))
  {
    if (_LoadCheckSE(this, FindOut->MidiId))
    {
      v11 = Concat_5221536(
              " LoadSe(",
              FindOut->FileName,
              ") ロード済なので skip です",
              0);
      Log(v11, 0);
    }
    else
    {
      poolSe = this->_poolSe;
      MidiId = FindOut->MidiId;
      DefineName = FindOut->DefineName;
      FileName = FindOut->FileName;
      LoopMode = FindOut->LoopMode;
      v19 = Allocate(SoundManager__SoundWork);
      SoundWork___ctor(v19, 1, DefineName, FileName, MidiId, LoopMode);
      PropertySheet___Add(poolSe, DefineName, v19);
    }
  }
}

// 0x133c350
void _LoadVoice(SoundManager *this, char *name) {
  Il2CppObject *v6;
  struct System_Collections_Generic_Dictionary_string__SoundManager__SoundWork__o *poolVoice;
  u64 *v8;

  if (!Animator___ContainsKey(this->_poolVoice, name))
  {
    v6 = Concat_5221536(" LoadVoice(", name, ") ロードします", 0);
    Log(v6, 0);
    poolVoice = this->_poolVoice;
    v8 = Allocate(SoundManager__SoundWork);
    SoundWork___ctor(v8, 2, name, name, 0, 0);
    PropertySheet___Add(poolVoice, name, v8);
  }
}

// 0x133a140
void _PlayBGM(SoundManager *this, s32 id, f32 fadetime, f32 starttime) {
  f32 v5;
  s32 v7;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  s64 v11;
  s64 v13;
  Il2CppObject *v14;
  f32 v15;
  System_String_o *v16;
  Il2CppObject *v18;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v19;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v20;
  f32 v21;

  v5 = starttime;
  v7 = id;
  v21 = starttime;
  memset(&v20, 0, sizeof(v20));
LABEL_7:
  _LoadBGM_Core(Instance, v7);
  Values = Type___get_Values(this->_poolBgm);
  Type___GetEnumerator(&v19, Values);
  v20 = v19;
  while ((sub_4D4B20(&v20) & 1) != 0)
  {
    v11 = sub_4D4CB0(&v20);
    v13 = v11;
    if (*(v11 + 24) == v7)
    {
      if (v5 < 0.0)
      {
        v14 = *(v11 + 16);
        if (Animator___ContainsKey(this->_poolBgm, v14))
        {
          v15 = *&object___get_Item(this->_poolBgm, v14)[3].monitor;
        }
        else
        {
          v15 = 0.0;
        }
        v21 = v15;
        v16 = sub_4FDC70(&v21, "F2");
        v18 = Concat_5221536("starttime : ", v16, "sec");
        Log(v18, 0);
        v5 = v21;
        v7 = *(v13 + 24);
      }
      _CrossFadePlayBGM_Core(this, *(v13 + 16), v7, fadetime, v5);
      break;
    }
  }
  nullsub_48(&v20);
}

// 0x1337b00
s32 _PlaySE_Core(SoundManager *this, void *audioClip, bool loop, f32 volume, f32 pan, char *name, s32 id) {
  struct UnityEngine_AudioSource_array *sourceSeArray;
  UnityEngine_AudioSource_o *v17;
  struct UnityEngine_AudioSource_array *v18;
  struct UnityEngine_AudioSource_array *v20;
  struct UnityEngine_AudioSource_array *v22;
  struct UnityEngine_AudioSource_array *v24;
  struct UnityEngine_AudioSource_array *v26;
  struct UnityEngine_AudioSource_array *v28;
  struct UnityEngine_AudioSource_array *v30;
  struct UnityEngine_AudioSource_array *v32;
  struct UnityEngine_AudioSource_array *v34;
  struct UnityEngine_AudioSource_array *v36;
  struct UnityEngine_AudioSource_array *v38;
  struct UnityEngine_AudioSource_array *v40;
  struct UnityEngine_AudioSource_array *v42;
  struct UnityEngine_AudioSource_array *v44;
  struct UnityEngine_AudioSource_array *v46;
  s64 v48;
  struct UnityEngine_Audio_AudioMixerGroup_array *gMixer_se;
  struct SoundManager__ChannelWork_array *channelSeArray;
  struct SoundManager__ChannelWork_array *v53;
  struct SoundManager__ChannelWork_array *v55;

  sourceSeArray = this->_sourceSeArray;
  v17 = sourceSeArray->m_Items[0];
  if (get_isPlaying(v17, 0))
  {
    v18 = this->_sourceSeArray;
    v17 = v18->m_Items[1];
    if (get_isPlaying(v17, 0))
    {
      v20 = this->_sourceSeArray;
      v17 = v20->m_Items[2];
      if (get_isPlaying(v17, 0))
      {
        v22 = this->_sourceSeArray;
        v17 = v22->m_Items[3];
        if (get_isPlaying(v17, 0))
        {
          v24 = this->_sourceSeArray;
          v17 = v24->m_Items[4];
          if (get_isPlaying(v17, 0))
          {
            v26 = this->_sourceSeArray;
            v17 = v26->m_Items[5];
            if (get_isPlaying(v17, 0))
            {
              v28 = this->_sourceSeArray;
              v17 = v28->m_Items[6];
              if (get_isPlaying(v17, 0))
              {
                v30 = this->_sourceSeArray;
                v17 = v30->m_Items[7];
                if (get_isPlaying(v17, 0))
                {
                  v32 = this->_sourceSeArray;
                  v17 = v32->m_Items[8];
                  if (get_isPlaying(v17, 0))
                  {
                    v34 = this->_sourceSeArray;
                    v17 = v34->m_Items[9];
                    if (get_isPlaying(v17, 0))
                    {
                      v36 = this->_sourceSeArray;
                      v17 = v36->m_Items[10];
                      if (get_isPlaying(v17, 0))
                      {
                        v38 = this->_sourceSeArray;
                        v17 = v38->m_Items[11];
                        if (get_isPlaying(v17, 0))
                        {
                          v40 = this->_sourceSeArray;
                          v17 = v40->m_Items[12];
                          if (get_isPlaying(v17, 0))
                          {
                            v42 = this->_sourceSeArray;
                            v17 = v42->m_Items[13];
                            if (get_isPlaying(v17, 0))
                            {
                              v44 = this->_sourceSeArray;
                              v17 = v44->m_Items[14];
                              if (get_isPlaying(v17, 0))
                              {
                                v46 = this->_sourceSeArray;
                                v17 = v46->m_Items[15];
                                if (get_isPlaying(v17, 0))
                                {
                                  LODWORD(v48) = -1;
                                  return v48;
                                }
                                v48 = 15;
                              }
                              else
                              {
                                v48 = 14;
                              }
                            }
                            else
                            {
                              v48 = 13;
                            }
                          }
                          else
                          {
                            v48 = 12;
                          }
                        }
                        else
                        {
                          v48 = 11;
                        }
                      }
                      else
                      {
                        v48 = 10;
                      }
                    }
                    else
                    {
                      v48 = 9;
                    }
                  }
                  else
                  {
                    v48 = 8;
                  }
                }
                else
                {
                  v48 = 7;
                }
              }
              else
              {
                v48 = 6;
              }
            }
            else
            {
              v48 = 5;
            }
          }
          else
          {
            v48 = 4;
          }
        }
        else
        {
          v48 = 3;
        }
      }
      else
      {
        v48 = 2;
      }
    }
    else
    {
      v48 = 1;
    }
  }
  else
  {
    v48 = 0;
  }
  set_loop(v17, loop);
  set_volume(v17, volume);
  set_panStereo(v17, pan);
  if ((id - 5701712) > 2)
  {
    gMixer_se = this->gMixer_se;
    if (!LODWORD(gMixer_se->max_length))
      goto LABEL_70;
  }
  else
  {
    gMixer_se = this->gMixer_bgm;
    if (!LODWORD(gMixer_se->max_length))
    {
LABEL_70:
    }
  }
  set_outputAudioMixerGroup(v17, gMixer_se->m_Items[0]);
  set_clip(v17, audioClip);
  Play_8758880(v17);
  channelSeArray = this->_channelSeArray;
  channelSeArray->m_Items[v48]->Key_DefineName = name;
  v53 = this->_channelSeArray;
  v53->m_Items[v48]->Key_MidiId = id;
  v55 = this->_channelSeArray;
  v55->m_Items[v48]->se3d = 0;
  return v48;
}

// 0x1337830
s32 _PlaySE_Ex(SoundManager *this, s32 id, f32 volume, f32 pan) {
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  s32 v10;
  s64 v11;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v14;

  memset(&v14, 0, sizeof(v14));
  Values = Type___get_Values(this->_poolSe);
  Type___GetEnumerator(&v14, Values);
  v10 = -1;
  while ((sub_4D4B20(&v14) & 1) != 0)
  {
    v11 = sub_4D4CB0(&v14);
    if (*(v11 + 24) == id)
    {
      v10 = _PlaySE_Core(this, *(v11 + 40), *(v11 + 48), volume, pan, *(v11 + 16), id);
      break;
    }
  }
  nullsub_48(&v14);
  return v10;
}

// 0x133c5e0
void _PlayVoice(SoundManager *this, char *name) {
  UnityEngine_MonoBehaviour_o **static_fields;
  UnityEngine_Coroutine_o *monitor;
  Il2CppObject *Item;
  UnityEngine_AudioClip_o *v9;
  u64 *v10;
  u64 *_9__99_0;
  Il2CppObject *v15;
  System_Delegate_o *v16;
  UnityEngine_Events_UnityAction_c *v17;
  UnityEngine_Events_UnityAction_o *v18;
  char *v19;
  s64 *v20;
  struct UnityEngine_AudioSource_array *sourceVoiceArray;
  il2cpp_array_size_t max_length;
  u64 v23;
  UnityEngine_AudioSource_o *v25;
  System_Collections_IEnumerator_o *v27;
  UnityEngine_MonoBehaviour_o **v28;
  UnityEngine_MonoBehaviour_o *v29;
  UnityEngine_Coroutine_o *v30;
  u64 v32[3];

  monitor = (*static_fields)[1].monitor;
  if (monitor)
    StopCoroutine_27344864(*static_fields, monitor);
  nowVoicePlaying = 0;
  _LoadVoice(Instance, name);
  if (Animator___ContainsKey(this->_poolVoice, name))
  {
    Item = object___get_Item(this->_poolVoice, name);
    HIDWORD(Item[3].klass) = 0;
    v9 = Item[2].monitor;
    v10 = Allocate(UnityEngine_Events_UnityAction);
    _ctor(v10, this, Method_SoundManager_CallbackVoice__, 0);
    else
    {
      _9__99_0 = __9__99_0;
      if (_9__99_0)
        goto LABEL_24;
    }
    v15 = __9;
    _9__99_0 = Allocate(UnityEngine_Events_UnityAction);
    _ctor(_9__99_0, v15, Method_SoundManager___c___PlayVoice_b__99_0__, 0);
    __9__99_0 = _9__99_0;
LABEL_24:
    v16 = Combine(v10, _9__99_0, 0);
    v18 = v16;
    if (v16)
    {
      if (v16->klass != UnityEngine_Events_UnityAction)
      {
        sub_8FC2C0(v16->klass->_1.element_class, UnityEngine_Events_UnityAction, v32);
        if ((v32[0] & 1) != 0)
          v19 = v32[2];
        else
          v19 = v32 + 1;
        v20 = sub_8C4940(v19);
      }
    }
    sourceVoiceArray = this->_sourceVoiceArray;
    max_length = sourceVoiceArray->max_length;
    if (max_length < 1)
    {
LABEL_36:
      {
LABEL_47:
        nowVoicePlaying = 1;
        UpdateVoiceSoundWork(this, v17);
        HalfBgm_Voice(this, 1);
        return;
      }
    }
    else
    {
      v23 = 0;
      while (1)
      {
        v25 = sourceVoiceArray->m_Items[v23];
        if (!get_isPlaying(v25, 0))
          break;
        LODWORD(max_length) = sourceVoiceArray->max_length;
        if (++v23 >= max_length)
          goto LABEL_36;
      }
      v27 = PlayVoiceCallback(v25, v9, 1.0, v18);
      v29 = *v28;
      v30 = (*v28)[1].monitor;
      if (v30)
      {
        StopCoroutine_27344864(*v28, v30);
        v29[1].monitor = 0;
      }
      v29[1].monitor = StartCoroutine_27343696(v29, v27);
        goto LABEL_47;
    }
    goto LABEL_47;
  }
}

// 0x1336220
void _SoundManagerInit(SoundManager *this) {
  UnityEngine_Object_o *object;
  u64 *v6;
  s64 v8;
  u64 v11;
  u32 *sourceBgmArray;
  s64 *v13;
  s64 *v14;
  UnityEngine_Audio_AudioMixerGroup_array *MatchingGroups;
  struct UnityEngine_AudioSource_array *v17;
  UnityEngine_AudioSource_o *v19;
  struct UnityEngine_AudioSource_array *v21;
  struct UnityEngine_AudioSource_array *v23;
  struct UnityEngine_AudioSource_array *v25;
  struct UnityEngine_AudioSource_array *v27;
  struct UnityEngine_AudioSource_array *v29;
  u32 *channelBgmArray;
  u64 *v32;
  s64 v34;
  u64 v36;
  u32 *sourceSeArray;
  s64 *v40;
  s64 *v41;
  UnityEngine_Audio_AudioMixerGroup_array *v43;
  struct UnityEngine_AudioSource_array *v44;
  UnityEngine_AudioSource_o *v46;
  struct UnityEngine_AudioSource_array *v48;
  struct UnityEngine_AudioSource_array *v50;
  struct UnityEngine_AudioSource_array *v52;
  struct UnityEngine_AudioSource_array *v54;
  struct UnityEngine_AudioSource_array *v56;
  u32 *channelSeArray;
  u64 *v59;
  s64 v61;
  u32 *v63;
  struct UnityEngine_AudioSource_array *v64;
  struct UnityEngine_AudioSource_array *v65;
  s64 *v66;
  s64 *v67;
  UnityEngine_Audio_AudioMixerGroup_array *v69;
  struct UnityEngine_AudioSource_array *sourceVoiceArray;
  UnityEngine_AudioSource_o *v71;
  struct UnityEngine_AudioSource_array *v72;
  struct UnityEngine_AudioSource_array *v74;
  struct UnityEngine_AudioSource_array *v76;
  struct UnityEngine_AudioSource_array *v78;
  struct UnityEngine_AudioSource_array *v80;
  struct UnityEngine_AudioSource_array *v82;
  s64 *v83;
  s64 *v84;
  UnityEngine_Audio_AudioMixerGroup_array *v86;
  struct UnityEngine_AudioSource_array *v87;
  UnityEngine_AudioSource_o *v88;
  struct UnityEngine_AudioSource_array *v89;
  struct UnityEngine_AudioSource_array *v91;
  struct UnityEngine_AudioSource_array *v93;
  struct UnityEngine_AudioSource_array *v95;
  struct UnityEngine_AudioSource_array *v97;
  UnityEngine_Audio_AudioMixerGroup_array *v99;

  Log("GameObject new 「SoundManagerObj」 です", 0);
  object = this->_object;
  if (op_Equality(object, 0, 0))
  {
    v6 = Allocate(UnityEngine_GameObject);
    _ctor(v6, "SoundManagerObj", 0);
    this->_object = v6;
    DontDestroyOnLoad(v6);
    this->Mixer = Load_object_("dds3AudioMixer");
  }
  Log("SoundManagerObj に 各.cs を AddComponent です", 0);
  AddComponent_object_(this->_object);
  AddComponent_object_(this->_object);
  Log("BGM用 チャンネル作成 です", 0);
  this->_sourceBgmArray = NewSpecific(UnityEngine_AudioSource, 2u);
  this->_channelBgmArray = NewSpecific(SoundManager__ChannelWork, 2u);
  v8 = 0;
  do
  {
    v11 = v8;
    sourceBgmArray = this->_sourceBgmArray;
    v13 = AddComponent_object_(this->_object);
    v14 = v13;
    *&sourceBgmArray[2 * v11 + 8] = v14;
    MatchingGroups = FindMatchingGroups(this->Mixer, "BGM");
    v17 = this->_sourceBgmArray;
    v19 = v17->m_Items[v11];
    set_outputAudioMixerGroup(v19, MatchingGroups->m_Items[0]);
    v21 = this->_sourceBgmArray;
    set_loop(v21->m_Items[v11], 1);
    v23 = this->_sourceBgmArray;
    set_playOnAwake(v23->m_Items[v11], 0);
    v25 = this->_sourceBgmArray;
    set_volume(v25->m_Items[v11], 1.0);
    v27 = this->_sourceBgmArray;
    set_panStereo(v27->m_Items[v11], 0.0);
    v29 = this->_sourceBgmArray;
    set_spatialBlend(v29->m_Items[v11], 0.0);
    channelBgmArray = this->_channelBgmArray;
    v32 = Allocate(SoundManager__ChannelWork);
    _ctor(v32, 0);
    v34 = "";
    *(v32 + 14) = 0;
    v32[2] = v34;
    v32[5] = 0;
    v32[6] = 0;
    v32[3] = 0;
    v32[4] = 0;
    *&channelBgmArray[2 * v11 + 8] = v32;
    v8 = 1;
  }
  while (!v11);
  Log("SE用 チャンネル作成 です", 0);
  this->_sourceSeArray = NewSpecific(UnityEngine_AudioSource, 0x10u);
  v36 = 0;
  this->_channelSeArray = NewSpecific(SoundManager__ChannelWork, 0x10u);
  do
  {
    sourceSeArray = this->_sourceSeArray;
    v40 = AddComponent_object_(this->_object);
    v41 = v40;
    *&sourceSeArray[2 * v36 + 8] = v41;
    v43 = FindMatchingGroups(this->Mixer, "SE");
    v44 = this->_sourceSeArray;
    v46 = v44->m_Items[v36];
    set_outputAudioMixerGroup(v46, v43->m_Items[0]);
    v48 = this->_sourceSeArray;
    set_loop(v48->m_Items[v36], 0);
    v50 = this->_sourceSeArray;
    set_playOnAwake(v50->m_Items[v36], 0);
    v52 = this->_sourceSeArray;
    set_volume(v52->m_Items[v36], 1.0);
    v54 = this->_sourceSeArray;
    set_panStereo(v54->m_Items[v36], 0.0);
    v56 = this->_sourceSeArray;
    set_spatialBlend(v56->m_Items[v36], 0.0);
    channelSeArray = this->_channelSeArray;
    v59 = Allocate(SoundManager__ChannelWork);
    _ctor(v59, 0);
    v61 = "";
    *(v59 + 14) = 0;
    v59[2] = v61;
    v59[5] = 0;
    v59[6] = 0;
    v59[3] = 0;
    v59[4] = 0;
    v63 = &channelSeArray[2 * v36++];
    *(v63 + 4) = v59;
  }
  while (v36 != 16);
  Log("VOICE用 チャンネル作成 です", 0);
  v64 = NewSpecific(UnityEngine_AudioSource, 2u);
  this->_sourceVoiceArray = v64;
  v65 = v64;
  v66 = AddComponent_object_(this->_object);
  v67 = v66;
  v65->m_Items[0] = v67;
  v69 = FindMatchingGroups(this->Mixer, "Voice");
  sourceVoiceArray = this->_sourceVoiceArray;
  v71 = sourceVoiceArray->m_Items[0];
  set_outputAudioMixerGroup(v71, v69->m_Items[0]);
  v72 = this->_sourceVoiceArray;
  set_loop(v72->m_Items[0], 0);
  v74 = this->_sourceVoiceArray;
  set_playOnAwake(v74->m_Items[0], 0);
  v76 = this->_sourceVoiceArray;
  set_volume(v76->m_Items[0], 1.0);
  v78 = this->_sourceVoiceArray;
  set_panStereo(v78->m_Items[0], 0.0);
  v80 = this->_sourceVoiceArray;
  set_spatialBlend(v80->m_Items[0], 0.0);
  v82 = this->_sourceVoiceArray;
  v83 = AddComponent_object_(this->_object);
  v84 = v83;
  v82->m_Items[1] = v84;
  v86 = FindMatchingGroups(this->Mixer, "Voice");
  v87 = this->_sourceVoiceArray;
  v88 = v87->m_Items[1];
  set_outputAudioMixerGroup(v88, v86->m_Items[0]);
  v89 = this->_sourceVoiceArray;
  set_loop(v89->m_Items[1], 0);
  v91 = this->_sourceVoiceArray;
  set_playOnAwake(v91->m_Items[1], 0);
  v93 = this->_sourceVoiceArray;
  set_volume(v93->m_Items[1], 1.0);
  v95 = this->_sourceVoiceArray;
  set_panStereo(v95->m_Items[1], 0.0);
  v97 = this->_sourceVoiceArray;
  set_spatialBlend(v97->m_Items[1], 0.0);
  this->_sourceMovie = AddComponent_object_(this->_object);
  v99 = FindMatchingGroups(this->Mixer, "Movie");
  set_outputAudioMixerGroup(this->_sourceMovie, v99->m_Items[0]);
  set_loop(this->_sourceMovie, 0);
  set_playOnAwake(this->_sourceMovie, 0);
  set_volume(this->_sourceMovie, 1.0);
  set_panStereo(this->_sourceMovie, 0.0);
  set_spatialBlend(this->_sourceMovie, 0.0);
  this->gMixer_bgm = FindMatchingGroups(this->Mixer, "BGM");
  this->gMixer_se = FindMatchingGroups(this->Mixer, "SE");
  Log("SMG TABLE 初期化 です", 0);
  SmgTableInit();
  Initialize();
}

// 0x1338460
bool _StatusSE(SoundManager *this, s32 id) {
  s64 i;
  struct UnityEngine_AudioSource_array *sourceSeArray;
  u64 v7;
  struct SoundManager__ChannelWork_array *channelSeArray;

  for (i = 4; ; ++i)
  {
    sourceSeArray = this->_sourceSeArray;
    v7 = i - 4;
    if (get_isPlaying(*(&sourceSeArray->obj.klass + i), 0))
    {
      channelSeArray = this->_channelSeArray;
      if (*(*(&channelSeArray->obj.klass + i) + 24LL) == id)
        break;
    }
    if (v7 >= 0xF)
      return 0;
  }
  return 1;
}

// 0x1338510
bool _StatusSE_NameHead(SoundManager *this, char *name_char1, char *name_char2) {
  s64 i;
  struct UnityEngine_AudioSource_array *sourceSeArray;
  u64 v9;
  UnityEngine_AudioSource_o *v11;
  struct SoundManager__ChannelWork_array *channelSeArray;
  System_String_o *v14;
  struct SoundManager__ChannelWork_array *v15;
  s32 Length;
  struct SoundManager__ChannelWork_array *v18;
  System_String_o *v20;
  f32 time;
  UnityEngine_AudioClip_o *clip;

  for (i = 4; ; ++i)
  {
    sourceSeArray = this->_sourceSeArray;
    v9 = i - 4;
    v11 = *(&sourceSeArray->obj.klass + i);
    if (get_isPlaying(v11, 0))
    {
      channelSeArray = this->_channelSeArray;
      v14 = Substring_5248048(*(*(&channelSeArray->obj.klass + i) + 16LL), 0, 1, 0);
      if (op_Equality(v14, name_char1, 0))
      {
        v15 = this->_channelSeArray;
        Length = get_Length(*(*(&v15->obj.klass + i) + 16LL), 0);
        v18 = this->_channelSeArray;
        v20 = Substring_5248048(*(*(&v18->obj.klass + i) + 16LL), Length - 3, 3, 0);
        if (op_Equality(v20, name_char2, 0))
          break;
      }
    }
    if (v9 >= 0xF)
      return 0;
  }
  time = get_time(v11, 0);
  clip = get_clip(v11);
  return time <= (get_length(clip) + -1.0);
}

// 0x133af90
void _StopBGM_Core(SoundManager *this, s32 id, f32 fadeTime) {
  u64 v7;
  struct SoundManager__ChannelWork_array *channelBgmArray;
  u64 v9;
  struct UnityEngine_AudioSource_array *sourceBgmArray;
  UnityEngine_AudioSource_o *v13;
  Il2CppObject *nowPlayBgmName;
  f32 time;
  System_Collections_IEnumerator_o *v22;
  struct SoundManager__ChannelWork_array *v23;
  struct SoundManager__ChannelWork_array *v25;
  s32 Key_MidiId;
  struct SoundManager_StaticFields **p_static_fields;
  struct SoundManager__ChannelWork_array *v31;
  struct SoundManager__ChannelWork_array *v33;

  v7 = 0;
  do
  {
    while (1)
    {
      channelBgmArray = this->_channelBgmArray;
      v9 = v7;
      if (id == -1 || channelBgmArray->m_Items[v7]->Key_MidiId == id)
        break;
      v7 = 1;
      if (v9)
        return;
    }
    sourceBgmArray = this->_sourceBgmArray;
    v13 = sourceBgmArray->m_Items[v7];
    if (get_isPlaying(v13, 0))
    {
      _StopFadeCoroutine(Instance, v9);
      time = get_time(v13, 0);
      if (Animator___ContainsKey(this->_poolBgm, nowPlayBgmName))
      {
        *&object___get_Item(this->_poolBgm, nowPlayBgmName)[3].monitor = time;
      }
      v22 = StopBGM_FadeOut(v13, fadeTime);
      _AddFadeCoroutineListAndStart(Instance, v9, v22);
      v23 = this->_channelBgmArray;
      v23->m_Items[v9]->status = 2;
    }
    v25 = this->_channelBgmArray;
    Key_MidiId = v25->m_Items[v9]->Key_MidiId;
    if (Key_MidiId == nowPlayBgmMidiId)
    {
      nowPlayBgmName = "";
      (*p_static_fields)->nowPlayBgmMidiId = 0;
    }
    v31 = this->_channelBgmArray;
    v31->m_Items[v9]->Key_DefineName = "";
    v33 = this->_channelBgmArray;
    v33->m_Items[v9]->Key_MidiId = 0;
    v7 = 1;
  }
  while (!v9);
}

// 0x13381c0
void _StopSE_Core(SoundManager *this, s32 id) {
  s64 i;
  struct UnityEngine_AudioSource_array *sourceSeArray;
  UnityEngine_AudioSource_o *v8;
  System_Collections_IEnumerator_o *v10;
  UnityEngine_MonoBehaviour_o **static_fields;
  UnityEngine_MonoBehaviour_o *v12;
  UnityEngine_Coroutine_o *klass;
  struct SoundManager__ChannelWork_array *v14;
  struct SoundManager__ChannelWork_array *v16;
  struct SoundManager__ChannelWork_array *channelSeArray;
  u64 v19;

  for (i = 4; i != 20; ++i)
  {
    while (1)
    {
      channelSeArray = this->_channelSeArray;
      v19 = i - 4;
      if (id == -1 || *(*(&channelSeArray->obj.klass + i) + 24LL) == id)
        break;
      if (++i == 20)
        return;
    }
    sourceSeArray = this->_sourceSeArray;
    v8 = *(&sourceSeArray->obj.klass + i);
    if (!get_isPlaying(v8, 0))
      goto LABEL_16;
    if (id == 5701728)
    {
      v10 = StopSE_FadeOut(v8, 0.15);
      v12 = *static_fields;
      klass = (*static_fields)[2].klass;
      if (klass)
      {
        StopCoroutine_27344864(*static_fields, klass);
        v12[2].klass = 0;
      }
      v12[2].klass = StartCoroutine_27343696(v12, v10);
LABEL_16:
      v14 = this->_channelSeArray;
      if (v19 >= LODWORD(v14->max_length))
        goto LABEL_17;
      goto LABEL_18;
    }
    Stop(v8);
    v14 = this->_channelSeArray;
    if (v19 >= LODWORD(v14->max_length))
    {
LABEL_17:
    }
LABEL_18:
    *(*(&v14->obj.klass + i) + 16LL) = "";
    v16 = this->_channelSeArray;
    *(*(&v16->obj.klass + i) + 24LL) = 0;
  }
}

// 0x133cd10
void _StopVoice(SoundManager *this) {
  UnityEngine_MonoBehaviour_o **static_fields;
  UnityEngine_Coroutine_o *monitor;
  struct UnityEngine_AudioSource_array *sourceVoiceArray;
  UnityEngine_AudioSource_o *v7;
  System_Collections_IEnumerator_o *v8;

  monitor = (*static_fields)[1].monitor;
  if (monitor)
    StopCoroutine_27344864(*static_fields, monitor);
  sourceVoiceArray = this->_sourceVoiceArray;
  if (SLODWORD(sourceVoiceArray->max_length) >= 1)
  {
    v7 = sourceVoiceArray->m_Items[0];
    v8 = StopVOICE_FadeOut(v7, 0.1);
    StartCoroutine_27343696(Instance, v8);
  }
  HalfBgm_Voice(this, 0);
  nowVoicePlaying = 0;
}

// 0x133e8d0
s32 p2sdAdpcmStreamPlay(char *fname, s32 vol) {
  return 0;
}

// 0x133e8c0
s32 p2sdAdpcmStreamStatus(void) {
  return 0;
}

// 0x133e8e0
void p2sdAdpcmStreamStop(void) {
  ;
}

// 0x133dca0
void p2sdBGMStopAll(void) {
LABEL_7:
  _StopBGM_Core(Instance, -1, 0.1);
}

// 0x133dd60
void p2sdBGMVolHalfDown(void) {
  struct SoundManager_o *Instance;
  struct UnityEngine_AudioSource_array *sourceBgmArray;
  UnityEngine_AudioSource_o *v6;

  sourceBgmArray = Instance->_sourceBgmArray;
  v6 = sourceBgmArray->m_Items[0];
  SetHalf(v6, 1);
}

// 0x133de40
void p2sdBGMVolHalfUp(void) {
  struct SoundManager_o *Instance;
  struct UnityEngine_AudioSource_array *sourceBgmArray;
  UnityEngine_AudioSource_o *v6;

  sourceBgmArray = Instance->_sourceBgmArray;
  v6 = sourceBgmArray->m_Items[0];
  SetHalf(v6, 0);
}

// 0x133df20
void p2sdBGMVolume(s32 vol) {
  ;
}

// 0x133e380
void p2sdContinue(s32 MidiNo) {
  s32 v3;

  else
  {
    v3 = MidiNo;
  }
  ContinueBGM_20162336(v3);
}

// 0x133e400
void p2sdContinue_20177920(char *define_name) {
  System_String_o *v3;

  else
  {
    v3 = define_name;
  }
  ContinueBGM(v3);
}

// 0x133bcf0
s32 p2sdDistanceVolume(SoundManager *this, s32 dis, s32 lim) {
  s32 v4;
  s32 v5;
  s32 v6;

  if (lim <= 3)
    v4 = 3;
  else
    v4 = lim;
  v5 = 10 * (10 - dis + 10 * v4) / v4;
  v6 = v5 & ~(v5 >> 31);
  if (v6 >= 100)
    return 100;
  else
    return v6;
}

// 0x133e080
void p2sdFadeIn(s32 MidiNo) {
  FadeinBGM_20161776(MidiNo, 1.0);
}

// 0x133e160
void p2sdFadeIn2(s32 MidiNo) {
  FadeinBGM_20161776(MidiNo, 1.0);
}

// 0x133e1d0
void p2sdFadeIn2_20177360(char *define_name) {
  FadeinBGM(define_name, 1.0);
}

// 0x133e0f0
void p2sdFadeIn_20177136(char *define_name) {
  FadeinBGM(define_name, 1.0);
}

// 0x133e240
void p2sdFadeOut(s32 MidiNo) {
LABEL_7:
  _StopBGM_Core(Instance, MidiNo, 2.0);
}

// 0x133e310
void p2sdFadeOut_20177680(char *define_name) {
  FadeoutBGM(define_name, 2.0);
}

// 0x133d090
s32 p2sdIOPerror(void) {
  return 0;
}

// 0x133c1b0
void p2sdIrxSetPos(SoundManager *this, s32 cx, s32 cy, s32 cz, s32 px, s32 py, s32 pz) {
  s32 _3DSE_stddeg;

  if (this->_3DSE_stdposx != px
    || this->_3DSE_stdposy != py
    || this->_3DSE_stdposz != pz
    || (_3DSE_stddeg = this->_3DSE_stddeg, _3DSE_stddeg != Atan(this, cx - px, pz - cz, *&cz)))
  {
    this->_3DSE_stdposx = px;
    this->_3DSE_stdposy = py;
    this->_3DSE_stdposz = pz;
    this->_3DSE_stddeg = Atan(this, cx - px, pz - cz, *&cz);
    this->_3DSE_se3dflag = 1;
  }
}

// 0x133d000
s32 p2sdLoadCheckMidi(s32 MidiNo) {
  return 1;
}

// 0x133d020
bool p2sdLoadCheckMidi_Fld(s32 MidiNo) {
  return _LoadCheckBGM(Instance, MidiNo);
}

// 0x133cf90
void p2sdLoadSMGFile(s32 MidiNo) {

}

// 0x133d010
void p2sdLoadSMGFileFname(char *aFilename) {
  ;
}

// 0x133df30
void p2sdMelodyTrans(s32 MidiNo) {
  s32 v5;
  f32 v6;
  s32 nowPlayBgmMidiId;

  if (MidiNo == 19070981)
  {
    _StopBGM_Core(Instance, nowPlayBgmMidiId, 1.0);
  }
  else if (MidiNo == -1)
  {
    v5 = nowPlayBgmMidiId + 1;
    v6 = 1.0;
    goto LABEL_9;
  }
  v6 = 1.0;
  v5 = MidiNo;
LABEL_9:
  FadeinBGM_20161776(v5, v6);
}

// 0x133d0a0
void p2sdOutputMode(s32 output_mode) {
  ;
}

// 0x133e480
void p2sdPause(s32 MidiNo) {
LABEL_7:
  _StopBGM_Core(Instance, MidiNo, 0.1);
}

// 0x133e550
void p2sdPause_20178256(char *define_name) {
  System_String_o *v3;

  else
  {
    v3 = define_name;
  }
  StopBGM(v3);
}

// 0x133dba0
void p2sdPlayBGM(s32 MidiNo) {
  s32 v3;

  else
  {
    v3 = MidiNo;
  }
  PlayBGM_20160448(v3);
}

// 0x133dc20
void p2sdPlayBGM_20175904(char *define_name) {
  System_String_o *v3;

  else
  {
    v3 = define_name;
  }
  PlayBGM(v3);
}

// 0x133d0b0
void p2sdPlaySE(s32 MidiNo) {
LABEL_7:
  _PlaySE_Ex(Instance, MidiNo, 1.0, 0.0);
}

// 0x133d180
void p2sdPlaySE_20173184(char *define_name) {
  System_String_o *v3;

  else
  {
    v3 = define_name;
  }
  PlaySE(v3);
}

// 0x133e8f0
void p2sdPlaySE_Dead(s32 devil_id) {
  u16 v3;
  u16 v4;
  System_String_array *v5;
  s64 *v7;
  s64 *v8;
  s64 *v10;
  s64 *v15;
  s64 *v16;
  System_String_o *v19;
  s64 *v21;
  System_String_o *v22;
  s32 v25;

  v25 = 0;
  v3 = Get(devil_id, 0);
  v25 = v3;
  v4 = v3;
  v5 = NewSpecific(string, 5u);
  v5->m_Items[0] = "D";
  v7 = sub_232A70(&v25, "000");
  v8 = v7;
  v5->m_Items[1] = v8;
  v5->m_Items[2] = "_MSE";
  if (v4 <= 0xFFu)
    v10 = &"X2";
  else
    v10 = &"X3";
  v15 = sub_232A70(&v25, *v10);
  v16 = v15;
  v5->m_Items[3] = v16;
  v5->m_Items[4] = "_23";
  v19 = Concat_5271600(v5);
  if (v25 == 192)
  {
    if (evtBitCheck(3712))
      v21 = &"D192M_MSEC0_23";
    else
      v21 = &"D192R_MSEC0_23";
    v22 = *v21;
  }
  else
  {
    v22 = v19;
  }
  PlaySE(v22);
}

// 0x133ecc0
void p2sdPlaySE_Fld(s32 MidiNo) {
  s32 fieldID;
  SoundManager_o *Instance;
  f32 v8;
  s32 v9;
  s32 Id_1916848;

  fieldID = fldGb->fieldID;
  if (fieldID == 35 && (MidiNo == 55 || MidiNo == 36))
    MidiNo |= 0x100u;
  if ((MidiNo > 0x39u || ((1LL << MidiNo) & 0x3802EDF00000000LL) == 0) && MidiNo != 311 && MidiNo != 292)
  {
    Id_1916848 = FindId_1916848(1, MidiNo);
LABEL_31:
    if ((byte_3F593DE & 1) != 0)
      goto LABEL_33;
    goto LABEL_32;
  }
  if (MidiNo != 34 || fieldID > 9)
  {
    Id_1916848 = MidiNo | 0x400000;
    goto LABEL_31;
  }
  v8 = 1.0;
  v9 = 4194368;
LABEL_26:
  _PlaySE_Ex(Instance, v9, v8, 0.0);
}

// 0x133d200
void p2sdPlaySE_Pan(s32 MidiNo, s32 pan) {
  f32 v6;
  f32 v7;

  v6 = pan - Instance->_3DSE_PS2DPAN_CENTER;
  v7 = v6 * 0.015625;
  _PlaySE_Ex(Instance, MidiNo, 1.0, v7);
}

// 0x133d2f0
void p2sdPlaySE_Pan_20173552(char *define_name, s32 pan) {
  s32 Id;

  Id = FindId(1, define_name);
  p2sdPlaySE_Pan(Id, pan);
}

// 0x133d3a0
void p2sdPlaySE_Vol(s32 MidiNo, s32 volume) {
  _PlaySE_Ex(Instance, MidiNo, volume * 0.0078125, 0.0);
}

// 0x133d480
void p2sdPlaySE_Vol_20173952(char *define_name, s32 volume) {
  s32 Id;

  Id = FindId(1, define_name);
  p2sdPlaySE_Vol(Id, volume);
}

// 0x133f010
void p2sdPlaySE_Vol_Fld(s32 MidiNo, s32 volume) {
  s32 v6;

  if (fldGb->fieldID == 35 && (MidiNo == 55 || MidiNo == 36))
    MidiNo |= 0x100u;
  if (MidiNo <= 0x39u && ((1LL << MidiNo) & 0x3802EDF00000000LL) != 0 || MidiNo == 311 || MidiNo == 292)
  {
    v6 = MidiNo | 0x400000;
  }
  else
  {
    v6 = MidiNo;
  }
  p2sdPlaySE_Vol(v6, volume);
}

// 0x133d530
void p2sdPlaySe3DEx(s32 MidiNo, f32 posx, f32 posy, f32 posz, s32 limit) {
  s32 Id_1916848;
  s32 v15;
  s32 v17;
  struct SoundManager__ChannelWork_array *channelSeArray;
  struct SoundManager__ChannelWork_array *v21;
  struct SoundManager__ChannelWork_array *v23;
  struct SoundManager__ChannelWork_array *v25;
  struct SoundManager__ChannelWork_array *v27;
  struct SoundManager__ChannelWork_array *v29;
  struct SoundManager__ChannelWork_array *v31;
  struct SoundManager__ChannelWork_array *v33;
  struct SoundManager__ChannelWork_array *v36;

  Id_1916848 = FindId_1916848(1, MidiNo);
LABEL_10:
  v15 = _PlaySE_Ex(Instance, Id_1916848, 0.0, 0.0);
  if (v15 != -1)
  {
    v17 = v15;
    channelSeArray = Instance->_channelSeArray;
    channelSeArray->m_Items[v17]->se3d = 1;
    v21 = Instance->_channelSeArray;
    v21->m_Items[v17]->posx = (posx * 0.1);
    v23 = Instance->_channelSeArray;
    v23->m_Items[v17]->posy = (posy * 0.1);
    v25 = Instance->_channelSeArray;
    v25->m_Items[v17]->posz = (posz * 0.1);
    v27 = Instance->_channelSeArray;
    v27->m_Items[v17]->lim = limit;
    v29 = Instance->_channelSeArray;
    v29->m_Items[v17]->ps2_vol = 0;
    v31 = Instance->_channelSeArray;
    v31->m_Items[v17]->ps2_pan = 0;
    v33 = Instance->_channelSeArray;
    v33->m_Items[v17]->pan_block = 0;
    if ((Id_1916848 - 5701712) <= 2)
    {
      v36 = Instance->_channelSeArray;
      v36->m_Items[v17]->pan_block = 1;
    }
    Instance->_3DSE_se3dflag = 1;
  }
}

// 0x133d900
void p2sdPlaySe3DEx_20175104(char *define_name, f32 posx, f32 posy, f32 posz, s32 limit) {
  s32 Id;

  Id = FindId(1, define_name);
  p2sdPlaySe3DEx(Id, posx, posy, posz, limit);
}

// 0x133bd30
void p2sdSet3DPan(SoundManager *this, s32 ch) {
  struct SoundManager__ChannelWork_array *channelSeArray;
  s64 v7;
  struct SoundManager__ChannelWork_array *v9;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  bool v18;
  s32 v20;
  s32 v21;
  s32 v22;
  bool v23;
  s32 v24;
  s32 v25;
  s64 v26;
  s32 v27;
  u64 v28;
  s64 v29;
  s32 _3DSE_PS2DPAN_CENTER;
  s64 v31;
  s32 v32;
  s32 v33;
  s32 v34;
  s32 v35;
  struct SoundManager__ChannelWork_array *v36;
  s32 lim;
  s32 v39;
  s32 v40;
  struct SoundManager__ChannelWork_array *v41;
  struct SoundManager__ChannelWork_array *v43;
  struct UnityEngine_AudioSource_array *sourceSeArray;
  UnityEngine_AudioSource_o *v47;
  struct SoundManager__ChannelWork_array *v48;
  f32 v50;

  channelSeArray = this->_channelSeArray;
  v7 = ch;
  if (channelSeArray->m_Items[ch]->se3d)
  {
    v9 = this->_channelSeArray;
    v11 = v9->m_Items[ch]->posx - this->_3DSE_stdposx;
    v12 = this->_channelSeArray->m_Items[ch]->posz - this->_3DSE_stdposz;
    v13 = this->_channelSeArray->m_Items[ch]->posy - this->_3DSE_stdposy;
    v14 = v11 * v11 + v12 * v12 + v13 * v13;
    if (v14)
    {
      v15 = 1;
      do
      {
        v16 = (v14 / v15 + v15) / 2;
        v17 = v15 + 1;
        v18 = v16 == v15 - 1 || v16 == v15;
        v15 = (v14 / v15 + v15) / 2;
      }
      while (!v18 && v16 != v17);
    }
    else
    {
      v16 = -1;
    }
    v20 = (Atan(this, -v11, v12) - this->_3DSE_stddeg) % 360;
    v21 = v20 + 360;
    if (v20 > -181)
      v21 = v20;
    if (v20 >= 181)
      v22 = v20 - 360;
    else
      v22 = v21;
    v23 = v22 < 0;
    if (v22 < 0)
      v22 = -v22;
    if (v23)
      v24 = -1;
    else
      v24 = 1;
    if (v22 <= 44)
    {
      _3DSE_PS2DPAN_CENTER = this->_3DSE_PS2DPAN_CENTER;
      v35 = 100;
      v34 = _3DSE_PS2DPAN_CENTER - 70 * v24 * v22 / 100;
      if (v16 >= 11)
      {
LABEL_38:
        v36 = this->_channelSeArray;
        lim = v36->m_Items[v7]->lim;
        if (lim <= 3)
          lim = 3;
        v39 = (10 * (10 - v16 + 10 * lim) / lim) & ~((10 * (10 - v16 + 10 * lim) / lim) >> 31);
        if (v39 >= 100)
          v39 = 100;
        v35 = v39 * v35 / 100;
LABEL_47:
        if (127 * v35 > 12699)
        {
          v40 = 127;
          v41 = this->_channelSeArray;
          if (LODWORD(v41->max_length) > ch)
          {
LABEL_52:
            v41->m_Items[v7]->ps2_vol = v40;
            v43 = this->_channelSeArray;
            v43->m_Items[v7]->ps2_pan = v34;
            sourceSeArray = this->_sourceSeArray;
            v47 = sourceSeArray->m_Items[v7];
            if (get_isPlaying(v47, 0))
            {
              set_volume(v47, v40 * 0.0078125);
              v48 = this->_channelSeArray;
              if (v48->m_Items[v7]->pan_block)
                v50 = 0.0;
              else
                v50 = (v34 - this->_3DSE_PS2DPAN_CENTER) * 0.015625;
              set_panStereo(v47, v50);
            }
            return;
          }
        }
        else
        {
          v40 = 127 * v35 / 100;
          v41 = this->_channelSeArray;
          if (LODWORD(v41->max_length) > ch)
            goto LABEL_52;
        }
      }
    }
    else
    {
      v25 = 70 * v24 * (180 - v22);
      v26 = 96207267450LL * v24 * v22;
      v27 = v22 - 90;
      if (v22 - 90 < 0)
        v27 = v22 - 87;
      v28 = v26 >> 63;
      v29 = 1374389535LL * v25;
      _3DSE_PS2DPAN_CENTER = this->_3DSE_PS2DPAN_CENTER;
      v31 = v26 >> 37;
      v32 = 75 - (v27 >> 2);
      v33 = _3DSE_PS2DPAN_CENTER - ((v29 >> 37) + (v29 >> 63));
      if (v22 <= 90)
        v34 = _3DSE_PS2DPAN_CENTER - (v31 + v28);
      else
        v34 = v33;
      if (v22 <= 90)
        v35 = 100 - ((v22 - 45) >> 1);
      else
        v35 = v32;
      if (v16 >= 11)
        goto LABEL_38;
    }
    v34 = _3DSE_PS2DPAN_CENTER + ((v34 - _3DSE_PS2DPAN_CENTER) >> 1);
    goto LABEL_47;
  }
}

// 0x133d9d0
void p2sdSetStandPos(f32 Cposx, f32 Cposy, f32 Cposz, f32 Pposx, f32 Pposy, f32 Pposz) {
  struct SoundManager_o *Instance;
  s32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  s32 v21;
  s32 v22;
  s32 v23;
  s32 v24;
  s32 _3DSE_stddeg;
  struct SoundManager_o *v26;
  u64 i;
  struct UnityEngine_AudioSource_array *sourceSeArray;

  if (Instance)
  {
    v16 = (Pposx * 0.1);
    v17 = Cposx * 0.1;
    v18 = Cposz * 0.1;
    v19 = Pposy * 0.1;
    v20 = Pposz * 0.1;
    v21 = v19;
    v22 = v20;
    v23 = v17;
    v24 = v18;
    if (Instance->_3DSE_stdposx != v16
      || Instance->_3DSE_stdposy != v21
      || Instance->_3DSE_stdposz != v22
      || (_3DSE_stddeg = Instance->_3DSE_stddeg,
          _3DSE_stddeg != Atan(Instance, v23 - v16, v22 - v24)))
    {
      Instance->_3DSE_stdposx = v16;
      Instance->_3DSE_stdposy = v21;
      Instance->_3DSE_stdposz = v22;
      Instance->_3DSE_stddeg = Atan(Instance, v23 - v16, v22 - v24);
      Instance->_3DSE_se3dflag = 1;
    }
    v26 = Instance;
    for (i = 0; i != 16; ++i)
    {
      sourceSeArray = v26->_sourceSeArray;
      if (get_isPlaying(sourceSeArray->m_Items[i], 0) && v26->_3DSE_se3dflag)
        p2sdSet3DPan(v26, i);
    }
    v26->_3DSE_se3dflag = 0;
  }
}

// 0x133e5d0
void p2sdSndStop(s32 MidiNo) {
LABEL_7:
  _StopSE_Core(Instance, MidiNo);
  _StopBGM_Core(Instance, MidiNo, 0.1);
}

// 0x133e760
void p2sdSndStopAll(void) {
LABEL_7:
  _StopSE_Core(Instance, -1);
  _StopBGM_Core(Instance, -1, 0.1);
  _StopVoice(Instance);
}

// 0x133e6f0
void p2sdSndStop_20178672(char *define_name) {
  StopSE(define_name);
  StopBGM(define_name);
}

// 0x133ef20
void p2sdSndStop_Fld(s32 MidiNo) {
  s32 v3;
  s32 Id_1916848;

  if (MidiNo <= 0x39u && ((1LL << MidiNo) & 0x3802EDF00000000LL) != 0)
  {
    v3 = MidiNo | 0x400000;
  }
  else
  {
    Id_1916848 = FindId_1916848(1, MidiNo);
    v3 = Id_1916848;
  }
  p2sdSndStop(v3);
}

// 0x133ec40
bool p2sdStatusSE_Dead(void) {
  return _StatusSE_NameHead(Instance, "D", "_23");
}

// 0x133c260
void sdfSoundDriverATick(SoundManager *this) {
  u64 i;
  struct UnityEngine_AudioSource_array *sourceSeArray;

  for (i = 0; i != 16; ++i)
  {
    sourceSeArray = this->_sourceSeArray;
    if (get_isPlaying(sourceSeArray->m_Items[i], 0) && this->_3DSE_se3dflag)
      p2sdSet3DPan(this, i);
  }
  this->_3DSE_se3dflag = 0;
}
