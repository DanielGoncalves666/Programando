#include<stdlib.h>
#include"DES.h"

struct deque
{
	int vetor[MAX];
	int ini, cont; // o fim é obtido por meio de ini e cont
};


/*
criaDeque
----------
Entrada: nenhuma
Descrição: cria um deque e coloca ele no estado vazio 
Saida: tipo Deque
*/
Deque criaDeque()
{
	Deque d = (Deque) malloc(sizeof(struct deque));
	if(d != NULL)
	{
		d->ini = 0; // inicio da deque
		d->cont = 0; // quantidade de elementos no deque
	}

	return d;
}

/*
dequeVazio
------------
Entrada: tipo deque
Descrição: verificar se o deque passado está vazio
Saída: 0, se há elementos
	   1, se a deque está vazio
*/
int dequeVazio(Deque d)
{
	if(d->cont == 0)
		return 1;
	else
		return 0;
}

/*
dequeCheio
-----------
Entrada: tipo deque
Descrição: verificar se a deque passada está cheio
Saída: 0, se não está cheio
       1, se está cheio
*/
int dequeCheio(Deque d)
{
	if(d->cont == MAX)
		return 1;
	else
		return 0;
}

/*
insereInicio
-----------
Entrada: tipo Deque
         inteiro a ser inserido
Descrição: insere 'elem' no inicio do deque 'd'
Saída: 0, se a inserção falhar
       1, se a inserção ocorrer com sucesso
*/
int insereInicio(Deque d, int elem)
{
	if(dequeCheio(d))
		return 0;
	
	d->ini = d->ini > 0 ? (d->ini - 1) : (MAX - 1);
	d->vetor[d->ini] = elem;
	d->cont++;
	
	return 1;
}

/*
insereFinal
-----------
Entrada: tipo Deque
         inteiro a ser inserido
Descrição: insere 'elem' no final do deque 'd'
Saída: 0, se a inserção falhar
       1, se a inserção ocorrer com sucesso
*/
int insereFinal(Deque d, int elem)
{
	if(dequeCheio(d))
		return 0;
		
	d->vetor[(d->ini + d->cont) % MAX] = elem;
	d->cont++;
	
	return 1;
}

/*
removeInicio
-----------
Entrada: tipo deque
		 ponteiro para inteiro, onde será armazenado o elemento removido
Descrição: remove o elemento do início do deque e armazena ele em 'elem'
Saida: 0, se a remoção falhar
       1, em sucesso
*/
int removeInicio(Deque d, int *elem)
{
	if(dequeVazio(d))
		return 0;
		
	*elem = d->vetor[d->ini];
	d->ini = (d->ini + 1) % MAX;
	d->cont--;
	
	return 1;
}

/*
removeFinal
-----------
Entrada: tipo deque
		 ponteiro para inteiro, onde será armazenado o elemento removido
Descrição: remove o elemento do final do deque e armazena ele em 'elem'
Saida: 0, se a remoção falhar
       1, em sucesso
*/
int removeFinal(Deque d, int *elem)
{
	if(dequeVazio(d))
		return 0;
		
	*elem = d->vetor[(d->ini + d->cont - 1) % MAX];
	d->cont--;
	
	return 1;
}
