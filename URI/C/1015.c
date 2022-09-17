#include<stdio.h>
#include<stdlib.h>
#include<math.h>

	float x1, x2, y, y2, distancia;

void main(){
	scanf("%f %f",&x1,&y);
	scanf("%f %f",&x2,&y2); 
	distancia=sqrt(pow(x2-x1,2)+pow(y2-y,2));
	printf("%.4f\n",distancia);
}
