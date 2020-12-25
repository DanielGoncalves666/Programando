#include<stdio.h>
#include<math.h>

int
main()
{
	double A = 0.0, D = 0.0, R = 0.0;
	double tangente = 0.0, H = 0.0;
	while(scanf("%lf %lf %lf",&A,&D,&R) != EOF)
	{
		tangente = tan(R);

	}

	return 0;
}

/*
	Caso:
* R == 90: H == A
* 50 <= R < 90:
	-Temos um ângulo.
	-Temos um cateto oposto a esse ângulo.
	-Queremos encontrar o cateto adjascente
	Logo:
		tan R = D / H
		h = D / tan R

* 90 < R <= 150:
	-Temos um ângulo
	-Temos um cateto adjascente a esse ângulo
	-Queremos encontrar o cateto oposto.
	Logo:
		tan R = H / D
		h = tan R / D
*/