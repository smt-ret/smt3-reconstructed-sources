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
    p_strJP106 = &"";
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
LABEL_9:
    Copy_3886320(v12, v10, v11);
    goto LABEL_10;
  }
  if (controllerID == 4)
  {
    v11 = *(v9 + 6);
    v12 = v7;
    goto LABEL_9;
  }
  if (controllerID == 5)
  {
    v11 = *(v9 + 6);
    v12 = v8;
    goto LABEL_9;
  }
LABEL_10:
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
          goto LABEL_24;
        LODWORD(v9) = keyCode - 348;
        break;
      case 1:
        if ((keyCode - 370) > 0x13)
          goto LABEL_24;
        LODWORD(v9) = keyCode - 368;
        break;
      case 2:
        if ((keyCode - 390) > 0x13)
          goto LABEL_24;
        LODWORD(v9) = keyCode - 388;
        break;
      case 3:
        if ((keyCode - 410) <= 0x13)
        {
          LODWORD(v9) = keyCode - 408;
        }
        else
        {
LABEL_24:
          if (trigger > -0.5)
            LODWORD(v9) = 13;
          else
            LODWORD(v9) = 12;
          if (trigger > -0.5 && trigger < 0.5)
            goto LABEL_29;
        }
        break;
      case 4:
      case 5:
        assignkeyInfo = this->_assignkeyInfo;
        max_length = assignkeyInfo->max_length;
        if (max_length < 1)
          goto LABEL_29;
        v9 = 0;
        while (1)
        {
          if (assignkeyInfo->m_Items[v9]->keyCode == keyCode)
            break;
          assignkeyInfo = this->_assignkeyInfo;
          LODWORD(max_length) = assignkeyInfo->max_length;
          if (++v9 >= max_length)
            goto LABEL_29;
        }
        break;
      default:
LABEL_29:
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
  struct InputAssign_AssignData_array *assignData;
  struct InputAssign_AssignCode_array *data;
  struct InputAssign_AssignData_array *v8;
  struct InputAssign_AssignCode_array *v10;
  struct InputAssign_AssignData_array *v12;
  struct InputAssign_AssignCode_array *v14;
  struct InputAssign_AssignData_array *v16;
  struct InputAssign_AssignCode_array *v18;
  struct InputAssign_AssignData_array *v20;
  struct InputAssign_AssignCode_array *v22;
  struct InputAssign_AssignData_array *v24;
  struct InputAssign_AssignCode_array *v26;
  struct InputAssign_AssignData_array *v28;
  struct InputAssign_AssignCode_array *v30;
  struct InputAssign_AssignData_array *v32;
  struct InputAssign_AssignCode_array *v34;
  struct InputAssign_AssignData_array *v36;
  struct InputAssign_AssignCode_array *v38;
  struct InputAssign_AssignData_array *v40;
  struct InputAssign_AssignCode_array *v42;
  struct InputAssign_AssignData_array *v44;
  struct InputAssign_AssignCode_array *v46;
  struct InputAssign_AssignData_array *v48;
  struct InputAssign_AssignCode_array *v50;
  struct InputAssign_AssignData_array *v52;
  struct InputAssign_AssignCode_array *v54;
  struct InputAssign_AssignData_array *v56;
  struct InputAssign_AssignCode_array *v58;
  struct InputAssign_AssignData_array *v60;
  struct InputAssign_AssignCode_array *v62;
  struct InputAssign_AssignData_array *v64;
  struct InputAssign_AssignCode_array *v66;
  struct InputAssign_AssignData_array *v68;
  struct InputAssign_AssignCode_array *v70;
  struct InputAssign_AssignData_array *v72;
  struct InputAssign_AssignCode_array *v74;
  s32 v76;
  struct InputAssign_AssignData_array *v77;
  struct InputAssign_AssignCode_array *v79;
  struct InputAssign_AssignData_array *v81;
  struct InputAssign_AssignCode_array *v83;
  struct InputAssign_AssignData_array *v85;
  struct InputAssign_AssignCode_array *v87;
  struct InputAssign_AssignData_array *v89;
  struct InputAssign_AssignCode_array *v91;
  struct InputAssign_AssignData_array *v93;
  struct InputAssign_AssignCode_array *v95;
  struct InputAssign_AssignData_array *v97;
  struct InputAssign_AssignCode_array *v99;
  struct InputAssign_AssignData_array *v101;
  struct InputAssign_AssignCode_array *v103;
  struct InputAssign_AssignData_array *v105;
  struct InputAssign_AssignCode_array *v107;
  struct InputAssign_AssignData_array *v109;
  struct InputAssign_AssignCode_array *v111;
  struct InputAssign_AssignData_array *v113;
  struct InputAssign_AssignCode_array *v115;
  struct InputAssign_AssignData_array *v117;
  struct InputAssign_AssignCode_array *v119;
  struct InputAssign_AssignData_array *v121;
  struct InputAssign_AssignCode_array *v123;
  struct InputAssign_AssignData_array *v125;
  struct InputAssign_AssignCode_array *v127;
  struct InputAssign_AssignData_array *v129;
  struct InputAssign_AssignCode_array *v131;
  struct InputAssign_AssignData_array *v133;
  struct InputAssign_AssignCode_array *v135;
  struct InputAssign_AssignData_array *v137;
  struct InputAssign_AssignCode_array *v139;
  struct InputAssign_AssignData_array *v141;
  struct InputAssign_AssignCode_array *v143;
  struct InputAssign_AssignData_array *v145;
  struct InputAssign_AssignCode_array *v147;
  struct InputAssign_AssignData_array *v149;
  struct InputAssign_AssignCode_array *v151;
  struct InputAssign_AssignData_array *v153;
  struct InputAssign_AssignCode_array *v155;
  struct InputAssign_AssignData_array *v157;
  struct InputAssign_AssignCode_array *v159;
  struct InputAssign_AssignData_array *v161;
  struct InputAssign_AssignCode_array *v163;
  struct InputAssign_AssignData_array *v165;
  struct InputAssign_AssignCode_array *v167;
  struct InputAssign_AssignData_array *v169;
  struct InputAssign_AssignCode_array *v171;
  struct InputAssign_AssignData_array *v173;
  struct InputAssign_AssignCode_array *v175;
  struct InputAssign_AssignData_array *v177;
  struct InputAssign_AssignCode_array *v179;
  struct InputAssign_AssignData_array *v181;
  struct InputAssign_AssignCode_array *v183;
  struct InputAssign_AssignData_array *v185;
  struct InputAssign_AssignCode_array *v187;
  struct InputAssign_AssignData_array *v189;
  struct InputAssign_AssignCode_array *v191;
  struct InputAssign_AssignData_array *v193;
  struct InputAssign_AssignCode_array *v195;
  struct InputAssign_AssignData_array *v197;
  struct InputAssign_AssignCode_array *v199;
  struct InputAssign_AssignData_array *v201;
  struct InputAssign_AssignCode_array *v203;
  struct InputAssign_AssignData_array *v205;

  if (controllerID < 4)
  {
    assignData = this->_assignData;
    data = assignData->m_Items[controllerID]->data;
    data->m_Items[0] = 2;
    v8 = this->_assignData;
    v10 = v8->m_Items[controllerID]->data;
    v10->m_Items[1] = 3;
    v12 = this->_assignData;
    v14 = v12->m_Items[controllerID]->data;
    v14->m_Items[2] = 4;
    v16 = this->_assignData;
    v18 = v16->m_Items[controllerID]->data;
    v18->m_Items[3] = 5;
    v20 = this->_assignData;
    v22 = v20->m_Items[controllerID]->data;
    v22->m_Items[5] = 6;
    v24 = this->_assignData;
    v26 = v24->m_Items[controllerID]->data;
    v26->m_Items[4] = 7;
    v28 = this->_assignData;
    v30 = v28->m_Items[controllerID]->data;
    v30->m_Items[6] = 9;
    v32 = this->_assignData;
    v34 = v32->m_Items[controllerID]->data;
    v34->m_Items[15] = 8;
    v36 = this->_assignData;
    v38 = v36->m_Items[controllerID]->data;
    v38->m_Items[7] = 22;
    v40 = this->_assignData;
    v42 = v40->m_Items[controllerID]->data;
    v42->m_Items[8] = 23;
    v44 = this->_assignData;
    v46 = v44->m_Items[controllerID]->data;
    v46->m_Items[9] = 24;
    v48 = this->_assignData;
    v50 = v48->m_Items[controllerID]->data;
    v50->m_Items[10] = 25;
    v52 = this->_assignData;
    v54 = v52->m_Items[controllerID]->data;
    v54->m_Items[11] = 1;
    v56 = this->_assignData;
    v58 = v56->m_Items[controllerID]->data;
    v58->m_Items[12] = 1;
    v60 = this->_assignData;
    v62 = v60->m_Items[controllerID]->data;
    v62->m_Items[13] = 1;
    v64 = this->_assignData;
    v66 = v64->m_Items[controllerID]->data;
    v66->m_Items[14] = 1;
    v68 = this->_assignData;
    v70 = v68->m_Items[controllerID]->data;
    v70->m_Items[17] = 10;
    v72 = this->_assignData;
    v74 = v72->m_Items[controllerID]->data;
    v76 = 11;
LABEL_75:
    v74->m_Items[16] = v76;
    return;
  }
  if (controllerID == 4)
  {
    v137 = this->_assignData;
    v139 = v137->m_Items[4]->data;
    v139->m_Items[2] = 72;
    v141 = this->_assignData;
    v143 = v141->m_Items[4]->data;
    v143->m_Items[3] = 61;
    v145 = this->_assignData;
    v147 = v145->m_Items[4]->data;
    v147->m_Items[0] = 73;
    v149 = this->_assignData;
    v151 = v149->m_Items[4]->data;
    v151->m_Items[1] = 74;
    v153 = this->_assignData;
    v155 = v153->m_Items[4]->data;
    v155->m_Items[5] = 60;
    v157 = this->_assignData;
    v159 = v157->m_Items[4]->data;
    v159->m_Items[4] = 62;
    v161 = this->_assignData;
    v163 = v161->m_Items[4]->data;
    v163->m_Items[6] = 87;
    v165 = this->_assignData;
    v167 = v165->m_Items[4]->data;
    v167->m_Items[15] = 86;
    v169 = this->_assignData;
    v171 = v169->m_Items[4]->data;
    v171->m_Items[7] = 107;
    v173 = this->_assignData;
    v175 = v173->m_Items[4]->data;
    v175->m_Items[8] = 108;
    v177 = this->_assignData;
    v179 = v177->m_Items[4]->data;
    v179->m_Items[9] = 109;
    v181 = this->_assignData;
    v183 = v181->m_Items[4]->data;
    v183->m_Items[10] = 110;
    v185 = this->_assignData;
    v187 = v185->m_Items[4]->data;
    v187->m_Items[11] = 1;
    v189 = this->_assignData;
    v191 = v189->m_Items[4]->data;
    v191->m_Items[12] = 1;
    v193 = this->_assignData;
    v195 = v193->m_Items[4]->data;
    v195->m_Items[13] = 1;
    v197 = this->_assignData;
    v199 = v197->m_Items[4]->data;
    v199->m_Items[14] = 1;
    v201 = this->_assignData;
    v203 = v201->m_Items[4]->data;
    v203->m_Items[17] = 59;
    v205 = this->_assignData;
    v74 = v205->m_Items[4]->data;
    v76 = 63;
    goto LABEL_75;
  }
  if (controllerID == 5)
  {
    v77 = this->_assignData;
    v79 = v77->m_Items[5]->data;
    v79->m_Items[2] = 102;
    v81 = this->_assignData;
    v83 = v81->m_Items[5]->data;
    v83->m_Items[3] = 104;
    v85 = this->_assignData;
    v87 = v85->m_Items[5]->data;
    v87->m_Items[0] = 110;
    v89 = this->_assignData;
    v91 = v89->m_Items[5]->data;
    v91->m_Items[1] = 109;
    v93 = this->_assignData;
    v95 = v93->m_Items[5]->data;
    v95->m_Items[5] = 95;
    v97 = this->_assignData;
    v99 = v97->m_Items[5]->data;
    v99->m_Items[4] = 107;
    v101 = this->_assignData;
    v103 = v101->m_Items[5]->data;
    v103->m_Items[6] = 128;
    v105 = this->_assignData;
    v107 = v105->m_Items[5]->data;
    v107->m_Items[7] = 68;
    v109 = this->_assignData;
    v111 = v109->m_Items[5]->data;
    v111->m_Items[8] = 92;
    v113 = this->_assignData;
    v115 = v113->m_Items[5]->data;
    v115->m_Items[9] = 79;
    v117 = this->_assignData;
    v119 = v117->m_Items[5]->data;
    v119->m_Items[10] = 80;
    v121 = this->_assignData;
    v123 = v121->m_Items[5]->data;
    v123->m_Items[11] = 67;
    v125 = this->_assignData;
    v127 = v125->m_Items[5]->data;
    v127->m_Items[12] = 91;
    v129 = this->_assignData;
    v131 = v129->m_Items[5]->data;
    v131->m_Items[13] = 93;
    v133 = this->_assignData;
    v135 = v133->m_Items[5]->data;
    v135->m_Items[14] = 69;
  }
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
  struct GlobalData_PadConfig_array *v114;
  s16 CONTROLER_TYPE_KEYBOAD;

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
    v114 = system_save.padconfig;
    if (LODWORD(v114->max_length) > id)
      goto LABEL_106;
LABEL_105:
  }
  v114 = system_save.padconfig;
  CONTROLER_TYPE_KEYBOAD = CONTROLER_TYPE_GAMEPAD;
  if (LODWORD(v114->max_length) <= id)
    goto LABEL_105;
LABEL_106:
  v114->m_Items[id].type = CONTROLER_TYPE_KEYBOAD;
}

// 0x114f000
void SetInputAssign_FromSaveData(InputAssign *this) {
  u64 v4;
  InputAssign_Fields *p_fields;
  s64 v6;
  struct InputAssign_AssignCode_array *data;
  struct GlobalData_PadConfig_array *padconfig;
  s32 v12;
  struct InputAssign_AssignCode_array *v15;
  struct GlobalData_PadConfig_array *v16;
  s32 v18;
  struct InputAssign_AssignCode_array *v21;
  struct GlobalData_PadConfig_array *v22;
  s32 v24;
  struct InputAssign_AssignCode_array *v27;
  struct GlobalData_PadConfig_array *v28;
  s32 v30;
  struct InputAssign_AssignCode_array *v33;
  struct GlobalData_PadConfig_array *v34;
  s32 v36;
  struct InputAssign_AssignCode_array *v39;
  struct GlobalData_PadConfig_array *v40;
  s32 v42;
  struct InputAssign_AssignCode_array *v45;
  struct GlobalData_PadConfig_array *v46;
  s32 v48;
  struct InputAssign_AssignCode_array *v51;
  struct GlobalData_PadConfig_array *v52;
  s32 v54;
  struct InputAssign_AssignCode_array *v57;
  struct GlobalData_PadConfig_array *v58;
  s32 v60;
  struct InputAssign_AssignCode_array *v63;
  struct GlobalData_PadConfig_array *v64;
  s32 v66;
  struct InputAssign_AssignCode_array *v69;
  struct GlobalData_PadConfig_array *v70;
  s32 v72;
  struct InputAssign_AssignCode_array *v75;
  struct GlobalData_PadConfig_array *v76;
  s32 v78;
  struct InputAssign_AssignCode_array *v81;
  struct GlobalData_PadConfig_array *v82;
  s32 v84;
  struct InputAssign_AssignCode_array *v87;
  struct GlobalData_PadConfig_array *v88;
  s32 v90;
  struct InputAssign_AssignCode_array *v93;
  struct GlobalData_PadConfig_array *v94;
  s32 v96;
  u64 v97;
  struct InputAssign_AssignCode_array *v100;
  struct GlobalData_PadConfig_array *v101;
  s32 v103;
  struct InputAssign_AssignCode_array *v106;
  struct GlobalData_PadConfig_array *v107;
  s32 v109;
  struct InputAssign_AssignCode_array *v112;
  struct GlobalData_PadConfig_array *v113;
  s32 v115;
  struct InputAssign_AssignCode_array *v118;
  struct GlobalData_PadConfig_array *v119;
  s32 v121;
  struct InputAssign_AssignCode_array *v124;
  struct GlobalData_PadConfig_array *v125;
  s32 v127;
  struct InputAssign_AssignCode_array *v130;
  struct GlobalData_PadConfig_array *v131;
  s32 v133;
  struct InputAssign_AssignCode_array *v136;
  struct GlobalData_PadConfig_array *v137;
  s32 v139;
  struct InputAssign_AssignCode_array *v142;
  struct GlobalData_PadConfig_array *v143;
  s32 v145;
  struct InputAssign_AssignCode_array *v148;
  struct GlobalData_PadConfig_array *v149;
  s32 v151;
  struct InputAssign_AssignCode_array *v154;
  struct GlobalData_PadConfig_array *v155;
  s32 v157;
  struct InputAssign_AssignCode_array *v160;
  struct GlobalData_PadConfig_array *v161;
  s32 v163;
  struct InputAssign_AssignCode_array *v166;
  struct GlobalData_PadConfig_array *v167;
  s32 v169;
  struct InputAssign_AssignCode_array *v172;
  struct GlobalData_PadConfig_array *v173;
  s32 v175;
  struct InputAssign_AssignCode_array *v178;
  struct GlobalData_PadConfig_array *v179;
  s32 v181;
  struct InputAssign_AssignCode_array *v184;
  struct GlobalData_PadConfig_array *v185;
  s32 v187;

  Log("InputAssign Load FromSavData ", 0);
  v4 = 0;
  p_fields = &this->fields;
  v6 = 100;
  do
  {
    data = p_fields->_assignData->m_Items[v4]->data;
    padconfig = system_save.padconfig;
    v12 = *(padconfig + v6 - 68);
    data->m_Items[0] = v12;
    v15 = p_fields->_assignData->m_Items[v4]->data;
    v16 = system_save.padconfig;
    v18 = *(v16 + v6 - 66);
    v15->m_Items[1] = v18;
    v21 = p_fields->_assignData->m_Items[v4]->data;
    v22 = system_save.padconfig;
    v24 = *(v22 + v6 - 64);
    v21->m_Items[2] = v24;
    v27 = p_fields->_assignData->m_Items[v4]->data;
    v28 = system_save.padconfig;
    v30 = *(v28 + v6 - 62);
    v27->m_Items[3] = v30;
    v33 = p_fields->_assignData->m_Items[v4]->data;
    v34 = system_save.padconfig;
    v36 = *(v34 + v6 - 60);
    v33->m_Items[4] = v36;
    v39 = p_fields->_assignData->m_Items[v4]->data;
    v40 = system_save.padconfig;
    v42 = *(v40 + v6 - 58);
    v39->m_Items[5] = v42;
    v45 = p_fields->_assignData->m_Items[v4]->data;
    v46 = system_save.padconfig;
    v48 = *(v46 + v6 - 56);
    v45->m_Items[6] = v48;
    v51 = p_fields->_assignData->m_Items[v4]->data;
    v52 = system_save.padconfig;
    v54 = *(v52 + v6 - 54);
    v51->m_Items[7] = v54;
    v57 = p_fields->_assignData->m_Items[v4]->data;
    v58 = system_save.padconfig;
    v60 = *(v58 + v6 - 52);
    v57->m_Items[8] = v60;
    v63 = p_fields->_assignData->m_Items[v4]->data;
    v64 = system_save.padconfig;
    v66 = *(v64 + v6 - 50);
    v63->m_Items[9] = v66;
    v69 = p_fields->_assignData->m_Items[v4]->data;
    v70 = system_save.padconfig;
    v72 = *(v70 + v6 - 48);
    v69->m_Items[10] = v72;
    v75 = p_fields->_assignData->m_Items[v4]->data;
    v76 = system_save.padconfig;
    v78 = *(v76 + v6 - 46);
    v75->m_Items[11] = v78;
    v81 = p_fields->_assignData->m_Items[v4]->data;
    v82 = system_save.padconfig;
    v84 = *(v82 + v6 - 44);
    v81->m_Items[12] = v84;
    v87 = p_fields->_assignData->m_Items[v4]->data;
    v88 = system_save.padconfig;
    v90 = *(v88 + v6 - 42);
    v87->m_Items[13] = v90;
    v93 = p_fields->_assignData->m_Items[v4]->data;
    v94 = system_save.padconfig;
    v96 = *(v94 + v6 - 40);
    v97 = v4 + 1;
    v93->m_Items[14] = v96;
    v100 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v101 = system_save.padconfig;
    v103 = *(v101 + v6 - 28);
    v100->m_Items[0] = v103;
    v106 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v107 = system_save.padconfig;
    v109 = *(v107 + v6 - 26);
    v106->m_Items[1] = v109;
    v112 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v113 = system_save.padconfig;
    v115 = *(v113 + v6 - 24);
    v112->m_Items[2] = v115;
    v118 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v119 = system_save.padconfig;
    v121 = *(v119 + v6 - 22);
    v118->m_Items[3] = v121;
    v124 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v125 = system_save.padconfig;
    v127 = *(v125 + v6 - 20);
    v124->m_Items[4] = v127;
    v130 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v131 = system_save.padconfig;
    v133 = *(v131 + v6 - 18);
    v130->m_Items[5] = v133;
    v136 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v137 = system_save.padconfig;
    v139 = *(v137 + v6 - 16);
    v136->m_Items[6] = v139;
    v142 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v143 = system_save.padconfig;
    v145 = *(v143 + v6 - 14);
    v142->m_Items[7] = v145;
    v148 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v149 = system_save.padconfig;
    v151 = *(v149 + v6 - 12);
    v148->m_Items[8] = v151;
    v154 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v155 = system_save.padconfig;
    v157 = *(v155 + v6 - 10);
    v154->m_Items[9] = v157;
    v160 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v161 = system_save.padconfig;
    v163 = *(v161 + v6 - 8);
    v160->m_Items[10] = v163;
    v166 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v167 = system_save.padconfig;
    v169 = *(v167 + v6 - 6);
    v166->m_Items[11] = v169;
    v172 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v173 = system_save.padconfig;
    v175 = *(v173 + v6 - 4);
    v172->m_Items[12] = v175;
    v178 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v179 = system_save.padconfig;
    v181 = *(v179 + v6 - 2);
    v178->m_Items[13] = v181;
    v184 = p_fields->_assignData->m_Items[v4 + 1]->data;
    v185 = system_save.padconfig;
    v187 = *(&v185->obj.klass + v6);
    v4 += 2LL;
    v6 += 80;
    v184->m_Items[14] = v187;
  }
  while (v4 != 8);
}
