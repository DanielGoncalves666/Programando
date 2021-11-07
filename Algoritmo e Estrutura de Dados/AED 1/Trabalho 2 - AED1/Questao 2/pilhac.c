#include <stdlib.h>
#include "pilhac.h"

struct no{
    char info_char;
    struct no *prox;
};

Pilhac cria_pilha_char(){
    return NULL;
}

int pilha_vazia_char(Pilhac p){
    if(p == NULL)
        return 1;
    else
        return 0;
}

int pushchar(Pilhac *p, char elem) {
    Pilhac N = (Pilhac)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;

    N->info_char = elem;
    N->prox = *p;
    *p = N;
    return 1;
}

int popchar(Pilhac *p, char *elem){
    if(pilha_vazia_char(*p))
        return 0;

    Pilhac aux = *p;
    *elem = aux->info_char;
    *p = aux->prox;
    free(aux);
    return 1;
}

int le_topo_char(Pilhac *p, char *elem){
    if(pilha_vazia_char(*p))
        return 0;
    *elem = (*p)->info_char;
    return 1;
}

int esvazia_pilha_char(Pilhac *p){
    if(pilha_vazia_char(*p))
        return 0;

    while(pilha_vazia_char(*p)==0){
        Pilhac aux = *p;
        *p = aux->prox;
        free(aux);
    }
    return 1;
}
