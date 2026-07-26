#include "types.h"

typedef struct ImeKeyboard ImeKeyboard;
typedef struct SwitchIME SwitchIME;

struct SwitchIME {
    void showKeyboardArg;
};

static ImeKeyboard *imeKeyObj;
static char *Nme_LocalID;
static char *Nme_LocalID2;
static bool NmeChack;
static bool MojiChack;
static u16 NmeBup[8];

void ChackSign(char *input);
void CloseIMECallback(ImeKeyboard *this);
char *GetLocalizeText(char *ID);
void InputCallbackCancel(ImeKeyboard *this, char *text);
void InputCallbackOK(ImeKeyboard *this, char *text);
s32 _TextCheckCallbackImpl(intptr_t textBuf, s64 *length, char *input, void *encoding);

// 0x13405e0
void ChackSign(char *input) {
  u64 v4;
  struct System_Char_array *NmeBup;
  u16 Chars;
  char *v9;

  if (get_Length(input) >= 1)
  {
    v4 = 0;
    do
    {
      Chars = get_Chars(input, v4);
      v9 = NmeBup + 2 * v4++;
      *(v9 + 16) = Chars;
    }
    while (v4 < get_Length(input));
  }
}

// 0x1340010
void Log(SwitchIME *this, char *log) {
  Log(log, 0);
}

// 0x1340120
void OpenIME(SwitchIME *this, char *titleText, char *initText, s32 maxLength, s32 lang, s32 minLength) {
    InputCallbackCancel(0, 0);
    CloseIMECallback(0);
}

// 0x133fbe0
s32 TextCheckCallback(intptr_t textBuf, s64 *length, void *str) {
  System_Byte_array *v8;
  s64 bufSize;
  intptr_t ptr;
  il2cpp_array_size_t max_length;
  u64 v12;
  System_Text_Encoding_o *Unicode;
  System_String_o *v16;
  bool v18;
  char v20;
  System_Text_Encoding_o *v23;

  v8 = NewSpecific(byte, LODWORD(str->bufSize));
  ptr = str->ptr;
  bufSize = str->bufSize;
  {
  }
  Copy_1551888(ptr, v8, 0, bufSize);
  max_length = v8->max_length;
  if (max_length < 1)
  {
    LODWORD(v12) = 0;
  }
  else
  {
    v12 = 0;
    while (1)
    {
      if (!v8->m_Items[v12])
      {
        if (!v8->m_Items[v12 + 1])
          break;
      }
      v12 += 2LL;
      LODWORD(max_length) = v8->max_length;
      if (v12 >= max_length)
    }
  }
  Unicode = get_Unicode();
  v16 = (Unicode->klass[1]._1.this_arg.data)(Unicode, v8, 0, v12, *&Unicode->klass[1]._1.this_arg.bits);
  v18 = op_Equality(v16, Empty, 0);
  if (v18)
  {
    v20 = 1;
  }
  else
  {
    v20 = 0;
  }
  MojiChack = v20;
  v23 = get_Unicode();
  return _TextCheckCallbackImpl(textBuf, length, v16, v23);
}

// 0x133fe40
s32 TextCheckCallbackUtf8(intptr_t textBuf, s64 *length, void *str) {
  System_Byte_array *v8;
  s64 bufSize;
  intptr_t ptr;
  il2cpp_array_size_t max_length;
  u64 v12;
  System_Text_Encoding_o *UTF8;
  System_String_o *v15;
  bool v17;
  char v19;
  System_Text_Encoding_o *v22;

  v8 = NewSpecific(byte, LODWORD(str->bufSize));
  ptr = str->ptr;
  bufSize = str->bufSize;
  {
  }
  Copy_1551888(ptr, v8, 0, bufSize);
  max_length = v8->max_length;
  if (max_length < 1)
  {
    LODWORD(v12) = 0;
  }
  else
  {
    v12 = 0;
    while (1)
    {
      if (!v8->m_Items[v12])
        break;
      LODWORD(max_length) = v8->max_length;
      if (++v12 >= max_length)
    }
  }
  UTF8 = get_UTF8();
  v15 = (UTF8->klass[1]._1.this_arg.data)(UTF8, v8, 0, v12, *&UTF8->klass[1]._1.this_arg.bits);
  v17 = op_Equality(v15, Empty, 0);
  if (v17)
  {
    v19 = 1;
  }
  else
  {
    v19 = 0;
  }
  MojiChack = v19;
  v22 = get_UTF8();
  return _TextCheckCallbackImpl(textBuf, length, v15, v22);
}

// 0x1340360
s32 _TextCheckCallbackImpl(intptr_t textBuf, s64 *length, char *input, void *encoding) {
  bool v10;
  System_String_o *Nme_LocalID;
  struct SwitchIME_StaticFields **p_static_fields;
  struct SwitchIME_StaticFields *static_fields;
  System_String_o *LocalizeText;
  System_String_o *v17;
  s64 v19;
  s64 v22;

  ChackSign(input, length);
  v10 = op_Equality(input, Empty, 0);

  {
    p_static_fields = &SwitchIME->static_fields;
    static_fields = SwitchIME->static_fields;
    if (static_fields->NmeChack)
    {
      static_fields->NmeChack = 0;
      Nme_LocalID = (*p_static_fields)->Nme_LocalID2;
      LocalizeText = GetLocalizeText(Nme_LocalID);
      v17 = Concat_5224608(LocalizeText, StringLiteral_859);
      v19 = (encoding->klass->vtable._28_GetBytes.methodPtr)(encoding, v17, encoding->klass->vtable._28_GetBytes.method);
      {
      }
      Copy(v19, 0, textBuf, *(v19 + 24), 0);
      *length = *(v19 + 24);
      return 1;
    }
  }
  v22 = (encoding->klass->vtable._28_GetBytes.methodPtr)(
          encoding,
          StringLiteral_859,
          encoding->klass->vtable._28_GetBytes.method);
  {
  }
  Copy(v22, 0, textBuf, *(v22 + 24), 0);
  *length = *(v22 + 24);
  InputCallbackOK(imeKeyObj, input);
  return 0;
}
