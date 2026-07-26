#include "types.h"

typedef struct effPCPDANTE_ShowTime_Param_t effPCPDANTE_ShowTime_Param_t;
typedef struct effPCPDANTE_ShowTime_tag effPCPDANTE_ShowTime_tag;
typedef struct nbPanelFlashData_t nbPanelFlashData_t;
typedef struct sdfTexHandle_t sdfTexHandle_t;

struct effPCPDANTE_ShowTime_tag {
    sdfVector4_t pos;
    effPCPDANTE_ShowTime_Param_t *param;
    nbPanelFlashData_t *flash[3];
    sdfTexHandle_t *hTex[2];
    s32 frame;
    s32 frameParts[3];
    u8 original;
};

// 0x11f0e20
void Clear(effPCPDANTE_ShowTime_tag *this) {
  struct nbPanelFlashData_t_array *v3;
  struct nbPanelFlashData_t_array *v4;
  u64 *v5;
  struct nbPanelFlashData_t_array *flash;
  u64 *v8;
  struct nbPanelFlashData_t_array *v10;
  u64 *v11;
  struct sdfTexHandle_t_array *v13;
  struct sdfTexHandle_t_array *v14;
  u64 *v15;
  struct sdfTexHandle_t_array *hTex;
  u64 *v18;

  *&this->pos.z = 0;
  this->param = 0;
  *&this->pos.x = 0;
  v3 = NewSpecific(nbPanelFlashData_t, 3u);
  this->flash = v3;
  v4 = v3;
  v5 = Allocate(nbPanelFlashData_t);
  nbPanelFlashData_t___ctor(v5);
  v4->m_Items[0] = v5;
  flash = this->flash;
  v8 = Allocate(nbPanelFlashData_t);
  nbPanelFlashData_t___ctor(v8);
  flash->m_Items[1] = v8;
  v10 = this->flash;
  v11 = Allocate(nbPanelFlashData_t);
  nbPanelFlashData_t___ctor(v11);
  v10->m_Items[2] = v11;
  v13 = NewSpecific(sdfTexHandle_t, 2u);
  this->hTex = v13;
  v14 = v13;
  v15 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v15);
  v14->m_Items[0] = v15;
  hTex = this->hTex;
  v18 = Allocate(sdfTexHandle_t);
  sdfTexHandle_t___ctor(v18);
  hTex->m_Items[1] = v18;
  this->frame = 0;
  this->frameParts = NewSpecific(s32, 3u);
  this->original = 0;
}
