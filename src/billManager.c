#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct BillTable_t BillTable_t;
typedef struct P2A_ANIMATION_tag P2A_ANIMATION_tag;
typedef struct P2A_HEAD_t P2A_HEAD_t;
typedef struct P2A_TEXANIM_tag P2A_TEXANIM_tag;
typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct billHandle_t billHandle_t;
typedef struct billManager_hG_t billManager_hG_t;
typedef struct dds3BillAnimResource_tag dds3BillAnimResource_tag;
typedef struct dds3BillAnim_tag dds3BillAnim_tag;
typedef struct dds3BillResource_tag dds3BillResource_tag;
typedef struct dds3Billboard_P2A_tag3 dds3Billboard_P2A_tag3;
typedef struct dds3DefaultMain dds3DefaultMain;
typedef struct dds3EffectTable_t dds3EffectTable_t;
typedef struct dds3MultiBillResource_tag dds3MultiBillResource_tag;
typedef struct dds3P2APolygonResource_tag dds3P2APolygonResource_tag;
typedef struct dds3P2APolygon_tag dds3P2APolygon_tag;
typedef struct pacFileHandle_t pacFileHandle_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfDrawTag_t sdfDrawTag_t;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfMemHandle_t sdfMemHandle_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct billManager_hG_t {
    u16 type;
    billHandle_t *handle;
};

static BillTable_t *BillboardTable[8];
static billManager_hG_t *hGeneralBillboard;
static dds3BillResource_tag *hDrawListTop;
static dds3EffectTable_t *EffBillboardTable[2];
static void *pBillTexture;
static f32 bill_alf_raito;
static f32 bill_alf_raito2;
static f32 bill_bri_raito;
static f32 bill_cut_raito;
static f32 bill_cut_raito2;
static f32 bill_par_scl_raito;
static f32 bill_eff_scl_raito;
static bool billtex_load;
static void *billtex_list;

dds3BillResource_tag *BillboardLoadTex(void *pTex);
u32 Byte2UInt32(u8 **bytedata, s32 pos);
sdfColor_t **GetColor(XRD773Unity_CommonMesh *this);
s32 **GetIndexTable(XRD773Unity_CommonMesh *this);
void *GetMainCamera(dds3DefaultMain *this);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
sdfVector3_t **GetPosition(XRD773Unity_CommonMesh *this);
void *GetTexture(XRD773Unity_CommonMesh *this);
s32 GetTmxIndex(u8 **bData, s32 bPos);
s32 GetUseIndex(XRD773Unity_CommonMesh *this);
s32 GetUseIndexMax(XRD773Unity_CommonMesh *this);
s32 GetUseOne(XRD773Unity_CommonMesh *this);
sdfVector2_t **GetUvTable(XRD773Unity_CommonMesh *this);
void *LoadFile(AssetBundleCtrl *this, char *key, char *path, char *name, char *extension);
void MultMatrixNoArg(void);
void P2A_ANIMATION_tag__pCopy(P2A_ANIMATION_tag *this, u8 **bytedata, s32 *bpos);
void P2A_HEAD_t__pCopy(P2A_HEAD_t *this, u8 **bytedata, s32 *bpos);
void P2A_TEXANIM_tag__pCopy(P2A_TEXANIM_tag *this, u8 **bytedata, s32 *bpos);
void SDF_VU0__ADDVECTOR(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_B(void);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__COPYVECTOR_C_TO_B(void);
f32 SDF_VU0__INNERPRODUCT(void);
void SDF_VU0__LOADMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADMATRIX_B(sdfMatrix4_t *aMatrix);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__NORMALIZE(void);
void SDF_VU0__SCALEVECTOR(f32 v);
void SDF_VU0__STOREIDENTITY(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREMATRIX(sdfMatrix4_t *aMatrix);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetMatTexture(XRD773Unity_CommonMesh *this, void *texture);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
void SetUseIndex(XRD773Unity_CommonMesh *this, s32 index);
void SetUvTable_20243232(XRD773Unity_CommonMesh *this, sdfVector2_t **pos);
void *billGetTexture(s32 index);
dds3BillAnimResource_tag *dds3BillAnimLoadP2A(void *pData, s32 *bPos, void **pTGA);
billHandle_t *dds3BillboardCopy(billHandle_t *hBillboard);
billHandle_t *dds3BillboardCreate(s32 type, void *pTex, s32 bPos, char *callname);
void dds3BillboardDelete(void **hData);
void dds3BillboardTagLink(billHandle_t **hBillboard, dds3BillResource_tag **hResource, s32 use_mesh_idx);
void dds3Billboard_BasicInit(billHandle_t **pBasic);
dds3BillResource_tag *dds3Billboard_P2AAnimDraw(dds3Billboard_P2A_tag3 **pP2A, dds3BillAnim_tag **pBillAnim);
billHandle_t *dds3Billboard_P2ACopy(dds3Billboard_P2A_tag3 *pCopyP2A);
void dds3Billboard_P2ASetAnim(dds3BillAnimResource_tag **hBillAnimRes, s32 number, dds3BillAnim_tag **pBillAnim);
void dds3Billboard_P2ASetNumber(dds3Billboard_P2A_tag3 **pP2A, s32 number);
void dds3P2APolygonGetResource(dds3P2APolygon_tag **hP2APoly, dds3P2APolygonResource_tag **pP2APolyRes);
u32 effColorMultiply(u32 abgr0, u32 abgr1);
sdfColor_t effGetBlendColor(u32 icol);
void effScreenOffset(void);
f32 sdfAtan2(f32 aY, f32 aX);
f32 sdfCos(f32 aRadius);
void *sdfDevLoadFileUnity_25061072(char *aFilename, u8 ***aTopPtr, s32 aSizePtr, char *akey);
f32 sdfFabs(f32 c);
void sdfMatSetAmbient(sdfMat_t *aMat, u32 aColor);
void sdfMatSetConstant(sdfMat_t *aMat, f32 aRatio);
void sdfMatSetDiffuse(sdfMat_t *aMat, u32 aColor);
void sdfMatSetSpecular(sdfMat_t *aMat, u32 aColor);
f32 sdfSin(f32 aRadius);

// 0x1317a80
void BillboardFreeTex(dds3BillResource_tag *hResource) {
  ;
}

// 0x1317890
dds3BillResource_tag *BillboardLoadTex(void *pTex) {
  u64 *v3;
  u64 *v4;
  bool v6;
  u64 v7;
  u64 v8;
  s16 v9;
  u32 *v10;
  s32 v11;
  s32 v13;
  u64 v15;
  s64 v17;
  s64 v18;

  v3 = Allocate(dds3BillResource_tag);
  dds3BillResource_tag___ctor(v3);
  *(v3 + 7) = 0;
  *(v3 + 22) = 0;
  v3[9] = 0;
  v3[10] = v3;
  *(v3 + 12) = 0;
  v4 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v4);
  v3[2] = v4;
  v6 = op_Inequality(pTex, 0, 0);
  v7 = v3[2];
  if (v6)
  {
    *(v7 + 40) = (pTex->klass->vtable._4_get_width.methodPtr)(pTex, pTex->klass->vtable._4_get_width.method);
    v8 = v3[2];
    v9 = (pTex->klass->vtable._6_get_height.methodPtr)(pTex, pTex->klass->vtable._6_get_height.method);
  }
  else
  {
    v9 = 8;
    *(v7 + 40) = 8;
    v8 = v3[2];
  }
  *(v8 + 42) = v9;
  ++*(v3 + 7);
  v10 = NewSpecific(UnityEngine_Vector2, 2u);
  v18 = 0;
  sub_851710(&v18, 0.0, 1.0);
  v11 = HIDWORD(v18);
  v10[8] = v18;
  v10[9] = v11;
  v17 = 0;
  sub_851710(&v17, 1.0, 0.0);
  v13 = HIDWORD(v17);
  v10[10] = v17;
  v10[11] = v13;
  v15 = v3[2];
  v3[4] = v10;
  v3[5] = 0;
  *(v3 + 12) = (*(v15 + 40) >> 1) * 0.0625;
  *(v3 + 13) = (*(v15 + 42) >> 1) * 0.0625;
  return v3;
}

// 0x1320b00
void **GetBillTexListUnit(void) {
  return billtex_list;
}

// 0x1320a90
void SetBillTexListUnit(void **texList) {
  billtex_list = texList;
}

// 0x1320a20
void SetBillTexLoadUnityOff(void) {
  billtex_load = 0;
}

// 0x13209b0
void SetBillTexLoadUnityOn(void) {
  billtex_load = 1;
}

// 0x13204b0
f32 billAlfRaitoGet(void) {
  s16 v3;
  s32 v4;
  f32 result;

  if ((v3 & 0x200) != 0)
  {
    v4 = v3 & 0x200;
    result = bill_alf_raito;
    if (result == 0.0)
    {
LABEL_5:
      else
      {
        result = bill_alf_raito2;
        if (result != 0.0)
          goto LABEL_8;
      }
      return 0.0;
    }
  }
  else
  {
    v4 = 0;
    result = bill_alf_raito;
    if (result == 0.0)
      goto LABEL_5;
  }
  return result;
}

// 0x13203b0
void billAlfRaitoSet(f32 raito) {
  bill_alf_raito = raito;
}

// 0x1320430
void billAlfRaitoSet2(f32 raito) {
  bill_alf_raito2 = raito;
}

// 0x1320650
f32 billBriRaitoGet(void) {
  return bill_bri_raito;
}

// 0x13205d0
void billBriRaitoSet(f32 raito) {
  bill_bri_raito = raito;
}

// 0x1320270
void billClrTexture(bool allclear) {
  billManager_c *v3;
  u64 v4;
  Il2CppClass **v5;
  struct UnityEngine_Texture_array *pBillTexture;
  u64 max_length_low;

  if (allclear)
  {
    if (pBillTexture)
    {
      v4 = 0;
      if ((v3->_2.bitflags2 & 2) == 0)
        goto LABEL_13;
LABEL_11:
LABEL_13:
      while (1)
      {
        max_length_low = LODWORD(pBillTexture->max_length);
        if (v4 >= max_length_low)
          break;
        else if (v4 >= max_length_low)
        {
          goto LABEL_17;
        }
        v5 = &pBillTexture->obj.klass + v4++;
        v5[4] = 0;
          goto LABEL_11;
      }
    }
  }
  pBillTexture = 0;
}

// 0x1320740
f32 billCutRaitoGet(void) {
  return bill_cut_raito;
}

// 0x1320830
f32 billCutRaitoGet2(void) {
  return bill_cut_raito2;
}

// 0x13206c0
void billCutRaitoSet(f32 raito) {
  bill_cut_raito = raito;
}

// 0x13207b0
void billCutRaitoSet2(f32 raito) {
  bill_cut_raito2 = raito;
}

// 0x131adc0
void *billGetTexture(s32 index) {
  struct UnityEngine_Texture_array *pBillTexture;
  s32 max_length;
  s64 v6;

  if (!pBillTexture)
    return 0;
LABEL_6:
  max_length = pBillTexture->max_length;
  if (max_length <= index)
    return 0;
LABEL_9:
  else
  {
    v6 = index;
    if (max_length <= index)
      goto LABEL_12;
  }
  return pBillTexture->m_Items[v6];
}

// 0x13201c0
s32 billGetTextureMax(void) {
  struct UnityEngine_Texture_array *pBillTexture;

  if (!pBillTexture)
    return 0;
LABEL_6:
  return pBillTexture->max_length;
}

// 0x1320920
void billScaleRaitoGet(f32 *par_scl_raito, f32 *eff_scl_raito) {
  *par_scl_raito = bill_par_scl_raito;
  *eff_scl_raito = bill_eff_scl_raito;
}

// 0x13208a0
void billScaleRaitoSet(f32 par_scl_raito, f32 eff_scl_raito) {
  bill_par_scl_raito = par_scl_raito;
  bill_eff_scl_raito = eff_scl_raito;
}

// 0x1320150
void billSetTexture(void **pTexture) {
  pBillTexture = pTexture;
}

// 0x131b8e0
void dds3BillAnimFreeP2A(dds3BillAnimResource_tag *hBillAnimRes) {
  ;
}

// 0x131b060
dds3BillAnimResource_tag *dds3BillAnimLoadP2A(void *pData, s32 *bPos, void **pTGA) {
  dds3BillAnimResource_tag_o *v6;
  Il2CppClass *v7;
  s64 *Interface;
  char *v9;
  s64 *v10;
  P2A_HEAD_t_o *v11;
  s32 v13;
  u32 v14;
  s32 v15;
  struct P2A_ANIMATION_tag_array *v16;
  struct P2A_HEAD_t_o *pHeader;
  struct P2A_TEXANIM_tag_array_array *v18;
  struct P2A_HEAD_t_o *v19;
  s64 v20;
  s32 v22;
  s32 TmxIndex;
  u64 v25;
  s32 v26;
  s32 max_length;
  u32 v28;
  u32 *pResList;
  UnityEngine_Texture_o *v31;
  s64 *Tex;
  u32 *v34;
  s64 *v35;
  struct dds3BillResource_tag_array *v39;
  u64 i;
  u32 *pAnimTable;
  u64 *v48;
  struct P2A_ANIMATION_tag_array *v50;
  struct P2A_ANIMATION_tag_array *v52;
  P2A_ANIMATION_tag_o *v54;
  s32 times;
  u32 *pTexAnimTable;
  s64 *v57;
  s64 *v58;
  u64 v60;
  s64 v61;
  struct P2A_TEXANIM_tag_array_array *v63;
  u32 *v65;
  u64 v66;
  u64 *v67;
  struct P2A_TEXANIM_tag_array_array *v69;
  P2A_TEXANIM_tag_array *v71;
  u64 v73;
  char mode;
  u32 *pABGRTable;
  s64 *v76;
  s64 *v78;
  s64 v80;
  struct System_UInt32_array_array *v81;
  u64 v82;
  System_UInt32_array *v84;
  struct System_UInt32_array_array *v86;
  Il2CppClass **v88;
  s32 v89;
  Il2CppClass *v90;
  u32 v91;
  u64 v93;
  s64 AnimNum;
  s32 v97;
  s32 pos;
  u64 v99[3];

  v97 = *bPos;
  pos = 0;
  v6 = Allocate(dds3BillAnimResource_tag);
  dds3BillAnimResource_tag___ctor(v6);
  if (pData)
  {
    Interface = QueryInterface(pData, byte);
    if (!Interface)
    {
      sub_8FC2C0(pData->klass->_1.element_class, v7, v99);
      if ((v99[0] & 1) != 0)
        v9 = v99[2];
      else
        v9 = v99 + 1;
      v10 = sub_8C4940(v9);
    }
  }
  else
  {
    Interface = 0;
  }
  v11 = Allocate(P2A_HEAD_t);
  P2A_HEAD_t___ctor(v11);
  P2A_HEAD_t__pCopy(v11, Interface, bPos);
  v13 = v11->tmxofs + v97;
  v14 = Byte2UInt32(Interface, v13);
  v6->pHeader = v11;
  v15 = v14;
  v16 = NewSpecific(P2A_ANIMATION_tag, v11->AnimNum);
  pHeader = v6->pHeader;
  v6->pAnimTable = v16;
  v18 = NewSpecific(P2A_TEXANIM_tag__, pHeader->AnimNum);
  v19 = v6->pHeader;
  v6->pTexAnimTable = v18;
  v6->pABGRTable = NewSpecific(uint__, v19->AnimNum);
  v6->TexNum = v15;
  v20 = v15;
  v6->pResList = NewSpecific(dds3BillResource_tag, v15);
  v22 = v13 + 4;
  TmxIndex = GetTmxIndex(Interface, v22);
  if (v15 >= 1)
  {
    v25 = 0;
    v26 = TmxIndex;
    do
    {
      while (pTGA)
      {
        max_length = pTGA->max_length;
        if (v26 + v25 >= max_length)
          v28 = 0;
        else
          v28 = v26 + v25;
        pResList = v6->pResList;
        v31 = pTGA->m_Items[v28];
        else
        {
          Tex = BillboardLoadTex(v31);
          if (Tex)
            goto LABEL_27;
        }
        *&pResList[2 * v25 + 8] = Tex;
        v39 = v6->pResList;
        v39->m_Items[v25]->hTex->texId = v26 + v25;
        if (v20 == ++v25)
          goto LABEL_45;
      }
      v34 = v6->pResList;
      else
      {
        v35 = BillboardLoadTex(0);
        if (v35)
          goto LABEL_32;
      }
      *&v34[2 * v25++ + 8] = v35;
    }
    while (v20 != v25);
  }
LABEL_45:
  v6->count = 1;
  v6->AnimNum = 1;
  AnimNum = v6->pHeader->AnimNum;
  if (v6->pHeader->AnimNum >= 1)
  {
    for (i = 0; i != AnimNum; ++i)
    {
      pAnimTable = v6->pAnimTable;
      v48 = Allocate(P2A_ANIMATION_tag);
      P2A_ANIMATION_tag___ctor(v48);
      *&pAnimTable[2 * i + 8] = v48;
      v50 = v6->pAnimTable;
      P2A_ANIMATION_tag__pCopy(v50->m_Items[i], Interface, bPos);
      v52 = v6->pAnimTable;
      v54 = v52->m_Items[i];
      if ((v54->mode & 0x10000000) != 0)
      {
        times = v54->times;
      }
      else
      {
        if ((v54->attr & 0xC0) == 0)
          goto LABEL_63;
        times = 2;
      }
      v6->AnimNum = times;
LABEL_63:
      pTexAnimTable = v6->pTexAnimTable;
      v57 = NewSpecific(P2A_TEXANIM_tag, v54->times);
      v58 = v57;
      *&pTexAnimTable[2 * i + 8] = v58;
      pos = v54->spranm + v97;
      LODWORD(v60) = v54->times;
      if (v60)
      {
        v61 = 4;
        do
        {
          v63 = v6->pTexAnimTable;
          v65 = v63->m_Items[i];
          v66 = v61 - 4;
          v67 = Allocate(P2A_TEXANIM_tag);
          P2A_TEXANIM_tag___ctor(v67);
          *&v65[2 * v61] = v67;
          v69 = v6->pTexAnimTable;
          v71 = v69->m_Items[i];
          P2A_TEXANIM_tag__pCopy(*(&v71->obj.klass + v61), Interface, &pos, 0);
          v60 = v54->times;
          v73 = v61 - 3;
          ++v61;
        }
        while (v73 < v60);
      }
      mode = v54->mode;
      v54->spranm = i;
      if ((mode & 1) != 0)
      {
        pABGRTable = v6->pABGRTable;
        v76 = NewSpecific(uint, v60);
        v78 = v76;
        *&pABGRTable[2 * i + 8] = v78;
        pos = v54->alpha + v97;
        if (v54->times)
        {
          v80 = 8;
          do
          {
            v81 = v6->pABGRTable;
            v82 = v80 - 8;
            v84 = v81->m_Items[i];
            *(&v84->obj.klass + v80) = 0;
            v86 = v6->pABGRTable;
            v88 = &v86->obj.klass + i;
            v89 = pos;
            v90 = v88[4];
            v91 = Byte2UInt32(Interface, v89);
            *(&v90->_1.image + v80) = v91;
            pos += 4;
            v93 = v80 - 7;
            ++v80;
          }
          while (v93 < v54->times);
        }
      }
      v54->alpha = i;
    }
  }
  return v6;
}

// 0x131cd40
billHandle_t *dds3BillboardCopy(billHandle_t *hBillboard) {
  dds3Billboard_P2A_tag3_o *pP2A;
  billHandle_t_o *v5;
  dds3Billboard_Normal_tag3_o *v6;
  billHandle_t_o *pBasic;

  pBasic = 0;
  if (!hBillboard)
    return 0;
  if (hBillboard->type == 1)
  {
    pP2A = hBillboard->pP2A;
    v5 = dds3Billboard_P2ACopy(pP2A);
    pBasic = v5;
  }
  else
  {
    v5 = Allocate(billHandle_t);
    billHandle_t___ctor(v5);
    v6 = Allocate(dds3Billboard_Normal_tag3);
    dds3Billboard_Normal_tag3___ctor(v6);
    v6->basic = v5;
    v5->pNormal = v6;
    pBasic = v5;
    v6->hResource = hBillboard->pNormal->hResource;
    ++v5->pNormal->hResource->count;
  }
  dds3Billboard_BasicInit(&pBasic);
  v5->type = hBillboard->type;
  v5->tbl = hBillboard->tbl;
  v5->texture = hBillboard->texture;
  v5->callname = "dds3BillboardCopy";
  return v5;
}

// 0x131cee0
billHandle_t *dds3BillboardCopyO(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v11[3];

  v5 = *hData;
  else if (!v5)
  {
    return dds3BillboardCopy(v5, *&bPos);
  }
  klass = v5->klass;
  if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != billHandle_t)
  {
    sub_8FC2C0(klass->_1.element_class, billHandle_t, v11);
    if ((v11[0] & 1) != 0)
      v8 = v11[2];
    else
      v8 = v11 + 1;
    v9 = sub_8C4940(v8);
  }
  return dds3BillboardCopy(v5, *&bPos);
}

// 0x13193e0
billHandle_t *dds3BillboardCreate(s32 type, void *pTex, s32 bPos, char *callname) {
  struct dds3EffectTable_t_array *EffBillboardTable;
  Il2CppObject *v12;
  billHandle_t_c *v13;
  billHandle_t_o *v14;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v17;
  s64 *v18;
  struct dds3EffectTable_t_array *v19;
  billHandle_t_o *v22[3];
  billHandle_t_o *pBasic;

  pBasic = 0;
  v12 = dds3EffectTable_t_CreateDelegate__Invoke(EffBillboardTable->m_Items[type]->Create, pTex, bPos, 0, 0);
  v14 = v12;
  if (v12)
  {
    klass = v12->klass;
    if (v12->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != billHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, billHandle_t, v22);
      if ((v22[0] & 1) != 0)
        v17 = v22[2];
      else
        v17 = v22 + 1;
      v18 = sub_8C4940(v17);
    }
  }
  pBasic = v12;
  dds3Billboard_BasicInit(&pBasic, v13);
  v14->type = type;
  v19 = EffBillboardTable;
  v14->tbl = v19->m_Items[type];
  v14->callname = callname;
  return v14;
}

// 0x13196e0
void dds3BillboardDelete(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 *monitor;
  s64 v10;
  s64 v11;
  u64 v12;
  UnityEngine_Object_o *v14;
  UnityEngine_Component_o **v15;
  UnityEngine_Object_o *gameObject;
  u64 *v19;
  s64 v21;
  s64 klass_low;
  Il2CppObject *v23;
  struct dds3EffectTable_t_array *EffBillboardTable;
  struct dds3EffectTable_t_array *v28;
  s64 v29;
  Il2CppObject *v31[3];
  Il2CppObject *UnnamedParameter;

  UnnamedParameter = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != billHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, billHandle_t, v31);
      if ((v31[0] & 1) != 0)
        v7 = v31[2];
      else
        v7 = v31 + 1;
      v8 = sub_8C4940(v7);
    }
    monitor = v3[6].monitor;
    if (monitor)
    {
      v10 = monitor[3];
      if (v10 >= 1)
      {
        v11 = 4;
        do
        {
          v12 = v11 - 4;
          v14 = monitor[v11];
          if (op_Inequality(v14, 0, 0))
          {
            v15 = v3[6].monitor;
            gameObject = get_gameObject(v15[v11]);
            Destroy_27360000(gameObject);
            v19 = v3[6].monitor;
            v19[v11] = 0;
          }
          monitor = v3[6].monitor;
          LODWORD(v10) = *(monitor + 6);
          v21 = v11 - 3;
          ++v11;
        }
        while (v21 < v10);
      }
      v3[6].monitor = 0;
    }
    UnnamedParameter = 0;
    klass_low = LOWORD(v3[4].klass);
    if (klass_low == 1)
      v23 = v3[5].klass;
    else
      v23 = v3[4].monitor;
    UnnamedParameter = v23;
    if (EffBillboardTable->m_Items[klass_low]->Delete)
    {
      v28 = EffBillboardTable;
      v29 = LOWORD(v3[4].klass);
      dds3EffectTable_t_DeleteDelegate__Invoke(v28->m_Items[v29]->Delete, &UnnamedParameter);
    }
  }
}

// 0x131d000
void dds3BillboardDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppObject *monitor;
  Il2CppObject *v9;
  u64 v10[3];

  v9 = 0;
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != billHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, billHandle_t, v10);
      if ((v10[0] & 1) != 0)
        v6 = v10[2];
      else
        v6 = v10 + 1;
      v7 = sub_8C4940(v6);
    }
    v9 = 0;
    if (LOWORD(v3[4].klass) == 1)
    {
      v3[5].klass->_1.name = v3;
      monitor = v3[5].klass;
    }
    else
    {
      *(v3[4].monitor + 2) = v3;
      monitor = v3[4].monitor;
    }
    v9 = monitor;
    dds3EffectTable_t_DrawDelegate__Invoke(*(v3[3].monitor + 3), &v9, 0);
  }
}

// 0x131d140
void dds3BillboardDrawOff(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u64 *monitor;
  s64 v10;
  s64 v11;
  UnityEngine_Object_o *v13;
  u64 *v14;
  s64 v16;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v18;
  s64 v19;
  u64 v20[3];

  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != billHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, billHandle_t, v20);
      if ((v20[0] & 1) != 0)
        v7 = v20[2];
      else
        v7 = v20 + 1;
      v8 = sub_8C4940(v7);
    }
    monitor = v3[6].monitor;
    if (monitor)
    {
      v10 = monitor[3];
      if (v10 >= 1)
      {
        v11 = 4;
        do
        {
          v13 = monitor[v11];
          if (op_Inequality(v13, 0, 0))
          {
            v14 = v3[6].monitor;
            v16 = v14[v11];
            gameObject = get_gameObject(v16);
            if (get_activeSelf(gameObject))
            {
              v18 = get_gameObject(v16);
              SetActive(v18, 0, 0);
            }
            *(v16 + 33) = 1;
          }
          monitor = v3[6].monitor;
          LODWORD(v10) = *(monitor + 6);
          v19 = v11 - 3;
          ++v11;
        }
        while (v19 < v10);
      }
    }
  }
}

// 0x131cc20
billHandle_t *dds3BillboardFileLoad(s32 type, char *pFileName, char *akey) {
  Il2CppObject *v5;
  System_Byte_array *v9;
  System_Byte_array *aTopPtr;

  v5 = pFileName;
  aTopPtr = 0;
  Write_2930400("BillManager Load...[{0}]\n", v5);
  if (!Contains(v5, ".bytes", 0))
    v5 = Concat_5224608(v5, ".bytes");
  sdfDevLoadFileUnity_25061072(v5, &aTopPtr, 0, akey);
  v9 = aTopPtr;
  return dds3BillboardCreate(type, &v9->obj, 0, "dds3BillboardFileLoad");
}

// 0x131d320
void *dds3BillboardGeneral(s32 number) {
  struct BillTable_t_array *BillboardTable;
  Il2CppObject *result;
  struct billManager_hG_t_array *hGeneralBillboard;
  struct billHandle_t_o *handle;
  struct dds3BillResource_tag_o *hResource;

  result = dds3BillboardCreate(BillboardTable->m_Items[number]->type, 0, 0, "dds3BillboardGeneral");
  handle = hGeneralBillboard->m_Items[number]->handle;
  result[5].monitor = handle->texture;
  hResource = handle->pNormal->hResource;
  *(result[4].monitor + 3) = hResource;
  ++hResource->count;
  return result;
}

// 0x131d440
s32 dds3BillboardGeneralNumber(void) {
  return BillboardTable->max_length;
}

// 0x131e160
s32 dds3BillboardGetAnimFrame(billHandle_t *hBillboard) {
  struct dds3BillAnim_tag_array *pAnim;

  if (hBillboard)
  {
    if (hBillboard->type == 1)
    {
      pAnim = hBillboard->pP2A->pAnim;
      LODWORD(hBillboard) = pAnim->m_Items[0]->pAnim->times;
    }
    else
    {
      LODWORD(hBillboard) = 0;
    }
  }
  return hBillboard;
}

// 0x131dff0
s32 dds3BillboardGetAnimNumber(billHandle_t *hBillboard) {
  if (hBillboard)
  {
    if (hBillboard->type == 1)
      LODWORD(hBillboard) = hBillboard->pP2A->hResource->pHeader->AnimNum;
    else
      LODWORD(hBillboard) = 0;
  }
  return hBillboard;
}

// 0x131e1c0
s32 dds3BillboardGetAnimState(billHandle_t *hBillboard) {
  if (hBillboard)
  {
    if (hBillboard->type == 1)
      LODWORD(hBillboard) = hBillboard->pP2A->state;
    else
      LODWORD(hBillboard) = 0;
  }
  return hBillboard;
}

// 0x131e1f0
s32 dds3BillboardGetAnimType(billHandle_t *hBillboard) {
  if (hBillboard)
  {
    if (hBillboard->type == 1)
      LODWORD(hBillboard) = hBillboard->pP2A->mode;
    else
      LODWORD(hBillboard) = 0;
  }
  return hBillboard;
}

// 0x131dfc0
s32 dds3BillboardGetCurrentAnimNumber(billHandle_t *hBillboard) {
  if (hBillboard)
  {
    if (hBillboard->type == 1)
      LODWORD(hBillboard) = hBillboard->pP2A->number;
    else
      LODWORD(hBillboard) = 0;
  }
  return hBillboard;
}

// 0x131e280
f32 dds3BillboardGetDirectionRotate(sdfVector4_t pPos, sdfVector4_t pVec) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v7;
  f32 v8;
  f32 v9;
  f32 v10;
  f32 v11;
  f32 v12;
  f32 v14;
  f32 v15;
  unsigned __int128 v17;
  UnityEngine_Vector4_o p;
  UnityEngine_Vector4_o v19;
  UnityEngine_Vector4_o v20;
  UnityEngine_Vector4_o v21;

  w = pVec.w;
  z = pVec.z;
  y = pVec.y;
  x = pVec.x;
  v7 = pPos.w;
  v8 = pPos.z;
  v9 = pPos.y;
  v10 = pPos.x;
  v20.x = v10;
  v20.y = v9;
  v20.z = v8;
  v20.w = v7;
  *&p.x = 0;
  *&p.z = 0;
  v17 = 0u;
  *&v19.x = 0;
  *&v19.z = 0;
  SDF_VU0__LOADVECTOR(v20);
  SDF_VU0__COPYVECTOR_A_TO_C();
  effScreenOffset();
  SDF_VU0__STOREVECTOR(&p);
  v21.x = x;
  v21.y = y;
  v21.z = z;
  v21.w = w;
  SDF_VU0__LOADVECTOR(v21);
  SDF_VU0__NORMALIZE();
  SDF_VU0__SCALEVECTOR(100.0);
  SDF_VU0__COPYVECTOR_C_TO_B();
  SDF_VU0__ADDVECTOR();
  effScreenOffset();
  SDF_VU0__STOREVECTOR(&v17);
  sub_854710(&p, 0);
  sub_854710(&v17, 0);
  sub_854930(&v19, 0);
  sub_854710(&p, 1u);
  sub_854710(&v17, 1u);
  sub_854930(&v19, 1u);
  sub_854930(&v19, 2u);
  SDF_VU0__LOADVECTOR(v19);
  SDF_VU0__NORMALIZE();
  SDF_VU0__STOREVECTOR(&v19);
  sub_854710(&v19, 1u);
  v12 = v11;
  sub_854710(&v19, 0);
  v15 = v14;
  return sdfAtan2(v12, v15);
}

// 0x131e4a0
f32 dds3BillboardGetDirectionScale(sdfVector4_t pPos, sdfVector4_t pVec) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  f32 v10;
  UnityEngine_Vector4_o v12;

  w = pVec.w;
  z = pVec.z;
  y = pVec.y;
  x = pVec.x;
  SDF_VU0__LOADVECTOR(dds3CameraTargetPos);
  SDF_VU0__LOADVECTOR_B(dds3CameraEyePos);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__NORMALIZE();
  SDF_VU0__COPYVECTOR_A_TO_B();
  v12.x = x;
  v12.y = y;
  v12.z = z;
  v12.w = w;
  SDF_VU0__LOADVECTOR(v12);
  v10 = SDF_VU0__INNERPRODUCT();
  return 1.0 - sdfFabs(v10);
}

// 0x131ded0
u16 dds3BillboardGetDrawType(billHandle_t *hBillboard) {
  u16 *MultiBillRes;

  if (hBillboard)
  {
    if (hBillboard->type == 1)
    {
      MultiBillRes = hBillboard->pP2A->MultiBillRes;
      goto LABEL_6;
    }
    if (!hBillboard->type)
    {
      MultiBillRes = hBillboard->pNormal->hResource;
LABEL_6:
      LOWORD(hBillboard) = MultiBillRes[12];
      return hBillboard;
    }
    LOWORD(hBillboard) = 0;
  }
  return hBillboard;
}

// 0x131d560
void **dds3BillboardGetGeneralPtexture(s32 number) {
  struct billManager_hG_t_array *hGeneralBillboard;

  return hGeneralBillboard->m_Items[number]->handle->pNormal->basic->texture;
}

// 0x131d4b0
sdfTexHandle_t *dds3BillboardGetGeneralTex(s32 number) {
  struct billManager_hG_t_array *hGeneralBillboard;

  return hGeneralBillboard->m_Items[number]->handle->pNormal->hResource->hTex;
}

// 0x131de50
sdfTexHandle_t *dds3BillboardGetTex(billHandle_t *hBillboard) {
  if (hBillboard)
  {
    if (hBillboard->type)
      return 0;
    else
      return hBillboard->pNormal->hResource->hTex;
  }
  return hBillboard;
}

// 0x131de80
u16 dds3BillboardGetType(billHandle_t *hBillboard) {
  if (hBillboard)
    LOWORD(hBillboard) = hBillboard->type;
  return hBillboard;
}

// 0x13199c0
void dds3BillboardLinkOt(void) {
  ;
}

// 0x13195b0
void dds3BillboardManagerExit(void) {
  billManager_c *v2;
  u64 v3;
  struct billManager_hG_t_array *hGeneralBillboard;
  Il2CppObject *hData;

  hData = 0;
  v3 = 0;
  hDrawListTop = 0;
  if ((v2->_2.bitflags2 & 2) != 0)
  {
LABEL_9:
  }
  while (1)
  {
    if (v3 >= SLODWORD(BillboardTable->max_length))
      break;
    else
    {
      if (v3 >= LODWORD(hGeneralBillboard->max_length))
        goto LABEL_15;
    }
    hData = hGeneralBillboard->m_Items[v3]->handle;
    dds3BillboardDelete(&hData);
    ++v3;
      goto LABEL_9;
  }
}

// 0x1318ea0
void dds3BillboardManagerInit(void) {
  struct billManager_hG_t_array *v4;
  billManager_c *v5;
  s64 v6;
  s16 v7;
  u64 v8;
  s64 v9;
  s32 i;
  u32 *hGeneralBillboard;
  u64 *v13;
  struct billManager_hG_t_array *v16;
  s64 v18;
  s64 v21;
  u64 v22;
  AssetBundleCtrl_o *asset_bc;
  struct BillTable_t_array *BillboardTable;
  Il2CppObject *File;
  s64 *v30;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v33;
  s64 *v34;
  struct billManager_hG_t_array *v36;
  s64 v38;
  struct billManager_hG_t_array *v40;
  s64 v42;
  struct billManager_hG_t_array *v43;
  s64 v45;
  u64 v48[3];

  v4 = NewSpecific(billManager_hG_t, LODWORD(BillboardTable->max_length));
  hGeneralBillboard = v4;
  v6 = 4;
  v7 = *&v5->_2.bitflags1;
  v8 = 0;
  if ((v7 & 0x200) != 0)
    goto LABEL_10;
LABEL_9:
  for (i = 0; ; i = v7 & 0x200)
  {
    if (v8 >= SLODWORD(BillboardTable->max_length))
      break;
    v13 = Allocate(billManager_hG_t);
    _ctor(v13, 0);
    *&hGeneralBillboard[2 * v6] = v13;
    v16 = hGeneralBillboard;
    v18 = *(&v16->obj.klass + v6);
    v9 = *(&BillboardTable->obj.klass + v6++);
    *(v18 + 16) = *(v9 + 32);
    v7 = *&v5->_2.bitflags1;
    v8 = v6 - 4;
    if ((v7 & 0x200) == 0)
      goto LABEL_9;
LABEL_10:
  }
  hDrawListTop = 0;
  v21 = 4;
  v22 = 0;
  if ((v5->_2.bitflags2 & 2) != 0)
  {
LABEL_32:
  }
  while (v22 < SLODWORD(BillboardTable->max_length))
  {
    asset_bc = get_asset_bc();
    File = LoadFile(
             asset_bc,
             "bill",
             *(*(&BillboardTable->obj.klass + v21) + 16LL),
             *(*(&BillboardTable->obj.klass + v21) + 24LL),
             ".tga",
             0);
    v30 = File;
    if (File)
    {
      klass = File->klass;
      if (File->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Texture)
      {
        sub_8FC2C0(klass->_1.element_class, UnityEngine_Texture, v48);
        if ((v48[0] & 1) != 0)
          v33 = v48[2];
        else
          v33 = v48 + 1;
        v34 = sub_8C4940(v33);
      }
    }
    v36 = hGeneralBillboard;
    v38 = *(&v36->obj.klass + v21);
    *(v38 + 24) = dds3BillboardCreate(
                    *(*(&BillboardTable->obj.klass + v21) + 32LL),
                    File,
                    -1,
                    "dds3BillboardManagerInit");
    v40 = hGeneralBillboard;
    v42 = *(*(&v40->obj.klass + v21) + 24LL);
    *(v42 + 88) = NewSpecific(UnityEngine_Texture, 1u);
    v43 = hGeneralBillboard;
    v45 = *(*(*(&v43->obj.klass + v21) + 24LL) + 88LL);
    *(v45 + 32) = v30;
    v22 = ++v21 - 4;
      goto LABEL_32;
  }
}

// 0x131e220
void dds3BillboardSetAnimColorAdvMode(billHandle_t **hBillboard) {
  billHandle_t_o *v2;

  v2 = *hBillboard;
  if (*hBillboard)
  {
    if (v2->type == 1)
      v2->pP2A->mode |= 0x1000000u;
  }
}

// 0x131e020
void dds3BillboardSetAnimKey(billHandle_t **hBillboard, s32 frame) {
  billHandle_t_o *v3;
  struct dds3Billboard_P2A_tag3_o *pP2A;
  s64 Anim_n;
  u64 i;
  struct dds3BillAnim_tag_array *pAnim;
  s64 v9;

  v3 = *hBillboard;
  if (*hBillboard)
  {
    if (v3->type == 1)
    {
      pP2A = v3->pP2A;
      Anim_n = pP2A->Anim_n;
      if (Anim_n >= 1)
      {
        for (i = 0; i != Anim_n; ++i)
        {
          pAnim = pP2A->pAnim;
          v9 = pAnim + 8 * i;
          *(*(v9 + 32) + 24LL) = (frame % *(*(*(v9 + 32) + 32LL) + 28LL));
        }
      }
    }
  }
}

// 0x131e0c0
void dds3BillboardSetAnimKey2(billHandle_t **hBillboard, s32 frame) {
  billHandle_t_o *v3;
  struct dds3Billboard_P2A_tag3_o *pP2A;
  s64 Anim_n;
  u64 v6;
  struct dds3BillAnim_tag_array *pAnim;
  s64 v9;
  s64 v10;

  v3 = *hBillboard;
  if (*hBillboard)
  {
    if (v3->type == 1)
    {
      pP2A = v3->pP2A;
      Anim_n = pP2A->Anim_n;
      if (Anim_n >= 1)
      {
        v6 = 0;
        do
        {
          pAnim = pP2A->pAnim;
          v9 = pAnim + 8 * v6++;
          v10 = *(v9 + 32);
          *(v10 + 24) = frame % *(*(v10 + 32) + 28LL);
          *(v10 + 28) = 1;
        }
        while (Anim_n != v6);
      }
    }
  }
}

// 0x131df10
void dds3BillboardSetAnimNumber(billHandle_t **hBillboard, s32 number) {
  billHandle_t_o *v5;
  dds3Billboard_P2A_tag3_o **p_pP2A;
  struct dds3Billboard_P2A_tag3_o *pP2A;

  v5 = *hBillboard;
  if (v5)
  {
    if (v5->type == 1)
    {
      pP2A = v5->pP2A;
      p_pP2A = &v5->pP2A;
      if (pP2A->number != number)
      {
        dds3Billboard_P2ASetNumber(p_pP2A, number);
      }
    }
  }
}

// 0x131dd80
void dds3BillboardSetCondition(billHandle_t **hBillboard, s16 condition) {
  billHandle_t_o *v3;
  struct dds3BillAnimResource_tag_o *hResource;
  s64 TexNum;
  u64 v6;
  struct dds3BillResource_tag_array *pResList;

  v3 = *hBillboard;
  if (*hBillboard)
  {
    if (v3->type == 1)
    {
      hResource = v3->pP2A->hResource;
      TexNum = hResource->TexNum;
      if (TexNum >= 1)
      {
        v6 = 0;
        pResList = hResource->pResList;
        if (!LODWORD(pResList->max_length))
        {
LABEL_9:
        }
        while (1)
        {
          pResList->m_Items[v6]->type = condition;
          if (TexNum - 1 == v6)
            break;
          ++v6;
          pResList = (*hBillboard)->pP2A->hResource->pResList;
          if (v6 >= LODWORD(pResList->max_length))
            goto LABEL_9;
        }
      }
    }
    else if (!v3->type)
    {
      v3->pNormal->hResource->type = condition;
    }
  }
}

// 0x131de90
void dds3BillboardSetDrawType(billHandle_t *hBillboard, u16 type) {
  if (hBillboard)
  {
    if (type == 1)
    {
      hBillboard->pP2A->MultiBillRes->type = 1;
    }
    else if (!type)
    {
      hBillboard->pNormal->hResource->type = 0;
    }
  }
}

// 0x131dba0
void dds3BillboardSetMode(billHandle_t **hBillboard, s16 mode) {
  billHandle_t_o *v3;
  s32 type;
  struct dds3Billboard_P2A_tag3_o *pP2A;
  s64 Anim_n;
  u64 v7;
  struct dds3BillAnim_tag_array *pAnim;
  struct P2A_ANIMATION_tag_o *v10;
  struct dds3BillAnim_tag_array *v11;
  struct P2A_ANIMATION_tag_o *v13;
  u64 v14;
  s64 v15;
  struct dds3BillAnim_tag_array *v16;
  struct P2A_ANIMATION_tag_o *v18;
  struct dds3BillAnim_tag_array *v19;
  struct P2A_ANIMATION_tag_o *v21;

  v3 = *hBillboard;
  if (*hBillboard)
  {
    type = v3->type;
    if (type == 3)
    {
LABEL_5:
      v3->mode = mode;
      return;
    }
    if (type != 1)
    {
      if (v3->type)
        return;
      goto LABEL_5;
    }
    pP2A = v3->pP2A;
    Anim_n = pP2A->Anim_n;
    if (Anim_n >= 1)
    {
      if (mode == 2)
      {
        v7 = 0;
        pAnim = pP2A->pAnim;
        if (!LODWORD(pAnim->max_length))
        {
LABEL_12:
        }
        while (1)
        {
          v10 = pAnim->m_Items[v7]->pAnim;
          v10->mode &= 0xFFFFFFF9;
          v11 = (*hBillboard)->pP2A->pAnim;
          v13 = v11->m_Items[v7]->pAnim;
          v13->mode |= 2u;
          if (Anim_n - 1 == v7)
            break;
          ++v7;
          pAnim = (*hBillboard)->pP2A->pAnim;
          if (v7 >= LODWORD(pAnim->max_length))
            goto LABEL_12;
        }
      }
      else
      {
        v14 = 0;
        v15 = Anim_n - 1;
        v16 = pP2A->pAnim;
        if (!LODWORD(v16->max_length))
        {
LABEL_20:
        }
        while (1)
        {
          v18 = v16->m_Items[v14]->pAnim;
          v18->mode &= 0xFFFFFFF9;
          if (mode == 3)
          {
            v19 = (*hBillboard)->pP2A->pAnim;
            v21 = v19->m_Items[v14]->pAnim;
            v21->mode |= 4u;
          }
          if (v15 == v14)
            break;
          ++v14;
          v16 = (*hBillboard)->pP2A->pAnim;
          if (v14 >= LODWORD(v16->max_length))
            goto LABEL_20;
        }
      }
    }
  }
}

// 0x131d610
void dds3BillboardSetPosition(billHandle_t **hBillboard, sdfVector4_t pPos) {
  if (*hBillboard)
    SDF_VU0__COPYVECTOR(&(*hBillboard)->pos, pPos, 0);
}

// 0x131d630
void dds3BillboardSetPositionO(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  UnityEngine_Vector4_o *v8;
  s64 v9;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  u64 v13[3];
  UnityEngine_Vector4_o v14;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  v8 = *hData;
  if (v8)
  {
    v9 = *&v8->x;
    if (*(*&v8->x + 288LL) < typeHierarchyDepth
      || *(*(v9 + 200) + 8 * typeHierarchyDepth - 8) != billHandle_t)
    {
      sub_8FC2C0(*(v9 + 64), billHandle_t, v13);
      if ((v13[0] & 1) != 0)
        v11 = v13[2];
      else
        v11 = v13 + 1;
      v12 = sub_8C4940(v11);
    }
    v14.x = x;
    v14.y = y;
    v14.z = z;
    v14.w = w;
    SDF_VU0__COPYVECTOR(v8 + 1, v14);
  }
}

// 0x131da70
void dds3BillboardSetRGBA(billHandle_t **hBillboard, u32 abgr) {
  if (*hBillboard)
    (*hBillboard)->abgr = abgr;
}

// 0x131da80
void dds3BillboardSetRGBAO(void **hData, u32 abgr) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  v5 = *hData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != billHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, billHandle_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
    HIDWORD(v5[3].klass) = abgr;
  }
}

// 0x131d790
void dds3BillboardSetRotate(billHandle_t **hBillboard, f32 rot) {
  if (*hBillboard)
    (*hBillboard)->rot = rot;
}

// 0x131d7a0
void dds3BillboardSetRotateO(void **hData, f32 rot) {
  f32 *v5;
  s64 v6;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  u64 v10[3];

  v5 = *hData;
  if (v5)
  {
    v6 = *v5;
    if (*(*v5 + 288LL) < typeHierarchyDepth
      || *(*(v6 + 200) + 8 * typeHierarchyDepth - 8) != billHandle_t)
    {
      sub_8FC2C0(*(v6 + 64), billHandle_t, v10);
      if ((v10[0] & 1) != 0)
        v8 = v10[2];
      else
        v8 = v10 + 1;
      v9 = sub_8C4940(v8);
    }
    v5[12] = rot;
  }
}

// 0x131d8c0
void dds3BillboardSetScale(billHandle_t **hBillboard, f32 x, f32 y) {
  if (*hBillboard)
  {
    sub_854930(&(*hBillboard)->scale, 0);
    sub_854930(&(*hBillboard)->scale, 1u);
  }
}

// 0x131d920
void dds3BillboardSetScaleO(void **hData, f32 x, f32 y) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  s64 v10;
  u64 v11[3];

  v5 = *hData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != billHandle_t)
    {
      sub_8FC2C0(klass->_1.element_class, billHandle_t, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
    v10 = &v5[2];
    sub_854930(v10, 0);
    sub_854930(v10, 1u);
  }
}

// 0x131e250
void dds3BillboardSetXYOffset(billHandle_t **hBillboard, f32 x, f32 y) {
  billHandle_t_o *v4;
  struct dds3BillResource_tag_o *hResource;

  v4 = *hBillboard;
  if (*hBillboard)
  {
    if (!v4->type)
    {
      hResource = v4->pNormal->hResource;
      hResource->width = x * 0.5;
      hResource->height = y * 0.5;
    }
  }
}

// 0x1317a90
void dds3BillboardTagLink(billHandle_t **hBillboard, dds3BillResource_tag **hResource, s32 use_mesh_idx) {
  dds3BillResource_tag_o *v7;
  billHandle_t_o *v8;
  s32 mode;
  f32 cx;
  f32 cy;
  f32 v12;
  f32 v13;
  f32 width;
  f32 v15;
  f32 v16;
  f32 height;
  f32 v18;
  f32 v19;
  billHandle_t_o *v20;
  struct XRD773Unity_CommonMesh_array *pMesh;
  f32 v22;
  f32 v23;
  s32 max_length;
  s64 v25;
  s32 UseOne;
  struct XRD773Unity_CommonMesh_array *v29;
  XRD773Unity_CommonMesh_o *v31;
  s32 UseIndexMax;
  struct XRD773Unity_CommonMesh_array *v33;
  s32 v34;
  s32 UseIndex;
  struct XRD773Unity_CommonMesh_array *v37;
  s32 v38;
  s32 v40;
  u32 TexNum;
  f32 v43;
  f32 v44;
  f32 v45;
  f32 v46;
  UnityEngine_GameObject_o *MainCamera;
  UnityEngine_Transform_o *transform;
  s64 v50;
  s64 v51;
  s64 v52;
  s64 v53;
  s64 v54;
  s64 v55;
  struct XRD773Unity_CommonMesh_array *v56;
  u32 v57;
  struct XRD773Unity_CommonMesh_array *v59;
  dds3BillResource_tag_o **v60;
  XRD773Unity_CommonMesh_o *v62;
  u64 v63;
  UnityEngine_Vector3_array *v64;
  struct XRD773Unity_CommonMesh_array *v65;
  XRD773Unity_CommonMesh_o *v67;
  System_Int32_array *v68;
  struct XRD773Unity_CommonMesh_array *v69;
  XRD773Unity_CommonMesh_o *v71;
  UnityEngine_Color_array *v72;
  struct XRD773Unity_CommonMesh_array *v73;
  XRD773Unity_CommonMesh_o *v75;
  UnityEngine_Vector2_array *v76;
  struct XRD773Unity_CommonMesh_array *v77;
  XRD773Unity_CommonMesh_o *v79;
  UnityEngine_GameObject_o *v80;
  UnityEngine_GameObject_o *v81;
  struct XRD773Unity_CommonMesh_array *v82;
  UnityEngine_GameObject_o *v84;
  UnityEngine_Transform_o *v86;
  struct XRD773Unity_CommonMesh_array *v87;
  UnityEngine_GameObject_o *v89;
  UnityEngine_Transform_o *v91;
  struct XRD773Unity_CommonMesh_array *v92;
  UnityEngine_Vector3_array *Position;
  struct XRD773Unity_CommonMesh_array *v95;
  UnityEngine_Vector3_array *v96;
  UnityEngine_Color_array *Color;
  f32 v101;
  f32 v102;
  f32 v103;
  struct XRD773Unity_CommonMesh_array *v106;
  XRD773Unity_CommonMesh_o *v108;
  s64 v109;
  s64 v110;
  s64 v111;
  s64 v112;
  s64 v113;
  s64 v114;
  s64 v115;
  f32 v117;
  f32 v118;
  f32 v119;
  f32 v120;
  s64 v122;
  s64 v123;
  s64 v124;
  s64 v125;
  s64 v126;
  s64 v127;
  s64 v128;
  f32 x;
  f32 y;
  f32 w;
  f32 v133;
  s64 v134;
  long f64 v135;
  f32 alf_raito;
  f32 v137;
  f32 v138;
  f32 v139;
  f32 bri_raito;
  f32 v141;
  f32 v142;
  long f64 v143;
  s32 v144;
  s32 v145;
  u32 *v147;
  s64 v148;
  long f64 v150;
  s32 v151;
  s32 v152;
  u32 *v154;
  s64 v155;
  long f64 v157;
  s32 v158;
  s32 v159;
  u32 *v161;
  s64 v162;
  long f64 v164;
  s32 v165;
  s32 v166;
  u32 *v168;
  struct XRD773Unity_CommonMesh_array *v170;
  System_Int32_array *IndexTable;
  s64 v174;
  s64 v176;
  s64 v177;
  s64 v179;
  s64 v181;
  s64 v183;
  struct UnityEngine_Texture_array *texture;
  s64 texId;
  il2cpp_array_size_t v188;
  UnityEngine_Object_o *v190;
  struct XRD773Unity_CommonMesh_array *v191;
  XRD773Unity_CommonMesh_o **v193;
  struct UnityEngine_Texture_array *v194;
  s64 v195;
  struct XRD773Unity_CommonMesh_array *v197;
  UnityEngine_Vector2_array *UvTable;
  struct UnityEngine_Vector2_array *uv;
  UnityEngine_Vector2_array *v201;
  struct UnityEngine_Vector2_array *v203;
  struct UnityEngine_Vector2_array *v205;
  il2cpp_array_size_t *p_max_length;
  s64 v208;
  u64 v211;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v215;
  struct XRD773Unity_CommonMesh_array *v217;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  System_String_o *v221;
  struct XRD773Unity_CommonMesh_array *v222;
  s64 v224;
  struct UnityEngine_Vector2_array *v228;
  u32 v229;
  struct XRD773Unity_CommonMesh_array *v231;
  XRD773Unity_CommonMesh_o *v233;
  UnityEngine_GameObject_o *v234;
  UnityEngine_GameObject_o *v235;
  long f64 v239;
  long f64 v240;
  long f64 v241;
  f32 v242;
  f32 v243;
  f32 v244;
  f32 v245;
  f32 v246;
  f32 v247;
  f32 z;
  s64 v249;
  dds3BillResource_tag_o **v250;
  dds3BillResource_tag_o **v251;
  f32 v;
  s32 v253;
  u32 v254;
  f32 v255;
  f32 v256;
  UnityEngine_Matrix4x4_o v257;
  UnityEngine_Matrix4x4_o v258;
  UnityEngine_Matrix4x4_o v259;
  UnityEngine_Matrix4x4_o v260;
  UnityEngine_Matrix4x4_o v261;
  UnityEngine_Matrix4x4_o v262;
  UnityEngine_Matrix4x4_o v263;
  UnityEngine_Quaternion_o v264;
  UnityEngine_Matrix4x4_o v265;
  UnityEngine_Matrix4x4_o v266;
  UnityEngine_Quaternion_o rotation;
  UnityEngine_Vector4_o v268;
  UnityEngine_Color_o v269;
  UnityEngine_Color_o v270;
  UnityEngine_Color_o v271;
  UnityEngine_Color_o v272;
  UnityEngine_Vector3_o zero;
  UnityEngine_Vector3_o v274;
  UnityEngine_Vector3_o v275;
  UnityEngine_Vector4_o v276;
  UnityEngine_Vector4_o v277;
  UnityEngine_Vector4_o v278;
  UnityEngine_Vector4_o v279;
  UnityEngine_Vector4_o v280;
  UnityEngine_Quaternion_o identity;
  UnityEngine_Color_o BlendColor;

  memset(&v266, 0, sizeof(v266));
  v7 = *hResource;
  v8 = *hBillboard;
  mode = (*hBillboard)->mode;
  if ((*hResource)->current_mode != mode)
  {
    if (v7->number >= 1)
    {
      v7->number = 0;
      LOWORD(mode) = (*hBillboard)->mode;
      v7 = *hResource;
    }
    v7->current_mode = mode;
    v7 = *hResource;
    v8 = *hBillboard;
  }
  cx = v7->cx;
  sub_854710(&v8->scale, 0);
  cy = (*hResource)->cy;
  v13 = v12;
  sub_854710(&(*hBillboard)->scale, 1u);
  width = (*hResource)->width;
  v16 = v15;
  sub_854710(&(*hBillboard)->scale, 0);
  height = (*hResource)->height;
  v19 = v18;
  sub_854710(&(*hBillboard)->scale, 1u);
  v20 = *hBillboard;
  pMesh = (*hBillboard)->pMesh;
  v23 = v22;
  if (pMesh)
  {
    max_length = pMesh->max_length;
    if (max_length <= use_mesh_idx)
    {
LABEL_171:
      ++(*hResource)->number;
      return;
    }
  }
  else
  {
    if (v20->texture)
      v40 = v20->mode + 4;
    else
      v40 = v20->mode;
    v253 = use_mesh_idx;
    if (v20->type == 1)
      TexNum = v20->pP2A->hResource->TexNum;
    else
      TexNum = 1;
    v20->pMesh = NewSpecific(XRD773Unity_CommonMesh, TexNum);
    pMesh = (*hBillboard)->pMesh;
    p_max_length = &pMesh->max_length;
    max_length = pMesh->max_length;
    if (max_length >= 1)
    {
      v251 = hResource;
      v208 = 4;
      do
      {
        {
        }
        v211 = v208 - 4;
        Instance = get_Instance();
        Mesh = GetMesh(Instance, v40, 0);
        v215 = Mesh;
        *(&pMesh->obj.klass + v208) = v215;
        v217 = (*hBillboard)->pMesh;
        gameObject = get_gameObject(*(&v217->obj.klass + v208), 0);
        name = get_name(gameObject);
        v221 = Concat_5224608(name, ":dds3BillBoardDraw:0");
        set_name(gameObject, v221);
        v222 = (*hBillboard)->pMesh;
        *(*(&v222->obj.klass + v208) + 32LL) = 257;
        pMesh = (*hBillboard)->pMesh;
        p_max_length = &pMesh->max_length;
        max_length = pMesh->max_length;
        v224 = v208 - 3;
        ++v208;
      }
      while (v224 < max_length);
      hResource = v251;
    }
    use_mesh_idx = v253;
    if (max_length <= v253)
      goto LABEL_171;
  }
  v25 = use_mesh_idx;
  UseOne = GetUseOne(pMesh->m_Items[use_mesh_idx]);
  v29 = (*hBillboard)->pMesh;
  v31 = v29->m_Items[use_mesh_idx];
  v245 = v19;
  v247 = width;
  v242 = v23;
  v243 = height;
  if (!UseOne)
  {
    else
    {
      v43 = v16;
      v44 = cy;
      v45 = cx;
      v46 = v13;
    }
    MainCamera = GetMainCamera(kernelObject);
    transform = get_transform(MainCamera, 0);
    rotation = get_rotation(transform);
    Rotate(&v265, rotation, 0);
    v50 = *&v265.m20;
    v51 = *&v265.m00;
    v13 = v46;
    cx = v45;
    cy = v44;
    v52 = *&v265.m01;
    *&v31->mat.m21 = *&v265.m21;
    *&v31->mat.m01 = v52;
    *&v31->mat.m20 = v50;
    *&v31->mat.m00 = v51;
    v53 = *&v265.m22;
    v54 = *&v265.m02;
    v16 = v43;
    v38 = 0;
    v55 = *&v265.m03;
    *&v31->mat.m23 = *&v265.m23;
    *&v31->mat.m03 = v55;
    *&v31->mat.m22 = v53;
    *&v31->mat.m02 = v54;
    v34 = 1;
    goto LABEL_32;
  }
  UseIndexMax = GetUseIndexMax(v31);
  v33 = (*hBillboard)->pMesh;
  v34 = UseIndexMax;
  UseIndex = GetUseIndex(v33->m_Items[use_mesh_idx]);
  if (UseIndex < v34)
  {
    v37 = (*hBillboard)->pMesh;
    v38 = UseIndex;
    SetUseIndex(v37->m_Items[use_mesh_idx], UseIndex + 1);
LABEL_32:
    v56 = (*hBillboard)->pMesh;
    v57 = 4 * v34;
    if (v57 > SLODWORD(GetPosition(v56->m_Items[use_mesh_idx])->max_length))
    {
      v59 = (*hBillboard)->pMesh;
      v60 = hResource;
      v62 = v59->m_Items[use_mesh_idx];
      v63 = v57;
      v64 = NewSpecific(UnityEngine_Vector3, v57);
      SetPosition_20241056(v62, v64);
      v65 = (*hBillboard)->pMesh;
      v67 = v65->m_Items[use_mesh_idx];
      v68 = NewSpecific(s32, (6 * v34));
      SetIndexTable(v67, v68);
      v69 = (*hBillboard)->pMesh;
      v71 = v69->m_Items[use_mesh_idx];
      v72 = NewSpecific(UnityEngine_Color, v63);
      SetColor_20241296(v71, v72);
      v73 = (*hBillboard)->pMesh;
      v75 = v73->m_Items[use_mesh_idx];
      v76 = NewSpecific(UnityEngine_Vector2, v63);
      SetUvTable_20243232(v75, v76);
      v77 = (*hBillboard)->pMesh;
      v79 = v77->m_Items[use_mesh_idx];
      v80 = get_gameObject(v79);
      hResource = v60;
      if (!get_activeSelf(v80))
      {
        v81 = get_gameObject(v79);
        SetActive(v81, 1, 0);
      }
      v79->hide = 0;
      v82 = (*hBillboard)->pMesh;
      v84 = get_gameObject(v82->m_Items[use_mesh_idx]);
      v86 = get_transform(v84, 0);
      zero = get_zero();
      set_position(v86, zero);
      v87 = (*hBillboard)->pMesh;
      v89 = get_gameObject(v87->m_Items[use_mesh_idx]);
      v91 = get_transform(v89, 0);
      {
      }
      identity = get_identity(0);
      set_rotation(v91, identity);
    }
    v92 = (*hBillboard)->pMesh;
    v250 = hResource;
    Position = GetPosition(v92->m_Items[use_mesh_idx]);
    v95 = (*hBillboard)->pMesh;
    v96 = Position;
    Color = GetColor(v95->m_Items[use_mesh_idx], 0);
    z = get_zero().z;
    v101 = (*hBillboard)->rot * 0.5;
    v102 = sdfSin(v101);
    v103 = sdfCos(v101);
    *&v264.x = 0;
    *&v264.z = 0;
    sub_1A1BDD0(&v264.x, 0.0, 0.0, v102, v103);
    Rotate(&v265, v264, 0);
    v266 = v265;
    v106 = (*hBillboard)->pMesh;
    v108 = v106->m_Items[use_mesh_idx];
    v109 = *&v108->mat.m00;
    v110 = *&v108->mat.m20;
    v111 = *&v108->mat.m21;
    *&v263.m01 = *&v108->mat.m01;
    *&v263.m21 = v111;
    *&v263.m00 = v109;
    *&v263.m20 = v110;
    v112 = *&v108->mat.m02;
    v113 = *&v108->mat.m22;
    v114 = *&v108->mat.m03;
    v115 = *&v108->mat.m23;
    *&v263.m03 = v114;
    *&v263.m23 = v115;
    *&v263.m02 = v112;
    *&v263.m22 = v113;
    else
    {
      v117 = v16;
      v118 = cy;
      v119 = cx;
      v120 = v13;
    }
    v122 = *&mod_p_matrix.m20;
    v123 = *&mod_p_matrix.m01;
    v124 = *&mod_p_matrix.m21;
    *&v260.m00 = *&mod_p_matrix.m00;
    *&v260.m20 = v122;
    *&v260.m01 = v123;
    *&v260.m21 = v124;
    v125 = *&mod_p_matrix.m02;
    v126 = *&mod_p_matrix.m22;
    v128 = *&mod_p_matrix.m03;
    v127 = *&mod_p_matrix.m23;
    v261 = v263;
    *&v260.m03 = v128;
    *&v260.m23 = v127;
    *&v260.m02 = v125;
    *&v260.m22 = v126;
    op_Multiply(&v262, &v261, &v260, 0);
    v257 = v266;
    v258 = v262;
    op_Multiply(&v259, &v258, &v257, 0);
    v266 = v259;
    x = (*hBillboard)->pos.x;
    y = (*hBillboard)->pos.y;
    v133 = (*hBillboard)->pos.z;
    w = (*hBillboard)->pos.w;
    v276.x = x;
    v276.y = y;
    v276.z = v133;
    v276.w = w;
    v134 = 4LL * v38;
    v274 = op_Implicit_8738992(v276);
    v275 = Scale(v274, mod_pos);
    op_Implicit(v275, 0);
    sub_1A009D0(&v266, 3);
    BlendColor = effGetBlendColor((*hBillboard)->abgr, 0);
    v268 = op_Implicit(BlendColor, 0);
    v255 = v268.x;
    v256 = v268.w;
    alf_raito = (*hBillboard)->alf_raito;
    v137 = v268.z;
    v = v268.y;
    if (alf_raito != 0.0)
    {
      v256 = v268.w * alf_raito;
      if ((v268.w * alf_raito) > 1.0)
        v256 = 1.0;
    }
    v138 = v119 * v120;
    v139 = v247 * v245;
    *&v135 = v243 * v242;
    bri_raito = (*hBillboard)->bri_raito;
    v141 = v118 * v117;
    if (bri_raito != 0.0)
    {
      v255 = v268.x * bri_raito;
      v137 = v268.z * bri_raito;
      v = v268.y * bri_raito;
    }
    v142 = v141 - *&v135;
    v244 = v243 * v242;
    v246 = v141;
    v254 = use_mesh_idx;
    v143 = sub_1A00CF0(&v266.m00, v138 - v139, v141 - *&v135, z, v135);
    v147 = (v96 + 48 * v38);
    v147[8] = LODWORD(v143);
    v147[9] = v144;
    v147[10] = v145;
    v277.x = v255;
    v277.w = v256;
    v277.y = v;
    v277.z = v137;
    v148 = v134 | 1LL;
    v269 = op_Implicit_27186336(v277);
    *&v239 = v269.a;
    Color->m_Items[4 * v38] = v269;
    v150 = sub_1A00CF0(&v266.m00, v138 + v139, v142, z, v239);
    v154 = (v96 + 12 * v148);
    v154[8] = LODWORD(v150);
    v154[9] = v151;
    v154[10] = v152;
    v278.x = v255;
    v278.w = v256;
    v155 = v148 + 1LL;
    v278.y = v;
    v278.z = v137;
    v270 = op_Implicit_27186336(v278);
    *&v240 = v270.a;
    Color->m_Items[v148] = v270;
    v157 = sub_1A00CF0(&v266.m00, v138 + v139, v246 + v244, z, v240);
    v161 = (v96 + 12 * v155);
    v161[8] = LODWORD(v157);
    v161[9] = v158;
    v161[10] = v159;
    v279.x = v255;
    v279.w = v256;
    v279.y = v;
    v279.z = v137;
    v162 = v134 | 3LL;
    v271 = op_Implicit_27186336(v279);
    *&v241 = v271.a;
    Color->m_Items[v155] = v271;
    v164 = sub_1A00CF0(&v266.m00, v138 - v139, v246 + v244, z, v241);
    v168 = (v96 + 12 * v162);
    v249 = v148 + 1LL;
    v168[8] = LODWORD(v164);
    v168[9] = v165;
    v168[10] = v166;
    v280.y = v;
    v280.x = v255;
    v280.w = v256;
    v280.z = v137;
    v272 = op_Implicit_27186336(v280);
    Color->m_Items[v162] = v272;
    v170 = (*hBillboard)->pMesh;
    IndexTable = GetIndexTable(v170->m_Items[v25]);
    v174 = (6 * v38) | 1LL;
    v176 = v174;
    v177 = v174 + 1LL;
    IndexTable->m_Items[6 * v38] = v134;
    IndexTable->m_Items[v174] = v148;
    v179 = v174 + 2LL;
    IndexTable->m_Items[v177] = v162;
    v181 = v174 + 3LL;
    IndexTable->m_Items[v179] = v148;
    v183 = v176 + 4;
    IndexTable->m_Items[v181] = v134 | 2;
    hResource = v250;
    IndexTable->m_Items[v183] = v162;
    texture = (*hBillboard)->texture;
    if (texture)
    {
      texId = (*v250)->hTex->texId;
      v188 = texture->max_length;
      if (texId < v188)
      {
        v190 = texture->m_Items[texId];
        if (op_Inequality(v190, 0, 0))
        {
          v191 = (*hBillboard)->pMesh;
          v193 = (&v191->obj.klass + v25);
          v194 = (*hBillboard)->texture;
          v195 = (*v250)->hTex->texId;
          SetMatTexture(v193[4], v194->m_Items[v195]);
          v197 = (*hBillboard)->pMesh;
          UvTable = GetUvTable(v197->m_Items[v25]);
          uv = (*v250)->uv;
          v201 = UvTable;
          sub_851A70(&UvTable->m_Items[v134], uv->m_Items[0].x, (*v250)->uv->m_Items[0].y);
          v203 = (*v250)->uv;
          sub_851A70(&v201->m_Items[v148], v203->m_Items[1].x, (*v250)->uv->m_Items[0].y);
          v205 = (*v250)->uv;
          sub_851A70(&v201->m_Items[v249], v205->m_Items[1].x, v205->m_Items[1].y);
          v228 = (*v250)->uv;
          v229 = v228->max_length;
          sub_851A70(&v201->m_Items[v162], v228->m_Items[0].x, (*v250)->uv->m_Items[1].y);
        }
      }
    }
    v231 = (*hBillboard)->pMesh;
    v233 = v231->m_Items[v25];
    v234 = get_gameObject(v233);
    if (!get_activeSelf(v234))
    {
      v235 = get_gameObject(v233);
      SetActive(v235, 1, 0);
    }
    v233->hide = 0;
    goto LABEL_171;
  }
}

// 0x131aab0
void dds3Billboard_BasicInit(billHandle_t **pBasic) {
  billHandle_t_Fields *p_fields;
  struct UnityEngine_Vector4_o *p_scale;

  p_fields = &(*pBasic)->fields;
  sub_854930(p_fields, 3u);
  sub_854930(p_fields, 2u);
  sub_854930(p_fields, 1u);
  sub_854930(p_fields, 0);
  p_scale = &(*pBasic)->scale;
  sub_854930(p_scale, 2u);
  sub_854930(p_scale, 1u);
  sub_854930(p_scale, 0);
  sub_854930(&(*pBasic)->scale, 3u);
  (*pBasic)->rot = 0.0;
  (*pBasic)->abgr = -2139062144;
  (*pBasic)->mode = 0;
}

// 0x131abb0
billHandle_t *dds3Billboard_NormalCreate(void *pTex, s32 bPos, bool pCopy, s32 billno) {
  billHandle_t_o *v7;
  dds3Billboard_Normal_tag3_o *v8;
  UnityEngine_Texture_c *v10;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v13;
  s64 *v14;
  u64 *v15;
  u64 *v16;
  u64 v20[3];

  v7 = Allocate(billHandle_t);
  billHandle_t___ctor(v7);
  v8 = Allocate(dds3Billboard_Normal_tag3);
  dds3Billboard_Normal_tag3___ctor(v8);
  if (pTex)
  {
    if (bPos == -1)
    {
      klass = pTex->klass;
      if (pTex->klass->_2.typeHierarchyDepth < typeHierarchyDepth
        || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_Texture)
      {
        sub_8FC2C0(klass->_1.element_class, UnityEngine_Texture, v20);
        if ((v20[0] & 1) != 0)
          v13 = v20[2];
        else
          v13 = v20 + 1;
        v14 = sub_8C4940(v13);
      }
    }
    else
    {
      pTex = billGetTexture(0);
    }
    v8->hResource = BillboardLoadTex(pTex, v10);
    v15 = NewSpecific(UnityEngine_Texture, 1u);
    v16 = v15;
    v16[4] = pTex;
    v7->texture = v16;
  }
  v8->basic = v7;
  v7->pNormal = v8;
  return v7;
}

// 0x131af00
void dds3Billboard_NormalDelete(void **hData) {

}

// 0x131af40
void dds3Billboard_NormalDraw(void **hData) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  billHandle_t_o **v9;
  dds3BillResource_tag_o **p_monitor;
  u64 v11[3];

  v4 = *hData;
  if (*hData)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Billboard_Normal_tag3)
    {
      sub_8FC2C0(klass->_1.element_class, dds3Billboard_Normal_tag3, v11);
      if ((v11[0] & 1) != 0)
        v7 = v11[2];
      else
        v7 = v11 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v9 = &v4[1];
  p_monitor = &v4[1].monitor;
  dds3BillboardTagLink(v9, p_monitor, 0);
}

// 0x131c340
dds3BillResource_tag *dds3Billboard_P2AAnimDraw(dds3Billboard_P2A_tag3 **pP2A, dds3BillAnim_tag **pBillAnim) {
  u64 *v5;
  int16x4_t v6;
  int16x4_t v7;
  struct dds3BillAnimResource_tag_o *hResource;
  dds3BillAnim_tag_o *v9;
  s32 wait;
  struct P2A_ANIMATION_tag_o *pAnim;
  struct P2A_TEXANIM_tag_array *pTexAnim;
  s64 key;
  struct P2A_TEXANIM_tag_array *v15;
  s64 v16;
  P2A_TEXANIM_tag_o *v18;
  u32 v19;
  struct System_UInt32_array_array *pABGRTable;
  s64 alpha;
  System_UInt32_array *v23;
  s64 v24;
  struct dds3BillResource_tag_array *pResList;
  dds3BillResource_tag_o *v28;
  u32 mode;
  struct billHandle_t_o *basic;
  s16 v31;
  struct sdfTexHandle_t_o *hTex;
  f32 v33;
  f32 v34;
  struct UnityEngine_Vector2_array *v35;
  int16x4_t v36;
  int16x4_t v37;
  struct UnityEngine_Vector2_array *v38;
  int16x4_t v39;
  int16x4_t v40;
  f32 v41;
  int16x4_t v43;
  int16x4_t v44;
  int16x4_t v45;
  int16x4_t v46;
  f32 v47;
  f32 v49;
  f32 v50;
  s64 v52;
  s64 v53;

  v5 = Allocate(dds3BillResource_tag);
  dds3BillResource_tag___ctor(v5);
  hResource = (*pP2A)->hResource;
  v9 = *pBillAnim;
  wait = (*pBillAnim)->wait;
  pAnim = (*pBillAnim)->pAnim;
  if (wait <= 0)
  {
    ++v9->key;
    if ((*pBillAnim)->key >= pAnim->times)
    {
      if ((pAnim->mode & 0x10) != 0)
      {
        (*pP2A)->state = 0;
        (*pBillAnim)->key = pAnim->times - 1;
      }
      else
      {
        (*pBillAnim)->key = 0;
      }
    }
    pTexAnim = (*pBillAnim)->pTexAnim;
    key = (*pBillAnim)->key;
    (*pBillAnim)->wait = pTexAnim->m_Items[key]->attr;
  }
  else
  {
    v9->wait = wait - 1;
  }
  v15 = (*pBillAnim)->pTexAnim;
  v16 = (*pBillAnim)->key;
  v18 = v15->m_Items[v16];
  if ((pAnim->mode & 1) != 0)
  {
    pABGRTable = hResource->pABGRTable;
    alpha = pAnim->alpha;
    v23 = pABGRTable->m_Items[alpha];
    v24 = (*pBillAnim)->key;
    v19 = v23->m_Items[v24];
  }
  else
  {
    v19 = -2139062144;
  }
  (*pP2A)->basic->abgr = v19;
  pResList = hResource->pResList;
  v28 = pResList->m_Items[v18->texid];
  mode = pAnim->mode;
  if ((mode & 2) != 0)
  {
    basic = (*pP2A)->basic;
    v31 = 2;
  }
  else
  {
    basic = (*pP2A)->basic;
    if ((mode & 4) != 0)
      v31 = 3;
    else
      v31 = 1;
  }
  basic->mode = v31;
  hTex = v28->hTex;
  v6.n64_u16[0] = hTex->width;
  v7.n64_u16[0] = hTex->height;
  v33 = 1.0 / (vmovl_s16(v6).n128_i32[0] * 16.0);
  v34 = 1.0 / (vmovl_s16(v7).n128_i32[0] * 16.0);
  v35 = NewSpecific(UnityEngine_Vector2, 2u);
  v36.n64_u16[0] = v18->v1;
  v37.n64_u16[0] = v18->u1;
  v53 = 0;
  v38 = v35;
  sub_851710(&v53, v33 * vmovl_s16(v37).n128_i32[0], 1.0 - (v34 * vmovl_s16(v36).n128_i32[0]));
  v41 = *(&v53 + 1);
  LODWORD(v38->m_Items[0].x) = v53;
  v38->m_Items[0].y = v41;
  v40.n64_u16[0] = v18->v2;
  v39.n64_u16[0] = v18->u2;
  v52 = 0;
  sub_851710(&v52, v33 * vmovl_s16(v39).n128_i32[0], 1.0 - (v34 * vmovl_s16(v40).n128_i32[0]));
  v47 = *(&v52 + 1);
  LODWORD(v38->m_Items[1].x) = v52;
  v38->m_Items[1].y = v47;
  v28->uv = v38;
  (*pP2A)->basic->rot = v18->angle;
  v44.n64_u16[0] = v18->sx;
  v45.n64_u16[0] = v18->sy;
  v43.n64_u16[0] = v18->cy;
  v46.n64_u16[0] = v18->cx;
  v49 = vmovl_s16(v44).n128_i32[0] * 0.5;
  v50 = vmovl_s16(v45).n128_i32[0] * 0.5;
  v28->cx = v49 - vmovl_s16(v46).n128_i32[0];
  v28->cy = v50 - vmovl_s16(v43).n128_i32[0];
  v28->width = v49;
  v28->height = v50;
  return v28;
}

// 0x131c6e0
u32 dds3Billboard_P2AColorMul(u32 color0, u32 color1) {
  return effColorMultiply(color0, color1);
}

// 0x131c020
billHandle_t *dds3Billboard_P2ACopy(dds3Billboard_P2A_tag3 *pCopyP2A) {
  billHandle_t_o *v3;
  dds3Billboard_P2A_tag3_o *v4;
  struct dds3BillAnimResource_tag_o *hResource;
  struct dds3BillAnim_tag_array *v6;
  u32 *pAnim;
  u64 v8;
  u64 *v9;
  u32 *v11;
  dds3MultiBillResource_tag_o *v13;
  struct dds3MultiBillResource_tag_o *MultiBillRes;
  struct dds3MultiBillResource_tag_o *v15;
  dds3Billboard_P2A_tag3_o *pP2A;

  v3 = Allocate(billHandle_t);
  billHandle_t___ctor(v3);
  v4 = Allocate(dds3Billboard_P2A_tag3);
  dds3Billboard_P2A_tag3___ctor(v4);
  pP2A = v4;
  hResource = pCopyP2A->hResource;
  ++hResource->count;
  v4->hResource = hResource;
  v6 = NewSpecific(dds3BillAnim_tag, hResource->AnimNum);
  v4->pAnim = v6;
  if (hResource->AnimNum)
  {
    pAnim = v6;
    v8 = 0;
    while (1)
    {
      v9 = Allocate(dds3BillAnim_tag);
      dds3BillAnim_tag___ctor(v9);
      v11 = &pAnim[2 * v8++];
      *(v11 + 4) = v9;
      if (v8 >= hResource->AnimNum)
        break;
      pAnim = v4->pAnim;
    }
  }
  v13 = Allocate(dds3MultiBillResource_tag);
  dds3MultiBillResource_tag___ctor(v13);
  v4->MultiBillRes = v13;
  v13->next = 0;
  MultiBillRes = v4->MultiBillRes;
  MultiBillRes->hBillRes = NewSpecific(dds3BillResource_tag, 2u);
  v15 = v4->MultiBillRes;
  v15->abgr = NewSpecific(uint, 2u);
  v4->state = 1;
  dds3Billboard_P2ASetNumber(&pP2A, 0);
  v3->pP2A = v4;
  v4->basic = v3;
  return v3;
}

// 0x131bdb0
billHandle_t *dds3Billboard_P2ACreate(void *pTex, s32 bPos, bool pCopy, s32 billno) {
  billHandle_t_o *v6;
  dds3Billboard_P2A_tag3_o *v7;
  dds3BillAnimResource_tag_o *v11;
  dds3BillAnimResource_tag_o *v12;
  struct dds3BillAnim_tag_array *v13;
  u32 *pAnim;
  u64 v16;
  u64 *v17;
  u32 *v19;
  dds3MultiBillResource_tag_o *v22;
  struct dds3MultiBillResource_tag_o *MultiBillRes;
  struct dds3MultiBillResource_tag_o *v24;
  dds3Billboard_P2A_tag3_o *v28;
  s32 bPosa;

  bPosa = bPos;
  v6 = Allocate(billHandle_t);
  billHandle_t___ctor(v6);
  v7 = Allocate(dds3Billboard_P2A_tag3);
  dds3Billboard_P2A_tag3___ctor(v7);
  v28 = v7;
  if (pTex)
  {
    v11 = dds3BillAnimLoadP2A(pTex, &bPosa, pBillTexture);
    v7->hResource = v11;
    v12 = v11;
    v13 = NewSpecific(dds3BillAnim_tag, v11->AnimNum);
    v7->pAnim = v13;
    if (v12->AnimNum)
    {
      pAnim = v13;
      v16 = 0;
      while (1)
      {
        v17 = Allocate(dds3BillAnim_tag);
        dds3BillAnim_tag___ctor(v17);
        v19 = &pAnim[2 * v16++];
        *(v19 + 4) = v17;
        if (v16 >= v12->AnimNum)
          break;
        pAnim = v7->pAnim;
      }
    }
    v6->texture = pBillTexture;
  }
  v22 = Allocate(dds3MultiBillResource_tag);
  dds3MultiBillResource_tag___ctor(v22);
  v7->MultiBillRes = v22;
  v22->next = 0;
  v7->MultiBillRes->type = 0;
  MultiBillRes = v7->MultiBillRes;
  MultiBillRes->hBillRes = NewSpecific(dds3BillResource_tag, 2u);
  v24 = v7->MultiBillRes;
  v24->abgr = NewSpecific(uint, 2u);
  v7->state = 1;
  dds3Billboard_P2ASetNumber(&v28, 0);
  v6->pP2A = v7;
  v7->basic = v6;
  return v6;
}

// 0x131c220
void dds3Billboard_P2ADelete(void **hData) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v5;
  s64 *v6;
  u64 v7[3];

  if (*hData)
  {
    klass = (*hData)->klass;
    if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3Billboard_P2A_tag3)
    {
      sub_8FC2C0(klass->_1.element_class, dds3Billboard_P2A_tag3, v7);
      if ((v7[0] & 1) != 0)
        v5 = v7[2];
      else
        v5 = v7 + 1;
      v6 = sub_8C4940(v5);
    }
  }
}

// 0x131c6f0
void dds3Billboard_P2ADraw(void **hData) {
  u32 *v4;
  s64 v5;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  u32 v9;
  s64 v10;
  u32 v11;
  f32 v12;
  struct dds3BillAnim_tag_array *pAnim;
  struct billHandle_t_o *v15;
  dds3Billboard_P2A_tag3_Fields *v17;
  s32 v18;
  s64 v19;
  s64 v20;
  s64 v21;
  s64 v23;
  s64 v24;
  s64 v25;
  s64 v27;
  s64 v28;
  s64 v29;
  u64 v30;
  s64 v31;
  s64 v33;
  s64 v34;
  dds3BillResource_tag_o *v36;
  int16x4_t v37;
  f32 cx;
  f32 cy;
  dds3BillResource_tag_o *v40;
  struct billHandle_t_o *basic;
  u32 abgr;
  dds3Billboard_P2A_tag3_Fields *p_fields;
  s64 v48;
  s64 v49;
  struct billHandle_t_o *v51;
  dds3Billboard_P2A_tag3_Fields *v52;
  struct billHandle_t_o *v55;
  dds3BillResource_tag_o *v56;
  dds3Billboard_P2A_tag3_o *v57[3];
  dds3Billboard_P2A_tag3_o *pP2A;

  pP2A = 0;
  v56 = 0;
  v4 = *hData;
  if (*hData)
  {
    v5 = *v4;
    if (*(*v4 + 288LL) < typeHierarchyDepth
      || *(*(v5 + 200) + 8 * typeHierarchyDepth - 8) != dds3Billboard_P2A_tag3)
    {
      sub_8FC2C0(*(v5 + 64), dds3Billboard_P2A_tag3, v57);
      if ((v57[0] & 1) != 0)
        v7 = v57[2];
      else
        v7 = v57 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  pP2A = *hData;
  v56 = 0;
  if (*(v4 + 20))
  {
    v9 = v4[11];
    if ((v9 & 0x10000000) != 0)
    {
      v19 = *(v4 + 3);
      v20 = *(v19 + 32);
      v21 = v4[12];
      v23 = v20 + 8 * v21;
      v24 = *(v19 + 64);
      v25 = *(*(v23 + 32) + 16LL);
      v27 = *(v4 + 2);
      v12 = *(v27 + 48);
      v11 = *(v27 + 52);
      if (v4[13])
      {
        v28 = 32;
        v29 = *(v24 + 8 * v25 + 32);
        v30 = 0;
        do
        {
          v31 = *(v4 + 7);
          v33 = *(v31 + v28);
          v34 = *(v4 + 7);
          if ((*(v33 + 24) & 0x80000000) != 0)
          {
            ++*(*(v34 + v28) + 24LL);
          }
          else
          {
            else if (v30 >= *(v34 + 24))
            {
LABEL_34:
            }
            v36 = dds3Billboard_P2AAnimDraw(&pP2A, (v34 + v28));
            v56 = v36;
            if (v36)
            {
              cx = v36->cx;
              cy = v36->cy;
              v40 = v36;
              v37.n64_u16[0] = *(*(v29 + v28) + 20LL);
              v36->cx = vmovl_s16(v37).n128_i32[0];
              v36->cy = -*(*(v29 + v28) + 22LL);
              basic = pP2A->basic;
              abgr = basic->abgr;
              basic->abgr = effColorMultiply(v11, abgr);
              p_fields = &pP2A->fields;
              pP2A->basic->rot = v12 + pP2A->basic->rot;
              dds3BillboardTagLink(&p_fields->basic, &v56, 0);
              v40->cx = cx;
              v40->cy = cy;
            }
          }
          v4 = pP2A;
          ++v30;
          v28 += 8;
        }
        while (v30 < pP2A->Anim_n);
      }
      goto LABEL_63;
    }
    if ((v9 & 0x40) != 0)
    {
      v48 = *(v4 + 2);
      v11 = *(v48 + 52);
      v12 = *(v48 + 48);
      v49 = *(v4 + 7);
      v56 = dds3Billboard_P2AAnimDraw(&pP2A, (v49 + 32));
      v51 = pP2A->basic;
      v51->abgr = effColorMultiply(v11, v51->abgr);
      v52 = &pP2A->fields;
      pP2A->basic->rot = v12 + pP2A->basic->rot;
      dds3BillboardTagLink(&v52->basic, &v56, 0);
      pAnim = pP2A->pAnim;
      if (LODWORD(pAnim->max_length) <= 1)
        goto LABEL_60;
    }
    else
    {
      v10 = *(v4 + 2);
      v11 = *(v10 + 52);
      v12 = *(v10 + 48);
      pAnim = *(v4 + 7);
      if ((v9 & 0x80) == 0)
      {
        v56 = dds3Billboard_P2AAnimDraw(&pP2A, pAnim->m_Items);
        v15 = pP2A->basic;
        v15->abgr = effColorMultiply(v11, v15->abgr);
        v17 = &pP2A->fields;
        v18 = 0;
        pP2A->basic->rot = v12 + pP2A->basic->rot;
        goto LABEL_62;
      }
      if (LODWORD(pAnim->max_length) <= 1)
      {
LABEL_60:
      }
    }
    v56 = dds3Billboard_P2AAnimDraw(&pP2A, &pAnim->m_Items[1]);
    v55 = pP2A->basic;
    v55->abgr = effColorMultiply(v11, v55->abgr);
    v17 = &pP2A->fields;
    pP2A->basic->rot = v12 + pP2A->basic->rot;
    v18 = 1;
LABEL_62:
    dds3BillboardTagLink(&v17->basic, &v56, v18);
    v4 = pP2A;
LABEL_63:
    *(*(v4 + 2) + 48LL) = v12;
    *(*(v4 + 2) + 52LL) = v11;
  }
}

// 0x131bce0
void dds3Billboard_P2ASetAnim(dds3BillAnimResource_tag **hBillAnimRes, s32 number, dds3BillAnim_tag **pBillAnim) {
  struct P2A_ANIMATION_tag_array *pAnimTable;
  Il2CppClass **v6;
  struct P2A_TEXANIM_tag_array_array *pTexAnimTable;
  struct P2A_ANIMATION_tag_o *v8;
  s64 spranm;
  P2A_TEXANIM_tag_array *v11;

  pAnimTable = (*hBillAnimRes)->pAnimTable;
  v6 = &pAnimTable->obj.klass + number;
  pTexAnimTable = (*hBillAnimRes)->pTexAnimTable;
  v8 = v6[4];
  spranm = v8->spranm;
  v11 = pTexAnimTable->m_Items[spranm];
  (*pBillAnim)->key = 0;
  (*pBillAnim)->wait = v11->m_Items[0]->attr;
  (*pBillAnim)->pAnim = v8;
  (*pBillAnim)->pTexAnim = v11;
}

// 0x131b8f0
void dds3Billboard_P2ASetNumber(dds3Billboard_P2A_tag3 **pP2A, s32 number) {
  struct dds3BillAnimResource_tag_o *hResource;
  struct P2A_ANIMATION_tag_array *pAnimTable;
  P2A_ANIMATION_tag_o *v9;
  u32 times;
  struct dds3BillAnim_tag_array *v13;
  struct dds3BillAnim_tag_array *v16;
  s32 v17;
  struct P2A_TEXANIM_tag_array_array *pTexAnimTable;
  s64 spranm;
  P2A_TEXANIM_tag_array *v24;
  u64 v25;
  s64 v27;
  s64 v28;
  s64 v29;
  s32 v30;
  struct dds3BillAnim_tag_array *pAnim;
  struct dds3BillAnim_tag_array *v33;
  dds3BillAnim_tag_o *v35;
  struct dds3BillAnim_tag_array *v37;
  dds3BillAnimResource_tag_o *hBillAnimRes;

  hResource = (*pP2A)->hResource;
  hBillAnimRes = hResource;
  pAnimTable = hResource->pAnimTable;
  v9 = pAnimTable->m_Items[number];
  times = v9->times;
  if (times)
  {
    if ((v9->mode & 0x10000000) != 0)
    {
      Write("billAnim..PLURAL SET\n", 0);
      (*pP2A)->mode = 0x10000000;
      (*pP2A)->number = number;
      (*pP2A)->Anim_n = v9->times;
      pTexAnimTable = hResource->pTexAnimTable;
      spranm = v9->spranm;
      if (v9->times >= 1)
      {
        v24 = pTexAnimTable->m_Items[spranm];
        v25 = 0;
        do
        {
          v27 = v24 + 8 * v25;
          v29 = *(v27 + 32);
          v28 = v27 + 32;
          v30 = *(v29 + 16);
          pAnim = (*pP2A)->pAnim;
          else if (v25 >= LODWORD(pAnim->max_length))
          {
LABEL_34:
          }
          dds3Billboard_P2ASetAnim(&hBillAnimRes, v30, &pAnim->m_Items[v25]);
          v33 = (*pP2A)->pAnim;
          v35 = v33->m_Items[v25];
          v35->key = -*(*v28 + 18LL);
          ++v25;
        }
        while (v25 < v9->times);
      }
      if ((v9->attr & 0x100) == 0)
        goto LABEL_52;
    }
    else if ((v9->attr & 0xC0) != 0)
    {
      Write("billAnim..(A)MTEX SET\n", 0);
      (*pP2A)->mode = v9->attr;
      (*pP2A)->number = number;
      (*pP2A)->Anim_n = 2;
      v13 = (*pP2A)->pAnim;
      dds3Billboard_P2ASetAnim(&hBillAnimRes, number, v13->m_Items);
      v16 = (*pP2A)->pAnim;
      v17 = number + 1;
      dds3Billboard_P2ASetAnim(&hBillAnimRes, v17, &v16->m_Items[1]);
      if ((v9->attr & 0x100) == 0)
        goto LABEL_52;
    }
    else
    {
      (*pP2A)->mode = 0;
      (*pP2A)->number = number;
      (*pP2A)->Anim_n = 1;
      v37 = (*pP2A)->pAnim;
      dds3Billboard_P2ASetAnim(&hBillAnimRes, number, v37->m_Items);
      if ((v9->attr & 0x100) == 0)
        goto LABEL_52;
    }
    Write("billAnim..P2A POLYGON\n", 0);
LABEL_52:
    LOWORD(times) = 1;
  }
  (*pP2A)->state = times;
}

// 0x131aaa0
void dds3MultiBillboardLinkOt(void) {
  ;
}

// 0x13199d0
void dds3MultiBillboardPktLink(dds3MultiBillResource_tag *hResource) {
  ;
}

// 0x13199e0
void dds3MultiBillboardTagLink(billHandle_t *hBillboard, dds3MultiBillResource_tag *hResource, s32 use_mesh_idx) {
  struct dds3BillResource_tag_array *hBillRes;
  dds3BillResource_tag_o *v9;
  f32 cx;
  f32 cy;
  f32 v12;
  f32 v13;
  f32 width;
  f32 v15;
  f32 v16;
  f32 height;
  f32 v18;
  f32 v19;
  f32 v20;
  struct XRD773Unity_CommonMesh_array *pMesh;
  f32 v22;
  struct XRD773Unity_CommonMesh_array *v24;
  s32 max_length;
  s32 UseIndex;
  struct XRD773Unity_CommonMesh_array *v28;
  s32 v29;
  s64 v30;
  s32 UseIndexMax;
  struct XRD773Unity_CommonMesh_array *v33;
  s32 v34;
  u32 v35;
  struct XRD773Unity_CommonMesh_array *v37;
  XRD773Unity_CommonMesh_o *v39;
  UnityEngine_Vector3_array *v40;
  struct XRD773Unity_CommonMesh_array *v41;
  XRD773Unity_CommonMesh_o *v43;
  System_Int32_array *v44;
  struct XRD773Unity_CommonMesh_array *v45;
  XRD773Unity_CommonMesh_o *v47;
  UnityEngine_Color_array *v48;
  struct XRD773Unity_CommonMesh_array *v49;
  XRD773Unity_CommonMesh_o *v51;
  UnityEngine_Vector2_array *v52;
  struct XRD773Unity_CommonMesh_array *v53;
  XRD773Unity_CommonMesh_o *v55;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_GameObject_o *v57;
  struct XRD773Unity_CommonMesh_array *v58;
  UnityEngine_GameObject_o *v60;
  UnityEngine_Transform_o *transform;
  struct XRD773Unity_CommonMesh_array *v63;
  UnityEngine_GameObject_o *v65;
  UnityEngine_Transform_o *v67;
  struct XRD773Unity_CommonMesh_array *v68;
  UnityEngine_Vector3_array *Position;
  struct XRD773Unity_CommonMesh_array *v71;
  UnityEngine_Vector3_array *v72;
  UnityEngine_Color_array *Color;
  f32 v76;
  f32 v77;
  f32 v78;
  struct XRD773Unity_CommonMesh_array *v81;
  XRD773Unity_CommonMesh_o *v83;
  s64 v84;
  s64 v85;
  s64 v86;
  s64 v87;
  s64 v88;
  s64 v89;
  s64 v90;
  s64 v93;
  s64 v94;
  s64 v95;
  s64 v96;
  s64 v97;
  s64 v98;
  s64 v99;
  f32 x;
  f32 y;
  f32 w;
  f32 z;
  f32 v107;
  f32 v108;
  f32 v109;
  s64 v110;
  struct System_UInt32_array *abgr;
  f32 v113;
  f32 v114;
  f32 v115;
  f32 v116;
  f32 alf_raito;
  f32 v118;
  long f64 v119;
  long f64 v120;
  s32 v121;
  s32 v122;
  u32 *v124;
  s64 v125;
  long f64 v127;
  long f64 v128;
  s32 v129;
  s32 v130;
  u32 *v132;
  long f64 v134;
  long f64 v135;
  s32 v136;
  s32 v137;
  s32 v138;
  u32 *v140;
  long f64 v142;
  long f64 v143;
  s32 v144;
  s32 v145;
  s32 v146;
  u32 *v148;
  struct XRD773Unity_CommonMesh_array *v150;
  System_Int32_array *IndexTable;
  s64 v154;
  s64 v156;
  s32 v157;
  s64 v158;
  s64 v160;
  s64 v162;
  s64 v164;
  struct UnityEngine_Texture_array *texture;
  s64 use_tmx_idx;
  s64 v169;
  s32 v170;
  UnityEngine_Object_o *v172;
  struct XRD773Unity_CommonMesh_array *v173;
  UnityEngine_Vector2_array *UvTable;
  struct UnityEngine_Vector2_array *uv;
  UnityEngine_Vector2_array *v177;
  struct UnityEngine_Vector2_array *v180;
  struct UnityEngine_Vector2_array *v182;
  struct UnityEngine_Vector2_array *v186;
  u32 v187;
  struct XRD773Unity_CommonMesh_array *v191;
  struct UnityEngine_Texture_array *v193;
  XRD773Unity_CommonMesh_o *v194;
  struct XRD773Unity_CommonMesh_array *v196;
  struct XRD773Unity_CommonMesh_array *v198;
  XRD773Unity_CommonMesh_o *v200;
  UnityEngine_GameObject_o *v201;
  UnityEngine_GameObject_o *v202;
  f32 v203;
  f32 v204;
  s64 v205;
  f32 v206;
  s64 v207;
  f32 v208;
  s64 v209;
  f32 v;
  s64 va;
  UnityEngine_Matrix4x4_o v212;
  UnityEngine_Matrix4x4_o v213;
  UnityEngine_Matrix4x4_o v214;
  UnityEngine_Matrix4x4_o v215;
  UnityEngine_Matrix4x4_o v216;
  UnityEngine_Matrix4x4_o v217;
  UnityEngine_Matrix4x4_o v218;
  UnityEngine_Matrix4x4_o v219;
  UnityEngine_Quaternion_o v220;
  UnityEngine_Matrix4x4_o v221;
  UnityEngine_Vector3_o v222;
  UnityEngine_Vector4_o v223;
  UnityEngine_Color_o v224;
  UnityEngine_Color_o v225;
  UnityEngine_Color_o v226;
  UnityEngine_Color_o v227;
  UnityEngine_Vector3_o zero;
  UnityEngine_Vector3_o v229;
  UnityEngine_Vector3_o v230;
  UnityEngine_Vector4_o v231;
  UnityEngine_Vector4_o v232;
  UnityEngine_Vector4_o v233;
  UnityEngine_Vector4_o v234;
  UnityEngine_Vector4_o v235;
  UnityEngine_Quaternion_o identity;
  UnityEngine_Color_o BlendColor;

  memset(&v221, 0, sizeof(v221));
  hBillRes = hResource->hBillRes;
  v9 = hBillRes->m_Items[1];
  cx = v9->cx;
  sub_854710(&hBillboard->scale, 0);
  cy = v9->cy;
  v13 = v12;
  sub_854710(&hBillboard->scale, 1u);
  width = v9->width;
  v16 = v15;
  sub_854710(&hBillboard->scale, 0);
  height = v9->height;
  v19 = v18;
  sub_854710(&hBillboard->scale, 1u);
  pMesh = hBillboard->pMesh;
  if (!pMesh)
    goto LABEL_139;
  v22 = v20;
  if (!GetUseOne(pMesh->m_Items[use_mesh_idx]))
    goto LABEL_139;
  v24 = hBillboard->pMesh;
  max_length = v24->max_length;
  if (max_length <= use_mesh_idx)
    goto LABEL_139;
  UseIndex = GetUseIndex(v24->m_Items[use_mesh_idx]);
  v28 = hBillboard->pMesh;
  v29 = UseIndex;
  v30 = UseIndex;
  UseIndexMax = GetUseIndexMax(v28->m_Items[use_mesh_idx]);
  if (v30 < UseIndexMax)
  {
    v33 = hBillboard->pMesh;
    v34 = UseIndexMax;
    v35 = 4 * UseIndexMax;
    if (v35 > SLODWORD(GetPosition(v33->m_Items[use_mesh_idx])->max_length))
    {
      v37 = hBillboard->pMesh;
      v39 = v37->m_Items[use_mesh_idx];
      v40 = NewSpecific(UnityEngine_Vector3, v35);
      SetPosition_20241056(v39, v40);
      v41 = hBillboard->pMesh;
      v43 = v41->m_Items[use_mesh_idx];
      v44 = NewSpecific(s32, (6 * v34));
      SetIndexTable(v43, v44);
      v45 = hBillboard->pMesh;
      v47 = v45->m_Items[use_mesh_idx];
      v48 = NewSpecific(UnityEngine_Color, v35);
      SetColor_20241296(v47, v48);
      v49 = hBillboard->pMesh;
      v51 = v49->m_Items[use_mesh_idx];
      v52 = NewSpecific(UnityEngine_Vector2, v35);
      SetUvTable_20243232(v51, v52);
      v53 = hBillboard->pMesh;
      v55 = v53->m_Items[use_mesh_idx];
      gameObject = get_gameObject(v55);
      if (!get_activeSelf(gameObject))
      {
        v57 = get_gameObject(v55);
        SetActive(v57, 1, 0);
      }
      v55->hide = 0;
      v58 = hBillboard->pMesh;
      v60 = get_gameObject(v58->m_Items[use_mesh_idx]);
      transform = get_transform(v60, 0);
      zero = get_zero();
      set_position(transform, zero);
      v63 = hBillboard->pMesh;
      v65 = get_gameObject(v63->m_Items[use_mesh_idx]);
      v67 = get_transform(v65, 0);
      {
      }
      identity = get_identity(0);
      set_rotation(v67, identity);
    }
    v68 = hBillboard->pMesh;
    v = cx;
    Position = GetPosition(v68->m_Items[use_mesh_idx]);
    v71 = hBillboard->pMesh;
    v72 = Position;
    v208 = v13;
    Color = GetColor(v71->m_Items[use_mesh_idx], 0);
    v76 = hBillboard->rot * 0.5;
    v77 = sdfSin(v76);
    v78 = sdfCos(v76);
    *&v220.x = 0;
    *&v220.z = 0;
    sub_1A1BDD0(&v220.x, 0.0, 0.0, v77, v78);
    Rotate(&v219, v220, 0);
    v221 = v219;
    v81 = hBillboard->pMesh;
    v83 = v81->m_Items[use_mesh_idx];
    v84 = *&v83->mat.m00;
    v85 = *&v83->mat.m20;
    v86 = *&v83->mat.m21;
    *&v218.m01 = *&v83->mat.m01;
    *&v218.m21 = v86;
    *&v218.m00 = v84;
    *&v218.m20 = v85;
    v87 = *&v83->mat.m02;
    v88 = *&v83->mat.m22;
    v89 = *&v83->mat.m03;
    v90 = *&v83->mat.m23;
    *&v218.m03 = v89;
    *&v218.m23 = v90;
    v206 = cy;
    v204 = v16;
    *&v218.m02 = v87;
    *&v218.m22 = v88;
    v203 = height;
    v93 = *&mod_p_matrix.m20;
    v94 = *&mod_p_matrix.m01;
    v95 = *&mod_p_matrix.m21;
    *&v215.m00 = *&mod_p_matrix.m00;
    *&v215.m20 = v93;
    *&v215.m01 = v94;
    *&v215.m21 = v95;
    v96 = *&mod_p_matrix.m02;
    v97 = *&mod_p_matrix.m22;
    v99 = *&mod_p_matrix.m03;
    v98 = *&mod_p_matrix.m23;
    v216 = v218;
    *&v215.m03 = v99;
    *&v215.m23 = v98;
    *&v215.m02 = v96;
    *&v215.m22 = v97;
    op_Multiply(&v217, &v216, &v215, 0);
    v212 = v221;
    v213 = v217;
    op_Multiply(&v214, &v213, &v212, 0);
    v221 = v214;
    x = hBillboard->pos.x;
    y = hBillboard->pos.y;
    z = hBillboard->pos.z;
    w = hBillboard->pos.w;
    v231.x = x;
    v231.y = y;
    v231.z = z;
    v231.w = w;
    v222 = op_Implicit_8738992(v231);
    v108 = mod_pos.x;
    v107 = mod_pos.y;
    v109 = mod_pos.z;
    v230.x = v108;
    v230.y = v107;
    v230.z = v109;
    v110 = 4LL * v29;
    v229 = Scale(v222, v230);
    op_Implicit(v229, 0);
    sub_1A009D0(&v221, 3);
    abgr = hResource->abgr;
    v113 = v * v208;
    v114 = v206 * v204;
    v115 = width * v19;
    v116 = v203 * v22;
    BlendColor = effGetBlendColor(abgr->m_Items[1]);
    v223 = op_Implicit(BlendColor, 0);
    alf_raito = hBillboard->alf_raito;
    v118 = v223.w;
    if (alf_raito != 0.0)
    {
      v118 = v223.w * alf_raito;
      if ((v223.w * alf_raito) > 1.0)
        v118 = 1.0;
    }
    v219.m20 = 0.0;
    *&v219.m00 = 0;
    sub_8524C0(&v219.m00, v113 - v115, v114 - v116, 0.0);
    v120 = sub_1A00CF0(&v221.m00, v219.m00, v219.m10, v219.m20, v119);
    v124 = (v72 + 12 * v110);
    v124[8] = LODWORD(v120);
    v124[9] = v121;
    v124[10] = v122;
    v232.y = v223.y;
    v232.x = v223.x;
    v232.z = v223.z;
    v232.w = v118;
    v125 = v110 | 1LL;
    v224 = op_Implicit_27186336(v232);
    Color->m_Items[v110] = v224;
    v218.m20 = 0.0;
    *&v218.m00 = 0;
    sub_8524C0(&v218.m00, v113 + v115, v114 - v116, 0.0);
    v128 = sub_1A00CF0(&v221.m00, v218.m00, v218.m10, v218.m20, v127);
    v132 = (v72 + 12 * v125);
    v132[8] = LODWORD(v128);
    v132[9] = v129;
    v132[10] = v130;
    v233.z = v223.z;
    v233.y = v223.y;
    v233.x = v223.x;
    v233.w = v118;
    v207 = v125 + 1LL;
    v225 = op_Implicit_27186336(v233);
    Color->m_Items[v125] = v225;
    v217.m20 = 0.0;
    *&v217.m00 = 0;
    sub_8524C0(&v217.m00, v113 + v115, v114 + v116, 0.0);
    v135 = sub_1A00CF0(&v221.m00, v217.m00, v217.m10, v217.m20, v134);
    v138 = v137;
    v140 = (v72 + 12 * v207);
    v140[8] = LODWORD(v135);
    v140[9] = v136;
    v234.z = v223.z;
    v234.x = v223.x;
    v234.y = v223.y;
    v234.w = v118;
    v140[10] = v138;
    v209 = v110 | 3LL;
    v226 = op_Implicit_27186336(v234);
    Color->m_Items[v207] = v226;
    v214.m20 = 0.0;
    *&v214.m00 = 0;
    sub_8524C0(&v214.m00, v113 - v115, v114 + v116, 0.0);
    v143 = sub_1A00CF0(&v221.m00, v214.m00, v214.m10, v214.m20, v142);
    v146 = v145;
    v148 = (v72 + 12 * v209);
    v148[8] = LODWORD(v143);
    v148[9] = v144;
    v235.z = v223.z;
    v235.x = v223.x;
    v235.y = v223.y;
    v235.w = v118;
    v148[10] = v146;
    v227 = op_Implicit_27186336(v235);
    Color->m_Items[v209] = v227;
    v150 = hBillboard->pMesh;
    v205 = use_mesh_idx;
    IndexTable = GetIndexTable(v150->m_Items[use_mesh_idx]);
    v154 = (6 * v30) | 1LL;
    v156 = v154;
    IndexTable->m_Items[6 * v30] = v110;
    v157 = v30;
    va = v110;
    v158 = v154 + 1LL;
    IndexTable->m_Items[v154] = v125;
    v160 = v154 + 2LL;
    IndexTable->m_Items[v158] = v209;
    v162 = v154 + 3LL;
    IndexTable->m_Items[v160] = v125;
    v164 = v156 + 4;
    IndexTable->m_Items[v162] = va | 2;
    IndexTable->m_Items[v164] = v209;
    texture = hBillboard->texture;
    if (texture)
    {
      use_tmx_idx = hBillboard->use_tmx_idx;
      v169 = use_tmx_idx - 128;
      if (((use_tmx_idx - 128) & 0x80000000) == 0)
      {
        v170 = texture->max_length;
        if (v169 < v170)
        {
          v172 = texture->m_Items[v169];
          if (op_Inequality(v172, 0, 0))
          {
            v173 = hBillboard->pMesh;
            UvTable = GetUvTable(v173->m_Items[use_mesh_idx]);
            uv = v9->uv;
            v177 = UvTable;
            sub_851A70(&UvTable->m_Items[va], uv->m_Items[0].x, v9->uv->m_Items[0].y);
            v180 = v9->uv;
            sub_851A70(&v177->m_Items[v125], v180->m_Items[1].x, v9->uv->m_Items[0].y);
            v182 = v9->uv;
            sub_851A70(&v177->m_Items[v207], v182->m_Items[1].x, v182->m_Items[1].y);
            v186 = v9->uv;
            v187 = v186->max_length;
            sub_851A70(&v177->m_Items[v209], v186->m_Items[0].x, v9->uv->m_Items[1].y);
            v191 = hBillboard->pMesh;
            v193 = hBillboard->texture;
            v194 = v191->m_Items[use_mesh_idx];
            SetMatTexture(v194, v193->m_Items[v169]);
          }
        }
      }
    }
    v196 = hBillboard->pMesh;
    SetUseIndex(v196->m_Items[use_mesh_idx], v157 + 1);
    v198 = hBillboard->pMesh;
    v200 = v198->m_Items[use_mesh_idx];
    v201 = get_gameObject(v198->m_Items[v205]);
    if (!get_activeSelf(v201))
    {
      v202 = get_gameObject(v200);
      SetActive(v202, 1, 0);
    }
    v200->hide = 0;
LABEL_139:
    ++v9->number;
  }
}

// 0x131e6d0
dds3P2APolygon_tag *dds3P2APolygonCopy(void **hData, s32 bPos, bool tbldata) {
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  dds3P2APolygon_tag_o *v10;
  billHandle_t_o *v12;
  u64 *v13;
  u64 v16[3];

  v5 = *hData;
  if (*hData)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3P2APolygon_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3P2APolygon_tag, v16);
      if ((v16[0] & 1) != 0)
        v8 = v16[2];
      else
        v8 = v16 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = Allocate(dds3P2APolygon_tag);
  dds3P2APolygon_tag___ctor(v10);
  v12 = v5[9].klass;
  v10->hBillboard = dds3BillboardCopy(v12);
  v13 = Allocate(sdfMat_t);
  sdfMat_t___ctor(v13);
  v10->pMat = v13;
  sdfMatSetConstant(v13, 1.0);
  sdfMatSetDiffuse(v10->pMat, 0x80808080);
  sdfMatSetAmbient(v10->pMat, 0x80808080);
  sdfMatSetSpecular(v10->pMat, 0x80808080);
  SDF_VU0__STOREIDENTITY(&v10->rot);
  SDF_VU0__STOREIDENTITY(&v10->dir);
  return v10;
}

// 0x131e5c0
dds3P2APolygon_tag *dds3P2APolygonCreate(void **hData, s32 bPos, bool tbldata) {
  dds3P2APolygon_tag_o *v6;
  Il2CppObject *v9;
  u64 *v10;

  v6 = Allocate(dds3P2APolygon_tag);
  dds3P2APolygon_tag___ctor(v6);
  v9 = *hData;
  v6->hBillboard = dds3BillboardCreate(1, v9, bPos, "dds3P2APolygonCreate");
  v10 = Allocate(sdfMat_t);
  sdfMat_t___ctor(v10);
  v6->pMat = v10;
  sdfMatSetConstant(v10, 1.0);
  SDF_VU0__STOREIDENTITY(&v6->rot);
  return v6;
}

// 0x131e8a0
void dds3P2APolygonDelete(void **hData) {
  dds3P2APolygon_tag_c *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  Il2CppClass *v8;
  u64 v9[3];

  v8 = 0;
  klass = (*hData)->klass;
  if (klass->_2.typeHierarchyDepth < typeHierarchyDepth
    || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3P2APolygon_tag)
  {
    sub_8FC2C0(klass->_1.element_class, dds3P2APolygon_tag, v9);
    if ((v9[0] & 1) != 0)
      v6 = v9[2];
    else
      v6 = v9 + 1;
    v7 = sub_8C4940(v6);
  }
  v8 = (*hData)[9].klass;
  dds3BillboardDelete(&v8, v3);
}

// 0x131f210
void dds3P2APolygonDraw(void **hData) {
  Il2CppObject *v3;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v6;
  s64 *v7;
  dds3P2APolygonResource_tag_o *v8;
  struct dds3BillResource_tag_array *v9;
  struct dds3BillResource_tag_array *v10;
  u64 *v11;
  struct dds3BillResource_tag_array *hResource;
  u64 *v14;
  Il2CppClass *v18;
  struct dds3BillResource_tag_array *v19;
  dds3BillResource_tag_o *v21;
  f32 v22;
  f32 v23;
  f32 v24;
  f32 v25;
  f32 height;
  f32 v27;
  Il2CppClass *v28;
  void *monitor;
  void *v30;
  Il2CppClass *v31;
  void *v32;
  void *v33;
  s64 v38;
  s64 v39;
  s64 v40;
  s64 v41;
  s64 v42;
  s64 v43;
  f32 v45;
  f32 v47;
  f32 v48;
  f32 *v50;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 x;
  f32 y;
  f32 z;
  Il2CppClass *v60;
  Il2CppClass *v61;
  u64 *v62;
  u64 *v64;
  XRD773Unity_GraphicManager_o *Instance;
  s64 *Mesh;
  s64 *v69;
  void *typeDefinition;
  XRD773Unity_CommonMesh_o *v74;
  UnityEngine_Vector3_array *v75;
  void *v76;
  XRD773Unity_CommonMesh_o *v78;
  UnityEngine_Color_array *v79;
  System_Array_o *v80;
  void *v81;
  void *v83;
  UnityEngine_Object_o *gameObject;
  System_String_o *name;
  System_String_o *v87;
  u32 *v88;
  void *v90;
  f32 v92;
  f32 v93;
  f32 v94;
  f32 v95;
  UnityEngine_Vector3_array *Position;
  void *v97;
  UnityEngine_Vector3_array *v98;
  UnityEngine_Color_array *Color;
  UnityEngine_Color_array *v101;
  long f64 v102;
  long f64 v103;
  f32 v104;
  f32 v105;
  long f64 v108;
  long f64 v109;
  f32 v110;
  f32 v111;
  long f64 v114;
  long f64 v115;
  f32 v116;
  f32 v117;
  long f64 v120;
  long f64 v121;
  f32 v122;
  f32 v123;
  Il2CppClass *parent;
  s64 texId;
  UnityEngine_Object_o *v130;
  void *v131;
  UnityEngine_Object_o *Texture;
  void *v135;
  Il2CppClass *v137;
  s64 v138;
  XRD773Unity_CommonMesh_o *v139;
  f32 *v141;
  struct UnityEngine_Vector2_array *uv;
  f32 *v143;
  f32 v145;
  f32 v146;
  struct UnityEngine_Vector2_array *v148;
  f32 v150;
  f32 v151;
  f32 m10;
  struct UnityEngine_Vector2_array *v154;
  f32 v156;
  f32 v157;
  struct UnityEngine_Vector2_array *v159;
  u32 max_length;
  f32 v163;
  f32 v164;
  f32 v165;
  void *v167;
  u32 *v169;
  s64 v171;
  UnityEngine_GameObject_o *v172;
  UnityEngine_GameObject_o *v173;
  f32 width;
  f32 cy;
  f32 cx;
  f32 v179;
  f32 v180;
  UnityEngine_Matrix4x4_o v181;
  UnityEngine_Matrix4x4_o v182;
  UnityEngine_Matrix4x4_o v183;
  UnityEngine_Matrix4x4_o v184;
  UnityEngine_Quaternion_o v185;
  UnityEngine_Matrix4x4_o v186;
  UnityEngine_Matrix4x4_o v187;
  UnityEngine_Matrix4x4_o v188;
  UnityEngine_Matrix4x4_o v189;
  UnityEngine_Matrix4x4_o v190;
  UnityEngine_Matrix4x4_o dest;
  UnityEngine_Matrix4x4_o v192;
  UnityEngine_Matrix4x4_o aMatrix;
  dds3P2APolygonResource_tag_o *pP2APolyRes;
  dds3P2APolygon_tag_o *hP2APoly;
  UnityEngine_Vector3_o v196;
  UnityEngine_Vector4_o v197;
  UnityEngine_Color_o v198;
  UnityEngine_Color_o v199;
  UnityEngine_Color_o v200;
  UnityEngine_Color_o v201;
  UnityEngine_Vector3_o v202;
  UnityEngine_Vector3_o v203;
  UnityEngine_Vector4_o v204;
  UnityEngine_Color_o BlendColor;

  pP2APolyRes = 0;
  hP2APoly = 0;
  memset(&aMatrix, 0, sizeof(aMatrix));
  v3 = *hData;
  if (*hData)
  {
    klass = v3->klass;
    if (v3->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3P2APolygon_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3P2APolygon_tag, &v190);
      if ((LOBYTE(v190.m00) & 1) != 0)
        v6 = *&v190.m01;
      else
        v6 = &v190.m00 + 1;
      v7 = sub_8C4940(v6);
    }
  }
  hP2APoly = *hData;
  v8 = Allocate(dds3P2APolygonResource_tag);
  dds3P2APolygonResource_tag___ctor(v8);
  pP2APolyRes = v8;
  v9 = NewSpecific(dds3BillResource_tag, 2u);
  v8->hResource = v9;
  v10 = v9;
  v11 = Allocate(dds3BillResource_tag);
  dds3BillResource_tag___ctor(v11);
  v10->m_Items[0] = v11;
  hResource = v8->hResource;
  v14 = Allocate(dds3BillResource_tag);
  dds3BillResource_tag___ctor(v14);
  hResource->m_Items[1] = v14;
  v18 = v3[9].klass;
  if (v18 && LOWORD(v18->_1.element_class) == 1 && LOWORD(v18->_1.declaringType->_1.byval_arg.bits))
  {
    dds3P2APolygonGetResource(&hP2APoly, &pP2APolyRes);
    v19 = v8->hResource;
    v21 = v19->m_Items[0];
    sub_854710(&v3[9].klass->_1.byval_arg, 0);
    v23 = v22;
    sub_854710(&v3[9].klass->_1.byval_arg, 1u);
    v25 = v24;
    cx = v21->cx;
    cy = v21->cy;
    height = v21->height;
    width = v21->width;
    v27 = *&v3[9].klass->_1.this_arg.data;
    v28 = v3[5].klass;
    monitor = v3[5].monitor;
    v30 = v3[6].monitor;
    *&v192.m01 = v3[6].klass;
    *&v192.m21 = v30;
    *&v192.m00 = v28;
    *&v192.m20 = monitor;
    v31 = v3[7].klass;
    v32 = v3[7].monitor;
    v33 = v3[8].monitor;
    *&v192.m03 = v3[8].klass;
    *&v192.m23 = v33;
    *&v192.m02 = v31;
    *&v192.m22 = v32;
    SDF_VU0__LOADMATRIX(&v192);
    memmove(&dest, &v3[1], 0x40u);
    SDF_VU0__LOADMATRIX_B(&dest);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(&aMatrix);
    v180 = height;
    v38 = *&mod_p_matrix.m00;
    v39 = *&mod_p_matrix.m20;
    v40 = *&mod_p_matrix.m01;
    *&v190.m21 = *&mod_p_matrix.m21;
    *&v190.m01 = v40;
    *&v190.m20 = v39;
    *&v190.m00 = v38;
    v41 = *&mod_p_matrix.m02;
    v42 = *&mod_p_matrix.m22;
    v43 = *&mod_p_matrix.m03;
    *&v190.m23 = *&mod_p_matrix.m23;
    *&v190.m03 = v43;
    *&v190.m22 = v42;
    *&v190.m02 = v41;
    sub_19FF440(&aMatrix, 0, &v189);
    v187 = v190;
    v186 = v189;
    v45 = v27 * 0.5;
    op_Multiply(&v188, &v187, &v186, 0);
    v47 = sdfSin(v45);
    v48 = sdfCos(v45);
    *&v185.x = 0;
    *&v185.z = 0;
    sub_1A1BDD0(&v185.x, 0.0, 0.0, v47, v48);
    Rotate(&v184, v185, 0);
    v182 = v188;
    v181 = v184;
    op_Multiply(&v183, &v182, &v181, 0);
    aMatrix = v183;
    v50 = v3[9].klass;
    v51 = v50[4];
    v52 = v50[5];
    v54 = v50[6];
    v53 = v50[7];
    v204.x = v51;
    v204.y = v52;
    v204.z = v54;
    v204.w = v53;
    v196 = op_Implicit_8738992(v204);
    x = mod_pos.x;
    y = mod_pos.y;
    z = mod_pos.z;
    v203.x = x;
    v203.y = y;
    v203.z = z;
    v202 = Scale(v196, v203);
    op_Implicit(v202, 0);
    sub_1A009D0(&aMatrix, 3);
    v60 = v3[9].klass;
    v61 = v60;
    if (!v60->_1.typeDefinition)
    {
      v62 = NewSpecific(XRD773Unity_CommonMesh, 1u);
      v60->_1.typeDefinition = v62;
      v64 = v62;
      {
      }
      Instance = get_Instance();
      Mesh = GetMesh(Instance, WORD1(v60->_1.element_class) + 4, 0);
      v69 = Mesh;
      v64[4] = v69;
      typeDefinition = v60->_1.typeDefinition;
      v74 = *(typeDefinition + 4);
      v75 = NewSpecific(UnityEngine_Vector3, 4u);
      SetPosition_20241056(v74, v75);
      v76 = v60->_1.typeDefinition;
      v78 = *(v76 + 4);
      v79 = NewSpecific(UnityEngine_Color, 4u);
      SetColor_20241296(v78, v79);
      v80 = NewSpecific(s32, 6u);
      InitializeArray_1543888(v80, Field__PrivateImplementationDetails__6DE216719A6E1E118DA5F0F078987A1B8E71B32F);
      v81 = v60->_1.typeDefinition;
      SetIndexTable(*(v81 + 4), v80, 0);
      v83 = v60->_1.typeDefinition;
      gameObject = get_gameObject(*(v83 + 4), 0);
      name = get_name(gameObject);
      v87 = Concat_5224608(name, ":dds3P2APolygonDraw:0");
      set_name(gameObject, v87);
      v88 = v60->_1.typeDefinition;
      *(*(v88 + 4) + 32LL) = 257;
      v61 = v3[9].klass;
    }
    BlendColor = effGetBlendColor(HIDWORD(v61->_1.this_arg.data), 0);
    v197 = op_Implicit(BlendColor, 0);
    if (v197.w > 0.0)
    {
      v90 = v60->_1.typeDefinition;
      v92 = v23 * cx;
      v93 = v25 * cy;
      v94 = v23 * width;
      v95 = v25 * v180;
      Position = GetPosition(*(v90 + 4), 0);
      v97 = v60->_1.typeDefinition;
      v98 = Position;
      Color = GetColor(*(v97 + 4), 0);
      v179 = v25 * cy;
      *&v190.m00 = 0;
      v101 = Color;
      v190.m20 = 0.0;
      sub_8524C0(&v190.m00, v92 - v94, v93 - v95, 0.0);
      v103 = sub_1A00CF0(&aMatrix.m00, v190.m00, v190.m10, v190.m20, v102);
      v98->m_Items[0].x = *&v103;
      v98->m_Items[0].y = v104;
      v98->m_Items[0].z = v105;
      v198 = op_Implicit_27186336(v197);
      v101->m_Items[0] = v198;
      v189.m20 = 0.0;
      *&v189.m00 = 0;
      sub_8524C0(&v189.m00, v92 + v94, v93 - v95, 0.0);
      v109 = sub_1A00CF0(&aMatrix.m00, v189.m00, v189.m10, v189.m20, v108);
      v98->m_Items[1].x = *&v109;
      v98->m_Items[1].y = v110;
      v98->m_Items[1].z = v111;
      v199 = op_Implicit_27186336(v197);
      v101->m_Items[1] = v199;
      v188.m20 = 0.0;
      *&v188.m00 = 0;
      sub_8524C0(&v188.m00, v92 + v94, v179 + v95, 0.0);
      v115 = sub_1A00CF0(&aMatrix.m00, v188.m00, v188.m10, v188.m20, v114);
      v98->m_Items[2].x = *&v115;
      v98->m_Items[2].y = v116;
      v98->m_Items[2].z = v117;
      v200 = op_Implicit_27186336(v197);
      v101->m_Items[2] = v200;
      v184.m20 = 0.0;
      *&v184.m00 = 0;
      sub_8524C0(&v184.m00, v92 - v94, v179 + (v25 * v180), 0.0);
      v121 = sub_1A00CF0(&aMatrix.m00, v184.m00, v184.m10, v184.m20, v120);
      v98->m_Items[3].x = *&v121;
      v98->m_Items[3].y = v122;
      v98->m_Items[3].z = v123;
      v201 = op_Implicit_27186336(v197);
      v101->m_Items[3] = v201;
      parent = v60->_1.parent;
      if (parent)
      {
        texId = v21->hTex->texId;
        v130 = *(&parent->_1.byval_arg.data + texId);
        if (op_Inequality(v130, 0, 0))
        {
          v131 = v60->_1.typeDefinition;
          Texture = GetTexture(*(v131 + 4), 0);
          if (op_Equality(Texture, 0, 0))
          {
            v135 = v60->_1.typeDefinition;
            v137 = v60->_1.parent;
            v138 = v21->hTex->texId;
            v139 = *(v135 + 4);
            SetMatTexture(v139, *(&v137->_1.byval_arg.data + v138), 0);
            v141 = NewSpecific(UnityEngine_Vector2, 4u);
            uv = v21->uv;
            v143 = v141;
            v146 = uv->m_Items[0].x;
            v145 = uv->m_Items[0].y;
            v141[8] = v146;
            v141[9] = v145;
            v148 = v21->uv;
            v150 = v21->uv->m_Items[0].y;
            v151 = v148->m_Items[1].x;
            *&v190.m00 = 0;
            sub_851710(&v190.m00, v151, v150);
            m10 = v190.m10;
            v143[10] = v190.m00;
            v143[11] = m10;
            v154 = v21->uv;
            v157 = v154->m_Items[1].x;
            v156 = v154->m_Items[1].y;
            v143[12] = v157;
            v143[13] = v156;
            v159 = v21->uv;
            max_length = v159->max_length;
            v163 = v21->uv->m_Items[1].y;
            v164 = v159->m_Items[0].x;
            *&v189.m00 = 0;
            sub_851710(&v189.m00, v164, v163);
            v165 = v189.m10;
            v143[14] = v189.m00;
            v143[15] = v165;
            v167 = v60->_1.typeDefinition;
            SetUvTable_20243232(*(v167 + 4), v143, 0);
          }
        }
      }
      v169 = v60->_1.typeDefinition;
      v171 = *(v169 + 4);
      v172 = get_gameObject(v171);
      if (!get_activeSelf(v172))
      {
        v173 = get_gameObject(v171);
        SetActive(v173, 1, 0);
      }
      *(v171 + 33) = 0;
    }
  }
}

// 0x131efe0
void dds3P2APolygonGetResource(dds3P2APolygon_tag **hP2APoly, dds3P2APolygonResource_tag **pP2APolyRes) {
  struct billHandle_t_o *hBillboard;
  dds3Billboard_P2A_tag3_o *v6;
  u32 mode;
  dds3P2APolygonResource_tag_o *v8;
  struct dds3BillResource_tag_array *hResource;
  struct dds3BillAnim_tag_array *pAnim;
  s64 *v12;
  s32 v13;
  struct dds3BillResource_tag_array *v14;
  struct dds3BillAnim_tag_array *v15;
  s64 *v17;
  s64 *v19;
  dds3P2APolygonResource_tag_o *v22;
  struct dds3BillAnim_tag_array *v23;
  dds3Billboard_P2A_tag3_o *pP2A;

  pP2A = 0;
  hBillboard = (*hP2APoly)->hBillboard;
  if (hBillboard->type == 1)
  {
    v6 = hBillboard->pP2A;
    pP2A = v6;
    mode = v6->mode;
    if ((mode & 0x40) != 0)
    {
      v8 = *pP2APolyRes;
      v13 = 2;
    }
    else
    {
      v8 = *pP2APolyRes;
      if ((mode & 0x80) == 0)
      {
        v8->type = 0;
        hResource = (*pP2APolyRes)->hResource;
        pAnim = v6->pAnim;
        v12 = dds3Billboard_P2AAnimDraw(&pP2A, pAnim->m_Items);
        if (!v12)
          goto LABEL_28;
        goto LABEL_27;
      }
      v13 = 3;
    }
    v8->type = v13;
    v14 = (*pP2APolyRes)->hResource;
    v15 = v6->pAnim;
    else if (!LODWORD(v15->max_length))
    {
      goto LABEL_18;
    }
    v17 = dds3Billboard_P2AAnimDraw(&pP2A, v15->m_Items);
    v19 = v17;
    v14->m_Items[1] = v19;
    v22 = *pP2APolyRes;
    v23 = v6->pAnim;
    hResource = v22->hResource;
    v12 = dds3Billboard_P2AAnimDraw(&pP2A, &v23->m_Items[1]);
    if (!v12)
      goto LABEL_28;
LABEL_27:
LABEL_28:
    hResource->m_Items[0] = v12;
  }
}

// 0x131eeb0
void dds3P2APolygonSetDirection(void **hData, sdfMatrix4_t *pMatrix) {
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
  v7 = *hData;
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
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3P2APolygon_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3P2APolygon_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[1]);
}

// 0x131e9c0
void dds3P2APolygonSetPosition(void **hData, sdfVector4_t pPos) {
  f32 w;
  f32 z;
  f32 y;
  f32 x;
  Il2CppObject *v8;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v11;
  s64 *v12;
  UnityEngine_Vector4_o *v13;
  u64 v14[3];
  UnityEngine_Vector4_o v15;

  w = pPos.w;
  z = pPos.z;
  y = pPos.y;
  x = pPos.x;
  v8 = *hData;
  if (v8)
  {
    klass = v8->klass;
    if (v8->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3P2APolygon_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3P2APolygon_tag, v14);
      if ((v14[0] & 1) != 0)
        v11 = v14[2];
      else
        v11 = v14 + 1;
      v12 = sub_8C4940(v11);
    }
  }
  v13 = v8[9].klass;
  if (v13)
  {
    v15.x = x;
    v15.y = y;
    v15.z = z;
    v15.w = w;
    SDF_VU0__COPYVECTOR(v13 + 1, v15);
  }
}

// 0x131ed90
void dds3P2APolygonSetRGBA(void **hData, u32 abgr) {
  u32 v3;
  Il2CppObject *v5;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v8;
  s64 *v9;
  Il2CppClass *v10;
  u64 v11[3];

  v3 = abgr;
  v5 = *hData;
  if (v5)
  {
    klass = v5->klass;
    if (v5->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3P2APolygon_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3P2APolygon_tag, v11);
      if ((v11[0] & 1) != 0)
        v8 = v11[2];
      else
        v8 = v11 + 1;
      v9 = sub_8C4940(v8);
    }
  }
  v10 = v5[9].klass;
  if (v10)
    HIDWORD(v10->_1.this_arg.data) = v3;
}

// 0x131ec60
void dds3P2APolygonSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
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
  v7 = *hData;
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
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3P2APolygon_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3P2APolygon_tag, v17);
      if ((v17[0] & 1) != 0)
        v14 = v17[2];
      else
        v14 = v17 + 1;
      v15 = sub_8C4940(v14);
    }
  }
  SDF_VU0__STOREMATRIX(&v7[5]);
}

// 0x131eb10
void dds3P2APolygonSetScale(void **hData, f32 scale) {
  Il2CppObject *v4;
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v7;
  s64 *v8;
  Il2CppClass *v9;
  u64 v10[3];

  v4 = *hData;
  if (v4)
  {
    klass = v4->klass;
    if (v4->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3P2APolygon_tag)
    {
      sub_8FC2C0(klass->_1.element_class, dds3P2APolygon_tag, v10);
      if ((v10[0] & 1) != 0)
        v7 = v10[2];
      else
        v7 = v10 + 1;
      v8 = sub_8C4940(v7);
    }
  }
  v9 = v4[9].klass;
  if (v9)
  {
    sub_854930(&v9->_1.byval_arg, 0);
    sub_854930(&v4[9].klass->_1.byval_arg, 1u);
  }
}

// 0x1317860
void effPkt3DPrimLinkPoly(sdfDrawTag_t *pTag, sdf3DPrimPolyParm_t *pParam) {
  ;
}

// 0x1317870
pacFileHandle_t *pacLoad(char *filename) {
  return 0;
}

// 0x1317840
void pacSync(pacFileHandle_t *pacFileHandle) {
  ;
}

// 0x1317830
void sdfChipFree(void *aPtr) {
  ;
}

// 0x1317880
sdfMemHandle_t *sdfDevLoadFile(char *aFilename, void *aTopPtr, s32 aSizePtr) {
  return 0;
}

// 0x1317850
void sdfSetPacketHeader(sdfGrPacketHeader_t *aHdr, s32 aSize) {
  ;
}
