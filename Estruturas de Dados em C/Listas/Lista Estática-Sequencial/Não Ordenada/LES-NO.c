#include"LES-NO.h"
#include<stdlib.h>

struct lista
{
	int vet[TAM];
	int fim; // indica a próxima posição livre
};

/*
criaLista
-----------
Entrada: nenhuma
Descrição: aloca uma instância da estrutura lista
Saída: ponteiro para uma Lista criada
*/
Lista criaLista()
{
	Lista lst;

	lst = (Lista) malloc(sizeof(struct lista));
	if(lst != NULL)
		lst->fim = 0; // coloca a lista no estado de vazia

	return lst;
}

/*
listaVazia
-----------
Entrada: ponteiro para uma lista
Descrição: verifica se a Lista passada está vazia
Saída:  0, se a lista não estiver vazia.
		1, se a lista estiver vazia.
*/
int listaVazia(Lista lst)
{
	if(lst->fim == 0)
		return 1; // lista vazia
	else 
		return 0; // lista não vazia
}

/*
listaCheia
-----------
Entrada: ponteiro para uma lista
Descrição: verifica se a lista passada está cheia
Saída:  0, se a lista não estiver cheia.
		1, se a lista estiver cheia.
*/
int listaCheia(Lista lst)
{
	if(lst->fim == TAM)
		return 1; // lista cheia
	else
		return 0; // lista não cheia
}

/*
insereElem
-----------
Entrada: ponteiro para uma lista
         inteiro à ser inserido
Descrição: insere 'elem' no final da lista, se possível
Saída: 0, se a inserção falhou
	   1, em sucesso
*/
int insereElem(Lista lst, int elem)
{
	if(lst == NULL || listaCheia(lst) == 1)
		return 0;

	lst->vet[lst->fim] = elem;
	lst->fim++;

	return 1;
}

/*
removeElem
-----------
Entrada: ponteiro para lista
	     inteiro indicando o elemento a ser removido
Descrição: percorre a lista e remove 'elem', se ele existir
Saída: 0, se a remoção falhou
	   1, em sucesso
*/
int removeElem(Lista lst, int elem)
{
	if(lst == NULL || listaVazia(lst) == 1)
		return 0;

	int i, aux = 0;

	// percorre até achar o elemento ou até o final da lista
	while(aux < lst->fim && lst->vet[aux] != elem)
		aux++;

	if(aux == lst->fim)
		return 0; // elemento não encontrado

	for(i = aux + 1; i < lst->fim; i++)
		lst->vet[i - 1] = lst->vet[i]; // deslocamento à esquerda até o final da lista
	// se ele for o último, nada acontece

	lst->fim--;

	return 1;
}

/*
existeElem
-----------
Entrada: ponteiro para lista
	     inteiro indicando o elemento a ser procurado
Descrição: verifica se pelo menos uma instância de 'elem' existe na lista
Saída: 0, se o elemento não está presente
	   1, se pelo menos uma instância do elemento está presente
*/
int existeElem(Lista lst, int elem)
{
	if(lst == NULL || listaVazia(lst) == 1)
		return 0;

	int i;

	for(i = 0; i < lst->fim; i++)
	{
		if(lst->vet[i] == elem)
			return 1;
	}

	return 0;
}

/*
obterValorElem
---------------
Entrada: ponteiro para lista
	     inteiro indicando o indice do elemento a ser retornado
	     ponteiro para inteiro, onde o elemento será armazenado se a operação tiver sucesso
Descrição: armazena em *elem o valor do elemento na posição 'indice'
Saída: 0, em fracasso
	   1, em sucesso

*/
int obterValorElem(Lista lst, int indice, int *elem)
{
	if(lst == NULL || indice < 0 || indice >= lst->fim)
		return 0;

	*elem = lst->vet[indice];
	
	return 1;
}


