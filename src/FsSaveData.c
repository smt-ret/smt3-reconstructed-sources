#include "types.h"

typedef struct FsSaveData FsSaveData;
typedef struct GameFileInfo_t GameFileInfo_t;
typedef struct SAVEDATA SAVEDATA;
typedef struct SAVEDATA_dds3GlobalWork_tag SAVEDATA_dds3GlobalWork_tag;
typedef struct SAVEDATA_dds3WorkVer7_tag SAVEDATA_dds3WorkVer7_tag;
typedef struct dds3AdditionWork_t dds3AdditionWork_t;
typedef struct dds3GlobalWork_t dds3GlobalWork_t;

static SAVEDATA *saveData;

void LoadCorrectionVer7(FsSaveData *this, SAVEDATA_dds3GlobalWork_tag *dds3Work, SAVEDATA_dds3WorkVer7_tag *dds3Ver7);
void backupData(SAVEDATA *this, s32 num, dds3GlobalWork_t *data, bool init);
void backupSystem(SAVEDATA *this);
void backupSystemVer7(SAVEDATA *this);
void initSystemVer7(SAVEDATA *this);
void initialize(SAVEDATA *this);
void restoreData(SAVEDATA *this, s32 num, dds3GlobalWork_t **data, dds3AdditionWork_t **addition);
void restoreSystem(SAVEDATA *this);
void restoreSystemVer7(SAVEDATA *this);
void setHeaderGameFileInfo(SAVEDATA *this, s32 num, GameFileInfo_t **data);

// 0x1140be0
void GetSuspendDispName(FsSaveData *this, s32 *nameU, s32 *nameD) {
  *nameU = saveData->AdditionBuff.nameU;
  *nameD = saveData->AdditionBuff.nameD;
}

// 0x1140b40
void GetSuspendFieldArea(FsSaveData *this, s32 *fieldID, s32 *areaID) {
  *fieldID = saveData->AdditionBuff.fieldID;
  *areaID = saveData->AdditionBuff.areaID;
}

// 0x113ed20
bool Load(FsSaveData *this) {
    restoreSystem(0);
    LoadCorrectionVer7(0, 0, 0);
    initSystemVer7(0);
    restoreSystemVer7(0);
    return 0;
}

// 0x11404d0
void LoadCorrectionVer6(FsSaveData *this, s32 *start, SAVEDATA_dds3GlobalWork_tag *dds3Work, s32 size) {
  *start -= size;
  dds3Work->amapEX.blkOpenFlg01 = 0;
  dds3Work->amapEX.blkOpenFlg00 = 0;
  dds3Work->amapEX.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  dds3Work->amapEX.blkOpenFlg01 = NewSpecific(uint, 0x20u);
  dds3Work->GameFileInfo.ver = 6;
}

// 0x1140570
void LoadCorrectionVer7(FsSaveData *this, SAVEDATA_dds3GlobalWork_tag *dds3Work, SAVEDATA_dds3WorkVer7_tag *dds3Ver7) {
  struct System_UInt32_array *v6;
  struct System_UInt32_array *v7;
  struct System_UInt32_array *v8;

  dds3Ver7->amap.blkOpenFlg28 = 0;
  dds3Ver7->amap.blkOpenFlg29 = 0;
  dds3Ver7->amap.blkOpenFlg26 = 0;
  dds3Ver7->amap.blkOpenFlg27 = 0;
  dds3Ver7->amap.blkOpenFlg24 = 0;
  dds3Ver7->amap.blkOpenFlg25 = 0;
  dds3Ver7->amap.blkOpenFlg22 = 0;
  dds3Ver7->amap.blkOpenFlg23 = 0;
  dds3Ver7->amap.blkOpenFlg20 = 0;
  dds3Ver7->amap.blkOpenFlg21 = 0;
  dds3Ver7->amap.blkOpenFlg18 = 0;
  dds3Ver7->amap.blkOpenFlg19 = 0;
  dds3Ver7->amap.blkOpenFlg16 = 0;
  dds3Ver7->amap.blkOpenFlg17 = 0;
  dds3Ver7->amap.blkOpenFlg14 = 0;
  dds3Ver7->amap.blkOpenFlg15 = 0;
  dds3Ver7->amap.blkOpenFlg12 = 0;
  dds3Ver7->amap.blkOpenFlg13 = 0;
  dds3Ver7->amap.blkOpenFlg10 = 0;
  dds3Ver7->amap.blkOpenFlg11 = 0;
  dds3Ver7->amap.blkOpenFlg08 = 0;
  dds3Ver7->amap.blkOpenFlg09 = 0;
  dds3Ver7->amap.blkOpenFlg06 = 0;
  dds3Ver7->amap.blkOpenFlg07 = 0;
  dds3Ver7->amap.blkOpenFlg04 = 0;
  dds3Ver7->amap.blkOpenFlg05 = 0;
  dds3Ver7->amap.blkOpenFlg02 = 0;
  dds3Ver7->amap.blkOpenFlg03 = 0;
  dds3Ver7->amap.blkOpenFlg00 = 0;
  dds3Ver7->amap.blkOpenFlg01 = 0;
  dds3Ver7->amap.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg01 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg02 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg03 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg04 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg05 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg06 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg07 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg08 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg09 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg10 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg11 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg12 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg13 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg14 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg15 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg16 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg17 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg18 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg19 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg20 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg21 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg22 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg23 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg24 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg25 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg26 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg27 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap.blkOpenFlg28 = NewSpecific(uint, 0x20u);
  v6 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg06 = 0;
  dds3Ver7->amap31.blkOpenFlg07 = 0;
  dds3Ver7->amap31.blkOpenFlg04 = 0;
  dds3Ver7->amap31.blkOpenFlg05 = 0;
  dds3Ver7->amap.blkOpenFlg29 = v6;
  dds3Ver7->amap31.blkOpenFlg02 = 0;
  dds3Ver7->amap31.blkOpenFlg03 = 0;
  dds3Ver7->amap31.blkOpenFlg00 = 0;
  dds3Ver7->amap31.blkOpenFlg01 = 0;
  dds3Ver7->amap31.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg01 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg02 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg03 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg04 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg05 = NewSpecific(uint, 0x20u);
  dds3Ver7->amap31.blkOpenFlg06 = NewSpecific(uint, 0x20u);
  v7 = NewSpecific(uint, 0x20u);
  dds3Ver7->amapEX.blkOpenFlg00 = 0;
  dds3Ver7->amapEX.blkOpenFlg01 = 0;
  dds3Ver7->amap31.blkOpenFlg07 = v7;
  dds3Ver7->amapEX.blkOpenFlg00 = NewSpecific(uint, 0x20u);
  v8 = NewSpecific(uint, 0x20u);
  *&dds3Ver7->dante_pelem.hensinmae = 0;
  *&dds3Ver7->dante_pelem.reserved2 = 0;
  dds3Ver7->dante_pelem.keisyoskill = 0;
  dds3Ver7->dante_pelem.keiattr = 0;
  *&dds3Ver7->dante_pelem.exp = 0;
  dds3Ver7->dante_pelem.mitamaparam = 0;
  dds3Ver7->dante_pelem.levelupparam = 0;
  *&dds3Ver7->dante_pelem.skillcnt = 0;
  dds3Ver7->dante_pelem.skill = 0;
  dds3Ver7->dante_pelem.param = 0;
  dds3Ver7->dante_pelem.skillparam = 0;
  dds3Ver7->amapEX.blkOpenFlg01 = v8;
  *&dds3Ver7->dante_pelem.id = 0;
  dds3Ver7->dante_pelem.param = NewSpecific(sbyte, 6u);
  dds3Ver7->dante_pelem.skillparam = NewSpecific(sbyte, 6u);
  dds3Ver7->dante_pelem.skill = NewSpecific(ushort, 0x18u);
  dds3Ver7->dante_pelem.mitamaparam = NewSpecific(sbyte, 6u);
  dds3Ver7->dante_pelem.levelupparam = NewSpecific(sbyte, 6u);
  dds3Ver7->dante_pelem.keisyoskill = NewSpecific(ushort, 0x18u);
  dds3Ver7->dante_pelem.keiattr = NewSpecific(byte, 0x18u);
  dds3Ver7->saveTime = 0;
  dds3Ver7->autoMapOpen = NewSpecific(sbyte, 0x24u);
  dds3Ver7->autoMapOpenEX = NewSpecific(sbyte, 2u);
  dds3Ver7->fldRunWork = NewSpecific(byte, 0x6Bu);
  dds3Ver7->reserved = NewSpecific(sbyte, 0x93u);
  dds3Work->GameFileInfo.ver = 7;
}

// 0x1140980
s32 Load_18090368(FsSaveData *this, s32 num, dds3GlobalWork_t **Loadbuff, dds3AdditionWork_t **AdditionBuff) {
  s32 v11;

  if (num <= 19)
  {
    restoreData(saveData, num, Loadbuff, AdditionBuff);
    v11 = 0;
  }
  else
  {
    restoreData(saveData, 20, Loadbuff, AdditionBuff);
    v11 = 1;
  }
  SuspendData->IsRestored = v11;
  return v11;
}

// 0x113e1c0
bool Save(FsSaveData *this, s32 num, dds3GlobalWork_t *Savebuff, bool init) {
    backupData(0, 0, 0, 0);
    backupSystem(0);
    backupSystemVer7(0);
    return 0;
}

// 0x113dff0
void SaveInit(FsSaveData *this) {
    initialize(0);
}

// 0x113e140
void SaveUnmount(FsSaveData *this) {
  Log(StringLiteral_4841, 0);
  Unmount(StringLiteral_4838, 0);
}

// 0x1140ab0
void loadHeaderGameFileInfo(FsSaveData *this, s32 num, GameFileInfo_t **data) {
  setHeaderGameFileInfo(saveData, num, data);
}
