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
    system("cls");
    puts("\nTAMANHO DA LISTA");

    system("Pause");
}

// //21 Exibir lista do início para o fim
void showListForwards() {
    system("cls");
    puts("\nDADOS DA LISTA");
    
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
    system("cls");
    puts("\nPESQUISA VALOR NA LISTA (Todas Ocorrências)");

    system("Pause");
}

//40 Recuperar elemento pelo índice
void getElementoByIndice() {
    system("cls");
    puts("\nRETORNA VALOR DO ELEMENTO PELO ÍNDICE");

    system("pause");
}

//50 Edita  elemento pelo índice
void editElementoByIndice() {
    system("cls");
    puts("\nEDITA VALOR DO ELEMENTO PELO ÍNDICE");

    system("Pause");
}

//Inserir no final da lista
void insereElementoFim() {
    system("cls");
    puts("\nINSERE UM NOVO ELEMENTO NO FINAL DA LISTA");
    printf("Informe o caractere: ");

}

//Inserir no início
void insereElementoInicio() {
    system("cls");
    puts("\nINSERE UM NOVO ELEMENTO NA LISTA");
    printf("Informe o caractere: ");

}

//Inserir na posição indicada pelo índice informado
void insereElementoMiddle() {
    system("cls");
    puts("\nINSERE UM NOVO ELEMENTO NA LISTA");
    printf("Informe a posição em que deseja inserir: ");

}

//Remover do final da lista
void removeElementoFim() {
    system("cls");
    puts("\nREMOVE UM ELEMENTO DO FIM DA LISTA");

    system("pause");
}

//Remover do início
void removeElementoInicio() {
    system("cls");
    puts("\nREMOVE UM ELEMENTO DO INÍCIO DA LISTA");

    system("pause");
}

//Remover da posição indicada pelo índice informado
void removeElementoMiddle() {
    system("cls");
    puts("\nREMOVE UM ELEMENTO DE UMA POSIÇÃO ESPECÍFICA DA LISTA");
    printf("Informe a posição: ");

    system("pause");
}

//Ordenar ascedente
void ordenaListAsc() {
    system("cls");
    puts("\nORDENAÇÃO DA LISTA");

    puts("Lista ordenada.");
    system("Pause");
}

void ordenaListDesc() {
    system("cls");
    puts("\nORDENAÇÃO DA LISTA");

    puts("Lista ordenada.");
    system("Pause");
}


//Limpar lista
void limpaLista() {
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
