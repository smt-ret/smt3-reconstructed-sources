#include "types.h"

typedef struct ChangeTex ChangeTex;
typedef struct campMenu campMenu;

void ChangeSprite(ChangeTex *this, void **sprData, char *loadPath, bool checkPlatform);

// 0x1322a00
void Awake(campMenu *this) {
  u64 *v3;

  v3 = Allocate(ChangeTex);
  _ctor(v3, 0);
  ChangeSprite(v3, this->MPSprite, this->texPath, 0);
}
