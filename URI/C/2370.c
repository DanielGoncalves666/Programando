#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct no
{
	int habilidade;
	char nome[50];
	struct no *dir;
	struct no *esq;
};

typedef struct no *Arv;

void inserir(Arv *jogadores, Arv novo);

int main()
{
	int alunos, times;
	int habilidade;
	char nome[50];
	Arv jogadores = NULL;
	
	scanf("%d %d",&alunos,&times);

	for(int i = 0; i < alunos; i++)
	{
		scanf(" %s %d",nome,&habilidade);
		Arv novo = (Arv) malloc(sizeof(struct no));
		strcpy(novo->nome,nome);
		novo->habilidade = habilidade;
		novo->dir = novo->esq = NULL;
	}

	Arv Times[times];
	for(int i = 0; i < times; i++)
		Times[i] = NULL;

	for(int i = 0;;i++)
	{
		if(i == 4)
			i = 0;
		


	}


	return 0;
}

void inserir(Arv *jogadores, Arv novo)
{
	if(*jogadores == NULL)
	{
		*jogadores = novo;
	}
	else
	{
		if((*jogadores)->habilidade > novo->habilidade)
		{
			inserir(&((*jogadores)->esq),novo);
		}
		else
		{
			inserir(&((*jogadores)->dir),novo);
		}
	}
}

int removerEDistribuir(Arv *jogadores, Arv Time)
{
	if(*jogadores == NULL)
		return 0;
	else
	{
		Arv *aux = *jogadores;
		while((*aux)->dir != NULL)
			*aux = (*aux)->dir;

			
	}
}