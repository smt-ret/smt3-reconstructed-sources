#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct nmeData_t nmeData_t;

static nmeData_t *GBWK;

s32 dds3FadeCheck(void);
void *dds3GetProcessData(dds3ProcessID_t **id);

// 0xeffff0
dds3ProcessFunc_t *nmeCalc(dds3ProcessID_t *PID) {
    dds3GetProcessData(0);
    dds3FadeCheck();
    return 0;
}
