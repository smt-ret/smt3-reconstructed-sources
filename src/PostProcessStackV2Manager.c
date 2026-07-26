#include "types.h"

typedef struct PostProcessStackV2Manager PostProcessStackV2Manager;
typedef struct dds3DefaultMain dds3DefaultMain;

f32 GetBloomDown(s32 deveilID);
void *GetCampCameraObj(dds3DefaultMain *this);

// 0x1890aa0
void Start(PostProcessStackV2Manager *this) {
  UnityEngine_GUILayer_o *Component_GUILayer;
  UnityEngine_Rendering_PostProcessing_PostProcessProfile_o *profile;
  UnityEngine_Rendering_PostProcessing_PostProcessProfile_o *v5;
  UnityEngine_GameObject_o *CampCameraObj;
  Il2CppObject *Component_object;
  UnityEngine_Rendering_PostProcessing_PostProcessLayer_o *v11;
  System_String_array *v12;
  s32 Mask;

  Component_GUILayer = GetComponent_GUILayer_(this);
  this->volume = Component_GUILayer;
  profile = get_profile(Component_GUILayer);
  this->bloom = GetSetting_object_(profile);
  v5 = get_profile(this->volume);
  this->dof = GetSetting_object_(v5);
  CampCameraObj = GetCampCameraObj(kernelObject);
  if (op_Inequality(CampCameraObj, 0, 0))
  {
    Component_object = GetComponent_object_(CampCameraObj);
    set_allowHDR(Component_object, 0);
    v11 = AddComponent_object_(CampCameraObj);
    Init(v11, this->m_resources, 0);
    v11->volumeTrigger = get_transform(CampCameraObj, 0);
    v12 = NewSpecific(string, 1u);
    v12->m_Items[0] = StringLiteral_8855;
    Mask = GetMask(v12);
    v11->volumeLayer = op_Implicit_27237744(Mask);
  }
  *&this->bloom_softKnee_mul = 0x3F828F5C3F666666LL;
}

// 0x1890cd0
void Update(PostProcessStackV2Manager *this) {
    GetBloomDown(0);
}
