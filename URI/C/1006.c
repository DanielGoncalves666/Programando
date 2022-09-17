#include<stdio.h>
#include<stdlib.h>
	
	double a, b, c, media;
	
void main(){
	scanf("%lf %lf %lf", &a, &b, &c);
	media=(a*2+b*3+c*5)/10;
	printf("MEDIA = %.1lf\n",media);
}
