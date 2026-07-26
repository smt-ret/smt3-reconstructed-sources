#include "types.h"

typedef struct TextEffect TextEffect;
typedef struct TextManager TextManager;
typedef struct TextManager_FONTTYPE TextManager_FONTTYPE;
typedef struct TextManager_GOParam TextManager_GOParam;
typedef struct _FRQ _FRQ;

struct TextManager_GOParam {
    void *gameobject;
    void *transform;
    void *recttransform;
    void *text;
    void *outline;
    TextEffect *txteff;
};

struct TextManager_FONTTYPE {
    s32 value__;
};

static char convert_tb[UNKNOWN_ARRAY_SIZE];
static char *upper_list[2];

char *ColorToString(TextManager *this, sdfColor_t col);
char *ConvertChar(TextManager *this, u16 data);
char *ConvertText(TextManager *this, char *itxt, sdfColor_t col);
void load_converttable(TextManager *this);
void setdata(TextManager *this, f32 x, f32 y, f32 z, sdfColor_t msgcol, char *text, _FRQ *frq);

// 0x1346a30
sdfColor_t AddColor(TextManager *this, u32 src, u32 dst) {
    return (sdfColor_t){0};
}

// 0x1345660
void Awake(TextManager *this) {
}

// 0x1346aa0
void Clear(TextManager *this) {
  this->clear_item = 1;
}

// 0x1346e80
char *ColorToString(TextManager *this, sdfColor_t col) {
    return 0;
}

// 0x13470a0
char *ConvertChar(TextManager *this, u16 data) {
    load_converttable(0);
    return 0;
}

// 0x1346c40
char *ConvertText(TextManager *this, char *itxt, sdfColor_t col) {
    ColorToString(0, (sdfColor_t){0});
    return 0;
}

// 0x1346bb0
void Draw(TextManager *this, f32 x, f32 y, sdfColor_t col, char *text) {
  System_String_o *v9;
  UnityEngine_Color_o white;

  v9 = ConvertText(this, text, col);
  white = get_white();
  setdata(this, x, y, 0.0, white, v9, 0);
}

// 0x1346df0
void Draw_20213232(TextManager *this, f32 x, f32 y, f32 z, char *text, _FRQ *frq) {
  UnityEngine_Color_o white;

  white = get_white();
  setdata(this, x, y, z, white, text, frq);
}

// 0x1346f70
void Draw_20213616(TextManager *this, _FRQ *frq) {
  System_String_o *v5;
  struct _FRQ_o *head;
  s32 strlen;
  s32 y;
  s32 x;
  struct _TEXT_o **p_str;
  struct _TEXT_o *v11;
  System_String_o *v12;
  UnityEngine_Color_o white;

  if (frq)
  {
    v5 = StringLiteral_416;
    head = frq->head;
    strlen = head->strlen;
    x = head->x;
    y = head->y;
    if (strlen >= 1)
    {
      p_str = &head->str;
      do
      {
        v11 = *p_str;
        v12 = ConvertChar(this, (*p_str)->code);
        v5 = Concat_5224608(v5, v12);
        p_str = &v11->next;
        --strlen;
      }
      while (strlen);
    }
    white = get_white();
    setdata(this, (x >> 4), (y >> 3), 0.0, white, v5, frq);
  }
}

// 0x1346ac0
sdfVector2_t GetFontSize(TextManager *this, s32 no) {
    return (sdfVector2_t){0};
}

// 0x1345d70
void LateUpdate(TextManager *this) {
  struct System_Collections_Generic_List_TextManager_GOParam__array *game_objects;
  s32 Count;
  s32 v6;
  struct System_Collections_Generic_List_TextManager_GOParam__array *v7;
  System_Collections_Generic_List_TextManager_GOParam__o *v9;
  UnityEngine_Object_o *gameobject;
  struct System_Collections_Generic_List_TextManager_GOParam__array *v12;
  s32 v14;
  s32 v15;
  struct System_Collections_Generic_List_TextManager_GOParam__array *v16;
  System_Collections_Generic_List_TextManager_GOParam__o *v18;
  UnityEngine_Object_o *v20;
  struct System_Collections_Generic_List_TextManager_GOParam__array *v21;
  s32 v23;
  s32 v24;
  struct System_Collections_Generic_List_TextManager_GOParam__array *v25;
  System_Collections_Generic_List_TextManager_GOParam__o *v27;
  UnityEngine_Object_o *v29;
  struct System_Collections_Generic_List_TextManager_GOParam__array *v30;
  s32 v32;
  s32 v33;
  struct System_Collections_Generic_List_TextManager_GOParam__array *v34;
  System_Collections_Generic_List_TextManager_GOParam__o *v36;
  UnityEngine_Object_o *v38;
  struct System_Collections_Generic_List_TextManager_GOParam__array *v39;
  s32 v41;
  s32 v42;
  struct System_Collections_Generic_List_TextManager_GOParam__array *v43;
  System_Collections_Generic_List_TextManager_GOParam__o *v45;
  UnityEngine_Object_o *v47;
  u64 i;
  struct System_Collections_Generic_List_TextManager_GOParam__array *v54;
  s32 v56;
  struct System_Int32_array *msgcount;
  s32 v58;
  s32 v60;
  struct System_Collections_Generic_List_TextManager_GOParam__array *v61;
  struct System_Int32_array *v63;
  char *v65;
  TextManager_GOParam_o obj;

  if (this->clear_item)
  {
    game_objects = this->game_objects;
    Count = _get_Count(game_objects->m_Items[0]);
    v6 = 0;
    v7 = this->game_objects;
    while (1)
    {
      v9 = v7->m_Items[0];
      if (v6 >= Count)
        break;
      _get_Item(
        &obj,
        v9,
        v6);
      gameobject = obj.gameobject;
      Destroy_27360000(gameobject);
      ++v6;
      v7 = this->game_objects;
      if (!LODWORD(v7->max_length))
    }
    _Clear(v9);
    v12 = this->game_objects;
    v14 = _get_Count(v12->m_Items[1]);
    v15 = 0;
    v16 = this->game_objects;
    while (1)
    {
      v18 = v16->m_Items[1];
      if (v15 >= v14)
        break;
      _get_Item(
        &obj,
        v18,
        v15);
      v20 = obj.gameobject;
      Destroy_27360000(v20);
      ++v15;
      v16 = this->game_objects;
      if ((v16->max_length & 0xFFFFFFFE) == 0)
    }
    _Clear(v18);
    v21 = this->game_objects;
    v23 = _get_Count(v21->m_Items[2]);
    v24 = 0;
    v25 = this->game_objects;
    while (1)
    {
      v27 = v25->m_Items[2];
      if (v24 >= v23)
        break;
      _get_Item(
        &obj,
        v27,
        v24);
      v29 = obj.gameobject;
      Destroy_27360000(v29);
      ++v24;
      v25 = this->game_objects;
      if (LODWORD(v25->max_length) <= 2uLL)
    }
    _Clear(v27);
    v30 = this->game_objects;
    v32 = _get_Count(v30->m_Items[3]);
    v33 = 0;
    v34 = this->game_objects;
    while (1)
    {
      v36 = v34->m_Items[3];
      if (v33 >= v32)
        break;
      _get_Item(
        &obj,
        v36,
        v33);
      v38 = obj.gameobject;
      Destroy_27360000(v38);
      ++v33;
      v34 = this->game_objects;
      if ((v34->max_length & 0xFFFFFFFC) == 0)
    }
    _Clear(v36);
    v39 = this->game_objects;
    v41 = _get_Count(v39->m_Items[4]);
    v42 = 0;
    v43 = this->game_objects;
    while (1)
    {
      v45 = v43->m_Items[4];
      if (v42 >= v41)
        break;
      _get_Item(
        &obj,
        v45,
        v42);
      v47 = obj.gameobject;
      Destroy_27360000(v47);
      ++v42;
      v43 = this->game_objects;
      if (LODWORD(v43->max_length) <= 4uLL)
    }
    _Clear(v45);
    add_gameobject(&obj, this, 0, 0);
    add_gameobject(&obj, this, 0, 1);
    add_gameobject(&obj, this, 0, 2);
    add_gameobject(&obj, this, 0, 3);
    add_gameobject(&obj, this, 0, 4);
    this->clear_item = 0;
  }
  else
  {
    for (i = 0; i != 5; ++i)
    {
      v54 = this->game_objects;
      v56 = _get_Count(v54->m_Items[i]);
      msgcount = this->msgcount;
      v58 = v56;
      v60 = msgcount->m_Items[i];
      if (v60 < v56)
      {
        do
        {
          v61 = this->game_objects;
          _get_Item(
            &obj,
            v61->m_Items[i],
            v60);
          SetActive(obj.gameobject, 0, 0);
          ++v60;
        }
        while (v58 != v60);
      }
      v63 = this->msgcount;
      v65 = v63 + 4 * i;
      *(v65 + 8) = 0;
    }
  }
}

// 0x1346ab0
void SetLanguage(TextManager *this, s32 lang, void *font) {
  ;
}

// 0x1345d30
void Start(TextManager *this) {
  set_overrideSorting(this->canv, 1);
  set_sortingOrder(this->canv, 0x4000);
}

// 0x1346810
sdfColor_t ToColor(TextManager *this, u32 col, u32 dst) {
    return (sdfColor_t){0};
}

// 0x13469c0
sdfColor_t ToDark(TextManager *this, sdfColor_t col, f32 mul) {
    return (sdfColor_t){0};
}

// 0x1347af0
char *ToZenkaku(char *istr) {
    return 0;
}

// 0x13476e0
u8 **UnicodeToIndexByte(TextManager *this, char *str) {
  System_Byte_array *v6;
  u64 *v7;
  s32 Length;
  s32 i;
  System_String_o *v11;
  u16 Chars;
  s32 v15;
  s16 v16;
  u32 Count;

  if (!convert_tb)
  if (IsNullOrEmpty(str))
    return this->dmytext;
  v7 = Allocate(System_Collections_Generic_List_byte_);
  __ctor(v7);
  Length = get_Length(str);
  if (Length >= 1)
  {
    for (i = 0; i != Length; ++i)
    {
      while (1)
      {
        v11 = Substring_5248048(str, i, 1);
        Chars = get_Chars(v11, 0);
        if (Chars > 0x7Fu)
          break;
        _Add(v7, Chars);
        if (Length == ++i)
      }
      v15 = IndexOf_string_(convert_tb, v11);
      if (v15 == -1)
        v16 = -32640;
      else
        v16 = (2 * v15) & 0x1F00 | v15 & 0x7F | 0x8080;
      _Add(v7, HIBYTE(v16));
      _Add(v7, v16);
    }
  }
  _Add(v7, 0);
  _Add(v7, 0);
  Count = _get_Count(v7);
  v6 = NewSpecific(byte, Count);
  _CopyTo(v7, v6);
  return v6;
}

// 0x13476a0
u8 **UnicodeToIndexByte2(TextManager *this, char *str) {
  System_Text_Encoding_o *Unicode;

  Unicode = get_Unicode();
  return (Unicode->klass->vtable._28_GetBytes.methodPtr)(Unicode, str, Unicode->klass->vtable._28_GetBytes.method);
}

// 0x1347950
u16 frwExchgStyle(TextManager *this, u16 code) {
  TextManager_c *v4;
  u64 *v5;
  u32 v6;
  u64 *v7;
  System_Text_Encoding_o *Unicode;
  System_String_o *v11;
  u32 v13;

  if (!convert_tb)
    load_converttable(v4, code);
  v5 = NewSpecific(byte, 3u);
  v6 = *(v5 + 6);
  v7 = v5;
  *(v5 + 32) = HIBYTE(code);
  *(v5 + 33) = code;
  *(v5 + 34) = 0;
  Unicode = get_Unicode();
  v11 = (Unicode->klass[1]._1.byval_arg.data)(Unicode, v7, *&Unicode->klass[1]._1.byval_arg.bits);
  v13 = IndexOf_string_(convert_tb, v11);
  if (v13 == -1)
    return -1;
  else
    return v13 & 0x7F | (((v13 >> 7) & 0xF) << 8) | 0x8080;
}

// 0x1347370
void load_converttable(TextManager *this) {
  u64 *v2;
  UnityEngine_Object_o *v3;
  s64 typeHierarchyDepth;
  System_Byte_array *bytes;
  System_Text_Encoding_o *Unicode;
  System_String_o *v7;
  System_String_array *v8;
  System_String_array *v10;
  il2cpp_array_size_t max_length;
  System_String_array *v12;
  s64 v13;
  System_String_o *v15;
  u64 *v16;
  System_String_array *v18;
  il2cpp_array_size_t v19;
  System_String_array *v20;
  s64 v21;
  s64 v23;
  u32 Count;
  struct System_String_array *v26;
  System_TimeZoneInfo_AdjustmentRule_array *v28;
  System_Array_o *convert_tb;
  System_Array_o *v30;
  s32 v31;

  v2 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v2);
  v3 = Load(StringLiteral_12218, 0);
  if (v3)
  {
    if (v3->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
    {
      if (v3->klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_TextAsset)
        v3 = 0;
    }
    else
    {
      v3 = 0;
    }
  }
  bytes = get_bytes(v3);
  Unicode = get_Unicode();
  v7 = (Unicode->klass[1]._1.byval_arg.data)(Unicode, bytes, *&Unicode->klass[1]._1.byval_arg.bits);
  v8 = NewSpecific(string, 1u);
  v8->m_Items[0] = StringLiteral_489;
  v10 = Split_5246672(v7, v8, 0);
  max_length = v10->max_length;
  if (max_length >= 2)
  {
    v12 = v10;
    v13 = 0;
    do
    {
      v15 = v12->m_Items[v13];
      v16 = NewSpecific(char, 1u);
      *(v16 + 16) = 44;
      v18 = Split(v15, v16);
      v19 = v18->max_length;
      if (v19 >= 2)
      {
        v20 = v18;
        v21 = 5;
        do
        {
          _Add(
            v2,
            *(&v20->obj.klass + v21));
          LODWORD(v19) = v20->max_length;
          v23 = v21 - 3;
          ++v21;
        }
        while (v23 < v19);
      }
      max_length = LODWORD(v12->max_length);
      ++v13;
    }
    while (v13 < ((max_length << 32) - 0x100000000LL) >> 32);
  }
  Count = _get_Count(v2);
  v26 = NewSpecific(string, Count);
  convert_tb = v26;
  v28 = _ToArray(v2);
  v30 = v28;
  v31 = _get_Count(v2);
  Copy_3886320(v30, convert_tb, v31);
}

// 0x1346310
void setdata(TextManager *this, f32 x, f32 y, f32 z, sdfColor_t msgcol, char *text, _FRQ *frq) {
}
