#include "types.h"

typedef struct FlipAnimation2 FlipAnimation2;
typedef struct FlipAnimation2_SEEK FlipAnimation2_SEEK;

struct FlipAnimation2_SEEK {
    s32 value__;
};

void update_texture(FlipAnimation2 *this);

// 0x113dc70
void AnimStart(FlipAnimation2 *this) {
  this->trigger = 1;
}

// 0x113dc80
void AnimStop(FlipAnimation2 *this) {
  this->trigger = 0;
  SetTexture(this->mat, "_MainTex", 0, 0);
}

// 0x113d690
void Start(FlipAnimation2 *this) {
  UnityEngine_Renderer_o *Component_GUILayer;
  UnityEngine_MeshFilter_o *v4;
  struct UnityEngine_Mesh_o *mesh;
  struct UnityEngine_Texture_array *Images;
  struct UnityEngine_Texture_array *v7;
  s64 stepcnt;
  s32 v10;
  struct UnityEngine_Texture_array *v11;
  s64 v12;
  s32 v14;
  f32 x;
  bool v16;
  f32 y;
  f32 v18;
  f32 v19;
  f32 v20;
  f32 width;

  Component_GUILayer = GetComponent_GUILayer_(this);
  this->mat = get_material(Component_GUILayer);
  v4 = GetComponent_GUILayer_(this);
  mesh = get_mesh(v4);
  Images = this->Images;
  this->mesh = mesh;
  this->stepcnt = 0;
  this->img_len = Images->max_length;
  if (Images->max_length)
  {
    SetTexture(this->mat, "_MainTex", 0, 0);
    v7 = this->Images;
    stepcnt = this->stepcnt;
    v10 = (v7->m_Items[stepcnt]->klass->vtable._4_get_width.methodPtr)(
            v7->m_Items[stepcnt],
            v7->m_Items[stepcnt]->klass->vtable._4_get_width.method);
    v11 = this->Images;
    this->width = v10;
    v12 = this->stepcnt;
    v14 = (v11->m_Items[v12]->klass->vtable._6_get_height.methodPtr)(
            v11->m_Items[v12],
            v11->m_Items[v12]->klass->vtable._6_get_height.method);
    x = this->Uv.x;
    v16 = this->StartFlag == 0;
    this->height = v14;
    *&this->seekx = 0;
    this->finished = 0;
    this->trigger = v16;
    if (x == 0.0)
    {
      this->uvset = 0;
LABEL_10:
      this->Count = this->Images->max_length;
      return;
    }
    y = this->Uv.y;
    this->uvset = y != 0.0;
    if (y == 0.0)
      goto LABEL_10;
    if (this->Pattern)
    {
      v18 = v14;
      v19 = this->Uv.y;
      v20 = v14 / v19;
      width = this->width;
    }
    else
    {
      width = this->width;
      v19 = this->Uv.y;
      v18 = v14;
      v20 = width / x;
    }
    this->lcnt = v20;
    this->tex_off.x = x / width;
    this->tex_off.y = v19 / v18;
  }
}

// 0x113d870
void Update(FlipAnimation2 *this) {
  if (!this->finished && this->trigger)
    update_texture(this);
}

// 0x113d890
void update_texture(FlipAnimation2 *this) {
  s32 seekx;
  f32 x;
  f32 v5;
  UnityEngine_Vector2_array *uv;
  f32 v7;
  il2cpp_array_size_t max_length;
  f32 v10;
  f32 v11;
  f32 v12;
  s32 v14;
  s32 v15;
  s32 v16;
  s32 v17;
  u32 v18;
  s32 seeky;
  s32 v20;
  s32 lcnt;
  s32 Count;
  s32 v23;
  s32 img_len;
  s32 v25;
  UnityEngine_Material_o *mat;
  struct UnityEngine_Texture_array *Images;

  if (!this->uvset)
    goto LABEL_22;
  seekx = this->seekx;
  x = this->tex_off.x;
  v5 = this->tex_off.y * this->seeky;
  uv = get_uv(this->mesh);
  v7 = 1.0 - v5;
  max_length = uv->max_length;
  uv->m_Items[1].y = v7;
  uv->m_Items[0].y = v7;
  v10 = x * seekx;
  v11 = 1.0 - (v5 + this->tex_off.y);
  uv->m_Items[3].y = v11;
  uv->m_Items[2].y = v11;
  v12 = v10 + this->tex_off.x;
  uv->m_Items[3].x = v12;
  uv->m_Items[1].x = v12;
  uv->m_Items[2].x = v10;
  uv->m_Items[0].x = v10;
  set_uv(this->mesh, uv);
  if (!this->Pattern)
  {
    seeky = this->seeky;
    v20 = this->seekx + 1;
    lcnt = this->lcnt;
    Count = this->Count;
    this->seekx = v20;
    if (v20 + lcnt * seeky >= Count)
    {
      if (!this->Loop)
        goto LABEL_28;
      seeky = 0;
      v20 = 0;
      this->stepcnt = 0;
      *&this->seekx = 0;
    }
    if ((this->Uv.x * v20) < this->width)
      goto LABEL_22;
    v23 = seeky + 1;
    this->seekx = 0;
    this->seeky = v23;
    if (lcnt * v23 < Count)
      goto LABEL_22;
    goto LABEL_15;
  }
  v14 = this->seekx;
  v15 = this->seeky + 1;
  v16 = this->lcnt;
  v17 = this->Count;
  this->seeky = v15;
  if (v15 + v16 * v14 >= v17)
  {
    if (!this->Loop)
      goto LABEL_28;
    v14 = 0;
    v15 = 0;
    this->stepcnt = 0;
    *&this->seekx = 0;
  }
  if ((this->Uv.y * v15) >= this->height)
  {
    v18 = v14 + 1;
    *&this->seekx = v18;
    if ((v16 * v18) >= v17)
    {
LABEL_15:
      if (!this->Loop)
        goto LABEL_28;
      this->stepcnt = 0;
      *&this->seekx = 0;
    }
  }
LABEL_22:
  img_len = this->img_len;
  v25 = this->stepcnt + 1;
  this->stepcnt = v25;
  if (v25 == img_len)
  {
    if (this->Loop)
    {
      v25 = 0;
      this->stepcnt = 0;
      goto LABEL_25;
    }
LABEL_28:
    this->finished = 1;
    return;
  }
LABEL_25:
  mat = this->mat;
  Images = this->Images;
  SetTexture(mat, "_MainTex", Images->m_Items[v25], 0);
}
