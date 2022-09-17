#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct no
{
	int poder;
	int mortos;
	int mortes;
	char nome[101];
	struct no *esq, *dir;
};

typedef struct no *Arv;

void inserir(Arv *a, char nome[], int poder, int mortos, int mortes);
char *consulta(Arv a);

int main()
{
	Arv godofor = NULL;
	int N, poder, mortos, mortes;
	char nome[101], *resul;

	scanf("%d",&N);
	for(int i = 0; i < N; i++)
	{
		scanf(" %s %d %d %d",nome, &poder,&mortos,&mortes);
		inserir(&godofor,nome,poder,mortos,mortes);
	}
	resul = consulta(godofor);
	printf("%s\n",resul);

	return 0;
}

void inserir(Arv *a, char nome[], int poder, int mortos, int mortes)
{
	if(*a == NULL)
	{
		Arv novo = (Arv) malloc(sizeof(struct no));
		novo->poder = poder;
		novo->mortos = mortos;
		novo->mortes = mortes;
		strcpy(novo->nome,nome);
		*a = novo;
	}
	else
	{
		Arv aux = *a;
		if(aux->poder < poder)
		{
			inserir(&(aux->dir),nome,poder,mortos,mortes);
		}
		else if(aux->poder == poder)
		{
			if(aux->mortos < mortos)
			{
				inserir(&(aux->dir),nome,poder,mortos,mortes);
			}else if(aux->mortos == mortos)
			{
				if(aux->mortes > mortes)
				{
					inserir(&(aux->dir),nome,poder,mortos,mortes);
				}
				else if(aux->mortes == mortes)
				{
					if(strcmp(nome,aux->nome) < 0)
					{
						inserir(&(aux->dir),nome,poder,mortos,mortes);
					}
					else
    					inserir(&(aux->esq),nome,poder,mortos,mortes);
				}
				else
    				inserir(&(aux->esq),nome,poder,mortos,mortes);
			}
			else
    		    inserir(&(aux->esq),nome,poder,mortos,mortes);
		}
		else
    		inserir(&(aux->esq),nome,poder,mortos,mortes);

	}
}

char *consulta(Arv a)
{
	if(a->dir == NULL)
	{
		return a->nome;
	}
	else
	{
		return consulta(a->dir);
	}
}