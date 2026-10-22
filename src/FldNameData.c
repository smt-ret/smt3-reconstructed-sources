#include "types.h"

typedef struct FldNameData FldNameData;

char *GetLocalizeText(char *ID);

// 0x113d080
char *GetAreaName(FldNameData *this, s32 fld, s32 area) {
  u64 *v6;
  u64 *v7;
  System_String_o *v9;
  s32 v11;
  s32 v12;

  v12 = fld;
  v6 = sub_8D3950(s32, &v12);
  v11 = area;
  v7 = sub_8D3950(s32, &v11);
  v9 = Format_5268592("<AREA{0:D2}_L{1:D4}>", v6, v7);
  return GetLocalizeText(v9);
}

// 0x113d150
char *GetBasyoName(FldNameData *this, s32 fld, s32 basyo) {
  u64 *v6;
  u64 *v7;
  System_String_o *v9;
  s32 v11;
  s32 v12;

  v12 = fld;
  v6 = sub_8D3950(s32, &v12);
  v11 = basyo;
  v7 = sub_8D3950(s32, &v11);
  v9 = Format_5268592("<BASYO{0:D2}_L{1:D4}>", v6, v7);
  return GetLocalizeText(v9);
}

// 0x113cfb0
char *GetFieldName(FldNameData *this, s32 fld) {
  System_String_o *Item;

  if (_get_Count(this->_fldFieldNameTbl) <= fld)
    return "";
  Item = _get_Item(
           this->_fldFieldNameTbl,
           fld);
  return GetLocalizeText(Item);
}

// 0x113d220
char *GetFloorName(FldNameData *this, s32 fld, s32 floor) {
  u64 *v6;
  u64 *v7;
  System_String_o *v9;
  s32 v11;
  s32 v12;

  v12 = fld;
  v6 = sub_8D3950(s32, &v12);
  v11 = floor;
  v7 = sub_8D3950(s32, &v11);
  v9 = Format_5268592("<FLOOR{0:D3}_L{1:D4}>", v6, v7);
  return GetLocalizeText(v9);
}

// 0x113d2f0
char *GetSaveNmlName(FldNameData *this, s32 TmnlId) {
  u64 *v4;
  System_String_o *v6;
  s32 v8;

  v8 = TmnlId;
  v4 = sub_8D3950(s32, &v8);
  v6 = Format("<NMLNM_L{0:D4}>", v4, 0);
  return GetLocalizeText(v6);
}

// 0x113d3a0
char *GetSaveSmlName(FldNameData *this, s32 TmnlId) {
  u64 *v4;
  System_String_o *v6;
  s32 v8;

  v8 = TmnlId;
  v4 = sub_8D3950(s32, &v8);
  v6 = Format("<SMLNM_L{0:D4}>", v4, 0);
  return GetLocalizeText(v6);
}

// 0x113d450
char *GetSuspendPosName(FldNameData *this, s32 fld, s32 area) {
  u64 *v6;
  u64 *v7;
  System_String_o *v9;
  s32 v11;
  s32 v12;

  v12 = fld;
  v6 = sub_8D3950(s32, &v12);
  v11 = area;
  v7 = sub_8D3950(s32, &v11);
  v9 = Format_5268592("<SUSPEND{0:D3}_L{1:D4}>", v6, v7);
  return GetLocalizeText(v9);
}
