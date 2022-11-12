#include<stdio.h>

int main()
{	
	int dias = 0;
	
	scanf("%d",&dias);
	
	float total = dias * 30.0;
	total -= total * 0.08;
	
	printf("%.2f\n", total);

	return 0;
}
