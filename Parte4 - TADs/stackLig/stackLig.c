#include "stackLig.h"
#include <malloc.h>
#include <stdio.h>

typedef struct _StackLig {
    int top;
    int *item;
} TStackLig;

TStackLig *sl_create(int maxLen) {
    TStackLig *stk = (TStackLig *) calloc(1, sizeof(TStackLig));
    stk->top = -1;
    stk->item = (int *) calloc(maxLen, sizeof(int));
    return stk;
}

void sl_destroy(TStackLig **ref) {
    TStackLig *itm = *ref;
    free(itm->item);
    free(itm);
    *ref = NULL;
}

int sl_isEmpty(const TStackLig *stk)
{
    return ((stk->top == -1) ? 1 : 0);
}

int sl_pop(TStackLig *stk, int *underFlow) {
    int ret;

    if (sl_isEmpty(stk)) {
        *underFlow = 1;
        ret = -1;
    } else {
        *underFlow = 0;
        ret = stk->item[stk->top--];
    }
    return ret;
}

void sl_push(TStackLig *stk, int valor, int *overFlow) {
    if (stk->top == sizeof(stk->item))
        *overFlow = 1;
    else {
        *overFlow = 0;
        stk->item[++stk->top] = valor;
    }
}

int sl_top(const TStackLig *stk, int *underFlow) {
    int ret;

    if (sl_isEmpty(stk)) {
        *underFlow = 1;
        ret = -1;
    } else {
        *underFlow = 0;
        ret = stk->item[stk->top];
    }
    return ret;
}

void sl_print(const TStackLig *stk) {
    for (int i = 0; i < stk->top; i++)
        printf("%d\n", stk->item[i]);
}