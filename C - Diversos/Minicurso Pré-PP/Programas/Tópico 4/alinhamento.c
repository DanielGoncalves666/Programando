#include<stdio.h>

int main()
{
	int i = 0, j = 0;
	
	do
	{
		j = 1;
		do
		{
			printf("%d\n",j);
			j++;
		}while(j <= 100);
	
		printf("\n\n");
		i++;
	}while(i < 3);
	
	
	
	
	/*
	while(i < 3)
	{
		j = 1;
		while(j <= 100)
		{
			printf("%d\n",j);
			j++;
		}
		printf("\n\n");
	
		i++;
	}*/
	
	
	
	/*
	for(i = 0; i < 3; i++)
	{
		for(j = 1; j <= 100; j++)
		{
			printf("%d\n",j);
		}
		printf("\n\n");
	}
	*/


	return 0;
}
