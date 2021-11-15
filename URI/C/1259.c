#include<stdio.h>
#include<stdlib.h>

struct no
{
	int valor;
	struct no *dir;
	struct no *esq;
};

typedef struct no * Arv;

void inserir(Arv *v, int valor)
{
	if(*v == NULL)
	{
		Arv nova = (Arv) malloc(sizeof(struct no));

		nova->dir = nova->esq = NULL;
		nova->valor = valor;

		*v = nova;
	}
	else if(valor < (*v)->valor)
		inserir(&((*v)->dir), valor);
	else
		inserir(&((*v)->esq), valor); 
}

void percorrerEmOrdem(Arv v)
{
	if(v != NULL)
	{
		percorrerEmOrdem(v->dir);
		printf("%d\n", v->valor);
		percorrerEmOrdem(v->esq);
	}
}

void percorrerEmOrdemI(Arv v)
{
	if(v != NULL)
	{
		percorrerEmOrdemI(v->esq);
		printf("%d\n", v->valor);
		percorrerEmOrdemI(v->dir);
	}
}

int main()
{
	int N, num;
	Arv par = NULL, impar = NULL;

	scanf("%d",&N);

	for(int i = 0; i < N; i++)
	{
		scanf("%d",&num);

		if(num % 2 == 0)
		{
			inserir(&par,num);
		}
		else
		{
			inserir(&impar,num);
		}
	}

	percorrerEmOrdem(par);
	percorrerEmOrdemI(impar);

	return 0;
}