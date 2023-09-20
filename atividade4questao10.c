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
    
    // Declara��o da vari�vel moeda do tipo Moeda
    struct Moeda moeda;
    
    printf("Digite a taxa de c�mbio (quantos d�lares valem 1 euro): ");
    scanf("%f", &moeda.euros);

    moeda.dolares = 1.0; // Taxa de c�mbio invertida para d�lares

    int opcao;
    do {
        printf("\nEscolha uma opera��o:\n");
        printf("1. Converter de d�lares para euros\n");
        printf("2. Converter de euros para d�lares\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);

        float valor;
        switch (opcao) {
            case 1:
                printf("Digite o valor em d�lares: ");
                scanf("%f", &valor);
                printf("%.2f d�lares � equivalente a %.2f euros.\n", valor, converterDolaresParaEuros(valor, moeda.euros));
                break;

            case 2:
                printf("Digite o valor em euros: ");
                scanf("%f", &valor);
                printf("%.2f euros � equivalente a %.2f d�lares.\n", valor, converterEurosParaDolares(valor, moeda.dolares));
                break;

            case 3:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Op��o inv�lida. Escolha uma op��o v�lida.\n");
        }
    } while (opcao != 3);
    
    return 0;
}

