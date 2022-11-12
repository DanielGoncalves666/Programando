#include<stdio.h>


int main()
{
	int num;
	
	scanf("%d",&num);
	
	if(num % 2 != 0)
		num -= 1;

	int i = num;
	while( i >= 0)
	{
		printf("%d\n", i);
		i -= 2;
	}


	return 0;
}
