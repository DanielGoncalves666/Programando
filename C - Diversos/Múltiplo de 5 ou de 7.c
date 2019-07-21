#include<stdio.h>
#include<stdlib.h>

int x;
 
int main()
{
	scanf("%d",&x);
	if(x%5==0 && x%7==0)
	{
		printf("O numero e multiplo de 5 e de 7");
	}
	else
	{
		printf("O numero nao e multiplo de 5 e de 7");
	}
	return 0;
}
