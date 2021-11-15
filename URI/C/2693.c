#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct no
{
	char nome[51];
	char regiao;
	int distancia;
	struct no *esq;
	struct no *dir;
};

typedef struct no *Alunos;

void inserir(Alunos *van, char nome[], char regiao, int distancia);
void percorrer(Alunos van);
void liberar(Alunos *l);

int main()
{
	int N, distancia;
	char nome[51], regiao;
	Alunos van = NULL;

	while(scanf("%d", &N) != EOF)
	{
		for(int i = 0; i < N; i++)
		{
			scanf(" %s %c %d",nome,&regiao,&distancia);
			inserir(&van,nome,regiao,distancia);
		}
		percorrer(van);
		liberar(&van);
	}

	return 0;
}

void inserir(Alunos *van, char nome[], char regiao, int distancia)
{
	if(*van == NULL)
	{
		Alunos novo = (Alunos) malloc(sizeof(struct no));
		novo->regiao = regiao;
		novo->distancia = distancia;
		strcpy(novo->nome,nome);
		novo->dir = novo->esq = NULL;
		*van = novo;
	}
	else
	{
		Alunos aux = *van;
		if(distancia < aux->distancia)
		{
			inserir(&(aux->esq),nome,regiao,distancia);
		}
		else if(distancia > aux->distancia)
		{
			inserir(&(aux->dir),nome,regiao,distancia);
		}
		else
		{
			if(regiao < aux->regiao)
			{
				inserir(&(aux->esq),nome,regiao,distancia);
			}
			else if(regiao > aux->regiao)
			{
				inserir(&(aux->dir),nome,regiao,distancia);
			}
			else
			{
				if(strcmp(nome,aux->nome) < 0)
				{
					inserir(&(aux->esq),nome,regiao,distancia);
				}
				else
				{
					inserir(&(aux->dir),nome,regiao,distancia);
				}
			}
		}
	}
}

void percorrer(Alunos van)
{
	if(van != NULL)
	{
		percorrer(van->esq);
		printf("%s\n",van->nome);
		percorrer(van->dir);
	}
}

void liberar(Alunos *l)
{
	if(*l != NULL)
	{
		liberar(&((*l)->esq));
		liberar(&((*l)->dir));
		free(*l);
		*l = NULL;
	}
}