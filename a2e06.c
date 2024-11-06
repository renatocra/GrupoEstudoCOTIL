/*
    Fazer um programa que leia 2 valores reais e apresente a média entre eles. Usar somente variáveis
    dinâmicas.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float *val, *media;

    media = (float *) malloc(4);
    val = (float *) malloc(4);

    system("chcp 65001");

    printf("\n\nValor 1: ");
    scanf("%f", val);
    *media = *val;

    printf("Valor 2: ");
    scanf("%f", val);

    *media += *val;

    free(val);
    val = NULL;

    *media /= 2;

    printf("\nMédia: %0.1f\n", *media);

    free(media);
    media = NULL;

    system("pause");
}