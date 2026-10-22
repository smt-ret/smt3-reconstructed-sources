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
  s64 typeHierarchyDepth;
  UnityEngine_Object_o *v14;
  UnityEngine_Object_o *setting;

  asset_bc = get_asset_bc();
  v3 = "debug";
  v4 = "DebugSetting";
  v5 = asset_bc;
  v6 = ".asset";
  v7 = Concat_5271136(v3, "/", v4, v6);
  File_16626736 = LoadFile_16626736(v5, v3, v7);
  else
  {
    if (!File_16626736)
    {
LABEL_14:
      v14 = 0;
      goto LABEL_18;
    }
  }
  typeHierarchyDepth = v11->_2.typeHierarchyDepth;
  if (File_16626736->klass->_2.typeHierarchyDepth < typeHierarchyDepth)
    goto LABEL_14;
  if (File_16626736->klass->_2.typeHierarchy[typeHierarchyDepth - 1] == v11)
    v14 = File_16626736;
  else
    v14 = 0;
LABEL_18:
  _setting = v14;
  setting = _setting;
  if (op_Equality(setting, 0, 0))
  {
    Log("_setting Is Null ", 0);
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
    return "ja";
  v6 = &"ja";
  if (v4->_DBG_LANG_JA)
    return "ja";
  if (v4->_DBG_LANG_ENUS)
    return "en-US";
  if (v4->_DBG_LANG_FR)
    return "fr";
  if (v4->_DBG_LANG_IT)
    return "it";
  if (v4->_DBG_LANG_DE)
    return "de";
  if (v4->_DBG_LANG_ES)
    return "es";
  if (v4->_DBG_LANG_ZHHANT)
    return "zh-Hant";
  if (v4->_DBG_LANG_KO)
    v6 = &"ko";
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
