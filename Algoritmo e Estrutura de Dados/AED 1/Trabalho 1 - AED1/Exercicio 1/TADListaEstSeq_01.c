#include <stdlib.h>
#include "TADListaEstSeq_01.h"
#include <math.h>
#define MAX 20

struct lista {
    float no[MAX];
    int Fim;
};

Lista cria_lista() {

    Lista lst = (Lista) malloc(sizeof(struct lista));

    if (lst != NULL)
        lst->Fim = 0;

    return lst;
}

int lista_vazia(Lista lst) {
    if (lst == NULL) return -1;
    return (lst->Fim == 0);
}

int lista_cheia(Lista lst) {
    if (lst == NULL) return -1;
    return (lst->Fim == MAX);
}

int insere_elem(Lista lst, float elem) {
    if (lst == NULL || lista_cheia(lst) == 1)
        return 0;

    lst->no[lst->Fim] = elem; // Insere elemento
    lst->Fim++; // Avança o Fim

    return 1;
}

int remove_elem(Lista lst, float elem) {
    if (lst == NULL || lista_vazia(lst))
        return 0; // FALHA

    int i, Aux = 0;

    // Percorrimento até achar o elem ou final de lista
    while (Aux < lst->Fim && lst->no[Aux] != elem)
        Aux++;

    if (Aux == lst->Fim) // Final de lista (elem nao existe)
        return 0; // Falha

    // Deslocamento à esq. do sucessor até o final da lista
    for (i = Aux+1; i < lst->Fim; i++)
        lst->no[i-1] = lst->no[i];

    lst->Fim--; // Decremento do campo Fim
    return 1; // Sucesso
}

void libera_lista (Lista *lst) {
    free (*lst);
    *lst = NULL;
}

void inicializa_lista(Lista lst) {
    lst->Fim = 0;
}

int get_elem(Lista lst, int pos, float *elem) {

    if (lst == NULL || lista_vazia(lst) || pos <= 0 || pos > lst->Fim)
        return 0; // FALHA

    *elem = lst->no[pos-1];
    return 1; // SUCESSO
}
int remove_impar(Lista lst){
    if (lst == NULL || lista_vazia(lst))
        return 0; // FALHA

    int i, Aux = 0;

    // Percorrimento até achar o elem ou final de lista
    while(1){
        while (Aux < lst->Fim && fmod(lst->no[Aux], 2) == 0)
            Aux++;

        if (Aux == lst->Fim){ // Final de lista
            break;;
        }

        // Deslocamento à esq. do sucessor até o final da lista
        for (i = Aux+1; i < lst->Fim; i++)
            lst->no[i-1] = lst->no[i];

        lst->Fim--; // Decremento do campo Fim
    }
    return 1; // Sucesso
}
int tamanho(Lista lst){
    return lst->Fim;
}
int esvaziar(Lista lst){
    if (lst == NULL || lista_vazia(lst))
        return 0; // FALHA
    else
        lst->Fim = 0;
    return 1;
}
int retorna_maior(Lista lst, float *num){
    if (lst == NULL || lista_vazia(lst))
        return 0; // FALHA
    int aux = 0;
    int cont;
    int i;
    for(cont = 0, i = 0; cont <= lst->Fim; cont++, i++){
        if(lst->no[i] > aux){
            aux = lst->no[i];
        }
    }
    *num = aux;
    return 1;//sucesso
}
Lista inverter(Lista lst){
    Lista L2 = (Lista) malloc(sizeof(struct lista));
    if (L2 != NULL)
        L2->Fim = 0;
    else
        return L2;
    int i;
    int cont = 0;
    cont = lst->Fim-1;
    for(i = 0; cont >= 0; cont --, i++, L2->Fim++)
        L2->no[i] = lst->no[cont];
    return L2;
}
Lista concatenar(Lista lst, Lista L2){
//retorna uma lista l3 que contem os elementos de L1 seguidos dos de L2
    int cont = 0;
    int i;
    Lista L3;
    L3 = cria_lista();
    for (i = 0; i < lst->Fim; i++, L3->Fim++)
        L3->no[i] = lst->no[i];
    for (; i < lst->Fim + L2->Fim; i++, L3->Fim++)
    {
        if(lista_cheia(L3) == 1){
            return NULL;
        }
        else{
            L3->no[i] = L2->no[cont];
            cont++;
        }
    }
    return L3;
}
