#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct paciente pac;

struct paciente {
	char nome[50];
	int cpf;
	int cod;
	pac *prox;
};

typedef struct consultorio consu;

struct consultorio {
	char nome[20];
	char medico[40];
	int codigo;
	int num;
	pac *pri;
	consu *prox;
};

typedef struct{
	consu *first;
	consu *last;
	int quant;
}predio;

void abrir (predio *a) {
	setlocale(LC_ALL, "Portuguese");
	consu *c;
	
	c = (consu *) calloc (1, sizeof(consu)); 
	
	printf("_____Abrindo consult�rio_____\n\n");
	printf("Nome do consult�rio: ");
	scanf("%s", c->nome);
	printf("\nNome do medico respons�vel: ");
	scanf("%s", c->medico);
	printf("\nCodigo do consult�rio: ");
	scanf("%i", &c->codigo);
	
	if (a->first == NULL) {
		a->first = c;
		a->last = c;
	}

	else{
		a->last->prox = c;
		a->last= c;
		a->last->prox = NULL;
	}
	
	/*teste
	if (a->first != NULL)
	printf("deu bom!\n");
	*/
	
	a->quant++;
};

int fechar (predio *a) {
	setlocale(LC_ALL, "Portuguese");
	consu *l, *ant, *n;
	int i=1;
	int del;
	n = a->first;
	
	
	printf("\n\nDigite o codigo do consult�rio que deseja fechar: ");
	scanf("%i", &del);
	
	if (a->quant == 1) {
		a->first == NULL;
		a->last == NULL;
		free(n);
		a->quant--;
		return 0;
	}
		
	if (del == n->codigo) {
		a->first = n->prox;
		free(n);
		a->quant--;
		return 0;
	}
	
	else {
		while (del != n->codigo && n != NULL) {
			ant = n;
			n = n->prox;
			if(n == NULL){
				system("cls");
				printf("Codigo Invalido!\n\n");
				return 0;
			} 			
		}

		ant->prox = n->prox;
		free(n);
		a->quant--;
	}	
	
	return 0;
}

void listar (predio *b) {
	setlocale(LC_ALL, "Portuguese");
	consu *p = b->first;
	int i = 1;
	
	printf("\nconsultorios cadastrados: %i\n\n", b->quant);
	
	if (b->quant == 0) {
		system ("cls");
		printf("Nenhum consult�rio aberto no momento!\n\n");
	}
	
	else{
		do{
			printf("\n%i - %s        CODIGO: %i\n", i, p->nome, p->codigo);
			p = p->prox;
			i++;
		}while (p != NULL);
	}
}


int paciente (predio *a) {
	setlocale(LC_ALL, "Portuguese");
	consu *c = a->first;
	pac *p = (pac *) calloc (1, sizeof(pac));
	int i;
		
	if (a->quant == 0) {
		return 0;
	}
			
	printf("\n\nDigite o codigo do consult�rio em que deseja analisar: ");
	scanf("%i", &i);

	while (i != c->codigo && c != NULL) {
		c = c->prox;
		if(c == NULL){
			system("cls");
			printf("Codigo Invalido!\n\n");
			return 0;
		} 			
	}	
	
	
	system("cls");
	printf("_____CONSULTORIO_____");
	printf("\n\n ESPECIALIDADE: %s", c->nome);
	printf("\n\n MEDICO RESPONSAVEL: %s", c->medico);
	
	printf("\n\n_____FILA DE PACIENTES NO CONSULTORIO_____");
	
	
	
	if (c->num == 0 && c->pri == NULL) {
		printf ("\n\n\n ***fila vazia!***");
	}
		
	else {	
		pac *b = c->pri;
		while (b != NULL) {
			printf("\n\n - Nome: %s", b->nome);
			printf("\n    CPF: %i", b->cpf);
			printf("\n    Codigo Dunimed: %i", b->cod);
			printf("\n\npacientes cadastrados: %i", c->num);
			b = b->prox;
		}
	}
		
		
	printf ("\n\nEscolha a op��o desejada");
	printf ("\n\n  1- Atender paciente na fila");
	printf ("\n  2- cadastrar novo paciente");
	printf ("\n\nop�ao: ");
	scanf ("%i", &i);
		
	if (i != 1 && i != 2) {
		printf (" \nCodigo invalido digite novamente: ");
		scanf("%i", &i);
	}
		
	if(i == 1) {
			
		if (c->pri == NULL) {
			printf("\n\nA FILA ESTA VAZIA!!");
			return 0;
		}
			
		else {
			pac *ant,*b = c->pri;
		
			if (c->num == 1) {
				c->pri = NULL;
				system("cls");
				printf("\n\npaciente atendido!");
				c->num--;
				return 0;
			}
			
			else if (c->num > 1){
				while(b->prox != NULL){
				ant = b;
				b = b->prox;
				}
	
				ant->prox = NULL;
							
				system ("cls");
				
				printf("___pacientes restantes___");
				pac *x = c->pri;
				while (x != NULL) {
					printf("\n\n - Nome: %s", x->nome);
					printf("\n    CPF: %i", x->cpf);
					printf("\n    Codigo Dunimed: %i", x->cod);
					
					x = x->prox;
				}
					
				c->num--;
				printf("\n\npaciente atendido!!");
				return 0;
			}
		}
	}
		
	else{
		printf("\n\n_____AGENDAMENTO_____");
		printf("\n\nDigite o nome do paciente: ");
		scanf("%s", p->nome);
		printf("\nDigite o CPF do paciente: ");
		scanf("%i", &p->cpf);
		printf("\nDigite o codigo Dunimed do paciente: ");
		scanf("%i", &p->cod);
	
		if (c->num == 0) {
			c->pri = p;
			c->num++;
			return 0;
		}
		
		else{
			p->prox = c->pri;
			c->pri = p;
			c->num++;
			return 0;
		}
	}	

}


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	predio li;
	li.first = NULL;
	li.last = NULL;
	li.quant = 0;
	int total = 0;
	
	consu *consultorio;
	int op;
	
	do{
		system ("cls");
		listar (&li);
		printf("\n\n_____MENU INICIAL_____ \n\n");
		printf("1 - Abrir consult�rio\n");
		printf("2 - Fechar consult�rio\n");
		printf("3 - Pacientes\n");
		printf("4 - Sair\n\n");
		printf("Escolha uma op��o: ");
		scanf("%i", &op);
	
		if (op == 1) {
			int x;
			do{
				system("cls");
				abrir(&li);
				printf("\n1 - Abrir outro consult�rio\n");
				printf("2 - sair");
				printf("\n\nop��o: ");
				scanf("%i", &x);
			}while(x != 2);
		}
		
		if (op == 2){
			int x;
			do {
				system ("cls");
				listar(&li);
				fechar(&li);
				listar(&li);
				printf("\n\n1 - Fechar outro consult�rio");
				printf("\n2 - Sair");
				printf("\n\nop�ao: ");
				scanf("%i", &x);
			}while (x !=2);
		}
		
		if (op == 3) {
			int x;
			do {
				system("cls");
				listar(&li);
				paciente(&li);
				printf("\n\n1 - Pacientes");
				printf("\n2 - Sair");
				printf("\n\nop�ao: ");
				scanf("%i", &x);
			}while(x!=2);
		}
	}while(op!=4);
	
return 0;
}


