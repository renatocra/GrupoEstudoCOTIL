/*
    Ponteiro para função
*/

#include <stdio.h>
#include <stdlib.h>

void exibeValor(int val) {
    printf("\nValor: %i\n", val);
}

int main() {

    system("chcp 65001");

    void (*pFunc)(int);

    pFunc = exibeValor;

    //Responda Qual o tamanho de Registro?
    printf("\n\n");
    printf("End. de main      : %x\n", &main);
    printf("End. de exibeValor: %x\n", &exibeValor);
    printf("End. de pFunc     : %x\n", &pFunc);
    printf("Apontado por pFunc: %x\n", pFunc);
    printf("\n");
    printf("\nChamando a função por ponteiro");
    pFunc(100);

    system("pause");
}