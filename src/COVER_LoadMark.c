#include "types.h"

typedef struct COVER_LoadMark COVER_LoadMark;

// 0xfe16e0
void SetDisp(COVER_LoadMark *this, bool act) {
  _BOOL4 v3;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v6;

  v3 = act;
  gameObject = get_gameObject(this);
  if (((get_activeSelf(gameObject) ^ v3) & 1) != 0)
  {
    v6 = get_gameObject(this);
    SetActive(v6, v3, 0);
  }
}
