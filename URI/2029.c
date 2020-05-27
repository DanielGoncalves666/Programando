#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const double pi = 3.14;
double V,D,area,altura;


int main(){
	while(scanf("%lf %lf",&V,&D) != EOF){
		area = pi * pow(D/2,2);
		altura = V / area;
		
		printf("ALTURA = %.2lf\n",altura);
		printf("AREA = %.2lf\n",area);
	}

	return 0;
}
