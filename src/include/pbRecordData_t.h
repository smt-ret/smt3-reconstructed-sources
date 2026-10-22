#pragma once
#include "types.h"

typedef struct pbRecordCharData_t pbRecordCharData_t;
typedef struct pbRecordData_t pbRecordData_t;
typedef struct pbRecordMapData_t pbRecordMapData_t;

struct pbRecordData_t {
    u8 current;
    u8 c_num;
    u8 b_num;
    u8 f_num;
    pbRecordCharData_t *c;
    pbRecordMapData_t *blk;
    pbRecordMapData_t *flor;
};
