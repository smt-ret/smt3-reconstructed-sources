struct libsdf_H_sdfModelNode_t_Fields
{
  struct libsdf_H_sdfModelNode_t_o *prev;
  struct libsdf_H_sdfModelNode_t_o *next;
  struct libsdf_H_sdfModelNode_t_o *parent;
  struct libsdf_H_sdfModelNode_t_o *children;
  struct libsdf_H_sdfModelRootNode_t_o *root;
  uint16_t flags;
  uint16_t drawAttr;
  uint32_t id;
  uint32_t color;
  struct libsdf_H_sdfMemHandle_t_array *drawPacketMemHandle;
  struct libsdf_H_sdfModelPacketHeader_tag_array *drawPacket;
  Il2CppObject *tmPacket;
  float bounds;
  struct libsdf_H_sdfModelNodeDef_t_o *shape;
  uint32_t pad0;
  Il2CppObject *userData;
  struct System_UInt32_array *pad1;
  struct UnityEngine_Vector4_o rotate;
  struct UnityEngine_Vector4_o pos;
  struct UnityEngine_Vector4_o scale;
  struct UnityEngine_Matrix4x4_o localNoScaledTm;
  struct UnityEngine_Matrix4x4_o tm;
};

struct bilManager_H_bilInstance_s_Fields
{
  struct UnityEngine_Vector4_o Pos;
  struct UnityEngine_Vector4_o Scl;
  int32_t Id;
  uint32_t Color;
  struct libsdf_H_sdfTexHandle_t_o *TexHandle;
  struct bilManager_H_bilInstance_s_o *Prev;
  struct bilManager_H_bilInstance_s_o *Next;
  struct bilManager_H_bilInstance_s_array *Draw;
};

struct libsdf_H_sdfMatrix4_t_Fields
{
  struct UnityEngine_Matrix4x4_o pm;
};

struct fldGlobal_StaticFields
{
  struct FldNameData_o *fldNameData;
  struct FldHitData_o *fldHitData;
  struct FldCameraParam_o *fldCameraParam;
  struct System_Byte_array_array *field_name;
  struct field_H_fldAreaName_t_array *area_name;
  struct field_H_fldBasyoName_t_array *basyo_name;
  struct field_H_fldFloorName_t_array *floor_name;
  struct System_String_array *fldsave_nml_name;
  struct System_String_array *fldsave_sml_name;
  struct field_H_fldGlobalWork_t_o *fldGb;
  struct field_H_fldDebug_t_o *fldDbg;
  struct basic_H_dds3Basic_t_o *player;
  struct basic_H_dds3Basic_t_o *player2;
  struct basic_H_dds3Basic_t_o *player3;
  struct System_Int32_array *gFldSaveNmlIdxTbl;
  int32_t fldAllCnt;
};

struct field_H_fldSceneParam_t_StaticFields
{
};

struct fldSky_typeSKYTBL_StaticFields
{
};

struct System_SByte_StaticFields
{
};

struct billManager_hG_t_Fields
{
  uint16_t type;
  struct effect_H_billHandle_t_o *handle;
};

struct billManager_StaticFields
{
  struct BillTable_t_array *BillboardTable;
  float bill_alf_raito;
};

struct pb_H_pb_Define_StaticFields
{
  int32_t PB_MCRD_TYPE_NOCRD;
  int32_t PB_MCRD_TYPE_PS1;
  int32_t PB_MCRD_STAT_SUCCEED;
};
