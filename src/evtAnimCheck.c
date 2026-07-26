#include "types.h"

typedef struct SAVEDATA SAVEDATA;
typedef struct evtAnimCheck evtAnimCheck;
typedef struct evtUnitHandle_t evtUnitHandle_t;

void initialize(SAVEDATA *this);

// 0x1352530
void Finish(evtAnimCheck *this, s32 LayerIndex) {
  struct System_Boolean_array *bFinished;

  bFinished = this->bFinished;
  bFinished->m_Items[LayerIndex] = 1;
}

// 0x1352580
bool IsFinished(evtAnimCheck *this, s32 LayerIndex) {
  struct System_Boolean_array *bFinished;

  bFinished = this->bFinished;
  return bFinished->m_Items[LayerIndex];
}

// 0x1352370
void ResetFlag(evtAnimCheck *this, evtUnitHandle_t *hndl, s32 LayerIndex) {
  struct System_Boolean_array *bFinished;

  if (this->Handle)
  {
    bFinished = this->bFinished;
    bFinished->m_Items[LayerIndex] = 0;
  }
  else
  {
    initialize(this, hndl);
  }
  this->Handle = hndl;
}

// 0x13523e0
void initialize(evtAnimCheck *this) {
  struct System_Boolean_array *bFinished;
  struct System_Boolean_array *v4;
  struct System_Boolean_array *v6;
  struct System_Boolean_array *v8;
  struct System_Boolean_array *v10;
  struct System_Boolean_array *v12;
  struct System_Boolean_array *v14;
  struct System_Boolean_array *v16;

  bFinished = this->bFinished;
  bFinished->m_Items[0] = 0;
  v4 = this->bFinished;
  v4->m_Items[1] = 0;
  v6 = this->bFinished;
  v6->m_Items[2] = 0;
  v8 = this->bFinished;
  v8->m_Items[3] = 0;
  v10 = this->bFinished;
  v10->m_Items[4] = 0;
  v12 = this->bFinished;
  v12->m_Items[5] = 0;
  v14 = this->bFinished;
  v14->m_Items[6] = 0;
  v16 = this->bFinished;
  v16->m_Items[7] = 0;
}
