#ifndef _GMA_ND_H
#define _GMA_ND_H

/*
	TAD referente a grafos implementados por matriz de adjascência (GMA) não direcionado (ND)

	Daniel Gonçalves
	2022
*/

typedef struct grafo * Grafo;

Grafo criarGrafo(int numVet);
int inserirAresta(Grafo g, int v1, int v2);
int removerAresta(Grafo g, int v1, int v2);
void exibirMatriz(Grafo g);
void exibirGrafo(Grafo g);
Grafo liberarGrafo(Grafo g);

#endif
