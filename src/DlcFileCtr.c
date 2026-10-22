#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct DlcFileCtr DlcFileCtr;
typedef struct DlcFileCtr_Data DlcFileCtr_Data;
typedef struct DlcFileCtr__LoadCoroutine_d__9 DlcFileCtr__LoadCoroutine_d__9;

struct DlcFileCtr {
    void *contents;
    s32 LoadSize;
};

struct DlcFileCtr_Data {
    s32 id;
    char *mount;
    u8 *buf;
};

struct DlcFileCtr__LoadCoroutine_d__9 {
    s32 __1__state;
    void *__2__current;
    DlcFileCtr *__4__this;
    s32 dlc_id;
    char *aname;
    void *req;
};

void LoadDirect(AssetBundleCtrl *this, char *key, char *aname, s32 dlc_id);

// 0xfe5dd0
bool Check(DlcFileCtr *this, s32 id) {
  s32 Count;
  s32 v6;
  s32 v7;

  Count = _get_Count(this->contents);
  if (Count < 1)
  {
    v7 = -1;
  }
  else
  {
    v6 = Count;
    v7 = 0;
    while (*&_get_Item(
                this->contents,
                v7)->isLongReference != id)
    {
      if (++v7 >= v6)
      {
        v7 = -1;
        return v7 >= 0;
      }
    }
  }
  return v7 >= 0;
}

// 0xfe5d10
s32 GetIndex(DlcFileCtr *this, s32 id) {
  s32 Count;
  s32 v6;
  s32 v7;

  Count = _get_Count(this->contents);
  if (Count < 1)
    return -1;
  v6 = Count;
  v7 = 0;
  while (*&_get_Item(
              this->contents,
              v7)->isLongReference != id)
  {
    if (++v7 >= v6)
      return -1;
  }
  return v7;
}

// 0xfdce50
void Load(DlcFileCtr *this, char *key, s32 id, char *aname) {
  AssetBundleCtrl_o *Ctrl_k__BackingField;
  System_String_o *v10;

LABEL_7:
  Ctrl_k__BackingField = _Ctrl_k__BackingField;
  v10 = ToLower(aname, 0);
  LoadDirect(Ctrl_k__BackingField, key, v10, id);
}

// 0xfdbf80
void *LoadCoroutine(DlcFileCtr *this, char *aname, s32 dlc_id, void **req) {
  u64 *v9;

  v9 = Allocate(DlcFileCtr__LoadCoroutine_d__9);
  _ctor(v9, 0);
  *(v9 + 4) = 0;
  v9[4] = this;
  *(v9 + 10) = dlc_id;
  v9[6] = aname;
  v9[7] = req;
  return v9;
}

// 0xfe5e90
bool Mount(DlcFileCtr *this, s32 id) {
  s32 Count;
  s32 v6;
  s32 v7;
  System_WeakReference_o *Item;
  System_Byte_array *v10;
  System_String_o *v11;
  System_String_o *v12;
  u16 v13;
  s64 pOutValue;
  u32 innerValue;

  innerValue = 0;
  pOutValue = 0;
  v13 = 0;
  Count = _get_Count(this->contents);
  if (Count < 1)
    return 0;
  v6 = Count;
  v7 = 0;
  while (*&_get_Item(
              this->contents,
              v7)->isLongReference != id)
  {
    if (++v7 >= v6)
      return 0;
  }
  Item = _get_Item(
           this->contents,
           v7);
  if (op_Equality(Item[1].klass, Empty, 0))
  {
    pOutValue = 0;
    innerValue = QueryMountCacheSize(&pOutValue, id).innerValue;
    sub_15C5000(&innerValue);
    v10 = NewSpecific(byte, pOutValue);
    v13 = v7 + 65;
    v11 = sub_3C3A80(&v13, 0);
    v12 = Concat_5224608("dlc", v11);
    innerValue = Mount(v12, id, v10, pOutValue, 0).innerValue;
    sub_15C5000(&innerValue);
    _get_Item(
      this->contents,
      v7)[1].klass = v12;
    _get_Item(
      this->contents,
      v7)[1].monitor = v10;
  }
  return 1;
}

// 0xfe6070
void Unmount(DlcFileCtr *this, s32 id) {
  s32 Count;
  s32 v6;
  s32 v7;
  System_WeakReference_o *Item;
  System_WeakReference_o *v9;

  Count = _get_Count(this->contents);
  if (Count >= 1)
  {
    v6 = Count;
    v7 = 0;
    while (*&_get_Item(
                this->contents,
                v7)->isLongReference != id)
    {
      if (++v7 >= v6)
        return;
    }
    Item = _get_Item(
             this->contents,
             v7);
    if (op_Inequality(Item[1].klass, Empty, 0))
    {
      v9 = _get_Item(
             this->contents,
             v7);
      Unmount(v9[1].klass, 0);
      _get_Item(
        this->contents,
        v7)[1].klass = Empty;
      _get_Item(
        this->contents,
        v7)[1].monitor = 0;
    }
  }
}
