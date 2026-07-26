#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct ChangeFont ChangeFont;

s32 GetLanguage(void);
void *LoadFile_16626736(AssetBundleCtrl *this, char *key, char *path_name);

// 0xfe1d20
void Awake(ChangeFont *this) {
  UnityEngine_GUILayer_o *Component_GUILayer;
  s32 Language;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v8;
  System_String_o *v9;
  System_String_o *v10;
  AssetBundleCtrl_o *v11;
  System_String_o *v12;
  System_String_o *v13;
  UnityEngine_Object_o *File_16626736;
  s64 typeHierarchyDepth;
  TMPro_TMP_FontAsset_o *v18;
  AssetBundleCtrl_o *v19;
  System_String_o *v20;
  System_String_o *v21;
  System_String_o *v22;
  AssetBundleCtrl_o *v23;
  System_String_o *v24;
  System_String_o *v25;
  UnityEngine_Object_o *v27;
  s64 v28;
  f32 v29;
  AssetBundleCtrl_o *v30;
  System_String_o *v31;
  System_String_o *v32;
  System_String_o *v33;
  AssetBundleCtrl_o *v34;
  System_String_o *v35;
  System_String_o *v36;
  UnityEngine_Object_o *v38;
  s64 v39;
  AssetBundleCtrl_o *v40;
  System_String_o *v41;
  System_String_o *v42;
  System_String_o *v43;
  AssetBundleCtrl_o *v44;
  System_String_o *v45;
  System_String_o *v46;

  Component_GUILayer = GetComponent_GUILayer_(this);
  Language = GetLanguage(0);
  if ((Language - 1) < 5)
  {
    asset_bc = get_asset_bc();
    v8 = StringLiteral_4619;
    v9 = StringLiteral_4620;
    v10 = StringLiteral_4621;
    v11 = asset_bc;
    v12 = StringLiteral_4586;
    v13 = Concat_5271136(v9, StringLiteral_74, v10, v12);
    File_16626736 = LoadFile_16626736(v11, v8, v13);
    if (File_16626736
          File_16626736->klass->_2.typeHierarchyDepth >= typeHierarchyDepth))
    {
      if (File_16626736->klass->_2.typeHierarchy[typeHierarchyDepth - 1] == TMPro_TMP_FontAsset)
        v18 = File_16626736;
      else
        v18 = 0;
    }
    else
    {
      v18 = 0;
    }
  }
  if (Language == 6)
  {
    v30 = get_asset_bc();
    v31 = StringLiteral_4622;
    v32 = StringLiteral_4623;
    v33 = StringLiteral_4624;
    v34 = v30;
    v35 = StringLiteral_4586;
    v36 = Concat_5271136(v32, StringLiteral_74, v33, v35);
    v38 = LoadFile_16626736(v34, v31, v36);
    {
      if (v38->klass->_2.typeHierarchy[v39 - 1] == TMPro_TMP_FontAsset)
        v18 = v38;
      else
        v18 = 0;
    }
    else
    {
      v18 = 0;
    }
    v29 = 0.0;
  }
  if (Language == 7)
  {
    v19 = get_asset_bc();
    v20 = StringLiteral_4625;
    v21 = StringLiteral_4626;
    v22 = StringLiteral_4627;
    v23 = v19;
    v24 = StringLiteral_4586;
    v25 = Concat_5271136(v21, StringLiteral_74, v22, v24);
    v27 = LoadFile_16626736(v23, v20, v25);
    {
      if (v27->klass->_2.typeHierarchy[v28 - 1] == TMPro_TMP_FontAsset)
        v18 = v27;
      else
        v18 = 0;
      v29 = -10.0;
    }
    else
    {
      v18 = 0;
      v29 = -10.0;
    }
    set_lineSpacing(Component_GUILayer, v29);
    if (op_Inequality(v18, 0, 0))
      set_font(Component_GUILayer, v18);
    return;
  }
  v40 = get_asset_bc();
  v41 = StringLiteral_4628;
  v42 = StringLiteral_4629;
  v43 = StringLiteral_4621;
  v44 = v40;
  v45 = StringLiteral_4586;
  v46 = Concat_5271136(v42, StringLiteral_74, v43, v45);
  LoadFile_16626736(v44, v41, v46);
}
