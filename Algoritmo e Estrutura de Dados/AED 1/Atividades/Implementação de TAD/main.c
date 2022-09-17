/*
main.c
----------
Daniel Gonçalves 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

void selectionSort(Aluno **vet, int qtd);
void troca(Aluno **um, Aluno **dois);
void imprimir(Aluno **vet, int qtd);

int main()
{
	int N = 0;//quantidade de alunos na turma
	Aluno **vetor = NULL;//vetor de alunos
	int i = 0, verifica = 0;
	int faltas = 0;
	double media = 0;
	char nome[50];
	
	while(1)
	{
		printf("Entre com a quantidade de alunos da Turma:\n");
		scanf("%d",&N);

		if(N <= 0)
		{
			printf("\n---------Quantidade de alunos inválida!---------\n");
			continue;
		}

		break;
	}

	vetor = (Aluno **) malloc(sizeof(Aluno *) * N);
	for(i = 0; i < N; i++)
	{
		vetor[i] = alocar();
	}

	for(i = 0; i < N;)
	{
		printf("\nPor favor, entre com o nome do aluno %d:\n",i + 1);
		scanf(" %[^\n]",nome);
		printf("\nEntre com a media do aluno %d:\n",i + 1);
		scanf("%lf",&media);
		printf("\nEntre com a quantidade de faltas do aluno %d:\n",i + 1);
		scanf("%d",&faltas);

		verifica = preencher(nome,media,faltas, vetor[i]);

		if(verifica == 0)
		{
			printf("---------\nFalha ocorrida! Entre com os dados novamente!---------\n");
			continue;
		}

		i++;
	}

	selectionSort(vetor,N);
	imprimir(vetor,N);

	for(i = 0; i < N; i++)
	{
		free(vetor[i]);
	}
	free(vetor);
	
	return (0);
}

void selectionSort(Aluno **vet, int qtd)
{
	int h = 0;
	int base = 0;//primeiro elemento da sequencia a ser considerado
	int maior = 0;//maior elemento

	for(base = 0; base < qtd - 1; base++)
	{
		h = base;
		for(; h < qtd; h++)
		{
			if(h == base)
				maior = h;
			else if( pegar_media(vet[maior]) < pegar_media(vet[h]))
			{
				maior = h;
			}
		}

		troca(&vet[base], &vet[maior]);
	}
}

void troca(Aluno **um, Aluno **dois)
{
	Aluno *aux = NULL;//variavel auxiliar

	aux = *um;
	*um = *dois;
	*dois = aux;
}

void imprimir(Aluno **vet, int qtd)
{
	int i = 0;

	for(i = 0; i<qtd; i++)
	{
		printf("\n----Aluno %d----\n",i + 1);
		printf("Nome: %s\n", pegar_nome(vet[i]));
		printf("Media: %.2f\n", pegar_media(vet[i]));
		printf("Faltas: %d\n\n", pegar_faltas(vet[i]));
	}
}