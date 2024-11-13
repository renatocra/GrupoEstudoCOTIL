/*
    Ponteiro para tipos primitivos
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 2;
    int *j;
    j = &i;

    system("chcp 65001");

    printf("\nEndereco de i    : %x", &i);
    printf("\nValor de i       : %d", i);
    printf("\nEnd. de j        : %x", &j);
    printf("\nEnd. apont por j : %x", j);
    printf("\nValor apt por j  : %d", *j);
    printf("\nTamanho de i     : %i", sizeof(i));
    printf("\nTamanho de j     : %i", sizeof(j));
    printf("\n");

    system("pause");
}