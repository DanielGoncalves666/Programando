#include<stdio.h>
#define pi 3.14159

int main()
{
	double l;
	double areaQuadrado, areaArco, areaResto, areaIntersecaoDe2Restos;
	double areaCentral, areaInterna, areaExterna;

	while(scanf("%d",&l) != EOF)
	{
		areaQuadrado = l * l;
		areaArco = (pi * areaQuadrado) / 4.0;
		areaResto = areaQuadrado - areaArco;
		areaIntersecaoDe2Restos = areaQuadrado - 2 * areaResto;

		areaCentral = 2 * areaResto + 2 * areaIntersecaoDe2Restos - areaQuadrado;
		areaInterna = (areaIntersecaoDe2Restos - areaCentral) / 2.0;
		areaExterna = (areaResto - areaInterna) / 2;

		printf("%.2lf %.2lf %.2lf\n",areaCentral,areaInterna,areaExterna);
	}

	return 0;
}