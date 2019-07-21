#include<stdio.h>
#include<stdlib.h>

float a,b,c,d,e,media;

int main()
{
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%f",&c);
	scanf("%f",&d);
	scanf("%f",&e);
	 
	media=(a+b+c+d+e)/5;
	
	printf("%.2f", media);
}
