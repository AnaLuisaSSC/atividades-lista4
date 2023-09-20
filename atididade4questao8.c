#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidadeEstoque;
};

float calcularTotal(float preco, int quantidade) {
    return preco * quantidade;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese"); 
    
    struct Produto produtos[3]; 
    int escolha;

    struct Produto produto1 = { "Produto 1", 10.0, 10 };
    struct Produto produto2 = { "Produto 2", 20.0, 15 };
    struct Produto produto3 = { "Produto 3", 30.0, 8 };

    produtos[0] = produto1;
    produtos[1] = produto2;
    produtos[2] = produto3;
    
    printf("----------- Lista de Produtos -----------\n");
    for (int i = 0; i < 3; i++) {
        printf("Produto %d: %s\n", i + 1, produtos[i].nome);
    }

    printf("\nEscolha um produto para comprar (1 a 3): ");
    scanf("%d", &escolha);

    if (escolha < 1 || escolha > 3) {
        printf("Opção inválida. Encerrando o programa.\n");
        return 1;
    }

    int quantidadeCompra;
    printf("Digite a quantidade que deseja comprar: ");
    scanf("%d", &quantidadeCompra);

    escolha--; 
    if (quantidadeCompra > produtos[escolha].quantidadeEstoque) {
        printf("Quantidade em estoque insuficiente. Encerrando o programa.\n");
        return 1;
    }

    float total = calcularTotal(produtos[escolha].preco, quantidadeCompra);

    printf("\n----------- Resumo da Compra -----------\n");
    printf("Produto: %s\n", produtos[escolha].nome);
    printf("Preço unitário: R$ %.2f\n", produtos[escolha].preco);
    printf("Quantidade comprada: %d\n", quantidadeCompra);
    printf("Total da compra: R$ %.2f\n", total);

    produtos[escolha].quantidadeEstoque -= quantidadeCompra;
    printf("Estoque atualizado: %d\n", produtos[escolha].quantidadeEstoque);

    return 0;
}

