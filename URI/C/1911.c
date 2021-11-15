#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct no
{
	char nome[21];
	char assinaturaOriginal[21];
	struct no *esq;
	struct no *dir;
};

typedef struct no *Classe;

void adicionar(Classe *l, char nome[], char assinatura[]);
int consultar(Classe l, char nome[], char assinatura[]);
void liberar(Classe *l);

int main()
{
	int N, M, quantidade;
	char nome[21], assinatura[21];
	Classe lista = NULL;

	while(1)
	{
		scanf("%d",&N);
		if(N == 0)
			break;
		
		for(int i = 0; i < N; i++)
		{
			scanf(" %s %s",nome,assinatura);
			adicionar(&lista,nome,assinatura);
		}

		quantidade = 0;
		scanf("%d",&M);
		for(int i = 0; i < M; i++)
		{
			scanf(" %s %s",nome, assinatura);
			quantidade += consultar(lista,nome,assinatura);
		}

		printf("%d\n",quantidade);

		liberar(&lista);
	}

	return 0;
}

void adicionar(Classe *l, char nome[], char assinatura[])
{
	if(*l == NULL)
	{
		Classe novo = (Classe) malloc(sizeof(struct no));
		strcpy(novo->nome,nome);
		strcpy(novo->assinaturaOriginal,assinatura);
		novo->dir = novo->esq = NULL;
		*l = novo;
	}
	else
	{
		Classe aux = *l;
		if(strcmp(aux->nome, nome) > 0)
		{
			// nome menor
			adicionar(&(aux->esq),nome,assinatura);
		}
		else
		{
			// nome maior
			adicionar(&(aux->dir),nome,assinatura);
		}
	}
}

int consultar(Classe l, char nome[], char assinatura[])
{
	if(strcmp(l->nome,nome) == 0)
	{
		int quantidade = 0;
		for(int i = 0; i < strlen(l->assinaturaOriginal); i++)
		{
			if(l->assinaturaOriginal[i] != assinatura[i])
				quantidade++;
		}

		if(quantidade >= 2)
			return 1;
		else
			return 0;
	}
	else if(strcmp(l->nome,nome) > 0)
	{
		return consultar(l->esq,nome,assinatura);
	}
	else
	{
		return consultar(l->dir,nome,assinatura);
	}

	return 0;
}

void liberar(Classe *l)
{
	if(*l != NULL)
	{
		liberar(&((*l)->esq));
		liberar(&((*l)->dir));
		free(*l);
		*l = NULL;
	}
}