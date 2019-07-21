#include<stdio.h>
#include<stdlib.h>

float C, F;

int main()
{
	scanf("%f",&F);
	C=(F-32)/1.8;
	printf("%.2f",C);
	
	return 0;	
}
