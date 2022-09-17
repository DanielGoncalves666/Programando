#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// como não sei o tamanho máximo da pilha, implementação com alocação dinâmica
struct no
{
	int valor;
	struct no *prox;
};

typedef struct no *Pilha;

void push(Pilha *p, int valor);
int pop(Pilha *p);
int min(Pilha p);


int main()
{
	int N, valor;
	char operacao[5];
	Pilha saco = NULL;


	scanf("%d",&N);
	for(int i = 0; i < N; i++)
	{
		scanf(" %s",operacao);

		if(strcmp(operacao,"PUSH") == 0)
		{
			scanf("%d",&valor);
			push(&saco,valor);
		}
		else if(strcmp(operacao,"POP") == 0)
		{
			valor = pop(&saco);

			if(valor == -1)
				printf("EMPTY\n");
		}
		else	// MIN
		{
			valor = min(saco);
			if(valor == -1)
				printf("EMPTY\n");
			else
				printf("%d\n",valor);
		}
	}

	return 0;
}

void push(Pilha *p, int valor)
{
	Pilha novo = (Pilha) malloc(sizeof(struct no));
	novo->valor = valor;

	if(*p == NULL)
	{
		// pilha vazia
		novo->prox = NULL;
		*p = novo;
	}
	else
	{
		novo->prox = *p;
		*p = novo;
	}
}

int pop(Pilha *p)
{
	if(*p == NULL)
		return -1;
	else
	{
		int valor = (*p)->valor;
		Pilha aux = *p;
		*p = aux->prox;

		free(aux);

		return valor;
	}
}

int min(Pilha p)
{
	if(p == NULL)
	{
		return -1;
	}
	else
	{
		Pilha aux = p;
		int grau = aux->valor;
		while(aux->prox != NULL)
		{
			if(aux->prox->valor < grau)
				grau = aux->prox->valor;

			aux = aux->prox;
		}
	
		return grau;
	}
}