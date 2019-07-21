#include<stdio.h>
#include<stdlib.h>
#include<math.h>

	double a, b, c, delta, R1, R2;

void main(){	
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a==0.0){
		printf("Impossivel calcular\n");
		exit(0);	
	}
	delta=pow(b,2)-4*a*c;
	if(delta<0){
		printf("Impossivel calcular\n");
		exit(0);
	}
	R1=(-b+sqrt(delta))/(2*a);
	R2=(-b-sqrt(delta))/(2*a);
	printf("R1 = %.5lf\n", R1);
	printf("R2 = %.5lf\n", R2);
}
