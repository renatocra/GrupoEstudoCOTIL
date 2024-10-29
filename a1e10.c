/*
    Faça um programa que leia o nome de 2 pessoas e informe qual é o maior. A verificação do maior deverá 
    ser feita por uma função que recebe o nome como parâmetro e conta a quantidade de caracteres deste
    nome. Não pode usar nenhuma função da lib do c como o strlen().
*/
#include <stdio.h>
#include <stdlib.h>

int tamanhoNome(const char nome[]) {
    int i = 0;
    while (nome[i]) {
        i++;
    }
    return(i++);

    //Opção C na veia
    // int i = 0;
    // for (i = 0; nome[i]; i++);
    // return(i);

    //Opção C na veia 2
    // int i = 0;
    // while (nome[++i]);
    // return(i);
}

int main() {
    char nome1[50], nome2[50];

    system("chcp 65001");
    puts("\n\n");

    printf("Informe o 1º nome: ");
    gets(nome1);
    printf("Informe o 2º nome: ");
    gets(nome2);

    if (tamanhoNome(nome1) > tamanhoNome(nome2))
        printf("%s é o maior\n", nome1);
    else
        printf("%s é o maior\n", nome2);

    system("pause");
}