#include<stdio.h>
#include<stdlib.h>

int x,y,soma;

int main()
{
	scanf("%d",&x);
	scanf("%d",&y);
	soma=x+y;
	if(soma>100)
	{
		printf("maior que 100");
	}
	else
	{
		printf("menor que 100");
	}
	return 0;
}
