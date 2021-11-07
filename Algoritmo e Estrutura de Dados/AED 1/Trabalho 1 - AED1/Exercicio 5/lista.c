#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no {
    char info;
    struct no *prox;
};

Lista criaLista() {
    return NULL;
}

int listaVazia(Lista li) {
    if (li == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int insereInicio(Lista *li, char element) {
    Lista aux = *li;

    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL) {
        return 0;// Falha: nó não alocado
    }

    N->info = element;
    if(listaVazia(*li) == 1){
        N->prox = N;
        *li= N;
        return 1;
    }

    N->prox = aux->prox;
    aux->prox = N;
}

int insereFinal(Lista *li, char element) {
    // Aloca um novo nó e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL) {
        return 0;// Falha: nó não alocado
    }
    N->info = element; // Insere o conteúdo
    // Caso em uma lista vazia
    if (listaVazia(*li) == 1) {
        N->prox = N; // Faz o novo nó apontar para ele mesmo
        *li = N; // Faz a lista apontar para o novo nó (último nó)
    }
    // Caso já tenha elementos naa lista
    else {
        N->prox = (*li)->prox; // Faz o novo nó apontar o 1º nó
        (*li)->prox = N; // Faz o último nó apontar para o novo nó
        *li = N; // Faz a lista apontar para o novo nó (último nó)
    }
    return 1;
}

int removeInicio(Lista *li, char *element) {
    // Trata lista vazia
    if (listaVazia(*li) == 1) {
        return 0;
    }
    Lista aux = (*li)->prox; // Faz aux apontar para 1o nó
    *element = aux->info; // Retorna valor do nó a ser removido
    if (*li == (*li)->prox) {
        *li = NULL;// Trata lista com 1 único nó
    }
    else {
        (*li)->prox = aux->prox;// Trata lista com + de 1 elemento
    }
    free(aux);
    return 1;
}

int imprimeLista(Lista li) {
    Lista aux = li;

    if(listaVazia(li) == 1){
        printf("Lista vazia.\n");
        return 1;
        }

    aux = aux->prox; // Faz com que aux->info seja o primeiro elemento
    printf("Lista: ");
    while (aux != li) {
        printf("%c ", aux->info);
        aux = aux->prox;
    }
    printf("%c", li->info); // exibe o último elemento
    return 1;
}

int tamanho(Lista li) {
    Lista aux = li;
    int count = 0;
    do {
        count++;
        aux = aux->prox;
    }while (aux != li);
    return count;
}

int removePos(Lista *li, int posicao) {
    Lista aux = *li;
    aux = aux->prox;

    if (posicao == 1) {
        (*li)->prox = aux->prox;
        free(aux);
        return 1;
    }
    int i;
    for (i = 0; i < posicao - 2; i++) {
        aux = aux->prox;
    }
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

int inserePos(Lista *li, int posicao, char element) {


    if (posicao == 1) {
        insereInicio(li, element);
        return 1;
    }

    Lista aux = *li;
    aux = aux->prox; // Pula para o primeiro elemento da lista

   if (posicao == tamanho(*li) + 1) {
        insereFinal(li, element);
    }
    else {
        Lista N = (Lista) malloc(sizeof(struct no));
        if (N == NULL) {
            return 0;
        }
        N->info = element; // Insere o conteúdo

        int i;
        for (i = 2; i <= posicao - 1; i++) {
            aux = aux->prox;
        }
        N->prox = aux->prox;
        aux->prox = N;
        return 1;
    }
}

int remove_final(Lista *lst, char *elem){
if(listaVazia(*lst)==1)
    return 0;

    Lista aux = (*lst)->prox;

    if ((*lst)->prox == *lst){
        *elem = (*lst)->info;
        *lst = NULL;
    }else{
    while (aux->prox != *lst)
        aux = aux->prox;
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    *elem = aux2->info;
    *lst = aux;
    free(aux2);
    }
    return 1;
}


