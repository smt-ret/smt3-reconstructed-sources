#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct btlKutiManager btlKutiManager;
typedef struct evtKutiManager evtKutiManager;
typedef struct evtUnitHandle_t evtUnitHandle_t;

void *GetAnimator(void *obj);
bool IsSpeaking(void);
void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name);
void Log(char *fmt, void **parray);
void StopKuti(btlKutiManager *this);
void mdlMotionStopKutiForUnity(evtUnitHandle_t **h, s32 index, bool sw);
void mdlSmoothLoopMotionForUnity(evtUnitHandle_t **h, s32 layer, s32 motion, s32 before, s32 wait, bool btl);

// 0x10ea6b0
void Append(evtKutiManager *this, char *key, char *path, bool evt) {
    LoadFileObject(0, 0, 0);
    Log(0, 0);
}

// 0x10e9f40
void Awake(evtKutiManager *this) {
  PropertySheet___Clear(this->TimeLine);
  this->KutiSwitch = 0;
  this->MsgTime = 0.0;
  this->hUnit = 0;
  this->KutiName = 0;
}

// 0x10e9fb0
void Clear(evtKutiManager *this, bool sw) {
  if (sw)
    PropertySheet___Clear(this->TimeLine);
  this->KutiSwitch = 0;
  this->MsgTime = 0.0;
  this->hUnit = 0;
  this->KutiName = 0;
}

// 0x10eb570
bool Contains(evtKutiManager *this) {
  return !IsNullOrEmpty(this->KutiName)
      && HashSet_Text____get_Count(this->TimeLine)
      && Animator___ContainsKey(this->TimeLine, this->KutiName);
}

// 0x10eae00
void FixedUpdate(evtKutiManager *this) {
  evtUnitHandle_t_o *hUnit;
  f32 deltaTime;

  hUnit = this->hUnit;
  if (hUnit)
  {
    deltaTime = get_deltaTime();
    IsSpeaking(this, hUnit, deltaTime);
  }
}

// 0x10ea030
void Initialize(evtKutiManager *this, char *key, char *path, bool evt) {
    LoadFileObject(0, 0, 0);
    Log(0, 0);
}

// 0x10ead30
bool IsExists(evtKutiManager *this) {
  return HashSet_Text____get_Count(this->TimeLine) != 0;
}

// 0x10eae40
void IsSpeaking(evtKutiManager *this, evtUnitHandle_t *h, f32 time) {
    GetAnimator(0);
    mdlMotionStopKutiForUnity(0, 0, 0);
    Log(0, 0);
    mdlSmoothLoopMotionForUnity(0, 0, 0, 0, 0, 0);
    StopKuti(0);
}

// 0x10ead90
void OnDestroy(evtKutiManager *this) {
  PropertySheet___Clear(this->TimeLine);
  this->KutiSwitch = 0;
  this->MsgTime = 0.0;
  this->hUnit = 0;
  this->KutiName = 0;
}

// 0x10eb4e0
void SetKutiName(evtKutiManager *this, char *name) {
  this->KutiName = 0;
  if (Animator___ContainsKey(this->TimeLine, name))
  {
    this->KutiName = name;
    this->KutiSwitch = 0;
    this->MsgTime = 0.0;
    this->UpTime = get_realtimeSinceStartup();
  }
}

// 0x10eb720
void SetUnit(evtKutiManager *this, evtUnitHandle_t *h) {
  this->hUnit = h;
}

// 0x10eb600
void StopKuti(evtKutiManager *this) {
  System_Object_array *v4;
  struct evtUnitHandle_t_o *v6;
  evtUnitHandle_t_o **p_hUnit;
  struct evtUnitHandle_t_o *hUnit;
  struct System_Byte_array *ExFlags;
  u32 KutiGroup;
  s32 v12;

  v4 = Empty_string_();
  Log(StringLiteral_12255, v4, 0);
  hUnit = this->hUnit;
  p_hUnit = &this->hUnit;
  v6 = hUnit;
  p_hUnit[2] = 0;
  *(p_hUnit + 7) = 0;
  *(p_hUnit + 24) = 0;
  if (hUnit)
  {
    ExFlags = v6->ExFlags;
    KutiGroup = v6->KutiGroup;
    if ((ExFlags->m_Items[KutiGroup] & 0x20) == 0)
    {
      v12 = (*p_hUnit)->KutiGroup;
      mdlMotionStopKutiForUnity(p_hUnit, v12, 0);
    }
  }
  *p_hUnit = 0;
}
