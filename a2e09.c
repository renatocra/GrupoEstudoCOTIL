#include <stdio.h>
#include <stdlib.h>

int main() {
    char *c;

    system("pause");
    for (int i = 0; i < 1000000; i++) {
        c = (char *) calloc(1024*1000, 1);
    }
    system("pause");
}