/*
    3. Fazer um programa que trate de um vetor de 20 elementos do tipo char. Ele deverá apresentar um menu que
       permitirá as seguintes operações (todas implementadas em sub-rotinas e sem o uso de variáveis globais):
       a. Carregar um vetor com caracteres gerados aleatoriamente (randômicos). Serão válidos apenas
          caracteres que representem letras maiúsculas de 'A' até 'Z'. Os caracteres podem se repetir.
       b. Exibir o conteúdo do vetor.
       c. Classificar os valores em ordem crescente. Caso o vetor esteja vazio, informar.
       d. Classificar os valores em ordem decrescente. Caso o vetor esteja vazio, informar.
       e. Pesquisar a existência de um valor no vetor. Se existe e em qual posição se encontra. Considere apenas a primeira correspondência. Caso o vetor esteja vazio, informar.
       f. Informar quantas ocorrências de um caractere informado pelo usuário existem no vetor.
       g. Informar o maior e o menor valor do vetor sem modificar sua ordenação.
       h. Embaralhar o conteúdo do vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

#define VMAX 20

enum EOrdDir {odAsc, odDesc};

void trocaChr(char *a, char *b) {
    char aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int isEmpty(const char vet[VMAX]) {
    return(vet[0] == '\0');
}



void printMenu() {
    printf("\nMANIPULAÇÃO DE ARRAY - MENU");
    printf("\n\t[1] Carregar o vetor.");
    printf("\n\t[2] Exibir vetor.");
    printf("\n\t[3] Classificar em ordem crescente.");
    printf("\n\t[4] Classificar em ordem decrescente.");
    printf("\n\t[5] Pesquisar caracter no vetor.");
    printf("\n\t[6] Contar caractere.");
    printf("\n\t[7] Maior e menor valor.");
    printf("\n\t[8] Embaralar vetor.");
    printf("\n\t[9] Sair.");
    printf("\n\nOpção: ");
}

void CarregaVetor(char vet[VMAX]) {
    srand(time(NULL));

    for (int i = 0; i < VMAX; i++) {
        vet[i] = rand() % 26 + 65;
    }
    printf("\nVetor carregado!\n");
    system("pause");        
}

void ExibeVetor(const char vet[VMAX]) {

    printf("\n\n");
    if (! isEmpty(vet)) {
        for (int i = 0; i < VMAX; i++) {
            printf("%c", vet[i]);
            if (i < VMAX - 1) printf(" - ");
        }        
    } else {
        printf("O vetor está vazio!\n");
    }
    printf("\n");
    system("pause");
}

void OrdenaVetor(char vet[VMAX], enum EOrdDir ord) {
    if (isEmpty(vet)) {
        printf("\nO vetor está vazio!\n");
        system("pause");
        return;
    }    

    for (int i = 0; i < VMAX - 1; i++) {
        for (int j = i; j < VMAX; j++) {
            if ((vet[i] > vet[j] && ord == odAsc) || (vet[i] < vet[j] && ord == odDesc))
                trocaChr(&vet[i], &vet[j]);
        }
    }
    printf("\nVetor ordenado!\n");
    system("pause");
}

void PesquisaVetor(const char vet[VMAX]) {
    char valPesq;
    int achou = 0;
    int i;

    if (isEmpty(vet)) {
        printf("\nO vetor está vazio!\n");
        system("pause");
        return;
    }    

    printf("\nInforme o caractere que quer pesquisar: ");
    do valPesq = getchar(); while (valPesq == '\n');
    valPesq = toupper(valPesq);
    for (i = 0; i < VMAX; i++) {
        achou = (valPesq == vet[i]);
        if (achou) break;
    }

    if (achou)
        printf("Caractere %c localizado na posição %i do vetor.\n", valPesq, i);
    else
        printf("Caractere %c não localizado no vetor.\n", valPesq);
    system("pause");
}

void ContaCaracter(const char vet[VMAX]) {
    char valPesq;
    int contChr;

    if (isEmpty(vet)) {
        printf("\nO vetor está vazio!\n");
        system("pause");
        return;
    }    

    printf("\nInforme o caractere que quer pesquisar: ");
    do valPesq = getchar(); while (valPesq == '\n');
    valPesq = toupper(valPesq);
    contChr = 0;
    for (int i = 0; i < VMAX; i++) {
        if (valPesq == vet[i])
            ++contChr;
    }

    if (contChr)
        printf("Foram localizadas %i ocorrências do caractere %c.\n", contChr, valPesq);
    else
        printf("Não foi encontrada nenhuma ocorrência do caractere %c.\n", valPesq);
    system("pause");
}

void MaiorMenor(const char vet[VMAX]) {
    char maior, menor;

    if (isEmpty(vet)) {
        printf("\nO vetor está vazio!\n");
        system("pause");
        return;
    }    

    maior = 0;
    menor = 127;
    for (int i = 0; i < VMAX; i++) {
        if (vet[i] > maior) maior = vet[i];
        if (vet[i] < menor) menor = vet[i];
    }
    printf("\n\nMenor caractere: %c. Maior caractere: %c.\n", menor, maior);
    system("pause");
}

void Shuffle(char vet[VMAX]) {
    int cortes, posA, posB;

    if (isEmpty(vet)) {
        printf("\nO vetor está vazio!\n");
        system("pause");
        return;
    }

    srand(time(NULL));
    cortes = rand() % 16 + 5;
    for (int i = 0; i <= cortes; i++) {
        posA = rand() % VMAX;
        posB = rand() % VMAX;
        trocaChr(&vet[posA], &vet[posB]);
    }
    printf("\nVetor embralhado!\n");
    system("pause");
}

void InicializaVetor(char vet[VMAX]) {
    for (int i = 0; i < VMAX; i++) vet[i] = '\0';
}

int main() {
    char vet[VMAX];
    char option;

    system("chcp 65001");

    InicializaVetor(vet);
    do {
        system("cls");
        printMenu();
        option = getch();
        printf("%c", option);

        switch (option) {
            case '1' : CarregaVetor(vet); break;
            case '2' : ExibeVetor(vet); break;
            case '3' : OrdenaVetor(vet, odAsc); break;
            case '4' : OrdenaVetor(vet, odDesc); break;
            case '5' : PesquisaVetor(vet); break;
            case '6' : ContaCaracter(vet); break;
            case '7' : MaiorMenor(vet); break;
            case '8' : Shuffle(vet); break;
            case '9' : printf("\n"); break;
        }
    } while (option != '9');
    system("Pause");
}