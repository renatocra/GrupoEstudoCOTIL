#include ".\stackLig\stackLig.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100


int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str) && *str != '.') {
            return 0;
        }
        str++;
    }
    return 1;
}

int main() {
    char expression[MAX_SIZE];
    int erro;
    float result = 0;

    system("chcp 65001");
    system("cls");

    printf("Digite a expressão em RPN (separada por espaços): ");
    fgets(expression, MAX_SIZE, stdin);
    expression[strcspn(expression, "\n")] = '\0';

    TStackLig *pilha = sl_create();
    char *token = strtok(expression, " ");

    while (token) {
        if (is_number(token)) {
            sl_push(pilha, atof(token));
        } else {
            switch (token[0]) {
                case '+':
                    sl_push(pilha, sl_pop(pilha, &erro) + sl_pop(pilha, &erro));
                    break;
                case '-':
                    sl_push(pilha, sl_pop(pilha, &erro) - sl_pop(pilha, &erro));
                    break;
                case '*':
                    sl_push(pilha, sl_pop(pilha, &erro) * sl_pop(pilha, &erro));
                    break;
                case '/':
                    sl_push(pilha, sl_pop(pilha, &erro) + sl_pop(pilha, &erro));
                    break;
                default:
                    printf("Erro: Operador inválido %s\n", token);
                    result -1;
            }
        }

        if (result == -1) break;

        token = strtok(NULL, " "); 
    }

    if (result != -1) {
        printf("Resultado: %.2f\n", sl_pop(pilha, &erro));
    }
    sl_destroy(&pilha);

    system("pause");

    return 0;
}