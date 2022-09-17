#include<stdlib.h>
#include"FDE-ES.h"

struct no
{
	int valor;
	struct no *prox;
};

struct fila
{
	struct no *ini;
	struct no *fim;
};


/*
criaFila
----------
Entrada: nenhuma
Descrição: cria uma Fila e coloca ela no estado vazio
Saida: ponteiro para estrutura fila
*/
Fila criaFila()
{
	Fila nova = (Fila) malloc(sizeof(struct fila));
	if(nova != NULL)
		nova->ini = nova->fim = NULL;
		
	return nova;
}

/*
filaVazia
------------
Entrada: tipo Fila
Descrição: verificar se fika passada está vazia
Saída: 0, se há elementos
	   1, se a fila está vazia
*/
int filaVazia(Fila f)
{
	if(f->ini == NULL)
		return 1;
	else
		return 0;
}

// Função filaCheia não tem motivo para ser implementada já que o máximo de elementos da fila vai depender da memória disponível

/*
insereFinal
----------
Entrada: Tipo fila
		 inteiro a ser incluído na fila.
Descrição: Adiciona 'elem' no final de f
Saída: 0, se a inserção falhar
       1, se suceder
*/
int insereFinal(Fila f, int elem)
{
	struct no *novo = (struct no *) malloc(sizeof(struct no));
	if(novo == NULL)
		return 0;
		
	novo->valor = elem;
	novo->prox = NULL;

	if(filaVazia(f))
		f->ini = novo;
	else
		(f->fim)->prox = novo;
	
	f->fim = novo;
	
	return 1;
}

/*
removeInicio
-------------
Entrada: Tipo fila
         ponteiro para inteiro, indicando onde o valor removido deve ser armazenado
Descrição: remove o elemento no começo da fila
Saída: 0, se a remoção falhar
       1, se a remoção suceder
*/
int removeInicio(Fila f, int *elem)
{
	if(filaVazia(f))
		return 0;
		
	struct no *aux = f->ini;
	*elem = aux->valor;
	
	if(f->ini == f->fim)
		f->fim = NULL;	
	
	f->ini = aux->prox;
	free(aux);
	
	return 1;
}

