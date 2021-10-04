#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <locale.h>

//structs

typedef struct Produto produto;

struct Produto {
	char nome[20];
	int codigo;
	int preco_custo;
	int preco_venda;
	int quant;
	produto *pai;
	produto *direita;
	produto *esquerda;
};

typedef struct{
	produto *first;
	int quantidade;
}arvore;



//fun��es

void listar(produto *p) {
	if (p == NULL){
        return;
    }
    printf("nome- %s\npre�o de custo - %i\npre�o de venda - %i\n", p->nome, p->preco_custo, p->preco_venda);
    listar(p->esquerda);
    listar(p->direita);
}


void inserir_recursivo(produto *Inserir, produto *Atual){
	
    if(Inserir->codigo < Atual->codigo){
        if(Atual->esquerda == NULL){
            Atual->esquerda = Inserir;
        }
        else{
            InserirRecursivo(Inserir, Atual->esquerda);
        }
    }
    else{
        if(Atual->direita == NULL){
            Atual->direita = Inserir;
        }
        else{
            InserirRecursivo(Inserir, Atual->direita);
        }
    }
}


void inserir_ordenado(produto *p, arvore *a){
    if(a != NULL){
        if(a->first != NULL){
            if(p != NULL){
                InserirRecursivo(p, a->first);
                a->quantidade++;
            }
        }
        else{
            a->first = p;
            a->quantidade++;
        }
    }
}

int main () {
	setlocale(LC_ALL,"portuguese");
	produto *P;
    arvore *Arv = (arvore *) calloc(1, sizeof(arvore));
    Arv->first = NULL;
    Arv->quantidade = 0;
    
    P = (produto *) calloc(1, sizeof(produto));
    P->codigo = 1234;
    strcpy(P->nome, "Teste1");
    inserir_ordenado(P, Arv);
    
    
    P = (produto *) calloc(1, sizeof(produto));
    P->codigo = 1234;
    strcpy(P->nome, "Teste2");
    inserir_ordenado(P, Arv);
	inserir_recursivo(P, )
    listar(P);
	/*
    P = (Paciente *) calloc(1, sizeof(Paciente));
    P->AnoNascimento = 2000;
    strcpy(P->Nome, "Teste2");
    InserirOrdenado(P, Arv);

    P = (Paciente *) calloc(1, sizeof(Paciente));
    P->AnoNascimento = 1980;
    strcpy(P->Nome, "Teste3");
    InserirOrdenado(P, Arv);
	*/
	return 0;
}
