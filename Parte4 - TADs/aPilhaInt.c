#include ".\stackSeq\stackSeq.h"
#include <stdio.h>

int main() {
    int erro;

    TStackSeq *pilha = create(10);

    push(pilha, 10, &erro);    
    push(pilha, 20, &erro);    
    push(pilha, 30, &erro);
    printf("%d\n", pop(pilha, &erro));    
    printf("%d\n", pop(pilha, &erro));    
    printf("%d\n", pop(pilha, &erro));    

    destroy(&pilha);

    return 0;
}