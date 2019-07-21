#include<stdio.h>
#include<stdlib.h>

int data, id;

int main()
{
	scanf("%d", &data);
	id=2017-data;
	
	if(id<=0)
	{
		printf("Idade inexistente");
	}	
	if(id>0 && id<12)
	{
		printf("Crianca");
	}
	if(id>12 && id<18)
	{
		printf("Adolescente");
	}
	if(id>18 && id<70)
	{
		printf("Adulto");
	}
	if(id>70)
	{
		printf("Idoso");
	}
	
	return 0;
}

