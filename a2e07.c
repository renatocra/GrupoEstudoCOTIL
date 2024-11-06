/*
    Fazer um programa que preencha um vetor de 5 elementos com valores de 1 a 5. Usar vetor dinâmico.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pVet;

    pVet = (int *) malloc(5 * sizeof(int)); //20 bytes

    system("chcp 65001");

    for (int i = 0; i < 5; i++)
        pVet[i] = i+1;

    puts("\n");

    for (int i = 0; i < 5; i++)
        printf("%i ", pVet[i]);

    free(pVet);
    pVet = NULL;

    puts("\n");
    system("pause");
}