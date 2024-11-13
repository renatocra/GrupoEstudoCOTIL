/*
    vetor como parâmetro;
*/

#include <stdio.h>
#include <stdlib.h>

//DESTACAR A IMPORTÂNCIA DO MODIFICADOR CONST
void imprimeVetor(const int *v) {  //ou (int v[]) ou ainda (int v[5])
    for (int i = 0; i < 5; i++)
        printf("%d - ", v[i]);
}

void mudaVetor(int *v) { //ou (int v[]) ou ainda (int v[5])
    v[0] = 99;
    v[1] = 88;
}


int main() {
    int valores[5] = {1, 2, 3, 4, 5};

    system("chcp 65001");
    puts("\n\n");

    //imprimeVetor(valores);
    imprimeVetor(&valores[0]);
    puts("\n");
    mudaVetor(valores);
    imprimeVetor(valores);

    puts("\n\n");
    system("pause");

    system("cls");
}