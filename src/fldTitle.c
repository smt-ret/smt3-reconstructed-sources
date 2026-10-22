#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fldTitleName fldTitleName;
typedef struct sdfTexHandle_t sdfTexHandle_t;

static s32 gfldTitleCnt;
static s32 gfldTitleStep;
static s32 gfldTitleID;
static s32 gfldTitleWait;
static bool gfldTitleDelete;
static sdfTexHandle_t *hFldTitleName;
static sdfTexHandle_t *hFldTitle01;
static sdfTexHandle_t *hFldTitle02;
static sdfTexHandle_t *hFldTitle03;
static s32 gfldTitleMiniCnt;
static s32 gfldTitleMiniStep;
static s32 gfldTitleMiniID;
static bool gfldTitleMiniDelete;
static sdfTexHandle_t *hFldTitleMiniName;
static sdfTexHandle_t *hFldTitleMini04;
static void *tit_obj;
static fldTitleName *tit_scr;
static char *langTbl[8];

s32 GetLanguage(void);
bool IsDLCField(s32 area);
bool IsFinished(fldTitleName *this);
bool IsFinishedMini(fldTitleName *this);
bool IsLoad(AssetBundles *this, char *key);
void LoadAssetExt(char *key, char *name, char *dlc);
void *LoadFile(AssetBundleCtrl *this, char *key, char *path, char *name, char *extension);
void **LoadSprite(AssetBundleCtrl *this, char *key, char *path, char *name);
void SetSprite(fldTitleName *this, bool amara, void **a, void **b);
void StartAnim(fldTitleName *this, bool in1st, s32 timer);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
bool evtBitCheck(s32 no);
void evtBitOn(s32 no);

// 0x178ea30
s32 fldTitleChk(void) {
  return dds3SearchProcessName("fldTitle") != 0;
}

// 0x178eab0
void *fldTitleDrawProc(dds3ProcessID_t *aProcId) {
  UnityEngine_Object_o *tit_scr;
  bool v6;
  s32 gfldTitleStep;
  s32 v31;
  s32 gfldTitleWait;
  bool v49;

  else
  {
    if (gfldTitleStep > 89)
      goto LABEL_20;
  }
  v6 = op_Equality(tit_scr, 0, 0);
  if (v6)
  {
      goto LABEL_56;
    goto LABEL_17;
  }
LABEL_20:
  else
  {
    if (gfldTitleStep > 2)
      goto LABEL_23;
  }
  if (gfldTitleStep)
  {
    if (gfldTitleStep == 1)
    {
      if (!IsFinished(tit_scr, 0))
      {
        v31 = 3;
        goto LABEL_89;
      }
    }
  }
  else
  {
    v49 = __OFSUB__(gfldTitleWait--, 1);
    if ((gfldTitleWait < 0) ^ v49 | (gfldTitleWait == 0))
    {
      StartAnim(tit_scr, 1, gfldTitleWait);
      gfldTitleStep = 1;
    }
  }
  return 0;
}

// 0x178f720
s32 fldTitleMiniChk(void) {
  return dds3SearchProcessName("fldTitleMini") != 0;
}

// 0x178f7a0
dds3ProcessFunc_t *fldTitleMiniDrawProc(dds3ProcessID_t *aProcId) {
  UnityEngine_Object_o *tit_scr;
  bool v6;
  UnityEngine_Object_o *tit_obj;
  u32 gfldTitleMiniStep;
  UnityEngine_Object_o *v33;

  else
  {
    if (gfldTitleMiniStep > 89)
      goto LABEL_20;
  }
  v6 = op_Equality(tit_scr, 0, 0);
  if (v6)
  {
    {
LABEL_17:
    }
LABEL_63:
    if (op_Inequality(tit_obj, 0, 0))
    {
      v33 = tit_obj;
      Destroy_27360000(v33);
    }
    aProcId->func_ans = -1;
    return 0;
  }
LABEL_20:
  else
  {
  }
  switch (gfldTitleMiniStep)
  {
    case 0u:
      StartAnim(tit_scr, 0, 0);
      goto LABEL_28;
    case 1u:
      else
      {
        gfldTitleMiniStep = 2;
      }
      break;
    case 2u:
      if (IsFinishedMini(tit_scr))
        return 0;
      goto LABEL_58;
    case 3u:
        goto LABEL_63;
      goto LABEL_17;
    default:
      goto LABEL_30;
  }
  return 0;
}

// 0x178fdc0
dds3ProcessFunc_t *fldTitleMiniShutDown(dds3ProcessID_t *id) {
  UnityEngine_Object_o *tit_obj;
  UnityEngine_Object_o *v6;

  if (op_Inequality(tit_obj, 0, 0))
  {
    v6 = tit_obj;
    Destroy_27360000(v6);
  }
  if (hFldTitleMiniName)
  {
    hFldTitleMiniName = 0;
  }
  if (hFldTitleMini04)
  {
    hFldTitleMini04 = 0;
  }
  return 0;
}

// 0x178ff40
void fldTitleMiniStart(s32 fld) {
  s32 areaID;
  s32 v9;
  AssetBundleCtrl_o *asset_bc;
  UnityEngine_Object_o *File;
  UnityEngine_Object_o *v13;
  UnityEngine_GameObject_o *v14;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v18;
  Il2CppObject *Component_object;
  Il2CppObject *v24;
  u64 *v26;
  System_String_o *v28;
  bool IsDLCField;
  s64 *v30;
  System_String_o *v31;
  System_String_o *v33;
  bool v34;
  fldTitle_c *v36;
  s16 v37;
  s32 v38;
  AssetBundleCtrl_o *v40;
  u64 *v41;
  u64 *v42;
  s32 v44;

  if (fld >= 10)
  {
    switch (fld)
    {
      case 11:
        if (evtBitCheck(1087))
          goto LABEL_96;
        return;
      case 12:
        if (fldGb->areaID != 1)
          goto LABEL_96;
        return;
      case 13:
        if (evtBitCheck(1219))
          goto LABEL_96;
        return;
      case 14:
        if (evtBitCheck(1056))
          goto LABEL_96;
        return;
      case 15:
        if (evtBitCheck(1088))
        {
          areaID = fldGb->areaID;
          if (areaID != 20)
          {
            if (areaID != 19)
              goto LABEL_96;
          }
        }
        return;
      case 16:
        if (evtBitCheck(1120))
          goto LABEL_96;
        return;
      case 17:
        if (evtBitCheck(1152))
          goto LABEL_96;
        return;
      case 18:
        if (evtBitCheck(1184))
          goto LABEL_96;
        return;
      case 19:
        if (evtBitCheck(1216))
          goto LABEL_96;
        return;
      case 20:
        if (evtBitCheck(1248))
          goto LABEL_96;
        return;
      case 21:
        if (evtBitCheck(1280))
          goto LABEL_96;
        return;
      case 22:
        if (evtBitCheck(1312))
          goto LABEL_96;
        return;
      case 23:
        if (evtBitCheck(1344))
          goto LABEL_96;
        return;
      case 24:
        if (evtBitCheck(1376))
          goto LABEL_96;
        return;
      case 25:
        if (evtBitCheck(1408))
          goto LABEL_96;
        return;
      case 26:
        if (evtBitCheck(1440))
          goto LABEL_96;
        return;
      case 27:
        if (evtBitCheck(1472))
          goto LABEL_96;
        return;
      case 28:
        if (evtBitCheck(1504))
          goto LABEL_96;
        return;
      case 29:
        if (evtBitCheck(1536))
          goto LABEL_96;
        return;
      case 30:
        if (evtBitCheck(1568))
          goto LABEL_96;
        return;
      case 31:
        if (evtBitCheck(1600))
          goto LABEL_96;
        return;
      case 32:
        if (evtBitCheck(1632))
          goto LABEL_96;
        return;
      case 33:
        if (evtBitCheck(1664))
          goto LABEL_96;
        return;
      case 34:
        if (evtBitCheck(1696))
        {
          if (fldGb->areaID != 2)
            goto LABEL_96;
        }
        return;
      case 35:
        if (evtBitCheck(1760))
          goto LABEL_96;
        return;
      case 38:
        if (evtBitCheck(1808))
          goto LABEL_96;
        return;
      case 40:
        if (evtBitCheck(1872))
          goto LABEL_96;
        return;
      case 41:
        if (evtBitCheck(1888))
          goto LABEL_96;
        return;
      case 42:
        if (evtBitCheck(1920))
          goto LABEL_96;
        return;
      case 43:
        if (evtBitCheck(1952))
          goto LABEL_96;
        return;
      case 44:
        if (evtBitCheck(1984))
          goto LABEL_96;
        return;
      case 45:
        if (evtBitCheck(2016))
          goto LABEL_96;
        return;
      case 60:
        if (evtBitCheck(960))
        {
          v9 = fldGb->areaID;
          if (v9 != 19)
          {
            if (v9 != 20)
              goto LABEL_95;
          }
        }
        return;
      case 61:
        if (evtBitCheck(962))
        {
LABEL_95:
          evtBitOn(965);
          goto LABEL_96;
        }
        return;
      default:
LABEL_96:
        asset_bc = get_asset_bc();
        File = LoadFile(asset_bc, "common", "dds3data/UI", "fldName", ".prefab");
        if (File)
        {
          if (File->klass == UnityEngine_GameObject)
            v13 = File;
          else
            v13 = 0;
        }
        else
        {
          v13 = 0;
        }
        if (op_Equality(v13, 0, 0))
          return;
        v14 = Find("Canvas_UI", 0);
        transform = get_transform(v14, 0);
        v18 = Instantiate_object__425520(v13, transform);
        tit_obj = v18;
        set_name(tit_obj, "fldName");
        Component_object = GetComponent_object_(tit_obj);
        if (op_Equality(Component_object, 0, 0))
        {
          AddComponent_object_(tit_obj);
        }
        v24 = GetComponent_object_(tit_obj);
        tit_scr = v24;
        gfldTitleMiniCnt = 0;
        gfldTitleMiniStep = 99;
        gfldTitleMiniDelete = 0;
        v44 = fld;
        v26 = sub_8D3950(s32, &v44);
        v28 = Format("f{0:D3}", v26, 0);
        IsDLCField = IsDLCField(fld);
        v30 = &"m";
        if (!IsDLCField)
          v30 = &"";
        v31 = *v30;
        v33 = Concat_5224608(v28, *v30);
        v34 = IsDLCField(fld);
        if ((fld & 0xFFFFFFFE) == 0x3C || v34)
        {
          v40 = get_asset_bc();
          if (!IsLoad(v40, v33))
          {
            LoadAssetExt(v33, v33, v31);
          }
          gfldTitleMiniStep = 98;
          v37 = *&v36->_2.bitflags1;
          if ((v37 & 0x200) != 0)
          {
LABEL_133:
            v38 = v37 & 0x200;
            if (gfldTitleMiniID != fld)
            {
LABEL_136:
              gfldTitleMiniID = fld;
              if ((v36->_2.bitflags2 & 2) == 0)
                goto LABEL_160;
              goto LABEL_158;
            }
LABEL_154:
            gfldTitleMiniStep = 3;
            if ((v36->_2.bitflags2 & 2) == 0)
              goto LABEL_160;
LABEL_158:
LABEL_160:
            if (!dds3SearchProcessName("fldTitle"))
            {
              v41 = Allocate(System_Func_dds3ProcessID_t__object_);
              object____ctor(
                v41,
                0,
                Method_fldTitle_fldTitleMiniDrawProc__);
              v42 = Allocate(System_Func_dds3ProcessID_t__object_);
              object____ctor(
                v42,
                0,
                Method_fldTitle_fldTitleMiniShutDown__);
              dds3StartProcess("fldTitleMini", 0x2B0Au, 0, 1, v41, 0, v42, 0, 0, 0);
            }
            return;
          }
        }
        else
        {
          if ((v37 & 0x200) != 0)
            goto LABEL_133;
        }
        v38 = 0;
        if (gfldTitleMiniID != fld)
          goto LABEL_136;
        goto LABEL_154;
    }
  }
}

// 0x17908a0
void fldTitleMiniStart2(void) {
  fldTitle_c *v2;
  s32 gfldTitleMiniID;
  s32 fieldID;

  if (gfldTitleMiniStep != 3)
    goto LABEL_24;
LABEL_6:
  fieldID = fldGb->fieldID;
  if (gfldTitleMiniID == fieldID)
  {
      goto LABEL_26;
  }
  else
  {
    gfldTitleMiniID = fieldID;
    if ((v2->_2.bitflags2 & 2) == 0)
    {
LABEL_26:
      if (gfldTitleMiniStep != 4)
        return;
      goto LABEL_27;
    }
  }
LABEL_25:
    goto LABEL_26;
  if (gfldTitleMiniStep != 4)
    return;
LABEL_27:
  gfldTitleMiniStep = 0;
}

// 0x178f0d0
dds3ProcessFunc_t *fldTitleShutDown(dds3ProcessID_t *id) {
  if (hFldTitleName)
  {
    hFldTitleName = 0;
  }
  if (hFldTitle01)
  {
    hFldTitle01 = 0;
  }
  if (hFldTitle02)
  {
    hFldTitle02 = 0;
  }
  if (hFldTitle03)
  {
    hFldTitle03 = 0;
  }
  return 0;
}

// 0x178f230
void fldTitleStart(s32 fld, s32 waittime) {
  AssetBundleCtrl_o *asset_bc;
  UnityEngine_Object_o *File;
  Il2CppObject *v8;
  UnityEngine_GameObject_o *v9;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v13;
  Il2CppObject *Component_object;
  Il2CppObject *v19;
  u64 *v22;
  System_String_o *v24;
  bool IsDLCField;
  s64 *v26;
  System_String_o *v27;
  System_String_o *v29;
  bool v30;
  AssetBundleCtrl_o *v32;
  s32 v37;

  asset_bc = get_asset_bc();
  File = LoadFile(asset_bc, "common", "dds3data/UI", "fldName", ".prefab");
  if (File)
  {
    if (File->klass == UnityEngine_GameObject)
      v8 = File;
    else
      v8 = 0;
  }
  else
  {
    v8 = 0;
  }
  if (!op_Equality(v8, 0, 0))
  {
    v9 = Find("Canvas_UI", 0);
    transform = get_transform(v9, 0);
    v13 = Instantiate_object__425520(v8, transform);
    tit_obj = v13;
    set_name(tit_obj, "fldName");
    Component_object = GetComponent_object_(tit_obj);
    if (op_Equality(Component_object, 0, 0))
    {
      AddComponent_object_(tit_obj);
    }
    v19 = GetComponent_object_(tit_obj);
    tit_scr = v19;
    gfldTitleCnt = 0;
    gfldTitleStep = 99;
    gfldTitleID = fld;
    gfldTitleWait = waittime;
    gfldTitleDelete = 0;
    v37 = fld;
    v22 = sub_8D3950(s32, &v37);
    v24 = Format("f{0:D3}", v22, 0);
    IsDLCField = IsDLCField(fld);
    v26 = &"m";
    if (!IsDLCField)
      v26 = &"";
    v27 = *v26;
    v29 = Concat_5224608(v24, *v26);
    v30 = IsDLCField(fld);
    if ((fld & 0xFFFFFFFE) == 0x3C || v30)
    {
      v32 = get_asset_bc();
      if (!IsLoad(v32, v29))
      {
        LoadAssetExt(v29, v29, v27);
      }
      gfldTitleStep = 98;
    }
    else if ((byte_3F5A648 & 1) != 0)
    {
      goto LABEL_55;
    }
    goto LABEL_55;
  }
}
