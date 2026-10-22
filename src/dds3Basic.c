#include "types.h"

typedef struct dds3BasicFunction_t dds3BasicFunction_t;
typedef struct dds3Basic_t dds3Basic_t;
typedef struct dds3PoseSet_t dds3PoseSet_t;

static dds3BasicFunction_t *basicfunctiontable[18];
static u32 dds3SerializeID_serialCounter;

void Mult(void);
void Normalize(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__SCALE_XYZ(void);
void SDF_VU0__SETSCALE1VECTOR(void);
void SDF_VU0__SET_ROW3(void);
void SDF_VU0__STOREIDENTITYVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__VECTOR_W_SET_ONE(void);
void ToMatrix(void);
bool evtBitCheck(s32 no);
f32 sdfFabs(f32 c);

// 0x1521040
u32 DDS3_GETBASICTYPEL(dds3Basic_t *pAreaBasic) {
  return HIBYTE(pAreaBasic->type);
}

// 0x1522320
s32 ToFrame(f32 time) {
  s32 targetFrameRate;
  f32 v5;
  f64 v6;
  s64 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f64 iptr;

  targetFrameRate = get_targetFrameRate();
  v5 = targetFrameRate * time;
  v6 = modf(v5, &iptr);
  if (v5 >= 0.0)
  {
    if (v6 != 0.5)
      return floorf(v5 + 0.5);
    v7 = iptr;
    v8 = iptr;
    v9 = 1.0;
  }
  else
  {
    if (v6 != -0.5)
      return ceilf(v5 + -0.5);
    v7 = iptr;
    v8 = iptr;
    v9 = -1.0;
  }
  v10 = v8 + v9;
  if ((v7 & 1) != 0)
    return v10;
  return v8;
}

// 0x1522430
s32 ToSpeed(s32 speed) {
  struct fldGlobalWork_t_o *fldGb;
  s32 v6;

  else if (CurrentEvent == 673)
  {
    return 2 * speed;
  }
  if (fldGb->fieldID != 24)
    return speed;
  if (fldGb->areaID != 9)
    return speed;
LABEL_15:
  if (!evtBitCheck(1381))
    return speed;
  v6 = 1;
  if (evtBitCheck(1382))
  {
    if (evtBitCheck(1384))
      v6 = 1;
    else
      v6 = 2;
  }
  return v6 * speed;
}

// 0x15222e0
f32 ToTime(s32 frame) {
  return (1.0 / get_targetFrameRate()) * frame;
}

// 0x15225b0
dds3Basic_t *dds3AddBasic(u32 type) {
  u64 *v3;
  struct dds3BasicFunction_t_array *basicfunctiontable;
  u64 v8;
  System_Func_object__int__o *v9;
  u64 v11;
  System_Func_object__int__o *v12;
  u64 v13;
  u64 v14;
  u64 v15;

  if (type > 0x11)
    return 0;
  v3 = Allocate(dds3Basic_t);
  dds3Basic_t___ctor(v3);
  if (v3)
  {
    v3[2] = 0;
    v3[3] = 0;
    *(v3 + 8) = type << 24;
    v8 = basicfunctiontable->m_Items[type];
    v3[12] = 0;
    v3[13] = 0;
    *(v3 + 28) = -2139062144;
    v3[10] = 0;
    v3[11] = 0;
    v3[5] = v8;
    v3[8] = 0;
    v3[9] = 0;
    v3[6] = 0;
    v3[7] = 0;
    if (v8)
    {
      v9 = *(v8 + 16);
      if (v9)
      {
        if (int___Invoke(v9, v3) != 1)
        {
          v11 = v3[5];
          if (v11)
          {
            v12 = *(v11 + 24);
            if (v12)
              int___Invoke(v12, v3);
          }
          v13 = v3[10];
          if (v13)
            *(v13 + 72) = v3[9];
          v14 = v3[9];
          if (v14)
          {
            v15 = v3[10];
            v3 = 0;
            *(v14 + 80) = v15;
            return v3;
          }
          return 0;
        }
      }
    }
  }
  return v3;
}

// 0x1522d30
void dds3AddPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos) {
  struct dds3PoseSet_t_o *poseset;
  f32 x;
  f32 v5;
  f32 w;
  f32 z;
  f32 y;
  UnityEngine_Vector4_o v9;
  UnityEngine_Vector4_o v10;

  poseset = (*pBasic)->poseset;
  x = pos.x;
  v5 = poseset->pos.x;
  poseset = (poseset + 24);
  v9.x = v5;
  w = pos.w;
  z = pos.z;
  y = pos.y;
  v9.y = *(&poseset->klass + 1);
  v9.z = *&poseset->monitor;
  v9.w = *(&poseset->monitor + 1);
  LODWORD(poseset->workscl.z) = LODWORD(poseset->workscl.z) & 0xFFFFFFFC | 1;
  SDF_VU0__LOADVECTOR(v9);
  v10.x = x;
  v10.y = y;
  v10.z = z;
  v10.w = w;
  SDF_VU0__LOADVECTOR_B(v10);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(poseset);
}

// 0x1522dc0
void dds3AddRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot) {
  struct dds3PoseSet_t_o *poseset;
  f32 x;
  f32 v5;
  f32 w;
  f32 z;
  f32 y;
  UnityEngine_Vector4_o v9;
  UnityEngine_Vector4_o v10;

  poseset = (*pBasic)->poseset;
  x = rot.x;
  v5 = poseset->rot.x;
  poseset = (poseset + 40);
  v9.x = v5;
  w = rot.w;
  z = rot.z;
  y = rot.y;
  v9.y = *(&poseset->klass + 1);
  v9.z = *&poseset->monitor;
  v9.w = *(&poseset->monitor + 1);
  LODWORD(poseset->workrot.z) = LODWORD(poseset->workrot.z) & 0xFFFFFFFC | 1;
  SDF_VU0__LOADVECTOR(v9);
  v10.x = x;
  v10.y = y;
  v10.z = z;
  v10.w = w;
  SDF_VU0__LOADVECTOR_B(v10);
  Mult();
  SDF_VU0__STOREVECTOR(poseset);
}

// 0x1522e50
void dds3AddSclPoseSet(dds3Basic_t **pBasic, sdfVector4_t scl) {
  struct dds3PoseSet_t_o *poseset;
  f32 x;
  f32 v5;
  f32 w;
  f32 z;
  f32 y;
  UnityEngine_Vector4_o v9;
  UnityEngine_Vector4_o v10;

  poseset = (*pBasic)->poseset;
  x = scl.x;
  v5 = poseset->scl.x;
  poseset = (poseset + 56);
  v9.x = v5;
  w = scl.w;
  z = scl.z;
  y = scl.y;
  v9.y = *(&poseset->klass + 1);
  v9.z = *&poseset->monitor;
  v9.w = *(&poseset->monitor + 1);
  LODWORD(poseset->workpos.z) = LODWORD(poseset->workpos.z) & 0xFFFFFFFC | 1;
  SDF_VU0__LOADVECTOR(v9);
  v10.x = x;
  v10.y = y;
  v10.z = z;
  v10.w = w;
  SDF_VU0__LOADVECTOR_B(v10);
  SDF_VU0__MULVECTOR();
  SDF_VU0__STOREVECTOR(poseset);
}

// 0x15229f0
void dds3BackupPoseSet(dds3PoseSet_t **pPoseSet) {
  SDF_VU0__COPYVECTOR(&(*pPoseSet)->workscl, (*pPoseSet)->scl, 0);
  SDF_VU0__COPYVECTOR(&(*pPoseSet)->workrot, (*pPoseSet)->rot, 0);
  SDF_VU0__COPYVECTOR(&(*pPoseSet)->workpos, (*pPoseSet)->pos, 0);
}

// 0x1523340
s32 dds3CallDrawProcuder(dds3Basic_t **basic) {
  Il2CppObject *v3;
  void *monitor;
  System_Func_object__int__o *v5;

  v3 = *basic;
  if (*basic && (monitor = v3[2].monitor) != 0 && (v5 = *(monitor + 5)) != 0)
    return int___Invoke(v5, v3);
  else
    return 1;
}

// 0x15232c0
s32 dds3CallMainProcuder(dds3Basic_t **basic) {
  Il2CppObject *v3;
  void *monitor;
  System_Func_object__int__o *v5;

  v3 = *basic;
  if (*basic && (monitor = v3[2].monitor) != 0 && (v5 = *(monitor + 4)) != 0)
    return int___Invoke(v5, v3);
  else
    return 1;
}

// 0x15229d0
s32 dds3CheckPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag) {
  return ((*pPoseSet)->flag & flag) != 0;
}

// 0x1522760
void dds3DeleteBasic(dds3Basic_t **basic) {
  Il2CppObject *v3;
  void *monitor;
  System_Func_object__int__o *v5;
  Il2CppClass *klass;
  u64 *v7;

  v3 = *basic;
  if (*basic)
  {
    monitor = v3[2].monitor;
    if (!monitor
      || (v5 = *(monitor + 3)) == 0
      || (int___Invoke(v5, v3), (v3 = *basic) != 0))
    {
      klass = v3[5].klass;
      if (klass)
      {
        klass->_1.castClass = v3[4].monitor;
        v3 = *basic;
      }
      v7 = v3[4].monitor;
      if (v7)
        v7[10] = v3[5].klass;
    }
  }
}

// 0x1522970
void dds3FreePoseSet(dds3Basic_t **basic) {
  dds3Basic_t_o *v2;

  v2 = *basic;
  if (*basic)
  {
    if (v2->poseset)
      v2->poseset = 0;
  }
}

// 0x1523460
char *dds3GetBasicName(dds3Basic_t **basic) {
  if (*basic)
    return (*basic)->name;
  else
    return 0;
}

// 0x1522bb0
void dds3GetPos2PoseSetMCR(dds3Basic_t **pBasic) {
  SDF_VU0__LOADVECTOR((*pBasic)->poseset->pos2, 0);
  SDF_VU0__VECTOR_W_SET_ONE();
}

// 0x1522b00
void dds3GetPosPoseSet(dds3Basic_t **pBasic) {
  SDF_VU0__LOADVECTOR((*pBasic)->poseset->pos, 0);
  SDF_VU0__VECTOR_W_SET_ONE();
}

// 0x1522b80
void dds3GetPosPoseSetMCR(dds3Basic_t **pBasic) {
  SDF_VU0__LOADVECTOR((*pBasic)->poseset->pos, 0);
  SDF_VU0__VECTOR_W_SET_ONE();
}

// 0x1522a60
f32 dds3GetRadiusPoseSet(dds3Basic_t **pBasic) {
  return (*pBasic)->poseset->r;
}

// 0x1522be0
void dds3GetRotPoseSet(dds3Basic_t **pBasic) {
  SDF_VU0__LOADVECTOR((*pBasic)->poseset->rot, 0);
  Normalize(0);
}

// 0x1522c60
void dds3GetRotPoseSetMCR(dds3Basic_t **pBasic) {
  SDF_VU0__LOADVECTOR((*pBasic)->poseset->rot, 0);
  Normalize(0);
}

// 0x1522c90
void dds3GetSclPoseSet(dds3Basic_t **pBasic) {
  dds3Basic_t_o *v3;

  v3 = *pBasic;
  SDF_VU0__LOADVECTOR(v3->poseset->scl);
}

// 0x1522d10
void dds3GetSclPoseSetMCR(dds3Basic_t *pBasic) {
  SDF_VU0__LOADVECTOR(pBasic->poseset->scl);
}

// 0x1522f90
void dds3GetTMPoseSet(dds3Basic_t **pBasic) {
  struct dds3PoseSet_t_o *poseset;
  u32 flag;
  f32 x;
  f32 v6;
  f32 y;
  f32 z;
  f32 w;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v13;
  f32 v14;
  f32 v15;
  f32 v16;
  f32 v17;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Vector4_o v19;
  UnityEngine_Vector4_o v20;
  UnityEngine_Vector4_o v21;

  poseset = (*pBasic)->poseset;
  flag = poseset->flag;
  if ((flag & 2) != 0)
  {
    memmove(&dest, &poseset->workTM->fields, 0x40u);
    SDF_VU0__LOADMATRIX(&dest);
  }
  else
  {
    x = poseset->pos.x;
    v6 = poseset->scl.x;
    y = poseset->scl.y;
    z = poseset->scl.z;
    w = poseset->scl.w;
    v10 = poseset->rot.x;
    v11 = poseset->rot.y;
    poseset->flag = flag | 2;
    v12 = poseset->rot.z;
    v13 = poseset->rot.w;
    v17 = x;
    v16 = poseset->pos.y;
    v14 = poseset->pos.z;
    v15 = poseset->pos.w;
    v19.x = v10;
    v19.y = v11;
    v19.z = v12;
    v19.w = v13;
    SDF_VU0__LOADVECTOR(v19);
    ToMatrix();
    v20.x = v6;
    v20.y = y;
    v20.z = z;
    v20.w = w;
    SDF_VU0__LOADVECTOR(v20);
    SDF_VU0__SCALE_XYZ();
    v21.y = v16;
    v21.x = v17;
    v21.z = v14;
    v21.w = v15;
    SDF_VU0__LOADVECTOR(v21);
    SDF_VU0__VECTOR_W_SET_ONE();
    SDF_VU0__SET_ROW3();
    SDF_VU0__STOREMATRIX(&poseset->workTM->pm);
  }
}

// 0x1522800
s32 dds3InitPoseSet(dds3Basic_t **basic) {
  u64 *v4;

  if (!*basic)
    return 0;
  if ((*basic)->poseset)
    return 0;
  v4 = Allocate(dds3PoseSet_t);
  dds3PoseSet_t___ctor(v4);
  if (!v4)
    return 0;
  *(v4 + 38) = 1;
  SDF_VU0__STOREIDENTITYVECTOR((v4 + 3), 0);
  SDF_VU0__STOREIDENTITYVECTOR((v4 + 5), 0);
  SDF_VU0__SETSCALE1VECTOR();
  SDF_VU0__STOREVECTOR((v4 + 7), 0);
  SDF_VU0__STOREIDENTITYVECTOR((v4 + 17), 0);
  *(v4 + 156) = 0;
  (*basic)->poseset = v4;
  return 1;
}

// 0x1522910
void dds3InitPoseSetValue(dds3PoseSet_t **pPoseSet) {
  if (*pPoseSet)
  {
    SDF_VU0__STOREIDENTITYVECTOR(&(*pPoseSet)->pos, 0);
    SDF_VU0__STOREIDENTITYVECTOR(&(*pPoseSet)->rot, 0);
    SDF_VU0__SETSCALE1VECTOR();
    SDF_VU0__STOREVECTOR(&(*pPoseSet)->scl, 0);
  }
}

// 0x1522ee0
void dds3MakeMatrix(sdfVector4_t scale, sdfVector4_t quaternion, sdfVector4_t transrate) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  s64 v8;
  s64 v9;
  UnityEngine_Vector4_o v10;
  UnityEngine_Vector4_o v11;

  w = scale.w;
  z = scale.z;
  y = scale.y;
  x = scale.x;
  SDF_VU0__LOADVECTOR(quaternion);
  ToMatrix();
  v10.x = x;
  v10.y = y;
  v10.z = z;
  v10.w = w;
  SDF_VU0__LOADVECTOR(v10);
  SDF_VU0__SCALE_XYZ();
  *&v11.x = v8;
  *&v11.z = v9;
  SDF_VU0__LOADVECTOR(v11);
  SDF_VU0__VECTOR_W_SET_ONE();
  SDF_VU0__SET_ROW3();
}

// 0x15229b0
void dds3OffPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag) {
  (*pPoseSet)->flag &= ~flag;
}

// 0x1522990
void dds3OnPoseSetFlag(dds3PoseSet_t **pPoseSet, u32 flag) {
  (*pPoseSet)->flag |= flag;
}

// 0x1523110
s32 dds3RadiusCheckPoseSet(dds3PoseSet_t **p1, dds3PoseSet_t **p2) {
  f32 v6;

  SDF_VU0__LOADVECTOR((*p1)->pos, 0);
  SDF_VU0__LOADVECTOR_B((*p2)->pos, 0);
  SDF_VU0__SUBVECTOR();
  v6 = SDF_VU0__GETLENGTH();
  return (sdfFabs(v6) - ((*p1)->r + (*p2)->r)) < 0.0;
}

// 0x15231f0
s32 dds3RadiusCheckPoseSet2(dds3PoseSet_t **p1, dds3PoseSet_t **p2) {
  f32 v6;

  SDF_VU0__LOADVECTOR((*p1)->pos, 0);
  SDF_VU0__LOADVECTOR_B((*p2)->pos, 0);
  SDF_VU0__SUBVECTOR();
  v6 = SDF_VU0__GETLENGTH();
  return (sdfFabs(v6) - (*p2)->r) < 0.0;
}

// 0x15233c0
u32 dds3SerializeID(void) {
  ++dds3SerializeID_serialCounter;
  dds3SerializeID_serialCounter = LOWORD(dds3SerializeID_serialCounter);
  return dds3SerializeID_serialCounter;
}

// 0x1523450
void dds3SetBasicName(dds3Basic_t **basic, char *name) {
  if (*basic)
    (*basic)->name = name;
}

// 0x1522a70
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos) {
  struct dds3PoseSet_t_o *poseset;

  poseset = (*pBasic)->poseset;
  poseset->flag = poseset->flag & 0xFFFFFFFC | 1;
  SDF_VU0__COPYVECTOR(&poseset->pos, pos);
}

// 0x1522a50
void dds3SetRadiusPoseSet(dds3Basic_t **pBasic, f32 radius) {
  (*pBasic)->poseset->r = radius;
}

// 0x1522aa0
void dds3SetRotPoseSet(dds3Basic_t **pBasic, sdfVector4_t rot) {
  struct dds3PoseSet_t_o *poseset;

  poseset = (*pBasic)->poseset;
  poseset->flag = poseset->flag & 0xFFFFFFFC | 1;
  SDF_VU0__COPYVECTOR(&poseset->rot, rot);
}

// 0x1522ad0
void dds3SetSclPoseSet(dds3Basic_t **pBasic, sdfVector4_t scl) {
  struct dds3PoseSet_t_o *poseset;

  poseset = (*pBasic)->poseset;
  poseset->flag = poseset->flag & 0xFFFFFFFC | 1;
  SDF_VU0__COPYVECTOR(&poseset->scl, scl);
}
