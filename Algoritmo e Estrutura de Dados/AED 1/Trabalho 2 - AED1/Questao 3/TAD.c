#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"

struct fila
{
	char placa[MAX][QTD];
	char tipo_servico[MAX];
	int hora[MAX], minuto[MAX];

	int ini, cont;
};

/*
cria_fila
-----------
Entrada: nenhuma
Processo: cria uma fila do tipo 'struct fila' e a coloca no estado vazio
Saída: endereço da fila criada
*/
Fila cria_fila()
{
	Fila f = (Fila) malloc(sizeof(struct fila));

	if(f != NULL)
		f->ini = f->cont = 0;

	return f;
}

/*
fila_vazia
-----------
Entrada: endereço de uma fila
Processo: verifica se a fila está vazia
Saida: 1, se vazia, 0, se não vazia.
*/
int fila_vazia(Fila f)
{
	if(f->cont == 0)
		return 1;

	return 0;
}

/*
fila_cheia
-----------
Entrada: endereço de uma fila
Processo: verifica se a fila está cheia
Saída: 1, se cheia, 0, se não cheia
*/
int fila_cheia(Fila f)
{
	if(f->cont == MAX)
		return 1;

	return 0;
}

/*
insere_fim
------------
Entrada: Tipo fila, string, caractere e dois inteiros
Processo: insere um elemno no fim da fila
Saída: 0, em falha, 1, em sucesso
*/
int insere_fim(Fila f, char plate[], char service, int hour, int minute)
{
	if(fila_cheia(f))
		return 0;

	int fim = (f->ini + f->cont) % MAX;

	strcpy(f->placa[fim],plate);
	f->tipo_servico[fim] = service;
	f->hora[fim] = hour;
	f->minuto[fim] = minute;

	f->cont++;

	return 1;
}

/*
Entrada: Tipo fila, string, ponteiro para caracteres e ponteiros para dois inteiros
Processo: remove o elemento no início da fila
Saída: 0, pra falha, 1, pra sucesso
*/
int remove_ini(Fila f, char plate[], char *service, int *hour, int *minute)
{
	if(fila_vazia(f))
		return 0;

	strcpy(plate,f->placa[f->ini]);
	*service = f->tipo_servico[f->ini];
	*hour = f->hora[f->ini];
	*minute = f->minuto[f->ini];

	f->ini = (f->ini + 1) % MAX;
	f->cont--;

	return 1;
}

/*
tamanho
--------
Entrada: Tipo Fila
Processo: verifica o tamanho da fila
Saída: o tamanho da fila
*/
int tamanho(Fila f)
{
	return f->cont;
}