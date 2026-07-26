#include "types.h"

typedef struct ChangeTex ChangeTex;
typedef struct PataPataAnm PataPataAnm;

void ChangeSprite(ChangeTex *this, void **sprData, char *loadPath, bool checkPlatform);

// 0x188c390
void Awake(PataPataAnm *this) {
  u64 *v3;

  v3 = Allocate(ChangeTex);
  _ctor(v3, 0);
  ChangeSprite(v3, this->m_Sprite, this->texPath, 0);
}

// 0x188c400
void Start(PataPataAnm *this) {
  UnityEngine_GUILayer_o *Component_GUILayer;
  struct UnityEngine_Sprite_array *m_Sprite;

  Component_GUILayer = GetComponent_GUILayer_(this);
  m_Sprite = this->m_Sprite;
  this->m_Image = Component_GUILayer;
  *&this->max = m_Sprite->max_length;
}

// 0x188c470
void Update(PataPataAnm *this) {
  s64 frameCount;
  struct UnityEngine_Sprite_array *v4;
  struct UnityEngine_Sprite_array *m_Sprite;

  frameCount = this->frameCount;
  if (frameCount >= this->max)
  {
    this->frameCount = 0;
    m_Sprite = this->m_Sprite;
    set_sprite(this->m_Image, m_Sprite->m_Items[0]);
  }
  else
  {
    v4 = this->m_Sprite;
    set_sprite(this->m_Image, v4->m_Items[frameCount]);
    ++this->frameCount;
  }
}
