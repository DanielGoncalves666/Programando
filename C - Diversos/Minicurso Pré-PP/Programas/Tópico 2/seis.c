#include<stdio.h>


int main()
{
	float num1, num2;
	float media;
	
	scanf("%f %f", &num1, &num2);
	
	if( num1 < 0.0 || num1 > 10.0)
	{
		printf("A primeira nota é inválido.\n");
	}
	else if(num2 < 0.0 || num2 > 10.0)
	{
		printf("A segunda nota é inválida.\n");
	}
	else
	{
		media = (num1 + num2) / 2.0;
		printf("A media eh %.2f\n", media);
	}


	return 0;
}
