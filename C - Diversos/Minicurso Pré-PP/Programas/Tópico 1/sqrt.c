#include<stdio.h>
#include<math.h>

int main()
{
	double a, b;
	printf("Digite um número: \n");
	scanf("%lf", &a);
	b = sqrt(a);
	printf("%.2lf", b);
	
	return 0;
}

