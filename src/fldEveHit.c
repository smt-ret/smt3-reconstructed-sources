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
  u32 *v5;
  struct putevebox_s_array *gEvnRngBox;
  s32 v9;
  u32 v11;
  s32 v12;
  s32 v15;
  s64 v17;
  u64 v18;
  s32 v19;
  s64 v21;
  s64 v22;
  struct putevebox_s_array *v23;
  struct UnityEngine_Vector4_array *facenml;
  f32 x;
  f32 y;
  f32 z;
  f32 w;
  f32 v31;
  struct putevebox_s_array *v32;
  struct System_Single_array *facenum;
  f32 *v36;
  s64 v38;
  s64 v39;
  UnityEngine_Vector4_o v40;
  UnityEngine_Vector4_o v41;
  UnityEngine_Vector4_o v42;

  v40 = pos;
  v38 = 0;
  v39 = 0;
  v5 = NewSpecific(f32, 2u);
  if (gEvnRngBox->m_Items[idx]->mode2D)
  {
    sub_854710(&v40, 0);
    sub_854930(&v38, 0);
    sub_854710(&v40, 1u);
    sub_854930(&v38, 1u);
    sub_854930(&v38, 2u);
    sub_854710(&v40, 0);
    v11 = 1;
    v5[8] = v9;
  }
  else
  {
    sub_854930(&v38, 0);
    sub_854710(&v40, 1u);
    sub_854930(&v38, 1u);
    sub_854710(&v40, 2u);
    sub_854930(&v38, 2u);
    sub_854710(&v40, 1u);
    v5[8] = v12;
    v11 = 2;
  }
  sub_854710(&v40, v11);
  v5[9] = v15;
  v17 = 0;
  v18 = 0;
  v19 = -1;
  while (v18 < 4)
  {
    v21 = v38;
    v22 = v39;
    v23 = gEvnRngBox;
    facenml = v23->m_Items[idx]->facenml;
    x = facenml->m_Items[v17 + 1].x;
    y = facenml->m_Items[v17 + 1].y;
    z = facenml->m_Items[v17 + 1].z;
    w = facenml->m_Items[v17 + 1].w;
    *&v41.x = v21;
    *&v41.z = v22;
    v42.x = x;
    v42.y = y;
    v42.z = z;
    v42.w = w;
    v31 = MATH_DotProduct(v41, v42);
    v32 = gEvnRngBox;
    facenum = v32->m_Items[idx]->facenum;
    v36 = (facenum + 4 * v18++);
    ++v17;
    if ((v31 - v36[9]) < 0.0)
      return v19;
  }
  return 0;
}

// 0x104de00
s32 fldEveHitProcess_Chk(void) {
  u64 v2;
  struct dds3ProcessID_t_array *gEvnRngPid;
  Il2CppClass **v7;

  v2 = 0;
  while (1)
  {
    if (v2 >= gEvnRngNum)
      return 0;
    else
    {
      if (v2 >= LODWORD(gEvnRngPid->max_length))
        goto LABEL_11;
    }
    v7 = &gEvnRngPid->obj.klass + v2++;
    if (v7[4])
      return 1;
  }
}

// 0x103b7f0
void fldEveHitProcess_Task(void) {
  s64 v2;
  u64 v4;
  struct dds3ProcessID_t_array *gEvnRngPid;
  dds3ProcessID_t_o *id;

  id = 0;
  v2 = 4;
  v4 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    if (v4 >= gEvnRngNum)
      break;
    else
    {
      if (v4 >= LODWORD(gEvnRngPid->max_length))
        goto LABEL_12;
    }
    id = *(&gEvnRngPid->obj.klass + v2);
    else if (!dds3ExistProcess(&id))
    {
      goto LABEL_16;
    }
    ++v2;
    v4 = v2 - 4;
      goto LABEL_6;
  }
}

// 0x102df40
s32 fldEveHitResID_Find(dds3ProcessID_t *pid) {
  s64 v3;
  s32 v4;
  u64 v6;
  struct dds3ProcessID_t_array *gEvnRngPid;
  struct dds3ProcessID_t_array *v11;
  struct fldResHead_t_array *gEvnRng;

  v3 = 4;
  v4 = -1;
  v6 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    if (v6 >= gEvnRngNum)
      return v4;
    else
    {
      if (v6 >= LODWORD(gEvnRngPid->max_length))
        goto LABEL_12;
    }
    if (*(&gEvnRngPid->obj.klass + v3))
    {
      v11 = gEvnRngPid;
      if (*(*(&v11->obj.klass + v3) + 24LL) == pid->namehash)
      {
        return *(*(&gEvnRng->obj.klass + v3) + 16LL);
      }
    }
    ++v3;
    v6 = v3 - 4;
      goto LABEL_6;
  }
}

// 0x10360e0
char *fldEveHitResName_Find(dds3ProcessID_t *pid) {
  s64 v3;
  u64 v5;
  struct dds3ProcessID_t_array *gEvnRngPid;
  struct dds3ProcessID_t_array *v10;
  struct fldResHead_t_array *gEvnRng;

  v3 = 4;
  v5 = 0;
  {
LABEL_6:
    goto LABEL_8;
  }
  while (1)
  {
LABEL_8:
    if (v5 >= gEvnRngNum)
      return 0;
    else
    {
      if (v5 >= LODWORD(gEvnRngPid->max_length))
        goto LABEL_12;
    }
    if (*(&gEvnRngPid->obj.klass + v3))
    {
      v10 = gEvnRngPid;
      if (*(*(&v10->obj.klass + v3) + 24LL) == pid->namehash)
        break;
    }
    ++v3;
    v5 = v3 - 4;
      goto LABEL_6;
  }
  return *(*(&gEvnRng->obj.klass + v3) + 24LL);
}

// 0x1035ba0
s32 fldEveHitTakaraIdx_Find(dds3ProcessID_t *pid) {
  s64 v3;
  s32 v4;
  u64 v6;
  struct dds3ProcessID_t_array *gEvnRngPid;
  struct dds3ProcessID_t_array *v11;
  struct putevebox_s_array *gEvnRngBox;

  v3 = 4;
  v4 = -1;
  v6 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    if (v6 >= gEvnRngNum)
      return v4;
    else
    {
      if (v6 >= LODWORD(gEvnRngPid->max_length))
        goto LABEL_12;
    }
    if (*(&gEvnRngPid->obj.klass + v3))
    {
      v11 = gEvnRngPid;
      if (*(*(&v11->obj.klass + v3) + 24LL) == pid->namehash)
      {
        return *(*(&gEvnRngBox->obj.klass + v3) + 82LL);
      }
    }
    ++v3;
    v6 = v3 - 4;
      goto LABEL_6;
  }
}

// 0x103c610
s32 fldEveHit_AddEveData(fldResHead_t *pEve, dds3Basic_t *pBasic) {
  struct fldResHead_t_array *gEve;
  s64 gEveNum;

  else
  {
    if (!pEve)
      goto LABEL_9;
  }
LABEL_9:
  gEve->m_Items[gEveNum] = pEve;
  ++gEveNum;
  return gEveNum - 1;
}

// 0x103c720
s32 fldEveHit_AddEveHit(fldResHead_t *pEvnRng, dds3Basic_t *pBasic) {
  f32 v5;
  u64 *v6;
  f32 *v7;
  u64 *v8;
  s64 gEvnRngNum;
  struct fldResHead_t_array *gEvnRng;
  struct fldResHead_t_array *v15;
  u32 max_length;
  struct fldResHead_t_array *v17;
  System_Byte_array *pDate;
  s32 v21;
  fldResPut_t_o *pPut;
  fldResPut_t_o *v23;
  struct fldResHead_t_array *v24;
  fldResPut_t_o *v25;
  u32 v27;
  f32 v29;
  f32 v30;
  struct fldResHead_t_array *v32;
  s32 v34;
  System_Byte_array *v35;
  fldResPutEvePoly_t_o *v36;
  struct fldResHead_t_array *v37;
  f32 v38;
  f32 v39;
  struct fldResHead_t_array *v41;
  struct fldResHead_t_array *v43;
  struct fldResHead_t_array *v45;
  u64 v53;
  s64 v54;
  struct putevebox_s_array *v56;
  struct UnityEngine_Vector4_array *v58;
  struct putevebox_s_array *v61;
  struct UnityEngine_Vector4_array *v63;
  struct putevebox_s_array *v66;
  struct UnityEngine_Vector4_array *v68;
  struct putevebox_s_array *v71;
  struct UnityEngine_Vector4_array *v73;
  struct putevebox_s_array *v77;
  struct putevebox_s_array *v81;
  struct UnityEngine_Vector4_array *v83;
  u32 *v84;
  struct putevebox_s_array *v87;
  struct UnityEngine_Vector4_array *v89;
  struct putevebox_s_array *v94;
  struct UnityEngine_Vector4_array *v96;
  struct putevebox_s_array *v101;
  struct UnityEngine_Vector4_array *v103;
  u32 v107;
  u32 *v108;
  struct putevebox_s_array *v113;
  struct UnityEngine_Vector4_array *v115;
  struct putevebox_s_array *v118;
  struct UnityEngine_Vector4_array *v120;
  struct putevebox_s_array *v123;
  struct UnityEngine_Vector4_array *v125;
  struct putevebox_s_array *v130;
  struct UnityEngine_Vector4_array *v132;
  struct putevebox_s_array *v135;
  u32 v136;
  struct fldResHead_t_array *v138;
  s32 v140;
  System_Byte_array *v141;
  fldResPutEveBox_t_o *v142;
  f32 x;
  f32 y;
  struct fldResHead_t_array *v145;
  struct fldResHead_t_array *v147;
  struct fldResHead_t_array *v149;
  struct fldResHead_t_array *v151;
  struct fldResHead_t_array *v153;
  struct fldResHead_t_array *v155;
  struct fldResHead_t_array *v157;
  u64 v169;
  s64 v170;
  struct putevebox_s_array *gEvnRngBox;
  struct UnityEngine_Vector4_array *vtx;
  struct putevebox_s_array *v177;
  struct UnityEngine_Vector4_array *v179;
  struct putevebox_s_array *v182;
  struct UnityEngine_Vector4_array *v184;
  struct putevebox_s_array *v187;
  struct UnityEngine_Vector4_array *v189;
  struct putevebox_s_array *v193;
  struct putevebox_s_array *v195;
  struct UnityEngine_Vector4_array *v197;
  u32 *v199;
  struct putevebox_s_array *v201;
  struct UnityEngine_Vector4_array *v203;
  struct putevebox_s_array *v206;
  struct UnityEngine_Vector4_array *v208;
  struct putevebox_s_array *v212;
  struct UnityEngine_Vector4_array *v214;
  struct putevebox_s_array *v217;
  struct UnityEngine_Vector4_array *v219;
  struct putevebox_s_array *v222;
  struct UnityEngine_Vector4_array *v224;
  struct putevebox_s_array *v228;
  struct UnityEngine_Vector4_array *v230;
  struct putevebox_s_array *v233;
  struct UnityEngine_Vector4_array *v235;
  struct putevebox_s_array *v238;
  struct UnityEngine_Vector4_array *v240;
  u32 v245;
  u32 *v246;
  struct putevebox_s_array *v250;
  struct UnityEngine_Vector4_array *facenml;
  struct putevebox_s_array *v255;
  struct UnityEngine_Vector4_array *v257;
  struct putevebox_s_array *v260;
  struct UnityEngine_Vector4_array *v262;
  struct putevebox_s_array *v267;
  struct UnityEngine_Vector4_array *v269;
  struct putevebox_s_array *v272;
  u32 v273;
  struct System_Single_array *v276;
  struct UnityEngine_Vector4_array *v278;
  f32 v280;
  f32 v281;
  f32 v282;
  f32 v283;
  u64 *v285;
  f32 v286;
  f32 v287;
  f32 v288;
  f32 v289;
  f32 v290;
  struct putevebox_s_array *v292;
  struct UnityEngine_Vector4_array *v294;
  f32 v297;
  f32 v298;
  f32 v299;
  struct putevebox_s_array *v300;
  f32 v301;
  struct UnityEngine_Vector4_array *v303;
  f32 v305;
  f32 v306;
  struct putevebox_s_array *v307;
  f32 v308;
  struct UnityEngine_Vector4_array *v310;
  f32 v312;
  f32 v313;
  struct putevebox_s_array *v315;
  s64 v319;
  u32 *v326;
  s64 v333;
  s64 v339;
  u32 v345;
  struct putevebox_s_array *v347;
  struct UnityEngine_Vector4_array *v349;
  struct putevebox_s_array *v352;
  struct UnityEngine_Vector4_array *v354;
  struct putevebox_s_array *v357;
  struct UnityEngine_Vector4_array *v359;
  struct putevebox_s_array *v362;
  u32 v363;
  struct System_Single_array *facenum;
  struct UnityEngine_Vector4_array *v367;
  f32 v368;
  f32 v369;
  f32 z;
  f32 w;
  f32 v372;
  f32 v373;
  f32 v374;
  f32 v375;
  f32 v376;
  struct putevebox_s_array *v378;
  struct UnityEngine_Vector4_array *v380;
  struct putevebox_s_array *v383;
  struct UnityEngine_Vector4_array *v385;
  struct putevebox_s_array *v388;
  struct UnityEngine_Vector4_array *v390;
  struct putevebox_s_array *v394;
  struct UnityEngine_Vector4_array *v396;
  struct putevebox_s_array *v399;
  struct UnityEngine_Vector4_array *v401;
  struct putevebox_s_array *v404;
  struct UnityEngine_Vector4_array *v406;
  struct putevebox_s_array *v410;
  struct UnityEngine_Vector4_array *v412;
  struct putevebox_s_array *v415;
  struct UnityEngine_Vector4_array *v417;
  struct putevebox_s_array *v420;
  struct UnityEngine_Vector4_array *v422;
  u32 v426;
  struct putevebox_s_array *v430;
  struct UnityEngine_Vector4_array *v432;
  struct putevebox_s_array *v436;
  struct UnityEngine_Vector4_array *v438;
  struct putevebox_s_array *v443;
  struct UnityEngine_Vector4_array *v445;
  struct putevebox_s_array *v450;
  struct UnityEngine_Vector4_array *v452;
  struct putevebox_s_array *v455;
  u32 v456;
  struct putevebox_s_array *v458;
  struct System_Single_array *v462;
  struct UnityEngine_Vector4_array *v464;
  f32 v466;
  f32 v467;
  f32 v468;
  f32 v469;
  f32 v471;
  f32 v472;
  f32 v473;
  f32 v474;
  f32 v475;
  struct putevebox_s_array *v477;
  struct UnityEngine_Vector4_array *v479;
  struct putevebox_s_array *v482;
  struct UnityEngine_Vector4_array *v484;
  struct putevebox_s_array *v487;
  struct UnityEngine_Vector4_array *v489;
  struct putevebox_s_array *v493;
  struct UnityEngine_Vector4_array *v495;
  struct putevebox_s_array *v498;
  struct UnityEngine_Vector4_array *v500;
  struct putevebox_s_array *v503;
  struct UnityEngine_Vector4_array *v505;
  struct putevebox_s_array *v509;
  struct UnityEngine_Vector4_array *v511;
  struct putevebox_s_array *v514;
  struct UnityEngine_Vector4_array *v516;
  struct putevebox_s_array *v519;
  struct UnityEngine_Vector4_array *v521;
  u32 v525;
  struct putevebox_s_array *v529;
  struct UnityEngine_Vector4_array *v531;
  struct putevebox_s_array *v535;
  struct UnityEngine_Vector4_array *v537;
  struct putevebox_s_array *v542;
  struct UnityEngine_Vector4_array *v544;
  struct putevebox_s_array *v549;
  struct UnityEngine_Vector4_array *v551;
  struct putevebox_s_array *v554;
  struct System_Single_array *v556;
  struct UnityEngine_Vector4_array *v557;
  f32 v559;
  f32 v560;
  f32 v561;
  f32 v562;
  f32 v564;
  f32 v565;
  f32 v566;
  f32 v567;
  f32 v568;
  struct putevebox_s_array *v570;
  struct UnityEngine_Vector4_array *v572;
  struct putevebox_s_array *v575;
  struct UnityEngine_Vector4_array *v577;
  struct putevebox_s_array *v580;
  struct UnityEngine_Vector4_array *v582;
  struct putevebox_s_array *v586;
  struct UnityEngine_Vector4_array *v588;
  struct putevebox_s_array *v591;
  struct UnityEngine_Vector4_array *v593;
  struct putevebox_s_array *v596;
  struct UnityEngine_Vector4_array *v598;
  struct putevebox_s_array *v602;
  struct UnityEngine_Vector4_array *v604;
  struct putevebox_s_array *v607;
  struct UnityEngine_Vector4_array *v609;
  struct putevebox_s_array *v612;
  struct UnityEngine_Vector4_array *v614;
  u32 v618;
  struct putevebox_s_array *v622;
  struct UnityEngine_Vector4_array *v624;
  struct putevebox_s_array *v628;
  struct UnityEngine_Vector4_array *v630;
  struct putevebox_s_array *v635;
  struct UnityEngine_Vector4_array *v637;
  struct putevebox_s_array *v642;
  struct UnityEngine_Vector4_array *v644;
  struct putevebox_s_array *v647;
  struct System_Single_array *v649;
  struct UnityEngine_Vector4_array *v650;
  f32 v652;
  f32 v653;
  f32 v654;
  f32 v655;
  f32 v657;
  f32 v658;
  f32 v659;
  f32 v660;
  f32 v661;
  struct putevebox_s_array *v663;
  struct UnityEngine_Vector4_array *v665;
  struct putevebox_s_array *v668;
  struct UnityEngine_Vector4_array *v670;
  struct putevebox_s_array *v673;
  struct UnityEngine_Vector4_array *v675;
  struct putevebox_s_array *v679;
  struct UnityEngine_Vector4_array *v681;
  struct putevebox_s_array *v684;
  struct UnityEngine_Vector4_array *v686;
  struct putevebox_s_array *v689;
  struct UnityEngine_Vector4_array *v691;
  struct putevebox_s_array *v695;
  struct UnityEngine_Vector4_array *v697;
  struct putevebox_s_array *v700;
  struct UnityEngine_Vector4_array *v702;
  struct putevebox_s_array *v705;
  struct UnityEngine_Vector4_array *v707;
  u32 v711;
  struct putevebox_s_array *v715;
  struct UnityEngine_Vector4_array *v717;
  struct putevebox_s_array *v721;
  struct UnityEngine_Vector4_array *v723;
  struct putevebox_s_array *v728;
  struct UnityEngine_Vector4_array *v730;
  struct putevebox_s_array *v735;
  struct UnityEngine_Vector4_array *v737;
  struct putevebox_s_array *v740;
  struct System_Single_array *v742;
  struct UnityEngine_Vector4_array *v743;
  f32 v745;
  f32 v746;
  f32 v747;
  f32 v748;
  f32 v750;
  f32 v751;
  f32 v752;
  f32 v753;
  f32 v754;
  struct putevebox_s_array *v756;
  struct UnityEngine_Vector4_array *v758;
  struct putevebox_s_array *v761;
  struct UnityEngine_Vector4_array *v763;
  struct putevebox_s_array *v766;
  struct UnityEngine_Vector4_array *v768;
  struct putevebox_s_array *v772;
  struct UnityEngine_Vector4_array *v774;
  struct putevebox_s_array *v777;
  struct UnityEngine_Vector4_array *v779;
  struct putevebox_s_array *v782;
  struct UnityEngine_Vector4_array *v784;
  struct putevebox_s_array *v788;
  struct UnityEngine_Vector4_array *v790;
  struct putevebox_s_array *v793;
  struct UnityEngine_Vector4_array *v795;
  struct putevebox_s_array *v798;
  struct UnityEngine_Vector4_array *v800;
  u32 v804;
  struct putevebox_s_array *v808;
  struct UnityEngine_Vector4_array *v810;
  struct putevebox_s_array *v814;
  struct UnityEngine_Vector4_array *v816;
  struct putevebox_s_array *v821;
  struct UnityEngine_Vector4_array *v823;
  struct putevebox_s_array *v828;
  struct UnityEngine_Vector4_array *v830;
  struct putevebox_s_array *v833;
  struct System_Single_array *v835;
  struct UnityEngine_Vector4_array *v836;
  f32 v838;
  f32 v839;
  f32 v840;
  f32 v841;
  f32 v843;
  f32 v844;
  f32 v845;
  f32 v846;
  f32 v847;
  struct System_Single_array *v887;
  struct UnityEngine_Vector4_array *v889;
  f32 v891;
  f32 v892;
  f32 v893;
  f32 v894;
  UnityEngine_Vector4_array *v896;
  f32 v897;
  struct putevebox_s_array *v899;
  struct UnityEngine_Vector4_array *v901;
  f32 v904;
  struct putevebox_s_array *v905;
  struct System_Single_array *v907;
  u32 v923;
  struct putevebox_s_array *v927;
  struct UnityEngine_Vector4_array *v929;
  struct putevebox_s_array *v932;
  struct UnityEngine_Vector4_array *v934;
  struct putevebox_s_array *v937;
  struct UnityEngine_Vector4_array *v939;
  struct putevebox_s_array *v942;
  u32 v943;
  struct putevebox_s_array *v944;
  s64 v948;
  u32 *v956;
  s64 v963;
  s64 v969;
  u32 v974;
  struct putevebox_s_array *v976;
  struct UnityEngine_Vector4_array *v978;
  struct putevebox_s_array *v981;
  struct UnityEngine_Vector4_array *v983;
  struct putevebox_s_array *v986;
  struct UnityEngine_Vector4_array *v988;
  struct putevebox_s_array *v991;
  u32 v992;
  struct putevebox_s_array *v995;
  struct UnityEngine_Vector4_array *v997;
  struct putevebox_s_array *v1000;
  struct UnityEngine_Vector4_array *v1002;
  struct putevebox_s_array *v1005;
  struct UnityEngine_Vector4_array *v1007;
  struct putevebox_s_array *v1011;
  u32 v1012;
  struct System_Single_array *v1014;
  struct UnityEngine_Vector4_array *v1016;
  f32 v1019;
  struct putevebox_s_array *v1021;
  struct UnityEngine_Vector4_array *v1023;
  f32 v1026;
  struct putevebox_s_array *v1027;
  struct System_Single_array *v1029;
  f32 *v1030;
  u32 v1046;
  struct putevebox_s_array *v1050;
  struct UnityEngine_Vector4_array *v1052;
  struct putevebox_s_array *v1055;
  struct UnityEngine_Vector4_array *v1057;
  struct putevebox_s_array *v1060;
  struct UnityEngine_Vector4_array *v1062;
  struct putevebox_s_array *v1065;
  u32 v1066;
  struct putevebox_s_array *v1069;
  struct UnityEngine_Vector4_array *v1071;
  struct putevebox_s_array *v1074;
  struct UnityEngine_Vector4_array *v1076;
  struct putevebox_s_array *v1079;
  struct UnityEngine_Vector4_array *v1081;
  struct putevebox_s_array *v1085;
  u32 v1086;
  struct System_Single_array *v1088;
  struct UnityEngine_Vector4_array *v1090;
  f32 v1093;
  struct putevebox_s_array *v1095;
  struct UnityEngine_Vector4_array *v1097;
  f32 v1100;
  struct putevebox_s_array *v1101;
  struct System_Single_array *v1103;
  f32 *v1104;
  u32 v1120;
  struct putevebox_s_array *v1124;
  struct UnityEngine_Vector4_array *v1126;
  struct putevebox_s_array *v1129;
  struct UnityEngine_Vector4_array *v1131;
  struct putevebox_s_array *v1134;
  struct UnityEngine_Vector4_array *v1136;
  struct putevebox_s_array *v1139;
  u32 v1140;
  struct putevebox_s_array *v1143;
  struct UnityEngine_Vector4_array *v1145;
  struct putevebox_s_array *v1148;
  struct UnityEngine_Vector4_array *v1150;
  struct putevebox_s_array *v1153;
  struct UnityEngine_Vector4_array *v1155;
  struct putevebox_s_array *v1159;
  u32 v1160;
  struct System_Single_array *v1162;
  struct UnityEngine_Vector4_array *v1164;
  f32 v1167;
  struct putevebox_s_array *v1169;
  struct UnityEngine_Vector4_array *v1171;
  f32 v1173;
  struct putevebox_s_array *v1174;
  struct System_Single_array *v1176;
  struct putevebox_s_array *v1179;
  struct UnityEngine_Vector4_array *v1181;
  struct putevebox_s_array *v1184;
  struct UnityEngine_Vector4_array *v1186;
  struct putevebox_s_array *v1189;
  struct UnityEngine_Vector4_array *v1191;
  struct putevebox_s_array *v1195;
  u32 v1196;
  struct System_Single_array *v1210;
  struct UnityEngine_Vector4_array *v1212;
  f32 v1215;
  struct putevebox_s_array *v1217;
  struct UnityEngine_Vector4_array *v1219;
  f32 v1222;
  struct putevebox_s_array *v1223;
  f32 v1224;
  struct System_Single_array *v1226;
  f32 v1228;
  s64 v1229;
  struct putevebox_s_array *v1231;
  struct UnityEngine_Vector4_array *v1233;
  struct putevebox_s_array *v1236;
  struct UnityEngine_Vector4_array *v1238;
  struct putevebox_s_array *v1241;
  struct UnityEngine_Vector4_array *v1243;
  struct putevebox_s_array *v1247;
  u32 v1248;
  struct System_Single_array *v1250;
  struct UnityEngine_Vector4_array *v1252;
  f32 v1254;
  f32 v1255;
  f32 v1256;
  f32 v1257;
  f32 v1259;
  f32 v1260;
  f32 v1261;
  f32 v1262;
  f32 v1263;
  struct System_Single_array *v1267;
  struct UnityEngine_Vector4_array *v1269;
  f32 v1271;
  f32 v1272;
  f32 v1273;
  f32 v1274;
  f32 v1276;
  f32 v1277;
  f32 v1278;
  f32 v1279;
  f32 v1280;
  struct System_Single_array *v1284;
  struct UnityEngine_Vector4_array *v1286;
  f32 v1288;
  f32 v1289;
  f32 v1290;
  f32 v1291;
  f32 v1293;
  f32 v1294;
  f32 v1295;
  f32 v1296;
  f32 v1297;
  struct System_Single_array *v1301;
  struct UnityEngine_Vector4_array *v1303;
  f32 v1305;
  f32 v1306;
  f32 v1307;
  f32 v1308;
  f32 v1310;
  f32 v1311;
  f32 v1312;
  f32 v1313;
  struct System_Single_array *v1319;
  struct UnityEngine_Vector4_array *v1321;
  f32 v1323;
  f32 v1324;
  f32 v1325;
  f32 v1326;
  f32 v1328;
  f32 v1329;
  f32 v1330;
  f32 v1331;
  f32 v1332;
  f32 *v1338;
  u32 v1351;
  struct putevebox_s_array *v1355;
  struct UnityEngine_Vector4_array *v1357;
  struct putevebox_s_array *v1360;
  struct UnityEngine_Vector4_array *v1362;
  struct putevebox_s_array *v1365;
  struct UnityEngine_Vector4_array *v1367;
  struct putevebox_s_array *v1370;
  struct System_Single_array *v1372;
  struct UnityEngine_Vector4_array *v1373;
  f32 v1376;
  struct putevebox_s_array *v1378;
  struct UnityEngine_Vector4_array *v1380;
  f32 v1383;
  struct putevebox_s_array *v1384;
  f32 v1385;
  struct System_Single_array *v1387;
  f32 v1389;
  s64 v1390;
  struct putevebox_s_array *v1392;
  struct UnityEngine_Vector4_array *v1394;
  struct putevebox_s_array *v1397;
  struct UnityEngine_Vector4_array *v1399;
  struct putevebox_s_array *v1402;
  struct UnityEngine_Vector4_array *v1404;
  struct putevebox_s_array *v1408;
  u32 v1409;
  struct System_Single_array *v1414;
  f32 *v1416;
  f32 v1418;
  f32 v1419;
  f32 v1420;
  f32 v1421;
  f32 v1423;
  f32 v1424;
  f32 v1425;
  f32 v1426;
  f32 v1427;
  u32 v1445;
  struct putevebox_s_array *v1449;
  struct UnityEngine_Vector4_array *v1451;
  struct putevebox_s_array *v1454;
  struct UnityEngine_Vector4_array *v1456;
  struct putevebox_s_array *v1459;
  struct UnityEngine_Vector4_array *v1461;
  struct putevebox_s_array *v1464;
  struct System_Single_array *v1466;
  struct UnityEngine_Vector4_array *v1467;
  f32 v1470;
  struct putevebox_s_array *v1472;
  struct UnityEngine_Vector4_array *v1474;
  s64 v1475;
  f32 v1478;
  struct putevebox_s_array *v1479;
  f32 v1480;
  struct System_Single_array *v1482;
  f32 v1484;
  s64 v1485;
  struct putevebox_s_array *v1487;
  struct UnityEngine_Vector4_array *v1489;
  struct putevebox_s_array *v1492;
  struct UnityEngine_Vector4_array *v1494;
  struct putevebox_s_array *v1497;
  struct UnityEngine_Vector4_array *v1499;
  struct putevebox_s_array *v1503;
  u32 v1504;
  struct System_Single_array *v1509;
  struct UnityEngine_Vector4_array *v1511;
  f32 v1513;
  f32 v1514;
  f32 v1515;
  f32 v1516;
  f32 v1518;
  f32 v1519;
  f32 v1520;
  f32 v1521;
  f32 v1522;
  u32 v1540;
  struct putevebox_s_array *v1544;
  struct UnityEngine_Vector4_array *v1546;
  struct putevebox_s_array *v1549;
  struct UnityEngine_Vector4_array *v1551;
  struct putevebox_s_array *v1554;
  struct UnityEngine_Vector4_array *v1556;
  struct putevebox_s_array *v1559;
  struct System_Single_array *v1561;
  struct UnityEngine_Vector4_array *v1562;
  f32 v1565;
  struct putevebox_s_array *v1567;
  struct UnityEngine_Vector4_array *v1569;
  f32 v1571;
  struct putevebox_s_array *v1572;
  struct System_Single_array *v1574;
  struct putevebox_s_array *v1577;
  struct UnityEngine_Vector4_array *v1579;
  struct putevebox_s_array *v1582;
  struct UnityEngine_Vector4_array *v1584;
  struct putevebox_s_array *v1587;
  struct UnityEngine_Vector4_array *v1589;
  struct putevebox_s_array *v1592;
  u32 v1593;
  struct UnityEngine_Vector4_array *v1599;
  f32 v1602;
  struct putevebox_s_array *v1604;
  struct putevebox_s_array *v1606;
  struct putevebox_s_array *v1608;
  struct putevebox_s_array *v1610;
  struct putevebox_s_array *v1612;
  struct putevebox_s_array *v1614;
  struct putevebox_s_array *v1616;
  struct putevebox_s_array *v1618;
  struct putevebox_s_array *v1620;
  s64 v1623;
  s64 v1624;
  s64 v1625;
  s64 v1626;
  s64 v1627;
  s64 v1628;
  dds3Basic_t_o *v1629;
  dds3Basic_t_o *v1630;
  dds3Basic_t_o *v1631;
  f32 *d;
  f32 da;
  f32 v1634;
  f32 v1635;
  f32 *v1636;
  s64 v1637;
  s64 v1638;
  f32 *c;
  f32 *ca;
  f32 v1641;
  f32 v1642;
  f32 *a;
  f32 *aa;
  f32 *v1645;
  f32 *v1646;
  f32 *b;
  f32 *ba;
  f32 *bb;
  UnityEngine_Vector4_o v1650;
  UnityEngine_Vector4_o v1651;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o v1653;
  UnityEngine_Vector4_o v1654;
  UnityEngine_Vector4_o v1655;
  UnityEngine_Vector4_o v1656;
  UnityEngine_Vector4_o v1657;
  UnityEngine_Vector4_o v1658;
  UnityEngine_Vector4_o v1659;
  UnityEngine_Vector4_o v1660;
  UnityEngine_Vector4_o v1661;
  UnityEngine_Vector4_o v1662;
  UnityEngine_Vector4_o v1663;
  UnityEngine_Vector4_o v1664;
  UnityEngine_Vector4_o v1665;
  UnityEngine_Vector4_o v1666;
  UnityEngine_Vector4_o v1667;
  UnityEngine_Vector4_o v1668;
  UnityEngine_Vector4_o v1669;
  UnityEngine_Vector4_o v1670;
  UnityEngine_Vector4_o v1671;
  UnityEngine_Vector4_o v1672;
  UnityEngine_Vector4_o v1673;
  UnityEngine_Vector4_o v1674;
  UnityEngine_Vector4_o v1675;
  UnityEngine_Vector4_o v1676;
  UnityEngine_Vector4_o v1677;
  UnityEngine_Vector4_o v1678;
  UnityEngine_Vector4_o v1679;
  UnityEngine_Vector4_o v1680;
  UnityEngine_Vector4_o v1681;
  UnityEngine_Vector4_o v1682;

  *&v1653.x = 0;
  *&v1653.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v1651.x = 0;
  *&v1651.z = 0;
  v5 = 0.0;
  v6 = NewSpecific(UnityEngine_Vector4, 8u);
  sub_854690(&v1653.x, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&dst.x, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&v1651.x, 0.0, 0.0, 1.0, 1.0);
  v7 = NewSpecific(f32, 4u);
  v8 = NewSpecific(UnityEngine_Vector4, 4u);
  a = NewSpecific(UnityEngine_Vector4, 4u);
  *&v1650.x = 0;
  *&v1650.z = 0;
  gEvnRng->m_Items[gEvnRngNum] = pEvnRng;
  v15 = gEvnRng;
  max_length = v15->max_length;
  v17 = gEvnRng;
  pDate = v15->m_Items[gEvnRngNum]->pDate;
  b = v7;
  v21 = v17->m_Items[gEvnRngNum]->_union;
  pPut = v17->m_Items[gEvnRngNum]->pPut;
  v23 = SetfldResPut(pDate, v21, pPut);
  v24 = gEvnRng;
  v25 = v23;
  v27 = SetfldEveType(v24->m_Items[gEvnRngNum]->pDate, v23->_union, gEvnRng->m_Items[gEvnRngNum]->pPut);
  if (v27 == 2)
  {
    v138 = gEvnRng;
    v140 = v25->_union;
    v141 = v138->m_Items[gEvnRngNum]->pDate;
    v142 = SetfldResPutEveBox(v141, v140);
    y = v142->y;
    x = v142->x;
    da = v142->z;
    v145 = gEvnRng;
    sub_854710(&v145->m_Items[gEvnRngNum]->sisei->fields, 0);
    v147 = gEvnRng;
    sub_854710(&v147->m_Items[gEvnRngNum]->sisei->fields, 1u);
    v149 = gEvnRng;
    sub_854710(&v149->m_Items[gEvnRngNum]->sisei->fields, 2u);
    v151 = gEvnRng;
    sub_854710(&v151->m_Items[gEvnRngNum]->sisei->rot, 0);
    sub_854930(&dst, 0);
    v153 = gEvnRng;
    sub_854710(&v153->m_Items[gEvnRngNum]->sisei->rot, 1u);
    sub_854930(&dst, 1u);
    v155 = gEvnRng;
    sub_854710(&v155->m_Items[gEvnRngNum]->sisei->rot, 2u);
    sub_854930(&dst, 2u);
    v157 = gEvnRng;
    sub_854710(&v157->m_Items[gEvnRngNum]->sisei->rot, 3u);
    sub_854930(&dst, 3u);
    LoadIdentity();
    SDF_VU0__LOADVECTOR(dst);
    ToMatrix();
    v1635 = x;
    sub_854930(&v1653, 0);
    v1641 = y;
    sub_854930(&v1653, 1u);
    sub_854930(&v1653, 2u);
    SDF_VU0__LOADVECTOR(v1653);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(v6 + 2);
    sub_854930(&v1653, 0);
    sub_854930(&v1653, 1u);
    sub_854930(&v1653, 2u);
    SDF_VU0__LOADVECTOR(v1653);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(v6 + 3);
    sub_854930(&v1653, 0);
    sub_854930(&v1653, 1u);
    sub_854930(&v1653, 2u);
    SDF_VU0__LOADVECTOR(v1653);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(v6 + 4);
    sub_854930(&v1653, 0);
    sub_854930(&v1653, 1u);
    sub_854930(&v1653, 2u);
    SDF_VU0__LOADVECTOR(v1653);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(v6 + 5);
    sub_854930(&v1653, 0);
    sub_854930(&v1653, 1u);
    sub_854930(&v1653, 2u);
    SDF_VU0__LOADVECTOR(v1653);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(v6 + 6);
    sub_854930(&v1653, 0);
    sub_854930(&v1653, 1u);
    sub_854930(&v1653, 2u);
    SDF_VU0__LOADVECTOR(v1653);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(v6 + 7);
    sub_854930(&v1653, 0);
    sub_854930(&v1653, 1u);
    sub_854930(&v1653, 2u);
    SDF_VU0__LOADVECTOR(v1653);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(v6 + 8);
    sub_854930(&v1653, 0);
    sub_854930(&v1653, 1u);
    sub_854930(&v1653, 2u);
    SDF_VU0__LOADVECTOR(v1653);
    SDF_VU0__APPLYMATRIX();
    SDF_VU0__STOREVECTOR(v6 + 9);
    v169 = 0;
    v170 = 4;
    do
    {
      vtx = gEvnRngBox->m_Items[gEvnRngNum]->vtx;
      sub_854710(&v6[v170], 0);
      sub_854930(vtx + v170 * 8, 0);
      v177 = gEvnRngBox;
      v179 = v177->m_Items[gEvnRngNum]->vtx;
      sub_854710(&v6[v170], 1u);
      sub_854930(v179 + v170 * 8, 1u);
      v182 = gEvnRngBox;
      v184 = v182->m_Items[gEvnRngNum]->vtx;
      sub_854710(&v6[v170], 2u);
      sub_854930(v184 + v170 * 8, 2u);
      v187 = gEvnRngBox;
      v189 = v187->m_Items[gEvnRngNum]->vtx;
      sub_854930(v189 + v170 * 8, 3u);
      ++v169;
      v170 += 2;
    }
    while (v169 != 8);
    SDF_VU0__LOADVECTOR(v1651);
    SDF_VU0__APPLYMATRIX();
    v193 = gEvnRngBox;
    SDF_VU0__STOREVECTOR(&v193->m_Items[gEvnRngNum]->boxnml);
    v195 = gEvnRngBox;
    v197 = v195->m_Items[gEvnRngNum]->vtx;
    sub_854710(v197->m_Items, 0);
    v199 = v8 + 3;
    sub_854930((v8 + 4), 0);
    v201 = gEvnRngBox;
    v203 = v201->m_Items[gEvnRngNum]->vtx;
    sub_854710(v203->m_Items, 1u);
    sub_854930((v8 + 4), 1u);
    v206 = gEvnRngBox;
    v208 = v206->m_Items[gEvnRngNum]->vtx;
    sub_854710(v208->m_Items, 2u);
    sub_854930((v8 + 4), 2u);
    sub_854930((v8 + 4), 3u);
    v212 = gEvnRngBox;
    v214 = v212->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v214->m_Items[1], 0);
    sub_854930((v8 + 6), 0);
    v217 = gEvnRngBox;
    v219 = v217->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v219->m_Items[1], 1u);
    sub_854930((v8 + 6), 1u);
    v222 = gEvnRngBox;
    v224 = v222->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v224->m_Items[1], 2u);
    sub_854930((v8 + 6), 2u);
    sub_854930((v8 + 6), 3u);
    v228 = gEvnRngBox;
    v230 = v228->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v230->m_Items[2], 0);
    sub_854930((v8 + 8), 0);
    v233 = gEvnRngBox;
    v235 = v233->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v235->m_Items[2], 1u);
    sub_854930((v8 + 8), 1u);
    v238 = gEvnRngBox;
    v240 = v238->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v240->m_Items[2], 2u);
    sub_854930((v8 + 8), 2u);
    v1629 = pBasic;
    sub_854930((v8 + 8), 3u);
    v246 = (b + 6);
    v245 = *(b + 6);
    aa = b + 8;
    v1636 = b + 11;
    c = b + 10;
    CalcABCD(v8, aa, b + 9, b + 10, b + 11);
    v1646 = b + 9;
    v250 = gEvnRngBox;
    facenml = v250->m_Items[gEvnRngNum]->facenml;
    sub_854930(facenml->m_Items, 0);
    v255 = gEvnRngBox;
    v257 = v255->m_Items[gEvnRngNum]->facenml;
    sub_854930(v257->m_Items, 1u);
    v260 = gEvnRngBox;
    v262 = v260->m_Items[gEvnRngNum]->facenml;
    sub_854930(v262->m_Items, 2u);
    v267 = gEvnRngBox;
    v269 = v267->m_Items[gEvnRngNum]->facenml;
    sub_854930(v269->m_Items, 3u);
    v272 = gEvnRngBox;
    v273 = v272->max_length;
    facenum = v272->m_Items[gEvnRngNum]->facenum;
    v367 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
    v368 = v367->m_Items[0].x;
    v369 = v367->m_Items[0].y;
    z = v367->m_Items[0].z;
    w = v367->m_Items[0].w;
    v372 = *(v8 + 8);
    v373 = *(v8 + 9);
    v374 = *(v8 + 10);
    v375 = *(v8 + 11);
    v1655.x = v368;
    v1655.y = v369;
    v1655.z = z;
    v1655.w = w;
    v1670.x = v372;
    v1670.y = v373;
    v1670.z = v374;
    v1670.w = v375;
    v376 = MATH_DotProduct(v1655, v1670);
    facenum->m_Items[0] = v376;
    v378 = gEvnRngBox;
    v380 = v378->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v380->m_Items[1], 0);
    sub_854930((v8 + 4), 0);
    v383 = gEvnRngBox;
    v385 = v383->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v385->m_Items[1], 1u);
    sub_854930((v8 + 4), 1u);
    v388 = gEvnRngBox;
    v390 = v388->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v390->m_Items[1], 2u);
    sub_854930((v8 + 4), 2u);
    sub_854930((v8 + 4), 3u);
    v394 = gEvnRngBox;
    v396 = v394->m_Items[gEvnRngNum]->vtx;
    sub_854710(v396->m_Items, 0);
    sub_854930((v8 + 6), 0);
    v399 = gEvnRngBox;
    v401 = v399->m_Items[gEvnRngNum]->vtx;
    sub_854710(v401->m_Items, 1u);
    sub_854930((v8 + 6), 1u);
    v404 = gEvnRngBox;
    v406 = v404->m_Items[gEvnRngNum]->vtx;
    sub_854710(v406->m_Items, 2u);
    sub_854930((v8 + 6), 2u);
    sub_854930((v8 + 6), 3u);
    v410 = gEvnRngBox;
    v412 = v410->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v412->m_Items[5], 0);
    sub_854930((v8 + 8), 0);
    v415 = gEvnRngBox;
    v417 = v415->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v417->m_Items[5], 1u);
    sub_854930((v8 + 8), 1u);
    v420 = gEvnRngBox;
    v422 = v420->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v422->m_Items[5], 2u);
    sub_854930((v8 + 8), 2u);
    sub_854930((v8 + 8), 3u);
    v426 = *v246;
    CalcABCD(v8, aa, v1646, c, v1636);
    v430 = gEvnRngBox;
    v432 = v430->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v432->m_Items[1], 0);
    v436 = gEvnRngBox;
    v438 = v436->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v438->m_Items[1], 1u);
    v443 = gEvnRngBox;
    v445 = v443->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v445->m_Items[1], 2u);
    v450 = gEvnRngBox;
    v452 = v450->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v452->m_Items[1], 3u);
    v455 = gEvnRngBox;
    v456 = v455->max_length;
    v462 = v455->m_Items[gEvnRngNum]->facenum;
    v464 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
    v466 = v464->m_Items[1].x;
    v467 = v464->m_Items[1].y;
    v468 = v464->m_Items[1].z;
    v469 = v464->m_Items[1].w;
    v471 = *(v8 + 8);
    v472 = *(v8 + 9);
    v473 = *(v8 + 10);
    v474 = *(v8 + 11);
    v1656.x = v466;
    v1656.y = v467;
    v1656.z = v468;
    v1656.w = v469;
    v1671.x = v471;
    v1671.y = v472;
    v1671.z = v473;
    v1671.w = v474;
    v475 = MATH_DotProduct(v1656, v1671);
    v462->m_Items[1] = v475;
    v477 = gEvnRngBox;
    v479 = v477->m_Items[gEvnRngNum]->vtx;
    sub_854710(v479->m_Items, 0);
    sub_854930((v8 + 4), 0);
    v482 = gEvnRngBox;
    v484 = v482->m_Items[gEvnRngNum]->vtx;
    sub_854710(v484->m_Items, 1u);
    sub_854930((v8 + 4), 1u);
    v487 = gEvnRngBox;
    v489 = v487->m_Items[gEvnRngNum]->vtx;
    sub_854710(v489->m_Items, 2u);
    sub_854930((v8 + 4), 2u);
    sub_854930((v8 + 4), 3u);
    v493 = gEvnRngBox;
    v495 = v493->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v495->m_Items[2], 0);
    sub_854930((v8 + 6), 0);
    v498 = gEvnRngBox;
    v500 = v498->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v500->m_Items[2], 1u);
    sub_854930((v8 + 6), 1u);
    v503 = gEvnRngBox;
    v505 = v503->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v505->m_Items[2], 2u);
    sub_854930((v8 + 6), 2u);
    sub_854930((v8 + 6), 3u);
    v509 = gEvnRngBox;
    v511 = v509->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v511->m_Items[4], 0);
    sub_854930((v8 + 8), 0);
    v514 = gEvnRngBox;
    v516 = v514->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v516->m_Items[4], 1u);
    sub_854930((v8 + 8), 1u);
    v519 = gEvnRngBox;
    v521 = v519->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v521->m_Items[4], 2u);
    sub_854930((v8 + 8), 2u);
    sub_854930((v8 + 8), 3u);
    v525 = *v246;
    CalcABCD(v8, aa, v1646, c, v1636);
    v529 = gEvnRngBox;
    v531 = v529->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v531->m_Items[2], 0);
    v535 = gEvnRngBox;
    v537 = v535->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v537->m_Items[2], 1u);
    v542 = gEvnRngBox;
    v544 = v542->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v544->m_Items[2], 2u);
    v549 = gEvnRngBox;
    v551 = v549->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v551->m_Items[2], 3u);
    v554 = gEvnRngBox;
    v556 = v554->m_Items[gEvnRngNum]->facenum;
    v557 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
    v559 = v557->m_Items[2].x;
    v560 = v557->m_Items[2].y;
    v561 = v557->m_Items[2].z;
    v562 = v557->m_Items[2].w;
    v564 = *(v8 + 8);
    v565 = *(v8 + 9);
    v566 = *(v8 + 10);
    v567 = *(v8 + 11);
    v1657.x = v559;
    v1657.y = v560;
    v1657.z = v561;
    v1657.w = v562;
    v1672.x = v564;
    v1672.y = v565;
    v1672.z = v566;
    v1672.w = v567;
    v568 = MATH_DotProduct(v1657, v1672);
    v556->m_Items[2] = v568;
    v570 = gEvnRngBox;
    v572 = v570->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v572->m_Items[3], 0);
    sub_854930((v8 + 4), 0);
    v575 = gEvnRngBox;
    v577 = v575->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v577->m_Items[3], 1u);
    sub_854930((v8 + 4), 1u);
    v580 = gEvnRngBox;
    v582 = v580->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v582->m_Items[3], 2u);
    sub_854930((v8 + 4), 2u);
    sub_854930((v8 + 4), 3u);
    v586 = gEvnRngBox;
    v588 = v586->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v588->m_Items[1], 0);
    sub_854930((v8 + 6), 0);
    v591 = gEvnRngBox;
    v593 = v591->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v593->m_Items[1], 1u);
    sub_854930((v8 + 6), 1u);
    v596 = gEvnRngBox;
    v598 = v596->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v598->m_Items[1], 2u);
    sub_854930((v8 + 6), 2u);
    sub_854930((v8 + 6), 3u);
    v602 = gEvnRngBox;
    v604 = v602->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v604->m_Items[7], 0);
    sub_854930((v8 + 8), 0);
    v607 = gEvnRngBox;
    v609 = v607->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v609->m_Items[7], 1u);
    sub_854930((v8 + 8), 1u);
    v612 = gEvnRngBox;
    v614 = v612->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v614->m_Items[7], 2u);
    sub_854930((v8 + 8), 2u);
    sub_854930((v8 + 8), 3u);
    v618 = *v246;
    CalcABCD(v8, aa, v1646, c, v1636);
    v622 = gEvnRngBox;
    v624 = v622->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v624->m_Items[3], 0);
    v628 = gEvnRngBox;
    v630 = v628->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v630->m_Items[3], 1u);
    v635 = gEvnRngBox;
    v637 = v635->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v637->m_Items[3], 2u);
    v642 = gEvnRngBox;
    v644 = v642->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v644->m_Items[3], 3u);
    v647 = gEvnRngBox;
    v649 = v647->m_Items[gEvnRngNum]->facenum;
    v650 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
    v652 = v650->m_Items[3].x;
    v653 = v650->m_Items[3].y;
    v654 = v650->m_Items[3].z;
    v655 = v650->m_Items[3].w;
    v657 = *(v8 + 8);
    v658 = *(v8 + 9);
    v659 = *(v8 + 10);
    v660 = *(v8 + 11);
    v1658.x = v652;
    v1658.y = v653;
    v1658.z = v654;
    v1658.w = v655;
    v1673.x = v657;
    v1673.y = v658;
    v1673.z = v659;
    v1673.w = v660;
    v661 = MATH_DotProduct(v1658, v1673);
    v649->m_Items[3] = v661;
    v663 = gEvnRngBox;
    v665 = v663->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v665->m_Items[2], 0);
    sub_854930((v8 + 4), 0);
    v668 = gEvnRngBox;
    v670 = v668->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v670->m_Items[2], 1u);
    sub_854930((v8 + 4), 1u);
    v673 = gEvnRngBox;
    v675 = v673->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v675->m_Items[2], 2u);
    sub_854930((v8 + 4), 2u);
    sub_854930((v8 + 4), 3u);
    v679 = gEvnRngBox;
    v681 = v679->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v681->m_Items[3], 0);
    sub_854930((v8 + 6), 0);
    v684 = gEvnRngBox;
    v686 = v684->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v686->m_Items[3], 1u);
    sub_854930((v8 + 6), 1u);
    v689 = gEvnRngBox;
    v691 = v689->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v691->m_Items[3], 2u);
    sub_854930((v8 + 6), 2u);
    sub_854930((v8 + 6), 3u);
    v695 = gEvnRngBox;
    v697 = v695->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v697->m_Items[6], 0);
    sub_854930((v8 + 8), 0);
    v700 = gEvnRngBox;
    v702 = v700->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v702->m_Items[6], 1u);
    sub_854930((v8 + 8), 1u);
    v705 = gEvnRngBox;
    v707 = v705->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v707->m_Items[6], 2u);
    sub_854930((v8 + 8), 2u);
    sub_854930((v8 + 8), 3u);
    v711 = *v246;
    CalcABCD(v8, aa, v1646, c, v1636);
    v715 = gEvnRngBox;
    v717 = v715->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v717->m_Items[4], 0);
    v721 = gEvnRngBox;
    v723 = v721->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v723->m_Items[4], 1u);
    v728 = gEvnRngBox;
    v730 = v728->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v730->m_Items[4], 2u);
    v735 = gEvnRngBox;
    v737 = v735->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v737->m_Items[4], 3u);
    v740 = gEvnRngBox;
    v742 = v740->m_Items[gEvnRngNum]->facenum;
    v743 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
    v745 = v743->m_Items[4].x;
    v746 = v743->m_Items[4].y;
    v747 = v743->m_Items[4].z;
    v748 = v743->m_Items[4].w;
    v750 = *(v8 + 8);
    v751 = *(v8 + 9);
    v752 = *(v8 + 10);
    v753 = *(v8 + 11);
    v1659.x = v745;
    v1659.y = v746;
    v1659.z = v747;
    v1659.w = v748;
    v1674.x = v750;
    v1674.y = v751;
    v1674.z = v752;
    v1674.w = v753;
    v754 = MATH_DotProduct(v1659, v1674);
    v742->m_Items[4] = v754;
    v756 = gEvnRngBox;
    v758 = v756->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v758->m_Items[6], 0);
    sub_854930((v8 + 4), 0);
    v761 = gEvnRngBox;
    v763 = v761->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v763->m_Items[6], 1u);
    sub_854930((v8 + 4), 1u);
    v766 = gEvnRngBox;
    v768 = v766->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v768->m_Items[6], 2u);
    sub_854930((v8 + 4), 2u);
    sub_854930((v8 + 4), 3u);
    v772 = gEvnRngBox;
    v774 = v772->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v774->m_Items[7], 0);
    sub_854930((v8 + 6), 0);
    v777 = gEvnRngBox;
    v779 = v777->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v779->m_Items[7], 1u);
    sub_854930((v8 + 6), 1u);
    v782 = gEvnRngBox;
    v784 = v782->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v784->m_Items[7], 2u);
    sub_854930((v8 + 6), 2u);
    sub_854930((v8 + 6), 3u);
    v788 = gEvnRngBox;
    v790 = v788->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v790->m_Items[4], 0);
    sub_854930((v8 + 8), 0);
    v793 = gEvnRngBox;
    v795 = v793->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v795->m_Items[4], 1u);
    sub_854930((v8 + 8), 1u);
    v798 = gEvnRngBox;
    v800 = v798->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v800->m_Items[4], 2u);
    sub_854930((v8 + 8), 2u);
    sub_854930((v8 + 8), 3u);
    v804 = *v246;
    CalcABCD(v8, aa, v1646, c, v1636);
    v808 = gEvnRngBox;
    v810 = v808->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v810->m_Items[5], 0);
    v814 = gEvnRngBox;
    v816 = v814->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v816->m_Items[5], 1u);
    v821 = gEvnRngBox;
    v823 = v821->m_Items[gEvnRngNum]->facenml;
    pBasic = v1629;
    sub_854930(&v823->m_Items[5], 2u);
    v828 = gEvnRngBox;
    v830 = v828->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v830->m_Items[5], 3u);
    v833 = gEvnRngBox;
    v835 = v833->m_Items[gEvnRngNum]->facenum;
    v836 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
    v838 = v836->m_Items[5].x;
    v839 = v836->m_Items[5].y;
    v840 = v836->m_Items[5].z;
    v841 = v836->m_Items[5].w;
    v843 = *(v8 + 8);
    v844 = *(v8 + 9);
    v845 = *(v8 + 10);
    v846 = *(v8 + 11);
    v1660.x = v838;
    v1660.y = v839;
    v1660.z = v840;
    v1660.w = v841;
    v1675.x = v843;
    v1675.y = v844;
    v1675.z = v845;
    v1675.w = v846;
    v847 = MATH_DotProduct(v1660, v1675);
    v29 = v1641;
    v30 = v1635;
    v835->m_Items[5] = v847;
    v5 = da;
      goto LABEL_1936;
LABEL_1934:
    goto LABEL_1936;
  }
  v29 = 0.0;
  v30 = 0.0;
  if (v27 != 1)
    goto LABEL_1933;
  v32 = gEvnRng;
  v34 = v25->_union;
  v35 = v32->m_Items[gEvnRngNum]->pDate;
  v36 = SetfldResPutEvePoly(v35, v34);
  v37 = gEvnRng;
  v39 = v36->y;
  v38 = v36->z;
  sub_854710(&v37->m_Items[gEvnRngNum]->sisei->fields, 0);
  v41 = gEvnRng;
  sub_854710(&v41->m_Items[gEvnRngNum]->sisei->fields, 1u);
  v43 = gEvnRng;
  sub_854710(&v43->m_Items[gEvnRngNum]->sisei->fields, 2u);
  v45 = gEvnRng;
  SDF_VU0__COPYVECTOR(&dst, v45->m_Items[gEvnRngNum]->sisei->rot);
  LoadIdentity();
  SDF_VU0__LOADVECTOR(dst);
  ToMatrix();
  v1634 = v38;
  sub_854930(&v1653, 0);
  sub_854930(&v1653, 1u);
  sub_854930(&v1653, 2u);
  SDF_VU0__LOADVECTOR(v1653);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(v6 + 2);
  sub_854930(&v1653, 0);
  sub_854930(&v1653, 1u);
  sub_854930(&v1653, 2u);
  SDF_VU0__LOADVECTOR(v1653);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(v6 + 3);
  sub_854930(&v1653, 0);
  sub_854930(&v1653, 1u);
  sub_854930(&v1653, 2u);
  SDF_VU0__LOADVECTOR(v1653);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(v6 + 4);
  sub_854930(&v1653, 0);
  sub_854930(&v1653, 1u);
  sub_854930(&v1653, 2u);
  SDF_VU0__LOADVECTOR(v1653);
  SDF_VU0__APPLYMATRIX();
  SDF_VU0__STOREVECTOR(v6 + 5);
  v53 = 0;
  v54 = 4;
  do
  {
    v56 = gEvnRngBox;
    v58 = v56->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v6[v54], 0);
    sub_854930(v58 + v54 * 8, 0);
    v61 = gEvnRngBox;
    v63 = v61->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v6[v54], 1u);
    sub_854930(v63 + v54 * 8, 1u);
    v66 = gEvnRngBox;
    v68 = v66->m_Items[gEvnRngNum]->vtx;
    sub_854710(&v6[v54], 2u);
    sub_854930(v68 + v54 * 8, 2u);
    v71 = gEvnRngBox;
    v73 = v71->m_Items[gEvnRngNum]->vtx;
    sub_854930(v73 + v54 * 8, 3u);
    ++v53;
    v54 += 2;
  }
  while (v53 != 4);
  SDF_VU0__LOADVECTOR(v1651);
  SDF_VU0__APPLYMATRIX();
  v77 = gEvnRngBox;
  SDF_VU0__STOREVECTOR(&v77->m_Items[gEvnRngNum]->boxnml);
  v81 = gEvnRngBox;
  v83 = v81->m_Items[gEvnRngNum]->vtx;
  v84 = v8 + 3;
  SDF_VU0__COPYVECTOR(v8 + 2, v83->m_Items[0]);
  v87 = gEvnRngBox;
  v89 = v87->m_Items[gEvnRngNum]->vtx;
  SDF_VU0__COPYVECTOR(v8 + 3, v89->m_Items[1]);
  v94 = gEvnRngBox;
  v96 = v94->m_Items[gEvnRngNum]->vtx;
  SDF_VU0__COPYVECTOR(v8 + 4, v96->m_Items[2]);
  v101 = gEvnRngBox;
  v103 = v101->m_Items[gEvnRngNum]->vtx;
  SDF_VU0__COPYVECTOR(v8 + 5, v103->m_Items[3]);
  v108 = (b + 6);
  v107 = *(b + 6);
  v1645 = b + 8;
  d = b + 11;
  CalcABCD(v8, b + 8, b + 9, b + 10, b + 11);
  v113 = gEvnRngBox;
  v115 = v113->m_Items[gEvnRngNum]->facenml;
  sub_854930(v115->m_Items, 0);
  v118 = gEvnRngBox;
  v120 = v118->m_Items[gEvnRngNum]->facenml;
  sub_854930(v120->m_Items, 1u);
  v123 = gEvnRngBox;
  v125 = v123->m_Items[gEvnRngNum]->facenml;
  sub_854930(v125->m_Items, 2u);
  v130 = gEvnRngBox;
  v132 = v130->m_Items[gEvnRngNum]->facenml;
  sub_854930(v132->m_Items, 3u);
  v135 = gEvnRngBox;
  v136 = v135->max_length;
  v276 = v135->m_Items[gEvnRngNum]->facenum;
  v278 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
  v1642 = v39;
  v280 = v278->m_Items[0].x;
  v281 = v278->m_Items[0].y;
  v282 = v278->m_Items[0].z;
  v283 = v278->m_Items[0].w;
  v285 = v8 + 4;
  v286 = *(v8 + 8);
  v287 = *(v8 + 9);
  v288 = *(v8 + 10);
  v289 = *(v8 + 11);
  v1654.x = v280;
  v1654.y = v281;
  v1654.z = v282;
  v1654.w = v283;
  v1669.x = v286;
  v1669.y = v287;
  v1669.z = v288;
  v1669.w = v289;
  v290 = MATH_DotProduct(v1654, v1669);
  v276->m_Items[0] = v290;
  v292 = gEvnRngBox;
  v29 = v1642;
  v30 = v1634;
  v5 = 0.0;
  v294 = v292->m_Items[gEvnRngNum]->facenml;
  sub_854710(v294->m_Items, 0);
  v298 = v297;
  v299 = sdfFabs(v298);
  v300 = gEvnRngBox;
  v301 = v299;
  v303 = v300->m_Items[gEvnRngNum]->facenml;
  sub_854710(v303->m_Items, 1u);
  v306 = sdfFabs(v305);
  v307 = gEvnRngBox;
  v308 = v306;
  v310 = v307->m_Items[gEvnRngNum]->facenml;
  sub_854710(v310->m_Items, 2u);
  v313 = sdfFabs(v312);
  ca = b + 10;
  if (v301 > v308 && v301 > v313)
  {
    v315 = gEvnRngBox;
    v315->m_Items[gEvnRngNum]->mode2D = 0;
    sub_854930(&v1650, 0);
    ba = b + 9;
    sub_854710((v8 + 4), 1u);
    v319 = (v8 + 6);
    sub_854710((v8 + 6), 1u);
    v1623 = (v8 + 8);
    sub_854710((v8 + 8), 1u);
    v1625 = (v8 + 10);
    sub_854710((v8 + 10), 1u);
    sub_854930(&v1650, 1u);
    sub_854710((v8 + 4), 2u);
    sub_854710(v319, 2u);
    v1627 = (v8 + 4);
    sub_854710(v1623, 2u);
    sub_854710(v1625, 2u);
    sub_854930(&v1650, 2u);
    v326 = a + 6;
    v1637 = (a + 8);
    sub_854930((a + 8), 0);
    sub_854710(v1627, 1u);
    sub_854930(v1637, 1u);
    sub_854710(v1627, 2u);
    sub_854930(v1637, 2u);
    v333 = (a + 12);
    sub_854930((a + 12), 0);
    sub_854710(v319, 1u);
    sub_854930((a + 12), 1u);
    sub_854710(v319, 2u);
    sub_854930((a + 12), 2u);
    v339 = (a + 16);
    sub_854930((a + 16), 0);
    sub_854710((a + 12), 1u);
    sub_854930((a + 16), 1u);
    sub_854710((a + 12), 2u);
    sub_854930((a + 16), 2u);
    v345 = *v108;
    v1630 = pBasic;
    CalcABCD(a, v1645, ba, ca, d);
    v347 = gEvnRngBox;
    v349 = v347->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v349->m_Items[1], 0);
    v352 = gEvnRngBox;
    v354 = v352->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v354->m_Items[1], 1u);
    v357 = gEvnRngBox;
    v359 = v357->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v359->m_Items[1], 2u);
    v362 = gEvnRngBox;
    v363 = v362->max_length;
    v887 = v362->m_Items[gEvnRngNum]->facenum;
    v889 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
    v891 = v889->m_Items[1].x;
    v892 = v889->m_Items[1].y;
    v893 = v889->m_Items[1].z;
    v894 = v889->m_Items[1].w;
    v896 = a;
    v1661.x = v891;
    v1661.y = v892;
    v1661.z = v893;
    v1661.w = v894;
    v897 = MATH_DotProduct(v1661, *(a + 8), 0);
    v887->m_Items[1] = v897;
    v899 = gEvnRngBox;
    v901 = v899->m_Items[gEvnRngNum]->facenml;
    v904 = MATH_DotProduct(v1650, v901->m_Items[1]);
    v905 = gEvnRngBox;
    v907 = v905->m_Items[gEvnRngNum]->facenum;
    if ((v904 - v907->m_Items[1]) < 0.0)
    {
      v995 = gEvnRngBox;
      v997 = v995->m_Items[gEvnRngNum]->facenml;
      sub_854930(&v997->m_Items[1], 0);
      v1000 = gEvnRngBox;
      v1002 = v1000->m_Items[gEvnRngNum]->facenml;
      sub_854930(&v1002->m_Items[1], 1u);
      v1005 = gEvnRngBox;
      v1007 = v1005->m_Items[gEvnRngNum]->facenml;
      sub_854930(&v1007->m_Items[1], 2u);
      v1011 = gEvnRngBox;
      v1012 = v1011->max_length;
      v1250 = v1011->m_Items[gEvnRngNum]->facenum;
      v1252 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
      v1254 = v1252->m_Items[1].x;
      v1255 = v1252->m_Items[1].y;
      v1256 = v1252->m_Items[1].z;
      v1257 = v1252->m_Items[1].w;
      v896 = a;
      v1259 = a[8];
      v1260 = a[9];
      v1261 = a[10];
      v1262 = a[11];
      v1662.x = v1254;
      v1662.y = v1255;
      v1662.z = v1256;
      v1662.w = v1257;
      v1676.x = v1259;
      v1676.y = v1260;
      v1676.z = v1261;
      v1676.w = v1262;
      v1263 = MATH_DotProduct(v1662, v1676);
      v29 = v1642;
      v30 = v1634;
      v1250->m_Items[1] = v1263;
      if (*v326)
      {
LABEL_1062:
        sub_854930(v1637, 0);
        sub_854710(v319, 1u);
        sub_854930(v1637, 1u);
        sub_854710(v319, 2u);
        sub_854930(v1637, 2u);
        sub_854930(v333, 0);
        sub_854710(v1623, 1u);
        sub_854930(v333, 1u);
        sub_854710(v1623, 2u);
        sub_854930(v333, 2u);
        sub_854930(v339, 0);
        sub_854710(v333, 1u);
        sub_854930(v339, 1u);
        sub_854710(v333, 2u);
        sub_854930(v339, 2u);
        v923 = *v108;
        CalcABCD(v896, v1645, ba, ca, d);
        v927 = gEvnRngBox;
        v929 = v927->m_Items[gEvnRngNum]->facenml;
        sub_854930(&v929->m_Items[2], 0);
        v932 = gEvnRngBox;
        v934 = v932->m_Items[gEvnRngNum]->facenml;
        sub_854930(&v934->m_Items[2], 1u);
        v937 = gEvnRngBox;
        v939 = v937->m_Items[gEvnRngNum]->facenml;
        sub_854930(&v939->m_Items[2], 2u);
        v942 = gEvnRngBox;
        v943 = v942->max_length;
        v1014 = v942->m_Items[gEvnRngNum]->facenum;
        v1016 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
        v1019 = MATH_DotProduct(v1016->m_Items[2], v896->m_Items[1]);
        v1014->m_Items[2] = v1019;
        v1021 = gEvnRngBox;
        v1023 = v1021->m_Items[gEvnRngNum]->facenml;
        v1026 = MATH_DotProduct(v1650, v1023->m_Items[2]);
        v1027 = gEvnRngBox;
        v1029 = v1027->m_Items[gEvnRngNum]->facenum;
        if ((v1026 - v1029->m_Items[2]) < 0.0)
        {
          v1069 = gEvnRngBox;
          v1071 = v1069->m_Items[gEvnRngNum]->facenml;
          sub_854930(&v1071->m_Items[2], 0);
          v1074 = gEvnRngBox;
          v1076 = v1074->m_Items[gEvnRngNum]->facenml;
          sub_854930(&v1076->m_Items[2], 1u);
          v1079 = gEvnRngBox;
          v1081 = v1079->m_Items[gEvnRngNum]->facenml;
          sub_854930(&v1081->m_Items[2], 2u);
          v1085 = gEvnRngBox;
          v1086 = v1085->max_length;
          v1267 = v1085->m_Items[gEvnRngNum]->facenum;
          v1269 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
          v1271 = v1269->m_Items[2].x;
          v1272 = v1269->m_Items[2].y;
          v1273 = v1269->m_Items[2].z;
          v1274 = v1269->m_Items[2].w;
          v1276 = v896->m_Items[1].x;
          v1277 = v896->m_Items[1].y;
          v1278 = v896->m_Items[1].z;
          v1279 = v896->m_Items[1].w;
          v1663.x = v1271;
          v1663.y = v1272;
          v1663.z = v1273;
          v1663.w = v1274;
          v1677.x = v1276;
          v1677.y = v1277;
          v1677.z = v1278;
          v1677.w = v1279;
          v1280 = MATH_DotProduct(v1663, v1677);
          v29 = v1642;
          v30 = v1634;
          v1267->m_Items[2] = v1280;
          v1030 = ca;
          if (*v326)
          {
LABEL_1242:
            sub_854930(v1637, 0);
            sub_854710(v1623, 1u);
            sub_854930(v1637, 1u);
            sub_854710(v1623, 2u);
            sub_854930(v1637, 2u);
            sub_854930(v333, 0);
            sub_854710(v1625, 1u);
            sub_854930(v333, 1u);
            sub_854710(v1625, 2u);
            sub_854930(v333, 2u);
            sub_854930(v339, 0);
            sub_854710(v333, 1u);
            sub_854930(v339, 1u);
            sub_854710(v333, 2u);
            sub_854930(v339, 2u);
            v1046 = *v108;
            CalcABCD(v896, v1645, ba, v1030, d);
            v1050 = gEvnRngBox;
            v1052 = v1050->m_Items[gEvnRngNum]->facenml;
            sub_854930(&v1052->m_Items[3], 0);
            v1055 = gEvnRngBox;
            v1057 = v1055->m_Items[gEvnRngNum]->facenml;
            sub_854930(&v1057->m_Items[3], 1u);
            v1060 = gEvnRngBox;
            v1062 = v1060->m_Items[gEvnRngNum]->facenml;
            sub_854930(&v1062->m_Items[3], 2u);
            v1065 = gEvnRngBox;
            v1066 = v1065->max_length;
            v1088 = v1065->m_Items[gEvnRngNum]->facenum;
            v1090 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
            v1093 = MATH_DotProduct(v1090->m_Items[3], v896->m_Items[2]);
            pBasic = v1630;
            v1088->m_Items[3] = v1093;
            v1095 = gEvnRngBox;
            v1097 = v1095->m_Items[gEvnRngNum]->facenml;
            v1100 = MATH_DotProduct(v1650, v1097->m_Items[3]);
            v1101 = gEvnRngBox;
            v1103 = v1101->m_Items[gEvnRngNum]->facenum;
            if ((v1100 - v1103->m_Items[3]) < 0.0)
            {
              v1143 = gEvnRngBox;
              v1145 = v1143->m_Items[gEvnRngNum]->facenml;
              sub_854930(&v1145->m_Items[3], 0);
              v1148 = gEvnRngBox;
              v1150 = v1148->m_Items[gEvnRngNum]->facenml;
              sub_854930(&v1150->m_Items[3], 1u);
              v1153 = gEvnRngBox;
              v1155 = v1153->m_Items[gEvnRngNum]->facenml;
              sub_854930(&v1155->m_Items[3], 2u);
              v1159 = gEvnRngBox;
              v1160 = v1159->max_length;
              v1284 = v1159->m_Items[gEvnRngNum]->facenum;
              v1286 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
              v1288 = v1286->m_Items[3].x;
              v1289 = v1286->m_Items[3].y;
              v1290 = v1286->m_Items[3].z;
              v1291 = v1286->m_Items[3].w;
              v1293 = v896->m_Items[2].x;
              v1294 = v896->m_Items[2].y;
              v1295 = v896->m_Items[2].z;
              v1296 = v896->m_Items[2].w;
              pBasic = v1630;
              v1664.x = v1288;
              v1664.y = v1289;
              v1664.z = v1290;
              v1664.w = v1291;
              v1678.x = v1293;
              v1678.y = v1294;
              v1678.z = v1295;
              v1678.w = v1296;
              v1297 = MATH_DotProduct(v1664, v1678);
              v29 = v1642;
              v30 = v1634;
              v1284->m_Items[3] = v1297;
              v1104 = ca;
              if (*v326)
              {
LABEL_1343:
                sub_854930(v1637, 0);
                sub_854710(v1625, 1u);
                sub_854930(v1637, 1u);
                sub_854710(v1625, 2u);
                sub_854930(v1637, 2u);
                v5 = 0.0;
                sub_854930(v333, 0);
                sub_854710(v1627, 1u);
                sub_854930(v333, 1u);
                sub_854710(v1627, 2u);
                sub_854930(v333, 2u);
                sub_854930(v339, 0);
                sub_854710(v333, 1u);
                sub_854930(v339, 1u);
                sub_854710(v333, 2u);
                sub_854930(v339, 2u);
                v1120 = *v108;
                CalcABCD(v896, v1645, ba, v1104, d);
                v1124 = gEvnRngBox;
                v1126 = v1124->m_Items[gEvnRngNum]->facenml;
                sub_854930(&v1126->m_Items[4], 0);
                v1129 = gEvnRngBox;
                v1131 = v1129->m_Items[gEvnRngNum]->facenml;
                sub_854930(&v1131->m_Items[4], 1u);
                v1134 = gEvnRngBox;
                v1136 = v1134->m_Items[gEvnRngNum]->facenml;
                sub_854930(&v1136->m_Items[4], 2u);
                v1139 = gEvnRngBox;
                v1140 = v1139->max_length;
                v1162 = v1139->m_Items[gEvnRngNum]->facenum;
                v1164 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
                v1167 = MATH_DotProduct(v1164->m_Items[4], v896->m_Items[0]);
                v1162->m_Items[4] = v1167;
                v1169 = gEvnRngBox;
                v1171 = v1169->m_Items[gEvnRngNum]->facenml;
                v1173 = MATH_DotProduct(v1650, v1171->m_Items[4]);
                v1174 = gEvnRngBox;
                v1176 = v1174->m_Items[gEvnRngNum]->facenum;
                if ((v1173 - v1176->m_Items[4]) >= 0.0)
                {
LABEL_1933:
                    goto LABEL_1936;
                  goto LABEL_1934;
                }
                v1179 = gEvnRngBox;
                v1181 = v1179->m_Items[gEvnRngNum]->facenml;
                sub_854930(&v1181->m_Items[4], 0);
                v1184 = gEvnRngBox;
                v1186 = v1184->m_Items[gEvnRngNum]->facenml;
                sub_854930(&v1186->m_Items[4], 1u);
                v1189 = gEvnRngBox;
                v1191 = v1189->m_Items[gEvnRngNum]->facenml;
                sub_854930(&v1191->m_Items[4], 2u);
                v1195 = gEvnRngBox;
                v1196 = v1195->max_length;
                v1301 = v1195->m_Items[gEvnRngNum]->facenum;
                v1303 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
                v1305 = v1303->m_Items[4].x;
                v1306 = v1303->m_Items[4].y;
                v1307 = v1303->m_Items[4].z;
                v1308 = v1303->m_Items[4].w;
                v1310 = v896->m_Items[0].x;
                v1311 = v896->m_Items[0].y;
                v1312 = v896->m_Items[0].z;
                v1313 = v896->m_Items[0].w;
                {
LABEL_1930:
                  v1668.x = v1305;
                  v1668.y = v1306;
                  v1668.z = v1307;
                  v1668.w = v1308;
                  v1682.x = v1310;
                  v1682.y = v1311;
                  v1682.z = v1312;
                  v1682.w = v1313;
                  v1602 = MATH_DotProduct(v1668, v1682);
                  v1301->m_Items[4] = v1602;
                  v29 = v1642;
                  v30 = v1634;
                  v5 = 0.0;
                  goto LABEL_1933;
                }
LABEL_1570:
                goto LABEL_1930;
              }
            }
            else
            {
              v1104 = ca;
              if (*v326)
                goto LABEL_1343;
            }
          }
        }
        else
        {
          v1030 = ca;
          if (*v326)
            goto LABEL_1242;
        }
      }
    }
    else if (*v326)
    {
      goto LABEL_1062;
    }
  }
  if (v308 <= v301 || v308 <= v313)
  {
    v944 = gEvnRngBox;
    v944->m_Items[gEvnRngNum]->mode2D = 2;
    bb = b + 9;
    sub_854710((v8 + 4), 0);
    v948 = (v8 + 6);
    sub_854710((v8 + 6), 0);
    v1624 = (v8 + 8);
    sub_854710((v8 + 8), 0);
    v1626 = (v8 + 10);
    sub_854710((v8 + 10), 0);
    sub_854930(&v1650, 0);
    sub_854710((v8 + 4), 1u);
    sub_854710((v8 + 6), 1u);
    sub_854710(v1624, 1u);
    v1631 = pBasic;
    sub_854710(v1626, 1u);
    sub_854930(&v1650, 1u);
    sub_854930(&v1650, 2u);
    sub_854710((v8 + 4), 0);
    v956 = a + 6;
    v1638 = (a + 8);
    sub_854930((a + 8), 0);
    sub_854710((v8 + 4), 1u);
    sub_854930(v1638, 1u);
    sub_854930(v1638, 2u);
    sub_854710((v8 + 6), 0);
    v963 = (a + 12);
    sub_854930((a + 12), 0);
    sub_854710((v8 + 6), 1u);
    sub_854930((a + 12), 1u);
    sub_854930((a + 12), 2u);
    sub_854710((a + 12), 0);
    v969 = (a + 16);
    sub_854930((a + 16), 0);
    sub_854710((a + 12), 1u);
    sub_854930((a + 16), 1u);
    sub_854930((a + 16), 2u);
    v974 = *v108;
    v1628 = v285;
    CalcABCD(a, v1645, bb, ca, d);
    v976 = gEvnRngBox;
    v978 = v976->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v978->m_Items[1], 0);
    v981 = gEvnRngBox;
    v983 = v981->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v983->m_Items[1], 1u);
    v986 = gEvnRngBox;
    v988 = v986->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v988->m_Items[1], 2u);
    v991 = gEvnRngBox;
    v992 = v991->max_length;
    v1210 = v991->m_Items[gEvnRngNum]->facenum;
    v1212 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
    v1215 = MATH_DotProduct(v1212->m_Items[1], *(a + 8), 0);
    v1210->m_Items[1] = v1215;
    v1217 = gEvnRngBox;
    v1219 = v1217->m_Items[gEvnRngNum]->facenml;
    v1222 = MATH_DotProduct(v1650, v1219->m_Items[1]);
    v1223 = gEvnRngBox;
    v1224 = v1222;
    v1226 = v1223->m_Items[gEvnRngNum]->facenum;
    v1228 = v1226->m_Items[1];
    v1229 = (a + 8);
    if ((v1224 - v1228) < 0.0)
    {
      v1231 = gEvnRngBox;
      v1233 = v1231->m_Items[gEvnRngNum]->facenml;
      sub_854930(&v1233->m_Items[1], 0);
      v1236 = gEvnRngBox;
      v1238 = v1236->m_Items[gEvnRngNum]->facenml;
      sub_854930(&v1238->m_Items[1], 1u);
      v1241 = gEvnRngBox;
      v1243 = v1241->m_Items[gEvnRngNum]->facenml;
      sub_854930(&v1243->m_Items[1], 2u);
      v1247 = gEvnRngBox;
      v1248 = v1247->max_length;
      v1319 = v1247->m_Items[gEvnRngNum]->facenum;
      v1321 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
      v1323 = v1321->m_Items[1].x;
      v1324 = v1321->m_Items[1].y;
      v1325 = v1321->m_Items[1].z;
      v1326 = v1321->m_Items[1].w;
      v1328 = a[8];
      v1329 = a[9];
      v1330 = a[10];
      v1331 = a[11];
      v1229 = (a + 8);
      v1665.x = v1323;
      v1665.y = v1324;
      v1665.z = v1325;
      v1665.w = v1326;
      v1679.x = v1328;
      v1679.y = v1329;
      v1679.z = v1330;
      v1679.w = v1331;
      v1332 = MATH_DotProduct(v1665, v1679);
      v29 = v1642;
      v30 = v1634;
      v1319->m_Items[1] = v1332;
    }
    sub_854710(v948, 0);
    sub_854930(v1229, 0);
    sub_854710(v948, 1u);
    sub_854930(v1229, 1u);
    v1338 = ca;
    sub_854930(v1229, 2u);
    sub_854710(v1624, 0);
    sub_854930(v963, 0);
    sub_854710(v1624, 1u);
    sub_854930(v963, 1u);
    sub_854930(v963, 2u);
    sub_854710(v963, 0);
    sub_854930(v969, 0);
    sub_854710(v963, 1u);
    sub_854930(v969, 1u);
    sub_854930(v969, 2u);
    v1351 = *v108;
    CalcABCD(a, v1645, bb, ca, d);
    v1355 = gEvnRngBox;
    v1357 = v1355->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v1357->m_Items[2], 0);
    v1360 = gEvnRngBox;
    v1362 = v1360->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v1362->m_Items[2], 1u);
    v1365 = gEvnRngBox;
    v1367 = v1365->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v1367->m_Items[2], 2u);
    v1370 = gEvnRngBox;
    v1372 = v1370->m_Items[gEvnRngNum]->facenum;
    v1373 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
    v1376 = MATH_DotProduct(v1373->m_Items[2], *(a + 12), 0);
    v1372->m_Items[2] = v1376;
    v1378 = gEvnRngBox;
    v1380 = v1378->m_Items[gEvnRngNum]->facenml;
    v1383 = MATH_DotProduct(v1650, v1380->m_Items[2]);
    v1384 = gEvnRngBox;
    v1385 = v1383;
    v1387 = v1384->m_Items[gEvnRngNum]->facenum;
    v1389 = v1387->m_Items[2];
    v1390 = (a + 8);
    if ((v1385 - v1389) < 0.0)
    {
      v1392 = gEvnRngBox;
      v1394 = v1392->m_Items[gEvnRngNum]->facenml;
      sub_854930(&v1394->m_Items[2], 0);
      v1397 = gEvnRngBox;
      v1399 = v1397->m_Items[gEvnRngNum]->facenml;
      sub_854930(&v1399->m_Items[2], 1u);
      v1402 = gEvnRngBox;
      v1404 = v1402->m_Items[gEvnRngNum]->facenml;
      sub_854930(&v1404->m_Items[2], 2u);
      v1408 = gEvnRngBox;
      v1409 = v1408->max_length;
      v1414 = v1408->m_Items[gEvnRngNum]->facenum;
      v1416 = v1408->m_Items[gEvnRngNum]->facenml;
      v1418 = v1416[16];
      v1419 = v1416[17];
      v1420 = v1416[18];
      v1421 = v1416[19];
      v1423 = a[12];
      v1424 = a[13];
      v1425 = a[14];
      v1426 = a[15];
      v1390 = (a + 8);
      v1666.x = v1418;
      v1666.y = v1419;
      v1666.z = v1420;
      v1666.w = v1421;
      v1680.x = v1423;
      v1680.y = v1424;
      v1680.z = v1425;
      v1680.w = v1426;
      v1427 = MATH_DotProduct(v1666, v1680);
      v29 = v1642;
      v30 = v1634;
      v1414->m_Items[2] = v1427;
      v1338 = ca;
    }
    sub_854710(v1624, 0);
    sub_854930(v1390, 0);
    sub_854710(v1624, 1u);
    sub_854930(v1390, 1u);
    sub_854930(v1390, 2u);
    sub_854710(v1626, 0);
    sub_854930(v963, 0);
    sub_854710(v1626, 1u);
    sub_854930(v963, 1u);
    sub_854930(v963, 2u);
    sub_854710(v963, 0);
    sub_854930(v969, 0);
    sub_854710(v963, 1u);
    sub_854930(v969, 1u);
    sub_854930(v969, 2u);
    v1445 = *v108;
    CalcABCD(a, v1645, bb, v1338, d);
    v1449 = gEvnRngBox;
    v1451 = v1449->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v1451->m_Items[3], 0);
    v1454 = gEvnRngBox;
    v1456 = v1454->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v1456->m_Items[3], 1u);
    v1459 = gEvnRngBox;
    v1461 = v1459->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v1461->m_Items[3], 2u);
    v1464 = gEvnRngBox;
    v1466 = v1464->m_Items[gEvnRngNum]->facenum;
    v1467 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
    v1470 = MATH_DotProduct(v1467->m_Items[3], *(a + 16), 0);
    v1466->m_Items[3] = v1470;
    v1472 = gEvnRngBox;
    v1474 = v1472->m_Items[gEvnRngNum]->facenml;
    v1475 = v1628;
    v1478 = MATH_DotProduct(v1650, v1474->m_Items[3]);
    v1479 = gEvnRngBox;
    v1480 = v1478;
    v1482 = v1479->m_Items[gEvnRngNum]->facenum;
    v1484 = v1482->m_Items[3];
    v1485 = (a + 8);
    if ((v1480 - v1484) < 0.0)
    {
      v1487 = gEvnRngBox;
      v1489 = v1487->m_Items[gEvnRngNum]->facenml;
      sub_854930(&v1489->m_Items[3], 0);
      v1492 = gEvnRngBox;
      v1494 = v1492->m_Items[gEvnRngNum]->facenml;
      sub_854930(&v1494->m_Items[3], 1u);
      v1497 = gEvnRngBox;
      v1499 = v1497->m_Items[gEvnRngNum]->facenml;
      sub_854930(&v1499->m_Items[3], 2u);
      v1503 = gEvnRngBox;
      v1504 = v1503->max_length;
      v1509 = v1503->m_Items[gEvnRngNum]->facenum;
      v1511 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
      v1513 = v1511->m_Items[3].x;
      v1514 = v1511->m_Items[3].y;
      v1515 = v1511->m_Items[3].z;
      v1516 = v1511->m_Items[3].w;
      v1518 = a[16];
      v1519 = a[17];
      v1520 = a[18];
      v1521 = a[19];
      v1485 = (a + 8);
      v1667.x = v1513;
      v1667.y = v1514;
      v1667.z = v1515;
      v1667.w = v1516;
      v1681.x = v1518;
      v1681.y = v1519;
      v1681.z = v1520;
      v1681.w = v1521;
      v1522 = MATH_DotProduct(v1667, v1681);
      v29 = v1642;
      v30 = v1634;
      v1509->m_Items[3] = v1522;
      v1475 = v1628;
    }
    sub_854710(v1626, 0);
    sub_854930(v1485, 0);
    sub_854710(v1626, 1u);
    sub_854930(v1485, 1u);
    sub_854930(v1485, 2u);
    sub_854710(v1475, 0);
    sub_854930(v963, 0);
    sub_854710(v1475, 1u);
    sub_854930(v963, 1u);
    v5 = 0.0;
    sub_854930(v963, 2u);
    sub_854710(v963, 0);
    sub_854930(v969, 0);
    sub_854710(v963, 1u);
    sub_854930(v969, 1u);
    sub_854930(v969, 2u);
    v1540 = *v108;
    CalcABCD(a, v1645, bb, v1338, d);
    v1544 = gEvnRngBox;
    v1546 = v1544->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v1546->m_Items[4], 0);
    v1549 = gEvnRngBox;
    v1551 = v1549->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v1551->m_Items[4], 1u);
    v1554 = gEvnRngBox;
    v1556 = v1554->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v1556->m_Items[4], 2u);
    v1559 = gEvnRngBox;
    v1561 = v1559->m_Items[gEvnRngNum]->facenum;
    v1562 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
    v1565 = MATH_DotProduct(v1562->m_Items[4], *(a + 8), 0);
    v1561->m_Items[4] = v1565;
    v1567 = gEvnRngBox;
    v1569 = v1567->m_Items[gEvnRngNum]->facenml;
    v1571 = MATH_DotProduct(v1650, v1569->m_Items[4]);
    v1572 = gEvnRngBox;
    v1574 = v1572->m_Items[gEvnRngNum]->facenum;
    if ((v1571 - v1574->m_Items[4]) >= 0.0)
    {
      pBasic = v1631;
        goto LABEL_1936;
      goto LABEL_1934;
    }
    v1577 = gEvnRngBox;
    v1579 = v1577->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v1579->m_Items[4], 0);
    v1582 = gEvnRngBox;
    v1584 = v1582->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v1584->m_Items[4], 1u);
    v1587 = gEvnRngBox;
    v1589 = v1587->m_Items[gEvnRngNum]->facenml;
    sub_854930(&v1589->m_Items[4], 2u);
    v1592 = gEvnRngBox;
    v1593 = v1592->max_length;
    v1301 = v1592->m_Items[gEvnRngNum]->facenum;
    v1599 = gEvnRngBox->m_Items[gEvnRngNum]->facenml;
    v1305 = v1599->m_Items[4].x;
    v1306 = v1599->m_Items[4].y;
    v1307 = v1599->m_Items[4].z;
    v1308 = v1599->m_Items[4].w;
    v1310 = a[8];
    v1311 = a[9];
    v1312 = a[10];
    v1313 = a[11];
    pBasic = v1631;
      goto LABEL_1930;
    goto LABEL_1570;
  }
  v458 = gEvnRngBox;
  v458->m_Items[gEvnRngNum]->mode2D = 1;
    goto LABEL_1934;
LABEL_1936:
  v1604 = gEvnRngBox;
  v1604->m_Items[gEvnRngNum]->put_serialID = pBasic->serialID;
  v1606 = gEvnRngBox;
  v1606->m_Items[gEvnRngNum]->sizex = v30;
  v1608 = gEvnRngBox;
  v1608->m_Items[gEvnRngNum]->sizey = v29;
  v1610 = gEvnRngBox;
  v1610->m_Items[gEvnRngNum]->sizez = v5;
  v1612 = gEvnRngBox;
  v1612->m_Items[gEvnRngNum]->anim_cntf = gEvnRngNum * 1.3;
  v1614 = gEvnRngBox;
  v1614->m_Items[gEvnRngNum]->TakaraIdx = -1;
  v1616 = gEvnRngBox;
  v1616->m_Items[gEvnRngNum]->npcHoji = -1;
  v1618 = gEvnRngBox;
  v1618->m_Items[gEvnRngNum]->npcHit = 0;
  v1620 = gEvnRngBox;
  v1620->m_Items[gEvnRngNum]->npcIdx = -1;
  return gEvnRngNum++;
}

// 0x104c6d0
void fldEveHit_AddEveHitItemBox(s32 idx, f32 x, f32 y, f32 z, f32 r) {
  s16 v7;
  s64 gProgramEveHitNum;
  u32 v10;
  dds3Basic_t_o *v11;
  struct fldProgramEveHit_tag_array *gProgramEveHit;
  struct fldProgramEveHit_tag_array *v16;
  s32 v18;
  struct fldProgramEveHit_tag_array *v20;
  struct fldProgramEveHit_tag_array *v22;
  struct fldProgramEveHit_tag_array *v24;
  struct fldProgramEveHit_tag_array *v26;
  struct fldProgramEveHit_tag_array *v28;
  struct fldProgramEveHit_tag_array *v30;
  struct fldProgramEveHit_tag_array *v32;
  struct fldProgramEveHit_tag_array *v34;
  struct fldProgramEveHit_tag_array *v36;
  struct fldProgramEveHit_tag_array *v38;
  struct fldProgramEveHit_tag_array *v40;
  struct fldProgramEveHit_tag_array *v42;
  struct fldProgramEveHit_tag_array *v44;
  struct fldProgramEveHit_tag_array *v46;
  struct fldProgramEveHit_tag_array *v48;
  struct fldProgramEveHit_tag_array *v50;
  struct fldProgramEveHit_tag_array *v52;
  struct fldProgramEveHit_tag_array *v54;
  struct fldProgramEveHit_tag_array *v56;
  struct fldProgramEveHit_tag_array *v58;
  struct fldProgramEveHit_tag_array *v60;
  struct fldResHead_t_o *ResHead;
  s64 v63;
  s64 v64;
  s64 v65;
  s64 v66;
  s64 v67;
  s64 v68;
  struct fldProgramEveHit_tag_array *v70;
  struct fldProgramEveHit_tag_array *v72;
  struct fldResHeadPos_t_o *sisei;
  struct fldProgramEveHit_tag_array *v75;
  u32 resourceID;
  dds3Basic_t_o *v78;
  struct fldProgramEveHit_tag_array *v80;
  s32 v82;
  struct putevebox_s_array *gEvnRngBox;
  struct putevebox_s_array *v86;
  struct putevebox_s_array *v88;
  fldResourcePoint_t_o v90;
  fldResourcePoint_t_o v91;

  v7 = idx;
  memset(&v91, 0, sizeof(v91));
  v10 = dds3SerializeID();
  dds3AddEventBasic(v10, "itembox_label", "program_eve");
  gProgramEveHit->m_Items[gProgramEveHitNum]->ResHeadData->resourceID = v10;
  v16 = gProgramEveHit;
  v18 = fldEveHit_AddEveData(v16->m_Items[gProgramEveHitNum]->ResHeadData, v11);
  v20 = gProgramEveHit;
  v20->m_Items[gProgramEveHitNum]->ball->Type = 0;
  v22 = gProgramEveHit;
  v22->m_Items[gProgramEveHitNum]->ball->r = r;
  v24 = gProgramEveHit;
  v24->m_Items[gProgramEveHitNum]->put->Type = 1;
  v26 = gProgramEveHit;
  v26->m_Items[gProgramEveHitNum]->put->EveIdx = v18;
  v28 = gProgramEveHit;
  v28->m_Items[gProgramEveHitNum]->put->Visible = 1;
  v30 = gProgramEveHit;
  v30->m_Items[gProgramEveHitNum]->put->pEveBall = gProgramEveHit->m_Items[gProgramEveHitNum]->ball;
  v32 = gProgramEveHit;
  v32->m_Items[gProgramEveHitNum]->ResHead->pPut = gProgramEveHit->m_Items[gProgramEveHitNum]->put;
  v34 = gProgramEveHit;
  v34->m_Items[gProgramEveHitNum]->ResHead->sisei = gProgramEveHit->m_Items[gProgramEveHitNum]->sisei;
  v36 = gProgramEveHit;
  sub_854930(&v36->m_Items[gProgramEveHitNum]->ResHead->sisei->fields, 0);
  v38 = gProgramEveHit;
  sub_854930(&v38->m_Items[gProgramEveHitNum]->ResHead->sisei->fields, 1u);
  v40 = gProgramEveHit;
  sub_854930(&v40->m_Items[gProgramEveHitNum]->ResHead->sisei->fields, 2u);
  v42 = gProgramEveHit;
  sub_854930(&v42->m_Items[gProgramEveHitNum]->ResHead->sisei->fields, 3u);
  v44 = gProgramEveHit;
  sub_854930(&v44->m_Items[gProgramEveHitNum]->ResHead->sisei->rot, 0);
  v46 = gProgramEveHit;
  sub_854930(&v46->m_Items[gProgramEveHitNum]->ResHead->sisei->rot, 1u);
  v48 = gProgramEveHit;
  sub_854930(&v48->m_Items[gProgramEveHitNum]->ResHead->sisei->rot, 2u);
  v50 = gProgramEveHit;
  sub_854930(&v50->m_Items[gProgramEveHitNum]->ResHead->sisei->rot, 3u);
  v52 = gProgramEveHit;
  sub_854930(&v52->m_Items[gProgramEveHitNum]->ResHead->sisei->scl, 0);
  v54 = gProgramEveHit;
  sub_854930(&v54->m_Items[gProgramEveHitNum]->ResHead->sisei->scl, 1u);
  v56 = gProgramEveHit;
  sub_854930(&v56->m_Items[gProgramEveHitNum]->ResHead->sisei->scl, 2u);
  v58 = gProgramEveHit;
  sub_854930(&v58->m_Items[gProgramEveHitNum]->ResHead->sisei->scl, 3u);
  v60 = gProgramEveHit;
  ResHead = v60->m_Items[gProgramEveHitNum]->ResHead;
  ResHead->resourceID = dds3SerializeID();
  v70 = gProgramEveHit;
  v70->m_Items[gProgramEveHitNum]->ResHead->resourceName = "program_eve";
  memset(&v91, 0, sizeof(v91));
  v72 = gProgramEveHit;
  sisei = v72->m_Items[gProgramEveHitNum]->ResHead->sisei;
  sub_F86A30(&v91, sisei->pos.x, sisei->pos.y, sisei->pos.z, sisei->pos.w, sisei->rot.x, sisei->rot.y, sisei->rot.z, sisei->rot.w, 0, v63, v64, v65, v66, v67, v68, *&sisei->scl.x, *&sisei->scl.z);
  v75 = gProgramEveHit;
  resourceID = v75->m_Items[gProgramEveHitNum]->ResHead->resourceID;
  v90 = v91;
  v78 = dds3AddPointBasic(resourceID, &v90, "program_hit");
  v80 = gProgramEveHit;
  v82 = fldEveHit_AddEveHit(v80->m_Items[gProgramEveHitNum]->ResHead, v78);
  gEvnRngBox->m_Items[v82]->TakaraIdx = v7;
  v86 = gEvnRngBox;
  v86->m_Items[v82]->npcHit = 2;
  v88 = gEvnRngBox;
  v88->m_Items[v82]->npcIdx = -1;
  ++gProgramEveHitNum;
}

// 0x104d150
void fldEveHit_AddEveHitNpc(char **resname, s32 eveidx, f32 x, f32 y, f32 z, f32 r, s32 hojiID, s32 npcidx) {
  s16 v10;
  s16 v11;
  struct fldProgramEveHit_tag_array *gProgramEveHit;
  s64 gProgramEveHitNum;
  struct fldProgramEveHit_tag_array *v19;
  struct fldProgramEveHit_tag_array *v21;
  struct fldProgramEveHit_tag_array *v23;
  struct fldProgramEveHit_tag_array *v25;
  struct fldProgramEveHit_tag_array *v27;
  struct fldProgramEveHit_tag_array *v29;
  struct fldProgramEveHit_tag_array *v31;
  struct fldProgramEveHit_tag_array *v33;
  struct fldProgramEveHit_tag_array *v35;
  struct fldProgramEveHit_tag_array *v37;
  struct fldProgramEveHit_tag_array *v39;
  struct fldProgramEveHit_tag_array *v41;
  struct fldProgramEveHit_tag_array *v43;
  struct fldProgramEveHit_tag_array *v45;
  struct fldProgramEveHit_tag_array *v47;
  struct fldProgramEveHit_tag_array *v49;
  struct fldProgramEveHit_tag_array *v51;
  struct fldProgramEveHit_tag_array *v53;
  struct fldProgramEveHit_tag_array *v55;
  struct fldProgramEveHit_tag_array *v58;
  struct fldResHead_t_o *ResHead;
  s64 v61;
  s64 v62;
  s64 v63;
  s64 v64;
  s64 v65;
  s64 v66;
  struct fldProgramEveHit_tag_array *v68;
  struct fldProgramEveHit_tag_array *v70;
  struct fldResHeadPos_t_o *sisei;
  struct fldProgramEveHit_tag_array *v73;
  u32 resourceID;
  dds3Basic_t_o *v76;
  struct fldProgramEveHit_tag_array *v78;
  s32 v80;
  struct putevebox_s_array *gEvnRngBox;
  struct putevebox_s_array *v84;
  struct putevebox_s_array *v86;
  fldResourcePoint_t_o v88;
  fldResourcePoint_t_o v89;

  v10 = npcidx;
  v11 = hojiID;
  memset(&v89, 0, sizeof(v89));
  gProgramEveHit->m_Items[gProgramEveHitNum]->ball->Type = 0;
  v19 = gProgramEveHit;
  v19->m_Items[gProgramEveHitNum]->ball->r = r;
  v21 = gProgramEveHit;
  v21->m_Items[gProgramEveHitNum]->put->Type = 1;
  v23 = gProgramEveHit;
  v23->m_Items[gProgramEveHitNum]->put->EveIdx = eveidx;
  v25 = gProgramEveHit;
  v25->m_Items[gProgramEveHitNum]->put->Visible = 1;
  v27 = gProgramEveHit;
  v27->m_Items[gProgramEveHitNum]->put->pEveBall = gProgramEveHit->m_Items[gProgramEveHitNum]->ball;
  v29 = gProgramEveHit;
  v29->m_Items[gProgramEveHitNum]->ResHead->pPut = gProgramEveHit->m_Items[gProgramEveHitNum]->put;
  v31 = gProgramEveHit;
  v31->m_Items[gProgramEveHitNum]->ResHead->sisei = gProgramEveHit->m_Items[gProgramEveHitNum]->sisei;
  v33 = gProgramEveHit;
  sub_854930(&v33->m_Items[gProgramEveHitNum]->ResHead->sisei->fields, 0);
  v35 = gProgramEveHit;
  sub_854930(&v35->m_Items[gProgramEveHitNum]->ResHead->sisei->fields, 1u);
  v37 = gProgramEveHit;
  sub_854930(&v37->m_Items[gProgramEveHitNum]->ResHead->sisei->fields, 2u);
  v39 = gProgramEveHit;
  sub_854930(&v39->m_Items[gProgramEveHitNum]->ResHead->sisei->fields, 3u);
  v41 = gProgramEveHit;
  sub_854930(&v41->m_Items[gProgramEveHitNum]->ResHead->sisei->rot, 0);
  v43 = gProgramEveHit;
  sub_854930(&v43->m_Items[gProgramEveHitNum]->ResHead->sisei->rot, 1u);
  v45 = gProgramEveHit;
  sub_854930(&v45->m_Items[gProgramEveHitNum]->ResHead->sisei->rot, 2u);
  v47 = gProgramEveHit;
  sub_854930(&v47->m_Items[gProgramEveHitNum]->ResHead->sisei->rot, 3u);
  v49 = gProgramEveHit;
  sub_854930(&v49->m_Items[gProgramEveHitNum]->ResHead->sisei->scl, 0);
  v51 = gProgramEveHit;
  sub_854930(&v51->m_Items[gProgramEveHitNum]->ResHead->sisei->scl, 1u);
  v53 = gProgramEveHit;
  sub_854930(&v53->m_Items[gProgramEveHitNum]->ResHead->sisei->scl, 2u);
  v55 = gProgramEveHit;
  sub_854930(&v55->m_Items[gProgramEveHitNum]->ResHead->sisei->scl, 3u);
  v58 = gProgramEveHit;
  ResHead = v58->m_Items[gProgramEveHitNum]->ResHead;
  ResHead->resourceID = dds3SerializeID();
  v68 = gProgramEveHit;
  v68->m_Items[gProgramEveHitNum]->ResHead->resourceName = *resname;
  memset(&v89, 0, sizeof(v89));
  v70 = gProgramEveHit;
  sisei = v70->m_Items[gProgramEveHitNum]->ResHead->sisei;
  sub_F86A30(&v89, sisei->pos.x, sisei->pos.y, sisei->pos.z, sisei->pos.w, sisei->rot.x, sisei->rot.y, sisei->rot.z, sisei->rot.w, 0, v61, v62, v63, v64, v65, v66, *&sisei->scl.x, *&sisei->scl.z);
  v73 = gProgramEveHit;
  resourceID = v73->m_Items[gProgramEveHitNum]->ResHead->resourceID;
  v88 = v89;
  v76 = dds3AddPointBasic(resourceID, &v88, "program_hit");
  v78 = gProgramEveHit;
  v80 = fldEveHit_AddEveHit(v78->m_Items[gProgramEveHitNum]->ResHead, v76);
  gEvnRngBox->m_Items[v80]->npcHoji = v11;
  v84 = gEvnRngBox;
  v84->m_Items[v80]->npcHit = 1;
  v86 = gEvnRngBox;
  v86->m_Items[v80]->npcIdx = v10;
  ++gProgramEveHitNum;
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
  u64 v6;
  struct putevebox_s_array *gEvnRngBox;
  struct fldResHead_t_array *gEvnRng;
  System_Byte_array *pDate;
  s32 v15;
  fldResPut_t_o *pPut;
  fldResPut_t_o *v17;
  struct fldResHead_t_array *v18;
  u32 v20;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  struct putevebox_s_array *v27;
  f32 *v29;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  struct putevebox_s_array *v36;
  Il2CppObject *workdata;
  Il2CppClass *element_class;
  char *v40;
  s64 *v41;
  s64 *v42;
  s64 v43;
  s64 v44;
  s64 v45;
  s64 v46;
  f32 v47;
  f32 v49;
  UnityEngine_Vector4_o v50;
  s64 v51;
  s64 v52;
  s64 v53;
  s64 v54;
  s64 v55;
  s64 v56;
  UnityEngine_Vector4_o p;
  u64 v58[3];
  UnityEngine_Vector4_o v59;
  UnityEngine_Vector4_o v60;

  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  *&v50.x = 0;
  *&v50.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  sub_854690(&v50.x, 0.0, 0.0, 0.0, 1.0);
  v6 = 0;
  {
LABEL_6:
    goto LABEL_8;
  }
  while (1)
  {
LABEL_8:
    if (v6 >= gEvnRngNum)
      return 0;
    else
    {
      if (v6 >= LODWORD(gEvnRngBox->max_length))
        goto LABEL_12;
    }
    if (gEvnRngBox->m_Items[v6]->put_serialID != put->serialID)
      goto LABEL_5;
    pDate = gEvnRng->m_Items[v6]->pDate;
    v15 = gEvnRng->m_Items[v6]->_union;
    pPut = gEvnRng->m_Items[v6]->pPut;
    v17 = SetfldResPut(pDate, v15, pPut);
    v18 = gEvnRng;
    v20 = SetfldEveType(v18->m_Items[v6]->pDate, v17->_union, gEvnRng->m_Items[v6]->pPut);
    if (v20 == 2)
      break;
    if (v20 == 1)
    {
      v36 = gEvnRngBox;
      return v36->m_Items[v6]->facehit == 1;
    }
    if (!v20)
    {
      workdata = put->workdata;
      if (!workdata)
        sub_8C38A0();
      element_class = workdata->klass->_1.element_class;
      {
        sub_8FC2C0(element_class, fldResourcePoint_t, v58);
        if ((v58[0] & 1) != 0)
          v40 = v58[2];
        else
          v40 = v58 + 1;
        v41 = sub_8C4940(v40);
      }
      v42 = sub_8D3F90(workdata);
      v43 = v42[1];
      v51 = *v42;
      v52 = v43;
      v44 = v42[2];
      v45 = v42[3];
      v46 = v42[5];
      v55 = v42[4];
      v56 = v46;
      v53 = v44;
      v54 = v45;
      sub_854710(&v51, 0);
      sub_854930(&v50, 0);
      sub_854710(&v51, 1u);
      sub_854930(&v50, 1u);
      sub_854710(&v51, 2u);
      sub_854930(&v50, 2u);
      SDF_VU0__LOADVECTOR(unit->poseset->rot);
      ToMatrix();
      SDF_VU0__STORE_ROW2(&p);
      sub_854930(&p, 1u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__NORMALIZE();
      SDF_VU0__SCALEVECTOR(-1.0);
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(v50);
      SDF_VU0__LOADVECTOR_B(unit->poseset->pos);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__STOREVECTOR(&p);
      sub_854930(&p, 1u);
      SDF_VU0__LOADVECTOR(p);
      v47 = SDF_VU0__GETLENGTH();
      SDF_VU0__NORMALIZE();
      SDF_VU0__COPYVECTOR_C_TO_B();
      v49 = SDF_VU0__INNERPRODUCT();
      if (OOYDEG(v49) >= 0.0)
        return v47 <= 200.0;
      return 0;
    }
LABEL_5:
    ++v6;
      goto LABEL_6;
  }
  SDF_VU0__LOADVECTOR(unit->poseset->rot);
  ToMatrix();
  SDF_VU0__STORE_ROW2(&p);
  sub_854930(&p, 1u);
  SDF_VU0__LOADVECTOR(p);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&p);
  x = p.x;
  y = p.y;
  z = p.z;
  w = p.w;
  v27 = gEvnRngBox;
  v29 = v27->m_Items[v6];
  v30 = v29[6];
  v31 = v29[7];
  v33 = v29[8];
  v32 = v29[9];
  v59.x = x;
  v59.y = y;
  v59.z = z;
  v59.w = w;
  v60.x = v30;
  v60.y = v31;
  v60.z = v33;
  v60.w = v32;
  return MATH_DotProduct(v59, v60) >= 0.01;
}

// 0x102ea50
s32 fldEveHit_ChkDir2(dds3Basic_t *unit, dds3Basic_t *put) {
  u64 v6;
  struct putevebox_s_array *gEvnRngBox;
  struct fldResHead_t_array *gEvnRng;
  System_Byte_array *pDate;
  s32 v15;
  fldResPut_t_o *pPut;
  fldResPut_t_o *v17;
  struct fldResHead_t_array *v18;
  u32 v20;
  struct putevebox_s_array *v23;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  struct putevebox_s_array *v31;
  f32 *v33;
  f32 v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  Il2CppObject *workdata;
  Il2CppClass *element_class;
  f32 v42;
  char *v43;
  s64 *v44;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  u64 v47[3];
  UnityEngine_Vector4_o v48;
  UnityEngine_Vector4_o v49;
  UnityEngine_Vector4_o v50;

  *&dst.x = 0;
  *&dst.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  sub_854690(&dst.x, 0.0, 0.0, 0.0, 1.0);
  v6 = 0;
  {
LABEL_6:
    goto LABEL_8;
  }
  while (1)
  {
LABEL_8:
    if (v6 >= gEvnRngNum)
      return 0;
    else
    {
      if (v6 >= LODWORD(gEvnRngBox->max_length))
        goto LABEL_12;
    }
    if (gEvnRngBox->m_Items[v6]->put_serialID != put->serialID)
      goto LABEL_5;
    pDate = gEvnRng->m_Items[v6]->pDate;
    v15 = gEvnRng->m_Items[v6]->_union;
    pPut = gEvnRng->m_Items[v6]->pPut;
    v17 = SetfldResPut(pDate, v15, pPut);
    v18 = gEvnRng;
    v20 = SetfldEveType(v18->m_Items[v6]->pDate, v17->_union, gEvnRng->m_Items[v6]->pPut);
    if (v20 == 2)
    {
      SDF_VU0__LOADVECTOR(unit->poseset->rot);
      ToMatrix();
      SDF_VU0__STORE_ROW2(&p);
      sub_854930(&p, 1u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__NORMALIZE();
      SDF_VU0__STOREVECTOR(&p);
      x = p.x;
      y = p.y;
      z = p.z;
      w = p.w;
      v31 = gEvnRngBox;
      v33 = v31->m_Items[v6];
      v34 = v33[6];
      v35 = v33[7];
      v37 = v33[8];
      v36 = v33[9];
      v48.x = x;
      v48.y = y;
      v48.z = z;
      v48.w = w;
      v50.x = v34;
      v50.y = v35;
      v50.z = v37;
      v50.w = v36;
      v38 = MATH_DotProduct(v48, v50);
      return v38 >= 0.0;
    }
    if (v20 == 1)
      break;
    if (!v20)
    {
      workdata = put->workdata;
      if (!workdata)
        sub_8C38A0();
      element_class = workdata->klass->_1.element_class;
      {
        sub_8FC2C0(element_class, fldResourcePoint_t, v47);
        if ((v47[0] & 1) != 0)
          v43 = v47[2];
        else
          v43 = v47 + 1;
        v44 = sub_8C4940(v43);
      }
      v49 = *sub_8D3F90(workdata);
      SDF_VU0__COPYVECTOR(&dst, v49);
      SDF_VU0__LOADVECTOR(unit->poseset->rot);
      ToMatrix();
      SDF_VU0__STORE_ROW2(&p);
      sub_854930(&p, 1u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__NORMALIZE();
      SDF_VU0__SCALEVECTOR(-1.0);
      SDF_VU0__COPYVECTOR_A_TO_C();
      SDF_VU0__LOADVECTOR(dst);
      SDF_VU0__LOADVECTOR_B(unit->poseset->pos);
      SDF_VU0__SUBVECTOR();
      SDF_VU0__STOREVECTOR(&p);
      sub_854930(&p, 1u);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__GETLENGTH();
      SDF_VU0__NORMALIZE();
      SDF_VU0__COPYVECTOR_C_TO_B();
      v42 = SDF_VU0__INNERPRODUCT();
      v38 = OOYDEG(v42);
      return v38 >= 0.0;
    }
LABEL_5:
    ++v6;
      goto LABEL_6;
  }
  v23 = gEvnRngBox;
  return v23->m_Items[v6]->facehit == 1;
}

// 0x10484a0
void fldEveHit_ChkEveHit(dds3Basic_t *pObjectBasic) {
  u64 *v2;
  u64 *v3;
  u64 *v4;
  System_Char_array *v5;
  s32 v12;
  u32 *v13;
  UnityEngine_Vector4_o *v14;
  UnityEngine_Vector4_o *v15;
  UnityEngine_Vector4_o *v16;
  struct putevebox_s_array *gEvnRngBox;
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  struct putevebox_s_array *v28;
  struct fldResHead_t_array *v31;
  struct fldResHead_t_array *v34;
  struct fldResHead_t_array *v37;
  System_Byte_array *pDate;
  s32 v40;
  fldResPut_t_o *pPut;
  fldResPut_t_o *v42;
  struct fldResHead_t_array *v43;
  fldResPut_t_o *v44;
  u32 v46;
  dds3PoseSet_t_o *v47;
  s64 p_pos;
  struct UnityEngine_Vector4_o *v49;
  struct UnityEngine_Vector4_o *v50;
  struct fldResHead_t_array *v53;
  u32 max_length;
  struct fldResHead_t_array *v56;
  struct fldResHead_t_array *v58;
  f32 v59;
  f32 v60;
  struct fldResHead_t_array *v62;
  f32 v63;
  f32 v64;
  f32 v68;
  f32 v69;
  struct putevebox_s_array *v70;
  struct UnityEngine_Vector4_array *v72;
  struct putevebox_s_array *v75;
  struct UnityEngine_Vector4_array *v77;
  struct putevebox_s_array *v82;
  struct UnityEngine_Vector4_array *v84;
  struct putevebox_s_array *v89;
  struct UnityEngine_Vector4_array *v91;
  struct putevebox_s_array *v96;
  s64 v100;
  struct fldResHead_t_array *v102;
  struct fldResHead_t_array *v104;
  struct fldResHead_t_array *v106;
  s64 v110;
  u64 v111;
  struct putevebox_s_array *v113;
  struct UnityEngine_Vector4_array *vtx;
  struct putevebox_s_array *v118;
  struct putevebox_s_array *v132;
  struct UnityEngine_Vector4_array *facenml;
  struct putevebox_s_array *v148;
  struct UnityEngine_Vector4_array *v150;
  struct putevebox_s_array *v164;
  struct UnityEngine_Vector4_array *v166;
  struct putevebox_s_array *v180;
  struct UnityEngine_Vector4_array *v182;
  struct putevebox_s_array *v196;
  struct UnityEngine_Vector4_array *v198;
  struct putevebox_s_array *v212;
  struct UnityEngine_Vector4_array *v214;
  s32 v218;
  struct fldResHead_t_array *v220;
  System_String_o **v222;
  struct fldResHead_t_array *v224;
  System_String_o **v226;
  u64 *v227;
  u64 *v228;
  f32 v232;
  f32 v234;
  f32 v236;
  System_String_o *v238;
  System_String_o *v241;
  struct putevebox_s_array *v250;
  struct UnityEngine_Vector4_array *v252;
  struct putevebox_s_array *v260;
  struct UnityEngine_Vector4_array *v262;
  struct putevebox_s_array *v270;
  struct UnityEngine_Vector4_array *v272;
  struct putevebox_s_array *v280;
  struct UnityEngine_Vector4_array *v282;
  s64 v286;
  struct putevebox_s_array *v287;
  s64 v288;
  f32 *v290;
  f32 v292;
  f32 v293;
  f32 v294;
  f32 v295;
  f32 v296;
  struct putevebox_s_array *v297;
  f32 v298;
  struct System_Single_array *facenum;
  f32 v302;
  struct putevebox_s_array *v303;
  struct UnityEngine_Vector4_array *v305;
  f32 v307;
  struct putevebox_s_array *v308;
  struct System_Single_array *v310;
  f32 v311;
  f32 v312;
  s32 v313;
  s32 v315;
  System_Byte_array *v316;
  fldResPut_t_o *v318;
  fldResPutEveBall_t_o *v319;
  dds3PoseSet_t_o *v320;
  s64 v321;
  struct fldResHead_t_array *v322;
  struct UnityEngine_Vector4_o *v324;
  struct fldResHead_t_array *v325;
  struct UnityEngine_Vector4_o *v327;
  struct fldResHead_t_array *v328;
  struct fldResHead_t_array *v335;
  System_String_o *v337;
  struct putevebox_s_array *v339;
  s32 TakaraIdx;
  System_Object_array *v342;
  System_Object_array *v343;
  s64 *v344;
  s64 *v346;
  s64 *v350;
  s64 *v351;
  s64 *v354;
  s64 *v355;
  s64 *v358;
  s64 *v359;
  s64 *v362;
  s64 *v363;
  s64 *v366;
  s64 *v367;
  System_String_o *v372;
  struct fldResHead_t_array *v374;
  System_String_o **v376;
  s64 v377;
  struct fldResHead_t_array *v379;
  u32 v381;
  dds3Basic_t_o *v382;
  Il2CppObject *v383;
  char *v385;
  s64 *v386;
  struct fldResHead_t_array *v388;
  System_String_o **v390;
  s32 v391;
  struct fldResHead_t_array *v394;
  System_String_o **v396;
  struct fldResHead_t_array *v398;
  System_String_o **v400;
  s64 EveIdx;
  struct fldResHead_t_array *gEve;
  u32 resourceID;
  dds3Basic_t_o *v406;
  Il2CppObject *Resource;
  char *v409;
  s64 *v410;
  struct dds3ProcessID_t_array *gEvnRngPid;
  s64 v415;
  s64 v416;
  s32 v417;
  s32 v419;
  struct putevebox_s_array *v421;
  struct fldResHead_t_array *v425;
  System_String_o *resourceName;
  struct fldResHead_t_array *v429;
  System_String_o **v431;
  struct putevebox_s_array *v432;
  s64 v434;
  struct fldResHead_t_array *v436;
  u32 v438;
  dds3Basic_t_o *v439;
  Il2CppObject *v440;
  System_String_o *v442;
  char *v443;
  s64 *v444;
  System_String_o *v446;
  s64 *started;
  struct dds3ProcessID_t_array *v449;
  s64 v450;
  s64 v454;
  struct putevebox_s_array *v455;
  fldEveHit_c *v457;
  u32 v458;
  s32 v460;
  s64 v461;
  struct fldResHead_t_array *v463;
  u32 v465;
  dds3Basic_t_o *v466;
  char *v467;
  s64 *v468;
  struct putevebox_s_array *v469;
  u32 v472;
  struct fldResHead_t_array *gEvnRng;
  u32 v500;
  s32 v501;
  s32 v502;
  s64 v503;
  UnityEngine_Vector4_o *dst;
  s64 v506;
  s64 v507;
  s64 v508;
  s32 klass_high;
  s32 klass;
  s32 handle_high;
  s32 handle_low;
  s32 v513;
  dds3Basic_t_o *scene;
  UnityEngine_Vector4_o v515;
  s64 v516;
  s64 v517;
  UnityEngine_Vector4_o v518;
  System_String_o *pScriptName;
  dds3Basic_t_o *pBasic;
  dds3PoseSet_t_o *p2;
  dds3PoseSet_t_o *p1;
  u32 v523;
  char v524[16];
  char *v525;
  UnityEngine_Vector4_o v526;
  UnityEngine_Vector4_o v527;
  UnityEngine_Vector4_o v528;

  v523 = 0;
  pScriptName = 0;
  pBasic = 0;
  *&v518.x = 0;
  *&v518.z = 0;
  v516 = 0;
  v517 = 0;
  scene = 0;
  *&v515.x = 0;
  *&v515.z = 0;
  v2 = Allocate(dds3PoseSet_t);
  dds3PoseSet_t___ctor(v2);
  p1 = v2;
  v3 = Allocate(dds3PoseSet_t);
  dds3PoseSet_t___ctor(v3);
  p2 = v3;
  sub_854690(&v518.x, 0.0, 0.0, 0.0, 1.0);
  v4 = NewSpecific(UnityEngine_Vector4, 8u);
  sub_854690(&v516, 0.0, 0.0, 0.0, 1.0);
  sub_854690(&v515.x, 0.0, 0.0, 0.0, 1.0);
  v5 = NewSpecific(char, 0x40u);
  CreateString_5280336(0, v5);
  else if (gEveOff)
  {
    return;
  }
  if (fldProcCheckFlag(0x40u))
  {
    fldEveHitProcess_Task();
    if (fldDbg->HitView == 1)
    {
      ooyTest_OT_Offset = 81;
    }
    dst = (v4 + 6);
    v508 = (v4 + 12);
    v507 = (v4 + 14);
    v503 = (v4 + 16);
    v506 = (v4 + 18);
    v12 = 0;
    v13 = v4 + 3;
    v14 = (v4 + 4);
    v15 = (v4 + 8);
    v16 = (v4 + 10);
    v501 = 0;
    pBasic = dds3GetControlScene();
    v502 = -1;
    v500 = -1;
    v523 = 0;
      goto LABEL_36;
LABEL_32:
    while (1)
    {
LABEL_36:
      if (v12 >= gEvnRngNum)
        goto LABEL_731;
LABEL_37:
      if (gEvnRngBox->m_Items[v523]->npcHoji < 1)
        goto LABEL_804;
      fieldID = fldGb->fieldID;
      areaID = fldGb->areaID;
      v28 = gEvnRngBox;
      if (!fldGbChkNpc(fieldID, areaID + 1, v28->m_Items[v523]->npcHoji))
      {
LABEL_804:
        v31 = gEvnRng;
        if (v31->m_Items[v523])
        {
          v34 = gEvnRng;
          if (fldEveHit_ChkOn(v34->m_Items[v523]->resourceName))
          {
            v37 = gEvnRng;
            pDate = v37->m_Items[v523]->pDate;
            v40 = gEvnRng->m_Items[v523]->_union;
            pPut = gEvnRng->m_Items[v523]->pPut;
            v42 = SetfldResPut(pDate, v40, pPut);
            v43 = gEvnRng;
            v44 = v42;
            v46 = SetfldEveType(v43->m_Items[v523]->pDate, v42->_union, v43->m_Items[v523]->pPut);
            switch (v46)
            {
              case 2u:
                v102 = gEvnRng;
                sub_854710(&v102->m_Items[v523]->sisei->fields, 0);
                v104 = gEvnRng;
                sub_854710(&v104->m_Items[v523]->sisei->fields, 1u);
                v106 = gEvnRng;
                sub_854710(&v106->m_Items[v523]->sisei->fields, 2u);
                v110 = 0;
                v111 = 0;
                do
                {
                  v113 = gEvnRngBox;
                  vtx = v113->m_Items[v523]->vtx;
                  SDF_VU0__COPYVECTOR(&v14[v110], vtx->m_Items[v110]);
                  ++v111;
                  ++v110;
                }
                while (v111 != 8);
                v118 = gEvnRngBox;
                SDF_VU0__COPYVECTOR(&v518, v118->m_Items[v523]->boxnml);
                sub_854710(v14, 0);
                sub_854710(dst, 0);
                sub_854710(v15, 0);
                sub_854710(v16, 0);
                sub_854710(v14, 1u);
                sub_854710(dst, 1u);
                sub_854710(v15, 1u);
                sub_854710(v16, 1u);
                sub_854710(v14, 2u);
                sub_854710(dst, 2u);
                sub_854710(v15, 2u);
                sub_854710(v16, 2u);
                v132 = gEvnRngBox;
                facenml = v132->m_Items[v523]->facenml;
                SDF_VU0__COPYVECTOR(&v518, facenml->m_Items[0]);
                sub_854710(v14, 0);
                sub_854710(dst, 0);
                sub_854710(v508, 0);
                sub_854710(v507, 0);
                sub_854710(v14, 1u);
                sub_854710(dst, 1u);
                sub_854710(v508, 1u);
                sub_854710(v507, 1u);
                sub_854710(v14, 2u);
                sub_854710(dst, 2u);
                sub_854710(v508, 2u);
                sub_854710(v507, 2u);
                v148 = gEvnRngBox;
                v150 = v148->m_Items[v523]->facenml;
                SDF_VU0__COPYVECTOR(&v518, v150->m_Items[1]);
                sub_854710(v14, 0);
                sub_854710(v15, 0);
                sub_854710(v508, 0);
                sub_854710(v503, 0);
                sub_854710(v14, 1u);
                sub_854710(v15, 1u);
                sub_854710(v508, 1u);
                sub_854710(v503, 1u);
                sub_854710(v14, 2u);
                sub_854710(v15, 2u);
                sub_854710(v508, 2u);
                sub_854710(v503, 2u);
                v164 = gEvnRngBox;
                v166 = v164->m_Items[v523]->facenml;
                SDF_VU0__COPYVECTOR(&v518, v166->m_Items[2]);
                sub_854710(dst, 0);
                sub_854710(v16, 0);
                sub_854710(v507, 0);
                sub_854710(v506, 0);
                sub_854710(dst, 1u);
                sub_854710(v16, 1u);
                sub_854710(v507, 1u);
                sub_854710(v506, 1u);
                sub_854710(dst, 2u);
                sub_854710(v16, 2u);
                sub_854710(v507, 2u);
                sub_854710(v506, 2u);
                v180 = gEvnRngBox;
                v182 = v180->m_Items[v523]->facenml;
                SDF_VU0__COPYVECTOR(&v518, v182->m_Items[3]);
                sub_854710(v15, 0);
                sub_854710(v16, 0);
                sub_854710(v503, 0);
                sub_854710(v506, 0);
                sub_854710(v15, 1u);
                sub_854710(v16, 1u);
                sub_854710(v503, 1u);
                sub_854710(v506, 1u);
                sub_854710(v15, 2u);
                sub_854710(v16, 2u);
                sub_854710(v503, 2u);
                sub_854710(v506, 2u);
                v196 = gEvnRngBox;
                v198 = v196->m_Items[v523]->facenml;
                SDF_VU0__COPYVECTOR(&v518, v198->m_Items[4]);
                sub_854710(v508, 0);
                sub_854710(v507, 0);
                sub_854710(v503, 0);
                sub_854710(v506, 0);
                sub_854710(v508, 1u);
                sub_854710(v507, 1u);
                sub_854710(v503, 1u);
                sub_854710(v506, 1u);
                sub_854710(v508, 2u);
                sub_854710(v507, 2u);
                sub_854710(v503, 2u);
                sub_854710(v506, 2u);
                v212 = gEvnRngBox;
                v214 = v212->m_Items[v523]->facenml;
                SDF_VU0__COPYVECTOR(&v518, v214->m_Items[5]);
                sub_854710(&pObjectBasic->poseset->pos, 0);
                sub_854930(&v518, 0);
                sub_854710(&pObjectBasic->poseset->pos, 1u);
                sub_854930(&v518, 1u);
                sub_854710(&pObjectBasic->poseset->pos, 2u);
                sub_854930(&v518, 2u);
                sub_854930(&v518, 3u);
                v218 = fldEveHit_ChkBoxIn(v518, v523);
                if (!v218)
                {
                  v394 = gEvnRng;
                  v396 = &v394->m_Items[v523]->resourceName;
                  pScriptName = fldInf_FindTypeEve(v396);
                  if (!pScriptName)
                  {
                    v398 = gEvnRng;
                    v400 = &v398->m_Items[v523]->resourceName;
                    pScriptName = fldDoor_Find(v400);
                    if (!pScriptName)
                    {
                      EveIdx = v44->EveIdx;
                      if ((EveIdx & 0x80000000) == 0)
                      {
                        resourceID = gEve->m_Items[EveIdx]->resourceID;
                        {
                        }
                        v406 = dds3SearchSceneBasic(&pBasic, resourceID, 0xDu);
                        Resource = dds3EventBasicGetResource(v406);
                        if (Resource && Resource->klass != string)
                        {
                          sub_8FC2C0(Resource->klass->_1.element_class, string, v524);
                          if ((v524[0] & 1) != 0)
                            v409 = v525;
                          else
                            v409 = &v524[1];
                          v410 = sub_8C4940(v409);
                        }
                        pScriptName = Resource;
                        fldEveHit_ScriptEnd(&pScriptName, v523);
                      }
                      gEvnRngPid->m_Items[v523] = 0;
                    }
                  }
                  break;
                }
                v220 = gEvnRng;
                v222 = &v220->m_Items[v523]->resourceName;
                pScriptName = fldInf_FindTypeEve(v222);
                if (pScriptName)
                  goto LABEL_650;
                v224 = gEvnRng;
                v226 = &v224->m_Items[v523]->resourceName;
                pScriptName = fldDoor_Find(v226);
                if (!pScriptName)
                {
                  v460 = fldGb->fieldID;
                  if (v460 == 60)
                    break;
                  if (v460 == 61)
                    break;
                  v461 = v44->EveIdx;
                  if ((v461 & 0x80000000) != 0)
                    break;
                  v463 = gEve;
                  v465 = v463->m_Items[v461]->resourceID;
                  v466 = dds3SearchSceneBasic(&pBasic, v465, 0xDu);
                  v383 = dds3EventBasicGetResource(v466);
                  if (v383 && v383->klass != string)
                  {
                    sub_8FC2C0(v383->klass->_1.element_class, string, v524);
                    if ((v524[0] & 1) != 0)
                      v467 = v525;
                    else
                      v467 = &v524[1];
                    v468 = sub_8C4940(v467);
                  }
                  goto LABEL_558;
                }
                v500 = v523;
                break;
              case 1u:
                v56 = gEvnRng;
                sub_854710(&v56->m_Items[v523]->sisei->fields, 0);
                v58 = gEvnRng;
                v60 = v59;
                sub_854710(&v58->m_Items[v523]->sisei->fields, 1u);
                v62 = gEvnRng;
                v64 = v63;
                sub_854710(&v62->m_Items[v523]->sisei->fields, 2u);
                v69 = v68;
                v70 = gEvnRngBox;
                v72 = v70->m_Items[v523]->vtx;
                SDF_VU0__COPYVECTOR(v14, v72->m_Items[0]);
                v75 = gEvnRngBox;
                v77 = v75->m_Items[v523]->vtx;
                SDF_VU0__COPYVECTOR(dst, v77->m_Items[1]);
                v82 = gEvnRngBox;
                v84 = v82->m_Items[v523]->vtx;
                SDF_VU0__COPYVECTOR(v15, v84->m_Items[2]);
                v89 = gEvnRngBox;
                v91 = v89->m_Items[v523]->vtx;
                SDF_VU0__COPYVECTOR(v16, v91->m_Items[3]);
                v96 = gEvnRngBox;
                SDF_VU0__COPYVECTOR(&v518, v96->m_Items[v523]->boxnml);
                {
                  v100 = dst;
                }
                else
                {
                  v100 = dst;
                }
                if (fldDbg->HitView == 1)
                {
                  v227 = NewSpecific(UnityEngine_Vector3, 2u);
                  v228 = v227;
                  sub_8529B0((v227 + 4), 0, v60 / 100.0);
                  sub_8529B0((v228 + 4), 1, v64 / -100.0);
                  sub_8529B0((v228 + 4), 2, v69 / 100.0);
                  sub_854710(&v518, 0);
                  sub_8529B0(v228 + 44, 0, (v60 + (v232 * 40.0)) / 100.0);
                  sub_854710(&v518, 1u);
                  sub_8529B0(v228 + 44, 1, (v64 + (v234 * 40.0)) / -100.0);
                  sub_854710(&v518, 2u);
                  sub_8529B0(v228 + 44, 2, (v69 + (v236 * 40.0)) / 100.0);
                  v238 = sub_232A70(&v523, "D3");
                  v241 = Concat_5224608("fldEveHit_ChkEveHitB", v238);
                  ooyTestLine3DForUnity(&HitEventObj, "HitEvent", v241, 0x8010FF10, 2, v228);
                  v100 = dst;
                }
                sub_854710(v14, 0);
                sub_854710(v100, 0);
                sub_854710(v14, 1u);
                sub_854710(v100, 1u);
                sub_854710(v14, 2u);
                sub_854710(v100, 2u);
                v250 = gEvnRngBox;
                v252 = v250->m_Items[v523]->facenml;
                SDF_VU0__COPYVECTOR(&v518, v252->m_Items[1]);
                sub_854710(dst, 0);
                sub_854710(v15, 0);
                sub_854710(dst, 1u);
                sub_854710(v15, 1u);
                sub_854710(dst, 2u);
                sub_854710(v15, 2u);
                v260 = gEvnRngBox;
                v262 = v260->m_Items[v523]->facenml;
                SDF_VU0__COPYVECTOR(&v518, v262->m_Items[2]);
                sub_854710(v15, 0);
                sub_854710(v16, 0);
                sub_854710(v15, 1u);
                sub_854710(v16, 1u);
                sub_854710(v15, 2u);
                sub_854710(v16, 2u);
                v270 = gEvnRngBox;
                v272 = v270->m_Items[v523]->facenml;
                SDF_VU0__COPYVECTOR(&v518, v272->m_Items[3]);
                sub_854710(v14, 0);
                sub_854710(v16, 0);
                sub_854710(v14, 1u);
                sub_854710(v16, 1u);
                sub_854710(v14, 2u);
                sub_854710(v16, 2u);
                v280 = gEvnRngBox;
                v282 = v280->m_Items[v523]->facenml;
                SDF_VU0__COPYVECTOR(&v518, v282->m_Items[4]);
                sub_854930(&v516, 0);
                sub_854930(&v516, 1u);
                sub_854930(&v516, 2u);
                sub_854930(&v515, 0);
                sub_854930(&v515, 1u);
                sub_854930(&v515, 2u);
                v286 = v516;
                v287 = gEvnRngBox;
                v288 = v517;
                v290 = v287->m_Items[v523]->facenml;
                v292 = v290[8];
                v293 = v290[9];
                v295 = v290[10];
                v294 = v290[11];
                *&v526.x = v286;
                *&v526.z = v288;
                v528.x = v292;
                v528.y = v293;
                v528.z = v295;
                v528.w = v294;
                v296 = MATH_DotProduct(v526, v528);
                v297 = gEvnRngBox;
                v298 = v296;
                facenum = v297->m_Items[v523]->facenum;
                v302 = facenum->m_Items[0];
                v303 = gEvnRngBox;
                v305 = v303->m_Items[v523]->facenml;
                v307 = MATH_DotProduct(v515, v305->m_Items[0]);
                v308 = gEvnRngBox;
                v310 = v308->m_Items[v523]->facenum;
                v311 = v298 - v302;
                v312 = v307 - v310->m_Items[0];
                if (v311 >= 0.0 || (v313 = -1, v312 < 0.0))
                {
                  if (v311 < 0.0 || v312 >= 0.0)
                    break;
                  v313 = 1;
                }
                v415 = v516;
                v416 = v517;
                v417 = v523;
                *&v527.x = v415;
                *&v527.z = v416;
                v419 = fldEveHitPositionInside(v527, v417);
                if (v419 == -1)
                {
                  v432 = gEvnRngBox;
                  v432->m_Items[v523]->facehit = 0;
                  break;
                }
                v421 = gEvnRngBox;
                v421->m_Items[v523]->facehit = v313;
                if (fldDbg->InfoOn == 1)
                {
                  v425 = gEvnRng;
                  resourceName = v425->m_Items[v523]->resourceName;
                  fldDbgPrintStr2DC(0, 24, -1, resourceName, 5);
                  v501 = 1;
                }
                v429 = gEvnRng;
                v431 = &v429->m_Items[v523]->resourceName;
                pScriptName = fldInf_FindTypeEve(v431);
                if (!pScriptName)
                {
                  v434 = v44->EveIdx;
                  if ((v434 & 0x80000000) != 0)
                    break;
                  v436 = gEve;
                  v438 = v436->m_Items[v434]->resourceID;
                  v439 = dds3SearchSceneBasic(&pBasic, v438, 0xDu);
                  v440 = dds3EventBasicGetResource(v439);
                  v442 = v440;
                  if (v440)
                  {
                    if (v440->klass != string)
                    {
                      sub_8FC2C0(v440->klass->_1.element_class, string, v524);
                      if ((v524[0] & 1) != 0)
                        v443 = v525;
                      else
                        v443 = &v524[1];
                      v444 = sub_8C4940(v443);
                    }
                  }
                  pScriptName = v440;
                  {
                  }
                  if (scrSearchScriptName(v442))
                    break;
                  scene = dds3GetActiveScene();
                  v446 = pScriptName;
                  started = dds3SceneBasicStartScript(&scene, v446);
                  v449 = gEvnRngPid;
                  v450 = v523;
                  v449->m_Items[v450] = started;
                  v454 = v523;
                  gFldEveRngIdx = v523;
                  gFldEveRngIdx_N = -1;
                  gFldEveRngIdx_T = -1;
                  v455 = gEvnRngBox;
                  if (v455->m_Items[v454]->npcHit == 1)
                  {
                    v458 = v523;
                    gFldEveRngIdx_N = v458;
                    if ((v457->_2.bitflags2 & 2) == 0)
                      goto LABEL_724;
LABEL_722:
                  }
                  else
                  {
                      goto LABEL_722;
                  }
LABEL_724:
                  v469 = gEvnRngBox;
                  if (v469->m_Items[v523]->npcHit == 2)
                  {
                    v472 = v523;
                    gFldEveRngIdx_T = v472;
                  }
                  break;
                }
LABEL_650:
                v502 = v523;
                break;
              case 0u:
                v47 = p1;
                p1->r = 30.0;
                p_pos = &v47->pos;
                sub_854710(&pObjectBasic->poseset->pos, 0);
                sub_854930(p_pos, 0);
                v49 = &p1->pos;
                sub_854710(&pObjectBasic->poseset->pos, 1u);
                sub_854930(v49, 1u);
                v50 = &p1->pos;
                sub_854710(&pObjectBasic->poseset->pos, 2u);
                sub_854930(v50, 2u);
                v53 = gEvnRng;
                max_length = v53->max_length;
                v315 = v44->_union;
                v316 = v53->m_Items[v523]->pDate;
                v318 = gEvnRng->m_Items[v523]->pPut;
                v319 = SetfldResPutEveBall(v316, v315, v318);
                v320 = p2;
                p2->r = v319->r;
                v321 = &v320->pos;
                v322 = gEvnRng;
                sub_854710(&v322->m_Items[v523]->sisei->fields, 0);
                sub_854930(v321, 0);
                v324 = &p2->pos;
                v325 = gEvnRng;
                sub_854710(&v325->m_Items[v523]->sisei->fields, 1u);
                sub_854930(v324, 1u);
                v327 = &p2->pos;
                v328 = gEvnRng;
                sub_854710(&v328->m_Items[v523]->sisei->fields, 2u);
                sub_854930(v327, 2u);
                if (dds3RadiusCheckPoseSet(&p1, &p2) != 1)
                {
                  v388 = gEvnRng;
                  v390 = &v388->m_Items[v523]->resourceName;
                  pScriptName = fldInf_FindTypeEve(v390);
                  if (!pScriptName && (v44->EveIdx & 0x80000000) == 0)
                  {
                    v391 = v523;
                    fldEveHit_ScriptEnd2(v391);
                  }
                  break;
                }
                if (fldDbg->InfoOn == 1)
                {
                  v335 = gEvnRng;
                  v337 = v335->m_Items[v523]->resourceName;
                  fldDbgPrintStr2DC(0, 0, -1, v337, 5);
                  v501 = 1;
                }
                if (fldDbg->InfoOn == 1)
                {
                  v339 = gEvnRngBox;
                  TakaraIdx = v339->m_Items[v523]->TakaraIdx;
                  if (TakaraIdx != -1)
                  {
                    v342 = NewSpecific(object, 6u);
                    *v524 = TakaraIdx;
                    v343 = v342;
                    v344 = sub_8D3950(s32, v524);
                    v346 = v344;
                    v343->m_Items[0] = v346;
                    v513 = *&_get_Item(
                               fldHitData->_fldItemBoxTbl,
                               TakaraIdx)->isLongReference;
                    v350 = sub_8D3950(s32, &v513);
                    v351 = v350;
                    v343->m_Items[1] = v351;
                    handle_low = SLOWORD(_get_Item(
                                           fldHitData->_fldItemBoxTbl,
                                           TakaraIdx)->gcHandle.handle);
                    v354 = sub_8D3950(s32, &handle_low);
                    v355 = v354;
                    v343->m_Items[2] = v355;
                    handle_high = SHIWORD(_get_Item(
                                            fldHitData->_fldItemBoxTbl,
                                            TakaraIdx)->gcHandle.handle);
                    v358 = sub_8D3950(s32, &handle_high);
                    v359 = v358;
                    v343->m_Items[3] = v359;
                    klass = _get_Item(
                              fldHitData->_fldItemBoxTbl,
                              TakaraIdx)[1].klass;
                    v362 = sub_8D3950(s32, &klass);
                    v363 = v362;
                    v343->m_Items[4] = v363;
                    klass_high = HIDWORD(_get_Item(
                                           fldHitData->_fldItemBoxTbl,
                                           TakaraIdx)[1].klass);
                    v366 = sub_8D3950(s32, &klass_high);
                    v367 = v366;
                    v343->m_Items[5] = v367;
                    v372 = Format_5268784("Takara:{0:D} [{1:D}, {2:D}, {3:D}, {4:D}, {5:D}]", v343, 0);
                    fldDbgPrintStr2DC(0, 12, -1, v372, 5);
                    v501 = 1;
                  }
                }
                v374 = gEvnRng;
                v376 = &v374->m_Items[v523]->resourceName;
                pScriptName = fldInf_FindTypeNpc(v376);
                if (pScriptName)
                  goto LABEL_650;
                v377 = v44->EveIdx;
                if ((v377 & 0x80000000) == 0)
                {
                  v379 = gEve;
                  v381 = v379->m_Items[v377]->resourceID;
                  v382 = dds3SearchSceneBasic(&pBasic, v381, 0xDu);
                  v383 = dds3EventBasicGetResource(v382);
                  if (v383 && v383->klass != string)
                  {
                    sub_8FC2C0(v383->klass->_1.element_class, string, v524);
                    if ((v524[0] & 1) != 0)
                      v385 = v525;
                    else
                      v385 = &v524[1];
                    v386 = sub_8C4940(v385);
                  }
LABEL_558:
                  pScriptName = v383;
                  fldEveHit_ScriptStart(&pScriptName, v523);
                }
                break;
            }
          }
        }
      }
      v12 = v523 + 1;
      ++v523;
        goto LABEL_32;
    }
  }
}

// 0x1047fe0
s32 fldEveHit_ChkEveHitAfter(void) {
  u16 gFldWap_after_flag;
  struct System_Char_array *gFldWap_after_scr;
  System_String_o *String_5280336;
  System_String_o *v12;
  System_String_o *v15;
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *scene;

  scene = 0;
  ActiveScene = 0;
  else
  {
    if ((gFldWap_after_flag & 1) == 0)
      return 0;
  }
  if ((gFldWap_after_flag & 2) != 0)
  {
    if (gFldWap_after_scr->m_Items[0])
    {
      scene = dds3GetActiveScene();
      String_5280336 = CreateString_5280336(0, gFldWap_after_scr);
      v12 = Replace_5267216(String_5280336, " ", "");
      dds3SceneBasicEndScript(&scene, v12);
    }
  }
  gFldWap_after_flag = 0;
  Clear(gFldWap_after_scr, 0, 15, 0);
  v15 = fldDoor_Find3();
  else if (!scrSearchScriptName(v15))
  {
    goto LABEL_34;
  }
  return 1;
}

// 0x104db40
s32 fldEveHit_ChkNpcScr(s32 npcidx) {
  s64 gFldEveRngIdx_N;
  struct putevebox_s_array *gEvnRngBox;
  struct putevebox_s_array *v10;

  else
  {
    if (gFldKyouseiTalk)
      return 1;
  }
  if (gFldEveRngIdx_N == -1)
    return 0;
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
  s64 gFldEveRngIdx_T;
  struct putevebox_s_array *gEvnRngBox;
  struct putevebox_s_array *v9;

  else
  {
    if (gFldEveRngIdx_T == -1)
      return 0;
  }
  else
  {
    if (gFldEveRngIdx_T >= LODWORD(gEvnRngBox->max_length))
      goto LABEL_9;
  }
  if (gEvnRngBox->m_Items[gFldEveRngIdx_T]->npcHit == 2)
  {
    v9 = gEvnRngBox;
    if (v9->m_Items[gFldEveRngIdx_T]->TakaraIdx == takaraidx)
      return 1;
  }
  return 0;
}

// 0x104c5c0
void fldEveHit_DrawEveHit(void) {
  u32 v2;

  v2 = 0;
  {
LABEL_6:
  }
  while (1)
  {
    if (v2 >= gEvnRngNum)
      break;
    else if (v2 >= LODWORD(gEvnRng->max_length))
    {
      goto LABEL_12;
    }
    ++v2;
      goto LABEL_6;
  }
}

// 0x103c450
void fldEveHit_End(void) {
  fldEveHit_c *v2;
  u64 v3;
  s16 v4;
  Il2CppClass **v5;
  s32 i;
  struct fldEveHit_StaticFields **p_static_fields;
  struct dds3ProcessID_t_array *gEvnRngPid;
  s32 v13;

  v3 = 0;
  gEveOff = 1;
  v4 = *&v2->_2.bitflags1;
  if ((v4 & 0x200) != 0)
    goto LABEL_10;
LABEL_9:
  for (i = 0; ; i = v4 & 0x200)
  {
    if (v3 >= gEvnRngNum)
      break;
    else
    {
      if (v3 >= LODWORD(gEvnRngPid->max_length))
        goto LABEL_17;
    }
    v5 = &gEvnRngPid->obj.klass + v3++;
    v5[4] = 0;
    if ((v4 & 0x200) == 0)
      goto LABEL_9;
LABEL_10:
  }
  gFldEveRngIdx = -1;
  (*p_static_fields)->gFldEveRngIdx_N = -1;
  (*p_static_fields)->gFldEveRngIdx_T = -1;
  else if (!dds3GetControlScene())
  {
    return;
  }
  v13 = -1;
  do
  {
    ++v13;
  }
  while (v13 < gEvnRngNum);
}

// 0x103b980
void fldEveHit_Init(void) {
  fldEveHit_c *v2;
  u64 v3;
  s32 v4;
  u32 *gEvnRngBox;
  u64 *v7;
  u64 v11;
  s64 v12;
  s32 v13;
  struct putevebox_s_array *v14;
  struct UnityEngine_Vector4_array *vtx;
  struct putevebox_s_array *v18;
  struct UnityEngine_Vector4_array *v20;
  struct putevebox_s_array *v22;
  struct UnityEngine_Vector4_array *v24;
  struct putevebox_s_array *v26;
  struct UnityEngine_Vector4_array *v28;
  u32 v30;
  struct putevebox_s_array *v31;
  struct putevebox_s_array *v33;
  struct putevebox_s_array *v35;
  struct putevebox_s_array *v37;
  u64 v40;
  s64 v41;
  s32 v42;
  struct putevebox_s_array *v43;
  struct UnityEngine_Vector4_array *facenml;
  struct putevebox_s_array *v47;
  struct UnityEngine_Vector4_array *v49;
  struct putevebox_s_array *v51;
  struct UnityEngine_Vector4_array *v53;
  struct putevebox_s_array *v55;
  struct UnityEngine_Vector4_array *v57;
  struct putevebox_s_array *v59;
  struct System_Single_array *facenum;
  char *v63;
  u32 v64;
  struct putevebox_s_array *v65;
  struct putevebox_s_array *v67;
  struct putevebox_s_array *v69;
  struct putevebox_s_array *v71;
  struct putevebox_s_array *v73;
  struct putevebox_s_array *v75;
  struct putevebox_s_array *v77;
  struct putevebox_s_array *v79;
  struct putevebox_s_array *v81;
  struct putevebox_s_array *v83;
  struct putevebox_s_array *v85;
  struct putevebox_s_array *v87;
  struct putevebox_s_array *v89;
  struct dds3ProcessID_t_array *gEvnRngPid;
  Il2CppClass **v93;
  u32 v94;
  u64 v95;
  s16 v96;
  s32 *v97;
  s32 i;
  struct fldEveHit_StaticFields **p_static_fields;
  s32 *gProgramEveHit;
  u64 *v102;

  gEvnRngNum = 0;
  gEveNum = 0;
  gEveOff = 0;
  v3 = 0;
  v4 = (v2->_2.bitflags2 >> 1) & 1;
  do
  {
    v7 = Allocate(putevebox_s);
    _ctor(v7, 0);
    *&gEvnRngBox[2 * v3 + 8] = v7;
    v11 = 0;
    v12 = 32;
    do
    {
      v14 = gEvnRngBox;
      vtx = v14->m_Items[v3]->vtx;
      sub_854930(vtx + v12, 0);
      v18 = gEvnRngBox;
      v20 = v18->m_Items[v3]->vtx;
      sub_854930(v20 + v12, 1u);
      v22 = gEvnRngBox;
      v24 = v22->m_Items[v3]->vtx;
      sub_854930(v24 + v12, 2u);
      v26 = gEvnRngBox;
      v28 = v26->m_Items[v3]->vtx;
      sub_854930(v28 + v12, 3u);
      ++v11;
      v12 += 16;
      v13 = (v30 >> 9) & 1;
    }
    while (v11 != 8);
    v31 = gEvnRngBox;
    sub_854930(&v31->m_Items[v3]->boxnml, 0);
    v33 = gEvnRngBox;
    sub_854930(&v33->m_Items[v3]->boxnml, 1u);
    v35 = gEvnRngBox;
    sub_854930(&v35->m_Items[v3]->boxnml, 2u);
    v37 = gEvnRngBox;
    sub_854930(&v37->m_Items[v3]->boxnml, 3u);
    v40 = 0;
    v41 = 32;
    do
    {
      v43 = gEvnRngBox;
      facenml = v43->m_Items[v3]->facenml;
      sub_854930(facenml + v41, 0);
      v47 = gEvnRngBox;
      v49 = v47->m_Items[v3]->facenml;
      sub_854930(v49 + v41, 1u);
      v51 = gEvnRngBox;
      v53 = v51->m_Items[v3]->facenml;
      sub_854930(v53 + v41, 2u);
      v55 = gEvnRngBox;
      v57 = v55->m_Items[v3]->facenml;
      sub_854930(v57 + v41, 3u);
      v59 = gEvnRngBox;
      facenum = v59->m_Items[v3]->facenum;
      v63 = facenum + 4 * v40++;
      *(v63 + 8) = 0;
      v42 = (v64 >> 9) & 1;
      v41 += 16;
    }
    while (v40 != 6);
    v65 = gEvnRngBox;
    v65->m_Items[v3]->put_serialID = 0;
    v67 = gEvnRngBox;
    v67->m_Items[v3]->sizex = 0.0;
    v69 = gEvnRngBox;
    v69->m_Items[v3]->sizey = 0.0;
    v71 = gEvnRngBox;
    v71->m_Items[v3]->sizez = 0.0;
    v73 = gEvnRngBox;
    v73->m_Items[v3]->anim_a = 0;
    v75 = gEvnRngBox;
    v75->m_Items[v3]->anim_cntf = 0.0;
    v77 = gEvnRngBox;
    v77->m_Items[v3]->type = 0;
    v79 = gEvnRngBox;
    v79->m_Items[v3]->TakaraIdx = -1;
    v81 = gEvnRngBox;
    v81->m_Items[v3]->npcHoji = -1;
    v83 = gEvnRngBox;
    v83->m_Items[v3]->npcHit = 0;
    v85 = gEvnRngBox;
    v85->m_Items[v3]->npcIdx = -1;
    v87 = gEvnRngBox;
    v87->m_Items[v3]->mode2D = 0;
    v89 = gEvnRngBox;
    v89->m_Items[v3]->facehit = 0;
    v93 = &gEvnRngPid->obj.klass + v3++;
    v93[4] = 0;
    v4 = (v94 >> 9) & 1;
  }
  while (v3 != 64);
  gProgramEveHitNum = 0;
  v95 = 0;
  v96 = *&v2->_2.bitflags1;
  if ((v96 & 0x200) != 0)
    goto LABEL_111;
LABEL_110:
  for (i = 0; ; i = v96 & 0x200)
  {
    if (v95 >= gProgramEveHit[6])
      break;
    v102 = Allocate(fldProgramEveHit_tag);
    _ctor(v102, 0);
    v97 = &gProgramEveHit[2 * v95++];
    *(v97 + 4) = v102;
    if ((v96 & 0x200) == 0)
      goto LABEL_110;
LABEL_111:
  }
  OldHitDoor = -1;
  (*p_static_fields)->OldHitInf = -1;
  (*p_static_fields)->gFldEveRngIdx = -1;
  (*p_static_fields)->gFldEveRngIdx_N = -1;
  (*p_static_fields)->gFldEveRngIdx_T = -1;
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
LABEL_11:
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
LABEL_32:
            v16 = DDS3_GBWK->unitwork;
            if ((v16->m_Items[v4]->badstatus & 0x100) != 0)
            {
              fldDbg->PlayerStatus |= 4u;
              {
LABEL_42:
                v20 = DDS3_GBWK->unitwork;
                if ((v20->m_Items[v4]->badstatus & 0x20) != 0)
                {
                  fldDbg->PlayerStatus |= 8u;
                    goto LABEL_52;
                }
                else
                {
                  {
LABEL_52:
                    v24 = DDS3_GBWK->unitwork;
                    if (v24->m_Items[v4]->badstatus < 0)
                    {
                      fldDbg->PlayerStatus |= 0x10u;
                    }
                    goto LABEL_59;
                  }
                }
                goto LABEL_52;
              }
            }
            else
            {
                goto LABEL_42;
            }
            goto LABEL_42;
          }
        }
        else
        {
            goto LABEL_32;
        }
        goto LABEL_32;
      }
    }
LABEL_59:
    ++v4;
    v5 = (v27 >> 9) & 1;
  }
  while (v4 != 16);
  v28 = DDS3_GBWK->unitwork;
  v30 = v28->m_Items[0];
  else if (datCheckDying(v30))
  {
LABEL_68:
    fldDbg->PlayerStatus |= 2u;
    PlayerStatus = fldDbg->PlayerStatus;
    v35 = (PlayerStatus >> 1) & 1;
    mdlSingleMotionForUnity(fldPlayerObj, "color", v35, 1, 0);
    v38 = "color";
    v39 = v35;
    goto LABEL_86;
  }
  v41 = fldPlayerObj;
  mdlSingleMotionForUnity(v41, "color", 0, 1, 0);
  v38 = "color";
  v39 = 0;
LABEL_86:
  mdlSingleMotionForUnity(fldPlayerObjM, v38, v39, 1, 0);
}
