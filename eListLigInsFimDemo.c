/**
 * Demosntração de performance inclusão no final da lista quando se tem ou não um ponteiro para o fim.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define QTD_LOOPS 5000

//Nó
typedef struct _NoInt {
    int item;
    struct _NoInt *next;
} TNoInt;

//Nó
typedef struct _ListaLigada {
    TNoInt *inicio;
    TNoInt *fim;
} TListaLigada;

#pragma region funções de timer
struct timeval start_t() {
    struct timeval tic_;
    gettimeofday(&tic_, NULL);
    return tic_;
}

struct timeval stop_t() {
    return start_t();
}

float tempo(struct timeval start, struct timeval stop) {
    long double t = ((stop.tv_sec  - start.tv_sec) * 1000.0) +
              ((stop.tv_usec - start.tv_usec) * 0.001);
  
  return t;
}
#pragma endregion

void insereNoFimLento(TListaLigada *l, int valor) {
    TNoInt *novo, *pos;
    
    novo = (TNoInt *) calloc(1, sizeof(TNoInt));
 
    novo->item = valor;
    novo->next = NULL;

    if (!l->inicio) {
        l->inicio = l->fim = novo;
    } else {
        pos = l->inicio;
        while (pos->next) pos = pos->next;
        pos->next = novo;
        l->fim = novo;
    }
}

void insereNoFimRapido(TListaLigada *l, int valor) {
    TNoInt *novo, *pos;
    
    novo = (TNoInt *) calloc(1, sizeof(TNoInt));
 
    novo->item = valor;
    novo->next = NULL;

    if (!l->inicio) {
        l->inicio = l->fim = novo;
    } else {
        pos = l->fim;
        pos->next = novo;
        l->fim = novo;
    }
}

void printList(TListaLigada *l) {
    TNoInt *pos;
    
    pos = l->inicio;
    while (pos) {
        printf("%2d - ", pos->item);
        pos = pos->next;
    }
    puts("\n");
    system("pause");
}

void limpaList(TListaLigada *l) {
    TNoInt *pos, *del;
    
    pos = l->inicio;
    while (pos) {
        del = pos;
        pos = pos->next;
        free(del);
    }
    l->inicio = l->fim = NULL;
}


int main(int argc, char **argv) {
    float diff1, diff2;
    struct timeval ini, fim;
    TListaLigada *listaLigada;

    system("chcp 65001");
    puts("\n");

    //Lenta
    listaLigada = (TListaLigada *) calloc(1, sizeof(TListaLigada));
    listaLigada->inicio = listaLigada->fim = NULL;
    ini = start_t();
    for (int i = 0; i < QTD_LOOPS; i++)
        insereNoFimLento(listaLigada, i);
    fim = stop_t();
    diff1 = tempo(ini, fim);
    printf("Inclusão lenta. Tempo decorrido: %.2f ms\n", diff1);
    limpaList(listaLigada);
    free(listaLigada);
    listaLigada = NULL;

    //Rapida
    listaLigada = (TListaLigada *) calloc(1, sizeof(TListaLigada));
    listaLigada->inicio = listaLigada->fim = NULL;
    ini = start_t();
    for (int i = 0; i < QTD_LOOPS; i++)
        insereNoFimRapido(listaLigada, i);
    fim = stop_t();
    diff2 = tempo(ini, fim);
    printf("Inclusão rápida. Tempo decorrido: %.2f ms\n", diff2);
    limpaList(listaLigada);
    free(listaLigada);

    printf("\nO método rápido foi %.0f%% mais eficiente nesta execução.\n", (1 - diff2/diff1)*100);

    system("pause");

    return 0;
}
