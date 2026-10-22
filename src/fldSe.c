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
static char *gFldFootSeLoadNum;
static s32 gFldCmnBgmSeLoadPhase;
static s32 gFldCmnBgmSeLoadIdx;
static char *gFldCmnBgmSeLoadNum;
static s32 *gFldCmnBgmSeLoadType;
static s32 gFldEventDataLoadPhase;
static s32 gFldEventDataLoadIdx;
static char *gFldEventDataLoadNum;
static char *gFldEventDataLoadMode;

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
LABEL_6:
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
      goto LABEL_6;
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
  AssetBundleCtrl_o *asset_bc;
  System_String_array *Keys;
  s64 max_length;
  System_String_array *v6;
  u64 v7;
  Il2CppClass **v15;
  System_String_o *v16;
  System_String_o **v17;
  System_String_o *v18;
  s32 v19;
  System_String_o *v20;
  System_Object_array *v21;
  s64 *v24;
  s64 *v25;
  s64 *v28;
  s64 *v29;
  Il2CppObject *v32;
  u8 v33;
  s32 v34;
  System_String_o *v35;
  System_Object_array *v36;
  s64 *v39;
  s64 *v40;
  s64 *v43;
  s64 *v44;
  Il2CppObject *v47;
  Il2CppObject *v50;
  AssetBundleCtrl_o *v53;
  AssetBundleCtrl_o *v56;
  u32 v58;
  s32 v59;
  s32 v60;
  s32 result;

  result = 0;
  asset_bc = get_asset_bc();
  Keys = GetKeys(asset_bc);
  if (Keys->max_length >= 1)
  {
    max_length = Keys->max_length;
    v6 = Keys;
    v7 = 0;
    v58 = field - 41;
    while (1)
    {
      v15 = &v6->obj.klass + v7;
      v18 = v15[4];
      v17 = (v15 + 4);
      v16 = v18;
      if (get_Length(v18) < 4)
        goto LABEL_92;
      if (get_Chars(v16, 0) == 102 || (v19 = 0, get_Chars(v16, 0) == 70))
      {
        v20 = Substring_5248048(v16, 1, 3);
        if (!TryParse(v20, &result, 0))
          goto LABEL_44;
        v21 = NewSpecific(object, 4u);
        v21->m_Items[0] = "field = ";
        v60 = field;
        v24 = sub_8D3950(s32, &v60);
        v25 = v24;
        v21->m_Items[1] = v25;
        v21->m_Items[2] = " = ";
        v59 = result;
        v28 = sub_8D3950(s32, &v59);
        v29 = v28;
        v21->m_Items[3] = v29;
        v32 = Concat_5270224(v21);
        Log(v32, 0);
        if (result != field)
        {
          v33 = (field == 61 && result == 16) ^ (field != 60 || result != 15);
          if ((field | 2) == 0x1E)
            v33 &= result != 18;
          v19 = (v58 > 4 || result != 40) & v33;
        }
        else
        {
LABEL_44:
          v19 = 0;
        }
      }
      if (get_Chars(v16, 0) == 101 || (v34 = v19 != 0, get_Chars(v16, 0) == 69))
      {
        v35 = Substring_5248048(v16, 1, 3);
        v34 = v19 != 0;
        if (TryParse(v35, &result, 0))
        {
          v36 = NewSpecific(object, 4u);
          v36->m_Items[0] = "field = ";
          v60 = field;
          v39 = sub_8D3950(s32, &v60);
          v40 = v39;
          v36->m_Items[1] = v40;
          v36->m_Items[2] = " = ";
          v59 = result;
          v43 = sub_8D3950(s32, &v59);
          v44 = v43;
          v36->m_Items[3] = v44;
          v47 = Concat_5270224(v36);
          Log(v47, 0);
          if (result != field)
          {
            v34 = (field == 61 && result == 16) ^ (field != 60 || result != 15);
            if ((field | 2) == 0x1E)
            {
              if (((result != 18) & v34) == 0)
                goto LABEL_92;
              goto LABEL_73;
            }
            if (v58 <= 4)
            {
              if (((result != 40) & v34) == 0)
                goto LABEL_92;
              goto LABEL_73;
            }
          }
        }
      }
      if (!v34)
        goto LABEL_92;
LABEL_73:
      v50 = Concat_5221536("!!!!![[[[[ RemoveALL : ", *v17, " ]]]]]!!!!!");
      Log(v50, 0);
      {
LABEL_79:
        goto LABEL_82;
      }
      while (1)
      {
LABEL_82:
        v53 = get_asset_bc();
        if (!IsLoad(v53, *v17))
          break;
        v56 = get_asset_bc();
        UnloadAB(v56, *v17);
          goto LABEL_79;
      }
LABEL_92:
      if (++v7 == max_length)
        return;
    }
  }
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
  struct typeFLDAREABGMTBL_array *gFldAreaBgm;
  s64 fieldID;
  struct typeFLDAREABGMTBL_array *v12;
  s64 v13;

  if (fldGb->fieldID == 34)
  {
    {
      else
      {
        if (gFldBgmBit)
          goto LABEL_9;
      }
    }
    else
    {
      v4 = 0;
      if (gFldBgmBit)
      {
LABEL_9:
        fieldID = fldGb->fieldID;
        if (evtBitCheck(gFldAreaBgm->m_Items[fieldID]->flag))
          return;
LABEL_30:
        fldBgmFadeOut();
        fldBgmPlay();
        return;
      }
    }
    v12 = gFldAreaBgm;
    v13 = fldGb->fieldID;
    if (evtBitCheck(v12->m_Items[v13]->flag))
      goto LABEL_30;
  }
}

// 0x15fc090
void fldBgmContinue(void) {
  s32 fieldID;
  s32 v5;
  s32 BgmId;
  s32 v8;
  s32 v12;
  struct typeFLDBGMTBL_array *gFldBgmTop;
  s32 SmgID;
  struct typeFLDBGMTBL_array *v19;
  struct typeFLDBGMTBL_array *v24;
  struct fldGlobalWork_t_o *fldGb;
  u32 v26;
  struct typeFLDBGMTBL_array *v29;
  struct fldGlobalWork_t_o *v31;
  s32 areaID;
  struct typeFLDBGMTBL_array *v34;
  s32 v37;
  struct typeFLDBGMTBL_array *v39;
  s32 v42;
  struct typeFLDAREABGMTBL_array *gFldAreaBgm;
  s64 v45;
  bool v47;
  struct fldGlobalWork_t_o *v51;
  struct fldGlobalWork_t_o *v52;
  struct typeFLDAREABGMTBL_array *v53;
  s64 v54;
  struct System_SByte_array *id1;
  struct typeFLDAREABGMTBL_array *v59;
  s64 v60;
  s64 v62;
  struct typeFLDBGMTBL_array *v67;
  struct fldGlobalWork_t_o *v68;
  u32 v69;
  struct typeFLDBGMTBL_array *v72;

  fieldID = fldGb->fieldID;
  v5 = DLCGetArea(fieldID);
  BgmId = fldGb->BgmId;
  v8 = fldBgmIdVonv(BgmId);
  if (v8 == -1)
  {
    v12 = fldGb->fieldID;
    else
    {
      if (v12 >= DNG_MAX)
        return;
    }
    SmgID = gFldBgmTop->m_Items[v5]->SmgID;
    v8 = fldGb->BgmId + SmgID;
    v19 = gFldBgmTop;
    fldSeSmgId = v19->m_Items[v5]->SmgID;
    if (fldGb->fieldID == 14)
    {
      if (evtBitCheck(5))
      {
        fldGb->BgmId = 1;
      }
      v24 = gFldBgmTop;
      v26 = fldGb->fieldID;
      v8 = fldGb->BgmId + v24->m_Items[v26]->SmgID;
      v29 = gFldBgmTop;
      fldSeSmgId = v29->m_Items[v26]->SmgID;
    }
    v31 = fldGb;
    if (v31->fieldID == 20)
    {
      areaID = v31->areaID;
      if (areaID == 5)
        goto LABEL_77;
      if (areaID == 8)
        goto LABEL_77;
      if (areaID == 13)
        goto LABEL_77;
      if (areaID == 14)
        goto LABEL_77;
      if (areaID == 15)
        goto LABEL_77;
      if (areaID == 24)
        goto LABEL_77;
      if (areaID == 12 && evtBitCheck(22))
      {
LABEL_77:
        v34 = gFldBgmTop;
        v37 = v34->m_Items[55]->SmgID;
        v8 = fldGb->BgmId + v37;
        v39 = gFldBgmTop;
        fldSeSmgId = v39->m_Items[55]->SmgID;
      }
    }
    v42 = fldGb->fieldID;
    if (v42 == 34)
      goto LABEL_124;
    if (v42 == 32)
      goto LABEL_124;
    if (v42 == 37)
      goto LABEL_124;
    if (v42 == 36)
      goto LABEL_124;
    if (v42 == 41)
      goto LABEL_124;
    if (v42 == 42)
      goto LABEL_124;
    if (v42 == 43)
      goto LABEL_124;
    if (v42 == 44)
      goto LABEL_124;
    if (v42 == 45)
    {
LABEL_124:
      v45 = fldGb->fieldID;
      v47 = evtBitCheck(gFldAreaBgm->m_Items[v45]->flag);
      if (v47)
      {
        v51 = fldGb;
        else
        {
          v52 = fldGb;
        }
        v53 = gFldAreaBgm;
        v54 = v52->fieldID;
        id1 = v53->m_Items[v54]->id1;
      }
      else
      {
        v51 = fldGb;
        else
        {
          v52 = fldGb;
        }
        v59 = gFldAreaBgm;
        v60 = v52->fieldID;
        id1 = v59->m_Items[v60]->id0;
      }
      v62 = v52->areaID + 1LL;
      v51->BgmId = id1->m_Items[v62];
      v67 = gFldBgmTop;
      v68 = fldGb;
      v69 = v68->fieldID;
      v8 = v68->BgmId + v67->m_Items[v69]->SmgID;
      v72 = gFldBgmTop;
      fldSeSmgId = v72->m_Items[v69]->SmgID;
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
      v36 = &"F060_01";
      goto LABEL_75;
    case 139:
      v36 = &"F061_01";
LABEL_75:
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
  s32 fieldID;
  s32 v5;
  struct fldGlobalWork_t_o *fldGb;
  s32 BgmId;
  s32 v10;
  s32 v14;
  struct typeFLDBGMTBL_array *gFldBgmTop;
  s32 SmgID;
  struct typeFLDBGMTBL_array *v21;
  struct typeFLDBGMTBL_array *v26;
  struct fldGlobalWork_t_o *v27;
  u32 v28;
  struct typeFLDBGMTBL_array *v31;
  struct fldGlobalWork_t_o *v33;
  s32 areaID;
  struct typeFLDBGMTBL_array *v36;
  s32 v39;
  struct typeFLDBGMTBL_array *v41;
  s32 v44;
  struct typeFLDAREABGMTBL_array *gFldAreaBgm;
  s64 v47;
  bool v49;
  struct fldGlobalWork_t_o *v53;
  struct fldGlobalWork_t_o *v54;
  struct typeFLDAREABGMTBL_array *v55;
  s64 v56;
  struct System_SByte_array *id1;
  s64 v59;
  char *v61;
  s32 v62;
  struct fldGlobalWork_t_o *v65;
  struct typeFLDAREABGMTBL_array *v66;
  s64 v67;
  struct System_SByte_array *id0;
  s64 v70;
  struct typeFLDBGMTBL_array *v75;
  struct fldGlobalWork_t_o *v76;
  u32 v77;
  struct typeFLDBGMTBL_array *v80;
  s32 v85;
  s32 v86;
  u64 *v87;
  System_String_o *v88;
  System_String_o *v90;
  System_String_o *v91;
  s32 v92;

  fieldID = fldGb->fieldID;
  v5 = DLCGetArea(fieldID);
  if (fldGb->fieldID != 20)
    goto LABEL_203;
  if (fldGb->areaID != 2)
  {
LABEL_203:
    BgmId = fldGb->BgmId;
    v10 = fldBgmIdVonv(BgmId);
    if (v10 != -1)
      goto LABEL_172;
    v14 = fldGb->fieldID;
    if (v14 < DNG_MAX)
    {
      SmgID = gFldBgmTop->m_Items[v5]->SmgID;
      v10 = fldGb->BgmId + SmgID;
      v21 = gFldBgmTop;
      fldSeSmgId = v21->m_Items[v5]->SmgID;
      if (fldGb->fieldID == 14)
      {
        if (evtBitCheck(5))
        {
          fldGb->BgmId = 1;
        }
        v26 = gFldBgmTop;
        v27 = fldGb;
        v28 = v27->fieldID;
        v10 = v27->BgmId + v26->m_Items[v28]->SmgID;
        v31 = gFldBgmTop;
        fldSeSmgId = v31->m_Items[v28]->SmgID;
      }
      v33 = fldGb;
      if (v33->fieldID == 20)
      {
        areaID = v33->areaID;
        if (areaID == 5)
          goto LABEL_83;
        if (areaID == 8)
          goto LABEL_83;
        if (areaID == 13)
          goto LABEL_83;
        if (areaID == 14)
          goto LABEL_83;
        if (areaID == 15)
          goto LABEL_83;
        if (areaID == 24)
          goto LABEL_83;
        if (areaID == 12 && evtBitCheck(22))
        {
LABEL_83:
          v36 = gFldBgmTop;
          v39 = v36->m_Items[55]->SmgID;
          v10 = fldGb->BgmId + v39;
          v41 = gFldBgmTop;
          fldSeSmgId = v41->m_Items[55]->SmgID;
        }
      }
      v44 = fldGb->fieldID;
      if (v44 == 34)
        goto LABEL_130;
      if (v44 == 32)
        goto LABEL_130;
      if (v44 == 37)
        goto LABEL_130;
      if (v44 == 36)
        goto LABEL_130;
      if (v44 == 41)
        goto LABEL_130;
      if (v44 == 42)
        goto LABEL_130;
      if (v44 == 43)
        goto LABEL_130;
      if (v44 == 44)
        goto LABEL_130;
      if (v44 == 45)
      {
LABEL_130:
        v47 = fldGb->fieldID;
        v49 = evtBitCheck(gFldAreaBgm->m_Items[v47]->flag);
        if (v49)
        {
          v53 = fldGb;
          else
          {
            v54 = fldGb;
          }
          v55 = gFldAreaBgm;
          v56 = v54->fieldID;
          id1 = v55->m_Items[v56]->id1;
          v59 = v54->areaID + 1LL;
          v61 = &id1->m_Items[v59];
          v62 = 1;
        }
        else
        {
          v53 = fldGb;
          else
          {
            v65 = fldGb;
          }
          v66 = gFldAreaBgm;
          v67 = v65->fieldID;
          id0 = v66->m_Items[v67]->id0;
          v70 = v65->areaID + 1LL;
          v62 = 0;
          v61 = &id0->m_Items[v70];
        }
        v53->BgmId = *v61;
        gFldBgmBit = v62;
        v75 = gFldBgmTop;
        v76 = fldGb;
        v77 = v76->fieldID;
        v10 = v76->BgmId + v75->m_Items[v77]->SmgID;
        v80 = gFldBgmTop;
        fldSeSmgId = v80->m_Items[v77]->SmgID;
      }
LABEL_172:
      gFldBgmLoadId = v10;
      gFldBgmLoadPhase = 0;
      if (!p2sdLoadCheckMidi_Fld(v10))
      {
        v85 = fldGb->fieldID;
        v92 = DLCGetArea(v85);
        v86 = v92;
        v87 = sub_8D3950(s32, &v92);
        v88 = Format("e{0:D3}", v87, 0);
        v90 = v88;
        if ((v86 - 2) <= 6)
          v91 = "fldbgm";
        else
          v91 = v88;
        {
        }
        LoadKeys(1, v91, 0);
        LoadKeys(3, v90, 0);
      }
    }
  }
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
  struct typeFLDAREABGMTBL_array *gFldAreaBgm;
  s64 v38;
  bool v40;
  struct typeFLDAREABGMTBL_array *v44;
  struct fldGlobalWork_t_o *v45;
  s64 v46;
  struct System_SByte_array *id1;
  s64 v49;
  char *v51;
  s32 v52;
  struct typeFLDAREABGMTBL_array *v58;
  struct fldGlobalWork_t_o *v59;
  s64 v60;
  struct System_SByte_array *id0;
  s64 v63;
  struct typeFLDBGMTBL_array *v68;
  u32 v69;
  struct typeFLDBGMTBL_array *v71;
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
  if (v10 < DNG_MAX)
  {
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
      v38 = fldGb->fieldID;
      v40 = evtBitCheck(gFldAreaBgm->m_Items[v38]->flag);
      if (v40)
      {
        v44 = gFldAreaBgm;
        v45 = fldGb;
        v46 = v45->fieldID;
        id1 = v44->m_Items[v46]->id1;
        v49 = v45->areaID + 1LL;
        v51 = &id1->m_Items[v49];
        v52 = 1;
      }
      else
      {
        v58 = gFldAreaBgm;
        v59 = fldGb;
        v60 = v59->fieldID;
        id0 = v58->m_Items[v60]->id0;
        v63 = v59->areaID + 1LL;
        v52 = 0;
        v51 = &id0->m_Items[v63];
      }
      BgmId = *v51;
      gFldBgmBit = v52;
      v68 = gFldBgmTop;
      v69 = fldGb->fieldID;
      v20 = v68->m_Items[v69]->SmgID + BgmId;
      v71 = gFldBgmTop;
      v23 = v71->m_Items[v69]->SmgID;
      if (v10 == 43)
      {
        fldRunCngBgm(SuspendData->bgm_mode);
        fldSeSmgId = v23;
        if (bSuspendBGM)
        {
          bSuspendBGM = 0;
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
  s32 v5;

  else
  {
    if (gFldBgmSisetuLoadPhase != -1)
      return;
  }
  switch (id)
  {
    case 0:
      v5 = 3211264;
      if ((v3->_2.bitflags2 & 2) != 0)
        goto LABEL_16;
      goto LABEL_22;
    case 1:
      v5 = 3735552;
      if ((v3->_2.bitflags2 & 2) != 0)
      {
LABEL_16:
      }
      goto LABEL_22;
    case 2:
      return;
    case 3:
    case 4:
      v5 = 0x20000;
      goto LABEL_22;
    case 5:
      v5 = 3145728;
LABEL_22:
      gFldBgmSisetuLoadId = v5;
      break;
    default:
      break;
  }
  gFldBgmSisetuLoadPhase = 0;
  fldBgmSisetuLoadChk(v3);
}

// 0x15f87e0
s32 fldBgmSisetuLoadChk(void) {
  s32 gFldBgmSisetuLoadPhase;

  if (gFldBgmSisetuLoadPhase == 1)
    goto LABEL_15;
LABEL_6:
  if (!gFldBgmSisetuLoadPhase)
  {
LABEL_18:
    ++gFldBgmSisetuLoadPhase;
    return 0;
  }
  gFldBgmSisetuLoadPhase = -1;
  return 1;
}

// 0x1603da0
void fldBgmStop(void) {
  s32 fldSeLastBgm;

  p2sdSndStop(fldSeLastBgm);
  fldGb->BgmId = 0;
}

// 0x1603d30
void fldBgmStopAll(void) {
  else
  {
    p2sdBGMStopAll();
  }
}

// 0x1603b20
void fldBgmTrans(void) {
  s32 fieldID;
  s32 BgmId;
  s32 v7;
  s32 v11;
  struct typeFLDBGMTBL_array *gFldBgmTop;
  struct fldGlobalWork_t_o *fldGb;
  s64 v16;

  fieldID = fldGb->fieldID;
  DLCGetArea(fieldID);
  BgmId = fldGb->BgmId;
  v7 = fldBgmIdVonv(BgmId);
  if (v7 == -1)
  {
    v11 = fldGb->fieldID;
    else
    {
      if (v11 >= DNG_MAX)
        return;
    }
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
  u64 *v1;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  System_Array_o *v7;
  System_Object_array *v8;
  s64 *v10;
  s64 *v11;
  s32 v13;
  s64 *v15;
  s64 *v16;
  System_String_o *v19;
  System_Object_array *v21;
  const MethodInfo_1260 *v23;
  const MethodInfo_1260 *v29;
  const MethodInfo_1260 *v30;
  void *monitor;
  u64 v32;
  u64 *v34;
  System_String_o *v35;
  u32 Count;
  struct System_String_array *v39;
  u32 v41;
  u64 v43;
  u32 *gFldCmnBgmSeLoadNum;
  s64 *v47;
  s64 *v48;
  struct System_Int32_array *gFldCmnBgmSeLoadType;
  s32 v51;
  char *v53;
  System_Collections_Generic_KeyValuePair_string__int__o v54;
  System_Collections_Generic_KeyValuePair_string__int__o v55;
  System_Collections_Generic_KeyValuePair_string__int__o v56;
  System_Collections_Generic_KeyValuePair_object__int__o Item;
  System_Collections_Generic_KeyValuePair_string__int__o v58;
  System_Collections_Generic_KeyValuePair_string__int__o v59;
  System_Collections_Generic_KeyValuePair_string__int__o v60;

  Item.key = 0;
  *&Item.value = 0;
  v1 = Allocate(System_Collections_Generic_List_KeyValuePair_string__int);
  int_____ctor(
    v1);
  fieldID = fldGb->fieldID;
  areaID = fldGb->areaID;
  v7 = NewSpecific(s32, 0x2Bu);
  InitializeArray_1543888(v7, Field__PrivateImplementationDetails__E629859A8E87309669BB83C497305E54DAB2DE05);
  int____Clear(v1);
  v8 = NewSpecific(object, 5u);
  v8->m_Items[0] = "!!!!!fldCmnBgmSeLoad : ";
  LODWORD(v56.key) = fieldID;
  v10 = sub_8D3950(s32, &v56);
  v11 = v10;
  v8->m_Items[1] = v11;
  v13 = areaID + 1;
  v8->m_Items[2] = " / ";
  LODWORD(v55.key) = v13;
  v15 = sub_8D3950(s32, &v55);
  v16 = v15;
  v8->m_Items[3] = v16;
  v8->m_Items[4] = " !!!!!";
  v19 = Concat_5270224(v8);
  v21 = Empty_string_();
  Log(v19, v21, 0);
  if ((fieldID - 2) <= 6)
  {
    v56.key = 0;
    *&v56.value = 0;
    sub_1A0C2D0(&v56, "fldbgm", 1);
    int____Add(v1, v56);
  }
  switch (fieldID)
  {
    case 28:
    case 30:
      v56.key = 0;
      *&v56.value = 0;
      sub_1A0C2D0(&v56, "e018", 1);
      int____Add(v1, v56);
      v55.key = 0;
      *&v55.value = 0;
      sub_1A0C2D0(&v55, "e018", 3);
      v58 = v55;
      v23 = Method_System_Collections_Generic_List_KeyValuePair_string__int___Add__;
      goto LABEL_42;
    case 60:
      v56.key = 0;
      *&v56.value = 0;
      sub_1A0C2D0(&v56, "e015", 3);
      int____Add(v1, v56);
      if (!evtBitCheck(964))
        goto LABEL_49;
      v56.key = 0;
      *&v56.value = 0;
      sub_1A0C2D0(&v56, "vmane", 5);
      v59 = v56;
      v29 = Method_System_Collections_Generic_List_KeyValuePair_string__int___Add__;
      break;
    case 61:
      v56.key = 0;
      *&v56.value = 0;
      sub_1A0C2D0(&v56, "e016", 3);
      int____Add(v1, v56);
      if (!evtBitCheck(964))
        goto LABEL_49;
      v56.key = 0;
      *&v56.value = 0;
      sub_1A0C2D0(&v56, "e711", 5);
      int____Add(v1, v56);
      v55.key = 0;
      *&v55.value = 0;
      sub_1A0C2D0(&v55, "e714", 5);
      int____Add(v1, v55);
      v54.key = 0;
      *&v54.value = 0;
      sub_1A0C2D0(&v54, "e715", 5);
      v59 = v54;
      v29 = Method_System_Collections_Generic_List_KeyValuePair_string__int___Add__;
      break;
    default:
      if ((fieldID - 41) <= 4)
      {
        if ((fieldID | 2) == 0x2B)
        {
          v56.key = 0;
          *&v56.value = 0;
          sub_1A0C2D0(&v56, "b_bgm11", 1);
          int____Add(v1, v56);
        }
        v56.key = 0;
        *&v56.value = 0;
        sub_1A0C2D0(&v56, "e040", 1);
        v58 = v56;
        v23 = Method_System_Collections_Generic_List_KeyValuePair_string__int___Add__;
LABEL_42:
        int____Add(v1, v58, v23);
      }
      switch (fieldID)
      {
        case 15:
        case 16:
        case 45:
          goto LABEL_49;
        case 18:
        case 28:
        case 30:
LABEL_50:
          v56.key = 0;
          *&v56.value = 0;
          sub_1A0C2D0(&v56, "v0x101", 5);
          int____Add(v1, v56);
          switch (fieldID)
          {
            case 19:
              goto LABEL_55;
            case 22:
            case 27:
              goto LABEL_51;
            case 23:
            case 25:
              goto LABEL_53;
            default:
              goto LABEL_57;
          }
          goto LABEL_57;
        case 19:
LABEL_55:
          v56.key = 0;
          *&v56.value = 0;
          sub_1A0C2D0(&v56, "v0x71", 5);
          int____Add(v1, v56);
          v56.key = 0;
          *&v56.value = 0;
          sub_1A0C2D0(&v56, "v0x73", 5);
          v60 = v56;
          v30 = Method_System_Collections_Generic_List_KeyValuePair_string__int___Add__;
          goto LABEL_56;
        case 22:
        case 27:
        case 37:
LABEL_51:
          v56.key = 0;
          *&v56.value = 0;
          sub_1A0C2D0(&v56, "vmane", 5);
          int____Add(v1, v56);
          if (fieldID == 25 || fieldID == 23)
            goto LABEL_53;
          goto LABEL_57;
        case 23:
        case 25:
LABEL_53:
          v56.key = 0;
          *&v56.value = 0;
          sub_1A0C2D0(&v56, "v0x3c", 5);
          int____Add(v1, v56);
          if (fieldID == 25)
            goto LABEL_54;
          goto LABEL_57;
        case 43:
LABEL_54:
          v56.key = 0;
          *&v56.value = 0;
          sub_1A0C2D0(&v56, "v0xce", 5);
          v60 = v56;
          v30 = Method_System_Collections_Generic_List_KeyValuePair_string__int___Add__;
LABEL_56:
          int____Add(v1, v60, v30);
          break;
        default:
          goto LABEL_57;
      }
      goto LABEL_57;
  }
  int____Add(v1, v59, v29);
LABEL_49:
  v56.key = 0;
  *&v56.value = 0;
  sub_1A0C2D0(&v56, "v0x3d", 5);
  int____Add(v1, v56);
  switch (fieldID)
  {
    case 18:
    case 28:
    case 30:
      goto LABEL_50;
    case 19:
      goto LABEL_55;
    case 22:
    case 27:
    case 37:
      goto LABEL_51;
    case 23:
    case 25:
      goto LABEL_53;
    case 43:
      goto LABEL_54;
    default:
      break;
  }
LABEL_57:
  monitor = v7[1].monitor;
  if (monitor >= 1)
  {
    v32 = 0;
    do
    {
      while (1)
      {
        if (fieldID == *(&v7[2].klass + v32))
          break;
        LODWORD(monitor) = v7[1].monitor;
        if (++v32 >= monitor)
          goto LABEL_65;
      }
      LODWORD(v55.key) = fieldID;
      v34 = sub_8D3950(s32, &v55);
      v35 = Format("e{0:D3}", v34, 0);
      v56.key = 0;
      *&v56.value = 0;
      sub_1A0C2D0(&v56, v35, 3);
      int____Add(v1, v56);
      LODWORD(monitor) = v7[1].monitor;
      ++v32;
    }
    while (v32 < monitor);
  }
LABEL_65:
  gFldCmnBgmSeLoadPhase = 0;
  gFldCmnBgmSeLoadIdx = 0;
  gFldCmnBgmSeLoadNum = 0;
  gFldCmnBgmSeLoadType = 0;
  if (int____get_Count(v1))
  {
    Count = int____get_Count(v1);
    v39 = NewSpecific(string, Count);
    gFldCmnBgmSeLoadNum = v39;
    v41 = int____get_Count(v1);
    gFldCmnBgmSeLoadType = NewSpecific(s32, v41);
    if (int____get_Count(v1) >= 1)
    {
      v43 = 0;
      do
      {
        Item = int____get_Item(v1, v43);
        v47 = sub_1A0C2F0(&Item);
        v48 = v47;
        *&gFldCmnBgmSeLoadNum[2 * v43 + 8] = v48;
        Item = int____get_Item(v1, v43);
        v51 = sub_1A0C310(&Item);
        v53 = gFldCmnBgmSeLoadType + 4 * v43++;
        *(v53 + 8) = v51;
      }
      while (v43 < int____get_Count(v1));
    }
  }
}

// 0x15fa9b0
s32 fldCmnBgmSeLoadChk(void) {
  s32 v4;
  s32 fieldID;
  System_String_o *v8;
  System_Object_array *v10;
  u64 v12;
  System_String_o *v13;
  System_Object_array *v15;
  struct System_String_array *gFldCmnBgmSeLoadNum;
  s32 gFldCmnBgmSeLoadIdx;
  u32 max_length;
  s32 v23;
  struct System_String_array *v24;
  s64 v25;
  System_String_o *v27;
  struct System_Int32_array *gFldCmnBgmSeLoadType;
  s64 v33;
  s32 v35;
  System_String_o *v36;
  System_String_o *v37;
  s32 v39;
  u64 *v40;
  System_String_o *v42;
  EventEMsgData_o *Data;
  s32 v45;
  AssetBundleCtrl_o *v47;
  System_String_o *v48;
  System_String_o *v50;
  System_String_o *v52;
  struct System_String_array *v54;
  s64 v55;
  AssetBundleCtrl_o *v58;
  struct System_Int32_array *v62;
  s64 v63;
  s32 v65;
  System_String_o *v66;
  s32 Length;
  System_String_o *v69;
  s32 v70;
  u64 *v71;
  System_String_o *v73;
  EventEMsgData_o *v75;
  AssetBundleCtrl_o *v77;
  System_String_o *v78;
  bool v79;
  s32 v82;
  System_String_o *v85;
  Il2CppObject *v88;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v91;
  s32 v93;
  s32 eventno;
  s32 result;

  result = 0;
  eventno = 0;
  v4 = 1;
  switch (gFldCmnBgmSeLoadPhase)
  {
    case 0:
      fieldID = fldGb->fieldID;
      if (fieldID < 1)
        return 0;
      if (fieldID > 61)
        return 0;
      v8 = Concat_5269984("@@@@@ Init fldCmnBgmSeLoadChk : ", &gFldCmnBgmSeLoadNum->obj, " @@@@@");
      v10 = Empty_string_();
      Log(v8, v10, 0);
      if (!gFldCmnBgmSeLoadNum)
      {
        fldCmnBgmSeLoad(v12);
      }
      v13 = Concat_5269984("@@@@@ Init fldCmnBgmSeLoadChkA : ", *(*(v12 + 184) + 128LL), " @@@@@", 0);
      v15 = Empty_string_();
      Log(v13, v15, 0);
      if (!gFldCmnBgmSeLoadNum)
        goto LABEL_163;
      max_length = gFldCmnBgmSeLoadNum->max_length;
      if (gFldCmnBgmSeLoadIdx == max_length)
      {
LABEL_163:
        v23 = 3;
        goto LABEL_159;
      }
      v85 = gFldCmnBgmSeLoadNum->m_Items[gFldCmnBgmSeLoadIdx];
      if (!Equals_5234480(v85, "fldbgm"))
      {
        v88 = Concat_5224608("LoadStart : ", v85);
        Log(v88, 0);
        asset_bc = get_asset_bc();
        if (!IsLoad(asset_bc, v85))
        {
          v91 = get_asset_bc();
          Load(v91, v85, v85, 0);
        }
        goto LABEL_155;
      }
      LoadFieldBGM(v85);
        goto LABEL_156;
      goto LABEL_158;
    case 1:
      v24 = gFldCmnBgmSeLoadNum;
      v25 = gFldCmnBgmSeLoadIdx;
      v27 = v24->m_Items[v25];
      if (Equals_5234480(v27, "fldbgm"))
      {
        if (IsFieldBGMLoaded(v27))
          goto LABEL_51;
        return 0;
      }
      v77 = get_asset_bc();
      if (!IsLoad(v77, v27))
        return 0;
LABEL_51:
      v33 = gFldCmnBgmSeLoadIdx;
      v35 = gFldCmnBgmSeLoadType->m_Items[v33];
      LoadKeys(v35, v27, 0);
      v36 = Substring_5248048(v27, 0, 1);
      if (!op_Equality(v36, "e", 0))
      {
        v78 = Substring_5248048(v27, 0, 1);
        v79 = op_Equality(v78, "v", 0);
        if (v79)
        {
          {
          }
          LoadFNPCVoice(v27);
            goto LABEL_126;
          goto LABEL_124;
        }
        {
LABEL_108:
        }
LABEL_122:
        LoadKeys(4, v27, 0);
LABEL_123:
        {
LABEL_126:
          ++gFldCmnBgmSeLoadIdx;
          if (gFldCmnBgmSeLoadIdx >= SLODWORD(gFldCmnBgmSeLoadNum->max_length))
            v82 = 3;
          else
            v82 = 0;
          v4 = 0;
          gFldCmnBgmSeLoadPhase = v82;
          return v4;
        }
LABEL_124:
        goto LABEL_126;
      }
      result = -1;
      v37 = Substring(v27, 1);
      if (TryParse(v37, &result, 0))
      {
        v39 = result;
        v93 = result;
        v40 = sub_8D3950(s32, &v93);
        v42 = Format("e{0:D3}", v40, 0);
        Data = GetData(v27, 0);
        {
        }
        LoadEventVoice(v39, v42, Data);
      }
      v45 = result;
      if (!IsDLCField(v45))
        goto LABEL_123;
      v47 = get_asset_bc();
      v48 = Concat_5224608(v27, "m");
      if (IsLoad(v47, v48))
      {
LABEL_155:
          goto LABEL_158;
        goto LABEL_156;
      }
      v50 = Concat_5224608(v27, "m");
      v52 = Concat_5224608(v27, "m");
      LoadAssetExt(v50, v52, "m");
      {
LABEL_156:
      }
LABEL_158:
      v23 = gFldCmnBgmSeLoadPhase + 1;
LABEL_159:
      v4 = 0;
      gFldCmnBgmSeLoadPhase = v23;
      return v4;
    case 2:
      v54 = gFldCmnBgmSeLoadNum;
      v55 = gFldCmnBgmSeLoadIdx;
      v27 = Concat_5224608(v54->m_Items[v55], "m");
      v58 = get_asset_bc();
      if (!IsLoad(v58, v27))
        return 0;
      v62 = gFldCmnBgmSeLoadType;
      v63 = gFldCmnBgmSeLoadIdx;
      v65 = v62->m_Items[v63];
      LoadKeys(v65, v27, 0);
      v66 = Substring_5248048(v27, 0, 1);
      if (op_Equality(v66, "e", 0))
      {
        eventno = -1;
        Length = get_Length(v27);
        v69 = Substring_5248048(v27, 1, Length - 2);
        if (TryParse(v69, &eventno, 0))
        {
          v70 = eventno;
          v93 = eventno;
          v71 = sub_8D3950(s32, &v93);
          v73 = Format("e{0:D3}m", v71, 0);
          v75 = GetData(v27, 0);
          {
          }
          LoadEventVoice(v70, v73, v75);
          ReleaseEventData(eventno);
        }
      }
        goto LABEL_108;
      goto LABEL_122;
    case 3:
      return v4;
    default:
      return 0;
  }
}

// 0x15fda20
void fldCmnBgmSeUnload(void) {
  fldSe_c *v2;
  u64 v3;
  struct System_String_array *gFldCmnBgmSeLoadNum;
  u64 max_length_low;
  System_String_o *v7;
  AssetBundleCtrl_o *asset_bc;
  struct System_Int32_array *gFldCmnBgmSeLoadType;
  struct System_String_array *v13;
  s32 v14;
  System_String_o *v16;
  System_String_o *key;

  key = 0;
  else if (!gFldCmnBgmSeLoadNum)
  {
    goto LABEL_29;
  }
  v3 = 0;
  if ((v2->_2.bitflags2 & 2) == 0)
    goto LABEL_11;
LABEL_9:
LABEL_11:
  while (1)
  {
    max_length_low = LODWORD(gFldCmnBgmSeLoadNum->max_length);
    if (v3 >= max_length_low)
      break;
    else if (v3 >= max_length_low)
    {
      goto LABEL_15;
    }
    v7 = gFldCmnBgmSeLoadNum->m_Items[v3];
    key = v7;
    ReplaceDLCName(&key, v7);
    asset_bc = get_asset_bc();
    UnloadAB(asset_bc, key);
    v13 = gFldCmnBgmSeLoadNum;
    v14 = gFldCmnBgmSeLoadType->m_Items[v3];
    v16 = v13->m_Items[v3];
    RemoveKeys(v14, v16);
    ++v3;
      goto LABEL_9;
  }
LABEL_29:
  gFldCmnBgmSeLoadPhase = 0;
  gFldCmnBgmSeLoadNum = 0;
  gFldCmnBgmSeLoadType = 0;
  gFldCmnBgmSeLoadIdx = 0;
}

// 0x1606a60
void fldEventDataLoad(void) {
  u64 *v3;
  s32 fieldID;
  _BOOL4 IsDLCField;
  u64 *v8;
  System_String_o *v9;
  s64 *v10;
  System_String_o *v12;
  s64 *v13;
  u64 v14;
  struct System_String_array *v16;
  struct System_String_array *v18;
  struct System_String_array *gFldEventDataLoadNum;
  struct System_String_array *gFldEventDataLoadMode;
  s64 v24;
  struct System_String_array *v29;
  System_String_o *Appendix;
  s64 *v31;
  s64 *v33;
  struct System_String_array *v35;
  System_String_o *v36;
  struct System_String_array *v43;
  u64 *v44;
  s64 *v45;
  s64 *v46;
  struct System_String_array *v49;
  struct System_String_array *v51;
  u64 *v52;
  System_String_o *v54;
  System_String_o *v55;
  s64 *v56;
  s64 *v57;
  struct System_String_array *v59;
  s32 v63;
  s32 v64;
  s32 v65;

  gFldEventDataLoadPhase = 0;
  gFldEventDataLoadIdx = 0;
  v3 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v3);
  fieldID = fldGb->fieldID;
  v65 = fieldID;
  IsDLCField = IsDLCField(fieldID);
  v8 = sub_8D3950(s32, &v65);
  v9 = Format("e{0:D3}", v8, 0);
  v10 = &"";
  if (IsDLCField)
    v10 = &"m";
  v12 = Concat_5224608(v9, *v10);
  v13 = DLCGetFieldSeKey(v12, fieldID);
  if (IsDLCField)
    v14 = 4;
  else
    v14 = 2;
  v16 = NewSpecific(string, v14);
  gFldEventDataLoadNum = v16;
  v18 = NewSpecific(string, v14);
  gFldEventDataLoadMode = v18;
  gFldEventDataLoadNum->m_Items[0] = v13;
  if (IsDLCField)
    v24 = "m";
  else
    v24 = 0;
  if ("m"
    && IsDLCField
    && !QueryInterface("m", gFldEventDataLoadMode->obj.klass->_1.element_class))
  {
  }
  gFldEventDataLoadMode->m_Items[0] = v24;
  v29 = gFldEventDataLoadNum;
  Appendix = GetAppendix();
  v31 = Concat_5224608(v13, Appendix);
  v33 = v31;
  v29->m_Items[1] = v33;
  v35 = gFldEventDataLoadMode;
  v36 = v35->m_Items[0];
  v35->m_Items[1] = v36;
  if (!IsDLCField)
  {
      goto LABEL_79;
    goto LABEL_55;
  }
  v43 = gFldEventDataLoadNum;
  v64 = fieldID;
  v44 = sub_8D3950(s32, &v64);
  v45 = Format("e{0:D3}", v44, 0);
  v46 = v45;
  v43->m_Items[2] = v46;
  v49 = gFldEventDataLoadMode;
  v49->m_Items[2] = 0;
  v51 = gFldEventDataLoadNum;
  v63 = fieldID;
  v52 = sub_8D3950(s32, &v63);
  v54 = Format("e{0:D3}", v52, 0);
  v55 = GetAppendix();
  v56 = Concat_5224608(v54, v55);
  v57 = v56;
  v51->m_Items[3] = v57;
  v59 = gFldEventDataLoadMode;
  v59->m_Items[3] = 0;
  {
LABEL_55:
  }
LABEL_79:
  gFldEventDataLoadPhase = 0;
  gFldEventDataLoadIdx = 0;
}

// 0x15f96e0
s32 fldEventDataLoadChk(void) {
  u64 *v3;
  System_String_o *v4;
  System_Object_array *v6;
  s32 v10;
  bool v12;
  s32 v14;
  s32 v15;
  UnityEngine_Object_o *gameObject;
  fldSe_c *v23;
  s32 fieldID;
  u64 v26;
  struct fldSe_StaticFields *v27;
  struct System_String_array *gFldEventDataLoadNum;
  s32 gFldEventDataLoadIdx;
  u32 max_length;
  struct fldSe_StaticFields *v31;
  s32 v32;
  struct System_String_array *v33;
  s64 v34;
  System_String_o *v36;
  AssetBundleCtrl_o *v37;
  System_String_o *v38;
  s32 v40;
  System_String_o *v41;
  u64 *v42;
  System_String_o *v43;
  System_String_o *v44;
  System_String_o *v46;
  System_Object_array *v48;
  struct System_String_array *v51;
  s64 v52;
  System_String_o *v54;
  System_String_o *v55;
  s32 v57;
  System_String_o *v58;
  u64 *v59;
  System_String_o *v60;
  AssetBundleCtrl_o *v61;
  System_String_o *v62;
  System_Object_array *v64;
  s32 v65;
  u64 *v68;
  System_String_o *v69;
  System_String_o *v71;
  u64 *v72;
  System_String_o *v73;
  System_Object_array *v75;
  s32 v76;
  bool IsDLCField;
  s32 v80;
  s32 ManiacsChar;
  System_Object_array *v83;
  UnityEngine_Object_o *v87;
  s32 v89;
  s32 v93;
  System_String_o *v96;
  System_String_o *v97;
  System_Object_array *v99;
  AssetBundleCtrl_o *asset_bc;
  struct System_String_array *gFldEventDataLoadMode;
  s64 v106;
  System_String_o *v108;
  s32 v111;
  s32 gFldEventDataLoadPhase;
  s32 no;
  s32 result;

  result = 0;
  no = 0;
  v3 = sub_8D3950(s32, &gFldEventDataLoadPhase);
  v4 = Concat("fldEventDataLoadChk : ", v3);
  v6 = Empty_string_();
  Log(v4, v6, 0);
  switch (gFldEventDataLoadPhase)
  {
    case 0:
      fieldID = fldGb->fieldID;
      if (fieldID < 1)
        return 0;
      if (fieldID > 61)
        return 0;
      if (!*(*(v26 + 184) + 152LL))
      {
        fldEventDataLoad(v26);
      }
      v27 = *(v26 + 184);
      if (!gFldEventDataLoadNum)
        goto LABEL_203;
      max_length = gFldEventDataLoadNum->max_length;
      if (gFldEventDataLoadIdx != max_length)
      {
        if ((*(v26 + 295) & 2) != 0 && !*(v26 + 216))
        {
          max_length = gFldEventDataLoadNum->max_length;
        }
        v96 = gFldEventDataLoadNum->m_Items[gFldEventDataLoadIdx];
        v97 = Concat_5221536("@@@ fldEventDataLoadChk0 : ", v96, " @@@");
        v99 = Empty_string_();
        Log(v97, v99, 0);
        asset_bc = get_asset_bc();
        if (!IsLoad(asset_bc, v96))
        {
          v106 = gFldEventDataLoadIdx;
          v108 = gFldEventDataLoadMode->m_Items[v106];
          LoadAssetExt(v96, v96, v108);
        }
        v32 = gFldEventDataLoadPhase + 1;
      }
      else
      {
LABEL_203:
        v31 = *(v26 + 184);
        v32 = 3;
      }
      goto LABEL_198;
    case 1:
      v33 = gFldEventDataLoadNum;
      v34 = gFldEventDataLoadIdx;
      v36 = v33->m_Items[v34];
      v37 = get_asset_bc();
      if (!IsLoad(v37, v36))
        return 0;
      result = -1;
      v38 = Substring_5248048(v36, 1, 3);
      if (!TryParse(v38, &result, 0))
        goto LABEL_163;
      v40 = result;
      result = DLCGetFieldCheck(v40);
      v41 = Remove(v36, 1, 3, 0);
      gFldEventDataLoadPhase = result;
      v42 = sub_8D3950(s32, &gFldEventDataLoadPhase);
      v43 = Format("{0:D3}", v42, 0);
      v44 = Insert(v41, 1, v43, 0);
      if (op_Inequality(v44, v36, 0))
      {
        LoadAssetExt(v44, v44, "");
        v46 = Concat_5221536("@@@ fldEventDataLoadChk1 : ", v36, " @@@");
        v48 = Empty_string_();
        Log(v46, v48, 0);
        v32 = 2;
LABEL_198:
        v89 = 0;
        gFldEventDataLoadPhase = v32;
      }
      else
      {
        v65 = result;
        {
LABEL_160:
        }
LABEL_162:
        LoadEventData(v36, v36, v65, 0, 0);
LABEL_163:
        ++gFldEventDataLoadIdx;
        if (gFldEventDataLoadIdx >= SLODWORD(gFldEventDataLoadNum->max_length))
          v93 = 3;
        else
          v93 = 0;
        v89 = 0;
        gFldEventDataLoadPhase = v93;
      }
      return v89;
    case 2:
      v51 = gFldEventDataLoadNum;
      v52 = gFldEventDataLoadIdx;
      v54 = v51->m_Items[v52];
      no = -1;
      v55 = Substring_5248048(v54, 1, 3);
      if (!TryParse(v55, &no, 0))
        return 0;
      v57 = no;
      no = DLCGetFieldCheck(v57);
      v58 = Remove(v54, 1, 3, 0);
      gFldEventDataLoadPhase = no;
      v59 = sub_8D3950(s32, &gFldEventDataLoadPhase);
      v60 = Format("{0:D3}", v59, 0);
      v36 = Insert(v58, 1, v60, 0);
      v61 = get_asset_bc();
      if (!IsLoad(v61, v36))
        return 0;
      v62 = Concat_5221536("@@@ fldEventDataLoadChk2 : ", v36, " @@@");
      v64 = Empty_string_();
      Log(v62, v64, 0);
      v65 = no;
        goto LABEL_162;
      goto LABEL_160;
    case 3:
      gFldEventDataLoadPhase = fldGb->fieldID;
      v68 = sub_8D3950(s32, &gFldEventDataLoadPhase);
      v69 = Format("f{0:D3}", v68, 0);
      v71 = Concat_5224608(v69, "kuti.bytes");
      StartFKuti(v69, v71);
      v111 = fldGb->fieldID;
      v72 = sub_8D3950(s32, &v111);
      v73 = Concat_5269984("@@@ fldEventDataLoadChk3 : ", v72, " @@@");
      v75 = Empty_string_();
      Log(v73, v75, 0);
      if (fldGb->fieldID != 43)
      {
        gFldEventDataLoadPhase = 6;
        if ((v23->_2.bitflags2 & 2) == 0)
          return gFldEventDataLoadPhase == 6;
LABEL_42:
        return gFldEventDataLoadPhase == 6;
      }
      else
      {
        v76 = 43;
      }
      IsDLCField = IsDLCField(v76);
      v80 = gFldEventDataLoadPhase;
      ManiacsChar = LoadManiacsChar(IsDLCField, v80 - 3);
      gFldEventDataLoadPhase = ManiacsChar;
      if ((v23->_2.bitflags2 & 2) != 0)
        goto LABEL_42;
      return gFldEventDataLoadPhase == 6;
    case 4:
    case 5:
      v10 = fldGb->fieldID;
      v12 = IsDLCField(v10);
      v14 = gFldEventDataLoadPhase;
      v15 = LoadManiacsChar(v12, v14 - 3);
      gFldEventDataLoadPhase = v15;
      if (gFldEventDataLoadPhase == 6)
      {
        if (player3)
        {
          fldRunDanteSetModel();
          gameObject = player3->gameObject;
          if (op_Equality(gameObject, 0, 0))
          {
            gFldEventDataLoadPhase = 7;
          }
        }
      }
        goto LABEL_42;
      return gFldEventDataLoadPhase == 6;
    case 6:
      return 1;
    case 7:
      v83 = Empty_string_();
      Log("fldSeLoad 7 : GameObject Wait", v83, 0);
      fldRunDanteSetModel();
      v87 = player3->gameObject;
      if (op_Equality(v87, 0, 0))
        return 0;
      gFldEventDataLoadPhase = 6;
      return 1;
    default:
      return 0;
  }
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
      goto LABEL_12;
LABEL_10:
LABEL_12:
    while (v4 < SLODWORD(gFldEventDataLoadNum->max_length))
    {
      asset_bc = get_asset_bc();
      UnloadAB(asset_bc, *(&gFldEventDataLoadNum->obj.klass + v3), 0);
      v11 = gFldEventDataLoadNum;
      v13 = *(&v11->obj.klass + v3);
      Remove(v13, 0);
      v4 = ++v3 - 4;
        goto LABEL_10;
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
    _Add(v1, "footse_cmn");
  switch (fieldID)
  {
    case 0xCu:
      goto LABEL_23;
    case 0xDu:
    case 0x14u:
    case 0x16u:
    case 0x18u:
    case 0x19u:
    case 0x21u:
    case 0x22u:
    case 0x23u:
      _Add(v1, "footse_p00");
      switch (fieldID)
      {
        case 0xDu:
          goto LABEL_23;
        case 0xEu:
        case 0x14u:
          _Add(v1, "footse_p01");
          if (fieldID - 18 < 2)
            goto LABEL_11;
          if (fieldID != 15)
            goto LABEL_26;
          _Add(v1, "footse_p02");
LABEL_49:
          v8 = "footse_p03";
          v9 = Method_System_Collections_Generic_List_string__Add__;
          break;
        case 0xFu:
        case 0x1Bu:
        case 0x1Fu:
          goto LABEL_10;
        case 0x12u:
        case 0x13u:
        case 0x17u:
        case 0x1Cu:
        case 0x1Eu:
          goto LABEL_11;
        case 0x15u:
        case 0x1Au:
        case 0x1Du:
          goto LABEL_15;
        case 0x18u:
          goto LABEL_49;
        case 0x20u:
          goto LABEL_20;
        default:
          goto LABEL_26;
      }
      goto LABEL_25;
    case 0xEu:
      v7 = &"footse_p01";
      goto LABEL_24;
    case 0xFu:
    case 0x1Bu:
    case 0x1Fu:
    case 0x3Cu:
LABEL_10:
      _Add(v1, "footse_p02");
      switch (fieldID)
      {
        case 0xFu:
        case 0x18u:
        case 0x3Cu:
          _Add(v1, "footse_p03");
          if (fieldID > 0x25)
            goto LABEL_22;
          if (((1LL << fieldID) & 0x508C0000) != 0)
            goto LABEL_11;
          if (((1LL << fieldID) & 0x24200000) != 0)
            goto LABEL_15;
          if (((1LL << fieldID) & 0x3100000000LL) != 0)
            goto LABEL_20;
          goto LABEL_22;
        case 0x12u:
        case 0x13u:
        case 0x17u:
        case 0x1Cu:
        case 0x1Eu:
          goto LABEL_11;
        case 0x15u:
        case 0x1Au:
        case 0x1Du:
          goto LABEL_15;
        case 0x20u:
        case 0x24u:
        case 0x25u:
          goto LABEL_20;
        default:
          goto LABEL_22;
      }
    case 0x12u:
    case 0x13u:
    case 0x17u:
    case 0x1Cu:
    case 0x1Eu:
LABEL_11:
      _Add(v1, "footse_p04");
      if (fieldID <= 0x1D && ((1 << fieldID) & 0x24200000) != 0)
        goto LABEL_15;
      goto LABEL_26;
    case 0x15u:
    case 0x1Au:
    case 0x1Du:
LABEL_15:
      v7 = &"footse_p05";
      goto LABEL_24;
    case 0x20u:
    case 0x24u:
    case 0x25u:
LABEL_20:
      _Add(v1, "footse_p06");
      if ((fieldID & 0xFFFFFFFE) != 0xC)
        goto LABEL_26;
      goto LABEL_23;
    default:
LABEL_22:
      if (fieldID - 40 <= 5)
      {
LABEL_23:
        v7 = &"footse_p07";
LABEL_24:
        v8 = *v7;
        v9 = Method_System_Collections_Generic_List_string__Add__;
LABEL_25:
        _Add(v1, v8, v9);
      }
LABEL_26:
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
  u64 *v3;
  System_String_o *v4;
  System_Object_array *v6;
  s32 v9;
  s32 v10;
  s32 fieldID;
  System_String_o *v14;
  System_Object_array *v16;
  u64 v18;
  struct fldSe_StaticFields *v19;
  struct System_String_array *v20;
  s32 v21;
  u32 max_length;
  struct System_String_array *gFldFootSeLoadNum;
  s64 gFldFootSeLoadIdx;
  System_String_o *v26;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v33;
  System_String_o *v34;
  System_Object_array *v36;
  AssetBundleCtrl_o *v39;
  struct System_String_array *v43;
  s32 v44;
  s32 v45;
  AssetBundleCtrl_o *v48;
  s32 gFldFootSeLoadPhase;

  v3 = sub_8D3950(s32, &gFldFootSeLoadPhase);
  v4 = Concat("fldFootSeLoadChk : ", v3);
  v6 = Empty_string_();
  Log(v4, v6, 0);
  v9 = gFldFootSeLoadPhase;
  if (v9)
  {
    if (v9 != 1)
      return v9 == 2;
    v26 = gFldFootSeLoadNum->m_Items[gFldFootSeLoadIdx];
    asset_bc = get_asset_bc();
    if (!IsLoad(asset_bc, v26))
      return 0;
    v10 = 0;
    gFldFootSeLoadPhase = 0;
  }
  else
  {
    fieldID = fldGb->fieldID;
    if (fieldID < 1)
      return 0;
    if (fieldID > 61)
      return 0;
    v14 = Concat_5269984("@@@@@ Init fldFotSeLoadNum : ", &gFldFootSeLoadNum->obj, " @@@@@");
    v16 = Empty_string_();
    Log(v14, v16, 0);
    if (!gFldFootSeLoadNum)
    {
      fldFootSeLoad(v18);
    }
    v19 = *(v18 + 184);
    v20 = gFldFootSeLoadNum;
    if (!v20)
      goto LABEL_97;
    if ((*(v18 + 295) & 2) != 0 && !*(v18 + 216))
    {
      v20 = gFldFootSeLoadNum;
    }
    v21 = gFldFootSeLoadIdx;
    max_length = v20->max_length;
    if (v21 != max_length)
    {
      if ((*(v18 + 295) & 2) != 0 && !*(v18 + 216))
      {
        v20 = gFldFootSeLoadNum;
        v21 = gFldFootSeLoadIdx;
        max_length = v20->max_length;
      }
      v33 = v20->m_Items[v21];
      v34 = Concat_5221536("@@@@ fldFootSeLoadChk : Check ", v33, " @@@@@");
      v36 = Empty_string_();
      Log(v34, v36, 0);
      {
LABEL_68:
      }
      while (1)
      {
        v39 = get_asset_bc();
        if (!IsLoad(v39, v33))
          break;
        {
        }
        LoadKeys(3, v33, 0);
        ++gFldFootSeLoadIdx;
        v43 = gFldFootSeLoadNum;
        v44 = gFldFootSeLoadIdx;
        v45 = v43->max_length;
        if (v44 >= v45)
        {
          gFldFootSeLoadPhase = 2;
          return 1;
        }
        v33 = v43->m_Items[v44];
          goto LABEL_68;
      }
      v48 = get_asset_bc();
      Load(v48, v33, v33, 0);
      v10 = 0;
      gFldFootSeLoadPhase = 1;
    }
    else
    {
LABEL_97:
      v10 = 0;
      *(*(v18 + 184) + 100LL) = 2;
    }
  }
  return v10;
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

  else if (!gFldFootSeLoadNum)
  {
    goto LABEL_26;
  }
  v3 = 4;
  v4 = 0;
  if ((v2->_2.bitflags2 & 2) == 0)
    goto LABEL_11;
LABEL_9:
LABEL_11:
  while (v4 < SLODWORD(gFldFootSeLoadNum->max_length))
  {
    asset_bc = get_asset_bc();
    UnloadAB(asset_bc, *(&gFldFootSeLoadNum->obj.klass + v3), 0);
    v11 = gFldFootSeLoadNum;
    v13 = *(&v11->obj.klass + v3);
    RemoveKeys(3, v13);
    v4 = ++v3 - 4;
      goto LABEL_9;
  }
LABEL_26:
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
  s32 fieldID;
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
  if (fieldID < DNG_MAX)
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
        v10 = fldSeSmgId + seid;
        v11 = fldGb;
        if (v11->fieldID == 20)
        {
          areaID = v11->areaID;
          if (areaID == 5)
            goto LABEL_48;
          if (areaID == 8)
            goto LABEL_48;
          if (areaID == 13)
            goto LABEL_48;
          if (areaID == 14)
            goto LABEL_48;
          if (areaID == 15)
            goto LABEL_48;
          if (areaID == 24)
            goto LABEL_48;
          if (areaID == 12 && evtBitCheck(22))
          {
LABEL_48:
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
  s32 v8;
  s32 v10;
  struct fldGlobalWork_t_o *v11;
  s32 areaID;
  struct typeFLDBGMTBL_array *gFldBgmTop;

  fieldID = fldGb->fieldID;
  else
  {
    if (fieldID >= DNG_MAX)
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
      v10 = fldSeSmgId + seid;
      v11 = fldGb;
      if (v11->fieldID == 20)
      {
        areaID = v11->areaID;
        if (areaID == 5)
          goto LABEL_57;
        if (areaID == 8)
          goto LABEL_57;
        if (areaID == 13)
          goto LABEL_57;
        if (areaID == 14)
          goto LABEL_57;
        if (areaID == 15)
          goto LABEL_57;
        if (areaID == 24)
          goto LABEL_57;
        if (areaID == 12 && evtBitCheck(22))
        {
LABEL_57:
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
  s32 fldSeSmgId;
  s32 v12;
  struct fldGlobalWork_t_o *v13;
  s32 areaID;
  struct typeFLDBGMTBL_array *gFldBgmTop;
  s32 Id_1916848;

  fieldID = fldGb->fieldID;
  else
  {
    if (fieldID >= DNG_MAX)
      return;
  }
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
LABEL_21:
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
                    goto LABEL_56;
                }
              }
            }
          }
        }
      }
    }
    v12 = gFldBgmTop->m_Items[55]->SmgID + seid;
  }
LABEL_56:
  Id_1916848 = FindId_1916848(1, v12);
  p2sdPlaySE_Vol_Fld(Id_1916848, vol);
}

// 0x1603190
void fldSe_Add(s32 id, f32 r, f32 x, f32 y, f32 z) {
  struct fldSe3D_tag_array *gFldSe3D;
  s64 gFldSe3DNum;
  struct fldSe3D_tag_array *v16;
  struct fldSe3D_tag_array *v18;
  struct fldSe3D_tag_array *v20;
  struct fldSe3D_tag_array *v22;
  struct fldSe3D_tag_array *v24;

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
  s64 v2;
  u64 v4;
  struct fldSe3D_tag_array *gFldSe3D;
  struct fldSe3D_tag_array *v9;
  struct typeFLDBGMTBL_array *gFldBgmTop;
  s64 fieldID;
  s32 SmgID;
  struct fldSe3D_tag_array *v17;
  s32 v19;

  v2 = 4;
  v4 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    if (v4 >= gFldSe3DNum)
      break;
    else
    {
      if (v4 >= LODWORD(gFldSe3D->max_length))
        goto LABEL_12;
    }
    if ((*(*(&gFldSe3D->obj.klass + v2) + 16LL) & 1) != 0)
    {
      v9 = gFldSe3D;
      *(*(&v9->obj.klass + v2) + 16LL) &= ~1u;
      fieldID = fldGb->fieldID;
      SmgID = gFldBgmTop->m_Items[fieldID]->SmgID;
      v17 = gFldSe3D;
      v19 = *(*(&v17->obj.klass + v2) + 20LL);
      p2sdSndStop_Fld(v19 + SmgID);
    }
    ++v2;
    v4 = v2 - 4;
      goto LABEL_6;
  }
}

// 0x15fe190
void fldSe_Task(void) {
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v13;
  f32 v14;
  f32 v16;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v25;
  s32 v26;
  s64 v27;
  u64 v29;
  s64 v30;
  struct fldSe3D_tag_array *gFldSe3D;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  struct fldSe3D_tag_array *v38;
  f32 v41;
  f32 v42;
  f32 v43;
  f32 v44;
  f32 v46;
  f32 v47;
  u64 v48;
  s16 v50;
  s32 v51;
  struct fldSe3D_tag_array *v53;
  f32 v55;
  f32 v56;
  f32 v57;
  f32 v58;
  struct fldSe3D_tag_array *v60;
  f32 v61;
  struct fldSe3D_tag_array *v63;
  struct fldSe3D_tag_array *v66;
  struct typeFLDBGMTBL_array *v73;
  s64 v74;
  s32 v76;
  struct fldSe3D_tag_array *v77;
  s32 v79;
  f32 v80;
  f32 v81;
  f32 v82;
  f32 v83;
  struct fldSe3D_tag_array *v85;
  f32 v86;
  f32 v87;
  f32 r;
  struct fldSe3D_tag_array *v90;
  struct fldSe3D_tag_array *v95;
  struct typeFLDBGMTBL_array *gFldBgmTop;
  s64 fieldID;
  s32 SmgID;
  struct fldSe3D_tag_array *v103;
  s32 id;
  u64 v106[2];

  v106[0] = 0;
  v106[1] = 0;
  sub_854690(v106, 0.0, -100.0, 0.0, 1.0);
  ++fldSe_Task_xyzcnt;
  sub_854710(&g_cameraPos, 0);
  v5 = v4;
  sub_854710(&g_targetPos, 0);
  v7 = v5 - v6;
  sub_854710(&g_targetPos, 1u);
  v9 = v8;
  sub_854710(&g_cameraPos, 2u);
  v11 = v10;
  sub_854710(&g_targetPos, 2u);
  v14 = v11 - v13;
  v16 = sdfSqrt((v7 * v7) + (v14 * v14), 0);
  if (v16 <= 200.0)
  {
    sub_854710(&g_cameraPos, 0);
    v20 = v24;
    sub_854710(&g_cameraPos, 2u);
    v23 = v25;
  }
  else
  {
    v18 = v16;
    sub_854710(&g_targetPos, 0);
    v20 = ((v7 / v18) * 200.0) + v19;
    sub_854710(&g_targetPos, 2u);
    v23 = ((v14 / v18) * 200.0) + v22;
  }
  v26 = 0;
  v27 = 4;
  v29 = 0;
  {
LABEL_26:
  }
  while (1)
  {
    if (v29 >= gFldSe3DNum)
      break;
    v34 = v9 - *(*(&gFldSe3D->obj.klass + v27) + 32LL);
    v35 = v23 - *(*(&gFldSe3D->obj.klass + v27) + 36LL);
    v36 = v20 - *(*(&gFldSe3D->obj.klass + v27) + 28LL);
    v37 = sdfSqrt(((v36 * v36) + (v34 * v34)) + (v35 * v35), 0);
    v38 = gFldSe3D;
    v30 = *(&v38->obj.klass + v27++);
    if ((*(v30 + 24) + 500.0) > v37)
      v26 = 1;
    v29 = v27 - 4;
      goto LABEL_26;
  }
  if (v26)
  {
    else if ((fldSe_Task_xyzcnt & 1) == 0)
    {
      goto LABEL_50;
    }
    sub_854710(&g_targetPos, 0);
    v42 = v41;
    sub_854710(&g_targetPos, 1u);
    v44 = v43;
    sub_854710(&g_targetPos, 2u);
    v47 = v46;
    p2sdSetStandPos(v20, v9, v23, v42, v44, v47);
  }
LABEL_50:
  v48 = 0;
  if ((v50 & 0x200) != 0)
    goto LABEL_95;
  while (1)
  {
    v51 = 0;
    if (v48 >= gFldSe3DNum)
      break;
    while (1)
    {
      v53 = gFldSe3D;
      v55 = v9 - v53->m_Items[v48]->y;
      v56 = v20 - v53->m_Items[v48]->x;
      v57 = v23 - v53->m_Items[v48]->z;
      v58 = sdfSqrt(((v56 * v56) + (v55 * v55)) + (v57 * v57), 0);
      v60 = gFldSe3D;
      v61 = v58;
      if ((v60->m_Items[v48]->flg & 1) != 0)
      {
        v90 = gFldSe3D;
        if ((v90->m_Items[v48]->r + 500.0) <= v61)
        {
          v95 = gFldSe3D;
          v95->m_Items[v48]->flg &= ~1u;
          fieldID = fldGb->fieldID;
          SmgID = gFldBgmTop->m_Items[fieldID]->SmgID;
          v103 = gFldSe3D;
          id = v103->m_Items[v48]->id;
          p2sdSndStop_Fld(id + SmgID);
        }
        else
        {
          sub_854930(v106, 0);
          sub_854930(v106, 1u);
          sub_854930(v106, 2u);
        }
      }
      else
      {
        v63 = gFldSe3D;
        if ((v63->m_Items[v48]->r + 500.0) > v61)
        {
          v66 = gFldSe3D;
          v66->m_Items[v48]->flg |= 1u;
          sub_854930(v106, 0);
          sub_854930(v106, 1u);
          sub_854930(v106, 2u);
          v73 = gFldBgmTop;
          v74 = fldGb->fieldID;
          v76 = v73->m_Items[v74]->SmgID;
          v77 = gFldSe3D;
          v79 = v77->m_Items[v48]->id;
          sub_854710(v106, 0);
          v81 = v80;
          sub_854710(v106, 1u);
          v83 = v82;
          sub_854710(v106, 2u);
          v85 = gFldSe3D;
          v87 = v86;
          r = v85->m_Items[v48]->r;
          p2sdPlaySe3DEx(v79 + v76, v81, v83, v87, (r / 100.0), 0);
        }
      }
      ++v48;
      if ((v50 & 0x200) == 0)
        break;
LABEL_95:
      v51 = v50 & 0x200;
      if (v48 >= gFldSe3DNum)
        goto LABEL_131;
    }
  }
LABEL_131:
  ++fldSe_Task_se3cnt;
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
        goto LABEL_26;
      }
      break;
    case 0:
      v6 = fldTalkBgmPlay_nowbgm;
      if (v6 != -1)
      {
        p2sdFadeOut(v6);
LABEL_26:
        fldTalkBgmPlay_nowbgm = -1;
      }
      break;
    case 1:
      v10 = gFldBgmTop->m_Items[50];
      goto LABEL_40;
    case 2:
      v12 = gFldBgmTop;
      v10 = v12->m_Items[14];
LABEL_40:
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
  s32 fieldID;
  u64 *v6;
  System_String_o *v7;
  u64 *v8;
  System_String_o *v10;
  AssetBundleCtrl_o *asset_bc;
  AssetBundleCtrl_o *v13;
  AssetBundleCtrl_o *v14;
  AssetBundleCtrl_o *v15;
  AssetBundleCtrl_o *v16;
  AssetBundleCtrl_o *v17;
  s32 v23;
  s32 v26;
  s32 v27;

  if (field <= 99)
  {
    fieldID = fldGb->fieldID;
    if (fieldID != field)
    {
      if (fieldID != 800)
      {
        if (fieldID != 801)
        {
          if (fieldID != 802)
          {
            if (fieldID != 803)
            {
              v27 = fieldID;
              v6 = sub_8D3950(s32, &v27);
              v7 = Format("f{0:D3}", v6, 0);
              v26 = fldGb->fieldID;
              v8 = sub_8D3950(s32, &v26);
              v10 = Format("e{0:D3}", v8, 0);
              {
              }
              RemoveKeys(5, 0);
              SndAssetBundleManager_SndData___Clear(VoiceBundleTable);
              RemoveKeys(1, v7);
              RemoveKeys(1, v10);
              RemoveKeys(3, v7);
              RemoveKeys(3, v10);
              asset_bc = get_asset_bc();
              UnloadAB(asset_bc, "e804");
              v13 = get_asset_bc();
              UnloadAB(v13, "f804");
              v14 = get_asset_bc();
              UnloadAB(v14, "e805");
              v15 = get_asset_bc();
              UnloadAB(v15, "f805");
              v16 = get_asset_bc();
              UnloadAB(v16, "e806");
              v17 = get_asset_bc();
              UnloadAB(v17, "f806");
              fldEventDataUnload();
              fldFootSeUnload();
              fldCmnBgmSeUnload();
            }
          }
        }
      }
    }
  }
  v23 = fldGb->fieldID;
  if (v23 < 100)
    goto LABEL_54;
  if (v23 >= 501)
  {
LABEL_54:
    RemoveOldEventField(field, *&area);
    PlayEventNo = 0;
  }
}
