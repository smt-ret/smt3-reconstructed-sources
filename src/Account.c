#include "types.h"

typedef struct Account Account;

struct Account {
    void userId;
    void userHandle;
};

static Account *Instance;
