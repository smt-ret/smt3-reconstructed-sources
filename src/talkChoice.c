#include "types.h"

typedef struct talkChoice talkChoice;
typedef struct talkChoice_Mode talkChoice_Mode;

struct talkChoice_Mode {
    s32 value__;
};

void Log(char *fmt, void **parray);

// 0x169cf10
void Awake(talkChoice *this) {
}

// 0x169d1f0
void Display(talkChoice *this, bool sw) {
}

// 0x169d290
void DisplayOff(talkChoice *this) {
    Log(0, 0);
}

// 0x169d3e0
s32 GetDisplayStatus(talkChoice *this) {
  return this->wnd_mode;
}

// 0x169cfd0
void Update(talkChoice *this) {
}
