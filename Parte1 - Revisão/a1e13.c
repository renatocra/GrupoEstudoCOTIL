/*
    Funções recursivas
*/

#include <stdio.h>
#include <stdlib.h>

int fatorial(int n) {}

int portencia(int b, int e) {}

int main() {
    int valor, expoente, resultado;

    system("chcp 65001");
    puts("\n");

    printf("Valor: ");
    scanf("%d", &valor);
    resultado = fatorial(valor);
    printf("%d! = %d", valor, resultado);

    // printf("Base: ");
    // scanf("%d", &valor);
    // printf("Expoente: ");
    // scanf("%d", &expoente);
    // resultado = portencia(valor, expoente);
    // printf("%d^%d = %d", valor, expoente, resultado);

    puts("\n");
    system("pause");
}