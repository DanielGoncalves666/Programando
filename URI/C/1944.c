#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct no
{
	char blocos[5];
	struct no *prox;
};

typedef struct no *Pilha;

void inserir(Pilha *p, char blocos[]);
void remover(Pilha *p);
int verificar(Pilha p, char blocos[]);

int main()
{
	int N;
	int quantidade = 0;
	char blocos[5], face[5] = {'F','A','C','E','\0'};
	blocos[4] = '\0';
	Pilha painel = NULL;
	inserir(&painel,face);

	scanf("%d",&N);
	for(int i = 0; i < N; i++)
	{
		scanf(" %c %c %c %c",&blocos[0],&blocos[1],&blocos[2],&blocos[3]);

		if(verificar(painel,blocos))
		{
			// o jogador ganha o prêmio;
			quantidade++;
			remover(&painel);

			if(painel == NULL)
				inserir(&painel, face);
		}
		else
		{
			inserir(&painel,blocos);
		}
	}

	printf("%d\n",quantidade);

	return 0;
}

void inserir(Pilha *p, char blocos[])
{
	Pilha novo = (Pilha) malloc(sizeof(struct no));
	strcpy(novo->blocos,blocos); 

	if(*p == NULL)
	{
		novo->prox = NULL;
		*p = novo;
	}
	else
	{
		novo->prox = *p;
		*p = novo;
	}	
}

void remover(Pilha *p)
{
	if(*p != NULL)
	{
		Pilha aux = *p;
		*p = aux->prox;
		free(aux);
	}
}

int verificar(Pilha p, char blocos[])
{
	if(p == NULL)
		return 0;
	else
	{
		int qtd = 0;
		for(int i = 0; i < 4; i++)
		{
			if(p->blocos[i] == blocos[3 - i])
				qtd++;
		}

		return qtd == 4;
	}
}