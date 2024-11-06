/*
    Defina um tipo registro com os campos id, nome e idade. Faça um programa que permita ao usuário
    cadastrar um registro deste tipo, alocado dinamicamente na memória, e que depois exiba os dados
    cadastrados na tela.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[40];
    int idade;
} tAluno;


int main() {
    tAluno *pAluno;

    pAluno = (tAluno *) malloc(sizeof(tAluno)); //49 bytes

    system("chcp 65001");

    puts("\n\n");
    printf("Id........: ");
    scanf("%i", &pAluno->id);
    getchar();
    printf("Nome......: ");
    gets(pAluno->nome);
    printf("Idade.....: ");
    scanf("%i", &pAluno->idade);

    puts("\n\nDados cadastrados:\n");
    printf("Id........: %i\n", pAluno->id);
    printf("Nome......: %s\n", pAluno->nome);
    printf("Idade.....: %i\n", pAluno->idade);

    free(pAluno);
    pAluno = NULL;

    puts("\n");
    system("pause");
}