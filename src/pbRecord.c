#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbGroupData_t pbGroupData_t;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct pbRecordData_t pbRecordData_t;
typedef struct pbRecord_t pbRecord_t;

struct pbRecord_t {
    s32 pnt;
    pbRecordData_t rec[UNKNOWN_ARRAY_SIZE];
};

void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void pbClearRecord(pbProcHandle_t **p);
void pbDispMyCharacter(pbProcHandle_t **p, s8 sw);
void pbGetMyCharcterPos2(pbProcHandle_t **p, s16 *x, s16 *y);
u32 pbMyCharacterDispStat(pbProcHandle_t **p);
pbGroupData_t *pbSearchGroupDB(pbProcHandle_t **p, u32 grpID);
void pbSetMyCharcterPos2(pbProcHandle_t **p, s16 x, s16 y);
void pb_General__CLR_MAP_BLKDAT_(s32 x, s32 y);
u16 pb_General__GET_MAP_BLK_(s32 x, s32 y);
void pb_General__SET_MAP_BLK_(s32 x, s32 y, s32 v);

// 0x14b0ae0
dds3ProcessFunc_t *deleteRecord(dds3ProcessID_t *id) {
    pbClearRecord(0);
    return 0;
}

// 0x14b0910
void deleteStack(pbRecordData_t **p) {
  pbRecordData_t_o *v2;

  v2 = *p;
  if ((*p)->c)
  {
    v2->current = 0;
    (*p)->c_num = 0;
    (*p)->c = 0;
    v2 = *p;
  }
  if (v2->blk)
  {
    v2->b_num = 0;
    (*p)->blk = 0;
    v2 = *p;
  }
  if (v2->flor)
  {
    v2->f_num = 0;
    (*p)->flor = 0;
  }
}

// 0x14b1db0
u32 pbAddRecord_blk(pbProcHandle_t **p, pbGroupData_t **grp) {
    return 0;
}

// 0x14b27a0
u32 pbAddRecord_char(pbProcHandle_t **p, u32 idx, pbProcHandle_t ***c) {
    pbGetMyCharcterPos2(0, 0, 0);
    pbMyCharacterDispStat(0);
    return 0;
}

// 0x14b2310
u32 pbAddRecord_flor(pbProcHandle_t **p, pbGroupData_t **grp) {
    return 0;
}

// 0x14b1390
s8 pbCheckPopRecord(pbProcHandle_t **p) {
    return 0;
}

// 0x14b0be0
void pbClearRecord(pbProcHandle_t **p) {
}

// 0x14b2cf0
void pbDebugPrintRecord(pbProcHandle_t **p) {
}

// 0x14b1180
u32 pbGetRecordPnt(pbProcHandle_t **p) {
    return 0;
}

// 0x14b14f0
s32 pbPopRecord(pbProcHandle_t **p, pbProcHandle_t ***c, pbProcHandle_t **blkDB) {
    pbSetMyCharcterPos2(0, 0, 0);
    pbDispMyCharacter(0, 0);
    pbSearchGroupDB(0, 0);
    pb_General__CLR_MAP_BLKDAT_(0, 0);
    pb_General__GET_MAP_BLK_(0, 0);
    pb_General__SET_MAP_BLK_(0, 0, 0);
    return 0;
}

// 0x14b1270
u32 pbPushRecord(pbProcHandle_t **p) {
    return 0;
}

// 0x14b0d60
pbProcHandle_t *pbStartRecord(pbProcHandle_t **parent) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    dds3SetProcessData(0, 0);
    return 0;
}

// 0x14b0970
dds3ProcessFunc_t *record(dds3ProcessID_t *id) {
    return 0;
}

// 0x14b0900
void sdfChipFreeDelayed(void *aPtr) {
  ;
}
