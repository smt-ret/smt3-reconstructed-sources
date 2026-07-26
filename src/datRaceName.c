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
    GetLocalizeText(0);
    return 0;
}

// 0x7c4a30
char *GetTag(s32 id, s32 Devilid) {
    IsZensyoMode();
    evtBitCheck(0);
    return 0;
}

// 0x7c4b70
bool raidoCheck(s32 Devilid) {
 if (IsZensyoMode())
  {
    return Devilid == 192;
  }
  return !evtBitCheck(3712);
}
