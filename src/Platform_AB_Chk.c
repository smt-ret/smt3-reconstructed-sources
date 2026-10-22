#include "types.h"

typedef struct Platform_AB_Chk Platform_AB_Chk;

static s32 platformCnt[3];

char *ABPlatformChk(Platform_AB_Chk *this, char *filePath);
char *DlcChk(Platform_AB_Chk *this);
void *ExistsChk(Platform_AB_Chk *this, char *path, char **filename);
char *LanguageSearch(Platform_AB_Chk *this, char **languageName, void *exist, char **filename, char *platform);
char *PlatformSearch(Platform_AB_Chk *this, char *path, char **filename, char **platformAry);
void PlatformSearchSet(Platform_AB_Chk *this, char *filePath, char **platformAry);
bool dds3CheckDLC1(void);
bool dds3CheckDLC2(void);
bool dds3CheckDLC3(void);
bool dds3CheckDLC4(void);
bool dds3CheckDLC5(void);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);
bool dds3CheckDLC8(void);

// 0x188e1a0
char *ABPlatformChk(Platform_AB_Chk *this, char *filePath) {
  u64 *v4;
  System_String_array *v6;
  il2cpp_array_size_t max_length;

  v4 = NewSpecific(char, 1u);
  *(v4 + 16) = 95;
  v6 = Split(filePath, v4);
  max_length = v6->max_length;
  return v6->m_Items[((max_length << 32) - 0x200000000LL) >> 32];
}

// 0x188ddb0
char *DlcChk(Platform_AB_Chk *this) {
  bool v2;
  System_String_o **v3;
  System_String_o *v5;
  bool v6;
  System_String_o **v7;
  System_String_o *v9;
  bool v10;
  System_String_o **v11;
  System_String_o *v13;
  bool v14;
  System_String_o **v15;
  System_String_o *v17;
  bool v18;
  System_String_o **v19;
  System_String_o *v21;
  bool v22;
  System_String_o **v23;
  System_String_o *v25;
  bool v26;
  System_String_o **v27;
  System_String_o *v29;
  bool v30;
  System_String_o **v31;

  v2 = dds3CheckDLC1();
  v3 = &"[1]";
  if (!v2)
    v3 = &"[-]";
  v5 = Concat_5224608("", *v3);
  v6 = dds3CheckDLC2();
  v7 = &"[2]";
  if (!v6)
    v7 = &"[-]";
  v9 = Concat_5224608(v5, *v7);
  v10 = dds3CheckDLC3();
  v11 = &"[3]";
  if (!v10)
    v11 = &"[-]";
  v13 = Concat_5224608(v9, *v11);
  v14 = dds3CheckDLC4();
  v15 = &"[4]";
  if (!v14)
    v15 = &"[-]";
  v17 = Concat_5224608(v13, *v15);
  v18 = dds3CheckDLC5();
  v19 = &"[5]";
  if (!v18)
    v19 = &"[-]";
  v21 = Concat_5224608(v17, *v19);
  v22 = dds3CheckDLC6();
  v23 = &"[6]";
  if (!v22)
    v23 = &"[-]";
  v25 = Concat_5224608(v21, *v23);
  v26 = dds3CheckDLC7();
  v27 = &"[7]";
  if (!v26)
    v27 = &"[-]";
  v29 = Concat_5224608(v25, *v27);
  v30 = dds3CheckDLC8();
  v31 = &"[8]";
  if (!v30)
    v31 = &"[-]";
  return Concat_5224608(v29, *v31);
}

// 0x188d5f0
void *ExistsChk(Platform_AB_Chk *this, char *path, char **filename) {
  u64 *v6;
  u64 v7;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  System_String_o *v12;
  il2cpp_array_size_t v14;
  System_String_o *v16;
  System_Collections_Generic_List_int__o *v17;
  s32 v18;

  v6 = Allocate(System_Collections_Generic_List_int_);
  __ctor(v6);
  if (GetLength(filename, 0) >= 1)
  {
    v7 = 0;
    do
    {
      bounds = filename->bounds;
      length = bounds[1].length;
      v12 = filename->m_Items[length * v7];
      v14 = bounds[1].length;
      v16 = Concat_5271136(path, v12, "/", filename->m_Items[v14 * v7 + 1]);
      if (Exists(v16))
      {
        v17 = v6;
        v18 = 1;
      }
      else
      {
        v17 = v6;
        v18 = 0;
      }
      _Add(v17, v18);
      ++v7;
    }
    while (v7 < GetLength(filename, 0));
  }
  return v6;
}

// 0x188da50
char *LanguageSearch(Platform_AB_Chk *this, char **languageName, void *exist, char **filename, char *platform) {
  u64 *v10;
  u64 v11;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  Il2CppArrayBounds *v16;
  il2cpp_array_size_t v18;
  System_String_o *v20;
  u64 *v21;
  System_Collections_Generic_IEnumerable_TSource__o *v23;
  Il2CppObject *object;
  System_String_o *v25;
  u64 v26;
  Il2CppArrayBounds *v28;
  Il2CppArrayBounds *v30;
  il2cpp_array_size_t v32;

  v10 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v10);
  if (GetLength(filename, 0) >= 1)
  {
    v11 = 0;
    do
    {
      bounds = filename->bounds;
      length = bounds[1].length;
      if (op_Equality(platform, filename->m_Items[length * v11], 0)
        && _get_Item(
             exist,
             v11) == 1)
      {
        v16 = filename->bounds;
        v18 = v16[1].length;
        v20 = filename->m_Items[v18 * v11 + 1];
        v21 = NewSpecific(char, 1u);
        *(v21 + 16) = 95;
        v23 = Split(v20, v21);
        object = Last_object_(v23);
        _Add(v10, object);
      }
      ++v11;
    }
    while (v11 < GetLength(filename, 0));
  }
  v25 = "";
  if (GetLength(languageName, 1) >= 1)
  {
    v26 = 0;
    do
    {
      v30 = languageName->bounds;
      if ((_IndexOf(
              v10,
              languageName->m_Items[v26])
          & 0x80000000) == 0)
      {
        if (op_Inequality(v25, "", 0))
        {
          v25 = Concat_5224608(v25, " + ");
          v28 = languageName->bounds;
          if (LODWORD(v28->length) <= 1)
            goto LABEL_23;
        }
        else
        {
          v28 = languageName->bounds;
          if (LODWORD(v28->length) <= 1)
          {
LABEL_23:
          }
        }
        v32 = v28[1].length;
        v25 = Concat_5224608(v25, *(&languageName->m_Items[v26] + v32), 0);
      }
      ++v26;
    }
    while (v26 < GetLength(languageName, 1));
  }
  return v25;
}

// 0x188d790
char *PlatformSearch(Platform_AB_Chk *this, char *path, char **filename, char **platformAry) {
  System_String_o *v9;
  u64 v11;
  u64 v12;
  Il2CppArrayBounds *bounds;
  il2cpp_array_size_t length;
  System_String_o *v17;
  Il2CppArrayBounds *v18;
  il2cpp_array_size_t v20;
  System_String_o *v22;
  u64 v26;
  struct System_Int32_array *platformCnt;
  Il2CppArrayBounds *v30;
  il2cpp_array_size_t v32;

  v9 = "";
  if (GetLength(filename, 0) >= 1)
  {
    v11 = 0;
    do
    {
      if (GetLength(platformAry, 1) >= 1)
      {
        v12 = 0;
        do
        {
          bounds = platformAry->bounds;
          length = bounds[1].length;
          v17 = *(&platformAry->m_Items[v12] + length);
          v18 = filename->bounds;
          v20 = v18[1].length;
          v22 = Concat_5271136(path, v17, "/", filename->m_Items[v20 * v11 + 1]);
          PlatformSearchSet(this, v22, platformAry);
          ++v12;
        }
        while (v12 < GetLength(platformAry, 1));
      }
      ++v11;
    }
    while (v11 < GetLength(filename, 0));
  }
  if (Sum(platformCnt) == 1
    && GetLength(platformAry, 1) >= 1)
  {
    v26 = 0;
    do
    {
      if (platformCnt->m_Items[v26] == 1)
      {
        v30 = platformAry->bounds;
        v32 = v30[1].length;
        v9 = *(&platformAry->m_Items[v26] + v32);
      }
      ++v26;
    }
    while (v26 < GetLength(platformAry, 1));
  }
  return v9;
}

// 0x188e030
void PlatformSearchSet(Platform_AB_Chk *this, char *filePath, char **platformAry) {
  _BOOL8 v6;
  System_String_o *v8;
  u64 v9;
  Il2CppArrayBounds *bounds;
  struct System_Int32_array *platformCnt;

  v6 = Exists(filePath);
  if (v6)
  {
    v8 = ABPlatformChk(v6, filePath);
    if (GetLength(platformAry, 1) >= 1)
    {
      v9 = 0;
      do
      {
        bounds = platformAry->bounds;
        if (op_Equality(platformAry->m_Items[v9], v8, 0))
        {
          platformCnt->m_Items[v9] = 1;
        }
        ++v9;
      }
      while (v9 < GetLength(platformAry, 1));
    }
  }
}

// 0x188c550
void Start(Platform_AB_Chk *this) {
  System_String_o *dataPath;
  System_String_o *v4;
  System_String_array *v5;
  Il2CppArrayBounds *bounds;
  System_String_array *v7;
  il2cpp_array_size_t length;
  Il2CppArrayBounds *v12;
  il2cpp_array_size_t v14;
  Il2CppArrayBounds *v16;
  il2cpp_array_size_t v18;
  Il2CppArrayBounds *v20;
  il2cpp_array_size_t v22;
  il2cpp_array_size_t v25;
  Il2CppArrayBounds *v27;
  il2cpp_array_size_t v29;
  Il2CppArrayBounds *v31;
  il2cpp_array_size_t v33;
  il2cpp_array_size_t v36;
  il2cpp_array_size_t v39;
  Il2CppArrayBounds *v41;
  il2cpp_array_size_t v43;
  Il2CppArrayBounds *v45;
  il2cpp_array_size_t v47;
  Il2CppArrayBounds *v49;
  il2cpp_array_size_t v51;
  il2cpp_array_size_t v54;
  Il2CppArrayBounds *v56;
  il2cpp_array_size_t v58;
  Il2CppArrayBounds *v60;
  il2cpp_array_size_t v62;
  il2cpp_array_size_t v65;
  il2cpp_array_size_t v68;
  Il2CppArrayBounds *v70;
  il2cpp_array_size_t v72;
  Il2CppArrayBounds *v74;
  il2cpp_array_size_t v76;
  Il2CppArrayBounds *v78;
  il2cpp_array_size_t v80;
  il2cpp_array_size_t v83;
  Il2CppArrayBounds *v85;
  il2cpp_array_size_t v87;
  System_String_array *v89;
  Il2CppArrayBounds *v90;
  System_String_array *v91;
  il2cpp_array_size_t v95;
  Il2CppArrayBounds *v97;
  il2cpp_array_size_t v99;
  Il2CppArrayBounds *v101;
  il2cpp_array_size_t v103;
  Platform_AB_Chk_o *v105;
  u32 *m_CachedPtr;
  System_String_array *v108;
  s64 v113;
  intptr_t v115;
  s64 v117;
  intptr_t v119;
  s64 v121;
  intptr_t v123;
  s64 v125;
  System_Collections_Generic_List_int__o *v127;
  System_String_o *v129;
  _BOOL8 v130;
  System_String_o *v133;
  s64 *v134;
  System_String_o *v135;
  TMPro_TMP_Text_o *text;
  s64 *v137;
  System_String_array *v138;
  System_String_o *v158;
  s64 v164[2];
  s64 v165[2];
  s64 v166[2];

  this->text = GetComponent_GUILayer_(this);
  dataPath = get_dataPath();
  v4 = Concat_5224608(dataPath, "/StreamingAssets/");
  v166[0] = 12;
  v166[1] = 2;
  v5 = sub_8DB0C0(string_, v166, 0);
  bounds = v5->bounds;
  v7 = v5;
  v5->m_Items[0] = "Switch";
  v5->m_Items[1] = "debug_platform_ab_chk_switch_en";
  length = bounds[1].length;
  v5->m_Items[length] = "Switch";
  v12 = v5->bounds;
  v14 = v12[1].length;
  v5->m_Items[v14 + 1] = "debug_platform_ab_chk_switch_ja";
  v16 = v5->bounds;
  v18 = v16[1].length;
  v5->m_Items[2 * v18] = "Switch";
  v20 = v5->bounds;
  v22 = v20[1].length;
  *(v5->m_Items + ((16 * v22) | 8)) = "debug_platform_ab_chk_switch_ko";
  v25 = v20[1].length;
  v5->m_Items[3 * v25] = "Switch";
  v27 = v5->bounds;
  v29 = v27[1].length;
  v5->m_Items[3 * v29 + 1] = "debug_platform_ab_chk_switch_zh";
  v31 = v5->bounds;
  v33 = v31[1].length;
  v5->m_Items[4 * v33] = "PS4";
  v36 = v31[1].length;
  *(v5->m_Items + ((32 * v36) | 8)) = "debug_platform_ab_chk_ps4_en";
  v39 = v31[1].length;
  v5->m_Items[5 * v39] = "PS4";
  v41 = v5->bounds;
  v43 = v41[1].length;
  v5->m_Items[5 * v43 + 1] = "debug_platform_ab_chk_ps4_ja";
  v45 = v5->bounds;
  v47 = v45[1].length;
  v5->m_Items[6 * v47] = "PS4";
  v49 = v5->bounds;
  v51 = v49[1].length;
  *(v5->m_Items + ((48 * v51) | 8)) = "debug_platform_ab_chk_ps4_ko";
  v54 = v49[1].length;
  v5->m_Items[7 * v54] = "PS4";
  v56 = v5->bounds;
  v58 = v56[1].length;
  v5->m_Items[7 * v58 + 1] = "debug_platform_ab_chk_ps4_zh";
  v60 = v5->bounds;
  v62 = v60[1].length;
  v5->m_Items[8 * v62] = "Pc";
  v65 = v60[1].length;
  *(v5->m_Items + ((v65 << 6) | 8)) = "debug_platform_ab_chk_steam_en";
  v68 = v60[1].length;
  v5->m_Items[9 * v68] = "Pc";
  v70 = v5->bounds;
  v72 = v70[1].length;
  v5->m_Items[9 * v72 + 1] = "debug_platform_ab_chk_steam_ja";
  v74 = v5->bounds;
  v76 = v74[1].length;
  v5->m_Items[10 * v76] = "Pc";
  v78 = v5->bounds;
  v80 = v78[1].length;
  *(v5->m_Items + ((80 * v80) | 8)) = "debug_platform_ab_chk_steam_ko";
  v83 = v78[1].length;
  v5->m_Items[11 * v83] = "Pc";
  v85 = v5->bounds;
  v87 = v85[1].length;
  v5->m_Items[11 * v87 + 1] = "debug_platform_ab_chk_steam_zh";
  v165[0] = 2;
  v165[1] = 3;
  v89 = sub_8DB0C0(string_, v165, 0);
  v90 = v89->bounds;
  v91 = v89;
  v89->m_Items[0] = "switch";
  v89->m_Items[1] = "ps4";
  v89->m_Items[2] = "steam";
  v95 = v90[1].length;
  v89->m_Items[v95] = "Switch";
  v97 = v89->bounds;
  v99 = v97[1].length;
  v89->m_Items[v99 + 1] = "PS4";
  v101 = v89->bounds;
  v103 = v101[1].length;
  v89->m_Items[v103 + 2] = "Pc";
  v164[0] = 2;
  v164[1] = 4;
  v105 = sub_8DB0C0(string_, v164, 0);
  m_CachedPtr = v105->m_CachedPtr;
  v108 = v105;
  v105[1].klass = "en";
  v105[1].monitor = "ja";
  v105[1].m_CachedPtr = "ko";
  v105[1].text = "zh";
  v113 = *(m_CachedPtr + 2);
  *(&v105[1].klass + v113) = "EFIGS";
  v115 = v105->m_CachedPtr;
  v117 = *(v115 + 16);
  *(&v105[1].monitor + v117) = "Japan";
  v119 = v105->m_CachedPtr;
  v121 = *(v119 + 16);
  *(&v105[1].m_CachedPtr + v121) = "Korea";
  v123 = v105->m_CachedPtr;
  v125 = *(v123 + 16);
  *(&v105[1].text + v125) = "China";
  v127 = ExistsChk(v105, v4, v7);
  v129 = PlatformSearch(this, v4, v7, v91);
  v130 = op_Inequality(v129, "", 0);
  if (v130)
  {
    v133 = LanguageSearch(v130, v108, v127, v7, v129);
    v130 = op_Equality(v133, "", 0);
    if (v130)
      v134 = "unknown";
    else
      v134 = v133;
  }
  else
  {
    v134 = "unknown";
    v129 = "unknown";
  }
  v135 = DlcChk(v130);
  text = this->text;
  v137 = v135;
  v138 = NewSpecific(string, 6u);
  v138->m_Items[0] = "Platform: ";
  v138->m_Items[1] = v129;
  v138->m_Items[2] = "  Language: ";
  v138->m_Items[3] = v134;
  v138->m_Items[4] = "  DLC: ";
  v138->m_Items[5] = v137;
  v158 = Concat_5271600(v138);
  set_text(text, v158);
}

// 0x188e260
void Update(Platform_AB_Chk *this) {
  ;
}
