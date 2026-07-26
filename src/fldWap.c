#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct doormovetbl_s doormovetbl_s;
typedef struct doormovework_s doormovework_s;
typedef struct fldSceneParam_t fldSceneParam_t;
typedef struct fldUnitControl_t fldUnitControl_t;
typedef struct fldwarp_s fldwarp_s;
typedef struct scrProcessWork_s scrProcessWork_s;
typedef struct warp_elvtbl_s warp_elvtbl_s;

static fldwarp_s *gFldWarpBuff;
static u16 gFldWap_after_flag;
static u16 gFldWap_after_scr[15];
static s32 gFldWap_after_nextidx;
static s32 gSuspendWarpIndex;
static s32 gFld_ElvId;
static s32 gFld_ElvTakasa;
static s32 gFldSisetu_Fld;
static s32 gFldSisetu_Area;
static s32 gFldSisetu_Type;
static s32 gFldSisetu_Idx;
static doormovework_s door_work[UNKNOWN_ARRAY_SIZE];
static char *scriptlabel[11];
static s32 gFldWarpIdx;
static s32 gFldWapPanel;
static bool ReadAssets;
static void *hasigo_name;

char *ByteToString(u16 **data);
char *CheckDoorWarpType(doormovetbl_s *wap);
s32 DLCGetFieldNo(s32 no);
f32 EulerAngleAxisY(void);
void GetCameraType(s32 field, s32 area, s32 wap, s32 cam, s32 *cammode, char **camname);
bool IsDLCField(s32 area);
bool IsLoad(AssetBundles *this, char *key);
bool IsMoverControl(dds3Basic_t *basic, char *name);
void LoadAssetExt(char *key, char *name, char *dlc);
void LoadField(s32 fld);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
void MakeWarpIndex(doormovetbl_s *pWap);
f32 OOYDEG(f32 a);
void SDF_ABORT3(char *aFmt, void **LegacyParamArray);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
s32 SetCopy(warp_elvtbl_s *this, u8 **data, s32 pos);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
void dds3FadeColorSet(u32 r, u32 g, u32 b);
void dds3FadeIn2(u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
dds3Basic_t *dds3GetActiveScene(void);
dds3Basic_t *dds3GetControlScene(void);
void dds3GetPosPoseSet(dds3Basic_t **pBasic);
dds3Basic_t *dds3SceneBasicSearchName(dds3Basic_t **scene, char *name);
dds3Basic_t *dds3SceneBasicSearchNameAndType(dds3Basic_t *scene, u32 type, char *name);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
void fldAnaStart(f32 x, f32 y, f32 z);
void fldAutoMapOpenBlock2(s32 fld, s32 area, s32 SBlock);
void fldBgmFadeOut(void);
void fldBgmSisetuLoad(s32 id);
void fldBgmTrans(void);
s32 fldBgmTransChk(s32 id1, s32 id2);
void fldDoorLoad(s32 field);
char *fldDoor_Find2(char **evename);
void fldDoor_Start(s32 evehit_resid);
char *fldEveHitResName_Find(dds3ProcessID_t *pid);
fldUnitControl_t *fldGetUnitControl(void);
s32 fldLoadNextFile(s32 field, s32 area);
s32 fldLoadNextGetStatus(void);
void fldMakeFilePath(char **pathstr, s32 field, s32 area);
void fldPlayerCalc_FastStart(void);
void fldPlayerCalc_WarpStart(void);
void fldPlayerOff(void);
void fldProcNext(s32 fld, s32 eveno);
void fldSePlay(s32 seid);
void fldSetSceneParam3(fldSceneParam_t *pParam, s32 loadField, s32 loadArea, char *pointResName);
void fldSetSceneParam4(fldSceneParam_t *pParam, s32 loadField, s32 loadArea, char *pointResName, s32 bgm, s32 camMode, char *camName);
void fldSetSceneParam5(fldSceneParam_t *pParam, s32 loadField, s32 loadArea, char *pointResName, s32 bgm, char *FoceScript);
void fldSetSceneParamLoad(fldSceneParam_t *pParam, s32 loadField, s32 loadArea, char *pointResName, s32 bgm, s32 camMode, char *camName);
s32 fldWap_SetBgm(doormovetbl_s *pWap);
void move_doorObject(doormovework_s *door, s32 lr, s32 oc);
scrProcessWork_s *scrGetScriptHandle(void);

// 0x147ea90
char *ByteToString(u16 **data) {
  il2cpp_array_size_t max_length;
  u64 v6;

  max_length = data->max_length;
  Clear(hasigo_name, 0);
  if (max_length < 1)
  {
    LODWORD(v6) = 0;
  }
  v6 = 0;
  do
  {
    if (!data->m_Items[v6])
      break;
    ++v6;
  }
  while (v6 < max_length);
  {
  }
  Append_5394864(hasigo_name, data, 0, v6);
  return (hasigo_name->klass->vtable._3_ToString.methodPtr)(
           hasigo_name,
           hasigo_name->klass->vtable._3_ToString.method);
}

// 0x1479cc0
char *CheckDoorWarpType(doormovetbl_s *wap) {
    IsDLCField(0);
    return 0;
}

// 0x147e790
void GetCameraType(s32 field, s32 area, s32 wap, s32 cam, s32 *cammode, char **camname) {
}

// 0x1482320
bool IsMoverControl(dds3Basic_t *basic, char *name) {
    return 0;
}

// 0x147c800
void MakeWarpIndex(doormovetbl_s *pWap) {
  struct System_Char_array *warp_camname;
  u32 max_length;
  s32 warp_cammode;
  s32 v9;

  warp_camname = pWap->warp_camname;
  max_length = warp_camname->max_length;
  warp_cammode = pWap->warp_cammode;
  v9 = pWap->warp_camname->m_Items[7] + 10 * warp_camname->m_Items[6] - 528;
  gSuspendWarpIndex = v9 | (warp_cammode << 8);
}

// 0x147e8c0
void MakeWarpIndex_21489856(s32 cammode, char *camname) {
  u16 Chars;
  s32 v7;
  s32 v9;

  Chars = get_Chars(camname, 6);
  v7 = 10 * Chars + get_Chars(camname, 7);
  v9 = v7 - 528;
  gSuspendWarpIndex = v9 | (cammode << 8);
}

// 0x147e980
void MakeWarpIndex_21490048(fldSceneParam_t *param) {
  s32 camMode;
  System_Char_array *camName;
  System_String_o *v5;
  s32 v7;
  s32 v9;
  u16 Chars;

  camMode = param->camMode;
  camName = param->camName;
  v5 = ByteToString(camName);
  if (IsNullOrEmpty(v5))
  {
    v7 = 1;
    v9 = camMode << 8;
  }
  else
  {
    Chars = get_Chars(v5, 6);
    v7 = 10 * Chars + get_Chars(v5, 7) - 528;
    v9 = camMode << 8;
  }
  gSuspendWarpIndex = v7 | v9;
}

// 0x1482530
void fldDoorDebugView(void) {
  ;
}

// 0x147d4c0
void fldDoorLoad(s32 field) {
    IsDLCField(0);
    fldMakeFilePath(0, 0, 0);
    LoadFileByte(0, 0, 0);
    SetCopy(0, 0, 0);
}

// 0x147a640
void fldDoorRun_FindStart(s32 resid) {
    fldPlayerCalc_WarpStart();
    scrGetScriptHandle();
    fldEveHitResName_Find(0);
    fldDoor_Find2(0);
    fldSePlay(0);
    fldDoor_Start(0);
    fldLoadNextGetStatus();
    fldBgmSisetuLoad(0);
    dds3FadeOut(0, 0, 0, 0);
    dds3FadeColorSet(0, 0, 0);
    fldAnaStart(0, 0, 0);
    fldGetUnitControl();
    dds3GetPosPoseSet(0);
    SDF_VU0__STOREVECTOR(0);
    dds3SetPosPoseSet(0, (sdfVector4_t){0});
}

// 0x14808c0
void fldDoor_AllSet(void) {
    dds3GetControlScene();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    EulerAngleAxisY();
    OOYDEG(0);
    dds3SceneBasicSearchNameAndType(0, 0, 0);
}

// 0x147b2c0
s32 fldDoor_ChkWarp(void) {
  return gFldWapPanel == 8;
}

// 0x1480210
void fldDoor_ElvExit(s32 select) {
    evtBitCheck(0);
    fldProcNext(0, 0);
    fldBgmFadeOut();
    fldWap_SetBgm(0);
    MakeWarpIndex(0);
    fldAutoMapOpenBlock2(0, 0, 0);
    fldSetSceneParam4(0, 0, 0, 0, 0, 0, 0);
    dds3AdminiCallSequence(0, 0, 0, 0);
}

// 0x1480030
s32 fldDoor_ElvTakasaToFloor(s32 takasa) {
  fldWap_c *v3;
  s32 *static_fields;
  s64 v5;
  s64 v6;
  struct warp_elvtbl_s_array *v8;
  u32 max_length;
  struct fldWap_StaticFields *v10;
  struct warp_elvtbl_s_array *elvtbl;
  s32 v15;
  struct System_Int16_array *floor;

  static_fields = v3->static_fields;
  v5 = static_fields[8];
  v6 = *(*static_fields + 16LL);
  if (*(*(v6 + 8 * v5 + 32) + 22LL) <= takasa)
  {
    v10 = v3->static_fields;
    elvtbl = v10->gFldWarpBuff->elvtbl;
    return ~v10->gFld_ElvTakasa + elvtbl->m_Items[v5]->floormax;
  }
  else
  {
    v8 = gFldWarpBuff->elvtbl;
    max_length = v8->max_length;
    v15 = v8->m_Items[v5]->floormax + ~takasa;
    floor = v8->m_Items[v5]->floor;
    return floor->m_Items[v15];
  }
}

// 0x147ebc0
void fldDoor_EveBtlExit(s32 field, s32 eveno) {
    fldDoorLoad(0);
    evtBitCheck(0);
    fldProcNext(0, 0);
    fldBgmFadeOut();
    fldAutoMapOpenBlock2(0, 0, 0);
    evtBitOn(0);
    SDF_ABORT3(0, 0);
    fldWap_SetBgm(0);
    MakeWarpIndex(0);
    fldSetSceneParam4(0, 0, 0, 0, 0, 0, 0);
    dds3AdminiCallSequence(0, 0, 0, 0);
}

// 0x147b050
void fldDoor_ExitCamera(char **evename) {
  u64 v3;
  struct doormovetbl_s_array *door_buff;
  doormovetbl_s_o *v7;
  s32 union01;
  System_String_o *String_5280336;
  System_String_o *v10;
  dds3Basic_t_o *ActiveScene;
  System_String_o *v14;
  System_String_o *v16;
  dds3Basic_t_o *pSceneBasic;
  dds3Basic_t_o *pCameraBasic;

  pCameraBasic = 0;
  pSceneBasic = 0;
  if (*evename)
  {
    v3 = 0;
    do
    {
      door_buff = gFldWarpBuff->door_buff;
      v7 = door_buff->m_Items[v3];
      if ((!v7->flag || evtBitCheck(v7->flag)) && v7->movetype)
      {
        union01 = v7->union01;
        String_5280336 = CreateString_5280336(0, v7->union02);
        v10 = Replace_5267216(String_5280336, StringLiteral_859, StringLiteral_416);
        if (fldGb->areaID + 1 == union01 && !Compare(*evename, v10, 0))
        {
          if (v7->warptype)
          {
            if (v7->warptype == 2)
              return;
          }
          else if (v7->warp_cammode == 3)
          {
            ActiveScene = dds3GetActiveScene();
            v14 = CreateString_5280336(0, v7->warp_camname);
            v16 = Replace_5267216(v14, StringLiteral_859, StringLiteral_416);
            pCameraBasic = dds3SceneBasicSearchNameAndType(ActiveScene, 4u, v16);
            pSceneBasic = dds3GetActiveScene();
            dds3SetActiveCameraSceneBasic(&pSceneBasic, &pCameraBasic);
            fldPlayerOff();
            return;
          }
        }
      }
    }
    while (v3++ < 0xFF);
  }
}

// 0x1479830
char *fldDoor_Find(char **evename) {
  u64 v3;
  struct doormovetbl_s_array *door_buff;
  doormovetbl_s_o *v7;
  s32 union01;
  System_String_o *v10;
  System_String_o *String_5280336;
  System_String_o *v12;
  bool v16;
  struct System_String_array *v18;
  struct System_String_array *v21;
  fldGlobal_c *v23;
  struct fldGlobal_StaticFields *static_fields;
  struct System_String_array *v26;
  struct System_String_array *v29;
  struct System_String_array *v32;
  struct System_String_array *scriptlabel;
  struct System_String_array *v37;
  struct System_String_array *v40;

  if (*evename)
  {
    v3 = 0;
    do
    {
      door_buff = gFldWarpBuff->door_buff;
      v7 = door_buff->m_Items[v3];
      if (!v7->flag || evtBitCheck(v7->flag))
      {
        union01 = v7->union01;
        if (fldGb->areaID + 1 == union01)
        {
          v10 = *evename;
          String_5280336 = CreateString_5280336(0, v7->union02);
          v12 = Replace_5267216(String_5280336, StringLiteral_859, StringLiteral_416);
          if (!Compare(v10, v12, 0))
          {
            switch (v7->movetype)
            {
              case 1u:
                if (fldGb->fieldID <= 9)
                {
                  return scriptlabel->m_Items[7];
                }
                else if (!v7->warptype
                       && (v7->union08 ? (v16 = v7->union08 <= 9) : (v16 = 0), v16))
                {
                  v40 = scriptlabel;
                  return v40->m_Items[6];
                }
                else
                {
                  return CheckDoorWarpType(v7);
                }
              case 2u:
                v18 = scriptlabel;
                return v18->m_Items[1];
              case 3u:
                v21 = scriptlabel;
                return v21->m_Items[2];
              case 4u:
                static_fields = v23->static_fields;
                if (static_fields->fldGb->fieldID >= 40)
                {
                  v37 = scriptlabel;
                  return v37->m_Items[9];
                }
                else
                {
                  v26 = scriptlabel;
                  return v26->m_Items[3];
                }
              case 5u:
                v29 = scriptlabel;
                return v29->m_Items[5];
              case 0xAu:
                v32 = scriptlabel;
                return v32->m_Items[8];
              default:
                break;
            }
          }
        }
      }
    }
    while (v3++ < 0xFF);
  }
  return 0;
}

// 0x1479e30
char *fldDoor_Find2(char **evename) {
  u64 v3;
  struct doormovetbl_s_array *door_buff;
  doormovetbl_s_o *v7;
  s32 union01;
  System_String_o *v10;
  System_String_o *String_5280336;
  System_String_o *v12;
  struct System_String_array *v18;
  struct System_String_array *v20;
  struct System_String_array *v23;
  struct System_String_array *v25;
  struct System_String_array *v27;
  struct System_String_array *scriptlabel;
  struct System_String_array *v32;
  struct System_String_array *v35;

  if (*evename)
  {
    v3 = 0;
    do
    {
      door_buff = gFldWarpBuff->door_buff;
      v7 = door_buff->m_Items[v3];
      if (!v7->flag || evtBitCheck(v7->flag))
      {
        union01 = v7->union01;
        if (fldGb->areaID + 1 == union01)
        {
          v10 = *evename;
          String_5280336 = CreateString_5280336(0, v7->union02);
          v12 = Replace_5267216(String_5280336, StringLiteral_859, StringLiteral_416);
          if (!Compare(v10, v12, 0))
          {
            gFldWarpIdx = v3;
            switch (v7->movetype)
            {
              case 1u:
                if (fldGb->fieldID <= 9)
                {
                  gFldWapPanel = 7;
                  return scriptlabel->m_Items[7];
                }
                else if (v7->warptype || !v7->union08 || v7->union08 > 9)
                {
                  gFldWapPanel = 0;
                  return CheckDoorWarpType(v7);
                }
                else
                {
                  gFldWapPanel = 6;
                  v35 = scriptlabel;
                  return v35->m_Items[6];
                }
              case 2u:
                gFldWapPanel = 1;
                v18 = scriptlabel;
                return v18->m_Items[1];
              case 3u:
                gFldWapPanel = 2;
                v20 = scriptlabel;
                return v20->m_Items[2];
              case 4u:
                if (fldGb->fieldID >= 40)
                {
                  gFldWapPanel = 9;
                  v32 = scriptlabel;
                  return v32->m_Items[9];
                }
                else
                {
                  gFldWapPanel = 3;
                  v23 = scriptlabel;
                  return v23->m_Items[3];
                }
              case 5u:
                gFldWapPanel = 5;
                v25 = scriptlabel;
                return v25->m_Items[5];
              case 0xAu:
                gFldWapPanel = 0;
                v27 = scriptlabel;
                return v27->m_Items[8];
              default:
                break;
            }
          }
        }
      }
    }
    while (v3++ < 0xFF);
  }
  return 0;
}

// 0x147a340
char *fldDoor_Find3(void) {
  fldWap_c *v2;
  struct fldWap_StaticFields *static_fields;
  s32 gFldWap_after_nextidx;
  struct doormovetbl_s_array *door_buff;
  doormovetbl_s_o *v7;
  s32 union01;
  struct System_String_array *scriptlabel;

  static_fields = v2->static_fields;
  gFldWap_after_nextidx = static_fields->gFldWap_after_nextidx;
  door_buff = static_fields->gFldWarpBuff->door_buff;
  v7 = door_buff->m_Items[gFldWap_after_nextidx];
  union01 = v7->union01;
  if (fldGb->areaID + 1 != union01 || v7->movetype != 10)
    return 0;
  gFldWarpIdx = gFldWap_after_nextidx;
  gFldWapPanel = 8;
  return scriptlabel->m_Items[8];
}

// 0x147f8a0
s32 fldDoor_GetElvTbl(s32 getmode) {
  fldWap_c *v3;
  struct fldWap_StaticFields *static_fields;
  s64 gFld_ElvId;
  struct warp_elvtbl_s_array *elvtbl;
  s32 result;
  struct warp_elvtbl_s_array *v9;
  struct warp_elvtbl_s_array *v11;
  struct System_Int16_array *floor;
  struct warp_elvtbl_s_array *v15;
  struct System_Int16_array *v17;
  struct warp_elvtbl_s_array *v19;
  struct System_Int16_array *v21;
  struct warp_elvtbl_s_array *v23;
  struct System_Int16_array *v25;
  struct warp_elvtbl_s_array *v27;
  struct System_Int16_array *v29;
  struct warp_elvtbl_s_array *v31;
  struct System_Int16_array *v33;
  struct warp_elvtbl_s_array *v35;
  struct System_Int16_array *sblock;
  struct warp_elvtbl_s_array *v39;
  struct System_Int16_array *v41;
  struct warp_elvtbl_s_array *v43;
  struct System_Int16_array *v45;
  struct warp_elvtbl_s_array *v47;
  struct System_Int16_array *v49;
  struct warp_elvtbl_s_array *v51;
  struct System_Int16_array *v53;
  struct warp_elvtbl_s_array *v55;
  struct System_Int16_array *v57;
  struct warp_elvtbl_s_array *v59;

  static_fields = v3->static_fields;
  gFld_ElvId = static_fields->gFld_ElvId;
  switch (getmode)
  {
    case 0:
      elvtbl = static_fields->gFldWarpBuff->elvtbl;
      result = elvtbl->m_Items[gFld_ElvId]->floormax;
      break;
    case 1:
      v9 = static_fields->gFldWarpBuff->elvtbl;
      result = v9->m_Items[gFld_ElvId]->se;
      break;
    case 2:
      v11 = static_fields->gFldWarpBuff->elvtbl;
      floor = v11->m_Items[gFld_ElvId]->floor;
      result = floor->m_Items[0];
      break;
    case 3:
      v15 = static_fields->gFldWarpBuff->elvtbl;
      v17 = v15->m_Items[gFld_ElvId]->floor;
      result = v17->m_Items[1];
      break;
    case 4:
      v19 = static_fields->gFldWarpBuff->elvtbl;
      v21 = v19->m_Items[gFld_ElvId]->floor;
      result = v21->m_Items[2];
      break;
    case 5:
      v23 = static_fields->gFldWarpBuff->elvtbl;
      v25 = v23->m_Items[gFld_ElvId]->floor;
      result = v25->m_Items[3];
      break;
    case 6:
      v27 = static_fields->gFldWarpBuff->elvtbl;
      v29 = v27->m_Items[gFld_ElvId]->floor;
      result = v29->m_Items[4];
      break;
    case 7:
      v31 = static_fields->gFldWarpBuff->elvtbl;
      v33 = v31->m_Items[gFld_ElvId]->floor;
      result = v33->m_Items[5];
      break;
    case 8:
      v35 = static_fields->gFldWarpBuff->elvtbl;
      sblock = v35->m_Items[gFld_ElvId]->sblock;
      result = sblock->m_Items[0];
      break;
    case 9:
      v39 = static_fields->gFldWarpBuff->elvtbl;
      v41 = v39->m_Items[gFld_ElvId]->sblock;
      result = v41->m_Items[1];
      break;
    case 10:
      v43 = static_fields->gFldWarpBuff->elvtbl;
      v45 = v43->m_Items[gFld_ElvId]->sblock;
      result = v45->m_Items[2];
      break;
    case 11:
      v47 = static_fields->gFldWarpBuff->elvtbl;
      v49 = v47->m_Items[gFld_ElvId]->sblock;
      result = v49->m_Items[3];
      break;
    case 12:
      v51 = static_fields->gFldWarpBuff->elvtbl;
      v53 = v51->m_Items[gFld_ElvId]->sblock;
      result = v53->m_Items[4];
      break;
    case 13:
      v55 = static_fields->gFldWarpBuff->elvtbl;
      v57 = v55->m_Items[gFld_ElvId]->sblock;
      result = v57->m_Items[5];
      break;
    case 14:
      v59 = static_fields->gFldWarpBuff->elvtbl;
      result = ~static_fields->gFld_ElvTakasa + v59->m_Items[gFld_ElvId]->floormax;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// 0x147f680
s32 fldDoor_GetHasigoTbl(s32 getmode) {
  fldWap_c *v3;
  s32 *static_fields;
  s64 v5;
  s64 v6;
  s64 v8;
  dds3Basic_t_o *v9;
  System_Char_array *v11;
  System_String_o *v13;
  System_Char_array *v16;
  System_String_o *v18;
  System_Char_array *v20;
  dds3Basic_t_o *scene;

  scene = 0;
  static_fields = v3->static_fields;
  v5 = static_fields[18];
  v6 = *(*static_fields + 24LL);
  v8 = *(v6 + 8 * v5 + 32);
  if (getmode == 2)
  {
    scene = dds3GetActiveScene();
    v11 = *(v8 + 48);
    v13 = ByteToString(v11);
  }
  if (getmode == 1)
  {
    scene = dds3GetActiveScene();
    v16 = *(v8 + 40);
    v18 = ByteToString(v16);
    v9 = dds3SceneBasicSearchName(&scene, v18);
    if (v9)
    v20 = *(v8 + 48);
    v13 = ByteToString(v20);
    {
      v9 = dds3SceneBasicSearchName(&scene, v13);
      if (!v9)
        return v9;
      LODWORD(v9) = v9->serialID;
      return v9;
    }
  }
  if (getmode)
    LODWORD(v9) = 0;
  else
    LODWORD(v9) = *(v8 + 32);
  return v9;
}

// 0x147a4a0
s32 fldDoor_GetWarpEff(void) {
  fldWap_c *v2;
  s32 *static_fields;
  s64 v4;
  s64 v5;

  static_fields = v2->static_fields;
  v4 = static_fields[18];
  v5 = *(*static_fields + 24LL);
  return *(*(v5 + 8 * v4 + 32) + 32LL);
}

// 0x1479370
void fldDoor_Init(void) {
  fldWap_c *v2;
  u64 v3;
  s32 v4;
  struct doormovework_s_array *door_work;
  struct doormovework_s_array *v7;
  struct doormovework_s_array *v9;
  struct doormovework_s_array *v11;
  struct doormovework_s_array *v13;
  struct doormovework_s_array *v15;
  struct doormovework_s_array *v17;
  struct doormovework_s_array *v19;
  struct doormovework_s_array *v21;
  struct doormovework_s_array *v23;
  struct doormovework_s_array *v25;
  struct doormovework_s_array *v27;
  struct doormovework_s_array *v29;
  struct doormovework_s_array *v31;
  struct doormovework_s_array *v33;
  struct doormovework_s_array *v35;
  struct doormovework_s_array *v37;
  struct doormovework_s_array *v39;
  struct doormovework_s_array *v41;
  struct doormovework_s_array *v43;
  Il2CppClass **v45;
  u32 v46;

  v3 = 0;
  do
  {
    door_work->m_Items[v3]->stat = 0;
    v7 = door_work;
    v7->m_Items[v3]->evehit_resid = 0;
    v9 = door_work;
    v9->m_Items[v3]->mode1 = 0;
    v11 = door_work;
    v11->m_Items[v3]->matter_resid1 = -1;
    v13 = door_work;
    v13->m_Items[v3]->mode2 = 0;
    v15 = door_work;
    v15->m_Items[v3]->matter_resid2 = -1;
    v17 = door_work;
    v17->m_Items[v3]->cnt1 = 0;
    v19 = door_work;
    v19->m_Items[v3]->cnt2 = 0;
    v21 = door_work;
    v21->m_Items[v3]->x1 = 0.0;
    v23 = door_work;
    v23->m_Items[v3]->y1 = 0.0;
    v25 = door_work;
    v25->m_Items[v3]->z1 = 0.0;
    v27 = door_work;
    v27->m_Items[v3]->mx1 = 0.0;
    v29 = door_work;
    v29->m_Items[v3]->my1 = 0.0;
    v31 = door_work;
    v31->m_Items[v3]->mz1 = 0.0;
    v33 = door_work;
    v33->m_Items[v3]->x2 = 0.0;
    v35 = door_work;
    v35->m_Items[v3]->y2 = 0.0;
    v37 = door_work;
    v37->m_Items[v3]->z2 = 0.0;
    v39 = door_work;
    v39->m_Items[v3]->mx2 = 0.0;
    v41 = door_work;
    v41->m_Items[v3]->my2 = 0.0;
    v43 = door_work;
    v45 = &v43->obj.klass + v3++;
    LODWORD(v45[4]->_1.generic_class) = 0;
    v46 = *&v2->_2.bitflags1;
    v4 = (v46 >> 9) & 1;
  }
  while (v3 != 256);
  gFldWarpIdx = -1;
}

// 0x147d9a0
bool fldDoor_SiseExit(void) {
    IsDLCField(0);
    IsLoad(0, 0);
    fldDoorLoad(0);
    evtBitCheck(0);
    fldBgmFadeOut();
    fldWap_SetBgm(0);
    MakeWarpIndex(0);
    fldSetSceneParam4(0, 0, 0, 0, 0, 0, 0);
    dds3AdminiCallSequence(0, 0, 0, 0);
    LoadField(0);
    return 0;
}

// 0x147aca0
void fldDoor_Start(s32 evehit_resid) {
  s64 i;
  fldWap_c *v4;
  u64 v5;
  struct fldWap_StaticFields *static_fields;
  struct doormovetbl_s_array *door_buff;
  struct doormovework_s_array *door_work;
  s64 v10;
  s64 v12;
  s32 v13;
  s32 v14;
  bool v15;
  bool v16;
  bool v17;
  struct fldGlobalWork_t_o *fldGb;
  struct fldGlobalWork_t_o *v20;
  struct fldGlobalWork_t_o *v21;

  if ((evehit_resid + 1) >= 2)
  {
    for (i = 4; i != 260; ++i)
    {
      v5 = i - 4;
      static_fields = v4->static_fields;
      door_buff = static_fields->gFldWarpBuff->door_buff;
      door_work = static_fields->door_work;
      v10 = *(&door_buff->obj.klass + i);
      v12 = *(&door_work->obj.klass + i);
      if (*(v12 + 16) == 1 && *(v12 + 20) == evehit_resid)
      {
        *(v12 + 16) = 2;
        *(v12 + 40) = 0;
        v13 = *(v10 + 32);
        if (v13 != 5
          && ((v14 = *(v10 + 34), v14 != 8) ? (v15 = v13 == 8) : (v15 = 1),
              !v15 ? (v16 = (v13 | 1) == 7) : (v16 = 1),
              !v16 ? (v17 = (v14 - 5) > 2u) : (v17 = 0),
              v17))
        {
          *(v12 + 48) = 20;
          if (fldGb->fieldID == 13)
          {
            if (evehit_resid == 65545 && !fldGb->areaID)
              *(v12 + 48) = 50;
          }
          v20 = fldGb;
          if (v20->fieldID == 20)
          {
            if (evehit_resid == 65540 && v20->areaID == 13)
              *(v12 + 48) = 50;
            if (evehit_resid == 65540 && fldGb->areaID == 24)
              *(v12 + 48) = 50;
          }
          v21 = fldGb;
          if (v21->fieldID == 31)
          {
            if (evehit_resid == 65577 && !v21->areaID)
              *(v12 + 48) = 50;
            if (evehit_resid == 65555 && fldGb->areaID == 12)
              *(v12 + 48) = 50;
            if (evehit_resid == 65556 && fldGb->areaID == 12)
              *(v12 + 48) = 50;
          }
        }
        else
        {
          *(v12 + 48) = 40;
        }
        *(v12 + 52) = 0;
        *(v12 + 60) = 0;
        *(v12 + 76) = 0;
        *(v12 + 84) = 0;
      }
    }
  }
}

// 0x1481a40
s32 fldDoor_Step(s32 matter_resid, f32 *x, f32 *y, f32 *z) {
    evtBitCheck(0);
    move_doorObject(0, 0, 0);
    return 0;
}

// 0x147d740
void fldDoor_Terminal(s32 type, s32 idx) {
    DLCGetFieldNo(0);
}

// 0x147b7f0
void fldDoor_Warp(char **evename) {
    evtBitOff(0);
    evtBitCheck(0);
    fldAutoMapOpenBlock2(0, 0, 0);
    fldBgmFadeOut();
    fldWap_SetBgm(0);
    MakeWarpIndex(0);
    fldPlayerCalc_FastStart();
    fldSetSceneParam4(0, 0, 0, 0, 0, 0, 0);
    dds3FadeOut(0, 0, 0, 0);
    fldSetSceneParam3(0, 0, 0, 0);
    dds3AdminiCallSequence(0, 0, 0, 0);
    fldSetSceneParam5(0, 0, 0, 0, 0, 0);
    fldProcNext(0, 0);
    evtBitOn(0);
}

// 0x147f450
void fldDoor_WarpCash(char **evename) {
  u64 v3;
  struct doormovetbl_s_array *door_buff;
  doormovetbl_s_o *v7;
  s32 union01;
  System_Char_array *union02;
  System_String_o *v11;
  s32 union08;
  s32 union09;
  s32 movetype;

  if (*evename)
  {
    v3 = 0;
    do
    {
      door_buff = gFldWarpBuff->door_buff;
      v7 = door_buff->m_Items[v3];
      if (v7->flag && !evtBitCheck(v7->flag))
        continue;
      union01 = v7->union01;
      if (fldGb->areaID + 1 != union01)
        continue;
      union02 = v7->union02;
      v11 = ByteToString(union02);
      if (!Equals_5234480(*evename, v11))
        continue;
      union08 = v7->union08;
      if (v7->union08)
      {
        union09 = v7->union09;
        if (v7->union09)
      }
      else
      {
        union08 = fldGb->fieldID;
        union09 = v7->union09;
        if (v7->union09)
        {
          if (v7->warptype)
            continue;
        }
      }
      union09 = fldGb->areaID + 1;
      if (v7->warptype)
        continue;
      movetype = v7->movetype;
      if (movetype == 1)
        return;
      if ((movetype - 2) <= 3)
      {
        fldLoadNextFile(union08, union09);
        return;
      }
    }
    while (v3++ < 0xFF);
  }
}

// 0x147c8e0
void fldDoor_WarpEx(s32 ex_no) {
    evtBitCheck(0);
    fldBgmFadeOut();
    fldWap_SetBgm(0);
    MakeWarpIndex(0);
    fldPlayerCalc_FastStart();
    fldSetSceneParam3(0, 0, 0, 0);
    fldSetSceneParam4(0, 0, 0, 0, 0, 0, 0);
    dds3AdminiCallSequence(0, 0, 0, 0);
    fldAutoMapOpenBlock2(0, 0, 0);
    fldSetSceneParam5(0, 0, 0, 0, 0, 0);
    dds3FadeIn2(0);
    evtBitOn(0);
    fldProcNext(0, 0);
}

// 0x147a540
s32 fldWapGetDoor(s32 getmode) {
  fldWap_c *v2;
  s32 *static_fields;
  s64 v4;
  s64 v5;
  u16 *v7;
  s32 v8;
  s32 result;
  s32 v10;

  static_fields = v2->static_fields;
  v4 = *(*static_fields + 24LL);
  v5 = static_fields[18];
  v7 = *(v4 + 8 * v5 + 32);
  if (v7[8] != 1)
    return 0;
  v8 = v7[16];
  if (v8 == 5)
    return 40;
  v10 = v7[17];
  result = 40;
  if (v8 != 8 && v10 != 7 && (v8 | 1) != 7 && (v10 - 5) >= 2u)
  {
    if (v10 == 8)
      return 40;
    else
      return 20;
  }
  return result;
}

// 0x14808b0
void fldWapLoadFromMem(void *data) {
  ;
}

// 0x147e040
bool fldWap_Load(s32 tmnltype, s32 tmnlid, fldSceneParam_t *param) {
    IsDLCField(0);
    IsLoad(0, 0);
    fldDoorLoad(0);
    evtBitCheck(0);
    MakeWarpIndex(0);
    fldSetSceneParamLoad(0, 0, 0, 0, 0, 0, 0);
    LoadAssetExt(0, 0, 0);
    return 0;
}

// 0x147b330
s32 fldWap_SetBgm(doormovetbl_s *pWap) {
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 BgmId;
  s32 warp_bgm;
  s32 v8;
  s32 v9;
  s32 warp_foot;
  fldGlobal_c *v12;
  s32 v14;
  fldGlobal_c *v16;
  struct fldGlobal_StaticFields *static_fields;
  s32 v19;

  fieldID = fldGb->fieldID;
  if (fieldID == 34)
  else  if (fieldID == 36)
  if (fieldID == 41)
  if (fieldID == 42)
  if (fieldID == 43)
  if (fieldID == 44)
  if (fieldID == 45)
  BgmId = fldGb->BgmId;
  warp_bgm = pWap->warp_bgm;
  if (BgmId == warp_bgm)
  {
    v8 = 0;
    warp_foot = pWap->warp_foot;
    if (!pWap->warp_foot)
  }
  v8 = fldBgmTransChk(BgmId, warp_bgm);
  if (pWap->warp_bgm)
  {
    if (v8 == 1)
    {
      static_fields = v16->static_fields;
      v19 = static_fields->fldGb->BgmId;
      gFldSndTransSrc = v19;
      v9 = 1;
    }
    else if (v8)
    {
      v9 = 0;
      {
        fldGb->BgmId = pWap->warp_bgm;
        if (v9)
        {
          fldBgmTrans();
        }
        warp_foot = pWap->warp_foot;
        if (!pWap->warp_foot)
      }
    }
    else
    {
      fldBgmFadeOut();
      v9 = 0;
    }
  }
  if (v8 != 1)
  v14 = fldGb->BgmId;
  gFldSndTransSrc = v14;
  fldGb->BgmId = 1;
  fldBgmTrans();
  v8 = 1;
  warp_foot = pWap->warp_foot;
  if (!pWap->warp_foot)
  {
    if ((v12->_2.bitflags2 & 2) == 0)
  }
  fldGb->FootSE = warp_foot - 1;
  fldGb->CamTableIdx = pWap->warp_camtbl;
  return v8;
}

// 0x147e520
bool fldWap_Suspend(s32 fld, s32 area, s32 CamIdx, s32 BgmId, s32 SeId, s32 WapIdx, fldSceneParam_t *param) {
    IsDLCField(0);
    IsLoad(0, 0);
    fldDoorLoad(0);
    GetCameraType(0, 0, 0, 0, 0, 0);
    fldSetSceneParamLoad(0, 0, 0, 0, 0, 0, 0);
    LoadAssetExt(0, 0, 0);
    return 0;
}

// 0x1481f90
void move_doorObject(doormovework_s *door, s32 lr, s32 oc) {
    dds3GetControlScene();
    dds3SearchSceneBasic(0, 0, 0);
    IsMoverControl(0, 0);
}
