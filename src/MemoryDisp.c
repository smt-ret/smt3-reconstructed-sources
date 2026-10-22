#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct MemoryDisp MemoryDisp;

char **GetKeys(AssetBundleCtrl *this);

// 0x1294390
void Start(MemoryDisp *this) {
  this->rect = GetComponent_GUILayer_(this);
}

// 0x12943f0
void Update(MemoryDisp *this) {
  TMPro_TMP_Text_o *Reserved;
  System_String_o *v4;
  System_String_o *v5;
  TMPro_TMP_Text_o *Allocated;
  System_String_o *v7;
  System_String_o *v8;
  TMPro_TMP_Text_o *Unused;
  System_String_o *v10;
  System_String_o *v11;
  TMPro_TMP_Text_o *GC_heap;
  System_String_o *v13;
  System_String_o *v14;
  TMPro_TMP_Text_o *GC_used;
  System_String_o *v16;
  System_String_o *v17;
  struct UnityEngine_GameObject_array *AllocatedObj;
  il2cpp_array_size_t max_length;
  u32 v22;
  s64 v23;
  struct UnityEngine_GameObject_array *v25;
  s64 v27;
  AssetBundleCtrl_o *asset_bc;
  System_String_array *Keys;
  TMPro_TMP_Text_o *ReservedCnt;
  System_String_array *v31;
  System_String_o *v32;
  u64 i;
  System_Text_StringBuilder_o *asset_str;
  System_String_o *v36;
  TMPro_TMP_Text_o *AllocatedList;
  System_String_o *v38;
  s64 v39;
  struct UnityEngine_GameObject_array *v41;
  s64 v43;
  s32 v44;
  f64 v45;

  v44 = 0;
  Reserved = this->Reserved;
  v45 = GetTotalReservedMemoryLong() / this->mega;
  v4 = sub_196BC0(&v45, "F2");
  v5 = Concat_5224608(v4, "M");
  set_text(Reserved, v5);
  Allocated = this->Allocated;
  v45 = GetTotalAllocatedMemoryLong() / this->mega;
  v7 = sub_196BC0(&v45, "F2");
  v8 = Concat_5224608(v7, "M");
  set_text(Allocated, v8);
  Unused = this->Unused;
  v45 = GetTotalUnusedReservedMemoryLong() / this->mega;
  v10 = sub_196BC0(&v45, "F2");
  v11 = Concat_5224608(v10, "M");
  set_text(Unused, v11);
  GC_heap = this->GC_heap;
  v45 = GetMonoHeapSizeLong() / this->mega;
  v13 = sub_196BC0(&v45, "F2");
  v14 = Concat_5224608(v13, "M");
  set_text(GC_heap, v14);
  GC_used = this->GC_used;
  v45 = get_usedHeapSizeLong() / this->mega;
  v16 = sub_196BC0(&v45, "F2");
  v17 = Concat_5224608(v16, "M");
  set_text(GC_used, v17);
  AllocatedObj = this->AllocatedObj;
  max_length = AllocatedObj->max_length;
  v22 = max_length;
  if (fldDbg->MemoryDisp == 2)
  {
    if (max_length >= 1)
    {
      v23 = 4;
      do
      {
        if (!get_activeSelf(*(&AllocatedObj->obj.klass + v23), 0))
        {
          v25 = this->AllocatedObj;
          SetActive(*(&v25->obj.klass + v23), 1, 0);
        }
        AllocatedObj = this->AllocatedObj;
        v22 = AllocatedObj->max_length;
        v27 = v23 - 3;
        ++v23;
      }
      while (v27 < v22);
    }
    asset_bc = get_asset_bc();
    Keys = GetKeys(asset_bc);
    v44 = Keys->max_length;
    ReservedCnt = this->ReservedCnt;
    v31 = Keys;
    v32 = sub_232970(&v44);
    set_text(ReservedCnt, v32);
    Clear(this->asset_str, 0);
    if (v44 >= 1)
    {
      for (i = 0; i < v44; ++i)
      {
        asset_str = this->asset_str;
        v36 = Concat_5224608(v31->m_Items[i], "\n");
        Append_5380272(asset_str, v36);
      }
    }
    AllocatedList = this->AllocatedList;
    v38 = (this->asset_str->klass->vtable._3_ToString.methodPtr)(
            this->asset_str,
            this->asset_str->klass->vtable._3_ToString.method);
    set_text(AllocatedList, v38);
  }
  else if (max_length >= 1)
  {
    v39 = 4;
    do
    {
      if (get_activeSelf(*(&AllocatedObj->obj.klass + v39), 0))
      {
        v41 = this->AllocatedObj;
        SetActive(*(&v41->obj.klass + v39), 0, 0);
      }
      AllocatedObj = this->AllocatedObj;
      v22 = AllocatedObj->max_length;
      v43 = v39 - 3;
      ++v39;
    }
    while (v43 < v22);
  }
}
