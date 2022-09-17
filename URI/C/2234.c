#include<stdio.h>

double H,P,media;

int main(){

	scanf("%lf %lf",&H,&P);
	media = H/P;
	
	printf("%.2lf\n",media);
	return 0;
}
