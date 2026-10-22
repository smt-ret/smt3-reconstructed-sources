#include "types.h"

typedef struct Smg Smg;
typedef struct Smg__MidiWork Smg__MidiWork;
typedef struct Smg_eDefineSMG Smg_eDefineSMG;
typedef struct Smg_eReq Smg_eReq;
typedef struct Smg_eType Smg_eType;

struct Smg__MidiWork {
    char *DefineName;
    char *FileName;
    s32 MidiId;
    bool LoopMode;
    char *Key_DefineName;
    s32 Key_MidiId;
};

struct Smg_eType {
    s32 value__;
};

struct Smg_eReq {
    s32 value__;
};

struct Smg_eDefineSMG {
    s32 value__;
};

static Smg *Instance;
static Smg__MidiWork *FindOut;

void MidiWork___Set(Smg__MidiWork *this, char *name, char *filename, s32 id, bool loop, char *key_name, s32 key_id);
bool _Find(Smg *this, s32 type, char *name);
bool _Find_1915872(Smg *this, s32 type, s32 id);
void *_GetTable(Smg *this, s32 type, char *name);
void _SmgTableInit(Smg *this);

// 0x1d32e0
void Awake(Smg *this) {
  Instance = this;
  Log("SMGテーブル Awake() です", 0);
}

// 0x1d3950
bool Find(s32 type, char *name) {
  return _Find(Instance, type, name);
}

// 0x1d3ee0
s32 FindId(s32 type, char *name) {
  if (!_Find(Instance, type, name))
    return -1;
  return FindOut->MidiId;
}

// 0x1d3fb0
s32 FindId_1916848(s32 type, s32 id) {
  s32 v3;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  s64 v8;
  s32 MidiId;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v14;

  v3 = id;
  memset(&v14, 0, sizeof(v14));
  if (type <= 7)
    __asm { BR              X11 }
  Values = Type___get_Values(Instance->_tableBgm);
  Type___GetEnumerator(&v14, Values);
  while ((sub_4D4B20(&v14) & 1) != 0)
  {
    v8 = sub_4D4CB0(&v14);
    if (*(v8 + 48) == v3)
    {
      MidiWork___Set(FindOut, *(v8 + 16), *(v8 + 24), *(v8 + 32), *(v8 + 36), *(v8 + 40), v3, 0);
      MidiId = FindOut->MidiId;
      nullsub_48(&v14);
      return MidiId;
    }
  }
  nullsub_48(&v14);
  MidiId = -1;
  FindOut->DefineName = "";
  return MidiId;
}

// 0x1d3b60
bool Find_1915744(s32 type, s32 id) {
  return _Find_1915872(Instance, type, id);
}

// 0x132f250
void MidiWork___Set(Smg__MidiWork *this, char *name, char *filename, s32 id, bool loop, char *key_name, s32 key_id) {
  this->DefineName = name;
  this->FileName = filename;
  this->MidiId = id;
  this->LoopMode = loop;
  this->Key_DefineName = key_name;
  this->Key_MidiId = key_id;
}

// 0x1d42a0
void SmgTableInit(void) {
  _SmgTableInit(Instance);
}

// 0x1d39d0
bool _Find(Smg *this, s32 type, char *name) {
  System_Collections_Generic_Dictionary_string__Smg__MidiWork__o *Table;
  System_Collections_Generic_Dictionary_object__object__o *v10;
  Il2CppObject *Item;

  if (op_Equality(FindOut->Key_DefineName, name, 0))
    goto LABEL_7;
  if (!name)
  {
    LOBYTE(Table) = 0;
    return Table;
  }
  Table = _GetTable(this, type, name);
  if (Table)
  {
    v10 = Table;
    if (Animator___ContainsKey(Table, name))
    {
      Item = object___get_Item(v10, name);
      MidiWork___Set(
        FindOut,
        Item[1].klass,
        Item[1].monitor,
        Item[2].klass,
        BYTE4(Item[2].klass),
        Item[2].monitor,
        Item[3].klass,
        0);
LABEL_7:
      LOBYTE(Table) = 1;
      return Table;
    }
    FindOut->DefineName = "";
    LOBYTE(Table) = 0;
  }
  return Table;
}

// 0x1d3be0
bool _Find_1915872(Smg *this, s32 type, s32 id) {
  _BOOL8 v8;
  System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o *Values;
  s64 v11;
  System_Collections_Generic_Dictionary_ValueCollection_Enumerator_TKey__TValue__o v16;

  memset(&v16, 0, sizeof(v16));
  if (FindOut->Key_MidiId == id)
  {
    return &xmmword_0 + 1;
  }
  else
  {
    if (type <= 7)
      __asm { BR              X10 }
    Values = Type___get_Values(this->_tableBgm);
    Type___GetEnumerator(&v16, Values);
    while ((sub_4D4B20(&v16) & 1) != 0)
    {
      v11 = sub_4D4CB0(&v16);
      if (*(v11 + 48) == id)
      {
        MidiWork___Set(
          FindOut,
          *(v11 + 16),
          *(v11 + 24),
          *(v11 + 32),
          *(v11 + 36),
          *(v11 + 40),
          id,
          0);
        nullsub_48(&v16);
        LOBYTE(v8) = 1;
        return v8;
      }
    }
    nullsub_48(&v16);
    LOBYTE(v8) = 0;
    FindOut->DefineName = "";
  }
  return v8;
}

// 0x1d3380
void *_GetTable(Smg *this, s32 type, char *name) {
  if (type <= 7)
    __asm { BR              X10 }
  return this->_tableBgm;
}

// 0x1d34e0
void *_GetTable_1914080(Smg *this, s32 type, s32 id) {
  if (type > 7)
    return this->_tableBgm;
  else
    return ((&loc_1D3504 + 4 * byte_32C305D[type]))(this, type, id);
}

// 0x1d4310
void _SmgTableInit(Smg *this) {
}

// 0x1d35d0
void _TblAdd(Smg *this, s32 type, char *name, s32 id) {
  System_Collections_Generic_Dictionary_string__Smg__MidiWork__o *Table;
  u64 *v10;

  Table = _GetTable(this, type, name, *&id);
  v10 = Allocate(Smg__MidiWork);
  MidiWork___ctor(v10, name, name, id, 0);
  PropertySheet___Add(Table, name, v10);
}

// 0x1d3690
void _TblAdd_1914512(Smg *this, s32 type, char *name, char *fname, s32 id, bool loop) {
  System_Collections_Generic_Dictionary_string__Smg__MidiWork__o *Table;
  u64 *v14;

  Table = _GetTable(this, type, name, fname);
  v14 = Allocate(Smg__MidiWork);
  MidiWork___ctor(v14, name, fname, id, loop);
  PropertySheet___Add(Table, name, v14);
}

// 0x1d3760
void _TblAdd_L_(Smg *this, s32 type, char *name, s32 id) {
  System_String_o *v10;
  System_Collections_Generic_Dictionary_string__Smg__MidiWork__o *Table;
  u64 *v12;

  v10 = Concat_5224608(name, "_L_");
  Table = _GetTable(this, type, name);
  v12 = Allocate(Smg__MidiWork);
  MidiWork___ctor(v12, name, v10, id, 1);
  PropertySheet___Add(Table, name, v12);
}

// 0x1d3860
void _TblCpy(Smg *this, s32 type, char *key_name, s32 key_id, char *name) {
  System_Collections_Generic_Dictionary_object__object__o *Table;
  Il2CppObject *Item;
  System_String_o *klass;
  System_String_o *monitor;
  s32 v15;
  char v16;
  u64 *v17;

  Table = _GetTable(this, type, name, *&key_id);
  Item = object___get_Item(Table, name);
  klass = Item[1].klass;
  monitor = Item[1].monitor;
  v15 = Item[2].klass;
  v16 = BYTE4(Item[2].klass);
  v17 = Allocate(Smg__MidiWork);
  MidiWork___ctor_20115936(v17, klass, monitor, v15, v16, key_name, key_id);
  PropertySheet___Add(Table, key_name, v17);
}
