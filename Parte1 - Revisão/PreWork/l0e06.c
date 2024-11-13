/*
    6. Desenvolva uma função que retorne o cálculo de uma potencia de números inteiros. Ela receberá a base
       e o expoente como parâmetro. Para resolver este problema utilize função recursiva.
*/

#include <stdio.h>
#include <stdlib.h>

int potencia(int b, int e) {
    if (e == 0)
        return(1);
    else
        return(b * potencia(b, e-1));
}

int main() {
    int base, expoente;

    system("chcp 65001");
    printf("Base....: ");
    scanf("%i", &base);
    printf("Expoente: ");
    scanf("%i", &expoente);
    printf("\nPotência: %i\n", potencia(base, expoente));
    system("Pause");
}