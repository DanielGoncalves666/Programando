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
	
	printf("Soma = %d\n", soma);


	return 0;
}
