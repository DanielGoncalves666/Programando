#include<stdio.h>
#include<stdlib.h>
#define DIM 3

//uma função que recebe um vetor unidimensional obedece a seguinte sintaxe:
//retorno nomeDaFuncao( tipo vetor[] , ...)     -neste caso o colchete é vazio
//outro detalhe é que na hora de invocar a função com vetor como argumento basta arrumar o nome do vetor, nem coclhete ou ()

//para passar matrizes multidimensionais para funções o primeiro par de colchetes pode estar vazio, ja o restante nao.
//desta maneira a sintaxe seria a seguinte: retorno nomeDaFunção(tipo vetor[][n], ...)


void preencher(int matriz[][DIM])
{
    int linha,
        coluna;

    for(linha=0 ; linha < DIM ; linha++)
        for(coluna=0 ; coluna < DIM ; coluna++)
        {
            printf("Entre com o elemento matriz[%d][%d]: ", linha+1, coluna+1);
            scanf("%d", &matriz[linha][coluna]);
        }
}

void exibir(int matriz[][DIM])
{
    int linha,
        coluna;

    for(linha=0 ; linha < DIM ; linha++)
    {
        for(coluna=0 ; coluna < DIM ; coluna++)
            printf("%3d ", matriz[linha][coluna]);

        printf("\n");
    }

}

int traco(int matriz[][DIM])
{
    int count,
        traco=0;

    for(count=0 ; count < DIM ; count++)
        traco += matriz[count][count];

    return traco;
}

int main(void)

{
    int matriz[DIM][DIM];

    preencher(matriz);
    exibir(matriz);

    printf("\nTraco da matriz: %d\n", traco(matriz));
    return 0;

}
