#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PathBasicControl_t dds3PathBasicControl_t;
typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct effEveBEDCutHandle_t effEveBEDCutHandle_t;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct evtUnitHandle_t_ActionDelegate evtUnitHandle_t_ActionDelegate;
typedef struct fldSceneParam_t fldSceneParam_t;
typedef struct instanceMes_tag_func_kutiDelegate instanceMes_tag_func_kutiDelegate;
typedef struct scrProcessWork_s scrProcessWork_s;

static s32 evtNextEventNo;
static evtUnitHandle_t *KutiModel;
static s32 KagPuzPos;
static s32 KagPuzNow;

void BillSetPB(s32 index);
void CallBattleSub(s32 encno, s32 eventno);
void CallBattleSub2(s32 encno);
void DetachModel(dds3Basic_t *basic, bool ul);
void DetachModelAll(void);
void EndingEventUnlock(s32 evtno);
void Eve_DistortionBlurSetDefTex(void);
void FromEuler(f32 aRotateX, f32 aRotateY, f32 aRotateZ);
u8 Get(s32 id);
s32 GetPibIndex(u8 **bData, s32 bPos);
bool IsDLC(void);
void Log(char *fmt, void **parray);
void Mult(void);
void PlayerUnitDisp(evtUnitHandle_t **h, bool sw);
void RemoveKeys(s32 type, char *key);
f32 SDF_DEGtoRAD(f32 n);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__LOADIDENTITYVECTOR(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__SETVECTOR_W(f32 v);
void SDF_VU0__SETVECTOR_X(f32 v);
void SDF_VU0__SETVECTOR_Y(f32 v);
void SDF_VU0__SETVECTOR_Z(f32 v);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void SDF_VU0__VECTOR_W_SET_ZERO(void);
u32 SDF_VU0__dds3ColorFtoI(f32 ratio);
void SetDrawFlag(u32 flag, u32 cnt);
void SetLight_From_evtCommand(char *light_name);
void UnloadALL(bool all);
void billAlfRaitoSet2(f32 raito);
void billCutRaitoSet2(f32 raito);
void datAddKotowariPoint(s32 type, s32 point);
s32 datGetKotowariLank(s32 lank);
dds3Basic_t *dds3AddBEDEffectObjectBasic(char *file, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddBEDEffectObjectBasic2(void *data, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddCameraObjectBasicTypeFree(u32 serialID, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddD3PEffectObjectBasic(char *file, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddD3PEffectObjectBasic2(void *effdata, sdfVector4_t pos, sdfVector4_t rot);
dds3Basic_t *dds3AddMG12EffectObjectBasic(s32 type, char *file);
dds3Basic_t *dds3AddMG12EffectObjectBasic2(s32 type, void *effdata);
void dds3AdminiCallSequence(s32 sequence, void *data, s32 datasize, s32 restore);
void dds3AdminiExitSequence(void);
void dds3DeleteSceneBasicData(dds3Basic_t **basic);
s32 dds3EffectObjectBasicLinkObject(dds3Basic_t **basic, dds3Basic_t **target);
s32 dds3EffectObjectBasicLinkObjectIndex(dds3Basic_t **basic, dds3Basic_t **target, s32 index);
void dds3EffectObjectBasicStatOn(dds3Basic_t **basic, u32 s);
void dds3EffectObjectBasicUnlinkObject(dds3Basic_t **basic);
void dds3EffectObjectPresetMG12(dds3Basic_t **eff);
s32 dds3EffectObjectSetMG12Pos(dds3Basic_t **eff, dds3Basic_t **p1, dds3Basic_t **p2, dds3Basic_t **p3, dds3Basic_t **p4);
s32 dds3ExistProcess(dds3ProcessID_t **id);
dds3Basic_t *dds3GetActiveScene(void);
dds3Basic_t *dds3GetActiveUnitSceneBasic(dds3Basic_t *pSceneBasic);
dds3Basic_t *dds3GetControlScene(void);
s32 dds3GetMapNo(dds3Basic_t **scene);
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target);
dds3ObjectBaseControlWorkData_t *dds3MatterObjectBasicGetControlWorkData(dds3Basic_t **pBasic);
dds3PathBasicControl_t *dds3MoverBasicGetPathControl(dds3Basic_t **pMoverBasic);
void dds3MoverBasicMakePath(dds3Basic_t **pMoverBasic);
void dds3MoverBasicSetPath(dds3Basic_t **pMoverBasic, dds3Basic_t **pPathBasic);
void dds3ObjectBaseCreateMover(dds3Basic_t **pObjectBasic);
void dds3ObjectBaseOffFlag(dds3Basic_t **pObjectBasic, u32 flag);
void dds3ObjectBaseOnFlag(dds3Basic_t **pObjectBasic, u32 flag, bool alock);
void dds3PathBasicControlAlterMode(dds3PathBasicControl_t **pControl, u32 mode);
void dds3Printf(char *str, void **LegacyParamArray);
dds3Basic_t *dds3SceneBasicSearchName(dds3Basic_t **scene, char *name);
dds3ProcessID_t *dds3SearchProcessID(s32 id);
dds3Basic_t *dds3SearchSceneBasic(dds3Basic_t **pBasic, u32 serialID, u32 type);
u32 dds3SerializeID(void);
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRadiusPoseSet(dds3Basic_t **pBasic, f32 radius);
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot);
void dds3SetSclPoseSet(dds3Basic_t **pBasic, sdfVector4_t scl);
void dds3StartBEDEffectObjectBasic(dds3Basic_t **basic, u32 cutno);
void effEveBEDCutSetScale(effEveBEDCutHandle_t **hEveBEDCut, f32 scale);
void encStart(bool bRandomEncount);
f32 evtCalcEffBedScale(s32 uid);
s32 evtCheckPathStat(dds3Basic_t *obj);
s32 evtCheckPolygonMovieFlag(dds3ProcessID_t *id, u32 flag);
s32 evtCheckSoundLoad(s32 eventno);
s32 evtCheckUnitWait(evtUnitHandle_t **h);
void evtDisableMoonCalc(void);
void evtDispBlurTexSet(s32 eventno, s32 rid);
void evtEffectLoopControl(dds3Basic_t *eff, s32 sw);
void evtEnableMoonCalc(void);
s32 evtFadeOutBgm(s32 eventno, s32 bgmno);
void evtFreeAllUnit(void);
void evtFreeStage(void);
s32 evtGetAgeOfMoon(void);
s32 evtGetAgeOfMoon16(void);
s32 evtGetEventPackStat(s32 eventno);
u8 **evtGetResorceData(s32 eventno, s32 rid);
evtUnitHandle_t *evtGetUnitHandle(s32 serial);
dds3ProcessID_t *evtInitMotionSeProcess(s32 unitid, s32 eventno, s32 rid);
void evtKillEventPack(s32 eventno);
void evtKillPictureProcess(dds3ProcessID_t *id);
void evtLinkLightObjectBasic(evtUnitHandle_t **h, dds3Basic_t **light, s32 frame);
s32 evtLoadArea(s32 fld, s32 area);
dds3ProcessID_t *evtLoadEventPack(s32 eventno);
s32 evtLoadSound(s32 eventno);
s32 evtLoadUnit(s32 major, s32 minor);
void evtPathDir(dds3Basic_t *basic, s32 dir);
s32 evtPathLinkAndMake(dds3Basic_t *path, dds3Basic_t *obj);
void evtPathLoop(dds3Basic_t *basic, s32 sw);
void evtPathRate(dds3Basic_t *basic, f32 rate);
void evtPathStart(dds3Basic_t *basic);
void evtPathStop(dds3Basic_t *basic);
void evtPictureDrawOff(dds3ProcessID_t *id);
void evtPictureDrawOn(dds3ProcessID_t *id);
void evtPictureSetAlpha(dds3ProcessID_t *id, s32 alp0, s32 alp1, s32 time);
void evtPictureSetOt(dds3ProcessID_t *id, s32 ot);
void evtPictureSetPos(dds3ProcessID_t *id, s32 x0, s32 y0, s32 x1, s32 y1, s32 time);
void evtPictureSetPri(dds3ProcessID_t *id, s32 pri);
void evtPictureSetSize(dds3ProcessID_t *id, s32 sw, s32 sh, s32 tw, s32 th);
void evtPictureSetZoom(dds3ProcessID_t *id, s32 zoom0, s32 zoom1, s32 time);
s32 evtPictureStat(dds3ProcessID_t *id);
void evtPictureSwap(dds3ProcessID_t *id1, dds3ProcessID_t *id2, s32 pat, s32 prm);
s32 evtPlayBgm(s32 eventno, s32 bgmno);
s32 evtPlaySe(s32 eventno, s32 seno);
s32 evtRegistBEField(s32 eventno, s32 rid);
s32 evtRegistBEUnit(s32 eventno, s32 rid);
void evtResetPolygonMovieFlag(dds3ProcessID_t *id, u32 flag);
void evtRunUnitKutiMotion(evtUnitHandle_t **h);
dds3Basic_t *evtSearchBasic(s32 type, s32 serial);
dds3ProcessID_t *evtSearchEventPack(s32 eventno);
void evtSetAgeOfMoon(s32 age);
void evtSetBokasi(s32 sw);
void evtSetPolygonMovieFlag(dds3ProcessID_t *id, u32 flag);
void evtSetSkyAlpha(s32 frame, s32 a);
void evtSetUnitColorA(evtUnitHandle_t **h, u32 frame, u32 a);
void evtSetUnitColorRGB(evtUnitHandle_t **h, u32 frame, u32 rgb);
void evtSetUnitExMotion(evtUnitHandle_t **h, s32 group, s32 motion, s32 before, s32 smooth, s32 mode);
void evtSetUnitKutiMotion(evtUnitHandle_t **h, s32 group, s32 motion);
void evtSetUnitLightAndAmbient(evtUnitHandle_t **h, u32 frame, u32 lrgb, u32 argb);
void evtSetUnitLightDir(evtUnitHandle_t **h, s32 frame);
void evtSetUnitMotion(evtUnitHandle_t **h, s32 motion, s32 before, s32 smooth, s32 mode);
void evtSetUnitMove2(evtUnitHandle_t **h, s32 movetype, s32 posID, s32 motion, s32 para1, s32 para2, evtUnitHandle_t_ActionDelegate *func, void *data);
void evtSetUnitMove3(evtUnitHandle_t **h, s32 pathID, s32 para1, s32 para2, s32 movesys, s32 movedir, s32 rotsys);
void evtSetUnitPos(s32 unitID, s32 posID);
void evtSetUnitRot2(evtUnitHandle_t **h, s32 posID, s32 para1);
s32 evtStageAnimeControl(s32 type, s32 mode);
dds3ProcessID_t *evtStartPictureProcess(s32 priority, char *texpath);
dds3ProcessID_t *evtStartPolygonMovie2(s32 priority, s32 eventno, s32 cutno);
s32 evtStopSe(s32 eventno, s32 seno);
void evtTransBgm(s32 eventno, s32 bgmno);
s32 evtUnitLightAnimeStat(evtUnitHandle_t **h);
void evtUnitLightOff(evtUnitHandle_t **h, s32 frame);
void evtUnitLightOn(evtUnitHandle_t **h);
void evtUnlinkLightObjectBasic(evtUnitHandle_t **h, s32 frame);
void evtUpdateEx_BGM_FADEOUT_E_After(s32 eid, s32 bgmid);
void evtUpdateEx_SE_E_After(s32 eid, s32 seid);
void fldBgmFadeOut(void);
void fldBgmPause(void);
void fldBgmStop(void);
void fldCamSyukanSuriawase(void);
s32 fldCommand_GetHojiID(char **pName);
void fldGbSetGimic(s32 fld, s32 area, s32 hojiID, s32 toplast);
dds3Basic_t *fldGetMatter_From_ModelRangeID(s32 modelRangeID);
dds3Basic_t *fldGetUnitFollowCamera(void);
void fldNpcShadow_Del(dds3Basic_t **aBasic);
void fldProcNext(s32 fld, s32 eveno);
void fldProc_SisetuReturnPoint(s32 fld, s32 area, u16 **pName);
void fldSetCharClr(void);
void fldSetSceneParam2(fldSceneParam_t *pParam, s32 loadField, s32 loadArea, char *pointResName);
void fldSetSceneParam3(fldSceneParam_t *pParam, s32 loadField, s32 loadArea, char *pointResName);
void fldSkySetAlpha(s32 alp);
void fldSkySetFilter(s32 idx, s32 mode, s32 hokan);
void fldSkySetFilterAnime(s32 type);
void itfMesMngSetKutiCallback(s32 id, instanceMes_tag_func_kutiDelegate *func);
s32 mdlChkMotionEndEx(dds3ModelHandle_t **aHandle, s32 aGroup);
void mdlHide(dds3ModelHandle_t *mdl);
void mdlShow(dds3ModelHandle_t *mdl);
void p2sdBGMVolHalfDown(void);
void p2sdBGMVolHalfUp(void);
s32 p2sdPlaySE(s32 a);
void scrAllReleaseScript(void);
s32 scrGetCommandTimer(void);
f32 scrGetFloatPara(s32 n);
s32 scrGetIntPara(s32 n);
s32 scrGetMessageHandle(void);
scrProcessWork_s *scrGetScriptHandle(void);
char *scrGetStrPara(s32 n);
void scrSetIntReturnValue(s32 i);
s32 sdfDelayedResrcCheck(void);
f32 sdfFabs(f32 c);

// 0x135a8e0
void CallBattleSub(s32 encno, s32 eventno) {
  s64 v4;
  u64 *v9;
  s64 v11;

  v4 = encno;
  fldBgmStop();
  p2sdPlaySE(15);
  encStart(0);
  evtNextEventNo = eventno;
  v11 = v4 << 32;
  v9 = sub_8D3950(nbNewBattleSeqData_t, &v11);
  dds3AdminiCallSequence(20, v9, 2, eventno > 0);
  scrAllReleaseScript();
}

// 0x135aae0
void CallBattleSub2(s32 encno) {
  s64 v2;
  u64 *v8;
  System_RuntimeTypeHandle_o v9;
  System_Type_o *TypeFromHandle;
  s32 v12;
  s64 v14;

  v2 = encno;
  fldBgmPause();
  p2sdPlaySE(15);
  encStart(0);
  evtNextEventNo = 0;
  v14 = v2 << 32;
  v8 = sub_8D3950(nbNewBattleSeqData_t, &v14);
  v9.value = nbNewBattleSeqData_t_var;
  TypeFromHandle = GetTypeFromHandle(v9);
  {
  }
  v12 = SizeOf_1552656(TypeFromHandle);
  dds3AdminiCallSequence(20, v8, v12, 1);
  scrAllReleaseScript();
}

// 0x13547d0
void KutiFunction(void) {
  evtRunUnitKutiMotion(&KutiModel);
}

// 0x1357760
f32 evtCalcEffBedScale(s32 uid) {
  f32 formsize;
  f32 formheight;
  f32 v5;

  formsize = Get(uid, 0)->formsize;
  formheight = Get(uid, 0)->formheight;
  v5 = (Get(uid, 0)->formscale * ((formsize + (formheight * 0.5)) * 0.5)) * 0.014286;
  if (v5 > 2.0)
    return 2.0;
  else
    return fmaxf(v5, 0.8);
}

// 0x1360800
s32 evtCommand_BGM_PLAY_E(void) {
  s32 IntPara;
  s32 v3;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  evtPlayBgm(IntPara, v3);
  return 1;
}

// 0x1360890
s32 evtCommand_BGM_TRANS_E(void) {
  s32 IntPara;
  s32 v3;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  evtTransBgm(IntPara, v3);
  return 1;
}

// 0x1360a00
s32 evtCommand_BGM_VOL_DOWN(void) {
  p2sdBGMVolHalfDown();
  return 1;
}

// 0x1360a70
s32 evtCommand_BGM_VOL_UP(void) {
  p2sdBGMVolHalfUp();
  return 1;
}

// 0x13606b0
s32 evtCommand_BOKASI_OFF(void) {
  evtSetBokasi(0);
  return 1;
}

// 0x1360640
s32 evtCommand_BOKASI_ON(void) {
  evtSetBokasi(1);
  return 1;
}

// 0x135aa40
s32 evtCommand_CALL_BATTLE(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  CallBattleSub(IntPara, 0);
  return 1;
}

// 0x135aca0
s32 evtCommand_CALL_BATTLE2(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  CallBattleSub2(IntPara);
  return 1;
}

// 0x1359d40
s32 evtCommand_CALL_COMBINE(void) {
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  System_String_o *StrPara;
  System_String_o *v7;
  System_Char_array *v9;

  fieldID = fldGb->fieldID;
  areaID = fldGb->areaID;
  StrPara = scrGetStrPara(0);
  v7 = (StrPara->klass->vtable._3_ToString.methodPtr)(StrPara, StrPara->klass->vtable._3_ToString.method);
  v9 = ToCharArray(v7);
  fldProc_SisetuReturnPoint(fieldID, areaID + 1, v9);
  dds3AdminiCallSequence(28, 0, 0, 0);
  scrSetIntReturnValue(0);
  return 1;
}

// 0x1359d10
s32 evtCommand_CALL_ENDSAVE(void) {
  dds3AdminiCallSequence(6, 0, 0, 0);
  return 1;
}

// 0x135a5c0
s32 evtCommand_CALL_EVENT(void) {
  s32 IntPara;
  System_Object_array *v3;
  s64 *v4;
  s64 *v6;
  u64 *v9;
  s32 v14;
  s32 v15;

  IntPara = scrGetIntPara(0);
  v15 = IntPara;
  v3 = NewSpecific(object, 1u);
  v4 = sub_8D3950(s32, &v15);
  v6 = v4;
  v3->m_Items[0] = v6;
  Log("call_event:{0:D}\n", v3, 0);
  RemoveKeys(5, 0);
  SndAssetBundleManager_SndData___Clear(VoiceBundleTable);
  v14 = IntPara;
  v9 = sub_8D3950(s32, &v14);
  dds3AdminiCallSequence(8, v9, 4, 0);
  scrAllReleaseScript();
  UnloadUnusedAssets();
  Collect(0);
  return 1;
}

// 0x135adf0
s32 evtCommand_CALL_FIELD(void) {
  s32 IntPara;
  s32 v4;
  System_String_o *StrPara;
  u64 *v7;
  char v10[136];
  fldSceneParam_t_o pParam;

  memset(&pParam, 0, sizeof(pParam));
  sub_F87580(&pParam);
  fldBgmFadeOut();
  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  StrPara = scrGetStrPara(2);
  fldSetSceneParam2(&pParam, IntPara, v4, StrPara);
  memcpy(v10, &pParam, sizeof(v10));
  v7 = sub_8D3950(fldSceneParam_t, v10);
  dds3AdminiCallSequence(7, v7, 2, 0);
  scrAllReleaseScript();
  return 1;
}

// 0x135af90
s32 evtCommand_CALL_FIELD2(void) {
  s32 fieldID;
  s32 IntPara;
  System_String_o *StrPara;
  u64 *v7;
  char v10[136];
  fldSceneParam_t_o pParam;

  memset(&pParam, 0, sizeof(pParam));
  sub_F87580(&pParam);
  fieldID = fldGb->fieldID;
  IntPara = scrGetIntPara(0);
  StrPara = scrGetStrPara(1);
  fldSetSceneParam2(&pParam, fieldID, IntPara, StrPara);
  memcpy(v10, &pParam, sizeof(v10));
  v7 = sub_8D3950(fldSceneParam_t, v10);
  dds3AdminiCallSequence(7, v7, 2, 0);
  scrAllReleaseScript();
  return 1;
}

// 0x135b120
s32 evtCommand_CALL_FIELD3(void) {
  s32 fieldID;
  s32 IntPara;
  System_String_o *StrPara;
  u64 *v7;
  char v10[136];
  fldSceneParam_t_o pParam;

  memset(&pParam, 0, sizeof(pParam));
  sub_F87580(&pParam);
  fieldID = fldGb->fieldID;
  IntPara = scrGetIntPara(0);
  StrPara = scrGetStrPara(1);
  fldSetSceneParam3(&pParam, fieldID, IntPara, StrPara);
  memcpy(v10, &pParam, sizeof(v10));
  v7 = sub_8D3950(fldSceneParam_t, v10);
  dds3AdminiCallSequence(7, v7, 2, 0);
  scrAllReleaseScript();
  return 1;
}

// 0x135a450
s32 evtCommand_CALL_NEXT(void) {
  u64 *v2;
  u64 *v3;
  u64 *v5;
  s32 v6;
  s32 v8;
  s32 v10;
  s32 v11;
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  v2 = sub_8D3950(s32, &IntPara);
  v11 = scrGetIntPara(1);
  v3 = sub_8D3950(s32, &v11);
  v10 = scrGetIntPara(2);
  v5 = sub_8D3950(s32, &v10);
  Write_2930912("CALL_NEXT({0:D},{1:D},{2:D})\n", v2, v3, v5, 0);
  v6 = scrGetIntPara(1);
  v8 = scrGetIntPara(2);
  fldProcNext(v6, v8);
  return 1;
}

// 0x135a2c0
s32 evtCommand_CALL_PUZZLEBOY(void) {
  u64 *v2;
  s32 IntPara;
  s32 fieldID;
  s32 v10;

  v2 = NewSpecific(uint, 1u);
  fldBgmFadeOut();
  IntPara = scrGetIntPara(0);
  *(v2 + 8) = IntPara;
  fieldID = fldGb->fieldID;
  v10 = *(v2 + 8);
  fldProcNext(fieldID, v10 + 1000);
  dds3AdminiCallSequence(39, v2, 4, 0);
  scrAllReleaseScript();
  return 1;
}

// 0x135a0a0
s32 evtCommand_CALL_RAG(void) {
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  System_String_o *StrPara;
  System_String_o *v7;
  System_Char_array *v9;

  fieldID = fldGb->fieldID;
  areaID = fldGb->areaID;
  StrPara = scrGetStrPara(0);
  v7 = (StrPara->klass->vtable._3_ToString.methodPtr)(StrPara, StrPara->klass->vtable._3_ToString.method);
  v9 = ToCharArray(v7);
  fldProc_SisetuReturnPoint(fieldID, areaID + 1, v9);
  dds3AdminiCallSequence(30, 0, 0, 0);
  scrSetIntReturnValue(0);
  return 1;
}

// 0x1359e60
s32 evtCommand_CALL_RECOVER(void) {
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  System_String_o *StrPara;
  System_String_o *v7;
  System_Char_array *v9;

  fieldID = fldGb->fieldID;
  areaID = fldGb->areaID;
  StrPara = scrGetStrPara(0);
  v7 = (StrPara->klass->vtable._3_ToString.methodPtr)(StrPara, StrPara->klass->vtable._3_ToString.method);
  v9 = ToCharArray(v7);
  fldProc_SisetuReturnPoint(fieldID, areaID + 1, v9);
  dds3AdminiCallSequence(31, 0, 0, 0);
  scrSetIntReturnValue(0);
  return 1;
}

// 0x135a1c0
s32 evtCommand_CALL_SAVE(void) {
  u64 *v2;
  s32 IntPara;
  s32 v5;

  v2 = NewSpecific(uint, 2u);
  IntPara = scrGetIntPara(0);
  *(v2 + 8) = IntPara;
  v5 = scrGetIntPara(1);
  *(v2 + 9) = v5;
  dds3AdminiCallSequence(32, v2, 8, 0);
  scrSetIntReturnValue(0);
  return 1;
}

// 0x1359f80
s32 evtCommand_CALL_SHOP(void) {
  struct fldGlobalWork_t_o *fldGb;
  s32 fieldID;
  s32 areaID;
  System_String_o *StrPara;
  System_String_o *v7;
  System_Char_array *v9;

  fieldID = fldGb->fieldID;
  areaID = fldGb->areaID;
  StrPara = scrGetStrPara(0);
  v7 = (StrPara->klass->vtable._3_ToString.methodPtr)(StrPara, StrPara->klass->vtable._3_ToString.method);
  v9 = ToCharArray(v7);
  fldProc_SisetuReturnPoint(fieldID, areaID + 1, v9);
  dds3AdminiCallSequence(29, 0, 0, 0);
  scrSetIntReturnValue(0);
  return 1;
}

// 0x1359c80
s32 evtCommand_CALL_STAFF(void) {
  UnloadALL(0, 0);
  dds3AdminiCallSequence(17, 0, 0, 0);
  return 1;
}

// 0x135c560
s32 evtCommand_CAM_CLS(void) {
  s32 IntPara;
  dds3Basic_t_o *basic;

  basic = 0;
  IntPara = scrGetIntPara(0);
  basic = evtSearchBasic(4, IntPara);
  if (basic)
  {
    dds3DeleteSceneBasicData(&basic);
  }
  return 1;
}

// 0x135c440
s32 evtCommand_CAM_CREATE(void) {
  u32 v2;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o v6;
  UnityEngine_Vector4_o v7;

  *&v7.x = 0;
  *&v7.z = 0;
  *&v6.x = 0;
  *&v6.z = 0;
  pBasic = 0;
  sub_854690(&v7.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v6.x, 0.0, 0.0, 0.0, 1.0);
  v2 = dds3SerializeID();
  pBasic = dds3AddCameraObjectBasicTypeFree(v2, v7, v6);
  dds3SetRadiusPoseSet(&pBasic, 1.0);
  scrSetIntReturnValue(v2);
  return 1;
}

// 0x135c0c0
s32 evtCommand_CAM_PATH_MOVE(void) {
  s32 IntPara;
  dds3Basic_t_o *UnitFollowCamera;
  s32 v10;
  dds3Basic_t_o *v11;
  dds3Basic_t_o *v12;

  else if ((scrGetIntPara(0) & 0x80000000) == 0)
  {
LABEL_6:
    IntPara = scrGetIntPara(0);
    UnitFollowCamera = evtSearchBasic(4, IntPara);
    if (!UnitFollowCamera)
      goto LABEL_32;
    goto LABEL_13;
  }
  else
  {
    UnitFollowCamera = fldGetUnitFollowCamera();
    if (!UnitFollowCamera)
      goto LABEL_32;
  }
LABEL_13:
  v10 = scrGetIntPara(1);
  else
  {
    v11 = evtSearchBasic(16, v10);
    if (!v11)
      goto LABEL_32;
  }
  v12 = v11;
  if (evtPathLinkAndMake(v12, UnitFollowCamera))
    return 1;
LABEL_32:
  Write("CAM_PATH_MOVE error!\n", 0);
  return 1;
}

// 0x135c2d0
s32 evtCommand_CAM_PATH_WAIT(void) {
  s32 IntPara;
  dds3Basic_t_o *UnitFollowCamera;

  if (scrGetIntPara(0) < 0)
    goto LABEL_15;
LABEL_6:
  IntPara = scrGetIntPara(0);
  UnitFollowCamera = evtSearchBasic(4, IntPara);
  if (!UnitFollowCamera)
    return 1;
LABEL_18:
  return (evtCheckPathStat(UnitFollowCamera) + 1) <= 1;
}

// 0x135c640
s32 evtCommand_CAM_POS_XYZ(void) {
  s32 IntPara;
  s64 v8;
  s64 v9;
  dds3Basic_t_o *pBasic;
  s64 v12;
  s64 v13;
  UnityEngine_Vector4_o v14;

  v12 = 0;
  v13 = 0;
  pBasic = 0;
  sub_854690(&v12, 0.0, 0.0, 0.0, 0.0);
  if (scrGetIntPara(0) < 0)
    goto LABEL_22;
LABEL_6:
  IntPara = scrGetIntPara(0);
  pBasic = evtSearchBasic(4, IntPara);
  if (pBasic)
  {
LABEL_13:
    scrGetFloatPara(1);
    sub_854930(&v12, 0);
    scrGetFloatPara(2);
    sub_854930(&v12, 1u);
    scrGetFloatPara(3);
    sub_854930(&v12, 2u);
    v8 = v12;
    v9 = v13;
    *&v14.x = v8;
    *&v14.z = v9;
    dds3SetPosPoseSet(&pBasic, v14);
  }
  return 1;
}

// 0x135caa0
s32 evtCommand_CAM_ROT_Q(void) {
  s32 IntPara;
  s64 v8;
  s64 v9;
  dds3Basic_t_o *pBasic;
  s64 v12;
  s64 v13;
  UnityEngine_Vector4_o v14;

  pBasic = 0;
  v12 = 0;
  v13 = 0;
  if (scrGetIntPara(0) < 0)
    goto LABEL_22;
LABEL_6:
  IntPara = scrGetIntPara(0);
  pBasic = evtSearchBasic(4, IntPara);
  if (pBasic)
  {
LABEL_13:
    scrGetFloatPara(1);
    sub_854930(&v12, 0);
    scrGetFloatPara(2);
    sub_854930(&v12, 1u);
    scrGetFloatPara(3);
    sub_854930(&v12, 2u);
    scrGetFloatPara(4);
    sub_854930(&v12, 3u);
    v8 = v12;
    v9 = v13;
    *&v14.x = v8;
    *&v14.z = v9;
    dds3SetRotPoseSet(&pBasic, v14);
  }
  return 1;
}

// 0x135c850
s32 evtCommand_CAM_ROT_XYZ(void) {
  s32 IntPara;
  f32 FloatPara;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v22;

  pBasic = 0;
  *&p.x = 0;
  *&p.z = 0;
  if (scrGetIntPara(0) < 0)
    goto LABEL_25;
LABEL_6:
  IntPara = scrGetIntPara(0);
  pBasic = evtSearchBasic(4, IntPara);
  if (pBasic)
  {
LABEL_13:
    FloatPara = scrGetFloatPara(1);
    v9 = SDF_DEGtoRAD(FloatPara);
    v10 = scrGetFloatPara(2);
    v11 = SDF_DEGtoRAD(v10);
    FromEuler(v9, v11, 0.0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    v12 = scrGetFloatPara(3);
    v13 = SDF_DEGtoRAD(v12);
    FromEuler(0.0, 0.0, v13);
    Mult();
    SDF_VU0__STOREVECTOR(&p);
    x = p.x;
    y = p.y;
    z = p.z;
    w = p.w;
    v22.x = x;
    v22.y = y;
    v22.z = z;
    v22.w = w;
    dds3SetRotPoseSet(&pBasic, v22);
  }
  return 1;
}

// 0x135bcf0
s32 evtCommand_CAM_SEL(void) {
  s32 IntPara;
  dds3Basic_t_o *pSceneBasic;
  dds3Basic_t_o *pCameraBasic;

  pCameraBasic = 0;
  pSceneBasic = 0;
  else if ((scrGetIntPara(0) & 0x80000000) == 0)
  {
LABEL_6:
    fldCamSyukanSuriawase();
    IntPara = scrGetIntPara(0);
    pCameraBasic = evtSearchBasic(4, IntPara);
    if (!pCameraBasic)
      return 1;
LABEL_22:
    pSceneBasic = dds3GetActiveScene();
    dds3SetActiveCameraSceneBasic(&pSceneBasic, &pCameraBasic);
    return 1;
  }
  pCameraBasic = fldGetUnitFollowCamera();
  if (pCameraBasic)
    goto LABEL_22;
  return 1;
}

// 0x135bea0
s32 evtCommand_CAM_SEL_FOVY(void) {
  s32 IntPara;
  dds3Basic_t_o *v6;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *v16[3];
  dds3Basic_t_o *pCameraBasic;

  ActiveScene = 0;
  pCameraBasic = 0;
  if (scrGetIntPara(0) < 0)
    goto LABEL_17;
LABEL_6:
  IntPara = scrGetIntPara(0);
  v6 = evtSearchBasic(4, IntPara);
  pCameraBasic = v6;
  if (v6)
  {
    workdata = v6->workdata;
    klass = workdata->klass;
    if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3CameraObjectBasicWorkData_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3CameraObjectBasicWorkData_t, v16);
      if ((v16[0] & 1) != 0)
        v13 = v16[2];
      else
        v13 = v16 + 1;
      v14 = sub_8C4940(v13);
    }
    HIDWORD(workdata[6].klass) |= 1u;
LABEL_21:
    ActiveScene = dds3GetActiveScene();
    dds3SetActiveCameraSceneBasic(&ActiveScene, &pCameraBasic);
  }
  return 1;
}

// 0x135d600
s32 evtCommand_CHG_MOON(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  evtSetAgeOfMoon(IntPara);
  return 1;
}

// 0x135dae0
s32 evtCommand_CHK_BE(void) {
  u64 *v1;
  u64 *v2;
  s32 IntPara;
  System_Object_array *v6;
  s64 *v7;
  s64 *v8;
  s32 v12;
  s32 v14;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  IntPara = scrGetIntPara(0);
  if (!scrGetScriptHandle())
    goto LABEL_24;
  else if (!evtSearchEventPack(IntPara))
  {
    goto LABEL_24;
  }
  if (evtGetEventPackStat(IntPara) == 2)
  {
    v14 = IntPara;
    v6 = NewSpecific(object, 1u);
    v7 = sub_8D3950(s32, &v14);
    v8 = v7;
    v6->m_Items[0] = v8;
    dds3Printf("BE ok! (%d)\n", v6, 0);
    v12 = 1;
    goto LABEL_28;
  }
LABEL_24:
  v12 = 0;
LABEL_28:
  scrSetIntReturnValue(v12);
  return 1;
}

// 0x135dce0
s32 evtCommand_DEL_BE(void) {
  u64 *v1;
  u64 *v2;
  s32 IntPara;
  System_Object_array *v6;
  s64 *v7;
  s64 *v8;
  s32 v13;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  IntPara = scrGetIntPara(0);
  if (scrGetScriptHandle())
  {
    if (evtSearchEventPack(IntPara))
    {
      v13 = IntPara;
      v6 = NewSpecific(object, 1u);
      v7 = sub_8D3950(s32, &v13);
      v8 = v7;
      v6->m_Items[0] = v8;
      dds3Printf("del BE (%d)..\n", v6, 0);
      evtKillEventPack(IntPara);
    }
  }
  return 1;
}

// 0x1360fb0
s32 evtCommand_DIST_BLUR_TEX_BE(void) {
  s32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  evtDispBlurTexSet(IntPara, v4);
  return 1;
}

// 0x1361060
s32 evtCommand_DIST_BLUR_TEX_DEF(void) {
  Eve_DistortionBlurSetDefTex();
  return 1;
}

// 0x13610d0
s32 evtCommand_DRAWSTOP(void) {
  s32 IntPara;
  u32 v4;

  IntPara = scrGetIntPara(0);
  if (IntPara <= 0)
  {
    v4 = 1;
  }
  else
  {
    v4 = IntPara;
  }
  SetDrawFlag(0x2000000u, v4);
  return 1;
}

// 0x1357170
s32 evtCommand_EFFBED_BE(void) {
  s32 IntPara;
  s32 v4;
  System_Byte_array *ResorceData;
  System_Byte_array *v7;
  s32 v8;
  u64 *v9;
  System_String_o *v10;
  System_Object_array *v12;
  dds3Basic_t_o *v18;
  u32 serialID;
  s32 v22;
  System_Object_array *v24;
  s64 *v25;
  s64 *v26;
  s32 PibIndex;
  dds3Basic_t_o *basic;
  UnityEngine_Vector4_o v32;
  UnityEngine_Vector4_o v33;

  *&v33.x = 0;
  *&v33.z = 0;
  *&v32.x = 0;
  *&v32.z = 0;
  basic = 0;
  sub_854690(&v33.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v32.x, 0.0, 0.0, 0.0, 0.0);
  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  ResorceData = evtGetResorceData(IntPara, v4);
  if (!ResorceData)
  {
    v24 = NewSpecific(object, 1u);
    PibIndex = scrGetIntPara(1);
    v25 = sub_8D3950(s32, &PibIndex);
    v26 = v25;
    v24->m_Items[0] = v26;
    dds3Printf("EFFBED_BE not fount RID = %d\n", v24);
    goto LABEL_54;
  }
  v7 = ResorceData;
  PibIndex = GetPibIndex(v7, 0);
  v8 = PibIndex;
  v9 = sub_8D3950(s32, &PibIndex);
  v10 = Concat_5269984("!!!!! EFFBED_BE : index = ", v9, " !!!!!");
  v12 = Empty_string_();
  Log(v10, v12, 0);
  BillSetPB(v8);
  if (scrGetIntPara(0) == 723)
  {
    if (scrGetIntPara(1) == 6)
      goto LABEL_59;
    if (scrGetIntPara(1) == 7)
    {
LABEL_59:
      billAlfRaitoSet2(3.0);
      billCutRaitoSet2(20.0);
    }
  }
  v18 = dds3AddBEDEffectObjectBasic2(&v7->obj, v33, v32);
  basic = v18;
  billAlfRaitoSet2(0.0);
  billCutRaitoSet2(0.0);
  if (!v18)
  {
LABEL_54:
    v22 = 0;
    goto LABEL_55;
  }
  dds3EffectObjectBasicStatOn(&basic, 1u);
  serialID = basic->serialID;
  v22 = serialID;
LABEL_55:
  scrSetIntReturnValue(v22);
  return 1;
}

// 0x13575c0
s32 evtCommand_EFFBED_BE_EVO(void) {
  return 1;
}

// 0x1356fd0
s32 evtCommand_EFFBED_LOAD(void) {
  System_String_o *StrPara;
  u32 serialID;
  s32 v6;
  Il2CppObject *v8;
  UnityEngine_Vector4_o v10;
  UnityEngine_Vector4_o v11;
  dds3Basic_t_o *basic;

  *&v11.x = 0;
  *&v11.z = 0;
  *&v10.x = 0;
  *&v10.z = 0;
  basic = 0;
  sub_854690(&v11.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v10.x, 0.0, 0.0, 0.0, 1.0);
  StrPara = scrGetStrPara(0);
  basic = dds3AddBEDEffectObjectBasic(StrPara, v11, v10);
  if (basic)
  {
    dds3EffectObjectBasicStatOn(&basic, 1u);
    serialID = basic->serialID;
    v6 = serialID;
  }
  else
  {
    Write("スクリプトコマンドEFFECT_LOAD()で対象ファイル\n", 0);
    v8 = scrGetStrPara(0);
    Write_2930400("{0}が見つかりません!!\n", v8);
    v6 = 0;
  }
  scrSetIntReturnValue(v6);
  return 1;
}

// 0x13575d0
s32 evtCommand_EFFBED_START(void) {
  s32 IntPara;
  u32 v6;
  System_Object_array *v7;
  s64 *v8;
  s64 *v9;
  u32 v13;
  dds3Basic_t_o *basic;

  basic = 0;
  IntPara = scrGetIntPara(0);
  basic = evtSearchBasic(7, IntPara);
  if (basic)
  {
    v6 = scrGetIntPara(1);
    if (v6 < 3)
    {
      dds3StartBEDEffectObjectBasic(&basic, v6);
    }
    else
    {
      v13 = v6;
      v7 = NewSpecific(object, 1u);
      v8 = sub_8D3950(uint, &v13);
      v9 = v8;
      v7->m_Items[0] = v9;
      dds3Printf("error EFFBED_START cut no over = %d\n", v7);
    }
  }
  return 1;
}

// 0x1357850
s32 evtCommand_EFFBED_START_EVO(void) {
  u64 *v1;
  s32 IntPara;
  u32 v7;
  System_Object_array *v8;
  s64 *v9;
  s64 *v10;
  s32 v13;
  s32 v15;
  f32 v16;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effEveBEDCutHandle_t_o *v20;
  effEveBEDCutHandle_t_c *v21;
  s64 v22;
  char *v23;
  s64 *v24;
  f32 v27;
  char *v28;
  s64 *v29;
  effEveBEDCutHandle_t_o *hEveBEDCut;
  dds3Basic_t_o *basic;
  char v32[16];
  char *v33;

  basic = 0;
  v1 = Allocate(effEveBEDCutHandle_t);
  effEveBEDCutHandle_t___ctor(v1);
  hEveBEDCut = v1;
  IntPara = scrGetIntPara(0);
  basic = evtSearchBasic(7, IntPara);
  if (basic)
  {
    v7 = scrGetIntPara(1);
    if (v7 < 3)
    {
      dds3StartBEDEffectObjectBasic(&basic, v7);
      else
      {
        v13 = scrGetIntPara(2);
        if (v13 < 0)
          return 1;
      }
      v15 = v13;
      v16 = evtCalcEffBedScale(v15);
      workdata = basic->workdata;
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v32);
        if ((v32[0] & 1) != 0)
          v28 = v33;
        else
          v28 = &v32[1];
        v29 = sub_8C4940(v28);
      }
      v20 = workdata[5].klass;
      if (v20)
      {
        v21 = v20->klass;
        if (v20->klass->_2.typeHierarchyDepth < v22
          || v21->_2.typeHierarchy[v22 - 1] != effEveBEDCutHandle_t)
        {
          sub_8FC2C0(v21->_1.element_class, effEveBEDCutHandle_t, v32);
          if ((v32[0] & 1) != 0)
            v23 = v33;
          else
            v23 = &v32[1];
          v24 = sub_8C4940(v23);
        }
        hEveBEDCut = v20;
        v27 = v16;
        effEveBEDCutSetScale(&hEveBEDCut, v27);
      }
      else
      {
        hEveBEDCut = 0;
      }
    }
    else
    {
      *v32 = v7;
      v8 = NewSpecific(object, 1u);
      v9 = sub_8D3950(uint, v32);
      v10 = v9;
      v8->m_Items[0] = v10;
      dds3Printf("error EFFBED_START cut no over = %d\n", v8);
    }
  }
  return 1;
}

// 0x1356ba0
s32 evtCommand_EFFECT_BE(void) {
  s32 IntPara;
  s32 v4;
  System_Byte_array *ResorceData;
  u32 serialID;
  s32 v9;
  System_Object_array *v11;
  s64 *v12;
  s64 *v13;
  s32 v18;
  dds3Basic_t_o *basic;
  UnityEngine_Vector4_o v20;
  UnityEngine_Vector4_o v21;

  *&v21.x = 0;
  *&v21.z = 0;
  *&v20.x = 0;
  *&v20.z = 0;
  basic = 0;
  sub_854690(&v21.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v20.x, 0.0, 0.0, 0.0, 0.0);
  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  ResorceData = evtGetResorceData(IntPara, v4);
  if (!ResorceData)
  {
    v11 = NewSpecific(object, 1u);
    v18 = scrGetIntPara(1);
    v12 = sub_8D3950(s32, &v18);
    v13 = v12;
    v11->m_Items[0] = v13;
    dds3Printf("EFFECT_BE not fount RID = %d\n", v11);
    goto LABEL_29;
  }
  basic = dds3AddD3PEffectObjectBasic2(&ResorceData->obj, v21, v20);
  if (!basic)
  {
    Write("EFFECT_BE()登録失敗\n", 0);
LABEL_29:
    v9 = 0;
    goto LABEL_30;
  }
  dds3EffectObjectBasicStatOn(&basic, 1u);
  serialID = basic->serialID;
  v9 = serialID;
LABEL_30:
  scrSetIntReturnValue(v9);
  return 1;
}

// 0x1358400
s32 evtCommand_EFFECT_CLS(void) {
  s32 IntPara;
  dds3Basic_t_o *basic;

  basic = 0;
  IntPara = scrGetIntPara(0);
  basic = evtSearchBasic(7, IntPara);
  if (basic)
  {
    dds3DeleteSceneBasicData(&basic);
  }
  return 1;
}

// 0x13592b0
s32 evtCommand_EFFECT_LINK(void) {
  s32 IntPara;
  u32 v6;
  s32 v9;
  dds3Basic_t_o *v10;
  dds3Basic_t_o *v12;
  dds3Basic_t_o *basic;

  basic = 0;
  v12 = 0;
  IntPara = scrGetIntPara(0);
  basic = evtSearchBasic(7, IntPara);
  if (basic)
  {
    v6 = 4;
    v12 = 0;
    do
    {
      v9 = scrGetIntPara(1);
      v10 = evtSearchBasic(v6++, v9);
    }
    while (v6 <= 9 && !v10);
    v12 = v10;
    if (v10)
      dds3EffectObjectBasicLinkObject(&basic, &v12);
  }
  return 1;
}

// 0x13593f0
s32 evtCommand_EFFECT_LINK2(void) {
  s32 IntPara;
  u32 v6;
  s32 v9;
  dds3Basic_t_o *v10;
  s32 v11;
  dds3Basic_t_o *v13;
  dds3Basic_t_o *basic;

  basic = 0;
  v13 = 0;
  IntPara = scrGetIntPara(0);
  basic = evtSearchBasic(7, IntPara);
  if (basic)
  {
    v6 = 4;
    v13 = 0;
    do
    {
      v9 = scrGetIntPara(1);
      v10 = evtSearchBasic(v6++, v9);
    }
    while (v6 <= 9 && !v10);
    v13 = v10;
    if (v10)
    {
      v11 = scrGetIntPara(2);
      dds3EffectObjectBasicLinkObjectIndex(&basic, &v13, v11);
    }
  }
  return 1;
}

// 0x1356e30
s32 evtCommand_EFFECT_LOAD(void) {
  System_String_o *StrPara;
  u32 serialID;
  s32 v6;
  Il2CppObject *v8;
  UnityEngine_Vector4_o v10;
  UnityEngine_Vector4_o v11;
  dds3Basic_t_o *basic;

  *&v11.x = 0;
  *&v11.z = 0;
  *&v10.x = 0;
  *&v10.z = 0;
  basic = 0;
  sub_854690(&v11.x, 0.0, 0.0, 0.0, 0.0);
  sub_854690(&v10.x, 0.0, 0.0, 0.0, 0.0);
  StrPara = scrGetStrPara(0);
  basic = dds3AddD3PEffectObjectBasic(StrPara, v11, v10);
  if (basic)
  {
    dds3EffectObjectBasicStatOn(&basic, 1u);
    serialID = basic->serialID;
    v6 = serialID;
  }
  else
  {
    Write("スクリプトコマンドEFFECT_LOAD()で対象ファイル\n", 0);
    v8 = scrGetStrPara(0);
    Write_2930400("{0}が見つかりません!!\n", v8);
    v6 = 0;
  }
  scrSetIntReturnValue(v6);
  return 1;
}

// 0x1359610
s32 evtCommand_EFFECT_OFF(void) {
  s32 IntPara;
  dds3Basic_t_o *v5;
  dds3Basic_t_o *v7;

  IntPara = scrGetIntPara(0);
  v5 = evtSearchBasic(7, IntPara);
  if (v5)
  {
    v7 = v5;
    evtEffectLoopControl(v7, 0);
  }
  return 1;
}

// 0x13591c0
s32 evtCommand_EFFECT_ON(void) {
  s32 IntPara;
  dds3Basic_t_o *v5;
  dds3Basic_t_o *v7;
  dds3Basic_t_o *basic;

  basic = 0;
  IntPara = scrGetIntPara(0);
  v5 = evtSearchBasic(7, IntPara);
  basic = v5;
  if (v5)
  {
    v7 = v5;
    evtEffectLoopControl(v7, 1);
    dds3EffectObjectBasicStatOn(&basic, 1u);
  }
  return 1;
}

// 0x13596f0
s32 evtCommand_EFFECT_PATH_MOVE(void) {
  s32 IntPara;
  dds3Basic_t_o *v5;
  dds3Basic_t_o *v7;
  s32 v10;
  dds3Basic_t_o *v11;
  dds3Basic_t_o *v13;
  System_Object_array *v15;
  s64 *v16;

  IntPara = scrGetIntPara(0);
  v5 = evtSearchBasic(7, IntPara);
  if (!v5)
    goto LABEL_20;
LABEL_9:
  v7 = v5;
  v10 = scrGetIntPara(1);
  v11 = evtSearchBasic(16, v10);
  if (!v11)
  {
LABEL_22:
    v15 = Empty_string_();
    v16 = &"EFFECT_PATH_MOVE not found path!\n";
    goto LABEL_23;
  }
LABEL_15:
  v13 = v11;
  evtPathLinkAndMake(v13, v7);
  return 1;
}

// 0x1359890
s32 evtCommand_EFFECT_PATH_WAIT(void) {
  s32 IntPara;
  dds3Basic_t_o *v5;
  dds3Basic_t_o *v7;

  IntPara = scrGetIntPara(0);
  v5 = evtSearchBasic(7, IntPara);
  if (!v5)
    goto LABEL_15;
LABEL_9:
  v7 = v5;
  return (evtCheckPathStat(v7) + 1) <= 1;
}

// 0x13589f0
s32 evtCommand_EFFECT_POS(void) {
  s32 IntPara;
  dds3Basic_t_o *v5;
  dds3Basic_t_o *v7;
  s32 v10;
  dds3Basic_t_o *v11;
  s64 workdata;
  Il2CppClass *v13;
  char *v14;
  s64 *v15;
  s64 *v17;
  s64 v18;
  s64 v19;
  s64 v20;
  s64 v21;
  Il2CppObject *v22;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s64 p_pos;
  s64 v26;
  s64 v27;
  s64 p_rot;
  s64 v29;
  s64 v30;
  s64 v31;
  char *v34;
  s64 *v35;
  s64 v36;
  s64 v37;
  s64 v38;
  s64 v39;
  s64 v40;
  s64 v41;
  u64 v42[2];
  char *v43;

  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  IntPara = scrGetIntPara(0);
  else
  {
    v5 = evtSearchBasic(7, IntPara);
    if (!v5)
      return 1;
  }
  v7 = v5;
  v10 = scrGetIntPara(1);
  else
  {
    v11 = evtSearchBasic(17, v10);
    if (!v11)
      return 1;
  }
  workdata = v11->workdata;
  if (!workdata)
    sub_8C38A0();
  v13 = *(*workdata + 64LL);
  {
    sub_8FC2C0(v13, fldResourcePoint_t, v42);
    if ((v42[0] & 1) != 0)
      v14 = v43;
    else
      v14 = v42 + 1;
    v15 = sub_8C4940(v14);
  }
  v17 = sub_8D3F90(workdata);
  v18 = v17[1];
  v36 = *v17;
  v37 = v18;
  v19 = v17[2];
  v20 = v17[3];
  v21 = v17[5];
  v40 = v17[4];
  v41 = v21;
  v38 = v19;
  v39 = v20;
  v22 = v7->workdata;
  klass = v22->klass;
  if (v22->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v42);
    if ((v42[0] & 1) != 0)
      v34 = v43;
    else
      v34 = v42 + 1;
    v35 = sub_8C4940(v34);
  }
  if ((v22[1].monitor & 4) == 0)
  {
    p_pos = &v7->poseset->pos;
    sub_854710(&v36, 0);
    sub_854930(p_pos, 0);
    v26 = &v7->poseset->pos;
    sub_854710(&v36, 1u);
    sub_854930(v26, 1u);
    v27 = &v7->poseset->pos;
    sub_854710(&v36, 2u);
    sub_854930(v27, 2u);
    p_rot = &v7->poseset->rot;
    sub_854710(&v38, 0);
    sub_854930(p_rot, 0);
    v29 = &v7->poseset->rot;
    sub_854710(&v38, 1u);
    sub_854930(v29, 1u);
    v30 = &v7->poseset->rot;
    sub_854710(&v38, 2u);
    sub_854930(v30, 2u);
    v31 = &v7->poseset->rot;
    sub_854710(&v38, 3u);
    sub_854930(v31, 3u);
  }
  v7->poseset->flag |= 1u;
  v7->poseset->flag &= ~2u;
  return 1;
}

// 0x13584e0
s32 evtCommand_EFFECT_POS_XYZ(void) {
  s32 IntPara;
  dds3Basic_t_o *v5;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  dds3Basic_t_o *v9;
  s64 p_pos;
  s64 v11;
  s64 v12;
  s64 p_monitor;
  char *v16;
  s64 *v17;
  u64 v18[3];

  IntPara = scrGetIntPara(0);
  else
  {
    v5 = evtSearchBasic(7, IntPara);
    if (!v5)
      return 1;
  }
  workdata = v5->workdata;
  klass = workdata->klass;
  v9 = v5;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v18);
    if ((v18[0] & 1) != 0)
      v16 = v18[2];
    else
      v16 = v18 + 1;
    v17 = sub_8C4940(v16);
  }
  if ((workdata[1].monitor & 4) != 0)
  {
    p_monitor = &workdata[2].monitor;
    scrGetFloatPara(1);
    sub_854930(p_monitor, 0);
    scrGetFloatPara(2);
    sub_854930(p_monitor, 1u);
    scrGetFloatPara(3);
    sub_854930(p_monitor, 2u);
  }
  else
  {
    p_pos = &v5->poseset->pos;
    scrGetFloatPara(1);
    sub_854930(p_pos, 0);
    v11 = &v9->poseset->pos;
    scrGetFloatPara(2);
    sub_854930(v11, 1u);
    v12 = &v9->poseset->pos;
    scrGetFloatPara(3);
    sub_854930(v12, 2u);
    v9->poseset->flag |= 1u;
    v9->poseset->flag &= ~2u;
  }
  return 1;
}

// 0x1358340
s32 evtCommand_EFFECT_PRESET(void) {
  s32 IntPara;
  dds3Basic_t_o *eff;

  eff = 0;
  IntPara = scrGetIntPara(0);
  eff = evtSearchBasic(7, IntPara);
  if (eff)
    dds3EffectObjectPresetMG12(&eff);
  return 1;
}

// 0x1358760
s32 evtCommand_EFFECT_ROT_XYZ(void) {
  s32 IntPara;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  f32 FloatPara;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  char *v21;
  s64 *v22;
  dds3Basic_t_o *v23;
  UnityEngine_Vector4_o p;
  u64 v25[3];
  UnityEngine_Vector4_o v26;

  *&p.x = 0;
  *&p.z = 0;
  v23 = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 1.0);
  IntPara = scrGetIntPara(0);
  v23 = evtSearchBasic(7, IntPara);
  workdata = v23->workdata;
  klass = workdata->klass;
  if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3EffectObjectBasicWorkData_t)
  {
    sub_8FC2C0(klass->_1.element_class, dds3EffectObjectBasicWorkData_t, v25);
    if ((v25[0] & 1) != 0)
      v21 = v25[2];
    else
      v21 = v25 + 1;
    v22 = sub_8C4940(v21);
  }
  if ((workdata[1].monitor & 4) == 0)
  {
    FloatPara = scrGetFloatPara(1);
    v10 = SDF_DEGtoRAD(FloatPara);
    v11 = scrGetFloatPara(2);
    v12 = SDF_DEGtoRAD(v11);
    FromEuler(v10, v12, 0.0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    v13 = scrGetFloatPara(3);
    v14 = SDF_DEGtoRAD(v13);
    FromEuler(0.0, 0.0, v14);
    Mult();
    SDF_VU0__STOREVECTOR(&p);
    x = p.x;
    y = p.y;
    z = p.z;
    w = p.w;
    v26.x = x;
    v26.y = y;
    v26.z = z;
    v26.w = w;
    dds3SetRotPoseSet(&v23, v26);
  }
  return 1;
}

// 0x1359550
s32 evtCommand_EFFECT_UNLINK(void) {
  s32 IntPara;
  dds3Basic_t_o *basic;

  basic = 0;
  IntPara = scrGetIntPara(0);
  basic = evtSearchBasic(7, IntPara);
  if (basic)
    dds3EffectObjectBasicUnlinkObject(&basic);
  return 1;
}

// 0x1357d30
s32 evtCommand_EFFMG1_BE(void) {
  s32 IntPara;
  s32 v4;
  System_Byte_array *ResorceData;
  u32 serialID;
  s32 v9;
  System_Object_array *v11;
  s64 *v12;
  s64 *v13;
  s32 v17;
  dds3Basic_t_o *basic;

  basic = 0;
  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  ResorceData = evtGetResorceData(IntPara, v4);
  if (!ResorceData)
  {
    v11 = NewSpecific(object, 1u);
    v17 = scrGetIntPara(1);
    v12 = sub_8D3950(s32, &v17);
    v13 = v12;
    v11->m_Items[0] = v13;
    dds3Printf("EFFMG1_BE not fount RID = %d\n", v11);
    goto LABEL_26;
  }
  basic = dds3AddMG12EffectObjectBasic2(1, &ResorceData->obj);
  if (!basic)
  {
LABEL_26:
    v9 = 0;
    goto LABEL_27;
  }
  dds3EffectObjectBasicStatOn(&basic, 1u);
  serialID = basic->serialID;
  v9 = serialID;
LABEL_27:
  scrSetIntReturnValue(v9);
  return 1;
}

// 0x1357be0
s32 evtCommand_EFFMG1_LOAD(void) {
  System_String_o *StrPara;
  u32 serialID;
  s32 v6;
  Il2CppObject *v8;
  dds3Basic_t_o *basic;

  basic = 0;
  StrPara = scrGetStrPara(0);
  basic = dds3AddMG12EffectObjectBasic(1, StrPara);
  if (basic)
  {
    dds3EffectObjectBasicStatOn(&basic, 1u);
    serialID = basic->serialID;
    v6 = serialID;
  }
  else
  {
    Write("スクリプトコマンドEFFMG1_LOAD()で対象ファイル\n", 0);
    v8 = scrGetStrPara(0);
    Write_2930400("{0}が見つかりません!!\n", v8);
    v6 = 0;
  }
  scrSetIntReturnValue(v6);
  return 1;
}

// 0x1358dc0
s32 evtCommand_EFFMG1_POS(void) {
  u64 *v1;
  u64 *v2;
  s32 IntPara;
  s32 v10;
  dds3Basic_t_o *v11;
  s32 v12;
  System_Object_array *v14;
  s64 *v15;
  dds3Basic_t_o *v17;
  dds3Basic_t_o *p3;
  dds3Basic_t_o *p2;
  dds3Basic_t_o *p1;
  dds3Basic_t_o *eff;

  eff = 0;
  p2 = 0;
  p1 = 0;
  v1 = Allocate(dds3Basic_t);
  dds3Basic_t___ctor(v1);
  p3 = v1;
  v2 = Allocate(dds3Basic_t);
  dds3Basic_t___ctor(v2);
  v17 = v2;
  IntPara = scrGetIntPara(0);
  eff = evtSearchBasic(7, IntPara);
  if (!eff)
  {
    v14 = Empty_string_();
    v15 = &"EFFMG1_POS mg1 ID error!\n";
    goto LABEL_22;
  }
  v10 = scrGetIntPara(1);
  v11 = evtSearchBasic(7, v10);
  p1 = v11;
  v12 = scrGetIntPara(2);
  p2 = evtSearchBasic(7, v12);
  if (!p2 || !v11)
  {
    v14 = Empty_string_();
    v15 = &"EFFMG1_POS point ID not found!\n";
    goto LABEL_22;
  }
  if (!dds3EffectObjectSetMG12Pos(&eff, &p1, &p2, &p3, &v17))
  {
    v14 = Empty_string_();
    v15 = &"EFFMG1_POS set error!\n";
LABEL_22:
    dds3Printf(*v15, v14);
  }
  return 1;
}

// 0x1358080
s32 evtCommand_EFFMG2_BE(void) {
  s32 IntPara;
  s32 v4;
  System_Byte_array *ResorceData;
  u32 serialID;
  s32 v9;
  System_Object_array *v11;
  s64 *v12;
  s64 *v13;
  s32 v17;
  dds3Basic_t_o *basic;

  basic = 0;
  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  ResorceData = evtGetResorceData(IntPara, v4);
  if (!ResorceData)
  {
    v11 = NewSpecific(object, 1u);
    v17 = scrGetIntPara(1);
    v12 = sub_8D3950(s32, &v17);
    v13 = v12;
    v11->m_Items[0] = v13;
    dds3Printf("EFFMG2_BE not fount RID = %d\n", v11);
    goto LABEL_26;
  }
  basic = dds3AddMG12EffectObjectBasic2(2, &ResorceData->obj);
  if (!basic)
  {
LABEL_26:
    v9 = 0;
    goto LABEL_27;
  }
  dds3EffectObjectBasicStatOn(&basic, 1u);
  serialID = basic->serialID;
  v9 = serialID;
LABEL_27:
  scrSetIntReturnValue(v9);
  return 1;
}

// 0x1357f30
s32 evtCommand_EFFMG2_LOAD(void) {
  System_String_o *StrPara;
  u32 serialID;
  s32 v6;
  Il2CppObject *v8;
  dds3Basic_t_o *basic;

  basic = 0;
  StrPara = scrGetStrPara(0);
  basic = dds3AddMG12EffectObjectBasic(2, StrPara);
  if (basic)
  {
    dds3EffectObjectBasicStatOn(&basic, 1u);
    serialID = basic->serialID;
    v6 = serialID;
  }
  else
  {
    Write("スクリプトコマンドEFFMG2_LOAD()で対象ファイル\n", 0);
    v8 = scrGetStrPara(0);
    Write_2930400("{0}が見つかりません!!\n", v8);
    v6 = 0;
  }
  scrSetIntReturnValue(v6);
  return 1;
}

// 0x1358fb0
s32 evtCommand_EFFMG2_POS(void) {
  s32 IntPara;
  s32 v8;
  dds3Basic_t_o *v9;
  s32 v10;
  dds3Basic_t_o *v12;
  s32 v13;
  dds3Basic_t_o *v15;
  s32 v16;
  System_Object_array *v18;
  s64 *v19;
  dds3Basic_t_o *v21;
  dds3Basic_t_o *p3;
  dds3Basic_t_o *p2;
  dds3Basic_t_o *p1;
  dds3Basic_t_o *eff;

  eff = 0;
  p2 = 0;
  p1 = 0;
  p3 = 0;
  v21 = 0;
  IntPara = scrGetIntPara(0);
  eff = evtSearchBasic(7, IntPara);
  if (!eff)
  {
    v18 = Empty_string_();
    v19 = &"EFFMG2_POS mg2 ID error!\n";
    goto LABEL_24;
  }
  v8 = scrGetIntPara(1);
  v9 = evtSearchBasic(7, v8);
  p1 = v9;
  v10 = scrGetIntPara(2);
  v12 = evtSearchBasic(7, v10);
  p2 = v12;
  v13 = scrGetIntPara(3);
  v15 = evtSearchBasic(7, v13);
  p3 = v15;
  v16 = scrGetIntPara(4);
  v21 = evtSearchBasic(7, v16);
  if (!v21 || !v9 || !v12 || !v15)
  {
    v18 = Empty_string_();
    v19 = &"EFFMG2_POS point ID not found!\n";
    goto LABEL_24;
  }
  if (!dds3EffectObjectSetMG12Pos(&eff, &p1, &p2, &p3, &v21))
  {
    v18 = Empty_string_();
    v19 = &"EFFMG2_POS set error!\n";
LABEL_24:
    dds3Printf(*v19, v18);
  }
  return 1;
}

// 0x1358280
s32 evtCommand_EFFMG2_PRESET(void) {
  s32 IntPara;
  dds3Basic_t_o *eff;

  eff = 0;
  IntPara = scrGetIntPara(0);
  eff = evtSearchBasic(7, IntPara);
  if (eff)
    dds3EffectObjectPresetMG12(&eff);
  return 1;
}

// 0x135a7d0
s32 evtCommand_EXIT_EVENT(void) {
  System_Object_array *v2;
  System_Object_array *v5;

  v2 = Empty_string_();
  Log("EXIT_EVENT START", v2, 0);
  fldSetCharClr();
  UnloadALL(0);
  v5 = Empty_string_();
  Log("EXIT_EVENT END", v5, 0);
  dds3AdminiExitSequence();
  return 1;
}

// 0x1360920
s32 evtCommand_FADEOUT_E(void) {
  s32 IntPara;
  s32 v3;
  s32 v4;
  s32 v6;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  evtFadeOutBgm(IntPara, v3);
  v4 = scrGetIntPara(0);
  v6 = scrGetIntPara(1);
  evtUpdateEx_BGM_FADEOUT_E_After(v4, v6);
  return 1;
}

// 0x135b5d0
s32 evtCommand_FIELD_ANIME_START(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  evtStageAnimeControl(0, IntPara);
  return 1;
}

// 0x135b670
s32 evtCommand_FIELD_ANIME_STOP(void) {
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  evtStageAnimeControl(1, IntPara);
  return 1;
}

// 0x135b2b0
s32 evtCommand_FIELD_BE(void) {
  System_Object_array *v2;
  UnityEngine_GameObject_o *v3;
  Il2CppClass *klass;
  s32 IntPara;
  s32 v9;
  s32 result;
  System_Object_array *v12;

  v2 = Empty_string_();
  Log("FIELD_BE start\n", v2, 0);
  v3 = Find("kernel", 0);
  klass = GetComponent_object_(v3)[14].klass;
  if (op_Inequality(klass, 0, 0) && !get_activeInHierarchy(klass))
    SetActive(klass, 1, 0);
  IntPara = scrGetIntPara(0);
  v9 = scrGetIntPara(1);
  result = evtRegistBEField(IntPara, v9);
  if (result)
  {
    v12 = Empty_string_();
    Log("FIELD_BE end\n", v12, 0);
    return 1;
  }
  return result;
}

// 0x135b710
s32 evtCommand_FIELD_CLS(void) {
  System_Object_array *v5;
  System_Object_array *v6;

  evtFreeAllUnit();
  do
  {
    {
      if (sdfDelayedResrcCheck() != 1)
        goto LABEL_12;
    }
  }
  while (sdfDelayedResrcCheck() == 1);
LABEL_12:
  evtFreeStage();
  do
  {
    {
      if (sdfDelayedResrcCheck() != 1)
        goto LABEL_21;
    }
  }
  while (sdfDelayedResrcCheck() == 1);
LABEL_21:
  else if (PlayEventNo == 800)
  {
    goto LABEL_28;
  }
  SetDrawFlag(0x2000000u, 1u);
LABEL_28:
  v5 = Empty_string_();
  Log("event stage shutdown !!\n", v5, 0);
  v6 = Empty_string_();
  dds3Printf("field shutdown.\n", v6);
  return 1;
}

// 0x135b900
s32 evtCommand_FIELD_CLS_STOP(void) {
  System_Object_array *v5;

  evtFreeAllUnit();
  DetachModelAll();
  do
  {
    {
      if (sdfDelayedResrcCheck() != 1)
        goto LABEL_15;
    }
  }
  while (sdfDelayedResrcCheck() == 1);
LABEL_15:
  evtFreeStage();
  do
  {
    {
      if (sdfDelayedResrcCheck() != 1)
        goto LABEL_24;
    }
  }
  while (sdfDelayedResrcCheck() == 1);
LABEL_24:
  else if (PlayEventNo != 672)
  {
    goto LABEL_31;
  }
  SetDrawFlag(0x2000000u, 1u);
LABEL_31:
  Write("event stage shutdown2 !!\n", 0);
  v5 = Empty_string_();
  dds3Printf("field shutdown2.\n", v5);
  return 1;
}

// 0x135b470
s32 evtCommand_FIELD_DSP(void) {
  s32 IntPara;
  s32 v4;
  s32 v5;
  s32 v8;
  s32 v10;
  dds3Basic_t_o *scene;

  scene = 0;
  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  v5 = v4 + (IntPara << 16);
  scene = dds3GetControlScene();
  if (dds3GetMapNo(&scene) != v5)
  {
    v8 = scrGetIntPara(0);
    v10 = scrGetIntPara(1);
    evtLoadArea(v8, v10);
  }
  return 1;
}

// 0x13615b0
s32 evtCommand_FRAMEMODE_OFF(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *UnitHandle;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  IntPara = scrGetIntPara(0);
  UnitHandle = evtGetUnitHandle(IntPara);
  if (UnitHandle)
LABEL_9:
    UnitHandle->modeflg &= ~1u;
  return 1;
}

// 0x13614d0
s32 evtCommand_FRAMEMODE_ON(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *UnitHandle;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  IntPara = scrGetIntPara(0);
  UnitHandle = evtGetUnitHandle(IntPara);
  if (UnitHandle)
LABEL_9:
    UnitHandle->modeflg |= 1u;
  return 1;
}

// 0x1361830
s32 evtCommand_GET_MACHINE(void) {
  scrSetIntReturnValue(1);
  return 1;
}

// 0x135d4c0
s32 evtCommand_GET_MOON(void) {
  s32 AgeOfMoon;

  AgeOfMoon = evtGetAgeOfMoon();
  scrSetIntReturnValue(AgeOfMoon);
  return 1;
}

// 0x135d560
s32 evtCommand_GET_MOON16(void) {
  s32 AgeOfMoon16;

  AgeOfMoon16 = evtGetAgeOfMoon16();
  scrSetIntReturnValue(AgeOfMoon16);
  return 1;
}

// 0x1361690
s32 evtCommand_GET_MSGTRG(void) {
  s32 MSGTRG;
  System_Object_array *v6;

  MSGTRG = 0;
  if (scrGetIntPara(0) != 723)
  {
LABEL_24:
      goto LABEL_27;
    goto LABEL_25;
  }
  if (!IsDLC())
    goto LABEL_23;
LABEL_10:
  if (MSGTRG != 1)
    goto LABEL_24;
  v6 = Empty_string_();
  Log("START MSG", v6, 0);
  MSGTRG = 1;
  MSGTRG = 0;
  {
LABEL_25:
  }
LABEL_27:
  scrSetIntReturnValue(MSGTRG);
  return 1;
}

// 0x13612a0
s32 evtCommand_GET_RESUME(void) {
  s32 IntPara;
  s32 KagPuzNow;

  IntPara = scrGetIntPara(0);
  if (IntPara == 1)
  {
      goto LABEL_18;
LABEL_12:
LABEL_18:
    scrSetIntReturnValue(KagPuzNow);
    return 1;
  }
  if (!IntPara)
  {
    KagPuzNow = KagPuzPos;
      goto LABEL_18;
    goto LABEL_12;
  }
  return 1;
}

// 0x1354a30
s32 evtCommand_KUTI(void) {
  u64 *v1;
  s32 IntPara;
  s32 v6;
  s32 v8;
  evtUnitHandle_t_o *v10;
  s32 MessageHandle;
  s32 v13;
  u64 *v14;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  if (h)
  {
    v6 = scrGetIntPara(1);
    v8 = scrGetIntPara(2);
    evtSetUnitKutiMotion(&h, v6, v8);
    evtRunUnitKutiMotion(&h);
    v10 = h;
    KutiModel = v10;
    MessageHandle = scrGetMessageHandle();
    if ((MessageHandle & 0x80000000) == 0)
    {
      v13 = MessageHandle;
      v14 = Allocate(instanceMes_tag_func_kutiDelegate);
      _ctor(v14, 0, Method_evtCommand_KutiFunction__, 0);
      itfMesMngSetKutiCallback(v13, v14);
    }
  }
  return 1;
}

// 0x1354860
s32 evtCommand_KUTISET(void) {
  u64 *v1;
  s32 IntPara;
  s32 v6;
  s32 v8;
  evtUnitHandle_t_o *v10;
  s32 MessageHandle;
  s32 v13;
  u64 *v14;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  if (h)
  {
    v6 = scrGetIntPara(1);
    v8 = scrGetIntPara(2);
    evtSetUnitKutiMotion(&h, v6, v8);
    v10 = h;
    KutiModel = v10;
    MessageHandle = scrGetMessageHandle();
    if ((MessageHandle & 0x80000000) == 0)
    {
      v13 = MessageHandle;
      v14 = Allocate(instanceMes_tag_func_kutiDelegate);
      _ctor(v14, 0, Method_evtCommand_KutiFunction__, 0);
      itfMesMngSetKutiCallback(v13, v14);
    }
  }
  return 1;
}

// 0x135f150
s32 evtCommand_LIGHT_PATH_MOVE(void) {
  s32 IntPara;
  dds3Basic_t_o *v5;
  s32 v6;
  dds3Basic_t_o *v9;
  System_Object_array *v12;

  IntPara = scrGetIntPara(0);
  v5 = evtSearchBasic(9, IntPara);
  v6 = scrGetIntPara(1);
  v9 = evtSearchBasic(16, v6);
  if (evtPathLinkAndMake(v9, v5))
    return 1;
  Write("LIGHT_PATH_MOVE error!\n", 0);
  v12 = Empty_string_();
  dds3Printf("error: LIGHT_PATH_MOVE.\n", v12);
  return 1;
}

// 0x135f2b0
s32 evtCommand_LIGHT_PATH_WAIT(void) {
  s32 IntPara;
  dds3Basic_t_o *v6;

  IntPara = scrGetIntPara(0);
  v6 = evtSearchBasic(9, IntPara);
  return (evtCheckPathStat(v6) + 1) <= 1;
}

// 0x135d6a0
s32 evtCommand_LOAD_BE(void) {
  u64 *v1;
  u64 *v2;
  s32 IntPara;
  scrProcessWork_s_o *ScriptHandle;
  scrProcessWork_s_o *v7;
  u64 *v9;
  System_String_o *v10;
  System_Object_array *v12;
  u64 *v14;
  System_String_o *v15;
  System_Object_array *v17;
  s32 v20;
  dds3ProcessID_t_o *target;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  target = v2;
  IntPara = scrGetIntPara(0);
  ScriptHandle = scrGetScriptHandle();
  if (!ScriptHandle)
    return 1;
  v7 = ScriptHandle;
  target = evtSearchEventPack(IntPara);
  if (target)
  {
    if (evtGetEventPackStat(IntPara) == 2)
    {
      v20 = IntPara;
      v9 = sub_8D3950(s32, &v20);
      v10 = Format("BE ok! ({0})\n", v9, 0);
      v12 = Empty_string_();
      Log(v10, v12, 0);
      return 1;
    }
  }
  else
  {
    v20 = IntPara;
    v14 = sub_8D3950(s32, &v20);
    v15 = Format("load BE ({0})..\n", v14, 0);
    v17 = Empty_string_();
    Log(v15, v17, 0);
    target = evtLoadEventPack(IntPara);
    dds3LinkProcess(&v7->ProcessID, &target);
  }
  return 0;
}

// 0x1360720
s32 evtCommand_LOAD_SOUND_E(void) {
  s32 v3;
  s32 result;
  s32 IntPara;

  if (!scrGetCommandTimer())
  {
    IntPara = scrGetIntPara(0);
    evtLoadSound(IntPara);
    return 0;
  }
  v3 = scrGetIntPara(0);
  result = evtCheckSoundLoad(v3);
  if (result != 1)
    return 0;
  return result;
}

// 0x13565a0
s32 evtCommand_MODEL_A(void) {
  u64 *v1;
  s32 IntPara;
  f32 FloatPara;
  u32 v6;
  s32 v7;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  SDF_VU0__LOADIDENTITYVECTOR();
  FloatPara = scrGetFloatPara(2);
  SDF_VU0__SETVECTOR_W(FloatPara);
  v6 = SDF_VU0__dds3ColorFtoI(128.0);
  v7 = scrGetIntPara(1);
  evtSetUnitColorA(&h, v7, v6);
  return 1;
}

// 0x13534d0
s32 evtCommand_MODEL_BE(void) {
  u64 *v1;
  u64 *v2;
  u64 *v3;
  s32 IntPara;
  s32 v8;
  s32 v9;
  s32 v11;
  System_Object_array *v13;
  s64 *v14;
  s64 *v15;
  u64 *v18;
  System_String_o *v19;
  System_Object_array *v21;
  s32 v23;
  s32 v25;
  s32 v28;
  s32 v30;
  dds3ProcessID_t_o *parent;
  dds3ProcessID_t_o *target;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  target = v2;
  v3 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v3);
  parent = v3;
  if (!scrGetScriptHandle())
    return 1;
LABEL_6:
  IntPara = scrGetIntPara(0);
  v8 = scrGetIntPara(1);
  v9 = evtRegistBEUnit(IntPara, v8);
  if (v9 != -2)
  {
    v11 = v9;
    if (v9 == -1)
    {
      v13 = NewSpecific(object, 1u);
      v30 = scrGetIntPara(1);
      v14 = sub_8D3950(s32, &v30);
      v15 = v14;
      v13->m_Items[0] = v15;
      dds3Printf("MODEL_BE not fount RID = %d!\n", v13);
    }
    else
    {
      v23 = scrGetIntPara(0);
      v25 = scrGetIntPara(1);
      target = evtInitMotionSeProcess(v11, v23, v25);
      if (target)
      {
        v28 = scrGetIntPara(0);
        parent = evtSearchEventPack(v28);
        dds3LinkProcess(&parent, &target);
      }
      scrSetIntReturnValue(v11);
    }
    return 1;
  }
  v30 = -2;
  v18 = sub_8D3950(s32, &v30);
  v19 = Concat("LoadWait : ", v18);
  v21 = Empty_string_();
  Log(v19, v21, 0);
  return 0;
}

// 0x1354f30
s32 evtCommand_MODEL_CLS(void) {
  s32 IntPara;
  dds3Basic_t_o *v8;
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *aBasic;

  aBasic = 0;
  ActiveScene = 0;
  ActiveScene = dds3GetActiveScene();
  IntPara = scrGetIntPara(0);
  aBasic = dds3SearchSceneBasic(&ActiveScene, IntPara, 5u);
  if (aBasic)
  {
    fldNpcShadow_Del(&aBasic);
    dds3DeleteSceneBasicData(&aBasic);
    v8 = aBasic;
    DetachModel(v8, 1);
  }
  return 1;
}

// 0x13550a0
s32 evtCommand_MODEL_CLS2(void) {
  s32 IntPara;
  dds3Basic_t_o *v8;
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *aBasic;

  aBasic = 0;
  ActiveScene = 0;
  ActiveScene = dds3GetActiveScene();
  IntPara = scrGetIntPara(0);
  aBasic = dds3SearchSceneBasic(&ActiveScene, IntPara, 5u);
  if (aBasic)
  {
    fldNpcShadow_Del(&aBasic);
    dds3DeleteSceneBasicData(&aBasic);
    v8 = aBasic;
    DetachModel(v8, 0);
  }
  return 1;
}

// 0x1353410
s32 evtCommand_MODEL_DSP(void) {
  s32 IntPara;
  s32 v4;
  s32 Unit;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  Unit = evtLoadUnit(IntPara, v4);
  scrSetIntReturnValue(Unit);
  return 1;
}

// 0x1354650
s32 evtCommand_MODEL_EXMOTION(void) {
  u64 *v1;
  s32 IntPara;
  s32 v6;
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v11;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  if (h)
  {
    v6 = scrGetIntPara(1);
    v7 = scrGetIntPara(2);
    v8 = scrGetIntPara(3);
    v9 = scrGetIntPara(4);
    v11 = scrGetIntPara(5);
    evtSetUnitExMotion(&h, v6, v7, v8, v9, v11);
  }
  return 1;
}

// 0x1354d20
s32 evtCommand_MODEL_EXWAIT(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *UnitHandle;
  evtUnitHandle_t_o *v7;
  struct System_Byte_array *ExFlags;
  s32 v9;
  dds3ModelHandle_t_o **p_Model;
  s32 v15;
  System_Object_array *v17;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  IntPara = scrGetIntPara(0);
  UnitHandle = evtGetUnitHandle(IntPara);
  if (!UnitHandle)
    return 1;
LABEL_9:
  v7 = UnitHandle;
  ExFlags = UnitHandle->ExFlags;
  v9 = scrGetIntPara(1);
  if ((ExFlags->m_Items[v9] & 1) == 0)
    return 1;
  p_Model = &v7->Model;
  v15 = scrGetIntPara(1);
  if (mdlChkMotionEndEx(p_Model, v15))
    return 1;
  v17 = Empty_string_();
  Log("MODEL_EXWAIT : ", v17, 0);
  return 0;
}

// 0x13561b0
s32 evtCommand_MODEL_LIGHT_DIR(void) {
  u64 *v1;
  s32 IntPara;
  f32 v6;
  f32 v7;
  f32 v9;
  f32 v10;
  f32 v12;
  f32 v13;
  s32 v16;
  System_Object_array *v18;
  UnityEngine_Vector4_o v19;
  evtUnitHandle_t_o *h;

  *&v19.x = 0;
  *&v19.z = 0;
  sub_854690(&v19.x, 0.0, 0.0, 0.0, 0.0);
  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  scrGetFloatPara(2);
  sub_854930(&v19, 0);
  scrGetFloatPara(3);
  sub_854930(&v19, 1u);
  scrGetFloatPara(4);
  sub_854930(&v19, 2u);
  sub_854710(&v19, 0);
  v7 = v6;
  if (sdfFabs(v7) > 0.01)
    goto LABEL_21;
  sub_854710(&v19, 1u);
  v10 = v9;
  if (sdfFabs(v10) > 0.01)
    goto LABEL_21;
  sub_854710(&v19, 2u);
  v13 = v12;
  if (sdfFabs(v13) <= 0.01)
  {
    v18 = Empty_string_();
    dds3Printf("WARNING: MODEL_LIGHT_DIR length zero\n", v18);
  }
  else
  {
LABEL_21:
    SDF_VU0__LOADVECTOR(v19);
    v16 = scrGetIntPara(1);
    evtSetUnitLightDir(&h, v16);
  }
  return 1;
}

// 0x13566b0
s32 evtCommand_MODEL_LIGHT_LINK(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *UnitHandle;
  s32 v8;
  dds3Basic_t_o *v9;
  dds3Basic_t_o *v10;
  System_String_array *v11;
  s64 *name;
  s64 *v16;
  System_String_o *v19;
  System_Object_array *v21;
  s32 v24;
  System_String_o *v26;
  evtUnitHandle_t_o *v33;
  dds3Basic_t_o *light;

  light = 0;
  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  v33 = v1;
  IntPara = scrGetIntPara(0);
  UnitHandle = evtGetUnitHandle(IntPara);
  v33 = UnitHandle;
  v8 = scrGetIntPara(2);
  v9 = evtSearchBasic(9, v8);
  light = v9;
  if (v9)
  {
    v10 = v9;
    v11 = NewSpecific(string, 5u);
    v11->m_Items[0] = "モデルに配置ライトをリンクさせる : ";
    name = v10->name;
    v11->m_Items[1] = name;
    v11->m_Items[2] = "を";
    v16 = UnitHandle->Owner->name;
    v11->m_Items[3] = v16;
    v11->m_Items[4] = "に";
    v19 = Concat_5271600(v11);
    v21 = Empty_string_();
    Log(v19, v21, 0);
    v24 = scrGetIntPara(1);
    evtLinkLightObjectBasic(&v33, &light, v24);
    v26 = light->name;
    SetLight_From_evtCommand(v26);
  }
  return 1;
}

// 0x1355e60
s32 evtCommand_MODEL_LIGHT_OFF(void) {
  u64 *v1;
  s32 IntPara;
  s32 v5;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  v5 = scrGetIntPara(1);
  evtUnitLightOff(&h, v5);
  return 1;
}

// 0x1355d90
s32 evtCommand_MODEL_LIGHT_ON(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  evtUnitLightOn(&h);
  return 1;
}

// 0x1356010
s32 evtCommand_MODEL_LIGHT_RGB(void) {
  u64 *v1;
  s32 IntPara;
  f32 FloatPara;
  f32 v6;
  f32 v7;
  u32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  u32 v12;
  s32 v13;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  FloatPara = scrGetFloatPara(2);
  SDF_VU0__SETVECTOR_X(FloatPara);
  v6 = scrGetFloatPara(3);
  SDF_VU0__SETVECTOR_Y(v6);
  v7 = scrGetFloatPara(4);
  SDF_VU0__SETVECTOR_Z(v7);
  SDF_VU0__VECTOR_W_SET_ZERO();
  v8 = SDF_VU0__dds3ColorFtoI(128.0);
  v9 = scrGetFloatPara(5);
  SDF_VU0__SETVECTOR_X(v9);
  v10 = scrGetFloatPara(6);
  SDF_VU0__SETVECTOR_Y(v10);
  v11 = scrGetFloatPara(7);
  SDF_VU0__SETVECTOR_Z(v11);
  SDF_VU0__VECTOR_W_SET_ONE();
  v12 = SDF_VU0__dds3ColorFtoI(128.0);
  v13 = scrGetIntPara(1);
  evtSetUnitLightAndAmbient(&h, v13, v8, v12);
  return 1;
}

// 0x1356ac0
s32 evtCommand_MODEL_LIGHT_UNLINK(void) {
  u64 *v1;
  s32 IntPara;
  s32 v5;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  v5 = scrGetIntPara(1);
  evtUnlinkLightObjectBasic(&h, v5);
  return 1;
}

// 0x1355f40
s32 evtCommand_MODEL_LIGHT_WAIT(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  return evtUnitLightAnimeStat(&h) != 1;
}

// 0x1354360
s32 evtCommand_MODEL_MOTION(void) {
  u64 *v1;
  s32 IntPara;
  s32 v6;
  s32 v7;
  s32 v9;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  if (h)
  {
    v6 = scrGetIntPara(1);
    v7 = scrGetIntPara(2);
    v9 = scrGetIntPara(3);
    evtSetUnitMotion(&h, v6, v7, v9, 0);
    Write("※注意:MODEL_MOTION()このコマンドは今後使用禁止になります。\n", 0);
  }
  return 1;
}

// 0x13544f0
s32 evtCommand_MODEL_MOTION2(void) {
  u64 *v1;
  s32 IntPara;
  s32 v6;
  s32 v7;
  s32 v8;
  s32 v10;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  if (h)
  {
    v6 = scrGetIntPara(1);
    v7 = scrGetIntPara(2);
    v8 = scrGetIntPara(3);
    v10 = scrGetIntPara(4);
    evtSetUnitMotion(&h, v6, v7, v8, v10);
  }
  return 1;
}

// 0x1355210
s32 evtCommand_MODEL_MOVE(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *UnitHandle;
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v11;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  UnitHandle = evtGetUnitHandle(IntPara);
  h = UnitHandle;
  if (UnitHandle)
  {
    UnitHandle->Frame = 0;
    v7 = scrGetIntPara(2);
    v8 = scrGetIntPara(1);
    v9 = scrGetIntPara(3);
    v11 = scrGetIntPara(4);
    evtSetUnitMove2(&h, v7, v8, -1, v9, v11, 0, 0);
  }
  return 1;
}

// 0x1355390
s32 evtCommand_MODEL_MOVE2(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *UnitHandle;
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v13;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  UnitHandle = evtGetUnitHandle(IntPara);
  h = UnitHandle;
  if (UnitHandle)
  {
    UnitHandle->Frame = 0;
    v7 = scrGetIntPara(1);
    v8 = scrGetIntPara(5);
    v9 = scrGetIntPara(6);
    v10 = scrGetIntPara(2);
    v11 = scrGetIntPara(4);
    v13 = scrGetIntPara(3);
    evtSetUnitMove3(&h, v7, v8, v9, v10, v11, v13);
  }
  return 1;
}

// 0x1355850
s32 evtCommand_MODEL_MOVE_MOT(void) {
  u64 *v1;
  s32 IntPara;
  s32 v7;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  if (h)
  {
    v7 = scrGetIntPara(1);
    evtSetUnitMotion(&h, v7, 5, 7, 1);
    Write("※注意:MODEL_MOVE_MOT()このコマンドは今後使用禁止になります。\n", 0);
  }
  return 1;
}

// 0x1355c40
s32 evtCommand_MODEL_OFF(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *UnitHandle;
  evtUnitHandle_t_o *v6;
  dds3ModelHandle_t_o *Model;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  UnitHandle = evtGetUnitHandle(IntPara);
  h = UnitHandle;
  if (UnitHandle)
  {
    v6 = UnitHandle;
    if (op_Equality(UnitHandle->Owner->name, "PLAYER_UNIT", 0))
    {
      PlayerUnitDisp(&h, 0);
    }
    else
    {
      Model = v6->Model;
      mdlHide(Model);
    }
  }
  return 1;
}

// 0x1355af0
s32 evtCommand_MODEL_ON(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *UnitHandle;
  evtUnitHandle_t_o *v6;
  dds3ModelHandle_t_o *Model;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  UnitHandle = evtGetUnitHandle(IntPara);
  h = UnitHandle;
  if (UnitHandle)
  {
    v6 = UnitHandle;
    if (op_Equality(UnitHandle->Owner->name, "PLAYER_UNIT", 0))
    {
      PlayerUnitDisp(&h, 1);
    }
    else
    {
      Model = v6->Model;
      mdlShow(Model);
    }
  }
  return 1;
}

// 0x1353320
s32 evtCommand_MODEL_PLAYER(void) {
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *ActiveUnitSceneBasic;
  s32 serialID;
  s32 v7;

  ActiveScene = dds3GetActiveScene();
  ActiveUnitSceneBasic = dds3GetActiveUnitSceneBasic(ActiveScene);
  if (ActiveUnitSceneBasic)
  {
    serialID = ActiveUnitSceneBasic->serialID;
    v7 = serialID;
  }
  else
  {
    v7 = -1;
  }
  scrSetIntReturnValue(v7);
  return 1;
}

// 0x1353880
s32 evtCommand_MODEL_POS(void) {
  s32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  evtSetUnitPos(IntPara, v4);
  return 1;
}

// 0x1353c60
s32 evtCommand_MODEL_POS_XYZ(void) {
  s32 IntPara;
  f32 FloatPara;
  f32 v7;
  f32 v8;
  char v10;
  s64 v11;
  s64 v12;
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *pBasic;
  s64 v16;
  s64 v17;
  UnityEngine_Vector4_o v18;

  v16 = 0;
  v17 = 0;
  ActiveScene = 0;
  pBasic = 0;
  sub_854690(&v16, 0.0, 0.0, 0.0, 0.0);
  ActiveScene = dds3GetActiveScene();
  IntPara = scrGetIntPara(0);
  pBasic = dds3SearchSceneBasic(&ActiveScene, IntPara, 5u);
  if (pBasic)
  {
    FloatPara = scrGetFloatPara(1);
    v7 = scrGetFloatPara(2);
    v8 = scrGetFloatPara(3);
    sub_854930(&v16, 0);
    sub_854930(&v16, 1u);
    sub_854930(&v16, 2u);
    v10 = 0;
    if (v7 == 65536.0 && v8 == 65536.0)
    {
      sub_854710(&v16, 0);
      sub_854930(&v16, 0);
      v10 = 1;
    }
    if (FloatPara == 65536.0 && v8 == 65536.0)
    {
      v10 = 1;
      sub_854710(&v16, 1u);
      sub_854930(&v16, 1u);
    }
    if (FloatPara == 65536.0 && v7 == 65536.0)
    {
      sub_854710(&v16, 2u);
    }
    else
    {
      if ((v10 & 1) != 0)
        goto LABEL_31;
      scrGetFloatPara(1);
      sub_854930(&v16, 0);
      scrGetFloatPara(2);
      sub_854930(&v16, 1u);
      scrGetFloatPara(3);
    }
    sub_854930(&v16, 2u);
LABEL_31:
    v11 = v16;
    v12 = v17;
    *&v18.x = v11;
    *&v18.z = v12;
    dds3SetPosPoseSet(&pBasic, v18);
  }
  return 1;
}

// 0x1356460
s32 evtCommand_MODEL_RGB(void) {
  u64 *v1;
  s32 IntPara;
  f32 FloatPara;
  f32 v6;
  f32 v7;
  u32 v8;
  s32 v9;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  FloatPara = scrGetFloatPara(2);
  SDF_VU0__SETVECTOR_X(FloatPara);
  v6 = scrGetFloatPara(3);
  SDF_VU0__SETVECTOR_Y(v6);
  v7 = scrGetFloatPara(4);
  SDF_VU0__SETVECTOR_Z(v7);
  SDF_VU0__VECTOR_W_SET_ZERO();
  v8 = SDF_VU0__dds3ColorFtoI(128.0);
  v9 = scrGetIntPara(1);
  evtSetUnitColorRGB(&h, v9, v8);
  return 1;
}

// 0x13559b0
s32 evtCommand_MODEL_ROT(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *UnitHandle;
  s32 v7;
  s32 v9;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  UnitHandle = evtGetUnitHandle(IntPara);
  h = UnitHandle;
  if (UnitHandle)
  {
    UnitHandle->Frame = 0;
    v7 = scrGetIntPara(1);
    v9 = scrGetIntPara(2);
    evtSetUnitRot2(&h, v7, v9);
  }
  return 1;
}

// 0x1353f70
s32 evtCommand_MODEL_ROT_XYZ(void) {
  s32 IntPara;
  f32 FloatPara;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *pBasic;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v22;

  *&p.x = 0;
  *&p.z = 0;
  ActiveScene = 0;
  pBasic = 0;
  sub_854690(&p.x, 0.0, 0.0, 0.0, 1.0);
  ActiveScene = dds3GetActiveScene();
  IntPara = scrGetIntPara(0);
  pBasic = dds3SearchSceneBasic(&ActiveScene, IntPara, 5u);
  if (pBasic)
  {
    FloatPara = scrGetFloatPara(1);
    v8 = SDF_DEGtoRAD(FloatPara);
    v9 = scrGetFloatPara(2);
    v10 = SDF_DEGtoRAD(v9);
    FromEuler(v8, v10, 0.0);
    SDF_VU0__COPYVECTOR_A_TO_B();
    v11 = scrGetFloatPara(3);
    v12 = SDF_DEGtoRAD(v11);
    FromEuler(0.0, 0.0, v12);
    Mult();
    SDF_VU0__STOREVECTOR(&p);
    x = p.x;
    y = p.y;
    z = p.z;
    w = p.w;
    v22.x = x;
    v22.y = y;
    v22.z = z;
    v22.w = w;
    dds3SetRotPoseSet(&pBasic, v22);
  }
  return 1;
}

// 0x1354190
s32 evtCommand_MODEL_SCL_XYZ(void) {
  s32 IntPara;
  s64 v7;
  s64 v8;
  dds3Basic_t_o *ActiveScene;
  dds3Basic_t_o *pBasic;
  s64 v12;
  s64 v13;
  UnityEngine_Vector4_o v14;

  v12 = 0;
  v13 = 0;
  ActiveScene = 0;
  pBasic = 0;
  sub_854690(&v12, 0.0, 0.0, 0.0, 1.0);
  ActiveScene = dds3GetActiveScene();
  IntPara = scrGetIntPara(0);
  pBasic = dds3SearchSceneBasic(&ActiveScene, IntPara, 5u);
  if (pBasic)
  {
    scrGetFloatPara(1);
    sub_854930(&v12, 0);
    scrGetFloatPara(2);
    sub_854930(&v12, 1u);
    scrGetFloatPara(3);
    sub_854930(&v12, 2u);
    v7 = v12;
    v8 = v13;
    *&v14.x = v7;
    *&v14.z = v8;
    dds3SetSclPoseSet(&pBasic, v14);
  }
  return 1;
}

// 0x1353b50
s32 evtCommand_MODEL_SHADOW_OFF(void) {
  s32 IntPara;
  dds3Basic_t_o *pBasic;
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = 0;
  pBasic = 0;
  pBasic = dds3GetActiveScene();
  IntPara = scrGetIntPara(0);
  pObjectBasic = dds3SearchSceneBasic(&pBasic, IntPara, 5u);
  if (pObjectBasic)
  {
    dds3ObjectBaseOffFlag(&pObjectBasic, 0x400u);
    dds3ObjectBaseOffFlag(&pObjectBasic, 0x200u);
  }
  return 1;
}

// 0x1353930
s32 evtCommand_MODEL_SHADOW_ON(void) {
  s32 IntPara;
  dds3Basic_t_o *pBasic;
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = 0;
  pBasic = 0;
  pBasic = dds3GetActiveScene();
  IntPara = scrGetIntPara(0);
  pObjectBasic = dds3SearchSceneBasic(&pBasic, IntPara, 5u);
  if (pObjectBasic)
  {
    dds3ObjectBaseOnFlag(&pObjectBasic, 0x400u, 0);
    dds3ObjectBaseOffFlag(&pObjectBasic, 0x200u);
  }
  return 1;
}

// 0x1353a40
s32 evtCommand_MODEL_SHADOW_ON2(void) {
  s32 IntPara;
  dds3Basic_t_o *pBasic;
  dds3Basic_t_o *pObjectBasic;

  pObjectBasic = 0;
  pBasic = 0;
  pBasic = dds3GetActiveScene();
  IntPara = scrGetIntPara(0);
  pObjectBasic = dds3SearchSceneBasic(&pBasic, IntPara, 5u);
  if (pObjectBasic)
  {
    dds3ObjectBaseOffFlag(&pObjectBasic, 0x400u);
    dds3ObjectBaseOnFlag(&pObjectBasic, 0x200u, 0);
  }
  return 1;
}

// 0x1354c10
s32 evtCommand_MODEL_WAIT(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *h;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  h = v1;
  IntPara = scrGetIntPara(0);
  h = evtGetUnitHandle(IntPara);
  if (!h)
    return 1;
  return evtCheckUnitWait(&h) == 1;
}

// 0x1355530
s32 evtCommand_MODEL_WAIT_EXMOT(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *UnitHandle;
  struct System_Int16_array *ExWaitMotion;
  s32 v8;
  s16 v9;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  IntPara = scrGetIntPara(0);
  UnitHandle = evtGetUnitHandle(IntPara);
  if (UnitHandle)
  {
    ExWaitMotion = UnitHandle->ExWaitMotion;
    v8 = scrGetIntPara(1);
    v9 = scrGetIntPara(2);
    ExWaitMotion->m_Items[v8] = v9;
  }
  return 1;
}

// 0x1355750
s32 evtCommand_MODEL_WAIT_HOKAN(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *UnitHandle;
  evtUnitHandle_t_o *v7;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  IntPara = scrGetIntPara(0);
  UnitHandle = evtGetUnitHandle(IntPara);
  if (UnitHandle)
  {
    v7 = UnitHandle;
    v7->WaitBefore = scrGetIntPara(1);
    v7->WaitSmooth = scrGetIntPara(2);
  }
  return 1;
}

// 0x1355660
s32 evtCommand_MODEL_WAIT_MOT(void) {
  u64 *v1;
  s32 IntPara;
  evtUnitHandle_t_o *UnitHandle;
  evtUnitHandle_t_o *v7;

  v1 = Allocate(evtUnitHandle_t);
  _ctor(v1, 0);
  IntPara = scrGetIntPara(0);
  UnitHandle = evtGetUnitHandle(IntPara);
  if (UnitHandle)
  {
    v7 = UnitHandle;
    v7->WaitMotion = scrGetIntPara(1);
  }
  return 1;
}

// 0x135d3e0
s32 evtCommand_MOON_START(void) {
  evtEnableMoonCalc();
  return 1;
}

// 0x135d450
s32 evtCommand_MOON_STOP(void) {
  evtDisableMoonCalc();
  return 1;
}

// 0x135ccb0
s32 evtCommand_OBJ_PATH_MOVE(void) {
  s32 IntPara;
  s32 v7;
  s32 v10;
  dds3ObjectBaseControlWorkData_t_o *ControlWorkData;
  struct dds3Basic_t_array *v12;
  dds3ObjectBaseControlWorkData_t_o *v13;
  dds3Basic_t_o *v15;
  struct dds3Basic_t_array *v16;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  s32 v23;
  System_String_o **v25;
  s32 v26;
  s32 v28;
  struct fldGlobalWork_t_o *v30;
  s32 v31;
  s32 fieldID;
  s32 v33;
  s32 v34;
  u64 *v36;
  u64 *v37;
  System_String_o **p_name;
  s32 HojiID;
  s32 v42;
  struct fldGlobalWork_t_o *fldGb;
  char *v46;
  s64 *v47;
  s32 v48;
  dds3Basic_t_o *pMoverBasic;
  dds3Basic_t_o *pPathBasic;
  dds3Basic_t_o *pBasic;
  dds3PathBasicControl_t_o *v52[3];
  dds3PathBasicControl_t_o *pControl;

  pControl = 0;
  pPathBasic = 0;
  pBasic = 0;
  pMoverBasic = 0;
  IntPara = scrGetIntPara(0);
  pBasic = evtSearchBasic(6, IntPara);
  if (pBasic)
    goto LABEL_79;
  v7 = scrGetIntPara(0);
  pBasic = fldGetMatter_From_ModelRangeID(v7);
  if (pBasic)
  {
LABEL_79:
    v10 = scrGetIntPara(1);
    pPathBasic = evtSearchBasic(16, v10);
    if (pPathBasic)
    {
      ControlWorkData = dds3MatterObjectBasicGetControlWorkData(&pBasic);
      v12 = ControlWorkData->pBasic;
      v13 = ControlWorkData;
      v15 = v12->m_Items[1];
      pMoverBasic = v15;
      if (!v15)
      {
        dds3ObjectBaseCreateMover(&pBasic);
        v16 = v13->pBasic;
        v15 = v16->m_Items[1];
        pMoverBasic = v15;
      }
      workdata = v15->workdata;
      klass = workdata->klass;
      if (workdata->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MoverBasicWorkData_t)
      {
        sub_8FC2C0(klass->_1.element_class, dds3MoverBasicWorkData_t, v52);
        if ((v52[0] & 1) != 0)
          v46 = v52[2];
        else
          v46 = v52 + 1;
        v47 = sub_8C4940(v46);
      }
      if (!workdata[2].monitor)
      {
        dds3MoverBasicSetPath(&pMoverBasic, &pPathBasic);
        dds3MoverBasicMakePath(&pMoverBasic);
      }
      pControl = dds3MoverBasicGetPathControl(&pMoverBasic);
      if (pControl)
      {
        v23 = scrGetIntPara(2);
        if (v23 == 1)
        {
          dds3PathBasicControlAlterMode(&pControl, 1u);
          p_name = &pPathBasic->name;
          if (pPathBasic->name)
          {
            HojiID = fldCommand_GetHojiID(p_name);
            if (HojiID >= 1)
            {
              v42 = HojiID;
              v31 = v42;
              fieldID = fldGb->fieldID;
              v33 = fldGb->areaID + 1;
              v34 = 0;
              goto LABEL_71;
            }
          }
        }
        else if (!v23)
        {
          dds3PathBasicControlAlterMode(&pControl, 0);
          v25 = &pPathBasic->name;
          if (pPathBasic->name)
          {
            v26 = fldCommand_GetHojiID(v25);
            if (v26 >= 1)
            {
              v28 = v26;
              v30 = fldGb;
              v31 = v28;
              fieldID = v30->fieldID;
              v33 = v30->areaID + 1;
              v34 = 1;
LABEL_71:
              fldGbSetGimic(fieldID, v33, v31, v34);
            }
          }
        }
      }
    }
  }
  else
  {
    LODWORD(v52[0]) = scrGetIntPara(0);
    v36 = sub_8D3950(s32, v52);
    Write_2930400("PARA0:{0:x8}\n", v36);
    v48 = scrGetIntPara(1);
    v37 = sub_8D3950(s32, &v48);
    Write_2930400("PARA1:{0:x8}\n", v37);
    Write("e OBJ_PATH_MOVE : obj==NULL\n", 0);
  }
  return 1;
}

// 0x135d1c0
s32 evtCommand_OBJ_PATH_WAIT(void) {
  s32 IntPara;
  dds3Basic_t_o *Matter_From_ModelRangeID;
  s32 v8;
  s32 v9;
  u64 *v11;
  u64 *v12;
  s32 v14;
  s32 v15;

  IntPara = scrGetIntPara(0);
  Matter_From_ModelRangeID = evtSearchBasic(6, IntPara);
  if (Matter_From_ModelRangeID)
    goto LABEL_31;
  v8 = scrGetIntPara(0);
  Matter_From_ModelRangeID = fldGetMatter_From_ModelRangeID(v8);
  if (Matter_From_ModelRangeID)
  {
LABEL_31:
    return (evtCheckPathStat(Matter_From_ModelRangeID) + 1) <= 1;
  }
  else
  {
    v15 = scrGetIntPara(0);
    v11 = sub_8D3950(s32, &v15);
    Write_2930400("PARA0:{0:x8}\n", v11);
    v9 = 1;
    v14 = scrGetIntPara(1);
    v12 = sub_8D3950(s32, &v14);
    Write_2930400("PARA1:{0:x8}\n", v12);
    Write("e OBJ_PATH_WAIT : obj==NULL\n", 0);
  }
  return v9;
}

// 0x135ec50
s32 evtCommand_PATH_DIR(void) {
  u32 v2;
  s32 IntPara;
  dds3Basic_t_o *v6;
  dds3Basic_t_o *Matter_From_ModelRangeID;
  s32 v9;
  s32 v11;
  System_String_o **p_name;
  struct System_String_o *name;
  s32 HojiID;
  s32 v17;
  s32 v19;
  struct fldGlobalWork_t_o *fldGb;
  s32 v22;
  s32 fieldID;
  s32 v24;
  s32 v25;
  struct fldGlobalWork_t_o *v26;

  v2 = 4;
  do
  {
    IntPara = scrGetIntPara(0);
    v6 = evtSearchBasic(v2++, IntPara);
    Matter_From_ModelRangeID = v6;
  }
  while (v2 <= 9 && !v6);
  if (v6)
    goto LABEL_47;
  v9 = scrGetIntPara(0);
  Matter_From_ModelRangeID = fldGetMatter_From_ModelRangeID(v9);
  if (Matter_From_ModelRangeID)
  {
LABEL_47:
    v11 = scrGetIntPara(1);
    evtPathDir(Matter_From_ModelRangeID, v11);
    name = Matter_From_ModelRangeID->name;
    p_name = &Matter_From_ModelRangeID->name;
    if (name)
    {
      HojiID = fldCommand_GetHojiID(p_name);
      if (HojiID >= 1)
      {
        v17 = HojiID;
        v19 = scrGetIntPara(1);
        if (v19)
        {
          v22 = v17;
          fieldID = fldGb->fieldID;
          v24 = fldGb->areaID + 1;
          v25 = 0;
        }
        else
        {
          v26 = fldGb;
          v22 = v17;
          fieldID = v26->fieldID;
          v24 = v26->areaID + 1;
          v25 = 1;
        }
        fldGbSetGimic(fieldID, v24, v22, v25);
      }
    }
  }
  return 1;
}

// 0x135f000
s32 evtCommand_PATH_LOOP_OFF(void) {
  u32 v2;
  s32 IntPara;
  dds3Basic_t_o *v6;
  dds3Basic_t_o *Matter_From_ModelRangeID;
  s32 v9;

  v2 = 4;
  do
  {
    IntPara = scrGetIntPara(0);
    v6 = evtSearchBasic(v2++, IntPara);
    Matter_From_ModelRangeID = v6;
  }
  while (v2 <= 9 && !v6);
  if (v6)
    goto LABEL_27;
  v9 = scrGetIntPara(0);
  Matter_From_ModelRangeID = fldGetMatter_From_ModelRangeID(v9);
  if (Matter_From_ModelRangeID)
  {
LABEL_27:
    evtPathLoop(Matter_From_ModelRangeID, 0);
  }
  return 1;
}

// 0x135eeb0
s32 evtCommand_PATH_LOOP_ON(void) {
  u32 v2;
  s32 IntPara;
  dds3Basic_t_o *v6;
  dds3Basic_t_o *Matter_From_ModelRangeID;
  s32 v9;

  v2 = 4;
  do
  {
    IntPara = scrGetIntPara(0);
    v6 = evtSearchBasic(v2++, IntPara);
    Matter_From_ModelRangeID = v6;
  }
  while (v2 <= 9 && !v6);
  if (v6)
    goto LABEL_27;
  v9 = scrGetIntPara(0);
  Matter_From_ModelRangeID = fldGetMatter_From_ModelRangeID(v9);
  if (Matter_From_ModelRangeID)
  {
LABEL_27:
    evtPathLoop(Matter_From_ModelRangeID, 1);
  }
  return 1;
}

// 0x135e9f0
s32 evtCommand_PATH_RATE(void) {
  u32 v2;
  s32 IntPara;
  dds3Basic_t_o *v6;
  dds3Basic_t_o *Matter_From_ModelRangeID;
  s32 v9;
  f32 FloatPara;
  System_String_o **p_name;
  struct System_String_o *name;
  s32 HojiID;
  s32 v17;
  f32 v19;
  struct fldGlobalWork_t_o *v21;
  s32 v22;
  s32 fieldID;
  s32 v24;
  s32 v25;
  struct fldGlobalWork_t_o *fldGb;

  v2 = 4;
  do
  {
    IntPara = scrGetIntPara(0);
    v6 = evtSearchBasic(v2++, IntPara);
    Matter_From_ModelRangeID = v6;
  }
  while (v2 <= 9 && !v6);
  if (v6)
    goto LABEL_47;
  v9 = scrGetIntPara(0);
  Matter_From_ModelRangeID = fldGetMatter_From_ModelRangeID(v9);
  if (Matter_From_ModelRangeID)
  {
LABEL_47:
    FloatPara = scrGetFloatPara(1);
    evtPathRate(Matter_From_ModelRangeID, FloatPara);
    name = Matter_From_ModelRangeID->name;
    p_name = &Matter_From_ModelRangeID->name;
    if (name)
    {
      HojiID = fldCommand_GetHojiID(p_name);
      if (HojiID >= 1)
      {
        v17 = HojiID;
        v19 = scrGetFloatPara(1);
        if (v19 <= 0.5)
        {
          v22 = v17;
          fieldID = fldGb->fieldID;
          v24 = fldGb->areaID + 1;
          v25 = 0;
        }
        else
        {
          v21 = fldGb;
          v22 = v17;
          fieldID = v21->fieldID;
          v24 = v21->areaID + 1;
          v25 = 1;
        }
        fldGbSetGimic(fieldID, v24, v22, v25);
      }
    }
  }
  return 1;
}

// 0x135e8a0
s32 evtCommand_PATH_START(void) {
  u32 v2;
  s32 IntPara;
  dds3Basic_t_o *v6;
  dds3Basic_t_o *Matter_From_ModelRangeID;
  s32 v9;

  v2 = 4;
  do
  {
    IntPara = scrGetIntPara(0);
    v6 = evtSearchBasic(v2++, IntPara);
    Matter_From_ModelRangeID = v6;
  }
  while (v2 <= 9 && !v6);
  if (v6)
    goto LABEL_27;
  v9 = scrGetIntPara(0);
  Matter_From_ModelRangeID = fldGetMatter_From_ModelRangeID(v9);
  if (Matter_From_ModelRangeID)
  {
LABEL_27:
    evtPathStart(Matter_From_ModelRangeID);
  }
  return 1;
}

// 0x135e6a0
s32 evtCommand_PATH_STOP(void) {
  s32 v4;
  dds3Basic_t_o *Matter_From_ModelRangeID;
  s32 v12;

  if (PlayEventNo != 618)
    goto LABEL_15;
LABEL_6:
  v4 = scrGetIntPara(0);
  Matter_From_ModelRangeID = evtSearchBasic(9, v4);
  if (Matter_From_ModelRangeID)
    goto LABEL_32;
LABEL_25:
  v12 = scrGetIntPara(0);
  Matter_From_ModelRangeID = fldGetMatter_From_ModelRangeID(v12);
  if (Matter_From_ModelRangeID)
  {
LABEL_32:
    evtPathStop(Matter_From_ModelRangeID);
  }
  return 1;
}

// 0x135de90
s32 evtCommand_PMV_LOAD(void) {
  u64 *v1;
  u64 *v2;
  s32 IntPara;
  s32 v5;
  System_Object_array *v6;
  s64 *v7;
  s64 *v8;
  s64 *v10;
  s64 *v12;
  scrProcessWork_s_o *ScriptHandle;
  struct dds3ProcessID_t_o *ProcessID;
  dds3ProcessID_t_o **p_ProcessID;
  s32 priority;
  System_Object_array *v19;
  s64 *v20;
  s64 *v21;
  s64 *v23;
  s64 *v25;
  s32 id;
  System_Object_array *v31;
  System_String_o *v32;
  System_String_array *v36;
  s32 v39;
  s32 v40;
  dds3ProcessID_t_o *target;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  target = v2;
  IntPara = scrGetIntPara(0);
  v5 = scrGetIntPara(1);
  v40 = IntPara;
  v6 = NewSpecific(object, 2u);
  v7 = sub_8D3950(s32, &v40);
  v8 = v7;
  v6->m_Items[0] = v8;
  v39 = v5;
  v10 = sub_8D3950(s32, &v39);
  v12 = v10;
  v6->m_Items[1] = v12;
  Log("PMV_LOAD({0:D},{1:D})\n", v6, 0);
  ScriptHandle = scrGetScriptHandle();
  if (ScriptHandle)
  {
    p_ProcessID = &ScriptHandle->ProcessID;
    ProcessID = ScriptHandle->ProcessID;
    if (ProcessID)
    {
      priority = ProcessID->priority;
      target = evtStartPolygonMovie2(priority, IntPara, v5);
      v19 = NewSpecific(object, 2u);
      v40 = IntPara;
      v20 = sub_8D3950(s32, &v40);
      v21 = v20;
      v19->m_Items[0] = v21;
      v39 = v5;
      v23 = sub_8D3950(s32, &v39);
      v25 = v23;
      v19->m_Items[1] = v25;
      Log("load PMV (%03d_%03d)..\n", v19, 0);
      dds3LinkProcess(p_ProcessID, &target);
      evtSetPolygonMovieFlag(target, 1u);
      id = target->id;
      scrSetIntReturnValue(id);
      v31 = Empty_string_();
      v32 = "PMV_LOAD() end\n";
    }
    else
    {
      v36 = Empty_string_();
      v32 = "※警告:PMV_LOAD()このコマンドはプロセス型スクリプトでのみ有効です。\n";
      v31 = v36;
    }
    Log(v32, v31, 0);
  }
  return 1;
}

// 0x135e400
s32 evtCommand_PMV_LOAD_END_WAIT(void) {
  u64 *v1;
  s32 IntPara;
  dds3ProcessID_t_o *v6;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  IntPara = scrGetIntPara(0);
  v6 = dds3SearchProcessID(IntPara);
  return evtCheckPolygonMovieFlag(v6, 8u) != 0;
}

// 0x135e4f0
s32 evtCommand_PMV_RUN(void) {
  u64 *v1;
  u64 *v2;
  scrProcessWork_s_o *ScriptHandle;
  struct dds3ProcessID_t_o *ProcessID;
  dds3ProcessID_t_o **p_ProcessID;
  s32 priority;
  s32 IntPara;
  s32 v11;
  dds3ProcessID_t_o *target;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  target = v2;
  ScriptHandle = scrGetScriptHandle();
  if (ScriptHandle)
  {
    p_ProcessID = &ScriptHandle->ProcessID;
    ProcessID = ScriptHandle->ProcessID;
    if (ProcessID)
    {
      priority = ProcessID->priority;
      IntPara = scrGetIntPara(0);
      v11 = scrGetIntPara(1);
      target = evtStartPolygonMovie2(priority, IntPara, v11);
      dds3LinkProcess(p_ProcessID, &target);
      scrSetIntReturnValue(target->id);
    }
    else
    {
      Write("※警告:PMV_RUN()このコマンドはプロセス型スクリプトでのみ有効です。\n", 0);
    }
  }
  return 1;
}

// 0x135e2c0
s32 evtCommand_PMV_RUN2(void) {
  u64 *v1;
  s32 IntPara;
  dds3ProcessID_t_o *v7;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  Write("PMV_RUN2()\n", 0);
  IntPara = scrGetIntPara(0);
  v7 = dds3SearchProcessID(IntPara);
  evtResetPolygonMovieFlag(v7, 1u);
  scrSetIntReturnValue(v7->id);
  Write("PMV_RUN2() end\n", 0);
  return 1;
}

// 0x1360dd0
s32 evtCommand_POINT_1ST(void) {
  s32 KotowariLank;

  KotowariLank = datGetKotowariLank(0);
  scrSetIntReturnValue(KotowariLank);
  return 1;
}

// 0x1360e70
s32 evtCommand_POINT_2ND(void) {
  s32 KotowariLank;

  KotowariLank = datGetKotowariLank(1);
  scrSetIntReturnValue(KotowariLank);
  return 1;
}

// 0x1360f10
s32 evtCommand_POINT_3RD(void) {
  s32 KotowariLank;

  KotowariLank = datGetKotowariLank(2);
  scrSetIntReturnValue(KotowariLank);
  return 1;
}

// 0x1360c50
s32 evtCommand_POINT_ADD(void) {
  s32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  datAddKotowariPoint(IntPara, v4);
  return 1;
}

// 0x1360d00
s32 evtCommand_POINT_GET(void) {
  struct System_Byte_array *kotowari;
  s32 IntPara;

  kotowari = DDS3_GBWK->kotowari;
  IntPara = scrGetIntPara(0);
  scrSetIntReturnValue(kotowari->m_Items[IntPara]);
  return 1;
}

// 0x135d930
s32 evtCommand_READ_BE(void) {
  u64 *v1;
  u64 *v2;
  s32 IntPara;
  scrProcessWork_s_o *ScriptHandle;
  scrProcessWork_s_o *v7;
  u64 *v8;
  System_String_o *v9;
  System_Object_array *v10;
  dds3ProcessID_t_o **p_ProcessID;
  s32 v15;
  dds3ProcessID_t_o *target;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  target = v2;
  IntPara = scrGetIntPara(0);
  ScriptHandle = scrGetScriptHandle();
  if (ScriptHandle)
  {
    v7 = ScriptHandle;
    target = evtSearchEventPack(IntPara);
    if (!target)
    {
      v15 = IntPara;
      v8 = sub_8D3950(s32, &v15);
      v9 = Format("read BE {0}..", v8, 0);
      v10 = Empty_string_();
      dds3Printf(v9, v10);
      target = evtLoadEventPack(IntPara);
      p_ProcessID = &v7->ProcessID;
      dds3LinkProcess(p_ProcessID, &target);
    }
  }
  return 1;
}

// 0x135ad40
s32 evtCommand_RESTORE_BATTLE(void) {
  s32 IntPara;
  s32 v5;

  IntPara = scrGetIntPara(0);
  v5 = scrGetIntPara(1);
  CallBattleSub(IntPara, v5);
  return 1;
}

// 0x1359bc0
s32 evtCommand_RTRN_TITLE(void) {
  UnloadALL(1, 0);
  init_flag = 1;
  dds3AdminiCallSequence(2, 0, 0, 0);
  return 1;
}

// 0x13599c0
s32 evtCommand_SEARCH_ID(void) {
  System_String_o *StrPara;
  dds3Basic_t_o *v5;
  s32 serialID;
  s32 v8;
  Il2CppObject *v10;
  System_Object_array *v11;
  s64 *v12;
  s64 *v13;
  dds3Basic_t_o *scene;

  scene = 0;
  scene = dds3GetControlScene();
  StrPara = scrGetStrPara(0);
  v5 = dds3SceneBasicSearchName(&scene, StrPara);
  if (v5)
  {
    serialID = v5->serialID;
    v8 = serialID;
  }
  else
  {
    v10 = scrGetStrPara(0);
    Write_2930400("ID : id not found!! <{0}>\n", v10);
    v11 = NewSpecific(object, 1u);
    v12 = scrGetStrPara(0);
    v13 = v12;
    v11->m_Items[0] = v13;
    dds3Printf("WARNING: ID not found! <{0}>\n", v11);
    v8 = 0;
  }
  scrSetIntReturnValue(v8);
  return 1;
}

// 0x1360420
s32 evtCommand_SET_SKY(void) {
  s32 IntPara;
  s32 v4;
  s32 v5;

  fldSkySetFilterAnime(0);
  fldSkySetAlpha(128);
  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  v5 = scrGetIntPara(2);
  fldSkySetFilter(IntPara, v4, v5);
  return 1;
}

// 0x1360500
s32 evtCommand_SET_SKY_A(void) {
  s32 IntPara;
  s32 v4;
  System_Object_array *v5;
  System_Object_array *v7;
  s32 v9;

  IntPara = scrGetIntPara(1);
  if (IntPara <= -256)
  {
    v7 = Empty_string_();
    dds3Printf("warning : SET_SKY_A alpha < -255\n", v7);
    v4 = -255;
LABEL_11:
      goto LABEL_14;
    goto LABEL_12;
  }
  v4 = IntPara;
  if (IntPara < 256)
    goto LABEL_11;
  v5 = Empty_string_();
  dds3Printf("warning : SET_SKY_A alpha > 255\n", v5);
  v4 = 255;
    goto LABEL_14;
LABEL_12:
LABEL_14:
  v9 = scrGetIntPara(0);
  evtSetSkyAlpha(v9, v4);
  return 1;
}

// 0x13611a0
s32 evtCommand_SET_SUSPEND(void) {
  s32 IntPara;
  s32 v4;

  IntPara = scrGetIntPara(0);
  v4 = scrGetIntPara(1);
  if (IntPara == 1)
  {
    KagPuzNow = v4;
    return 1;
  }
  else
  {
    if (!IntPara)
    {
      KagPuzPos = v4;
    }
    return 1;
  }
}

// 0x1360ae0
s32 evtCommand_SE_PLAY_E(void) {
  s32 IntPara;
  s32 v3;
  s32 v4;
  s32 v6;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  evtPlaySe(IntPara, v3);
  v4 = scrGetIntPara(0);
  v6 = scrGetIntPara(1);
  evtUpdateEx_SE_E_After(v4, v6);
  return 1;
}

// 0x1360bc0
s32 evtCommand_SE_STOP_E(void) {
  s32 IntPara;
  s32 v3;

  IntPara = scrGetIntPara(0);
  v3 = scrGetIntPara(1);
  evtStopSe(IntPara, v3);
  return 1;
}

// 0x13600b0
s32 evtCommand_TEX_ALP(void) {
  s32 IntPara;
  dds3ProcessID_t_o *v4;
  s32 v5;
  s32 v6;
  s32 v8;

  IntPara = scrGetIntPara(0);
  v4 = dds3SearchProcessID(IntPara);
  v5 = scrGetIntPara(1);
  v6 = scrGetIntPara(2);
  v8 = scrGetIntPara(3);
  evtPictureSetAlpha(v4, v5, v6, v8);
  return 1;
}

// 0x135f3a0
s32 evtCommand_TEX_BE(void) {
  u64 *v1;
  u64 *v2;
  scrProcessWork_s_o *ScriptHandle;
  dds3ProcessID_t_o **p_ProcessID;
  s32 IntPara;
  s32 v9;
  s32 id;
  System_Object_array *v14;
  s64 *v15;
  s64 *v16;
  s32 v20;
  dds3ProcessID_t_o *target;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  target = v2;
  ScriptHandle = scrGetScriptHandle();
  if (ScriptHandle)
  {
    p_ProcessID = &ScriptHandle->ProcessID;
    if (ScriptHandle->ProcessID)
    {
      IntPara = scrGetIntPara(0);
      v9 = scrGetIntPara(1);
      if (evtGetResorceData(IntPara, v9))
      {
        dds3LinkProcess(p_ProcessID, &target);
        id = target->id;
        scrSetIntReturnValue(id);
      }
      else
      {
        v14 = NewSpecific(object, 1u);
        v20 = scrGetIntPara(1);
        v15 = sub_8D3950(s32, &v20);
        v16 = v15;
        v14->m_Items[0] = v16;
        dds3Printf("TEX_BE not fount RID = %d\n", v14);
      }
    }
    else
    {
      Write("※警告:TEX_BE()このコマンドはプロセス型スクリプトでのみ有効です。\n", 0);
    }
  }
  return 1;
}

// 0x135f9d0
s32 evtCommand_TEX_CLS(void) {
  u64 *v1;
  s32 IntPara;
  dds3ProcessID_t_o *v6;
  dds3ProcessID_t_o *id;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  id = v1;
  IntPara = scrGetIntPara(0);
  id = dds3SearchProcessID(IntPara);
  if (dds3ExistProcess(&id) == 1)
  {
    v6 = id;
    evtKillPictureProcess(v6);
  }
  return 1;
}

// 0x135f620
s32 evtCommand_TEX_LOAD(void) {
  u64 *v1;
  u64 *v2;
  scrProcessWork_s_o *ScriptHandle;
  dds3ProcessID_t_o **p_ProcessID;
  System_String_o *StrPara;
  dds3ProcessID_t_o *target;

  v1 = Allocate(scrProcessWork_s);
  scrProcessWork_s___ctor(v1);
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  target = v2;
  ScriptHandle = scrGetScriptHandle();
  if (ScriptHandle)
  {
    p_ProcessID = &ScriptHandle->ProcessID;
    if (ScriptHandle->ProcessID)
    {
      StrPara = scrGetStrPara(0);
      target = evtStartPictureProcess(11006, StrPara);
      dds3LinkProcess(p_ProcessID, &target);
      scrSetIntReturnValue(target->id);
    }
    else
    {
      Write("※警告:TEX_LOAD()このコマンドはプロセス型スクリプトでのみ有効です。\n", 0);
    }
  }
  return 1;
}

// 0x135f8c0
s32 evtCommand_TEX_OFF(void) {
  u64 *v1;
  s32 IntPara;
  dds3ProcessID_t_o *v6;
  dds3ProcessID_t_o *id;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  id = v1;
  IntPara = scrGetIntPara(0);
  id = dds3SearchProcessID(IntPara);
  if (dds3ExistProcess(&id) == 1)
  {
    v6 = id;
    evtPictureDrawOff(v6);
  }
  return 1;
}

// 0x135f7b0
s32 evtCommand_TEX_ON(void) {
  u64 *v1;
  s32 IntPara;
  dds3ProcessID_t_o *v6;
  dds3ProcessID_t_o *id;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  id = v1;
  IntPara = scrGetIntPara(0);
  id = dds3SearchProcessID(IntPara);
  if (dds3ExistProcess(&id) == 1)
  {
    v6 = id;
    evtPictureDrawOn(v6);
  }
  return 1;
}

// 0x135fc80
s32 evtCommand_TEX_OT(void) {
  s32 IntPara;
  dds3ProcessID_t_o *v4;
  s32 v6;

  IntPara = scrGetIntPara(0);
  v4 = dds3SearchProcessID(IntPara);
  v6 = scrGetIntPara(1);
  evtPictureSetOt(v4, v6);
  return 1;
}

// 0x135ff70
s32 evtCommand_TEX_POS(void) {
  s32 IntPara;
  dds3ProcessID_t_o *v4;
  s32 v5;
  s32 v6;
  s32 v7;
  s32 v8;
  s32 v10;

  IntPara = scrGetIntPara(0);
  v4 = dds3SearchProcessID(IntPara);
  v5 = scrGetIntPara(1);
  v6 = scrGetIntPara(2);
  v7 = scrGetIntPara(3);
  v8 = scrGetIntPara(4);
  v10 = scrGetIntPara(5);
  evtPictureSetPos(v4, v5, v6, v7, v8, v10);
  return 1;
}

// 0x135fd60
s32 evtCommand_TEX_PRI(void) {
  s32 IntPara;
  dds3ProcessID_t_o *v4;
  s32 v6;

  IntPara = scrGetIntPara(0);
  v4 = dds3SearchProcessID(IntPara);
  v6 = scrGetIntPara(1);
  evtPictureSetPri(v4, v6);
  return 1;
}

// 0x135fe40
s32 evtCommand_TEX_SIZE(void) {
  s32 IntPara;
  dds3ProcessID_t_o *v4;
  s32 v5;
  s32 v6;
  s32 v7;
  s32 v9;

  IntPara = scrGetIntPara(0);
  v4 = dds3SearchProcessID(IntPara);
  v5 = scrGetIntPara(1);
  v6 = scrGetIntPara(2);
  v7 = scrGetIntPara(3);
  v9 = scrGetIntPara(4);
  evtPictureSetSize(v4, v5, v6, v7, v9);
  return 1;
}

// 0x13602d0
s32 evtCommand_TEX_STAT(void) {
  s32 IntPara;
  dds3ProcessID_t_o *v5;
  u32 v6;
  s32 v7;
  s32 v9;
  s32 v11;

  IntPara = scrGetIntPara(0);
  v5 = dds3SearchProcessID(IntPara);
  v6 = evtPictureStat(v5);
  v7 = scrGetIntPara(1);
  if (v7 == 2)
  {
    v9 = (v6 >> 1) & 1;
  }
  else if (v7 == 1)
  {
    v9 = v6 & 1;
  }
  else if (v7)
  {
    v9 = 0;
  }
  else
  {
    v9 = v6 != 0;
  }
  if (v7 != 3 || (v6 & 4) == 0)
    v11 = v9;
  else
    v11 = 1;
  scrSetIntReturnValue(v11);
  return 1;
}

// 0x135fae0
s32 evtCommand_TEX_SWAP(void) {
  u64 *v1;
  u64 *v2;
  s32 IntPara;
  s32 v6;
  s32 v7;
  s32 v8;
  dds3ProcessID_t_o *v11;
  dds3ProcessID_t_o *v12;
  dds3ProcessID_t_o *v14;
  dds3ProcessID_t_o *id;

  v1 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v1);
  id = v1;
  v2 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v2);
  v14 = v2;
  IntPara = scrGetIntPara(0);
  id = dds3SearchProcessID(IntPara);
  v6 = scrGetIntPara(1);
  v14 = dds3SearchProcessID(v6);
  v7 = scrGetIntPara(2);
  v8 = scrGetIntPara(3);
  if (dds3ExistProcess(&id) == 1)
  {
    if (dds3ExistProcess(&v14) == 1)
    {
      v12 = v14;
      v11 = id;
      evtPictureSwap(v11, v12, v7, v8);
    }
  }
  return 1;
}

// 0x13601c0
s32 evtCommand_TEX_ZOOM(void) {
  s32 IntPara;
  dds3ProcessID_t_o *v4;
  s32 v5;
  s32 v6;
  s32 v8;

  IntPara = scrGetIntPara(0);
  v4 = dds3SearchProcessID(IntPara);
  v5 = scrGetIntPara(1);
  v6 = scrGetIntPara(2);
  v8 = scrGetIntPara(3);
  evtPictureSetZoom(v4, v5, v6, v8);
  return 1;
}

// 0x135bb10
s32 evtCommand_UNIT_CLS(void) {
  System_Object_array *v3;

  evtFreeAllUnit();
  Write("unit all clear !!\n", 0);
  v3 = Empty_string_();
  dds3Printf("unit all clear.\n", v3);
  return 1;
}

// 0x135bbe0
s32 evtCommand_UNIT_CLS_STOP(void) {
  System_Object_array *v3;

  evtFreeAllUnit();
  do
  {
    {
      if (sdfDelayedResrcCheck() != 1)
        goto LABEL_12;
    }
  }
  while (sdfDelayedResrcCheck() == 1);
LABEL_12:
  Write("unit all clear2 !!\n", 0);
  v3 = Empty_string_();
  dds3Printf("unit all clear2.\n", v3);
  return 1;
}

// 0x13613b0
s32 evtCommand_UNLOCK_TRP(void) {
  s32 v2;
  u64 *v3;
  System_String_o *v4;
  System_Object_array *v6;
  s32 IntPara;

  IntPara = scrGetIntPara(0);
  v2 = IntPara;
  v3 = sub_8D3950(s32, &IntPara);
  v4 = Concat("UNLOCK = ", v3);
  v6 = Empty_string_();
  Log(v4, v6, 0);
  EndingEventUnlock(v2);
  return 1;
}

// 0x1353270
dds3Basic_t *evtSearchBasic(s32 type, s32 serial) {
  dds3Basic_t_o *pBasic;

  pBasic = 0;
  pBasic = dds3GetActiveScene();
  return dds3SearchSceneBasic(&pBasic, serial, type);
}
