#include <stdio.h>
#include <stdlib.h>

#define N 20 //quantidade maxima de bebidas
int quantidade = 0;//aquantidade de bebidas registradas

struct bebida
{
	char nome[20];
	int volume;
	float preco;
};
typedef struct bebida Bebida;

void inicializaVetor(Bebida **vet);
int escolha(int num, Bebida **vet);
void alocar(Bebida **vet);
void inserirRegistro(Bebida **vetor);
void apagarUltimo(Bebida **vetor);
void imprimirTabela(Bebida **vetor);


int main()
{
	Bebida **vetor = (Bebida **) malloc(sizeof(Bebida *) * N);//tabela com o maximo de 20 bebidas
	int num = 0;//armazena a escolha do usuario
	int retorno = 0;//retorno da funcao escolha
	int i = 0;

	inicializaVetor(vetor);

	while(1)
	{
		printf("\n------- Por favor, escolha uma opcao: -------\b");
		printf("\n1 - Inserir Registro\n2 - Apagar ultimo Registro\n3 - Imprimir tabela\n4 - Sair\n\n");
		scanf("%d",&num);

		retorno = escolha(num, vetor);

		if(retorno == -1)
			break;
	}

	free(vetor);

	return 0;
}

void inicializaVetor(Bebida **vet)
{
	int i = 0;

	for(i = 0; i < N; i++)
	{
		vet[i] = NULL;
	}
}

int escolha(int num, Bebida **vet)
{
	switch(num)
	{
		case 1:
			if(quantidade == 20)
			{
				printf("-----Quantidade Maxima de registros alcançada!-----");
				return 1;
			}
			alocar(vet);
			inserirRegistro(vet);
			return 1;
		case 2:
			if(quantidade == 0)
			{
				printf("\n----- Tabela vazia! -----");
				return 1;
			}

			apagarUltimo(vet);
			return 1;
		case 3:
			if(quantidade == 0)
			{
				printf("\n----- Tabela vazia! -----");
				return 1;
			}
			imprimirTabela(vet);
			return 1;
		case 4:
			return -1;
		default:
			printf("-----\nEntrada Invalida!-----\n");
			return 1;
	}
}

void alocar(Bebida **vet)
{
	vet[quantidade] = (Bebida *) malloc(sizeof(Bebida));
}

void inserirRegistro(Bebida **vetor)
{
	printf("\nInsira o nome da bebida:\n");
	scanf(" %[^\n]", vetor[quantidade]->nome);
	while(1)
	{
		printf("\nInsira o volume:\n");
		scanf("%d",&vetor[quantidade]->volume);
		printf("\nInsira o preço:\n");
		scanf("%f",&vetor[quantidade]->preco);

		if(vetor[quantidade]->volume < 0 || vetor[quantidade]->preco < 0 )
		{
			printf("---\nValores abaixo de zero não são permitidos---\n");
			continue;
		}

		break;
	}

	quantidade++;
}

void apagarUltimo(Bebida **vetor)
{
	free( vetor[quantidade - 1]);
	quantidade--;
}

void imprimirTabela(Bebida **vetor)
{
	int i = 0;

	for(i = 0; i < quantidade; i++)
	{
		printf("\n------Bebida #%d------\n", i + 1);
		printf("Nome: %s\n",vetor[i]->nome);
		printf("Volume: %d ml\n", vetor[i]->volume);
		printf("Preco: R$%.2f unidade\n",vetor[i]->preco);
	}
}