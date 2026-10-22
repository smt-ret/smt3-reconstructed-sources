#include "types.h"

static char *txt[30];

char *GetLocalizeText(char *ID);

// 0x12afaf0
char *Get(s32 id) {
  u64 *v3;
  System_String_o *v5;
  s32 v7;

  v7 = id;
  v3 = sub_8D3950(s32, &v7);
  v5 = Format("<HEARTS_L{0:D4}>", v3, 0);
  return GetLocalizeText(v5);
}
