#include <stdio.h>
#include <string.h>
#include "estoque.h"

void exibir_menu(void) {
    printf("\n=== CONTROLE DE ESTOQUE ===\n");
    printf("1 - Listar produtos\n");
    printf("2 - Exibir total em estoque (com tributos)\n");
    printf("3 - Exibir total com desconto a vista\n");
    printf("4 - Exibir total a prazo (com juros)\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

void listar_produtos(Produto lista[], int total) {
    printf("\n--- Produtos Cadastrados ---\n");

    for (int i = 0; i < total; i++) {
        printf(
            "ID: %d | Categoria: %s | Cod. Barras: %s | "
            "Nome: %s | Preco: R$ %.2f | Qtd: %d\n",
            lista[i].id,
            lista[i].categoria,
            lista[i].codigo_barras,
            lista[i].nome,
            lista[i].preco,
            lista[i].quantidade
        );
    }
}

float calcular_total(Produto lista[], int total) {
    float soma = 0.0f;

    for (int i = 0; i < total; i++) {
        soma += lista[i].preco * lista[i].quantidade;
    }

    return soma + (soma * TAXA_PADRAO);
}

float aplicar_desconto(float total) {
    return total - (total * TAXA_DESCONTO);
}

float aplicar_juros(float total) {
    return total + (total * TAXA_JUROS);
}

int main(void) {
    Produto estoque[MAX_ITENS];

    int total_produtos = 2;

    estoque[0].id = 1;
    strcpy(estoque[0].categoria, "Papelaria");
    strcpy(estoque[0].codigo_barras, "789000000001");
    strcpy(estoque[0].nome, "Caderno");
    estoque[0].preco = 15.50f;
    estoque[0].quantidade = 10;

    estoque[1].id = 2;
    strcpy(estoque[1].categoria, "Papelaria");
    strcpy(estoque[1].codigo_barras, "789000000002");
    strcpy(estoque[1].nome, "Caneta");
    estoque[1].preco = 3.00f;
    estoque[1].quantidade = 50;

    int opcao = -1;

    while (opcao != 0) {
        exibir_menu();

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida!\n");
            break;
        }

        switch (opcao) {
            case 1:
                listar_produtos(estoque, total_produtos);
                break;

            case 2:
                printf(
                    "\nValor total em estoque (com tributos): R$ %.2f\n",
                    calcular_total(estoque, total_produtos)
                );
                break;

            case 3: {
                float total = calcular_total(estoque, total_produtos);

                printf(
                    "\nValor total com desconto a vista: R$ %.2f\n",
                    aplicar_desconto(total)
                );

                break;
            }

            case 4: {
                float total = calcular_total(estoque, total_produtos);

                printf(
                    "\nValor total a prazo (com juros): R$ %.2f\n",
                    aplicar_juros(total)
                );

                break;
            }

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    }

    return 0;
}