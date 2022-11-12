#include<stdio.h>

int main()
{
	int a, b;

	scanf("%d %d",&a,&b);
	
	if( a > b)
	{
		printf("%d eh o maior.\n",a);
	}
	else if( a == b)
	{
		printf("Os dois números são iguais.\n");
	}
	else
	{
		printf("%d eh o maior.\n",b);
	}

	return 0;
}
