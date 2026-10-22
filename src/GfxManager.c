#include "types.h"

typedef struct GfxManager GfxManager;
typedef struct GfxManager_DrawCmd GfxManager_DrawCmd;
typedef struct SAVEDATA SAVEDATA;
typedef struct _FRQ _FRQ;
typedef struct sdfGrPacketHeader_t sdfGrPacketHeader_t;

struct GfxManager_DrawCmd {
    char *hashname;
    u64 type;
    u32 time;
    void *obj;
};

void Draw(s32 x, s32 y, _FRQ *frq, s32 colno);
void init_fadeinout(GfxManager *this, GfxManager_DrawCmd *cmd, void *param);
void initialize(SAVEDATA *this);
void update_drawsprite(GfxManager *this, GfxManager_DrawCmd *cmd, void *param);
void update_fadeinout(GfxManager *this, GfxManager_DrawCmd *cmd, void *param);

// 0x1142000
void Awake(GfxManager *this) {
  u64 *v3;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v5;
  Il2CppObject *v7;
  s32 screen_wid;
  s32 screen_hei;
  s32 v14;
  s32 v15;
  UnityEngine_Vector2_o v17;
  UnityEngine_Vector2_o v18;
  UnityEngine_Vector3_o one;
  UnityEngine_Vector3_o v20;

  v3 = Allocate(UnityEngine_GameObject);
  _ctor_27226688(v3);
  this->tree_obj = v3;
  set_name(v3, "Gfx");
  transform = get_transform(this->tree_obj, 0);
  v5 = get_transform(this, 0);
  SetParent(transform, v5);
  v7 = AddComponent_object_(this->tree_obj);
  one = get_one();
  set_localScale(v7, one);
  v18 = 0;
  sub_851710(&v18, screen_wid, screen_hei);
  set_sizeDelta(v7, v18);
  v14 = screen_wid;
  v15 = screen_hei;
  v17 = 0;
  sub_851710(&v17, -v14 * 0.5, v15 * 0.5);
  v20 = op_Implicit_8725680(v17);
  set_localPosition(v7, v20);
  GfxManager_DrawCmd___Clear(this->draw_command);
  this->time = 0;
}

// 0x11428b0
void Draw(GfxManager *this, char *hash, u64 type, void *param) {
  GfxManager_DrawCmd_o v11;
  GfxManager_DrawCmd_o v12;
  GfxManager_DrawCmd_o v13;
  s64 v14;
  struct UnityEngine_GameObject_o *obj;

  v14 = 0;
  obj = 0;
  if (!GfxManager_DrawCmd___ContainsKey(this->draw_command, hash))
    initialize(this, hash, type, param);
  GfxManager_DrawCmd___get_Item(&v13, this->draw_command, hash);
  v14 = *&v13.time;
  obj = v13.obj;
  if (v13.type == 0x4000000)
  {
    v11.hashname = v13.hashname;
    v11.type = 0x4000000;
    *&v11.time = v14;
    v11.obj = obj;
    update_drawsprite(this, &v11, param);
  }
  else if (v13.type == 1)
  {
    v12.hashname = v13.hashname;
    v12.type = 1;
    *&v12.time = v14;
    v12.obj = obj;
    update_fadeinout(this, &v12, param);
  }
}

// 0x11421f0
void LateUpdate(GfxManager *this) {
  u64 *v3;
  UnityEngine_Object_o *v5;
  mdlEffectResrcItem_t_o *v6;
  s32 v7;
  System_Collections_Generic_Dictionary_string__GfxManager_DrawCmd__o *draw_command;
  System_String_o *Item;
  u64 v10[2];
  s32 v11;
  UnityEngine_Object_o *obj;
  u64 v13[5];
  s64 v14;
  s64 v15;
  s64 v16;
  s64 v17;
  s64 v18;
  System_Collections_Generic_Dictionary_Enumerator_TKey__TValue__o v19;
  s64 v20;
  s64 v21;
  s64 v22;

  v21 = 0;
  v22 = 0;
  v14 = 0;
  v20 = 0;
  memset(&v19, 0, sizeof(v19));
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  ++this->time;
  v3 = Allocate(System_Collections_Generic_List_string_);
  __ctor(v3);
  GfxManager_DrawCmd___GetEnumerator(&v19, this->draw_command);
  while ((sub_435020(&v19)
         & 1) != 0)
  {
    sub_435270(&v19, v13);
    v16 = v13[2];
    v14 = v13[0];
    v15 = v13[1];
    v17 = v13[3];
    v18 = v13[4];
    sub_1A0BEB0(&v14, v10);
    if (v10[1] != 1 && v11 != this->time)
    {
      v5 = obj;
      v6 = v10[0];
      Destroy_27360000(v5);
      _Add(v3, v6);
    }
  }
  nullsub_28(&v19);
  if (_get_Count(v3) >= 1)
  {
    v7 = 0;
    do
    {
      draw_command = this->draw_command;
      Item = _get_Item(
               v3,
               v7);
      GfxManager_DrawCmd___Remove(draw_command, Item);
      ++v7;
    }
    while (v7 < _get_Count(v3));
  }
}

// 0x11421e0
void Update(GfxManager *this) {
  ;
}

// 0x1143180
void draw_sprite(GfxManager *this, sdfGrPacketHeader_t *pkt, void *obj) {
  Il2CppObject *Component_object;

  Component_object = GetComponent_object_(obj);
  Draw(Component_object, pkt);
}

// 0x1143110
void draw_trianglefan(GfxManager *this, sdfGrPacketHeader_t *pkt, void *obj) {
  Il2CppObject *Component_object;

  Component_object = GetComponent_object_(obj);
  Draw(Component_object, pkt);
}

// 0x11427f0
void init_drawsprite(GfxManager *this, GfxManager_DrawCmd *cmd, void *param) {
  UnityEngine_GameObject_o *obj;
  struct System_String_o *hashname;
  u64 type;
  struct UnityEngine_GameObject_o *v10;
  GfxManager_DrawCmd_o v12;

  obj = cmd->obj;
  AddComponent_object_(obj);
  AddComponent_object_(obj);
  AddComponent_object_(obj);
  hashname = cmd->hashname;
  type = cmd->type;
  v10 = cmd->obj;
  *&v12.time = *&cmd->time;
  v12.obj = v10;
  v12.hashname = hashname;
  v12.type = type;
  update_drawsprite(this, &v12, param);
}

// 0x1142710
void init_fadeinout(GfxManager *this, GfxManager_DrawCmd *cmd, void *param) {
  UnityEngine_GameObject_o *obj;
  Il2CppObject *v8;
  struct System_String_o *hashname;
  u64 type;
  struct UnityEngine_GameObject_o *v11;
  GfxManager_DrawCmd_o v13;

  obj = cmd->obj;
  AddComponent_object_(obj);
  v8 = AddComponent_object_(obj);
  set_overrideSorting(v8, 1);
  set_sortingOrder(v8, 100);
  hashname = cmd->hashname;
  type = cmd->type;
  v11 = cmd->obj;
  *&v13.time = *&cmd->time;
  v13.obj = v11;
  v13.hashname = hashname;
  v13.type = type;
  update_fadeinout(this, &v13, param);
  AddComponent_object_(this->tree_obj);
}

// 0x1142480
void initialize(GfxManager *this, char *hash, u64 type, void *param) {
  u32 v9;
  u64 *v10;
  UnityEngine_Transform_o *transform;
  UnityEngine_Transform_o *v12;
  System_Collections_Generic_Dictionary_string__GfxManager_DrawCmd__o *draw_command;
  Il2CppObject *Component_object;
  GfxManager_DrawCmd_o v18;
  GfxManager_DrawCmd_o v19;
  UnityEngine_Vector2_o v20;
  UnityEngine_Vector3_o one;
  UnityEngine_Vector3_o zero;

  v9 = this->time - 1;
  v10 = Allocate(UnityEngine_GameObject);
  _ctor(v10, hash, 0);
  AddComponent_object_(v10);
  AddComponent_object_(v10);
  transform = get_transform(v10, 0);
  v12 = get_transform(this->tree_obj, 0);
  SetParent(transform, v12);
  draw_command = this->draw_command;
  v19.hashname = hash;
  v19.type = type;
  v19.time = v9;
  *(&v19.time + 1) = 0;
  v19.obj = v10;
  GfxManager_DrawCmd___Add(draw_command, hash, &v19);
  Component_object = GetComponent_object_(v10);
  v19.hashname = 0;
  sub_851710(&v19, 0.0, 1.0);
  set_anchorMin(Component_object, v19.hashname);
  v20 = 0;
  sub_851710(&v20, 0.0, 1.0);
  set_anchorMax(Component_object, v20);
  one = get_one();
  set_localScale(Component_object, one);
  zero = get_zero();
  set_localPosition(Component_object, zero);
  if (type == 0x4000000)
  {
    AddComponent_object_(v10);
    AddComponent_object_(v10);
    AddComponent_object_(v10);
    v19.hashname = hash;
    v19.type = 0x4000000;
    v19.time = v9;
    *(&v19.time + 1) = 0;
    v19.obj = v10;
    update_drawsprite(this, &v19, param);
  }
  else if (type == 1)
  {
    v18.hashname = hash;
    v18.type = 1;
    v18.time = v9;
    *(&v18.time + 1) = 0;
    v18.obj = v10;
    init_fadeinout(this, &v18, param);
  }
}

// 0x1142cf0
void update_drawsprite(GfxManager *this, GfxManager_DrawCmd *cmd, void *param) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  UnityEngine_GameObject_o *obj;
  Il2CppObject *Component_object;
  sdfGrPacketHeader_t_o *monitor;
  struct sdfGifTag_t_o *giftag;
  sdfGrPacketHeader_t_c *v15;
  s64 v16;
  char *name;
  s64 v18;
  s64 v19;
  char *v20;
  s64 *v21;
  Il2CppObject *v22;
  sdfGrPacketHeader_t_c *v24;
  s64 v25;
  char *v26;
  s64 *v27;
  struct System_String_o *hashname;
  u64 type;
  System_Collections_Generic_Dictionary_string__GfxManager_DrawCmd__o *draw_command;
  u64 v31;
  struct UnityEngine_GameObject_o *v32;
  char *v33;
  s64 *v34;
  GfxManager_o *v35;
  s64 v36;
  s32 v37;
  GfxManager_DrawCmd_o v38;

  v37 = 0;
  v36 = 0;
  v35 = this;
  if (param)
  {
    klass = param->klass;
    if (param->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != sdfDrawTag_t)
    {
      sub_8FC2C0(klass->_1.element_class, sdfDrawTag_t, &v38);
      if ((v38.hashname & 1) != 0)
        v9 = *&v38.time;
      else
        v9 = &v38.hashname + 1;
      v10 = sub_8C4940(v9);
    }
  }
  obj = cmd->obj;
  Component_object = GetComponent_object_(obj);
  do
  {
    monitor = param[1].monitor;
    if (monitor)
    {
      while (1)
      {
        giftag = monitor->giftag;
        if (monitor->primitive)
          break;
        if ((giftag->regs & 0xF) != 0xE)
          goto LABEL_32;
        v15 = monitor->klass;
        if (monitor->klass->_2.typeHierarchyDepth < v16 || v15->_2.typeHierarchy[v16 - 1] != sdf2DTexPacket_t)
        {
          sub_8FC2C0(v15->_1.element_class, sdf2DTexPacket_t, &v38);
          if ((v38.hashname & 1) != 0)
            v33 = *&v38.time;
          else
            v33 = &v38.hashname + 1;
          v34 = sub_8C4940(v33);
        }
        name = monitor[1].klass->_1.name;
        if (name)
        {
          v18 = *name;
          if (*(*name + 288LL) < v19 || *(*(v18 + 200) + 8 * v19 - 8) != sdfTexHandle_t)
          {
            sub_8FC2C0(*(v18 + 64), sdfTexHandle_t, &v38);
            if ((v38.hashname & 1) != 0)
              v20 = *&v38.time;
            else
              v20 = &v38.hashname + 1;
            v21 = sub_8C4940(v20);
          }
        }
        Component_object[1].monitor = name;
        monitor = monitor->dmatag->addr;
        if (!monitor)
          goto LABEL_39;
LABEL_33:
        v24 = monitor->klass;
        if (monitor->klass->_2.typeHierarchyDepth < v25
          || v24->_2.typeHierarchy[v25 - 1] != sdfGrPacketHeader_t)
        {
          sub_8FC2C0(v24->_1.element_class, sdfGrPacketHeader_t, &v38);
          if ((v38.hashname & 1) != 0)
            v26 = *&v38.time;
          else
            v26 = &v38.hashname + 1;
          v27 = sub_8C4940(v26);
        }
      }
      sub_17A6190(&v36, giftag->parm);
      LOBYTE(v38.type) = 0;
      v38.hashname = 0;
      sub_17A6CD0(&v38, HIWORD(v36));

      {
        if (LOBYTE(v38.hashname) != 6)
          goto LABEL_32;
      }
      v22 = GetComponent_object_(obj);
      Draw(v22, monitor);
LABEL_32:
      monitor = monitor->dmatag->addr;
      if (!monitor)
        goto LABEL_39;
      goto LABEL_33;
    }
LABEL_39:
    param = param[1].klass;
  }
  while (param);
  hashname = cmd->hashname;
  type = cmd->type;
  ++cmd->time;
  draw_command = v35->draw_command;
  v31 = type;
  v32 = cmd->obj;
  *&v38.time = *&cmd->time;
  v38.obj = v32;
  v38.hashname = hashname;
  v38.type = v31;
  GfxManager_DrawCmd___set_Item(draw_command, hashname, &v38);
}

// 0x11429d0
void update_fadeinout(GfxManager *this, GfxManager_DrawCmd *cmd, void *param) {
  Il2CppClass *klass;
  s64 typeHierarchyDepth;
  char *v9;
  s64 *v10;
  UnityEngine_GameObject_o *obj;
  s64 v12;
  Il2CppObject *Component_object;
  Il2CppObject *v15;
  struct System_String_o *hashname;
  System_Collections_Generic_Dictionary_string__GfxManager_DrawCmd__o *draw_command;
  u64 type;
  struct UnityEngine_GameObject_o *v19;
  UnityEngine_Vector2_o v20;
  UnityEngine_Vector3_o v21;
  UnityEngine_Vector3_o v22;
  s64 v23;
  s64 v24;
  s64 v25;
  s64 v26;
  s64 v27;
  s64 v28;
  GfxManager_DrawCmd_o v29;
  UnityEngine_Vector2_o v30;

  v27 = 0;
  v28 = 0;
  v26 = 0;
  v24 = 0;
  v25 = 0;
  if (param)
  {
    klass = param->klass;
    if (param->klass->_2.typeHierarchyDepth < typeHierarchyDepth
      || klass->_2.typeHierarchy[typeHierarchyDepth - 1] != dds3KernelDraw_FADEPKT_t)
    {
      sub_8FC2C0(klass->_1.element_class, dds3KernelDraw_FADEPKT_t, &v29);
      if ((v29.hashname & 1) != 0)
        v9 = *&v29.time;
      else
        v9 = &v29.hashname + 1;
      v10 = sub_8C4940(v9);
    }
  }
  obj = cmd->obj;
  sub_17A6E20(&v27, param[5].klass->_1.namespaze);
  sub_17A6E20(&v26, param[6].klass->_1.namespaze);
  sub_17A6D70(&v28, *(param[4].monitor + 3));
  v12 = *(param[5].monitor + 3);
  v23 = 0;
  sub_17A6D70(&v23, v12);
  Component_object = GetComponent_object_(obj);
  v22.z = 0.0;
  *&v22.x = 0;
  sub_8524C0(&v22.x, v27, WORD1(v27), 0.0);
  set_localPosition(Component_object, v22);
  v21.z = 0.0;
  *&v21.x = 0;
  sub_8526E0(&v21, (v26 - v27), (WORD1(v26) - WORD1(v27)));
  v30 = op_Implicit(v21, 0);
  set_sizeDelta(Component_object, v30);
  v20 = 0;
  sub_851710(&v20, 0.0, 1.0);
  set_pivot(Component_object, v20);
  v15 = GetComponent_object_(obj);
  sub_19EC630(&v24, v28 / 255.0, BYTE1(v28) / 255.0, BYTE2(v28) / 255.0, BYTE3(v28) * 0.0078125);
  (v15->klass->vtable[23].methodPtr)(v15, v15->klass->vtable[23].*&v24, *(&v24 + 1), *&v25, *(&v25 + 1));
  ++cmd->time;
  draw_command = this->draw_command;
  hashname = cmd->hashname;
  type = cmd->type;
  v19 = cmd->obj;
  *&v29.time = *&cmd->time;
  v29.obj = v19;
  v29.hashname = hashname;
  v29.type = type;
  GfxManager_DrawCmd___set_Item(draw_command, hashname, &v29);
}
