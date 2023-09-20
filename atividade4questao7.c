#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

struct ContaBancaria {
    char nomeTitular[50];
    int numeroConta;
    float saldo;
};

void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Depósito realizado com sucesso. Novo saldo: %.2f\n", conta->saldo);
}

bool sacar(struct ContaBancaria *conta, float valor) {
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque realizado com sucesso. Novo saldo: %.2f\n", conta->saldo);
        return true;
    } else {
        printf("Saldo insuficiente para realizar o saque.\n");
        return false;
    }
}

float verificarSaldo(const struct ContaBancaria *conta) {
    return conta->saldo;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese"); 
    
    struct ContaBancaria conta;
    
    printf("Digite o nome do titular da conta: ");
    fgets(conta.nomeTitular, sizeof(conta.nomeTitular), stdin);
    
    printf("Digite o número da conta: ");
    scanf("%d", &conta.numeroConta);

    printf("Digite o saldo inicial: ");
    scanf("%f", &conta.saldo);
    
    printf("\n----------- Operações Bancárias -----------\n");

    int opcao;
    do {
        printf("\nEscolha uma operação:\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Verificar saldo\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                float valorDeposito;
                printf("Digite o valor a ser depositado: ");
                scanf("%f", &valorDeposito);
                depositar(&conta, valorDeposito);
                break;

            case 2:
                float valorSaque;
                printf("Digite o valor a ser sacado: ");
                scanf("%f", &valorSaque);
                sacar(&conta, valorSaque); 
                break;

            case 3: 
                printf("Saldo atual: %.2f\n", verificarSaldo(&conta));
                break;

            case 4:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida. Escolha uma opção válida.\n");
        }
    } while (opcao != 4);
    
    return 0;
}

