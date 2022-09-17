#include<stdio.h>
#include<math.h>

const double PI = 3.141592654;

int
main()
{
	double A, B, C;
	double altura = 0;

	while(scanf("%lf %lf %lf",&A,&B,&C) != EOF)
	{
		altura = (B * tan((A * PI)/180.00)) + C;
		printf("%.2lf\n", altura * 5);
	}

	return 0;
}