#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct no
{
	int validade;
	char nome[21];
	struct no *dir;
	struct no *esq;
};

typedef struct no *Arv;

void inserir(Arv *carnes, char nome[], int valid);
int percorrer(Arv carnes, int primeiro);
void liberar(Arv *carnes);

int main()
{
	int N, valid;
	char nome[21];
	Arv carnes = NULL;

	while(scanf("%d",&N) != EOF)
	{
		for(int i = 0; i < N; i++)
		{
			scanf(" %s %d",nome,&valid);
			inserir(&carnes,nome,valid);
		}

		percorrer(carnes,1);
		printf("\n");
		liberar(&carnes);
	}


	return 0;
}

void inserir(Arv *carnes, char nome[], int valid)
{
	if(*carnes == NULL)
	{
		Arv novo = (Arv) malloc(sizeof(struct no));
		novo->validade = valid;
		strcpy(novo->nome,nome);
		novo->dir = novo->esq = NULL;
		*carnes = novo;
	}
	else
	{
		Arv aux = *carnes;
		if(aux->validade > valid)
		{
			inserir(&(aux->esq),nome,valid);
		}
		else
		{
			inserir(&(aux->dir),nome,valid);
		}
	}
}

// 0 se o primeiro já passou, 1 se ainda não passou
int percorrer(Arv carnes, int primeiro)
{
	int aux;

	if(carnes != NULL)
	{
		aux = percorrer(carnes->esq,primeiro);
		if(aux)
		{
			printf("%s",carnes->nome);
			aux = 0;		
		}
		else
			printf(" %s",carnes->nome);

		aux = percorrer(carnes->dir,aux);
	
		return aux;
	}

	return primeiro;
}

void liberar(Arv *carnes)
{
	if(*carnes != NULL)
	{
		Arv aux = *carnes;
		liberar(&(aux->esq));
		liberar(&(aux->dir));
		free(*carnes);
		*carnes = NULL;
	}
}