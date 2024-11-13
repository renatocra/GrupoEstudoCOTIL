/*
    struct como parametro;
*/

#include <stdio.h>
#include <stdlib.h>

struct _aluno {
    int ra;
    float nota1;
    float nota2;
    float nota3;
    float media;
};

void imprimeRegistro(struct _aluno r) {
    printf("\tRA....: %d\n", r.ra);
    printf("\tNota 1: %.1f\n", r.nota1);
    printf("\tNota 2: %.1f\n", r.nota2);
    printf("\tNota 3: %.1f\n", r.nota3);
    printf("\tMédia.: %.1f\n\n", r.media);
}

// void calculaMedia(struct _aluno r) {
//     r.media = (r.nota1 + r.nota2 + r.nota3) / 3;
// }

void calculaMedia(struct _aluno *r) {
    r->media = (r->nota1 + r->nota2 + r->nota3) / 3;
}

int main() {
    struct _aluno aluno = {333, 10.0, 5.5, 7.5, 0.0};
    
    system("chcp 65001");
    puts("\n\n");

    imprimeRegistro(aluno);
    puts("\n");
    //calculaMedia(aluno);
    calculaMedia(&aluno);
    imprimeRegistro(aluno);

    //Pq a media não foi calculada?
    //Debugar inspecionando endereço

    puts("\n\n");
    system("pause");
}