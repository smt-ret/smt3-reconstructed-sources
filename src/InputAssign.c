#include "types.h"

typedef struct InputAssign InputAssign;
typedef struct InputAssign_AssignCode InputAssign_AssignCode;
typedef struct InputAssign_AssignData InputAssign_AssignData;
typedef struct InputAssign_AssignkeyInfo InputAssign_AssignkeyInfo;
typedef struct InputAssign_ControllerID InputAssign_ControllerID;
typedef struct InputAssign_ControllerType InputAssign_ControllerType;
typedef struct InputAssign_KeyID InputAssign_KeyID;
typedef struct InputAssign_KeyboardType InputAssign_KeyboardType;

struct InputAssign {
    InputAssign_AssignData *_assignData[6];
    InputAssign_AssignData *SavedAssignData;
    InputAssign_AssignData *_assignData_sav[6];
    InputAssign_AssignkeyInfo *_assignkeyInfo[131];
};

struct InputAssign_AssignData {
    InputAssign_AssignCode *data[18];
};

struct InputAssign_AssignkeyInfo {
    s32 keyCode;
    char *strUS104;
    char *strJP106;
};

struct InputAssign_ControllerID {
    s32 value__;
};

struct InputAssign_ControllerType {
    s32 value__;
};

struct InputAssign_KeyboardType {
    s32 value__;
};

struct InputAssign_KeyID {
    s32 value__;
};

struct InputAssign_AssignCode {
    s32 value__;
};

static InputAssign *_instance;

void SetAssignDefault(InputAssign *this, s32 controllerID, s32 getMachine);

// 0x11508d0
void DispAssignCode(InputAssign *this, s32 idx) {
  ;
}

// 0x114edc0
s32 GetAssignCode(InputAssign *this, s32 controllerID, s32 keyID) {
  struct InputAssign_AssignData_array *assignData;
  struct InputAssign_AssignCode_array *data;

  assignData = this->_assignData;
  data = assignData->m_Items[controllerID]->data;
  return data->m_Items[keyID];
}

// 0x114e850
s32 GetControllerType(InputAssign *this, s32 controllerID) {
  if (controllerID >= 5)
    return 2 * (controllerID == 5);
  else
    return dword_33CC574[controllerID];
}

// 0x114ea60
s32 GetKeyCode(InputAssign *this, s32 controllerID, s32 assignCode) {
  s32 result;
  struct InputAssign_AssignkeyInfo_array *assignkeyInfo;

  switch (controllerID)
  {
    case 0:
      result = assignCode + 348;
      break;
    case 1:
      result = assignCode + 368;
      break;
    case 2:
      result = assignCode + 388;
      break;
    case 3:
      result = assignCode + 408;
      break;
    default:
      assignkeyInfo = this->_assignkeyInfo;
      result = assignkeyInfo->m_Items[assignCode]->keyCode;
      break;
  }
  return result;
}

// 0x114ed00
s32 GetKeyID(InputAssign *this, s32 controllerID, s32 assignCode) {
  u64 v4;
  s32 v5;
  struct InputAssign_AssignData_array *assignData;
  struct InputAssign_AssignCode_array *data;

  v4 = 0;
  v5 = 18;
  while (1)
  {
    assignData = this->_assignData;
    data = assignData->m_Items[controllerID]->data;
    if (data->m_Items[v4] == assignCode)
      break;
    if (v4++ > 0x10)
      return v5;
  }
  return v4;
}

// 0x114eaf0
char *GetKeyboardString(InputAssign *this, s32 assignCode, s32 keyboardType) {
  struct InputAssign_AssignkeyInfo_array *v7;
  System_String_o **p_strJP106;
  struct InputAssign_AssignkeyInfo_array *assignkeyInfo;

  if (keyboardType == 1)
  {
    assignkeyInfo = this->_assignkeyInfo;
    p_strJP106 = &assignkeyInfo->m_Items[assignCode]->strJP106;
  }
  else if (keyboardType)
  {
    p_strJP106 = &StringLiteral_416;
  }
  else
  {
    v7 = this->_assignkeyInfo;
    p_strJP106 = &v7->m_Items[assignCode]->strUS104;
  }
  return *p_strJP106;
}

// 0x114d580
void InitAssignData(InputAssign *this) {
  s64 i;
  u32 *assignData;
  Il2CppObject *v7;
  u64 v8;
  u32 *assignData_sav;
  Il2CppObject *v11;
  Il2CppObject *v13;
  s32 v15;
  s32 v17;
  s32 v19;
  s32 v21;
  s32 v23;
  s32 v25;

  this->_assignData = NewSpecific(InputAssign_AssignData, 6u);
  this->_assignData_sav = NewSpecific(InputAssign_AssignData, 6u);
  for (i = 4; i != 10; ++i)
  {
    assignData = this->_assignData;
    v7 = Allocate(InputAssign_AssignData);
    v8 = i - 4;
    v7[1].klass = NewSpecific(InputAssign_AssignCode, 0x12u);
    _ctor(v7, 0);
    *&assignData[2 * i] = v7;
    assignData_sav = this->_assignData_sav;
    v11 = Allocate(InputAssign_AssignData);
    v11[1].klass = NewSpecific(InputAssign_AssignCode, 0x12u);
    _ctor(v11, 0);
    *&assignData_sav[2 * i] = v11;
  }
  v13 = Allocate(InputAssign_AssignData);
  v13[1].klass = NewSpecific(InputAssign_AssignCode, 0x12u);
  _ctor(v13, 0);
  this->SavedAssignData = v13;
  SetAssignDefault(this, 0, v15);
  SetAssignDefault(this, 1, v17);
  SetAssignDefault(this, 2, v19);
  SetAssignDefault(this, 3, v21);
  SetAssignDefault(this, 4, v23);
  SetAssignDefault(this, 5, v25);
}

// 0x114d830
void InitAssignkeyInfo(InputAssign *this) {
  ;
}

// 0x114e880
bool IsChangedDefaultSetting(InputAssign *this, s32 controllerID, s32 machine) {
  System_Array_o *v6;
  System_Array_o *v7;
  System_Array_o *v8;
  u64 *v9;
  System_Array_o *v10;
  s32 v11;
  System_Array_o *v12;
  s64 i;
  struct InputAssign_AssignData_array *assignData;
  u64 v15;
  struct InputAssign_AssignCode_array *data;
  s32 v18;

  v6 = NewSpecific(InputAssign_AssignCode, 0xFu);
  InitializeArray_1543888(v6, Field__PrivateImplementationDetails__C18D5D6668FD6384BB327042F3FFE9E4F6FAB889);
  v7 = NewSpecific(InputAssign_AssignCode, 0xFu);
  InitializeArray_1543888(v7, Field__PrivateImplementationDetails__1B437F6441FAD028C866485AB5004BE1F6080915);
  v8 = NewSpecific(InputAssign_AssignCode, 0xFu);
  InitializeArray_1543888(v8, Field__PrivateImplementationDetails__3B84111B40ED3AB4AD4A248FD5AAFC7ACEED6ABA);
  v9 = NewSpecific(InputAssign_AssignCode, 0x12u);
  v10 = v9;
  if (controllerID < 4)
  {
    v11 = *(v9 + 6);
    v12 = v6;
    Copy_3886320(v12, v10, v11);
  }
  if (controllerID == 4)
  {
    v11 = *(v9 + 6);
    v12 = v7;
  }
  if (controllerID == 5)
  {
    v11 = *(v9 + 6);
    v12 = v8;
  }
  for (i = 8; ; ++i)
  {
    assignData = this->_assignData;
    v15 = i - 8;
    data = assignData->m_Items[controllerID]->data;
    v18 = *(&data->obj.klass + i);
    if (v18 != *(&v10->klass + i))
      break;
    if (v15 >= 0x11)
      return 0;
  }
  return 1;
}

// 0x114efa0
bool IsKeyboardAssignCode(InputAssign *this, s32 assignCode) {
  switch (assignCode)
  {
    case 0:
      return 0;
    case 1:
      return 1;
    case 128:
      return 0;
  }
  return assignCode > 33;
}

// 0x114efd0
bool IsPadAssignCode(InputAssign *this, s32 assignCode) {
  switch (assignCode)
  {
    case 0:
      return 0;
    case 1:
      return 1;
    case 128:
      return 0;
  }
  return assignCode < 34;
}

// 0x114ef30
bool IsValidAssignCode(InputAssign *this, s32 controllerID, s32 assignCode) {
  if (controllerID >= 4)
  {
    if ((controllerID - 4) <= 1 && assignCode)
    {
      if (assignCode != 1)
        return assignCode != 128 && assignCode > 33;
      return 1;
    }
    return 0;
  }
  if (!assignCode)
    return 0;
  if (assignCode != 1)
    return assignCode <= 33;
  return 1;
}

// 0x114ebc0
s32 KeyCodeToAssignCode(InputAssign *this, s32 controllerID, s32 keyCode, f32 trigger) {
  struct InputAssign_AssignkeyInfo_array *assignkeyInfo;
  il2cpp_array_size_t max_length;
  u64 v9;

  if (trigger < 0.5 && keyCode == 0 && trigger > -0.5)
  {
    LODWORD(v9) = 1;
  }
  else
  {
    switch (controllerID)
    {
      case 0:
        if ((keyCode - 350) > 0x13)
        LODWORD(v9) = keyCode - 348;
        break;
      case 1:
        if ((keyCode - 370) > 0x13)
        LODWORD(v9) = keyCode - 368;
        break;
      case 2:
        if ((keyCode - 390) > 0x13)
        LODWORD(v9) = keyCode - 388;
        break;
      case 3:
        if ((keyCode - 410) <= 0x13)
        {
          LODWORD(v9) = keyCode - 408;
        }
        else
        {
          if (trigger > -0.5)
            LODWORD(v9) = 13;
          else
            LODWORD(v9) = 12;
          if (trigger > -0.5 && trigger < 0.5)
        }
        break;
      case 4:
      case 5:
        assignkeyInfo = this->_assignkeyInfo;
        max_length = assignkeyInfo->max_length;
        if (max_length < 1)
        v9 = 0;
        while (1)
        {
          if (assignkeyInfo->m_Items[v9]->keyCode == keyCode)
            break;
          assignkeyInfo = this->_assignkeyInfo;
          LODWORD(max_length) = assignkeyInfo->max_length;
          if (++v9 >= max_length)
        }
        break;
      default:
        LODWORD(v9) = 0;
        break;
    }
  }
  return v9;
}

// 0x1150860
void PopCurrentAssisnData(InputAssign *this, s32 padID) {
  struct InputAssign_AssignData_array *assignData;

  assignData = this->_assignData;
  Copy_3886320(this->SavedAssignData->data, assignData->m_Items[padID]->data, this->SavedAssignData->data->max_length);
}

// 0x11507f0
void PushCurrentAssignData(InputAssign *this, s32 padID) {
  struct InputAssign_AssignData_array *assignData;

  assignData = this->_assignData;
  Copy_3886320(assignData->m_Items[padID]->data, this->SavedAssignData->data, this->SavedAssignData->data->max_length);
}

// 0x114ee40
bool SetAssignCode(InputAssign *this, s32 controllerID, s32 keyID, s32 assignCode) {
  bool v5;
  struct InputAssign_AssignData_array *assignData;
  struct InputAssign_AssignCode_array *data;

  if (controllerID >= 4)
  {
    if ((controllerID - 4) > 1)
      return 0;
    v5 = 0;
    if (!assignCode)
      return v5;
    if (assignCode != 1)
    {
      if (assignCode == 128)
        return v5;
      if (assignCode <= 33)
        return 0;
    }
  }
  else
  {
    v5 = 0;
    if (!assignCode)
      return v5;
    if (assignCode != 1)
    {
      if (assignCode == 128)
        return v5;
      if (assignCode > 33)
        return 0;
    }
  }
  assignData = this->_assignData;
  data = assignData->m_Items[controllerID]->data;
  data->m_Items[keyID] = assignCode;
  return 1;
}

// 0x114d8a0
void SetAssignDefault(InputAssign *this, s32 controllerID, s32 getMachine) {
}

// 0x114ff50
void SetInputAssign_FromInputAssign(InputAssign *this, s32 id, s32 type) {
  struct InputAssign_AssignData_array *assignData;
  struct GlobalData_PadConfig_array *padconfig;
  struct InputAssign_AssignCode_array *data;
  s32 v12;
  struct InputAssign_AssignData_array *v14;
  struct GlobalData_PadConfig_array *v15;
  struct InputAssign_AssignCode_array *v17;
  s32 v19;
  struct InputAssign_AssignData_array *v21;
  struct GlobalData_PadConfig_array *v22;
  struct InputAssign_AssignCode_array *v24;
  s32 v26;
  struct InputAssign_AssignData_array *v28;
  struct GlobalData_PadConfig_array *v29;
  struct InputAssign_AssignCode_array *v31;
  s32 v33;
  struct InputAssign_AssignData_array *v35;
  struct GlobalData_PadConfig_array *v36;
  struct InputAssign_AssignCode_array *v38;
  s32 v40;
  struct InputAssign_AssignData_array *v42;
  struct GlobalData_PadConfig_array *v43;
  struct InputAssign_AssignCode_array *v45;
  s32 v47;
  struct InputAssign_AssignData_array *v49;
  struct GlobalData_PadConfig_array *v50;
  struct InputAssign_AssignCode_array *v52;
  s32 v54;
  struct InputAssign_AssignData_array *v56;
  struct GlobalData_PadConfig_array *v57;
  struct InputAssign_AssignCode_array *v59;
  s32 v61;
  struct InputAssign_AssignData_array *v63;
  struct GlobalData_PadConfig_array *v64;
  struct InputAssign_AssignCode_array *v66;
  s32 v68;
  struct InputAssign_AssignData_array *v70;
  struct GlobalData_PadConfig_array *v71;
  struct InputAssign_AssignCode_array *v73;
  s32 v75;
  struct InputAssign_AssignData_array *v77;
  struct GlobalData_PadConfig_array *v78;
  struct InputAssign_AssignCode_array *v80;
  s32 v82;
  struct InputAssign_AssignData_array *v84;
  struct GlobalData_PadConfig_array *v85;
  struct InputAssign_AssignCode_array *v87;
  s32 v89;
  struct InputAssign_AssignData_array *v91;
  struct GlobalData_PadConfig_array *v92;
  struct InputAssign_AssignCode_array *v94;
  s32 v96;
  struct InputAssign_AssignData_array *v98;
  struct GlobalData_PadConfig_array *v99;
  struct InputAssign_AssignCode_array *v101;
  s32 v103;
  struct InputAssign_AssignData_array *v105;
  struct GlobalData_PadConfig_array *v106;
  struct InputAssign_AssignCode_array *v108;
  s32 v110;
  GlobalData_c *v112;
  struct GlobalData_StaticFields *static_fields;
  struct GlobalData_PadConfig_array *v114;
  s16 CONTROLER_TYPE_KEYBOAD;
  struct GlobalData_StaticFields *v116;

  assignData = this->_assignData;
  padconfig = system_save.padconfig;
  data = assignData->m_Items[id]->data;
  v12 = data->m_Items[0];
  padconfig->m_Items[id].btn_a = v12;
  v14 = this->_assignData;
  v15 = system_save.padconfig;
  v17 = v14->m_Items[id]->data;
  v19 = v17->m_Items[1];
  v15->m_Items[id].btn_b = v19;
  v21 = this->_assignData;
  v22 = system_save.padconfig;
  v24 = v21->m_Items[id]->data;
  v26 = v24->m_Items[2];
  v22->m_Items[id].btn_x = v26;
  v28 = this->_assignData;
  v29 = system_save.padconfig;
  v31 = v28->m_Items[id]->data;
  v33 = v31->m_Items[3];
  v29->m_Items[id].btn_y = v33;
  v35 = this->_assignData;
  v36 = system_save.padconfig;
  v38 = v35->m_Items[id]->data;
  v40 = v38->m_Items[4];
  v36->m_Items[id].btn_r1 = v40;
  v42 = this->_assignData;
  v43 = system_save.padconfig;
  v45 = v42->m_Items[id]->data;
  v47 = v45->m_Items[5];
  v43->m_Items[id].btn_l1 = v47;
  v49 = this->_assignData;
  v50 = system_save.padconfig;
  v52 = v49->m_Items[id]->data;
  v54 = v52->m_Items[6];
  v50->m_Items[id].btn_st = v54;
  v56 = this->_assignData;
  v57 = system_save.padconfig;
  v59 = v56->m_Items[id]->data;
  v61 = v59->m_Items[7];
  v57->m_Items[id].key_u = v61;
  v63 = this->_assignData;
  v64 = system_save.padconfig;
  v66 = v63->m_Items[id]->data;
  v68 = v66->m_Items[8];
  v64->m_Items[id].key_d = v68;
  v70 = this->_assignData;
  v71 = system_save.padconfig;
  v73 = v70->m_Items[id]->data;
  v75 = v73->m_Items[9];
  v71->m_Items[id].key_l = v75;
  v77 = this->_assignData;
  v78 = system_save.padconfig;
  v80 = v77->m_Items[id]->data;
  v82 = v80->m_Items[10];
  v78->m_Items[id].key_r = v82;
  v84 = this->_assignData;
  v85 = system_save.padconfig;
  v87 = v84->m_Items[id]->data;
  v89 = v87->m_Items[11];
  v85->m_Items[id].key_lu = v89;
  v91 = this->_assignData;
  v92 = system_save.padconfig;
  v94 = v91->m_Items[id]->data;
  v96 = v94->m_Items[12];
  v92->m_Items[id].key_ld = v96;
  v98 = this->_assignData;
  v99 = system_save.padconfig;
  v101 = v98->m_Items[id]->data;
  v103 = v101->m_Items[13];
  v99->m_Items[id].key_rd = v103;
  v105 = this->_assignData;
  v106 = system_save.padconfig;
  v108 = v105->m_Items[id]->data;
  v110 = v108->m_Items[14];
  v106->m_Items[id].key_ru = v110;
  if (type == 2)
  {
    static_fields = v112->static_fields;
    v114 = static_fields->system_save.padconfig;
    CONTROLER_TYPE_KEYBOAD = static_fields->CONTROLER_TYPE_KEYBOAD;
    if (LODWORD(v114->max_length) > id)
  }
  v116 = v112->static_fields;
  v114 = v116->system_save.padconfig;
  CONTROLER_TYPE_KEYBOAD = v116->CONTROLER_TYPE_GAMEPAD;
  if (LODWORD(v114->max_length) <= id)
  v114->m_Items[id].type = CONTROLER_TYPE_KEYBOAD;
}

// 0x114f000
void SetInputAssign_FromSaveData(InputAssign *this) {
}
