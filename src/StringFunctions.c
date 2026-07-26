#include "types.h"

static char *activeString;
static s32 activePosition;

// 0x133f720
char *ChangeCharacter(char *sourceString, s32 charIndex, u16 newChar) {
    return 0;
}

// 0x133f810
bool IsXDigit(u16 character) {
 if (IsDigit(character))
  {
    return 1;
  }
  return IndexOf(StringLiteral_12188, character, 0) >= 0;
}

// 0x133f8c0
char *StrChr(char *stringToSearch, u16 charToFind) {
  s32 v4;

  v4 = IndexOf(stringToSearch, charToFind, 0);
  if (v4 < 0)
    return 0;
  else
    return Substring(stringToSearch, v4);
}

// 0x133f910
char *StrRChr(char *stringToSearch, u16 charToFind) {
  s32 IndexOf;

  IndexOf = LastIndexOf(stringToSearch, charToFind, 0);
  if (IndexOf < 0)
    return 0;
  else
    return Substring(stringToSearch, IndexOf);
}

// 0x133f960
char *StrStr(char *stringToSearch, char *stringToFind) {
  s32 v4;

  v4 = IndexOf_5260384(stringToSearch, stringToFind);
  if (v4 < 0)
    return 0;
  else
    return Substring(stringToSearch, v4);
}

// 0x133f9b0
char *StrTok(char *stringToTokenize, char *delimiters) {
  StringFunctions_c *v5;
  struct StringFunctions_StaticFields *static_fields;
  s32 activePosition;
  StringFunctions_c *v8;
  struct StringFunctions_StaticFields *v9;
  s32 v10;
  u16 Chars;
  struct StringFunctions_StaticFields *v12;
  s32 v13;
  StringFunctions_c *v15;
  struct StringFunctions_StaticFields *v16;
  s32 v17;
  s32 i;
  struct StringFunctions_StaticFields *v19;
  s32 v20;
  u16 v21;

  if (stringToTokenize)
  {
    activeString = stringToTokenize;
    activePosition = -1;
  }
  static_fields = v5->static_fields;
  if (!static_fields->activeString)
    return 0;
  activePosition = static_fields->activePosition;
  if (activePosition == get_Length(static_fields->activeString))
    return 0;
  do
  {
    ++activePosition;
    v9 = v8->static_fields;
    v10 = v9->activePosition;
    if (v10 >= get_Length(v9->activeString))
      break;
    Chars = get_Chars(activeString, activePosition);
  }
  while ((IndexOf(delimiters, Chars, 0) & 0x80000000) == 0);
  v12 = StringFunctions->static_fields;
  v13 = v12->activePosition;
  if (v13 == get_Length(v12->activeString))
    return 0;
  v16 = StringFunctions->static_fields;
  v17 = v16->activePosition;
  for (i = v17 + 1; ; i = v16->activePosition + 1)
  {
    v16->activePosition = i;
    v19 = v15->static_fields;
    v20 = v19->activePosition;
    if (v20 >= get_Length(v19->activeString))
      break;
    v21 = get_Chars(activeString, activePosition);
    if (IndexOf(delimiters, v21, 0) != -1)
      break;
    v16 = StringFunctions->static_fields;
  }
  return Substring_5248048(activeString, v17, activePosition - v17);
}
