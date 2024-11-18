#include "stackLig.h"
#include <malloc.h>
#include <stdio.h>

typedef struct _NoStack {
    float valor;
    struct _NoStack *prior;
} TNoStack;

typedef struct _StackLig {
    TNoStack *topo;
    int tamanho;
} TStackLig;

TStackLig *sl_create() {
    TStackLig *stk = (TStackLig *) calloc(1, sizeof(TStackLig));
    stk->topo = NULL;
    stk->tamanho = 0;
    return stk;
}

void sl_destroy(TStackLig **ref) {
    TStackLig *aux = *ref;
    TNoStack *del;

    while (aux->topo) {
        del = aux->topo;
        aux->topo = aux->topo->prior;
        free(del);
    }
    aux->tamanho = 0;

    free(aux);
    *ref = NULL;
}

int sl_isEmpty(const TStackLig *stk)
{
    return ((stk->tamanho) ? 0 : 1);
}

float sl_pop(TStackLig *stk, int *underFlow) {
    float ret;
    TNoStack *del;

    if (sl_isEmpty(stk)) {
        *underFlow = 1;
        ret = -1;
    } else {
        *underFlow = 0;
        ret = stk->topo->valor;
        del = stk->topo;
        stk->topo = stk->topo->prior;
        stk->tamanho--;
        free(del);
    }
    return ret;
}

void sl_push(TStackLig *stk, float valor) {
    TNoStack *novo = (TNoStack *) calloc(1, sizeof(TNoStack));

    novo->valor = valor;
    novo->prior = stk->topo;
    stk->topo = novo;
    stk->tamanho++;
}

float sl_peek(const TStackLig *stk, int *underFlow) {
    float ret;

    if (sl_isEmpty(stk)) {
        *underFlow = 1;
        ret = -1;
    } else {
        *underFlow = 0;
        ret = stk->topo->valor;
    }
    return ret;
}

void sl_print(const TStackLig *stk) {
    TNoStack *aux;

    aux = stk->topo;
    while (stk->topo) {
        printf("%f\n", stk->topo->valor);
        aux = aux->prior;
    }
}