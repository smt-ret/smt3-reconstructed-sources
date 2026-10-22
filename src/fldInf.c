#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct FLD_INF_ALL_t FLD_INF_ALL_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct scrProcessWork_s scrProcessWork_s;
typedef struct warp_elvtbl_s warp_elvtbl_s;

static FLD_INF_ALL_t *gFldInf;
static s32 gFldInfIdx;
static s32 gFldInf_HitIdx;
static s32 gFldInf_WpExit;
static char *scriptlabel[8];

void CallBattleSub2(s32 encno);
bool IsDLCField(s32 area);
u8 **LoadFileByte(AssetBundleCtrl *this, char *key, char *path_name);
s32 SetCopy(warp_elvtbl_s *this, u8 **data, s32 pos);
void datAddItem(s32 id, s32 num);
void datAddMaka(s32 addmaka);
dds3Basic_t *dds3GetActiveScene(void);
dds3Basic_t *dds3SceneBasicSearchName(dds3Basic_t **scene, char *name);
dds3ProcessID_t *dds3SceneBasicStartScript(dds3Basic_t **scene, char *procname);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic);
bool evtBitCheck(s32 no);
void evtBitOff(s32 no);
void evtBitOn(s32 no);
void evtSetUnitPos(s32 unitID, s32 posID);
dds3Basic_t *fldCamNowEveCamera(bool nc);
char *fldDoor_Find2(char **evename);
s32 fldDoor_GetHasigoTbl(s32 getmode);
char *fldInf_FindTypeEveNpc(char **evename);
void fldKaifukuTest(void);
void fldMakeFilePath(char **pathstr, s32 field, s32 area);
void fldPlayerAnimation(s32 act, bool init);
void fldPlayerOff(void);
void fldPlayerOn(void);
void fldProcNext(s32 fld, s32 eveno);
void resetCamNormal(void);
void resetCamTgtPlayer(void);
void scrAllReleaseScript(void);
scrProcessWork_s *scrSearchScriptName(char *scriptname);

// 0x10b8960
s32 fldInfChkFastPanel(s32 aline) {
  s64 v2;
  s64 v4;
  s32 *static_fields;
  s64 v6;
  s64 v7;
  s64 v9;
  s64 v11;
  s64 v14;
  s32 *v15;
  s64 v16;
  s64 v17;
  s64 v19;
  s32 *v23;
  s64 v24;
  s64 v25;
  s64 v27;
  s32 *v30;
  s64 v31;
  s64 v32;
  s64 v34;
  bool v36;
  s32 *v37;
  s64 v38;
  s64 v39;
  s64 v41;
  s64 v43;
  s32 *v45;
  s64 v46;
  s64 v47;
  s32 *v49;
  s64 v50;
  s64 v51;
  s64 v53;
  s32 *v56;
  s64 v57;
  s64 v58;
  s64 v60;
  s32 *v63;
  s64 v64;
  s64 v65;
  u64 v67;
  s32 result;
  struct fldResHead_t_array *gEvnRng;
  s64 gFldInf_HitIdx;
  struct FLD_INF_SET_t_array *set;
  s64 gFldInfIdx;
  struct fldResHead_t_array *v83;
  s64 v84;
  System_String_o **p_resourceName;

  LODWORD(v2) = aline;
  while (1)
  {
    if (v2 > 9)
    {
      v4 = v2 - 10LL;
      v6 = *(*static_fields + 40LL);
      v7 = static_fields[2];
      v9 = *(*(v6 + 8 * v7 + 32) + 32LL);
      if (v4 >= *(v9 + 24))
        goto LABEL_11;
LABEL_12:
      v11 = *(*(v9 + 8 * v4 + 32) + 24LL);
      v2 = *(v11 + 32);
      if ((v2 - 101) < 5)
        return v2;
      goto LABEL_15;
    }
    v4 = v2 - 1LL;
    v24 = *(*v23 + 40LL);
    v25 = v23[2];
    v27 = *(*(v24 + 8 * v25 + 32) + 24LL);
    if (!*(*(v27 + 8 * v4 + 32) + 16LL))
    {
        goto LABEL_63;
LABEL_60:
LABEL_63:
      v46 = *(*v45 + 40LL);
      v47 = v45[2];
      v9 = *(*(v46 + 8 * v47 + 32) + 24LL);
      if (v4 >= *(v9 + 24))
      {
LABEL_11:
      }
      goto LABEL_12;
    }
    v31 = *(*v30 + 40LL);
    v32 = v30[2];
    v34 = *(*(v31 + 8 * v32 + 32) + 24LL);
    v36 = evtBitCheck(*(*(v34 + 8 * v4 + 32) + 16LL), 0);
    if (!v36)
    {
        goto LABEL_63;
      goto LABEL_60;
    }
    v38 = *(*v37 + 40LL);
    v39 = v37[2];
    v41 = *(*(v38 + 8 * v39 + 32) + 24LL);
    v43 = *(*(v41 + 8 * v4 + 32) + 24LL);
    v2 = *(v43 + 33);
    if ((v2 - 101) < 5)
      return v2;
LABEL_15:
    if (!v2)
      return v2;
    if (v2 == 100)
      break;
    if (v2 <= 9)
    {
LABEL_58:
    }
    else
    {
      v14 = v2 - 10;
      v16 = *(*v15 + 40LL);
      v17 = v15[2];
      v19 = *(*(v16 + 8 * v17 + 32) + 32LL);
      if (*(*(v19 + 8 * v14 + 32) + 16LL) != -1)
      {
        v50 = *(*v49 + 40LL);
        v51 = v49[2];
        v53 = *(*(v50 + 8 * v51 + 32) + 32LL);
        if (!*(*(v53 + 8 * v14 + 32) + 16LL))
          goto LABEL_127;
        v57 = *(*v56 + 40LL);
        v58 = v56[2];
        v60 = *(*(v57 + 8 * v58 + 32) + 32LL);
        if (*(*(v60 + 8 * v14 + 32) + 16LL) == 1)
        {
LABEL_127:
          v64 = *(*v63 + 40LL);
          v65 = v63[2];
          v67 = *(*(*(v64 + 8 * v65 + 32) + 16LL) + 20LL);
          if (v67 < 4)
            return dword_32C3B50[v67];
        }
        LODWORD(v2) = 0;
        return v2;
      }
        goto LABEL_58;
    }
  }
  fldInf_FindTypeEveNpc(&gEvnRng->m_Items[gFldInf_HitIdx]->resourceName);
  set = gFldInf->set;
  if (!set->m_Items[gFldInfIdx]->st->Action)
  {
    LODWORD(v2) = 199;
    return v2;
  }
  v83 = gEvnRng;
  v84 = gFldInf_HitIdx;
  p_resourceName = &v83->m_Items[v84]->resourceName;
  fldDoor_Find2(p_resourceName);
  LODWORD(v2) = 102;
  switch (gFldWapPanel)
  {
    case 3:
      return v2;
    case 5:
      if (fldDoor_GetHasigoTbl(0))
        result = 105;
      else
        result = 104;
      break;
    case 6:
      LODWORD(v2) = 106;
      return v2;
    case 7:
      LODWORD(v2) = 107;
      return v2;
    default:
      LODWORD(v2) = 100;
      return v2;
  }
  return result;
}

// 0x10ba7c0
s32 fldInfGet(s32 aline, s32 acol) {
  s64 v5;
  s32 *v7;
  s64 v8;
  s64 v9;
  s64 v11;
  s32 *static_fields;
  s64 v16;
  s64 v17;
  s64 v19;

  v5 = aline - 10LL;
  if (acol == 1)
  {
    v16 = *(*static_fields + 40LL);
    v17 = static_fields[2];
    v19 = *(*(v16 + 8 * v17 + 32) + 32LL);
    return *(*(v19 + 8LL * v5 + 32) + 18LL);
  }
  else if (acol)
  {
    return 0;
  }
  else
  {
    v8 = *(*v7 + 40LL);
    v9 = v7[2];
    v11 = *(*(v8 + 8 * v9 + 32) + 32LL);
    return *(*(v11 + 8 * v5 + 32) + 16LL);
  }
}

// 0x10ba950
void fldInfLoad(s32 field) {
  u64 *v3;
  u64 *v6;
  System_String_o *v8;
  bool IsDLCField;
  s64 *v10;
  System_String_o *v12;
  Il2CppObject *v13;
  u64 *v14;
  System_String_o *v16;
  AssetBundleCtrl_o *asset_bc;
  System_Byte_array *FileByte;
  s32 v21;
  System_String_o *pathstr;

  pathstr = 0;
  if (field <= 199)
  {
    v3 = Allocate(FLD_INF_ALL_t);
    _ctor(v3, 0);
    gFldInf = v3;
    v21 = field;
    pathstr = "";
    v6 = sub_8D3950(s32, &v21);
    v8 = Format("f{0:D3}", v6, 0);
    IsDLCField = IsDLCField(field);
    v10 = &"m";
    if (!IsDLCField)
      v10 = &"";
    v12 = Concat_5224608(v8, *v10);
    fldMakeFilePath(&pathstr, field, 1);
    v13 = pathstr;
    v21 = field;
    v14 = sub_8D3950(s32, &v21);
    v16 = Format_5268592("{0}F{1:D3}.INF.bytes", v13, v14);
    asset_bc = get_asset_bc();
    FileByte = LoadFileByte(asset_bc, v12, v16);
    SetCopy(gFldInf, FileByte, 0);
  }
}

// 0x10bab70
void fldInfLoadFromMem(void *data) {
  ;
}

// 0x10b90d0
s32 fldInfNext(s32 aline, s32 asel) {
  u64 *v5;
  s64 v8;
  s32 *static_fields;
  s64 v10;
  s64 v11;
  s64 v13;
  s64 v15;
  u8 *v17;
  s32 *v19;
  s64 v20;
  s64 v21;
  s64 v23;
  s32 *v26;
  s64 v27;
  s64 v28;
  s64 v30;
  bool v32;
  s32 *v33;
  s64 v34;
  s64 v35;
  s64 v37;
  s64 v39;
  s32 *v41;
  s64 v42;
  s64 v43;
  s64 v45;
  s64 v47;
  u32 v49;
  signed s32 v50;
  s32 *v52;
  s64 v53;
  s64 v54;
  s64 v56;
  s64 v58;
  s32 *v61;
  s64 v62;
  s64 v63;
  s64 v65;
  s64 v67;
  s32 *v71;
  s64 v72;
  s64 v73;
  s64 v75;
  s32 *v78;
  s64 v79;
  s64 v80;
  s64 v81;
  s64 v83;
  s64 v85;
  s32 *v89;
  s64 v90;
  s64 v91;
  s64 v92;
  s64 v94;
  s64 v96;
  s32 v98;
  struct FLD_INF_EX_t_array *ex;
  struct FLD_INF_SET_t_array *set;
  s64 gFldInfIdx;
  struct FLD_INF_MSG_t_array *ms;
  s64 v106;
  s32 Param2;
  s32 fieldID;
  s32 *v115;
  s64 v116;
  s64 v117;
  s64 v119;
  s64 v120;
  s64 v121;
  s64 v123;
  s64 v124;
  struct FLD_INF_EX_t_array *v126;
  struct FLD_INF_EX_t_array *v130;
  struct FLD_INF_EX_t_array *v132;
  u32 max_length;
  s32 cammode;
  struct FLD_INF_EX_t_array *v137;
  struct FLD_INF_EX_t_array *v140;
  s32 v142;
  s32 Param1;
  s32 v146;
  s32 *v147;
  s64 v148;
  s64 v149;
  s64 v151;
  s64 v153;
  s64 v154;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  struct FLD_INF_VIEW_t_array *view;
  struct FLD_INF_VIEW_t_array *v165;
  struct FLD_INF_VIEW_t_array *v169;
  System_String_o *PlayerPos;
  dds3Basic_t_o *v172;
  dds3Basic_t_o *v173;
  s32 serialID;
  s32 v176;
  struct FLD_INF_VIEW_t_array *v178;
  s32 v185;
  struct FLD_INF_VIEW_t_array *v187;
  System_String_o *Cam;
  dds3Basic_t_o *v190;
  u32 v192;
  char *v195;
  s64 *v196;
  dds3Basic_t_o *handle;
  dds3Basic_t_o *v198[3];
  dds3Basic_t_o *scene;

  scene = 0;
  handle = 0;
  v5 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v5);
  if (aline > 9)
  {
    v8 = aline - 10LL;
    v10 = *(*static_fields + 40LL);
    v11 = static_fields[2];
    v13 = *(*(v10 + 8 * v11 + 32) + 32LL);
    v15 = *(*(v13 + 8 * v8 + 32) + 24LL);
    v17 = (v15 + asel + 32);
    goto LABEL_51;
  }
  v8 = aline - 1LL;
  v20 = *(*v19 + 40LL);
  v21 = v19[2];
  v23 = *(*(v20 + 8 * v21 + 32) + 24LL);
  if (!*(*(v23 + 8 * v8 + 32) + 16LL))
  {
      goto LABEL_44;
LABEL_41:
    goto LABEL_44;
  }
  v27 = *(*v26 + 40LL);
  v28 = v26[2];
  v30 = *(*(v27 + 8 * v28 + 32) + 24LL);
  v32 = evtBitCheck(*(*(v30 + 8 * v8 + 32) + 16LL), 0);
  if (v32)
  {
    v34 = *(*v33 + 40LL);
    v35 = v33[2];
    v37 = *(*(v34 + 8 * v35 + 32) + 24LL);
    v39 = *(*(v37 + 8 * v8 + 32) + 24LL);
    v17 = (v39 + 33);
    goto LABEL_51;
  }
    goto LABEL_41;
LABEL_44:
  v42 = *(*v41 + 40LL);
  v43 = v41[2];
  v45 = *(*(v42 + 8 * v43 + 32) + 24LL);
  v47 = *(*(v45 + 8 * v8 + 32) + 24LL);
  v17 = (v47 + 32);
LABEL_51:
  v49 = *v17;
  v50 = v49 - 10;
  if (v49 >= 0xA && v49 != 100)
  {
    v53 = *(*v52 + 40LL);
    v54 = v52[2];
    v56 = *(*(v53 + 8 * v54 + 32) + 32LL);
    v58 = *(*(v56 + 8LL * v50 + 32) + 32LL);
    if (*(v58 + 32))
      evtBitOff(*(v58 + 32), 0);
    v62 = *(*v61 + 40LL);
    v63 = v61[2];
    v65 = *(*(v62 + 8 * v63 + 32) + 32LL);
    v67 = *(*(v65 + 8LL * v50 + 32) + 32LL);
    if (*(v67 + 34))
      evtBitOn(*(v67 + 34), 0);
  }
  else
  {
    scene = dds3GetActiveScene();
    if (v49 < 0xA || v49 == 100)
    {
LABEL_77:
      if (v49)
        return v49;
      v72 = *(*v71 + 40LL);
      v73 = v71[2];
      v75 = *(*(v72 + 8 * v73 + 32) + 32LL);
      if (*(*(v75 + 8LL * v8 + 32) + 42LL))
      {
        v79 = v78[2];
        v80 = *(*v78 + 32LL);
        v81 = *(*v78 + 40LL);
        v83 = *(*(v81 + 8 * v79 + 32) + 32LL);
        v85 = *(*(v83 + 8LL * v8 + 32) + 42LL);
        if (*(*(v80 + 8 * v85 + 32) + 16LL) == 4)
        {
          scrAllReleaseScript();
          v90 = v89[2];
          v91 = *(*v89 + 32LL);
          v92 = *(*v89 + 40LL);
          v94 = *(*(v92 + 8 * v90 + 32) + 32LL);
          v96 = *(*(v94 + 8LL * v8 + 32) + 42LL);
          v98 = *(*(v91 + 8 * v96 + 32) + 20LL);
          ex = gFldInf->ex;
          set = gFldInf->set;
          ms = set->m_Items[gFldInfIdx]->ms;
          v106 = ms->m_Items[v8]->Ex;
          Param2 = ex->m_Items[v106]->Param2;
          fieldID = fldGb->fieldID;
          fldProcNext(fieldID, v98);
          CallBattleSub2(v98);
          if (Param2 == 1)
          {
            fldGb->FukiTalk = 1;
          }
          return v98 + 200;
        }
      }
      if (fldCamNowEveCamera(0))
      {
        cammode = fldGb->cammode;
        switch (cammode)
        {
          case 3:
            goto LABEL_315;
          case 1:
            resetCamTgtPlayer();
            return 0;
          case 0:
LABEL_315:
            resetCamNormal();
            break;
        }
      }
      return 0;
    }
  }
  v116 = *(*v115 + 40LL);
  v117 = v115[2];
  v119 = v116 + 8 * v117;
  v120 = v50;
  v121 = *(*(v119 + 32) + 32LL);
  v123 = *(v121 + 8LL * v50 + 32);
  v124 = *(v123 + 42);
  if (!*(v123 + 42))
    goto LABEL_198;
  v126 = gFldInf->ex;
  if (v126->m_Items[v124]->Id != 1)
  {
    v130 = gFldInf->ex;
    if (v130->m_Items[v124]->Id == 2)
    {
      v132 = gFldInf->ex;
      max_length = v132->max_length;
      Param1 = v132->m_Items[v124]->Param1;
      v146 = gFldInf->ex->m_Items[v124]->Param2;
      datAddItem(Param1, v146);
    }
    else
    {
      v137 = gFldInf->ex;
      if (v137->m_Items[v124]->Id == 3)
      {
        v140 = gFldInf->ex;
        v142 = v140->m_Items[v124]->Param1;
        datAddMaka(v142);
          goto LABEL_148;
        goto LABEL_199;
      }
    }
LABEL_198:
      goto LABEL_199;
    goto LABEL_148;
  }
  fldKaifukuTest();
  {
LABEL_148:
  }
LABEL_199:
  v148 = *(*v147 + 40LL);
  v149 = v147[2];
  v151 = *(*(v148 + 8 * v149 + 32) + 32LL);
  v153 = *(v151 + 8 * v120 + 32);
  v154 = *(v153 + 40);
  if (!*(v153 + 40))
    return v49;
  workdata = player->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3UnitObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3UnitObjectBasicWorkData_t, v198);
    if ((v198[0] & 1) != 0)
      v195 = v198[2];
    else
      v195 = v198 + 1;
    v196 = sub_8C4940(v195);
  }
  if (!workdata[2].klass)
  {
LABEL_220:
      goto LABEL_227;
    goto LABEL_221;
  }
  view = gFldInf->view;
  if (view->m_Items[v154]->PlayerOn == 1)
  {
    fldPlayerOn();
    goto LABEL_220;
  }
  fldPlayerOff();
  {
LABEL_221:
  }
LABEL_227:
  v165 = gFldInf->view;
  if (!IsNullOrEmpty(v165->m_Items[v154]->PlayerPos))
  {
    v169 = gFldInf->view;
    PlayerPos = v169->m_Items[v154]->PlayerPos;
    v172 = dds3SceneBasicSearchName(&scene, PlayerPos);
    if (v172)
    {
      v173 = v172;
      serialID = player->serialID;
      v176 = v173->serialID;
      evtSetUnitPos(serialID, v176);
    }
  }
  v178 = gFldInf->view;
  if (IsNullOrEmpty(v178->m_Items[v154]->Cam))
  {
    if (fldCamNowEveCamera(0))
    {
      handle = fldFollowCameraControl->handle;
      dds3SetActiveCameraSceneBasic(&scene, &handle);
      v185 = fldGb->cammode;
      if (v185 == 3)
      {
LABEL_278:
        resetCamNormal();
        return v49;
      }
      if (v185 != 1)
      {
        if (v185)
          return v49;
        goto LABEL_278;
      }
      resetCamTgtPlayer();
    }
  }
  else
  {
    v187 = gFldInf->view;
    Cam = v187->m_Items[v154]->Cam;
    v190 = dds3SceneBasicSearchName(&scene, Cam);
    if (v190)
    {
      v192 = v190->serialID;
      handle = dds3SearchSceneBasic(&scene, v192, 4u);
      if (handle)
      {
        dds3SetActiveCameraSceneBasic(&scene, &handle);
      }
    }
  }
  return v49;
}

// 0x10bab80
void fldInfToWAP(void) {
  s64 gFldInf_HitIdx;
  struct fldResHead_t_array *gEvnRng;
  System_String_o **p_resourceName;
  System_String_o *v10;
  s32 v15;
  s64 *started;
  struct dds3ProcessID_t_array *gEvnRngPid;
  dds3Basic_t_o *scene;

  scene = 0;
  gFldInf_WpExit = 1;
  p_resourceName = &gEvnRng->m_Items[gFldInf_HitIdx]->resourceName;
  v10 = fldDoor_Find2(p_resourceName);
  else if (scrSearchScriptName(v10))
  {
    return;
  }
  scene = dds3GetActiveScene();
  if ((fldGb->fieldID & 0xFFFFFFFE) == 0x3C)
    v15 = 5;
  else
    v15 = 0;
  fldPlayerAnimation(v15, 0);
  started = dds3SceneBasicStartScript(&scene, v10);
  gEvnRngPid->m_Items[gFldInf_HitIdx] = started;
}

// 0x10b7b20
char *fldInf_FindTypeEve(char **evename) {
  u64 v3;
  struct FLD_INF_PACK_t_array *pack;
  s64 v7;
  struct FLD_INF_PACK_t_array *v9;
  u64 v10;
  struct FLD_INF_PACK2_t_array *EveHit;
  s32 v15;
  System_String_o *v17;
  struct FLD_INF_PACK_t_array *v18;
  struct FLD_INF_PACK2_t_array *v20;
  struct FLD_INF_PACK_t_array *v24;
  s32 gFldInfIdx;
  s32 Idx;
  struct FLD_INF_SET_t_array *v28;
  s64 i;
  u64 v33;
  struct FLD_INF_SET_t_array *set;
  struct FLD_INF_SET_t_array *v37;
  s32 v40;
  System_String_o *v42;
  struct FLD_INF_SET_t_array *v43;
  struct System_String_array *scriptlabel;

  if (!*evename)
    return 0;
  v3 = 0;
  while (1)
  {
    pack = gFldInf->pack;
    if (pack->m_Items[v3]->Idx)
      break;
LABEL_44:
    if (v3++ >= 7)
    {
      for (i = 4; ; ++i)
      {
        v33 = i - 4;
        set = gFldInf->set;
        if (*(*(*(&set->obj.klass + i) + 16LL) + 16LL) == 1)
        {
          v37 = gFldInf->set;
          v40 = *(*(*(&v37->obj.klass + i) + 16LL) + 18LL);
          if (fldGb->areaID + 1 == v40)
          {
            v42 = *evename;
            v43 = gFldInf->set;
            if (!Compare(v42, *(*(*(&v43->obj.klass + i) + 16LL) + 24LL), 0))
              break;
          }
        }
        if (v33 >= 0x27)
          return 0;
      }
      gFldInfIdx = v33;
      goto LABEL_74;
    }
  }
  v7 = 4;
  while (1)
  {
    v9 = gFldInf->pack;
    v10 = v7 - 4;
    EveHit = v9->m_Items[v3]->EveHit;
    v15 = *(*(&EveHit->obj.klass + v7) + 16LL);
    if (fldGb->areaID + 1 == v15)
    {
      v17 = *evename;
      v18 = gFldInf->pack;
      v20 = v18->m_Items[v3]->EveHit;
      if (!Compare(v17, *(*(&v20->obj.klass + v7) + 24LL), 0))
      {
        v24 = gFldInf->pack;
        if (gFldInfIdx != -1)
        {
          Idx = v24->m_Items[v3]->Idx;
          v28 = gFldInf->set;
          if (v28->m_Items[gFldInfIdx]->st->Type == 1)
            break;
        }
      }
    }
    ++v7;
    if (v10 >= 4)
      goto LABEL_44;
  }
  gFldInfIdx = Idx;
LABEL_74:
  return scriptlabel->m_Items[4];
}

// 0x10b84d0
char *fldInf_FindTypeEveNpc(char **evename) {
  u64 v3;
  struct FLD_INF_PACK_t_array *pack;
  s64 v7;
  struct FLD_INF_PACK_t_array *v9;
  u64 v10;
  struct FLD_INF_PACK2_t_array *EveHit;
  s32 v15;
  System_String_o *v17;
  struct FLD_INF_PACK_t_array *v18;
  struct FLD_INF_PACK2_t_array *v20;
  s64 i;
  u64 v25;
  struct FLD_INF_SET_t_array *set;
  struct FLD_INF_SET_t_array *v29;
  struct FLD_INF_SET_t_array *v32;
  s32 v35;
  System_String_o *v37;
  struct FLD_INF_SET_t_array *v38;
  struct fldInf_StaticFields **p_static_fields;
  struct fldInf_StaticFields *v43;
  struct fldInf_StaticFields *static_fields;
  struct FLD_INF_PACK_t_array *v45;
  struct System_String_array *scriptlabel;

  if (!*evename)
    return 0;
  v3 = 0;
  while (1)
  {
    pack = gFldInf->pack;
    if (pack->m_Items[v3]->Idx)
      break;
LABEL_32:
    if (v3++ >= 7)
    {
      for (i = 4; ; ++i)
      {
        v25 = i - 4;
        set = gFldInf->set;
        if (!*(*(*(&set->obj.klass + i) + 16LL) + 16LL))
          goto LABEL_79;
        v29 = gFldInf->set;
        if (*(*(*(&v29->obj.klass + i) + 16LL) + 16LL) == 1)
        {
LABEL_79:
          v32 = gFldInf->set;
          v35 = *(*(*(&v32->obj.klass + i) + 16LL) + 18LL);
          if (fldGb->areaID + 1 == v35)
          {
            v37 = *evename;
            v38 = gFldInf->set;
            if (!Compare(v37, *(*(*(&v38->obj.klass + i) + 16LL) + 24LL), 0))
              break;
          }
        }
        if (v25 >= 0x27)
          return 0;
      }
      gFldInfIdx = v25;
      if (LODWORD(scriptlabel->max_length) > 4)
        return scriptlabel->m_Items[4];
LABEL_70:
    }
  }
  v7 = 4;
  while (1)
  {
    v9 = gFldInf->pack;
    v10 = v7 - 4;
    EveHit = v9->m_Items[v3]->EveHit;
    v15 = *(*(&EveHit->obj.klass + v7) + 16LL);
    if (fldGb->areaID + 1 == v15)
    {
      v17 = *evename;
      v18 = gFldInf->pack;
      v20 = v18->m_Items[v3]->EveHit;
      if (!Compare(v17, *(*(&v20->obj.klass + v7) + 24LL), 0))
        break;
    }
    ++v7;
    if (v10 >= 4)
      goto LABEL_32;
  }
  v43 = static_fields;
  v45 = gFldInf->pack;
  v43->gFldInfIdx = v45->m_Items[v3]->Idx;
  scriptlabel = (*p_static_fields)->scriptlabel;
  if (LODWORD(scriptlabel->max_length) <= 4)
    goto LABEL_70;
  return scriptlabel->m_Items[4];
}

// 0x10b7fe0
char *fldInf_FindTypeNpc(char **evename) {
  u64 v3;
  struct FLD_INF_PACK_t_array *pack;
  s64 v7;
  fldInf_c *v8;
  struct FLD_INF_PACK_t_array *v10;
  u64 v11;
  struct FLD_INF_PACK2_t_array *EveHit;
  s32 v16;
  System_String_o *v18;
  struct FLD_INF_PACK_t_array *v19;
  struct FLD_INF_PACK2_t_array *v21;
  struct FLD_INF_PACK_t_array *v24;
  s32 Idx;
  s32 *v27;
  s64 v28;
  s64 v29;
  s64 i;
  u64 v34;
  struct FLD_INF_SET_t_array *set;
  struct FLD_INF_SET_t_array *v38;
  s32 v41;
  System_String_o *v43;
  struct FLD_INF_SET_t_array *v44;
  struct System_String_array *scriptlabel;

  if (!*evename)
    return 0;
  v3 = 0;
  do
  {
    pack = gFldInf->pack;
    if (pack->m_Items[v3]->Idx)
    {
      v7 = 4;
      do
      {
        v10 = gFldInf->pack;
        v11 = v7 - 4;
        EveHit = v10->m_Items[v3]->EveHit;
        v16 = *(*(&EveHit->obj.klass + v7) + 16LL);
        if (fldGb->areaID + 1 != v16)
          goto LABEL_48;
        v18 = *evename;
        v19 = gFldInf->pack;
        v21 = v19->m_Items[v3]->EveHit;
        if (Compare(v18, *(*(&v21->obj.klass + v7) + 24LL), 0))
          goto LABEL_48;
        v24 = gFldInf->pack;
        Idx = v24->m_Items[v3]->Idx;
        if (gFldInfIdx == -1)
        {
          else
          {
            gFldInfIdx = Idx;
            if ((v8->_2.bitflags2 & 2) == 0)
              goto LABEL_45;
          }
        }
        else if ((v8->_2.bitflags2 & 2) == 0)
        {
          goto LABEL_45;
        }
LABEL_45:
        v28 = *(*v27 + 40LL);
        v29 = v27[2];
        if (!*(*(*(v28 + 8 * v29 + 32) + 16LL) + 16LL))
        {
          gFldInfIdx = Idx;
          goto LABEL_79;
        }
LABEL_48:
        ++v7;
      }
      while (v11 < 4);
    }
  }
  while (v3++ < 7);
  for (i = 4; ; ++i)
  {
    v34 = i - 4;
    set = gFldInf->set;
    if (!*(*(*(&set->obj.klass + i) + 16LL) + 16LL))
    {
      v38 = gFldInf->set;
      v41 = *(*(*(&v38->obj.klass + i) + 16LL) + 18LL);
      if (fldGb->areaID + 1 == v41)
      {
        v43 = *evename;
        v44 = gFldInf->set;
        if (!Compare(v43, *(*(*(&v44->obj.klass + i) + 16LL) + 24LL), 0))
          break;
      }
    }
    if (v34 >= 0x27)
      return 0;
  }
  gFldInfIdx = v34;
LABEL_79:
  return scriptlabel->m_Items[4];
}
