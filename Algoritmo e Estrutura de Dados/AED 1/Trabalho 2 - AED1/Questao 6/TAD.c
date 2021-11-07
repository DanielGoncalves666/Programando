//fila de prioridade descendente, onde o elemento com maior prioridade é removido
//alocação estática/sequencial (uso do contador) e inserção ordenada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"

struct paciente{
    char nome[QTD];
    int idade;
    int orgao;
    int gravidade;
};

struct fila{
    struct paciente no[MAX];
    int ini, cont;
};

/*
cria_fp
---------
Entrada: nenhuma
Processo: aloca uma estrutura do tipo 'struct fpd'
Saída: endereço para uma 'struct fpd'
*/
Fila cria_fp()
{
	Fila f = (Fila) malloc(sizeof(struct fila));

	if(f != NULL)
	{
		f->ini = f->cont = 0;
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
	if(f->cont == 0)
		return 1;

	return 0;
}

/*
fp_cheia
---------
Entrada: Tipo Fila
Processo: verifica se a fila está cheia
Saída: 1, se cheia, 0, se não cheia
*/
int fp_cheia(Fila f)
{
	if(f->cont == MAX)
		return 1;

	return 0;
}

/*
insere_ord
---------
Entrada: Tipo fila, string, três inteiros.
Processo: insere, de modo ordenado, o novo paciente na fila.
Saída: 0, em falha, 1, em sucesso.
*/
int insere_ord(Fila p, char name[], int idad, int org, int grau)
{
    if(fp_cheia(p))
        return 0;

    int fim = (p->ini + p->cont) % MAX;

    //fila vazia
    if(fp_vazia(p))
    {
        strcpy(p->no[p->ini].nome,name);
        p->no[p->ini].idade = idad;
        p->no[p->ini].orgao = org;
        p->no[p->ini].gravidade = grau;

        p->cont++;

        return 1;
    }

    //gravidade menor ou igual que a do ultimo elemento, insere no fim
    if(grau <= p->no[fim].gravidade)
    {
        p->cont++;
        fim = (p->ini + p->cont) % MAX;

        strcpy(p->no[fim].nome,name);
        p->no[fim].idade = idad;
        p->no[fim].orgao = org;
        p->no[fim].gravidade = grau;

        return 1;
    }

    //adicionar no meio da lista
	int aux = p->ini;
    int i;

	//procura pela posicao correta
	while( grau <= p->no[aux].gravidade)
        aux++;

	//deslocamento
	for(i = (fim + 1) % MAX; i > aux; i--)
    {
        strcpy(p->no[i].nome,p->no[i - 1].nome);
        p->no[i].idade = p->no[i - 1].idade;
        p->no[i].orgao = p->no[i - 1].orgao;
        p->no[i].gravidade = p->no[i - 1].gravidade;
    }
		
    strcpy(p->no[aux].nome,name);
    p->no[aux].idade = idad;
    p->no[aux].orgao = org;
    p->no[aux].gravidade = grau;

    p->cont++;

    return 1;
}

/*
remover_ini
---------
Entrada: Tipo Fila, string, três ponteiros para inteiros (idade, órgao, gravidade)
Processo: remove o elemento de maior prioridade da fila (inicio)
Saída: 0, em falha, 1 em sucesso.
*/
int remove_ini(Fila p, char name[], int *idad, int *org, int *grau)
{
    if(fp_vazia(p))
        return 0;

    strcpy(name,p->no[p->ini].nome);
    *idad = p->no[p->ini].idade;
    *org = p->no[p->ini].orgao;
    *grau = p->no[p->ini].gravidade;

    p->ini = (p->ini + 1) % MAX;//incremento circular

    p->cont--;

    return 1;
}

/*
esvazia_fp
---------
Entrada: Ponteiro para tipo Fila
Processo: desaloca a lista e seta o Tipo Fila para NULL
Saída: 0, em falha, 1, em sucesso
*/
int esvazia_fp(Fila f)
{
	if(f != NULL)
	{
		f->ini = f->cont = 0;
        return 1;
	}

    return 0;
}
