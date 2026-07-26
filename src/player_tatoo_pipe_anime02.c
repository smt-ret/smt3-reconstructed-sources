#include "types.h"

typedef struct player_tatoo_pipe_anime02 player_tatoo_pipe_anime02;

// 0x154aa00
void OnStateEnter(player_tatoo_pipe_anime02 *this, void *animator, void *stateInfo, s32 layerIndex) {
  SetInteger(animator, StringLiteral_4572, 102);
}
