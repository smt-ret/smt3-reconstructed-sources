#include "types.h"

typedef struct btlKutiManager btlKutiManager;
typedef struct btlKutiManager_TLTbl btlKutiManager_TLTbl;
typedef struct evtTexManager evtTexManager;

struct btlKutiManager_TLTbl {
    char *name;
    f32 *timeline;
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
  this->KutiSwitch = 0;
  this->MsgTime = 0.0;
  this->game_obj = 0;
  this->anim = 0;
  PropertySheet___Clear(this->TimeLine);
  else
  {
    DanteBattleVoiceClear();
  }
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
  UnityEngine_Object_o *anim;
  Il2CppObject *Item;
  s32 v7;
  f32 MsgTime;
  s32 v9;
  f32 v10;
  bool *p_KutiSwitch;
  s32 v12;
  bool v13;
  u64 *v14;
  System_String_o *v15;
  System_Object_array *v17;
  UnityEngine_Animator_o *v18;
  s64 *v19;
  System_Object_array *v20;
  s64 *v23;
  s64 *v24;
  s64 *v29;
  s64 *v30;
  System_String_o *v33;
  System_Object_array *v35;
  s32 v37;
  f32 v38;
  f32 v39;

  if (HashSet_Text____get_Count(this->TimeLine)
    && !IsNullOrEmpty(this->KutiName))
  {
    anim = this->anim;
    if (!op_Equality(anim, 0, 0))
    {
      Item = object___get_Item(this->TimeLine, this->KutiName);
      this->MsgTime = get_realtimeSinceStartup() - this->UpTime;
      if (_get_Count(Item) < 2)
      {
        p_KutiSwitch = &this->KutiSwitch;
        if (this->KutiSwitch)
        {
          v7 = 0;
          v13 = 0;
          goto LABEL_26;
        }
        v12 = 0;
        v13 = 0;
        v7 = 0;
      }
      else
      {
        v7 = 0;
        do
        {
          MsgTime = this->MsgTime;
          if (MsgTime >= _get_Item(
                            Item,
                            v7))
          {
            v10 = this->MsgTime;
            v9 = v7 + 1;
            if (v10 <= _get_Item(
                          Item,
                          v7 + 1))
              break;
          }
          else
          {
            v9 = v7 + 1;
          }
          v7 = v9;
        }
        while (v9 < _get_Count(Item)
                   - 1);
        p_KutiSwitch = &this->KutiSwitch;
        v12 = v7 & 1;
        v13 = v7 & 1;
        if (v12 != this->KutiSwitch)
          goto LABEL_21;
      }
      if (v7 != _get_Count(Item))
        return;
LABEL_21:
      if (v12)
      {
        v39 = this->MsgTime;
        v14 = sub_8D3950(f32, &v39);
        v15 = Concat("@@@@@ SPEAK ON ", v14);
        v17 = Empty_string_();
        Log(v15, v17, 0);
        v18 = this->anim;
        v19 = &"01_01";
        goto LABEL_52;
      }
LABEL_26:
      v20 = NewSpecific(object, 4u);
      v20->m_Items[0] = "SPEAK OFF @@@@@ ";
      v38 = this->MsgTime;
      v23 = sub_8D3950(f32, &v38);
      v24 = v23;
      v20->m_Items[1] = v24;
      v20->m_Items[2] = " : ";
      v37 = v7;
      v29 = sub_8D3950(s32, &v37);
      v30 = v29;
      v20->m_Items[3] = v30;
      v33 = Concat_5270224(v20);
      v35 = Empty_string_();
      Log(v33, v35, 0);
      if (v7 == _get_Count(Item))
      {
        StopKuti(this);
LABEL_53:
        *p_KutiSwitch = v13;
        return;
      }
      v18 = this->anim;
      v19 = &"01_00";
LABEL_52:
      Play(v18, *v19, 1, 0);
      goto LABEL_53;
    }
  }
}

// 0x1321980
void OnDestroy(btlKutiManager *this) {
  this->KutiSwitch = 0;
  this->MsgTime = 0.0;
  this->game_obj = 0;
  this->anim = 0;
  PropertySheet___Clear(this->TimeLine);
  else
  {
    DanteBattleVoiceClear();
  }
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
  Log("@@@@@ Stop Kuti @@@@@", v4, 0);
  this->KutiName = 0;
  this->MsgTime = 0.0;
  this->KutiSwitch = 0;
  anim = this->anim;
  if (op_Inequality(anim, 0, 0))
    Play(this->anim, "01_00", 1, 0);
}
