/*
    Normalização de um Modelo de Programação Linear

    Ao longo do código, uso as seguintes representações:
        1 - =
        2 - >=
        3 - <=

    by Daniel Gonçalves 2022
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int tipoEquacao; // 0 - função objetivo ou 1 - equação de restrição 
    double *funcao;
    int qtdExcessos;
    int qtdFolgas;
    int qtdArtificiais;
    int tipoSinal; // 1 - =, 2 - >=, 3 - <=
    double constante;
}equacao;

equacao *capturarEquacao(int qtd, int b); // ok
void imprimirEquacao(equacao *eq, int qtd, int tipo);
char *sinal(int tipo); // ok
void normalizar(equacao *objetivo, equacao **restricoes, int qtdVD, int qtdR);

int main()
{
    int qtdVD = 0; // quantidade de variáveis de decisão
    int qtdR = 0; // quantidade de restrições
    int tipo = 0; // tipo do problema

    equacao *objetivo = NULL;
    equacao **restricoes = NULL;

    printf("\nEntre com a quantidade de variáveis de decisão: ");
    scanf("%d", &qtdVD);

    printf("\nEntre com a quantidade de restrições: ");
    scanf("%d", &qtdR);

    if(qtdVD <= 0 || qtdR <= 0)
    {
        fprintf(stderr, "Quantidades inválidas\n");
        return 1;
    }

    printf("\nO problema é de 1 - Maximização ou de 2 - Minimização? ");
    scanf("%d",&tipo);

    restricoes = (equacao **) calloc(qtdR, sizeof(equacao *));

    printf("\n==== Função objetivo ====");
    objetivo = capturarEquacao(qtdVD, 0);
    for(int i = 0; i < qtdR; i++)
    {
        printf("\n== %d-ésima equação de restrição ==", i + 1);
        restricoes[i] = capturarEquacao(qtdVD, 1);
    }

    normalizar(objetivo,restricoes,qtdVD,qtdR);

    imprimirEquacao(objetivo,qtdVD, tipo);
    printf("\nSujeito à: \n");
    for(int i = 0; i < qtdR; i++)
        imprimirEquacao(restricoes[i], qtdVD, tipo);
    
    return 0;
}

/* b = 0 para função objetivo, b = 1 para restrição */
equacao *capturarEquacao(int qtd, int b)
{
    equacao *nova = (equacao *) calloc(1,sizeof(equacao));
    nova->tipoEquacao = b;
    nova->tipoSinal = 1; // igual por padrão
    nova->constante = 0; // zero por padrão
    nova->qtdArtificiais = 0;
    nova->qtdExcessos = 0;
    nova->qtdFolgas = 0;
    nova->funcao = (double *) calloc(qtd, sizeof(double));

    int i = 0;
    for(i = 0; i < qtd; i++)
    {
        printf("\nEntre com o %d-ésimo coeficiente: ", i + 1);
        scanf("%lf", &(nova->funcao[i]));
    }

    if(b == 1)
    {
        printf("\nEntre com o tipo de sinal:\n 1 - =\n 2 - >=\n 3 - <=\n");
        scanf("%d",&(nova->tipoSinal));

        printf("\nEntre com o valor constante da restrição: ");
        scanf("%lf", &(nova->constante));
    }

    return nova;
}

// b = 0 para função objetivo, b = 1 para restrição
void imprimirEquacao(equacao *eq, int qtd, int tipo)
{
    char s = ' ';

    if(eq->tipoEquacao == 0)
    {
        if(tipo == 1)
        {
            printf("\nMAX");
            s = '-';
        }
        else
        {
            printf("\nMIN");
            s = '+';
        }

        printf("\tZ = ");
    }        

    int i = 0;
    for(i = 0; i < qtd; i++)
        printf("%+lf x%d  ", eq->funcao[i], i + 1);

    if(eq->tipoEquacao == 0)
    {
        for(int i = 0; i < eq->qtdFolgas; i++)
            printf("+0 f%d  ", i + 1);

        for(int i = 0; i < eq->qtdExcessos; i++)
            printf("-0 e%d  ", i + 1);

        for(int i = 0; i < eq->qtdArtificiais; i++)
            printf("%cM a%d  ", s, i + 1);
    }
    else
    {
        for(int i = 0; i < eq->qtdFolgas; i++)
            printf("+f%d  ", i + 1);

        for(int i = 0; i < eq->qtdExcessos; i++)
            printf("-e%d  ", i + 1);

        for(int i = 0; i < eq->qtdArtificiais; i++)
            printf("+a%d  ", i + 1);
    }

    if(eq->tipoEquacao == 1)
        printf("%s %+lf", sinal(eq->tipoSinal), eq->constante);

    printf("\n");
}

char *sinal(int tipo)
{
    switch(tipo)
    {
        case 1:
            return "=";
        case 2:
            return ">=";
        case 3:
            return "<=";
        default:
            return "?";
    }
}

void normalizar(equacao *objetivo, equacao **restricoes, int qtdVD, int qtdR)
{
    for(int i = 0; i < qtdR; i++)
    {
        switch(restricoes[i]->tipoSinal)
        {
            case 1: // artificial
                objetivo->qtdArtificiais++;
                restricoes[i]->qtdArtificiais++;
                
                break;
            case 2: // excesso e artificial
                objetivo->qtdExcessos++;
                objetivo->qtdArtificiais++;
                restricoes[i]->qtdExcessos++;
                restricoes[i]->qtdArtificiais++;

                break;
            case 3: // folga
                objetivo->qtdFolgas++;
                restricoes[i]->qtdFolgas++;

                break;
        }
    }
}