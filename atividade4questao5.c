#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Livro {
    char titulo[70];
    char autor[100];
    int ano;
};

void adicionarLivro(struct Livro lista[], int *num_livro) {
    if (*num_livro < 10) {
        printf("Informe o nome do livro: ");
        scanf("%s", lista[*num_livro].titulo);
        
        printf("Informe o nome do autor: ");
        scanf("%s", lista[*num_livro].autor);

        printf("Informe o ano de publicação: ");
        scanf("%d", &lista[*num_livro].ano);

        (*num_livro)++;
        printf("O livro foi adicionado com sucesso!!!!\n");
    } else {
        printf("A lista está cheia. Não é possível adicionar mais livros.\n");
    }
}

void listarLivros(struct Livro lista[], int numLivro) {
    if (numLivro == 0) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("------------------------------------------Lista dos seus livros:------------------------------------------\n\n");
    for (int i = 0; i < numLivro; i++) {
        printf("Nome: %s \nAutor: %s \nAno: %d\n", lista[i].titulo, lista[i].autor, lista[i].ano);
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    }
}

// Função para buscar um livro pelo nome
void buscarLivro(struct Livro lista[], int numLivro, char nomeBusca[]) {
    int encontrado = 0;
    for (int i = 0; i < numLivro; i++) {
        if (strcmp(lista[i].titulo, nomeBusca) == 0) {
            printf("Seu livro foi encontrado:\n");
            printf("Nome: %s \nAutor: %s \nAno: %d\n", lista[i].titulo, lista[i].autor, lista[i].ano);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Livro não foi encontrado.\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    struct Livro lista[100];
    int numLivro = 0;
    int opcao;
    char nomeBusca[50];

    do {
        printf("-----------------------------------------------------------------Menu do programa: ----------------------------------------------------------------- \n");
        printf("1 - Adicionar livro \n");
        printf("2 - Listar livros \n");
        printf("3 - Buscar livro pelo Nome: \n");
        printf("0 - Sair \n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro(lista, &numLivro);
                break;
            case 2:
                listarLivros(lista, numLivro);
                break;
            case 3:
                printf("Digite o nome do livro para ser buscado: ");
                scanf("%s", nomeBusca);
                buscarLivro(lista, numLivro, nomeBusca);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
