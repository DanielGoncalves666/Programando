#include<stdio.h>

int main()
{
	int i = 1;
	
	do
	{
		printf("%d\n", i * 3);
	
		i++;
	}while(i <= 5);
	
	/*
	while( i <= 5)
	{
		printf("%d\n", i * 3);
		
		i++;
	}
	*/

	return 0;
}
