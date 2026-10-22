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
  v3[1].klass = Replace_5267216(name, Appendix, "");
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
  struct System_String_array *LangTagTable;
  s64 LangID;

  return Concat_5224608("_", LangTagTable->m_Items[LangID]);
}

// 0x128fcf0
s32 GetBaseLanguage(void) {
  System_String_o *Desired;
  System_Object_array *v4;
  s64 *strLanguage;
  s64 *v9;
  s64 *v10;
  Il2CppObject *v13;
  s32 v19;

  Desired = GetDesired();
  strLanguage = Desired;
  LangID = 0;
  v4 = NewSpecific(object, 4u);
  v4->m_Items[0] = "Language : ";
  v4->m_Items[1] = strLanguage;
  v4->m_Items[2] = ",";
  v19 = 0;
  v9 = sub_8D3950(s32, &v19);
  v10 = v9;
  v4->m_Items[3] = v10;
  v13 = Concat_5270224(v4);
  Log(v13, 0);
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
  v5 = Replace_5267216(key, Appendix, "");
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
  struct System_String_array *LangTagTable;
  s64 LangID;

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
    return "";
  v3 = Replace_5267216(ID, "<", "");
  v5 = Replace_5267216(v3, ">", "");
  v6 = 0;
    goto LABEL_10;
LABEL_8:
  while (1)
  {
LABEL_10:
    if (v6 >= _get_Count(DataList))
    {
      if (Equals_5239888(v5, "nulldata", 5))
        return " ";
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
      goto LABEL_8;
  }
  _get_Item(
    &v13,
    DataList,
    v6);
  Item = object___get_Item(v13.data, v5);
  if (op_Equality(Item, "null", 0)
    || op_Equality(Item, "NULL", 0))
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
    return "";
  v5 = Replace_5267216(ID, "<", "");
  v7 = Replace_5267216(v5, ">", "");
  v8 = ContainsIndex(dic);
  if (v8 == -1)
    return "";
LABEL_8:
  v10 = v8;
  _get_Item(
    &v17,
    DataList,
    v10);
  if (!Animator___ContainsKey(v17.data, v7))
    return "";
  _get_Item(
    &v17,
    DataList,
    v10);
  Item = object___get_Item(v17.data, v7);
  if (Equals_5239888(Item, "null", 5))
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
  return Concat_5224608("_", v6);
}

// 0x1291870
void Load(char *key, char *filePath) {
  System_String_o *Appendix;
  System_String_o *v7;
  System_String_o *v8;
  System_String_o *v10;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v14;
  System_String_o *v15;
  UnityEngine_Object_o *Asset;
  s64 typeHierarchyDepth;
  UnityEngine_Object_o *v19;
  System_Collections_Generic_List_Localize_EvtMsgDat__o *DataList;
  Localize_EvtMsgDat_o v24;
  Localize_EvtMsgDat_o v25;

  Appendix = GetAppendix();
  v7 = Replace_5267216(key, Appendix, "");
  v8 = GetAppendix(v7);
  v10 = Concat_5224608(v7, v8);
  asset_bc = get_asset_bc();
  if (IsLoad(asset_bc, v10))
  {
    else if (ContainsIndex(key) != -1)
    {
      return;
    }
    v14 = get_asset_bc();
    v15 = ToUpper(v10, 0);
    Asset = LoadAsset(v14, v10, filePath, v15, 0);
    if (Asset
          Asset->klass->_2.typeHierarchyDepth >= typeHierarchyDepth))
    {
      if (Asset->klass->_2.typeHierarchy[typeHierarchyDepth - 1] == EventEMsgData)
        v19 = Asset;
      else
        v19 = 0;
    }
    else
    {
      v19 = 0;
    }
    if (op_Inequality(v19, 0, 0))
    {
      memset(&v24, 0, sizeof(v24));
      sub_1290FC0(&v24, key, v19);
      v25 = v24;
      _Add(DataList, &v25);
    }
  }
}

// 0x1290870
void LoadBattleLocalizeText(void) {
  Localize_c *v3;
  u64 v4;
  u64 v5;
  System_String_o *v6;
  struct System_String_array *RaceTable;
  struct System_String_array *ActionTable;
  System_String_o *v12;

  v4 = 0;
  {
LABEL_6:
  }
  while (v4 < SLODWORD(RaceTable->max_length))
  {
    v5 = 0;
    if ((v3->_2.bitflags2 & 2) == 0)
      goto LABEL_14;
LABEL_12:
LABEL_14:
    while (1)
    {
      if (v5 >= SLODWORD(ActionTable->max_length))
        break;
      else
      {
        if (v4 >= LODWORD(RaceTable->max_length))
          goto LABEL_18;
      }
      v12 = RaceTable->m_Items[v4];
      v6 = Concat_5221536(v12, "_", ActionTable->m_Items[v5]);
      LoadLocalizeText("battle", v6);
      ++v5;
        goto LABEL_12;
    }
    ++v4;
    if ((v3->_2.bitflags2 & 2) != 0)
      goto LABEL_6;
  }
  LoadLocalizeText("battle", "BOSS_STOPMES");
  LoadLocalizeText("battle", "INNEN");
  LoadLocalizeText("battle", "NEGO_HELP");
  LoadLocalizeText("battle", "NEGO_HELP_UP");
  LoadLocalizeText("battle", "PUNK_INNEN");
  LoadLocalizeText("common", "DATITEMHELP");
  LoadLocalizeText("battle", "DATJYOKYOHELP");
  LoadLocalizeText("common", "DATSKILLHELP");
  LoadLocalizeText("battle", "MISCACTION");
  LoadLocalizeText("battle", "DATACTIONMISCHELP");
}

// 0x12902c0
void LoadCommonData(void) {
  System_String_o *PlatformStr;
  System_String_o *v18;
  System_String_o *v19;
  System_String_o *v20;

  LoadLocalizeText("common", "COMMON");
  LoadLocalizeText("common", "FLDTERM");
  LoadLocalizeText("common", "DEVIL");
  LoadLocalizeText("common", "RACE");
  LoadLocalizeText("common", "ITEM");
  LoadLocalizeText("common", "GUIDE");
  LoadLocalizeText("common", "AUTOMAP");
  LoadLocalizeText("common", "HEARTS");
  LoadLocalizeText("common", "SKILL");
  LoadLocalizeText("common", "ETC");
  LoadLocalizeText("common", "AISYO");
  LoadLocalizeText("common", "AREA");
  LoadLocalizeText("common", "BASYO");
  LoadLocalizeText("common", "FLOOR");
  PlatformStr = GetPlatformStr();
  v18 = Concat_5224608("common", PlatformStr);
  v19 = GetPlatformStr(v18);
  v20 = Concat_5224608("ETC", v19);
  LoadLocalizeText(v18, v20);
}

// 0x1290240
void LoadDefault(s32 language) {
  _Clear(DataList);
  LoadCommonData();
}

// 0x1291110
void LoadEventData(char *key, char *name, s32 eventno, bool check) {
  struct System_String_array *LangTagTable;
  s64 LangID;
  System_String_o *v13;
  System_Object_array *v14;
  System_String_o *v15;
  System_String_o *Appendix;
  System_String_o *v17;
  System_Object_array *v19;
  s64 *v24;
  s64 *v25;
  Il2CppObject *v28;
  AssetBundleCtrl_o *asset_bc;
  System_Collections_Generic_List_Localize_EvtMsgDat__o *DataList;
  System_String_o *v54;
  struct System_String_array *v57;
  s64 v58;
  System_String_o *v61;
  AssetBundleCtrl_o *v62;
  System_String_o *v63;
  System_String_o *v65;
  AssetBundleCtrl_o *v67;
  UnityEngine_Object_o *v68;
  s64 v70;
  UnityEngine_Object_o *v71;
  System_Collections_Generic_List_Localize_EvtMsgDat__o *v74;
  System_String_o *v75;
  Localize_EvtMsgDat_o v76;
  Localize_EvtMsgDat_o v77;

  v13 = Concat_5224608("dds3Data/localize_text/", LangTagTable->m_Items[LangID]);
  v14 = Empty_string_();
  v15 = Format_5268784(v13, v14);
  Appendix = GetAppendix(v15);
  v17 = Replace_5267216(name, Appendix, "");
  Load(v17, v15);
  v19 = NewSpecific(object, 4u);
  v19->m_Items[0] = "LoadEventData : ";
  v19->m_Items[1] = key;
  v19->m_Items[2] = ",";
  LODWORD(v77.name) = eventno;
  v24 = sub_8D3950(s32, &v77);
  v25 = v24;
  v19->m_Items[3] = v25;
  v28 = Concat_5270224(v19);
  Log(v28, 0);
  asset_bc = get_asset_bc();
  if (IsLoad(asset_bc, key))
  {
    else if (ContainsIndex(key) == -1)
    {
      goto LABEL_36;
    }
    if (eventno <= 599)
    {
      v54 = ToUpper(v17, 0);
      v57 = LangTagTable;
      v58 = LangID;
      v61 = Concat_5221536(v54, "INF_", v57->m_Items[v58]);
      v62 = get_asset_bc();
      v63 = Concat_5271136(v15, "/", v61, ".asset");
      if (IsFileExists(v62, key, v63))
      {
        v65 = Concat_5224608(v17, "inf");
        if (ContainsIndex(v65) == -1)
        {
          v67 = get_asset_bc();
          v68 = LoadAsset(v67, key, v15, v61, 0);
          {
            if (v68->klass->_2.typeHierarchy[v70 - 1] == EventEMsgData)
              v71 = v68;
            else
              v71 = 0;
          }
          else
          {
            v71 = 0;
          }
          if (op_Inequality(v71, 0, 0))
          {
            v74 = DataList;
            v75 = Concat_5224608(v17, "inf");
            memset(&v76, 0, sizeof(v76));
            sub_1290FC0(&v76, v75, v71);
            v77 = v76;
            _Add(v74, &v77);
          }
        }
      }
    }
  }
}

// 0x12905b0
void LoadLocalizeText(char *key, char *filename) {
  System_String_o *Appendix;
  System_String_o *v7;
  System_String_o *v8;
  System_String_o *v10;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v15;
  struct System_String_array *LangTagTable;
  s64 LangID;
  System_String_o *v21;
  System_String_o *v22;
  System_String_o *v23;
  UnityEngine_Object_o *Asset;
  s64 typeHierarchyDepth;
  UnityEngine_Object_o *v27;
  System_Collections_Generic_List_Localize_EvtMsgDat__o *DataList;
  Localize_EvtMsgDat_o v32;
  Localize_EvtMsgDat_o v33;

  Appendix = GetAppendix();
  v7 = Replace_5267216(key, Appendix, "");
  v8 = GetAppendix(v7);
  v10 = Concat_5224608(v7, v8);
  asset_bc = get_asset_bc();
  if (IsLoad(asset_bc, v10))
  {
    else if (ContainsIndex(filename) != -1)
    {
      return;
    }
    v15 = get_asset_bc();
    v21 = Concat_5224608("dds3Data/localize_text/", LangTagTable->m_Items[LangID]);
    v22 = GetAppendix(v21);
    v23 = Concat_5224608(filename, v22);
    Asset = LoadAsset(v15, v10, v21, v23, 0);
    if (Asset
          Asset->klass->_2.typeHierarchyDepth >= typeHierarchyDepth))
    {
      if (Asset->klass->_2.typeHierarchy[typeHierarchyDepth - 1] == EventEMsgData)
        v27 = Asset;
      else
        v27 = 0;
    }
    else
    {
      v27 = 0;
    }
    if (op_Inequality(v27, 0, 0))
    {
      memset(&v32, 0, sizeof(v32));
      sub_1290FC0(&v32, filename, v27);
      v33 = v32;
      _Add(DataList, &v33);
    }
  }
}

// 0x1291ac0
void ReleaseEventData(s32 eventno) {
  u64 *v3;
  System_String_o *v4;
  u64 *v5;
  System_String_o *v7;
  s32 v8;
  s32 v10;
  u64 *v13;
  System_String_o *v14;
  u64 *v15;
  System_String_o *v17;
  s32 v18;
  s32 v20;
  s32 v23;
  s32 v24;

  v24 = eventno;
  v3 = sub_8D3950(s32, &v24);
  v4 = Format("e{0:D3}", v3, 0);
  v23 = eventno;
  v5 = sub_8D3950(s32, &v23);
  v7 = Format("e{0:D3}m", v5, 0);
  v8 = ContainsIndex(v4);
  if (v8 != -1)
  {
    v10 = v8;
    if (ContainsIndex(v7) != -1)
    {
      _RemoveAt(DataList, v10);
    }
  }
  v24 = eventno;
  v13 = sub_8D3950(s32, &v24);
  v14 = Format("e{0:D3}inf", v13, 0);
  v23 = eventno;
  v15 = sub_8D3950(s32, &v23);
  v17 = Format("e{0:D3}minf", v15, 0);
  v18 = ContainsIndex(v14);
  if (v18 != -1)
  {
    v20 = v18;
    if (ContainsIndex(v17) != -1)
    {
      _RemoveAt(DataList, v20);
    }
  }
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
  v5 = Replace_5267216(key, Appendix, "");
  v6 = Concat_5224608(v5, Appendix);
  v8 = ContainsIndex(v6);
  if (v8 != -1)
  {
    v10 = v8;
    _RemoveAt(DataList, v10);
  }
  v13 = Concat_5221536(v5, "INF", Appendix);
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
  Localize_c *v2;
  u64 v3;
  u64 v4;
  System_String_o *v5;
  struct System_String_array *RaceTable;
  struct System_String_array *ActionTable;
  System_String_o *v11;

  v3 = 0;
  {
LABEL_6:
  }
  while (v3 < SLODWORD(RaceTable->max_length))
  {
    v4 = 0;
    if ((v2->_2.bitflags2 & 2) == 0)
      goto LABEL_14;
LABEL_12:
LABEL_14:
    while (1)
    {
      if (v4 >= SLODWORD(ActionTable->max_length))
        break;
      else
      {
        if (v3 >= LODWORD(RaceTable->max_length))
          goto LABEL_18;
      }
      v11 = RaceTable->m_Items[v3];
      v5 = Concat_5221536(v11, "_", ActionTable->m_Items[v4]);
      Remove(v5);
      ++v4;
        goto LABEL_12;
    }
    ++v3;
    if ((v2->_2.bitflags2 & 2) != 0)
      goto LABEL_6;
  }
  Remove("BOSS_STOPMES");
  Remove("INNEN");
  Remove("NEGO_HELP");
  Remove("NEGO_HELP_UP");
  Remove("PUNK_INNEN");
  Remove("DATITEMHELP");
  Remove("DATJYOKYOHELP");
  Remove("DATSKILLHELP");
  Remove("MISCACTION");
  Remove("DATACTIONMISCHELP");
}

// 0x1292220
void SettingFontMaterial(void) {
  u64 *v2;
  u32 *v3;
  s32 v37;
  s64 v38;
  System_String_o **v39;
  s64 *v40;
  System_String_o *v41;
  System_String_o *v42;
  Il2CppObject *v44;
  s64 v45;
  u64 v46;
  u64 *v47;
  System_String_o *v53;
  Il2CppObject *object;
  AssetBundleCtrl_o *asset_bc;
  UnityEngine_Object_o *File;
  s64 typeHierarchyDepth;
  UnityEngine_Texture_o *mainTexture;
  System_Object_array *v61;
  s64 *v63;
  s64 *v64;
  UnityEngine_Texture_o *v67;
  s64 *v68;
  s64 *v69;
  Il2CppObject *v72;
  u64 v73;
  u64 *v74;
  System_String_o *v76;
  Il2CppObject *v77;
  System_String_o *v79;
  UnityEngine_Texture_o *v80;
  System_String_o *v81;
  Il2CppObject *v83;
  u64 *v116;
  s32 v117;

  v2 = NewSpecific(string, 0x20u);
  v3 = v2 + 3;
  v2[4] = "MsgFont0";
  v2[5] = "MsgFont1";
  v2[6] = "MsgFont2";
  v2[7] = "MsgFont3";
  v2[8] = "MsgFont4";
  v2[9] = "MsgFont5";
  v2[10] = "TMC00";
  v2[11] = "TMC01";
  v2[12] = "TMC02";
  v2[13] = "TMC03";
  v2[14] = "TMC04";
  v2[15] = "TMC05";
  v2[16] = "TMC06";
  v2[17] = "TMC07";
  v2[18] = "TMC08";
  v2[19] = "TMC09";
  v2[20] = "TMC10";
  v2[21] = "TMC11";
  v2[22] = "TMC12";
  v2[23] = "TMC13";
  v2[24] = "TMC14";
  v2[25] = "TMC15";
  v2[26] = "TMC16";
  v2[27] = "TMC17";
  v2[28] = "TMC18";
  v2[29] = "TMC19";
  v2[30] = "TMC20";
  v2[31] = "TMC21";
  v2[32] = "TMC22";
  v2[33] = "TMC23";
  v2[34] = "TMC24";
  v2[35] = "TMC25";
LABEL_135:
  v37 = LangID - 1;
  if (v37 > 6)
  {
    v40 = &"_font-ja";
    v39 = &"font-ja/Materials";
  }
  else
  {
    v38 = v37;
    v39 = *(&off_3B2BFD0 + v38 * 8);
    v40 = off_3B2C008[v38];
  }
  v41 = *v39;
  v42 = *v40;
  v44 = Concat_5271136("LoadMat[", *v40, "] : ", *v39);
  Log(v44, 0);
  v45 = *v3;
  if (*v3 >= 1)
  {
    v46 = 0;
    v47 = v2 + 4;
    v116 = v2;
    do
    {
      v53 = Concat_5224608("Fonts & Materials/", v47[v46]);
      object = Load_object_(v53);
      asset_bc = get_asset_bc();
      File = LoadFile(asset_bc, v42, v41, v47[v46], ".mat");
      if (File)
      {
        if (File->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
        {
          if (File->klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Material)
            File = 0;
        }
        else
        {
          File = 0;
        }
      }
      mainTexture = get_mainTexture(File);
      set_mainTexture(object, mainTexture);
      v61 = NewSpecific(object, 4u);
      v61->m_Items[0] = "SaveMat[";
      v117 = v46;
      v63 = sub_8D3950(s32, &v117);
      v64 = v63;
      v61->m_Items[1] = v64;
      v61->m_Items[2] = "] : ";
      v67 = get_mainTexture(object);
      v68 = (v67->klass->vtable._3_ToString.methodPtr)(v67, v67->klass->vtable._3_ToString.method);
      v69 = v68;
      v61->m_Items[3] = v69;
      v72 = Concat_5270224(v61);
      Log(v72, 0);
      LODWORD(v45) = *v3;
      ++v46;
    }
    while (v46 < *v3);
    if (v45 >= 1)
    {
      v73 = 0;
      v74 = v116 + 4;
      do
      {
        v76 = Concat_5224608("Fonts & Materials/", v74[v73]);
        v77 = Load_object_(v76);
        v79 = v74[v73];
        v80 = get_mainTexture(v77);
        v81 = (v80->klass->vtable._3_ToString.methodPtr)(v80, v80->klass->vtable._3_ToString.method);
        v83 = Concat_5271136("CheckMat[", v79, "] : ", v81);
        Log(v83, 0);
        LODWORD(v45) = *v3;
        ++v73;
      }
      while (v73 < *v3);
    }
  }
}
