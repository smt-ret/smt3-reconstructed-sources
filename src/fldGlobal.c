#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct FldCameraParam FldCameraParam;
typedef struct FldHitData FldHitData;
typedef struct FldNameData FldNameData;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct fldAreaName_t fldAreaName_t;
typedef struct fldBasyoName_t fldBasyoName_t;
typedef struct fldDebug_t fldDebug_t;
typedef struct fldFloorName_t fldFloorName_t;
typedef struct fldGlobalWork_t fldGlobalWork_t;

static FldNameData *fldNameData;
static FldHitData *fldHitData;
static FldCameraParam *fldCameraParam;
static u8 *field_name[45];
static fldAreaName_t *area_name[400];
static fldBasyoName_t *basyo_name[336];
static fldFloorName_t *floor_name[224];
static char *fldsave_nml_name[32];
static char *fldsave_sml_name[64];
static fldGlobalWork_t *fldGb;
static fldDebug_t *fldDbg;
static dds3Basic_t *player;
static dds3Basic_t *player2;
static dds3Basic_t *player3;
static s32 gFldSaveNmlIdxTbl[32];
static s32 fldAllCnt;

bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void *LoadAsset(AssetBundleCtrl *this, char *key, char *path, char *name);
void evtBitOn(s32 no);
void fldAutoMapClear(void);
void fldCameraInit(void);
void fldGbFlagClear(void);
void fldGbTblLoad(void);
void fldItemBoxOpen(s32 idx);

// 0x127b8c0
bool fldAllTblLoad(void) {
  s32 fldAllCnt;
  AssetBundleCtrl_o *v4;
  AssetBundleCtrl_o *v6;
  AssetBundleCtrl_o *asset_bc;

  if (fldAllCnt == 2)
  if (fldAllCnt == 1)
  {
    asset_bc = get_asset_bc();
    if (IsLoad(asset_bc, StringLiteral_8913))
    return 0;
  }
  else
  {
    if (!fldAllCnt)
    {
      v4 = get_asset_bc();
      if (!IsLoad(v4, StringLiteral_8913))
      {
        v6 = get_asset_bc();
        Load(v6, StringLiteral_8913, StringLiteral_8913, 0);
      }
      {
        ++fldAllCnt;
        return 0;
      }
    }
    return 0;
  }
}

// 0x127e7d0
s32 fldAreaNameGetIdx(s32 fld, s32 area) {
  s32 v5;
  s32 v7;

  v5 = 0;
  while (1)
  {
    v7 = v5 + 1;
    if (*&_get_Item(
             fldNameData->_fldAreaNameTbl,
             v7)->isLongReference == fld)
    {
      if (*(&_get_Item(
                fldNameData->_fldAreaNameTbl,
                v7)->isLongReference
           + 1) == area)
        break;
    }
    if (++v5 > 0x18E)
      return 0;
  }
  return v5 + 1;
}

// 0x127e8e0
s32 fldBasyoNameGetIdx(s32 fld, s32 basyo) {
  s32 v5;
  s32 v7;

  v5 = 0;
  while (1)
  {
    v7 = v5 + 1;
    if (*&_get_Item(
             fldNameData->_fldBasyoNameTbl,
             v7)->isLongReference == fld)
    {
      if (*(&_get_Item(
                fldNameData->_fldBasyoNameTbl,
                v7)->isLongReference
           + 1) == basyo)
        break;
    }
    if (++v5 > 0x14E)
      return 0;
  }
  return v5 + 1;
}

// 0x127e9f0
s32 fldFloorNameGetIdx(s32 fld, s32 floor) {
  s32 v5;
  s32 v7;

  v5 = 0;
  while (1)
  {
    v7 = v5 + 1;
    if (*&_get_Item(
             fldNameData->_fldFloorNameTbl,
             v7)->isLongReference == fld)
    {
      if (*(&_get_Item(
                fldNameData->_fldFloorNameTbl,
                v7)->isLongReference
           + 1) == floor)
        break;
    }
    if (++v5 > 0xDE)
      return 0;
  }
  return v5 + 1;
}

// 0x127a860
s32 fldGbChkAnime(s32 fld, s32 area, s32 blk) {
  char v4;
  s32 v9;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v13;

  v4 = blk;
  if (fld <= 0x1E && ((1 << fld) & 0x400006A4) != 0 || fld > 599)
    return 0;
  if (fldGb->fieldID > 39)
  {
    if (fld > 39)
    {
      if ((fld - 40) > 5)
        v9 = 0;
      else
        v9 = dword_33CC850[fld - 40];
    }
    else
    {
      v9 = fld % 100;
    }
  }
  v9 = fld % 100;
  {
  }
  PushBlock = DDS3_GBWK->fldSave->PushBlock;
  v13 = PushBlock->m_Items[v9];
  return ((1 << v4) & v13->m_Items[area]->ManimeOffFlg) != 0;
}

// 0x127d740
s32 fldGbChkEAnime(s32 fld, s32 area, s32 grp) {
  char v4;
  s32 v9;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v13;

  v4 = grp;
  if (fld <= 0x1E && ((1 << fld) & 0x400006A4) != 0 || fld > 599)
    return 0;
  if (fldGb->fieldID > 39)
  {
    if (fld > 39)
    {
      if ((fld - 40) > 5)
        v9 = 0;
      else
        v9 = dword_33CC850[fld - 40];
    }
    else
    {
      v9 = fld % 100;
    }
  }
  v9 = fld % 100;
  {
  }
  PushBlock = DDS3_GBWK->fldSave->PushBlock;
  v13 = PushBlock->m_Items[v9];
  return ((1 << v4) & v13->m_Items[area]->EanimeOffFlg) != 0;
}

// 0x127d2a0
s32 fldGbChkEView(s32 fld, s32 area, s32 grp) {
  char v4;
  s32 v9;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v13;

  v4 = grp;
  if (fld <= 0x1E && ((1 << fld) & 0x400006A4) != 0 || fld > 599)
    return 0;
  if (fldGb->fieldID > 39)
  {
    if (fld > 39)
    {
      if ((fld - 40) > 5)
        v9 = 0;
      else
        v9 = dword_33CC850[fld - 40];
    }
    else
    {
      v9 = fld % 100;
    }
  }
  v9 = fld % 100;
  {
  }
  PushBlock = DDS3_GBWK->fldSave->PushBlock;
  v13 = PushBlock->m_Items[v9];
  return ((1 << v4) & v13->m_Items[area]->EviewOffFlg) != 0;
}

// 0x1270ec0
s32 fldGbChkGimic(s32 fld, s32 area, s32 hojiID) {
  char v4;
  s32 v9;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v13;

  v4 = hojiID;
  if (fld <= 0x1E && ((1 << fld) & 0x400006A4) != 0 || fld > 599)
    return 0;
  if (fldGb->fieldID > 39)
  {
    if (fld > 39)
    {
      if ((fld - 40) > 5)
        v9 = 0;
      else
        v9 = dword_33CC850[fld - 40];
    }
    else
    {
      v9 = fld % 100;
    }
  }
  v9 = fld % 100;
  {
  }
  PushBlock = DDS3_GBWK->fldSave->PushBlock;
  v13 = PushBlock->m_Items[v9];
  return ((1 << v4) & v13->m_Items[area]->gimicLastFlg) != 0;
}

// 0x127a3b0
s32 fldGbChkHit(s32 fld, s32 area, s32 blk) {
  char v4;
  s32 v9;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v13;

  v4 = blk;
  if (fld <= 0x1E && ((1 << fld) & 0x400006A4) != 0 || fld > 599)
    return 0;
  if (fldGb->fieldID > 39)
  {
    if (fld > 39)
    {
      if ((fld - 40) > 5)
        v9 = 0;
      else
        v9 = dword_33CC850[fld - 40];
    }
    else
    {
      v9 = fld % 100;
    }
  }
  v9 = fld % 100;
  {
  }
  PushBlock = DDS3_GBWK->fldSave->PushBlock;
  v13 = PushBlock->m_Items[v9];
  return ((1 << v4) & v13->m_Items[area]->hitOffFlg) != 0;
}

// 0x127e030
s32 fldGbChkNpc(s32 fld, s32 area, s32 hojiID) {
  char v4;
  s32 v9;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v13;

  v4 = hojiID;
  if (fld <= 0x1E && ((1 << fld) & 0x400006A4) != 0 || fld > 599)
    return 0;
  if (fldGb->fieldID > 39)
  {
    if (fld > 39)
    {
      if ((fld - 40) > 5)
        v9 = 0;
      else
        v9 = dword_33CC850[fld - 40];
    }
    else
    {
      v9 = fld % 100;
    }
  }
  v9 = fld % 100;
  {
  }
  PushBlock = DDS3_GBWK->fldSave->PushBlock;
  v13 = PushBlock->m_Items[v9];
  return ((1 << v4) & v13->m_Items[area]->npcOffFlg) != 0;
}

// 0x127e6a0
s32 fldGbChkTakaraOpen(s32 idx) {
  s32 v3;
  s32 v5;
  struct System_Byte_array *takara;
  char v7;
  s32 v9;
  s32 v10;
  s32 v12;
  struct System_Byte_array *takara2;
  char v14;

  v3 = idx - 256;
  if (idx >= 256)
  {
    v12 = v3 >> 3;
    takara2 = DDS3_GBWK->fldSave->takara2;
    v14 = v3 & 7;
    v9 = takara2->m_Items[v12];
    v10 = 1 << v14;
  }
  else
  {
    v5 = idx >> 3;
    takara = DDS3_GBWK->fldSave->takara;
    v7 = idx & 7;
    v9 = takara->m_Items[v5];
    v10 = 1 << v7;
  }
  return (v10 & v9) != 0;
}

// 0x12710d0
s32 fldGbChkView(s32 fld, s32 area, s32 blk) {
  char v4;
  s32 v9;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v13;

  v4 = blk;
  if (fld <= 0x1E && ((1 << fld) & 0x400006A4) != 0 || fld > 599)
    return 0;
  if (fldGb->fieldID > 39)
  {
    if (fld > 39)
    {
      if ((fld - 40) > 5)
        v9 = 0;
      else
        v9 = dword_33CC850[fld - 40];
    }
    else
    {
      v9 = fld % 100;
    }
  }
  v9 = fld % 100;
  {
  }
  PushBlock = DDS3_GBWK->fldSave->PushBlock;
  v13 = PushBlock->m_Items[v9];
  return ((1 << v4) & v13->m_Items[area]->MviewOffFlg) != 0;
}

// 0x127baa0
void fldGbFlagClear(void) {
  u64 i;
  struct System_Byte_array *takara;
  char *v6;
  struct System_Byte_array *takara2;
  struct System_Byte_array *v10;
  struct System_Byte_array *v12;
  struct System_Byte_array *v14;
  struct System_Byte_array *v16;
  struct System_Byte_array *v18;
  struct System_Byte_array *v20;
  struct System_Byte_array *v22;
  u64 v24;
  u64 j;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v29;
  struct fldBlockBuff_t_array_array *v31;
  fldBlockBuff_t_array *v33;
  struct fldBlockBuff_t_array_array *v35;
  fldBlockBuff_t_array *v37;
  struct fldBlockBuff_t_array_array *v39;
  fldBlockBuff_t_array *v41;
  struct fldBlockBuff_t_array_array *v43;
  fldBlockBuff_t_array *v45;
  u64 v48;
  s32 v49;
  struct fldBlockBuff_t_array_array *v50;
  fldBlockBuff_t_array *v52;
  struct System_Byte_array *EanimeCngID;
  s64 v56;
  u32 v57;
  struct fldBlockBuff_t_array_array *v58;
  fldBlockBuff_t_array *v60;
  struct fldBlockBuff_t_array_array *v62;
  fldBlockBuff_t_array *v64;
  Il2CppClass **v66;

  for (i = 0; i != 32; ++i)
  {
    takara = DDS3_GBWK->fldSave->takara;
    v6 = takara + i;
    v6[32] = 0;
  }
  takara2 = DDS3_GBWK->fldSave->takara2;
  takara2->m_Items[0] = 0;
  v10 = DDS3_GBWK->fldSave->takara2;
  v10->m_Items[1] = 0;
  v12 = DDS3_GBWK->fldSave->takara2;
  v12->m_Items[2] = 0;
  v14 = DDS3_GBWK->fldSave->takara2;
  v14->m_Items[3] = 0;
  v16 = DDS3_GBWK->fldSave->takara2;
  v16->m_Items[4] = 0;
  v18 = DDS3_GBWK->fldSave->takara2;
  v18->m_Items[5] = 0;
  v20 = DDS3_GBWK->fldSave->takara2;
  v20->m_Items[6] = 0;
  v22 = DDS3_GBWK->fldSave->takara2;
  v24 = 0;
  v22->m_Items[7] = 0;
  for (j = 0; ; j = 0)
  {
    do
    {
      PushBlock = DDS3_GBWK->fldSave->PushBlock;
      v29 = PushBlock->m_Items[v24];
      v29->m_Items[j]->MviewOffFlg = 0;
      v31 = DDS3_GBWK->fldSave->PushBlock;
      v33 = v31->m_Items[v24];
      v33->m_Items[j]->ManimeOffFlg = 0;
      v35 = DDS3_GBWK->fldSave->PushBlock;
      v37 = v35->m_Items[v24];
      v37->m_Items[j]->hitOffFlg = 0;
      v39 = DDS3_GBWK->fldSave->PushBlock;
      v41 = v39->m_Items[v24];
      v41->m_Items[j]->EviewOffFlg = 0;
      v43 = DDS3_GBWK->fldSave->PushBlock;
      v45 = v43->m_Items[v24];
      v45->m_Items[j]->EanimeOffFlg = 0;
      v48 = 0;
      do
      {
        v50 = DDS3_GBWK->fldSave->PushBlock;
        v52 = v50->m_Items[v24];
        EanimeCngID = v52->m_Items[j]->EanimeCngID;
        v56 = EanimeCngID + v48++;
        *(v56 + 32) = -1;
        v49 = (v57 >> 9) & 1;
      }
      while (v48 != 16);
      v58 = DDS3_GBWK->fldSave->PushBlock;
      v60 = v58->m_Items[v24];
      v60->m_Items[j]->npcOffFlg = 0;
      v62 = DDS3_GBWK->fldSave->PushBlock;
      v64 = v62->m_Items[v24];
      v66 = &v64->obj.klass + j++;
      HIWORD(v66[4]->_1.byval_arg.bits) = 0;
    }
    while (j != 32);
    if (++v24 == 40)
      break;
  }
  fldAutoMapClear();
}

// 0x127db70
s32 fldGbGetEAnimeCngID(s32 fld, s32 area, s32 grp) {
  s32 v9;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v13;
  struct System_Byte_array *EanimeCngID;

  if (fld <= 0x1E && ((1 << fld) & 0x400006A4) != 0 || fld > 599)
    return -1;
  if (fldGb->fieldID > 39)
  {
    if (fld > 39)
    {
      if ((fld - 40) > 5)
        v9 = 0;
      else
        v9 = dword_33CC850[fld - 40];
    }
    else
    {
      v9 = fld % 100;
    }
  }
  v9 = fld % 100;
  {
  }
  PushBlock = DDS3_GBWK->fldSave->PushBlock;
  v13 = PushBlock->m_Items[v9];
  EanimeCngID = v13->m_Items[area]->EanimeCngID;
  if (EanimeCngID->m_Items[grp] == 255)
    return -1;
  else
    return EanimeCngID->m_Items[grp];
}

// 0x127c7d0
s32 fldGbGetHojiIndex(s32 fld) {
  if (fld <= 39)
    return fld % 100;
  if ((fld - 40) > 5)
    return 0;
  return dword_33CC850[fld - 40];
}

// 0x127c820
s32 fldGbGetHojiNoData(s32 fld) {
  return fld <= 0x1E && ((1 << fld) & 0x400006A4) != 0 || fld > 599;
}

// 0x127c5e0
void fldGbInit_Field(void) {
  fldGb->flag = 0;
  fldGb->cammode2 = 0;
  fldGb->FootSEUp = 0;
  fldGb->ElvIdx = -1;
  fldGb->WaterIdx = -1;
  fldGb->AllPanelMode = 1;
  fldGb->AllPanelCnt = 0;
  fldGb->EL_serialID = -1;
  fldGb->SeId = 16;
  fldGb->DmgOn = 0;
  fldGb->DmgLeng = 100.0;
  fldGb->GunDmgOn = 0;
  gfldPlayerDamegeCnt = 0;
  fldGb->NoroiDamegeCnt = 0;
  fldGb->syukan_cam_reset_flg = 0;
  fldGb->LastMoveLeng = 0.0;
  fldDbg->MenuOn = 0;
  fldDbg->MenuCur = 0;
  fldDbg->MenuCur1 = 0;
  fldDbg->MenuCur2 = 0;
  fldDbg->MenuCur3 = 0;
  fldDbg->MenuCur4 = 0;
  fldDbg->MenuCur11 = 1;
  fldDbg->SkyTblID = 0;
  fldDbg->SkyTblAnm = 0;
  fldDbg->FilterID = 0;
  fldDbg->FilterAlp = 0;
  fldDbg->FilterAnm = 0;
}

// 0x127c1c0
void fldGbInit_System(s32 mode) {
  fldGlobal_c *v3;

  fldGb->fieldID = 0;
  fldGb->areaID = 0;
  fldGb->blockID = 0;
  fldGb->fieldOldID = 0;
  fldGb->flag = 0;
  fldGb->cammode = 0;
  fldGb->cammode2 = 0;
  fldGb->NoEncountCnt = 0;
  fldGb->NoInpAmCnt = 0;
  fldGb->NoInpPlCnt = 0;
  fldGb->FootSE = 0;
  fldGb->FootSEUp = 0;
  fldGb->ElvIdx = -1;
  fldGb->WaterIdx = -1;
  fldGb->nameU = -1;
  fldGb->nameD = -1;
  fldGb->AllPanelMode = 1;
  fldGb->AllPanelCnt = 0;
  fldGb->EL_serialID = -1;
  fldGb->CamTableIdx = 0;
  fldGb->BgmId = 1;
  fldGb->SeId = 16;
  fldGb->AreaToArea = 0;
  fldGb->Snow = 0;
  fldGb->DmgOn = 0;
  fldGb->DmgLeng = 100.0;
  fldGb->GunDmgOn = 0;
  fldGb->NoroiDamegeCnt = 0;
  fldGb->LightMa = 0;
  fldGb->EncPID = 0;
  fldGb->EncPIDUpper = 0;
  fldGb->LastMoveLeng = 0.0;
  fldGb->FukiTalk = 0;
  fldGb->syukan_cam_reset_flg = 0;
  fldGb->playerX = 0.0;
  fldGb->playerY = 0.0;
  fldGb->playerZ = 0.0;
  fldGb->playerOldX = 0.0;
  fldGb->playerOldY = 0.0;
  fldGb->playerOldZ = 0.0;
  fldGb->playerNewX = 0.0;
  fldGb->playerNewY = 0.0;
  fldGb->playerNewZ = 0.0;
  fldGb->PlayerKakudo = 0.0;
  fldGb->PlayerKakudoGoal = 180.0;
  fldGb->PlayerMotionFrame = 0.0;
  fldGb->PlayerSaka = 0.0;
  fldGb->HitUpdate = 0;
  fldDbg->MenuOn = 0;
  fldDbg->MenuCur = 0;
  fldDbg->MenuCur1 = 0;
  fldDbg->MenuCur2 = 0;
  fldDbg->MenuCur3 = 0;
  fldDbg->MenuCur4 = 0;
  fldDbg->MenuCur11 = 1;
  fldDbg->HitView = 0;
  fldDbg->ViewMode = 0;
  fldDbg->InfoOn = 0;
  fldDbg->BlurOn = 1;
  fldDbg->ExBlurOn = 1;
  fldDbg->SkyTblID = 0;
  fldDbg->SkyTblAnm = 0;
  fldDbg->FilterID = 0;
  fldDbg->FilterAlp = 0;
  fldDbg->FilterMode = 0;
  fldDbg->FilterAnm = 0;
  fldDbg->NoClip = 1;
  fldDbg->EncountBtnOn = 0;
  fldDbg->PlayerStatus = 0;
  fldDbg->PlayerAction = 0;
  fldDbg->AutomapRapid = 0;
  fldDbg->SpProcOn = 1;
  fldDbg->WarpSkip = 1;
  if (!mode)
  {
    fldGbFlagClear(v3);
  }
}

// 0x127caf0
void fldGbSetAnime(s32 fld, s32 area, s32 blk, s32 onoff) {
  char v6;
  s32 v10;
  struct fldBlockBuff_t_array_array *v13;
  fldBlockBuff_t_array *v15;
  fldBlockBuff_t_o *v17;
  s32 v18;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v21;

  v6 = blk;
  if ((fld > 0x1E || ((1 << fld) & 0x400006A4) == 0) && fld <= 599)
  {
    if (fldGb->fieldID <= 39)
    {
      v10 = fld % 100;
      if (!onoff)
      {
        PushBlock = DDS3_GBWK->fldSave->PushBlock;
        v21 = PushBlock->m_Items[v10];
        v17 = v21->m_Items[area];
        v18 = v17->ManimeOffFlg & ~(1 << v6);
        v17->ManimeOffFlg = v18;
        return;
      }
    }
    else
    {
      if (fld > 39)
      {
        if ((fld - 40) > 5)
          v10 = 0;
        else
          v10 = dword_33CC850[fld - 40];
      }
      else
      {
        v10 = fld % 100;
      }
      if (!onoff)
    }
    v13 = DDS3_GBWK->fldSave->PushBlock;
    v15 = v13->m_Items[v10];
    v17 = v15->m_Items[area];
    v18 = v17->ManimeOffFlg | (1 << v6);
  }
}

// 0x127d4b0
void fldGbSetEAnime(s32 fld, s32 area, s32 grp, s32 onoff) {
  char v6;
  s32 v10;
  struct fldBlockBuff_t_array_array *v13;
  fldBlockBuff_t_array *v15;
  fldBlockBuff_t_o *v17;
  s32 v18;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v21;

  v6 = grp;
  if ((fld > 0x1E || ((1 << fld) & 0x400006A4) == 0) && fld <= 599)
  {
    if (fldGb->fieldID <= 39)
    {
      v10 = fld % 100;
      if (!onoff)
      {
        PushBlock = DDS3_GBWK->fldSave->PushBlock;
        v21 = PushBlock->m_Items[v10];
        v17 = v21->m_Items[area];
        v18 = v17->EanimeOffFlg & ~(1 << v6);
        v17->EanimeOffFlg = v18;
        return;
      }
    }
    else
    {
      if (fld > 39)
      {
        if ((fld - 40) > 5)
          v10 = 0;
        else
          v10 = dword_33CC850[fld - 40];
      }
      else
      {
        v10 = fld % 100;
      }
      if (!onoff)
    }
    v13 = DDS3_GBWK->fldSave->PushBlock;
    v15 = v13->m_Items[v10];
    v17 = v15->m_Items[area];
    v18 = v17->EanimeOffFlg | (1 << v6);
  }
}

// 0x127d950
void fldGbSetEAnimeCngID(s32 fld, s32 area, s32 grp, s32 animeid) {
  u8 v5;
  s32 v10;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v14;
  struct System_Byte_array *EanimeCngID;

  v5 = animeid;
  if ((fld > 0x1E || ((1 << fld) & 0x400006A4) == 0) && fld <= 599)
  {
    if (fldGb->fieldID <= 39)
    {
      v10 = fld % 100;
      {
        PushBlock = DDS3_GBWK->fldSave->PushBlock;
        v14 = PushBlock->m_Items[v10];
        EanimeCngID = v14->m_Items[area]->EanimeCngID;
        EanimeCngID->m_Items[grp] = v5;
        return;
      }
    }
    else
    {
      if (fld > 39)
      {
        if ((fld - 40) > 5)
          v10 = 0;
        else
          v10 = dword_33CC850[fld - 40];
      }
      else
      {
        v10 = fld % 100;
      }
    }
  }
}

// 0x127d010
void fldGbSetEView(s32 fld, s32 area, s32 grp, s32 onoff) {
  char v6;
  s32 v10;
  struct fldBlockBuff_t_array_array *v13;
  fldBlockBuff_t_array *v15;
  fldBlockBuff_t_o *v17;
  s32 v18;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v21;

  v6 = grp;
  if ((fld > 0x1E || ((1 << fld) & 0x400006A4) == 0) && fld <= 599)
  {
    if (fldGb->fieldID <= 39)
    {
      v10 = fld % 100;
      if (!onoff)
      {
        PushBlock = DDS3_GBWK->fldSave->PushBlock;
        v21 = PushBlock->m_Items[v10];
        v17 = v21->m_Items[area];
        v18 = v17->EviewOffFlg & ~(1 << v6);
        v17->EviewOffFlg = v18;
        return;
      }
    }
    else
    {
      if (fld > 39)
      {
        if ((fld - 40) > 5)
          v10 = 0;
        else
          v10 = dword_33CC850[fld - 40];
      }
      else
      {
        v10 = fld % 100;
      }
      if (!onoff)
    }
    v13 = DDS3_GBWK->fldSave->PushBlock;
    v15 = v13->m_Items[v10];
    v17 = v15->m_Items[area];
    v18 = v17->EviewOffFlg | (1 << v6);
  }
}

// 0x127e240
void fldGbSetGimic(s32 fld, s32 area, s32 hojiID, s32 toplast) {
  char v6;
  s32 v10;
  struct fldBlockBuff_t_array_array *v13;
  fldBlockBuff_t_array *v15;
  fldBlockBuff_t_o *v17;
  s32 v18;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v21;

  v6 = hojiID;
  if ((fld > 0x1E || ((1 << fld) & 0x400006A4) == 0) && fld <= 599)
  {
    if (fldGb->fieldID <= 39)
    {
      v10 = fld % 100;
      if (!toplast)
      {
        PushBlock = DDS3_GBWK->fldSave->PushBlock;
        v21 = PushBlock->m_Items[v10];
        v17 = v21->m_Items[area];
        v18 = v17->gimicLastFlg & ~(1 << v6);
        v17->gimicLastFlg = v18;
        return;
      }
    }
    else
    {
      if (fld > 39)
      {
        if ((fld - 40) > 5)
          v10 = 0;
        else
          v10 = dword_33CC850[fld - 40];
      }
      else
      {
        v10 = fld % 100;
      }
      if (!toplast)
    }
    v13 = DDS3_GBWK->fldSave->PushBlock;
    v15 = v13->m_Items[v10];
    v17 = v15->m_Items[area];
    v18 = v17->gimicLastFlg | (1 << v6);
  }
}

// 0x127cd80
void fldGbSetHit(s32 fld, s32 area, s32 blk, s32 onoff) {
  char v6;
  s32 v10;
  struct fldBlockBuff_t_array_array *v13;
  fldBlockBuff_t_array *v15;
  fldBlockBuff_t_o *v17;
  s32 v18;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v21;

  v6 = blk;
  if ((fld > 0x1E || ((1 << fld) & 0x400006A4) == 0) && fld <= 599)
  {
    if (fldGb->fieldID <= 39)
    {
      v10 = fld % 100;
      if (!onoff)
      {
        PushBlock = DDS3_GBWK->fldSave->PushBlock;
        v21 = PushBlock->m_Items[v10];
        v17 = v21->m_Items[area];
        v18 = v17->hitOffFlg & ~(1 << v6);
        v17->hitOffFlg = v18;
        return;
      }
    }
    else
    {
      if (fld > 39)
      {
        if ((fld - 40) > 5)
          v10 = 0;
        else
          v10 = dword_33CC850[fld - 40];
      }
      else
      {
        v10 = fld % 100;
      }
      if (!onoff)
    }
    v13 = DDS3_GBWK->fldSave->PushBlock;
    v15 = v13->m_Items[v10];
    v17 = v15->m_Items[area];
    v18 = v17->hitOffFlg | (1 << v6);
  }
}

// 0x127dda0
void fldGbSetNpc(s32 fld, s32 area, s32 hojiID, s32 onoff) {
  char v6;
  s32 v10;
  struct fldBlockBuff_t_array_array *v13;
  fldBlockBuff_t_array *v15;
  fldBlockBuff_t_o *v17;
  s32 v18;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v21;

  v6 = hojiID;
  if ((fld > 0x1E || ((1 << fld) & 0x400006A4) == 0) && fld <= 599)
  {
    if (fldGb->fieldID <= 39)
    {
      v10 = fld % 100;
      if (!onoff)
      {
        PushBlock = DDS3_GBWK->fldSave->PushBlock;
        v21 = PushBlock->m_Items[v10];
        v17 = v21->m_Items[area];
        v18 = v17->npcOffFlg & ~(1 << v6);
        v17->npcOffFlg = v18;
        return;
      }
    }
    else
    {
      if (fld > 39)
      {
        if ((fld - 40) > 5)
          v10 = 0;
        else
          v10 = dword_33CC850[fld - 40];
      }
      else
      {
        v10 = fld % 100;
      }
      if (!onoff)
    }
    v13 = DDS3_GBWK->fldSave->PushBlock;
    v15 = v13->m_Items[v10];
    v17 = v15->m_Items[area];
    v18 = v17->npcOffFlg | (1 << v6);
  }
}

// 0x127e4d0
void fldGbSetTakaraOpen(s32 idx) {
  s32 v4;
  struct System_Byte_array *takara;
  s32 v8;
  struct System_Byte_array *takara2;

  if (idx >= 256)
  {
    v8 = (idx - 256) >> 3;
    takara2 = DDS3_GBWK->fldSave->takara2;
    takara2->m_Items[v8] |= 1 << (idx & 7);
    fldItemBoxOpen(idx);
  }
  else
  {
    v4 = idx >> 3;
    takara = DDS3_GBWK->fldSave->takara;
    takara->m_Items[v4] |= 1 << (idx & 7);
    fldItemBoxOpen(idx);
    if (idx >= 240)
      evtBitOn(idx + 1552);
  }
}

// 0x127c860
void fldGbSetView(s32 fld, s32 area, s32 blk, s32 onoff) {
  char v6;
  s32 v10;
  struct fldBlockBuff_t_array_array *v13;
  fldBlockBuff_t_array *v15;
  fldBlockBuff_t_o *v17;
  s32 v18;
  struct fldBlockBuff_t_array_array *PushBlock;
  fldBlockBuff_t_array *v21;

  v6 = blk;
  if ((fld > 0x1E || ((1 << fld) & 0x400006A4) == 0) && fld <= 599)
  {
    if (fldGb->fieldID <= 39)
    {
      v10 = fld % 100;
      if (!onoff)
      {
        PushBlock = DDS3_GBWK->fldSave->PushBlock;
        v21 = PushBlock->m_Items[v10];
        v17 = v21->m_Items[area];
        v18 = v17->MviewOffFlg & ~(1 << v6);
        v17->MviewOffFlg = v18;
        return;
      }
    }
    else
    {
      if (fld > 39)
      {
        if ((fld - 40) > 5)
          v10 = 0;
        else
          v10 = dword_33CC850[fld - 40];
      }
      else
      {
        v10 = fld % 100;
      }
      if (!onoff)
    }
    v13 = DDS3_GBWK->fldSave->PushBlock;
    v15 = v13->m_Items[v10];
    v17 = v15->m_Items[area];
    v18 = v17->MviewOffFlg | (1 << v6);
  }
}

// 0x127b3d0
void fldGbTblLoad(void) {
  u64 *v1;
  UnityEngine_Object_o *fldNameData;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v8;
  UnityEngine_Object_o *Asset;
  struct fldGlobal_StaticFields *static_fields;
  s64 typeHierarchyDepth;
  UnityEngine_Object_o *v13;
  UnityEngine_Object_o *fldHitData;
  AssetBundleCtrl_o *v17;
  AssetBundleCtrl_o *v19;
  UnityEngine_Object_o *v21;
  struct fldGlobal_StaticFields *v22;
  s64 v23;
  UnityEngine_Object_o *v24;
  UnityEngine_Object_o *fldCameraParam;
  AssetBundleCtrl_o *v28;
  AssetBundleCtrl_o *v31;
  UnityEngine_Object_o *v34;
  struct fldGlobal_StaticFields *v35;
  s64 v36;
  UnityEngine_Object_o *v37;

  v1 = Allocate(sdfFileCmdHandle_t);
  sdfFileCmdHandle_t___ctor(v1);
  if (op_Equality(fldNameData, 0, 0))
  {
    asset_bc = get_asset_bc();
    if (IsLoad(asset_bc, StringLiteral_8913))
    {
      v8 = get_asset_bc();
      {
      }
      Asset = LoadAsset(
                v8,
                StringLiteral_8913,
                ParamDataAssetPath,
                StringLiteral_16674,
                0);
      else
      {
        static_fields = fldGlobal->static_fields;
        if (!Asset)
      }
      if (Asset->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
      {
        if (Asset->klass->_2.typeHierarchy[typeHierarchyDepth - 1] == FldNameData)
          v13 = Asset;
        else
          v13 = 0;
      }
      v13 = 0;
      static_fields->fldNameData = v13;
    }
  }
  if (op_Equality(fldHitData, 0, 0))
  {
    v17 = get_asset_bc();
    if (IsLoad(v17, StringLiteral_8913))
    {
      v19 = get_asset_bc();
      {
      }
      v21 = LoadAsset(
              v19,
              StringLiteral_8913,
              ParamDataAssetPath,
              StringLiteral_16675,
              0);
      else
      {
        v22 = fldGlobal->static_fields;
        if (!v21)
      }
      if (v21->klass->_2.typeHierarchyDepth >= v23)
      {
        if (v21->klass->_2.typeHierarchy[v23 - 1] == FldHitData)
          v24 = v21;
        else
          v24 = 0;
      }
      v24 = 0;
      v22->fldHitData = v24;
    }
  }
  if (op_Equality(fldCameraParam, 0, 0))
  {
    v28 = get_asset_bc();
    if (IsLoad(v28, StringLiteral_8913))
    {
      v31 = get_asset_bc();
      {
      }
      v34 = LoadAsset(
              v31,
              StringLiteral_8913,
              ParamDataAssetPath,
              StringLiteral_16676,
              0);
      else
      {
        v35 = fldGlobal->static_fields;
        if (!v34)
      }
      if (v34->klass->_2.typeHierarchyDepth >= v36)
      {
        if (v34->klass->_2.typeHierarchy[v36 - 1] == FldCameraParam)
          v37 = v34;
        else
          v37 = 0;
      }
      v37 = 0;
      v35->fldCameraParam = v37;
      fldCameraInit();
    }
  }
}
