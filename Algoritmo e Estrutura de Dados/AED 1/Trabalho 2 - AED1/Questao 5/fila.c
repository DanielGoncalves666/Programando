#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct no{
    Aluno info;
    struct no *prox;
};

struct fila{
    struct no *ini;
    struct no *fim;
};

/*
cria_fila
---------
Entrada: nenhuma
Processo: aloca uma estrutura do tipo 'struct fila' e seta a fil para o estado vazio
Saída: endereço para uma 'struct fila'
*/
Fila cria_fila(){
    Fila f;

    f = (Fila) malloc(sizeof(struct fila));
    if(f != NULL){
        f->ini = NULL;
        f->fim = NULL;
    }

    return f;
}

/*
fp_vazia
---------
Entrada: Tipo Fila
Processo: verifica se a fila está vazia
Saída: 1, se vazia, 0, se não vazia
*/
int fp_vazia(Fila f)
{
    if(f->ini == NULL)
        return 1;

    return 0;
}

//nao existe o conceito de lista cheia neste caso

/*
insere_fim
---------
Entrada: Tipo fila, estrutura do tipo Aluno
Processo: insere uma estrutura do tipo Aluno no fim da fila
Saída: 0, em falha, 1, em sucesso.
*/
int insere_fim(Fila f, Aluno elem){
    struct no *N;

    N = (struct no*) malloc(sizeof(struct no));

    if(N == NULL)
        return 0;

    N->info = elem;

    if(fp_vazia(f) == 1)
        f->ini = N;
    else
        f->fim->prox = N;

    N->prox = NULL;
    f->fim = N;
    return 1;
}

/*
remove_ord
---------
Entrada: Tipo fila, endereço de estrutura do tipo Aluno
Processo: remove o aluno com menor prioridade da fila
Saída: 0, em falha, 1, em sucesso.
*/
int remove_ord(Fila f, Aluno *elem){

    if(fp_vazia(f) == 1)
        return 0;

    struct no* aux = f->ini;
    struct no* menor = aux;
    aux = aux->prox;

    while(aux != NULL){
        if(menor->info.ano > aux->info.ano)
            menor = aux; ///Chega no menor elemento
        aux = aux->prox;
    }

    ///menor � o primeiro elemento
    if(menor == f->ini){
        f->ini = menor->prox;
        *elem = menor->info;
        free(menor);
        return 1;
    }

    aux = f->ini;
    while(aux->prox != menor){
        aux = aux->prox;
    }

    ///Menor eh o ultimo elemento
    if(menor == f->fim){
        f->fim = aux;
        *elem = menor->info;
        free(menor);
        return 1;
    }

    ///Menor esta no meio
    aux->prox = menor->prox;
    *elem = menor->info;
    free(menor);
    return 1;


}

/*
esvazia_fp
---------
Entrada: Ponteiro para tipo Fila
Processo: desaloca os elementos Alunos presentes na fila e seta ela para o estado vazio
Saída: nada
*/
void esvazia_fp(Fila f){

    if(f != NULL)
    {
        struct no *aux;

        while(f->ini != NULL)
        {
            aux = f->ini;
            f->ini = aux->prox;

            free(aux);
        }

        f->ini = f->fim = NULL;
    }
}
