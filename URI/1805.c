#include<stdio.h>
//ocorreu problemas de tipo

int main()
{
	unsigned long long soma = 0;
	long long i = 0;
	long long inferior, superior;

	scanf("%lld %lld",&inferior, &superior);

	i = superior - inferior + 1;

	if(i % 2 == 0)
		soma = (superior + inferior) * (i / 2);
	else
	{
		soma = (superior + inferior) * ((i - 1) / 2);
		soma += inferior + ((i - 1) / 2);
	}

	printf("%llu\n",soma);

	return 0;
}