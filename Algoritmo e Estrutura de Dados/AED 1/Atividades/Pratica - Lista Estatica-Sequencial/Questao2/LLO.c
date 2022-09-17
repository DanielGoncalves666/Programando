//Lista Linear ordenada

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../include/LLO.h"

#define MAX 20

struct bebida{
	char nome[lim];
	int volume;
	float preco;
};
typedef struct bebida bebida;

struct llo
{
	bebida vetor[MAX];
	int FIM;
};

void insere_aux(struct bebida *aux, char nome[lim], int volume, float preco);
int compararBebidas(struct bebida um, char *dois, int volume);
void conversao_lower(char *vet);

/*
criar_lista
----------
Entrada: Nenhuma
Operação: Aloca uma estrutura do tipo 'struct llo' e seta FIM para zero
Saída: tipo ListaBebidas
*/
ListaBebidas criar_lista()
{
	ListaBebidas p = (ListaBebidas) malloc(sizeof(struct llo));

	if(p != NULL)
		p->FIM = 0;

	return p;
}

/*
lista_vazia
----------
Entrada: tipo ListaBebidas
Operação: verifica se a lista está vazia
Saída: 0, para não, 1, para sim
*/
int lista_vazia(ListaBebidas p)
{	
	if(p->FIM == 0)
		return 1;

	return 0;
}

/*
lista_cheia
----------
Entrada: tipo ListaBebidas
Operação: verifica se a lista está cheia
Saída: 0, para não, 1, para sim
*/
int lista_cheia(ListaBebidas p)
{
	if(p->FIM == MAX)
		return 1;

	return 0;
}

/*
apaga_lista
----------
Entrada: tipo ListaBebidas
Operação: desaloca a estrutura lista
Saída: nenhuma
*/ 
void apaga_lista(ListaBebidas *p)
{
	free(*p);
	*p = NULL;
}

/*
insere_ord
----------
Entrada: tipo ListaBebidas, string, inteiro, float
Operação: insere um novo elemento na lista
Saída: 0, em fracasso, 1, em sucesso
*/
int insere_ord(ListaBebidas p, char nome[lim], int volume, float preco)
{
	if(p == NULL || lista_cheia(p) == 1)
		return 0;

	//lista vazia ou maior que o ultimo elemento
	if(lista_vazia(p) == 1 || compararBebidas(p->vetor[p->FIM - 1], nome, volume) == 1)
		insere_aux(&p->vetor[p->FIM],nome, volume, preco);
	else
	{
		//adicionar no meio da lista
		int i = 0, aux = 0;

		//procura pela posicao correta
		while( compararBebidas(p->vetor[aux],nome,volume) == 1)
			aux++;

		//deslocamento
		for(i = p->FIM; i > aux; i--)
			p->vetor[i] = p->vetor[i - 1];
		
		insere_aux(&p->vetor[aux],nome,volume,preco);

	}

	p->FIM++;

	return 1;
}

/*
insere_aux
-------------
Entrada: ponteiro para tipo struct bebida, string, inteiro e float 
Processo: preenche a estruta bebida com os dados.
Saida: nenhuma
*/
void insere_aux(struct bebida *aux, char nome[lim], int volume, float preco)
{
	strcpy(aux->nome,nome);
	aux->preco = preco;
	aux->volume = volume;
}

/*
remove_elem
----------
Entrada: tipo ListaBebidas, vetor de caracteres
Operação: remove um elemento da lista
Saída: 0, em fracasso, 1, em sucesso
*/
int remove_ord(ListaBebidas p, char string[lim])
{
	if(p == NULL || lista_vazia(p) == 1)
		return 0;
	
	int aux = 0, i = 0;

	while(aux < p->FIM && strcmp(string, p->vetor[aux].nome) != 0)
		aux++;

	if(aux == p->FIM)
		return 0;

	for(i = aux + 1; i < p->FIM; i++)
	{
		p->vetor[i - 1] = p->vetor[i];
	}

	p->FIM--;

	return 1;
}

/*
get_pos
----------
Entrada: tipo ListaBebidas, inteiro indicando a posição(1 até FIM)
Operação: retorna o conteúdo da posição indicada, se ela existe.
Saída: -1 ou NULL,em fracasso, 1 , em sucesso
*/
char *get_pos_nome(ListaBebidas p, int pos)
{
	if(p == NULL || pos <= 0 || pos > p->FIM)
		return NULL;

	return p->vetor[pos - 1].nome;
}

int get_pos_volume(ListaBebidas p, int pos)
{
	if(p == NULL || pos <= 0 || pos > p->FIM)
		return -1;

	return p->vetor[pos - 1].volume;
}

float get_pos_preco(ListaBebidas p, int pos)
{
	if(p == NULL || pos <= 0 || pos > p->FIM)
		return -1;

	return p->vetor[pos - 1].preco;
}

/*
compararBebidas
----------------
Entrada: tipo struct bebida, uma string, inteiro indicando volume 
Processo: decide qual bebida virá antes na lista.
Saida: 1, se for a bebida um, 2, se for a bebida 2
*/
int compararBebidas(struct bebida um, char *dois, int volume)
{
	conversao_lower(um.nome);
	conversao_lower(dois);

	int result = strcmp(um.nome, dois);

	if(result == 0)
	{
		if(um.volume <= volume)
			return 1;
		else
			return 2;
	}
	else if(result < 0)
		return 1;
	else
		return 2;
}

/*
conversao_lower
----------------
Entrada: uma string
Processo: converte a string para lowercase
Saida: nenhuma
*/
void conversao_lower(char *vet)
{
	int i = 0;
	while(vet[i] != '\0')
	{
		if(isalpha(vet[i]) != 0)
			vet[i] = tolower(vet[i]);
		
		i++;
	}
}