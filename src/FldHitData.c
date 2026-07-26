#include "types.h"

typedef struct FldHitData FldHitData;
typedef struct fldNpcTable_t fldNpcTable_t;

// 0x113cdc0
fldNpcTable_t *GetFldNpcTable(FldHitData *this, s32 id) {
  if (_get_Count(this->_fldNpcTable) <= id)
    return 0;
  else
    return _get_Item(
             this->_fldNpcTable,
             id);
}
