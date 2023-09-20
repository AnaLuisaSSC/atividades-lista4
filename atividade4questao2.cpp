#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

/* Questão 2 - Crie uma struct chamada "Tipo" que possa armazenar um valor do tipo inteiro, um valor do tipo pontoflutuante e uma letra. Escreva um programa que 
demonstre o uso da struct, atribuindo valores de diferentes tipos e imprimindo-os.*/

struct Tipo {
    int valorInteiro;
    float pontoFlutuante;
    char letra;
};

int main() {
	 setlocale(LC_ALL, "Portuguese");
	 
    struct Tipo tipos;

    tipos.valorInteiro = 77;
    tipos.pontoFlutuante = 36.87;
    tipos.letra = 'Z';

    printf("Valor Inteiro: %d\n",tipos.valorInteiro);
    printf("Valor Flutuante: %f\n", tipos.pontoFlutuante);
    printf("Letra: %c\n", tipos.letra);

    return 0;
}

