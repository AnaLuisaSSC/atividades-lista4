#include <stdio.h>
#include <math.h>
#include <locale.h> 

/*Questão 3 - Crie uma struct chamada "Ponto" que represente um ponto no plano cartesiano com coordenadas x e y.     Em seguida, implemente funções para calcular a 
distância entre dois pontos e a inclinação da reta que os conecta.   */

struct Ponto {
   	double x;
    double y;
}Ponto;

	double calcular_distancia(struct Ponto p1, struct Ponto p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

	double calcular_inclinacao(struct Ponto p1, struct Ponto p2) {
	    double dx = p2.x - p1.x;
	    double dy = p2.y - p1.y;
	    
	    if (dx == 0.0) {
	        return INFINITY;
	    } else {
	        return dy / dx;
	    }
	}

int main() {
	 setlocale(LC_ALL, "Portuguese");
	 
    struct Ponto ponto1 = {2.0, 4.0};
    struct Ponto ponto2 = {6.0, 8.0};

    double distancia = calcular_distancia(ponto1, ponto2);
    printf("Distância entre os pontos: %lf\n", distancia);

    // Cálculo e impressão da inclinação da reta
    double inclinacao = calcular_inclinacao(ponto1, ponto2);
    if (isinf(inclinacao)) {
        printf("Inclinação: Infinita (reta vertical)\n");
    } else {
        printf("Inclinação: %lf\n", inclinacao);
    }


    return 0;
}

