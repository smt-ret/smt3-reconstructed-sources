#include "types.h"

typedef struct AssetBundles AssetBundles;
typedef struct datUnitWork_s datUnitWork_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;
typedef struct nbSound_t nbSound_t;

static char *bgmno;
static s32 bgmsub;
static s32 bgmloadphase;
static s32 bgmdone;
static s32 bgmkey;
static char *nbLoadSound_str;

char *AppendDLC(char *name, bool append);
void FadeoutBGM(char *name, f32 fadeTime);
s32 FindId(s32 type, char *name);
u8 Get(s32 id);
u32 GetMotionMIDI(s32 id, s32 mot, datUnitWork_t *uwork);
s32 GetUnitID(nbFormation_t *form);
bool IsLoad(AssetBundles *this, char *key);
bool IsModelDante(s32 id);
void Load(char *key, char *filePath);
s32 LoadBattleBGM(s32 *bgmdone, s32 *bgmloadphase);
void LoadKeysBGM1(s32 type, char *key, char *bgm_name);
void LoadSound(char *key, char *path);
void PlayBGM(char *name);
void ReleaseSound(char *key);
void RemoveDLC(char *key);
bool evtBitCheck(s32 no);
nbSound_t *nbAddSoundTable(s32 id);
void nbFreeSound1(nbMainProcessData_t *data, s32 index);
s32 nbGetBgmCategoryInBattle(void);
s32 nbGetBgmCategoryInField(u32 encdata);
nbMainProcessData_t *nbGetMainProcessData(void);
u32 nbGetMotionMIDI(nbFormation_t *form, s32 mot);
s32 nbGetMotionSeNo(s32 id, s32 mot);
s32 nbGetUnitID(datUnitWork_t *work);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);
s32 nbSearchEmptySoundTable(void);
s32 nbSearchSoundTable(s32 id);
void p2sdBGMVolume(u16 vol);
s32 p2sdFadeOut(s32 a);
s32 p2sdPlaySE(s32 a);

// 0x157f6d0
u32 GetMotionMIDI(s32 id, s32 mot, datUnitWork_t *uwork) {
  s32 v9;
  s32 MotionSeNo;
  s32 v12;
  bool IsModelDante;
  s32 nowindex;

  v9 = Get(id, 0);
  MotionSeNo = nbGetMotionSeNo(v9, mot);
  if (MotionSeNo < 0)
    return 0;
LABEL_9:
  v12 = MotionSeNo;
  IsModelDante = IsModelDante(v9);
  if (uwork && !IsModelDante && uwork->nowcommand == 1)
  {
    nowindex = uwork->nowindex;
    switch (nowindex)
    {
      case 264:
        v12 = 8;
        break;
      case 267:
        v12 = 9;
        break;
      case 268:
        v12 = 10;
        break;
    }
  }
  evtBitCheck(3087);
  if (IsModelDante)
    return (((v12 + 16 * v9) << 16) + 0x10000000) | 2;
  else
    return ((v12 + 16 * v9) << 16) + 0x10000000;
}

// 0x157f900
u32 GetNegoMIDI(s32 id) {
  return (id << 16) + 83886080;
}

// 0x157f480
s32 GetUnitID(nbFormation_t *form) {
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;

  formindex = form->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  return nbGetUnitID(UnitWorkFromFormindex);
}

// 0x1580050
nbSound_t *nbAddSoundTable(s32 id) {
  nbMainProcessData_t_o *MainProcessData;
  s32 v5;
  struct nbSound_t_array *sound;
  nbSound_t_o *v9;
  nbSound_t_o *result;
  s32 v13;
  struct nbSound_t_array *v14;

  MainProcessData = nbGetMainProcessData();
  else
  {
    v5 = nbSearchSoundTable(id);
    if ((v5 & 0x80000000) == 0)
    {
LABEL_9:
      sound = MainProcessData->sound;
      v9 = sound->m_Items[v5];
      ++v9->linkcnt;
      return 0;
    }
  }
  v13 = nbSearchEmptySoundTable();
  v14 = MainProcessData->sound;
  result = v14->m_Items[v13];
  result->exist = 1;
  result->id = id;
  result->linkcnt = 1;
  return result;
}

// 0x157ccd0
void nbBgmFadeOut(void) {
  System_String_o *bgmno;

  FadeoutBGM(bgmno, 1.0);
}

// 0x1580d50
void nbBgmLoad(s32 encdata) {
  u64 *v3;
  u64 *v11;
  u64 *v21;
  s32 BgmCategoryInField;
  s32 v56;
  s32 v58;
  s32 bgmsub;
  s32 v60;
  u32 v61;
  s32 v63;
  s32 v64;
  u32 v65;
  u64 *v67;
  System_String_o *v69;
  System_String_o *appended;
  AssetBundleCtrl_o *asset_bc;
  s32 v75;
  AssetBundleCtrl_o *v76;
  s32 bgmkey;

  v3 = NewSpecific(string, 7u);
  v3[4] = "B0100_B0101_BGM01";
  v3[5] = "B0100_B0102_BGM01";
  v3[6] = "B0100_B0103_BGM01";
  v3[7] = "B0100_B0104_BGM01";
  v3[8] = "B0100_B0105_BGM01";
  v3[9] = "B0100_B0106_BGM01";
  v3[10] = "B0100_B0107_BGM01";
  v11 = NewSpecific(string, 8u);
  v11[4] = "B0300_B0301_BGM01";
  v11[5] = "B0300_B0302_BGM01";
  v11[6] = "B0300_B0303_BGM01";
  v11[7] = "B0300_B0304_BGM01";
  v11[8] = "B0300_B0305_BGM01";
  v11[9] = "B0300_B0306_BGM01";
  v11[10] = "B0300_B0307_BGM01";
  v11[11] = "B0300_B0308_BGM01";
  v21 = NewSpecific(string, 8u);
  v21[4] = "B0500_B0501_BGM01";
  v21[5] = "B0500_B0502_BGM01";
  v21[6] = "B0500_B0503_BGM01";
  v21[7] = "B0500_B0504_BGM01";
  v21[8] = "B0500_B0505_BGM01";
  v21[9] = "B0500_B0506_BGM01";
  v21[10] = "B0500_B0507_BGM01";
  v21[11] = "B0500_B0508_BGM01";
  else if (bgmloadphase)
  {
    return;
  }
  if (encdata)
  {
    BgmCategoryInField = nbGetBgmCategoryInField(encdata);
    {
LABEL_103:
    }
  }
  else
  {
    BgmCategoryInField = nbGetBgmCategoryInBattle();
      goto LABEL_103;
  }
  bgmdone = 0;
  switch (BgmCategoryInField)
  {
    case 1:
      v56 = bgmsub % 7;
      bgmno = v3[v56 + 4];
      v58 = 6;
      goto LABEL_205;
    case 2:
      v60 = bgmsub + 7;
      if (bgmsub >= 0)
        v60 = bgmsub;
      v61 = bgmsub - (v60 & 0xFFFFFFF8);
      bgmno = v11[v61 + 4];
      v58 = 8;
      goto LABEL_205;
    case 3:
      v63 = bgmsub;
      v64 = v63 + 7;
      if (v63 >= 0)
        v64 = bgmsub;
      v65 = v63 - (v64 & 0xFFFFFFF8);
      bgmno = v21[v65 + 4];
      v58 = 1;
      goto LABEL_205;
    case 4:
      bgmno = "B0800_B0801_BGM01";
      v58 = 4;
      goto LABEL_205;
    case 5:
      bgmno = "B0200_B0201_BGM01";
      v58 = 7;
      goto LABEL_205;
    case 6:
      bgmno = "B0400_B0401_BGM01";
      v58 = 9;
      goto LABEL_205;
    case 7:
      bgmno = "B0600_B0601_BGM01";
      v58 = 2;
      goto LABEL_205;
    case 8:
      bgmno = "B0700_B0701_BGM01";
      v58 = 3;
      goto LABEL_205;
    case 9:
      bgmno = "B0900_B0901_BGM01";
      v58 = 5;
      goto LABEL_205;
    case 10:
      bgmno = "B1200_B1201_BGM01";
      v58 = 12;
      goto LABEL_205;
    case 11:
      bgmno = "B1300_B1301_BGM01";
      v58 = 13;
      goto LABEL_205;
    case 12:
      bgmno = "B1400_B1401_BGM01";
      v58 = 14;
      goto LABEL_205;
    case 13:
      bgmno = "B1500_B1501_BGM01";
      v58 = 15;
      goto LABEL_205;
    case 14:
      bgmno = "B1100_B1101_BGM01";
      v58 = 11;
      goto LABEL_205;
    case 15:
      bgmno = "B1000_B1001_BGM01";
      v58 = 10;
LABEL_205:
      bgmkey = v58;
      break;
    default:
      break;
  }
  v67 = sub_8D3950(s32, &bgmkey);
  v69 = Format("b_bgm{0:D2}", v67, 0);
  appended = AppendDLC(v69, 1);
  if (!Equals_5234480(appended, v69))
    goto LABEL_224;
  asset_bc = get_asset_bc();
  if (!IsLoad(asset_bc, v69))
  {
    v76 = get_asset_bc();
    Load(v76, v69, v69, 0);
LABEL_224:
    v75 = 1;
    goto LABEL_228;
  }
  else
  {
    v75 = 2;
  }
LABEL_228:
  bgmloadphase = v75;
}

// 0x1580ac0
s32 nbBgmLoadChk(void) {
  u64 *v3;
  System_String_o *v5;
  System_String_o *appended;
  bool v8;
  s32 v11;
  s32 bgmloadphase;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *bgmno;
  s32 bgmkey;

  v3 = sub_8D3950(s32, &bgmkey);
  v5 = Format("b_bgm{0:D2}", v3, 0);
  appended = AppendDLC(v5, 1);
  v8 = Equals_5234480(appended, v5);
  if (v8)
  {
    else
    {
      if (bgmdone == 1)
        return 1;
    }
    if (bgmloadphase == 2)
    {
      v11 = 1;
      LoadKeysBGM1(1, v5, bgmno);
      bgmloadphase = 0;
      bgmdone = 1;
    }
    else
    {
      if (bgmloadphase != 1)
        return 0;
      asset_bc = get_asset_bc();
      if (IsLoad(asset_bc, v5))
      {
        v11 = 0;
        ++bgmloadphase;
      }
      else
      {
        return 0;
      }
    }
  }
  else
  {
    return LoadBattleBGM(&bgmdone, &bgmloadphase);
  }
  return v11;
}

// 0x157cd70
void nbBgmNext(void) {
  ++bgmsub;
}

// 0x1581d30
void nbBgmPlay(void) {
  System_String_o *bgmno;

  PlayBGM(bgmno);
}

// 0x1581dd0
void nbBgmStop(void) {
  System_String_o *bgmno;

  FadeoutBGM(bgmno, 1.0);
  p2sdFadeOut(2818048);
}

// 0x1581dc0
void nbBgmTrans(void) {
  ;
}

// 0x1581f00
void nbBgmVolOff(void) {
  p2sdBGMVolume(0);
}

// 0x1581e90
void nbBgmVolOn(void) {
  p2sdBGMVolume(0x7Fu);
}

// 0x157fe00
void nbDeleteSound(s32 id) {
  nbMainProcessData_t_o *MainProcessData;
  s32 v5;
  struct nbSound_t_array *sound;
  s32 v9;
  struct nbSound_t_array *v11;

  MainProcessData = nbGetMainProcessData();
  else
  {
    v5 = nbSearchSoundTable(id);
    if (v5 < 0)
      return;
  }
  sound = MainProcessData->sound;
  v9 = v5;
  --sound->m_Items[v5]->linkcnt;
  v11 = MainProcessData->sound;
  if (!v11->m_Items[v5]->linkcnt)
  {
    nbFreeSound1(MainProcessData, v9);
  }
}

// 0x1580780
void nbFreeSound(nbMainProcessData_t *data) {
  u64 *v24;
  System_String_o *v26;
  s32 bgmkey;

  nbFreeSound1(data, 0);
  nbFreeSound1(data, 1);
  nbFreeSound1(data, 2);
  nbFreeSound1(data, 3);
  nbFreeSound1(data, 4);
  nbFreeSound1(data, 5);
  nbFreeSound1(data, 6);
  nbFreeSound1(data, 7);
  nbFreeSound1(data, 8);
  nbFreeSound1(data, 9);
  data->sound = 0;
  data->sound_mem = 0;
  v24 = sub_8D3950(s32, &bgmkey);
  v26 = Format("b_bgm{0:D2}", v24, 0);
  RemoveDLC(v26);
}

// 0x157ff60
void nbFreeSound1(nbMainProcessData_t *data, s32 index) {
  struct nbSound_t_array *sound;
  nbSound_t_o *v7;
  u64 *v8;
  System_String_o *v10;
  u16 id;

  sound = data->sound;
  v7 = sound->m_Items[index];
  if (v7->exist)
  {
    id = v7->id;
    v8 = sub_8D3950(ushort, &id);
    v10 = Format("B{0:X4}", v8, 0);
    ReleaseSound(v10);
    *&v7->exist = 0;
  }
}

// 0x157f840
u32 nbGetMotionMIDI(nbFormation_t *form, s32 mot) {
  s32 UnitID;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;

  UnitID = GetUnitID(form, *&mot);
  formindex = form->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  return GetMotionMIDI(UnitID, mot, UnitWorkFromFormindex);
}

// 0x157f5c0
s32 nbGetMotionSeNo(s32 id, s32 mot) {
  datUnitVisual_t_o *v5;
  struct datUnitVisual_t_array *datHumanVisual;
  struct datUnitMotion_s_array *motion;

  if (!id)
  {
    else
    {
      if (!LODWORD(datHumanVisual->max_length))
        goto LABEL_11;
    }
    v5 = datHumanVisual->m_Items[0];
    goto LABEL_13;
  }
  v5 = Get(id, 0);
LABEL_13:
  motion = v5->motion;
  return motion->m_Items[mot]->se_no;
}

// 0x157f910
u32 nbGetNegoMIDI(nbFormation_t *form) {
  return (GetUnitID(form) << 16) + 83886080;
}

// 0x15809c0
void nbInitSound(nbMainProcessData_t *data) {
  struct nbSound_t_array *v3;
  u32 *sound;
  u64 i;
  u64 *v6;

  v3 = NewSpecific(nbSound_t, 0xAu);
  data->sound = v3;
  sound = v3;
  for (i = 0; ; ++i)
  {
    v6 = Allocate(nbSound_t);
    nbSound_t___ctor(v6);
    *&sound[2 * i + 8] = v6;
    if (i == 9)
      break;
    sound = data->sound;
  }
}

// 0x1580480
s32 nbLoadSound(s32 id) {
  nbSound_t_o *v4;
  nbSound_t_o *v7;
  u32 MotionMIDI;
  u64 *v9;
  System_String_o *v11;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v14;
  s32 v16;

  nbGetMainProcessData();
  v4 = nbAddSoundTable(id);
  if (v4)
  {
    v7 = v4;
    v16 = id;
    MotionMIDI = GetMotionMIDI(id, 0, 0);
    v9 = sub_8D3950(s32, &v16);
    v11 = Format("B{0:X4}", v9, 0);
    asset_bc = get_asset_bc();
    if (!IsLoad(asset_bc, v11))
    {
      v14 = get_asset_bc();
      Load(v14, v11, v11, 0);
      v7->motse_h = HIWORD(MotionMIDI);
    }
  }
  return 1;
}

// 0x157fc70
s32 nbMemoryLoadMotionSe(nbFormation_t *form, s32 mot) {
  s32 result;
  u64 *v9;
  AssetBundleCtrl_o *asset_bc;
  s32 v13;

  nbGetMainProcessData();
  if (mot < 0)
    return 0;
LABEL_6:
  result = nbGetMotionMIDI(form, mot);
  if (result)
  {
    v13 = result;
    v9 = sub_8D3950(uint, &v13);
    Write_2930400("MIDI=0x{0:X8}\n", v9);
    asset_bc = get_asset_bc();
    if (IsLoad(asset_bc, form->akey))
    {
      Write("motSE_ok!\n", 0);
    }
    return 1;
  }
  return result;
}

// 0x157f980
s32 nbMemoryLoadNegoSe(nbFormation_t *form) {
  nbMainProcessData_t_o *MainProcessData;
  AssetBundleCtrl_o *asset_bc;
  s32 v8;

  MainProcessData = nbGetMainProcessData();
LABEL_10:
  GetUnitID(form);
  asset_bc = get_asset_bc();
  if (IsLoad(asset_bc, form->akey))
  {
    Write("negoSE_ok!\n", 0);
    return 1;
  }
  else
  {
    v8 = GetUnitID(form);
    if ((nbSearchSoundTable(v8) & 0x80000000) == 0)
      goto LABEL_24;
  }
  return 0;
}

// 0x157e310
void nbPlaySe(s32 no) {
  p2sdPlaySE(no);
}

// 0x157f520
void nbPlaySe_22541600(char *no) {
  s32 Id;

  Id = FindId(1, no);
  p2sdPlaySE(Id);
}

// 0x15801a0
s32 nbSearchEmptySoundTable(void) {
  nbMainProcessData_t_o *MainProcessData;
  struct nbSound_t_array *sound;
  struct nbSound_t_array *v4;
  struct nbSound_t_array *v5;
  struct nbSound_t_array *v7;
  struct nbSound_t_array *v8;
  struct nbSound_t_array *v10;
  struct nbSound_t_array *v12;
  struct nbSound_t_array *v14;
  struct nbSound_t_array *v16;
  struct nbSound_t_array *v18;

  MainProcessData = nbGetMainProcessData();
  sound = MainProcessData->sound;
  if (!sound->m_Items[0]->exist)
    return 0;
  v4 = MainProcessData->sound;
  if (!v4->m_Items[1]->exist)
    return 1;
  v5 = MainProcessData->sound;
  if (!v5->m_Items[2]->exist)
    return 2;
  v7 = MainProcessData->sound;
  if (!v7->m_Items[3]->exist)
    return 3;
  v8 = MainProcessData->sound;
  if (!v8->m_Items[4]->exist)
    return 4;
  v10 = MainProcessData->sound;
  if (!v10->m_Items[5]->exist)
    return 5;
  v12 = MainProcessData->sound;
  if (!v12->m_Items[6]->exist)
    return 6;
  v14 = MainProcessData->sound;
  if (!v14->m_Items[7]->exist)
    return 7;
  v16 = MainProcessData->sound;
  if (!v16->m_Items[8]->exist)
    return 8;
  v18 = MainProcessData->sound;
  if (v18->m_Items[9]->exist)
    return -1;
  else
    return 9;
}

// 0x157fb70
s32 nbSearchSoundTable(s32 id) {
  nbMainProcessData_t_o *MainProcessData;
  u64 v4;
  s32 v5;
  struct nbSound_t_array *sound;
  struct nbSound_t_array *v8;

  MainProcessData = nbGetMainProcessData();
  v4 = 0;
  v5 = -1;
  while (1)
  {
    sound = MainProcessData->sound;
    if (sound->m_Items[v4]->exist)
    {
      v8 = MainProcessData->sound;
      if (v8->m_Items[v4]->id == id)
        break;
    }
    if (v4++ > 8)
      return v5;
  }
  return v4;
}

// 0x1580600
void nbUpdateSoundTable(nbMainProcessData_t *data) {
  u64 i;
  struct nbSound_t_array *sound;
  nbSound_t_o *v6;
  u64 *v7;
  System_String_o *v9;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v12;
  u16 id;

  for (i = 0; i != 10; ++i)
  {
    sound = data->sound;
    v6 = sound->m_Items[i];
    if (v6->exist && v6->motse_h == 1)
    {
      id = v6->id;
      v7 = sub_8D3950(ushort, &id);
      v9 = Format("M{0:X4}", v7, 0);
      asset_bc = get_asset_bc();
      if (IsLoad(asset_bc, v9))
      {
        v12 = Concat_5224608("battle/devil/", v9);
        LoadSound(v9, v12);
        v6->motse_h = 0;
      }
    }
  }
}
