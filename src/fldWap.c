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
static doormovework_s *door_work;
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
      goto LABEL_16;
    goto LABEL_13;
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
LABEL_13:
  }
LABEL_16:
  Append_5394864(hasigo_name, data, 0, v6);
  return (hasigo_name->klass->vtable._3_ToString.methodPtr)(
           hasigo_name,
           hasigo_name->klass->vtable._3_ToString.method);
}

// 0x1479cc0
char *CheckDoorWarpType(doormovetbl_s *wap) {
  struct System_String_array *scriptlabel;
  System_String_o *v6;
  s32 fieldID;
  struct System_String_array *v10;

  else
  {
    if (!LODWORD(scriptlabel->max_length))
      goto LABEL_6;
  }
  v6 = scriptlabel->m_Items[0];
  fieldID = fldGb->fieldID;
  else if (!IsDLCField(fieldID))
  {
    return v6;
  }
  if (wap->after_flag)
  {
    v10 = scriptlabel;
    return v10->m_Items[10];
  }
  return v6;
}

// 0x147e790
void GetCameraType(s32 field, s32 area, s32 wap, s32 cam, s32 *cammode, char **camname) {
  u64 *v12;
  s32 v13;

  if (gFldWarpBuff)
  {
    fldGb->CamTableIdx = BYTE2(wap);
    gSuspendWarpIndex = wap;
    *cammode = BYTE1(wap);
    v13 = wap;
    v12 = sub_8D3950(s32, &v13);
    *camname = Format("01cam_{0:D2}", v12, 0);
  }
}

// 0x1482320
bool IsMoverControl(dds3Basic_t *basic, char *name) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  Il2CppClass *v10;
  s64 v12;
  u64 *v13;
  s64 v14;
  s64 v15;
  char *v16;
  s64 *v17;
  char *v19;
  s64 *v20;
  u64 v21[2];
  char *v22;

  workdata = basic->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3SceneBasic_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3SceneBasic_t, v21);
    if ((v21[0] & 1) != 0)
      v19 = v22;
    else
      v19 = v21 + 1;
    v20 = sub_8C4940(v19);
  }
  v8 = workdata[2].klass;
  if (!*(*&v8->_1.this_arg.bits + 16LL))
    return 0;
  v10 = workdata[2].klass;
  v12 = *(*&v10->_1.this_arg.bits + 24LL);
  while (1)
  {
    v13 = *(v12 + 56);
    if (v13)
    {
      v14 = *v13;
      if (*(*v13 + 288LL) < v15 || *(*(v14 + 200) + 8 * v15 - 8) != dds3MoverBasicWorkData_t)
      {
        sub_8FC2C0(*(v14 + 64), dds3MoverBasicWorkData_t, v21);
        if ((v21[0] & 1) != 0)
          v16 = v22;
        else
          v16 = v21 + 1;
        v17 = sub_8C4940(v16);
      }
      if (v13[3] && op_Equality(*(v13[2] + 24LL), name, 0))
        break;
    }
    v12 = *(v12 + 72);
    if (!v12)
      return 0;
  }
  return 1;
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
      goto LABEL_11;
  }
  else
  {
    Chars = get_Chars(v5, 6);
    v7 = 10 * Chars + get_Chars(v5, 7) - 528;
    v9 = camMode << 8;
      goto LABEL_11;
  }
LABEL_11:
  gSuspendWarpIndex = v7 | v9;
}

// 0x1482530
void fldDoorDebugView(void) {
  ;
}

// 0x147d4c0
void fldDoorLoad(s32 field) {
  u64 *v3;
  u64 *v5;
  System_String_o *v7;
  bool IsDLCField;
  s64 *v9;
  System_String_o *v10;
  Il2CppObject *v12;
  Il2CppObject *v14;
  u64 *v15;
  System_String_o *v17;
  AssetBundleCtrl_o *asset_bc;
  System_Byte_array *FileByte;
  s32 v22;
  System_String_o *pathstr;

  pathstr = 0;
  v3 = Allocate(fldwarp_s);
  _ctor(v3, 0);
  else
  {
    gFldWarpBuff = v3;
    if (field > 99)
      return;
  }
  v22 = field;
  pathstr = "";
  v5 = sub_8D3950(s32, &v22);
  v7 = Format("f{0:D3}", v5, 0);
  IsDLCField = IsDLCField(field);
  v9 = &"m";
  if (!IsDLCField)
    v9 = &"";
  v10 = Concat_5224608(v7, *v9);
  v12 = Concat_5224608("NextField : ", v10);
  Log(v12, 0);
  fldMakeFilePath(&pathstr, field, 1);
  v14 = pathstr;
  v22 = field;
  v15 = sub_8D3950(s32, &v22);
  v17 = Format_5268592("{0}F{1:D3}.WAP.bytes", v14, v15);
  asset_bc = get_asset_bc();
  FileByte = LoadFileByte(asset_bc, v10, v17);
  SetCopy(gFldWarpBuff, FileByte, 0, 0);
}

// 0x147a640
void fldDoorRun_FindStart(s32 resid) {
  u64 *v3;
  dds3ProcessID_t_o *ProcessID;
  s32 *static_fields;
  s64 v11;
  s64 v12;
  u16 *v14;
  s32 v16;
  s32 v17;
  struct doormovework_s_array *door_work;
  s32 v24;
  s32 v26;
  struct doormovework_s_array *v28;
  f32 x1;
  u32 v33;
  u32 v34;
  u32 v35;
  f32 *fldGb;
  f32 v39;
  f32 v40;
  f32 v41;
  fldUnitControl_t_Fields *p_fields;
  UnityEngine_Vector4_o p;
  System_String_o *evename;

  *&p.x = 0;
  *&p.z = 0;
  v3 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v3);
  evename = "";
  if (fldGb->fieldID <= 9)
  {
    fldPlayerCalc_WarpStart();
  }
  else
  {
    if (!resid)
      goto LABEL_19;
    ProcessID = scrGetScriptHandle()->ProcessID;
    evename = fldEveHitResName_Find(ProcessID);
    if (evename)
    {
      if (fldDoor_Find2(&evename))
      {
LABEL_19:
        v11 = static_fields[18];
        v12 = *(*static_fields + 24LL);
        v14 = *(v12 + 8 * v11 + 32);
        switch (v14[8])
        {
          case 1:
            v16 = v14[11];
            if (fldGb->areaID + 1 == v16)
            {
              v17 = v14[18];
              fldSePlay(v17);
              fldDoor_Start(door_work->m_Items[v11]->evehit_resid);
              if (v14[30] <= 5u)
              {
                if (!fldLoadNextGetStatus())
                {
                  v24 = v14[30];
                  fldBgmSisetuLoad(v24);
                }
              }
            }
            break;
          case 2:
            v26 = v14[11];
            if (fldGb->areaID + 1 == v26)
            {
              v28 = door_work;
              x1 = v28->m_Items[v11]->x1;
              gfldPlayerKakudo2 = x1;
              gfldPlayerKakudo2Mode = 1;
              if (v14[16] == 1)
              {
                fldSePlay(56);
                v33 = 192;
                v34 = 192;
                v35 = 192;
              }
              else
              {
                v33 = 0;
                v34 = 0;
                v35 = 0;
              }
              dds3FadeOut(v33, v34, v35, 0xFu);
            }
            break;
          case 3:
            dds3FadeColorSet(0, 0, 0);
            v39 = fldGb[78];
            v40 = fldGb[79];
            v41 = fldGb[80];
            fldAnaStart(v39, v40, v41);
            break;
          case 5:
            *&p.x = 0;
            *&p.z = 0;
            p_fields = &fldGetUnitControl()->fields;
            dds3GetPosPoseSet(&p_fields->handle);
            SDF_VU0__STOREVECTOR(&p);
            sub_854710(&p, 1u);
            sub_854930(&p, 1u);
            dds3SetPosPoseSet(&p_fields->handle, p);
            if (v14[16])
            {
              gfldPlayerHasiCnt = -100;
            }
            else
            {
              gfldPlayerHasiCnt = 100;
            }
            break;
          case 0xA:
            fldSePlay(56);
            break;
          default:
            return;
        }
      }
    }
  }
}

// 0x14808c0
void fldDoor_AllSet(void) {
  u64 i;
  struct doormovework_s_array *door_work;
  doormovework_s_o *v8;
  struct doormovetbl_s_array *door_buff;
  doormovetbl_s_o *v11;
  s32 movetype;
  s32 union01;
  u64 v15;
  struct fldResHead_t_array *gEvnRng;
  struct fldResHead_t_array *v21;
  System_String_o *resourceName;
  System_String_o *String_5280336;
  System_String_o *v25;
  struct fldResHead_t_array *v27;
  struct fldResHead_t_array *v29;
  struct fldResHead_t_array *v31;
  struct fldResHead_t_array *v33;
  struct fldResHead_t_array *v35;
  f32 v38;
  f32 j;
  s32 v41;
  System_String_o *v42;
  System_String_o *v44;
  dds3Basic_t_o *v45;
  u64 v46;
  struct fldResHead_t_array *v49;
  struct fldResHead_t_array *v52;
  System_String_o *v54;
  System_String_o *v55;
  System_String_o *v56;
  struct fldResHead_t_array *v58;
  struct fldResHead_t_array *v60;
  struct fldResHead_t_array *v62;
  struct fldResHead_t_array *v64;
  struct fldResHead_t_array *v66;
  f32 v69;
  f32 m;
  s32 v71;
  System_String_o *v73;
  System_String_o *v75;
  dds3Basic_t_o *v76;
  u64 v77;
  struct fldResHead_t_array *v80;
  struct fldResHead_t_array *v83;
  System_String_o *v85;
  System_String_o *v86;
  System_String_o *v87;
  struct fldResHead_t_array *v89;
  struct fldResHead_t_array *v91;
  struct fldResHead_t_array *v93;
  struct fldResHead_t_array *v95;
  struct fldResHead_t_array *v97;
  f32 v100;
  f32 k;
  s32 v102;
  s32 union03;
  s32 matter_resid1;
  s32 union04;
  dds3Basic_t_o *scene;
  UnityEngine_Vector4_o v114;
  s64 v115;

  *&v114.x = 0;
  *&v114.z = 0;
  sub_854690(&v114.x, 0.0, 0.0, 0.0, 1.0);
  scene = dds3GetControlScene();
  v115 = 0;
  for (i = 0; i != 256; ++i)
  {
    while (1)
    {
LABEL_7:
      v8 = door_work->m_Items[i];
      door_buff = gFldWarpBuff->door_buff;
      v11 = door_buff->m_Items[i];
      movetype = v11->movetype;
      if (movetype == 1)
        break;
      if (movetype != 2)
        goto LABEL_220;
      union01 = v11->union01;
      if (fldGb->areaID + 1 != union01)
        goto LABEL_220;
      v15 = 0;
        goto LABEL_25;
LABEL_21:
LABEL_25:
      while (1)
      {
        if (v15 >= gEvnRngNum)
          break;
LABEL_26:
        else
        {
          if (v15 >= LODWORD(gEvnRng->max_length))
            goto LABEL_29;
        }
        if (gEvnRng->m_Items[v15]->resourceName)
        {
          v21 = gEvnRng;
          resourceName = v21->m_Items[v15]->resourceName;
          String_5280336 = CreateString_5280336(0, v11->union02);
          v25 = Replace_5267216(String_5280336, " ", "");
          if (!Compare(resourceName, v25, 0))
          {
            v27 = gEvnRng;
            v8->evehit_resid = v27->m_Items[v15]->resourceID;
            v29 = gEvnRng;
            sub_854710(&v29->m_Items[v15]->sisei->rot, 0);
            sub_854930(&v114, 0);
            v31 = gEvnRng;
            sub_854710(&v31->m_Items[v15]->sisei->rot, 1u);
            sub_854930(&v114, 1u);
            v33 = gEvnRng;
            sub_854710(&v33->m_Items[v15]->sisei->rot, 2u);
            sub_854930(&v114, 2u);
            v35 = gEvnRng;
            sub_854710(&v35->m_Items[v15]->sisei->rot, 3u);
            sub_854930(&v114, 3u);
            SDF_VU0__LOADVECTOR(v114);
            v38 = EulerAngleAxisY();
            for (j = OOYDEG(v38); j < 0.0; j = j + 360.0)
              ;
            while (j > 360.0)
              j = j + -360.0;
            v8->x1 = j;
          }
        }
        ++v15;
          goto LABEL_21;
      }
LABEL_123:
      v8->stat = 0;
      *&v8->cnt1 = 0;
      *&v8->y1 = 0;
      *&v8->x2 = 0;
      v8->z2 = 0.0;
      if (++i == 256)
        return;
    }
    v41 = v11->union01;
    if (fldGb->areaID + 1 == v41)
    {
      v8->matter_resid1 = -1;
      if (!v11->union03)
        goto LABEL_125;
      v42 = CreateString_5280336(0, v11->union06);
      v44 = Replace_5267216(v42, " ", "");
      v45 = dds3SceneBasicSearchNameAndType(scene, 6u, v44);
      if (!v45)
      {
LABEL_125:
        v8->matter_resid2 = -1;
        if (!v11->union04)
          goto LABEL_183;
        v73 = CreateString_5280336(0, v11->union07);
        v75 = Replace_5267216(v73, " ", "");
        v76 = dds3SceneBasicSearchNameAndType(scene, 6u, v75);
        if (!v76)
          goto LABEL_183;
        v77 = 0;
        v8->matter_resid2 = v76->serialID;
          goto LABEL_135;
LABEL_131:
        while (1)
        {
LABEL_135:
          if (v77 >= gEvnRngNum)
            goto LABEL_183;
LABEL_136:
          else
          {
            v80 = gEvnRng;
            if (v77 >= LODWORD(v80->max_length))
              goto LABEL_139;
          }
          if (v80->m_Items[v77]->resourceName)
          {
            v83 = gEvnRng;
            v85 = v83->m_Items[v77]->resourceName;
            v86 = CreateString_5280336(0, v11->union02);
            v87 = Replace_5267216(v86, " ", "");
            if (!Compare(v85, v87, 0))
            {
              v89 = gEvnRng;
              v8->evehit_resid = v89->m_Items[v77]->resourceID;
              v91 = gEvnRng;
              sub_854710(&v91->m_Items[v77]->sisei->rot, 0);
              sub_854930(&v114, 0);
              v93 = gEvnRng;
              sub_854710(&v93->m_Items[v77]->sisei->rot, 1u);
              sub_854930(&v114, 1u);
              v95 = gEvnRng;
              sub_854710(&v95->m_Items[v77]->sisei->rot, 2u);
              sub_854930(&v114, 2u);
              v97 = gEvnRng;
              sub_854710(&v97->m_Items[v77]->sisei->rot, 3u);
              sub_854930(&v114, 3u);
              SDF_VU0__LOADVECTOR(v114);
              v100 = EulerAngleAxisY();
              for (k = OOYDEG(v100); k < 0.0; k = k + 360.0)
                ;
              while (k > 360.0)
                k = k + -360.0;
              if (k >= 45.0 && k <= 135.0)
              {
                v102 = 1;
LABEL_182:
                LODWORD(v115) = v102;
                goto LABEL_134;
              }
              if (k < 135.0 || k > 225.0)
              {
                if (k > 315.0 || k < 225.0)
                  v102 = 2;
                else
                  v102 = 3;
                goto LABEL_182;
              }
              LODWORD(v115) = 0;
            }
          }
LABEL_134:
          ++v77;
            goto LABEL_131;
        }
      }
      v46 = 0;
      v8->matter_resid1 = v45->serialID;
        goto LABEL_75;
LABEL_71:
      while (1)
      {
LABEL_75:
        if (v46 >= gEvnRngNum)
          goto LABEL_125;
LABEL_76:
        else
        {
          v49 = gEvnRng;
          if (v46 >= LODWORD(v49->max_length))
            goto LABEL_79;
        }
        if (v49->m_Items[v46]->resourceName)
        {
          v52 = gEvnRng;
          v54 = v52->m_Items[v46]->resourceName;
          v55 = CreateString_5280336(0, v11->union02);
          v56 = Replace_5267216(v55, " ", "");
          if (!Compare(v54, v56, 0))
          {
            v58 = gEvnRng;
            v8->evehit_resid = v58->m_Items[v46]->resourceID;
            v60 = gEvnRng;
            sub_854710(&v60->m_Items[v46]->sisei->rot, 0);
            sub_854930(&v114, 0);
            v62 = gEvnRng;
            sub_854710(&v62->m_Items[v46]->sisei->rot, 1u);
            sub_854930(&v114, 1u);
            v64 = gEvnRng;
            sub_854710(&v64->m_Items[v46]->sisei->rot, 2u);
            sub_854930(&v114, 2u);
            v66 = gEvnRng;
            sub_854710(&v66->m_Items[v46]->sisei->rot, 3u);
            sub_854930(&v114, 3u);
            SDF_VU0__LOADVECTOR(v114);
            v69 = EulerAngleAxisY();
            for (m = OOYDEG(v69); m < 0.0; m = m + 360.0)
              ;
            while (m > 360.0)
              m = m + -360.0;
            if (m >= 45.0 && m <= 135.0)
            {
              v71 = 1;
LABEL_122:
              HIDWORD(v115) = v71;
              goto LABEL_74;
            }
            if (m < 135.0 || m > 225.0)
            {
              if (m > 315.0 || m < 225.0)
                v71 = 2;
              else
                v71 = 3;
              goto LABEL_122;
            }
            HIDWORD(v115) = 0;
          }
        }
LABEL_74:
        ++v46;
          goto LABEL_71;
      }
    }
LABEL_220:
    ;
  }
}

// 0x147b2c0
s32 fldDoor_ChkWarp(void) {
  return gFldWapPanel == 8;
}

// 0x1480210
void fldDoor_ElvExit(s32 select) {
  s32 *static_fields;
  s64 v6;
  s64 v7;
  s32 *v9;
  s64 v10;
  s64 v11;
  s32 gFld_ElvTakasa;
  s64 i;
  u64 v16;
  struct doormovetbl_s_array *door_buff;
  s64 v19;
  s32 v21;
  s32 gFld_ElvId;
  s32 v23;
  s32 v24;
  s32 v26;
  fldGlobal_c *v27;
  s32 v29;
  s32 fieldID;
  s32 v33;
  u64 *v34;
  s32 v35;
  s32 v36;
  u16 v38;
  s32 v42;
  struct warp_elvtbl_s_array *elvtbl;
  s64 v45;
  struct System_Int16_array *sblock;
  s32 v49;
  System_String_o *String_5280336;
  System_String_o *v51;
  s32 v52;
  System_String_o *v53;
  s32 v54;
  System_String_o *v55;
  System_String_o *v56;
  char v57[136];
  fldSceneParam_t_o pParam;

  memset(&pParam, 0, sizeof(pParam));
  sub_F87580(&pParam);
  v6 = *(*static_fields + 16LL);
  v7 = static_fields[8];

  {
    v10 = *(*v9 + 16LL);
    v11 = v9[8];
    gFld_ElvTakasa = *(*(v10 + 8 * v11 + 32) + 22LL) + ~select;
  }
  for (i = 4; ; ++i)
  {
    v16 = i - 4;
    door_buff = gFldWarpBuff->door_buff;
    v19 = *(&door_buff->obj.klass + i);
    if (*(v19 + 20) && !evtBitCheck(*(v19 + 20), 0) || *(v19 + 16) != 6)
      goto LABEL_42;
    v21 = *(v19 + 32);
    if (v21 - 1 == gFld_ElvId && gFld_ElvTakasa == *(v19 + 34) && !*(v19 + 56))
      break;
    if (*(v19 + 16) == 6)
    {
      v23 = *(v19 + 32);
      else if (v23 - 1 != gFld_ElvId)
      {
        goto LABEL_42;
      }
      if (gFld_ElvTakasa == *(v19 + 34) && *(v19 + 56) == 3)
      {
        v29 = *(v19 + 60);
        fieldID = fldGb->fieldID;
        fldProcNext(fieldID, v29);
        fldBgmFadeOut();
        if (!*(v19 + 62))
        {
          v33 = *(v19 + 64);
          if (v33)
          {
            fldProcNext(v33, v29);
          }
        }
        *v57 = v29;
        v34 = sub_8D3950(s32, v57);
        v35 = 8;
        v36 = 4;
        goto LABEL_101;
      }
    }
LABEL_42:
    if (v16 >= 0xFF)
      return;
  }
  v24 = *(v19 + 60);
  if (!*(v19 + 60))
  {
    v24 = fldGb->fieldID;
  }
  v26 = *(v19 + 62);
  if (!*(v19 + 62))
  {
    v26 = fldGb->areaID + 1;
    if ((v27->_2.bitflags2 & 2) == 0)
      goto LABEL_74;
    goto LABEL_72;
  }
  {
LABEL_72:
  }
LABEL_74:
  if (fldGb->fieldID != v24)
  {
    fldBgmFadeOut();
  }
  fldWap_SetBgm(v19);
  v38 = *(v19 + 100);
  if (v38)
  {
    gFldWap_after_flag = v38;
    Copy_3886320(*(v19 + 104), gFldWap_after_scr, *(*(v19 + 104) + 24LL), 0);
    gFldWap_after_nextidx = i - 3;
  }
  MakeWarpIndex(v19);
  v42 = *(v19 + 58);
  gFldNowDZone = v42;
  elvtbl = gFldWarpBuff->elvtbl;
  v45 = gFld_ElvId;
  sblock = elvtbl->m_Items[v45]->sblock;
  v49 = sblock->m_Items[gFld_ElvTakasa];
  fldAutoMapOpenBlock2(v24, v26, v49);
  String_5280336 = CreateString_5280336(0, *(v19 + 72), 0);
  v51 = Replace_5267216(String_5280336, " ", "");
  v52 = *(v19 + 96);
  v53 = v51;
  v54 = *(v19 + 80);
  v55 = CreateString_5280336(0, *(v19 + 88), 0);
  v56 = Replace_5267216(v55, " ", "");
  fldSetSceneParam4(&pParam, v24, v26, v53, v52, v54, v56);
  memcpy(v57, &pParam, sizeof(v57));
  v34 = sub_8D3950(fldSceneParam_t, v57);
  v35 = 7;
  v36 = 2;
LABEL_101:
  dds3AdminiCallSequence(v35, v34, v36, 0);
}

// 0x1480030
s32 fldDoor_ElvTakasaToFloor(s32 takasa) {
  s32 *static_fields;
  s64 v5;
  s64 v6;
  struct warp_elvtbl_s_array *v8;
  u32 max_length;
  struct warp_elvtbl_s_array *elvtbl;
  s32 v15;
  struct System_Int16_array *floor;

  v5 = static_fields[8];
  v6 = *(*static_fields + 16LL);
  if (*(*(v6 + 8 * v5 + 32) + 22LL) <= takasa)
  {
    elvtbl = gFldWarpBuff->elvtbl;
    return ~gFld_ElvTakasa + elvtbl->m_Items[v5]->floormax;
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
  u64 *v6;
  s64 i;
  u64 v10;
  struct doormovetbl_s_array *door_buff;
  s64 v13;
  System_Object_array *v14;
  s64 *v15;
  s64 *v16;
  s64 *v18;
  s64 *v20;
  s32 v24;
  s32 v26;
  u16 v28;
  s32 v32;
  System_String_o *String_5280336;
  System_String_o *v34;
  s32 v35;
  System_String_o *v36;
  s32 v37;
  System_String_o *v38;
  System_String_o *v39;
  u64 *v40;
  s32 v41;
  s32 v42;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  s32 v49;
  s32 v53;
  u32 v54;
  s32 v55;
  u32 v57;
  System_WeakReference_o *Item;
  struct fldSave_t_o *fldSave;
  s32 v70;
  char dest[136];
  fldSceneParam_t_o pParam;

  memset(&pParam, 0, sizeof(pParam));
  sub_F87580(&pParam);
  v6 = NewSpecific(s32, 2u);
  fldDoorLoad(field);
  for (i = 4; ; ++i)
  {
    v10 = i - 4;
    door_buff = gFldWarpBuff->door_buff;
    v13 = *(&door_buff->obj.klass + i);
    if (*(v13 + 20) && !evtBitCheck(*(v13 + 20), 0) || *(v13 + 16) != 8 || *(v13 + 32) != eveno)
      goto LABEL_18;
    if (!*(v13 + 56))
      break;
    if (*(v13 + 56) == 2)
    {
      fldProcNext(0, 0);
      fldBgmFadeOut();
      fieldID = fldGb->fieldID;
      areaID = fldGb->areaID;
      v49 = *(v13 + 64);
      fldAutoMapOpenBlock2(fieldID, areaID + 1, v49);
      v53 = fldGb->fieldID;
      gFldSisetu_Fld = v53;
      gFldSisetu_Area = fldGb->areaID + 1;
      gFldSisetu_Type = *(v13 + 60);
      gFldSisetu_Idx = *(v13 + 62);
      switch (*(v13 + 60))
      {
        case 0:
          *dest = *(v13 + 62);
          v40 = sub_8D3950(s32, dest);
          v41 = 29;
          goto LABEL_111;
        case 1:
          *dest = *(v13 + 62);
          v40 = sub_8D3950(s32, dest);
          v41 = 30;
          goto LABEL_111;
        case 2:
          *dest = *(v13 + 62);
          v40 = sub_8D3950(s32, dest);
          v41 = 28;
          goto LABEL_111;
        case 3:
          v54 = *(v6 + 6);
          *(v6 + 8) = 0;
          v55 = *(v13 + 62);
          *(v6 + 9) = v55;
          if (*(&_get_Item(
                    fldHitData->_fldSaveNml,
                    *(v6 + 9))->isLongReference
               + 1))
          {
            Item = _get_Item(
                     fldHitData->_fldSaveNml,
                     *(v6 + 9));
            evtBitOn(*(&Item->isLongReference + 1), 0);
          }
            goto LABEL_104;
          goto LABEL_106;
        case 4:
          v57 = *(v6 + 6);
          *(v6 + 8) = 1;
          *(v6 + 9) = *(v13 + 62);
            goto LABEL_106;
LABEL_104:
LABEL_106:
          DDS3_GBWK->fldSave->tmnltype = *(v6 + 8);
          fldSave = DDS3_GBWK->fldSave;
          v41 = 32;
          v40 = v6;
          fldSave->tmnlid = *(v6 + 9);
LABEL_111:
          v42 = 4;
          goto LABEL_112;
        case 5:
          v41 = 31;
          v40 = 0;
          v42 = 0;
          goto LABEL_112;
        default:
          return;
      }
    }
LABEL_18:
    if (v10 >= 0xFF)
    {
      *dest = field;
      v14 = NewSpecific(object, 2u);
      v15 = sub_8D3950(s32, dest);
      v16 = v15;
      v14->m_Items[0] = v16;
      v70 = eveno;
      v18 = sub_8D3950(s32, &v70);
      v20 = v18;
      v14->m_Items[1] = v20;
      SDF_ABORT3("WAP DataNotFound fld:%d, id:%d", v14, 0);
      return;
    }
  }
  if (*(v13 + 60))
    v24 = *(v13 + 60);
  else
    v24 = field;
  v26 = *(v13 + 62);
  if (fldGb->fieldID != v24)
  {
    fldBgmFadeOut();
  }
  fldWap_SetBgm(v13);
  v28 = *(v13 + 100);
  if (v28)
  {
    gFldWap_after_flag = v28;
    Copy_3886320(*(v13 + 104), gFldWap_after_scr, *(*(v13 + 104) + 24LL), 0);
    gFldWap_after_nextidx = i - 3;
  }
  MakeWarpIndex(v13);
  v32 = *(v13 + 58);
  gFldNowDZone = v32;
  String_5280336 = CreateString_5280336(0, *(v13 + 72), 0);
  v34 = Replace_5267216(String_5280336, " ", "");
  v35 = *(v13 + 96);
  v36 = v34;
  v37 = *(v13 + 80);
  v38 = CreateString_5280336(0, *(v13 + 88), 0);
  v39 = Replace_5267216(v38, " ", "");
  fldSetSceneParam4(&pParam, v24, v26, v36, v35, v37, v39);
  pParam.callmode = 6;
  memcpy(dest, &pParam, sizeof(dest));
  v40 = sub_8D3950(fldSceneParam_t, dest);
  v41 = 7;
  v42 = 2;
LABEL_112:
  dds3AdminiCallSequence(v41, v40, v42, 0);
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
        v10 = Replace_5267216(String_5280336, " ", "");
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
            v16 = Replace_5267216(v14, " ", "");
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
          v12 = Replace_5267216(String_5280336, " ", "");
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
                if (fldGb->fieldID >= 40)
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
          v12 = Replace_5267216(String_5280336, " ", "");
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
  s32 gFldWap_after_nextidx;
  struct doormovetbl_s_array *door_buff;
  doormovetbl_s_o *v7;
  s32 union01;
  struct System_String_array *scriptlabel;

  door_buff = gFldWarpBuff->door_buff;
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

  switch (getmode)
  {
    case 0:
      elvtbl = gFldWarpBuff->elvtbl;
      result = elvtbl->m_Items[gFld_ElvId]->floormax;
      break;
    case 1:
      v9 = gFldWarpBuff->elvtbl;
      result = v9->m_Items[gFld_ElvId]->se;
      break;
    case 2:
      v11 = gFldWarpBuff->elvtbl;
      floor = v11->m_Items[gFld_ElvId]->floor;
      result = floor->m_Items[0];
      break;
    case 3:
      v15 = gFldWarpBuff->elvtbl;
      v17 = v15->m_Items[gFld_ElvId]->floor;
      result = v17->m_Items[1];
      break;
    case 4:
      v19 = gFldWarpBuff->elvtbl;
      v21 = v19->m_Items[gFld_ElvId]->floor;
      result = v21->m_Items[2];
      break;
    case 5:
      v23 = gFldWarpBuff->elvtbl;
      v25 = v23->m_Items[gFld_ElvId]->floor;
      result = v25->m_Items[3];
      break;
    case 6:
      v27 = gFldWarpBuff->elvtbl;
      v29 = v27->m_Items[gFld_ElvId]->floor;
      result = v29->m_Items[4];
      break;
    case 7:
      v31 = gFldWarpBuff->elvtbl;
      v33 = v31->m_Items[gFld_ElvId]->floor;
      result = v33->m_Items[5];
      break;
    case 8:
      v35 = gFldWarpBuff->elvtbl;
      sblock = v35->m_Items[gFld_ElvId]->sblock;
      result = sblock->m_Items[0];
      break;
    case 9:
      v39 = gFldWarpBuff->elvtbl;
      v41 = v39->m_Items[gFld_ElvId]->sblock;
      result = v41->m_Items[1];
      break;
    case 10:
      v43 = gFldWarpBuff->elvtbl;
      v45 = v43->m_Items[gFld_ElvId]->sblock;
      result = v45->m_Items[2];
      break;
    case 11:
      v47 = gFldWarpBuff->elvtbl;
      v49 = v47->m_Items[gFld_ElvId]->sblock;
      result = v49->m_Items[3];
      break;
    case 12:
      v51 = gFldWarpBuff->elvtbl;
      v53 = v51->m_Items[gFld_ElvId]->sblock;
      result = v53->m_Items[4];
      break;
    case 13:
      v55 = gFldWarpBuff->elvtbl;
      v57 = v55->m_Items[gFld_ElvId]->sblock;
      result = v57->m_Items[5];
      break;
    case 14:
      v59 = gFldWarpBuff->elvtbl;
      result = ~gFld_ElvTakasa + v59->m_Items[gFld_ElvId]->floormax;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// 0x147f680
s32 fldDoor_GetHasigoTbl(s32 getmode) {
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
  v5 = static_fields[18];
  v6 = *(*static_fields + 24LL);
  v8 = *(v6 + 8 * v5 + 32);
  if (getmode == 2)
  {
    scene = dds3GetActiveScene();
    v11 = *(v8 + 48);
    v13 = ByteToString(v11);
      goto LABEL_35;
    goto LABEL_19;
  }
  if (getmode == 1)
  {
    scene = dds3GetActiveScene();
    v16 = *(v8 + 40);
    v18 = ByteToString(v16);
    v9 = dds3SceneBasicSearchName(&scene, v18);
    if (v9)
      goto LABEL_36;
    v20 = *(v8 + 48);
    v13 = ByteToString(v20);
    {
LABEL_35:
      v9 = dds3SceneBasicSearchName(&scene, v13);
      if (!v9)
        return v9;
LABEL_36:
      LODWORD(v9) = v9->serialID;
      return v9;
    }
LABEL_19:
    goto LABEL_35;
  }
  if (getmode)
    LODWORD(v9) = 0;
  else
    LODWORD(v9) = *(v8 + 32);
  return v9;
}

// 0x147a4a0
s32 fldDoor_GetWarpEff(void) {
  s32 *static_fields;
  s64 v4;
  s64 v5;

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
  s32 gFldSisetu_Fld;
  u64 *v4;
  System_String_o *v6;
  s32 v7;
  bool IsDLCField;
  s64 *v9;
  Il2CppObject *v11;
  AssetBundleCtrl_o *asset_bc;
  bool IsLoad;
  s32 *static_fields;
  s32 v18;
  s32 v19;
  s32 v20;
  u32 v22;
  u64 v23;
  struct doormovetbl_s_array *v25;
  doormovetbl_s_o *v27;
  struct doormovetbl_s_array *door_buff;
  s32 v35;
  s32 union08;
  s32 union09;
  u16 after_flag;
  s32 warp_attr;
  System_String_o *String_5280336;
  System_String_o *v48;
  s32 warp_bgm;
  System_String_o *v50;
  s32 warp_cammode;
  System_String_o *v52;
  System_String_o *v53;
  s32 v56;
  u64 *v57;
  char dest[136];
  fldSceneParam_t_o pParam;

  memset(&pParam, 0, sizeof(pParam));
  sub_F87580(&pParam);
  if (!gFldSisetu_Fld)
    return 1;
LABEL_6:
  *dest = gFldSisetu_Fld;
  v4 = sub_8D3950(s32, dest);
  v6 = Format("f{0:D3}", v4, 0);
  v7 = gFldSisetu_Fld;
  IsDLCField = IsDLCField(v7);
  v9 = &"m";
  if (!IsDLCField)
    v9 = &"";
  v11 = Concat_5224608(v6, *v9);
  Log(v11, 0);
  asset_bc = get_asset_bc();
  IsLoad = IsLoad(asset_bc, v11);
  if (IsLoad)
  {
    ReadAssets = 0;
    v18 = static_fields[11];
    v19 = static_fields[12];
    v20 = static_fields[13];
    fldDoorLoad(static_fields[10]);
    v22 = v19 - 3;
    if ((v19 - 3) >= 2)
    {
      v23 = 0;
      while (1)
      {
        door_buff = gFldWarpBuff->door_buff;
        v27 = door_buff->m_Items[v23];
        if ((!v27->flag || evtBitCheck(v27->flag))
          && v27->movetype == 7
          && v18 == v27->union01
          && v19 == v27->union03
          && v20 == v27->union04
          && !v27->warptype)
        {
          break;
        }
        if (v23++ >= 0xFF)
          return 1;
      }
    }
    else
    {
      v23 = 0;
      while (1)
      {
        v25 = gFldWarpBuff->door_buff;
        v27 = v25->m_Items[v23];
        if ((!v27->flag || evtBitCheck(v27->flag))
          && v27->movetype == 7
          && v19 == v27->union03
          && v20 == v27->union04
          && !v27->warptype)
        {
          break;
        }
        if (v23++ > 0xFE)
          return 1;
      }
    }
    union08 = v27->union08;
    if (!v27->union08)
    {
      union08 = gFldSisetu_Fld;
    }
    union09 = v27->union09;
    if (!v27->union09)
    {
      union09 = gFldSisetu_Area;
    }
    if (fldGb->fieldID != union08)
    {
      fldBgmFadeOut();
    }
    fldWap_SetBgm(v27);
    after_flag = v27->after_flag;
    if (after_flag)
    {
      gFldWap_after_flag = after_flag;
      Copy_3886320(v27->after_scr, gFldWap_after_scr, v27->after_scr->max_length);
      gFldWap_after_nextidx = v23 + 1;
    }
    MakeWarpIndex(v27);
    warp_attr = v27->warp_attr;
    gFldNowDZone = warp_attr;
    String_5280336 = CreateString_5280336(0, v27->warp_pos);
    v48 = Replace_5267216(String_5280336, " ", "");
    warp_bgm = v27->warp_bgm;
    v50 = v48;
    warp_cammode = v27->warp_cammode;
    v52 = CreateString_5280336(0, v27->warp_camname);
    v53 = Replace_5267216(v52, " ", "");
    fldSetSceneParam4(&pParam, union08, union09, v50, warp_bgm, warp_cammode, v53);
    if (v22 >= 2)
      v56 = 4;
    else
      v56 = 5;
    pParam.callmode = v56;
    gFldSisetu_Fld = 0;
    gFldSisetu_Area = 0;
    gFldSisetu_Type = 0;
    gFldSisetu_Idx = 0;
    memcpy(dest, &pParam, sizeof(dest));
    v57 = sub_8D3950(fldSceneParam_t, dest);
    dds3AdminiCallSequence(7, v57, 2, 0);
    return 1;
  }
  else
  {
    if (ReadAssets)
      return 0;
  }
  v35 = gFldSisetu_Fld;
  LoadField(v35);
  ReadAssets = 1;
  return 0;
}

// 0x147aca0
void fldDoor_Start(s32 evehit_resid) {
  s64 i;
  u64 v5;
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
      door_buff = gFldWarpBuff->door_buff;
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
  System_Array_o *v9;
  s32 v11;
  u64 v14;
  struct doormovework_s_array *door_work;
  doormovework_s_o *v18;
  s32 stat;
  s32 v20;
  s32 v22;
  u32 cnt1;
  s32 cntmax;
  f32 x1;
  f32 mx1;
  s32 cnt2;
  f32 x2;
  s32 v30;
  f32 y1;
  f32 my1;
  f32 v33;
  f32 v34;
  f32 v35;
  s32 v36;
  u32 v37;
  s32 v38;
  f32 v39;
  f32 mx2;
  f32 v42;
  f32 my2;
  f32 v44;
  f32 y2;
  f32 v47;
  f32 *p_z2;
  f32 z2;
  f32 v51;
  f32 *p_z1;
  f32 v53;
  f32 v54;
  f32 v55;
  f32 v56;
  f32 v57;
  f32 v58;
  f32 v59;
  s32 v60;
  f32 v62;
  f32 v63;
  f32 v64;
  f32 v65;
  f32 v67;
  f32 z1;
  f32 v70;
  f32 mz2;

  v9 = NewSpecific(f32, 0x32u);
  InitializeArray_1543888(v9, Field__PrivateImplementationDetails__D06E46ACE00EA24621D43E230A972753D152E916);
  if (fldGb->fieldID > 199)
    return 0;
  v14 = 0;
  while (1)
  {
    v18 = door_work->m_Items[v14];
    if (v18->matter_resid1 != matter_resid)
      break;
    stat = v18->stat;
    if (stat == 3)
    {
      if (v18->cnt1 > 19)
      {
        v18->cnt1 = 0;
        v18->stat = 1;
        goto LABEL_60;
      }
      y1 = v18->y1;
      my1 = v18->my1;
      v33 = v18->z1 - v18->mz1;
      v18->x1 = v18->x1 - v18->mx1;
      v18->y1 = y1 - my1;
      v18->z1 = v33;
      if (evtBitCheck(2803))
      {
        v34 = v18->y1 - v18->my1;
        v35 = v18->z1 - v18->mz1;
        v18->x1 = v18->x1 - v18->mx1;
        v18->y1 = v34;
        v18->z1 = v35;
      }
      goto LABEL_58;
    }
    if (stat == 2)
    {
      cnt1 = v18->cnt1;
      cntmax = v18->cntmax;
      if (cnt1 >= cntmax)
      {
        if (!evtBitCheck(2803))
          goto LABEL_60;
        v36 = 0;
        v18->stat = 3;
LABEL_59:
        v18->cnt1 = v36;
LABEL_60:
        *x = v18->x1;
        *y = v18->y1;
        *z = v18->z1;
        move_doorObject(v18, 0, v11);
        return 1;
      }
      x1 = v18->x1;
      mx1 = v18->mx1;
      if (cntmax == 40)
      {
        v62 = mx1 * *(&v9[2].klass + cnt1);
        v63 = v18->my1;
        v64 = x1 + v62;
        v65 = v18->y1;
        v18->x1 = v64;
        v67 = v65 + (v63 * *(&v9[2].klass + cnt1));
        p_z1 = &v18->z1;
        z1 = v18->z1;
        v18->y1 = v67;
        v57 = z1 + (v18->mz1 * *(&v9[2].klass + cnt1));
LABEL_57:
        *p_z1 = v57;
      }
      else
      {
        p_z1 = &v18->z1;
        v53 = v18->z1;
        v18->x1 = x1 + mx1;
        v54 = v53 + v18->mz1;
        v18->y1 = v18->y1 + v18->my1;
        v18->z1 = v54;
        if (evtBitCheck(2803))
        {
          v55 = v18->y1;
          v56 = v18->my1;
          v57 = v18->z1 + v18->mz1;
          v18->x1 = v18->x1 + v18->mx1;
          v18->y1 = v55 + v56;
          goto LABEL_57;
        }
      }
LABEL_58:
      v36 = v18->cnt1 + 1;
      goto LABEL_59;
    }
LABEL_20:
    if (v14++ >= 0xFF)
      return 0;
  }
  if (v18->matter_resid2 != matter_resid)
    goto LABEL_20;
  v20 = v18->stat;
  if (v20 == 3)
  {
    cnt2 = v18->cnt2;
    if (cnt2 < 20)
    {
      v30 = cnt2 + 1;
      v58 = v18->y2 - v18->my2;
      v59 = v18->z2 - v18->mz2;
      x2 = v18->x2 - v18->mx2;
      v18->x2 = x2;
      v18->y2 = v58;
      v18->z2 = v59;
    }
    else
    {
      x2 = v18->x2;
      v30 = 0;
    }
    v18->cnt2 = v30;
    *x = x2;
    goto LABEL_68;
  }
  if (v20 != 2)
    goto LABEL_20;
  v37 = v18->cnt2;
  v38 = v18->cntmax;
  if (v37 >= v38)
  {
    if (evtBitCheck(2803))
    {
      v60 = 0;
      goto LABEL_66;
    }
  }
  else
  {
    v39 = v18->x2;
    mx2 = v18->mx2;
    if (v38 == 40)
    {
      v42 = mx2 * *(&v9[2].klass + v37);
      my2 = v18->my2;
      v44 = v39 + v42;
      y2 = v18->y2;
      v18->x2 = v44;
      v47 = y2 + (my2 * *(&v9[2].klass + v37));
      p_z2 = &v18->z2;
      z2 = v18->z2;
      v18->y2 = v47;
      v51 = z2 + (v18->mz2 * *(&v9[2].klass + v37));
    }
    else
    {
      p_z2 = &v18->z2;
      v70 = v18->z2;
      v18->x2 = v39 + mx2;
      mz2 = v18->mz2;
      v18->y2 = v18->y2 + v18->my2;
      v51 = v70 + mz2;
    }
    *p_z2 = v51;
    v60 = v37 + 1;
LABEL_66:
    v18->cnt2 = v60;
  }
  *x = v18->x2;
LABEL_68:
  *y = v18->y2;
  *z = v18->z2;
  v22 = 1;
  move_doorObject(v18, 1, v11);
  return v22;
}

// 0x147d740
void fldDoor_Terminal(s32 type, s32 idx) {
  u32 v5;
  s32 v7;
  fldWap_c *v8;
  s32 v10;
  fldWap_c *v11;
  struct fldWap_StaticFields **p_static_fields;

  v5 = idx & 0xFFFFFFFE;
  if (!type)
  {
    if (v5 == 32)
    {
      v10 = DLCGetFieldNo(idx);
        goto LABEL_32;
    }
    else
    {
      v10 = *&_get_Item(
                fldHitData->_fldSaveNml,
                idx)->isLongReference;
        goto LABEL_32;
    }
LABEL_32:
    gFldSisetu_Fld = v10;
    if ((v11->_2.bitflags2 & 2) == 0)
    {
LABEL_35:
      gFldSisetu_Type = 3;
      goto LABEL_36;
    }
LABEL_33:
    goto LABEL_35;
  }
  if (v5 == 62)
  {
    v7 = DLCGetFieldNo(idx);
      goto LABEL_24;
  }
  else
  {
    v7 = *&_get_Item(
             fldHitData->_fldSaveSml,
             idx)->isLongReference;
      goto LABEL_24;
  }
LABEL_24:
  gFldSisetu_Fld = v7;
  if ((v8->_2.bitflags2 & 2) != 0)
    goto LABEL_25;
LABEL_27:
LABEL_36:
  (*p_static_fields)->gFldSisetu_Idx = idx;
}

// 0x147b7f0
void fldDoor_Warp(char **evename) {
  s32 gFldWap_after_nextidx;
  struct doormovetbl_s_array *door_buff;
  doormovetbl_s_o *v10;
  s32 union01;
  System_String_o *String_5280336;
  System_String_o *v13;
  s32 movetype;
  s16 union03;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  s16 union04;
  struct fldGlobalWork_t_o *v23;
  s32 v24;
  s32 v25;
  s32 union08;
  s32 union09;
  fldGlobal_c *v30;
  s64 v33;
  s32 v36;
  struct fldWap_StaticFields **p_static_fields;
  struct fldWap_StaticFields *v38;
  struct fldWap_StaticFields *v39;
  struct warp_elvtbl_s_array *elvtbl;
  s32 area;
  s32 v43;
  struct warp_elvtbl_s_array *v44;
  s64 gFld_ElvId;
  s64 v47;
  s64 gFld_ElvTakasa;
  s64 v49;
  s32 v51;
  struct fldGlobalWork_t_o *v55;
  s32 union10;
  s32 v57;
  s32 v58;
  s32 v62;
  u64 *v63;
  s32 v64;
  s32 v66;
  u64 *v67;
  s32 v68;
  s32 v71;
  u32 v74;
  s16 v77;
  u16 after_flag;
  s32 warp_attr;
  u32 v84;
  System_String_o *v85;
  System_String_o *v87;
  s32 warp_bgm;
  s32 warp_cammode;
  System_String_o *v91;
  System_String_o *v93;
  System_String_o *v94;
  System_String_o *v95;
  u32 monitor;
  s32 v98;
  s32 *v99;
  u32 v100;
  s32 v102;
  System_WeakReference_o *Item;
  struct fldSave_t_o *fldSave;
  Il2CppObject *data;
  char dest[136];
  fldSceneParam_t_o pParam;

  memset(&pParam, 0, sizeof(pParam));
  sub_F87580(&pParam);
  data = NewSpecific(s32, 2u);
  evtBitOff(1292);
  if (IsNullOrEmpty(*evename))
  {
    if (gFldWapPanel != 8)
      return;
  }
  gFldWap_after_nextidx = 0;
  while (1)
  {
    if ((byte_3F5989C & 1) == 0)
      goto LABEL_17;
LABEL_18:
    else
    {
      if (gFldWapPanel != 8)
        goto LABEL_25;
    }
LABEL_25:
    door_buff = gFldWarpBuff->door_buff;
    v10 = door_buff->m_Items[gFldWap_after_nextidx];
    if (!v10->flag || evtBitCheck(v10->flag))
    {
      if (v10->movetype)
      {
        union01 = v10->union01;
        String_5280336 = CreateString_5280336(0, v10->union02);
        v13 = Replace_5267216(String_5280336, " ", "");
        if (fldGb->areaID + 1 == union01)
          break;
      }
    }
LABEL_72:
    if (gFldWap_after_nextidx++ >= 255)
      return;
  }
  else if ((byte_3F5989C & 1) == 0)
  {
    goto LABEL_40;
  }
  if (gFldWapPanel != 8)
    goto LABEL_44;
LABEL_53:
  movetype = v10->movetype;
  if (movetype != 3)
    goto LABEL_62;
  union03 = v10->union03;
  if (union03)
  {
    fieldID = fldGb->fieldID;
    areaID = fldGb->areaID;
    fldAutoMapOpenBlock2(fieldID, areaID + 1, union03);
    movetype = v10->movetype;
LABEL_62:
    if (movetype == 10)
    {
      union04 = v10->union04;
      if (union04)
      {
        v23 = fldGb;
        v24 = v23->fieldID;
        v25 = v23->areaID;
        fldAutoMapOpenBlock2(v24, v25 + 1, union04);
      }
    }
  }
  switch (v10->warptype)
  {
    case 0u:
      union08 = v10->union08;
      if (!v10->union08)
      {
        union08 = fldGb->fieldID;
      }
      union09 = v10->union09;
      if (v10->union09)
      {
          goto LABEL_151;
        goto LABEL_149;
      }
      union09 = fldGb->areaID + 1;
      if ((v30->_2.bitflags2 & 2) != 0)
      {
LABEL_149:
      }
LABEL_151:
      if (fldGb->fieldID != union08)
      {
        fldBgmFadeOut();
      }
      v77 = fldWap_SetBgm(v10);
      after_flag = v10->after_flag;
      if (after_flag)
      {
        gFldWap_after_flag = after_flag;
        Copy_3886320(v10->after_scr, gFldWap_after_scr, v10->after_scr->max_length);
        gFldWap_after_nextidx = gFldWap_after_nextidx + 1;
      }
      MakeWarpIndex(v10);
      warp_attr = v10->warp_attr;
      gFldNowDZone = warp_attr;
      if (union08 <= 9)
      {
        fldPlayerCalc_FastStart();
      }
      if (v10->movetype - 3 > 1)
      {
        v93 = CreateString_5280336(0, v10->warp_pos);
        v94 = Replace_5267216(v93, " ", "");
        warp_bgm = v10->warp_bgm;
        v87 = v94;
        warp_cammode = v10->warp_cammode;
        v95 = CreateString_5280336(0, v10->warp_camname);
        v91 = Replace_5267216(v95, " ", "");
        {
LABEL_188:
          fldSetSceneParam4(&pParam, union08, union09, v87, warp_bgm, warp_cammode, v91);
          goto LABEL_193;
        }
LABEL_186:
        goto LABEL_188;
      }
      gfldPlayerAnaCnt = 15;
      dds3FadeOut(0, 0, 0, 0);
      v84 = v10->warp_cammode - 1;
      v85 = CreateString_5280336(0, v10->warp_pos);
      v87 = Replace_5267216(v85, " ", "");
      if (v84 <= 1)
      {
        warp_bgm = v10->warp_bgm;
        warp_cammode = v10->warp_cammode;
        v91 = CreateString_5280336(0, v10->warp_camname);
          goto LABEL_188;
        goto LABEL_186;
      }
      fldSetSceneParam3(&pParam, union08, union09, v87);
LABEL_193:
      pParam.bgmMode = v77;
LABEL_194:
      memcpy(dest, &pParam, sizeof(dest));
      v63 = sub_8D3950(fldSceneParam_t, dest);
      v64 = 7;
      v74 = 2;
LABEL_240:
      dds3AdminiCallSequence(v64, v63, v74, 0);
      break;
    case 1u:
      gFldNowDZone = 0;
      v33 = v10->union08 - 1LL;
      v36 = fldGb->fieldID;
      v38 = v39;
      elvtbl = gFldWarpBuff->elvtbl;
      area = elvtbl->m_Items[v33]->area;
      v38->gFld_ElvId = v33;
      (*p_static_fields)->gFld_ElvTakasa = v10->union09;
      v43 = fldGb->areaID;
      v44 = (*p_static_fields)->gFldWarpBuff->elvtbl;
      gFld_ElvId = (*p_static_fields)->gFld_ElvId;
      v47 = v44 + 8 * gFld_ElvId;
      gFld_ElvTakasa = (*p_static_fields)->gFld_ElvTakasa;
      v49 = *(*(v47 + 32) + 32LL);
      v51 = *(v49 + 2 * gFld_ElvTakasa + 32);
      fldAutoMapOpenBlock2(v36, v43 + 1, v51);
      fldSetSceneParam5(&pParam, v36, area, "01pos_01", 0, "elvstart_label");
      goto LABEL_194;
    case 2u:
      fldProcNext(0, 0);
      fldBgmFadeOut();
      v55 = fldGb;
      union10 = v10->union10;
      v58 = v55->fieldID;
      v57 = v55->areaID;
      fldAutoMapOpenBlock2(v58, v57 + 1, union10);
      v62 = fldGb->fieldID;
      gFldSisetu_Fld = v62;
      gFldSisetu_Area = fldGb->areaID + 1;
      gFldSisetu_Type = v10->union08;
      gFldSisetu_Idx = v10->union09;
      switch (v10->union08)
      {
        case 0:
          *dest = v10->union09;
          v63 = sub_8D3950(s32, dest);
          v64 = 29;
          goto LABEL_239;
        case 1:
          *dest = v10->union09;
          v63 = sub_8D3950(s32, dest);
          v64 = 30;
          goto LABEL_239;
        case 2:
          *dest = v10->union09;
          v63 = sub_8D3950(s32, dest);
          v64 = 28;
          goto LABEL_239;
        case 3:
          monitor = data[1].monitor;
          LODWORD(data[2].klass) = 0;
          v98 = v10->union09;
          HIDWORD(data[2].klass) = v98;
          v99 = &data[2].klass + 1;
          if (v98 != 32)
          {
            if (v98 != 33)
            {
              if (*(&_get_Item(
                        fldHitData->_fldSaveNml,
                        *v99)->isLongReference
                   + 1))
              {
                Item = _get_Item(
                         fldHitData->_fldSaveNml,
                         *v99);
                evtBitOn(*(&Item->isLongReference + 1), 0);
              }
            }
          }
          DDS3_GBWK->fldSave->tmnltype = data[2].klass;
          fldSave = DDS3_GBWK->fldSave;
          v64 = 32;
          v63 = data;
          fldSave->tmnlid = HIDWORD(data[2].klass);
          goto LABEL_239;
        case 4:
          v100 = data[1].monitor;
          LODWORD(data[2].klass) = 1;
          v102 = v10->union09;
          HIDWORD(data[2].klass) = v102;
          DDS3_GBWK->fldSave->tmnltype = data[2].klass;
          DDS3_GBWK->fldSave->tmnlid = HIDWORD(data[2].klass);
          v64 = 32;
          v63 = data;
          goto LABEL_239;
        case 5:
          v64 = 31;
          v63 = 0;
          v74 = 0;
          goto LABEL_240;
        default:
          return;
      }
      return;
    case 3u:
      v66 = v10->union08;
      {
        v67 = data;
      }
      else
      {
        v67 = data;
      }
      v68 = fldGb->fieldID;
      fldProcNext(v68, v66);
      fldBgmFadeOut();
      if (!v10->union09)
      {
        v71 = v10->union10;
        if (v71)
        {
          fldProcNext(v71, v66);
        }
      }
      if (v66 < 0x3E8u)
      {
        *dest = v66;
        v63 = sub_8D3950(s32, dest);
        v64 = 8;
LABEL_239:
        v74 = 4;
      }
      else
      {
        *(v67 + 8) = v66 - 1000;
        v74 = *(v67 + 6);
        *(v67 + 9) = fldGb->fieldID;
        v64 = 19;
        v63 = v67;
      }
      goto LABEL_240;
    default:
      goto LABEL_72;
  }
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
          goto LABEL_22;
      }
      else
      {
        union08 = fldGb->fieldID;
        union09 = v7->union09;
        if (v7->union09)
        {
LABEL_22:
          if (v7->warptype)
            continue;
          goto LABEL_23;
        }
      }
      union09 = fldGb->areaID + 1;
      if (v7->warptype)
        continue;
LABEL_23:
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
  u64 *v3;
  u64 *v5;
  s64 i;
  u64 v8;
  struct doormovetbl_s_array *door_buff;
  s64 v11;
  s32 fieldID;
  s32 v14;
  fldGlobal_c *v15;
  s64 v16;
  s32 v20;
  struct fldWap_StaticFields **p_static_fields;
  struct fldWap_StaticFields *v22;
  struct fldWap_StaticFields *v23;
  struct warp_elvtbl_s_array *elvtbl;
  s32 area;
  s32 areaID;
  struct warp_elvtbl_s_array *v28;
  s64 gFld_ElvId;
  struct System_Int16_array *sblock;
  s64 gFld_ElvTakasa;
  s32 v34;
  struct fldGlobalWork_t_o *fldGb;
  s32 v40;
  s32 v41;
  s32 v42;
  s32 v46;
  u64 *v47;
  s32 v48;
  s32 v50;
  s32 v51;
  s32 v54;
  u32 v57;
  s16 v60;
  u16 v61;
  s32 v65;
  s32 v67;
  System_String_o *v68;
  System_String_o *v70;
  System_String_o *String_5280336;
  s32 v72;
  s32 v73;
  System_String_o *v74;
  System_String_o *v76;
  u32 v77;
  s32 v78;
  u32 v80;
  System_WeakReference_o *Item;
  struct fldSave_t_o *fldSave;
  char dest[136];
  fldSceneParam_t_o pParam;

  memset(&pParam, 0, sizeof(pParam));
  sub_F87580(&pParam);
  v3 = NewSpecific(s32, 2u);
  if (ex_no)
  {
    v5 = v3;
    for (i = 4; ; ++i)
    {
      v8 = i - 4;
      door_buff = gFldWarpBuff->door_buff;
      v11 = *(&door_buff->obj.klass + i);
      if ((!*(v11 + 20) || evtBitCheck(*(v11 + 20), 0)) && *(v11 + 16) == 9 && *(v11 + 32) == ex_no)
        break;
LABEL_14:
      if (v8 >= 0xFF)
        return;
    }
    switch (*(v11 + 56))
    {
      case 0:
        fieldID = *(v11 + 60);
        if (!*(v11 + 60))
        {
          fieldID = fldGb->fieldID;
        }
        v14 = *(v11 + 62);
        if (*(v11 + 62))
        {
            goto LABEL_92;
          goto LABEL_90;
        }
        v14 = fldGb->areaID + 1;
        if ((v15->_2.bitflags2 & 2) != 0)
        {
LABEL_90:
        }
LABEL_92:
        if (fldGb->fieldID != fieldID)
        {
          fldBgmFadeOut();
        }
        v60 = fldWap_SetBgm(v11);
        v61 = *(v11 + 100);
        if (v61)
        {
          gFldWap_after_flag = v61;
          Copy_3886320(*(v11 + 104), gFldWap_after_scr, *(*(v11 + 104) + 24LL), 0);
          gFldWap_after_nextidx = i - 3;
        }
        MakeWarpIndex(v11);
        v65 = *(v11 + 58);
        gFldNowDZone = v65;
        if (fieldID <= 9)
        {
          fldPlayerCalc_FastStart();
        }
        if (*(v11 + 16) - 3 > 1)
        {
          String_5280336 = CreateString_5280336(0, *(v11 + 72), 0);
          v70 = Replace_5267216(String_5280336, " ", "");
        }
        else
        {
          gfldPlayerAnaCnt = 15;
          v67 = *(v11 + 80);
          v68 = CreateString_5280336(0, *(v11 + 72), 0);
          v70 = Replace_5267216(v68, " ", "");
          if (v67 != 1)
          {
            fldSetSceneParam3(&pParam, fieldID, v14, v70);
            goto LABEL_130;
          }
        }
        v72 = *(v11 + 96);
        v73 = *(v11 + 80);
        v74 = CreateString_5280336(0, *(v11 + 88), 0);
        v76 = Replace_5267216(v74, " ", "");
        fldSetSceneParam4(&pParam, fieldID, v14, v70, v72, v73, v76);
LABEL_130:
        pParam.bgmMode = v60;
LABEL_131:
        memcpy(dest, &pParam, sizeof(dest));
        v47 = sub_8D3950(fldSceneParam_t, dest);
        v48 = 7;
        v57 = 2;
LABEL_167:
        dds3AdminiCallSequence(v48, v47, v57, 0);
        break;
      case 1:
        v16 = *(v11 + 60) - 1LL;
        v20 = fldGb->fieldID;
        v22 = v23;
        elvtbl = gFldWarpBuff->elvtbl;
        area = elvtbl->m_Items[v16]->area;
        v22->gFld_ElvId = v16;
        (*p_static_fields)->gFld_ElvTakasa = *(v11 + 62);
        areaID = fldGb->areaID;
        v28 = (*p_static_fields)->gFldWarpBuff->elvtbl;
        gFld_ElvId = (*p_static_fields)->gFld_ElvId;
        sblock = v28->m_Items[gFld_ElvId]->sblock;
        gFld_ElvTakasa = (*p_static_fields)->gFld_ElvTakasa;
        v34 = sblock->m_Items[gFld_ElvTakasa];
        fldAutoMapOpenBlock2(v20, areaID + 1, v34);
        fldSetSceneParam5(&pParam, v20, area, "01pos_01", 0, "elvstart_label");
        goto LABEL_131;
      case 2:
        fldBgmFadeOut();
        dds3FadeIn2(0xFu);
        v40 = fldGb->fieldID;
        v41 = fldGb->areaID;
        v42 = *(v11 + 64);
        fldAutoMapOpenBlock2(v40, v41 + 1, v42);
        v46 = fldGb->fieldID;
        gFldSisetu_Fld = v46;
        gFldSisetu_Area = fldGb->areaID + 1;
        gFldSisetu_Type = *(v11 + 60);
        gFldSisetu_Idx = *(v11 + 62);
        switch (*(v11 + 60))
        {
          case 0:
            *dest = *(v11 + 62);
            v47 = sub_8D3950(s32, dest);
            v48 = 29;
            goto LABEL_166;
          case 1:
            *dest = *(v11 + 62);
            v47 = sub_8D3950(s32, dest);
            v48 = 30;
            goto LABEL_166;
          case 2:
            *dest = *(v11 + 62);
            v47 = sub_8D3950(s32, dest);
            v48 = 28;
            goto LABEL_166;
          case 3:
            v77 = *(v5 + 6);
            *(v5 + 8) = 0;
            v78 = *(v11 + 62);
            *(v5 + 9) = v78;
            if (*(&_get_Item(
                      fldHitData->_fldSaveNml,
                      *(v5 + 9))->isLongReference
                 + 1))
            {
              Item = _get_Item(
                       fldHitData->_fldSaveNml,
                       *(v5 + 9));
              evtBitOn(*(&Item->isLongReference + 1), 0);
            }
              goto LABEL_159;
            goto LABEL_161;
          case 4:
            v80 = *(v5 + 6);
            *(v5 + 8) = 1;
            *(v5 + 9) = *(v11 + 62);
              goto LABEL_161;
LABEL_159:
LABEL_161:
            DDS3_GBWK->fldSave->tmnltype = *(v5 + 8);
            fldSave = DDS3_GBWK->fldSave;
            v48 = 32;
            v47 = v5;
            fldSave->tmnlid = *(v5 + 9);
            goto LABEL_166;
          case 5:
            v48 = 31;
            v47 = 0;
            v57 = 0;
            goto LABEL_167;
          default:
            return;
        }
      case 3:
        v50 = *(v11 + 60);
        v51 = fldGb->fieldID;
        fldProcNext(v51, v50);
        fldBgmFadeOut();
        if (!*(v11 + 62))
        {
          v54 = *(v11 + 64);
          if (v54)
          {
            fldProcNext(v54, v50);
          }
        }
        if (v50 < 0x3E8u)
        {
          *dest = v50;
          v47 = sub_8D3950(s32, dest);
          v48 = 8;
LABEL_166:
          v57 = 4;
        }
        else
        {
          *(v5 + 8) = v50 - 1000;
          v57 = *(v5 + 6);
          *(v5 + 9) = fldGb->fieldID;
          v48 = 19;
          v47 = v5;
        }
        goto LABEL_167;
      default:
        goto LABEL_14;
    }
  }
}

// 0x147a540
s32 fldWapGetDoor(s32 getmode) {
  s32 *static_fields;
  s64 v4;
  s64 v5;
  u16 *v7;
  s32 v8;
  s32 result;
  s32 v10;

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
  s64 *v8;
  s32 v9;
  System_Collections_Generic_List_WeakReference__o **p_fldSaveSml;
  s32 v12;
  bool IsDLCField;
  s64 *v14;
  System_String_o *v15;
  u64 *v16;
  System_String_o *v17;
  System_String_o *v19;
  AssetBundleCtrl_o *asset_bc;
  s64 i;
  u64 v25;
  struct doormovetbl_s_array *door_buff;
  s64 v28;
  u16 v31;
  s32 v35;
  s16 v36;
  s32 v37;
  System_String_o *String_5280336;
  System_String_o *v39;
  s32 v40;
  System_String_o *v41;
  s32 v42;
  System_String_o *v43;
  System_String_o *v45;
  s32 v48;
  struct fldGlobalWork_t_o *fldGb;
  s32 v50;
  s32 v51;

  if (tmnltype)
  {
    v8 = &Method_System_Collections_Generic_List_fldSaveSml_t__get_Item__;
    v9 = 4;
    p_fldSaveSml = &fldHitData->_fldSaveSml;
  }
  else
  {
    v8 = &Method_System_Collections_Generic_List_fldSaveNml_t__get_Item__;
    v9 = 3;
    p_fldSaveSml = &fldHitData->_fldSaveNml;
  }
  v12 = *&_get_Item(*p_fldSaveSml, tmnlid, *v8)->isLongReference;
  IsDLCField = IsDLCField(v12);
  v14 = &"m";
  if (!IsDLCField)
    v14 = &"";
  v15 = *v14;
  v51 = v12;
  v16 = sub_8D3950(s32, &v51);
  v17 = Format("f{0:D3}", v16, 0);
  v19 = Concat_5224608(v17, v15);
  asset_bc = get_asset_bc();
  if (IsLoad(asset_bc, v19))
  {
    if (v12)
    {
      fldDoorLoad(v12);
      for (i = 4; ; ++i)
      {
        v25 = i - 4;
        door_buff = gFldWarpBuff->door_buff;
        v28 = *(&door_buff->obj.klass + i);
        if ((!*(v28 + 20) || evtBitCheck(*(v28 + 20), 0))
          && *(v28 + 16) == 7
          && v9 == *(v28 + 32)
          && *(v28 + 34) == tmnlid
          && !*(v28 + 56))
        {
          break;
        }
        if (v25 >= 0xFF)
          return 1;
      }
      fldGb->CamTableIdx = *(v28 + 82);
      v31 = *(v28 + 100);
      if (v31)
      {
        gFldWap_after_flag = v31;
        Copy_3886320(*(v28 + 104), gFldWap_after_scr, *(*(v28 + 104) + 24LL), 0);
        gFldWap_after_nextidx = i - 3;
      }
      MakeWarpIndex(v28);
      v35 = *(v28 + 58);
      gFldNowDZone = v35;
      if (*(v28 + 60))
        v12 = *(v28 + 60);
      v36 = *(v28 + 62);
      if (!v36)
        v36 = 1;
      if (v12)
      {
        v37 = v36;
        String_5280336 = CreateString_5280336(0, *(v28 + 72), 0);
        v39 = Replace_5267216(String_5280336, " ", "");
        v40 = *(v28 + 96);
        v41 = v39;
        v42 = *(v28 + 80);
        v43 = CreateString_5280336(0, *(v28 + 88), 0);
        v45 = Replace_5267216(v43, " ", "");
        fldSetSceneParamLoad(param, v12, v37, v41, v40, v42, v45);
        param->callmode = 5;
        v48 = *(v28 + 96);
        if (*(v28 + 96))
        {
          if (fldGb->BgmId != v48)
          {
            fldGb->BgmId = v48;
          }
        }
        v50 = *(v28 + 98);
        if (*(v28 + 98))
        {
          fldGb->FootSE = v50 - 1;
        }
      }
    }
    return 1;
  }
  else
  {
    LoadAssetExt(v19, v19, v15);
    return 0;
  }
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
  s32 v19;

  fieldID = fldGb->fieldID;
  if (fieldID == 34)
    goto LABEL_58;
  else if (fieldID == 32)
  {
    goto LABEL_58;
  }
  else if (fieldID == 37)
  {
    goto LABEL_58;
  }
  if (fieldID == 36)
    goto LABEL_58;
  if (fieldID == 41)
    goto LABEL_58;
  if (fieldID == 42)
    goto LABEL_58;
  if (fieldID == 43)
    goto LABEL_58;
  if (fieldID == 44)
    goto LABEL_58;
  if (fieldID == 45)
    goto LABEL_58;
  BgmId = fldGb->BgmId;
  warp_bgm = pWap->warp_bgm;
  if (BgmId == warp_bgm)
  {
LABEL_58:
    v8 = 0;
    warp_foot = pWap->warp_foot;
    if (!pWap->warp_foot)
      goto LABEL_96;
    goto LABEL_59;
  }
  v8 = fldBgmTransChk(BgmId, warp_bgm);
  if (pWap->warp_bgm)
  {
    if (v8 == 1)
    {
      v19 = fldGb->BgmId;
      gFldSndTransSrc = v19;
      v9 = 1;
        goto LABEL_90;
    }
    else if (v8)
    {
      v9 = 0;
      {
LABEL_90:
        fldGb->BgmId = pWap->warp_bgm;
        if (v9)
        {
          fldBgmTrans();
        }
LABEL_95:
        warp_foot = pWap->warp_foot;
        if (!pWap->warp_foot)
          goto LABEL_96;
        goto LABEL_59;
      }
    }
    else
    {
      fldBgmFadeOut();
      v9 = 0;
        goto LABEL_90;
    }
    goto LABEL_90;
  }
  if (v8 != 1)
    goto LABEL_95;
  v14 = fldGb->BgmId;
  gFldSndTransSrc = v14;
  fldGb->BgmId = 1;
  fldBgmTrans();
  v8 = 1;
  warp_foot = pWap->warp_foot;
  if (!pWap->warp_foot)
  {
LABEL_96:
    if ((v12->_2.bitflags2 & 2) == 0)
      goto LABEL_99;
    goto LABEL_97;
  }
LABEL_59:
  fldGb->FootSE = warp_foot - 1;
  if ((v12->_2.bitflags2 & 2) != 0)
  {
LABEL_97:
  }
LABEL_99:
  fldGb->CamTableIdx = pWap->warp_camtbl;
  return v8;
}

// 0x147e520
bool fldWap_Suspend(s32 fld, s32 area, s32 CamIdx, s32 BgmId, s32 SeId, s32 WapIdx, fldSceneParam_t *param) {
  bool IsDLCField;
  s64 *v15;
  System_String_o *v16;
  u64 *v17;
  System_String_o *v18;
  System_String_o *v20;
  AssetBundleCtrl_o *asset_bc;
  s64 v23;
  s32 v24;
  s32 v26;
  s32 v28;
  System_String_o *v29;
  s32 v33;
  System_String_o *camname;
  s32 cammode;

  cammode = 0;
  camname = 0;
  IsDLCField = IsDLCField(fld);
  v15 = &"m";
  if (!IsDLCField)
    v15 = &"";
  v16 = *v15;
  v33 = fld;
  v17 = sub_8D3950(s32, &v33);
  v18 = Format("f{0:D3}", v17, 0);
  v20 = Concat_5224608(v18, v16);
  asset_bc = get_asset_bc();
  if (IsLoad(asset_bc, v20))
  {
    if (fld)
    {
      fldDoorLoad(fld);
      if (area)
      {
        cammode = 0;
        camname = "";
        GetCameraType(v26, v23, WapIdx, v24, &cammode, &camname);
        v28 = cammode;
        v29 = camname;
        fldSetSceneParamLoad(param, fld, area, "", BgmId, v28, v29);
        param->callmode = 5;
        fldGb->BgmId = BgmId;
        fldGb->FootSE = SeId;
      }
    }
    return 1;
  }
  else
  {
    LoadAssetExt(v20, v20, v16);
    return 0;
  }
}

// 0x1481f90
void move_doorObject(doormovework_s *door, s32 lr, s32 oc) {
  Il2CppObject *v6;
  s64 v8;
  u32 v9;
  UnityEngine_GameObject_o *FildMapObj;
  UnityEngine_Object_o *Component_object;
  dds3ModelFileTable_t_array *v17;
  u64 *v18;
  s32 Index_dds3ModelFileTable_t;
  u32 *monitor;
  s64 v21;
  UnityEngine_GameObject_o *fields;
  UnityEngine_Transform_o *transform;
  dds3Basic_t_o *v26;
  System_String_o *name;
  f32 *p_z2;
  f32 v31;
  f32 v32;
  u64 v33;
  f32 v34;
  UnityEngine_Vector3_o v35;
  UnityEngine_Vector3_o v36;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector3_o localPosition;

  pBasic = 0;
  v36.z = 0.0;
  *&v36.x = 0;
  v6 = Allocate(fldWap___c__DisplayClass50_0);
  _ctor(v6, 0);
  v8 = 28;
  if (lr)
    v8 = 36;
  v9 = *(&door->klass + v8);
  if (v9 != -1)
  {
    if (!op_Equality(FildMapObj, 0, 0))
    {
      get_transform(FildMapObj, 0);
      pBasic = dds3GetControlScene();
      v6[1].klass = dds3SearchSceneBasic(&pBasic, v9, 6u);
      Component_object = GetComponent_object_(FildMapObj);
      if (op_Equality(Component_object, 0, 0)
        || (v17 = Component_object[1].monitor,
            v18 = Allocate(System_Predicate_GameObject_),
            __ctor(
              v18,
              v6,
              Method_fldWap___c__DisplayClass50_0__move_doorObject_b__0__),
            Index_dds3ModelFileTable_t = FindIndex_dds3ModelFileTable_t_(v17, v18),
            Index_dds3ModelFileTable_t == -1))
      {
        fields = v6[1].klass->_1.fields;
        {
LABEL_30:
          if (!op_Equality(fields, 0, 0))
          {
            transform = get_transform(fields, 0);
            localPosition = get_localPosition(transform);
            v26 = pBasic;
            v36 = localPosition;
            name = get_name(fields);
            if (!IsMoverControl(v26, name))
            {
              if (lr)
              {
                p_z2 = &door->z2;
                v31 = door->x2 / -100.0;
                v32 = door->y2 / -100.0;
                v36.x = v31;
                v36.y = v32;
                v33 = __PAIR64__(LODWORD(v32), LODWORD(v31));
              }
              else
              {
                v36.x = door->x1 / -100.0;
                v36.y = door->y1 / -100.0;
                p_z2 = &door->z1;
                v33 = *&v36.x;
              }
              v34 = *p_z2 / -100.0;
              v35.z = 0.0;
              v36.z = v34;
              *&v35.x = 0;
              sub_8524C0(&v35.x, *&v33, *(&v33 + 1), v34);
              set_localPosition(transform, v35);
            }
          }
          return;
        }
      }
      else
      {
        monitor = Component_object[1].monitor;
        v21 = Index_dds3ModelFileTable_t;
        fields = *&monitor[2 * v21 + 8];
          goto LABEL_30;
      }
      goto LABEL_30;
    }
  }
}
