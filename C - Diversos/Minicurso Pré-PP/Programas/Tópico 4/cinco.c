#include<stdio.h>

int main()
{
	int num = 0;
	int soma = 0;
	int i;
	
	for(i = 0; i < 10; i++)
	{
		scanf("%d",&num);
		soma += num;
	}
	
	printf("Soma = %.2lf\n", soma / 10.0);

	return 0;
}
