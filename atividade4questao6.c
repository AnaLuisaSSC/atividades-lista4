#include <stdio.h>
#include <locale.h>

struct Estudante {
    char nome[50];
    char matricula[30];
    float notas[3]; // Notas em três disciplinas
};

float calcularMedia(const struct Estudante *estudante) {
    float soma = 0.0;
    for (int i = 0; i < 3; i++) {
        soma += estudante->notas[i];
    }
    return soma / 3.0;
}

int estaAprovado(const struct Estudante *estudante) {
    float media = calcularMedia(estudante);
    return media >= 7.0;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese"); 
    
    
    struct Estudante aluno;
    
    printf("\n-------------------Cadastro do Aluno ----------------\n\n\n");
    
    printf("Nome: ");
    fflush(stdin);
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    
    printf("Matrícula: ");
    fflush(stdin);
    fgets(aluno.matricula, sizeof(aluno.matricula), stdin);

    for (int i = 0; i < 3; i++) {
        printf("Informe a nota da disciplina %d: ", i + 1);
        scanf("%f", &aluno.notas[i]);
    }
    
    printf("\n\n------------------ Lendo os dados da struct --------------------\n\n");
    printf("Nome: %s", aluno.nome);
    printf("Matrícula: %s", aluno.matricula);

    for (int i = 0; i < 3; i++) {
        printf("Nota da Disciplina %d: %.2f\n", i + 1, aluno.notas[i]);
    }

    printf("Média das Notas: %.2f\n", calcularMedia(&aluno));

    if (estaAprovado(&aluno)) {
        printf("O aluno está aprovado.\n");
    } else {
        printf("O aluno não está aprovado.\n");
    }
    
    return 0;
}

