#include<stdio.h>

int main()
{
	int num = 0;
	int milhar, centenas, dezenas, unidade;

	scanf("%d",&num);
	
	if( num >= 1000 && num < 10000)
	{
		milhar = num / 1000;
		num -= milhar * 1000; // num = num % 1000;
		
		centenas = num / 100;
		num -= centenas * 100;
		
		dezenas = num / 10;
		num = num % 10;
		
		unidade = num;
		
		printf("%d\n",milhar);
		printf("%d\n",centenas);
		printf("%d\n",dezenas);
		printf("%d\n",unidade);
	}

	return 0;
}
