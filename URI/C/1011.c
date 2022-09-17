#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.14159

	double raio, volume;

void main(){
	scanf("%lf",&raio);
	volume=(4.0/3)*pi*pow(raio,3);
	printf("VOLUME = %.3lf\n", volume);
}
