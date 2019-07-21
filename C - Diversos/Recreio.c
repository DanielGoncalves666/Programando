#include<stdio.h>
#include<stdlib.h>

int x;

int main()
{
	scanf("%d",&x);
	if(x>=50 && x<=100)
	{
		printf("Numero no intervalo de 50 a 100.");
	}
	else
	{
		printf("Numero fora do intervalo de 50 a 100.");
	}
	
	return 0;
}
