/*
    1. Dada uma data informada pelo usuário indicar ordinalmente o dia do ano que ela representa do 1º
       dia ao 365º/366º (conforme o ano for ou não bissexto). O usuário informará separadamente os valores
       do dia, do mês e do ano pesquisado. A entrada de dados deverá ser executada por uma função do tipo
       procedimento (ou seja, que retorna void). Esta função além de ler, deverá fazer a consistência dos
       dados de entrada. Consistência simples: dia entre 1 - 31 e mês entre 1 - 12.
       A verificação se o ano é ou não bissexto deve ser feita por uma função com retorno booleano.
       O cálculo do n-ésimo dia do ano deve ser feito por uma função que retorna um inteiro.
       Não podem ser usadas variáveis globais.

    Versão em C - Com a carga de dados em função
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int dia, mes, ano;
    int ehBissexto;
    int diaDoAno, totDiasDoAno;

    system("chcp 65001");
    printf("Informe o dia da data: ");
    scanf("%i", &dia);
	printf("Informe o mês da data: ");
    scanf("%i", &mes);
	printf("Informe o ano da data: ");
    scanf("%i", &ano);

    ehBissexto = (((ano % 4) == 0) && ((ano % 100) != 0)) || ((ano % 400) == 0);

    diaDoAno = dia;

    switch (13 - mes) {
        case 1: diaDoAno += 30;		//se dez acumula dias de nov
        case 2: diaDoAno += 31;		//se nov acumula dias de out
        case 3: diaDoAno += 30;		//se out acumula dias de set
        case 4: diaDoAno += 31;		//se set acumula dias de ago
        case 5: diaDoAno += 31;		//se ago acumula dias de jul
        case 6: diaDoAno += 30;		//se jul acumula dias de jun
        case 7: diaDoAno += 31;		//se jun acumula dias de mai
        case 8: diaDoAno += 30;		//se mai acumula dias de abr
        case 9: diaDoAno += 31;		//se abr acumula dias de mar
        case 10: diaDoAno += (ehBissexto ? 29 : 28); //se mar acumula dias de fev
        case 11: diaDoAno += 31;	//se fev acumula dias de jan
    }

	totDiasDoAno = (ehBissexto ? 366 : 365);

    printf("Esta data é o %iº dia do ano e está a %i dias do final do ano!\n", diaDoAno, (totDiasDoAno - diaDoAno));
    system("pause");
}