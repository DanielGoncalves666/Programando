#include<stdio.h>
#include<stdlib.h>
#include"GMA-ND.h"

struct grafo
{
	int numVertices;
	int numArestas;
	int **mat;
};

static int **alocarMatriz(int linhas, int colunas);
static int **desalocarMatriz(int **mat, int qtd);

/*
alocarMatriz
-------------
Entrada: inteiro, indicando a quantidade de linhas da matriz
         inteiro, indicando a quantidade de colunas da matriz
Descrição: aloca uma matriz linhas x colunas de forma dinâmica
Saída: ponteiro para ponteiro de inteiros, contendo a matriz, se a alocação for possível, ou NULL, se não for possível.
*/
int **alocarMatriz(int linhas, int colunas)
{
	int **mat = (int **) malloc(sizeof(int *) * linhas);
	if(mat != NULL)
	{
		for(int i = 0; i < colunas; i++)
		{
			mat[i] = (int *) calloc(colunas,sizeof(int));
			if(mat[i] == NULL)
			{
				mat = desalocarMatriz(mat, i);
				break;
			}
		}
	}

	return mat;
}

/*
desalocarMatriz
----------------
Entrada: ponteiro para ponteiro de inteiros
         inteiro, indicando a quantidade de linhas que já foram ocupadas e precisam ser liberadas
Descrição: libera a memória alocada para a matriz recebida
Saída: NULL, para setar o ponteiro que representa a matriz passada
*/
int **desalocarMatriz(int **mat, int qtd)
{
	for(int i = 0; i < qtd; i++)
		free(mat[i]);
		
	free(mat);
	return NULL;
}

// ----------------------------------------------------------------------------------------------- // 

/*
criarGrafo
-----------
Entrada: inteiro, indicando a quantidade de vértices no grafo
Descrição: aloca uma estrutura grafo e coloca ela no estado vazio
Saída: ponteiro para estrutura grafo
*/
Grafo criarGrafo(int numVet)
{
	if(numVet <= 0)
		return NULL;

	Grafo g = (Grafo) malloc(sizeof(struct grafo));
	if(g != NULL)
	{
		g->mat = alocarMatriz(numVet,numVet);
		if(g->mat == NULL)
			free(g);
		else
		{
			g->numVertices = numVet;
			g->numArestas = 0;
		}
	}

	return g;
}

/*
inserirAresta
-------------
Entrada: tipo Grafo
         inteiro, indicando a primeira ponta da aresta
         inteiro, indicando a segunda ponta da aresta
Descrição: insere a aresta (v1,v2) no grafo, caso v1 e v2 existam. Todas as arestas são não-direcionadas
Saída: 0, se a operação de inserção falhar
       1, se a operação suceder
*/
int inserirAresta(Grafo g, int v1, int v2)
{
	if(g == NULL)
		return 0;
		
	if(v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices)
		return 0; // vértices inexistentes 

	if(g->mat[v1][v2] != 0) // não permite a criação de muiti-grafos
		return 0;
		
	g->mat[v1][v2] = 1;
	g->mat[v2][v1] = 1;
	g->numArestas++;

	return 1;
}

/*
removerAresta
--------------
Entrada: tipo Grafo
         inteiro, indicando a primeira ponta da aresta
         inteiro, indicando a segunda ponta da aresta
Descrição: remove a aresta (v1,v2) do grafo, se ela exitir. Todas as arestas são não-direcionadas
Saída: 0, se a operação de remoção falhar
       1, se a operação suceder
*/
int removerAresta(Grafo g, int v1, int v2)
{
	if(g == NULL)
		return 0;
		
	if(v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices)
		return 0; // vértices inexistentes
		
	if(g->mat[v1][v2] == 0)
		return 0;
		
	g->mat[v1][v2] = 0;
	g->mat[v2][v1] = 0;
	g->numArestas--;
	
	return 1;
}

/*
exibirMatriz
-------------
Entrada: tipo Grafo
Descrição: imprime o conteúdo da matriz de adjascências do grafo.
Saída: nenhuma
*/
void exibirMatriz(Grafo g)
{
	printf("\n Grafo - Matriz %d x %d\n", g->numVertices, g->numVertices);
	
	for(int i = 0; i < g->numVertices; i++)
	{
		printf("%2d:", i);
		for(int h = 0; h < g->numVertices; h++)
		{
			printf(" %d",g->mat[i][h]);
		}
		printf("\n");
	}
}

/*
exibirGrafo
------------
Entrada: tipo Grafo
Descrição: exibe um resumo dos vértices e seus vizinhos
Saída: nenhuma
*/
void exibirGrafo(Grafo g)
{
	printf("\n Grafo - Vizinhos\n");
	
	for(int i = 0; i < g->numVertices; i++)
	{
		printf("%2d:",i);
		for(int h = 0; h < g->numVertices; h++)
		{
			if(g->mat[i][h] == 1)
				printf(" %2d",h);
		}
		printf("\n");
	}
}

/*
liberarGrafo
-------------
Entrada: tipo Grafo
Descrição: desaloca as estruturas relacionados ao grafo
Saída: NULL, para setar o ponteiro para estrutura grafo
*/
Grafo liberarGrafo(Grafo g)
{
	if(g != NULL)
	{
		g->mat = desalocarMatriz(g->mat, g->numVertices);
		free(g);
		g = NULL;
	}
	
	return g;
}
