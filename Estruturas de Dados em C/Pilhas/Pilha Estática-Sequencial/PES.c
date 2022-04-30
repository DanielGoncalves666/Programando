#include<stdlib.h>
#include"PES.h"

struct pilha
{
	int vetor[MAX];
	int topo; // pode indicar a próxima posição livre ou a última ocupada. Usaremos indicando a última ocupada
};


/*
criaPilha
----------
Entrada: nenhuma
Descrição: cria uma pilha e coloca ela no estado vazio 
Saida: tipo Pilha
*/
Pilha criaPilha()
{
	Pilha p = (Pilha) malloc(sizeof(struct pilha));
	if(p != NULL)
		p->topo = -1;

	return p;
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
	if(p->topo == -1)
		return 1;
	else
		return 0;
}

/*
pilhaCheia
-----------
Entrada: tipo pilha
Descrição: verificar se a pilha passada está cheia
Saída: 0, se não está cheia
       1, se está cheia
*/
int pilhaCheia(Pilha p)
{
	if(p->topo == MAX - 1)
		return 1;
	else
		return 0;
}

/*
push
-----
Entrada: tipo Pilha
         inteiro, indicando o elemento a ser empilhadado
Descrição: coloca 'elem' no topo da pilha, se possível
Saída: 0, se o empilhamento falhar
       1, se o empilhamento suceder
*/
int push(Pilha p, int elem)
{
	if(pilhaCheia(p))
		return 0;
	
	p->topo++;
	p->vetor[p->topo] = elem;

	return 1;
}

/*
pop
----
Entrada: tipo Pilha
	     ponteiro para inteiro, indicando onde devemos armazenar o valor desempilhado
Descrição: retira o elemento no topo da pilha, se possível
Saída: 0, se o desempilhamento falhar
       1, se o desempilhamento suceder
*/
int pop(Pilha p, int *elem)
{
	if(pilhaVazia(p))
		return 0;
		
	*elem = p->vetor[p->topo];
	p->topo--;
	
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
		
	*elem = p->vetor[p->topo];
	
	return 1;
}


