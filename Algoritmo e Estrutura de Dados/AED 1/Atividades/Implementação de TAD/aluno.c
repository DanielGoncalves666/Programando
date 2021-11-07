/*
aluno.c
----------
Daniel Gonçalves 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

//---Estrutura--//

struct aluno
{
	char nome[50];
	double media;
	int faltas;
};

//---Operações----//

/*
alocar
----------
Entrada: nenhuma
Processo: aloca uma estrutura do tipo Aluno
Saída: endereço para uma entrutura do tipo Aluno
*/
Aluno *alocar()
{
	Aluno *p = (Aluno *) malloc(sizeof(Aluno));

	return p;
}

/*
preencher
------------
Entrada: uma string, um double, um inteiro e um endereço para Alunos
Processo: Verifica a validade dos dados de entrada e preenche as estruturas com os dados recebidos.
Saída: 0, em falha, 1, em sucesso.
*/
int preencher(char *nom, double med, int falt, Aluno *p)
{
	if(p == NULL || med < 0.0 || falt < 0)
	{
		return 0;
	}

	strcpy(p->nome,nom);
	(*p).media = med;
	(*p).faltas = falt;

	return 1;
}

/*
pegar_media
---------
Entrada: estrutura de dados do tipo aluno
Processo: verficada a validade do ponteiro.
Saída: a media, em sucesso, -1, em fracasso
*/
double pegar_media(Aluno *p)
{
	if(p == NULL)
	{
		return -1;
	}

	return p->media;
}


/*
pegar_faltas
---------
Entrada: estrutura de dados do tipo aluno
Processo: verficada a validade do ponteiro.
Saída: a qtd_faltas, em sucesso, -1, em fracasso
*/
int pegar_faltas(Aluno *p)
{
	if(p == NULL)
	{
		return -1;
	}

	return p->faltas;
}


/*
pegar_nome
---------
Entrada: estrutura de dados do tipo aluno
Processo: verficada a validade do ponteiro.
Saída: o nome, em sucesso, NULL, em fracasso
*/
char *pegar_nome(Aluno *p)
{
	if(p == NULL)
	{
		return NULL;
	}

	return p->nome;
}

/*
deletar
----------
Entrada: ponteiro para ponteiro para estrutura Aluno
Processo: desaloca a estratura e seta o ponteiro para NULL.
Saída: nenhuma
*/
void deletar(Aluno **p)
{
	free(*p);
	*p = NULL;
}