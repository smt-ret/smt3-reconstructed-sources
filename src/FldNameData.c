#include "types.h"

typedef struct FldNameData FldNameData;

char *GetLocalizeText(char *ID);

// 0x113d080
char *GetAreaName(FldNameData *this, s32 fld, s32 area) {
    GetLocalizeText(0);
    return 0;
}

// 0x113d150
char *GetBasyoName(FldNameData *this, s32 fld, s32 basyo) {
    GetLocalizeText(0);
    return 0;
}

// 0x113cfb0
char *GetFieldName(FldNameData *this, s32 fld) {
  System_String_o *Item;

  if (_get_Count(this->_fldFieldNameTbl) <= fld)
    return StringLiteral_416;
  Item = _get_Item(
           this->_fldFieldNameTbl,
           fld);
  return GetLocalizeText(Item);
}

// 0x113d220
char *GetFloorName(FldNameData *this, s32 fld, s32 floor) {
    GetLocalizeText(0);
    return 0;
}

// 0x113d2f0
char *GetSaveNmlName(FldNameData *this, s32 TmnlId) {
    GetLocalizeText(0);
    return 0;
}

// 0x113d3a0
char *GetSaveSmlName(FldNameData *this, s32 TmnlId) {
    GetLocalizeText(0);
    return 0;
}

// 0x113d450
char *GetSuspendPosName(FldNameData *this, s32 fld, s32 area) {
    GetLocalizeText(0);
    return 0;
}
