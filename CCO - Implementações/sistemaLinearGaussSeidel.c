/*
    Método (iterativo) de Gauss Seidel para resolução de sistemas lineares.

    By Daniel Gonçalves 2022
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int qtd = 0; // quantidade de equações e de incógnitas

double **capturarMatrizAmpCoeficientes();
void imprimirMatriz(double **matriz);
void liberarMatriz(double **matriz);

int criterioSassenfeld(double **matriz);
double maximo(double *vet, int qtd);

void copiarEstimativas(double *origem, double *copia);
void generateNthEstimative(double **matriz, double *estimativas);
int criterioDeParada(double *estimativas, double *estimativasAnt, double erro);
double diferenca(double atual, double anterior);

int main()
{
	double **matriz = NULL;
    double *estimativa = NULL;
	double *estimativaAnterior = NULL;
	double erro = 0;

	printf("\nEntre com a quantidade de equações e de incógnitas: ");
	scanf("%d", &qtd);
	
	if(qtd <= 0)
	{
		fprintf(stderr, "\nQuantidade inválida.\n");
		return 1;
	}

    estimativa = (double *) calloc(qtd, sizeof(double));
	estimativaAnterior = (double *) calloc(qtd, sizeof(double));
    if(estimativa == NULL)
    {
        fprintf(stderr, "\n Não foi possível alocar memória para as estimativas.\n");
        return 2;
    }

	matriz = capturarMatrizAmpCoeficientes();
	if(matriz == NULL)
	{
		fprintf(stderr,"\n Não foi possível alocar memória para a matriz.\n");
		return 2;
	}

    if( criterioSassenfeld(matriz) == 0)
    {
        fprintf(stderr, "\nNão podemos garantir a convergência deste sistema linear ao utilizar o Método de Gauss-Seidel.\n");
        return 3;
    }

	printf("\nEntre com o erro aceitável: \n");
	scanf("%lf", &erro);

	int qtdIter = 0;
	do
	{
		copiarEstimativas(estimativa,estimativaAnterior);
		generateNthEstimative(matriz,estimativa);
		qtdIter++;

	}while( criterioDeParada(estimativa, estimativaAnterior, erro));

	printf("\nSolução (%d iterações): \n", qtdIter);
	for(int i = 0; i < qtd; i++)
	{
		printf("x_%d = %lf\n", i + 1, estimativa[i]);
	}

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
		printf("\n");
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

// 0 para não converge, 1 para converge
int criterioSassenfeld(double **matriz)
{
    double *betas = (double *) calloc(qtd, sizeof(double));

    for(int i = 0; i < qtd; i++)
    {
        for(int h = 0; h < qtd; h++)
        {
            if(i == h)
                continue;

            betas[i] += (h < i) ? (fabs(matriz[i][h]) * betas[h]) : fabs(matriz[i][h]); 
        }

        betas[i] *= fabs(1.0 / matriz[i][i]);
    }

    if( maximo(betas,qtd) < 1.0)
        return 1;

    return 0;
}
/*
4 1 1 4
8 0 1 3
1 -1 5 1
    Não converge
*/

double maximo(double *vet, int qtd)
{
    double maior = vet[0];

    for(int i = 1; i < qtd; i++)
    {
        maior = fmax(maior, vet[i]);
    }

    return maior;
}

void copiarEstimativas(double *origem, double *copia)
{
	for(int i = 0; i < qtd; i++)
		copia[i] = origem[i];
}

void generateNthEstimative(double **matriz, double *estimativas)
{
	int h;

    for(int i = 0; i < qtd; i++)
	{
		estimativas[i] = 0; // zera a estimativa
		for(h = 0; h < qtd; h++)
		{
			if(i == h)
				continue;
			
			estimativas[i] += matriz[i][h] * -1 * estimativas[h]; // inverte pois mudou de lado da equação
		}
		estimativas[i] += matriz[i][h]; // b
		estimativas[i] *= (1.0 / matriz[i][i]); // e se o coeficiente for zero?
	}
}

// 0 para parada, 1 para continuar
int criterioDeParada(double *estimativas, double *estimativasAnt, double erro)
{
	double maior = diferenca(estimativas[0], estimativasAnt[0]);

	for(int i = 0; i < qtd; i++)
	{
		maior = fmax(maior, diferenca(estimativas[i], estimativasAnt[i]));
	}

	return !(maior < erro);
}

double diferenca(double atual, double anterior)
{
	double maior = 0.0;

	if(atual != 0)
	{
		maior = fabs((atual - anterior) / atual);
	}
	else if(atual == 0 && anterior == 0)
	{
		maior = 0;
	}
	else 
	{
		maior = 1;
	}

	return maior;
}