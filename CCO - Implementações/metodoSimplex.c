/**
 * Normalização e resolução de Problemas de Programação Linear utilizando o método Simples (uma etapa e duas etapas).
 * 
 * Revisar metodo. Solução inicial correspondente a cada restrição não acontece.
 * 
 * by Daniel Gonçalves 2023. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct{
    int tipoEquacao; // 0 - função objetivo ou 1 - equação de restrição 
    double *funcao;
    int qtdExcessos;
    int qtdFolgas;
    int qtdArtificiais;
    int tipoSinal; // 1 - =, 2 - >=, 3 - <=
    double constante;
}equacao;

typedef struct{
    int qtdVD; // quantidade de variáveis de decisão
    int qtdR; // quantidade de restrições
    int tipo; // tipo de problema  (1 - Maximização ou de 2 - Minimização)
    
    equacao *objetivo;
    equacao **restricoes;
}mpl;

// não inclui os valores usados apenas para determinar a última linha
typedef struct{
    bool duasFases;
    int qtdColCentro;
    int qtdLinCentro;

    bool *colunaValida; // indica se a coluna do centro correspondente é válida
    bool ultimaValida; // usada apenas no simples de duas fases, indica se a linha inferior ainda é usada

    char **variaveisSuperiores; // variaveis superiores do quadro
    char **variaveisEsquerda; // variaveis inferiores do quadro

    double **A; // centro do quadro
    double *B; // coluna direita do quadro
    double **lastLine; // linhas inferiores do quadro (devem incluir o valor à direita)
}quadroSimplex;

equacao *capturarEquacao(int qtd, int b); // ok
void normalizar(mpl problema); // ok
void imprimirEquacao(equacao *eq, int qtd, int tipo); // ok
char *sinal(int tipo); // ok

quadroSimplex *criarQuadro(mpl problema); // ok
void desalocarQuadro(quadroSimplex *quadro); // ok
void preencherQuadro(quadroSimplex *quadro, mpl problema); // ok (necessário resolver os exemplos em papel)
int preencheVariaveis(char **destino, int qtd, int inicio, char *textoInicial); // ok
void imprimirQuadro(quadroSimplex *quadro, int tipo); // ok

int metodoSimplex(quadroSimplex *quadro);
void imprimirSolucaoFinal(quadroSimplex *quadro, mpl problema, int status);

int valorMaisNegativo(quadroSimplex *quadro); // Passo 1 (1 fase) // ok
int valorMaisNegativoDuasFases(quadroSimplex *quadro); // Passo 1 (2 fases) // ok
int determinarPivo(quadroSimplex *quadro, int colunaTrabalho); // Passo 2 (1 e 2 Fases) // ok
void swapStrings(quadroSimplex *quadro, int indexPivo, int colunaTrabalho); // Passo 3 (1 e 2 Fases) // ok
void operacoesElementaresColTrab(quadroSimplex *quadro, int indexPivo, int colunaTrabalho); // Passo 4 (1 e 2 Fases) // ok
bool verificaUltimaLinha(quadroSimplex *quadro); // Modificação 4 // ok

int main()
{
    mpl problema;
    quadroSimplex *quadro = NULL;
    int retorno = 0;

    problema.qtdVD = 0;
    problema.qtdR = 0;
    problema.tipo = 0;
    problema.objetivo = NULL;
    problema.restricoes = NULL;

    // ----------- Entrada do problema ----------------- //

    printf("\nEntre com a quantidade de variáveis de decisão: ");
    scanf("%d", &problema.qtdVD);

    printf("\nEntre com a quantidade de restrições: ");
    scanf("%d", &problema.qtdR);

    if(problema.qtdVD <= 0 || problema.qtdR <= 0)
    {
        fprintf(stderr, "Quantidades inválidas\n");
        return 1;
    }

    printf("\nO problema é de 1 - Maximização ou de 2 - Minimização? ");
    scanf("%d",&problema.tipo);

    problema.restricoes = (equacao **) calloc(problema.qtdR, sizeof(equacao *));

    printf("\n==== Função objetivo ====");
    problema.objetivo = capturarEquacao(problema.qtdVD, 0);
    for(int i = 0; i < problema.qtdR; i++)
    {
        printf("\n== %d-ésima equação de restrição ==", i + 1);
        problema.restricoes[i] = capturarEquacao(problema.qtdVD, 1);
    }

    // --------- Normalização ----------- //

    normalizar(problema);

    // --------- Impressão do problema normalizado ------------ // 

    imprimirEquacao(problema.objetivo, problema.qtdVD, problema.tipo);
    printf("\nSujeito à: \n");
    for(int i = 0; i < problema.qtdR; i++)
        imprimirEquacao(problema.restricoes[i], problema.qtdVD, problema.tipo);
    
    // -------- Resolução do problema ------------ //

    quadro = criarQuadro(problema);

    preencherQuadro(quadro,problema);
    imprimirQuadro(quadro,problema.tipo);

    retorno = metodoSimplex(quadro);
    imprimirSolucaoFinal(quadro,problema,retorno);

    desalocarQuadro(quadro);

    return 0;
}

/**
 * capturarEquacao
 * ----------------
 * Entrada: inteiro, indicando a quantidade de variáveis de decisão
 *          inteiro, indica o tipo de equação (b = 0, para função objetivo, b = 1, para função restrição)
 * Processo: Aloca uma estrutura do tipo equacao e a preenche.
 * Saída: ponteiro para tipo equacao, a qual foi alocada e preenchida
*/
/* b = 0 para função objetivo, b = 1 para restrição */
equacao *capturarEquacao(int qtd, int b)
{
    equacao *nova = (equacao *) calloc(1,sizeof(equacao));
    if(nova != NULL)
    {
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
            printf("\nEntre com o coeficiente da %d-ésima variável de decisão: ", i + 1);
            scanf("%lf", &(nova->funcao[i]));
        }

        if(b == 1)
        {
            printf("\nEntre com o tipo de sinal:\n 1 - =\n 2 - >=\n 3 - <=\n");
            scanf("%d",&(nova->tipoSinal));

            printf("\nEntre com o valor constante da restrição (lado direito): ");
            scanf("%lf", &(nova->constante));
        }
    }

    return nova;
}

/**
 * normalizar
 * -----------
 * Entrada: tipo mpl
 * Processo: Realiza a normalização do modelo de programação linear passado.
 * Saída: nenhuma
*/
void normalizar(mpl problema)
{
    for(int i = 0; i < problema.qtdR; i++)
    {
        switch(problema.restricoes[i]->tipoSinal)
        {
            case 1: // artificial
                problema.objetivo->qtdArtificiais++;
                problema.restricoes[i]->qtdArtificiais++;
                
                break;
            case 2: // excesso e artificial
                problema.objetivo->qtdExcessos++;
                problema.objetivo->qtdArtificiais++;
                problema.restricoes[i]->qtdExcessos++;
                problema.restricoes[i]->qtdArtificiais++;

                break;
            case 3: // folga
                problema.objetivo->qtdFolgas++;
                problema.restricoes[i]->qtdFolgas++;

                break;
        }
    }
}

/**
 * imprimirEquacao
 * ----------------
 * Entrada: ponteiro para equacao
 *          inteiro, indicando a quantidade de variáveis de decisão
 *          inteiro, indicando o tipo do problema (b = 0 para função objetivo, b = 1 para restrição)
 * Processo: Imprime a equação passada
 * Saída: nenhuma
*/
void imprimirEquacao(equacao *eq, int qtdVD, int tipo)
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
    for(i = 0; i < qtdVD; i++)
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

/**
 * sinal
 * --------
 * Entrada: inteiro, indicando o tipo de sinal a ser retornado
 * Processo: Determina o sinal a ser retorndado de acordo com o inteiro passado.
 * Saída: string
*/
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

/**
 * criarQuadro
 * ------------
 * Entrada: tipo mpl, indicando o problema ao qual o quadro será utilizado para resolver
 * Processo: Realiza a alocação de um novo quadroSimplex de acordo com o mpl passado.
 * Saída: ponteiro para quadroSimplex
*/
quadroSimplex *criarQuadro(mpl problema)
{
    quadroSimplex *novo = (quadroSimplex *) calloc(1, sizeof(quadroSimplex));
    if(novo != NULL)
    {
        novo->qtdColCentro = problema.qtdVD + problema.objetivo->qtdArtificiais + problema.objetivo->qtdExcessos + problema.objetivo->qtdFolgas;

        novo->qtdLinCentro = problema.objetivo->qtdArtificiais + problema.objetivo->qtdFolgas;

        novo->A = (double **) malloc(novo->qtdLinCentro * sizeof(double *));
        for(int i = 0; i < novo->qtdLinCentro; i++)
            novo->A[i] = (double *) calloc(novo->qtdColCentro, sizeof(double));

        novo->B = (double *) calloc(novo->qtdLinCentro, sizeof(double));

        novo->lastLine = (double **) malloc(2 * sizeof(double *));
        for(int i = 0; i < 2; i++)
            novo->lastLine[i] = (double *) calloc(novo->qtdColCentro + 1, sizeof(double));
    
        if(problema.objetivo->qtdArtificiais != 0)
        {    // duas linhas inferiores
            novo->ultimaValida = true;
            novo->duasFases = true;
        }
        else
        {
            novo->duasFases = false;
            novo->ultimaValida = false;
        }

        novo->colunaValida = (bool *) malloc(sizeof(bool) * novo->qtdColCentro);

        novo->variaveisSuperiores = (char **) malloc(sizeof(char *) * novo->qtdColCentro);
        for(int i = 0; i < novo->qtdColCentro; i++)
            novo->variaveisSuperiores[i] = calloc(4, sizeof(char));

        novo->variaveisEsquerda = (char **) malloc(sizeof(char *) * novo->qtdLinCentro);
        for(int i = 0; i < novo->qtdLinCentro; i++)
            novo->variaveisEsquerda[i] = calloc(4,sizeof(char));
    }

    return novo;
}

/**
 * desalocarQuadro
 * ----------------
 * Entrada: ponteiro para quadroSimplex
 * Processo: Desaloca o quadro passado
 * Saída: nenhuma
*/
void desalocarQuadro(quadroSimplex *quadro)
{
    if(quadro != NULL)
    {
        for(int i = 0; i < quadro->qtdLinCentro; i++)
            free(quadro->A[i]);
        free(quadro->A);

        free(quadro->B);

        free(quadro->lastLine[0]);
        free(quadro->lastLine[1]);
        free(quadro->lastLine);

        free(quadro->colunaValida);

        for(int i = 0; i < quadro->qtdColCentro; i++)
            free(quadro->variaveisSuperiores[i]);
        free(quadro->variaveisSuperiores);

        for(int i = 0; i < quadro->qtdLinCentro; i++)
            free(quadro->variaveisEsquerda[i]);
        free(quadro->variaveisEsquerda);

        free(quadro);
    }
}

/**
 * preencherQuadro
 * ----------------
 * Entrada: ponteiro para quadroSimplex
 *          tipo mpl, contendo o problema
 * Processo: Preenche o quadro com os valores obtidos à partir do problema.
 * Saída: nenhuma
*/
void preencherQuadro(quadroSimplex *quadro, mpl problema)
{
    int contExcesso = 0;
    int contArtificial = 0;
    int contFolga = 0;

    char var[4];

    int i,h,j;

    // preenche o centro
    for(i = 0; i < quadro->qtdLinCentro; i++)
    {
        for(h = 0; h < problema.qtdVD; h++) // copia os coeficientes das variáveis de decisão das restrições
            quadro->A[i][h] = problema.restricoes[i]->funcao[h];

        // folga
        for(h += contFolga, j = 0; j < problema.restricoes[i]->qtdFolgas; h++, j++)
            quadro->A[i][h] = 1;
        
        contFolga += problema.restricoes[i]->qtdFolgas;
        h += problema.objetivo->qtdFolgas - contFolga;

        // excesso
        for(h += contExcesso, j = 0; j < problema.restricoes[i]->qtdExcessos; h++, j++)
            quadro->A[i][h] = -1;

        contExcesso += problema.restricoes[i]->qtdExcessos;
        h+= problema.objetivo->qtdExcessos - contExcesso;

        // artificial
        for(h += contArtificial, j = 0; j < problema.restricoes[i]->qtdArtificiais; h++, j++)
            quadro->A[i][h] = 1;

        contArtificial += problema.restricoes[i]->qtdArtificiais;
        h+= problema.objetivo->qtdArtificiais - contArtificial;
    }

    // preenche a coluna à direita
    for(i = 0; i < quadro->qtdLinCentro; i++)
        quadro->B[i] = problema.restricoes[i]->constante;

    // valida todas as colunas do centro
    for(i = 0; i < quadro->qtdColCentro; i++)
        quadro->colunaValida[i] = true;
    
    // linha inferior
    if(problema.tipo == 1) // maximização
    {
        // C0t * A - C
        if(quadro->ultimaValida) // Modificação 1
        {
            for(i = 0; i < problema.qtdVD; i++)
            {
                quadro->lastLine[0][i] = - problema.objetivo->funcao[i];
                quadro->lastLine[1][i] += 0;
               
                for(h = problema.objetivo->qtdFolgas; h < quadro->qtdLinCentro; h++)
                    quadro->lastLine[1][i] += quadro->A[h][i];
            }

            for(j = 0;j < problema.objetivo->qtdFolgas; i++, j++)
            {
                quadro->lastLine[0][i] = 0;
                quadro->lastLine[1][i] = 0;

                for(h = problema.objetivo->qtdFolgas; h < quadro->qtdLinCentro; h++)
                    quadro->lastLine[1][i] += quadro->A[h][i];
            }

            for(j = 0;j < problema.objetivo->qtdExcessos; i++, j++)
            {
                quadro->lastLine[0][i] = 0;
                quadro->lastLine[1][i] = 0;

                for(h = problema.objetivo->qtdFolgas; h < quadro->qtdLinCentro; h++)
                    quadro->lastLine[1][i] += quadro->A[h][i];
            }

            for(j = 0;j < problema.objetivo->qtdArtificiais; i++, j++)
            {
                quadro->lastLine[0][i] = 0;
                quadro->lastLine[1][i] = -1;

                for(h = problema.objetivo->qtdFolgas; h < quadro->qtdLinCentro; h++)
                    quadro->lastLine[1][i] += quadro->A[h][i];
            }
        }
        else
        {
            for(i = 0; i < problema.qtdVD; i++)
            {
                quadro->lastLine[0][i] = - problema.objetivo->funcao[i];
            }

            for(j = 0;j < problema.objetivo->qtdFolgas; i++, j++)
            {
                quadro->lastLine[0][i] = 0;
            }
        }
    }
    else // minimização
    {
        // C - C0t * A
        if(quadro->ultimaValida) // Modificação 1
        {
            for(i = 0; i < problema.qtdVD; i++)
            {
                quadro->lastLine[0][i] = problema.objetivo->funcao[i];
                quadro->lastLine[1][i] = 0;
               
                for(h = problema.objetivo->qtdFolgas; h < quadro->qtdLinCentro; h++)
                    quadro->lastLine[1][i] -= quadro->A[h][i];
            }

            for(j = 0;j < problema.objetivo->qtdFolgas; i++, j++)
            {
                quadro->lastLine[0][i] = 0;
                quadro->lastLine[1][i] = 0;

                for(h = problema.objetivo->qtdFolgas; h < quadro->qtdLinCentro; h++)
                    quadro->lastLine[1][i] -= quadro->A[h][i];
            }

            for(j = 0;j < problema.objetivo->qtdExcessos; i++, j++)
            {
                quadro->lastLine[0][i] = 0;
                quadro->lastLine[1][i] = 0;

                for(h = problema.objetivo->qtdFolgas; h < quadro->qtdLinCentro; h++)
                    quadro->lastLine[1][i] -= quadro->A[h][i];
            }

            for(j = 0;j < problema.objetivo->qtdArtificiais; i++, j++)
            {
                quadro->lastLine[0][i] = 0;
                quadro->lastLine[1][i] = 1;
                
                for(h = problema.objetivo->qtdFolgas; h < quadro->qtdLinCentro; h++)
                    quadro->lastLine[1][i] -= quadro->A[h][i];
            }
        }
        else
        {   
            for(i = 0; i < problema.qtdVD; i++)
            {
                quadro->lastLine[0][i] = problema.objetivo->funcao[i];
            }

            for(j = 0;j < problema.objetivo->qtdFolgas; i++, j++)
            {
                quadro->lastLine[0][i] = 0;
            }
        }
    }

    // preenche a variável abaixo da coluna à direita
    if(quadro->ultimaValida)// duas fases
    {
        quadro->lastLine[0][quadro->qtdColCentro] = 0;
        quadro->lastLine[1][quadro->qtdColCentro] = 0;
                
        for(h = problema.objetivo->qtdFolgas; h < quadro->qtdLinCentro; h++)
            quadro->lastLine[1][quadro->qtdColCentro] -= quadro->B[h];
    }
    else
    {
        quadro->lastLine[0][quadro->qtdColCentro] = 0; 
    }

    // ------- Variáveis Superiores -------- //
    // variáveis superiores (variáveis de decisão)
    i = preencheVariaveis(quadro->variaveisSuperiores,problema.qtdVD,0,"x");

    // variáveis superiores (variáveis de folga) 
    i = preencheVariaveis(quadro->variaveisSuperiores,problema.objetivo->qtdFolgas,i,"f");

    // variáveis superiores (variáveis de excesso)
    i = preencheVariaveis(quadro->variaveisSuperiores,problema.objetivo->qtdExcessos,i,"e");

    // variáveis superiores (variáveis artificiais)
    preencheVariaveis(quadro->variaveisSuperiores,problema.objetivo->qtdArtificiais,i,"a");

    // ------- Variáveis Esquerda -------- //
    // folgas
    i = preencheVariaveis(quadro->variaveisEsquerda, problema.objetivo->qtdFolgas, 0, "f");

    // artificiais
    preencheVariaveis(quadro->variaveisEsquerda, problema.objetivo->qtdArtificiais, i, "a");
}

/**
 * preencheVariaveis
 * ------------------
 * Preenche o vetor de strings 'destino', iniciando pela posição 'inicio', com 'qtd' strings criadas à partir
 * da concatenação de 'textoInicial' com um inteiro.
 * 
 * Parâmetros: ponteiro para ponteiro de char, indicando um vetor de strings
 *             inteiro, indicando a quantidade de posições do vetor que devem ser preenchidas
 *             inteiro, indicando a posição de inicio
 *             ponteiro para char, indicando a string contendo o texto base
 * 
 * Retorno: inteiro, indicando a posição adjascente da última preenchida;
*/
int preencheVariaveis(char **destino, int qtd, int inicio, char *textoInicial)
{
    int i,j;
    char var[4];

    for(i = inicio, j = 0; j < qtd; j++, i++)
    {
        sprintf(var,"%s%d",textoInicial, j + 1);
        strcpy(destino[i], var);
    }

    return i;
}

/**
 * imprimirQuadro
 * ----------------
 * Realiza a impressão do quadro Simplex (sem os valores que são utilizados para gerar a linha inferior)
 * 
 * Parâmetros: ponteiro para quadroSimplex
 *             inteiro, indicando se o problema é de 1 - Maximização ou 2 - Minimização
 * Retorno: nenhum
*/
void imprimirQuadro(quadroSimplex *quadro, int tipo)
{
    int i,h;

    // linha superior
    if(tipo == 1)
    {
        printf("\n\nMAX \t|");
    }
    else
    {
        printf("\n\nMIN \t|");
    }

    for(i = 0; i < quadro->qtdColCentro; i++)
    {
        if(! quadro->colunaValida[i])   
            continue;

        printf("%s\t", quadro->variaveisSuperiores[i]);// variáveis superiores
    }

    printf("|\n\n");

    // linhas centrais
    for(i = 0; i < quadro->qtdLinCentro; i++)
    {
        printf("%3s \t|", quadro->variaveisEsquerda[i]); // variável à esquerda

        for(h = 0; h < quadro->qtdColCentro; h++)
        {
            if(! quadro->colunaValida[h])   
                continue;

            printf("%.2lf\t", quadro->A[i][h]); // retângulo central
        }

        printf("| %.2lf\n", quadro->B[i]); // coluna à direita
    }

    printf("\n");

    //linhas inferiores

    for(i = 0; i < 1 + quadro->duasFases; i++)
    {
        printf("    \t|");

        for(h = 0; h < quadro->qtdColCentro; h++)
        {
            if(! quadro->colunaValida[h])   
                continue;

            printf("%.2lf\t", quadro->lastLine[i][h]); // ultima linha centro
        }

        printf("| %.2lf\n", quadro->lastLine[i][h]);
    }

}

/**
 * metodoSimplex
 * ---------------
 * Aplica o Método Simplex no quadro Simplex passado.
 * 
 * Parâmetros: ponteiro para quadroSimplex
 *         
 * Retorno: inteiro, 0, se não existe solução, 1, em sucesso
*/
int metodoSimplex(quadroSimplex *quadro)
{
    int colunaTrabalho = 0; // índice do menor valor e coluna de trabalho
    int indexPivo = -1; // índice do pivo na coluna de trabalho

    int i,h;

    while(1)
    {
        // Passo 1
        if(quadro->duasFases)
            colunaTrabalho = valorMaisNegativoDuasFases(quadro); // Modificação 2
        else
            colunaTrabalho = valorMaisNegativo(quadro);
        
        if(colunaTrabalho == -1) // nenhum valor negativo na última linha, finaliza o método
            break; // Verificação do Passo 5

        // Passo 2
        indexPivo = determinarPivo(quadro, colunaTrabalho);
        if(indexPivo == -1) // a coluna de trabalho não apresenta nenhum valor positivo
            return 0; // sem solução

        if(quadro->duasFases) // Modificação 3
        {
            if(strncmp("a",quadro->variaveisEsquerda[indexPivo],1) == 0) // caso uma artificial esteja subindo
            {
                for(i = quadro->qtdColCentro - 1; i >= 0; i--)
                {
                    if(strcmp(quadro->variaveisEsquerda[indexPivo], quadro->variaveisSuperiores[i]) == 0)
                    {
                        quadro->colunaValida[i] = false; // invalida sua coluna
                        break;
                    }
                }
            }
        }

        // Passo 3
        swapStrings(quadro, indexPivo, colunaTrabalho);

        // Passo 4
        operacoesElementaresColTrab(quadro,indexPivo, colunaTrabalho);

        if(quadro->ultimaValida) // Modificação 4
        {
            if(verificaUltimaLinha(quadro))
            {
                quadro->ultimaValida = false; // a última linha deixa de ser considerada pois não tem nenhum valor negativo
            }
        }

        imprimirQuadro(quadro,2);
    }

    // modificação 5
    for(i = 0; i < quadro->qtdLinCentro; i++)
    {
        if(strncmp("a",quadro->variaveisEsquerda[i],1) == 0) // caso exista uma artificial na solução final
        {
            if(quadro->B[i] != 0.0) // e ela for diferente de zero
                return 0;
        }
    }

    return 1;
}


/**
 * valorMaisNegativo
 * -------------------
 * Determina o valor mais negativo da última linha do quadro (Passo 1 do Método Simplex. apenas para 1 fase)
 * 
 * Parâmetros:  ponteiro para quadroSimplex
 * 
 * Retorno: inteiro não negativo, indicando o índice do valor mais negativo. Caso não existir valor negativo,
 *              retorna -1.
*/
int valorMaisNegativo(quadroSimplex *quadro)
{ 
    double menorValor = quadro->lastLine[0][0];
    int colunaTrabalho = 0; // índice do menor valor
    
    for(int i = 1; i < quadro->qtdColCentro; i++)
    {
        if(quadro->lastLine[0][i] < menorValor)
        {
            menorValor = quadro->lastLine[0][i];
            colunaTrabalho = i;
        }
    }
    // se existir duas posições com o menor valor, a primeira da esquerda pra direita é escolhida

    if(menorValor >= 0) // caso não haja nenhum valor negativo
        return -1;

    return colunaTrabalho;
}

/**
 * valorMaisNegativoDuasFases
 * -------------------
 * Determina o valor mais negativo da última linha do quadro, caso a linha ainda seja válida. Caso a linha não
 *      seja válida, determina o valor mais negativo da penúltima linha, desde que o valor da mesma coluna seja 
 *      zero. (Passo 1 do Método Simplex, apenas para 2 fases)
 * 
 * Parâmetros:  ponteiro para quadroSimplex
 * 
 * Retorno: inteiro não negativo, indicando o índice do valor mais negativo. Caso não existir valor negativo,
 *              retorna -1.
*/
int valorMaisNegativoDuasFases(quadroSimplex *quadro)
{ 
    double erro = 0.0000000001;
    double menorValor = 0;
    int colunaTrabalho = -1; //índice do menor valor

    if(quadro->ultimaValida)
    {
        menorValor = quadro->lastLine[1][0];
        colunaTrabalho = 0;
    }
    
    // se ainda estiver valida, começa em 1, senão, começa em 0
    for(int i = quadro->ultimaValida; i < quadro->qtdColCentro; i++)
    {
        if(quadro->ultimaValida)
        {
            if(quadro->lastLine[1][i] < menorValor)
            {
                menorValor = quadro->lastLine[1][i];
                colunaTrabalho = i;
            }
        }
        else
        {
            if(!quadro->colunaValida[i])
                continue;

            if(quadro->lastLine[1][i] < 0 + erro && quadro->lastLine[1][i] > 0 - erro)
            {
                if(colunaTrabalho == -1)
                {
                    colunaTrabalho = i;
                    menorValor = quadro->lastLine[0][i];
                }
                else
                {
                    if(quadro->lastLine[0][i] < menorValor)
                    {
                        colunaTrabalho = i;
                        menorValor = quadro->lastLine[0][i];
                    }
                }
            }
        }
    }
    // se existir duas posições com o menor valor, a primeira da esquerda pra direita é escolhida

    if(menorValor >= 0) // caso não haja nenhum valor negativo
        return -1;

    return colunaTrabalho;
}

/**
 * determinarPivo
 * ----------------
 * Dada a coluna de trabalho, determina o pivô. (Funciona para Simplex simples e de duas fases)
 *  (Passo 2 do método Simplex)
 * 
 * Parâmetros: ponteiro para quadroSimplex
 *             inteiro, indicando a coluna de trabalho
 * 
 * Retorno: inteiro não negativo, indicando o índice na coluna de trabalho do pivô. Retornará -1 se não existir 
 *              nenhum posição com valor maior que zero.
*/
int determinarPivo(quadroSimplex *quadro, int colunaTrabalho)
{
    int indexPivo = -1;
    double menorQuociente = 0;

    for(int i = 0; i < quadro->qtdLinCentro; i++)
    {
        if( quadro->A[i][colunaTrabalho] <= 0) // pula os divisores negativos e nulos
            continue;

        if(indexPivo == -1)
        {
            indexPivo = i;
            menorQuociente = quadro->B[i] / quadro->A[i][colunaTrabalho];
        }
        else if( quadro->B[i] / quadro->A[i][colunaTrabalho] < menorQuociente)
        {
            menorQuociente = quadro->B[i] / quadro->A[i][colunaTrabalho];
            indexPivo = i;
        }
    }

    return indexPivo;
}

/**
 * swapStrings
 * ------------
 * Realiza o swap da string na posição 'indexPivo' das variáveis à esquerda com a string na posição 'colunaTrabalho'
 *      das variáveis superiores. (Passo 3 do método simplex)
 * 
 * Parâmetros: ponteiro para quadroSimplex
 *             inteiro, índice da string das variáveis à esquerda
 *             inteiro, indice da string das variáveis superiores
 * 
 * Retorno: nada
*/
void swapStrings(quadroSimplex *quadro, int indexPivo, int colunaTrabalho)
{
    char aux[4];

    strcpy(aux, quadro->variaveisEsquerda[indexPivo]);
    strcpy(quadro->variaveisEsquerda[indexPivo], quadro->variaveisSuperiores[colunaTrabalho]);
    strcpy(quadro->variaveisSuperiores[colunaTrabalho], aux);
}

/**
 * operacoesElementaresColTrab
 * -----------------------------
 * Divide a linha do pivô de modo que ele fique com valor 1, e aplica operações elementares no restante das linhas
 *      (incluindo as linhas inferiores, de modo que a coluna de trabalho fique toda zerada com excessão do pivô.)
 *      (Passo 4 do método Simplex, funcionando para 1 e 2 fases)
 * 
 * Parâmetros: ponteiro para quadroSimplex
 *             inteiro, indicando a linha do pivo
 *             inteiro, indicando a coluna de trabalho
 * 
 * Retorno: nenhum
*/
void operacoesElementaresColTrab(quadroSimplex *quadro, int indexPivo, int colunaTrabalho)
{
    double valorPivo = 0; // armazena o valor do pivo (para ficar mais legivel)
    double valorZerador = 0; // armazena o valor que irá zerar a posição na coluna de trabalho
    int i,h;

    // divide a linha do pivô por ele mesmo 
    valorPivo = quadro->A[indexPivo][colunaTrabalho];    
    for(i = 0; i < quadro->qtdColCentro; i++)
    {
        if(!quadro->colunaValida[i])
            continue;

        quadro->A[indexPivo][i] /= valorPivo;
    }
    quadro->B[indexPivo] /= valorPivo;

    // linhas centrais
    for(i = 0; i < quadro->qtdLinCentro; i++)
    {
        if(i == indexPivo)
            continue;

        // aplica a operação nos termos do retângulo central
        valorZerador = quadro->A[i][colunaTrabalho] * -1;
        for(h = 0; h < quadro->qtdColCentro; h++)
        {
            if(!quadro->colunaValida[i])
                continue;

            quadro->A[i][h] += valorZerador * quadro->A[indexPivo][h];
        }
        quadro->B[i] += valorZerador * quadro->B[indexPivo]; // aplica a operação no termo à direita
    }

    // linha inferior
    for(i = 0; i < 1 + quadro->ultimaValida; i++)
    {
        valorZerador = quadro->lastLine[i][colunaTrabalho] * -1;
        for(h = 0; h < quadro->qtdColCentro; h++)
        {
            if(!quadro->colunaValida[h])
                continue;

            quadro->lastLine[i][h] += valorZerador * quadro->A[indexPivo][h];
        }
        quadro->lastLine[i][h] += valorZerador * quadro->B[indexPivo]; // aplica no termo inferior direito
    }
}

/**
 * verificaUltimaLinha
 * --------------------
 * No caso do Método Simplex de Duas fases, verifica se a ultima linha possui apenas valores não negativos ou não.
 * 
 * Parâmetros: ponteiro para quadroSimplex
 * 
 * Retorno: boolean, true se a ultima linha não possui nenhum valor negativo, falso em caso contrário
*/
bool verificaUltimaLinha(quadroSimplex *quadro)
{
    for(int i = 0; i < quadro->qtdColCentro; i++)
    {
        if(quadro->lastLine[1][i] < 0)
            return false;
    }

    return true;
}


/**
 * imprimirSolucaoFinal
 * ---------------------
 * Imprime a solução do MPL, se a mesma existir.
 * 
 * Parâmetros: ponteiro para quadroSimplex
 * 
 * Retorno: nenhum
*/
void imprimirSolucaoFinal(quadroSimplex *quadro, mpl problema, int status)
{
    if(status == 0)
    {
        printf("\n\n ==== O MPL não apresenta solução. \n\n");
        return;
    }

    double *solucaoFinal = (double *) calloc(quadro->qtdColCentro + 1, sizeof(double));

    char letra;
    int alt;

    int inicioVD = 0;
    int inicioFolgas = problema.qtdVD;
    int inicioExcessos = inicioFolgas + problema.objetivo->qtdFolgas;
    int inicioArtificiais =inicioExcessos + problema.objetivo->qtdExcessos;

    int i;
    for(i = 0; i < quadro->qtdLinCentro; i++)
    {
        sscanf(quadro->variaveisEsquerda[i],"%c%d", &letra, &alt);

        switch(letra)
        {
            case 'x':
                solucaoFinal[inicioVD + alt - 1] = quadro->B[i];
                break;
            case 'f':
                solucaoFinal[inicioFolgas + alt - 1] = quadro->B[i];
                break;
            case 'e':
                solucaoFinal[inicioExcessos + alt - 1] = quadro->B[i];
                break;
            case 'a':
                solucaoFinal[inicioArtificiais + alt - 1] = quadro->B[i];
                break;
        }
    }

    solucaoFinal[quadro->qtdColCentro] = quadro->lastLine[0][quadro->qtdColCentro] * (problema.tipo == 1 ? 1 : -1);

    printf("\n\n");
    for(i = 0; i < quadro->qtdColCentro; i++)
    {
        if(i < inicioFolgas)
            printf("x%d = %.2lf\n", i + 1, solucaoFinal[i]);
        else if(i < inicioExcessos)
            printf("f%d = %.2lf\n", i + 1 - inicioFolgas, solucaoFinal[i]);
        else if(i < inicioArtificiais)
            printf("e%d = %.2lf\n", i + 1 - inicioExcessos, solucaoFinal[i]);
        else
            printf("a%d = %.2lf\n", i + 1 - inicioArtificiais, solucaoFinal[i]);
    }

    printf("Z = %.2lf\n", solucaoFinal[i]);

    free(solucaoFinal);
}
