#include "types.h"

typedef struct InputUtil_ControllerType InputUtil_ControllerType;
typedef struct InputUtil_KeyTbl InputUtil_KeyTbl;
typedef struct InputUtil_Pad InputUtil_Pad;

struct InputUtil_KeyTbl {
    s64 button;
    u64 retkey;
};

struct InputUtil_ControllerType {
    s32 value__;
};

struct InputUtil_Pad {
    u64 _buttons;
    u16 _analogLX;
    u16 _analogLY;
    u16 _analogRX;
    u16 _analogRY;
};

static f32 StickValBorder;
static u64 currentKey[4];
static u64 oldKey[4];
static u64 oneShotKey[4];
static u64 repeatKey[4];
static u64 repeatKeyFirst[4];
static f32 defFirstDelayTime;
static f32 defIntervalTime;
static f32 nextIntervalTime[4];
static f32 nextRepeatTime[4];
static bool flg_sleep_fade;
static s32 noinput_frame_cnt;
static s32 _npad_count;
static char *joyname;
static f32 *VibLevel[4];
static void pad_state;
static void *npad_id_list[5];
static void npad_id[UNKNOWN_ARRAY_SIZE];
static void npad_style[UNKNOWN_ARRAY_SIZE];
static void *cnt_buttons;
static void *trg_buttons;
static bool b_use_handheld;
static bool b_handheld;
static f32 **AnalogStickLRval[8];
static InputUtil_KeyTbl *switch_key_checktable[3];
static s32 dualpattern[4];

bool GetPadKey(s32 controller, s32 assignCode);
bool IsDualPattern(s32 attr);
void ShowControllerSupport(void);
void SwitchExchangeID(s32 index);
void SwitchGetAnalogData(void *stat, s32 style, u64 *key);
void SwitchRefleshController(void);
u64 Switch_Assign_Retkey(s32 no, u64 retkey);
void Switch_Pad_Update(void);
void reset_keydata(void);
void switch_pad_init(void);

// 0x11551c0
void CheckNoInput(u64 *ret) {
}

// 0x1152ef0
s32 GetControllerNum(void) {
  return _npad_count;
}

// 0x1152690
s32 GetControllerType(bool test_mode, s32 type) {
  s32 v3;
  struct nn_hid_NpadId_array *npad_id_list;
  s32 StyleSet;

  v3 = type;
  if (test_mode)
    return v3;
  StyleSet = GetStyleSet(npad_id_list->m_Items[1]);
  if (StyleSet == 8)
    return 1;
  return 2 * (StyleSet == 16);
}

// 0x11524c0
u64 GetCurrentKey(s32 kind) {
  struct System_UInt64_array *currentKey;

  return currentKey->m_Items[kind];
}

// 0x1152840
bool GetKey(s32 controller, s32 keyID, s32 assign_idx) {
  InputAssign_o *Instance;
  struct InputAssign_AssignData_array *assignData;
  InputAssign_o *v12;
  struct InputAssign_AssignCode_array *data;
  struct InputAssign_AssignData_array *v16;
  s64 v19;
  s32 keyCode;
  struct InputAssign_AssignkeyInfo_array *assignkeyInfo;

  Instance = get_Instance();
  assignData = Instance->_assignData;
  v12 = Instance;
  data = assignData->m_Items[controller]->data;
  if (assign_idx != -1)
  {
    v16 = Instance->_assignData;
    data = v16->m_Items[assign_idx]->data;
  }
  v19 = data->m_Items[keyID];
  else if (GetPadKey(controller, v19))
  {
    return 1;
  }
  switch (controller)
  {
    case 0:
      keyCode = v19 + 348;
      break;
    case 1:
      keyCode = v19 + 368;
      break;
    case 2:
      keyCode = v19 + 388;
      break;
    case 3:
      keyCode = v19 + 408;
      break;
    default:
      assignkeyInfo = v12->_assignkeyInfo;
      keyCode = assignkeyInfo->m_Items[v19]->keyCode;
      break;
  }
  return GetKey(keyCode, 0);
}

// 0x1152420
u64 GetOneShotKey(s32 kind) {
  struct System_UInt64_array *oneShotKey;

  return oneShotKey->m_Items[kind];
}

// 0x1152a50
bool GetPadKey(s32 controller, s32 assignCode) {
    return 0;
}

// 0x1152560
u64 GetRepeatKey(bool oneShot, s32 kind) {
  InputUtil_c *v5;
  struct InputUtil_StaticFields *static_fields;
  struct System_UInt64_array *oneShotKey;
  s64 v9;
  struct System_UInt64_array *repeatKey;
  struct System_UInt64_array *v13;

  if (oneShot)
  {
    static_fields = v5->static_fields;
    oneShotKey = static_fields->oneShotKey;
    v9 = oneShotKey + 8 * kind;
    repeatKey = static_fields->repeatKey;
    return repeatKey->m_Items[kind] | *(v9 + 32);
  }
  else
  {
    v13 = repeatKey;
    return v13->m_Items[kind];
  }
}

// 0x11508f0
void Init(void) {
    reset_keydata();
    switch_pad_init();
}

// 0x11551b0
bool IsDecideCircle(void) {
  return 1;
}

// 0x1153090
bool IsDualPattern(s32 attr) {
    return 0;
}

// 0x1155fd0
bool LRInputCheck(void) {
    SwitchExchangeID(0);
    return 0;
}

// 0x1155f50
void LRInputCheckEnd(void) {
  Log(StringLiteral_5018, 0);
  StopLrAssignmentMode();
}

// 0x1155ed0
void LRInputCheckStart(void) {
  Log(StringLiteral_5017, 0);
  StartLrAssignmentMode();
}

// 0x1155390
void SetSleepFadeMode(bool set) {
  flg_sleep_fade = set;
}

// 0x1155a60
void SetVib(s32 index, s32 value0, s32 value1) {
}

// 0x1155400
void SetVib0(s32 index, s32 value0) {
}

// 0x1155730
void SetVib1(s32 index, s32 value1) {
}

// 0x1152f60
void ShowControllerSupport(void) {
}

// 0x1153e40
void SwitchExchangeID(s32 index) {
}

// 0x11537e0
void SwitchGetAnalogData(void *stat, s32 style, u64 *key) {
}

// 0x1154f00
s32 SwitchGetControllerLR(s32 index) {
  struct nn_hid_NpadId_array *npad_id_list;
  struct nn_hid_NpadId_array *v8;
  s32 StyleSet;

  if (GetAssignment(npad_id_list->m_Items[index]) != 1)
    return -1;
  v8 = npad_id_list;
  StyleSet = GetStyleSet(v8->m_Items[index]);
  if (StyleSet == 8)
    return 1;
  if (StyleSet == 16)
    return 0;
  return -1;
}

// 0x1154e60
s32 SwitchGetControllerMode(s32 index) {
  struct nn_hid_NpadId_array *npad_id_list;

  return GetAssignment(npad_id_list->m_Items[index]);
}

// 0x1155040
u64 SwitchGetCurrentKey(s32 index) {
  if (!ulong___ContainsKey(cnt_buttons, index))
    return 0;
  return ulong___get_Item(cnt_buttons, index);
}

// 0x1155110
s32 SwitchGetStyle(s32 index) {
  struct nn_hid_NpadStyle_array *npad_style;

  return npad_style->m_Items[index];
}

// 0x1153d10
s32 SwitchIsJoycon(s32 no) {
  struct nn_hid_NpadStyle_array *npad_style;

  return npad_style->m_Items[no] == 4 || (npad_style->m_Items[no] - 1) < 2;
}

// 0x1154570
void SwitchMergeController(s32 index1, s32 index2) {
}

// 0x1153190
void SwitchRefleshController(void) {
    IsDualPattern(0);
}

// 0x1154db0
void SwitchSeparateController(s32 index, bool lr) {
  struct nn_hid_NpadId_array *npad_id_list;

  SetAssignmentModeSingle_27617840(npad_id_list->m_Items[index], !lr);
}

// 0x1153dd0
void SwitchSetUseHandheld(bool sw) {
  LOBYTE(v3[2].klass->rgctx_data) = sw;
  reset_keydata();
}

// 0x1153aa0
u64 Switch_Assign_Retkey(s32 no, u64 retkey) {
  u64 v3;
  s32 v5;
  InputAssign_o *Instance;
  u64 v8;
  struct InputAssign_AssignData_array *assignData;
  struct InputAssign_AssignCode_array *data;

  v3 = retkey;
  if (v3 > 0x1000)
  {
    if (v3 > 0x8000)
    {
      if (v3 > 0x20000)
      {
        if (v3 == 0x1000000)
        {
          v5 = 8;
        }
        if (v3 == 0x2000000)
        {
          v5 = 9;
        }
      }
      else
      {
        if (v3 == 0x10000)
        {
          v5 = 10;
        }
        if (v3 == 0x20000)
        {
          v5 = 11;
        }
      }
    }
    else
    {
      switch (v3)
      {
        case 0x2000uLL:
          v5 = 12;
        case 0x4000uLL:
          v5 = 7;
        case 0x8000uLL:
          v5 = 13;
      }
    }
    return v3;
  }
  if (v3 > 0x100)
  {
    if (v3 > 0x400)
    {
      if (v3 == 2048)
      {
        v5 = 5;
      }
      if (v3 == 4096)
      {
        v5 = 6;
      }
    }
    else
    {
      if (v3 == 512)
      {
        v5 = 3;
      }
      if (v3 == 1024)
      {
        v5 = 4;
      }
    }
    return v3;
  }
  if (v3 - 1 <= 3)
  {
    v5 = 22;
    switch (v3)
    {
      case 1uLL:
      case 2uLL:
        v5 = 23;
      case 3uLL:
        return v3;
      case 4uLL:
        v5 = 24;
    }
  }
  if (v3 == 8)
  {
    v5 = 25;
  }
  if (v3 != 256)
    return v3;
  v5 = 2;
  Instance = get_Instance();
  v8 = 0;
  while (1)
  {
    assignData = Instance->_assignData;
    data = assignData->m_Items[no]->data;
    if (data->m_Items[v8] == v5)
      break;
    if (v8++ > 0x10)
      return v3 & 0x1FFA0F0;
  }
  if (v8 >= 0x10 || ((0x87FFu >> v8) & 1) == 0)
    return v3 & 0x1FFA0F0;
  return qword_33CC588[v8];
}

// 0x1150f50
void Switch_Pad_Update(void) {
    IsDualPattern(0);
    ShowControllerSupport();
    SwitchRefleshController();
    SwitchGetAnalogData(0, 0, 0);
    Switch_Assign_Retkey(0, 0);
}

// 0x1150ee0
void Update(void) {
    Switch_Pad_Update();
}

// 0x1152760
void resetRepeat(s32 index, f32 delayTime) {
  InputUtil_c *v5;
  struct InputUtil_StaticFields *static_fields;
  struct System_Single_array *nextRepeatTime;

  if (delayTime >= 0.0)
  {
    static_fields = v5->static_fields;
  }
  else
  {
    static_fields = v5->static_fields;
    delayTime = static_fields->defFirstDelayTime;
  }
  nextRepeatTime = static_fields->nextRepeatTime;
  nextRepeatTime->m_Items[index] = -delayTime;
}

// 0x1150960
void reset_keydata(void) {
  u64 i;
  struct System_UInt64_array *currentKey;
  struct System_UInt64_array *oldKey;
  struct System_UInt64_array *oneShotKey;
  struct System_UInt64_array *repeatKey;
  struct System_UInt64_array *repeatKeyFirst;
  struct InputUtil_StaticFields *static_fields;
  struct System_Single_array *nextIntervalTime;
  f32 defFirstDelayTime;
  f32 *v18;

  for (i = 0; i != 4; ++i)
  {
    currentKey->m_Items[i] = 0;
    oldKey->m_Items[i] = 0;
    oneShotKey->m_Items[i] = 0;
    repeatKey->m_Items[i] = 0;
    repeatKeyFirst->m_Items[i] = 0;
    static_fields = InputUtil->static_fields;
    nextIntervalTime = static_fields->nextIntervalTime;
    defFirstDelayTime = static_fields->defFirstDelayTime;
    v18 = (nextIntervalTime + 4 * i);
    v18[8] = defFirstDelayTime;
  }
}

// 0x1150b00
void switch_pad_init(void) {
  struct nn_hid_NpadId_array *v4;
  struct nn_hid_NpadStyle_array *v6;
  struct nn_hid_NpadId_array *npad_id_list;
  s32 StyleSet;
  s64 v14;
  u32 *AnalogStickLRval;
  u64 v16;
  s64 *v17;
  s64 *v19;
  struct System_Single_array_array_array *v22;
  s64 v24;
  s64 *v25;
  s64 *v27;
  struct System_Single_array_array_array *v32;
  s64 v34;
  s64 *v35;
  s64 *v36;

  Log(StringLiteral_5006, 0);
  Initialize(0);
  SetSupportedIdType_27612192(npad_id_list);
  SetSupportedStyleSet(7);
  SetHoldType(1);
  v4 = NewSpecific(
         nn_hid_NpadId,
         LODWORD(npad_id_list->max_length));
  npad_id = v4;
  v6 = NewSpecific(nn_hid_NpadStyle, LODWORD(npad_id_list->max_length));
  npad_style = v6;
  ulong___Clear(cnt_buttons);
  ulong___Clear(trg_buttons);
  b_use_handheld = 1;
  StyleSet = GetStyleSet(npad_id_list->m_Items[0]);
  b_handheld = StyleSet != 0;
  v14 = 4;
  while (1)
  {
    v16 = v14 - 4;
    v17 = NewSpecific(float__, 2u);
    v19 = v17;
    *&AnalogStickLRval[2 * v14] = v19;
    v22 = AnalogStickLRval;
    v24 = *(&v22->obj.klass + v14);
    v25 = NewSpecific(f32, 2u);
    v27 = v25;
    *(v24 + 32) = v27;
    v32 = AnalogStickLRval;
    v34 = *(&v32->obj.klass + v14);
    v35 = NewSpecific(f32, 2u);
    v36 = v35;
    *(v34 + 40) = v36;
    if (v14 == 11)
      break;
    ++v14;
  }
}
