/*
Este programa implementa o problema de Josephus utilizando o TAD lista.
Decidimos pela implementacao dinamica encadeada circular,
pois os soldados estao agrupados em um circulo e, dentro da logica do problema,
o sucessor do ultimo soldado sera o primeiro novamente e esta dinamica ocorrera algumas vezes durante a execucao.
Assim, uma aplicacao que facilite percorrer do ultimo para o primeiro, a circular, eh a melhor

Desenvolvido por:
    Arthur Resende Santos
    Daniel Gonçalves
    Henrique Braga
    Lorenzo Machado Burgos
  */

#include <stdlib.h>
#include <string.h>
#include "Trabalho-ex7.h"
#define MAX 30

struct no
{
    char nome[MAX];
    struct no *prox;
};

Lista criar_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if(lst == NULL)
        return 1; //vazia
    else
        return 0;
}

int escolha_nome(Lista *lst, char *nome)
{
    if(lista_vazia(*lst) == 1)
    {
        return 0;
    }
    if(strcmp((*lst)->nome, nome)==0)
    {
        return 1; //operacao concluida
    }

    Lista aux=*lst;
    *lst=(*lst)->prox;

    while(*lst != aux && strcmp((*lst)->nome, nome)!= 0)
    {
        *lst=(*lst)->prox;
    }
    if(*lst == aux)
    {
        return 0; //"fim" da lista e o elemento nao foi encontrado
    }
    else
    {
        return 1;//operacao concluida
    }
}

int escolha_pos(Lista *lst, int pos, char *nome)
{
    if(lista_vazia(*lst) == 1)
    {
        return 0;
    }

    int i;
    for(i = 1; i < pos ;i++)
    {
        *lst = (*lst)->prox;
    }

    strcpy(nome, (*lst)->nome);

    return 1; //operacao concluida
}

int insere_elem(Lista *lst, char *nome)
{
    Lista N;
    N = (Lista) malloc (sizeof(struct no));
    if(N==NULL)
    {
        return 0; // erro na alocacao
    }

    strcpy(N->nome, nome);

    if(lista_vazia(*lst) == 1)
    {
        *lst = N;
        N->prox = N;
        return 1;
    }

    N->prox = (*lst)->prox;
    (*lst)->prox = N;
    *lst = N;
    return 1;
}

int remove_pos(Lista *lst, int pos, int qnt, char *nome)
{
    if(lista_vazia(*lst) == 1)
    {
        return 0;
    }

    Lista aux=*lst;
    int i;

    for(i=1;i<pos;i++)
    {
        (*lst)=(*lst)->prox;
    }

    while(aux->prox != *lst)
    {
        aux=aux->prox;
    }
    Lista aux2 = *lst;

    strcpy(nome, (*lst)->nome);

    aux->prox = aux2->prox;
    (*lst) = (*lst)->prox;


    free(aux2);
    if(qnt == 1)
    {
        return -1;
    }
    return 1;
}

int get_nome(Lista lst, int pos, char *nome)
{
    if (pos < 1 || pos > tamanho(lst))
    {
        return 0;
    }
    for ( ;pos>0 ;pos--)
        lst = lst->prox;

    strcpy(nome, lst->nome);
    return 1;
}

int tamanho(Lista lst)
{
    if (lst == NULL)
        return (0);
    else
    {
        Lista aux;
        int cont;
        for (cont = 1, aux = lst->prox; aux != lst; cont++)
            aux = aux->prox;
        return cont;
    }
}


