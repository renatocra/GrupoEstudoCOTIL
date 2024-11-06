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

    system("pause");
}

//21 Exibir convidados confirmados
void showListConfirmados(TListaLigada *lista) {
    system("cls");
    puts("\nLISTA DE CONVIDADOS CONFIRMADOS");
    
    system("Pause");
}

//22 Exibir todos os contatos
void showListConvidados(TListaLigada *lista) {
    system("cls");
    puts("\nLISTA DE CONVIDADOS (TODOS)");
    
    system("Pause");
}

//30 Pesquisar valor
void pesquisaConvidado(TListaLigada *lista) {
    system("cls");
    puts("\nPESQUISA CONVIDADO NA LISTA");

    system("Pause");
}

//40 Recuperar elemento pelo índice
void getElementoByIndice(TListaLigada *lista) {
    system("cls");
    puts("\nRETORNA DADOS DO ELEMENTO PELO ÍNDICE");

    system("pause");
}

//50 Marcar/Desmarcar presença pelo índice
void marcarDesmarcarByIndice(TListaLigada *lista) {
    system("cls");
    puts("\nALTERA STATUS DO CONVIDADO");

    system("pause");
}

//Inserir convidado em ordem
void insereConvidado(TListaLigada *lista) {
    system("cls");
    puts("\nINSERE UM NOVO CONVIDADO NA LISTA");
}

//Remover da posição indicada pelo índice informado
void removeConvidado(TListaLigada *lista) {
    system("cls");
    puts("\nREMOVE UM CONVIDADO DE UMA POSIÇÃO ESPECÍFICA DA LISTA");

    system("pause");
}

//Mostrar quantidade de confirmados
void exibeResumo(TListaLigada *lista) {
    system("cls");
    puts("\nRESUMO DA LISTA DE CONVIDADOS");

    system("pause");
}


//Limpar lista
void limpaLista(TListaLigada *lista) {
    char confirma = 'N';

    printf("\nPara confirmar a limpeza da lista digite Y ou qualquer outra tecla para cancelar: ");
    scanf(" %c", &confirma);

    if (confirma == 'Y') {

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
