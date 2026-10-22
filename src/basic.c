#include "types.h"

typedef struct dds3EffectObjectBasicWorkData_t dds3EffectObjectBasicWorkData_t;
typedef struct dds3MatterObjectBasicWorkData_t dds3MatterObjectBasicWorkData_t;
typedef struct dds3ModelBasicWorkData_t dds3ModelBasicWorkData_t;
typedef struct dds3ModelRangeBasicWorkData_t dds3ModelRangeBasicWorkData_t;
typedef struct dds3MoverBasicWorkData_t dds3MoverBasicWorkData_t;
typedef struct dds3ObjectBaseControlWorkData_t dds3ObjectBaseControlWorkData_t;
typedef struct dds3PathBasicControl_t dds3PathBasicControl_t;
typedef struct dds3UnitObjectBasicWorkData_t dds3UnitObjectBasicWorkData_t;

// 0x1311870
void dds3EffectObjectBasicWorkData_t__Clear(dds3EffectObjectBasicWorkData_t *this) {
  u64 *v3;
  f32 v4;
  f32 v5;
  Il2CppObject *v6;
  u64 *v7;
  f32 v8;
  f32 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;

  v3 = Allocate(dds3ObjectBaseControlWorkData_t);
  _ctor(v3, 0);
  *&this->stat = 0;
  this->handle = 0;
  this->pObjectBaseControlWorkData = v3;
  v12 = 0;
  v13 = 0;
  sub_854690(&v12, 0.0, 0.0, 0.0, 0.0);
  v5 = *&v13;
  v4 = *(&v13 + 1);
  *&this->linkpos.x = v12;
  this->linkpos.z = v5;
  this->linkpos.w = v4;
  v6 = Allocate(dds3Basic_t);
  v6[7].monitor = NewSpecific(uint, 3u);
  _ctor(v6, 0);
  this->linkbasic = v6;
  *&this->linkindex = 0;
  this->reserve3 = 0;
  this->para = 0;
  this->cuth = 0;
  *&this->reserve1 = 0;
  v7 = Allocate(fldResourceEffect_t);
  fldResourceEffect_t___ctor(v7);
  this->pFldEx = v7;
  v10 = 0;
  v11 = 0;
  sub_854690(&v10, 0.0, 0.0, 0.0, 0.0);
  v9 = *&v11;
  v8 = *(&v11 + 1);
  *&this->FldExBasePos.x = v10;
  this->FldExBasePos.z = v9;
  this->FldExBasePos.w = v8;
}

// 0x1311ad0
void dds3MatterObjectBasicWorkData_t__Clear(dds3MatterObjectBasicWorkData_t *this) {
  u64 *v3;
  f32 v4;
  f32 v5;
  f32 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;

  v3 = Allocate(dds3ObjectBaseControlWorkData_t);
  _ctor(v3, 0);
  this->pObjectBaseControlWorkData = v3;
  *&this->hojiID = 0;
  this->OtLinkIdx = 0;
  v10 = 0;
  v11 = 0;
  sub_854690(&v10, 0.0, 0.0, 0.0, 0.0);
  v5 = *&v11;
  v4 = *(&v11 + 1);
  *&this->base_pos.x = v10;
  this->base_pos.z = v5;
  this->base_pos.w = v4;
  v8 = 0;
  v9 = 0;
  sub_854690(&v8, 0.0, 0.0, 0.0, 0.0);
  v6 = *(&v9 + 1);
  v7 = v8;
  LODWORD(this->move_pos.z) = v9;
  this->move_pos.w = v6;
  *&this->move_pos.x = v7;
}

// 0x1311bc0
void dds3ModelBasicWorkData_t__Clear(dds3ModelBasicWorkData_t *this) {
  Il2CppObject *v3;
  u64 *v4;
  u64 *v5;
  u64 *v6;

  v3 = Allocate(dds3Basic_t);
  v3[7].monitor = NewSpecific(uint, 3u);
  _ctor(v3, 0);
  this->pTextureBasic = v3;
  v4 = Allocate(sdfModelDef_t);
  sdfModelDef_t___ctor(v4);
  this->pModelDef = v4;
  v5 = Allocate(sdfMotionPlayBook_t);
  sdfMotionPlayBook_t___ctor(v5);
  this->pMotDef = v5;
  v6 = Allocate(sdfModelTexList_t);
  sdfModelTexList_t___ctor(v6);
  this->pTexList = v6;
  this->padd = NewSpecific(uint, 3u);
}

// 0x1311d40
void dds3ModelRangeBasicWorkData_t__Clear(dds3ModelRangeBasicWorkData_t *this) {
  u64 *v3;
  u64 *v4;
  f32 v5;
  f32 v6;
  s64 v7;
  s64 v8;

  v3 = Allocate(fldResourceModelRange_t);
  fldResourceModelRange_t___ctor(v3);
  this->pRange = v3;
  this->pShapePacket = 0;
  v4 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v4);
  this->hPlane = v4;
  v7 = 0;
  v8 = 0;
  sub_854690(&v7, 0.0, 0.0, 0.0, 0.0);
  v6 = *&v8;
  v5 = *(&v8 + 1);
  *&this->pPlane.x = v7;
  this->pPlane.z = v6;
  this->pPlane.w = v5;
  *&this->blockID = 0;
}

// 0x1313610
void dds3MoverBasicWorkData_t__Clear(dds3MoverBasicWorkData_t *this) {
  Il2CppObject *v3;

  v3 = Allocate(dds3Basic_t);
  v3[7].monitor = NewSpecific(uint, 3u);
  _ctor(v3, 0);
  this->pFunc = 0;
  this->pPathBasic = 0;
  this->pObjectBasic = v3;
  this->pPathControl = 0;
}

// 0x13136d0
void dds3ObjectBaseControlWorkData_t__Clear(dds3ObjectBaseControlWorkData_t *this) {
  u64 *v3;
  struct dds3Basic_t_array *v4;

  this->flag = 0;
  v3 = Allocate(dds3BasicArrayHandle_t);
  _ctor(v3, 0);
  this->hEventBasicArray = v3;
  this->modelType = 0;
  this->pModel = 0;
  v4 = NewSpecific(dds3Basic_t, 8u);
  *&this->MotMode = 0;
  *&this->svs = 0;
  this->pModelRangeRootNode = 0;
  this->pMot = 0;
  this->pBasic = v4;
  this->pUserValue = 0;
  this->sdwnodeidx = NewSpecific(s32, 0x18u);
}

// 0x1313780
void dds3PathBasicControl_t__Clear(dds3PathBasicControl_t *this) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  u64 *v6;
  u64 *v7;

  *&this->mode = 0;
  *&this->frameMax = 0;
  v3 = Allocate(effSpline_t);
  effSpline_t___ctor(v3);
  this->pSplineHandle = v3;
  v4 = Allocate(fldResourcePathData_t_Vector3);
  fldResourcePathData_t_Vector3___ctor(v4);
  this->pTransrate = v4;
  v5 = Allocate(fldResourcePathData_t_Vector4);
  fldResourcePathData_t_Vector4___ctor(v5);
  this->pRotation = v5;
  v6 = Allocate(fldResourcePathData_t_Float);
  fldResourcePathData_t_Float___ctor(v6);
  this->pFovy = v6;
  v7 = Allocate(fldResourcePathData_t_Light);
  fldResourcePathData_t_Light___ctor(v7);
  this->pLight = v7;
}

// 0x1313970
void dds3UnitObjectBasicWorkData_t__Clear(dds3UnitObjectBasicWorkData_t *this) {
  u64 *v3;
  u64 *v4;

  this->statusID = 0;
  this->pWorkData = 0;
  v3 = Allocate(evtUnitHandle_t);
  evtUnitHandle_t___ctor(v3);
  this->hUnit = v3;
  v4 = Allocate(dds3ObjectBaseControlWorkData_t);
  _ctor(v4, 0);
  this->IsBattle = 0;
  *&this->EL_serialID = 0;
  *&this->flag = 0;
  this->pObjectBaseControlWorkData = v4;
}
