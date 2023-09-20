#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

struct Moeda {
    float dolares;
    float euros;
};

float converterDolaresParaEuros(float valorDolares, float taxaCambio) {
    return valorDolares * taxaCambio;
}

float converterEurosParaDolares(float valorEuros, float taxaCambio) {
    return valorEuros / taxaCambio;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese"); 
    
    // Declaração da variável moeda do tipo Moeda
    struct Moeda moeda;
    
    printf("Digite a taxa de câmbio (quantos dólares valem 1 euro): ");
    scanf("%f", &moeda.euros);

    moeda.dolares = 1.0; // Taxa de câmbio invertida para dólares

    int opcao;
    do {
        printf("\nEscolha uma operação:\n");
        printf("1. Converter de dólares para euros\n");
        printf("2. Converter de euros para dólares\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);

        float valor;
        switch (opcao) {
            case 1:
                printf("Digite o valor em dólares: ");
                scanf("%f", &valor);
                printf("%.2f dólares é equivalente a %.2f euros.\n", valor, converterDolaresParaEuros(valor, moeda.euros));
                break;

            case 2:
                printf("Digite o valor em euros: ");
                scanf("%f", &valor);
                printf("%.2f euros é equivalente a %.2f dólares.\n", valor, converterEurosParaDolares(valor, moeda.dolares));
                break;

            case 3:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida. Escolha uma opção válida.\n");
        }
    } while (opcao != 3);
    
    return 0;
}

