#include<stdio.h>
#include<stdlib.h>

float dist, d1, d2, ICM;

int main(){
	scanf("%f %f %f",&dist,&d1,&d2);
	ICM = dist/ ( d1 + d2 );
	printf("%.2f\n",ICM);

	return 0;
}
