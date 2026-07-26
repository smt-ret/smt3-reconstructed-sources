#include "types.h"

typedef struct btlKutiManager btlKutiManager;
typedef struct btlKutiManager_TLTbl btlKutiManager_TLTbl;
typedef struct evtTexManager evtTexManager;

struct btlKutiManager_TLTbl {
    char *name;
    f32 timeline[UNKNOWN_ARRAY_SIZE];
};

void DanteBattleVoiceClear(void);
void Initialize(evtTexManager *this, char *key, char *path);
bool IsSpeaking(void);
void Log(char *fmt, void **parray);
void StopKuti(btlKutiManager *this);

// 0x13216d0
void Awake(btlKutiManager *this) {
  Initialize(this);
}

// 0x13218e0
void Clear(btlKutiManager *this) {
    DanteBattleVoiceClear();
}

// 0x1321fd0
bool Contains(btlKutiManager *this) {
  return !IsNullOrEmpty(this->KutiName)
      && HashSet_Text____get_Count(this->TimeLine)
      && Animator___ContainsKey(this->TimeLine, this->KutiName);
}

// 0x1321a20
void FixedUpdate(btlKutiManager *this) {
  UnityEngine_Object_o *game_obj;
  f32 deltaTime;

  game_obj = this->game_obj;
  if (!op_Equality(game_obj, 0, 0))
  {
    deltaTime = get_deltaTime();
    IsSpeaking(this, deltaTime);
  }
}

// 0x13216e0
void Initialize(btlKutiManager *this) {
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  struct UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  struct btlKutiManager_TLTbl_array *TimeLineTbl;
  il2cpp_array_size_t max_length;
  s64 v10;
  u64 v11;
  s64 v12;
  u64 *v13;
  struct btlKutiManager_TLTbl_array *v14;
  struct btlKutiManager_TLTbl_array *v16;

  this->KutiSwitch = 0;
  this->MsgTime = 0.0;
  this->game_obj = 0;
  this->anim = 0;
  PropertySheet___Clear(this->TimeLine);
  DanteBattleVoiceClear();
  transform = get_transform(this, 0);
  Child = GetChild(transform, 0);
  gameObject = get_gameObject(Child);
  this->game_obj = gameObject;
  Component_object = GetComponent_object_(gameObject);
  TimeLineTbl = this->TimeLineTbl;
  this->anim = Component_object;
  max_length = TimeLineTbl->max_length;
  if (max_length >= 1)
  {
    v10 = 0;
    v11 = 0;
    v12 = max_length;
    do
    {
      v13 = Allocate(System_Collections_Generic_List_float_);
      __ctor(v13);
      _Add(v13, 0.0);
      v14 = this->TimeLineTbl;
      _AddRange(v13, v14->m_Items[v10].timeline);
      v16 = this->TimeLineTbl;
      PropertySheet___Add(this->TimeLine, v16->m_Items[v10].name, v13);
      ++v11;
      ++v10;
    }
    while (v12 != v11);
  }
}

// 0x1321ab0
void IsSpeaking(btlKutiManager *this, f32 time) {
    Log(0, 0);
    StopKuti(0);
}

// 0x1321980
void OnDestroy(btlKutiManager *this) {
    DanteBattleVoiceClear();
}

// 0x1321f40
void SetKutiName(btlKutiManager *this, char *name) {
  this->KutiName = 0;
  if (Animator___ContainsKey(this->TimeLine, name))
  {
    this->KutiName = name;
    this->KutiSwitch = 0;
    this->MsgTime = 0.0;
    this->UpTime = get_realtimeSinceStartup();
  }
}

// 0x1322060
void StopKuti(btlKutiManager *this) {
  System_Object_array *v4;
  UnityEngine_Object_o *anim;

  v4 = Empty_string_();
  Log(StringLiteral_12255, v4, 0);
  this->KutiName = 0;
  this->MsgTime = 0.0;
  this->KutiSwitch = 0;
  anim = this->anim;
  if (op_Inequality(anim, 0, 0))
    Play(this->anim, StringLiteral_12256, 1, 0);
}
