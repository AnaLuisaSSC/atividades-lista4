#include <stdio.h>
#include <math.h>
#include <locale.h> 

/*Quest�o 3 - Crie uma struct chamada "Ponto" que represente um ponto no plano cartesiano com coordenadas x e y.     Em seguida, implemente fun��es para calcular a 
dist�ncia entre dois pontos e a inclina��o da reta que os conecta.   */

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
    printf("Dist�ncia entre os pontos: %lf\n", distancia);

    // C�lculo e impress�o da inclina��o da reta
    double inclinacao = calcular_inclinacao(ponto1, ponto2);
    if (isinf(inclinacao)) {
        printf("Inclina��o: Infinita (reta vertical)\n");
    } else {
        printf("Inclina��o: %lf\n", inclinacao);
    }


    return 0;
}

