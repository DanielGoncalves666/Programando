#include <stdio.h>
#include <stdlib.h>
#include "header_4.h"

struct no{
    double info;
    struct no* prox;
};

/*
cria_lista
-----------
Entrada: nenhuma
Processo: cria uma lista com cabeçalho e seta ela pra estado vazio
Saída: tipo LISTA
*/
Lista cria_lista()
{
    //aloca o nó cabeçalho: 
    Lista cabe;
    cabe = (Lista) malloc(sizeof(struct no));

    //se a lista foi alocada com sucesso, seta para o estado vazio
    if(cabe != NULL)
    {
        cabe->prox = NULL;
        cabe->info = 0;//irá armazenar o tamanho da lista
    }

    return cabe;
}


/*
lista_vazia
------------
Entrada: tipo Lista
Processo: verifica se a lista está vazia, o que ocorre se o cabelho aponta para NULL
Saída: 1, se vazia, 0, se não vazia
*/
int lista_vazia(Lista lst)
{
    if(lst->prox == NULL)
        return 1;
    
    return 0;
}

/*
insere_ord
------------
Entrada: tipo Lista, tipo double representado um elemento
Processo: Insere um novo elemento, ordenadamente, na lista
Saída: 0, em fracasso, 1, em sucesso
*/
int insere_ord(Lista lst, double elem)
{
    
    //aloca novo no
    Lista novo;
    novo = (Lista) malloc(sizeof(struct no));

    //verificamos se o no foi alocado com sucesso
    if(novo == NULL) 
        return 0;

    novo->info = elem;//inicializamos o campo info com o elemento passado

    //ponteiro para Lista, auxiliar
    Lista aux = lst;

    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;//percorremos a lista ate encontrar a posicao correta

    novo->prox = aux->prox;//o novo no vai apontar para o no que o elemento anterior apontava
    aux->prox = novo;//o no anterior agora aponta para o novo no
    lst->info++;//incrementa a qtd de elem da lista

    return 1;
}


/*
remov
------------
Entrada: tipo Lista, tipo double representado um elemento
Processo: Remove um elemento da lista
Saída: 0, em fracasso, 1, em sucesso
*/
int remov(Lista lst, double elem)
{
    //caso a lista estiver vazia
    if(lista_vazia(lst))
        return 0;

    Lista aux = lst;//recebe o endereço do cabeçalho

    //percorre a lista até encontrar o elemento, chegar no final
    //ou se encontrar um elemento maior que o procurado
    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;
    
    //se o elemento a ser retirado for maior que o último
    //ou se o no selecionado nao possui o elemento
    if(aux->prox == NULL || aux->prox->info > elem)
        return 0;

    Lista aux2 = aux->prox;//armzenamos o endereço do no a ser desalocado
    aux->prox = aux2->prox;//fazemos o no anterior apontar para o posterior
    free(aux2);

    lst->info--;

    return 1;
}

/*
obtem_valor
------------
Entrada: tipo Lista, inteiro representando posição a ser retornada, endereço para double onde o valor sera armazenado
Processo: realiza a consulta de um elemento na lista
Saída: 0, em fracasso, 1, em sucesso
*/
int obtem_valor_elem(Lista lst, int pos, double *valor)
{

    //se a lista estiver vazia
    //ou se pos for menor que 1 ou maior que o tamanho
    if(lista_vazia(lst) || pos < 1 || pos > lst->info)
        return 0;

    lst = lst->prox;//fazemos com que lst aponte para o primerio elemento

    int i = 1;
    while(i < pos)
    {
        lst = lst->prox;
        i++;
        //percorre a lista até que lst aponte para o elemento que estamos querendo
    }

    *valor = lst->info;
    return 1;
}

/*
tamanho
------------
Entrada: tipo Lista
Processo: consulta a quantidade de elementos da lista
Saída: quantidade de elementos da lista
*/
int tamanho(Lista lst)
{
    return lst->info;
}

/*
iguais
------------
Entrada: dois tipo Lista
Processo: verifica se as duas listas recebidas são iguais
Saída: 0, se não, 1, se sim
*/
int iguais(Lista lst, Lista lst2)
{

    //se as duas forem vazias, iguais
    //senão, se apenas uma for vazia, diferentes
    //se os tamanhos forem diferentes, diferentes
    if(lista_vazia(lst) == 1 && lista_vazia(lst2) == 1)
        return 1;
    else if(lista_vazia(lst) == 1 || lista_vazia(lst2) == 1)
        return 0;
    else if (tamanho(lst) != tamanho(lst2))
        return 0;

    //aqui é garantido que o tamanho é igual, logo só precisamos verificar por NULL em apenas uma lista
    while(lst->prox != NULL)
    {
        if(lst->prox->info != lst2->prox->info)
            return 0;//se encontrarmos um valor diferente
        
        lst = lst->prox;
        lst2 = lst2->prox;
    }

    return 1;
}

/*
maior
------------
Entrada: tipo Lista, ponteiro para double
Processo: retorna o maior elemento da lista, armazenado na variavel maior
Saída: 0, se a lista estiver vazia, 1, em sucesso
*/
int maior(Lista lst, double *maior)
{
    if(lista_vazia(lst) == 1)
        return 0;

    //percorre a lista até chegar no final dela, onde o maior elemento se encontra
    while(lst->prox != NULL){
        lst = lst->prox;
    }

    *maior = lst->info;

    return 1;
}

/*
esvaziar
------------
Entrada: tipo Lista
Processo: esvazia uma lista
Saída: nada
*/
void esvaziar(Lista lst)
{
    double valor;

    if(lista_vazia(lst) == 1)
        return;

    int i;
    for(i = 0; i < tamanho(lst); i++)
    {
        obtem_valor_elem(lst,1,&valor);
        remov(lst,valor);
    }

    lst->info = 0;
    lst->prox = NULL;
    //realizamos um processo sequencial de remoção do primeiro elemento da lista
}

Lista intercala(Lista lst, Lista lst2){

    int retorno;

    if(lista_vazia(lst) == 1)
        return lst2;
    else if(lista_vazia(lst2) == 1)
        return lst;
    //caso uma das lista esteja vazia, a intercalação é simplesmente a outra, o caso de ambas vazias já entra aqui

    Lista lst3 = cria_lista();
    if(lst3 == NULL)
        return NULL;

    while(lst->prox != NULL || lst2->prox != NULL){

        if(lst->prox != NULL)
        {
            retorno = insere_ord(lst3,lst->prox->info);
            if(!retorno)
                return NULL;
            lst = lst->prox;
        }

        if(lst2->prox != NULL)
        {
            retorno = insere_ord(lst3,lst2->prox->info);
            if(!retorno)
                return NULL;
            lst2 = lst2->prox;
        }
    }

    return lst3;
}
