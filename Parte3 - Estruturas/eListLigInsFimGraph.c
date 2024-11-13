/**
 * Demosntração de performance inclusão no final da lista quando se tem ou não um ponteiro para o fim.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <windows.h>

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
        while (pos->next) { /*Sleep(0.1);*/ pos = pos->next; }
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
        Sleep(5);
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
    TListaLigada *listaLigada = (TListaLigada *) calloc(1, sizeof(TListaLigada));
    listaLigada->inicio = listaLigada->fim = NULL;

    printf("%s;%s\n", "Valor", "Tempo");

    for (int i = 0; i < 100000; i++) {
        struct timeval ini = start_t();
        insereNoFimLento(listaLigada, i);
        //insereNoFimRapido(listaLigada, i);
        struct timeval fim = stop_t();
        if (i % 10 == 0) printf("%d;%2.40f\n", i, tempo(ini, fim));
    }
    limpaList(listaLigada);
    
    free(listaLigada);

    return 0;
}
