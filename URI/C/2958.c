#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct no
{
	char classificacao[3];
	struct no *esq, *dir;
};

typedef struct no *Arv;

void inserir(Arv *a, char classificacao[]);
void percorrer(Arv v);

int main()
{
	int N, M;
	Arv vida = NULL;
	Arv disciplina = NULL;
	char classi[3];

	scanf("%d %d",&N,&M);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf(" %s",classi);
			if(classi[1] == 'V')
				inserir(&vida,classi);
			else
				inserir(&disciplina,classi);
		}
	}

	percorrer(vida);
	percorrer(disciplina);

	return 0;
}

void inserir(Arv *a, char classificacao[])
{
	if(*a == NULL)
	{
		Arv novo = (Arv) malloc(sizeof(struct no));
		strcpy(novo->classificacao,classificacao);
		novo->esq = novo->dir = NULL;
		*a = novo;
	}
	else
	{
		Arv aux = *a;
		if(classificacao[0] < aux->classificacao[0])
		{
			inserir(&(aux->esq),classificacao);
		}
		else
		{
			inserir(&(aux->dir),classificacao);
		}
	}
}

void percorrer(Arv v)
{
	if(v != NULL)
	{
		percorrer(v->dir);
		printf("%s\n",v->classificacao);
		percorrer(v->esq);
	}
}