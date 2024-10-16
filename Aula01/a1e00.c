/*
    Demonstrando o escopo de variáveis
    Mostrar debugando
    1. Mostrar o erro
    2. Deixar vidas global
    3. Pq incvidas falhou? É o mesmo nome, mas é outra var - imprimir o endereço para comprovar
    4. Remover da global e declarar na main()
    5. Pq não rolou? Pq o main é o ponto de entrada, mas é uma função. C não tem o conceito de programa principal. Tudo é func
    6. implementar o exibeSequencia();
    7. pq o i não imprime no final?
    8. Pq se declarar o i tb não deu - mostrar no debug
    9. Corrigir
*/

#include <stdio.h>
#include <stdlib.h>

void exibeSequencia() {
    int i;
    
    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    printf("\nÚltimo valoe impresso foi %d", i);
}

void incrementaVidas() {
    char letra;
    int vidas = 0;
    letra = 'a';
    vidas++;
    printf("\n%x\n", &vidas);
}

int main() {
    exibeSequencia();
    system("pause");
}