#include ".\stackLig\stackLig.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int erro;
    float result = 0.0f;
    //4 * (5 + 10) + 40
    //4<>     5<>     10+     *     40+
    //100

    TStackLig *pilha = sl_create();

    sl_push(pilha, 10);
    sl_push(pilha, 20);
    sl_push(pilha, 30);
    sl_push(pilha, 40);
    sl_print(pilha);
    return 0;


    printf("\n-----");    
    printf("----\n\n");
    sl_print(pilha);
    
    sl_push(pilha, 4);    
    printf("\n-----");    
    printf("----\n\n");
    sl_print(pilha);

    sl_push(pilha, 5);
    printf("\n-----");    
    printf("----\n\n");
    sl_print(pilha);

    sl_push(pilha, 10);
    printf("\n-----");    
    printf("----\n\n");
    sl_print(pilha);

    sl_push(pilha, sl_pop(pilha, &erro) + sl_pop(pilha, &erro));
    printf("\n-----");    
    printf("----\n\n");
    sl_print(pilha);

    sl_push(pilha, sl_pop(pilha, &erro) * sl_pop(pilha, &erro));
    printf("\n-----");    
    printf("----\n\n");
    sl_print(pilha);

    sl_push(pilha, 40);
    printf("\n-----");    
    printf("----\n\n");
    sl_print(pilha);

    sl_push(pilha, sl_pop(pilha, &erro) + sl_pop(pilha, &erro));
    printf("\n-----");    
    printf("----\n\n");
    sl_print(pilha);


    printf("%f\n", sl_pop(pilha, &erro));    

    sl_destroy(&pilha);

    system("pause");

    return 0;
}