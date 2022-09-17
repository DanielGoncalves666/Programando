#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct produto
{
	char nome[51];
	double preco;
	struct produto *dir;
	struct produto *esq;
};

typedef struct produto *Feira;

void adicionar(Feira *f, char *nome, double preco);
void esvaziar(Feira *f);
double consultarPreco(Feira f, char *nome);


int main()
{
	int N, M, P, qtd;
	char nome[51];
	double preco, total;
	Feira feira = NULL;

	scanf("%d",&N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d ",&M);
		for(int j = 0; j < M; j++)
		{
			scanf("%s", nome);
			scanf("%lf", &preco);
			adicionar(&feira,nome,preco);
		}

		total = 0;
		scanf("%d ", &P);
		for(int j = 0; j < P; j++)
		{
			scanf("%s",nome);
			scanf("%d", &qtd);
			preco = consultarPreco(feira,nome);

			total += preco * qtd;
		}

		printf("R$ %.2lf\n",total);
		esvaziar(&feira);
	}

	return 0;
}

void adicionar(Feira *f, char *nome, double preco)
{
	if(*f == NULL)
	{
		Feira novo = (Feira) malloc(sizeof(struct produto));
		strcpy(novo->nome, nome);
		novo->preco = preco;
		novo->dir = novo->esq = NULL;
		
		*f = novo;
	}
	else if(strcmp(nome, (*f)->nome) < 0)
	{
		// novo produto tem nome menor que o do nó
		adicionar(&((*f)->esq),nome,preco);
	}
	else
	{
		adicionar(&((*f)->dir), nome,preco);
	}
}

double consultarPreco(Feira f, char *nome)
{
	if(f == NULL)
		return 0;
	
	if(strcmp(f->nome, nome) == 0)
	{
		return f->preco;
	}
	else if(strcmp(f->nome, nome) > 0)
	{
		// nome do produto é menor que o do nó
		return consultarPreco(f->esq, nome);
	}
	else
	{
		return consultarPreco(f->dir, nome);
	}
}

// esvazia em pós ordem
void esvaziar(Feira *f)
{
	if(*f != NULL)
	{
		esvaziar(&(*f)->esq);
		esvaziar(&(*f)->dir);
		free(*f);
		*f = NULL;
	}
}