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
  Log(StringLiteral_8936, 0);
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
    MidiWork___Set(0, 0, 0, 0, 0, 0, 0);
    return 0;
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
      LOBYTE(Table) = 1;
      return Table;
    }
    FindOut->DefineName = StringLiteral_416;
    LOBYTE(Table) = 0;
  }
  return Table;
}

// 0x1d3be0
bool _Find_1915872(Smg *this, s32 type, s32 id) {
    MidiWork___Set(0, 0, 0, 0, 0, 0, 0);
    return 0;
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

  v10 = Concat_5224608(name, StringLiteral_4906);
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
