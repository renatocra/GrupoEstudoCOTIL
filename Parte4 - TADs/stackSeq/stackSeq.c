#include "stackSeq.h"
#include <malloc.h>
#include <stdio.h>

typedef struct _StackSeq {
    int top;
    int *item;
} TStackSeq;

TStackSeq *ss_create(int maxLen) {
    TStackSeq *stk = (TStackSeq *) calloc(1, sizeof(TStackSeq));
    stk->top = -1;
    stk->item = (int *) calloc(maxLen, sizeof(int));
    return stk;
}

void ss_destroy(TStackSeq **ref) {
    TStackSeq *itm = *ref;
    free(itm->item);
    free(itm);
    *ref = NULL;
}

int ss_isEmpty(const TStackSeq *stk)
{
    return ((stk->top == -1) ? 1 : 0);
}

int ss_pop(TStackSeq *stk, int *underFlow) {
    int ret;

    if (ss_isEmpty(stk)) {
        *underFlow = 1;
        ret = -1;
    } else {
        *underFlow = 0;
        ret = stk->item[stk->top--];
    }
    return ret;
}

void ss_push(TStackSeq *stk, int valor, int *overFlow) {
    if (stk->top == sizeof(stk->item))
        *overFlow = 1;
    else {
        *overFlow = 0;
        stk->item[++stk->top] = valor;
    }
}

int ss_top(const TStackSeq *stk, int *underFlow) {
    int ret;

    if (ss_isEmpty(stk)) {
        *underFlow = 1;
        ret = -1;
    } else {
        *underFlow = 0;
        ret = stk->item[stk->top];
    }
    return ret;
}

void ss_print(const TStackSeq *stk) {
    for (int i = 0; i < stk->top; i++)
        printf("%d\n", stk->item[i]);
}