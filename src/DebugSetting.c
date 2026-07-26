#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct DebugSetting DebugSetting;

static DebugSetting *_setting;

u8 Get(s32 id);
void *LoadFile_16626736(AssetBundleCtrl *this, char *key, char *path_name);

// 0xfe51b0
DebugSetting *Get(void) {
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v3;
  System_String_o *v4;
  AssetBundleCtrl_o *v5;
  System_String_o *v6;
  System_String_o *v7;
  UnityEngine_Object_o *File_16626736;
  DebugSetting_c *v11;
  struct DebugSetting_StaticFields *static_fields;
  s64 typeHierarchyDepth;
  UnityEngine_Object_o *v14;
  UnityEngine_Object_o *setting;

  asset_bc = get_asset_bc();
  v3 = StringLiteral_2012;
  v4 = StringLiteral_4663;
  v5 = asset_bc;
  v6 = StringLiteral_4586;
  v7 = Concat_5271136(v3, StringLiteral_74, v4, v6);
  File_16626736 = LoadFile_16626736(v5, v3, v7);
  else
  {
    static_fields = DebugSetting->static_fields;
    if (!File_16626736)
    {
      v14 = 0;
    }
  }
  typeHierarchyDepth = v11->_2.typeHierarchyDepth;
  if (File_16626736->klass->_2.typeHierarchyDepth < typeHierarchyDepth)
  if (File_16626736->klass->_2.typeHierarchy[typeHierarchyDepth - 1] == v11)
    v14 = File_16626736;
  else
    v14 = 0;
  static_fields->_setting = v14;
  setting = _setting;
  if (op_Equality(setting, 0, 0))
  {
    Log(StringLiteral_4664, 0);
  }
  return _setting;
}

// 0xfe50f0
bool GetDLC1Flag(DebugSetting *this) {
  DebugSetting_o *v4;

  v4 = Get();
  return op_Inequality(v4, 0, 0) && v4->_DBG_DLC1;
}

// 0xfe53d0
bool GetDLC2Flag(DebugSetting *this) {
  DebugSetting_o *v4;

  v4 = Get();
  return op_Inequality(v4, 0, 0) && v4->_DBG_DLC2;
}

// 0xfe5490
bool GetDLC3Flag(DebugSetting *this) {
  DebugSetting_o *v4;

  v4 = Get();
  return op_Inequality(v4, 0, 0) && v4->_DBG_DLC3;
}

// 0xfe5550
bool GetDLC4Flag(DebugSetting *this) {
  DebugSetting_o *v4;

  v4 = Get();
  return op_Inequality(v4, 0, 0) && v4->_DBG_DLC4;
}

// 0xfe5610
bool GetDLC5Flag(DebugSetting *this) {
  DebugSetting_o *v4;

  v4 = Get();
  return op_Inequality(v4, 0, 0) && v4->_DBG_DLC5;
}

// 0xfe56d0
bool GetDLC6Flag(DebugSetting *this) {
  DebugSetting_o *v4;

  v4 = Get();
  return op_Inequality(v4, 0, 0) && v4->_DBG_DLC6;
}

// 0xfe5790
bool GetDLC7Flag(DebugSetting *this) {
  DebugSetting_o *v4;

  v4 = Get();
  return op_Inequality(v4, 0, 0) && v4->_DBG_DLC7;
}

// 0xfe5850
bool GetDLC8Flag(DebugSetting *this) {
  DebugSetting_o *v4;

  v4 = Get();
  return op_Inequality(v4, 0, 0) && v4->_DBG_DLC8;
}

// 0xfe5910
char *GetLanguage(DebugSetting *this) {
  DebugSetting_o *v4;
  s64 *v6;

  v4 = Get();
  if (op_Equality(v4, 0, 0))
    return StringLiteral_48;
  v6 = &StringLiteral_48;
  if (v4->_DBG_LANG_JA)
    return StringLiteral_48;
  if (v4->_DBG_LANG_ENUS)
    return StringLiteral_840;
  if (v4->_DBG_LANG_FR)
    return StringLiteral_914;
  if (v4->_DBG_LANG_IT)
    return StringLiteral_932;
  if (v4->_DBG_LANG_DE)
    return StringLiteral_902;
  if (v4->_DBG_LANG_ES)
    return StringLiteral_907;
  if (v4->_DBG_LANG_ZHHANT)
    return StringLiteral_872;
  if (v4->_DBG_LANG_KO)
    v6 = &StringLiteral_49;
  return *v6;
}

// 0xfe5ac0
s32 GetPlatform(DebugSetting *this) {
  DebugSetting_o *v4;

  v4 = Get();
  if (op_Equality(v4, 0, 0))
    return 0;
  if (v4->_DBG_PLATFORM_SWITCH)
    return 0;
  if (v4->_DBG_PLATFORM_PS4)
    return 1;
  return 2 * v4->_DBG_PLATFORM_STEAM;
}
