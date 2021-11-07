#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha{
    int no[max];
    int topo;
};

/*
cria_pilha
----------
Entrada: nenhuma
Processo: aloca uma strutura do tipo 'struct pilha'
Saída: Endereço para um tipo 'struct pilha', em sucesso, NULL, em fracasso.
*/
pilha cria_pilha(){
    pilha p;
    p = (pilha) malloc(sizeof(struct pilha));
    
    if(p!=NULL)
        p->topo = -1;
    return p;
}

/*
pilha_vazia
-------------
Entrada: Tipo pilha
Processo: verifica se a pilha está vazia
Saída: 1, se vazio, 0, se não vazio.
*/
int pilha_vazia(pilha p){
    if(p->topo == -1)
        return 1;
    else
        return 0;
}

/*
pilha_cheia
-------------
Entrada: Tipo pilha
Processo: verifica se a pilha está cheia
Saída: 1, se cheia, 0, se não cheia.
*/
int pilha_cheia(pilha p){
    if(p->topo == max-1)
        return 1;
    else
        return 0;
}

/*
push
-------------
Entrada: Tipo pilha, inteiro
Processo: insere o inteiro passado no topo da pilha
Saída: 1, em sucesso, 0, em fracasso
*/
int push(pilha p, int elem){
    if(p == NULL  || pilha_cheia(p))
        return 0;

    p->topo ++;
    p->no[p->topo] = elem;

    return 1;
}

/*
pop
-------------
Entrada: Tipo pilha, endereço para inteiro
Processo: remove o elemento no topo da pilha e o atribui a variavel cujo endereço foi passado
Saída: 1, em sucesso, 0, em fracasso
*/
int pop(pilha p, int *elem){
    if(p == NULL  || pilha_vazia(p))
        return 0;

    *elem = p->no[p->topo];
    p->topo--;
    
    return 1;
}

/*
ve_topo
-------------
Entrada: Tipo pilha, endereço para inteiro
Processo: atribui a variável cujo endereço foi passado o vaor do elemento no topo da pilha.
Saída: 1, em sucesso, 0, em fracasso
*/
int ve_topo(pilha p, int *elem){
    if(p == NULL  || pilha_vazia(p))
        return 0;

    *elem = p->no[p->topo];

    return 1;
}

/*
esvazia_pilha
-------------
Entrada: Tipo pilha
Processo: retorna a pilha ao estado vazio
Saída: 1, em sucesso, 0, em fracasso
*/
int esvazia_pilha(pilha p){
    if(pilha_vazia(p))
        return 0;

    p->topo = -1;

    return 1;
}
