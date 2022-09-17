/*
main.c
----------
Daniel Gonçalves 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
	char nome[50];
	double media;
	int faltas;
};
typedef struct aluno Aluno;

//---Prototipos---//

Aluno *alocar(int qtd);
int preencher(char *nom, double med, int falt, Aluno *p);
void selectionSort(Aluno *vet, int qtd);
void troca(Aluno *um, Aluno *dois);
void imprimir(Aluno *vet, int qtd);

int main()
{
	int N = 0;//quantidade de alunos na turma
	Aluno *vetor = NULL;//vetor de alunos
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

	vetor = alocar(N);
	if(vetor == NULL)
	{
		printf("---------\nFalha na alocação!---------\n");
		return 1;
	}

	for(i = 0; i < N;)
	{
		printf("\nPor favor, entre com o nome do aluno %d:\n",i+1);
		scanf(" %[^\n]",nome);
		printf("\nEntre com a media do aluno %d:\n",i+1);
		scanf("%lf",&media);
		printf("\nEntre com a quantidade de faltas do aluno %d:\n",i+1);
		scanf("%d",&faltas);

		verifica = preencher(nome,media,faltas, &vetor[i]);

		if(verifica == 0)
		{
			printf("---------\nFalha ocorrida! Entre com os dados novamente!---------\n");
			continue;
		}

		i++;
	}

	if(N > 1)
		selectionSort(vetor,N);
	
	imprimir(vetor,N);

	free(vetor);

	return (0);
}

Aluno *alocar(int qtd)
{
	if(qtd <= 0)
		return NULL;

	Aluno *p = (Aluno *) malloc(sizeof(Aluno) * qtd);

	return p;
}

int preencher(char *nom, double med, int falt, Aluno *p)
{
	if(p == NULL || med < 0.0 || falt < 0)
	{
		return 0;
	}

	strcpy(p->nome, nom);
	(*p).media = med;
	(*p).faltas = falt;

	return 1;
}

void selectionSort(Aluno *vet, int qtd)
{
	int h = 0;
	int base = 0;//primeiro elemento da sequencia a ser considerado
	int maior = 0;//maior elemento

	for(base = 0; base < qtd - 1; base++)
	{
		for(h = 0; h < qtd; h++)
		{
			if(h == base)
				maior = h;
			else if(vet[maior].media < vet[h].media)
			{
				maior = h;
			}
		}

		troca(&vet[base], &vet[maior]);
	}
}

void troca(Aluno *um, Aluno *dois)
{
	Aluno aux;//variavel auxiliar

	aux = *um;
	*um = *dois;
	*dois = aux;
}

void imprimir(Aluno *vet, int qtd)
{
	int i = 0;

	for(i = 0; i<qtd; i++)
	{
		printf("\n----Aluno %d----\n",i + 1);
		printf("Nome: %s\n",vet[i].nome);
		printf("Media: %.2f\n", vet[i].media);
		printf("Faltas: %d\n\n", vet[i].faltas);
	}
}