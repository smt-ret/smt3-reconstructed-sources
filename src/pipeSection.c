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
    objMyData();
}

// 0x1548150
void ActionBound(tagPipeObject *objPtr) {
    VecNormalize(0);
    VecZoom(0, 0);
    VecdotRad((sdfVector4_t){0}, (sdfVector4_t){0});
    VecRotateZ(0, 0);
}

// 0x1549c50
void ActionCrush(tagPipeObject *objPtr) {
    VecNormalize(0);
}

// 0x1549e50
void ActionDeath(tagPipeObject *objPtr) {
    pipeEffSet(0, 0);
    objMake(0, 0, 0, 0, 0, 0);
    objAdd(0);
    objMdlAlphaSet(0, 0);
}

// 0x1549830
void ActionHm(tagPipeObject *objPtr) {
    objMyData();
    VecNormalize(0);
    VecZoom(0, 0);
}

// 0x15485d0
void ActionKey(tagPipeObject *objPtr) {
    DDS3_PADCHECK_TRIG(0);
    objMyStatusChange(0, 0);
    DDS3_PADCHECK_PRESS(0);
    sdfFabs(0);
    VecNormalize(0);
    VecZoom(0, 0);
}

// 0x1549700
void ActionRot(tagPipeObject *objPtr) {
    SDF_DEGtoRAD(0);
    VecRotateZ(0, 0);
}

// 0x1549b20
void ActionSlide(tagPipeObject *objPtr) {
}

// 0x154a000
void ActionZMotion(tagPipeObject *objPtr) {
    objMyData();
    objMdlSclSet(0, 0);
}

// 0x154a710
void EmSound(tagPipeObject *objPtr) {
  if ((objPtr->status & 0x1000) != 0)
  {
    p2sdPlaySE_20173184(StringLiteral_9511);
  }
}

// 0x1546750
void EmTask(tagPipeObject *objPtr) {
    objMyData();
    ActionHm(0);
    ActionSlide(0);
    ActionRot(0);
    ActionCrush(0);
    ActionBound(0);
    objMake(0, 0, 0, 0, 0, 0);
    objAdd(0);
    ActionDeath(0);
    ActionZMotion(0);
    ActionAbsorp(0);
    objMdlSclSet(0, 0);
    objMdlPosSet(0);
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
        }
      }
      v15 = status | 0x400;
    }
    else
    {
      v15 = objPtr->status & 0xFBFF;
    }
    objPtr->status = v15;
    objMyStatusChange(objPtr, 0);
  }
  if (action != 1)
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
    }
  }
  else if (objPtr->count < 2)
  {
    objPtr->status &= ~0x200u;
    attackCount = 0;
  }
  if (!objPtr->count)
  if (IsFinished(basicMyChk, 0, 0))
  {
    objPtr->status &= ~0x100u;
  }
  if (((PosTable->tSize - 1536) + 256.0) < offsetCount)
    objPtr->status |= 0x200u;
  ActionKey(objPtr);
}

// 0x154a3a0
void MyDraw(tagPipeObject *objPtr) {
    SetMdlPosition(0);
}

// 0x1546ee0
void MyHitAction(tagPipeObject *objPtr) {
    makaAdd(0, 0, 0);
    objMyStatusChange(0, 0);
    objAddDMaka(0, 0, 0);
    dds3GetRandA(0);
    objAddDRBOX(0, 0, 0);
}

// 0x154a4b0
void MySound(tagPipeObject *objPtr) {
    p2sdPlaySE_20173184(0);
    dds3GetRandA(0);
}

// 0x1546310
void MyTask(tagPipeObject *objPtr) {
    MyAction(0);
    objMdlAlphaSet(0, 0);
    VecNormalize(0);
    VecZoom(0, 0);
    objMdlPosSet(0);
    ButtonGuideDispOut();
}

// 0x15454c0
void ObjectDraw(void) {
  pipeObject_c *v2;
  struct pipeObject_StaticFields *static_fields;
  struct tagPipeObject_array *ObjWork;
  struct tagMakaObject_array *makaWork;
  s64 i;
  tagPipeObject_o *v9;
  tagMakaObject_o *v12;
  s32 v13;
  s64 v14;
  u32 max_length;
  tagMakaObject_o *v21;

  static_fields = v2->static_fields;
  ObjWork = static_fields->ObjWork;
  makaWork = static_fields->makaWork;
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
      max_length = makaWork->max_length;
      if (v12->count == 7)
        break;
      makaDraw(makaWork->m_Items[v14]);
      if (--v14 == -1)
    }
    v13 = v14 - 1;
  }
  while (v14);
  if (v12)
    makaDraw(v12);
  eglSetOt(39);
  eglLinkAlpha(0);
  eglLinkTest(1, 5, 128, 1, 0, 0, 1, 3);
}

// 0x1545800
void ObjectSound(void) {
    p2sdPlaySE_20173184(0);
    MySound(0);
}

// 0x1544ff0
void PipeMain(void) {
  pipeObject_c *v2;
  struct pipeObject_StaticFields *static_fields;
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

  static_fields = v2->static_fields;
  makaWork = static_fields->makaWork;
  ObjWork = static_fields->ObjWork;
  PartsWork = static_fields->PartsWork;
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
      }
      else
      {
        EmTask(v15);
      }
      v19 = *(&ObjWork->obj.klass + i);
      if (v19->id != 255)
      {
        if (!v19->enabled)
          break;
      }
      if (--i == 3)
    }
    if ((byte_3F59CB1 & 1) == 0)
    objMdlDel(v19);
    v19->id = -1;
  }
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
  pipeSection_c *v6;
  struct pipeSection_StaticFields *static_fields;
  s16 v8;
  s32 v10;
  s32 v12;
  pipeSection_c *v13;
  struct pipeSection_StaticFields *v14;
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
      static_fields = v6->static_fields;
      v8 = static_fields->myStatus | 1;
    }
    else
    {
      static_fields = v6->static_fields;
      v8 = static_fields->myStatus | 2;
    }
    static_fields->myStatus = v8;
  }
  {
    v10 = datGetPlayerParam(4);
    if ((v10 & 0x80000000) == 0)
  }
  v10 = datGetPlayerParam(4);
  if ((v10 & 0x80000000) == 0)
  {
    v12 = v10;
    if (v12 <= 14)
    {
      v14 = v13->static_fields;
      v15 = v14->myStatus | 0x10;
    }
    else
    {
      v14 = v13->static_fields;
      v15 = v14->myStatus | 0x20;
    }
    v14->myStatus = v15;
  }
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
  pipeSection_c *v2;
  struct pipeSection_StaticFields *static_fields;
  struct pipeSection_StaticFields *v4;
  struct pipeSection_StaticFields *v5;

  static_fields = v2->static_fields;
  if (static_fields->linkHeader00)
  {
    static_fields->linkHeader00 = 0;
  }
  v4 = v2->static_fields;
  if (v4->PosTable)
  {
    v4->PosTable = 0;
  }
  v5 = v2->static_fields;
  if (v5->obTable)
  {
    v5->obTable = 0;
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
  static_fields = *(v4 + 184);
  if (static_fields->hWorkArea)
  {
    if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
    {
      static_fields = pipeObject->static_fields;
    }
    static_fields->hWorkArea = 0;
  }
  PipeTexRelease(v4);
  pipeDataRelease();
  dds3BackColor = 0x80000000;
}

// 0x1533a20
void pipeInitSection(void) {
    dds3AddScene();
    dds3SetControlScene(0);
    dds3SetActiveScene(0);
    AddCamera();
    dds3AddAreaBasic(0, 0);
    mymdlStartUp();
    PlayerStatusSetUp();
    dds3SetLightColor(0, 0, (sdfVector4_t){0});
    dds3SetLightDir(0, 0, (sdfVector4_t){0});
    dds3SetAmbientColor(0, (sdfVector4_t){0});
    dds3SetFogColor(0, (sdfVector4_t){0});
    dds3SetFogPara(0, 0, 0, 0, 0);
}

// 0x15330a0
s32 pipeLoadSection(s32 index) {
    pipeDataRelease();
    pipeFileLoad(0, 0, 0, 0);
    InitLoadModel();
    LoadKeys(0, 0, 0);
    return 0;
}

// 0x1544040
s32 pipeMainSection(void) {
  u64 v4;
  struct pipeSection_StaticFields *static_fields;
  s32 pipeIndex;
  struct pipeSection_StaticFields *v9;

  pipeOffset();
  static_fields = pipeSection->static_fields;
  pipeIndex = static_fields->pipeIndex;
  if (pipeIndex == 0xFFFF)
  {
    if (static_fields->offsetCount > static_fields->PosTable->tSize - 1536)
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
  }
  if (*(*(v4 + 184) + 52LL) <= *(*(*(v4 + 184) + 112LL) + 24LL) - 1024)
  {
    if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
    PipeMain(v4);
    v9 = pipeSection->static_fields;
    if (v9->offsetCount <= 799)
    {
      if (v9->camMode)
      {
        PipeCameraAction3();
      }
      else
      {
        PipeCameraAction();
      }
    }
    else
    {
      PipeCamera();
    }
    if (!CameraAction)
      return 0;
    CamActionQuake();
    return 0;
  }
  if ((*(v4 + 295) & 2) != 0 && !*(v4 + 216))
  pipeEnd(v4);
  pipeIndex = 0;
  return 1;
}

// 0x1544850
void pipeOffset(void) {
    getPartsInfo(0);
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
  ButtonGuideDispSet(StringLiteral_21925, 0, 0, 90);
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
