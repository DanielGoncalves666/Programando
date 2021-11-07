#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include "palavra.h"

typedef struct NO *Dicionario;

Dicionario *cria_Dicionario();
void libera_Dicionario(Dicionario* raiz);
int estaVazio_Dicionario(Dicionario *raiz);
int totalNO_Dicionario(Dicionario *raiz);

Palavra *consulta_Dicionario(Dicionario *raiz, char palavra[]);

int insere_Palavra(Dicionario *raiz, Palavra nova);
int remove_Palavra(Dicionario *raiz, char palavra[]);

void salvarPalavrasEmOrdem(FILE *arq, Dicionario raiz);
void salvarPalavrasPreOrdem(FILE *arq, Dicionario raiz);
void salvarPalavrasPosOrdem(FILE *arq, Dicionario raiz);

void calcularQuantidadePorLetra(Dicionario raiz, int *vetor);

#endif