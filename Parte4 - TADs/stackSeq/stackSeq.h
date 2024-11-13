typedef struct _StackSeq TStackSeq;

TStackSeq *ss_create(int maxLen);
void ss_destroy(TStackSeq **ref);
int ss_isEmpty(const TStackSeq *stk);
int ss_pop(TStackSeq *stk, int *underFlow);
void ss_push(TStackSeq *stk, int valor, int *overFlow);
int ss_top(const TStackSeq *stk, int *underFlow);
void ss_print(const TStackSeq *stk);
