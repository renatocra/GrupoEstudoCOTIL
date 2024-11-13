typedef struct _StackLig TStackLig;

TStackLig *sl_create(int maxLen);
void sl_destroy(TStackLig **ref);
int sl_isEmpty(const TStackLig *stk);
int sl_pop(TStackLig *stk, int *underFlow);
void sl_push(TStackLig *stk, int valor, int *overFlow);
int sl_top(const TStackLig *stk, int *underFlow);
void sl_print(const TStackLig *stk);
