/*
    Demonstrando a leitura de caracteres
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    //começar jogador com 5 para mostrar vazamento da memória depois passar para 21
    char jogador[21];
    char categoria;
    int idade;

    system("chcp 65001");

    puts("\nEntendendo a leitura de string e char");

    //mostrar o que ocorre quando lê só o nome e quando nome com espaço em branco
     //printf("Jogador: ");
     //scanf("%s", jogador);
        //pq sem o &
        //conclui a leitura do buffer com espaço se digitar nome e sobrenome ele só considere o nome
        //o restante fica perdido no buffer
        //Veja que se adicionar mais um scanf ele já lê 
    //scanf("%s", jogador); //pq sem o &

    //gets lê até o enter - MAS ELA É CONSIDERADA INSEGURA
    //printf("Jogador: ");
    //gets(jogador);

    //printf("Categoria (A, B ou C): ");
    //scanf("%c", &categoria);


    //A boa prática
    printf("Jogador: ");
    fgets(jogador, 21, stdin);
    printf("Categoria (A, B ou C): ");
    categoria = getchar();
    printf("Idade: ");
    scanf("%i", &idade);
 
    puts("\n\n");
    printf("%s\n%c\n%i\n", jogador, categoria, idade);
    system("pause");
}