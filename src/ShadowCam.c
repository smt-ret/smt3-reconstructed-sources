#include "types.h"

typedef struct ShadowCam ShadowCam;
typedef struct dds3DefaultMain dds3DefaultMain;

void *GetShadowMapTex(dds3DefaultMain *this);

// 0x1d2910
void OnPreRender(ShadowCam *this) {
}

// 0x1d25d0
void Start(ShadowCam *this) {
  struct UnityEngine_Camera_o *Component_GUILayer;
  s32 ShadowCamID;
  UnityEngine_Shader_o *ShadowMap;
  struct UnityEngine_RenderTexture_o *ShadowMapTex;

  this->_ShadowMap = Find(StringLiteral_8917, 0);
  this->_ShadowMapClip = Find(StringLiteral_8918, 0);
  this->_ShadowMap2 = Find(StringLiteral_8919, 0);
  this->_ShadowMapClip2 = Find(StringLiteral_8920, 0);
  Component_GUILayer = GetComponent_GUILayer_(this);
  ShadowCamID = this->ShadowCamID;
  this->cacheCamera = Component_GUILayer;
  if (ShadowCamID == 1)
    ShadowMap = this->_ShadowMap;
  else
    ShadowMap = this->_ShadowMap2;
  SetReplacementShader(Component_GUILayer, ShadowMap, StringLiteral_4782);
  ShadowMapTex = GetShadowMapTex(kernelObject);
  this->ShadowMap = ShadowMapTex;
  SetGlobalTexture(this->ProjectionShadowMapID, ShadowMapTex, 0);
  set_targetTexture(this->cacheCamera, this->ShadowMap);
  SetGlobalTexture(this->ID_AtlusMat_ShadowMap2_Rt, this->ShadowMap, 0);
}

// 0x1d2720
void Update(ShadowCam *this) {
  _BOOL4 TexClipMode;
  _BOOL4 PShadow_TexClipMode;
  s32 ShadowCamID;
  UnityEngine_Camera_o *cacheCamera;
  UnityEngine_Shader_o *ShadowMapClip;
  struct fldGlobalWork_t_o *fldGb;
  s32 areaID;

  TexClipMode = this->_TexClipMode;
  if (TexClipMode != PShadow_TexClipMode)
  {
    ShadowCamID = this->ShadowCamID;
    cacheCamera = this->cacheCamera;
    this->_TexClipMode = PShadow_TexClipMode;
    if (PShadow_TexClipMode)
    {
      if (ShadowCamID == 1)
        ShadowMapClip = this->_ShadowMapClip;
      else
        ShadowMapClip = this->_ShadowMapClip2;
    }
    else if (ShadowCamID == 1)
    {
      ShadowMapClip = this->_ShadowMap;
    }
    else
    {
      ShadowMapClip = this->_ShadowMap2;
    }
    SetReplacementShader(cacheCamera, ShadowMapClip, StringLiteral_4782);
  }
  this->bWaterClipMode = 0;
  if (fldGb->fieldID == 22)
  {
    else
    {
      areaID = fldGb->areaID;
      if (areaID == 8)
    }
    else    if (areaID != 15)
      return;
    this->bWaterClipMode = 1;
  }
}
