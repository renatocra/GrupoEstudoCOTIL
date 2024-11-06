/*
    Impacto do conceito de row/column major order vs. memória cache no desempenho
*/

#include <stdio.h>
#include <stdlib.h>
#define NROWS 100000
#define NCOLS 2000

int main() {
    int m[NROWS][NCOLS];

    //Respeitando o rows-major order
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            m[i][j] = (i + j) % 2;
        }
    }

    //Desrespeitando o rows-major order
    // for (int j = 0; j < NCOLS; j++) {
    //     for (int i = 0; i < NROWS; i++) {
    //         m[i][j] = (i + j) % 2;
    //     }
    // }

    system("pause");
 
    return 0;
}
