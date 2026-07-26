#include "types.h"

typedef struct bmenu_in bmenu_in;

// 0x13212c0
void OnStateEnter(bmenu_in *this, void *animator, void *stateInfo, s32 layerIndex) {
  bComFlag = 0;
}

// 0x1321330
void OnStateExit(bmenu_in *this, void *animator, void *stateInfo, s32 layerIndex) {
  ;
}
