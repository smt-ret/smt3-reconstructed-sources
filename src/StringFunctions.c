#include "types.h"

static char *activeString;
static s32 activePosition;

// 0x133f720
char *ChangeCharacter(char *sourceString, s32 charIndex, u16 newChar) {
  System_String_o *v6;
  System_String_o *v7;
  System_String_o *v8;
  u16 v10;

  v10 = newChar;
  if (charIndex <= 0)
    v6 = "";
  else
    v6 = Substring_5248048(sourceString, 0, charIndex);
  v7 = sub_3C3A80(&v10, 0);
  if (get_Length(sourceString) - 1 <= charIndex)
    v8 = "";
  else
    v8 = Substring(sourceString, charIndex + 1);
  return Concat_5221536(v6, v7, v8);
}

// 0x133f810
bool IsXDigit(u16 character) {
 if (IsDigit(character))
  {
    return 1;
  }
  return IndexOf("ABCDEFabcdef", character, 0) >= 0;
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
  s32 activePosition;
  s32 v10;
  u16 Chars;
  s32 v13;
  s32 v17;
  s32 i;
  s32 v20;
  u16 v21;

  if (stringToTokenize)
  {
    activeString = stringToTokenize;
    activePosition = -1;
  }
  if (!activeString)
    return 0;
  if (activePosition == get_Length(activeString))
    return 0;
  do
  {
    ++activePosition;
    v10 = activePosition;
    if (v10 >= get_Length(activeString))
      break;
    Chars = get_Chars(activeString, activePosition);
  }
  while ((IndexOf(delimiters, Chars, 0) & 0x80000000) == 0);
  v13 = activePosition;
  if (v13 == get_Length(activeString))
    return 0;
  v17 = activePosition;
  for (i = v17 + 1; ; i = activePosition + 1)
  {
    activePosition = i;
    v20 = activePosition;
    if (v20 >= get_Length(activeString))
      break;
    v21 = get_Chars(activeString, activePosition);
    if (IndexOf(delimiters, v21, 0) != -1)
      break;
  }
  return Substring_5248048(activeString, v17, activePosition - v17);
}
