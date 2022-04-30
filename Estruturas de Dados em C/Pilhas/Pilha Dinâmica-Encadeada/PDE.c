#include<stdlib.h>
#include"PDE.h"

struct no
{
	int valor;
	struct no * prox;
};


/*
criaPilha
----------
Entrada: nenhuma
Descrição: retorna uma pilha no estado vazio
Saida: tipo Pilha
*/
Pilha criaPilha()
{
	return NULL;
}

/*
pilhaVazia
------------
Entrada: tipo pilha
Descrição: verificar se a pilha passada está vazia
Saída: 0, se há elementos
	   1, se a lista está vazia
*/
int pilhaVazia(Pilha p)
{
	if(p == NULL)
		return 1;
	else
		return 0;
}

// pilhaCheia não faz sentido ser implementada pois o número máximo de elementos depende da memória disponível

/*
push
-----
Entrada: ponteiro para tipo Pilha
         inteiro, indicando o elemento a ser empilhadado
Descrição: coloca 'elem' no topo da pilha, se possível
Saída: 0, se o empilhamento falhar
       1, se o empilhamento suceder
*/
int push(Pilha *p, int elem)
{
	Pilha novo = (Pilha) malloc(sizeof(struct no));
	if(novo == NULL)
		return 0;
		
	novo->valor = elem;	
	novo->prox = *p;
	*p = novo;
	
	return 1;
}

/*
pop
----
Entrada: ponteiro para tipo Pilha
	     ponteiro para inteiro, indicando onde devemos armazenar o valor desempilhado
Descrição: retira o elemento no topo da pilha, se possível
Saída: 0, se o desempilhamento falhar
       1, se o desempilhamento suceder
*/
int pop(Pilha *p, int *elem)
{
	if(pilhaVazia(*p))
		return 0;
		
	Pilha aux = *p;
		
	*elem = aux->valor;
	*p = aux->prox;
	
	free(aux);
		
	return 1;
}

/*
leTopo
--------
Entrada: tipo Pilha
		 ponteiro para inteiro, indicando onde o valor do topo deve ser armazenado
Descrição: consulta o elemento no topo da pilha
Saída: 0, se a consulta falhar
       1, se a consulta suceder
*/
int leTopo(Pilha p, int *elem)
{
	if(pilhaVazia(p))
		return 0;
		
	*elem = p->valor;
	
	return 1;
}


