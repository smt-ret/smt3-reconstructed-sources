#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct FieldChrHD FieldChrHD;
typedef struct ModelHD ModelHD;
typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ProcessFunc_t dds3ProcessFunc_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct pbProcHandle_t pbProcHandle_t;
typedef struct sdfModelOt_t sdfModelOt_t;

static f32 dir_rot[4];
static XRD773Unity_CommonMesh *pMesh;
static sdfVector3_t pMeshPos;
static sdfVector3_t r_cameraPos;
static sdfVector3_t r_cameraQuakePos;
static void *m_colorTex;
static void *m_depthTex;
static void *m_postRenderMat;
static s32 pbStartCameraPosflag;
static s32 pbChangeInitPosflag;
static s32 P_DrawCnt;
static bool ScaleCharflag;
static void *pModelObj;
static void *childobj;
static sdfVector3_t pbCameraPos[4];
static sdfVector3_t pbcCameraPos[4];
static sdfVector3_t pbBGAngle[4];
static sdfVector3_t pbcBGAngle[4];
static void *rCameraObj;
static void *r_camera;
static void *pbCameraObj;
static void *pb_camera;
static sdfVector3_t pbBGPos[4];

void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
void *GetMainCamera(dds3DefaultMain *this);
void *GetRenderCamera(dds3DefaultMain *this);
void *LoadPrefab_16624656(AssetBundleCtrl *this, char *key, char *path, char *name);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SetFrameAnime(ModelHD *this, bool act);
void StepFrame(ModelHD *this);
f32 dds3GetRandFloatA(char *name);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
void dds3SetProcessData(dds3ProcessID_t **id, void *data);
void *dds3StartProcess(char *v1, s32 dDS3_PRIORITY_DRAW_PB, s32 v2, s32 v3, dds3ProcessFunc_t *drawExit, void *deleteExit, void *p);
void fldDrawMaruKage(f32 x, f32 y, f32 z, f32 r, s32 a);
void mdlFree(dds3ModelHandle_t **aHandle);
void mdlGetPosition(dds3ModelHandle_t **aHandle);
void mdlGetRotate(dds3ModelHandle_t **aHandle);
void mdlLinkSub(dds3ModelHandle_t **aHandle, sdfModelOt_t **aModelOt, void *modelobj, bool camera_identity);
dds3ModelHandle_t *mdlLoad(s32 aMajor, s32 aMinor, u8 **byteData, s32 bPos);
void mdlLoopMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber);
void mdlSetEffectScale(dds3ModelHandle_t **aHandle, f32 aScale);
FieldChrHD *mdlSetHD(void *obj, s32 mode, evtUnitHandle_t *hunit, s32 layer);
void mdlSetPosition(dds3ModelHandle_t **aHandle);
void mdlSetRotate(dds3ModelHandle_t **aHandle);
void mdlSetScale(dds3ModelHandle_t **aHandle);
void *pbGetMyCharRootNode(pbProcHandle_t **p);

// 0x14aed30
dds3ProcessFunc_t *deleteMyCharacter(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3ModelHandle_t_o **v7;
  dds3ModelHandle_t_o *v8;
  s64 v9;
  char *v10;
  s64 *v11;
  dds3ModelHandle_t_o **v12;
  char *v16;
  s64 *v17;
  u64 v18[2];
  char *v19;

  workdata = id->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, v18);
    if ((v18[0] & 1) != 0)
      v16 = v19;
    else
      v16 = v18 + 1;
    v17 = sub_8C4940(v16);
  }
  v7 = workdata[2].klass;
  if (v7)
  {
    v8 = *v7;
    if (LOBYTE((*v7)[2].stat) < v9 || *(v8[1].modelRoot + v9 - 1) != pbMyChar_t)
    {
      sub_8FC2C0(v8->modelRoot, pbMyChar_t, v18);
      if ((v18[0] & 1) != 0)
        v10 = v19;
      else
        v10 = v18 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  v12 = v7 + 6;
  mdlFree(v12);
  P_DrawCnt = 0;
  return 0;
}

// 0x14ac7d0
dds3ProcessFunc_t *drawMyCharacter(dds3ProcessID_t *id) {
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  u64 *image;
  s64 v10;
  char *v11;
  s64 *v12;
  s32 v13;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  struct UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v19;
  f32 v20;
  f32 v21;
  f32 v22;
  UnityEngine_Transform_o *v23;
  UnityEngine_Transform_o *v27;
  f32 v28;
  void *data;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *v39;
  f32 v40;
  f32 v41;
  f32 v42;
  f32 v43;
  f32 v45;
  f32 v46;
  UnityEngine_Transform_o *v48;
  UnityEngine_Component_o *v49;
  struct UnityEngine_GameObject_o *v50;
  UnityEngine_Transform_o *v52;
  f32 v53;
  f32 v54;
  f32 v55;
  UnityEngine_Transform_o *v56;
  UnityEngine_Transform_o *v60;
  f32 v61;
  UnityEngine_GameObject_o *MainCamera;
  struct UnityEngine_GameObject_o *RenderCamera;
  Il2CppObject *v74;
  u64 *v76;
  f32 y;
  f32 z;
  s32 v80;
  s32 v81;
  s32 v83;
  s32 v84;
  s32 v86;
  s32 v87;
  u64 *v89;
  s32 v90;
  s32 v91;
  s32 v93;
  s32 v94;
  s32 v96;
  s32 v97;
  s32 v99;
  s32 v100;
  u64 *v103;
  UnityEngine_Transform_o *v105;
  f32 x;
  UnityEngine_Transform_o *v107;
  f32 v108;
  UnityEngine_Transform_o *v109;
  f32 v110;
  f32 v111;
  UnityEngine_Transform_o *v113;
  f32 v114;
  UnityEngine_Transform_o *v115;
  f32 v116;
  UnityEngine_Transform_o *v117;
  s32 v118;
  s32 v119;
  UnityEngine_Transform_o *v121;
  f32 v122;
  UnityEngine_Transform_o *v123;
  f32 v124;
  UnityEngine_Transform_o *v125;
  s32 v126;
  s32 v127;
  UnityEngine_Transform_o *v129;
  f32 v130;
  UnityEngine_Transform_o *v131;
  f32 v132;
  UnityEngine_Transform_o *v133;
  s32 v134;
  s32 v135;
  u64 *v137;
  UnityEngine_Transform_o *v138;
  f32 v139;
  UnityEngine_Transform_o *v140;
  f32 v141;
  UnityEngine_Transform_o *v142;
  s32 v143;
  s32 v144;
  UnityEngine_Transform_o *v146;
  f32 v147;
  UnityEngine_Transform_o *v148;
  f32 v149;
  UnityEngine_Transform_o *v150;
  s32 v151;
  s32 v152;
  UnityEngine_Transform_o *v154;
  f32 v155;
  UnityEngine_Transform_o *v156;
  f32 v157;
  UnityEngine_Transform_o *v158;
  s32 v159;
  s32 v160;
  UnityEngine_Transform_o *v162;
  f32 v163;
  UnityEngine_Transform_o *v164;
  f32 v165;
  UnityEngine_Transform_o *v166;
  s32 v168;
  s32 v169;
  pbGame_c *v171;
  s32 v175;
  struct UnityEngine_Vector3_array *v178;
  s64 v179;
  char *v181;
  s64 v183;
  pbModel_c *v185;
  UnityEngine_Transform_o *v186;
  f32 v187;
  UnityEngine_Transform_o *v188;
  f32 v189;
  UnityEngine_Transform_o *v190;
  f32 v192;
  UnityEngine_Transform_o *v195;
  struct UnityEngine_Vector3_array *pbcBGAngle;
  UnityEngine_GameObject_o *v199;
  UnityEngine_Transform_o *v200;
  f32 v203;
  UnityEngine_Transform_o *v204;
  s64 pb_cdir;
  UnityEngine_Transform_o *v210;
  UnityEngine_Transform_o *v211;
  f32 v212;
  UnityEngine_Transform_o *v213;
  s32 v214;
  struct UnityEngine_Vector3_array *pbcCameraPos;
  s64 v217;
  f32 v219;
  struct UnityEngine_Vector3_array *v220;
  struct UnityEngine_Vector3_array *pbCameraPos;
  s64 v223;
  f32 v225;
  s64 v226;
  f32 v228;
  struct UnityEngine_Vector3_array *v230;
  s64 v231;
  char *v233;
  s64 v235;
  UnityEngine_Transform_o *v236;
  u64 *v237;
  u32 *v238;
  u32 v240;
  u32 *v241;
  s16 v245;
  s32 v246;
  f32 pbQuakePosX;
  u32 v249;
  u64 v252;
  f32 v254;
  u64 v255;
  f32 *v257;
  f32 *v258;
  f32 v259;
  f32 RandFloatA;
  f32 v262;
  f32 v263;
  f32 v266;
  f32 v268;
  f32 v269;
  f32 v272;
  f32 *p_x;
  f32 v275;
  f32 v276;
  f32 v277;
  f32 v279;
  f32 v284;
  f32 v288;
  f32 v293;
  f32 v294;
  f32 v296;
  f32 v297;
  f32 v298;
  f32 v299;
  f32 v302;
  UnityEngine_Transform_o *v303;
  s32 pbQuakeFrame;
  s32 v308;
  UnityEngine_Object_o *pb_camera;
  s16 v313;
  s32 v314;
  f32 v317;
  f32 v318;
  f32 v321;
  UnityEngine_Transform_o *v324;
  f32 v325;
  UnityEngine_Transform_o *v326;
  f32 v330;
  UnityEngine_Transform_o *v331;
  f32 v333;
  f32 v334;
  f32 v335;
  f32 v336;
  f32 v337;
  f32 v338;
  f32 v339;
  f32 v340;
  f32 v341;
  f32 v342;
  f32 v343;
  s64 v344;
  s32 v345;
  s64 v346;
  s32 v347;
  s64 v348;
  s32 v349;
  s64 v350;
  s32 v351;
  s64 v352;
  s32 v353;
  s64 v354;
  s32 v355;
  s64 v356;
  s32 v357;
  dds3ModelHandle_t_o *v358;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector3_o aHandle;
  char *v361;
  sdfModelOt_t_o *aModelOt;
  UnityEngine_Quaternion_o v363;
  UnityEngine_Quaternion_o v364;

  *&p.x = 0;
  *&p.z = 0;
  aModelOt = 0;
  v358 = 0;
  workdata = id->workdata;
  if (workdata)
  {
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbProcHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbProcHandle_t, &aHandle);
      if ((LOBYTE(aHandle.x) & 1) != 0)
        v6 = v361;
      else
        v6 = &aHandle.x + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = workdata[2].klass;
  if (v8)
  {
    image = v8->_1.image;
    if (*(v8->_1.image + 288) < v10 || *(image[25] + 8 * v10 - 8) != pbMyChar_t)
    {
      sub_8FC2C0(image[8], pbMyChar_t, &aHandle);
      if ((LOBYTE(aHandle.x) & 1) != 0)
        v11 = v361;
      else
        v11 = &aHandle.x + 1;
      v12 = sub_8C4940(v11);
    }
  }
  v13 = SLODWORD(workdata[1].monitor) >> 16;
  if (v13 == 5)
    goto LABEL_37;
LABEL_20:
  if (v13 == 1)
  {
    LODWORD(workdata[1].monitor) = 0;
  }
  transform = get_transform(pModelObj, 0);
  Child = GetChild(transform, 0);
  gameObject = get_gameObject(Child);
  childobj = gameObject;
  v19 = get_transform(childobj, 0);
  v20 = *&v8->_1.byval_arg.data;
  v21 = *(&v8->_1.byval_arg.data + 1);
  v22 = *&v8->_1.byval_arg.bits;
  aHandle.z = 0.0;
  *&aHandle.x = 0;
  v23 = v19;
  sub_8524C0(&aHandle.x, v20, v21 + -10.0, v22);
  set_position(v23, aHandle);
  switch (LODWORD(v8->_1.namespaze))
  {
    case 0:
      v27 = get_transform(childobj, 0);
      {
      }
      v28 = 0.0;
      goto LABEL_59;
    case 1:
      v27 = get_transform(childobj, 0);
      {
      }
      v28 = 90.0;
      goto LABEL_59;
    case 2:
      v27 = get_transform(childobj, 0);
      {
      }
      v28 = 180.0;
      goto LABEL_59;
    case 3:
      v27 = get_transform(childobj, 0);
      {
      }
      v28 = 270.0;
LABEL_59:
      v363 = Euler(-90.0, v28, 0.0);
      set_rotation(v27, v363);
      break;
    default:
      break;
  }
  if (LODWORD(v8->_1.name))
  {
    data = v8->_1.this_arg.data;
    *&aHandle.x = data;
    SDF_VU0__LOADVECTOR(v8->_1.byval_arg);
    mdlSetPosition(&aHandle);
    Component_object = GetComponent_object_(pModelObj);
    StepFrame(Component_object);
    aModelOt = 0;
    v39 = *&v8->_1.this_arg.bits;
    v358 = v8->_1.this_arg.data;
    mdlLinkSub(&v358, &aModelOt, v39, 0);
    mdlGetPosition(&v8->_1.this_arg);
    SDF_VU0__STOREVECTOR(&p);
    sub_854710(&p, 0);
    v41 = v40;
    sub_854710(&p, 1u);
    v43 = v42;
    sub_854710(&p, 2u);
    v46 = v45;
    fldDrawMaruKage(v41, v43 + -1.0, v46, 20.0, 128);
  }
  v48 = get_transform(pModelObj, 0);
  v49 = GetChild(v48, 0);
  v50 = get_gameObject(v49);
  childobj = v50;
  v52 = get_transform(childobj, 0);
  v53 = *&v8->_1.byval_arg.data;
  v54 = *(&v8->_1.byval_arg.data + 1);
  v55 = *&v8->_1.byval_arg.bits;
  aHandle.z = 0.0;
  *&aHandle.x = 0;
  v56 = v52;
  sub_8524C0(&aHandle.x, v53, v54 + -10.0, v55);
  set_position(v56, aHandle);
  switch (LODWORD(v8->_1.namespaze))
  {
    case 0:
      v60 = get_transform(childobj, 0);
      {
      }
      v61 = 0.0;
      goto LABEL_108;
    case 1:
      v60 = get_transform(childobj, 0);
      {
      }
      v61 = 90.0;
      goto LABEL_108;
    case 2:
      v60 = get_transform(childobj, 0);
      {
      }
      v61 = 180.0;
      goto LABEL_108;
    case 3:
      v60 = get_transform(childobj, 0);
      {
      }
      v61 = 270.0;
LABEL_108:
      v364 = Euler(-90.0, v61, 0.0);
      set_rotation(v60, v364);
      break;
    default:
      break;
  }
  else if (pbStartCameraPosflag)
  {
    goto LABEL_136;
  }
  MainCamera = GetMainCamera(kernelObject);
  pbCameraObj = MainCamera;
  pb_camera = GetComponent_object_(pbCameraObj);
  RenderCamera = GetRenderCamera(kernelObject);
  rCameraObj = RenderCamera;
  v74 = GetComponent_object_(rCameraObj);
  r_camera = v74;
  set_fieldOfView(pb_camera, 60.0);
  v76 = NewSpecific(UnityEngine_Vector3, 4u);
  aHandle.z = 0.0;
  *&aHandle.x = 0;
  sub_8524C0(&aHandle.x, 150.0, 0.0, 0.0);
  y = aHandle.y;
  z = aHandle.z;
  *(v76 + 8) = LODWORD(aHandle.x);
  *(v76 + 9) = y;
  *(v76 + 10) = z;
  v357 = 0;
  v356 = 0;
  sub_8524C0(&v356, 150.0, -90.0, 0.0);
  v80 = HIDWORD(v356);
  v81 = v357;
  *(v76 + 11) = v356;
  *(v76 + 12) = v80;
  *(v76 + 13) = v81;
  v355 = 0;
  v354 = 0;
  sub_8524C0(&v354, 30.0, 0.0, -180.0);
  v83 = HIDWORD(v354);
  v84 = v355;
  *(v76 + 14) = v354;
  *(v76 + 15) = v83;
  *(v76 + 16) = v84;
  v353 = 0;
  v352 = 0;
  sub_8524C0(&v352, 150.0, 90.0, 0.0);
  v86 = HIDWORD(v352);
  v87 = v353;
  *(v76 + 17) = v352;
  *(v76 + 18) = v86;
  *(v76 + 19) = v87;
  pbBGAngle = v76;
  v89 = NewSpecific(UnityEngine_Vector3, 4u);
  v351 = 0;
  v350 = 0;
  sub_8524C0(&v350, -180.0, 0.0, 0.0);
  v90 = HIDWORD(v350);
  v91 = v351;
  *(v89 + 8) = v350;
  *(v89 + 9) = v90;
  *(v89 + 10) = v91;
  v349 = 0;
  v348 = 0;
  sub_8524C0(&v348, 0.0, 90.0, -180.0);
  v93 = HIDWORD(v348);
  v94 = v349;
  *(v89 + 11) = v348;
  *(v89 + 12) = v93;
  *(v89 + 13) = v94;
  v347 = 0;
  v346 = 0;
  sub_8524C0(&v346, 0.0, 0.0, -180.0);
  v96 = HIDWORD(v346);
  v97 = v347;
  *(v89 + 14) = v346;
  *(v89 + 15) = v96;
  *(v89 + 16) = v97;
  v345 = 0;
  v344 = 0;
  sub_8524C0(&v344, 0.0, -90.0, -180.0);
  v99 = HIDWORD(v344);
  v100 = v345;
  *(v89 + 17) = v344;
  *(v89 + 18) = v99;
  *(v89 + 19) = v100;
  pbcBGAngle = v89;
LABEL_136:
  v103 = NewSpecific(UnityEngine_Vector3, 4u);
  v105 = get_transform(childobj, 0);
  x = get_position(v105).x;
  v107 = get_transform(childobj, 0);
  v108 = get_position(v107).y;
  v109 = get_transform(childobj, 0);
  v333 = get_position(v109).z;
  aHandle.z = 0.0;
  *&aHandle.x = 0;
  sub_8524C0(&aHandle.x, x, v108 + 400.0, v333 + -240.0);
  v110 = aHandle.y;
  v111 = aHandle.z;
  *(v103 + 8) = LODWORD(aHandle.x);
  *(v103 + 9) = v110;
  *(v103 + 10) = v111;
  v113 = get_transform(childobj, 0);
  v114 = get_position(v113).x;
  v115 = get_transform(childobj, 0);
  v116 = get_position(v115).y;
  v117 = get_transform(childobj, 0);
  v334 = get_position(v117).z;
  v357 = 0;
  v356 = 0;
  sub_8524C0(&v356, v114 + 240.0, v116 + 400.0, v334);
  v118 = HIDWORD(v356);
  v119 = v357;
  *(v103 + 11) = v356;
  *(v103 + 12) = v118;
  *(v103 + 13) = v119;
  v121 = get_transform(childobj, 0);
  v122 = get_position(v121).x;
  v123 = get_transform(childobj, 0);
  v124 = get_position(v123).y;
  v125 = get_transform(childobj, 0);
  v335 = get_position(v125).z;
  v355 = 0;
  v354 = 0;
  sub_8524C0(&v354, v122, v124 + 400.0, v335 + 240.0);
  v126 = HIDWORD(v354);
  v127 = v355;
  *(v103 + 14) = v354;
  *(v103 + 15) = v126;
  *(v103 + 16) = v127;
  v129 = get_transform(childobj, 0);
  v130 = get_position(v129).x;
  v131 = get_transform(childobj, 0);
  v132 = get_position(v131).y;
  v133 = get_transform(childobj, 0);
  v336 = get_position(v133).z;
  v353 = 0;
  v352 = 0;
  sub_8524C0(&v352, v130 + -240.0, v132 + 400.0, v336);
  v134 = HIDWORD(v352);
  v135 = v353;
  *(v103 + 17) = v352;
  *(v103 + 18) = v134;
  *(v103 + 19) = v135;
  pbCameraPos = v103;
  v137 = NewSpecific(UnityEngine_Vector3, 4u);
  v138 = get_transform(childobj, 0);
  v139 = get_position(v138).x;
  v140 = get_transform(childobj, 0);
  v141 = get_position(v140).y;
  v142 = get_transform(childobj, 0);
  v337 = get_position(v142).z;
  v351 = 0;
  v350 = 0;
  sub_8524C0(&v350, v139, v141 + 450.0, v337);
  v143 = HIDWORD(v350);
  v144 = v351;
  *(v137 + 8) = v350;
  *(v137 + 9) = v143;
  *(v137 + 10) = v144;
  v146 = get_transform(childobj, 0);
  v147 = get_position(v146).x;
  v148 = get_transform(childobj, 0);
  v149 = get_position(v148).y;
  v150 = get_transform(childobj, 0);
  v338 = get_position(v150).z;
  v349 = 0;
  v348 = 0;
  sub_8524C0(&v348, v147, v149 + 450.0, v338);
  v151 = HIDWORD(v348);
  v152 = v349;
  *(v137 + 11) = v348;
  *(v137 + 12) = v151;
  *(v137 + 13) = v152;
  v154 = get_transform(childobj, 0);
  v155 = get_position(v154).x;
  v156 = get_transform(childobj, 0);
  v157 = get_position(v156).y;
  v158 = get_transform(childobj, 0);
  v339 = get_position(v158).z;
  v347 = 0;
  v346 = 0;
  sub_8524C0(&v346, v155, v157 + 450.0, v339);
  v159 = HIDWORD(v346);
  v160 = v347;
  *(v137 + 14) = v346;
  *(v137 + 15) = v159;
  *(v137 + 16) = v160;
  v162 = get_transform(childobj, 0);
  v163 = get_position(v162).x;
  v164 = get_transform(childobj, 0);
  v165 = get_position(v164).y;
  v166 = get_transform(childobj, 0);
  v340 = get_position(v166).z;
  v345 = 0;
  v344 = 0;
  sub_8524C0(&v344, v163, v165 + 450.0, v340);
  v168 = HIDWORD(v344);
  v169 = v345;
  *(v137 + 17) = v344;
  *(v137 + 18) = v168;
  *(v137 + 19) = v169;
  pbcCameraPos = v137;
  else
  {
    if (BGDrawflag)
      goto LABEL_158;
  }
  if (cameraWk_flg)
  {
    v195 = get_transform(BGImage, 0);
    {
LABEL_207:
    }
  }
  else
  {
    v195 = get_transform(BGImage, 0);
    pbcBGAngle = pbBGAngle;
      goto LABEL_207;
  }
  set_localEulerAngles(v195, pbcBGAngle->m_Items[pb_cdir]);
  v210 = get_transform(BGImage, 0);
  v211 = get_transform(childobj, 0);
  v212 = get_position(v211).x;
  v213 = get_transform(childobj, 0);
  v342 = get_position(v213).z;
  aHandle.z = 0.0;
  *&aHandle.x = 0;
  sub_8524C0(&aHandle.x, v212, -200.0, v342 + 100.0);
  set_position(v210, aHandle);
  BGDrawflag = 1;
  if ((v171->_2.bitflags2 & 2) == 0)
  {
LABEL_232:
    if (!cameraWk_flg)
      goto LABEL_161;
LABEL_233:
    if ((*&v171->_2.bitflags1 & 0x200) == 0)
    {
      v214 = 0;
      if (pbViewChangeflag)
        goto LABEL_235;
LABEL_254:
      if (pb_cdirflag)
        goto LABEL_293;
      if (pbChangeCameraMovflag)
        goto LABEL_293;
      v223 = pb_cdir;
      v225 = sub_8527D0(&pbCameraPos->m_Items[v223].x, 0);
      sub_8529B0(&r_cameraPos, 0, v225 + pbScrollCameraPosMovXbup);
      v220 = pbCameraPos;
LABEL_271:
      v226 = pb_cdir;
      v228 = sub_8527D0(&v220->m_Items[v226].x, 2);
      sub_8529B0(&r_cameraPos, 2, v228 + pbScrollCameraPosMovYbup);
      pb_cdirflag = 1;
      goto LABEL_293;
    }
    else
    {
      if (!pbViewChangeflag)
        goto LABEL_254;
    }
LABEL_235:
    if (pb_cdirflag)
      goto LABEL_293;
    if (pbChangeCameraMovflag)
      goto LABEL_293;
    v217 = pb_cdir;
    v219 = sub_8527D0(&pbcCameraPos->m_Items[v217].x, 0);
    sub_8529B0(&r_cameraPos, 0, v219 + pbScrollCameraPosMovXbup);
    v220 = pbcCameraPos;
    goto LABEL_271;
  }
LABEL_159:
    goto LABEL_232;
  if (cameraWk_flg)
    goto LABEL_233;
LABEL_161:
  v175 = *&v171->_2.bitflags1 & 0x200;
  if (!pbStartCameraPosflag)
  {
    pb_cameraAngle.x = 60.0;
    pb_cameraAngle.y = 0.0;
    v199 = get_gameObject(pb_camera);
    v200 = get_transform(v199, 0);
    set_localEulerAngles(v200, pb_cameraAngle);
    aHandle.z = 0.0;
    *&aHandle.x = 0;
    sub_8524C0(&aHandle.x, 180.0, 400.0, 140.0);
    v203 = aHandle.z;
    *&r_cameraPos.x = *&aHandle.x;
    r_cameraPos.z = v203;
    v204 = get_transform(pb_camera, 0);
    set_position(v204, r_cameraPos);
    set_farClipPlane(pb_camera, 1200.0);
    pbStartCameraPosflag = 1;
      goto LABEL_298;
    goto LABEL_216;
  }
  if (!pbViewChangeflag)
  {
    if (!pbCameraRotateflag)
    {
      if (!pbChangeCameraMovflag)
      {
        v230 = pbCameraPos;
        v231 = pb_cdir;
        v233 = v230 + 12 * v231;
        v235 = *(v233 + 4);
        LODWORD(v233) = *(v233 + 10);
        *&r_cameraPos.x = v235;
        LODWORD(r_cameraPos.z) = v233;
      }
    }
LABEL_293:
    goto LABEL_294;
  }
  if (!pbCameraRotateflag)
  {
    if (!pbChangeCameraMovflag)
    {
      v178 = pbcCameraPos;
      v179 = pb_cdir;
      v181 = v178 + 12 * v179;
      v183 = *(v181 + 4);
      LODWORD(v181) = *(v181 + 10);
      *&r_cameraPos.x = v183;
      LODWORD(r_cameraPos.z) = v181;
    }
  }
  if (pbChangeCameraMovflag)
  {
LABEL_294:
    if ((v185->_2.bitflags2 & 2) == 0)
      goto LABEL_297;
    goto LABEL_295;
  }
  v186 = get_transform(childobj, 0);
  v187 = get_position(v186).x;
  v188 = get_transform(childobj, 0);
  v189 = get_position(v188).y;
  v190 = get_transform(childobj, 0);
  v341 = get_position(v190).z;
  aHandle.z = 0.0;
  *&aHandle.x = 0;
  sub_8524C0(&aHandle.x, v187, v189 + 450.0, v341);
  v192 = aHandle.z;
  *&r_cameraPos.x = *&aHandle.x;
  r_cameraPos.z = v192;
  if ((v185->_2.bitflags2 & 2) != 0)
  {
LABEL_295:
  }
LABEL_297:
  v236 = get_transform(pb_camera, 0);
  set_position(v236, r_cameraPos);
    goto LABEL_298;
LABEL_216:
LABEL_298:
  if (pbCameraQuakeflag != 1)
    goto LABEL_398;
LABEL_299:
  v237 = NewSpecific(f32, 2u);
  v238 = NewSpecific(f32, 2u);
  v240 = v238[6];
  v241 = v238;
  v238[8] = 1058642330;
  v238[9] = 1058642330;
  if ((v245 & 0x200) != 0)
  {
    v246 = v245 & 0x200;
    if (pbQuakeFrame)
      goto LABEL_305;
LABEL_417:
    pbCameraQuakeflag = 0;
    return 0;
  }
  v246 = 0;
  if (!pbQuakeFrame)
    goto LABEL_417;
LABEL_305:
  v249 = *(v237 + 6);
  *(v237 + 8) = pbQuakePosX * 0.01;
  *(v237 + 9) = pbQuakePosY * 0.01;
  v252 = 0;
  do
  {
    v255 = v252;
    v257 = v237 + v252;
    v259 = v257[8];
    v258 = v257 + 8;
    if (v259 == 0.0)
      goto LABEL_378;
    RandFloatA = dds3GetRandFloatA("");
    v262 = *v258;
    v263 = *v258;
    v266 = sub_8527D0(&r_cameraQuakePos.x, v255);
    else
    {
      v254 = RandFloatA * v262;
      if (v255 >= *(v237 + 6))
      {
LABEL_333:
      }
    }
    v268 = v254 * 0.5;
    v269 = fabsf(v266);
    v272 = v268 + (v263 * 0.5);
    if (v269 >= (*v258 * *&v241[v255 + 8]))
    {
      v279 = sub_8527D0(&r_cameraQuakePos.x, v255);
      if (v279 <= 0.0)
      {
        p_x = &r_cameraQuakePos.x;
        v277 = v272 + sub_8527D0(p_x, v255);
      }
      else
      {
        p_x = &r_cameraQuakePos.x;
        v277 = sub_8527D0(p_x, v255) - v272;
      }
    }
    else
    {
      p_x = &r_cameraQuakePos.x;
      v275 = sub_8527D0(p_x, v255);
      v276 = dds3GetRandFloatA("");
      v277 = v275 + ((v272 * (v276 + -0.5)) + (v272 * (v276 + -0.5)));
    }
    sub_8529B0(p_x, v255, v277);
    v284 = sub_8527D0(&r_cameraQuakePos.x, v255);
    if (v284 >= -*v258)
    {
        goto LABEL_370;
LABEL_366:
      goto LABEL_370;
    }
    else if (v255 >= *(v237 + 6))
    {
LABEL_364:
    }
    sub_8529B0(&r_cameraQuakePos, v255, -*v258);
      goto LABEL_366;
LABEL_370:
    v288 = sub_8527D0(&r_cameraQuakePos.x, v255);
    if (v288 > *v258)
    {
      else if (v255 >= *(v237 + 6))
      {
LABEL_376:
      }
      sub_8529B0(&r_cameraQuakePos, v255, *v258);
    }
LABEL_378:
    v252 = 1;
  }
  while (!v255);
  v293 = r_cameraPos.x;
  v294 = sub_8527D0(&r_cameraQuakePos.x, 0);
  v296 = r_cameraPos.y;
  v297 = v294;
  v298 = sub_8527D0(&r_cameraQuakePos.x, 1);
  v299 = r_cameraPos.z;
  aHandle.z = 0.0;
  *&aHandle.x = 0;
  sub_8524C0(&aHandle.x, v293 + v297, v296 + v298, v299);
  v302 = aHandle.z;
  *&r_cameraPos.x = *&aHandle.x;
  r_cameraPos.z = v302;
  v303 = get_transform(pb_camera, 0);
  set_position(v303, r_cameraPos);
  if (pbQuakeFrame >= 1)
  {
    pbQuakePosX -= (pbQuakePosX / (pbQuakeFrame + 5));
    pbQuakePosY -= (pbQuakePosY / (pbQuakeFrame + 5));
  }
  v308 = pbQuakeFrame;
  if (v308 >= 1)
  {
    pbQuakeFrame = v308 - 1;
  }
LABEL_398:
  if (op_Inequality(pb_camera, 0, 0))
  {
    if ((v313 & 0x200) != 0)
    {
      v314 = v313 & 0x200;
      if (!cameraWk_flg)
        goto LABEL_424;
LABEL_407:
      v317 = BGImagePos.x;
      v318 = BGImagePos.z;
      aHandle.z = 0.0;
      *&aHandle.x = 0;
      sub_8524C0(&aHandle.x, v317, -480.0, v318);
      v321 = aHandle.z;
      *&BGImagePos.x = *&aHandle.x;
      BGImagePos.z = v321;
    }
    else
    {
      v314 = 0;
      if (cameraWk_flg)
        goto LABEL_407;
LABEL_424:
      v324 = get_transform(childobj, 0);
      v325 = get_position(v324).x;
      v326 = get_transform(childobj, 0);
      v343 = get_position(v326).z;
      aHandle.z = 0.0;
      *&aHandle.x = 0;
      sub_8524C0(&aHandle.x, v325, -480.0, v343);
      v330 = aHandle.z;
      *&BGImagePos.x = *&aHandle.x;
      BGImagePos.z = v330;
    }
    v331 = get_transform(BGImage, 0);
    set_position(v331, BGImagePos);
  }
  return 0;
}

// 0x14afd60
void pbChangeMotion(pbProcHandle_t **p, u32 num) {
  ;
}

// 0x14afd70
void pbChangeMotion2(pbProcHandle_t **p, u32 num, f32 st, f32 total) {
  ;
}

// 0x14afc50
void pbDispMyCharacter(pbProcHandle_t **p, s8 sw) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  data = (*p)->data;
  if (data)
  {
    klass = data->klass;
    if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbMyChar_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbMyChar_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  if (*p)
    LODWORD(data[1].klass) = sw;
}

// 0x14aef10
void pbGetModelPos(dds3ModelHandle_t *aHandle, sdfVector4_t *pos) {
  dds3ModelHandle_t_o *aHandlea;

  aHandlea = aHandle;
  mdlGetPosition(&aHandlea);
  SDF_VU0__STOREVECTOR(pos);
}

// 0x14aefa0
void pbGetModelRot(dds3ModelHandle_t *aHandle, sdfVector4_t *rot) {
  dds3ModelHandle_t_o *aHandlea;

  aHandlea = aHandle;
  mdlGetRotate(&aHandlea);
  SDF_VU0__STOREVECTOR(rot);
}

// 0x14af0e0
void pbGetModelScl(dds3ModelHandle_t *aHandle, sdfVector4_t *scl) {
  ;
}

// 0x14afd80
u32 pbGetMotion(pbProcHandle_t **p) {
  return 0;
}

// 0x14afa40
void *pbGetMyCharRootNode(pbProcHandle_t **p) {
  Il2CppObject *result;
  Il2CppObject **data;
  Il2CppObject *v5;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  result = *p;
  data = (*p)->data;
  if (data)
  {
    v5 = *data;
    if (LOBYTE((*data)[18].klass) < typeHierarchyDepth
      || *(v5[12].monitor + typeHierarchyDepth - 1) != pbMyChar_t)
    {
      sub_8FC2C0(v5[4].klass, pbMyChar_t, v9);
      if ((v9[0] & 1) != 0)
        v7 = v9[2];
      else
        v7 = v9 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  if (result)
    return data[6];
  return result;
}

// 0x14b0160
void pbGetMyCharcterPos(pbProcHandle_t **p, sdfVector4_t *pos) {
  UnityEngine_Vector4_o *data;
  s64 v6;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  data = (*p)->data;
  if (data)
  {
    v6 = *&data->x;
    if (*(*&data->x + 288LL) < typeHierarchyDepth
      || *(*(v6 + 200) + 8 * typeHierarchyDepth - 8) != pbMyChar_t)
    {
      sub_8FC2C0(*(v6 + 64), pbMyChar_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  if (*p)
    SDF_VU0__COPYVECTOR(pos, data[2]);
}

// 0x14b0280
void pbGetMyCharcterPos2(pbProcHandle_t **p, s16 *x, s16 *y) {
  s16 *data;
  s64 v8;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u64 v12[3];

  data = (*p)->data;
  if (data)
  {
    v8 = *data;
    if (*(*data + 288LL) < typeHierarchyDepth || *(*(v8 + 200) + 8 * typeHierarchyDepth - 8) != pbMyChar_t)
    {
      sub_8FC2C0(*(v8 + 64), pbMyChar_t, v12);
      if ((v12[0] & 1) != 0)
        v10 = v12[2];
      else
        v10 = v12 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  if (*p)
  {
    *x = data[10];
    *y = data[11];
  }
}

// 0x14b03a0
s32 pbGetMyCharcterRot(pbProcHandle_t **p) {
  s32 *data;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v9[3];

  data = (*p)->data;
  if (data)
  {
    v4 = *data;
    if (*(*data + 288LL) < typeHierarchyDepth || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != pbMyChar_t)
    {
      sub_8FC2C0(*(v4 + 64), pbMyChar_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (*p)
    return data[6];
  else
    return -1;
}

// 0x14af100
pbProcHandle_t *pbInitMyCharacterDraw(pbProcHandle_t **parent, u32 col, u32 motion) {
  u64 *v5;
  u64 *v6;
  u64 *v7;
  u64 *v8;
  u64 *v9;
  pbProcHandle_t_Fields *p_fields;
  u64 *v13;
  u64 *v14;
  u64 v16;
  s64 typeHierarchyDepth;
  char *v18;
  s64 *v19;
  dds3ModelHandle_t_o **v21;
  UnityEngine_Object_o *pModelObj;
  UnityEngine_Object_o *v27;
  struct dds3ModelFileTable_t_array *devilModelFileTable;
  System_String_o *akey;
  System_String_o *fname;
  UnityEngine_GameObject_o *btldevil;
  AssetBundleCtrl_o *asset_bc;
  System_String_o *v38;
  Il2CppObject *Prefab_16624656;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v43;
  UnityEngine_Transform_o *v46;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v49;
  s64 v51;
  UnityEngine_Transform_o *v52;
  s64 v53;
  UnityEngine_Transform_o *v55;
  f32 *p_SDF_CC_NDNM;
  f32 v58;
  f32 v59;
  f32 v60;
  f32 v61;
  UnityEngine_Transform_o *v62;
  UnityEngine_GameObject_o *v65;
  Il2CppObject *Component_object;
  UnityEngine_Vector4_o v68;
  u64 v69[3];
  UnityEngine_Quaternion_o localRotation;
  UnityEngine_Vector3_o v71;
  UnityEngine_Vector4_o v72;
  UnityEngine_Quaternion_o v73;
  UnityEngine_Quaternion_o v74;

  *&v68.x = 0;
  *&v68.z = 0;
  sub_854690(&v68.x, 40.0, 40.0, 40.0, 1.0);
  v5 = Allocate(UnityEngine_GameObject);
  _ctor_27226688(v5);
  set_name(v5, "pbInitMyCharacterDraw");
  v6 = Allocate(pbProcHandle_t);
  v7 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v7);
  v6[2] = v7;
  LODWORD(v69[0]) = 0;
  v6[4] = sub_8D3950(s32, v69);
  _ctor(v6, 0);
  v8 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v8,
    0,
    Method_pbModel_drawMyCharacter__);
  v9 = Allocate(System_Func_dds3ProcessID_t__object_);
  object____ctor(
    v9,
    0,
    Method_pbModel_deleteMyCharacter__);
  v6[2] = dds3StartProcess("pb-draw-mycharacter", 0x2AFDu, 1, 1, v8, 0, v9, 0, 0, 0);
  if (*parent)
  {
    p_fields = &(*parent)->fields;
    dds3LinkProcess(&p_fields->id, v6 + 2);
  }
  *(v6 + 6) = 0x10000;
  v13 = Allocate(pbMyChar_t);
  v14 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v14);
  v13[6] = v14;
  _ctor(v13, 0);
  v6[4] = v13;
  if (v13)
  {
    v16 = *v13;
    if (*(*v13 + 288) < typeHierarchyDepth || *(*(v16 + 200) + 8 * typeHierarchyDepth - 8) != pbMyChar_t)
    {
      sub_8FC2C0(*(v16 + 64), pbMyChar_t, v69);
      if ((v69[0] & 1) != 0)
        v18 = v69[2];
      else
        v18 = v69 + 1;
      v19 = sub_8C4940(v18);
    }
  }
  dds3SetProcessData(v6 + 2, v6);
  v13[2] = 1;
  *(v13 + 6) = -1;
  sub_854930((v13 + 4), 0);
  sub_854930((v13 + 4), 2u);
  sub_854930((v13 + 4), 3u);
  v13[6] = mdlLoad(6, 336, 0, 0, 0);
  v21 = (v13 + 6);
  mdlLoopMotion(v13 + 6, 0, 0);
  if (op_Inequality(pModelObj, 0, 0))
  {
    v27 = pModelObj;
    Destroy_27360000(v27);
    pModelObj = 0;
    SetActive(kernelObject->btldevil, 0, 0);
  }
  akey = devilModelFileTable->m_Items[336]->akey;
  fname = devilModelFileTable->m_Items[336]->fname;
  btldevil = kernelObject->btldevil;
  SetActive(btldevil, 1, 0);
  asset_bc = get_asset_bc();
  v38 = Concat_5224608("charactor/b/", fname);
  Prefab_16624656 = LoadPrefab_16624656(asset_bc, akey, v38, fname);
  transform = get_transform(btldevil, 0);
  v43 = Instantiate_object__425664(Prefab_16624656, transform, 0);
  pModelObj = v43;
  SetActive(pModelObj, 1, 0);
  v13[7] = pModelObj;
  *(*(v13[6] + 64) + 208LL) = pModelObj;
  v46 = get_transform(pModelObj, 0);
  Child = GetChild(v46, 0);
  gameObject = get_gameObject(Child);
  v49 = get_transform(gameObject, 0);
  v51 = *&v68.x;
  v52 = v49;
  v53 = *&v68.z;
  *&v72.x = v51;
  *&v72.z = v53;
  v71 = op_Implicit_8738992(v72);
  set_localScale(v52, v71);
  v55 = get_transform(gameObject, 0);
  p_SDF_CC_NDNM = &SDF_CC_NDNM;
  v58 = p_SDF_CC_NDNM[2];
  v59 = p_SDF_CC_NDNM[3];
  v60 = p_SDF_CC_NDNM[4];
  v61 = p_SDF_CC_NDNM[5];
  v62 = get_transform(gameObject, 0);
  localRotation = get_localRotation(v62);
  v73.x = v58;
  v73.y = v59;
  v73.z = v60;
  v73.w = v61;
  v74 = op_Multiply(v73, localRotation, 0);
  set_localRotation(v55, v74);
  v65 = pModelObj;
  mdlSetHD(v65, 3, 0, 15);
  Component_object = GetComponent_object_(pModelObj);
  SetFrameAnime(Component_object, 1);
  ScaleCharflag = 0;
  SDF_VU0__LOADVECTOR(v68);
  mdlSetScale(v21);
  mdlSetEffectScale(v21, 100.0);
  return v6;
}

// 0x14afd90
void pbMoveMyCharcter(pbProcHandle_t **p, f32 x, f32 y) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s64 v10;
  u64 v11[3];

  data = (*p)->data;
  if (data)
  {
    klass = data->klass;
    if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbMyChar_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbMyChar_t, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  if (*p)
  {
    v10 = &data[2];
    sub_854710(&data[2], 0);
    sub_854930(v10, 0);
    sub_854710(v10, 2u);
    sub_854930(v10, 2u);
  }
}

// 0x14afee0
void pbMoveMyCharcter2(pbProcHandle_t **p, s16 x, s16 y) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u64 v12[3];

  data = (*p)->data;
  if (data)
  {
    klass = data->klass;
    if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbMyChar_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbMyChar_t, v12);
      if ((v12[0] & 1) != 0)
        v10 = v12[2];
      else
        v10 = v12 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  if (*p)
  {
    WORD2(data[1].klass) += x;
    HIWORD(data[1].klass) += y;
  }
}

// 0x14afb40
u32 pbMyCharacterDispStat(pbProcHandle_t **p) {
  u32 *data;
  s64 v4;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 v9[3];

  data = (*p)->data;
  if (data)
  {
    v4 = *data;
    if (*(*data + 288LL) < typeHierarchyDepth || *(*(v4 + 200) + 8 * typeHierarchyDepth - 8) != pbMyChar_t)
    {
      sub_8FC2C0(*(v4 + 64), pbMyChar_t, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  if (*p)
    return data[4];
  else
    return 0;
}

// 0x14aeca0
void pbSetModelPos(dds3ModelHandle_t *aHandle, sdfVector4_t *pos) {
  dds3ModelHandle_t_o *aHandlea;

  aHandlea = aHandle;
  SDF_VU0__LOADVECTOR(*pos);
  mdlSetPosition(&aHandlea);
}

// 0x14af030
void pbSetModelRot(dds3ModelHandle_t *aHandle, f32 x, f32 y, f32 z) {
  dds3ModelHandle_t_o *aHandlea;

  aHandlea = aHandle;
  FromEuler(x, y, z);
  mdlSetRotate(&aHandlea);
}

// 0x14af0f0
void pbSetModelScl(dds3ModelHandle_t *aHandle, sdfVector4_t *scl) {
  ;
}

// 0x14b0000
void pbSetMyCharcterPos2(pbProcHandle_t **p, s16 x, s16 y) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  s64 v12;
  u64 v13[3];

  data = (*p)->data;
  if (data)
  {
    klass = data->klass;
    if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbMyChar_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbMyChar_t, v13);
      if ((v13[0] & 1) != 0)
        v10 = v13[2];
      else
        v10 = v13 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  if (*p)
  {
    WORD2(data[1].klass) = x;
    HIWORD(data[1].klass) = y;
    v12 = &data[2];
    sub_854930(&data[2], 0);
    sub_854930(v12, 2u);
  }
}

// 0x14b04b0
void pbSetMyCharcterRot(pbProcHandle_t **p, s32 dir) {
  Il2CppObject *data;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *v10;
  Il2CppObject *MyCharRootNode;
  Il2CppClass *v14;
  s64 v15;
  char *v16;
  s64 *v17;
  struct System_Single_array *dir_rot;
  f32 v21;
  dds3ModelHandle_t_o *aHandle[2];
  char *v25;

  data = (*p)->data;
  if (data)
  {
    klass = data->klass;
    if (data->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != pbMyChar_t)
    {
      sub_8FC2C0(klass->_1.element_class, pbMyChar_t, aHandle);
      if ((aHandle[0] & 1) != 0)
        v8 = v25;
      else
        v8 = aHandle + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(dds3ModelHandle_t);
  dds3ModelHandle_t___ctor(v10);
  if (*p)
  {
    else
    {
      MyCharRootNode = pbGetMyCharRootNode(p);
      if (MyCharRootNode)
      {
LABEL_14:
        v14 = MyCharRootNode->klass;
        if (MyCharRootNode->klass->_2.typeHierarchyDepth < v15
          || v14->_2.typeHierarchy[v15 - 1] != dds3ModelHandle_t)
        {
          sub_8FC2C0(v14->_1.element_class, dds3ModelHandle_t, aHandle);
          if ((aHandle[0] & 1) != 0)
            v16 = v25;
          else
            v16 = aHandle + 1;
          v17 = sub_8C4940(v16);
        }
      }
    }
    v21 = dir_rot->m_Items[dir];
    aHandle[0] = MyCharRootNode;
    FromEuler(0.0, v21, 0.0);
    mdlSetRotate(aHandle);
    LODWORD(data[1].monitor) = dir;
  }
}

// 0x14ac7c0
void sdfChipFreeDelayed(void *aPtr) {
  ;
}
