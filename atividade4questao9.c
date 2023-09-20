#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>

struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
    struct tm dataAdmissao;
};

void darAumento(struct Funcionario *funcionario, float percentual) {
    funcionario->salario *= (1 + percentual / 100);
    printf("Aumento de salário aplicado com sucesso. Novo salário: R$ %.2f\n", funcionario->salario);
}

int calcularTempoNaEmpresa(const struct Funcionario *funcionario) {
    time_t currentTime;
    time(&currentTime);
    
    double diferenca = difftime(currentTime, mktime(&funcionario->dataAdmissao));
    return (int)(diferenca / (60 * 60 * 24 * 365)); 
}

int main(void) {
    setlocale(LC_ALL, "Portuguese"); 
    
   
    struct Funcionario funcionario;
    
    printf("Digite o nome do funcionário: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
    
    printf("Digite o cargo do funcionário: ");
    fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);

    printf("Digite o salário do funcionário: ");
    scanf("%f", &funcionario.salario);
    
    printf("Digite a data de admissão (formato: AAAA MM DD): ");
    scanf("%d %d %d", &funcionario.dataAdmissao.tm_year, &funcionario.dataAdmissao.tm_mon, &funcionario.dataAdmissao.tm_mday);

    int opcao;
    do {
        printf("\nEscolha uma operação:\n");
        printf("1. Dar aumento de salário\n");
        printf("2. Calcular tempo na empresa\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                float percentualAumento;
                printf("Digite o percentual de aumento: ");
                scanf("%f", &percentualAumento);
                darAumento(&funcionario, percentualAumento);
                break;

            case 2:
                printf("O funcionário está na empresa há %d anos.\n", calcularTempoNaEmpresa(&funcionario));
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

