#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

struct Pessoa {
    char nome[50];
    int idade;
    float altura; 
};

struct Pessoa SetPessoa(char *nome, int idade, float altura) {
    struct Pessoa P;
    strcpy(P.nome, nome); 
    P.idade = idade;
    P.altura = altura;
    return P;
}

void ImprimePessoa(struct Pessoa P) {
    printf("Nome: %s \n Idade: %d \n Altura: %f \n", P.nome, P.idade, P.altura);
}

int main() {
    struct Pessoa Lucas;
    setlocale(LC_ALL, "Portuguese");

    printf("---------------------------------------------- Cadastro da Pessoa ----------------------------------------------\n\n\n");

    Lucas = SetPessoa("Lucas Moura", 23, 1.80); 
    ImprimePessoa(Lucas); 
    return 0;
}

