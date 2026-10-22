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
static char *randlog;

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
LABEL_15:
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
              goto LABEL_63;
          }
          *p_endinglistl = *setp;
          goto LABEL_63;
        }
      }
      prev = endinglistf->prev;
      if (prev)
      {
        prev->next = v6;
        (*setp)->prev = endinglistf->prev;
LABEL_74:
        (*setp)->next = endinglistf;
        endinglistf->prev = *setp;
        goto LABEL_75;
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
          break;
        default:
LABEL_73:
          (*setp)->prev = 0;
          goto LABEL_74;
      }
      startinglistf = v6;
      goto LABEL_73;
    case 2u:
      endinglistf = runninglistf;
      v6 = *setp;
      if (endinglistf)
        goto LABEL_15;
      break;
    case 1u:
      endinglistf = startinglistf;
      v6 = *setp;
      if (endinglistf)
        goto LABEL_15;
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
      goto LABEL_53;
  }
  *p_runninglistl = *setp;
LABEL_53:
  (*setp)->prev = 0;
LABEL_63:
  (*setp)->next = 0;
LABEL_75:
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
            goto LABEL_12;
          goto LABEL_41;
        case 2u:
          v22 = v3->next;
          runninglistf = v22;
          v7 = *setp;
          v8 = (*setp)->next;
          if (v8)
            goto LABEL_12;
          goto LABEL_41;
        case 1u:
          v14 = v3->next;
          startinglistf = v14;
          v7 = *setp;
          v8 = (*setp)->next;
          if (v8)
            goto LABEL_12;
          goto LABEL_41;
      }
    }
    v7 = *setp;
    v8 = (*setp)->next;
    if (v8)
    {
LABEL_12:
      v9 = v7->prev;
      p_prev = &v8->prev;
      goto LABEL_13;
    }
LABEL_41:
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
LABEL_14:
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
LABEL_13:
    *p_prev = v9;
    goto LABEL_14;
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
  Write_2930400("shutdown {0}!!\n", &name->obj);
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
            goto LABEL_33;
        }
        if (sibling)
          v11->sibling = v9->sibling;
      }
LABEL_33:
      (*setp)->parent = 0;
      (*setp)->sibling = 0;
    }
  }
}

// 0x17b8c90
void PadEi(void) {
  s64 v2;
  u64 v3;
  s64 i;
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v9;
  System_Byte_array *v11;
  struct System_Byte_array_array_array *dds3PrivatePadMap;
  System_Byte_array_array *v14;
  u64 v15;
  System_Byte_array *v17;
  char v19;
  struct System_Byte_array_array_array *v21;
  System_Byte_array_array *v23;
  System_Byte_array *v25;
  struct System_Byte_array_array_array *v26;
  System_Byte_array_array *v28;
  System_Byte_array *v30;
  char v31;
  s64 v32;
  u64 v37;
  struct System_Byte_array_array_array *dds3PadAnalog;
  System_Byte_array_array *v40;
  System_Byte_array *v42;
  struct System_Byte_array_array_array *dds3PrivatePadAnalog;
  System_Byte_array_array *v45;
  System_Byte_array *v46;
  u8 v47;
  struct System_Byte_array_array_array *v48;
  System_Byte_array_array *v50;
  System_Byte_array *v52;
  struct System_Byte_array_array_array *v53;
  System_Byte_array_array *v55;
  System_Byte_array *v57;
  u8 v59;
  struct System_Byte_array_array *dds3PadAnalogMap;
  struct System_Byte_array_array *dds3PrivatePadAnalogMap;
  System_Byte_array *v65;
  System_Byte_array *v67;
  u8 v69;

  v2 = 0;
  do
  {
    v3 = v2;
    for (i = 32; i != 48; ++i)
    {
      else
      {
        if (!LODWORD(dds3PadMap->max_length))
        {
LABEL_8:
        }
      }
      v9 = dds3PadMap->m_Items[0];
      v11 = v9->m_Items[v3];
      v14 = dds3PrivatePadMap->m_Items[0];
      v15 = i - 32;
      v17 = v14->m_Items[v3];
      v19 = *(&v17->obj.klass + i);
      *(&v11->obj.klass + i) = v19;
      v21 = dds3PadMap;
      v23 = v21->m_Items[1];
      v25 = v23->m_Items[v3];
      v26 = dds3PrivatePadMap;
      v28 = v26->m_Items[1];
      v30 = v28->m_Items[v3];
      v31 = *(&v30->obj.klass + i);
      *(&v25->obj.klass + i) = v31;
    }
    v32 = 0;
    do
    {
      v37 = v32;
      v40 = dds3PadAnalog->m_Items[v3];
      v42 = v40->m_Items[v37];
      v45 = dds3PrivatePadAnalog->m_Items[v3];
      v46 = v45->m_Items[v37];
      v47 = v46->m_Items[0];
      v42->m_Items[0] = v47;
      v48 = dds3PadAnalog;
      v50 = v48->m_Items[v3];
      v52 = v50->m_Items[v37];
      v53 = dds3PrivatePadAnalog;
      v55 = v53->m_Items[v3];
      v57 = v55->m_Items[v37];
      v59 = v57->m_Items[1];
      v52->m_Items[1] = v59;
      v65 = dds3PadAnalogMap->m_Items[v3];
      v67 = dds3PrivatePadAnalogMap->m_Items[v3];
      v69 = v67->m_Items[v37];
      v65->m_Items[v37] = v69;
      v32 = 1;
    }
    while (!v37);
    v2 = 1;
  }
  while (!v3);
}

// 0x17b91e0
s32 RunProcess(dds3ProcessID_t **pro) {
  dds3ProcessID_t_o *v3;
  u64 v4;
  dds3ProcessID_t_o *v5;
  s32 v6;
  s64 v7;
  u64 v8;
  s64 i;
  struct System_Byte_array_array_array *dds3PadMap;
  System_Byte_array_array *v12;
  u64 v13;
  System_Byte_array *v15;
  struct System_Byte_array_array_array *v17;
  System_Byte_array_array *v19;
  System_Byte_array *v21;
  struct System_Byte_array_array_array *dds3PadAnalog;
  System_Byte_array_array *v25;
  System_Byte_array *v26;
  struct System_Byte_array_array_array *v27;
  System_Byte_array_array *v28;
  System_Byte_array *v29;
  struct System_Byte_array_array *dds3PadAnalogMap;
  System_Byte_array *v32;
  struct System_Byte_array_array_array *v41;
  System_Byte_array_array *v43;
  System_Byte_array *v44;
  struct System_Byte_array_array_array *v45;
  System_Byte_array_array *v47;
  System_Byte_array *v48;
  struct System_Byte_array_array *v50;
  System_Byte_array *v52;
  System_Text_Encoding_o *ASCII;
  System_Reflection_Assembly_o *v58;
  char *v59;
  s64 *v60;
  dds3ProcessID_t_o *v61;
  System_Text_Encoding_o *v62;
  u64 v66[3];

  v3 = *pro;
  if (((*pro)->flag & 0x20) == 0)
  {
    *(*(v4 + 184) + 72LL) = v3;
    if (((*pro)->flag & 0x10) != 0)
    {
      v7 = 0;
      do
      {
        v8 = v7;
        for (i = 32; i != 48; ++i)
        {
          else
          {
            if (!LODWORD(dds3PadMap->max_length))
            {
LABEL_21:
            }
          }
          v12 = dds3PadMap->m_Items[0];
          v13 = i - 32;
          v15 = v12->m_Items[v8];
          *(&v15->obj.klass + i) = 0;
          v17 = dds3PadMap;
          v19 = v17->m_Items[1];
          v21 = v19->m_Items[v8];
          *(&v21->obj.klass + i) = 0;
        }
        v25 = dds3PadAnalog->m_Items[v8];
        v26 = v25->m_Items[0];
        v26->m_Items[0] = 0;
        v27 = dds3PadAnalog;
        v28 = v27->m_Items[v8];
        v29 = v28->m_Items[0];
        v29->m_Items[1] = 0;
        v32 = dds3PadAnalogMap->m_Items[v8];
        v32->m_Items[0] = 0;
        v41 = dds3PadAnalog;
        v43 = v41->m_Items[v8];
        v44 = v43->m_Items[1];
        v44->m_Items[0] = 0;
        v45 = dds3PadAnalog;
        v47 = v45->m_Items[v8];
        v48 = v47->m_Items[1];
        v48->m_Items[1] = 0;
        v50 = dds3PadAnalogMap;
        v52 = v50->m_Items[v8];
        v7 = 1;
        v52->m_Items[1] = 0;
      }
      while (!v8);
      v5 = *pro;
      if (!(*pro)->processfunc)
        goto LABEL_89;
    }
    else
    {
      PadEi(v4);
      v5 = *pro;
      if (!(*pro)->processfunc)
        goto LABEL_89;
    }
    if (v5->func_ans != -1)
    {
      v5->func_ans = 0;
      ASCII = get_ASCII();
      (ASCII->klass[1]._1.byval_arg.data)(ASCII, (*pro)->name, *&ASCII->klass[1]._1.byval_arg.bits);
      v58 = Assembly___Invoke(
              (*pro)->processfunc,
              *pro);
      if (v58)
      {
        if (v58->klass != System_Func_dds3ProcessID_t__object_)
        {
          sub_8FC2C0(v58->klass->_1.element_class, System_Func_dds3ProcessID_t__object_, v66);
          if ((v66[0] & 1) != 0)
            v59 = v66[2];
          else
            v59 = v66 + 1;
          v60 = sub_8C4940(v59);
        }
        (*pro)->processfunc = v58;
      }
      v61 = *pro;
      if ((*pro)->func_ans == -1 && (v61->flag & 0xF) == 2)
      {
        v62 = get_ASCII();
        (v62->klass[1]._1.byval_arg.data)(v62, (*pro)->name, *&v62->klass[1]._1.byval_arg.bits);
        EndProcess(pro);
        v6 = 0;
        goto LABEL_93;
      }
      v61->func_ans = 0;
      v5 = *pro;
    }
LABEL_89:
    ++v5->runtime;
    v6 = 1;
LABEL_93:
    runprocess = 0;
    return v6;
  }
  return 1;
}

// 0x17b9890
void RunningProcess(void) {
  struct dds3ProcessID_t_o *runninglistf;
  struct dds3ProcessID_t_o *endinglistf;
  bool v6;
  struct dds3ProcessID_t_o *v7;
  struct dds3ProcessID_t_o *prev;
  struct dds3ProcessID_t_o *v12;
  struct dds3ProcessID_t_o *v15;
  dds3ProcessID_t_o *pro;

  pro = 0;
  v6 = endinglistf == 0;
  if (runninglistf)
  {
LABEL_9:
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
LABEL_29:
              if (prev)
              {
                endinglistf = prev->next;
                v6 = endinglistf == 0;
              }
              else
              {
                v6 = endinglistf == 0;
              }
              goto LABEL_9;
            }
            endinglistf = pro->next;
            v6 = endinglistf == 0;
            goto LABEL_9;
          }
          pro = runninglistf;
          v7 = runninglistf->prev;
            break;
          if (RunProcess(&pro))
            goto LABEL_14;
LABEL_17:
          if (v7)
          {
            runninglistf = v7->next;
            if (!runninglistf)
              goto LABEL_51;
          }
          {
            if (!runninglistf)
            {
LABEL_51:
              v6 = 0;
              goto LABEL_52;
            }
          }
          else
          {
            if (!runninglistf)
              goto LABEL_51;
          }
        }
        if (!RunProcess(&pro))
          goto LABEL_17;
LABEL_14:
        runninglistf = pro->next;
        if (!runninglistf)
          goto LABEL_51;
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
          goto LABEL_40;
LABEL_43:
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
        goto LABEL_43;
LABEL_40:
      runninglistf = pro->next;
      if (!runninglistf)
        return;
    }
  }
LABEL_52:
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
          goto LABEL_57;
LABEL_60:
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
        goto LABEL_60;
LABEL_57:
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
  s64 *v10;
  u32 *randlog;
  struct System_String_array *v17;
  s64 randlogidx;
  s64 *v19;
  s64 *v20;

  else if (randlog)
  {
    goto LABEL_22;
  }
  v6 = NewSpecific(string, 0x1Cu);
  randlog = v6;
  v8 = 0;
  if ((v7->_2.bitflags2 & 2) != 0)
    goto LABEL_12;
LABEL_13:
  v10 = "---";
  if (!"---")
    goto LABEL_17;
LABEL_14:
  while (1)
  {
LABEL_17:
    *&randlog[2 * v8 + 8] = "---";
    if (v8 == 27)
      break;
    ++v8;
      goto LABEL_13;
LABEL_12:
      goto LABEL_13;
    v10 = "---";
    if ("---")
      goto LABEL_14;
  }
LABEL_22:
  if (!IsNullOrEmpty(name))
  {
    v17 = randlog;
    v19 = Concat_5221536(name, ":", val);
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
  struct dds3ProcessID_t_o *startinglistf;
  dds3ProcessID_t_o *setp;

  setp = 0;
  if (startinglistf)
    goto LABEL_18;
}

// 0x17bb180
void dds3DebugNowProcess(void) {
  struct dds3ProcessID_t_o *runprocess;

  else
  {
    if (runprocess)
      goto LABEL_6;
  }
  Write("now process [NULL]\n", 0);
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
  struct dds3ProcessID_t_o *endinglistf;
  dds3ProcessID_t_o *setp;

  setp = 0;
  else
  {
    if (endinglistf)
      goto LABEL_6;
  }
}

// 0x17baec0
s32 dds3ExistProcess(dds3ProcessID_t **id) {
  struct dds3ProcessID_t_o *startinglistf;
  struct dds3ProcessID_t_o *runninglistf;
  struct dds3ProcessID_t_o *endinglistf;

  else
  {
    if (startinglistf)
      goto LABEL_6;
  }
LABEL_8:
  else
  {
    if (runninglistf)
      goto LABEL_11;
  }
LABEL_17:
  if (endinglistf)
  {
LABEL_20:
    while (endinglistf != *id)
    {
      endinglistf = endinglistf->next;
      if (!endinglistf)
        return 0;
    }
    return 1;
  }
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
  System_String_o *v5;
  u32 Rand;
  sdfRandCB_t_o *aCB;

  Rand = 0;
  aCB = 0;
  Rand = sdfGetRand(&aCB);
  v5 = sub_818660(&Rand, "d8");
  SetRandHistory(name, v5);
  return Rand;
}

// 0x17bb7e0
u32 dds3GetRandB(char *name) {
  System_String_o *v5;
  u32 Rand;

  Rand = 0;
  Rand = sdfGetRand(&dds3RandCB);
  v5 = sub_818660(&Rand, "d8");
  SetRandHistory(name, v5);
  return Rand;
}

// 0x17bb8d0
f32 dds3GetRandFloatA(char *name) {
  System_String_o *v5;
  f32 RandFloat;
  sdfRandCB_t_o *aCB;

  RandFloat = 0.0;
  aCB = 0;
  RandFloat = sdfGetRandFloat(&aCB);
  v5 = sub_4FDC70(&RandFloat, "f8");
  SetRandHistory(name, v5);
  return RandFloat;
}

// 0x17bb9a0
f32 dds3GetRandFloatB(char *name) {
  System_String_o *v5;
  f32 RandFloat;

  RandFloat = 0.0;
  RandFloat = sdfGetRandFloat(&dds3RandCB);
  v5 = sub_4FDC70(&RandFloat, "f8");
  SetRandHistory(name, v5);
  return RandFloat;
}

// 0x17bba90
u32 dds3GetRandIntA(u32 aLimit, char *name) {
  System_String_o *v7;
  u32 RandInt;
  sdfRandCB_t_o *aCB;

  RandInt = 0;
  aCB = 0;
  RandInt = sdfGetRandInt(&aCB, aLimit);
  v7 = sub_818660(&RandInt, "d8");
  SetRandHistory(name, v7);
  return RandInt;
}

// 0x17bbb70
u32 dds3GetRandIntB(u32 aLimit, char *name) {
  System_String_o *v7;
  u32 RandInt;

  RandInt = 0;
  RandInt = sdfGetRandInt(&dds3RandCB, aLimit);
  v7 = sub_818660(&RandInt, "d8");
  SetRandHistory(name, v7);
  return RandInt;
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
              goto LABEL_17;
          }
          if (sibling)
            child->sibling = v5->sibling;
        }
LABEL_17:
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
  dds3ProcessID_t_o *result;

  else
  {
    result = startinglistf;
    if (result)
      goto LABEL_6;
  }
LABEL_8:
  result = runninglistf;
  if (!result)
  {
LABEL_13:
    for (result = endinglistf; result; result = result->next)
    {
      if (result->id == id)
        break;
    }
    return result;
  }
LABEL_11:
  while (result->id != id)
  {
    result = result->next;
    if (!result)
      goto LABEL_13;
  }
  return result;
}

// 0x17ba530
dds3ProcessID_t *dds3SearchProcessName(char *namestr) {
  System_Text_Encoding_o *ASCII;
  s64 v4;
  u64 *v5;
  u64 v7;
  u32 *v8;
  u64 *v9;
  s64 v10;
  u64 v35;
  u64 v38;
  s32 v39;
  u64 *v40;
  struct dds3ProcessID_t_o *startinglistf;
  s64 v44;
  struct System_Byte_array *name;
  dds3ProcessID_t_o *endinglistf;
  s64 v54;
  s64 v55;
  struct System_Byte_array *v57;

  ASCII = get_ASCII();
  v4 = (ASCII->klass->vtable._28_GetBytes.methodPtr)(ASCII, namestr, ASCII->klass->vtable._28_GetBytes.method);
  v5 = NewSpecific(byte, 0x18u);
  v8 = v5 + 3;
  v7 = *(v5 + 6);
  v9 = v5;
  *(v5 + 32) = 0;
  *(v5 + 33) = 0;
  *(v5 + 34) = 0;
  *(v5 + 35) = 0;
  *(v5 + 36) = 0;
  *(v5 + 37) = 0;
  *(v5 + 38) = 0;
  *(v5 + 39) = 0;
  *(v5 + 40) = 0;
  *(v5 + 41) = 0;
  *(v5 + 42) = 0;
  *(v5 + 43) = 0;
  *(v5 + 44) = 0;
  *(v5 + 45) = 0;
  *(v5 + 46) = 0;
  *(v5 + 47) = 0;
  *(v5 + 48) = 0;
  *(v5 + 49) = 0;
  *(v5 + 50) = 0;
  *(v5 + 51) = 0;
  *(v5 + 52) = 0;
  *(v5 + 53) = 0;
  *(v5 + 54) = 0;
  *(v5 + 55) = 0;
  v10 = *(v4 + 24);
  if (v10 >= 1)
  {
    v35 = 0;
    do
    {
      *(v5 + v35 + 32) = *(v4 + 32 + v35);
      LODWORD(v10) = *(v4 + 24);
      ++v35;
    }
    while (v35 < v10);
  }
  v38 = 0;
  v39 = 0;
  v40 = v5 + 4;
  if (!*v8)
  {
LABEL_62:
  }
  while (*(v40 + v38))
  {
    v39 += *(v40 + v38++);
    if (v38 >= *v8)
      goto LABEL_62;
  }
  else
  {
    if (!startinglistf)
      goto LABEL_81;
  }
  do
  {
    if (startinglistf->namehash == v39)
    {
      v44 = 0;
      while (1)
      {
        name = startinglistf->name;
        if (*(v9 + v38 + v44 + 32) != name->m_Items[v38 + v44])
          break;
        --v44;
        if (v38 + v44 == -1)
          return startinglistf;
      }
    }
    startinglistf = startinglistf->next;
  }
  while (startinglistf);
LABEL_81:
  else
  {
    startinglistf = runninglistf;
    if (startinglistf)
      goto LABEL_84;
  }
  if (!endinglistf)
    return 0;
  v54 = v9 + v38 + 32;
  do
  {
    if (endinglistf->namehash == v39)
    {
      v55 = 0;
      while (1)
      {
        v57 = endinglistf->name;
        if (*(v54 + v55) != v57->m_Items[v38 + v55])
          break;
        --v55;
        if (v38 + v55 == -1)
          return endinglistf;
      }
    }
    endinglistf = endinglistf->next;
    startinglistf = 0;
  }
  while (endinglistf);
  return startinglistf;
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
LABEL_10:
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
    goto LABEL_10;
  }
  if (v5 != 1)
    return 0;
  result = startinglistf;
  if (n >= 1)
    goto LABEL_10;
  return result;
}

// 0x17bb010
dds3ProcessID_t *dds3SearchProcessPriority(s32 priority) {
  s64 v2;
  dds3ProcessID_t_o *result;

  LODWORD(v2) = priority;
  else
  {
    result = startinglistf;
    if (result)
      goto LABEL_6;
  }
LABEL_8:
  result = runninglistf;
  if (!result)
  {
LABEL_13:
    for (result = endinglistf; result; result = result->next)
    {
      if (result->priority == v2)
        break;
    }
    return result;
  }
LABEL_11:
  while (result->priority != v2)
  {
    result = result->next;
    if (!result)
      goto LABEL_13;
  }
  return result;
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
  if (!LODWORD(name->max_length))
  {
LABEL_7:
  }
  while (1)
  {
    name->m_Items[v19] = 0;
    if (v19 == 23)
      break;
    ++v19;
    name = setp->name;
    if (v19 >= LODWORD(name->max_length))
      goto LABEL_7;
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
            goto LABEL_11;
        }
        if (sibling)
          child->sibling = v2->sibling;
      }
LABEL_11:
      (*target)->parent = 0;
      (*target)->sibling = 0;
    }
  }
}
