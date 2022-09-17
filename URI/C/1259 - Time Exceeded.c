// Time Limit Exceeded

#include<stdio.h>
#include<stdlib.h>

struct no
{
	int num;
	struct no *prox;
};

typedef struct no * Lista;

Lista criarLista();
void adicionarNaListaCrescente(Lista list, int num);
void adicionarNaListaDecrescente(Lista list, int num);
void imprimirLista(Lista list);

int main()
{
	int N, num;
	Lista pares = criarLista();
	Lista impares = criarLista();

	scanf("%d",&N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d",&num);
		if(num % 2 == 0)
			adicionarNaListaCrescente(pares, num);
		else
			adicionarNaListaDecrescente(impares, num);
	}

	imprimirLista(pares);
	imprimirLista(impares);

	return 0;
}

Lista criarLista()
{
	Lista cab = (Lista) malloc(sizeof(struct no));

	cab->prox = NULL;
	cab->num = 0;

	return cab;
}

void adicionarNaListaCrescente(Lista list, int num)
{
	// enquanto o ponteiro para nó não apontar para NULL
	while( list->prox != NULL && num > list->prox->num)
		list = list->prox;

	Lista Novo = (Lista) malloc(sizeof(struct no));
	Novo->num = num;

	Novo->prox = list->prox;
	list->prox = Novo;
}

void adicionarNaListaDecrescente(Lista list, int num)
{
	// enquanto o ponteiro para nó não apontar para NULL
	while( list->prox != NULL && num < list->prox->num)
		list = list->prox;

	Lista Novo = (Lista) malloc(sizeof(struct no));
	Novo->num = num;

	Novo->prox = list->prox;
	list->prox = Novo;
}

void imprimirLista(Lista list)
{
	while(list->prox != NULL)
	{
		printf("%d\n", list->prox->num);
		list = list->prox;
	}
}