#include "types.h"

typedef struct UiHD UiHD;
typedef struct UiHDMesh UiHDMesh;
typedef struct XRD773Unity_GraphicManager XRD773Unity_GraphicManager;

f32 GetConfigBright(void);
u32 GetDrawFlag(void);
void *GetNormalMat(XRD773Unity_GraphicManager *this, s32 mode);
void RefreshTmpMat(UiHD *this);
void SetDrawFlag(u32 flag, u32 cnt);
void SetLightAll(UiHDMesh *this, void *rootobj);
void SetMatInit(UiHDMesh *this, void *rootobj);
void SetMatInit2(UiHD *this, void *childobj);
void SetTextMeshBright(void);

// 0x1348410
void Awake(UiHD *this) {
  u64 *v3;
  u64 *v4;
  u64 *v5;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  UnityEngine_GameObject_o *v9;
  UnityEngine_GameObject_o *v11;

  v3 = Allocate(System_Collections_Generic_List_Material_);
  __ctor(v3);
  this->mat_list = v3;
  v4 = Allocate(System_Collections_Generic_List_Material_);
  __ctor(v4);
  this->tmp_list = v4;
  v5 = Allocate(System_Collections_Generic_List_GameObject_);
  __ctor(v5);
  this->tmp_obj = v5;
  *&this->tmp_refresh = 0;
  gameObject = get_gameObject(this);
  Component_object = GetComponent_object_(gameObject);
  if (op_Inequality(Component_object, 0, 0))
    this->outline = 1;
  v9 = get_gameObject(this);
  SetMatInit(this, v9);
  get_gameObject(this);
  SetLightAll(this, v11);
}

// 0x1348e70
void LateUpdate(UiHD *this) {
  UnityEngine_GameObject_o *v5;

  if ((GetDrawFlag() & 0x80000000) == 0)
  {
    SetTextMeshBright();
    SetDrawFlag(0x80000000, 1u);
  }
  if (this->tmp_refresh)
    RefreshTmpMat(this);
  get_gameObject(this);
  SetLightAll(this, v5);
}

// 0x1348d10
void RefreshTmpMat(UiHD *this) {
  s32 v3;
  System_WeakReference_o *Item;
  UnityEngine_Component_o *transform;
  UnityEngine_GUILayer_o *Component_GUILayer;
  s64 v7;
  s64 v8;
  s64 v9;
  u64 v10;
  s64 v11;

  _Clear(this->tmp_list);
  if (_get_Count(this->tmp_obj) >= 1)
  {
    v3 = 0;
    do
    {
      Item = _get_Item(
               this->tmp_obj,
               v3);
      transform = get_transform(Item, 0);
      Component_GUILayer = GetComponent_GUILayer_(transform);
      v7 = (*&Component_GUILayer->klass[3]._2.thread_static_fields_size)(
             Component_GUILayer,
             *&Component_GUILayer->klass[3]._2.flags);
      v8 = *(v7 + 24);
      if (v8 >= 1)
      {
        v9 = v7;
        v10 = 0;
        v11 = v7 + 32;
        do
        {
          _Add(
            this->tmp_list,
            *(v11 + 8 * v10));
          LODWORD(v8) = *(v9 + 24);
          ++v10;
        }
        while (v10 < v8);
      }
      ++v3;
    }
    while (v3 < _get_Count(this->tmp_obj));
  }
}

// 0x1348600
void SetLightAll(UiHD *this, void *rootobj) {
  f32 ConfigBright;
  s32 v5;
  System_WeakReference_o *Item;
  s32 v7;
  System_WeakReference_o *v8;
  s32 id_Config_Bright;

  ConfigBright = GetConfigBright();
  if (_get_Count(this->mat_list) >= 1)
  {
    v5 = 0;
    do
    {
      Item = _get_Item(
               this->mat_list,
               v5);
      if (HasProperty_27243776(Item, StringLiteral_5226))
        SetFloat_27246832(Item, this->id_Config_Bright, ConfigBright);
      ++v5;
    }
    while (v5 < _get_Count(this->mat_list));
  }
  if (_get_Count(this->tmp_list) >= 1)
  {
    v7 = 0;
    do
    {
      v8 = _get_Item(
             this->tmp_list,
             v7);
      if (HasProperty_27243776(v8, StringLiteral_5226))
      {
        id_Config_Bright = this->id_Config_Bright;
        if (id_Config_Bright == -1)
        {
          id_Config_Bright = PropertyToID(StringLiteral_5226);
          this->id_Config_Bright = id_Config_Bright;
        }
        SetFloat_27246832(v8, id_Config_Bright, ConfigBright);
      }
      ++v7;
    }
    while (v7 < _get_Count(this->tmp_list));
  }
}

// 0x1348550
void SetMatInit(UiHD *this, void *rootobj) {
  UnityEngine_Transform_o *transform;
  s32 v6;
  UnityEngine_Transform_o *v7;
  UnityEngine_Component_o *Child;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Transform_o *v12;

  SetMatInit2(this, rootobj);
  transform = get_transform(rootobj, 0);
  if (get_childCount(transform) >= 1)
  {
    v6 = 0;
    do
    {
      v7 = get_transform(rootobj, 0);
      Child = GetChild(v7, v6);
      gameObject = get_gameObject(Child);
      SetMatInit2(this, gameObject);
      SetMatInit(this, gameObject);
      ++v6;
      v12 = get_transform(rootobj, 0);
    }
    while (v6 < get_childCount(v12));
  }
}

// 0x13487a0
void SetMatInit2(UiHD *this, void *childobj) {
  UnityEngine_Component_o *transform;
  UnityEngine_Object_o *Component_GUILayer;
  UnityEngine_Object_o *v9;
  UnityEngine_Object_o *v11;
  System_String_o *name;
  XRD773Unity_GraphicManager_o *Instance;
  UnityEngine_Material_o *NormalMat;
  struct System_Collections_Generic_List_Material__o *mat_list;
  mdlEffectResrcItem_t_o *v16;
  UnityEngine_Component_o *v17;
  UnityEngine_Object_o *v19;
  UnityEngine_Object_o *v21;
  UnityEngine_Object_o *v23;
  System_String_o *v24;
  XRD773Unity_GraphicManager_o *v25;
  UnityEngine_Material_o *v26;
  struct System_Collections_Generic_List_Material__o *v27;
  mdlEffectResrcItem_t_o *v28;
  UnityEngine_Component_o *v29;
  UnityEngine_Object_o *v31;
  s64 v32;
  s64 v33;
  s64 v34;
  u64 v35;
  s64 v36;
  UnityEngine_GameObject_o *gameObject;
  Il2CppObject *Component_object;
  UnityEngine_Object_o *v42;
  System_String_o *v43;
  XRD773Unity_GraphicManager_o *v44;
  UnityEngine_Material_o *v45;
  UnityEngine_Material_o *material;
  UnityEngine_Object_o *v47;
  System_String_o *v48;
  XRD773Unity_GraphicManager_o *v50;
  UnityEngine_Material_o *v51;
  UnityEngine_Material_o *v52;

  transform = get_transform(childobj, 0);
  Component_GUILayer = GetComponent_GUILayer_(transform);
  if (op_Inequality(Component_GUILayer, 0, 0))
  {
    v9 = (Component_GUILayer->klass[2]._1.parent)(Component_GUILayer, Component_GUILayer->klass[2]._1.generic_class);
    if (op_Equality(v9, 0, 0)
      || (v11 = (Component_GUILayer->klass[2]._1.parent)(
                  Component_GUILayer,
                  Component_GUILayer->klass[2]._1.generic_class),
          name = get_name(v11),
          Contains(name, StringLiteral_12221, 0)))
    {
      {
      }
      Instance = get_Instance();
      NormalMat = GetNormalMat(Instance, 20);
      (Component_GUILayer->klass[2]._1.typeDefinition)(
        Component_GUILayer,
        NormalMat,
        Component_GUILayer->klass[2]._1.interopData);
    }
    mat_list = this->mat_list;
    v16 = (Component_GUILayer->klass[2]._1.parent)(Component_GUILayer, Component_GUILayer->klass[2]._1.generic_class);
    _Add(mat_list, v16);
  }
  v17 = get_transform(childobj, 0);
  v19 = GetComponent_GUILayer_(v17);
  if (op_Inequality(v19, 0, 0))
  {
    v21 = (v19->klass[2]._1.parent)(v19, v19->klass[2]._1.generic_class);
    if (op_Equality(v21, 0, 0)
      || (v23 = (v19->klass[2]._1.parent)(v19, v19->klass[2]._1.generic_class),
          v24 = get_name(v23),
          Contains(v24, StringLiteral_12221, 0)))
    {
      {
      }
      v25 = get_Instance();
      v26 = GetNormalMat(v25, 20);
      (v19->klass[2]._1.typeDefinition)(v19, v26, v19->klass[2]._1.interopData);
    }
    v27 = this->mat_list;
    v28 = (v19->klass[2]._1.parent)(v19, v19->klass[2]._1.generic_class);
    _Add(v27, v28);
  }
  v29 = get_transform(childobj, 0);
  v31 = GetComponent_GUILayer_(v29);
  if (op_Inequality(v31, 0, 0))
  {
    _Add(this->tmp_obj, childobj);
    v32 = (*&v31->klass[3]._2.thread_static_fields_size)(v31, *&v31->klass[3]._2.flags);
    v33 = *(v32 + 24);
    if (v33 >= 1)
    {
      v34 = v32;
      v35 = 0;
      v36 = v32 + 32;
      do
      {
        _Add(
          this->tmp_list,
          *(v36 + 8 * v35));
        this->tmp_refresh = 1;
        LODWORD(v33) = *(v34 + 24);
        ++v35;
      }
      while (v35 < v33);
    }
  }
  if (this->outline)
  {
    gameObject = get_gameObject(this);
    Component_object = GetComponent_object_(gameObject);
    if (op_Inequality(Component_object, 0, 0))
    {
      v42 = get_gameObject(this);
      v43 = get_name(v42);
      if (Contains(v43, StringLiteral_12222, 0))
      {
        {
        }
        v44 = get_Instance();
        v45 = GetNormalMat(v44, 20);
        set_material(Component_object, v45);
        material = get_material(Component_object);
        set_renderQueue(material, 2999);
      }
    }
    if (op_Inequality(Component_object, 0, 0))
    {
      v47 = get_gameObject(this);
      v48 = get_name(v47);
      if (Contains(v48, StringLiteral_12223, 0))
      {
        {
        }
        v50 = get_Instance();
        v51 = GetNormalMat(v50, 20);
        set_material(Component_object, v51);
        v52 = get_material(Component_object);
        set_renderQueue(v52, 2999);
      }
    }
  }
}

// 0x1348f50
void SetMatrial(UiHD *this, void *mat) {
  _Add(this->mat_list, mat);
}

// 0x1348e60
void Start(UiHD *this) {
  ;
}
