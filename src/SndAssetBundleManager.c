#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct EventEMsgData EventEMsgData;
typedef struct SndAssetBundleManager_RepData SndAssetBundleManager_RepData;
typedef struct SndAssetBundleManager_RepData_mList SndAssetBundleManager_RepData_mList;
typedef struct SndAssetBundleManager_SNDDIR SndAssetBundleManager_SNDDIR;
typedef struct SndAssetBundleManager_SndData SndAssetBundleManager_SndData;
typedef struct SoundManager SoundManager;

struct SndAssetBundleManager_SNDDIR {
    s32 value__;
};

struct SndAssetBundleManager_SndData {
    char *key;
    s32 path;
    s32 id;
    char *name;
    bool diff;
};

struct SndAssetBundleManager_RepData {
    char *base_name;
    s32 check;
    SndAssetBundleManager_RepData_mList data[UNKNOWN_ARRAY_SIZE];
};

struct SndAssetBundleManager_RepData_mList {
    char *rep_name;
    s32 event_id;
};

static void *BGMBundleTable;
static void *SEBundleTable;
static void *MotionVoiceTable;
static void *NPCVoiceTable;
static void *VoiceBundleTable;
static void *ReplaceVoiceTable;
static void *LoadedTable;
static s32 RepEventNo;

char *AppendDLC(char *name, bool append);
void DeleteVoiceALL(void);
char *GetAppendix(void);
char *GetDLCTag(s32 eventno);
EventEMsgData *GetData(char *key);
void InitializeDLCReplaceTable(void);
bool IsDLC(void);
bool IsDLCField(s32 area);
bool IsFileExists(AssetBundleCtrl *this, char *key, char *path_name);
char *IsLocalizeKey(char *key);
void *LoadAudioClip(AssetBundleCtrl *this, char *key, char *path, char *name);
void LoadBGM(char *name);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void LoadLocalizeText(char *key, char *filename);
void LoadSE(char *name);
void Remove(char *key);
bool ReplaceDLCName(char **key, char *name);
char *ReplaceVoice(char *id);
char *VoiceCommonKey(char *key, char *name);
void _DeleteBGM(SoundManager *this, char *name);
void _DeleteSE(SoundManager *this, char *name);
void _appendList(char *filename, void **dic, s32 pathid);
void _load_motionvoice(void);
void _load_npcvoice(void);
void _load_replacevoice(void);
void _loadbgm(s32 type, char *key);
void _loadbgm2(char *key, char *bgm_name);
void _loadse(char *key);
void _loadse2(char *key, char *se_name);
void _loadvoice(char *key, char *path);
bool load_voice(s32 eventno, char *key, char *name, char *voice, EventEMsgData *data, s32 i, bool replace);

// 0x1334d20
void CheckEnemy(s32 eno) {
  s32 v3;
  s32 v4;

  if ((byte_3F59326 & 1) == 0)
  {
    v3 = eno - 262;
    if ((eno - 262) <= 0x10)
    v4 = -1;
  }
  v3 = eno - 262;
  if ((eno - 262) > 0x10)
  v4 = dword_33CC9B4[v3];
  RepEventNo = v4;
}

// 0x1332b30
void *GetAudioClip(s32 type, char *name) {
    ReplaceDLCName(0, 0);
    AppendDLC(0, 0);
    GetData(0);
    LoadAudioClip(0, 0, 0, 0);
    return 0;
}

// 0x132f270
void Initialize(void) {
  System_String_o *v12;
  System_String_o *v15;
  s32 v16;
  System_String_o *v18;
  System_String_o *v20;
  System_String_o *v22;
  System_String_o *v25;
  s32 v26;
  System_String_o *v28;
  System_String_o *v30;
  System_String_o *v32;
  System_String_o *v34;
  System_String_o *v36;
  System_String_o *v39;
  s32 v40;

  PropertySheet___Clear(BGMBundleTable);
  PropertySheet___Clear(SEBundleTable);
  SndAssetBundleManager_SndData___Clear(VoiceBundleTable);
  int___Clear(LoadedTable);
  _appendList(StringLiteral_12098, &BGMBundleTable, 1);
  _appendList(StringLiteral_12099, &BGMBundleTable, 2);
  _appendList(StringLiteral_12100, &SEBundleTable, 3);
  _appendList(StringLiteral_12101, &SEBundleTable, 4);
  _load_motionvoice();
  _load_npcvoice();
  _load_replacevoice();
  InitializeDLCReplaceTable();
  v12 = StringLiteral_4738;
  v15 = IsLocalizeKey(v12);
  _loadbgm(v16, v15);
  v18 = StringLiteral_4738;
  v20 = IsLocalizeKey(v18);
  _loadse(v20);
  v22 = StringLiteral_5155;
  v25 = IsLocalizeKey(v22);
  _loadbgm(v26, v25);
  v28 = StringLiteral_5155;
  v30 = IsLocalizeKey(v28);
  _loadse(v30);
  v32 = StringLiteral_12102;
  v34 = IsLocalizeKey(v32);
  _loadse(v34);
  v36 = StringLiteral_12103;
  v39 = IsLocalizeKey(v36);
  _loadbgm(v40, v39);
}

// 0x1331f40
bool IsConstantsVoice(char *name) {
  System_String_o *v3;
  bool v5;

  v3 = ReplaceVoice(name);
  v5 = Equals_5234480(v3, name);
  if (v5)
  {
    {
    }
  }
  else
  {
    {
    }
    if (SndAssetBundleManager_SndData___ContainsKey(VoiceBundleTable, v3))
    {
      return 1;
    }
  }
  return SndAssetBundleManager_SndData___ContainsKey(VoiceBundleTable, name);
}

// 0x1330c20
char *IsLocalizeKey(char *key) {
  s32 Length;
  s32 v4;
  System_String_o *v5;
  System_String_o *v7;
  System_String_o *Appendix;

  Length = get_Length(key);
  v4 = Length - 3;
  if (Length < 3 || get_Chars(key, v4) != 95)
    return key;
  v5 = Substring_5248048(key, v4, 3);
  v7 = ToUpper(v5, 0);
  Appendix = GetAppendix();
  if (!op_Inequality(v7, Appendix, 0))
    return Substring_5248048(key, 0, v4);
  else
    return key;
}

// 0x1333700
void LoadBossAIMSG(char *key) {
  System_String_o *v4;
  s64 *v5;
  EventEMsgData_o *Data;
  s32 Count;
  const MethodInfo_1260 **v8;
  System_String_o **v9;
  System_String_o **v10;
  s32 v11;
  s32 v12;
  System_String_o *fields;
  System_String_o *v14;
  Il2CppObject *v15;
  System_String_o *v16;
  System_String_o *v19;
  struct System_String_o *v21;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v24;
  s32 v26;
  System_String_o **v27;
  const MethodInfo_1260 **v28;
  System_String_o **v29;
  struct System_String_o *v30;
  bool v32;
  System_Collections_Generic_Dictionary_string__SndAssetBundleManager_SndData__o *VoiceBundleTable;
  System_String_o *v35;
  SndAssetBundleManager_SndData_o v36;

  if (IsDLC())
  {
    Remove(StringLiteral_12117, 0);
    v4 = StringLiteral_5039;
    v5 = &StringLiteral_12118;
  }
  else
  {
    Remove(StringLiteral_12118, 0);
    v4 = StringLiteral_5039;
    v5 = &StringLiteral_12117;
  }
  LoadLocalizeText(v4, *v5);
  Data = GetData(*v5, 0);
  Count = _get_Count(Data->_eventEMsgData);
  if (Count >= 1)
  {
    v8 = &Method_System_Collections_Generic_List_MsgData__get_Item__;
    v9 = &StringLiteral_416;
    v10 = &StringLiteral_4869;
    v11 = Count;
    v12 = 0;
    v35 = key;
    do
    {
      fields = _get_Item(Data->_eventEMsgData, v12, *v8)->fields;
      v14 = *v9;
      if (Equals_5234480(key, *v10))
        v14 = StringLiteral_4735;
      v15 = Concat_5224608(fields, v14);
      v16 = Format(StringLiteral_12119, v15, 0);
      v19 = Concat_5224608(fields, v14);
      v21 = VoiceCommonKey(key, v19);
      asset_bc = get_asset_bc();
      if (IsFileExists(asset_bc, v21, v16))
      {
        v24 = _get_Item(Data->_eventEMsgData, v12, *v8)->fields;
        {
        }
        if (!SndAssetBundleManager_SndData___ContainsKey(VoiceBundleTable, v24))
        {
          v26 = v11;
          v27 = v10;
          v28 = v8;
          v29 = v9;
          v30 = Concat_5224608(v24, v14);
          v32 = !IsNullOrEmpty(v14);
          {
          }
          v36.key = v21;
          *&v36.path = 5;
          v36.name = v30;
          v36.diff = v32;
          *(&v36.diff + 1) = 0;
          *(&v36.diff + 1) = 0;
          SndAssetBundleManager_SndData___Add(VoiceBundleTable, v24, &v36);
          v9 = v29;
          v8 = v28;
          v10 = v27;
          v11 = v26;
          key = v35;
        }
      }
      ++v12;
    }
    while (v11 != v12);
  }
}

// 0x1333cc0
void LoadEventVoice(s32 eventno, char *key, EventEMsgData *data) {
    IsLocalizeKey(0);
    IsDLCField(0);
    GetDLCTag(0);
    IsDLC();
    load_voice(0, 0, 0, 0, 0, 0, 0);
}

// 0x1334850
void LoadFNPCVoice(char *key) {
}

// 0x1330ae0
void LoadKeys(s32 type, char *key, char *path) {
  System_String_o *v9;
  s32 v10;

  v9 = IsLocalizeKey(key, key);
  if ((type - 1) < 2)
  {
    _loadbgm(v10, v9);
  }
  else if ((type - 3) >= 2)
  {
    if (type == 5)
    {
      _loadvoice(key, path);
    }
  }
  else
  {
    _loadse(v9);
  }
}

// 0x13315e0
void LoadKeysBGM1(s32 type, char *key, char *bgm_name) {
  if ((type - 1) <= 1)
  {
    _loadbgm2(key, bgm_name, bgm_name);
  }
}

// 0x1331d30
s32 LoadKeysMSE(char *key, s32 idx) {
    LoadSE(0);
    return 0;
}

// 0x1331a40
void LoadKeysSE1(s32 type, char *key, char *se_name) {
  if ((type - 3) <= 1)
  {
    _loadse2(key, se_name, se_name);
  }
}

// 0x1332320
void RemoveKeys(s32 type, char *key) {
    _DeleteBGM(0, 0);
    DeleteVoiceALL();
    _DeleteSE(0, 0);
}

// 0x1332310
void RemoveKeysAll(char *key) {
  ;
}

// 0x1332060
char *ReplaceVoice(char *id) {
  struct System_String_o *name;
  System_String_c *klass;
  u64 v12;
  System_String_Fields *i;
  s32 m_stringLength;
  SndAssetBundleManager_SndData_o v23;

  if (SndAssetBundleManager_SndData___ContainsKey(VoiceBundleTable, id))
  {
    SndAssetBundleManager_SndData___get_Item(&v23, VoiceBundleTable, id);
    if (v23.diff)
      id = v23.name;
  }
  if (SndAssetBundleManager_RepData___ContainsKey(ReplaceVoiceTable, id))
  {
    SndAssetBundleManager_RepData___get_Item(&v23, ReplaceVoiceTable, id);
    name = v23.name;
    klass = v23.name[1].klass;
    if (klass >= 1)
    {
      v12 = 0;
      for (i = &v23.name[1].fields; ; i += 2)
      {
        m_stringLength = i->m_stringLength;
        if (i->m_stringLength == -1)
          break;
        {
        }
        if (m_stringLength == RepEventNo)
          break;
        if ((i->m_stringLength & 0x8000) != 0)
        {
          if (fldGb->fieldID == LOBYTE(i->m_stringLength))
            break;
        }
        LODWORD(klass) = name[1].klass;
        if (++v12 >= klass)
          return id;
      }
      return i[-1];
    }
  }
  return id;
}

// 0x1333aa0
char *VoiceCommonKey(char *key, char *name) {
  if (Equals_5234480(name, StringLiteral_12120)
    || Equals_5234480(name, StringLiteral_12121)
    || Equals_5234480(name, StringLiteral_12122)
    || Equals_5234480(name, StringLiteral_12123)
    || Equals_5234480(name, StringLiteral_12124)
    || Equals_5234480(name, StringLiteral_12125)
    || Equals_5234480(name, StringLiteral_12126)
    || Equals_5234480(name, StringLiteral_12127)
    || Equals_5234480(name, StringLiteral_12128)
    || Equals_5234480(name, StringLiteral_12129)
    || Equals_5234480(name, StringLiteral_12130)
    || Equals_5234480(name, StringLiteral_12131)
    || Equals_5234480(name, StringLiteral_12132)
    || Equals_5234480(name, StringLiteral_12133))
  {
    return StringLiteral_5039;
  }
  if (Equals_5234480(name, StringLiteral_12134))
    return StringLiteral_5039;
  return key;
}

// 0x132f680
void _appendList(char *filename, void **dic, s32 pathid) {
  u64 *v6;
  UnityEngine_Object_o *v7;
  s64 typeHierarchyDepth;
  System_Byte_array *bytes;
  System_Text_Encoding_o *Unicode;
  System_String_o *v11;
  System_String_array *v12;
  System_String_array *v14;
  il2cpp_array_size_t max_length;
  s64 *v16;
  System_String_o **v17;
  System_String_o **v18;
  System_String_array *v19;
  s64 v20;
  System_String_o **m_Items;
  System_String_o *v23;
  u64 *v24;
  System_String_array *v26;
  System_String_array *v27;
  System_String_o *v28;
  struct System_String_o *v31;
  Il2CppObject *v33;
  Il2CppObject *Item;
  System_String_o **v35;
  s64 *v36;
  System_String_o **v37;
  System_Collections_Generic_Dictionary_string__Dictionary_string__SndAssetBundleManager_SndData___o **v38;
  u64 *v39;
  System_Collections_Generic_Dictionary_string__Dictionary_string__SndAssetBundleManager_SndData___o *v40;
  UnityEngine_Rendering_PostProcessing_PropertySheet_o *v41;
  SndAssetBundleManager_SndData_o v44;

  v6 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v6);
  v7 = Load(filename, 0);
  if (v7)
  {
    if (v7->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
    {
      if (v7->klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_TextAsset)
        v7 = 0;
    }
    else
    {
      v7 = 0;
    }
  }
  bytes = get_bytes(v7);
  Unicode = get_Unicode();
  v11 = (Unicode->klass[1]._1.byval_arg.data)(Unicode, bytes, *&Unicode->klass[1]._1.byval_arg.bits);
  v12 = NewSpecific(string, 1u);
  v12->m_Items[0] = StringLiteral_489;
  v14 = Split_5246672(v11, v12, 0);
  max_length = v14->max_length;
  if (max_length >= 2)
  {
    v16 = &char;
    v17 = &StringLiteral_76;
    v18 = &StringLiteral_496;
    v19 = v14;
    v20 = 0;
    m_Items = v14->m_Items;
    do
    {
      v23 = m_Items[v20];
      v24 = NewSpecific(*v16, 1u);
      *(v24 + 16) = 44;
      v26 = Split(v23, v24);
      if (LODWORD(v26->max_length) == 3)
      {
        v27 = v26;
        v28 = Substring_5248048(v26->m_Items[0], 0, 2);
        if (!op_Equality(v28, *v17, 0))
        {
          if (get_Chars(v27->m_Items[0], 0) == 34)
          {
            v31 = Replace_5267216(v27->m_Items[0], *v18, StringLiteral_416);
            v33 = Replace_5267216(v27->m_Items[1], *v18, StringLiteral_416);
            if (Animator___ContainsKey(*dic, v33))
            {
              Item = object___get_Item(*dic, v33);
              v44.key = v33;
              v44.path = pathid;
              v44.id = 0;
              v44.name = v31;
              *&v44.diff = 0;
              SndAssetBundleManager_SndData___Add(Item, v31, &v44);
            }
            else
            {
              v35 = v18;
              v36 = v16;
              v37 = v17;
              v38 = dic;
              v39 = Allocate(System_Collections_Generic_Dictionary_string__SndAssetBundleManager_SndData_);
              SndAssetBundleManager_SndData____ctor(
                v39);
              v44.key = v33;
              v44.path = pathid;
              v44.id = 0;
              v44.name = v31;
              *&v44.diff = 0;
              SndAssetBundleManager_SndData___Add(v39, v31, &v44);
              v40 = *v38;
              v41 = v39;
              dic = v38;
              v17 = v37;
              v16 = v36;
              v18 = v35;
              PropertySheet___Add(v40, v33, v41);
            }
          }
        }
      }
      max_length = LODWORD(v19->max_length);
      ++v20;
    }
    while (v20 < ((max_length << 32) - 0x100000000LL) >> 32);
  }
}

// 0x132fa90
void _load_motionvoice(void) {
  u64 *v1;
  UnityEngine_Object_o *v2;
  s64 typeHierarchyDepth;
  System_Byte_array *bytes;
  System_Text_Encoding_o *Unicode;
  System_String_o *v6;
  System_String_array *v7;
  System_String_array *v10;
  il2cpp_array_size_t max_length;
  s64 *v13;
  System_String_o **v14;
  s64 v15;
  System_String_o **m_Items;
  System_String_o *v20;
  u64 *v21;
  System_String_array *v23;
  System_String_array *v24;
  System_String_o *v25;
  System_String_o **v27;
  s64 *v29;
  mdlEffectResrcItem_t_o *v30;
  s64 *v32;
  s64 *v33;
  s64 *v36;
  s64 *v38;

  v1 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v1);
  v2 = Load(StringLiteral_12104, 0);
  if (v2)
  {
    if (v2->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
    {
      if (v2->klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_TextAsset)
        v2 = 0;
    }
    else
    {
      v2 = 0;
    }
  }
  bytes = get_bytes(v2);
  Unicode = get_Unicode();
  v6 = (Unicode->klass[1]._1.byval_arg.data)(Unicode, bytes, *&Unicode->klass[1]._1.byval_arg.bits);
  v7 = NewSpecific(string, 1u);
  v7->m_Items[0] = StringLiteral_489;
  v10 = Split_5246672(v6, v7, 0);
  _Clear(MotionVoiceTable);
  max_length = v10->max_length;
  if (max_length >= 2)
  {
    v13 = &char;
    v14 = &StringLiteral_416;
    v15 = 0;
    m_Items = v10->m_Items;
    do
    {
      v20 = m_Items[v15];
      v21 = NewSpecific(*v13, 1u);
      *(v21 + 16) = 44;
      v23 = Split(v20, v21);
      if (LODWORD(v23->max_length) == 2)
      {
        v24 = v23;
        v25 = Substring_5248048(v23->m_Items[0], 0, 2);
        if (!op_Equality(v25, StringLiteral_76, 0))
        {
          v27 = v14;
          Replace_5267216(v24->m_Items[0], StringLiteral_212, *v14);
          v29 = v13;
          Replace_5267216(v24->m_Items[1], StringLiteral_212, *v27);
          v30 = NewSpecific(string, 2u);
          v32 = Replace_5267216(v24->m_Items[0], StringLiteral_212, *v27);
          v33 = v32;
          v30->memHandle = v33;
          v36 = Replace_5267216(v24->m_Items[1], StringLiteral_212, *v27);
          v38 = v36;
          v13 = v29;
          v30->pTexture = v38;
          v14 = v27;
          {
            m_Items = v10->m_Items;
          }
          else
          {
            m_Items = v10->m_Items;
          }
          _Add(MotionVoiceTable, v30);
        }
      }
      max_length = LODWORD(v10->max_length);
      ++v15;
    }
    while (v15 < ((max_length << 32) - 0x100000000LL) >> 32);
  }
}

// 0x132ff60
void _load_npcvoice(void) {
  u64 *v1;
  UnityEngine_Object_o *v2;
  s64 typeHierarchyDepth;
  System_Byte_array *bytes;
  System_Text_Encoding_o *Unicode;
  System_String_o *v6;
  System_String_array *v7;
  System_String_array *v10;
  il2cpp_array_size_t max_length;
  s64 v13;
  System_String_o *v19;
  u64 *v20;
  System_String_array *v22;
  System_String_array *v23;
  System_String_o *v24;
  mdlEffectResrcItem_t_o *v25;
  s64 *v27;
  s64 *v28;
  s64 *v30;
  s64 *v31;
  s64 *v34;
  s64 *v36;

  v1 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v1);
  v2 = Load(StringLiteral_12105, 0);
  if (v2)
  {
    if (v2->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
    {
      if (v2->klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_TextAsset)
        v2 = 0;
    }
    else
    {
      v2 = 0;
    }
  }
  bytes = get_bytes(v2);
  Unicode = get_Unicode();
  v6 = (Unicode->klass[1]._1.byval_arg.data)(Unicode, bytes, *&Unicode->klass[1]._1.byval_arg.bits);
  v7 = NewSpecific(string, 1u);
  v7->m_Items[0] = StringLiteral_489;
  v10 = Split_5246672(v6, v7, 0);
  _Clear(NPCVoiceTable);
  max_length = v10->max_length;
  if (max_length >= 2)
  {
    v13 = 0;
    do
    {
      v19 = v10->m_Items[v13];
      v20 = NewSpecific(char, 1u);
      *(v20 + 16) = 44;
      v22 = Split(v19, v20);
      if (LODWORD(v22->max_length) == 4)
      {
        v23 = v22;
        v24 = Substring_5248048(v22->m_Items[0], 0, 3);
        if (!op_Equality(v24, StringLiteral_76, 0))
        {
          v25 = NewSpecific(string, 3u);
          v27 = Replace_5267216(v23->m_Items[0], StringLiteral_212, StringLiteral_416);
          v28 = v27;
          v25->memHandle = v28;
          v30 = Replace_5267216(v23->m_Items[1], StringLiteral_212, StringLiteral_416);
          v31 = v30;
          v25->pTexture = v31;
          v34 = Replace_5267216(v23->m_Items[2], StringLiteral_212, StringLiteral_416);
          v36 = v34;
          v25[1].klass = v36;
          {
          }
          _Add(NPCVoiceTable, v25);
        }
      }
      max_length = LODWORD(v10->max_length);
      ++v13;
    }
    while (v13 < ((max_length << 32) - 0x100000000LL) >> 32);
  }
}

// 0x1330440
void _load_replacevoice(void) {
}

// 0x1330d20
void _loadbgm(s32 type, char *key) {
    LoadBGM(0);
}

// 0x1331680
void _loadbgm2(char *key, char *bgm_name) {
    LoadBGM(0);
}

// 0x1330f30
void _loadse(char *key) {
    LoadSE(0);
}

// 0x1331ae0
void _loadse2(char *key, char *se_name) {
    LoadSE(0);
}

// 0x13311c0
void _loadvoice(char *key, char *path) {
  u64 *v5;
  AssetBundleCtrl_o *asset_bc;
  System_Byte_array *FileByte;
  System_Text_Encoding_o *Unicode;
  System_String_o *v10;
  System_String_array *v11;
  System_String_array *v13;
  il2cpp_array_size_t max_length;
  System_String_array *v15;
  s64 v16;
  System_String_o **m_Items;
  System_String_o *v19;
  u64 *v20;
  System_String_array *v22;
  System_String_array *v23;
  System_String_o *v24;
  struct System_String_o *v28;
  System_Collections_Generic_Dictionary_string__SndAssetBundleManager_SndData__o *VoiceBundleTable;
  SndAssetBundleManager_SndData_o v34;

  if (path)
  {
    v5 = Allocate(System_Collections_Generic_List_string_);
    __ctor(v5);
    asset_bc = get_asset_bc();
    FileByte = LoadFileByte(asset_bc, key, path);
    Unicode = get_Unicode();
    v10 = (Unicode->klass[1]._1.byval_arg.data)(Unicode, FileByte, *&Unicode->klass[1]._1.byval_arg.bits);
    v11 = NewSpecific(string, 1u);
    v11->m_Items[0] = StringLiteral_489;
    v13 = Split_5246672(v10, v11, 0);
    max_length = v13->max_length;
    if (max_length >= 2)
    {
      v15 = v13;
      v16 = 0;
      m_Items = v13->m_Items;
      do
      {
        v19 = m_Items[v16];
        v20 = NewSpecific(char, 1u);
        *(v20 + 16) = 44;
        v22 = Split(v19, v20);
        if (LODWORD(v22->max_length) == 1)
        {
          v23 = v22;
          v24 = Substring_5248048(v22->m_Items[0], 0, 2);
          if (!op_Equality(v24, StringLiteral_76, 0))
          {
            if (get_Chars(v23->m_Items[0], 0) == 34)
            {
              v28 = Replace_5267216(v23->m_Items[0], StringLiteral_496, StringLiteral_416);
              {
              }
              if (!SndAssetBundleManager_SndData___ContainsKey(VoiceBundleTable, v28))
              {
                {
                }
                v34.key = key;
                *&v34.path = 5;
                v34.name = v28;
                *&v34.diff = 0;
                SndAssetBundleManager_SndData___Add(VoiceBundleTable, v28, &v34);
              }
            }
          }
        }
        max_length = LODWORD(v15->max_length);
        ++v16;
      }
      while (v16 < ((max_length << 32) - 0x100000000LL) >> 32);
    }
  }
}

// 0x13345d0
bool load_voice(s32 eventno, char *key, char *name, char *voice, EventEMsgData *data, s32 i, bool replace) {
  AssetBundleCtrl_o *asset_bc;
  System_Collections_Generic_Dictionary_string__SndAssetBundleManager_SndData__o *VoiceBundleTable;
  System_WeakReference_o *Item;
  System_Collections_Generic_Dictionary_object__SndAssetBundleManager_SndData__o *v21;
  System_WeakReference_o *v22;
  s32 v23;
  System_Collections_Generic_Dictionary_string__SndAssetBundleManager_SndData__o *v24;
  System_String_o *v25;
  bool v26;
  bool v28;
  System_Collections_Generic_Dictionary_string__SndAssetBundleManager_SndData__o *v29;
  System_String_o *fields;
  u64 v32[5];
  u32 v33[2];
  SndAssetBundleManager_SndData_o v34;

  memset(v33, 0, 7);
  memset(&v32[4], 0, 7);
  asset_bc = get_asset_bc();
  if (!IsFileExists(asset_bc, key, name))
    return 0;
  Item = _get_Item(
           data->_eventEMsgData,
           i);
  if (!SndAssetBundleManager_SndData___ContainsKey(VoiceBundleTable, *&Item->fields))
  {
    memset(v33, 0, 7);
    v28 = replace;
    v29 = VoiceBundleTable;
    fields = _get_Item(
               data->_eventEMsgData,
               i)->fields;
    v34.key = key;
    *&v34.path = 5;
    *(&v34.diff + 1) = *(v33 + 3);
    v34.name = voice;
    v34.diff = v28;
    *(&v34.diff + 1) = v33[0];
    SndAssetBundleManager_SndData___Add(v29, fields, &v34);
    return 1;
  }
  if (!replace)
    return 1;
  v21 = VoiceBundleTable;
  v22 = _get_Item(
          data->_eventEMsgData,
          i);
  SndAssetBundleManager_SndData___get_Item(v32, v21, *&v22->fields);
  *(&v32[4] + 3) = HIDWORD(v32[3]);
  LODWORD(v32[4]) = *(&v32[3] + 1);
  v23 = HIDWORD(v32[1]);
  v24 = VoiceBundleTable;
  v25 = _get_Item(
          data->_eventEMsgData,
          i)->fields;
  v34.path = 5;
  v34.id = v23;
  *(&v34.diff + 1) = *(&v32[4] + 3);
  v34.name = voice;
  v26 = 1;
  v34.key = key;
  v34.diff = 1;
  *(&v34.diff + 1) = v32[4];
  SndAssetBundleManager_SndData___set_Item(v24, v25, &v34);
  return v26;
}
