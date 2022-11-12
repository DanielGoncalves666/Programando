#include<stdio.h>
#include<math.h>

int main()
{
	double valor;
	
	scanf("%lf",&valor);
	
	if( valor > 0.0)
	{
		printf("A raiz quadrada é %.2lf\n", sqrt(valor));
	}
	else if( valor < 0.0)
	{
		printf("O quadrado é %.2lf\n", pow(valor,2));
	}
	else
	{
		printf("O valor é 0.0\n");
	}


	return 0;
}
