/*
    2. Fazer um programa que carregue um vetor de 8 elementos informados pelo usuário e que inverta a ordem
       do seu conteúdo. Apresente no final o vetor invertido. Usar apenas uma variável composta (vetor).
*/

#include <stdio.h>
#include <stdlib.h>
#define VMAX 8

int main() {
    int vet[VMAX];

    system("chcp 65001");
    for (int i = 0; i < VMAX; i++) {
        printf("Informe o %iº valor: ", i+1);
        scanf("%i", &vet[i]);
    }

    for (int i = 0; i < VMAX/2; i++) {
        int aux;

        aux = vet[i];
        vet[i] = vet[VMAX - 1 - i];
        vet[VMAX - 1 - i] = aux;
    }

    printf("\nEstado do vetor:\n");
    for (int i = 0; i < VMAX; i++) {
        printf("%i - ", vet[i]);
    }
    printf("\n");

    system("pause");
}