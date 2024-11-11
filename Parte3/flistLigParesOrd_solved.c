/**
* Lista de pares ordenados (gráfico de uma planilha).​
*   Implemente lista de valores reais​
*   Esses valores serão pares ordenados, ou seja, dois valores​
*   Através de uma lista linear duplamente ligada​
*   Desenvolver em equipe de forma colaborativa​
*   Renato irá definir a estrutura e o programa base​
*   A lista deverá permitir as operações abaixo:​
*       1. Consultar dados do descritor​
*       2. Exibir a lista (2 sentidos)​
*       3. Inserir no final​
*       4. Inserir início (2 formas)​
*       5. Recuperar elemento​
*       6. Remover do início​
*       7. Remover do final​
*       8. Pesquisar um elemento​
*       9. Ordenar a lista​
*       10. Inserir em uma posição solicitada​
*       11. Remover de uma posição solicitada​
*       12. Limpar lista​
*       13. Gerar uma lista com dados teste​
*       14. Traçar o gráfico da função*​
**/

#define DEBUG
//#undef DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Nó
typedef struct _NoParOrd {
    float x;
    float y;
    struct _NoParOrd *next;
    struct _NoParOrd *prior;
} TNoParOrd;

typedef struct _ListaLigada {
    TNoParOrd *inicio;
    TNoParOrd *fim;
    int tamanho;
} TListaLigada;

#pragma region interface
void showExibirMenu() {
    puts("\nLISTA DE PARES ORDENADOS - EXBIR LISTA/GRAFICO");
    puts("\t[1] Exibe do início ao fim");
    puts("\t[2] Exibe do fim ao início");
    puts("\t[3] Exibe gráfico da função");
    puts("\t[0] Voltar ao menu principal");
    printf("\nOpção: ");
}

void showInserirMenu() {
    puts("\nLISTA DE PARES ORDENADOS - INSERIR NA LISTA");
    puts("\t[1] Inserir no final da lista");
    puts("\t[2] Inserir no início");
    puts("\t[3] Inserir na posição indicada pelo índice informado");
    puts("\t[0] Voltar ao menu principal");
    printf("\nOpção: ");
}

void showRemoverMenu() {
    puts("\nLISTA DE PARES ORDENADOS - REMOVER DA LISTA");
    puts("\t[1] Remover do final da lista");
    puts("\t[2] Remover do início");
    puts("\t[3] Remover da posição indicada pelo índice informado");
    puts("\t[0] Voltar ao menu principal");
    printf("\nOpção: ");
}

void showOrdenarMenu() {
    puts("\nLISTA DE PARES ORDENADOS - ORDENAR LISTA");
    puts("\t[1] Ordem crescente");
    puts("\t[2] Ordem decrescente");
    puts("\t[0] Voltar ao menu principal");
    printf("\nOpção: ");
}

void showMainMenu() {
    puts("\nLISTA DE PARES ORDENADOS");
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
                        case '3' : comando += 3; break; //Exibe o gráfico da função
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
void showTamanho(const TListaLigada *lista) {
    system("cls");
    puts("\nTAMANHO DA LISTA");

    printf("\tTamanho da lista: %d elementos.\n", lista->tamanho);
    system("pause");
}

//21 Exibir lista do início para o fim
void showListForwards(const TListaLigada *lista) {
    TNoParOrd *aux;
    int i = 0;

    system("cls");
    puts("\nEXIBE LISTA DO INÍCIO PARA O FIM");
    
    aux = lista->inicio;
    if (!lista->tamanho) {
        printf("\tLista vazia!\n");
    } else {
        while (aux) {
            printf("\tPonto %2d -> %5.2f;%5.2f\n", i++, aux->x, aux->y);
            aux = aux->next;
        }
    }

    system("pause");
}

//22 Exibir lista do fim para o início
void showListRewind(const TListaLigada *lista) {
    TNoParOrd *aux;
    int i = 0;

    system("cls");
    puts("\nEXIBE LISTA DO INÍCIO PARA O FIM");
    
    aux = lista->fim;
    if (!lista->tamanho) {
        printf("\tLista vazia!\n");
    } else {
        while (aux) {
            printf("\tPonto %2d -> %5.2f;%5.2f\n", i++, aux->x, aux->y);
            aux = aux->prior;
        }
    }

    system("pause");
}

//23 Exibir gráfico da função
void showFuncGraph(const TListaLigada *lista) {
    TNoParOrd *aux;
    int i = 0;

    system("cls");

    aux = lista->inicio;
    if (!lista->tamanho) {
        printf("\tLista vazia!\n");
    } else {
        while (aux) {
            printf("%5.2f;%5.2f\n", aux->x, aux->y);
            aux = aux->next;
        }
    }

    system("pause");
}

//30 Pesquisar valor
void pesquisaValor(const TListaLigada *lista) {
    float xVal;
    int achou = 0;
    int i = 0;
    TNoParOrd *aux;

    system("cls");
    puts("\nPESQUISA PAR ORDENADO PELO VALOR DE X");
    if (!lista->tamanho) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe o \"X\" procurado: ");
        scanf("%f", &xVal);
        aux = lista->inicio;
        while (aux) {
            if (aux->x == xVal) {
                achou = 1;
                printf("\tPar ordenado referente a X = %5.2f localizado na posição %d. f(x) = %5.2f\n", xVal, i, aux->y);
                break;
            }
            aux = aux->next;
            i++;
        }
    }

    if (!achou)
        puts("Nenhuma ocorrência do valor foi encontrada na lista!");

    system("Pause");
}

//40 Recuperar elemento pelo índice
void getElementoByIndice(const TListaLigada *lista) {
    int indice = 0, invalidIdx = 0;
    TNoParOrd *aux;

    system("cls");
    puts("\nRETORNA DADOS DO ELEMENTO PELO ÍNDICE");
    if (!lista->tamanho) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe a posição que deseja recuperar: ");
        scanf("%d", &indice);

        aux = lista->inicio;
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
            puts("\nPar ordenado");
            printf("X: %5.2f\n", aux->x);
            printf("Y: %5.2f\n\n", aux->y);
        }
    }
    system("pause");
}

//50 Edita elemento pelo índice
void editElementoByIndice(TListaLigada *lista) {
    int indice = 0, invalidIdx = 0;
    TNoParOrd *aux, newVal, oldVal;

    system("cls");
    puts("\nEDITA VALOR DO ELEMENTO PELO ÍNDICE");
    if (!lista) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe a posição que deseja recuperar: ");
        scanf("%d", &indice);

        aux = lista->inicio;
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
            oldVal.x = aux->x;
            oldVal.y = aux->y;
            printf("Valor atual da posição %d é %5.2f;%5.2f.\n", indice, oldVal.x, oldVal.y);
            printf("Informe o novo valor de X: ");
            scanf("%f", &newVal.x);
            printf("Informe o novo valor de Y: ");
            scanf("%f", &newVal.y);
            printf("\nO valor da posição %d foi alterado de %5.2f;%5.2f para %5.2f;%5.2f\n", indice, oldVal.x, oldVal.y, newVal.x, newVal.y);
            aux->x = newVal.x;
            aux->y = newVal.y;
        }
    }
    system("Pause");
}

//Inserir no final da lista
void insereElementoFim(TListaLigada *lista) {
    TNoParOrd *novo, *ins;

    system("cls");
    puts("\nINSERE UM NOVO CONVIDADO NA LISTA");
    novo = (TNoParOrd *) calloc(1, sizeof(TNoParOrd));
    printf("\tValor de X: ");
    scanf("%f", &novo->x);
    printf("\tValor de Y: ");
    scanf("%f", &novo->y);
    novo->next = novo->prior = NULL;

    ins = lista->inicio;
    if (lista->tamanho == 0) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->next = novo;
        novo->prior = lista->fim;
        lista->fim = novo;
    }
    lista->tamanho++;
}

//Inserir no início
void insereElementoInicio(TListaLigada *lista) {
    TNoParOrd *novo, *ins;

    system("cls");
    puts("\nINSERE UM NOVO CONVIDADO NA LISTA");
    novo = (TNoParOrd *) calloc(1, sizeof(TNoParOrd));
    printf("\tValor de X: ");
    scanf("%f", &novo->x);
    printf("\tValor de Y: ");
    scanf("%f", &novo->y);
    novo->next = novo->prior = NULL;

    ins = lista->inicio;
    if (lista->tamanho == 0) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->next = lista->inicio;
        lista->inicio->prior = novo;
        lista->inicio = novo;
    }
    lista->tamanho++;
}

//Inserir na posição indicada pelo índice informado
void insereElementoMiddle(TListaLigada *lista) {
    TNoParOrd *novo, *ins;
    int indice = 0, invalidIdx = 0;

    system("cls");
    puts("\nINSERE UM NOVO CONVIDADO NA LISTA");
    printf("Informe a posição em que deseja inserir: ");
    scanf("%d", &indice);

    ins = lista->inicio;
    if (!ins) { //lista vazia
        invalidIdx = 1;
    } else {
        for (int i = 0; i < indice; i++) {
            ins = ins->next;
            if (!ins) {
                invalidIdx = 1;
                break;
            }
        }
    }

    if (invalidIdx) {
        printf("\nA lista não possui a posição informada!\n");
        system("pause");
    } else {
        novo = (TNoParOrd *) calloc(1, sizeof(TNoParOrd));
        printf("\tValor de X: ");
        scanf("%f", &novo->x);
        printf("\tValor de Y: ");
        scanf("%f", &novo->y);
        novo->next = novo->prior = NULL;

        if (ins == lista->inicio) {  //head
            novo->next = lista->inicio;
            lista->inicio->prior = novo;
            lista->inicio = novo;
        } else {  //body
            novo->next = ins;
            novo->prior = ins->prior;
            ins->prior->next = novo;
            ins->prior = novo;
        }
        lista->tamanho++;
    }
}

//Remover do final da lista
void removeElementoFim(TListaLigada *lista) {
    TNoParOrd *del, old;

    system("cls");
    puts("\nREMOVE UM ELEMENTO DO FIM DA LISTA");
    if (!lista) {
        printf("\tLista vazia! Não é possível remover elementos.\n");
    } else {
        del = lista->fim;
        if (lista->tamanho == 1) {
            lista->inicio = lista->fim = NULL;
        } else {
            del->prior->next = NULL;
            lista->fim = del->prior;
        }
        old.x = del->x;
        old.y = del->y;
        free(del);
        printf("\nPar %5.2f;%5.2f removido da lista.\n", old.x, old.y);
        lista->tamanho--;
    }
    system("pause");
}

//Remover do início
void removeElementoInicio(TListaLigada *lista) {
    TNoParOrd *del, old;

    system("cls");
    puts("\nREMOVE UM ELEMENTO DO INÍCIO DA LISTA");
    if (!lista) {
        printf("\tLista vazia! Não é possível remover elementos.\n");
    } else {
        del = lista->fim;
        if (lista->tamanho == 1) {
            lista->inicio = lista->fim = NULL;
        } else {
            del->prior->next = NULL;
            lista->fim = del->prior;
        }
        old.x = del->x;
        old.y = del->y;
        free(del);
        printf("\nPar %5.2f;%5.2f removido da lista.\n", old.x, old.y);
        lista->tamanho--;
    }
    system("pause");
}

//Remover da posição indicada pelo índice informado
void removeElementoMiddle(TListaLigada *lista) {
    // char old[MAX_LEN_NOME];
    // TNoNome *del, *ant;
    // int indice, invalidIdx = 0;

    // system("cls");
    // puts("\nREMOVE UM CONVIDADO DE UMA POSIÇÃO ESPECÍFICA DA LISTA");
    // printf("Informe a posição: ");
    // scanf("%d", &indice);

    // del = ant = lista->inicio;
    // if (!lista->tamanho) { //lista vazia
    //     invalidIdx = 1;
    // } else {
    //     for (int i = 0; i < indice; i++) {
    //         ant = del;
    //         del = del->next;
    //         if (!del) {
    //             invalidIdx = 1;
    //             break;
    //         }
    //     }
    // }

    // if (invalidIdx) {
    //     printf("\nA lista não possui a posição informada!\n");
    // } else {
    //     if (lista->inicio == del)
    //         if (lista->inicio == lista->fim)  //lista unitária
    //             lista->inicio = lista->fim = NULL;
    //         else
    //             lista->inicio = del->next;   //remoção na cabeça
    //     else
    //         ant->next = del->next;

    //     strcpy(old, del->nome);
    //     free(del);
    //     lista->tamanho--;
    //     printf("\nConvidado %s removido da lista.\n", old);
    // }
    system("pause");
}

//Ordem crescente
void ordenaListAsc(const TListaLigada *lista) {
    // TNoNome *pos;
    // int contConf = 0;

    // system("cls");
    // puts("\nRESUMO DA LISTA DE CONVIDADOS");

    // if (!lista->tamanho) {
    //     printf("\tLista vazia!\n");
    // } else {
    //     pos = lista->inicio;
    //     while (pos) {
    //         if (pos->status)
    //             contConf++;
    //         pos = pos->next;
    //     }

    //     printf("Convidado..: %d\n", lista->tamanho);
    //     printf("Confirmados: %d\n", contConf);
    //     printf("Pendentes..: %d\n\n", lista->tamanho - contConf);
    // }

    system("pause");
}

//Ordem decrescente
void ordenaListDesc(const TListaLigada *lista) {
    // TNoNome *pos;
    // int contConf = 0;

    // system("cls");
    // puts("\nRESUMO DA LISTA DE CONVIDADOS");

    // if (!lista->tamanho) {
    //     printf("\tLista vazia!\n");
    // } else {
    //     pos = lista->inicio;
    //     while (pos) {
    //         if (pos->status)
    //             contConf++;
    //         pos = pos->next;
    //     }

    //     printf("Convidado..: %d\n", lista->tamanho);
    //     printf("Confirmados: %d\n", contConf);
    //     printf("Pendentes..: %d\n\n", lista->tamanho - contConf);
    // }

    system("pause");
}

//Limpar lista
void limpaLista(TListaLigada *lista) {
    // char confirma = 'N';
    // TNoNome *del;

    // printf("\nPara confirmar a limpeza da lista digite Y ou qualquer outra tecla para cancelar: ");
    // scanf(" %c", &confirma);

    // if (confirma == 'Y') {
    //     while (lista->inicio) {
    //         del = lista->inicio;
    //         lista->inicio = lista->inicio->next;
    //         free(del);
    //     }
    //     puts("\nLista excluída.");
    // } else {
    //     puts("\nLimpeza cancelada.");
    // }
    system("pause");
}

//Popular dados teste
void popularDadosTeste(TListaLigada *lista) {
    TNoParOrd *novo = (TNoParOrd *) calloc(1, sizeof(TNoParOrd));
    novo->x = 0;
    novo->y = 2 * 0 + 3;
    novo->prior = novo->next = NULL;
    lista->inicio = novo;
    lista->fim = novo;
    lista->tamanho++;

    for (int i = 1; i < 15; i++) {
        novo = (TNoParOrd *) calloc(1, sizeof(TNoParOrd));
        novo->x = i;
        novo->y = 2 * i + 3;
        novo->prior = lista->fim;
        novo->next = NULL;
        lista->fim->next = novo;
        lista->fim = novo;
        lista->tamanho++;
    }
}
#pragma endregion


int main(int argc, char **argv) {
    int command;
    TListaLigada *listaPares;

    listaPares = (TListaLigada *) calloc(1, sizeof(TListaLigada));
    listaPares->inicio = NULL;
    listaPares->fim = NULL;
    listaPares->tamanho = 0;
    
    system("chcp 65001");

    do {
        command = getComando();
        switch (command) {
            case 10: showTamanho(listaPares); break;  //Exibe tamanho da lista
            case 21: showListForwards(listaPares); break;  //Exibir do início ao fim
            case 22: showListRewind(listaPares); break;  //Exibir do fim ao início
            case 23: showFuncGraph(listaPares); break;  //Exibir gráfico da função
            case 30: pesquisaValor(listaPares); break;  //Pesquisar contato
            case 40: getElementoByIndice(listaPares); break;  //Recuperar elemento pelo índice
            case 50: editElementoByIndice(listaPares); break;  //Edita elemento pelo índice
            case 61: insereElementoFim(listaPares); break;  //Inserir no final da lista
            case 62: insereElementoInicio(listaPares); break;  //Inserir no início
            case 63: insereElementoMiddle(listaPares); break;  //Inserir na posição indicada pelo índice informado
            case 71: removeElementoFim(listaPares); break;  //Remover do final da lista
            case 72: removeElementoInicio(listaPares); break;  //Remover do início
            case 73: removeElementoMiddle(listaPares); break;  //Remover da posição indicada pelo índice informado
            case 81: ordenaListAsc(listaPares); break;  //Ordem crescente
            case 82: ordenaListDesc(listaPares); break;  //Ordem decrescente
            case 90: limpaLista(listaPares); break;  //Limpar lista
            #ifdef DEBUG
            case 99: popularDadosTeste(listaPares); break;  //Popular dados teste
            #endif
            case 00: break;  //Sair
        }
    } while (command);

    free(listaPares);

    return EXIT_SUCCESS;
}
