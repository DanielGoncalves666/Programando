#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct no
{
	char nome[200];
	int peso, idade;
	double altura;
	struct no *dir;
	struct no *esq;
};

typedef struct no *Arv;

void adicionar(Arv *renas, char nome[], int peso, int idade, double altura);
void insere(Arv *renas, Arv novo);
int percorrerEmOrdem(Arv renas, int id, int limite);
void liberarArvore(Arv *renas);

int main()
{
	int T, N, M;
	int peso, idade;
	char nome[200];
	double altura;

	Arv Renas = NULL;

	scanf("%d",&T);
	for(int i = 0; i < T; i++)
	{
		scanf("%d %d",&N,&M);

		for(int j = 0; j < N; j++)
		{
			scanf(" %s %d %d %lf",nome,&peso,&idade,&altura);
			adicionar(&Renas,nome,peso,idade,altura);
		}

		printf("CENARIO {%d}\n", i + 1);
		percorrerEmOrdem(Renas, 0, M);

		liberarArvore(&Renas);
	}

	return 0;
}

void adicionar(Arv *renas, char nome[], int peso, int idade, double altura)
{
	Arv novo = (Arv) malloc(sizeof(struct no));
	strcpy(novo->nome,nome);
	novo->peso = peso;
	novo->idade = idade;
	novo->altura = altura;
	novo->dir = novo ->esq = NULL;

	insere(renas, novo);
}

void insere(Arv *renas, Arv novo)
{
	// como é descrescente, as Renas "maiores" vão pra esquerda

	if(*renas == NULL)
		*renas = novo;
	else if((*renas)->peso < novo->peso)
	{
		// caso a nova Rena tiver peso maior que a do nó
		insere(&((*renas)->esq),novo);
	}else if((*renas)-> peso > novo->peso)
	{
		// caso a nova Rena tiver peso menor que a do nó
		insere(&((*renas)->dir),novo);
	}
	else
	{
		//caso tenha o mesmo peso
		if( (*renas)->idade > novo->idade)
		{
			//idade da nova é menor que a do nó, então ela vai pra esquerda
			insere(&((*renas)->esq),novo);
		}
		else if( (*renas)->idade < novo->idade)
		{
			// idade da nova é maior que a do nó, então ela vai pra direita
			insere(&((*renas)->dir),novo);
		}
		else
		{
			//peso e idade iguais
			if( (*renas)->altura > novo->altura)
			{
				//altura da nova é menor que a do nó, então ela vai pra esquerda
				insere(&((*renas)->esq),novo);
			}
			else if( (*renas)->altura < novo->altura)
			{
				// altura da nova é maior que a do nó, então ela vai pra direita
				insere(&((*renas)->dir),novo);
			}
			else
			{
				//peso, idade e altura iguais
				if( strcmp((*renas)->nome,novo->nome) > 0)
				{
					//o nome da rena no nó é maior que o nome da nova rena, então ela vai pra esquerda
					insere(&((*renas)->esq),novo);
				}
				else
				{
					insere(&((*renas)->dir),novo);
				}
			}
		}
	}
}

// recebe 0 no começo como id
int percorrerEmOrdem(Arv renas, int id, int limite)
{
	int retorno = 0;

	if(renas != NULL && limite != id)
	{
		retorno += percorrerEmOrdem(renas->esq, id, limite);
		
		if(id + retorno != limite)
		{
			printf("%d - %s\n", 1 + id + retorno,renas->nome);
			retorno++;
		}

		if(id + retorno != limite)
			retorno += percorrerEmOrdem(renas->dir, id + retorno,limite);
	
		return retorno;
	}

	return 0;
}

void liberarArvore(Arv *renas)
{
	if(*renas != NULL)
	{
		liberarArvore(&((*renas)->esq));
		liberarArvore(&((*renas)->dir));

		free(*renas);
		*renas = NULL;
	}
}