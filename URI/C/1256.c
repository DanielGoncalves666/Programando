#include<stdio.h>
#include<stdlib.h>

struct no 
{
	int num;
	struct no * prox;
};

typedef struct no Valor;

struct tabHash
{
	int tamanho;
	Valor **tab;
};

typedef struct tabHash TabelaHash;

TabelaHash *criarHash(int qtd);
void inserir(TabelaHash *st, int num);
void imprimirTabela(TabelaHash t);

int main()
{
	int N,M,C,valor;
	TabelaHash *tabela;

	scanf("%d",&N);
	for(int i = 0;;)
	{
		scanf("%d %d",&M,&C);
		tabela = criarHash(M);

		for(int j = 0; j < C; j++)
		{
			scanf("%d",&valor);
			inserir(tabela,valor);
		}

		imprimirTabela(*tabela);
		
		i++;
		if(i < N)
			printf("\n");
		else
			break;
	}

	return 0;
}

TabelaHash *criarHash(int qtd)
{
	TabelaHash* t = (TabelaHash *) malloc(sizeof(TabelaHash));

	t->tamanho = qtd;
	t->tab = (Valor **) malloc(sizeof(Valor *) * qtd);

	for(int i = 0; i < qtd; i++)
	{
		t->tab[i] = NULL;
	}

	return t;
}

void inserir(TabelaHash *t, int num)
{
	Valor *novo = (Valor *) malloc(sizeof(Valor));
	novo->num = num;
	novo->prox = NULL;

	int chave = num % t->tamanho;
	Valor *aux = t->tab[chave];
	if(aux == NULL)
		t->tab[chave] = novo;
	else
	{
		while(aux->prox != NULL)
			aux = aux->prox;

		aux->prox = novo;
	}
}

void imprimirTabela(TabelaHash t)
{
	for(int i = 0; i < t.tamanho; i++)
	{
		printf("%d ", i);

		Valor *aux = t.tab[i];

		while(aux != NULL)
		{
			printf("-> %d ", aux->num);
			aux = aux->prox;
		}

		printf("-> \\\n");
	}
}