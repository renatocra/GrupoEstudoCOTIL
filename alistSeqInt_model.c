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

enum EListShowDirection {sdForwards, sdRewind};
enum EListOrderDirection {odAsc, odDesc};
enum EListPosAction {paIniShift, paIniSwap, paFim, paFirstItem, paLastItem, paMiddle};

//Descritor
typedef struct {
    int inicio;
    int final;
    int tamanho;
} TDescritor;

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
void showDescritor(TDescritor desc) {
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

//20 Exibir lista
void showList(const int *list, TDescritor desc, enum EListShowDirection dir) {
    system("cls");
    puts("\nDADOS DA LISTA");
    if (!desc.tamanho) {
        printf("\tLista vazia!\n");
    } else if (dir == sdForwards) {
        for (int i = desc.inicio; i <= desc.final; i++)
            printf("\t%d -> %d\n", i, list[i]);
    } else {
        for (int i = desc.final; i >= desc.inicio; i--)
            printf("\t%d -> %d\n", i, list[i]);
    }
    system("Pause");
}

//30 Pesquisar valor
void pesquisaValor(const int *list, TDescritor desc) {
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
            if (valor == list[i]) {
                achou = 1;
                printf("\t%d -> %d\n", i, list[i]);
            }
        }
    }

    if (!achou)
        puts("Nenhuma ocorrência do valor foi encontrada na lista!");
    system("Pause");
}

//40 Recuperar elemento pelo índice
void getElementoByIndice(const int *list, TDescritor desc) {
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
            printf("\nO valor da posição %d é: %d\n", indice, list[indice]);
        }
    }
    system("Pause");
}

//50 Edita  elemento pelo índice
void editElementoByIndice(const int *list, TDescritor desc) {
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
            oldVal = list[indice];
            printf("Valor atual da posição %d é %d. Informe o novo valor: ", indice, oldVal);
            scanf("%d", &list[indice]);
            printf("\nO valor da posição %d foi alterado de %d para %d\n", indice, oldVal, list[indice]);
        }
    }
    system("Pause");
}

//Inserir
void insereElemento(int *list, TDescritor *desc, enum EListPosAction pos) {
    int valor, indice;

    system("cls");
    puts("\nINSERE UM NOVO ELEMENTO NA LISTA");
    if (desc->tamanho == MAX_LEN) {
        printf("\tLista cheia! Não é possível inserir novo elemento.\n");
        system("pause");
    } else {
        printf("Informe o valor: ");
        scanf("%d", &valor);
        if (!desc->tamanho)
            pos = paFirstItem;        

        switch (pos) {
            case paFirstItem:
                list[desc->inicio] = valor;
                desc->final++;
                desc->tamanho++;
                break;
            case paFim:
                list[++desc->final] = valor;
                desc->tamanho++;
                break;
            case paIniSwap:
                list[++desc->final] = list[desc->inicio];
                list[desc->inicio] = valor;
                desc->tamanho++;
                break;
            case paIniShift:
                for (int i = ++desc->final; i > desc->inicio; i--)
                    list[i] = list[i - 1];
                list[desc->inicio] = valor;
                desc->tamanho++;
                break;
            case paMiddle:
                printf("Informe a posição: ");
                scanf("%d", &indice);
                if (indice < desc->inicio || indice > desc->final) {
                    printf("\nA lista não possui a posição informada!\n");
                    system("pause");
                } else {
                    for (int i = ++desc->final; i > indice; i--)
                        list[i] = list[i - 1];
                    list[indice] = valor;
                    desc->tamanho++;
                }
                break;
        }
    }
}

//Remover
void removeElemento(int *list, TDescritor *desc, enum EListPosAction pos) {
    int valor, indice;

    system("cls");
    puts("\nREMOVE UM ELEMENTO NA LISTA");
    if (!desc->tamanho) {
        printf("\tLista vazia! Não é possível remover elementos.\n");
    } else {
        switch (pos) {
            case paFim:
                valor = list[desc->final];
                desc->final--;
                desc->tamanho--;
                printf("\nValor %d removido da lista.\n", valor);
                break;
            case paIniSwap:
                valor = list[desc->inicio];
                list[desc->inicio] = list[desc->final--];
                desc->tamanho--;
                printf("\nValor %d removido da lista.\n", valor);
                break;
            case paIniShift:
                valor = list[desc->inicio];
                for (int i = desc->inicio; i < desc->final; i++)
                    list[i] = list[i + 1];
                desc->final--;
                desc->tamanho--;
                printf("\nValor %d removido da lista.\n", valor);
                break;
            case paMiddle:
                printf("Informe a posição: ");
                scanf("%d", &indice);
                if (indice < desc->inicio || indice > desc->final) {
                    printf("\nA lista não possui a posição informada!\n");
                    system("pause");
                } else {
                    valor = list[indice];
                    for (int i = indice; i < desc->final; i++)
                        list[i] = list[i + 1];
                    desc->final--;
                    desc->tamanho--;
                    printf("\nValor %d removido da lista.\n", valor);
                }
                break;
        }
        system("pause");
    }
}

//Ordenar
void ordenaList(int *list, TDescritor desc, enum EListOrderDirection dir) {
    system("cls");
    puts("\nORDENAÇÃO DA LISTA");
    if (!desc.tamanho)
        printf("\tLista vazia!\n");
    else {
        switch (dir) {
            //Bublle Sort
            case odAsc:
                for (int i = desc.inicio, trocou = 0; i < desc.final; i++) {
                    trocou = 0;
                    for (int j = 0; j < desc.final - i; j++) {
                        if (list[j] > list[j + 1]) {
                            trocaInt(&list[j], &list[j + 1]);
                            trocou = 1;
                        }
                    }
                    if (!trocou) break;
                }
                break;
            case odDesc:
                //Variação da Selection Sort
                for (int i = desc.inicio; i < desc.final; i++) {
                    for (int j = i; j <= desc.final; j++) {
                        if (list[i] < list[j])
                            trocaInt(&list[i], &list[j]);
                    }
                }
                break;
        }
        puts("Lista ordenada.");
    }
    system("Pause");
}

//Limpar lista
void limpaLista(TDescritor *desc) {
    char confirma = 'N';

    printf("\nPara confirmar a limpeza da lista digite Y ou qualquer outra tecla para cancelar: ");
    scanf(" %c", &confirma);

    if (confirma == 'Y') {
        desc->final = -1;
        desc->tamanho = 0;
        puts("\nLista excluída.");
    } else {
        puts("\nLimpeza cancelada.");
    }
    system("pause");
}

//Popular dados teste
void popularDadosTeste(int *list, TDescritor *desc) {
    srand(time(NULL));

    desc->final = -1;
    desc->tamanho = 0;
    for (int i = desc->inicio; i < MAX_LEN; i++) {
        list[i] = rand() % 11; //i + 1;
        desc->final++;
        desc->tamanho++;
    }
}
#pragma endregion


int main(int argc, char **argv) {
    int command;
    TDescritor desc;
    int *listaInt;
    
    listaInt = (int *) calloc(MAX_LEN, sizeof(int));
    desc.inicio = desc.tamanho = 0;
    desc.final = -1;

    system("chcp 65001");

    do {
        command = getComando();
        switch (command) {
            case 10: showDescritor(desc); break;  //Exibe dados do descritor
            case 21: showList(listaInt, desc, sdForwards); break;  //Exibir do início ao fim
            case 22: showList(listaInt, desc, sdRewind); break;  //Exibir do fim ao início
            case 30: pesquisaValor(listaInt, desc); break;  //Pesquisar valor
            case 40: getElementoByIndice(listaInt, desc); break;  //Recuperar elemento pelo índice
            case 50: editElementoByIndice(listaInt, desc); break;  //Edita elemento pelo índice
            case 61: insereElemento(listaInt, &desc, paFim); break;  //Inserir no final da lista
            case 62: insereElemento(listaInt, &desc, paIniSwap); break;  //Inserir no início (colocando o antigo primeiro elemento no final)
            case 63: insereElemento(listaInt, &desc, paIniShift); break;  //Inserir no início (deslocando os demais elementos para a direita)
            case 64: insereElemento(listaInt, &desc, paMiddle); break;  //Inserir na posição indicada pelo índice informado
            case 71: removeElemento(listaInt, &desc, paFim); break;  //Remover do final da lista
            case 72: removeElemento(listaInt, &desc, paIniSwap); break;  //Remover do início (colocando o antigo último elemento no início)
            case 73: removeElemento(listaInt, &desc, paIniShift); break;  //Remover do início (deslocando os demais elementos para a esquerda)
            case 74: removeElemento(listaInt, &desc, paMiddle); break;  //Remover da posição indicada pelo índice informado
            case 81: ordenaList(listaInt, desc, odAsc); break;  //Ordem crescente
            case 82: ordenaList(listaInt, desc, odDesc); break;  //Ordem decrescente
            case 90: limpaLista(&desc); break;  //Limpar lista
            #ifdef DEBUG
            case 99: popularDadosTeste(listaInt, &desc); break;  //Popular dados teste
            #endif
            case 00: break;  //Sair
        }
    } while (command);

    free(listaInt);
    listaInt = NULL;

    return 0;
}
