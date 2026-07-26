#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct MemoryDisp MemoryDisp;

char **GetKeys(AssetBundleCtrl *this);

// 0x1294390
void Start(MemoryDisp *this) {
  this->rect = GetComponent_GUILayer_(this);
}

// 0x12943f0
void Update(MemoryDisp *this) {
    GetKeys(0);
}
