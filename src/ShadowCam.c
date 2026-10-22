#include "types.h"

typedef struct ShadowCam ShadowCam;
typedef struct dds3DefaultMain dds3DefaultMain;

void *GetShadowMapTex(dds3DefaultMain *this);

// 0x1d2910
void OnPreRender(ShadowCam *this) {
  UnityEngine_Transform_o *transform;
  f32 *static_fields;
  f32 v7;
  f32 v8;
  f32 v9;
  UnityEngine_Transform_o *v10;
  f32 PShadow_RotX;
  UnityEngine_Transform_o *v14;
  f32 PShadow_RotY;
  UnityEngine_Transform_o *v17;
  f32 PShadow2_CamX;
  f32 PShadow2_CamY;
  f32 PShadow2_CamZ;
  UnityEngine_Transform_o *v22;
  UnityEngine_Transform_o *v23;
  f32 PShadow2_RotX;
  UnityEngine_Transform_o *v27;
  f32 PShadow2_RotY;
  UnityEngine_Transform_o *v29;
  f32 v31;
  f32 v32;
  f32 v33;
  f32 v34;
  s32 ID_AtlusMat_ShadowViewProj;
  s32 ProjectionClipYID;
  s32 ID_AtlusMat_ShadowClipVec;
  s32 ID_AtlusMat_ShadowMap_ClipY;
  f32 PShadow2_Alp;
  s32 ID_AtlusMat_Shadow2ViewProj;
  s32 ID_AtlusMat_Shadow2Alp;
  UnityEngine_Matrix4x4_o v49;
  UnityEngine_Matrix4x4_o v50;
  UnityEngine_Matrix4x4_o v51;
  UnityEngine_Vector3_o v52;
  UnityEngine_Matrix4x4_o v53;
  UnityEngine_Matrix4x4_o v54;
  UnityEngine_Matrix4x4_o v55;
  UnityEngine_Matrix4x4_o v56;
  UnityEngine_Matrix4x4_o v57;
  UnityEngine_Matrix4x4_o v58;
  UnityEngine_Matrix4x4_o value;
  UnityEngine_Quaternion_o rotation;
  UnityEngine_Matrix4x4_o v61;
  UnityEngine_Matrix4x4_o v62;
  UnityEngine_Quaternion_o v63;
  UnityEngine_Quaternion_o v64;
  UnityEngine_Vector4_o v65;

  memset(&v62, 0, sizeof(v62));
  memset(&v61, 0, sizeof(v61));
  *&rotation.x = 0;
  *&rotation.z = 0;
  if (this->GameUse)
  {
    if (this->ShadowCamID == 1)
    {
      transform = get_transform(this, 0);
      v7 = static_fields[275];
      v8 = static_fields[276];
      v9 = static_fields[277];
      value.m20 = 0.0;
      *&value.m00 = 0;
      sub_8524C0(&value.m00, v7, v8, v9);
      set_position(transform, *&value.m00);
      v10 = get_transform(this, 0);
      v14 = v10;
      {
      }
      v63 = Euler(PShadow_RotX, PShadow_RotY, 0.0);
      set_rotation(v14, v63);
      set_orthographicSize(this->cacheCamera, PShadow_CamSize);
      set_farClipPlane(this->cacheCamera, PShadow_CamFar);
    }
    else
    {
      PShadow2_OnOff = 1.0;
      PShadow2_YClipOnOff = 0.0;
      v17 = get_transform(this, 0);
      v22 = v17;
      value.m20 = 0.0;
      *&value.m00 = 0;
      sub_8524C0(&value.m00, PShadow2_CamX, PShadow2_CamY, PShadow2_CamZ);
      set_position(v22, *&value.m00);
      v23 = get_transform(this, 0);
      v27 = v23;
      {
      }
      v64 = Euler(PShadow2_RotX, PShadow2_RotY, 0.0);
      set_rotation(v27, v64);
      set_orthographicSize(this->cacheCamera, PShadow2_CamSize);
      set_farClipPlane(this->cacheCamera, PShadow2_CamFar);
      PShadow2_CamFar = 12.0;
    }
  }
  v29 = get_transform(this->cacheCamera, 0);
  rotation = get_rotation(v29);
  sub_1A1CAE0(&rotation.x, 0);
  v32 = v31 * 0.017453;
  v33 = sinf(v32);
  v34 = cosf(v32);
  get_worldToCameraMatrix(&value, this->cacheCamera);
  v62 = value;
  get_projectionMatrix(&v58, this->cacheCamera);
  v56 = v58;
  GetGPUProjectionMatrix(&v57, &v56, 1);
  v61 = v57;
  if (this->ShadowCamID == 1)
  {
    ID_AtlusMat_ShadowViewProj = this->ID_AtlusMat_ShadowViewProj;
    value = v61;
    v58 = v62;
    v55 = value;
    v54 = v58;
    op_Multiply(&v57, &v55, &v54, 0);
    v53 = v57;
    SetGlobalMatrix(ID_AtlusMat_ShadowViewProj, &v53);
    ProjectionClipYID = this->ProjectionClipYID;
    SetGlobalFloat(ProjectionClipYID, 0.5 - (PShadow_ClipY / 100.0), 0);
    SetGlobalFloat(
      this->ID_AtlusMat_ShadowOnOff,
      PShadow_OnOff,
      0);
    SetGlobalFloat(
      this->ID_AtlusMat_ShadowAlp,
      PShadow_Alp,
      0);
    SetGlobalFloat(
      this->ID_AtlusMat_ShadowClipX,
      PShadow_ClipX / 100.0,
      0);
    SetGlobalFloat(
      this->ID_AtlusMat_ShadowClipZ,
      PShadow_ClipZ / 100.0,
      0);
    ID_AtlusMat_ShadowClipVec = this->ID_AtlusMat_ShadowClipVec;
    v52.z = 0.0;
    *&v52.x = 0;
    sub_8524C0(&v52.x, v33, 0.0, v34);
    v65 = op_Implicit(v52, 0);
    SetGlobalVector(ID_AtlusMat_ShadowClipVec, v65, 0);
    SetGlobalFloat(
      this->ID_AtlusMat_ShadowVecClipOnOff,
      PShadow_VecClipOnOff,
      0);
    SetGlobalFloat(
      this->ID_AtlusMat_ShadowYClipOnOff,
      PShadow_YClipOnOff,
      0);
    ID_AtlusMat_ShadowMap_ClipY = this->ID_AtlusMat_ShadowMap_ClipY;
    if (this->bWaterClipMode)
      PShadow2_Alp = -1.25;
    else
      PShadow2_Alp = -99999.0;
  }
  else
  {
    ID_AtlusMat_Shadow2ViewProj = this->ID_AtlusMat_Shadow2ViewProj;
    value = v61;
    v58 = v62;
    v51 = value;
    v50 = v58;
    op_Multiply(&v57, &v51, &v50, 0);
    v49 = v57;
    SetGlobalMatrix(ID_AtlusMat_Shadow2ViewProj, &v49);
    SetGlobalFloat(this->ID_AtlusMat_Shadow2OnOff, 1.0, 0);
    ID_AtlusMat_Shadow2Alp = this->ID_AtlusMat_Shadow2Alp;
    ID_AtlusMat_ShadowMap_ClipY = ID_AtlusMat_Shadow2Alp;
  }
  SetGlobalFloat(ID_AtlusMat_ShadowMap_ClipY, PShadow2_Alp, 0);
}

// 0x1d25d0
void Start(ShadowCam *this) {
  struct UnityEngine_Camera_o *Component_GUILayer;
  s32 ShadowCamID;
  UnityEngine_Shader_o *ShadowMap;
  struct UnityEngine_RenderTexture_o *ShadowMapTex;

  this->_ShadowMap = Find("Atlus/AtlusMat_ShadowMap", 0);
  this->_ShadowMapClip = Find("Atlus/AtlusMat_ShadowMapClip", 0);
  this->_ShadowMap2 = Find("Atlus/AtlusMat_ShadowMap2", 0);
  this->_ShadowMapClip2 = Find("Atlus/AtlusMat_ShadowMapClip2", 0);
  Component_GUILayer = GetComponent_GUILayer_(this);
  ShadowCamID = this->ShadowCamID;
  this->cacheCamera = Component_GUILayer;
  if (ShadowCamID == 1)
    ShadowMap = this->_ShadowMap;
  else
    ShadowMap = this->_ShadowMap2;
  SetReplacementShader(Component_GUILayer, ShadowMap, "RenderType");
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
    SetReplacementShader(cacheCamera, ShadowMapClip, "RenderType");
  }
  this->bWaterClipMode = 0;
  if (fldGb->fieldID == 22)
  {
    else
    {
      areaID = fldGb->areaID;
      if (areaID == 8)
        goto LABEL_36;
    }
    else if (areaID == 14)
    {
      goto LABEL_36;
    }
    if (areaID != 15)
      return;
LABEL_36:
    this->bWaterClipMode = 1;
  }
}
