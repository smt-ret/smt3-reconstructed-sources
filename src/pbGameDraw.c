#include "types.h"

typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct pbBlockDataBase_t pbBlockDataBase_t;
typedef struct pbGroupData_t pbGroupData_t;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfIVector4_t sdfIVector4_t;
typedef struct sdfMat_t sdfMat_t;

static s32 degree_mode_b;
static pbProcHandle_t *menu_proc;
static pbProcHandle_t *help_proc;
static s32 *csrColor[4];
static sdfIVector4_t *csrPos[4];
static sdfIVector4_t *csrUv[4];
static sdfVector4_t mrpb_angle;
static sdfVector4_t mrpb_pos;
static s32 RndBlkPosCnt;
static s32 RndCoreBlkPosCnt;
static s32 RndBlkPosgrpCnt;
static s32 RndBlkflag;
static s32 RndCoreBlkPosCnflag;
static s32 mBlkStageChangeflag;
static sdfVector3_t RndCorePos;
static u32 outLineChkCnt;
static u32 outLineChkCnt2;
static u8 *outLineChk[UNKNOWN_ARRAY_SIZE];
static bool OutLineFDraw;
static bool OutLineMDraw;
static s32 PB_BLOCK_LENGTH_H;
static f32 PB_OUTLINE;
static sdfVector4_t outlineBase[UNKNOWN_ARRAY_SIZE];
static f32 mapCursor_f;

void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
u32 drawBlock(sdfVector4_t offset, u8 face, u32 type, sdfDrawTag_t **drTag);
void linkTM(sdfVector4_t angle, sdfVector4_t trans, sdfDrawTag_t **drTag);
void makeBlockDataBase(pbBlockDataBase_t **db);
u8 pbCheckDrawFace(s16 x, s16 y, u32 type);
void pbRebuildOutline(pbGroupData_t **p);
u16 pb_General__GET_MAP_BLK_(s32 x, s32 y);
u32 pb_General__GET_MAP_GRPID_(s32 x, s32 y);
void pb_General__SET_MAP_BLK_(s32 x, s32 y, s32 v);
s32 sdfDrawTagInit(sdfDrawTag_t *a);
void sdfMatFreeDelayed(sdfMat_t *aMat);
sdfMat_t *sdfMatNew(void);
f32 sdfSin(f32 aRadius);
void sdfVu0LoadMatrix(sdfMatrix4_t *aMatrix);
void sdfVu0StoreMatrix(sdfMatrix4_t *aMatrix);

// 0x149be30
dds3ProcessFunc_t *blockDB(dds3ProcessID_t *id) {
    makeBlockDataBase(0);
    sdfDrawTagInit(0);
    linkTM((sdfVector4_t){0}, (sdfVector4_t){0}, 0);
    pbCheckDrawFace(0, 0, 0);
    drawBlock((sdfVector4_t){0}, 0, 0, 0);
    sdfVu0StoreMatrix(0);
    sdfVu0LoadMatrix(0);
    return 0;
}

// 0x149d5d0
dds3ProcessFunc_t *deleteBlockDB(dds3ProcessID_t *id) {
    sdfMatFreeDelayed(0);
    return 0;
}

// 0x149df50
void deleteMapCursor(dds3ProcessID_t *id) {
}

// 0x149bb90
void freeAllDataBase(pbBlockDataBase_t **db) {
  pbBlockDataBase_t_o *v3;
  pbBlockDataBase_t_Fields *p_fields;
  u64 v5;
  struct pbGroupData_t_array *grp;
  Il2CppClass **v8;

  v3 = *db;
  p_fields = &(*db)->fields;
  if (p_fields->grp_num >= 1)
  {
    v5 = 0;
    do
    {
      grp = v3->grp;
      else      v8 = &grp->obj.klass + v5++;
      v8[4] = 0;
      v3 = *db;
    }
    while (v5 < (*db)->grp_num);
    p_fields = &v3->fields;
  }
  p_fields->grp_num = 0;
}

// 0x149bb80
void freeGroupData(pbGroupData_t **p) {
  *p = 0;
}

// 0x149a660
void makeBlockDataBase(pbBlockDataBase_t **db) {
    pb_General__GET_MAP_BLK_(0, 0);
    pb_General__GET_MAP_GRPID_(0, 0);
    pb_General__SET_MAP_BLK_(0, 0, 0);
    pbRebuildOutline(0);
}

// 0x149d850
dds3ProcessFunc_t *mapCursor(dds3ProcessID_t *id) {
    sdfDrawTagInit(0);
    sdfSin(0);
    return 0;
}

// 0x149e920
void pbPrintBlockDB(pbProcHandle_t **p) {
}

// 0x149b9c0
void pbRebuildOutline(pbGroupData_t **p) {
  pbGroupData_t_o *v4;
  s64 v5;
  struct pbBlockData_t_array *blk;
  u64 v7;
  struct pbBlockData_t_array *v8;
  struct pbBlockData_t_o *core;
  u64 max_length_low;
  s16 x;
  s16 v14;
  s16 y;
  s16 grpID;
  s16 v18;
  s64 v19;

  v4 = *p;
  if ((*p)->num >= 1)
  {
    v5 = 4;
    do
    {
      blk = v4->blk;
      v7 = v5 - 4;
      *(*(&blk->obj.klass + v5) + 22LL) = 0;
      v8 = (*p)->blk;
      core = (*p)->core;
      max_length_low = LODWORD(v8->max_length);
      x = core->x;
      v14 = *(*(&v8->obj.klass + v5) + 18LL);
      y = core->y;
      grpID = (*p)->grpID;
      v18 = *(*(&(*p)->blk->obj.klass + v5) + 20LL);
      checkDrawOutline(v14 + x, v18 + y, grpID);
      v4 = *p;
      v19 = v5 - 3;
      ++v5;
    }
    while (v19 < (*p)->num);
  }
}

// 0x149e6c0
void pbReleaseGroupDB(pbProcHandle_t **p, u32 grpID) {
}

// 0x149e510
pbGroupData_t *pbSearchGroupDB(pbProcHandle_t **p, u32 grpID) {
    return 0;
}

// 0x149f900
void pbSetMapCursorFlag(pbProcHandle_t **p, s32 flag) {
}

// 0x149e040
pbProcHandle_t *pbStartBlockDataBase(pbProcHandle_t **parent) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    dds3SetProcessData(0, 0);
    sdfMatNew();
    return 0;
}

// 0x149f650
pbProcHandle_t *pbStartDrawMapCursor(pbProcHandle_t **parent) {
    dds3StartProcess(0, 0, 0, 0, 0, 0, 0);
    dds3LinkProcess(0, 0);
    dds3SetProcessData(0, 0);
    return 0;
}

// 0x149a5a0
pbGroupData_t *searchGroupDB(pbBlockDataBase_t *db, u32 grpID) {
  u64 v3;
  struct pbGroupData_t_array *grp;
  struct pbGroupData_t_array *v7;

  if (db->grp_num < 1)
    return 0;
  v3 = 0;
  while (1)
  {
    grp = db->grp;
    if (grpID == grp->m_Items[v3]->grpID)
      break;
    if (++v3 >= db->grp_num)
      return 0;
  }
  v7 = db->grp;
  return v7->m_Items[v3];
}
