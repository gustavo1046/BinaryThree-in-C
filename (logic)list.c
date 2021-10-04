#include <stdio.h>

struct numero;

typedef struct numerais numero;

struct numerais {
	int valor;
	numero *prox;
};

int main () {
	int c;
	numero n1, n2, n3, n4, n5;
	n1.valor = 10;
	n2.valor = 20;
	n3.valor = 30;
	n4.valor = 40;
	n5.valor = 50;
	
	n1.prox = &n2;
	n2.prox = &n3;
	n3.prox = &n4;
	n4.prox = &n5;
	n5.prox = NULL;
	
	numero *temp = &n1;
	
	for (c=1; c<6; c++) {
		while (temp!=NULL) {
			printf("Valor do N%d: %d\n", c, temp->valor);
			temp = temp->prox;
			c++;
		}
	}

return 0;
}


/*
TESTE

printf("Valor do N1: %d\n", n1.valor);
printf("Valor do N2: %d\n", n2.valor);
printf("Valor do Proximo do N1: %d\n", n1.prox->valor);
printf("Valor do Proximo do Proximo do N1: %d\n", n1.prox->Prox->valor);
    
*/


