/*
    4. Projete um tipo registro para guardar dados referente a um produto. A saber: código, nome (com 30
       posições), cor (20 posições), peso, dimensões e unidade (2 posições) de medida. O campo dimensões
       deverá ser um sub registro formado por: altura, comprimento e largura. A partir daí crie um programa
       que permita cadastrar os dados de dois registros desse tipo. Implemente três funções neste programa
       que recebam esses dois registros como parâmetros e retornem, respectivamente, o registro mais pesado;
       o registro que ocupa a maior área; o registro que ocupa o maior volume. Finalize o programa,
       apresentando na tela os dados do produto mais pesado, do de maior área e do de maior volume. Na
       exibição, o nome do produto apresentado deverá ter no máximo 15 caracteres. Se o conteúdo for maior,
       deve ser truncado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tdimensoes {
    float altura, comprimento, largura;
};

struct tproduto {
    int codigo;
    char nome[31];
    char cor[21];
    float peso;
    struct tdimensoes dimensoes;
    char unidade[3];
};

void CadastraProduto(struct tproduto *p) {
    printf("\nDados do produto:\n");
    printf("\tCódigo: ");
    scanf("%i", &p->codigo);
    while (getchar() != '\n');
    printf("\tNome: ");
    fgets(p->nome, sizeof(p->nome), stdin);
    printf("\tCor: ");
    fgets(p->cor, sizeof(p->cor), stdin);
    printf("\tPeso: ");
    scanf("%f", &p->peso);
    printf("\tDimensões:\n");
    printf("\t\tAltura: ");
    scanf("%f", &p->dimensoes.altura);
    printf("\t\tComprimento: ");
    scanf("%f", &p->dimensoes.comprimento);
    printf("\t\tLargura: ");
    scanf("%f", &p->dimensoes.largura);
    printf("\tUnidade: ");
    while (getchar() != '\n');
    fgets(p->unidade, sizeof(p->unidade), stdin);
    printf("\nProduto cadastrado!\n");

    system("pause");
}

struct tproduto getProdMaisPesado(struct tproduto p1, struct tproduto p2) {
    return(p1.peso > p2.peso ? p1 : p2);
}

struct tproduto getProdMaiorArea(struct tproduto p1, struct tproduto p2) {
    return(p1.dimensoes.largura * p1.dimensoes.comprimento > 
           p2.dimensoes.largura * p2.dimensoes.comprimento ? p1 : p2);
}

struct tproduto getProdMaiorVolume(struct tproduto p1, struct tproduto p2) {
    return(p1.dimensoes.largura * p1.dimensoes.comprimento * p1.dimensoes.altura >
           p2.dimensoes.largura * p2.dimensoes.comprimento * p2.dimensoes.altura ? p1 : p2);
}

int main() {
    struct tproduto produto1, produto2;
    struct tproduto maisPesado, maiorArea, maiorVolume;

    system("chcp 65001");
    CadastraProduto(&produto1);
    printf("\n\n");
    CadastraProduto(&produto2);
 
    //mostrar esta construção 
    printf("%s\n", getProdMaisPesado(produto1, produto2).nome);

    maisPesado = getProdMaisPesado(produto1, produto2);
    maisPesado.nome[10] = '\0';

    maiorArea = getProdMaiorArea(produto1, produto2);
    strncpy(maiorArea.nome, maiorArea.nome, 10);

    maiorVolume = getProdMaiorVolume(produto1, produto2);
    strncpy(maiorVolume.nome, maiorVolume.nome, 10);

    printf("Mais pesado: %s\n", maisPesado.nome);
    printf("Maior área: %s\n", maiorArea.nome);
    printf("Maior volume: %s\n", maiorVolume.nome);
    system("Pause");
}
