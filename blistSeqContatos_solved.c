/**
 * Lista de contatos ordenados.
 *  - Implemente um sistema simples de gerenciamento de contatos
 *  - Desenvolver em equipe de forma colaborativa
 *  - Através de uma lista linear sequencial com descritor
 *  - Usar alocação dinâmica. Alocar no início e desalocar no fim.
 *  - Os contatos em cada posição da lista poderão ser estáticos.
 *  - Os atributos do contato serão: id, nome, telefone, email, instagram.
 *  - Renato irá definir a estrutura e o programa base
 *  - A lista deverá ter apenas as operações abaixo:
 *      1. Consultar o tamanho da lista
 *      2. Exibir a lista
 *      3. Pesquisar um elemento (pesquisa binária) 
 *      4. Inserir (preservando a ordenação)
 *      5. Recuperar elemento
 *      6. Remover de uma posição solicitada
 *      7. Limpar lista
 */

#define DEBUG
//#undef DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#define MAX_LEN_LISTA 10
#define MAX_NOME_CONTATO 40
#define MAX_FONE_CONTATO 20
#define MAX_INSTA_CONTATO 20

//Container / Nó
typedef struct {
    int id;
    char nome[MAX_NOME_CONTATO];
    char fone[MAX_FONE_CONTATO];
    char insta[MAX_INSTA_CONTATO];
} TContato;

//Descritor
typedef struct {
    int inicio;
    int final;
    int tamanho;
} TDescritor;


#pragma region interface
void showPesquisarMenu() {
    puts("\nLISTA DE CONTATOS - PESQUISAR");
    puts("\t[1] Pesquisar por nome");
    puts("\t[2] Pesquisar por perfil do Instagran");
    puts("\t[0] Voltar ao menu principal");
    printf("\nOpção: ");
}

void showMainMenu() {
    puts("\nLISTA DE INTEIROS");
    puts("\t[1] Exibe tamanho da lista");
    puts("\t[2] Exibir lista de contatos");
    puts("\t[3] Pesquisar contato");
    puts("\t[4] Recuperar contato");
    puts("\t[5] Inserir contato");
    puts("\t[6] Remover um contato");
    puts("\t[7] Limpar a lista");
    puts("\t[0] Sair");
    printf("\nOpção: ");
}

char getOptionMenu(char mainOrSub) {
    char option = '\0';

    system("cls");
    switch (mainOrSub) {
        case 'M' : showMainMenu(); break;
        case 'P' : showPesquisarMenu(); break;
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
            case '2' : comando = 20; break;     //Exibir lista de contatos
            case '3' :                          //Exibir lista de contatos
                comando = 30;                   //Pesquisar contato
                do {
                    optionSub = getOptionMenu('P');
                    switch (optionSub) {
                        case '1' : comando += 1; break; //Pesquisar por nome
                        case '2' : comando += 2; break; //Pesquisar por perfil do Instagran
                        case '0' : printf("\n"); break;
                        default : optionSub = '\0';
                    }
                } while (!optionSub);
                break;
            case '4' : comando = 40; break;     //Recuperar contato
            case '5' : comando = 50; break;     //Inserir contato
            case '6' : comando = 60; break;     //Remover um contato
            case '7' : comando = 70; break;     //Limpar a lista
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
//10 Exibe tamanho da lista
void showTamanho(TDescritor desc) {
    system("cls");
    puts("\nCONTATOS CADASTRADOS");
    if (!desc.tamanho)
        printf("\tLista vazia\n");
    else
        printf("\tVocê tem %d contatos cadastrados\n", desc.tamanho);
    system("Pause");
}

//20 Exibir lista de contatos
void showList(const TContato *list, TDescritor desc) {
    system("cls");
    puts("\nLISTAGEM DE CONTATOS");
    if (!desc.tamanho) {
        printf("\tLista vazia!\n");
    } else {
        for (int i = desc.inicio; i <= desc.final; i++) {
            printf("\tÍndice...: %d\n", i);
            printf("\tId.......: %d\n", list[i].id);
            printf("\tNome.....: %s\n", list[i].nome);
            printf("\tFone.....: %s\n", list[i].fone);
            printf("\tInstagram: %s\n\n", list[i].insta);
        }
    }
    system("Pause");
}

//31 Pesquisar por nome
void pesquisaNome(const TContato *list, TDescritor desc) {
    char nome[MAX_NOME_CONTATO];
    int inicio = 0;
    int fim = desc.final;
    int meio;
    int achou = 0;
    int comp;

    system("cls");
    puts("\nPESQUISA POR NOME (Primeira Ocorrência)");
    if (!desc.tamanho) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe o nome a ser procurado: ");
        fgets(nome, MAX_NOME_CONTATO, stdin); nome[strlen(nome)-1] = '\0';

        while (inicio <= fim) {
            meio = inicio + (fim - inicio) / 2;
            comp = strcmp(list[meio].nome, nome);

            if (comp == 0) {
                achou = 1;
                break;
            } else if (comp < 0) {
                inicio = meio + 1;
            } else {
                fim = meio - 1;
            }
        }

        if (achou)
            printf("\nContato %s localizado na posição: %d\n", list[meio].nome, meio);
        else
            puts("\nNenhuma ocorrência do nome foi encontrada na lista!");
    }
    system("Pause");
}

//32 Pesquisar por perfil do Instagran
void pesquisaInsta(const TContato *list, TDescritor desc) {
    char nome[MAX_INSTA_CONTATO];
    int inicio = 0;
    int fim = desc.final;
    int meio;
    int achou = 0;
    int comp;

    system("cls");
    puts("\nPESQUISA POR PERFIL DO INSTAGRAM (Primeira Ocorrência)");
    if (!desc.tamanho) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe o perfil a ser procurado: ");
        fgets(nome, MAX_INSTA_CONTATO, stdin); nome[strlen(nome)-1] = '\0';

        while (inicio <= fim) {
            meio = inicio + (fim - inicio) / 2;
            comp = strcmp(list[meio].insta, nome);

            if (comp == 0) {
                achou = 1;
                break;
            } else if (comp < 0) {
                inicio = meio + 1;
            } else {
                fim = meio - 1;
            }
        }

        if (achou)
            printf("\nContato %s localizado na posição: %d\n", list[meio].nome, meio);
        else
            puts("\nNenhuma ocorrência do nome foi encontrada na lista!");
    }
    system("Pause");
}

//40 Recuperar contato
void getElementoByIndice(const TContato *list, TDescritor desc) {
    int indice;

    system("cls");
    puts("\nRETORNA DADOS DO CONTATO PELO ÍNDICE");
    if (!desc.tamanho) {
        printf("\tLista vazia!\n");
    } else {
        printf("Informe a posição que deseja recuperar: ");
        scanf("%d", &indice);
        if (indice < desc.inicio || indice > desc.final) {
            printf("\nA lista não possui a posição informada!");
        } else {
            printf("\tÍndice...: %d\n", indice);
            printf("\tId.......: %d\n", list[indice].id);
            printf("\tNome.....: %s\n", list[indice].nome);
            printf("\tFone.....: %s\n", list[indice].fone);
            printf("\tInstagram: %s\n\n", list[indice].insta);
        }
    }
    system("Pause");
}

//50 Inserir contato
void insereContato(TContato *list, TDescritor *desc) {
    int indice;
    TContato novo;

    system("cls");
    puts("\nINSERE UM NOVO CONTATO NA LISTA");
    if (desc->tamanho == MAX_LEN_LISTA) {
        printf("\tLista cheia! Não é possível inserir novo elemento.\n");
        system("pause");
    } else {
        printf("Dados do novo contato:\n");
        printf("\tId.......: ");
        scanf("%d", &novo.id); getchar();
        printf("\tNome.....: ");
        fgets(novo.nome, MAX_NOME_CONTATO, stdin); novo.nome[strlen(novo.nome)-1] = '\0';
        printf("\tFone.....: ");
        fgets(novo.fone, MAX_FONE_CONTATO, stdin); novo.fone[strlen(novo.fone)-1] = '\0';
        printf("\tInstagram: ");
        fgets(novo.insta, MAX_INSTA_CONTATO, stdin); novo.insta[strlen(novo.insta)-1] = '\0';

        if (desc->tamanho == 0)
            indice = 0;
        else
            for (indice = desc->inicio; strcmp(novo.nome, list[indice].nome) >= 0 && indice <= desc->final; indice++);
        desc->final++;
        for (int i = desc->final; i > indice; i--)
            list[i] = list[i - 1];
        list[indice] = novo;
        desc->tamanho++;
    }
}

//60 Remover um contato
void removeContato(TContato *list, TDescritor *desc) {
    int indice;
    TContato del;

    system("cls");
    puts("\nREMOVE UM CONTATO DA LISTA");
    if (!desc->tamanho) {
        printf("\tLista vazia! Não é possível remover elementos.\n");
    } else {
        printf("Informe a posição: ");
        scanf("%d", &indice);
        if (indice < desc->inicio || indice > desc->final) {
            printf("\nA lista não possui a posição informada!\n");
        } else {
            del = list[indice];
            for (int i = indice; i < desc->final; i++)
                list[i] = list[i + 1];
            desc->final--;
            desc->tamanho--;
            printf("\nContato %d - %s removido da lista.\n", del.id, del.nome);
        }
    }
    system("pause");
}

//70 Limpar a lista
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

//99 Popular dados teste
void popularDadosTeste(TContato *list, TDescritor *desc) {
    TContato aux[] = {
        {7, "Aline", "6666-7777", "@aline"},
        {6, "Barbara", "5555-6666", "@barb"},
        {5, "Davi", "4444-5555", "@davi"},
        {4, "Diego", "3333-4444", "@diego"},
        {2, "Gabriel", "1111-2222", "@gabriel"},
        {3, "Gilaine", "2222-3333", "@gislaine"},
        {8, "Marcos", "7777-8888", "@marcos"},
        {1, "Renato", "4444-3333", "@renato"}
    };

    desc->final = -1;
    desc->tamanho = 0;
    for (int i = desc->inicio; i < 8 && i < MAX_LEN_LISTA; i++) {
        list[i] = aux[i];
        desc->final++;
        desc->tamanho++;
    }
}
#pragma endregon

int main(int argc, char **argv) {
    int command;
    TDescritor desc;
    TContato *listaContatos;
    
    listaContatos = (TContato *) calloc(MAX_LEN_LISTA, sizeof(TContato));
    desc.inicio = desc.tamanho = 0;
    desc.final = -1;

    system("chcp 65001");

    do {
        command = getComando();
        switch (command) {
            case 10: showTamanho(desc); break;  //Exibe tamanho da lista
            case 20: showList(listaContatos, desc); break;  //Exibir lista de contatos
            case 31: pesquisaNome(listaContatos, desc); break;  //Pesquisar por nome
            case 32: pesquisaInsta(listaContatos, desc); break;  //Pesquisar por perfil do Instagran
            case 40: getElementoByIndice(listaContatos, desc); break;  //Recuperar contato
            case 50: insereContato(listaContatos, &desc); break;  //Inserir contato
            case 60: removeContato(listaContatos, &desc); break;  //Remover um contato
            case 70: limpaLista(&desc); break;  //Limpar a lista
            #ifdef DEBUG
            case 99: popularDadosTeste(listaContatos, &desc); break;  //Popular dados teste
            #endif
            case 00: break;  //Sair
        }
    } while (command);

    return 0;
}
