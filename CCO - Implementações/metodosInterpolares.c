/*
    Método de Newton para Interpolação Numérica

    By Daniel Gonçalves 2022
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    double x;
    double fx;
}Ponto;

Ponto *capturarPontos(int N); // ok
void ordenarPontos(Ponto *vet, int N); // ok
double *operadorDiferencasDivididas(Ponto *vet, int N); // ok
double *calcularCoeficientesFinais(Ponto *vet, double *coefIniciais, int N);
double combinar(Ponto *vet, int primeiro, int qtd, int N);
void imprimirEquacao(double *coeficientes, int N); // ok

int main()
{
    int N = 0; // quantidade de pontos
    Ponto *vetor = NULL; // vetor de pontos

    printf("\nEntre com a quantidade de pontos: ");
    scanf("%d", &N);

    vetor = capturarPontos(N);
    if(vetor == NULL)
    {
        fprintf(stderr, "\nNão foi possível alocar memória para os pontos.\n");
        return 1;
    }
    
    ordenarPontos(vetor, N);

    double *coeficientesIniciais = operadorDiferencasDivididas(vetor,N);
    double *coeficientesFinais = calcularCoeficientesFinais(vetor, coeficientesIniciais, N);

    imprimirEquacao(coeficientesFinais, N);

    free(vetor);
    free(coeficientesIniciais);
    free(coeficientesFinais);

    return 0;
}

Ponto *capturarPontos(int N)
{
    Ponto *vet = (Ponto *) malloc(sizeof(Ponto) * N);
    if(vet != NULL)
    {
        for(int i = 0; i < N; i++)
        {
            printf("\nEntre com o %d-ésimo ponto: x f(x)\n", i);
            scanf("%lf %lf", &vet[i].x, &vet[i].fx);        
        }
    }

    return vet;
}

void ordenarPontos(Ponto *vet, int N)
{
    Ponto aux;
    int j;

    //insertSort
    for(int i = 1; i < N; i++)
    {
        j = i;
        for(int h = j-1; h >= 0; h--)
        {    
            if(vet[j].x < vet[h].x)
            {
                aux = vet[j];
                vet[j] = vet[h];
                vet[h] = aux;
                j--;
            }
            else
                break;
        }
    }
}

double *operadorDiferencasDivididas(Ponto *vet, int N)
{
    double **matriz = (double **) malloc(sizeof(double *) * N);
    double *linha = malloc(sizeof(double) * N);
    for(int i = 0; i < N; i++)
    {
        matriz[i] = (double *) malloc(sizeof(double) * N);
    }

    // matriz triangular superior esquerda
    // irei inverter os eixos dela, de modo a contribuir com eficiência de memória

    for(int i = 0; i < N; i++) // primeira linha
    {
        matriz[0][i] = vet[i].fx;
    }
    linha[0] = matriz[0][0];

    for(int i = 1; i < N; i++)
    {
        for(int h = 0; h < (N - i); h++)
        {
            matriz[i][h] = (matriz[i - 1][h + 1] - matriz[i - 1][h]) / (vet[h + i].x - vet[h].x);
        }
        linha[i] = matriz[i][0]; 
    }

    for(int i = 0; i < N; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return linha;
}

/*
    0       1       2       3
    01      12      23
    012     123
    0123
*/

double *calcularCoeficientesFinais(Ponto *vet, double *coefIniciais, int N)
{
    double *coefFinais = (double *) calloc(N, sizeof(double));
    int sinal = 1;

    if(coefFinais != NULL)
    {
        coefFinais[0] += coefIniciais[0];// a0
        for(int i = 1; i < N; i++)// a1, a2, a3
        {
            sinal = 1;
            for(int h = i; h >= 0; h--) // (x - x0) ...
            {
                coefFinais[h] += coefIniciais[i] * combinar(vet, 0, i - h, i) * sinal;
                sinal *= -1;
            } 
        }
    }

    return coefFinais;
}

// na primeira chamada index deve ser 0
double combinar(Ponto *vet, int primeiro, int qtd, int N)
{
    double total = 0;
    
    if(qtd == 0)
        return 1.0;

    for(int i = primeiro; i <= N - qtd; i++)// estabelece o primeiro valor da sequencia. Esse valor é o que tem menor índice.
    {
        total += vet[i].x * combinar(vet, i + 1, qtd - 1, N);
    }

    return total;
}

/*
    (x - x0) = x - x0
    (x - x0)(x - x1) = 
        x^2 - x1x - x0x + x1x0 = 
        x^2 - (x0 + x1)x + x1x0
    (x - x0)(x - x1)(x - x2) = 
        x^3 - (x0 + x1)x^2 + x1x0x - x2x^2 + (x0 + x1)x2x  -x2x1x0 = 
        x^3 - (x0 + x1 + x2)x^2 + (x1x0 + x2x1 + x2x0 )x - x2x1x0
    (x - x0)(x - x1)(x - x2)(x - x3) =
        x^4 - (x0 + x1 + x2)x^3 + (x1x0 + x2x1 + x2x0 )x^2 - x2x1x0x - x3x^3 + (x0 + x1 + x2)x3x^2 - (x1x0 + x2x1 + x2x0 )x3x + x3x2x1x0 = 
        x^4 - (x0 + x1 + x2 + x3)x^3 + (x1x0 + x2x1 + x2x0 + x3x0 + x3x1 + x3x2)x^2 - (x2x1x0 + x3x1x0 + x3x2x1 + x3x2x0)x + x3x2x1x0


*/

void imprimirEquacao(double *coeficientes, int N)
{
    printf("\nP(x) = ");
    for(int i = N - 1; i >= 0; i--)
    {
        printf("%+lf * x^%d ", coeficientes[i], i);
    }
}