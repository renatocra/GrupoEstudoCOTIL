/*
    Demonstrando passagem de parâmetros
*/

#include <stdio.h>
#include <stdlib.h>

void dobroDeARef(int *a) {
    *a *= 2;
    printf("Endereço de a: %X\n", &a);
    printf("Endereço apontado por a (parâmetro formal): %X\n", a);
}

int dobroDeA(int a) {
    int valor = 0;
    valor = a * 2;
    printf("Endereço de a (parâmetro formal): %X\n", &a);
    return(valor);
}

int main() { 
    int val, dobro = 0;

    system("chcp 65001");

    printf("\nPor VALOR:");
    val = 5;

    printf("\nEndereço de val (parâmetro real): %X\n", &val);
    dobro = dobroDeA(val);

    system("pause");

    printf("\n\nPor REFERÊNCIA:\n");
    val = 8;

    printf("\nEndereço de val (parâmetro real): %X\n", &val);
    dobroDeARef(&val);

    system("pause");
}