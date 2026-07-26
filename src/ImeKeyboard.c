#include "types.h"

typedef struct ImeKeyboard ImeKeyboard;
typedef struct SwitchIME SwitchIME;

void MojiInput(void);
void OpenIME(SwitchIME *this, char *titleText, char *initText, s32 maxLength, s32 lang, s32 minLength);

// 0x1148df0
void CloseIMECallback(ImeKeyboard *this) {
  Il2CppObject *v3;

  v3 = StringLiteral_4915;
  Log(v3, 0);
  this->_IsOpenIME_k__BackingField = 0;
}

// 0x1149040
void InputCallbackAbort(ImeKeyboard *this, char *text) {
  Il2CppObject *v6;

  v6 = Concat_5221536(StringLiteral_4918, text, StringLiteral_441);
  Log(v6, 0);
  this->_IsCancel_k__BackingField = 1;
}

// 0x1148f90
void InputCallbackCancel(ImeKeyboard *this, char *text) {
  Il2CppObject *v4;

  v4 = StringLiteral_4917;
  Log(v4, 0);
  this->_IsCancel_k__BackingField = 1;
}

// 0x1148ea0
void InputCallbackOK(ImeKeyboard *this, char *text) {
  Il2CppObject *v6;

  v6 = Concat_5221536(StringLiteral_4916, text, StringLiteral_441);
  Log(v6, 0);
  this->_InputText_k__BackingField = text;
  MojiInput();
}

// 0x1148c70
void Log(ImeKeyboard *this, char *log) {
  Log(log, 0);
}

// 0x1148dc0
void OpenIME(ImeKeyboard *this, char *titleText, char *initText, s32 maxLength, s32 lang) {
  SwitchIME_o *imeObj;

  imeObj = this->imeObj;
  if (imeObj)
  {
    *&this->_IsOpenIME_k__BackingField = 1;
    OpenIME(imeObj, titleText, initText, maxLength, lang, 1, 0);
  }
}

// 0x1148d40
void Start(ImeKeyboard *this) {
  u64 *v3;

  *&this->_IsOpenIME_k__BackingField = 0;
  this->_InputText_k__BackingField = 0;
  v3 = Allocate(SwitchIME);
  _ctor(v3, this, 0);
  this->imeObj = v3;
}

// 0x1148db0
void Update(ImeKeyboard *this) {
  ;
}
