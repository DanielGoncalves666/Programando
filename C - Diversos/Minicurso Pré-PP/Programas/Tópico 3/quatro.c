#include<stdio.h>

int main()
{
	int num;
	int soma = 0;
	int i = 0;
	
	while(i < 10)
	{
		scanf("%d",&num);
		soma += num;

		i++;
	}
	
	printf("%d\n",soma);
	


	return 0;
}
