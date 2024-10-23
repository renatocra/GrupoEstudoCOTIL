/*
    Demonstrando passagem de parâmetros
    Exemplo em cpp
*/

#include <iostream>

using namespace std;

void dobroDeARef(int& a) {
    a *= 2;
    cout << "Endereço de a: " << &a << endl;
    cout << "Endereço apontado por a (parametro formal): " << a << endl;
}

int dobroDeA(int a) {
    int valor = 0;
    valor = a * 2;
    cout << "Endereco de a (parametro formal): " << &a << endl;
    return(valor);
}

int main() { 
    int val, dobro = 0;

    int idade = 10;
    int& refIdade = idade;


    cout << endl << "Por VALOR:" << endl;
    val = 5;

    cout << "Endereco de val (parametro real): " << &val << endl;
    dobro = dobroDeA(val);

    cout << endl << endl;
    cout << "Por REFERENCIA:" << endl;
    val = 8;

    cout << "Endereco de val (parametro real): " << &val << endl;
    dobroDeARef(val);

    refIdade = 20;
    cout << "Endereco de idade: " << &idade << endl;
    cout << "Endereco de refIdade: " << &refIdade << endl;
    cout << "Valor de idade: " << idade << endl;
    cout << "Valor de refIdade: " << refIdade << endl;

    cout << "";
}