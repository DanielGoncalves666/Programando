/*
Daniel Gonçalves 2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario
{
	int matricula;
	char nome[51], cargo[25];
	int idade;
	double salario;
};
typedef struct funcionario Funcionario;

Funcionario cadastro(int);
void consulta(char entrada[], int total, Funcionario *lista);

int main()
{
	int i = 0;
	int matricula = 0;//numero de matricula
	int total = 0;//total de funcionarios cadastrados
	Funcionario *lista = NULL;//ponteiro para a lista de funcionarios
	char entrada[51];//armazena a entrada da consulta

	for(i = 0; i < 10; i++)
	{
		printf("\nEntre com o numero de matricula do funcionario:\n");
		scanf("%d",&matricula);

		if(matricula == 0)
			break;

		lista = (Funcionario *) realloc(lista, sizeof(Funcionario) * (i + 1));

		lista[i] = cadastro(matricula);
		total++;
	}
	printf("\n----------------------Cadastros Encerrados!----------------------\n");

	printf("----------------------Iniciando Consultas...---------------------\n");
	
	while(1)
	{
		printf("\nEntre com o nome do funcionario:\n");
		scanf(" %[^\n]",entrada);
		getchar();

		if(strcmp(entrada,"FIM") == 0)
			break;

		consulta(entrada, total, lista);
	}

	return (0);
}


Funcionario
cadastro(int matricula)
{
	Funcionario aux;
	
	aux.matricula = matricula;

	printf("\nEntre com o nome do funcionario (MAX 50 digitos):\n");
	scanf(" %[^\n]",aux.nome);
	
	printf("\nEntre com a idade:\n");
	scanf("%d",&aux.idade);
	
	printf("\nEntre com o cargo (MAX 24 digitos):\n");
	scanf(" %[^\n]",aux.cargo);

	printf("\nEntre com o salario:\n");
	scanf("%lf",&aux.salario);

	return aux;
}

void
consulta(char entrada[], int total, Funcionario *lista)
{
	int i = 0;

	for(i = 0; i < total; i++)
	{
		if(strcmp(entrada,lista[i].nome) == 0)
		{
			printf("\nCadastro Encontrado!\n");
			printf("Matricula = %d\n",lista[i].matricula);
			printf("Nome = %s\n",lista[i].nome);
			printf("Idade = %d\n",lista[i].idade);
			printf("Cargo = %s\n",lista[i].cargo);
			printf("Salario = %.2lf\n",lista[i].salario);
			return;
		}
	}

	printf("\nCadastro NAO Encontrado!\n");
}