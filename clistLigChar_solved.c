/**
 * Lista de caracteres.
 *  Implemente lista de valores caracteres
 *  Através de uma lista linear simplesmente ligada
 *  Desenvolver em equipe de forma colaborativa
 *  Não usar descritor
 *  Renato irá definir a estrutura e o programa base
 *  A lista deverá permitir as operações abaixo:
 *      1. Consultar tamanho da lista
 *      2. Exibir a lista do início ao fim
 *      3. Exibir a lista do fim ao início
 *      4. Inserir no final
 *      5. Inserir início
 *      6. Recuperar elemento
 *      7. Remover do início
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

//Nó
typedef struct _NoChar {
    char item;
    struct _NoChar *next;
} TNoChar;

TNoChar *lista = NULL;

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
    puts("\t[2] Inserir no início");
    puts("\t[3] Inserir na posição indicada pelo índice informado");
    puts("\t[0] Voltar ao menu principal");
    printf("\nOpção: ");
}

void showRemoverMenu() {
    puts("\nLISTA DE INTEIROS - REMOVER DA LISTA");
    puts("\t[1] Remover do final da lista");
    puts("\t[2] Remover do início");
    puts("\t[3] Remover da posição indicada pelo índice informado");
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
    puts("\t[1] Exibe tamanho da lista");
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
            case '1' : comando = 10; break;     //Exibe tamanho da lista
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
                        case '2' : comando += 2; break; //Inserir no início
                        case '3' : comando += 3; break; //Inserir na posição indicada pelo índice informado
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
                        case '2' : comando += 2; break; //Remover do início
                        case '3' : comando += 3; break; //Remover da posição indicada pelo índice informado
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
#pragma endregion

#pragma region operacoes_lista
//10 Exibe tamanho da lista
void showTamanho() {
    int i = 0;
    TNoChar *aux;

    system("cls");
    puts("\nTAMANHO DA LISTA");

    aux = lista;
    while (aux) {
        i++;
        aux = aux->next;
    }

    printf("\tTamanho da lista: %d elementos.\n", i);
    system("Pause");
}

// //21 Exibir lista do início para o fim
void showListForwards() {
    TNoChar *aux;
    int i = 0;

    system("cls");
    puts("\nDADOS DA LISTA");
    
    aux = lista;
    if (!aux) {
        printf("\tLista vazia!\n");
    } else {
        while (aux) {
            printf("\t%d -> %c\n", i++, aux->item);
            aux = aux->next;
        }
    }

    system("Pause");
}

//22 Exibir lista do fim para o início
void exibeNoInvertido(TNoChar *no, int indice) {
    if (!no)
        return;
    else {
        exibeNoInvertido(no->next, indice + 1);
        printf("\t%d -> %c\n", indice, no->item);
    }
}

void showListRewind() {
    int i = 0;

    system("cls");
    puts("\nDADOS DA LISTA");
    if (!lista)
        printf("\tLista vazia!\n");
    else
        exibeNoInvertido(lista, i);
    system("Pause");
}

//30 Pesquisar valor
void pesquisaValor() {
    char valor;
    int achou = 0, i = 0;
    TNoChar *aux;

    system("cls");
    puts("\nPESQUISA VALOR NA LISTA (Todas Ocorrências)");
    if (!lista) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe o valor: ");
        scanf(" %c", &valor);
        aux = lista;
        while (aux) {
            if (valor == aux->item) {
                achou = 1;
                printf("\t%d -> %c\n", i, aux->item);
            }
            i++;
            aux = aux->next;
        }
    }

    if (!achou)
        puts("Nenhuma ocorrência do valor foi encontrada na lista!");
    system("Pause");
}

//40 Recuperar elemento pelo índice
void getElementoByIndice() {
    int indice = 0, invalidIdx = 0;
    TNoChar *aux;

    system("cls");
    puts("\nRETORNA VALOR DO ELEMENTO PELO ÍNDICE");
    if (!lista) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe a posição que deseja recuperar: ");
        scanf("%d", &indice);

        aux = lista;
        for (int i = 0; i < indice; i++) {
            aux = aux->next;
            if (!aux) {
                invalidIdx = 1;
                break;
            }
        }

        if (invalidIdx)
            printf("\nA lista não possui a posição informada!\n");
        else
            printf("\nO valor da posição %d é: %c\n", indice, aux->item);
    }
    system("pause");
}

//50 Edita  elemento pelo índice
void editElementoByIndice() {
    int indice = 0, invalidIdx = 0;
    TNoChar *aux;
    char newVal = '\0', oldVal = '\0';

    system("cls");
    puts("\nEDITA VALOR DO ELEMENTO PELO ÍNDICE");
    if (!lista) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe a posição que deseja recuperar: ");
        scanf("%d", &indice);

        aux = lista;
        for (int i = 0; i < indice; i++) {
            aux = aux->next;
            if (!aux) {
                invalidIdx = 1;
                break;
            }
        }

        if (invalidIdx)
            printf("\nA lista não possui a posição informada!\n");
        else {
            oldVal = aux->item;
            printf("Valor atual da posição %d é %c. Informe o novo valor: ", indice, oldVal);
            scanf(" %c", &newVal);
            aux->item = newVal;
            printf("\nO valor da posição %d foi alterado de %c para %c\n", indice, oldVal, aux->item);
        }
    }
    system("Pause");
}

//Inserir no final da lista
void insereElementoFim() {
    char letra;
    TNoChar *novo = NULL, *aux = NULL;

    system("cls");
    puts("\nINSERE UM NOVO ELEMENTO NO FINAL DA LISTA");
    printf("Informe o caractere: ");
    scanf(" %c", &letra);

    novo = (TNoChar *) malloc(sizeof(TNoChar));
    novo->item = letra;
    novo->next = NULL;

    if (!lista) {
        lista = novo;        
    } else {
        aux = lista;
        while (aux->next)
            aux = aux->next;
        aux->next = novo;
    }
}

//Inserir no início
void insereElementoInicio() {
    char letra;
    TNoChar *novo = NULL, *aux = NULL;

    system("cls");
    puts("\nINSERE UM NOVO ELEMENTO NA LISTA");
    printf("Informe o caractere: ");
    scanf(" %c", &letra);

    novo = (TNoChar *) malloc(sizeof(TNoChar));
    novo->item = letra;
    novo->next = lista;
    lista = novo;
}

//Inserir na posição indicada pelo índice informado
void insereElementoMiddle() {
    int indice = 0, invalidIdx = 0;
    char letra;
    TNoChar *novo = NULL, *aux = NULL, *ant = NULL;

    system("cls");
    puts("\nINSERE UM NOVO ELEMENTO NA LISTA");
    printf("Informe a posição em que deseja inserir: ");
    scanf("%d", &indice);

    aux = lista;
    if (!aux) { //lista vazia
        invalidIdx = 1;
    } else {
        for (int i = 0; i < indice; i++) {
            aux = aux->next;
            if (!aux) {
                invalidIdx = 1;
                break;
            }
        }
    }

    if (invalidIdx) {
        printf("\nA lista não possui a posição informada!\n");
        system("pause");
    } else {
        printf("Informe o caractere: ");
        scanf(" %c", &letra);

        novo = (TNoChar *) malloc(sizeof(TNoChar));
        novo->item = letra;
        novo->next = NULL;

        if (aux == lista) {  //head
            novo->next = lista;
            lista = novo;
        } else {  //body
            ant = lista;
            while (ant->next != aux) ant = ant->next;
            novo->next = aux;
            ant->next = novo;
        }
    }
}

//Remover do final da lista
void removeElementoFim() {
    char old;
    TNoChar *del, *aux;

    system("cls");
    puts("\nREMOVE UM ELEMENTO DO FIM DA LISTA");
    if (!lista) {
        printf("\tLista vazia! Não é possível remover elementos.\n");
    } else {
        del = lista;
        if (!lista->next) {
            lista = NULL;
        } else {
            while (del->next) del = del->next;
            aux = lista;
            while (aux->next->next) aux = aux->next;
            aux->next = NULL;
        }
        old = del->item;
        free(del);
        printf("\nLetra %c removido da lista.\n", old);
    }
    system("pause");
}

//Remover do início
void removeElementoInicio() {
    char old;
    TNoChar *del, *aux;

    system("cls");
    puts("\nREMOVE UM ELEMENTO DO INÍCIO DA LISTA");
    if (!lista) {
        printf("\tLista vazia! Não é possível remover elementos.\n");
    } else {
        del = lista;
        lista = del->next;
        old = del->item;
        free(del);
        printf("\nLetra %c removido da lista.\n", old);
    }
    system("pause");
}

//Remover da posição indicada pelo índice informado
void removeElementoMiddle() {
    char old;
    TNoChar *del, *ant;
    int indice, invalidIdx = 0;

    system("cls");
    puts("\nREMOVE UM ELEMENTO DE UMA POSIÇÃO ESPECÍFICA DA LISTA");
    printf("Informe a posição: ");
    scanf("%d", &indice);

    del = ant = lista;
    if (!del) { //lista vazia
        invalidIdx = 1;
    } else {
        for (int i = 0; i < indice; i++) {
            ant = del;
            del = del->next;
            if (!del) {
                invalidIdx = 1;
                break;
            }
        }
    }

    if (invalidIdx) {
        printf("\nA lista não possui a posição informada!\n");
    } else {
        if (lista == del)
            if (!del->next)  //lista unitária
                lista = NULL;
            else
                lista = del->next;   //remoção na cabeça
        else
            ant->next = del->next;

        old = del->item;
        free(del);
        printf("\nValor %c removido da lista.\n", old);
    }
    system("pause");
}

//Ordenar ascedente
void ordenaListAsc() {
    TNoChar *posI, *posJ;
    char aux;

    system("cls");
    puts("\nORDENAÇÃO DA LISTA");
    if (!lista)
        printf("\tLista vazia!\n");
    else if (lista && lista->next) { //Lista com mais de um elemento
        //Selection Sort
        posI = lista;
        while (posI->next) {
            posJ = posI->next;
            while (posJ) {
                if (posI->item > posJ->item) {
                    aux = posI->item;
                    posI->item = posJ->item;
                    posJ->item = aux;
                }
                posJ = posJ->next;    
            }
            posI = posI->next;
        }    
    }
    puts("Lista ordenada.");
    system("Pause");
}

void ordenaListDesc() {
    TNoChar *posI, *posJ;
    char aux;

    system("cls");
    puts("\nORDENAÇÃO DA LISTA");
    if (!lista)
        printf("\tLista vazia!\n");
    else if (lista && lista->next) { //Lista com mais de um elemento
        //Selection Sort
        posI = lista;
        while (posI->next) {
            posJ = posI->next;
            while (posJ) {
                if (posI->item < posJ->item) {
                    aux = posI->item;
                    posI->item = posJ->item;
                    posJ->item = aux;
                }
                posJ = posJ->next;    
            }
            posI = posI->next;
        }    
    }
    puts("Lista ordenada.");
    system("Pause");
}


//Limpar lista
void limpaLista() {
    char confirma = 'N';
    TNoChar *del;

    printf("\nPara confirmar a limpeza da lista digite Y ou qualquer outra tecla para cancelar: ");
    scanf(" %c", &confirma);

    if (confirma == 'Y') {
        while (lista) {
            del = lista;
            lista = lista->next;
            free(del);
        }
        puts("\nLista excluída.");
    } else {
        puts("\nLimpeza cancelada.");
    }
    system("pause");
}

//Popular dados teste
void popularDadosTeste() {
    TNoChar *novo;

    srand(time(NULL));

    for (int i = 0; i < 8; i++) {
        novo = (TNoChar *) calloc(1, sizeof(TNoChar));
        novo->item = rand() % 26 + 65;
        novo->next = lista;
        lista = novo;
    }
}
#pragma endregion


int main(int argc, char **argv) {
    int command;
    
    system("chcp 65001");

    do {
        command = getComando();
        switch (command) {
            case 10: showTamanho(); break;  //Exibe tamanho da lista
            case 21: showListForwards(); break;  //Exibir do início ao fim
            case 22: showListRewind(); break;  //Exibir do fim ao início
            case 30: pesquisaValor(); break;  //Pesquisar valor
            case 40: getElementoByIndice(); break;  //Recuperar elemento pelo índice
            case 50: editElementoByIndice(); break;  //Edita elemento pelo índice
            case 61: insereElementoFim(); break;  //Inserir no final da lista
            case 62: insereElementoInicio(); break;  //Inserir no início
            case 63: insereElementoMiddle(); break;  //Inserir na posição indicada pelo índice informado
            case 71: removeElementoFim(); break;  //Remover do final da lista
            case 72: removeElementoInicio(); break;  //Remover do início
            case 73: removeElementoMiddle(); break;  //Remover da posição indicada pelo índice informado
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
