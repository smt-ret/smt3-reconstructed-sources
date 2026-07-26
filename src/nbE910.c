#include "types.h"

typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nbE910_funcDelegate nbE910_funcDelegate;
typedef struct nbEventProcessData_t nbEventProcessData_t;

static nbE910_funcDelegate *func[2];

void *dds3GetProcessData(dds3ProcessID_t **id);
void nbPanelAllHide(void);
void nbUpdateEventProcessData(dds3ProcessID_t **id);

// 0x16fe130
s32 End(nbEventProcessData_t *ed) {
  if (ed->seqtime < 61)
    return 0;
  Write(StringLiteral_21335, 0);
  ed->data->endtype = 8;
  return 1;
}

// 0x16fe080
s32 Test(nbEventProcessData_t *ed) {
  nbPanelAllHide();
  if (ed)
    *&ed->seq = (ed->seq + 1);
  return 0;
}

// 0x16fe1d0
void *nbE910Process_1(dds3ProcessID_t *id) {
    dds3GetProcessData(0);
    nbUpdateEventProcessData(0);
    return 0;
}
