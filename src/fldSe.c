#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct EventEMsgData EventEMsgData;
typedef struct fldSe3D_tag fldSe3D_tag;
typedef struct typeFLDAREABGMTBL typeFLDAREABGMTBL;
typedef struct typeFLDBGMTBL typeFLDBGMTBL;

static s32 DNG_MAX;
static typeFLDAREABGMTBL *gFldAreaBgm[46];
static s32 gFldBgmBit;
static s32 fldSeLastBgm;
static s32 fldSeSmgId;
static typeFLDBGMTBL *gFldBgmTop[62];
static s32 gFldSndTransSrc;
static fldSe3D_tag *gFldSe3D[8];
static s32 gFldSe3DNum;
static char *soundCmnTbl[4];
static s32 fldSe_Task_se3cnt;
static s32 fldSe_Task_xyzcnt;
static s32 fldTalkBgmPlay_nowbgm;
static s32 gFldBgmLoadId;
static s32 gFldBgmLoadPhase;
static s32 gFldBgmSisetuLoadId;
static s32 gFldBgmSisetuLoadPhase;
static s32 gFldFootSeLoadPhase;
static s32 gFldFootSeLoadIdx;
static char gFldFootSeLoadNum[UNKNOWN_ARRAY_SIZE];
static s32 gFldCmnBgmSeLoadPhase;
static s32 gFldCmnBgmSeLoadIdx;
static char gFldCmnBgmSeLoadNum[UNKNOWN_ARRAY_SIZE];
static s32 gFldCmnBgmSeLoadType[UNKNOWN_ARRAY_SIZE];
static s32 gFldEventDataLoadPhase;
static s32 gFldEventDataLoadIdx;
static char gFldEventDataLoadNum[UNKNOWN_ARRAY_SIZE];
static char gFldEventDataLoadMode[UNKNOWN_ARRAY_SIZE];

s32 DLCGetArea(s32 area);
s32 DLCGetFieldCheck(s32 no);
char *DLCGetFieldSeKey(char *key, s32 no);
void EndFKuti(void);
s32 FindId(s32 type, char *name);
s32 FindId_1916848(s32 type, s32 id);
char *GetAppendix(void);
EventEMsgData *GetData(char *key);
char **GetKeys(AssetBundleCtrl *this);
bool IsDLCField(s32 area);
bool IsFieldBGMLoaded(char *key);
bool IsLoad(AssetBundles *this, char *key);
void Load(char *key, char *filePath);
void LoadAssetExt(char *key, char *name, char *dlc);
void LoadEventData(char *key, s32 e, bool ecmnf);
void LoadEventVoice(s32 eventno, char *key, EventEMsgData *data);
void LoadFNPCVoice(char *key);
void LoadFieldBGM(char *key);
void LoadKeys(s32 type, char *key, char *path);
s32 LoadManiacsChar(bool mode, s32 phase);
void Log(char *fmt, void **parray);
void ReleaseEventData(s32 eventno);
void Remove(char *key);
void RemoveKeys(s32 type, char *key);
void RemoveOldEventField(s32 field);
bool ReplaceDLCName(char **key, char *name);
void StartFKuti(char *key, char *name);
void StopBGMALL_Compulsion(bool flg);
void UnloadAB(AssetBundleCtrl *this, char *key);
bool evtBitCheck(s32 no);
void fldBgmFadeOut(void);
s32 fldBgmIdVonv(s32 BgmId);
void fldBgmPlay(void);
s32 fldBgmSisetuLoadChk(void);
void fldCmnBgmSeLoad(void);
void fldCmnBgmSeUnload(void);
void fldEventDataLoad(void);
void fldEventDataUnload(void);
void fldFootSeLoad(void);
void fldFootSeUnload(void);
void fldRunCngBgm(s32 mode);
void fldRunDanteSetModel(void);
void p2sdBGMStopAll(void);
void p2sdContinue(s32 MidiNo);
s32 p2sdFadeOut(s32 a);
bool p2sdLoadCheckMidi_Fld(s32 MidiNo);
void p2sdMelodyTrans(s32 midiNo);
void p2sdPause(s32 MidiNo);
s32 p2sdPlayBGM(s32 a);
s32 p2sdPlaySE(s32 a);
void p2sdPlaySE_Fld(s32 MidiNo);
void p2sdPlaySE_Vol_Fld(s32 MidiNo, s32 volume);
void p2sdPlaySe3DEx(s32 MidiNo, f32 posx, f32 posy, f32 posz, s32 limit);
void p2sdSetStandPos(f32 Cposx, f32 Cposy, f32 Cposz, f32 Pposx, f32 Pposy, f32 Pposz);
void p2sdSndStop(s32 MidiNo);
void p2sdSndStop_Fld(s32 MidiNo);
f32 sdfSqrt(f32 aValue);

// 0x1602d40
void CommonBgmLoad(void) {
  s64 v2;
  u64 v4;
  AssetBundleCtrl_o *asset_bc;
  struct System_String_array *soundCmnTbl;

  v2 = 4;
  v4 = 0;
  {
  }
  while (v4 < SLODWORD(soundCmnTbl->max_length))
  {
    asset_bc = get_asset_bc();
    Load(
      asset_bc,
      *(&soundCmnTbl->obj.klass + v2),
      *(&soundCmnTbl->obj.klass + v2),
      0);
    ++v2;
    v4 = v2 - 4;
  }
}

// 0x1602ea0
bool IsCommonBgmLoaded(void) {
  u64 v2;
  AssetBundleCtrl_o *asset_bc;
  struct System_String_array *soundCmnTbl;

  v2 = 0;
  while (1)
  {
    if (v2 >= SLODWORD(soundCmnTbl->max_length))
      break;
    asset_bc = get_asset_bc();
    if (IsLoad(asset_bc, soundCmnTbl->m_Items[v2++]))
      return 1;
  }
  return 0;
}

// 0x16052a0
void RemoveOldEventField(s32 field) {
    GetKeys(0);
    IsLoad(0, 0);
    UnloadAB(0, 0);
}

// 0x15fbfa0
void ResetPhase(void) {
  gFldFootSeLoadPhase = 0;
  gFldCmnBgmSeLoadPhase = 0;
  gFldEventDataLoadPhase = 0;
}

// 0x15fed60
void fldBgmBitChk(void) {
  s32 v4;
  struct fldSe_StaticFields *static_fields;
  struct typeFLDAREABGMTBL_array *gFldAreaBgm;
  s64 fieldID;
  struct typeFLDAREABGMTBL_array *v12;
  s64 v13;

  if (fldGb->fieldID == 34)
  {
    {
      else
      {
        static_fields = fldSe->static_fields;
        if (static_fields->gFldBgmBit)
      }
    }
    else
    {
      v4 = 0;
      static_fields = fldSe->static_fields;
      if (static_fields->gFldBgmBit)
      {
        gFldAreaBgm = static_fields->gFldAreaBgm;
        fieldID = fldGb->fieldID;
        if (evtBitCheck(gFldAreaBgm->m_Items[fieldID]->flag))
          return;
        fldBgmFadeOut();
        fldBgmPlay();
        return;
      }
    }
    v12 = static_fields->gFldAreaBgm;
    v13 = fldGb->fieldID;
    if (evtBitCheck(v12->m_Items[v13]->flag))
  }
}

// 0x15fc090
void fldBgmContinue(void) {
  s32 fieldID;
  s32 v5;
  s32 BgmId;
  s32 v8;
  fldGlobal_c *v9;
  struct fldGlobal_StaticFields *static_fields;
  s32 v12;
  struct fldSe_StaticFields *v13;
  struct typeFLDBGMTBL_array *gFldBgmTop;
  s32 SmgID;
  struct fldSe_StaticFields *v18;
  struct typeFLDBGMTBL_array *v19;
  fldSe_c *v22;
  struct fldSe_StaticFields *v23;
  struct typeFLDBGMTBL_array *v24;
  struct fldGlobalWork_t_o *fldGb;
  u32 v26;
  struct fldSe_StaticFields *v28;
  struct typeFLDBGMTBL_array *v29;
  struct fldGlobalWork_t_o *v31;
  s32 areaID;
  struct typeFLDBGMTBL_array *v34;
  s32 v37;
  struct fldSe_StaticFields *v38;
  struct typeFLDBGMTBL_array *v39;
  s32 v42;
  struct typeFLDAREABGMTBL_array *gFldAreaBgm;
  s64 v45;
  bool v47;
  fldGlobal_c *v48;
  struct fldGlobal_StaticFields *v49;
  struct fldGlobalWork_t_o *v51;
  struct fldGlobalWork_t_o *v52;
  struct typeFLDAREABGMTBL_array *v53;
  s64 v54;
  struct System_SByte_array *id1;
  struct fldGlobal_StaticFields *v57;
  struct typeFLDAREABGMTBL_array *v59;
  s64 v60;
  s64 v62;
  fldSe_c *v64;
  struct fldSe_StaticFields *v65;
  struct typeFLDBGMTBL_array *v67;
  struct fldGlobalWork_t_o *v68;
  u32 v69;
  struct fldSe_StaticFields *v71;
  struct typeFLDBGMTBL_array *v72;

  fieldID = fldGb->fieldID;
  v5 = DLCGetArea(fieldID);
  BgmId = fldGb->BgmId;
  v8 = fldBgmIdVonv(BgmId);
  if (v8 == -1)
  {
    static_fields = v9->static_fields;
    v12 = static_fields->fldGb->fieldID;
    else
    {
      v13 = fldSe->static_fields;
      if (v12 >= v13->DNG_MAX)
        return;
    }
    gFldBgmTop = v13->gFldBgmTop;
    SmgID = gFldBgmTop->m_Items[v5]->SmgID;
    v8 = fldGb->BgmId + SmgID;
    v18 = fldSe->static_fields;
    v19 = v18->gFldBgmTop;
    v18->fldSeSmgId = v19->m_Items[v5]->SmgID;
    if (fldGb->fieldID == 14)
    {
      if (evtBitCheck(5))
      {
        fldGb->BgmId = 1;
      }
      v23 = v22->static_fields;
      v24 = v23->gFldBgmTop;
      v26 = fldGb->fieldID;
      v8 = fldGb->BgmId + v24->m_Items[v26]->SmgID;
      v28 = fldSe->static_fields;
      v29 = v28->gFldBgmTop;
      v28->fldSeSmgId = v29->m_Items[v26]->SmgID;
    }
    v31 = fldGb;
    if (v31->fieldID == 20)
    {
      areaID = v31->areaID;
      if (areaID == 5)
      if (areaID == 8)
      if (areaID == 13)
      if (areaID == 14)
      if (areaID == 15)
      if (areaID == 24)
      if (areaID == 12 && evtBitCheck(22))
      {
        v34 = gFldBgmTop;
        v37 = v34->m_Items[55]->SmgID;
        v8 = fldGb->BgmId + v37;
        v38 = fldSe->static_fields;
        v39 = v38->gFldBgmTop;
        v38->fldSeSmgId = v39->m_Items[55]->SmgID;
      }
    }
    v42 = fldGb->fieldID;
    if (v42 == 34)
    if (v42 == 32)
    if (v42 == 37)
    if (v42 == 36)
    if (v42 == 41)
    if (v42 == 42)
    if (v42 == 43)
    if (v42 == 44)
    if (v42 == 45)
    {
      v45 = fldGb->fieldID;
      v47 = evtBitCheck(gFldAreaBgm->m_Items[v45]->flag);
      if (v47)
      {
        v49 = v48->static_fields;
        v51 = v49->fldGb;
        else
        {
          v52 = v49->fldGb;
        }
        v53 = gFldAreaBgm;
        v54 = v52->fieldID;
        id1 = v53->m_Items[v54]->id1;
      }
      else
      {
        v57 = v48->static_fields;
        v51 = v57->fldGb;
        else
        {
          v52 = v57->fldGb;
        }
        v59 = gFldAreaBgm;
        v60 = v52->fieldID;
        id1 = v59->m_Items[v60]->id0;
      }
      v62 = v52->areaID + 1LL;
      v51->BgmId = id1->m_Items[v62];
      v65 = v64->static_fields;
      v67 = v65->gFldBgmTop;
      v68 = fldGb;
      v69 = v68->fieldID;
      v8 = v68->BgmId + v67->m_Items[v69]->SmgID;
      v71 = fldSe->static_fields;
      v72 = v71->gFldBgmTop;
      v71->fldSeSmgId = v72->m_Items[v69]->SmgID;
    }
  }
  else if (gFldStart == 1)
  {
    return;
  }
  fldSeLastBgm = v8;
  p2sdContinue(v8);
}

// 0x16039d0
void fldBgmFadeOut(void) {
  s32 fldSeLastBgm;
  struct fldGlobalWork_t_o *fldGb;

  if (fldSeLastBgm)
  {
    p2sdFadeOut(fldSeLastBgm);
    if (fldGb->BgmId >= 128)
    {
      fldGb->BgmId = 1;
    }
    fldSeLastBgm = 0;
  }
}

// 0x1603590
s32 fldBgmIdVonv(s32 BgmId) {
  s32 result;
  struct typeFLDBGMTBL_array *gFldBgmTop;
  typeFLDBGMTBL_o *v7;
  struct typeFLDBGMTBL_array *v9;
  struct typeFLDBGMTBL_array *v12;
  struct typeFLDBGMTBL_array *v15;
  typeFLDBGMTBL_o *v17;
  struct typeFLDBGMTBL_array *v19;
  struct typeFLDBGMTBL_array *v22;
  struct typeFLDBGMTBL_array *v25;
  struct typeFLDBGMTBL_array *v28;
  struct typeFLDBGMTBL_array *v31;
  struct typeFLDBGMTBL_array *v34;
  s64 *v36;

  result = 7208961;
  switch (BgmId)
  {
    case 128:
      v7 = gFldBgmTop->m_Items[50];
      return v7->SmgID + 1;
    case 129:
      v9 = gFldBgmTop;
      v7 = v9->m_Items[51];
      return v7->SmgID + 1;
    case 130:
      v12 = gFldBgmTop;
      v7 = v12->m_Items[52];
      return v7->SmgID + 1;
    case 131:
      v15 = gFldBgmTop;
      v17 = v15->m_Items[51];
      return v17->SmgID + 2;
    case 132:
      v19 = gFldBgmTop;
      v7 = v19->m_Items[53];
      return v7->SmgID + 1;
    case 133:
      v22 = gFldBgmTop;
      v17 = v22->m_Items[53];
      return v17->SmgID + 2;
    case 134:
      v25 = gFldBgmTop;
      v7 = v25->m_Items[54];
      return v7->SmgID + 1;
    case 135:
      v28 = gFldBgmTop;
      v7 = v28->m_Items[56];
      return v7->SmgID + 1;
    case 136:
      v31 = gFldBgmTop;
      v17 = v31->m_Items[56];
      return v17->SmgID + 2;
    case 137:
      v34 = gFldBgmTop;
      return v34->m_Items[56]->SmgID + 3;
    case 138:
      v36 = &StringLiteral_11911;
    case 139:
      v36 = &StringLiteral_5161;
      result = FindId(0, *v36);
      break;
    case 140:
      result = 7208960;
      break;
    case 141:
      return result;
    default:
      result = -1;
      break;
  }
  return result;
}

// 0x15fb420
void fldBgmLoad(void) {
    DLCGetArea(0);
    fldBgmIdVonv(0);
    evtBitCheck(0);
    p2sdLoadCheckMidi_Fld(0);
    LoadKeys(0, 0, 0);
}

// 0x15fc020
s32 fldBgmLoadChk(void) {
  gFldBgmLoadPhase = -1;
  return 1;
}

// 0x15fd580
void fldBgmPause(void) {
  s32 fldSeLastBgm;

  p2sdPause(fldSeLastBgm);
  fldSeLastBgm = 0;
}

// 0x15fcaf0
void fldBgmPlay(void) {
  s32 fieldID;
  s32 v5;
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v9;
  u32 v10;
  u32 areaID;
  s32 BgmId;
  s32 v14;
  struct fldSe_StaticFields *static_fields;
  struct typeFLDBGMTBL_array *gFldBgmTop;
  s32 SmgID;
  s32 v20;
  struct typeFLDBGMTBL_array *v21;
  s32 v23;
  struct typeFLDBGMTBL_array *v25;
  u32 max_length;
  struct typeFLDBGMTBL_array *v28;
  s32 fieldOldID;
  struct typeFLDBGMTBL_array *v32;
  fldSe_c *v34;
  struct fldSe_StaticFields *v35;
  struct typeFLDAREABGMTBL_array *gFldAreaBgm;
  s64 v38;
  bool v40;
  fldSe_c *v41;
  struct fldSe_StaticFields *v42;
  struct typeFLDAREABGMTBL_array *v44;
  struct fldGlobalWork_t_o *v45;
  s64 v46;
  struct System_SByte_array *id1;
  s64 v49;
  char *v51;
  s32 v52;
  struct fldSe_StaticFields *v56;
  struct typeFLDAREABGMTBL_array *v58;
  struct fldGlobalWork_t_o *v59;
  s64 v60;
  struct System_SByte_array *id0;
  s64 v63;
  fldSe_c *v65;
  struct fldSe_StaticFields *v66;
  struct typeFLDBGMTBL_array *v68;
  u32 v69;
  struct typeFLDBGMTBL_array *v71;
  struct fldTest_StaticFields *v75;
  u64 v78;

  fieldID = fldGb->fieldID;
  v5 = DLCGetArea(fieldID);
  StopBGMALL_Compulsion(0);
  if (fldGb->fieldID == 20)
  {
    else if (fldGb->areaID == 2)
    {
      return;
    }
  }
  v9 = fldGb;
  v10 = v9->fieldID;
  areaID = v9->areaID;
  BgmId = v9->BgmId;
  v14 = fldBgmIdVonv(BgmId);
  static_fields = fldSe->static_fields;
  if (v10 < static_fields->DNG_MAX)
  {
    gFldBgmTop = static_fields->gFldBgmTop;
    SmgID = gFldBgmTop->m_Items[v5]->SmgID;
    v20 = fldGb->BgmId + SmgID;
    v21 = gFldBgmTop;
    v23 = v21->m_Items[v5]->SmgID;
    if (v10 == 20)
    {
      if (areaID <= 0x18 && (((1 << areaID) & 0x100E120) != 0 || areaID == 12 && evtBitCheck(22)))
      {
        v28 = gFldBgmTop;
        v20 = v28->m_Items[55]->SmgID + BgmId;
        v23 = v28->m_Items[55]->SmgID;
      }
    }
    else if (v10 == 14)
    {
      if (evtBitCheck(5))
      {
        v25 = gFldBgmTop;
        max_length = v25->max_length;
        v20 = v25->m_Items[v5]->SmgID + 1;
        v23 = v25->m_Items[v5]->SmgID;
        BgmId = 1;
      }
    }
    else if (v10 == 35 && areaID == 9)
    {
      if (evtBitCheck(68) && evtBitCheck(87) && !evtBitCheck(63))
      {
        fieldOldID = fldGb->fieldOldID;
        if (fieldOldID != 5)
        {
          if (fieldOldID != 35)
          {
            v32 = gFldBgmTop;
            v14 = v32->m_Items[51]->SmgID + 1;
          }
        }
      }
    }
    else if (v10 <= 0x2D && ((1LL << v10) & 0x3E3500000000LL) != 0)
    {
      v35 = v34->static_fields;
      gFldAreaBgm = v35->gFldAreaBgm;
      v38 = fldGb->fieldID;
      v40 = evtBitCheck(gFldAreaBgm->m_Items[v38]->flag);
      if (v40)
      {
        v42 = v41->static_fields;
        v44 = v42->gFldAreaBgm;
        v45 = fldGb;
        v46 = v45->fieldID;
        id1 = v44->m_Items[v46]->id1;
        v49 = v45->areaID + 1LL;
        v51 = &id1->m_Items[v49];
        v52 = 1;
      }
      else
      {
        v56 = v41->static_fields;
        v58 = v56->gFldAreaBgm;
        v59 = fldGb;
        v60 = v59->fieldID;
        id0 = v58->m_Items[v60]->id0;
        v63 = v59->areaID + 1LL;
        v52 = 0;
        v51 = &id0->m_Items[v63];
      }
      BgmId = *v51;
      gFldBgmBit = v52;
      v66 = v65->static_fields;
      v68 = v66->gFldBgmTop;
      v69 = fldGb->fieldID;
      v20 = v68->m_Items[v69]->SmgID + BgmId;
      v71 = gFldBgmTop;
      v23 = v71->m_Items[v69]->SmgID;
      if (v10 == 43)
      {
        fldRunCngBgm(SuspendData->bgm_mode);
        fldSeSmgId = v23;
        v75 = fldTest->static_fields;
        if (v75->bSuspendBGM)
        {
          v75->bSuspendBGM = 0;
          return;
        }
      }
    }
    if (v14 == -1)
      v14 = v20;
    fldSeSmgId = v23;
  }
  else if (gFldStart == 1)
  {
    return;
  }
  fldGb->BgmId = BgmId;
  if (*(*(v78 + 184) + 20LL) != v14)
  {
    if ((*(v78 + 295) & 2) != 0 && !*(v78 + 216))
    fldBgmFadeOut(v78);
  }
  *(*(v78 + 184) + 20LL) = v14;
  p2sdPlayBGM(v14);
}

// 0x15fd460
void fldBgmPlay2(void) {
  s32 BgmId;
  u32 *data;
  s32 v7;

  BgmId = fldGb->BgmId;
  if (BgmId == 128)
  {
    data = v4[2].klass->_1.byval_arg.data;
    v7 = *(*(data + 54) + 16LL);
    p2sdPlayBGM(v7 + 1);
  }
  else
  {
    fldBgmPlay();
  }
}

// 0x15f8770
s32 fldBgmSisetuGetStatus(void) {
  return gFldBgmSisetuLoadPhase != -1;
}

// 0x1604c70
void fldBgmSisetuLoad(s32 id) {
  fldSe_c *v3;
  struct fldSe_StaticFields *static_fields;
  s32 v5;

  else
  {
    static_fields = fldSe->static_fields;
    if (static_fields->gFldBgmSisetuLoadPhase != -1)
      return;
  }
  switch (id)
  {
    case 0:
      v5 = 3211264;
      if ((v3->_2.bitflags2 & 2) != 0)
    case 1:
      v5 = 3735552;
    case 2:
      return;
    case 3:
    case 4:
      v5 = 0x20000;
    case 5:
      v5 = 3145728;
      static_fields->gFldBgmSisetuLoadId = v5;
      break;
    default:
      break;
  }
  gFldBgmSisetuLoadPhase = 0;
  fldBgmSisetuLoadChk(v3);
}

// 0x15f87e0
s32 fldBgmSisetuLoadChk(void) {
    return 0;
}

// 0x1603da0
void fldBgmStop(void) {
  s32 fldSeLastBgm;

  p2sdSndStop(fldSeLastBgm);
  fldGb->BgmId = 0;
}

// 0x1603d30
void fldBgmStopAll(void) {
    p2sdBGMStopAll();
}

// 0x1603b20
void fldBgmTrans(void) {
  s32 fieldID;
  s32 BgmId;
  s32 v7;
  fldGlobal_c *v8;
  struct fldGlobal_StaticFields *static_fields;
  s32 v11;
  struct fldSe_StaticFields *v12;
  struct typeFLDBGMTBL_array *gFldBgmTop;
  struct fldGlobalWork_t_o *fldGb;
  s64 v16;

  fieldID = fldGb->fieldID;
  DLCGetArea(fieldID);
  BgmId = fldGb->BgmId;
  v7 = fldBgmIdVonv(BgmId);
  if (v7 == -1)
  {
    static_fields = v8->static_fields;
    v11 = static_fields->fldGb->fieldID;
    else
    {
      v12 = fldSe->static_fields;
      if (v11 >= v12->DNG_MAX)
        return;
    }
    gFldBgmTop = v12->gFldBgmTop;
    v16 = fldGb->fieldID;
    v7 = fldGb->BgmId + gFldBgmTop->m_Items[v16]->SmgID;
  }
  p2sdMelodyTrans(v7);
}

// 0x1603b10
s32 fldBgmTransChk(s32 id1, s32 id2) {
  return 0;
}

// 0x1605f00
void fldCmnBgmSeLoad(void) {
    Log(0, 0);
    evtBitCheck(0);
}

// 0x15fa9b0
s32 fldCmnBgmSeLoadChk(void) {
    Log(0, 0);
    fldCmnBgmSeLoad();
    IsLoad(0, 0);
    Load(0, 0);
    LoadFieldBGM(0);
    IsFieldBGMLoaded(0);
    LoadKeys(0, 0, 0);
    LoadFNPCVoice(0);
    GetData(0);
    LoadEventVoice(0, 0, 0);
    IsDLCField(0);
    LoadAssetExt(0, 0, 0);
    ReleaseEventData(0);
    return 0;
}

// 0x15fda20
void fldCmnBgmSeUnload(void) {
    ReplaceDLCName(0, 0);
    UnloadAB(0, 0);
    RemoveKeys(0, 0);
}

// 0x1606a60
void fldEventDataLoad(void) {
    IsDLCField(0);
    DLCGetFieldSeKey(0, 0);
    GetAppendix();
}

// 0x15f96e0
s32 fldEventDataLoadChk(void) {
    Log(0, 0);
    fldEventDataLoad();
    IsLoad(0, 0);
    LoadAssetExt(0, 0, 0);
    DLCGetFieldCheck(0);
    LoadEventData(0, 0, 0);
    StartFKuti(0, 0);
    IsDLCField(0);
    LoadManiacsChar(0, 0);
    fldRunDanteSetModel();
    return 0;
}

// 0x15fd620
void fldEventDataUnload(void) {
  fldSe_c *v2;
  s64 v3;
  u64 v4;
  AssetBundleCtrl_o *asset_bc;
  struct System_String_array *gFldEventDataLoadNum;
  struct System_String_array *v11;
  System_String_o *v13;

  if (gFldEventDataLoadNum)
  {
    v3 = 4;
    v4 = 0;
    if ((v2->_2.bitflags2 & 2) == 0)
    while (v4 < SLODWORD(gFldEventDataLoadNum->max_length))
    {
      asset_bc = get_asset_bc();
      UnloadAB(asset_bc, *(&gFldEventDataLoadNum->obj.klass + v3), 0);
      v11 = gFldEventDataLoadNum;
      v13 = *(&v11->obj.klass + v3);
      Remove(v13, 0);
      v4 = ++v3 - 4;
    }
    EndFKuti();
  }
  gFldEventDataLoadPhase = 0;
  gFldEventDataLoadNum = 0;
  gFldEventDataLoadMode = 0;
  gFldEventDataLoadIdx = 0;
}

// 0x1605a90
void fldFootSeLoad(void) {
  u64 *v1;
  u32 fieldID;
  s64 *v7;
  mdlEffectResrcItem_t_o *v8;
  const MethodInfo_1260 *v9;
  u32 Count;
  struct System_String_array *v13;
  u64 v16;
  u32 *gFldFootSeLoadNum;
  s64 *Item;
  s64 *v21;
  u32 *v23;

  v1 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v1);
  fieldID = fldGb->fieldID;
  _Clear(v1);
  if (fieldID - 11 <= 0x58)
    _Add(v1, StringLiteral_16735);
  switch (fieldID)
  {
    case 0xCu:
    case 0xDu:
    case 0x14u:
    case 0x16u:
    case 0x18u:
    case 0x19u:
    case 0x21u:
    case 0x22u:
    case 0x23u:
      _Add(v1, StringLiteral_16736);
      switch (fieldID)
      {
        case 0xDu:
        case 0xEu:
        case 0x14u:
          _Add(v1, StringLiteral_16737);
          if (fieldID - 18 < 2)
          if (fieldID != 15)
          _Add(v1, StringLiteral_16738);
          v8 = StringLiteral_16739;
          v9 = Method_System_Collections_Generic_List_string__Add__;
          break;
        case 0xFu:
        case 0x1Bu:
        case 0x1Fu:
        case 0x12u:
        case 0x13u:
        case 0x17u:
        case 0x1Cu:
        case 0x1Eu:
        case 0x15u:
        case 0x1Au:
        case 0x1Du:
        case 0x18u:
        case 0x20u:
        default:
      }
    case 0xEu:
      v7 = &StringLiteral_16737;
    case 0xFu:
    case 0x1Bu:
    case 0x1Fu:
    case 0x3Cu:
      _Add(v1, StringLiteral_16738);
      switch (fieldID)
      {
        case 0xFu:
        case 0x18u:
        case 0x3Cu:
          _Add(v1, StringLiteral_16739);
          if (fieldID > 0x25)
          if (((1LL << fieldID) & 0x508C0000) != 0)
          if (((1LL << fieldID) & 0x24200000) != 0)
          if (((1LL << fieldID) & 0x3100000000LL) != 0)
        case 0x12u:
        case 0x13u:
        case 0x17u:
        case 0x1Cu:
        case 0x1Eu:
        case 0x15u:
        case 0x1Au:
        case 0x1Du:
        case 0x20u:
        case 0x24u:
        case 0x25u:
        default:
      }
    case 0x12u:
    case 0x13u:
    case 0x17u:
    case 0x1Cu:
    case 0x1Eu:
      _Add(v1, StringLiteral_16740);
      if (fieldID <= 0x1D && ((1 << fieldID) & 0x24200000) != 0)
    case 0x15u:
    case 0x1Au:
    case 0x1Du:
      v7 = &StringLiteral_16741;
    case 0x20u:
    case 0x24u:
    case 0x25u:
      _Add(v1, StringLiteral_16742);
      if ((fieldID & 0xFFFFFFFE) != 0xC)
    default:
      if (fieldID - 40 <= 5)
      {
        v7 = &StringLiteral_16743;
        v8 = *v7;
        v9 = Method_System_Collections_Generic_List_string__Add__;
        _Add(v1, v8, v9);
      }
      gFldFootSeLoadPhase = 0;
      gFldFootSeLoadIdx = 0;
      gFldFootSeLoadNum = 0;
      if (_get_Count(v1))
      {
        Count = _get_Count(v1);
        v13 = NewSpecific(string, Count);
        gFldFootSeLoadNum = v13;
        if (_get_Count(v1) >= 1)
        {
          v16 = 0;
          do
          {
            Item = _get_Item(
                     v1,
                     v16);
            v21 = Item;
            v23 = &gFldFootSeLoadNum[2 * v16++];
            *(v23 + 4) = v21;
          }
          while (v16 < _get_Count(v1));
        }
      }
      return;
  }
}

// 0x15fa410
s32 fldFootSeLoadChk(void) {
    Log(0, 0);
    IsLoad(0, 0);
    fldFootSeLoad();
    LoadKeys(0, 0, 0);
    Load(0, 0);
    return 0;
}

// 0x15fd830
void fldFootSeUnload(void) {
  fldSe_c *v2;
  s64 v3;
  u64 v4;
  AssetBundleCtrl_o *asset_bc;
  struct System_String_array *gFldFootSeLoadNum;
  struct System_String_array *v11;
  System_String_o *v13;

  else  v3 = 4;
  v4 = 0;
  if ((v2->_2.bitflags2 & 2) == 0)
  while (v4 < SLODWORD(gFldFootSeLoadNum->max_length))
  {
    asset_bc = get_asset_bc();
    UnloadAB(asset_bc, *(&gFldFootSeLoadNum->obj.klass + v3), 0);
    v11 = gFldFootSeLoadNum;
    v13 = *(&v11->obj.klass + v3);
    RemoveKeys(3, v13);
    v4 = ++v3 - 4;
  }
  gFldFootSeLoadNum = 0;
  gFldFootSeLoadPhase = 0;
  gFldFootSeLoadNum = 0;
  gFldFootSeLoadIdx = 0;
}

// 0x1604b50
void fldMotionSePlay(s32 seid, s32 subid) {
  s32 v5;

  if (seid)
    v5 = (seid << 16) + 150994944 + subid;
  else
    v5 = 151060480;
  p2sdPlaySE(v5);
}

// 0x1604be0
void fldMotionSeStop(s32 seid, s32 subid) {
  s32 v5;

  if (seid)
    v5 = (seid << 16) + 150994944 + subid;
  else
    v5 = 151060480;
  p2sdSndStop(v5);
}

// 0x1604dd0
void fldPlay3DSe(s32 id, f32 r, f32 x, f32 y, f32 z) {

}

// 0x1603e70
void fldSePlay(s32 seid) {
  struct fldGlobalWork_t_o *fldGb;
  fldSe_c *v5;
  s32 fieldID;
  struct fldSe_StaticFields *static_fields;
  s32 v8;
  s32 v10;
  struct fldGlobalWork_t_o *v11;
  s32 areaID;
  struct typeFLDBGMTBL_array *gFldBgmTop;

  fieldID = fldGb->fieldID;
  else if (seid < 16)
  {
    return;
  }
  static_fields = v5->static_fields;
  if (fieldID < static_fields->DNG_MAX)
  {
    switch (seid)
    {
      case 128:
        v8 = 6684768;
        break;
      case 129:
        v8 = 6684769;
        break;
      case 130:
        v8 = 6684772;
        break;
      case 131:
        v8 = 7208961;
        break;
      default:
        v10 = static_fields->fldSeSmgId + seid;
        v11 = fldGb;
        if (v11->fieldID == 20)
        {
          areaID = v11->areaID;
          if (areaID == 5)
          if (areaID == 8)
          if (areaID == 13)
          if (areaID == 14)
          if (areaID == 15)
          if (areaID == 24)
          if (areaID == 12 && evtBitCheck(22))
          {
            v10 = gFldBgmTop->m_Items[55]->SmgID + seid;
          }
        }
        v8 = v10;
        break;
    }
    p2sdPlaySE_Fld(v8);
  }
}

// 0x1604230
void fldSeStop(s32 seid) {
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  struct fldSe_StaticFields *static_fields;
  s32 v8;
  s32 v10;
  struct fldGlobalWork_t_o *v11;
  s32 areaID;
  struct typeFLDBGMTBL_array *gFldBgmTop;

  fieldID = fldGb->fieldID;
  else
  {
    static_fields = fldSe->static_fields;
    if (fieldID >= static_fields->DNG_MAX)
      return;
  }
  switch (seid)
  {
    case 258:
      v8 = 6684772;
      break;
    case 257:
      v8 = 6684769;
      break;
    case 256:
      v8 = 6684768;
      break;
    default:
      v10 = static_fields->fldSeSmgId + seid;
      v11 = fldGb;
      if (v11->fieldID == 20)
      {
        areaID = v11->areaID;
        if (areaID == 5)
        if (areaID == 8)
        if (areaID == 13)
        if (areaID == 14)
        if (areaID == 15)
        if (areaID == 24)
        if (areaID == 12 && evtBitCheck(22))
        {
          v10 = gFldBgmTop->m_Items[55]->SmgID + seid;
        }
      }
      v8 = v10;
      break;
  }
  p2sdSndStop_Fld(v8);
}

// 0x16045b0
void fldSeVol(s32 seid, s32 vol) {
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  struct fldSe_StaticFields *static_fields;
  s32 fldSeSmgId;
  s32 v12;
  struct fldGlobalWork_t_o *v13;
  s32 areaID;
  struct typeFLDBGMTBL_array *gFldBgmTop;
  s32 Id_1916848;

  fieldID = fldGb->fieldID;
  else
  {
    static_fields = fldSe->static_fields;
    if (fieldID >= static_fields->DNG_MAX)
      return;
  }
  fldSeSmgId = static_fields->fldSeSmgId;
  if ((seid - 32) <= 0x19)
    fldSeSmgId = 0x400000;
  v12 = fldSeSmgId + seid;
  v13 = fldGb;
  if (v13->fieldID == 20)
  {
    else
    {
      areaID = v13->areaID;
      if (areaID != 5)
      {
        if (areaID != 8)
        {
          if (areaID != 13)
          {
            if (areaID != 14)
            {
              if (areaID != 15)
              {
                if (areaID != 24)
                {
                  if (areaID != 12 || !evtBitCheck(22))
                }
              }
            }
          }
        }
      }
    }
    v12 = gFldBgmTop->m_Items[55]->SmgID + seid;
  }
  Id_1916848 = FindId_1916848(1, v12);
  p2sdPlaySE_Vol_Fld(Id_1916848, vol);
}

// 0x1603190
void fldSe_Add(s32 id, f32 r, f32 x, f32 y, f32 z) {
  fldSe_c *v11;
  struct fldSe_StaticFields *static_fields;
  struct fldSe3D_tag_array *gFldSe3D;
  s64 gFldSe3DNum;
  struct fldSe3D_tag_array *v16;
  struct fldSe3D_tag_array *v18;
  struct fldSe3D_tag_array *v20;
  struct fldSe3D_tag_array *v22;
  struct fldSe3D_tag_array *v24;

  static_fields = v11->static_fields;
  gFldSe3D = static_fields->gFldSe3D;
  gFldSe3DNum = static_fields->gFldSe3DNum;
  gFldSe3D->m_Items[gFldSe3DNum]->flg = 0;
  v16 = gFldSe3D;
  v16->m_Items[gFldSe3DNum]->id = id;
  v18 = gFldSe3D;
  v18->m_Items[gFldSe3DNum]->r = r;
  v20 = gFldSe3D;
  v20->m_Items[gFldSe3DNum]->x = x;
  v22 = gFldSe3D;
  v22->m_Items[gFldSe3DNum]->y = y;
  v24 = gFldSe3D;
  v24->m_Items[gFldSe3DNum]->z = z;
  ++gFldSe3DNum;
}

// 0x1602fc0
void fldSe_Init(void) {
  fldSe_c *v2;
  s64 v3;
  s32 v4;
  u64 v6;
  u32 *gFldSe3D;
  u64 *v8;
  struct fldSe3D_tag_array *v10;
  struct fldSe3D_tag_array *v12;
  struct fldSe3D_tag_array *v14;
  u32 v16;

  v3 = 4;
  do
  {
    v6 = v3 - 4;
    v8 = Allocate(fldSe3D_tag);
    _ctor(v8, 0);
    *&gFldSe3D[2 * v3] = v8;
    v10 = gFldSe3D;
    *(*(&v10->obj.klass + v3) + 16LL) = 0;
    v12 = gFldSe3D;
    *(*(&v12->obj.klass + v3) + 24LL) = 0;
    v14 = gFldSe3D;
    *(*(&v14->obj.klass + v3) + 20LL) = 0;
    v16 = *&v2->_2.bitflags1;
    ++v3;
    v4 = (v16 >> 9) & 1;
  }
  while (v3 != 12);
  gFldSe3DNum = 0;
}

// 0x1603370
void fldSe_Kill(void) {
    p2sdSndStop_Fld(0);
}

// 0x15fe190
void fldSe_Task(void) {
    sdfSqrt(0);
    p2sdSetStandPos(0, 0, 0, 0, 0, 0);
    p2sdSndStop_Fld(0);
    p2sdPlaySe3DEx(0, 0, 0, 0, 0);
}

// 0x16048f0
void fldTalkBgmPlay(s32 id) {
  s32 fldTalkBgmPlay_nowbgm;
  s32 v6;
  struct typeFLDBGMTBL_array *gFldBgmTop;
  typeFLDBGMTBL_o *v10;
  struct typeFLDBGMTBL_array *v12;
  s32 v14;

  switch (id)
  {
    case -1:
      if (fldTalkBgmPlay_nowbgm != -1)
      {
        p2sdSndStop(fldTalkBgmPlay_nowbgm);
      }
      break;
    case 0:
      v6 = fldTalkBgmPlay_nowbgm;
      if (v6 != -1)
      {
        p2sdFadeOut(v6);
        fldTalkBgmPlay_nowbgm = -1;
      }
      break;
    case 1:
      v10 = gFldBgmTop->m_Items[50];
    case 2:
      v12 = gFldBgmTop;
      v10 = v12->m_Items[14];
      v14 = v10->SmgID + 1;
      p2sdPlayBGM(v14);
      fldTalkBgmPlay_nowbgm = v14;
      break;
    default:
      return;
  }
}

// 0x1604e90
void fldUnloadAll(s32 field, s32 area) {
    RemoveKeys(0, 0);
    UnloadAB(0, 0);
    fldEventDataUnload();
    fldFootSeUnload();
    fldCmnBgmSeUnload();
    RemoveOldEventField(0);
}
