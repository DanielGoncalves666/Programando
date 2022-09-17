#include<stdio.h>
#include<stdlib.h>

struct no
{
	int valor;
	struct no *prox;
	struct no *ant;
};
typedef struct no *No;

struct fila
{
	int soma;
	struct no *ini;
	struct no *fim;
};
typedef struct fila *Fila;

void inserir(Fila f, int valor);
void remover(Fila f);
void liberar(Fila f);

int main()
{
	Fila f = (Fila) malloc(sizeof(struct fila));
	f->fim = f->ini = NULL;
	f->soma = 0;

	int T, K, N;

	scanf("%d",&T);
	for(int i = 0; i < T; i++)
	{
		scanf("%d %d",&K,&N);
		for(int j = 0; j < K; j++)
		{
			inserir(f,j);
		}

		if(N <= K)
		{
			printf("%d\n",N - 1);
		}
		else
		{
			for(int j = K; j < N; j++)
			{
				f->soma %= 1000007;
				inserir(f,f->soma);
				remover(f);
			}
			printf("%d\n",f->ini->valor);
		}

		liberar(f);
	}

	return 0;
}

void inserir(Fila f, int valor)
{
	No novo = (No) malloc(sizeof(struct no));
	novo->valor = valor;
	
	if(f->ini == NULL)
	{
		novo->prox = NULL;
		novo->ant = NULL;
		f->ini = f->fim = novo;
		f->soma = novo->valor;
	}
	else
	{
		novo->prox = f->ini;
		novo->ant = NULL;
		novo->prox->ant = novo;
		f->ini = novo;
		f->soma += novo->valor % 1000007; 
	}
}

void remover(Fila f)
{
	if(f->ini == NULL)
		return;

	if(f->ini == f->fim)
	{
		No aux = f->fim;

		f->soma -= aux->valor;
		f->ini = f->fim = NULL;

		free(aux);
	}
	else
	{
		No aux = f->fim;
		
		f->soma += 1000007 - aux->valor;
		f->fim = aux->ant;
		f->fim->prox = NULL;

		free(aux);
	}
}

void liberar(Fila f)
{
	No aux;
	while(f->ini != NULL)
	{
		aux = f->ini;
		f->ini = aux->prox;

		free(aux);
	}
	f->soma = 0;
}