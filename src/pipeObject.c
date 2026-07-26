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
    InitModel(0, 0, 0, 0, 0, 0, 0, 0);
    dds3UnitObjectBasicSetOt(0, 0);
    mdlGetMotionCtrlr(0, 0);
    Initmymdl();
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
  }
  else
  {
    th = v4->th;
  }
  sdfTexFreeDelayed(th);
  v4->th = 0;
  {
  }
  v8 = MakaTex;
  v9 = v8->m_Items[1];
  if ((byte_3F59CBB & 1) != 0)
  {
    v10 = v9->th;
    if (!v10)
  }
  else
  {
    v10 = v9->th;
  }
  sdfTexFreeDelayed(v10);
  v9->th = 0;
  {
  }
  v13 = MakaTex;
  v14 = v13->m_Items[2];
  if ((byte_3F59CBB & 1) != 0)
  {
    v15 = v14->th;
    if (!v15)
  }
  else
  {
    v15 = v14->th;
  }
  sdfTexFreeDelayed(v15);
  v14->th = 0;
  {
  }
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
      }
      v22 = 4LL * v12;
      v9 = *(&unk_33CD088 + v22);
      v10 = *(&unk_33CD0A0 + v22);
      v23 = &unk_33CD0B8;
    case 3u:
      v15 = pInfo->goWay;
      v16 = v15 - 1;
      if ((v15 - 1) >= 6 || ((0x2Bu >> v16) & 1) == 0)
      {
        v17 = 90.0;
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
      }
      v13 = v19 == 2;
      v14 = 90.0;
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
    SetVec(0, 0, 0, 0);
    Veccross(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    VecNormalize(0);
    VecZoom(0, 0);
}

// 0x153f0b0
void mdlTask(tagPipeObject *objPtr, tagpipeBasic *basicPtr, f32 x, f32 y, f32 z) {
    getPosTranslate(0, 0);
    Veccross(0, (sdfVector4_t){0}, (sdfVector4_t){0});
    VecNormalize(0);
    SDF_DEGtoRAD(0);
    MatRotateX(0, 0);
    MatRotateY(0, 0);
    MatRotateZ(0, 0);
    MatTrPos(0, 0);
    QurtFromMatrix(0, 0);
    dds3SetRotPoseSet(0, (sdfVector4_t){0});
    SetMdlRotation(0);
}

// 0x1537fb0
void mymdlStartUp(void) {
    partsInit();
    mymdlInit(0, 0, 0, 0, 0, 0);
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
    objMake(0, 0, 0, 0, 0, 0);
    objAdd(0);
}

// 0x153cc80
void objAddDRBOX(s32 offset, f32 x, f32 y) {
    objMake(0, 0, 0, 0, 0, 0);
    objAdd(0);
}

// 0x153c920
void objCopy(s32 offset, f32 x, f32 y, u8 id, u8 action, s16 count, s16 num) {
    objMake(0, 0, 0, 0, 0, 0);
    dds3GetRandA(0);
    objAdd(0);
}

// 0x153c0b0
void objCopy2(s32 offset, f32 x, f32 y, u8 id, u8 action, s16 count, s16 num, s32 w) {
    objMake(0, 0, 0, 0, 0, 0);
    dds3GetRandA(0);
    objAdd(0);
}

// 0x153d190
void objDel(tagPipeObject *objPtr) {
  objMdlDel(objPtr);
  objPtr->id = -1;
}

// 0x153d610
void objDelAll(void) {
    objMdlDel(0);
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
    dds3GetRandA(0);
    objInfo(0);
    return 0;
}

// 0x153b980
u8 objMake(tagPipeObject *objPtr, s32 offset, u8 id, u8 way, u8 action, u8 value) {
    dds3GetRandA(0);
    objInfo(0);
    return 0;
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
    case 2u:
      PipeEML = PipeEMS;
    case 3u:
    case 4u:
    case 7u:
    case 8u:
      return;
    case 5u:
    case 6u:
      PipeEML = PipeMaka1;
      v16 = 50;
    case 9u:
      PipeEML = PipeZMaka;
      v16 = 2;
    case 0xAu:
      PipeEML = PipeRBOX;
      v16 = 10;
      objPtr->mdl = mymdlAddObject(PipeEML, v16);
      return;
    case 0xBu:
      mdl = mymdlAddObject(PipeDMaka, 4u);
      objPtr->mdl = mdl;
      if (mdl == 0xFF)
        return;
      v24 = mdl;
      if (LODWORD(PipeDMaka->max_length) > mdl)
    case 0xCu:
      v26 = mymdlAddObject(PipeDRBOX, 2u);
      objPtr->mdl = v26;
      if (v26 == 0xFF)
        return;
      PipeDMaka = PipeDRBOX;
      v24 = v26;
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
    case 2u:
      PipeEML = PipeEMS;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
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
    case 9u:
      PipeEML = PipeZMaka;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
    case 0xAu:
      PipeEML = PipeRBOX;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
    case 0xBu:
      PipeEML = PipeDMaka;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
    case 0xCu:
      PipeEML = PipeDRBOX;
      mdl = objPtr->mdl;
      v10 = PipeEML->m_Items[mdl];
      if ((byte_3F59CA9 & 1) == 0)
    default:

      {
        if (id != 129)
          return;
        basicMy = MyLine;
        if (!LODWORD(basicMy->max_length))
      }
      v10 = basicMy->m_Items[0];
      p_model = &v10->model;
      Color = mdlGetColor(p_model);
      mdlSetColor(p_model, Color & 0xFFFFFF | (alpha << 24), 0);
      return;
  }
}

// 0x153f690
void objMdlColorSet(tagPipeObject *objPtr, u32 color) {
  pipeObject_c *v5;
  struct pipeObject_StaticFields *static_fields;

  switch (objPtr->id)
  {
    case 1u:
      if (objPtr->mdl < LODWORD(PipeEML->max_length))
        return;
    case 2u:
      if (objPtr->mdl >= LODWORD(PipeEMS->max_length))
      return;
    case 3u:
    case 4u:
    case 7u:
    case 8u:
      return;
    case 5u:
    case 6u:
      if (objPtr->mdl >= LODWORD(PipeMaka1->max_length))
      return;
    case 9u:
      if (objPtr->mdl >= LODWORD(PipeZMaka->max_length))
      return;
    case 0xAu:
      if (objPtr->mdl >= LODWORD(PipeRBOX->max_length))
      return;
    case 0xBu:
      if (objPtr->mdl >= LODWORD(PipeDMaka->max_length))
      return;
    case 0xCu:
      if (objPtr->mdl >= LODWORD(PipeDRBOX->max_length))
      return;
    default:
      if (objPtr->id == 128)
      {
        static_fields = v5->static_fields;
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
      case 2u:
        PipeEML = PipeEMS;
        mdl = objPtr->mdl;
        if (mdl < LODWORD(PipeEML->max_length))
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
      case 9u:
        PipeEML = PipeZMaka;
        mdl = objPtr->mdl;
        if (mdl < LODWORD(PipeEML->max_length))
      case 0xAu:
        PipeEML = PipeRBOX;
        mdl = objPtr->mdl;
        if (mdl < LODWORD(PipeEML->max_length))
      case 0xBu:
        PipeEML = PipeDMaka;
        mdl = objPtr->mdl;
        if (mdl < LODWORD(PipeEML->max_length))
      case 0xCu:
        PipeEML = PipeDRBOX;
        mdl = objPtr->mdl;
        v9 = PipeEML->m_Items[mdl];
        v9->enabled = 0;
        dds3ObjectBaseOnFlag(&v9->basic, 1u, 0);
        gameObject = v9->basic->gameObject;
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
        }
        cmpSetupObject(gameObject, 0);
        break;
    }
  }
}

// 0x153b500
void objMdlMotion(tagPipeObject *objPtr, s32 motion, f32 speed) {
    mdlSmoothLoopMotion(0, 0, 0, 0, 0);
}

// 0x153e020
void objMdlPosSet(tagPipeObject *objPtr) {
    getPosTranslate(0, 0);
    mymdlPosSet(0, 0, 0, 0);
    mdlTask(0, 0, 0, 0, 0);
    eglSetOt(0);
    eglLinkTest(0, 0, 0, 0, 0, 0, 0, 0);
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
    case 2u:
      PipeEML = PipeEMS;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
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
    case 9u:
      PipeEML = PipeZMaka;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
    case 0xAu:
      PipeEML = PipeRBOX;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
    case 0xBu:
      PipeEML = PipeDMaka;
      mdl = objPtr->mdl;
      if (mdl < LODWORD(PipeEML->max_length))
    case 0xCu:
      PipeEML = PipeDRBOX;
      mdl = objPtr->mdl;
      v9 = PipeEML->m_Items[mdl];
    default:
      if (objPtr->id != 128)
        return;
      mymdlSclSet(basicMy->m_Items[0], scl);
      v9 = MyLine->m_Items[0];
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
    objInfo(0);
    objMdlMotion(0, 0, 0);
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
  }
  else
  {
    if (v5)
    {
      v6 = action;
      if (action > 0xAu)
        return;
    }
  }
  v5 = objMyData();
  v6 = action;
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
    objCopy2(0, 0, 0, 0, 0, 0, 0, 0);
    dds3GetRandA(0);
    objAdd(0);
    objOptionInc(0, 0);
    objMake(0, 0, 0, 0, 0, 0);
}

// 0x153c560
void objOptionInc(tagPipeObject *objPtr, u8 op) {
    SDF_DEGtoRAD(0);
    VecRotateZ(0, 0);
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
    }
    mymdlVisible(v7, value);
  }
  v11 = PipeZMaka->m_Items[0];
  if (v11->enabled == 1)
  {
    mymdlVisible(v11, value);
    if (LODWORD(PipeZMaka->max_length) > 1)
  }
  if (LODWORD(PipeZMaka->max_length) <= 1)
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
    }
    mymdlVisible(v19, value);
  }
  for (k = 0; k != 10; ++k)
  {
    while (1)
    {
      v24 = PipeCur2->m_Items[k];
      if (v24->enabled == 1)
        break;
      if (++k == 10)
    }
    mymdlVisible(v24, value);
  }
  for (m = 0; m != 10; ++m)
  {
    while (1)
    {
      v29 = PipeLine->m_Items[m];
      if (v29->enabled == 1)
        break;
      if (++m == 10)
    }
    mymdlVisible(v29, value);
  }
  for (n = 0; n != 50; ++n)
  {
    while (1)
    {
      v34 = PipeEMS->m_Items[n];
      if (v34->enabled == 1)
        break;
      if (++n == 50)
    }
    mymdlVisible(v34, value);
  }
  for (ii = 0; ii != 50; ++ii)
  {
    while (1)
    {
      v39 = PipeEML->m_Items[ii];
      if (v39->enabled == 1)
        break;
      if (++ii == 50)
    }
    mymdlVisible(v39, value);
  }
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
    getPartsInfo(0);
    mymdlAddObject(0, 0);
    mymdlPosSet(0, 0, 0, 0);
    PipemdlRot(0, 0);
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
      case 2u:
        PipeLine = PipeCur;
        if (mdl < LODWORD(PipeLine->max_length))
      case 4u:
        PipeLine = PipeCur2;
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
  while (1)
  {
    if (v4 >= PartsWork[6])
      break;
    v7 = Allocate(tagpipeParts);
    v7[1].monitor = NewSpecific(sbyte, 5u);
    _ctor(v7, 0);
    v5 = &PartsWork[2 * v4++];
    *(v5 + 4) = v7;
  }
  v10 = 23;
  v11 = 19;
  if ((v3->_2.bitflags2 & 2) == 0)
  while (1)
  {
    v12 = PartsWork;
    *(*(&v12->obj.klass + v10) + 20LL) = -1;
    if (v10 == 4)
      break;
    v11 = --v10 - 4;
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
  pipeObject_c *v2;
  struct pipeObject_StaticFields *static_fields;

  static_fields = v2->static_fields;
  if (static_fields->hWorkArea)
  {
    static_fields->hWorkArea = 0;
  }
}
