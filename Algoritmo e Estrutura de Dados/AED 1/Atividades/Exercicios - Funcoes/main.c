/*
Exercícios sobre Funções - Todos os 4 foram feitos no mesmo arquivo.
Daniel Gonçalves - 2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int potencia(int,int);
int sinal(int);
int quadradoPerfeito(int);
int *vetorProduto(int *, int *);

int main()
{
	int a = 0,b = 0;
	int i = 0;
	scanf("%d %d",&a,&b);
	printf("\n%d ^ %d = %d\n\n",a,b,potencia(a,b));

	scanf("%d",&a);
	printf("%d\n\n",sinal(a));

	scanf("%d",&a);
	printf("%d\n\n",quadradoPerfeito(a));

	int vet1[] = {1,2,3,4,5,6,7,8,9,10};
	int vet2[] = {10,10,10,10,10,10,10,10,10,10};
	int *vet3 = vetorProduto(vet1,vet2);

	for(i = 0; i < 10; i++)
	{
		printf("%d ",vet3[i]);
	}
	

	return (0);
}

/*
potencia
---------
A função recebe dois inteiros e retorna o primeiro inteiro elevado ao segundo.
Nessa função não foi usado pow, apesar de ser mais simples.
*/
int potencia(int a, int b)
{
	int aux = 0;//variável auxiliar

	if(b == 0)
	 	return 1;
	else if(b == 1)
		return a;
	else
	{
		if(b % 2 == 0)
		{
			aux = potencia(a,b/2);
			return aux * aux;
		}
		else
		{
			aux = potencia(a, (b-1)/2);
			return aux * aux * a;
		}
	}
}

/*
sinal
-------
Recebe um número inteiro e retorna:
0 - se nulo
1 - se positivo
-1 - se negativo
*/
int sinal(int num)
{
	if(num > 0)
		return 1;
	else if(num < 0)
		return -1;
	else
		return 0;
}

/*
quadradoPerfeito
-----------------
A função recebe um número inteiro e retorna:
1 - se ele for um quadrado perfeito
0 - se ele não for um quadrado perfeito
*/
int quadradoPerfeito(int num)
{
	int menor = 0;//maior inteiro menor q a raiz
	double raiz = 0.0;//armazena a raiz

	if(num <= 0)
		return 0;

	raiz = sqrt(num);
	menor = floor(raiz);

	if(menor * menor == num)
		return 1;

	return 0;
}

/*
vetorProduto
-------------
A função recebe o endereço de dois vetores e retorna o endereço de um vetor contendo o produto dos dois vetores dados
*/
int *vetorProduto(int *vet1, int *vet2)
{
	int *vetFinal = (int *) malloc(sizeof(int) * 10);//vetor com o produto dos vetores
	int i = 0;

	for(i = 0; i < 10; i++)
	{
		vetFinal[i] = vet1[i] * vet2[i];
	}

	return vetFinal;
}
