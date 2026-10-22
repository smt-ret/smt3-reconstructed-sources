#include "types.h"

typedef struct effSpline_t effSpline_t;

static f32 EFF_SPL_DEFAULTSTEP;

void MakeCoefficient(effSpline_t *pspline, f32 ***pdc);
void MakeCoefficient2(effSpline_t *pspline, f32 ***pdc);
void MakeCoefficientTable(effSpline_t *pspline, s32 bogus);
void MakeDifferential(f32 ***pdc, sdfVector3_t **ppoint, s32 n);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void SolveTridiagonal(f32 ***pout, s32 index, f32 **pdd, s32 n);
void effSplCalc(sdfVector4_t *pout, effSpline_t *pspline, f32 weight, u32 segment);

// 0x1241130
void MakeCoefficient(effSpline_t *pspline, f32 ***pdc) {
  struct UnityEngine_Vector3_array *ppoint;
  System_Single_array **v4;
  s64 v6;
  u64 v7;
  u32 v8;
  u64 v9;
  char *v10;
  s64 v11;
  s64 v12;
  f32 v14;
  u64 max_length_low;
  f32 v16;
  struct UnityEngine_Vector3_array *v17;
  u64 v18;
  f32 v20;
  System_Single_array *v21;
  u32 max_length;
  f32 v23;
  System_Single_array *v24;
  f32 v25;
  struct UnityEngine_Vector3_array *mhcoef;
  f32 v29;
  struct UnityEngine_Vector3_array *v31;
  struct UnityEngine_Vector3_array *v33;
  s64 pcoef1;
  s64 pcoef0;
  s64 pcoef2;
  u32 v38;
  s64 v39;
  s64 numpoint;
  f32 *v42;
  f32 *v43;
  s64 v44;
  u64 v45;
  s64 v46;

  numpoint = pspline->numpoint;
  if (numpoint - 1 >= 1)
  {
    ppoint = pspline->ppoint;
    pcoef2 = pspline->pcoef2;
    pcoef0 = pspline->pcoef0;
    v4 = pdc;
    v6 = 0;
    v7 = 0;
    v8 = 1;
    pcoef1 = pspline->pcoef1;
    do
    {
      v9 = v7;
      v10 = ppoint + 12 * v7++;
      v39 = v6;
      v44 = v9 + pcoef0;
      v45 = v9;
      v46 = v9 + pcoef1;
      v11 = 0;
      v42 = (v10 + 44);
      v43 = (v10 + 32);
      v12 = v9 + pcoef2;
      v38 = v8;
      do
      {
        v14 = sub_8527D0(v43, v11);
        max_length_low = LODWORD(ppoint->max_length);
        v16 = v14;
        v17 = ppoint;
        v18 = v7;
        v20 = sub_8527D0(v42, v11);
        v21 = *v4;
        max_length = (*v4)->max_length;
        v23 = v20;
        v24 = *v4;
        v25 = *(v21->m_Items + v6);
        mhcoef = pspline->mhcoef;
        v29 = *(&v24->m_Items[1] + v6);
        sub_8529B0(&mhcoef->m_Items[v44], v11, ((v16 - v20) + (v16 - v20)) + (v25 + v29));
        v31 = pspline->mhcoef;
        v4 = pdc;
        sub_8529B0(&v31->m_Items[v46], v11, ((v23 - v16) * 3.0) - ((v25 + v25) + v29));
        v33 = pspline->mhcoef;
        sub_8529B0(&v33->m_Items[v12], v11, v25);
        v6 += 4 * numpoint;
        ++v11;
        v7 = v18;
        ppoint = v17;
        v8 += numpoint;
      }
      while (v11 != 3);
      v6 = v39 + 4;
      v8 = v38 + 1;
    }
    while (v7 != numpoint - 1);
  }
}

// 0x1241420
void MakeCoefficient2(effSpline_t *pspline, f32 ***pdc) {
  struct UnityEngine_Vector3_array *ppoint;
  s64 v5;
  u64 v6;
  u32 v7;
  u64 v8;
  char *v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  f32 v15;
  f32 v17;
  struct UnityEngine_Vector3_array *mhcoef;
  struct UnityEngine_Vector3_array *v20;
  struct UnityEngine_Vector3_array *v22;
  s64 v24;
  s32 v25;
  f32 v26;
  System_Single_array *v27;
  u32 max_length;
  f32 v29;
  f32 v30;
  struct UnityEngine_Vector3_array *v33;
  f32 v34;
  struct UnityEngine_Vector3_array *v36;
  struct UnityEngine_Vector3_array *v38;
  s64 pcoef1;
  s64 pcoef0;
  s64 pcoef2;
  u32 v43;
  s64 v44;
  s64 numpoint;
  u64 v47;
  f32 *v48;
  f32 *v49;
  u64 v50;

  numpoint = pspline->numpoint;
  if (numpoint - 1 >= 1)
  {
    ppoint = pspline->ppoint;
    pcoef2 = pspline->pcoef2;
    pcoef0 = pspline->pcoef0;
    v5 = 0;
    v6 = 0;
    v7 = 1;
    pcoef1 = pspline->pcoef1;
    do
    {
      v8 = v6;
      v9 = ppoint + 12 * v6++;
      v50 = v8;
      v43 = v7;
      v44 = v5;
      v47 = v6;
      v10 = v8 + pcoef0;
      v11 = v8 + pcoef1;
      v12 = 0;
      v48 = (v9 + 44);
      v49 = (v9 + 32);
      v13 = v8 + pcoef2;
      do
      {
        v15 = sub_8527D0(v49, v12);
        v17 = sub_8527D0(v48, v12);
        if (v15 == v17)
        {
          mhcoef = pspline->mhcoef;
          sub_8529B0(&mhcoef->m_Items[v10], v12, 0.0);
          v20 = pspline->mhcoef;
          sub_8529B0(&v20->m_Items[v11], v12, 0.0);
          v22 = pspline->mhcoef;
          v24 = &v22->m_Items[v13];
          v25 = v12;
          v26 = 0.0;
        }
        else
        {
          v27 = *pdc;
          max_length = (*pdc)->max_length;
          v29 = v17;
          v30 = *(v27->m_Items + v5);
          v33 = pspline->mhcoef;
          v34 = *(&v27->m_Items[1] + v5);
          sub_8529B0(&v33->m_Items[v10], v12, ((v15 - v17) + (v15 - v17)) + (v30 + v34));
          v36 = pspline->mhcoef;
          sub_8529B0(&v36->m_Items[v11], v12, ((v29 - v15) * 3.0) - ((v30 + v30) + v34));
          v38 = pspline->mhcoef;
          v26 = v30;
          v25 = v12;
          v24 = &v38->m_Items[v13];
        }
        sub_8529B0(v24, v25, v26);
        v5 += 4 * numpoint;
        ++v12;
        v6 = v47;
        v7 += numpoint;
      }
      while (v12 != 3);
      v5 = v44 + 4;
      v7 = v43 + 1;
    }
    while (v47 != numpoint - 1);
  }
}

// 0x1240ce0
void MakeCoefficientTable(effSpline_t *pspline, s32 bogus) {
  UnityEngine_Vector3_array *ppoint;
  s32 numpoint;
  System_Single_array *pdc;

  pdc = NewSpecific(f32, 3 * pspline->numpoint);
  ppoint = pspline->ppoint;
  numpoint = pspline->numpoint;
  MakeDifferential(&pdc, ppoint, numpoint);
  if (bogus)
  {
    MakeCoefficient2(pspline, &pdc);
  }
  else
  {
    MakeCoefficient(pspline, &pdc);
  }
}

// 0x1240dd0
void MakeDifferential(f32 ***pdc, sdfVector3_t **ppoint, s32 n) {
  s64 v5;
  s64 v6;
  u64 *v7;
  s32 i;
  f32 v11;
  f32 v13;
  f32 v15;
  s64 v17;
  f32 v19;
  UnityEngine_Vector3_o *v21;
  s64 v22;
  f32 v24;
  f32 v26;
  f32 v28;
  u64 v29;
  f32 v31;

  v5 = (n - 1);
  v6 = n - 2LL;
  v7 = NewSpecific(f32, n);
  for (i = 0; i != 3; ++i)
  {
    v11 = sub_8527D0(&ppoint->m_Items[1].x, i);
    v13 = v11 - sub_8527D0(&ppoint->m_Items[0].x, i);
    *(v7 + 8) = v13 * 3.0;
    v15 = sub_8527D0(&ppoint->m_Items[v5].x, i);
    v19 = v15 - sub_8527D0(&ppoint->m_Items[v6].x, i);
    *(v7 + v5 + 8) = v19 * 3.0;
    if (v6 >= 1)
    {
      v21 = &ppoint->m_Items[2];
      v22 = 9;
      do
      {
        v24 = sub_8527D0(&v21[-1].x, i);
        v26 = sub_8527D0(&v21[-2].x, i);
        v28 = sub_8527D0(&v21->x, i);
        v29 = v22 - 8;
        v31 = (v24 - v26) + (v28 - sub_8527D0(&v21[-1].x, i));
        *(v7 + v22++) = v31 * 3.0;
        ++v21;
      }
      while (v29 + 1 != v5);
    }
    SolveTridiagonal(pdc, v17, v7, n);
  }
}

// 0x12417a0
void SolveTridiagonal(f32 ***pout, s32 index, f32 **pdd, s32 n) {
  f32 *v8;
  System_Single_array *v9;
  s32 v11;
  f32 v12;
  u64 v13;
  s64 v14;
  f32 v15;
  System_Single_array *v17;
  System_Single_array *v18;
  u64 v20;
  f32 v22;
  f32 *v24;
  f32 v26;
  System_Single_array *v29;
  System_Single_array *v30;
  f32 v32;
  f32 v33;
  s64 v34;
  f32 v36;
  s64 v38;
  s64 v39;
  s32 v40;
  f32 *v42;
  f32 v44;
  f32 *v46;
  s64 v47;

  v8 = NewSpecific(f32, n);
  v9 = *pout;
  v11 = n - 2;
  v9->m_Items[0] = pdd->m_Items[0] * 0.5;
  if (n - 2 <= 0)
  {
    LODWORD(v14) = n - 1;
    v12 = 2.0;
  }
  else
  {
    v12 = 2.0;
    v13 = 0;
    v14 = (n - 1);
    do
    {
      v15 = 1.0 / v12;
      v8[v13 + 9] = v15;
      v17 = *pout;
      v18 = *pout;
      v12 = 4.0 - v15;
      v20 = v13;
      v22 = pdd->m_Items[v13 + 1] - v18->m_Items[v13];
      v24 = (v17 + 4 * v13++);
      v24[9] = v22 / v12;
    }
    while (v20 + 2 != v14);
    v11 = n - 2;
  }
  v26 = 1.0 / v12;
  v8[v14 + 8] = v26;
  v29 = *pout;
  v30 = *pout;
  v32 = 2.0 - v26;
  v33 = pdd->m_Items[v14];
  v34 = v11;
  v36 = (v33 - v30->m_Items[v11]) / v32;
  v29->m_Items[v14] = v36;
  if ((v11 & 0x80000000) == 0)
  {
    v38 = 4LL * v11;
    v47 = v11 + 1LL;
    v39 = 0;
    v40 = n - 1;
    do
    {
      v42 = (*pout + 4 * v39 + v38);
      v44 = v8[v38 / 4 + 9 + v39];
      v46 = (*pout + 4 * v39-- + v38);
      v42[8] = v42[8] - (v44 * v46[9]);
    }
    while (v47 + v39 > 0);
  }
}

// 0x1241c50
void effSplCalc(sdfVector4_t *pout, effSpline_t *pspline, f32 weight, u32 segment) {
  struct UnityEngine_Vector3_array *ppoint;
  u32 max_length;
  struct UnityEngine_Vector3_array *mhcoef;
  u64 v11;
  u32 v12;
  struct UnityEngine_Vector3_array *v13;
  char *v15;
  s64 v16;
  s64 v17;
  char *v19;
  s64 v20;
  UnityEngine_Vector4_o *v21;
  u32 v22;
  char *v24;
  s64 v25;
  s64 pcoef1;
  char *v28;
  s64 v29;
  s64 pcoef2;
  char *v32;
  s64 v33;
  struct UnityEngine_Vector3_array *v34;
  char *v36;
  s64 v37;
  s64 v38;
  s32 v39;
  s64 v40;
  s32 v41;
  s64 v42;
  s32 v43;
  s64 v44;
  s32 v45;
  s64 v46;
  s32 v47;
  s64 v48;
  s32 v49;

  v49 = 0;
  v48 = 0;
  v47 = 0;
  v46 = 0;
  v45 = 0;
  v44 = 0;
  v43 = 0;
  v42 = 0;
  v41 = 0;
  v40 = 0;
  v39 = 0;
  v38 = 0;
  if (pspline->islinear)
  {
    ppoint = pspline->ppoint;
    max_length = ppoint->max_length;
    v15 = ppoint + 12 * segment;
    v16 = *(v15 + 4);
    v41 = *(v15 + 10);
    v17 = segment + 1LL;
    v40 = v16;
    v19 = ppoint + 12 * v17;
    v20 = *(v19 + 4);
    LODWORD(v19) = *(v19 + 10);
    v38 = v20;
    v39 = v19;
    sub_8527D0(&v40, 0);
    sub_8527D0(&v38, 0);
    sub_8527D0(&v40, 0);
    sub_854930(pout, 0);
    sub_8527D0(&v40, 1);
    sub_8527D0(&v38, 1);
    sub_8527D0(&v40, 1);
    sub_854930(pout, 1u);
    sub_8527D0(&v40, 2);
    sub_8527D0(&v38, 2);
    sub_8527D0(&v40, 2);
    v21 = pout;
    v22 = 2;
  }
  else
  {
    mhcoef = pspline->mhcoef;
    v11 = pspline->pcoef0 + segment;
    v12 = mhcoef->max_length;
    v13 = pspline->mhcoef;
    v24 = mhcoef + 12 * v11;
    v25 = *(v24 + 4);
    LODWORD(v24) = *(v24 + 10);
    v48 = v25;
    v49 = v24;
    pcoef1 = pspline->pcoef1;
    v28 = v13 + 12 * pcoef1 + 12 * segment;
    v29 = *(v28 + 4);
    LODWORD(v28) = *(v28 + 10);
    v46 = v29;
    v47 = v28;
    pcoef2 = pspline->pcoef2;
    v32 = v13 + 12 * pcoef2 + 12 * segment;
    v33 = *(v32 + 4);
    LODWORD(v32) = *(v32 + 10);
    v44 = v33;
    v45 = v32;
    v34 = pspline->ppoint;
    v36 = v34 + 12 * segment;
    v37 = *(v36 + 4);
    LODWORD(v36) = *(v36 + 10);
    v42 = v37;
    v43 = v36;
    sub_8527D0(&v48, 0);
    sub_8527D0(&v46, 0);
    sub_8527D0(&v44, 0);
    sub_8527D0(&v42, 0);
    sub_854930(pout, 0);
    sub_8527D0(&v48, 1);
    sub_8527D0(&v46, 1);
    sub_8527D0(&v44, 1);
    sub_8527D0(&v42, 1);
    sub_854930(pout, 1u);
    sub_8527D0(&v48, 2);
    sub_8527D0(&v46, 2);
    sub_8527D0(&v44, 2);
    sub_8527D0(&v42, 2);
    sub_854930(pout, 2u);
    v21 = pout;
    v22 = 3;
  }
  sub_854930(v21, v22);
}

// 0x1242100
void effSplCalcRegist(effSpline_t *pspline, f32 weight, u32 segment) {
  struct UnityEngine_Vector3_array *ppoint;
  u32 max_length;
  struct UnityEngine_Vector3_array *mhcoef;
  u64 v9;
  u32 v10;
  struct UnityEngine_Vector3_array *v11;
  char *v13;
  s64 v14;
  s64 v15;
  char *v17;
  s64 v18;
  u32 v19;
  char *v21;
  s64 v22;
  s64 pcoef1;
  char *v25;
  s64 v26;
  s64 pcoef2;
  char *v29;
  s64 v30;
  struct UnityEngine_Vector3_array *v31;
  char *v33;
  s64 v34;
  s64 v35;
  s32 v36;
  s64 v37;
  s32 v38;
  s64 v39;
  s32 v40;
  s64 v41;
  s32 v42;
  s64 v43;
  s32 v44;
  s64 v45;
  s32 v46;
  UnityEngine_Vector4_o v47;

  v46 = 0;
  v45 = 0;
  v44 = 0;
  v43 = 0;
  v42 = 0;
  v41 = 0;
  v40 = 0;
  v39 = 0;
  v38 = 0;
  v37 = 0;
  v36 = 0;
  v35 = 0;
  *&v47.x = 0;
  *&v47.z = 0;
  if (pspline->islinear)
  {
    ppoint = pspline->ppoint;
    max_length = ppoint->max_length;
    v13 = ppoint + 12 * segment;
    v14 = *(v13 + 4);
    v38 = *(v13 + 10);
    v15 = segment + 1LL;
    v37 = v14;
    v17 = ppoint + 12 * v15;
    v18 = *(v17 + 4);
    LODWORD(v17) = *(v17 + 10);
    v35 = v18;
    v36 = v17;
    sub_8527D0(&v37, 0);
    sub_8527D0(&v35, 0);
    sub_8527D0(&v37, 0);
    sub_854930(&v47, 0);
    sub_8527D0(&v37, 1);
    sub_8527D0(&v35, 1);
    sub_8527D0(&v37, 1);
    sub_854930(&v47, 1u);
    sub_8527D0(&v37, 2);
    sub_8527D0(&v35, 2);
    sub_8527D0(&v37, 2);
    v19 = 2;
  }
  else
  {
    mhcoef = pspline->mhcoef;
    v9 = pspline->pcoef0 + segment;
    v10 = mhcoef->max_length;
    v11 = pspline->mhcoef;
    v21 = mhcoef + 12 * v9;
    v22 = *(v21 + 4);
    LODWORD(v21) = *(v21 + 10);
    v45 = v22;
    v46 = v21;
    pcoef1 = pspline->pcoef1;
    v25 = v11 + 12 * pcoef1 + 12 * segment;
    v26 = *(v25 + 4);
    LODWORD(v25) = *(v25 + 10);
    v43 = v26;
    v44 = v25;
    pcoef2 = pspline->pcoef2;
    v29 = v11 + 12 * pcoef2 + 12 * segment;
    v30 = *(v29 + 4);
    LODWORD(v29) = *(v29 + 10);
    v41 = v30;
    v42 = v29;
    v31 = pspline->ppoint;
    v33 = v31 + 12 * segment;
    v34 = *(v33 + 4);
    LODWORD(v33) = *(v33 + 10);
    v39 = v34;
    v40 = v33;
    sub_8527D0(&v45, 0);
    sub_8527D0(&v43, 0);
    sub_8527D0(&v41, 0);
    sub_8527D0(&v39, 0);
    sub_854930(&v47, 0);
    sub_8527D0(&v45, 1);
    sub_8527D0(&v43, 1);
    sub_8527D0(&v41, 1);
    sub_8527D0(&v39, 1);
    sub_854930(&v47, 1u);
    sub_8527D0(&v45, 2);
    sub_8527D0(&v43, 2);
    sub_8527D0(&v41, 2);
    sub_8527D0(&v39, 2);
    sub_854930(&v47, 2u);
    v19 = 3;
  }
  sub_854930(&v47, v19);
  SDF_VU0__LOADVECTOR(v47);
}

// 0x1240ba0
effSpline_t *effSplInitialize2(sdfVector3_t **ppoint, u32 numpoint, s32 bogus) {
  u64 *v7;

  v7 = Allocate(effSpline_t);
  effSpline_t___ctor(v7);
  *(v7 + 4) = numpoint;
  v7[4] = ppoint;
  v7[5] = 0;
  v7[6] = 0;
  *(v7 + 14) = 0;
  *(v7 + 15) = LODWORD(EFF_SPL_DEFAULTSTEP);
  if (numpoint > 2)
  {
    *(v7 + 10) = 0;
    *(v7 + 4) = numpoint;
    v7[3] = NewSpecific(UnityEngine_Vector3, 3 * numpoint);
    v7[4] = ppoint;
    *(v7 + 10) = 0;
    *(v7 + 11) = numpoint;
    *(v7 + 12) = 2 * numpoint;
    *(v7 + 52) = 0;
    *(v7 + 15) = LODWORD(EFF_SPL_DEFAULTSTEP);
    MakeCoefficientTable(v7, bogus);
  }
  else
  {
    *(v7 + 10) = 1;
    *(v7 + 10) = 0;
  }
  return v7;
}

// 0x1241b60
void effSplRelease(effSpline_t **pspline) {
  if (*pspline)
    (*pspline)->ppoint = 0;
}

// 0x12425b0
void effSplRewind(effSpline_t *pspline) {
  *&pspline->segment = 0;
}

// 0x1241b70
s32 effSplRun(sdfVector4_t *pout, effSpline_t *pspline) {
  u32 segment;
  f32 weight;
  f32 v8;
  u32 v9;
  u32 v10;
  bool v11;
  s32 result;

  *&pout->x = 0;
  *&pout->z = 0;
  segment = pspline->segment;
  weight = pspline->weight;
  effSplCalc(pout, pspline, weight, segment);
  v8 = weight + pspline->step;
  v9 = segment + (v8 > 1.0);
  v10 = pspline->numpoint - 1;
  if (v8 > 1.0)
    v8 = v8 + -1.0;
  v11 = v9 >= v10;
  if (v9 >= v10)
    v9 = 0;
  pspline->segment = v9;
  result = !v11;
  if (v11)
    v8 = 0.0;
  pspline->weight = v8;
  return result;
}

// 0x12425c0
void effSplSetStep(effSpline_t *pspline, f32 step) {
  pspline->step = step;
}
