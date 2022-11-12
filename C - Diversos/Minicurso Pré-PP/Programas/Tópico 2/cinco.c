#include<stdio.h>

int main()
{
	int num1, num2;
	
	scanf("%d %d",&num1, &num2);
	
	if( num1 > num2)
	{
		printf("%d é o maior. A diferença entre eles é de %d\n", num1, num1 - num2);
	}
	else if( num1 < num2)
	{
		printf("%d é o maior. A diferença entre eles é de %d\n", num2, num2 - num1);
	}
	else
	{
		printf("Os números são iguais e a diferença é zero.");
	}



	return 0;
}
