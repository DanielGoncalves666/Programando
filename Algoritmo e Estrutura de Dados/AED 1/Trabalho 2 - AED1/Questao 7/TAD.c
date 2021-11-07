//Implementação estática/sequencial com disperdício de posição de deque de inteiros

#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"

#define MAX 15

struct deque
{
	int vet[MAX];
	int ini, fim;
};

/*
cria_deque
----------
Entrada: nenhuma
Processo: realiza a alocação e coloca o deque em estado vazio.
Saída: tipo Deque, em sucesso, NULL, em falha
*/
Deque cria_deque()
{
	Deque d = (Deque) malloc(sizeof(struct deque));

	if(d != NULL)
	{
		d->ini = d->fim = 0;
		//ini indica a posição anterior do elemento que inicia a fila
		//fim indica a ultima posição ocupada
		//quando o deque está vazio, ini == fim 
	}

	return d;
}

/*
deque_vazio
-------------
Entrada: Tipo Deque
Processo: verifica se o deque está vazio
Saída: 1, se vazio, 0, se não vazio.
*/
int deque_vazio(Deque d)
{
	if(d->ini == d->fim)
		return 1;

	return 0;
}

/*
deque_cheio
------------
Entrada: Tipo Deque
Processo: verifica se o deque está cheio
Saída: 1, se cheio, 0, se não cheio.
*/
int deque_cheio(Deque d)
{
	//d->fim + 1 | é feito para compensar pela posição disperdiçada
	// % MAX | é feito pois temos uma fila circular
	if(d->ini == (d->fim + 1) % MAX)
		return 1;

	return 0;
}

/*
insere_inicio
-------------
Entrada: Tipo Deque e um inteiro
Processo: insere o inteiro passado como argumento no inicio do deque
Saída: 0, em falha, 1, em sucesso 
*/
int insere_inicio(Deque d, int elem)
{
	if(deque_cheio(d))
		return 0;

	d->vet[d->ini] = elem;
	//decremento circular
	if(d->ini == 0)
		d->ini = MAX - 1;
	else
		d->ini--;
	
	return 1;
}

/*
insere_final
------------
Entrada: Tipo Deque e um inteiro
Processo: insere o inteiro passado como argumento no final do deque
Saída: 0, em falha, 1, em sucesso.
*/
int insere_final(Deque d, int elem)
{
	if(deque_cheio(d))
		return 0;

	//incremento circular
	d->fim = (d->fim + 1) % MAX;

	d->vet[d->fim] = elem;

	return 1;
}

/*
remove_inicio
---------------
Entrada: Tipo Deque e endereço para um inteiro
Processo: remove o elemento no inicio da fila
Saída: 0, em falha, 1, em sucesso
*/
int remove_inicio(Deque d, int *elem)
{
	if(deque_vazio(d))
		return 0;

	//incremento circular
	d->ini = (d->ini + 1) % MAX;
	*elem = d->vet[d->ini];

	return 1;
}

/*
remove_final
------------
Entrada: Tipo Deque e endereço para um elemento
Processo: remove o elemento no final da fila
Saída: 0, em falha, 1, em sucesso
*/
int remove_final(Deque d, int *elem)
{
	if(deque_vazio(d))
		return 0;

	*elem = d->vet[d->fim];
	//decremento circular
	if(d->fim == 0)
		d->fim = MAX - 1;
	else	
		d->fim--;

	return 1;
}

/*
apagar_deque
------------
Entrada: Ponteiro para tipo Deque
Processo: Libera a memória do deque e seta o ponteiro para NULL
Saída: nenhuma
*/
void apagar_deque(Deque *d)
{
	free(*d);
	*d = NULL;
}