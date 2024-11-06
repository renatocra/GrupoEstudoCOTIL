/*
    Alocação contígua de matriz
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char mChar[3][3] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}};
 
    system("chcp 65001");

    //Executar linha a linha e ir mostrando as saídas
    printf("\n\nEndereços de cada elemento:");
    printf("\nEndereco de mChar[0][0] : %p", &mChar[0][0]);
    printf("\nEndereco de mChar[0][1] : %p", &mChar[0][1]);
    printf("\nEndereco de mChar[0][2] : %p", &mChar[0][2]);
    printf("\nEndereco de mChar[1][0] : %p", &mChar[1][0]);
    printf("\nEndereco de mChar[1][1] : %p", &mChar[1][1]);
    printf("\nEndereco de mChar[1][2] : %p", &mChar[1][2]);
    printf("\nEndereco de mChar[2][0] : %p", &mChar[2][0]);
    printf("\nEndereco de mChar[2][1] : %p", &mChar[2][1]);
    printf("\nEndereco de mChar[2][2] : %p", &mChar[2][2]);
    printf("\n");

    system("pause");
}
