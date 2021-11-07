#include <stdlib.h>
#include "Trabalho-ex2.h"

int const TAMANHO_MAX = 250;

struct lt
{
    char *vetor;
    int tamanho;
};


int contem(Lista l, char elem)
{
    for(int i=0; i < l->tamanho; i++)
    {
        if(l->vetor[i] ==  elem)
            return 1;
    }
    return 0;
}

Lista insere_ord(Lista l, char elem)
{
    if (lista_cheia(l) == 1)
        return l;  // Falha

    // Trata lista vazia ou elemento ≥ último da lista
    if (lista_vazia(l) == 1 || elem <= l->vetor[l->tamanho-1])
    {
        l->vetor[l->tamanho] = elem; // Insere no final
    }
    else
    {
        int i;
        // Deslocamento a direita para abrir espaco para o novo elem
        for (i = l->tamanho; (i > 0 && l->vetor[i-1] < elem); i--)
            l->vetor[i] = l->vetor[i-1];

        l->vetor[i] = elem; // Inclui o novo elemento na lista
    }
    l->tamanho++; // Avança o Fim
    return l; // Sucesso
}


int lista_vazia(Lista l)
{
    return l->tamanho == 0 ? 1 : 0;
}

int lista_cheia(Lista l)
{
    return l->tamanho == TAMANHO_MAX ? 1 : 0;
}

Lista limpa_lista(Lista l)
{
    if(lista_vazia(l))
        return l;

    l->tamanho = 0;
    return l;
}

Lista remove_pares(Lista l)
{
    if(lista_vazia(l))
        return l;

    Lista *LR = criar_lista();
    for(int i=0; i < l->tamanho; i++)
    {
        if(l->vetor[i] % 2 == 1)
            LR = insere_ord(LR, l->vetor[i]);
    }

    return LR;
}

int tamanho(Lista l)
{
    return l->tamanho;
}

char menor(Lista l)
{
    if(lista_vazia(l))
        return 0;

    return l->vetor[l->tamanho-1];
}

Lista criar_lista()
{
    Lista l = malloc(sizeof(Lista));
    l->tamanho = 0;
    l->vetor = malloc(TAMANHO_MAX*sizeof(char));
    return l;
}

Lista remove_elem(Lista l, char elem)
{
    int posicao  = -1;

    if(lista_vazia(l))
            return l;

    for(int i = 0; i < l->tamanho; i++)
    {
        if(l->vetor[i] == elem)
        {
            posicao = i;
            break;
        }
    }

    if(posicao == -1)
    {
        return l;
    }

    for(int i = posicao; i < l->tamanho; i++)
    {
        char temp = l->vetor[i];
        l->vetor[i] = l->vetor[i+1];
        l->vetor[i+1] = temp;
    }

    l->tamanho--;
    return l;
}

char get_posicao(Lista l, int posicao)
{
    return l->vetor[posicao];
}

Lista intercalar(Lista l1, Lista l2)
{
    for(int i=0; i < l2->tamanho; i++)
    {
        l1 = insere_ord(l1, l2->vetor[i]);
    }
    return l1;
}



