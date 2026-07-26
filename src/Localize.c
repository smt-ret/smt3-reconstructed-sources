#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct EventEMsgData EventEMsgData;
typedef struct Localize_EvtMsgDat Localize_EvtMsgDat;

struct Localize_EvtMsgDat {
    char *name;
    EventEMsgData *table;
    void *data;
};

static void *DataList;
static s32 LangID;
static char *strLanguage;
static char *LangTagTable[8];
static char *PlatformTagTable[3];
static s32 PlatformID;
static char *RaceTable[17];
static char *ActionTable[4];

s32 ContainsIndex(char *name);
char *GetAppendix(void);
char *GetPlatformStr(void);
bool IsFileExists(AssetBundleCtrl *this, char *key, char *path_name);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void *LoadAsset(AssetBundleCtrl *this, char *key, char *path, char *name);
void LoadCommonData(void);
void *LoadFile(AssetBundleCtrl *this, char *key, char *path, char *name, char *extension);
void LoadLocalizeText(char *key, char *filename);
void Remove(char *key);

// 0x1290ec0
s32 ContainsIndex(char *name) {
  Il2CppObject *v3;
  System_String_o *Appendix;
  System_Collections_Generic_List_Localize_EvtMsgDat__o *DataList;
  u64 *v8;

  v3 = Allocate(Localize___c__DisplayClass28_0);
  _ctor(v3, 0);
  Appendix = GetAppendix();
  v3[1].klass = Replace_5267216(name, Appendix, StringLiteral_416);
  v8 = Allocate(System_Predicate_Localize_EvtMsgDat_);
  __ctor(
    v8,
    v3,
    Method_Localize___c__DisplayClass28_0__ContainsIndex_b__0__);
  return _FindIndex(
           DataList,
           v8);
}

// 0x1290470
char *GetAppendix(void) {
  Localize_c *v2;
  struct Localize_StaticFields *static_fields;
  struct System_String_array *LangTagTable;
  s64 LangID;

  static_fields = v2->static_fields;
  LangTagTable = static_fields->LangTagTable;
  LangID = static_fields->LangID;
  return Concat_5224608(StringLiteral_558, LangTagTable->m_Items[LangID]);
}

// 0x128fcf0
s32 GetBaseLanguage(void) {
    return 0;
}

// 0x1291cf0
EventEMsgData *GetData(char *key) {
  System_String_o *Appendix;
  System_String_o *v5;
  System_String_o *v6;
  System_String_o *v7;
  s32 v9;
  s32 v11;
  Localize_EvtMsgDat_o v14;

  Appendix = GetAppendix();
  v5 = Replace_5267216(key, Appendix, StringLiteral_416);
  v6 = GetAppendix(v5);
  v7 = Concat_5224608(v5, v6);
  v9 = ContainsIndex(v7);
  if (v9 == -1)
    return 0;
  v11 = v9;
  _get_Item(
    &v14,
    DataList,
    v11);
  return v14.table;
}

// 0x1290510
char *GetLangCode(void) {
  Localize_c *v2;
  struct Localize_StaticFields *static_fields;
  struct System_String_array *LangTagTable;
  s64 LangID;

  static_fields = v2->static_fields;
  LangTagTable = static_fields->LangTagTable;
  LangID = static_fields->LangID;
  return ToLower(LangTagTable->m_Items[LangID], 0);
}

// 0x128ff70
s32 GetLanguage(void) {
  return LangID;
}

// 0x1291e00
char *GetLocalizeText(char *ID) {
  System_String_o *v3;
  System_String_o *v5;
  s32 v6;
  Il2CppObject *Item;
  Localize_EvtMsgDat_o v13;

  if (!ID || !get_Length(ID))
    return StringLiteral_416;
  v3 = Replace_5267216(ID, StringLiteral_2303, StringLiteral_416);
  v5 = Replace_5267216(v3, StringLiteral_604, StringLiteral_416);
  v6 = 0;
  while (1)
  {
    if (v6 >= _get_Count(DataList))
    {
      if (Equals_5239888(v5, StringLiteral_5058, 5))
        return StringLiteral_212;
      else
        return v5;
    }
    _get_Item(
      &v13,
      DataList,
      v6);
    if (Animator___ContainsKey(v13.data, v5))
    {
      break;
    }
    ++v6;
  }
  _get_Item(
    &v13,
    DataList,
    v6);
  Item = object___get_Item(v13.data, v5);
  if (op_Equality(Item, StringLiteral_3359, 0)
    || op_Equality(Item, StringLiteral_3674, 0))
  {
    return 0;
  }
  return Item;
}

// 0x1292040
char *GetLocalizeText_19472448(char *dic, char *ID) {
  System_String_o *v5;
  System_String_o *v7;
  s32 v8;
  s32 v10;
  Il2CppObject *Item;
  Localize_EvtMsgDat_o v17;

  if (!ID || !get_Length(ID))
    return StringLiteral_416;
  v5 = Replace_5267216(ID, StringLiteral_2303, StringLiteral_416);
  v7 = Replace_5267216(v5, StringLiteral_604, StringLiteral_416);
  v8 = ContainsIndex(dic);
  if (v8 == -1)
    return StringLiteral_416;
  v10 = v8;
  _get_Item(
    &v17,
    DataList,
    v10);
  if (!Animator___ContainsKey(v17.data, v7))
    return StringLiteral_416;
  _get_Item(
    &v17,
    DataList,
    v10);
  Item = object___get_Item(v17.data, v7);
  if (Equals_5239888(Item, StringLiteral_3359, 5))
    return 0;
  else
    return Item;
}

// 0x128ffe0
s32 GetPlatform(void) {
  PlatformID = 0;
  return PlatformID;
}

// 0x1290150
char *GetPlatformCode(void) {
  struct System_String_array *PlatformTagTable;
  s64 PlatformID;

  PlatformID = 0;
  return ToLower(PlatformTagTable->m_Items[PlatformID], 0);
}

// 0x1290050
char *GetPlatformStr(void) {
  struct System_String_array *PlatformTagTable;
  s64 PlatformID;
  System_String_o *v6;

  PlatformID = 0;
  v6 = ToLower(PlatformTagTable->m_Items[PlatformID], 0);
  return Concat_5224608(StringLiteral_558, v6);
}

// 0x1291870
void Load(char *key, char *filePath) {
    GetAppendix();
    IsLoad(0, 0);
    ContainsIndex(0);
    LoadAsset(0, 0, 0, 0);
}

// 0x1290870
void LoadBattleLocalizeText(void) {
    LoadLocalizeText(0, 0);
}

// 0x12902c0
void LoadCommonData(void) {
  System_String_o *PlatformStr;
  System_String_o *v18;
  System_String_o *v19;
  System_String_o *v20;

  LoadLocalizeText(StringLiteral_4611, StringLiteral_5025);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5026);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5027);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5028);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5029);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5030);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5031);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5032);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5033);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5034);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5035);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5036);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5037);
  LoadLocalizeText(StringLiteral_4611, StringLiteral_5038);
  PlatformStr = GetPlatformStr();
  v18 = Concat_5224608(StringLiteral_4611, PlatformStr);
  v19 = GetPlatformStr(v18);
  v20 = Concat_5224608(StringLiteral_5034, v19);
  LoadLocalizeText(v18, v20);
}

// 0x1290240
void LoadDefault(s32 language) {
  _Clear(DataList);
  LoadCommonData();
}

// 0x1291110
void LoadEventData(char *key, char *name, s32 eventno, bool check) {
    GetAppendix();
    Load(0, 0);
    IsLoad(0, 0);
    ContainsIndex(0);
    LoadAsset(0, 0, 0, 0);
    IsFileExists(0, 0, 0);
}

// 0x12905b0
void LoadLocalizeText(char *key, char *filename) {
    GetAppendix();
    IsLoad(0, 0);
    ContainsIndex(0);
    LoadAsset(0, 0, 0, 0);
}

// 0x1291ac0
void ReleaseEventData(s32 eventno) {
    ContainsIndex(0);
}

// 0x1290d30
void Remove(char *key) {
  System_String_o *Appendix;
  System_String_o *v5;
  System_String_o *v6;
  s32 v8;
  s32 v10;
  System_String_o *v13;
  s32 v14;
  s32 v16;

  Appendix = GetAppendix();
  v5 = Replace_5267216(key, Appendix, StringLiteral_416);
  v6 = Concat_5224608(v5, Appendix);
  v8 = ContainsIndex(v6);
  if (v8 != -1)
  {
    v10 = v8;
    _RemoveAt(DataList, v10);
  }
  v13 = Concat_5221536(v5, StringLiteral_5057, Appendix);
  else
  {
    v14 = ContainsIndex(v13);
    if (v14 == -1)
      return;
  }
  v16 = v14;
  _RemoveAt(DataList, v16);
}

// 0x1290af0
void RemoveBattleLocalizeText(void) {
    Remove(0);
}

// 0x1292220
void SettingFontMaterial(void) {
    LoadFile(0, 0, 0, 0, 0);
}
