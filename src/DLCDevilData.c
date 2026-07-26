#include "types.h"

typedef struct DLCDevilData DLCDevilData;
typedef struct datDevilAI_t2 datDevilAI_t2;
typedef struct datDevilFormat_s datDevilFormat_t;
typedef struct datDevilNegoFormat_s datDevilNegoFormat_t;
typedef struct datEncountPack_s datEncountPack_t;
typedef struct datEncount_s datEncount_t;

// 0xfe4890
datDevilAI_t2 *GetDevilAIData(DLCDevilData *this, s32 id) {
  if (_get_Count(this->_DevilAITbl) <= id)
    return 0;
  else
    return _get_Item(
             this->_DevilAITbl,
             id);
}

// 0xfe4bb0
u32 GetDevilAisyoData(DLCDevilData *this, s32 id, s32 attr) {
  System_WeakReference_Fields fields;

  if (_get_Count(this->_DevilAisyoTbl) <= id)
    return 100;
  fields = _get_Item(
             this->_DevilAisyoTbl,
             id)->fields;
  return *(*&fields + 4LL * attr + 32);
}

// 0xfe49d0
s32 GetDevilEncountCount(DLCDevilData *this) {
  return _get_Count(this->_DevilEncountTbl);
}

// 0xfe4a20
datEncount_t *GetDevilEncountData(DLCDevilData *this, s32 id) {
  if (_get_Count(this->_DevilEncountTbl) <= id)
    return 0;
  else
    return _get_Item(
             this->_DevilEncountTbl,
             id);
}

// 0xfe4ac0
s32 GetDevilEncountPackCount(DLCDevilData *this) {
  return _get_Count(this->_DevilEncountPackTbl);
}

// 0xfe4b10
datEncountPack_t *GetDevilEncountPackData(DLCDevilData *this, s32 id) {
  if (_get_Count(this->_DevilEncountPackTbl) <= id)
    return 0;
  else
    return _get_Item(
             this->_DevilEncountPackTbl,
             id);
}

// 0xfe47a0
s32 GetDevilFormatCount(DLCDevilData *this) {
  return _get_Count(this->_DevilFormatTbl);
}

// 0xfe47f0
datDevilFormat_t *GetDevilFormatData(DLCDevilData *this, s32 id) {
  if (_get_Count(this->_DevilFormatTbl) <= id)
    return 0;
  else
    return _get_Item(
             this->_DevilFormatTbl,
             id);
}

// 0xfe4930
datDevilNegoFormat_t *GetDevilNegoFormat(DLCDevilData *this, s32 id) {
  if (_get_Count(this->_DevilNegoFormatTbl) <= id)
    return 0;
  else
    return _get_Item(
             this->_DevilNegoFormatTbl,
             id);
}
