#include<stdio.h>

int fibo (int i) {
	
	int final;
	
	if ( i==1  )
		return 1;
	if (i==2)
		return 1;
 
	return fibo(i-1) + fibo(i-2);
}

int main () {	

int fibo (int i);

int x, resultado;

	printf("////////// SEQUENCIA DE FIBONACCI //////////\n\n");
	printf("Digite a posicao da sequencia de fibonacci voce deseja saber o numero ");
	setbuf(stdin,NULL);
	scanf("%i", &x);
	
	system("cls");
	
	resultado = fibo(x);
	
	printf("O numero que esta na posicao %i eh: %i\n\n", x, resultado);

return 0;	
}








