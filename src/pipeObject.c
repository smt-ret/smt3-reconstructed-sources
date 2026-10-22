#include "types.h"

typedef struct AnimChecker AnimChecker;
typedef struct PIPE_EFF_t PIPE_EFF_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct mnMyLink_h_tagPipeLinkData mnMyLink_h_tagPipeLinkData;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfMotionCtrlr_t sdfMotionCtrlr_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;
typedef struct tagMakaObject tagMakaObject;
typedef struct tagPipeEnemyInfo tagPipeEnemyInfo;
typedef struct tagPipeObject tagPipeObject;
typedef struct tagPipePartsInfo tagPipePartsInfo;
typedef struct tagPipeTexture tagPipeTexture;
typedef struct tagpipeBasic tagpipeBasic;
typedef struct tagpipeParts tagpipeParts;

static void *basicMyAnm;
static AnimChecker *basicMyChk;
static tagpipeParts *PartsWork[20];
static tagpipeBasic *PipeCur[10];
static tagpipeBasic *PipeCur2[10];
static tagpipeBasic *PipeLine[10];
static tagPipeObject *ObjWork[150];
static tagpipeBasic *basicMy[1];
static tagpipeBasic *MyLine[1];
static tagpipeBasic *PipeEMS[50];
static tagpipeBasic *PipeEML[50];
static tagpipeBasic *PipeRBOX[10];
static tagpipeBasic *PipeMaka1[50];
static tagpipeBasic *PipeZMaka[2];
static tagpipeBasic *PipeDMaka[4];
static tagpipeBasic *PipeDRBOX[2];
static tagPipeTexture *MakaTex[4];
static tagMakaObject *makaWork[15];
static PIPE_EFF_t *pipe_CELL01_D3P[10];
static PIPE_EFF_t *pipe_BREAK01_D3P[10];
static PIPE_EFF_t *pipe_BREAK02_D3P[10];
static PIPE_EFF_t *pipe_DAMAGE01_D3P[10];
static PIPE_EFF_t *pipe_DAMAGE03_D3P[10];
static PIPE_EFF_t *pipe_ATTACK01_D3P[5];
static sdfMemHandle_t *hWorkArea;
static void *WorkAreaPtr;

void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
void InitModel(tagpipeBasic *pModel, s32 mNum, s32 mPtn, s32 motion, f32 frm1, f32 frm2, f32 speed, char *name);
void Initmymdl(void);
void MatRotateX(sdfMatrix4_t **pmat, f32 Radian);
void MatRotateY(sdfMatrix4_t **pmat, f32 Radian);
void MatRotateZ(sdfMatrix4_t **pmat, f32 Radian);
void MatTrPos(sdfMatrix4_t **pmat, sdfMatrix4_t *amat);
void PipemdlRot(tagpipeBasic *pWork, tagPipePartsInfo *pInfo);
void QurtFromMatrix(sdfVector4_t *q, sdfMatrix4_t *mat);
f32 SDF_DEGtoRAD(f32 n);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SetMdlRotation(tagpipeBasic **pWork);
void SetVec(sdfVector4_t *pVec, f32 x, f32 y, f32 z);
f32 VecNormalize(sdfVector4_t *pVec);
void VecRotateZ(sdfVector4_t *pVec, f32 Radian);
void VecZoom(sdfVector4_t *pVec, f32 s);
void Veccross(sdfVector4_t *vec, sdfVector4_t vec1, sdfVector4_t vec2);
u32 dds3GetRandA(char *name);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void dds3UnitObjectBasicSetOt(dds3Basic_t **aPtr, s32 idx);
void eglLinkTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
void eglSetOt(s32 ot);
tagPipePartsInfo *getPartsInfo(s16 partsID);
void getPosTranslate(tagPipeObject *objPtr, sdfVector4_t *pos);
u32 mdlGetColor(dds3ModelHandle_t **aHandle);
sdfMotionCtrlr_t *mdlGetMotionCtrlr(dds3ModelHandle_t **aHandle, s32 aGroup);
void mdlSetColor(dds3ModelHandle_t **aHandle, u32 aColor);
void mdlSmoothLoopMotion(dds3ModelHandle_t **aHandle, s32 aGroup, s32 aNumber, f32 aBeforeLeng, f32 aSmoothLeng);
void mdlTask(tagPipeObject *objPtr, tagpipeBasic *basicPtr, f32 x, f32 y, f32 z);
s16 mymdlAddObject(tagpipeBasic **pWork, u16 mdlSize);
void mymdlInit(tagpipeBasic **pWork, f32 sclx, f32 scly, f32 sclz, f32 sclw, u16 mdlSize);
void mymdlInitObject(tagpipeBasic **pWork, u16 mdlSize);
void mymdlPosSet(tagpipeBasic *pWork, f32 x, f32 y, f32 z);
void mymdlSclSet(tagpipeBasic *pWork, f32 scl);
void mymdlVisible(tagpipeBasic *pWork, s8 value);
s32 objAdd(tagPipeObject *objPtr);
void objCopy2(s32 offset, f32 x, f32 y, u8 id, u8 action, s16 count, s16 num, s32 w);
tagPipeEnemyInfo *objInfo(s32 id);
u8 objMake(tagPipeObject *objPtr, s32 offset, u8 id, u8 way, u8 action, u8 value);
void objMdlAdd(tagPipeObject *objPtr);
void objMdlAlphaSet(tagPipeObject *objPtr, u8 alpha);
void objMdlDel(tagPipeObject *objPtr);
void objMdlMotion(tagPipeObject *objPtr, s32 motion, f32 speed);
void objMdlSclSet(tagPipeObject *objPtr, f32 scl);
tagPipeObject *objMyData(void);
void objMyLoad(tagPipeObject *objPtr);
void objOptionInc(tagPipeObject *objPtr, u8 op);
void partsInit(void);
void pipeBulrSetLimit(s32 frame);
void pipeEffSet(tagPipeObject *objPtr, u8 effNum);
void sdfTexFreeDelayed(sdfTexHandle_t *aHandle);
sdfTexHandle_t *sdfTexSet(void *aTex);

// 0x153a060
void InitLoadModel(void) {
  struct tagpipeBasic_array *basicMy;
  struct tagpipeBasic_array *MyLine;
  struct tagpipeBasic_array *v9;
  dds3Basic_t_o **p_basic;
  u64 i;
  struct tagpipeBasic_array *PipeMaka1;
  tagpipeBasic_o *v17;
  u64 *v18;
  System_String_o *v19;
  struct tagpipeBasic_array *v22;
  tagpipeBasic_o *v23;
  dds3ModelHandle_t_o **p_model;
  struct tagpipeBasic_array *PipeZMaka;
  tagpipeBasic_o *v29;
  u64 *v30;
  System_String_o *v31;
  struct tagpipeBasic_array *v34;
  tagpipeBasic_o *v35;
  dds3ModelHandle_t_o **v37;
  struct tagpipeBasic_array *v41;
  tagpipeBasic_o *v43;
  u64 *v44;
  System_String_o *v45;
  struct tagpipeBasic_array *v48;
  tagpipeBasic_o *v49;
  dds3ModelHandle_t_o **v51;
  struct tagpipeBasic_array *PipeDMaka;
  tagpipeBasic_o *v56;
  u64 *v57;
  System_String_o *v58;
  struct tagpipeBasic_array *v62;
  tagpipeBasic_o *v64;
  u64 *v65;
  System_String_o *v66;
  struct tagpipeBasic_array *v70;
  tagpipeBasic_o *v72;
  u64 *v73;
  System_String_o *v74;
  struct tagpipeBasic_array *v78;
  tagpipeBasic_o *v80;
  u64 *v81;
  System_String_o *v82;
  struct tagpipeBasic_array *PipeDRBOX;
  tagpipeBasic_o *v87;
  u64 *v88;
  System_String_o *v89;
  struct tagpipeBasic_array *v93;
  tagpipeBasic_o *v95;
  u64 *v96;
  System_String_o *v97;
  s64 j;
  u64 v102;
  struct tagpipeBasic_array *PipeLine;
  tagpipeBasic_o *v105;
  u64 *v106;
  System_String_o *v107;
  struct tagpipeBasic_array *PipeCur;
  tagpipeBasic_o *v111;
  u64 *v112;
  System_String_o *v113;
  struct tagpipeBasic_array *PipeCur2;
  tagpipeBasic_o *v117;
  u64 *v118;
  System_String_o *v119;
  u64 k;
  struct tagpipeBasic_array *PipeRBOX;
  tagpipeBasic_o *v125;
  u64 *v126;
  System_String_o *v127;
  u64 m;
  struct tagpipeBasic_array *PipeEMS;
  tagpipeBasic_o *v133;
  u64 *v134;
  System_String_o *v135;
  u64 v137;
  u64 v138;
  s32 v139;
  s64 v140;
  tagpipeBasic_o *v142;
  u64 *v143;
  System_String_o *v144;
  u32 v146;
  s32 v147;
  s32 v148;
  s32 v149;

  else
  {
    if (!LODWORD(basicMy->max_length))
      goto LABEL_6;
  }
  InitModel(basicMy->m_Items[0], 2, 16, 1, 1.0, 1.0, 1.0, "Player");
  InitModel(MyLine->m_Items[0], 2, 32, 0, 1.0, 1.0, 1.0, "MyLine");
  v9 = MyLine;
  p_basic = &v9->m_Items[0]->basic;
  dds3UnitObjectBasicSetOt(p_basic, 7);
  for (i = 0; i != 50; ++i)
  {
    v17 = PipeMaka1->m_Items[i];
    v149 = i;
    v18 = sub_8D3950(s32, &v149);
    v19 = Concat("PipeMaka1_", v18);
    InitModel(v17, 2, 13, 0, 1.0, 1.0, 1.0, v19);
    v22 = PipeMaka1;
    v23 = v22->m_Items[i];
    if ((byte_3F59CAB & 1) != 0)
    {
      p_model = &v23->model;
        goto LABEL_27;
    }
    else
    {
      p_model = &v23->model;
        goto LABEL_27;
    }
LABEL_27:
    mdlGetMotionCtrlr(p_model, 0);
  }
  else
  {
    if (!LODWORD(PipeZMaka->max_length))
      goto LABEL_31;
  }
  v29 = PipeZMaka->m_Items[0];
  v149 = 0;
  v30 = sub_8D3950(s32, &v149);
  v31 = Concat("PipeZMaka_", v30);
  InitModel(v29, 2, 14, 0, 1.0, 1.0, 1.0, v31);
  v34 = PipeZMaka;
  v35 = v34->m_Items[0];
  if ((byte_3F59CAB & 1) != 0)
  {
    v37 = &v35->model;
    {
LABEL_35:
    }
  }
  else
  {
    v37 = &v35->model;
      goto LABEL_35;
  }
  mdlGetMotionCtrlr(v37, 0);
  v41 = PipeZMaka;
  v43 = v41->m_Items[1];
  v149 = 1;
  v44 = sub_8D3950(s32, &v149);
  v45 = Concat("PipeZMaka_", v44);
  InitModel(v43, 2, 14, 0, 1.0, 1.0, 1.0, v45);
  v48 = PipeZMaka;
  v49 = v48->m_Items[1];
  if ((byte_3F59CAB & 1) != 0)
  {
    v51 = &v49->model;
    {
LABEL_47:
    }
  }
  else
  {
    v51 = &v49->model;
      goto LABEL_47;
  }
  mdlGetMotionCtrlr(v51, 0);
  else
  {
    if (!LODWORD(PipeDMaka->max_length))
      goto LABEL_54;
  }
  v56 = PipeDMaka->m_Items[0];
  v149 = 0;
  v57 = sub_8D3950(s32, &v149);
  v58 = Concat("PipeDMaka_", v57);
  InitModel(v56, 2, 21, 0, 1.0, 1.0, 1.0, v58);
  v62 = PipeDMaka;
  v64 = v62->m_Items[1];
  v149 = 1;
  v65 = sub_8D3950(s32, &v149);
  v66 = Concat("PipeDMaka_", v65);
  InitModel(v64, 2, 21, 0, 1.0, 1.0, 1.0, v66);
  v70 = PipeDMaka;
  v72 = v70->m_Items[2];
  v149 = 2;
  v73 = sub_8D3950(s32, &v149);
  v74 = Concat("PipeDMaka_", v73);
  InitModel(v72, 2, 21, 0, 1.0, 1.0, 1.0, v74);
  v78 = PipeDMaka;
  v80 = v78->m_Items[3];
  v149 = 3;
  v81 = sub_8D3950(s32, &v149);
  v82 = Concat("PipeDMaka_", v81);
  InitModel(v80, 2, 21, 0, 1.0, 1.0, 1.0, v82);
  else
  {
    if (!LODWORD(PipeDRBOX->max_length))
      goto LABEL_73;
  }
  v87 = PipeDRBOX->m_Items[0];
  v149 = 0;
  v88 = sub_8D3950(s32, &v149);
  v89 = Concat("PipeDRBOX_", v88);
  InitModel(v87, 2, 33, 0, 1.0, 1.0, 1.0, v89);
  v93 = PipeDRBOX;
  v95 = v93->m_Items[1];
  v149 = 1;
  v96 = sub_8D3950(s32, &v149);
  v97 = Concat("PipeDRBOX_", v96);
  InitModel(v95, 2, 33, 0, 1.0, 1.0, 1.0, v97);
  for (j = 4; j != 14; ++j)
  {
    v102 = j - 4;
    v105 = *(&PipeLine->obj.klass + j);
    v149 = j - 4;
    v106 = sub_8D3950(s32, &v149);
    v107 = Concat("PipeLine_", v106);
    InitModel(v105, 2, 8, 0, 1.0, 1.0, 1.0, v107);
    v111 = *(&PipeCur->obj.klass + j);
    v148 = j - 4;
    v112 = sub_8D3950(s32, &v148);
    v113 = Concat("PipeCur_", v112);
    InitModel(v111, 2, 10, 0, 1.0, 1.0, 1.0, v113);
    v117 = *(&PipeCur2->obj.klass + j);
    v147 = j - 4;
    v118 = sub_8D3950(s32, &v147);
    v119 = Concat("PipeCur2_", v118);
    InitModel(v117, 2, 9, 0, 1.0, 1.0, 1.0, v119);
  }
  for (k = 0; k != 10; ++k)
  {
    v125 = PipeRBOX->m_Items[k];
    v149 = k;
    v126 = sub_8D3950(s32, &v149);
    v127 = Concat("PipeRBOX_", v126);
    InitModel(v125, 2, 15, -1, 1.0, 1.0, 1.0, v127);
  }
  for (m = 0; m != 50; ++m)
  {
    v133 = PipeEMS->m_Items[m];
    v149 = m;
    v134 = sub_8D3950(s32, &v149);
    v135 = Concat("PipeEMS_", v134);
    InitModel(v133, 2, 12, -1, 1.0, 1.0, 1.0, v135);
  }
  v138 = 0;
  do
  {
    v140 = *(*(v137 + 184) + 80LL);
    v142 = *(v140 + 8 * v138 + 32);
    v149 = v138;
    v143 = sub_8D3950(s32, &v149);
    v144 = Concat("PipeEML_", v143);
    InitModel(v142, 2, 11, -1, 1.0, 1.0, 1.0, v144);
    ++v138;
    v139 = (v146 >> 9) & 1;
  }
  while (v138 != 50);
  Initmymdl(v137);
}

// 0x1539f30
void Initmymdl(void) {
  mymdlInitObject(PipeLine, 0xAu);
  mymdlInitObject(PipeCur, 0xAu);
  mymdlInitObject(PipeCur2, 0xAu);
  mymdlInitObject(PipeRBOX, 0xAu);
  mymdlInitObject(PipeEMS, 0x32u);
  mymdlInitObject(PipeEML, 0x32u);
  mymdlInitObject(PipeMaka1, 0x32u);
  mymdlInitObject(PipeZMaka, 2u);
  mymdlInitObject(PipeDMaka, 4u);
  mymdlInitObject(PipeDRBOX, 2u);
}

// 0x1541460
bool PipeTexLoad(void) {
  return 1;
}

// 0x1541470
bool PipeTexRelease(void) {
  struct tagPipeTexture_array *MakaTex;
  tagPipeTexture_o *v4;
  sdfTexHandle_t_o *th;
  struct tagPipeTexture_array *v8;
  tagPipeTexture_o *v9;
  sdfTexHandle_t_o *v10;
  struct tagPipeTexture_array *v13;
  tagPipeTexture_o *v14;
  sdfTexHandle_t_o *v15;
  struct tagPipeTexture_array *v18;
  tagPipeTexture_o *v19;
  sdfTexHandle_t_o *v20;

  v4 = MakaTex->m_Items[0];
  if ((byte_3F59CBB & 1) != 0)
  {
    th = v4->th;
    if (!th)
      goto LABEL_9;
  }
  else
  {
    th = v4->th;
    if (!th)
    {
LABEL_9:
        goto LABEL_18;
      goto LABEL_10;
    }
  }
  sdfTexFreeDelayed(th);
  v4->th = 0;
  {
LABEL_10:
  }
LABEL_18:
  v8 = MakaTex;
  v9 = v8->m_Items[1];
  if ((byte_3F59CBB & 1) != 0)
  {
    v10 = v9->th;
    if (!v10)
      goto LABEL_21;
  }
  else
  {
    v10 = v9->th;
    if (!v10)
    {
LABEL_21:
        goto LABEL_30;
      goto LABEL_22;
    }
  }
  sdfTexFreeDelayed(v10);
  v9->th = 0;
  {
LABEL_22:
  }
LABEL_30:
  v13 = MakaTex;
  v14 = v13->m_Items[2];
  if ((byte_3F59CBB & 1) != 0)
  {
    v15 = v14->th;
    if (!v15)
      goto LABEL_33;
  }
  else
  {
    v15 = v14->th;
    if (!v15)
    {
LABEL_33:
        goto LABEL_42;
      goto LABEL_34;
    }
  }
  sdfTexFreeDelayed(v15);
  v14->th = 0;
  {
LABEL_34:
  }
LABEL_42:
  v18 = MakaTex;
  v19 = v18->m_Items[3];
  if ((byte_3F59CBB & 1) != 0)
  {
    v20 = v19->th;
    if (!v20)
      return 1;
  }
  else
  {
    v20 = v19->th;
    if (!v20)
      return 1;
  }
  sdfTexFreeDelayed(v20);
  v19->th = 0;
  return 1;
}

// 0x1540f20
void PipemdlRot(tagpipeBasic *pWork, tagPipePartsInfo *pInfo) {
  f32 v5;
  s32 goWay;
  char v8;
  f32 v9;
  f32 v10;
  s32 v11;
  char v12;
  bool v13;
  f32 v14;
  s32 v15;
  char v16;
  f32 v17;
  char v18;
  s32 v19;
  char v20;
  s32 v21;
  s64 v22;
  char *v23;
  f32 v24;
  f32 v25;
  f32 v26;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  tagpipeBasic_o *pWorka;
  UnityEngine_Vector4_o v34;
  UnityEngine_Vector4_o v35;

  pWorka = pWork;
  v5 = 0.0;
  v34.x = 0.0;
  v34.y = 0.0;
  v34.z = 0.0;
  v34.w = 0.0;
  SDF_VU0__LOADVECTOR(v34);
  switch (pInfo->inWay)
  {
    case 1u:
      goWay = pInfo->goWay;
      v8 = goWay - 2;
      if ((goWay - 2) < 5 && ((0x17u >> v8) & 1) != 0)
      {
        v10 = flt_33CD044[v8];
        v9 = 0.0;
      }
      else
      {
        v9 = 0.0;
        v5 = 0.0;
        if (goWay == 5)
          v10 = -180.0;
        else
          v10 = 0.0;
      }
      break;
    case 2u:
      v11 = pInfo->goWay;
      v12 = v11 - 1;
      if ((v11 - 1) >= 6 || ((0x2Du >> v12) & 1) == 0)
      {
        v13 = v11 == 5;
        v14 = -90.0;
        goto LABEL_27;
      }
      v22 = 4LL * v12;
      v9 = *(&unk_33CD088 + v22);
      v10 = *(&unk_33CD0A0 + v22);
      v23 = &unk_33CD0B8;
      goto LABEL_43;
    case 3u:
      v15 = pInfo->goWay;
      v16 = v15 - 1;
      if ((v15 - 1) >= 6 || ((0x2Bu >> v16) & 1) == 0)
      {
        v17 = 90.0;
        goto LABEL_18;
      }
      v10 = 0.0;
      v5 = flt_33CD058[v16];
      v9 = 90.0;
      break;
    case 4u:
      v15 = pInfo->goWay;
      v18 = v15 - 1;
      if ((v15 - 1) < 6 && ((0x27u >> v18) & 1) != 0)
      {
        v10 = 0.0;
        v5 = flt_33CD070[v18];
        v9 = -90.0;
      }
      else
      {
        v17 = -90.0;
LABEL_18:
        v10 = 0.0;
        if (v15 == 5)
          v9 = v17;
        else
          v9 = 0.0;
        if (v15 == 5)
          v5 = 180.0;
        else
          v5 = 0.0;
      }
      break;
    case 5u:
      v19 = pInfo->goWay;
      v20 = v19 - 1;
      if ((v19 - 1) < 6 && ((0x2Du >> v20) & 1) != 0)
      {
        v22 = 4LL * v20;
        v9 = *(&unk_33CD0D0 + v22);
        v10 = *(&unk_33CD0E8 + v22);
        v23 = &unk_33CD100;
        goto LABEL_43;
      }
      v13 = v19 == 2;
      v14 = 90.0;
LABEL_27:
      v9 = 0.0;
      if (v13)
        v5 = v14;
      else
        v5 = 0.0;
      v10 = 0.0;
      break;
    case 6u:
      v21 = pInfo->goWay;
      if ((v21 - 1) >= 4)
      {
        v5 = 0.0;
        if (v21 == 5)
          v9 = 180.0;
        else
          v9 = 0.0;
        v10 = v9;
      }
      else
      {
        v22 = 4LL * (v21 - 1);
        v9 = *(&unk_32C3BB0 + v22);
        v10 = *(&unk_32C3BC0 + v22);
        v23 = &unk_32C3BD0;
LABEL_43:
        v5 = *&v23[v22];
      }
      break;
    default:
      v9 = 0.0;
      v10 = 0.0;
      break;
  }
  v24 = SDF_DEGtoRAD(v5);
  v25 = SDF_DEGtoRAD(v10);
  v26 = SDF_DEGtoRAD(v9);
  FromEuler(v24, v25, v26);
  SDF_VU0__STOREVECTOR(&pWork->rot);
  x = pWork->rot.x;
  y = pWork->rot.y;
  z = pWork->rot.z;
  w = pWork->rot.w;
  v35.x = x;
  v35.y = y;
  v35.z = z;
  v35.w = w;
  dds3SetRotPoseSet(&pWork->basic, v35);
  SetMdlRotation(&pWorka);
}

// 0x153acf0
void getPosTranslate(tagPipeObject *objPtr, sdfVector4_t *pos) {
  struct tagPipePosData_array *pData;
  s64 v7;
  struct tagPipePosData_array *v9;
  s64 offset;
  f32 v11;
  f32 v12;
  struct tagPipePosData_array *v14;
  s64 v15;
  f32 v16;
  f32 v17;
  struct tagPipePosData_array *v19;
  s64 v20;
  f32 v21;
  f32 v22;
  struct tagPipePosData_array *v24;
  s64 v25;
  f32 v26;
  f32 v27;
  struct tagPipePosData_array *v29;
  s64 v30;
  f32 v31;
  f32 v32;
  f32 v34;
  struct tagPipePosData_array *v35;
  s64 v36;
  struct tagPipePosData_array *v38;
  s64 v39;
  f32 v40;
  f32 v41;
  struct tagPipePosData_array *v43;
  s64 v44;
  f32 v45;
  f32 v46;
  f32 v48;
  f32 v49;
  f32 v50;
  struct tagPipePosData_array *v51;
  s64 v52;
  struct tagPipePosData_array *v54;
  s64 v55;
  struct tagPipePosData_array *v57;
  s64 v58;
  UnityEngine_Vector4_o v60;
  UnityEngine_Vector4_o vec;
  UnityEngine_Vector4_o pVec;

  *&pVec.x = 0;
  *&pVec.z = 0;
  *&vec.x = 0;
  *&vec.z = 0;
  *&v60.x = 0;
  *&v60.z = 0;
  pData = PosTable->pData;
  v7 = objPtr->offset + 1LL;
  sub_854710(&pData->m_Items[v7]->fields, 0);
  v9 = PosTable->pData;
  offset = objPtr->offset;
  v12 = v11;
  sub_854710(&v9->m_Items[offset]->fields, 0);
  v14 = PosTable->pData;
  v15 = objPtr->offset + 1LL;
  v17 = v16;
  sub_854710(&v14->m_Items[v15]->fields, 1u);
  v19 = PosTable->pData;
  v20 = objPtr->offset;
  v22 = v21;
  sub_854710(&v19->m_Items[v20]->fields, 1u);
  v24 = PosTable->pData;
  v25 = objPtr->offset + 1LL;
  v27 = v26;
  sub_854710(&v24->m_Items[v25]->fields, 2u);
  v29 = PosTable->pData;
  v30 = objPtr->offset;
  v32 = v31;
  sub_854710(&v29->m_Items[v30]->fields, 2u);
  SetVec(&pVec, v12 - v17, v22 - v27, v32 - v34);
  v35 = PosTable->pData;
  v36 = objPtr->offset;
  sub_854710(&v35->m_Items[v36]->up, 0);
  v38 = PosTable->pData;
  v39 = objPtr->offset;
  v41 = v40;
  sub_854710(&v38->m_Items[v39]->up, 1u);
  v43 = PosTable->pData;
  v44 = objPtr->offset;
  v46 = v45;
  sub_854710(&v43->m_Items[v44]->up, 2u);
  SetVec(&v60, v41, v46, v48);
  Veccross(&vec, pVec, v60);
  VecNormalize(&vec);
  v49 = sub_851730(&objPtr->pos, 0);
  VecZoom(&vec, v49);
  v50 = sub_851730(&objPtr->pos, 1);
  VecZoom(&v60, v50);
  v51 = PosTable->pData;
  v52 = objPtr->offset;
  sub_854710(&v51->m_Items[v52]->fields, 0);
  sub_854710(&vec, 0);
  sub_854710(&v60, 0);
  sub_854930(pos, 0);
  v54 = PosTable->pData;
  v55 = objPtr->offset;
  sub_854710(&v54->m_Items[v55]->fields, 1u);
  sub_854710(&vec, 1u);
  sub_854710(&v60, 1u);
  sub_854930(pos, 1u);
  v57 = PosTable->pData;
  v58 = objPtr->offset;
  sub_854710(&v57->m_Items[v58]->fields, 2u);
  sub_854710(&vec, 2u);
  sub_854710(&v60, 2u);
  sub_854930(pos, 2u);
}

// 0x153f0b0
void mdlTask(tagPipeObject *objPtr, tagpipeBasic *basicPtr, f32 x, f32 y, f32 z) {
  u64 *v11;
  struct tagPipePosData_array *pData;
  s64 offsetCount;
  struct tagPipePosData_array *v21;
  s64 v22;
  struct tagPipePosData_array *v25;
  s64 v26;
  struct tagPipePosData_array *v29;
  s64 v30;
  struct tagPipePosData_array *v33;
  s64 v34;
  struct tagPipePosData_array *v37;
  s64 v38;
  struct tagPipePosData_array *v41;
  s64 v42;
  struct tagPipePosData_array *v45;
  s64 v46;
  struct tagPipePosData_array *v49;
  s64 v50;
  sdfMatrix4_t_o *v52;
  f32 v53;
  f32 v54;
  f32 v55;
  f32 v56;
  f32 v57;
  f32 v58;
  f32 v59;
  f32 v60;
  f32 v62;
  f32 v63;
  f32 v64;
  f32 v65;
  f32 v67;
  f32 v68;
  f32 w;
  f32 v70;
  sdfMatrix4_t_o *amat;
  UnityEngine_Vector4_o pos;
  UnityEngine_Vector4_o v74;
  UnityEngine_Vector4_o pVec;
  UnityEngine_Vector4_o vec;
  tagpipeBasic_o *pWork;
  UnityEngine_Vector4_o v78;

  pWork = basicPtr;
  *&vec.x = 0;
  *&vec.z = 0;
  *&pVec.x = 0;
  *&pVec.z = 0;
  *&v74.x = 0;
  *&v74.z = 0;
  *&pos.x = 0;
  *&pos.z = 0;
  v11 = Allocate(sdfMatrix4_t);
  sdfMatrix4_t___ctor(v11);
  amat = v11;
  getPosTranslate(objPtr, &pos);
  pData = PosTable->pData;
  sub_854710(&pData->m_Items[offsetCount]->up, 0);
  sub_854930(&v74, 0);
  v21 = PosTable->pData;
  v22 = offsetCount;
  sub_854710(&v21->m_Items[v22]->up, 1u);
  sub_854930(&v74, 1u);
  v25 = PosTable->pData;
  v26 = offsetCount;
  sub_854710(&v25->m_Items[v26]->up, 2u);
  sub_854930(&v74, 2u);
  v29 = PosTable->pData;
  v30 = offsetCount + 1LL;
  sub_854710(&v29->m_Items[v30]->fields, 0);
  v33 = PosTable->pData;
  v34 = offsetCount;
  sub_854710(&v33->m_Items[v34]->fields, 0);
  sub_854930(&pVec, 0);
  v37 = PosTable->pData;
  v38 = offsetCount + 1LL;
  sub_854710(&v37->m_Items[v38]->fields, 1u);
  v41 = PosTable->pData;
  v42 = offsetCount;
  sub_854710(&v41->m_Items[v42]->fields, 1u);
  sub_854930(&pVec, 1u);
  v45 = PosTable->pData;
  v46 = offsetCount + 1LL;
  sub_854710(&v45->m_Items[v46]->fields, 2u);
  v49 = PosTable->pData;
  v50 = offsetCount;
  sub_854710(&v49->m_Items[v50]->fields, 2u);
  sub_854930(&pVec, 2u);
  Veccross(&vec, pVec, v74);
  VecNormalize(&vec);
  VecNormalize(&pVec);
  VecNormalize(&v74);
  v52 = amat;
  sub_854710(&vec, 0);
  amat->pm.m00 = v53;
  sub_854710(&vec, 1u);
  v52->pm.m01 = v54;
  sub_854710(&vec, 2u);
  v52->pm.m02 = v55;
  sub_854710(&pVec, 0);
  v52->pm.m10 = v56;
  sub_854710(&pVec, 1u);
  v52->pm.m11 = v57;
  sub_854710(&pVec, 2u);
  v52->pm.m12 = v58;
  sub_854710(&v74, 0);
  v52->pm.m20 = v59;
  sub_854710(&v74, 1u);
  v52->pm.m21 = v60;
  sub_854710(&v74, 2u);
  v52->pm.m22 = v62;
  v52->pm.m33 = 1.0;
  v63 = SDF_DEGtoRAD(x);
  MatRotateX(&amat, v63);
  v64 = SDF_DEGtoRAD(y);
  MatRotateY(&amat, v64);
  v65 = SDF_DEGtoRAD(z);
  MatRotateZ(&amat, v65);
  MatTrPos(&amat, amat);
  QurtFromMatrix(&basicPtr->rot, amat);
  v67 = basicPtr->rot.x;
  v68 = basicPtr->rot.y;
  v70 = basicPtr->rot.z;
  w = basicPtr->rot.w;
  v78.x = v67;
  v78.y = v68;
  v78.z = v70;
  v78.w = w;
  dds3SetRotPoseSet(&basicPtr->basic, v78);
  SetMdlRotation(&pWork);
}

// 0x1537fb0
void mymdlStartUp(void) {
  u64 *v1;
  u64 v3;
  u64 v4;
  s32 *v5;
  s32 *ObjWork;
  u64 *v7;
  u64 v10;
  s32 *v11;
  s32 *PipeCur;
  Il2CppObject *v13;
  u64 *v14;
  u64 v17;
  s32 *v18;
  s32 *PipeCur2;
  Il2CppObject *v20;
  u64 *v21;
  u64 v24;
  s32 *v25;
  s32 *PipeLine;
  Il2CppObject *v27;
  u64 *v28;
  u64 v31;
  s32 *v32;
  s32 *basicMy;
  Il2CppObject *v34;
  u64 *v35;
  u64 v38;
  s32 *v39;
  s32 *MyLine;
  Il2CppObject *v41;
  u64 *v42;
  u64 v45;
  s32 *v46;
  s32 *PipeEMS;
  Il2CppObject *v48;
  u64 *v49;
  u64 v52;
  s32 *v53;
  s32 *v54;
  Il2CppObject *v55;
  u64 *v56;
  u64 v59;
  s32 *v60;
  s32 *PipeRBOX;
  Il2CppObject *v62;
  u64 *v63;
  u64 v66;
  s32 *v67;
  s32 *PipeMaka1;
  Il2CppObject *v69;
  u64 *v70;
  u64 v73;
  s32 *v74;
  s32 *v75;
  Il2CppObject *v76;
  u64 *v77;
  u64 v80;
  s32 *v81;
  s32 *PipeDMaka;
  Il2CppObject *v83;
  u64 *v84;
  u64 v87;
  s32 *v88;
  s32 *PipeDRBOX;
  Il2CppObject *v90;
  u64 *v91;
  u64 v94;
  s32 *v95;
  s32 *PartsWork;
  Il2CppObject *v97;
  u64 v100;
  s32 *v101;
  s32 *MakaTex;
  Il2CppObject *v103;
  u64 *v104;
  u64 *v105;
  u64 v108;
  s32 *v109;
  s32 *makaWork;
  Il2CppObject *v111;
  u64 v114;
  s32 *v115;
  s32 *pipe_CELL01_D3P;
  Il2CppObject *v117;
  u64 *v118;
  u64 *v119;
  u64 v122;
  s32 *v123;
  s32 *pipe_DAMAGE01_D3P;
  Il2CppObject *v125;
  u64 *v126;
  u64 *v127;
  u64 v130;
  s32 *v131;
  s32 *pipe_DAMAGE03_D3P;
  Il2CppObject *v133;
  u64 *v134;
  u64 *v135;
  u64 v138;
  s32 *v139;
  s32 *pipe_BREAK01_D3P;
  Il2CppObject *v141;
  u64 *v142;
  u64 *v143;
  u64 v146;
  s32 *v147;
  s32 *pipe_BREAK02_D3P;
  Il2CppObject *v149;
  u64 *v150;
  u64 *v151;
  u64 v154;
  s16 v155;
  s32 *v156;
  s32 i;
  s32 *pipe_ATTACK01_D3P;
  Il2CppObject *v159;
  u64 *v160;
  u64 *v161;
  f32 v164;

  v1 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v1);
  *(*(v3 + 184) + 192LL) = v1;
  v4 = 0;
  if ((*(v3 + 295) & 2) != 0)
  {
LABEL_9:
  }
  while (1)
  {
    ObjWork = *(*(v3 + 184) + 48LL);
    if (v4 >= ObjWork[6])
      break;
    v7 = Allocate(tagPipeObject);
    _ctor(v7, 0);
    v5 = &ObjWork[2 * v4++];
    *(v5 + 4) = v7;
      goto LABEL_9;
  }
  v10 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_25;
LABEL_23:
LABEL_25:
  while (1)
  {
    PipeCur = *(*(v3 + 184) + 24LL);
    if (v10 >= PipeCur[6])
      break;
    v13 = Allocate(tagpipeBasic);
    v14 = Allocate(dds3ModelHandle_t);
    dds3ModelHandle_t___ctor(v14);
    v13[1].monitor = v14;
    v13[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v13, 0);
    v11 = &PipeCur[2 * v10++];
    *(v11 + 4) = v13;
      goto LABEL_23;
  }
  v17 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_41;
LABEL_39:
LABEL_41:
  while (1)
  {
    PipeCur2 = *(*(v3 + 184) + 32LL);
    if (v17 >= PipeCur2[6])
      break;
    v20 = Allocate(tagpipeBasic);
    v21 = Allocate(dds3ModelHandle_t);
    dds3ModelHandle_t___ctor(v21);
    v20[1].monitor = v21;
    v20[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v20, 0);
    v18 = &PipeCur2[2 * v17++];
    *(v18 + 4) = v20;
      goto LABEL_39;
  }
  v24 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_57;
LABEL_55:
LABEL_57:
  while (1)
  {
    PipeLine = *(*(v3 + 184) + 40LL);
    if (v24 >= PipeLine[6])
      break;
    v27 = Allocate(tagpipeBasic);
    v28 = Allocate(dds3ModelHandle_t);
    dds3ModelHandle_t___ctor(v28);
    v27[1].monitor = v28;
    v27[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v27, 0);
    v25 = &PipeLine[2 * v24++];
    *(v25 + 4) = v27;
      goto LABEL_55;
  }
  v31 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_73;
LABEL_71:
LABEL_73:
  while (1)
  {
    basicMy = *(*(v3 + 184) + 56LL);
    if (v31 >= basicMy[6])
      break;
    v34 = Allocate(tagpipeBasic);
    v35 = Allocate(dds3ModelHandle_t);
    dds3ModelHandle_t___ctor(v35);
    v34[1].monitor = v35;
    v34[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v34, 0);
    v32 = &basicMy[2 * v31++];
    *(v32 + 4) = v34;
      goto LABEL_71;
  }
  v38 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_89;
LABEL_87:
LABEL_89:
  while (1)
  {
    MyLine = *(*(v3 + 184) + 64LL);
    if (v38 >= MyLine[6])
      break;
    v41 = Allocate(tagpipeBasic);
    v42 = Allocate(dds3ModelHandle_t);
    dds3ModelHandle_t___ctor(v42);
    v41[1].monitor = v42;
    v41[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v41, 0);
    v39 = &MyLine[2 * v38++];
    *(v39 + 4) = v41;
      goto LABEL_87;
  }
  v45 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_105;
LABEL_103:
LABEL_105:
  while (1)
  {
    PipeEMS = *(*(v3 + 184) + 72LL);
    if (v45 >= PipeEMS[6])
      break;
    v48 = Allocate(tagpipeBasic);
    v49 = Allocate(dds3ModelHandle_t);
    dds3ModelHandle_t___ctor(v49);
    v48[1].monitor = v49;
    v48[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v48, 0);
    v46 = &PipeEMS[2 * v45++];
    *(v46 + 4) = v48;
      goto LABEL_103;
  }
  v52 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_121;
LABEL_119:
LABEL_121:
  while (1)
  {
    v54 = *(*(v3 + 184) + 72LL);
    if (v52 >= v54[6])
      break;
    if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
    {
      v54 = PipeEMS;
    }
    v55 = Allocate(tagpipeBasic);
    v56 = Allocate(dds3ModelHandle_t);
    dds3ModelHandle_t___ctor(v56);
    v55[1].monitor = v56;
    v55[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v55, 0);
    v53 = &v54[2 * v52++];
    *(v53 + 4) = v55;
      goto LABEL_119;
  }
  v59 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_137;
LABEL_135:
LABEL_137:
  while (1)
  {
    PipeRBOX = *(*(v3 + 184) + 88LL);
    if (v59 >= PipeRBOX[6])
      break;
    v62 = Allocate(tagpipeBasic);
    v63 = Allocate(dds3ModelHandle_t);
    dds3ModelHandle_t___ctor(v63);
    v62[1].monitor = v63;
    v62[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v62, 0);
    v60 = &PipeRBOX[2 * v59++];
    *(v60 + 4) = v62;
      goto LABEL_135;
  }
  v66 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_153;
LABEL_151:
LABEL_153:
  while (1)
  {
    PipeMaka1 = *(*(v3 + 184) + 96LL);
    if (v66 >= PipeMaka1[6])
      break;
    v69 = Allocate(tagpipeBasic);
    v70 = Allocate(dds3ModelHandle_t);
    dds3ModelHandle_t___ctor(v70);
    v69[1].monitor = v70;
    v69[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v69, 0);
    v67 = &PipeMaka1[2 * v66++];
    *(v67 + 4) = v69;
      goto LABEL_151;
  }
  v73 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_169;
LABEL_167:
LABEL_169:
  while (1)
  {
    v75 = *(*(v3 + 184) + 96LL);
    if (v73 >= v75[6])
      break;
    if ((*(v3 + 295) & 2) != 0 && !*(v3 + 216))
    {
      v75 = PipeMaka1;
    }
    v76 = Allocate(tagpipeBasic);
    v77 = Allocate(dds3ModelHandle_t);
    dds3ModelHandle_t___ctor(v77);
    v76[1].monitor = v77;
    v76[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v76, 0);
    v74 = &v75[2 * v73++];
    *(v74 + 4) = v76;
      goto LABEL_167;
  }
  v80 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_185;
LABEL_183:
LABEL_185:
  while (1)
  {
    PipeDMaka = *(*(v3 + 184) + 112LL);
    if (v80 >= PipeDMaka[6])
      break;
    v83 = Allocate(tagpipeBasic);
    v84 = Allocate(dds3ModelHandle_t);
    dds3ModelHandle_t___ctor(v84);
    v83[1].monitor = v84;
    v83[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v83, 0);
    v81 = &PipeDMaka[2 * v80++];
    *(v81 + 4) = v83;
      goto LABEL_183;
  }
  v87 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_201;
LABEL_199:
LABEL_201:
  while (1)
  {
    PipeDRBOX = *(*(v3 + 184) + 120LL);
    if (v87 >= PipeDRBOX[6])
      break;
    v90 = Allocate(tagpipeBasic);
    v91 = Allocate(dds3ModelHandle_t);
    dds3ModelHandle_t___ctor(v91);
    v90[1].monitor = v91;
    v90[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v90, 0);
    v88 = &PipeDRBOX[2 * v87++];
    *(v88 + 4) = v90;
      goto LABEL_199;
  }
  v94 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_217;
LABEL_215:
LABEL_217:
  while (1)
  {
    PartsWork = *(*(v3 + 184) + 16LL);
    if (v94 >= PartsWork[6])
      break;
    v97 = Allocate(tagpipeParts);
    v97[1].monitor = NewSpecific(sbyte, 5u);
    _ctor(v97, 0);
    v95 = &PartsWork[2 * v94++];
    *(v95 + 4) = v97;
      goto LABEL_215;
  }
  v100 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_233;
LABEL_231:
LABEL_233:
  while (1)
  {
    MakaTex = *(*(v3 + 184) + 128LL);
    if (v100 >= MakaTex[6])
      break;
    v103 = Allocate(tagPipeTexture);
    v104 = Allocate(sdfTexHandle_t);
    sdfTexHandle_t___ctor(v104);
    v103[1].klass = v104;
    v105 = Allocate(sdfMemHandle_t);
    sdfMemHandle_t___ctor(v105);
    v103[1].monitor = v105;
    _ctor(v103, 0);
    v101 = &MakaTex[2 * v100++];
    *(v101 + 4) = v103;
      goto LABEL_231;
  }
  v108 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_249;
LABEL_247:
LABEL_249:
  while (1)
  {
    makaWork = *(*(v3 + 184) + 136LL);
    if (v108 >= makaWork[6])
      break;
    v111 = Allocate(tagMakaObject);
    v111[1].monitor = NewSpecific(s32, 2u);
    v111[2].klass = NewSpecific(sbyte, 3u);
    _ctor(v111, 0);
    v109 = &makaWork[2 * v108++];
    *(v109 + 4) = v111;
      goto LABEL_247;
  }
  v114 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_265;
LABEL_263:
LABEL_265:
  while (1)
  {
    pipe_CELL01_D3P = *(*(v3 + 184) + 144LL);
    if (v114 >= pipe_CELL01_D3P[6])
      break;
    v117 = Allocate(PIPE_EFF_t);
    v118 = Allocate(sdfMemHandle_t);
    sdfMemHandle_t___ctor(v118);
    v117[1].klass = v118;
    v119 = Allocate(effHandle_t);
    effHandle_t___ctor(v119);
    v117[2].monitor = v119;
    _ctor(v117, 0);
    v115 = &pipe_CELL01_D3P[2 * v114++];
    *(v115 + 4) = v117;
      goto LABEL_263;
  }
  v122 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_281;
LABEL_279:
LABEL_281:
  while (1)
  {
    pipe_DAMAGE01_D3P = *(*(v3 + 184) + 168LL);
    if (v122 >= pipe_DAMAGE01_D3P[6])
      break;
    v125 = Allocate(PIPE_EFF_t);
    v126 = Allocate(sdfMemHandle_t);
    sdfMemHandle_t___ctor(v126);
    v125[1].klass = v126;
    v127 = Allocate(effHandle_t);
    effHandle_t___ctor(v127);
    v125[2].monitor = v127;
    _ctor(v125, 0);
    v123 = &pipe_DAMAGE01_D3P[2 * v122++];
    *(v123 + 4) = v125;
      goto LABEL_279;
  }
  v130 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_297;
LABEL_295:
LABEL_297:
  while (1)
  {
    pipe_DAMAGE03_D3P = *(*(v3 + 184) + 176LL);
    if (v130 >= pipe_DAMAGE03_D3P[6])
      break;
    v133 = Allocate(PIPE_EFF_t);
    v134 = Allocate(sdfMemHandle_t);
    sdfMemHandle_t___ctor(v134);
    v133[1].klass = v134;
    v135 = Allocate(effHandle_t);
    effHandle_t___ctor(v135);
    v133[2].monitor = v135;
    _ctor(v133, 0);
    v131 = &pipe_DAMAGE03_D3P[2 * v130++];
    *(v131 + 4) = v133;
      goto LABEL_295;
  }
  v138 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_313;
LABEL_311:
LABEL_313:
  while (1)
  {
    pipe_BREAK01_D3P = *(*(v3 + 184) + 152LL);
    if (v138 >= pipe_BREAK01_D3P[6])
      break;
    v141 = Allocate(PIPE_EFF_t);
    v142 = Allocate(sdfMemHandle_t);
    sdfMemHandle_t___ctor(v142);
    v141[1].klass = v142;
    v143 = Allocate(effHandle_t);
    effHandle_t___ctor(v143);
    v141[2].monitor = v143;
    _ctor(v141, 0);
    v139 = &pipe_BREAK01_D3P[2 * v138++];
    *(v139 + 4) = v141;
      goto LABEL_311;
  }
  v146 = 0;
  if ((*(v3 + 295) & 2) == 0)
    goto LABEL_329;
LABEL_327:
LABEL_329:
  while (1)
  {
    pipe_BREAK02_D3P = *(*(v3 + 184) + 160LL);
    if (v146 >= pipe_BREAK02_D3P[6])
      break;
    v149 = Allocate(PIPE_EFF_t);
    v150 = Allocate(sdfMemHandle_t);
    sdfMemHandle_t___ctor(v150);
    v149[1].klass = v150;
    v151 = Allocate(effHandle_t);
    effHandle_t___ctor(v151);
    v149[2].monitor = v151;
    _ctor(v149, 0);
    v147 = &pipe_BREAK02_D3P[2 * v146++];
    *(v147 + 4) = v149;
      goto LABEL_327;
  }
  v154 = 0;
  v155 = *(v3 + 294);
  if ((v155 & 0x200) != 0)
    goto LABEL_344;
LABEL_343:
  for (i = 0; ; i = v155 & 0x200)
  {
    pipe_ATTACK01_D3P = *(*(v3 + 184) + 184LL);
    if (v154 >= pipe_ATTACK01_D3P[6])
      break;
    v159 = Allocate(PIPE_EFF_t);
    v160 = Allocate(sdfMemHandle_t);
    sdfMemHandle_t___ctor(v160);
    v159[1].klass = v160;
    v161 = Allocate(effHandle_t);
    effHandle_t___ctor(v161);
    v159[2].monitor = v161;
    _ctor(v159, 0);
    v156 = &pipe_ATTACK01_D3P[2 * v154++];
    *(v156 + 4) = v159;
    if ((v155 & 0x200) == 0)
      goto LABEL_343;
LABEL_344:
  }
  partsInit(v3);
  v164 = 1.0;
  mymdlInit(basicMy, 1.0, 1.0, 1.0, 1.0, 1u);
  mymdlInit(MyLine, v164, v164, v164, v164, 1u);
  mymdlInit(PipeMaka1, v164, v164, v164, v164, 0x32u);
  mymdlInit(PipeZMaka, v164, v164, v164, v164, 2u);
  mymdlInit(PipeDMaka, v164, v164, v164, v164, 4u);
  mymdlInit(PipeDRBOX, v164, v164, v164, v164, 2u);
  mymdlInit(PipeLine, v164, v164, v164, v164, 0xAu);
  mymdlInit(PipeCur, v164, v164, v164, v164, 0xAu);
  mymdlInit(PipeCur2, v164, v164, v164, v164, 0xAu);
  mymdlInit(PipeRBOX, v164, v164, v164, v164, 0xAu);
  mymdlInit(PipeEMS, v164, v164, v164, v164, 0x32u);
  mymdlInit(PipeEML, 1.0, 1.0, 1.0, 1.0, 0x32u);
}

// 0x153c340
s32 objAdd(tagPipeObject *objPtr) {
  struct tagPipeObject_array *ObjWork;
  s32 v6;
  s64 v8;
  Il2CppClass **v10;
  tagPipeObject_o *v12;
  f32 y;
  f32 v15;

  if (objPtr->id == 5)
  {
    if (objPtr->action == 26)
    {
      v6 = 5;
    }
    else
    {
      v6 = 1;
    }
    dbMAKANum += v6;
  }
  if ((objPtr->status & 0x4000) != 0)
  {
    ++dbZMAKANum;
  }
  v8 = 0;
  do
  {
    if (v8 == -150)
      return 0;
    v10 = &ObjWork->obj.klass + v8--;
  }
  while (LOBYTE(v10[153]->_1.byval_arg.bits) != 255);
  objMdlAdd(objPtr);
  if (objPtr->mdl == 255)
    return 0;
  v12 = ObjWork->m_Items[v8 + 150];
  v12->offset = objPtr->offset;
  v12->w = objPtr->w;
  y = objPtr->pos.y;
  v12->pos.x = objPtr->pos.x;
  v12->pos.y = y;
  v15 = objPtr->vpos.y;
  v12->vpos.x = objPtr->vpos.x;
  v12->vpos.y = v15;
  v12->id = objPtr->id;
  v12->action = objPtr->action;
  v12->enabled = objPtr->enabled;
  v12->mdl = objPtr->mdl;
  v12->count = objPtr->count;
  v12->status = objPtr->status;
  return 1;
}

// 0x153cba0
void objAddDMaka(s32 offset, f32 x, f32 y) {
  u64 *v7;

  v7 = Allocate(tagPipeObject);
  _ctor(v7, 0);
  objMake(v7, offset, 0xBu, 0, 0, 0);
  sub_8518D0((v7 + 3), 0, x);
  sub_8518D0((v7 + 3), 1, y);
  *(v7 + 25) = 29;
  objAdd(v7);
}

// 0x153cc80
void objAddDRBOX(s32 offset, f32 x, f32 y) {
  u64 *v7;

  v7 = Allocate(tagPipeObject);
  _ctor(v7, 0);
  objMake(v7, offset, 0xCu, 0, 0, 0);
  sub_8518D0((v7 + 3), 0, x);
  sub_8518D0((v7 + 3), 1, y);
  *(v7 + 25) = 29;
  objAdd(v7);
}

// 0x153c920
void objCopy(s32 offset, f32 x, f32 y, u8 id, u8 action, s16 count, s16 num) {
  s32 v10;
  u64 *v14;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;

  v10 = num;
  v14 = Allocate(tagPipeObject);
  _ctor(v14, 0);
  objMake(v14, offset, id, 0, action, 0);
  for (; v10; --v10)
  {
    v18 = (dds3GetRandA("") % 0x190);
    sub_8518D0((v14 + 3), 0, (v18 + x) + -200.0);
    v19 = (dds3GetRandA("") % 0x190);
    sub_8518D0((v14 + 3), 1, (v19 + y) + -200.0);
    *(v14 + 4) = dds3GetRandA("") % 0x14 + offset;
    v20 = (dds3GetRandA("") % 0xA);
    sub_8518D0((v14 + 4), 0, v20 + -5.0);
    v21 = (dds3GetRandA("") % 0xA);
    sub_8518D0((v14 + 4), 1, v21 + -5.0);
    *(v14 + 25) = count;
    objAdd(v14);
  }
}

// 0x153c0b0
void objCopy2(s32 offset, f32 x, f32 y, u8 id, u8 action, s16 count, s16 num, s32 w) {
  s32 v12;
  u64 *v16;
  f32 v20;
  s64 v21;
  u32 RandA;
  u32 v23;
  f32 v24;
  f32 v25;

  v12 = num;
  v16 = Allocate(tagPipeObject);
  _ctor(v16, 0);
  objMake(v16, offset, id, 0, action, 0);
  if (v12)
  {
    v20 = w;
    v21 = 2 * w;
    do
    {
      RandA = dds3GetRandA("");
      sub_8518D0((v16 + 3), 0, ((RandA % v21) + x) - v20);
      v23 = dds3GetRandA("");
      sub_8518D0((v16 + 3), 1, ((v23 % v21) + y) - v20);
      *(v16 + 4) = dds3GetRandA("") % (w / 20) + offset;
      v24 = (dds3GetRandA("") % 0xA);
      sub_8518D0((v16 + 4), 0, v24 + -5.0);
      v25 = (dds3GetRandA("") % 0xA);
      sub_8518D0((v16 + 4), 1, v25 + -5.0);
      *(v16 + 25) = count;
      objAdd(v16);
      --v12;
    }
    while (v12);
  }
}

// 0x153d190
void objDel(tagPipeObject *objPtr) {
  objMdlDel(objPtr);
  objPtr->id = -1;
}

// 0x153d610
void objDelAll(void) {
  struct tagPipeObject_array *ObjWork;
  s64 i;
  tagPipeObject_o *v6;
  s64 v8;
  u64 v10;
  struct tagMakaObject_array *makaWork;
  u64 max_length_low;
  UnityEngine_Object_o *v14;
  struct tagMakaObject_array *v16;
  UnityEngine_Object_o *v18;
  struct tagMakaObject_array *v19;

  for (i = 153; i != 3; --i)
  {
    v6 = *(&ObjWork->obj.klass + i);
    if (v6->id != 255)
    {
 if ((byte_3F59CB1 & 1) != 0)
      {
        goto LABEL_18;
      }
      goto LABEL_18;
    }
  }
  v8 = 4;
  v10 = 0;
    goto LABEL_28;
LABEL_26:
LABEL_28:
  while (1)
  {
    max_length_low = LODWORD(makaWork->max_length);
    if (v10 >= max_length_low)
      break;
    else if (v10 >= max_length_low)
    {
      goto LABEL_32;
    }
    v14 = *(*(&makaWork->obj.klass + v8) + 40LL);
    if (op_Inequality(v14, 0, 0))
    {
      v16 = makaWork;
      v18 = *(*(&v16->obj.klass + v8) + 40LL);
      Destroy_27360000(v18);
      v19 = makaWork;
      *(*(&v19->obj.klass + v8) + 40LL) = 0;
    }
    ++v8;
    v10 = v8 - 4;
      goto LABEL_26;
  }
}

// 0x153b410
tagPipeEnemyInfo *objInfo(s32 id) {
  struct tagPipeEnemyInfo_array *PipeEnemyInfo;
  s64 max_length_low;
  s64 v6;
  s64 v7;
  tagPipeEnemyInfo_o *result;
  tagPipeEnemyInfo_o *v10;

  {
  }
  max_length_low = SLODWORD(PipeEnemyInfo->max_length);
  v6 = -max_length_low;
  v7 = &PipeEnemyInfo->m_Items[max_length_low];
  do
  {
    if (!v6)
      return 0;
    LODWORD(max_length_low) = max_length_low - 1;
    v10 = *(v7 - 8);
    v7 -= 8;
    result = v10;
    ++v6;
  }
  while (v10->chID != id);
  return result;
}

// 0x153c870
void objInit(void) {
  struct tagPipeObject_array *ObjWork;
  s64 i;
  s64 v6;

  for (i = 153; i != 3; --i)
  {
    v6 = *(&ObjWork->obj.klass + i);
    *(v6 + 40) = -1;
  }
}

// 0x153c750
void objInitMyAdd(void) {
  u64 *v1;
  struct tagPipeObject_array *ObjWork;
  s64 i;
  s64 v7;

  v1 = Allocate(tagPipeObject);
  _ctor(v1, 0);
LABEL_7:
  for (i = 153; i != 3; --i)
  {
    v7 = *(&ObjWork->obj.klass + i);
    *(v7 + 40) = -1;
  }
  objMyLoad(v1);
  objAdd(v1);
}

// 0x153b6a0
u8 objLoad(tagPipeObject *objPtr, s32 index) {
  struct tagPipeEnemyTable_array *tabPtr;
  tagPipeEnemyTable_o *v8;
  u64 *v9;
  u32 v11;
  u8 v12;
  u32 v13;
  u8 v14;
  u32 v15;
  f32 v16;
  f32 v17;
  struct UnityEngine_Vector2_o *p_pos;
  f32 v19;
  u32 chID;
  tagPipeEnemyInfo_o *v22;
  u32 action;

  tabPtr = obTable->tabPtr;
  v8 = tabPtr->m_Items[index];
  v9 = Allocate(tagPipeEnemyInfo);
  _ctor(v9, 0);
  v11 = v8->offset + dds3GetRandA("");
  v12 = v8->way % 0xAu;
  v13 = v11 / 9;
  if (v8->way >= 0x64u)
    v14 = v11 % 9 + 1;
  else
    v14 = v8->way / 0xAu;
  if (!(v8->way % 0xAu))
  {
    while (1)
    {
      v15 = v11 - 9 * v13;
      v12 = v15 + 1;
      if (v15 != 4)
        break;
      v11 += v11 >> 1;
      v13 = v11 / 9;
    }
  }
  if ((v12 & 1) != 0)
    v16 = (60 * v14) * 0.70711;
  else
    v16 = (60 * v14);
  if (v12 <= 3u)
  {
    v17 = v16;
  }
  else if (v12 >= 7u)
  {
    v17 = -v16;
  }
  else
  {
    v17 = 0.0;
  }
  sub_8518D0(&objPtr->pos, 1, v17);
  if (v12 <= 9u)
  {
    if (((1 << v12) & 0x92) != 0)
    {
      p_pos = &objPtr->pos;
      v19 = -v16;
      goto LABEL_32;
    }
    if (((1 << v12) & 0x248) != 0)
    {
      p_pos = &objPtr->pos;
      v19 = v16;
      goto LABEL_32;
    }
  }
  v19 = 0.0;
  p_pos = &objPtr->pos;
LABEL_32:
  sub_8518D0(p_pos, 0, v19);
  chID = v8->chID;
  objPtr->id = chID;
  objPtr->offset = v8->offset;
  objPtr->enabled = 1;
  objPtr->action = v8->action;
  objPtr->count = 0;
  if ((chID & 0x10) != 0)
    goto LABEL_38;
  v22 = objInfo(chID);
  if (v22)
  {
    chID = objPtr->id;
    objPtr->w = v22->w;
LABEL_38:
    if (chID <= 0xF)
    {
      action = objPtr->action;
      if (action <= 0x10 && ((1 << action) & 0x18040) != 0)
        objPtr->offset -= 560;
    }
    if ((chID & 0x10) != 0)
      objPtr->count = 10 * v8->value;
    LOBYTE(v22) = v8->value;
  }
  return v22;
}

// 0x153b980
u8 objMake(tagPipeObject *objPtr, s32 offset, u8 id, u8 way, u8 action, u8 value) {
  u64 *v13;
  u8 v15;
  u32 v16;
  s64 v17;
  char v18;
  f32 v19;
  f32 v20;
  struct UnityEngine_Vector2_o *p_pos;
  f32 v22;
  tagPipeEnemyInfo_o *v24;
  u32 v25;

  v13 = Allocate(tagPipeEnemyInfo);
  _ctor(v13, 0);
  if (way)
  {
    v15 = way / 0xAu;
    LOBYTE(v16) = way % 0xAu;
  }
  else
  {
    v17 = dds3GetRandA("") + offset;
    v18 = v17 + 3;
    if (v17 >= 0)
      v18 = v17;
    v15 = v17 - (v18 & 0xFC);
    v16 = (dds3GetRandA("") + id) % 9 + 1;
  }
  if ((v16 & 1) != 0)
    v19 = ((100 * v15) + 150.0) * 0.70711;
  else
    v19 = (100 * v15) + 150.0;
  if (v16 <= 3u)
  {
    v20 = v19;
  }
  else if (v16 >= 7u)
  {
    v20 = -v19;
  }
  else
  {
    v20 = 0.0;
  }
  sub_8518D0(&objPtr->pos, 1, v20);
  if (v16 <= 9u)
  {
    if (((1 << v16) & 0x92) != 0)
    {
      p_pos = &objPtr->pos;
      v22 = -v19;
      goto LABEL_25;
    }
    if (((1 << v16) & 0x248) != 0)
    {
      p_pos = &objPtr->pos;
      v22 = v19;
      goto LABEL_25;
    }
  }
  v22 = 0.0;
  p_pos = &objPtr->pos;
LABEL_25:
  sub_8518D0(p_pos, 0, v22);
  objPtr->id = id;
  objPtr->offset = offset;
  objPtr->enabled = 1;
  objPtr->action = action;
  objPtr->count = 0;
  if ((id & 0x10) != 0)
    goto LABEL_30;
  v24 = objInfo(id);
  if (!v24)
    return 0;
LABEL_29:
  id = objPtr->id;
  objPtr->w = v24->w;
LABEL_30:
  if (id <= 0xFu)
  {
    v25 = objPtr->action;
    if (v25 <= 0x10 && ((1 << v25) & 0x18040) != 0)
      objPtr->offset -= 560;
  }
  if ((id & 0x10) != 0)
    objPtr->count = 10 * value;
  return value;
}

// 0x153cd60
void objMdlAdd(tagPipeObject *objPtr) {
  tagpipeBasic_array *PipeEML;
  struct tagpipeBasic_array *MyLine;
  tagpipeBasic_o *v11;
  dds3ModelHandle_t_o **v12;
  u32 v13;
  u16 v16;
  u8 mdl;
  struct tagpipeBasic_array *PipeDMaka;
  s64 v24;
  u8 v26;
  tagpipeBasic_o *v29;
  dds3ModelHandle_t_o **p_model;

  switch (objPtr->id)
  {
    case 1u:
      goto LABEL_28;
    case 2u:
      PipeEML = PipeEMS;
      goto LABEL_28;
    case 3u:
    case 4u:
    case 7u:
    case 8u:
      return;
    case 5u:
    case 6u:
      PipeEML = PipeMaka1;
LABEL_28:
      v16 = 50;
      goto LABEL_37;
    case 9u:
      PipeEML = PipeZMaka;
      v16 = 2;
      goto LABEL_37;
    case 0xAu:
      PipeEML = PipeRBOX;
      v16 = 10;
LABEL_37:
      objPtr->mdl = mymdlAddObject(PipeEML, v16);
      return;
    case 0xBu:
      mdl = mymdlAddObject(PipeDMaka, 4u);
      objPtr->mdl = mdl;
      if (mdl == 0xFF)
        return;
      v24 = mdl;
      if (LODWORD(PipeDMaka->max_length) > mdl)
        goto LABEL_57;
      goto LABEL_56;
    case 0xCu:
      v26 = mymdlAddObject(PipeDRBOX, 2u);
      objPtr->mdl = v26;
      if (v26 == 0xFF)
        return;
      PipeDMaka = PipeDRBOX;
      v24 = v26;
      if (LODWORD(PipeDMaka->max_length) <= v26)
      {
LABEL_56:
      }
LABEL_57:
      v29 = PipeDMaka->m_Items[v24];
      p_model = &v29->model;
      mdlGetMotionCtrlr(p_model, 0);
      return;
    default:
      if (objPtr->id == 128)
      {
        objPtr->mdl = mymdlAddObject(basicMy, 1u);
        mymdlAddObject(MyLine, 1u);
        v11 = MyLine->m_Items[0];
        v12 = &v11->model;
        v13 = mdlGetColor(v12) & 0xFFFFFF;
        mdlSetColor(v12, v13);
      }
      return;
  }
}

// 0x153dcc0
void objMdlAlphaSet(tagPipeObject *objPtr, u8 alpha) {
  s32 id;
  struct tagpipeBasic_array *PipeEML;
  s64 mdl;
  tagpipeBasic_o *v10;
  dds3ModelHandle_t_o **p_model;
  u32 Color;
  struct tagpipeBasic_array *basicMy;

  id = objPtr->id;
  switch (objPtr->id)
  {
    case 1u:
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
        goto LABEL_9;
      goto LABEL_8;
    case 2u:
      PipeEML = PipeEMS;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
        goto LABEL_9;
      goto LABEL_8;
    case 3u:
    case 4u:
    case 7u:
    case 8u:
      return;
    case 5u:
    case 6u:
      PipeEML = PipeMaka1;
      mdl = objPtr->mdl;
      if (mdl >= LODWORD(PipeEML->max_length))
        goto LABEL_8;
      goto LABEL_9;
    case 9u:
      PipeEML = PipeZMaka;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
        goto LABEL_9;
      goto LABEL_8;
    case 0xAu:
      PipeEML = PipeRBOX;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
        goto LABEL_9;
      goto LABEL_8;
    case 0xBu:
      PipeEML = PipeDMaka;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
        goto LABEL_9;
      goto LABEL_8;
    case 0xCu:
      PipeEML = PipeDRBOX;
      mdl = objPtr->mdl;
      if (mdl >= LODWORD(PipeEML->max_length))
      {
LABEL_8:
      }
LABEL_9:
      v10 = PipeEML->m_Items[mdl];
      if ((byte_3F59CA9 & 1) == 0)
        goto LABEL_10;
      goto LABEL_11;
    default:
      if (id == 128)
      {
        if (!LODWORD(basicMy->max_length))
        {
LABEL_57:
        }
      }
      else
      {
        if (id != 129)
          return;
        basicMy = MyLine;
        if (!LODWORD(basicMy->max_length))
          goto LABEL_57;
      }
      v10 = basicMy->m_Items[0];
LABEL_11:
      p_model = &v10->model;
      Color = mdlGetColor(p_model);
      mdlSetColor(p_model, Color & 0xFFFFFF | (alpha << 24), 0);
      return;
  }
}

// 0x153f690
void objMdlColorSet(tagPipeObject *objPtr, u32 color) {
  switch (objPtr->id)
  {
    case 1u:
      if (objPtr->mdl < LODWORD(PipeEML->max_length))
        return;
      goto LABEL_36;
    case 2u:
      if (objPtr->mdl >= LODWORD(PipeEMS->max_length))
        goto LABEL_36;
      return;
    case 3u:
    case 4u:
    case 7u:
    case 8u:
      return;
    case 5u:
    case 6u:
      if (objPtr->mdl >= LODWORD(PipeMaka1->max_length))
        goto LABEL_36;
      return;
    case 9u:
      if (objPtr->mdl >= LODWORD(PipeZMaka->max_length))
        goto LABEL_36;
      return;
    case 0xAu:
      if (objPtr->mdl >= LODWORD(PipeRBOX->max_length))
        goto LABEL_36;
      return;
    case 0xBu:
      if (objPtr->mdl >= LODWORD(PipeDMaka->max_length))
        goto LABEL_36;
      return;
    case 0xCu:
      if (objPtr->mdl >= LODWORD(PipeDRBOX->max_length))
        goto LABEL_36;
      return;
    default:
      if (objPtr->id == 128)
      {
        if (!LODWORD(MyLine->max_length))
        {
LABEL_36:
        }
      }
      return;
  }
}

// 0x153d200
void objMdlDel(tagPipeObject *objPtr) {
  struct tagpipeBasic_array *PipeEML;
  s64 mdl;
  tagpipeBasic_o *v9;
  UnityEngine_GameObject_o *gameObject;
  struct tagpipeBasic_array *MyLine;
  tagpipeBasic_o *v16;
  UnityEngine_GameObject_o *v18;
  struct tagpipeBasic_array *basicMy;
  tagpipeBasic_o *v21;

  if (objPtr->mdl != 255)
  {
    objMdlSclSet(objPtr, 1.0);
    objMdlAlphaSet(objPtr, 0x80u);
    switch (objPtr->id)
    {
      case 1u:
        mdl = objPtr->mdl;
        if (mdl < LODWORD(PipeEML->max_length))
          goto LABEL_13;
        goto LABEL_12;
      case 2u:
        PipeEML = PipeEMS;
        mdl = objPtr->mdl;
        if (mdl < LODWORD(PipeEML->max_length))
          goto LABEL_13;
        goto LABEL_12;
      case 3u:
      case 4u:
      case 7u:
      case 8u:
        return;
      case 5u:
      case 6u:
        PipeEML = PipeMaka1;
        mdl = objPtr->mdl;
        if (mdl >= LODWORD(PipeEML->max_length))
          goto LABEL_12;
        goto LABEL_13;
      case 9u:
        PipeEML = PipeZMaka;
        mdl = objPtr->mdl;
        if (mdl < LODWORD(PipeEML->max_length))
          goto LABEL_13;
        goto LABEL_12;
      case 0xAu:
        PipeEML = PipeRBOX;
        mdl = objPtr->mdl;
        if (mdl < LODWORD(PipeEML->max_length))
          goto LABEL_13;
        goto LABEL_12;
      case 0xBu:
        PipeEML = PipeDMaka;
        mdl = objPtr->mdl;
        if (mdl < LODWORD(PipeEML->max_length))
          goto LABEL_13;
        goto LABEL_12;
      case 0xCu:
        PipeEML = PipeDRBOX;
        mdl = objPtr->mdl;
        if (mdl >= LODWORD(PipeEML->max_length))
        {
LABEL_12:
        }
LABEL_13:
        v9 = PipeEML->m_Items[mdl];
        v9->enabled = 0;
        dds3ObjectBaseOnFlag(&v9->basic, 1u, 0);
        gameObject = v9->basic->gameObject;
          goto LABEL_16;
        goto LABEL_18;
      default:
        if (objPtr->id != 128)
          return;
        v16 = MyLine->m_Items[0];
        v16->enabled = 0;
        dds3ObjectBaseOnFlag(&v16->basic, 1u, 0);
        v18 = v16->basic->gameObject;
        cmpSetupObject(v18, 0);
        v21 = basicMy->m_Items[0];
        v21->enabled = 0;
        dds3ObjectBaseOnFlag(&v21->basic, 1u, 0);
        gameObject = v21->basic->gameObject;
        {
LABEL_16:
        }
LABEL_18:
        cmpSetupObject(gameObject, 0);
        break;
    }
  }
}

// 0x153b500
void objMdlMotion(tagPipeObject *objPtr, s32 motion, f32 speed) {
  s32 v4;
  struct tagpipeBasic_array *basicMy;
  dds3ModelHandle_t_o **p_model;
  UnityEngine_Object_o *basicMyAnm;

  v4 = motion;
  if (objPtr->id == 128)
  {
    else
    {
      if (!LODWORD(basicMy->max_length))
        goto LABEL_7;
    }
    p_model = &basicMy->m_Items[0]->model;
    mdlSmoothLoopMotion(p_model, 0, v4, 2.0, 2.0);
    if (op_Inequality(basicMyAnm, 0, 0))
    {
      if ((v4 - 2) >= 3)
        v4 = 0;
      SetInteger(basicMyAnm, "anim", v4);
    }
  }
}

// 0x153e020
void objMdlPosSet(tagPipeObject *objPtr) {
  struct tagpipeBasic_array *PipeEML;
  s64 mdl;
  tagpipeBasic_o *v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v16;
  struct tagpipeBasic_array *v18;
  tagpipeBasic_o *v21;
  struct tagpipeBasic_array *MyLine;
  struct tagpipeBasic_array *v26;
  UnityEngine_Object_o *v28;
  struct tagpipeBasic_array *v32;
  UnityEngine_Transform_o *v34;
  struct tagpipeBasic_array *PipeZMaka;
  s64 v40;
  tagpipeBasic_o *v42;
  f32 v43;
  f32 v44;
  f32 v45;
  f32 v46;
  f32 v48;
  struct tagpipeBasic_array *PipeDMaka;
  s64 v51;
  UnityEngine_Object_o *gameObject;
  struct tagpipeBasic_array *v56;
  s64 v57;
  UnityEngine_Transform_o *transform;
  UnityEngine_Component_o *Child;
  UnityEngine_Transform_o *v62;
  struct tagpipeBasic_array *v65;
  s64 v66;
  UnityEngine_Transform_o *v68;
  UnityEngine_Component_o *v69;
  UnityEngine_Transform_o *v70;
  struct tagpipeBasic_array *basicMy;
  UnityEngine_Transform_o *v73;
  UnityEngine_Transform_o *parent;
  UnityEngine_Transform_o *v76;
  UnityEngine_Transform_o *v77;
  f32 v79;
  f32 x;
  f32 y;
  f32 w;
  struct tagpipeBasic_array *v85;
  s64 v86;
  struct tagpipeBasic_array *v89;
  s64 v90;
  UnityEngine_Object_o *v92;
  struct tagpipeBasic_array *v95;
  s64 v96;
  UnityEngine_Transform_o *v98;
  struct tagpipeBasic_array *v99;
  UnityEngine_Transform_o *v100;
  UnityEngine_Transform_o *v102;
  struct tagpipeBasic_array *v103;
  s64 v104;
  UnityEngine_Transform_o *v106;
  struct tagpipeBasic_array *PipeDRBOX;
  s64 v110;
  struct tagpipeBasic_array *v113;
  s64 v114;
  UnityEngine_Object_o *v116;
  struct tagpipeBasic_array *v119;
  s64 v120;
  UnityEngine_Transform_o *v122;
  struct tagpipeBasic_array *v123;
  UnityEngine_Transform_o *v124;
  UnityEngine_Transform_o *v126;
  struct tagpipeBasic_array *v127;
  s64 v128;
  UnityEngine_Transform_o *v130;
  f32 v135;
  f32 v136;
  f32 v137;
  f32 z;
  struct tagpipeBasic_array *v139;
  f32 v141;
  UnityEngine_Transform_o *v142;
  UnityEngine_Transform_o *v143;
  struct tagpipeBasic_array *v145;
  UnityEngine_Transform_o *v147;
  struct tagpipeBasic_array *v148;
  UnityEngine_Transform_o *v150;
  UnityEngine_Component_o *v151;
  UnityEngine_GameObject_o *v152;
  UnityEngine_Transform_o *v154;
  f32 lrRad;
  f32 udRad;
  struct tagpipeBasic_array *v159;
  tagpipeBasic_o *v161;
  f32 v162;
  f32 v163;
  f32 v164;
  f32 v165;
  f32 v167;
  struct tagpipeBasic_array *v168;
  tagpipeBasic_o *v170;
  f32 v171;
  f32 v172;
  f32 v173;
  f32 v174;
  f32 v176;
  s64 v178;
  s32 v179;
  UnityEngine_Vector4_o pos;
  UnityEngine_Vector3_o v181;
  UnityEngine_Vector3_o forward;
  UnityEngine_Vector3_o v183;
  UnityEngine_Vector3_o position;
  UnityEngine_Vector3_o v185;
  UnityEngine_Vector3_o v186;
  UnityEngine_Vector3_o v187;
  UnityEngine_Vector3_o v188;
  UnityEngine_Vector4_o v189;
  UnityEngine_Vector4_o v190;
  UnityEngine_Quaternion_o rotation;
  UnityEngine_Quaternion_o v192;
  UnityEngine_Quaternion_o v193;
  UnityEngine_Quaternion_o v194;

  *&pos.x = 0;
  *&pos.z = 0;
  if (objPtr->mdl != 255)
  {
    getPosTranslate(objPtr, &pos);
    switch (objPtr->id)
    {
      case 1u:
        mdl = objPtr->mdl;
        if (mdl < LODWORD(PipeEML->max_length))
          goto LABEL_13;
        goto LABEL_12;
      case 2u:
        PipeEML = PipeEMS;
        mdl = objPtr->mdl;
        if (mdl < LODWORD(PipeEML->max_length))
          goto LABEL_13;
        goto LABEL_12;
      case 3u:
      case 4u:
      case 7u:
      case 8u:
        return;
      case 5u:
      case 6u:
        PipeEML = PipeMaka1;
        mdl = objPtr->mdl;
        if (mdl >= LODWORD(PipeEML->max_length))
          goto LABEL_12;
        goto LABEL_13;
      case 9u:
        v40 = objPtr->mdl;
        v42 = PipeZMaka->m_Items[v40];
        sub_854710(&pos, 0);
        v44 = v43;
        sub_854710(&pos, 1u);
        v46 = v45;
        sub_854710(&pos, 2u);
        mymdlPosSet(v42, v44, v46, v48);
        v51 = objPtr->mdl;
        gameObject = PipeDMaka->m_Items[v51]->basic->gameObject;
        if (op_Inequality(gameObject, 0, 0))
        {
          v56 = PipeZMaka;
          v57 = objPtr->mdl;
          transform = get_transform(v56->m_Items[v57]->basic->gameObject, 0);
          Child = GetChild(transform, 1);
          v62 = get_transform(Child, 0);
          if (op_Inequality(v62, 0, 0))
          {
            v65 = PipeZMaka;
            v66 = objPtr->mdl;
            v68 = get_transform(v65->m_Items[v66]->basic->gameObject, 0);
            v69 = GetChild(v68, 0);
            v70 = get_transform(v69, 0);
            position = get_position(v70);
            set_position(v62, position);
            v73 = get_transform(basicMy->m_Items[0]->basic->gameObject, 0);
            rotation = get_rotation(v73);
            set_rotation(v62, rotation);
            Rotate_27486992(v62, 0.0, 0.0, 180.0);
            v181 = get_position(v62);
            forward = get_forward(v62, 0);
            {
            }
            v187 = op_Multiply(forward, 0.5, 0);
            v185 = op_Addition(v181, v187);
            set_position(v62, v185);
            v179 = 0;
            v178 = 0;
            sub_8524C0(&v178, 1.0, 1.0, 1.0);
            parent = get_parent(v62);
            pos.y = 1.0 / get_lossyScale(parent).y;
            v76 = get_parent(v62);
            pos.x = 1.0 / get_lossyScale(v76).x;
            v77 = get_parent(v62);
            v79 = 1.0 / COERCE_FLOAT(LODWORD(get_lossyScale(v77).z));
            pos.z = v79;
            x = pos.x;
            y = pos.y;
            w = pos.w;
            {
            }
            v189.x = x;
            v189.y = y;
            v189.z = v79;
            v189.w = w;
            v186 = op_Implicit_8738992(v189);
            set_localScale(v62, v186);
          }
        }
        return;
      case 0xAu:
        PipeEML = PipeRBOX;
        mdl = objPtr->mdl;
        if (mdl < LODWORD(PipeEML->max_length))
          goto LABEL_13;
        goto LABEL_12;
      case 0xBu:
        v85 = PipeDMaka;
        v86 = objPtr->mdl;
        mdlTask(objPtr, v85->m_Items[v86], 90.0, 180.0, 0.0);
        v89 = PipeDMaka;
        v90 = objPtr->mdl;
        v92 = v89->m_Items[v90]->basic->gameObject;
        if (op_Inequality(v92, 0, 0))
        {
          v95 = PipeDMaka;
          v96 = objPtr->mdl;
          v98 = get_transform(v95->m_Items[v96]->basic->gameObject, 0);
          v99 = basicMy;
          v100 = v98;
          v102 = get_transform(v99->m_Items[0]->basic->gameObject, 0);
          v192 = get_rotation(v102);
          set_rotation(v100, v192);
          v103 = PipeDMaka;
          v104 = objPtr->mdl;
          v106 = get_transform(v103->m_Items[v104]->basic->gameObject, 0);
          Rotate_27486992(v106, 0.0, 0.0, 180.0);
        }
        PipeEML = PipeDMaka;
        mdl = objPtr->mdl;
        if (mdl < LODWORD(PipeEML->max_length))
          goto LABEL_13;
        goto LABEL_12;
      case 0xCu:
        v110 = objPtr->mdl;
        mdlTask(objPtr, PipeDRBOX->m_Items[v110], 90.0, 180.0, 0.0);
        v113 = PipeDRBOX;
        v114 = objPtr->mdl;
        v116 = v113->m_Items[v114]->basic->gameObject;
        if (op_Inequality(v116, 0, 0))
        {
          v119 = PipeDRBOX;
          v120 = objPtr->mdl;
          v122 = get_transform(v119->m_Items[v120]->basic->gameObject, 0);
          v123 = basicMy;
          v124 = v122;
          v126 = get_transform(v123->m_Items[0]->basic->gameObject, 0);
          v193 = get_rotation(v126);
          set_rotation(v124, v193);
          v127 = PipeDRBOX;
          v128 = objPtr->mdl;
          v130 = get_transform(v127->m_Items[v128]->basic->gameObject, 0);
          Rotate_27486992(v130, 0.0, 0.0, 180.0);
        }
        PipeEML = PipeDRBOX;
        mdl = objPtr->mdl;
        if (mdl >= LODWORD(PipeEML->max_length))
        {
LABEL_12:
        }
LABEL_13:
        v10 = PipeEML->m_Items[mdl];
        sub_854710(&pos, 0);
        v12 = v11;
        sub_854710(&pos, 1u);
        v14 = v13;
        sub_854710(&pos, 2u);
        mymdlPosSet(v10, v12, v14, v16);
        return;
      default:
        if (objPtr->id != 128)
          return;
        v18 = basicMy;
        v21 = v18->m_Items[0];
        mdlTask(objPtr, v21, udRad, lrRad, 0.0);
        mdlTask(objPtr, MyLine->m_Items[0], -90.0, 0.0, 0.0);
        v26 = basicMy;
        v28 = v26->m_Items[0]->basic->gameObject;
        if (!op_Inequality(v28, 0, 0))
          goto LABEL_166;
        if (offsetCount >= 800)
        {
          v135 = pipeVertical.x;
          v136 = pipeVertical.y;
          z = pipeVertical.z;
          v137 = pipeVertical.w;
          v139 = basicMy;
          v141 = -z;
          v142 = get_transform(v139->m_Items[0]->basic->gameObject, 0);
          v143 = get_transform(pipeCameraObj, 0);
          v183 = get_position(v143);
          v190.x = v135;
          v190.y = v136;
          v190.z = v141;
          v190.w = v137;
          v188 = op_Implicit_8738992(v190);
          LookAt_27488480(v142, v183, v188);
          v145 = basicMy;
          v147 = get_transform(v145->m_Items[0]->basic->gameObject, 0);
          Rotate_27486992(v147, 0.0, 0.0, 180.0);
          v148 = basicMy;
          v150 = get_transform(v148->m_Items[0]->basic->gameObject, 0);
          v151 = GetChild(v150, 0);
          v152 = get_gameObject(v151);
          v154 = get_transform(v152, 0);
          {
          }
          v194 = Euler(udRad * 0.5, 0.0, lrRad);
          set_localRotation(v154, v194);
LABEL_166:
            goto LABEL_169;
        }
        else
        {
          v32 = basicMy;
          v34 = get_transform(v32->m_Items[0]->basic->gameObject, 0);
          Rotate_27486992(v34, 0.0, 180.0, 0.0);
          {
LABEL_169:
            v159 = basicMy;
            v161 = v159->m_Items[0];
            sub_854710(&pos, 0);
            v163 = v162;
            sub_854710(&pos, 1u);
            v165 = v164;
            sub_854710(&pos, 2u);
            mymdlPosSet(v161, v163, v165, v167);
            v168 = MyLine;
            v170 = v168->m_Items[0];
            sub_854710(&pos, 0);
            v172 = v171;
            sub_854710(&pos, 1u);
            v174 = v173;
            sub_854710(&pos, 2u);
            mymdlPosSet(v170, v172, v174, v176);
            eglSetOt(50);
            eglLinkTest(1, 5, 128, 1, 0, 0, 1, 1);
            eglSetOt(51);
            eglLinkTest(1, 5, 128, 1, 0, 0, 1, 1);
            eglSetOt(52);
            eglLinkTest(1, 5, 128, 1, 0, 0, 1, 1);
            eglSetOt(53);
            eglLinkTest(1, 5, 128, 1, 0, 0, 1, 1);
            eglSetOt(54);
            eglLinkTest(1, 5, 128, 1, 0, 0, 1, 1);
            eglSetOt(55);
            eglLinkTest(1, 5, 128, 1, 0, 0, 1, 3);
            return;
          }
        }
        goto LABEL_169;
    }
  }
}

// 0x153d9e0
void objMdlSclSet(tagPipeObject *objPtr, f32 scl) {
  struct tagpipeBasic_array *PipeEML;
  s64 mdl;
  tagpipeBasic_o *v9;
  struct tagpipeBasic_array *basicMy;
  struct tagpipeBasic_array *MyLine;

  switch (objPtr->id)
  {
    case 1u:
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
        goto LABEL_9;
      goto LABEL_8;
    case 2u:
      PipeEML = PipeEMS;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
        goto LABEL_9;
      goto LABEL_8;
    case 3u:
    case 4u:
    case 7u:
    case 8u:
      return;
    case 5u:
    case 6u:
      PipeEML = PipeMaka1;
      mdl = objPtr->mdl;
      if (mdl >= LODWORD(PipeEML->max_length))
        goto LABEL_8;
      goto LABEL_9;
    case 9u:
      PipeEML = PipeZMaka;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
        goto LABEL_9;
      goto LABEL_8;
    case 0xAu:
      PipeEML = PipeRBOX;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
        goto LABEL_9;
      goto LABEL_8;
    case 0xBu:
      PipeEML = PipeDMaka;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
        goto LABEL_9;
      goto LABEL_8;
    case 0xCu:
      PipeEML = PipeDRBOX;
      mdl = objPtr->mdl;
      if (mdl >= LODWORD(PipeEML->max_length))
      {
LABEL_8:
      }
LABEL_9:
      v9 = PipeEML->m_Items[mdl];
      goto LABEL_10;
    default:
      if (objPtr->id != 128)
        return;
      mymdlSclSet(basicMy->m_Items[0], scl);
      v9 = MyLine->m_Items[0];
LABEL_10:
      mymdlSclSet(v9, scl);
      return;
  }
}

// 0x153d8f0
tagPipeObject *objMyData(void) {
  struct tagPipeObject_array *ObjWork;
  s64 v4;
  Il2CppClass **v6;
  tagPipeObject_o *result;

  v4 = 0;
  do
  {
    if (v4 == -150)
      return 0;
    v6 = &ObjWork->obj.klass + v4--;
    result = v6[153];
  }
  while (result->id != 128);
  return result;
}

// 0x153b270
void objMyLoad(tagPipeObject *objPtr) {
  u64 *v3;
  s32 id;
  tagPipeEnemyInfo_o *v7;
  f32 v10;

  v3 = Allocate(tagPipeEnemyInfo);
  _ctor(v3, 0);
  sub_8518D0(&objPtr->pos, 0, 0.0);
  sub_8518D0(&objPtr->pos, 1, 0.0);
  sub_8518D0(&objPtr->vpos, 0, 0.0);
  sub_8518D0(&objPtr->vpos, 1, 0.0);
  id = 128;
  objPtr->id = 0x80;
  {
    else
    {
      id = objPtr->id;
    }
  }
  objPtr->offset = offsetCount;
  objPtr->enabled = 1;
  objPtr->count = 0;
  objPtr->action = 0;
  else
  {
    v7 = objInfo(id);
    if (!v7)
      return;
  }
  objPtr->w = v7->w;
  objMdlMotion(objPtr, 1, v10);
}

// 0x153fad0
void objMyStatusChange(tagPipeObject *objPtr, u8 action) {
  f32 v3;
  tagPipeObject_o *v5;
  s32 v6;
  tagPipeObject_o *v11;
  s32 v12;

  v5 = objPtr;
  if ((byte_3F59C46 & 1) != 0)
  {
    if (objPtr)
      goto LABEL_3;
  }
  else
  {
    if (v5)
    {
LABEL_3:
      v6 = action;
      if (action > 0xAu)
        return;
      goto LABEL_10;
    }
  }
  v5 = objMyData();
  v6 = action;
LABEL_10:
  switch (v6)
  {
    case 0:
      objMdlMotion(v5, 1, v3);
      v5->action = 0;
      v5->count = 0;
      attackCount = 0;
      break;
    case 1:
      if ((myStatus & 0xF) != 0)
      {
        v11 = v5;
        v12 = 4;
      }
      else
      {
        v11 = v5;
        v12 = 2;
      }
      objMdlMotion(v11, v12, v3);
      v5->action = 1;
      v5->count = 27;
      v5->status |= 0x240u;
      break;
    case 2:
      CameraAction = 6;
      objMdlMotion(v5, 3, v3);
      v5->action = 2;
      v5->count = 30;
      v5->status |= 0x208u;
      pipeEffSet(v5, 2u);
      attackCount = 0;
      pipeBulrSetLimit(10);
      break;
    case 10:
      pipeEffSet(v5, 4u);
      break;
    default:
      return;
  }
}

// 0x153bc40
void objOption(tagPipeObject *objPtr, u8 op) {
  s32 v3;
  u64 *v5;
  System_Array_o *v6;
  s32 offset;
  struct UnityEngine_Vector2_o *p_pos;
  f32 v11;
  f32 v14;
  u32 id;
  s32 v18;
  u64 v19;
  char v20;
  s32 v21;
  u8 v23;
  u8 action;
  s32 v28;
  u32 v29;

  v3 = op;
  v5 = Allocate(tagPipeObject);
  _ctor(v5, 0);
  v6 = NewSpecific(byte, 0x10u);
  InitializeArray_1543888(v6, Field__PrivateImplementationDetails__BDB9FC8E863887E419C7AC68F7268CDDE003770B);
  if (objPtr->action == 26)
  {
    offset = objPtr->offset;
    p_pos = &objPtr->pos;
    v11 = sub_851730(p_pos, 0);
    v14 = sub_851730(p_pos, 1);
    objCopy2(offset, v11, v14, 5u, 0, 0, 5, 100);
    return;
  }
  id = objPtr->id;
  if (id > 0xF)
    return;
  if (id == 10)
  {
    v18 = HIBYTE(myStatus) & 0xF;
    if (v18 == 2)
    {
      if ((dds3GetRandA("") & 0x1FF) >= v3)
        goto LABEL_50;
    }
    else
    {
      if (v18 != 1)
      {
        if ((myStatus & 0xF00) != 0)
          return;
        if (v3 + 128 > dds3GetRandA(""))
          return;
LABEL_50:
          goto LABEL_60;
        goto LABEL_58;
      }
      if (dds3GetRandA("") >= v3)
        goto LABEL_50;
    }
  }
  else if (v3 <= 0x63u)
  {
    objAdd(objPtr);
    v28 = v3;
    v29 = v3 - 20;
    if (v29 <= 0x3C)
      goto LABEL_41;
    while (v28)
    {
      objOptionInc(objPtr, v3);
      objAdd(objPtr);
      v28 = --v3;
      v29 = v3 - 20;
      if (v29 <= 0x3C)
      {
LABEL_41:
        if (((1LL << v29) & 0x1000010000100001LL) != 0)
          return;
      }
    }
  }
  else
  {
    if (v3 == 101)
    {
      objPtr->status |= 0x4000u;
      {
LABEL_60:
        objAdd(objPtr);
        return;
      }
LABEL_58:
      goto LABEL_60;
    }
    if (v3 == 100)
    {
      v19 = 0;
      v20 = 15;
      v21 = objPtr->offset;
      if (!LODWORD(v6[1].monitor))
      {
LABEL_29:
      }
      while (1)
      {
        v23 = *(&v6[2].klass + v19);
        action = objPtr->action;
        objMake(v5, v21, id, v23, action, 0);
        objAdd(v5);
        if (!v20)
          break;
        LOBYTE(id) = objPtr->id;
        --v20;
        ++v19;
        v21 = objPtr->offset;
        if (v19 >= LODWORD(v6[1].monitor))
          goto LABEL_29;
      }
    }
  }
}

// 0x153c560
void objOptionInc(tagPipeObject *objPtr, u8 op) {
  struct UnityEngine_Vector2_o *p_pos;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  UnityEngine_Vector4_o v11;

  *&v11.x = 0;
  *&v11.z = 0;
  if (op <= 0x13u)
  {
    objPtr->offset += 30;
  }
  else if (op <= 0x63u)
  {
    objPtr->offset += 30;
    p_pos = &objPtr->pos;
    sub_851730(p_pos, 0);
    sub_854930(&v11, 0);
    sub_851730(p_pos, 1);
    sub_854930(&v11, 1u);
    sub_854930(&v11, 2u);
    if (op <= 0x27u)
    {
      v7 = 10.0;
    }
    else if (op <= 0x3Bu)
    {
      v7 = -10.0;
    }
    else if (op <= 0x4Fu)
    {
      v7 = 5.0;
    }
    else
    {
      v7 = -5.0;
    }
    v8 = SDF_DEGtoRAD(v7);
    VecRotateZ(&v11, v8);
    sub_854710(&v11, 0);
    sub_8518D0(p_pos, 0, v9);
    sub_854710(&v11, 1u);
    sub_8518D0(p_pos, 1, v10);
  }
}

// 0x153c740
void objSetAction(tagPipeObject *objPtr, u8 action, s16 count) {
  objPtr->action = action;
  objPtr->count = count;
}

// 0x153fda0
void objVisibleAll(s8 value) {
  struct tagpipeBasic_array *PipeMaka1;
  s64 i;
  tagpipeBasic_o *v7;
  struct tagpipeBasic_array *PipeZMaka;
  tagpipeBasic_o *v11;
  tagpipeBasic_o *v12;
  struct tagpipeBasic_array *PipeCur;
  s64 j;
  tagpipeBasic_o *v19;
  struct tagpipeBasic_array *PipeCur2;
  s64 k;
  tagpipeBasic_o *v24;
  struct tagpipeBasic_array *PipeLine;
  s64 m;
  tagpipeBasic_o *v29;
  struct tagpipeBasic_array *PipeEMS;
  s64 n;
  tagpipeBasic_o *v34;
  struct tagpipeBasic_array *PipeEML;
  s64 ii;
  tagpipeBasic_o *v39;
  struct tagpipeBasic_array *PipeRBOX;
  s64 jj;
  tagpipeBasic_o *v44;

  for (i = 0; i != 50; ++i)
  {
    while (1)
    {
      v7 = PipeMaka1->m_Items[i];
      if (v7->enabled == 1)
        break;
      if (++i == 50)
        goto LABEL_15;
    }
    mymdlVisible(v7, value);
  }
LABEL_15:
  v11 = PipeZMaka->m_Items[0];
  if (v11->enabled == 1)
  {
    mymdlVisible(v11, value);
    if (LODWORD(PipeZMaka->max_length) > 1)
      goto LABEL_18;
LABEL_26:
  }
  if (LODWORD(PipeZMaka->max_length) <= 1)
    goto LABEL_26;
LABEL_18:
  v12 = PipeZMaka->m_Items[1];
  if (v12->enabled == 1)
  {
    mymdlVisible(v12, value);
  }
  for (j = 0; j != 10; ++j)
  {
    while (1)
    {
      v19 = PipeCur->m_Items[j];
      if (v19->enabled == 1)
        break;
      if (++j == 10)
        goto LABEL_36;
    }
    mymdlVisible(v19, value);
  }
LABEL_36:
  for (k = 0; k != 10; ++k)
  {
    while (1)
    {
      v24 = PipeCur2->m_Items[k];
      if (v24->enabled == 1)
        break;
      if (++k == 10)
        goto LABEL_45;
    }
    mymdlVisible(v24, value);
  }
LABEL_45:
  for (m = 0; m != 10; ++m)
  {
    while (1)
    {
      v29 = PipeLine->m_Items[m];
      if (v29->enabled == 1)
        break;
      if (++m == 10)
        goto LABEL_54;
    }
    mymdlVisible(v29, value);
  }
LABEL_54:
  for (n = 0; n != 50; ++n)
  {
    while (1)
    {
      v34 = PipeEMS->m_Items[n];
      if (v34->enabled == 1)
        break;
      if (++n == 50)
        goto LABEL_63;
    }
    mymdlVisible(v34, value);
  }
LABEL_63:
  for (ii = 0; ii != 50; ++ii)
  {
    while (1)
    {
      v39 = PipeEML->m_Items[ii];
      if (v39->enabled == 1)
        break;
      if (++ii == 50)
        goto LABEL_72;
    }
    mymdlVisible(v39, value);
  }
LABEL_72:
  for (jj = 0; jj != 10; ++jj)
  {
    while (1)
    {
      v44 = PipeRBOX->m_Items[jj];
      if (v44->enabled == 1)
        break;
      if (++jj == 10)
        return;
    }
    mymdlVisible(v44, value);
  }
}

// 0x1540300
void partsAdd(mnMyLink_h_tagPipeLinkData *pPtr, s32 offset) {
  s32 partsID;
  tagPipePartsInfo_o *PartsInfo;
  u32 v8;
  u8 v9;
  s64 v10;
  struct tagpipeParts_array *PartsWork;
  Il2CppClass **v14;
  u32 v15;
  tagPipePartsInfo_o *v18;
  struct tagpipeParts_array *v20;
  struct tagpipeParts_array *v22;
  struct tagpipeParts_array *v24;
  struct tagpipeParts_array *v28;
  tagpipeParts_o *v30;
  struct tagpipeParts_array *v32;
  struct tagpipeParts_array *v36;
  struct tagpipeBasic_array *PipeLine;
  s64 mdl;
  tagpipeBasic_o *v41;
  struct tagPipePosData_array *pData;
  struct tagpipeParts_array *v44;
  s64 v46;
  struct tagPipePosData_array *v48;
  struct tagpipeParts_array *v49;
  f32 v50;
  f32 v51;
  s64 v53;
  struct tagPipePosData_array *v55;
  struct tagpipeParts_array *v56;
  f32 v57;
  f32 v58;
  s64 v60;
  f32 v63;
  struct tagpipeBasic_array *v66;
  struct tagpipeParts_array *v67;
  struct tagpipeParts_array *v70;
  tagpipeParts_o *v72;
  struct tagpipeParts_array *v74;
  struct tagpipeBasic_array *PipeCur;
  struct tagpipeParts_array *v79;
  s64 v81;
  tagpipeBasic_o *v83;
  struct tagPipePosData_array *v85;
  struct tagpipeParts_array *v86;
  s64 v88;
  struct tagPipePosData_array *v90;
  struct tagpipeParts_array *v91;
  f32 v92;
  f32 v93;
  s64 v95;
  struct tagPipePosData_array *v97;
  struct tagpipeParts_array *v98;
  f32 v99;
  f32 v100;
  s64 v102;
  f32 v105;
  struct tagpipeParts_array *v109;
  tagpipeParts_o *v111;
  struct tagpipeParts_array *v113;
  struct tagpipeParts_array *v117;
  struct tagpipeBasic_array *PipeCur2;
  s64 v120;
  tagpipeBasic_o *v122;
  struct tagPipePosData_array *v124;
  struct tagpipeParts_array *v125;
  s64 v127;
  struct tagPipePosData_array *v129;
  struct tagpipeParts_array *v130;
  f32 v131;
  f32 v132;
  s64 v134;
  struct tagPipePosData_array *v136;
  struct tagpipeParts_array *v137;
  f32 v138;
  f32 v139;
  s64 v141;
  f32 v144;
  s64 v147;

  partsID = pPtr->partsID;
  PartsInfo = getPartsInfo(pPtr->partsID, *&offset);
  if (PartsInfo)
  {
    v8 = (partsID << 19 >> 24) & 0xFFFFFFFE;
    if (PartsInfo->inWay + PartsInfo->goWay == 7)
      v9 = v8 | 1;
    else
      v9 = v8 + 2;
  }
  else
  {
    v9 = 0;
  }
  v10 = 0;
  while (v10 != -20)
  {
    v14 = &PartsWork->obj.klass + v10--;
    if (BYTE4(v14[23]->_1.name) == 255)
    {
      v15 = v10 + 20;
      v18 = getPartsInfo(pPtr->partsID);
      v20 = PartsWork;
      v20->m_Items[v10 + 20]->id = v9;
      v22 = PartsWork;
      v22->m_Items[v10 + 20]->offset = offset;
      v24 = PartsWork;
      switch (v24->m_Items[v10 + 20]->id)
      {
        case 1u:
        case 3u:
          v28 = PartsWork;
          v30 = v28->m_Items[v10 + 20];
          v30->mdl = mymdlAddObject(PipeLine, 0xAu);
          v32 = PartsWork;
          if (v32->m_Items[v10 + 20]->mdl == 255)
            return;
          v36 = PartsWork;
          mdl = v36->m_Items[v10 + 20]->mdl;
          v41 = PipeLine->m_Items[mdl];
          pData = PosTable->pData;
          v44 = PartsWork;
          v46 = v44->m_Items[v10 + 20]->offset;
          sub_854710(&pData->m_Items[v46]->fields, 0);
          v48 = PosTable->pData;
          v49 = PartsWork;
          v51 = v50;
          v53 = v49->m_Items[v10 + 20]->offset;
          sub_854710(&v48->m_Items[v53]->fields, 1u);
          v55 = PosTable->pData;
          v56 = PartsWork;
          v58 = v57;
          v60 = v56->m_Items[v10 + 20]->offset;
          sub_854710(&v55->m_Items[v60]->fields, 2u);
          mymdlPosSet(v41, v51, v58, v63);
          v66 = PipeLine;
          v67 = PartsWork;
          if (v15 < LODWORD(v67->max_length))
            goto LABEL_122;
          goto LABEL_121;
        case 2u:
          v70 = PartsWork;
          v72 = v70->m_Items[v10 + 20];
          v72->mdl = mymdlAddObject(PipeCur, 0xAu);
          v74 = PartsWork;
          if (v74->m_Items[v10 + 20]->mdl == 255)
            return;
          v79 = PartsWork;
          v81 = v79->m_Items[v10 + 20]->mdl;
          v83 = PipeCur->m_Items[v81];
          v85 = PosTable->pData;
          v86 = PartsWork;
          v88 = v86->m_Items[v10 + 20]->offset;
          sub_854710(&v85->m_Items[v88]->fields, 0);
          v90 = PosTable->pData;
          v91 = PartsWork;
          v93 = v92;
          v95 = v91->m_Items[v10 + 20]->offset;
          sub_854710(&v90->m_Items[v95]->fields, 1u);
          v97 = PosTable->pData;
          v98 = PartsWork;
          v100 = v99;
          v102 = v98->m_Items[v10 + 20]->offset;
          sub_854710(&v97->m_Items[v102]->fields, 2u);
          mymdlPosSet(v83, v93, v100, v105);
          v67 = PartsWork;
          v66 = PipeCur;
          if (v15 < LODWORD(v67->max_length))
            goto LABEL_122;
          goto LABEL_121;
        case 4u:
          v109 = PartsWork;
          v111 = v109->m_Items[v10 + 20];
          v111->mdl = mymdlAddObject(PipeCur2, 0xAu);
          v113 = PartsWork;
          if (v113->m_Items[v10 + 20]->mdl == 255)
            return;
          v117 = PartsWork;
          v120 = v117->m_Items[v10 + 20]->mdl;
          v122 = PipeCur2->m_Items[v120];
          v124 = PosTable->pData;
          v125 = PartsWork;
          v127 = v125->m_Items[v10 + 20]->offset;
          sub_854710(&v124->m_Items[v127]->fields, 0);
          v129 = PosTable->pData;
          v130 = PartsWork;
          v132 = v131;
          v134 = v130->m_Items[v10 + 20]->offset;
          sub_854710(&v129->m_Items[v134]->fields, 1u);
          v136 = PosTable->pData;
          v137 = PartsWork;
          v139 = v138;
          v141 = v137->m_Items[v10 + 20]->offset;
          sub_854710(&v136->m_Items[v141]->fields, 2u);
          mymdlPosSet(v122, v132, v139, v144);
          v66 = PipeCur2;
          v67 = PartsWork;
          if (v15 >= LODWORD(v67->max_length))
          {
LABEL_121:
          }
LABEL_122:
          v147 = v67->m_Items[v10 + 20]->mdl;
          PipemdlRot(v66->m_Items[v147], v18);
          break;
        default:
          return;
      }
      return;
    }
  }
}

// 0x1541290
void partsDel(tagpipeParts *pPtr) {
  s64 mdl;
  struct tagpipeBasic_array *PipeLine;
  tagpipeBasic_o *v7;
  UnityEngine_GameObject_o *gameObject;

  mdl = pPtr->mdl;
  if (mdl != 255)
  {
    switch (pPtr->id)
    {
      case 1u:
      case 3u:
        if (mdl >= LODWORD(PipeLine->max_length))
          goto LABEL_9;
        goto LABEL_10;
      case 2u:
        PipeLine = PipeCur;
        if (mdl < LODWORD(PipeLine->max_length))
          goto LABEL_10;
        goto LABEL_9;
      case 4u:
        PipeLine = PipeCur2;
        if (mdl >= LODWORD(PipeLine->max_length))
        {
LABEL_9:
        }
LABEL_10:
        v7 = PipeLine->m_Items[mdl];
        v7->enabled = 0;
        dds3ObjectBaseOnFlag(&v7->basic, 1u, 0);
        gameObject = v7->basic->gameObject;
        cmpSetupObject(gameObject, 0);
        break;
      default:
        break;
    }
    pPtr->id = -1;
  }
}

// 0x1539cf0
void partsInit(void) {
  struct tagpipeParts_array *v2;
  pipeObject_c *v3;
  u64 v4;
  s32 *v5;
  s32 *PartsWork;
  Il2CppObject *v7;
  s64 v10;
  u64 v11;
  struct tagpipeParts_array *v12;

  v2 = NewSpecific(tagpipeParts, 0x14u);
  PartsWork = v2;
  v4 = 0;
  if ((v3->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
  }
  while (1)
  {
    if (v4 >= PartsWork[6])
      break;
    v7 = Allocate(tagpipeParts);
    v7[1].monitor = NewSpecific(sbyte, 5u);
    _ctor(v7, 0);
    v5 = &PartsWork[2 * v4++];
    *(v5 + 4) = v7;
      goto LABEL_9;
  }
  v10 = 23;
  v11 = 19;
  if ((v3->_2.bitflags2 & 2) == 0)
    goto LABEL_27;
LABEL_25:
  while (1)
  {
LABEL_27:
    v12 = PartsWork;
    *(*(&v12->obj.klass + v10) + 20LL) = -1;
    if (v10 == 4)
      break;
    v11 = --v10 - 4;
      goto LABEL_25;
  }
}

// 0x153f930
void pipeMyMakaAdd(s32 addMaka) {
  myMaka += addMaka;
  myAllMAKA += addMaka;
}

// 0x153f9c0
void pipeMyMakaSub(s32 subMaka) {
  myMaka -= subMaka;
}

// 0x153fa40
void pipeMyMakaSubRate(f32 subMakaRate) {
  myMaka = (myMaka - (myMaka * subMakaRate));
}

// 0x1541830
bool texLoad(char *filename, tagPipeTexture *texPtr) {
  Il2CppObject *mp;
  sdfTexHandle_t_o *v5;
  struct sdfMemHandle_t_o **p_mh;
  struct sdfMemHandle_t_o *mh;

  mp = texPtr->mp;
  v5 = sdfTexSet(mp);
  mh = texPtr->mh;
  p_mh = &texPtr->mh;
  *(p_mh - 1) = v5;
  if (mh)
  {
    *p_mh = 0;
    p_mh[1] = 0;
  }
  return 1;
}

// 0x15417b0
bool texRelease(tagPipeTexture *texPtr) {
  sdfTexHandle_t_o *th;

  th = texPtr->th;
  if (th)
  {
    sdfTexFreeDelayed(th);
    texPtr->th = 0;
  }
  return 1;
}

// 0x1537f20
void workRelease(void) {
  if (hWorkArea)
  {
    hWorkArea = 0;
  }
}
