/*
	Método de Jordan para resolução de sistemas lineares
	// Incompleto
	
	by Daniel Gonçalves 2022
*/

#include<stdio.h>
#include<stdlib.h>

int qtd = 0; // quantidade de equações e de incógnitas

double **capturarMatrizAmpCoeficientes();
void imprimirMatriz(double **matriz);
void liberarMatriz(double **matriz);

int trocarLinhas(double **matriz, int l1, int l2);
int multiplicarEquacao(double **matriz, int l1, double valor);
int combinacaoLinear(double **matriz, int l1, int l2, double valor);

int naoNulasA(double **matriz);
int naoNulasB(double **matriz);

int main()
{

	double **matriz = NULL;

	printf("\nEntre com a quantidade de equações e de incógnitas: ");
	scanf("%d", &qtd);
	
	if(qtd <= 0)
	{
		fprintf(stderr, "\nQuantidade inválida.\n");
		return 1;
	}

	matriz = capturarMatrizAmpCoeficientes();
	if(matriz == NULL)
	{
		fprintf(stderr,"\n Não foi possível alocar memória para a matriz.\n");
		return 2;
	}

	imprimirMatriz(matriz);

	//trocarLinhas(matriz, 0, 1);
	//multiplicarEquacao(matriz,0,10.6);
	//combinacaoLinear(matriz, 1,0,-2.0);
	
	//imprimirMatriz(matriz);	

	printf("A %d, B %d\n", naoNulasA(matriz), naoNulasB(matriz));






	liberarMatriz(matriz);
	return 0;
}


double **capturarMatrizAmpCoeficientes(){
	double **matriz = (double **) calloc(qtd, sizeof(double *)); // qtd equações
	if(matriz != NULL)
	{
		for(int i = 0; i < qtd; i++)
		{
			matriz[i] = (double *) calloc(qtd + 1, sizeof(double)); // qtd + 1 posições para os coeficientes e para o b
			
			if(matriz[i] == NULL)
				return NULL;		
		}
	
		for(int i = 0; i < qtd; i++)
		{
			printf("\nEntre com a %d-ésima equação de %d equações: \n", i + 1, qtd);
			for(int h = 0; h < qtd + 1; h++)
			{
				scanf("%lf", &matriz[i][h]);
			}
		}
	}

	return matriz;
}

void imprimirMatriz(double **matriz)
{

	if(matriz == NULL)
	{
		fprintf(stderr,"\n Matriz inexistente. \n");
	}
	else
	{
		for(int i = 0; i < qtd; i++)
		{
			for(int h = 0; h < qtd + 1; h++)
			{
				printf("%9.6lf ", matriz[i][h]);
			}
			printf("\n");
		}
	}
}

void liberarMatriz(double **matriz)
{
	if(matriz != NULL)
	{
		for(int i = 0; i < qtd; i++)
		{
			free(matriz[i]);
		}
		free(matriz);
	}
	
	matriz = NULL;
}

// 0 para falha, 1 para sucesso
int trocarLinhas(double **matriz, int l1, int l2)
{
	if(matriz == NULL) 
		return 0; 

	if(l1 < 0 || l2 < 0 || l1 >= qtd || l2 >= qtd)
		return 0;
		
	if(l1 == l2)
		return 1;
		
	double *buffer = (double *) calloc(qtd + 1, sizeof(double));
	if(buffer == NULL)
		return 0;
	
	for(int i = 0; i < qtd + 1; i++)
	{
		buffer[i] = matriz[l1][i];
		matriz[l1][i] = matriz[l2][i];
		matriz[l2][i] = buffer[i];
	}
	
	free(buffer);
	return 1;
}

// 0 para falha, 1 para sucesso
int multiplicarEquacao(double **matriz, int l1, double valor)
{
	if(matriz == NULL)
		return 0;
		
	if(l1 < 0 || l1 >= qtd)
		return 0;
		
	for(int i = 0; i < qtd + 1; i++)
	{
		matriz[l1][i] *= valor;
	}
	
	return 1;
}

// 0 para falha, 1 para sucesso
int combinacaoLinear(double **matriz, int l1, int l2, double valor)
{
	if(matriz == NULL)
		return 0;
		
	if(l1 < 0 || l2 < 0 || l1 >= qtd || l2 >= qtd)
		return 0;
		
	for(int i = 0; i < qtd + 1; i++)
	{
		matriz[l1][i] += matriz[l2][i] * valor;
	}
	
	return 1;
}


int naoNulasA(double **matriz)
{
	int count = 0;
	
	for(int i = 0; i < qtd; i++)
	{
		for(int h = 0; h < qtd; h++)
		{
			if(matriz[i][h] == 0.0)
			{
				count++;
				break;
			}
		}
	}
	
	return qtd - count;
}

int naoNulasB(double **matriz)
{
	int count = 0;
	
	for(int i = 0; i < qtd; i++)
	{
		if(matriz[i][qtd] == 0.0)
			count++;
	}
	
	return qtd - count;
}
