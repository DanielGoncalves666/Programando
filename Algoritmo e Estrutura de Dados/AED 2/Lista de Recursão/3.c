#include<stdio.h>

//Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321

int inversao(int N, int *aux)
{
	//o caso base é quando resta um número com apenas um digito, nesse caso retornamos o número e setamos a
	//variavel auxiliar para 1

	if(N < 10)
	{
		*aux = 1;
		return N;
	}
	else
	{
		int M = inversao(N / 10, aux);
		
		*aux *= 10;
		return N % 10 * (*aux) +  M; 
	}

	//o caso geral, recursivo, atribuimos variavel M o resto do numero invertido, multiplicamos por 10 a variavel
	//aux por ela ser uma casa maior que a anterior e procedemos no retorno do valor total, que é a soma do
	//numero M com o valor relativo da ultima casa de N multiplicado por aux.
}

int main()
{
	int a;
	int *aux;

	scanf("%d",&a);

	printf("%d\n",inversao(a,aux));

	return 0;
}