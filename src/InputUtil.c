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
static void *npad_id;
static void *npad_style;
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
  u64 v5;
  s32 noinput_frame_cnt;

  else
  {
    v5 = *ret;
    if (flg_sleep_fade)
      goto LABEL_6;
  }
  if (v5)
  {
    noinput_frame_cnt = 0;
  }
  else
  {
    noinput_frame_cnt = noinput_frame_cnt + 1;
    if (noinput_frame_cnt >= 36000)
    {
      flg_sleep_fade = 1;
    }
  }
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
  s32 v6;
  f32 AxisRaw;
  f32 v9;
  u64 *v10;
  Il2CppObject *v11;
  s64 *v12;
  f32 v15;
  f32 v16;
  u64 *v17;
  Il2CppObject *v18;
  s64 *v19;
  f32 v21;
  struct System_String_o *v22;
  f32 v24;
  bool result;
  f32 v27;
  struct System_String_o *v28;
  f32 v30;
  u64 *v31;
  s64 *v32;
  u64 *v33;
  s64 *v34;
  System_String_o *v36;
  System_String_o *v39;
  s32 v41;

  get_Instance();
  if (controller > 3)
    return 0;
LABEL_6:
  v6 = controller + 1;
  switch (assignCode)
  {
    case 22:
      joyname = "VerticalKey";
      AxisRaw = GetAxisRaw(joyname, 0);
      v41 = v6;
      v9 = AxisRaw;
      v10 = sub_8D3950(s32, &v41);
      v11 = "DPad";
      v12 = &"_Vertical";
      goto LABEL_21;
    case 23:
      joyname = "VerticalKey";
      v15 = GetAxisRaw(joyname, 0);
      v41 = v6;
      v16 = v15;
      v17 = sub_8D3950(s32, &v41);
      v18 = "DPad";
      v19 = &"_Vertical";
      goto LABEL_28;
    case 24:
      joyname = "HorizontalKey";
      v21 = GetAxisRaw(joyname, 0);
      v41 = v6;
      v9 = v21;
      v10 = sub_8D3950(s32, &v41);
      v11 = "DPad";
      v12 = &"_Horizontal";
LABEL_21:
      v22 = Concat_5269984(v11, v10, *v12);
      joyname = v22;
      v24 = GetAxisRaw(joyname, 0);
      result = 1;
      if (v9 <= -1.0 || v24 <= -1.0)
        return result;
      return 0;
    case 25:
      joyname = "HorizontalKey";
      v27 = GetAxisRaw(joyname, 0);
      v41 = v6;
      v16 = v27;
      v17 = sub_8D3950(s32, &v41);
      v18 = "DPad";
      v19 = &"_Horizontal";
LABEL_28:
      v28 = Concat_5269984(v18, v17, *v19);
      joyname = v28;
      v30 = GetAxisRaw(joyname, 0);
      result = 1;
      if (v16 >= 1.0 || v30 >= 1.0)
        return result;
      return 0;
    case 26:
      v41 = v6;
      v31 = sub_8D3950(s32, &v41);
      v32 = &"Vertical";
      goto LABEL_34;
    case 27:
      v41 = v6;
      v33 = sub_8D3950(s32, &v41);
      v34 = &"Vertical";
      goto LABEL_40;
    case 28:
      v41 = v6;
      v31 = sub_8D3950(s32, &v41);
      v32 = &"Horizontal";
LABEL_34:
      v36 = Concat(*v32, v31);
      joyname = v36;
      if (GetAxisRaw(joyname, 0) <= -StickValBorder)
        goto LABEL_38;
      return 0;
    case 29:
      v41 = v6;
      v33 = sub_8D3950(s32, &v41);
      v34 = &"Horizontal";
LABEL_40:
      v39 = Concat(*v34, v33);
      joyname = v39;
      if (GetAxisRaw(joyname, 0) < StickValBorder)
        return 0;
LABEL_38:
      result = 1;
      break;
    default:
      return 0;
  }
  return result;
}

// 0x1152560
u64 GetRepeatKey(bool oneShot, s32 kind) {
  struct System_UInt64_array *oneShotKey;
  s64 v9;
  struct System_UInt64_array *repeatKey;
  struct System_UInt64_array *v13;

  if (oneShot)
  {
    v9 = oneShotKey + 8 * kind;
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
  else
  {
    reset_keydata(InputUtil);
  }
  switch_pad_init();
}

// 0x11551b0
bool IsDecideCircle(void) {
  return 1;
}

// 0x1153090
bool IsDualPattern(s32 attr) {
  u64 v3;
  struct System_Int32_array *dualpattern;
  u64 max_length_low;
  char *v8;

  v3 = 0;
  while (1)
  {
    max_length_low = LODWORD(dualpattern->max_length);
    if (v3 >= max_length_low)
      return 0;
    else if (v3 >= max_length_low)
    {
      goto LABEL_11;
    }
    v8 = dualpattern + 4 * v3++;
    if (*(v8 + 8) == attr)
      return 1;
  }
}

// 0x1155fd0
bool LRInputCheck(void) {
  u64 v2;
  struct nn_hid_NpadId_array *npad_id_list;
  u64 max_length_low;
  s32 v7;
  s32 StyleSet;
  s32 v9;
  u64 *v21;
  s64 *v22;
  bool result;
  Il2CppObject *v25;
  System_String_o *v29;
  s32 v30;
  s32 v31;

  v2 = 0;
  {
LABEL_4:
    goto LABEL_7;
  }
  while (1)
  {
LABEL_7:
    max_length_low = LODWORD(npad_id_list->max_length);
    if (v2 >= max_length_low)
      return 0;
    else if (v2 >= max_length_low)
    {
      goto LABEL_11;
    }
    v7 = npad_id_list->m_Items[v2];
    StyleSet = GetStyleSet(v7);
    if (StyleSet)
      break;
LABEL_6:
    ++v2;
      goto LABEL_4;
  }
  v9 = StyleSet;
  GetState(&pad_state, v7, v9, 0);
  switch (v9)
  {
    case 1:
      if (!sub_1A57840(&pad_state, 64))
        goto LABEL_6;
      if (!sub_1A57840(&pad_state, 128))
        goto LABEL_6;
      SwitchExchangeID(v2);
      v25 = "ProCon";
      goto LABEL_97;
    case 2:
      if (!sub_1A57840(&pad_state, 64))
        goto LABEL_6;
      if (!sub_1A57840(&pad_state, 128))
        goto LABEL_6;
      SwitchExchangeID(v2);
      v25 = "LRInputCheck Handheld";
      goto LABEL_97;
    case 4:
      if (!sub_1A57840(&pad_state, 128))
        goto LABEL_6;
      if (!sub_1A57840(&pad_state, 64))
        goto LABEL_6;
      SwitchExchangeID(v2);
      v25 = "JoyDual";
      goto LABEL_97;
    case 8:
      if (!sub_1A57840(&pad_state, 0x1000000))
        goto LABEL_6;
      if (!sub_1A57840(&pad_state, 0x2000000))
        goto LABEL_6;
      SwitchExchangeID(v2);
      v30 = v2;
      v21 = sub_8D3950(s32, &v30);
      v22 = &"JoyConL : ";
      goto LABEL_93;
    case 16:
      if (!sub_1A57840(&pad_state, 0x4000000))
        goto LABEL_6;
      if (!sub_1A57840(&pad_state, 0x8000000))
        goto LABEL_6;
      SwitchExchangeID(v2);
      v31 = v2;
      v21 = sub_8D3950(s32, &v31);
      v22 = &"JoyConR : ";
LABEL_93:
      v29 = Concat(*v22, v21);
      v25 = v29;
LABEL_97:
      Log(v25, 0);
      result = 1;
      break;
    default:
      goto LABEL_6;
  }
  return result;
}

// 0x1155f50
void LRInputCheckEnd(void) {
  Log("LRInputCheckEnd", 0);
  StopLrAssignmentMode();
}

// 0x1155ed0
void LRInputCheckStart(void) {
  Log("LRInputCheckStart", 0);
  StartLrAssignmentMode();
}

// 0x1155390
void SetSleepFadeMode(bool set) {
  flg_sleep_fade = set;
}

// 0x1155a60
void SetVib(s32 index, s32 value0, s32 value1) {
  struct System_Single_array_array *VibLevel;
  System_Single_array *v10;
  struct System_Single_array_array *v12;
  System_Single_array *v14;
  System_Object_array *v16;
  s64 *v18;
  s64 *v19;
  s64 *v22;
  s64 *v23;
  s64 *v26;
  s64 *v27;
  Il2CppObject *v31;
  s32 v39;
  s32 v40;
  s32 v41;

  v10 = VibLevel->m_Items[index];
  v10->m_Items[0] = value0;
  v12 = VibLevel;
  v14 = v12->m_Items[index];
  v14->m_Items[1] = value1;
  v16 = NewSpecific(object, 7u);
  v16->m_Items[0] = "VibSet[";
  v41 = index;
  v18 = sub_8D3950(s32, &v41);
  v19 = v18;
  v16->m_Items[1] = v19;
  v16->m_Items[2] = "]Low[";
  v40 = value0;
  v22 = sub_8D3950(s32, &v40);
  v23 = v22;
  v16->m_Items[3] = v23;
  v16->m_Items[4] = "]High[";
  v39 = value1;
  v26 = sub_8D3950(s32, &v39);
  v27 = v26;
  v16->m_Items[5] = v27;
  v16->m_Items[6] = "]";
  v31 = Concat_5270224(v16);
  Log(v31, 0);
}

// 0x1155400
void SetVib0(s32 index, s32 value0) {
  struct System_Single_array_array *VibLevel;
  System_Single_array *v8;
  System_Object_array *v10;
  s64 *v12;
  s64 *v13;
  s64 *v16;
  s64 *v17;
  Il2CppObject *v21;
  s32 v27;
  s32 v28;

  v8 = VibLevel->m_Items[index];
  v8->m_Items[0] = value0;
  v10 = NewSpecific(object, 5u);
  v10->m_Items[0] = "VibSet[";
  v28 = index;
  v12 = sub_8D3950(s32, &v28);
  v13 = v12;
  v10->m_Items[1] = v13;
  v10->m_Items[2] = "]Low[";
  v27 = value0;
  v16 = sub_8D3950(s32, &v27);
  v17 = v16;
  v10->m_Items[3] = v17;
  v10->m_Items[4] = "]";
  v21 = Concat_5270224(v10);
  Log(v21, 0);
}

// 0x1155730
void SetVib1(s32 index, s32 value1) {
  struct System_Single_array_array *VibLevel;
  System_Single_array *v8;
  System_Object_array *v10;
  s64 *v12;
  s64 *v13;
  s64 *v16;
  s64 *v17;
  Il2CppObject *v21;
  s32 v27;
  s32 v28;

  v8 = VibLevel->m_Items[index];
  v8->m_Items[1] = value1;
  v10 = NewSpecific(object, 5u);
  v10->m_Items[0] = "VibSet[";
  v28 = index;
  v12 = sub_8D3950(s32, &v28);
  v13 = v12;
  v10->m_Items[1] = v13;
  v10->m_Items[2] = "]High[";
  v27 = value1;
  v16 = sub_8D3950(s32, &v27);
  v17 = v16;
  v10->m_Items[3] = v17;
  v10->m_Items[4] = "]";
  v21 = Concat_5270224(v10);
  Log(v21, 0);
}

// 0x1152f60
void ShowControllerSupport(void) {
  char max_length;
  u64 *v5;
  u32 v6;
  nn_hid_ControllerSupportArg_o v7;
  u32 innerValue;
  nn_hid_ControllerSupportArg_o v9;

  innerValue = 0;
  memset(&v9, 0, sizeof(v9));
  sub_1A51740(&v9);
  v9.enableTakeOverConnection = 1;
  max_length = npad_id_list->max_length;
  v7 = v9;
  v9.enableSingleMode = 1;
  v9.playerCountMax = max_length - 1;
  innerValue = Show_27595344(&v7, 1).innerValue;
  if (!sub_15C4FE0(&innerValue))
  {
    v6 = innerValue;
    v5 = sub_8D3950(nn_Result, &v6);
    Log(v5, 0);
  }
}

// 0x1153e40
void SwitchExchangeID(s32 index) {
  struct nn_hid_NpadId_array *npad_id_list;
  s64 v5;
  s32 v7;
  u64 *v8;
  Il2CppObject *v10;
  System_Int32_c **v12;
  s64 v13;
  u64 v15;
  u64 *v17;
  struct nn_hid_NpadId_array *v19;
  u64 *v21;
  Il2CppObject *v23;
  struct nn_hid_NpadId_array *v24;
  u64 max_length_low;
  s32 v27;
  s64 v30;
  u64 v32;
  u64 *v34;
  struct nn_hid_NpadId_array *v36;
  u64 *v38;
  Il2CppObject *v40;
  u64 v42;
  s64 v43;
  InputUtil_c *v44;
  struct nn_hid_NpadId_array *v45;
  u64 v46;
  System_Int32_c **v47;
  s64 v49;
  u64 v51;
  struct nn_hid_NpadId_array *v52;
  u64 v53;
  struct nn_hid_NpadId_array *v55;
  u64 v56;
  s32 v58;
  s64 v60;
  s64 v61;
  s64 v62;
  u64 *v64;
  struct nn_hid_NpadId_array *v66;
  u64 *v68;
  Il2CppObject *v70;
  s32 Assignment;
  s32 v72;

  v5 = index;
  v7 = npad_id_list->m_Items[index];
  v72 = v7;
  v8 = sub_8D3950(nn_hid_NpadId, &v72);
  v10 = Concat("SwitchExchangeID : ", v8);
  Log(v10, 0);
  if (v7)
  {
    v12 = &s32;
    v13 = 9;
    v15 = 1;
      goto LABEL_17;
LABEL_15:
LABEL_17:
    while (v15 < SLODWORD(npad_id_list->max_length))
    {
      v72 = v13 - 8;
      v17 = sub_8D3950(s32, &v72);
      v19 = npad_id_list;
      Assignment = GetAssignment(*(&v19->obj.klass + v13), 0);
      v21 = sub_8D3950(nn_hid_NpadJoyAssignmentMode, &Assignment);
      v23 = Concat_5269984(v17, ":", v21);
      Log(v23, 0);
      ++v13;
      v15 = v13 - 8;
        goto LABEL_15;
    }
    if (index >= 2)
    {
      while (1)
      {
        v24 = npad_id_list;
        max_length_low = LODWORD(v24->max_length);
        v27 = *(&v24->max_length + v5 + 1);
        SwapAssignment(v27, npad_id_list->m_Items[v5]);
        if (v5 < 3)
          break;
        --v5;
      }
    }
    Log(" ", 0);
    v30 = 9;
    v32 = 1;
    {
LABEL_43:
    }
    while (v32 < SLODWORD(npad_id_list->max_length))
    {
      v72 = v30 - 8;
      v34 = sub_8D3950(s32, &v72);
      v36 = npad_id_list;
      Assignment = GetAssignment(*(&v36->obj.klass + v30), 0);
      v38 = sub_8D3950(nn_hid_NpadJoyAssignmentMode, &Assignment);
      v40 = Concat_5269984(v34, ":", v38);
      Log(v40, 0);
      ++v30;
      v32 = v30 - 8;
        goto LABEL_43;
    }
    Log(" ", 0);
    v42 = 1;
    v43 = 9;
    {
LABEL_60:
    }
    while (1)
    {
      v45 = npad_id_list;
      v46 = LODWORD(v45->max_length);
      if (v42 >= v46)
        break;
      else
      {
        v47 = v12;
        if (v42 >= v46)
          goto LABEL_66;
      }
      v49 = v43;
      if (!GetStyleSet(v45->m_Items[v42]))
      {
        while (1)
        {
          v51 = v49 - 8;
          v52 = npad_id_list;
          v53 = LODWORD(v52->max_length);
          if (v51 >= ((v53 << 32) - 0x100000000LL) >> 32)
            break;
          else if (v51 >= v53)
          {
            goto LABEL_77;
          }
          if (GetStyleSet(*(&v52->obj.klass + v49), 0))
          {
            break;
          }
          ++v49;
        }
        v55 = npad_id_list;
        v56 = LODWORD(v55->max_length);
        v58 = v55->m_Items[v42];
        SwapAssignment(v58, *(&npad_id_list->obj.klass + v49), 0);
      }
      v12 = v47;
      ++v42;
      ++v43;
        goto LABEL_60;
    }
    v60 = 9;
    v61 = 1;
    if ((v44->_2.bitflags2 & 2) == 0)
      goto LABEL_97;
LABEL_95:
LABEL_97:
    while (v61 < SLODWORD(npad_id_list->max_length))
    {
      v62 = *v12;
      v72 = v60 - 8;
      v64 = sub_8D3950(v62, &v72);
      v66 = npad_id_list;
      Assignment = GetAssignment(*(&v66->obj.klass + v60), 0);
      v68 = sub_8D3950(nn_hid_NpadJoyAssignmentMode, &Assignment);
      v70 = Concat_5269984(v64, ":", v68);
      Log(v70, 0);
      v61 = ++v60 - 8;
        goto LABEL_95;
    }
  }
}

// 0x11537e0
void SwitchGetAnalogData(void *stat, s32 style, u64 *key) {
  struct nn_hid_AnalogStickState_o *p_analogStickR;
  f32 v8;
  f32 v10;
  f32 v12;
  f32 v13;
  f32 v14;
  s64 v15;
  struct nn_hid_AnalogStickState_o *p_analogStickL;
  f32 v17;
  f32 v19;
  f32 v21;
  f32 StickValBorder;
  s64 v24;
  f32 v26;
  u64 v27;

  GetHoldType();
  if (style != 16)
  {
    p_analogStickL = &stat->analogStickL;
    v17 = sub_1A508D0(p_analogStickL);
    v19 = sub_1A50910(p_analogStickL);
    *key &= 0xFFFFFFFFFFF0FFFFLL;
    v21 = v19;
    else
    {
      if (v21 < StickValBorder)
        goto LABEL_15;
    }
    v24 = 0x20000;
    goto LABEL_35;
  }
  p_analogStickR = &stat->analogStickR;
  v8 = sub_1A508D0(p_analogStickR);
  v10 = sub_1A50910(p_analogStickR);
  *key &= 0xFFFFFFFFFF0FFFFFLL;
  v12 = v10;
  v13 = StickValBorder;
  if (v12 >= v13)
    goto LABEL_21;
LABEL_7:
  v14 = -v12;
  if (v13 > v14)
    goto LABEL_23;
  v15 = 0x800000;
LABEL_22:
  *key |= v15;
LABEL_23:
  v26 = StickValBorder;
  if (v8 <= -v26)
  {
    v27 = *key | 0x100000;
    goto LABEL_46;
  }
  if (v8 >= v26)
  {
    v27 = *key | 0x400000;
LABEL_46:
    *key = v27;
  }
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
  struct nn_hid_NpadId_array *npad_id_list;
  u32 max_length;
  s32 v9;
  s32 v11;
  u64 *v13;
  struct nn_hid_NpadId_array *v14;
  u64 *v16;
  Il2CppObject *v18;
  u64 *v20;
  struct nn_hid_NpadId_array *v22;
  u64 *v24;
  Il2CppObject *v26;
  u64 *v28;
  struct nn_hid_NpadId_array *v30;
  u64 *v32;
  Il2CppObject *v34;
  u64 *v36;
  struct nn_hid_NpadId_array *v38;
  u64 *v40;
  Il2CppObject *v42;
  u64 *v44;
  struct nn_hid_NpadId_array *v46;
  u64 *v48;
  Il2CppObject *v50;
  System_Object_array *v51;
  s64 *v53;
  s64 *v54;
  s64 *v57;
  s64 *v58;
  s64 *v61;
  s64 *v62;
  s64 *v65;
  s64 *v66;
  Il2CppObject *v69;
  s32 v78;
  s32 v79;
  s32 Assignment;
  s32 v81;

  max_length = npad_id_list->max_length;
  v9 = npad_id_list->m_Items[index1];
  v11 = npad_id_list->m_Items[index2];
  SetAssignmentModeDual(v9);
  SetAssignmentModeDual(v11);
  v81 = 0;
  v13 = sub_8D3950(s32, &v81);
  else
  {
    v14 = npad_id_list;
    if (!LODWORD(v14->max_length))
      goto LABEL_13;
  }
  Assignment = v14->m_Items[0];
  v16 = sub_8D3950(nn_hid_NpadId, &Assignment);
  v18 = Concat_5269984(v13, ":", v16);
  Log(v18, 0);
  v81 = 1;
  v20 = sub_8D3950(s32, &v81);
  v22 = npad_id_list;
  Assignment = v22->m_Items[1];
  v24 = sub_8D3950(nn_hid_NpadId, &Assignment);
  v26 = Concat_5269984(v20, ":", v24);
  Log(v26, 0);
  v81 = 2;
  v28 = sub_8D3950(s32, &v81);
  v30 = npad_id_list;
  Assignment = v30->m_Items[2];
  v32 = sub_8D3950(nn_hid_NpadId, &Assignment);
  v34 = Concat_5269984(v28, ":", v32);
  Log(v34, 0);
  v81 = 3;
  v36 = sub_8D3950(s32, &v81);
  v38 = npad_id_list;
  Assignment = v38->m_Items[3];
  v40 = sub_8D3950(nn_hid_NpadId, &Assignment);
  v42 = Concat_5269984(v36, ":", v40);
  Log(v42, 0);
  v81 = 4;
  v44 = sub_8D3950(s32, &v81);
  v46 = npad_id_list;
  Assignment = v46->m_Items[4];
  v48 = sub_8D3950(nn_hid_NpadId, &Assignment);
  v50 = Concat_5269984(v44, ":", v48);
  Log(v50, 0);
  v51 = NewSpecific(object, 8u);
  v51->m_Items[0] = "SwitchMerge : ";
  v81 = v9;
  v53 = sub_8D3950(nn_hid_NpadId, &v81);
  v54 = v53;
  v51->m_Items[1] = v54;
  v51->m_Items[2] = ",";
  Assignment = GetAssignment(v9);
  v57 = sub_8D3950(nn_hid_NpadJoyAssignmentMode, &Assignment);
  v58 = v57;
  v51->m_Items[3] = v58;
  v51->m_Items[4] = ",";
  v79 = v11;
  v61 = sub_8D3950(nn_hid_NpadId, &v79);
  v62 = v61;
  v51->m_Items[5] = v62;
  v51->m_Items[6] = ",";
  v78 = GetAssignment(v11);
  v65 = sub_8D3950(nn_hid_NpadJoyAssignmentMode, &v78);
  v66 = v65;
  v51->m_Items[7] = v66;
  v69 = Concat_5270224(v51);
  Log(v69, 0);
  MergeSingleAsDual(v9, v11);
}

// 0x1153190
void SwitchRefleshController(void) {
  s64 v2;
  u64 v4;
  struct nn_hid_NpadId_array *npad_id_list;
  u64 max_length_low;
  s32 StyleSet;
  struct nn_hid_NpadId_array *v9;
  s32 v10;
  u64 *v12;
  u64 *v13;
  Il2CppObject *v15;
  struct nn_hid_NpadId_array *v17;
  u64 *v19;
  Il2CppObject *v21;
  System_Object_array *v23;
  s64 *v26;
  s64 *v27;
  s64 *v30;
  s64 *v32;
  struct nn_hid_NpadId_array *v36;
  s64 *v38;
  s64 *v39;
  Il2CppObject *v44;
  struct nn_hid_NpadId_array *v45;
  s32 v52;
  s32 attributes;
  bool v54[4];
  nn_hid_NpadState_o pOutValue;

  v54[0] = 0;
  memset(&pOutValue, 0, sizeof(pOutValue));
  v2 = 8;
  v4 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(npad_id_list->max_length);
    if (v4 >= max_length_low)
      break;
    else if (v4 >= max_length_low)
    {
      goto LABEL_12;
    }
    StyleSet = GetStyleSet(*(&npad_id_list->obj.klass + v2), 0);
    v9 = npad_id_list;
    v10 = StyleSet;
    attributes = *(&v9->obj.klass + v2);
    v12 = sub_8D3950(nn_hid_NpadId, &attributes);
    v52 = v10;
    v13 = sub_8D3950(nn_hid_NpadStyle, &v52);
    v15 = Concat_5269984(v12, " is ", v13);
    Log(v15, 0);
    if (v10 == 4)
    {
      memset(&pOutValue, 0, sizeof(pOutValue));
      v17 = npad_id_list;
      GetState(&pOutValue, *(&v17->obj.klass + v2), 4, 0);
      attributes = pOutValue.attributes;
      v19 = sub_8D3950(s32, &attributes);
      v21 = Concat("status : ", v19);
      Log(v21, 0);
      if (!IsDualPattern(pOutValue.attributes))
      {
        v54[0] = (pOutValue.attributes & 4) != 0;
        v23 = NewSpecific(object, 7u);
        v23->m_Items[0] = "LR = ";
        attributes = v2 - 8;
        v26 = sub_8D3950(s32, &attributes);
        v27 = v26;
        v23->m_Items[1] = v27;
        v23->m_Items[2] = ",";
        v30 = sub_3C0020(v54);
        v32 = v30;
        v23->m_Items[3] = v32;
        v23->m_Items[4] = ",";
        v36 = npad_id_list;
        v52 = *(&v36->obj.klass + v2);
        v38 = sub_8D3950(nn_hid_NpadId, &v52);
        v39 = v38;
        v23->m_Items[5] = v39;
        v23->m_Items[6] = ",AutoSeparate";
        v44 = Concat_5270224(v23);
        Log(v44, 0);
        v45 = npad_id_list;
        SetAssignmentModeSingle_27617840(*(&v45->obj.klass + v2), !v54[0], 0);
      }
    }
    ++v2;
    v4 = v2 - 8;
      goto LABEL_6;
  }
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
          goto LABEL_38;
        }
        if (v3 == 0x2000000)
        {
          v5 = 9;
          goto LABEL_38;
        }
      }
      else
      {
        if (v3 == 0x10000)
        {
          v5 = 10;
          goto LABEL_38;
        }
        if (v3 == 0x20000)
        {
          v5 = 11;
          goto LABEL_38;
        }
      }
    }
    else
    {
      switch (v3)
      {
        case 0x2000uLL:
          v5 = 12;
          goto LABEL_38;
        case 0x4000uLL:
          v5 = 7;
          goto LABEL_38;
        case 0x8000uLL:
          v5 = 13;
          goto LABEL_38;
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
        goto LABEL_38;
      }
      if (v3 == 4096)
      {
        v5 = 6;
        goto LABEL_38;
      }
    }
    else
    {
      if (v3 == 512)
      {
        v5 = 3;
        goto LABEL_38;
      }
      if (v3 == 1024)
      {
        v5 = 4;
        goto LABEL_38;
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
        goto LABEL_38;
      case 2uLL:
        v5 = 23;
        goto LABEL_38;
      case 3uLL:
        return v3;
      case 4uLL:
        v5 = 24;
        goto LABEL_38;
    }
  }
  if (v3 == 8)
  {
    v5 = 25;
    goto LABEL_38;
  }
  if (v3 != 256)
    return v3;
  v5 = 2;
LABEL_38:
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
  s32 v2;
  s32 v3;
  s64 v4;
  u64 v6;
  struct nn_hid_NpadId_array *npad_id_list;
  u64 max_length_low;
  s32 StyleSet;
  s32 v11;
  struct nn_hid_NpadId_array *v13;
  u64 v17;
  struct nn_hid_NpadId_array *v19;
  s32 v21;
  struct nn_hid_NpadId_array *v22;
  s64 v24;
  s64 v25;
  s64 v26;
  s64 v27;
  u64 v28;
  s64 v29;
  u64 v31;
  struct nn_hid_NpadId_array *v34;
  s64 npad_count;
  s32 v37;
  s32 v38;
  s32 v39;
  struct System_Single_array_array_array *AnalogStickLRval;
  System_Single_array_array *v43;
  System_Single_array *v45;
  f32 v46;
  struct System_Single_array_array_array *v48;
  System_Single_array_array *v50;
  System_Single_array *v52;
  f32 v53;
  struct System_Single_array_array_array *v55;
  System_Single_array_array *v57;
  System_Single_array *v59;
  f32 v60;
  struct System_Single_array_array_array *v62;
  System_Single_array_array *v64;
  System_Single_array *v66;
  f32 v68;
  s64 v73;
  struct nn_hid_NpadStyle_array *npad_style;
  s64 *v76;
  s64 v77;
  struct nn_hid_AnalogStickState_o v78;
  struct nn_hid_AnalogStickState_o v79;
  s64 v80;
  s64 v81;
  u64 Item;
  u64 v86;
  struct System_UInt64_array *currentKey;
  s64 v91;
  u64 v92;
  u64 v94;
  s64 v95;
  u64 v96;
  u64 v97;
  u64 v98;
  struct InputUtil_KeyTbl_array_array *switch_key_checktable;
  struct InputUtil_KeyTbl_array_array *v102;
  InputUtil_KeyTbl_array *v104;
  u64 retkey;
  s64 button;
  struct System_UInt64_array *v108;
  struct System_UInt64_array *oldKey;
  struct System_UInt64_array *oneShotKey;
  System_Object_array *v115;
  s64 *v118;
  s64 *v120;
  s64 *v125;
  s64 *v126;
  s64 *v130;
  s64 *v131;
  Il2CppObject *v134;
  u64 v139;
  s64 v140;
  struct nn_hid_NpadId_array *v142;
  u64 v143;
  s64 v145;
  u64 v147;
  struct nn_hid_NpadId_array *v148;
  u64 v149;
  struct nn_hid_NpadId_array *v151;
  u64 v152;
  s32 v154;
  s64 v156;
  s32 v157;
  u64 v158;
  u64 v159;
  nn_hid_NpadState_o v160;
  s32 v161;
  s32 attributes;
  s32 v163;
  nn_hid_NpadState_o pOutValue;
  u64 buttons;

  buttons = 0;
  v2 = 0;
  v3 = 0;
  v4 = 8;
  memset(&pOutValue, 0, sizeof(pOutValue));
  v6 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    max_length_low = LODWORD(npad_id_list->max_length);
    if (v6 >= max_length_low)
      break;
    else if (v6 >= max_length_low)
    {
      goto LABEL_12;
    }
    StyleSet = GetStyleSet(*(&npad_id_list->obj.klass + v4), 0);
    if (v4 == 8)
      v2 = StyleSet;
    if (StyleSet)
    {
      v11 = v3 + 1;
      if (StyleSet == 4)
      {
        memset(&pOutValue, 0, sizeof(pOutValue));
        v13 = npad_id_list;
        GetState(&pOutValue, *(&v13->obj.klass + v4), 4, 0);
        if (!IsDualPattern(pOutValue.attributes))
          v11 = v3;
      }
    }
    else
    {
      v11 = v3;
    }
    ++v4;
    v3 = v11;
    v6 = v4 - 8;
      goto LABEL_6;
  }
  get_mode(0);
  if (!v3)
  {
      goto LABEL_46;
    goto LABEL_40;
  }
  if (!v2)
  {
    else if (!b_handheld)
    {
      goto LABEL_52;
    }
    if ((*(v17 + 295) & 2) == 0)
    {
LABEL_46:
      ShowControllerSupport(v17);
      v22 = npad_id_list;
      b_handheld = GetStyleSet(v22->m_Items[0]) != 0;
      return;
    }
LABEL_40:
    goto LABEL_46;
  }
  else
  {
    if (!b_handheld)
    {
LABEL_32:
      v19 = npad_id_list;
      v21 = GetStyleSet(v19->m_Items[0]);
      b_handheld = v21 != 0;
      buttons = 0;
      if ((*(v17 + 295) & 2) == 0)
        goto LABEL_55;
      goto LABEL_53;
    }
  }
LABEL_52:
  buttons = 0;
  if ((*(v17 + 295) & 2) != 0)
  {
LABEL_53:
  }
LABEL_55:
  *(*(v17 + 184) + 80LL) = 0;
  v24 = *(v17 + 184);
  v25 = *(*(v24 + 152) + 24LL);
  v26 = v25;
  if (*(v24 + 193))
  {
    if (v25 < 2)
    {
      v31 = v25 != 1;
      if (v31 >= v25)
        return;
    }
    else
    {
      v27 = 9;
      v28 = 1;
      if ((*(v17 + 295) & 2) == 0)
        goto LABEL_62;
LABEL_60:
      while (1)
      {
LABEL_62:
        v29 = *(*(v17 + 184) + 152LL);
        if (GetStyleSet(*(v29 + 4 * v27), 0))
        {
          v31 = v27 - 8 != v25;
          if (v31 >= v25)
            return;
          goto LABEL_73;
        }
        if (v27 - 7 >= v25)
          break;
        v28 = ++v27 - 8;
          goto LABEL_60;
      }
      v31 = v27 - 7 != v25;
      if (v31 >= v25)
        return;
    }
  }
  else
  {
    v31 = 1;
    if (v25 <= 1)
      return;
  }
LABEL_73:
  v157 = 0;
  v156 = v25;
  do
  {
    while (1)
    {
      while (1)
      {
        buttons = 0;
        v34 = npad_id_list;
        npad_count = _npad_count;
        v37 = v34->m_Items[v31];
        v38 = GetStyleSet(v37);
        if (v38)
          break;
        ++v157;
        if (++v31 == v26)
          goto LABEL_210;
      }
      v39 = v38;
      GetState(&pad_state, v37, v39, 0);
      v43 = AnalogStickLRval->m_Items[npad_count];
      v45 = v43->m_Items[0];
      v46 = sub_1A508D0(&pad_state.analogStickL);
      v45->m_Items[0] = v46;
      v48 = AnalogStickLRval;
      v50 = v48->m_Items[npad_count];
      v52 = v50->m_Items[0];
      v53 = sub_1A50910(&pad_state.analogStickL);
      v52->m_Items[1] = v53;
      v55 = AnalogStickLRval;
      v57 = v55->m_Items[npad_count];
      v59 = v57->m_Items[1];
      v60 = sub_1A508D0(&pad_state.analogStickR);
      v59->m_Items[0] = v60;
      v62 = AnalogStickLRval;
      v64 = v62->m_Items[npad_count];
      v66 = v64->m_Items[1];
      v68 = sub_1A50910(&pad_state.analogStickR);
      v66->m_Items[1] = v68;
      if (v39 != 4)
        break;
      else if (IsDualPattern(pad_state.attributes))
      {
        break;
      }
      v115 = NewSpecific(object, 6u);
      v115->m_Items[0] = "JoyDual Half Pipe : ";
      v163 = v37;
      v118 = sub_8D3950(nn_hid_NpadId, &v163);
      v120 = v118;
      v115->m_Items[1] = v120;
      v115->m_Items[2] = ",";
      attributes = pad_state.attributes;
      v125 = sub_8D3950(nn_hid_NpadAttribute, &attributes);
      v126 = v125;
      v115->m_Items[3] = v126;
      v115->m_Items[4] = ",";
      v161 = 4;
      v130 = sub_8D3950(nn_hid_NpadStyle, &v161);
      v131 = v130;
      v115->m_Items[5] = v131;
      v134 = Concat_5270224(v115);
      Log(v134, 0);
      SwitchRefleshController();
      if (++v31 == v26)
        goto LABEL_210;
    }
    buttons = pad_state.buttons;
    GetPlayerLedPattern(v37);
    v73 = _npad_count;
    _npad_count = v73 + 1;
    npad_style->m_Items[v73] = v39;
    v77 = v76[14];
    v160.samplingNumber = v76[13];
    v160.buttons = v77;
    v78 = v76[15];
    v79 = v76[16];
    v81 = v76[17];
    v80 = v76[18];
    *&v160.attributes = v81;
    v160.preButtons = v80;
    v160.analogStickL = v78;
    v160.analogStickR = v79;
    SwitchGetAnalogData(&v160, v39, &buttons);
    if (!ulong___ContainsKey(cnt_buttons, npad_count))
    {
      Item = 0;
        goto LABEL_126;
LABEL_121:
      goto LABEL_126;
    }
    Item = ulong___get_Item(cnt_buttons, npad_count);
      goto LABEL_121;
LABEL_126:
    v86 = buttons;
    ulong___set_Item(cnt_buttons, npad_count, buttons);
    ulong___set_Item(trg_buttons, npad_count, v86 & ~Item);
    if (v39 == 8)
      v91 = 1;
    else
      v91 = 2LL * (v39 == 16);
    v158 = currentKey->m_Items[npad_count];
    v159 = v31;
    v92 = ulong___get_Item(cnt_buttons, npad_count);
    v94 = ulong___get_Item(trg_buttons, npad_count);
    v95 = 0;
    v96 = 0;
    v97 = 0;
    v98 = 0;
    {
LABEL_137:
      goto LABEL_139;
    }
    while (1)
    {
LABEL_139:
      if (v96 >= SLODWORD(switch_key_checktable->m_Items[v91]->max_length))
        break;
      v102 = switch_key_checktable;
      v104 = v102->m_Items[v91];
      button = v104->m_Items[v95].button;
      retkey = v104->m_Items[v95].retkey;
      if ((button & v92) != 0)
      {
        v98 |= Switch_Assign_Retkey(npad_count, retkey);
      }
      if ((button & v94) != 0)
      {
        v97 |= Switch_Assign_Retkey(npad_count, retkey);
      }
      ++v96;
      ++v95;
        goto LABEL_137;
    }
    v108 = currentKey;
    v26 = v156;
    v108->m_Items[npad_count] = v98;
    oldKey->m_Items[npad_count] = v158;
    oneShotKey->m_Items[npad_count] = v97;
    v31 = v159 + 1;
  }
  while (v159 + 1 != v156);
LABEL_210:
  if (v157)
  {
    v139 = 1;
    v140 = 9;
      goto LABEL_216;
LABEL_214:
LABEL_216:
    while (1)
    {
      v142 = npad_id_list;
      v143 = LODWORD(v142->max_length);
      if (v139 >= v143)
        break;
      else if (v139 >= v143)
      {
        goto LABEL_220;
      }
      v145 = v140;
      if (!GetStyleSet(v142->m_Items[v139]))
      {
        while (1)
        {
          v147 = v145 - 8;
          v148 = npad_id_list;
          v149 = LODWORD(v148->max_length);
          if (v147 >= ((v149 << 32) - 0x100000000LL) >> 32)
            break;
          else if (v147 >= v149)
          {
            goto LABEL_231;
          }
          if (GetStyleSet(*(&v148->obj.klass + v145), 0))
          {
            break;
          }
          ++v145;
        }
        v151 = npad_id_list;
        v152 = LODWORD(v151->max_length);
        v154 = v151->m_Items[v139];
        SwapAssignment(v154, *(&npad_id_list->obj.klass + v145), 0);
      }
      ++v139;
      ++v140;
        goto LABEL_214;
    }
  }
}

// 0x1150ee0
void Update(void) {
  else
  {
    Switch_Pad_Update(InputUtil);
  }
  create_repeatdata();
}

// 0x1152760
void resetRepeat(s32 index, f32 delayTime) {
  struct System_Single_array *nextRepeatTime;

  {
    delayTime = defFirstDelayTime;
  }
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
  InputUtil_c *v13;
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

  Log("switch_pad_init", 0);
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
  if ((v13->_2.bitflags2 & 2) != 0)
  {
LABEL_14:
    goto LABEL_16;
  }
  while (1)
  {
LABEL_16:
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
      goto LABEL_14;
  }
}
