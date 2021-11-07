#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no {
    int info;
    struct no *prox;
    struct no *ant;
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

// Inserção no início
int insereElem(Lista *li, int element) {
    // Alocação de um novo nó e seu preenchimento
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL) {
        return 0;
    }
    N->info = element;
    N->ant = NULL; // Não há antecessor ao novo nó
    N->prox = *li; // O sucessor é o resto da lista já existente
    if (listaVazia(*li) == 0) {
        (*li)->ant = N; // O antecessor do 1º nó (antes nulo) aponta pro novo nó
    }
    *li = N; // Faz lista apontar pro 1º nó
    return 1;
}

int removeElem(Lista *lst, int elem){
    if(listaVazia(*lst) == 1)
        return 0;

    Lista aux = *lst;

    while(aux->prox != NULL && aux->info != elem)
        aux = aux->prox;

    if(aux->info != elem) return 0;

    if(aux->prox != NULL)
        aux->prox->ant = aux->ant;
    if(aux->ant != NULL)
        aux->ant->prox = aux->prox;
    if(aux == *lst)
        *lst = aux->prox;
    free(aux);
    return 1;
}

int obtem_valor(Lista lst, int Pos){
    int i = 1;

    while(lst->prox != NULL && i < Pos){
        lst = lst->prox;
        i++;
    }
    if(i == Pos)
        return lst->info;
}

int tamanho(Lista li) {
    int Temp = 0;
    while (li != NULL) {
        Temp++;
        li = li->prox;
    }
    return Temp;
}

int esvaziar(Lista *li) {
    if (listaVazia(*li) == 1) {
        return 0;
    }
    while (listaVazia(*li) != 1) {
        removeElem(li, (*li)->info);
    }
    return 1;
}

int removeMaior(Lista *li) {
    Lista aux = *li;
    int maior = (*li)->info;
    while (aux != NULL) {
        if (aux->info > maior) {
            maior = aux->info;
        }
        aux = aux->prox;
    }
    removeElem(li, maior);
    return 1;
}

Lista inverter(Lista lst){

    if(listaVazia(lst) == 1)
        return lst;

    Lista lst2 = NULL;

    while(lst != NULL){
        insereElem(&lst2,lst->info);
        lst = lst->prox;
    }

    return lst2;
}

Lista multiplos3(Lista lst){
    Lista lst2 = NULL;

    ///Pra ficar na mesma ordem da lista original vou verificar de tras pra frente
    while(lst->prox != NULL){
        lst = lst->prox;
    }

    while(lst != NULL){
        if(lst->info % 3 == 0)
            insereElem(&lst2, lst->info);
            lst = lst->ant;
    }

    return lst2;
}

Lista primos(Lista lst){
    Lista lst2 = NULL;
    int i;

    while(lst != NULL){
        for(i = lst->info - 1; i > 1; i--)
            if(lst->info % i == 0)
                break;
        if(i == 1 ){
            Lista novo = (Lista) malloc(sizeof(struct no));
                novo-> info = lst->info;
                novo->ant = NULL;
                novo->prox = lst2;

            if(listaVazia(lst2) == 0)
                (lst2)->ant = novo;
            lst2 = novo;

        }
        lst = lst->prox;
    }
    return lst2;
}

int removeTodos(Lista *lst, int elem){
    int flag = 0;

    if(listaVazia(*lst) == 1)
        return 0;

    Lista aux;

    while(aux != NULL){
            aux = *lst;

        if(aux == NULL) ///Após remover o unico elemento da lista restante.
            return flag;

        while(aux->prox != NULL && aux->info != elem)
            aux = aux->prox;

        if(aux->info == elem) flag++; /// Flag conta a quantidade de remoçoes que foram feitas

        if(aux->info != elem) return flag;

        if(aux->prox != NULL)
            aux->prox->ant = aux->ant;
        if(aux->ant != NULL)
            aux->ant->prox = aux->prox;
        if(aux == *lst)
            *lst = aux->prox;
        free(aux);
    }

    return flag;
}
