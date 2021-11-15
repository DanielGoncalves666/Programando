#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define n 3.14159

	double raio, area;

void main(){
	scanf("%lf",&raio);
	area=n*pow(raio,2);
	printf("A=%.4lf\n",area);
}
