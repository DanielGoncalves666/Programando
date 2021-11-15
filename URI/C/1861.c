#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct assassino
{
	int vivo;	// 0 se morreu, 1 se continua vivo
	int quantidade;
	char nome[11];
	struct assassino *dir;
	struct assassino *esq;
};

typedef struct assassino *Hall;

struct no
{
	char nome[11];
	struct no *prox;
};

typedef struct no *Lista;

void adicionar(Hall *h, char nome[]);
void adicionarMorto(Lista *mortos, char nome[]);
void matar(Hall *h, char nome[]);
void imprimir(Hall h);

int main()
{
	char assassino[11], morto[11];
	Hall Assassinos = NULL;
	Lista Mortos = NULL;

	while(scanf("%s %s ",assassino,morto) != EOF)
	{
		adicionar(&Assassinos,assassino);
		adicionarMorto(&Mortos,morto);
	}

	matar(&Assassinos,morto);

	while(Mortos != NULL)
	{
		Lista aux = Mortos;
		matar(&Assassinos,aux->nome);
		Mortos = aux->prox;
		free(aux);
	}

	printf("HALL OF MURDERERS\n");
	imprimir(Assassinos);

	return 0;
}

void adicionar(Hall *h, char nome[])
{
	if(*h == NULL)
	{
		Hall novo = (Hall) malloc(sizeof(struct assassino));
		novo->vivo = 1;
		novo->quantidade = 1;
		strcpy(novo->nome,nome);
		novo->dir = novo->esq = NULL;
		
		*h = novo;
	}
	else
	{
		Hall aux = *h;

		if(strcmp(aux->nome,nome) > 0)
		{
			//nome do novo assassino é menor que o nome no nó
			adicionar(&(aux->esq),nome);
		}
		else if(strcmp(aux->nome,nome) < 0)
		{
			//nome do novo assassino é maior que o nome no nó
			adicionar(&(aux->dir),nome);
		}
		else
		{
			//o assassino já existe;
			aux->quantidade++;
		}
	}
}

void adicionarMorto(Lista *mortos, char nome[])
{
	Lista novo = (Lista) malloc(sizeof(struct no));
	strcpy(novo->nome,nome);
	novo->prox = *mortos;
	*mortos = novo;
}

void matar(Hall *h, char nome[])
{
	if(*h != NULL)
	{
		Hall aux = *h;

		if(strcmp(aux->nome,nome) > 0)
		{
			matar(&(aux->esq),nome);
		}
		else if(strcmp(aux->nome,nome) < 0)
		{
			matar(&(aux->dir),nome);
		}
		else
		{
			// o assassino morreu
			aux->vivo = 0;
		}
	}
}

void imprimir(Hall h)
{
	if(h != NULL)
	{
		imprimir(h->esq);
		if(h->vivo)
		{
			printf("%s %d\n",h->nome,h->quantidade);
		}

		imprimir(h->dir);
	}
}