#include "types.h"

static char *tbl[15];

char *GetLocalizeText(char *ID);

// 0xfde830
char *GetStr(s32 no) {
  u64 *v3;
  System_String_o *v5;
  s32 v7;

  v7 = no;
  v3 = sub_8D3950(s32, &v7);
  v5 = Format("<MISCACTION_L{0:D4}>", v3, 0);
  return GetLocalizeText(v5);
}
