#include<stdlib.h>
#include"FES-DP.h"

struct fila
{
	int vetor[MAX];
	int ini, fim; // usando método em que ocorre disperdício de uma posição (ultima posição n é ocupada)
};


/*
criaFila
----------
Entrada: nenhuma
Descrição: cria uma fila e coloca ela no estado vazio 
Saida: tipo Fila
*/
Fila criaFila()
{
	Fila f = (Fila) malloc(sizeof(struct fila));
	if(f != NULL)
	{
		f->ini = 0; // inicio da fila
		f->fim = 0; // fim da fila (aponta para a proxima posição a ser preenchida)
	}

	return f;
}

/*
filaVazia
------------
Entrada: tipo fila
Descrição: verificar se a fila passada está vazia
Saída: 0, se há elementos
	   1, se a fila está vazia
*/
int filaVazia(Fila f)
{
	if(f->ini == f->fim)
		return 1;
	else
		return 0;
}

/*
filaCheia
-----------
Entrada: tipo fila
Descrição: verificar se a fila passada está cheia
Saída: 0, se não está cheia
       1, se está cheia
*/
int filaCheia(Fila f)
{
	if(f->ini == (f->fim + 1) % MAX)
		return 1;
	else
		return 0;
}

/*
insereFinal
-----------
Entrada: tipo Fila
         inteiro a ser inserido
Descrição: insere 'elem' no final da fila 'f'
Saída: 0, se a inserção falhar
       1, se a inserção ocorrer com sucesso
*/
int insereFinal(Fila f, int elem)
{
	if(filaCheia(f))
		return 0;
		
	f->vetor[f->fim] = elem;
	f->fim = (f->fim + 1) % MAX;
	
	return 1;
}

/*
removeInicio
-----------
Entrada: tipo fila
		 ponteiro para inteiro, onde será armazenado o elemento removido
Descrição: remove o elemento do início da fila e armazena ele em 'elem'
Saida: 0, se a remoção falhar
       1, em sucesso
*/
int removeInicio(Fila f, int *elem)
{
	if(filaVazia(f))
		return 0;
		
	*elem = f->vetor[f->ini];
	f->ini = (f->ini + 1) % MAX;
	
	return 1;
}

