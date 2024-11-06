/*
    combinações array de registro
*/

#include <stdio.h>
#include <stdlib.h>

struct _aluno {
    int ra;
    float notas[3];
    float media;
};

//Note que agora volta a usar o ponto pois o ponteiro é do array
void imprimeRegistro(const struct _aluno *r) {
    for (int j = 0; j < 3; j++) {
        printf("\tRA....: %d\n", r[j].ra);
        for (int i = 0; i < 3; i++)
            printf("\tNota %d: %.1f\n", i, r[j].notas[i]);
        printf("\tMédia.: %.1f\n\n", r[j].media);
    }
}

void calculaMedia(struct _aluno *r) {
    for (int j = 0; j < 3; j++) {
        r[j].media = 0.00;
        for (int i = 0; i < 3; i++)
            r[j].media += r[j].notas[i];
        r[j].media /= 3.0;
    }
}

int main() {
    struct _aluno aluno[3] = {{333, {10.0, 5.5, 7.5}, 0.0},
                              {348, {5.5, 9.5, 2.5}, 0.0},
                              {510, {3.5, 5.0, 7.5}, 0.0}};
    
    system("chcp 65001");
    puts("\n\n");

    imprimeRegistro(aluno);
    puts("\n");
    calculaMedia(aluno);
    imprimeRegistro(aluno);

    puts("\n\n");
    system("pause");
}