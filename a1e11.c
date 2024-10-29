/*
    Altere o programa anterior. Agora ele não fará mais a leitura de dois nomes, ao invés disso irá comparar
    2 nomes enviados por parâmetros de linha de comando.
*/
#include <stdio.h>
#include <stdlib.h>

int tamanhoNome(const char nome[]) {
    int i = 0;
    while (nome[++i]);
    return(i);
}

void comparaNomes(const char nome1[], const char nome2[]) {
    if (tamanhoNome(nome1) > tamanhoNome(nome2))
        printf("%s eh o maior\n", nome1);
    else
        printf("%s eh o maior\n", nome2);
}

int main(int argc, char *argv[]) {
    char nome1[50], nome2[50];

    switch (argc) {
        case 3:
            comparaNomes(argv[1], argv[2]);
            break;
        case 2:
            printf("Informe o segundo nome: ");
            gets(nome2);
            comparaNomes(argv[1], nome2);
            break;
        case 1:
            printf("Informe o primeiro nome: ");
            gets(nome1);
            printf("Informe o segundo nome: ");
            gets(nome2);
            comparaNomes(nome1, nome2);
            break;
        default:
            printf("Parametros incorretos!");
    }

    return 0;
}