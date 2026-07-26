#include "types.h"

typedef struct ChangeTex ChangeTex;
typedef struct buttonSetOK buttonSetOK;

void ChangeSprite(ChangeTex *this, void **sprData, char *loadPath, bool checkPlatform);

// 0x1322800
void Awake(buttonSetOK *this) {
  u64 *v3;
  UnityEngine_UI_Image_o *buttonImage;
  struct UnityEngine_Sprite_array *sprTbl;

  v3 = Allocate(ChangeTex);
  _ctor(v3, 0);
  ChangeSprite(v3, this->sprTbl, this->texPath, 1);
  sprTbl = this->sprTbl;
  buttonImage = this->buttonImage;
  set_sprite(buttonImage, sprTbl->m_Items[0]);
}
