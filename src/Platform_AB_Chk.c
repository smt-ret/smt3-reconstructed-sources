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
  v3 = &StringLiteral_8809;
  if (!v2)
    v3 = &StringLiteral_8808;
  v5 = Concat_5224608(StringLiteral_416, *v3);
  v6 = dds3CheckDLC2();
  v7 = &StringLiteral_8810;
  if (!v6)
    v7 = &StringLiteral_8808;
  v9 = Concat_5224608(v5, *v7);
  v10 = dds3CheckDLC3();
  v11 = &StringLiteral_8811;
  if (!v10)
    v11 = &StringLiteral_8808;
  v13 = Concat_5224608(v9, *v11);
  v14 = dds3CheckDLC4();
  v15 = &StringLiteral_8812;
  if (!v14)
    v15 = &StringLiteral_8808;
  v17 = Concat_5224608(v13, *v15);
  v18 = dds3CheckDLC5();
  v19 = &StringLiteral_8813;
  if (!v18)
    v19 = &StringLiteral_8808;
  v21 = Concat_5224608(v17, *v19);
  v22 = dds3CheckDLC6();
  v23 = &StringLiteral_8814;
  if (!v22)
    v23 = &StringLiteral_8808;
  v25 = Concat_5224608(v21, *v23);
  v26 = dds3CheckDLC7();
  v27 = &StringLiteral_8815;
  if (!v26)
    v27 = &StringLiteral_8808;
  v29 = Concat_5224608(v25, *v27);
  v30 = dds3CheckDLC8();
  v31 = &StringLiteral_8816;
  if (!v30)
    v31 = &StringLiteral_8808;
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
      v16 = Concat_5271136(path, v12, StringLiteral_74, filename->m_Items[v14 * v7 + 1]);
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
  v25 = StringLiteral_416;
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
        if (op_Inequality(v25, StringLiteral_416, 0))
        {
          v25 = Concat_5224608(v25, StringLiteral_8817);
          v28 = languageName->bounds;
          if (LODWORD(v28->length) <= 1)
        }
        else
        {
          v28 = languageName->bounds;
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

  v9 = StringLiteral_416;
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
          v22 = Concat_5271136(path, v17, StringLiteral_74, filename->m_Items[v20 * v11 + 1]);
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
    ExistsChk(0, 0, 0);
    PlatformSearch(0, 0, 0, 0);
    LanguageSearch(0, 0, 0, 0, 0);
    DlcChk(0);
}

// 0x188e260
void Update(Platform_AB_Chk *this) {
  ;
}
