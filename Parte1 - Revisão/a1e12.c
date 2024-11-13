/*
    Retornando códigos de erros ao SO
    echo %ERRORLEVEL%
    Exemplo de usos. Crashs de programas. Como não inicializou interface.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char nome1[50], nome2[50];
    int errorCode = 0;

    switch (argc) {
        case 3:
            printf("Nomes foram comparados.");
            errorCode =  0; //Retorno quando ok
            break;
        case 2:
            errorCode = 1; //Código de erro quando falta um argumento
            break;
        case 1:
            errorCode = 2; //Código de erro quando faltam dois argumento
            break;
        default:
            errorCode = 3; //Código de erro quando há excesso de argumentos
    }

    if (errorCode != 0)
        printf("Parametros incorretos.");

    return errorCode;
}