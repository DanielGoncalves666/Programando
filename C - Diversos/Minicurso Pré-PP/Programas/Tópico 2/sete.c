#include<stdio.h>


int main()
{
	int num;
	
	scanf("%d",&num);

	if(num < 0)
	{
		printf("Numero inválido.\n");
	}
	else
	{
		int centenas = num / 100;
		num = num % 100;
		int dezenas = num / 10;
		int unidades = num % 10;
		
		printf("Soma = %d\n", centenas + dezenas + unidades);
	}

	return 0;
}
