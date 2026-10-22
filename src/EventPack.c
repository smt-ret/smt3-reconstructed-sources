#include "types.h"

typedef struct AnimChecker AnimChecker;
typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct AssetBundles AssetBundles;
typedef struct EventEMsgData EventEMsgData;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtPackProcessData_t evtPackProcessData_t;
typedef struct evtTexManager evtTexManager;

static s32 AssetLoadWait;
static evtTexManager *currTexMngr;
static s32 DisableStop1EventNo;
static char *com_str;
static s32 evtRegistBEUnit_minor;
static s32 evtRegistBEUnit_buf;
static s32 save_serial;
static void *be_name;
static void *be_bnm;
static char *LoadPack_bename;
static void *m_key;
static void *v_key;
static s32 gSpEvtLoadPhase;
static s32 gSpEvtLoadIdx;
static s32 *gSpEvtLoadNum;
static s32 SPSE1;
static s32 SPFLD;
static s32 SPLNG;
static void *m_spkey1;
static void *m_spkey2;
static s32 EventNoSw;
static s32 CurrentEvent;

s32 AttachModel_26586560(dds3Basic_t *basic, char *key, char *chkname, char *name);
void BillSetTexture(evtTexManager *this);
void CheckLoadPack(evtPackProcessData_t *data);
void Destroy(evtTexManager *this, bool unload);
void Eve_DistortionBlurSetDefTex(void);
void Eve_DistortionBlurSetTex(void *hTex);
void Eve_PartialMultiBlurSetDefTex(void);
void Eve_PartialMultiFilterSetDefTex(void);
void Eve_RippleBlurSetDefTex(void);
void FinalizeLoadManager(bool sw);
bool FldDataCheck(s32 field, s32 area);
void *GetAnimator(void *obj);
char *GetAppendix(void);
char *GetDLCTag(s32 eventno);
EventEMsgData *GetData(char *key);
void Initialize(evtTexManager *this, char *key, char *path);
bool IsAnimStarted(AnimChecker *this, s32 LayerIndex);
bool IsDLC(void);
bool IsLoad(AssetBundles *this, char *key);
bool IsNoText(s32 eventno);
bool IsStartModelLoaded(void);
void Load(char *key, char *filePath);
void LoadAssetExt(char *key, char *name, char *dlc);
void LoadDirect(AssetBundleCtrl *this, char *key, char *aname, s32 dlc_id);
void LoadEventData(char *key, s32 e, bool ecmnf);
void LoadEventModel(void);
void LoadEventVoice(s32 eventno, char *key, EventEMsgData *data);
void *LoadFile_16626736(AssetBundleCtrl *this, char *key, char *path_name);
void LoadKeys(s32 type, char *key, char *path);
void LoadPack(evtPackProcessData_t *data);
void Log(char *fmt, void **parray);
void MarkPibIndex(u8 ***bData);
void MarkTmxIndex(u8 ***bData);
void ReleaseManiacsChar(void);
void Remove(char *key);
void RemoveKeys(s32 type, char *key);
void SetBoostFrameRate(dds3DefaultMain *this);
void SetDrawFlag(u32 flag, u32 cnt);
void SetNormalFrameRate(dds3DefaultMain *this);
void SetShadowMode(dds3DefaultMain *this, s32 mode);
bool SpEvtCheckLoad(s32 eventno);
s32 SpEvtLoadFinished(void);
void SpEvtUnloadAll(s32 eventno);
void StartLoad(void);
void UnloadAB(AssetBundleCtrl *this, char *key);
void UnloadALL(bool all);
void WindowDispOff(bool sw);
void billAlfRaitoSet(f32 raito);
void billCutRaitoSet(f32 raito);
void billScaleRaitoSet(f32 par_scl_raito, f32 eff_scl_raito);
dds3Basic_t *dds3GetActiveScene(void);
dds3Basic_t *dds3GetControlScene(void);
void *dds3GetProcessData(dds3ProcessID_t **id);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
dds3ProcessID_t *dds3SearchProcessPriority(s32 priority);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
evtPackProcessData_t *evtGetPackProcessData(s32 eventno);
s32 evtLoadArea_FromMemory(s32 fld, s32 area, u8 **pF1, u8 **pF2, u8 **pTB, u8 **pBF);
s32 evtPlaySe(s32 eventno, s32 seno);
dds3ProcessID_t *evtSearchEventPack(s32 eventno);
s32 evtSetRegistUnit(s32 major, s32 minor);
void fldCmnBgmSeUnload(void);
void fldEventDataUnload(void);
void fldFileAddrResetMode(s32 mode);
void fldFootSeUnload(void);
void fldFreeNextFile(void);
void tpAlfRaitoSet(f32 raito);

// 0xfed800
void CheckLoadPack(evtPackProcessData_t *data) {
  u64 *v3;
  System_String_o *v5;
  s32 eventno;
  System_String_o *DLCTag;
  System_String_o *v8;
  System_String_o *v9;
  System_String_o *v11;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v16;
  UnityEngine_Object_o *File_16626736;
  s64 typeHierarchyDepth;
  System_Object_array *v19;
  struct System_String_o *LoadPack_bename;
  s64 *v26;
  s64 *v27;
  System_String_o *v29;
  System_Object_array *v31;
  struct System_Byte_array *v33;
  s32 v35;
  s32 v36;
  evtTexManager_o *currTexMngr;
  u64 *v39;
  System_String_o *v41;
  Il2CppObject *v43;
  Il2CppClass *klass;
  s64 v47;
  char *v48;
  s64 *v49;
  u64 *v50;
  evtTexManager_o *v53;
  u64 *v54;
  System_String_o *v55;
  struct evtTexManager_o **p_e9xxxTexManager;
  u64 *v63;
  System_String_o *v65;
  Il2CppObject *v66;
  Il2CppClass *v68;
  s64 v69;
  char *v70;
  s64 *v71;
  u64 *v72;
  u64 *v73;
  System_String_o *v74;
  u64 *v76;
  System_String_o *v78;
  evtTexManager_o *v81;
  struct System_Char_array *v82;
  s64 v83;
  s64 v84;
  s64 v85;
  u64 TypeTableCount;
  struct beTypeTable_s_array *v87;
  struct beTypeTable_s_array *typetable;
  u64 v89;
  s64 i;
  u64 *v92;
  u64 j;
  struct beTypeTable_s_array *v94;
  struct beTypeTable_s_array *v96;
  u64 ItemCount;
  struct beNameTable_s_array *v99;
  u32 *nametable;
  u64 v101;
  u64 v102;
  System_Byte_array *v103;
  u64 *v104;
  s64 v107;
  struct System_Char_array *v108;
  s64 v109;
  s64 v110;
  struct System_Char_array *v111;
  char *v112;
  s64 v113;
  s64 v114;
  s32 v115;
  s32 pos[2];
  System_Byte_array *bData;

  *pos = 0;
  bData = 0;
  LODWORD(v110) = data->eventno;
  v3 = sub_8D3950(s32, &v110);
  v5 = Format("e{0:D3}", v3, 0);
  eventno = data->eventno;
  DLCTag = GetDLCTag(eventno);
  v8 = DLCTag;
  if (data->eventno == 715)
  {
    v9 = ToUpper(DLCTag, 0);
    if (op_Equality(v9, "M", 0))
      v8 = "";
  }
  v11 = Concat_5224608(v5, v8);
  asset_bc = get_asset_bc();
  v16 = Concat_5224608(LoadPack_bename, ".bytes");
  File_16626736 = LoadFile_16626736(asset_bc, v11, v16);
  if (File_16626736)
  {
    if (File_16626736->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
    {
      if (File_16626736->klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_TextAsset)
        File_16626736 = 0;
    }
    else
    {
      File_16626736 = 0;
    }
  }
  bData = get_bytes(File_16626736);
  v19 = NewSpecific(object, 6u);
  v19->m_Items[0] = "CheckLoadPack : ";
  v19->m_Items[1] = v11;
  v19->m_Items[2] = ",";
  if (LoadPack_bename
    && !QueryInterface(LoadPack_bename, v19->obj.klass->_1.element_class))
  {
  }
  v19->m_Items[3] = LoadPack_bename;
  v19->m_Items[4] = ",";
  LODWORD(v110) = bData->max_length;
  v26 = sub_8D3950(s32, &v110);
  v27 = v26;
  v19->m_Items[5] = v27;
  v29 = Concat_5270224(v19);
  v31 = Empty_string_();
  Log(v29, v31, 0);
  if (!bData)
  {
    v36 = -1;
    goto LABEL_143;
  }
  pos[1] = 0;
  MarkTmxIndex(&bData);
  MarkPibIndex(&bData);
  v33 = NewSpecific(byte, LODWORD(bData->max_length));
  data->addr = v33;
  BlockCopy(bData, 0, v33, 0, bData->max_length);
  v35 = data->eventno;
  if (v35 < 901)
  {
    if ((v35 & 0xFFFFFFFE) == 0x326)
    {
LABEL_83:
      p_e9xxxTexManager = &data->e9xxxTexManager;
      goto LABEL_107;
    }
LABEL_58:
    if (currTexMngr)
    {
      Destroy(currTexMngr, 1, 0);
    }
    v115 = data->eventno;
    v39 = sub_8D3950(s32, &v115);
    v41 = Format("E{0:D3}_BE_TEX", v39, 0);
    v43 = GetData(v41, 0);
    else
    {
      if (v43)
      {
LABEL_72:
        klass = v43->klass;
        if (v43->klass->_2.typeHierarchyDepth < v47 || klass->_2.typeHierarchy[v47 - 1] != evtTexManager)
        {
          sub_8FC2C0(klass->_1.element_class, evtTexManager, &v110);
          if ((v110 & 1) != 0)
            v48 = v112;
          else
            v48 = &v110 + 1;
          v49 = sub_8C4940(v48);
        }
      }
    }
    currTexMngr = v43;
    if (!currTexMngr)
    {
      v50 = Allocate(evtTexManager);
      _ctor(v50, 0);
      currTexMngr = v50;
      v53 = currTexMngr;
      LODWORD(v110) = data->eventno;
      v54 = sub_8D3950(s32, &v110);
      v55 = Format("E{0:D3}_BE_TEX", v54, 0);
      Initialize(v53, v11, v55, 0);
    }
    goto LABEL_83;
  }
  if (v35 > 915)
    goto LABEL_58;
  v115 = data->eventno;
  v63 = sub_8D3950(s32, &v115);
  v65 = Format("E{0:D3}_BE_TEX", v63, 0);
  v66 = GetData(v65, 0);
  if (v66)
  {
    v68 = v66->klass;
    if (v66->klass->_2.typeHierarchyDepth < v69 || v68->_2.typeHierarchy[v69 - 1] != evtTexManager)
    {
      sub_8FC2C0(v68->_1.element_class, evtTexManager, &v110);
      if ((v110 & 1) != 0)
        v70 = v112;
      else
        v70 = &v110 + 1;
      v71 = sub_8C4940(v70);
    }
    data->e9xxxTexManager = v66;
      goto LABEL_106;
    goto LABEL_101;
  }
  data->e9xxxTexManager = 0;
  v72 = Allocate(evtTexManager);
  _ctor(v72, 0);
  data->e9xxxTexManager = v72;
  LODWORD(v110) = data->eventno;
  v73 = sub_8D3950(s32, &v110);
  v74 = Format("E{0:D3}_BE_TEX", v73, 0);
  Initialize(v72, v11, v74, 0);
  {
LABEL_101:
  }
LABEL_106:
  p_e9xxxTexManager = &currTexMngr;
LABEL_107:
  *p_e9xxxTexManager = 0;
  LODWORD(v110) = data->eventno;
  v76 = sub_8D3950(s32, &v110);
  v78 = Format("E{0:D3}_BE_PB", v76, 0);
  Initialize(v11, v78, 0);
  if ((data->eventno - 601) <= 0x12A)
  {
    v81 = currTexMngr;
    if (v81)
    {
      BillSetTexture(v81);
    }
  }
  data->be_f = 0;
  v110 = 0;
  v113 = 0;
  v114 = 0;
  v111 = 0;
  v112 = 0;
  sub_134F3C0(&v110, bData, &pos[1]);
  v82 = v111;
  v84 = v113;
  v83 = v114;
  *&data->header.ExpandSize = v112;
  *&data->header.Version = v84;
  v85 = v110;
  *&data->header.Reserve3 = v83;
  *&data->header.FileType = v85;
  data->header.MagicCode = v82;
  TypeTableCount = data->header.TypeTableCount;
  v87 = NewSpecific(beTypeTable_s, TypeTableCount);
  data->typetable = v87;
  if (TypeTableCount >= 1)
  {
    typetable = v87;
    v89 = 0;
    for (i = 32; ; i += 32)
    {
      v112 = 0;
      v113 = 0;
      v110 = 0;
      v111 = 0;
      sub_134FA40(&v110, bData, &pos[1]);
      v109 = v113;
      v107 = v110;
      v108 = v111;
      v92 = (&typetable->obj.klass + i);
      v92[2] = v112;
      v92[3] = v109;
      *v92 = v107;
      v92[1] = v108;
      if (TypeTableCount - 1 == v89)
        break;
      typetable = data->typetable;
      ++v89;
    }
    for (j = 0; j != TypeTableCount; ++j)
    {
      v94 = data->typetable;
      if (!v94->m_Items[j].Type)
      {
        v96 = data->typetable;
        ItemCount = v96->m_Items[j].ItemCount;
        pos[0] = data->typetable->m_Items[j].ItemAddress;
        v99 = NewSpecific(beNameTable_s, ItemCount);
        data->nametable = v99;
        if (ItemCount >= 1)
        {
          nametable = v99;
          v101 = 0;
          v102 = ItemCount - 1;
          while (1)
          {
            v103 = bData;
            v104 = Allocate(beNameTable_s);
            beNameTable_s___ctor(v104, v103, pos);
            *&nametable[2 * v101 + 8] = v104;
            if (v102 == v101)
              break;
            nametable = data->nametable;
            ++v101;
          }
        }
      }
    }
  }
  v36 = 2;
LABEL_143:
  data->stat = v36;
}

// 0xfea200
void LoadPack(evtPackProcessData_t *data) {
  s32 eventno;
  System_Text_StringBuilder_o *m_key;
  u64 *v6;
  System_Text_StringBuilder_o *v8;
  System_String_o *DLCTag;
  System_Object_array *v14;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v18;
  System_String_o *v22;
  System_String_o *v24;
  System_String_o *v26;
  AssetBundleCtrl_o *v29;
  System_String_o *v31;
  System_String_o *v36;
  System_Text_StringBuilder_o *v37;
  u64 *v38;
  System_Text_StringBuilder_o *v40;
  System_String_o *v41;
  System_String_o *v42;
  bool IsNullOrEmpty;
  AssetBundleCtrl_o *v47;
  System_String_o *v49;
  System_Object_array *v52;
  bool v54;
  s32 v57;
  System_String_o *v64;
  System_String_o *v66;
  Il2CppObject *v67;
  System_String_o *v68;
  u64 *v69;
  u64 *v70;
  System_String_o *v72;
  System_Text_StringBuilder_o *v_key;
  u64 *v78;
  AssetBundleCtrl_o *v80;
  System_String_o *v81;
  System_String_o *v83;
  System_String_o *v84;
  System_Object_array *v86;
  AssetBundleCtrl_o *v87;
  System_String_o *v88;
  AssetBundleCtrl_o *v91;
  System_String_o *v93;
  System_String_o *v94;
  System_String_o *v95;
  s32 v97;
  s32 v98;
  bool v99[4];

  v99[0] = 0;
  eventno = data->eventno;
  Clear(m_key, 0);
  v98 = eventno;
  v6 = sub_8D3950(s32, &v98);
  AppendFormat(m_key, "e{0:D3}", v6);
  v8 = m_key;
  DLCTag = GetDLCTag(eventno);
  Append_5380272(v8, DLCTag);
  switch (AssetLoadWait)
  {
    case 0:
      SetBoostFrameRate(kernelObject);
      v14 = Empty_string_();
      Log("LoadPack[0] : AssetCheck", v14, 0);
      asset_bc = get_asset_bc();
      v18 = (m_key->klass->vtable._3_ToString.methodPtr)(
              m_key,
              m_key->klass->vtable._3_ToString.method);
      if (!IsLoad(asset_bc, v18))
      {
        v22 = (m_key->klass->vtable._3_ToString.methodPtr)(
                m_key,
                m_key->klass->vtable._3_ToString.method);
        v24 = (m_key->klass->vtable._3_ToString.methodPtr)(
                m_key,
                m_key->klass->vtable._3_ToString.method);
        v26 = GetDLCTag(eventno);
        LoadAssetExt(v22, v24, v26);
      }
      AssetLoadWait = 1;
      break;
    case 1:
      v29 = get_asset_bc();
      v31 = (m_key->klass->vtable._3_ToString.methodPtr)(
              m_key,
              m_key->klass->vtable._3_ToString.method);
      if (IsLoad(v29, v31))
      {
        v36 = (m_key->klass->vtable._3_ToString.methodPtr)(
                m_key,
                m_key->klass->vtable._3_ToString.method);
        LoadEventData(v36, eventno, 1, 0);
        Clear(m_key, 0);
        v37 = m_key;
        v98 = eventno;
        v38 = sub_8D3950(s32, &v98);
        AppendFormat(v37, "e{0:D3}", v38);
        v40 = m_key;
        v41 = GetDLCTag(eventno);
        Append_5380272(v40, v41);
        v42 = GetDLCTag(eventno);
        IsNullOrEmpty = IsNullOrEmpty(v42);
        if (IsNullOrEmpty)
        {
            goto LABEL_61;
          goto LABEL_63;
        }
        Clear(v_key, 0);
        v98 = eventno;
        v78 = sub_8D3950(s32, &v98);
        AppendFormat(v_key, "e{0:D3}", v78);
        v80 = get_asset_bc();
        v81 = (v_key->klass->vtable._3_ToString.methodPtr)(
                v_key,
                v_key->klass->vtable._3_ToString.method);
        v99[0] = IsLoad(v80, v81);
        v83 = sub_3C0020(v99);
        v84 = Concat_5224608("LoadPack[3] : exx ", v83);
        v86 = Empty_string_();
        Log(v84, v86, 0);
        v87 = get_asset_bc();
        v88 = (v_key->klass->vtable._3_ToString.methodPtr)(
                v_key,
                v_key->klass->vtable._3_ToString.method);
        if (IsLoad(v87, v88))
          goto LABEL_60;
        v91 = get_asset_bc();
        v93 = (v_key->klass->vtable._3_ToString.methodPtr)(
                v_key,
                v_key->klass->vtable._3_ToString.method);
        v94 = (v_key->klass->vtable._3_ToString.methodPtr)(
                v_key,
                v_key->klass->vtable._3_ToString.method);
        v95 = ToLower(v94, 0);
        LoadDirect(v91, v93, v95, -1);
        AssetLoadWait = 4;
      }
      break;
    case 4:
      v47 = get_asset_bc();
      v49 = (v_key->klass->vtable._3_ToString.methodPtr)(
              v_key,
              v_key->klass->vtable._3_ToString.method);
      if (IsLoad(v47, v49))
      {
LABEL_60:
        {
LABEL_61:
        }
LABEL_63:
        AssetLoadWait = 5;
      }
      break;
    case 5:
      v52 = Empty_string_();
      Log("LoadPack[5]", v52, 0);
      v54 = !SpEvtCheckLoad(eventno);
      if (v54)
        v57 = 7;
      else
        v57 = 6;
      AssetLoadWait = v57;
      if (AssetLoadWait == 7)
      {
        StartLoad();
      }
      break;
    case 6:
      if (SpEvtLoadFinished() == 1)
      {
        StartLoad();
        AssetLoadWait = 7;
      }
      break;
    case 7:
      if (Load(eventno, 0))
      {
        v64 = (m_key->klass->vtable._3_ToString.methodPtr)(
                m_key,
                m_key->klass->vtable._3_ToString.method);
        LoadEventData(v64, eventno, 0, 0);
        v66 = GetDLCTag(eventno);
        v67 = v66;
        if (eventno == 715)
        {
          v68 = ToUpper(v66, 0);
          if (op_Equality(v68, "M", 0))
            v67 = "";
        }
        v98 = eventno;
        v69 = sub_8D3950(s32, &v98);
        v97 = eventno;
        v70 = sub_8D3950(s32, &v97);
        v72 = Format_5268688("dds3data/event/e{0:D3}{1}/e{2:D3}.be", v69, v67, v70);
        LoadPack_bename = v72;
        AssetLoadWait = 0;
        data->assetbundle = 0;
        PlayEventNo = eventno;
        if (eventno == 602 || eventno == 726 || eventno == 809 || (eventno - 740) <= 8)
        {
          DisableStop1EventNo = eventno;
        }
        data->stat = 1;
        SetNormalFrameRate(kernelObject);
      }
      break;
    default:
      return;
  }
}

// 0xfe7480
void SetEventPackName(s32 eventno, char **name) {
  u64 *v5;
  s32 v6;

  v6 = eventno;
  v5 = sub_8D3950(s32, &v6);
  *name = Format("e{0:D3}_p", v5, 0);
}

// 0xfeac60
bool SpEvtCheckLoad(s32 eventno) {
  u64 *v4;
  u64 *v6;
  System_String_o *v7;
  System_Object_array *v9;
  _BOOL4 v12;
  bool v13;
  s32 v14;
  const MethodInfo_1260 *v15;
  s32 v16;
  const MethodInfo_1260 *v17;
  s32 v18;
  const MethodInfo_1260 *v20;
  s32 v21;
  const MethodInfo_1260 *v23;
  s32 v24;
  u64 v25;
  const MethodInfo_1260 *v26;
  s32 v27;
  const MethodInfo_1260 *v28;
  s32 v29;
  u32 Count;
  struct System_Int32_array *v37;
  s32 v40;
  u64 v43;
  struct System_Int32_array *gSpEvtLoadNum;
  s32 Item;
  char *v47;
  s32 v48;
  System_Object_array *v49;
  s64 *v51;
  s64 *v52;
  s64 *v55;
  s64 *v56;
  System_String_o *v58;
  System_Object_array *v60;
  s32 v66;
  s32 v67;
  s32 v68;

  gSpEvtLoadNum = 0;
  gSpEvtLoadIdx = 0;
  gSpEvtLoadPhase = -1;
  v4 = Allocate(System_Collections_Generic_List_int_);
  __ctor(v4);
  v68 = eventno;
  v6 = sub_8D3950(s32, &v68);
  v7 = Concat("SpEvtCheckLoad : ", v6);
  v9 = Empty_string_();
  Log(v7, v9, 0);
  _Clear(v4);
  if (eventno <= 899)
  {
    if (!IsNoText(eventno))
    {
      _Add(v4, SPLNG + eventno);
    }
  }
  if ((eventno - 619) <= 0x29 && ((1LL << (eventno - 107)) & 0x22000202001LL) != 0)
  {
    _Add(v4, 804);
    _Add(v4, 6804);
    goto LABEL_24;
  }
  if (eventno == 715)
  {
    if (!IsDLC())
      goto LABEL_43;
    _Add(v4, 715);
    _Add(v4, 5715);
    v15 = Method_System_Collections_Generic_List_int__Add__;
    v16 = 6715;
    goto LABEL_42;
  }
  if (eventno == 714)
  {
    if (!IsDLC())
      goto LABEL_43;
    v15 = Method_System_Collections_Generic_List_int__Add__;
    v16 = 714;
LABEL_42:
    _Add(v4, v16, v15);
LABEL_43:
    v13 = 0;
    v12 = 0;
LABEL_44:
    _Add(v4, 2002);
LABEL_45:
    v14 = eventno - 603;
LABEL_46:
    switch (v14)
    {
      case 0:
      case 2:
        _Add(v4, 3014);
        if ((eventno & 0xFFFFFFFE) == 0x25C)
          goto LABEL_49;
        goto LABEL_118;
      case 1:
LABEL_49:
        v18 = SPSE1 + 603;
        v17 = Method_System_Collections_Generic_List_int__Add__;
        goto LABEL_86;
      case 12:
        v21 = SPSE1 + 619;
        v20 = Method_System_Collections_Generic_List_int__Add__;
        goto LABEL_117;
      case 13:
      case 15:
        _Add(v4, 4601);
        v20 = Method_System_Collections_Generic_List_int__Add__;
        v21 = 4619;
        goto LABEL_117;
      case 14:
        v20 = Method_System_Collections_Generic_List_int__Add__;
        v21 = 4614;
        goto LABEL_117;
      case 16:
        v23 = Method_System_Collections_Generic_List_int__Add__;
        v24 = 4615;
        goto LABEL_69;
      case 20:
        _Add(v4, 7619);
        _Add(v4, 4220);
        if (v12)
          goto LABEL_67;
        goto LABEL_118;
      case 26:
LABEL_67:
        v17 = Method_System_Collections_Generic_List_int__Add__;
        v18 = 4615;
        goto LABEL_86;
      case 29:
        _Add(v4, 4615);
        v23 = Method_System_Collections_Generic_List_int__Add__;
        v24 = 7619;
LABEL_69:
        _Add(v4, v24, v23);
        v20 = Method_System_Collections_Generic_List_int__Add__;
        v21 = 4220;
        goto LABEL_117;
      case 32:
        _Add(v4, 6603);
        v20 = Method_System_Collections_Generic_List_int__Add__;
        v21 = 4628;
        goto LABEL_117;
      case 33:
        v20 = Method_System_Collections_Generic_List_int__Add__;
        v21 = 4629;
        goto LABEL_117;
      case 43:
      case 49:
        goto LABEL_73;
      case 59:
        _Add(v4, 3615);
        _Add(v4, 4615);
LABEL_73:
        _Add(v4, 7619);
        v20 = Method_System_Collections_Generic_List_int__Add__;
        v21 = 4623;
        goto LABEL_117;
      case 67:
      case 68:
        v20 = Method_System_Collections_Generic_List_int__Add__;
        v21 = 4615;
        goto LABEL_117;
      case 73:
        _Add(v4, 4231);
        _Add(v4, 4240);
        _Add(v4, 4234);
        _Add(v4, 4605);
        v20 = Method_System_Collections_Generic_List_int__Add__;
        v21 = 4629;
        goto LABEL_117;
      case 75:
      case 76:
      case 78:
        v17 = Method_System_Collections_Generic_List_int__Add__;
        v18 = 3677;
        goto LABEL_86;
      case 89:
        _Add(v4, 684);
        v20 = Method_System_Collections_Generic_List_int__Add__;
        v21 = 694;
        goto LABEL_117;
      case 90:
        _Add(v4, 4216);
        v20 = Method_System_Collections_Generic_List_int__Add__;
        v21 = 4602;
        goto LABEL_117;
      case 91:
        _Add(v4, 684);
        _Add(v4, 617);
        _Add(v4, 692);
        HIDWORD(v25) = eventno - 699;
        LODWORD(v25) = eventno - 699;
        switch ((v25 >> 2))
        {
          case 0u:
            goto LABEL_78;
          case 1u:
            goto LABEL_79;
          case 5u:
            goto LABEL_80;
          case 8u:
            goto LABEL_81;
          default:
            goto LABEL_118;
        }
      case 96:
LABEL_78:
        _Add(v4, 4202);
        _Add(v4, 4234);
        v17 = Method_System_Collections_Generic_List_int__Add__;
        v18 = 4616;
        goto LABEL_86;
      case 100:
LABEL_79:
        _Add(v4, 617);
        v17 = Method_System_Collections_Generic_List_int__Add__;
        v18 = 676;
        goto LABEL_86;
      case 116:
LABEL_80:
        v17 = Method_System_Collections_Generic_List_int__Add__;
        v18 = 718;
        goto LABEL_86;
      case 127:
        v28 = Method_System_Collections_Generic_List_int__Add__;
        v29 = 2003;
        goto LABEL_97;
      case 128:
LABEL_81:
        if (!IsDLC())
          goto LABEL_87;
        v17 = Method_System_Collections_Generic_List_int__Add__;
        v18 = 731;
        break;
      default:
        goto LABEL_57;
    }
    goto LABEL_86;
  }
LABEL_24:
  v12 = eventno == 629;
  switch (eventno)
  {
    case 603:
    case 615:
    case 619:
    case 623:
    case 632:
    case 634:
    case 635:
    case 661:
    case 677:
    case 678:
    case 679:
    case 681:
      break;
    case 629:
    case 636:
    case 672:
      _Add(v4, 802);
      v13 = 0;
      if ((eventno - 632) > 0x1D || ((1 << (eventno - 120)) & 0x2000000D) == 0)
        goto LABEL_45;
      break;
    default:
      v13 = eventno > 721;
      if ((eventno - 710) > 0xB)
        goto LABEL_45;
      goto LABEL_44;
  }
  _Add(v4, 2001);
  v13 = 0;
  v14 = eventno - 603;
  if ((eventno - 603) <= 0x80)
    goto LABEL_46;
LABEL_57:
  if (eventno != 741 && (eventno - 740) <= 8)
  {
    v17 = Method_System_Collections_Generic_List_int__Add__;
    v18 = 4240;
LABEL_86:
    _Add(v4, v18, v17);
  }
LABEL_87:
  if (eventno > 703)
  {
    if ((eventno - 704) < 2)
    {
      _Add(v4, 614);
      v26 = Method_System_Collections_Generic_List_int__Add__;
      v27 = 699;
      goto LABEL_100;
    }
    if (eventno == 741)
    {
      v28 = Method_System_Collections_Generic_List_int__Add__;
      v29 = 4241;
LABEL_97:
      _Add(v4, v29, v28);
    }
LABEL_98:
    if (eventno < 712 || v13)
    {
LABEL_101:
      switch (eventno)
      {
        case 717:
          _Add(v4, 715);
          _Add(v4, 720);
          _Add(v4, SPLNG + 715);
          goto LABEL_111;
        case 721:
        case 722:
          _Add(v4, 720);
LABEL_111:
          v20 = Method_System_Collections_Generic_List_int__Add__;
          v21 = SPLNG + 720;
          goto LABEL_117;
        case 728:
          v20 = Method_System_Collections_Generic_List_int__Add__;
          v21 = 723;
          goto LABEL_117;
        case 729:
          v20 = Method_System_Collections_Generic_List_int__Add__;
          v21 = 728;
          goto LABEL_117;
        case 744:
          v20 = Method_System_Collections_Generic_List_int__Add__;
          v21 = 743;
          goto LABEL_117;
        case 804:
          v20 = Method_System_Collections_Generic_List_int__Add__;
          v21 = 4619;
          goto LABEL_117;
        case 805:
        case 806:
          v20 = Method_System_Collections_Generic_List_int__Add__;
          v21 = 3804;
          goto LABEL_117;
        case 807:
          _Add(v4, 800);
          v20 = Method_System_Collections_Generic_List_int__Add__;
          v21 = 5800;
          goto LABEL_117;
        default:
          goto LABEL_118;
      }
    }
    v26 = Method_System_Collections_Generic_List_int__Add__;
    v27 = 711;
LABEL_100:
    _Add(v4, v27, v26);
    goto LABEL_101;
  }
  if (eventno == 614)
  {
    v20 = Method_System_Collections_Generic_List_int__Add__;
    v21 = 614;
  }
  else
  {
    if (eventno != 650)
      goto LABEL_98;
    v20 = Method_System_Collections_Generic_List_int__Add__;
    v21 = 617;
  }
LABEL_117:
  _Add(v4, v21, v20);
LABEL_118:
  Count = _get_Count(v4);
  v37 = NewSpecific(s32, Count);
  gSpEvtLoadNum = v37;
  v40 = _get_Count(v4);
  if (v40 >= 1)
  {
    v43 = 0;
    do
    {
      Item = _get_Item(
               v4,
               v43);
      v47 = gSpEvtLoadNum + 4 * v43++;
      *(v47 + 8) = Item;
      v48 = _get_Count(v4);
    }
    while (v43 < v48);
  }
  gSpEvtLoadPhase = 0;
  v49 = NewSpecific(object, 4u);
  v49->m_Items[0] = "SpEvtCheckLoad : ";
  v67 = eventno;
  v51 = sub_8D3950(s32, &v67);
  v52 = v51;
  v49->m_Items[1] = v52;
  v49->m_Items[2] = ",";
  v66 = _get_Count(v4);
  v55 = sub_8D3950(s32, &v66);
  v56 = v55;
  v49->m_Items[3] = v56;
  v58 = Concat_5270224(v49);
  v60 = Empty_string_();
  Log(v58, v60, 0);
  return _get_Count(v4) != 0;
}

// 0xfeb990
s32 SpEvtLoadFinished(void) {
  s32 gSpEvtLoadPhase;
  struct System_Int32_array *v6;
  s64 v7;
  s32 v9;
  AssetBundleCtrl_o *v10;
  System_String_o *v11;
  System_Text_StringBuilder_o *m_spkey2;
  System_String_o *v17;
  System_String_o *v18;
  System_String_o *v20;
  System_String_o *v21;
  System_String_o *v22;
  EventEMsgData_o *v24;
  System_String_o *v25;
  System_String_o *v26;
  s64 v27;
  System_String_o *v28;
  EventEMsgData_o *v29;
  s32 v30;
  System_String_o *v31;
  struct System_Int32_array *gSpEvtLoadNum;
  s64 gSpEvtLoadIdx;
  s64 v52;
  s32 v53;
  System_String_o *v54;
  System_String_o *v57;
  System_String_o *v59;
  s64 v60;
  System_String_o *v61;
  EventEMsgData_o *Data;
  struct System_Int32_array *v65;
  s32 v66;
  s32 max_length;
  s32 v70;
  AssetBundleCtrl_o *v72;
  System_String_o *v73;
  System_String_o *v77;
  System_String_o *v79;
  System_String_o *v81;
  System_String_o *v86;

  if (!gSpEvtLoadPhase)
    goto LABEL_35;
LABEL_6:
  if (gSpEvtLoadPhase != 1)
    return gSpEvtLoadPhase == 2;
  v6 = gSpEvtLoadNum;
  v7 = gSpEvtLoadIdx;
  v9 = v6->m_Items[v7];
  v10 = get_asset_bc();
  v11 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
          m_spkey1,
          m_spkey1->klass->vtable._3_ToString.method);
  if (!IsLoad(v10, v11))
    return 0;
  if ((v9 - 7000) <= 0x3E7)
  {
LABEL_69:
    v52 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    v53 = 1;
    goto LABEL_76;
  }
  if ((v9 - 6000) <= 0x3E7)
  {
    if (v9 != 6804 && v9 != 6604)
      goto LABEL_78;
    goto LABEL_69;
  }
  if ((v9 - 5000) <= 0x3E7)
  {
    v57 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    v59 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    LoadEventData(v57, v59, v9 - 5000, 0, 0);
    v60 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    v61 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    Data = GetData(v61, 0);
    v30 = v9;
    v31 = v60;
    v29 = Data;
LABEL_91:
    LoadEventVoice(v30, v31, v29);
      goto LABEL_92;
LABEL_79:
    goto LABEL_92;
  }
  if ((v9 - 3000) <= 0x7CF)
  {
    v52 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    v53 = 3;
LABEL_76:
    v54 = v52;
LABEL_77:
    LoadKeys(v53, v54, 0);
    goto LABEL_78;
  }
  if ((v9 - 2000) <= 0x3E7)
  {
    v86 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    LoadKeys(3, v86, 0);
    v54 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    v53 = 1;
    goto LABEL_77;
  }
  if (v9 <= 1999)
  {
    Clear(m_spkey2, 0);
    v17 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    Append_5380272(m_spkey2, v17);
    Append_5380272(m_spkey2, "m");
    v18 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    v20 = (m_spkey2->klass->vtable._3_ToString.methodPtr)(
            m_spkey2,
            m_spkey2->klass->vtable._3_ToString.method);
    LoadEventData(v18, v20, v9, 0, 0);
    v21 = (m_spkey2->klass->vtable._3_ToString.methodPtr)(
            m_spkey2,
            m_spkey2->klass->vtable._3_ToString.method);
    v22 = (m_spkey2->klass->vtable._3_ToString.methodPtr)(
            m_spkey2,
            m_spkey2->klass->vtable._3_ToString.method);
    v24 = GetData(v22, 0);
    LoadEventVoice(v9, v21, v24);
    v25 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    v26 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    LoadEventData(v25, v26, v9, 0, 0);
    v27 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    v28 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    v29 = GetData(v28, 0);
    v30 = v9;
    v31 = v27;
    goto LABEL_91;
  }
LABEL_78:
    goto LABEL_79;
LABEL_92:
  ++gSpEvtLoadIdx;
  v65 = gSpEvtLoadNum;
  v66 = gSpEvtLoadIdx;
  max_length = v65->max_length;
  if (v66 < max_length)
  {
    v70 = v65->m_Items[v66];
    get_keystring(v70);
    v72 = get_asset_bc();
    v73 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
            m_spkey1,
            m_spkey1->klass->vtable._3_ToString.method);
    if (!IsLoad(v72, v73))
    {
      v77 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
              m_spkey1,
              m_spkey1->klass->vtable._3_ToString.method);
      v79 = (m_spkey1->klass->vtable._3_ToString.methodPtr)(
              m_spkey1,
              m_spkey1->klass->vtable._3_ToString.method);
      v81 = GetDLCTag(v70);
      LoadAssetExt(v77, v79, v81);
    }
    return 0;
  }
  gSpEvtLoadPhase = 2;
  return 1;
}

// 0xfec340
void SpEvtUnloadAll(s32 eventno) {
  AssetBundleCtrl_o *asset_bc;
  u32 Count;
  System_String_array *v5;
  System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o *Keys;
  u64 *v7;
  u64 *v8;
  System_String_o *v10;
  System_String_o *DLCTag;
  System_String_o *v12;
  u64 *v13;
  System_String_o *v14;
  System_String_o *v16;
  System_String_o *Appendix;
  System_String_o *v18;
  u64 *v19;
  System_String_o *v20;
  System_String_o *v21;
  System_String_o *v22;
  u64 *v24;
  System_String_o *v26;
  System_String_o *v27;
  System_String_o *v28;
  bool v29;
  s64 *v30;
  System_Collections_Generic_List_mdlEffectResrcItem_t__o *v31;
  s64 *v32;
  s64 *v33;
  s64 v34;
  s64 *v35;
  System_String_o *v36;
  const MethodInfo_1260 *v37;
  s64 *v38;
  s64 *v39;
  s64 *v40;
  s64 *v41;
  System_String_o *v43;
  System_String_o **m_Items;
  s32 v46;
  il2cpp_array_size_t max_length;
  u64 v48;
  System_String_o *v50;
  System_String_o *v51;
  System_String_o *v53;
  System_String_o *v55;
  System_String_o *Item;
  System_String_o *v58;
  System_Object_array *v60;
  AssetBundleCtrl_o *v62;
  System_String_o *v67;
  System_String_o *v71;
  System_String_o *v73;
  s32 Length;
  System_String_o *v76;
  s32 v77;
  System_String_o *v78;
  System_String_o *v79;
  System_Object_array *v81;
  AssetBundleCtrl_o *v83;
  System_String_o *v87;
  System_Collections_Generic_List_mdlEffectResrcItem_t__o *v94;
  s32 v95;
  s32 v96;
  s32 v97;
  s32 result;

  result = 0;
  asset_bc = get_asset_bc();
  Count = HashSet_Text____get_Count(asset_bc->assetbundle);
  v5 = NewSpecific(string, Count);
  Keys = string___get_Keys(asset_bc->assetbundle);
  string___CopyTo(Keys, v5, 0);
  v7 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v7);
  if ((eventno - 800) > 6 || ((1 << (eventno - 32)) & 0x71) == 0)
  {
    v97 = eventno;
    v8 = sub_8D3950(s32, &v97);
    v10 = Format("e{0:D3}", v8, 0);
    DLCTag = GetDLCTag(eventno);
    v12 = Concat_5224608(v10, DLCTag);
    v94 = v7;
    _Add(v7, v12);
    v96 = eventno;
    v13 = sub_8D3950(s32, &v96);
    v14 = Format("e{0:D3}", v13, 0);
    v16 = GetDLCTag(eventno);
    Appendix = GetAppendix();
    v18 = Concat_5221536(v14, v16, Appendix);
    _Add(v94, v18);
    v95 = eventno;
    v19 = sub_8D3950(s32, &v95);
    v20 = Format("f{0:D3}", v19, 0);
    v21 = GetDLCTag(eventno);
    v22 = Concat_5224608(v20, v21);
    _Add(v94, v22);
    if (eventno <= 899)
    {
      if (!IsNoText(eventno))
      {
        v97 = eventno;
        v24 = sub_8D3950(s32, &v97);
        v26 = Format("e{0:D3}", v24, 0);
        v27 = GetAppendix();
        v28 = Concat_5224608(v26, v27);
        _Add(v94, v28);
      }
    }
    switch (eventno)
    {
      case 603:
      case 615:
      case 619:
      case 623:
      case 632:
      case 634:
      case 635:
      case 661:
      case 677:
      case 678:
      case 679:
      case 681:
        goto LABEL_26;
      case 629:
      case 636:
        _Add(v94, "e802");
        v29 = 0;
        if ((eventno - 632) > 3 || eventno == 633)
          goto LABEL_27;
LABEL_26:
        _Add(v94, "ecmn1");
        v29 = 0;
        goto LABEL_27;
      case 714:
        if (!IsDLC())
          goto LABEL_48;
        v33 = &"e714";
        break;
      case 715:
        if (!IsDLC())
          goto LABEL_48;
        v33 = &"e715";
        break;
      default:
        v29 = eventno > 721;
        if ((eventno - 710) <= 0xB)
          goto LABEL_49;
        goto LABEL_27;
    }
    _Add(v94, *v33);
LABEL_48:
    v29 = 0;
LABEL_49:
    _Add(v94, "ecmn2");
    if ((eventno - 603) <= 0x80)
    {
LABEL_27:
      switch (eventno)
      {
        case 603:
        case 605:
          v31 = v94;
          _Add(v94, "e014");
          if ((eventno & 0xFFFFFFFE) != 0x25C)
            goto LABEL_108;
          v32 = &"e603";
          goto LABEL_53;
        case 604:
          v30 = &"e603";
          goto LABEL_62;
        case 615:
          v30 = &"f619";
          goto LABEL_62;
        case 616:
          v31 = v94;
          _Add(v94, "f601");
LABEL_101:
          v38 = &"f619";
          goto LABEL_105;
        case 617:
          v30 = &"f614";
          goto LABEL_62;
        case 618:
          v31 = v94;
          _Add(v94, "f601");
          v38 = &"f605";
          goto LABEL_105;
        case 619:
          v31 = v94;
          _Add(v94, "f615");
          _Add(v94, "f220");
          v38 = &"f804";
          goto LABEL_105;
        case 623:
          v39 = &"e619";
          goto LABEL_67;
        case 629:
        case 670:
        case 671:
          v30 = &"f615";
LABEL_62:
          v36 = *v30;
          v37 = Method_System_Collections_Generic_List_string__Add__;
          v31 = v94;
          goto LABEL_107;
        case 632:
          v39 = &"f615";
LABEL_67:
          v31 = v94;
          _Add(v94, *v39);
          _Add(v94, "f619");
          v38 = &"f220";
          goto LABEL_105;
        case 635:
          v31 = v94;
          _Add(v94, "f628");
          v38 = &"e603";
          goto LABEL_105;
        case 636:
          v31 = v94;
          _Add(v94, "f629");
          v38 = &"e629";
          goto LABEL_105;
        case 646:
        case 652:
          v31 = v94;
          goto LABEL_71;
        case 662:
          v31 = v94;
          _Add(v94, "e615");
          _Add(v94, "f615");
LABEL_71:
          _Add(v31, "f619");
          v38 = &"f623";
          goto LABEL_105;
        case 676:
          v31 = v94;
          _Add(v94, "f231");
          _Add(v94, "f240");
          _Add(v94, "f234");
          _Add(v94, "f605");
          v38 = &"f629";
          goto LABEL_105;
        case 692:
          v40 = &"e684";
          v31 = v94;
          goto LABEL_76;
        case 693:
          v31 = v94;
          _Add(v94, "f216");
          v38 = &"f602";
          goto LABEL_105;
        case 694:
          v31 = v94;
          _Add(v94, "e684");
          v40 = &"e617";
LABEL_76:
          _Add(v31, *v40);
          v38 = &"e694";
          goto LABEL_105;
        case 699:
          v31 = v94;
          _Add(v94, "f202");
          _Add(v94, "f234");
          v38 = &"f616";
          goto LABEL_105;
        case 703:
          v31 = v94;
          _Add(v94, "e617");
          v38 = &"e676";
          goto LABEL_105;
        case 730:
          v41 = &"ecmn3";
          v31 = v94;
          goto LABEL_88;
        case 731:
          v31 = v94;
          if (!IsDLC())
            goto LABEL_89;
          v41 = &"e731";
          goto LABEL_88;
        default:
          break;
      }
    }
    v31 = v94;
    if (eventno != 741 && (eventno - 740) <= 8)
    {
      v32 = &"f240";
LABEL_53:
      _Add(v31, *v32);
    }
    v34 = (eventno - 678);
    if (v34 <= 0x3F)
    {
      if (((1LL << (eventno + 90)) & 0xB) != 0)
      {
        v35 = &"e677";
        goto LABEL_91;
      }
      if (((1LL << (eventno + 90)) & 0xC000000) != 0)
      {
        _Add(v31, "e614");
        v35 = &"e699";
        goto LABEL_91;
      }
      if (v34 == 63)
      {
        v41 = &"f241";
LABEL_88:
        _Add(v31, *v41);
        goto LABEL_89;
      }
    }
    if (eventno == 614)
    {
      v38 = &"e704";
    }
    else
    {
      if (eventno != 650)
      {
LABEL_89:
        if (eventno < 712 || v29)
          goto LABEL_92;
        v35 = &"e711";
LABEL_91:
        _Add(v31, *v35);
LABEL_92:
        switch (eventno)
        {
          case 717:
            _Add(v31, "e714");
            _Add(v31, "e715");
            v38 = &"e720";
            goto LABEL_105;
          case 718:
          case 720:
            break;
          case 719:
            v38 = &"e718";
            goto LABEL_105;
          case 721:
          case 722:
            _Add(v31, "e720");
            v43 = GetAppendix();
            v36 = Concat_5224608("e720", v43);
            goto LABEL_106;
          default:
            if (eventno == 804)
              goto LABEL_101;
            break;
        }
LABEL_108:
        if (_get_Count(v31) >= 1)
        {
          m_Items = v5->m_Items;
          v46 = 0;
          do
          {
            max_length = v5->max_length;
            if (max_length >= 1)
            {
              v48 = 0;
              do
              {
                v50 = Substring_5248048(m_Items[v48], 0, 1);
                v51 = ToUpper(v50, 0);
                if (!op_Inequality(v51, "E", 0)
                  || !op_Inequality(v51, "F", 0))
                {
                  result = -1;
                  v53 = Substring_5248048(m_Items[v48], 1, 3);
                  if (TryParse(v53, &result, 0))
                  {
                    v55 = m_Items[v48];
                    Item = _get_Item(
                             v31,
                             v46);
                    if (Equals_5234480(v55, Item))
                    {
                      v58 = Concat_5224608("Unload = ", m_Items[v48]);
                      v60 = Empty_string_();
                      Log(v58, v60, 0);
                      v62 = get_asset_bc();
                      v31 = v94;
                      UnloadAB(v62, m_Items[v48]);
                      v67 = m_Items[v48];
                      {
                      }
                      RemoveKeys(1, v67);
                      RemoveKeys(3, m_Items[v48]);
                      v71 = m_Items[v48];
                      Remove(v71, 0);
                      v73 = m_Items[v48];
                      Length = get_Length(v73);
                      if (get_Chars(v73, Length - 1) == 109)
                      {
                        v76 = m_Items[v48];
                        v77 = get_Length(v76);
                        v78 = Substring_5248048(v76, 0, v77 - 1);
                        v79 = Concat_5224608("Unload = ", v78);
                        v81 = Empty_string_();
                        Log(v79, v81, 0);
                        v83 = get_asset_bc();
                        UnloadAB(v83, v78);
                        v87 = m_Items[v48];
                        {
                        }
                        RemoveKeys(1, v87);
                        RemoveKeys(3, m_Items[v48]);
                        v31 = v94;
                        Remove(v78, 0);
                      }
                    }
                  }
                }
                LODWORD(max_length) = v5->max_length;
                ++v48;
              }
              while (v48 < max_length);
            }
            ++v46;
          }
          while (v46 < _get_Count(v31));
        }
        WindowDispOff(0);
        {
        }
        RemoveKeys(5, 0);
        FinalizeLoadManager(1);
        DisableStop1EventNo = 0;
        return;
      }
      v38 = &"e617";
    }
LABEL_105:
    v36 = *v38;
LABEL_106:
    v37 = Method_System_Collections_Generic_List_string__Add__;
LABEL_107:
    _Add(v31, v36, v37);
    goto LABEL_108;
  }
}

// 0xfe9d10
void UnloadALL(bool all) {
  AssetBundleCtrl_o *asset_bc;
  u32 Count;
  System_String_array *v5;
  System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o *Keys;
  il2cpp_array_size_t max_length;
  u64 v9;
  Il2CppClass **v11;
  System_String_o **v12;
  System_String_o *v13;
  System_String_o *v14;
  System_String_o *v15;
  System_String_o *v17;
  System_String_o *v22;
  AssetBundleCtrl_o *v25;
  AssetBundleCtrl_o *v28;
  AssetBundleCtrl_o *v31;
  s32 result;

  result = 0;
  asset_bc = get_asset_bc();
  Count = HashSet_Text____get_Count(asset_bc->assetbundle);
  v5 = NewSpecific(string, Count);
  Keys = string___get_Keys(asset_bc->assetbundle);
  string___CopyTo(Keys, v5, 0);
  max_length = v5->max_length;
  if (max_length >= 1)
  {
    v9 = 0;
    do
    {
      v11 = &v5->obj.klass + v9;
      v13 = v11[4];
      v12 = (v11 + 4);
      v14 = Substring_5248048(v13, 0, 1);
      v15 = ToUpper(v14, 0);
      if (!op_Inequality(v15, "E", 0)
        || !op_Inequality(v15, "F", 0))
      {
        result = -1;
        v17 = Substring_5248048(*v12, 1, 3);
        if (TryParse(v17, &result, 0))
        {
          if (get_Length(*v12) == 4)
            goto LABEL_23;
          if (get_Length(*v12) == 5)
          {
LABEL_23:
            v22 = *v12;
            {
            }
            RemoveKeys(1, v22);
            RemoveKeys(3, *v12);
            RemoveKeys(4, *v12);
          }
          if (all)
          {
            while (1)
            {
              v28 = get_asset_bc();
              if (!IsLoad(v28, *v12))
                break;
              v31 = get_asset_bc();
              UnloadAB(v31, *v12);
            }
          }
          else
          {
            v25 = get_asset_bc();
            UnloadAB(v25, *v12);
          }
        }
      }
      LODWORD(max_length) = v5->max_length;
      ++v9;
    }
    while (v9 < max_length);
  }
  RemoveKeys(5, 0);
  SndAssetBundleManager_SndData___Clear(VoiceBundleTable);
  fldEventDataUnload();
  fldFootSeUnload();
  fldCmnBgmSeUnload();
  UnloadALL(0);
  ReleaseManiacsChar();
  PlayEventNo = 0;
}

// 0xfe7f00
void evtDispBlurTexSet(s32 eventno, s32 rid) {
  evtPackProcessData_t_o *PackProcessData;
  UnityEngine_Object_o *distblurtex;
  UnityEngine_Object_o *v8;
  AssetBundleCtrl_o *asset_bc;
  UnityEngine_Object_o *File_16626736;
  UnityEngine_Texture_o *v13;
  UnityEngine_Object_c *klass;
  s64 typeHierarchyDepth;
  char *v16;
  s64 *v17;
  u64 v18[3];

  PackProcessData = evtGetPackProcessData(eventno, *&rid);
  distblurtex = PackProcessData->distblurtex;
  if (op_Inequality(distblurtex, 0, 0))
  {
    v8 = PackProcessData->distblurtex;
    Destroy_27360000(v8);
    PackProcessData->distblurtex = 0;
  }
  asset_bc = get_asset_bc();
  File_16626736 = LoadFile_16626736(asset_bc, "bill", "dds3data/bill/roll_blur.png");
  v13 = File_16626736;
  if (File_16626736)
  {
    klass = File_16626736->klass;
    if (File_16626736->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Texture)
    {
      sub_8FC2C0(klass->_1.element_class, UnityEngine_Texture, v18);
      if ((v18[0] & 1) != 0)
        v16 = v18[2];
      else
        v16 = v18 + 1;
      v17 = sub_8C4940(v16);
    }
  }
  Eve_DistortionBlurSetTex(v13);
  PackProcessData->distblurtex = v13;
}

// 0xfe7620
s32 evtGetEventPackStat(s32 eventno) {
  u64 *v3;
  s32 *ProcessData;
  s64 v7;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  dds3ProcessID_t_o *v13;
  u64 v14[3];

  v3 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v3);
  v13 = v3;
  v13 = evtSearchEventPack(eventno);
  if (!v13)
    return -1;
LABEL_6:
  ProcessData = dds3GetProcessData(&v13);
  v7 = *ProcessData;
  if (*(*ProcessData + 288LL) < typeHierarchyDepth
    || *(*(v7 + 200) + 8 * typeHierarchyDepth - 8) != evtPackProcessData_t)
  {
    sub_8FC2C0(*(v7 + 64), evtPackProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v11 = v14[2];
    else
      v11 = v14 + 1;
    v12 = sub_8C4940(v11);
  }
  return ProcessData[5];
}

// 0xfe77a0
evtPackProcessData_t *evtGetPackProcessData(s32 eventno) {
  u64 *v3;
  evtPackProcessData_t_o *result;
  evtPackProcessData_t_c *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  dds3ProcessID_t_o *v12;
  u64 v13[3];

  v3 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v3);
  v12 = v3;
  else
  {
    result = evtSearchEventPack(eventno);
    v12 = result;
    if (!result)
      return result;
  }
  else
  {
    result = dds3GetProcessData(&v12);
    if (!result)
      return result;
  }
  klass = result->klass;
  if (result->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPackProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, evtPackProcessData_t, v13);
    if ((v13[0] & 1) != 0)
      v9 = v13[2];
    else
      v9 = v13 + 1;
    v10 = sub_8C4940(v9);
  }
  return result;
}

// 0xfe7930
u8 **evtGetResorceData(s32 eventno, s32 rid) {
  u64 *v5;
  f32 v9;
  f32 v11;
  f32 v13;
  Il2CppObject *ProcessData;
  Il2CppObject *v16;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v19;
  s64 *v20;
  struct evtTexManager_o *monitor;
  System_Array_o *v23;
  s64 v24;
  u64 v25;
  u32 *v26;
  System_Byte_array *v28;
  u32 *v30;
  System_Array_o *v32;
  u32 *v33;
  evtTexManager_o *currTexMngr;
  dds3ProcessID_t_o *v38;
  u64 v39[3];

  v5 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v5);
  v38 = v5;
  v38 = evtSearchEventPack(eventno);
  if (!v38)
    return 0;
LABEL_6:
  if (eventno <= 693)
  {
    switch (eventno)
    {
      case 615:
        if (rid <= 0x10 && ((1 << rid) & 0x19800) != 0)
        {
          tpAlfRaitoSet(4.0);
        }
        break;
      case 628:
        if (rid == 11)
        {
          billAlfRaitoSet(2.0);
          v9 = 50.0;
          goto LABEL_56;
        }
        break;
      case 634:
        if (rid == 9)
        {
          e634_flag = 1;
        }
        break;
      case 635:
        if (rid == 17)
        {
          v11 = 1.5;
          goto LABEL_62;
        }
        break;
      case 646:
        if (rid == 9 || rid == 5)
        {
          tpAlfRaitoSet(2.5);
          billAlfRaitoSet(2.5);
          billScaleRaitoSet(1.0, 2.0);
        }
        break;
      default:
        goto LABEL_63;
    }
    goto LABEL_63;
  }
  if (eventno != 694)
  {
    if (eventno != 697)
    {
      if (eventno != 719 || rid != 7)
        goto LABEL_63;
      goto LABEL_58;
    }
    if (rid != 10)
      goto LABEL_63;
    v13 = 3.0;
LABEL_55:
    billAlfRaitoSet(v13);
    v9 = 25.0;
LABEL_56:
    billCutRaitoSet(v9);
    goto LABEL_63;
  }
  if ((rid - 7) < 2)
  {
    v13 = 2.0;
    goto LABEL_55;
  }
  if (rid != 6)
    goto LABEL_63;
LABEL_58:
  v11 = 2.0;
LABEL_62:
  billAlfRaitoSet(v11);
LABEL_63:
  ProcessData = dds3GetProcessData(&v38);
  v16 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPackProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, evtPackProcessData_t, v39);
      if ((v39[0] & 1) != 0)
        v19 = v39[2];
      else
        v19 = v39 + 1;
      v20 = sub_8C4940(v19);
    }
  }
  if ((LODWORD(ProcessData[1].klass) - 901) <= 0xE)
  {
    monitor = v16[11].monitor;
    currTexMngr = monitor;
  }
  if (HIDWORD(v16[1].klass) != 2 || SHIDWORD(v16[4].klass) < 1)
    return 0;
  v23 = v16[2].monitor;
  v24 = 0;
  v25 = 0;
  while (1)
  {
    v26 = v16[5].monitor;
    if (v26[v24 + 12] == rid)
      break;
    ++v25;
    v24 += 8;
    if (v25 >= SHIDWORD(v16[4].klass))
      return 0;
  }
  v30 = v16[5].monitor;
  v32 = NewSpecific(byte, v30[v24 + 9]);
  v33 = v16[5].monitor;
  v28 = v32;
  BlockCopy(v23, v33[v24 + 11], v32, 0, v33[v24 + 9]);
  if (currTexMngr)
  {
    BillSetTexture(currTexMngr);
  }
  return v28;
}

// 0xfe9950
dds3ProcessID_t *evtInitMotionSeProcess(s32 unitid, s32 eventno, s32 rid) {
  u64 *v7;
  u64 *v8;
  u64 *v9;
  u64 *v10;
  System_String_o *v11;
  evtMotionSeData_t_o *data;
  evtPackProcessData_t_o *PackProcessData;
  evtPackProcessData_t_o *v15;
  u64 v16;
  struct beTypeTable_s_array *typetable;
  struct beTypeTable_s_array *v20;
  struct beTypeTable_s_array *v22;
  u32 *bPlayed;
  s64 *v25;
  s64 *v26;
  s64 i;
  struct System_Byte_array_array *v29;
  u64 v30;
  struct System_Byte_array_array *v32;
  System_Byte_array *v34;
  u64 *v36;
  u64 *v37;
  s32 v41;
  s32 v42;

  v7 = Allocate(evtMotionSeData_t);
  evtMotionSeData_t___ctor(v7);
  v8 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v8);
  v42 = eventno;
  v9 = sub_8D3950(s32, &v42);
  v41 = rid;
  v10 = sub_8D3950(s32, &v41);
  v11 = Format_5268592("mse_{0:D}_{1:D}", v9, v10);
  data = Allocate(evtMotionSeData_t);
  evtMotionSeData_t___ctor(data);
  data->unitid = unitid;
  data->eventno = eventno;
  data->rid = rid;
  else
  {
    PackProcessData = evtGetPackProcessData(eventno);
    if (!PackProcessData)
      goto LABEL_31;
  }
  v15 = PackProcessData;
  data->bPlayed = NewSpecific(byte__, PackProcessData->header.TypeTableCount);
  if (v15->header.TypeTableCount >= 1)
  {
    v16 = 0;
    do
    {
      typetable = v15->typetable;
      if (typetable->m_Items[v16].Type == 6)
      {
        v20 = v15->typetable;
        if (v20->m_Items[v16].LinkID == data->rid)
        {
          v22 = v15->typetable;
          bPlayed = data->bPlayed;
          v25 = NewSpecific(byte, v22->m_Items[v16].ItemCount);
          v26 = v25;
          *&bPlayed[2 * v16 + 8] = v26;
          for (i = 32; ; ++i)
          {
            v29 = data->bPlayed;
            v30 = i - 32;
            if (v30 >= SLODWORD(v29->m_Items[v16]->max_length))
              break;
            v32 = data->bPlayed;
            v34 = v32->m_Items[v16];
            *(&v34->obj.klass + i) = 0;
          }
        }
      }
      ++v16;
    }
    while (v16 < v15->header.TypeTableCount);
  }
LABEL_31:
  data->OldFrame = -1;
  v36 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v36,
    0,
    Method_EventPack_evtMotionSeProcess1__);
  v37 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v37,
    0,
    Method_EventPack_evtMotionSeShutdown__);
  return dds3StartProcess(v11, 0x3ECu, 0, 0, v36, 0, v37, 0, data, 0);
}

// 0xfef1c0
void evtKillAllEventPackProcess(void) {
  u64 *v1;
  dds3ProcessID_t_o *id;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  id = v1;
  {
LABEL_6:
  }
  while (1)
  {
    id = dds3SearchProcessPriority(1004);
    if (!id)
      break;
    dds3KillProcess(&id, 0);
      goto LABEL_6;
  }
}

// 0xfef000
void evtKillEventPack(s32 eventno) {
  u64 *v3;
  Il2CppObject *ProcessData;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v12;
  s64 *v13;
  dds3ProcessID_t_o *v14[3];
  dds3ProcessID_t_o *id;

  v3 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v3);
  id = v3;
  else
  {
    id = evtSearchEventPack(eventno);
    if (!id)
      return;
  }
  ProcessData = dds3GetProcessData(&id);
  CurrentEvent = 0;
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPackProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, evtPackProcessData_t, v14);
    if ((v14[0] & 1) != 0)
      v12 = v14[2];
    else
      v12 = v14 + 1;
    v13 = sub_8C4940(v12);
  }
  LOBYTE(ProcessData[1].monitor) = 1;
  dds3KillProcess(&id, 0);
}

// 0xfeed20
dds3ProcessID_t *evtLoadEventPack(s32 eventno) {
  evtPackProcessData_t_o *data;
  u64 *v4;
  dds3ProcessID_t_o *result;
  u64 *v8;
  System_String_o *v9;
  System_String_o *v11;
  u64 *v12;
  u64 *v13;
  u64 *v15;
  u64 *v16;
  u64 *v17;
  dds3ProcessID_t_o *target;
  dds3ProcessID_t_o *parent;
  s32 v23;

  target = 0;
  data = Allocate(evtPackProcessData_t);
  evtPackProcessData_t___ctor(data);
  v4 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v4);
  parent = v4;
  else
  {
    result = evtSearchEventPack(eventno);
    parent = result;
    if (result)
      return result;
  }
  v23 = eventno;
  v8 = sub_8D3950(s32, &v23);
  v9 = Format("e{0:D3}_p", v8, 0);
  CurrentEvent = eventno;
  data->eventno = eventno;
  data->stat = 0;
  AssetLoadWait = 0;
  v11 = v9;
  v12 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v12,
    0,
    Method_EventPack_evtPackProcess1__);
  v13 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v13,
    0,
    Method_EventPack_evtPackShutdown__);
  parent = dds3StartProcess(v11, 0x3ECu, 1, 1, v12, 0, v13, 0, data, 0);
  v15 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v15);
  v16 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v16,
    0,
    Method_dds3UnityEx_evtUpdateEx_Unity__);
  v17 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v17,
    0,
    Method_dds3UnityEx_evtShutdownEx_Unity__);
  target = dds3StartProcess(v11, 0x2B0Au, 1, 1, v16, 0, v17, 0, data, 0);
  dds3LinkProcess(&parent, &target);
  SetShadowMode(kernelObject, 3);
  return parent;
}

// 0xfe8d40
void *evtMotionSeProcess1(dds3ProcessID_t *id) {
  u64 *v2;
  Il2CppObject *ProcessData;
  Il2CppObject *v6;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  u32 v13;
  dds3Basic_t_o *v14;
  dds3Basic_t_o *v16;
  s32 klass_high;
  evtPackProcessData_t_o *PackProcessData;
  Il2CppObject *workdata;
  Il2CppClass *v20;
  s64 v21;
  Il2CppClass *v22;
  evtPackProcessData_t_o *v23;
  UnityEngine_Object_o *v24;
  UnityEngine_GameObject_o *v26;
  UnityEngine_Component_o *Animator;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Object_o *Component_GUILayer;
  UnityEngine_Object_c *v33;
  const char *name;
  s32 castClass;
  f32 v40;
  s32 v41;
  f32 v42;
  s32 v43;
  s64 **v44;
  u64 v45;
  struct beTypeTable_s_array *typetable;
  struct beTypeTable_s_array *v48;
  struct beTypeTable_s_array *v50;
  struct beTypeTable_s_array *v52;
  s64 i;
  struct beTypeTable_s_array *v55;
  u64 v56;
  System_Byte_array *addr;
  beMotionSeTable_s_o *v59;
  Il2CppClass *v61;
  s64 v63;
  System_Object_array *v65;
  s64 **v67;
  s64 *v68;
  s64 *v70;
  s64 *v71;
  s64 *v76;
  s64 *v77;
  s64 *v82;
  s64 *v83;
  s64 *v88;
  s64 *v89;
  s64 *v94;
  s64 *v95;
  System_String_o *v98;
  System_Object_array *v100;
  Il2CppClass *v101;
  s64 v103;
  char *v105;
  s64 *v106;
  s32 v107;
  s32 Se;
  s32 v109;
  s32 Frame;
  UnityEngine_AnimatorStateInfo_o v111;
  char v112[4];
  s32 pos;
  UnityEngine_AnimatorStateInfo_o v114;
  dds3Basic_t_o *pBasic;
  dds3ProcessID_t_o *ida;

  ida = id;
  pBasic = 0;
  memset(&v114, 0, sizeof(v114));
  pos = 0;
  v112[0] = 0;
  v2 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v2);
  ProcessData = dds3GetProcessData(&ida);
  v6 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtMotionSeData_t)
    {
      sub_8FC2C0(klass->_1.element_class, evtMotionSeData_t, &v111);
      if ((v111.m_Name & 1) != 0)
        v9 = *&v111.m_Length;
      else
        v9 = &v111.m_Name + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else if (!dds3GetActiveScene())
  {
    goto LABEL_54;
  }
  pBasic = dds3GetActiveScene();
  v13 = v6[1].klass;
  v14 = dds3SearchSceneBasic(&pBasic, v13, 5u);
  if (!v14)
    goto LABEL_54;
  v16 = v14;
  klass_high = HIDWORD(v6[1].klass);
  else
  {
    PackProcessData = evtGetPackProcessData(klass_high);
    if (!PackProcessData)
      goto LABEL_54;
  }
  if (SHIDWORD(v6[1].klass) < 600)
    return 0;
  workdata = v16->workdata;
  v20 = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < v21
    || v20->_2.typeHierarchy[v21 - 1] != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(v20->_1.element_class, dds3UnitObjectBasicWorkData_t, &v111);
    if ((v111.m_Name & 1) != 0)
      v105 = *&v111.m_Length;
    else
      v105 = &v111.m_Name + 1;
    v106 = sub_8C4940(v105);
  }
  v22 = workdata[2].klass;
  if (!v22)
  {
LABEL_54:
    ida->func_ans = -1;
    return 0;
  }
  v23 = PackProcessData;
  v24 = *(v22->_1.methods + 16);
  if (!op_Equality(v24, 0, 0))
  {
    v26 = *(v22->_1.methods + 16);
    Animator = GetAnimator(v26);
    if (!op_Equality(Animator, 0, 0))
    {
      gameObject = get_gameObject(Animator);
      if (get_activeSelf(gameObject))
      {
        GetCurrentAnimatorStateInfo(&v111, Animator, 0);
        v114 = v111;
        GetCurrentAnimatorClipInfoCount(Animator, 0);
        v107 = *(v22->_1.interfaceOffsets + 25);
        Component_GUILayer = GetComponent_GUILayer_(Animator);
        if (!op_Equality(Component_GUILayer, 0, 0)
          && IsAnimStarted(Component_GUILayer, 0))
        {
          v33 = Component_GUILayer[1].klass;
          name = v33->_1.name;
          castClass = v33->_1.castClass;
          if (castClass != -1 && castClass == v107)
          {
            v40 = sub_85FB60(&v114);
            v41 = (v40 * get_targetFrameRate());
            if (v41)
            {
              if (sub_85FBA0(&v114) || sub_85FB40(&v114) < 1.0)
              {
                v42 = sub_85FB40(&v114);
                v43 = fmodf(v42 * v41, v41);
                if (v23->header.TypeTableCount < 1)
                  return 0;
              }
              else
              {
                v43 = v41 - 1;
                if (v23->header.TypeTableCount < 1)
                  return 0;
              }
              v44 = &"@@@@@@@@@@@ PlayMotionSE : ";
              v45 = 0;
              do
              {
                typetable = v23->typetable;
                if (typetable->m_Items[v45].Type == 6)
                {
                  v48 = v23->typetable;
                  if (v48->m_Items[v45].LinkID == LODWORD(v6[1].monitor))
                  {
                    v50 = v23->typetable;
                    if (v50->m_Items[v45].UserData == v107)
                    {
                      v52 = v23->typetable;
                      pos = v52->m_Items[v45].ItemAddress;
                      v112[0] = 0;
                      for (i = 32; ; ++i)
                      {
                        v55 = v23->typetable;
                        v56 = i - 32;
                        if (v56 >= v55->m_Items[v45].ItemCount)
                          break;
                        addr = v23->addr;
                        v59 = Allocate(beMotionSeTable_s);
                        beMotionSeTable_s___ctor(v59, addr, &pos);
                        if (v43 >= v59->Frame - 1 && v112[0] == 0)
                        {
                          v61 = v6[2].klass;
                          v63 = *(&v61->_1.byval_arg.data + v45);
                          if (!*(v63 + i))
                          {
                            v65 = NewSpecific(object, 0xAu);
                            v67 = v44;
                            v68 = *v44;
                            v65->m_Items[0] = v68;
                            v111.m_Name = i - 32;
                            v70 = sub_8D3950(s32, &v111);
                            v71 = v70;
                            v65->m_Items[1] = v71;
                            if ("[ "
                              && !QueryInterface("[ ", v65->obj.klass->_1.element_class))
                            {
                            }
                            v65->m_Items[2] = "[ ";
                            Frame = v59->Frame;
                            v76 = sub_8D3950(s32, &Frame);
                            v77 = v76;
                            v65->m_Items[3] = v77;
                            if (" - "
                              && !QueryInterface(" - ", v65->obj.klass->_1.element_class))
                            {
                            }
                            v65->m_Items[4] = " - ";
                            v109 = v43;
                            v82 = sub_8D3950(s32, &v109);
                            v83 = v82;
                            v65->m_Items[5] = v83;
                            if (" ]"
                              && !QueryInterface(" ]", v65->obj.klass->_1.element_class))
                            {
                            }
                            v65->m_Items[6] = " ]";
                            Se = v59->Se;
                            v88 = sub_8D3950(s32, &Se);
                            v89 = v88;
                            v65->m_Items[7] = v89;
                            if ("/"
                              && !QueryInterface("/", v65->obj.klass->_1.element_class))
                            {
                            }
                            v65->m_Items[8] = "/";
                            v94 = sub_3C0020(v112);
                            v95 = v94;
                            v65->m_Items[9] = v95;
                            v98 = Concat_5270224(v65);
                            v100 = Empty_string_();
                            Log(v98, v100, 0);
                            evtPlaySe(HIDWORD(v6[1].klass), v59->Se, 0);
                            v101 = v6[2].klass;
                            v103 = *(&v101->_1.byval_arg.data + v45);
                            v44 = v67;
                            *(v103 + i) = 1;
                          }
                        }
                      }
                    }
                  }
                }
                ++v45;
              }
              while (v45 < v23->header.TypeTableCount);
            }
          }
        }
      }
    }
  }
  return 0;
}

// 0xfe98d0
void *evtMotionSeShutdown(dds3ProcessID_t *id) {
  dds3ProcessID_t_o *ida;

  ida = id;
  dds3GetProcessData(&ida);
  ida->func_ans = -1;
  return 0;
}

// 0xfee430
void *evtPackProcess1(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  evtPackProcessData_t_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 klass_high;
  evtPackProcessData_t_o *v7;
  char *v9;
  s64 *v10;
  dds3ProcessID_t_o *v11[3];
  dds3ProcessID_t_o *ida;

  ida = id;
  ProcessData = dds3GetProcessData(&ida);
  klass = ProcessData->klass;
  if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPackProcessData_t)
  {
    sub_8FC2C0(klass->_1.element_class, evtPackProcessData_t, v11);
    if ((v11[0] & 1) != 0)
      v9 = v11[2];
    else
      v9 = v11 + 1;
    v10 = sub_8C4940(v9);
  }
  klass_high = HIDWORD(ProcessData[1].klass);
  v7 = ProcessData;
  if (klass_high == 1)
  {
    CheckLoadPack(v7, v3);
  }
  else if (!klass_high)
  {
    LoadPack(v7, v3);
  }
  return 0;
}

// 0xfee5b0
void *evtPackShutdown(dds3ProcessID_t *id) {
  Il2CppObject *ProcessData;
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  System_Object_array *v12;
  s64 *v15;
  s64 *v16;
  s64 *v19;
  s64 *v20;
  void **p_monitor;
  s64 *v24;
  s64 *v25;
  System_String_o *v27;
  System_Object_array *v29;
  evtTexManager_o *monitor;
  evtTexManager_o *currTexMngr;
  s32 v36;
  UnityEngine_Object_o *v44;
  s32 v47;
  dds3ProcessID_t_o *ida;
  u64 v49[3];

  ida = id;
  ProcessData = dds3GetProcessData(&ida);
  v4 = ProcessData;
  if (ProcessData)
  {
    klass = ProcessData->klass;
    if (ProcessData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != evtPackProcessData_t)
    {
      sub_8FC2C0(klass->_1.element_class, evtPackProcessData_t, v49);
      if ((v49[0] & 1) != 0)
        v7 = v49[2];
      else
        v7 = v49 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  fldFreeNextFile();
  if (LODWORD(v4[1].klass) == 618)
  {
    typeClose = 1;
  }
  v12 = NewSpecific(object, 6u);
  v12->m_Items[0] = "evtPackShutdown : ";
  LODWORD(v49[0]) = fldGb->fieldID;
  v15 = sub_8D3950(s32, v49);
  v16 = v15;
  v12->m_Items[1] = v16;
  v12->m_Items[2] = ",";
  v47 = v4[1].klass;
  v19 = sub_8D3950(s32, &v47);
  v20 = v19;
  v12->m_Items[3] = v20;
  v12->m_Items[4] = " : ";
  p_monitor = &v4[1].monitor;
  v24 = sub_3C0020(&v4[1].monitor);
  v25 = v24;
  v12->m_Items[5] = v25;
  v27 = Concat_5270224(v12);
  v29 = Empty_string_();
  Log(v27, v29, 0);
  Destroy(1, 0);
  monitor = v4[11].monitor;
  if (monitor)
  {
    Destroy(monitor, 1, 0);
    v4[11].monitor = 0;
  }
  else
  {
    if (currTexMngr)
    {
      Destroy(currTexMngr, 1, 0);
    }
  }
  else
  {
    currTexMngr = 0;
    if (*p_monitor)
      goto LABEL_83;
  }
  v36 = v4[1].klass;
  SpEvtUnloadAll(v36);
  UnloadUnusedAssets();
LABEL_83:
  *p_monitor = 0;
  RemoveKeys(5, 0);
  v44 = v4[9].monitor;
  if (op_Inequality(v44, 0, 0))
  {
    Eve_DistortionBlurSetDefTex();
    v4[9].monitor = 0;
  }
  if (v4[10].klass)
  {
    Eve_PartialMultiBlurSetDefTex();
    v4[10].klass = 0;
  }
  if (v4[10].monitor)
  {
    Eve_RippleBlurSetDefTex();
    v4[10].monitor = 0;
  }
  if (v4[11].klass)
  {
    Eve_PartialMultiFilterSetDefTex();
    v4[11].klass = 0;
  }
  if (v4[2].klass)
    v4[2].klass = 0;
  if (v4[2].monitor)
    v4[2].monitor = 0;
  if (v4[7].klass)
    v4[7].klass = 0;
  if (v4[8].monitor)
    v4[8].monitor = 0;
  ida->func_ans = -1;
  return 0;
}

// 0xfe8820
s32 evtRegistBEField(s32 eventno, s32 rid) {
  u64 *v5;
  evtPackProcessData_t_o *PackProcessData;
  evtPackProcessData_t_o *v9;
  u64 v10;
  System_Byte_array *v11;
  System_Byte_array *v12;
  s32 v13;
  s64 v14;
  struct beTypeTable_s_array *typetable;
  struct beTypeTable_s_array *v17;
  s32 v19;
  struct beTypeTable_s_array *v20;
  u32 v22;
  System_Byte_array *v23;
  struct beTypeTable_s_array *v24;
  s32 v26;
  System_Array_o *v27;
  System_Array_o *addr;
  struct beTypeTable_s_array *v29;
  System_Byte_array *v31;
  struct beTypeTable_s_array *v32;
  struct beTypeTable_s_array *v34;
  System_Byte_array *v36;
  struct beTypeTable_s_array *v37;
  struct beTypeTable_s_array *v39;
  struct beTypeTable_s_array *v41;
  struct beTypeTable_s_array *v43;
  System_Byte_array *v45;
  s32 v46;
  bool v50;
  s32 v51;
  dds3KernelDraw_c *v52;
  s32 v54;
  s32 area;
  System_Byte_array *pF1;
  u64 v57[2];
  s32 v58;

  v58 = 0;
  v5 = Allocate(evtPackProcessData_t);
  evtPackProcessData_t___ctor(v5);
  PackProcessData = evtGetPackProcessData(eventno);
  if (PackProcessData->header.TypeTableCount < 1)
    return 0;
  v9 = PackProcessData;
  v54 = eventno;
  area = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 52;
  pF1 = 0;
  do
  {
    typetable = v9->typetable;
    if (*(&typetable->obj.klass + v14) == rid)
    {
      v17 = v9->typetable;
      v19 = *(v17 + v14 - 20);
      switch (v19)
      {
        case 4:
          v29 = v9->typetable;
          v22 = *(v29 + v14 - 16);
          v31 = NewSpecific(byte, v22);
          v32 = v9->typetable;
          v12 = v31;
          v26 = *(v32 + v14 - 8);
          addr = v9->addr;
          v27 = v12;
          break;
        case 3:
          v34 = v9->typetable;
          v22 = *(v34 + v14 - 16);
          v36 = NewSpecific(byte, v22);
          v37 = v9->typetable;
          v11 = v36;
          v26 = *(v37 + v14 - 8);
          addr = v9->addr;
          v27 = v11;
          break;
        case 2:
          v20 = v9->typetable;
          v22 = *(v20 + v14 - 16);
          v23 = NewSpecific(byte, v22);
          v24 = v9->typetable;
          pF1 = v23;
          v26 = *(v24 + v14 - 8);
          v27 = v23;
          addr = v9->addr;
          break;
        default:
          goto LABEL_32;
      }
      BlockCopy(addr, v26, v27, 0, v22);
    }
LABEL_32:
    v39 = v9->typetable;
    if (*(v39 + v14 - 4) == rid)
    {
      v41 = v9->typetable;
      if (*(v41 + v14 - 20) == 1)
      {
        v43 = v9->typetable;
        v58 = *(v43 + v14 - 8);
        v45 = v9->addr;
        v57[0] = 0;
        v57[1] = 0;
        sub_134F940(v57, v45, &v58);
        v13 = v57[0];
        area = HIDWORD(v57[0]);
      }
    }
    ++v10;
    v14 += 32;
  }
  while (v10 < v9->header.TypeTableCount);
  v46 = 0;
  if (!v12 || !v11 || !pF1)
    return v46;
  if (!FldDataCheck(v13, area))
    return 0;
  evtLoadArea_FromMemory(v13, area, pF1, v11, v12, 0);
  fldFileAddrResetMode(1);
  v50 = v54 != 602;
  if (v54 >= 740)
    v50 = v54 > 749;
  if (v54 == 671 || v54 == 635)
  {
    v51 = 0;
    goto LABEL_60;
  }
  v51 = (v54 - 800) > 9 && v50;
  if (v54 == 655)
  {
LABEL_69:
    v46 = 1;
    Postblur_AccumTex_NowMode = 1;
    if ((v51 & 1) != 0)
    {
      if ((v52->_2.bitflags2 & 2) != 0)
        goto LABEL_74;
      goto LABEL_76;
    }
  }
  else
  {
LABEL_60:
    if (v54 == 726)
      return 1;
    if (v54 == 684)
      goto LABEL_69;
    if (!v51)
    {
      return 1;
    }
    else
    {
      {
LABEL_74:
      }
LABEL_76:
      v46 = 1;
      SetDrawFlag(0x2000000u, 1u);
    }
  }
  return v46;
}

// 0xfe8100
s32 evtRegistBEUnit(s32 eventno, s32 rid) {
  evtPackProcessData_t_o *PackProcessData;
  u64 *v6;
  UnityEngine_GameObject_o *v7;
  Il2CppObject *Component_object;
  s64 v10;
  u64 v11;
  s32 v12;
  struct beTypeTable_s_array *typetable;
  struct beTypeTable_s_array *v15;
  struct beNameTable_s_array *nametable;
  struct beTypeTable_s_array *v22;
  s64 NameIndex;
  struct System_Text_StringBuilder_o *v26;
  Il2CppObject *com_str;
  System_Text_StringBuilder_o *be_bnm;
  Il2CppObject *v31;
  System_String_o *v32;
  System_String_o *v33;
  System_Object_array *v35;
  System_String_o *v36;
  System_String_o *v37;
  struct beTypeTable_s_array *v38;
  System_String_o *v39;
  s32 ItemSize;
  u64 *v42;
  u64 *v44;
  s32 evtRegistBEUnit_minor;
  dds3Basic_t_o *v49;
  System_String_o *v50;
  System_String_o *v51;
  System_Object_array *v52;
  System_String_o *v54;
  System_String_o *v56;
  s32 v58;
  u64 *v61;
  u64 *v63;
  s32 v65;
  s32 v66;
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  v66 = eventno;
  PackProcessData = evtGetPackProcessData(eventno, *&rid);
  v6 = sub_8D3950(s32, &v66);
  com_str = Format("e{0:D3}", v6, 0);
  v7 = Find("kernel", 0);
  Component_object = GetComponent_object_(v7);
  SetActive(Component_object[15].monitor, 1, 0);
  if (evtRegistBEUnit_minor == evtRegistBEUnit_buf)
  {
    if (PackProcessData->header.TypeTableCount < 1)
    {
      return -1;
    }
    else
    {
      v10 = 0;
      v11 = 0;
      v12 = -1;
      while (1)
      {
        typetable = PackProcessData->typetable;
        if (typetable->m_Items[v10].ID == rid)
        {
          v15 = PackProcessData->typetable;
          if (v15->m_Items[v10].Type == 5)
            break;
        }
        ++v11;
        ++v10;
        if (v11 >= PackProcessData->header.TypeTableCount)
          return v12;
      }
      Clear(be_name, 0);
      v22 = PackProcessData->typetable;
      nametable = PackProcessData->nametable;
      NameIndex = v22->m_Items[v10].NameIndex;
      Append_5398496(be_name, nametable->m_Items[NameIndex]->Name);
      v26 = Replace(
              be_name,
              " ",
              "",
              0);
      be_name = v26;
      Clear(be_bnm, 0);
      v31 = (be_name->klass->vtable._3_ToString.methodPtr)(
              be_name,
              be_name->klass->vtable._3_ToString.method);
      AppendFormat_5402480(be_bnm, "event/{0}/{1}", com_str, v31);
      v32 = (be_bnm->klass->vtable._3_ToString.methodPtr)(
              be_bnm,
              be_bnm->klass->vtable._3_ToString.method);
      v33 = Concat_5224608("Load PB : ", v32);
      v35 = Empty_string_();
      Log(v33, v35, 0);
      v36 = (be_bnm->klass->vtable._3_ToString.methodPtr)(
              be_bnm,
              be_bnm->klass->vtable._3_ToString.method);
      v37 = ToUpper(v36, 0);
      v38 = PackProcessData->typetable;
      v39 = v37;
      ItemSize = v38->m_Items[v10].ItemSize;
      v66 = rid;
      v42 = sub_8D3950(s32, &v66);
      v65 = ItemSize;
      v44 = sub_8D3950(s32, &v65);
      Write_2930752("unit decode rid:{0:D}, size:{1:D}\n", v42, v44, 0);
      v12 = evtSetRegistUnit(3, evtRegistBEUnit_minor);
      pBasic = dds3GetControlScene();
      v49 = dds3SearchSceneBasic(&pBasic, v12, 5u);
      v50 = (be_name->klass->vtable._3_ToString.methodPtr)(
              be_name,
              be_name->klass->vtable._3_ToString.method);
      v51 = Concat_5271136("AttachModel : ", v39, ", ", v50, 0);
      v52 = Empty_string_();
      Log(v51, v52, 0);
      v54 = com_str;
      v56 = (be_name->klass->vtable._3_ToString.methodPtr)(
              be_name,
              be_name->klass->vtable._3_ToString.method);
      v58 = AttachModel_26586560(v49, v54, v39, v56);
      ++evtRegistBEUnit_minor;
      if (evtRegistBEUnit_minor >= 2000)
      {
        evtRegistBEUnit_minor = 1000;
      }
      if (v58)
      {
        save_serial = v12;
        return -2;
      }
      else
      {
        evtRegistBEUnit_buf = evtRegistBEUnit_minor;
        v66 = evtRegistBEUnit_minor;
        v61 = sub_8D3950(s32, &v66);
        v65 = ItemSize;
        v63 = sub_8D3950(s32, &v65);
        Write_2930752("BE regist unit {0:D} < {1:D} >\n", v61, v63);
      }
    }
  }
  else
  {
    LoadEventModel();
    if (IsStartModelLoaded())
    {
      ++evtRegistBEUnit_minor;
      if (evtRegistBEUnit_minor >= 2000)
      {
        evtRegistBEUnit_minor = 1000;
      }
      evtRegistBEUnit_buf = evtRegistBEUnit_minor;
      return save_serial;
    }
    else
    {
      return -2;
    }
  }
  return v12;
}

// 0xfe7500
dds3ProcessID_t *evtSearchEventPack(s32 eventno) {
  u64 *v4;
  System_String_o *com_str;
  s32 v8;

LABEL_7:
  v8 = eventno;
  v4 = sub_8D3950(s32, &v8);
  com_str = Format("e{0:D3}_p", v4, 0);
  return dds3SearchProcessName(com_str);
}
