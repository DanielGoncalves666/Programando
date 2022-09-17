#ifndef _GMA_D_H
#define _GMA_D_H

/*
	TAD referente a grafos implementados por matriz de adjascência (GMA) direcionado (D)

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
