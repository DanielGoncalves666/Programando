#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct no
{
	char lingua[30];
	char mensagem[30];
	struct no *esq, *dir;
};

typedef struct no *Arv;

void inserir(Arv *a, char lingua[], char mensagem[]);
char *consulta(Arv a, char lingua[]);

int main()
{
	Arv a = NULL;
	int N, M;
	char lingua[30], mensagem[30], nome[30], *resul;

	scanf("%d",&N);
	for(int i = 0; i < N; i++)
	{
		scanf(" %s",lingua);
		scanf(" %[^\n]",mensagem);
		inserir(&a,lingua,mensagem);
	}

	scanf("%d",&M);
	for(int i = 0; i < M; i++)
	{
		scanf(" %[^\n]",nome);
		scanf(" %s",lingua);
		resul = consulta(a,lingua);

		printf("%s\n",nome);
		printf("%s\n\n",resul);
	}

	return 0;
}

void inserir(Arv *a, char lingua[], char mensagem[])
{
	if(*a == NULL)
	{
		Arv nov = (Arv) malloc(sizeof(struct no));
		strcpy(nov->lingua,lingua);
		strcpy(nov->mensagem,mensagem);
		nov->dir = nov->esq = NULL;
		*a = nov;
	}
	else
	{
		Arv aux = *a;
		if(strcmp(lingua,aux->lingua) < 0)
		{
			inserir(&(aux->esq),lingua,mensagem);
		}
		else
		{
			inserir(&(aux->dir),lingua,mensagem);
		}
	}
}

char *consulta(Arv a, char lingua[])
{
	if(a == NULL)
		return NULL;
	else
	{
		if(strcmp(lingua,a->lingua) < 0)
			return consulta(a->esq,lingua);
		else if(strcmp(lingua,a->lingua) > 0)
			return consulta(a->dir,lingua);
		else
			return a->mensagem;
	}
}