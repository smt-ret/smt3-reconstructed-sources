#include "types.h"

typedef struct AssetBundleCtrl AssetBundleCtrl;
typedef struct btlKutiManager btlKutiManager;
typedef struct evtKutiManager evtKutiManager;
typedef struct evtUnitHandle_t evtUnitHandle_t;

void *GetAnimator(void *obj);
bool IsSpeaking(void);
void *LoadFileObject(AssetBundleCtrl *this, char *key, char *path_name);
void Log(char *fmt, void **parray);
void StopKuti(btlKutiManager *this);
void mdlMotionStopKutiForUnity(evtUnitHandle_t **h, s32 index, bool sw);
void mdlSmoothLoopMotionForUnity(evtUnitHandle_t **h, s32 layer, s32 motion, s32 before, s32 wait, bool btl);

// 0x10ea6b0
void Append(evtKutiManager *this, char *key, char *path, bool evt) {
  s64 **v9;
  s64 *v10;
  System_String_array *v11;
  System_String_o *v18;
  u64 *v19;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *FileObject;
  s64 typeHierarchyDepth;
  System_Byte_array *bytes;
  System_Text_Encoding_o *Unicode;
  System_String_o *v26;
  System_String_array *v27;
  System_String_array *v29;
  s32 v30;
  System_String_array *v31;
  u64 v32;
  s64 v33;
  System_String_o *v35;
  u64 *v36;
  System_String_array *v38;
  u64 *v39;
  il2cpp_array_size_t max_length;
  s64 v41;
  s64 v43;
  u64 *v46;
  System_String_o *v47;
  System_Object_array *v49;
  s32 Count;
  f32 result;

  v9 = &"event";
  result = 0.0;
  if (!evt)
    v9 = &"fld/f";
  v10 = *v9;
  v11 = NewSpecific(string, 6u);
  v11->m_Items[0] = "dds3data/";
  v11->m_Items[1] = v10;
  v11->m_Items[2] = "/";
  v11->m_Items[3] = key;
  v11->m_Items[4] = "/";
  v11->m_Items[5] = path;
  v18 = Concat_5271600(v11);
  v19 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v19);
  asset_bc = get_asset_bc();
  FileObject = LoadFileObject(asset_bc, key, v18);
  if (FileObject)
  {
    if (FileObject->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
    {
      if (FileObject->klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_TextAsset)
        FileObject = 0;
    }
    else
    {
      FileObject = 0;
    }
    bytes = get_bytes(FileObject);
    Unicode = get_Unicode();
    v26 = (Unicode->klass[1]._1.byval_arg.data)(Unicode, bytes, *&Unicode->klass[1]._1.byval_arg.bits);
    v27 = NewSpecific(string, 1u);
    v27->m_Items[0] = "\r\n";
    v29 = Split_5246672(v26, v27, 0);
    v30 = v29->max_length - 1;
    if (v30 >= 1)
    {
      v31 = v29;
      v32 = 0;
      v33 = v30;
      while (1)
      {
        v35 = v31->m_Items[v32];
        v36 = NewSpecific(char, 1u);
        *(v36 + 16) = 44;
        v38 = Split(v35, v36);
        v39 = Allocate(System_Collections_Generic_List_float_);
        __ctor(v39);
        _Add(v39, 0.0);
        max_length = v38->max_length;
        if (max_length >= 3)
        {
          v41 = 6;
          do
          {
            result = 0.0;
            if (TryParse(*(&v38->obj.klass + v41), &result, 0))
              _Add(v39, result);
            LODWORD(max_length) = v38->max_length;
            v43 = v41 - 3;
            ++v41;
          }
          while (v43 < max_length);
        }
        if (!Animator___ContainsKey(this->TimeLine, v38->m_Items[0]))
        {
          PropertySheet___Add(this->TimeLine, v38->m_Items[0], v39);
        }
        if (++v32 == v33)
          break;
      }
    }
    Count = HashSet_Text____get_Count(this->TimeLine);
    v46 = sub_8D3950(s32, &Count);
    v47 = Concat("Init Finished : ", v46);
    v49 = Empty_string_();
    Log(v47, v49, 0);
  }
}

// 0x10e9f40
void Awake(evtKutiManager *this) {
  PropertySheet___Clear(this->TimeLine);
  this->KutiSwitch = 0;
  this->MsgTime = 0.0;
  this->hUnit = 0;
  this->KutiName = 0;
}

// 0x10e9fb0
void Clear(evtKutiManager *this, bool sw) {
  if (sw)
    PropertySheet___Clear(this->TimeLine);
  this->KutiSwitch = 0;
  this->MsgTime = 0.0;
  this->hUnit = 0;
  this->KutiName = 0;
}

// 0x10eb570
bool Contains(evtKutiManager *this) {
  return !IsNullOrEmpty(this->KutiName)
      && HashSet_Text____get_Count(this->TimeLine)
      && Animator___ContainsKey(this->TimeLine, this->KutiName);
}

// 0x10eae00
void FixedUpdate(evtKutiManager *this) {
  evtUnitHandle_t_o *hUnit;
  f32 deltaTime;

  hUnit = this->hUnit;
  if (hUnit)
  {
    deltaTime = get_deltaTime();
    IsSpeaking(this, hUnit, deltaTime);
  }
}

// 0x10ea030
void Initialize(evtKutiManager *this, char *key, char *path, bool evt) {
  s64 **v8;
  s64 *v9;
  System_String_array *v10;
  System_String_o *v17;
  u64 *v18;
  AssetBundleCtrl_o *asset_bc;
  Il2CppObject *FileObject;
  s64 typeHierarchyDepth;
  System_Byte_array *bytes;
  System_Text_Encoding_o *Unicode;
  System_String_o *v25;
  System_String_array *v26;
  System_String_array *v28;
  s32 v29;
  System_String_array *v30;
  u64 v31;
  s64 v32;
  System_String_o *v34;
  u64 *v35;
  System_String_array *v37;
  u64 *v38;
  il2cpp_array_size_t max_length;
  s64 v40;
  s64 v42;
  u64 *v44;
  System_String_o *v45;
  System_Object_array *v47;
  s32 Count;
  f32 result;

  result = 0.0;
  this->hUnit = 0;
  PropertySheet___Clear(this->TimeLine);
  this->KutiSwitch = 0;
  this->MsgTime = 0.0;
  v8 = &"event";
  this->KutiName = 0;
  if (!evt)
    v8 = &"fld/f";
  v9 = *v8;
  v10 = NewSpecific(string, 6u);
  v10->m_Items[0] = "dds3data/";
  v10->m_Items[1] = v9;
  v10->m_Items[2] = "/";
  v10->m_Items[3] = key;
  v10->m_Items[4] = "/";
  v10->m_Items[5] = path;
  v17 = Concat_5271600(v10);
  v18 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v18);
  asset_bc = get_asset_bc();
  FileObject = LoadFileObject(asset_bc, key, v17);
  if (FileObject)
  {
    if (FileObject->klass->_2.typeHierarchyDepth >= typeHierarchyDepth)
    {
      if (FileObject->klass->_2.typeHierarchy[typeHierarchyDepth - 1] != UnityEngine_TextAsset)
        FileObject = 0;
    }
    else
    {
      FileObject = 0;
    }
    bytes = get_bytes(FileObject);
    Unicode = get_Unicode();
    v25 = (Unicode->klass[1]._1.byval_arg.data)(Unicode, bytes, *&Unicode->klass[1]._1.byval_arg.bits);
    v26 = NewSpecific(string, 1u);
    v26->m_Items[0] = "\r\n";
    v28 = Split_5246672(v25, v26, 0);
    v29 = v28->max_length - 1;
    if (v29 >= 1)
    {
      v30 = v28;
      v31 = 0;
      v32 = v29;
      while (1)
      {
        v34 = v30->m_Items[v31];
        v35 = NewSpecific(char, 1u);
        *(v35 + 16) = 44;
        v37 = Split(v34, v35);
        v38 = Allocate(System_Collections_Generic_List_float_);
        __ctor(v38);
        _Add(v38, 0.0);
        max_length = v37->max_length;
        if (max_length >= 3)
        {
          v40 = 6;
          do
          {
            result = 0.0;
            if (TryParse(*(&v37->obj.klass + v40), &result, 0))
              _Add(v38, result);
            LODWORD(max_length) = v37->max_length;
            v42 = v40 - 3;
            ++v40;
          }
          while (v42 < max_length);
        }
        PropertySheet___Add(this->TimeLine, v37->m_Items[0], v38);
        if (++v31 == v32)
          break;
      }
    }
    Count = HashSet_Text____get_Count(this->TimeLine);
    v44 = sub_8D3950(s32, &Count);
    v45 = Concat("Init Finished : ", v44);
    v47 = Empty_string_();
    Log(v45, v47, 0);
  }
}

// 0x10ead30
bool IsExists(evtKutiManager *this) {
  return HashSet_Text____get_Count(this->TimeLine) != 0;
}

// 0x10eae40
void IsSpeaking(evtKutiManager *this, evtUnitHandle_t *h, f32 time) {
  s32 KutiGroup;
  struct evtUnitHandle_t_o *KutiModel;
  struct dds3Basic_t_o *Owner;
  UnityEngine_GameObject_o *gameObject;
  UnityEngine_Component_o *Animator;
  struct System_Byte_array *ExFlags;
  Il2CppObject *Item;
  s32 v20;
  f32 MsgTime;
  s32 v22;
  f32 v23;
  bool *p_KutiSwitch;
  s32 v25;
  bool v26;
  u64 *v27;
  System_String_o *v28;
  System_Object_array *v30;
  struct System_Int16_array *ExNowMotion;
  struct System_Int16_array *ExBefore;
  s32 v35;
  struct System_Int16_array *ExSmooth;
  s32 v38;
  s32 v40;
  System_Object_array *v41;
  s64 *v44;
  s64 *v45;
  s64 *v50;
  s64 *v51;
  System_String_o *v54;
  System_Object_array *v56;
  s32 v58;
  f32 v59;
  evtUnitHandle_t_o *ha;

  ha = h;
  if (h)
  {
    if (HashSet_Text____get_Count(this->TimeLine))
    {
      KutiGroup = h->KutiGroup;
      if (!IsNullOrEmpty(this->KutiName))
      {
        if (KutiModel)
        {
          if (((h->klass->vtable._0_Equals.methodPtr)(h, KutiModel, h->klass->vtable._0_Equals.method) & 1) != 0)
          {
            Owner = h->Owner;
            if (Owner)
            {
              gameObject = Owner->gameObject;
              {
              }
              if (!op_Equality(gameObject, 0, 0))
              {
                Animator = GetAnimator(gameObject);
                {
                }
                if (!op_Equality(Animator, 0, 0))
                {
                  GetComponent_GUILayer_(Animator);
                  ExFlags = h->ExFlags;
                  if ((ExFlags->m_Items[KutiGroup] & 0x24) != 0)
                  {
                    mdlMotionStopKutiForUnity(&ha, KutiGroup, 0);
                    return;
                  }
                  Item = object___get_Item(this->TimeLine, this->KutiName);
                  this->MsgTime = get_realtimeSinceStartup() - this->UpTime;
                  if (_get_Count(Item) < 2)
                  {
                    p_KutiSwitch = &this->KutiSwitch;
                    if (this->KutiSwitch)
                    {
                      v20 = 0;
                      v26 = 0;
                      goto LABEL_59;
                    }
                    v25 = 0;
                    v26 = 0;
                    v20 = 0;
                  }
                  else
                  {
                    v20 = 0;
                    do
                    {
                      MsgTime = this->MsgTime;
                      if (MsgTime >= _get_Item(
                                        Item,
                                        v20))
                      {
                        v23 = this->MsgTime;
                        v22 = v20 + 1;
                        if (v23 <= _get_Item(
                                      Item,
                                      v20 + 1))
                          break;
                      }
                      else
                      {
                        v22 = v20 + 1;
                      }
                      v20 = v22;
                    }
                    while (v22 < _get_Count(Item)
                                - 1);
                    p_KutiSwitch = &this->KutiSwitch;
                    v25 = v20 & 1;
                    v26 = v20 & 1;
                    if (v25 != this->KutiSwitch)
                      goto LABEL_45;
                  }
                  if (v20 != _get_Count(Item))
                    return;
LABEL_45:
                  if (v25)
                  {
                    v59 = this->MsgTime;
                    v27 = sub_8D3950(f32, &v59);
                    v28 = Concat("@@@@@ SPEAK ON ", v27);
                    v30 = Empty_string_();
                    Log(v28, v30, 0);
                    ExNowMotion = ha->ExNowMotion;
                    ExBefore = ha->ExBefore;
                    v35 = ExNowMotion->m_Items[KutiGroup];
                    ExSmooth = ha->ExSmooth;
                    v38 = ExBefore->m_Items[KutiGroup];
                    v40 = ExSmooth->m_Items[KutiGroup];
                    mdlSmoothLoopMotionForUnity(&ha, KutiGroup, v35, v38, v40, 0, 0);
LABEL_88:
                    *p_KutiSwitch = v26;
                    return;
                  }
LABEL_59:
                  v41 = NewSpecific(object, 4u);
                  if ("SPEAK OFF @@@@@ "
                    && !QueryInterface("SPEAK OFF @@@@@ ", v41->obj.klass->_1.element_class))
                  {
                  }
                  v41->m_Items[0] = "SPEAK OFF @@@@@ ";
                  v59 = this->MsgTime;
                  v44 = sub_8D3950(f32, &v59);
                  v45 = v44;
                  v41->m_Items[1] = v45;
                  if (" : "
                    && !QueryInterface(" : ", v41->obj.klass->_1.element_class))
                  {
                  }
                  v41->m_Items[2] = " : ";
                  v58 = v20;
                  v50 = sub_8D3950(s32, &v58);
                  v51 = v50;
                  v41->m_Items[3] = v51;
                  v54 = Concat_5270224(v41);
                  v56 = Empty_string_();
                  Log(v54, v56, 0);
                  if (v20 == _get_Count(Item))
                  {
                    StopKuti(this);
                  }
                  else
                  {
                    mdlMotionStopKutiForUnity(&ha, KutiGroup, 0);
                  }
                  goto LABEL_88;
                }
              }
            }
          }
        }
      }
    }
  }
}

// 0x10ead90
void OnDestroy(evtKutiManager *this) {
  PropertySheet___Clear(this->TimeLine);
  this->KutiSwitch = 0;
  this->MsgTime = 0.0;
  this->hUnit = 0;
  this->KutiName = 0;
}

// 0x10eb4e0
void SetKutiName(evtKutiManager *this, char *name) {
  this->KutiName = 0;
  if (Animator___ContainsKey(this->TimeLine, name))
  {
    this->KutiName = name;
    this->KutiSwitch = 0;
    this->MsgTime = 0.0;
    this->UpTime = get_realtimeSinceStartup();
  }
}

// 0x10eb720
void SetUnit(evtKutiManager *this, evtUnitHandle_t *h) {
  this->hUnit = h;
}

// 0x10eb600
void StopKuti(evtKutiManager *this) {
  System_Object_array *v4;
  struct evtUnitHandle_t_o *v6;
  evtUnitHandle_t_o **p_hUnit;
  struct evtUnitHandle_t_o *hUnit;
  struct System_Byte_array *ExFlags;
  u32 KutiGroup;
  s32 v12;

  v4 = Empty_string_();
  Log("@@@@@ Stop Kuti @@@@@", v4, 0);
  hUnit = this->hUnit;
  p_hUnit = &this->hUnit;
  v6 = hUnit;
  p_hUnit[2] = 0;
  *(p_hUnit + 7) = 0;
  *(p_hUnit + 24) = 0;
  if (hUnit)
  {
    ExFlags = v6->ExFlags;
    KutiGroup = v6->KutiGroup;
    if ((ExFlags->m_Items[KutiGroup] & 0x20) == 0)
    {
      v12 = (*p_hUnit)->KutiGroup;
      mdlMotionStopKutiForUnity(p_hUnit, v12, 0);
    }
  }
  *p_hUnit = 0;
}
