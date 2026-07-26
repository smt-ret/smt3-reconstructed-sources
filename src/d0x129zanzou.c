#include "types.h"

typedef struct FieldChrHD FieldChrHD;
typedef struct d0x129zanzou d0x129zanzou;

static s32 id_BlendPower;

bool ChkMotion(FieldChrHD *this, s32 motion);

// 0x161ea30
void OnDestroy(d0x129zanzou *this) {
  u64 v3;
  s64 i;
  struct UnityEngine_Material_array_array *mat_list;
  u64 v6;
  struct UnityEngine_Material_array_array *v8;
  UnityEngine_Material_array *v10;
  UnityEngine_Object_o *v12;
  struct UnityEngine_Material_array_array *v13;
  UnityEngine_Material_array *v15;
  s32 v17;
  System_WeakReference_o *Item;
  UnityEngine_Object_o *sharedMesh;
  System_WeakReference_o *v21;

  if (this->CloneCount >= 1)
  {
    v3 = 0;
    for (i = 4; ; i = 4)
    {
      while (1)
      {
        mat_list = this->mat_list;
        v6 = i - 4;
        if (v6 >= SLODWORD(mat_list->m_Items[v3]->max_length))
          break;
        v8 = this->mat_list;
        v10 = v8->m_Items[v3];
        v12 = *(&v10->obj.klass + i);
        Destroy_27360000(v12);
        v13 = this->mat_list;
        v15 = v13->m_Items[v3];
        *(&v15->obj.klass + i++) = 0;
      }
      if (++v3 >= this->CloneCount)
        break;
    }
  }
  if (_get_Count(this->BakeCloneMeshList) >= 1)
  {
    v17 = 0;
    do
    {
      Item = _get_Item(
               this->BakeCloneMeshList,
               v17);
      sharedMesh = get_sharedMesh(Item);
      Destroy_27360000(sharedMesh);
      v21 = _get_Item(
              this->BakeCloneMeshList,
              v17);
      set_sharedMesh(v21, 0);
      ++v17;
    }
    while (v17 < _get_Count(this->BakeCloneMeshList));
  }
}

// 0x161e5a0
void Start(d0x129zanzou *this) {
  u64 *v3;
  struct System_Single_array *v4;
  s32 CloneCount;
  u64 v6;
  Il2CppObject *BakeMeshObj;
  UnityEngine_Transform_o *transform;
  Il2CppObject *v12;
  struct System_Collections_Generic_List_SkinnedMeshRenderer__o *BakeCloneMeshList;
  UnityEngine_GameObject_o *v14;
  Il2CppObject *Component_object;
  Il2CppObject *v16;
  UnityEngine_Material_array *materials;
  u32 *mat_list;
  UnityEngine_Material_array *v19;
  s64 *v20;
  s64 *v21;
  u32 *blendpow;
  s64 *v24;
  s64 *v26;
  il2cpp_array_size_t max_length;
  u64 v29;
  UnityEngine_Material_o **m_Items;
  struct UnityEngine_Material_array_array *v32;
  u32 *v33;
  UnityEngine_Material_o *v34;
  struct System_Single_array_array *v38;
  System_Single_array *v40;
  UnityEngine_Material_o *v44;
  struct System_Single_array_array *v45;
  System_Single_array *v47;
  struct System_Single_array *blendspd;

  v3 = Allocate(System_Collections_Generic_List_SkinnedMeshRenderer_);
  __ctor(
    v3);
  this->BakeCloneMeshList = v3;
  this->mat_list = NewSpecific(UnityEngine_Material__, this->CloneCount);
  this->blendpow = NewSpecific(float__, this->CloneCount);
  v4 = NewSpecific(f32, this->CloneCount);
  CloneCount = this->CloneCount;
  this->blendspd = v4;
  if (CloneCount >= 1)
  {
    v6 = 0;
    do
    {
      BakeMeshObj = this->BakeMeshObj;
      transform = get_transform(this->InstantiateObj, 0);
      v12 = Instantiate_object__425664(BakeMeshObj, transform, 0);
      BakeCloneMeshList = this->BakeCloneMeshList;
      v14 = v12;
      Component_object = GetComponent_object_(v12);
      _Add(BakeCloneMeshList, Component_object);
      v16 = GetComponent_object_(v14);
      materials = get_materials(v16);
      mat_list = this->mat_list;
      v19 = materials;
      v20 = NewSpecific(UnityEngine_Material, LODWORD(materials->max_length));
      v21 = v20;
      *&mat_list[2 * v6 + 8] = v21;
      blendpow = this->blendpow;
      v24 = NewSpecific(f32, LODWORD(v19->max_length));
      v26 = v24;
      *&blendpow[2 * v6 + 8] = v26;
      max_length = v19->max_length;
      if (max_length >= 1)
      {
        v29 = 0;
        m_Items = v19->m_Items;
        do
        {
          v32 = this->mat_list;
          v33 = v32->m_Items[v6];
          v34 = m_Items[v29];
          *&v33[2 * v29 + 8] = v34;
          v38 = this->blendpow;
          v40 = v38->m_Items[v6];
          v40->m_Items[v29] = this->blendini;
          v44 = m_Items[v29];
          v45 = this->blendpow;
          v47 = v45->m_Items[v6];
          SetFloat_27246832(v44, id_BlendPower, v47->m_Items[v29]);
          LODWORD(max_length) = v19->max_length;
          ++v29;
        }
        while (v29 < max_length);
      }
      blendspd = this->blendspd;
      blendspd->m_Items[v6++] = -10.0;
    }
    while (v6 < this->CloneCount);
  }
}

// 0x161ec50
void Update(d0x129zanzou *this) {
    ChkMotion(0, 0);
}
