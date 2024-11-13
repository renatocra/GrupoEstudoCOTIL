#include ".\stackSeq\stackSeq.h"
#include <stdio.h>

int main() {
    int erro;

    TStackSeq *pilha = ss_create(10);

    ss_push(pilha, 10, &erro);    
    ss_push(pilha, 20, &erro);    
    ss_push(pilha, 30, &erro);
    printf("%d\n", ss_pop(pilha, &erro));    
    printf("%d\n", ss_pop(pilha, &erro));    
    printf("%d\n", ss_pop(pilha, &erro));    

    ss_destroy(&pilha);

    return 0;
}