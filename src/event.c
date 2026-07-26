#include "types.h"

typedef struct evtUnitHandle_t evtUnitHandle_t;
typedef struct pmdCameraTable_t pmdCameraTable_t;
typedef struct pmdCutInfo_t pmdCutInfo_t;
typedef struct pmdEffectTable_t pmdEffectTable_t;
typedef struct pmdFrameTable_t pmdFrameTable_t;
typedef struct pmdHeader_t pmdHeader_t;
typedef struct pmdSceneFogTable_t pmdSceneFogTable_t;
typedef struct pmdSceneLightTable_t pmdSceneLightTable_t;
typedef struct pmdStageTable_t pmdStageTable_t;
typedef struct pmdTypeTable_t pmdTypeTable_t;
typedef struct pmdUnitTable_t pmdUnitTable_t;

sdfVector4_t pmdSceneLightTable_t__SetVector4(pmdSceneLightTable_t *this, u8 **data, s32 *pos);

// 0x134ff20
void evtUnitHandle_t__Clear(evtUnitHandle_t *this) {
}

// 0x13510b0
void pmdCameraTable_t__SetData(pmdCameraTable_t *this, u8 **data, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;

  v7 = *pos;
  this->NameIndex = ToInt32(data, v7, 0);
  v8 = *pos + 4;
  *pos = v8;
  this->Reserve1 = ToInt32(data, v8, 0);
  v9 = *pos + 4;
  *pos = v9;
  this->Reserve2 = ToInt32(data, v9, 0);
  v10 = *pos + 4;
  *pos = v10;
  this->Reserve3 = ToInt32(data, v10, 0);
  *pos += 4;
}

// 0x13511b0
void pmdCutInfo_t__SetData(pmdCutInfo_t *this, u8 **data, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;

  v7 = *pos;
  this->FirstFrame = ToInt32(data, v7, 0);
  v8 = *pos + 4;
  *pos = v8;
  this->LastFrame = ToInt32(data, v8, 0);
  v9 = *pos + 4;
  *pos = v9;
  this->TotalFrame = ToInt32(data, v9, 0);
  v10 = *pos + 4;
  *pos = v10;
  this->Reserve1 = ToInt32(data, v10, 0);
  *pos += 4;
}

// 0x13512b0
void pmdEffectTable_t__SetData(pmdEffectTable_t *this, u8 **data, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;

  v7 = *pos;
  this->NameIndex = ToInt32(data, v7, 0);
  v8 = *pos + 4;
  *pos = v8;
  this->DataOffset = ToInt32(data, v8, 0);
  v9 = *pos + 4;
  *pos = v9;
  this->Type = ToInt32(data, v9, 0);
  v10 = *pos + 4;
  *pos = v10;
  this->Reserve2 = ToInt32(data, v10, 0);
  *pos += 4;
}

// 0x13513b0
void pmdFrameTable_t__SetData(pmdFrameTable_t *this, u8 **d, s32 *p) {
  s32 v4;
  u32 max_length;
  s64 v7;
  s64 v9;
  u32 v10;
  s32 v11;
  u8 v13;
  s64 v14;
  s64 v16;
  u32 v17;
  s32 v18;
  u8 v20;
  s64 v21;
  s64 v23;
  u32 v24;
  s32 v25;
  u8 v27;
  s64 v28;
  struct pmdDataInfo_t_array *Data;
  s64 v32;
  struct pmdDataInfo_t_array *v33;
  u8 v35;
  s64 v37;
  struct pmdDataInfo_t_array *v38;
  u8 v40;
  s64 v42;
  struct pmdDataInfo_t_array *v43;
  u8 v45;
  s64 v47;
  struct pmdDataInfo_t_array *v48;
  u8 v50;
  struct pmdDataInfo_t_array *v52;
  s64 v54;
  struct pmdDataInfo_t_array *v55;
  u8 v57;
  s64 v59;
  struct pmdDataInfo_t_array *v60;
  u8 v62;
  s64 v64;
  struct pmdDataInfo_t_array *v65;
  u8 v67;
  s64 v69;
  struct pmdDataInfo_t_array *v70;

  v4 = *p;
  max_length = d->max_length;
  v7 = v4 + 1LL;
  this->ObjectType = d->m_Items[v4] | (d->m_Items[v7] << 8);
  v9 = *p + 2LL;
  *p = v9;
  v10 = d->max_length;
  v11 = v9;
  v13 = d->m_Items[v9];
  v14 = v11 + 1LL;
  this->Frame = v13 | (d->m_Items[v14] << 8);
  v16 = *p + 2LL;
  *p = v16;
  v17 = d->max_length;
  v18 = v16;
  v20 = d->m_Items[v16];
  v21 = v18 + 1LL;
  this->Length = v20 | (d->m_Items[v21] << 8);
  v23 = *p + 2LL;
  *p = v23;
  v24 = d->max_length;
  v25 = v23;
  v27 = d->m_Items[v23];
  v28 = v25 + 1LL;
  this->NameIndex = v27 | (d->m_Items[v28] << 8);
  *p += 2;
  Data = this->Data;
  *&Data->m_Items[0].c0 = 0;
  v32 = *p;
  v33 = this->Data;
  v35 = d->m_Items[v32];
  v33->m_Items[0].c0 = v35;
  v37 = *p + 1LL;
  v38 = this->Data;
  v40 = d->m_Items[v37];
  v38->m_Items[0].c1 = v40;
  v42 = *p + 2LL;
  v43 = this->Data;
  v45 = d->m_Items[v42];
  v43->m_Items[0].c2 = v45;
  v47 = *p + 3LL;
  v48 = this->Data;
  v50 = d->m_Items[v47];
  v48->m_Items[0].c3 = v50;
  *p += 4;
  v52 = this->Data;
  *&v52->m_Items[0].i = 0;
  v54 = *p;
  v55 = this->Data;
  v57 = d->m_Items[v54];
  LOBYTE(v55->m_Items[0].i) = v57;
  v59 = *p + 1LL;
  v60 = this->Data;
  v62 = d->m_Items[v59];
  BYTE1(v60->m_Items[0].i) = v62;
  v64 = *p + 2LL;
  v65 = this->Data;
  v67 = d->m_Items[v64];
  BYTE2(v65->m_Items[0].i) = v67;
  v69 = *p + 3LL;
  v70 = this->Data;
  HIBYTE(v70->m_Items[0].i) = d->m_Items[v69];
  *p += 4;
}

// 0x13518c0
void pmdHeader_t__SetData(pmdHeader_t *this, u8 **data, s32 *pos) {
  s64 v7;
  s64 v9;
  s32 v11;
  s32 v12;
  s64 v14;
  struct System_Byte_array *MagicCode;
  u8 v17;
  s64 v19;
  struct System_Byte_array *v20;
  u8 v22;
  s64 v24;
  struct System_Byte_array *v25;
  u8 v27;
  s64 v29;
  struct System_Byte_array *v30;
  u8 v32;
  s32 v34;
  s32 v35;
  s32 v36;
  s32 v37;
  s32 v38;

  v7 = *pos;
  this->FileType = data->m_Items[v7];
  v9 = *pos + 1LL;
  *pos = v9;
  this->FileFormat = data->m_Items[v9];
  v11 = *pos + 1;
  *pos = v11;
  this->UserID = ToInt16(data, v11, 0);
  v12 = *pos + 2;
  *pos = v12;
  this->FileSize = ToInt32(data, v12, 0);
  v14 = *pos + 4LL;
  *pos = v14;
  MagicCode = this->MagicCode;
  v17 = data->m_Items[v14];
  MagicCode->m_Items[0] = v17;
  v19 = *pos + 1LL;
  *pos = v19;
  v20 = this->MagicCode;
  v22 = data->m_Items[v19];
  v20->m_Items[1] = v22;
  v24 = *pos + 1LL;
  *pos = v24;
  v25 = this->MagicCode;
  v27 = data->m_Items[v24];
  v25->m_Items[2] = v27;
  v29 = *pos + 1LL;
  *pos = v29;
  v30 = this->MagicCode;
  v32 = data->m_Items[v29];
  v30->m_Items[3] = v32;
  v34 = *pos + 1;
  *pos = v34;
  this->ExpandSize = ToInt32(data, v34, 0);
  v35 = *pos + 4;
  *pos = v35;
  this->TypeTableCount = ToInt32(data, v35, 0);
  v36 = *pos + 4;
  *pos = v36;
  this->Version = ToInt32(data, v36, 0);
  v37 = *pos + 4;
  *pos = v37;
  this->Reserve2 = ToInt32(data, v37, 0);
  v38 = *pos + 4;
  *pos = v38;
  this->Reserve3 = ToInt32(data, v38, 0);
  *pos += 4;
}

// 0x1351d00
void pmdSceneFogTable_t__SetData(pmdSceneFogTable_t *this, u8 **data, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;

  v7 = *pos;
  this->Min = ToSingle(data, v7, 0);
  v8 = *pos + 4;
  *pos = v8;
  this->Max = ToSingle(data, v8, 0);
  v9 = *pos + 4;
  *pos = v9;
  this->Near = ToSingle(data, v9, 0);
  v10 = *pos + 4;
  *pos = v10;
  this->Far = ToSingle(data, v10, 0);
  v11 = *pos + 4;
  *pos = v11;
  this->Color = ToUInt32(data, v11, 0);
  v12 = *pos + 4;
  *pos = v12;
  this->Reserve1 = ToInt32(data, v12, 0);
  v13 = *pos + 4;
  *pos = v13;
  this->Reserve2 = ToInt32(data, v13, 0);
  v14 = *pos + 4;
  *pos = v14;
  this->Reserve3 = ToInt32(data, v14, 0);
  *pos += 4;
}

// 0x1351f70
void pmdSceneLightTable_t__SetData(pmdSceneLightTable_t *this, u8 **data, s32 *pos) {
  pmdSceneLightTable_t_o *v7;
  pmdSceneLightTable_t_o *v9;

  this->Color = pmdSceneLightTable_t__SetVector4(this, data, pos);
  this->Dir = pmdSceneLightTable_t__SetVector4(v7, data, pos);
  this->Ambient = pmdSceneLightTable_t__SetVector4(v9, data, pos);
}

// 0x1351e70
sdfVector4_t pmdSceneLightTable_t__SetVector4(pmdSceneLightTable_t *this, u8 **data, s32 *pos) {
  s32 v6;
  f32 v7;
  s32 v8;
  f32 v9;
  f32 v10;
  s32 v11;
  f32 v12;
  f32 v13;
  s32 v14;
  f32 v15;
  f32 v16;
  UnityEngine_Vector4_o result;

  v6 = *pos;
  v7 = ToSingle(data, v6, 0);
  v8 = *pos + 4;
  v9 = v7;
  *pos = v8;
  v10 = ToSingle(data, v8, 0);
  v11 = *pos + 4;
  v12 = v10;
  *pos = v11;
  v13 = ToSingle(data, v11, 0);
  v14 = *pos + 4;
  v15 = v13;
  *pos = v14;
  v16 = ToSingle(data, v14, 0);
  *pos += 4;
  result.w = v16;
  result.x = v9;
  result.y = v12;
  result.z = v15;
  return result;
}

// 0x1352000
void pmdStageTable_t__SetData(pmdStageTable_t *this, u8 **data, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;

  v7 = *pos;
  this->NameIndex = ToInt32(data, v7, 0);
  v8 = *pos + 4;
  *pos = v8;
  this->FileIndex = ToInt32(data, v8, 0);
  v9 = *pos + 4;
  *pos = v9;
  this->MajorNum = ToInt32(data, v9, 0);
  v10 = *pos + 4;
  *pos = v10;
  this->MinorNum = ToInt32(data, v10, 0);
  *pos += 4;
}

// 0x1352100
void pmdTypeTable_t__SetData(pmdTypeTable_t *this, u8 **data, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;

  v7 = *pos;
  this->Type = ToInt32(data, v7, 0);
  v8 = *pos + 4;
  *pos = v8;
  this->ItemSize = ToInt32(data, v8, 0);
  v9 = *pos + 4;
  *pos = v9;
  this->ItemCount = ToInt32(data, v9, 0);
  v10 = *pos + 4;
  *pos = v10;
  this->ItemAddress = ToInt32(data, v10, 0);
  *pos += 4;
}

// 0x1352200
void pmdUnitTable_t__SetData(pmdUnitTable_t *this, u8 **data, s32 *pos) {
  s32 v7;
  s32 v8;
  s32 v9;
  s32 v10;
  s32 v11;
  s32 v12;
  s32 v13;
  s32 v14;

  v7 = *pos;
  this->NameIndex = ToInt32(data, v7, 0);
  v8 = *pos + 4;
  *pos = v8;
  this->FileIndex = ToInt32(data, v8, 0);
  v9 = *pos + 4;
  *pos = v9;
  this->MajorNum = ToInt32(data, v9, 0);
  v10 = *pos + 4;
  *pos = v10;
  this->MinorNum = ToInt32(data, v10, 0);
  v11 = *pos + 4;
  *pos = v11;
  this->DataOffset = ToInt32(data, v11, 0);
  v12 = *pos + 4;
  *pos = v12;
  this->DataSize = ToInt32(data, v12, 0);
  v13 = *pos + 4;
  *pos = v13;
  this->Reserve1 = ToInt32(data, v13, 0);
  v14 = *pos + 4;
  *pos = v14;
  this->Reserve2 = ToInt32(data, v14, 0);
  *pos += 4;
}
