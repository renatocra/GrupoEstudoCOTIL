#include <stdio.h>
#include <stdlib.h>

int main() {

    char ***a;
    int cont = 33;


    a = (char***) malloc(sizeof(char**)*4);

    for (int i = 0; i < 4; i++) {
        a[i] = (char**) malloc(4 * sizeof(char*));
        for (int j = 0; j < 4; j++) {
            a[i][j] = (char*) calloc(4, sizeof(char));
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                a[i][j][k] = cont++;
            }
        }
    }

    for (int k = 0; k < 4; k++) {    
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%c ", a[k][i][j]);
            }
            puts("");
        }
        puts("\n\n");
    }

    for (int i = 0; i < 4; i++) {   
        for (int j = 0; j < 4; j++) {
            free(a[i][j]); 
        }
        free(a[i]);
    }
    free(a);
    a = NULL;

    return 0;
}