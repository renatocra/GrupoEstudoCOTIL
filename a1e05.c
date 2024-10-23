/* 
    Tipo Lógico em C
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001");
    puts("\n\n");

    //Inteiro
    //Atribuir valores 1, -1, 5
    int a = 0;
    if (a) {
        printf("A é VERDADEIRO. Seu valor é: %i\n", a);
    } else {
        printf("A é FALSO. Seu valor é: %i\n", a);
    }

    system("pause");


    puts("\n\n");

    //Caractere
    //Atribuir valores A, 2, x, \n, \r, \t, \0
    char l = 'A'; 
    if (l) {
        printf("L é VERDADEIRO. Seu código é: %i\n", l);
    } else {
        printf("L é FALSO. Seu código é: %i\n", l);
    }

    system("pause");


    puts("\n\n");

    //Float
    //Atribuir valores 0.00, 0.0001, -5.69
    float n = -5.69;
    if (n) {
        printf("N é VERDADEIRO. Seu valor é: %f\n", n);
    } else {
        printf("N é FALSO. Seu valor é: %f\n", n);
    }

    system("pause");


    puts("\n\n");

    //Ponteiro
    //Atribuir valores [sem inicializar] malloc ( (int *) malloc(0x4) ), &a, NULL
    int *p = NULL;
    if (p) {
        printf("P é VERDADEIRO. Seu valor é: %x\n", p);
    } else {
        printf("P é FALSO. Seu valor é: %x\n", p);
    }

    system("pause");
}