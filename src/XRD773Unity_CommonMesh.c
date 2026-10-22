#include "types.h"

typedef struct XRD773Unity_CommonMesh XRD773Unity_CommonMesh;
typedef struct XRD773Unity_CommonMesh_COL XRD773Unity_CommonMesh_COL;
typedef struct XRD773Unity_CommonMesh_POS XRD773Unity_CommonMesh_POS;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;
typedef struct dds3DefaultMain dds3DefaultMain;

struct XRD773Unity_CommonMesh_POS {
    f32 x;
    f32 y;
    f32 z;
};

struct XRD773Unity_CommonMesh_COL {
    s32 r;
    s32 g;
    s32 b;
};

void *GetMainCamera(dds3DefaultMain *this);
void *GetNormalMat(XRD773Unity_GraphicManager *this, s32 mode);
void *GetPaletteMat(XRD773Unity_GraphicManager *this, s32 mode);
void *GetPlaneMat(XRD773Unity_GraphicManager *this, s32 mode);
void SetCOL(XRD773Unity_CommonMesh_COL ***col, s32 count, s32 r, s32 g, s32 b);
void SetIndex4(s32 ***idx, s32 count, s32 index);
void SetPOS(XRD773Unity_CommonMesh_POS ***pos, s32 count, f32 x, f32 y, f32 z);

// 0x134d7b0
void *AllocateNativeArray(XRD773Unity_CommonMesh *this, s32 lenght) {
  s32 m_Length;
  s32 v6;
  void *m_Buffer;
  s64 v8;
  s64 v9;
  s64 v10;
  void *v11;
  u64 *v12;
  System_Tuple_NativeArray_Vector3___NativeArray_Color___o *v13;
  void *v15;
  s64 v16;
  Unity_Collections_NativeArray_Vector3__o v17;
  Unity_Collections_NativeArray_Color__o v18;

  if ((byte_3F593BE & 1) != 0)
  {
    m_Length = this->positionNA.m_Length;
    if (m_Length >= lenght)
      goto LABEL_3;
LABEL_8:
    if (m_Length >= 1)
      sub_7FD250(&this->positionNA);
    v15 = 0;
    v16 = 0;
    sub_7FCEE0(&v15, lenght, 4u, 1);
    v9 = v16;
    this->positionNA.m_Buffer = v15;
    *&this->positionNA.m_Length = v9;
    v6 = this->colorNA.m_Length;
    if (v6 < lenght)
      goto LABEL_4;
LABEL_11:
    m_Buffer = this->colorNA.m_Buffer;
    v8 = *&this->colorNA.m_Length;
    goto LABEL_12;
  }
  m_Length = this->positionNA.m_Length;
  if (m_Length < lenght)
    goto LABEL_8;
LABEL_3:
  v6 = this->colorNA.m_Length;
  if (v6 >= lenght)
    goto LABEL_11;
LABEL_4:
  if (v6 >= 1)
    sub_7FBE50(&this->colorNA);
  v15 = 0;
  v16 = 0;
  sub_7FBAE0(&v15, lenght, 4u, 1);
  m_Buffer = v15;
  v8 = v16;
  this->colorNA.m_Buffer = v15;
  *&this->colorNA.m_Length = v8;
LABEL_12:
  this->nativePoints = lenght;
  v11 = this->positionNA.m_Buffer;
  v10 = *&this->positionNA.m_Length;
  v12 = Allocate(System_Tuple_NativeArray_Vector3___NativeArray_Color);
  v17.m_Buffer = v11;
  *&v17.m_Length = v10;
  v18.m_Buffer = m_Buffer;
  *&v18.m_Length = v8;
  v13 = v12;
  _NativeArray_Color_____ctor(v12, v17, v18);
  return v13;
}

// 0x134d920
s32 **AlocateIndexTable(XRD773Unity_CommonMesh *this, s32 point) {
  System_Int32_array *result;

  if ((byte_3F593BF & 1) != 0)
  {
    result = this->index;
    if (SLODWORD(result->max_length) >= point)
      return result;
LABEL_5:
    result = NewSpecific(s32, point);
    this->index = result;
    return result;
  }
  result = this->index;
  if (SLODWORD(result->max_length) < point)
    goto LABEL_5;
  return result;
}

// 0x134d540
void Awake(XRD773Unity_CommonMesh *this) {
  u64 *v3;
  UnityEngine_MeshFilter_o *Component_GUILayer;
  u64 *v5;

  v3 = Allocate(UnityEngine_Mesh);
  _ctor(v3, 0);
  this->mesh = v3;
  MarkDynamic(v3);
  Component_GUILayer = GetComponent_GUILayer_(this);
  set_sharedMesh(Component_GUILayer, this->mesh);
  v5 = Allocate(UnityEngine_MaterialPropertyBlock);
  _ctor(v5, 0);
  this->block = v5;
}

// 0x134e5e0
void ClearUseIndex(XRD773Unity_CommonMesh *this) {
  struct System_Int32_array *index;
  UnityEngine_GameObject_o *MainCamera;
  UnityEngine_Transform_o *transform;
  s64 v9;
  s64 v10;
  s64 v11;
  s64 v12;
  s64 v13;
  s64 v14;
  UnityEngine_Matrix4x4_o v15;
  UnityEngine_Quaternion_o rotation;

  index = this->index;
  this->use_idx_now = 0;
  this->use_one = 1;
  Clear(index, 0, index->max_length, 0);
  MainCamera = GetMainCamera(kernelObject);
  transform = get_transform(MainCamera, 0);
  rotation = get_rotation(transform);
  Rotate(&v15, rotation, 0);
  v10 = *&v15.m00;
  v9 = *&v15.m20;
  v11 = *&v15.m01;
  *&this->mat.m21 = *&v15.m21;
  *&this->mat.m01 = v11;
  *&this->mat.m20 = v9;
  *&this->mat.m00 = v10;
  v13 = *&v15.m02;
  v12 = *&v15.m22;
  v14 = *&v15.m03;
  *&this->mat.m23 = *&v15.m23;
  *&this->mat.m03 = v14;
  *&this->mat.m22 = v12;
  *&this->mat.m02 = v13;
}

// 0x134e780
void FillIndex(s32 ***idx) {
  System_Int32_array *v2;
  u64 v3;

  v2 = *idx;
  if (SLODWORD((*idx)->max_length) >= 1)
  {
    v3 = 0;
    do
    {
      v2->m_Items[v3] = v3;
      v2 = *idx;
      ++v3;
    }
    while (v3 < SLODWORD((*idx)->max_length));
  }
}

// 0x134e520
void FillIndexTable(XRD773Unity_CommonMesh *this, s32 cnt) {
  s64 v5;
  struct System_Int32_array *v6;
  struct System_Int32_array *index;
  s64 v8;
  s64 v9;

  v5 = cnt;
  v6 = NewSpecific(s32, cnt);
  this->index = v6;
  if (cnt >= 1)
  {
    index = v6;
    v8 = 0;
    v9 = v5 - 1;
    if (!LODWORD(v6->max_length))
    {
LABEL_7:
    }
    while (1)
    {
      index->m_Items[v8] = v8;
      if (v9 == v8)
        break;
      index = this->index;
      if (++v8 >= LODWORD(index->max_length))
        goto LABEL_7;
    }
  }
}

// 0x134e4f0
sdfColor_t **GetColor(XRD773Unity_CommonMesh *this) {
  return this->color;
}

// 0x134e510
s32 **GetIndexTable(XRD773Unity_CommonMesh *this) {
  return this->index;
}

// 0x134e170
sdfVector3_t **GetPosition(XRD773Unity_CommonMesh *this) {
  return this->position;
}

// 0x134ddf0
void *GetTexture(XRD773Unity_CommonMesh *this) {
  return this->texture;
}

// 0x134e720
s32 GetUseIndex(XRD773Unity_CommonMesh *this) {
  return this->use_idx_now;
}

// 0x134e740
s32 GetUseIndexMax(XRD773Unity_CommonMesh *this) {
  return this->use_idx_max;
}

// 0x134e770
s32 GetUseOne(XRD773Unity_CommonMesh *this) {
  return this->use_one;
}

// 0x134e330
sdfVector2_t **GetUvTable(XRD773Unity_CommonMesh *this) {
  return this->uv;
}

// 0x134d5f0
void OnDestroy(XRD773Unity_CommonMesh *this) {
  UnityEngine_Object_o *mesh;
  UnityEngine_MeshFilter_o *Component_GUILayer;
  s32 m_Length;

  mesh = this->mesh;
  Destroy_27360000(mesh);
  Component_GUILayer = GetComponent_GUILayer_(this);
  set_sharedMesh(Component_GUILayer, 0);
  m_Length = this->positionNA.m_Length;
  this->mesh = 0;
  if (m_Length >= 1)
    sub_7FD250(&this->positionNA);
  if (this->colorNA.m_Length >= 1)
    sub_7FBE50(&this->colorNA);
}

// 0x134ddb0
void ResetTexture(XRD773Unity_CommonMesh *this) {
  XRD773Unity_CommonMesh_c *klass;

  if (this->use_texture)
  {
    klass = this->klass;
    this->use_texture = 0;
    (klass->vtable._6__SetDrawMode.methodPtr)(this, this->draw_mode, klass->vtable._6__SetDrawMode.method);
  }
  this->texture = 0;
}

// 0x134ec40
void SetCOL(XRD773Unity_CommonMesh_COL ***col, s32 count, s32 r, s32 g, s32 b) {
  XRD773Unity_CommonMesh_COL_array *v11;
  u64 *v16;

  v11 = *col;
  if ((*col)->m_Items[count])
  {
    v11->m_Items[count]->r = r;
    (*col)->m_Items[count]->g = g;
    (*col)->m_Items[count]->b = b;
  }
  else
  {
    v16 = Allocate(XRD773Unity_CommonMesh_COL);
    _ctor(v16, r, g, b, 0);
    v11->m_Items[count] = v16;
  }
}

// 0x134edf0
void SetCOL4(XRD773Unity_CommonMesh_COL ***col, s32 count, s32 r, s32 g, s32 b) {
  s32 v11;

  v11 = count + 1;
  SetCOL(col, count, r, g, b);
  SetCOL(col, v11, r, g, b);
  SetCOL(col, count + 2, r, g, b);
  SetCOL(col, count + 3, r, g, b);
}

// 0x134dab0
void SetColor(XRD773Unity_CommonMesh *this, void col, s32 length) {
  s64 v5;
  void *m_Buffer;
  struct UnityEngine_Color_array *color;
  Unity_Collections_NativeArray_Color__o v9;
  Unity_Collections_NativeArray_T__o v10;

  v9 = col;
  v5 = *&col.m_Length;
  m_Buffer = col.m_Buffer;
  color = this->color;
  if (color && v5 == LODWORD(color->max_length))
  {
    if (v5 >= length)
    {
      v10.m_Buffer = m_Buffer;
      *&v10.m_Length = v5;
      _Copy_8373120(v10, 0, color, 0, length);
    }
  }
  else
  {
    this->color = sub_7FBED0(&v9);
  }
}

// 0x134e340
void SetColorTable(XRD773Unity_CommonMesh *this, XRD773Unity_CommonMesh_COL **col) {
  struct UnityEngine_Color_array *v5;
  u32 *max_length;
  struct UnityEngine_Color_array *color;
  s64 v8;
  u64 v9;
  u8 *v11;
  s32 v12;
  s32 v14;
  f32 v15;
  s32 v16;
  s32 v17;
  s32 v18;
  s64 v20;
  s64 v21;

  v5 = NewSpecific(UnityEngine_Color, LODWORD(col->max_length));
  this->color = v5;
  max_length = col->max_length;
  if (max_length >= 1)
  {
    color = v5;
    v8 = 0;
    v9 = 0;
    while (1)
    {
      v11 = col->m_Items[v9];
      v12 = v11[16];
      v14 = v11[20];
      v15 = v11[24] / 255.0;
      v20 = 0;
      v21 = 0;
      sub_19EC630(&v20, v12 / 255.0, v14 / 255.0, v15, 0.5);
      v16 = HIDWORD(v20);
      v18 = v21;
      v17 = HIDWORD(v21);
      max_length = (color + v8);
      max_length[8] = v20;
      max_length[9] = v16;
      max_length[10] = v18;
      max_length[11] = v17;
      LODWORD(max_length) = col->max_length;
      if (++v9 >= max_length)
        break;
      color = this->color;
      v8 += 16;
    }
  }
}

// 0x134db90
void SetColor_20241296(XRD773Unity_CommonMesh *this, sdfColor_t **col) {
  this->color = col;
}

// 0x134e7f0
void SetIndex4(s32 ***idx, s32 count, s32 index) {
  s64 v4;
  s32 v6;
  s64 v7;
  char *v9;
  s32 v10;
  s64 v11;
  u32 v13;
  s64 v15;

  v4 = count + 1LL;
  v6 = index + 1;
  (*idx)->m_Items[count] = index;
  v7 = count + 2LL;
  v9 = *idx + 4 * v4;
  v10 = index + 2;
  *(v9 + 8) = v6;
  v11 = count + 3LL;
  v13 = count + 4;
  (*idx)->m_Items[v7] = v10;
  (*idx)->m_Items[v11] = index + 3;
  v15 = v11 + 2LL;
  (*idx)->m_Items[v13] = v10;
  (*idx)->m_Items[v15] = v6;
}

// 0x134e950
void SetIndex4_20244816(s32 ***idx) {
  s32 v4;
  s32 v5;
  signed s32 v6;
  u64 v7;

  if (SLODWORD((*idx)->max_length) >= 6)
  {
    v4 = 0;
    v5 = 0;
    v6 = 0;
    do
    {
      SetIndex4(idx, v5, v4);
      v7 = 715827883LL * SLODWORD((*idx)->max_length);
      ++v6;
      v5 += 6;
      v4 += 4;
    }
    while (v6 < (HIDWORD(v7) + (v7 >> 63)));
  }
}

// 0x134e500
void SetIndexTable(XRD773Unity_CommonMesh *this, s32 **idx) {
  this->index = idx;
}

// 0x134dda0
void SetMatTexture(XRD773Unity_CommonMesh *this, void *texture) {
  this->texture = texture;
  this->use_texture = 1;
}

// 0x134e9e0
void SetPOS(XRD773Unity_CommonMesh_POS ***pos, s32 count, f32 x, f32 y, f32 z) {
  XRD773Unity_CommonMesh_POS_array *v11;
  XRD773Unity_CommonMesh_POS_array *v15;
  u64 *v17;

  v11 = *pos;
  if ((*pos)->m_Items[count])
  {
    v11->m_Items[count]->x = x;
    (*pos)->m_Items[count]->y = y;
    v15 = *pos;
    v15->m_Items[count]->z = z;
  }
  else
  {
    v17 = Allocate(XRD773Unity_CommonMesh_POS);
    _ctor(v17, x, y, z, 0);
    v11->m_Items[count] = v17;
  }
}

// 0x134eb90
void SetPOS4(XRD773Unity_CommonMesh_POS ***pos, s32 count, f32 x, f32 y, f32 z, f32 w, f32 h) {
  f32 v13;
  f32 v14;
  s32 v15;

  v13 = x + w;
  v14 = y + h;
  v15 = count + 1;
  SetPOS(pos, count, x, y, z);
  SetPOS(pos, v15, v13, y, z);
  SetPOS(pos, count + 2, x, v14, z);
  SetPOS(pos, count + 3, v13, v14, z);
}

// 0x134d9c0
void SetPosition(XRD773Unity_CommonMesh *this, void pos, s32 length) {
  s64 v5;
  void *m_Buffer;
  struct UnityEngine_Vector3_array *position;
  Unity_Collections_NativeArray_Vector3__o v9;
  Unity_Collections_NativeArray_T__o v10;

  v9 = pos;
  v5 = *&pos.m_Length;
  m_Buffer = pos.m_Buffer;
  position = this->position;
  if (position && v5 == LODWORD(position->max_length))
  {
    if (v5 >= length)
    {
      v10.m_Buffer = m_Buffer;
      *&v10.m_Length = v5;
      _Copy_8378240(v10, 0, position, 0, length);
    }
  }
  else
  {
    this->position = sub_7FD2D0(&v9);
  }
}

// 0x134dfe0
void SetPositionTable(XRD773Unity_CommonMesh *this, XRD773Unity_CommonMesh_POS **pos) {
  struct UnityEngine_Vector3_array *v5;
  u32 *max_length;
  struct UnityEngine_Vector3_array *position;
  s64 v8;
  u64 v9;
  XRD773Unity_CommonMesh_POS_o *v11;
  f32 z;
  f32 v14;
  f32 x;
  s32 v16;
  s32 v17;
  s64 v19;
  s32 v20;

  v5 = NewSpecific(UnityEngine_Vector3, LODWORD(pos->max_length));
  this->position = v5;
  max_length = pos->max_length;
  if (max_length >= 1)
  {
    position = v5;
    v8 = 0;
    v9 = 0;
    while (1)
    {
      v11 = pos->m_Items[v9];
      z = v11->z;
      v14 = -v11->y;
      x = v11->x;
      v20 = 0;
      v19 = 0;
      sub_8524C0(&v19, x, v14, z);
      v16 = HIDWORD(v19);
      v17 = v20;
      max_length = (position + v8);
      max_length[8] = v19;
      max_length[9] = v16;
      max_length[10] = v17;
      LODWORD(max_length) = pos->max_length;
      if (++v9 >= max_length)
        break;
      position = this->position;
      v8 += 12;
    }
  }
}

// 0x134daa0
void SetPosition_20241056(XRD773Unity_CommonMesh *this, sdfVector3_t **pos) {
  this->position = pos;
}

// 0x134de00
void SetSprite(XRD773Unity_CommonMesh *this, void *sprite) {
  struct UnityEngine_Texture_o *texture;
  UnityEngine_Rect_o textureRect;

  *&textureRect.m_XMin = 0;
  texture = get_texture(sprite);
  if (!this->use_texture)
  {
    this->use_texture = 1;
    (this->klass->vtable._6__SetDrawMode.methodPtr)(
      this,
      this->draw_mode,
      this->klass->vtable._6__SetDrawMode.method);
  }
  this->texture = texture;
  this->ou = 0.0;
  this->ov = (texture->klass->vtable._6_get_height.methodPtr)(
                      texture,
                      texture->klass->vtable._6_get_height.method);
  textureRect = get_textureRect(sprite);
  this->ou = sub_1A1D9D0(&textureRect);
  textureRect = get_textureRect(sprite);
  this->ov = sub_1A1DA70(&textureRect);
}

// 0x134dd30
void SetTexture(XRD773Unity_CommonMesh *this, void *texture) {
  if (!this->use_texture)
  {
    this->use_texture = 1;
    (this->klass->vtable._6__SetDrawMode.methodPtr)(
      this,
      this->draw_mode,
      this->klass->vtable._6__SetDrawMode.method);
  }
  this->texture = texture;
  this->ou = 0.0;
  this->ov = (texture->klass->vtable._6_get_height.methodPtr)(
                      texture,
                      texture->klass->vtable._6_get_height.method);
}

// 0x134ee90
void SetTile(XRD773Unity_CommonMesh_POS ***pos, XRD773Unity_CommonMesh_COL ***col, s32 ***idx, s32 count, s32 x, s32 y, s32 z, s32 w, s32 h, s32 r, s32 g, s32 b) {
  f32 v13;
  s32 v14;
  f32 v15;
  f32 v17;
  f32 v18;
  f32 v20;
  s32 v22;
  s32 v23;
  s32 v25;

  v13 = x;
  v14 = 4 * count;
  v15 = y;
  v17 = z;
  v18 = x + w;
  v20 = y + h;
  v22 = (4 * count) | 1;
  SetPOS(pos, 4 * count, x, y, z, idx);
  v23 = (4 * count) | 2;
  SetPOS(pos, v22, v18, v15, v17);
  v25 = (4 * count) | 3;
  SetPOS(pos, v23, v13, v20, v17);
  SetPOS(pos, v25, v18, v20, v17);
  SetCOL(col, v14, r, g, b);
  SetCOL(col, v22, r, g, b);
  SetCOL(col, v23, r, g, b);
  SetCOL(col, v25, r, g, b);
  SetIndex4(idx, 6 * count, v14);
}

// 0x134e730
void SetUseIndex(XRD773Unity_CommonMesh *this, s32 index) {
  this->use_idx_now = index;
}

// 0x134e750
void SetUseIndexMax(XRD773Unity_CommonMesh *this, s32 index) {
  if (this->use_idx_max < index)
    this->use_idx_max = index;
}

// 0x134e180
void SetUvTable(XRD773Unity_CommonMesh *this, XRD773Unity_CommonMesh_POS **pos) {
  struct UnityEngine_Vector2_array *v5;
  struct UnityEngine_Vector2_array *uv;
  s64 v7;
  u64 v8;
  XRD773Unity_CommonMesh_POS_o **m_Items;
  f32 ou;
  f32 x;
  s32 v13;
  f32 ov;
  s32 v15;
  f32 y;
  s32 v18;
  s32 v19;
  char *v21;
  u32 max_length;
  s64 v23;

  if (this->use_texture)
  {
    v5 = NewSpecific(UnityEngine_Vector2, LODWORD(pos->max_length));
    this->uv = v5;
    if (pos->max_length >= 1)
    {
      uv = v5;
      v7 = 0;
      v8 = 0;
      m_Items = pos->m_Items;
      ou = this->ou;
      while (1)
      {
        x = m_Items[v8]->x;
        v13 = (this->texture->klass->vtable._4_get_width.methodPtr)(
                this->texture,
                this->texture->klass->vtable._4_get_width.method);
        ov = this->ov;
        v15 = v13;
        y = m_Items[v8]->y;
        v18 = (this->texture->klass->vtable._6_get_height.methodPtr)(
                this->texture,
                this->texture->klass->vtable._6_get_height.method);
        v23 = 0;
        sub_851710(&v23, (ou + x) / v15, (ov - y) / v18);
        v19 = HIDWORD(v23);
        v21 = uv + v7;
        *(v21 + 8) = v23;
        *(v21 + 9) = v19;
        max_length = pos->max_length;
        if (++v8 >= max_length)
          break;
        uv = this->uv;
        v7 += 8;
        ou = this->ou;
      }
    }
  }
}

// 0x134e320
void SetUvTable_20243232(XRD773Unity_CommonMesh *this, sdfVector2_t **pos) {
  this->uv = pos;
}

// 0x134dba0
void Setting(XRD773Unity_CommonMesh *this) {
  UnityEngine_Object_o *texture;
  UnityEngine_MaterialPropertyBlock_o *block;
  UnityEngine_MaterialPropertyBlock_o *v9;

  Clear(this->mesh, 0);
  set_vertices(this->mesh, this->position);
  set_uv(this->mesh, this->uv);
  set_colors(this->mesh, this->color);
  set_triangles(this->mesh, this->index);
  RecalculateBounds(this->mesh);
  if (this->use_texture)
  {
    Clear_27250688(this->block);
    texture = this->texture;
    if (op_Inequality(texture, 0, 0))
    {
      block = this->block;
      {
      }
      SetTexture_27252016(block, main_tex_id, this->texture);
    }
    if (this->use_palette)
    {
      v9 = this->block;
      {
      }
      SetTexture_27252016(v9, palette_id, this->palette);
    }
    SetPropertyBlock(this->_renderer, this->block);
  }
}

// 0x134dee0
void _SetDrawMode(XRD773Unity_CommonMesh *this, s32 mode) {
  XRD773Unity_GraphicManager_o *Instance;
  UnityEngine_Material_o *PaletteMat;
  XRD773Unity_GraphicManager_o *v7;
  XRD773Unity_GraphicManager_o *v8;

  if (this->use_texture)
  {
    if (this->use_palette)
    {
      {
      }
      Instance = get_Instance();
      PaletteMat = GetPaletteMat(Instance, mode);
    }
    else
    {
      {
      }
      v8 = get_Instance();
      PaletteMat = GetNormalMat(v8, mode);
    }
  }
  else
  {
    {
    }
    v7 = get_Instance();
    PaletteMat = GetPlaneMat(v7, mode);
  }
  (this->klass->vtable._5__SetMaterial.methodPtr)(this, PaletteMat, this->klass->vtable._5__SetMaterial.method);
}

// 0x134ded0
void _SetMaterial(XRD773Unity_CommonMesh *this, void *material) {
  set_sharedMaterial(this->_renderer, material);
}
