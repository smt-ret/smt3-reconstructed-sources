#include "types.h"

typedef struct datUnitWork_s datUnitWork_t;
typedef struct effBTL_SkillLight_t effBTL_SkillLight_t;
typedef struct effBTL_SkillModel_t effBTL_SkillModel_t;
typedef struct effBTL_SkillPositionPtr_t effBTL_SkillPositionPtr_t;
typedef struct effBattleLight_EFFBTL_POINTLIGHT_P effBattleLight_EFFBTL_POINTLIGHT_P;
typedef struct effBattleLight_effBTLPointLight_Base_tag effBattleLight_effBTLPointLight_Base_tag;
typedef struct effBattleLight_effBTLPointLight_tag effBattleLight_effBTLPointLight_tag;
typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct nbFormation_t nbFormation_t;
typedef struct nbMainProcessData_t nbMainProcessData_t;

struct effBattleLight_effBTLPointLight_tag {
    effBTL_SkillLight_t *light;
    s32 light_frame;
    effBTL_SkillModel_t *model;
    s32 model_frame;
};

struct effBattleLight_effBTLPointLight_Base_tag {
    sdfVector4_t light_direction;
    u32 light_diffuse;
    u32 light_ambient;
    u32 reserve1;
    u32 reserve2;
};

struct effBattleLight_EFFBTL_POINTLIGHT_P {
    s32 value__;
};

static effBattleLight_effBTLPointLight_tag effBTLPointLight[UNKNOWN_ARRAY_SIZE];
static effBattleLight_effBTLPointLight_Base_tag effBTLPointLightBase[UNKNOWN_ARRAY_SIZE];
static u32 effBTLPointLightProcess;

void SDF_VU0__COPYVECTOR(sdfVector4_t *dst, sdfVector4_t src);
void SDF_VU0__LOADVECTOR(sdfVector4_t p);
void effBTLModelColorMain(void);
u32 effBTLPartGetFadeFramePtr(u32 PtrNum);
void effBTLPartGetPointLightPtr(nbFormation_t **pFormation, effBTL_SkillPositionPtr_t **pPosPtr, sdfVector4_t *pDir);
void effBTLPointLightEnd(void);
void effBTLPointLightGroupSet(effBTL_SkillLight_t **pLight, u32 group);
void effBTLPointLightMain(void);
void effBTLPointLightModelSet(effBTL_SkillLight_t **pLight, nbFormation_t **pFormation);
void effBTLPointLightStart(void);
u32 effBTLSkillGetInvokeParty(void);
u32 effBTLSkillGetTargetParty(void);
void effBTL_SkillLight_t__Copy(effBTL_SkillLight_t *this, effBTL_SkillLight_t *data);
void effBTL_SkillModel_t__Copy(effBTL_SkillModel_t *this, effBTL_SkillModel_t *data);
u32 effColorBlend(u32 abgr0, u32 abgr1, f32 rate);
void evtSetUnitColorRGB(evtUnitHandle_t **h, u32 frame, u32 rgb);
void evtSetUnitLightAndAmbient(evtUnitHandle_t **h, u32 frame, u32 lrgb, u32 argb);
void evtSetUnitLightDir(evtUnitHandle_t **h, s32 frame);
void evtUnitLightOff(evtUnitHandle_t **h, s32 frame);
void evtUnitLightOn(evtUnitHandle_t **h);
nbMainProcessData_t *nbGetMainProcessData(void);
datUnitWork_t *nbGetUnitWorkFromFormindex(s32 formindex);

// 0x14ba790
u32 DDS3EFFECT_RGBA(u32 r, u32 g, u32 b, u32 a) {
  return r | (g << 8) | (b << 16) | (a << 24);
}

// 0x14bbe80
void effBTLModelColorMain(void) {
  nbMainProcessData_t_o *MainProcessData;
  s64 i;
  u32 v6;
  evtUnitHandle_t_o **v7;
  struct nbFormation_t_array *form;
  u64 v9;
  effBattleLight_c *v11;
  s64 v12;
  struct effBattleLight_StaticFields *static_fields;
  s64 v15;
  s64 v17;
  u32 *v18;
  s64 v19;
  u32 v20;
  u32 v21;
  u32 FadeFramePtr;
  u32 v24;
  u32 v26;
  u32 v27;
  s64 v28;
  u32 v29;
  u32 v31;
  evtUnitHandle_t_o **v32;
  u32 v33;

  MainProcessData = nbGetMainProcessData();
  for (i = 4; i != 36; ++i)
  {
    form = MainProcessData->form;
    v9 = i - 4;
    v12 = *(&form->obj.klass + i);
    static_fields = v11->static_fields;
    v15 = *(&static_fields->effBTLPointLight->obj.klass + i);
    if ((~*(v12 + 136) & 3) == 0)
    {
      v17 = *(v15 + 40);
      if ((v17 & 0x80000000) == 0)
      {
        v18 = *(*(v15 + 32) + 24LL);
        v19 = v18[4];
        v20 = v18[5];
        v21 = v18[6];
        FadeFramePtr = effBTLPartGetFadeFramePtr(v20);
        v24 = effBTLPartGetFadeFramePtr(*(*(*(v15 + 32) + 24LL) + 28LL));
        if (v19 < v21 && v21 >= v24)
        {
          v26 = v21 - v24;
          v27 = v24;
          if (v19 < v26)
          {
            v7 = (v12 + 168);
            if (*(v12 + 168))
            {
              if (v17 == v19)
              {
                v28 = *(v12 + 192);
                v29 = *(*(v15 + 32) + 16LL);
                if ((v28 & 0xFFFFFF) != 0x808080)
                {
                  v6 = effColorBlend(v29, v28, 0.5);
                  evtSetUnitColorRGB((v12 + 168), FadeFramePtr, v6, 0);
                  v7 = (v12 + 168);
                  if (v17 != v26)
                }
                v31 = FadeFramePtr;
                v32 = v7;
                evtSetUnitColorRGB(v7, v31, v29);
                v7 = v32;
              }
              if (v17 != v26)
              {
                ++*(v15 + 40);
                continue;
              }
              v33 = *(v12 + 192);
              evtSetUnitColorRGB(v7, v27, v33);
            }
          }
        }
      }
    }
  }
}

// 0x14bb0e0
void effBTLModelColorSet(effBTL_SkillModel_t **pModel, nbFormation_t **pFormation) {
  nbFormation_t_o *v5;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 id;
  struct effBattleLight_effBTLPointLight_tag_array *effBTLPointLight;
  s64 v11;
  effBattleLight_effBTLPointLight_tag_o *v13;

  v5 = *pFormation;
  if (!*pFormation || (v5->stat & 1) == 0)
  formindex = v5->formindex;
  UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
  if ((UnitWorkFromFormindex->flag & 4) != 0 || (id = UnitWorkFromFormindex->id, id != 264) && id != 293)
  {
    v11 = (*pFormation)->formindex;
    v13 = effBTLPointLight->m_Items[v11];
    effBTL_SkillModel_t__Copy(v13->model, *pModel);
    v13->model_frame = 0;
  }
}

// 0x14ba9b0
void effBTLPointLightCompulsionOFF(void) {
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v7;

  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    v7 = form->m_Items[i];
    if ((~v7->stat & 3) == 0 && v7->hunit)
    {
      evtUnitLightOff(&v7->hunit, 0);
      evtSetUnitColorRGB(&v7->hunit, 0xCu, v7->modelcol);
    }
  }
  effBTLPointLightProcess = 0;
}

// 0x14bb7f0
void effBTLPointLightEnd(void) {
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v8;

  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    v8 = form->m_Items[i];
    if ((~v8->stat & 3) == 0 && v8->hunit)
    {
      evtUnitLightOff(&v8->hunit, 12);
      evtSetUnitColorRGB(&v8->hunit, 0xCu, v8->modelcol);
    }
  }
}

// 0x14badd0
void effBTLPointLightGroupSet(effBTL_SkillLight_t **pLight, u32 group) {
  u64 *v5;
  nbMainProcessData_t_o *MainProcessData;
  u64 i;
  struct nbFormation_t_array *form;
  nbFormation_t_o *v13;
  nbFormation_t_o *pFormation;

  pFormation = 0;
  v5 = Allocate(effBattleLight_effBTLPointLight_tag);
  _ctor(v5, 0);
  MainProcessData = nbGetMainProcessData();
  for (i = 0; i != 32; ++i)
  {
    form = MainProcessData->form;
    v13 = form->m_Items[i];
    pFormation = v13;
    if ((v13->stat & 3) == 3 && (v13->stat & group) != 0)
    {
      effBTLPointLightModelSet(pLight, &pFormation);
    }
  }
}

// 0x14ba7a0
void effBTLPointLightInit(void) {
  effBTLPointLightProcess = 0;
}

// 0x14bb950
void effBTLPointLightMain(void) {
  nbMainProcessData_t_o *MainProcessData;
  s64 i;
  struct nbFormation_t_array *form;
  u64 v6;
  effBattleLight_c *v8;
  struct effBattleLight_StaticFields *static_fields;
  s64 v11;
  struct effBattleLight_effBTLPointLight_Base_tag_array *effBTLPointLightBase;
  s64 v14;
  u32 *v15;
  s64 v16;
  u32 v17;
  u32 v18;
  s64 v19;
  u32 FadeFramePtr;
  u32 v22;
  u32 v24;
  u32 v25;
  effBTL_SkillPositionPtr_t_o **v28;
  u32 v29;
  u32 v30;
  evtUnitHandle_t_o *hunit;
  UnityEngine_Vector4_o pDir;
  nbFormation_t_o *pFormation;

  *&pDir.z = 0;
  pFormation = 0;
  *&pDir.x = 0;
  hunit = 0;
  MainProcessData = nbGetMainProcessData();
  for (i = 4; i != 36; ++i)
  {
    form = MainProcessData->form;
    v6 = i - 4;
    pFormation = *(&form->obj.klass + i);
    static_fields = v8->static_fields;
    v11 = *(&static_fields->effBTLPointLight->obj.klass + i);
    effBTLPointLightBase = static_fields->effBTLPointLightBase;
    if ((~pFormation->stat & 3) == 0)
    {
      v14 = *(v11 + 24);
      if ((v14 & 0x80000000) == 0)
      {
        v15 = *(*(v11 + 16) + 32LL);
        v16 = v15[4];
        v17 = v15[5];
        v18 = v15[6];
        v19 = *(&effBTLPointLightBase->obj.klass + i);
        FadeFramePtr = effBTLPartGetFadeFramePtr(v17);
        v22 = effBTLPartGetFadeFramePtr(*(*(*(v11 + 16) + 32LL) + 28LL));
        if (v16 < v18 && v18 >= v22)
        {
          v24 = v18 - v22;
          v25 = v22;
          if (v16 < v24)
          {
            hunit = pFormation->hunit;
            if (hunit)
            {
              if (v14 == v16)
              {
                evtUnitLightOn(&hunit);
                evtSetUnitLightAndAmbient(
                  &hunit,
                  FadeFramePtr,
                  *(*(v11 + 16) + 24LL),
                  *(*(v11 + 16) + 28LL),
                  0);
                v28 = (*(v11 + 16) + 16LL);
                effBTLPartGetPointLightPtr(&pFormation, v28, &pDir);
                SDF_VU0__LOADVECTOR(pDir);
                evtSetUnitLightDir(&hunit, FadeFramePtr);
              }
              if (v14 == v24)
              {
                v29 = *(v19 + 32);
                v30 = *(v19 + 36);
                evtSetUnitLightAndAmbient(&hunit, v25, v29, v30);
                SDF_VU0__LOADVECTOR(*(v19 + 16), 0);
                evtSetUnitLightDir(&hunit, v25);
              }
              ++*(v11 + 24);
            }
          }
        }
      }
    }
  }
}

// 0x14baaf0
void effBTLPointLightModelSet(effBTL_SkillLight_t **pLight, nbFormation_t **pFormation) {
  struct effBattleLight_effBTLPointLight_tag_array *effBTLPointLight;
  effBattleLight_effBTLPointLight_tag_o *v8;
  nbFormation_t_o *v10;
  s32 formindex;
  datUnitWork_t_o *UnitWorkFromFormindex;
  s32 id;
  struct effBTL_SkillLight_t_o *light;
  struct effBTL_SkillLight_t_o *v16;
  u32 diffuse;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 v21;
  f32 v22;

  v8 = effBTLPointLight->m_Items[(*pFormation)->formindex];
  effBTL_SkillLight_t__Copy(v8->light, *pLight);
  v10 = *pFormation;
  if (*pFormation && (v10->stat & 1) != 0)
  {
    formindex = v10->formindex;
    UnitWorkFromFormindex = nbGetUnitWorkFromFormindex(formindex);
    if ((UnitWorkFromFormindex->flag & 4) == 0)
    {
      id = UnitWorkFromFormindex->id;
      if (id == 293 || id == 264)
      {
        light = v8->light;
        light->diffuse = -2130724458;
        v8->light->ambient = -2142227948;
      }
    }
  }
  v16 = v8->light;
  diffuse = v16->diffuse;
  v18 = diffuse;
  v19 = BYTE1(diffuse);
  v20 = BYTE2(diffuse);
  if (v18 >= v19)
    v21 = v16->diffuse;
  else
    v21 = BYTE1(diffuse);
  if (v21 >= v20)
    v22 = v21;
  else
    v22 = BYTE2(diffuse);
  if (v22 > 135.0)
    v16->diffuse = ((v18 / v22) * 135.0) | (((v20 / v22) * 135.0) << 8) | (((v20 / v22) * 135.0) << 16);
  v8->light_frame = 0;
}

// 0x14ba920
void effBTLPointLightOFF(void) {
  effBattleLight_c *v2;
  struct effBattleLight_StaticFields *static_fields;

  static_fields = v2->static_fields;
  if (static_fields->effBTLPointLightProcess)
  {
    static_fields->effBTLPointLightProcess = 3;
  }
}

// 0x14ba810
void effBTLPointLightON(void) {
  s32 v3;
  struct effBattleLight_StaticFields *static_fields;

  {
    else
    {
      static_fields = effBattleLight->static_fields;
      if (static_fields->effBTLPointLightProcess)
    }
    if (v3)
    {
      else
      {
        effBTLPointLightProcess = 1;
      }
    }
    else
    {
      static_fields->effBTLPointLightProcess = 1;
    }
    return;
  }
  v3 = 0;
  static_fields = effBattleLight->static_fields;
  if (!static_fields->effBTLPointLightProcess)
  static_fields->effBTLPointLightProcess = 2;
}

// 0x14bc180
void effBTLPointLightRun(void) {
    effBTLPointLightMain();
    effBTLModelColorMain();
    effBTLPointLightStart();
    effBTLPointLightEnd();
}

// 0x14baf50
void effBTLPointLightSet(effBTL_SkillLight_t **pLight, nbFormation_t **pFormation) {
  u32 TargetParty;
  u32 v7;
  effBTL_SkillLight_t_o **v8;
  u32 v9;

  if ((*pLight)->color_anim->fade_in_frame != (*pLight)->color_anim->fade_out_frame)
  {
    switch ((*pLight)->pos_ptr->target)
    {
      case 0u:
        effBTLPointLightModelSet(pLight, pFormation);
        return;
      case 1u:
        TargetParty = effBTLSkillGetInvokeParty();
      case 2u:
        TargetParty = effBTLSkillGetTargetParty();
        v7 = TargetParty;
        v8 = pLight;
        v9 = v7;
      case 3u:
        v8 = pLight;
        v9 = 1792;
        effBTLPointLightGroupSet(v8, v9);
        break;
      default:
        return;
    }
  }
}

// 0x14bb250
void effBTLPointLightStart(void) {
  effBattleLight_c *v2;
  struct effBattleLight_effBTLPointLight_tag_array *v3;
  u64 i;
  u32 *effBTLPointLight;
  u64 *v9;
  u32 *v11;
  u64 v12;
  s32 v13;
  struct effBattleLight_effBTLPointLight_tag_array *v14;
  effBattleLight_effBTLPointLight_tag_o *v16;
  u64 *v17;
  u64 *v18;
  u32 v19;
  struct effBattleLight_effBTLPointLight_Base_tag_array *v20;
  u64 v22;
  u32 *effBTLPointLightBase;
  u64 *v24;
  u64 v27;
  struct effBattleLight_effBTLPointLight_Base_tag_array *v29;
  Il2CppClass **v31;
  Il2CppClass *v32;
  nbMainProcessData_t_o *MainProcessData;
  s64 j;
  struct nbFormation_t_array *form;
  s64 v39;
  struct effBattleLight_effBTLPointLight_Base_tag_array *v40;
  UnityEngine_Vector4_o *v42;
  s64 v43;

  else  v3 = NewSpecific(effBattleLight_effBTLPointLight_tag, 0x20u);
  effBTLPointLight = v3;
  for (i = 0; i != 32; ++i)
  {
    v9 = Allocate(effBattleLight_effBTLPointLight_tag);
    _ctor(v9, 0);
    v11 = &effBTLPointLight[2 * i];
    *(v11 + 4) = v9;
  }
  v12 = 0;
  v13 = (v2->_2.bitflags2 >> 1) & 1;
  do
  {
    v14 = effBTLPointLight;
    v16 = v14->m_Items[v12];
    v17 = Allocate(effBTL_SkillLight_t);
    effBTL_SkillLight_t___ctor(v17);
    v16->light = v17;
    v16->light_frame = -1;
    v18 = Allocate(effBTL_SkillModel_t);
    effBTL_SkillModel_t___ctor(v18);
    v16->model = v18;
    v16->model_frame = -1;
    ++v12;
    v13 = (v19 >> 9) & 1;
  }
  while (v12 != 32);
  else  v20 = NewSpecific(effBattleLight_effBTLPointLight_Base_tag, 0x20u);
  effBTLPointLightBase = v20;
  v22 = 0;
  while (1)
  {
    v24 = Allocate(effBattleLight_effBTLPointLight_Base_tag);
    _ctor(v24, 0);
    *&effBTLPointLightBase[2 * v22 + 8] = v24;
    if (v22 == 31)
      break;
    ++v22;
  }
  v27 = 0;
  do
  {
    v29 = effBTLPointLightBase;
    v31 = &v29->obj.klass + v27++;
    v32 = v31[4];
    v32->_1.byval_arg.data = 0;
    *&v32->_1.byval_arg.bits = 0;
    v32->_1.name = 0;
    v32->_1.namespaze = 0;
  }
  while (v27 != 32);
  MainProcessData = nbGetMainProcessData();
  for (j = 4; j != 36; ++j)
  {
    form = MainProcessData->form;
    v39 = *(&form->obj.klass + j);
    v40 = effBTLPointLightBase;
    if ((~*(v39 + 136) & 3) == 0)
    {
      v42 = *(v39 + 168);
      if (v42)
      {
        v43 = *(&v40->obj.klass + j);
        SDF_VU0__COPYVECTOR((v43 + 16), v42[2], 0);
        *(v43 + 32) = *(*(v39 + 168) + 16LL);
        *(v43 + 36) = *(*(v39 + 168) + 96LL);
      }
    }
  }
}

// 0x14bb7e0
void effBattleLight_effBTLPointLight_Base_tag__Clear(effBattleLight_effBTLPointLight_Base_tag *this) {
  *&this->light_diffuse = 0;
  *&this->reserve1 = 0;
  *&this->light_direction.x = 0;
  *&this->light_direction.z = 0;
}

// 0x14bc2b0
void effBattleLight_effBTLPointLight_Base_tag__Copy(effBattleLight_effBTLPointLight_Base_tag *this, effBattleLight_effBTLPointLight_Base_tag *param) {
  f32 z;
  f32 w;

  z = param->light_direction.z;
  w = param->light_direction.w;
  *&this->light_direction.x = *&param->light_direction.x;
  this->light_direction.z = z;
  this->light_direction.w = w;
  this->light_diffuse = param->light_diffuse;
  this->light_ambient = param->light_ambient;
  this->reserve1 = param->reserve1;
  this->reserve2 = param->reserve2;
}

// 0x14bb730
void effBattleLight_effBTLPointLight_tag__Clear(effBattleLight_effBTLPointLight_tag *this) {
  u64 *v3;
  u64 *v4;

  v3 = Allocate(effBTL_SkillLight_t);
  effBTL_SkillLight_t___ctor(v3);
  this->light = v3;
  this->light_frame = -1;
  v4 = Allocate(effBTL_SkillModel_t);
  effBTL_SkillModel_t___ctor(v4);
  this->model = v4;
  this->model_frame = -1;
}

// 0x14bc2f0
void effBattleLight_effBTLPointLight_tag__Copy(effBattleLight_effBTLPointLight_tag *this, effBattleLight_effBTLPointLight_tag *param) {
  effBTL_SkillLight_t__Copy(this->light, param->light);
  this->light_frame = param->light_frame;
  effBTL_SkillModel_t__Copy(this->model, param->model);
  this->model_frame = param->model_frame;
}
