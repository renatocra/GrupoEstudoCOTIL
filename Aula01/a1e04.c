/*
    Demonstrando a leitura de caracteres 2
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao;
    char letra;

    system("chcp 65001");
    puts("\nBoa prática:");

    printf("Opção: ");
    scanf("%d", &opcao);
    printf("Letra: ");

    scanf(" %c", &letra); //espaço antes do %c

    printf("Opção: %i  Letra: %c\n", opcao, letra);

    puts("\nOutra opção:\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    printf("Letra: ");

    letra = getchar();
    if (letra == '\n')
        letra = getchar();

    printf("Opção: %i  Letra: %c\n", opcao, letra);

    puts("\nOutra opção:\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    printf("Letra: ");

    do {
        letra = getchar();
    } while (letra == '\n');

    printf("Opção: %i  Letra: %c\n", opcao, letra);



    puts("\nOutra opção:\n");
    char palavra[11];
    printf("Opção: ");
    scanf("%d", &opcao);
    printf("Palavra: ");

    scanf(" %s", palavra); //não lê se tiver espaço. Se for usar gets teria que limpar buffer antes

    printf("Opção: %i  Palavra: %s\n", opcao, palavra);


    puts("\nOutra opção:\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    printf("Palavra: ");

    scanf(" %[^\n]", palavra); 

    printf("Opção: %i  Palavra: %s\n", opcao, palavra);

    system("pause");
}