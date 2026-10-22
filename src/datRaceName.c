#include "types.h"

static char *txt[64];

char *GetLocalizeText(char *ID);
char *GetTag(s32 id);
bool IsZensyoMode(void);
bool evtBitCheck(s32 no);

// 0x7c4990
char *DAT_STR_REF_RCNAME(s32 idx) {
  struct System_String_array *txt;

  return txt->m_Items[idx];
}

// 0x7c4c30
char *Get(s32 id, s32 Devilid) {
  System_String_o *Tag;

  Tag = GetTag(id, Devilid);
  return GetLocalizeText(Tag);
}

// 0x7c4ce0
char *GetEncyc(s32 id) {
  u64 *v4;
  System_String_o *v6;
  s32 v7;

  if (id == 40)
    return "？？？";
  v7 = id;
  v4 = sub_8D3950(s32, &v7);
  v6 = Format("<RACE_L{0:D4}>", v4, 0);
  return GetLocalizeText(v6);
}

// 0x7c4a30
char *GetTag(s32 id, s32 Devilid) {
  u64 *v5;
  System_String_o *result;
  s32 v9;

  v9 = id;
  v5 = sub_8D3950(s32, &v9);
  result = Format("<RACE_L{0:D4}>", v5, 0);
  if (id == 40)
  {
    else if ((byte_3CF2FEF & 1) != 0)
    {
LABEL_8:
      else if (IsZensyoMode())
      {
        goto LABEL_11;
      }
      if (evtBitCheck(3712))
        goto LABEL_12;
      goto LABEL_17;
    }
    goto LABEL_8;
  }
  return result;
}

// 0x7c4b70
bool raidoCheck(s32 Devilid) {
 if (IsZensyoMode())
  {
    return Devilid == 192;
  }
  return !evtBitCheck(3712);
}
