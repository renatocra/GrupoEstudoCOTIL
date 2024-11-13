/**
* Lista de convidados.
*   Implemente uma lista de convidados para uma festa
*   Deve conter o nome e um status informando se confirmado sim ou não
*   O campo status de ser “Falso” por padrão, na inclusão
*   Desenvolver em equipe de forma colaborativa
*   Através de uma lista linear simplesmente ligada com descritor
*   Renato irá definir a estrutura e o programa base
*   A lista deverá ter apenas as operações abaixo:
*       1. Consultar o tamanho da lista
*       2. Exibir a lista (todos e só os confirmados)
*       3. Pesquisar um elemento
*       4. Inserir (preservando a ordenação)
*       5. Recuperar elemento
*       6. Confirmar presença, alterando o status para “true”
*       7. Remover de uma posição solicitada
*       8. Limpar lista
 */

#define DEBUG
//#undef DEBUG
#define MAX_LEN_NOME 50

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//Nó
typedef struct _NoNome {
    char nome[MAX_LEN_NOME];
    int status;
    struct _NoNome *next;
} TNoNome;

typedef struct _ListaLigada {
    TNoNome *inicio;
    TNoNome *fim;
    int tamanho;
} TListaLigada;

#pragma region interface
void showExibirMenu() {
    puts("\nLISTA DE CONVIDADOS - EXBIR LISTA");
    puts("\t[1] Exibe confirmados");
    puts("\t[2] Exibe todos");
    puts("\t[0] Voltar ao menu principal");
    printf("\nOpção: ");
}

void showMainMenu() {
    puts("\nLISTA DE CONVIDADOS");
    puts("\t[1] Exibe tamanho da lista");
    puts("\t[2] Exibir lista");
    puts("\t[3] Pesquisar convidado");
    puts("\t[4] Recuperar elemento pelo índice");
    puts("\t[5] Marcar/Desmarcar presença pelo índice");
    puts("\t[6] Inserir elemento na lista");
    puts("\t[7] Remover elemento da lista");
    puts("\t[8] Mostrar quantidade de confirmados");
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
                        case '1' : comando += 1; break; //Exibe confirmados
                        case '2' : comando += 2; break; //Exibe todos
                        case '0' : printf("\n"); break;
                        default : optionSub = '\0';
                    }
                } while (!optionSub);
                break;
            case '3' : comando = 30; break;     //Pesquisar valor
            case '4' : comando = 40; break;     //Recuperar elemento pelo índice
            case '5' : comando = 50; break;     //Marcar/Desmarcar confirmado pelo índice
            case '6' : comando = 60; break;     //Inserir elemento na lista
            case '7' : comando = 70; break;     //Remover elemento da lista
            case '8' : comando = 80; break;     //Mostrar quantidade de confirmados
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
void showTamanho(TListaLigada *lista) {
    system("cls");
    puts("\nTAMANHO DA LISTA");

    printf("\tTamanho da lista: %d elementos.\n", lista->tamanho);
    system("pause");
}

//21 Exibir convidados confirmados
void showListConfirmados(TListaLigada *lista) {
    TNoNome *aux;
    int i = 0;

    system("cls");
    puts("\nLISTA DE CONVIDADOS CONFIRMADOS");
    
    aux = lista->inicio;
    if (!lista->tamanho) {
        printf("\tLista vazia!\n");
    } else {
        while (aux) {
            if (aux->status)
                printf("\t%2d -> %s\n", i, aux->nome);
            aux = aux->next;
            i++;
        }
    }

    system("Pause");
}

//22 Exibir todos os contatos
void showListConvidados(TListaLigada *lista) {
    TNoNome *aux;
    int i = 0;

    system("cls");
    puts("\nLISTA DE CONVIDADOS (TODOS)");
    
    aux = lista->inicio;
    if (!lista->tamanho) {
        printf("\tLista vazia!\n");
    } else {
        while (aux) {
            printf("\t%2d -> %s\n", i++, aux->nome);
            aux = aux->next;
        }
    }

    system("Pause");
}

//30 Pesquisar valor
void pesquisaConvidado(TListaLigada *lista) {
    char nome[MAX_LEN_NOME];
    int achou = 0;
    int i = 0;
    int comp;
    TNoNome *aux;

    system("cls");
    puts("\nPESQUISA CONVIDADO NA LISTA");
    if (!lista->tamanho) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe o nome: ");
        fgets(nome, MAX_LEN_NOME, stdin); nome[strlen(nome)-1] = '\0';
        aux = lista->inicio;
        while (aux) {
            comp = strcmp(aux->nome, nome);
            if (comp == 0) {
                achou = 1;
                printf("\tConvidado %s localizado na posição %d\n", aux->nome, i);
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
void getElementoByIndice(TListaLigada *lista) {
    int indice = 0, invalidIdx = 0;
    TNoNome *aux;

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
            puts("\nDados do contato");
            printf("Nome  : %s\n", aux->nome);
            printf("Status: %s\n\n", aux->status ? "Confirmado" : "Pendente");
        }
    }
    system("pause");
}

//50 Marcar/Desmarcar presença pelo índice
void marcarDesmarcarByIndice(TListaLigada *lista) {
    int indice = 0, invalidIdx = 0;
    TNoNome *aux;

    system("cls");
    puts("\nALTERA STATUS DO CONVIDADO");
    if (!lista->tamanho) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe a posição do convidado que deseja mudar o status: ");
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
            aux->status = (aux->status ? 0 : 1);
            printf("\nConvidado %s agora está %s\n", aux->nome, (aux->status ? "Confirmado" : "Pendente"));
        }
    }
    system("Pause");
}

//Inserir convidado em ordem
void insereConvidado(TListaLigada *lista) {
    TNoNome *novo, *ins, *ant;
    int comp;

    system("cls");
    puts("\nINSERE UM NOVO CONVIDADO NA LISTA");
    printf("\tNome do convidado: ");
    novo = (TNoNome *) calloc(1, sizeof(TNoNome));
    fgets(novo->nome, MAX_LEN_NOME, stdin); novo->nome[strlen(novo->nome)-1] = '\0';
    novo->status = 0;
    novo->next = NULL;

    ins = lista->inicio;
    if (lista->tamanho == 0) {
        lista->inicio = novo;
        lista->fim = novo;
    } else if (lista->tamanho == 1) {
        comp = strcmp(novo->nome, ins->nome);
        if (comp < 0) {
            novo->next = ins;
            lista->inicio = novo;
        } else {
            ins->next = novo;
            lista->fim = novo;
        }
    } else {
        comp = strcmp(novo->nome, ins->nome);
        if (comp < 0) {
            novo->next = ins;
            lista->inicio = novo;
        } else {
            while (ins->next && comp > 0) {
                comp = strcmp(novo->nome, ins->nome);
                if (comp > 0) {
                    ant = ins;
                    ins = ins->next;
                }
            }
            if (ins != lista->fim) {    //No meio
                novo->next = ant->next;
                ant->next = novo;
            } else if (strcmp(novo->nome, ins->nome) > 0) { //À direita do fim
                ins->next = novo;
                lista->fim = novo;
            } else {    //À esquerda do fim
                novo->next = ant->next;
                ant->next = novo;
            }
        }
    }
    lista->tamanho++;
}

//Remover da posição indicada pelo índice informado
void removeConvidado(TListaLigada *lista) {
    char old[MAX_LEN_NOME];
    TNoNome *del, *ant;
    int indice, invalidIdx = 0;

    system("cls");
    puts("\nREMOVE UM CONVIDADO DE UMA POSIÇÃO ESPECÍFICA DA LISTA");
    printf("Informe a posição: ");
    scanf("%d", &indice);

    del = ant = lista->inicio;
    if (!lista->tamanho) { //lista vazia
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
        if (lista->inicio == del)
            if (lista->inicio == lista->fim)  //lista unitária
                lista->inicio = lista->fim = NULL;
            else
                lista->inicio = del->next;   //remoção na cabeça
        else
            ant->next = del->next;

        strcpy(old, del->nome);
        free(del);
        lista->tamanho--;
        printf("\nConvidado %s removido da lista.\n", old);
    }
    system("pause");
}

//Mostrar quantidade de confirmados
void exibeResumo(TListaLigada *lista) {
    TNoNome *pos;
    int contConf = 0;

    system("cls");
    puts("\nRESUMO DA LISTA DE CONVIDADOS");

    if (!lista->tamanho) {
        printf("\tLista vazia!\n");
    } else {
        pos = lista->inicio;
        while (pos) {
            if (pos->status)
                contConf++;
            pos = pos->next;
        }

        printf("Convidado..: %d\n", lista->tamanho);
        printf("Confirmados: %d\n", contConf);
        printf("Pendentes..: %d\n\n", lista->tamanho - contConf);
    }

    system("pause");
}


//Limpar lista
void limpaLista(TListaLigada *lista) {
    char confirma = 'N';
    TNoNome *del;

    printf("\nPara confirmar a limpeza da lista digite Y ou qualquer outra tecla para cancelar: ");
    scanf(" %c", &confirma);

    if (confirma == 'Y') {
        while (lista->inicio) {
            del = lista->inicio;
            lista->inicio = lista->inicio->next;
            free(del);
        }
        puts("\nLista excluída.");
    } else {
        puts("\nLimpeza cancelada.");
    }
    system("pause");
}

//Popular dados teste
void popularDadosTeste(TListaLigada *lista) {
    int i = 0;
    TNoNome *novo;
    TNoNome aux[] = {
        {"Aline", 0, NULL},
        {"Bruno", 1, NULL},
        {"Carolina", 1, NULL},
        {"Daniela", 1, NULL},
        {"Eduardo", 0, NULL},
        {"Fernanda", 1, NULL},
        {"Gabriel", 1, NULL},
        {"Helena", 0, NULL},
        {"Igor", 0, NULL},
        {"Juliana", 1, NULL},
        {"Renato", 1, NULL},
        {"Sabrina", 0, NULL},
        {"Zaca", 1, NULL}
    };

    novo = (TNoNome *) calloc(1, sizeof(TNoNome));
    strcpy(novo->nome, aux[i].nome);
    novo->status = aux[i].status;
    novo->next = NULL;
    lista->inicio = novo;
    lista->fim = novo;
    lista->tamanho++;

    for (i = 1; i < sizeof(aux) / sizeof(TNoNome); i++) {
        novo = (TNoNome *) calloc(1, sizeof(TNoNome));
        strcpy(novo->nome, aux[i].nome);
        novo->status = aux[i].status;
        novo->next = NULL;
        lista->fim->next = novo;
        lista->fim = novo;
        lista->tamanho++;
    }
}
#pragma endregion


int main(int argc, char **argv) {
    int command;
    TListaLigada *listaConvidados;

    listaConvidados = (TListaLigada *) calloc(1, sizeof(TListaLigada));
    listaConvidados->inicio = NULL;
    listaConvidados->fim = NULL;
    listaConvidados->tamanho = 0;
    
    system("chcp 65001");

    do {
        command = getComando();
        switch (command) {
            case 10: showTamanho(listaConvidados); break;  //Exibe tamanho da lista
            case 21: showListConfirmados(listaConvidados); break;  //Exibir convidados confirmados
            case 22: showListConvidados(listaConvidados); break;  //Exibir todos contatos
            case 30: pesquisaConvidado(listaConvidados); break;  //Pesquisar contato
            case 40: getElementoByIndice(listaConvidados); break;  //Recuperar elemento pelo índice
            case 50: marcarDesmarcarByIndice(listaConvidados); break;  //Marcar/Desmarcar presença
            case 60: insereConvidado(listaConvidados); break;  //Inserir convidado em ordem
            case 70: removeConvidado(listaConvidados); break;  //Remover da posição indicada pelo índice informado
            case 80: exibeResumo(listaConvidados); break;  //Exibe dados de resumo
            case 90: limpaLista(listaConvidados); break;  //Limpar lista
            #ifdef DEBUG
            case 99: popularDadosTeste(listaConvidados); break;  //Popular dados teste
            #endif
            case 00: break;  //Sair
        }
    } while (command);

    free(listaConvidados);

    return 0;
}
