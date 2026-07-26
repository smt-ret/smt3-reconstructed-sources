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
    nbGetBgmCategoryInField(0);
    nbGetBgmCategoryInBattle();
    AppendDLC(0, 0);
    IsLoad(0, 0);
    Load(0, 0);
}

// 0x1580ac0
s32 nbBgmLoadChk(void) {
    AppendDLC(0, 0);
    LoadKeysBGM1(0, 0, 0);
    IsLoad(0, 0);
    LoadBattleBGM(0, 0);
    return 0;
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
    nbFreeSound1(0, 0);
    RemoveDLC(0);
}

// 0x157ff60
void nbFreeSound1(nbMainProcessData_t *data, s32 index) {
    ReleaseSound(0);
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
    Get(0);
    return 0;
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
    nbGetMainProcessData();
    nbAddSoundTable(0);
    GetMotionMIDI(0, 0, 0);
    IsLoad(0, 0);
    Load(0, 0);
    return 0;
}

// 0x157fc70
s32 nbMemoryLoadMotionSe(nbFormation_t *form, s32 mot) {
    nbGetMainProcessData();
    nbGetMotionMIDI(0, 0);
    IsLoad(0, 0);
    return 0;
}

// 0x157f980
s32 nbMemoryLoadNegoSe(nbFormation_t *form) {
    nbGetMainProcessData();
    GetUnitID(0);
    IsLoad(0, 0);
    nbSearchSoundTable(0);
    Load(0, 0);
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
    IsLoad(0, 0);
    LoadSound(0, 0);
}
