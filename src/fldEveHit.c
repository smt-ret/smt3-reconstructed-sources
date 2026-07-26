#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct fldProgramEveHit_tag fldProgramEveHit_tag;
typedef struct fldResHead_t fldResHead_t;
typedef struct fldResPutEveBall_t fldResPutEveBall_t;
typedef struct fldResPutEveBox_t fldResPutEveBox_t;
typedef struct fldResPutEvePoly_t fldResPutEvePoly_t;
typedef struct fldResPut_t fldResPut_t;
typedef struct fldResourcePoint_t fldResourcePoint_t;
typedef struct putevebox_s putevebox_s;
typedef struct scrProcessWork_s scrProcessWork_s;
typedef struct typeFLD_EVEHIT_TBL typeFLD_EVEHIT_TBL;

static typeFLD_EVEHIT_TBL *gFldEveHitOnOffTbl[32];
static s32 OldHitDoor;
static s32 OldHitInf;
static fldResHead_t *gEvnRng[64];
static s32 gEvnRngNum;
static s32 gFldEveRngIdx;
static s32 gFldEveRngIdx_N;
static s32 gFldEveRngIdx_T;
static dds3ProcessID_t *gEvnRngPid[64];
static fldResHead_t *gEve[72];
static s32 gEveNum;
static s32 gEveOff;
static putevebox_s *gEvnRngBox[64];
static fldProgramEveHit_tag *gProgramEveHit[64];
static s32 gProgramEveHitNum;
static s32 gFldKyouseiTalk;

void CalcABCD(sdfVector4_t **v, f32 *a, f32 *b, f32 *c, f32 *d);
void LoadIdentity(void);
f32 MATH_DotProduct(sdfVector4_t v1, sdfVector4_t v2);
f32 OOYDEG(f32 a);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__GETLENGTH(void);
f32 SDF_VU0__INNERPRODUCT(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STORE_ROW2(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
u32 SetfldEveType(u8 **pData, s32 addr, fldResPut_t *pPut);
fldResPut_t *SetfldResPut(u8 **pData, s32 addr, fldResPut_t *pPut);
fldResPutEveBall_t *SetfldResPutEveBall(u8 **pData, s32 addr, fldResPut_t *pPut);
fldResPutEveBox_t *SetfldResPutEveBox(u8 **pData, s32 addr);
fldResPutEvePoly_t *SetfldResPutEvePoly(u8 **pData, s32 addr);
void ToMatrix(void);
u32 datAddHp(datUnitWork_t *work, s32 hp);
u32 datAddMp(datUnitWork_t *work, s32 mp);
s32 datCheckDying(datUnitWork_t *work);
dds3Basic_t *dds3AddEventBasic(u32 serialID, void *pData, char *pName);
dds3Basic_t *dds3AddPointBasic(u32 serialID, fldResourcePoint_t *pData, char *pName);
void *dds3EventBasicGetResource(dds3Basic_t *pBasic);
s32 dds3ExistProcess(dds3ProcessID_t **id);
dds3Basic_t *dds3GetActiveScene(void);
dds3Basic_t *dds3GetControlScene(void);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
s32 dds3RadiusCheckPoseSet(dds3PoseSet_t **p1, dds3PoseSet_t **p2);
void dds3SceneBasicEndScript(dds3Basic_t **scene, char *procname);
dds3ProcessID_t *dds3SceneBasicStartScript(dds3Basic_t **scene, char *procname);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
u32 dds3SerializeID(void);
void deleteFldMenuSub(s32 second);
bool evtBitCheck(s32 no);
void fldDbgPrintStr2DC(s32 x, s32 y, s32 col, char *str, s32 second);
char *fldDoor_Find(char **evename);
char *fldDoor_Find2(char **evename);
char *fldDoor_Find3(void);
void fldDoor_Init(void);
s32 fldEveHitPositionInside(sdfVector4_t pos, s32 idx);
void fldEveHitProcess_Task(void);
s32 fldEveHit_AddEveData(fldResHead_t *pEve, dds3Basic_t *pBasic);
s32 fldEveHit_AddEveHit(fldResHead_t *pEvnRng, dds3Basic_t *pBasic);
s32 fldEveHit_ChkBoxIn(sdfVector4_t pos, s32 idx);
s32 fldEveHit_ChkOn(char *evehitname);
s32 fldEveHit_ScriptEnd(char **pScriptName, s32 idx);
s32 fldEveHit_ScriptEnd2(s32 idx);
dds3ProcessID_t *fldEveHit_ScriptStart(char **pScriptName, s32 idx);
s32 fldGbChkNpc(s32 fld, s32 area, s32 hojiID);
char *fldInf_FindTypeEve(char **evename);
char *fldInf_FindTypeEveNpc(char **evename);
char *fldInf_FindTypeNpc(char **evename);
s8 fldProcCheckFlag(u32 flag);
void mdlSingleMotionForUnity(void *obj, char *name, s32 value, bool reset, s32 index);
void ooyTestLine3DForUnity(void **parent, char *pName, char *cName, u32 col, s32 size, sdfVector3_t **pos);
s32 p2sdPlaySE(s32 a);
scrProcessWork_s *scrSearchScriptName(char *scriptname);
f32 sdfFabs(f32 c);

// 0x1047530
s32 fldEveHitPositionInside(sdfVector4_t pos, s32 idx) {
    MATH_DotProduct((sdfVector4_t){0}, (sdfVector4_t){0});
    return 0;
}

// 0x104de00
s32 fldEveHitProcess_Chk(void) {
    return 0;
}

// 0x103b7f0
void fldEveHitProcess_Task(void) {
    dds3ExistProcess(0);
}

// 0x102df40
s32 fldEveHitResID_Find(dds3ProcessID_t *pid) {
    return 0;
}

// 0x10360e0
char *fldEveHitResName_Find(dds3ProcessID_t *pid) {
    return 0;
}

// 0x1035ba0
s32 fldEveHitTakaraIdx_Find(dds3ProcessID_t *pid) {
    return 0;
}

// 0x103c610
s32 fldEveHit_AddEveData(fldResHead_t *pEve, dds3Basic_t *pBasic) {
  struct fldEveHit_StaticFields *v4;
  struct fldResHead_t_array *gEve;
  s64 gEveNum;
  struct fldEveHit_StaticFields *static_fields;

  else
  {
    v4 = fldEveHit->static_fields;
    gEve = v4->gEve;
    gEveNum = v4->gEveNum;
    if (!pEve)
  }
  gEve->m_Items[gEveNum] = pEve;
  ++gEveNum;
  return gEveNum - 1;
}

// 0x103c720
s32 fldEveHit_AddEveHit(fldResHead_t *pEvnRng, dds3Basic_t *pBasic) {
    SetfldResPut(0, 0, 0);
    SetfldEveType(0, 0, 0);
    SetfldResPutEveBox(0, 0);
    LoadIdentity();
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(0);
    CalcABCD(0, 0, 0, 0, 0);
    MATH_DotProduct((sdfVector4_t){0}, (sdfVector4_t){0});
    SetfldResPutEvePoly(0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    sdfFabs(0);
    return 0;
}

// 0x104c6d0
void fldEveHit_AddEveHitItemBox(s32 idx, f32 x, f32 y, f32 z, f32 r) {
    dds3SerializeID();
    dds3AddEventBasic(0, 0, 0);
    fldEveHit_AddEveData(0, 0);
    dds3AddPointBasic(0, 0, 0);
    fldEveHit_AddEveHit(0, 0);
}

// 0x104d150
void fldEveHit_AddEveHitNpc(char **resname, s32 eveidx, f32 x, f32 y, f32 z, f32 r, s32 hojiID, s32 npcidx) {
    dds3SerializeID();
    dds3AddPointBasic(0, 0, 0);
    fldEveHit_AddEveHit(0, 0);
}

// 0x10478e0
s32 fldEveHit_ChkBoxIn(sdfVector4_t pos, s32 idx) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  s64 v8;
  u64 v9;
  struct putevebox_s_array *gEvnRngBox;
  struct UnityEngine_Vector4_array *facenml;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  struct putevebox_s_array *v20;
  struct System_Single_array *facenum;
  bool v24;
  UnityEngine_Vector4_o v26;
  UnityEngine_Vector4_o v27;

  w = pos.w;
  z = pos.z;
  y = pos.y;
  x = pos.x;
  v8 = 0;
  v9 = 0;
  while (1)
  {
    facenml = gEvnRngBox->m_Items[idx]->facenml;
    v15 = facenml->m_Items[v8].x;
    v16 = facenml->m_Items[v8].y;
    v17 = facenml->m_Items[v8].z;
    v18 = facenml->m_Items[v8].w;
    v26.x = x;
    v26.y = y;
    v26.z = z;
    v26.w = w;
    v27.x = v15;
    v27.y = v16;
    v27.z = v17;
    v27.w = v18;
    v19 = MATH_DotProduct(v26, v27);
    v20 = gEvnRngBox;
    facenum = v20->m_Items[idx]->facenum;
    if ((v19 - facenum->m_Items[v9]) > 0.0)
      break;
    v24 = v9++ >= 5;
    ++v8;
    if (v24)
      return 1;
  }
  return 0;
}

// 0x102e0f0
s32 fldEveHit_ChkDir(dds3Basic_t *unit, dds3Basic_t *put) {
    SetfldResPut(0, 0, 0);
    SetfldEveType(0, 0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__STORE_ROW2(0);
    SDF_VU0__NORMALIZE();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__GETLENGTH();
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__INNERPRODUCT();
    OOYDEG(0);
    MATH_DotProduct((sdfVector4_t){0}, (sdfVector4_t){0});
    return 0;
}

// 0x102ea50
s32 fldEveHit_ChkDir2(dds3Basic_t *unit, dds3Basic_t *put) {
    SetfldResPut(0, 0, 0);
    SetfldEveType(0, 0, 0);
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    ToMatrix();
    SDF_VU0__STORE_ROW2(0);
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(0);
    MATH_DotProduct((sdfVector4_t){0}, (sdfVector4_t){0});
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__COPYVECTOR_A_TO_C();
    SDF_VU0__LOADVECTOR_B((sdfVector4_t){0});
    SDF_VU0__SUBVECTOR();
    SDF_VU0__GETLENGTH();
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__INNERPRODUCT();
    OOYDEG(0);
    return 0;
}

// 0x10484a0
void fldEveHit_ChkEveHit(dds3Basic_t *pObjectBasic) {
    fldProcCheckFlag(0);
    fldEveHitProcess_Task();
    dds3GetControlScene();
    fldInf_FindTypeEveNpc(0);
    fldEveHit_ScriptStart(0, 0);
    fldDoor_Find(0);
    fldEveHit_ScriptEnd(0, 0);
    deleteFldMenuSub(0);
    fldDoor_Find2(0);
    fldGbChkNpc(0, 0, 0);
    fldEveHit_ChkOn(0);
    SetfldResPut(0, 0, 0);
    SetfldEveType(0, 0, 0);
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
    fldEveHit_ChkBoxIn((sdfVector4_t){0}, 0);
    fldInf_FindTypeEve(0);
    dds3SearchSceneBasic(0, 0, 0);
    dds3EventBasicGetResource(0);
    ooyTestLine3DForUnity(0, 0, 0, 0, 0, 0);
    MATH_DotProduct((sdfVector4_t){0}, (sdfVector4_t){0});
    fldEveHitPositionInside((sdfVector4_t){0}, 0);
    fldDbgPrintStr2DC(0, 0, 0, 0, 0);
    scrSearchScriptName(0);
    dds3GetActiveScene();
    dds3SceneBasicStartScript(0, 0);
    SetfldResPutEveBall(0, 0, 0);
    dds3RadiusCheckPoseSet(0, 0);
    fldEveHit_ScriptEnd2(0);
    fldInf_FindTypeNpc(0);
}

// 0x1047fe0
s32 fldEveHit_ChkEveHitAfter(void) {
    dds3GetActiveScene();
    dds3SceneBasicEndScript(0, 0);
    fldDoor_Find3();
    scrSearchScriptName(0);
    dds3SceneBasicStartScript(0, 0);
    return 0;
}

// 0x104db40
s32 fldEveHit_ChkNpcScr(s32 npcidx) {
  struct fldEveHit_StaticFields *static_fields;
  s64 gFldEveRngIdx_N;
  struct putevebox_s_array *gEvnRngBox;
  struct putevebox_s_array *v10;

  else
  {
    static_fields = fldEveHit->static_fields;
    if (static_fields->gFldKyouseiTalk)
      return 1;
  }
  gFldEveRngIdx_N = static_fields->gFldEveRngIdx_N;
  if (gFldEveRngIdx_N == -1)
    return 0;
  gEvnRngBox = static_fields->gEvnRngBox;
  if (gEvnRngBox->m_Items[gFldEveRngIdx_N]->npcHit != 1)
    return 0;
  v10 = gEvnRngBox;
  return v10->m_Items[gFldEveRngIdx_N]->npcIdx == npcidx;
}

// 0x1048280
s32 fldEveHit_ChkOn(char *evehitname) {
  s64 i;
  u64 v5;
  struct typeFLD_EVEHIT_TBL_array *gFldEveHitOnOffTbl;
  s32 v9;
  struct typeFLD_EVEHIT_TBL_array *v11;
  s32 v14;
  struct typeFLD_EVEHIT_TBL_array *v16;
  struct typeFLD_EVEHIT_TBL_array *v20;

  for (i = 4; ; ++i)
  {
    v5 = i - 4;
    v9 = *(*(&gFldEveHitOnOffTbl->obj.klass + i) + 16LL);
    if (fldGb->fieldID == v9)
    {
      v11 = gFldEveHitOnOffTbl;
      v14 = *(*(&v11->obj.klass + i) + 18LL);
      if (fldGb->areaID + 1 == v14)
      {
        v16 = gFldEveHitOnOffTbl;
        if (!Compare(*(*(&v16->obj.klass + i) + 24LL), evehitname, 0))
          break;
      }
    }
    if (v5 >= 0x1F)
      return 1;
  }
  v20 = gFldEveHitOnOffTbl;
  return evtBitCheck(*(*(&v20->obj.klass + i) + 20LL), 0);
}

// 0x104dca0
s32 fldEveHit_ChkTakaraScr(s32 takaraidx) {
    return 0;
}

// 0x104c5c0
void fldEveHit_DrawEveHit(void) {
}

// 0x103c450
void fldEveHit_End(void) {
    dds3GetControlScene();
}

// 0x103b980
void fldEveHit_Init(void) {
    fldDoor_Init();
}

// 0x1047d30
s32 fldEveHit_ScriptEnd(char **pScriptName, s32 idx) {
  struct dds3ProcessID_t_array *gEvnRngPid;
  System_String_o *v8;
  System_String_o *v11;
  dds3Basic_t_o *scene;

  scene = 0;
  gEvnRngPid->m_Items[idx] = 0;
  v8 = *pScriptName;
  if (!scrSearchScriptName(v8))
    return -1;
  scene = dds3GetActiveScene();
  v11 = *pScriptName;
  dds3SceneBasicEndScript(&scene, v11);
  return 0;
}

// 0x1047e90
s32 fldEveHit_ScriptEnd2(s32 idx) {
  struct dds3ProcessID_t_array *gEvnRngPid;
  struct dds3ProcessID_t_array *v8;
  dds3ProcessID_t_o *id;

  id = 0;
  id = gEvnRngPid->m_Items[idx];
  if (dds3ExistProcess(&id))
  {
    dds3KillProcess(&id, 0);
  }
  v8 = gEvnRngPid;
  v8->m_Items[idx] = 0;
  return 0;
}

// 0x1047ac0
dds3ProcessID_t *fldEveHit_ScriptStart(char **pScriptName, s32 idx) {
  System_String_o *v5;
  scrProcessWork_s_o *v6;
  s64 *started;
  System_String_o *v10;
  struct dds3ProcessID_t_array *gEvnRngPid;
  struct putevebox_s_array *gEvnRngBox;
  struct putevebox_s_array *v20;
  dds3Basic_t_o *scene;

  scene = 0;
  v5 = *pScriptName;
  v6 = scrSearchScriptName(v5);
  started = 0;
  if (!v6)
  {
    scene = dds3GetActiveScene();
    v10 = *pScriptName;
    started = dds3SceneBasicStartScript(&scene, v10);
    gEvnRngPid->m_Items[idx] = started;
    gFldEveRngIdx = idx;
    gFldEveRngIdx_N = -1;
    gFldEveRngIdx_T = -1;
    if (gEvnRngBox->m_Items[idx]->npcHit == 1)
    {
      gFldEveRngIdx_N = idx;
    }
    v20 = gEvnRngBox;
    if (v20->m_Items[idx]->npcHit == 2)
    {
      gFldEveRngIdx_T = idx;
    }
  }
  return started;
}

// 0x103b0e0
void fldKaifukuTest(void) {
  s64 i;
  u64 v4;
  struct datUnitWork_t_array *unitwork;
  datUnitWork_t_o *v7;
  struct datUnitWork_t_array *v8;
  struct datUnitWork_t_array *v10;
  s64 v12;

  for (i = 4; i != 20; ++i)
  {
    v4 = i - 4;
    unitwork = DDS3_GBWK->unitwork;
    v7 = *(&unitwork->obj.klass + i);
    datAddHp(v7, 9999);
    v8 = DDS3_GBWK->unitwork;
    datAddMp(*(&v8->obj.klass + i), 9999, 0);
    v10 = DDS3_GBWK->unitwork;
    v12 = *(&v10->obj.klass + i);
    *(v12 + 30) = 0;
  }
  p2sdPlaySE(16);
}

// 0x103b260
void fldStatusSet(void) {
  u64 v4;
  s32 v5;
  struct datUnitWork_t_array *unitwork;
  struct datUnitWork_t_array *v9;
  struct datUnitWork_t_array *v12;
  struct datUnitWork_t_array *v16;
  struct datUnitWork_t_array *v20;
  struct datUnitWork_t_array *v24;
  u32 v27;
  struct datUnitWork_t_array *v28;
  datUnitWork_t_o *v30;
  u32 PlayerStatus;
  s32 v35;
  UnityEngine_GameObject_o *fldPlayerObj;
  UnityEngine_GameObject_o *fldPlayerObjM;
  System_String_o *v38;
  s32 v39;
  UnityEngine_GameObject_o *v41;

  fldDbg->PlayerStatus = 0;
  v4 = 0;
  do
  {
    unitwork = DDS3_GBWK->unitwork;
    if ((unitwork->m_Items[v4]->flag & 2) != 0)
    {
      v9 = DDS3_GBWK->unitwork;
      if (v9->m_Items[v4]->hp)
      {
        v12 = DDS3_GBWK->unitwork;
        if ((v12->m_Items[v4]->badstatus & 0x40) != 0)
        {
          fldDbg->PlayerStatus |= 1u;
          {
            v16 = DDS3_GBWK->unitwork;
            if ((v16->m_Items[v4]->badstatus & 0x100) != 0)
            {
              fldDbg->PlayerStatus |= 4u;
              {
                v20 = DDS3_GBWK->unitwork;
                if ((v20->m_Items[v4]->badstatus & 0x20) != 0)
                {
                  fldDbg->PlayerStatus |= 8u;
                }
                else
                {
                  {
                    v24 = DDS3_GBWK->unitwork;
                    if (v24->m_Items[v4]->badstatus < 0)
                    {
                      fldDbg->PlayerStatus |= 0x10u;
                    }
                  }
                }
              }
            }
            else
            {
            }
          }
        }
        else
        {
        }
      }
    }
    ++v4;
    v5 = (v27 >> 9) & 1;
  }
  while (v4 != 16);
  v28 = DDS3_GBWK->unitwork;
  v30 = v28->m_Items[0];
  else if (datCheckDying(v30))
  {
    fldDbg->PlayerStatus |= 2u;
    PlayerStatus = fldDbg->PlayerStatus;
    v35 = (PlayerStatus >> 1) & 1;
    mdlSingleMotionForUnity(fldPlayerObj, StringLiteral_16609, v35, 1, 0);
    v38 = StringLiteral_16609;
    v39 = v35;
  }
  v41 = fldPlayerObj;
  mdlSingleMotionForUnity(v41, StringLiteral_16609, 0, 1, 0);
  v38 = StringLiteral_16609;
  v39 = 0;
  mdlSingleMotionForUnity(fldPlayerObjM, v38, v39, 1, 0);
}
