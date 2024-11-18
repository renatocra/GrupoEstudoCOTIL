#ifndef STACKLIG_H
#define STACKLIG_H

typedef struct _NoStack TNoStack;
typedef struct _StackLig TStackLig;

TStackLig *sl_create();
void sl_destroy(TStackLig **ref);
int sl_isEmpty(const TStackLig *stk);
float sl_pop(TStackLig *stk, int *underFlow);
void sl_push(TStackLig *stk, float valor);
float sl_peek(const TStackLig *stk, int *underFlow);
void sl_print(const TStackLig *stk);

#endif