#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
    int info;
    struct no* prox;
};


Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1;
    return 0;
}

int insere(Lista *lst, int elem){
    Lista novo;
    novo = (Lista)malloc(sizeof(struct no));

    if(novo == NULL) return 0;
    novo->info = elem;

    if(lista_vazia(*lst) == 1 || (*lst)->info >= elem){
        novo->prox = *lst;
        *lst = novo;
        return 1;
    }

    Lista aux = *lst;

    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;
    novo->prox = aux->prox;
    aux->prox = novo;
    return 1;

}

int remov(Lista *lst, int elem){
    if(lista_vazia(*lst) == 1 || elem < (*lst)->info)
        return 0;

    Lista aux = *lst;
    if(elem == (*lst)->info){
        *lst = aux->prox;
        free(aux);
        return 1;
    }

    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;
    if(aux->prox == NULL || aux->prox->info > elem)
        return 0;

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

int obtem_valor(Lista lst, int pos){

    if(lista_vazia(lst) == 1)
        return;

    int i = 1;
    while(lst != NULL && i < pos){
        lst = lst->prox;
        i++;
        }

    if(i == pos)
        return lst->info;

    return;
}

int tamanho(Lista lst){
    int tamanho = 0;

    while(lst != NULL){
        lst = lst->prox;
        tamanho++;
        }

    return tamanho;
}

int iguais(Lista lst, Lista lst2){

    if(lista_vazia(lst) == 1 && lista_vazia(lst2) == 1)
        return 1;
    else if(lista_vazia(lst) == 1 || lista_vazia(lst2) == 1)
        return 0;
    else if (tamanho(lst) != tamanho(lst2))
        return 0;

    while(lst != NULL){
        if(lst->info != lst2->info)
            return 0;
        else
            lst = lst->prox;
            lst2 = lst2->prox;
    }

    return 1;
}

int maior(Lista lst){

    if(lista_vazia(lst) == 1)
        return;

    int maior = lst->info;

    while(lst != NULL){
        if(lst->info > maior)
            maior = lst->info;
        lst = lst->prox;
    }

    return maior;
}

int esvaziar(Lista *lst){

    if(lista_vazia(*lst) == 1)
        return 0;

    while(*lst != NULL)
        remov(&(*lst), obtem_valor(*lst,1));

    return 1;
}

Lista intercala(Lista lst, Lista lst2){

    if(lista_vazia(lst) == 1)
        return lst2;
    else if(lista_vazia(lst2) == 1)
        return lst;

    Lista lst3 = NULL;

    while(lst != NULL && lst2 != NULL){
        if(lst->info <= lst2->info){
            insere(&lst3, lst->info);
            lst = lst->prox;
        }else{
            insere(&lst3, lst2->info);
            lst2 = lst2->prox;
        }
    }

    while(lst != NULL){
        insere(&lst3, lst->info);
        lst = lst->prox;
    }

    while(lst2 != NULL){
        insere(&lst3, lst2->info);
        lst2 = lst2->prox;
    }

    return lst3;
}
