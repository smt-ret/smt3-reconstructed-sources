#include "types.h"

typedef struct bmenu_stay bmenu_stay;

// 0x1321350
void OnStateEnter(bmenu_stay *this, void *animator, void *stateInfo, s32 layerIndex) {
  ;
}

// 0x13213d0
void OnStateExit(bmenu_stay *this, void *animator, void *stateInfo, s32 layerIndex) {
  bComFlag = 0;
}

// 0x1321360
void OnStateUpdate(bmenu_stay *this, void *animator, void *stateInfo, s32 layerIndex) {
  bComFlag = 1;
}
