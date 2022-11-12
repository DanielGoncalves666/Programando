#include<stdio.h>
#include<math.h>

int main()
{
	int valor;
	
	scanf("%d",&valor);
	
	if( valor > 0 )
	{
		printf("A raiz quadrada de %d é %.0lf\n", valor, sqrt(valor));
	}
	else if(valor < 0)
	{
		printf("O valor é inválido");
	}
	else
	{
		printf("O valor é zero.\n");
	}

	return 0;
}
