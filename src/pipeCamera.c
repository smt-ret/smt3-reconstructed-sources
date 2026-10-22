#include "types.h"

typedef struct dds3Basic_t dds3Basic_t;
typedef struct tagPipeObject tagPipeObject;

static void *pipeCameraObj;
static void *pipeCameraCtrl;
static sdfVector4_t pipeVertical;
static sdfVector4_t pipeCameraPos;
static sdfVector4_t pipeTargetPos;
static dds3Basic_t *pipe_Camera;

void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SetCamera(void);
void SetVec(sdfVector4_t *pVec, f32 x, f32 y, f32 z);
f32 VecNormalize(sdfVector4_t *pVec);
void VecRotateX(sdfVector4_t *pVec, f32 Radian);
void VecZoom(sdfVector4_t *pVec, f32 s);
void Veccross(sdfVector4_t *vec, sdfVector4_t vec1, sdfVector4_t vec2);
f32 Vecdot(sdfVector4_t vec1, sdfVector4_t vec2);
dds3Basic_t *dds3AddCameraObjectBasicTypeLookAt(u32 serialID, sdfVector4_t eyePos, sdfVector4_t targetPos, sdfVector4_t vertical);
void dds3CameraObjectBasicGetTgtCam(dds3Basic_t **pBasic, sdfVector4_t *tgtpos, sdfVector4_t *campos);
void dds3CameraObjectBasicSetTargetPos(dds3Basic_t **pBasic, sdfVector4_t targetPos);
dds3Basic_t *dds3GetActiveScene(void);
u32 dds3SerializeID(void);
dds3Basic_t *dds3SetActiveCameraSceneBasic(dds3Basic_t **pSceneBasic, dds3Basic_t **pCameraBasic);
void dds3SetBasicName(dds3Basic_t **basic, char *name);
void dds3SetPosPoseSet(dds3Basic_t **pBasic, sdfVector4_t pos);
void dds3SetRadiusPoseSet(dds3Basic_t **pBasic, f32 radius);
void dds3SetScreenFovy(f32 fovy);
void getPosTranslate(tagPipeObject *objPtr, sdfVector4_t *pos);
tagPipeObject *objMyData(void);
f32 sdfFabs(f32 c);
f32 sdfSqrt(f32 aValue);

// 0x14b7e80
void AddCamera(void) {
  s64 v3;
  u32 v5;
  struct dds3Basic_t_o *v7;
  dds3Basic_t_o *pSceneBasic;
  UnityEngine_Vector4_o v14;

  pSceneBasic = 0;
  v5 = dds3SerializeID();
  *&v14.x = 0;
  *&v14.z = v3;
  v7 = dds3AddCameraObjectBasicTypeLookAt(v5, pipeCameraPos, pipeTargetPos, v14);
  pipe_Camera = v7;
  dds3SetBasicName(&pipe_Camera, "Pipe_Cam");
  dds3CameraObjectBasicSetTargetPos(&pipe_Camera, pipeTargetPos);
  dds3SetRadiusPoseSet(&pipe_Camera, 2.0);
  pSceneBasic = dds3GetActiveScene();
  dds3SetActiveCameraSceneBasic(&pSceneBasic, &pipe_Camera);
  dds3SetScreenFovy(0.87965);
  SetCamera();
}

// 0x14b8330
void CalcCamera(void) {
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  Il2CppObject *workdata;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  u64 v16[3];
  UnityEngine_Vector4_o v17;

  dds3CameraObjectBasicSetTargetPos(&pipe_Camera, pipeTargetPos);
  x = pipeCameraPos.x;
  y = pipeCameraPos.y;
  z = pipeCameraPos.z;
  w = pipeCameraPos.w;
  v17.x = x;
  v17.y = y;
  v17.z = z;
  v17.w = w;
  dds3SetPosPoseSet(&pipe_Camera, v17);
  int___Invoke(pipe_Camera->basicfunction->mainprocuder, pipe_Camera);
  workdata = pipe_Camera->workdata;
  if (workdata)
  {
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
  }
  SDF_VU0__COPYVECTOR(&workdata[2].monitor, pipeVertical);
  SDF_VU0__COPYVECTOR(&workdata[4].monitor, pipeVertical);
  SetCamera();
}

// 0x14b7aa0
void CamActionQuake(void) {
  System_Array_o *v1;
  struct tagPipePosData_array *pData;
  s64 offsetCount;
  struct tagPipePosData_array *v9;
  s64 v10;
  f32 v11;
  f32 v12;
  struct tagPipePosData_array *v15;
  s64 v16;
  f32 v17;
  f32 v18;
  f32 v20;
  s64 v21;
  s64 p_pipeTargetPos;
  struct UnityEngine_Vector4_o *v26;
  struct UnityEngine_Vector4_o *v27;
  struct UnityEngine_Vector4_o *p_pipeCameraPos;
  struct UnityEngine_Vector4_o *v29;
  struct UnityEngine_Vector4_o *v30;
  UnityEngine_Vector4_o v31;

  v1 = NewSpecific(sbyte, 6u);
  InitializeArray_1543888(v1, Field__PrivateImplementationDetails__23B59D6204593493E1FFE18CD6B7F5644A6BD056);
  *&v31.x = 0;
  *&v31.z = 0;
  if (CameraAction)
  {
    pData = PosTable->pData;
    sub_854710(&pData->m_Items[offsetCount]->up, 0);
    v9 = PosTable->pData;
    v10 = offsetCount;
    v12 = v11;
    sub_854710(&v9->m_Items[v10]->up, 1u);
    v15 = PosTable->pData;
    v16 = offsetCount;
    v18 = v17;
    sub_854710(&v15->m_Items[v16]->up, 2u);
    SetVec(&v31, v12, v18, v20);
    VecNormalize(&v31);
    v21 = 6LL - CameraAction;
    VecZoom(&v31, *(&v1[2].klass + v21), 0);
    --CameraAction;
    p_pipeTargetPos = &pipeTargetPos;
    sub_854710(p_pipeTargetPos, 0);
    sub_854710(&v31, 0);
    sub_854930(p_pipeTargetPos, 0);
    v26 = &pipeTargetPos;
    sub_854710(v26, 1u);
    sub_854710(&v31, 1u);
    sub_854930(v26, 1u);
    v27 = &pipeTargetPos;
    sub_854710(v27, 2u);
    sub_854710(&v31, 2u);
    sub_854930(v27, 2u);
    p_pipeCameraPos = &pipeCameraPos;
    sub_854710(p_pipeCameraPos, 0);
    sub_854710(&v31, 0);
    sub_854930(p_pipeCameraPos, 0);
    v29 = &pipeCameraPos;
    sub_854710(v29, 1u);
    sub_854710(&v31, 1u);
    sub_854930(v29, 1u);
    v30 = &pipeCameraPos;
    sub_854710(v30, 2u);
    sub_854710(&v31, 2u);
    sub_854930(v30, 2u);
  }
}

// 0x14b4920
void PipeCamera(void) {
  s64 offsetCount;
  tagPipeObject_o *v4;
  tagPipeObject_o *v6;
  struct tagPipePosData_array *pData;
  struct tagPipePosData_array *v11;
  struct tagPipePosData_array *v13;
  struct tagPipePosData_array *v15;
  s64 v16;
  struct tagPipePosData_array *v18;
  f32 v19;
  f32 v20;
  struct tagPipePosData_array *v22;
  f32 v23;
  f32 v24;
  struct tagPipePosData_array *v26;
  f32 v27;
  f32 v28;
  struct tagPipePosData_array *v30;
  f32 v31;
  f32 v32;
  struct tagPipePosData_array *v34;
  f32 v35;
  f32 v36;
  f32 v38;
  struct tagPipePosData_array *v39;
  struct tagPipePosData_array *v41;
  f32 v42;
  f32 v43;
  struct tagPipePosData_array *v45;
  f32 v46;
  f32 v47;
  f32 v49;
  struct tagPipePosData_array *v51;
  struct tagPipePosData_array *v53;
  struct tagPipePosData_array *v55;
  UnityEngine_Vector4_o v57;
  UnityEngine_Vector4_o v58;
  UnityEngine_Vector4_o pVec;
  u64 v60[2];

  v60[0] = 0;
  v60[1] = 0;
  *&pVec.x = 0;
  *&pVec.z = 0;
  *&v58.x = 0;
  *&v58.z = 0;
  *&v57.x = 0;
  *&v57.z = 0;
  v4 = objMyData();
  if (v4)
  {
    v6 = v4;
    getPosTranslate(v6, &v57);
    sub_854710(&v57, 0);
    pData = PosTable->pData;
    sub_854710(&pData->m_Items[offsetCount]->fields, 0);
    sub_854930(v60, 0);
    sub_854710(&v57, 1u);
    v11 = PosTable->pData;
    sub_854710(&v11->m_Items[offsetCount]->fields, 1u);
    sub_854930(v60, 1u);
    sub_854710(&v57, 2u);
    v13 = PosTable->pData;
    sub_854710(&v13->m_Items[offsetCount]->fields, 2u);
    sub_854930(v60, 2u);
    v15 = PosTable->pData;
    v16 = offsetCount + 1;
    sub_854710(&v15->m_Items[v16]->fields, 0);
    v18 = PosTable->pData;
    v20 = v19;
    sub_854710(&v18->m_Items[offsetCount]->fields, 0);
    v22 = PosTable->pData;
    v24 = v23;
    sub_854710(&v22->m_Items[v16]->fields, 1u);
    v26 = PosTable->pData;
    v28 = v27;
    sub_854710(&v26->m_Items[offsetCount]->fields, 1u);
    v30 = PosTable->pData;
    v32 = v31;
    sub_854710(&v30->m_Items[v16]->fields, 2u);
    v34 = PosTable->pData;
    v36 = v35;
    sub_854710(&v34->m_Items[offsetCount]->fields, 2u);
    SetVec(&pVec, v20 - v24, v28 - v32, v36 - v38);
    v39 = PosTable->pData;
    sub_854710(&v39->m_Items[offsetCount]->up, 0);
    v41 = PosTable->pData;
    v43 = v42;
    sub_854710(&v41->m_Items[offsetCount]->up, 1u);
    v45 = PosTable->pData;
    v47 = v46;
    sub_854710(&v45->m_Items[offsetCount]->up, 2u);
    SetVec(&v58, v43, v47, v49);
    sub_854710(&v57, 0);
    sub_854930(&pipeTargetPos, 0);
    sub_854710(&v57, 1u);
    sub_854930(&pipeTargetPos, 1u);
    sub_854710(&v57, 2u);
    sub_854930(&pipeTargetPos, 2u);
    VecNormalize(&pVec);
    VecZoom(&pVec, -600.0);
    VecNormalize(&v58);
    VecZoom(&v58, -50.0);
    sub_854710(&v57, 0);
    sub_854710(&pVec, 0);
    sub_854710(&v58, 0);
    sub_854930(&pipeCameraPos, 0);
    sub_854710(&v57, 1u);
    sub_854710(&pVec, 1u);
    sub_854710(&v58, 1u);
    sub_854930(&pipeCameraPos, 1u);
    sub_854710(&v57, 2u);
    sub_854710(&pVec, 2u);
    sub_854710(&v58, 2u);
    sub_854930(&pipeCameraPos, 2u);
    v51 = PosTable->pData;
    sub_854710(&v51->m_Items[offsetCount]->up, 0);
    sub_854930(&pipeVertical, 0);
    v53 = PosTable->pData;
    sub_854710(&v53->m_Items[offsetCount]->up, 1u);
    sub_854930(&pipeVertical, 1u);
    v55 = PosTable->pData;
    sub_854710(&v55->m_Items[offsetCount]->up, 2u);
    sub_854930(&pipeVertical, 2u);
  }
}

// 0x14b5130
void PipeCameraAction(void) {
  s64 offsetCount;
  tagPipeObject_o *v4;
  tagPipeObject_o *v6;
  struct tagPipePosData_array *pData;
  struct tagPipePosData_array *v11;
  struct tagPipePosData_array *v13;
  struct tagPipePosData_array *v15;
  s64 v16;
  struct tagPipePosData_array *v18;
  f32 v19;
  f32 v20;
  struct tagPipePosData_array *v22;
  f32 v23;
  f32 v24;
  struct tagPipePosData_array *v26;
  f32 v27;
  f32 v28;
  struct tagPipePosData_array *v30;
  f32 v31;
  f32 v32;
  struct tagPipePosData_array *v34;
  f32 v35;
  f32 v36;
  f32 v38;
  struct tagPipePosData_array *v39;
  struct tagPipePosData_array *v41;
  f32 v42;
  f32 v43;
  struct tagPipePosData_array *v45;
  f32 v46;
  f32 v47;
  f32 v49;
  f32 *p_pos;
  f32 v52;
  f32 v53;
  f32 v55;
  f32 v56;
  f32 v57;
  f32 v58;
  f32 v60;
  f32 v61;
  struct UnityEngine_Vector4_o *p_pipeCameraPos;
  struct tagPipePosData_array *v66;
  struct tagPipePosData_array *v68;
  struct tagPipePosData_array *v70;
  f32 v72;
  f32 v73;
  f32 v74;
  s32 v76;
  struct tagPipePosData_array *v78;
  struct tagPipePosData_array *v80;
  struct tagPipePosData_array *v82;
  UnityEngine_Vector4_o v85;
  UnityEngine_Vector4_o pos;
  u64 v87[2];
  UnityEngine_Vector4_o v88;
  UnityEngine_Vector4_o pVec;
  u64 v90[2];

  *&pos.x = 0;
  *&pos.z = 0;
  *&v85.x = 0;
  *&v85.z = 0;
  v90[0] = 0;
  v90[1] = 0;
  *&pVec.x = 0;
  *&pVec.z = 0;
  *&v88.x = 0;
  *&v88.z = 0;
  v87[0] = 0;
  v87[1] = 0;
  v4 = objMyData();
  *&pos.x = 0;
  *&pos.z = 0;
  *&v85.x = 0;
  *&v85.z = 0;
  if (v4)
  {
    v6 = v4;
    getPosTranslate(v6, &pos);
    sub_854710(&pos, 0);
    pData = PosTable->pData;
    sub_854710(&pData->m_Items[offsetCount]->fields, 0);
    sub_854930(v90, 0);
    sub_854710(&pos, 1u);
    v11 = PosTable->pData;
    sub_854710(&v11->m_Items[offsetCount]->fields, 1u);
    sub_854930(v90, 1u);
    sub_854710(&pos, 2u);
    v13 = PosTable->pData;
    sub_854710(&v13->m_Items[offsetCount]->fields, 2u);
    sub_854930(v90, 2u);
    v15 = PosTable->pData;
    v16 = offsetCount + 10;
    sub_854710(&v15->m_Items[v16]->fields, 0);
    v18 = PosTable->pData;
    v20 = v19;
    sub_854710(&v18->m_Items[offsetCount]->fields, 0);
    v22 = PosTable->pData;
    v24 = v23;
    sub_854710(&v22->m_Items[v16]->fields, 1u);
    v26 = PosTable->pData;
    v28 = v27;
    sub_854710(&v26->m_Items[offsetCount]->fields, 1u);
    v30 = PosTable->pData;
    v32 = v31;
    sub_854710(&v30->m_Items[v16]->fields, 2u);
    v34 = PosTable->pData;
    v36 = v35;
    sub_854710(&v34->m_Items[offsetCount]->fields, 2u);
    SetVec(&pVec, v20 - v24, v28 - v32, v36 - v38);
    v39 = PosTable->pData;
    sub_854710(&v39->m_Items[offsetCount]->up, 0);
    v41 = PosTable->pData;
    v43 = v42;
    sub_854710(&v41->m_Items[offsetCount]->up, 1u);
    v45 = PosTable->pData;
    v47 = v46;
    sub_854710(&v45->m_Items[offsetCount]->up, 2u);
    SetVec(&v88, v43, v47, v49);
    sub_854710(&pos, 0);
    sub_854930(&pipeTargetPos, 0);
    sub_854710(&pos, 1u);
    sub_854930(&pipeTargetPos, 1u);
    sub_854710(&pos, 2u);
    sub_854930(&pipeTargetPos, 2u);
    VecNormalize(&pVec);
    VecZoom(&pVec, -600.0);
    if (offsetCount <= 479)
    {
      VecNormalize(&v88);
      VecZoom(&v88, 400.0);
      v66 = PosTable->pData;
      sub_854710(&v66->m_Items[480]->fields, 0);
      sub_854710(&pVec, 0);
      sub_854710(&v88, 0);
      sub_854930(&pipeCameraPos, 0);
      v68 = PosTable->pData;
      sub_854710(&v68->m_Items[480]->fields, 1u);
      sub_854710(&pVec, 1u);
      sub_854710(&v88, 1u);
      sub_854930(&pipeCameraPos, 1u);
      v70 = PosTable->pData;
      sub_854710(&v70->m_Items[480]->fields, 2u);
      sub_854710(&pVec, 2u);
      sub_854710(&v88, 2u);
      sub_854930(&pipeCameraPos, 2u);
      v72 = -0.0;
    }
    else
    {
      if (offsetCount > 679)
      {
        if (offsetCount > 799)
          return;
        p_pos = &v6->pos;
        v52 = (((offsetCount - 680) / 120.0) * 50.0) + -100.0;
        v53 = sub_851730(p_pos, 0);
        v55 = sub_851730(p_pos, 0);
        v56 = sdfSqrt(250000.0 - (v53 * v55), 0);
        v57 = sdfFabs(-50.0);
        v58 = sub_851730(p_pos, 1);
        if ((v56 + v57) < sdfFabs(v52 + v58))
        {
          v60 = sdfFabs(-50.0);
          v61 = sub_851730(p_pos, 1);
          v52 = -((v56 + v60) - sdfFabs(v61));
        }
        VecNormalize(&v88);
        VecZoom(&v88, v52);
        sub_854710(&pos, 0);
        sub_854710(&pVec, 0);
        sub_854710(&v88, 0);
        sub_854930(&pipeCameraPos, 0);
        sub_854710(&pos, 1u);
        sub_854710(&pVec, 1u);
        sub_854710(&v88, 1u);
        sub_854930(&pipeCameraPos, 1u);
        sub_854710(&pos, 2u);
        sub_854710(&pVec, 2u);
        sub_854710(&v88, 2u);
        p_pipeCameraPos = &pipeCameraPos;
        goto LABEL_88;
      }
      v73 = (offsetCount - 480);
      v74 = 1.0 - (((v73 / -200.0) + 1.0) * ((v73 / -200.0) + 1.0));
      VecNormalize(&v88);
      VecZoom(&v88, (v74 * -500.0) + 400.0, 0);
      sub_854710(&pVec, 0);
      sub_854710(&v88, 0);
      sub_854930(v87, 0);
      sub_854710(&pVec, 1u);
      sub_854710(&v88, 1u);
      sub_854930(v87, 1u);
      sub_854710(&pVec, 2u);
      sub_854710(&v88, 2u);
      sub_854930(v87, 2u);
      v76 = ((v74 * v73) + 480.0);
      v78 = PosTable->pData;
      sub_854710(&v78->m_Items[v76]->fields, 0);
      sub_854710(v87, 0);
      sub_854930(&pipeCameraPos, 0);
      v80 = PosTable->pData;
      sub_854710(&v80->m_Items[v76]->fields, 1u);
      sub_854710(v87, 1u);
      sub_854930(&pipeCameraPos, 1u);
      v82 = PosTable->pData;
      sub_854710(&v82->m_Items[v76]->fields, 2u);
      sub_854710(v87, 2u);
      sub_854930(&pipeCameraPos, 2u);
      v72 = v74 * -1.5708;
    }
    sub_854930(&v85, 0);
    sub_854930(&v85, 1u);
    sub_854930(&v85, 2u);
    VecRotateX(&v85, v72);
    sub_854710(&v85, 0);
    sub_854930(&pipeVertical, 0);
    sub_854710(&v85, 1u);
    sub_854930(&pipeVertical, 1u);
    sub_854710(&v85, 2u);
    p_pipeCameraPos = &pipeVertical;
LABEL_88:
    sub_854930(p_pipeCameraPos, 2u);
  }
}

// 0x14b5f00
void PipeCameraAction2(void) {
  tagPipeObject_o *v2;
  tagPipeObject_o *v4;
  struct tagPipePosData_array *pData;
  s64 offsetCount;
  struct tagPipePosData_array *v12;
  s64 v13;
  struct tagPipePosData_array *v16;
  s64 v17;
  struct tagPipePosData_array *v20;
  s64 v21;
  struct tagPipePosData_array *v24;
  s64 v25;
  f32 v26;
  f32 v27;
  struct tagPipePosData_array *v30;
  s64 v31;
  f32 v32;
  f32 v33;
  struct tagPipePosData_array *v36;
  s64 v37;
  f32 v38;
  f32 v39;
  struct tagPipePosData_array *v42;
  s64 v43;
  f32 v44;
  f32 v45;
  struct tagPipePosData_array *v48;
  s64 v49;
  f32 v50;
  f32 v51;
  f32 v53;
  struct tagPipePosData_array *v55;
  s64 v56;
  struct tagPipePosData_array *v59;
  s64 v60;
  f32 v61;
  f32 v62;
  struct tagPipePosData_array *v65;
  s64 v66;
  f32 v67;
  f32 v68;
  f32 v70;
  s32 v74;
  f32 v75;
  struct tagPipePosData_array *v76;
  struct tagPipePosData_array *v79;
  s64 v80;
  struct tagPipePosData_array *v83;
  s64 v84;
  struct tagPipePosData_array *v87;
  s64 v88;
  struct tagPipePosData_array *v91;
  s64 v92;
  struct tagPipePosData_array *v95;
  s64 v96;
  struct tagPipePosData_array *v99;
  s64 v100;
  struct tagPipePosData_array *v103;
  s64 v104;
  struct tagPipePosData_array *v107;
  s64 v108;
  struct UnityEngine_Vector4_o *p_pipeVertical;
  struct tagPipePosData_array *v112;
  s64 v113;
  struct tagPipePosData_array *v116;
  s64 v117;
  struct tagPipePosData_array *v120;
  s64 v121;
  struct tagPipePosData_array *v124;
  s64 v125;
  struct tagPipePosData_array *v128;
  s64 v129;
  struct tagPipePosData_array *v132;
  s64 v133;
  UnityEngine_Vector4_o v135;
  u64 v136[2];
  UnityEngine_Vector4_o v137;
  UnityEngine_Vector4_o pVec;
  u64 v139[2];

  *&v135.x = 0;
  *&v135.z = 0;
  v139[0] = 0;
  v139[1] = 0;
  *&pVec.x = 0;
  *&pVec.z = 0;
  *&v137.x = 0;
  *&v137.z = 0;
  v136[0] = 0;
  v136[1] = 0;
  v2 = objMyData();
  *&v135.x = 0;
  *&v135.z = 0;
  if (v2)
  {
    v4 = v2;
    getPosTranslate(v4, &v135);
    sub_854710(&v135, 0);
    pData = PosTable->pData;
    sub_854710(&pData->m_Items[offsetCount]->fields, 0);
    sub_854930(v139, 0);
    sub_854710(&v135, 1u);
    v12 = PosTable->pData;
    v13 = offsetCount;
    sub_854710(&v12->m_Items[v13]->fields, 1u);
    sub_854930(v139, 1u);
    sub_854710(&v135, 2u);
    v16 = PosTable->pData;
    v17 = offsetCount;
    sub_854710(&v16->m_Items[v17]->fields, 2u);
    sub_854930(v139, 2u);
    v20 = PosTable->pData;
    v21 = offsetCount + 10LL;
    sub_854710(&v20->m_Items[v21]->fields, 0);
    v24 = PosTable->pData;
    v25 = offsetCount;
    v27 = v26;
    sub_854710(&v24->m_Items[v25]->fields, 0);
    v30 = PosTable->pData;
    v31 = offsetCount + 10LL;
    v33 = v32;
    sub_854710(&v30->m_Items[v31]->fields, 1u);
    v36 = PosTable->pData;
    v37 = offsetCount;
    v39 = v38;
    sub_854710(&v36->m_Items[v37]->fields, 1u);
    v42 = PosTable->pData;
    v43 = offsetCount + 10LL;
    v45 = v44;
    sub_854710(&v42->m_Items[v43]->fields, 2u);
    v48 = PosTable->pData;
    v49 = offsetCount;
    v51 = v50;
    sub_854710(&v48->m_Items[v49]->fields, 2u);
    SetVec(&pVec, v27 - v33, v39 - v45, v51 - v53);
    v55 = PosTable->pData;
    v56 = offsetCount;
    sub_854710(&v55->m_Items[v56]->up, 0);
    v59 = PosTable->pData;
    v60 = offsetCount;
    v62 = v61;
    sub_854710(&v59->m_Items[v60]->up, 1u);
    v65 = PosTable->pData;
    v66 = offsetCount;
    v68 = v67;
    sub_854710(&v65->m_Items[v66]->up, 2u);
    SetVec(&v137, v62, v68, v70);
    VecNormalize(&pVec);
    VecZoom(&pVec, -600.0);
    v74 = offsetCount;
    if (v74 <= 339)
    {
      v112 = PosTable->pData;
      v113 = offsetCount;
      sub_854710(&v112->m_Items[v113]->fields, 0);
      sub_854930(&pipeTargetPos, 0);
      v116 = PosTable->pData;
      v117 = offsetCount;
      sub_854710(&v116->m_Items[v117]->fields, 1u);
      sub_854930(&pipeTargetPos, 1u);
      v120 = PosTable->pData;
      v121 = offsetCount;
      sub_854710(&v120->m_Items[v121]->fields, 2u);
      sub_854930(&pipeTargetPos, 2u);
      VecNormalize(&v137);
      VecZoom(&v137, 600.0);
      v124 = PosTable->pData;
      v125 = offsetCount;
      sub_854710(&v124->m_Items[v125]->fields, 0);
      sub_854710(&v137, 0);
      sub_854930(&pipeCameraPos, 0);
      v128 = PosTable->pData;
      v129 = offsetCount;
      sub_854710(&v128->m_Items[v129]->fields, 1u);
      sub_854710(&v137, 1u);
      sub_854930(&pipeCameraPos, 1u);
      v132 = PosTable->pData;
      v133 = offsetCount;
      sub_854710(&v132->m_Items[v133]->fields, 2u);
      sub_854710(&v137, 2u);
      sub_854930(&pipeCameraPos, 2u);
      sub_854930(&pipeVertical, 0);
      sub_854930(&pipeVertical, 1u);
      p_pipeVertical = &pipeVertical;
      goto LABEL_86;
    }
    if (v74 <= 799)
    {
      v75 = (v74 - 340);
      v76 = PosTable->pData;
      sub_854710(&v76->m_Items[v74]->fields, 0);
      sub_854710(v139, 0);
      sub_854930(&pipeTargetPos, 0);
      v79 = PosTable->pData;
      v80 = offsetCount;
      sub_854710(&v79->m_Items[v80]->fields, 1u);
      sub_854710(v139, 1u);
      sub_854930(&pipeTargetPos, 1u);
      v83 = PosTable->pData;
      v84 = offsetCount;
      sub_854710(&v83->m_Items[v84]->fields, 2u);
      sub_854710(v139, 2u);
      sub_854930(&pipeTargetPos, 2u);
      VecNormalize(&v137);
      VecZoom(&v137, ((v75 / 460.0) * -650.0) + 600.0, 0);
      v87 = PosTable->pData;
      v88 = offsetCount;
      sub_854710(&v87->m_Items[v88]->fields, 0);
      sub_854710(&v137, 0);
      sub_854710(&pVec, 0);
      sub_854930(v136, 0);
      v91 = PosTable->pData;
      v92 = offsetCount;
      sub_854710(&v91->m_Items[v92]->fields, 1u);
      sub_854710(&v137, 1u);
      sub_854710(&pVec, 1u);
      sub_854930(v136, 1u);
      v95 = PosTable->pData;
      v96 = offsetCount;
      sub_854710(&v95->m_Items[v96]->fields, 2u);
      sub_854710(&v137, 2u);
      sub_854710(&pVec, 2u);
      sub_854930(v136, 2u);
      sub_854710(v136, 0);
      sub_854930(&pipeCameraPos, 0);
      sub_854710(v136, 1u);
      sub_854930(&pipeCameraPos, 1u);
      sub_854710(v136, 2u);
      sub_854930(&pipeCameraPos, 2u);
      v99 = PosTable->pData;
      v100 = offsetCount;
      sub_854710(&v99->m_Items[v100]->up, 0);
      sub_854930(&pipeVertical, 0);
      v103 = PosTable->pData;
      v104 = offsetCount;
      sub_854710(&v103->m_Items[v104]->up, 1u);
      sub_854930(&pipeVertical, 1u);
      v107 = PosTable->pData;
      v108 = offsetCount;
      sub_854710(&v107->m_Items[v108]->up, 2u);
      p_pipeVertical = &pipeVertical;
LABEL_86:
      sub_854930(p_pipeVertical, 2u);
    }
  }
}

// 0x14b6d40
void PipeCameraAction3(void) {
  s64 offsetCount;
  tagPipeObject_o *v4;
  tagPipeObject_o *v6;
  struct tagPipePosData_array *pData;
  struct tagPipePosData_array *v11;
  struct tagPipePosData_array *v13;
  struct tagPipePosData_array *v15;
  s64 v16;
  struct tagPipePosData_array *v18;
  f32 v19;
  f32 v20;
  struct tagPipePosData_array *v22;
  f32 v23;
  f32 v24;
  struct tagPipePosData_array *v26;
  f32 v27;
  f32 v28;
  struct tagPipePosData_array *v30;
  f32 v31;
  f32 v32;
  struct tagPipePosData_array *v34;
  f32 v35;
  f32 v36;
  f32 v38;
  struct tagPipePosData_array *v39;
  struct tagPipePosData_array *v41;
  f32 v42;
  f32 v43;
  struct tagPipePosData_array *v45;
  f32 v46;
  f32 v47;
  f32 v49;
  f32 *p_pos;
  f32 v52;
  f32 v53;
  f32 v55;
  f32 v56;
  f32 v57;
  f32 v58;
  f32 v60;
  f32 v61;
  struct UnityEngine_Vector4_o *p_pipeCameraPos;
  struct tagPipePosData_array *v66;
  struct tagPipePosData_array *v68;
  struct tagPipePosData_array *v70;
  f32 v72;
  f32 v73;
  f32 v74;
  f32 v76;
  s32 v77;
  struct tagPipePosData_array *v79;
  struct tagPipePosData_array *v81;
  struct tagPipePosData_array *v83;
  UnityEngine_Vector4_o v86;
  UnityEngine_Vector4_o pos;
  UnityEngine_Vector4_o v88;
  UnityEngine_Vector4_o pVec;
  u64 v90[2];

  *&pos.x = 0;
  *&pos.z = 0;
  *&v86.x = 0;
  *&v86.z = 0;
  v90[0] = 0;
  v90[1] = 0;
  *&pVec.x = 0;
  *&pVec.z = 0;
  *&v88.x = 0;
  *&v88.z = 0;
  v4 = objMyData();
  *&pos.x = 0;
  *&pos.z = 0;
  *&v86.x = 0;
  *&v86.z = 0;
  if (v4)
  {
    v6 = v4;
    getPosTranslate(v6, &pos);
    sub_854710(&pos, 0);
    pData = PosTable->pData;
    sub_854710(&pData->m_Items[offsetCount]->fields, 0);
    sub_854930(v90, 0);
    sub_854710(&pos, 1u);
    v11 = PosTable->pData;
    sub_854710(&v11->m_Items[offsetCount]->fields, 1u);
    sub_854930(v90, 1u);
    sub_854710(&pos, 2u);
    v13 = PosTable->pData;
    sub_854710(&v13->m_Items[offsetCount]->fields, 2u);
    sub_854930(v90, 2u);
    v15 = PosTable->pData;
    v16 = offsetCount + 10;
    sub_854710(&v15->m_Items[v16]->fields, 0);
    v18 = PosTable->pData;
    v20 = v19;
    sub_854710(&v18->m_Items[offsetCount]->fields, 0);
    v22 = PosTable->pData;
    v24 = v23;
    sub_854710(&v22->m_Items[v16]->fields, 1u);
    v26 = PosTable->pData;
    v28 = v27;
    sub_854710(&v26->m_Items[offsetCount]->fields, 1u);
    v30 = PosTable->pData;
    v32 = v31;
    sub_854710(&v30->m_Items[v16]->fields, 2u);
    v34 = PosTable->pData;
    v36 = v35;
    sub_854710(&v34->m_Items[offsetCount]->fields, 2u);
    SetVec(&pVec, v20 - v24, v28 - v32, v36 - v38);
    v39 = PosTable->pData;
    sub_854710(&v39->m_Items[offsetCount]->up, 0);
    v41 = PosTable->pData;
    v43 = v42;
    sub_854710(&v41->m_Items[offsetCount]->up, 1u);
    v45 = PosTable->pData;
    v47 = v46;
    sub_854710(&v45->m_Items[offsetCount]->up, 2u);
    SetVec(&v88, v43, v47, v49);
    sub_854710(&pos, 0);
    sub_854930(&pipeTargetPos, 0);
    sub_854710(&pos, 1u);
    sub_854930(&pipeTargetPos, 1u);
    sub_854710(&pos, 2u);
    sub_854930(&pipeTargetPos, 2u);
    VecNormalize(&pVec);
    VecZoom(&pVec, -600.0);
    if (offsetCount <= 479)
    {
      VecNormalize(&v88);
      VecZoom(&v88, -400.0);
      v66 = PosTable->pData;
      sub_854710(&v66->m_Items[480]->fields, 0);
      sub_854710(&pVec, 0);
      sub_854710(&v88, 0);
      sub_854930(&pipeCameraPos, 0);
      v68 = PosTable->pData;
      sub_854710(&v68->m_Items[480]->fields, 1u);
      sub_854710(&pVec, 1u);
      sub_854710(&v88, 1u);
      sub_854930(&pipeCameraPos, 1u);
      v70 = PosTable->pData;
      sub_854710(&v70->m_Items[480]->fields, 2u);
      sub_854710(&pVec, 2u);
      sub_854710(&v88, 2u);
      sub_854930(&pipeCameraPos, 2u);
      v72 = 0.0;
    }
    else
    {
      if (offsetCount > 679)
      {
        if (offsetCount > 799)
          return;
        p_pos = &v6->pos;
        v52 = (((offsetCount - 680) / 120.0) * 50.0) + -100.0;
        v53 = sub_851730(p_pos, 0);
        v55 = sub_851730(p_pos, 0);
        v56 = sdfSqrt(250000.0 - (v53 * v55), 0);
        v57 = sdfFabs(-50.0);
        v58 = sub_851730(p_pos, 1);
        if ((v56 + v57) < sdfFabs(v52 + v58))
        {
          v60 = sdfFabs(-50.0);
          v61 = sub_851730(p_pos, 1);
          v52 = -((v56 + v60) - sdfFabs(v61));
        }
        VecNormalize(&v88);
        VecZoom(&v88, v52);
        sub_854710(&pos, 0);
        sub_854710(&pVec, 0);
        sub_854710(&v88, 0);
        sub_854930(&pipeCameraPos, 0);
        sub_854710(&pos, 1u);
        sub_854710(&pVec, 1u);
        sub_854710(&v88, 1u);
        sub_854930(&pipeCameraPos, 1u);
        sub_854710(&pos, 2u);
        sub_854710(&pVec, 2u);
        sub_854710(&v88, 2u);
        p_pipeCameraPos = &pipeCameraPos;
        goto LABEL_88;
      }
      v73 = (offsetCount - 480);
      v74 = 1.0 - (((v73 / -200.0) + 1.0) * ((v73 / -200.0) + 1.0));
      VecNormalize(&v88);
      VecZoom(&v88, (v74 * 300.0) + -400.0, 0);
      v76 = (v74 * v73) + 480.0;
      v77 = v76;
      v79 = PosTable->pData;
      sub_854710(&v79->m_Items[v77]->fields, 0);
      sub_854710(&pVec, 0);
      sub_854710(&v88, 0);
      sub_854930(&pipeCameraPos, 0);
      v81 = PosTable->pData;
      sub_854710(&v81->m_Items[v77]->fields, 1u);
      sub_854710(&pVec, 1u);
      sub_854710(&v88, 1u);
      sub_854930(&pipeCameraPos, 1u);
      v83 = PosTable->pData;
      sub_854710(&v83->m_Items[v77]->fields, 2u);
      sub_854710(&pVec, 2u);
      sub_854710(&v88, 2u);
      sub_854930(&pipeCameraPos, 2u);
      v72 = v74 * 1.5708;
    }
    sub_854930(&v86, 0);
    sub_854930(&v86, 1u);
    sub_854930(&v86, 2u);
    VecRotateX(&v86, v72);
    sub_854710(&v86, 0);
    sub_854930(&pipeVertical, 0);
    sub_854710(&v86, 1u);
    sub_854930(&pipeVertical, 1u);
    sub_854710(&v86, 2u);
    p_pipeCameraPos = &pipeVertical;
LABEL_88:
    sub_854930(p_pipeCameraPos, 2u);
  }
}

// 0x14b8050
void SetCamera(void) {
  UnityEngine_Object_o *pipeCameraObj;
  UnityEngine_GameObject_o *v5;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  pipeCamera_c *v10;
  f32 v11;
  f32 v12;
  f32 v13;
  UnityEngine_Transform_o *transform;
  f32 v17;
  f32 w;
  f32 x;
  f32 y;
  f32 v22;
  f32 v23;
  f32 v24;
  UnityEngine_Transform_o *v25;
  UnityEngine_Transform_o *v26;
  UnityEngine_Vector4_o zero;
  UnityEngine_Vector4_o campos;
  UnityEngine_Vector3_o v29;
  UnityEngine_Vector3_o v30;
  UnityEngine_Vector3_o v31;
  UnityEngine_Vector4_o v32;

  *&campos.x = 0;
  *&campos.z = 0;
  *&zero.x = 0;
  *&zero.z = 0;
  if (!op_Equality(pipeCameraObj, 0, 0))
  {
      goto LABEL_17;
    goto LABEL_14;
  }
  v5 = Find("Main Camera", 0);
  gameObject = get_gameObject(v5);
  pipeCameraObj = gameObject;
  Component_object = GetComponent_object_(pipeCameraObj);
  pipeCameraCtrl = Component_object;
  if ((v10->_2.bitflags2 & 2) != 0)
  {
LABEL_14:
  }
LABEL_17:
  campos = get_zero();
  zero = get_zero();
  dds3CameraObjectBasicGetTgtCam(&pipe_Camera, &zero, &campos);
  v11 = campos.x / 100.0;
  v12 = campos.y / -100.0;
  v13 = campos.z / 100.0;
  transform = get_transform(pipeCameraObj, 0);
  v29.x = v11;
  v29.y = v12;
  v29.z = v13;
  set_localPosition(transform, v29);
  set_fieldOfView(
    pipeCameraCtrl,
    (dds3ScreenParam->fovy * 360.0) / 6.2832,
    0);
  v17 = zero.y / -100.0;
  w = pipeVertical.w;
  x = pipeVertical.x;
  y = pipeVertical.y;
  v22 = -pipeVertical.z;
  v23 = zero.x / 100.0;
  v24 = zero.z / 100.0;
  v25 = get_transform(pipeCameraObj, 0);
  v32.x = x;
  v32.y = y;
  v32.z = v22;
  v32.w = w;
  v26 = v25;
  v31 = op_Implicit_8738992(v32);
  v30.x = v23;
  v30.y = v17;
  v30.z = v24;
  LookAt_27488480(v26, v30, v31);
}

// 0x14b45c0
void getViewPortMatrix(sdfMatrix4_t **mat) {
  f32 *static_fields;
  f32 v5;
  f32 v6;
  f32 v7;
  f32 v8;
  u64 *v9;
  s32 v10;
  sdfMatrix4_t_o *v11;
  f32 v12;
  sdfMatrix4_t_o *v13;
  f32 v14;
  sdfMatrix4_t_o *v15;
  f32 v16;
  sdfMatrix4_t_o *v17;
  f32 v18;
  sdfMatrix4_t_o *v19;
  f32 v20;
  sdfMatrix4_t_o *v21;
  f32 v22;
  sdfMatrix4_t_o *v23;
  f32 v24;
  sdfMatrix4_t_o *v25;
  f32 v26;
  sdfMatrix4_t_o *v27;
  sdfMatrix4_t_o *v28;
  sdfMatrix4_t_o *v29;
  UnityEngine_Vector4_o v30;
  UnityEngine_Vector4_o pVec;
  UnityEngine_Vector4_o vec;
  UnityEngine_Vector4_o v33;
  UnityEngine_Vector4_o v34;
  UnityEngine_Vector4_o v35;

  *&vec.x = 0;
  *&vec.z = 0;
  *&pVec.x = 0;
  *&pVec.z = 0;
  *&v30.x = 0;
  *&v30.z = 0;
  v5 = static_fields[12];
  static_fields += 12;
  v6 = static_fields[1];
  v7 = static_fields[2];
  v8 = static_fields[3];
  sub_854710(static_fields, 0);
  sub_854710(&pipeCameraPos, 0);
  sub_854930(&v30, 0);
  sub_854710(&pipeTargetPos, 1u);
  sub_854710(&pipeCameraPos, 1u);
  sub_854930(&v30, 1u);
  sub_854710(&pipeTargetPos, 2u);
  sub_854710(&pipeCameraPos, 2u);
  sub_854930(&v30, 2u);
  VecNormalize(&v30);
  Veccross(&vec, pipeVertical, v30);
  VecNormalize(&vec);
  Veccross(&pVec, v30, vec);
  VecNormalize(&pVec);
  v9 = Allocate(sdfMatrix4_t);
  sdfMatrix4_t___ctor(v9);
  *mat = v9;
  sub_854710(&vec, 0);
  *(v9 + 4) = v10;
  v11 = *mat;
  sub_854710(&vec, 1u);
  v11->pm.m10 = v12;
  v13 = *mat;
  sub_854710(&vec, 2u);
  v13->pm.m20 = v14;
  v15 = *mat;
  sub_854710(&pVec, 0);
  v15->pm.m01 = v16;
  v17 = *mat;
  sub_854710(&pVec, 1u);
  v17->pm.m11 = v18;
  v19 = *mat;
  sub_854710(&pVec, 2u);
  v19->pm.m21 = v20;
  v21 = *mat;
  sub_854710(&v30, 0);
  v21->pm.m02 = v22;
  v23 = *mat;
  sub_854710(&v30, 1u);
  v23->pm.m12 = v24;
  v25 = *mat;
  sub_854710(&v30, 2u);
  v25->pm.m22 = v26;
  v27 = *mat;
  v33.x = v5;
  v33.y = v6;
  v33.z = v7;
  v33.w = v8;
  v27->pm.m30 = -Vecdot(vec, v33);
  v28 = *mat;
  v34.x = v5;
  v34.y = v6;
  v34.z = v7;
  v34.w = v8;
  v28->pm.m31 = -Vecdot(pVec, v34);
  v29 = *mat;
  v35.x = v5;
  v35.y = v6;
  v35.z = v7;
  v35.w = v8;
  v29->pm.m32 = -Vecdot(v30, v35);
  (*mat)->pm.m33 = 1.0;
}

// 0x14b8520
s8 pipeCamGetMode(s32 mapIdx, s32 prevArea) {
  s8 result;
  bool v5;

  result = 1;
  switch (prevArea)
  {
    case ')':
      return mapIdx == 1;
    case '*':
      v5 = mapIdx < 4;
      goto LABEL_7;
    case '+':
      v5 = mapIdx < 6;
      goto LABEL_7;
    case ',':
      v5 = mapIdx < 8;
LABEL_7:
      result = v5;
      break;
    case '-':
      return result;
    default:
      result = 0;
      break;
  }
  return result;
}
