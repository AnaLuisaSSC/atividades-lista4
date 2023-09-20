#include <stdio.h>
#include <string.h>
#include <locale.h> 

/* Questão 4 - Crie uma struct chamada "Contato" que armazene o nome e o número de telefone de uma pessoa. escreva um programa que permita ao usuário adicionar 
contatos, listar todos os contatos e buscar um contato pelo nome. */

struct Contato {
    char nome[70]; 
	char telefone[20];  
};

void adicionarContato(struct Contato agenda[], int *num_contatos) {  //num= numero
    if (*num_contatos < 10) { 
        printf("Informe o nome do contato: ");
        scanf("%s", agenda[*num_contatos].nome);

        printf("Informe o número de telefone do contato: ");
        scanf("%s", agenda[*num_contatos].telefone);

        (*num_contatos)++;
        printf("O contato foi adicionado com sucesso!!!!\n");
    } else {
        printf("A agenda está cheia. Não é possível adicionar mais contatos.\n");
    }
}

void listarContatos(struct Contato agenda[], int num_contatos) {
	 if (num_contatos == 0) {
        printf("A agenda está vazia.\n");
        return;
    }

    printf("------------------------------------------Lista dos seus contatos:------------------------------------------\n\n");
    for (int i = 0; i < num_contatos; i++) {
        printf("Nome: %s \nTelefone: %s \n", agenda[i].nome, agenda[i].telefone);
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    }
}

// Função para buscar um contato pelo nome
void buscarContato(struct Contato agenda[], int num_contatos, char nome_busca[]) {
    int encontrado = 0;
    for (int i = 0; i < num_contatos; i++) {
        if (strcmp(agenda[i].nome, nome_busca) == 0) {
            printf("Seu contato foi encontrado:\n");
            printf("Nome: %s \nTelefone: %s \n", agenda[i].nome, agenda[i].telefone);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Contato não foi encontrado.\n");
    }
}

int main() {
	 setlocale(LC_ALL, "Portuguese");
	 
    struct Contato agenda[100]; 
    int num_contatos = 0; 
    int opcao;
    char nome_busca[50];

    do {
        printf("-----------------------------------------------------------------Menu do programa: ----------------------------------------------------------------- \n");
        printf("1 - Adicionar Contato \n");
        printf("2 - Listar Contatos \n");
        printf("3 - Buscar Contato pelo Nome: \n");
        printf("0 - Sair \n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(agenda, &num_contatos);
                break;
            case 2:
            	 listarContatos(agenda, num_contatos);
                break;
            case 3:
                printf("Digite o nome do contato para ser buscado: ");
                scanf("%s", nome_busca);
                buscarContato(agenda, num_contatos, nome_busca);
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

