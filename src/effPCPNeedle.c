#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct dds3EffectPCPData_t dds3EffectPCPData_t;
typedef struct dds3NeedleModel_tag dds3NeedleModel_tag;
typedef struct dds3TrackPoly_t dds3TrackPoly_t;
typedef struct effPCPNeedleSpiralParam_t effPCPNeedleSpiralParam_t;
typedef struct effPCPNeedleSpiral_tag effPCPNeedleSpiral_tag;
typedef struct nbFormation_t nbFormation_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfMat_t sdfMat_t;

static sdf3DPrimPolyParm_t *NM_PrimPolyParm;

f32 DDS3EFFECT_RAND_F(void);
f32 DDS3EFFECT_RAND_FA(f32 r);
u32 DDS3EFFECT_RAND_I(void);
sdfColor_t **GetColor(XRD773Unity_CommonMesh *this);
s32 **GetIndexTable(XRD773Unity_CommonMesh *this);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
sdfVector3_t **GetPosition(XRD773Unity_CommonMesh *this);
void LookAtMatrix(sdfVector4_t aTarget, sdfVector4_t aEye, sdfVector4_t aDown);
void ReverseMatrix(void);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__APPLYMATRIX_XYZ(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_A(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__STOREVECTOR_B(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SDF_VU0__SUBVECTOR_B_A(void);
void SDF_VU0__SWAPVECTOR_A_C(void);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
void SetRotateMatrixAxis(f32 aAngle, sdfVector4_t aAxis);
void *dds3EffectPCPDataGetDataUnityOffSet(void *hData, s32 offset, s32 type);
void dds3EffectPCPData_t__pCopy(dds3EffectPCPData_t *this, u8 **bytedata, s32 *pos);
dds3NeedleModel_tag *dds3NeedleModelCreate(u32 number);
void dds3NeedleModelDelete(dds3NeedleModel_tag *hNModel);
void dds3NeedleModelDraw(dds3NeedleModel_tag *hNModel);
void dds3NeedleModelGetPosition(dds3NeedleModel_tag *hNModel, u32 index, sdfVector4_t *pPos);
void dds3NeedleModelSetPosition(dds3NeedleModel_tag **hNModel, u32 index, sdfVector4_t pPos);
void dds3NeedleModelVNCListCreate(dds3NeedleModel_tag **hNModel, u32 split, f32 radius, f32 length, u32 abgr_in, u32 abgr_out);
void dds3TrackPolyColorSet(dds3TrackPoly_t **hTrackPoly, s32 number, u32 color);
dds3TrackPoly_t *dds3TrackPolyCreate(s32 number, s32 face, s32 rec, s32 type);
void dds3TrackPolyDelete(dds3TrackPoly_t **hTrackPoly);
void dds3TrackPolyDraw(dds3TrackPoly_t **hTrackPoly, char *funcname);
void dds3TrackPolyListInit(dds3TrackPoly_t **hTrackPoly, s32 number);
void dds3TrackPolySet(dds3TrackPoly_t **hTrackPoly, s32 number, sdfVector4_t **pV);
void dds3TrackPolySetMode(dds3TrackPoly_t **hTrackPoly, u16 mode);
void dds3TrackPolyVCRefresh_ParType1(dds3TrackPoly_t **hTrackPoly, u32 index);
void dds3TrackPolyVCSet(dds3TrackPoly_t **hTrackPoly, s32 type, u32 abgr_in, u32 abgr_out);
void effBTLModelGetSphereCenter(nbFormation_t **pFormation);
s32 effBTLSkillCheckRun(void);
nbFormation_t *effBTLSkillGetInvokeFormation(s32 idx);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
sdfColor_t effGetBlendColor(u32 icol);
sdfColor_t effGetVertexColor(u32 icol, sdfColor_t blend_col);
effPCPNeedleSpiral_tag *effPCPNeedleSpiralCreate(effPCPNeedleSpiralParam_t *pParam);
void effPCPNeedleSpiralParam_t__pClone(effPCPNeedleSpiralParam_t *this, effPCPNeedleSpiralParam_t **param);
f32 sdfCos(f32 aRadius);
sdfMat_t *sdfMatNew(void);
void sdfMatSetConstant(sdfMat_t *aMat, f32 aRatio);
f32 sdfSin(f32 aRadius);

// 0x1758db0
dds3NeedleModel_tag *dds3NeedleModelCreate(u32 number) {
  dds3NeedleModel_tag_o *v3;
  s64 v4;
  struct System_Single_array *v5;
  struct System_Single_array *scale;
  struct System_Single_array *v9;
  sdfMat_t_o *v12;
  u64 v14;
  u32 *pPart;
  u64 *v17;
  struct dds3NeedleModelPart_tag_array *v19;
  Il2CppClass **v21;

  v3 = Allocate(dds3NeedleModel_tag);
  _ctor(v3, 0);
  v4 = number;
  v3->pPart = NewSpecific(dds3NeedleModelPart_tag, number);
  v3->number = number;
  v3->blend = 2;
  v5 = NewSpecific(f32, 3u);
  v3->scale = v5;
  v5->m_Items[0] = 1.0;
  scale = v3->scale;
  scale->m_Items[1] = 1.0;
  v9 = v3->scale;
  v9->m_Items[2] = 1.0;
  v3->hVNMem = 0;
  v3->hMem = 0;
  SDF_VU0__STOREIDENTITY(&v3->matrix);
  v12 = sdfMatNew();
  v3->pMat = v12;
  sdfMatSetConstant(v12, 1.0);
  if (number)
  {
    v14 = 0;
    do
    {
      pPart = v3->pPart;
      v17 = Allocate(dds3NeedleModelPart_tag);
      _ctor(v17, 0);
      *&pPart[2 * v14 + 8] = v17;
      v19 = v3->pPart;
      v21 = &v19->obj.klass + v14++;
      LODWORD(v21[4]->_1.byval_arg.data) = -2139062144;
    }
    while (v4 != v14);
  }
  NM_PrimPolyParm->attr = 0x4000;
  return v3;
}

// 0x1759020
void dds3NeedleModelDelete(dds3NeedleModel_tag *hNModel) {
  Il2CppObject *hVNMem;
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v6;
  u64 v7;
  UnityEngine_Object_o *v9;
  struct XRD773Unity_CommonMesh_array *v10;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v14;
  s64 v16;

LABEL_7:
  hVNMem = hNModel->hVNMem;
  if (hVNMem)
  {
    Write_2930400("dds3NeedleModelVNCListDelete[%p] ****\n", hVNMem);
  }
  pMesh = hNModel->pMesh;
  if (pMesh)
  {
    max_length = pMesh->max_length;
    if (max_length >= 1)
    {
      v6 = 4;
      do
      {
        v7 = v6 - 4;
        v9 = *(&pMesh->obj.klass + v6);
        if (op_Inequality(v9, 0, 0))
        {
          v10 = hNModel->pMesh;
          gameObject = get_gameObject(*(&v10->obj.klass + v6), 0);
          Destroy_27360000(gameObject);
          v14 = hNModel->pMesh;
          *(&v14->obj.klass + v6) = 0;
        }
        pMesh = hNModel->pMesh;
        LODWORD(max_length) = pMesh->max_length;
        v16 = v6 - 3;
        ++v6;
      }
      while (v16 < max_length);
    }
    hNModel->pMesh = 0;
  }
}

// 0x17593b0
void dds3NeedleModelDraw(dds3NeedleModel_tag *hNModel) {
  f32 *p_SDF_CC_NDNM;
  struct System_Single_array *scale;
  f32 v6;
  f32 v7;
  f32 v8;
  u32 max_length;
  f32 v10;
  f32 v12;
  f32 v13;
  struct XRD773Unity_CommonMesh_array *v16;
  struct XRD773Unity_CommonMesh_array *v18;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v21;
  struct XRD773Unity_CommonMesh_array *pMesh;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  System_String_o *v25;
  struct XRD773Unity_CommonMesh_array *v26;
  u64 *v28;
  u64 *v29;
  u64 v30;
  s32 v31;
  char *v32;
  struct dds3NeedleModelPart_tag_array *pPart;
  u32 abgr;
  struct XRD773Unity_CommonMesh_array *v39;
  u32 v40;
  struct XRD773Unity_CommonMesh_array *v42;
  XRD773Unity_CommonMesh_o *v44;
  u64 v45;
  UnityEngine_Vector3_array *v46;
  struct XRD773Unity_CommonMesh_array *v47;
  XRD773Unity_CommonMesh_o *v49;
  UnityEngine_Color_array *v50;
  struct XRD773Unity_CommonMesh_array *v51;
  XRD773Unity_CommonMesh_o *v53;
  System_Int32_array *v54;
  struct XRD773Unity_CommonMesh_array *v55;
  UnityEngine_Vector3_array *Position;
  struct XRD773Unity_CommonMesh_array *v58;
  UnityEngine_Color_array *Color;
  struct XRD773Unity_CommonMesh_array *v61;
  System_Int32_array *IndexTable;
  u64 v65;
  s32 v66;
  System_Int32_array *v67;
  f32 *v68;
  f32 v69;
  struct dds3NeedleModelPart_tag_array *v71;
  f32 v72;
  f32 v73;
  f32 v74;
  f32 *v76;
  f32 v77;
  f32 v78;
  f32 v79;
  f32 v80;
  f32 *v83;
  f32 v84;
  f32 v85;
  f32 v86;
  s32 *v87;
  u64 v88;
  Il2CppObject *v89;
  s32 v90;
  u32 *p_z;
  s64 v92;
  struct UnityEngine_Vector4_array *pVertex;
  f32 *v95;
  f32 v96;
  f32 v97;
  f32 v98;
  f32 v99;
  long f64 v100;
  long f64 v101;
  s32 v102;
  s32 v103;
  u32 v104;
  dds3NeedleModel_tag_o *v106;
  struct System_UInt32_array *pVC;
  u32 v109;
  il2cpp_array_size_t v112;
  s64 v113;
  s64 v114;
  struct XRD773Unity_CommonMesh_array *v116;
  s32 *m_Items;
  u64 *v123;
  f32 y;
  u64 v125;
  s32 a;
  UnityEngine_Vector3_array *a_8;
  UnityEngine_Color_array *v129;
  s64 point;
  UnityEngine_Matrix4x4_o v131;
  UnityEngine_Matrix4x4_o v132;
  UnityEngine_Matrix4x4_o v133;
  UnityEngine_Matrix4x4_o v134;
  UnityEngine_Matrix4x4_o v135;
  UnityEngine_Vector3_o v136;
  UnityEngine_Matrix4x4_o v137;
  UnityEngine_Vector3_o v138;
  UnityEngine_Vector3_o v139;
  UnityEngine_Vector3_o v140;
  UnityEngine_Vector4_o v141;
  UnityEngine_Color_o VertexColor;
  UnityEngine_Vector3_o v143;
  UnityEngine_Vector3_o v144;
  UnityEngine_Vector3_o v145;
  UnityEngine_Vector3_o v146;
  UnityEngine_Vector4_o v147;
  UnityEngine_Vector4_o v148;
  UnityEngine_Vector4_o v149;
  UnityEngine_Color_o BlendColor;
  UnityEngine_Color_o v151;

  memset(&v137, 0, sizeof(v137));
  p_SDF_CC_NDNM = &SDF_CC_NDNM;
  scale = hNModel->scale;
  v6 = p_SDF_CC_NDNM[41];
  v7 = p_SDF_CC_NDNM[42];
  v8 = p_SDF_CC_NDNM[43];
  max_length = scale->max_length;
  v10 = scale->m_Items[0];
  v12 = scale->m_Items[2];
  v13 = scale->m_Items[1];
  v136.z = 0.0;
  *&v136.x = 0;
  sub_8524C0(&v136.x, v10, v13, v12);
  v143.x = v6;
  v143.y = v7;
  v143.z = v8;
  v138 = Scale(v143, v136);
  Scale(&v135, v138);
  sub_19FF440(&hNModel->fields, 0, &v134);
  v132 = v135;
  v131 = v134;
  op_Multiply(&v133, &v132, &v131, 0);
  v137 = v133;
  if (!hNModel->pMesh)
  {
    v16 = NewSpecific(XRD773Unity_CommonMesh, 1u);
    hNModel->pMesh = v16;
    v18 = v16;
    {
    }
    Instance = get_Instance();
    Mesh = GetMesh(Instance, hNModel->blend, 0);
    v21 = Mesh;
    v18->m_Items[0] = v21;
    pMesh = hNModel->pMesh;
    gameObject = get_gameObject(pMesh->m_Items[0]);
    name = get_name(gameObject);
    v25 = Concat_5224608(name, ":dds3NeedleModelDraw:");
    set_name(gameObject, v25);
    v26 = hNModel->pMesh;
    SetAutoHide(v26->m_Items[0], 1);
  }
  point = hNModel->point;
  v28 = NewSpecific(UnityEngine_Vector4, hNModel->number);
  v29 = v28;
  if (hNModel->number)
  {
    v30 = 0;
    v31 = 0;
    v32 = v28 + 44;
    do
    {
      pPart = hNModel->pPart;
      abgr = pPart->m_Items[v30]->abgr;
      if (HIBYTE(abgr))
      {
        BlendColor = effGetBlendColor(abgr);
        v141 = op_Implicit(BlendColor, 0);
        ++v31;
        *(v32 - 12) = v141;
      }
      ++v30;
      v32 += 16;
    }
    while (v30 < hNModel->number);
  }
  else
  {
    v31 = 0;
  }
  v39 = hNModel->pMesh;
  v40 = v31 * point;
  if (v40 > SLODWORD(GetPosition(v39->m_Items[0])->max_length))
  {
    v42 = hNModel->pMesh;
    v44 = v42->m_Items[0];
    v45 = v40;
    v46 = NewSpecific(UnityEngine_Vector3, v40);
    SetPosition_20241056(v44, v46);
    v47 = hNModel->pMesh;
    v49 = v47->m_Items[0];
    v50 = NewSpecific(UnityEngine_Color, v45);
    SetColor_20241296(v49, v50);
    v51 = hNModel->pMesh;
    v53 = v51->m_Items[0];
    v54 = NewSpecific(s32, v45);
    SetIndexTable(v53, v54);
  }
  if (v31 >= 1)
  {
    v55 = hNModel->pMesh;
    Position = GetPosition(v55->m_Items[0]);
    v58 = hNModel->pMesh;
    a_8 = Position;
    Color = GetColor(v58->m_Items[0], 0);
    v61 = hNModel->pMesh;
    v129 = Color;
    IndexTable = GetIndexTable(v61->m_Items[0]);
    if (hNModel->number)
    {
      m_Items = IndexTable->m_Items;
      v123 = v29;
      v65 = 0;
      v66 = 0;
      v67 = IndexTable;
      do
      {
        while (1)
        {
          while (1)
          {
            v68 = &v29[2 * v65];
            v69 = v68[11];
            if (v69 > 0.0)
              break;
            if (++v65 >= hNModel->number)
              goto LABEL_96;
          }
          v71 = hNModel->pPart;
          v72 = v68[8];
          v73 = v68[9];
          v74 = v68[10];
          v76 = v71->m_Items[v65];
          v77 = v76[4];
          v78 = v76[5];
          v79 = v76[6];
          v80 = v76[7];
          v147.x = v77;
          v147.y = v78;
          v147.z = v79;
          v147.w = v80;
          v139 = op_Implicit_8738992(v147);
          v144.x = v139.x;
          v144.y = v139.y;
          v83 = &SDF_CC_NDNM;
          v85 = v83[41];
          v84 = v83[42];
          v86 = v83[43];
          v144.z = v139.z;
          v146.x = v85;
          v146.y = v84;
          v146.z = v86;
          v145 = Scale(v144, v146);
          op_Implicit(v145, 0);
          sub_1A009D0(&v137, 3);
          if (point >= 1)
            break;
          v29 = v123;
          if (++v65 >= hNModel->number)
            goto LABEL_96;
        }
        v87 = &m_Items[v66];
        v125 = v65;
        a = v66;
        v88 = 0;
        v89 = &v129->obj + v66;
        v90 = v66;
        p_z = &a_8->m_Items[v66].z;
        v92 = 0;
        do
        {
          pVertex = hNModel->pVertex;
          v95 = (pVertex + 1 * v92);
          v96 = v95[8];
          v97 = v95[9];
          v98 = v95[10];
          v99 = v95[11];
          v148.x = v96;
          v148.y = v97;
          v148.z = v98;
          v148.w = v99;
          v140 = op_Implicit_8738992(v148);
          v101 = sub_1A00CF0(&v137.m00, v140.x, v140.y, v140.z, v100);
          v104 = v90 + v88;
          *(p_z - 2) = LODWORD(v101);
          *(p_z - 1) = v102;
          *p_z = v103;
          v106 = hNModel;
          pVC = hNModel->pVC;
          v109 = pVC->m_Items[v92];
          v149.x = v72;
          v149.y = v73;
          v149.z = v74;
          v149.w = v69;
          v151 = op_Implicit_27186336(v149);
          VertexColor = effGetVertexColor(v109, v151);
          v89[v92 + 2] = VertexColor;
          hNModel = v106;
          ++v88;
          p_z += 3;
          v87[v92++] = v104;
        }
        while (point != v88);
        v66 = a + v88;
        v29 = v123;
        v65 = v125 + 1;
      }
      while (v125 + 1 < v106->number);
    }
    else
    {
      v67 = IndexTable;
      v66 = 0;
    }
LABEL_96:
    LODWORD(v112) = v67->max_length;
    if (v66 < v112)
    {
      v113 = v66;
      do
      {
        v114 = v113 + 1;
        v67->m_Items[v113] = 0;
        v112 = v67->max_length;
        ++v113;
      }
      while (v114 < v112);
    }
    v116 = hNModel->pMesh;
    SetActive(v116->m_Items[0], 1, 0);
  }
}

// 0x17592a0
void dds3NeedleModelDrawOff(dds3NeedleModel_tag *hNModel) {
  struct XRD773Unity_CommonMesh_array *pMesh;
  il2cpp_array_size_t max_length;
  s64 v5;
  UnityEngine_Object_o *v7;
  struct XRD773Unity_CommonMesh_array *v8;
  s64 v10;

  pMesh = hNModel->pMesh;
  if (pMesh)
  {
    max_length = pMesh->max_length;
    if (max_length >= 1)
    {
      v5 = 4;
      do
      {
        v7 = *(&pMesh->obj.klass + v5);
        if (op_Inequality(v7, 0, 0))
        {
          v8 = hNModel->pMesh;
          SetActive(*(&v8->obj.klass + v5), 0, 0);
        }
        pMesh = hNModel->pMesh;
        LODWORD(max_length) = pMesh->max_length;
        v10 = v5 - 3;
        ++v5;
      }
      while (v10 < max_length);
    }
  }
}

// 0x1759ee0
void dds3NeedleModelGetPosition(dds3NeedleModel_tag *hNModel, u32 index, sdfVector4_t *pPos) {
  struct dds3NeedleModelPart_tag_array *pPart;
  s64 v8;
  struct dds3NeedleModelPart_tag_array *v10;
  struct dds3NeedleModelPart_tag_array *v12;

  pPart = hNModel->pPart;
  v8 = index;
  sub_854710(&pPart->m_Items[index]->fields, 0);
  sub_854930(pPos, 0);
  v10 = hNModel->pPart;
  sub_854710(&v10->m_Items[v8]->fields, 1u);
  sub_854930(pPos, 1u);
  v12 = hNModel->pPart;
  sub_854710(&v12->m_Items[v8]->fields, 2u);
  sub_854930(pPos, 2u);
}

// 0x1759ff0
void dds3NeedleModelSetColor(dds3NeedleModel_tag **hNModel, u32 index, u32 abgr) {
  struct dds3NeedleModelPart_tag_array *pPart;

  pPart = (*hNModel)->pPart;
  pPart->m_Items[index]->abgr = abgr;
}

// 0x175a050
void dds3NeedleModelSetMatrix(dds3NeedleModel_tag **hNModel, sdfMatrix4_t *pMatrix) {
  s64 v3;
  s64 v4;
  s64 v6;
  s64 v7;
  s64 v8;
  s64 v9;
  UnityEngine_Matrix4x4_o v10;

  v3 = *&pMatrix->m00;
  v4 = *&pMatrix->m20;
  v6 = *&pMatrix->m21;
  *&v10.m01 = *&pMatrix->m01;
  *&v10.m21 = v6;
  *&v10.m00 = v3;
  *&v10.m20 = v4;
  v7 = *&pMatrix->m02;
  v8 = *&pMatrix->m22;
  v9 = *&pMatrix->m23;
  *&v10.m03 = *&pMatrix->m03;
  *&v10.m23 = v9;
  *&v10.m02 = v7;
  *&v10.m22 = v8;
  SDF_VU0__LOADMATRIX(&v10);
  SDF_VU0__STOREMATRIX(&(*hNModel)->matrix, 0);
}

// 0x1759db0
void dds3NeedleModelSetPosition(dds3NeedleModel_tag **hNModel, u32 index, sdfVector4_t pPos) {
  struct dds3NeedleModelPart_tag_array *pPart;
  s64 v7;
  s64 p_fields;
  struct dds3NeedleModelPart_tag_array *v10;
  s64 v12;
  struct dds3NeedleModelPart_tag_array *v13;
  s64 v15;
  UnityEngine_Vector4_o v16;

  v16 = pPos;
  pPart = (*hNModel)->pPart;
  v7 = index;
  p_fields = &pPart->m_Items[index]->fields;
  sub_854710(&v16, 0);
  sub_854930(p_fields, 0);
  v10 = (*hNModel)->pPart;
  v12 = &v10->m_Items[v7]->fields;
  sub_854710(&v16, 1u);
  sub_854930(v12, 1u);
  v13 = (*hNModel)->pPart;
  v15 = &v13->m_Items[v7]->fields;
  sub_854710(&v16, 2u);
  sub_854930(v15, 2u);
}

// 0x175a0b0
void dds3NeedleModelVNCListCreate(dds3NeedleModel_tag **hNModel, u32 split, f32 radius, f32 length, u32 abgr_in, u32 abgr_out) {
  dds3NeedleModel_tag_o *v11;
  u32 v12;
  Il2CppObject *hVNMem;
  u64 v14;
  struct UnityEngine_Vector4_array *v15;
  struct UnityEngine_Vector4_array *v16;
  struct System_UInt32_array *v17;
  u32 *v19;
  f32 v20;
  f32 v21;
  f32 v22;
  s64 v23;
  u64 v24;
  u32 v25;
  f32 v26;
  f32 v27;
  f32 v28;
  s32 v29;
  s32 v30;
  s32 v31;
  f32 *v33;
  f32 v34;
  s32 v35;
  s32 v36;
  s32 v37;
  char *v39;
  f32 v41;
  f32 v42;
  u64 v44;
  s32 v45;
  s32 v46;
  s32 v47;
  f32 v51;
  f32 v52;
  u64 v53;
  f32 v54;
  s32 v55;
  s32 v56;
  s32 v57;
  f32 v59;
  s32 v60;
  s32 v61;
  s32 v62;
  Il2CppObject *v65;
  dds3NeedleModel_tag_o **v66;
  f32 v67;
  f32 v68;
  u32 v70;
  struct System_UInt32_array *v72;
  struct UnityEngine_Vector4_array *v73;
  struct UnityEngine_Vector4_array *v74;
  s64 v75;
  s64 v76;
  s64 v77;
  s64 v78;
  s64 v79;
  s64 v80;
  s64 v81;
  s64 v82;
  s64 v83;
  s64 v84;
  UnityEngine_Vector4_o zero;

  v11 = *hNModel;
  if (split <= 3)
    v12 = 3;
  else
    v12 = split;
  v70 = v12;
  if (v11->hVNMem)
  {
    else if ((byte_3F5A5EC & 1) != 0)
    {
      goto LABEL_11;
    }
    goto LABEL_11;
  }
LABEL_16:
  v14 = 3 * v70;
  v15 = NewSpecific(UnityEngine_Vector4, v14);
  v16 = NewSpecific(UnityEngine_Vector4, v14);
  v17 = NewSpecific(uint, v14);
  (*hNModel)->pVertex = v15;
  (*hNModel)->pNormal = v16;
  (*hNModel)->pVC = v17;
  v74 = v15;
  v72 = v17;
  v66 = hNModel;
  (*hNModel)->point = v14;
  v19 = &v17->m_Items[2];
  v20 = v70;
  v21 = 0.0;
  v22 = -length;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v73 = v16;
  v67 = (6.2832 / v20) * 0.5;
  v68 = 6.2832 / v20;
  do
  {
    v26 = sdfCos(v21);
    v27 = sdfSin(v21);
    v83 = 0;
    v84 = 0;
    sub_854690(&v83, v26, v27, 0.0, 0.0);
    v28 = *&v83;
    v29 = HIDWORD(v83);
    v31 = v84;
    v30 = HIDWORD(v84);
    v33 = (v16 + v23 * 16);
    *(v33 + 8) = v83;
    *(v33 + 9) = v29;
    *(v33 + 10) = v31;
    *(v33 + 11) = v30;
    v34 = v16->m_Items[v23].y * radius;
    v81 = 0;
    v82 = 0;
    sub_854690(&v81, v28 * radius, v34, v22, 0.0);
    v35 = HIDWORD(v81);
    v37 = v82;
    v36 = HIDWORD(v82);
    v39 = v74 + v23 * 16;
    *(v39 + 8) = v81;
    *(v39 + 9) = v35;
    *(v39 + 10) = v37;
    *(v39 + 11) = v36;
    *(v19 - 2) = abgr_out;
    v41 = sdfCos(v67 + v21);
    v42 = sdfSin(v67 + v21);
    v79 = 0;
    v80 = 0;
    sub_854690(&v79, v41, v42, 0.0, 0.0);
    v44 = v24 + 1;
    v45 = HIDWORD(v79);
    v47 = v80;
    v46 = HIDWORD(v80);
    *(v33 + 12) = v79;
    *(v33 + 13) = v45;
    *(v33 + 14) = v47;
    *(v33 + 15) = v46;
    zero = get_zero();
    *(v39 + 3) = zero;
    v21 = v68 + v21;
    *(v19 - 1) = abgr_in;
    v51 = sdfCos(v21);
    v52 = sdfSin(v21);
    v77 = 0;
    v78 = 0;
    sub_854690(&v77, v51, v52, 0.0, 0.0);
    v53 = v44 + 1;
    v54 = *&v77;
    v55 = HIDWORD(v77);
    v56 = v78;
    v57 = HIDWORD(v78);
    *(v33 + 16) = v77;
    *(v33 + 17) = v55;
    *(v33 + 18) = v56;
    *(v33 + 19) = v57;
    v59 = v33[17] * radius;
    v75 = 0;
    v76 = 0;
    sub_854690(&v75, v54 * radius, v59, v22, 0.0);
    v60 = HIDWORD(v75);
    v62 = v76;
    v61 = HIDWORD(v76);
    *(v39 + 16) = v75;
    *(v39 + 17) = v60;
    *(v39 + 18) = v62;
    *(v39 + 19) = v61;
    ++v25;
    v16 = v73;
    v23 += 3;
    v24 = v53 + 1;
    *v19 = abgr_out;
    v19 += 3;
  }
  while (v25 < v70);
  v65 = (*v66)->hVNMem;
  Write_2930400("dds3NeedleModelVNCListCreate[%p] ****\n", v65);
}

// 0x1759210
void dds3NeedleModelVNCListDelete(dds3NeedleModel_tag *hNModel) {
  Il2CppObject *hVNMem;

  hVNMem = hNModel->hVNMem;
  if (hVNMem)
  {
    Write_2930400("dds3NeedleModelVNCListDelete[%p] ****\n", hVNMem);
  }
}

// 0x175af50
effPCPNeedleSpiral_tag *effPCPNeedleSpiralCopy(void **hData, s32 bPos, bool tbldata) {
  effPCPNeedleSpiral_tag_c *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppClass *v8;
  char *v10;
  s64 *v11;
  u64 v12[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPNeedleSpiral_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPNeedleSpiral_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v8 = (*hData)[1].klass;
  return effPCPNeedleSpiralCreate(v8, v5);
}

// 0x175a7f0
effPCPNeedleSpiral_tag *effPCPNeedleSpiralCreate(effPCPNeedleSpiralParam_t *pParam) {
  u64 *v3;
  u64 *v4;
  u32 number;
  u32 v7;
  dds3NeedleModel_tag_o *v8;
  struct System_UInt32_array *n_vc;
  u32 max_length;
  u32 v12;
  s32 v15;
  s32 v16;
  dds3TrackPoly_t_o *v17;
  u64 v18;
  s64 v19;
  u32 timing;
  u64 v21;
  s64 v22;
  f32 v23;
  f32 v24;
  s64 v25;
  u32 *v27;
  u64 v28;
  u64 *v29;
  u64 v32;
  s64 v34;
  u32 v35;
  s64 v37;
  s64 v39;

  v3 = Allocate(effPCPNeedleSpiral_tag);
  _ctor(v3, 0);
  v3[3] = NewSpecific(effPCPNeedleSpiralPart_tag, pParam->number);
  v4 = Allocate(effPCPNeedleSpiralParam_t);
  effPCPNeedleSpiralParam_t___ctor(v4);
  v3[2] = v4;
  effPCPNeedleSpiralParam_t__pClone(pParam, v3 + 2);
  number = pParam->number;
  v3[7] = 0;
  *(v3 + 8) = -2139062144;
  *(v3 + 9) = number;
  v3[5] = 0;
  v7 = pParam->number;
  v8 = dds3NeedleModelCreate(v7);
  v3[6] = v8;
  v8->blend = pParam->blend;
  n_vc = pParam->n_vc;
  max_length = n_vc->max_length;
  v12 = n_vc->m_Items[0];
  dds3NeedleModelVNCListCreate(v3 + 6, pParam->n_split, pParam->n_radius, pParam->n_length, v12, pParam->n_vc->m_Items[1]);
  v15 = *(v3 + 9);
  v16 = *(v3[2] + 100);
  v17 = dds3TrackPolyCreate(v15, v16, 0, 0);
  v18 = v3[2];
  v3[5] = v17;
  dds3TrackPolyVCSet(v3 + 5, 1, *(v18 + 104), *(v18 + 104), 0);
  dds3TrackPolySetMode(v3 + 5, *(v3[2] + 40), 0);
  v19 = *(v3 + 9);
  if (pParam->timing)
    timing = pParam->timing;
  else
    timing = 1;
  if (v19)
  {
    v21 = v3[2];
    v22 = -v19;
    v24 = *(v21 + 64);
    v23 = *(v21 + 68);
    v25 = 4;
    do
    {
      v27 = v3[3];
      v28 = v25 - 4;
      v29 = Allocate(effPCPNeedleSpiralPart_tag);
      _ctor(v29, 0);
      *&v27[2 * v25] = v29;
      v32 = v3[3];
      v34 = *(v32 + 8 * v25);
      *(v34 + 56) = DDS3EFFECT_RAND_F() * 6.2832;
      *(v34 + 52) = v24 * DDS3EFFECT_RAND_FA(v23);
      v35 = DDS3EFFECT_RAND_I();
      *(v34 + 48) = v35 / timing * timing - v35;
      v37 = *(v3[6] + 80);
      v39 = *(v37 + 8 * v25++);
      *(v39 + 32) = 8421504;
    }
    while (v22 + v25 != 4);
  }
  return v3;
}

// 0x175a6d0
effPCPNeedleSpiral_tag *effPCPNeedleSpiralCreateP(void **pData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *pData;
  else if (!v5)
  {
    return effPCPNeedleSpiralCreate(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPNeedleSpiralParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPNeedleSpiralParam_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return effPCPNeedleSpiralCreate(v5, *&bPos);
}

// 0x175ad10
effPCPNeedleSpiral_tag *effPCPNeedleSpiralCreatePCF(void **hData, s32 bPos, bool tbldata) {
  dds3EffectPCPData_t_o *v6;
  Il2CppObject *v7;
  Il2CppClass *v8;
  s64 *Interface;
  char *v10;
  s64 *v11;
  struct dds3EffectPCPData_Part_t_array *pcpData;
  Il2CppObject *v14;
  u32 offset;
  effPCPNeedleSpiralParam_t_c *v17;
  Il2CppObject *DataUnityOffSet;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v21;
  s64 *v22;
  u64 v24[2];
  char *v25;
  s32 pos;

  pos = bPos;
  v6 = Allocate(dds3EffectPCPData_t);
  dds3EffectPCPData_t___ctor(v6);
  v7 = *hData;
  if (*hData)
  {
    Interface = QueryInterface(*hData, byte);
    if (!Interface)
    {
      sub_8FC2C0(v7->klass->_1.element_class, v8, v24);
      if ((v24[0] & 1) != 0)
        v10 = v25;
      else
        v10 = v24 + 1;
      v11 = sub_8C4940(v10);
    }
  }
  else
  {
    Interface = 0;
  }
  dds3EffectPCPData_t__pCopy(v6, Interface, &pos);
  pcpData = v6->pcpData;
  v14 = *hData;
  offset = pcpData->m_Items[0]->offset;
  DataUnityOffSet = dds3EffectPCPDataGetDataUnityOffSet(v14, offset + bPos, 57);
  else if (!DataUnityOffSet)
  {
    return effPCPNeedleSpiralCreate(DataUnityOffSet, v17);
  }
  klass = DataUnityOffSet->klass;
  if (DataUnityOffSet->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPNeedleSpiralParam_t)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPNeedleSpiralParam_t, v24);
    if ((v24[0] & 1) != 0)
      v21 = v25;
    else
      v21 = v24 + 1;
    v22 = sub_8C4940(v21);
  }
  return effPCPNeedleSpiralCreate(DataUnityOffSet, v17);
}

// 0x175abc0
void effPCPNeedleSpiralDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3NeedleModel_tag_o *v9;
  u64 v10[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPNeedleSpiral_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPNeedleSpiral_tag, v10);
      if ((v10[0] & 1) != 0)
        v6 = v10[2];
      else
        v6 = v10 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  dds3TrackPolyDelete(&v3[2].monitor);
  v9 = v3[3].klass;
  dds3NeedleModelDelete(v9);
}

// 0x175b060
void effPCPNeedleSpiralDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  UnityEngine_Vector4_array *v8;
  f32 *v15;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  s64 klass_high;
  Il2CppClass *v26;
  s32 data_high;
  dds3NeedleModel_tag_o **v28;
  u64 i;
  u64 *monitor;
  s64 v31;
  s32 v32;
  s32 v33;
  dds3NeedleModel_tag_o *v34;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v42;
  f32 v43;
  f32 v46;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v52;
  struct dds3NeedleModelPart_tag_array *pPart;
  f32 v55;
  u32 v56;
  struct dds3NeedleModelPart_tag_array *v57;
  dds3NeedleModel_tag_o *v63;
  s32 data;
  s32 v67;
  f32 v69;
  u32 abgr1;
  UnityEngine_Vector4_array *pV;
  UnityEngine_Matrix4x4_o v73;
  nbFormation_t_o *pFormation;
  UnityEngine_Vector4_o v76;
  UnityEngine_Vector4_o v77;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o pPos;
  UnityEngine_Vector4_o v80;
  UnityEngine_Vector4_o v81;
  u64 v82[2];
  u64 v83[4];
  UnityEngine_Vector4_o v84;
  UnityEngine_Vector4_o v85;
  UnityEngine_Vector4_o v86;
  UnityEngine_Vector4_o v87;
  UnityEngine_Vector4_o v88;

  v82[0] = 0;
  v82[1] = 0;
  pFormation = 0;
  *&v81.x = 0;
  *&v81.z = 0;
  *&v80.x = 0;
  *&v80.z = 0;
  *&pPos.x = 0;
  *&pPos.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v77.x = 0;
  *&v77.z = 0;
  *&v76.x = 0;
  *&v76.z = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPNeedleSpiral_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPNeedleSpiral_tag, v83);
      if ((v83[0] & 1) != 0)
        v6 = v83[2];
      else
        v6 = v83 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  sub_854690(v82, 0.0, 1.0, 0.0, 0.0);
  *&v81.x = 0;
  *&v81.z = 0;
  *&v80.x = 0;
  *&v80.z = 0;
  *&pPos.x = 0;
  *&pPos.z = 0;
  v8 = NewSpecific(UnityEngine_Vector4, 2u);
  *&p.x = 0;
  *&p.z = 0;
  *&v77.x = 0;
  *&v77.z = 0;
  *&v76.x = 0;
  *&v76.z = 0;
  sub_854930(&v77, 0);
  sub_854710(&v77, 0);
  sub_854930(&v77, 1u);
  sub_854930(&v77, 2u);
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  sub_854930(&v76, 0);
  sub_854710(&v76, 0);
  sub_854930(&v76, 1u);
  sub_854930(&v76, 2u);
  pV = v8;
  if (!effBTLSkillCheckRun())
    goto LABEL_27;
LABEL_16:
  pFormation = effBTLSkillGetInvokeFormation(0);
  effBTLModelGetSphereCenter(&pFormation);
  SDF_VU0__STOREVECTOR(&v81);
  v15 = v3[1].klass;
  v85 = *(v15 + 1);
  x = v81.x;
  y = v81.y;
  z = v81.z;
  w = v81.w;
  v88.x = x;
  v88.y = y;
  v88.z = z;
  v88.w = w;
  *&v84.x = 0;
  LookAtMatrix(v85, v88, v84);
  ReverseMatrix();
  SDF_VU0__STOREMATRIX(&v3[3].klass->_1.name);
LABEL_28:
  sub_854930(&v80, 0);
  sub_854930(&v80, 1u);
  sub_854930(&v80, 2u);
  SDF_VU0__LOADVECTOR(v80);
  SDF_VU0__APPLYMATRIX_XYZ();
  SDF_VU0__STOREVECTOR(&v80);
  SDF_VU0__LOADVECTOR_B(v76);
  SDF_VU0__MULVECTOR();
  SDF_VU0__STOREVECTOR(&v76);
  klass_high = HIDWORD(v3[2].klass);
  if (klass_high)
  {
    v26 = v3[1].klass;
    data_high = HIDWORD(v26->_1.byval_arg.data);
    v69 = *&v26->_1.castClass;
    data = v26->_1.this_arg.data;
    v28 = &v3[3];
    abgr1 = v3[2].klass;
    v67 = *(&v26->_1.byval_arg.bits + 1);
    for (i = 0; klass_high != i; ++i)
    {
      monitor = v3[1].monitor;
      v31 = monitor[i + 4];
      v32 = *(v31 + 48);
      if (v32)
      {
        if (v32 < 0)
          goto LABEL_51;
      }
      else
      {
        memmove(&v73, &(*v28)->fields, 0x40u);
        SDF_VU0__LOADMATRIX(&v73);
        v46 = *(v31 + 56);
        sdfCos(v46);
        sub_854930(&v81, 0);
        sdfSin(*(v31 + 56), 0);
        sub_854930(&v81, 1u);
        sub_854930(&v81, 2u);
        SDF_VU0__LOADVECTOR(v81);
        SDF_VU0__APPLYMATRIX_XYZ();
        SDF_VU0__STOREVECTOR(&v81);
        sub_854710(&v81, 0);
        sub_854930(v31 + 16, 0);
        sub_854710(&v81, 1u);
        sub_854930(v31 + 16, 1u);
        sub_854710(&v81, 2u);
        sub_854930(v31 + 16, 2u);
        v50 = v81.x;
        v49 = v81.y;
        v52 = v81.z;
        v51 = v81.w;
        v86.x = v50;
        v86.y = v49;
        v86.z = v52;
        v86.w = v51;
        dds3NeedleModelSetPosition(&v3[3], i, v86);
      }
      v33 = data_high - v32;
      if (data_high < v32)
      {
LABEL_51:
        pPart = (*v28)->pPart;
        pPart->m_Items[i]->abgr = 0;
        dds3TrackPolyColorSet(&v3[2].monitor, i, 0);
        dds3TrackPolyListInit(&v3[2].monitor, i);
        goto LABEL_80;
      }
      v34 = *v28;
      dds3NeedleModelGetPosition(v34, i, &pPos);
      SDF_VU0__LOADVECTOR(v76);
      SDF_VU0__LOADVECTOR_B(pPos);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&pPos);
      sub_854710(v31 + 16, 0);
      sub_854930(&v81, 0);
      sub_854710(v31 + 16, 1u);
      sub_854930(&v81, 1u);
      sub_854710(v31 + 16, 2u);
      sub_854930(&v81, 2u);
      v36 = *(v31 + 56);
      v38 = v80.x;
      v37 = v80.y;
      v40 = v80.z;
      v39 = v80.w;
      v87.x = v38;
      v87.y = v37;
      v87.z = v40;
      v87.w = v39;
      SetRotateMatrixAxis(v36, v87);
      *(v31 + 56) = v69 + *(v31 + 56);
      SDF_VU0__LOADVECTOR(v81);
      SDF_VU0__APPLYMATRIX_XYZ();
      SDF_VU0__STOREVECTOR(&v81);
      sub_854710(&v81, 0);
      sub_854710(&v80, 0);
      sub_854930(&v81, 0);
      sub_854710(&v81, 1u);
      sub_854710(&v80, 1u);
      sub_854930(&v81, 1u);
      sub_854710(&v81, 2u);
      sub_854710(&v80, 2u);
      sub_854930(&v81, 2u);
      SDF_VU0__LOADVECTOR(v81);
      SDF_VU0__LOADVECTOR_B(*&v3[1].klass->_1.name);
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&v81);
      dds3NeedleModelSetPosition(&v3[3], i, v81);
      if (v67 && v32 < v67)
      {
        v42 = v67;
        v43 = v32;
      }
      else
      {
        if (data)
        {
          v55 = 0.0;
          if (data_high == v32)
            goto LABEL_66;
        }
        v55 = 1.0;
        if (!data)
          goto LABEL_66;
        v55 = 1.0;
        if (v33 > data)
          goto LABEL_66;
        v43 = v33;
        v42 = data;
      }
      v55 = v43 / v42;
LABEL_66:
      v56 = effColorBlend(abgr1 & 0xFFFFFF, abgr1, v55);
      v57 = (*v28)->pPart;
      v57->m_Items[i]->abgr = v56;
      if (v32 >= 1)
      {
        SDF_VU0__LOADVECTOR(v76);
        SDF_VU0__LOADVECTOR_B(v81);
        SDF_VU0__ADDVECTOR();
        SDF_VU0__COPYVECTOR_A_TO_C();
        SDF_VU0__LOADVECTOR(pPos);
        SDF_VU0__COPYVECTOR_C_TO_B();
        SDF_VU0__SUBVECTOR();
        SDF_VU0__LOADVECTOR_B(p);
        SDF_VU0__OUTERPRODUCT();
        SDF_VU0__NORMALIZE();
        SDF_VU0__LOADVECTOR_B(v77);
        SDF_VU0__MULVECTOR();
        SDF_VU0__SWAPVECTOR_A_C();
        SDF_VU0__COPYVECTOR_A_TO_B();
        SDF_VU0__ADDVECTOR_A_C();
        SDF_VU0__STOREVECTOR(pV->m_Items);
        SDF_VU0__COPYVECTOR_C_TO_A();
        SDF_VU0__SUBVECTOR_B_A();
        SDF_VU0__STOREVECTOR_B(&pV->m_Items[1]);
        dds3TrackPolySet(&v3[2].monitor, i, pV);
        dds3TrackPolyVCRefresh_ParType1(&v3[2].monitor, i);
        dds3TrackPolyColorSet(&v3[2].monitor, i, v56 & 0xFF000000 | 0x808080);
      }
LABEL_80:
      ++*(v31 + 48);
    }
  }
  dds3TrackPolyDraw(&v3[2].monitor, "");
  v63 = v3[3].klass;
  dds3NeedleModelDraw(v63);
}

// 0x175bf50
void effPCPNeedleSpiralSetColor(void **hData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPNeedleSpiral_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPNeedleSpiral_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*hData)[2].klass) = abgr;
}

// 0x175bcc0
void effPCPNeedleSpiralSetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v10;
  s64 *v11;
  u64 v12[3];
  UnityEngine_Vector4_o v13;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPNeedleSpiral_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effPCPNeedleSpiral_tag, v12);
    if ((v12[0] & 1) != 0)
      v10 = v12[2];
    else
      v10 = v12 + 1;
    v11 = sub_8C4940(v10);
  }
  v13.x = x;
  v13.y = y;
  v13.z = z;
  v13.w = w;
  SDF_VU0__COPYVECTOR(&(*hData)[1].klass->_1.name, v13, 0);
}

// 0x175bde0
void effPCPNeedleSpiralSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
  UnityEngine_Matrix4x4_o *v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  UnityEngine_Matrix4x4_o v10;
  UnityEngine_Matrix4x4_o v11;

  v3 = pMatrix;
  v5 = *hData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effPCPNeedleSpiral_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effPCPNeedleSpiral_tag, &v11);
      if ((LOBYTE(v11.m00) & 1) != 0)
        v8 = *&v11.m01;
      else
        v8 = &v11.m00 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = *v3;
  v11 = v10;
  SDF_VU0__LOADMATRIX(&v11);
  SDF_VU0__STOREMATRIX(&v5[3].klass->_1.name);
}

// 0x1758da0
void effPkt3DPrimLinkPoly(sdfDrawTag_t *pTag, sdf3DPrimPolyParm_t *pParam) {
  ;
}
