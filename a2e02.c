/*
    Ponteiro para struct
*/

#include <stdio.h>
#include <stdlib.h>

struct Registro {
    int id;
    char letra;
    char uf[2];
};

int main() {
    struct Registro reg = {1, 'X', {'S', 'P'}};
    struct Registro *pReg = NULL;

    system("chcp 65001");

    printf("\n\n");

    pReg = &reg;

    //Responda Qual o tamanho de Registro?
    printf("\nRegistro por ponteiro");
    printf("\nEndereco de reg           : %x", &reg);
    printf("\nTamanho de reg            : %d", sizeof(reg));
    printf("\nEndereco de pReg          : %x", &pReg);
    printf("\nApontado por pReg         : %x", pReg);
    printf("\nValor apt. por pReg       : %i", *pReg); 
    printf("\nValor apt. por pReg.Id    : %i", pReg->id);
    printf("\nValor apt. por pReg.letra : %c", pReg->letra);
    printf("\nValor apt. por pReg.uf[0] : %c", pReg->uf[0]);
    printf("\nValor apt. por pReg.uf[1] : %c", pReg->uf[1]);
    printf("\n");

    system("pause");
}