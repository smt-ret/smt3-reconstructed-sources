#include "types.h"

typedef struct C_fps C_fps;

// 0xfe18b0
void Start(C_fps *this) {
  this->nextTime = get_time(0) + 1.0;
  *&this->frameCount = 0;
  *&this->seconds = 0;
}

// 0xfe18f0
void Update(C_fps *this) {
}
