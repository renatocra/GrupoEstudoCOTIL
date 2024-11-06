/**
 * Lista de inteiros.
 * Implemente lista de valores inteiros
 * Através de uma lista linear sequencial com descritor
 * Desenvolver em equipe de forma colaborativa
 * Usar alocação dinâmica. Alocar no início e desalocar no fim.
 * Renato irá definir a estrutura e o programa base
 * A lista deverá permitir as operações abaixo:
 *      1. Consultar dados do descritor
 *      2. Exibir a lista (2 sentidos)
 *      3. Exibir a lista do fim ao início
 *      4. Inserir no final
 *      5. Inserir início (2 formas)
 *      6. Recuperar elemento
 *      7. Remover do início (2 formas)
 *      8. Remover do final
 *      9. Pesquisar um elemento
 *      10. Ordenar a lista
 *      11. Inserir em uma posição solicitada
 *      12. Remover de uma posição solicitada
 *      13. Limpar lista
 *      14. Gerar lista com dados teste
 */

#define DEBUG
//#undef DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define MAX_LEN 10

//Descritor
typedef struct {
    int inicio;
    int final;
    int tamanho;
} TDescritor;

/* *** Definição da lista e descritor como globais *** */
    TDescritor desc;
    int listaInt[MAX_LEN];


#pragma region interface
void showExibirMenu() {
    puts("\nLISTA DE INTEIROS - EXBIR LISTA");
    puts("\t[1] Exibe do início ao fim");
    puts("\t[2] Exibe do fim ao início");
    puts("\t[0] Voltar ao menu principal");
    printf("\nOpção: ");
}

void showInserirMenu() {
    puts("\nLISTA DE INTEIROS - INSERIR NA LISTA");
    puts("\t[1] Inserir no final da lista");
    puts("\t[2] Inserir no início (colocando o antigo primeiro elemento no final)");
    puts("\t[3] Inserir no início (deslocando os demais elementos para a direita)");
    puts("\t[4] Inserir na posição indicada pelo índice informado");
    puts("\t[0] Voltar ao menu principal");
    printf("\nOpção: ");
}

void showRemoverMenu() {
    puts("\nLISTA DE INTEIROS - REMOVER DA LISTA");
    puts("\t[1] Remover do final da lista");
    puts("\t[2] Remover do início (colocando o antigo último elemento no início)");
    puts("\t[3] Remover do início (deslocando os demais elementos para a esquerda)");
    puts("\t[4] Remover da posição indicada pelo índice informado");
    puts("\t[0] Voltar ao menu principal");
    printf("\nOpção: ");
}

void showOrdenarMenu() {
    puts("\nLISTA DE INTEIROS - ORDENAR LISTA");
    puts("\t[1] Ordem crescente");
    puts("\t[2] Ordem decrescente");
    puts("\t[0] Voltar ao menu principal");
    printf("\nOpção: ");
}

void showMainMenu() {
    puts("\nLISTA DE INTEIROS");
    puts("\t[1] Exibe dados do descritor");
    puts("\t[2] Exibir lista");
    puts("\t[3] Pesquisar valor");
    puts("\t[4] Recuperar elemento pelo índice");
    puts("\t[5] Editar valor de elemento pelo índice");
    puts("\t[6] Inserir elemento na lista");
    puts("\t[7] Remover elemento da lista");
    puts("\t[8] Ordenar elementos da lista");
    puts("\t[9] Limpar a lista");
    puts("\t[0] Sair");
    printf("\nOpção: ");
}

char getOptionMenu(char mainOrSub) {
    char option = '\0';

    system("cls");
    switch (mainOrSub) {
        case 'M' : showMainMenu(); break;
        case 'E' : showExibirMenu(); break;
        case 'I' : showInserirMenu(); break;
        case 'R' : showRemoverMenu(); break;
        case 'O' : showOrdenarMenu(); break;
    }
    option = getch();
    printf("%c", option);
}

int getComando() {
    char optionMain = '\0';
    char optionSub = '\0';
    int comando = 0;
    
    do {
        optionMain = getOptionMenu('M');
        switch (optionMain) {
            case '1' : comando = 10; break;     //Exibe dados do descritor
            case '2' :                          //Exibir lista
                comando = 20;
                do {
                    optionSub = getOptionMenu('E');
                    switch (optionSub) {
                        case '1' : comando += 1; break; //Exibe do início ao fim
                        case '2' : comando += 2; break; //Exibe do fim ao início
                        case '0' : printf("\n"); break;
                        default : optionSub = '\0';
                    }
                } while (!optionSub);
                break;
            case '3' : comando = 30; break;     //Pesquisar valor
            case '4' : comando = 40; break;     //Recuperar elemento pelo índice
            case '5' : comando = 50; break;     //Editar elemento pelo índice
            case '6' :                          //Inserir elemento na lista
                comando = 60;
                do {
                    optionSub = getOptionMenu('I');
                    switch (optionSub) {
                        case '1' : comando += 1; break; //Inserir no final da lista
                        case '2' : comando += 2; break; //Inserir no início (colocando o antigo primeiro elemento no final)
                        case '3' : comando += 3; break; //Inserir no início (deslocando os demais elementos para a direita)
                        case '4' : comando += 4; break; //Inserir na posição indicada pelo índice informado
                        case '0' : printf("\n"); break;
                        default : optionSub = '\0';
                    }
                } while (!optionSub);
                break;
            case '7' :                          //Remover elemento da lista
                comando = 70;
                do {
                    optionSub = getOptionMenu('R');
                    switch (optionSub) {
                        case '1' : comando += 1; break; //Remover do final da lista
                        case '2' : comando += 2; break; //Remover do início (colocando o antigo último elemento no início)
                        case '3' : comando += 3; break; //Remover do início (deslocando os demais elementos para a esquerda)
                        case '4' : comando += 4; break; //Remover da posição indicada pelo índice informado
                        case '0' : printf("\n"); break;
                        default : optionSub = '\0';
                    }
                } while (!optionSub);
                break;
            case '8' :                          //Ordenar elementos da lista
                comando = 80;
                do {
                    optionSub = getOptionMenu('O');
                    switch (optionSub) {
                        case '1' : comando += 1; break; //Ordem crescente
                        case '2' : comando += 2; break; //Ordem decrescente
                        case '0' : printf("\n"); break;
                        default : optionSub = '\0';
                    }
                } while (!optionSub);
                break;
            case '9' : comando = 90; break;     //Limpar lista
            case 'D' : comando = 99; break;     //Popular dados teste
            case '0' : comando = 0; printf("\n"); break; //Sair
            default : comando = -1; break;
        }
    } while (optionMain == -1);
    return comando;
}
#pragma endregion

#pragma region funcoes_auxiliares
void trocaInt(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
#pragma endregion

#pragma region operacoes_lista
//10 Exibe dados do descritor
void showDescritor() {
    system("cls");
    puts("\nDADOS DO DESCRITOR");
    if (!desc.tamanho) {
        printf("\tInício da lista : %s\n", "Lista vazia");
        printf("\tFim da lista    : %s\n", "Lista vazia");
    } else {
        printf("\tInício da lista : %d\n", desc.inicio);
        printf("\tFim da lista    : %d\n", desc.final);
    }
    printf("\tTamanho da lista: %d\n", desc.tamanho);
    system("Pause");
}

//21 Exibir lista do início para o fim
void showListForwards() {
    system("cls");
    puts("\nDADOS DA LISTA");
    if (!desc.tamanho) {
        printf("\tLista vazia!\n");
    } else {
        for (int i = desc.inicio; i <= desc.final; i++)
            printf("\t%d -> %d\n", i, listaInt[i]);
    }
    system("Pause");
}

//22 Exibir lista do fim para o início
void showListRewind() {
    system("cls");
    puts("\nDADOS DA LISTA");
    if (!desc.tamanho) {
        printf("\tLista vazia!\n");
    } else {
        for (int i = desc.final; i >= desc.inicio; i--)
            printf("\t%d -> %d\n", i, listaInt[i]);
    }
    system("Pause");
}

//30 Pesquisar valor
void pesquisaValor() {
    int valor;
    int achou = 0;

    system("cls");
    puts("\nPESQUISA VALOR NA LISTA (Todas Ocorrências)");
    if (!desc.tamanho) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe o valor: ");
        scanf("%d", &valor);
        for (int i = desc.inicio; i <= desc.final; i++) {
            if (valor == listaInt[i]) {
                achou = 1;
                printf("\t%d -> %d\n", i, listaInt[i]);
            }
        }
    }

    if (!achou)
        puts("Nenhuma ocorrência do valor foi encontrada na lista!");
    system("Pause");
}

//40 Recuperar elemento pelo índice
void getElementoByIndice() {
    int indice;

    system("cls");
    puts("\nRETORNA VALOR DO ELEMENTO PELO ÍNDICE");
    if (!desc.tamanho) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe a posição que deseja recuperar: ");
        scanf("%d", &indice);
        if (indice < desc.inicio || indice > desc.final) {
            printf("\nA lista não possui a posição informada!");
        } else {
            printf("\nO valor da posição %d é: %d\n", indice, listaInt[indice]);
        }
    }
    system("Pause");
}

//50 Edita  elemento pelo índice
void editElementoByIndice() {
    int indice, oldVal;

    system("cls");
    puts("\nEDITA VALOR DO ELEMENTO PELO ÍNDICE");
    if (!desc.tamanho) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe a posição que deseja editar: ");
        scanf("%d", &indice);
        if (indice < desc.inicio || indice > desc.final) {
            printf("\nA lista não possui a posição informada!");
        } else {
            oldVal = listaInt[indice];
            printf("Valor atual da posição %d é %d. Informe o novo valor: ", indice, oldVal);
            scanf("%d", &listaInt[indice]);
            printf("\nO valor da posição %d foi alterado de %d para %d\n", indice, oldVal, listaInt[indice]);
        }
    }
    system("Pause");
}

//Inserir no final da lista
void insereElementoFim() {
    int valor, indice;

    system("cls");
    puts("\nINSERE UM NOVO ELEMENTO NA LISTA");
    if (desc.tamanho == MAX_LEN) {
        printf("\tLista cheia! Não é possível inserir novo elemento.\n");
        system("pause");
    } else {
        printf("Informe o valor: ");
        scanf("%d", &valor);

        desc.final++;
        listaInt[desc.final] = valor;
        desc.tamanho++;
    }
}

//Inserir no início (colocando o antigo primeiro elemento no final)
void insereElementoIniSwap() {
    int valor, indice;

    system("cls");
    puts("\nINSERE UM NOVO ELEMENTO NA LISTA");
    if (desc.tamanho == MAX_LEN) {
        printf("\tLista cheia! Não é possível inserir novo elemento.\n");
        system("pause");
    } else {
        printf("Informe o valor: ");
        scanf("%d", &valor);

        desc.final++;
        listaInt[desc.final] = listaInt[desc.inicio];
        listaInt[desc.inicio] = valor;
        desc.tamanho++;
    }
}

//Inserir no início (deslocando os demais elementos para a direita)
void insereElementoIniShift() {
    int valor, indice;

    system("cls");
    puts("\nINSERE UM NOVO ELEMENTO NA LISTA");
    if (desc.tamanho == MAX_LEN) {
        printf("\tLista cheia! Não é possível inserir novo elemento.\n");
        system("pause");
    } else {
        printf("Informe o valor: ");
        scanf("%d", &valor);

        ++desc.final;
        for (int i = desc.final; i > desc.inicio; i--)
            listaInt[i] = listaInt[i - 1];
        listaInt[desc.inicio] = valor;
        desc.tamanho++;
    }
}

//Inserir na posição indicada pelo índice informado
void insereElementoMiddle() {
    int valor, indice;

    system("cls");
    puts("\nINSERE UM NOVO ELEMENTO NA LISTA");
    if (desc.tamanho == MAX_LEN) {
        printf("\tLista cheia! Não é possível inserir novo elemento.\n");
        system("pause");
    } else {
        printf("Informe o valor: ");
        scanf("%d", &valor);

        printf("Informe a posição: ");
        scanf("%d", &indice);
        if (indice < desc.inicio || indice > desc.final) {
            printf("\nA lista não possui a posição informada!\n");
            system("pause");
        } else {
            desc.final++;
            for (int i = desc.final; i > indice; i--)
                listaInt[i] = listaInt[i - 1];
            listaInt[indice] = valor;
            desc.tamanho++;
        }
    }
}

//Remover do final da lista
void removeElementoFim() {
    int valor, indice;

    system("cls");
    puts("\nREMOVE UM ELEMENTO NA LISTA");
    if (!desc.tamanho) {
        printf("\tLista vazia! Não é possível remover elementos.\n");
    } else {
        valor = listaInt[desc.final];
        desc.final--;
        desc.tamanho--;
        printf("\nValor %d removido da lista.\n", valor);
    }
    system("pause");
}

//Remover do início (colocando o antigo último elemento no início)
void removeElementoIniSwap() {
    int valor, indice;

    system("cls");
    puts("\nREMOVE UM ELEMENTO NA LISTA");
    if (!desc.tamanho) {
        printf("\tLista vazia! Não é possível remover elementos.\n");
    } else {
        valor = listaInt[desc.inicio];
        listaInt[desc.inicio] = listaInt[desc.final];
        desc.final--;
        desc.tamanho--;
        printf("\nValor %d removido da lista.\n", valor);
    }
    system("pause");
}

//Remover do início (deslocando os demais elementos para a esquerda)
void removeElementoIniShift() {
    int valor, indice;

    system("cls");
    puts("\nREMOVE UM ELEMENTO NA LISTA");
    if (!desc.tamanho) {
        printf("\tLista vazia! Não é possível remover elementos.\n");
    } else {
        valor = listaInt[desc.inicio];
        for (int i = desc.inicio; i < desc.final; i++)
            listaInt[i] = listaInt[i + 1];
        desc.final--;
        desc.tamanho--;
        printf("\nValor %d removido da lista.\n", valor);
    }
    system("pause");
}

//Remover da posição indicada pelo índice informado
void removeElementoMiddle() {
    int valor, indice;

    system("cls");
    puts("\nREMOVE UM ELEMENTO NA LISTA");
    if (!desc.tamanho) {
        printf("\tLista vazia! Não é possível remover elementos.\n");
    } else {
        printf("Informe a posição: ");
        scanf("%d", &indice);
        if (indice < desc.inicio || indice > desc.final) {
            printf("\nA lista não possui a posição informada!\n");
            system("pause");
        } else {
            valor = listaInt[indice];
            for (int i = indice; i < desc.final; i++)
                listaInt[i] = listaInt[i + 1];
            desc.final--;
            desc.tamanho--;
            printf("\nValor %d removido da lista.\n", valor);
        }
    }
    system("pause");
}

//Ordenar ascedente
void ordenaListAsc() {
    system("cls");
    puts("\nORDENAÇÃO DA LISTA");
    if (!desc.tamanho)
        printf("\tLista vazia!\n");
    else {
        //Bublle Sort
        for (int i = desc.inicio, trocou = 0; i < desc.final; i++) {
            trocou = 0;
            for (int j = 0; j < desc.final - i; j++) {
                if (listaInt[j] > listaInt[j + 1]) {
                    trocaInt(&listaInt[j], &listaInt[j + 1]);
                    trocou = 1;
                }
            }
            if (!trocou) break;
        }
        puts("Lista ordenada.");
    }
    system("Pause");
}

void ordenaListDesc() {
    system("cls");
    puts("\nORDENAÇÃO DA LISTA");
    if (!desc.tamanho)
        printf("\tLista vazia!\n");
    else {
        //Variação da Selection Sort
        for (int i = desc.inicio; i < desc.final; i++) {
            for (int j = i; j <= desc.final; j++) {
                if (listaInt[i] < listaInt[j])
                    trocaInt(&listaInt[i], &listaInt[j]);
            }
        }
        puts("Lista ordenada.");
    }
    system("Pause");
}


//Limpar lista
void limpaLista() {
    char confirma = 'N';

    printf("\nPara confirmar a limpeza da lista digite Y ou qualquer outra tecla para cancelar: ");
    scanf(" %c", &confirma);

    if (confirma == 'Y') {
        desc.final = -1;
        desc.tamanho = 0;
        puts("\nLista excluída.");
    } else {
        puts("\nLimpeza cancelada.");
    }
    system("pause");
}

//Popular dados teste
void popularDadosTeste() {
    srand(time(NULL));

    desc.final = -1;
    desc.tamanho = 0;
    for (int i = desc.inicio; i < MAX_LEN; i++) {
        listaInt[i] = rand() % 11; //i + 1;
        desc.final++;
        desc.tamanho++;
    }
}
#pragma endregion


int main(int argc, char **argv) {
    int command;
    
    desc.inicio = desc.tamanho = 0;
    desc.final = -1;

    system("chcp 65001");

    do {
        command = getComando();
        switch (command) {
            case 10: showDescritor(); break;  //Exibe dados do descritor
            case 21: showListForwards(); break;  //Exibir do início ao fim
            case 22: showListRewind(); break;  //Exibir do fim ao início
            case 30: pesquisaValor(); break;  //Pesquisar valor
            case 40: getElementoByIndice(); break;  //Recuperar elemento pelo índice
            case 50: editElementoByIndice(); break;  //Edita elemento pelo índice
            case 61: insereElementoFim(); break;  //Inserir no final da lista
            case 62: insereElementoIniSwap(); break;  //Inserir no início (colocando o antigo primeiro elemento no final)
            case 63: insereElementoIniShift(); break;  //Inserir no início (deslocando os demais elementos para a direita)
            case 64: insereElementoMiddle(); break;  //Inserir na posição indicada pelo índice informado
            case 71: removeElementoFim(); break;  //Remover do final da lista
            case 72: removeElementoIniSwap(); break;  //Remover do início (colocando o antigo último elemento no início)
            case 73: removeElementoIniShift(); break;  //Remover do início (deslocando os demais elementos para a esquerda)
            case 74: removeElementoMiddle(); break;  //Remover da posição indicada pelo índice informado
            case 81: ordenaListAsc(); break;  //Ordem crescente
            case 82: ordenaListDesc(); break;  //Ordem decrescente
            case 90: limpaLista(); break;  //Limpar lista
            #ifdef DEBUG
            case 99: popularDadosTeste(); break;  //Popular dados teste
            #endif
            case 00: break;  //Sair
        }
    } while (command);

    return 0;
}
