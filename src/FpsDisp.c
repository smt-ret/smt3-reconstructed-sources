#include "types.h"

typedef struct FpsDisp FpsDisp;

bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);

// 0x113dcf0
void Start(FpsDisp *this) {
  UnityEngine_GameObject_o *gameObject;

  gameObject = get_gameObject(this);
  SetActive(gameObject, 0, 0);
  SetActive(this->fpsObj, 0, 0);
}

// 0x113dd30
void Update(FpsDisp *this) {
  bool activeSelf;

  else if (!DDS3_PADCHECK_PRESS(14))
  {
    return;
  }
  if (DDS3_PADCHECK_TRIG(11))
  {
    activeSelf = get_activeSelf(this->fpsObj);
    SetActive(this->fpsObj, !activeSelf, 0);
  }
}
