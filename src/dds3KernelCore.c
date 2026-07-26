#include "types.h"

typedef struct dds3ProcessID_t dds3ProcessID_t;
typedef struct sdfRandCB_t sdfRandCB_t;

static dds3ProcessID_t *startinglistf;
static dds3ProcessID_t *startinglistl;
static s32 startinglistcnt;
static dds3ProcessID_t *endinglistf;
static dds3ProcessID_t *endinglistl;
static s32 endinglistcnt;
static dds3ProcessID_t *runninglistf;
static dds3ProcessID_t *runninglistl;
static s32 runninglistcnt;
static dds3ProcessID_t *runprocess;
static s8 trees[64];
static s32 randlogidx;
static char randlog[UNKNOWN_ARRAY_SIZE];

void AddProcessList(dds3ProcessID_t **setp);
void ChangeProcessFlag(s32 change, dds3ProcessID_t **target, u32 flag, s32 type);
void ChangeProcessFlagChild(s32 change, dds3ProcessID_t **parent, u32 flag);
void DeleteProcessList(dds3ProcessID_t **setp);
void EndProcess(dds3ProcessID_t **setp);
void KillProcess(dds3ProcessID_t **setp);
void PadEi(void);
s32 RunProcess(dds3ProcessID_t **pro);
void RunningProcess(void);
void SetRandHistory(char *name, char *val);
void StartingProcess(void);
void dds3EndingProcess(void);
s32 dds3ExistProcess(dds3ProcessID_t **id);
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer);
dds3ProcessID_t *dds3SearchProcessName(char *namestr);
u32 sdfGetRand(sdfRandCB_t **aCB);
f32 sdfGetRandFloat(sdfRandCB_t **aCB);
u32 sdfGetRandInt(sdfRandCB_t **aCB, u32 aLimit);

// 0x17b8420
void AddProcessList(dds3ProcessID_t **setp) {
  u32 v3;
  dds3KernelCore_c *v4;
  struct dds3ProcessID_t_o *endinglistf;
  dds3ProcessID_t_o *v6;
  s32 v7;
  struct dds3ProcessID_t_o **p_endinglistl;
  s32 v10;
  struct dds3ProcessID_t_o **p_runninglistl;
  struct dds3ProcessID_t_o *prev;
  s32 v13;
  struct dds3KernelCore_StaticFields *p_endinglistf;
  u32 v17;

  v3 = (*setp)->flag & 0xF;
  switch (v3)
  {
    case 3u:
      v6 = *setp;
      if (!endinglistf)
        break;
      while (endinglistf->priority <= v6->priority)
      {
        endinglistf = endinglistf->next;
        if (!endinglistf)
        {
          v7 = v6->flag & 0xF;
          switch (v7)
          {
            case 3:
              endinglistl->next = v6;
              (*setp)->prev = endinglistl;
              p_endinglistl = &endinglistl;
              break;
            case 2:
              runninglistl->next = v6;
              (*setp)->prev = runninglistl;
              p_endinglistl = &runninglistl;
              break;
            case 1:
              startinglistl->next = v6;
              (*setp)->prev = startinglistl;
              p_endinglistl = &startinglistl;
              break;
            default:
          }
          *p_endinglistl = *setp;
        }
      }
      prev = endinglistf->prev;
      if (prev)
      {
        prev->next = v6;
        (*setp)->prev = endinglistf->prev;
        (*setp)->next = endinglistf;
        endinglistf->prev = *setp;
      }
      v13 = v6->flag & 0xF;
      switch (v13)
      {
        case 3:
          p_endinglistf = &endinglistf;
          break;
        case 2:
          p_endinglistf = &runninglistf;
          break;
        case 1:
          p_endinglistf = v4->static_fields;
          break;
        default:
          (*setp)->prev = 0;
      }
      p_endinglistf->startinglistf = v6;
    case 2u:
      endinglistf = runninglistf;
      v6 = *setp;
      if (endinglistf)
      break;
    case 1u:
      endinglistf = startinglistf;
      v6 = *setp;
      if (endinglistf)
      break;
    default:
      return;
  }
  v10 = v6->flag & 0xF;
  switch (v10)
  {
    case 3:
      endinglistf = v6;
      p_runninglistl = &endinglistl;
      break;
    case 2:
      runninglistf = v6;
      p_runninglistl = &runninglistl;
      break;
    case 1:
      startinglistf = v6;
      p_runninglistl = &startinglistl;
      break;
    default:
  }
  *p_runninglistl = *setp;
  (*setp)->prev = 0;
  (*setp)->next = 0;
  v17 = (*setp)->flag & 0xF;
  switch (v17)
  {
    case 3u:
      ++endinglistcnt;
      break;
    case 2u:
      ++runninglistcnt;
      break;
    case 1u:
      ++startinglistcnt;
      break;
  }
}

// 0x17b9ef0
void ChangeProcessFlag(s32 change, dds3ProcessID_t **target, u32 flag, s32 type) {
  u32 v10;
  dds3ProcessID_t_o *startinglistf;
  s32 v12;
  u32 v13;
  s32 v14;
  s32 v15;
  u32 v16;
  u32 v17;
  u32 v18;
  dds3ProcessID_t_o *runninglistf;
  u32 v21;
  s32 v22;
  s32 v23;
  dds3ProcessID_t_o *endinglistf;
  u32 v26;
  s32 v27;
  s32 v28;

  switch (type)
  {
    case 0:
      v16 = (*target)->flag;
      v17 = flag & 0xFFFFFF0;
      if (change)
        v18 = v16 | v17;
      else
        v18 = v16 & ~v17;
      (*target)->flag = v18;
      break;
    case 1:
    case 3:
      v10 = flag & 0xFFFFFF0;
      v12 = ~v10;
      if (startinglistf)
      {
        if (type == 3)
        {
          if (change)
          {
            do
            {
              startinglistf->flag |= v10;
              startinglistf = dds3ProcessID_t__Clone(startinglistf->next);
            }
            while (startinglistf);
          }
          else
          {
            do
            {
              startinglistf->flag &= v12;
              startinglistf = dds3ProcessID_t__Clone(startinglistf->next);
            }
            while (startinglistf);
          }
        }
        else if (type == 1)
        {
          do
          {
            if (startinglistf != *target)
            {
              v13 = startinglistf->flag;
              v14 = v13 & v12;
              v15 = v13 | v10;
              if (!change)
                v15 = v14;
              startinglistf->flag = v15;
            }
            startinglistf = dds3ProcessID_t__Clone(startinglistf->next);
          }
          while (startinglistf);
        }
        else
        {
          do
            startinglistf = dds3ProcessID_t__Clone(startinglistf->next);
          while (startinglistf);
        }
      }
      if (runninglistf)
      {
        if (type == 3)
        {
          if (change)
          {
            do
            {
              runninglistf->flag |= v10;
              runninglistf = dds3ProcessID_t__Clone(runninglistf->next);
            }
            while (runninglistf);
          }
          else
          {
            do
            {
              runninglistf->flag &= v12;
              runninglistf = dds3ProcessID_t__Clone(runninglistf->next);
            }
            while (runninglistf);
          }
        }
        else if (type == 1)
        {
          do
          {
            if (runninglistf != *target)
            {
              v21 = runninglistf->flag;
              v22 = v21 & v12;
              v23 = v21 | v10;
              if (!change)
                v23 = v22;
              runninglistf->flag = v23;
            }
            runninglistf = dds3ProcessID_t__Clone(runninglistf->next);
          }
          while (runninglistf);
        }
        else
        {
          do
            runninglistf = dds3ProcessID_t__Clone(runninglistf->next);
          while (runninglistf);
        }
      }
      if (endinglistf)
      {
        if (type == 3)
        {
          if (change)
          {
            do
            {
              endinglistf->flag |= v10;
              endinglistf = dds3ProcessID_t__Clone(endinglistf->next);
            }
            while (endinglistf);
          }
          else
          {
            do
            {
              endinglistf->flag &= v12;
              endinglistf = dds3ProcessID_t__Clone(endinglistf->next);
            }
            while (endinglistf);
          }
        }
        else if (type == 1)
        {
          do
          {
            if (endinglistf != *target)
            {
              v26 = endinglistf->flag;
              v27 = v26 & v12;
              v28 = v26 | v10;
              if (!change)
                v28 = v27;
              endinglistf->flag = v28;
            }
            endinglistf = dds3ProcessID_t__Clone(endinglistf->next);
          }
          while (endinglistf);
        }
        else
        {
          do
            endinglistf = dds3ProcessID_t__Clone(endinglistf->next);
          while (endinglistf);
        }
      }
      break;
    case 2:
      ChangeProcessFlagChild(change, target, flag, *&type);
      break;
    default:
      return;
  }
}

// 0x17b9e20
void ChangeProcessFlagChild(s32 change, dds3ProcessID_t **parent, u32 flag) {
  u32 v7;
  u32 v8;
  u32 v9;
  struct dds3ProcessID_t_o *child;
  dds3ProcessID_t_o *parenta;

  v7 = (*parent)->flag;
  v8 = v7 | flag & 0xFFFFFF0;
  v9 = v7 & ~(flag & 0xFFFFFF0);
  if (change)
    v9 = v8;
  (*parent)->flag = v9;
  child = (*parent)->child;
  for (parenta = child; child; parenta = child)
  {
    ChangeProcessFlagChild(change, &parenta, flag);
    child = child->sibling;
  }
}

// 0x17ba480
void DebugProcess(dds3ProcessID_t **pro, s8 mes) {
  ;
}

// 0x17ba4a0
void DebugProcessTree(dds3ProcessID_t **ps, s32 level) {
  ;
}

// 0x17b8100
void DeleteProcessList(dds3ProcessID_t **setp) {
  dds3ProcessID_t_o *v3;
  u32 v4;
  bool v5;
  struct dds3ProcessID_t_o *prev;
  dds3ProcessID_t_o *v7;
  struct dds3ProcessID_t_o *v8;
  struct dds3ProcessID_t_o *v9;
  struct dds3ProcessID_t_o **p_prev;
  u32 v11;
  struct dds3ProcessID_t_o *v14;
  struct dds3ProcessID_t_o *next;
  s32 v19;
  struct dds3ProcessID_t_o *v22;

  v3 = *setp;
  v4 = (*setp)->flag & 0xF;
  if (v4)
    v5 = ((*setp)->flag & 0xF) - 1 > 2;
  else
    v5 = 1;
  if (!v5)
  {
    prev = v3->prev;
    if (prev)
    {
      prev->next = v3->next;
    }
    else
    {
      switch (v4)
      {
        case 3u:
          next = v3->next;
          endinglistf = next;
          v7 = *setp;
          v8 = (*setp)->next;
          if (v8)
        case 2u:
          v22 = v3->next;
          runninglistf = v22;
          v7 = *setp;
          v8 = (*setp)->next;
          if (v8)
        case 1u:
          v14 = v3->next;
          startinglistf = v14;
          v7 = *setp;
          v8 = (*setp)->next;
          if (v8)
      }
    }
    v7 = *setp;
    v8 = (*setp)->next;
    if (v8)
    {
      v9 = v7->prev;
      p_prev = &v8->prev;
    }
    v19 = v7->flag & 0xF;
    switch (v19)
    {
      case 3:
        v9 = v7->prev;
        p_prev = &endinglistl;
        break;
      case 2:
        v9 = v7->prev;
        p_prev = &runninglistl;
        break;
      case 1:
        v9 = v7->prev;
        p_prev = &startinglistl;
        break;
      default:
        (*setp)->next = 0;
        (*setp)->prev = 0;
        v11 = (*setp)->flag & 0xF;
        switch (v11)
        {
          case 3u:
            --endinglistcnt;
            break;
          case 2u:
            --runninglistcnt;
            break;
          case 1u:
            --startinglistcnt;
            break;
        }
        return;
    }
    *p_prev = v9;
  }
}

// 0x17b8020
void EndProcess(dds3ProcessID_t **setp) {
  dds3ProcessID_t_o **v5;

  if (((*setp)->flag & 0xF) - 1 <= 1)
  {
    DeleteProcessList(setp);
    (*setp)->flag = (*setp)->flag & 0xFFFFFFF0 | 3;
    AddProcessList(setp);
    if (!(*setp)->shutdowntimer)
    {
      else
      {
        v5 = setp;
      }
      KillProcess(v5);
    }
  }
}

// 0x17b7f60
void Init(void) {
  startinglistf = 0;
  startinglistl = 0;
  startinglistcnt = 0;
  endinglistf = 0;
  endinglistl = 0;
  endinglistcnt = 0;
  runninglistf = 0;
  runninglistl = 0;
  runninglistcnt = 0;
  runprocess = 0;
}

// 0x17b88f0
void KillProcess(dds3ProcessID_t **setp) {
  struct dds3ProcessID_t_o *child;
  struct System_Byte_array *name;
  dds3ProcessID_t_o *v7;
  System_Func_AssemblyName__Assembly__o *shutdownfunc;
  dds3ProcessID_t_o *v9;
  struct dds3ProcessID_t_o *parent;
  dds3ProcessID_t_o *v11;
  dds3ProcessID_t_o *sibling;
  dds3ProcessID_t_o *id;

  id = 0;
  if (*setp)
  {
    child = (*setp)->child;
    if (child)
    {
      id = (*setp)->child;
      do
      {
        child = child->sibling;
        dds3KillProcess(&id, 0);
        id = child;
      }
      while (child);
    }
  }
  DeleteProcessList(setp);
  name = (*setp)->name;
  Write_2930400(StringLiteral_14726, &name->obj);
  v7 = *setp;
  shutdownfunc = (*setp)->shutdownfunc;
  if (shutdownfunc)
  {
    Assembly___Invoke(shutdownfunc, v7);
    v7 = *setp;
  }
  if (v7)
    v7->flag &= 0xFFFFFFF0;
  v9 = *setp;
  if (*setp)
  {
    parent = v9->parent;
    if (parent)
    {
      v11 = parent->child;
      if (v11 == v9)
      {
        parent->child = v9->sibling;
      }
      else if (v11)
      {
        while (1)
        {
          sibling = v11->sibling;
          if (sibling == v9)
            break;
          v11 = v11->sibling;
          if (!sibling)
        }
        if (sibling)
          v11->sibling = v9->sibling;
      }
      (*setp)->parent = 0;
      (*setp)->sibling = 0;
    }
  }
}

// 0x17b8c90
void PadEi(void) {
}

// 0x17b91e0
s32 RunProcess(dds3ProcessID_t **pro) {
    PadEi();
    EndProcess(0);
    return 0;
}

// 0x17b9890
void RunningProcess(void) {
  dds3KernelCore_c *v2;
  struct dds3KernelCore_StaticFields *static_fields;
  struct dds3ProcessID_t_o *runninglistf;
  struct dds3ProcessID_t_o *endinglistf;
  bool v6;
  struct dds3ProcessID_t_o *v7;
  struct dds3ProcessID_t_o *prev;
  struct dds3ProcessID_t_o *v12;
  struct dds3ProcessID_t_o *v15;
  dds3ProcessID_t_o *pro;

  pro = 0;
  static_fields = v2->static_fields;
  runninglistf = static_fields->runninglistf;
  endinglistf = static_fields->endinglistf;
  v6 = endinglistf == 0;
  if (runninglistf)
  {
    if (!v6)
    {
      while (1)
      {
        while (1)
        {
          if (runninglistf->priority > endinglistf->priority)
          {
            pro = endinglistf;
            prev = endinglistf->prev;
            else if (!RunProcess(&pro))
            {
              if (prev)
              {
                endinglistf = prev->next;
                v6 = endinglistf == 0;
              }
              else
              {
                v6 = endinglistf == 0;
              }
            }
            endinglistf = pro->next;
            v6 = endinglistf == 0;
          }
          pro = runninglistf;
          v7 = runninglistf->prev;
            break;
          if (RunProcess(&pro))
          if (v7)
          {
            runninglistf = v7->next;
            if (!runninglistf)
          }
          {
            if (!runninglistf)
            {
              v6 = 0;
            }
          }
          else
          {
            if (!runninglistf)
          }
        }
        if (!RunProcess(&pro))
        runninglistf = pro->next;
        if (!runninglistf)
      }
    }
    while (1)
    {
      while (1)
      {
        pro = runninglistf;
        v12 = runninglistf->prev;
          break;
        if (RunProcess(&pro))
        if (v12)
        {
          runninglistf = v12->next;
          if (!runninglistf)
            return;
        }
        else
        {
          if (!runninglistf)
            return;
        }
      }
      if (!RunProcess(&pro))
      runninglistf = pro->next;
      if (!runninglistf)
        return;
    }
  }
  if (!v6 && endinglistf)
  {
    do
    {
      while (1)
      {
        pro = endinglistf;
        v15 = endinglistf->prev;
          break;
        if (RunProcess(&pro))
        if (v15)
        {
          endinglistf = v15->next;
          if (!endinglistf)
            return;
        }
        {
          if (!endinglistf)
            return;
        }
        else
        {
          if (!endinglistf)
            return;
        }
      }
      if (!RunProcess(&pro))
      endinglistf = pro->next;
    }
    while (endinglistf);
  }
}

// 0x17bb570
void SetRandHistory(char *name, char *val) {
  struct System_String_array *v6;
  dds3KernelCore_c *v7;
  u64 v8;
  struct dds3KernelCore_StaticFields *static_fields;
  s64 *v10;
  u32 *randlog;
  dds3KernelCore_c *v15;
  struct dds3KernelCore_StaticFields *v16;
  struct System_String_array *v17;
  s64 randlogidx;
  s64 *v19;
  s64 *v20;

  else  v6 = NewSpecific(string, 0x1Cu);
  randlog = v6;
  v8 = 0;
  if ((v7->_2.bitflags2 & 2) != 0)
  static_fields = v7->static_fields;
  v10 = StringLiteral_14731;
  randlog = static_fields->randlog;
  if (!StringLiteral_14731)
  while (1)
  {
    *&randlog[2 * v8 + 8] = StringLiteral_14731;
    if (v8 == 27)
      break;
    ++v8;
    v10 = StringLiteral_14731;
    if (StringLiteral_14731)
  }
  if (!IsNullOrEmpty(name))
  {
    v16 = v15->static_fields;
    v17 = v16->randlog;
    randlogidx = v16->randlogidx;
    v19 = Concat_5221536(name, StringLiteral_84, val);
    v20 = v19;
    v17->m_Items[randlogidx] = v20;
    randlogidx = (randlogidx + 1) % 28;
  }
}

// 0x17b8aa0
void StartProcess(dds3ProcessID_t **setp) {
  DeleteProcessList(setp);
  (*setp)->flag = (*setp)->flag & 0xFFFFFFF0 | 2;
  AddProcessList(setp);
  (*setp)->starttime = 0;
  (*setp)->runtime = 0;
}

// 0x17b8b40
void StartingProcess(void) {
    DeleteProcessList(0);
    AddProcessList(0);
}

// 0x17bb180
void dds3DebugNowProcess(void) {
}

// 0x17bad60
void dds3EndProcess(dds3ProcessID_t **id) {
  if (((*id)->flag & 0xF) == 2)
  {
    DeleteProcessList(id);
    (*id)->flag = (*id)->flag & 0xFFFFFFF0 | 3;
    AddProcessList(id);
  }
}

// 0x17b9d30
void dds3EndingProcess(void) {
    KillProcess(0);
}

// 0x17baec0
s32 dds3ExistProcess(dds3ProcessID_t **id) {
    return 0;
}

// 0x17ba230
s32 dds3GetProcessCount(u32 type) {
  char v2;
  s32 v3;

  v2 = type;
  v3 = v2 & 0xF;
  switch (v3)
  {
    case 3:
      return endinglistcnt;
    case 2:
      return runninglistcnt;
    case 1:
      return startinglistcnt;
    default:
      return 0;
  }
}

// 0x17bb170
void *dds3GetProcessData(dds3ProcessID_t **id) {
  return (*id)->workdata;
}

// 0x17bb150
u32 dds3GetProcessRunTime(dds3ProcessID_t **id) {
  return (*id)->runtime;
}

// 0x17bb140
u32 dds3GetProcessStartTime(dds3ProcessID_t **id) {
  return (*id)->starttime;
}

// 0x17bae30
u32 dds3GetProcessStat(dds3ProcessID_t **id) {
  u32 result;

  else
  {
    result = dds3ExistProcess(id);
    if (!result)
      return result;
  }
  if (((*id)->flag & 0xC) != 0)
    return 0;
  else
    return (*id)->flag & 0xF;
}

// 0x17bb4a0
u32 dds3GetRandA(char *name) {
    sdfGetRand(0);
    SetRandHistory(0, 0);
    return 0;
}

// 0x17bb7e0
u32 dds3GetRandB(char *name) {
    sdfGetRand(0);
    SetRandHistory(0, 0);
    return 0;
}

// 0x17bb8d0
f32 dds3GetRandFloatA(char *name) {
    sdfGetRandFloat(0);
    SetRandHistory(0, 0);
    return 0;
}

// 0x17bb9a0
f32 dds3GetRandFloatB(char *name) {
    sdfGetRandFloat(0);
    SetRandHistory(0, 0);
    return 0;
}

// 0x17bba90
u32 dds3GetRandIntA(u32 aLimit, char *name) {
    sdfGetRandInt(0, 0);
    SetRandHistory(0, 0);
    return 0;
}

// 0x17bbb70
u32 dds3GetRandIntB(u32 aLimit, char *name) {
    sdfGetRandInt(0, 0);
    SetRandHistory(0, 0);
    return 0;
}

// 0x17b9b90
s32 dds3KillProcess(dds3ProcessID_t **id, s32 shutdowntimer) {
  dds3ProcessID_t_o *v5;

  v5 = *id;
  if (!*id)
    return 0;
  if (v5->func_ans == -1)
    return 0;
  if ((v5->flag & 0xF) - 1 < 2)
  {
    v5->shutdowntimer = shutdowntimer;
    EndProcess(id, *&shutdowntimer);
    return 1;
  }
  if ((v5->flag & 0xF) == 3)
  {
    v5->shutdowntimer = shutdowntimer;
    if (!(*id)->shutdowntimer)
    {
      KillProcess(id, *&shutdowntimer);
    }
    return 1;
  }
  return 0;
}

// 0x17b5650
s32 dds3KillProcessName(char *name, s32 shutdowntimer) {
  dds3ProcessID_t_o *v5;
  dds3ProcessID_t_o *id;

  id = 0;
  v5 = dds3SearchProcessName(name, *&shutdowntimer);
  id = v5;
  if (v5)
  {
    LODWORD(v5) = dds3KillProcess(&id, shutdowntimer);
  }
  return v5;
}

// 0x17bb290
void dds3LinkProcess(dds3ProcessID_t **parent, dds3ProcessID_t **target) {
  dds3ProcessID_t_o *v5;
  struct dds3ProcessID_t_o *v6;
  dds3ProcessID_t_o *child;
  dds3ProcessID_t_o *sibling;
  struct dds3ProcessID_t_o **p_child;
  struct dds3ProcessID_t_o *v10;
  struct dds3ProcessID_t_o *v11;

  v5 = *target;
  if ((*target)->parent)
  {
    if (v5)
    {
      v6 = v5->parent;
      if (v6)
      {
        child = v6->child;
        if (child == v5)
        {
          v6->child = v5->sibling;
        }
        else if (child)
        {
          while (1)
          {
            sibling = child->sibling;
            if (sibling == v5)
              break;
            child = child->sibling;
            if (!sibling)
          }
          if (sibling)
            child->sibling = v5->sibling;
        }
        (*target)->parent = 0;
        (*target)->sibling = 0;
      }
    }
  }
  p_child = &(*parent)->child;
  v10 = *p_child;
  if (*p_child)
  {
    do
    {
      v11 = v10;
      v10 = v10->sibling;
    }
    while (v10);
    p_child = &v11->sibling;
  }
  *p_child = *target;
  (*target)->parent = *parent;
}

// 0x17ba490
void dds3PrintProcessList(void) {
  ;
}

// 0x17ba4b0
void dds3PrintProcessTree(void) {
  ;
}

// 0x17ba4c0
s32 dds3ProcessMain(void) {
  StartingProcess();
  RunningProcess();
  dds3EndingProcess();
  return 1;
}

// 0x17bb420
void dds3ResetProcessFlag(dds3ProcessID_t **target, u32 flag, s32 type) {
  ChangeProcessFlag(0, target, flag, type);
}

// 0x17bbc70
dds3ProcessID_t *dds3SearchProcessID(s32 id) {
    return 0;
}

// 0x17ba530
dds3ProcessID_t *dds3SearchProcessName(char *namestr) {
    return 0;
}

// 0x17ba340
dds3ProcessID_t *dds3SearchProcessNumber(u32 type, s32 n) {
  char v4;
  s32 v5;
  dds3ProcessID_t_o *result;
  s32 v8;

  v4 = type;
  v5 = v4 & 0xF;
  if (v5 == 3)
  {
    result = endinglistf;
    if (n < 1)
      return result;
    if (result)
    {
      v8 = 1;
      do
      {
        result = result->next;
        if (v8 >= n)
          break;
        ++v8;
      }
      while (result);
    }
    return result;
  }
  if (v5 == 2)
  {
    result = runninglistf;
    if (n < 1)
      return result;
  }
  if (v5 != 1)
    return 0;
  result = startinglistf;
  if (n >= 1)
  return result;
}

// 0x17bb010
dds3ProcessID_t *dds3SearchProcessPriority(s32 priority) {
    return 0;
}

// 0x17bb160
void dds3SetProcessData(dds3ProcessID_t **id, void *data) {
  (*id)->workdata = data;
}

// 0x17bb3a0
void dds3SetProcessFlag(dds3ProcessID_t **target, u32 flag, s32 type) {
  ChangeProcessFlag(1, target, flag, type);
}

// 0x17bae00
void dds3SetShutdownTimer(dds3ProcessID_t **id, s32 newtimer) {
  if (((*id)->flag & 0xF) != 0 && ((*id)->flag & 0xF) - 1 <= 2)
    (*id)->shutdowntimer = newtimer;
}

// 0x17b52c0
dds3ProcessID_t *dds3StartProcess(char *namestr, u32 priority, s32 starttimer, s32 shutdowntimer, void *processfunc, dds3ProcessID_t *id0, void *shutdownfunc, dds3ProcessID_t *id1, void *data) {
  System_Text_Encoding_o *ASCII;
  s64 v17;
  dds3ProcessID_t_o *v18;
  u64 v19;
  struct System_Byte_array *name;
  s32 Length;
  dds3ProcessID_t_o *v23;
  struct System_Byte_array *v24;
  s64 v25;
  u64 v26;
  s32 v30;
  s64 v31;
  dds3ProcessID_t_c *klass;
  dds3ProcessID_t_o *result;
  System_Func_dds3ProcessID_t__object__o *v38;
  dds3ProcessID_t_o *setp;

  setp = 0;
  ASCII = get_ASCII();
  v17 = (ASCII->klass->vtable._28_GetBytes.methodPtr)(ASCII, namestr, ASCII->klass->vtable._28_GetBytes.method);
  v18 = Allocate(dds3ProcessID_t);
  dds3ProcessID_t___ctor(v18);
  setp = v18;
  if (!v18)
    return 0;
  v38 = shutdownfunc;
  v19 = 0;
  v18->namehash = 0;
  name = v18->name;
  while (1)
  {
    name->m_Items[v19] = 0;
    if (v19 == 23)
      break;
    ++v19;
    name = setp->name;
    if (v19 >= LODWORD(name->max_length))
  }
  Length = get_Length(namestr);
  v23 = setp;
  v24 = setp->name;
  if (Length >= 1)
  {
    v25 = 32;
    do
    {
      v26 = v25 - 32;
      *(&v24->obj.klass + v25) = *(v17 + v25);
      v23 = setp;
      setp->namehash += *(v17 + v25);
      v30 = get_Length(namestr);
      v24 = v23->name;
      v31 = v25 - 31;
      ++v25;
    }
    while (v31 < v30);
  }
  v24->m_Items[23] = 0;
  v23->flag = 1;
  v23->priority = priority;
  klass = v23->klass;
  *&v23->starttime = 0;
  v23->id = (klass->vtable._2_GetHashCode.methodPtr)(v23, klass->vtable._2_GetHashCode.method);
  v23->starttimer = starttimer;
  v23->shutdowntimer = shutdowntimer;
  v23->child = 0;
  v23->sibling = 0;
  v23->processfunc = processfunc;
  v23->shutdownfunc = v38;
  v23->prev = 0;
  v23->parent = 0;
  v23->workdata = data;
  v23->next = 0;
  AddProcessList(&setp);
  result = setp;
  if (!setp->starttimer)
  {
    DeleteProcessList(&setp);
    setp->flag = setp->flag & 0xFFFFFFF0 | 2;
    AddProcessList(&setp);
    result = setp;
    *&setp->starttime = 0;
  }
  return result;
}

// 0x17b9cc0
void dds3UnlinkProcess(dds3ProcessID_t **target) {
  dds3ProcessID_t_o *v2;
  struct dds3ProcessID_t_o *parent;
  dds3ProcessID_t_o *child;
  dds3ProcessID_t_o *sibling;

  v2 = *target;
  if (*target)
  {
    parent = v2->parent;
    if (parent)
    {
      child = parent->child;
      if (child == v2)
      {
        parent->child = v2->sibling;
      }
      else if (child)
      {
        while (1)
        {
          sibling = child->sibling;
          if (sibling == v2)
            break;
          child = child->sibling;
          if (!sibling)
        }
        if (sibling)
          child->sibling = v2->sibling;
      }
      (*target)->parent = 0;
      (*target)->sibling = 0;
    }
  }
}
