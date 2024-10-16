/*
    5. Desenvolva uma função que retorne o cálculo do fatorial de um valor informado no parâmetro. Para
       resolver este problema utilize função recursiva.
*/

#include <stdio.h>
#include <stdlib.h>

int fatIterativo(int n) {
    int fat = n;

    for (int i = n - 1; i > 0; i--) {
        fat *= i;
    }

    if (n == 0)
        fat = 1;

    return(fat);
}

int fatRecursivo(int n) {
    if (n == 0 || n == 1)
        return(1);
    else
        return(n * fatRecursivo(n-1));
}

int fatRecursivo2(int n) {
    return(n == 0 || n == 1 ? 1 : n * fatRecursivo2(n-1));
}

int main() {
    system("chcp 65001");
    printf("\n %i! = %i\n", 5, fatRecursivo2(5));
    system("Pause");
}