//deque de caracteres implementado dinâmico/encadeado (circular)

#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"

struct no
{
	char info;
	struct no *prox;
	struct no *ant;
};

struct deque
{
	struct no *ini;
	struct no *fim;
};

/*
cria_deque
----------
Entrada: nenhuma
Processo: aloca um tipo 'struct deque' e o seta para o estado vazio
Saída: Tipo Deque
*/
Deque cria_deque()
{
	Deque d = (Deque) malloc(sizeof(struct deque));

	if(d != NULL)
	{
		d->ini = d->fim = NULL;
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
	if(d->ini == NULL)
		return 1;

	return 0;
}

/* A operação deque_cheio não existe. Tal condição só é atingida
se toda a memória tiver sido usada */

/*
insere_inicio
--------------
Entrada: Tipo deque e um caractere
Processo: realiza a inserção de um elemento no inicio do deque
Saída: 0, em falha, 1, em sucesso
*/
int insere_inicio(Deque d, char elem)
{
	struct no *novo = (struct no *) malloc(sizeof(struct no));
	
	if(novo == NULL)
		return 0;

	novo->info = elem;//armazena o elemento
	novo->ant = NULL;//nenhum elemento antes, coloca em NULL
	if(deque_vazio(d))
	{
		d->fim = novo;//se o deque estiver vazio, o fim vai apontar para este nó também.
		novo->prox = NULL;//unico elemento do deque, seta prox para NULL
	}
	else
	{
		novo->prox = d->ini;//o novo nó passará a apontar para o antigo primeiro
		d->ini->ant = novo;//o antigo primeiro passa a apontar para o novo
	}

	d->ini = novo;

	return 1;
}

/*
insere_final
-------------
Entrada: Tipo deque e um caractere
Processo: realiza a inserção de um elemento no final do deque
Saída: 0, em falha, 1, em sucesso
*/
int insere_final(Deque d, char elem)
{
	struct no *novo = (struct no *) malloc(sizeof(struct no));
	
	if(novo == NULL)
		return 0;

	novo->info = elem;
	novo->prox = NULL;//nenhum elemento depois, coloca em NULL
	if(deque_vazio(d))
	{
		d->ini = novo;//se o deque estiver vazio, o inicio também apontará para o novo nó
		novo->ant = NULL;//unico elemento do deque, seta ant para NULL
	}
	else
	{
		novo->ant = d->fim;//o novo nó passará a apontar para o antigo último
		d->fim->prox = novo;//o antigo ultimo passa a apontar para o novo
	}

	d->fim = novo;

	return 1;	
}

/*
remove_inicio
-------------
Entrada: Tipo deque e um endereço para caractere
Processo: remove o elemento no inicio do deque
Saída: 0, em falha, 1, em sucesso
*/
int remove_inicio(Deque d, char *elem)
{
	if(deque_vazio(d))
		return 0;

	struct no *aux = d->ini;
	*elem = aux->info;

	if(d->ini == d->fim)//caso tenha apenas um elemento no deque, ambos ini e fim precisam apontar para NULL
		d->ini = d->fim = NULL;
	else
	{
		d->ini = aux->prox;//o inicio passará a apontar para o segundo elemento
		d->ini->ant = NULL;//o novo primeiro elemento apontará para NULL como anterior
	}

	free(aux);

	return 1;
}

/*
remove_final
------------
Entrada: Tipo deque e um endereço para caractere
Processo: remove o elemento no final do deque
Saída: 0, em falha, 1, em sucesso
*/
int remove_final(Deque d, char *elem)
{
	if(deque_vazio(d))
		return 0;

	struct no *aux = d->fim;
	*elem = aux->info;

	if(d->ini == d->fim)//caso tenha apenas um elemento no deque, ambos ini e fim precisam apontar para NULL
		d->ini = d->fim = NULL;
	else
	{
		d->fim = aux->ant;//o fim passará a apontar para o penultimo elemento
		d->fim->prox = NULL;//o novo ultimo elemento apontará para NULL como proximo
	}

	free(aux);

	return 1;
}

/*
apagar_deque
-------------
Entrada: Endereço para o tipo Deque
Processo: desaloca todos os elementos no deque e por fim o deque, setando o ponteiro para NULL no final
Saída: nenhuma
*/
void apagar_deque(Deque *d)
{
	struct no *aux;

	if(*d != NULL)//a fila precisa existir
	{
		//caso o deque ja estiver vazio, esse laço é pulado
		while((*d)->ini != NULL)
		{
			aux = (*d)->ini;
			(*d)->ini = aux->prox;

			free(aux);
		}

		free(*d);

		*d = NULL; 
	}
}