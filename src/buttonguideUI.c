#include "types.h"

typedef struct ChangeTex ChangeTex;
typedef struct buttonguideUI buttonguideUI;

void ChangeSprite(ChangeTex *this, void **sprData, char *loadPath, bool checkPlatform);

// 0x13228b0
void Awake(buttonguideUI *this) {
  u64 *v3;

  v3 = Allocate(ChangeTex);
  _ctor(v3, 0);
  ChangeSprite(v3, this->sprTbl, this->texPath, 1);
}

// 0x1322920
void Change(buttonguideUI *this, s32 setNum, s32 setSpr) {
  struct UnityEngine_UI_Image_array *buttonImage;
  s32 max_length;
  struct UnityEngine_Sprite_array *sprTbl;
  s32 v7;
  s64 v8;

  if ((setNum & 0x80000000) == 0)
  {
    buttonImage = this->buttonImage;
    max_length = buttonImage->max_length;
    if (max_length > setNum && setSpr >= 1)
    {
      sprTbl = this->sprTbl;
      v7 = sprTbl->max_length;
      if (v7 >= setSpr)
      {
        v8 = setSpr - 1LL;
        set_sprite(buttonImage->m_Items[setNum], sprTbl->m_Items[v8]);
      }
    }
  }
}
