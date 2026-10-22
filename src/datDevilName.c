#include "types.h"

static char *txt;
static char *txt_loc;

char *GetLocalizeText(char *ID);
bool IsDLC(void);
bool IsZensyoMode(void);
bool evtBitCheck(s32 no);

// 0xe49b50
char *DAT_STR_REF_DVNAME(s32 idx) {
  struct System_String_array *txt;

  return txt->m_Items[idx];
}

// 0xe49bf0
char *Get(s32 id) {
  s32 v4;
  struct System_String_array *txt_loc;
  System_String_o *v9;
  bool v10;
  u32 v11;
  s64 *v12;

  v4 = convDLCDevilNumber(id);
  else if (!IsZensyoMode())
  {
    goto LABEL_13;
  }
  if (v4 == 192)
  {
    v12 = &"<DEVILMC_L0192>";
    goto LABEL_39;
  }
  if (v4 == 191)
  {
LABEL_21:
    v12 = &"<DEVIL_L0192>";
LABEL_39:
    v9 = *v12;
    return GetLocalizeText(v9);
  }
LABEL_13:
  v9 = txt_loc->m_Items[v4];
  v10 = evtBitCheck(3712);
  v11 = v4 - 339;
  if (v10)
  {
    if (v11 < 3 || v4 == 192)
      goto LABEL_21;
  }
  else if (v11 < 3 || v4 == 192)
  {
    if (IsDLC())
      v9 = Replace_5267216(v9, "MC", "");
  }
  return GetLocalizeText(v9);
}

// 0xe49fc0
char *GetEncyc(s32 id) {
  s32 v3;
  s32 v5;
  System_String_o *v6;
  struct System_String_array *txt_loc;

  v3 = convDLCDevilNumber(id);
  if (v3 == 192)
  {
    v6 = "<DEVILMC_L0192>";
  }
  else
  {
    v5 = v3;
    if (v3 == 191)
    {
      v6 = "<DEVIL_L0192>";
    }
    else
    {
      v6 = txt_loc->m_Items[v5];
    }
  }
  return GetLocalizeText(v6);
}

// 0xe49e10
char *GetTag(s32 id) {
  s32 v4;
  s64 *v6;
  struct System_String_array *txt_loc;
  System_String_o *v10;

  v4 = convDLCDevilNumber(id);
  else if (!IsZensyoMode())
  {
    goto LABEL_13;
  }
  if (v4 == 192)
  {
    v6 = &"<DEVILMC_L0192>";
    return *v6;
  }
  if (v4 == 191)
  {
    v6 = &"<DEVIL_L0192>";
    return *v6;
  }
LABEL_13:
  v10 = txt_loc->m_Items[v4];
  if ((v4 - 339) >= 3 && v4 != 192)
    return v10;
  if (IsDLC())
    return Replace_5267216(v10, "MC", "");
  return v10;
}
