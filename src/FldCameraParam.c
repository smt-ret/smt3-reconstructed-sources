#include "types.h"

typedef struct FldCameraParam FldCameraParam;

// 0x113cc20
f32 GetFiledCeiling(FldCameraParam *this, s32 fieldID) {
  if (_get_Count(this->_fldCeilingTbl) <= fieldID)
    return -1.0;
  else
    return _get_Item(
             this->_fldCeilingTbl,
             fieldID);
}
