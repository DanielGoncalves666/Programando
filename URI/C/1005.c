#include<stdio.h>
#include<stdlib.h>

	double a,b,media;

void main(){
	scanf("%lf %lf",&a,&b);
	
	media=(a*3.5+b*7.5)/11;
	
	printf("MEDIA = %.5lf\n", media);
}
