#include "types.h"

typedef struct effBezier_t effBezier;
typedef struct effBezier_t effBezier_t;

static f32 EFF_BEZ_DEFAULTSTEP;

void effBezCalc(effBezier *this, sdfVector4_t out, effBezier_t *pbezier, f32 weight, u32 segment);

// 0x1379620
void effBezCalc(effBezier *this, sdfVector4_t out, effBezier_t *pbezier, f32 weight, u32 segment) {
  u64 *v9;
  struct UnityEngine_Vector3_array *ppoint;
  u64 *v11;
  char *v13;
  s64 v14;
  s64 *v15;
  Il2CppClass *v16;
  s64 *v17;
  s64 *Interface;
  char *v19;
  s64 *v20;
  s64 v21;
  s64 v22;
  char *v24;
  s64 v25;
  s64 *v26;
  Il2CppClass *v27;
  s64 *v28;
  s64 *v29;
  char *v30;
  s64 *v31;
  char *v33;
  s64 v34;
  s64 *v35;
  Il2CppClass *v36;
  s64 *v37;
  s64 *v38;
  char *v39;
  s64 *v40;
  f32 *p_y;
  s64 v43;
  s64 *v44;
  Il2CppClass *v45;
  s64 *v46;
  s64 *v47;
  char *v48;
  s64 *v49;
  f32 v50;
  u32 v51;
  f32 v54;
  f32 v55;
  s64 v82;
  s32 v83;
  s64 v84;
  s32 v85;
  s64 v86;
  s32 v87;
  s64 v88;
  s32 v89;
  UnityEngine_Vector4_o v90;
  u64 v91[2];
  char *v92;

  v90 = out;
  v9 = NewSpecific(f32, 4u);
  ppoint = pbezier->ppoint;
  v11 = v9;
  v13 = ppoint + 12 * segment;
  v14 = *(v13 + 4);
  LODWORD(v13) = *(v13 + 10);
  v88 = v14;
  v89 = v13;
  v15 = sub_8D3950(UnityEngine_Vector3, &v88);
  if (v15)
  {
    v17 = v15;
    Interface = QueryInterface(v15, f32);
    if (!Interface)
    {
      sub_8FC2C0(*(*v17 + 64), v16, v91);
      if ((v91[0] & 1) != 0)
        v19 = v92;
      else
        v19 = v91 + 1;
      v20 = sub_8C4940(v19);
    }
  }
  else
  {
    Interface = 0;
  }
  v21 = segment;
  v22 = segment + 1LL;
  v24 = ppoint + 12 * v22;
  v25 = *(v24 + 4);
  LODWORD(v24) = *(v24 + 10);
  v86 = v25;
  v87 = v24;
  v26 = sub_8D3950(UnityEngine_Vector3, &v86);
  if (v26)
  {
    v28 = v26;
    v29 = QueryInterface(v26, f32);
    if (!v29)
    {
      sub_8FC2C0(*(*v28 + 64), v27, v91);
      if ((v91[0] & 1) != 0)
        v30 = v92;
      else
        v30 = v91 + 1;
      v31 = sub_8C4940(v30);
    }
  }
  else
  {
    v29 = 0;
  }
  v33 = &ppoint->max_length + 12 * v21;
  v34 = *(v33 + 4);
  LODWORD(v33) = *(v33 + 10);
  v84 = v34;
  v85 = v33;
  v35 = sub_8D3950(UnityEngine_Vector3, &v84);
  if (v35)
  {
    v37 = v35;
    v38 = QueryInterface(v35, f32);
    if (!v38)
    {
      sub_8FC2C0(*(*v37 + 64), v36, v91);
      if ((v91[0] & 1) != 0)
        v39 = v92;
      else
        v39 = v91 + 1;
      v40 = sub_8C4940(v39);
    }
  }
  else
  {
    v38 = 0;
  }
  p_y = &ppoint->m_Items[v21].y;
  v43 = *(p_y + 4);
  *&p_y = p_y[10];
  v82 = v43;
  v83 = p_y;
  v44 = sub_8D3950(UnityEngine_Vector3, &v82);
  if (v44)
  {
    v46 = v44;
    v47 = QueryInterface(v44, f32);
    if (!v47)
    {
      sub_8FC2C0(*(*v46 + 64), v45, v91);
      if ((v91[0] & 1) != 0)
        v48 = v92;
      else
        v48 = v91 + 1;
      v49 = sub_8C4940(v48);
    }
  }
  else
  {
    v47 = 0;
  }
  v50 = 1.0 - weight;
  v51 = *(v11 + 6);
  *(v11 + 8) = v50 * (v50 * v50);
  *(v11 + 9) = ((v50 * v50) * weight) * 3.0;
  v54 = (weight * weight) * v50;
  v55 = (weight * weight) * weight;
  *(v11 + 10) = v54 * 3.0;
  *(v11 + 11) = v55;
  sub_854930(&v90, 0);
  sub_854930(&v90, 1u);
  sub_854930(&v90, 2u);
  sub_854930(&v90, 3u);
}

// 0x13793f0
effBezier_t *effBezInitialize(effBezier *this, sdfVector3_t ppoint, u32 numpoint) {
  f32 z;
  f32 y;
  f32 x;
  u64 *v8;
  u64 *v9;
  effBezier_t_o *result;
  s64 *Interface;
  Il2CppClass *v13;
  s64 *v14;
  char *v15;
  s64 *v16;
  u32 v18[4];
  u64 v19[3];

  z = ppoint.z;
  y = ppoint.y;
  x = ppoint.x;
  v8 = Allocate(sdfMemHandle_t);
  sdfMemHandle_t___ctor(v8);
  v9 = Allocate(effBezier_t);
  effBezier_t___ctor(v9);
  result = 0;
  if (numpoint >= 4)
  {
    v9[2] = v8;
    *(v9 + 6) = numpoint;
    *v18 = x;
    *&v18[1] = y;
    *&v18[2] = z;
    Interface = sub_8D3950(UnityEngine_Vector3, v18);
    if (Interface)
    {
      v14 = Interface;
      Interface = QueryInterface(Interface, UnityEngine_Vector3);
      if (!Interface)
      {
        sub_8FC2C0(*(*v14 + 64), v13, v19);
        if ((v19[0] & 1) != 0)
          v15 = v19[2];
        else
          v15 = v19 + 1;
        v16 = sub_8C4940(v15);
      }
    }
    v9[4] = Interface;
    v9[5] = 0;
    *(v9 + 12) = LODWORD(EFF_BEZ_DEFAULTSTEP);
    return v9;
  }
  return result;
}

// 0x1379590
void effBezRelease(effBezier *this, effBezier_t *pbezier) {
  ;
}

// 0x1379f70
void effBezRewind(effBezier *this, effBezier_t *pbezier) {
  *&pbezier->segment = 0;
}

// 0x13795a0
s32 effBezRun(effBezier *this, sdfVector4_t out, effBezier_t *pbezier) {
  f32 weight;
  u32 segment;
  f32 v8;
  u32 v9;
  u32 v10;
  bool v11;
  s32 result;

  weight = pbezier->weight;
  segment = pbezier->segment;
  effBezCalc(this, out, pbezier, weight, segment);
  v8 = weight + pbezier->step;
  v9 = segment + 3;
  if (v8 <= 1.0)
    v9 = segment;
  v10 = pbezier->numpoint - 1;
  if (v8 > 1.0)
    v8 = v8 + -1.0;
  v11 = v9 >= v10;
  if (v9 >= v10)
    v9 = 0;
  pbezier->segment = v9;
  result = !v11;
  if (v11)
    v8 = 0.0;
  pbezier->weight = v8;
  return result;
}

// 0x1379f80
void effBezSetStep(effBezier *this, effBezier_t *pbezier, f32 step) {
  pbezier->step = step;
}
