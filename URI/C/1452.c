#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct no
{
	int id;
	struct no *prox;
};
typedef struct no * Servidores;

// essa estrutura armazena o nome da apliação e os ID's dos servidores que a provém.
// os ID's são numerados de 0 até N - 1, na ordem de entrada dos servidores.
struct aplicacao
{
	char nome[21];
	Servidores servers;
	struct aplicacao *prox;
};
typedef struct aplicacao *Aplicacoes;

void adicionar(Aplicacoes *apl, int qtd, int id);
void adicionarConexao(Aplicacoes apl, int **matriz, int qtd, int id);
struct aplicacao *buscarAplicacao(Aplicacoes apl, char nome[]);
int contarConexoes(int **matriz, int qtdServidores, int qtdClientes);
void liberarListaServidores(Aplicacoes *apl);

int main()
{
	int N, M, qtd;
	int **matrizAdjacencia;
	Aplicacoes apl = NULL;

	while(1)
	{
		scanf("%d %d",&N,&M);

		if(N == 0 && M == 0)
			break;

		matrizAdjacencia = (int **) malloc(sizeof(int *) * (N + M));
		for(int i = 0; i < (N + M); i++)
			matrizAdjacencia[i] = (int *) calloc(N + M, sizeof(int));

		// servidores
		for(int i = 0; i < N; i++)
		{
			scanf("%d",&qtd);
			adicionar(&apl,qtd,i);
		}

		// clientes
		for(int i = N; i < N + M; i++)
		{
			scanf("%d",&qtd);
			adicionarConexao(apl,matrizAdjacencia,qtd, i);// i -> id do jogador + quantidade de servidores
		}

		int total = contarConexoes(matrizAdjacencia, N,M);
		printf("%d\n",total);

		for(int i = 0; i < (N + M); i++)
			free(matrizAdjacencia[i]);
		free(matrizAdjacencia);

		liberarListaServidores(&apl);
	}

	return 0;
}

void adicionar(Aplicacoes *apl, int qtd, int id)
{
	char nome[21];
	
	for(int i = 0; i < qtd; i++)
	{
		scanf(" %s", nome);
		
		if(*apl == NULL)
		{
			// adiciona a primeira aplicação

			Aplicacoes novo = (Aplicacoes) malloc(sizeof(struct aplicacao));
			Servidores server = (Servidores) malloc(sizeof(struct no));
			server->id = id;
			server->prox = NULL;
			
			strcpy(novo->nome,nome);
			novo->servers = server;
			novo->prox = NULL;

			*apl = novo;
		}
		else
		{
			if(strcmp((*apl)->nome, nome) == 0)
			{
				// adiciona um servidor na primeira aplicação da lista

				Servidores server = (Servidores) malloc(sizeof(struct no));
				server->id = id;
				
				Aplicacoes aux = *apl;
				server->prox = aux->servers;
				aux->servers = server;
			}
			else
			{
				Servidores server = (Servidores) malloc(sizeof(struct no));
				server->id = id;
				
				Aplicacoes aux = *apl;
				while(aux->prox != NULL && strcmp(aux->prox->nome,nome) != 0)
					aux = aux->prox;

				if(aux->prox == NULL)
				{
					// adiciona uma nova aplicação
					server->prox = NULL;

					Aplicacoes novo = (Aplicacoes) malloc(sizeof(struct aplicacao));
					strcpy(novo->nome,nome);
					novo->servers = server;

					novo->prox = *apl;
					*apl = novo;
				}
				else
				{
					// adiciona um novo servidor em uma aplicação já existente
				
					server->prox = aux->prox->servers;
					aux->prox->servers = server;
				}			
			}
		}
	}
}

void adicionarConexao(Aplicacoes apl, int **matriz, int qtd, int id)
{
	char nome[21];
	Aplicacoes aplEscolhida;

	for(int i = 0; i < qtd; i++)
	{
		scanf(" %s",nome);
		aplEscolhida = buscarAplicacao(apl,nome);
		if(aplEscolhida == NULL)// se retornar NULL é pq aquela aplicação não existe
			continue;

		Servidores aux = aplEscolhida->servers;
		while(aux != NULL)
		{
			matriz[aux->id][id] = 1;// ligação entre o servidor e o usuario
			matriz[id][aux->id] = 1;// ligação entre o usuario e o servidor
			aux = aux->prox;
		}
	}

}

struct aplicacao *buscarAplicacao(Aplicacoes apl, char nome[])
{
	if(apl == NULL)
		return NULL;

	if(strcmp(apl->nome,nome) == 0)
	{
		return apl;
	}
	else
	{
		while(apl->prox != NULL && strcmp(apl->prox->nome,nome) != 0)
			apl = apl->prox;

		return apl->prox;
	}
}

int contarConexoes(int **matriz, int qtdServidores, int qtdClientes)
{
	int qtd = 0;

	for(int i = 0; i < qtdServidores; i++)
	{
		for(int h = qtdServidores; h < qtdServidores + qtdClientes; h++)
		{
			if(matriz[i][h] == 1)
				qtd++;
		}
	}

	return qtd;
}

void liberarListaServidores(Aplicacoes *apl)
{
	Aplicacoes aux = *apl;

	while(aux != NULL)
	{
		while(aux->servers != NULL)
		{
			Servidores a = aux->servers;
			aux->servers = a->prox;
			free(a);
		}
		Aplicacoes ap = aux;
		aux = ap->prox;
		free(aux);
	}

	*apl = NULL;
}


//				1 2 3 1 2
//Servidor 1		  1 0
//Servidor 2          0 0
//Servidor 3	      0 0
//Cliente 1		1 0 0    
//Cliente 2		0 0 0    