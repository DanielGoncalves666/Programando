#include<stdio.h>
#include<stdlib.h>

struct no
{
	int num;
	struct no *prox;
	struct no *ant;
};
typedef struct no Carta;

struct fila
{
	Carta *ini;
	Carta *fim;
};
typedef struct fila * Fila;

Fila criarFila();
void adicionar(Fila f, int num);
int remover(Fila f);
void LiberarFila(Fila f);
Fila descarte(Fila inicial);
void imprimir(Fila f);

int main()
{
	int num;
	Fila baralhoInicial;
	Fila baralhoDescartado;

	while(1)
	{
		scanf("%d",&num);
		if(num == 0)
			break;

		baralhoInicial = criarFila();
		for(int i = 1; i <= num; i++)
			adicionar(baralhoInicial,i);

		baralhoDescartado = descarte(baralhoInicial);		

		imprimir(baralhoDescartado);
		printf("\nRemaining card: %d\n",baralhoInicial->ini->num);

		LiberarFila(baralhoInicial);
		LiberarFila(baralhoDescartado);
	}

	return 0;
}

Fila criarFila()
{
	Fila nova = (Fila) malloc(sizeof(struct fila));
	nova->ini = nova->fim = NULL;

	return nova;
}

void adicionar(Fila f, int num)
{
	Carta * novo = (Carta *) malloc(sizeof(Carta));
	novo->num = num;

	if(f->fim == NULL)
	{
		f->ini = f->fim = novo;
		novo->prox = novo->ant = NULL;
	}
	else
	{
		f->fim->prox = novo;
		novo->ant = f->fim;
		novo->prox = NULL;

		f->fim = novo;
	}
}

int remover(Fila f)
{
	int num;

	if(f->ini == NULL)
		return -1;
	else if(f->ini == f->fim)
	{
		// apenas uma carta na fila
		Carta *aux = f->ini;
		num = aux->num;

		f->ini = f->fim = NULL;
		free(aux);

		return num;
	}
	else
	{
		Carta *aux = f->ini;
		num = aux->num;
		
		f->ini = aux->prox;
		f->ini->ant = NULL;
		if(f->ini->prox == NULL)
			f->fim = f->ini;

		free(aux);

		return num;
	}
}

void LiberarFila(Fila f)
{
	while(f->ini != NULL)
	{
		Carta *aux = f->ini;
		f->ini = aux->prox;

		free(aux);
	}

	free(f);
}

Fila descarte(Fila inicial)
{
	Fila descarte = criarFila();
	int num;

	while(inicial->ini != inicial->fim)
	{
		num = remover(inicial);// descarta a carta do topo;
		adicionar(descarte,num);//adiciona a carta descartada na "pilha" das descartadas

		num = remover(inicial);
		adicionar(inicial,num);//move a segunda carta para o fim da pilha
	}

	return descarte;
}

void imprimir(Fila f)
{
	Carta *aux = f->ini;
	
	printf("Discarded cards:");
	if(aux != NULL)
	{
		printf(" %d", aux->num);
	}

	while(aux->prox != NULL)
	{
		printf(", %d",aux->prox->num);
		aux = aux->prox;
	}
}