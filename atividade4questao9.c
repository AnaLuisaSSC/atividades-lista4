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
    printf("Aumento de sal�rio aplicado com sucesso. Novo sal�rio: R$ %.2f\n", funcionario->salario);
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
    
    printf("Digite o nome do funcion�rio: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
    
    printf("Digite o cargo do funcion�rio: ");
    fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);

    printf("Digite o sal�rio do funcion�rio: ");
    scanf("%f", &funcionario.salario);
    
    printf("Digite a data de admiss�o (formato: AAAA MM DD): ");
    scanf("%d %d %d", &funcionario.dataAdmissao.tm_year, &funcionario.dataAdmissao.tm_mon, &funcionario.dataAdmissao.tm_mday);

    int opcao;
    do {
        printf("\nEscolha uma opera��o:\n");
        printf("1. Dar aumento de sal�rio\n");
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
                printf("O funcion�rio est� na empresa h� %d anos.\n", calcularTempoNaEmpresa(&funcionario));
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

