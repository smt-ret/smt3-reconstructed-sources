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
    update_drawsprite(0, 0, 0);
    init_fadeinout(0, 0, 0);
}

// 0x1142cf0
void update_drawsprite(GfxManager *this, GfxManager_DrawCmd *cmd, void *param) {
    Draw(0, 0, 0, 0);
}

// 0x11429d0
void update_fadeinout(GfxManager *this, GfxManager_DrawCmd *cmd, void *param) {
}
