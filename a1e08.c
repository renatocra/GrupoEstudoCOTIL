/*
    combinações registro com array
*/

#include <stdio.h>
#include <stdlib.h>

struct _aluno {
    int ra;
    float notas[3];
    float media;
};

void imprimeRegistro(const struct _aluno r) {
    printf("\tRA....: %d\n", r.ra);
    for (int i = 0; i < 3; i++)
        printf("\tNota %d: %.1f\n", i, r.notas[i]);
    printf("\tMédia.: %.1f\n\n", r.media);
}

void calculaMedia(struct _aluno *r) {
    r->media = 0.00;
    for (int i = 0; i < 3; i++)
        r->media += r->notas[i];
    r->media /= 3.0;
}

int main() {
    struct _aluno aluno = {333, {10.0, 5.5, 7.5}, 0.0};
    
    system("chcp 65001");
    puts("\n\n");

    imprimeRegistro(aluno);
    puts("\n");
    calculaMedia(&aluno);
    imprimeRegistro(aluno);

    puts("\n\n");
    system("pause");
}