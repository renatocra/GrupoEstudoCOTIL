/*
    Ponteiro para vetor
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int vInt[3] = {10, 20, 30};
    char vUFs[2][2] = {{'S', 'P'}, {'S', 'C'}};

    system("chcp 65001");

    //Executar linha a linha e ir mostrando as saídas
    printf("\n\nPARTE 1 - Vetores pelo identificador");
    printf("\nEndereco de vInt       : %x", vInt);
    printf("\nEndereco de vInt[0]    : %x", &vInt[0]);
    printf("\nEndereco de vInt[1]    : %x", &vInt[1]);
    printf("\nEndereco de vInt[2]    : %x", &vInt[2]);
    printf("\nTamanho de vInt        : %d", sizeof(vInt));
    printf("\nTamanho de vInt[0]     : %d", sizeof(vInt[0]));
    printf("\nValor de vInt[0]       : %i", vInt[0]);
    printf("\nValor de vInt[1]       : %i", vInt[1]);
    printf("\nValor de vInt[2]       : %i", vInt[2]);
    printf("\n");

    printf("\nEndereco de vUFs      : %x", vUFs);
    printf("\nEndereco de vUFs(0,0) : %x", &vUFs[0][0]);
    printf("\nEndereco de vUFs(0,1) : %x", &vUFs[0][1]);
    printf("\nEndereco de vUFs(1,0) : %x", &vUFs[1][0]);
    printf("\nEndereco de vUFs(1,1) : %x", &vUFs[1][1]);
    printf("\nTamanho de vUFs       : %d", sizeof(vUFs));
    printf("\nTamanho de vUFs[0]    : %d", sizeof(vUFs[0]));
    printf("\nTamanho de vUFs(0,0)  : %d", sizeof(vUFs[0][0]));
    printf("\nValor de vUFs(0,0)    : %c", vUFs[0][0]);
    printf("\nValor de vUFs(0,1)    : %c", vUFs[0][1]);
    printf("\nValor de vUFs(1,0)    : %c", vUFs[1][0]);
    printf("\nValor de vUFs(1,1)    : %c", vUFs[1][1]);

    printf("\n\n");
    
    system("pause");

    int *pInt = vInt; //&vInt[0]
    char *pChar = vUFs[0];

    printf("\nEndereco de pInt       : %x", &pInt);
    printf("\nEndereco de pChar      : %x", &pChar);
    printf("\nApontado por pInt      : %x", pInt);
    printf("\nApontado por pChar     : %x", pChar);
    printf("\nValor apt. por pInt    : %i", *pInt);
    printf("\nValor apt. por pChar   : %c", *pChar);
    printf("\n");

    pInt++;
    printf("\nApos avanco do ponteiro int................");
    printf("\nApontado por pInt      : %x", pInt);
    printf("\nValor apt. por pInt    : %i", *pInt);
    printf("\n");

    pInt++;
    printf("\nApos avanco do ponteiro int para a última posição................");
    printf("\nApontado por pInt      : %x", pInt);
    printf("\nValor apt. por pInt    : %i", *pInt);
    printf("\n");

    pInt++;
    printf("\nApos avanco do ponteiro int após a última posição................");
    printf("\nApontado por pInt      : %x", pInt);
    printf("\nValor apt. por pInt    : %i", *pInt);
    printf("\n");

    system("pause");


    printf("\nPARTE 3 - Array char por ponteiro");
    printf("\nEndereco de pChar      : %x", &pChar);
    printf("\nApontado por pChar     : %x", pChar);
    printf("\n");

    pChar = vUFs[0];

    printf("\nApos atribuicao do ponteiro................");
    printf("\nApontado por pChar     : %x", pChar);
    printf("\nValor apt. por pChar   : %c", *pChar);
    printf("\n");

    pChar++;
    printf("\nApos avanco do ponteiro................");
    printf("\nApontado por pChar     : %x", pChar);
    printf("\nValor apt. por pChar   : %c", *pChar);
    printf("\n");

    pChar++;
    printf("\nApos segundo avanco do ponteiro................");
    printf("\nApontado por pChar     : %x", pChar);
    printf("\nValor apt. por pChar   : %c", *pChar);
    printf("\n");

    pChar++;
    printf("\nApos terceiro avanco do ponteiro................");
    printf("\nApontado por pChar     : %x", pChar);
    printf("\nValor apt. por pChar   : %c", *pChar);
    printf("\n");

    system("pause");
}
