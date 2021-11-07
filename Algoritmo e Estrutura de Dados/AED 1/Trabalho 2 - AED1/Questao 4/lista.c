#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "fila.h"
#include "lista.h"
#define max 50

struct lista{
    Pessoa dados[max];
    int cont;
};

Lista cria_lista(){
    Lista nova = (Lista) malloc(sizeof(struct lista));

    if(nova == NULL)
        return 0;

    nova->cont = 0;
    return nova;

}

int lista_vazia(Lista li){
    if(li->cont == 0)
        return 1;
    return 0;
}

int lista_cheia(Lista li){
    if(li->cont == max)
        return 1;
    return 0;
}

int insereLista(Lista li, Pessoa elem){
    if(lista_cheia(li) == 1)
        return 0;

    li->dados[li->cont] = elem;
    li->cont++;
    return 1;
}

int menor_data(Lista li, Pessoa *elem){
    int menor = 0;
    if(lista_vazia(li) == 1)
        return 0;

    int i;
    ///Encontrando o paciente com a data da 2 dose, mais proxima
    for(i = 1; i < li->cont; i++){
        if(li->dados[i].segundaDose.ano < li->dados[menor].segundaDose.ano){
            menor = i;
            continue;
        }if(li->dados[i].segundaDose.ano == li->dados[menor].segundaDose.ano)
            if(li->dados[i].segundaDose.mes < li->dados[menor].segundaDose.mes){
                menor = i;
                continue;
            }if(li->dados[i].segundaDose.ano == li->dados[menor].segundaDose.ano)
                if(li->dados[i].segundaDose.mes == li->dados[menor].segundaDose.mes)
                    if(li->dados[i].segundaDose.dia < li->dados[menor].segundaDose.dia){
                        menor = i;
                        continue;
                }
    }
    *elem = li->dados[menor];
    for(i = menor; i < li->cont; i++){
        li->dados[i] = li->dados[i+1];
    }
    li->cont --;
    return 1;
}

int maior_idade(Lista li, char local[11], Pessoa *elem){
    int maior;

    int i;

    for(i = 0; i < li->cont; i++){
        if(strcmp(li->dados[i].localVacinacao, local) == 0){
            maior = i;
            break;}
    }

    ///Nao existe nqm na lista q vai se vacinar no local
    if(i == li->cont)
        return 0;

    ///Procura o com maior idade
    for(i; i < li->cont; i++){
        if(strcmp(li->dados[i].localVacinacao, local) == 0 && li->dados[i].idade > li->dados[maior].idade)
            maior = i;
    }
    *elem = li->dados[maior];
    for(i = maior; i < li->cont; i++){
        li->dados[i] = li->dados[i+1];
    }
    li->cont --;
    return 1;
}

int getPos(Lista li, int pos, Pessoa *elem){
    if(pos >= li->cont)
        return 0;

    *elem = li->dados[pos];
    return 1;
}
