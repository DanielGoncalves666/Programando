#include<stdio.h>

int main()
{	
	int porcentagem = 0;
	int produto = 100;
	
	scanf("%d",&porcentagem);
	
	float final = produto - produto * (porcentagem / 100.0);
	
	printf("%f\n",final);

	return 0;
}
