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
    SndAssetBundleManager_RepData_mList *data;
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
      goto LABEL_3;
LABEL_5:
    v4 = -1;
    goto LABEL_6;
  }
  v3 = eno - 262;
  if ((eno - 262) > 0x10)
    goto LABEL_5;
LABEL_3:
  v4 = dword_33CC9B4[v3];
LABEL_6:
  RepEventNo = v4;
}

// 0x1332b30
void *GetAudioClip(s32 type, char *name) {
  System_String_o *v5;
  s32 v6;
  System_String_o *v7;
  System_String_o *v9;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *v11;
  System_Collections_Generic_Dictionary_string__SndAssetBundleManager_SndData__o *v12;
  System_String_o *v13;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  System_Collections_Generic_Dictionary_string__SndAssetBundleManager_SndData__o *v16;
  System_String_o *v17;
  s32 v18;
  s32 Length;
  s32 v25;
  Il2CppObject *v27;
  System_String_array *v31;
  System_String_o *v32;
  UnityEngine_Object_o *v33;
  Il2CppObject *v42;
  Il2CppObject *Data;
  char *v46;
  s64 *v47;
  AssetBundleCtrl_o *asset_bc;
  SndAssetBundleManager_SndData_o v56;
  SndAssetBundleManager_SndData_o v57;
  struct System_String_o *v58;
  s64 v59;
  struct System_String_o *v60;
  System_String_o *key;

  v59 = 0;
  v60 = 0;
  v58 = 0;
  v5 = "sound";
  key = "snd";
  v6 = get_Length(name) - 3;
  v7 = Substring_5248048(name, v6, 3);
  v9 = name;
  if (op_Equality(v7, "_L_", 0))
    v9 = Substring_5248048(name, 0, v6);
  if (!type)
  {
    Values = Type___get_Values(BGMBundleTable);
    Type___GetEnumerator(&v57, Values);
    v59 = *&v57.path;
    v60 = v57.name;
    v58 = v57.key;
    do
    {
      if ((sub_4D4B20(&v58) & 1) == 0)
      {
        nullsub_48(&v58);
        return 0;
      }
      v16 = sub_4D4CB0(&v58);
    }
    while (!SndAssetBundleManager_SndData___ContainsKey(v16, v9));
    SndAssetBundleManager_SndData___get_Item(&v57, v16, v9);
    if (v57.path == 1)
    {
      v17 = Concat_5224608(v5, "/bgm");
    }
    else
    {
      SndAssetBundleManager_SndData___get_Item(&v57, v16, v9);
      if (v57.path != 2)
        goto LABEL_28;
      v17 = Concat_5224608(v5, "/bgm2");
    }
    v5 = v17;
LABEL_28:
    SndAssetBundleManager_SndData___get_Item(&v57, v16, v9);
    key = v57.key;
    if (ReplaceDLCName(&key, v9))
    {
      name = AppendDLC(name, 0);
    }
    nullsub_48(&v58);
    goto LABEL_62;
  }
  if (type != 1)
  {
    if (type == 2)
    {
      if (SndAssetBundleManager_SndData___ContainsKey(VoiceBundleTable, v9))
      {
        v5 = Concat_5224608(v5, "/voice");
        {
        }
        SndAssetBundleManager_SndData___get_Item(&v57, VoiceBundleTable, v9);
        key = v57.key;
        goto LABEL_62;
      }
      Length = get_Length(v9);
      if (get_Chars(v9, Length - 1) == 109)
      {
        v25 = get_Length(v9);
        v27 = Substring_5248048(v9, 0, v25 - 1);
        {
        }
        if (SndAssetBundleManager_SndData___ContainsKey(VoiceBundleTable, v27))
        {
          v5 = Concat_5224608(v5, "/voice");
          {
          }
          SndAssetBundleManager_SndData___get_Item(&v57, VoiceBundleTable, v27);
          key = v57.key;
          SndAssetBundleManager_SndData___get_Item(&v56, VoiceBundleTable, v27);
          name = v56.name;
          goto LABEL_62;
        }
      }
    }
    return 0;
  }
  v11 = Type___get_Values(SEBundleTable);
  Type___GetEnumerator(&v57, v11);
  v59 = *&v57.path;
  v60 = v57.name;
  v58 = v57.key;
  do
  {
    if ((sub_4D4B20(&v58) & 1) == 0)
    {
      v18 = 0;
      goto LABEL_41;
    }
    v12 = sub_4D4CB0(&v58);
  }
  while (!SndAssetBundleManager_SndData___ContainsKey(v12, v9));
  SndAssetBundleManager_SndData___get_Item(&v57, v12, v9);
  if (v57.path == 3)
  {
    v13 = Concat_5224608(v5, "/se");
  }
  else
  {
    SndAssetBundleManager_SndData___get_Item(&v57, v12, v9);
    if (v57.path == 4)
      v13 = Concat_5224608(v5, "/se2");
    else
      v13 = Concat_5224608(v5, "/bgm");
  }
  v5 = v13;
  SndAssetBundleManager_SndData___get_Item(&v57, v12, v9);
  key = v57.key;
  v18 = 1;
LABEL_41:
  nullsub_48(&v58);
  if (!v18)
    return 0;
LABEL_62:
  v31 = NewSpecific(string, 6u);
  v31->m_Items[0] = "LoadAssetBundle : ";
  v32 = key;
  v31->m_Items[1] = v32;
  v31->m_Items[2] = ",";
  v31->m_Items[3] = v5;
  v31->m_Items[4] = ",";
  v31->m_Items[5] = name;
  v42 = Concat_5271600(v31);
  Log(v42, 0);
  Data = GetData(name, 0);
  v33 = Data;
  if (Data)
  {
    if (Data->klass != UnityEngine_AudioClip)
    {
      sub_8FC2C0(Data->klass->_1.element_class, UnityEngine_AudioClip, &v57);
      if ((v57.key & 1) != 0)
        v46 = v57.name;
      else
        v46 = &v57.key + 1;
      v47 = sub_8C4940(v46);
    }
  }
  if (op_Equality(v33, 0, 0))
  {
    asset_bc = get_asset_bc();
    return LoadAudioClip(asset_bc, key, v5, name);
  }
  return v33;
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
  _appendList("table/BGMTable", &BGMBundleTable, 1);
  _appendList("table/BGM2Table", &BGMBundleTable, 2);
  _appendList("table/SETable", &SEBundleTable, 3);
  _appendList("table/SE2Table", &SEBundleTable, 4);
  _load_motionvoice();
  _load_npcvoice();
  _load_replacevoice();
  InitializeDLCReplaceTable();
  v12 = "ecmn";
  v15 = IsLocalizeKey(v12);
  _loadbgm(v16, v15);
  v18 = "ecmn";
  v20 = IsLocalizeKey(v18);
  _loadse(v20);
  v22 = "fcmn";
  v25 = IsLocalizeKey(v22);
  _loadbgm(v26, v25);
  v28 = "fcmn";
  v30 = IsLocalizeKey(v28);
  _loadse(v30);
  v32 = "fcmn_1";
  v34 = IsLocalizeKey(v32);
  _loadse(v34);
  v36 = "fcmn_2";
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
LABEL_8:
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
      goto LABEL_8;
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
    Remove("AI_MSG", 0);
    v4 = "battle";
    v5 = &"AI_MSGD";
  }
  else
  {
    Remove("AI_MSGD", 0);
    v4 = "battle";
    v5 = &"AI_MSG";
  }
  LoadLocalizeText(v4, *v5);
  Data = GetData(*v5, 0);
  Count = _get_Count(Data->_eventEMsgData);
  if (Count >= 1)
  {
    v8 = &Method_System_Collections_Generic_List_MsgData__get_Item__;
    v9 = &"";
    v10 = &"dvl0xc0d";
    v11 = Count;
    v12 = 0;
    v35 = key;
    do
    {
      fields = _get_Item(Data->_eventEMsgData, v12, *v8)->fields;
      v14 = *v9;
      if (Equals_5234480(key, *v10))
        v14 = "m";
      v15 = Concat_5224608(fields, v14);
      v16 = Format("sound/Voice/{0}.wav", v15, 0);
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
  System_Object_array *v6;
  Il2CppObject *v12;
  System_String_o *v15;
  s32 Length;
  System_String_o *v17;
  _BOOL4 v18;
  s64 *v20;
  _BOOL4 v21;
  System_String_o *DLCTag;
  bool IsDLCField;
  s32 i;
  System_WeakReference_o *Item;
  System_String_o *v31;
  System_String_o *v32;
  System_Object_array *v33;
  System_String_o *v36;
  s32 v37;
  System_String_o *v38;
  s32 v39;
  System_WeakReference_o *v43;
  System_WeakReference_o *v44;
  struct System_String_o *fields;
  System_Collections_Generic_Dictionary_string__SndAssetBundleManager_SndData__o *VoiceBundleTable;
  System_String_o *v52;
  s32 v54;
  System_WeakReference_o *v58;
  System_WeakReference_o *v59;
  System_Collections_Generic_Dictionary_string__SndAssetBundleManager_SndData__o *v61;
  struct System_String_o *klass;
  struct System_String_o *monitor;
  System_Collections_Generic_Dictionary_string__SndAssetBundleManager_SndData__o *v65;
  System_String_o *v68;
  System_String_o *str1;
  s32 Count;
  u16 Chars;
  SndAssetBundleManager_SndData_o v73;

  Chars = 0;
  v6 = NewSpecific(object, 4u);
  v6->m_Items[0] = "key = ";
  v6->m_Items[1] = key;
  v6->m_Items[2] = "data = ";
  v6->m_Items[3] = data;
  v12 = Concat_5270224(v6);
  Log(v12, 0);
  if (op_Equality(data, 0, 0))
    return;
  Count = _get_Count(data->_eventEMsgData);
  v15 = IsLocalizeKey(key);
  Length = get_Length(v15);
  Chars = get_Chars(v15, Length - 1);
  v17 = sub_3C3A80(&Chars, 0);
  v18 = Equals_5239888(v17, "m", 5);
  v20 = &"";
  if (v18)
    v20 = &"m";
  v21 = v18;
  str1 = *v20;
  else if (!IsDLCField(eventno))
  {
LABEL_34:
    DLCTag = GetDLCTag(eventno);
    if (IsNullOrEmpty(DLCTag))
      goto LABEL_47;
  }
  else if (!(v21 | !IsDLC()))
  {
LABEL_50:
    IsDLCField = IsDLCField(eventno);
    if (eventno != 714 && !IsDLCField)
      return;
    goto LABEL_59;
  }
LABEL_47:
  else if ((v21 & ~IsDLC() & 1) != 0)
  {
    goto LABEL_50;
  }
LABEL_59:
  if (Count >= 1)
  {
    for (i = 0; i != Count; ++i)
    {
      Item = _get_Item(
               data->_eventEMsgData,
               i);
      v31 = Concat_5224608(*&Item->fields, str1);
      v32 = Concat_5221536("sound/Voice/", v31, ".wav");
      v33 = Empty_string_();
      v36 = Format_5268784(v32, v33);
      load_voice(v37, v15, v36, v31, data, i, v21);
    }
  }
  v38 = key;
  v39 = 0;
  {
LABEL_68:
  }
  while (v39 < _get_Count(MotionVoiceTable))
  {
    v43 = _get_Item(
            MotionVoiceTable,
            v39);
    v44 = v43;
    if (Equals_5239888(v43[1].monitor, v38, 5))
    {
      if (!SndAssetBundleManager_SndData___ContainsKey(VoiceBundleTable, *&v44[1].fields))
      {
        fields = v44[1].fields;
        {
        }
        v52 = v44[1].fields;
        v73.key = key;
        *&v73.path = 5;
        v73.name = fields;
        *&v73.diff = 0;
        v38 = key;
        SndAssetBundleManager_SndData___Add(VoiceBundleTable, v52, &v73);
      }
    }
    ++v39;
      goto LABEL_68;
  }
  v54 = 0;
    goto LABEL_96;
LABEL_94:
LABEL_96:
  while (v54 < _get_Count(NPCVoiceTable))
  {
    v58 = _get_Item(
            NPCVoiceTable,
            v54);
    v59 = v58;
    if (Equals_5239888(*&v58[1].fields, v38, 5))
    {
      else
      {
        v61 = VoiceBundleTable;
        if (!LODWORD(v59[1].klass))
          goto LABEL_106;
      }
      if (!SndAssetBundleManager_SndData___ContainsKey(v61, v59[1].monitor))
      {
        klass = v59[2].klass;
        monitor = v59[1].monitor;
        {
          v65 = VoiceBundleTable;
          if (!LODWORD(v59[1].klass))
          {
LABEL_115:
          }
        }
        else
        {
          v65 = VoiceBundleTable;
          if (!LODWORD(v59[1].klass))
            goto LABEL_115;
        }
        v68 = v59[1].monitor;
        v73.key = klass;
        *&v73.path = 5;
        v73.name = monitor;
        v73.diff = 1;
        *(&v73.diff + 1) = 0;
        *(&v73.diff + 1) = 0;
        SndAssetBundleManager_SndData___Add(v65, v68, &v73);
        v38 = key;
      }
    }
    ++v54;
      goto LABEL_94;
  }
}

// 0x1334850
void LoadFNPCVoice(char *key) {
  Il2CppObject *v4;
  u64 *v5;
  UnityEngine_Object_o *v6;
  s64 typeHierarchyDepth;
  System_Byte_array *bytes;
  System_Text_Encoding_o *Unicode;
  System_String_o *v10;
  System_String_array *v11;
  System_String_array *v14;
  u64 *v16;
  System_String_o *v17;
  il2cpp_array_size_t max_length;
  s64 v19;
  System_String_o *v21;
  u64 *v22;
  System_String_array *v24;
  System_String_array *v25;
  System_String_o *v26;
  struct System_String_o *v28;
  System_String_o *v30;
  struct System_String_o *v32;
  System_Collections_Generic_Dictionary_string__SndAssetBundleManager_SndData__o *VoiceBundleTable;
  System_String_o *value;
  SndAssetBundleManager_SndData_o v40;

  v4 = Concat_5224608("NPCVoice key = ", key);
  Log(v4, 0);
  v5 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v5);
  v6 = Load("table/VoiceTable", 0);
  if (v6)
  {
    if (v6->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
    {
      if (v6->klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_TextAsset)
        v6 = 0;
    }
    else
    {
      v6 = 0;
    }
  }
  bytes = get_bytes(v6);
  Unicode = get_Unicode();
  v10 = (Unicode->klass[1]._1.byval_arg.data)(Unicode, bytes, *&Unicode->klass[1]._1.byval_arg.bits);
  v11 = NewSpecific(string, 1u);
  v11->m_Items[0] = "\r\n";
  v14 = Split_5246672(v10, v11, 0);
  LODWORD(v40.key) = fldGb->fieldID;
  v16 = sub_8D3950(s32, &v40);
  v17 = Format("f{0:D3}", v16, 0);
  max_length = v14->max_length;
  value = v17;
  if (max_length >= 2)
  {
    v19 = 0;
    do
    {
      v21 = v14->m_Items[v19];
      v22 = NewSpecific(char, 1u);
      *(v22 + 16) = 44;
      v24 = Split(v21, v22);
      if (LODWORD(v24->max_length) == 4)
      {
        v25 = v24;
        v26 = Substring_5248048(v24->m_Items[0], 0, 3);
        if (!op_Equality(v26, "//", 0))
        {
          v28 = Replace_5267216(v25->m_Items[0], " ", "");
          v30 = Replace_5267216(v25->m_Items[1], " ", "");
          v32 = Replace_5267216(v25->m_Items[2], " ", "");
          if (Equals_5234480(v30, value))
          {
            {
            }
            if (!SndAssetBundleManager_SndData___ContainsKey(VoiceBundleTable, v28))
            {
              {
              }
              v40.key = v32;
              *&v40.path = 5;
              v40.diff = 1;
              v40.name = v28;
              *(&v40.diff + 1) = 0;
              *(&v40.diff + 1) = 0;
              SndAssetBundleManager_SndData___Add(VoiceBundleTable, v28, &v40);
            }
          }
        }
      }
      max_length = LODWORD(v14->max_length);
      ++v19;
    }
    while (v19 < ((max_length << 32) - 0x100000000LL) >> 32);
  }
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
  Il2CppObject *Item;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  s32 v10;
  s32 v11;
  System_String_o *v13;
  System_String_o *v15[4];
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v16;
  s64 v17;
  s64 v18;
  s64 v19;

  v18 = 0;
  v19 = 0;
  v17 = 0;
  memset(&v16, 0, sizeof(v16));
  if (!Animator___ContainsKey(SEBundleTable, key))
    return -1;
  Item = object___get_Item(SEBundleTable, key);
  Values = SndAssetBundleManager_SndData___get_Values(Item);
  SndAssetBundleManager_SndData___GetEnumerator(&v16, Values);
  v10 = 0;
  v11 = 0;
  while ((sub_4D4060(&v16) & 1) != 0)
  {
    sub_4D4200(&v16, v15);
    if (v11 >= idx)
    {
      v13 = v15[2];
      LoadSE(v13);
      ++v10;
    }
    ++v11;
    if (v10 > 2)
      goto LABEL_20;
  }
  v11 = -1;
LABEL_20:
  nullsub_47(&v16);
  return v11;
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
  Il2CppObject *Item;
  System_String_o *v12;
  Il2CppObject *v18;
  System_String_o *v21;
  System_Collections_Generic_Dictionary_string__int__o *LoadedTable;
  System_String_o *v26;
  System_Collections_Generic_Dictionary_string__int__o *v28;
  System_String_o *v29;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v31;
  s64 v32;
  s64 v33;
  s64 v34;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v35;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v36;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v37;
  s64 v38;
  s64 v39;
  s64 v40;

  v39 = 0;
  v40 = 0;
  v38 = 0;
  memset(&v37, 0, sizeof(v37));
  memset(&v36, 0, sizeof(v36));
  memset(&v35, 0, sizeof(v35));
  if (type == 1)
  {
    if (IsNullOrEmpty(key))
      return;
    if (!Animator___ContainsKey(BGMBundleTable, key))
      return;
    Item = object___get_Item(BGMBundleTable, key);
    SndAssetBundleManager_SndData___GetEnumerator(&v31, Item);
    v37 = v31;
    v40 = v34;
    v38 = v32;
    v39 = v33;
    while ((sub_436350(&v37)
           & 1) != 0)
    {
      sub_4365A0(&v37, &v31);
      v36 = v31;
      v12 = sub_1A0C1A0(&v36);
      _DeleteBGM(Instance, v12);
    }
    nullsub_29(&v37);
  }
  if ((type - 3) > 1)
  {
LABEL_52:
    if (type == 5)
    {
      DeleteVoiceALL();
    }
    return;
  }
  if (!IsNullOrEmpty(key))
  {
    if (Animator___ContainsKey(SEBundleTable, key))
    {
      v18 = object___get_Item(SEBundleTable, key);
      SndAssetBundleManager_SndData___GetEnumerator(&v31, v18);
      v37 = v31;
      v40 = v34;
      v38 = v32;
      v39 = v33;
      while ((sub_436350(&v37)
             & 1) != 0)
      {
        sub_4365A0(&v37, &v31);
        v35 = v31;
        v21 = sub_1A0C1A0(&v35);
        _DeleteSE(Instance, v21);
      }
      nullsub_29(&v37);
      v26 = Concat_5224608(key, "_SE");
      if (int___ContainsKey(LoadedTable, v26))
      {
        {
        }
        v28 = LoadedTable;
        v29 = Concat_5224608(key, "_SE");
        int___Remove(v28, v29);
      }
      goto LABEL_52;
    }
  }
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
  if (Equals_5234480(name, "AI_MSG_L0092")
    || Equals_5234480(name, "AI_MSG_L0093")
    || Equals_5234480(name, "AI_MSG_L0094")
    || Equals_5234480(name, "AI_MSG_L0095")
    || Equals_5234480(name, "AI_MSG_L0096")
    || Equals_5234480(name, "AI_MSG_L0097")
    || Equals_5234480(name, "AI_MSG_L0098")
    || Equals_5234480(name, "AI_MSG_L0099")
    || Equals_5234480(name, "AI_MSG_L0100")
    || Equals_5234480(name, "AI_MSG_L0101")
    || Equals_5234480(name, "AI_MSG_L0102")
    || Equals_5234480(name, "AI_MSG_L0103")
    || Equals_5234480(name, "AI_MSG_L0104")
    || Equals_5234480(name, "AI_MSG_L0105"))
  {
    return "battle";
  }
  if (Equals_5234480(name, "AI_MSG_L0106"))
    return "battle";
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
  v12->m_Items[0] = "\r\n";
  v14 = Split_5246672(v11, v12, 0);
  max_length = v14->max_length;
  if (max_length >= 2)
  {
    v16 = &char;
    v17 = &"//";
    v18 = &"\"";
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
            v31 = Replace_5267216(v27->m_Items[0], *v18, "");
            v33 = Replace_5267216(v27->m_Items[1], *v18, "");
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
  v2 = Load("table/MotionVoiceTable", 0);
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
  v7->m_Items[0] = "\r\n";
  v10 = Split_5246672(v6, v7, 0);
  _Clear(MotionVoiceTable);
  max_length = v10->max_length;
  if (max_length >= 2)
  {
    v13 = &char;
    v14 = &"";
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
        if (!op_Equality(v25, "//", 0))
        {
          v27 = v14;
          Replace_5267216(v24->m_Items[0], " ", *v14);
          v29 = v13;
          Replace_5267216(v24->m_Items[1], " ", *v27);
          v30 = NewSpecific(string, 2u);
          v32 = Replace_5267216(v24->m_Items[0], " ", *v27);
          v33 = v32;
          v30->memHandle = v33;
          v36 = Replace_5267216(v24->m_Items[1], " ", *v27);
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
  v2 = Load("table/VoiceTableE", 0);
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
  v7->m_Items[0] = "\r\n";
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
        if (!op_Equality(v24, "//", 0))
        {
          v25 = NewSpecific(string, 3u);
          v27 = Replace_5267216(v23->m_Items[0], " ", "");
          v28 = v27;
          v25->memHandle = v28;
          v30 = Replace_5267216(v23->m_Items[1], " ", "");
          v31 = v30;
          v25->pTexture = v31;
          v34 = Replace_5267216(v23->m_Items[2], " ", "");
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
  System_String_o *v15;
  u64 *v16;
  System_String_array *v18;
  System_String_array *v19;
  System_String_o *v21;
  s32 v22;
  System_String_o *v23;
  System_String_o *v24;
  struct System_String_o *v27;
  s32 v29;
  struct SndAssetBundleManager_RepData_mList_array *v30;
  struct SndAssetBundleManager_RepData_mList_array *v32;
  u64 v33;
  SndAssetBundleManager_RepData_mList_o *m_Items;
  System_String_o **v35;
  u64 v36;
  System_String_o *v38;
  System_String_o *v41;
  System_String_o *v44;
  System_String_o *v46;
  s32 Length;
  bool v49;
  System_Collections_Generic_Dictionary_string__SndAssetBundleManager_RepData__o *ReplaceVoiceTable;
  struct System_String_o *v53;
  System_String_array *v54;
  u64 v55;
  u16 v56[2];
  s32 result;
  SndAssetBundleManager_RepData_o v58;
  SndAssetBundleManager_RepData_o v59;

  memset(&v58, 0, sizeof(v58));
  result = 0;
  v56[0] = 0;
  v1 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v1);
  v2 = Load("table/OverwriteTable", 0);
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
  v7->m_Items[0] = "\r\n";
  v10 = Split_5246672(v6, v7, 0);
  SndAssetBundleManager_RepData___Clear(ReplaceVoiceTable);
  max_length = v10->max_length;
  if (max_length >= 2)
  {
    v13 = 0;
    v54 = v10;
    do
    {
      v15 = v10->m_Items[v13];
      v16 = NewSpecific(char, 1u);
      *(v16 + 16) = 44;
      v18 = Split(v15, v16);
      v19 = v18;
      v21 = Substring_5248048(v18->m_Items[0], 0, 2);
      if (!op_Equality(v21, "//", 0))
      {
        v22 = v19->max_length;
        if (v22 >= 5 && v22 - 2 == 3 * ((v22 - 2) / 3))
        {
          v23 = Replace_5267216(v19->m_Items[0], " ", "");
          if (IsNullOrEmpty(v23))
            v24 = "ecmn";
          else
            v24 = v23;
          v27 = Replace_5267216(v19->m_Items[1], " ", "");
          {
          }
          if (!SndAssetBundleManager_RepData___ContainsKey(ReplaceVoiceTable, v27))
          {
            v58.base_name = v27;
            *&v58.check = 0;
            v29 = LODWORD(v19->max_length) - 2;
            v55 = (v29 / 3);
            v30 = NewSpecific(SndAssetBundleManager_RepData_mList, v55);
            v58.data = v30;
            if (v29 >= 3)
            {
              v32 = v30;
              v53 = v27;
              v33 = 0;
              m_Items = v30->m_Items;
              v35 = &v19->m_Items[4];
              v36 = 4;
              do
              {
                v38 = Replace_5267216(*(v35 - 2), " ", "", 0);
                IsNullOrEmpty(v38);
                m_Items->rep_name = 0;
                *&m_Items->event_id = 0;
                v41 = Replace_5267216(*(v35 - 1), " ", "", 0);
                m_Items->rep_name = v41;
                result = -1;
                v44 = Replace_5267216(*v35, " ", "");
                if (!Equals_5234480(v44, "-1"))
                {
                  v46 = Replace_5267216(*v35, " ", "");
                  TryParse_2306272(v46, 515, 0, &result);
                }
                m_Items->event_id = result;
                Length = get_Length(v24);
                v56[0] = get_Chars(v24, Length - 1);
                v49 = sub_3C3930(v56, 0x6Du);
                ++v33;
                v36 += 3LL;
                ++m_Items;
                v35 += 3;
              }
              while (v55 != v33);
              v58.check = v49;
              v27 = v53;
            }
            {
              v10 = v54;
            }
            else
            {
              v10 = v54;
            }
            v59 = v58;
            SndAssetBundleManager_RepData___Add(ReplaceVoiceTable, v27, &v59);
          }
        }
      }
      max_length = LODWORD(v10->max_length);
      ++v13;
    }
    while (v13 < ((max_length << 32) - 0x100000000LL) >> 32);
  }
}

// 0x1330d20
void _loadbgm(s32 type, char *key) {
  Il2CppObject *Item;
  System_String_o *v9;
  System_String_o *v10[4];
  u64 v11[5];
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v17;
  s64 v18;
  s64 v19;
  s64 v20;

  v19 = 0;
  v20 = 0;
  v18 = 0;
  memset(&v17, 0, sizeof(v17));
  v12 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  if (Animator___ContainsKey(BGMBundleTable, key))
  {
    Item = object___get_Item(BGMBundleTable, key);
    SndAssetBundleManager_SndData___GetEnumerator(&v17, Item);
    while ((sub_436350(&v17)
           & 1) != 0)
    {
      sub_4365A0(&v17, v11);
      v14 = v11[2];
      v12 = v11[0];
      v13 = v11[1];
      v15 = v11[3];
      v16 = v11[4];
      sub_1A0C1C0(&v12, v10);
      v9 = v10[2];
      LoadBGM(v9);
    }
    nullsub_29(&v17);
  }
}

// 0x1331680
void _loadbgm2(char *key, char *bgm_name) {
  Il2CppObject *Item;
  Il2CppObject *v10;
  System_String_o *v11;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v12;
  s64 v13;
  s64 v14;
  s64 v15;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v16;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v17;
  s64 v18;
  s64 v19;
  s64 v20;

  v19 = 0;
  v20 = 0;
  v18 = 0;
  memset(&v17, 0, sizeof(v17));
  memset(&v16, 0, sizeof(v16));
  if (Animator___ContainsKey(BGMBundleTable, key))
  {
    Item = object___get_Item(BGMBundleTable, key);
    SndAssetBundleManager_SndData___GetEnumerator(&v12, Item);
    v17 = v12;
    v20 = v15;
    v18 = v13;
    v19 = v14;
    while ((sub_436350(&v17)
           & 1) != 0)
    {
      sub_4365A0(&v17, &v12);
      v16 = v12;
      sub_1A0C1C0(&v16, &v11);
      if (Equals_5234480(v11, key))
      {
        sub_1A0C1C0(&v16, &v12);
        if (Equals_5234480(v12.current.key, bgm_name))
        {
          sub_1A0C1C0(&v16, &v12);
          v10 = v12.current.key;
          LoadBGM(v10);
        }
      }
    }
    nullsub_29(&v17);
  }
}

// 0x1330f30
void _loadse(char *key) {
  System_Collections_Generic_Dictionary_string__int__o *LoadedTable;
  System_String_o *v5;
  Il2CppObject *Item;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  System_String_o *v13;
  System_Collections_Generic_Dictionary_string__int__o *v16;
  System_String_o *v17;
  System_String_o *v18[4];
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v19;
  s64 v20;
  s64 v21;
  s64 v22;

  v21 = 0;
  v22 = 0;
  v20 = 0;
  memset(&v19, 0, sizeof(v19));
  v5 = Concat_5224608(key, "_SE");
  if (!int___ContainsKey(LoadedTable, v5))
  {
    if (Animator___ContainsKey(SEBundleTable, key))
    {
      Item = object___get_Item(SEBundleTable, key);
      Values = SndAssetBundleManager_SndData___get_Values(Item);
      SndAssetBundleManager_SndData___GetEnumerator(&v19, Values);
      while ((sub_4D4060(&v19) & 1) != 0)
      {
        sub_4D4200(&v19, v18);
        v13 = v18[2];
        LoadSE(v13);
      }
      nullsub_47(&v19);
      v16 = LoadedTable;
      v17 = Concat_5224608(key, "_SE");
      int___Add(v16, v17, 0);
    }
  }
}

// 0x1331ae0
void _loadse2(char *key, char *se_name) {
  Il2CppObject *Item;
  System_String_o *v10;
  System_String_o *v11[4];
  u64 v12[2];
  System_String_o *name;
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  System_String_o *v18;
  s64 v19;
  s64 v20;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v21;
  s64 v22;
  s64 v23;
  s64 v24;

  v23 = 0;
  v24 = 0;
  v22 = 0;
  memset(&v21, 0, sizeof(v21));
  v16 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  if (Animator___ContainsKey(SEBundleTable, key))
  {
    Item = object___get_Item(SEBundleTable, key);
    SndAssetBundleManager_SndData___GetEnumerator(&v21, Item);
    while ((sub_436350(&v21)
           & 1) != 0)
    {
      sub_4365A0(&v21, v12);
      v18 = name;
      v16 = v12[0];
      v17 = v12[1];
      v19 = v14;
      v20 = v15;
      sub_1A0C1C0(&v16, v11);
      if (Equals_5234480(v11[2], se_name))
      {
        sub_1A0C1C0(&v16, v12);
        v10 = name;
        LoadSE(v10);
      }
    }
    nullsub_29(&v21);
  }
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
    v11->m_Items[0] = "\r\n";
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
          if (!op_Equality(v24, "//", 0))
          {
            if (get_Chars(v23->m_Items[0], 0) == 34)
            {
              v28 = Replace_5267216(v23->m_Items[0], "\"", "");
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
