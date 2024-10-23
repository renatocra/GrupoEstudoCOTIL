/*
    Demonstrando a leitura de caracteres 2
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao;
    char letra;

    system("chcp 65001");
    puts("\nEntendendo a leitura de char");

    //Neste exemplo a leitura do inteiro deixa um enter no buffer
    // printf("Opção: ");
    // scanf("%d", &opcao);
    // printf("Letra: ");
    // scanf("%c", &letra);
 
    //Usando o getchar ocorre o mesmo efeito pois o enter está lá
    // printf("Opção: ");
    // scanf("%d", &opcao);
    // printf("Letra: ");
    // letra = getchar();

    // printf("Opção: ");
    // scanf("%d", &opcao);
    // printf("\nApós a leitura do inteiro, no buffer do teclado encontramos o caractere: %i\n", getchar());
    // puts("Ele estava sendo lido pelo getchar, impedindo a leitura da letra\n");
    // printf("Letra: ");
    // letra = getchar();

    // puts("\n");
    // printf("%i\n%c\n", opcao, letra);
    // system("pause");

    puts("\n\nDemonstração. Digitando uma letra e Pressionando ENTER\n");
    char buffer1, buffer2;
    buffer1 = getchar();
    buffer2 = getchar();

    system("pause");
}