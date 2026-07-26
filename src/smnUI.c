#include "types.h"

typedef struct smnUI smnUI;
typedef struct smnUI_Mode smnUI_Mode;

struct smnUI_Mode {
    s32 value__;
};

// 0x168d1c0
void Awake(smnUI *this) {
}

// 0x168d4b0
void Display(smnUI *this, bool sw) {
}

// 0x168d660
void DisplayOff(smnUI *this) {
}

// 0x168d570
void DisplayOn(smnUI *this) {
}

// 0x168d750
s32 GetDisplayStatus(smnUI *this) {
  return this->wnd_mode;
}

// 0x168d2b0
void Update(smnUI *this) {
}
