#ifndef ESTOQUE_H
#define ESTOQUE_H

#define MAX_ITENS 50
#define ESTOQUE_MINIMO 5
#define TAXA_PADRAO 0.10
#define TAXA_DESCONTO 0.05
#define TAXA_JUROS 0.08

typedef struct {
    int id;
    char categoria[20];
    char codigo_barras[20];
    char nome[30];
    float preco;
    int quantidade;
} Produto;

float aplicar_desconto(float total);
float aplicar_juros(float total);

#endif
