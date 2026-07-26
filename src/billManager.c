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
static billManager_hG_t hGeneralBillboard[UNKNOWN_ARRAY_SIZE];
static dds3BillResource_tag *hDrawListTop;
static dds3EffectTable_t *EffBillboardTable[2];
static void pBillTexture[UNKNOWN_ARRAY_SIZE];
static f32 bill_alf_raito;
static f32 bill_alf_raito2;
static f32 bill_bri_raito;
static f32 bill_cut_raito;
static f32 bill_cut_raito2;
static f32 bill_par_scl_raito;
static f32 bill_eff_scl_raito;
static bool billtex_load;
static void billtex_list[UNKNOWN_ARRAY_SIZE];

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
    return 0;
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
    return 0;
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
    return 0;
}

// 0x13201c0
s32 billGetTextureMax(void) {
  struct UnityEngine_Texture_array *pBillTexture;

  if (!pBillTexture)
    return 0;
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
    P2A_HEAD_t__pCopy(0, 0, 0);
    Byte2UInt32(0, 0);
    GetTmxIndex(0, 0);
    BillboardLoadTex(0);
    P2A_ANIMATION_tag__pCopy(0, 0, 0);
    P2A_TEXANIM_tag__pCopy(0, 0, 0);
    return 0;
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
  v5->callname = StringLiteral_12242;
  return v5;
}

// 0x131cee0
billHandle_t *dds3BillboardCopyO(void **hData, s32 bPos, bool tbldata) {
    dds3BillboardCopy(0);
    return 0;
}

// 0x13193e0
billHandle_t *dds3BillboardCreate(s32 type, void *pTex, s32 bPos, char *callname) {
    dds3Billboard_BasicInit(0);
    return 0;
}

// 0x13196e0
void dds3BillboardDelete(void **hData) {
}

// 0x131d000
void dds3BillboardDraw(void **hData) {
}

// 0x131d140
void dds3BillboardDrawOff(void **hData) {
}

// 0x131cc20
billHandle_t *dds3BillboardFileLoad(s32 type, char *pFileName, char *akey) {
  Il2CppObject *v5;
  System_Byte_array *v9;
  System_Byte_array *aTopPtr;

  v5 = pFileName;
  aTopPtr = 0;
  Write_2930400(StringLiteral_12240, v5);
  if (!Contains(v5, StringLiteral_4739, 0))
    v5 = Concat_5224608(v5, StringLiteral_4739);
  sdfDevLoadFileUnity_25061072(v5, &aTopPtr, 0, akey);
  v9 = aTopPtr;
  return dds3BillboardCreate(type, &v9->obj, 0, StringLiteral_12241);
}

// 0x131d320
void *dds3BillboardGeneral(s32 number) {
  struct BillTable_t_array *BillboardTable;
  Il2CppObject *result;
  struct billManager_hG_t_array *hGeneralBillboard;
  struct billHandle_t_o *handle;
  struct dds3BillResource_tag_o *hResource;

  result = dds3BillboardCreate(BillboardTable->m_Items[number]->type, 0, 0, StringLiteral_12243);
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
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
    SDF_VU0__COPYVECTOR_A_TO_C();
    effScreenOffset();
    SDF_VU0__STOREVECTOR(0);
    SDF_VU0__NORMALIZE();
    SDF_VU0__SCALEVECTOR(0);
    SDF_VU0__COPYVECTOR_C_TO_B();
    SDF_VU0__ADDVECTOR();
    sdfAtan2(0, 0);
    return 0;
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
    }
    if (!hBillboard->type)
    {
      MultiBillRes = hBillboard->pNormal->hResource;
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
    dds3BillboardDelete(0);
}

// 0x1318ea0
void dds3BillboardManagerInit(void) {
    LoadFile(0, 0, 0, 0, 0);
    dds3BillboardCreate(0, 0, 0, 0);
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
        while (1)
        {
          pResList->m_Items[v6]->type = condition;
          if (TexNum - 1 == v6)
            break;
          ++v6;
          pResList = (*hBillboard)->pP2A->hResource->pResList;
          if (v6 >= LODWORD(pResList->max_length))
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
      v3->mode = mode;
      return;
    }
    if (type != 1)
    {
      if (v3->type)
        return;
    }
    pP2A = v3->pP2A;
    Anim_n = pP2A->Anim_n;
    if (Anim_n >= 1)
    {
      if (mode == 2)
      {
        v7 = 0;
        pAnim = pP2A->pAnim;
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
        }
      }
      else
      {
        v14 = 0;
        v15 = Anim_n - 1;
        v16 = pP2A->pAnim;
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
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x131da70
void dds3BillboardSetRGBA(billHandle_t **hBillboard, u32 abgr) {
  if (*hBillboard)
    (*hBillboard)->abgr = abgr;
}

// 0x131da80
void dds3BillboardSetRGBAO(void **hData, u32 abgr) {
}

// 0x131d790
void dds3BillboardSetRotate(billHandle_t **hBillboard, f32 rot) {
  if (*hBillboard)
    (*hBillboard)->rot = rot;
}

// 0x131d7a0
void dds3BillboardSetRotateO(void **hData, f32 rot) {
}

// 0x131d8c0
void dds3BillboardSetScale(billHandle_t **hBillboard, f32 x, f32 y) {
}

// 0x131d920
void dds3BillboardSetScaleO(void **hData, f32 x, f32 y) {
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
    GetMesh(0, 0, 0);
    GetUseOne(0);
    GetMainCamera(0);
    GetUseIndexMax(0);
    GetUseIndex(0);
    SetUseIndex(0, 0);
    GetPosition(0);
    SetPosition_20241056(0, 0);
    SetIndexTable(0, 0);
    SetColor_20241296(0, 0);
    SetUvTable_20243232(0, 0);
    GetColor(0);
    sdfSin(0);
    sdfCos(0);
    effGetBlendColor(0);
    GetIndexTable(0);
    SetMatTexture(0, 0);
    GetUvTable(0);
}

// 0x131aab0
void dds3Billboard_BasicInit(billHandle_t **pBasic) {
}

// 0x131abb0
billHandle_t *dds3Billboard_NormalCreate(void *pTex, s32 bPos, bool pCopy, s32 billno) {
    billGetTexture(0);
    BillboardLoadTex(0);
    return 0;
}

// 0x131af00
void dds3Billboard_NormalDelete(void **hData) {

}

// 0x131af40
void dds3Billboard_NormalDraw(void **hData) {
    dds3BillboardTagLink(0, 0, 0);
}

// 0x131c340
dds3BillResource_tag *dds3Billboard_P2AAnimDraw(dds3Billboard_P2A_tag3 **pP2A, dds3BillAnim_tag **pBillAnim) {
    return 0;
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
}

// 0x131c6f0
void dds3Billboard_P2ADraw(void **hData) {
    dds3Billboard_P2AAnimDraw(0, 0);
    effColorMultiply(0, 0);
    dds3BillboardTagLink(0, 0, 0);
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
      Write(StringLiteral_12237, 0);
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
          else          dds3Billboard_P2ASetAnim(&hBillAnimRes, v30, &pAnim->m_Items[v25]);
          v33 = (*pP2A)->pAnim;
          v35 = v33->m_Items[v25];
          v35->key = -*(*v28 + 18LL);
          ++v25;
        }
        while (v25 < v9->times);
      }
      if ((v9->attr & 0x100) == 0)
    }
    else if ((v9->attr & 0xC0) != 0)
    {
      Write(StringLiteral_12238, 0);
      (*pP2A)->mode = v9->attr;
      (*pP2A)->number = number;
      (*pP2A)->Anim_n = 2;
      v13 = (*pP2A)->pAnim;
      dds3Billboard_P2ASetAnim(&hBillAnimRes, number, v13->m_Items);
      v16 = (*pP2A)->pAnim;
      v17 = number + 1;
      dds3Billboard_P2ASetAnim(&hBillAnimRes, v17, &v16->m_Items[1]);
      if ((v9->attr & 0x100) == 0)
    }
    else
    {
      (*pP2A)->mode = 0;
      (*pP2A)->number = number;
      (*pP2A)->Anim_n = 1;
      v37 = (*pP2A)->pAnim;
      dds3Billboard_P2ASetAnim(&hBillAnimRes, number, v37->m_Items);
      if ((v9->attr & 0x100) == 0)
    }
    Write(StringLiteral_12239, 0);
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
    GetUseOne(0);
    GetUseIndex(0);
    GetUseIndexMax(0);
    GetPosition(0);
    SetPosition_20241056(0, 0);
    SetIndexTable(0, 0);
    SetColor_20241296(0, 0);
    SetUvTable_20243232(0, 0);
    GetColor(0);
    sdfSin(0);
    sdfCos(0);
    effGetBlendColor(0);
    GetIndexTable(0);
    GetUvTable(0);
    SetMatTexture(0, 0);
    SetUseIndex(0, 0);
}

// 0x131e6d0
dds3P2APolygon_tag *dds3P2APolygonCopy(void **hData, s32 bPos, bool tbldata) {
    dds3BillboardCopy(0);
    sdfMatSetConstant(0, 0);
    sdfMatSetDiffuse(0, 0);
    sdfMatSetAmbient(0, 0);
    sdfMatSetSpecular(0, 0);
    SDF_VU0__STOREIDENTITY(0);
    return 0;
}

// 0x131e5c0
dds3P2APolygon_tag *dds3P2APolygonCreate(void **hData, s32 bPos, bool tbldata) {
  dds3P2APolygon_tag_o *v6;
  Il2CppObject *v9;
  u64 *v10;

  v6 = Allocate(dds3P2APolygon_tag);
  dds3P2APolygon_tag___ctor(v6);
  v9 = *hData;
  v6->hBillboard = dds3BillboardCreate(1, v9, bPos, StringLiteral_12244);
  v10 = Allocate(sdfMat_t);
  sdfMat_t___ctor(v10);
  v6->pMat = v10;
  sdfMatSetConstant(v10, 1.0);
  SDF_VU0__STOREIDENTITY(&v6->rot);
  return v6;
}

// 0x131e8a0
void dds3P2APolygonDelete(void **hData) {
    dds3BillboardDelete(0);
}

// 0x131f210
void dds3P2APolygonDraw(void **hData) {
    dds3P2APolygonGetResource(0, 0);
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__LOADMATRIX_B(0);
    MultMatrixNoArg();
    SDF_VU0__STOREMATRIX(0);
    sdfSin(0);
    sdfCos(0);
    GetMesh(0, 0, 0);
    SetPosition_20241056(0, 0);
    SetColor_20241296(0, 0);
    SetIndexTable(0, 0);
    effGetBlendColor(0);
    GetPosition(0);
    GetColor(0);
    GetTexture(0);
    SetMatTexture(0, 0);
    SetUvTable_20243232(0, 0);
}

// 0x131efe0
void dds3P2APolygonGetResource(dds3P2APolygon_tag **hP2APoly, dds3P2APolygonResource_tag **pP2APolyRes) {
    dds3Billboard_P2AAnimDraw(0, 0);
}

// 0x131eeb0
void dds3P2APolygonSetDirection(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x131e9c0
void dds3P2APolygonSetPosition(void **hData, sdfVector4_t pPos) {
    SDF_VU0__COPYVECTOR(0, (sdfVector4_t){0});
}

// 0x131ed90
void dds3P2APolygonSetRGBA(void **hData, u32 abgr) {
}

// 0x131ec60
void dds3P2APolygonSetRotateMatrix(void **hData, sdfMatrix4_t *pMatrix) {
    SDF_VU0__LOADMATRIX(0);
    SDF_VU0__STOREMATRIX(0);
}

// 0x131eb10
void dds3P2APolygonSetScale(void **hData, f32 scale) {
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
