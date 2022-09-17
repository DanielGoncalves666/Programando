/*
O nome do arquivo a ser criado e a quantidade de alunos é informada na linha de comando
Daniel Goncalves 2021.
*/
#include <stdio.h>
#include <stdlib.h>

void leitura(int *matricula, char nome[], double *nota);
void escrita(int matricula, char nome[], double nota, FILE *arq);

int main(int argc, char *argv[])
{
	FILE *arquivo = NULL;
	int i = 0;

	int matricula = 0;
	char nome[51];
	double nota = 0;

	arquivo = fopen(argv[1],"w");

	if(arquivo == NULL){
		printf("Falha!\n");
		return 1;
	}

	for(i = 0; i < atoi(argv[2]); i++)
	{
		leitura(&matricula,nome,&nota);
		escrita(matricula,nome,nota,arquivo);
	}

	fclose(arquivo);

	return 0;
}

void
leitura(int *matricula, char nome[], double *nota)
{
	printf("\nEntre com a matricula e a nota do aluno:\n");
	scanf("%d %lf", matricula, nota);
	printf("Entre com o nome do aluno(50 digitos):\n");
	scanf(" %[^\n]",nome);
}

void
escrita(int matricula, char nome[], double nota, FILE *arq)
{
	fprintf(arq, "%d\n%s\n%.2lf\n\n",matricula,nome,nota);
}