typedef struct _StackSeq TStackSeq;

TStackSeq *create(int maxLen);
void destroy(TStackSeq **ref);
int isEmpty(const TStackSeq *stk);
int pop(TStackSeq *stk, int *underFlow);
void push(TStackSeq *stk, int valor, int *overFlow);
int top(const TStackSeq *stk, int *underFlow);
void print(const TStackSeq *stk);
