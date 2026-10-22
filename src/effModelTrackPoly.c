#include "types.h"

typedef struct Eff_ModelTrackPolyABGR_t Eff_ModelTrackPolyABGR_t;
typedef struct Eff_ModelTrackPolyParam_t Eff_ModelTrackPolyParam_t;
typedef struct Eff_ModelTrackPoly_tag Eff_ModelTrackPoly_tag;
typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct XRD773Unity_GraphicManager_CommonObject XRD773Unity_GraphicManager_CommonObject;
typedef struct dds3HermitianTrackPoly_tag dds3HermitianTrackPoly_tag;
typedef struct dds3ModelHandle_t dds3ModelHandle_t;
typedef struct effMTPolyListHandle_t effMTPolyListHandle_t;
typedef struct effSwordTrackParams_t effSwordTrackParams_t;
typedef struct sdf3DPrimPolyParm_t sdf3DPrimPolyParm_t;
typedef struct sdfMat_t sdfMat_t;
typedef struct sdfModelRootNode_t sdfModelRootNode_t;

static sdf3DPrimPolyParm_t *HTP_PrimPolyParm;
static s32 id_Shift;
static s32 id_ColShift;

void Eff_HermitianSpline(sdfVector4_t **pVertex, f32 percentage);
Eff_ModelTrackPoly_tag *Eff_ModelTrackPolyCreate(Eff_ModelTrackPolyParam_t *pParam);
void Eff_ModelTrackPolyDelete(Eff_ModelTrackPoly_tag **hMTPoly);
void Eff_ModelTrackPolyGetMarkPosition(Eff_ModelTrackPoly_tag *hMTPoly);
void Eff_ModelTrackPolyReset(Eff_ModelTrackPoly_tag **hMTPoly);
s32 Eff_ModelTrackPoly_DANTE_Check(dds3ModelHandle_t *hModel);
sdfColor_t **GetColor(XRD773Unity_CommonMesh *this);
s32 **GetIndexTable(XRD773Unity_CommonMesh *this);
XRD773Unity_CommonMesh *GetMesh(XRD773Unity_GraphicManager *this, s32 index, bool outlinechk);
sdfVector3_t **GetPosition(XRD773Unity_CommonMesh *this);
bool MeshDraw(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t blend_col);
void SDF_VU0__ADDVECTOR_A_C(void);
void SDF_VU0__ADDVECTOR_C_A(void);
void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__COPYVECTOR_A_TO_C(void);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SDF_VU0__LOADVECTOR_B(sdfVector4_t p);
void SDF_VU0__MULVECTOR(void);
void SDF_VU0__STOREVECTOR(sdfVector4_t *p);
void SDF_VU0__SUBVECTOR(void);
void SetActive(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetAutoHide(XRD773Unity_GraphicManager_CommonObject *this, bool act);
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col);
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx);
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos);
dds3HermitianTrackPoly_tag *dds3HermitianTrackPolyCreate(u32 face, u32 split);
void dds3HermitianTrackPolyDraw(dds3HermitianTrackPoly_tag **hPoly);
void dds3HermitianTrackPolyGetVertex(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t *pVertex0, sdfVector4_t *pVertex1, s32 frame);
void dds3HermitianTrackPolySetVC(dds3HermitianTrackPoly_tag **hPoly, Eff_ModelTrackPolyABGR_t *pABGR);
void dds3HermitianTrackPolySetVertex(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t **pVertex);
void dds3HermitianTrackPolySetVertexSub(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t **pVertex);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
Eff_ModelTrackPoly_tag *effSwordTrackCreate(effSwordTrackParams_t *pParams);
void effSwordTrackDelete(Eff_ModelTrackPoly_tag **hSwordTrack);
void effSwordTrackDraw(Eff_ModelTrackPoly_tag **hSwordTrack);
void effSwordTrackPolygon2DDraw(Eff_ModelTrackPoly_tag **hSwordTrack);
void effSwordTrackRecord(Eff_ModelTrackPoly_tag **hSwordTrack);
s32 mdlGetMajorNum(dds3ModelHandle_t **aHandle);
s32 mdlGetMinorNum(dds3ModelHandle_t **aHandle);
s32 mdlGetMotionFrameForUnity(void *obj);
void pMeshDelete(dds3HermitianTrackPoly_tag **hPoly);
sdfMat_t *sdfMatNew(void);
void sdfMatSetConstant(sdfMat_t *aMat, f32 aRatio);
s32 sdfModelGetMarkPosUnity(sdfModelRootNode_t *aRoot, s32 aId);

// 0x16bf290
u32 DDS3EFFECT_RGBA(u32 r, u32 g, u32 b, u32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x16c1200
void Eff_HermitianSpline(sdfVector4_t **pVertex, f32 percentage) {
  u64 *v4;
  UnityEngine_Vector4_o v35;
  UnityEngine_Vector4_o v36;
  UnityEngine_Vector4_o p;

  *&p.x = 0;
  *&p.z = 0;
  *&v36.x = 0;
  *&v36.z = 0;
  *&v35.x = 0;
  *&v35.z = 0;
  v4 = NewSpecific(UnityEngine_Vector4, 4u);
  sub_854930(&v35, 0);
  sub_854710(&v35, 0);
  sub_854930(&v35, 1u);
  sub_854930(&v35, 2u);
  SDF_VU0__LOADVECTOR(pVertex->m_Items[1]);
  SDF_VU0__LOADVECTOR_B(pVertex->m_Items[0]);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR(pVertex->m_Items[2]);
  SDF_VU0__LOADVECTOR_B(pVertex->m_Items[1]);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__LOADVECTOR_B(v35);
  SDF_VU0__MULVECTOR();
  SDF_VU0__STOREVECTOR(&p);
  SDF_VU0__LOADVECTOR(pVertex->m_Items[2]);
  SDF_VU0__LOADVECTOR_B(pVertex->m_Items[1]);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR(pVertex->m_Items[3]);
  SDF_VU0__LOADVECTOR_B(pVertex->m_Items[2]);
  SDF_VU0__SUBVECTOR();
  SDF_VU0__ADDVECTOR_A_C();
  SDF_VU0__LOADVECTOR_B(v35);
  SDF_VU0__MULVECTOR();
  SDF_VU0__STOREVECTOR(&v36);
  sub_854930((v4 + 4), 0);
  sub_854710((v4 + 4), 0);
  sub_854930((v4 + 4), 1u);
  sub_854930((v4 + 4), 2u);
  sub_854930((v4 + 6), 0);
  sub_854710((v4 + 6), 0);
  sub_854930((v4 + 6), 1u);
  sub_854930((v4 + 6), 2u);
  sub_854930((v4 + 8), 0);
  sub_854710((v4 + 8), 0);
  sub_854930((v4 + 8), 1u);
  sub_854930((v4 + 8), 2u);
  sub_854930((v4 + 10), 0);
  sub_854710((v4 + 10), 0);
  sub_854930((v4 + 10), 1u);
  sub_854930((v4 + 10), 2u);
  SDF_VU0__LOADVECTOR(*(v4 + 2), 0);
  SDF_VU0__LOADVECTOR_B(pVertex->m_Items[1]);
  SDF_VU0__MULVECTOR();
  SDF_VU0__COPYVECTOR_A_TO_C();
  SDF_VU0__LOADVECTOR(*(v4 + 3), 0);
  SDF_VU0__LOADVECTOR_B(p);
  SDF_VU0__MULVECTOR();
  SDF_VU0__ADDVECTOR_C_A();
  SDF_VU0__LOADVECTOR(*(v4 + 4), 0);
  SDF_VU0__LOADVECTOR_B(v36);
  SDF_VU0__MULVECTOR();
  SDF_VU0__ADDVECTOR_C_A();
  SDF_VU0__LOADVECTOR(*(v4 + 5), 0);
  SDF_VU0__LOADVECTOR_B(pVertex->m_Items[2]);
  SDF_VU0__MULVECTOR();
  SDF_VU0__ADDVECTOR_A_C();
}

// 0x16c2540
void Eff_ModelTrackPolyColorSet(Eff_ModelTrackPoly_tag **hMTPoly, u32 abgr) {
  (*hMTPoly)->hPoly->abgr = abgr;
}

// 0x16c1a70
Eff_ModelTrackPoly_tag *Eff_ModelTrackPolyCreate(Eff_ModelTrackPolyParam_t *pParam) {
  Eff_ModelTrackPoly_tag_o *v3;
  dds3ModelHandle_t_o *hModel;
  u64 *v8;
  u64 *v9;
  u64 v12;
  s32 motionMinorNum;
  s32 v15;
  struct Eff_ModelTrackPolyParam_t_o *param;
  struct Eff_ModelTrackPolyParam_t_o *v18;
  u32 face;
  u32 split;
  Eff_ModelTrackPoly_tag_o *v22;

  v3 = Allocate(Eff_ModelTrackPoly_tag);
  Eff_ModelTrackPoly_tag___ctor(v3);
  v3->param = pParam;
  hModel = pParam->hModel;
  else if (Eff_ModelTrackPoly_DANTE_Check(pParam->hModel))
  {
LABEL_6:
    v8 = Allocate(effSwordTrackParams_t);
    effSwordTrackParams_t___ctor(v8);
    v8[2] = pParam->hModel;
    v9 = NewSpecific(uint, 2u);
    v8[3] = v9;
    *(v9 + 8) = 101;
    v12 = v8[3];
    *(v12 + 36) = 100;
    v8[4] = 0xC800000008LL;
    *(v8 + 14) = 1048576000;
    motionMinorNum = v3->param->hModel->motionMinorNum;
    if (motionMinorNum == 9)
    {
      v8[5] = 0x3D4CCCCD0000000ALL;
      *(v8 + 13) = -1061109568;
      *(v8 + 9) = 69;
      v15 = 1036831949;
    }
    else if (motionMinorNum == 10)
    {
      v8[5] = 0x3CCCCCCD00000006LL;
      *(v8 + 13) = -924260120;
      *(v8 + 9) = 113;
      v15 = 1034147594;
    }
    else if (motionMinorNum == 16)
    {
      v8[5] = 0x3D4CCCCD0000000ALL;
      *(v8 + 13) = -1195853640;
      v15 = 1041865114;
    }
    else if (motionMinorNum == 17)
    {
      v8[5] = 0x3D4CCCCD00000008LL;
      *(v8 + 13) = -1197959016;
      *(v8 + 9) = 44;
      v15 = 1045220557;
    }
    else
    {
      if (motionMinorNum == 18)
      {
        v8[5] = 0x3D4CCCCD0000000BLL;
        *(v8 + 13) = -926365496;
      }
      else
      {
        v8[5] = 0x3CCCCCCD00000006LL;
        *(v8 + 13) = -1195853640;
        *(v8 + 9) = 27;
      }
      v15 = 1039516303;
    }
    *(v8 + 14) = v15;
    *(v8 + 12) = 12;
    v22 = effSwordTrackCreate(v8);
    v22->param = pParam;
    v22->hPoly->abgr = *(v8 + 13);
    v22->param_dante->sub_alpha_in = 16;
    v3 = v22;
    v22->param_dante->sub_alpha_out = 0;
    return v3;
  }
  param = v3->param;
  v3->frame = 0;
  param->split = 6;
  v18 = v3->param;
  face = v18->face;
  split = v18->split;
  v3->hPoly = dds3HermitianTrackPolyCreate(face, split);
  dds3HermitianTrackPolySetVC(&v3->hPoly, pParam->abgr);
  v3->hPoly->blend = pParam->blend;
  return v3;
}

// 0x16c1f60
void Eff_ModelTrackPolyDelete(Eff_ModelTrackPoly_tag **hMTPoly) {
  dds3ModelHandle_t_o *hModel;
  dds3HermitianTrackPoly_tag_o **p_hPoly;
  dds3HermitianTrackPoly_tag_o **v7;
  dds3HermitianTrackPoly_tag_o **v9;

  hModel = (*hMTPoly)->param->hModel;
  if (Eff_ModelTrackPoly_DANTE_Check(hModel))
  {
    p_hPoly = &(*hMTPoly)->hPoly;
    pMeshDelete(p_hPoly);
    effSwordTrackDelete(hMTPoly);
    (*hMTPoly)->hPoly = 0;
  }
  v7 = &(*hMTPoly)->hPoly;
  if (*v7)
  {
    pMeshDelete(v7);
    v9 = &(*hMTPoly)->hPoly;
    pMeshDelete(v9);
  }
}

// 0x16c25d0
void Eff_ModelTrackPolyDraw(Eff_ModelTrackPoly_tag **hMTPoly) {
  dds3ModelHandle_t_o *hModel;
  s32 v4;
  Eff_ModelTrackPolyParam_t_Fields *p_fields;
  s32 MinorNum;
  Eff_ModelTrackPoly_tag_o *v9;
  struct effSwordTrackParams_t_o *param_dante;
  s32 motionMinorNum;
  u32 frame;
  s32 v13;
  UnityEngine_GameObject_o *modelobj;
  s32 MotionFrameForUnity;
  Eff_ModelTrackPoly_tag_o *v17;
  f32 v18;
  struct Eff_ModelTrackPolyParam_t_o *param;
  struct effSwordTrackParams_t_o *v20;
  s32 v21;
  s32 v22;
  struct effSwordTrackParams_t_o *v23;
  s32 v24;
  struct dds3HermitianTrackPoly_tag_o *v25;
  u32 abgr;
  dds3HermitianTrackPoly_tag_o **p_hPoly;
  struct dds3HermitianTrackPoly_tag_o *v28;
  struct effSwordTrackParams_t_o *v29;
  u64 v30;
  u32 v31;
  f32 v32;
  struct effSwordTrackParams_t_o *v33;
  s32 v34;
  s32 v35;
  f32 v36;
  struct effSwordTrackParams_t_o *v37;
  u32 v38;
  struct effSwordTrackParams_t_o *v39;
  f32 v40;
  f32 v41;
  struct dds3HermitianTrackPoly_tag_o *v42;
  struct effSwordTrackParams_t_o *v43;
  u64 v44;
  u32 v45;
  f32 v46;
  f32 v47;
  f32 v48;
  struct dds3HermitianTrackPoly_tag_o *hPoly;
  struct effSwordTrackParams_t_o *v50;
  u64 v51;
  u32 v52;
  f32 v53;
  f32 v54;
  f32 v55;
  s32 v56;
  struct effSwordTrackParams_t_o *v57;
  u32 v58;
  u64 v59;
  Eff_ModelTrackPoly_tag_o *v60;
  u32 v61;
  f32 v62;
  struct effSwordTrackParams_t_o *v63;
  f32 v64;
  f32 v65;
  Eff_ModelTrackPoly_tag_o *hSwordTrack;

  hSwordTrack = 0;
  if ((*hMTPoly)->hPoly)
  {
    hModel = (*hMTPoly)->param->hModel;
    v4 = Eff_ModelTrackPoly_DANTE_Check(hModel);
    p_fields = &(*hMTPoly)->param->fields;
    if (v4)
    {
      MinorNum = mdlGetMinorNum(&p_fields->hModel);
      v9 = *hMTPoly;
      hSwordTrack = v9;
      param_dante = v9->param_dante;
      motionMinorNum = param_dante->hModel->motionMinorNum;
      if (motionMinorNum != 9)
      {
        if (motionMinorNum == 10)
        {
          frame = v9->frame;
          if (frame >= 0x1E)
          {
            if (frame > 0x2C)
            {
              if (frame > 0x34)
              {
                if (frame > 0x58)
                {
                  if (frame > 0x68)
                  {
                    param_dante->frame_s = 105;
                    v13 = 116;
                  }
                  else
                  {
                    param_dante->frame_s = 89;
                    v13 = 101;
                  }
                }
                else
                {
                  param_dante->frame_s = 53;
                  v13 = 66;
                }
              }
              else
              {
                param_dante->frame_s = 45;
                v13 = 50;
              }
            }
            else
            {
              param_dante->frame_s = 30;
              v13 = 36;
            }
            v9->param_dante->frame_e = v13;
            v58 = v9->frame;
            if (v58 == 101 || v58 == v9->param_dante->frame_s)
            {
              v9->slide_par = 1.0;
              v9->hPoly->count = 0;
              v9->hPoly->current = 2;
            }
            effSwordTrackDraw(&hSwordTrack);
            v60 = hSwordTrack;
            v61 = hSwordTrack->frame;
            if (v61 > 0x70 || v61 > hSwordTrack->param_dante->frame_e)
            {
              v62 = hSwordTrack->slide_par + -0.2;
              hSwordTrack->slide_par = v62;
              if (v62 < 0.0)
                v60->slide_par = 0.0;
            }
            v63 = v60->param_dante;
            LODWORD(v59) = v63->frame_e;
            v64 = v61;
            v65 = v59;
            if (v64 < v65)
            {
              v63->sub_alpha_in = 16;
              v60->param_dante->sub_alpha_out = 0;
              return;
            }
            v63->sub_alpha_in = 32;
            v57 = v60->param_dante;
            goto LABEL_156;
          }
LABEL_78:
          v9->frame = frame + 1;
          return;
        }
        switch (motionMinorNum)
        {
          case 16:
            frame = v9->frame;
            if (frame < 0xC)
              goto LABEL_78;
            if (frame > 0x25)
            {
              if (frame > 0x30)
              {
                param_dante->frame_s = 49;
                v33 = v9->param_dante;
                v34 = -1197432672;
                v35 = 200;
              }
              else
              {
                param_dante->frame_s = 38;
                v33 = v9->param_dante;
                v34 = -1196906328;
                v35 = 47;
              }
            }
            else
            {
              param_dante->frame_s = 12;
              v33 = v9->param_dante;
              v34 = -1061635912;
              v35 = 33;
            }
            v33->frame_e = v35;
            v9->param_dante->slide = 0.05;
            hPoly = v9->hPoly;
            v50 = v9->param_dante;
            v50->abgr = v34;
            hPoly->abgr = v34;
            if (v9->frame == v9->param_dante->frame_s)
            {
              v9->slide_par = 1.0;
              v9->hPoly->count = 0;
              v9->hPoly->current = 2;
            }
            effSwordTrackDraw(&hSwordTrack);
            v52 = v9->frame;
            if (v52 >= 0x1C && (v52 < 0x26 || v52 - 45 <= 3))
            {
              v53 = v9->slide_par + -0.2;
              v9->slide_par = v53;
              if (v53 < 0.0)
                v9->slide_par = 0.0;
            }
            v39 = v9->param_dante;
            LODWORD(v51) = v39->frame_e;
            v54 = v52;
            v55 = v51;
            if (v54 < v55)
            {
              if (v52 < 0x31)
                goto LABEL_85;
              v56 = 48;
LABEL_137:
              v39->sub_alpha_in = v56;
              goto LABEL_138;
            }
LABEL_136:
            v56 = 32;
            goto LABEL_137;
          case 17:
            frame = v9->frame;
            if (frame < 0x1F)
              goto LABEL_78;
            param_dante->frame_s = 31;
            v9->param_dante->frame_e = 44;
            effSwordTrackDraw(&hSwordTrack);
            if (v9->frame >= 0x2E)
            {
              v36 = v9->slide_par + -0.1;
              v9->slide_par = v36;
              if (v36 < 0.0)
                v9->slide_par = 0.0;
            }
            v37 = v9->param_dante;
            goto LABEL_77;
          case 18:
            frame = v9->frame;
            if (frame < 0x19)
              goto LABEL_78;
            if (frame > 0x31)
            {
              if (frame > 0x86)
              {
                param_dante->frame_s = 135;
                v23 = v9->param_dante;
                v24 = 154;
              }
              else
              {
                param_dante->frame_s = 50;
                v23 = v9->param_dante;
                v24 = 68;
              }
            }
            else
            {
              param_dante->frame_s = 25;
              v23 = v9->param_dante;
              v24 = 39;
            }
            v23->frame_e = v24;
            v42 = v9->hPoly;
            v43 = v9->param_dante;
            v43->abgr = -926365496;
            v42->abgr = -926365496;
            if (v9->frame == v9->param_dante->frame_s)
            {
              v9->slide_par = 1.0;
              v9->hPoly->count = 0;
              v9->hPoly->current = 2;
            }
            effSwordTrackDraw(&hSwordTrack);
            v45 = v9->frame;
            v37 = v9->param_dante;
            if (v45 - 65 < 4 || v45 > v37->frame_e)
            {
              v46 = v9->slide_par + -0.2;
              v9->slide_par = v46;
              if (v46 < 0.0)
                v9->slide_par = 0.0;
            }
            LODWORD(v44) = v37->frame_e;
            v47 = v45;
            v48 = v44;
            if (v47 >= v48)
            {
              v37->sub_alpha_in = 32;
              goto LABEL_138;
            }
            if (v45 - 51 > 0x11)
            {
              v37->sub_alpha_in = 16;
              goto LABEL_86;
            }
LABEL_77:
            v37->sub_alpha_in = 48;
LABEL_138:
            v57 = v9->param_dante;
LABEL_156:
            v57->sub_alpha_out = 20;
            return;
        }
        v38 = v9->frame;
        if (v38 < 0x13)
        {
          v9->frame = v38 + 1;
          return;
        }
        effSwordTrackDraw(&hSwordTrack);
        v31 = v9->frame;
        if (v31 < 0x1C)
        {
LABEL_84:
          v39 = v9->param_dante;
          LODWORD(v30) = v39->frame_e;
          v40 = v31;
          v41 = v30;
          if (v40 < v41)
          {
LABEL_85:
            v39->sub_alpha_in = 16;
LABEL_86:
            v9->param_dante->sub_alpha_out = 0;
            return;
          }
          goto LABEL_136;
        }
LABEL_64:
        v32 = v9->slide_par + -0.2;
        v9->slide_par = v32;
        if (v32 < 0.0)
          v9->slide_par = 0.0;
        goto LABEL_84;
      }
      frame = v9->frame;
      if (frame < 0x16)
        goto LABEL_78;
      if (frame > 0x24)
      {
        if ((MinorNum - 339) < 3)
          goto LABEL_54;
        param_dante->frame_s = 37;
        v9->param_dante->frame_e = 46;
        v20 = v9->param_dante;
        v21 = -1061109568;
        v22 = 1041865114;
      }
      else
      {
        param_dante->frame_s = 22;
        v9->param_dante->frame_e = 33;
        v20 = v9->param_dante;
        v21 = -1063214944;
        v22 = 1028443341;
      }
      LODWORD(v20->slide) = v22;
      v28 = v9->hPoly;
      v29 = v9->param_dante;
      v29->abgr = v21;
      v28->abgr = v21;
LABEL_54:
      if (v9->frame == v9->param_dante->frame_s)
      {
        v9->slide_par = 1.0;
        v9->hPoly->count = 0;
        v9->hPoly->current = 2;
      }
      effSwordTrackDraw(&hSwordTrack);
      v31 = v9->frame;
      if (v31 < 0x1F || v31 - 37 < 0xC)
        goto LABEL_84;
      goto LABEL_64;
    }
    modelobj = p_fields->hModel->modelRoot->modelobj;
    MotionFrameForUnity = mdlGetMotionFrameForUnity(modelobj);
    v17 = *hMTPoly;
    v18 = (MotionFrameForUnity + 1);
    param = (*hMTPoly)->param;
    if (param->frame_s > v18)
    {
      Eff_ModelTrackPolyReset(hMTPoly);
      return;
    }
    if (param->frame_e >= v18)
    {
      if (v17->frame % param->record)
        goto LABEL_42;
      Eff_ModelTrackPolyGetMarkPosition(v17);
    }
    else
    {
      v25 = v17->hPoly;
      abgr = v25->abgr;
      if (!HIBYTE(abgr))
        goto LABEL_42;
      v25->abgr = abgr - 0x20000000;
    }
    v17 = *hMTPoly;
LABEL_42:
    p_hPoly = &v17->hPoly;
    dds3HermitianTrackPolyDraw(p_hPoly);
    ++(*hMTPoly)->frame;
  }
}

// 0x16c2550
void Eff_ModelTrackPolyDrawOnly(Eff_ModelTrackPoly_tag **hMTPoly) {
  struct dds3HermitianTrackPoly_tag_o **p_hPoly;
  dds3HermitianTrackPoly_tag_o **v4;

  p_hPoly = &(*hMTPoly)->hPoly;
  else
  {
    v4 = p_hPoly;
  }
  dds3HermitianTrackPolyDraw(v4);
}

// 0x16c2350
void Eff_ModelTrackPolyGetMarkPosition(Eff_ModelTrackPoly_tag *hMTPoly) {
  u64 *v3;
  struct Eff_ModelTrackPolyParam_t_o *param;
  struct System_UInt32_array *mark;
  struct dds3ModelHandle_t_o *hModel;
  sdfModelRootNode_t_o *modelRoot;
  u64 *v9;
  s32 v11;
  struct System_UInt32_array *v13;
  dds3HermitianTrackPoly_tag_o **p_hPoly;

  v3 = NewSpecific(UnityEngine_Vector4, 2u);
  param = hMTPoly->param;
  hModel = param->hModel;
  mark = param->mark;
  modelRoot = hModel->modelRoot;
  v9 = v3;
  v11 = mark->m_Items[0];
  sdfModelGetMarkPosUnity(modelRoot, v11);
  SDF_VU0__STOREVECTOR(v9 + 2);
  v13 = hMTPoly->param->mark;
  sdfModelGetMarkPosUnity(hModel->modelRoot, v13->m_Items[1]);
  SDF_VU0__STOREVECTOR(v9 + 3);
  p_hPoly = &hMTPoly->hPoly;
  dds3HermitianTrackPolySetVertex(p_hPoly, v9);
}

// 0x16c33e0
void Eff_ModelTrackPolyListColorSet(effMTPolyListHandle_t **hMTPolyList, u32 index, u32 abgr) {
  struct Eff_ModelTrackPoly_tag_array *hPolyList;
  s64 v8;

  hPolyList = (*hMTPolyList)->hPolyList;
  else
  {
    v8 = index;
    if (LODWORD(hPolyList->max_length) <= index)
      goto LABEL_6;
  }
  hPolyList->m_Items[v8]->hPoly->abgr = abgr;
}

// 0x16c2fc0
effMTPolyListHandle_t *Eff_ModelTrackPolyListCreate(Eff_ModelTrackPolyParam_t *pParam, u32 number) {
  effMTPolyListHandle_t_o *v5;
  struct Eff_ModelTrackPoly_tag_array *v6;
  u32 *hPolyList;
  u64 v9;
  s64 v10;
  s64 *v12;

  v5 = Allocate(effMTPolyListHandle_t);
  effMTPolyListHandle_t___ctor(v5);
  v6 = NewSpecific(Eff_ModelTrackPoly_tag, number);
  v5->hPolyList = v6;
  v5->number = number;
  v5->hMem = 0;
  if (number)
  {
    hPolyList = v6;
    v9 = 0;
    v10 = number - 1LL;
      goto LABEL_7;
LABEL_8:
    v12 = Eff_ModelTrackPolyCreate(pParam);
    if (!v12)
      goto LABEL_12;
LABEL_9:
    while (1)
    {
LABEL_12:
      *&hPolyList[2 * v9 + 8] = v12;
      if (v10 == v9)
        break;
      hPolyList = v5->hPolyList;
      ++v9;
        goto LABEL_8;
LABEL_7:
        goto LABEL_8;
      v12 = Eff_ModelTrackPolyCreate(pParam);
      if (v12)
        goto LABEL_9;
    }
  }
  return v5;
}

// 0x16c3130
void Eff_ModelTrackPolyListDelete(effMTPolyListHandle_t **hMTPolyList) {
  s64 number;
  u64 v4;
  s64 v5;
  s64 v6;
  struct Eff_ModelTrackPoly_tag_array *hPolyList;

  number = (*hMTPolyList)->number;
  if (number)
  {
    v4 = 0;
    v5 = number - 1;
    v6 = 32;
    hPolyList = (*hMTPolyList)->hPolyList;
      goto LABEL_7;
LABEL_8:
    if (v4 >= LODWORD(hPolyList->max_length))
    {
LABEL_9:
    }
    while (1)
    {
      Eff_ModelTrackPolyDelete((hPolyList + v6));
      if (v5 == v4)
        break;
      ++v4;
      v6 += 8;
      hPolyList = (*hMTPolyList)->hPolyList;
        goto LABEL_8;
LABEL_7:
        goto LABEL_8;
      if (v4 >= LODWORD(hPolyList->max_length))
        goto LABEL_9;
    }
  }
}

// 0x16c34b0
void Eff_ModelTrackPolyListDrawOnly(effMTPolyListHandle_t **hMTPolyList) {
  s64 number;
  s64 v4;
  u64 v5;
  struct Eff_ModelTrackPoly_tag_array *hPolyList;
  Il2CppClass **v9;
  dds3HermitianTrackPoly_tag_o **p_bits;

  number = (*hMTPolyList)->number;
  if (number)
  {
    v4 = number - 1;
    v5 = 0;
    hPolyList = (*hMTPolyList)->hPolyList;
      goto LABEL_7;
    while (1)
    {
LABEL_8:
      if (v5 >= LODWORD(hPolyList->max_length))
      {
LABEL_9:
      }
      while (1)
      {
        v9 = &hPolyList->obj.klass + v5;
        p_bits = &v9[4]->_1.byval_arg.bits;
        else
        {
          dds3HermitianTrackPolyDraw(p_bits);
          if (v4 == v5)
            return;
        }
        ++v5;
        hPolyList = (*hMTPolyList)->hPolyList;
          goto LABEL_8;
LABEL_7:
          break;
        if (v5 >= LODWORD(hPolyList->max_length))
          goto LABEL_9;
      }
    }
  }
}

// 0x16c34a0
void Eff_ModelTrackPolyListDrawOnlyOff(effMTPolyListHandle_t *hMTPolyList) {
  ;
}

// 0x16c3330
void Eff_ModelTrackPolyListReset(effMTPolyListHandle_t **hMTPolyList, u32 index) {
  struct Eff_ModelTrackPoly_tag_array *hPolyList;
  s64 v6;

  hPolyList = (*hMTPolyList)->hPolyList;
  else
  {
    v6 = index;
    if (LODWORD(hPolyList->max_length) <= index)
      goto LABEL_6;
  }
  Eff_ModelTrackPolyReset(&hPolyList->m_Items[v6], *&index);
}

// 0x16c3220
void Eff_ModelTrackPolyListVertexSet(effMTPolyListHandle_t **hMTPolyList, u32 index, sdfVector4_t **pVertex) {
  struct Eff_ModelTrackPoly_tag_array *hPolyList;
  s64 v8;
  dds3HermitianTrackPoly_tag_o **p_hPoly;

  hPolyList = (*hMTPolyList)->hPolyList;
  else
  {
    v8 = index;
    if (LODWORD(hPolyList->max_length) <= index)
      goto LABEL_6;
  }
  p_hPoly = &hPolyList->m_Items[v8]->hPoly;
  dds3HermitianTrackPolySetVertex(p_hPoly, pVertex, pVertex);
}

// 0x16c2170
void Eff_ModelTrackPolyReset(Eff_ModelTrackPoly_tag **hMTPoly) {
  dds3ModelHandle_t_o *hModel;
  struct dds3HermitianTrackPoly_tag_o **p_hPoly;

  hModel = (*hMTPoly)->param->hModel;
  if (!Eff_ModelTrackPoly_DANTE_Check((*hMTPoly)->param->hModel))
    goto LABEL_12;
LABEL_6:
LABEL_10:
  (*hMTPoly)->frame = 0;
  (*hMTPoly)->slide_par = 1.0;
LABEL_13:
  p_hPoly = &(*hMTPoly)->hPoly;
  (*p_hPoly)->count = 0;
  (*p_hPoly)->current = 2;
  (*p_hPoly)->abgr = -2139062144;
}

// 0x16c24c0
void Eff_ModelTrackPolyVertexSet(Eff_ModelTrackPoly_tag **hMTPoly, sdfVector4_t **pVertex) {
  dds3HermitianTrackPoly_tag_o **p_hPoly;

  p_hPoly = &(*hMTPoly)->hPoly;
  dds3HermitianTrackPolySetVertex(p_hPoly, pVertex);
}

// 0x16bf2a0
s32 Eff_ModelTrackPoly_DANTE_Check(dds3ModelHandle_t *hModel) {
  s32 MinorNum;
  dds3ModelHandle_t_o *aHandle;

  aHandle = hModel;
  if (mdlGetMajorNum(&aHandle) != 1)
    return 0;
  MinorNum = mdlGetMinorNum(&aHandle);
  return MinorNum == 192 || (MinorNum - 339) < 3;
}

// 0x16bf720
bool MeshDraw(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t blend_col) {
  dds3HermitianTrackPoly_tag_o *v4;
  XRD773Unity_CommonMesh_o *pMesh;
  XRD773Unity_GraphicManager_o *Instance;
  UnityEngine_Object_o *gameObject;
  System_String_o *v9;
  System_String_o *v10;
  UnityEngine_Object_o *sharedMaterial;
  System_String_o *name;
  Il2CppObject *v14;
  u64 point;
  s64 count;
  UnityEngine_Vector3_array *v17;
  UnityEngine_Color_array *v18;
  UnityEngine_Vector3_array *Position;
  UnityEngine_Color_array *Color;
  dds3HermitianTrackPoly_tag_o *v22;
  s32 current;
  s32 v24;
  u32 v25;
  UnityEngine_Color_array *v26;
  u64 v27;
  s64 v28;
  f32 *p_z;
  f32 *p_a;
  struct UnityEngine_Vector4_array *pVertex;
  s64 v32;
  f32 *v34;
  f32 v35;
  f32 v36;
  f32 v37;
  f32 v38;
  f32 *p_SDF_CC_NDNM;
  f32 v42;
  f32 v43;
  f32 v44;
  struct System_UInt32_array *pVC;
  u32 v48;
  f32 v49;
  f32 v50;
  f32 v51;
  f32 v52;
  f32 v53;
  f32 v54;
  f32 v55;
  s32 v57;
  s32 v58;
  u32 v59;
  System_Int32_array *v60;
  System_Int32_array *IndexTable;
  u64 v62;
  s32 v63;
  s32 *v64;
  u64 v65;
  u64 max_length_low;
  s32 v69;
  s32 v71;
  s32 v73;
  s32 v75;
  u32 v77;
  il2cpp_array_size_t max_length;
  bool v79;
  s64 v80;
  XRD773Unity_CommonMesh_o *v83;
  s32 v84;
  UnityEngine_Vector3_o v85;
  UnityEngine_Vector3_o v86;
  UnityEngine_Color_o v88;
  UnityEngine_Vector3_o v89;
  UnityEngine_Vector4_o v90;

  v4 = *hPoly;
  if (*hPoly && v4->count >= 4)
  {
    pMesh = v4->pMesh;
    if (op_Equality(pMesh, 0, 0))
    {
      {
      }
      Instance = get_Instance();
      pMesh = GetMesh(Instance, (*hPoly)->blend, 0, 0);
      gameObject = get_gameObject(pMesh);
      v9 = sub_8185A0(&(*hPoly)->blend);
      v10 = Concat_5224608("effModelTrackPoly.MeshDraw:", v9);
      set_name(gameObject, v10);
      SetAutoHide(pMesh, 1);
      (*hPoly)->pMesh = pMesh;
      sharedMaterial = get_sharedMaterial(pMesh->_renderer);
      name = get_name(sharedMaterial);
      v14 = Concat_5224608("mesh._renderer.sharedMaterial:", name);
      Log(v14, 0);
    }
    point = (*hPoly)->point;
    count = (*hPoly)->count;
    if (point > SLODWORD(GetPosition(pMesh)->max_length))
    {
      v17 = NewSpecific(UnityEngine_Vector3, point);
      SetPosition_20241056(pMesh, v17);
      v18 = NewSpecific(UnityEngine_Color, point);
      SetColor_20241296(pMesh, v18);
    }
    Position = GetPosition(pMesh);
    v83 = pMesh;
    Color = GetColor(pMesh, 0);
    v22 = *hPoly;
    current = (*hPoly)->current;
    if (current < 0)
      v24 = point;
    else
      v24 = 0;
    v84 = count;
    if (count >= 1)
    {
      v25 = v24 + current;
      v26 = Color;
      v27 = 0;
      v28 = count - 1;
      p_z = &Position->m_Items[0].z;
      p_a = &Color->m_Items[0].a;
      if ((v25 - count) >= 0)
        v25 -= count;
      while (1)
      {
        pVertex = v22->pVertex;
        v32 = v25;
        v34 = (&pVertex->obj + v25);
        v35 = v34[8];
        v36 = v34[9];
        v37 = v34[10];
        v38 = v34[11];
        v90.x = v35;
        v90.y = v36;
        v90.z = v37;
        v90.w = v38;
        v85 = op_Implicit_8738992(v90);
        p_SDF_CC_NDNM = &SDF_CC_NDNM;
        v43 = p_SDF_CC_NDNM[41];
        v42 = p_SDF_CC_NDNM[42];
        v44 = p_SDF_CC_NDNM[43];
        v89.x = v43;
        v89.y = v42;
        v89.z = v44;
        v86 = Scale(v85, v89);
        *(p_z - 2) = v86;
        pVC = (*hPoly)->pVC;
        v48 = pVC->m_Items[v32];
        v88 = op_Implicit_27186336(blend_col);
        v50 = BYTE1(v48);
        v51 = v88.g * (v50 * 0.0039216);
        v52 = BYTE2(v48);
        v53 = v52 * 0.0039216;
        v54 = HIBYTE(v48);
        v55 = v54 * 0.0078125;
        v49 = v48;
        *(p_a - 3) = v88.r * (v49 * 0.0039216);
        *(p_a - 2) = v51;
        *(p_a - 1) = v88.b * v53;
        *p_a = v88.a * v55;
        if (v28 == v27)
          break;
        if (v32 + 1 >= point)
          v25 = 0;
        else
          v25 = v32 + 1;
        v22 = *hPoly;
        ++v27;
        p_z += 3;
        p_a += 4;
      }
    }
    v57 = v84 - 1;
    if (v84 - 2 >= 0)
      v57 = v84 - 2;
    v58 = v57 >> 1;
    v59 = 2 * ((v57 & 0xFFFFFFFE) + (v57 >> 1));
    if (v59 > SLODWORD(GetIndexTable(v83)->max_length))
    {
      v60 = NewSpecific(s32, v59);
      SetIndexTable(v83, v60);
    }
    IndexTable = GetIndexTable(v83);
    if (v84 - 2 < 2)
    {
      v77 = 0;
      max_length = IndexTable->max_length;
      if (max_length <= 0)
      {
LABEL_74:
        v79 = 1;
        SetActive(v83, 1, 0);
        return v79;
      }
    }
    else
    {
      v62 = 0;
      v63 = 0;
      v64 = &IndexTable->m_Items[5];
      do
      {
        v65 = v62;
        max_length_low = LODWORD(IndexTable->max_length);
        *(v64 - 5) = v63;
        v69 = v63 + 1;
        *(v64 - 4) = v69;
        v71 = v69 + 2;
        *(v64 - 3) = v71;
        v73 = v71 - 3;
        *(v64 - 2) = v73;
        v75 = v73 + 3;
        *(v64 - 1) = v75;
        v63 = v75 - 1;
        --v58;
        v62 = v65 + 6;
        *v64 = v63;
        v64 += 6;
      }
      while (v58);
      v77 = v65 + 6;
      max_length = IndexTable->max_length;
      if (v65 + 6 >= max_length)
        goto LABEL_74;
    }
    v80 = 0;
    do
    {
      IndexTable->m_Items[v77 + v80++] = 0;
    }
    while ((v77 + v80) < max_length);
    goto LABEL_74;
  }
  return 0;
}

// 0x16bf370
dds3HermitianTrackPoly_tag *dds3HermitianTrackPolyCreate(u32 face, u32 split) {
  u64 v5;
  u64 *v6;
  u64 *v7;
  sdfMat_t_o *v9;

  v5 = 2 * face * split + 4;
  v6 = Allocate(dds3HermitianTrackPoly_tag);
  dds3HermitianTrackPoly_tag___ctor(v6);
  v6[5] = NewSpecific(UnityEngine_Vector4, v5);
  v7 = NewSpecific(uint, v5);
  v6[2] = 0x8080808000000002LL;
  v6[6] = v7;
  *(v6 + 6) = v5;
  *(v6 + 9) = split;
  *(v6 + 28) = 0x200000000LL;
  v6[8] = 0;
  v9 = sdfMatNew();
  v6[7] = v9;
  sdfMatSetConstant(v9, 1.0);
  HTP_PrimPolyParm->attr = 0x4000;
  return v6;
}

// 0x16bf580
void dds3HermitianTrackPolyDelete(dds3HermitianTrackPoly_tag **hPoly) {
  dds3HermitianTrackPoly_tag_o **v3;

  else
  {
    v3 = hPoly;
  }
  pMeshDelete(v3);
}

// 0x16bf600
void dds3HermitianTrackPolyDraw(dds3HermitianTrackPoly_tag **hPoly) {
  u32 abgr;
  f32 v4;
  f32 v5;
  f32 v6;
  f32 v7;
  UnityEngine_Color_o v9;
  UnityEngine_Vector4_o v10;

  if (*hPoly)
  {
    abgr = (*hPoly)->abgr;
    *&v9.r = 0;
    *&v9.b = 0;
    v4 = abgr;
    v5 = BYTE1(abgr);
    v6 = BYTE2(abgr);
    v7 = HIBYTE(abgr);
    sub_19EC630(&v9.r, v4 * 0.0078125, v5 * 0.0078125, v6 * 0.0078125, v7 * 0.0078125);
    v10 = op_Implicit(v9, 0);
    MeshDraw(hPoly, v10);
  }
}

// 0x16c1100
void dds3HermitianTrackPolyGetVertex(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t *pVertex0, sdfVector4_t *pVertex1, s32 frame) {
  dds3HermitianTrackPoly_tag_o *v5;
  s32 v6;
  struct UnityEngine_Vector4_array *pVertex;
  s64 v9;

  v5 = *hPoly;
  v6 = (*hPoly)->current - 2 * (frame + (*hPoly)->split * (frame - 1));
  if (v6 <= 1)
    v6 = v6 + v5->point - 2;
  pVertex = v5->pVertex;
  v9 = v6;
  SDF_VU0__COPYVECTOR(pVertex0, pVertex->m_Items[v6]);
  SDF_VU0__COPYVECTOR(pVertex1, pVertex->m_Items[v9 + 1]);
}

// 0x16c1a40
void dds3HermitianTrackPolyReset(dds3HermitianTrackPoly_tag **hPoly) {
  (*hPoly)->count = 0;
  (*hPoly)->current = 2;
  (*hPoly)->abgr = -2139062144;
}

// 0x16c1a30
void dds3HermitianTrackPolySetBlend(dds3HermitianTrackPoly_tag **hPoly, u32 blend) {
  (*hPoly)->blend = blend;
}

// 0x16c11c0
void dds3HermitianTrackPolySetCurrent(dds3HermitianTrackPoly_tag **hPoly, s32 frame) {
  dds3HermitianTrackPoly_tag_o *v3;
  s32 v4;

  v3 = *hPoly;
  v4 = (*hPoly)->current - 2 * (frame + ((*hPoly)->split - 1) * (frame - 1));
  if (v4 <= 1)
    v4 = v4 + v3->point - 2;
  v3->current = v4;
}

// 0x16c1950
void dds3HermitianTrackPolySetVC(dds3HermitianTrackPoly_tag **hPoly, Eff_ModelTrackPolyABGR_t *pABGR) {
  u32 v3;
  f32 v4;
  f32 v5;
  struct System_UInt32_array *pVC;
  f32 v7;
  u64 v9;
  u32 v11;
  char *v13;
  u64 v14;
  u32 v15;

  v3 = (*hPoly)->point >> 1;
  if (v3)
  {
    v4 = v3;
    v5 = 1.0 / v4;
    pVC = (*hPoly)->pVC;
    v7 = 0.0;
    v9 = 0;
    do
    {
      v11 = effColorBlend(pABGR->e0, pABGR->s0, v7);
      v13 = pVC + 4 * v9;
      *(v13 + 8) = v11;
      v14 = v9 + 1;
      v15 = effColorBlend(pABGR->e1, pABGR->s1, v7);
      v7 = v5 + v7;
      --v3;
      v9 = v14 + 1;
      *(v13 + 9) = v15;
    }
    while (v3);
  }
}

// 0x16bfdd0
void dds3HermitianTrackPolySetVertex(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t **pVertex) {
  u64 *v5;
  s64 *v6;
  s64 *v7;
  u32 *v8;
  s64 *v10;
  s64 *v11;
  u64 *v13;
  u64 *v14;
  dds3HermitianTrackPoly_tag_o *v18;
  s32 count;
  s32 split;
  u64 *v21;
  s64 v23;
  s64 v25;
  UnityEngine_Vector4_o *v26;
  s64 v28;
  s64 v29;
  UnityEngine_Vector4_o *v30;
  s64 v33;
  s64 v34;
  UnityEngine_Vector4_o *v35;
  s64 v37;
  s64 v40;
  dds3HermitianTrackPoly_tag_o *v43;
  s32 v44;
  dds3HermitianTrackPoly_tag_o **v45;
  f32 v46;
  s32 v47;
  UnityEngine_Vector4_array *v49;
  dds3HermitianTrackPoly_tag_o *v55;
  u32 v56;
  f32 v65;
  f32 v66;
  s64 v90;
  s64 v92;
  UnityEngine_Vector4_o *v93;
  s64 v95;
  s64 v96;
  UnityEngine_Vector4_o *v97;
  s64 v99;
  s64 v102;
  s64 v105;
  s64 v108;
  f32 v112;
  f32 v113;
  UnityEngine_Vector4_array *v115;
  s32 current;
  s32 v141;
  UnityEngine_Vector4_array *v142;

  v5 = NewSpecific(UnityEngine_Vector4__, 2u);
  v6 = NewSpecific(UnityEngine_Vector4, 4u);
  v7 = v6;
  v8 = v5 + 3;
  v5[4] = v7;
  v10 = NewSpecific(UnityEngine_Vector4, 4u);
  v11 = v10;
  v5[5] = v11;
  v13 = NewSpecific(UnityEngine_Vector4, 4u);
  v14 = NewSpecific(UnityEngine_Vector4, 2u);
  v18 = *hPoly;
  if (*hPoly)
  {
    count = v18->count;
    if (count)
    {
      split = v18->split;
      v21 = v14;
      if (count >= 6 * split)
      {
        current = v18->current;
        v141 = v18->count;
        v23 = v5[4];
        v25 = v5[5];
        v26 = (v23 + 32);
        dds3HermitianTrackPolyGetVertex(hPoly, v26, (v25 + 32), 3);
        v28 = v5[4];
        v29 = v5[5];
        v30 = (v28 + 48);
        dds3HermitianTrackPolyGetVertex(hPoly, v30, (v29 + 48), 2);
        v33 = v5[4];
        v34 = v5[5];
        v35 = (v33 + 64);
        dds3HermitianTrackPolyGetVertex(hPoly, v35, (v34 + 64), 1);
        v37 = v5[4];
        SDF_VU0__COPYVECTOR((v37 + 80), pVertex->m_Items[0], 0);
        v40 = v5[5];
        v142 = pVertex;
        SDF_VU0__COPYVECTOR((v40 + 80), pVertex->m_Items[1], 0);
        v43 = *hPoly;
        v44 = (*hPoly)->current - 2 * (*hPoly)->split - 2;
        v45 = hPoly;
        if (v44 <= 1)
          v44 = v44 + v43->point - 2;
        v43->current = v44;
        if (split >= 1)
        {
          v46 = 0.0;
          v47 = split;
          do
          {
            v49 = v5[4];
            v46 = (1.0 / split) + v46;
            Eff_HermitianSpline(v49, v46);
            SDF_VU0__STOREVECTOR(v21 + 2);
            Eff_HermitianSpline(v5[5], v46);
            SDF_VU0__STOREVECTOR(v21 + 3);
            dds3HermitianTrackPolySetVertexSub(v45, v21);
            --v47;
          }
          while (v47);
        }
        count = v141;
        (*v45)->count = v141;
        hPoly = v45;
        v55 = *v45;
        pVertex = v142;
        v55->current = current;
      }
      if (count >= 4 * split)
      {
        v90 = v5[4];
        v92 = v5[5];
        v93 = (v90 + 32);
        dds3HermitianTrackPolyGetVertex(hPoly, v93, (v92 + 32), 2);
        v95 = v5[4];
        v96 = v5[5];
        v97 = (v95 + 48);
        dds3HermitianTrackPolyGetVertex(hPoly, v97, (v96 + 48), 1);
        v99 = v5[4];
        SDF_VU0__COPYVECTOR((v99 + 64), pVertex->m_Items[0], 0);
        v102 = v5[5];
        SDF_VU0__COPYVECTOR((v102 + 64), pVertex->m_Items[1], 0);
        v105 = v5[4];
        SDF_VU0__COPYVECTOR((v105 + 80), pVertex->m_Items[0], 0);
        v108 = v5[5];
        SDF_VU0__COPYVECTOR((v108 + 80), pVertex->m_Items[1], 0);
        if (split >= 1)
        {
          v112 = 1.0 / split;
          v113 = 0.0;
          do
          {
            v113 = v112 + v113;
            v115 = v5[4];
            Eff_HermitianSpline(v115, v113);
            SDF_VU0__STOREVECTOR(v21 + 2);
            Eff_HermitianSpline(v5[5], v113);
            SDF_VU0__STOREVECTOR(v21 + 3);
            dds3HermitianTrackPolySetVertexSub(hPoly, v21);
            --split;
          }
          while (split);
        }
      }
      else
      {
        v56 = *(v13 + 6);
        dds3HermitianTrackPolyGetVertex(hPoly, v13 + 2, v13 + 3, 1);
        SDF_VU0__LOADVECTOR(pVertex->m_Items[0]);
        SDF_VU0__LOADVECTOR_B(*(v13 + 2), 0);
        SDF_VU0__SUBVECTOR();
        SDF_VU0__STOREVECTOR(v13 + 4);
        SDF_VU0__LOADVECTOR(pVertex->m_Items[1]);
        SDF_VU0__LOADVECTOR_B(*(v13 + 3), 0);
        SDF_VU0__SUBVECTOR();
        SDF_VU0__STOREVECTOR(v13 + 5);
        if (split >= 1)
        {
          v65 = 1.0 / split;
          v66 = 0.0;
          do
          {
            sub_854710((v13 + 4), 0);
            v66 = v65 + v66;
            sub_854710((v13 + 8), 0);
            sub_854930((v21 + 4), 0);
            sub_854710((v13 + 4), 1u);
            sub_854710((v13 + 8), 1u);
            sub_854930((v21 + 4), 1u);
            sub_854710((v13 + 4), 2u);
            sub_854710((v13 + 8), 2u);
            sub_854930((v21 + 4), 2u);
            sub_854710((v13 + 6), 0);
            sub_854710((v13 + 10), 0);
            sub_854930((v21 + 6), 0);
            sub_854710((v13 + 6), 1u);
            sub_854710((v13 + 10), 1u);
            sub_854930((v21 + 6), 1u);
            sub_854710((v13 + 6), 2u);
            sub_854710((v13 + 10), 2u);
            sub_854930((v21 + 6), 2u);
            dds3HermitianTrackPolySetVertexSub(hPoly, v21);
            --split;
          }
          while (split);
        }
      }
    }
    else
    {
      dds3HermitianTrackPolySetVertexSub(hPoly, pVertex);
    }
  }
}

// 0x16c0df0
void dds3HermitianTrackPolySetVertexSub(dds3HermitianTrackPoly_tag **hPoly, sdfVector4_t **pVertex) {
  struct UnityEngine_Vector4_array *v3;
  s64 current;
  s64 v10;
  dds3HermitianTrackPoly_tag_o *v12;
  struct System_UInt32_array *pVC;
  s64 v14;
  struct System_UInt32_array *v16;
  s64 v17;
  dds3HermitianTrackPoly_tag_o *v19;
  s32 point;
  struct UnityEngine_Vector4_array *v21;
  struct UnityEngine_Vector4_array *v22;
  dds3HermitianTrackPoly_tag_o *v25;
  struct System_UInt32_array *v26;
  struct System_UInt32_array *v28;
  s32 count;

  v3 = (*hPoly)->pVertex;
  current = (*hPoly)->current;
  SDF_VU0__COPYVECTOR(&v3->m_Items[current], pVertex->m_Items[0]);
  v10 = (*hPoly)->current + 1LL;
  SDF_VU0__COPYVECTOR(&v3->m_Items[v10], pVertex->m_Items[1]);
  v12 = *hPoly;
  if ((*hPoly)->blend == 12)
  {
    pVC = v12->pVC;
    v14 = v12->current;
    pVC->m_Items[v14] = v12->abgr;
    v16 = (*hPoly)->pVC;
    v17 = (*hPoly)->current;
    v16->m_Items[v17 + 1] = (*hPoly)->abgr;
    v12 = *hPoly;
  }
  v12->current += 2;
  v19 = *hPoly;
  point = (*hPoly)->point;
  if ((*hPoly)->current == point)
  {
    v21 = v19->pVertex;
    SDF_VU0__COPYVECTOR(v21->m_Items, pVertex->m_Items[0]);
    v22 = (*hPoly)->pVertex;
    SDF_VU0__COPYVECTOR(&v22->m_Items[1], pVertex->m_Items[1]);
    v25 = *hPoly;
    if ((*hPoly)->blend == 12)
    {
      v26 = v25->pVC;
      v26->m_Items[0] = v25->abgr;
      v28 = (*hPoly)->pVC;
      v28->m_Items[1] = (*hPoly)->abgr;
      v25 = *hPoly;
    }
    v25->current = 2;
    v19 = *hPoly;
    point = (*hPoly)->point;
  }
  count = v19->count;
  if (count < point - 2)
    v19->count = count + 2;
}

// 0x16c1e40
Eff_ModelTrackPoly_tag *effSwordTrackCreate(effSwordTrackParams_t *pParams) {
  u64 *v3;
  Eff_ModelTrackPolyABGR_t_o *v4;
  u32 point;
  f32 step;
  u32 v9;

  v3 = Allocate(Eff_ModelTrackPoly_tag);
  Eff_ModelTrackPoly_tag___ctor(v3);
  v4 = Allocate(Eff_ModelTrackPolyABGR_t);
  Eff_ModelTrackPolyABGR_t___ctor(v4);
  v3[3] = pParams;
  v3[4] = 0x3F80000000000000LL;
  point = pParams->point;
  step = pParams->step;
  if ((1.0 / step) >= 0.0)
    v9 = (1.0 / step);
  else
    v9 = (1.0 / step);
  v3[5] = dds3HermitianTrackPolyCreate(point, v9);
  v4->s0 = pParams->abgr;
  v4->s1 = pParams->abgr;
  v4->e0 = pParams->abgr;
  v4->e1 = pParams->abgr;
  dds3HermitianTrackPolySetVC(v3 + 5, v4);
  *(v3[5] + 16) = pParams->blend;
  return v3;
}

// 0x16c20a0
void effSwordTrackDelete(Eff_ModelTrackPoly_tag **hSwordTrack) {
  Eff_ModelTrackPoly_tag_o *v3;
  dds3HermitianTrackPoly_tag_o **p_hPoly;

  v3 = *hSwordTrack;
  p_hPoly = &v3->hPoly;
LABEL_7:
  pMeshDelete(p_hPoly);
}

// 0x16c2ee0
void effSwordTrackDraw(Eff_ModelTrackPoly_tag **hSwordTrack) {
  u64 v2;
  u32 *p_frame;
  u32 v5;
  struct effSwordTrackParams_t_o *param_dante;
  f32 v7;
  f64 v8;
  f32 v9;

  p_frame = &(*hSwordTrack)->frame;
  v5 = *p_frame;
  param_dante = (*hSwordTrack)->param_dante;
  LODWORD(v2) = param_dante->frame_s;
  v7 = *p_frame;
  v8 = v2;
  *&v8 = v8;
  if (v7 >= *&v8)
  {
    LODWORD(v8) = param_dante->frame_e;
    v9 = *&v8;
    if (v7 < v9)
    {
      effSwordTrackRecord(hSwordTrack);
    }
    effSwordTrackPolygon2DDraw(hSwordTrack);
    p_frame = &(*hSwordTrack)->frame;
    v5 = *p_frame;
  }
  *p_frame = v5 + 1;
}

// 0x16c3790
void effSwordTrackPolygon2DDraw(Eff_ModelTrackPoly_tag **hSwordTrack) {
  struct dds3HermitianTrackPoly_tag_o *v3;
  UnityEngine_Material_o *sharedMaterial;
  UnityEngine_Material_o *v8;
  struct System_UInt32_array *pVC;
  s32 v10;
  s64 v11;
  u32 *p_sub_alpha_in;
  il2cpp_array_size_t max_length;
  u32 v14;
  s32 v15;
  s64 v16;
  u64 v17;
  u32 v19;
  struct System_UInt32_array *v20;
  u32 v21;
  u64 max_length_low;
  dds3HermitianTrackPoly_tag_o *hPoly;
  UnityEngine_Vector4_o one;

  v3 = (*hSwordTrack)->hPoly;
  hPoly = v3;
  one = get_one();
  if (MeshDraw(&hPoly, one))
  {
    sharedMaterial = get_sharedMaterial(v3->pMesh->_renderer);
    SetFloat_27246832(
      sharedMaterial,
      id_Shift,
      (*hSwordTrack)->param_dante->slide * (*hSwordTrack)->slide_par,
      0);
    v8 = get_sharedMaterial(v3->pMesh->_renderer);
    SetFloat_27246832(
      v8,
      id_ColShift,
      (*hSwordTrack)->slide_par,
      0);
    pVC = v3->pVC;
    v10 = 0;
    v11 = 8;
    p_sub_alpha_in = &(*hSwordTrack)->param_dante->sub_alpha_in;
    max_length = pVC->max_length;
    if (max_length > 0)
    {
LABEL_16:
      v14 = *p_sub_alpha_in << 24;
      v15 = max_length;
      v16 = v11;
      do
      {
        v17 = v16 - 8;
        v19 = *(&pVC->obj.klass + v16);
        if (HIBYTE(v19))
        {
          v20 = v3->pVC;
          v21 = v19 - v14;
          max_length_low = LODWORD(v20->max_length);
          if (v21 > *(&v20->obj.klass + v16))
            v21 &= 0xFFFFFFu;
          *(&v3->pVC->obj.klass + v16) = v21;
        }
        pVC = v3->pVC;
        v16 += 2;
        v15 = pVC->max_length;
      }
      while (v16 - 8 < v15);
    }
    while (v10 != 1)
    {
      p_sub_alpha_in = &(*hSwordTrack)->param_dante->sub_alpha_out;
      ++v10;
      ++v11;
      max_length = pVC->max_length;
      if (v10 < max_length)
        goto LABEL_16;
    }
  }
}

// 0x16c3780
void effSwordTrackPolygonDraw(Eff_ModelTrackPoly_tag **hSwordTrack) {
  ;
}

// 0x16c3600
void effSwordTrackRecord(Eff_ModelTrackPoly_tag **hSwordTrack) {
  u64 *v3;
  struct effSwordTrackParams_t_o *param_dante;
  u64 *v6;
  struct System_UInt32_array *mark;
  struct dds3ModelHandle_t_o *hModel;
  sdfModelRootNode_t_o *modelRoot;
  s32 v11;
  struct System_UInt32_array *v13;
  dds3HermitianTrackPoly_tag_o **p_hPoly;

  v3 = NewSpecific(UnityEngine_Vector4, 2u);
  param_dante = (*hSwordTrack)->param_dante;
  v6 = v3;
  hModel = param_dante->hModel;
  mark = param_dante->mark;
  modelRoot = hModel->modelRoot;
  v11 = mark->m_Items[0];
  sdfModelGetMarkPosUnity(modelRoot, v11);
  SDF_VU0__STOREVECTOR(v6 + 2);
  v13 = (*hSwordTrack)->param_dante->mark;
  sdfModelGetMarkPosUnity(hModel->modelRoot, v13->m_Items[1]);
  SDF_VU0__STOREVECTOR(v6 + 3);
  p_hPoly = &(*hSwordTrack)->hPoly;
  dds3HermitianTrackPolySetVertex(p_hPoly, v6);
}

// 0x16c22b0
void effSwordTrackReset(Eff_ModelTrackPoly_tag **hSwordTrack) {
  Eff_ModelTrackPoly_tag_o *v3;

  (*hSwordTrack)->frame = 0;
  (*hSwordTrack)->slide_par = 1.0;
  v3 = *hSwordTrack;
  v3->hPoly->count = 0;
  v3->hPoly->current = 2;
  v3->hPoly->abgr = -2139062144;
}

// 0x16c2eb0
void effSwordTrackReset2(Eff_ModelTrackPoly_tag **hSwordTrack) {
  (*hSwordTrack)->slide_par = 1.0;
  (*hSwordTrack)->hPoly->count = 0;
  (*hSwordTrack)->hPoly->current = 2;
}

// 0x16bf4b0
void pMeshDelete(dds3HermitianTrackPoly_tag **hPoly) {
  UnityEngine_Object_o *pMesh;
  UnityEngine_Object_o *gameObject;

  if (*hPoly)
  {
    pMesh = (*hPoly)->pMesh;
    if (op_Inequality(pMesh, 0, 0))
    {
      gameObject = get_gameObject((*hPoly)->pMesh, 0);
      Destroy_27360000(gameObject);
      (*hPoly)->pMesh = 0;
    }
  }
}
