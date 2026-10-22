#include "types.h"

static u8 tbl[15149];

static char *txt[160];

char *GetLocalizeText(char *ID);
bool dds3CheckDLC6(void);
bool dds3CheckDLC7(void);

// 0x12b6e20
char *Get(s32 id) {
  s32 v2;
  u64 *v3;
  System_String_o *v5;
  s32 v7;

  v2 = id;
  if ((byte_3F59226 & 1) != 0)
  {
    if ((id - 89) > 1)
      goto LABEL_3;
  }
  else
  {
    if ((v2 - 89) > 1)
    {
LABEL_3:
      if ((v2 - 91) > 2)
        goto LABEL_17;
      goto LABEL_12;
    }
  }
  if (!dds3CheckDLC6())
    v2 = 94;
  if ((v2 - 91) <= 2)
  {
LABEL_12:
    if (!dds3CheckDLC7())
      v2 = 94;
  }
LABEL_17:
  v7 = v2;
  v3 = sub_8D3950(s32, &v7);
  v5 = Format("<DATITEMHELP_L{0:D4}>", v3, 0);
  return GetLocalizeText(v5);
}
