#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct no{
    Pessoa info;
    struct no *prox;
};

struct fila{
    struct no *ini;
    struct no *fim;
};

Fila cria_fila(){
    Fila f;

    f = (Fila) malloc(sizeof(struct fila));
    if(f != NULL){
        f->ini = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_vazia(Fila f){
    if(f->ini == NULL)
        return 1;
    return 0;
}

int insere_fim(Fila f, Pessoa elem){
    struct no *N;

    N = (struct no*) malloc(sizeof(struct no));

    if(N == NULL)
        return 0;

    N->info = elem;

    if(fila_vazia(f) == 1)
        f->ini = N;
    else
        f->fim->prox = N;
    f->fim = N;
    return 1;
}

int remove_ini(Fila f, Pessoa *elem){
    if(fila_vazia(f) == 1)
        return 0;

    struct no *aux = f->ini;

    *elem = aux->info;

    if(f->ini == f->fim)
        f->fim == NULL;

    f->ini = aux->prox;
    free(aux);
    return 1;
}

void apaga_fila(Fila f){
    Pessoa b;

    while(fila_vazia(f) != 1){
        remove_ini(f,&b);
    }
    free(f);
}

void esvazia_fila(Fila f){
    Pessoa b;

    while(fila_vazia(f) != 1)
        remove_ini(f,&b);
}

int tamanho(Fila f){
    struct no *aux = f->ini;
    if(fila_vazia(f) == 1)
        return 0;

    int i = 1;
    while(aux != f->fim){
        i++;
        aux = aux->prox;
    }

    return i;
}

