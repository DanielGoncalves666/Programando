#include<stdio.h>
#include<stdlib.h>

int kg;

int main()
{
	scanf("%d",&kg);
	if(kg<=50)
	{
		printf("D23\n");
	}
	if(kg>50 && kg<=60)
	{
		printf("D26\n");
	}
	if(kg>60 && kg<=70)
	{
		printf("D28\n");
	}
	return 0;
}
