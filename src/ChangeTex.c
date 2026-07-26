#include "types.h"

typedef struct AssetBundles AssetBundles;
typedef struct ChangeTex ChangeTex;

void ChangeSprite(ChangeTex *this, void **sprData, char *loadPath, bool checkPlatform);
s32 GetLanguage(void);
s32 GetPlatform(void);
bool IsLoad(AssetBundles *this, char *key);

// 0xfe2270
void Awake(ChangeTex *this) {
  u64 *v3;
  s64 *sprite;
  s64 *v6;
  UnityEngine_UI_Image_o *setImage;

  this->setImage = GetComponent_GUILayer_(this);
  v3 = NewSpecific(UnityEngine_Sprite, 1u);
  sprite = get_sprite(this->setImage);
  v6 = sprite;
  v3[4] = v6;
  ChangeSprite(this, v3, this->texPath, this->GroupCheck);
  setImage = this->setImage;
  set_sprite(setImage, v3[4]);
}

// 0xfe2390
void ChangeSprite(ChangeTex *this, void **sprData, char *loadPath, bool checkPlatform) {
  Il2CppObject *v9;
  u32 Language;
  System_String_o *v13;
  System_String_o *v14;
  s32 Platform;
  System_String_o *v16;
  s64 *v17;
  System_String_o *v18;
  System_String_o *v19;
  Il2CppObject *v20;
  System_String_o *v21;
  System_String_o *v22;
  System_String_o *v23;
  System_String_o *v24;
  System_String_o *v25;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v30;
  System_String_o *changePath;
  AssetBundleCtrl_o *v32;
  UnityEngine_AssetBundle_o *v33;
  struct UnityEngine_Sprite_array *AssetWithSubAssets_object;
  u64 *v35;
  System_Object_array *spriteList;
  u64 *v38;
  s64 *object;
  u32 *v41;
  s64 v42;
  Il2CppObject *v45;
  u64 v46;
  s32 v47;

  v9 = Allocate(ChangeTex___c__DisplayClass7_0);
  _ctor(v9, 0);
  v9[1].klass = sprData;
  if (!op_Equality(loadPath, StringLiteral_416, 0))
  {
    Language = GetLanguage(0);
    if (Language <= 7)
    {
      v13 = StringLiteral_416;
      v14 = *off_3B22D40[Language];
      if (checkPlatform)
      {
        Platform = GetPlatform(0);
        if (Platform == 2)
        {
          v16 = StringLiteral_4642;
          v17 = &StringLiteral_4643;
        }
        else if (Platform == 1)
        {
          v16 = StringLiteral_4640;
          v17 = &StringLiteral_4641;
        }
        else
        {
          v16 = v13;
          if (Platform)
          v16 = StringLiteral_4638;
          v17 = &StringLiteral_4639;
        }
        v13 = *v17;
      }
      else
      {
        v16 = StringLiteral_416;
      }
      v18 = Concat_5221536(StringLiteral_4644, v16, v14);
      v19 = StringLiteral_4645;
      v20 = v18;
      v21 = Concat_5271136(StringLiteral_4646, v14, StringLiteral_74, v13);
      v22 = StringLiteral_4647;
      v23 = v21;
      v24 = Concat_5221536(v14, v16, StringLiteral_87);
      v25 = Replace_5267216(loadPath, v19, v23);
      this->changePath = Replace_5267216(v25, v22, v24);
      asset_bc = get_asset_bc();
      if (IsLoad(asset_bc, v20))
      {
        v30 = get_asset_bc();
        changePath = this->changePath;
        v32 = v30;
        if (Animator___ContainsKey(v32->assetbundle, v20))
        {
          v33 = *(object___get_Item(v32->assetbundle, v20)[1].monitor
                + 4);
        }
        else
        {
          v33 = 0;
        }
        AssetWithSubAssets_object = LoadAssetWithSubAssets_object_(v33, changePath);
        this->spriteList = AssetWithSubAssets_object;
        if (AssetWithSubAssets_object)
        {
          if (AssetWithSubAssets_object->max_length)
          {
            v35 = Allocate(ChangeTex___c__DisplayClass7_1);
            _ctor(v35, 0);
            v35[3] = v9;
            *(v35 + 4) = 0;
            if (SLODWORD(v9[1].klass->_1.namespaze) >= 1)
            {
              do
              {
                spriteList = this->spriteList;
                v38 = Allocate(System_Predicate_Sprite_);
                __ctor(
                  v38,
                  v35,
                  Method_ChangeTex___c__DisplayClass7_1__ChangeSprite_b__0__);
                object = Find_object_(spriteList, v38);
                {
                }
                if (op_Inequality(object, 0, 0))
                {
                  v41 = *(v35[3] + 16);
                  v42 = *(v35 + 4);
                  *&v41[2 * v42 + 8] = object;
                }
                else
                {
                  v45 = Concat_5224608(StringLiteral_4648, this->changePath);
                  {
                  }
                  Log(v45, 0);
                }
                v46 = v35[3];
                v47 = *(v35 + 4) + 1;
                *(v35 + 4) = v47;
              }
              while (v47 < *(*(v46 + 16) + 24LL));
            }
          }
        }
      }
    }
  }
}

// 0xfe2880
void **GetSprite(ChangeTex *this) {
  return this->spriteList;
}
