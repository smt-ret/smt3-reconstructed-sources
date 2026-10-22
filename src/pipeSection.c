#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct fldTitleName fldTitleName;
typedef struct mnMyLink_h_tagPipeLinkInfo mnMyLink_h_tagPipeLinkInfo;
typedef struct tagMakaObject tagMakaObject;
typedef struct tagPipeObject tagPipeObject;
typedef struct tagPipePartsInfo tagPipePartsInfo;
typedef struct tagPipePosTable tagPipePosTable;
typedef struct tagPipeTable tagPipeTable;
typedef struct tagpipeBasic tagpipeBasic;
typedef struct tagpipeParts tagpipeParts;

static u32 F059_SMG;
static u32 FESE_53_SMG;
static s32 F059_01;
static s32 F059_02;
static s32 F059_04;
static s32 F059_05;
static s32 F059_06;
static s32 F059_08;
static s32 F059_09;
static s32 FESE_53_SE00;
static f32 AddHit;
static s32 startTime;
static bool checkTime;
static s32 offsetCount;
static s32 nowIndex;
static s32 partsCount;
static s32 myIndex;
static f32 lrRad;
static f32 udRad;
static s32 pipeIndex;
static u8 attackCount;
static s32 myMaka;
static s32 ZmakaCount;
static s32 playerDAMAGE;
static s8 rBoxNum;
static s8 offsetStep;
static s8 offsetStepCount;
static s8 CameraAction;
static s8 camMode;
static s16 myStatus;
static mnMyLink_h_tagPipeLinkInfo *linkHeader00;
static tagPipePosTable *PosTable;
static tagPipeTable *obTable;
static s32 dbMAKANum;
static s32 dbZMAKANum;
static s32 dbRBOXNum;
static s32 myAllMAKA;
static s32 Hitcount;

void ActionAbsorp(tagPipeObject *objPtr);
void ActionBound(tagPipeObject *objPtr);
void ActionCrush(tagPipeObject *objPtr);
void ActionDeath(tagPipeObject *objPtr);
void ActionHm(tagPipeObject *objPtr);
void ActionKey(tagPipeObject *objPtr);
void ActionRot(tagPipeObject *objPtr);
void ActionSlide(tagPipeObject *objPtr);
void ActionZMotion(tagPipeObject *objPtr);
void AddCamera(void);
void ButtonGuideDispOut(void);
void ButtonGuideDispSet(char *name, bool timer, bool empty, s32 waitTimer);
void CalcCamera(void);
void CamActionQuake(void);
bool DDS3_PADCHECK_PRESS(s32 id);
bool DDS3_PADCHECK_TRIG(s32 id);
void EmTask(tagPipeObject *objPtr);
void InitLoadModel(void);
void Initmymdl(void);
bool IsFinished(fldTitleName *this);
void LoadKeys(s32 type, char *key, char *path);
void MyAction(tagPipeObject *objPtr);
void MyDraw(tagPipeObject *objPtr);
void MyHitAction(tagPipeObject *objPtr);
void MySound(tagPipeObject *objPtr);
void MyTask(tagPipeObject *objPtr);
void ObjectDraw(void);
void ObjectSound(void);
void PipeCamera(void);
void PipeCameraAction(void);
void PipeCameraAction3(void);
void PipeMain(void);
bool PipeTexRelease(void);
void PlayerStatusSetUp(void);
f32 SDF_DEGtoRAD(f32 n);
void SetMdlPosition(tagpipeBasic **pWork);
f32 VecNormalize(sdfVector4_t *pVec);
void VecRotateZ(sdfVector4_t *pVec, f32 Radian);
void VecZoom(sdfVector4_t *pVec, f32 s);
f32 VecdotRad(sdfVector4_t vec1, sdfVector4_t vec2);
s32 datGetPlayerParam(s32 id);
dds3Basic_t *dds3AddAreaBasic(u32 serialID, char *pName);
dds3Basic_t *dds3AddScene(void);
void dds3DeleteScene(dds3Basic_t **scene);
void dds3FadeIn(u32 r, u32 g, u32 b, u32 frame);
void dds3FadeOut(u32 r, u32 g, u32 b, u32 frame);
dds3Basic_t *dds3GetControlScene(void);
u32 dds3GetRandA(char *name);
void dds3SetActiveScene(dds3Basic_t *scene);
void dds3SetAmbientColor(u32 frame, sdfVector4_t col);
void dds3SetControlScene(dds3Basic_t **scene);
void dds3SetFogColor(u32 frame, sdfVector4_t col);
void dds3SetFogPara(u32 frame, f32 max, f32 min, f32 near, f32 far);
void dds3SetLightColor(u32 frame, u32 no, sdfVector4_t col);
void dds3SetLightDir(u32 frame, u32 no, sdfVector4_t dir);
void eglLinkAlpha(s32 mode);
void eglLinkTest(s32 ate, s32 atst, s32 aref, s32 afail, s32 date, s32 datm, s32 zte, s32 ztst);
void eglSetOt(s32 ot);
tagPipePartsInfo *getPartsInfo(s16 partsID);
void makaAdd(s32 maka, f32 x, f32 y);
void makaDraw(tagMakaObject *makaPtr);
void makaInit(void);
void mymdlStartUp(void);
s32 objAdd(tagPipeObject *objPtr);
void objAddDMaka(s32 offset, f32 x, f32 y);
void objAddDRBOX(s32 offset, f32 x, f32 y);
void objDelAll(void);
void objInitMyAdd(void);
u8 objMake(tagPipeObject *objPtr, s32 offset, u8 id, u8 way, u8 action, u8 value);
void objMdlAlphaSet(tagPipeObject *objPtr, u8 alpha);
void objMdlDel(tagPipeObject *objPtr);
void objMdlPosSet(tagPipeObject *objPtr);
void objMdlSclSet(tagPipeObject *objPtr, f32 scl);
tagPipeObject *objMyData(void);
void objMyStatusChange(tagPipeObject *objPtr, u8 action);
void objVisibleAll(s8 value);
s32 p2sdFadeOut(s32 a);
s32 p2sdPlayBGM(s32 a);
void p2sdPlaySE_20173184(char *define_name);
void partsDel(tagpipeParts *pPtr);
void partsInit(void);
void pipeBulrLimit(void);
void pipeDataRelease(void);
void pipeDrawSection(void);
void pipeEffCal(void);
void pipeEffDraw(void);
void pipeEffRelease(void);
void pipeEffSet(tagPipeObject *objPtr, u8 effNum);
void pipeEnd(void);
s32 pipeFileLoad(char *filename, tagPipePosTable **posPtr, tagPipeTable **tabPtr, mnMyLink_h_tagPipeLinkInfo **linkInfo);
s32 pipeMainSection(void);
void pipeOffset(void);
void pipeStart(void);
f32 sdfFabs(f32 c);

// 0x154a200
void ActionAbsorp(tagPipeObject *objPtr) {
  int16x4_t v2;
  int16x4_t v3;
  tagPipeObject_o *v5;
  tagPipeObject_o *v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  s32 count;

  else
  {
    v5 = objMyData(pipeObject);
    if (objPtr->count < 0)
      return;
  }
  v6 = v5;
  v7 = sub_851730(&objPtr->pos, 0);
  v2.n64_u16[0] = objPtr->count;
  v8 = v7;
  v9 = sub_851730(&v6->pos, 0);
  sub_8518D0(&objPtr->pos, 0, ((v8 * vmovl_s16(v2).n128_i32[0]) + (v9 * (100 - objPtr->count))) / 100.0);
  v10 = sub_851730(&objPtr->pos, 1);
  v3.n64_u16[0] = objPtr->count;
  v11 = v10;
  v12 = sub_851730(&v6->pos, 1);
  sub_8518D0(&objPtr->pos, 1, ((v11 * vmovl_s16(v3).n128_i32[0]) + (v12 * (100 - objPtr->count))) / 100.0);
  objPtr->offset = v6->offset;
  count = objPtr->count;
  if (count >= 1)
  {
    count = (count + -16.667);
    objPtr->count = count;
  }
  if (count < 0)
    objPtr->count = 0;
}

// 0x1548150
void ActionBound(tagPipeObject *objPtr) {
  s32 count;
  s32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 v26;
  UnityEngine_Vector4_o v27;
  UnityEngine_Vector4_o v28;
  UnityEngine_Vector4_o pVec;

  *&pVec.x = 0;
  *&pVec.z = 0;
  *&v28.x = 0;
  *&v28.z = 0;
  *&v27.x = 0;
  *&v27.z = 0;
  sub_851730(&objPtr->vpos, 0);
  sub_854930(&pVec, 0);
  sub_851730(&objPtr->vpos, 1);
  sub_854930(&pVec, 1u);
  sub_854930(&pVec, 2u);
  VecNormalize(&pVec);
  count = objPtr->count;
  if (objPtr->id == 128)
  {
    if (count >= 6)
    {
      v5 = 150.0;
      goto LABEL_11;
    }
    v4 = 30 * count;
  }
  else
  {
    if (count >= 6)
    {
      v5 = 50.0;
      goto LABEL_11;
    }
    v4 = 10 * count;
  }
  v5 = v4;
LABEL_11:
  VecZoom(&pVec, v5);
  v6 = sub_851730(&objPtr->pos, 0);
  sub_854710(&pVec, 0);
  sub_8518D0(&objPtr->pos, 0, v6 + v7);
  v8 = sub_851730(&objPtr->pos, 1);
  sub_854710(&pVec, 1u);
  sub_8518D0(&objPtr->pos, 1, v8 + v9);
  v10 = sub_851730(&objPtr->pos, 0);
  v12 = sub_851730(&objPtr->pos, 1);
  if (((v10 * v10) + (v12 * v12)) > 250000.0)
  {
    sub_851730(&objPtr->pos, 0);
    sub_854930(&v28, 0);
    sub_851730(&objPtr->pos, 1);
    sub_854930(&v28, 1u);
    sub_854930(&v28, 2u);
    sub_851730(&objPtr->vpos, 0);
    sub_854930(&v27, 0);
    sub_851730(&objPtr->vpos, 1);
    sub_854930(&v27, 1u);
    sub_854930(&v27, 2u);
    v13 = VecdotRad(v28, v27);
    sub_854710(&v28, 0);
    if (v14 != 0.0)
    {
      sub_854710(&v27, 0);
      if (v15 != 0.0)
      {
        sub_854710(&v28, 1u);
        v17 = v16;
        sub_854710(&v28, 0);
        v19 = v18;
        sub_854710(&v27, 1u);
        v21 = v20;
        sub_854710(&v27, 0);
        if ((v17 / v19) < (v21 / v22))
          v13 = -v13;
      }
    }
    VecRotateZ(&v27, v13 + v13);
    sub_854710(&v27, 0);
    sub_8518D0(&objPtr->vpos, 0, -v23);
    sub_854710(&v27, 1u);
    sub_8518D0(&objPtr->vpos, 1, -v24);
    sub_851730(&objPtr->pos, 0);
    sub_854930(&pVec, 0);
    sub_851730(&objPtr->pos, 1);
    sub_854930(&pVec, 1u);
    sub_854930(&pVec, 2u);
    VecNormalize(&pVec);
    VecZoom(&pVec, 500.0);
    sub_854710(&pVec, 0);
    sub_8518D0(&objPtr->pos, 0, v25);
    sub_854710(&pVec, 1u);
    sub_8518D0(&objPtr->pos, 1, v26);
  }
  if (objPtr->count)
    --objPtr->count;
}

// 0x1549c50
void ActionCrush(tagPipeObject *objPtr) {
  f32 v4;
  f32 v5;
  tagPipeObject_o *v6;
  tagPipeObject_o *v7;
  UnityEngine_Vector4_o v9;

  *&v9.x = 0;
  *&v9.z = 0;
  objPtr->offset += 11;
    goto LABEL_9;
LABEL_10:
  while (1)
  {
    v7 = chHitObj(objPtr, 0.0);
    if (!v7)
      break;
    while (1)
    {
      v6 = v7;
      sub_851730(&objPtr->pos, 0);
      sub_851730(&v6->pos, 0);
      sub_854930(&v9, 0);
      sub_851730(&objPtr->pos, 1);
      sub_851730(&v6->pos, 1);
      sub_854930(&v9, 1u);
      sub_854930(&v9, 2u);
      VecNormalize(&v9);
      if (v6->id <= 2u)
      {
        v6->action = 17;
        v6->count = 50;
        sub_854710(&v9, 0);
        sub_8518D0(&v6->vpos, 0, -v4);
        sub_854710(&v9, 1u);
        sub_8518D0(&v6->vpos, 1, -v5);
          goto LABEL_10;
      }
      else
      {
          goto LABEL_10;
      }
LABEL_9:
        break;
      v7 = chHitObj(objPtr, 0.0);
      if (!v7)
        goto LABEL_13;
    }
  }
LABEL_13:
  if (objPtr->count)
    --objPtr->count;
}

// 0x1549e50
void ActionDeath(tagPipeObject *objPtr) {
  u64 *v3;
  u16 status;
  s16 count;
  u8 v8;
  u16 v10;
  s32 offset;
  f32 v12;
  f32 v13;

  v3 = Allocate(tagPipeObject);
  _ctor(v3, 0);
  status = objPtr->status;
  objPtr->status = status & 0xEFFF;
  count = objPtr->count;
  if (count)
  {
    v8 = count - 32;
    objPtr->count = count - 32;
  }
  else if ((status & 0x2000) != 0)
  {
    v8 = 0;
  }
  else
  {
    pipeEffSet(objPtr, 4u);
    v10 = objPtr->status;
    v8 = 0x80;
    objPtr->count = 128;
    objPtr->status = v10 | 0x3000;
    if ((v10 & 0x4000) != 0)
    {
      offset = objPtr->offset;
      objMake(v3, offset + 40, 9u, 0, 0x15u, 0);
      v12 = sub_851730(&objPtr->pos, 0);
      sub_8518D0((v3 + 3), 0, v12);
      v13 = sub_851730(&objPtr->pos, 1);
      sub_8518D0((v3 + 3), 1, v13);
      *(v3 + 25) = 160;
      objAdd(v3);
      v8 = objPtr->count;
    }
  }
  objPtr->offset += 6;
  objMdlAlphaSet(objPtr, v8);
}

// 0x1549830
void ActionHm(tagPipeObject *objPtr) {
  tagPipeObject_o *v4;
  u32 action;
  f32 v6;
  f32 *p_pos;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v14;
  f32 v15;
  f32 v16;
  UnityEngine_Vector4_o v17;

  *&v17.x = 0;
  *&v17.z = 0;
  v4 = objMyData();
  *&v17.x = 0;
  *&v17.z = 0;
  action = objPtr->action;
  if (action >= 0xA)
    v6 = 8.0;
  else
    v6 = 4.0;
  if (action == 9 || action == 7)
    v6 = -v6;
  p_pos = &v4->pos;
  sub_851730(&v4->pos, 0);
  sub_851730(&objPtr->pos, 0);
  sub_854930(&v17, 0);
  sub_851730(p_pos, 1);
  sub_851730(&objPtr->pos, 1);
  sub_854930(&v17, 1u);
  sub_854930(&v17, 2u);
  VecNormalize(&v17);
  VecZoom(&v17, v6);
  v8 = sub_851730(&objPtr->pos, 0);
  sub_854710(&v17, 0);
  sub_8518D0(&objPtr->pos, 0, v8 + v9);
  v10 = sub_851730(&objPtr->pos, 1);
  sub_854710(&v17, 1u);
  sub_8518D0(&objPtr->pos, 1, v10 + v11);
  if ((objPtr->action | 2) == 0xA)
  {
    v12 = sub_851730(&objPtr->pos, 0);
    v14 = sub_851730(&objPtr->pos, 1);
    if (((v12 * v12) + (v14 * v14)) > 250000.0)
    {
      sub_851730(&objPtr->pos, 0);
      sub_854930(&v17, 0);
      sub_851730(&objPtr->pos, 1);
      sub_854930(&v17, 1u);
      sub_854930(&v17, 2u);
      VecNormalize(&v17);
      VecZoom(&v17, 500.0);
      sub_854710(&v17, 0);
      sub_8518D0(&objPtr->pos, 0, v15);
      sub_854710(&v17, 1u);
      sub_8518D0(&objPtr->pos, 1, v16);
    }
  }
}

// 0x15485d0
void ActionKey(tagPipeObject *objPtr) {
  f32 v3;
  f32 v8;
  f32 v9;
  f32 v10;
  s64 v12;
  s64 v13;
  f32 v18;
  struct UnityEngine_Vector2_o *p_vpos;
  f32 v22;
  f32 v23;
  f32 udRad;
  f32 v28;
  f32 v29;
  f32 lrRad;
  struct UnityEngine_Vector2_o *v35;
  f32 v36;
  f32 v38;
  f32 v39;
  f32 v41;
  f32 v44;
  pipeSection_c *v45;
  f32 v47;
  s16 v48;
  s32 v49;
  f32 v50;
  f32 v51;
  f32 v54;
  f32 v55;
  f32 v56;
  f32 v60;
  pipeSection_c *v62;
  f32 v64;
  s16 v65;
  s32 v66;
  f32 v67;
  f32 v68;
  f32 v71;
  f32 v72;
  f32 v73;
  f32 v75;
  f32 v76;
  struct UnityEngine_Vector2_o *p_pos;
  f32 v78;
  f32 v79;
  f32 v80;
  f32 v81;
  UnityEngine_Vector4_o v83;

  v3 = 0.0;
  *&v83.x = 0;
  *&v83.z = 0;
  sub_854690(&v83.x, 0.0, 0.0, 0.0, 0.0);
  else if (!DDS3_PADCHECK_TRIG(3))
  {
    goto LABEL_21;
  }
  if ((objPtr->status & 0x200) == 0)
  {
    objMyStatusChange(objPtr, 1u);
    if (objPtr->action == 1 && objPtr->count >= 3)
    {
      ++attackCount;
      if ((objPtr->status & 0x400) != 0)
        goto LABEL_19;
      goto LABEL_22;
    }
  }
LABEL_21:
  if ((objPtr->status & 0x400) != 0)
  {
LABEL_19:
    v8 = 4.0;
    v9 = 20.0;
    v10 = 1.0;
    v3 = 2.0;
    goto LABEL_46;
  }
LABEL_22:
  v10 = 0.0;
  v9 = 0.0;
  v8 = 0.0;
  v12 = myStatus >> 4;
  if (v12 <= 2)
  {
    v3 = flt_33CD118[v12];
    v13 = 4 * v12;
    v10 = *(&unk_33CD124 + v13);
    v9 = *(&unk_33CD130 + v13);
    v8 = *(&unk_33CD13C + v13);
      goto LABEL_47;
    goto LABEL_27;
  }
LABEL_46:
  {
LABEL_47:
    if (DDS3_PADCHECK_PRESS(6))
      goto LABEL_48;
    goto LABEL_29;
  }
LABEL_27:
    goto LABEL_47;
  if (DDS3_PADCHECK_PRESS(6))
  {
LABEL_48:
    udRad = udRad - v3;
    if (sdfFabs(udRad) > 10.0)
    {
      udRad = -10.0;
    }
    p_vpos = &objPtr->vpos;
    v28 = sub_851730(&objPtr->vpos, 1);
    sub_8518D0(&objPtr->vpos, 1, v28 - v8);
    v29 = sub_851730(&objPtr->vpos, 1);
    v23 = -v9;
    if (v29 < -v9)
      goto LABEL_60;
    goto LABEL_61;
  }
LABEL_29:
  if (DDS3_PADCHECK_PRESS(7))
  {
    udRad = v3 + udRad;
    v18 = udRad;
    if (sdfFabs(v18) > 10.0)
    {
      udRad = 10.0;
    }
    p_vpos = &objPtr->vpos;
    v22 = sub_851730(&objPtr->vpos, 1);
    sub_8518D0(&objPtr->vpos, 1, v8 + v22);
    if (sub_851730(&objPtr->vpos, 1) > v9)
    {
      v23 = v9;
LABEL_60:
      sub_8518D0(p_vpos, 1, v23);
    }
  }
LABEL_61:
  else if (DDS3_PADCHECK_PRESS(4))
  {
LABEL_64:
    lrRad = lrRad - v3;
    if (sdfFabs(lrRad) > 10.0)
    {
      lrRad = -10.0;
    }
    v35 = &objPtr->vpos;
    v36 = sub_851730(&objPtr->vpos, 0);
    sub_8518D0(&objPtr->vpos, 0, v36 - v8);
    v38 = sub_851730(&objPtr->vpos, 0);
    v39 = -v9;
    if (v38 >= -v9)
      goto LABEL_96;
LABEL_95:
    sub_8518D0(v35, 0, v39);
    goto LABEL_96;
  }
  if (DDS3_PADCHECK_PRESS(5))
  {
    lrRad = v3 + lrRad;
    v41 = lrRad;
    if (sdfFabs(v41) > 10.0)
    {
      lrRad = 10.0;
    }
    v35 = &objPtr->vpos;
    v44 = sub_851730(&objPtr->vpos, 0);
    sub_8518D0(&objPtr->vpos, 0, v8 + v44);
    if (sub_851730(&objPtr->vpos, 0) > v9)
    {
      v39 = v9;
      goto LABEL_95;
    }
  }
LABEL_96:
  else
  {
    v47 = udRad;
    if (v47 == 0.0)
      goto LABEL_99;
  }
  v48 = *&v45->_2.bitflags1;
  if ((v48 & 0x200) != 0)
  {
    v49 = v48 & 0x200;
    if (v47 <= 0.0)
    {
LABEL_105:
      v50 = v47 + 0.5;
      udRad = v47 + 0.5;
      if ((v45->_2.bitflags2 & 2) != 0)
        goto LABEL_109;
LABEL_119:
      udRad = v50;
      if ((v45->_2.bitflags2 & 2) == 0)
        goto LABEL_120;
      goto LABEL_100;
    }
  }
  else
  {
    v49 = 0;
    if (v47 <= 0.0)
      goto LABEL_105;
  }
  v50 = v47 + -0.5;
  udRad = v47 + -0.5;
  if ((v45->_2.bitflags2 & 2) == 0)
    goto LABEL_119;
LABEL_109:
    goto LABEL_119;
  udRad = v50;
  if ((v45->_2.bitflags2 & 2) == 0)
    goto LABEL_120;
LABEL_100:
LABEL_120:
  v51 = udRad;
  if (sdfFabs(v51) < 0.5)
  {
    udRad = 0.0;
  }
  if (sub_851730(&objPtr->vpos, 1) != 0.0)
  {
    v54 = sub_851730(&objPtr->vpos, 1);
    v55 = sub_851730(&objPtr->vpos, 1);
    if (v54 <= 0.0)
      v56 = v10 + v55;
    else
      v56 = v55 - v10;
    sub_8518D0(&objPtr->vpos, 1, v56);
    udRad = v56;
  }
  v60 = sub_851730(&objPtr->vpos, 1);
  if (sdfFabs(v60) < v10)
    sub_8518D0(&objPtr->vpos, 1, 0.0);
  else
  {
    v64 = lrRad;
    if (v64 == 0.0)
      goto LABEL_144;
  }
  v65 = *&v62->_2.bitflags1;
  if ((v65 & 0x200) == 0)
  {
    v66 = 0;
    if (v64 <= 0.0)
      goto LABEL_150;
LABEL_159:
    v67 = v64 + -0.5;
    lrRad = v64 + -0.5;
    if ((v62->_2.bitflags2 & 2) != 0)
      goto LABEL_153;
LABEL_163:
    lrRad = v67;
    if ((v62->_2.bitflags2 & 2) == 0)
      goto LABEL_164;
    goto LABEL_145;
  }
  v66 = v65 & 0x200;
  if (v64 > 0.0)
    goto LABEL_159;
LABEL_150:
  v67 = v64 + 0.5;
  lrRad = v64 + 0.5;
  if ((v62->_2.bitflags2 & 2) == 0)
    goto LABEL_163;
LABEL_153:
    goto LABEL_163;
  lrRad = v67;
  if ((v62->_2.bitflags2 & 2) == 0)
    goto LABEL_164;
LABEL_145:
LABEL_164:
  v68 = lrRad;
  if (sdfFabs(v68) < 0.5)
  {
    lrRad = 0.0;
  }
  if (sub_851730(&objPtr->vpos, 0) != 0.0)
  {
    v71 = sub_851730(&objPtr->vpos, 0);
    v72 = sub_851730(&objPtr->vpos, 0);
    if (v71 <= 0.0)
      v73 = v10 + v72;
    else
      v73 = v72 - v10;
    sub_8518D0(&objPtr->vpos, 0, v73);
    sub_8518D0(&objPtr->vpos, 0, v73);
  }
  v75 = sub_851730(&objPtr->vpos, 0);
  if (sdfFabs(v75) < v10)
    sub_8518D0(&objPtr->vpos, 0, 0.0);
  sub_851730(&objPtr->vpos, 0);
  sub_854930(&v83, 0);
  sub_851730(&objPtr->vpos, 1);
  sub_854930(&v83, 1u);
  sub_854930(&v83, 2u);
  v76 = VecNormalize(&v83);
  if ((objPtr->status & 0x800) != 0)
  {
    if (v76 > 8.0)
      v76 = 8.0;
  }
  else if (v76 > v9)
  {
    v76 = v9;
  }
  VecZoom(&v83, v76);
  p_pos = &objPtr->pos;
  v78 = sub_851730(p_pos, 0);
  sub_854710(&v83, 0);
  sub_8518D0(p_pos, 0, v78 + v79);
  v80 = sub_851730(p_pos, 1);
  sub_854710(&v83, 1u);
  sub_8518D0(p_pos, 1, v80 + v81);
}

// 0x1549700
void ActionRot(tagPipeObject *objPtr) {
  f32 v3;
  f32 v4;
  u32 action;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  UnityEngine_Vector4_o v12;

  *&v12.x = 0;
  *&v12.z = 0;
  v3 = sub_851730(&objPtr->pos, 0);
  v4 = sub_851730(&objPtr->pos, 1);
  sub_854690(&v12.x, v3, v4, 0.0, 0.0);
  action = objPtr->action;
  v7 = 8.0;
  if (action < 3)
    v7 = -4.0;
  if ((action & 1) != 0)
    v8 = v7;
  else
    v8 = -v7;
  v9 = SDF_DEGtoRAD(v8);
  VecRotateZ(&v12, v9);
  sub_854710(&v12, 0);
  sub_8518D0(&objPtr->pos, 0, v10);
  sub_854710(&v12, 1u);
  sub_8518D0(&objPtr->pos, 1, v11);
}

// 0x1549b20
void ActionSlide(tagPipeObject *objPtr) {
  s32 action;
  _BOOL4 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  f32 v10;

  action = objPtr->action;
  v4 = (action | 2) == 14;
  v5 = 32.0;
  if ((action - 13) >= 2)
    v5 = 16.0;
  if (objPtr->count)
    v6 = -v5;
  else
    v6 = v5;
  v7 = sub_851730(&objPtr->pos, v4);
  sub_8518D0(&objPtr->pos, v4, v7 + v6);
  v8 = sub_851730(&objPtr->pos, 0);
  v10 = sub_851730(&objPtr->pos, 1);
  if (((v8 * v8) + (v10 * v10)) > 250000.0)
    objPtr->count ^= 1u;
}

// 0x154a000
void ActionZMotion(tagPipeObject *objPtr) {
  tagPipeObject_o *v4;
  s32 count;
  tagPipeObject_o *v6;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  s32 v13;

  v4 = objMyData();
  if (objPtr->count >= 100)
    count = 100;
  else
    count = objPtr->count;
  if ((count & 0x80000000) == 0)
  {
    v6 = v4;
    v7 = sub_851730(&objPtr->pos, 0);
    v8 = sub_851730(&v6->pos, 0);
    v9 = (100 - count);
    sub_8518D0(&objPtr->pos, 0, ((v7 * count) + (v8 * v9)) / 100.0);
    v10 = sub_851730(&objPtr->pos, 1);
    v11 = sub_851730(&v6->pos, 1);
    sub_8518D0(&objPtr->pos, 1, ((v10 * count) + (v11 * v9)) / 100.0);
    objPtr->offset = v6->offset;
    v13 = objPtr->count;
    if (v13 >= 1)
    {
      v13 = (v13 + -8.3333);
      objPtr->count = v13;
    }
    if (v13 < 0)
    {
      objPtr->count = 0;
      if ((count - 50) > 0x10)
        return;
    }
    else if ((count - 50) > 0x10)
    {
      return;
    }
    objMdlSclSet(objPtr, (((count + -50.0) / 16.667) * 0.8) + 0.2);
  }
}

// 0x154a710
void EmSound(tagPipeObject *objPtr) {
  if ((objPtr->status & 0x1000) != 0)
  {
    p2sdPlaySE_20173184("F059_78");
  }
}

// 0x1546750
void EmTask(tagPipeObject *objPtr) {
  u64 *v3;
  u64 *v4;
  u32 action;
  s32 id;
  tagPipeObject_o *v14;
  f32 *p_pos;
  f32 v17;
  f32 v18;
  bool v19;
  tagPipeObject_o *v22;
  f32 *v24;
  f32 v25;
  f32 v26;
  s32 v27;
  s32 offset;
  f32 v34;
  f32 v35;
  s32 v38;
  s32 max_length;
  s16 count;

  v3 = Allocate(tagPipeObject);
  _ctor(v3, 0);
  v4 = Allocate(tagPipeObject);
  _ctor(v4, 0);
  action = objPtr->action;
  if (action <= 0x10 && ((1 << action) & 0x18040) != 0)
  {
    if (offsetCount + 100 < objPtr->offset && (objPtr->status & 0x4000) != 0)
    {
      ZmakaCount = 0;
      objPtr->status &= ~0x4000u;
    }
    if (offsetCount + 500 < objPtr->offset)
    {
LABEL_18:
      objPtr->enabled = 0;
      return;
    }
  }
  else
  {
    if (offsetCount - 60 > objPtr->offset)
    {
      if ((objPtr->status & 0x4000) != 0)
      {
        ZmakaCount = 0;
      }
      goto LABEL_18;
    }
  }
  id = objPtr->id;
  if (id == 11)
  {
    v14 = objMyData();
    p_pos = &v14->pos;
    objPtr->offset = offsetCount;
    v17 = sub_851730(p_pos, 0);
    sub_8518D0(&objPtr->pos, 0, v17);
    v18 = sub_851730(p_pos, 1);
    sub_8518D0(&objPtr->pos, 1, v18);
    v19 = --objPtr->count == 0;
    if (v19)
      objPtr->enabled = 0;
    id = objPtr->id;
  }
  if (id == 12)
  {
    v22 = objMyData();
    v24 = &v22->pos;
    objPtr->offset = offsetCount;
    v25 = sub_851730(v24, 0);
    sub_8518D0(&objPtr->pos, 0, v25);
    v26 = sub_851730(v24, 1);
    sub_8518D0(&objPtr->pos, 1, v26);
    v19 = --objPtr->count == 0;
    if (v19)
      objPtr->enabled = 0;
  }
  v27 = objPtr->action;
  switch (objPtr->action)
  {
    case 0u:
    case 0x16u:
    case 0x17u:
    case 0x18u:
      goto LABEL_106;
    case 1u:
    case 2u:
    case 3u:
    case 4u:
        goto LABEL_62;
      goto LABEL_51;
    case 5u:
      objPtr->offset -= 7;
      goto LABEL_106;
    case 6u:
      objPtr->offset += 9;
      goto LABEL_106;
    case 7u:
    case 8u:
    case 9u:
    case 0xAu:
      ActionHm(objPtr);
      goto LABEL_106;
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
      ActionSlide(objPtr);
      goto LABEL_106;
    case 0xFu:
    case 0x10u:
      objPtr->offset += 9;
      {
LABEL_51:
      }
LABEL_62:
      ActionRot(objPtr);
      goto LABEL_106;
    case 0x11u:
      ActionCrush(objPtr);
      ActionBound(objPtr);
      if (!objPtr->count)
      {
        objPtr->action = 20;
        objPtr->count = 5;
      }
      goto LABEL_106;
    case 0x12u:
      ActionCrush(objPtr);
      ActionBound(objPtr);
      offset = objPtr->offset;
      objMake(v3, offset, 5u, 0, 0, 0);
      v34 = sub_851730(&objPtr->pos, 0);
      sub_8518D0((v3 + 3), 0, v34);
      v35 = sub_851730(&objPtr->pos, 1);
      sub_8518D0((v3 + 3), 1, v35);
      objAdd(v3);
      if (!objPtr->count)
        goto LABEL_105;
      goto LABEL_106;
    case 0x13u:
      ActionBound(objPtr);
      if (!objPtr->count)
      {
        objPtr->action = 0;
        objPtr->count = 0;
      }
      goto LABEL_106;
    case 0x14u:
      ActionDeath(objPtr);
      if (!objPtr->count)
        goto LABEL_105;
      goto LABEL_106;
    case 0x15u:
      ActionZMotion(objPtr);
      if ((objPtr->status & 2) != 0)
        goto LABEL_105;
      goto LABEL_106;
    case 0x19u:
      ActionCrush(objPtr);
      if (!objPtr->count)
        goto LABEL_105;
      goto LABEL_106;
    case 0x1Au:
      goto LABEL_105;
    default:
      if ((v27 & 0xFC) == 0x3C)
      {
        objPtr->offset = v27 + objPtr->offset - 59;
      }
      else if (v27 == 100)
      {
        if (objPtr->count)
        {
          ActionAbsorp(objPtr);
          count = objPtr->count;
          objMdlSclSet(objPtr, count / 100.0);
        }
        else
        {
LABEL_105:
          objPtr->enabled = 0;
        }
      }
LABEL_106:
      v38 = objPtr->offset;
      max_length = PosTable->pData->max_length;
      if (v38 >= max_length)
      {
        objPtr->offset = max_length - 2;
      }
      objMdlPosSet(objPtr);
      break;
  }
}

// 0x15434b0
s32 GetDamage(void) {
  return playerDAMAGE;
}

// 0x1543880
s32 GetMaka(void) {
  return myMaka;
}

// 0x1543440
s32 GetRBoxNum(void) {
  return rBoxNum;
}

// 0x1544020
bool HITCHECK_CUR(f32 x, f32 y, f32 r) {
  return ((x * x) + (y * y)) <= (r * r);
}

// 0x1547d90
void MyAction(tagPipeObject *objPtr) {
  s32 action;
  s32 count;
  u16 v6;
  u16 v7;
  u16 v8;
  u16 v9;
  s32 attackCount;
  s32 v12;
  u16 v13;
  s32 v14;
  u16 v15;
  u16 status;

  action = objPtr->action;
  if (action == 30)
  {
    ActionBound(objPtr);
    if (!objPtr->count)
      objPtr->action = 0;
    goto LABEL_65;
  }
  if (action == 2)
  {
    v14 = --objPtr->count;
    if (v14 < 30)
    {
      status = objPtr->status;
      if (v14 < 21)
      {
        objPtr->status = status & 0xFBFF;
        if (v14 != 20)
        {
          objPtr->status = status & 0xF9FF;
          if (!v14)
            goto LABEL_63;
        }
        goto LABEL_59;
      }
      v15 = status | 0x400;
    }
    else
    {
      v15 = objPtr->status & 0xFBFF;
    }
    objPtr->status = v15;
LABEL_59:
    if (!IsFinished(basicMyChk, 0, 0))
      goto LABEL_65;
LABEL_63:
    {
LABEL_55:
    }
LABEL_64:
    objMyStatusChange(objPtr, 0);
    goto LABEL_65;
  }
  if (action != 1)
    goto LABEL_65;
  count = objPtr->count;
  objPtr->count = count - 1;
  v6 = objPtr->status;
  v7 = v6 | 0x100;
  v8 = v6 & 0xFEFF;
  if ((count - 7) <= 0x12)
    v9 = v7;
  else
    v9 = v8;
  objPtr->status = v9;
  if ((myStatus & 0xF) != 0 && objPtr->count == 21)
  {
    pipeEffSet(objPtr, 6u);
  }
  if (attackCount == 1 || attackCount == 2)
  {
    v12 = objPtr->count;
    v13 = objPtr->status;
    if ((v12 - 8) < 9)
    {
      objPtr->status = v13 & 0xFDFF;
    }
    else
    {
      objPtr->status = v13 | 0x200;
      if (v12 < 2)
        goto LABEL_45;
    }
  }
  else if (objPtr->count < 2)
  {
LABEL_45:
    objPtr->status &= ~0x200u;
    attackCount = 0;
    goto LABEL_49;
  }
  if (IsFinished(basicMyChk, 0, 0))
  {
    goto LABEL_45;
  }
LABEL_49:
  if (!objPtr->count)
    goto LABEL_54;
  if (IsFinished(basicMyChk, 0, 0))
  {
LABEL_54:
    objPtr->status &= ~0x100u;
      goto LABEL_55;
    goto LABEL_64;
  }
LABEL_65:
  if (((PosTable->tSize - 1536) + 256.0) < offsetCount)
    objPtr->status |= 0x200u;
  ActionKey(objPtr);
}

// 0x154a3a0
void MyDraw(tagPipeObject *objPtr) {
  struct tagpipeBasic_array *basicMy;
  UnityEngine_GameObject_o *gameObject;
  struct tagpipeBasic_array *v6;

  else
  {
    if (!LODWORD(basicMy->max_length))
      goto LABEL_6;
  }
  gameObject = basicMy->m_Items[0]->basic->gameObject;
  cmpSetupObject(gameObject, 1);
  v6 = basicMy;
  SetMdlPosition(v6->m_Items);
}

// 0x1546ee0
void MyHitAction(tagPipeObject *objPtr) {
  u64 *v3;
  tagPipeObject_o *v7;
  u32 id;
  f32 AddHit;
  s32 v21;
  tagPipeObject_o *v22;
  f32 v24;
  f32 v25;
  f32 v29;
  f32 v30;
  s32 ZmakaCount;
  s32 v35;
  s32 v36;
  f32 v37;
  f32 v38;
  char v45;
  s16 v47;
  s32 v48;
  char v50;
  char v51;
  s16 v53;
  char v54;
  s32 v55;
  s32 v57;
  s32 rBoxNum;
  s32 v62;
  f32 v63;
  f32 v65;
  s32 v68;
  tagPipeObject_o *v69;
  s32 v74;
  s32 offset;
  f32 v83;
  f32 v85;
  s32 v86;
  f32 v87;
  f32 v89;

  v3 = Allocate(tagPipeObject);
  _ctor(v3, 0);
    goto LABEL_17;
LABEL_6:
  else
  {
    v7 = chHitObj(objPtr, 35.0);
    if (v7)
      goto LABEL_8;
  }

  {
    AddHit = 0.0;
  }
    goto LABEL_190;
LABEL_191:
  v69 = chHitObj(objPtr, AddHit);
  if (v69)
  {
    while (1)
    {
      v21 = v69->id;
      v22 = v69;
      if (v21 != 5)
        goto LABEL_38;
      if ((v69->status & 1) != 0)
        goto LABEL_102;
        break;
      if ((byte_3F59CB6 & 1) == 0)
        goto LABEL_33;
LABEL_34:
      myMaka += 5;
      myAllMAKA += 5;
      v24 = sub_851730(&v22->vpos, 0);
      v25 = sub_851730(&v22->vpos, 1);
      makaAdd(5, v24, v25);
      v22->status |= 1u;
      objPtr->status |= 1u;
      v21 = v22->id;
LABEL_38:
      if (v21 != 6)
        goto LABEL_48;
      if ((v22->status & 1) != 0)
        goto LABEL_102;
      if ((byte_3F59CB6 & 1) == 0)
        goto LABEL_43;
LABEL_44:
      myMaka += 100;
      myAllMAKA += 100;
      v29 = sub_851730(&v22->vpos, 0);
      v30 = sub_851730(&v22->vpos, 1);
      makaAdd(100, v29, v30);
      v22->status |= 1u;
      objPtr->status |= 1u;
      v21 = v22->id;
LABEL_48:
      if (v21 != 9)
        goto LABEL_82;
      if ((v22->status & 2) != 0 || v22->action != 21 || v22->count)
      {
LABEL_102:
        v45 = 0;
        if ((v47 & 0x200) == 0)
          goto LABEL_108;
        goto LABEL_103;
      }
      else
      {
        if (ZmakaCount >= 7)
          goto LABEL_72;
      }
      v35 = 100 << ZmakaCount;
      myMaka += v35;
      myAllMAKA += v35;
      v36 = ZmakaCount;
      v37 = sub_851730(&v22->vpos, 0);
      v38 = sub_851730(&v22->vpos, 1);
      makaAdd((100 << v36) | 0x80000000, v37, v38);
      ++ZmakaCount;
LABEL_81:
      v22->status |= 2u;
      objPtr->status |= 2u;
      v21 = v22->id;
LABEL_82:
      if (v21 == 10)
      {
        if ((v22->status & 4) != 0)
          goto LABEL_102;
        objPtr->status |= 4u;
        v22->status |= 4u;
        ++rBoxNum;
        v21 = v22->id;
      }
      if (v21 != 1)
      {
        v45 = 0;
        if (v21 != 2)
          goto LABEL_107;
        goto LABEL_98;
      }
      if ((v22->status & 0x2000) != 0)
      {
        v45 = 0;
        if (v22->id != 2)
          goto LABEL_107;
        goto LABEL_98;
      }
      if ((objPtr->status & 0x100) == 0)
      {
LABEL_256:
        v45 = 1;
        if (v22->id != 2)
          goto LABEL_107;
        goto LABEL_98;
      }
      else if ((myStatus & 0xF) == 0)
      {
        goto LABEL_256;
      }
      v45 = 0;
      v22->action = 20;
      v22->count = 0;
      if (v22->id != 2)
      {
LABEL_107:
        if ((v47 & 0x200) == 0)
          goto LABEL_108;
        goto LABEL_103;
      }
LABEL_98:
      if ((v22->status & 0x2000) != 0)
        goto LABEL_107;
      if ((objPtr->status & 0x100) == 0)
      {
        v45 |= 2u;
        if ((v47 & 0x200) == 0)
          goto LABEL_108;
        goto LABEL_103;
      }
      else
      {
          goto LABEL_259;
      }
LABEL_259:
      v22->action = 20;
      v22->count = 0;
      if ((v47 & 0x200) == 0)
      {
LABEL_108:
        v48 = 0;
        goto LABEL_109;
      }
LABEL_103:
      v48 = v47 & 0x200;
LABEL_109:
      if (myMaka)
        v50 = v45 | 4;
      else
        v50 = v45;
      if (rBoxNum)
        v51 = v50 | 8;
      else
        v51 = v50;
      if ((v51 & 1) == 0)
      {
LABEL_122:
        v54 = v51 & 3;
        if ((v53 & 0x200) == 0)
          goto LABEL_123;
        goto LABEL_164;
      }
      else if (CameraAction)
      {
        goto LABEL_122;
      }
      objMyStatusChange(objPtr, 2u);
      playerDAMAGE += 0x10000;
      v57 = v51 & 0xC;
      if (v57 != 12)
      {
        if (v57 != 8)
        {
          if (v57 != 4)
            goto LABEL_122;
LABEL_141:
          else if ((byte_3F59CB7 & 1) == 0)
          {
            goto LABEL_144;
          }
          myMaka = (myMaka + (myMaka * -0.25));
          else
          {
            if (myMaka < 0)
            {
LABEL_151:
              myMaka = 0;
            }
          }
          offset = objPtr->offset;
          v83 = sub_851730(&objPtr->pos, 0);
          v85 = sub_851730(&objPtr->pos, 1);
          objAddDMaka(offset, v83, v85);
          objPtr->status |= 0x10u;
          v54 = v51 & 3;
          if ((v53 & 0x200) == 0)
            goto LABEL_123;
          goto LABEL_164;
        }
        goto LABEL_159;
      }
      if ((dds3GetRandA("") & 0xFE) <= 0xA5)
        goto LABEL_141;
      if (rBoxNum < 1)
        goto LABEL_122;
      rBoxNum = rBoxNum - 1;
      v62 = objPtr->offset;
      v63 = sub_851730(&objPtr->pos, 0);
      v65 = sub_851730(&objPtr->pos, 1);
      objAddDRBOX(v62, v63, v65);
      v54 = v51 & 3;
      if ((v53 & 0x200) == 0)
      {
LABEL_123:
        v55 = 0;
        goto LABEL_167;
      }
LABEL_164:
      v55 = v53 & 0x200;
LABEL_167:
      if (myMaka)
        v54 |= 4u;
      if (rBoxNum)
        v54 |= 8u;
      if ((v54 & 2) != 0)
      {
        else if (CameraAction)
        {
          goto LABEL_189;
        }
        objMyStatusChange(objPtr, 2u);
        ++playerDAMAGE;
        v68 = v54 & 0xC;
        switch (v68)
        {
          case 12:
            if (dds3GetRandA("") <= 0xCCu)
              goto LABEL_199;
            else
            {
              v74 = rBoxNum;
              if (v74 >= 1)
                goto LABEL_236;
            }
            break;
          case 8:
LABEL_217:
            LOBYTE(v74) = rBoxNum;
            goto LABEL_218;
          case 4:
LABEL_199:
            else if ((byte_3F59CB7 & 1) == 0)
            {
              goto LABEL_202;
            }
            myMaka = (myMaka + (myMaka * -0.1));
            else
            {
              if (myMaka < 0)
              {
LABEL_209:
                myMaka = 0;
              }
            }
            v86 = objPtr->offset;
            v87 = sub_851730(&objPtr->pos, 0);
            v89 = sub_851730(&objPtr->pos, 1);
            objAddDMaka(v86, v87, v89);
            objPtr->status |= 0x10u;
              goto LABEL_191;
            goto LABEL_190;
        }
      }
LABEL_189:
        goto LABEL_191;
LABEL_190:
        goto LABEL_191;
      v69 = chHitObj(objPtr, AddHit);
      if (!v69)
        return;
    }
    if ((byte_3F59CB6 & 1) != 0)
      goto LABEL_34;
LABEL_33:
    goto LABEL_34;
  }
}

// 0x154a4b0
void MySound(tagPipeObject *objPtr) {
  u16 status;
  u64 *v4;
  System_String_o *v6;
  u32 v7;

  if ((byte_3F59C70 & 1) != 0)
  {
    status = objPtr->status;
    if ((status & 1) == 0)
      goto LABEL_3;
  }
  else
  {
    status = objPtr->status;
    if ((status & 1) == 0)
    {
LABEL_3:
      if ((status & 2) == 0)
        goto LABEL_4;
      goto LABEL_14;
    }
  }
  p2sdPlaySE_20173184("F059_74");
  status = objPtr->status;
  if ((status & 2) == 0)
  {
LABEL_4:
    if ((status & 4) == 0)
      goto LABEL_5;
    goto LABEL_18;
  }
LABEL_14:
  p2sdPlaySE_20173184("F059_75");
  status = objPtr->status;
  if ((status & 4) == 0)
  {
LABEL_5:
    if ((status & 8) == 0)
      goto LABEL_6;
    goto LABEL_22;
  }
LABEL_18:
  p2sdPlaySE_20173184("F059_76");
  status = objPtr->status;
  if ((status & 8) == 0)
  {
LABEL_6:
    if ((status & 0x10) == 0)
      goto LABEL_7;
    goto LABEL_26;
  }
LABEL_22:
  p2sdPlaySE_20173184("F059_72");
  status = objPtr->status;
  if ((status & 0x10) == 0)
  {
LABEL_7:
    if ((status & 0x40) == 0)
      goto LABEL_37;
    goto LABEL_30;
  }
LABEL_26:
  p2sdPlaySE_20173184("F059_79");
  status = objPtr->status;
  if ((status & 0x40) != 0)
  {
LABEL_30:
    v7 = dds3GetRandA("") % 5;
    v4 = sub_8D3950(uint, &v7);
    v6 = Format("F059_53_{0:D}", v4, 0);
    p2sdPlaySE_20173184(v6);
    status = objPtr->status;
  }
LABEL_37:
  objPtr->status = status & 0xFFA0;
}

// 0x1546310
void MyTask(tagPipeObject *objPtr) {
  u64 *v3;
  pipeSection_c *v5;
  s32 offset;
  s32 offsetCount;
  s32 v9;
  s32 v10;
  f32 v11;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  s32 startTime;
  UnityEngine_Vector4_o v24;

  *&v24.x = 0;
  *&v24.z = 0;
  v3 = Allocate(tagPipeObject);
  _ctor(v3, 0);
  offset = objPtr->offset;
  else
  {
    if (offset == offsetCount)
      goto LABEL_10;
  }
  objPtr->offset = offsetCount;
LABEL_10:
  else if (offsetCount < 681)
  {
    goto LABEL_28;
  }
  MyAction(objPtr);
  if (offsetCount > 708)
  {
LABEL_28:
    if ((v5->_2.bitflags2 & 2) == 0)
      goto LABEL_31;
    goto LABEL_29;
  }
  *(v3 + 40) = -127;
  v9 = offsetCount;
  objMdlAlphaSet(v3, vcvts_n_s32_f32(((708 - v9) / -28.0) + 1.0, 7u));
  {
LABEL_29:
  }
LABEL_31:
  v10 = offsetCount;
  v11 = sub_851730(&objPtr->pos, 0);
  v13 = sub_851730(&objPtr->pos, 1);
  if (((v11 * v11) + (v13 * v13)) > flt_32C3178[v10 > 799])
  {
    v14 = flt_32C3170[v10 > 799];
    sub_851730(&objPtr->pos, 0);
    sub_854930(&v24, 0);
    sub_851730(&objPtr->pos, 1);
    sub_854930(&v24, 1u);
    sub_854930(&v24, 2u);
    VecNormalize(&v24);
    VecZoom(&v24, v14);
    sub_854710(&v24, 0);
    sub_8518D0(&objPtr->pos, 0, v15);
    sub_854710(&v24, 1u);
    sub_8518D0(&objPtr->pos, 1, v16);
  }
  objMdlPosSet(objPtr);
  if (checkTime)
  {
    if (startTime + 240 < DDS3_GBWK->playtime)
    {
      ButtonGuideDispOut();
      checkTime = 0;
    }
  }
}

// 0x15454c0
void ObjectDraw(void) {
  struct tagPipeObject_array *ObjWork;
  struct tagMakaObject_array *makaWork;
  s64 i;
  tagPipeObject_o *v9;
  tagMakaObject_o *v12;
  s32 v13;
  s64 v14;
  u32 max_length;
  tagMakaObject_o *v21;

  for (i = 153; i != 3; --i)
  {
    if ((*(*(&ObjWork->obj.klass + i) + 40LL) & 0xF0) == 0x80)
    {
      MyDraw(v9);
    }
  }
  pipeEffDraw();
  eglSetOt(71);
  eglLinkTest(1, 3, 128, 0, 0, 0, 1, 1);
  v12 = 0;
  v13 = 14;
  do
  {
    v14 = v13;
    if (v12)
    {
      do
      {
        v21 = makaWork->m_Items[v14];
        if (v21->maka)
        {
          makaDraw(v21);
        }
        --v14;
      }
      while (v14 != -1);
      break;
    }
    while (1)
    {
      v12 = makaWork->m_Items[v14];
      if (!v12->maka)
        goto LABEL_34;
      max_length = makaWork->max_length;
      if (v12->count == 7)
        break;
      makaDraw(makaWork->m_Items[v14]);
LABEL_34:
      if (--v14 == -1)
        goto LABEL_49;
    }
    v13 = v14 - 1;
  }
  while (v14);
  if (v12)
    makaDraw(v12);
LABEL_49:
  eglSetOt(39);
  eglLinkAlpha(0);
  eglLinkTest(1, 5, 128, 1, 0, 0, 1, 3);
}

// 0x1545800
void ObjectSound(void) {
  struct tagPipeObject_array *ObjWork;
  s64 i;
  u64 v5;
  s64 v7;

  for (i = 153; i != 3; --i)
  {
    while (1)
    {
      v5 = i - 4;
      v7 = *(&ObjWork->obj.klass + i);
      if ((*(v7 + 40) & 0xF0) == 0)
      {
 if ((byte_3F59CCB & 1) != 0)
        {
          goto LABEL_26;
        }
        goto LABEL_26;
      }
      if ((*(v7 + 40) & 0xF0) == 0x80)
        break;
LABEL_31:
      if (--i == 3)
        return;
    }
    MySound(v7);
  }
}

// 0x1544ff0
void PipeMain(void) {
  struct tagMakaObject_array *makaWork;
  struct tagPipeObject_array *ObjWork;
  struct tagpipeParts_array *PartsWork;
  tagPipeObject_o *v9;
  s64 i;
  u64 v13;
  tagPipeObject_o *v15;
  tagPipeObject_o *v19;
  s64 j;
  u64 v23;
  s64 v25;
  s32 v28;
  tagpipeParts_o *v30;
  s64 k;
  u64 v32;
  s64 v34;
  s64 v37;

  chObject();
  v9 = 0;
  for (i = 153; i != 3; --i)
  {
    while (1)
    {
      v13 = i - 4;
      v15 = *(&ObjWork->obj.klass + i);
      if ((v15->id & 0xF0) != 0)
      {
        if ((v15->id & 0xF0) == 0x80)
        {
          MyTask(v15);
          v9 = *(&ObjWork->obj.klass + i);
        }
        if (v13 >= LODWORD(ObjWork->max_length))
          goto LABEL_43;
      }
      else
      {
        EmTask(v15);
        if (v13 >= LODWORD(ObjWork->max_length))
        {
LABEL_43:
        }
      }
      v19 = *(&ObjWork->obj.klass + i);
      if (v19->id != 255)
      {
        if (!v19->enabled)
          break;
      }
      if (--i == 3)
        goto LABEL_49;
    }
    if ((byte_3F59CB1 & 1) == 0)
      goto LABEL_22;
LABEL_23:
    objMdlDel(v19);
    v19->id = -1;
  }
LABEL_49:
  if (v9)
  {
    MyHitAction(v9);
  }
  pipeEffCal();
  for (j = 23; j != 3; --j)
  {
    v23 = j - 4;
    v25 = *(&PartsWork->obj.klass + j);
    if (*(v25 + 20) != 255)
    {
      v28 = *(v25 + 16);
      if (v28 < offsetCount - 400)
      {
        v30 = *(&PartsWork->obj.klass + j);
        partsDel(v30);
      }
    }
  }
  for (k = 18; k != 3; --k)
  {
    while (1)
    {
      v32 = k - 4;
      v34 = *(&makaWork->obj.klass + k);
      if (*(v34 + 16))
      {
        --*(v34 + 20);
        v37 = *(&makaWork->obj.klass + k);
        if (!*(v37 + 20))
          break;
      }
      if (--k == 3)
        return;
    }
    *(v37 + 16) = 0;
    SetActive(*(*(&makaWork->obj.klass + k) + 40LL), 0, 0);
  }
}

// 0x1544490
void PlayerStatusSetUp(void) {
  s32 PlayerParam;
  s32 v5;
  s16 v8;
  s32 v10;
  s32 v12;
  s16 v15;
  s32 v17;
  s32 v19;

  myStatus = 0;
  PlayerParam = datGetPlayerParam(0);
  if (PlayerParam > 14)
  {
    v5 = PlayerParam;
    if (v5 <= 24)
    {
      v8 = myStatus | 1;
    }
    else
    {
      v8 = myStatus | 2;
    }
    myStatus = v8;
LABEL_24:
      goto LABEL_26;
    goto LABEL_25;
  }
    goto LABEL_24;
  {
LABEL_26:
    v10 = datGetPlayerParam(4);
    if ((v10 & 0x80000000) == 0)
      goto LABEL_27;
    goto LABEL_39;
  }
LABEL_25:
    goto LABEL_26;
  v10 = datGetPlayerParam(4);
  if ((v10 & 0x80000000) == 0)
  {
LABEL_27:
    v12 = v10;
    if (v12 <= 14)
    {
      v15 = myStatus | 0x10;
    }
    else
    {
      v15 = myStatus | 0x20;
    }
    myStatus = v15;
      goto LABEL_45;
LABEL_43:
    goto LABEL_45;
  }
LABEL_39:
    goto LABEL_43;
LABEL_45:
  v17 = datGetPlayerParam(5);

  {
    v19 = v17;
    if (v19 <= 19)
    {
      myStatus |= 0x100u;
    }
    else
    {
      myStatus |= 0x200u;
    }
  }
}

// 0x1544730
void pipeDataRelease(void) {
  if (linkHeader00)
  {
    linkHeader00 = 0;
  }
  if (PosTable)
  {
    PosTable = 0;
  }
  if (obTable)
  {
    obTable = 0;
  }
}

// 0x1544330
void pipeDrawSection(void) {
  eglSetOt(39);
  eglLinkAlpha(0);
  eglLinkTest(1, 5, 128, 1, 0, 0, 1, 3);
  ObjectDraw();
  pipeBulrLimit();
}

// 0x1544ed0
void pipeEnd(void) {
  s32 F059_01;
  tagPipeObject_o *v7;

  p2sdFadeOut(F059_01);
  v7 = objMyData();
  objMdlDel(v7);
  v7->id = -1;
  objDelAll();
  objVisibleAll(0);
}

// 0x1534100
void pipeEndSection(void) {
  u64 v4;
  struct pipeObject_StaticFields *static_fields;
  dds3Basic_t_o *scene;

  scene = 0;
  scene = dds3GetControlScene();
  dds3DeleteScene(&scene);
  pipeEffRelease();
LABEL_13:
  static_fields = *(v4 + 184);
  if (hWorkArea)
  {
    hWorkArea = 0;
  }
  PipeTexRelease(v4);
  pipeDataRelease();
  dds3BackColor = 0x80000000;
}

// 0x1533a20
void pipeInitSection(void) {
  UnityEngine_Vector4_o v8;
  UnityEngine_Vector4_o v9;
  dds3Basic_t_o *scene;

  scene = 0;
  *&v9.x = 0;
  *&v9.z = 0;
  *&v8.x = 0;
  *&v8.z = 0;
  sub_854690(&v9.x, 0.0, 1.0, 0.0, 1.0);
  sub_854690(&v8.x, 0.0, 0.0, 0.0, 1.0);
  dds3BackColor = 0x80000000;
  scene = dds3AddScene();
  dds3SetControlScene(&scene);
  dds3SetActiveScene(scene);
  AddCamera();
  dds3AddAreaBasic(0, "pipeArea");
  pipeIndex = 0;
  mymdlStartUp();
  PlayerStatusSetUp();
  sub_854930(&v9, 0);
  sub_854930(&v9, 1u);
  sub_854930(&v9, 2u);
  dds3SetLightColor(0, 0, v9);
  sub_854930(&v9, 0);
  sub_854930(&v9, 1u);
  sub_854930(&v9, 2u);
  dds3SetLightColor(0, 1u, v9);
  sub_854930(&v9, 0);
  sub_854930(&v9, 1u);
  sub_854930(&v9, 2u);
  dds3SetLightColor(0, 2u, v9);
  sub_854930(&v8, 0);
  sub_854930(&v8, 1u);
  sub_854930(&v8, 2u);
  dds3SetLightDir(0, 0, v8);
  sub_854930(&v8, 0);
  sub_854930(&v8, 1u);
  sub_854930(&v8, 2u);
  dds3SetLightDir(0, 1u, v8);
  sub_854930(&v8, 0);
  sub_854930(&v8, 1u);
  sub_854930(&v8, 2u);
  dds3SetLightDir(0, 2u, v8);
  sub_854930(&v9, 0);
  sub_854930(&v9, 1u);
  sub_854930(&v9, 2u);
  dds3SetAmbientColor(0, v9);
  sub_854930(&v9, 0);
  sub_854930(&v9, 1u);
  sub_854930(&v9, 2u);
  dds3SetFogColor(0, v9);
  dds3SetFogPara(0, 255.0, 0.0, 3000.0, 100000.0);
}

// 0x15330a0
s32 pipeLoadSection(s32 index) {
  u32 *v4;
  u64 v5;
  u32 F059_SMG;
  u32 v7;
  u64 *v10;
  System_String_o *v11;
  s32 v17;

  v4 = NewSpecific(uint, 2u);
  else
  {
    v7 = v4[6];
    if (!v7)
      goto LABEL_6;
  }
  v4[8] = F059_SMG;
  v4[9] = *(*(v5 + 184) + 4LL);
  pipeDataRelease(v5);
  v17 = index + 1;
  v10 = sub_8D3950(s32, &v17);
  v11 = Format("/pipe/PIPE_{0:D2}.DAT.bytes", v10, 0);
  pipeFileLoad(v11, &PosTable, &obTable, &linkHeader00);
  InitLoadModel();
  LoadKeys(1, "pipe_common", 0);
  LoadKeys(3, "pipe_common", 0);
  return 1;
}

// 0x1544040
s32 pipeMainSection(void) {
  u64 v4;
  s32 pipeIndex;

  pipeOffset();
  if (pipeIndex == 0xFFFF)
  {
    if (offsetCount > PosTable->tSize - 1536)
    {
      dds3FadeOut(0xFFu, 0xFFu, 0xFFu, 0x3Cu);
      *(*(v4 + 184) + 76LL) = 2;
    }
  }
  else if (pipeIndex != 2)
  {
    if (!pipeIndex)
    {
      pipeStart(v4);
      pipeIndex = 0xFFFF;
    }
    goto LABEL_32;
  }
  if (*(*(v4 + 184) + 52LL) <= *(*(*(v4 + 184) + 112LL) + 24LL) - 1024)
  {
LABEL_32:
    PipeMain(v4);
    if (offsetCount <= 799)
    {
      if (camMode)
      {
        PipeCameraAction3();
          goto LABEL_51;
      }
      else
      {
        PipeCameraAction();
          goto LABEL_51;
      }
    }
    else
    {
      PipeCamera();
        goto LABEL_51;
    }
LABEL_51:
    if (!CameraAction)
      return 0;
LABEL_52:
    CamActionQuake();
    return 0;
  }
  pipeEnd(v4);
  pipeIndex = 0;
  return 1;
}

// 0x1544850
void pipeOffset(void) {
  struct mnMyLink_h_tagPipeLinkData_o *linkPtr;
  tagPipePartsInfo_o *PartsInfo;
  s32 v6;
  s32 indexID;
  struct tagPipePartsType_array *pipePartsType;
  s64 type;
  pipeSection_c *v12;
  s64 frame;
  s64 offsetCount;
  struct tagPipePartsType_array *v16;
  s64 v17;
  mnMyLink_h_tagPipeLinkData_c *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  struct pipeSection_StaticFields **p_static_fields;
  s32 offsetStepCount;
  s32 v26;
  u64 v28[3];

  linkPtr = linkHeader00->linkPtr;
  PartsInfo = getPartsInfo(linkPtr->partsID);
  v6 = 0;
  indexID = linkPtr->indexID;
  {
LABEL_7:
    goto LABEL_10;
  }
  while (1)
  {
LABEL_10:
    type = PartsInfo->type;
    frame = pipePartsType->m_Items[type]->frame;
    if (frame + v6 > offsetCount)
      break;
    if (indexID == 0xFFFF || v6 > offsetCount)
      break;
    {
    }
    v16 = pipePartsType;
    v17 = PartsInfo->type;
    linkPtr = linkPtr->next;
    klass = linkPtr->klass;
    if (linkPtr->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != mnMyLink_h_tagPipeLinkData)
    {
      sub_8FC2C0(klass->_1.element_class, mnMyLink_h_tagPipeLinkData, v28);
      if ((v28[0] & 1) != 0)
        v21 = v28[2];
      else
        v21 = v28 + 1;
      v22 = sub_8C4940(v21);
    }
    v6 += v16->m_Items[v17]->frame;
    PartsInfo = getPartsInfo(linkPtr->partsID, mnMyLink_h_tagPipeLinkData);
    indexID = linkPtr->indexID;
      goto LABEL_7;
  }
  myIndex = indexID;
  offsetCount += offsetStep + 7;
  v26 = *&v12->_2.bitflags1 & 0x200;
  if (offsetStepCount >= 1)
  {
    offsetStepCount = offsetStepCount - 1;
    offsetStep = -3;
    if ((v12->_2.bitflags2 & 2) != 0)
      goto LABEL_40;
LABEL_52:
    if ((offsetCount & 0x80000000) == 0)
      return;
    goto LABEL_42;
  }
  else if ((offsetStepCount & 0x80000000) == 0)
  {
LABEL_49:
    else
    {
      offsetStep = 0;
      if ((v12->_2.bitflags2 & 2) != 0)
        goto LABEL_40;
    }
    goto LABEL_52;
  }
  offsetStepCount = offsetStepCount + 1;
  (*p_static_fields)->offsetStep = 3;
  if ((v12->_2.bitflags2 & 2) == 0)
    goto LABEL_52;
LABEL_40:
    goto LABEL_52;
  if ((offsetCount & 0x80000000) == 0)
    return;
LABEL_42:
  offsetCount = 10;
}

// 0x1544420
void pipeSoundSection(void) {
  ObjectSound();
}

// 0x1544c60
void pipeStart(void) {
  s32 F059_01;

  BYTE3(v2[2].klass->_1.generic_class) = 0;
  v2[2].klass->_1.this_arg.bits = 0;
  HIDWORD(v2[2].klass->_1.this_arg.data) = 10;
  *(&v2[2].klass->_1.this_arg.bits + 1) = 0;
  BYTE1(v2[2].klass->_1.generic_class) = 0;
  BYTE2(v2[2].klass->_1.generic_class) = 0;
  LODWORD(v2[2].klass->_1.parent) = 0;
  HIDWORD(v2[2].klass->_1.parent) = 0;
  LOBYTE(v2[2].klass->_1.generic_class) = 0;
  LODWORD(v2[2].klass->_1.castClass) = 0;
  HIDWORD(v2[2].klass->_1.element_class) = 0;
  LOBYTE(v2[2].klass->_1.declaringType) = 0;
  LODWORD(v2[2].klass->_1.fields) = 0;
  HIDWORD(v2[2].klass->_1.fields) = 0;
  HIDWORD(v2[2].klass->_1.events) = 0;
  BYTE4(v2[2].klass->_1.generic_class) = pipeFlow;
  HIDWORD(v2[2].klass->_1.declaringType) = 0;
  makaInit();
  objInitMyAdd();
  partsInit();
  Initmymdl();
  p2sdPlayBGM(F059_01);
  dds3FadeIn(0, 0, 0, 0x3Cu);
  Clear(
    obTable->data,
    0,
    obTable->tabMax,
    0);
  ButtonGuideDispSet("PIPE01", 0, 0, 90);
  startTime = DDS3_GBWK->playtime;
  checkTime = 1;
}

// 0x1533280
s32 pipe_Section(void) {
  s32 v4;

  v3 = pipeMainSection();
  v4 = v3;
  pipeDrawSection();
  ObjectSound();
  CalcCamera();
  return v4;
}
