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
}

// 0x1241420
void MakeCoefficient2(effSpline_t *pspline, f32 ***pdc) {
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
    SolveTridiagonal(0, 0, 0, 0);
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
}

// 0x1242100
void effSplCalcRegist(effSpline_t *pspline, f32 weight, u32 segment) {
    SDF_VU0__LOADVECTOR((sdfVector4_t){0});
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
