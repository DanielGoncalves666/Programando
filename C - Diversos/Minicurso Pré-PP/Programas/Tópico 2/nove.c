#include<stdio.h>

int main()
{
	int num;
	
	scanf("%d",&num);

	if( num % 3 == 0 && num % 5 == 0)
	{
		printf("Falso.\n");
	}
	else if( num % 3 == 0 || num % 5 == 0)
	{
		printf("Verdadeiro\n");
	}
	else
	{
		printf("Falso 2.\n");	
	}


	return 0;
}
