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
  fldInf_c *v3;
  s64 v4;
  s32 *static_fields;
  s64 v6;
  s64 v7;
  s64 v9;
  s64 v11;
  fldInf_c *v13;
  s64 v14;
  s32 *v15;
  s64 v16;
  s64 v17;
  s64 v19;
  fldInf_c *v21;
  fldInf_c *v22;
  s32 *v23;
  s64 v24;
  s64 v25;
  s64 v27;
  fldInf_c *v29;
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
  fldInf_c *v55;
  s32 *v56;
  s64 v57;
  s64 v58;
  s64 v60;
  fldInf_c *v62;
  s32 *v63;
  s64 v64;
  s64 v65;
  u64 v67;
  s32 result;
  fldEveHit_c *v69;
  struct fldEveHit_StaticFields *v70;
  struct fldResHead_t_array *gEvnRng;
  s64 gFldInf_HitIdx;
  struct fldInf_StaticFields *v76;
  struct FLD_INF_SET_t_array *set;
  s64 gFldInfIdx;
  fldEveHit_c *v80;
  struct fldEveHit_StaticFields *v81;
  struct fldResHead_t_array *v83;
  s64 v84;
  System_String_o **p_resourceName;

  LODWORD(v2) = aline;
  while (1)
  {
    if (v2 > 9)
    {
      v4 = v2 - 10LL;
      static_fields = v3->static_fields;
      v6 = *(*static_fields + 40LL);
      v7 = static_fields[2];
      v9 = *(*(v6 + 8 * v7 + 32) + 32LL);
      if (v4 >= *(v9 + 24))
      v11 = *(*(v9 + 8 * v4 + 32) + 24LL);
      v2 = *(v11 + 32);
      if ((v2 - 101) < 5)
        return v2;
    }
    v4 = v2 - 1LL;
    v23 = v22->static_fields;
    v24 = *(*v23 + 40LL);
    v25 = v23[2];
    v27 = *(*(v24 + 8 * v25 + 32) + 24LL);
    if (!*(*(v27 + 8 * v4 + 32) + 16LL))
    {
      v45 = v29->static_fields;
      v46 = *(*v45 + 40LL);
      v47 = v45[2];
      v9 = *(*(v46 + 8 * v47 + 32) + 24LL);
    }
    v30 = v29->static_fields;
    v31 = *(*v30 + 40LL);
    v32 = v30[2];
    v34 = *(*(v31 + 8 * v32 + 32) + 24LL);
    v36 = evtBitCheck(*(*(v34 + 8 * v4 + 32) + 16LL), 0);
    v37 = v29->static_fields;
    v38 = *(*v37 + 40LL);
    v39 = v37[2];
    v41 = *(*(v38 + 8 * v39 + 32) + 24LL);
    v43 = *(*(v41 + 8 * v4 + 32) + 24LL);
    v2 = *(v43 + 33);
    if ((v2 - 101) < 5)
      return v2;
    if (!v2)
      return v2;
    if (v2 == 100)
      break;

    {
      v14 = v2 - 10;
      v15 = v13->static_fields;
      v16 = *(*v15 + 40LL);
      v17 = v15[2];
      v19 = *(*(v16 + 8 * v17 + 32) + 32LL);
      if (*(*(v19 + 8 * v14 + 32) + 16LL) != -1)
      {
        v49 = v21->static_fields;
        v50 = *(*v49 + 40LL);
        v51 = v49[2];
        v53 = *(*(v50 + 8 * v51 + 32) + 32LL);
        if (!*(*(v53 + 8 * v14 + 32) + 16LL))
        v56 = v55->static_fields;
        v57 = *(*v56 + 40LL);
        v58 = v56[2];
        v60 = *(*(v57 + 8 * v58 + 32) + 32LL);
        if (*(*(v60 + 8 * v14 + 32) + 16LL) == 1)
        {
          v63 = v62->static_fields;
          v64 = *(*v63 + 40LL);
          v65 = v63[2];
          v67 = *(*(*(v64 + 8 * v65 + 32) + 16LL) + 20LL);
          if (v67 < 4)
            return dword_32C3B50[v67];
        }
        LODWORD(v2) = 0;
        return v2;
      }
    }
  }
  v70 = v69->static_fields;
  gEvnRng = v70->gEvnRng;
  fldInf_FindTypeEveNpc(&gEvnRng->m_Items[gFldInf_HitIdx]->resourceName);
  v76 = fldInf->static_fields;
  set = v76->gFldInf->set;
  gFldInfIdx = v76->gFldInfIdx;
  if (!set->m_Items[gFldInfIdx]->st->Action)
  {
    LODWORD(v2) = 199;
    return v2;
  }
  v81 = v80->static_fields;
  v83 = v81->gEvnRng;
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
  fldInf_c *v6;
  s32 *v7;
  s64 v8;
  s64 v9;
  s64 v11;
  fldInf_c *v14;
  s32 *static_fields;
  s64 v16;
  s64 v17;
  s64 v19;

  v5 = aline - 10LL;
  if (acol == 1)
  {
    static_fields = v14->static_fields;
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
    v7 = v6->static_fields;
    v8 = *(*v7 + 40LL);
    v9 = v7[2];
    v11 = *(*(v8 + 8 * v9 + 32) + 32LL);
    return *(*(v11 + 8 * v5 + 32) + 16LL);
  }
}

// 0x10ba950
void fldInfLoad(s32 field) {
    IsDLCField(0);
    fldMakeFilePath(0, 0, 0);
    LoadFileByte(0, 0, 0);
    SetCopy(0, 0, 0);
}

// 0x10bab70
void fldInfLoadFromMem(void *data) {
  ;
}

// 0x10b90d0
s32 fldInfNext(s32 aline, s32 asel) {
    evtBitCheck(0);
    evtBitOff(0);
    evtBitOn(0);
    dds3GetActiveScene();
    scrAllReleaseScript();
    fldProcNext(0, 0);
    CallBattleSub2(0);
    fldCamNowEveCamera(0);
    resetCamTgtPlayer();
    resetCamNormal();
    datAddItem(0, 0);
    datAddMaka(0);
    fldKaifukuTest();
    fldPlayerOn();
    fldPlayerOff();
    dds3SceneBasicSearchName(0, 0);
    evtSetUnitPos(0, 0);
    dds3SetActiveCameraSceneBasic(0, 0);
    dds3SearchSceneBasic(0, 0, 0);
    return 0;
}

// 0x10bab80
void fldInfToWAP(void) {
  fldInf_c *v2;
  struct fldInf_StaticFields *static_fields;
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
  static_fields = v2->static_fields;
  gFldInf_HitIdx = static_fields->gFldInf_HitIdx;
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
  fldInf_c *v22;
  struct fldInf_StaticFields *static_fields;
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
        static_fields = v22->static_fields;
        v24 = static_fields->gFldInf->pack;
        gFldInfIdx = static_fields->gFldInfIdx;
        if (gFldInfIdx != -1)
        {
          Idx = v24->m_Items[v3]->Idx;
          v28 = static_fields->gFldInf->set;
          if (v28->m_Items[gFldInfIdx]->st->Type == 1)
            break;
        }
      }
    }
    ++v7;
    if (v10 >= 4)
  }
  gFldInfIdx = Idx;
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
  fldInf_c *v41;
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
    if (v3++ >= 7)
    {
      for (i = 4; ; ++i)
      {
        v25 = i - 4;
        set = gFldInf->set;
        if (!*(*(*(&set->obj.klass + i) + 16LL) + 16LL))
        v29 = gFldInf->set;
        if (*(*(*(&v29->obj.klass + i) + 16LL) + 16LL) == 1)
        {
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
  }
  static_fields = v41->static_fields;
  p_static_fields = &v41->static_fields;
  v43 = static_fields;
  v45 = static_fields->gFldInf->pack;
  v43->gFldInfIdx = v45->m_Items[v3]->Idx;
  scriptlabel = (*p_static_fields)->scriptlabel;
  if (LODWORD(scriptlabel->max_length) <= 4)
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
  struct fldInf_StaticFields *static_fields;
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
        v18 = *evename;
        v19 = gFldInf->pack;
        v21 = v19->m_Items[v3]->EveHit;
        if (Compare(v18, *(*(&v21->obj.klass + v7) + 24LL), 0))
        static_fields = v8->static_fields;
        v24 = static_fields->gFldInf->pack;
        Idx = v24->m_Items[v3]->Idx;
        if (static_fields->gFldInfIdx == -1)
        {
          else
          {
            static_fields->gFldInfIdx = Idx;
            if ((v8->_2.bitflags2 & 2) == 0)
          }
        }
        else        v27 = v8->static_fields;
        v28 = *(*v27 + 40LL);
        v29 = v27[2];
        if (!*(*(*(v28 + 8 * v29 + 32) + 16LL) + 16LL))
        {
          gFldInfIdx = Idx;
        }
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
  return scriptlabel->m_Items[4];
}
