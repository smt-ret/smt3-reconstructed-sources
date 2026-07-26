#include "types.h"

typedef struct fldRunSuspendData fldRunSuspendData;
typedef struct fldTest_FLDRUN_DANTE_t fldTest_FLDRUN_DANTE_t;
typedef struct fldTest_FLDRUN_PLAYER_t fldTest_FLDRUN_PLAYER_t;

struct fldRunSuspendData {
    u8 bgm_mode;
    u8 motion;
    u8 old_status;
    u8 stance;
    u8 status;
    u8 tikamiti;
    s16 backup_ix;
    s16 backup_iz;
    s16 door_ix;
    s16 door_iz;
    s16 goal_ix;
    s16 goal_iz;
    s16 ix;
    s16 iz;
    s16 player_ix;
    s16 player_iz;
    s16 wkmode;
    s32 cnt_ex;
    s32 goal;
    s32 nextframe;
    s32 now;
    s32 routeidx;
    s32 routedatatop;
    s32 update_flag;
    f32 d_p_len;
    f32 d_c_dir;
    f32 d_p_dir;
    f32 dir;
    f32 door_dir;
    f32 nowframe;
    f32 oldframe;
    f32 speed;
    f32 x;
    f32 y;
    f32 z;
    f32 r;
    u8 doorname[12];
    bool IsRestored;
    void *array;
    s32 kagpuz_pos;
    s32 kagpuz_now;
    s32 oldAreaID;
};

void Restore(fldRunSuspendData *this, fldTest_FLDRUN_DANTE_t **d, fldTest_FLDRUN_PLAYER_t **p);

// 0x16026a0
void BackupFldRunWork(void) {
  fldTest_c *v2;
  struct fldTest_StaticFields *static_fields;
  struct fldRunSuspendData_o *SuspendData;
  struct fldTest_FLDRUN_DANTE_t_o *fldRun_Dante;
  struct fldTest_FLDRUN_PLAYER_t_o *fldRun_Player;
  struct fldTest_FLDRUN_DOOR_t_o *pDoor;

  static_fields = v2->static_fields;
  SuspendData = static_fields->SuspendData;
  fldRun_Dante = static_fields->fldRun_Dante;
  fldRun_Player = static_fields->fldRun_Player;
  SuspendData->bgm_mode = fldRun_Dante->bgm_mode;
  SuspendData->motion = fldRun_Dante->motion;
  SuspendData->old_status = fldRun_Dante->old_status;
  SuspendData->stance = fldRun_Dante->stance;
  SuspendData->status = fldRun_Dante->status;
  SuspendData->tikamiti = fldRun_Dante->tikamiti;
  SuspendData->backup_ix = fldRun_Dante->backup_ix;
  SuspendData->backup_iz = fldRun_Dante->backup_iz;
  pDoor = fldRun_Dante->pDoor;
  if (pDoor)
  {
    SuspendData->door_ix = pDoor->ix;
    SuspendData->door_iz = fldRun_Dante->pDoor->iz;
    SuspendData->door_dir = fldRun_Dante->pDoor->dir;
  }
  SuspendData->goal_ix = fldRun_Dante->goal_ix;
  SuspendData->goal_iz = fldRun_Dante->goal_iz;
  SuspendData->ix = fldRun_Dante->ix;
  SuspendData->iz = fldRun_Dante->iz;
  SuspendData->player_ix = fldRun_Player->ix;
  SuspendData->player_iz = fldRun_Player->iz;
  SuspendData->routeidx = fldRun_Dante->RouteIdx;
  SuspendData->routedatatop = fldRun_Dante->RouteDataTop;
  SuspendData->wkmode = fldRun_Dante->wkmode;
  SuspendData->cnt_ex = fldRun_Dante->cnt_ex;
  SuspendData->goal = fldRun_Dante->goal;
  SuspendData->nextframe = fldRun_Dante->nextframe;
  SuspendData->now = fldRun_Dante->now;
  SuspendData->update_flag = fldRun_Dante->update_flag;
  SuspendData->d_p_len = fldRun_Dante->d_p_len;
  SuspendData->d_c_dir = fldRun_Dante->d_c_dir;
  SuspendData->d_p_dir = fldRun_Dante->d_p_dir;
  SuspendData->dir = fldRun_Dante->dir;
  SuspendData->speed = fldRun_Dante->speed;
  SuspendData->x = fldRun_Dante->x;
  SuspendData->y = fldRun_Dante->y;
  SuspendData->z = fldRun_Dante->z;
  SuspendData->r = fldRun_Dante->r;
  SuspendData->kagpuz_pos = KagPuzPos;
  SuspendData->kagpuz_now = KagPuzNow;
  SuspendData->oldAreaID = fldGb->areaOldID;
}

// 0x16024e0
void Copy(fldRunSuspendData *this, fldRunSuspendData **ret) {
  this->bgm_mode = (*ret)->bgm_mode;
  this->motion = (*ret)->motion;
  this->old_status = (*ret)->old_status;
  this->stance = (*ret)->stance;
  this->status = (*ret)->status;
  this->tikamiti = (*ret)->tikamiti;
  this->backup_ix = (*ret)->backup_ix;
  this->backup_iz = (*ret)->backup_iz;
  this->door_ix = (*ret)->door_ix;
  this->door_iz = (*ret)->door_iz;
  this->door_dir = (*ret)->door_dir;
  this->goal_ix = (*ret)->goal_ix;
  this->goal_iz = (*ret)->goal_iz;
  this->ix = (*ret)->ix;
  this->iz = (*ret)->iz;
  this->player_ix = (*ret)->ix;
  this->player_iz = (*ret)->iz;
  this->routeidx = (*ret)->routeidx;
  this->routedatatop = (*ret)->routedatatop;
  this->wkmode = (*ret)->wkmode;
  this->cnt_ex = (*ret)->cnt_ex;
  this->goal = (*ret)->goal;
  this->nextframe = (*ret)->nextframe;
  this->now = (*ret)->now;
  this->update_flag = (*ret)->update_flag;
  this->d_p_len = (*ret)->d_p_len;
  this->d_c_dir = (*ret)->d_c_dir;
  this->d_p_dir = (*ret)->d_p_dir;
  this->dir = (*ret)->dir;
  this->speed = (*ret)->speed;
  this->x = (*ret)->x;
  this->y = (*ret)->y;
  this->z = (*ret)->z;
  this->r = (*ret)->r;
  this->kagpuz_pos = (*ret)->kagpuz_pos;
  this->kagpuz_now = (*ret)->kagpuz_now;
  this->oldAreaID = (*ret)->oldAreaID;
}

// 0x1602290
s32 GetStanceID(fldRunSuspendData *this) {
  return this->stance;
}

// 0x16022a0
void Restore(fldRunSuspendData *this, fldTest_FLDRUN_DANTE_t **d, fldTest_FLDRUN_PLAYER_t **p) {
  fldTest_FLDRUN_DANTE_t_o *v7;
  struct fldTest_FLDRUN_DOOR_t_o *pDoor;

  if (this->IsRestored)
  {
    (*d)->bgm_mode = this->bgm_mode;
    (*d)->motion = this->motion;
    (*d)->old_status = this->old_status;
    (*d)->stance = this->stance;
    (*d)->status = this->status;
    (*d)->tikamiti = this->tikamiti;
    (*d)->backup_ix = this->backup_ix;
    (*d)->backup_iz = this->backup_iz;
    v7 = *d;
    pDoor = (*d)->pDoor;
    if (pDoor)
    {
      pDoor->ix = this->door_ix;
      (*d)->pDoor->iz = this->door_iz;
      (*d)->pDoor->dir = this->door_dir;
      v7 = *d;
    }
    v7->goal_ix = this->goal_ix;
    (*d)->goal_iz = this->goal_iz;
    (*d)->ix = this->ix;
    (*d)->iz = this->iz;
    (*p)->ix = this->player_ix;
    (*p)->iz = this->player_iz;
    (*d)->wkmode = this->wkmode;
    (*d)->cnt_ex = this->cnt_ex;
    (*d)->goal = this->goal;
    (*d)->nextframe = this->nextframe;
    (*d)->now = this->now;
    (*d)->RouteIdx = this->routeidx;
    (*d)->RouteDataTop = this->routedatatop;
    (*d)->update_flag = this->update_flag;
    (*d)->d_p_len = this->d_p_len;
    (*d)->d_c_dir = this->d_c_dir;
    (*d)->d_p_dir = this->d_p_dir;
    (*d)->dir = this->dir;
    (*d)->speed = this->speed;
    (*d)->x = this->x;
    (*d)->y = this->y;
    (*d)->z = this->z;
    (*d)->r = this->r;
    fldGb->areaOldID = this->oldAreaID;
    this->IsRestored = 0;
  }
}

// 0x16028a0
void RestoreFldRunWork(u8 **data) {
    Restore(0, 0, 0);
}

// 0x1601da0
u8 **ToArray(fldRunSuspendData *this) {
  System_Collections_Generic_List_byte__o *array;
  s16 backup_ix;
  System_Collections_Generic_IEnumerable_T__o *Bytes;
  System_Collections_Generic_List_byte__o *v7;
  System_Collections_Generic_IEnumerable_T__o *v8;
  System_Collections_Generic_List_byte__o *v9;
  System_Collections_Generic_IEnumerable_T__o *v10;
  System_Collections_Generic_List_byte__o *v11;
  System_Collections_Generic_IEnumerable_T__o *v12;
  System_Collections_Generic_List_byte__o *v13;
  System_Collections_Generic_IEnumerable_T__o *v14;
  System_Collections_Generic_List_byte__o *v15;
  System_Collections_Generic_IEnumerable_T__o *v16;
  System_Collections_Generic_List_byte__o *v17;
  System_Collections_Generic_IEnumerable_T__o *v18;
  System_Collections_Generic_List_byte__o *v19;
  System_Collections_Generic_IEnumerable_T__o *v20;
  System_Collections_Generic_List_byte__o *v21;
  System_Collections_Generic_IEnumerable_T__o *v22;
  System_Collections_Generic_List_byte__o *v23;
  System_Collections_Generic_IEnumerable_T__o *v24;
  System_Collections_Generic_List_byte__o *v25;
  System_Collections_Generic_IEnumerable_T__o *v26;
  System_Collections_Generic_List_byte__o *v27;
  System_Collections_Generic_IEnumerable_T__o *Bytes_3927552;
  System_Collections_Generic_List_byte__o *v29;
  System_Collections_Generic_IEnumerable_T__o *v30;
  System_Collections_Generic_List_byte__o *v31;
  System_Collections_Generic_IEnumerable_T__o *v32;
  System_Collections_Generic_List_byte__o *v33;
  System_Collections_Generic_IEnumerable_T__o *v34;
  System_Collections_Generic_List_byte__o *v35;
  System_Collections_Generic_IEnumerable_T__o *v36;
  System_Collections_Generic_List_byte__o *v37;
  System_Collections_Generic_IEnumerable_T__o *v38;
  System_Collections_Generic_List_byte__o *v39;
  System_Collections_Generic_IEnumerable_T__o *v40;
  System_Collections_Generic_List_byte__o *v41;
  System_Collections_Generic_IEnumerable_T__o *Bytes_3927920;
  System_Collections_Generic_List_byte__o *v43;
  System_Collections_Generic_IEnumerable_T__o *v44;
  System_Collections_Generic_List_byte__o *v45;
  System_Collections_Generic_IEnumerable_T__o *v46;
  System_Collections_Generic_List_byte__o *v47;
  System_Collections_Generic_IEnumerable_T__o *v48;
  System_Collections_Generic_List_byte__o *v49;
  System_Collections_Generic_IEnumerable_T__o *v50;
  System_Collections_Generic_List_byte__o *v51;
  System_Collections_Generic_IEnumerable_T__o *v52;
  System_Collections_Generic_List_byte__o *v53;
  System_Collections_Generic_IEnumerable_T__o *v54;
  System_Collections_Generic_List_byte__o *v55;
  System_Collections_Generic_IEnumerable_T__o *v56;
  System_Collections_Generic_List_byte__o *v57;
  System_Collections_Generic_IEnumerable_T__o *v58;
  System_Collections_Generic_List_byte__o *v59;
  System_Collections_Generic_IEnumerable_T__o *v60;
  System_Collections_Generic_List_byte__o *v61;
  System_Collections_Generic_IEnumerable_T__o *v62;
  System_Collections_Generic_List_byte__o *v63;
  System_Collections_Generic_IEnumerable_T__o *v64;

  _Clear(this->array);
  _Add(this->array, this->bgm_mode);
  _Add(this->array, this->motion);
  _Add(this->array, this->old_status);
  _Add(this->array, this->stance);
  _Add(this->array, this->status);
  _Add(this->array, this->tikamiti);
  array = this->array;
  backup_ix = this->backup_ix;
  Bytes = GetBytes(backup_ix, 0);
  _AddRange(array, Bytes);
  v7 = this->array;
  v8 = GetBytes(this->backup_iz, 0);
  _AddRange(v7, v8);
  v9 = this->array;
  v10 = GetBytes(this->door_ix, 0);
  _AddRange(v9, v10);
  v11 = this->array;
  v12 = GetBytes(this->door_iz, 0);
  _AddRange(v11, v12);
  v13 = this->array;
  v14 = GetBytes(this->goal_ix, 0);
  _AddRange(v13, v14);
  v15 = this->array;
  v16 = GetBytes(this->goal_iz, 0);
  _AddRange(v15, v16);
  v17 = this->array;
  v18 = GetBytes(this->ix, 0);
  _AddRange(v17, v18);
  v19 = this->array;
  v20 = GetBytes(this->iz, 0);
  _AddRange(v19, v20);
  v21 = this->array;
  v22 = GetBytes(this->player_ix, 0);
  _AddRange(v21, v22);
  v23 = this->array;
  v24 = GetBytes(this->player_iz, 0);
  _AddRange(v23, v24);
  v25 = this->array;
  v26 = GetBytes(this->wkmode, 0);
  _AddRange(v25, v26);
  v27 = this->array;
  Bytes_3927552 = GetBytes_3927552(this->cnt_ex);
  _AddRange(v27, Bytes_3927552);
  v29 = this->array;
  v30 = GetBytes_3927552(this->goal);
  _AddRange(v29, v30);
  v31 = this->array;
  v32 = GetBytes_3927552(this->nextframe);
  _AddRange(v31, v32);
  v33 = this->array;
  v34 = GetBytes_3927552(this->now);
  _AddRange(v33, v34);
  v35 = this->array;
  v36 = GetBytes_3927552(this->routeidx);
  _AddRange(v35, v36);
  v37 = this->array;
  v38 = GetBytes_3927552(this->routedatatop);
  _AddRange(v37, v38);
  v39 = this->array;
  v40 = GetBytes_3927552(this->update_flag);
  _AddRange(v39, v40);
  v41 = this->array;
  Bytes_3927920 = GetBytes_3927920(this->d_p_len);
  _AddRange(v41, Bytes_3927920);
  v43 = this->array;
  v44 = GetBytes_3927920(this->d_c_dir);
  _AddRange(v43, v44);
  v45 = this->array;
  v46 = GetBytes_3927920(this->d_p_dir);
  _AddRange(v45, v46);
  v47 = this->array;
  v48 = GetBytes_3927920(this->dir);
  _AddRange(v47, v48);
  v49 = this->array;
  v50 = GetBytes_3927920(this->door_dir);
  _AddRange(v49, v50);
  v51 = this->array;
  v52 = GetBytes_3927920(this->nowframe);
  _AddRange(v51, v52);
  v53 = this->array;
  v54 = GetBytes_3927920(this->oldframe);
  _AddRange(v53, v54);
  v55 = this->array;
  v56 = GetBytes_3927920(this->speed);
  _AddRange(v55, v56);
  v57 = this->array;
  v58 = GetBytes_3927920(this->x);
  _AddRange(v57, v58);
  v59 = this->array;
  v60 = GetBytes_3927920(this->y);
  _AddRange(v59, v60);
  v61 = this->array;
  v62 = GetBytes_3927920(this->z);
  _AddRange(v61, v62);
  v63 = this->array;
  v64 = GetBytes_3927920(this->r);
  _AddRange(v63, v64);
  _Add(this->array, this->kagpuz_pos);
  _Add(this->array, this->kagpuz_now);
  _Add(this->array, this->oldAreaID);
  return _ToArray(this->array);
}
