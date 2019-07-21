#include<stdio.h>
#include<stdlib.h>

float a,b,c,d,media;

int main()
{
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%f",&c);
	scanf("%f",&d);
	 
	media=(a+b+c+d)/4;
	
	printf("%.2f", media);
	 
	return 0; 
}
