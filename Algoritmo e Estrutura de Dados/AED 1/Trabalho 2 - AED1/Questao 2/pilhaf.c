#include <stdlib.h>
#include "pilhaf.h"

struct no{
    float info;
    struct no *prox;
};

Pilha cria_pilha(){
    return NULL;
}

int pilha_vazia(Pilha p){
    if(p == NULL)
        return 1;
    else
        return 0;
}

int push(Pilha *p, float elem) {
    Pilha N = (Pilha)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;

    N->info = elem;
    N->prox = *p;
    *p = N;
    return 1;
}

int pop(Pilha *p, float *elem){
    if(pilha_vazia(*p))
        return 0;

    Pilha aux = *p;
    *elem = aux->info;
    *p = aux->prox;
    free(aux);
    return 1;
}

int le_topo(Pilha *p, float *elem){
    if(pilha_vazia(*p))
        return 0;
    *elem = (*p)->info;
    return 1;
}

int esvazia_pilha(Pilha *p){
    if(pilha_vazia(*p)==1)
        return 0;

    while(pilha_vazia(*p)==0){
        Pilha aux = *p;
        *p = aux->prox;
        free(aux);
    }
    return 1;
}
