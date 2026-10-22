#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct dds3MagaFuncTable_t dds3MagaFuncTable_t;
typedef struct dds3MagatuhiBill_tag dds3MagatuhiBill_tag;
typedef struct dds3MagatuhiPar_tag dds3MagatuhiPar_tag;
typedef struct effBezier4P_t effBezier4P_t;
typedef struct effHandle_t effHandle_t;
typedef struct effMagaCylinderParam_t effMagaCylinderParam_t;
typedef struct effMagaCylinder_tag effMagaCylinder_tag;
typedef struct effMagaP4Point_t effMagaP4Point_t;
typedef struct effMagaPoint4Param_t effMagaPoint4Param_t;
typedef struct effMagaPoint4_tag effMagaPoint4_tag;
typedef struct effMagaSCArea_t effMagaSCArea_t;
typedef struct effMagaSmokeConvParam_t effMagaSmokeConvParam_t;
typedef struct effMagaSmokeConv_tag effMagaSmokeConv_tag;
typedef struct effMagaSmokeParam_t effMagaSmokeParam_t;
typedef struct effMagaSmoke_tag effMagaSmoke_tag;
typedef struct effMagaSpiralParam_t effMagaSpiralParam_t;
typedef struct effMagaSpiral_tag effMagaSpiral_tag;
typedef struct effMagatuhiParams_t effMagatuhiParams_t;
typedef struct effMagatuhi_tag effMagatuhi_tag;
typedef struct sdfRandCB_t sdfRandCB_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct effMagatuhi_tag {
    effMagatuhiParams_t *params;
    dds3MagatuhiBill_tag *hMagaBill;
};

static u16 ***dds3MagatuhiUVBuff;
static dds3MagaFuncTable_t *EffMagatuhiParTable[5];

void ClearUseIndex(XRD773Unity_CommonMesh *this);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__APPLYMATRIX(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__GETLENGTH(void);
void SDF_VU0__INTERPOLATE(f32 rate);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__OUTERPRODUCT(void);
sdfVector4_t SDF_VU0__Retdds3ColorItoF(u32 rgba, f32 ratio);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
u32 SDF_VU0__dds3ColorFtoI(f32 ratio);
void SDF_VU0__dds3ColorItoF(u32 rgba);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetMatTexture(XRD773Unity_CommonMesh *this, void *texture);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
void SetUvTable_20243232(XRD773Unity_CommonMesh *this, sdfVector2_t **pos);
effBezier4P_t *dds3Bezier4PCreate(u32 number);
s32 dds3Bezier4PRun(effBezier4P_t **pEffBezier4P, u32 index, sdfVector4_t *pOut);
void **dds3BillboardGetGeneralPtexture(s32 number);
sdfTexHandle_t *dds3BillboardGetGeneralTex(s32 number);
dds3MagatuhiBill_tag *dds3MagatuhiBillCreate(u32 number, u32 point, f32 scale, u32 blend, f32 t);
void dds3MagatuhiBillDraw(dds3MagatuhiBill_tag *hMagaBill, char *callname);
void dds3MagatuhiBillPartsInit(dds3MagatuhiBill_tag **hMagaBill, u32 index);
void dds3MagatuhiBillSetVertex(dds3MagatuhiBill_tag **hMagaBill, u32 index, sdfVector4_t pV);
dds3MagatuhiPar_tag *dds3MagatuhiParCreateTbl(u16 type, void *pData, s32 bPos);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
void effMagaCylinderParam_t__bCopy(effMagaCylinderParam_t *this, u8 **bytedata, s32 *bPos);
void effMagaCylinderParam_t__pClone(effMagaCylinderParam_t *this, effMagaCylinderParam_t **dst);
void effMagaCylinderPartInit(effMagaCylinder_tag **pMagaCylinder, u32 index);
void effMagaCylinderRandomize(effHandle_t **hEffect);
void effMagaP4Randomize(effHandle_t **hEffect);
void effMagaPoint4Param_t__bCopy(effMagaPoint4Param_t *this, u8 **bytedata, s32 *bPos);
void effMagaPoint4Param_t__pClone(effMagaPoint4Param_t *this, effMagaPoint4Param_t **dst);
void effMagaPoint4PartInit(effMagaPoint4_tag **pMagaPoint4, u32 index);
void effMagaSmokeConvParam_t__bCopy(effMagaSmokeConvParam_t *this, u8 **bytedata, s32 *bPos);
void effMagaSmokeConvParam_t__pClone(effMagaSmokeConvParam_t *this, effMagaSmokeConvParam_t **dst);
void effMagaSmokeConvPartInit(effMagaSmokeConv_tag **pMagaSmokeConv, u32 index);
void effMagaSmokeParam_t__bCopy(effMagaSmokeParam_t *this, u8 **bytedata, s32 *bPos);
void effMagaSmokeParam_t__pClone(effMagaSmokeParam_t *this, effMagaSmokeParam_t **dst);
void effMagaSmokePartInit(effMagaSmoke_tag **pMagaSmoke, u32 index);
void effMagaSmokeRandomize(effHandle_t **hEffect);
void effMagaSpiralParam_t__bCopy(effMagaSpiralParam_t *this, u8 **bytedata, s32 *bPos);
void effMagaSpiralParam_t__pClone(effMagaSpiralParam_t *this, effMagaSpiralParam_t **dst);
void effMagaSpiralPartInit(effMagaSpiral_tag **pMagaSpiral, u32 index);
void effMagaSpiralRandomize(effHandle_t **hEffect);
effMagatuhi_tag *effMagatuhiCreate(effMagatuhiParams_t *pParams);
void effMagatuhiDelete(effMagatuhi_tag **pMagatuhi);
f32 sdfCos(f32 aRadius);
u32 sdfGetRand(sdfRandCB_t **aCB);
f32 sdfGetRandFloat(sdfRandCB_t **aCB);
f32 sdfSin(f32 aRadius);

// 0x16b5860
void InitMagatuhiEdtorProcess(void) {
  ;
}

// 0x16a8340
dds3MagatuhiBill_tag *dds3MagatuhiBillCreate(u32 number, u32 point, f32 scale, u32 blend, f32 t) {
  u64 v11;
  dds3MagatuhiBill_tag_o *v12;
  struct dds3MagatuhiBillTail_tag_array *v13;
  u32 *pTail;
  u64 v16;
  u64 v17;
  u64 *v18;
  struct System_UInt16_array_array_array *v22;
  u64 i;
  u32 *dds3MagatuhiUVBuff;
  s64 *v39;
  s64 *v40;
  struct System_UInt16_array_array_array *v42;
  System_UInt16_array_array *v44;
  s64 *v45;
  s64 *v46;
  struct System_UInt16_array_array_array *v48;
  System_UInt16_array_array *v49;
  System_UInt16_array *v50;
  struct System_UInt16_array_array_array *v51;
  System_UInt16_array_array *v52;
  System_UInt16_array *v53;
  struct System_UInt16_array_array_array *v55;
  System_UInt16_array_array *v57;
  s64 *v58;
  s64 *v59;
  struct System_UInt16_array_array_array *v61;
  System_UInt16_array_array *v63;
  System_UInt16_array *v65;
  struct System_UInt16_array_array_array *v67;
  System_UInt16_array_array *v69;
  System_UInt16_array *v71;
  struct System_UInt16_array_array_array *v73;
  System_UInt16_array_array *v75;
  s64 *v76;
  s64 *v77;
  struct System_UInt16_array_array_array *v79;
  System_UInt16_array_array *v81;
  System_UInt16_array *v83;
  struct System_UInt16_array_array_array *v85;
  System_UInt16_array_array *v87;
  System_UInt16_array *v89;
  struct System_UInt16_array_array_array *v91;
  System_UInt16_array_array *v93;
  s64 *v94;
  s64 *v96;
  struct System_UInt16_array_array_array *v98;
  System_UInt16_array_array *v100;
  System_UInt16_array *v102;
  struct System_UInt16_array_array_array *v104;
  System_UInt16_array_array *v106;
  System_UInt16_array *v107;
  u32 v108;
  dds3MagatuhiBill_tag_o *hMagaBill;

  v11 = point * number;
  v12 = Allocate(dds3MagatuhiBill_tag);
  _ctor(v12, 0);
  hMagaBill = v12;
  v12->number = number;
  v12->point = point;
  v12->scale = scale;
  v12->t = t;
  v12->blend = blend;
  v12->pVertex = NewSpecific(UnityEngine_Vector4, v11);
  v12->pScale = NewSpecific(f32, v11);
  v12->pVC = NewSpecific(uint, v11);
  v12->pRGBA = NewSpecific(uint, v11);
  v12->pCurrent = NewSpecific(ushort, v11);
  v12->pCount = NewSpecific(ushort, v11);
  v13 = NewSpecific(dds3MagatuhiBillTail_tag, v11);
  v12->pTail = v13;
  if (v11)
  {
    pTail = v13;
    v16 = 0;
    v17 = v11 - 1;
    while (1)
    {
      v18 = Allocate(dds3MagatuhiBillTail_tag);
      _ctor(v18, 0);
      *&pTail[2 * v16 + 8] = v18;
      if (v17 == v16)
        break;
      pTail = v12->pTail;
      ++v16;
    }
  }
  v12->hMem = 0;
  v12->hTex = dds3BillboardGetGeneralTex(0);
  v22 = NewSpecific(ushort____, 0x20u);
  dds3MagatuhiUVBuff = v22;
  for (i = 0; i != 32; ++i)
  {
    v39 = NewSpecific(ushort__, 4u);
    v40 = v39;
    *&dds3MagatuhiUVBuff[2 * i + 8] = v40;
    v42 = dds3MagatuhiUVBuff;
    v44 = v42->m_Items[i];
    v45 = NewSpecific(ushort, 2u);
    v46 = v45;
    v44->m_Items[0] = v46;
    v48 = dds3MagatuhiUVBuff;
    v49 = v48->m_Items[i];
    v50 = v49->m_Items[0];
    v50->m_Items[0] = 0;
    v51 = dds3MagatuhiUVBuff;
    v52 = v51->m_Items[i];
    v53 = v52->m_Items[0];
    v53->m_Items[1] = 0;
    v55 = dds3MagatuhiUVBuff;
    v57 = v55->m_Items[i];
    v58 = NewSpecific(ushort, 2u);
    v59 = v58;
    v57->m_Items[1] = v59;
    v61 = dds3MagatuhiUVBuff;
    v63 = v61->m_Items[i];
    v65 = v63->m_Items[1];
    v65->m_Items[0] = 1024;
    v67 = dds3MagatuhiUVBuff;
    v69 = v67->m_Items[i];
    v71 = v69->m_Items[1];
    v71->m_Items[1] = 0;
    v73 = dds3MagatuhiUVBuff;
    v75 = v73->m_Items[i];
    v76 = NewSpecific(ushort, 2u);
    v77 = v76;
    v75->m_Items[2] = v77;
    v79 = dds3MagatuhiUVBuff;
    v81 = v79->m_Items[i];
    v83 = v81->m_Items[2];
    v83->m_Items[0] = 1024;
    v85 = dds3MagatuhiUVBuff;
    v87 = v85->m_Items[i];
    v89 = v87->m_Items[2];
    v89->m_Items[1] = 1024;
    v91 = dds3MagatuhiUVBuff;
    v93 = v91->m_Items[i];
    v94 = NewSpecific(ushort, 2u);
    v96 = v94;
    v93->m_Items[3] = v96;
    v98 = dds3MagatuhiUVBuff;
    v100 = v98->m_Items[i];
    v102 = v100->m_Items[3];
    v102->m_Items[0] = 0;
    v104 = dds3MagatuhiUVBuff;
    v106 = v104->m_Items[i];
    v107 = v106->m_Items[3];
    v107->m_Items[1] = 1024;
  }
  if (number)
  {
    v108 = 0;
    do
    {
      dds3MagatuhiBillPartsInit(&hMagaBill, v108++);
    }
    while (number != v108);
  }
  return v12;
}

// 0x16a8e10
void dds3MagatuhiBillDelete(dds3MagatuhiBill_tag *hMagaBill) {
  ;
}

// 0x16a8e20
void dds3MagatuhiBillDraw(dds3MagatuhiBill_tag *hMagaBill, char *callname) {
  f32 scale;
  s64 number;
  struct System_UInt32_array *pVC;
  struct System_UInt16_array *pCount;
  struct System_UInt32_array *pRGBA;
  struct XRD773Unity_CommonMesh_array *pMesh;
  u64 v12;
  s32 v13;
  struct XRD773Unity_CommonMesh_array *v16;
  struct XRD773Unity_CommonMesh_array *v18;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v21;
  struct XRD773Unity_CommonMesh_array *v22;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  System_String_o *v26;
  struct XRD773Unity_CommonMesh_array *v27;
  u64 v29;
  u32 v30;
  s32 v32;
  UnityEngine_Vector2_array *v34;
  struct System_Single_array *v36;
  s64 v37;
  s64 v38;
  u32 *p_r;
  s64 v41;
  u32 *p_y;
  s64 p_z;
  s64 v44;
  f32 *v46;
  f32 v47;
  s16 v48;
  u16 v50;
  s64 v51;
  f32 v54;
  f32 w;
  f32 y;
  f32 x;
  f32 z;
  long f64 v60;
  f32 v61;
  struct XRD773Unity_CommonMesh_array *v62;
  f32 v63;
  long f64 v66;
  f32 v67;
  f32 v68;
  f32 v69;
  f32 v70;
  f32 v71;
  long f64 v72;
  struct XRD773Unity_CommonMesh_array *v74;
  long f64 v76;
  long f64 v77;
  u32 v78;
  struct XRD773Unity_CommonMesh_array *v80;
  long f64 v82;
  long f64 v83;
  struct XRD773Unity_CommonMesh_array *v85;
  long f64 v87;
  u32 v88;
  s32 v90;
  s32 v92;
  s32 v94;
  s32 v96;
  s32 v98;
  s32 v99;
  s32 v100;
  s32 v102;
  s32 v103;
  s32 v104;
  s32 v106;
  s32 v107;
  s32 v108;
  s32 v110;
  s32 v111;
  s32 v112;
  struct XRD773Unity_CommonMesh_array *v120;
  struct XRD773Unity_CommonMesh_array *v122;
  struct XRD773Unity_CommonMesh_array *v124;
  struct XRD773Unity_CommonMesh_array *v126;
  UnityEngine_Texture_array *GeneralPtexture;
  struct XRD773Unity_CommonMesh_array *v130;
  struct XRD773Unity_CommonMesh_array *v131;
  f32 v137;
  f32 v138;
  f32 v139;
  f32 v140;
  f32 v141;
  f32 v142;
  s32 v143;
  struct System_UInt16_array *v144;
  struct System_UInt32_array *v145;
  s64 v146;
  struct System_UInt16_array *pCurrent;
  u64 v148;
  f32 v149;
  struct System_UInt32_array *v150;
  dds3MagatuhiBill_tag_o *v151;
  System_Int32_array *idx;
  UnityEngine_Vector3_array *pos;
  s32 v154;
  s32 point;
  UnityEngine_Vector2_array *v156;
  u32 rgba;
  struct System_Single_array *pScale;
  struct UnityEngine_Vector4_array *pVertex;
  u32 v160;
  u16 v161;
  s32 v162;
  u16 v163;
  u32 v164;
  UnityEngine_Color_array *col;
  u32 *v166;
  u32 v167;
  s64 v168;
  s64 v169;
  UnityEngine_Vector4_o p;
  s64 v171;
  s64 v172;
  s64 v173;
  s64 v174;
  UnityEngine_Vector4_o dst;
  UnityEngine_Matrix4x4_o aMatrix;
  UnityEngine_Vector3_o v177;
  UnityEngine_Vector3_o v178;
  UnityEngine_Vector3_o v179;
  UnityEngine_Vector3_o v180;
  UnityEngine_Vector3_o v181;
  UnityEngine_Vector3_o v182;
  UnityEngine_Vector3_o v183;
  UnityEngine_Vector3_o v184;
  UnityEngine_Vector4_o v185;
  UnityEngine_Vector3_o v186;
  UnityEngine_Vector3_o v187;
  UnityEngine_Vector3_o v188;
  UnityEngine_Vector3_o v189;
  UnityEngine_Vector3_o v190;
  UnityEngine_Vector4_o v191;
  UnityEngine_Vector4_o v192;

  v172 = 0;
  v173 = 0;
  v174 = 0;
  v168 = 0;
  *&p.z = 0;
  v171 = 0;
  v169 = 0;
  *&p.x = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  *&dst.x = 0;
  *&dst.z = 0;
  SDF_VU0__STOREIDENTITY(&aMatrix);
  point = hMagaBill->point;
  scale = hMagaBill->scale;
  number = hMagaBill->number;
  pVC = hMagaBill->pVC;
  pCount = hMagaBill->pCount;
  pRGBA = hMagaBill->pRGBA;
  pMesh = hMagaBill->pMesh;
  pCurrent = hMagaBill->pCurrent;
  if (pMesh)
  {
    ClearUseIndex(pMesh->m_Items[0]);
    if (number)
      goto LABEL_7;
LABEL_28:
    v13 = 0;
    goto LABEL_29;
  }
  v16 = NewSpecific(XRD773Unity_CommonMesh, 1u);
  hMagaBill->pMesh = v16;
  v18 = v16;
  {
  }
  Instance = get_Instance();
  Mesh = GetMesh(Instance, 6, 0);
  v21 = Mesh;
  v18->m_Items[0] = v21;
  v22 = hMagaBill->pMesh;
  gameObject = get_gameObject(v22->m_Items[0]);
  name = get_name(gameObject);
  v26 = Concat_5221536(name, ":", callname);
  set_name(gameObject, v26);
  v27 = hMagaBill->pMesh;
  SetAutoHide(v27->m_Items[0], 1);
  if (!number)
    goto LABEL_28;
LABEL_7:
  v12 = 0;
  v13 = 0;
  do
  {
    while (1)
    {
      if (HIBYTE(pRGBA->m_Items[v12]))
        break;
      if (number == ++v12)
        goto LABEL_29;
    }
    v13 += pCount->m_Items[v12++];
  }
  while (number != v12);
LABEL_29:
  pos = NewSpecific(UnityEngine_Vector3, (4 * v13));
  v156 = NewSpecific(UnityEngine_Vector2, (4 * v13));
  col = NewSpecific(UnityEngine_Color, (4 * v13));
  idx = NewSpecific(s32, (6 * v13));
  sub_851710(&v174, 0.0, 1.0);
  sub_851710(&v173, 1.0, 1.0);
  sub_851710(&v172, 1.0, 0.0);
  sub_851710(&v171, 0.0, 0.0);
  if (number)
  {
    v143 = 8 * (v13 > 1249);
    v144 = pCount;
    v145 = pRGBA;
    v150 = pVC;
    v151 = hMagaBill;
    v149 = scale * 4.0;
    v146 = number;
    v29 = 0;
    v30 = 0;
    v167 = 0;
    do
    {
      v32 = pCount->m_Items[v29];
      pVertex = hMagaBill->pVertex;
      pScale = hMagaBill->pScale;
      rgba = pRGBA->m_Items[v29];
      v34 = v156;
      v148 = v29 + 1;
      v36 = hMagaBill->pScale;
      if (HIBYTE(rgba))
      {
        v162 = v29 * point;
        v37 = pCurrent->m_Items[v29];
        v38 = v37 + (v29 * point);
        SDF_VU0__COPYVECTOR(&dst, pVertex->m_Items[v38]);
        v154 = v32 - v143;
        if (v32 - v143 >= 1)
        {
          p_r = &col->m_Items[v30 + 1].r;
          v41 = &idx->m_Items[v167 + 5];
          p_y = &v156->m_Items[v30 + 3].y;
          p_z = &pos->m_Items[v30].z;
          v163 = 0;
          do
          {
            v44 = v162 + v37;
            v166 = v41;
            v46 = (v36 + 4 * v44);
            v47 = v46[8];
            v46[8] = (v47 * 0.75) + 0.25;
            v48 = point;
            v191.x = dst.x;
            v191.y = dst.y;
            if (v37)
              v48 = v37;
            v191.z = dst.z;
            v191.w = dst.w;
            v50 = v48 - 1;
            SDF_VU0__LOADVECTOR(v191);
            SDF_VU0__STOREVECTOR(&p);
            v161 = v50;
            v51 = v162 + v50;
            SDF_VU0__LOADVECTOR_B(pVertex->m_Items[v51]);
            SDF_VU0__ADDVECTOR();
            SDF_VU0__STOREVECTOR(&dst);
            SDF_VU0__dds3ColorItoF(rgba);
            SDF_VU0__COPYVECTOR_A_TO_B();
            v54 = v149 * v47;
            SDF_VU0__dds3ColorItoF(pVC->m_Items[v163]);
            SDF_VU0__MULVECTOR();
            v160 = SDF_VU0__dds3ColorFtoI(128.0);
            w = p.w;
            x = p.x;
            y = p.y;
            z = p.z;
            {
            }
            v192.x = x;
            v192.y = y;
            v192.z = z;
            v192.w = w;
            v177 = op_Implicit_8738992(v192);
            v61 = v54 / -100.0;
            v62 = hMagaBill->pMesh;
            v63 = v54 / 100.0;
            v66 = sub_1A00CF0(&v62->m_Items[0]->mat.m00, v61, v63, 0.0, v60);
            v67 = *&v66;
            v69 = v68;
            v71 = v70;
            {
            }
            v186.x = v67;
            v186.y = v69;
            v186.z = v71;
            v187.x = v177.x / 100.0;
            v187.y = v177.y / -100.0;
            v187.z = v177.z / 100.0;
            v178 = op_Addition(v186, v187);
            *(p_z - 8) = v178;
            v74 = hMagaBill->pMesh;
            v76 = sub_1A00CF0(&v74->m_Items[0]->mat.m00, v63, v63, 0.0, v72);
            v188.x = v177.x / 100.0;
            v188.y = v177.y / -100.0;
            v188.z = v177.z / 100.0;
            v182.x = *&v76;
            v182.y = v137;
            v182.z = v138;
            v179 = op_Addition(v182, v188);
            v78 = v30 + 1;
            *(p_z + 4) = v179;
            v80 = hMagaBill->pMesh;
            v82 = sub_1A00CF0(&v80->m_Items[0]->mat.m00, v63, v61, 0.0, v77);
            v189.x = v177.x / 100.0;
            v189.y = v177.y / -100.0;
            v189.z = v177.z / 100.0;
            v183.x = *&v82;
            v183.y = v139;
            v183.z = v140;
            v180 = op_Addition(v183, v189);
            v164 = v30 + 2;
            *(p_z + 16) = v180;
            v85 = hMagaBill->pMesh;
            v87 = sub_1A00CF0(&v85->m_Items[0]->mat.m00, v61, v61, 0.0, v83);
            v190.x = v177.x / 100.0;
            v190.y = v177.y / -100.0;
            v190.z = v177.z / 100.0;
            v184.x = *&v87;
            v184.y = v141;
            v184.z = v142;
            v181 = op_Addition(v184, v190);
            v88 = v30 + 3;
            *(p_z + 28) = v181;
            v90 = HIDWORD(v174);
            *(p_y - 7) = v174;
            *(p_y - 6) = v90;
            v92 = HIDWORD(v173);
            *(p_y - 5) = v173;
            *(p_y - 4) = v92;
            v94 = HIDWORD(v172);
            *(p_y - 3) = v172;
            *(p_y - 2) = v94;
            v96 = HIDWORD(v171);
            *(p_y - 1) = v171;
            *p_y = v96;
            v185 = SDF_VU0__Retdds3ColorItoF(v160, 128.0);
            sub_19EC630(&v168, v185.x, v185.y, v185.z, v185.w);
            v98 = HIDWORD(v168);
            v99 = v169;
            v100 = HIDWORD(v169);
            *(p_r - 4) = v168;
            *(p_r - 3) = v98;
            *(p_r - 2) = v99;
            *(p_r - 1) = v100;
            v102 = HIDWORD(v168);
            v103 = v169;
            v104 = HIDWORD(v169);
            *p_r = v168;
            p_r[1] = v102;
            p_r[2] = v103;
            p_r[3] = v104;
            v106 = HIDWORD(v168);
            v107 = v169;
            v108 = HIDWORD(v169);
            p_r[4] = v168;
            p_r[5] = v106;
            p_r[6] = v107;
            p_r[7] = v108;
            v110 = HIDWORD(v168);
            v111 = v169;
            v112 = HIDWORD(v169);
            p_r[8] = v168;
            p_r[9] = v110;
            p_r[10] = v111;
            p_r[11] = v112;
            *(v166 - 5) = v30;
            pVC = v150;
            hMagaBill = v151;
            v34 = v156;
            *(v166 - 4) = v78;
            *(v166 - 3) = v88;
            *(v166 - 2) = v78;
            *(v166 - 1) = v164;
            LOWORD(v37) = v161;
            v36 = pScale;
            v30 += 4;
            p_r += 16;
            p_y += 8;
            p_z += 48;
            *v166 = v88;
            v41 = (v166 + 6);
            v167 += 6;
            ++v163;
          }
          while (v154 > v163);
        }
      }
      pRGBA = v145;
      v29 = v148;
      pCount = v144;
    }
    while (v148 != v146);
    if (v30)
    {
      v120 = hMagaBill->pMesh;
      if (v120)
      {
        SetPosition_20241056(v120->m_Items[0], pos);
        v122 = hMagaBill->pMesh;
        SetIndexTable(v122->m_Items[0], idx);
        v124 = hMagaBill->pMesh;
        SetColor_20241296(v124->m_Items[0], col);
        v126 = hMagaBill->pMesh;
        SetUvTable_20243232(v126->m_Items[0], v156);
        GeneralPtexture = dds3BillboardGetGeneralPtexture(0);
        v130 = hMagaBill->pMesh;
        SetMatTexture(v130->m_Items[0], GeneralPtexture->m_Items[0]);
        v131 = hMagaBill->pMesh;
        SetActive(v131->m_Items[0], 1, 0);
      }
    }
  }
}

// 0x16a8cb0
void dds3MagatuhiBillPartsInit(dds3MagatuhiBill_tag **hMagaBill, u32 index) {
  struct System_UInt16_array *pCurrent;
  s64 v5;
  struct System_UInt16_array *pCount;
  struct System_UInt32_array *pRGBA;
  struct dds3MagatuhiBillTail_tag_array *pTail;
  s64 *v13;
  struct dds3MagatuhiBillTail_tag_array *v14;

  pCurrent = (*hMagaBill)->pCurrent;
  v5 = index;
  pCurrent->m_Items[index] = 0;
  pCount = (*hMagaBill)->pCount;
  pCount->m_Items[index] = 0;
  pRGBA = (*hMagaBill)->pRGBA;
  pRGBA->m_Items[index] = -2139062144;
  pTail = (*hMagaBill)->pTail;
  v13 = pTail->m_Items[index];
  v13[2] = 1086918619;
  v13[3] = 1078530011;
  v14 = (*hMagaBill)->pTail;
  v14->m_Items[v5] = v13;
}

// 0x16aa8f0
void dds3MagatuhiBillReset(dds3MagatuhiBill_tag **hMagaBill, u32 index) {
  dds3MagatuhiBillPartsInit(hMagaBill, index);
}

// 0x16aa630
void dds3MagatuhiBillSetRGBA(dds3MagatuhiBill_tag **hMagaBill, u32 index, u32 abgr) {
  struct System_UInt32_array *pRGBA;

  pRGBA = (*hMagaBill)->pRGBA;
  pRGBA->m_Items[index] = abgr;
}

// 0x16aa690
void dds3MagatuhiBillSetVC(dds3MagatuhiBill_tag **hMagaBill, u32 abgr_s, u32 abgr_e) {
  dds3MagatuhiBill_tag_o *v4;
  s64 point;
  f32 v6;
  f32 v7;
  f32 v8;
  u64 v12;
  s64 v13;
  struct System_UInt32_array *pVC;
  u32 v15;

  v4 = *hMagaBill;
  point = (*hMagaBill)->point;
  if ((*hMagaBill)->point)
  {
    v6 = point;
    v7 = 1.0 / v6;
    v8 = 0.0;
    v12 = 0;
    v13 = point - 1;
    while (1)
    {
      pVC = v4->pVC;
      v15 = effColorBlend(abgr_s, abgr_e, v8, *&abgr_e);
      pVC->m_Items[v12] = v15;
      if (v13 == v12)
        break;
      v4 = *hMagaBill;
      ++v12;
      v8 = v7 + v8;
    }
  }
}

// 0x16a9bc0
void dds3MagatuhiBillSetVertex(dds3MagatuhiBill_tag **hMagaBill, u32 index, sdfVector4_t pV) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  dds3MagatuhiBill_tag_o *v10;
  struct System_UInt16_array *pCurrent;
  f32 scale;
  u32 point;
  s32 v15;
  u32 v16;
  struct UnityEngine_Vector4_array *pVertex;
  u32 max_length;
  Il2CppObject *v21;
  Il2CppClass *klass;
  u32 v23;
  f32 v24;
  f32 v25;
  s64 v26;
  Il2CppObject *v28;
  Il2CppClass *v29;
  f32 v30;
  struct System_UInt16_array *pCount;
  u32 v34;
  struct dds3MagatuhiBillTail_tag_array *pTail;
  dds3MagatuhiBillTail_tag_o *v38;
  f32 s_rad;
  f32 RandFloat;
  f32 v42;
  f32 v43;
  struct UnityEngine_Vector4_array *v44;
  f32 v45;
  f32 v46;
  f32 v47;
  f32 *v49;
  struct System_Single_array *pScale;
  f32 *v52;
  s64 v53;
  u32 v54;
  u32 v55;
  u32 v56;
  dds3MagatuhiBill_tag_o *v57;
  signed s32 v58;
  s64 v59;
  struct UnityEngine_Vector4_array *v60;
  Il2CppObject *v62;
  Il2CppClass *v63;
  u32 monitor;
  struct dds3MagatuhiBillTail_tag_array *v65;
  dds3MagatuhiBillTail_tag_o *v67;
  f32 v68;
  f32 width;
  f32 v70;
  f32 v71;
  f32 radian;
  struct UnityEngine_Vector4_array *v75;
  s32 v76;
  s32 v77;
  s32 v78;
  Il2CppObject *v80;
  struct UnityEngine_Vector4_array *v81;
  f32 v82;
  f32 v83;
  f32 v84;
  f32 *v86;
  struct System_UInt16_array *v87;
  struct System_UInt16_array *v89;
  u32 v91;
  s64 v92;
  Il2CppClass *v93;
  u64 v94;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v96;
  UnityEngine_Vector4_o dst;
  u32 v98;
  u32 v99;
  UnityEngine_Vector4_o v100;
  UnityEngine_Vector4_o v101;
  UnityEngine_Vector4_o v102;

  w = pV.w;
  z = pV.z;
  y = pV.y;
  x = pV.x;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v96.x = 0;
  *&v96.z = 0;
  v93 = 0;
  v94 = 0;
  *&p.x = 0;
  *&p.z = 0;
  v10 = *hMagaBill;
  pCurrent = (*hMagaBill)->pCurrent;
  scale = (*hMagaBill)->scale;
  point = (*hMagaBill)->point;
  v15 = pCurrent->m_Items[index];
  v16 = point * index;
  pVertex = v10->pVertex;
  max_length = pVertex->max_length;
  v21 = &pVertex->obj + (v16 + v15);
  v92 = (v16 + v15);
  klass = v21[2].klass;
  if (v15 + 1 < point)
    v23 = v15 + 1;
  else
    v23 = 0;
  v25 = *&v21[2].monitor;
  v24 = *(&v21[2].monitor + 1);
  v91 = v23;
  v96.z = v25;
  v96.w = v24;
  v26 = (v23 + v16);
  *&v96.x = klass;
  v28 = &pVertex->obj + (v23 + v16);
  v29 = v28[2].klass;
  v30 = *&v28[2].monitor;
  LODWORD(v28) = HIDWORD(v28[2].monitor);
  *&dst.x = v29;
  dst.z = v30;
  LODWORD(dst.w) = v28;
  pCount = v10->pCount;
  v34 = pCount->m_Items[index];
  v100.x = x;
  v100.y = y;
  v100.z = z;
  v100.w = w;
  v98 = point;
  v99 = v34;
  SDF_VU0__COPYVECTOR(&dst, v100);
  pTail = (*hMagaBill)->pTail;
  v38 = pTail->m_Items[index];
  s_rad = v38->s_rad + 0.21817;
  v38->s_rad = s_rad;
  if (s_rad >= 3.1416)
  {
    v38->s_rad = s_rad + -3.1416;
    RandFloat = sdfGetRandFloat(&dds3Effect_Rand);
    s_rad = v38->s_rad;
    v38->scale = RandFloat * 1.5;
  }
  v42 = sdfSin(s_rad);
  v43 = v38->scale;
  v44 = (*hMagaBill)->pVertex;
  v45 = dst.y;
  v46 = dst.z;
  v47 = dst.w;
  v49 = (&v44->obj + v26);
  v49[8] = dst.x;
  v49[9] = v45;
  v49[10] = v46;
  v49[11] = v47;
  pScale = (*hMagaBill)->pScale;
  v52 = (pScale + 4 * v26);
  v53 = v92;
  v52[8] = (v42 * v43) + 1.0;
  v54 = v98;
  if (v99 >= 8)
  {
    if (v91 >= 7)
      v55 = 0;
    else
      v55 = v98;
    v56 = v91 + v55 + v16;
    v57 = *hMagaBill;
    v58 = v56 - 7;
    v59 = v58;
    v60 = (*hMagaBill)->pVertex;
    v62 = &v60->obj + v58;
    v63 = v62[2].klass;
    monitor = v62[2].monitor;
    LODWORD(v62) = HIDWORD(v62[2].monitor);
    v93 = v63;
    v94 = __PAIR64__(v62, monitor);
    v65 = v57->pTail;
    v67 = v65->m_Items[index];
    v68 = v67->radian + v57->t;
    v67->radian = v68;
    if (v68 < 6.2832)
      goto LABEL_76;
    width = v67->width;
    v67->radian = v68 + -6.2832;
    if (width >= 1.0)
    {
      if (width <= 0.5)
        goto LABEL_76;
      v70 = (sdfGetRandFloat(&dds3Effect_Rand) * 0.4) + 0.6;
      v71 = -0.25;
    }
    else
    {
      v70 = (sdfGetRandFloat(&dds3Effect_Rand) * 0.4) + 0.6;
      v71 = 0.25;
    }
    v67->width = width + (v70 * v71);
LABEL_76:
    SDF_VU0__LOADVECTOR(dds3CameraEyePos);
    SDF_VU0__LOADVECTOR_B(dds3CameraTargetPos);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_A_TO_C();
    v101.x = x;
    v101.y = y;
    v101.z = z;
    v101.w = w;
    SDF_VU0__LOADVECTOR(v101);
    SDF_VU0__LOADVECTOR_B(v96);
    SDF_VU0__SUBVECTOR();
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__OUTERPRODUCT();
    SDF_VU0__NORMALIZE();
    SDF_VU0__STOREVECTOR(&p);
    radian = v67->radian;
    sdfSin(radian);
    sub_854710(&v93, 0);
    sub_854710(&p, 0);
    sub_854930(&v93, 0);
    sub_854710(&v93, 1u);
    sub_854710(&p, 1u);
    sub_854930(&v93, 1u);
    sub_854710(&v93, 2u);
    sub_854710(&p, 2u);
    sub_854930(&v93, 2u);
    v75 = (*hMagaBill)->pVertex;
    v76 = HIDWORD(v93);
    v78 = v94;
    v77 = HIDWORD(v94);
    v80 = &v75->obj + v59;
    LODWORD(v80[2].klass) = v93;
    HIDWORD(v80[2].klass) = v76;
    LODWORD(v80[2].monitor) = v78;
    HIDWORD(v80[2].monitor) = v77;
    v54 = v98;
    v53 = v92;
  }
  v102.x = x;
  v102.y = y;
  v102.z = z;
  v102.w = w;
  SDF_VU0__LOADVECTOR_B(v102);
  SDF_VU0__LOADVECTOR(v96);
  SDF_VU0__SUBVECTOR();
  if (SDF_VU0__GETLENGTH() > (scale * 3.0))
  {
    sub_854930(&p, 0);
    sub_854930(&p, 1u);
    sub_854930(&p, 2u);
    SDF_VU0__NORMALIZE();
    SDF_VU0__LOADVECTOR_B(p);
    SDF_VU0__MULVECTOR();
  }
  SDF_VU0__STOREVECTOR(&v96);
  v81 = (*hMagaBill)->pVertex;
  if (v99 + 1 <= v54)
    LOWORD(v54) = v99 + 1;
  v82 = v96.y;
  v84 = v96.z;
  v83 = v96.w;
  v86 = (&v81->obj + v53);
  v86[8] = v96.x;
  v86[9] = v82;
  v86[10] = v84;
  v86[11] = v83;
  v87 = (*hMagaBill)->pCurrent;
  v87->m_Items[index] = v91;
  v89 = (*hMagaBill)->pCount;
  v89->m_Items[index] = v54;
}

// 0x16ad470
void *dds3MagatuhiGetHandle(dds3MagatuhiPar_tag *hMagaPar) {
  return hMagaPar->pHandle;
}

// 0x16b0b30
u32 dds3MagatuhiGetType(dds3MagatuhiPar_tag *hMagaPar) {
  return hMagaPar->type;
}

// 0x16b5410
dds3MagatuhiPar_tag *dds3MagatuhiParCopy(void **hData, s32 bPos) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s32 v10;
  u64 *monitor;
  s64 v12;
  s64 v13;
  char *v14;
  s64 *v15;
  u64 *v16;
  s64 v17;
  s64 v18;
  char *v19;
  s64 *v20;
  s64 v21;
  s64 v22;
  char *v23;
  s64 *v24;
  s64 v25;
  s64 v26;
  Il2CppObject *v27;
  s64 v28;
  s64 v29;
  char *v31;
  s64 *v32;
  char *v33;
  s64 *v34;
  u64 v35[2];
  char *v36;

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v35);
      if ((v35[0] & 1) != 0)
        v8 = v36;
      else
        v8 = v35 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = v5[1].klass;
  switch (v10)
  {
    case 0:
      monitor = v5[1].monitor;
      v12 = *monitor;
      if (*(*monitor + 288LL) < v13 || *(*(v12 + 200) + 8 * v13 - 8) != effMagaSmokeConv_tag)
      {
        sub_8FC2C0(*(v12 + 64), effMagaSmokeConv_tag, v35);
        if ((v35[0] & 1) != 0)
          v14 = v36;
        else
          v14 = v35 + 1;
        v15 = sub_8C4940(v14);
      }
      goto LABEL_34;
    case 1:
      monitor = v5[1].monitor;
      v28 = *monitor;
      if (*(*monitor + 288LL) < v29 || *(*(v28 + 200) + 8 * v29 - 8) != effMagaPoint4_tag)
      {
        sub_8FC2C0(*(v28 + 64), effMagaPoint4_tag, v35);
        if ((v35[0] & 1) != 0)
          v33 = v36;
        else
          v33 = v35 + 1;
        v34 = sub_8C4940(v33);
      }
LABEL_34:
      v27 = monitor[2];
      break;
    case 2:
      v16 = v5[1].monitor;
      v21 = *v16;
      if (*(*v16 + 288LL) < v22 || *(*(v21 + 200) + 8 * v22 - 8) != effMagaCylinder_tag)
      {
        sub_8FC2C0(*(v21 + 64), effMagaCylinder_tag, v35);
        if ((v35[0] & 1) != 0)
          v23 = v36;
        else
          v23 = v35 + 1;
        v24 = sub_8C4940(v23);
      }
      goto LABEL_31;
    case 3:
      v16 = v5[1].monitor;
      v25 = *v16;
      if (*(*v16 + 288LL) < v26 || *(*(v25 + 200) + 8 * v26 - 8) != effMagaSpiral_tag)
      {
        sub_8FC2C0(*(v25 + 64), effMagaSpiral_tag, v35);
        if ((v35[0] & 1) != 0)
          v31 = v36;
        else
          v31 = v35 + 1;
        v32 = sub_8C4940(v31);
      }
      goto LABEL_31;
    case 4:
      v16 = v5[1].monitor;
      v17 = *v16;
      if (*(*v16 + 288LL) < v18 || *(*(v17 + 200) + 8 * v18 - 8) != effMagaSmoke_tag)
      {
        sub_8FC2C0(*(v17 + 64), effMagaSmoke_tag, v35);
        if ((v35[0] & 1) != 0)
          v19 = v36;
        else
          v19 = v35 + 1;
        v20 = sub_8C4940(v19);
      }
LABEL_31:
      v27 = v16[10];
      break;
    default:
      v27 = 0;
      break;
  }
  return dds3MagatuhiParCreateTbl(v10, v27, 0);
}

// 0x16b4160
dds3MagatuhiPar_tag *dds3MagatuhiParCreate(u16 type, void *pData, s32 bPos) {
  dds3MagatuhiPar_tag_o *v7;
  struct dds3MagaFuncTable_t_array *EffMagatuhiParTable;

  v7 = Allocate(dds3MagatuhiPar_tag);
  _ctor(v7, 0);
  v7->pHandle = Invoke(
                         EffMagatuhiParTable->m_Items[type]->Create,
                         pData,
                         bPos,
                         0,
                         0);
  v7->type = type;
  return v7;
}

// 0x16b4250
dds3MagatuhiPar_tag *dds3MagatuhiParCreateTbl(u16 type, void *pData, s32 bPos) {
  dds3MagatuhiPar_tag_o *v7;
  struct dds3MagaFuncTable_t_array *EffMagatuhiParTable;

  v7 = Allocate(dds3MagatuhiPar_tag);
  _ctor(v7, 0);
  v7->pHandle = Invoke(
                         EffMagatuhiParTable->m_Items[type]->Create,
                         pData,
                         bPos,
                         1,
                         0);
  v7->type = type;
  return v7;
}

// 0x16b44b0
void dds3MagatuhiParDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct dds3MagaFuncTable_t_array *EffMagatuhiParTable;
  s64 klass_low;
  u64 v12[3];

  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v12);
      if ((v12[0] & 1) != 0)
        v6 = v12[2];
      else
        v6 = v12 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  klass_low = LODWORD(v3[1].klass);
  Invoke(EffMagatuhiParTable->m_Items[klass_low]->Delete, &v3[1].monitor, 0);
}

// 0x16b4350
void dds3MagatuhiParDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct dds3MagaFuncTable_t_array *EffMagatuhiParTable;
  s64 klass_low;
  u64 v12[3];

  v3 = *hData;
  if (v3)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v12);
      if ((v12[0] & 1) != 0)
        v6 = v12[2];
      else
        v6 = v12 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  klass_low = LODWORD(v3[1].klass);
  Invoke(EffMagatuhiParTable->m_Items[klass_low]->Draw, &v3[1].monitor, 0);
}

// 0x16b4340
void dds3MagatuhiParDrawOff(void **hData) {
  ;
}

// 0x16b5010
u8 dds3MagatuhiParGetLoop(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  u64 *monitor;
  s64 v9;
  s64 v10;
  u8 *v11;
  u64 *v12;
  s64 v13;
  s64 v14;
  char *v15;
  s64 *v16;
  s64 v17;
  s64 v18;
  char *v19;
  s64 *v20;
  s64 v21;
  s64 v22;
  u64 *v23;
  s64 v24;
  s64 v25;
  u8 result;
  char *v27;
  s64 *v28;
  char *v29;
  s64 *v30;
  char *v31;
  s64 *v32;
  u64 v33[2];
  char *v34;

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v33);
      if ((v33[0] & 1) != 0)
        v6 = v34;
      else
        v6 = v33 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  switch (LODWORD(v3[1].klass))
  {
    case 0:
      monitor = v3[1].monitor;
      v9 = *monitor;
      if (*(*monitor + 288LL) < v10 || *(*(v9 + 200) + 8 * v10 - 8) != effMagaSmokeConv_tag)
      {
        sub_8FC2C0(*(v9 + 64), effMagaSmokeConv_tag, v33);
        if ((v33[0] & 1) != 0)
          v27 = v34;
        else
          v27 = v33 + 1;
        v28 = sub_8C4940(v27);
      }
      v11 = (monitor[2] + 48LL);
      goto LABEL_32;
    case 1:
      v23 = v3[1].monitor;
      v24 = *v23;
      if (*(*v23 + 288LL) < v25 || *(*(v24 + 200) + 8 * v25 - 8) != effMagaPoint4_tag)
      {
        sub_8FC2C0(*(v24 + 64), effMagaPoint4_tag, v33);
        if ((v33[0] & 1) != 0)
          v31 = v34;
        else
          v31 = v33 + 1;
        v32 = sub_8C4940(v31);
      }
      v11 = (v23[2] + 24LL);
      goto LABEL_32;
    case 2:
      v12 = v3[1].monitor;
      v17 = *v12;
      if (*(*v12 + 288LL) < v18 || *(*(v17 + 200) + 8 * v18 - 8) != effMagaCylinder_tag)
      {
        sub_8FC2C0(*(v17 + 64), effMagaCylinder_tag, v33);
        if ((v33[0] & 1) != 0)
          v19 = v34;
        else
          v19 = v33 + 1;
        v20 = sub_8C4940(v19);
      }
      goto LABEL_28;
    case 3:
      v12 = v3[1].monitor;
      v21 = *v12;
      if (*(*v12 + 288LL) < v22 || *(*(v21 + 200) + 8 * v22 - 8) != effMagaSpiral_tag)
      {
        sub_8FC2C0(*(v21 + 64), effMagaSpiral_tag, v33);
        if ((v33[0] & 1) != 0)
          v29 = v34;
        else
          v29 = v33 + 1;
        v30 = sub_8C4940(v29);
      }
      goto LABEL_28;
    case 4:
      v12 = v3[1].monitor;
      v13 = *v12;
      if (*(*v12 + 288LL) < v14 || *(*(v13 + 200) + 8 * v14 - 8) != effMagaSmoke_tag)
      {
        sub_8FC2C0(*(v13 + 64), effMagaSmoke_tag, v33);
        if ((v33[0] & 1) != 0)
          v15 = v34;
        else
          v15 = v33 + 1;
        v16 = sub_8C4940(v15);
      }
LABEL_28:
      v11 = (v12[10] + 32LL);
LABEL_32:
      result = *v11;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// 0x16b4650
u16 dds3MagatuhiParGetState(void **hData) {
  return 1;
}

// 0x16b4610
void dds3MagatuhiParReset(void **hData) {

}

// 0x16b4c10
void dds3MagatuhiParSetLoop(void **hData, u8 loop) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 *monitor;
  s64 v11;
  s64 v12;
  u8 *v13;
  u64 *v14;
  s64 v15;
  s64 v16;
  char *v17;
  s64 *v18;
  s64 v19;
  s64 v20;
  char *v21;
  s64 *v22;
  s64 v23;
  s64 v24;
  u64 *v25;
  s64 v26;
  s64 v27;
  char *v28;
  s64 *v29;
  char *v30;
  s64 *v31;
  char *v32;
  s64 *v33;
  u64 v34[2];
  char *v35;

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v34);
      if ((v34[0] & 1) != 0)
        v8 = v35;
      else
        v8 = v34 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  switch (LODWORD(v5[1].klass))
  {
    case 0:
      monitor = v5[1].monitor;
      v11 = *monitor;
      if (*(*monitor + 288LL) < v12 || *(*(v11 + 200) + 8 * v12 - 8) != effMagaSmokeConv_tag)
      {
        sub_8FC2C0(*(v11 + 64), effMagaSmokeConv_tag, v34);
        if ((v34[0] & 1) != 0)
          v28 = v35;
        else
          v28 = v34 + 1;
        v29 = sub_8C4940(v28);
      }
      v13 = (monitor[2] + 48LL);
      goto LABEL_32;
    case 1:
      v25 = v5[1].monitor;
      v26 = *v25;
      if (*(*v25 + 288LL) < v27 || *(*(v26 + 200) + 8 * v27 - 8) != effMagaPoint4_tag)
      {
        sub_8FC2C0(*(v26 + 64), effMagaPoint4_tag, v34);
        if ((v34[0] & 1) != 0)
          v32 = v35;
        else
          v32 = v34 + 1;
        v33 = sub_8C4940(v32);
      }
      v13 = (v25[2] + 24LL);
      goto LABEL_32;
    case 2:
      v14 = v5[1].monitor;
      v19 = *v14;
      if (*(*v14 + 288LL) < v20 || *(*(v19 + 200) + 8 * v20 - 8) != effMagaCylinder_tag)
      {
        sub_8FC2C0(*(v19 + 64), effMagaCylinder_tag, v34);
        if ((v34[0] & 1) != 0)
          v21 = v35;
        else
          v21 = v34 + 1;
        v22 = sub_8C4940(v21);
      }
      goto LABEL_28;
    case 3:
      v14 = v5[1].monitor;
      v23 = *v14;
      if (*(*v14 + 288LL) < v24 || *(*(v23 + 200) + 8 * v24 - 8) != effMagaSpiral_tag)
      {
        sub_8FC2C0(*(v23 + 64), effMagaSpiral_tag, v34);
        if ((v34[0] & 1) != 0)
          v30 = v35;
        else
          v30 = v34 + 1;
        v31 = sub_8C4940(v30);
      }
      goto LABEL_28;
    case 4:
      v14 = v5[1].monitor;
      v15 = *v14;
      if (*(*v14 + 288LL) < v16 || *(*(v15 + 200) + 8 * v16 - 8) != effMagaSmoke_tag)
      {
        sub_8FC2C0(*(v15 + 64), effMagaSmoke_tag, v34);
        if ((v34[0] & 1) != 0)
          v17 = v35;
        else
          v17 = v34 + 1;
        v18 = sub_8C4940(v17);
      }
LABEL_28:
      v13 = (v14[10] + 32LL);
LABEL_32:
      *v13 = loop;
      break;
    default:
      return;
  }
}

// 0x16b4690
void dds3MagatuhiParSetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppObject *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  struct dds3MagaFuncTable_t_array *EffMagatuhiParTable;
  s64 klass_low;
  struct dds3MagaFuncTable_t_array *v18;
  s64 v19;
  u64 v21[3];
  UnityEngine_Vector4_o v22;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  v8 = *hData;
  if (v8)
  {
    klass = v8->klass;
    if (v8->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v21);
      if ((v21[0] & 1) != 0)
        v11 = v21[2];
      else
        v11 = v21 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  klass_low = LODWORD(v8[1].klass);
  if (EffMagatuhiParTable->m_Items[klass_low]->SetPos)
  {
    v18 = EffMagatuhiParTable;
    v19 = LODWORD(v8[1].klass);
    v22.x = x;
    v22.y = y;
    v22.z = z;
    v22.w = w;
    Invoke(v18->m_Items[v19]->SetPos, &v8[1].monitor, v22, 0);
  }
}

// 0x16b4a50
void dds3MagatuhiParSetRGBA(void **hData, u32 abgr) {
  u32 v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct dds3MagaFuncTable_t_array *EffMagatuhiParTable;
  s64 klass_low;
  struct dds3MagaFuncTable_t_array *v15;
  s64 v16;
  u64 v18[3];

  v3 = abgr;
  v5 = *hData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v18);
      if ((v18[0] & 1) != 0)
        v8 = v18[2];
      else
        v8 = v18 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  klass_low = LODWORD(v5[1].klass);
  if (EffMagatuhiParTable->m_Items[klass_low]->SetRGBA)
  {
    v15 = EffMagatuhiParTable;
    v16 = LODWORD(v5[1].klass);
    Invoke(v15->m_Items[v16]->SetRGBA, &v5[1].monitor, v3, 0);
  }
}

// 0x16b4870
void dds3MagatuhiParSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
  UnityEngine_Matrix4x4_o *v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct dds3MagaFuncTable_t_array *EffMagatuhiParTable;
  s64 klass_low;
  struct dds3MagaFuncTable_t_array *v15;
  s64 v16;
  s64 v18;
  s64 v19;
  s64 v20;
  dds3MagaFuncTable_t_SetRotateMatrixDelegate_o *SetRotateMatrix;
  s64 v22;
  s64 v23;
  s64 v24;
  UnityEngine_Matrix4x4_o v25;
  u64 v26[3];

  v3 = pMatrix;
  v5 = *hData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v26);
      if ((v26[0] & 1) != 0)
        v8 = v26[2];
      else
        v8 = v26 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  klass_low = LODWORD(v5[1].klass);
  if (EffMagatuhiParTable->m_Items[klass_low]->SetRotateMatrix)
  {
    v15 = EffMagatuhiParTable;
    v16 = LODWORD(v5[1].klass);
    v18 = *&v3->m00;
    v19 = *&v3->m20;
    v20 = *&v3->m21;
    SetRotateMatrix = v15->m_Items[v16]->SetRotateMatrix;
    *&v25.m01 = *&v3->m01;
    *&v25.m21 = v20;
    *&v25.m00 = v18;
    *&v25.m20 = v19;
    v22 = *&v3->m02;
    v23 = *&v3->m22;
    v24 = *&v3->m23;
    *&v25.m03 = *&v3->m03;
    *&v25.m23 = v24;
    *&v25.m02 = v22;
    *&v25.m22 = v23;
    Invoke(SetRotateMatrix, &v5[1].monitor, &v25, 0);
  }
}

// 0x16b5820
void dds3MagatuhiParSetScale(void **hData, f32 scale) {

}

// 0x16af2d0
effMagaCylinder_tag *effMagaCylinderCreate(void *pData, s32 bPos, bool tbldata) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 name_low;
  u64 *v15;
  u64 *v16;
  u64 *v17;
  u64 v19;
  effMagatuhiParams_t_o *v20;
  s64 v21;
  u64 v22;
  u32 *v23;
  u64 *v24;
  u64 v27;
  s64 v29;
  u32 Rand;
  s32 bPosa;
  u64 v35[2];
  char *v36;

  bPosa = bPos;
  if (tbldata)
  {
    if (pData)
    {
      klass = pData->klass;
      if (pData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaCylinderParam_t)
      {
        sub_8FC2C0(klass->_1.element_class, effMagaCylinderParam_t, v35);
        if ((v35[0] & 1) != 0)
          v8 = v36;
        else
          v8 = v35 + 1;
        v9 = sub_8C4940(v8);
      }
    }
  }
  else
  {
    if (pData)
    {
      Interface = QueryInterface(pData, byte);
      if (!Interface)
      {
        sub_8FC2C0(pData->klass->_1.element_class, v10, v35);
        if ((v35[0] & 1) != 0)
          v12 = v36;
        else
          v12 = v35 + 1;
        v13 = sub_8C4940(v12);
      }
    }
    else
    {
      Interface = 0;
    }
    pData = Allocate(effMagaCylinderParam_t);
    effMagaCylinderParam_t___ctor(pData);
    effMagaCylinderParam_t__bCopy(pData, Interface, &bPosa);
  }
  name_low = LODWORD(pData[5].klass->_1.name);
  v15 = Allocate(effMagaCylinder_tag);
  _ctor(v15, 0);
  if (tbldata)
  {
    v16 = Allocate(effMagaCylinderParam_t);
    effMagaCylinderParam_t___ctor(v16);
    v15[10] = v16;
    v17 = v15 + 10;
    effMagaCylinderParam_t__pClone(pData, v15 + 10);
  }
  else
  {
    v15[10] = pData;
    v17 = v15 + 10;
  }
  v15[11] = NewSpecific(effMagaCylinderPart_tag, name_low);
  *(v15 + 26) = -2139062144;
  v15[14] = 0;
  SDF_VU0__STOREIDENTITY((v15 + 2), 0);
  v19 = v15[10];
  if (*(v19 + 40) <= 0)
  {
    *(v19 + 40) = 1;
    v19 = *v17;
  }
  v20 = *(v19 + 80);
  v15[12] = effMagatuhiCreate(v20);
  if (name_low)
  {
    v21 = *(*v17 + 40);
    v22 = 0;
    while (1)
    {
      v23 = v15[11];
      v24 = Allocate(effMagaCylinderPart_tag);
      _ctor(v24, 0);
      *&v23[2 * v22 + 8] = v24;
      v27 = v15[11];
      v29 = *(v27 + 8 * v22 + 32);
        break;
      if ((byte_3F5A39D & 1) == 0)
        goto LABEL_38;
LABEL_39:
      else
      {
          goto LABEL_42;
      }
      Rand = sdfGetRand(&dds3Effect_Rand);
      ++v22;
      *(v29 + 16) = Rand / v21 * v21 - Rand;
      if (name_low == v22)
        return v15;
    }
    if ((byte_3F5A39D & 1) != 0)
      goto LABEL_39;
LABEL_38:
    goto LABEL_39;
  }
  return v15;
}

// 0x16af700
void effMagaCylinderDelete(void **pData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effMagatuhi_tag_o **v8;
  u64 v9[3];

  v3 = *pData;
  if (*pData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaCylinder_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaCylinder_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[6];
  effMagatuhiDelete(v8);
}

// 0x16afc90
void effMagaCylinderDraw(void **pData) {
  effMagaCylinder_tag_o *v3;
  effMagaCylinder_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct effMagaCylinderParam_t_o *param;
  s64 number;
  s32 life;
  s32 timing;
  s32 loop;
  u32 abgr;
  u64 v16;
  struct effMagaCylinderPart_tag_array *pPart;
  effMagaCylinderPart_tag_o *v19;
  s32 frame;
  f32 rotate;
  f32 radius;
  f32 radius_s;
  f32 v27;
  struct effMagaCylinderPart_tag_array *v28;
  f32 v30;
  s32 v31;
  u32 v32;
  s32 v33;
  struct System_UInt32_array *pRGBA;
  u32 Rand;
  System_String_o *v37;
  dds3MagatuhiBill_tag_o *v38;
  s32 fade_out;
  s32 v40;
  s32 v41;
  dds3MagatuhiBill_tag_o *v42;
  s32 fade_in;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  dds3MagatuhiBill_tag_o *hMagaBill;
  effMagaCylinder_tag_o *pMagaCylinder;
  u64 v49[4];

  hMagaBill = 0;
  pMagaCylinder = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  v3 = *pData;
  if (*pData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaCylinder_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaCylinder_tag, v49);
      if ((v49[0] & 1) != 0)
        v6 = v49[2];
      else
        v6 = v49 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  param = v3->param;
  number = param->MagaParam->number;
  life = param->life;
  timing = param->timing;
  fade_in = param->fade_in;
  fade_out = param->fade_out;
  loop = param->loop;
  abgr = v3->abgr;
  v42 = v3->pMagatuhi->hMagaBill;
  hMagaBill = v42;
  pMagaCylinder = v3;
  SDF_VU0__COPYVECTOR(&dst, param->pos);
  memmove(&dest, &v3->fields, 0x40u);
  SDF_VU0__LOADMATRIX(&dest);
  if (number)
  {
    v41 = (abgr >> 23) & 0x1FE;
    v40 = abgr & 0xFFFFFF;
    v16 = 0;
    while (1)
    {
      while (1)
      {
        pPart = v3->pPart;
        v19 = pPart->m_Items[v16];
        frame = v19->frame;
        if (frame)
        {
          if (frame >= 1 && life >= frame)
          {
            rotate = v19->rotate;
            sdfCos(rotate);
            sub_854930(&p, 0);
            sub_854930(&p, 1u);
            sdfSin(rotate);
            sub_854930(&p, 2u);
            SDF_VU0__LOADVECTOR_B(dst);
            SDF_VU0__LOADVECTOR(p);
            SDF_VU0__APPLYMATRIX();
            SDF_VU0__ADDVECTOR();
            SDF_VU0__STOREVECTOR(&p);
            radius = v19->radius;
            radius_s = v19->radius_s;
            v19->rotate = v19->rotate + v19->rotate_s;
            v19->radius = radius + radius_s;
            if (frame >= fade_in)
            {
              v27 = 1.0;
              if (life - frame <= fade_out)
                v27 = (life - frame) / fade_out;
            }
            else
            {
              v27 = frame / fade_in;
            }
            v30 = v27 * 127.0;
            v31 = v30;
            if (v30 >= 0.0)
              LOBYTE(v31) = v30;
            v32 = (v41 * (v31 << 16)) & 0xFF000000;
            v33 = v40 | v32;
            pRGBA = v42->pRGBA;
            pRGBA->m_Items[v16] = v33;
            dds3MagatuhiBillSetVertex(&hMagaBill, v16, p);
          }
        }
        else
        {
          effMagaCylinderPartInit(&pMagaCylinder, v16);
          v28 = v3->pPart;
          v19 = v28->m_Items[v16];
        }
        if (loop && life <= frame)
          break;
        ++v16;
        ++v19->frame;
        if (number == v16)
          goto LABEL_58;
      }
        break;
      if ((byte_3F5A39D & 1) == 0)
        goto LABEL_45;
LABEL_46:
      Rand = sdfGetRand(&dds3Effect_Rand);
      ++v16;
      v19->frame = Rand / timing * timing - Rand;
      if (number == v16)
        goto LABEL_58;
    }
    if ((byte_3F5A39D & 1) != 0)
      goto LABEL_46;
LABEL_45:
    goto LABEL_46;
  }
LABEL_58:
  v37 = "effMagaCylinderDraw";
  v38 = v3->pMagatuhi->hMagaBill;
  dds3MagatuhiBillDraw(v38, v37);
}

// 0x16af820
void effMagaCylinderPartInit(effMagaCylinder_tag **pMagaCylinder, u32 index) {
  struct effMagaCylinderPart_tag_array *pPart;
  effMagaCylinderPart_tag_o *v7;
  f32 height;
  struct effMagaCylinderParam_t_o *param;
  f32 rotate_s;
  f32 rotate_r;
  struct effMagaCylinderParam_t_o *v17;
  f32 radius_s_r;
  f32 radius_s;
  struct effMagaCylinderParam_t_o *v22;
  f32 radius_e_r;
  f32 radius_e;
  struct effMagatuhi_tag_o *pMagatuhi;
  dds3MagatuhiBill_tag_o **p_hMagaBill;
  struct System_UInt32_array *pRGBA;

  pPart = (*pMagaCylinder)->pPart;
  v7 = pPart->m_Items[index];
  v7->frame = 0;
  height = (*pMagaCylinder)->param->height;
LABEL_9:
  v7->height = -(height * sdfGetRandFloat(&dds3Effect_Rand));
  else
  {
      goto LABEL_25;
  }
LABEL_25:
  v7->rotate = sdfGetRandFloat(&dds3Effect_Rand) * 6.2832;
  param = (*pMagaCylinder)->param;
  rotate_s = param->rotate_s;
  rotate_r = param->rotate_r;
  else
  {
      goto LABEL_33;
  }
LABEL_33:
  v7->rotate_s = rotate_s
                      * ((1.0 - rotate_r)
                       + (rotate_r * sdfGetRandFloat(&dds3Effect_Rand)));
  v17 = (*pMagaCylinder)->param;
  radius_s_r = v17->radius_s_r;
  radius_s = v17->radius_s;
  else
  {
      goto LABEL_41;
  }
LABEL_41:
  v7->radius = radius_s
                    * ((1.0 - radius_s_r)
                     + (radius_s_r * sdfGetRandFloat(&dds3Effect_Rand)));
  v22 = (*pMagaCylinder)->param;
  radius_e_r = v22->radius_e_r;
  radius_e = v22->radius_e;
  else
  {
      goto LABEL_49;
  }
LABEL_49:
  v7->radius_s = ((radius_e
                        * ((1.0 - radius_e_r)
                         + (radius_e_r
                          * sdfGetRandFloat(&dds3Effect_Rand))))
                       - v7->radius)
                      / (*pMagaCylinder)->param->life;
  pMagatuhi = (*pMagaCylinder)->pMagatuhi;
  p_hMagaBill = &pMagatuhi->hMagaBill;
LABEL_53:
  dds3MagatuhiBillPartsInit(p_hMagaBill, index);
  pRGBA = (*pMagaCylinder)->pMagatuhi->hMagaBill->pRGBA;
  pRGBA->m_Items[index] = 0;
}

// 0x16b05a0
void effMagaCylinderRandomize(effHandle_t **hEffect) {
  Il2CppObject *pwork;
  dds3MagatuhiPar_tag_c *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  effMagaCylinder_tag_o **v7;
  effMagaCylinder_tag_o *v8;
  effMagaCylinder_tag_o *v9;
  effMagaCylinder_tag_c *v10;
  s64 v11;
  char *v12;
  s64 *v13;
  s64 v14;
  s64 v15;
  s64 v16;
  u64 v17;
  s64 v18;
  dds3MagatuhiBill_tag_o *v19;
  u64 v22;
  s64 v25;
  s64 v27;
  s64 Rand;
  f32 v29;
  f32 v30;
  s64 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  s64 v35;
  f32 v36;
  f32 v37;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  char *v44;
  s64 *v45;
  char *v46;
  s64 *v47;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  effMagaCylinder_tag_o *pMagaCylinder;
  dds3MagatuhiBill_tag_o *hMagaBill;
  u64 v53[2];
  char *v54;
  UnityEngine_Vector4_o v55;

  pMagaCylinder = 0;
  hMagaBill = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  if ((*hEffect)->major == 3)
  {
    pwork = (*hEffect)->pwork;
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v53);
      if ((v53[0] & 1) != 0)
        v44 = v54;
      else
        v44 = v53 + 1;
      v45 = sub_8C4940(v44);
    }
    if (LODWORD(pwork[1].klass) == 2)
    {
      v7 = (*hEffect)->pwork;
      v8 = *v7;
      if (LOBYTE((*v7)[2].matrix.m02) < typeHierarchyDepth
        || *(v8[1].param + typeHierarchyDepth - 1) != v4)
      {
        sub_8FC2C0(*&v8->matrix.m03, v4, v53);
        if ((v53[0] & 1) != 0)
          v46 = v54;
        else
          v46 = v53 + 1;
        v47 = sub_8C4940(v46);
      }
      v9 = v7[3];
      if (v9)
      {
        v10 = v9->klass;
        if (v9->klass->_2.typeHierarchyDepth < v11 || v10->_2.typeHierarchy[v11 - 1] != effMagaCylinder_tag)
        {
          sub_8FC2C0(v10->_1.element_class, effMagaCylinder_tag, v53);
          if ((v53[0] & 1) != 0)
            v12 = v54;
          else
            v12 = v53 + 1;
          v13 = sub_8C4940(v12);
        }
      }
      v14 = *(&loc_50 + v9);
      v15 = *(v14 + 80);
      v16 = *(v14 + 36);
      v17 = *(v15 + 16);
      v18 = *(v15 + 20);
      v19 = *(*(&loc_60 + v9) + 24LL);
      pMagaCylinder = v7[3];
      hMagaBill = v19;
      SDF_VU0__COPYVECTOR(&dst, *(v14 + 16), 0);
      memmove(&dest, &v9->fields, 0x40u);
      SDF_VU0__LOADMATRIX(&dest);
      if (v17)
      {
        v22 = 0;
        while (1)
        {
          effMagaCylinderPartInit(&pMagaCylinder, v22);
          v25 = *(&loc_58 + v9);
          v27 = *(v25 + 8 * v22 + 32);
            break;
          if ((byte_3F5A39D & 1) == 0)
            goto LABEL_36;
LABEL_37:
          Rand = sdfGetRand(&dds3Effect_Rand);
          v29 = *(v27 + 36);
          v30 = *(v27 + 24);
          v31 = Rand % v16;
          if (v31 <= v18)
            v32 = 0.0;
          else
            v32 = (v31 - v18);
          v34 = *(v27 + 28);
          v33 = *(v27 + 32);
          *(v27 + 16) = v31;
          if (v31 > v18)
            LODWORD(v31) = 0;
          LODWORD(v35) = v18 - v31;
          v36 = v33 + (v32 * v29);
          v37 = v30 + (v34 * v32);
          sub_854930(&p, 3u);
          if (v35 >= 1)
          {
            do
            {
              sdfCos(v37);
              sub_854930(&p, 0);
              sub_854930(&p, 1u);
              sdfSin(v37);
              sub_854930(&p, 2u);
              SDF_VU0__LOADVECTOR_B(dst);
              SDF_VU0__LOADVECTOR(p);
              SDF_VU0__APPLYMATRIX();
              SDF_VU0__ADDVECTOR();
              SDF_VU0__STOREVECTOR(&p);
              x = p.x;
              y = p.y;
              z = p.z;
              w = p.w;
              v55.x = x;
              v55.y = y;
              v55.z = z;
              v55.w = w;
              dds3MagatuhiBillSetVertex(&hMagaBill, v22, v55);
              v37 = v34 + v37;
              v36 = v29 + v36;
              --v35;
            }
            while (v35);
          }
          v22 += 3LL;
          *(v27 + 32) = v36;
          *(v27 + 24) = v37;
          if (v22 >= v17)
            return;
        }
        if ((byte_3F5A39D & 1) != 0)
          goto LABEL_37;
LABEL_36:
        goto LABEL_37;
      }
    }
  }
}

// 0x16b0260
void effMagaCylinderSetPosition(void **pData, sdfVector4_t pPos) {
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
  klass = (*pData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaCylinder_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effMagaCylinder_tag, v12);
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
  SDF_VU0__COPYVECTOR(&(*pData)[5].klass->_1.name, v13, 0);
}

// 0x16b0380
void effMagaCylinderSetRGBA(void **pData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*pData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaCylinder_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effMagaCylinder_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*pData)[6].monitor) = abgr;
}

// 0x16b0470
void effMagaCylinderSetRotateMatrix(void **pData, sdfMatrix4_t *pMatrix) {
  s64 v5;
  s64 v6;
  Il2CppObject *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  UnityEngine_Matrix4x4_o v16;
  u64 v17[3];

  v5 = *&pMatrix->m00;
  v6 = *&pMatrix->m20;
  v7 = *pData;
  v8 = *&pMatrix->m21;
  *&v16.m01 = *&pMatrix->m01;
  *&v16.m21 = v8;
  *&v16.m00 = v5;
  *&v16.m20 = v6;
  v9 = *&pMatrix->m02;
  v10 = *&pMatrix->m22;
  v11 = *&pMatrix->m23;
  *&v16.m03 = *&pMatrix->m03;
  *&v16.m23 = v11;
  *&v16.m02 = v9;
  *&v16.m22 = v10;
  SDF_VU0__LOADMATRIX(&v16);
  if (v7)
  {
    klass = v7->klass;
    if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaCylinder_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaCylinder_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[1]);
}

// 0x16aee40
void effMagaP4Randomize(effHandle_t **hEffect) {
  effMagaPoint4_tag_o **pwork;
  effMagaPoint4_tag_o *v6;
  s64 typeHierarchyDepth;
  effMagaPoint4_tag_o *v8;
  effMagaPoint4_tag_c *klass;
  s64 v10;
  char *v11;
  s64 *v12;
  struct effMagaPoint4Param_t_o *param;
  struct effMagatuhiParams_t_o *MagaParam;
  s64 life;
  u64 number;
  s64 tail;
  dds3MagatuhiBill_tag_o *v18;
  u64 v19;
  struct effMagaPoint4Part_tag_array *pPart;
  effMagaPoint4Part_tag_o *v24;
  s32 v26;
  struct effBezier4PPart_t_array *v27;
  effBezier4PPart_t_o *v29;
  bool v30;
  s64 v31;
  s32 v32;
  f32 v34;
  s64 v35;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  char *v42;
  s64 *v43;
  u64 v44;
  UnityEngine_Vector4_o v45;
  UnityEngine_Vector4_o pOut;
  UnityEngine_Vector4_o p;
  effMagaPoint4_tag_o *pMagaPoint4;
  dds3MagatuhiBill_tag_o *hMagaBill;
  u64 v50[2];
  char *v51;
  UnityEngine_Vector4_o v52;

  pMagaPoint4 = 0;
  hMagaBill = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&pOut.x = 0;
  *&pOut.z = 0;
  *&v45.x = 0;
  *&v45.z = 0;
  pwork = (*hEffect)->pwork;
  v6 = *pwork;
  if (LOBYTE((*pwork)[5].monitor) < typeHierarchyDepth
    || *(v6[3].pBezier4P + typeHierarchyDepth - 1) != dds3MagatuhiPar_tag)
  {
    sub_8FC2C0(v6[1].monitor, dds3MagatuhiPar_tag, v50);
    if ((v50[0] & 1) != 0)
      v42 = v51;
    else
      v42 = v50 + 1;
    v43 = sub_8C4940(v42);
  }
  v8 = pwork[3];
  if (v8)
  {
    klass = v8->klass;
    if (v8->klass->_2.typeHierarchyDepth < v10 || klass->_2.typeHierarchy[v10 - 1] != effMagaPoint4_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaPoint4_tag, v50);
      if ((v50[0] & 1) != 0)
        v11 = v51;
      else
        v11 = v50 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  param = v8->param;
  MagaParam = param->MagaParam;
  life = param->life;
  number = MagaParam->number;
  tail = MagaParam->tail;
  v18 = v8->pMagatuhi->hMagaBill;
  pMagaPoint4 = pwork[3];
  hMagaBill = v18;
  v44 = number;
  if (number)
  {
    v19 = 0;
    while (1)
    {
      effMagaPoint4PartInit(&pMagaPoint4, v19);
      pPart = v8->pPart;
      v24 = pPart->m_Items[v19];
        break;
      if ((byte_3F5A39D & 1) == 0)
        goto LABEL_29;
LABEL_30:
      v26 = sdfGetRand(&dds3Effect_Rand) % life;
      v24->frame = v26;
      v27 = v8->pBezier4P->pPart;
      v29 = v27->m_Items[v19];
      v30 = v26 <= tail;
      v31 = v26 - tail;
      if (v30)
      {
        v29->weight = 0.0;
        v32 = tail - v24->frame;
      }
      else
      {
        v29->weight = v29->step * v31;
        v32 = tail;
      }
      dds3Bezier4PRun(&v8->pBezier4P, v19, &pOut);
      v29->weight = v29->step * v24->frame;
      dds3Bezier4PRun(&v8->pBezier4P, v19, &v45);
      if (v32 >= 1)
      {
        v34 = 0.0;
        v35 = v32;
        do
        {
          SDF_VU0__LOADVECTOR(pOut);
          SDF_VU0__LOADVECTOR_B(v45);
          SDF_VU0__INTERPOLATE(v34);
          SDF_VU0__STOREVECTOR(&p);
          x = p.x;
          y = p.y;
          z = p.z;
          w = p.w;
          v52.x = x;
          v52.y = y;
          v52.z = z;
          v52.w = w;
          v34 = (1.0 / v32) + v34;
          dds3MagatuhiBillSetVertex(&hMagaBill, v19, v52);
          --v35;
        }
        while (v35);
      }
      ++v24->frame;
      v19 += 4LL;
      if (v19 >= v44)
        return;
    }
    if ((byte_3F5A39D & 1) != 0)
      goto LABEL_30;
LABEL_29:
    goto LABEL_30;
  }
}

// 0x16aead0
void effMagaP4SetPoint(effHandle_t **hEffect, effMagaP4Point_t *pP4Point) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *monitor;
  s64 v9;
  s64 v10;
  char *v11;
  s64 *v12;
  s64 v13;
  s64 i;
  struct UnityEngine_Vector4_array *point;
  u64 v16;
  s64 v17;
  struct UnityEngine_Vector4_array *v20;
  s64 v21;
  struct UnityEngine_Vector4_array *v24;
  s64 v25;
  struct System_Single_array *radius;
  s64 v29;
  s32 v31;
  char *v33;
  s64 *v34;
  u64 v35[2];
  char *v36;

  pwork = (*hEffect)->pwork;
  klass = pwork->klass;
  if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
  {
    sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v35);
    if ((v35[0] & 1) != 0)
      v33 = v36;
    else
      v33 = v35 + 1;
    v34 = sub_8C4940(v33);
  }
  monitor = pwork[1].monitor;
  if (monitor)
  {
    v9 = *monitor;
    if (*(*monitor + 288LL) < v10 || *(*(v9 + 200) + 8 * v10 - 8) != effMagaPoint4_tag)
    {
      sub_8FC2C0(*(v9 + 64), effMagaPoint4_tag, v35);
      if ((v35[0] & 1) != 0)
        v11 = v36;
      else
        v11 = v35 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  v13 = 8;
  for (i = 32; i != 96; i += 16)
  {
    point = pP4Point->point;
    v16 = v13 - 8;
    v17 = *(monitor[2] + 16LL);
    sub_854710(point + i, 0);
    sub_854930(v17 + i, 0);
    v20 = pP4Point->point;
    v21 = *(monitor[2] + 16LL);
    sub_854710(v20 + i, 1u);
    sub_854930(v21 + i, 1u);
    v24 = pP4Point->point;
    v25 = *(monitor[2] + 16LL);
    sub_854710(v24 + i, 2u);
    sub_854930(v25 + i, 2u);
    radius = pP4Point->radius;
    v29 = *(monitor[2] + 48LL);
    v31 = *(&radius->obj.klass + v13);
    *(v29 + 4 * v13++) = v31;
  }
}

// 0x16ad480
effMagaPoint4_tag *effMagaPoint4Create(void *pData, s32 bPos, bool tbldata) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  u64 *v15;
  u64 *v16;
  u64 *v17;
  u64 *v18;
  u64 v20;
  effMagatuhiParams_t_o *v21;
  s64 v23;
  u64 v24;
  u32 *v25;
  u64 *v26;
  u64 v29;
  s64 v31;
  u32 Rand;
  s32 bPosa;
  u64 v37[2];
  char *v38;

  bPosa = bPos;
  if (tbldata)
  {
    if (pData)
    {
      klass = pData->klass;
      if (pData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaPoint4Param_t)
      {
        sub_8FC2C0(klass->_1.element_class, effMagaPoint4Param_t, v37);
        if ((v37[0] & 1) != 0)
          v8 = v38;
        else
          v8 = v37 + 1;
        v9 = sub_8C4940(v8);
      }
    }
  }
  else
  {
    if (pData)
    {
      Interface = QueryInterface(pData, byte);
      if (!Interface)
      {
        sub_8FC2C0(pData->klass->_1.element_class, v10, v37);
        if ((v37[0] & 1) != 0)
          v12 = v38;
        else
          v12 = v37 + 1;
        v13 = sub_8C4940(v12);
      }
    }
    else
    {
      Interface = 0;
    }
    pData = Allocate(effMagaPoint4Param_t);
    effMagaPoint4Param_t___ctor(pData);
    effMagaPoint4Param_t__bCopy(pData, Interface, &bPosa);
  }
  v14 = *(pData[3].monitor + 4);
  v15 = Allocate(effMagaPoint4_tag);
  _ctor(v15, 0);
  if (tbldata)
  {
    v16 = Allocate(effMagaPoint4Param_t);
    effMagaPoint4Param_t___ctor(v16);
    v15[2] = v16;
    v17 = v15 + 2;
    effMagaPoint4Param_t__pClone(pData, v15 + 2);
  }
  else
  {
    v15[2] = pData;
    v17 = v15 + 2;
  }
  v18 = NewSpecific(effMagaPoint4Part_tag, v14);
  v20 = v15[2];
  v15[3] = v18;
  v15[6] = 0;
  if (*(v20 + 32) <= 0)
  {
    *(v20 + 32) = 1;
    v20 = *v17;
  }
  v21 = *(v20 + 56);
  v15[5] = effMagatuhiCreate(v21);
  v15[4] = dds3Bezier4PCreate(v14);
  if (v14)
  {
    v23 = *(*v17 + 32);
    v24 = 0;
    while (1)
    {
      v25 = v15[3];
      v26 = Allocate(effMagaPoint4Part_tag);
      _ctor(v26, 0);
      *&v25[2 * v24 + 8] = v26;
      v29 = v15[3];
      v31 = *(v29 + 8 * v24 + 32);
        break;
      if ((byte_3F5A39D & 1) == 0)
        goto LABEL_38;
LABEL_39:
      else
      {
          goto LABEL_42;
      }
      Rand = sdfGetRand(&dds3Effect_Rand);
      ++v24;
      *(v31 + 16) = Rand / v23 * v23 - Rand;
      if (v14 == v24)
        return v15;
    }
    if ((byte_3F5A39D & 1) != 0)
      goto LABEL_39;
LABEL_38:
    goto LABEL_39;
  }
  return v15;
}

// 0x16ad8b0
void effMagaPoint4Delete(void **pData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effMagatuhi_tag_o **p_monitor;
  u64 v9[3];

  v3 = *pData;
  if (*pData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaPoint4_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaPoint4_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p_monitor = &v3[2].monitor;
  effMagatuhiDelete(p_monitor);
}

// 0x16ae650
void effMagaPoint4Draw(void **pData) {
  effMagaPoint4_tag_o *v5;
  effMagaPoint4_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct effMagaPoint4Param_t_o *param;
  s64 number;
  s32 loop;
  s32 life;
  s64 timing;
  effBezier4P_t_o *pBezier4P;
  u64 i;
  struct effMagaPoint4Part_tag_array *pPart;
  effMagaPoint4Part_tag_o *v19;
  s32 frame;
  f32 v25;
  struct effMagaPoint4Part_tag_array *v26;
  u32 Rand;
  f32 v29;
  u8 v30;
  s32 v31;
  struct System_UInt32_array *pRGBA;
  System_String_o *v34;
  dds3MagatuhiBill_tag_o *v35;
  s32 fade_out;
  s32 v37;
  dds3MagatuhiBill_tag_o *v38;
  s32 fade_in;
  UnityEngine_Vector4_o pOut;
  dds3MagatuhiBill_tag_o *hMagaBill;
  effBezier4P_t_o *pEffBezier4P;
  effMagaPoint4_tag_o *pMagaPoint4;
  u64 v44[3];

  pEffBezier4P = 0;
  pMagaPoint4 = 0;
  *&pOut.x = 0;
  *&pOut.z = 0;
  hMagaBill = 0;
  v5 = *pData;
  if (*pData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaPoint4_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaPoint4_tag, v44);
      if ((v44[0] & 1) != 0)
        v8 = v44[2];
      else
        v8 = v44 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  *&pOut.x = 0;
  *&pOut.z = 0;
  param = v5->param;
  number = param->MagaParam->number;
  loop = param->loop;
  life = param->life;
  timing = param->timing;
  fade_in = param->fade_in;
  fade_out = param->fade_out;
  pBezier4P = v5->pBezier4P;
  hMagaBill = v5->pMagatuhi->hMagaBill;
  v38 = hMagaBill;
  pEffBezier4P = pBezier4P;
  pMagaPoint4 = v5;
  if (number)
  {
    v37 = loop;
    for (i = 0; number != i; ++i)
    {
      while (1)
      {
        pPart = v5->pPart;
        v19 = pPart->m_Items[i];
        frame = v19->frame;
        if (frame)
          break;
        effMagaPoint4PartInit(&pMagaPoint4, i);
        v26 = v5->pPart;
        v19 = v26->m_Items[i];
LABEL_29:
        if (loop)
          goto LABEL_30;
LABEL_54:
        ++i;
        ++v19->frame;
        if (number == i)
          goto LABEL_58;
      }
      if (frame < 1 || life < frame)
        goto LABEL_29;
      dds3Bezier4PRun(&pEffBezier4P, i, &pOut);
      if (frame >= fade_in)
      {
        v25 = 1.0;
        if (life - frame <= fade_out)
          v25 = (life - frame) / fade_out;
      }
      else
      {
        v25 = frame / fade_in;
      }
      v29 = v25 * 127.0;
      if (v29 >= 0.0)
        v30 = v29;
      else
        v30 = v29;
      v31 = (v30 << 24) | 0x808080;
      pRGBA = v38->pRGBA;
      pRGBA->m_Items[i] = v31;
      dds3MagatuhiBillSetVertex(&hMagaBill, i, pOut);
      loop = v37;
      if (!v37)
        goto LABEL_54;
LABEL_30:
      if (life > frame)
        goto LABEL_54;
      if ((byte_3F5A39D & 1) == 0)
        goto LABEL_34;
LABEL_35:
      Rand = sdfGetRand(&dds3Effect_Rand);
      v19->frame = Rand / timing * timing - Rand;
    }
  }
LABEL_58:
  v34 = "effMagaPoint4Draw";
  v35 = v5->pMagatuhi->hMagaBill;
  dds3MagatuhiBillDraw(v35, v34);
}

// 0x16ad9d0
void effMagaPoint4PartInit(effMagaPoint4_tag **pMagaPoint4, u32 index) {
  f32 life;
  struct effBezier4PPart_t_array *pPart;
  effBezier4PPart_t_o *v11;
  struct UnityEngine_Vector4_array *point;
  struct UnityEngine_Vector4_array *v15;
  struct UnityEngine_Vector3_array *v17;
  f32 v18;
  struct UnityEngine_Vector3_array *v20;
  f32 v21;
  struct UnityEngine_Vector3_array *v23;
  f32 v24;
  struct UnityEngine_Vector4_array *v30;
  struct UnityEngine_Vector4_array *v32;
  struct UnityEngine_Vector3_array *v34;
  f32 v35;
  struct UnityEngine_Vector3_array *v37;
  f32 v38;
  struct UnityEngine_Vector3_array *v40;
  f32 v41;
  struct UnityEngine_Vector4_array *v47;
  struct UnityEngine_Vector4_array *v49;
  struct UnityEngine_Vector3_array *v51;
  f32 v52;
  struct UnityEngine_Vector3_array *v54;
  f32 v55;
  struct UnityEngine_Vector3_array *v57;
  f32 v58;
  struct UnityEngine_Vector4_array *v64;
  struct UnityEngine_Vector3_array *v66;
  f32 v67;
  struct UnityEngine_Vector3_array *v69;
  f32 v70;
  struct UnityEngine_Vector3_array *v72;
  f32 v73;
  struct effMagatuhi_tag_o *pMagatuhi;
  dds3MagatuhiBill_tag_o **p_hMagaBill;
  struct System_UInt32_array *pRGBA;
  UnityEngine_Vector4_o v81;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v83;
  UnityEngine_Vector4_o v84;

  *&v84.x = 0;
  *&v84.z = 0;
  *&v83.x = 0;
  *&v83.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v81.x = 0;
  *&v81.z = 0;
  SDF_VU0__LOADVECTOR(dds3CameraEyePos);
  SDF_VU0__LOADVECTOR_B(dds3CameraTargetPos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  life = (*pMagaPoint4)->param->life;
  pPart = (*pMagaPoint4)->pBezier4P->pPart;
  v11 = pPart->m_Items[index];
  v11->weight = 0.0;
  v11->step = 1.0 / life;
LABEL_16:
  sdfGetRandFloat(&dds3Effect_Rand);
  sub_854930(&v84, 0);
  sub_854710(&v84, 0);
  sub_854930(&v84, 1u);
  sub_854930(&v84, 2u);
  point = (*pMagaPoint4)->param->point;
  SDF_VU0__LOADVECTOR(point->m_Items[0]);
  v15 = (*pMagaPoint4)->param->point;
  SDF_VU0__LOADVECTOR_B(v15->m_Items[1]);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__SUBVECTOR();
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__LOADVECTOR_B(v84);
  SDF_VU0__MULVECTOR();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__STOREVECTOR(&v81);
  v17 = v11->point;
  sub_854710(&v81, 0);
  sub_8529B0(v17->m_Items, 0, v18);
  v20 = v11->point;
  sub_854710(&v81, 1u);
  sub_8529B0(v20->m_Items, 1, v21);
  v23 = v11->point;
  sub_854710(&v81, 2u);
  sub_8529B0(v23->m_Items, 2, v24);
  if ((byte_3F5A3A0 & 1) != 0)
  {
      goto LABEL_40;
  }
  else
  {
      goto LABEL_40;
  }
LABEL_40:
    goto LABEL_43;
LABEL_41:
LABEL_43:
  sdfGetRandFloat(&dds3Effect_Rand);
  sub_854930(&v84, 0);
  sub_854710(&v84, 0);
  sub_854930(&v84, 1u);
  sub_854930(&v84, 2u);
  v30 = (*pMagaPoint4)->param->point;
  SDF_VU0__LOADVECTOR(v30->m_Items[1]);
  v32 = (*pMagaPoint4)->param->point;
  SDF_VU0__LOADVECTOR_B(v32->m_Items[2]);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__SUBVECTOR();
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__LOADVECTOR_B(v84);
  SDF_VU0__MULVECTOR();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__STOREVECTOR(&v81);
  v34 = v11->point;
  sub_854710(&v81, 0);
  sub_8529B0(&v34->m_Items[1], 0, v35);
  v37 = v11->point;
  sub_854710(&v81, 1u);
  sub_8529B0(&v37->m_Items[1], 1, v38);
  v40 = v11->point;
  sub_854710(&v81, 2u);
  sub_8529B0(&v40->m_Items[1], 2, v41);
  if ((byte_3F5A3A0 & 1) != 0)
  {
      goto LABEL_61;
  }
  else
  {
      goto LABEL_61;
  }
LABEL_61:
    goto LABEL_64;
LABEL_62:
LABEL_64:
  sdfGetRandFloat(&dds3Effect_Rand);
  sub_854930(&v84, 0);
  sub_854710(&v84, 0);
  sub_854930(&v84, 1u);
  sub_854930(&v84, 2u);
  v47 = (*pMagaPoint4)->param->point;
  SDF_VU0__LOADVECTOR(v47->m_Items[2]);
  v49 = (*pMagaPoint4)->param->point;
  SDF_VU0__LOADVECTOR_B(v49->m_Items[3]);
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__SUBVECTOR();
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__OUTERPRODUCT();
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v83);
  SDF_VU0__LOADVECTOR_B(v84);
  SDF_VU0__MULVECTOR();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__STOREVECTOR(&v81);
  v51 = v11->point;
  sub_854710(&v81, 0);
  sub_8529B0(&v51->m_Items[2], 0, v52);
  v54 = v11->point;
  sub_854710(&v81, 1u);
  sub_8529B0(&v54->m_Items[2], 1, v55);
  v57 = v11->point;
  sub_854710(&v81, 2u);
  sub_8529B0(&v57->m_Items[2], 2, v58);
  if ((byte_3F5A3A0 & 1) != 0)
  {
      goto LABEL_82;
  }
  else
  {
      goto LABEL_82;
  }
LABEL_82:
    goto LABEL_85;
LABEL_83:
LABEL_85:
  sdfGetRandFloat(&dds3Effect_Rand);
  sub_854930(&v84, 0);
  sub_854710(&v84, 0);
  sub_854930(&v84, 1u);
  sub_854930(&v84, 2u);
  SDF_VU0__LOADVECTOR(v83);
  SDF_VU0__LOADVECTOR_B(v84);
  SDF_VU0__MULVECTOR();
  v64 = (*pMagaPoint4)->param->point;
  SDF_VU0__LOADVECTOR_B(v64->m_Items[3]);
  SDF_VU0__ADDVECTOR();
  SDF_VU0__STOREVECTOR(&v81);
  v66 = v11->point;
  sub_854710(&v81, 0);
  sub_8529B0(&v66->m_Items[3], 0, v67);
  v69 = v11->point;
  sub_854710(&v81, 1u);
  sub_8529B0(&v69->m_Items[3], 1, v70);
  v72 = v11->point;
  sub_854710(&v81, 2u);
  sub_8529B0(&v72->m_Items[3], 2, v73);
  pMagatuhi = (*pMagaPoint4)->pMagatuhi;
  p_hMagaBill = &pMagatuhi->hMagaBill;
LABEL_97:
  dds3MagatuhiBillPartsInit(p_hMagaBill, index);
  pRGBA = (*pMagaPoint4)->pMagatuhi->hMagaBill->pRGBA;
  pRGBA->m_Items[index] = 0;
}

// 0x16b3f60
void effMagaRandomize(effHandle_t **hEffect) {
  Il2CppObject *pwork;
  dds3MagatuhiPar_tag_c *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  if ((*hEffect)->major == 3)
  {
    pwork = (*hEffect)->pwork;
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v9);
      if ((v9[0] & 1) != 0)
        v7 = v9[2];
      else
        v7 = v9 + 1;
      v8 = sub_8C4940(v7);
    }
    switch (LODWORD(pwork[1].klass))
    {
      case 1:
        effMagaP4Randomize(hEffect, v4);
        break;
      case 2:
        effMagaCylinderRandomize(hEffect, v4);
        break;
      case 3:
        effMagaSpiralRandomize(hEffect, v4);
        break;
      case 4:
        effMagaSmokeRandomize(hEffect, v4);
        break;
      default:
        return;
    }
  }
}

// 0x16ad1c0
void effMagaSCSetArea(effHandle_t **hEffect, effMagaSCArea_t *pMagaSCArea) {
  Il2CppObject *pwork;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  u64 *monitor;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  s64 v15;
  s64 v16;
  char *v17;
  s64 *v18;
  char *v19;
  s64 *v20;
  u64 v21[2];
  char *v22;

  pwork = (*hEffect)->pwork;
  klass = pwork->klass;
  if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
  {
    sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v21);
    if ((v21[0] & 1) != 0)
      v17 = v22;
    else
      v17 = v21 + 1;
    v18 = sub_8C4940(v17);
  }
  monitor = pwork[1].monitor;
  v9 = *monitor;
  if (*(*monitor + 288LL) < v10 || *(*(v9 + 200) + 8 * v10 - 8) != effMagaSmokeConv_tag)
  {
    sub_8FC2C0(*(v9 + 64), effMagaSmokeConv_tag, v21);
    if ((v21[0] & 1) != 0)
      v19 = v22;
    else
      v19 = v21 + 1;
    v20 = sub_8C4940(v19);
  }
  v11 = monitor[2] + 16LL;
  sub_854710(&pMagaSCArea->fields, 0);
  sub_854930(v11, 0);
  v12 = monitor[2] + 16LL;
  sub_854710(&pMagaSCArea->fields, 1u);
  sub_854930(v12, 1u);
  v13 = monitor[2] + 16LL;
  sub_854710(&pMagaSCArea->fields, 2u);
  sub_854930(v13, 2u);
  *(monitor[2] + 68LL) = pMagaSCArea->s_radius;
  v14 = monitor[2] + 32LL;
  sub_854710(&pMagaSCArea->c_center, 0);
  sub_854930(v14, 0);
  v15 = monitor[2] + 32LL;
  sub_854710(&pMagaSCArea->c_center, 1u);
  sub_854930(v15, 1u);
  v16 = monitor[2] + 32LL;
  sub_854710(&pMagaSCArea->c_center, 2u);
  sub_854930(v16, 2u);
  *(monitor[2] + 96LL) = pMagaSCArea->c_radius;
}

// 0x16aad00
effMagaSmokeConv_tag *effMagaSmokeConvCreate(void *pData, s32 bPos, bool tbldata) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 name_low;
  u64 *v15;
  u64 *v16;
  u64 *v17;
  u64 *v18;
  u64 v20;
  effMagatuhiParams_t_o *v21;
  s64 v23;
  u64 v24;
  u32 *v25;
  u64 *v26;
  u64 v29;
  s64 v31;
  u32 Rand;
  s32 bPosa;
  u64 v37[2];
  char *v38;

  bPosa = bPos;
  if (tbldata)
  {
    if (pData)
    {
      klass = pData->klass;
      if (pData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSmokeConvParam_t)
      {
        sub_8FC2C0(klass->_1.element_class, effMagaSmokeConvParam_t, v37);
        if ((v37[0] & 1) != 0)
          v8 = v38;
        else
          v8 = v37 + 1;
        v9 = sub_8C4940(v8);
      }
    }
  }
  else
  {
    if (pData)
    {
      Interface = QueryInterface(pData, byte);
      if (!Interface)
      {
        sub_8FC2C0(pData->klass->_1.element_class, v10, v37);
        if ((v37[0] & 1) != 0)
          v12 = v38;
        else
          v12 = v37 + 1;
        v13 = sub_8C4940(v12);
      }
    }
    else
    {
      Interface = 0;
    }
    pData = Allocate(effMagaSmokeConvParam_t);
    effMagaSmokeConvParam_t___ctor(pData);
    effMagaSmokeConvParam_t__bCopy(pData, Interface, &bPosa);
  }
  name_low = LODWORD(pData[7].klass->_1.name);
  v15 = Allocate(effMagaSmokeConv_tag);
  _ctor(v15, 0);
  if (tbldata)
  {
    v16 = Allocate(effMagaSmokeConvParam_t);
    effMagaSmokeConvParam_t___ctor(v16);
    v15[2] = v16;
    v17 = v15 + 2;
    effMagaSmokeConvParam_t__pClone(pData, v15 + 2);
  }
  else
  {
    v15[2] = pData;
    v17 = v15 + 2;
  }
  v18 = NewSpecific(effMagaSmokeConvPart_tag, name_low);
  v20 = v15[2];
  v15[3] = v18;
  v15[7] = 0;
  if (*(v20 + 56) <= 0)
  {
    *(v20 + 56) = 1;
    v20 = *v17;
  }
  v21 = *(v20 + 112);
  v15[6] = effMagatuhiCreate(v21);
  v15[4] = dds3Bezier4PCreate(name_low);
  if (name_low)
  {
    v23 = *(*v17 + 56);
    v24 = 0;
    while (1)
    {
      v25 = v15[3];
      v26 = Allocate(effMagaSmokeConvPart_tag);
      _ctor(v26, 0);
      *&v25[2 * v24 + 8] = v26;
      v29 = v15[3];
      v31 = *(v29 + 8 * v24 + 32);
        break;
      if ((byte_3F5A39D & 1) == 0)
        goto LABEL_38;
LABEL_39:
      else
      {
          goto LABEL_42;
      }
      Rand = sdfGetRand(&dds3Effect_Rand);
      ++v24;
      *(v31 + 48) = Rand / v23 * v23 - Rand;
      if (name_low == v24)
        return v15;
    }
    if ((byte_3F5A39D & 1) != 0)
      goto LABEL_39;
LABEL_38:
    goto LABEL_39;
  }
  return v15;
}

// 0x16ab400
void effMagaSmokeConvDelete(void **pData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effMagatuhi_tag_o **v8;
  u64 v9[3];

  v3 = *pData;
  if (*pData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSmokeConv_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaSmokeConv_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[3];
  effMagatuhiDelete(v8);
}

// 0x16abd30
void effMagaSmokeConvDraw(void **pData) {
  __int128 v2;
  __int128 v3;
  effMagaSmokeConv_tag_o *v5;
  effMagaSmokeConv_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  struct effMagaSmokeConvParam_t_o *param;
  s32 loop;
  s32 life;
  s64 timing;
  s64 number;
  s32 fade_in;
  struct effMagaSmokeConvParam_t_o *v17;
  f32 c_radius;
  effMagaSmokeConv_tag_o *v22;
  u64 i;
  struct effMagaSmokeConvPart_tag_array *pPart;
  effMagaSmokeConvPart_tag_o *v26;
  struct effBezier4PPart_t_array *v27;
  s32 frame;
  effBezier4PPart_t_o *v31;
  f32 angle;
  f32 v34;
  struct UnityEngine_Vector3_array *point;
  f32 v38;
  struct UnityEngine_Vector3_array *v40;
  f32 v41;
  struct UnityEngine_Vector3_array *v43;
  f32 v44;
  __int128 v47;
  __int128 v48;
  f32 RandFloat;
  struct UnityEngine_Vector3_array *v50;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 v55;
  f32 v56;
  struct UnityEngine_Vector3_array *v58;
  f32 v59;
  f32 v60;
  f32 v61;
  f32 v62;
  f32 v63;
  struct UnityEngine_Vector3_array *v65;
  f32 v66;
  f32 v67;
  f32 v68;
  f32 v69;
  f32 v70;
  f32 v73;
  struct UnityEngine_Vector3_array *v74;
  f32 v75;
  f32 v76;
  f32 v77;
  f32 v78;
  f32 v79;
  f32 v80;
  struct UnityEngine_Vector3_array *v82;
  f32 v83;
  f32 v84;
  f32 v85;
  f32 v86;
  f32 v87;
  struct UnityEngine_Vector3_array *v89;
  f32 v90;
  f32 v91;
  f32 v92;
  f32 v93;
  f32 v94;
  struct UnityEngine_Vector3_array *v96;
  f32 v97;
  struct UnityEngine_Vector3_array *v99;
  f32 v100;
  struct UnityEngine_Vector3_array *v102;
  f32 v103;
  f32 v105;
  f32 v106;
  struct effMagaSmokeConvPart_tag_array *v107;
  u32 Rand;
  f32 v110;
  f32 v111;
  u8 v112;
  s32 v113;
  struct System_UInt32_array *pRGBA;
  System_String_o *v116;
  dds3MagatuhiBill_tag_o *v117;
  f32 c_step;
  f32 c_step_a;
  s32 v120;
  s32 fade_out;
  f32 c_ampli;
  f32 v123;
  f32 v124;
  effMagaSmokeConv_tag_o *v125;
  dds3MagatuhiBill_tag_o *v126;
  effBezier4P_t_o *pBezier4P;
  UnityEngine_Vector4_o v128;
  UnityEngine_Vector4_o v129;
  UnityEngine_Vector4_o v130;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v132;
  UnityEngine_Vector4_o v133;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o pOut;
  dds3MagatuhiBill_tag_o *hMagaBill;
  effBezier4P_t_o *pEffBezier4P;
  effMagaSmokeConv_tag_o *pMagaSmokeConv;
  u64 v139[4];

  pEffBezier4P = 0;
  pMagaSmokeConv = 0;
  *&v128.x = 0;
  *&pOut.z = 0;
  hMagaBill = 0;
  *&dst.z = 0;
  *&pOut.x = 0;
  *&v133.z = 0;
  *&dst.x = 0;
  *&v132.z = 0;
  *&v133.x = 0;
  *&p.z = 0;
  *&v132.x = 0;
  *&v130.z = 0;
  *&p.x = 0;
  *&v129.z = 0;
  *&v130.x = 0;
  *&v128.z = 0;
  *&v129.x = 0;
  v5 = *pData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSmokeConv_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaSmokeConv_tag, v139);
      if ((v139[0] & 1) != 0)
        v8 = v139[2];
      else
        v8 = v139 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  pMagaSmokeConv = v5;
  *&pOut.x = 0;
  *&pOut.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  *&v133.x = 0;
  *&v133.z = 0;
  *&v132.x = 0;
  *&v132.z = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&v130.x = 0;
  *&v130.z = 0;
  *&v129.x = 0;
  *&v129.z = 0;
  *&v128.x = 0;
  *&v128.z = 0;
  SDF_VU0__LOADVECTOR(dds3CameraEyePos);
  SDF_VU0__LOADVECTOR_B(dds3CameraTargetPos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  param = v5->param;
  loop = param->loop;
  life = param->life;
  timing = param->timing;
  number = param->MagaParam->number;
  fade_in = param->fade_in;
  fade_out = param->fade_out;
  *&v3 = param->s_angle_s;
  *&v2 = param->s_ampli_s;
  hMagaBill = v5->pMagatuhi->hMagaBill;
  v126 = hMagaBill;
  pBezier4P = v5->pBezier4P;
  pEffBezier4P = pBezier4P;
  SDF_VU0__COPYVECTOR(&dst, param->s_pos);
  v17 = v5->param;
  c_radius = v17->c_radius;
  c_ampli = v17->c_ampli;
  c_step = v17->c_step;
  c_step_a = v17->c_step_a;
  SDF_VU0__COPYVECTOR(&v132, v17->c_pos);
  v22 = pMagaSmokeConv;
  if (number)
  {
    v124 = c_radius * 0.4;
    v123 = c_radius * 0.65;
    v125 = pMagaSmokeConv;
    v120 = life;
    for (i = 0; number != i; ++i)
    {
      while (1)
      {
        pPart = v22->pPart;
        v26 = pPart->m_Items[i];
        v27 = pBezier4P->pPart;
        frame = v26->frame;
        if (frame)
          break;
        effMagaSmokeConvPartInit(&pMagaSmokeConv, i);
        v107 = v22->pPart;
        v26 = v107->m_Items[i];
LABEL_80:
        if (loop)
          goto LABEL_81;
LABEL_107:
        ++i;
        ++v26->frame;
        if (number == i)
          goto LABEL_113;
      }
      if (frame < 1 || life < frame)
        goto LABEL_80;
      v31 = v27->m_Items[i];
      if (v31->step == 0.0)
      {
        SDF_VU0__COPYVECTOR(&v133, v26->pos);
        angle = v26->angle;
        sdfSin(angle);
        sub_854710(&v26->dirUp, 1u);
        sub_854930(&v26->dirUp, 1u);
        sub_854710(&dst, 0);
        sub_854710(&v26->fields, 0);
        sub_854710(&v26->dirUp, 0);
        sub_854930(&pOut, 0);
        sub_854710(&dst, 1u);
        sub_854710(&v26->fields, 1u);
        sub_854710(&v26->dirUp, 1u);
        sub_854930(&pOut, 1u);
        sub_854710(&dst, 2u);
        sub_854710(&v26->fields, 2u);
        sub_854710(&v26->dirUp, 2u);
        sub_854930(&pOut, 2u);
        v34 = v26->angle;
        v26->amplitude = *&v2 + v26->amplitude;
        v26->angle = *&v3 + v34;
        SDF_VU0__LOADVECTOR(v132);
        SDF_VU0__LOADVECTOR_B(pOut);
        SDF_VU0__SUBVECTOR();
        life = v120;
        if (SDF_VU0__GETLENGTH() <= c_radius)
        {
          SDF_VU0__NORMALIZE();
          SDF_VU0__STOREVECTOR(&v129);
          SDF_VU0__LOADVECTOR_B(p);
          SDF_VU0__OUTERPRODUCT();
          SDF_VU0__NORMALIZE();
          SDF_VU0__STOREVECTOR(&v130);
          SDF_VU0__LOADVECTOR(pOut);
          SDF_VU0__LOADVECTOR_B(v133);
          SDF_VU0__SUBVECTOR();
          SDF_VU0__NORMALIZE();
          SDF_VU0__STOREVECTOR(&v128);
          point = v31->point;
          sub_854710(&pOut, 0);
          sub_8529B0(point->m_Items, 0, v38);
          v40 = v31->point;
          sub_854710(&pOut, 1u);
          sub_8529B0(v40->m_Items, 1, v41);
          v43 = v31->point;
          sub_854710(&pOut, 2u);
          sub_8529B0(v43->m_Items, 2, v44);
          else if ((byte_3F5A39E & 1) == 0)
          {
            goto LABEL_38;
          }
          v47 = v2;
          v48 = v3;
          RandFloat = sdfGetRandFloat(&dds3Effect_Rand);
          v50 = v31->point;
          v51 = c_ampli * ((RandFloat * 0.5) + 0.5);
          sub_854710(&pOut, 0);
          v53 = v52;
          sub_854710(&v129, 0);
          v55 = v54;
          sub_854710(&v128, 0);
          sub_8529B0(&v50->m_Items[1], 0, (v53 + (v124 * v55)) + (v51 * v56));
          v58 = v31->point;
          sub_854710(&pOut, 1u);
          v60 = v59;
          sub_854710(&v129, 1u);
          v62 = v61;
          sub_854710(&v128, 1u);
          sub_8529B0(&v58->m_Items[1], 1, (v60 + (v124 * v62)) + (v51 * v63));
          v65 = v31->point;
          sub_854710(&pOut, 2u);
          v67 = v66;
          sub_854710(&v129, 2u);
          v69 = v68;
          sub_854710(&v128, 2u);
          sub_8529B0(&v65->m_Items[1], 2, (v67 + (v124 * v69)) + (v51 * v70));
          v73 = sdfGetRandFloat(&dds3Effect_Rand);
          v74 = v31->point;
          v75 = c_ampli * ((v73 + -0.5) + (v73 + -0.5));
          sub_854710(&pOut, 0);
          v77 = v76;
          sub_854710(&v129, 0);
          v79 = v78;
          sub_854710(&v130, 0);
          sub_8529B0(&v74->m_Items[2], 0, (v77 + (v123 * v79)) + (v75 * v80));
          v82 = v31->point;
          sub_854710(&pOut, 1u);
          v84 = v83;
          sub_854710(&v129, 1u);
          v86 = v85;
          sub_854710(&v130, 1u);
          sub_8529B0(&v82->m_Items[2], 1, (v84 + (v123 * v86)) + (v75 * v87));
          v89 = v31->point;
          sub_854710(&pOut, 2u);
          v91 = v90;
          sub_854710(&v129, 2u);
          v93 = v92;
          sub_854710(&v130, 2u);
          sub_8529B0(&v89->m_Items[2], 2, (v91 + (v123 * v93)) + (v75 * v94));
          v96 = v31->point;
          sub_854710(&v132, 0);
          sub_8529B0(&v96->m_Items[3], 0, v97);
          v99 = v31->point;
          sub_854710(&v132, 1u);
          v3 = v48;
          sub_8529B0(&v99->m_Items[3], 1, v100);
          v102 = v31->point;
          sub_854710(&v132, 2u);
          v2 = v47;
          sub_8529B0(&v102->m_Items[3], 2, v103);
          v31->step = c_step;
        }
        if (frame < fade_in)
          goto LABEL_73;
        goto LABEL_95;
      }
      dds3Bezier4PRun(&pEffBezier4P, i, &pOut);
      v31->step = c_step_a * v31->step;
      if (frame < fade_in)
      {
LABEL_73:
        v105 = fade_in;
        v106 = frame;
        goto LABEL_97;
      }
LABEL_95:
      v110 = 1.0;
      if (life - frame > fade_out)
        goto LABEL_98;
      v106 = (life - frame);
      v105 = fade_out;
LABEL_97:
      v110 = v106 / v105;
LABEL_98:
      v111 = v110 * 127.0;
      if (v111 >= 0.0)
        v112 = v111;
      else
        v112 = v111;
      v113 = (v112 << 24) | 0x808080;
      pRGBA = v126->pRGBA;
      pRGBA->m_Items[i] = v113;
      dds3MagatuhiBillSetVertex(&hMagaBill, i, pOut);
      v22 = v125;
      if (!loop)
        goto LABEL_107;
LABEL_81:
      if (life > frame)
        goto LABEL_107;
      if ((byte_3F5A39D & 1) == 0)
        goto LABEL_85;
LABEL_86:
      Rand = sdfGetRand(&dds3Effect_Rand);
      v26->frame = Rand / timing * timing - Rand;
    }
  }
LABEL_113:
  v116 = "effMagaSmokeConvDraw";
  v117 = v22->pMagatuhi->hMagaBill;
  dds3MagatuhiBillDraw(v117, v116);
}

// 0x16ab530
void effMagaSmokeConvPartInit(effMagaSmokeConv_tag **pMagaSmokeConv, u32 index) {
  struct effMagaSmokeConvPart_tag_array *pPart;
  UnityEngine_Vector4_o *v7;
  struct effMagaSmokeConvParam_t_o *param;
  f32 s_ampli;
  f32 s_ampli_r;
  struct effMagaSmokeConvParam_t_o *v24;
  f32 s_up_s;
  f32 s_up_s_r;
  struct effBezier4PPart_t_array *v30;
  struct effMagatuhi_tag_o *pMagatuhi;
  dds3MagatuhiBill_tag_o **p_hMagaBill;
  struct System_UInt32_array *pRGBA;
  UnityEngine_Vector4_o v36;

  *&v36.x = 0;
  *&v36.z = 0;
  pPart = (*pMagaSmokeConv)->pPart;
  v7 = pPart->m_Items[index];
LABEL_9:
  sdfGetRandFloat(&dds3Effect_Rand);
  else
  {
      goto LABEL_25;
  }
LABEL_25:
  sdfGetRandFloat(&dds3Effect_Rand);
  sub_854930(&v36, 0);
  sub_854930(&v36, 1u);
  else
  {
      goto LABEL_33;
  }
LABEL_33:
  sdfGetRandFloat(&dds3Effect_Rand);
  sub_854930(&v36, 2u);
  SDF_VU0__LOADVECTOR(v36);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v36);
  sub_854710(&v36, 0);
  sub_854930(&v7[1], 0);
  sub_854930(&v7[1], 1u);
  sub_854710(&v36, 2u);
  sub_854930(&v7[1], 2u);
  else
  {
      goto LABEL_41;
  }
LABEL_41:
  sdfGetRandFloat(&dds3Effect_Rand);
  sub_854930(&v7[2], 0);
  sub_854930(&v7[2], 1u);
  else
  {
      goto LABEL_49;
  }
LABEL_49:
  sdfGetRandFloat(&dds3Effect_Rand);
  sub_854930(&v7[2], 2u);
  SDF_VU0__LOADVECTOR(v7[2]);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(v7 + 2);
  param = (*pMagaSmokeConv)->param;
  s_ampli = param->s_ampli;
  s_ampli_r = param->s_ampli_r;
  else
  {
      goto LABEL_57;
  }
LABEL_57:
  v7[3].y = s_ampli
                 * ((1.0 - s_ampli_r)
                  + (s_ampli_r * sdfGetRandFloat(&dds3Effect_Rand)));
  else
  {
      goto LABEL_65;
  }
LABEL_65:
  v7[3].z = sdfGetRandFloat(&dds3Effect_Rand) * 6.2832;
  v24 = (*pMagaSmokeConv)->param;
  s_up_s = v24->s_up_s;
  s_up_s_r = v24->s_up_s_r;
  else
  {
      goto LABEL_73;
  }
LABEL_73:
  v7[3].w = s_up_s
                 * ((1.0 - s_up_s_r)
                  + (s_up_s_r * sdfGetRandFloat(&dds3Effect_Rand)));
  v30 = (*pMagaSmokeConv)->pBezier4P->pPart;
  *&v30->m_Items[index]->weight = 0;
  pMagatuhi = (*pMagaSmokeConv)->pMagatuhi;
  p_hMagaBill = &pMagatuhi->hMagaBill;
LABEL_79:
  dds3MagatuhiBillPartsInit(p_hMagaBill, index);
  pRGBA = (*pMagaSmokeConv)->pMagatuhi->hMagaBill->pRGBA;
  pRGBA->m_Items[index] = 0;
}

// 0x16b2380
effMagaSmoke_tag *effMagaSmokeCreate(void *pData, s32 bPos, bool tbldata) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 name_low;
  u64 *v15;
  u64 *v16;
  u64 *v17;
  u64 v19;
  effMagatuhiParams_t_o *v20;
  s64 v21;
  u64 v22;
  u32 *v23;
  u64 *v24;
  u64 v27;
  s64 v29;
  u32 Rand;
  s32 bPosa;
  u64 v35[2];
  char *v36;

  bPosa = bPos;
  if (tbldata)
  {
    if (pData)
    {
      klass = pData->klass;
      if (pData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSmokeParam_t)
      {
        sub_8FC2C0(klass->_1.element_class, effMagaSmokeParam_t, v35);
        if ((v35[0] & 1) != 0)
          v8 = v36;
        else
          v8 = v35 + 1;
        v9 = sub_8C4940(v8);
      }
    }
  }
  else
  {
    if (pData)
    {
      Interface = QueryInterface(pData, byte);
      if (!Interface)
      {
        sub_8FC2C0(pData->klass->_1.element_class, v10, v35);
        if ((v35[0] & 1) != 0)
          v12 = v36;
        else
          v12 = v35 + 1;
        v13 = sub_8C4940(v12);
      }
    }
    else
    {
      Interface = 0;
    }
    pData = Allocate(effMagaSmokeParam_t);
    effMagaSmokeParam_t___ctor(pData);
    effMagaSmokeParam_t__bCopy(pData, Interface, &bPosa);
  }
  name_low = LODWORD(pData[5].klass->_1.name);
  v15 = Allocate(effMagaSmoke_tag);
  _ctor(v15, 0);
  if (tbldata)
  {
    v16 = Allocate(effMagaSmokeParam_t);
    effMagaSmokeParam_t___ctor(v16);
    v15[10] = v16;
    v17 = v15 + 10;
    effMagaSmokeParam_t__pClone(pData, v15 + 10);
  }
  else
  {
    v15[10] = pData;
    v17 = v15 + 10;
  }
  *(v15 + 24) = -2139062144;
  v15[11] = NewSpecific(effMagaSmokePart_tag, name_low);
  v15[14] = 0;
  SDF_VU0__STOREIDENTITY((v15 + 2), 0);
  v19 = v15[10];
  if (*(v19 + 40) <= 0)
  {
    *(v19 + 40) = 1;
    v19 = *v17;
  }
  v20 = *(v19 + 80);
  v15[13] = effMagatuhiCreate(v20);
  if (name_low)
  {
    v21 = *(*v17 + 40);
    v22 = 0;
    while (1)
    {
      v23 = v15[11];
      v24 = Allocate(effMagaSmokePart_tag);
      _ctor(v24, 0);
      *&v23[2 * v22 + 8] = v24;
      v27 = v15[11];
      v29 = *(v27 + 8 * v22 + 32);
        break;
      if ((byte_3F5A39D & 1) == 0)
        goto LABEL_38;
LABEL_39:
      else
      {
          goto LABEL_42;
      }
      Rand = sdfGetRand(&dds3Effect_Rand);
      ++v22;
      *(v29 + 48) = Rand / v21 * v21 - Rand;
      if (name_low == v22)
        return v15;
    }
    if ((byte_3F5A39D & 1) != 0)
      goto LABEL_39;
LABEL_38:
    goto LABEL_39;
  }
  return v15;
}

// 0x16b27b0
void effMagaSmokeDelete(void **pData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effMagatuhi_tag_o **p_monitor;
  u64 v9[3];

  v3 = *pData;
  if (*pData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSmoke_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaSmoke_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  p_monitor = &v3[6].monitor;
  effMagatuhiDelete(p_monitor);
}

// 0x16b2fb0
void effMagaSmokeDraw(void **pData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  s64 name_low;
  u32 v10;
  s32 data_high;
  s32 data_low;
  f32 v13;
  f32 v14;
  u64 v17;
  u64 *monitor;
  s64 v20;
  s32 v21;
  f32 v23;
  f32 v26;
  f32 v27;
  u64 *v28;
  u32 Rand;
  f32 v31;
  s32 v32;
  u32 v33;
  s32 v34;
  struct System_UInt32_array *pRGBA;
  System_String_o *v37;
  dds3MagatuhiBill_tag_o *v38;
  s32 data;
  s64 v40;
  s32 v41;
  s32 v42;
  dds3MagatuhiBill_tag_o *v43;
  s32 v44;
  s64 bits;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  dds3MagatuhiBill_tag_o *hMagaBill;
  effMagaSmoke_tag_o *pMagaSmoke;
  u64 v51[4];

  hMagaBill = 0;
  pMagaSmoke = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  v3 = *pData;
  if (*pData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSmoke_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaSmoke_tag, v51);
      if ((v51[0] & 1) != 0)
        v6 = v51[2];
      else
        v6 = v51 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  pMagaSmoke = *pData;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  v8 = v3[5].klass;
  name_low = LODWORD(v8->_1.declaringType->_1.name);
  v10 = v3[6].klass;
  data_high = HIDWORD(v8->_1.byval_arg.data);
  bits = v8->_1.byval_arg.bits;
  v44 = *(&v8->_1.byval_arg.bits + 1);
  data = v8->_1.this_arg.data;
  data_low = LOBYTE(v8->_1.byval_arg.data);
  v13 = *&v8->_1.element_class;
  v14 = *&v8->_1.castClass;
  v43 = *(v3[6].monitor + 3);
  hMagaBill = v43;
  SDF_VU0__COPYVECTOR(&dst, *&v8->_1.name);
  memmove(&dest, &v3[1], 0x40u);
  SDF_VU0__LOADMATRIX(&dest);
  if (name_low)
  {
    v42 = (v10 >> 23) & 0x1FE;
    v41 = v10 & 0xFFFFFF;
    v17 = 0;
    v40 = name_low;
    do
    {
      while (1)
      {
        monitor = v3[5].monitor;
        v20 = monitor[v17 + 4];
        v21 = *(v20 + 48);
        if (v21)
          break;
        effMagaSmokePartInit(&pMagaSmoke, v17);
        v28 = v3[5].monitor;
        v20 = v28[v17 + 4];
LABEL_30:
        if (data_low)
          goto LABEL_31;
LABEL_54:
        ++v17;
        ++*(v20 + 48);
        if (name_low == v17)
          goto LABEL_58;
      }
      if (v21 < 1 || data_high < v21)
        goto LABEL_30;
      v23 = *(v20 + 56);
      sdfSin(v23);
      sub_854710(v20 + 32, 1u);
      sub_854930(v20 + 32, 1u);
      sub_854710(v20 + 16, 0);
      sub_854710(v20 + 32, 0);
      sub_854930(&p, 0);
      sub_854710(v20 + 16, 1u);
      sub_854710(v20 + 32, 1u);
      sub_854930(&p, 1u);
      sub_854710(v20 + 16, 2u);
      sub_854710(v20 + 32, 2u);
      sub_854930(&p, 2u);
      SDF_VU0__LOADVECTOR_B(dst);
      SDF_VU0__LOADVECTOR(p);
      SDF_VU0__APPLYMATRIX();
      SDF_VU0__ADDVECTOR();
      SDF_VU0__STOREVECTOR(&p);
      v26 = *(v20 + 56);
      *(v20 + 52) = v14 + *(v20 + 52);
      *(v20 + 56) = v13 + v26;
      if (v21 >= v44)
      {
        v27 = 1.0;
        if (data_high - v21 <= data)
          v27 = (data_high - v21) / data;
      }
      else
      {
        v27 = v21 / v44;
      }
      v31 = v27 * 127.0;
      v32 = v31;
      if (v31 >= 0.0)
        LOBYTE(v32) = v31;
      v33 = (v42 * (v32 << 16)) & 0xFF000000;
      v34 = v41 | v33;
      pRGBA = v43->pRGBA;
      pRGBA->m_Items[v17] = v34;
      dds3MagatuhiBillSetVertex(&hMagaBill, v17, p);
      name_low = v40;
      if (!data_low)
        goto LABEL_54;
LABEL_31:
      if (data_high > v21)
        goto LABEL_54;
      if ((byte_3F5A39D & 1) == 0)
        goto LABEL_35;
LABEL_36:
      Rand = sdfGetRand(&dds3Effect_Rand);
      ++v17;
      *(v20 + 48) = Rand / bits * bits - Rand;
    }
    while (name_low != v17);
  }
LABEL_58:
  v37 = "effMagaSmokeDraw";
  v38 = *(v3[6].monitor + 3);
  dds3MagatuhiBillDraw(v38, v37);
}

// 0x16b28d0
void effMagaSmokePartInit(effMagaSmoke_tag **pMagaSmoke, u32 index) {
  struct effMagaSmokePart_tag_array *pPart;
  UnityEngine_Vector4_o *v7;
  struct effMagaSmokeParam_t_o *param;
  f32 ampli;
  f32 ampli_r;
  struct effMagaSmokeParam_t_o *v24;
  f32 up_s;
  f32 up_s_r;
  struct effMagatuhi_tag_o *pMagatuhi;
  dds3MagatuhiBill_tag_o **p_hMagaBill;
  struct System_UInt32_array *pRGBA;
  UnityEngine_Vector4_o v34;

  *&v34.x = 0;
  *&v34.z = 0;
  pPart = (*pMagaSmoke)->pPart;
  v7 = pPart->m_Items[index];
LABEL_9:
  sdfGetRandFloat(&dds3Effect_Rand);
  else
  {
      goto LABEL_25;
  }
LABEL_25:
  sdfGetRandFloat(&dds3Effect_Rand);
  sub_854930(&v34, 0);
  sub_854930(&v34, 1u);
  else
  {
      goto LABEL_33;
  }
LABEL_33:
  sdfGetRandFloat(&dds3Effect_Rand);
  sub_854930(&v34, 2u);
  SDF_VU0__LOADVECTOR(v34);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v34);
  sub_854710(&v34, 0);
  sub_854930(&v7[1], 0);
  sub_854930(&v7[1], 1u);
  sub_854710(&v34, 2u);
  sub_854930(&v7[1], 2u);
  else
  {
      goto LABEL_41;
  }
LABEL_41:
  sdfGetRandFloat(&dds3Effect_Rand);
  sub_854930(&v7[2], 0);
  sub_854930(&v7[2], 1u);
  else
  {
      goto LABEL_49;
  }
LABEL_49:
  sdfGetRandFloat(&dds3Effect_Rand);
  sub_854930(&v7[2], 2u);
  SDF_VU0__LOADVECTOR(v7[2]);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(v7 + 2);
  param = (*pMagaSmoke)->param;
  ampli = param->ampli;
  ampli_r = param->ampli_r;
  else
  {
      goto LABEL_57;
  }
LABEL_57:
  v7[3].y = ampli
                 * ((1.0 - ampli_r)
                  + (ampli_r * sdfGetRandFloat(&dds3Effect_Rand)));
  else
  {
      goto LABEL_65;
  }
LABEL_65:
  v7[3].z = sdfGetRandFloat(&dds3Effect_Rand) * 6.2832;
  v24 = (*pMagaSmoke)->param;
  up_s = v24->up_s;
  up_s_r = v24->up_s_r;
  else
  {
      goto LABEL_73;
  }
LABEL_73:
  v7[3].w = up_s
                 * ((1.0 - up_s_r)
                  + (up_s_r * sdfGetRandFloat(&dds3Effect_Rand)));
  pMagatuhi = (*pMagaSmoke)->pMagatuhi;
  p_hMagaBill = &pMagatuhi->hMagaBill;
LABEL_77:
  dds3MagatuhiBillPartsInit(p_hMagaBill, index);
  pRGBA = (*pMagaSmoke)->pMagatuhi->hMagaBill->pRGBA;
  pRGBA->m_Items[index] = 0;
}

// 0x16b3910
void effMagaSmokeRandomize(effHandle_t **hEffect) {
  Il2CppObject *pwork;
  dds3MagatuhiPar_tag_c *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppObject *v7;
  Il2CppClass *v8;
  effMagaSmoke_tag_o *monitor;
  effMagaSmoke_tag_c *v10;
  s64 v11;
  char *v12;
  s64 *v13;
  s64 v14;
  s64 v15;
  u64 v16;
  dds3MagatuhiBill_tag_o *v17;
  effManager_c **v20;
  u64 v21;
  s64 v24;
  u64 v26;
  s64 v27;
  u64 v28;
  effManager_c **v29;
  signed s32 Rand;
  f32 v31;
  f32 v32;
  f32 v33;
  s32 v34;
  s64 v35;
  s32 v36;
  f32 v37;
  f32 v38;
  f32 v39;
  f32 v40;
  f32 v41;
  f32 v42;
  s64 i;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  char *v51;
  s64 *v52;
  char *v53;
  s64 *v54;
  s64 v55;
  s32 v56;
  u64 v57;
  f32 v58;
  f32 v59;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  effMagaSmoke_tag_o *pMagaSmoke;
  dds3MagatuhiBill_tag_o *hMagaBill;
  u64 v65[2];
  char *v66;
  UnityEngine_Vector4_o v67;

  pMagaSmoke = 0;
  hMagaBill = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  if ((*hEffect)->major == 3)
  {
    pwork = (*hEffect)->pwork;
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v65);
      if ((v65[0] & 1) != 0)
        v51 = v66;
      else
        v51 = v65 + 1;
      v52 = sub_8C4940(v51);
    }
    if (LODWORD(pwork[1].klass) == 4)
    {
      v7 = (*hEffect)->pwork;
      v8 = v7->klass;
      if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth || v8->_2.typeHierarchy[typeHierarchyDepth - 1] != v4)
      {
        sub_8FC2C0(v8->_1.element_class, v4, v65);
        if ((v65[0] & 1) != 0)
          v53 = v66;
        else
          v53 = v65 + 1;
        v54 = sub_8C4940(v53);
      }
      monitor = v7[1].monitor;
      if (monitor)
      {
        v10 = monitor->klass;
        if (monitor->klass->_2.typeHierarchyDepth < v11 || v10->_2.typeHierarchy[v11 - 1] != effMagaSmoke_tag)
        {
          sub_8FC2C0(v10->_1.element_class, effMagaSmoke_tag, v65);
          if ((v65[0] & 1) != 0)
            v12 = v66;
          else
            v12 = v65 + 1;
          v13 = sub_8C4940(v12);
        }
      }
      v14 = *(&loc_50 + monitor);
      v15 = *(v14 + 80);
      v16 = *(v15 + 16);
      v55 = *(v15 + 20);
      v56 = *(v14 + 36);
      v17 = *(*(&loc_68 + monitor) + 24LL);
      pMagaSmoke = monitor;
      hMagaBill = v17;
      SDF_VU0__COPYVECTOR(&dst, *(v14 + 16), 0);
      memmove(&dest, &monitor->fields, 0x40u);
      SDF_VU0__LOADMATRIX(&dest);
      v57 = v16;
      if (v16)
      {
        v20 = &effManager;
        v21 = 0;
        while (1)
        {
          effMagaSmokePartInit(&pMagaSmoke, v21);
          v24 = *(&loc_58 + monitor);
          v26 = *v20;
          v27 = *(v24 + 8 * v21 + 32);
          if (((*v20)->_2.bitflags2 & 2) == 0 || *(v26 + 216))
            break;
          if ((byte_3F5A39D & 1) == 0)
            goto LABEL_36;
LABEL_37:
          v28 = *v20;
          if (((*v20)->_2.bitflags2 & 2) != 0 && !*(v28 + 216))
          v29 = v20;
          Rand = sdfGetRand(&(*v20)->static_fields->dds3Effect_Rand, 0);
          v31 = *(v27 + 56);
          v32 = *(v27 + 60);
          v33 = *(v27 + 52);
          v34 = Rand % v56;
          *(v27 + 48) = Rand % v56;
          v35 = *(&loc_50 + monitor);
          if (Rand % v56 > v55)
            v34 = 0;
          v36 = v55 - v34;
          v58 = *(v35 + 72);
          v59 = *(v35 + 64);
          if (Rand % v56 <= v55)
            v37 = 0.0;
          else
            v37 = (Rand % v56 - v55);
          v38 = (*(v35 + 64) * v37) + v31;
          v39 = (v37 * *(v35 + 72)) + v33;
          sub_854710(v27 + 32, 1u);
          v41 = (v37 * v32) + v40;
          v42 = v32;
          sub_854930(&p, 3u);
          if (v36 >= 1)
          {
            for (i = 0; i < v36; ++i)
            {
              sdfSin(v38);
              v41 = v42 + v41;
              sub_854710(v27 + 16, 0);
              sub_854710(v27 + 32, 0);
              sub_854930(&p, 0);
              sub_854710(v27 + 16, 1u);
              sub_854930(&p, 1u);
              sub_854710(v27 + 16, 2u);
              sub_854710(v27 + 32, 2u);
              sub_854930(&p, 2u);
              SDF_VU0__LOADVECTOR_B(dst);
              SDF_VU0__LOADVECTOR(p);
              SDF_VU0__APPLYMATRIX();
              SDF_VU0__ADDVECTOR();
              SDF_VU0__STOREVECTOR(&p);
              x = p.x;
              y = p.y;
              z = p.z;
              w = p.w;
              v67.x = x;
              v67.y = y;
              v67.z = z;
              v67.w = w;
              dds3MagatuhiBillSetVertex(&hMagaBill, v21, v67);
              v39 = v58 + v39;
              v38 = v59 + v38;
            }
          }
          *(v27 + 52) = v39;
          *(v27 + 56) = v38;
          sub_854930(v27 + 32, 1u);
          v21 += 3LL;
          v20 = v29;
          if (v21 >= v57)
            return;
        }
        if ((byte_3F5A39D & 1) != 0)
          goto LABEL_37;
LABEL_36:
        goto LABEL_37;
      }
    }
  }
}

// 0x16b35d0
void effMagaSmokeSetPosition(void **pData, sdfVector4_t pPos) {
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
  klass = (*pData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSmoke_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effMagaSmoke_tag, v12);
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
  SDF_VU0__COPYVECTOR(&(*pData)[5].klass->_1.name, v13, 0);
}

// 0x16b36f0
void effMagaSmokeSetRGBA(void **pData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*pData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSmoke_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effMagaSmoke_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*pData)[6].klass) = abgr;
}

// 0x16b37e0
void effMagaSmokeSetRotateMatrix(void **pData, sdfMatrix4_t *pMatrix) {
  s64 v5;
  s64 v6;
  Il2CppObject *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  UnityEngine_Matrix4x4_o v16;
  u64 v17[3];

  v5 = *&pMatrix->m00;
  v6 = *&pMatrix->m20;
  v7 = *pData;
  v8 = *&pMatrix->m21;
  *&v16.m01 = *&pMatrix->m01;
  *&v16.m21 = v8;
  *&v16.m00 = v5;
  *&v16.m20 = v6;
  v9 = *&pMatrix->m02;
  v10 = *&pMatrix->m22;
  v11 = *&pMatrix->m23;
  *&v16.m03 = *&pMatrix->m03;
  *&v16.m23 = v11;
  *&v16.m02 = v9;
  *&v16.m22 = v10;
  SDF_VU0__LOADMATRIX(&v16);
  if (v7)
  {
    klass = v7->klass;
    if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSmoke_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaSmoke_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[1]);
}

// 0x16b0b40
effMagaSpiral_tag *effMagaSpiralCreate(void *pData, s32 bPos, bool tbldata) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  Il2CppClass *v10;
  s64 *Interface;
  char *v12;
  s64 *v13;
  u64 v14;
  u64 *v15;
  u64 *v16;
  u64 *v17;
  u64 v19;
  effMagatuhiParams_t_o *v20;
  s64 v21;
  u64 v22;
  u32 *v23;
  u64 *v24;
  u64 v27;
  s64 v29;
  u32 Rand;
  s32 bPosa;
  u64 v35[2];
  char *v36;

  bPosa = bPos;
  if (tbldata)
  {
    if (pData)
    {
      klass = pData->klass;
      if (pData->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSpiralParam_t)
      {
        sub_8FC2C0(klass->_1.element_class, effMagaSpiralParam_t, v35);
        if ((v35[0] & 1) != 0)
          v8 = v36;
        else
          v8 = v35 + 1;
        v9 = sub_8C4940(v8);
      }
    }
  }
  else
  {
    if (pData)
    {
      Interface = QueryInterface(pData, byte);
      if (!Interface)
      {
        sub_8FC2C0(pData->klass->_1.element_class, v10, v35);
        if ((v35[0] & 1) != 0)
          v12 = v36;
        else
          v12 = v35 + 1;
        v13 = sub_8C4940(v12);
      }
    }
    else
    {
      Interface = 0;
    }
    pData = Allocate(effMagaSpiralParam_t);
    effMagaSpiralParam_t___ctor(pData);
    effMagaSpiralParam_t__bCopy(pData, Interface, &bPosa);
  }
  v14 = *(pData[5].monitor + 4);
  v15 = Allocate(effMagaSpiral_tag);
  _ctor(v15, 0);
  if (tbldata)
  {
    v16 = Allocate(effMagaSpiralParam_t);
    effMagaSpiralParam_t___ctor(v16);
    v15[10] = v16;
    v17 = v15 + 10;
    effMagaSpiralParam_t__pClone(pData, v15 + 10);
  }
  else
  {
    v15[10] = pData;
    v17 = v15 + 10;
  }
  v15[11] = NewSpecific(effMagaSpiralPart_tag, v14);
  *(v15 + 26) = -2139062144;
  v15[14] = 0;
  SDF_VU0__STOREIDENTITY((v15 + 2), 0);
  v19 = v15[10];
  if (*(v19 + 40) <= 0)
  {
    *(v19 + 40) = 1;
    v19 = *v17;
  }
  v20 = *(v19 + 88);
  v15[12] = effMagatuhiCreate(v20);
  if (v14)
  {
    v21 = *(*v17 + 40);
    v22 = 0;
    while (1)
    {
      v23 = v15[11];
      v24 = Allocate(effMagaSpiralPart_tag);
      _ctor(v24, 0);
      *&v23[2 * v22 + 8] = v24;
      v27 = v15[11];
      v29 = *(v27 + 8 * v22 + 32);
        break;
      if ((byte_3F5A39D & 1) == 0)
        goto LABEL_38;
LABEL_39:
      else
      {
          goto LABEL_42;
      }
      Rand = sdfGetRand(&dds3Effect_Rand);
      ++v22;
      *(v29 + 16) = Rand / v21 * v21 - Rand;
      if (v14 == v22)
        return v15;
    }
    if ((byte_3F5A39D & 1) != 0)
      goto LABEL_39;
LABEL_38:
    goto LABEL_39;
  }
  return v15;
}

// 0x16b0f70
void effMagaSpiralDelete(void **pData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  effMagatuhi_tag_o **v8;
  u64 v9[3];

  v3 = *pData;
  if (*pData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSpiral_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaSpiral_tag, v9);
      if ((v9[0] & 1) != 0)
        v6 = v9[2];
      else
        v6 = v9 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  v8 = &v3[6];
  effMagatuhiDelete(v8);
}

// 0x16b1510
void effMagaSpiralDraw(void **pData) {
  effMagaSpiral_tag_o *v3;
  effMagaSpiral_tag_c *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  struct effMagaSpiralParam_t_o *param;
  s64 number;
  s32 life;
  s32 timing;
  s32 loop;
  u32 abgr;
  u64 v16;
  struct effMagaSpiralPart_tag_array *pPart;
  effMagaSpiralPart_tag_o *v19;
  s32 frame;
  f32 rotate;
  f32 v25;
  f32 radius;
  f32 radius_s;
  f32 v28;
  struct effMagaSpiralPart_tag_array *v29;
  f32 v31;
  s32 v32;
  u32 v33;
  s32 v34;
  struct System_UInt32_array *pRGBA;
  u32 Rand;
  System_String_o *v38;
  dds3MagatuhiBill_tag_o *v39;
  s32 fade_out;
  s32 v41;
  s32 v42;
  dds3MagatuhiBill_tag_o *v43;
  s32 fade_in;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  dds3MagatuhiBill_tag_o *hMagaBill;
  effMagaSpiral_tag_o *pMagaSpiral;
  u64 v50[4];

  hMagaBill = 0;
  pMagaSpiral = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  v3 = *pData;
  if (*pData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSpiral_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaSpiral_tag, v50);
      if ((v50[0] & 1) != 0)
        v6 = v50[2];
      else
        v6 = v50 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  param = v3->param;
  number = param->MagaParam->number;
  life = param->life;
  timing = param->timing;
  fade_in = param->fade_in;
  fade_out = param->fade_out;
  loop = param->loop;
  abgr = v3->abgr;
  v43 = v3->pMagatuhi->hMagaBill;
  hMagaBill = v43;
  pMagaSpiral = v3;
  SDF_VU0__COPYVECTOR(&dst, param->pos);
  memmove(&dest, &v3->fields, 0x40u);
  SDF_VU0__LOADMATRIX(&dest);
  if (number)
  {
    v42 = (abgr >> 23) & 0x1FE;
    v41 = abgr & 0xFFFFFF;
    v16 = 0;
    while (1)
    {
      while (1)
      {
        pPart = v3->pPart;
        v19 = pPart->m_Items[v16];
        frame = v19->frame;
        if (frame)
        {
          if (frame >= 1 && life >= frame)
          {
            rotate = v19->rotate;
            sdfCos(rotate);
            sub_854930(&p, 0);
            sub_854930(&p, 1u);
            sdfSin(rotate);
            sub_854930(&p, 2u);
            SDF_VU0__LOADVECTOR_B(dst);
            SDF_VU0__LOADVECTOR(p);
            SDF_VU0__APPLYMATRIX();
            SDF_VU0__ADDVECTOR();
            SDF_VU0__STOREVECTOR(&p);
            v25 = v19->rotate + v19->rotate_s;
            radius = v19->radius;
            radius_s = v19->radius_s;
            v19->up = v19->up + v19->up_s;
            v19->rotate = v25;
            v19->radius = radius + radius_s;
            if (frame >= fade_in)
            {
              v28 = 1.0;
              if (life - frame <= fade_out)
                v28 = (life - frame) / fade_out;
            }
            else
            {
              v28 = frame / fade_in;
            }
            v31 = v28 * 127.0;
            v32 = v31;
            if (v31 >= 0.0)
              LOBYTE(v32) = v31;
            v33 = (v42 * (v32 << 16)) & 0xFF000000;
            v34 = v41 | v33;
            pRGBA = v43->pRGBA;
            pRGBA->m_Items[v16] = v34;
            dds3MagatuhiBillSetVertex(&hMagaBill, v16, p);
          }
        }
        else
        {
          effMagaSpiralPartInit(&pMagaSpiral, v16);
          v29 = v3->pPart;
          v19 = v29->m_Items[v16];
        }
        if (loop && life <= frame)
          break;
        ++v16;
        ++v19->frame;
        if (number == v16)
          goto LABEL_58;
      }
        break;
      if ((byte_3F5A39D & 1) == 0)
        goto LABEL_45;
LABEL_46:
      Rand = sdfGetRand(&dds3Effect_Rand);
      ++v16;
      v19->frame = Rand / timing * timing - Rand;
      if (number == v16)
        goto LABEL_58;
    }
    if ((byte_3F5A39D & 1) != 0)
      goto LABEL_46;
LABEL_45:
    goto LABEL_46;
  }
LABEL_58:
  v38 = "effMagaSpiralDraw";
  v39 = v3->pMagatuhi->hMagaBill;
  dds3MagatuhiBillDraw(v39, v38);
}

// 0x16b1090
void effMagaSpiralPartInit(effMagaSpiral_tag **pMagaSpiral, u32 index) {
  struct effMagaSpiralPart_tag_array *pPart;
  effMagaSpiralPart_tag_o *v7;
  struct effMagaSpiralParam_t_o *param;
  f32 up_s;
  f32 up_r;
  struct effMagaSpiralParam_t_o *v14;
  f32 rotate_s;
  f32 rotate_r;
  struct effMagaSpiralParam_t_o *v19;
  f32 radius_s_r;
  f32 radius_s;
  struct effMagaSpiralParam_t_o *v24;
  f32 radius_e_r;
  f32 radius_e;
  struct effMagatuhi_tag_o *pMagatuhi;
  dds3MagatuhiBill_tag_o **p_hMagaBill;
  struct System_UInt32_array *pRGBA;

  pPart = (*pMagaSpiral)->pPart;
  v7 = pPart->m_Items[index];
  *&v7->frame = 0;
  param = (*pMagaSpiral)->param;
  up_s = param->up_s;
  up_r = param->up_r;
LABEL_9:
  v7->up_s = up_s
                  * ((1.0 - up_r)
                   + (up_r * sdfGetRandFloat(&dds3Effect_Rand)));
  else
  {
      goto LABEL_25;
  }
LABEL_25:
  v7->rotate = sdfGetRandFloat(&dds3Effect_Rand) * 6.2832;
  v14 = (*pMagaSpiral)->param;
  rotate_s = v14->rotate_s;
  rotate_r = v14->rotate_r;
  else
  {
      goto LABEL_33;
  }
LABEL_33:
  v7->rotate_s = rotate_s
                      * ((1.0 - rotate_r)
                       + (rotate_r * sdfGetRandFloat(&dds3Effect_Rand)));
  v19 = (*pMagaSpiral)->param;
  radius_s_r = v19->radius_s_r;
  radius_s = v19->radius_s;
  else
  {
      goto LABEL_41;
  }
LABEL_41:
  v7->radius = radius_s
                    * ((1.0 - radius_s_r)
                     + (radius_s_r * sdfGetRandFloat(&dds3Effect_Rand)));
  v24 = (*pMagaSpiral)->param;
  radius_e_r = v24->radius_e_r;
  radius_e = v24->radius_e;
  else
  {
      goto LABEL_49;
  }
LABEL_49:
  v7->radius_s = ((radius_e
                        * ((1.0 - radius_e_r)
                         + (radius_e_r
                          * sdfGetRandFloat(&dds3Effect_Rand))))
                       - v7->radius)
                      / (*pMagaSpiral)->param->life;
  pMagatuhi = (*pMagaSpiral)->pMagatuhi;
  p_hMagaBill = &pMagatuhi->hMagaBill;
LABEL_53:
  dds3MagatuhiBillPartsInit(p_hMagaBill, index);
  pRGBA = (*pMagaSpiral)->pMagatuhi->hMagaBill->pRGBA;
  pRGBA->m_Items[index] = 0;
}

// 0x16b1dd0
void effMagaSpiralRandomize(effHandle_t **hEffect) {
  Il2CppObject *pwork;
  dds3MagatuhiPar_tag_c *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  Il2CppObject *v7;
  Il2CppClass *v8;
  effMagaSpiral_tag_o *monitor;
  effMagaSpiral_tag_c *v10;
  s64 v11;
  char *v12;
  s64 *v13;
  s64 v14;
  s64 v15;
  s32 v16;
  u64 v17;
  s64 v18;
  dds3MagatuhiBill_tag_o *v19;
  u64 v22;
  s64 v25;
  s64 v27;
  signed s32 Rand;
  s32 v29;
  f32 v30;
  f32 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  s32 v35;
  f32 v36;
  f32 v37;
  s64 i;
  f32 y;
  f32 x;
  f32 w;
  f32 z;
  char *v45;
  s64 *v46;
  char *v47;
  s64 *v48;
  u64 v49;
  f32 v50;
  f32 v51;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Vector4_o dst;
  UnityEngine_Vector4_o p;
  effMagaSpiral_tag_o *pMagaSpiral;
  dds3MagatuhiBill_tag_o *hMagaBill;
  u64 v57[2];
  char *v58;
  UnityEngine_Vector4_o v59;

  pMagaSpiral = 0;
  hMagaBill = 0;
  *&p.x = 0;
  *&p.z = 0;
  *&dst.x = 0;
  *&dst.z = 0;
  if ((*hEffect)->major == 3)
  {
    pwork = (*hEffect)->pwork;
    klass = pwork->klass;
    if (pwork->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3MagatuhiPar_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3MagatuhiPar_tag, v57);
      if ((v57[0] & 1) != 0)
        v45 = v58;
      else
        v45 = v57 + 1;
      v46 = sub_8C4940(v45);
    }
    if (LODWORD(pwork[1].klass) == 3)
    {
      v7 = (*hEffect)->pwork;
      v8 = v7->klass;
      if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth || v8->_2.typeHierarchy[typeHierarchyDepth - 1] != v4)
      {
        sub_8FC2C0(v8->_1.element_class, v4, v57);
        if ((v57[0] & 1) != 0)
          v47 = v58;
        else
          v47 = v57 + 1;
        v48 = sub_8C4940(v47);
      }
      monitor = v7[1].monitor;
      if (monitor)
      {
        v10 = monitor->klass;
        if (monitor->klass->_2.typeHierarchyDepth < v11 || v10->_2.typeHierarchy[v11 - 1] != effMagaSpiral_tag)
        {
          sub_8FC2C0(v10->_1.element_class, effMagaSpiral_tag, v57);
          if ((v57[0] & 1) != 0)
            v12 = v58;
          else
            v12 = v57 + 1;
          v13 = sub_8C4940(v12);
        }
      }
      v14 = *(&loc_50 + monitor);
      v15 = *(v14 + 88);
      v16 = *(v14 + 36);
      v17 = *(v15 + 16);
      v18 = *(v15 + 20);
      v19 = *(*(&loc_60 + monitor) + 24LL);
      pMagaSpiral = monitor;
      hMagaBill = v19;
      SDF_VU0__COPYVECTOR(&dst, *(v14 + 16), 0);
      memmove(&dest, &monitor->fields, 0x40u);
      SDF_VU0__LOADMATRIX(&dest);
      v49 = v17;
      if (v17)
      {
        v22 = 0;
        while (1)
        {
          effMagaSpiralPartInit(&pMagaSpiral, v22);
          v25 = *(&loc_58 + monitor);
          v27 = *(v25 + 8 * v22 + 32);
            break;
          if ((byte_3F5A39D & 1) == 0)
            goto LABEL_36;
LABEL_37:
          Rand = sdfGetRand(&dds3Effect_Rand);
          v51 = *(v27 + 32);
          v29 = Rand % v16;
          v30 = (Rand % v16 - v18);
          if (Rand % v16 <= v18)
            v30 = 0.0;
          v31 = *(v27 + 28) + (*(v27 + 32) * v30);
          *(v27 + 16) = v29;
          v50 = *(v27 + 40);
          v32 = v30 * v50;
          v33 = *(v27 + 24);
          v34 = v30 * v33;
          if (v29 > v18)
            v29 = 0;
          v35 = v18 - v29;
          v36 = *(v27 + 36) + v32;
          v37 = *(v27 + 20) + v34;
          sub_854930(&p, 3u);
          if (v35 >= 1)
          {
            for (i = 0; i < v35; ++i)
            {
              sdfCos(v31);
              sub_854930(&p, 0);
              sub_854930(&p, 1u);
              sdfSin(v31);
              sub_854930(&p, 2u);
              SDF_VU0__LOADVECTOR_B(dst);
              SDF_VU0__LOADVECTOR(p);
              SDF_VU0__APPLYMATRIX();
              SDF_VU0__ADDVECTOR();
              SDF_VU0__STOREVECTOR(&p);
              x = p.x;
              y = p.y;
              z = p.z;
              w = p.w;
              v59.x = x;
              v59.y = y;
              v59.z = z;
              v59.w = w;
              dds3MagatuhiBillSetVertex(&hMagaBill, v22, v59);
              v31 = v51 + v31;
              v37 = v33 + v37;
              v36 = v50 + v36;
            }
          }
          v22 += 3LL;
          *(v27 + 20) = v37;
          *(v27 + 36) = v36;
          *(v27 + 28) = v31;
          if (v22 >= v49)
            return;
        }
        if ((byte_3F5A39D & 1) != 0)
          goto LABEL_37;
LABEL_36:
        goto LABEL_37;
      }
    }
  }
}

// 0x16b1a90
void effMagaSpiralSetPosition(void **pData, sdfVector4_t pPos) {
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
  klass = (*pData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSpiral_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effMagaSpiral_tag, v12);
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
  SDF_VU0__COPYVECTOR(&(*pData)[5].klass->_1.name, v13, 0);
}

// 0x16b1bb0
void effMagaSpiralSetRGBA(void **pData, u32 abgr) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 v9[3];

  klass = (*pData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSpiral_tag)
  {
    sub_8FC2C0(klass->_1.element_class, effMagaSpiral_tag, v9);
    if ((v9[0] & 1) != 0)
      v7 = v9[2];
    else
      v7 = v9 + 1;
    v8 = sub_8C4940(v7);
  }
  LODWORD((*pData)[6].monitor) = abgr;
}

// 0x16b1ca0
void effMagaSpiralSetRotateMatrix(void **pData, sdfMatrix4_t *pMatrix) {
  s64 v5;
  s64 v6;
  Il2CppObject *v7;
  s64 v8;
  s64 v9;
  s64 v10;
  s64 v11;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v14;
  s64 *v15;
  UnityEngine_Matrix4x4_o v16;
  u64 v17[3];

  v5 = *&pMatrix->m00;
  v6 = *&pMatrix->m20;
  v7 = *pData;
  v8 = *&pMatrix->m21;
  *&v16.m01 = *&pMatrix->m01;
  *&v16.m21 = v8;
  *&v16.m00 = v5;
  *&v16.m20 = v6;
  v9 = *&pMatrix->m02;
  v10 = *&pMatrix->m22;
  v11 = *&pMatrix->m23;
  *&v16.m03 = *&pMatrix->m03;
  *&v16.m23 = v11;
  *&v16.m02 = v9;
  *&v16.m22 = v10;
  SDF_VU0__LOADMATRIX(&v16);
  if (v7)
  {
    klass = v7->klass;
    if (v7->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != effMagaSpiral_tag)
    {
      sub_8FC2C0(klass->_1.element_class, effMagaSpiral_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[1]);
}

// 0x16aa970
effMagatuhi_tag *effMagatuhiCreate(effMagatuhiParams_t *pParams) {
  Il2CppObject *v3;
  f32 scale;
  u32 number;
  u32 tail;
  u32 blend;
  f32 t;
  dds3MagatuhiBill_tag_o *monitor;
  s64 point;
  f32 v14;
  f32 v15;
  Il2CppClass *klass;
  u32 namespaze_high;
  u32 data;
  f32 v19;
  u64 v20;
  s64 v21;
  struct System_UInt32_array *pVC;
  u32 v23;

  v3 = Allocate(effMagatuhi_tag);
  _ctor(v3, 0);
  v3[1].klass = pParams;
  scale = pParams->scale;
  number = pParams->number;
  tail = pParams->tail;
  blend = pParams->blend;
  t = pParams->t;
  monitor = dds3MagatuhiBillCreate(number, tail, scale, blend, t);
  v3[1].monitor = monitor;
  point = monitor->point;
  if (monitor->point)
  {
    v14 = point;
    v15 = 1.0 / v14;
    klass = v3[1].klass;
    namespaze_high = HIDWORD(klass->_1.namespaze);
    data = klass->_1.byval_arg.data;
    v19 = 0.0;
    v20 = 0;
    v21 = point - 1;
    while (1)
    {
      pVC = monitor->pVC;
      v23 = effColorBlend(namespaze_high, data, v19);
      pVC->m_Items[v20] = v23;
      if (v21 == v20)
        break;
      monitor = v3[1].monitor;
      ++v20;
      v19 = v15 + v19;
    }
  }
  return v3;
}

// 0x16aaad0
void effMagatuhiDelete(effMagatuhi_tag **pMagatuhi) {
  struct dds3MagatuhiBill_tag_o *hMagaBill;
  struct XRD773Unity_CommonMesh_array **p_pMesh;
  struct XRD773Unity_CommonMesh_array *v5;
  struct XRD773Unity_CommonMesh_array *pMesh;
  u32 max_length;
  s64 v8;
  u64 v9;
  UnityEngine_Object_o *v11;
  struct XRD773Unity_CommonMesh_array *v12;
  UnityEngine_Object_o *gameObject;
  struct XRD773Unity_CommonMesh_array *v16;
  struct dds3MagatuhiBill_tag_o *v18;
  s64 v19;

  if (*pMagatuhi)
  {
    hMagaBill = (*pMagatuhi)->hMagaBill;
    if (hMagaBill)
    {
      pMesh = hMagaBill->pMesh;
      p_pMesh = &hMagaBill->pMesh;
      v5 = pMesh;
      if (pMesh)
      {
        if (v5->max_length >= 1)
        {
          max_length = v5->max_length;
          v8 = 4;
          do
          {
            v9 = v8 - 4;
            v11 = *(&v5->obj.klass + v8);
            if (op_Inequality(v11, 0, 0))
            {
              v12 = (*pMagatuhi)->hMagaBill->pMesh;
              gameObject = get_gameObject(*(&v12->obj.klass + v8), 0);
              {
              }
              Destroy_27360000(gameObject);
              v16 = (*pMagatuhi)->hMagaBill->pMesh;
              *(&v16->obj.klass + v8) = 0;
            }
            v18 = (*pMagatuhi)->hMagaBill;
            v5 = v18->pMesh;
            max_length = v5->max_length;
            v19 = v8 - 3;
            ++v8;
          }
          while (v19 < max_length);
          p_pMesh = &v18->pMesh;
        }
        *p_pMesh = 0;
      }
    }
  }
  dds3MagatuhiUVBuff = 0;
}

// 0x16aac80
void effMagatuhiDraw(effMagatuhi_tag **pMagatuhi, char *callname) {
  dds3MagatuhiBill_tag_o *hMagaBill;

  hMagaBill = (*pMagatuhi)->hMagaBill;
  dds3MagatuhiBillDraw(hMagaBill, callname);
}
